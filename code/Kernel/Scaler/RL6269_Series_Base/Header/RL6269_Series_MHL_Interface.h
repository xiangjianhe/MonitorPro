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
// ID Code      : RL6269_Series_MHL_Interface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_MHL_SUPPORT == _ON)
extern void ScalerMHLModeMHLSetting(BYTE ucInputPort);
extern void ScalerMHLModeHdmiSetting(BYTE ucInputPort);
extern void ScalerMHLInitialSettings(void);
extern void ScalerMHLCBUSPhySwitch(BYTE ucPortSelect, bit bSelect);
extern void ScalerMHLCBUSSwitchClk(EnumClkSel enumClockSel);
extern void ScalerMHLIntHandler_EXINT0(void);
extern bit ScalerMHLMscSendCommand(BYTE ucInputPort, EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue);
extern void ScalerMHLMscCheckDeviceINT(BYTE ucInputPort);
extern bit ScalerMHLMscHandler(BYTE ucInputPort, BYTE ucActivePort, BYTE ucModeState);
extern bit ScalerMHLMscRAPHandler(BYTE ucInputPort);
extern bit ScalerMHLMscRCPGetCommand(BYTE ucInputPort, BYTE *pucKeyCode);

#if(_MHL_UCP_SUPPORT == _ON)
extern bit ScalerMHLMscUCPGetCommand(BYTE ucInputPort, BYTE *pucKeyCode);
#endif

#endif // End of #if(_MHL_SUPPORT == _ON)
