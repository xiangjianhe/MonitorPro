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
// ID Code      : ScalerTimerFunctionInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __SCALER_TIMERFUNCTION__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerTimerSetTimerCount(EnumScalerTimerOperationMode enumOperationMode);
extern void ScalerTimerActiveTimerEvent(WORD usTime, BYTE ucEventID);
extern void ScalerTimerReactiveTimerEvent(WORD usTime, BYTE ucEventID);
extern void ScalerTimerCancelTimerEvent(BYTE ucEventID);
extern void ScalerTimerDelayXms(WORD usNum);
extern bit ScalerTimerPollingFlagProc(WORD usTimeout, WORD ucRegister, BYTE ucBit, bit bSuccess);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern bit ScalerTimerPollingDataBitFlagProc(WORD usTimeout, WORD usRegister, BYTE ucValue, BYTE ucBit, bit bSuccess);
#endif
extern bit ScalerTimerWaitForEvent(EnumWaitEventType enumEvent);

#endif // End of #ifndef __SCALER_TIMERFUNCTION__