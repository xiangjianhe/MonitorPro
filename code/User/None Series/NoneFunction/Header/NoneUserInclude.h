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
// ID Code      : UserInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "NoneUserModeTable.h"

#if(_OSD_TYPE == _NONE_OSD)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _CHECK_ADC_SAVE,
    _CHECK_ADC_LOAD,
    _CHECK_SYSTEM_DATA_SAVE,
    _CHECK_SYSTEM_DATA_LOAD,
    _CHECK_MODE_USER_DATA_SAVE,
    _CHECK_MODE_USER_DATA_LOAD,    
} EnumADCCheckType;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

//----------------------------------------------------------------------------------------
// Extern functions from UserAdjust.c
//----------------------------------------------------------------------------------------
#ifndef __USER_ADJUST__
#if(_OVERSCAN_SUPPORT == _ON)
extern bit UserAdjustCheckOverScan(void);
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
extern WORD UserAdjustSelectAspectRatio(void);
#endif

extern void UserAdjustContrast(BYTE ucContrast);
extern void UserAdjustBacklight(BYTE ucBacklight);
extern void UserAdjustBrightness(BYTE ucBrightness);
extern void UserAdjustSharpness(BYTE ucSharpness);
extern void UserAdjustLoadDitherTable(void);

#if(_VGA_SUPPORT == _ON)

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
extern void UserAdjustDigitalFilterEnhancePhase(void);
#endif

#if(_RINGING_FILTER_SUPPORT == _ON)
extern void UserAdjustRingingFilter(void);
#endif

#endif  // End of #if(_VGA_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON)
extern void UserAdjustIDitherOn(void);
#endif

#if(_YPEAKING_SUPPORT == _ON)
extern void UserAdjustYpeaking(void);
#endif

#if(_OD_SUPPORT == _ON)
extern void UserAdjustODLoadLUT(void);
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
extern void UserAdjustUltraVivid(void);
#endif

#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserInterface.c
//----------------------------------------------------------------------------------------
#ifndef __USER_INTERFACE__
extern void UserInterfaceInitial(void);
extern void UserInterfacePanelPowerAction(BYTE ucEvent);
extern void UserInterfaceAdjustColorProc(void);
extern void UserInterfaceOsdActiveProc(void);
extern void UserInterfaceOsdResetProc(void);
extern bit UserInterfaceOsdNoSupportCheck(void);
extern void UserInterfaceAdjustInputTiming(void);
extern bit UserInterfaceOsdGetLogoOn(void);

#if((_DIGITAL_PORT_SUPPORT == _ON) && (_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
extern void UserInterfaceNVRamRestoreHDCP(void);
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
extern BYTE UserInterfaceGetFactoryCommand_EXINT1(void);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern BYTE UserInterfaceDdcciHDMIFreesyncOpcode_EXINT1(void);
#endif

#endif

extern bit UserInterfaceGetActiveByPass(void);
extern void UserInterfaceKeyPadLedControl(BYTE ucKeyPadLed);

extern bit UserInterfaceCheckNVRamData(EnumADCCheckType enumType);

#if(_VGA_SUPPORT == _ON)
extern BYTE UserInterfaceCheckVGAModeSearch(BYTE ucModeIndex);
extern bit UserInterfaceLoadModeTableDefault(void);
extern bit UserInterfaceFirstAutoConfig(void);
extern void UserInterfaceAutoConfigPercentage(BYTE ucAutoPercentage);
#endif

#if(_AUDIO_SUPPORT == _ON)
extern bit UserInterfaceGetAudioMute(void);
extern WORD UserInterfaceGetAudioVolume(void);
extern bit UserInterfaceGetAudioSource(void);
extern void UserInterfaceAudioResetProc(void);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern EnumAudioDACOutput UserInterfaceGetAudioDACOutput(void);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)

extern bit UserInterfaceCheckCableReset(void);

#if(_ENERGY_STAR_SUPPORT == _ON)
extern BYTE UserInterfaceGetOSDBackightValue(void);
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
extern bit UserInterfaceJudgeRGBQuantizationLimitRange(void);
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
extern bit UserInterfaceJudgeYCCQuantizationFullRange(void);
#endif

#endif // End of #ifndef __USER_INTERFACE__

#endif//#if(_OSD_TYPE == _NONE_OSD)
