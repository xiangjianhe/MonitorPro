/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2012>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : SysPower.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_POWER__

#include "SysInclude.h"


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructPowerInfoType idata g_stPowerInfo = {0};

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysPowerInitial(void);
void SysPowerHandler(void);
void SysPowerSwitch(EnumPowerAction enumSwitch);

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
void SysPowerIdleProc(void);
#endif

BYTE SysPowerGetPowerStatus(void);
void SysPowerSystemClockSelect(BYTE ucClockSel);
void SysPowerTopIsolation(BYTE ucOn);
void SysPowerAnalogIsolation(BYTE ucOn);
void SysPowerGDIIsolation(BYTE ucOn);
void SysPowerRecoverTopAreaData(void);
void SysPowerRecoverAnalogAreaData(void);
void SysPowerRecoverGDIAreaData(void);
void SysPowerSetTargetPowerStatus(EnumPowerStatus enumPorStatus);

#if(_DIGITAL_PORT_SUPPORT == _ON)
void SysPowerRecoverHDCPKey(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initial Source Switch Flags
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysPowerInitial(void)
{    
    // Scaler whole chip reset
    ScalerGlobalWholeChipReset();

    // Internal oscillator trimming and on
    ScalerIOSCTrimming();

#if(_MHL_SUPPORT == _ON)
    // Initial Calibration for MHL
    ScalerMHLInitialSettings(); 
#endif

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
    // SDRAM power down
    ScalerSDRAMPowerControl(_OFF);
#endif

    // Initial analog power cut area status is on.
    SysPowerAnalogIsolation(_ON);

    // Initial top power cut area status is on.
    SysPowerTopIsolation(_ON);
    
    // Initial GDI power cut area status is on.
    SysPowerGDIIsolation(_ON);

#if(_SUPER_LOW_POWER_SUPPORT == _ON)

    // 30uA has no power wait source read EDID
    while((ScalerSLPV33OffStatus() == _TRUE) || (ScalerSLPVSetSwrEnStatus() == _FALSE))
    {
        UserCommonDdcciHandler();
        
        ScalerDebug();
    }

#endif

}

//--------------------------------------------------
// Description  : Power Handler Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysPowerHandler(void)
{
    // The process will deal with all kinds of power changing by power action flag.  
    switch(GET_TARGET_POWER_STATUS())
    {
        case _POWER_STATUS_NORMAL:

            switch(GET_POWER_STATUS())
            {
                case _POWER_STATUS_OFF:
                    SysPowerSwitch(_POWER_ACTION_OFF_TO_NORMAL);
                    break;

                case _POWER_STATUS_SAVING:
                    SysPowerSwitch(_POWER_ACTION_PS_TO_NORMAL);
                    break;

                case _POWER_STATUS_AC_ON:
                    SysPowerSwitch(_POWER_ACTION_AC_ON_TO_NORMAL);
                    break;

                case _POWER_STATUS_NOSUPPORT_SAVING:
                    break;

                case _POWER_STATUS_NORMAL:
                    break;

                default:
                    break;
            }            
            
            SET_POWER_STATUS(_POWER_STATUS_NORMAL);
            
            break;
            
        case _POWER_STATUS_OFF:

            switch(GET_POWER_STATUS())
            {
                case _POWER_STATUS_SAVING:
                    SysPowerSwitch(_POWER_ACTION_PS_TO_OFF);
                    break;

                case _POWER_STATUS_AC_ON:
                    SysPowerSwitch(_POWER_ACTION_AC_ON_TO_OFF);
                    break;

                case _POWER_STATUS_NOSUPPORT_SAVING:
                    SysPowerSwitch(_POWER_ACTION_NOSUPPORT_PS_TO_OFF);
                    break;

                case _POWER_STATUS_NORMAL:
                    SysPowerSwitch(_POWER_ACTION_NORMAL_TO_OFF);
                    break;

                default:
                    break;
            }

            SET_POWER_STATUS(_POWER_STATUS_OFF);
            
            break;

        case _POWER_STATUS_SAVING:

            switch(GET_POWER_STATUS())
            {
                case _POWER_STATUS_NORMAL:
                    SysPowerSwitch(_POWER_ACTION_NORMAL_TO_PS);
                    break;

                case _POWER_STATUS_NOSUPPORT_SAVING:
                    SysPowerSwitch(_POWER_ACTION_NOSUPPORT_PS_TO_PS);
                    break;

                default:
                    break;                   
            }
                        
            SET_POWER_STATUS(_POWER_STATUS_SAVING);

            break;

        case _POWER_STATUS_NOSUPPORT_SAVING:

            if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
            {
                SysPowerSwitch(_POWER_ACTION_NORMAL_TO_NOSUPPORT_PS);
            }
            
            SET_POWER_STATUS(_POWER_STATUS_NOSUPPORT_SAVING);

            break;           

        default:
            break;
    }

    // Clear power action to avoid repeat calls in next circle.
    SET_TARGET_POWER_STATUS(GET_POWER_STATUS());

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
    // MCU go into idle mode to reduce overall system power consumption under power saving and power off status.
    if(((GET_POWER_STATUS() == _POWER_STATUS_SAVING) || (GET_POWER_STATUS() == _POWER_STATUS_OFF)) && (UserCommonInterfaceGetRunDdcciCommand() == _FALSE))
    {
        // Call operation function to make mcu system into idle mode.
        SysPowerIdleProc();
    }
#endif

}

//--------------------------------------------------
// Description  : Deal With Power Manage According To Input Pamater
// Input Value  : ucSwitch    --> Power action description.
// Output Value : None
//--------------------------------------------------
void SysPowerSwitch(EnumPowerAction enumSwitch)
{
    switch(enumSwitch)
    {
        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:
        
            g_bSysPSIntDetect = _FALSE;

#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
            if(GET_DP_AUDIO_PLAYING_ALONE() == _TRUE)
            {
                // User Power Process
                UserInterfacePowerSwitch(enumSwitch);

                // Mode Power Saving Process
                SysModeResetState(_MODE_ACTION_RESET_TO_POWER_SAVING);
                
                break;
            }
#endif // End of #if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))

#if(_AUDIO_SUPPORT == _ON)
            SysAudioPowerProc(enumSwitch);
#endif             
            // User Power Process
            UserInterfacePowerSwitch(enumSwitch);

            // Mode Power Saving Process
            SysModeResetState(_MODE_ACTION_RESET_TO_POWER_SAVING);

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
            // SDRAM power down
            ScalerSDRAMPowerControl(_OFF);
#endif
            // Interface Power Saving Process
            ScalerSyncPowerProc(enumSwitch);
                
            // Set mcu module to power saving state
            ScalerMcuPwmControl(_POWER_STATUS_SAVING);
            
            // Set Pin configure to power saving state
            ScalerPinshareConfig(_POWER_STATUS_SAVING);
            
#if(_LOW_POWER_GDI_ISOLATION == _ON)
            // GDI module isolation on.
            SysPowerGDIIsolation(_ON);
#endif
            // Analog isolation on.
            SysPowerAnalogIsolation(_ON);

            // Top isolation on.
            SysPowerTopIsolation(_ON);

            // Select internal oscillator as system clock.
            SysPowerSystemClockSelect(_IOSC_CLK);
           
            // LDO low power control.
            ScalerLDOPowerControl(_POWER_STATUS_SAVING);

            // Host control to power saving mode.
            ScalerGlobalHostControlMode(_POWER_STATUS_SAVING);
                
            // Set SI's powerboard to low power
            PCB_POWERBOARD_LOWPOWER(_LOW_POWER_ON);

#if(_SUPER_LOW_POWER_SUPPORT == _ON)

            if(enumSwitch == _POWER_ACTION_NORMAL_TO_PS)
            {
                // Set System to SLP of Power Saving
                ScalerSLPPowerStatus(_POWER_STATUS_SAVING);
            }
#endif

            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
            
            g_bSysPSIntDetect = _FALSE;

            // User Power Process
            UserInterfacePowerSwitch(enumSwitch);
            
#if(_LOW_POWER_GDI_ISOLATION == _OFF)

            ///////////////////////////////
            // Make Sure GDI Reset First //
            ///////////////////////////////

            // GDI module isolation off.
            SysPowerGDIIsolation(_OFF); 

            // Recover Data in GDI power cut area.
            SysPowerRecoverGDIAreaData();
#endif

#if(_AUDIO_SUPPORT == _ON)
            SysAudioPowerProc(enumSwitch);
#endif 
            SysSourcePowerOffProc();

            // Mode Power Off Process
            SysModeResetState(_MODE_ACTION_RESET_TO_POWER_OFF);

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
            // SDRAM power down
            ScalerSDRAMPowerControl(_OFF);
#endif
            // Interface Power Off Process
            ScalerSyncPowerProc(enumSwitch);
            
            // Set mcu module to power off state
            ScalerMcuPwmControl(_POWER_STATUS_OFF);
            
            // Set mcu module to power off state
            ScalerPinshareConfig(_POWER_STATUS_OFF);

#if(_LOW_POWER_GDI_ISOLATION == _ON)
            // GDI module isolation on.
            SysPowerGDIIsolation(_ON);
#endif
            // Analog isolation on.
            SysPowerAnalogIsolation(_ON);

            // Top isolation on.
            SysPowerTopIsolation(_ON);

            // Select internal oscillator as system clock.
            SysPowerSystemClockSelect(_IOSC_CLK);

            // LDO low power control.
            ScalerLDOPowerControl(_POWER_STATUS_OFF);

            // Host control to power down mode.
            ScalerGlobalHostControlMode(_POWER_STATUS_OFF);

            // Set SI's powerboard to low power
            PCB_POWERBOARD_LOWPOWER(_LOW_POWER_ON);

#if(_SUPER_LOW_POWER_SUPPORT == _ON)

            // Set System to SLP of Power Saving
            ScalerSLPPowerStatus(_POWER_STATUS_OFF); 
#endif

            break;
            
        case _POWER_ACTION_PS_TO_OFF:

            // User Power process
            UserInterfacePowerSwitch(enumSwitch);
            
            g_bSysPSIntDetect = _FALSE;

#if(_AUDIO_SUPPORT == _ON)
            SysAudioPowerProc(enumSwitch);
#endif      
            SysSourcePowerOffProc();

            // Interface Power Off Process
            ScalerSyncPowerProc(enumSwitch);
                        
            // Set mcu module to power off state
            ScalerMcuPwmControl(_POWER_STATUS_OFF);

            // Pin configure to power off state.
            ScalerPinshareConfig(_POWER_STATUS_OFF);

            // Host control to power down mode.
            ScalerGlobalHostControlMode(_POWER_STATUS_OFF);

#if(_SUPER_LOW_POWER_SUPPORT == _ON)

            // Set System to SLP of Power Saving
            ScalerSLPPowerStatus(_POWER_STATUS_OFF); 
#endif

            break;

        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:            

#if(_SUPER_LOW_POWER_SUPPORT == _ON)
            // SLP System Initail
            ScalerSLPSystemInitial();
#endif

#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
            if((enumSwitch == _POWER_ACTION_PS_TO_NORMAL) && (GET_DP_AUDIO_PLAYING_ALONE() == _TRUE))
            {                
                // User Power Process
                UserInterfacePowerSwitch(enumSwitch);

                SysSourceInfoReset();
                
                break;
            }
#endif            
            
            // Wake up SI's powerboard
            PCB_POWERBOARD_LOWPOWER(_LOW_POWER_OFF);
            
            // Release host control status to normal state.
            ScalerGlobalHostControlMode(_POWER_STATUS_NORMAL);                    

            // LDO to normal setting.
            ScalerLDOPowerControl(_POWER_STATUS_NORMAL);

            // GDI module isolation off.
            SysPowerGDIIsolation(_OFF);
    
            // Top isolation off.
            SysPowerTopIsolation(_OFF);

            // Analog isolation off.
            SysPowerAnalogIsolation(_OFF);

            // Select M2PLL as system clock.
            SysPowerSystemClockSelect(_M2PLL_CLK);


#if((_AUDIO_SUPPORT == _ON) && (_EMBEDDED_DAC_SUPPORT == _ON))
#if(_SLEEP_AUDIO_SUPPORT == _ON)
            if(GET_AUDIO_STATE() != _AUDIO_STATUS_PLAYBACK)
            {
                // Audio DAC initial, Initialize Audio DAC to Gain Depop Time
                ScalerAudioDACInitial();
            }
#else
            // Audio DAC initial, Initialize Audio DAC to Gain Depop Time
            ScalerAudioDACInitial();
#endif
#endif

#if(_EFFUSE_FUNCTION_SUPPORT == _ON)
            // Pop Up Effuse Data Value
            ScalerGlobalEffuseInitial();
#endif
            // Recover Data in GDI power cut area.
            SysPowerRecoverGDIAreaData();

            // Recover Data In Top Power Cut Area Block.
            SysPowerRecoverTopAreaData();

            // Recover Data In Top Power Cut Area Block.
            SysPowerRecoverAnalogAreaData();

#if(_DP_SUPPORT == _ON)
            if(enumSwitch == _POWER_ACTION_OFF_TO_NORMAL)
            {
                ScalerSyncDpHPDPowerOfftoNormalProc(UserCommonNVRamGetSystemData(_DP_HOT_PLUG_DC_OFF_HIGH));
            }
#endif
            // Sync Power On Process
            ScalerSyncPowerProc(enumSwitch);            

            // Pin configure to normal state.
            ScalerPinshareConfig(_POWER_STATUS_NORMAL);
            
            // Set mcu module to normal state
            ScalerMcuPwmControl(_POWER_STATUS_NORMAL);
               
            // User Power Process
            UserInterfacePowerSwitch(enumSwitch);
               
#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
            // SDRAM power On
            ScalerSDRAMPowerControl(_ON);

#if(_SDRAM_PHASE_CALIBRATION == _ON)
            if((enumSwitch == _POWER_ACTION_PS_TO_NORMAL) || (enumSwitch == _POWER_ACTION_OFF_TO_NORMAL))
            {
                SET_DCON_ONLINE_STATUS(_TRUE); 
                SET_CAS_CHANGE_STATUS(_FALSE);
            }
#endif

#endif
            // Clear Source Ready Flag
            SysSourceInfoReset();

            // Set Display to Free Run Mode
            SysModeSetFreeRun();
            
#if(_VGA_SUPPORT == _ON)
            // Calibrate sync processor HS delay
            ScalerIDomainModifyHsLatchEdgeDelay();
#endif
            
#if(_AUDIO_SUPPORT == _ON)
            SysAudioPowerProc(enumSwitch);
#endif             

#if(_LC_TANK_SUPPORT == _ON)
            // LC Tank Initial
            ScalerLCTankInitial();
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_NOSUPPORT_PS:

            // User Power Process
            UserInterfacePowerSwitch(enumSwitch);
            
            break;

        default:
            break;
    }
}

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
//--------------------------------------------------
// Description  : MCU Work In Idle Mode In A Short Period Of Time.
// Input Value  : None.
// Output Value : None
//--------------------------------------------------
void SysPowerIdleProc(void)
{
#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
    if((GET_DP_AUDIO_PLAYING_ALONE() == _FALSE))
    {
        // Set Timer2 Count to 100ms but Reload value remains the same(1ms)
        ScalerTimerSetTimerCount(_TIMER_OPERATION_POWER_IDLE_MODE);

        // Enter Idle Mode
        ScalerMcuIntoIdle();

        // Add Timer Counter according to Timer2
        ScalerTimerAddTimerCounter();

        // Set Timer2 Count to 1ms
        ScalerTimerSetTimerCount(_TIMER_OPERATION_POWER_SAVING_MODE);
    }
#else    
    // Set Timer2 Count to 100ms but Reload value remains the same(1ms)
    ScalerTimerSetTimerCount(_TIMER_OPERATION_POWER_IDLE_MODE);

    // Enter Idle Mode
    ScalerMcuIntoIdle();

    // Add Timer Counter according to Timer2
    ScalerTimerAddTimerCounter();

    // Set Timer2 Count to 1ms
    ScalerTimerSetTimerCount(_TIMER_OPERATION_POWER_SAVING_MODE);
#endif    
}
#endif // End of #if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)

//--------------------------------------------------
// Description  : Get Current System Power Status.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE SysPowerGetPowerStatus(void)
{
    return GET_POWER_STATUS();
}

//--------------------------------------------------
// Description  : Clock Select For System.
// Input Value  : ucClockSel    --> System refernce clock select.
// Output Value : None
//--------------------------------------------------
void SysPowerSystemClockSelect(BYTE ucClockSel)
{
    BYTE ucGlobalIRQTemp = 0;
    
    if(ucClockSel == _M2PLL_CLK)
    {

#if(_LC_TANK_SUPPORT == _ON)
        // Power on LC Tank Clock.
        ScalerPowerLCTankPower(_ON);
#endif
        // Power on Xtal Clock.
        ScalerPowerXtalPower(_ON);

        // Power on M2PLL.
        ScalerPllM2PLLPower(_ON);

        // Backup Global IRQ Control Status
        ucGlobalIRQTemp = ScalerGlobalGetIRQControl();

        ScalerGlobalIRQControl(_DISABLE);      
               
        // Flash clock divider,target clock freq = 48M in normal mode.
        ScalerMcuFlashClockDiv(_FLASH_CLK_DIV);

        // MCU clock divider,target clock freq = 24M in normal mode.
        ScalerMcuClockDiv(_MCU_CLK_DIV);
        
        // Select CPU clock to M2PLL.
        ScalerMcuClockSel(_M2PLL_CLK);

        // Restore Global IRQ Control Status
        ScalerGlobalSetIRQControl(ucGlobalIRQTemp);

        // Set Timer Count
        ScalerTimerSetTimerCount(_TIMER_OPERATION_POWER_NORMAL_MODE);

#if(_PWM_FUNCTION_SUPPORT == _ON)
        // PWM clock select to M2PLL.
        ScalerMcuPwmClockSel(_M2PLL_CLK);
#endif

#if(_LOW_SPEED_ADC_SUPPORT == _ON)
        // ADC clock select to external Xtal.
        ScalerMcuSarAdcClkSel(_EXT_XTAL_CLK);
#endif

        // Switch GDI Clk to M2PLL
        ScalerSyncSwitchGDIClk(_M2PLL_CLK);

#if(_MHL_SUPPORT == _ON)
        // Switch MHL System Clk to M2PLL
        ScalerMHLCBUSSwitchClk(_M2PLL_CLK);
#endif

        // Xtal CLK Select to external crystal clock.
        ScalerGlobalCrystalClkSel(_EXT_XTAL_CLK);

        // Modify debounce settings for Xtal clock.
        ScalerMcuDdcDebounceSel(_EXT_XTAL_CLK);

#if(_HW_IIC_SUPPORT == _ON)
        // Modify Hardware IIC frequency divisor for Xtal clock.
        ScalerMcuHwIICSetFreqDiv(_EXT_XTAL_CLK);
#endif

        // Modify 5us delay for Flash CLK = 24.3M
        ScalerMcu5usDelayCalc(_M2PLL_CLK);

        // Internal CLK Select to M2PLL.
        ScalerGlobalSystemClkSel(_M2PLL_CLK);

    }
    else
    {
        // Internal oscillator divider.
        ScalerIOSCClockDiv(_IOSC_DIV);

        // Xtal CLK Select to INOSC
        ScalerGlobalCrystalClkSel(_IOSC_CLK);

        // Modify debounce settings for INOSC clock.
        ScalerMcuDdcDebounceSel(_IOSC_CLK);

#if(_HW_IIC_SUPPORT == _ON)        
        // Modify Hardware IIC frequency divisor for IOSC clock.
        ScalerMcuHwIICSetFreqDiv(_IOSC_CLK);
#endif

#if(_MHL_SUPPORT == _ON)
        // Switch MHL System Clk to IOSC
        ScalerMHLCBUSSwitchClk(_IOSC_CLK);
#endif

        // Switch GDI Clk to Internal Crystal.
        ScalerSyncSwitchGDIClk(_IOSC_CLK);

        // Internal CLK Select to Internal Crystal..
        ScalerGlobalSystemClkSel(_IOSC_CLK);

#if(_PWM_FUNCTION_SUPPORT == _ON)
        // PWM clock select to Xtal.
        ScalerMcuPwmClockSel(_IOSC_CLK);
#endif

#if(_LOW_SPEED_ADC_SUPPORT == _ON)
        // ADC clock select to Internal Crystal..
        ScalerMcuSarAdcClkSel(_IOSC_CLK);
#endif

        // Select CPU clock to Internal Crystal.
        ScalerMcuClockSel(_IOSC_CLK);

        // Flash clock divider,target clock freq = 7M in power saving mode.
        ScalerMcuFlashClockDiv(_FLASH_CLK_PS_DIV);

        // MCU clock divider,target clock freq = 3.5M in power saving mode.
        ScalerMcuClockDiv(_MCU_CLK_PS_DIV);

        // Set Timer Count
        ScalerTimerSetTimerCount(_TIMER_OPERATION_POWER_SAVING_MODE);

        // Modify 5us delay for Flash CLK = 7M
        ScalerMcu5usDelayCalc(_IOSC_CLK);

        // Power down M2PLL.
        ScalerPllM2PLLPower(_OFF);

        // Power down Xtal.
        ScalerPowerXtalPower(_OFF);

#if(_LC_TANK_SUPPORT == _ON)
        // Power off LC Tank Clock.
        ScalerPowerLCTankPower(_OFF);
#endif
    }
}

//--------------------------------------------------
// Description  : Power Isolation Setting For Top Module.
// Input Value  : ucOn    --> On/Off Select.
// Output Value : None
//--------------------------------------------------
void SysPowerTopIsolation(BYTE ucOn)
{
    if(ucOn == _ON)
    {
        // Record current top power isolation status.
        SET_POWER_TOP_ISO_FLG();
    }
    
    // Top block(LVDS) isolation control.
    ScalerPowerTopIsolation(ucOn);
}

//--------------------------------------------------
// Description  : Power Isolation Setting For Analog Module.
// Input Value  : ucOn    --> On/Off Select.
// Output Value : None
//--------------------------------------------------
void SysPowerAnalogIsolation(BYTE ucOn)
{
    if(ucOn == _ON)
    {
        // Record current analog power isolation status.
        SET_POWER_ANALOG_ISO_FLG();
    }
    
    // Analog block(LVDS) isolation control.
    ScalerPowerAnalogIsolation(ucOn);
}

//--------------------------------------------------
// Description  : Power Isolation Setting For GDI Module.
// Input Value  : ucOn    --> On/Off Select.
// Output Value : None
//--------------------------------------------------
void SysPowerGDIIsolation(BYTE ucOn)
{
    if(ucOn == _ON)
    {
        // Record current GDI power isolation status.
        SET_POWER_GDI_ISO_FLG();
    }
    
    // GDI block isolation control.
    ScalerPowerGDIIsolation(ucOn);
}

//--------------------------------------------------
// Description  : Recover The Data of LUT/Latch/SRAM In Top Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysPowerRecoverTopAreaData(void)
{   
    // Data table should be re-filled only power cut or AC on events.
    if(GET_POWER_TOP_ISO_FLG() == _TRUE)
    {
        // Clear Top isolation mode
        CLR_POWER_TOP_ISO_FLG();
        
        // User Power On Initial
        UserInterfaceOsdPowerOnInitial();

        // Initialize Osd Position
        ScalerGlobalOsdInitial();

        // DPLL power up
        ScalerPllSetDpllReset();      
    }
}

//--------------------------------------------------
// Description  : Recover The Data of LUT/Latch/SRAM In Top Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysPowerRecoverAnalogAreaData(void)
{   
    // Data table should be re-filled only power cut or AC on events.
    if(GET_POWER_ANALOG_ISO_FLG() == _TRUE)
    {
        // Clear Top isolation mode
        CLR_POWER_ANALOG_ISO_FLG();

        // LVDS Port Power On recover
        ScalerDisplayInitialTable();
    }
}

//--------------------------------------------------
// Description  : Recover The Data of HDCP In Gdi Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysPowerRecoverGDIAreaData(void)
{
    if(GET_POWER_GDI_ISO_FLG() == _TRUE)
    {
#if(_DP_SUPPORT == _ON)
        // Recover Dp Mac and Aux Setting
        ScalerDpInitial();        
#endif
        
#if(_DIGITAL_PORT_SUPPORT == _ON)
        // Recover HDCP key.
        SysPowerRecoverHDCPKey();        
#endif
        // Clear Top isolation mode
        CLR_POWER_GDI_ISO_FLG();
    }
}

//--------------------------------------------------
// Description  : Set Power Action for other layer
// Input Value  : ucAction    --> Power Action
// Output Value : None
//--------------------------------------------------
void SysPowerSetTargetPowerStatus(EnumPowerStatus enumPorStatus)
{
    SET_TARGET_POWER_STATUS(enumPorStatus);
}

#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Recover The Data of HDCP In Gdi Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysPowerRecoverHDCPKey(void)
{
    BYTE ucI = 0;
    BYTE pucTemp[16];

    ScalerSyncHdcpEnableDownLoadKey(_ENABLE);

    for(ucI = 0; ucI < 20; ucI++)
    {
        UserInterfaceGetHDCPKey((ucI * 16), 16, pucTemp);
        ScalerSyncHdcpDownLoadKey(16, pucTemp);
    }

    if(g_bSysPSIntDetect == _FALSE)
    {
        UserInterfaceGetHDCPKeyBKsv(0, 5, pucTemp);
        
        ScalerSyncHdcpDownLoadBKsv(0, 5, pucTemp);
    }

    ScalerSyncHdcpEnableDownLoadKey(_DISABLE);
}
#endif
