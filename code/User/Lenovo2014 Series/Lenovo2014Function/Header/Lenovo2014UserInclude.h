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
// ID Code      : UserInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "Lenovo2014UserModeTable.h"

#if(_OSD_TYPE == _LENOVO_2014_OSD)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Flash Item Length For Each Page
//--------------------------------------------------
#define _DATA_ITEM_LENGTH       16
#define _PAGE_INFO_LENGTH       16

//--------------------------------------------------
// Definitions of Flash Page Size
//--------------------------------------------------
#define _FLASH_PAGE_SIZE        4096

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
//DFM rev07 patch note 3 >>
#define _TPV_EDID_PAGE              (_SYSTEM_EEPROM_EMULATION_END_PAGE + 1)//page14

#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_PORT)) 
#define _DPEDID_PAGE			_TPV_EDID_PAGE//page14
#define _DPEDID_OFFSET			0
#define _DP2EDID_OFFSET			0x0100
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) 
#define _MHLEDID_PAGE			_TPV_EDID_PAGE//page14
#define _MHLEDID_OFFSET			0x0200
#define _MHL2EDID_OFFSET		0x0300
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)) 
#define _HDMIEDID_PAGE			_TPV_EDID_PAGE//page14
#define _HDMIEDID_OFFSET        0x0400
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)) 
#define _DVIEDID_PAGE			_TPV_EDID_PAGE//page14
#define _DVIEDID_OFFSET			0x0500
#endif
#if(_A0_INPUT_PORT_TYPE == _A0_VGA_PORT) 
#define _VGAEDID_PAGE			_TPV_EDID_PAGE//page14
#define _VGAEDID_OFFSET			0x0580
#endif
//DFM rev07 patch note 3 <<
#endif

//20121008 HDCP key write modify
#define _HDCP_PAGE				15


//--------------------------------------------------
// Definitions of Key Mask
//--------------------------------------------------
#define _POWER_KEY_MASK                             0x01
#define _MENU_KEY_MASK                              0x02
#define _RIGHT_KEY_MASK                             0x04
#define _LEFT_KEY_MASK                              0x08
#define _EXIT_KEY_MASK                              0x10
#define _SOURCE_KEY_MASK                            0x20
#define _MENU_LEFT_KEY_MASK                         0x40
//#define _KEY6_MASK                                  0x40
#define _KEY7_MASK                                  0x80
#define KEY_NONE                                    0x00

// add for xml and customer config
#define KEY_POWER                                   _POWER_KEY_MASK
#define KEY_MENU                                    _MENU_KEY_MASK
#define KEY_RIGHT                                   _RIGHT_KEY_MASK
#define KEY_LEFT                                    _LEFT_KEY_MASK
#define KEY_EXIT                                    _EXIT_KEY_MASK
#define KEY_DOWN                                    _SOURCE_KEY_MASK
#define KEY_UP                                      _MENU_LEFT_KEY_MASK

#define _POWER_RIGHT_KEY_MASK                       (_POWER_KEY_MASK | _RIGHT_KEY_MASK)
#define _POWER_MENU_KEY_MASK                        (_POWER_KEY_MASK | _MENU_KEY_MASK)
#define _POWER_LEFT_RIGHT_KEY_MASK                  (_POWER_KEY_MASK | _LEFT_KEY_MASK | _RIGHT_KEY_MASK)
#define _POWER_LEFT_KEY_MASK                        (_POWER_KEY_MASK | _LEFT_KEY_MASK )
//20120508 Abel Factory Mode OSD Modify
#if 0//((_PROJECT == _PRJ_L_E2224_AD_INL_M215HNE_L30) || (_PROJECT == _PRJ_L_E2224_AD_SAMSUNG_LTM215HP01) || (_PROJECT == _PRJ_L_E2054_A_LNT_LM195WX1_S2A1))
#define _POWER_MENU_LEFT_KEY_MASK                   (_POWER_KEY_MASK |_MENU_LEFT_KEY_MASK)
#else
#define _POWER_MENU_LEFT_KEY_MASK                   (_POWER_KEY_MASK |_MENU_KEY_MASK | _LEFT_KEY_MASK)
#endif
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_USER_DCR_FUNCTION == _ON)//Eli 20140909
extern BYTE g_ucPreDCRPWM;
#if(_DCR_PANEL_ON_OFF == _ON)
extern BYTE g_ucDCRBLOffPWM;
extern WORD g_usDCRBLOffCunt;
extern bit g_bDCRBLOffStart;
#endif
#endif

#if(_ENERGY_STAR_SUPPORT == _ON)
extern BYTE code tBRIGHTNESS_PWM[101];//lorimiao 20131218 for ES6.0 test 
#endif

//20141125 Abel
#if(_AUTO_POWER_DOWN == _ON)
extern DWORD g_usDisPlayCunt;
#endif

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
#if(_FACTORY_MODE_OWNER == _OWNER_TPV) //ada.chen 20150806
    _CHECK_OSD_DATA_LOAD,
    _CHECK_BRICON_DATA_LOAD,
    _CHECK_COLORTEMP_DATA_LOAD,    
#endif
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
    _FLASH_ITEMID_BRICON,
    _FLASH_ITEMID_COLORPROC0_7200,
    _FLASH_ITEMID_COLORPROC1_SRGB, 
    _FLASH_ITEMID_COLORPROC2_6500,
    _FLASH_ITEMID_COLORPROC3_9300,//10
    _FLASH_ITEMID_COLORPROC4_USER,
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
    _FLASH_ITEMID_COLORPROC5_LBL,//B
#endif    
    _FLASH_ITEMID_SIXCOLOR_DATA,
    _FLASH_ITEMID_PANEL_DATA,
    _FLASH_ITEMID_FACTORY_DATA,
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
	_FLASH_ITEMID_FACTORY_BASE_DATA,
#endif
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    _FLASH_ITEMID_EDID_SN_0,//F
    _FLASH_ITEMID_EDID_SN_1,//10
	_FLASH_ITEMID_EDID_CHECKSUM,//11
	_FLASH_ITEMID_TE_DATA_0,//12
	_FLASH_ITEMID_TE_DATA_1,//13
	_FLASH_ITEMID_TE_DATA_2,//15
	_FLASH_ITEMID_TE_DATA_3, //16
	_FLASH_ITEMID_TE_DATA_4, //17
	_FLASH_ITEMID_TE_DATA_5, //18
	_FLASH_ITEMID_DATA_BACKUP_FLAG,//0x19
#endif
    _FLASH_ITEMID_MODE_USER_DATA, //16
    _FLASH_ITEMID_MODE_USER_DATA_END =  _FLASH_ITEMID_MODE_USER_DATA + _MODE_SLOT_AMOUNT - 1//30
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
extern bit UserCheckAspectRatioFunction(void);
#endif

extern void UserAdjustContrast(BYTE ucContrast);
extern void UserAdjustBacklightPercent(BYTE ucValue);
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

#if((_DCC_FUNCTION == _ON) && (_ICM_SUPPORT == _ON))
void UserAdjustVividSetting(void);  
#endif //#if((_DCC_FUNCTION == _ON)&&(_ICM_SUPPORT == _ON))

#if(_AUDIO_SUPPORT == _ON)
extern void UserAdjustAudioMuteSwitch(void);

extern void UserAdjustAudioVolume(BYTE ucVolume);
extern WORD UserAdjustAudioVolumeMapping(BYTE ucVolume);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern void UserAdjustAudioSource(void);
#endif

#endif

#if(_OD_SUPPORT == _ON)
extern void UserAdjustODLoadLUT(void);
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
extern void UserAdjustUltraVivid(void);
#endif

#if(_3D_SUPPORT == _ON)
extern void UserAdjust3DMode(BYTE uc3DMode);//Eli Add
#endif

extern void OsdReset(void);//Eli Add
extern BYTE UserAdjustContrastChangeover(BYTE ucColor, BYTE ucValue);//Eli Add

#if(_USER_DCR_FUNCTION == _ON)//Eli 20140909
extern void UserAdjustDCRControl(bit bEn);
extern void UserAdjustDCRMeasure(void);
#endif

#if(_ENERGY_STAR_SUPPORT == _ON)//lorimiao 20131218 for ES6.0 test
extern void UserAdjustESBacklight(void);
#endif//#if(_ENERGY_STAR_SUPPORT == _ON)

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
#if(_OD_SUPPORT == _ON)
extern BYTE UserInterfaceGetODGainData(void);
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

#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)

