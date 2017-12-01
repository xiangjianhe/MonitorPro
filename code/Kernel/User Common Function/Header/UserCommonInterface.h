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
// ID Code      : UserCommonInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
//----------------------------------------------------------------------------------------
// Extern functions from UserCommonAdjust.c
//----------------------------------------------------------------------------------------
#if(_I_DITHER_SUPPORT == _ON)
extern void UserCommonAdjustIDither(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonDdcciFunction.c
//----------------------------------------------------------------------------------------
extern void UserCommonDdcciHandler(void);

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonInterface.c
//----------------------------------------------------------------------------------------
extern void UserCommonInterfaceAdjustColorProc(void);
extern void UserCommonInterfaceOsdActiveProc(void);
extern void UserCommonInterfaceOsdResetProc(void);
extern void UserCommonInterfaceAdjustInputTiming(void);
extern bit UserCommonInterfaceReadyForActive(void);

#if(_VGA_SUPPORT == _ON)
extern void UserCommonInterfaceAdjustADCData(void);
#endif

extern bit UserCommonInterfaceCheckNoSupport(void);

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
extern void UserCommonInterfaceDdcciIntGetData_EXINT1(void);
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
extern bit UserCommonInterfaceGetRunDdcciCommand(void);
#endif

extern void UserCommonInterfaceInitial(void);

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonNVRamSystem.c
//----------------------------------------------------------------------------------------
extern BYTE UserCommonNVRamGetSystemData(EnumSystemDataItemDataType enumDataType);
extern void UserCommonNVRamSetSystemData(BYTE ucDataType, BYTE ucValue);

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

extern void UserCommonEepromSaveSystemData(void);
extern void UserCommonEepromRestoreSystemData(void);

#if(_VGA_SUPPORT == _ON)
extern void UserCommonEepromLoadADCSetting(EnumColorSpace enumColorFormat);
#endif

#define UserCommonNVRamSaveSystemData()        UserCommonEepromSaveSystemData()
#if(_VGA_SUPPORT == _ON)
#define UserCommonNVRamLoadADCSetting(x)       UserCommonEepromLoadADCSetting(x)
#endif

#else // Else of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

extern void UserCommonFlashSaveSystemData(void);
extern void UserCommonFlashRestoreSystemData(void);

#if(_VGA_SUPPORT == _ON)
extern void UserCommonFlashLoadADCSetting(EnumColorSpace enumColorFormat);
#endif

#define UserCommonNVRamSaveSystemData()        UserCommonFlashSaveSystemData()
#if(_VGA_SUPPORT == _ON)
#define UserCommonNVRamLoadADCSetting(x)       UserCommonFlashLoadADCSetting(x)
#endif

#endif // End of #elif(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)


//----------------------------------------------------------------------------------------
// Extern functions from UserModeSearch.c
//----------------------------------------------------------------------------------------
#if (_VGA_SUPPORT == _ON)
extern BYTE UserCommonModeSearchModeVGA(void);
extern BYTE UserCommonModeSearchGetModeVideoType(BYTE ucIndex);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserInterface.c
//----------------------------------------------------------------------------------------
extern void UserInterfaceTimerEventProc(BYTE ucEventID);

#if(_INSTANT_TIMER_EVENT_0 == _ON)
extern void UserInterfaceTimer0InstantAccess_TIMER0(void);
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
extern void UserInterfaceTimer1InstantAccess_TIMER1(void);
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
extern void UserInterfaceTimer2InstantAccess_TIMER2(void);
#endif

#if(_UART_SUPPORT == _ON)
extern void UserInterfaceUartIntHandler_SERIALPORT(void);
#endif

extern void UserInterfacePowerSwitch(EnumPowerAction enumSwitch);
extern void UserInterfaceInitial(void);
extern void UserInterfacePanelPowerAction(BYTE ucEvent);
extern void UserInterfaceOsdPowerOnInitial(void);
extern bit UserInterfaceOsdGetLogoOn(void);
extern void UserInterfaceAdjustDisplayTiming(void);

#if((_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE))
extern void UserInterfaceChangeMHLEDIDData(BYTE ucInputPort);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
extern void UserInterfaceGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
extern void UserInterfaceGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
extern BYTE UserInterfaceGetDdcciStatus_EXINT1(void);
#endif

extern bit UserInterfaceCheckIntoPS(void);
extern void UserInterfaceKeyPadLedControl(BYTE ucKeyPadLed);

#if((_VGA_SUPPORT == _ON) && (_YPBPR_SUPPORT == _ON))
extern bit UserInterfaceCheckHDTVMode(BYTE ucModeNumber);
#endif

#if(_AUDIO_SUPPORT == _ON)
extern bit UserInterfaceGetAudioReadyToPlay(void);
extern WORD UserInterfaceGetAudioVolume(void);
extern bit UserInterfaceGetAudioSource(void);
extern bit UserInterfaceDecideAudioNonLPCMMute(void);
extern void UserInterfaceAudioPowerProc(EnumPowerStatus enumPowStatus);
extern void UserInterfaceAudioAmpMuteProc(bit bMute);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern EnumAudioDACOutput UserInterfaceGetAudioDACOutput(void);
#endif

#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
extern bit UserInterfaceGetAudioStandAlone(void);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)

extern bit UserInterfaceCheckCableReset(void);
extern void UserInterfaceUncallFunction(void);
extern bit UserInterfaceGetForcePowSavStatus(void);
extern bit UserInterfaceDClkNoSupportCheck(void);

#if(_MHL_SUPPORT == _ON)
extern bit UserInterfaceMHLMscRCPProc(BYTE ucKeyCode);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserOsd.c
//----------------------------------------------------------------------------------------
extern void UserOsdHandler(void);

//----------------------------------------------------------------------------------------
// Extern functions from UserKey.c
//----------------------------------------------------------------------------------------
extern void UserKeyHandler(void);

