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
// ID Code      : RTDInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "LenovoGreenProject.h"
#include "LenovoGreenNVRamOsd.h"
#if (CVT_EN_ON_LINE_WRITE_EDID == ENABLE)
#include "CVTEFunctionWriteEdid.h"
#endif

#if(_OSD_TYPE == _LEONVO_GREEN_OSD)


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
#define _BRIGHTNESS_MAX                             178
#define _BRIGHTNESS_MIN                             78
#define _BRIGHTNESS_CENTER                          (((_BRIGHTNESS_MAX - _BRIGHTNESS_MIN) / 2) + _BRIGHTNESS_MIN)

//--------------------------------------------------
// Definitions of Sharpness Range
//--------------------------------------------------
#define _SHARPNESS_MAX                              4
#define _SHARPNESS_MIN                              0

//--------------------------------------------------
// Definitions of Phase Range
//--------------------------------------------------
#define _OSD_PHASE_MAX                              100
#define _OSD_PHASE_MIN                              0

//--------------------------------------------------
// Definitions of OD Gain Range
//--------------------------------------------------
#define _OD_GAIN_MAX                                127
#define _OD_GAIN_MIN                                0
#define _OD_GAIN_CENTER                             (((_OD_GAIN_MAX - _OD_GAIN_MIN) / 2) + _OD_GAIN_MIN)
//==================================================================
//OSD OD Gain Default Value
//==================================================================
#ifndef _OD_NORMAL_GAIN
#define _OD_NORMAL_GAIN								_OD_GAIN_CENTER
#endif

//--------------------------------------------------
// Definitions of 3D EFFECT
//--------------------------------------------------
#define _3D_EFFECT_MAX                              0x10
#define _3D_EFFECT_MIN                              0x00

//--------------------------------------------------
// Definitions of 2DTO3D EFFECT
//--------------------------------------------------
#define _2DTO3D_H_EFFECT_MAX                        0x30
#define _2DTO3D_H_EFFECT_MIN                        0x00

#define _2DTO3D_H_V_EFFECT_MAX                      0xFF
#define _2DTO3D_H_V_EFFECT_MIN                      0x00

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
#define _OSD_H_POS_CENTER                           (((_OSD_H_POS_MAX - _OSD_H_POS_MIN) / 2) + _OSD_H_POS_MIN)

//--------------------------------------------------
// Definitions of OSD V Position Range
//--------------------------------------------------
#define _OSD_V_POS_MAX                              200
#define _OSD_V_POS_MIN                              0
#define _OSD_V_POS_CENTER                           (((_OSD_V_POS_MAX - _OSD_V_POS_MIN) / 2) + _OSD_V_POS_MIN)

//--------------------------------------------------
// Definitions of Hue Saturation Range
// Allowed Hue = 0 ~ 360, Sat = 0 ~ 330
//--------------------------------------------------
#define _DEFAULT_HUE                                _HUE_CENTER
#define _DEFAULT_SATURATION                         _SATURATION_CENTER

//--------------------------------------------------
// Definitions of Hue Saturation Range
//--------------------------------------------------
#define _SIX_COLOR_SATURATION_MAX                   200
#define _SIX_COLOR_SATURATION_MIN                   0
#define _SIX_COLOR_SATURATION_CENTER                100

#define _SIX_COLOR_HUE_MAX                          100
#define _SIX_COLOR_HUE_MIN                          0
#define _SIX_COLOR_HUE_CENTER                       50

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
// Macro of Key Hold Key
//--------------------------------------------------
#define GET_KEYHOLDKEY()                       		(bit)(g_stOsdInfo.ucOsdKeyControl & _BIT4)
#define SET_KEYHOLDKEY()                       		(g_stOsdInfo.ucOsdKeyControl |= _BIT4)
#define CLR_KEYHOLDKEY()                       		(g_stOsdInfo.ucOsdKeyControl &= ~_BIT4)

//--------------------------------------------------
// Macro of Key Message
//--------------------------------------------------
#define GET_KEYMESSAGE()                            (g_stOsdInfo.ucOsdKeyMessage)
#define SET_KEYMESSAGE(x)                           (g_stOsdInfo.ucOsdKeyMessage = (x))

//--------------------------------------------------
// Definitions of Key Message
//--------------------------------------------------
#define _MENU_KEY_MESSAGE                           0
#define _RIGHT_KEY_MESSAGE                          1
#define _LEFT_KEY_MESSAGE                           2
#define _EXIT_KEY_MESSAGE                           3
#define _5_KEY_MESSAGE                              4
#define _6_KEY_MESSAGE                              5
#define _7_KEY_MESSAGE                              6
#define _HOLD_KEY_MESSAGE                           7
#define _NONE_KEY_MESSAGE                           8

#define _KEY_AMOUNT                                 4

//--------------------------------------------------
// Definitions of LED indicction
//--------------------------------------------------
typedef enum
{
    _LED_ALL_OFF = _LED_SYSTEM_END,          
}EnumUserLedIndication;

//--------------------------------------------------
// Definitions of Different OSD Map Type
//--------------------------------------------------
#define _OSD_MAP0                                   0	// main menu
#define _OSD_MAP1                                   1	// logo
#define _OSD_MAP2                                   2	// message
#define _OSD_MAP3                                   3
//#define _OSD_MAP4                                   4
//#define _OSD_MAP5                                   5
//#define _OSD_LOGO_MAP                               6


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
#define LOGO_1bit(x)                                (x)

//--------------------------------------------------
// Definitions of Checking Max or Min Value Used by RTDOsdDisplayDetOverRange()
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


//--------------------------------------------------
// Definations of Write Byte
//--------------------------------------------------
#define _WRITE_BYTE0                                0
#define _WRITE_BYTE1                                1
#define _WRITE_BYTE2                                2
#define _WRITE_BYTEALL                              3


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
#define GET_OSD_POWER_SAVING_SHOW_SOURCE()          (g_stOsdInfo.b1OsdWakeUpShowSource)
#define SET_OSD_POWER_SAVING_SHOW_SOURCE(x)         (g_stOsdInfo.b1OsdWakeUpShowSource = (x))

//--------------------------------------------------
// MACRO for Source Menu Status
//--------------------------------------------------
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
// MACRO for Osd Pre Status
//--------------------------------------------------
#define GET_OSD_PRE_STATE()                         (g_stOsdInfo.ucOsdPreState)
#define SET_OSD_PRE_STATE(x)                        (g_stOsdInfo.ucOsdPreState = (x))

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

//--------------------------------------------------
// MACRO for 3D Effect Real Value
//--------------------------------------------------
#define GET_OSD_3D_EFFECT_REAL_VALUE()              (g_stOsdInfo.ucOsd3DEffectRealValue)
#define SET_OSD_3D_EFFECT_REAL_VALUE(x)             (g_stOsdInfo.ucOsd3DEffectRealValue = (x))

#define GET_OSD_SLIDER_REDRAW()                     (g_stOsdInfo.b1SliderReDraw)
#define SET_OSD_SLIDER_REDRAW(x)                    (g_stOsdInfo.b1SliderReDraw = (x))


#define GET_SHOW_SOURCE_INFO()						(g_stOsdInfo.b1OsdShowSourceInfo)
#if((_D0_INPUT_PORT_TYPE == _D0_NO_PORT) && (_D1_INPUT_PORT_TYPE == _D1_NO_PORT)\
&& (_D2_INPUT_PORT_TYPE == _D2_NO_PORT) && (_D3_INPUT_PORT_TYPE == _D3_NO_PORT))
#define SET_SHOW_SOURCE_INFO(x)						(g_stOsdInfo.b1OsdShowSourceInfo = (0))
#else
#define SET_SHOW_SOURCE_INFO(x)						(g_stOsdInfo.b1OsdShowSourceInfo = (x))
#endif

//--------------------------------------------------    
// Macro of DVTotal_OverSpec_FLAG                      
//--------------------------------------------------
#define GET_DVTotal_OverSpec_FLAG()                (g_stOsdInfo.b1DVTotalOverSpec)
#define SET_DVTotal_OverSpec_FLAG()                (g_stOsdInfo.b1DVTotalOverSpec = _TRUE)
#define CLR_DVTotal_OverSpec_FLAG()                (g_stOsdInfo.b1DVTotalOverSpec = _FALSE)

//--------------------------------------------------
// Macro of Previous Input Port
//--------------------------------------------------
#define GET_PREVIOUS_INPUT_PORT_STATUS()            (g_stOsdInfo.ucPreviousInputPort)
#define SET_PREVIOUS_INPUT_PORT(x)                  (g_stOsdInfo.ucPreviousInputPort = (x))

//==========================================================================================================
// Macro of NVRam BriCon Data
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
// Macro of Color TemperatureStatus
//--------------------------------------------------
#define GET_COLOR_TEMP_STATUS()                       (g_stOSDUserData.bColorTempStatus)
#define SET_COLOR_TEMP_STATUS(x)                      (g_stOSDUserData.bColorTempStatus = (x))

//--------------------------------------------------
// Macro of Color Temperature
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE()                       (g_stOSDUserData.b4ColorTempType)
#define SET_COLOR_TEMP_TYPE(x)                      (g_stOSDUserData.b4ColorTempType = (x))

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

//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_ASPECT_RATIO_TYPE()                 (g_stOSDUserData.b3AspectRatio)
#define SET_OSD_ASPECT_RATIO_TYPE(x)                (g_stOSDUserData.b3AspectRatio = (x))

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
// MACRO for Energy Star Status
//--------------------------------------------------
#define GET_OSD_ES_STATUS()                        (g_stOSDUserData.b1OsdESStatus)
#define SET_OSD_ES_STATUS(x)                       (g_stOSDUserData.b1OsdESStatus = (x))

//--------------------------------------------------
// MACRO for Sharpness
//--------------------------------------------------
#define GET_OSD_SHARPNESS()                         (g_stOSDUserData.b3Sharpness)
#define SET_OSD_SHARPNESS(x)                        (g_stOSDUserData.b3Sharpness = (x))

//--------------------------------------------------
// MACRO for Transparency
//--------------------------------------------------
#define GET_OSD_TRANSPARENCY_STATUS()               (g_stOSDUserData.b3Transparency)
#define SET_OSD_TRANSPARENCY_STATUS(x)              (g_stOSDUserData.b3Transparency = (x))

//--------------------------------------------------
// MACRO for Language
//--------------------------------------------------
#define GET_OSD_LANGUAGE()                          (g_stOSDUserData.b4Language)
#define SET_OSD_LANGUAGE(x)                         (g_stOSDUserData.b4Language = (x))

//--------------------------------------------------
// MACRO for OsdPosStatus
//--------------------------------------------------
#define GET_OSD_POS_STATUS()						(g_stOSDUserData.bOsdPosStatus)
#define SET_OSD_POS_STATUS(x)						(g_stOSDUserData.bOsdPosStatus = (x))

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
// MACRO for OD Status
//--------------------------------------------------
#define GET_OSD_OD_STATUS()                         (g_stOSDUserData.b1ODStatus)
#define SET_OSD_OD_STATUS(x)                        (g_stOSDUserData.b1ODStatus = (x))

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
#define SET_OSD_AUDIO_SOURCE(x)                     (g_stOSDUserData.b1AudioSourceStatus = (x))

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

//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_OVERSCAN_STATUS()                   (g_stOSDUserData.b1OverScan)
#define SET_OSD_OVERSCAN_STATUS(x)                  (g_stOSDUserData.b1OverScan = (x))

//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------
#define GET_OSD_HLWIN_TYPE()                        (g_stOSDUserData.ucHLWinType)
#define SET_OSD_HLWIN_TYPE(x)                       (g_stOSDUserData.ucHLWinType = (x))

//--------------------------------------------------
// MACRO for 3D Status
//--------------------------------------------------
#define GET_OSD_3D_STATUS()                         (g_stOSDUserData.b23DStatus)
#define SET_OSD_3D_STATUS(x)                        (g_stOSDUserData.b23DStatus = (x))

//--------------------------------------------------
// MACRO for 3D LR Status
//--------------------------------------------------
#define GET_OSD_3D_LR_STATUS()                      (g_stOSDUserData.b13DLRStatus)
#define SET_OSD_3D_LR_STATUS(x)                     (g_stOSDUserData.b13DLRStatus = (x))

//--------------------------------------------------
// MACRO for 3D Format Status
//--------------------------------------------------
#define GET_OSD_3D_FORMAT_STATUS()                  (g_stOSDUserData.b23DFormatStatus)
#define SET_OSD_3D_FORMAT_STATUS(x)                 (g_stOSDUserData.b23DFormatStatus = (x))

//--------------------------------------------------
// MACRO for 3D EFFECT
//--------------------------------------------------
#define GET_OSD_3D_EFFECT()                         (g_stOSDUserData.uc3DEffect)
#define SET_OSD_3D_EFFECT(x)                        (g_stOSDUserData.uc3DEffect = (x))

//--------------------------------------------------
// MACRO for 3D 3DTO2D
//--------------------------------------------------
#define GET_OSD_3D_3DTO2D()                         (g_stOSDUserData.b13D3DTO2DStatus)
#define SET_OSD_3D_3DTO2D(x)                        (g_stOSDUserData.b13D3DTO2DStatus = (x))

//--------------------------------------------------
// MACRO for 3D Convergence
//--------------------------------------------------
#define GET_OSD_3D_CONVERGENCE()                    (g_stOSDUserData.uc3DConvergence)
#define SET_OSD_3D_CONVERGENCE(x)                   (g_stOSDUserData.uc3DConvergence = (x))

//--------------------------------------------------
// MACRO for 3D Convergence Mode
//--------------------------------------------------
#define GET_OSD_3D_CONVERGENCE_MODE()               (g_stOSDUserData.b33DConvergenceMode)
#define SET_OSD_3D_CONVERGENCE_MODE(x)              (g_stOSDUserData.b33DConvergenceMode = (x))

//--------------------------------------------------
// MACRO for PCM Status
//--------------------------------------------------
#define GET_OSD_PCM_STATUS()                        (g_stOSDUserData.b2PCMStatus)
#define SET_OSD_PCM_STATUS(x)                       (g_stOSDUserData.b2PCMStatus = (x))

//--------------------------------------------------
// MACRO for Button Repeat Status
//--------------------------------------------------
#define GET_OSD_BUTTON_REPEAT_STATUS()				(g_stOSDUserData.b2OsdButtonRepeatStatus)
#define SET_OSD_BUTTON_REPEAT_STATUS(x)				(g_stOSDUserData.b2OsdButtonRepeatStatus = (x))	

//--------------------------------------------------
// MACRO for Button Repeat Status
//--------------------------------------------------
#define GET_OSD_LOCK_STATUS()						(g_stOSDUserData.b1OsdLockStatus)
#define SET_OSD_LOCK_STATUS(x)						(g_stOSDUserData.b1OsdLockStatus = (x))	

//--------------------------------------------------
// MACRO for LowBlueLight
//--------------------------------------------------
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
#define GET_LOWBLUELIGHT_STATUS()                   (g_stOSDUserData.b1LowBlueLightStatus)
#define SET_LOWBLUELIGHT_STATUS(x)                  (g_stOSDUserData.b1LowBlueLightStatus = (x))
#endif
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
#define _OSD_FLY_H_STEP								120
#define _OSD_FLY_V_STEP								100

#define GET_OSD_FLY_H_STATE()						((bit)(g_ucOsdFlyState & _BIT7))					
#define SET_OSD_FLY_H_STATE()						(g_ucOsdFlyState |= _BIT7)		// up
#define CLR_OSD_FLY_H_STATE()						(g_ucOsdFlyState &= ~_BIT7)		// down

#define GET_OSD_FLY_V_STATE()						((bit)(g_ucOsdFlyState & _BIT6))					
#define SET_OSD_FLY_V_STATE()						(g_ucOsdFlyState |= _BIT6)		// right
#define CLR_OSD_FLY_V_STATE()						(g_ucOsdFlyState &= ~_BIT6)		// left

//--------------------------------------------------
// Definitions of ROW Command Setting
//--------------------------------------------------
// row command BYTE 0

// row start
#define _ROW_END		0
#define _ROW_START 		_BIT7

// VBI
#define _VBI_DISABLE	0
#define _VBI_ENALBE		_BIT6

// 1bit font selection
#define _1BIT_0_511		0
#define _1BIT_512_1023	_BIT5

// 1 bit border shadow
#define _1BIT_BS_NONE		0
#define _1BIT_BS_BORDER		(1<<2)
#define _1BIT_BS_SHADOW_LT	(4<<2)
#define _1BIT_BS_SHADOW_LB	(5<<2)
#define _1BIT_BS_SHADOW_RT	(6<<2)
#define _1BIT_BS_SHADOW_RB	(7<<2)

// double size
#define _CHAR_WIDTH_NORMAL	0
#define _CHAR_WIDTH_DOUBLE	_BIT1
#define _CHAR_HEIGHT_NORMAL	0
#define _CHAR_HEIGHT_DOUBLE	_BIT0

// row command BYTE 1
#define ROW_HEIGHT(x)		((x-1)<<3)
#define COL_SPACE(x)		(x)

// row command BYTE 2
#define ROW_LENGTH(x)		(x)

#define ROWCOMMAND(B0_7, B0_6, B0_5, B0_4_2, B0_1, B0_0, B1_7_3, B1_2_0, B2_7_0)		B0_7|B0_6|B0_5|B0_4_2|B0_1|B0_0, B1_7_3|B1_2_0, B2_7_0

//--------------------------------------------------
// Definitions of OSD
//--------------------------------------------------
#define _PFONT_PAGE_0                               0
#define _PFONT_PAGE_1                               1
#define _PFONT_PAGE_2                               2
#define _PFONT_PAGE_ITEM_0                          3
#define _PFONT_PAGE_ITEM_1                          4
#define _PFONT_PAGE_ITEM_2                          5
#define _PFONT_PAGE_ITEM_3                          6
#define _PFONT_PAGE_ITEM_4                          7
#define _PFONT_PAGE_ITEM_5                          8
#define _PFONT_PAGE_ITEM_6                          9
#define _PFONT_PAGE_NUMBER_0                        10
#define _PFONT_PAGE_NUMBER_1                        11
#define _PFONT_PAGE_NUMBER_2                        12
#define _PFONT_PAGE_NUMBER_3                        13
#define _PFONT_PAGE_NUMBER_4                        14

#define _OSD_GLOBAL_START                           0x01
#define _OSD_GLOBAL_END                             0x0F

#define _OSD_PAGE_0_START                           0x02
#define _OSD_PAGE_0_END                             0x5F

// jimmy no use
#define _OSD_PAGE_1_START                           0x60
#define _OSD_PAGE_1_END                             0x9F

#define _OSD_PAGE_2_START                           0xA0
#define _OSD_PAGE_2_END                             0xFE


#define _SUB_PAGE_ITEM_0                            (_OSD_PAGE_2_START)					// key info sCANCEL / sEXIT
#define _SUB_PAGE_ITEM_0_END                        (_OSD_PAGE_2_START + 9)				
#define _SUB_PAGE_ITEM_1                            (_SUB_PAGE_ITEM_0_END)				// key info sOK
#define _SUB_PAGE_ITEM_1_END                        (_SUB_PAGE_ITEM_0_END + 5)//Robert Wang 20130118 3>5
#define _SUB_PAGE_ITEM_2                            (_SUB_PAGE_ITEM_1_END)				// slider
#define _SUB_PAGE_ITEM_2_END                        (_SUB_PAGE_ITEM_1_END + 22)
#define _SUB_PAGE_ITEM_3                            (_SUB_PAGE_ITEM_2_END)				// item 0
#define _SUB_PAGE_ITEM_3_END                        (_SUB_PAGE_ITEM_2_END + 17)
#define _SUB_PAGE_ITEM_4                            (_SUB_PAGE_ITEM_3_END)				// item 1
#define _SUB_PAGE_ITEM_4_END                        (_SUB_PAGE_ITEM_3_END + 13)
#define _SUB_PAGE_ITEM_5                            (_SUB_PAGE_ITEM_4_END)				// item 2
#define _SUB_PAGE_ITEM_5_END                        (_SUB_PAGE_ITEM_4_END + 10)
#define _SUB_PAGE_ITEM_6                            (_SUB_PAGE_ITEM_5_END)				// item 3
#define _SUB_PAGE_ITEM_6_END                        (_SUB_PAGE_ITEM_5_END + 8)//Robert Wang 20130118 10>8
#define _SUB_PAGE_NUMBER_0                          (_SUB_PAGE_ITEM_6_END)				// number
#define _SUB_PAGE_NUMBER_0_END                      (_SUB_PAGE_ITEM_6_END + 2)
#define _SUB_PAGE_NUMBER_1                          (_SUB_PAGE_NUMBER_0_END)				// number
#define _SUB_PAGE_NUMBER_1_END                      (_SUB_PAGE_NUMBER_0_END + 2)
#define _SUB_PAGE_NUMBER_2                          (_SUB_PAGE_NUMBER_1_END)				// number
#define _SUB_PAGE_NUMBER_2_END                      (_SUB_PAGE_NUMBER_1_END + 2)
#define _SUB_PAGE_NUMBER_3                          (_SUB_PAGE_NUMBER_2_END)				// number
#define _SUB_PAGE_NUMBER_3_END                      (_SUB_PAGE_NUMBER_2_END + 2)
#define _SUB_PAGE_NUMBER_4                          (_SUB_PAGE_NUMBER_3_END)				// number
#define _SUB_PAGE_NUMBER_4_END                      (_SUB_PAGE_NUMBER_3_END + 2)




#define _NORMAL                                     0
#define _CENTER                                     1
#define _START                                      0
#define _RUN                                        1

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


#define _OSD_SELECT									0
#define _OSD_UNSELECT								1
#define _OSD_INDICATE								2
#define _OSD_STATIC									3


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

#define _TYPE_SHADOW_1                              (0<<1)
#define _TYPE_SHADOW_2                              (1<<1)
#define _TYPE_SHADOW_3                              (2<<1)
#define _TYPE_SHADOW_4                              (3<<1)
#define _TYPE_3D_BUTTON_1                           (4<<1)
#define _TYPE_3D_BUTTON_2                           (5<<1)
#define _TYPE_BORDER								(7<<1)

#define _OSDPOS_DEFAULT								0
#define _OSDPOS_CUSTOM								1

#define _OSD_BUTTON_REPEAT_OFF						0
#define _OSD_BUTTON_REPEAT_DEFAULT					1
#define _OSD_BUTTON_REPEAT_SLOW						2

//=========== OSD Font Icon Address ======================//

#define _1BIT_GLOBAL_START				            0x00
#define _1BIT_STRING_START                          0x02
#define _1BIT_P2_START								0x100


#define _2BIT_OFFSET                                0x93
#define _2BIT_KEYITEM_START                         0x00
#define _2BIT_MAINICON_START                        _2i_ARROW_END   //Addr = 0x0d

#define _2BIT_MAINICON_START_PICTURE                _2BIT_MAINICON_START
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
#define _2BIT_MAINICON_START_LOWBLUELIGHT           (_2BIT_MAINICON_START_PICTURE + 6)
#define _2BIT_MAINICON_START_POSITION               (_2BIT_MAINICON_START_LOWBLUELIGHT + 6)
#else
#define _2BIT_MAINICON_START_POSITION               (_2BIT_MAINICON_START_PICTURE + 6)
#endif
#define _2BIT_MAINICON_START_SETUP                  (_2BIT_MAINICON_START_POSITION + 6)      
#define _2BIT_MAINICON_START_PROPERTIES             (_2BIT_MAINICON_START_SETUP + 6) 
#define _2BIT_MAINICON_START_OPTION                 (_2BIT_MAINICON_START_PROPERTIES + 6) 
#define _2BIT_MAINICON_START_EXIT                   (_2BIT_MAINICON_START_OPTION + 6)
#define _2BIT_MAINICON_END                          (_2BIT_MAINICON_START_EXIT + 6) // Addr = 0x31


#define _2BIT_SLIDER_START                          _2BIT_MAINICON_END  // 0x20 two bit font , Addr =0x31
#define _2BIT_SUBICON_START							(_2BIT_SLIDER_START + 33) // Addr = 0x71

#define _FONT2_LOWBLUELIGHT_START                   _2BIT_MAINICON_START

//****************************************************************************
#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)

#define _1BIT_LOGO_START_ADDRESS                    0x00
#define _1BIT_LOG1_START_ADDRESS                    0x100    

#if ( ( _PANEL_DH_WIDTH==1440 ) && ( _PANEL_DV_HEIGHT == 900 ) )
//Logo 1440x900(一個區塊114字寬x25字高)
#define _OSD_LOGO_ROW_SIZE                          34
#define _OSD_LOGO_COL1_SIZE                         11    
#define _OSD_LOGO_COL2_SIZE                         72
#define _OSD_EPA_LOGO_COL_SIZE                      16
#define _1BIT_EPA_LOG_START_ADDRESS                 (_1BIT_LOG1_START_ADDRESS + 0x21)//0x21 _1BIT_LOG1 icon  
#define _1BIT_EPA_LOG_ICON_START                    0x21 

#elif ( ( _PANEL_DH_WIDTH==1600 ) && ( _PANEL_DV_HEIGHT == 900 ) )
//Logo 1440x900(一個區塊114字寬x25字高)
#define _OSD_LOGO_ROW_SIZE                          35
#define _OSD_LOGO_COL1_SIZE                         11    
#define _OSD_LOGO_COL2_SIZE                         74
#define _OSD_EPA_LOGO_COL_SIZE                      16
#define _1BIT_EPA_LOG_START_ADDRESS                 (_1BIT_LOG1_START_ADDRESS + 0x2f)//0x21 _1BIT_LOG1 icon  
#define _1BIT_EPA_LOG_ICON_START                    0x2f 

#elif ( ( _PANEL_DH_WIDTH==1280 ) && ( _PANEL_DV_HEIGHT == 1024 ) )
//Logo 1280x1024(兩個區塊)
#define _OSD_LOGO_ROW_SIZE                          32  
#define _OSD_LOGO_COL1_SIZE                         9    
#define _OSD_LOGO_COL2_SIZE                         64
#define _OSD_EPA_LOGO_COL_SIZE                      16
#define _1BIT_EPA_LOG_START_ADDRESS                 (_1BIT_LOG1_START_ADDRESS + 0x0c)//0x63 _1BIT_LOG1 icon  
#define _1BIT_EPA_LOG_ICON_START                    0x0c

#elif( ( _PANEL_DH_WIDTH==1680 ) && ( _PANEL_DV_HEIGHT == 1050 ) )
//Logo 1680x1050(兩個區塊)
#define _OSD_LOGO_ROW_SIZE                           37  
#define _OSD_LOGO_COL1_SIZE                          12   
#define _OSD_LOGO_COL2_SIZE                          81
#define _OSD_EPA_LOGO_COL_SIZE                       17
#define _1BIT_EPA_LOG_START_ADDRESS                 (_1BIT_LOG1_START_ADDRESS + 0x63)//0x63 _1BIT_LOG1 icon  
#define _1BIT_EPA_LOG_ICON_START                    0x63

#elif ( ( _PANEL_DH_WIDTH==1920 ) && ( _PANEL_DV_HEIGHT == 1080 ) )
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

#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))

#define _OSD_EXTEND_256_2BIT_FONTS                   _DISABLE

#define _OSD_2_FONT_FUNCTION_LOGO                   _OFF

#define _OSD_LOGOA_WIDTH                            1920
#define _OSD_LOGOA_HEIGHT                           1080

#define _OSD_LOGO_2BIT_OFFSET                       122
#define _OSD_LOGO_FONT_BASE_ADDRESS                 954

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              61


#elif((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))

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

#define _OSD_LOGOA_WIDTH                            1608
#define _OSD_LOGOA_HEIGHT                           900

#define _OSD_LOGOB_WIDTH                            1608
#define _OSD_LOGOB_HEIGHT                           900

#define _OSD_LOGO_2BIT_OFFSET                       102
#define _OSD_LOGO_FONT_BASE_ADDRESS                 711

#define _OSD_LOGOA_ADDRESS_ROWCOMMAND               0
#define _OSD_LOGOA_ADDRESS_CHARCOMMAND              51


#else
	#warning "check logo"	
#endif


#endif
//---------------------------------------------------------------------
// Definitions of OSD Show Number Function Used by RTDOsdDisplayShowNumber()
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


#define _OSD_REPEAT                             	0
#define _OSD_NO_REPEAT                          	1

//------------------------------------------------------
// Definitions of OSD Slider Function Used by RTDOsdDisplaySlider()
//------------------------------------------------------
#define _SLIDER_RESOLUTION                          (10)

#define _SLIDER_20									0
#define _SLIDER_12									1

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
#if 1//Robert Wang 20131029 modify for _MSG_FLYING
#define _POS_MSG                                    2
#if((_PANEL_DH_WIDTH == 1920)&&(_PANEL_DV_HEIGHT == 1080))
#define _MSG_POSITION_FONT_A_H_DELAY_               3
#define _MSG_POSITION_FONT_A_V_DELAY_               3
#elif((_PANEL_DH_WIDTH == 1600)&&(_PANEL_DV_HEIGHT == 900))
#define _MSG_POSITION_FONT_A_H_DELAY_               2
#define _MSG_POSITION_FONT_A_V_DELAY_               3
#elif((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 1024))
#define _MSG_POSITION_FONT_A_H_DELAY_               2
#define _MSG_POSITION_FONT_A_V_DELAY_               2
#else
#define _MSG_POSITION_FONT_A_H_DELAY_               2
#define _MSG_POSITION_FONT_A_V_DELAY_               2
#endif
#endif

// characeter command attribute
#define _AT_NORMAL									0x8C	// font select 0 ~ 255, palette 0~15, width 12

#define _AT_FS1										0x2c	// font select 256 ~ 511, palette 0~15, width 12

//--------------------------------------------------
// Definations of HL window Border Size
//--------------------------------------------------
#define _HL_WIN_BORDER_SIZE                         2

enum OSDMessageTye
{
	_MSG_AUTO = 0,
	_MSG_LOCK,
	_MSG_UNLOCK,
	_MSG_DDCCI_ON,
	_MSG_DDCCI_OFF,
	_MSG_SLEEP,
	_MSG_NOCABLE,
	_MSG_OOR,
	_MSG_FLYING,
};

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
    _ASPECT_RATIO_OFF, 		// input timing ratio
    _ASPECT_RATIO_ORIGIN,
    _ASPECT_RATIO_AMOUNT = _ASPECT_RATIO_ORIGIN,
};

enum OSDColortempStatus
{
	_COLOR_PRESET = 0,
	_COLOR_USER,
};

//--------------------------------------------------
// Definitions of Color Temperature
//--------------------------------------------------
enum OSDColortemptureDef
{
	_CT_7200,	// Neutral        
	_CT_SRGB,	// srgb        
    _CT_6500,	// reddish
	_CT_9300,	// bluish
    _CT_USER,
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
    _CTLOWBLUELIGHT,
#endif    
    _CT_OFF,
    _CT_COLORTEMP_AMOUNT = _CT_OFF,
};

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
    BYTE b1OsdWakeUpShowSource : 1;
    BYTE b1OsdFactoryModeStatus : 1;
    BYTE b1OsdDoAspectRatio : 1;
    BYTE ucOsdsixColor : 3;
    
    BYTE ucOsdColorFormat : 2;
    BYTE b1SliderReDraw : 1;
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
	BYTE b1EnergyMode : 1;    		//Factory Energy on /off
#endif
    BYTE b1OsdShowSourceInfo : 1;

    BYTE ucOsdState;
    BYTE ucOsdPreState;
    BYTE ucOsdEventMsg;
    BYTE ucOsdKeyMessage;
    BYTE ucOsdKeyControl;
    BYTE ucOsdSixColorHue;
    BYTE ucOsdSixColorSaturation;
    BYTE ucOsd3DEffectRealValue;
    BYTE b1DVTotalOverSpec :1;      //20141217 Abel Modify    
    BYTE ucPreviousInputPort;       ///20160314 Ada
}StructOsdInfo;

typedef enum
{
#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)
    _FONT1_LOGO0 = 0,
    _FONT1_LOGO1,
    _FONT1_EPA_LOGO,
#elif(_LOGO_TYPE == _LENOVO)
    _FONT2_LOGO = 0,
    _FONT1_EPA_LOGO,

#elif((_LOGO_TYPE == _LENOVO_THINKVISION_EPA) || (_LOGO_TYPE == _LENOVO_THINKVISION) ||(_LOGO_TYPE == _LENOVO_2015_EPA) ||(_LOGO_TYPE == _LENOVO_2015))

	_FONT1_LOGO0 = 0,

#endif
    
    _FONT1_GLOBAL,
    _FONT1_P2_MAIN,    
    _FONT1_P2_INPUTINFO,
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
    _FONT2_LOWBLUELIGHT_HOTKEY,
#endif    
    _FONT2_KEYITEM, // KEY符號
    _FONT2_MAINICON,  // 空白 and main icon
    
    _FONT2_DYNAMIC_PICTURE_CONTENT,
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
    _FONT2_DYNAMIC_LOWBLUELIGHT_CONTENT,
#endif    
    _FONT2_DYNAMIC_POSITION_CONTENT,
    _FONT2_DYNAMIC_SETUP_CONTENT,
    _FONT2_DYNAMIC_PROPERTIES_CONTENT,
    _FONT2_DYNAMIC_OPTION_CONTENT,
    _FONT2_DYNAMIC_ACCESSIBILITY,
    _FONT2_DYNAMIC_INPUTINFO,
    //_FONT2_DYNAMIC_OSDPOSITION_CONTENT,
    _FONT2_SLIDER,

	_FONT0_DSUB,
	_FONT0_DVI,
	_FONT0_HDMI,
	_FONT0_DP,

};

typedef enum
{
    _PALETTE_COMMOND = 0,
    _PALETTE_LOGO,
	_PALETTE_INPUT,
};


enum OSDColorPaletteDef
{
    _CP_BG = 0,
    _CP_BLACK = _CP_BG,
    _CP_WHITE,                  // 1
	_CP_GRAYW,                  // 2
	_CP_GRAYB = 3,              // 3
    _CP_GRAY_224 = 	_CP_GRAYB,  // 3
    _CP_GREEN,                  // 4
    _CP_GREENW0,                // 5
    _CP_GREENW1,                // 6
    _CP_NONE_7,                 // 7 
    
    _CP_NONE_8,                 // 8
    _CP_NONE_9,                 // 9
    _CP_RED,                    // 10
    _CP_ORANGE,                 // 11
    _CP_WHITE1,                 // 12
    _CP_GRAYN,                  // 13 
    _CP_GREEW,                  // 14 
    _CP_WHITE2,                 // 15



    _CP2_BLACK,                 // 16
    _CP2_WHITE,                 // 17
	_CP2_GRAYW,                 // 18
	_CP2_GRAYB,                 // 19
    _CP2_GREEN,                 // 20
    _CP2_GREENW0,               // 21
    _CP2_GREENW1,               // 22
    _CP2_NONE_23,               // 23
    
    _CP2_NONE_24,               // 24
    _CP2_NONE_25,               // 25
    _CP2_RED,                   // 26 
    _CP2_ORANGE,                // 27
    _CP2_WHITE1,                // 28
    _CP2_GRAYN,                 // 29 
    _CP2_GREEW,                 // 30
    _CP2_WHITE2,                // 31


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
    _WIN_0 = 0,
    _WIN_1,
    _WIN_2,
    _WIN_3,
    _WIN_4,
    _WIN_5,
    _WIN_6,
    _WIN_7,

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
    _PALETTE_0 = 0,
};

typedef enum
{
//---0---
    _MENU_NONE,

//---1---
    _OSD_MAIN_BRIGHTCONTRAST,
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
    _OSD_MAIN_LOWBLUELIGHT,
#endif    
    _OSD_MAIN_IMAGEPOSTION,
    _OSD_MAIN_IMAGESETUP,
    _OSD_MAIN_IMAGEPROPERTIES,
    _OSD_MAIN_OPTION,
    _OSD_MAIN_EXIT,
    _OSD_MAIN_TPV_FACTORY,

//---2---
    _OSD_PICTURE_BRIGHTNESS,
    _OSD_PICTURE_CONTRAST,
#if(_LENOVO_DPS_SUPPORT == _ON)
    _OSD_PICTURE_DPS,
#endif
#if(_USER_DCR_FUNCTION == _ON)
    _OSD_PICTURE_DCR,
#endif    

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
    _OSD_LOWBLUELIGHT_ENABLE,
    _OSD_LOWBLUELIGHT_DISABLE,
#endif    

    _OSD_POS_HPOS,
    _OSD_POS_VPOS,
    _OSD_SETUP_AUTOMATIC,
    _OSD_SETUP_MANUAL,    
    _OSD_PROP_COLOR,
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
    _OSD_PROP_INPUT,
#endif
    _OSD_PROP_SCALING,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
    _OSD_PROP_BLUELIGHT,
#endif
#if(_OD_SUPPORT == _ON)
    _OSD_PROP_OD,
#endif
    _OSD_OPTION_INFORMATION,
    _OSD_OPTION_LANGUAGE,
    _OSD_OPTION_OSDPOS,
    _OSD_OPTION_DEFAULT,
    _OSD_OPTION_ACCESSIBILITY,

//---3---
    _OSD_PICTURE_BRIGHTNESS_ADJUST,
    _OSD_PICTURE_CONTRAST_ADJUST,
#if(_LENOVO_DPS_SUPPORT == _ON)    
    _OSD_PICTURE_DPS_ADJUST,
#endif    
#if(_USER_DCR_FUNCTION == _ON)
    _OSD_PICTURE_DCR_ADJUST,
#endif    
    _OSD_POS_HPOS_ADJUST,
    _OSD_POS_VPOS_ADJUST,
    _OSD_SETUP_MANUAL_CLOCK,    
    _OSD_SETUP_MANUAL_PHASE,
    _OSD_SETUP_MANUAL_SAVE,
    _OSD_PROP_COLOR_PRESET,
    _OSD_PROP_COLOR_CUSTOM,
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
    _OSD_PROP_INPUT_ANALOG,
    _OSD_PROP_INPUT_DIGITAL,
#endif
    _OSD_PROP_SCALING_OFF,
    _OSD_PROP_SCALING_ON,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
    _OSD_PROP_BLUELIGHT_OFF,
    _OSD_PROP_BLUELIGHT_ON,
#endif
#if(_OD_SUPPORT == _ON)
    _OSD_PROP_OD_ON,
    _OSD_PROP_OD_OFF,
#endif
    _OSD_OPTION_INFORMATION_SHOW,
    _OSD_OPTION_LANGUAGE_ADJUST,
    _OSD_OPTION_OSDPOS_DEFAULT,
    _OSD_OPTION_OSDPOS_CUSTOM,
    _OSD_OPTION_DEFAULT_CANCEL,
    _OSD_OPTION_DEFAULT_RESET,
    _OSD_OPTION_ACCESSIBILITY_BUTTON_REPEAT,
    _OSD_OPTION_ACCESSIBILITY_MENU_TIMEOUT,
  
//---4---
    _OSD_SETUP_MANUAL_CLOCK_ADJUST,    
    _OSD_SETUP_MANUAL_PHASE_ADJUST,
    _OSD_PROP_COLOR_PRESET_ADJUST,
    _OSD_PROP_COLOR_CUSTOM_RED,
    _OSD_PROP_COLOR_CUSTOM_GREEN,
    _OSD_PROP_COLOR_CUSTOM_BLUE,
    _OSD_PROP_COLOR_CUSTOM_SAVE,    
    _OSD_OPTION_OSDPOS_CUSTOM_HPOS,
    _OSD_OPTION_OSDPOS_CUSTOM_VPOS,
    _OSD_OPTION_OSDPOS_CUSTOM_SAVE,
    _OSD_OPTION_ACCESSIBILITY_BUTTON_OFF,
    _OSD_OPTION_ACCESSIBILITY_BUTTON_DEFAULT,
    _OSD_OPTION_ACCESSIBILITY_BUTTON_SLOW,
    _OSD_OPTION_ACCESSIBILITY_MENU_TIMEOUT_ADJUST,
    
//---5---
    _OSD_PROP_COLOR_CUSTOM_RED_ADJUST,
    _OSD_PROP_COLOR_CUSTOM_GREEN_ADJUST,
    _OSD_PROP_COLOR_CUSTOM_BLUE_ADJUST,   
    _OSD_OPTION_OSDPOS_CUSTOM_HPOS_ADJUST,
    _OSD_OPTION_OSDPOS_CUSTOM_VPOS_ADJUST,

//---OSD HotKey---
     _OSD_HOTKEY_BRIGHTNESS_ADJUST,
     _OSD_HOTKEY_SOURCE_SWITCH,
};

typedef enum
{
	_ENGLISH=0,
    _FRENCH,
    _ITALIAN,
    _CHINESE_S,
    _SPANISH,
    _JAPAN,
    _GERMAN,
    _RUSSIAN,
    _LANGUAGE_AMOUNT,
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
    _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG,
};


typedef enum
{
	ROW0 = 0,
	ROW1,
	ROW2,
	ROW3,
	ROW4,
	ROW5,
	ROW6,
	ROW7,
	ROW8,
	ROW9,
	ROW10,
	ROW11,
	ROW12,
	ROW13,
	ROW14,
	ROW15,
	ROW16,
	ROW17,
	ROW18,
	ROW19,
	ROW20,
	ROW21,
	ROW22,
	ROW23,
	ROW24,
	ROW25,
	ROW26,
	ROW27,
	ROW28,
	ROW29,
	ROW30,
	ROW31,
};

typedef enum
{
	COL0 = 0,
	COL1,
	COL2,
	COL3,
	COL4,
	COL5,
	COL6,
	COL7,
	COL8,
	COL9,
	COL10,
	COL11,
	COL12,
	COL13,
	COL14,
	COL15,
	COL16,
	COL17,
	COL18,
	COL19,
	COL20,
	COL21,
	COL22,
	COL23,
	COL24,
	COL25,
	COL26,
	COL27,
	COL28,
	COL29,
	COL30,
	COL31,
};

typedef enum
{
	_KEY_INFO_ALL = 0,
	_KEY_INFO_EXIT,
	_KEY_INFO_CANCEL,
};


 // sub icon
typedef enum
{
	_MAIN_ICON_PICTURE = 0,
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
    _MAIN_ICON_LOWBLUELIGHT,
#endif    
    _MAIN_ICON_POSTION,
	_MAIN_ICON_SETUP,
	_MAIN_ICON_PROPERTIES,
	_MAIN_ICON_OPTION,
	_MAIN_ICON_EXIT,	
	_MAIN_ICON_FACTORY,

	_SUB_ICON_BRIGHTNESS,
	_SUB_ICON_CONTRAST,
#if(_LENOVO_DPS_SUPPORT == _ON)
	_SUB_ICON_DPS,
#endif
#if(_USER_DCR_FUNCTION == _ON)
	_SUB_ICON_DCR,
#endif

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
    _SUB_ICON_LOWBLUELIGHT_ENABLE,
    _SUB_ICON_LOWBLUELIGHT_DISABLE,
#endif    
   
	_SUB_ICON_HPOS,
	_SUB_ICON_VPOS,

	_SUB_ICON_AUTOMATIC,
	_SUB_ICON_MANUAL,

	_SUB_ICON_COLOR,
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
	_SUB_ICON_INPUT,
#endif
	_SUB_ICON_SCALING,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
    _SUB_ICON_BLUELIGHT,
#endif

    _SUB_ICON_OD,
	_SUB_ICON_INFORMATION,
	_SUB_ICON_LANGUAGE,
	_SUB_ICON_OSDPOS,
	_SUB_ICON_RESET,
	_SUB_ICON_ACCESSIBILITY,	
	_SUB_ICON_BUTTON_REPEAT,
	_SUB_ICON_MENU_TIMEOUT,


	_SUB_ICON_BRIGHTNESS_ADJUST,
	_SUB_ICON_CONTRAST_ADJUST,
	_SUB_ICON_HPOS_ADJUST,
	_SUB_ICON_VPOS_ADJUST,


	_TITLE_ICON_BRIGHTNESS,
	_TITLE_ICON_CONTRAST,
#if(_LENOVO_DPS_SUPPORT == _ON)	
	_TITLE_ICON_DPS,
#endif	
#if(_USER_DCR_FUNCTION == _ON)
	_TITLE_ICON_DCR,
#endif
	_TITLE_ICON_HPOS,
	_TITLE_ICON_VPOS,	
	_TITLE_ICON_MANUAL,
	_TITLE_ICON_COLOR,
	_TITLE_ICON_INPUT,
	_TITLE_ICON_SCALING,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
    _TITLE_ICON_BLUELIGHT,
#endif	
    _TITLE_ICON_OD,
	_TITLE_ICON_INFORMATION,
	_TITLE_ICON_LANGUAGE,
	_TITLE_ICON_OSDPOS,
	_TITLE_ICON_RESET,
	_TITLE_ICON_ACCESSIBILITY,	
	_SUB_ICON_OSDPOS_HPOS_ADJUST,
	_SUB_ICON_OSDPOS_VPOS_ADJUST,
    _SUBTITLE_ICON_BUTTON_REPEAT,
    _SUBTITLE_ICON_MENU_TIMEOUT,

	_SUB_ICON_ANALOG,
	_SUB_ICON_DIGITAL,

};

// sub item
typedef enum
{
	_SUB_ITEM_MANUAL_CLOCK = 0,
	_SUB_ITEM_MANUAL_PHASE,
	_SUB_ITEM_MANUAL_SAVE,

	_SUB_ITEM_MANUAL_CLOCK_ADJUST,
	_SUB_ITEM_MANUAL_PHASE_ADJUST,

	_SUB_ITEM_COLOR_PRESET,
	_SUB_ITEM_COLOR_CUSTOM,

	_SUB_ITEM_PRESET_NEUTRAL,
	_SUB_ITEM_PRESET_SRGB,
	_SUB_ITEM_PRESET_REDDISH,
	_SUB_ITEM_PRESET_BLUISH,

	_SUB_ITEM_CUSTOM_RED,
	_SUB_ITEM_CUSTOM_GREEN,
	_SUB_ITEM_CUSTOM_BLUE,
	_SUB_ITEM_CUSTOM_SAVE,

	_SUB_ITEM_CUSTOM_RED_ADJUST,
	_SUB_ITEM_CUSTOM_GREEN_ADJUST,
	_SUB_ITEM_CUSTOM_BLUE_ADJUST,

	_SUB_ITEM_INPUT_ANALOG,
	_SUB_ITEM_INPUT_DIGITAL,
		
	_SUB_ITEM_SCALING_OFF,
	_SUB_ITEM_SCALING_ON,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
    _SUB_ITEM_BLUELIGHT_OFF,
    _SUB_ITEM_BLUELIGHT_ON,
#endif

    _SUB_ITEM_OD_ON,
    _SUB_ITEM_OD_OFF,
    
	_SUB_ITEM_OSDPOS_DEFAULT,
	_SUB_ITEM_OSDPOS_CUSTOM,
	_SUB_ITEM_OSDPOS_H,
	_SUB_ITEM_OSDPOS_V,
	_SUB_ITEM_OSDPOS_SAVE,
	_SUB_ITEM_OSDPOS_H_ADJUST,
	_SUB_ITEM_OSDPOS_V_ADJUST,

	_SUB_ITEM_DEFAULT_CANCEL,
	_SUB_ITEM_DEFAULT_RESET,

	_SUB_ITEM_BUTTON_OFF,
	_SUB_ITEM_BUTTON_DEFAULT,
	_SUB_ITEM_BUTTON_SLOW,
#if(_LENOVO_DPS_SUPPORT == _ON)
	_SUB_ITEM_DPS_OFF,
	_SUB_ITEM_DPS_ON,

#endif	
#if(_USER_DCR_FUNCTION == _ON)
    _SUB_ITEM_DCR_OFF,
    _SUB_ITEM_DCR_ON,
#endif    
};

typedef enum
{
	_MAIN_CONTENT_PICTURE = 0,
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
    _MAIN_CONTENT_LOWBLUELIGHT,
#endif    
	_MAIN_CONTENT_POSTION,
	_MAIN_CONTENT_SETUP,
	_MAIN_CONTENT_PROPERTIES,
	_MAIN_CONTENT_OPTION,
	_MAIN_CONTENT_EXIT,	
	_MAIN_CONTENT_FACTORY,
};


typedef enum
{
	_MAIN_STRING_PICTURE = 0,
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
    _MAIN_STRING_LOWBLUELIGHT,
#endif    
	_MAIN_STRING_POSITION,
	_MAIN_STRING_SETUP,
	_MAIN_STRING_PROPERTIES,
	_MAIN_STRING_OPTION,
	_MAIN_STRING_EXIT,
	_MAIN_STRING_FACTORY,

	_MAIN_STRING_BRIGHTNESS,
	_MAIN_STRING_CONTRAST,
#if(_LENOVO_DPS_SUPPORT == _ON)
	_MAIN_STRING_DPS,
#endif
#if(_USER_DCR_FUNCTION == _ON)
	_MAIN_STRING_DCR,
#endif      

    _MAIN_STRING_LOWBLUELIGHT_ENABLE,
    _MAIN_STRING_LOWBLUELIGHT_DISABLE,


	_MAIN_STRING_HPOS,
	_MAIN_STRING_VPOS,
	_MAIN_STRING_MANUAL,

	_MAIN_STRING_COLOR,
	_MAIN_STRING_PRESET,
	_MAIN_STRING_CUSTOM,
	_MAIN_STRING_INPUT,
	_MAIN_STRING_SCALING,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
    _MAIN_STRING_BLUELIGHT,
#endif
    _MAIN_STRING_OD,
    _MAIN_STRING_INFORMATION,
	_MAIN_STRING_LANGUAGE,
	_MAIN_STRING_OSDPOS,
	_MAIN_STRING_DEFAULT,
	_MAIN_STRING_ACCESSIBILITY,
//	_MAIN_STRING_BUTTON_REPEAT,
//	_MAIN_STRING_MENU_TIMEOUT,	
	_MAIN_STRING_END,


	_SUB_STRING_BRIGHTNESS,
	_SUB_STRING_CONTRAST,
#if(_LENOVO_DPS_SUPPORT == _ON)
	_SUB_STRING_DPS,
#endif
#if(_USER_DCR_FUNCTION == _ON)
	_SUB_STRING_DCR,
#endif    
	_SUB_STRING_HPOS,
	_SUB_STRING_VPOS,
	_SUB_STRING_AUTOMATIC,
	_SUB_STRING_MANUAL,

	_SUB_STRING_COLOR,
	_SUB_STRING_INPUT,
	_SUB_STRING_SCALING,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
    _SUB_STRING_BLUELIGHT,
#endif
    _SUB_STRING_OD,
    
    _SUB_STRING_INFORMATION,
    _SUB_STRING_LANGUAGE_SELECT,
    _SUB_STRING_OSDPOSTION_SELECT,
    _SUB_STRING_DEFAULT_SELECT,
    _SUB_STRING_ACCESSIBILITY,

	_SUB_STRING_SCALING_OFF,
	_SUB_STRING_SCALING_ON,

	_SUB_STRING_BUTTON_REPEAT,
	_SUB_STRING_MENU_TIMEOUT,


	_SUB_TITLE_STRING_BUTTON_REPEAT,
	_SUB_TITLE_STRING_MENU_TIMEOUT,	


    _SUB_STRING_END,
	
};


typedef enum
{
	_SLIDER_BRIGHTNESS = 0,
	_SLIDER_CONTRAST,
	_SLIDER_HPOS,
	_SLIDER_VPOS,
	_SLIDER_CLOCK,
	_SLIDER_PHASE,
	_SLIDER_RED,
	_SLIDER_GREEN,
	_SLIDER_BLUE,
	_SLIDER_OSDHPOS,
	_SLIDER_OSDVPOS,
	_SLIDER_OSDTIMEOUT,
	
};


//--------------------------
// definition of 1 bit font 
//--------------------------

// font 256 ~ 511
typedef enum
{
	 ___ = 0,
	_iFULL = 1,
	_iBODER_L_U,
	_iBODER_R_U,
	_iBODER_L_D,
	_iBODER_R_D,
/*//Eli 20120823 modify osd icon.
	_iPICTURE_00,	// 0x06
	_iPICTURE_01,
	_iPICTURE_02,
	_iPICTURE_10,	
	_iPICTURE_11,
	_iPICTURE_12,

	_iPOSITION_00,	// 0x0C
	_iPOSITION_01,
	_iPOSITION_02,
	_iPOSITION_10,
	_iPOSITION_11,
	_iPOSITION_12,

	_iSETUP_01,	// 0x12
	_iSETUP_02, 
	_iSETUP_11,
	_iSETUP_12,

	_iPROPERTIES_01, // 0x16
	_iPROPERTIES_02,
	_iPROPERTIES_10,
	_iPROPERTIES_11,
	_iPROPERTIES_12,

	_iOPTION_00,	// 0x1B
	_iOPTION_01,
	_iOPTION_02,
	_iOPTION_11,
	_iOPTION_12,

	_iEXIT_01,	// 0x20
	_iEXIT_02,
	_iEXIT_11,
	_iEXIT_12,
*/
	_iUP,		// 0x24
	_iUP_0,		// 0x25
	_iUP_1,

	_iPLUS,		// 0x27
	_iMINUS,	// 0x28

	_iDOWN,		// 0x29
	_iLEFT,
	_iRIGHT,

	_iBACK_00,	// 0x2c
	_iBACK_01,
	_iBACK_02,
	_iBACK_10,
	_iBACK_11,
	_iBACK_12,

	_iLEFT_00,	// 0x32
	_iLEFT_01,
	_iLEFT_02,
	_iLEFT_10,
	_iLEFT_11,
	_iLEFT_12,

	_iRIGHT_00,	// 0x38
	_iRIGHT_01,
	_iRIGHT_02,
	_iRIGHT_10,
	_iRIGHT_11,

	_iOK_00,	// 0x3d
	_iOK_01,
	_iOK_02,
	_iOK_10,
	_iOK_11,
	_iOK_12,

	_iF,
	
};


//--------------------------
// definition of 2 bit font 
//--------------------------
typedef enum
{ // empty and main icon font address
    _2i_EMPTY_1 = _2BIT_KEYITEM_START,  // 0
    _2i_EMPTY_2,                        // 1
    _2i_ARROW_L1,                       // 2 
    _2i_ARROW_L2,                       // 3
    _2i_ARROW_R1,                       // 4
    _2i_ARROW_R2,                       // 5
    _2i_ARROW_ENTER1,                   // 6
    _2i_ARROW_ENTER2,                   // 7
    _2i_ARROW_CANCEL_UP1,               // 8
    _2i_ARROW_CANCEL_UP2,               // 9
    _2i_ARROW_CANCEL_DOWN1,             // a
    _2i_ARROW_CANCEL_DOWN2,             // b
    _2i_ARROW_CANCEL_DOWN3,             // c
    _2i_ARROW_END,
};

typedef enum
{ 
	_2iPICTURE_00 = _2BIT_MAINICON_START,
	_2iPICTURE_01,
	_2iPICTURE_02,
	_2iPICTURE_10,	
	_2iPICTURE_11,
	_2iPICTURE_12,

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
	_2iLOWBLUELIGHT_00,
	_2iLOWBLUELIGHT_01,
	_2iLOWBLUELIGHT_02,
	_2iLOWBLUELIGHT_10,
	_2iLOWBLUELIGHT_11,
	_2iLOWBLUELIGHT_12,
#endif    

	_2iPOSITION_00,
	_2iPOSITION_01,
	_2iPOSITION_02,
	_2iPOSITION_10,
	_2iPOSITION_11,
	_2iPOSITION_12,

    _2iSETUP_00,
	_2iSETUP_01,
	_2iSETUP_02, 
    _2iSETUP_10,
    _2iSETUP_11,
	_2iSETUP_12,

    _2iPROPERTIES_00,
	_2iPROPERTIES_01,
	_2iPROPERTIES_02,
	_2iPROPERTIES_10,
	_2iPROPERTIES_11,
	_2iPROPERTIES_12,

	_2iOPTION_00,
	_2iOPTION_01,
	_2iOPTION_02,
	_2iOPTION_10,	
	_2iOPTION_11,
	_2iOPTION_12,
	
    _2iEXIT_00,
	_2iEXIT_01,
	_2iEXIT_02,
	_2iEXIT_10,
	_2iEXIT_11,
	_2iEXIT_12,
};

typedef enum
{    
	_2i_BRI_SUB_00 = _2BIT_SUBICON_START,
    _2i_BRI_SUB_01,
    _2i_CON_SUB_00,    
    _2i_CON_SUB_01,    
	_2i_BRI_R_00,
	_2i_BRI_R_01,
    _2i_CON_R_00,    
    _2i_CON_R_01,    
    _2i_CON_L_00,    
    _2i_CON_L_01,   
#if(_USER_DCR_FUNCTION == _ON)
    _2i_DCR_SUB_00,    
    _2i_DCR_SUB_01,   
#endif
    _2i_PICTURE00,
    _2i_PICTURE01,
    _2i_PICTURE02,
    _2i_PICTURE03,
    _2i_PICTURE04,
    _2i_PICTURE05,
    _2i_PICTURE06,
    _2i_PICTURE07,
    _2i_PICTURE08,
#if(_LENOVO_DPS_SUPPORT == _ON)
    _2i_DPS_SUB_00,    
    _2i_DPS_SUB_01,    
    _2i_DPS_H_00,
    _2i_DPS_H_01,
    _2i_DPS_H_10,
    _2i_DPS_H_11,
#endif
};

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
typedef enum
{
	_2i_LOWBLUELIGHT_00 = _2BIT_SUBICON_START,
	_2i_LOWBLUELIGHT_01,
	_2i_LOWBLUELIGHT_02,
	_2i_LOWBLUELIGHT_03,
	_2i_LOWBLUELIGHT_04,
	_2i_LOWBLUELIGHT_05,	
	_2i_LOWBLUELIGHT_06,
};
#endif    

typedef enum
{
	_2i_HPOS_SUB_00 = _2BIT_SUBICON_START,
	_2i_HPOS_SUB_01,
	_2i_HPOS_R_00,
	_2i_HPOS_R_01,
	_2i_VPOS_L_00,
	_2i_VPOS_L_01,	
	_2i_VPOS_SUB_00,
	_2i_VPOS_SUB_01,

    _2i_POSITION00,
    _2i_POSITION01,
    _2i_POSITION02,
    _2i_POSITION03,
    _2i_POSITION04,
    _2i_POSITION05,
    _2i_POSITION06,
    _2i_POSITION07,
    _2i_POSITION08,
};

/*
typedef enum
{
	_2i_OSDHPOS_L_00 = _2BIT_SUBICON_START+2,
	_2i_OSDHPOS_L_01,
	_2i_OSDHPOS_R_00,
	_2i_OSDHPOS_R_01,
	_2i_OSDVPOS_R_00,
	_2i_OSDVPOS_R_01,
	_2i_OSDVPOS_L_00,
	_2i_OSDVPOS_L_01,
};
*/
typedef enum
{
    _2i_AUTOMATIC_SUB_00 = _2BIT_SUBICON_START,
    _2i_AUTOMATIC_SUB_01,
	_2i_MANUAL_SUB_00,
	_2i_MANUAL_SUB_01,
	_2i_MANUAL_H_00,
	_2i_MANUAL_H_01,
	_2i_MANUAL_H_10,
	_2i_MANUAL_H_11,
	_2i_MANUAL00,
	_2i_MANUAL01,
	_2i_MANUAL02,
	_2i_MANUAL03,
	_2i_MANUAL04,
	_2i_MANUAL05,
	_2i_MANUAL06,
	_2i_MANUAL07,
	_2i_MANUAL08,
};

typedef enum
{
	_2i_COLOR_SUB_00 = _2BIT_SUBICON_START,
	_2i_COLOR_SUB_01,

	_2i_XXX_SUB_00,
	_2i_XXX_SUB_01,

	_2i_INPUT_SUB_00,
	_2i_INPUT_SUB_01,
	_2i_INPUT_SUB_02,

	_2i_SCALING_SUB_00,
	_2i_SCALING_SUB_01,

    _2i_PROPERTIES00,
    _2i_PROPERTIES01,
    _2i_PROPERTIES02,
    _2i_PROPERTIES03,
    _2i_PROPERTIES04,
    _2i_PROPERTIES05,
    _2i_PROPERTIES06,
    _2i_PROPERTIES07,
    _2i_PROPERTIES08,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
    _2i_BLUELIGHT_SUB_00,
    _2i_BLUELIGHT_SUB_01,
#endif
};


typedef enum
{
	_2i_INFORMATION_SUB_00 = _2BIT_SUBICON_START,
	_2i_INFORMATION_SUB_01,

	_2i_LANGUAGE_SUB_00,
	_2i_LANGUAGE_SUB_01,

	_2i_OSDPOS_SUB_00,
	_2i_OSDPOS_SUB_01,

	_2i_RESET_SUB_00,
	_2i_RESET_SUB_01,

	_2i_ACCESSIBILITY_SUB_00,
	_2i_ACCESSIBILITY_SUB_01,

    _2i_INFORMATION00,
    _2i_INFORMATION01,
    _2i_INFORMATION02,
    _2i_INFORMATION03,
    _2i_INFORMATION04,
    _2i_INFORMATION05,
    _2i_INFORMATION06,
    _2i_INFORMATION07,
    _2i_INFORMATION08,

 	_2i_OSDHPOS_L_00,
	_2i_OSDHPOS_L_01,
	_2i_OSDHPOS_R_00,
	_2i_OSDHPOS_R_01,
	_2i_OSDVPOS_R_00,
	_2i_OSDVPOS_R_01,
	_2i_OSDVPOS_L_00,
	_2i_OSDVPOS_L_01,    
};

typedef enum
{ 
   	_2i_ACCESSIBILITY_H_00 = _2BIT_SUBICON_START,
	_2i_ACCESSIBILITY_H_01,
	_2i_ACCESSIBILITY_H_10,
	_2i_ACCESSIBILITY_H_11,

    _2i_BUTTON_REPEAT_SUB_00,
    _2i_BUTTON_REPEAT_SUB_01,

	_2i_MENU_TIMEOUT_SUB_00,
	_2i_MENU_TIMEOUT_SUB_01,
 
};

typedef enum
{    
	_2i_INPUT_H_00 = _2BIT_SUBICON_START,
	_2i_INPUT_H_01,
	_2i_INPUT_H_02,
	_2i_INPUT_H_10,
	_2i_INPUT_H_11,
	_2i_INPUT_H_12,

	_2i_INPUT_VGA_00,
    _2i_INPUT_VGA_01,
    _2i_INPUT_VGA_02,
	_2i_INPUT_DVI_00,
    _2i_INPUT_DVI_01,
    _2i_INPUT_DVI_02,
	_2i_INPUT_DP_00,
    _2i_INPUT_DP_01,
    _2i_INPUT_DP_02,    
};




#define _TABSEL_CHT_ENG			0xFE    // ENG TABLE
#define _TABSEL_CHT_BIG         0xFD    // CHT BIG TEXT
#define _TABSEL_CHT_EXTEND      _TABSEL_CHT_BIG    // CHT BIG TEXT




#define _TABSEL_JAP_ENG			0xFE    // JAP + ENG
#define _TABSEL_JAP_BIG1        0xFD    // JAP BIG TEXT_1
#define _TABSEL_JAP_BIG2        0xFC    // JAP BIG TEXT_2
#define _TABSEL_JAP_EXTEND      _TABSEL_JAP_BIG2


/*
// China 0
#define _CHT_00					0x10, 0x11	// 簡
#define _CHT_01					0x12, 0x13	// 體
#define _CHT_02					0x14		// 中
#define _CHT_03					0x15, 0x16	// 文
#define _CHT_04					0x17, 0x18	// 亮
#define _CHT_05					0x19, 0x1a	// 度
#define _CHT_06					0x1b, 0x1c	// 對
#define _CHT_07					0x1d, 0x1e	// 比
#define _CHT_08					0x1f, 0x20	// 圖
#define _CHT_09					0x21, 0x22	// 像
#define _CHT_0A					0x23, 0x24	// 位
#define _CHT_0B					0x25, 0x26	// 置
#define _CHT_0C					0x27, 0x28	// 調
#define _CHT_0D					0x29, 0x2a	// 整
#define _CHT_0E					0x2b, 0x2c	// 設
#define _CHT_0F					0x2d, 0x2e	// 定
#define _CHT_10					0x2f, 0x30	// 色
#define _CHT_11					0x31, 0x32	// 溫
#define _CHT_12					0x33, 0x34	// 選
#define _CHT_13					0x35, 0x36	// 項
#define _CHT_14					0x37, 0x38	// 退
#define _CHT_15					0x39, 0x3a	// 出
#define _CHT_16					0x3b, 0x3c	// 水
#define _CHT_17					0x3d, 0x3e	// 平
#define _CHT_18					0x3f, 0x40	// 垂
#define _CHT_19					0x41, 0x42	// 直
#define _CHT_1A					0x43, 0x44	// 手
#define _CHT_1B					0x45, 0x46	// 動
#define _CHT_1C					0x47, 0x48	// 顏
#define _CHT_1D					0x49, 0x4a	// 預
#define _CHT_1E					0x4b, 0x4c	// 模
#define _CHT_1F					0x4d, 0x4e	// 式
#define _CHT_20					0x4f, 0x50	// 用
#define _CHT_21					0x51, 0x52	// 戶
#define _CHT_22					0x53, 0x54	// 信
#define _CHT_23					0x55, 0x56	// 息
#define _CHT_24					0x57, 0x58	// 機
#define _CHT_25					0x59, 0x5a	// 種
#define _CHT_26					0x5b, 0x5c	// 名
#define _CHT_27					0x5d, 0x5e	// 版
#define _CHT_28					0x5f, 0x60	// 本
#define _CHT_29					0x61, 0x62	// 號
#define _CHT_2A					0x63, 0x64	// 菜
#define _CHT_2B					0x65, 0x66	// 單
#define _CHT_2C					0x67, 0x68	// 語
#define _CHT_2D					0x69, 0x6a	// 言
#define _CHT_2E					0x6b, 0x6c	// 工
#define _CHT_2F					0x6d, 0x6e	// 廠
#define _CHT_30					0x6f, 0x70	// 默
#define _CHT_31					0x71, 0x72	// 認
#define _CHT_32					0x73, 0x74	// 值
#define _CHT_33					0x75, 0x76	// OSD
#define _CHT_34					0x77, 0x78	// 響
#define _CHT_35					0x79, 0x7a	// 應
#define _CHT_36					0x7b, 0x7c	// 控
#define _CHT_37					0x7d, 0x7e	// 制
#define _CHT_38					0x7f, 0x80	// 時
#define _CHT_39					0x81, 0x82	// 鐘
#define _CHT_3A					0x83, 0x84	// 相
#define _CHT_3B					0x85, 0x86	// 保
#define _CHT_3C					0x87, 0x88	// 存
#define _CHT_3D					0x89, 0x8a	// 標
#define _CHT_3E					0x8b, 0x8c	// 準
#define _CHT_3F					0x8d, 0x8e	// 暖
#define _CHT_40					0x8f, 0x90	// 冷
#define _CHT_41					0x91, 0x92	// 紅
#define _CHT_42					0x93, 0x94	// 綠
#define _CHT_43					0x95, 0x96	// 藍
#define _CHT_44					0x97, 0x98	// 取
#define _CHT_45					0x99, 0x9a	// 消
#define _CHT_46					0x9b, 0x9c	// 復
#define _CHT_47					0x9d		// 自
#define _CHT_48					0x9e, 0x9f	// 輸
#define _CHT_49					0xa0, 0xa1	// 入
#define _CHT_4A					0xa2, 0xa3	// 縮
#define _CHT_4B					0xa4, 0xa5	// 放
#define _CHT_4C					0xa6, 0xa7	// 例
#define _CHT_4D					0xa8, 0xa9	// 顯
#define _CHT_4E					0xaa, 0xab	// 示
#define _CHT_4F					0xac, 0xad	// 間
#define _CHT_50					0xae, 0xaf	// 關
#define _CHT_51					0xb0, 0xb1	// 慢
#define _CHT_52                 0xb2, 0xb3  // 已
#define _CHT_53                 0xb4, 0xb5  // 鎖 
#define _CHT_54                 0xb6, 0xb7  // 解
#define _CHT_55                 0xb8        // C 
#define _CHT_56                 0xb9        // D 
#define _CHT_57                 0xba        // I 
#define _CHT_58                 0xbb, 0xbc  // 開 
#define _CHT_59                 0xbd, 0xbe  // 無

#define _CHT_60                 0xbf, 0xc0  // 線 
#define _CHT_61                 0xc1, 0xc2  // 連
#define _CHT_62                 0xc3, 0xc4  // 接 
#define _CHT_63                 0xc5, 0xc6  // 檢
#define _CHT_64                 0xc7, 0xc8  // 查
#define _CHT_65                 0xc9, 0xca  // 確

// China 1
#define _sCHT_00				0x10, 0x11	// 調
#define _sCHT_01				0x12, 0x13	// 整
#define _sCHT_02				0x14, 0x15	// 全
#define _sCHT_03				0x16, 0x17	// 屏
#define _sCHT_04				0x18, 0x19	// 亮
#define _sCHT_05				0x1a, 0x1b	// 度
#define _sCHT_06				0x1c    	// 明
#define _sCHT_07				0x1d, 0x1e	// 暗
#define _sCHT_08				0x1f, 0x20	// 水
#define _sCHT_09				0x21, 0x22	// 平
#define _sCHT_0A				0x23, 0x24	// 垂
#define _sCHT_0B				0x25, 0x26	// 直
#define _sCHT_0C				0x27		// 圖
#define _sCHT_0D				0x28, 0x29	// 像
#define _sCHT_0E				0x2a, 0x2b	// 移
#define _sCHT_0F				0x2c, 0x2d	// 動
#define _sCHT_10				0x2e, 0x2f	// 屏
#define _sCHT_11				0x30, 0x31	// 幕
#define _sCHT_12				0x32, 0x33	// 優
#define _sCHT_13				0x34, 0x35	// 化
#define _sCHT_14				0x36, 0x37	// 手
#define _sCHT_15				0x38, 0x39	// 相
#define _sCHT_16				0x3A, 0x3B	// 位
#define _sCHT_17				0x3C, 0x3D	// 及
#define _sCHT_18				0x3E, 0x3F	// 時
#define _sCHT_19				0x40, 0x41	// 鐘
#define _sCHT_1A				0x42, 0x43	// 紅
#define _sCHT_1B				0x44, 0x45	// 綠
#define _sCHT_1C				0x46, 0x47	// 藍
#define _sCHT_1D				0x48, 0x49	// 色
#define _sCHT_1E				0x4a, 0x4b	// 選
#define _sCHT_1F				0x4c, 0x4d	// 擇
#define _sCHT_20				0x4e, 0x4f	// 視
#define _sCHT_21				0x50, 0x51	// 頻
#define _sCHT_22				0x52, 0x53	// 信
#define _sCHT_23				0x54, 0x55	// 號
#define _sCHT_24				0x56, 0x57	// 比
#define _sCHT_25				0x58, 0x59	// 例
#define _sCHT_26				0x5a, 0x5b	// 類
#define _sCHT_27				0x5c, 0x5d	// 型
#define _sCHT_28				0x5e 		// 與
#define _sCHT_29				0x5f		// 高
#define _sCHT_2A				0x60, 0x61	// 輸
#define _sCHT_2B				0x62, 0x63	// 入
#define _sCHT_2C				0x64		// 同
#define _sCHT_2D				0x65		// 的
#define _sCHT_2E				0x66, 0x67	// 寬
#define _sCHT_2F				0x68, 0x69	// 將
#define _sCHT_30				0x6a, 0x6b	// 擴
#define _sCHT_31				0x6c, 0x6d	// 展
#define _sCHT_32				0x6e, 0x6f	// 至
#define _sCHT_33				0x70, 0x71	// 全
#define _sCHT_34				0x72, 0x73	// 幕
#define _sCHT_35				0x74, 0x75	// 顯
#define _sCHT_36				0x76, 0x77	// 示
#define _sCHT_37				0x78, 0x79	// 分
#define _sCHT_38				0x7a, 0x7b	// 辨
#define _sCHT_39				0x7c, 0x7d	// 刷
#define _sCHT_3A				0x7e, 0x7f	// 新
#define _sCHT_3B				0x80, 0x81	// 率
#define _sCHT_3C				0x82, 0x83	// 以
#define _sCHT_3D				0x84, 0x85	// 及
#define _sCHT_3E				0x86 		// 產
#define _sCHT_3F				0x87		// 品
#define _sCHT_40				0x88, 0x89	// 詳
#define _sCHT_41				0x8a, 0x8b	// 細
#define _sCHT_42				0x8c, 0x8d	// 信
#define _sCHT_43				0x8e, 0x8f	// 息
#define _sCHT_44				0x90, 0x91	// 改
#define _sCHT_45				0x92, 0x93	// 變
#define _sCHT_46				0x94, 0x95	// 菜
#define _sCHT_47				0x96		// 單 
#define _sCHT_48				0x97		// 言
#define _sCHT_49				0x98, 0x99	// 語
#define _sCHT_4A				0x9a		// 置 
#define _sCHT_4B				0x9b		// 間 
#define _sCHT_4C				0x9c, 0x9d	// 按  
#define _sCHT_4D				0x9e, 0x9f	// 鍵
#define _sCHT_4E				0xa0, 0xa1	// 響 
#define _sCHT_4F				0xa2, 0xa3	// 應
#define _sCHT_50				0xa4, 0xa5	// 速
#define _sCHT_51				0xa6, 0xa7	// 度
#define _sCHT_52				0xa8, 0xa9	// 及
#define _sCHT_53				0xaa, 0xab	// 恢
#define _sCHT_54				0xac, 0xad	// 愎
#define _sCHT_55				0xae, 0xaf	// 初
#define _sCHT_56				0xb0, 0xb1	// 始
#define _sCHT_57				0xb2, 0xb3	// 值
#define _sCHT_58				0xb4, 0xb5	// 設
#define _sCHT_59				0xb6, 0xb7	// 定
#define _sCHT_5A                0xb8        // 自         
#define _sCHT_5B                0xb9        // 中
#define _sCHT_5C                0xba,0xbb   // 稍     
#define _sCHT_5D                0xbc,0xbd   // 等

#define _sCHT_5E                0xbe        // 0         
#define _sCHT_5F                0xbf        // 1
#define _sCHT_60                0xc0        // 2     
#define _sCHT_61                0xc1        // 4
#define _sCHT_62                0xc2        // 5     
#define _sCHT_63                0xc3        // 6
#define _sCHT_64                0xc4        // 8
#define _sCHT_65                0xc5        // 9     
#define _sCHT_66                0xc6,0xc7   // 超
#define _sCHT_67                0xc8        // 出     
#define _sCHT_68                0xc9,0xca   // 范
#define _sCHT_69                0xcb        // 圍     
#define _sCHT_6A                0xcc        // 為
#define _sCHT_6B                0xcd        // x     
#define _sCHT_6C                0xce        // H
#define _sCHT_6D                0xcf        // z

// China 2
#define _CHT_200				0x02, 0x03	// 模
#define _CHT_201				0x04, 0x05	// 擬
#define _CHT_202				0x06, 0x07	// 數
#define _CHT_203				0x08, 0x09	// 字
#define _CHT_204				0x0a, 0x0b	// 原
#define _CHT_205				0x0c, 0x0d	// 始
#define _CHT_206				0x0e, 0x0f	// 寬
#define _CHT_207				0x10, 0x11	// 高
#define _CHT_208				0x12, 0x13	// 比
#define _CHT_209				0x14, 0x15	// 全
#define _CHT_20A				0x16, 0x17	// 屏
#define _CHT_20B				0x18, 0x19	// 幕
#define _CHT_20C				0x1a, 0x1b	// 按
#define _CHT_20D				0x1c, 0x1d	// 鍵
#define _CHT_20E				0x1e, 0x1f	// 反
#define _CHT_20F				0x20, 0x21	// 應
#define _CHT_210				0x22, 0x23	// 速
#define _CHT_211				0x24, 0x25	// 度
#define _CHT_212				0x26        // -
#define _CHT_213				0x27    	// 1
#define _CHT_214				0x28    	// __4
*/

typedef enum             
{                              
// CHT BIG TEXT  

     _CH_00 = 0x00 ,
     _CH_01,         
     _CH_02,         
     _CH_03,         
     _CH_04,         
     _CH_05,         
     _CH_06,         
     _CH_07,         
     _CH_08,         
     _CH_09,         
     _CH_0A,         
     _CH_0B,         
     _CH_0C,         
     _CH_0D,         
     _CH_0E,         
     _CH_0F,         

// 
     _CH_10,         
     _CH_11,         
     _CH_12,         
     _CH_13,         
     _CH_14,         
     _CH_15,         
     _CH_16,         
     _CH_17,         
     _CH_18,         
     _CH_19,         
     _CH_1A,         
     _CH_1B,         
     _CH_1C,         
     _CH_1D,         
     _CH_1E,         
     _CH_1F,         

     _CH_20,         
     _CH_21,         
     _CH_22,         
     _CH_23,         
     _CH_24,         
     _CH_25,         
     _CH_26,         
     _CH_27,         
     _CH_28,         
     _CH_29,         
     _CH_2A,         
     _CH_2B,         
     _CH_2C,         
     _CH_2D,         
     _CH_2E,         
     _CH_2F,         

     _CH_30,         
     _CH_31,         
     _CH_32,         
     _CH_33,         
     _CH_34,         
     _CH_35,         
     _CH_36,         
     _CH_37,         
     _CH_38,         
     _CH_39,         
     _CH_3A,         
     _CH_3B,         
     _CH_3C,         
     _CH_3D,         
     _CH_3E,         
     _CH_3F,         

     _CH_40,         
     _CH_41,         
     _CH_42,         
     _CH_43,         
     _CH_44,         
     _CH_45,         
     _CH_46,         
     _CH_47,         
     _CH_48,         
     _CH_49,         
     _CH_4A,         
     _CH_4B,         
     _CH_4C,         
     _CH_4D,         
     _CH_4E,         
     _CH_4F,  
     
     _CH_50,         
     _CH_51,         
     _CH_52,         
     _CH_53,         
     _CH_54,         
     _CH_55,         
     _CH_56,         
     _CH_57,         
     _CH_58,         
     _CH_59,         
     _CH_5A,         
     _CH_5B,         
     _CH_5C,         
     _CH_5D,         
     _CH_5E,         
     _CH_5F,         

     _CH_60,         
     _CH_61,         
     _CH_62,         
     _CH_63,         
     _CH_64,         
     _CH_65,         
     _CH_66,         
     _CH_67,         
     _CH_68,         
     _CH_69,         
     _CH_6A,         
     _CH_6B,         
     _CH_6C,         
     _CH_6D,         
     _CH_6E,         
     _CH_6F,         

     _CH_70,         
     _CH_71,         
     _CH_72,         
     _CH_73,         
     _CH_74,         
     _CH_75,         
     _CH_76,         
     _CH_77,         
     _CH_78,         
     _CH_79,         
     _CH_7A,         
     _CH_7B,         
     _CH_7C,         
     _CH_7D,         
     _CH_7E,         
     _CH_7F,         

     _CH_80,         
     _CH_81,         
     _CH_82,         
     _CH_83,         
     _CH_84,         
     _CH_85,         
     _CH_86,         
     _CH_87,         
     _CH_88,         
     _CH_89,         
     _CH_8A,         
     _CH_8B,         
     _CH_8C,         
     _CH_8D,         
     _CH_8E,         
     _CH_8F,         

     _CH_90,         
     _CH_91,         
     _CH_92,         
     _CH_93,         
     _CH_94,         
     _CH_95,         
     _CH_96,         
     _CH_97,         
     _CH_98,         
     _CH_99,         
     _CH_9A,         
     _CH_9B,         
     _CH_9C,         
     _CH_9D,         
     _CH_9E,         
     _CH_9F,         


     _CH_A0,         
     _CH_A1,         
     _CH_A2,         
     _CH_A3,         
     _CH_A4,         
     _CH_A5,         
     _CH_A6,         
     _CH_A7,         
     _CH_A8,         
     _CH_A9,         
     _CH_AA,         
     _CH_AB,         
     _CH_AC,         
     _CH_AD,         
     _CH_AE,         
     _CH_AF,         

     _CH_B0,         
     _CH_B1,         
     _CH_B2,         
     _CH_B3,         
     _CH_B4,         
     _CH_B5,         
     _CH_B6,         
     _CH_B7,         
     _CH_B8,         
     _CH_B9,         
     _CH_BA,         
     _CH_BB,         
     _CH_BC,         
     _CH_BD,         
     _CH_BE,         
     _CH_BF,         

     _CH_C0,         
     _CH_C1,         
     _CH_C2,         
     _CH_C3,         
     _CH_C4,         
     _CH_C5,         
     _CH_C6,         
     _CH_C7,         
     _CH_C8,         
     _CH_C9,         
     _CH_CA,         
     _CH_CB,         
     _CH_CC,         
     _CH_CD,         
     _CH_CE,         
     _CH_CF,         
     
     _CH_D0,         
     _CH_D1,         
     _CH_D2,         
     _CH_D3,         
     _CH_D4,         
     _CH_D5,         
     _CH_D6,         
     _CH_D7,         
     _CH_D8,         
     _CH_D9,         
     _CH_DA,         
     _CH_DB,         
     _CH_DC,         
     _CH_DD,         
     _CH_DE,         
     _CH_DF,         

     _CH_E0,         
     _CH_E1,         
     _CH_E2,         
     _CH_E3,         
     _CH_E4,         
     _CH_E5,         
     _CH_E6,         
     _CH_E7,         
     _CH_E8,         
     _CH_E9,         
     _CH_EA,         
     _CH_EB,         
     _CH_EC,         
     _CH_ED,         
     _CH_EE,         
     _CH_EF,         


     _CH_F0,         
     _CH_F1,         
     _CH_F2,         
     _CH_F3,         
     _CH_F4,         
     _CH_F5,         
     _CH_F6,         
     _CH_F7,         
     _CH_F8,         
     _CH_F9,         
     _CH_FA,         
     _CH_FB,         
     _CH_FC,         
     _CH_FD,         
     _CH_FE,         
     _CH_FF,         

};





// Japan b
#define _JAP_00 				0x10		// 日
#define _JAP_01 				0x11, 0x12	// 本
#define _JAP_02 				0x13, 0x14	// 語
#define _JAP_03 				0x15, 0x16	// 輝
#define _JAP_04 				0x17, 0x18	// 度
#define _JAP_05 				0x19
#define _JAP_06 				0x1a
#define _JAP_07  				0x1b, 0x1c
#define _JAP_08 				0x1d
#define _JAP_09 				0x1e, 0x1f
#define _JAP_0A 				0x20, 0x21	// 畫
#define _JAP_0B 				0x22, 0x23	// 像
#define _JAP_0C 				0x24, 0x25	// 位
#define _JAP_0D 				0x26, 0x27	// 置
#define _JAP_0E 				0x28, 0x29	// 調
#define _JAP_0F 				0x2a, 0x2b	// 整
#define _JAP_10 				0x2c, 0x2d	// 水
#define _JAP_11 				0x2e, 0x2f	// 平
#define _JAP_12 				0x30, 0x31	// 垂
#define _JAP_13 				0x32, 0x33	// 直
#define _JAP_14 				0x34, 0x35	// 面
#define _JAP_15 				0x36, 0x37	// 設
#define _JAP_16 				0x38, 0x39	// 定
#define _JAP_17 				0x3a, 0x3b	// 特
#define _JAP_18 				0x3c, 0x3d	// 性
#define _JAP_19 				0x3e, 0x3f	// 終
#define _JAP_1A 				0x40		// 了
#define _JAP_1B 				0x41, 0x42	// 才
#define _JAP_1C 				0x43, 0x44		
#define _JAP_1D 				0x45, 0x46
#define _JAP_1E 				0x47		
#define _JAP_1F 				0x48, 0x49	// 取		
#define _JAP_20 				0x4a, 0x4b	// 消		
#define _JAP_21 				0x4c, 0x4d	// 手
#define _JAP_22 				0x4e, 0x4f	// 動		
#define _JAP_23 				0x50		// 自		
#define _JAP_24 				0x51, 0x52	// 保
#define _JAP_25 				0x53, 0x54	// 存		
#define _JAP_26 				0x55, 0x56	// 		
#define _JAP_27 				0x57  		// 口		
#define _JAP_28 				0x58, 0x59	// 相		
#define _JAP_29 				0x5A		// 力		
#define _JAP_2A 				0x5B, 0x5C	// 一		
#define _JAP_2B 				0x5D, 0x5E	// 入		
#define _JAP_2C 				0x5F, 0x60	// 信		
#define _JAP_2D 				0x61, 0x62	// 號		
#define _JAP_2E 				0x63, 0x64	// 縮		
#define _JAP_2F 				0x65, 0x66	// 尺		
#define _JAP_30 				0x67		// 		
#define _JAP_31 				0x68		// 中
#define _JAP_32 				0x69, 0x6a	// 
#define _JAP_33 				0x6b, 0x6c	// 
#define _JAP_34 				0x6d, 0x6e	// 
#define _JAP_35 				0x6f, 0x70	// 間
#define _JAP_36 				0x71, 0x72	// 色
#define _JAP_37 				0x73, 0x74	// 赤
#define _JAP_38 				0x75, 0x76	// 綠
#define _JAP_39 				0x77, 0x78	// 青
#define _JAP_3A 				0x79, 0x7a	// 
#define _JAP_3B 				0x7b, 0x7c	// 
#define _JAP_3C 				0x7d, 0x7e	// 
#define _JAP_3D 				0x7f, 0x80	// 
#define _JAP_3E 				0x81, 0x82	// 
#define _JAP_3F 				0x83, 0x84	// 
#define _JAP_40 				0x85, 0x86	// ㄦ 
#define _JAP_41 				0x87, 0x88	// 元 
#define _JAP_42 				0x89, 0x8a	//  
#define _JAP_43 				0x8b		// A 
#define _JAP_44 				0x8c		// R 
#define _JAP_45 				0x8d, 0x8e	// 全 
#define _JAP_46 				0x8f		// 
#define _JAP_47 				0x90, 0x91	// 情 
#define _JAP_48 				0x92, 0x93	// 報
#define _JAP_49 				0x94, 0x95	// 表
#define _JAP_4A 				0x96, 0x97	// 示
#define _JAP_4B 				0x98, 0x99	// 言
#define _JAP_4C 				0x9a, 0x9b	// 再
#define _JAP_4D 				0x9c, 0x9d	// 可
#define _JAP_4E 				0x9e, 0x9f	// 能
#define _JAP_4F 				0xa0, 0xa1	// 既
#define _JAP_50 				0xa2, 0xa3	// 值
#define _JAP_51 				0xa4, 0xa5	// 個
#define _JAP_52 				0xa6, 0xa7	// 別
#define _JAP_53 				0xa8, 0xa9	// 化
#define _JAP_54 				0xaa, 0xab	// 
#define _JAP_55 				0xac, 0xad	// 
#define _JAP_56 				0xae, 0xaf	// 應
#define _JAP_57 				0xb0, 0xb1	// 答
#define _JAP_58 				0xb2, 0xb3	// 速
#define _JAP_59 				0xb4, 0xb5	// 度
#define _JAP_5A 				0xb6, 0xb7	// 二
#define _JAP_5B 				0xb8, 0xb9	// 時
#define _JAP_5C 				0xba	// 
#define _JAP_5D                 0xbb, 0xbc  // 
#define _JAP_5E                 0xbd        // 
#define _JAP_5F                 0xbe        // 
#define _JAP_60                 0xbf,0xc0   // 
#define _JAP_61                 0xc1,0xc2   // 
#define _JAP_62                 0xc3        // 
#define _JAP_63                 0xc4,0xc5   // 
#define _JAP_64                 0xc6,0xc7   // 解
#define _JAP_65                 0xc8,0xc9   // 除
#define _JAP_66                 0xca,0xcb   // 省
#define _JAP_67                 0xcc,0xcd   // 電
#define _JAP_68                 0xce,0xcf   // 力
#define _JAP_69                 0xd0,0xd1   // 
#define _JAP_6A                 0xd2,0xd3   // 
#define _JAP_6B                 0xd3        // C
#define _JAP_6C                 0xd4        // D
#define _JAP_6D                 0xd5        // I
#define _JAP_6E                 0xd6,0xd7   // 非
#define _JAP_6F                 0xd8,0xd9   // 名
#define _JAP_70                 0xda,0xdb   // 
#define _JAP_71                 0xdc        // 

#define _JAP_73                 0xdd,0xde   // 接
#define _JAP_74                 0xdf,0xe0   // 繞
#define _JAP_75                 0xe1,0xe2   // 
#define _JAP_76                 0xe3        // 
#define _JAP_77                 0xe4,0xe5   // 
#define _JAP_78                 0xe6,0xe7   // 
#define _JAP_79                 0xe8,0xe9   // 
#define _JAP_7A                 0xea,0xeb   // 
#define _JAP_7B                 0xec,0xed   // 
#define _JAP_7C                 0xee        // 
#define _JAP_7D                 0xef        // 
#define _JAP_7E                 0xf0        // o
#define _JAP_7F                 0xf1        // K
#define _JAP_80                 0xf2        // 1


// Japan s
#define _sJAP_00				0x10, 0x11	// 畫
#define _sJAP_01				0x12, 0x13	// 面
#define _sJAP_02				0x14, 0x15	// 全
#define _sJAP_03				0x16, 0x17	// 体
#define _sJAP_04				0x18		// 
#define _sJAP_05				0x19		// 
#define _sJAP_06				0x1a, 0x1b	// 輝
#define _sJAP_07				0x1c, 0x1d	// 度
#define _sJAP_08				0x1e, 0x1f	// 調
#define _sJAP_09				0x20, 0x21	// 整
#define _sJAP_0A				0x22		// 
#define _sJAP_0B			 	0x23		// 
#define _sJAP_0C				0x24		// 
#define _sJAP_0D				0x25		// 
#define _sJAP_0E				0x26		// 明 
#define _sJAP_0F				0x27		// 
#define _sJAP_10				0x28		// 
#define _sJAP_11				0x29		// 
#define _sJAP_12				0x2a, 0x2b	// 部
#define _sJAP_13				0x2c, 0x2d	// 分
#define _sJAP_14				0x2e, 0x2f	// 暗
#define _sJAP_15				0x30, 0x31	// 差
#define _sJAP_16				0x32, 0x33	// 異
#define _sJAP_17				0x34, 0x35	// 像
#define _sJAP_18				0x36, 0x37	// 左
#define _sJAP_19				0x38, 0x39	//  
#define _sJAP_1A				0x3a, 0x3b	// 移
#define _sJAP_1B				0x3c, 0x3d	// 動
#define _sJAP_1C				0x3e		// 右
#define _sJAP_1D				0x3f, 0x40	// 上
#define _sJAP_1E				0x41, 0x42	// 下
#define _sJAP_1F				0x43		// 自
#define _sJAP_20				0x44		// 
#define _sJAP_21				0x45		// 
#define _sJAP_22				0x46		// 
#define _sJAP_23				0x47		// 口
#define _sJAP_24				0x48, 0x49	// 置 
#define _sJAP_25				0x4a, 0x4b	// 相
#define _sJAP_26				0x4c, 0x4d	// 手
#define _sJAP_27				0x4e, 0x4f	// 位
#define _sJAP_28				0x50, 0x51	// 行
#define _sJAP_29				0x52, 0x53	// 
#define _sJAP_2A				0x54, 0x55	// 
#define _sJAP_2B				0x56		// 
#define _sJAP_2C				0x57, 0x58	// 赤 
#define _sJAP_2D				0x59, 0x5a	// 綠 
#define _sJAP_2E				0x5b		// 青 
#define _sJAP_2F				0x5c		//
#define _sJAP_30				0x5d		//
#define _sJAP_31				0x5e		//
#define _sJAP_32				0x5f		//
#define _sJAP_33				0x60		//
#define _sJAP_34				0x61		//
#define _sJAP_35				0x62		// 號
#define _sJAP_36				0x63, 0x64	//  
#define _sJAP_37				0x65, 0x66	// 
#define _sJAP_38				0x67, 0x68	// 入 
#define _sJAP_39				0x69, 0x6a	// 信 
#define _sJAP_3A				0x6b, 0x6c	// 
#define _sJAP_3B				0x6d, 0x6e	//  
#define _sJAP_3C				0x6f		// 才
#define _sJAP_3D				0x70		// ㄗ
#define _sJAP_3E				0x71		// 尺
#define _sJAP_3F				0x72		// 
#define _sJAP_40				0x73		// 同
#define _sJAP_41				0x74, 0x75	// 
#define _sJAP_42				0x76, 0x77	// 
#define _sJAP_43				0x78, 0x79	// 
#define _sJAP_44				0x7a, 0x7b	// ㄦ
#define _sJAP_45				0x7c, 0x7d	// 選
#define _sJAP_46				0x7e, 0x7f	// 擇
#define _sJAP_47				0x80, 0x81	// 
#define _sJAP_48				0x82, 0x83	// 縮
#define _sJAP_49				0x84, 0x85	// 
#define _sJAP_4A				0x86, 0x87	// 比
#define _sJAP_4B				0x88, 0x89	// 全
#define _sJAP_4C				0x8a, 0x8b	// 表
#define _sJAP_4D				0x8c, 0x8d	// 示
#define _sJAP_4E				0x8e		// 
#define _sJAP_4F				0x8f		// 品
#define _sJAP_50				0x90, 0x91	// 解
#define _sJAP_51				0x92, 0x93	// 更
#define _sJAP_52				0x94, 0x95	// 新
#define _sJAP_53				0x96, 0x97	// 速
#define _sJAP_54				0x98, 0x99	// 製
#define _sJAP_55				0x9a, 0x9b	// 情
#define _sJAP_56				0x9c, 0x9d	// 報
#define _sJAP_57				0x9e		// x
#define _sJAP_58				0x9f		// 二
#define _sJAP_59				0xa0		// 
#define _sJAP_5A				0xa1		// 一
#define _sJAP_5B				0xa2		// 言
#define _sJAP_5C				0xa3		// 
#define _sJAP_5D				0xa4		// 出
#define _sJAP_5E				0xa5		// 
#define _sJAP_5F				0xa6		//
#define _sJAP_60				0xa7		// 工
#define _sJAP_61				0xa8, 0xa9	//
#define _sJAP_62				0xaa, 0xab	// 語
#define _sJAP_63				0xac, 0xad	//
#define _sJAP_64				0xae, 0xaf	//
#define _sJAP_65				0xb0, 0xb1	// 場
#define _sJAP_66				0xb2, 0xb3	// 荷
#define _sJAP_67				0xb4, 0xb5	// 時
#define _sJAP_68				0xb6, 0xb7	// 設
#define _sJAP_69				0xb8, 0xb9	// 定
#define _sJAP_6A				0xba, 0xbb	// 戾
#define _sJAP_6B				0xbc, 0xbd	// 
#define _sJAP_6C				0xbe, 0xbf	// 應
#define _sJAP_6D				0xc0, 0xc1	// 答
#define _sJAP_6E				0xc2, 0xc3	// ㄙ
#define _sJAP_6F				0xc4, 0xc5	// 變
#define _sJAP_70				0xc6  		// 
#define _sJAP_71                0xc7        //力
#define _sJAP_72                0xc8,0xc9   //號
#define _sJAP_73                0xca,0xcb   //
#define _sJAP_74                0xcc        //
#define _sJAP_75                0xcd        //
#define _sJAP_76                0xce,0xcf   //外
#define _sJAP_77                0xd0,0xd1   //
#define _sJAP_78                0xd2        //
#define _sJAP_79                0xd3,0xd4   //
#define _sJAP_7A                0xd5,0xd6   //
#define _sJAP_7B                0xd7        //
#define _sJAP_7C                0xd8,0xd9   //
#define _sJAP_7D                0xda        //
#define _sJAP_7E                0xdb        // 0
#define _sJAP_7F                0xdc        // 1
#define _sJAP_80                0xdd        // 2
#define _sJAP_81                0xde        // 4
#define _sJAP_82                0xdf        // 5
#define _sJAP_83                0xe0        // 6
#define _sJAP_84                0xe1        // 8
#define _sJAP_85                0xe2        // 9
#define _sJAP_86                0xe3        // x
#define _sJAP_87                0xe4        // H
#define _sJAP_88                0xe5        // z

#define _sJAP_89                0xe6,0xe7   // 最
#define _sJAP_8A                0xe8,0xe9   // 適
#define _sJAP_8B                0xea,0xeb   // 化
#define _sJAP_8C                0xec,0xed   // 行
#define _sJAP_8D                0xee,0xef   // 
#define _sJAP_8E                0xf0        // 
#define _sJAP_8F                0xf1        // 
#define _sJAP_90                0xf2        // 
#define _sJAP_91                0xf3,0xf4   // 待
#define _sJAP_92                0xf5        // 
#define _sJAP_93                0xf6,0xf7   // 

/*
// JAP + ENG
#define _GO_        0x00
#define _GK_        0x01
#define _G_SLASH_   0x02
#define _GD_        0x03
#define _GC_        0x04
#define _GI_        0x05
*/

typedef enum             
{                              
// JAP BIG TEXT  
  _JP_00 = 0x10 ,
     _JP_01,         
     _JP_02,         
     _JP_03,         
     _JP_04,         
     _JP_05,         
     _JP_06,         
     _JP_07,         
     _JP_08,         
     _JP_09,         
     _JP_0A,         
     _JP_0B,         
     _JP_0C,         
     _JP_0D,         
     _JP_0E,         
     _JP_0F,         

     _JP_10,         
     _JP_11,         
     _JP_12,         
     _JP_13,         
     _JP_14,         
     _JP_15,         
     _JP_16,         
     _JP_17,         
     _JP_18,         
     _JP_19,         
     _JP_1A,         
     _JP_1B,         
     _JP_1C,         
     _JP_1D,         
     _JP_1E,         
     _JP_1F,         

     _JP_20,         
     _JP_21,         
     _JP_22,         
     _JP_23,         
     _JP_24,         
     _JP_25,         
     _JP_26,         
     _JP_27,         
     _JP_28,         
     _JP_29,         
     _JP_2A,         
     _JP_2B,         
     _JP_2C,         
     _JP_2D,         
     _JP_2E,         
     _JP_2F,         

     _JP_30,         
     _JP_31,         
     _JP_32,         
     _JP_33,         
     _JP_34,         
     _JP_35,         
     _JP_36,         
     _JP_37,         
     _JP_38,         
     _JP_39,         
     _JP_3A,         
     _JP_3B,         
     _JP_3C,         
     _JP_3D,         
     _JP_3E,         
     _JP_3F,         

     _JP_40,         
     _JP_41,         
     _JP_42,         
     _JP_43,         
     _JP_44,         
     _JP_45,         
     _JP_46,         
     _JP_47,         
     _JP_48,         
     _JP_49,         
     _JP_4A,         
     _JP_4B,         
     _JP_4C,         
     _JP_4D,         
     _JP_4E,         
     _JP_4F,        

     _JP_50,         
     _JP_51,         
     _JP_52,         
     _JP_53,         
     _JP_54,         
     _JP_55,         
     _JP_56,         
     _JP_57,         
     _JP_58,         
     _JP_59,         
     _JP_5A,         
     _JP_5B,         
     _JP_5C,         
     _JP_5D,         
     _JP_5E,         
     _JP_5F,         

     _JP_60,         
     _JP_61,         
     _JP_62,         
     _JP_63,         
     _JP_64,         
     _JP_65,         
     _JP_66,         
     _JP_67,         
     _JP_68,         
     _JP_69,         
     _JP_6A,         
     _JP_6B,         
     _JP_6C,         
     _JP_6D,         
     _JP_6E,        
     _JP_6F,         

     _JP_70,         
     _JP_71,         
     _JP_72,         
     _JP_73,         
     _JP_74,         
     _JP_75,         
     _JP_76,         
     _JP_77,         
     _JP_78,         
     _JP_79,         
     _JP_7A,         
     _JP_7B,         
     _JP_7C,         
     _JP_7D,         
     _JP_7E,         
     _JP_7F,        

     _JP_80,         
     _JP_81,         
     _JP_82,         
     _JP_83,         
     _JP_84,         
     _JP_85,         
     _JP_86,         
     _JP_87,         
     _JP_88,         
     _JP_89,         
     _JP_8A,         
     _JP_8B,         
     _JP_8C,         
     _JP_8D,         
     _JP_8E,         
     _JP_8F,         

     _JP_90,         
     _JP_91,         
     _JP_92,         
     _JP_93,         
     _JP_94,         
     _JP_95,         
     _JP_96,         
     _JP_97,         
     _JP_98,         
     _JP_99,         
     _JP_9A,         
     _JP_9B,         
     _JP_9C,         
     _JP_9D,         
     _JP_9E,         
     _JP_9F,         

     _JP_A0,         
     _JP_A1,         
     _JP_A2,         
     _JP_A3,         
     _JP_A4,         
     _JP_A5,         
     _JP_A6,         
     _JP_A7,         
     _JP_A8,         
     _JP_A9,         
     _JP_AA,         
     _JP_AB,         
     _JP_AC,         
     _JP_AD,         
     _JP_AE,         
     _JP_AF,         

     _JP_B0,         
     _JP_B1,         
     _JP_B2,         
     _JP_B3,         
     _JP_B4,         
     _JP_B5,         
     _JP_B6,         
     _JP_B7,         
     _JP_B8,         
     _JP_B9,         
     _JP_BA,         
     _JP_BB,         
     _JP_BC,         
     _JP_BD,         
     _JP_BE,         
     _JP_BF,         

     _JP_C0,         
     _JP_C1,         
     _JP_C2,         
     _JP_C3,         
     _JP_C4,         
     _JP_C5,         
     _JP_C6,         
     _JP_C7,         
     _JP_C8,         
     _JP_C9,         
     _JP_CA,         
     _JP_CB,         
     _JP_CC,         
     _JP_CD,         
     _JP_CE,         
     _JP_CF,         

     _JP_D0,         
     _JP_D1,         
     _JP_D2,         
     _JP_D3,         
     _JP_D4,         
     _JP_D5,         
     _JP_D6,         
     _JP_D7,         
     _JP_D8,         
     _JP_D9,         
     _JP_DA,         
     _JP_DB,         
     _JP_DC,         
     _JP_DD,         
     _JP_DE,         
     _JP_DF,         

     _JP_E0,         
     _JP_E1,         
     _JP_E2,         
     _JP_E3,         
     _JP_E4,         
     _JP_E5,         
     _JP_E6,         
     _JP_E7,         
     _JP_E8,         
     _JP_E9,         
     _JP_EA,         
     _JP_EB,         
     _JP_EC,         
     _JP_ED,         
     _JP_EE,         
     _JP_EF,         

     _JP_F0,         
     _JP_F1,         
     _JP_F2,         
     _JP_F3,         
     _JP_F4,         
     _JP_F5,         
     _JP_F6,         
     _JP_F7,         
     _JP_F8,         
     _JP_F9,         
     _JP_FA,         
     _JP_FB,         
     _JP_FC,         
     _JP_FD,         
     _JP_FE,         
     _JP_FF,         

};









//RUSSIAN
typedef enum             
{                              
//Address 0x10~0x1F 
    _RU_BR = 0x10,      
    _RU_Bp,  
    _RU_Bk,  
    _RU_Bo,  
    _RU_Bc,  
    _RU_BT,  
    _RU_Bb,  
    _RU_BK,  
    _RU_BH,  
    _RU_Ba,  
    _RU_BBn,  
    _RU_Bn1,  
    _RU_Bx,  
    _RU_Be,  
    _RU_Bnn,  
    _RU_B3,
        
//Address 0x20~0x2F                         
    _RU_B6, 
    _RU_BR1, 
    _RU_BT1, 
    _RU_Bn2, 
    _RU_BB, 
    _RU_BBH, 
    _RU_BNDot, 
    _RU_BBA, 
    _RU_BB1, 
    _RU_BM, 
    _RU_B4, 
    _RU_By, 
    _RU_B10,       
    _RU_BB4,    
    _RU_BBQ,    
    _RU_BBC,    


//Address 0x30~0x3F 
	_RU_BBx, 
	_RU_BB42, 
	_RU_BBA1, 
	_RU_BBM,
	_RU_BBW,  
	_RU_BT3, 
	_RU_BBP, 
	_RU_BI,
	_RU_BB3,
	_RU_NB1,
	_RU_NB2,
	_RU_BBN,
	_RU_BO,
	_RU_BBA2,
	_RU_BY,
	_RU_BEI,

//Address 0x40~0x4F 
	_RU_P, 
	_RU_e, 
	_RU_r, 
	_RU_y,
	_RU_n1,  
	_RU_N1, 
	_RU_p, 
	_RU_o,
	_RU_B,
	_RU_k,
	_RU_a,
	_RU_R1,
	_RU_c,
	_RU_T,
	_RU_31,
	_RU_H,

//Address 0x50~0x5F 
	_RU_41,
	_RU_bi,
	_RU_M,
	_RU_x1,
	_RU_A1,
	_RU_42,
	_RU_n2,
	_RU_W1,
	_RU_61,
	_RU_n3,
	_RU_3,
  	_RU_x,
  	_RU_O,
  	_RU_Q,
  	_RU_10,
  	_RU_T1,

//Address 0x60~0x6F 
    _RU_b,
    _RU_NDot,
    _RU_N2, 
  	_RU_W,
    _RU_C,
    _RU_BEC,
    _RU_BED,
    _RU_B1,
    _RU_NB0,
	_RU_NB4,
	_RU_NB5,
	_RU_NB6,
	_RU_NB8,
	_RU_NB9,
	_RU_H1,
	_RU_z,

//Address 0x70~0x7F 
    _RU_A,
};

typedef enum             
{                              
     __1 = 0,
     __4,
     __8,
     _SLASH,
     _COLON,
     _DOT,
     _SEC_1,
     _SEC_2,
     _PARENT_OPEN,
     _PARENT_CLOSE,
     _COMMA,
     _AT_SIGN,
     _LINE,
     __X,
     __H,
     __z,
};

/*
// Latin
#define __1             0x00
#define __4             0x01
#define __8             0x02
#define _SLASH          0x03
#define _COLON          0x04
#define _DOT            0x05
#define _SEC_1          0x06
#define _SEC_2          0x07
#define _PARENT_OPEN    0x08
#define _PARENT_CLOSE   0x09
#define _COMMA          0x0A
#define _AT_SIGN        0x0B
#define _LINE           0x0c
#define __X             0x0d
#define __H             0x0e
#define __z             0x0f
*/

#define _8P_  __8  
#define _6P_  __8  
#define _4P_  __4  
#define ___     __1     


#define _bsn_    0xd8


#define _0_     0x10
#define _1_     (_0_+0x01)
#define _2_     (_0_+0x02)
#define _3_     (_0_+0x03)
#define _4_     (_0_+0x04)
#define _5_     (_0_+0x05)
#define _6_     (_0_+0x06)
#define _7_     (_0_+0x07)
#define _8_     (_0_+0x08)
#define _9_     (_0_+0x09)

#define _b0_     0xDA
#define _b1_     (_b0_+0x01)
#define _b2_     (_b0_+0x02)
#define _b3_     (_b0_+0x03)
#define _b4_     (_b0_+0x04)
#define _b5_     (_b0_+0x05)
#define _b6_     (_b0_+0x06)
#define _b7_     (_b0_+0x07)
#define _b8_     (_b0_+0x08)
#define _b9_     (_b0_+0x09)

#define _sa_    0x20  // subitem 說明文字第二排小寫
#define _sb_    (_sa_+0x01)
#define _sc_    (_sa_+0x02)
#define _sd_    (_sa_+0x03)
#define _se_    (_sa_+0x04)
#define _sf_    (_sa_+0x05)
#define _sg_    (_sa_+0x06)
#define _sh_    (_sa_+0x07)
#define _si_    (_sa_+0x08)
#define _sj_    (_sa_+0x09)
#define _sk_    (_sa_+0x0a)
#define _sl_    (_sa_+0x0b)
#define _sm_    (_sa_+0x0c)
#define _sn_    (_sa_+0x0d)
#define _so_    (_sa_+0x0e)
#define _sp_    (_sa_+0x0f)
#define _sq_    (_sa_+0x10)
#define _sr_    (_sa_+0x11)
#define _ss_    (_sa_+0x12)
#define _st_    (_sa_+0x13)
#define _su_    (_sa_+0x14)
#define _sv_    (_sa_+0x15)
#define _sw_    (_sa_+0x16)
#define _sx_    (_sa_+0x17)
#define _sy_    (_sa_+0x18)
#define _sz_    (_sa_+0x19)




#define _a_     0x40  // 粗體小寫字
#define _b_     (_a_+0x01)
#define _c_     (_a_+0x02)
#define _d_     (_a_+0x03)
#define _e_     (_a_+0x04)
#define _f_     (_a_+0x05)
#define _g_     (_a_+0x06)
#define _h_     (_a_+0x07)
#define _i_     (_a_+0x08)
#define _j_     (_a_+0x09)
#define _k_     (_a_+0x0a)
#define _l_     (_a_+0x0b)
#define _m_     (_a_+0x0c)
#define _n_     (_a_+0x0d)
#define _o_     (_a_+0x0e)
#define _p_     (_a_+0x0f)
#define _q_     (_a_+0x10)
#define _r_     (_a_+0x11)
#define _s_     (_a_+0x12)
#define _t_     (_a_+0x13)
#define _u_     (_a_+0x14)
#define _v_     (_a_+0x15)
#define _w_     (_a_+0x16)
#define _x_     (_a_+0x17)
#define _y_     (_a_+0x18)
#define _z_     (_a_+0x19)

#define _A_     0x5A // 粗體大寫字
#define _B_     (_A_+0x01)
#define _C_     (_A_+0x02)
#define _D_     (_A_+0x03)
#define _E_     (_A_+0x04)
#define _F_     (_A_+0x05)
#define _G_     (_A_+0x06)
#define _H_     (_A_+0x07)
#define _I_     (_A_+0x08)
#define _J_     (_A_+0x09)
#define _K_     (_A_+0x0a)
#define _L_     (_A_+0x0b)
#define _M_     (_A_+0x0c)
#define _N_     (_A_+0x0d)
#define _O_     (_A_+0x0e)
#define _P_     (_A_+0x0f)
#define _Q_     (_A_+0x10)
#define _R_     (_A_+0x11)
#define _S_     (_A_+0x12)
#define _T_     (_A_+0x13)
#define _U_     (_A_+0x14)
#define _V_     (_A_+0x15)
#define _W_     (_A_+0x16)
#define _X_     (_A_+0x17)
#define _Y_     (_A_+0x18)
#define _Z_     (_A_+0x19)


#define _ba_    _a_      
#define _bb_    _b_  
#define _bc_    _c_  
#define _bd_    _d_  
#define _be_    _e_  
#define _bf_    _f_  
#define _bg_    _g_  
#define _bh_    _h_  
#define _bi_    _i_  
#define _bj_    _j_  
#define _bk_    _k_  
#define _bl_    _l_  
#define _bm_    _m_  
#define _bn_    _n_  
#define _bo_    _o_  
#define _bp_    _p_  
#define _bq_    _q_  
#define _br_    _r_  
#define _bs_    _s_  
#define _bt_    _t_  
#define _bu_    _u_  
#define _bv_    _v_  
#define _bw_    _w_  
#define _bx_    _x_  
#define _by_    _y_  
#define _bz_    _z_  

#define _bA_    _A_  
#define _bB_    _B_  
#define _bC_    _C_  
#define _bD_    _D_  
#define _bE_    _E_  
#define _bF_    _F_  
#define _bG_    _G_  
#define _bH_    _H_  
#define _bI_    _I_  
#define _bJ_    _J_  
#define _bK_    _K_  
#define _bL_    _L_  
#define _bM_    _M_  
#define _bN_    _N_  
#define _bO_    _O_  
#define _bP_    _P_  
#define _bQ_    _Q_  
#define _bR_    _R_  
#define _bS_    _S_  
#define _bT_    _T_  
#define _bU_    _U_  
#define _bV_    _V_  
#define _bW_    _W_ 
#define _bX_    _X_  
#define _bY_    _Y_  
#define _bZ_    _Z_  


#define _sA_    0x74   // subitem 說明文字第二排大寫
#define _sB_    (_sA_+0x01)
#define _sC_    (_sA_+0x02)
#define _sD_    (_sA_+0x03)
#define _sE_    (_sA_+0x04)
#define _sF_    (_sA_+0x05)
#define _sG_    (_sA_+0x06)
#define _sH_    (_sA_+0x07)
#define _sI_    (_sA_+0x08)
#define _sJ_    (_sA_+0x09)
#define _sK_    (_sA_+0x0a)
#define _sL_    (_sA_+0x0b)
#define _sM_    (_sA_+0x0c)
#define _sN_    (_sA_+0x0d)
#define _sO_    (_sA_+0x0e)
#define _sP_    (_sA_+0x0f)
#define _sQ_    (_sA_+0x10)
#define _sR_    (_sA_+0x11)
#define _sS_    (_sA_+0x12)
#define _sT_    (_sA_+0x13)
#define _sU_    (_sA_+0x14)
#define _sV_    (_sA_+0x15)
#define _sW_    (_sA_+0x16)
#define _sX_    (_sA_+0x17)
#define _sY_    (_sA_+0x18)
#define _sZ_    (_sA_+0x19)

#define _mA_    0x8E // subitem 說明文字第一排大寫
#define _mB_    (_mA_+0x01)
#define _mC_    (_mA_+0x02)
#define _mD_    (_mA_+0x03)
#define _mE_    (_mA_+0x04)
#define _mF_    (_mA_+0x05)
#define _mG_    (_mA_+0x06)
#define _mH_    (_mA_+0x07)
#define _mI_    (_mA_+0x08)
#define _mJ_    (_mA_+0x09)
#define _mK_    (_mA_+0x0a)
#define _mL_    (_mA_+0x0b)
#define _mM_    (_mA_+0x0c)
#define _mN_    (_mA_+0x0d)
#define _mO_    (_mA_+0x0e)
#define _mP_    (_mA_+0x0f)
#define _mQ_    (_mA_+0x10)
#define _mR_    (_mA_+0x11)
#define _mS_    (_mA_+0x12)
#define _mT_    (_mA_+0x13)
#define _mU_    (_mA_+0x14)
#define _mV_    (_mA_+0x15)
#define _mW_    (_mA_+0x16)
#define _mX_    (_mA_+0x17)
#define _mY_    (_mA_+0x18)
#define _mZ_    (_mA_+0x19)

#define _ma_    0xA8  // subitem 說明文字第一排小寫
#define _mb_    (_ma_+0x01)
#define _mc_    (_ma_+0x02)
#define _md_    (_ma_+0x03)
#define _me_    (_ma_+0x04)
#define _mf_    (_ma_+0x05)
#define _mg_    (_ma_+0x06)
#define _mh_    (_ma_+0x07)
#define _mi_    (_ma_+0x08)
#define _mj_    (_ma_+0x09)
#define _mk_    (_ma_+0x0a)
#define _ml_    (_ma_+0x0b)
#define _mm_    (_ma_+0x0c)
#define _mn_    (_ma_+0x0d)
#define _mo_    (_ma_+0x0e)
#define _mp_    (_ma_+0x0f)
#define _mq_    (_ma_+0x10)
#define _mr_    (_ma_+0x11)
#define _ms_    (_ma_+0x12)
#define _mt_    (_ma_+0x13)
#define _mu_    (_ma_+0x14)
#define _mv_    (_ma_+0x15)
#define _mw_    (_ma_+0x16)
#define _mx_    (_ma_+0x17)
#define _my_    (_ma_+0x18)
#define _mz_    (_ma_+0x19)




#define _EU_0D  0x0D
#define _EU_0E  0x0E
#define _EU_0F  0x0F
  
#define _EU_1A  0x1A
#define _EU_1B  0x1B
#define _EU_1C  0x1C
#define _EU_1D  0x1D
#define _EU_1E  0x1E
#define _EU_1F  0x1F
 
#define _EU_3A  0x3A
#define _EU_3B  0x3B
#define _EU_3C  0x3C
#define _EU_3D  0x3D
#define _EU_3E  0x3E
#define _EU_3F  0x3F

#define _EU_C2  0xC2
#define _EU_C3  0xC3
#define _EU_C4  0xC4
#define _EU_C5  0xC5
#define _EU_C6  0xC6
#define _EU_C7  0xC7
#define _EU_C8  0xC8
#define _EU_C9  0xC9
#define _EU_CA  0xCA
#define _EU_CB  0xCB
#define _EU_CC  0xCC
#define _EU_CD  0xCD
#define _EU_CE  0xCE
#define _EU_CF  0xCF
 
#define _EU_D0  0xD0
#define _EU_D1  0xD1
#define _EU_D2  0xD2
#define _EU_D3  0xD3
#define _EU_D4  0xD4
#define _EU_D5  0xD5
#define _EU_D6  0xD6
#define _EU_D7  0xD7
#define _EU_D8  0xD8
#define _EU_D9  0xD9

#define _EU_E5  0xE5




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
extern WORD xdata g_usAdjustValue0;
extern WORD xdata g_usAdjustValue1;
extern WORD xdata g_usAdjustValue2;
#endif

#ifndef __RTD_OSDFUNC__
extern WORD xdata g_usFontSelectStart;
extern WORD xdata g_usFontTableStart;
extern BYTE xdata g_ucOsdWidth;
extern BYTE xdata g_ucOsdHeight;
extern BYTE xdata g_ucOsdMap;
extern BYTE xdata g_ucOsdFlyH;
extern BYTE xdata g_ucOsdFlyV;
extern BYTE xdata g_ucOsdFlyState;
extern BYTE g_ucFontPointer0;
extern BYTE g_ucFontPointer1;
extern BYTE g_ucFontPointer2;
#endif
//----------------------------------------------------------------------------------------
// Extern Tables from RTDOsdFont.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDFONT__
#endif

//----------------------------------------------------------------------------------------
// Extern Tables from RTDOsdTable.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDTABLE__
extern BYTE code tOSD_WIN_TYPE0[];
extern BYTE code tOSD_WIN_TYPE1[];

/*
extern BYTE code tOSD_iPICTURE[];
extern BYTE code tOSD_iPOSITION[];
extern BYTE code tOSD_iSETUP[];
extern BYTE code tOSD_iPROPERTIES[];
extern BYTE code tOSD_iOPTION[];
extern BYTE code tOSD_iEXIT[];
*/
extern BYTE code tOSD_iBACK[];
extern BYTE code tOSD_iLEFT[];
extern BYTE code tOSD_iRIGHT[];
extern BYTE code tOSD_iOK[];


extern BYTE code tOSD_2iKEYITEM1[];
extern BYTE code tOSD_2iKEYITEM2[];
extern BYTE code tOSD_2iKEYITEM3[];
extern BYTE code tOSD_2iKEYITEM4[];


//Eli 20120823 modify osd icon.
//==============================
extern BYTE code tOSD_2iPICTURE[];
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
extern BYTE code tOSD_2iLOWBLUELIGHT[];
#endif    
extern BYTE code tOSD_2iPOSITION[];
extern BYTE code tOSD_2iSETUP[];
extern BYTE code tOSD_2iPROPERTIES[];
extern BYTE code tOSD_2iOPTION[];
extern BYTE code tOSD_2iEXIT[];


//============================
// sub page:
//============================
extern BYTE code tOSD_2i_SUB_PICTURE[];
extern BYTE code tOSD_2i_SUB_POSITION[];
extern BYTE code tOSD_2i_SUB_MANUAL[];
extern BYTE code tOSD_2i_SUB_COLOR[];
extern BYTE code tOSD_2i_SUB_INFORMATION[];

extern BYTE code tOSD_2i_BRIGHTNESS_SUB[];
extern BYTE code tOSD_2i_CONTRAST_SUB[];

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
extern BYTE code tOSD_2i_LOWBLUELIGHT_ENABLE[];
extern BYTE code tOSD_2i_LOWBLUELIGHT_DISABLE[];

extern BYTE code tOSD_LBL_HOTKEY_ICO_ENABLE[];
extern BYTE code tOSD_LBL_HOTKEY_ICO_DISABLE[];
#endif    

#if(_LENOVO_DPS_SUPPORT == _ON)
extern BYTE code tOSD_2i_DPS_SUB[];
extern BYTE code tOSD_2i_DPS_H[];
extern BYTE code tOSD_sDPS[];
extern BYTE code tOSD_sDPS_COLON[];
extern BYTE code tOSD_sDPS_EXPLAIN1[];
#endif
#if(_USER_DCR_FUNCTION == _ON)
extern BYTE code tOSD_2i_DCR_SUB[];
extern BYTE code tOSD_2i_DCR_H[];
extern BYTE code tOSD_sDCR[];
extern BYTE code tOSD_sDCR_COLON[];
extern BYTE code tOSD_sDCR_EXPLAIN1[];
#endif
extern BYTE code tOSD_2i_HPOS_SUB[];
extern BYTE code tOSD_2i_VPOS_SUB[];
extern BYTE code tOSD_2i_AUTOMATIC_SUB[];
extern BYTE code tOSD_2i_MANUAL_SUB[];
extern BYTE code tOSD_2i_COLOR_SUB[];
extern BYTE code tOSD_2i_INPUT_SUB[];
extern BYTE code tOSD_2i_SCALING_SUB[];
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
extern BYTE code tOSD_2i_BLUELIGHT_SUB[];
#endif
#if(_OD_SUPPORT==_ON)			
extern BYTE code tOSD_2i_OD_SUB[];
extern BYTE code tOSD_2i_OD_H[];
#endif
extern BYTE code tOSD_2i_INFORMATION_SUB[];
extern BYTE code tOSD_2i_LANGUAGE_SUB[];
extern BYTE code tOSD_2i_OSDPOS_SUB[];
extern BYTE code tOSD_2i_RESET_SUB[];
extern BYTE code tOSD_2i_ACCESSIBILITY_SUB[];
extern BYTE code tOSD_2i_BUTTON_REPEAT_SUB[];
extern BYTE code tOSD_2i_MENU_TIMEOUT_SUB[];
extern BYTE code tOSD_2i_VGA_SUB[];
extern BYTE code tOSD_2i_DVI_SUB[] ;
extern BYTE code tOSD_2i_BRIGHTNESS_L[];
extern BYTE code tOSD_2i_BRIGHTNESS_R[];
extern BYTE code tOSD_2i_CONTRAST_L[];
extern BYTE code tOSD_2i_CONTRAST_R[];
extern BYTE code tOSD_2i_HPOS_L[];
extern BYTE code tOSD_2i_HPOS_R[];
extern BYTE code tOSD_2i_VPOS_L[];
extern BYTE code tOSD_2i_VPOS_R[];
extern BYTE code tOSD_2i_BRIGHTNESS_H[];
extern BYTE code tOSD_2i_CONTRAST_H[];
extern BYTE code tOSD_2i_HPOS_H[];
extern BYTE code tOSD_2i_VPOS_H[];
extern BYTE code tOSD_2i_MANUAL_H[];
extern BYTE code tOSD_2i_COLOR_H[];
extern BYTE code tOSD_2i_SCALING_H[];
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
extern BYTE code tOSD_2i_BLUELIGHT[];
#endif
extern BYTE code tOSD_2i_INFORMATION_H[];
extern BYTE code tOSD_2i_LANGUAGE_H[];
extern BYTE code tOSD_2i_OSDPOS_H[];
extern BYTE code tOSD_2i_RESET_H[];
extern BYTE code tOSD_2i_ACCESSIBILITY_H[];
extern BYTE code tOSD_2i_INPUT_H[];
extern BYTE code tOSD_2i_OSDHPOS_L[];
extern BYTE code tOSD_2i_OSDHPOS_R[];
extern BYTE code tOSD_2i_OSDVPOS_L[];
extern BYTE code tOSD_2i_OSDVPOS_R[];
extern BYTE code tOSD_2iSliderBar[];
extern BYTE code tOSD_2iSliderX[101][4];


/*
//===============================
extern BYTE code tOSD_2i_BRIGHTNESS[];
extern BYTE code tOSD_2i_CONTRAST[];
extern BYTE code tOSD_2i_HPOS[];
extern BYTE code tOSD_2i_VPOS[];

extern BYTE code tOSD_2i_AUTOMATIC[];
extern BYTE code tOSD_2i_MANUAL[];
extern BYTE code tOSD_2i_COLOR[];
extern BYTE code tOSD_2i_INPUT[];
extern BYTE code tOSD_2i_SCALING[];
extern BYTE code tOSD_2i_INFORMATION[];
extern BYTE code tOSD_2i_LANGUAGE[];
extern BYTE code tOSD_2i_OSDPOS[];
extern BYTE code tOSD_2i_RESET[];
extern BYTE code tOSD_2i_ACCESSIBILITY[];
extern BYTE code tOSD_2i_BUTTON_REPEAT[];
extern BYTE code tOSD_2i_MENU_TIMEOUT[]; 
extern BYTE code tOSD_2i_VGA[];
extern BYTE code tOSD_2i_DVI[];
*/


extern BYTE code tOSD_CHARWIDTH_CHINA_0[];
extern BYTE code tOSD_CHARWIDTH_CHINA_BIG_TEXT[];
extern BYTE code tOSD_CHARWIDTH_JAPAN_0[];
extern BYTE code tOSD_CHARWIDTH_JAPAN_BIG1[];
extern BYTE code tOSD_CHARWIDTH_JAPAN_BIG2[];
extern BYTE code tOSD_CHARWIDTH_RUSSIAN[];
extern BYTE code tOSD_CHARWIDTH_LATIN[];

extern BYTE code tOSD_sEXITKEY[]; 
extern BYTE code tOSD_sCANCELKEY[];
extern BYTE code tOSD_sOKKEY[];
extern BYTE code tOSD_sBRIGHTNESS_CONTRAST[];
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
extern BYTE code tOSD_sLOWBLUELIGHT[];
extern BYTE code tOSD_sLOWBLUELIGHT_ENABLE[];
extern BYTE code tOSD_sLOWBLUELIGHT_DISABLE[];
#endif    

extern BYTE code tOSD_sIMAGE_POSITION[];
extern BYTE code tOSD_sIMAGE_SETUP[];
extern BYTE code tOSD_sIMAGE_PROPERTIES[];
extern BYTE code tOSD_sOPTIONS[];
extern BYTE code tOSD_sEXIT[];
extern BYTE code tOSD_sFACTORY_MODE[];
extern BYTE code tOSD_sBRIGHTNESS[];
extern BYTE code tOSD_sCONTRAST[];
extern BYTE code tOSD_sHPOS[]; 
extern BYTE code tOSD_sVPOS[]; 
extern BYTE code tOSD_sMANUAL[]; 
extern BYTE code tOSD_sCOLOR[];
extern BYTE code tOSD_sINPUT[];
extern BYTE code tOSD_sINFORMATION[];
extern BYTE code tOSD_sLANGUAGE[];
extern BYTE code tOSD_sOSDPOS[];
extern BYTE code tOSD_sFACTORY_DEFAULT[];
extern BYTE code tOSD_sSCALING[];
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
extern BYTE code tOSD_sBLUELIGHT[];
#endif
#if(_OD_SUPPORT==_ON)			
extern BYTE code tOSD_sOD[];
extern BYTE code tOSD_sOD_COLON[];
extern BYTE code tOSD_sOD_EXPLAIN[];
#endif    
extern BYTE code tOSD_sACCESSIBILITY[];
extern BYTE code tOSD_sBRIGHTNESS_COLON[];
extern BYTE code tOSD_sCONTRAST_COLON[];
extern BYTE code tOSD_sHPOS_COLON[]; 
extern BYTE code tOSD_sVPOS_COLON[]; 
extern BYTE code tOSD_sAUTOMATIC_COLON[];
extern BYTE code tOSD_sMANUAL_COLON[];
extern BYTE code tOSD_sCOLOR_COLON[];
extern BYTE code tOSD_sINPUT_COLON[];
extern BYTE code tOSD_sSCALING_COLON[];
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
extern BYTE code tOSD_sBLUELIGHT_COLON[];
#endif
extern BYTE code tOSD_sINFORMATION_COLON[];
extern BYTE code tOSD_sLANGUAGE_COLON[];
extern BYTE code tOSD_sOSDPOS_COLON[];
extern BYTE code tOSD_sFACTORY_DEFAULT_COLON[];
extern BYTE code tOSD_sACCESSIBILITY_COLON[];
extern BYTE code tOSD_sBRIGHTNESS_EXPLAIN[];
extern BYTE code tOSD_sCONTRAST_EXPLAIN1[];
extern BYTE code tOSD_sHPOS_EXPLAIN[];
extern BYTE code tOSD_sVPOS_EXPLAIN[];
extern BYTE code tOSD_sAUTOMATIC_EXPLAIN1[];
extern BYTE code tOSD_sMANUAL_EXPLAIN1[];
extern BYTE code tOSD_sCOLOR_EXPLAIN[];
extern BYTE code tOSD_sINPUT_EXPLAIN[];
extern BYTE code tOSD_sSCALING_EXPLAIN[];
extern BYTE code tOSD_sSCALING_OFF_EXPLAIN1[];
extern BYTE code tOSD_sSCALING_OFF_EXPLAIN2[];
extern BYTE code tOSD_sSCALING_ON_EXPLAIN[];
extern BYTE code tOSD_sINFORMATION_EXPLAIN1[];
extern BYTE code tOSD_sINFORMATION_EXPLAIN2[];
extern BYTE code tOSD_sLANGUAGE_EXPLAIN[];
extern BYTE code tOSD_sOSDPOS_EXPLAIN[];
extern BYTE code tOSD_sFACTORY_DEFAULT_EXPLAIN1[];
extern BYTE code tOSD_sFACTORY_DEFAULT_EXPLAIN2[];
extern BYTE code tOSD_sACCESSIBILITY_EXPLAIN1[];
extern BYTE code tOSD_sACCESSIBILITY_EXPLAIN2[];
extern BYTE code tOSD_sCLOCK[];
extern BYTE code tOSD_sPHASE[];
extern BYTE code tOSD_sSAVE[];
extern BYTE code tOSD_sPRESET[];
extern BYTE code tOSD_sCUSTOM[];
extern BYTE code tOSD_sNEUTRAL[];
extern BYTE code tOSD_sSRGB[];
extern BYTE code tOSD_sREDDISH[];
extern BYTE code tOSD_sBLUISH[];
extern BYTE code tOSD_sRED[];
extern BYTE code tOSD_sGREEN[];
extern BYTE code tOSD_sBLUE[];
extern BYTE code tOSD_sANALOG[];
extern BYTE code tOSD_sDVI[];
extern BYTE code tOSD_sSCALING_OFF[];
extern BYTE code tOSD_sSCALING_ON[];
extern BYTE code tOSD_sENGLISH[];
extern BYTE code tOSD_sFRENCH[];
extern BYTE code tOSD_sITALIAN[];
extern BYTE code tOSD_sCHINESE_S[];
extern BYTE code tOSD_sSPANISH[];
extern BYTE code tOSD_sJAPAN[];
extern BYTE code tOSD_sGERMAN[];
extern BYTE code tOSD_sRUSSIAN[];
extern BYTE code tOSD_sMODE[];
extern BYTE code tOSD_sMODE_NAME[];
extern BYTE code tOSD_scMODE_NAME[];
extern BYTE code tOSD_sMICROCODE[];
extern BYTE code tOSD_scMICROCODE[];
extern BYTE code tOSD_sDEFAULT[];
extern BYTE code tOSD_sOSDPOSITIONCUSTOM[];
extern BYTE code tOSD_sOSDHPOS[];
extern BYTE code tOSD_sOSDVPOS[];
extern BYTE code tOSD_sOSDPOSITIONSAVE[];
extern BYTE code tOSD_sCANCEL[]; 
extern BYTE code tOSD_sRESET[]; 
extern BYTE code tOSD_sBUTTON_REPEAT[];
extern BYTE code tOSD_sMENU_TIMEOUT[];
#if((_LENOVO_DPS_SUPPORT == _ON) || (_OD_SUPPORT == _ON)||(_USER_DCR_FUNCTION == _ON))
extern BYTE code tOSD_sON[];
#endif
extern BYTE code tOSD_sOFF[];
extern BYTE code tOSD_sBTNDEFAULT[];
extern BYTE code tOSD_sSLOW[];
extern BYTE code tOSD_sAUTOADJUST_0[];
extern BYTE code tOSD_sAUTOADJUST_1[];
extern BYTE code tOSD_sMENU_LOCK[];
extern BYTE code tOSD_sMENU_UNLOCK[];
extern BYTE code tOSD_sDDCCI_ON[];
extern BYTE code tOSD_sDDCCI_OFF[];
extern BYTE code tOSD_sPOWER_SAVING[];
extern BYTE code tOSD_sNOCABLE_0[];
extern BYTE code tOSD_sNOCABLE_1[];
extern BYTE code tOSD_sOOR_0[];
extern BYTE code tOSD_sOOR_1[];
extern BYTE code tOSD_sBTNSlider_L[];
extern BYTE code tOSD_sBTNSlider_R[];


extern BYTE OsdGetTableValue(BYTE value, BYTE num);


#endif


//----------------------------------------------------------------------------------------
// Extern Tables from RTDOsdACTIONFLOW.c
//----------------------------------------------------------------------------------------
//#ifndef __RTD_OSDACTIONFLOW__
//code void (*OperationTable[][4])(void);
//#endif

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
extern void RTDKeyInitial(void);
extern void TPVKeyIntoFactory(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from RTDOsd.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSD__
extern void OsdReset(void);
extern void OsdTimeoutSaveData(void);//Eli 20121001 modify bug T9CGT478FEG3HN-74,T9CGT478FEG3HN-77.
#endif


//----------------------------------------------------------------------------------------
// Extern functions from RTDOsdFunc.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDFUNC__
extern void OsdFuncDisableOsd(void);
extern void OsdFuncEnableOsd(void);
extern void OsdFuncApplyMap(BYTE ucOsdMap, BYTE ucColor);
extern WORD OsdFuncGetAddr(BYTE ucOsdMap, BYTE ucRow, BYTE ucCol);
extern void OsdFuncSet2BitIconOffset(BYTE ucOffset);
extern void OsdFuncSetBlending(BYTE ucType);
extern void OsdFuncSetTransparency(BYTE ucTrans);
extern void OsdFuncSetPosition(BYTE ucType, WORD usX, WORD usY);
extern void OsdFuncPutChar(BYTE ucRow, BYTE ucCol, BYTE ucChar, BYTE ucColor, BYTE ucAttribute);
extern void OsdFuncPutCharSeries(BYTE ucRow, BYTE ucCol, BYTE ucChar, BYTE ucColor, BYTE ucAttribute, BYTE ucLength);
//extern void OsdFuncPutString(BYTE ucRow, BYTE ucCol, BYTE ucLanguage, BYTE *pArray, BYTE ucColor, BYTE ucAttribute);
extern void OsdFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFontTabSelect, BYTE *pArray, BYTE ucLanguage, BYTE ucColor);
extern void OsdFuncPutStringPropCenter(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucFontTabSelect, BYTE *pArray, BYTE ucLanguage, BYTE ucColor);
extern void OsdFuncPutStringPropAlignRight(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucFontTabSelect, BYTE *pArray, BYTE ucLanguage, BYTE ucColor);


extern WORD OsdFuncGetStringLength(BYTE *pArray, BYTE ucLanguage);

extern void OsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucColor);
extern void OsdFuncPutIcon2Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
extern void OsdFuncPutIcon2BitTable(BYTE ucRow, BYTE ucCol, BYTE *pArray, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
extern void OsdFuncDrawWindow(BYTE ucWin, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE *pArray);
#if((_LOGO_TYPE == _IBM_THINKVISION_LENOVO) && (_EPA_LOGO == _ON))
extern void OsdFuncDrawWindowPixel(BYTE ucWin, WORD usHstart, WORD usVstart, WORD usHend, WORD usVend, BYTE ucColor, BYTE *pArray);
#endif
extern void OsdFuncCloseWindow(BYTE ucIndex);

extern BYTE RTDOsdFuncGetOsdFontPointer(BYTE ucPointerSelect);
extern BYTE RTDOsdFuncSetOsdFontPointer(BYTE ucPointerSelect,BYTE ucPointer);
extern BYTE OsdFuncSetOsdFontPointer(BYTE ucPointerSelect,BYTE ucPointer);
extern BYTE OsdFuncGetOsdFontPointer(BYTE ucPointerSelect);

#endif


//----------------------------------------------------------------------------------------
// Extern functions from RTDOsdDisplay.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDDISPLAY__
extern void OsdDispDisableOsdTimerEvent(void);
extern void OsdDispMainIcon(void);
extern void OsdDispKeyInfo(BYTE ucState);
extern void OsdDispSubStringClear(void);
extern void OsdDispMainStringClear(void);
extern void OsdDispSubTitleStringClear(void);
extern void OsdDispMainMenuString(BYTE ucState);
extern void OsdDispMainIconDraw(BYTE ucItem, BYTE ucState);
extern void OsdDispMainIconChange(BYTE ucItem, BYTE ucState);
extern void OsdDispMainIconSwitch(void);
extern void OsdDispSubIcon(BYTE ucItem, BYTE ucState);
extern void OsdDispSubItem(BYTE ucItem, BYTE ucState);
extern void OsdDispDrawSlider(BYTE ucRow, BYTE ucColor, BYTE ucPercent, BYTE ucState);
extern void OsdDispDrawNumber(BYTE ucRow, BYTE ucCol, WORD usValue, BYTE ucLength, BYTE ucColor, BYTE ucAlign, BYTE ucFptsSelect);
extern void OsdDispSlider(BYTE ucState);
extern void OsdDispContentClear();
extern void OsdDispContent(BYTE ucState);
extern void OsdDispMainMenu(BYTE ucState);
extern void OsdDispBriHotkeyMenu(void);
extern BYTE OsdDispJudgeSourceType(void);   //20120730 Abel add
extern void OsdDispShowLogo(void);          //20120731 Abel add
extern void OsdDispLanguageSelect(BYTE ucLanguage);
extern void OsdDispLanguagePage(BYTE ucLanguage);
extern void OsdDispInformationPage(void);
extern void OsdDispMessage(BYTE ucState);
//extern void OsdDispInputInfo(void);  // EasonLee Modify
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
extern void OsdDisplayLowBlueLightHotKeyMsg(void);
#endif
extern void OsdDispTimingAndInputSource(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from RTDOsdFont.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDFONT__
extern void OsdLoadFont(BYTE ucState);
extern void OsdLoadPalette(BYTE ucState);
#endif

#endif//#if(_OSD_TYPE == _LEONVO_GREEN_OSD)
