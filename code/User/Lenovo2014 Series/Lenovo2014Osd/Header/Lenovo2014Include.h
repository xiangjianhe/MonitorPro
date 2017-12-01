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
// ID Code      : RTDInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "Lenovo2014Project.h"
#include "Lenovo2014NVRamOsd.h"
#if (CVT_EN_ON_LINE_WRITE_EDID == ENABLE)
#include "CVTEFunctionWriteEdid.h"
#endif
								
#if(_OSD_TYPE == _LENOVO_2014_OSD)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// HDMI Freesync
//--------------------------------------------------
#define _DDCCI_OPCODE_VCP_HDMI_FREESYNC_SUPPORT     0xE6

//--------------------------------------------------
// Definitions of Contrast Range (Real Value)
//--------------------------------------------------
#define _CONTRAST_MAX                               100
#define _CONTRAST_MIN                               0
#define _CONTRAST_CENTER                            (((_CONTRAST_MAX - _CONTRAST_MIN) / 2) + _CONTRAST_MIN)

//--------------------------------------------------
// Definitions of Contrast Range (Real Value)
//--------------------------------------------------
#define BACKLIGHT_PERCENT_MAX                       100
#define BACKLIGHT_PERCENT_MIN                       0

//--------------------------------------------------
// Definitions of Backlight Range
//--------------------------------------------------
#ifndef _BACKLIGHT_MAX
#define _BACKLIGHT_MAX                              255
#endif
#ifndef _BACKLIGHT_MIN
#define _BACKLIGHT_MIN                              0
#endif
#ifndef _BACKLIGHT_CENTER
#define _BACKLIGHT_CENTER                           (((_BACKLIGHT_MAX - _BACKLIGHT_MIN) / 2) + _BACKLIGHT_MIN)
#endif
//--------------------------------------------------
// Definitions of Brightness Range
//--------------------------------------------------
#define _BRIGHTNESS_MAX                             255
#define _BRIGHTNESS_MIN                             0
#define _BRIGHTNESS_CENTER                          (((_BRIGHTNESS_MAX - _BRIGHTNESS_MIN) / 2) + _BRIGHTNESS_MIN)

//--------------------------------------------------
// Definitions of Contrast Range (Real Value)
//--------------------------------------------------
#define _COLORTEMP_USER_MAX                         128
#define _COLORTEMP_USER_MIN                         28
#define _COLORTEMP_USER_CENTER                      (((_COLORTEMP_USER_MAX - _COLORTEMP_USER_MIN) / 2) + _COLORTEMP_USER_MIN)

//--------------------------------------------------
// Brightness/Contrast Default Value
//--------------------------------------------------
#define _DEFAULT_CONTRAST_TEXT                      50
#define _DEFAULT_BACKLGHT_TEXT                      50

#define _DEFAULT_CONTRAST_WEB                       60
#define _DEFAULT_BACKLGHT_WEB                       70

#define _DEFAULT_CONTRAST_VIDEO                     65
#define _DEFAULT_BACKLGHT_VIDEO                     90

#define _DEFAULT_CONTRAST_SPLIT                     65
#define _DEFAULT_BACKLGHT_SPLIT                     90

//--------------------------------------------------
// Definitions of Sharpness Range
//--------------------------------------------------
#define _SHARPNESS_MAX                              4
#define _SHARPNESS_MIN                              0

//--------------------------------------------------
// Definitions of Phase Range
//--------------------------------------------------
#define _PHASE_MAX                                  63
#define _PHASE_MIN                                  0
#define _PHASE_MIN_CENTER                           (((_PHASE_MAX - _PHASE_MIN) / 2) + _PHASE_MIN)

//--------------------------------------------------
// Definitions of OD Gain Range
//--------------------------------------------------
#define _OD_GAIN_MAX                                127
#define _OD_GAIN_MIN                                0
#define _OD_GAIN_CENTER                             (((_OD_GAIN_MAX - _OD_GAIN_MIN) / 2) + _OD_GAIN_MIN) 

//==================================================================
//OSD OD Gain Default Value
//==================================================================
#ifndef _OD_STATUS_DEFAULT
#define _OD_STATUS_DEFAULT							_OSD_OD_DEF_VALUE//_OFF
#endif

#ifndef _OD_NORMAL_GAIN
#define _OD_NORMAL_GAIN							    _OD_GAIN_CENTER
#endif

//--------------------------------------------------
// Definitions of 3D EFFECT
//--------------------------------------------------
#define _3D_EFFECT_MAX                              3
#define _3D_EFFECT_MIN                              0

//--------------------------------------------------
// Definitions of Menu Time Range
//--------------------------------------------------
#define _OSD_TIMEOUT_ADJUST_MAX                     60
#define _OSD_TIMEOUT_ADJUST_MIN                     5

//--------------------------------------------------
// Definitions of Transparency Range
//--------------------------------------------------
#define _OSD_TRANSPARENCY_MAX                       7
#define _OSD_TRANSPARENCY_MIN                       0

//--------------------------------------------------
// Definitions of OSD H Position Range
//--------------------------------------------------
#define _OSD_H_POS_MAX                              200
#define _OSD_H_POS_MIN                              0
#define _OSD_H_POS_CENTER                           (_OSD_H_POS_MAX -_OSD_H_POS_MIN)/2

//--------------------------------------------------
// Definitions of OSD V Position Range
//--------------------------------------------------
#define _OSD_V_POS_MAX                              200
#define _OSD_V_POS_MIN                              0
#define _OSD_V_POS_CENTER                           (_OSD_V_POS_MAX -_OSD_V_POS_MIN)/2

//--------------------------------------------------
// Definitions of Hue Saturation Range
//--------------------------------------------------
//#define _SATURATION_MAX                             200
//#define _SATURATION_MIN                             0

//#define _HUE_MAX                                    227
//#define _HUE_MIN                                    27

#define _DEFAULT_HUE                                (((_HUE_MAX - _HUE_MIN) * 50)/100 + _HUE_MIN)
#define _DEFAULT_SATURATION                         ((_SATURATION_MAX + _SATURATION_MIN) / 2)

//--------------------------------------------------
// Macro of Key Scan Start Flag
//--------------------------------------------------
#define GET_KEYSCANSTART()                          ((bit)(g_stOsdInfo.ucOsdKeyControl & _BIT1))
#define SET_KEYSCANSTART()                          (g_stOsdInfo.ucOsdKeyControl |= _BIT1)
#define CLR_KEYSCANSTART()                          (g_stOsdInfo.ucOsdKeyControl &= ~_BIT1)

//--------------------------------------------------
// Macro of Key Scan Ready Flag
//--------------------------------------------------
#define GET_KEYSCANREADY()                          ((bit)(g_stOsdInfo.ucOsdKeyControl & _BIT0))
#define SET_KEYSCANREADY()                          (g_stOsdInfo.ucOsdKeyControl |= _BIT0)
#define CLR_KEYSCANREADY()                          (g_stOsdInfo.ucOsdKeyControl &= ~_BIT0)

//--------------------------------------------------
// Macro of Key Repeat Start
//--------------------------------------------------
#define GET_KEYREPEATSTART()                        (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT2)
#define SET_KEYREPEATSTART()                        (g_stOsdInfo.ucOsdKeyControl |= _BIT2)
#define CLR_KEYREPEATSTART()                        (g_stOsdInfo.ucOsdKeyControl &= ~_BIT2)

//--------------------------------------------------
// Macro of Key Repeat Function Enable
// If you want to use repeat function, please set this flag. If not, please clear it.
//--------------------------------------------------
#define GET_KEYREPEATENABLE()                       (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT3)
#define SET_KEYREPEATENABLE()                       (g_stOsdInfo.ucOsdKeyControl |= _BIT3)
#define CLR_KEYREPEATENABLE()                       (g_stOsdInfo.ucOsdKeyControl &= ~_BIT3)

//--------------------------------------------------
// Macro of Key Message
//--------------------------------------------------
#define GET_KEYMESSAGE()                            (g_stOsdInfo.ucOsdKeyMessage)
#define SET_KEYMESSAGE(x)                           (g_stOsdInfo.ucOsdKeyMessage = (x))

//--------------------------------------------------    
// Macro of OSD_LOCK_FLAG                      
//--------------------------------------------------
//INPUT OSD Flag(OSD INPUT Source 顯示依據)
#define GET_OSD_INPUT_FLAG()                        (g_stOsdInfo.ucOSDInputFlag)
#define SET_OSD_INPUT_FLAG(x)                       (g_stOsdInfo.ucOSDInputFlag = (x))

//--------------------------------------------------
// Macro of Previous Input Port
//--------------------------------------------------
#define GET_PREVIOUS_INPUT_PORT_STATUS()            (g_stOsdInfo.ucPreviousInputPort)
#define SET_PREVIOUS_INPUT_PORT(x)                  (g_stOsdInfo.ucPreviousInputPort = (x))

//--------------------------------------------------    
// Macro of Key_Relax_FLAG                      
//--------------------------------------------------
//Key 鬆開可動作Flag(避免重複執行按下及鬆開)
#define GET_Key_Relax_FLAG()                      (g_stOsdInfo.ucKeyRelaxFlag)
#define SET_Key_Relax_FLAG()                      (g_stOsdInfo.ucKeyRelaxFlag = _TRUE)
#define CLR_Key_Relax_FLAG()                      (g_stOsdInfo.ucKeyRelaxFlag = _FALSE)

//--------------------------------------------------    
// Macro of DVTotal_OverSpec_FLAG                      
//--------------------------------------------------
#define GET_DVTotal_OverSpec_FLAG()                (g_stOsdInfo.b1DVTotalOverSpec)
#define SET_DVTotal_OverSpec_FLAG()                (g_stOsdInfo.b1DVTotalOverSpec = _TRUE)
#define CLR_DVTotal_OverSpec_FLAG()                (g_stOsdInfo.b1DVTotalOverSpec = _FALSE)

#define GET_OSD_LBL_STATUS()                   		(g_stOsdInfo.b1OSDLBLStatus)
#define SET_OSD_LBL_STATUS(x)                  		(g_stOsdInfo.b1OSDLBLStatus = (x))

//--------------------------------------------------
// Definitions of Key Message
//--------------------------------------------------
#define _MENU_KEY_MESSAGE                           0
#define _LEFT_KEY_MESSAGE                           1
#define _RIGHT_KEY_MESSAGE                          2
#define _EXIT_KEY_MESSAGE                           3
#define _SOURCE_KEY_MESSAGE                         4
#define _MENU_LEFT_KEY_MESSAGE                      5
//#define _6_KEY_MESSAGE                              5
#define _7_KEY_MESSAGE                              6
#define _HOLD_KEY_MESSAGE                           7
#define _NONE_KEY_MESSAGE                           8

#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
#define _KEY_AMOUNT                                 6//5
#elif((_FACTORY_MODE_OWNER == _OWNER_FOXCONN)||(_FACTORY_MODE_OWNER == _OWNER_WISTRON))
#define _KEY_AMOUNT                                 4
#else
#define _KEY_AMOUNT                                 5
#endif

//--------------------------------------------------
// Definitions of Key Repeat Start Time (Unit in sec)
//--------------------------------------------------
#define _KEY_REPEAT_DEFAULT_TIME                    0.2  
#define _KEY_REPEAT_SLOW_TIME                       1.5

//--------------------------------------------------
// Definitions of 3D Effect
//--------------------------------------------------
enum OSDSelect3DEffectDef
{
    _3D_EFFECT_OFF = _OFF,
    _3D_EFFECT_WEAK,
    _3D_EFFECT_MEDIUM,
    _3D_EFFECT_STRONG,
    _3D_EFFECT_AMOUNT = _3D_EFFECT_STRONG,
};

//--------------------------------------------------
// Definitions of LED indicction
//--------------------------------------------------
typedef enum
{
    _LED_ALL_OFF = _LED_SYSTEM_END,          
    _LED_1_ON,   //Eli ???      
    _LED_2_ON,            
    _LED_3_ON,           
    _LED_1_FLASH_ON,           
	_LED_2_FLASH_ON, 			 
    _LED_1_FLASH_OFF,
    _LED_2_FLASH_OFF,
}EnumUserLedIndication;

//--------------------------------------------------
// Definitions of OSD Bar indicction
//--------------------------------------------------
typedef enum
{
    _Bar_0_100 = 0x00,          
    _Bar_5_60,             
}OsdBarType;

//--------------------------------------------------
// Definitions of Message OSD indicction
//--------------------------------------------------
enum OSDMessageTye
{
    _MSG_AUTO = 0,
    _MSG_LOCK_UNLOCK,  
    _MSG_DDCCI_ON_OFF,   
    _MSG_SLEEP,
    _MSG_NOCABLE,
    _MSG_OOR,

#if(_AUTO_POWER_DOWN == _ON)
    _MSG_AUTO_POWER_DOWN,
#endif
    _MSG_FLYING,
};

//--------------------------------------------------
// Definitions of OSD DP Select indicction
//--------------------------------------------------
typedef enum
{
    _DP_1_1 = 0x00,          
    _DP_1_2,             
}OsdDPType;

//--------------------------------------------------
// Definitions of Different OSD Map Type
//--------------------------------------------------
#define _OSD_MAP0                                   0
#define _OSD_MAP1                                   1
#define _OSD_MAP2                                   2
#define _OSD_MAP3                                   3
#define _OSD_MAP4                                   4
#define _OSD_MAP5                                   5
#define _OSD_LOGO_MAP                               6

//--------------------------------------------------
// Definitions of 1bit Font Select From
//--------------------------------------------------
#define _1BIT_FONT_0_255_WIDTH_12                   0x8C
#define _1BIT_FONT_0_255_WIDTH_6                    0x86
#define _1BIT_FONT_256_511_WIDTH_12                 0x2C

//--------------------------------------------------
// Macro of OSD
//--------------------------------------------------
#define FONTBYTE0(x)                                HIBYTE(0x1000 | (x)),LOBYTE(0x1000 | (x))
#define FONTBYTE1(x)                                HIBYTE(0x5000 | (x)),LOBYTE(0x5000 | (x))
#define FONTBYTE2(x)                                HIBYTE(0x9000 | (x)),LOBYTE(0x9000 | (x))
#define FONTALLBYTE(x)                              HIBYTE(0xD000 | (x)),LOBYTE(0xD000 | (x))
#define WINDOWBYTE0(x)                              HIBYTE(0x0000 | (x)),LOBYTE(0x0000 | (x))
#define WINDOWBYTE1(x)                              HIBYTE(0x4000 | (x)),LOBYTE(0x4000 | (x))
#define WINDOWBYTE2(x)                              HIBYTE(0x8000 | (x)),LOBYTE(0x8000 | (x))
#define WINDOWALLBYTE(x)                            HIBYTE(0xC000 | (x)),LOBYTE(0xC000 | (x))
#define FRAMEBYTE0(x)                               WINDOWBYTE0(x)
#define FRAMEBYTE1(x)                               WINDOWBYTE1(x)
#define FRAMEBYTE2(x)                               WINDOWBYTE2(x)
#define FRAMEALLBYTE(x)                             WINDOWALLBYTE(x)
#define WINNO(x)                                    (x)
#define ROW(x)                                      (x)
#define COL(x)                                      (x)
#define WIDTH(x)                                    (x)
#define HEIGHT(x)                                   (x)
#define LENGTH(x)                                   (x)
#define FGCOLOR(x)                                  (x)
#define BGCOLOR(x)                                  (x)
#define COLOR00(x)                                  (x)
#define COLOR01(x)                                  (x)
#define COLOR10(x)                                  (x)
#define COLOR11(x)                                  (x)
#define XSTART(x)                                   (x)
#define YSTART(x)                                   (x)
#define XEND(x)                                     (x)
#define YEND(x)                                     (x)
#define PIXELROW(x)                                 (x * 18)
#define PIXELCOL(x)                                 (x * 12)
#define CHAR(x)                                     (x)
#define PIXEL(x)                                    (x)

//--------------------------------------------------
// Definitions of Checking Max or Min Value Used by OsdDisplayDetOverRange()
//--------------------------------------------------
#define _DET_OVERRANGE_MAX                          (0)
#define _DET_OVERRANGE_MIN                          (1)

//--------------------------------------------------
// Definations of OSD Function
//--------------------------------------------------
#define _SPACE_                                     0xfc
#define _EXT_                                       0xfc
#define _REPEAT_                                    0xfd
#define _NEXT_                                      0xfe
#define _END_                                       0xff

#if 1//Robert Wang 20121210
//--------------------------------------------------
// Definations of Write Byte
//--------------------------------------------------
#define _WRITE_BYTE0                                0
#define _WRITE_BYTE1                                1
#define _WRITE_BYTE2                                2
#define _WRITE_BYTEALL                              3
#endif

//--------------------------------------------------
// MACRO for OSD Logo Status
//--------------------------------------------------
#define GET_OSD_LOGO_ON()                           (g_stOsdInfo.b1OsdLogo)
#define SET_OSD_LOGO_ON(x)                          (g_stOsdInfo.b1OsdLogo = (x))

//--------------------------------------------------
// MACRO for Power Saving Show Source
//--------------------------------------------------
#define GET_OSD_WAKE_UP_SWITCH_DDCCI_PORT()         (g_stOsdInfo.b1OsdWakeUpSwitchDdcciPort)
#define SET_OSD_WAKE_UP_SWITCH_DDCCI_PORT(x)        (g_stOsdInfo.b1OsdWakeUpSwitchDdcciPort = (x))

//--------------------------------------------------
// MACRO for Power Saving Show Source
//--------------------------------------------------
#define GET_OSD_SHOWING_SWITCH_DDCCI_PORT()         (g_stOsdInfo.b1OsdShowingSwitchDdcciPort)
#define SET_OSD_SHOWING_SWITCH_DDCCI_PORT(x)        (g_stOsdInfo.b1OsdShowingSwitchDdcciPort = (x))

//--------------------------------------------------
// MACRO for Power Saving Show Source
//--------------------------------------------------
#define GET_OSD_POWER_SAVING_SHOW_SOURCE()          (g_stOsdInfo.b1OsdWakeUpShowSource)
#define SET_OSD_POWER_SAVING_SHOW_SOURCE(x)         (g_stOsdInfo.b1OsdWakeUpShowSource = (x))

//--------------------------------------------------
// MACRO for Source Menu Status
//--------------------------------------------------
#define GET_OSD_DO_WORK_MENU_STATUS()               (g_stOsdInfo.b1OsdDoWorkMenuStatus)
#define SET_OSD_DO_WORK_MENU_STATUS(x)              (g_stOsdInfo.b1OsdDoWorkMenuStatus = (x))

//--------------------------------------------------
// MACRO for Source Menu Status
//--------------------------------------------------
//工廠OSD選項Flag
#define GET_OSD_IN_FACTORY_MENU_STATUS()            (g_stOsdInfo.b1OsdFactoryModeStatus)
#define SET_OSD_IN_FACTORY_MENU_STATUS(x)           (g_stOsdInfo.b1OsdFactoryModeStatus = (x))

//--------------------------------------------------
// MACRO for Source Menu Status
//--------------------------------------------------
#define GET_OSD_DO_ASPECT_RATIO()                   (g_stOsdInfo.b1OsdDoAspectRatio)
#define SET_OSD_DO_ASPECT_RATIO(x)                  (g_stOsdInfo.b1OsdDoAspectRatio = (x))

//--------------------------------------------------
// MACRO for Osd Status
//--------------------------------------------------
#define GET_OSD_COLOR_FORMAT()                      (g_stOsdInfo.ucOsdColorFormat)
#define SET_OSD_COLOR_FORMAT(x)                     (g_stOsdInfo.ucOsdColorFormat = (x))

#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
//--------------------------------------------------
// Macro for Energy Mode
//--------------------------------------------------
#define GET_ENERGY_MODE()							(g_stOsdInfo.b1EnergyMode)
#define SET_ENERGY_MODE(x)							(g_stOsdInfo.b1EnergyMode = (x))
#endif

//--------------------------------------------------
// MACRO for Osd Status
//--------------------------------------------------
#define GET_OSD_STATE()                             (g_stOsdInfo.ucOsdState)
#define SET_OSD_STATE(x)                            (g_stOsdInfo.ucOsdState = (x))

//--------------------------------------------------
// MACRO for Osd Evevt Message
//--------------------------------------------------
#define GET_OSD_EVENT_MESSAGE()                     (g_stOsdInfo.ucOsdEventMsg)
#define SET_OSD_EVENT_MESSAGE(x)                    (g_stOsdInfo.ucOsdEventMsg = (x))

//--------------------------------------------------
// MACRO for Six Color
//--------------------------------------------------
#define GET_OSD_SIX_COLOR()                         (g_stOsdInfo.ucOsdsixColor)
#define SET_OSD_SIX_COLOR(x)                        (g_stOsdInfo.ucOsdsixColor = (x))

//--------------------------------------------------
// MACRO for Six Color Hue
//--------------------------------------------------
#define GET_OSD_SIX_COLOR_HUE()                     (g_stOsdInfo.ucOsdSixColorHue)
#define SET_OSD_SIX_COLOR_HUE(x)                    (g_stOsdInfo.ucOsdSixColorHue = (x))

//--------------------------------------------------
// MACRO for Six Color Saturation
//--------------------------------------------------
#define GET_OSD_SIX_COLOR_SATURATION()              (g_stOsdInfo.ucOsdSixColorSaturation)
#define SET_OSD_SIX_COLOR_SATURATION(x)             (g_stOsdInfo.ucOsdSixColorSaturation = (x))

//==========================================================================================================
// Macro of Eeprom BriCon Data
//==========================================================================================================
//--------------------------------------------------
// MACRO for Contrast
//--------------------------------------------------
#define GET_OSD_CONTRAST()                          (g_stBriConData.ucContrast)
#define SET_OSD_CONTRAST(x)                         (g_stBriConData.ucContrast = (x))

//--------------------------------------------------
// MACRO for Contrast
//--------------------------------------------------
#define GET_OSD_BRIGHTNESS()                        (g_stBriConData.ucBrightness)
#define SET_OSD_BRIGHTNESS(x)                       (g_stBriConData.ucBrightness = (x))

//==========================================================================================================
// Macro of NVRam User Data
//==========================================================================================================
//--------------------------------------------------
// MACRO for Transparency
//--------------------------------------------------
#define GET_OSD_ROTATE_STATUS()                     (g_stOSDUserData.b1OsdRotate)
#define SET_OSD_ROTATE_STATUS(x)                    (g_stOSDUserData.b1OsdRotate = (x))

//--------------------------------------------------
// MACRO for Transparency
//--------------------------------------------------
#define GET_OSD_3DOSD_STATUS()                      (g_stOSDUserData.b1Osd3DOSD)
#define SET_OSD_3DOSD_STATUS(x)                     (g_stOSDUserData.b1Osd3DOSD = (x))

//--------------------------------------------------
// Macro of BackLight
//--------------------------------------------------
#define GET_OSD_BACKLIGHT()                         (g_stOSDUserData.ucBackLight)
#define SET_OSD_BACKLIGHT(x)                        (g_stOSDUserData.ucBackLight = (x))

//--------------------------------------------------
// Macro of Color Temperature
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE()                       (g_stOSDUserData.b4ColorTempType)
#define SET_COLOR_TEMP_TYPE(x)                      (g_stOSDUserData.b4ColorTempType = (x))

//--------------------------------------------------
// Macro of Preset Color Temperature BackUp
//--------------------------------------------------
//Save Preset Mode Color Type
#define GET_PRESET_COLOR_TEMP_BACKUP()				(g_stOSDUserData.b4PresetColorTempBackUp)
#define SET_PRESET_COLOR_TEMP_BACKUP(x)				(g_stOSDUserData.b4PresetColorTempBackUp = (x))

//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_R()                (g_stColorProcData.ucColorTempR)
#define SET_COLOR_TEMP_TYPE_USER_R(x)               (g_stColorProcData.ucColorTempR = (x))

//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_G()                (g_stColorProcData.ucColorTempG)
#define SET_COLOR_TEMP_TYPE_USER_G(x)               (g_stColorProcData.ucColorTempG = (x))
//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_B()                (g_stColorProcData.ucColorTempB)
#define SET_COLOR_TEMP_TYPE_USER_B(x)               (g_stColorProcData.ucColorTempB = (x))

#if(_ASPECT_RATIO_SUPPORT == _ON)
//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_ASPECT_RATIO_TYPE()                 (g_stOSDUserData.b3AspectRatio)
#define SET_OSD_ASPECT_RATIO_TYPE(x)                (g_stOSDUserData.b3AspectRatio = (x))
#endif

//--------------------------------------------------
// MACRO for VGA Color Format Status
//--------------------------------------------------
#define GET_VGA_COLOR_FORMAT_STATUS()               (g_stOSDUserData.b2VGARGBYUV)
#define SET_VGA_COLOR_FORMAT_STATUS(x)              (g_stOSDUserData.b2VGARGBYUV = (x))

//--------------------------------------------------
// MACRO for VGA Color Format Status
//--------------------------------------------------
#define GET_DVI_COLOR_FORMAT_STATUS()               (g_stOSDUserData.b2DVIRGBYUV)
#define SET_DVI_COLOR_FORMAT_STATUS(x)              (g_stOSDUserData.b2DVIRGBYUV = (x))

//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_DDCCI_STATUS()                      (g_stOSDUserData.b1DDCCIStatus)
#define SET_OSD_DDCCI_STATUS(x)                     (g_stOSDUserData.b1DDCCIStatus = (x))

//--------------------------------------------------
// MACRO for Ultra Vivid Status
//--------------------------------------------------
#define GET_OSD_ULTRA_VIVID_STATUS()                (g_stOSDUserData.b2UltraVividStatus)
#define SET_OSD_ULTRA_VIVID_STATUS(x)               (g_stOSDUserData.b2UltraVividStatus = (x))

//--------------------------------------------------
// MACRO for Sharpness
//--------------------------------------------------
#define GET_OSD_SHARPNESS()                         (g_stOSDUserData.b3Sharpness)
#define SET_OSD_SHARPNESS(x)                        (g_stOSDUserData.b3Sharpness = (x))

//--------------------------------------------------
// MACRO for Transparency
//--------------------------------------------------
//Eli Add 20110803
#define GET_OSD_TRANSPARENCY_STATUS()               (g_stOSDUserData.b3Transparency)
#define SET_OSD_TRANSPARENCY_STATUS(x)              (g_stOSDUserData.b3Transparency = (x))

//--------------------------------------------------
// MACRO for Language
//--------------------------------------------------
#define GET_OSD_LANGUAGE()                          (g_stOSDUserData.b4Language)
#define SET_OSD_LANGUAGE(x)                         (g_stOSDUserData.b4Language = (x))

//--------------------------------------------------
// MACRO for OsdTimeout
//--------------------------------------------------
#define GET_OSD_TIME_OUT()                          (g_stOSDUserData.ucOsdTimeout)
#define SET_OSD_TIME_OUT(x)                         (g_stOSDUserData.ucOsdTimeout = (x))

//--------------------------------------------------
// MACRO for OsdHPos
//--------------------------------------------------
#define GET_OSD_HPOS()                              (g_stOSDUserData.ucOsdHPos)
#define SET_OSD_HPOS(x)                             (g_stOSDUserData.ucOsdHPos = (x))

//--------------------------------------------------
// MACRO for OsdVPos
//--------------------------------------------------
#define GET_OSD_VPOS()                              (g_stOSDUserData.ucOsdVPos)
#define SET_OSD_VPOS(x)                             (g_stOSDUserData.ucOsdVPos = (x))

//--------------------------------------------------
// MACRO for OsdGamma
//--------------------------------------------------
#define GET_OSD_GAMMA()                             (g_stOSDUserData.b3Gamma)
#define SET_OSD_GAMMA(x)                            (g_stOSDUserData.b3Gamma = (x))

//--------------------------------------------------
// MACRO for BLU Status
//--------------------------------------------------
#define GET_OSD_LOW_BLUE_LIGHT_STATUS()             (g_stOSDUserData.b1LowBlueLightStatus)
#define SET_OSD_LOW_BLUE_LIGHT_STATUS(x)            (g_stOSDUserData.b1LowBlueLightStatus = (x))

//--------------------------------------------------
// MACRO for OD Status
//--------------------------------------------------
#define GET_OSD_OD_STATUS()                         (g_stOSDUserData.b2ODStatus)
#define SET_OSD_OD_STATUS(x)                        (g_stOSDUserData.b2ODStatus = (x))

//--------------------------------------------------
// MACRO for OD Gain
//--------------------------------------------------
#define GET_OSD_OD_GAIN()                           (g_stOSDUserData.ucODGain)
#define SET_OSD_OD_GAIN(x)                          (g_stOSDUserData.ucODGain = (x))

//--------------------------------------------------
// MACRO for Color Effect
//--------------------------------------------------
#define GET_OSD_COLOR_EFFECT()                      (g_stOSDUserData.b4ColorEffect)
#define SET_OSD_COLOR_EFFECT(x)                     (g_stOSDUserData.b4ColorEffect = (x))

//--------------------------------------------------
// MACRO for DCR Status
//--------------------------------------------------
#define GET_OSD_DCR_STATUS()                        (g_stOSDUserData.b1OsdDCRStatus)
#define SET_OSD_DCR_STATUS(x)                       (g_stOSDUserData.b1OsdDCRStatus = (x))


//--------------------------------------------------
// MACRO for Volume Mute
//--------------------------------------------------
#define GET_OSD_VOLUME_MUTE()                       (g_stOSDUserData.b1VolumeMute)
#define SET_OSD_VOLUME_MUTE(x)                      (g_stOSDUserData.b1VolumeMute = (x))

//--------------------------------------------------
// MACRO for Volume
//--------------------------------------------------
#define GET_OSD_VOLUME()                            (g_stOSDUserData.ucVolume)
#define SET_OSD_VOLUME(x)                           (g_stOSDUserData.ucVolume = (x))

//--------------------------------------------------
// MACRO for Audio Stand a long
//--------------------------------------------------
#define GET_OSD_AUDIO_STAND_ALONE()                 (g_stOSDUserData.b1AudioStandAloneStatus)
#define SET_OSD_AUDIO_STAND_ALONE(x)                (g_stOSDUserData.b1AudioStandAloneStatus = (x))

//--------------------------------------------------
// MACRO for Audio Source
//--------------------------------------------------
#define GET_OSD_AUDIO_SOURCE()                      (g_stOSDUserData.b1AudioSourceStatus)
#define SET_OSD_AUDIO_SOURCE(x)                      (g_stOSDUserData.b1AudioSourceStatus = (x))

//--------------------------------------------------
// MACRO for Hue
//--------------------------------------------------
#define GET_OSD_HUE()                               (g_stOSDUserData.ucHue)
#define SET_OSD_HUE(x)                              (g_stOSDUserData.ucHue = (x))

//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------
#define GET_OSD_SATURATION()                        (g_stOSDUserData.ucSaturation)
#define SET_OSD_SATURATION(x)                       (g_stOSDUserData.ucSaturation = (x))

#if(_OVERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_OVERSCAN_STATUS()                   (g_stOSDUserData.b1OverScan)
#define SET_OSD_OVERSCAN_STATUS(x)                  (g_stOSDUserData.b1OverScan = (x))
#endif

//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------
#define GET_OSD_HLWIN_TYPE()                        (g_stOSDUserData.ucHLWinType)
#define SET_OSD_HLWIN_TYPE(x)                       (g_stOSDUserData.ucHLWinType = (x))

//--------------------------------------------------
// MACRO for 3D Status
//--------------------------------------------------
//3D狀態Flag(3D or 2D to 3D or 2D三種狀態)
#define GET_OSD_3D_STATUS()                         (g_stOSDUserData.b23DStatus)
#define SET_OSD_3D_STATUS(x)                        (g_stOSDUserData.b23DStatus = (x))

//--------------------------------------------------
// MACRO for 3D LR Status
//--------------------------------------------------
//3D 左右眼Flag
#define GET_OSD_3D_LR_STATUS()                      (g_stOSDUserData.b13DLRStatus)
#define SET_OSD_3D_LR_STATUS(x)                     (g_stOSDUserData.b13DLRStatus = (x))

//--------------------------------------------------
// MACRO for 3D Format Status
//--------------------------------------------------
//3D格式Flag(SBS or TNB)
#define GET_OSD_3D_FORMAT_STATUS()                  (g_stOSDUserData.b23DFormatStatus)
#define SET_OSD_3D_FORMAT_STATUS(x)                 (g_stOSDUserData.b23DFormatStatus = (x))

//--------------------------------------------------
// MACRO for 3D EFFECT
//--------------------------------------------------
//3D效果Flag(景深)
#define GET_OSD_3D_EFFECT()                         (g_stOSDUserData.uc3DEffect)
#define SET_OSD_3D_EFFECT(x)                        (g_stOSDUserData.uc3DEffect = (x))

//--------------------------------------------------
// MACRO for 3D 3DTO2D
//--------------------------------------------------
//2D to 3D Flag(開啟關閉)
#define GET_OSD_3D_3DTO2D()                         (g_stOSDUserData.b13D3DTO2DStatus)
#define SET_OSD_3D_3DTO2D(x)                        (g_stOSDUserData.b13D3DTO2DStatus = (x))

//--------------------------------------------------
// MACRO for 3D Convergence
//--------------------------------------------------
//2D to 3D 收歛(OUTWARD or INWARD)
#define GET_OSD_3D_CONVERGENCE()                    (g_stOSDUserData.uc3DConvergence)
#define SET_OSD_3D_CONVERGENCE(x)                   (g_stOSDUserData.uc3DConvergence = (x))

//--------------------------------------------------
// MACRO for 3D Convergence Mode
//--------------------------------------------------
//2D to 3D收斂模式(Mode1~6)
#define GET_OSD_3D_CONVERGENCE_MODE()               (g_stOSDUserData.b33DConvergenceMode)
#define SET_OSD_3D_CONVERGENCE_MODE(x)              (g_stOSDUserData.b33DConvergenceMode = (x))

//--------------------------------------------------
// MACRO for PCM Status
//--------------------------------------------------
#define GET_OSD_PCM_STATUS()                        (g_stOSDUserData.b2PCMStatus)
#define SET_OSD_PCM_STATUS(x)                       (g_stOSDUserData.b2PCMStatus = (x))

//--------------------------------------------------
// MACRO for 3D Mode Status
//--------------------------------------------------
#define GET_3D_MODE_STATUS()                        (g_stOSDUserData.b33DModeStatus)
#define SET_3D_MODE_STATUS(x)                       (g_stOSDUserData.b33DModeStatus = (x))

//--------------------------------------------------
// MACRO for Novo Vision Status
//--------------------------------------------------
#define GET_NOVO_VISION_STATUS()                    (g_stOSDUserData.b3NovoVisionStatus)
#define SET_NOVO_VISION_STATUS(x)                   (g_stOSDUserData.b3NovoVisionStatus = (x))

//--------------------------------------------------
// MACRO for Novo Vision Status
//--------------------------------------------------
#define GET_OSD_BUTTON_REPEAT_STATUS()              (g_stOSDUserData.b2OsdButtonRepeatStatus)
#define SET_OSD_BUTTON_REPEAT_STATUS(x)             (g_stOSDUserData.b2OsdButtonRepeatStatus = (x))

//--------------------------------------------------
// MACRO for Keypad Buzzer Status
//--------------------------------------------------
#define GET_KEYPAD_BUZZER_MUTE_STATUS()             (g_stOSDUserData.b1KeypadBuzzerStatus)
#define SET_KEYPAD_BUZZER_MUTE_STATUS(x)            (g_stOSDUserData.b1KeypadBuzzerStatus = (x))

//--------------------------------------------------    
// Macro of OSD_LOCK_FLAG                      
//--------------------------------------------------
//lorimiao 20130729 for OSD lock issue
//OSD Lock Flag(OSD顯示Lock & ULock依據)
#define GET_OSD_LOCK_STATUS()                        (g_stOSDUserData.b1OSDLockFlag)
#define SET_OSD_LOCK_STATUS(x)                       (g_stOSDUserData.b1OSDLockFlag = (x))

//--------------------------------------------------
// MACRO for FactoryMode
//--------------------------------------------------
//lorimiao 20130806 for NovoVision spec
#define GET_FACTORY_RESET()               		   (g_stOSDUserData.b1FactoryReset)
#define SET_FACTORY_RESET(x)              		   (g_stOSDUserData.b1FactoryReset = (x))

//--------------------------------------------------
// MACRO for DP Select(1.1 or 1.2)
//--------------------------------------------------
#define GET_DP_TYPE()               	            (g_stOSDUserData.b1DPType)
#define SET_DP_TYPE(x)              		        (g_stOSDUserData.b1DPType = (x))

//--------------------------------------------------
// MACRO for Panel Time Min
//--------------------------------------------------
#define GET_PANEL_TIME_MIN()                        (g_stPanelTimeData.ucMin)
#define SET_PANEL_TIME_MIN(x)                       (g_stPanelTimeData.ucMin = (x))

//--------------------------------------------------
// MACRO for Panel Time Hour
//--------------------------------------------------
#define GET_PANEL_TIME_HOUR()                       (g_stPanelTimeData.usHour)
#define SET_PANEL_TIME_HOUR(x)                      (g_stPanelTimeData.usHour = (x))

//--------------------------------------------------
// MACRO for Factory Power Saving Case
//--------------------------------------------------
#define GET_FORCE_POW_SAV_STATUS()                  (g_bForcePowSavStatus)
#define SET_FORCE_POW_SAV_STATUS(x)                 (g_bForcePowSavStatus = (x))

//--------------------------------------------------
// MACRO for OSD FLYING
//--------------------------------------------------
#define _OSD_FLY_H_STEP                             200
#define _OSD_FLY_V_STEP                             200

#define GET_OSD_FLY_H_STATE()                       ((bit)(g_ucOsdFlyState & _BIT7))                    
#define SET_OSD_FLY_H_STATE()                       (g_ucOsdFlyState |= _BIT7)      // up
#define CLR_OSD_FLY_H_STATE()                       (g_ucOsdFlyState &= ~_BIT7)     // down

#define GET_OSD_FLY_V_STATE()                       ((bit)(g_ucOsdFlyState & _BIT6))                    
#define SET_OSD_FLY_V_STATE()                       (g_ucOsdFlyState |= _BIT6)      // right
#define CLR_OSD_FLY_V_STATE()                       (g_ucOsdFlyState &= ~_BIT6)     // left

//--------------------------------------------------
// MACRO for OSD BUTTON REPEAT
//--------------------------------------------------
#define _NORMAL                                     0
#define _CENTER                                     1
#define _START                                      0
#define _RUN                                        1

#if 1//Robert Wang 20130603
#define _OSD_BUTTON_REPEAT_OFF                      0
#define _OSD_BUTTON_REPEAT_DEFAULT                  1
#define _OSD_BUTTON_REPEAT_SLOW                     2
#endif

//--------------------------------------------------
// Definitions of OSD Window
//--------------------------------------------------
//=========== OSD Window Setting ======================//
//Blending type1:Only windows blending.
//Blending type2:All blending.
//Blending type3:Windows & Character background blending.
#define _WIN0                                       0
#define _WIN1                                       1
#define _WIN2                                       2
#define _WIN3                                       3
#define _WIN4                                       4
#define _WIN5                                       5
#define _WIN6                                       6
#define _WIN7                                       7
#define _WIN8                                       8 //Eli 20110622 add
#define _WIN9                                       9 //Eli 20110622 add
#define _WIN41                                      10
#define _WIN42                                      11
#define _WIN43                                      12
#define _WIN_ALL                                    0xFF

#define _WIN0_TRANS                                 (_BIT7 | 0)
#define _WIN1_TRANS                                 (_BIT7 | 1)
#define _WIN2_TRANS                                 (_BIT7 | 2)
#define _WIN3_TRANS                                 (_BIT7 | 3)
#define _WIN4_TRANS                                 (_BIT7 | 4)
#define _WIN5_TRANS                                 (_BIT7 | 5)
#define _WIN6_TRANS                                 (_BIT7 | 6)
#define _WIN7_TRANS                                 (_BIT7 | 7)

#define COLOR(fg,bg)                                (fg << 4 | bg)
#define COLOR0(x)                                   (x)
#define COLOR1(x)                                   (x)
#define COLOR2(x)                                   (x)
#define COLOR3(x)                                   (x)

#define X_START(x)                                  (x)
#define Y_START(x)                                  (x)
#define X_END(x)                                    (x)
#define Y_END(x)                                    (x)

#define _BORDER0_1_PIXEL                            0
#define _BORDER0_2_PIXEL                            1
#define _BORDER0_3_PIXEL                            2
#define _BORDER0_4_PIXEL                            3
#define _BORDER0_5_PIXEL                            4
#define _BORDER0_6_PIXEL                            5
#define _BORDER0_7_PIXEL                            6
#define _BORDER0_8_PIXEL                            7

#define _BORDER1_1_PIXEL                            0x00
#define _BORDER1_2_PIXEL                            0x08
#define _BORDER1_3_PIXEL                            0x10
#define _BORDER1_4_PIXEL                            0x18
#define _BORDER1_5_PIXEL                            0x20
#define _BORDER1_6_PIXEL                            0x28
#define _BORDER1_7_PIXEL                            0x30
#define _BORDER1_8_PIXEL                            0x38

#define _BLEND_DISABLE                              0
#define _BLEND_ENABLE                               0x80
#define _GRADIENT_DISABLE                           0
#define _GRADIENT_ENABLE                            0x40
#define _GRADIENT_DIRECTION_H                       0
#define _GRADIENT_DIRECTION_V                       0x20
#define _BORDER_DISABLE                             0
#define _BORDER_ENABLE                              0x10

#define _1_LEVEL_RER_GRADIENT                       0x20
#define _2_LEVEL_RER_GRADIENT                       0x40
#define _3_LEVEL_RER_GRADIENT                       0x60
#define _4_LEVEL_RER_GRADIENT                       0x80
#define _5_LEVEL_RER_GRADIENT                       0xA0
#define _6_LEVEL_RER_GRADIENT                       0xC0
#define _7_LEVEL_RER_GRADIENT                       0xE0
#define _8_LEVEL_RER_GRADIENT                       0x00

#define _R_GRADIENT_DEC                             0x00
#define _R_GRADIENT_INC                             0x80
#define _G_GRADIENT_DEC                             0x00
#define _G_GRADIENT_INC                             0x40
#define _B_GRADIENT_DEC                             0x00
#define _B_GRADIENT_INC                             0x20

#define _GRADIENT_LEVEL_1                           0
#define _GRADIENT_LEVEL_2                           0x08
#define _GRADIENT_LEVEL_3                           0x10
#define _GRADIENT_LEVEL_4                           0x18

#define _R_GRADIENT_ENABLE                          0x04
#define _R_GRADIENT_DISABLE                         0x00
#define _G_GRADIENT_ENABLE                          0x02
#define _G_GRADIENT_DISABLE                         0x00
#define _B_GRADIENT_ENABLE                          0x01
#define _B_GRADIENT_DISABLE                         0x00

#define _SHADOW_1                                   0x00
#define _SHADOW_2                                   0x02
#define _SHADOW_3                                   0x04
#define _SHADOW_4                                   0x06
#define _3D_BUTTON_1                                0x08
#define _3D_BUTTON_2                                0x0A

#define _BLENDING_DISABLE                           0x00
#define _BLENDING_TYPE1                             0x04
#define _BLENDING_TYPE2                             0x08
#define _BLENDING_TYPE3                             0x0c

#define _WIN0_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN0_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN0_FUNC_CONTROL                          (_BLEND_ENABLE | _GRADIENT_DISABLE | _GRADIENT_DIRECTION_H | _BORDER_DISABLE | _3D_BUTTON_1)
#define _WIN0_GRADIENT_CONTROL0                     (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_3 | _R_GRADIENT_INC | _G_GRADIENT_INC | _B_GRADIENT_INC)
#define _WIN0_GRADIENT_CONTROL1                     (_3_LEVEL_RER_GRADIENT)

#define _WIN0_ROTATE_BORDER_PIXEL                   (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN0_ROTATE_BORDER_COLOR                   ((_CP_BLACK << 4)  |_CP_BLACK)
#define _WIN0_ROTATE_FUNC_CONTROL                   (_BLEND_ENABLE | _GRADIENT_ENABLE | _GRADIENT_DIRECTION_V | _BORDER_ENABLE | _SHADOW_3)
#define _WIN0_ROTATE_GRADIENT_CONTROL0              (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_4 | _R_GRADIENT_DEC | _G_GRADIENT_DEC | _B_GRADIENT_DEC)
#define _WIN0_ROTATE_GRADIENT_CONTROL1              (_3_LEVEL_RER_GRADIENT)

#define _WIN1_BORDER_PIXEL                          (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN1_BORDER_COLOR                          ((_CP_FOCUS_FRAME << 4) | _CP_FOCUS_FRAME)
#define _WIN1_FUNC_CONTROL                          (_BLEND_ENABLE | _GRADIENT_DISABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN1_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN1_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN2_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN2_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN2_FUNC_CONTROL                          (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN2_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN2_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN3_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN3_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN3_FUNC_CONTROL                          (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN3_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN3_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN4_BORDER_PIXEL                          (_DISABLE)
#define _WIN4_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN4_FUNC_CONTROL                          (_BLEND_ENABLE)
#define _WIN4_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN4_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN41_BORDER_PIXEL                         (_DISABLE)
#define _WIN41_BORDER_COLOR                         ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN41_FUNC_CONTROL                         (_BLEND_ENABLE)
#define _WIN41_GRADIENT_CONTROL0                    (_DISABLE)
#define _WIN41_GRADIENT_CONTROL1                    (_DISABLE)

#define _WIN5_BORDER_PIXEL                          (_DISABLE)
#define _WIN5_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN5_FUNC_CONTROL                          (_BLEND_ENABLE)
#define _WIN5_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN5_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN6_BORDER_PIXEL                          (_DISABLE)
#define _WIN6_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN6_FUNC_CONTROL                          (_BLEND_ENABLE)
#define _WIN6_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN6_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN7_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN7_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN7_FUNC_CONTROL                          (_BLEND_ENABLE)
#define _WIN7_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN7_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN8_BORDER_PIXEL                          (_DISABLE)
#define _WIN8_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN8_FUNC_CONTROL                          (_BLEND_ENABLE)
#define _WIN8_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN8_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN9_BORDER_PIXEL                          (_DISABLE)
#define _WIN9_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN9_FUNC_CONTROL                          (_BLEND_ENABLE)
#define _WIN9_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN9_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN0_TRANS_BORDER_PIXEL                    (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN0_TRANS_BORDER_COLOR                    (_CP_YELLOW << 4)
#define _WIN0_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE)
#define _WIN0_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN0_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN1_TRANS_BORDER_PIXEL                    (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN1_TRANS_BORDER_COLOR                    (_CP_YELLOW << 4)
#define _WIN1_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE)
#define _WIN1_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN1_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN2_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN2_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN2_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN2_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN2_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN3_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN3_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN3_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN3_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN3_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN4_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN4_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN4_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN4_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN4_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN5_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN5_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN5_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN5_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN5_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN6_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN6_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN6_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN6_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN6_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN7_TRANS_BORDER_PIXEL                    (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN7_TRANS_BORDER_COLOR                    (_CP_YELLOW << 4)   
#define _WIN7_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE)
#define _WIN7_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN7_TRANS_GRADIENT_CONTROL1               (_DISABLE)

//void OsdDisplayDrawWindow(BYTE ucIndex, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor, BYTE ucBorderPixel, BYTE ucBorderColor, BYTE ucWinFuncControl, BYTE ucGradientCon0, BYTE ucGradientCon1)
#define _ROTATE_WINDOW_OFFSET                       7

//void OsdDisplaySetPosition(BYTE ucType, WORD usX, WORD usY)
#define _MAIN_WINDOW_SIZE_X                         (_WIN_7_X_END - _WIN_7_X_START)
#define _MAIN_WINDOW_SIZE_Y                         (_WIN_0_Y_END - _WIN_0_Y_START)

#define _INPUT_SOURCE_SIZE_X                        (120)
#define _INPUT_SOURCE_SIZE_Y                        (54)

#define _MESSAGE_WINDOW_SIZE_X                      (_X_MSG_END - _X_MSG_START) //240
#define _MESSAGE_WINDOW_SIZE_Y                      (_Y_MSG_END - _Y_MSG_START) //182

#define _LOGO_WINDOW_SIZE_X                         840
#define _LOGO_WINDOW_SIZE_Y                         176

#define _LOW_BLUE_LIGHT_SIZE_X                     (168)//(48)
#define _LOW_BLUE_LIGHT_SIZE_Y                     (90)//(54)

//---------------------------------------------------------------------
// Definitions of OSD Show Number Function Used by OsdDisplayShowNumber()
//---------------------------------------------------------------------
#define _ALIGN_LEFT                                 (0)
#define _ALIGN_RIGHT                                (1)

#define _FORCE_SHOW_NUMBER_OFF                      (0 << 1)
#define _FORCE_SHOW_NUMBER_ON                       (1 << 1)

#define _SHOW_1                                     (0 << 4)
#define _SHOW_2                                     (1 << 4)
#define _SHOW_3                                     (2 << 4)
#define _SHOW_4                                     (3 << 4)
#define _SHOW_5                                     (4 << 4)
#define _SHOW_6                                     (5 << 4)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#define _OSD_WF_BYTE0                               (_OSD_WF_CONTROL | _OSD_BYTE0)
#define _OSD_WF_BYTE1                               (_OSD_WF_CONTROL | _OSD_BYTE1)
#define _OSD_WF_BYTE2                               (_OSD_WF_CONTROL | _OSD_BYTE2)
#define _OSD_WF_BYTEALL                             (_OSD_WF_CONTROL | _OSD_BYTEALL | _OSD_WITHOUT_DB)
#define _OSD_WF_BYTEALL_WITH_DB                     (_OSD_WF_CONTROL | _OSD_BYTEALL | _OSD_WITH_DB)

#define _OSD_SRAM_BYTE0                             (_OSD_SRAM | _OSD_BYTE0)
#define _OSD_SRAM_BYTE1                             (_OSD_SRAM | _OSD_BYTE1)
#define _OSD_SRAM_BYTE2                             (_OSD_SRAM | _OSD_BYTE2)
#define _OSD_SRAM_BYTEALL                           (_OSD_SRAM | _OSD_BYTEALL | _OSD_WITHOUT_DB)
#define _OSD_SRAM_BYTEALL_WITH_DB                   (_OSD_SRAM | _OSD_BYTEALL | _OSD_WITH_DB)


#define _PALETTE_INDEX0                             0   // 0 ~ 15
#define _PALETTE_INDEX1                             1   // 16 ~ 31
#define _PALETTE_INDEX2                             2   // 32 ~ 47
#define _PALETTE_INDEX3                             3   // 48 ~ 63

#define _POS_DIRECT                                 0
#define _POS_PERCENT                                1

// characeter command attribute
#define _AT_NORMAL                                  0x8C    // font select 0 ~ 255, palette 0~15, width 12
#define _AT_FS1                                     0x2c    // font select 256 ~ 511, palette 0~15, width 12

#define _OSD_ROW                                    30
#define _OSD_COL                                    28
#define _OSD_WINODW_MENU_WIDTH                      (_OSD_COL * 12)

#define _OSD_INPUT_SOURCE_HOTKEY_ROW                19
#define _OSD_INPUT_SOURCE_HOTKEY_COL                18
#define _OSD_INPUT_SOURCE_HOTKEY_WIDTH              (_OSD_INPUT_SOURCE_HOTKEY_COL * 12)

#define _OSD_MESSAGE_ROW                            10
#define _OSD_MESSAGE_COL                            20
#define _OSD_MESSAGE_WIDTH                          (_OSD_MESSAGE_COL * 12)

//--------------------------------------------------
// Definations of OSD Type
//--------------------------------------------------
#define _LOGO_OSD                                   0
#define _MAIN_OSD                                   1
#define _INPUT_SOURCE_OSD                           2
#define _MESSAGE_OSD                                3
#define _LOW_BLUE_LIGHT_OSD                         4

//--------------------------------------------------
// Definations of Novo Vision Contrast & Brightness
//--------------------------------------------------
#define _NOVO_VISION_TEXT_BRI                 _OSD_BRIGHTNESS_DEF_VALUE
#define _NOVO_VISION_TEXT_CON                 _OSD_CONTRAST_DEF_VALUE

#define _NOVO_VISION_WEB_BRI                  90
#define _NOVO_VISION_WEB_CON                  60

#define _NOVO_VISION_VIDEO_BRI                100
#define _NOVO_VISION_VIDEO_CON                65

#define _NOVO_VISION_SPLIT_BRI                100
#define _NOVO_VISION_SPLIT_CON                65

//--------------------------------------------------
// Definations of HL window Border Size
//--------------------------------------------------
#define _HL_WIN_BORDER_SIZE                         0

//--------------------------------------------------
// Define OSD SOURCE PORT
//--------------------------------------------------
enum OSDSourcePortType
{
    _OSD_SOURCE_PORT_VGA,
    _OSD_SOURCE_PORT_DVI,
    _OSD_SOURCE_PORT_HDMI,
    _OSD_SOURCE_PORT_DP,
};

//--------------------------------------------------
// Define Gamma
//--------------------------------------------------
enum GammaType
{
    _GAMMA_18,
    _GAMMA_20,
    _GAMMA_22,
    _GAMMA_24,
    _GAMMA_OFF,
    _GAMMA_AMOUNT = _GAMMA_OFF,
};

//--------------------------------------------------
// Define HL Window Type
//--------------------------------------------------
enum HLWinType
{
    _HL_WIN_OFF,
    _HL_WIN_1,
    _HL_WIN_2,
    _HL_WIN_3,
    _HL_WIN_4,
    _HL_WIN_5,
    _HL_WIN_AMOUNT = _HL_WIN_5,
};

//--------------------------------------------------
// Define Color Effect
//--------------------------------------------------
enum ColorEffectType      
{
    _COLOREFFECT_GAME,
    _COLOREFFECT_MOVIE,
    _COLOREFFECT_PHOTO,
    _COLOREFFECT_VIVID,
    _COLOREFFECT_USER,
    _COLOREFFECT_STANDARD,
    _COLOREFFECT_AMOUNT = _COLOREFFECT_STANDARD,
};

//--------------------------------------------------
// Define Color Effect Six Color
//--------------------------------------------------
enum SixColorType      
{
    _SIXCOLOR_R,
    _SIXCOLOR_Y,
    _SIXCOLOR_G,
    _SIXCOLOR_C,
    _SIXCOLOR_B,
    _SIXCOLOR_M,
    _SIXCOLOR_AMOUNT = _SIXCOLOR_M,
};

//--------------------------------------------------
// Define Ultra Vivid
//--------------------------------------------------
enum UltraVividType
{
    _ULTRA_VIVID_L,
    _ULTRA_VIVID_M,
    _ULTRA_VIVID_H,
    _ULTRA_VIVID_OFF,
    _ULTRA_VIVID_AMOUNT = _ULTRA_VIVID_OFF,
};


//--------------------------------------------------
// Define Supported Aspect Ratios
//--------------------------------------------------
enum AspectRatioType
{
    _ASPECT_RATIO_FULL,
    _ASPECT_RATIO_16_BY_9,
    _ASPECT_RATIO_4_BY_3,
    _ASPECT_RATIO_5_BY_4,
    _ASPECT_RATIO_OFF,      // input timing ratio
    _ASPECT_RATIO_ORIGIN,
    _ASPECT_RATIO_AMOUNT = _ASPECT_RATIO_ORIGIN,
};

//--------------------------------------------------
// Definitions of PCMType
//--------------------------------------------------
enum PCMType
{
    _PCM_OSD_SRGB,
    _PCM_OSD_ADOBE_RGB,
    _PCM_OSD_NATIVE,
    _PCM_OSD_AMOUNT = _PCM_OSD_NATIVE,
};

typedef struct
{
    BYTE b1OsdLogo : 1;
    BYTE b1OsdWakeUpSwitchDdcciPort : 1;
    BYTE b1OsdShowingSwitchDdcciPort : 1;
    BYTE b1OsdWakeUpShowSource : 1;
    BYTE b1OsdDoWorkMenuStatus : 1;
    BYTE b1OsdFactoryModeStatus : 1;
    BYTE b1OsdDoAspectRatio : 1;
    BYTE ucOsdColorFormat : 2;
    BYTE ucOsdsixColor : 3;
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
	BYTE b1EnergyMode : 1;    		//Factory Energy on /off
#endif

    BYTE ucOsdState;
    BYTE ucOsdEventMsg;
    BYTE ucOsdKeyMessage;
    BYTE ucOsdKeyControl;
    BYTE ucOsdSixColorHue;
    BYTE ucOsdSixColorSaturation;
    BYTE ucOSDInputFlag :1;          
    BYTE ucKeyRelaxFlag :1;         //20120530 Abel Modify
    BYTE b1DVTotalOverSpec :1;      //20141217 Abel Modify
	BYTE b1OSDLBLStatus :1;         //20160918  Ada
    BYTE ucPreviousInputPort;       ///20160310 Ada

}StructOsdInfo;

enum OSDColorPaletteDef
{
    _CP_BG = 0,
    _CP_ITEM_UNSEL_BG,
    _CP_ITEM_SEL_BG,
    _CP_FOCUS_FRAME,
    _CP_ITEM_FOCUS_BG,
    _CP_Unused5,
    _CP_Unused6,
    _CP_Unused7,
    
    _CP_MENU_BG,
    _CP_Unused9,
    _CP_Unused10,
    _CP_Unused11,
    _CP_Unused12,
    _CP_BLACK,
    _CP_WHITE,
    _CP_YELLOW,

/*
    _CP_2BIT_FRONT8_BLANK = 16,
    _CP_2BIT_FRONT8_BLACK,
    _CP_2BIT_GRAY,
    _CP_2BIT_GRAY_2,
    _CP_2BIT_YELLOW,
    _CP_2BIT_YELLOW_1,
    _CP_2BIT_Unused1,
    _CP_2BIT_Unused2,
    
    _CP_2BIT_BEHIND8_BLANK,
    _CP_2BIT_BEHIND8_BLACK,
    _CP_2BIT_GRAY_5,
    _CP_2BIT_YELLOW_2,
    _CP_2BIT_YELLOW_3,
    _CP_2BIT_Unused3,
    _CP_2BIT_Unused4,
    _CP_2BIT_Unused5,
*/
};

#if((_LOGO_TYPE != _LENOVO_THINKVISION) && (_LOGO_TYPE != _LENOVO_THINKVISION_EPA) && (_LOGO_TYPE != _LENOVO_2015_EPA) && (_LOGO_TYPE != _LENOVO_2015))
enum OSDLOGOColorPaletteDef
{
#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)

    _CP_LOGO_IBM_BG = 0,
    _CP_LOGO_IBM_BLACK = 0,
    _CP_LOGO_IBM_NONE_1,   
    _CP_LOGO_IBM_NONE_2,   
    _CP_LOGO_IBM_GRAY_224,     
    _CP_LOGO_IBM_GRAY_79,  
    _CP_LOGO_IBM_RED_255,  
    _CP_LOGO_IBM_NONE_6,  
    _CP_LOGO_IBM_NONE_7,

    _CP_LOGO_IBM_NONE_8, 
    _CP_LOGO_IBM_NONE_9,   
    _CP_LOGO_IBM_EPA_BLUE,
    _CP_LOGO_IBM_WHITE,
    _CP_LOGO_IBM_NONE_12,
    _CP_LOGO_IBM_NONE_13,
    _CP_LOGO_IBM_NONE_14,
    _CP_LOGO_IBM_NONE_15,
    
#elif(_LOGO_TYPE == _LENOVO)

    _CP_LOGO_LENOVO_BG = 0,
    _CP_LOGO_LENOVO_BLACK = 0,
    _CP_LOGO_LENOVO_LOGO_BLUE2,
    _CP_LOGO_LENOVO_LOGO_BLUE1,
    _CP_LOGO_LENOVO_LOGO_BLUE3,
    _CP_LOGO_LENOVO_NONE_4,
    _CP_LOGO_LENOVO_NONE_5,
    _CP_LOGO_LENOVO_NONE_6,
    _CP_LOGO_LENOVO_NONE_7,
    
    _CP_LOGO_LENOVO_NONE_8,
    _CP_LOGO_LENOVO_NONE_9,
    _CP_LOGO_LENOVO_EPA_BLUE,
    _CP_LOGO_LENOVO_WHITE,	
    _CP_LOGO_LENOVO_NONE_12,
    _CP_LOGO_LENOVO_NONE_13,
    _CP_LOGO_LENOVO_NONE_14,
    _CP_LOGO_LENOVO_NONE_15,
    
#endif    
};
#endif
typedef enum
{
    _MENU_NONE,         //0

    //Level 1
    //Main Item
    _MAIN_BRI_CON_DCR,
    _MAIN_IMAGE_POSITION,
    _MAIN_IMAGE_SETUP,
    _MAIN_IMAGE_PROPERTIES,
    _MAIN_OPTIONS,
    _MAIN_FACTORY,
    _ADJ_FACTORY,

    //Level 2
    //Sub Item
    _SUB_BRI,
    _SUB_CON,
#if(_USER_DCR_FUNCTION == _ON)	    
    _SUB_DCR,
#endif

    _SUB_IMAGE_POS_H,
    _SUB_IMAGE_POS_V,

    _SUB_AUTO_SETUP,
    _SUB_MANUAL,

    _SUB_COLOR,
#if(_INPUT_PORT_MAX > 0x01)  
    _SUB_INPUT_SIGNAL,
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
    _SUB_SCALING,
#endif

#if(_OD_OSD_SUPPORT == _ON)
    _SUB_OVER_DRIVE,
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
    _SUB_LOW_BLUE_LIGHT,
#endif

    _SUB_INFORMATION,
#if(_LANGUAGE_TYPE != _1_LAN)
    _SUB_MENU_LANGUAGE,
#endif
    _SUB_MENU_POSITION,
    _SUB_FACTORY_DEFAULT,
    _SUB_ACCESSIBILITY,
#if (_DP_SUPPORT == _ON)
    _SUB_DP_SELECT,
#endif

    //Level 3
    _BAR_BRI,
    _BAR_CON,
    
#if(_USER_DCR_FUNCTION == _ON)	    
    _SUB_DCR_ON,
    _SUB_DCR_OFF,
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
    _SUB_LOW_BLUE_LIGHT_ON,
    _SUB_LOW_BLUE_LIGHT_OFF,
#endif

    _BAR_H_POSITION,
    _BAR_V_POSITION,

    _SUB_MANUAL_CLOCK,
    _SUB_MANUAL_PHASE,

    _SUB_COLOR_PRESET_MODE,  //33
    _SUB_COLOR_CUSTOM,       //34
#if(_INPUT_PORT_MAX == 0x02)  
    _SUB_INPUT_ANALOG,
	_SUB_INPUT_DIGITAL1,
	_SUB_INPUT_DIGITAL0,

#elif(_INPUT_PORT_MAX == 0x03)
    _SUB_INPUT_ANALOG,
    _SUB_INPUT_DIGITAL0,
    _SUB_INPUT_DIGITAL1,
#endif
#if(_ASPECT_RATIO_SUPPORT == _ON)
    _SUB_SCALING_FULL_SCREEN,
    _SUB_SCALING_ORIGINAL_AR,
#endif

#if(_OD_OSD_SUPPORT == _ON)
#if(_OD_MULTI_SELECT == _ON)
	_SUB_OD_OFF,
	_SUB_OD_NORMAL,
	_SUB_OD_EXTREME,
#else
	_SUB_OD_ON,
	_SUB_OD_OFF,
#endif
#endif

    _DISP_INFORMATION,
#if(_LANGUAGE_TYPE != _1_LAN)
    _SUB_LAN_ENGLISH,
    _SUB_LAN_FRENCH,
    _SUB_LAN_ITALIAN,
    _SUB_LAN_CHINESE_S,
    _SUB_LAN_SPANISH,
    _SUB_LAN_JAPAN,
    _SUB_LAN_GERMAN,
    _SUB_LAN_RUSSIAN,
#endif
    _SUB_POS_DEFAULT,
    _SUB_POS_CUSTOM,

    _SUB_FACTORY_CANCEL,
    _SUB_FACTORY_RESET,

    _SUB_ACCESS_RATE,
    _SUB_ACCESS_TIMEOUT,

#if (_DP_SUPPORT == _ON)
    _SUB_DP_SL_11,
    _SUB_DP_SL_12,
#endif

    //Level 4
    _BAR_CLOCK,
    _BAR_PHASE,

    _SUB_NEUTRAL,      //61
    _SUB_BLUISH,       //62
    _SUB_REDDISH,      //63
    _SUB_sRGB,         //64

    _SUB_CUSTOM_R,     //65 
    _SUB_CUSTOM_G,     //66
    _SUB_CUSTOM_B,     //67

    _SUB_POS_CUST_H,
    _SUB_POS_CUST_V,

    _SUB_REPEAT_OFF,
    _SUB_REPEAT_DEFAULT,
    _SUB_REPEAT_SLOW,

    _BAR_MENU_TIMEOUT,

    //Level 5
    _BAR_CUSTOM_R,    //74
    _BAR_CUSTOM_G,    //75
    _BAR_CUSTOM_B,    //76

    _BAR_POS_CUST_H,
    _BAR_POS_CUST_V,

     //HotKey
    _HOTKEY_MESSAGE_MENU,        //20120531 Abel 
    _HOTKEY_BAR_BRI,
    
    _MAIN_MENU_STATE_END,
};

typedef enum
{
// bank 0    
    _FONT1_GLOBAL = 0,
    _FONT1_BAR,
    _FONT1_BUTTON_ICON,

    _FONT1_INPUT_OSD_VGA,
    _FONT1_INPUT_OSD_DVI,//jason.cheng 20150207_1 modify DVI source icon
    _FONT1_INPUT_OSD_HDMI,
    _FONT1_INPUT_OSD_DP,
    _MESSAGE_FONT_GLOBAL,
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
    _FONT1_LOW_BLUE_LIGHT_ENABLE,
    _FONT1_LOW_BLUE_LIGHT_DISABLE,
#endif

// bank 2
    _FONTX_LOGO, 

};


/*
typedef enum
{
    _OSD_STRING_TITLE,
    _OSD_STRING_PICTURE_PAGE,
    _OSD_STRING_DISPLAY_PAGE,
    _OSD_STRING_COLOR_PAGE,
    _OSD_STRING_ADVANCE_PAGE,
    _OSD_STRING_INPUT_PAGE,
    _OSD_STRING_AUDIO_PAGE,
    _OSD_STRING_OTHER_PAGE,

    _OSD_STRING_GAMMA_SELECT,
    _OSD_STRING_COLOR_TEMPERATURE,
    _OSD_STRING_COLOR_MODE,
    _OSD_STRING_COLOR_DEMO_MODE,
    _OSD_STRING_COLOR_FORMAT,
    _OSD_STRING_ASPECT_RATIO,
    _OSD_STRING_OVER_DRIVE,
    _OSD_STRING_3D_ITEM,
    _OSD_STRING_AUDIO_SOURCE,
    _OSD_STRING_LANGUAGE,
    _OSD_STRING_COLOR_SIXCOLOR,
    _OSD_STRING_3D_LR_SELECT,
    _OSD_STRING_3D_FORMAT_SELECT,
    _OSD_STRING_3D_CONVERGENCE,
    _OSD_STRING_3D_CONVERGENCE_SELECT,

    _OSD_STRING_R_G_B,
    _OSD_STRING_SIX_COLOR_PAGE,
    _OSD_STRING_3D_PAGE,

    _OSD_STRING_ON_OFF,
    _OSD_STRING_FACTORY,
    _OSD_STRING_NO_SIGNAL,
    _OSD_STRING_NO_CABLE,
    _OSD_STRING_NO_SUPPORT,
    _OSD_STRING_AUTO_ADJUSTMENT,
    _OSD_STRING_INPUT_MESSAGE_TABLE,
    _OSD_STRING_AUTO_COLOR,
    _OSD_STRING_DDCCI,
    _OSD_STRING_GO_TO_POWER_SAVING_MODE,
    _OSD_STRING_HDCPENABLE,
    _OSD_STRING_NOW_RESOLUTION,

    _OSD_STRING_HFREQUENCY,
    _OSD_STRING_VFREQUENCY,
    _OSD_STRING_PIXELCLOCK,
    _OSD_STRING_SHOW_NUMBER,

};
*/


typedef enum
{
    _WIN_0,
    _WIN_1,
    _WIN_2,
    _WIN_3,
    _WIN_4,
    _WIN_41,
    _WIN_5,
    _WIN_6,
    _WIN_7,
    _WIN_8,
    _WIN_9,

    _WIN_0_TRANS,
    _WIN_1_TRANS,
    _WIN_2_TRANS,
    _WIN_3_TRANS,
    _WIN_4_TRANS,
    _WIN_5_TRANS,
    _WIN_6_TRANS,
    _WIN_7_TRANS,
};

typedef enum
{
    _PALETTE_0,
    _PALETTE_1,
    _PALETTE_2,
    _PALETTE_3,
    _PALETTE_LOGO,
    _PALETTE_INPUT,
    _PALETTE_LOW_BLUE_LIGHT,
};

enum OSDLanguageDef
{
#if 1
    _ENGLISH=0,
    _FRENCH,
    _ITALIAN,
    _CHINESE_S,
    _SPANISH,
    _JAPAN,
    _GERMAN,
    _RUSSIAN,
#else
    _ENGLISH = 0,
    _FRENCH,
    _GERMAN,
    _SPANISH,
    _CHINESE_T,
    _CHINESE_S,
    _JAPAN,
#endif
    _LANGUAGE_AMOUNT
};

enum OSDEvenMassage
{
    _OSDEVENT_NONE_MSG = 0,
    _OSDEVENT_SHOW_NOSIGNAL_MSG,
    _OSDEVENT_SHOW_NOCABLE_MSG,
    _OSDEVENT_SHOW_NOSUPPORT_MSG,
    _OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG,
    _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG,
    _OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG,    
    _OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG,
    _OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG,    
    _OSDEVENT_DO_AUTO_CONFIG_MSG,
    _OSDEVENT_ACTIVE_DO_ONE_TIME_MSG,
    _OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_ADCDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_COLORPROC_MSG,
    _OSDEVENT_SAVE_NVRAM_BRICON_MSG,
    _OSDEVENT_SAVE_NVRAM_FACTORYDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG,
};

//--------------------------------------------------
// Definitions of Color Temperature
//--------------------------------------------------
enum OSDColortemptureDef
{
//lorimiao 0723
    _CT_7200,   // Neutral        
    _CT_SRGB,   // srgb        
    _CT_6500,   // reddish
    _CT_9300,   // bluish
    _CT_USER,   // Custom RGB

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	_CTLOWBLUELIGHT,
#endif

    _CT_OFF,
    _CT_COLORTEMP_AMOUNT = _CT_OFF,
};

typedef enum //Eli Add
{
//    _3D_MODE_OFF = 0,
    _3D_MODE_AUTO = 0,    
    _3D_MODE_SBS,
    _3D_MODE_TNB,
    _2D_TO_3D_MODE1_OUTWARD,
    _2D_TO_3D_MODE4_OUTWARD,
};

typedef enum //Eli Add
{
    _2D_TO_3D_INWARD = 0,
    _2D_TO_3D_OUTWARD,
};

typedef enum //Eli Add
{
    _NOVO_VISION_TEXT = 0,    
    _NOVO_VISION_WEB,
    _NOVO_VISION_VIDEO,
    _NOVO_VISION_SPLIT,
};

typedef enum //Eli Add
{
    _REPEAT_RATE_OFF = 0,    
    _REPEAT_RATE_DEFAULT,
    _REPEAT_RATE_SLOW,
};

//20140912 Abel Modify
// Latin
typedef enum
{
//Address 0x00~0x0F 
    __1 = 0,          //空12
    __6,              //空6
    __5,              //空5
    _SLASH,           //"/"
    _COLON,           //":"
    _DOT,             //"."
    _AT_SIGN1,        //"@"
    _AT_SIGN2,
    _PARENT_OPEN,     //"("
    _PARENT_CLOSE,    //")"
    _COMMA,           //","         
    _LINE ,           //"-"
    _AT_SIGN,    
    _PERIOD,          //句號
    _COMMA_DUM,       //頓號
    _LITTLE_DOT,      //句號2
    
//Address 0x10~0x1F 
    _0_ = 0x10,
    _1_,
    _2_,
    _3_,
    _4_,
    _5_,
    _6_,
    _7_,
    _8_,
    _9_,
    _x_,      
    _K_,      
    _H_,      
    _z_,      
    _D_,
    _I_,

//Address 0x20~0x2F 
    _A_ = 0x20,
    _B_,
    _C_,
    _E_,
    _F_,
    _G_,
    _J_,
    _L_,
    _M_,
    _N_,
    _O_,
    _P_,
    _Q_,
    _R_,
    _S_,
    _T_,

//Address 0x30~0x3F 
    _U_,
    _V_,
    _W1_,
    _W2_,
    _X_,
    _Y_,
    _Z_,
    _a_,
    _b_,
    _c_,
    _d_,
    _e_,
    _f_,
    _g_,
    _h_,
    _i_,


//Address 0x40~0x4F 
    _j_,
    _k_,
    _l_,
    _m_,
    _n_,
    _o_,
    _p_,
    _q_,
    _r_,
    _s_,
    _t_,
    _u_,
    _v_,
    _w1_,
    _w2_,
    _y_,
       
//Address 0x50~0x5F 
    _SP_n_e_,   // SP mean special
    _SP_p_e_,
    _SP_p_u_,
    _SP_p_a_,
    _SP_up_dot_,
    _SP_A_a_,
    _SP_s_n_,
    _SP_p_o_,
    _SP_dd_u_,
    _SP_beta_,
    _SP_dd_a_,
    _SP_n_a_,
    _SP_dd_o_,
    _SP_p_i_,


//Address 0x60~0x6F 
   

//Address 0x70~0x7F 
   

//Address 0x80~0x8F 
   
    
//Address 0x90~0x9F     
   

//Address 0xA0~0xAF     
  
    
};

// CHT
typedef enum
{
//Address 0x20~0x2F 
    _CHT_00A = 0x20,
    _CHT_00B,
    _CHT_01A,
    _CHT_01B,
    _CHT_02A,
    _CHT_02B,
    _CHT_03A,
    _CHT_03B,
    _CHT_04A,
    _CHT_04B,
    _CHT_05A,
    _CHT_05B,
    _CHT_06A,
    _CHT_06B,
    _CHT_07A,
    _CHT_07B,

//Address 0x30~0x3F 
    _CHT_08A,
    _CHT_08B,
    _CHT_09A,
    _CHT_09B,
    _CHT_0A,        // 名
    _CHT_0BA,       // 版
    _CHT_0BB,              
    _CHT_0CA,       // 本 
    _CHT_0CB,        
    _CHT_0DA,       // 號
    _CHT_0DB,        
    _CHT_0EA,       // 調
    _CHT_0EB,              
    _CHT_0FA,       // 整 
    _CHT_0FB,        
    _CHT_10A,       // 屏

//Address 0x40~0x4F     
    _CHT_10B,     
    _CHT_11A,       // 幕
    _CHT_11B,    
    _CHT_12A,       // 体
    _CHT_12B,    
    _CHT_13A,       // 亮
    _CHT_13B,                
    _CHT_14A,       // 度 
    _CHT_14B,            
    _CHT_15A,       // 對 
    _CHT_15B,        
    _CHT_16A,       // 比
    _CHT_16B,              
    _CHT_17A,       // 圖 
    _CHT_17B,        
    _CHT_18A,       // 像

//Address 0x50~0x5F     
    _CHT_18B,     
    _CHT_19A,       // 水
    _CHT_19B,    
    _CHT_1AA,       // 平
    _CHT_1AB,    
    _CHT_1BA,       // 垂
    _CHT_1BB,                
    _CHT_1CA,       // 直 
    _CHT_1CB,            
    _CHT_1DA,       // 位 
    _CHT_1DB,        
    _CHT_1EA,       // 置
    _CHT_1EB,              
    _CHT_1FA,       // 優 
    _CHT_1FB,        
    _CHT_20A,       // 化

//Address 0x60~0x6F     
    _CHT_20B,     
    _CHT_21A,       // 屬
    _CHT_21B,    
    _CHT_22A,       // 性
    _CHT_22B,    
    _CHT_23A,       // 選
    _CHT_23B,                
    _CHT_24A,       // 項
    _CHT_24B,           
    _CHT_25,        // C  
    _CHT_26,        // R                  
    _CHT_27A,       // 工 
    _CHT_27B,        
    _CHT_28A,       // 廠
    _CHT_28B,
    _CHT_29A,       // 信

//Address 0x70~0x7F     
    _CHT_29B,     
    _CHT_2AA,       // 無
    _CHT_2AB,    
    _CHT_2BA,       // 輸     
    _CHT_2BB,    
    _CHT_2CA,       // 入
    _CHT_2CB,                
    _CHT_2DA,       // 線
    _CHT_2DB,                          
    _CHT_2EA,       // 連 
    _CHT_2EB,        
    _CHT_2FA,       // 接
    _CHT_2FB,
    _CHT_30A,       // 檢
    _CHT_30B,     
    _CHT_31A,       // 查
    
//Address 0x80~0x8F         
    _CHT_31B,    
    _CHT_32A,       // 超     
    _CHT_32B,    
    _CHT_33A,       // 出
    _CHT_33B,                
    _CHT_34A,       // 範
    _CHT_34B,                          
    _CHT_35A,       // 圍 
    _CHT_35B,        
    _CHT_36A,       // 菜
    _CHT_36B,
    _CHT_37A,       // 單
    _CHT_37B,
    _CHT_38A,       // 已
    _CHT_38B,
    _CHT_39A,       // 鎖

//Address 0x90~0x9F         
    _CHT_39B,    
    _CHT_3AA,       // 解     
    _CHT_3AB,    
    _CHT_3BA,       // 關
    _CHT_3BB,                
    _CHT_3CA,       // 開
    _CHT_3CB,                          
    _CHT_3DA,       // 為 
    _CHT_3DB,        
    _CHT_3EA,       // 設
    _CHT_3EB,
    _CHT_3FA,       // 定
    _CHT_3FB,
    _CHT_40,        // 自
    _CHT_41A,       // 動
    _CHT_41B,      

//Address 0xA0~0xAF               
    _CHT_42A,       // 中     
    _CHT_42B,    
    _CHT_43A,       // 請
    _CHT_43B,                
    _CHT_44A,       // 稍
    _CHT_44B,                          
    _CHT_45A,       // 等 
    _CHT_45B,        
    _CHT_46A,       // 即 
    _CHT_46B,        
    _CHT_47A,       // 將
    _CHT_47B,
    _CHT_48A,       // 閉
    _CHT_48B,
    _CHT_49A,       // 顯
    _CHT_49B,       

//Address 0xB0~0xBF
    _CHT_4AA,       // 示
    _CHT_4AB,       
    _CHT_4BA,       // 器
    _CHT_4BB,

#if((_PROJECT == _PRJ_L_T2254G_A_SEC_LTM220MT12) || (_PROJECT == _CVT_RL6230_PROJECT))
    _CHT_4CA,       //腴
    _CHT_4CB,
    _CHT_4DA,       //邿
    _CHT_4DB,
    _CHT_4EA,       //扞
    _CHT_4EB,
#endif

};

#define _CHT_00     _CHT_00A, _CHT_00B  // 確
#define _CHT_01     _CHT_01A, _CHT_01B  // 定
#define _CHT_02     _CHT_02A, _CHT_02B  // 退
#define _CHT_03     _CHT_03A, _CHT_03B  // 出
#define _CHT_04     _CHT_04A, _CHT_04B  // 取
#define _CHT_05     _CHT_05A, _CHT_05B  // 消
#define _CHT_06     _CHT_06A, _CHT_06B  // 模
#define _CHT_07     _CHT_07A, _CHT_07B  // 式
#define _CHT_08     _CHT_08A, _CHT_08B  // 機
#define _CHT_09     _CHT_09A, _CHT_09B  // 種
// _CHT_0A                              // 名
#define _CHT_0B     _CHT_0BA, _CHT_0BB  // 版
#define _CHT_0C     _CHT_0CA, _CHT_0CB  // 本
#define _CHT_0D     _CHT_0DA, _CHT_0DB  // 號
#define _CHT_0E     _CHT_0EA, _CHT_0EB  // 調                      
#define _CHT_0F     _CHT_0FA, _CHT_0FB  // 整      
#define _CHT_10     _CHT_10A, _CHT_10B  // 屏        
#define _CHT_11     _CHT_11A, _CHT_11B  // 幕       
#define _CHT_12     _CHT_12A, _CHT_12B  // 体            
#define _CHT_13     _CHT_13A, _CHT_13B  // 亮      
#define _CHT_14     _CHT_14A, _CHT_14B  // 度         
#define _CHT_15     _CHT_15A, _CHT_15B  // 對 
#define _CHT_16     _CHT_16A, _CHT_16B  // 比  
#define _CHT_17     _CHT_17A, _CHT_17B  // 圖     
#define _CHT_18     _CHT_18A, _CHT_18B  // 像         
#define _CHT_19     _CHT_19A, _CHT_19B  // 水
#define _CHT_1A     _CHT_1AA, _CHT_1AB  // 平        
#define _CHT_1B     _CHT_1BA, _CHT_1BB  // 垂
#define _CHT_1C     _CHT_1CA, _CHT_1CB  // 直                     
#define _CHT_1D     _CHT_1DA, _CHT_1DB  // 位  
#define _CHT_1E     _CHT_1EA, _CHT_1EB  // 置          
#define _CHT_1F     _CHT_1FA, _CHT_1FB  // 優                 
#define _CHT_20     _CHT_20A, _CHT_20B  // 化
#define _CHT_21     _CHT_21A, _CHT_21B  // 屬      
#define _CHT_22     _CHT_22A, _CHT_22B  // 性
#define _CHT_23     _CHT_23A, _CHT_23B  // 選
#define _CHT_24     _CHT_24A, _CHT_24B  // 項
//_CHT_25,         //C  
//_CHT_26,         //R               
#define _CHT_27     _CHT_27A, _CHT_27B  // 工
#define _CHT_28     _CHT_28A, _CHT_28B  // 廠
#define _CHT_29     _CHT_29A, _CHT_29B  // 信
#define _CHT_2A     _CHT_2AA, _CHT_2AB  // 無
#define _CHT_2B     _CHT_2BA, _CHT_2BB  // 輸   
#define _CHT_2C     _CHT_2CA, _CHT_2CB  // 入
#define _CHT_2D     _CHT_2DA, _CHT_2DB  // 線
#define _CHT_2E     _CHT_2EA, _CHT_2EB  // 連 
#define _CHT_2F     _CHT_2FA, _CHT_2FB  // 接
#define _CHT_30     _CHT_30A, _CHT_30B  // 檢
#define _CHT_31     _CHT_31A, _CHT_31B  // 查
#define _CHT_32     _CHT_32A, _CHT_32B  // 超   
#define _CHT_33     _CHT_33A, _CHT_33B  // 出
#define _CHT_34     _CHT_34A, _CHT_34B  // 範
#define _CHT_35     _CHT_35A, _CHT_35B  // 圍 
#define _CHT_36     _CHT_36A, _CHT_36B  // 菜
#define _CHT_37     _CHT_37A, _CHT_37B  // 單
#define _CHT_38     _CHT_38A, _CHT_38B  // 已
#define _CHT_39     _CHT_39A, _CHT_39B  // 鎖
#define _CHT_3A     _CHT_3AA, _CHT_3AB  // 解  
#define _CHT_3B     _CHT_3BA, _CHT_3BB  // 關
#define _CHT_3C     _CHT_3CA, _CHT_3CB  // 開
#define _CHT_3D     _CHT_3DA, _CHT_3DB  // 為 
#define _CHT_3E     _CHT_3EA, _CHT_3EB  // 設
#define _CHT_3F     _CHT_3FA, _CHT_3FB  // 定
//_CHT_40  自
#define _CHT_41     _CHT_41A, _CHT_41B  // 動
#define _CHT_42     _CHT_42A, _CHT_42B  // 中  
#define _CHT_43     _CHT_43A, _CHT_43B  // 請
#define _CHT_44     _CHT_44A, _CHT_44B  // 稍
#define _CHT_45     _CHT_45A, _CHT_45B  // 等 
#define _CHT_46     _CHT_46A, _CHT_46B  // 即           
#define _CHT_47     _CHT_47A, _CHT_47B  // 將
#define _CHT_48     _CHT_48A, _CHT_48B  // 閉
#define _CHT_49     _CHT_49A, _CHT_49B  // 顯   
#define _CHT_4A     _CHT_4AA, _CHT_4AB  // 示
#define _CHT_4B     _CHT_4BA, _CHT_4BB  // 器
#if((_PROJECT == _PRJ_L_T2254G_A_SEC_LTM220MT12) || (_PROJECT == _CVT_RL6230_PROJECT))
#define _CHT_4C     _CHT_4CA, _CHT_4CB  // 腴
#define _CHT_4D     _CHT_4DA, _CHT_4DB  // 腴
#define _CHT_4E     _CHT_4EA, _CHT_4EB  // 腴
#endif   




// JAP
typedef enum
{
//Address 0x20~0x2F 
    _JAP_020 = 0x20,
    _JAP_021,
    _JAP_022,
    _JAP_023,
    _JAP_024,    // 了
    _JAP_025,
    _JAP_026,
    _JAP_027,    
    _JAP_028,
    _JAP_029,
    _JAP_02A,
    _JAP_02B,
    _JAP_02C,
    _JAP_02D,
    _JAP_02E,
    _JAP_02F,   // 名

//Address 0x30~0x3F 
    _JAP_030,
    _JAP_031,
    _JAP_032,
    _JAP_033,
    _JAP_034,
    _JAP_035,
    _JAP_036,   //畫
    _JAP_037,    
    _JAP_038,   //面  
    _JAP_039,
    _JAP_03A,   //全
    _JAP_03B,
    _JAP_03C,   //體
    _JAP_03D,
    _JAP_03E,   //之
    _JAP_03F,    
   
//Address 0x40~0x4F 
    _JAP_040,   //輝  
    _JAP_041,
    _JAP_042,   //度
    _JAP_043,
    _JAP_044,
    _JAP_045,   //卜
    _JAP_046,
    _JAP_047,    
    _JAP_048,   //C   
    _JAP_049,   //R
    _JAP_04A,   //調
    _JAP_04B,
    _JAP_04C,   //整
    _JAP_04D,
    _JAP_04E,   //像 
    _JAP_04F,   

//Address 0x50~0x5F 
    _JAP_050,   //水  
    _JAP_051,
    _JAP_052,   //平
    _JAP_053,
    _JAP_054,   //垂
    _JAP_055,   
    _JAP_056,   //直
    _JAP_057,    
    _JAP_058,   //位   
    _JAP_059,   
    _JAP_05A,   //置
    _JAP_05B,
    _JAP_05C,   //自
    _JAP_05D,   //動
    _JAP_05E,    
    _JAP_05F,    

//Address 0x60~0x6F 
    _JAP_060,   //行  
    _JAP_061,
    _JAP_062,   
    _JAP_063,
    _JAP_064,   
    _JAP_065,   
    _JAP_066,   
    _JAP_067,    
    _JAP_068,      
    _JAP_069,   
    _JAP_06A,   //相
    _JAP_06B,   
    _JAP_06C,   
    _JAP_06D,   
    _JAP_06E,    
    _JAP_06F,    

//Address 0x70~0x7F 
    _JAP_070,     
    _JAP_071,
    _JAP_072,   
    _JAP_073,
    _JAP_074,   
    _JAP_075,   //工
    _JAP_076,   
    _JAP_077,   //場
    _JAP_078,      
    _JAP_079,   //省
    _JAP_07A,   
    _JAP_07B,   //電 
    _JAP_07C,   
    _JAP_07D,   //力 
    _JAP_07E,    
    _JAP_07F,   //ㄨ
    
//Address 0x80~0x8F 
    _JAP_080,   //二 
    _JAP_081,
    _JAP_082,   
    _JAP_083,
    _JAP_084,   
    _JAP_085,   
    _JAP_086,   
    _JAP_087,    
    _JAP_088,      
    _JAP_089,   
    _JAP_08A,    //解
    _JAP_08B,   
    _JAP_08C,    //除
    _JAP_08D,   
    _JAP_08E,    //接
    _JAP_08F,  

//Address 0x90~0x9F 
    _JAP_090,    //繞 
    _JAP_091,
    _JAP_092,   
    _JAP_093,
    _JAP_094,   
    _JAP_095,   
    _JAP_096,   
    _JAP_097,    
    _JAP_098,    //信  
    _JAP_099,   
    _JAP_09A,    //號
    _JAP_09B,   
    _JAP_09C,   
    _JAP_09D,   
    _JAP_09E,    
    _JAP_09F,   


//Address 0xA0~0xAF 
    _JAP_0A0,     
    _JAP_0A1,
    _JAP_0A2,   
    _JAP_0A3,
    _JAP_0A4,    //入
    _JAP_0A5,   
    _JAP_0A6,    //範 
    _JAP_0A7,    
    _JAP_0A8,    //圍 
    _JAP_0A9,   
    _JAP_0AA,    //外
    _JAP_0AB,   
    _JAP_0AC,    //非 
    _JAP_0AD,   
    _JAP_0AE,    //表
    _JAP_0AF,    

//Address 0xB0~0xBF 
    _JAP_0B0,    //示
    _JAP_0B1,
    _JAP_0B2,    //最
    _JAP_0B3,
    _JAP_0B4,    //適
    _JAP_0B5,   
    _JAP_0B6,    //化
    _JAP_0B7,    
    _JAP_0B8,    //待
    _JAP_0B9,   
    _JAP_0BA,   
    _JAP_0BB,   
    _JAP_0BC,   
    _JAP_0BD,   
    _JAP_0BE,    
    _JAP_0BF,    

//Address 0xC0~0xCF 
    _JAP_0C0,     
    _JAP_0C1,   //為
    _JAP_0C2,     
    _JAP_0C3,
    _JAP_0C4,   
    _JAP_0C5, 
    _JAP_0C6,   //夕     
    _JAP_0C7,    
    _JAP_0C8,      
    _JAP_0C9,  

    _JAP_0CA,   
    _JAP_0CB,   
    _JAP_0CC,   
    _JAP_0CD,   
    _JAP_0CE,    
    _JAP_0CF,     
};


// RUS
typedef enum
{
//Address 0x20~0x2F 
    _RUS_50 = 0x50,
    _RUS_51,
    _RUS_52,
    _RUS_53,
    _RUS_54,
    _RUS_55,
    _RUS_56,
    _RUS_57,
    _RUS_58,
    _RUS_59,
    _RUS_5A,
    _RUS_5B,
    _RUS_5C,
    _RUS_5D,
    _RUS_5E,
    _RUS_5F,
    
//Address 0x60~0x6F 
    _RUS_60,
    _RUS_61,
    _RUS_62,
    _RUS_63,
    _RUS_64,
    _RUS_65,
    _RUS_66,
    _RUS_67,
    _RUS_68,
    _RUS_69,
    _RUS_6A,
    _RUS_6B,
    _RUS_6C,
    _RUS_6D,
    _RUS_6E,
    _RUS_6F,
    
};

//--------------------------------------------------
// Definitions of ROW Command Setting
//--------------------------------------------------
// row command BYTE 0
// row start
#define _ROW_END        0
#define _ROW_START      _BIT7

// VBI
#define _VBI_DISABLE    0
#define _VBI_ENALBE     _BIT6

// 1bit font selection
#define _1BIT_0_511     0
#define _1BIT_512_1023  _BIT5

// 1 bit border shadow
#define _1BIT_BS_NONE       0
#define _1BIT_BS_BORDER     (1<<2)
#define _1BIT_BS_SHADOW_LT  (4<<2)
#define _1BIT_BS_SHADOW_LB  (5<<2)
#define _1BIT_BS_SHADOW_RT  (6<<2)
#define _1BIT_BS_SHADOW_RB  (7<<2)

// double size
#define _CHAR_WIDTH_NORMAL  0
#define _CHAR_WIDTH_DOUBLE  _BIT1
#define _CHAR_HEIGHT_NORMAL 0
#define _CHAR_HEIGHT_DOUBLE _BIT0

// row command BYTE 1
#define ROW_HEIGHT(x)       ((x-1)<<3)
#define COL_SPACE(x)        (x)

// row command BYTE 2
#define ROW_LENGTH(x)       (x)

#define ROWCOMMAND(B0_7, B0_6, B0_5, B0_4_2, B0_1, B0_0, B1_7_3, B1_2_0, B2_7_0)        B0_7|B0_6|B0_5|B0_4_2|B0_1|B0_0, B1_7_3|B1_2_0, B2_7_0

#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)

#define _1BIT_LOGO_START_ADDRESS                    0x00
#define _1BIT_LOG1_START_ADDRESS                    0x100    

#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))
//Logo 1440x900(一個區塊114字寬x25字高)
#define _OSD_LOGO_ROW_SIZE                          34
#define _OSD_LOGO_COL1_SIZE                         11    
#define _OSD_LOGO_COL2_SIZE                         72
#define _OSD_EPA_LOGO_COL_SIZE                      16
#define _1BIT_EPA_LOG_START_ADDRESS                 (_1BIT_LOG1_START_ADDRESS + 0x21)//0x21 _1BIT_LOG1 icon  
#define _1BIT_EPA_LOG_ICON_START                    0x21 

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))
//Logo 1440x900(一個區塊114字寬x25字高)
#define _OSD_LOGO_ROW_SIZE                          35
#define _OSD_LOGO_COL1_SIZE                         11    
#define _OSD_LOGO_COL2_SIZE                         74
#define _OSD_EPA_LOGO_COL_SIZE                      16
#define _1BIT_EPA_LOG_START_ADDRESS                 (_1BIT_LOG1_START_ADDRESS + 0x2f)//0x21 _1BIT_LOG1 icon  
#define _1BIT_EPA_LOG_ICON_START                    0x2f 

#elif((_PANEL_DH_WIDTH == 1280) && (_PANEL_DV_HEIGHT == 1024))
//Logo 1280x1024(兩個區塊)
#define _OSD_LOGO_ROW_SIZE                          32  
#define _OSD_LOGO_COL1_SIZE                         9    
#define _OSD_LOGO_COL2_SIZE                         64
#define _OSD_EPA_LOGO_COL_SIZE                      16
#define _1BIT_EPA_LOG_START_ADDRESS                 (_1BIT_LOG1_START_ADDRESS + 0x0c)//0x63 _1BIT_LOG1 icon  
#define _1BIT_EPA_LOG_ICON_START                    0x0c

#elif((_PANEL_DH_WIDTH == 1680) && (_PANEL_DV_HEIGHT == 1050))
//Logo 1680x1050(兩個區塊)
#define _OSD_LOGO_ROW_SIZE                           37  
#define _OSD_LOGO_COL1_SIZE                          12   
#define _OSD_LOGO_COL2_SIZE                          81
#define _OSD_EPA_LOGO_COL_SIZE                       17
#define _1BIT_EPA_LOG_START_ADDRESS                 (_1BIT_LOG1_START_ADDRESS + 0x63)//0x63 _1BIT_LOG1 icon  
#define _1BIT_EPA_LOG_ICON_START                    0x63

#elif((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
//Logo 1920x1080(兩個區塊13字寬x18字高 & 89字寬x14字高...共32字高)
#define _OSD_LOGO_ROW_SIZE                           41  
#define _OSD_LOGO_COL1_SIZE                          13    
#define _OSD_LOGO_COL2_SIZE                          89
#define _OSD_EPA_LOGO_COL_SIZE                       17
#define _1BIT_EPA_LOG_START_ADDRESS                 (_1BIT_LOG1_START_ADDRESS + 0x84)//0x63 _1BIT_LOG1 icon  
#define _1BIT_EPA_LOG_ICON_START                    0x84
#endif

#elif(_LOGO_TYPE == _LENOVO)

#define _2BIT_LOGO_START_ADDRESS                    0x00 
#define _1BIT_EPA_LOG_START_ADDRESS                 0x100 
#define _1BIT_EPA_LOG_ICON_START                    0x00

#if(_EPA_LOGO == _ON)
#define _OSD_LOGO_ROW_SIZE                          17
#else
#define _OSD_LOGO_ROW_SIZE                          5
#endif

#define _OSD_LOGO_COL_SIZE                          46    
#define _OSD_SPACE_LOGO_COL_SIZE                    1
#define _OSD_EPA_LOGO_COL_SIZE                      17

#elif(_LOGO_TYPE == _LENOVO_THINKVISION_EPA)

#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1920
#define _OSD_LOGOA_HEIGHT                           1080

#define _OSD_LOGO_2BIT_OFFSET                       177
#define _OSD_LOGO_FONT_BASE_ADDRESS                 1143

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              61

#elif((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1440
#define _OSD_LOGOA_HEIGHT                           900

#define _OSD_LOGO_2BIT_OFFSET                       150
#define _OSD_LOGO_FONT_BASE_ADDRESS                 837

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              51

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1608
#define _OSD_LOGOA_HEIGHT                           900

#define _OSD_LOGOB_WIDTH                            1608
#define _OSD_LOGOB_HEIGHT                           900

#define _OSD_LOGO_2BIT_OFFSET                       145
#define _OSD_LOGO_FONT_BASE_ADDRESS                 837

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              51


#elif((_PANEL_DH_WIDTH == 1280) && (_PANEL_DV_HEIGHT == 1024))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1272
#define _OSD_LOGOA_HEIGHT                           1008

#define _OSD_LOGO_2BIT_OFFSET                       111
#define _OSD_LOGO_FONT_BASE_ADDRESS                 711

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              57


#else
	#warning "check logo"	
#endif

#elif(_LOGO_TYPE == _LENOVO_THINKVISION)


#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1440
#define _OSD_LOGOA_HEIGHT                           900

#define _OSD_LOGO_2BIT_OFFSET                       140
#define _OSD_LOGO_FONT_BASE_ADDRESS                 783

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              51

#else
	#warning "check logo"	
#endif


#elif(_LOGO_TYPE == _LENOVO_2015)

#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1440
#define _OSD_LOGOA_HEIGHT                           900

#define _OSD_LOGO_2BIT_OFFSET                       100
#define _OSD_LOGO_FONT_BASE_ADDRESS                 648

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              51

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1596
#define _OSD_LOGOA_HEIGHT                           900

#define _OSD_LOGO_2BIT_OFFSET                       100
#define _OSD_LOGO_FONT_BASE_ADDRESS                 693

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              51

#else
	#warning "check logo"	
#endif

#elif(_LOGO_TYPE == _LENOVO_2015_EPA)

#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1440
#define _OSD_LOGOA_HEIGHT                           900

#define _OSD_LOGO_2BIT_OFFSET                       110
#define _OSD_LOGO_FONT_BASE_ADDRESS                 702

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              51

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1596
#define _OSD_LOGOA_HEIGHT                           900

#define _OSD_LOGO_2BIT_OFFSET                       110
#define _OSD_LOGO_FONT_BASE_ADDRESS                 738

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              51

#else
	#warning "check logo"	
#endif

#endif


//--------------------------------------------------
// Definitions of OSD
//--------------------------------------------------
#define _PFONT_PAGE_0                               0
#define _PFONT_PAGE_1                               1
#define _PFONT_PAGE_2                               2
#define _PFONT_PAGE_3                               3

#define _PFONT_PAGE_ITEM_0                          4
#define _PFONT_PAGE_ITEM_1                          5
#define _PFONT_PAGE_ITEM_2                          6
#define _PFONT_PAGE_ITEM_3                          7
#define _PFONT_PAGE_ITEM_4                          8
#define _PFONT_PAGE_ITEM_5                          9
#define _PFONT_PAGE_ITEM_6                          10
#define _PFONT_PAGE_NUMBER_0                        11
#define _PFONT_PAGE_NUMBER_1                        12
#define _PFONT_PAGE_NUMBER_2                        13

#define _OSD_PAGE_0_START                           0x2E    // message、information page
#define _OSD_PAGE_0_END                             0x88

#define _OSD_PAGE_1_START                           0x36//0x10    // main menu function description string
#define _OSD_PAGE_1_END                             0x63//0x3D

#define _OSD_PAGE_2_START                           32    // key button string
#define _OSD_PAGE_2_END                             46

#define _OSD_PAGE_3_START                           0x2F
#define _OSD_PAGE_3_END                             0xFF

#define _SUB_PAGE_ITEM_0                            (_OSD_PAGE_2_START)                 // key info sCANCEL / sEXIT
#define _SUB_PAGE_ITEM_0_END                        (_OSD_PAGE_2_START + 9)             
#define _SUB_PAGE_ITEM_1                            (_SUB_PAGE_ITEM_0_END)              // key info sOK
#define _SUB_PAGE_ITEM_1_END                        (_SUB_PAGE_ITEM_0_END + 5)
#define _SUB_PAGE_ITEM_2                            (_SUB_PAGE_ITEM_1_END)              
#define _SUB_PAGE_ITEM_2_END                        (_SUB_PAGE_ITEM_1_END + 23)
#define _SUB_PAGE_ITEM_3                            (_SUB_PAGE_ITEM_2_END)              
#define _SUB_PAGE_ITEM_3_END                        (_SUB_PAGE_ITEM_2_END + 17)
#define _SUB_PAGE_ITEM_4                            (_SUB_PAGE_ITEM_3_END)              
#define _SUB_PAGE_ITEM_4_END                        (_SUB_PAGE_ITEM_3_END + 13)
#define _SUB_PAGE_ITEM_5                            (_SUB_PAGE_ITEM_4_END)              
#define _SUB_PAGE_ITEM_5_END                        (_SUB_PAGE_ITEM_4_END + 10)
#define _SUB_PAGE_ITEM_6                            (_SUB_PAGE_ITEM_5_END)              
#define _SUB_PAGE_ITEM_6_END                        (_SUB_PAGE_ITEM_5_END + 10)
#define _SUB_PAGE_NUMBER_0                          (_SUB_PAGE_ITEM_6_END)              
#define _SUB_PAGE_NUMBER_0_END                      (_SUB_PAGE_ITEM_6_END + 3)          
#define _SUB_PAGE_NUMBER_1                          (_SUB_PAGE_NUMBER_0_END)            
#define _SUB_PAGE_NUMBER_1_END                      (_SUB_PAGE_NUMBER_0_END + 3)        
#define _SUB_PAGE_NUMBER_2                          (_SUB_PAGE_NUMBER_1_END)            
#define _SUB_PAGE_NUMBER_2_END                      (_SUB_PAGE_NUMBER_1_END + 3)   

//--------------------------------------------------
// Definitions of Item list
//--------------------------------------------------
//                                       
//===========   ===========   ===========
//=_ITEM_4_1=   =_ITEM_4_2=   =_ITEM_4_3=
//===========   ===========   ===========
//                                       
//===========   ===========   ===========
//=_ITEM_3_1=   =_ITEM_3_2=   =_ITEM_3_3=
//===========   ===========   ===========
//                                       
//===========   ===========   ===========
//=_ITEM_2_1=   =_ITEM_2_2=   =_ITEM_2_3=
//===========   ===========   ===========
//                                       
//===========   ===========   ===========
//=_ITEM_1_1=   =_ITEM_1_2=   =_ITEM_1_3=
//===========   ===========   ===========
                                 
#define _ITEM_5_1                                   13
#define _ITEM_5_2                                   14
#define _ITEM_5_3                                   15

// ITEM_3_X & ITEM_4_X used 1 bit Font 256-511
#define _ITEM_4_1                                   10
#define _ITEM_4_2                                   11
#define _ITEM_4_3                                   12

#define _ITEM_3_1                                   7
#define _ITEM_3_2                                   8
#define _ITEM_3_3                                   9

// ITEM_1_X & ITEM_2_X used 1 bit Font 0-255
#define _ITEM_2_1                                   3
#define _ITEM_2_2                                   4
#define _ITEM_2_3                                   5
#define _ITEM_2_4                                   6

#define _ITEM_1_1                                   0
#define _ITEM_1_2                                   1
#define _ITEM_1_3                                   2

#define _ICON_1_1                                   100
#define _ICON_1_2                                   101
#define _ICON_1_3                                   102
#define _ICON_1_4                                   103
#define _ICON_1_5                                   104
//--------------------------------------------------
// Definitions of OSD
//--------------------------------------------------
#define _ITEM_5_ROW                                 1
#define _ITEM_4_ROW                                 4
#define _ITEM_3_ROW                                 7
#define _ITEM_2_ROW                                 10
#define _ITEM_1_ROW                                 13

#define _ITEM_COL_1                                 2
#define _ITEM_COL_2                                 14
#define _ITEM_COL_3                                 26

#define _ICON_COL_1                                 2
#define _ICON_COL_2                                 9
#define _ICON_COL_3                                 16
#define _ICON_COL_4                                 24
#define _ICON_COL_5                                 31
#define _ITEM_UNSELECT                              0
#define _ITEM_SELECT                                1
#define _ITEM_FOCUS                                 2

#define _BAR_WIDTH                                  35
#define _BAR_HEIGHT                                 2

#define _ITEM_WIDTH                                 9
#define _ITEM_HEIGHT                                2
#define _ICON_WIDTH                                 4
#define _ICON_HEIGHT                                2

#define _DISPLAY_AREA_SWITCH_DELAYTIME              500

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#ifndef __RTD_DDCCI__
extern bit g_bForcePowSavStatus;
extern BYTE code tLANGUAGEDEFINE[];
#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)////lorimiao 20130806
extern BYTE xdata ucDDCPowerSavingTemp;
#endif
#endif

#ifndef __RTD_OSD__
extern StructOsdInfo g_stOsdInfo;
extern WORD g_usAdjustValue_1;
extern WORD g_usAdjustValue_2;
extern WORD g_usAdjustValue_3;
extern WORD g_usAdjustValue_4;
extern BYTE ucBurnInPattern;    //20120614 Abel Modify
#endif

#ifndef __RTD_OSDFUNC__
extern WORD xdata g_usFontSelectStart;
extern WORD xdata g_usFontTableStart;
extern BYTE xdata g_ucOsdWidth;
extern BYTE xdata g_ucOsdHeight;

#if 1   //alex.huang 20120111
extern BYTE xdata g_ucOsdMap;
#endif

/*
extern BYTE xdata g_ucOsdFlyH;
extern BYTE xdata g_ucOsdFlyV;
extern BYTE xdata g_ucOsdFlyState;
extern bit g_bStopOsdFlyH;
extern bit g_bStopOsdFlyV;
*/
extern BYTE g_ucFontPointer0;
extern BYTE g_ucFontPointer1;
extern BYTE g_ucFontPointer2;
extern BYTE g_ucFontPointer3;

#endif
//----------------------------------------------------------------------------------------
// Extern Tables from OsdFont.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDFONT__
#endif

//----------------------------------------------------------------------------------------
// Extern Tables from OsdTable.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDTABLE__
extern BYTE code tPALETTE_0[];
extern BYTE code tPALETTE_1[];
extern BYTE code tPALETTE_2[];
extern BYTE code tPALETTE_3[];
extern BYTE code tPALETTE_LOGO[];
extern BYTE code tPALETTE_INPUT[];
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
extern BYTE code tPALETTE_LOW_BLUE_LIGHT[];
#endif

extern BYTE code twOSD_WIN0[];
extern BYTE code twOSD_WIN1[];
extern BYTE code twOSD_WIN2[];
extern BYTE code twOSD_WIN3[];
extern BYTE code twOSD_WIN4[];
extern BYTE code twOSD_WIN41[];
extern BYTE code twOSD_WIN5[];
extern BYTE code twOSD_WIN6[];
extern BYTE code twOSD_WIN7[];
extern BYTE code twOSD_WIN8[];
extern BYTE code twOSD_WIN9[];

extern BYTE code twOSD_WIN0_TRANS[];
extern BYTE code twOSD_WIN1_TRANS[];
extern BYTE code twOSD_WIN2_TRANS[];
extern BYTE code twOSD_WIN3_TRANS[];
extern BYTE code twOSD_WIN4_TRANS[];
extern BYTE code twOSD_WIN5_TRANS[];
extern BYTE code twOSD_WIN6_TRANS[];
extern BYTE code twOSD_WIN7_TRANS[];

#if 1
extern BYTE code tOSD_CHARWIDTH_TABLE_GLOBLE[][2];
extern BYTE code tOSD_CHARWIDTH_TABLE_WEST[][2];
extern BYTE code tOSD_CHARWIDTH_TABLE_CHS[][2];
extern BYTE code tOSD_CHARWIDTH_TABLE_JAP[][2];
extern BYTE code tOSD_CHARWIDTH_TABLE_RUS[][2];

extern BYTE code tOSD_BUTTON_EXIT_ICON[];
extern BYTE code tOSD_BUTTON_LEFT_ICON[];
extern BYTE code tOSD_BUTTON_RIGHT_ICON[];
extern BYTE code tOSD_BUTTON_OK_ICON[];
extern BYTE code tOSD_BUTTON_POWER_ICON[];

//extern BYTE code tOSD_BAR_TABLE_U[];
//extern BYTE code tOSD_BAR_TABLE_D[];


//--------------------------------------------------
// Message Table
//--------------------------------------------------
extern BYTE code tOSD_POWER_SAVING_STR[];
extern BYTE code tOSD_NO_CONNECTION_STR[]; 
extern BYTE code tOSD_CHECK_CABLE_STR[];
extern BYTE code tOSD_INPUT_NOT_SUPPORT_STR_0[];
extern BYTE code tOSD_INPUT_NOT_SUPPORT_STR_1[];
extern BYTE code tOSD_OSD_LOCKED_STR[];
extern BYTE code tOSD_OSD_UNLOCKED_STR[];
extern BYTE code tOSD_AUTO_POWER_DOWN_STR[];
extern BYTE code tOSD_DDCCI_ENABLE_STR[];
extern BYTE code tOSD_DDCCI_DISABLE_STR[];
extern BYTE code tOSD_AUTOMATIC[];
extern BYTE code tOSD_PLEASE_WAIT[];
extern BYTE code tOSD_sMODE[]; 
#if((_PROJECT == _PRJ_L_T2254G_A_SEC_LTM220MT12) || (_PROJECT == _CVT_RL6230_PROJECT))  //腴邿扞
extern BYTE code tOSD_sMODE_NAME_LOW_RADIATION[]; 
#endif
extern BYTE code tOSD_sMODE_NAME[]; 
extern BYTE code tOSD_scMODE_NAME[];
extern BYTE code tOSD_sMICROCODE[];
extern BYTE code tOSD_scMICROCODE[];
extern BYTE code tOSD_sOK[];
extern BYTE code tOSD_sEXIT[];
extern BYTE code tOSD_sCANCEL[];
extern BYTE code tOSD_sDESCRIPTION_BRI_CON_DCR[];
extern BYTE code tOSD_sDESCRIPTION_IMAGE_POSITION[];
extern BYTE code tOSD_sDESCRIPTION_IMAGE_SETUP[];
extern BYTE code tOSD_sDESCRIPTION_IMAGE_PROPERTIES[];
extern BYTE code tOSD_sDESCRIPTION_OPTION[];
extern BYTE code tOSD_sDESCRIPTION_FACTORY[];
#endif

//extern BYTE code tOSD_ITEM_BRI_CON_DCR_0[];
/*
extern BYTE code tOSD_ITEM_BRI_CON_DCR_1[];
extern BYTE code tOSD_ITEM_IMAGE_POSITION[];
extern BYTE code tOSD_ITEM_IMAGE_SETUP[];
extern BYTE code tOSD_ITEM_IMAGE_PROPERTIES[];
extern BYTE code tOSD_ITEM_OPTIONS[];
extern BYTE code tOSD_ITEM_BRIGHTNESS[];
extern BYTE code tOSD_ITEM_CONTRAST[];
extern BYTE code tOSD_ITEM_DCR[];
extern BYTE code tOSD_ITEM_H_POSITION[];
extern BYTE code tOSD_ITEM_V_POSITION[];
extern BYTE code tOSD_ITEM_AUTO_SETUP[];
extern BYTE code tOSD_ITEM_MANUAL[];
extern BYTE code tOSD_ITEM_SCALING[];
extern BYTE code tOSD_ITEM_COLOR[];
extern BYTE code tOSD_ITEM_INPUT_SIGNAL[];
extern BYTE code tOSD_ITEM_FACTORY_DEFAULT[];
extern BYTE code tOSD_ITEM_ACCESSIBILITY[];
extern BYTE code tOSD_ITEM_INFORMATION[];
extern BYTE code tOSD_ITEM_MENU_LANGUAGE[];
extern BYTE code tOSD_ITEM_ON[];
extern BYTE code tOSD_ITEM_OFF[];
extern BYTE code tOSD_ITEM_CLOCK[];
extern BYTE code tOSD_ITEM_PHASE[];
extern BYTE code tOSD_ITEM_PRESET_MODE[];
extern BYTE code tOSD_ITEM_CUSTOM[];
extern BYTE code tOSD_ITEM_ANALOG[];
extern BYTE code tOSD_ITEM_DVI[];
extern BYTE code tOSD_ITEM_HDMI[];
extern BYTE code tOSD_ITEM_DISPLAY_PORT[];
extern BYTE code tOSD_ITEM_LAN_ENGLISH[];
extern BYTE code tOSD_ITEM_LAN_FRENCH[];
extern BYTE code tOSD_ITEM_LAN_ITALIAN[];
extern BYTE code tOSD_ITEM_LAN_CHINESE_S[];
extern BYTE code tOSD_ITEM_LAN_SPANISH[];
extern BYTE code tOSD_ITEM_LAN_JAPAN[];
extern BYTE code tOSD_ITEM_LAN_GERMAN[];
extern BYTE code tOSD_ITEM_LAN_RUSSIAN[];
extern BYTE code tOSD_ITEM_FACTORY_CANCEL[];
extern BYTE code tOSD_ITEM_FACTORY_RESET[];
extern BYTE code tOSD_ITEM_REPEAT_RATE[];
extern BYTE code tOSD_ITEM_MENU_TIMEOUT[];
extern BYTE code tOSD_ITEM_NEUTRAL[];
extern BYTE code tOSD_ITEM_sRGB[];
extern BYTE code tOSD_ITEM_REDDISH[];
extern BYTE code tOSD_ITEM_BLUISH[];
extern BYTE code tOSD_ITEM_CUSTOM_R[];
extern BYTE code tOSD_ITEM_CUSTOM_G[];
extern BYTE code tOSD_ITEM_CUSTOM_B[];
extern BYTE code tOSD_ITEM_REPEAT_DEFAULT[];
extern BYTE code tOSD_ITEM_REPEAT_SLOW[];
*/
#endif


//----------------------------------------------------------------------------------------
// Extern Tables from OsdACTIONFLOW.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDACTIONFLOW__
//extern code void (*OperationTable[][5])(void);
#endif

//----------------------------------------------------------------------------------------
// Extern Tables from Panel.h
//----------------------------------------------------------------------------------------
#ifndef __USER_PANEL__

#if(_OD_SUPPORT == _ON)
extern code BYTE *tOD_TABLE[];
#endif

#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
//----------------------------------------------------------------------------------------
// Extern functions from UserDdcci.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_DDCCI__
extern void UserDdcciHandler(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from RTDKey.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_KEY__
extern void RTDKeyInitial(void);//Eli modify
extern void TPVKeyIntoFactory(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from Osd.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSD__
extern void OsdTimeoutSaveData(void);
#endif


//----------------------------------------------------------------------------------------
// Extern functions from OsdFunc.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDFUNC__
extern void OsdFuncSetPosition(WORD usX, WORD usY);
extern void OsdFuncCloseWindow(BYTE ucIndex);
extern void OsdFuncDisableOsd(void);
extern void OsdFuncEnableOsd(void);
//extern void OsdFuncSet2BitIconOffset(BYTE ucOffset);
extern void OsdFuncOsdTransparency(BYTE ucTrans);
extern void OsdFuncOsdBlending(BYTE ucType);


#if 1   //alex.huang 20120111
extern void OsdFuncApplyMap(BYTE ucOsdMapType);
extern WORD OsdFuncCalcStartAddress(BYTE ucRow, BYTE ucCol);
extern void OsdFunc1bitColor(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucForegroundColor, BYTE ucBackgroundColor);
extern void OsdFuncBlank(BYTE ucRow,BYTE ucCol, BYTE ucPiexl,BYTE ucHeight,BYTE ucColor);
extern void OsdFunc1bitByte0(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucByte0);
extern void OsdFunc1bitChar(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucChar);
extern void OsdFunc1bitItemApplyChar(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucChar);
#endif

#endif


//----------------------------------------------------------------------------------------
// Extern functions from OsdDisplay.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDDISPLAY__
extern WORD Xpos,Ypos;//lorimiao 20130731 for MSG OSD Move
extern bit Xdirect,Ydirect;
extern BYTE ucLedFlashCount;

extern void OsdDispMainMenu(void);
#if(_INPUT_PORT_MAX >= 0x01)
extern BYTE OsdDisplayJudgeSourceType(void);
#endif
extern void OsdDisplayTimingAndInputSource(void);
extern void OsdDisplayNoSupportProc(void);
extern void OsdDisplayNoCableProc(void);
extern void OsdDisplayWakeUpShowSource();
extern void OsdDisplayOSDLockProc(void);
extern void OsdDisplayOSDDDCCIONOFFProc(void);
#if(_AUTO_POWER_DOWN == _ON)
extern void OsdDisplayOSDAutoPowerDown(void);
#endif
#if(_VGA_SUPPORT == _ON) 
extern void OsdDisplayAutoProc(void);
extern void OsdDisplayAutoBalanceProc(void);
#endif
extern BYTE OsdDispJudgeSourceType(void);
extern void OsdDisplayShowLogo(void);
extern void OsdDisplayOsdMessage(BYTE ucMessage);
extern void OsdDisplayWakeUpSwitchDdcciPort();
extern void OsdDisplayPowerSavingProc(void);
extern void OsdDisplaySetPosition(BYTE ucType, WORD usHPos, WORD usVPos);
extern void OsdDisplayDisableOsd(void);
extern WORD OsdDisplayDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle);
extern void OsdDisplayDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void OsdDisplayDispButton(BYTE ucState);
extern void OsdDisplayMainMenuDescription(BYTE ucState);
extern void OsdDispMessageFlying(void);
#if(_INPUT_PORT_MAX >= 0x01)
extern void OsdDispInputInfo(void);
#endif
extern void OsdDisplayItemDraw(BYTE ucItem, BYTE ucItemStatus, BYTE ucOsdState);
extern void OsdDisplayItemFrame(BYTE ucRow, BYTE ucCol, BYTE ucBgColor);
extern void OsdDisplayIconFrame(BYTE ucRow, BYTE ucCol, BYTE ucBgColor);
//extern void OsdDisplayItemString(BYTE ucRow, BYTE ucCol, BYTE ucOsdState, BYTE ucColor);
extern void OsdDisplayItemColor(BYTE ucRow, BYTE ucCol, BYTE ucFgColor, BYTE ucBgColor);
extern void OsdDisplayIconColor(BYTE ucRow, BYTE ucCol, BYTE ucFgColor, BYTE ucBgColor);
extern void OsdDisplayDrawFocusFrame(BYTE ucRow);
extern void OsdDisplayClearFocusFrame(BYTE ucRow);
extern void OsdDisplayDrawBar(BYTE ucRow, BYTE ucBarValue, BYTE ucBarType);
//extern void OsdDisplayClearBar(BYTE ucRow);
extern void OsdDisplayDrawInformation(void);
extern void OsdDispInformationPage(void);
extern bit OsdDisplayWaitForDrawing(void);

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_LBL_HOTKEY_FUNCTION == _ON))
extern void OsdDisplayLowBlueLightHotKeyMsg(void);
#endif

#endif

//----------------------------------------------------------------------------------------
// Extern functions from OsdAnimation.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSD_ANIMATION__
extern void OsdAnimationItemAnimation(BYTE ucOsdState);
#endif
extern void OsdAnimationItemAnimation1(BYTE ucOsdState);


//----------------------------------------------------------------------------------------
// Extern functions from OsdFont.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDFONT__
extern void OsdFontLoadFont(BYTE ucState);
extern void OsdFontLoadItem(BYTE ucState, WORD usOffset);
#endif

#ifndef __RTD_OSDFONTBANK__
extern void OsdFontLoadFontBank1(BYTE ucState);
extern void OsdFontLoadFontBank2(BYTE ucState);
extern void OsdFontLoadItemBank2(BYTE ucState, WORD usOffset);
extern void OsdFontLoadItemBank4(BYTE ucState, WORD usOffset);
extern void OsdFontLoadItemBank6(BYTE ucState, WORD usOffset);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from OsdTableFunc.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDTABLEFUNC__
extern void OsdTableFuncDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void OsdTableFuncSetColorPalette(BYTE ucPaletteIndex, BYTE ucColorPalette);
extern void OsdTableFuncLoadText(BYTE ucRow, BYTE ucCol, BYTE ucSelect, BYTE code *pArray, BYTE ucType);
extern void OsdTableFuncLoadIcon(BYTE ucRow, BYTE ucCol, BYTE code *pArray);
extern BYTE OsdFucnGetCharWidth(BYTE ucChar, BYTE ucFontTabSelect, BYTE ucLanguage);
extern WORD OsdFuncGetStringLength(BYTE *pArray, BYTE ucLanguage);
extern BYTE OsdFuncGetOsdFontPointer(BYTE ucPointerSelect);
extern BYTE OsdFuncSetOsdFontPointer(BYTE ucPointerSelect,BYTE ucPointer);
extern void OsdFuncPutStringPropCenter(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucFptsSelect, BYTE *pArray, BYTE ucLanguage, BYTE ucColor, BYTE ucFontSelect);
extern void OsdFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE *pArray, BYTE ucLanguage, BYTE ucColor, BYTE ucFontSelect);
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)//jason.cheng 20150116_1 update	
extern void OsdFuncASCIIConvert(BYTE *pArrayIn,BYTE *pArrayOut);//jason.cheng 20150116_1 Update //2015-01-15  By Jerry //
#endif
#endif

#define _LOGO_1Bit_START    0x01
#define _LOGO_2Bit_START    0x38 // 20110915 Lexie, B010 modify poweron LOGO 
#define _LOGO_4Bit_START    0x45 // 20110915 Lexie, B010 modify poweron LOGO

#define LOGO_1bit(x)     (_LOGO_1Bit_START + x)
#define LOGO_2bit(x)     (0x00 + x)
#define LOGO_4bit(x)     (_LOGO_4Bit_START + x)

#define GLOBAL(x)                       (_FONT1_GLOBLE_START + x)
#define EURO(x)                         (_FONT1_STR_START + x)
#define CHS(x)                          (_FONT1_STR_START + x)
#define JAP(x)                          (_FONT1_STR_START + x)
#define RUS(x)                          (_FONT1_STR_START + x)
#define RUS_T(x)                        (_FONT1_STR_START + x)

#define _BUTTON_ICON_ROW                17
#define _BUTTON_STR_ROW                 19

#define _ICON_TYPE                0
#define _TEXT_TYPE                1

#define _WIN_0_X_START          0
#define _WIN_0_X_END            454
#define _WIN_0_Y_START          0
#define _WIN_0_Y_END            323

#define _WIN_7_X_START          10
#define _WIN_7_X_END            454
#define _WIN_7_Y_START          179
#define _WIN_7_Y_END            323

#define _WIN_8_X_START          164
#define _WIN_8_X_END            167
#define _WIN_8_Y_START          1
#define _WIN_8_Y_END            2

#define _WIN_9_X_START          298
#define _WIN_9_X_END            301
#define _WIN_9_Y_START          1
#define _WIN_9_Y_END            2

#define _WIN_41_X_START         385
#define _WIN_41_X_END           491
#define _WIN_41_Y_START         242
#define _WIN_41_Y_END           278

#define  ROW_COMMAND_END            0x00,0x00,0x00
#define  ROW_COMMAND_HEIGHT22(x)	0x80,((22 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT18(x)    0x80,((18 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT17(x)    0x80,((17 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT16(x)    0x80,((16 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT15(x)    0x80,((15 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT14(x)    0x80,((14 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT13(x)    0x80,((13 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT12(x)    0x80,((12 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT11(x)    0x80,((11 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT10(x)    0x80,((10 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT9(x)     0x80,((9 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT8(x)     0x80,((8 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT7(x)     0x80,((7 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT6(x)     0x80,((6 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT5(x)     0x80,((5 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT4(x)     0x80,((4 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT3(x)     0x80,((3 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT2(x)     0x80,((2 - 1) << 3),x
#define  ROW_COMMAND_HEIGHT1(x)     0x80,((1 - 1) << 3),x

#define _OSD_MAP0_Height        20
#define _OSD_MAP0_Width         37
#define _OSD_MAP0_CharNumber   (WORD)(_OSD_MAP0_Height * _OSD_MAP0_Width)

#define _OSD_BLANK_ITEM_MIN         (4)
#define _OSD_BLANK_ITEM_DEFAULT     (4 + 144) // 144 = (_ITEM_WIDTH + 2) x 12
#define _OSD_BLANK_BAR_MAX          (4 + 242) //


#define _OSD_BLANK_ANIMATION_STEP   12

#define _X_MSG_START                18
#define _X_MSG_END                  ((12*35)+_X_MSG_START)//496//500//503
#define _Y_MSG_START                3
#define _Y_MSG_END                  ((18*5)+_Y_MSG_START)//115

#define _OSD_MSG_ROW                8   //10
#define _OSD_MSG_COL                37//41  //60

#define _OSD_MAP1_Height            8   //10
#define _OSD_MAP1_CharNumber   (WORD)(42+42+42+42+42+42+42+42)  //(WORD)(60+60+60+60+60+60+60+60+60+60)

#define _OSD_MAP2_Height        9
#define _OSD_MAP2_CharNumber   (WORD)(55+55+55+55+55+55+55+55+55)

//=========== OSD Font Icon Address ======================//
#define _1BIT_FONT_START_ADDRESS            0x00

#define _FONT1_GLOBLE_START                 0x00    // Size = 0x12
#define _FONT1_STR_START                    0x3E    //
#define _FONT1_SECONDPAGE_START             0x100   //

#define _FONT1_BUTTON_ICON_START            0x110   // Size = 0x1E

#define _FONT1_BAR_START                    (0x100 + 46)   // Size = 0x22  //same as DYNAMIC

//////////////////////////////////////////////////////////////////////

#define _FONT1_ITEM_DYNAMIC_1_of_2          46  // Size = 15 x 2
#define _FONT1_ITEM_DYNAMIC_2_of_2          76  // 46 + 15x2 = 76
#define _FONT1_ITEM_DYNAMIC_3_of_2          106 // 76 + 15x2 = 106

#define _FONT1_256_512_ITEM_DYNAMIC_1_of_2  (0x100 + 46)    //
#define _FONT1_256_512_ITEM_DYNAMIC_2_of_2  (0x100 + 76)    //
#define _FONT1_256_512_ITEM_DYNAMIC_3_of_2  (0x100 + 106)   //

#define _FONT1_ITEM_DYNAMIC_1_of_3          46  // Size = 9 x 2
#define _FONT1_ITEM_DYNAMIC_2_of_3          64  // 46 + 9x2 = 64
#define _FONT1_ITEM_DYNAMIC_3_of_3          82  // 64 + 9x2 = 82
#define _FONT1_ITEM_DYNAMIC_4_of_3          100 // 82 + 9x2 = 100

#define _FONT1_256_512_ITEM_DYNAMIC_1_of_3  (0x100 + 46)    //
#define _FONT1_256_512_ITEM_DYNAMIC_2_of_3  (0x100 + 64)    //
#define _FONT1_256_512_ITEM_DYNAMIC_3_of_3  (0x100 + 82)    //
#define _FONT1_256_512_ITEM_DYNAMIC_4_of_3  (0x100 + 100)   //

#define _FONT1_ICON_DYNAMIC_1_of_5          46  // Size = 4 x 2 or 5 x 2
#define _FONT1_ICON_DYNAMIC_2_of_5          54  // 46 + 8 = 54
#define _FONT1_ICON_DYNAMIC_3_of_5          62  // 54 + 8 = 62
#define _FONT1_ICON_DYNAMIC_4_of_5          72  // 62 + 10 = 72
#define _FONT1_ICON_DYNAMIC_5_of_5          80  // 72 + 8 = 80
#define _FONT1_ICON_DYNAMIC_6_of_5          88  // 80 + 8 = 88

//////////////////////////////////////////////////////////////////////

#define _FONT1_ICON_1_START_1_of_5          154 //
#define _FONT1_ICON_1_START_2_of_5          162 //
#define _FONT1_ICON_1_START_3_of_5          170 //
#define _FONT1_ICON_1_START_4_of_5          180 //
#define _FONT1_ICON_1_START_5_of_5          188 //

#define _FONT1_ITEM_2_START_1_of_2          196 //
#define _FONT1_ITEM_2_START_2_of_2          226 //

#define _FONT1_ITEM_2_START_1_of_3          196 //
#define _FONT1_ITEM_2_START_2_of_3          214 //
#define _FONT1_ITEM_2_START_3_of_3          232 //

#define _FONT1_ITEM_3_START_1_of_2          (0x100 + 136) //
#define _FONT1_ITEM_3_START_2_of_2          (0x100 + 166) //

#define _FONT1_ITEM_3_START_1_of_3          (0x100 + 136) //
#define _FONT1_ITEM_3_START_2_of_3          (0x100 + 154) //
#define _FONT1_ITEM_3_START_3_of_3          (0x100 + 172) //

#define _FONT1_ITEM_4_START_1_of_2          (0x100 + 196) //
#define _FONT1_ITEM_4_START_2_of_2          (0x100 + 226) //

#define _FONT1_ITEM_4_START_1_of_3          (0x100 + 196) //
#define _FONT1_ITEM_4_START_2_of_3          (0x100 + 214) //
#define _FONT1_ITEM_4_START_3_of_3          (0x100 + 232) //

#define _FONT1_ITEM_5_2_START               (0x100 + 46) //same as DYNAMIC

//--------------------------------------------------
// Char Alias
//--------------------------------------------------
enum OSDFontDef
{
    ___ = 0x00,

    _Item_Frame_LT_,                            // 1
    _Item_Frame_LB_ = _Item_Frame_LT_,          // 1
    _Item_Frame_RT_ = _Item_Frame_LT_,          // 1
    _Item_Frame_RB_ = _Item_Frame_LT_,          // 1

    _Select_Frame_T_,                           // 2
    _Select_Frame_B_,                           // 3
    _Select_Frame_TB_,                          // 4

    _Select_Frame_L_,                           // 5
    _Select_Frame_LT_,                          // 6
    _Select_Frame_LB_,                          // 7
    _Select_Frame_LTB_,                         // 8

    _Select_Frame_R_,                           // 9
    _Select_Frame_RT_,                          // 10
    _Select_Frame_RB_,                          // 11
    _Select_Frame_RTB_,                         // 12

    _Select_Frame_SPECIAL_1,                    // 13
    _Select_Frame_SPECIAL_2,                    // 14
    _Select_Frame_SPECIAL_3,                    // 15
    _Select_Frame_SPECIAL_4,                    // 16

    _Factory_F_,                                // 17
   
};


typedef enum
{
    _Bar_Space_ = _FONT1_BAR_START, // _FONT1_BAR_START
    _Bar_U,
    _Bar_D,
    _Bar_T_U,
    _Bar_T_D,
    _Bar_0_U,
    _Bar_0_D,
    _Bar_10_U,
    _Bar_10_D,
    _Bar_20_U,
    _Bar_20_D,
    _Bar_30_U,
    _Bar_30_D,
    _Bar_40_U,
    _Bar_40_D,
    _Bar_50_U,
    _Bar_50_D,
    _Bar_60_U,
    _Bar_60_D,
    _Bar_70_U,
    _Bar_70_D,
    _Bar_80_U,
    _Bar_80_D,
    _Bar_90_U,
    _Bar_90_D,
    _Bar_100_U,
    _Bar_100_D,
    _Bar_L_U,
    _Bar_L_D,
    _Bar_R_U,
    _Bar_R_D,
    _Bar_V,
    _Bar_5_U,
    _Bar_5_D,
    
};

typedef enum
{
    _ButtonIconExit_0 = _FONT1_BUTTON_ICON_START, // _FONT1_BUTTON_ICON_START
    _ButtonIconExit_1,
    _ButtonIconExit_2,
    _ButtonIconExit_3,
    _ButtonIconExit_4,
    _ButtonIconExit_5,
    _ButtonIconLeft_0,
    _ButtonIconLeft_1,
    _ButtonIconLeft_2,
    _ButtonIconLeft_3,
    _ButtonIconLeft_4,
    _ButtonIconLeft_5,
    _ButtonIconRight_0,
    _ButtonIconRight_1,
    _ButtonIconRight_2,
    _ButtonIconRight_3,
    _ButtonIconRight_4,
    _ButtonIconRight_5,
    _ButtonIconOk_0,
    _ButtonIconOk_1,
    _ButtonIconOk_2,
    _ButtonIconOk_3,
    _ButtonIconOk_4,
    _ButtonIconOk_5,
    _ButtonIconPower_0,
    _ButtonIconPower_1,
    _ButtonIconPower_2,
    _ButtonIconPower_3,
    _ButtonIconPower_4,
    _ButtonIconPower_5,
    
};

//--------------------------------------------------
// Definitions of Window Item Select
//--------------------------------------------------
typedef enum
{
    _MAINITEM_WINDOW = 0,
    _SUBITEM_WINDOW,
    _ADJITEM_WINDOW,
};

//--------------------------------------------------
// Definitions of OSD Slider Function Used by COsdFxSlider()
//--------------------------------------------------
#define _SLIDER_START_ADDRESS                   (0x09)
#define _S_BAR                                  (_SLIDER_START_ADDRESS)         // Start Icon
#define _M_BAR                                  (_SLIDER_START_ADDRESS+1)       // Medium Icon
#define _E_BAR                                  (_SLIDER_START_ADDRESS+2)       // End Icon
#define _ARROW                                  (_SLIDER_START_ADDRESS+3)       
#define _SIRCLEARROW                            0x0D       

typedef enum
{
    _KEY_INFO_ALL = 0,
    _KEY_INFO_EXIT,
    _KEY_INFO_CANCEL,
    _KEY_INFO_OK,
    
};



#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
