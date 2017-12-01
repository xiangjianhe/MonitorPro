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

#include "RTD2011UserModeTable.h"

#if(_OSD_TYPE == _REALTEK_2011_OSD)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Flash Item Length For Each Page
//--------------------------------------------------
#define _DATA_ITEM_LENGTH       16
#define _PAGE_INFO_LENGTH       16


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

typedef enum
{
    _FLASH_ITEMID_VGA_ADC_DATA = 0x0000, // 0
    _FLASH_ITEMID_YPBPR_ADC_DATA,
    _FLASH_ITEMID_SYSTEM_DATA,
    _FLASH_ITEMID_PANEL_INDEX,
    _FLASH_ITEMID_OSD_DATA_START,
    _FLASH_ITEMID_OSD_DATA_0 = _FLASH_ITEMID_OSD_DATA_START,
    _FLASH_ITEMID_OSD_DATA_1, // 5
    _FLASH_ITEMID_OSD_DATA_END = _FLASH_ITEMID_OSD_DATA_1,
    _FLASH_ITEMID_BRICON_SRC0_VGA,
    _FLASH_ITEMID_BRICON_SRC1_VIDEO,
    _FLASH_ITEMID_BRICON_SRC2_DVI,
    _FLASH_ITEMID_BRICON_SRC3_HDMI,
    _FLASH_ITEMID_BRICON_SRC4_DP, // 10
    _FLASH_ITEMID_COLORPROC0_9300,
    _FLASH_ITEMID_COLORPROC1_7500,
    _FLASH_ITEMID_COLORPROC2_6500,
    _FLASH_ITEMID_COLORPROC3_5800,
    _FLASH_ITEMID_COLORPROC4_SRGB, // 15
    _FLASH_ITEMID_COLORPROC5_USER,
    _FLASH_ITEMID_SIXCOLOR_DATA,
    _FLASH_ITEMID_PANEL_DATA,
    _FLASH_ITEMID_MODE_USER_DATA, // 19
    _FLASH_ITEMID_MODE_USER_DATA_END =  _FLASH_ITEMID_MODE_USER_DATA + _MODE_SLOT_AMOUNT - 1 // 34
} EnumFlashItemIDType;

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
extern void UserAdjustSelectAspectRatio(void);
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

#if(_GAMMA_FUNCTION == _ON)
extern void UserAdjustGamma(BYTE ucGamma);
#endif

#if(_PCM_FUNCTION == _ON)
extern void UserAdjustPCM(BYTE ucPCM);
#endif

#if(_ICM_SUPPORT == _ON)
extern void UserAdjustICM(BYTE ucColorEffect);
#endif

#if(_DCC_FUNCTION == _ON)
extern void UserAdjustDCC(BYTE ucColorEffect);
#endif // End of #if(_DCC_FUNCTION == _ON)

#if(_YPEAKING_SUPPORT == _ON)
extern void UserAdjustYpeaking(void);
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
extern void UserAdjustHighLightWindowEffectSpace(void);
extern void UserAdjustHLWinType(BYTE ucHLWinType);
extern void UserAdjustHLWinType5Move(void);
#endif

#if(_AUDIO_SUPPORT == _ON)
extern void UserAdjustAudioMuteSwitch(void);
extern void UserAdjustAudioVolume(BYTE ucVolume);
extern WORD UserAdjustAudioVolumeMapping(BYTE ucVolume);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern void UserAdjustAudioSource(void);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)

#if(_OD_SUPPORT == _ON)
extern void UserAdjustODLoadLUT(void);
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
extern void UserAdjustUltraVivid(void);
#endif
#endif // End of #ifndef __USER_ADJUST__

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

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
extern bit UserInterfaceFlashLoadItem(EnumFlashItemIDType enumItemID, BYTE* pucData, BYTE ucLength);
extern bit UserInterfaceFlashSaveItem(EnumFlashItemIDType enumItemID, BYTE* pucData, BYTE ucLength);
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
extern BYTE UserInterfaceGetFactoryCommand_EXINT1(void);

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
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
extern bit UserInterfaceGetAudioReadyToPlay(void);
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

#endif//#if(_OSD_TYPE == _REALTEK_2011_OSD)

