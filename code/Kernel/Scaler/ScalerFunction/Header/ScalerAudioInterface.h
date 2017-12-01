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
// ID Code      : ScalerAudioInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerAudioInitial(void);
extern void ScalerAudioMuteProc(bit bMute, WORD usVolume);
extern void ScalerAudioDigitalDetect(void);
extern bit ScalerAudioGetAudioDetected(void);
extern BYTE ScalerAudioGetDigitalAudioSource(void);
extern bit ScalerAudioLPCMCheckData(void);

#if(_HDMI_SUPPORT == _ON)
extern bit ScalerAudioLPCMCheckInfo(void);
#endif

extern void ScalerAudioDigitalOutputMute(bit bMute);

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
extern void ScalerAudioInternalAudioGenSwitch(bit bOn);
extern bit ScalerAudioGetInternalAudioGenEnable(void);
#endif

#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern void ScalerAudioDACSetState(EnumAudioDACState enumTargetState);
extern EnumAudioDACState ScalerAudioDACGetState(void);
extern bit ScalerAudioDACGetStateChange(void);
extern void ScalerAudioDACClrStateChange(void);
extern void ScalerAudioDACSetVcmReady(bit bReady);
extern void ScalerAudioDACNormalToDepop(void);
extern void ScalerAudioDACDepopToNormal(void);
extern void ScalerAudioDACOutputEnable(void);
extern EnumAudioDACOutput ScalerAudioDACGetOutput(void);
extern void ScalerAudioDACRestart(void);
extern void ScalerAudioAnalogVolumeMute(bit bMute, BYTE ucVolume);
extern void ScalerAudioAnalogAdjustVolume(WORD usVolume, bit bAudioInputType);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)
