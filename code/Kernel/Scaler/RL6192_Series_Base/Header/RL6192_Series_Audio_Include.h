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
// ID Code      : RL6192_Series_Audio_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_DP_SUPPORT == _ON)
#define _DP_BCH_ERROR_HANDLE                      _ON
#else
#define _DP_BCH_ERROR_HANDLE                      _OFF
#endif


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __RL6192_SERIES_AUDIO__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

#if(_AUDIO_SUPPORT == _ON)

#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern void ScalerAudioDACInitial(void);
extern bit ScalerAudioDACGetInputSource(void);
#endif

extern void ScalerAudioDigitalAudioInitial(void);
extern void ScalerAudioDigitalVolumeMute(bit bMute, WORD usVolume);

#if(_DP_BCH_ERROR_HANDLE == _ON)
extern void ScalerAudioDpBchErrorHandle(void);
#endif

#endif

#endif // End of #ifndef __RL6192_SERIES_AUDIO__
