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
// ID Code      : ScalerAudioInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#define _INITIAL_I_CODE                             0x0040
#define _STABLE_I_CODE                              0x0004

#if(_EMBEDDED_DAC_SUPPORT == _ON)
#define GET_AUDIO_DAC_STATE()                       (g_stAudioDACInfo.b3AudioDACState)
#define SET_AUDIO_DAC_STATE(x)                      (g_stAudioDACInfo.b3AudioDACState = x)

#define GET_AUDIO_DAC_STATE_CHANGE()                (bit)(g_stAudioDACInfo.b1AudioDACStateChange)
#define SET_AUDIO_DAC_STATE_CHANGE()                (g_stAudioDACInfo.b1AudioDACStateChange = _TRUE)
#define CLR_AUDIO_DAC_STATE_CHANGE()                (g_stAudioDACInfo.b1AudioDACStateChange = _FALSE)
#endif

#define GET_AUDIO_SAMPLING_FREQ()                   (g_stAudioDigtalInfo.b4AudioSamplingFreq)
#define SET_AUDIO_SAMPLING_FREQ(x)                  (g_stAudioDigtalInfo.b4AudioSamplingFreq = x)

#define GET_AUDIO_PACKET_DETECT()                   (bit)(g_stAudioDigtalInfo.b1AudioDetected)
#define SET_AUDIO_PACKET_DETECT()                   (g_stAudioDigtalInfo.b1AudioDetected = _TRUE)
#define CLR_AUDIO_PACKET_DETECT()                   (g_stAudioDigtalInfo.b1AudioDetected = _FALSE)

#define GET_DIGITAL_AUDIO_SOURCE()                  (g_stAudioDigtalInfo.b2AudioDigitalSource)
#define SET_DIGITAL_AUDIO_SOURCE(x)                 (g_stAudioDigtalInfo.b2AudioDigitalSource = x)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

#if(_EMBEDDED_DAC_SUPPORT == _ON)
typedef struct
{
    BYTE b3AudioDACState : 3;
    BYTE b1AudioDACStateChange : 1;
}StructAudioDACInfo;
#endif

typedef struct
{
    BYTE b4AudioSamplingFreq : 4;
    BYTE b1AudioDetected : 1;
    BYTE b1AudioICodeReloaded : 1;
    BYTE b2AudioDigitalSource : 2;
}StructAudioDigitalInfo;
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern StructAudioDACInfo g_stAudioDACInfo;
#endif

extern StructAudioDigitalInfo g_stAudioDigtalInfo;
//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern BYTE ScalerAudioSamplingFreqDetect(void);
extern void ScalerAudioLoadStableICodeEvent(void);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern void ScalerAudioDACSetState(EnumAudioDACState enumTargetState);
extern void ScalerAudioDACSetVcmReady(bit bReady);
extern void ScalerAudioDACNormalToDepop(void);
extern void ScalerAudioDACDepopToNormal(void);
extern void ScalerAudioDACRestart(void);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)
