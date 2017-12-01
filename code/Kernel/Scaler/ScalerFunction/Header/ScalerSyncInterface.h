/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : ScalerSyncInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Definitions of ADC Clock Limit
//--------------------------------------------------
#define GET_ADC_LIMIT_CLOCK()                          (g_usAdcClockLimit)

//--------------------------------------------------
// Definitions of Sync Channel
//--------------------------------------------------
#define GET_VGA_SYNC_FROM_SOG()                        ScalerSyncVgaGetSyncPad()
#endif

//--------------------------------------------------
// Macros of HDMI HotPlug Toggle Support
//--------------------------------------------------
#if(_DIGITAL_PORT_SUPPORT)
#define GET_HDMI_HOTPLUG_TOGGLE()                    ((g_ucHDMIHotPlug & _BIT7) >> 7)
#define SET_HDMI_HOTPLUG_TOGGLE()                    (g_ucHDMIHotPlug |= _BIT7)
#define CLR_HDMI_HOTPLUG_TOGGLE()                    (g_ucHDMIHotPlug &= ~_BIT7)

#define GET_HDMI_HOTPLUG_TIME()                      ((WORD)(g_ucHDMIHotPlug & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) * 100)
#define SET_HDMI_HOTPLUG_TIME(x)                     (g_ucHDMIHotPlug = (g_ucHDMIHotPlug & ~(_BIT3 | _BIT2 | _BIT1 | _BIT0)) | (x))
#endif


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
extern WORD idata g_usAdcClockLimit;
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
extern BYTE xdata g_ucDigitalSwitch;
extern BYTE xdata g_ucHDMIHotPlug;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_VGA_SUPPORT == _ON)
extern void ScalerSyncVgaScanInitial(void);
extern bit ScalerSyncVgaPreDetect(void);
extern bit ScalerSyncVgaStableDetect(void);
extern bit ScalerSyncVgaGetSyncPad(void);
extern BYTE ScalerSyncVgaSyncTypeAutoRun(void);
extern bit ScalerSyncVgaAdcClkInitial(void);
extern void ScalerSyncVgaSyncProcClampPosCheck(BYTE ucVideoModeFlg);
extern bit ScalerSyncVgaAdcClkSetting(void);
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
extern void ScalerSyncTmdsScanInitial(BYTE ucInputPort);
extern bit ScalerSyncTmdsNormalPreDetect(BYTE ucInputPort);
extern BYTE ScalerSyncTmdsScanInputPort(BYTE ucInputType);
extern bit ScalerSyncTmdsPSPreDetect(BYTE ucInputPort);
extern bit ScalerSyncTmdsStableDetect(BYTE ucSourceType);

#if(_MHL_SUPPORT == _ON)
extern bit ScalerSyncMHLPSPreDetect(BYTE ucInputPort);
extern bit ScalerSyncMHLNormalPreDetect(BYTE ucInputPort);
#endif

#endif

#if(_DP_SUPPORT == _ON)
extern void ScalerSyncDpScanInitial(void);
extern bit ScalerSyncDpNormalPreDetect(void);
extern BYTE ScalerSyncDpScanInputPort(void);
extern bit ScalerSyncDpPSPreDetect(void);
extern bit ScalerSyncDpStableDetect(void);
extern void ScalerSyncDpHPDPowerOfftoNormalProc(BYTE ucDpHotPlugDCOffHigh);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
extern void ScalerSyncHdcpEnableDownLoadKey(bit bEnable);
extern void ScalerSyncHdcpDownLoadBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
extern void ScalerSyncHdcpDownLoadKey(WORD usLength, BYTE *pReadArray);
extern bit ScalerSyncHdcpCheckEnabled(BYTE ucInputPort);    
#endif

extern void ScalerSyncInterlaceInitial(BYTE ucSourceType);
extern bit ScalerSyncInterlaceCheck(BYTE ucSourceType);
extern void ScalerSyncActiveProc(BYTE ucSourceType);
extern void ScalerSyncPowerProc(EnumPowerAction enumPowerAction);
extern void ScalerSyncSwitchGDIClk(BYTE ucClk);
extern WORD ScalerSyncGetInputPixelClk(void);
extern void ScalerSyncInterfaceSwitch(BYTE ucInputPortType, BYTE ucSourceSearchDelayMode);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
extern BYTE ScalerSyncPSRecover_EXINT1(void);
#endif

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
extern BYTE ScalerSyncGetHDMIFREESYNCVcp_EXINT1(void);
extern void ScalerSyncSetHDMIFREESYNCVcp_EXINT1(BYTE ucVcpCode);
#endif

