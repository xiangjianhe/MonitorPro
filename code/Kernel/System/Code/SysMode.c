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
// ID Code      : SysMode.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_MODE__

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
StructModeInfoType idata g_stModeInfo = {0};
// ModeInfo bit[0:4] -- Mode State
// ModeInfo bit[5] -- Display Ready
// ModeInfo bit[6] -- Timing Confirm
// ModeInfo bit[7] -- ModeStateChanged

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysModeHandler(void);
BYTE SysModeGetModeState(void);
bit SysModeGetDisplaySettingReady(void);
bit SysModeGetTimingConfirm(void);
bit SysModeGetActiveReady(void);
bit SysModeDisplaySetting(void);
void SysModeSetUpInputCapture(void);
void SysModeSetUpDisplayCapture(void);
bit SysModeSetUpMDomain(void);
void SysModeResetState(BYTE ucResetTarget);
void SysModeSetFreeRun(void);
bit SysModeGetModeStateChange(void);
void SysModeSetResetTarget(EnumModeAction enumResetTarget);
void SysModeColorSpaceConvert(EnumColorSpace enumColorFormat);
void SysModeDisplayTimingInitial(void);    
//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysModeHandler(void)
{                    
    switch(GET_MODE_STATE())
    {
        case _MODE_STATUS_POWER_OFF:

            break;
            
        case _MODE_STATUS_INITIAL:            

            break;

        case _MODE_STATUS_SEARCH:
        case _MODE_STATUS_NOSIGNAL:
        case _MODE_STATUS_POWER_SAVING:            
            
            if((GET_SOURCE_JUDGE(g_ucSearchIndex) == _TRUE) && (GET_MODE_TIMING_CONFIRM() == _FALSE))
            {            
                CLR_INPUT_TIMING_DOUBLE_CHECK();
                
                // Measure Current Input Timing to gather all required timing Info
                if(ScalerMeasureInputInfo(GET_SOURCE_TYPE(g_ucSearchIndex)) == _TRUE)
                {
                    DebugMessageSystem("Input Timing HFreq", GET_INPUT_TIMING_HFREQ());
                    DebugMessageSystem("Input Timing HTotal", GET_INPUT_TIMING_HTOTAL());                    
                    DebugMessageSystem("Input Timing HStart", GET_INPUT_TIMING_HSTART());
                    DebugMessageSystem("Input Timing HWidth", GET_INPUT_TIMING_HWIDTH());
                    DebugMessageSystem("Input Timing Hsync Polarity", GET_INPUT_TIMING_H_POLARITY());
                    DebugMessageSystem("Input Timing Hsync Width", GET_INPUT_TIMING_HSYNCWIDTH());
                    DebugMessageSystem("Input Timing VFreq", GET_INPUT_TIMING_VFREQ());
                    DebugMessageSystem("Input Timing VTotal", GET_INPUT_TIMING_VTOTAL());
                    DebugMessageSystem("Input Timing VStart", GET_INPUT_TIMING_VSTART());
                    DebugMessageSystem("Input Timing VHeight", GET_INPUT_TIMING_VHEIGHT());
                    DebugMessageSystem("Input Timing Vsync Polarity", GET_INPUT_TIMING_V_POLARITY());
                    DebugMessageSystem("Input Timing Vsync Width", GET_INPUT_TIMING_VSYNCWIDTH());
                    
                    SET_MODE_TIMING_CONFIRM(); 
                    SET_INPUT_TIMING_DOUBLE_CHECK();
                }                
            }

#if(_SDRAM_PHASE_CALIBRATION == _ON)
            if((GET_MODE_TIMING_CONFIRM() == _TRUE) && (GET_FIRST_AUTOK_STATUS() == _FALSE))
            {
                SET_FIRST_AUTOK_STATUS(_TRUE);
                ScalerSDRAMPhaseSearch();
                SET_DCON_ONLINE_STATUS(_FALSE);
            }
            else if((GET_DCON_ONLINE_STATUS() == _TRUE))
            {
                SET_DCON_ONLINE_STATUS(_FALSE);
               
                ScalerSDRAMPhaseDCOnCheck(_SDRAM_PHASE_ON_LINE_ADDRESS); 

                if(GET_CAS_CHANGE_STATUS() == _TRUE)
                {
                    ScalerSDRAMPhaseDCOnCheck(_SDRAM_PHASE_ON_LINE_ADDRESS);  
                }
            }       
#endif

            if((GET_MODE_STATE() == _MODE_STATUS_POWER_SAVING) && (GET_SOURCE_SWITCH_FINISH() == _TRUE) && (UserInterfaceCheckIntoPS() == _TRUE))
            {                                    
                SET_TARGET_POWER_STATUS(_POWER_STATUS_SAVING);
                CLR_SOURCE_SWITCH_FINISH();
            }            

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
            if((GET_MODE_STATE() == _MODE_STATUS_NOSIGNAL) || (GET_MODE_STATE() == _MODE_STATUS_POWER_SAVING))
#endif
            {

#if(_SUPER_LOW_POWER_SUPPORT == _OFF)
                if(UserInterfaceCheckCableReset() == _TRUE)
                {
                    if(GET_POWER_STATUS() != _POWER_STATUS_NORMAL)
                    {
                        SET_TARGET_POWER_STATUS(_POWER_STATUS_NORMAL);
                    }

                    SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);

                    SysSourceCableResetProc();
                }
#endif
            }    
            
            break;
            
        case _MODE_STATUS_DISPLAY_SETTING:

            if(GET_MODE_DISPLAY_SETTING_READY() == _FALSE)
            {
                if(SysModeDisplaySetting() == _TRUE)
                {
#if(_PANEL_POW_SEQ_FAST_MODE == _ON)                    
                    UserInterfacePanelPowerAction(_PANEL_ON);
#endif                    
                    UserCommonInterfaceAdjustColorProc();

                    SET_MODE_DISPLAY_SETTING_READY();

                    SET_MODE_RESET_TARGET(_MODE_ACTION_NO_RESET_MODE);

                    ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE);                                                    

#if(_LC_TANK_SUPPORT == _ON)
                    // Start DPLL offset regulation
                    ScalerTimer1SetTimerCount(_TIMER_COUNT_25_MS);
#endif
                }
            }
            
            break;
            
        case _MODE_STATUS_ACTIVE:

            if(GET_MODE_STATE_CHANGE() == _TRUE)
            {
                ScalerGlobalFirstActiveProc(GET_SOURCE_TYPE(g_ucSearchIndex)); 
                UserCommonInterfaceOsdActiveProc();                    
                UserInterfacePanelPowerAction(_BACKLIGHT_ON);
                SysSourceFirstActiveProc();                
            }
                            
            ScalerSyncActiveProc(GET_SOURCE_TYPE(g_ucSearchIndex));
            
            break;
            
        case _MODE_STATUS_NOSUPPORT:
                
            break;        

        case _MODE_STATUS_FACTORY:
            
            break;
            
        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Return Mode State for other Group
// Input Value  : None
// Output Value : Mode State
//--------------------------------------------------
BYTE SysModeGetModeState(void)
{
    return GET_MODE_STATE();
}

//--------------------------------------------------
// Description  : Return Mode Display Setting Ready
// Input Value  : None
// Output Value : Mode State
//--------------------------------------------------
bit SysModeGetDisplaySettingReady(void)
{
    return GET_MODE_DISPLAY_SETTING_READY();
}

//--------------------------------------------------
// Description  : Return Mode Timing Confirm
// Input Value  : None
// Output Value : Mode State
//--------------------------------------------------
bit SysModeGetTimingConfirm(void)
{
    return GET_MODE_TIMING_CONFIRM();
}

//--------------------------------------------------
// Description  : Return Mode Active Ready
// Input Value  : None
// Output Value : Mode State
//--------------------------------------------------
bit SysModeGetActiveReady(void)
{
    return GET_MODE_ACTIVE_READY();
}

//--------------------------------------------------
// Description  : Include all required settings for Display
// Input Value  : Input Source Type
// Output Value : None
//--------------------------------------------------
bit SysModeDisplaySetting(void)
{   
    // Copy Input Timing to I Domain Timing as initial value
    SET_MDOMAIN_INPUT_STRUCTURE(g_stInputTimingData);

    // Set Up Input Timing to I Domain
    SysModeSetUpInputCapture();
    
    // Set D Domain Functions
    SysModeSetUpDisplayCapture();    

    // Set M Domain Functions
    if(SysModeSetUpMDomain() == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Set Up stuffs into I-Domain
// Input Value  : Timing Info Into VGIP
// Output Value : None
//--------------------------------------------------
void SysModeSetUpInputCapture(void)
{    
    // Add Required Functions to Modify Input Timing    

    if(GET_MDOMAIN_INPUT_VSTART() >= (GET_MDOMAIN_INPUT_VTOTAL() - GET_MDOMAIN_INPUT_VHEIGHT() + 1))
    {    
        SET_MDOMAIN_INPUT_VSTART((GET_MDOMAIN_INPUT_VTOTAL() - GET_MDOMAIN_INPUT_VHEIGHT()));
    } 

    if((GET_MDOMAIN_INPUT_HWIDTH() % 2) != 0x00)
    {
        // We should let H-width is even integer in case of the width of memory FIFO read width must even integer.
        SET_MDOMAIN_INPUT_HWIDTH(GET_MDOMAIN_INPUT_HWIDTH() + 1);
    }

    UserCommonInterfaceAdjustInputTiming();

    ScalerIDomainVgipSetInputCapture();

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON) || (_OD_SUPPORT == _ON)) 
    ScalerDisplaySelectDVFMode();
#endif

#if(_3D_SUPPORT == _ON)
    ScalerVgipMaskSignal();  
    ScalerColorAdjust2DTo3DAnd3DEffect();
#endif // End of #if(_3D_SUPPORT == _ON)
}

//--------------------------------------------------
// Description  : Set Up I-Domain
// Input Value  : Timing Info Into D Domain
// Output Value : None
//--------------------------------------------------
void SysModeSetUpDisplayCapture(void)
{
    // Initialize Display Timing
    SysModeDisplayTimingInitial();
    
    UserInterfaceAdjustDisplayTiming();         
}

//--------------------------------------------------
// Description  : Set Up M-Domain
// Input Value  : Timing Info Into M Domain
// Output Value : None
//--------------------------------------------------
bit SysModeSetUpMDomain(void)
{    
    if(ScalerMDomainControl() == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Mode Reset 
// Input Value  : Reset Target
// Output Value : None
//--------------------------------------------------
void SysModeResetState(BYTE ucResetTarget)
{
    DebugMessageSystem("SysModeResetState!!", ucResetTarget);

    switch(ucResetTarget)
    {        
        case _MODE_ACTION_RESET_TO_SEARCH:

#if(_LC_TANK_SUPPORT == _ON)
            // Stop DPLL offset regulation
            ScalerTimer1SetTimerCount(_TIMER_OFF);
#endif
                
            // User Reset Process
            UserCommonInterfaceOsdResetProc();

            // Clear Source Ready Flag            
            SysSourceInfoReset();        

            // Clear Measure Ready Flag
            CLR_MODE_TIMING_CONFIRM();        

            // Clear M Domain Ready Flag
            CLR_MODE_DISPLAY_SETTING_READY();           

            // Clear No Wait For Active Flag
            CLR_MODE_NO_WAIT_FOR_ACTIVE();

            // Clear Mode Active Ready Flag
            CLR_MODE_ACTIVE_READY();
            
            SysModeSetFreeRun();
            
            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_ACTIVE_STATE);            
            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_NOSIGNAL_STATE);
            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE);

           break;
            
        case _MODE_ACTION_RESET_TO_DISPLAY_SETTING:

#if(_LC_TANK_SUPPORT == _ON)
            // Stop DPLL offset regulation
            ScalerTimer1SetTimerCount(_TIMER_OFF);
#endif

            if(GET_MODE_STATE() != _MODE_STATUS_ACTIVE)
            {
                // User Reset Process
                UserCommonInterfaceOsdResetProc();
            }

            // Clear M Domain Ready Flag
            CLR_MODE_DISPLAY_SETTING_READY();                    

            // Set No Wait For Active Flag
            SET_MODE_NO_WAIT_FOR_ACTIVE();

            // Clear Mode Active Ready Flag
            CLR_MODE_ACTIVE_READY();            
            

            break;

#if(_3D_SUPPORT == _ON)
        case _MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG:

            if(GET_MODE_STATE() != _MODE_STATUS_ACTIVE)
            {
                // User Reset Process
                UserCommonInterfaceOsdResetProc();
            }

            // Clear M Domain Ready Flag
            CLR_MODE_DISPLAY_SETTING_READY();                    

            // Set No Wait For Active Flag
            SET_MODE_NO_WAIT_FOR_ACTIVE();

            // Clear Mode Active Ready Flag
            CLR_MODE_ACTIVE_READY();            
            
            break;
#endif

        case _MODE_ACTION_RESET_TO_NOSUPPORT:

            if(GET_MODE_STATE() == _MODE_STATUS_DISPLAY_SETTING)
            {
                // Clear M Domain Ready Flag
                CLR_MODE_DISPLAY_SETTING_READY();           
                
                SysModeSetFreeRun();            
            }
           
            break;

        case _MODE_ACTION_RESET_TO_POWER_SAVING:
                
            // User Reset Process
            UserCommonInterfaceOsdResetProc();

            // Clear Source Ready Flag            
            SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);

            // Clear Source Judge 
            CLR_SOURCE_JUDGE(g_ucSearchIndex);

            // Clear Measure Ready Flag
            CLR_MODE_TIMING_CONFIRM();        

            // Clear M Domain Ready Flag
            CLR_MODE_DISPLAY_SETTING_READY();           

            // Clear No Wait For Active Flag
            CLR_MODE_NO_WAIT_FOR_ACTIVE();

            // Clear Mode Active Ready Flag
            CLR_MODE_ACTIVE_READY();            
                                    
            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_ACTIVE_STATE);            
            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_NOSIGNAL_STATE);
            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE);

            break;
            
        case _MODE_ACTION_RESET_TO_POWER_OFF:

#if(_LC_TANK_SUPPORT == _ON)
            // Stop DPLL offset regulation
            ScalerTimer1SetTimerCount(_TIMER_OFF);
#endif
            
            // User Reset Process
            UserCommonInterfaceOsdResetProc();          

            // Clear Source Ready Flag            
            SysSourceInfoReset();        

            CLR_SOURCE_HP_SOURCE_JUDGE();

            // Clear Measure Ready Flag
            CLR_MODE_TIMING_CONFIRM();        

            // Clear M Domain Ready Flag
            CLR_MODE_DISPLAY_SETTING_READY();    

            // Clear No Wait For Active Flag
            CLR_MODE_NO_WAIT_FOR_ACTIVE();

            // Clear Mode Active Ready Flag
            CLR_MODE_ACTIVE_READY();            
            
            // Judge Reset Process
            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_ACTIVE_STATE);            

            break;
            
        default:
            break;
    }        

    ScalerGlobalResetProc(ucResetTarget);
}

//--------------------------------------------------
// Description  : Set Free Run Mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysModeSetFreeRun(void)
{
    // Set D Domain Timing
    SysModeDisplayTimingInitial();
    
    ScalerMDomainSetDisplayFormat(_FREE_RUN_NO_INPUT);

    // Enable Spread Spectrum
    ScalerPllSetDpllSsc(_DCLK_SPREAD_SPEED, _DCLK_SPREAD_RANGE);    
}

//--------------------------------------------------
// Description  : Mode State Change Flag for other layer
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit SysModeGetModeStateChange(void)
{
    return GET_MODE_STATE_CHANGE();
}

//--------------------------------------------------
// Description  : Set Reset Status for User
// Input Value  : Target Reset State
// Output Value : None
//--------------------------------------------------
void SysModeSetResetTarget(EnumModeAction enumResetTarget)
{
    SET_MODE_RESET_TARGET(enumResetTarget);
}

//--------------------------------------------------
// Description  : Let User Specify Which Color Space is used
// Input Value  : Target Color Space
// Output Value : None
//--------------------------------------------------
void SysModeColorSpaceConvert(EnumColorSpace enumColorFormat)
{
#if(_VGA_SUPPORT == _ON)
    if(GET_SOURCE_TYPE(g_ucSearchIndex) == _SOURCE_VGA)
    {           
        ScalerADCClampMode(enumColorFormat);

        // Download adc data from NVRam
        UserCommonNVRamLoadADCSetting(enumColorFormat);

        // Gain Offset Adjust.
        UserCommonInterfaceAdjustADCData();        
    }
#endif

    ScalerColor422To444();

    ScalerColorSpaceConvert(enumColorFormat);

    // Adjust Dither
#if(_I_DITHER_SUPPORT == _ON)
    UserCommonAdjustIDither();
#endif

}

//--------------------------------------------------
// Description  : Give Display Timing Initial Value
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysModeDisplayTimingInitial(void)
{
    // Set Up Display Timing According to Panel Spec
    SET_MDOMAIN_OUTPUT_HWIDTH(_PANEL_DH_WIDTH);
    SET_MDOMAIN_OUTPUT_HBWIDTH(_PANEL_DH_WIDTH);
    SET_MDOMAIN_OUTPUT_HTOTAL(_PANEL_DH_TOTAL);
    SET_MDOMAIN_OUTPUT_HSTART(_PANEL_DH_START);

    SET_MDOMAIN_OUTPUT_VHEIGHT(_PANEL_DV_HEIGHT);
    SET_MDOMAIN_OUTPUT_VBHEIGHT(_PANEL_DV_HEIGHT);    
    SET_MDOMAIN_OUTPUT_VTOTAL(_PANEL_DV_TOTAL);
    SET_MDOMAIN_OUTPUT_VSTART(_PANEL_DV_START);       
}
