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
// ID Code      : SysInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
//----------------------------------------------------------------------------------------
// Extern functions from SysMode.c
//----------------------------------------------------------------------------------------
extern BYTE SysModeGetModeState(void);
extern bit SysModeGetTimingConfirm(void);
extern void SysModeSetFreeRun(void);
extern bit SysModeGetModeStateChange(void);
extern void SysModeSetResetTarget(EnumModeAction enumResetTarget);
extern void SysModeColorSpaceConvert(EnumColorSpace enumColorFormat);

//----------------------------------------------------------------------------------------
// Extern functions from SysPower.c
//----------------------------------------------------------------------------------------
extern BYTE SysPowerGetPowerStatus(void);
extern void SysPowerSetTargetPowerStatus(EnumPowerStatus enumPorStatus);

//----------------------------------------------------------------------------------------
// Extern functions from SysSource.c
//----------------------------------------------------------------------------------------
extern BYTE SysSourceGetSourceType(void);
extern BYTE SysSourceGetInputPort(void);

#if(_SLEEP_AUDIO_SUPPORT == _ON)
extern BYTE SysSourceGetAudioPlaybackPort(void);
#endif

extern void SysSourceSwitchInputPort(BYTE ucInputPort);
extern bit SysSourceCheckTargetTimes(BYTE ucTargetTimes);
extern void SysSourceSetScanType(BYTE ucScanType);
extern BYTE SysSourceGetScanType(void);
extern BYTE SysSourceConvertSearchPort(BYTE ucInputPort);
extern bit SysSourceGetCableDetect(BYTE ucInputPort);
extern bit SysSourceGetCableStatusChange(BYTE ucInputPort);
extern void SysSourceSetSearchPriority(EnumSourceSearchPort enumPort, EnumSourceSearchPortPriority enumSourcePriority);
extern void SysSourceSetSearchGroup(EnumSourceSearchPort enumPort, EnumSourceSearchGroup enumSourceGroup);

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
extern bit SysSourceHpGetSourceJudge(void);
extern BYTE SysSourceHpGetTargetSourceType(BYTE ucSearchIndex);
extern BYTE SysSourceHpGetTargetSearchTimes(void);
extern bit SysSourceHpGetSwitchPortNoCable(void);
extern bit SysSourceHpGetTargetPortNoSignal(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from SysAudio.c
//----------------------------------------------------------------------------------------

#if(_AUDIO_SUPPORT == _ON)
extern EnumAudioState SysAudioGetAudioState(void);
extern void SysAudioMuteProc(bit bMute);

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
extern void SysAudioInternalGenTestProc(bit bOn);
#endif
#endif
