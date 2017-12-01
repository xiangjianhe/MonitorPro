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
// ID Code      : RL6269_Series_DP_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//----------------------------------------------------------------------------
// Macro of Dp Link Training Information
//----------------------------------------------------------------------------
#define GET_DP_FAKE_LINK_TRAINING()                 ((g_ucDpInfo & _BIT7) >> 7)
#define SET_DP_FAKE_LINK_TRAINING()                 (g_ucDpInfo |= _BIT7)
#define CLR_DP_FAKE_LINK_TRAINING()                 (g_ucDpInfo &= ~_BIT7)

#define GET_DP_VALID_VIDEO_CHECK()                  ((g_ucDpInfo & _BIT6) >> 6)
#define SET_DP_VALID_VIDEO_CHECK()                  (g_ucDpInfo |= _BIT6)
#define CLR_DP_VALID_VIDEO_CHECK()                  (g_ucDpInfo &= ~_BIT6)

#define GET_DP_PS_AUX_TOGGLE()                      (g_bDpPSAuxToggle)
#define SET_DP_PS_AUX_TOGGLE()                      (g_bDpPSAuxToggle = _TRUE)
#define CLR_DP_PS_AUX_TOGGLE()                      (g_bDpPSAuxToggle = _FALSE)

#define GET_DP_LINK_TRAINING_STATUS()               (g_ucDpLTStatus)
#define SET_DP_LINK_TRAINING_STATUS(x)              (g_ucDpLTStatus = x)

#define GET_DP_PHY_CTS_FLG()                        (bit)ScalerGetBit(PB_A0_SIG_DET, _BIT7)
#define SET_DP_PHY_CTS_FLG()                        ScalerSetBit(PB_A0_SIG_DET, ~_BIT7, _BIT7)
#define CLR_DP_PHY_CTS_FLG()                        ScalerSetBit(PB_A0_SIG_DET, ~_BIT7, 0x00)

#define GET_DP_MSA_FAIL_MAC_RESET_COUNT()           (g_ucDpMSAFailMacRsetCount)
#define ADD_DP_MSA_FAIL_MAC_RESET_COUNT()           (g_ucDpMSAFailMacRsetCount++)
#define CLR_DP_MSA_FAIL_MAC_RESET_COUNT()           (g_ucDpMSAFailMacRsetCount = 0)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//--------------------------------------------------
// Definitions for DP training Pattern 1 FLD Reference Clock Select
//--------------------------------------------------
typedef enum
{
    _DP_FLD_REF_D10_2 = 0x00,
    _DP_FLD_REF_XTAL,
} EnumDpTp1FLDClk;

//--------------------------------------------------
// Definitions of DP Link Rate
//--------------------------------------------------
typedef enum
{
    _DP_LINK_HBR = 0x00,
    _DP_LINK_RBR,
} EnumDpLinkRate;


#ifndef __RL6269_SERIES_DP__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern bit g_bDpPSAuxToggle;
extern BYTE xdata g_ucDpInfo;
extern BYTE xdata g_ucDpLTStatus;


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

#if(_DP_SUPPORT == _ON)
extern void ScalerDpHotPlugEvent(EnumDpHotPlugAssertType enumHpdType);
extern void ScalerDpLinkStatusIRQ(void);
extern void ScalerDpMacInitial(void);
extern void ScalerDpPhyInitial(void);
extern void ScalerDpRebuildPhy(BYTE ucDpcdRate, BYTE ucDpcdLane);
extern void ScalerDpValidSignalDetection(void);
extern bit ScalerDpCDRCheck(void);
extern bit ScalerDpAlignCheck(void);
extern bit ScalerDpDecodeCheck(void);
extern bit ScalerDpGetVideoStream(void);
extern bit ScalerDpMSACheck(void);
extern bit ScalerDpMiscCheck(void);
extern void ScalerDpDisplayFormatSetting(void);
extern void ScalerDpVideoSetting(void);
extern bit ScalerDpStreamClkRegenerate(void);
extern void ScalerDpAdjustVsyncDelay(void);
extern bit ScalerDpFifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition);
extern void ScalerDpSinkStatusSet(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);  
extern void ScalerDpCrcCalculate(void);
extern bit ScalerDpHdcpCheck(void);
extern void ScalerDpCpIRQ(void);
extern bit ScalerDpHdcpEnebled(void);
extern void ScalerDpLowPowerCheck(BYTE ucPowerAction);
extern BYTE ScalerDpGetDpcdInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
extern BYTE ScalerDpGetDpcdInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
extern void ScalerDpSetDpcdValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpSetDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpPhyCTS(void); 

#if(_DP_ASSR_MODE_SUPPORT == _ON)
extern void ScalerDpASSRModeSetting(void);
#endif

#endif

#endif // End of #ifndef __RL6269_SERIES_DP__
