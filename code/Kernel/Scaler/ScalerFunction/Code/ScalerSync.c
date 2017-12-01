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
// ID Code      : ScalerSync.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_SYNC__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) || (_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || ((_DVI_SUPPORT != _ON) && (_HDMI_SUPPORT != _ON)))
#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)
#warning "Z0 Toggle Solution Is Not Available !!!!"
#endif
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//--------------------------------------------------
// Enumerations of SyncProc/AutoFunc Measure Mode
//--------------------------------------------------
typedef enum
{
    _SOG_LEVEL_VALID,
    _SOG_LEVEL_INVALID,
    _SOG_LEVEL_FAIL,
} EnumSogLevelSearchResult;
 
//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
WORD idata g_usInputPixelClk = 0;

#if(_VGA_SUPPORT == _ON)
WORD idata g_usAdcClockLimit = _PIXEL_WIDTH_LIMIT;
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
BYTE idata g_ucHdcpBksvBackup[5] = {0};
BYTE xdata g_ucDigitalSwitch = 0;
BYTE xdata g_ucHDMIHotPlug = 0;

#if(_FREESYNC_SUPPORT == _ON)

#if(_HDMI_FREESYNC_SUPPORT == _ON)
StructHDMIFREESYNCENABLE g_stHDMIFREESYNCInfo;

#if(_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE)
BYTE g_ucHDMIFREESYNCVCPReceive;
#endif
#endif

BYTE g_ucFREESYNCSupport;
WORD g_usFREESYNCVFreq;
#endif

#endif

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)
bit idata g_bTmdsD0Z0Toggle = 0;
bit idata g_bTmdsD1Z0Toggle = 0;
bit idata g_bTmdsGlobalZ0Toggle = 0;
#endif

#if(_MHL_SUPPORT == _ON)
StructMHLProcessInfo g_stMHLProcess[_MHL_PORT_VALID] = {0};
bit g_bMHLPortActive = 0;
#endif

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
BYTE ScalerSyncGetHDMIFREESYNCVcp_EXINT1(void);
void ScalerSyncSetHDMIFREESYNCVcp_EXINT1(BYTE ucVcpCode);
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_VGA_SUPPORT == _ON)
void ScalerSyncVgaScanInitial(void);
bit ScalerSyncVgaPreDetect(void);
bit ScalerSyncVgaStableDetect(void);
void ScalerSyncVgaAdcInitial(void);
void ScalerSyncVgaSyncProcInitial(void);
bit ScalerSyncVgaHSSyncStableDetect(void);
bit ScalerSyncVgaSyncStableCheck(void);
WORD ScalerSyncGetDeVsyncWidth(void) ;
BYTE ScalerSyncVgaSyncTypeAutoRun(void);
bit ScalerSyncVgaAdcClkInitial(void);
void ScalerSyncVgaSyncProcClampPosCheck(BYTE ucVideoModeFlg);
bit ScalerSyncVgaAdcClkSetting(void);

#if(_SOG_SUPPORT == _ON)
EnumSogLevelSearchResult ScalerSyncVgaSogCheckFlag(BYTE ucTimeOutCounter);
EnumSogLevelSearchResult ScalerSyncVgaSogCheckHs(StructMeasureSyncData *stMeasureSyncHV);
EnumSogLevelSearchResult ScalerSyncVgaSogCheckVs(StructMeasureSyncData *stMeasureSyncHV, BYTE ucTimeOutCounter);
bit ScalerSyncVgaSogSyncCheck(void);
#endif
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
void ScalerSyncTmdsScanInitial(BYTE ucInputPort);
bit ScalerSyncTmdsNormalPreDetect(BYTE ucInputPort);
BYTE ScalerSyncTmdsScanInputPort(BYTE ucInputType);
BYTE ScalerSyncTmdsVideoDetect(bit bWait);
void ScalerSyncTmdsVideoDetectEvent(void);
bit ScalerSyncTmdsPSPreDetect(BYTE ucInputPort);
bit ScalerSyncTmdsStableDetect(BYTE ucSourceType);

#if(_MHL_SUPPORT == _ON)
bit ScalerSyncMHLPSPreDetect(BYTE ucInputPort);
bit ScalerSyncMHLNormalPreDetect(BYTE ucInputPort);
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
BYTE ScalerSyncTMDSHdmiGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
#endif
#endif

#if(_DP_SUPPORT == _ON)
void ScalerSyncDpScanInitial(void);
bit ScalerSyncDpNormalPreDetect(void);
BYTE ScalerSyncDpScanInputPort(void);
bit ScalerSyncDpPSPreDetect(void);
bit ScalerSyncDpStableDetect(void);
void ScalerSyncDpHPDPowerOfftoNormalProc(BYTE ucDpHotPlugDCOffHighStatus);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
void ScalerSyncHdcpEnableDownLoadKey(bit bEnable);
void ScalerSyncHdcpDownLoadBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
void ScalerSyncHdcpDownLoadKey(WORD usLength, BYTE *pReadArray);
bit ScalerSyncHdcpCheckEnabled(BYTE ucInputPort);
#endif

void ScalerSyncInterlaceInitial(BYTE ucSourceType);
bit ScalerSyncInterlaceCheck(BYTE ucSourceType);

void ScalerSyncActiveProc(BYTE ucSourceType);
void ScalerSyncResetProc(void);
void ScalerSyncPowerProc(EnumPowerAction enumPowerAction);
void ScalerSyncSwitchGDIClk(BYTE ucClk);
WORD ScalerSyncGetInputPixelClk(void);
void ScalerSyncInterfaceSwitch(BYTE ucInputPortType, BYTE ucSourceSearchDelayMode);
void ScalerSyncAdcApllPowerDown(void);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
BYTE ScalerSyncPSRecover_EXINT1(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initial Setting for VGA Scanning Port(Power Normal)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncVgaScanInitial(void)
{          
    // ADC Initial Setting
    ScalerSyncVgaAdcInitial();

    // Sync Processor Initial Setting
    ScalerSyncVgaSyncProcInitial();

    // ADC Schmitt Trigger Setting
    ScalerADCSchmittTriggerSetting();

    // Initial ADC data to VGIP path swap setting.
    ScalerSetBit(CM_16_IPH_ACT_WID_H, ~(_BIT6 | _BIT5 | _BIT4), ((_A0_INPUT_SWAP_GB << 6) | (_A0_INPUT_SWAP_RB << 5) | (_A0_INPUT_SWAP_RG << 4)));
}

//--------------------------------------------------
// Description  : Signal PreDetection for VGA(Power Normal)
// Input Value  : None
// Output Value : True : VGA Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerSyncVgaPreDetect(void)
{
    // Debounce counter reference 14.318MHz sync process clock, minimum pulse width is 171ns
    // n / 14.318 / 1000 = 171 => n = 2
    ScalerSyncProcSetDebounce(0x02);

    // Enable sync pulse detect
    ScalerSyncProcPulseDetectEnable(_ENABLE);

    // Clamp trigger edge and clamp setting for initial setting
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_04_SYNC_CLAMP_CTRL0, 0x02);
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_05_SYNC_CLAMP_CTRL1, 0x01);

    if(ScalerSyncVgaHSSyncStableDetect() == _TRUE)
    {
        if(ScalerSyncVgaSyncStableCheck() == _TRUE)
        {
            return _TRUE;
        }            
    }
    else
    {
        // Inverse CS_RAW signal for repeat check status
        ScalerSetBit(CM_48_SYNC_INVERT, ~_BIT3, ((~ ScalerGetBit(CM_48_SYNC_INVERT, _BIT3)) & _BIT3));

        if(ScalerSyncVgaHSSyncStableDetect() == _TRUE)
        {
            if(ScalerSyncVgaSyncStableCheck() == _TRUE)
            {
                return _TRUE;
            }       
        }
    }

#if(_SOG_SUPPORT == _ON)
    // Enable DC Restore
    ScalerADCDCRestoreEn(_ENABLE);

    // SOG power up
    ScalerSetBit(P0_C6_ADC_POWER, ~_BIT5, _BIT5);

    // Wait for SOG Stable
    ScalerTimerDelayXms(5);  

    if(ScalerSyncVgaSogSyncCheck() == _TRUE)
    {
        if(ScalerSyncVgaSyncStableCheck() == _TRUE)
        {
            // Sync is valid
            return _TRUE;
        }           
    }

    // Disable DC Restore
    ScalerADCDCRestoreEn(_DISABLE);
    
    // SOG power down
    ScalerSetBit(P0_C6_ADC_POWER, ~_BIT5, 0x00);

    // Disable De-composite circuit
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT5, 0x00);

#endif // End of #if(_SOG_SUPPORT == _ON)

    // Disable sync pulse detect
    ScalerSyncProcPulseDetectEnable(_DISABLE);

    // Disable SyncProc Clock
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT7, _BIT7);

    return _FALSE;
}

//--------------------------------------------------
// Description  : On Line Check VGA sync stability
// Input Value  : None
// Output Value : True --> VGA Sync Stable
//                False --> VGA Sync Unstable
//--------------------------------------------------
bit ScalerSyncVgaStableDetect(void)
{
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT7, 0x00);
    
    if(ScalerGetBit(CM_4E_HSYNC_TYPE_DETECTION_FLAG, (_BIT7 | _BIT6 | _BIT5 | _BIT3)) != 0x00)
    {
        return _FALSE;
    }
    else
    {

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
        // Check porch voltage level change for chroma pattern 12
        if(ScalerSyncProcCheckPorchChange() == _TRUE)
        {
            // Toggle "Clamp-to-Top" status
            ScalerADCSetClampToTopStatus(~(ScalerADCGetClampToTopStatus()));

            DebugMessageAnalog("Toggle clamp-to-top status", ScalerADCGetClampToTopStatus());
        }
#endif                           
        return _TRUE;
    }
}    

//--------------------------------------------------
// Description  : Get VGA Sync Pad
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerSyncVgaGetSyncPad(void)
{
    return (bit)(ScalerGetBit(CM_47_SYNC_SELECT, _BIT4));
}

//--------------------------------------------------
// Description  : ADC Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncVgaAdcInitial(void)
{
    // Adc output clock setting
    ScalerADCOutputClkSetting();
    
    // ADC Power control setting
    ScalerADCPowerSetting();
    
    // ADC bias current setting
    ScalerADCBiasCurrentSetting();
       
    // ADC Port Select to Port0, select differential signal
    ScalerSetBit(P0_CE_ADC_CTL_RGB, ~(_BIT3 | _BIT2), _BIT2);    

    // ADC offset No Depend On Gain, Red Clamp Voltage 400mV    
    ScalerSetBit(P0_CF_ADC_CTL_RED, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT6);

    // ADC offset No Depend On Gain, Green Clamp Voltage 400mV    
    ScalerSetBit(P0_D0_ADC_CTL_GRN, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT6);

    // ADC offset No Depend On Gain, Blue Clamp Voltage 400mV    
    ScalerSetBit(P0_D1_ADC_CTL_BLU, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT6);

    // Enable DC Restore
    ScalerADCDCRestoreEn(_ON); // wuzanne1493

    // Disable SOG Clamp
    ScalerADCSOGClampEn(_OFF);

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)    
    // Disable Clamp to Top
    ScalerSetBit(P0_D6_ADC_CLAMP_CTRL2, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
#endif

    // Bandwitdth extra setting off
    ScalerSetBit(P0_D4_ADC_CLAMP_CTRL0, ~_BIT1, 0x00);

    // Bit3: ADC Regulator Output Not Short to Groud
    // Bit2: SOG0 Bias Current from ADC BandGap
    // Bit0: Bias Current of SOG normal
    ScalerSetBit(P0_D5_ADC_CLAMP_CTRL1, ~(_BIT3 | _BIT2 | _BIT0), _BIT2);

    // SOG0 DC restore resister is 1M, Adc Gain Range 0.25 ~ 1.25v
    ScalerSetBit(P0_D6_ADC_CLAMP_CTRL2, ~(_BIT7 | _BIT6 | _BIT3), (_BIT7 | _BIT3));

    // PGA by pass setting
    ScalerADCPGAbyPassSetting();
}

//--------------------------------------------------
// Description  : ADC Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncVgaSyncProcInitial(void)
{
    // SOG Source Select to SOG0, VGA-ADC HS/VS Source Select to Original HS/VS of ADC Source    
    ScalerSetBit(CM_47_SYNC_SELECT, ~(_BIT3 | _BIT2), 0x00);

    // G Clamp Position default Setting
    ScalerSyncProcClampPosSetting(0x04, 0x10);

    // Clamp position unit: Single ADC clock
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_06_SYNC_CLAMP_CTRL2, 0x30);

    // Coast Setting for Front porch default condition: +2/-1
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_07_SYNC_COAST_CTRL, 0x21);

    // Capture window max missing times & Capture auto increase step & Capture window initial width.
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_08_CAPTURE_WINDOW_SETTING, (_CAP_WINDOW_WIDTH_DEFAULT & 0x1F));

    // Bit6: Measure Time Clock = 4096 Xtal, Measure source select capture window
    ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_18_SYNC_TEST_MODE, ~(_BIT6 | _BIT3), (_BIT6 | _BIT3));        
}

//--------------------------------------------------
// Description  : Sync Processor Detect H/V Sync Stable for SS/CS
// Input Value  : None
// Output Value : True --> HV Stable
//                False --> HV Not Stable
//--------------------------------------------------
bit ScalerSyncVgaHSSyncStableDetect(void)
{
    BYTE ucCirCleCnt = 0;
    BYTE ucTimeOut = 0;
    BYTE ucCnt = 0;
    WORD usHSyncPeriod = 0;
    WORD usHSyncPulseCount = 0;

    if((MCU_CTRL_FFED & _BIT1) == _BIT1) // CPU clock come from M2PLL, base on 24.3M
    {
        ucTimeOut = 60;
    }
    else // CPU clock come from internal or external crystal clock, base on 3.5M
    {
        if((ScalerGetBit(CM_0B_POWER_CTRL2, _BIT0) == _BIT0) && (((MCU_CTRL_FFED & 0x3C) >> 2) == _FLASH_CLK_PS_FAST_DIV)) // 27MHz and flash clock div = 1 --> for DP Case
        {            
            ucTimeOut = 30;
        }
        else
        {
            ucTimeOut = 8;
        }
    }

    ucCirCleCnt = 5;
 
    do
    {
        ucCirCleCnt--;

        // Clear flag
        ScalerSetBit(CM_5B_HS_DETECT, ~_BIT7, _BIT7); 
        
        // For SOG Power Stable, Refernce H-Freq = 15.63k
        for(ucCnt = 0; ucCnt <= ucTimeOut; ucCnt++)
        {
            _nop_();
        }

        if(ScalerGetBit(CM_5B_HS_DETECT, _BIT7) == _BIT7)
        {                
            continue;
        }
        else
        {
            break;
        }
    }while(ucCirCleCnt > 0);
    
    if(ucCirCleCnt != 0)
    {
        return _FALSE;
    }
    
    // Enable Sync Processor Clock
    ScalerSetBit(CM_47_SYNC_SELECT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT0), 0x00);

    // HS_OUT Signal Output Enable, HS Out not invert
    ScalerSetBit(CM_48_SYNC_INVERT, ~(_BIT5 | _BIT4), _BIT4);

    // HS_OUT by pass mode, Measure Source is ADC_HS1/ADC_VS, H Sync measure source is original hs
    ScalerSetByte(CM_49_SYNC_CTRL, 0x06);
    
    // Sync from HS Pad
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT4, 0x00);

    // Start Stable Period Measure
    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT0, 0x00);
    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT0, _BIT0);

    if(ScalerTimerPollingFlagProc(12, CM_4F_STABLE_MEASURE, _BIT7, _TRUE) == _FALSE)
    {
        return _FALSE;
    }                     

    // Pop up stable result
    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT1, _BIT1);

    usHSyncPeriod = ((WORD)(ScalerGetByte(CM_50_STABLE_PERIOD_H) & 0x07) << 8) | ScalerGetByte(CM_51_STABLE_PERIOD_L);
    usHSyncPulseCount = ((WORD)(ScalerGetByte(CM_4A_STABLE_HIGH_PERIOD_H) & 0x07) << 8) | ScalerGetByte(CM_4B_STABLE_HIGH_PERIOD_L);

    if(ScalerGetBit(CM_4F_STABLE_MEASURE, _BIT6) == 0x00) // HS Negative
    {
        usHSyncPulseCount = (usHSyncPeriod - usHSyncPulseCount);
    }

    if(((usHSyncPulseCount * 7) < usHSyncPeriod) && (usHSyncPulseCount >= _MIN_SYNC_HIGHPULSE_CNT_PS))
    {
        if(ScalerTimerPollingFlagProc(_WAIT_TWO_FRAME_TIME, CM_4E_HSYNC_TYPE_DETECTION_FLAG, _BIT4, _TRUE) == _TRUE) // Saperate signal
        {
            return _TRUE;
        }

#if(_VGA_COMPOSITE_SUPPORT == _ON)
        if(ScalerGetBit(CM_4E_HSYNC_TYPE_DETECTION_FLAG, _BIT1) == _BIT1) // Composite signal, this bit need waitting for one frame
        {    
            return _TRUE;                        
        }  
#endif // End of #if(_VGA_COMPOSITE_SUPPORT == _ON)
    }              

    return _FALSE;
}


//--------------------------------------------------
// Description  : VGA Sync Stable Measure Check 3 times
// Input Value  : None
// Output Value : True --> Sync Stable
//                False --> Sync Unstable
//--------------------------------------------------
bit ScalerSyncVgaSyncStableCheck(void)
{
    BYTE ucCheckTimes = 3;

    do
    {
        ucCheckTimes--;
        
        // Start Stable Period Measure
        ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT0, 0x00);
        ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT0, _BIT0);

        if(ScalerTimerPollingFlagProc(12, CM_4F_STABLE_MEASURE, _BIT7, _TRUE) == _TRUE)
        {                   
            continue;
        }    
        else
        {
            return _FALSE;
        } 
        
    }while(ucCheckTimes > 0);

    // Down Counter Setting
    ScalerSyncProcDownCounterSetting();

    return _TRUE;
}

//--------------------------------------------------
// Description  : Get DeVS Width
// Input Value  : None
// Output Value : DeVs Width (unit : line)
//--------------------------------------------------
WORD ScalerSyncGetDeVsyncWidth(void) 
{
    PDATA_WORD(6) = _MAX_VSYNC_HIGH_PERIOD;
    
    // Capture window counter of DeVS be equaled both time, the count is V Sync pulse width
    for(pData[0] = 0; pData[0] < 10; pData[0]++)
    {
        ScalerGetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_0A_DEVS_CAP_NUM_H, 2, &pData[2], _AUTOINC);

        // Get DeVS High Period Width
        PDATA_WORD(7) = (((WORD)(pData[2] & 0x0F) << 8) | pData[3]);

        if((PDATA_WORD(7) == PDATA_WORD(6)) || (PDATA_WORD(7) >= _MAX_VSYNC_HIGH_PERIOD))
        {
            break;
        }

        // Back up current V Sync Count
        PDATA_WORD(6) = PDATA_WORD(7);
    }

    return PDATA_WORD(7);
}

//--------------------------------------------------
// Description  : VGA Sync Type Detect AutoRun
// Input Value  : None
// Output Value : Sync Type                
//--------------------------------------------------
BYTE ScalerSyncVgaSyncTypeAutoRun(void)
{
    BYTE ucSyncTemp = _NO_SYNC_STATE;

    // wuzanne1493
    if(ScalerGetBit(CM_47_SYNC_SELECT, _BIT7) == _BIT7)
    {
        return ucSyncTemp;
    }
        
    // Stop Stable Measure
    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT0, 0x00);

    // Disable Hsync Type Detection Auto Run, Disable De-Composite
    ScalerSetBit(CM_47_SYNC_SELECT, ~(_BIT6 | _BIT5), 0x00);
    
    // Enable Hsync Type Detection Auto Run
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT6, _BIT6);

    // Check the result of Auto Run
    // 120ms need change by current clock in future, by macro 
    if(ScalerTimerPollingFlagProc(_AUTO_RUN_POLLING_TIME, CM_4C_VSYNC_COUNTER_LEVEL_MSB, _BIT7, _TRUE) == _FALSE)
    {        
        return ucSyncTemp;
    }

    switch((ScalerGetBit(CM_4C_VSYNC_COUNTER_LEVEL_MSB, 0xff) & 0x70) >> 4)
    {
        case _NO_SIGNAL: // No Signal
        case _NOT_SUPPORT: // Not Support
        case _HSYNC_WITHOUT_VS: // Hsync only
            ucSyncTemp = _NO_SYNC_STATE;
            
            break;

#if (_YPBPR_SUPPORT == _ON)
        case _YPBPR_SYNC: // YPbPr-Type CS
            ucSyncTemp = _SOY_STATE;
            
            break;
#endif // End of #if (_YPBPR_SUPPORT == _ON)

        case _SERRATION_CS: // Serration-Type CS
            ucSyncTemp = _CS_STATE;
            
            break;
                     
        case _XOR_OR_TYPE_CS_WITH_EQR: // CS with Equalizer
        case _XOR_OR_TYPE_CS_WITHOUT_EQR: // OR-Type & XOR-Type CS

            // Pop Up Stable Value
            ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT1, _BIT1);

            PDATA_WORD(1) = ((((WORD)(ScalerGetByte(CM_4A_STABLE_HIGH_PERIOD_H) & 0x07) << 8) | ScalerGetByte(CM_4B_STABLE_HIGH_PERIOD_L)) + 1);

            PDATA_WORD(1) += _CAP_WINDOW_WIDTH_TOR;

            if(PDATA_WORD(1) <= 0x1F)
            {
                ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_08_CAPTURE_WINDOW_SETTING, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), PDATA_WORD(1));
            }
        
            ucSyncTemp = _CS_STATE;
            
            break;

        case _SEPARATE_HSYNC: // Separate Sync

            // Disable Coast Output in separate sync typer.
            ScalerSetBit(CM_48_SYNC_INVERT, ~_BIT6, 0x00);

            ucSyncTemp = _SS_STATE;
            
            break;

        default:
            ucSyncTemp = _NO_SYNC_STATE;
            
            break;
    }

    if(ucSyncTemp == _SOY_STATE)
    {
        SET_COLOR_SPACE(_COLOR_SPACE_YPBPR);
        SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);                
    }
    else
    {
        SET_COLOR_SPACE(_COLOR_SPACE_RGB);
        SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);
    }

    return ucSyncTemp;            
}

//--------------------------------------------------
// Description  : ADC Clock Initial before mode search
// Input Value  : None
// Output Value : True --> Success
//                False --> Error
//--------------------------------------------------
bit ScalerSyncVgaAdcClkInitial(void)
{
    WORD usIHFreq = 0;
    WORD usIHTotal = 0;

    usIHFreq = ((WORD)((_SYNC_PROC_CLK * 10 * 2 / (((WORD)(ScalerGetByte(CM_50_STABLE_PERIOD_H) & 0x07) << 8) | ScalerGetByte(CM_51_STABLE_PERIOD_L)) + 1) / 2));

    usIHTotal = (WORD)(((DWORD)_ADC_SAMPLE_CLOCK_LIMIT / usIHFreq / 4) * 4);

    if(usIHTotal > _PIXEL_WIDTH_LIMIT)
    {
        usIHTotal = _PIXEL_WIDTH_LIMIT;
    }

    g_usAdcClockLimit = usIHTotal; 

    g_stInputTimingData.usHTotal = usIHTotal; 
    
    ScalerADCBandWidthSetting(((DWORD)usIHFreq * (DWORD)usIHTotal) / 10000);

    if(ScalerAPLLAdjust(usIHTotal, usIHFreq) == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Clamp Position Check avoid BP too short.
// Input Value  : ucVideoModeFlg --> Video Mode flag type
// Output Value : None
//--------------------------------------------------
void ScalerSyncVgaSyncProcClampPosCheck(BYTE ucVideoModeFlg)
{
    WORD usClampPosStart = 0;
    WORD usClampPosEnd = 0;

    switch(ucVideoModeFlg)
    {
        case 0x10: // _VIDEO_MODE_GROUP1: 
            
            usClampPosStart = 0x08;
            usClampPosEnd = 0x16;

#if (_YPBPR_SUPPORT == _ON)
            SET_COLOR_SPACE(_COLOR_SPACE_YPBPR);
#endif
            break;

        case 0x20: //_VIDEO_MODE_GROUP2: 
            
            usClampPosStart = 0x30;
            usClampPosEnd = 0x38;

#if (_YPBPR_SUPPORT == _ON)
            SET_COLOR_SPACE(_COLOR_SPACE_YPBPR);
#endif
            break;

        case 0x80: // _VIDEO_MODE_GROUP3:
             
            usClampPosStart = 0x28;
            usClampPosEnd = 0x50;

#if (_YPBPR_SUPPORT == _ON)
            SET_COLOR_SPACE(_COLOR_SPACE_YPBPR);
#endif
            break;

        default:

            // Convert H start/HS width to current resolution           
            PDATA_WORD(0) = (DWORD)GET_ACTIVE_H_START() * GET_INPUT_TIMING_HTOTAL() / g_usAdcClockLimit;      
            PDATA_WORD(1) = (DWORD)GET_INPUT_TIMING_HTOTAL() * GET_INPUT_TIMING_HSYNCWIDTH() / GET_SYNC_H_PERIOD();

            // Check H start position
            if(PDATA_WORD(0) <= PDATA_WORD(1))
            {
                // Invalid measure; Set default clamp position
                usClampPosStart = 0x04;  
                usClampPosEnd = 0x0A;                                                            
            }
            else
            {
                // Calculate back porch size
                PDATA_WORD(2) = PDATA_WORD(0) - PDATA_WORD(1);
                
                // Check auto-function result for clamp position
                if(PDATA_WORD(2) > 0x12)
                {
                    // Clamp to back porch
                    usClampPosStart = 0x04;
                    usClampPosEnd = 0x10;                                                    
                }
                else
                {
                    // Clamp to back porch with shortened length 
                    usClampPosEnd = ((PDATA_WORD(2) >= 9) ? (PDATA_WORD(2) - 0x02) : 0x07);
                    usClampPosStart = ((usClampPosEnd >= 0x07) ? (usClampPosEnd - 0x06) : 0x01);
                }
            }

            break;
    }

    // Clamp position apply
    ScalerSyncProcClampPosSetting(usClampPosStart, usClampPosEnd);
}

//--------------------------------------------------
// Description  : ADC Clock Setting After mode search
// Input Value  : None
// Output Value : True --> Success
//                False --> Error
//--------------------------------------------------
bit ScalerSyncVgaAdcClkSetting(void)
{
    ScalerADCBandWidthSetting(((DWORD)GET_INPUT_TIMING_HFREQ() * (DWORD)GET_INPUT_TIMING_HTOTAL()) / 10000);

    if(ScalerAPLLAdjust(GET_INPUT_TIMING_HTOTAL(), GET_INPUT_TIMING_HFREQ()) == _FALSE)
    {
        return _FALSE;
    }

    // Coast Setting for progressive mode: +1/-1
    if(GET_INPUT_TIMING_INTERLACE_FLG() == _FALSE)
    {
        ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_07_SYNC_COAST_CTRL, 0x11);
    }

    return _TRUE;
}

#if(_SOG_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Polling for SOG detected flag
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
EnumSogLevelSearchResult ScalerSyncVgaSogCheckFlag(BYTE ucTimeOutCounter)
{
    // HS Detect Circuit Select At CS_RAW; only for 6230, no effect for others
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT4, 0x00);

    for(pData[0] = 5; pData[0] > 0; --pData[0])
    {
        // Clear SOG detected flag
        ScalerSetBit(CM_5B_HS_DETECT, ~_BIT6, _BIT6);

        // For SOG Power Stable, Refernce H-Freq = 15.63k
        for(pData[1] = 0; pData[1] <= ucTimeOutCounter; pData[1]++)
        {
            _nop_();
        }

        // Check SOG detect flag
        if(ScalerGetBit(CM_5B_HS_DETECT, _BIT6) != _BIT6)
        {
            return _SOG_LEVEL_FAIL;
        }
    }

    // SOG flag is valid
    return _SOG_LEVEL_VALID;
}

//--------------------------------------------------
// Description  : Check for SOG HS result
// Input Value  : stMeasureSyncHV --> structure for detected HS info
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
EnumSogLevelSearchResult ScalerSyncVgaSogCheckHs(StructMeasureSyncData *stMeasureSyncHV)
{
    WORD usHSyncPeriod = 0;
    WORD usHSyncPulseCount = 0;

    // Enable Sync Processor Clock
    ScalerSetBit(CM_47_SYNC_SELECT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT0), 0x00);

    // HS_OUT Signal Output Enable
    ScalerSetByte(CM_48_SYNC_INVERT, 0x10);

    // HS_OUT by pass mode, Measure Source is ADC_HS1/ADC_VS, H Sync measure source is original hs
    ScalerSetByte(CM_49_SYNC_CTRL, 0x06);

    // Sync from SOG Pad
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT4, _BIT4);

    // Start Stable Period Measure
    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT0, 0x00);
    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT0, _BIT0);

    if(ScalerTimerPollingFlagProc(12, CM_4F_STABLE_MEASURE, _BIT7, _TRUE) == _TRUE)
    {
        // Pop up stable result
        ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT1, _BIT1);

        usHSyncPeriod = ((WORD)(ScalerGetByte(CM_50_STABLE_PERIOD_H) & 0x07) << 8) | ScalerGetByte(CM_51_STABLE_PERIOD_L);
        usHSyncPulseCount = ((WORD)(ScalerGetByte(CM_4A_STABLE_HIGH_PERIOD_H) & 0x07) << 8) | ScalerGetByte(CM_4B_STABLE_HIGH_PERIOD_L);

        // Check HS width / HS period ratio
        if(((usHSyncPulseCount * 7) >= usHSyncPeriod) || 
           (usHSyncPulseCount < _MIN_SYNC_HIGHPULSE_CNT_PS))
        {
            return _SOG_LEVEL_INVALID;
        }

        // De-bounce check for stable measure
        if((stMeasureSyncHV->usHSPeriod != 0) || (stMeasureSyncHV->usHSWidth != 0))
        {
            if((abs(stMeasureSyncHV->usHSPeriod - usHSyncPeriod) > ((stMeasureSyncHV->usHSPeriod <= 1) ? 1 : (stMeasureSyncHV->usHSPeriod >> 1))) ||
               (abs(stMeasureSyncHV->usHSWidth - usHSyncPulseCount) > ((stMeasureSyncHV->usHSWidth <= 1) ? 1 : (stMeasureSyncHV->usHSWidth >> 1))))
            {
                return _SOG_LEVEL_INVALID;
            }
        }
        else
        {
            // Store measure HS info
            stMeasureSyncHV->usHSPeriod = usHSyncPeriod;
            stMeasureSyncHV->usHSWidth = usHSyncPulseCount;

            // Set VS down-counter
            ScalerSyncProcDownCounterSetting();
        }

        // SOG HS is valid
        return _SOG_LEVEL_VALID;
    }

    return _SOG_LEVEL_FAIL;
}

//--------------------------------------------------
// Description  : Check for SOG VS result
// Input Value  : stMeasureSyncHV --> structure for detected VS info
//                ucTimeoutCounter --> time out for 2 VS period
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
EnumSogLevelSearchResult ScalerSyncVgaSogCheckVs(StructMeasureSyncData *stMeasureSyncHV, BYTE ucTimeoutCounter)
{
    StructMeasureSyncData stMeasureSyncHVCurrent;
    BYTE ucLoopCounter = 0;

    // Check whether time-out counter is too small
    if(ucTimeoutCounter < 8)
    {
        ucTimeoutCounter = _WAIT_TWO_FRAME_TIME;
    }

    // Make total waiting time a multiple of 4
    ucTimeoutCounter = ((ucTimeoutCounter >> 2) + 1);

    // Enable De-composite circuit; Set to analog measure
    ScalerSetBit(CM_47_SYNC_SELECT, ~(_BIT5 | _BIT0), _BIT5);    

    // Select DE-VS/HS
    ScalerSetBit(CM_49_SYNC_CTRL, ~(_BIT6 | _BIT5),  (_BIT6 | _BIT5));

    // Stop measure block
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
    
    // Start on-line measure
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT7, _BIT7);

    // Waitting for de-composite circuit decode one frame.
    while(ucLoopCounter < ucTimeoutCounter)
    {
        ++ucLoopCounter;
        ScalerTimerDelayXms(4);

        if((ScalerGetBit(CM_52_MEAS_HS_PER_H, _BIT4) != 0x00) ||            // HS overflow
           (ScalerGetBit(CM_54_MEAS_VS_PER_H, (_BIT5 | _BIT4)) != 0x00))    // VS overflow or timeout
        {
            return _SOG_LEVEL_FAIL;
        }

        if(ucLoopCounter == (ucTimeoutCounter / 2))
        {
            // Enable over-range detect; V range = 8 lines
            ScalerSetBit(CM_58_MEAS_HS_VS_HI_SEL, ~(_BIT5 | _BIT4 | _BIT2), (_BIT5 | _BIT4 | _BIT2));
        }

        // Check result
        if(ucLoopCounter == ucTimeoutCounter)
        {
            // Pop up measurement result
            ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT6, _BIT6);

            // Set to read VS Width
            ScalerSetBit(CM_58_MEAS_HS_VS_HI_SEL, ~_BIT0, _BIT0);

            // Pop out VS period, VS width
            stMeasureSyncHVCurrent.usVSPeriod = ((((WORD)ScalerGetByte(CM_54_MEAS_VS_PER_H) & 0x0F) << 8) | (ScalerGetByte(CM_55_MEAS_VS_PER_L))) + 1;
            stMeasureSyncHVCurrent.usVSWidth = ((((WORD)ScalerGetByte(CM_56_MEAS_HS_VS_HI_H) & 0xF0) << 4) | (ScalerGetByte(CM_57_MEAS_HS_VS_HI_L))) + 1;

            // Check VS over range result
            if(ScalerGetBit(CM_58_MEAS_HS_VS_HI_SEL, _BIT2) == _BIT2)
            {
                // VS over-range; Reset detect flag
                ScalerSetBit(CM_58_MEAS_HS_VS_HI_SEL, ~(_BIT5 | _BIT4 | _BIT2), _BIT2);
                break;
            }

            // Check VS polarity, VS width & V total
            if((stMeasureSyncHVCurrent.usVSWidth >= _MAX_VSYNC_HIGH_PERIOD) ||
               (stMeasureSyncHVCurrent.usVSPeriod > _MAX_VSYNC_TOTAL) || 
               (stMeasureSyncHVCurrent.usVSPeriod < _MIN_VSYNC_TOTAL))
            {
                // VS format error
                break;
            }

            // De-bounce cehck for VS result
            if(stMeasureSyncHV->usVSPeriod != 0)
            {
                if((abs(stMeasureSyncHV->usVSPeriod - stMeasureSyncHVCurrent.usVSPeriod) > 2) ||
                   (abs(stMeasureSyncHV->usVSWidth - stMeasureSyncHVCurrent.usVSWidth) > 1))
                {
                    break;
                }
            }
            else
            {
                // Store measured VS info
                stMeasureSyncHV->usVSPeriod = stMeasureSyncHVCurrent.usVSPeriod;
                stMeasureSyncHV->usVSWidth = stMeasureSyncHVCurrent.usVSWidth;
            }

            // Disable over-range detect
            ScalerSetBit(CM_58_MEAS_HS_VS_HI_SEL, ~(_BIT5 | _BIT4 | _BIT2), _BIT2);

            // Stop on-line measure
            ScalerSetBit(CM_52_MEAS_HS_PER_H, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

            // SOG VS is valid
            return _SOG_LEVEL_VALID;
        }
    }

    // Stop on-line measure
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    return _SOG_LEVEL_INVALID;
}

//-------------------------------------------------------------------
// Description  : Check SOG Sync Status
// Input Value  : None
// Output Value : _TRUE: SOG Sync Checked OK  _FALSE: SOG Sync Checked Fail
//-------------------------------------------------------------------
bit ScalerSyncVgaSogSyncCheck(void)
{
    BYTE ucFlagTimeOutCounter = 0x00;
    BYTE ucVsTimeOutCounter = _WAIT_TWO_FRAME_TIME;
    BYTE ucLevelCounter = 0x00;
    BYTE ucLevelTarget = 0x00;
    bit bResetSearch = _FALSE;
    StructMeasureSyncData stMeasureSyncHV;
    BYTE ucSOYCompareLelArr[3]; // NOT INITIALIZED here to avoid being treated as a code table    

    // Set pre-set SOG compare levels
    ucSOYCompareLelArr[0] = 0x10;
    ucSOYCompareLelArr[1] = 0x16;
    ucSOYCompareLelArr[2] = 0x1C;

    memset(&stMeasureSyncHV, 0x00, sizeof(StructMeasureSyncData));

    if((MCU_CTRL_FFED & _BIT1) == _BIT1) // CPU clock come from M2PLL, based on 24.3M
    {
        ucFlagTimeOutCounter = 60;
    }
    else // CPU clock come from internal or external crystal clock, base on 3.5M
    {
        if((ScalerGetBit(CM_0B_POWER_CTRL2, _BIT0) == _BIT0) && 
           (((MCU_CTRL_FFED & 0x3C) >> 2) == _FLASH_CLK_PS_FAST_DIV)) // 27MHz and flash clock div = 1 --> for DP Case
        {
            ucFlagTimeOutCounter = 30;
        }
        else
        {
            ucFlagTimeOutCounter = 8;
        }
    }

    // Search pre-set SOG compare levels
    while(ucLevelCounter < sizeof(ucSOYCompareLelArr))
    {
        // Set current SOG compare level
        ScalerSetBit(P0_D7_ADC_SOG_DAC_SOY_CONTROL, ~(0x3F), ucSOYCompareLelArr[ucLevelCounter]);
        ++ucLevelCounter;

        // Check SOG flag and HS result
        if(((pData[0] = ScalerSyncVgaSogCheckFlag(ucFlagTimeOutCounter)) != _SOG_LEVEL_VALID) ||
           ((pData[0] = ScalerSyncVgaSogCheckHs(&stMeasureSyncHV)) != _SOG_LEVEL_VALID) ||
           ((pData[0] = ScalerSyncVgaSogCheckVs(&stMeasureSyncHV, ucVsTimeOutCounter)) != _SOG_LEVEL_VALID))
        {
            // Stop searching up if target level already being found, or invald result detected
            if((ucLevelTarget != 0x00) || (pData[0] == _SOG_LEVEL_INVALID))
            {
                break;
            }

            continue;
        }

        if(ucLevelTarget != 0x00)
        {
            // Second level found. Set average SOG compare level.
            ucLevelTarget = (ucLevelTarget + ScalerGetBit(P0_D7_ADC_SOG_DAC_SOY_CONTROL, 0x3F)) / 2;
            break;
        }
        else if((bResetSearch == _FALSE) && (ucLevelCounter != 1))
        {
            // Reset search process to avoid the case when sync become available during searching
            bResetSearch = _TRUE;
            ucLevelCounter = 0;
            ucLevelTarget = 0;
            memset(&stMeasureSyncHV, 0x00, sizeof(StructMeasureSyncData));

            continue;
        }

        // Store current compare level
        ucLevelTarget = ScalerGetBit(P0_D7_ADC_SOG_DAC_SOY_CONTROL, 0x3F);

        // Update VS time-out counter   
        ucVsTimeOutCounter = (WORD)(((DWORD)stMeasureSyncHV.usHSPeriod * stMeasureSyncHV.usVSPeriod * 2) / _SYNC_PROC_CLK) + 1;
    }

    if(ucLevelTarget != 0x00)
    {
        // Resume target compare level
        ScalerSetBit(P0_D7_ADC_SOG_DAC_SOY_CONTROL, ~(0x3F), ucLevelTarget);
        
        if(stMeasureSyncHV.usVSWidth <= 1)
        {
            // Enable Clamp Mask and select clamp mask signal as DeVS
            ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_05_SYNC_CLAMP_CTRL1, 0xC2);

            // Align the rising edge of Clamp Mask to DeVS rising edge
            ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_04_SYNC_CLAMP_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        }
    }
    
    return (ucLevelTarget != 0x00);
}
#endif // #if(_SOG_SUPPORT == _ON)
#endif // #if(_VGA_SUPPORT == _ON)


#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Initial Setting for TMDS Scanning Port(Power Normal)
// Input Value  : Input Port(D0 or D1, HDMI or DVI)
// Output Value : None
//--------------------------------------------------
void ScalerSyncTmdsScanInitial(BYTE ucInputPort)
{
    ScalerTmdsInitial(ucInputPort);
    
    ScalerTmdsInterruptInitial();
}

//--------------------------------------------------
// Description  : Signal PreDetection for TMDS(Power Normal)
// Input Value  : Input Port(D0 or D1, HDMI or DVI)
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerSyncTmdsNormalPreDetect(BYTE ucInputPort)
{    
    if((ucInputPort == _D0_INPUT_PORT && GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE) || 
        (ucInputPort == _D1_INPUT_PORT && GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE) ||
        (ucInputPort == _D2_INPUT_PORT && GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE) ||
        (ucInputPort == _D3_INPUT_PORT && GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE))
    {
        // DDC handshake Detected
        if((ucInputPort == _D0_INPUT_PORT) && (g_bTmdsD0DdcDetected == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : Normal D0 DDC", 0);
            
            g_bTmdsD0DdcDetected = _FALSE;
            
            return _TRUE;
        }
        
        if((ucInputPort == _D1_INPUT_PORT) && (g_bTmdsD1DdcDetected == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : Normal D1 DDC", 0);

            g_bTmdsD1DdcDetected = _FALSE;
       
            return _TRUE;
        }
        
        if((ucInputPort == _D2_INPUT_PORT) && (g_bTmdsD2DdcDetected == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : Normal D2 DDC", 0);
            
            g_bTmdsD2DdcDetected = _FALSE;
                    
            return _TRUE;
        }

        if((ucInputPort == _D3_INPUT_PORT) && (g_bTmdsD3DdcDetected == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : Normal D3 DDC", 0);        
            
            g_bTmdsD3DdcDetected = _FALSE;
                    
            return _TRUE;
        }
        
        if(ucInputPort == _D2_INPUT_PORT)
        {
#if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
            ucInputPort = _D0_INPUT_PORT;
#elif(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
            ucInputPort = _D1_INPUT_PORT;
#endif
        }

        if(ucInputPort == _D3_INPUT_PORT)
        {
#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
            ucInputPort = _D0_INPUT_PORT;
#elif(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
            ucInputPort = _D1_INPUT_PORT;
#endif
        }
        
        // DDC handshake Detected
        if(ucInputPort == _D0_INPUT_PORT)
        {       
            // Enable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
            if(((MCU_DVI_EDID_IRQ_FFE4 & _BIT3) != _BIT3) && (g_bTmdsD0DdcDetected != _TRUE))
            {
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;            

                g_bTmdsD0DdcDetected = _FALSE;
            }
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
            if(((MCU_HDMI_EDID_IRQ_FFE5 & _BIT3) != _BIT3) && (g_bTmdsD0DdcDetected != _TRUE))
            {
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;

                g_bTmdsD0DdcDetected = _FALSE;
            }
#endif                         
        }
        
        if(ucInputPort == _D1_INPUT_PORT)
        {
#if((_D1_DDC_CHANNEL_SEL == _DDC2) || (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2))
            if(((MCU_DVI_EDID_IRQ_FFE4 & _BIT3) != _BIT3) && (g_bTmdsD1DdcDetected != _TRUE))
            {
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
                
                g_bTmdsD1DdcDetected = _FALSE;
            }
#elif((_D1_DDC_CHANNEL_SEL == _DDC3) || (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3))
            if(((MCU_HDMI_EDID_IRQ_FFE5 & _BIT3) != _BIT3) && (g_bTmdsD1DdcDetected != _TRUE))
            {
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;

                g_bTmdsD1DdcDetected = _FALSE;
            }
#endif        
        }

        ScalerTimerDelayXms(6);

        if(GET_TMDS_PHY_SET() == _TRUE)
        {
            DebugMessageScaler("7. wuzanne test : Normal TMDS Clock Stable", 0);
            
            return _TRUE;
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : TMDS Port Source/Sync Scanning and Setting
// Input Value  : Input Port(D0 or D1, HDMI or DVI)
// Output Value : Source DVI --> DVI Format
//                Source HDMI --> HDMI Format
//                Source None --> No Stable Sync
//--------------------------------------------------
BYTE ScalerSyncTmdsScanInputPort(BYTE ucInputType)
{
    BYTE ucTmdsType = _SOURCE_NONE; 

    BYTE ucTmdsVideoDataType = _TMDS_VIDEO_DATA_NONE;

    ucInputType = ucInputType;

    if(GET_TMDS_PHY_SET() == _TRUE)
    {
        // Delay for PHY Stable
        ScalerTimerDelayXms(2);
        
        if(ScalerTmdsCheckCDRStable(g_usTmdsClkCount) == _FALSE)
        {

#if(_MHL_SUPPORT == _ON)
            if(((ScalerGetBit(PB_B5_DP_2D_SWITCH, _BIT2) == 0x00) && (GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)) ||
               ((ScalerGetBit(PB_B5_DP_2D_SWITCH, _BIT2) == _BIT2) && (GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)))
            {
                // Set Upper Bound
                ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_MHL_FREQ_NORMAL_UPPER_BOUND));
                ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_MHL_FREQ_NORMAL_UPPER_BOUND));    
            }
            else
#endif
            {
                // Set Upper Bound
                ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_NORMAL_UPPER_BOUND));
                ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_NORMAL_UPPER_BOUND));    
            }

            // Set Lower Bound
            ScalerSetByte(P2_EA_HDMI_FREQDET_LOWER_M, HIBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));
            ScalerSetByte(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));

            // Set Stable Time (0x7F = about 5ms)
            ScalerSetByte(P2_EC_HDMI_FREQDET_STABLE, 0x7F);

            // Disable Freq. Unstable IRQ
            ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT1, 0x00);

            // Enable Freq. Stable IRQ
            ScalerSetBit(P2_EF_HDMI_FREQDET_RESERVED, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            CLR_TMDS_PHY_SET();
            
            return _SOURCE_NONE;
        }
        
        DebugMessageDigital("9. Freq Check Pass => Pixel Clock", GET_INPUT_PIXEL_CLK());

        // Clear RGBHV Flag
        ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

        // Clear Info Packet SRAM
        ScalerSetBit(P2_AD_CPS, ~_BIT3, _BIT3);
        ScalerSetBit(P2_AD_CPS, ~_BIT3, 0x00);

        // Clear AVI infoframe & GCP packet Detection Flag
        ScalerSetBit(P2_CC_HDMI_GPVS, ~_BIT6, _BIT6);
        ScalerSetBit(P2_CC_HDMI_GPVS, ~_BIT5, _BIT5);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
        // Clear DRR flag
        CLR_FREESYNC_ENABLED();

        // Clear SPD infoframe
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, ~(_BIT7 | _BIT6), _BIT6);
#endif

#if(_3D_SUPPORT == _ON)
        // Clear Detection Flag
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, ~(_BIT7 | _BIT6), _BIT7);
#endif
        
        if(ScalerTmdsFormatDetect() == _SOURCE_HDMI)
        {        
            DebugMessageDigital("Format Detect HDMI", 0x00);

#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_BY_INPUT)
            ScalerSetDataPortBit(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, ~_BIT1, _BIT1);
#endif

#if(_HDMI_FROM_DVI_CONNECT == _OFF)            
            if((ucInputType == _D0_DVI_PORT) || (ucInputType == _D1_DVI_PORT) || (ucInputType == _D2_DVI_PORT) || (ucInputType == _D3_DVI_PORT))
            {
                return _SOURCE_NONE;
            }
#endif            
            ucTmdsType = _SOURCE_HDMI;
        }
        else
        {            
#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_BY_INPUT)
            ScalerSetDataPortBit(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, ~_BIT1, 0x00);
#endif            

            ucTmdsType = _SOURCE_DVI;
        }

        ucTmdsVideoDataType = ScalerSyncTmdsVideoDetect(_WAIT);

        if(ucTmdsVideoDataType == _TMDS_VIDEO_DATA_DE_ONLY)
        {
            DebugMessageDigital("DE Only Mode", 0x00);
            
#if(_DVI_DE_ONLY_SUPPORT == _ON)
            if(ucTmdsType == _SOURCE_DVI)
            {
                // Enable DE Only Mode
                ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~_BIT7, _BIT7);
            }
            else
            {
                return _SOURCE_NONE;
            }
#else
            return _SOURCE_NONE;
#endif
        }
        else if(ucTmdsVideoDataType == _TMDS_VIDEO_DATA_RGBHV) 
        {
            // Enable DE Only Mode
            ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~_BIT7, _BIT7);
        }
        else
        {
            return _SOURCE_NONE;
        }

#if(_HDMI_SUPPORT == _ON)
        if(ucTmdsType == _SOURCE_HDMI)
        {                
            // HDMI packet detect --> AVI infoframe & GCP packet 
            ScalerTmdsHdmiPacketDetect(_WAIT);

            ScalerTmdsHdmiVideoSetting();

            SET_COLOR_DEPTH(ScalerTmdsHdmiGetColorDepth());
                
            if(GET_COLOR_DEPTH() != _COLOR_DEPTH_8_BITS)
            {
                DebugMessageDigital("Deep Color Mode Detected", GET_COLOR_DEPTH());

                switch(GET_COLOR_DEPTH())
                {
                    case _COLOR_DEPTH_10_BITS:
                        pData[0] = 10;
                        break;
                        
                    case _COLOR_DEPTH_12_BITS:
                        pData[0] = 12;
                        break;
                        
                    case _COLOR_DEPTH_16_BITS:
                        pData[0] = 16;
                        break;

                    default:
                        break;
                }
                
                SET_INPUT_PIXEL_CLK((GET_INPUT_PIXEL_CLK() << 3) / pData[0]);
                
                if(ScalerTmdsHdmiDeepColorProc() == _FALSE)
                {
                    return _SOURCE_NONE;
                }            
                
                // Turn On Deep Color Block
                ScalerSetBit(P2_B5_UP_DOWN_CTRL0, ~_BIT7, _BIT7);                
            }
            else
            {
                // Turn off Deep Color Block            
                ScalerSetBit(P2_B5_UP_DOWN_CTRL0, ~_BIT7, 0x00);
            }

#if(_HDMI_FREESYNC_SUPPORT == _ON)
            if(ScalerSyncTMDSHdmiGetAmdSpdInfo(_SPD_INFO_FREESYNC_SUPPORT) == _ENABLE)
            {
                SET_HDMI_FREESYNC_ENABLED();

                // Get SPD Free Sync Vfreq Max
                g_usFREESYNCVFreq = (WORD)ScalerSyncTMDSHdmiGetAmdSpdInfo(_SPD_INFO_FREESYNC_MAX_VFREQ) * 10;

                // Disable DE Only Mode
                ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~_BIT7, 0x00);


            }
#endif
        }
        else
        {

#if(_MHL_SUPPORT == _ON)
            // Guard Band reference disable for data remapping
            ScalerSetBit(P26_B2_MHL_CTRL_12, ~_BIT7, 0x00);
#endif

            CLR_HDMI_AVI_INFO_FRAME_RECEIVED();

            CLR_HDMI_GCP_RECEIVED();

            // Disable All WD when DVI
            ScalerTmdsHdmiWatchDog((_HDMI_AVI_INFO_VARIATION_WD | _HDMI_AV_MUTE_WD), _DISABLE);

            ScalerTmdsDviVideoSetting();
            
            SET_COLOR_DEPTH(_COLOR_DEPTH_8_BITS);
            
            // Turn off Deep Color Block            
            ScalerSetBit(P2_B5_UP_DOWN_CTRL0, ~_BIT7, 0x00);            
        }
#else
        
        ScalerTmdsDviVideoSetting();
        
        SET_COLOR_DEPTH(_COLOR_DEPTH_8_BITS);
        
        // Turn off Deep Color Block            
        ScalerSetBit(P2_B5_UP_DOWN_CTRL0, ~_BIT7, 0x00);
#endif

        // Enable Video Output
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~_BIT3, _BIT3);
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_80_HDMI_DPC_SET0, ~_BIT7, _BIT7);

        // Enable RGB Clk Output
        ScalerSetBit(P2_A6_TMDS_OUTPUT_CTRL, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5 | _BIT4 | _BIT3));

        return ucTmdsType;
    }
        
    return _SOURCE_NONE;
}

//--------------------------------------------------
// Description  : Detect TMDS video mode
// Input Value  : bWait => Whether to wait then read
// Output Value : TMDS video type
//--------------------------------------------------
BYTE ScalerSyncTmdsVideoDetect(bit bWait)
{
    BYTE ucTemp = _TMDS_VIDEO_DATA_NONE;

    if(bWait == _WAIT)
    {
        // Wait at least 1 frame for HW auto update TMDS video RGBHV valid value
        ScalerTimerPollingFlagProc(45, P2_A4_TMDS_CTRL, _BIT3, _TRUE);

        if(ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5)) == (_BIT7 | _BIT6 | _BIT5))
        {
            // H/Vsync received
            if(ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
            {
                ucTemp = _TMDS_VIDEO_DATA_RGBHV;
            }
            else
            {
                ucTemp = _TMDS_VIDEO_DATA_DE_ONLY;
            }
        }
        else
        {
            ucTemp = _TMDS_VIDEO_DATA_NONE;
        }
        
        CLR_TMDS_RGBHV_DETECTING();

        return ucTemp;
    }
    else
    {
        // R/G/B data detected
        if(ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5)) == (_BIT7 | _BIT6 | _BIT5))
        {
            // H/Vsync received
            if(ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
            {
                ucTemp = _TMDS_VIDEO_DATA_RGBHV;
            }
            else
            {
                ucTemp = _TMDS_VIDEO_DATA_DE_ONLY;
            }
        }
        else
        {
            ucTemp = _TMDS_VIDEO_DATA_NONE;
        }

        // Clear video Detection Flag
        ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

        SET_TMDS_RGBHV_DETECTING();

        // Activate TMDS video Detection Event
        ScalerTimerActiveTimerEvent(SEC(0.045), _SCALER_TIMER_EVENT_TMDS_VIDEO_DETECT);

        return ucTemp;
    }
}

//--------------------------------------------------
// Description  : TMDS video Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTmdsVideoDetectEvent(void)
{
    CLR_TMDS_RGBHV_DETECTING();
}

//--------------------------------------------------
// Description  : Signal Detection for TMDS(Power Saving)
// Input Value  : Input Port(D0 or D1, HDMI or DVI)
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerSyncTmdsPSPreDetect(BYTE ucInputPort)
{
    BYTE ucTemp = 0;

    if((ucInputPort == _D0_INPUT_PORT && GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE) || 
        (ucInputPort == _D1_INPUT_PORT && GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE) ||
        (ucInputPort == _D2_INPUT_PORT && GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE) ||
        (ucInputPort == _D3_INPUT_PORT && GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE))
    {
        // DDC handshake Detected
        if((ucInputPort == _D0_INPUT_PORT) && (g_bTmdsD0DdcDetected == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : PowerSaving D0 DDC", 0);
            
            g_bTmdsD0DdcDetected = _FALSE;

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)            
            SET_TMDS_D0_TOGGLE_Z0();
#endif
            return _TRUE;
        }
        
        if((ucInputPort == _D1_INPUT_PORT) && (g_bTmdsD1DdcDetected == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : PowerSaving D1 DDC", 0);
            
            g_bTmdsD1DdcDetected = _FALSE;

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)            
            SET_TMDS_D1_TOGGLE_Z0();
#endif                    
            return _TRUE;
        }

        if((ucInputPort == _D2_INPUT_PORT) && (g_bTmdsD2DdcDetected == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : PowerSaving D2 DDC", 0);
            
            g_bTmdsD2DdcDetected = _FALSE;
                    
            return _TRUE;
        }

        if((ucInputPort == _D3_INPUT_PORT) && (g_bTmdsD3DdcDetected == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : PowerSaving D3 DDC", 0);
            
            g_bTmdsD3DdcDetected = _FALSE;
                    
            return _TRUE;
        }
        
        if(ucInputPort == _D2_INPUT_PORT)
        {
#if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
            ucInputPort = _D0_INPUT_PORT;
#elif(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
            ucInputPort = _D1_INPUT_PORT;
#endif
        }

        if(ucInputPort == _D3_INPUT_PORT)
        {
#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
            ucInputPort = _D0_INPUT_PORT;
#elif(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
            ucInputPort = _D1_INPUT_PORT;
#endif
        }
        
        // DDC handshake Detected
        if(ucInputPort == _D0_INPUT_PORT)
        {       
            // Enable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
            if(((MCU_DVI_EDID_IRQ_FFE4 & _BIT3) != _BIT3) && (g_bTmdsD0DdcDetected != _TRUE))
            {
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;            
            }
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
            if(((MCU_HDMI_EDID_IRQ_FFE5 & _BIT3) != _BIT3) && (g_bTmdsD0DdcDetected != _TRUE))
            {
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;
            }
#endif                         
        }
        
        if(ucInputPort == _D1_INPUT_PORT)
        {
#if((_D1_DDC_CHANNEL_SEL == _DDC2) || (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2))
            if(((MCU_DVI_EDID_IRQ_FFE4 & _BIT3) != _BIT3) && (g_bTmdsD1DdcDetected != _TRUE))
            {
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
                
                g_bTmdsD1DdcDetected = _FALSE;
            }
#elif((_D1_DDC_CHANNEL_SEL == _DDC3) || (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3))
            if(((MCU_HDMI_EDID_IRQ_FFE5 & _BIT3) != _BIT3) && (g_bTmdsD1DdcDetected != _TRUE))
            {
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;

                g_bTmdsD1DdcDetected = _FALSE;
            }
#endif        
        }    

        // Enable Freq. Detect & Choose Measure Clk to TMDS Clk
        ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), _BIT7);       
        
        // Clear Freq. Stable Flag
        ScalerSetBit(P2_EF_HDMI_FREQDET_RESERVED, ~_BIT6, _BIT6);

        // Clear Unstable Flag
        ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);        

        // Delay enough time for freq. measure (calculated for measure 10 times)
        for(ucTemp = 0; ucTemp < 100; ucTemp++)
        {
            _nop_();
        }

        // Detect Freq. Measure Stable
        if((ScalerGetBit(P2_E6_HDMI_FREQDET_CTRL, (_BIT6 | _BIT2)) == _BIT6) && (ScalerGetBit(P2_EF_HDMI_FREQDET_RESERVED, _BIT6) == _BIT6))
        {        
            // Switch to Bandgap
            ScalerGDIBandgap(_ON);

            ScalerTimerDelayXms(2); // wuzanne1493

            // Clear Flag
            ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);
            ScalerSetBit(P2_EF_HDMI_FREQDET_RESERVED, ~_BIT6, _BIT6);

            // Delay enough time for freq. measure (calculated for measure 10 times)
            for(ucTemp = 0; ucTemp < 100; ucTemp++)
            {
                _nop_();
            }

            if((ScalerGetBit(P2_E6_HDMI_FREQDET_CTRL, (_BIT6 | _BIT2)) == _BIT6) && (ScalerGetBit(P2_EF_HDMI_FREQDET_RESERVED, _BIT6) == _BIT6))
            {
                DebugMessageScaler("7. wuzanne test : Power Saving TMDS Clock Stable", 0);

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)

                if(ucInputPort == _D0_INPUT_PORT)
                {
                    SET_TMDS_D0_TOGGLE_Z0();                
                }
                else if(ucInputPort == _D1_INPUT_PORT)
                {
                    SET_TMDS_D1_TOGGLE_Z0();                                   
                }   
#endif
                return _TRUE;
            }
            else
            {
                // Switch back to power saving Bandgap
                ScalerGDIBandgap(_OFF);
                
                // Disable Freq. Detection
                ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);

                return _FALSE;
            }
        }
        else
        {
            // Disable Freq. Detection
            ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);
            
            return _FALSE;
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : On Line Check TMDS stability
// Input Value  : ucSourceType --> Source Type
// Output Value : True --> TMDS Stable
//                False --> TMDS Unstable
//--------------------------------------------------
bit ScalerSyncTmdsStableDetect(BYTE ucSourceType)
{
    // CLR SCL/SDA Toggle Flag
    g_bTmdsD0DdcDetected = _FALSE;
    g_bTmdsD1DdcDetected = _FALSE;    

    if(ScalerTmdsCheckCDRStable(g_usTmdsClkCount) == _FALSE)    
    {
        DebugMessageDigital("CDR Unstable!!", ucSourceType);
        return _FALSE;
    }

    // Check TMDS Clock Output Disable
    if(ScalerGetBit(P2_A6_TMDS_OUTPUT_CTRL, _BIT3) == 0x00)
    {
        DebugMessageDigital("TMDS Clock Output has been disable", ucSourceType);
        return _FALSE;
    }
 
#if(_MHL_SUPPORT == _ON)
    if(GET_TMDS_CLK_MODE() == _TMDS_24BIT_PHY_SETTING)
#endif

    {
        if(ucSourceType == _SOURCE_HDMI)
        {
            if(ScalerGetBit(P2_CB_HDMI_SR, _BIT0) == 0x00)
            {
                DebugMessageDigital("Tmds Format Changed", ucSourceType);
                return _FALSE;
            }
        }
        else
        {
            if(ScalerGetBit(P2_CB_HDMI_SR, _BIT0) == _BIT0)
            {
                DebugMessageDigital("Tmds Format Changed", ucSourceType);
                return _FALSE;
            }
        }
    }

    if(GET_TMDS_Z0_ASSERTED() == _TRUE)
    {
        if((ScalerGetBit(P2_A9_TMDS_ACC1, _BIT6) == _BIT6) && (ScalerGetBit(P2_A9_TMDS_ACC1, (_BIT7 | _BIT5)) != (_BIT7 | _BIT5)))
        {
            SET_TMDS_HPD_TRIGGER_EVENT();
            
            CLR_TMDS_Z0_ASSERTED();

            DebugMessageDigital("7. wuzanne test : HDCP Abnormal !!!!!", 0);
            
            return _FALSE;            
        }
        else if((ScalerGetBit(P2_A9_TMDS_ACC1, (_BIT7 | _BIT5)) == (_BIT7 | _BIT5)))
        {
            CLR_TMDS_Z0_ASSERTED();

            DebugMessageDigital("7. wuzanne test : HDCP Normal", 0);
        }                        
    }

    if(ucSourceType == _SOURCE_DVI)
    {
        if(GET_TMDS_RGBHV_DETECTING() == _FALSE)
        {
            // TMDS Video Detected
            if(ScalerSyncTmdsVideoDetect(_NOT_WAIT) != _TMDS_VIDEO_DATA_RGBHV)
            {
                DebugMessageDigital("TMDS Video format changed", ucSourceType);

#if(_DVI_DE_ONLY_SUPPORT == _OFF)
                return _FALSE;
#endif
            }
        }
    }    

#if(_HDMI_SUPPORT == _ON)

    if(ucSourceType == _SOURCE_HDMI)
    {
        if(GET_HDMI_PACKET_DETECTING() == _FALSE)
        {
            // HDMI Packet Detected
            ScalerTmdsHdmiPacketDetect(_NOT_WAIT);

            if(GET_HDMI_AVI_INFO_FRAME_RECEIVED() == _TRUE)
            {
                if(ScalerTmdsHdmiColorInfoChanged() == _TRUE)
                {                                    
                    DebugMessageDigital("Color Info Changed", ucSourceType);  
                    return _FALSE;
                }                           
            }
            else
            {
                
#if(_MHL_SUPPORT == _ON)
                if(GET_TMDS_CLK_MODE() == _TMDS_24BIT_PHY_SETTING)
#endif
                {
                    if(GET_COLOR_SPACE() != _COLOR_SPACE_RGB)
                    {
                        DebugMessageDigital("HDMI Info Frame Not Received and not RGB", ucSourceType);
                        return _FALSE;
                    }
                }

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)    
                if(GET_COLOR_RGB_QUANTIZATION_RANGE() != _RGB_QUANTIZATION_RESERVED)
                {
                    DebugMessageDigital("No Quantization Range Specified", ucSourceType);
                    return _FALSE;
                }
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
                if(GET_COLOR_YCC_QUANTIZATION_RANGE() != _YCC_QUANTIZATION_LIMIT_RANGE)
                {                    
                    DebugMessageDigital("No YCC Quantization Range Specified", ucSourceType);
                    return _FALSE;
                }
#endif
            }

            if((ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_41_HDMI_VWDSR, _BIT0) == _BIT0) && (ScalerGetBit(P2_CC_HDMI_GPVS, _BIT0) == _BIT0))
            {
                DebugMessageDigital("HDMI AVI info frame has changed", ucSourceType);
                return _FALSE;
            }
            
            if(GET_HDMI_GCP_RECEIVED() == _TRUE)
            {   
                if(ScalerTmdsHdmiGetColorDepth()!= GET_COLOR_DEPTH())
                {
                    DebugMessageDigital("Color Depth Has Changed", GET_COLOR_DEPTH());                 
                    return _FALSE;
                }
            }
            else
            {
                if(GET_COLOR_DEPTH() != _COLOR_DEPTH_8_BITS)
                {
                    DebugMessageDigital("HDMI GCP PACKET Not Received and not 8 bit", ucSourceType);
                    return _FALSE;
                }
            }
        }

#if(_HDMI_FREESYNC_SUPPORT == _ON)
        if(GET_TMDS_RX0_SPD_INFO_FRAME_RECEIVED() == _TRUE)
        {
            if((bit)ScalerSyncTMDSHdmiGetAmdSpdInfo(_SPD_INFO_FREESYNC_SUPPORT) != GET_HDMI_FREESYNC_ENABLED())
            {
                DebugMessageOsd("HDMI Freesync Status Change", GET_HDMI_FREESYNC_ENABLED());
                return _FALSE;
            }
        }
        else
        {
            if(GET_HDMI_FREESYNC_ENABLED() == _TRUE)
            {
                DebugMessageOsd("HDMI Freesync Status Change", GET_HDMI_FREESYNC_ENABLED());
                return _FALSE;
            }
        }
#endif
    }

#if(_3D_SUPPORT == _ON) 

        // 3D Info Frame Detected
        if(GET_HDMI_3D_INFO_RECEIVED() == _TRUE)
        {
            if(ScalerTmdsHdmiGet3DFormat() != GET_3D_TX_INPUT_FORMAT())
            {
                DebugMessageDigital("HDMI 3D Tx Format Changed", 0x00);                
                return _FALSE;
            }            
        } 
        else
        {
            if(GET_3D_TX_INPUT_FORMAT() != _NO_3D_FORMAT)
            {
                return _FALSE;
            }
        }    
#endif

#endif

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)

    if((GET_TMDS_D0_TOGGLE_Z0() == _TRUE) || (GET_TMDS_D1_TOGGLE_Z0() == _TRUE))
    {
        SET_TMDS_TOGGLE_Z0_EVENT();

        return _FALSE;
    }
    
#endif

    return _TRUE;
}    

#if(_MHL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Signal PreDetection for MHL(Power Saving)
// Input Value  : Input Port(D0 or D1, HDMI or DVI)
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerSyncMHLPSPreDetect(BYTE ucInputPort)
{
    BYTE ucTemp = 0;

    // Check RAP Content OFF
    if(ucInputPort == _D0_INPUT_PORT)
    {
        
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        if(ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
        {
            return _FAIL;
        }
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        if(ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
        {
            return _FAIL;
        }
#endif

    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {

#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        if(ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
        {
            return _FAIL;
        }
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        if(ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
        {
            return _FAIL;
        }
#endif

    }

    if(GET_MHL_2D_SWITCH() == _TRUE)
    {
        CLR_MHL_2D_SWITCH();
        return _TRUE;
    }

    // Enable Freq. Detect & Choose Measure Clk to TMDS Clk
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), _BIT7);       
    
    // Clear Freq. Stable Flag
    ScalerSetBit(P2_EF_HDMI_FREQDET_RESERVED, ~_BIT6, _BIT6);

    // Clear Unstable Flag
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);         

    // Delay enough time for freq. measure (calculated for measure 10 times)
    for(ucTemp = 0; ucTemp < 100; ucTemp++)
    {
        _nop_();
    }

    // Detect Freq. Measure Stable
    if((ScalerGetBit(P2_E6_HDMI_FREQDET_CTRL, (_BIT6 | _BIT2)) == _BIT6) && (ScalerGetBit(P2_EF_HDMI_FREQDET_RESERVED, _BIT6) == _BIT6))
    {        
        // Switch to Bandgap
        ScalerGDIBandgap(_ON);

        ScalerTimerDelayXms(2); // wuzanne1493

        // Clear Flag
        ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);
        ScalerSetBit(P2_EF_HDMI_FREQDET_RESERVED, ~_BIT6, _BIT6);

        // Delay enough time for freq. measure (calculated for measure 10 times)
        for(ucTemp = 0; ucTemp < 100; ucTemp++)
        {
            _nop_();
        }

        if((ScalerGetBit(P2_E6_HDMI_FREQDET_CTRL, (_BIT6 | _BIT2)) == _BIT6) && (ScalerGetBit(P2_EF_HDMI_FREQDET_RESERVED, _BIT6) == _BIT6))
        {
            if((ScalerGetBit(PB_B5_DP_2D_SWITCH, _BIT2) == 0x00) &&
                ((GET_D0_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE)))
            {
                ScalerMHLCBUSResetProc(_D0_INPUT_PORT);
            }
            else if((ScalerGetBit(PB_B5_DP_2D_SWITCH, _BIT2) == _BIT2) &&
                ((GET_D1_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE)))
            {
                ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
            }
            
            DebugMessageScaler("7. wuzanne test : Power Saving TMDS Clock Stable", 0);
            
            return _TRUE;
        }
        else
        {
            // Switch back to power saving Bandgap
            ScalerGDIBandgap(_OFF);
            
            // Disable Freq. Detection
            ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);
        }
    }
    else
    {
        // Disable Freq. Detection
        ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);
    }

    switch(GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()))
    {
        case _MHL_STATE_INITIAL:
        case _MHL_STATE_PATH_EN_DONE:
        case _MHL_STATE_DONE:

            return _FAIL;
            break;

        default:
            
            return _SUCCESS;
            break;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Signal PreDetection for MHL(Power Normal)
// Input Value  : Input Port(D0 or D1, HDMI or DVI)
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerSyncMHLNormalPreDetect(BYTE ucInputPort)
{
    // Check RAP Content OFF
    if(ucInputPort == _D0_INPUT_PORT)
    {
        
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        if(ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
        {
            return _FAIL;
        }
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        if(ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
        {
            return _FAIL;
        }
#endif

    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {

#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        if(ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
        {
            return _FAIL;
        }
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        if(ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
        {
            return _FAIL;
        }
#endif

    }

    if(GET_MHL_2D_SWITCH() == _TRUE)
    {
        CLR_MHL_2D_SWITCH();
        return _TRUE;
    }

    ScalerTimerDelayXms(6);

    if(GET_TMDS_PHY_SET() == _TRUE)
    {
        DebugMessageScaler("7. wuzanne test : Normal TMDS Clock Stable", 0);
        SET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE(), _MHL_STATE_DONE);
        return _SUCCESS;
    }

    switch(GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()))
    {
        case _MHL_STATE_INITIAL:
        case _MHL_STATE_PATH_EN_DONE:

            return _FAIL;
            break;

        default:
            
            return _SUCCESS;
            break;
    }

    return _FAIL;
}
#endif // End of #if(_MHL_SUPPORT == _ON)

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get AMD SPD Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerSyncTMDSHdmiGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent)
{
    if(GET_TMDS_RX0_SPD_INFO_FRAME_RECEIVED() == _TRUE)
    {
        // Get AMD OUI
        ScalerGetDataPortByte(P2_CD_HDMI_PSAP, 0xAF, 3, pData, _AUTOINC);
        if((pData[0] == 0x1A) && (pData[1] == 0x00) && (pData[2] == 0x00))
        {
            switch(enumContent)
            {
                case _SPD_INFO_FREESYNC_SUPPORT:

                    return ((bit)ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0xB4, _BIT0));

                case _SPD_INFO_FREESYNC_ENABLE:

                    return ((bit)ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0xB4, _BIT1));

                case _SPD_INFO_FREESYNC_ACTIVE:

                    return ((bit)ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0xB4, _BIT2));

                case _SPD_INFO_FREESYNC_MIN_VFREQ:

                    ScalerGetDataPortByte(P2_CD_HDMI_PSAP, 0xB5, 1, pData, _AUTOINC);

                    if(((WORD)pData[0] * 10) < _PANEL_FREESYNC_MIN_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MIN_FRAME_RATE / 10;
                        DebugMessageOsd("Freesync SPD info abnormal", 0);
                    }
                    else if(((WORD)pData[0] * 10) > _PANEL_FREESYNC_MAX_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MAX_FRAME_RATE / 10;
                        DebugMessageOsd("Freesync SPD info abnormal", 1);
                    }

                    return pData[0];

                case _SPD_INFO_FREESYNC_MAX_VFREQ:

                    ScalerGetDataPortByte(P2_CD_HDMI_PSAP, 0xB6, 1, pData, _AUTOINC);

                    if(((WORD)pData[0] * 10) < _PANEL_FREESYNC_MIN_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MIN_FRAME_RATE / 10;
                        DebugMessageOsd("Freesync SPD info abnormal", 0);
                    }
                    else if(((WORD)pData[0] * 10) > _PANEL_FREESYNC_MAX_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MAX_FRAME_RATE / 10;
                        DebugMessageOsd("Freesync SPD info abnormal", 1);
                    }

                    return pData[0];

                default:

                    return 0x00;
            }
        }
    }

    return 0x00;
}
#endif // End of #if(_HDMI_FREESYNC_SUPPORT == _ON)
#endif

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initial Setting for DP Scanning Port(Power Normal)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncDpScanInitial(void)
{ 
    ScalerDpMacInitial();

    ScalerDpPhyInitial();   

    CLR_DP_FAKE_LINK_TRAINING();    
}

//--------------------------------------------------
// Description  : Signal PreDetection for DP(Power Normal)
// Input Value  : None
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerSyncDpNormalPreDetect(void)
{    
    // For Dp PHY CTS Test
    if(GET_DP_PHY_CTS_FLG() == _TRUE)
    {
        ScalerDpPhyCTS();
        
        return _FALSE;
    }
    
    if((ScalerDpGetDpcdInfo(0x00, 0x06, 0x00) & (_BIT1 | _BIT0)) == _BIT1)
    {
        CLR_DP_VALID_VIDEO_CHECK();

        return _FALSE;
    }

#if(_DP_ASSR_MODE_SUPPORT == _ON)
    // ASSR Mode Setting
    ScalerDpASSRModeSetting();
#endif    

    switch(GET_DP_LINK_TRAINING_STATUS())
    {
        case _DP_NORMAL_LINK_TRAINING_PASS:
        case _DP_LINK_STATUS_FAIL:

            CLR_DP_VALID_VIDEO_CHECK();

            if((ScalerDpCDRCheck() == _TRUE) && (ScalerDpAlignCheck() == _TRUE) && (ScalerDpDecodeCheck() == _TRUE))
            {               
                ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);

                if(GET_DP_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL)
                {
                    SET_DP_LINK_TRAINING_STATUS(_DP_NORMAL_LINK_TRAINING_PASS);
                }
   
                ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);

                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ);
                
                return _TRUE;
            }
            else
            {
                DebugMessageDigital("7. wuzanne test : Link Status Fail IRQ", 0);
                
                ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);

                if(GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS)
                {                    
                    SET_DP_LINK_TRAINING_STATUS(_DP_LINK_STATUS_FAIL);

                    ScalerTimerActiveTimerEvent(SEC(0.05), _SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ);
                }
   
                ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
            }

            break;

        case _DP_LINK_TRAINING_FAIL:

            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ);
            
            ScalerDpLinkStatusIRQ();

            break;

        case _DP_FAKE_LINK_TRAINING_PASS:

            CLR_DP_VALID_VIDEO_CHECK();

            DebugMessageDigital("6. wuzanne test : DP Rebuild PHY", GET_DP_LINK_TRAINING_STATUS());

            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ);

            ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);

            if(GET_DP_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS)
            {
                ScalerDpRebuildPhy(ScalerDpGetDpcdInfo(0x00, 0x01, 0x00), ScalerDpGetDpcdInfo(0x00, 0x01, 0x01));
            }

            ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);

            if((ScalerDpCDRCheck() == _TRUE) && (ScalerDpAlignCheck() == _TRUE) && (ScalerDpDecodeCheck() == _TRUE))
            {   
                DebugMessageDigital("7. wuzanne test : DP Rebuild PHY Pass", 0);
                
                ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);

                if(GET_DP_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS)
                {
                    SET_DP_LINK_TRAINING_STATUS(_DP_NORMAL_LINK_TRAINING_PASS);
                }

                ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
                
                ScalerTimerDelayXms(20);
 
                if(ScalerDpHdcpCheck() == _FALSE)
                {
                    DebugMessageDigital("6. wuzanne test : DP HDCP Check Fail after Rebuild PHY", 0);

                    ScalerDpCpIRQ();
                    
                    ScalerTimerReactiveTimerEvent(SEC(1), _SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT);                      
                }

                // De-Skew Circuit Reset
                ScalerSetBit(PC_BB_DP_RESERVE1, ~_BIT5, 0x00);
                ScalerSetBit(PC_BB_DP_RESERVE1, ~_BIT5, _BIT5);

                // Mac Reset After Link Clock Stable
                ScalerSetBit(PC_A1_DP_CTL, ~_BIT6, _BIT6);
                ScalerSetBit(PC_A1_DP_CTL, ~_BIT6, 0x00);

                // Secondary Data Reset (DP Audio Block)
                ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_92_AUD_BUF_STATUS, ~_BIT2, _BIT2);
                ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_92_AUD_BUF_STATUS, ~_BIT2, 0x00);
                
                return _TRUE;
            }
            else
            {
                DebugMessageDigital("6. wuzanne test : DP Rebuild PHY Fail", 0);

                ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);

                if(GET_DP_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS)
                {
                    SET_DP_LINK_TRAINING_STATUS(_DP_LINK_STATUS_FAIL);
                }

                ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
                                 
                ScalerDpLinkStatusIRQ();
            }

            break;

        case _DP_LINK_TRAINING_NONE:

            if(GET_DP_VALID_VIDEO_CHECK() == _TRUE)
            {                
                ScalerDpValidSignalDetection();

                DebugMessageDigital("7. wuzanne test : VBIOS Check !!!!!!!", GET_DP_FAKE_LINK_TRAINING());                
            }
            
        default:

            break;               
    }

    CLR_DP_VALID_VIDEO_CHECK();

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP Port Source/Sync Scanning and Setting
// Input Value  : None
// Output Value : Source DP --> DP Sync Stable
//                Source None --> No Stable Sync
//--------------------------------------------------
BYTE ScalerSyncDpScanInputPort(void)
{
    if(GET_DP_LINK_TRAINING_STATUS() != _DP_NORMAL_LINK_TRAINING_PASS)
    {
        return _SOURCE_NONE;
    }
    
    if(ScalerDpHdcpCheck() == _FALSE)
    {
        DebugMessageDigital("6. wuzanne test : DP HDCP Check Fail", 0);

        ScalerDpCpIRQ();
        
        ScalerTimerReactiveTimerEvent(SEC(1), _SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT);  
        
        return _SOURCE_NONE;
    }
    
    if(ScalerDpGetVideoStream() == _FALSE)
    {
        DebugMessageDigital("6. wuzanne test : DP Video Stream Fail", 0);
    
        return _SOURCE_NONE;            
    }

    if((ScalerDpGetDpcdInfo(0x06, 0x80, 0x07) != 0x00) || 
       (ScalerDpGetDpcdInfo(0x06, 0x80, 0x08) != 0x00) ||
       (ScalerDpGetDpcdInfo(0x06, 0x80, 0x09) != 0x00) ||
       (ScalerDpGetDpcdInfo(0x06, 0x80, 0x0A) != 0x00) ||
       (ScalerDpGetDpcdInfo(0x06, 0x80, 0x0B) != 0x00))
    {
        DebugMessageDigital("7. wuzanne test : Cancel DP Long HPD", 0);
        
        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT);
    }
    
    if(ScalerDpMSACheck() == _FALSE)
    {
        DebugMessageDigital("6. wuzanne test : DP MSA Fail", 0);

        return _SOURCE_NONE;
    }

    ScalerDpDisplayFormatSetting();

    ScalerDpVideoSetting();

    if(ScalerDpStreamClkRegenerate() == _FALSE)
    {
        DebugMessageDigital("6. wuzanne test : DP SteamClk Fail", 0);
        
        return _SOURCE_NONE;         
    }

    if(ScalerDpFifoCheck(_DP_FIFO_DELAY_CHECK) == _FALSE)
    {
        ScalerDpAdjustVsyncDelay();

        if(ScalerDpFifoCheck(_DP_FIFO_DELAY_CHECK) == _FALSE)
        {
            DebugMessageDigital("6. wuzanne test : DP Fifo Fail", 0);

            // Set DP Receive Port0 In Sync
            ScalerDpSinkStatusSet(_DP_SINK_REVEICE_PORT0, _DP_SINK_OUT_OF_SYNC);
        
            return _SOURCE_NONE;
        }
    }

    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT);

    ScalerSetBit(PC_A2_DP_OUTPUT_CTL, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

    // Set DP Receive Port0 In Sync
    ScalerDpSinkStatusSet(_DP_SINK_REVEICE_PORT0, _DP_SINK_IN_SYNC);
    
    return _SOURCE_DP;
}

//--------------------------------------------------
// Description  : Signal Detection for DP(Power Saving)
// Input Value  : None
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerSyncDpPSPreDetect(void)
{    
    // Back to noraml for DP PHY CTS    
    if(GET_DP_PHY_CTS_FLG() == _TRUE)
    {    
        return _TRUE;
    }
    
    if(GET_DP_VALID_VIDEO_CHECK() == _TRUE)
    {
        DebugMessageDigital("7. wuzanne test : Valid Video Check", 0);

        return _TRUE;
    }
      
    if(GET_DP_PS_AUX_TOGGLE() == _TRUE)
    {
        DebugMessageDigital("7. wuzanne test : Power Saving Aux Handshake", 0);
        
        return _TRUE;
    }
    
    if(GET_DP_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS)
    {

#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))

        if(GET_DIGITAL_AUDIO_SOURCE() == _DIGITAL_AUDIO_SOURCE_DP)
        {
            DebugMessageAudio("00. DP Power Saving Audio : Idle Pattern Case", GET_DIGITAL_AUDIO_SOURCE());   
            return _TRUE;
        }
#endif
        DebugMessageDigital("7. wuzanne test : Idle Pattern Case", 0);
        
        return _TRUE;
    }
    
    return _FALSE;
}

//--------------------------------------------------
// Description  : On Line Check DP stability
// Input Value  : None
// Output Value : True --> DP Stable
//                False --> DP Unstable
//--------------------------------------------------
bit ScalerSyncDpStableDetect(void)
{
    if((ScalerDpGetDpcdInfo(0x00, 0x06, 0x00) & (_BIT1 | _BIT0)) == _BIT1)
    {
        DebugMessageDigital("7. wuzanne test : DP Power Down", 0);
        
        return _FALSE;
    }
    
    if((ScalerDpCDRCheck() == _FALSE) || (ScalerDpAlignCheck() == _FALSE) || (ScalerDpDecodeCheck() == _FALSE))
    {   
        DebugMessageDigital("7. wuzanne test : DP Link Fail", 0);
        
        return _FALSE;               
    }
    
    if(ScalerDpMiscCheck() == _FALSE)
    {
        DebugMessageDigital("7. wuzanne test : DP Misc Change", 0);
        
        return _FALSE;
    }

    if(ScalerDpFifoCheck(_DP_FIFO_POLLING_CHECK) == _FALSE)
    {
        DebugMessageDigital("7. wuzanne test : Fifo Under/Overflow", 0);
        
        return _FALSE;
    }

    ScalerDpCrcCalculate(); 
            
    return _TRUE;
}    

//--------------------------------------------------
// Description  : DP DC OFF to Normal HPD Process
// Input Value  : UserData -> _DP_HOT_PLUG_DC_OFF_HIGH status
// Output Value : None
//--------------------------------------------------
void ScalerSyncDpHPDPowerOfftoNormalProc(BYTE ucDpHotPlugDCOffHighStatus)
{
    if(((bit)ucDpHotPlugDCOffHighStatus) == _TRUE)
    {
#if(_DP_DCOFF_HPD_FORCE_HIGH == _ON)

        DebugMessageDigital("7. wuzanne test : DP HPD Force High", 0);

        return;
#endif
        
#if(_DP_DELL_D3_TEST_SUPPORT == _OFF)        
        if(ScalerDpGetDpcdInfo(0x00, 0x06, 0x00) != 0x02)
#endif            
        {
#if(_DP_DUAL_MODE_SUPPORT == _ON)                
            if((GET_DP_LINK_TRAINING_STATUS() != _DP_FAKE_LINK_TRAINING_PASS) && (GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_DP))
#else
            if(GET_DP_LINK_TRAINING_STATUS() != _DP_FAKE_LINK_TRAINING_PASS)
#endif
            {
                DebugMessageDigital("7. wuzanne test : Long HPD Event", ucDpHotPlugDCOffHighStatus);
                
                ScalerDpHotPlugEvent(_DP_LONG_HPD_EVENT);
            }        
        }                
    }
    else
    {
        DebugMessageDigital("7. wuzanne test : HPD Asserted", ucDpHotPlugDCOffHighStatus);
        
        ScalerDpHotPlugEvent(_DP_HPD_ASSERTED);
    }        
}
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable DownLoad HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncHdcpEnableDownLoadKey(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Suspend Key Calculation before load key
        ScalerSetBit(P2_AE_TMDS_RPS, ~(_BIT1 | _BIT0), _BIT0);

        // Manual Select Key SRAM Access Right
        ScalerSetBit(P2_A9_TMDS_ACC1, ~_BIT4, 0x00);
        
        // Switch MAC to Hdmi
        ScalerSetBit(PC_A1_DP_CTL, ~_BIT5, _BIT5);
        
        // Enable HDCP Block, and Key download port
        ScalerSetBit(P2_C0_HDCP_CTRL, ~(_BIT7 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0)); 

        // Set Km Clock to EMCU Clock
        ScalerSetBit(P2_AC_Z0CC2, ~_BIT4, 0x00);
    }
    else if(bEnable == _DISABLE)
    {
        // Set Km Clock to Xtal Clock
        ScalerSetBit(P2_AC_Z0CC2, ~_BIT4, _BIT4);
        
        // Disable Key download port
        ScalerSetBit(P2_C0_HDCP_CTRL, ~_BIT1, 0x00);

        // New Cipher Mode
        ScalerSetBit(P2_C0_HDCP_CTRL, ~_BIT7, _BIT7);
        
        // Auto Select Key SRAM Access Right
        ScalerSetBit(P2_A9_TMDS_ACC1, ~_BIT4, _BIT4);

        // Release Key Calculation
        ScalerSetBit(P2_AE_TMDS_RPS, ~_BIT1, _BIT1);
    }
}

//--------------------------------------------------
// Description  : DownLoad HDCP BKsv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncHdcpDownLoadBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray)
{
    for(pData[0] = ucSubAddr; pData[0] < ucLength; pData[0]++)
    {
#if(_HDMI_SUPPORT == _ON || _DVI_SUPPORT == _ON)        
        ScalerSetDataPortByte(P2_C3_HDCP_ADDR_PORT, pData[0], pReadArray[pData[0]]);
#endif

#if(_DP_SUPPORT == _ON)
        ScalerDpSetDpcdValue(0x06, 0x80, (0x00 | pData[0]), pReadArray[pData[0]]);

        // HDCP Support
        ScalerDpSetDpcdValue(0x06, 0x80, 0x28, 0x01);

        // Enable DP Link Integrity Enable
        ScalerSetByte(PC_E4_HDCP_INTGT_VRF, 0xB4);
#endif
        g_ucHdcpBksvBackup[pData[0]] = pReadArray[pData[0]];
    }
    
    DebugMessageDigital("8. HDCP Bksv Backup", g_ucHdcpBksvBackup[0]);
    DebugMessageDigital("8. HDCP Bksv Backup", g_ucHdcpBksvBackup[1]);
    DebugMessageDigital("8. HDCP Bksv Backup", g_ucHdcpBksvBackup[2]);
    DebugMessageDigital("8. HDCP Bksv Backup", g_ucHdcpBksvBackup[3]);
    DebugMessageDigital("8. HDCP Bksv Backup", g_ucHdcpBksvBackup[4]);    
}

//--------------------------------------------------
// Description  : DownLoad HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncHdcpDownLoadKey(WORD usLength, BYTE *pReadArray)
{
    ScalerWrite(P2_C1_DEVICE_KEY_ACCESS_PORT, usLength, pReadArray, _NON_AUTOINC);
}

//--------------------------------------------------
// Description  : Check whether HDCP is enabled
// Input Value  : Input Port
// Output Value : TRUE => HDCP Enabled
//--------------------------------------------------
bit ScalerSyncHdcpCheckEnabled(BYTE ucInputPort)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        return ScalerDpHdcpEnebled();
#elif((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
        return ScalerTmdsHdcpEnabled();
#endif
    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        return ScalerDpHdcpEnebled();
#elif((_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
        return ScalerTmdsHdcpEnabled();
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT)
        if(GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS)
        {
            return ScalerTmdsHdcpEnabled();
        }
        else
        {
            return ScalerDpHdcpEnebled();
        }
#endif
    }

    return _FALSE;
}
#endif

//--------------------------------------------------
// Description  : Initial Interlace Detection Method
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerSyncInterlaceInitial(BYTE ucSourceType)
{
    // Disable IVS Delay one line; Default field source from VGIP
    ScalerSetBit(CM_13_VGIP_ODD_CTRL, ~(_BIT7 | _BIT6 | _BIT0), _BIT0);

    // Clear VGIP Interlace Toggle Flag
    ScalerSetBit(CM_1A_IPV_ACT_LEN_H, ~_BIT5, _BIT5);
    
    switch(ucSourceType)
    {
        
#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:        

            // Clear Interlace toggle flag
            ScalerSetBit(CM_4A_STABLE_HIGH_PERIOD_H, ~(_BIT6 | _BIT4), (_BIT6 | _BIT4));
            
            break;
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

#if(_DVI_SUPPORT == _ON)
        case _SOURCE_DVI:
#endif

#if(_HDMI_SUPPORT == _ON)
        case _SOURCE_HDMI:
#endif            
            
            // Clear Interlace toggle and error flag
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_50_HDMI_VCR, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));

            break;
#endif

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:

            break;
#endif
         
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Check Interlace
// Input Value  : Source Type
// Output Value : TRUE => Interlaced Detected
//--------------------------------------------------
bit ScalerSyncInterlaceCheck(BYTE ucSourceType)
{    
    switch(ucSourceType)
    {
        
#if(_VGA_SUPPORT == _ON)        
        case _SOURCE_VGA:

            if((ScalerGetBit(CM_1A_IPV_ACT_LEN_H, _BIT5) == _BIT5) ||
               (ScalerGetBit(CM_4A_STABLE_HIGH_PERIOD_H, (_BIT6 | _BIT4)) != 0x00))
            {
                // Clear VGIP Interlace Toggle Flag
                ScalerSetBit(CM_1A_IPV_ACT_LEN_H, ~_BIT5, _BIT5);

                // Clear Interlace toggle flag
                ScalerSetBit(CM_4A_STABLE_HIGH_PERIOD_H, ~(_BIT6 | _BIT4), (_BIT6 | _BIT4));
                
                return _TRUE;
            }
            
            break;
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

#if(_DVI_SUPPORT == _ON)
        case _SOURCE_DVI:
#endif

#if(_HDMI_SUPPORT == _ON)
        case _SOURCE_HDMI:
#endif
           
#if(_DVI_DE_ONLY_SUPPORT == _ON)

            if(ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT4 | _BIT3)) != (_BIT4 | _BIT3))
            {                
                // Detect by Vtotal
                if(ScalerGetBit(CM_1A_IPV_ACT_LEN_H, _BIT5) == _BIT5)
                {   
                    if(GET_INPUT_TIMING_DOUBLE_CHECK() == _FALSE)
                    {
                        // Interlace field signal from VGIP
                        ScalerSetBit(CM_13_VGIP_ODD_CTRL, ~_BIT0, _BIT0);
                        
                        // Set Video Compensation to ODD Field
                        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT6, 0x00);
                    }

                    // Clear VGIP Interlace Toggle Flag
                    ScalerSetBit(CM_1A_IPV_ACT_LEN_H, ~_BIT5, _BIT5);

                    return _TRUE;
                }
            }
            else
#endif        
            {                          
                // Detect by VS Position                
                if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_50_HDMI_VCR, _BIT6) == _BIT6)
                {                    
                    if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_50_HDMI_VCR, _BIT5) == 0x00)                    
                    {
                        if(GET_INPUT_TIMING_DOUBLE_CHECK() == _FALSE)
                        {
                            // Interlace field signal from interface
                            ScalerSetBit(CM_13_VGIP_ODD_CTRL, ~_BIT0, 0x00);

                            // Set Video Compensation to EVEN Field
                            ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT6, _BIT6);                    
                        }

                        // Clear Interlace toggle flag
                        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_50_HDMI_VCR, ~_BIT6, _BIT6);

                        return _TRUE;                        
                    }
                    else
                    {                    
                        // Clear Interlace toggle and error flag
                        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_50_HDMI_VCR, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));
                    }
                }

#if(_3D_SUPPORT == _ON) 
                if((GET_3D_TX_INPUT_FORMAT() == _FRAME_PACKING) && 
                    ((g_stInputTimingData.usVHeight == 2228) || (g_stInputTimingData.usVHeight == 1028) || (g_stInputTimingData.usVHeight == 1226)))
                {
                    // 1080i / 480i / 576i
                    return _TRUE;
                }
#endif
            }        

            break;
#endif

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:

            if(ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, (_BIT7 | _BIT6)) == _BIT7)
            {
                if(GET_INPUT_TIMING_DOUBLE_CHECK() == _FALSE)
                {                
                    // Interlace field signal from interface
                    ScalerSetBit(CM_13_VGIP_ODD_CTRL, ~_BIT0, 0x00);

                    // Set Video Compensation to EVEN Field
                    ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT6, _BIT6); 
                }                

                return _TRUE;
            }
            else if(ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6))
            {
                if(ScalerGetBit(CM_1A_IPV_ACT_LEN_H, _BIT5) == _BIT5)
                {
                    if(GET_INPUT_TIMING_DOUBLE_CHECK() == _FALSE)
                    {                    
                        // Select Filed Signal from VGIP
                        ScalerSetBit(CM_13_VGIP_ODD_CTRL, ~_BIT0, _BIT0);;

                        // Set Video Compensation to ODD Field
                        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT6, 0x00);
                    }

                    // Clear VGIP Interlace Toggle Flag
                    ScalerSetBit(CM_1A_IPV_ACT_LEN_H, ~_BIT5, _BIT5);
                    
                    return _TRUE;
                }
            }
            
            break;
#endif

        default:
            break;
    }    

    return _FALSE;
}

//--------------------------------------------------
// Description  : Process Required to be Performed for Active State
// Input Value  : Current Source Type
// Output Value : None
//--------------------------------------------------
void ScalerSyncActiveProc(BYTE ucSourceType)
{
    switch(ucSourceType)
    {

#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

#if(_ADCNR_BY_HISTOGRAM_SUPPORT == _ON)
            ScalerNrGrayDetect();
#endif
        break;            
#endif

#if(_DVI_SUPPORT == _ON)
        case _SOURCE_DVI:                
            break;
#endif

#if(_HDMI_SUPPORT)
        case _SOURCE_HDMI:
            
            ScalerTmdsHdmiAVMuteProc();

            break;
#endif

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:          
            
            break;          
#endif 
        default:
            break;
    }        
}

//--------------------------------------------------
// Description  : Sync reset Process for Mode Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncResetProc(void)
{
#if(_DP_SUPPORT == _ON)

    // Disable DP Fifo Under/OverFlow Watch Dog
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_CA_DP_VWD_CTRL, ~(_BIT5 | _BIT4), 0x00);                        

#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_TMDS_VIDEO_DETECT);

#if(_HDMI_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_TMDS_HDMI_PACKET_DETECT);
    ScalerTmdsHdmiWatchDog((_HDMI_AVI_INFO_VARIATION_WD | _HDMI_AV_MUTE_WD), _DISABLE);
#endif // End of #if(_HDMI_SUPPORT == _ON)

#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
}

//--------------------------------------------------
// Description  : Power Process for Interface
// Input Value  : Power Action
// Output Value : None
//--------------------------------------------------
void ScalerSyncPowerProc(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:  

            // ADC Bandgap Enable
            ScalerADCBandgap(_ON);

#if(_DIGITAL_PORT_SUPPORT == _ON)
            // GDI Bandgap Enable
            ScalerGDIBandgap(_ON);
#endif
#if(_MHL_SUPPORT == _ON)
            if(enumPowerAction == _POWER_ACTION_OFF_TO_NORMAL)
            {
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
                SET_MHL_PORT_ACTIVE(0);

                if((GET_D0_TMDS_MODE() == _TMDS_MHL_MODE) && \
                    (ScalerGetBit(PB_B6_Z0_0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == (_BIT7 | _BIT6 | _BIT5 | _BIT4)) && \
                    (GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()) >= _MHL_STATE_DEV_CAP_RDY) && \
                    (((GET_D0_MHL_ADOPTER_ID_HBYTE() == _ASUS_PADFONE2_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _ASUS_PADFONE2_ADOPTER_ID_LBYTE)) ||
                    ((GET_D0_MHL_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE))))
                {
                    // Reset CBUS
                    ScalerMHLCBUSResetProc(_D0_INPUT_PORT);
                }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
                SET_MHL_PORT_ACTIVE(1);
#else
                SET_MHL_PORT_ACTIVE(0);
#endif

                if((GET_D1_TMDS_MODE() == _TMDS_MHL_MODE) && \
                    (ScalerGetBit(PB_B7_Z0_1, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == (_BIT7 | _BIT6 | _BIT5 | _BIT4)) && \
                    (GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()) >= _MHL_STATE_DEV_CAP_RDY) && \
                    (((GET_D1_MHL_ADOPTER_ID_HBYTE() == _ASUS_PADFONE2_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _ASUS_PADFONE2_ADOPTER_ID_LBYTE)) ||
                    ((GET_D1_MHL_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE))))
                {
                    // Reset CBUS
                    ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
                }
#endif
            }
#endif  // End of #if(_MHL_SUPPORT == _ON)

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
            
            // Power down ADC/APLL
            ScalerSyncAdcApllPowerDown();

            // ADC Bandgap Disable
            ScalerADCBandgap(_OFF);

#if(_DIGITAL_PORT_SUPPORT == _ON)

#if((_DVI_SUPPORT == _ON) || _HDMI_SUPPORT == _ON)
            // TMDS Power Saving Process
            ScalerTmdsPowerSavingProc();
#endif

#if(_DP_SUPPORT == _ON)
            ScalerDpLowPowerCheck(_POWER_STATUS_SAVING);

#else // Else of #if(_DP_SUPPORT == _ON)

            // GDI Bandgap Disable
            ScalerGDIBandgap(_OFF);

            ScalerGDIPhyPowerSavingProc();
#endif // End of  #if(_DP_SUPPORT == _ON)

#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

            // Schmitt trigger setting old mode in power saving.
            ScalerSetByte(P0_F4_HS_SCHMITT_TRIGGER_CTRL, 0xC2);

            // Disable Sync proc clock
            ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT7, _BIT7);    
            
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:            
            
            // Power down ADC/APLL
            ScalerSyncAdcApllPowerDown();

#if(_VGA_SUPPORT == _ON)
            // Disable sync pulse detect
            ScalerSyncProcPulseDetectEnable(_DISABLE);
#endif

            // ADC Bandgap Disable
            ScalerADCBandgap(_OFF);

#if(_DIGITAL_PORT_SUPPORT == _ON)

#if((_DVI_SUPPORT == _ON) || _HDMI_SUPPORT == _ON)    
            ScalerTmdsPowerOffProc();
#endif

#if(_DP_SUPPORT == _ON)
            ScalerDpLowPowerCheck(_POWER_STATUS_OFF);

#else // Else of #if(_DP_SUPPORT == _ON)

            // GDI Bandgap Disable
            ScalerGDIBandgap(_OFF);
            
            ScalerGDIPhyPowerOffProc();

#if(_MHL_SUPPORT != _ON)
            EX0 = 0;
#endif
            
#endif // End of  #if(_DP_SUPPORT == _ON)

            ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);
            
            ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _OFF);

#if(_MHL_SUPPORT == _ON)
            ScalerMHLPowerOffProc();
#endif

#endif

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _TRUE)
            CLR_TMDS_D0_TOGGLE_Z0();
            CLR_TMDS_D1_TOGGLE_Z0();
            CLR_TMDS_TOGGLE_Z0_EVENT();
#endif
            // Schmitt trigger setting old mode in power saving.
            ScalerSetByte(P0_F4_HS_SCHMITT_TRIGGER_CTRL, 0x42);

            // Disable Sync proc clock
            ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT7, _BIT7);    

            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Switch GDI Clk
// Input Value  : CLK Source
// Output Value : None
//--------------------------------------------------
void ScalerSyncSwitchGDIClk(BYTE ucClk)
{
    ScalerSetBit(P2_E1_AUX_PS_REPLY, ~_BIT5, ((ucClk == _M2PLL_CLK) ? _BIT5 : 0x00));
}

//--------------------------------------------------
// Description  : Let Upper Layer Get Input Pixel Clk
// Input Value  : None
// Output Value : Input Pixel Clk (in 0.1MHz)
//--------------------------------------------------
WORD ScalerSyncGetInputPixelClk(void)
{
    return GET_INPUT_PIXEL_CLK();
}

//--------------------------------------------------
// Description  : Switch Between Interfaces
// Input Value  : Current Input Port, Target Source Type, Source Search Mode
// Output Value : None
//--------------------------------------------------
void ScalerSyncInterfaceSwitch(BYTE ucInputPortType, BYTE ucSourceSearchDelayMode)
{    
    ucSourceSearchDelayMode = ucSourceSearchDelayMode;
    
#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON) || (_MHL_SUPPORT == _ON))
    if((ucInputPortType != _D0_DVI_PORT) && (ucInputPortType != _D1_DVI_PORT) && (ucInputPortType != _D2_DVI_PORT) && (ucInputPortType != _D3_DVI_PORT) &&
       (ucInputPortType != _D0_HDMI_PORT) && (ucInputPortType != _D1_HDMI_PORT) && (ucInputPortType != _D2_HDMI_PORT) && (ucInputPortType != _D3_HDMI_PORT) &&
       (ucInputPortType != _D0_MHL_PORT) && (ucInputPortType != _D1_MHL_PORT))
    {
        ScalerTmdsFreqDetectDisable();
    }
#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

#if(_DP_SUPPORT == _ON)
    if((ucInputPortType != _D0_DP_PORT) && (ucInputPortType != _D1_DP_PORT) && (ucInputPortType != _D1_DP_DUAL_PORT))
    {        
        SET_DP_FAKE_LINK_TRAINING();

        ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);

        if(GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS)
        {
            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);
        }
        
        ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
    }
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_DIGITAL_PORT_SUPPORT == _ON)
    if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
    {    
        SET_D0_PORT_DIGITAL_SWITCH();
        SET_D1_PORT_DIGITAL_SWITCH();  

#if((_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0) || (_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH);
#endif

#if((_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1) || (_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1))
        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH);
#endif
    }    
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_AUDIO_SUPPORT == _ON)
    if(ucInputPortType == _A0_VGA_PORT)
    {
        // Disable Audio Detection
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, ~_BIT7, 0x00);
    }
    else
    {
        // Enable Audio Detection
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, ~_BIT7, _BIT7);
    }
#endif

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)

    if(GET_TMDS_TOGGLE_Z0_EVENT() == _TRUE)
    {
        if(GET_TMDS_D0_TOGGLE_Z0() == _TRUE)
        {
            ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);
            CLR_DIGITAL_PORT_SWITCH_TO_D0();            
        }
        else if(GET_TMDS_D1_TOGGLE_Z0() == _TRUE)
        {
            ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _OFF);
            CLR_DIGITAL_PORT_SWITCH_TO_D1();
        }

        ScalerTimerDelayXms(130);

        CLR_TMDS_D0_TOGGLE_Z0();
        CLR_TMDS_D1_TOGGLE_Z0();
        CLR_TMDS_TOGGLE_Z0_EVENT();        
    }
    
#endif

    switch(ucInputPortType)
    {

        case _A0_VGA_PORT:

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)

            CLR_TMDS_D0_TOGGLE_Z0();
            CLR_TMDS_D1_TOGGLE_Z0();
            CLR_TMDS_TOGGLE_Z0_EVENT();  
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {
                PCB_DIGITAL_SWITCH_TO_D1_IDLE();
                PCB_DIGITAL_SWITCH_TO_D0_IDLE();
                
                CLR_DIGITAL_PORT_SWITCH_TO_D0();           
                CLR_DIGITAL_PORT_SWITCH_TO_D1();
                CLR_DIGITAL_PORT_SWITCH_TO_D2();
                CLR_DIGITAL_PORT_SWITCH_TO_D3();   

                ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);
                ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _OFF);

                ScalerGDIPhyPowerSavingProc();
            }            
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
            
            break;


        case _D0_DVI_PORT:
        case _D0_HDMI_PORT:
        case _D0_MHL_PORT:
        case _D0_DP_PORT:            

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)
            CLR_TMDS_D1_TOGGLE_Z0();
#endif
  
#if(_DIGITAL_PORT_SUPPORT == _ON)
            
            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {                
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE))
                {
                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
                }
#endif                

#if((_D2_INPUT_PORT_SWITCH_FROM != _SWITCH_FROM_D0) && (_D3_INPUT_PORT_SWITCH_FROM != _SWITCH_FROM_D0))
                PCB_DIGITAL_SWITCH_TO_D1_IDLE();
#endif                         
                PCB_DIGITAL_SWITCH_TO_D0();

                SET_DIGITAL_PORT_SWITCH_TO_D0(); 
                CLR_DIGITAL_PORT_SWITCH_TO_D1();
                CLR_DIGITAL_PORT_SWITCH_TO_D2();
                CLR_DIGITAL_PORT_SWITCH_TO_D3();                  

                ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _OFF);
            }
            else
            {               
#if((_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0) && (_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
                if((GET_D0_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE))
                {
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE))
                    {                        
                        PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
                    }
#endif                                        
                    CLR_D0_PORT_DIGITAL_SWITCH();
                    
                    PCB_DIGITAL_SWITCH_TO_D0();

                    SET_DIGITAL_PORT_SWITCH_TO_D0();
                    CLR_DIGITAL_PORT_SWITCH_TO_D2();
                    CLR_DIGITAL_PORT_SWITCH_TO_D3();

                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH);
                }                 
#elif(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
                if((GET_D0_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE))
                {
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE))
                    {
                        PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
                    }
#endif                      
                    CLR_D0_PORT_DIGITAL_SWITCH(); 
                    
                    PCB_DIGITAL_SWITCH_TO_D0();

                    SET_DIGITAL_PORT_SWITCH_TO_D0();                    
                    CLR_DIGITAL_PORT_SWITCH_TO_D2();   

                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH);
                }                
#elif(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
                if((GET_D0_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE))
                {
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE))
                    {
                        PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
                    }
#endif                    
                    CLR_D0_PORT_DIGITAL_SWITCH();
                    
                    PCB_DIGITAL_SWITCH_TO_D0();

                    SET_DIGITAL_PORT_SWITCH_TO_D0();  
                    CLR_DIGITAL_PORT_SWITCH_TO_D3();
 
                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH);
                }
#else

#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE))
                {
                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
                }
#endif
                PCB_DIGITAL_SWITCH_TO_D0();

                SET_DIGITAL_PORT_SWITCH_TO_D0();
#endif // End of #if((_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0) && (_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
            }

            ScalerGDIDigitalPhySwitch(ucInputPortType);

            ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _ON);

            ScalerGDIPhy2DSwitch(_D0_INPUT_PORT);

#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

            ScalerSyncAdcApllPowerDown();

            break;
            
        case _D1_DVI_PORT:
        case _D1_HDMI_PORT:
        case _D1_MHL_PORT:
        case _D1_DP_PORT:            

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)
            CLR_TMDS_D0_TOGGLE_Z0();
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
           
            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE))
                {
                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
                }
#endif

#if((_D2_INPUT_PORT_SWITCH_FROM != _SWITCH_FROM_D1) && (_D3_INPUT_PORT_SWITCH_FROM != _SWITCH_FROM_D1))
                PCB_DIGITAL_SWITCH_TO_D0_IDLE();
#endif                
                PCB_DIGITAL_SWITCH_TO_D1();
                
                CLR_DIGITAL_PORT_SWITCH_TO_D0();                
                SET_DIGITAL_PORT_SWITCH_TO_D1();
                CLR_DIGITAL_PORT_SWITCH_TO_D2();
                CLR_DIGITAL_PORT_SWITCH_TO_D3();                  

                ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);
            }
            else
            {               
#if((_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1) && (_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1))                
                if((GET_D1_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE))
                {
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE))
                    {
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
                    }
#endif                       
                    CLR_D1_PORT_DIGITAL_SWITCH();
                                        
                    PCB_DIGITAL_SWITCH_TO_D1();

                    SET_DIGITAL_PORT_SWITCH_TO_D1();                   
                    CLR_DIGITAL_PORT_SWITCH_TO_D2();
                    CLR_DIGITAL_PORT_SWITCH_TO_D3();
 
                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH);
                }
#elif(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
                if((GET_D1_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE))
                {
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE))
                    {
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
                    }
#endif                    
                    CLR_D1_PORT_DIGITAL_SWITCH();
                                        
                    PCB_DIGITAL_SWITCH_TO_D1();

                    SET_DIGITAL_PORT_SWITCH_TO_D1();  
                    CLR_DIGITAL_PORT_SWITCH_TO_D2();  

                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH);
                }                
#elif(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
                if((GET_D1_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE))
                {
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE))
                    {
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
                    }
#endif
                    CLR_D1_PORT_DIGITAL_SWITCH();
                    
                    PCB_DIGITAL_SWITCH_TO_D1();

                    SET_DIGITAL_PORT_SWITCH_TO_D1();  
                    CLR_DIGITAL_PORT_SWITCH_TO_D3();   

                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH);
                }
#else

#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE))
                {
                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
                }
#endif
                PCB_DIGITAL_SWITCH_TO_D1();

                SET_DIGITAL_PORT_SWITCH_TO_D1();                   
                
#endif // End of #if((_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1) && (_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1))                
            }

            ScalerGDIDigitalPhySwitch(ucInputPortType);

            ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _ON);

            ScalerGDIPhy2DSwitch(_D1_INPUT_PORT);            
            
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

            ScalerSyncAdcApllPowerDown();
            
            break;

        case _D2_DVI_PORT:
        case _D2_HDMI_PORT:

#if(_DIGITAL_PORT_SUPPORT == _ON)

            
#if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {  
#if(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE))
                {
                    PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
                }
#endif

#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
                PCB_DIGITAL_SWITCH_TO_D1_IDLE();
#endif                
                PCB_DIGITAL_SWITCH_TO_D2();

                CLR_DIGITAL_PORT_SWITCH_TO_D0();               
                CLR_DIGITAL_PORT_SWITCH_TO_D1();
                SET_DIGITAL_PORT_SWITCH_TO_D2();
                CLR_DIGITAL_PORT_SWITCH_TO_D3();

                ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _OFF);
            }
            else
            {
#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
                if((GET_D0_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE))
                {
#if(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE))
                    {
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
                    }
#endif                    
                    CLR_D0_PORT_DIGITAL_SWITCH();
                    
                    PCB_DIGITAL_SWITCH_TO_D2();

                    CLR_DIGITAL_PORT_SWITCH_TO_D0();            
                    SET_DIGITAL_PORT_SWITCH_TO_D2();
                    CLR_DIGITAL_PORT_SWITCH_TO_D3();
                    
                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH);
                }

#else // Else of #if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)

                if((GET_D0_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE))
                {   
#if(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE))
                    {
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
                    }
#endif
                    CLR_D0_PORT_DIGITAL_SWITCH(); 
                    
                    PCB_DIGITAL_SWITCH_TO_D2();

                    CLR_DIGITAL_PORT_SWITCH_TO_D0();                 
                    SET_DIGITAL_PORT_SWITCH_TO_D2();

                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH);
                }
#endif // End of #if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)               
            }

            ScalerGDIDigitalPhySwitch(ucInputPortType);

            ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _ON); 

            ScalerGDIPhy2DSwitch(_D0_INPUT_PORT);
            
#elif(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {         
#if(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE))
                {
                    PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
                }
#endif

#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
                PCB_DIGITAL_SWITCH_TO_D0_IDLE();
#endif                                
                PCB_DIGITAL_SWITCH_TO_D2();

                CLR_DIGITAL_PORT_SWITCH_TO_D0();                
                CLR_DIGITAL_PORT_SWITCH_TO_D1();
                SET_DIGITAL_PORT_SWITCH_TO_D2();

                CLR_DIGITAL_PORT_SWITCH_TO_D3();   

#if(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
                if(GET_HDMI_HOTPLUG_TOGGLE() == _TRUE)
                {
                    PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);
                }
#endif                                   
                ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);
            }
            else
            {      
#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
                if((GET_D1_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE) && GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
                {   
#if(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE))
                    {
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
                    }
#endif                    
                    CLR_D1_PORT_DIGITAL_SWITCH();
                   
                    PCB_DIGITAL_SWITCH_TO_D2();

                    CLR_DIGITAL_PORT_SWITCH_TO_D1();                     
                    SET_DIGITAL_PORT_SWITCH_TO_D2();
                    CLR_DIGITAL_PORT_SWITCH_TO_D3();
                     
                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH);
                }

#else // Else of #if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)

                if((GET_D1_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE))
                {                       

#if(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE))
                    {
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
                    }
#endif
                    CLR_D1_PORT_DIGITAL_SWITCH();
                   
                    PCB_DIGITAL_SWITCH_TO_D2();

                    CLR_DIGITAL_PORT_SWITCH_TO_D1();                   
                    SET_DIGITAL_PORT_SWITCH_TO_D2();  

                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH);
                }
#endif // End of #if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
            }

            ScalerGDIDigitalPhySwitch(ucInputPortType);

            ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _ON);

            ScalerGDIPhy2DSwitch(_D1_INPUT_PORT);

#endif // End of #if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)

#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)            

            ScalerSyncAdcApllPowerDown();

            break;

        case _D3_DVI_PORT:
        case _D3_HDMI_PORT:

#if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {        
#if(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE))
                {
                    PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D3_HOTPLUG(_D3_HOT_PLUG_HIGH);
                }
#endif   

#if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
                PCB_DIGITAL_SWITCH_TO_D1_IDLE();
#endif                                
                PCB_DIGITAL_SWITCH_TO_D3();

                CLR_DIGITAL_PORT_SWITCH_TO_D0();             
                CLR_DIGITAL_PORT_SWITCH_TO_D1();
                CLR_DIGITAL_PORT_SWITCH_TO_D2();
                SET_DIGITAL_PORT_SWITCH_TO_D3();                  
             
                ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _OFF);
            }
            else
            {
#if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
                if((GET_D0_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE))
                {
#if(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE))
                    {
                        PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D3_HOTPLUG(_D3_HOT_PLUG_HIGH);
                    }
#endif  
                    CLR_D0_PORT_DIGITAL_SWITCH();
                    
                    PCB_DIGITAL_SWITCH_TO_D3();

                    CLR_DIGITAL_PORT_SWITCH_TO_D0();                 
                    CLR_DIGITAL_PORT_SWITCH_TO_D2();
                    SET_DIGITAL_PORT_SWITCH_TO_D3();
 
                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH);
                }

#else // Else of #if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)

                if((GET_D0_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE))
                {   
#if(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE))
                    {
                        PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D3_HOTPLUG(_D3_HOT_PLUG_HIGH);
                    }
#endif                      
                    CLR_D0_PORT_DIGITAL_SWITCH(); 
                    
                    PCB_DIGITAL_SWITCH_TO_D3();

                    CLR_DIGITAL_PORT_SWITCH_TO_D0();                      
                    SET_DIGITAL_PORT_SWITCH_TO_D3();   
 
                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH);
                }
#endif // End of #if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)              
            }

            ScalerGDIDigitalPhySwitch(ucInputPortType);

            ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _ON);   

            ScalerGDIPhy2DSwitch(_D0_INPUT_PORT);
            
#elif(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {       
#if(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE))
                {
                    PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D3_HOTPLUG(_D3_HOT_PLUG_HIGH);
                }
#endif    

#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
                PCB_DIGITAL_SWITCH_TO_D0_IDLE();
#endif                                
                PCB_DIGITAL_SWITCH_TO_D3();

                CLR_DIGITAL_PORT_SWITCH_TO_D0();              
                CLR_DIGITAL_PORT_SWITCH_TO_D1();
                CLR_DIGITAL_PORT_SWITCH_TO_D2();
                SET_DIGITAL_PORT_SWITCH_TO_D3();  
               
                ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);
            }
            else
            {      
#if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
                if((GET_D1_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE) && GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
                {   
#if(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE))
                    {
                        PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D3_HOTPLUG(_D3_HOT_PLUG_HIGH);
                    }
#endif                       
                    CLR_D1_PORT_DIGITAL_SWITCH();
                   
                    PCB_DIGITAL_SWITCH_TO_D3();

                    CLR_DIGITAL_PORT_SWITCH_TO_D1();                     
                    CLR_DIGITAL_PORT_SWITCH_TO_D2();
                    SET_DIGITAL_PORT_SWITCH_TO_D3();
                    
                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH);
                }
                
#else // Else of #if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)

                if((GET_D1_PORT_DIGITAL_SWITCH() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE))
                {                    
#if(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE))
                    {
                        PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D3_HOTPLUG(_D3_HOT_PLUG_HIGH);
                    }
#endif 
                    CLR_D1_PORT_DIGITAL_SWITCH();
                   
                    PCB_DIGITAL_SWITCH_TO_D3();

                    CLR_DIGITAL_PORT_SWITCH_TO_D1();               
                    SET_DIGITAL_PORT_SWITCH_TO_D3(); 
  
                    ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH);
                }
#endif // End of #if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
            }

            ScalerGDIDigitalPhySwitch(ucInputPortType);

            ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _ON); 

            ScalerGDIPhy2DSwitch(_D1_INPUT_PORT);

#endif // End of #if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)

#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
          
            ScalerSyncAdcApllPowerDown();

            break;
 
#if(_DIGITAL_PORT_SUPPORT == _ON)

        case _D1_DP_DUAL_PORT:

            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE) && (GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS)) 
            {                    
                PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
            }

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {                                
                CLR_DIGITAL_PORT_SWITCH_TO_D0();                
                CLR_DIGITAL_PORT_SWITCH_TO_D2();
                CLR_DIGITAL_PORT_SWITCH_TO_D3();                  
                
                ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);
            }

            SET_DIGITAL_PORT_SWITCH_TO_D1();

            ScalerGDIDigitalPhySwitch(ucInputPortType);

            ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _ON);

            ScalerGDIPhy2DSwitch(_D1_INPUT_PORT);

            break;

#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON) 

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Power Down VGA Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncAdcApllPowerDown(void)
{
    // Power down APLL
    ScalerSetBit(P1_AF_PLL_WD, ~_BIT0, _BIT0);    
    
    // Power down ADC VCM/ADC clock/SOG Power/RGB Channel
    ScalerSetBit(P0_C6_ADC_POWER, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2 | _BIT1 | _BIT0), 0x00); 
}

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Quick Recover from Power Saving
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerSyncPSRecover_EXINT1(void) using 2
{
    BYTE ucTimeOut = 200;
    
    // Recover GDI Power Cut
    if(ScalerGetBit_EXINT1(CM_0A_POWER_CTRL1, _BIT1) == _BIT1)
    {    
        if((MCU_CTRL_FFED & _BIT1) == 0x00)
        {
            // Set Flash/Mcu Clock Divider to 1
            MCU_CTRL_FFED = _BIT2 | (MCU_CTRL_FFED & 0xC3);
            MCU_CLOCK_CTRL_FFEE = _BIT2 | (MCU_CLOCK_CTRL_FFEE & 0xC3);    
        }
        
        // Weak power on
        ScalerSetBit_EXINT1(CM_0A_POWER_CTRL1, ~_BIT4, _BIT4);

        // Wait for weak power on flag
		ucTimeOut = 200;
		
        while((ScalerGetBit_EXINT1(CM_0A_POWER_CTRL1, _BIT6) != _BIT6) && (ucTimeOut-- > 0));

        // Strong power on    
        ScalerSetBit_EXINT1(CM_0A_POWER_CTRL1, ~_BIT5, _BIT5);

        // Wait for strong power on flag
        ucTimeOut = 200;
        
        while((ScalerGetBit_EXINT1(CM_0A_POWER_CTRL1, _BIT7) != _BIT7) && (ucTimeOut-- > 0));            

        // Block Reset
        ScalerSetBit_EXINT1(CM_0A_POWER_CTRL1, ~_BIT0, _BIT0);

        // Waiting for GDI put cut reset finish.
        for(ucTimeOut = 0; ucTimeOut <= 5; ucTimeOut++)
        {
            _nop_();    
        }

        // Block Normal
        ScalerSetBit_EXINT1(CM_0A_POWER_CTRL1, ~_BIT0, 0x00);

        // GDI Normal Operation mode.
        ScalerSetBit_EXINT1(CM_0A_POWER_CTRL1, ~_BIT1, 0x00);

        // Recover HDCP Block
        // Clear Key Ready Falg & Set Authst New Mode
        ScalerSetBit_EXINT1(P2_AE_TMDS_RPS, ~(_BIT1 | _BIT0), _BIT0);

        // Fill In Backup Bksv
        ScalerSetBit_EXINT1(P2_C0_HDCP_CTRL, ~(_BIT2 | _BIT0), _BIT0);

        ScalerSetByte_EXINT1(P2_C3_HDCP_ADDR_PORT, 0x00);
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, g_ucHdcpBksvBackup[0]);    
        ScalerSetByte_EXINT1(P2_C3_HDCP_ADDR_PORT, 0x01);
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, g_ucHdcpBksvBackup[1]);
        ScalerSetByte_EXINT1(P2_C3_HDCP_ADDR_PORT, 0x02);
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, g_ucHdcpBksvBackup[2]);    
        ScalerSetByte_EXINT1(P2_C3_HDCP_ADDR_PORT, 0x03);
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, g_ucHdcpBksvBackup[3]);    
        ScalerSetByte_EXINT1(P2_C3_HDCP_ADDR_PORT, 0x04);
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, g_ucHdcpBksvBackup[4]);        

        // Set HDCP Feature
        ScalerSetByte_EXINT1(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS);
        
#if(_HDMI_SUPPORT == _ON)

#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_0)
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, 0x91);            
#elif(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_1)
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, 0x93);
#else
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, 0x91);
#endif

#else // Else of #if(_HDMI_SUPPORT == _ON)

#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_0)
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, 0x11);            
#elif(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_1)
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, 0x13);
#else
        ScalerSetByte_EXINT1(P2_C4_HDCP_DATA_PORT, 0x11);
#endif

#endif // End of #if(_HDMI_SUPPORT == _ON)

        if(g_bTmdsD0DdcDetected == _TRUE)
        {
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
            // Set HDCP DDC Channel
            ScalerSetBit_EXINT1(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), 0x00);
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
            // Set HDCP DDC Channel
            ScalerSetBit_EXINT1(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), _BIT1);
#endif
        }
        else
        {
#if(_D1_DDC_CHANNEL_SEL == _DDC2)            
            // Set HDCP DDC Channel
            ScalerSetBit_EXINT1(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), 0x00);
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
            // Set HDCP DDC Channel
            ScalerSetBit_EXINT1(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), _BIT1);
#endif
        }

        // Set DDC Debounce
        ScalerSetBit_EXINT1(P2_AC_Z0CC2, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6));

        return _TRUE;
    }

    return _FALSE;
}
#endif

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
//--------------------------------------------------
// Description  : Get HDMI FREESYNC VCP
// Input Value  : None
// Output Value : HDMI FREESYNC VCP
//                False --> Disabled
//--------------------------------------------------
BYTE ScalerSyncGetHDMIFREESYNCVcp_EXINT1(void) using 2
{
    return GET_HDMI_FREESYNC_VCP();
}

//--------------------------------------------------
// Description  : Set HDMI FREESYNC VCP
// Input Value  : HDMI FREESYNC VCP
// Output Value : None
//--------------------------------------------------
void ScalerSyncSetHDMIFREESYNCVcp_EXINT1(BYTE ucVcpCode) using 2
{
    g_ucHDMIFREESYNCVCPReceive = ucVcpCode;
}
#endif

