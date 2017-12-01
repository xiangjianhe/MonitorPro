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
// ID Code      : RL6192_Series_Audio_Interface.h No.0000
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
#if(_AUDIO_SUPPORT == _ON)

#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern void ScalerAudioDACInitial(void);
extern void ScalerAudioDACInputSwitch(bit bAudioSource);
extern void ScalerAudioDACOutputSwitch(EnumAudioDACOutput enumDACOutput);
extern bit ScalerAudioDACGetInputSource(void);
#endif

extern void ScalerAudioDisable(void);
extern void ScalerAudioDigitalAdjustVolume(WORD usVolume);
extern void ScalerAudioDigitalVolumeMute(bit bMute, WORD usVolume);
extern void ScalerAudioDigitalOutputMute(bit bMute);
extern void ScalerAudioWatchDogProc(bit bOn);
#endif
