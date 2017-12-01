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
// ID Code      : ScalerGlobal.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_GLOBAL__

#include "ScalerFunctionInclude.h"

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


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerGlobalWholeChipReset(void);
void ScalerGlobalHostControlMode(EnumPowerStatus enumPorStatus);
void ScalerGlobalWatchDog(bit bEnable);
void ScalerGlobalFirstActiveProc(BYTE ucSourceType);
void ScalerGlobalCrystalClkSel(bit bSel);
void ScalerGlobalResetProc(BYTE ucResetTarget);
BYTE ScalerGlobalGetIRQControl(void);
void ScalerGlobalSetIRQControl(BYTE ucIRQControl);
void ScalerGlobalIRQControl(bit bEn);
void ScalerGlobalOsdInitial(void);

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)
void ScalerGlobalPreventGarbageByBacklight_EXINT0(void);
#endif

#if(_EFFUSE_FUNCTION_SUPPORT == _ON)
void ScalerGlobalEffuseInitial(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Scaler Whole Chip Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalWholeChipReset(void)
{
    // Whole chip reset 
    ScalerSetBit(CM_01_HOST_CTRL, ~_BIT0, _BIT0);

    // For Delay 10 ms 
    ScalerTimerDelayXms(10);
    
    // Clear to 0 
    ScalerSetBit(CM_01_HOST_CTRL, ~_BIT0, 0x00);
}

//--------------------------------------------------
// Description  : Host Control to Power Down Mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalHostControlMode(EnumPowerStatus enumPorStatus)
{
    switch(enumPorStatus)
    {
        case _POWER_STATUS_OFF:
            // Host control to power-down mode 
            ScalerSetBit(CM_01_HOST_CTRL, ~_BIT2, _BIT2);
            
            break;
            
        case _POWER_STATUS_SAVING:
            // Host control to power-saving mode 
            ScalerSetBit(CM_01_HOST_CTRL, ~_BIT1, _BIT1);
            break;

        case _POWER_STATUS_NORMAL:
        default:
            
            // Host control to normal mode 
            ScalerSetBit(CM_01_HOST_CTRL, ~(_BIT2 | _BIT1), 0x00);
            
            break;
    }
}

//--------------------------------------------------
// Description  : Enabel Global Watch Dog
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerGlobalWatchDog(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        if(GET_MEMORY_SELECT() == _FRAME_SYNC_LINE_BUFFER)
        {
            // Set Free Run DVTotal = WD-Triggering DVTotal + 1 to Prevent DVTotal Too Long
            ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0B_DISP_DV_TOTAL_H, 2, pData, _AUTOINC);
            PDATA_WORD(0) += 1;            
            
            ScalerSetBit(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(PDATA_WORD(0))) & 0x0F);
            ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, (LOBYTE(PDATA_WORD(0))));                        
        }
        
        // Set Background Color to Black
        ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);  

        // Disable WD First and Clear VS Timeout Flag
        ScalerSetByte(CM_0C_WATCH_DOG_CTRL0, 0x00); 
        
#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)        
     
        // Clear Buffer Status and Input HVsync error flag
        ScalerSetByte(CM_02_STATUS0, 0x00);        

        // Internal IRQ Enable (Global)
        ScalerGlobalIRQControl(_ENABLE);
            
        // Enable Input HVsync error IRQ and fifo under/overflow IRQ
        ScalerSetBit(CM_04_IRQ_CTRL0, ~(_BIT5 | _BIT1), (_BIT5 | _BIT1));
        
        EX0 = 1;  
#else
       
        // Clear Buffer Status
        ScalerSetByte(CM_02_STATUS0, 0x00);

        // Enable Input H/V Error WD & WD Action
        ScalerSetBit(CM_0C_WATCH_DOG_CTRL0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1), (_BIT7 | _BIT6 | _BIT2 | _BIT1));
        
        // Enable Frame Sync WD
        ScalerSetBit(CM_0C_WATCH_DOG_CTRL0, ~(_BIT5 | _BIT3), (_BIT5 | _BIT3)); 
#endif
    }
    else
    {
#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)        
        // Disable Input HVsync error IRQ and fifo under/overflow IRQ
        ScalerSetBit(CM_04_IRQ_CTRL0, ~(_BIT5 | _BIT1), 0x00);  
#else
        ScalerSetByte(CM_0C_WATCH_DOG_CTRL0, 0x00);
#endif
    }
}

//--------------------------------------------------
// Description  : Process Required when Switched to Active State
// Input Value  : Input Source
// Output Value : None
//--------------------------------------------------
void ScalerGlobalFirstActiveProc(BYTE ucSourceType)
{
    // Enable Watch Dog
    ScalerGlobalWatchDog(_ENABLE);

    ScalerVgipDoubleBufferEnable(_ENABLE);
       
    switch(ucSourceType)
    {

#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

#if(_ADCNR_BY_HISTOGRAM_SUPPORT == _ON)
            ScalerNrInitial();
#endif
            break;
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
        case _SOURCE_DVI:
        case _SOURCE_HDMI:
            
            ScalerTmdsFirstActiveProc(ucSourceType);
            
            break;
#endif

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:        
            
            // Enable DP Fifo Under/OverFlow Watch Dog
            ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_CA_DP_VWD_CTRL, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));                        

            break;            
#endif

        default:
            break;
    }        

#if(_SDRAM_PHASE_CALIBRATION == _ON)
    g_ucPhaseCycle = 1; 
    g_ucPhaseCntCheck = 0;     
    SET_CAS_CHANGE_STATUS(_FALSE);
    ScalerTimerActiveTimerEvent(SEC(60), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);
#endif

#if((_DCC_HISTOGRM_INFO == _ON) && (_DCC_HISTOGRAM_THD_CHANGE == _ON))
    ScalerTimerActiveTimerEvent((WORD)(((DWORD)_PANEL_DH_TOTAL * _PANEL_DV_TOTAL * 2) / GET_D_CLK_FREQ()), _SCALER_TIMER_EVENT_DCC_HISTOGRAM_THD_CHANGE);
#endif

}

//--------------------------------------------------
// Description  : Select internal oscillator Clock.
// Input Value  : bSel    --> _TRUE: Xtal, _FALSE: M2PLL.
// Output Value : None
//--------------------------------------------------
void ScalerGlobalCrystalClkSel(bit bSel)
{
    if(bSel == _IOSC_CLK)
    {
        // Select at internal Xtal.
        ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT3, _BIT3);
    }
    else if(bSel == _EXT_XTAL_CLK)
    {
        // Select at external Xtal.
        ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT3, 0x00);
    }
}

//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : None
//--------------------------------------------------
void ScalerGlobalResetProc(BYTE ucResetTarget)
{
    switch(ucResetTarget)
    {  
        case _MODE_ACTION_RESET_TO_SEARCH:                

            // Set Background Color to Black
            ScalerDDomainBackgroundSetColor(0, 0, 0);
            ScalerDDomainBackgroundEnable(_ENABLE);

            ScalerGlobalWatchDog(_DISABLE);
            
            ScalerVgipDoubleBufferEnable(_DISABLE);

            ScalerSyncResetProc();

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))
            ScalerGlobalSetInterrupt(_IRQ_IVS, _DISABLE);
            ScalerGlobalSetInterrupt(_IRQ_DVS, _DISABLE);
#endif

#if(_SDRAM_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CALIBRATION);
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CNT_CHECK);
#endif

            break;
            
        case _MODE_ACTION_RESET_TO_DISPLAY_SETTING:

            // Set Background Color to Black
            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
            ScalerDDomainBackgroundSetColor(0, 0, 0);
            ScalerDDomainBackgroundEnable(_ENABLE);
            
            ScalerGlobalWatchDog(_DISABLE);

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))
            ScalerGlobalSetInterrupt(_IRQ_IVS, _DISABLE);
            ScalerGlobalSetInterrupt(_IRQ_DVS, _DISABLE);
#endif

#if(_SDRAM_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CALIBRATION);
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CNT_CHECK);
#endif

            break;

#if(_3D_SUPPORT == _ON)
        case _MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG:

            ScalerGlobalWatchDog(_DISABLE);

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
            ScalerGlobalSetInterrupt(_IRQ_IVS, _DISABLE);
            ScalerGlobalSetInterrupt(_IRQ_DVS, _DISABLE);
#endif

#if(_SDRAM_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CALIBRATION);
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CNT_CHECK);
#endif

            break;
#endif

        case _MODE_ACTION_RESET_TO_POWER_SAVING:
        case _MODE_ACTION_RESET_TO_POWER_OFF:
        
            ScalerGlobalWatchDog(_DISABLE);
            
            ScalerSyncResetProc();

#if(_SDRAM_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CALIBRATION);
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CNT_CHECK);
#endif

            break;         
            
        default:
            
            break;
    }

#if(_OD_SUPPORT == _ON)
    ScalerODControl(_OFF);
#endif

#if((_DCC_HISTOGRM_INFO == _ON) && (_DCC_HISTOGRAM_THD_CHANGE == _ON))
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DCC_HISTOGRAM_THD_CHANGE);
#endif

}

//--------------------------------------------------
// Description  : Get Global IRQ Control Register
// Input Value  : None
// Output Value : CM_14_IRQ_CTRL0 Register Value
//--------------------------------------------------
BYTE ScalerGlobalGetIRQControl(void)
{
    return ScalerGetByte(CM_04_IRQ_CTRL0);
}

//--------------------------------------------------
// Description  : Set Global IRQ Control Register
// Input Value  : CM_14_IRQ_CTRL0 Register Value
// Output Value : None
//--------------------------------------------------
void ScalerGlobalSetIRQControl(BYTE ucIRQControl)
{
    ScalerSetByte(CM_04_IRQ_CTRL0, ucIRQControl);
}

//--------------------------------------------------
// Description  : Set Global IRQ Control Register
// Input Value  : CM_14_IRQ_CTRL0 Register Value
// Output Value : None
//--------------------------------------------------
void ScalerGlobalIRQControl(bit bEn)
{
    if(bEn == _ENABLE)
    {
        ScalerSetBit(CM_04_IRQ_CTRL0, ~_BIT7, _BIT7);        
    }
    else
    {
        ScalerSetBit(CM_04_IRQ_CTRL0, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Initialize OSD Position Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalOsdInitial(void)
{
#if(_OSD_POSITION_SELF_ALIGNMENT == _ON)
    SET_OSD_POSITION_OFFSET_H(_OSD_POSITION_OFFSET_H);
    SET_OSD_POSITION_OFFSET_V(_OSD_POSITION_OFFSET_V);
    SET_OSD_WINDOW_START_OFFSET(_OSD_OFFSET_DRAW_WINDOW);

#else
    SET_OSD_POSITION_OFFSET_H(0);
    SET_OSD_POSITION_OFFSET_V(0);
    SET_OSD_WINDOW_START_OFFSET(0);

#endif

    ScalerOsdPosition(_OSD_POSITION_FONT_A, 0, 0);
    ScalerOsdPosition(_OSD_POSITION_FONT_B, 0, 0);
    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_ENA);
}

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)
//--------------------------------------------------
// Description  : Check if fifo underflow or overflow, turn off backlight
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalPreventGarbageByBacklight_EXINT0(void) using 1
{
    if(((ScalerGetBit_EXINT0(CM_02_STATUS0, (_BIT1 | _BIT0)) != 0x00) && (ScalerGetBit_EXINT0(CM_04_IRQ_CTRL0, _BIT1) == _BIT1)) || 
       ((ScalerGetBit_EXINT0(CM_02_STATUS0, (_BIT6 | _BIT5)) != 0x00) && (ScalerGetBit_EXINT0(CM_04_IRQ_CTRL0, _BIT5) == _BIT5)))        
    {                
#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
        // Disable LED Booster En
        ScalerSetBit_EXINT0(P16_A0_LEDBC_DRIVER_CTRL1, ~_BIT5, 0x00);
#else
        PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF);
#endif

        // Set force to background and free run mode
        ScalerSetBit_EXINT0(CM_28_VDISP_CTRL, ~(_BIT5 | _BIT3), _BIT5);

        // Disable Input HVsync error IRQ and fifo under/overflow IRQ
        ScalerSetBit_EXINT0(CM_04_IRQ_CTRL0, ~(_BIT5 | _BIT1), 0x00);        
    }
}
#endif // End of #if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)

#if(_EFFUSE_FUNCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Scaler Effuse Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalEffuseInitial(void)
{
    // Pop Up Efuse Results
    ScalerSetBit(P24_A2_EFUSE_CTRL, ~(_BIT5 | _BIT4), _BIT4);
    ScalerTimerPollingFlagProc(20, P24_A2_EFUSE_CTRL, _BIT4, _FALSE);
}
#endif

