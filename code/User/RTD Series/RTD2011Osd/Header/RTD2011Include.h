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

#include "RTD2011Project.h"
#include "RTD2011NVRamOsd.h"

#if(_OSD_TYPE == _REALTEK_2011_OSD)

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
#define _CONTRAST_MAX                               178
#define _CONTRAST_MIN                               78
#define _CONTRAST_CENTER                            (((_CONTRAST_MAX - _CONTRAST_MIN) / 2) + _CONTRAST_MIN)

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
// Definitions of OSD V Position Range
//--------------------------------------------------
#define _OSD_ASPECT_ORIGINAL_RATIO_MAX              100
#define _OSD_ASPECT_ORIGINAL_RATIO_MIN              0
#define _OSD_ASPECT_ORIGINAL_RATIO_CENTER           ((_OSD_ASPECT_ORIGINAL_RATIO_MAX - _OSD_ASPECT_ORIGINAL_RATIO_MIN) / 2)

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
#define _OSD_MAP0                                   0
#define _OSD_MAP1                                   1
#define _OSD_MAP2                                   2
#define _OSD_MAP3                                   3
#define _OSD_MAP4                                   4
#define _OSD_MAP5                                   5
#define _OSD_LOGO_MAP                               6


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

//--------------------------------------------------
// MACRO for 3D Effect Real Value
//--------------------------------------------------
#define GET_OSD_3D_EFFECT_REAL_VALUE()              (g_stOsdInfo.ucOsd3DEffectRealValue)
#define SET_OSD_3D_EFFECT_REAL_VALUE(x)             (g_stOsdInfo.ucOsd3DEffectRealValue = (x))


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
// Macro of Aspect Origin Ratio
//--------------------------------------------------
#define GET_OSD_ASPECT_ORIGIN_RATIO()               (g_stOSDUserData.ucAspectOriginRatio)
#define SET_OSD_ASPECT_ORIGIN_RATIO(x)              (g_stOSDUserData.ucAspectOriginRatio = (x))

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
// MACRO for OsdVPos
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
// MACRO for Energy Star Status
//--------------------------------------------------
#define GET_OSD_ES_STATUS()                        (g_stOSDUserData.b1OsdESStatus)
#define SET_OSD_ES_STATUS(x)                       (g_stOSDUserData.b1OsdESStatus = (x))

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
// MACRO for Auto-Color Type
//--------------------------------------------------
#define _AUTO_COLOR_TYPE_INTERNAL                   0
#define _AUTO_COLOR_TYPE_EXTERNAL                   1

#define GET_OSD_FACTORY_AUTO_COLOR_TYPE()           (g_stOSDUserData.b1FactoryAutoColorType)
#define SET_OSD_FACTORY_AUTO_COLOR_TYPE(x)          (g_stOSDUserData.b1FactoryAutoColorType = (x))

//--------------------------------------------------
// MACRO for PCM Status
//--------------------------------------------------
#define GET_OSD_PCM_STATUS()                        (g_stOSDUserData.b2PCMStatus)
#define SET_OSD_PCM_STATUS(x)                       (g_stOSDUserData.b2PCMStatus = (x))

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
// Definitions of OSD
//--------------------------------------------------
#define _PFONT_PAGE_0                               0
#define _PFONT_PAGE_1                               1
#define _PFONT_PAGE_2                               2
#define _PFONT_PAGE_ITEM_1                          3
#define _PFONT_PAGE_ITEM_2                          4
#define _PFONT_PAGE_ITEM_3                          5
#define _PFONT_PAGE_ITEM_4                          6
#define _PFONT_PAGE_ITEM_5                          7
#define _PFONT_PAGE_ITEM_6                          8
#define _PFONT_PAGE_ITEM_7                          9
#define _PFONT_PAGE_ITEM_8                          10

#define _OSD_GLOBAL_START                           0x01
#define _OSD_GLOBAL_END                             0x0F

#define _OSD_PAGE_0_START                           0x29
#define _OSD_PAGE_0_END                             0x90

#define _OSD_PAGE_1_START                           0x91
#define _OSD_PAGE_1_END                             0xC0

#define _OSD_PAGE_2_START                           0xC1
#define _OSD_PAGE_2_END                             0xF0

#define _SUB_PAGE_ITEM_1                            (_OSD_PAGE_2_START)
#define _SUB_PAGE_ITEM_1_END                        (_OSD_PAGE_2_START + 6)
#define _SUB_PAGE_ITEM_2                            (_SUB_PAGE_ITEM_1_END)
#define _SUB_PAGE_ITEM_2_END                        (_SUB_PAGE_ITEM_1_END + 6)
#define _SUB_PAGE_ITEM_3                            (_SUB_PAGE_ITEM_2_END)
#define _SUB_PAGE_ITEM_3_END                        (_SUB_PAGE_ITEM_2_END + 10)
#define _SUB_PAGE_ITEM_4                            (_SUB_PAGE_ITEM_3_END)
#define _SUB_PAGE_ITEM_4_END                        (_SUB_PAGE_ITEM_3_END + 5)
#define _SUB_PAGE_ITEM_5                            (_SUB_PAGE_ITEM_4_END)
#define _SUB_PAGE_ITEM_5_END                        (_SUB_PAGE_ITEM_4_END + 6)
#define _SUB_PAGE_ITEM_6                            (_SUB_PAGE_ITEM_5_END)
#define _SUB_PAGE_ITEM_6_END                        (_SUB_PAGE_ITEM_5_END + 8)
#define _SUB_PAGE_ITEM_7                            (_SUB_PAGE_ITEM_6_END)
#define _SUB_PAGE_ITEM_7_END                        (_SUB_PAGE_ITEM_6_END + 6)
#define _SUB_PAGE_ITEM_8                            (_SUB_PAGE_ITEM_7_END) 
#define _SUB_PAGE_ITEM_8_END                        (_SUB_PAGE_ITEM_7_END + 6)

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

#define _WIN0_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#if(_OSD_3D_FUNCTION == _ON)
#define _WIN0_BORDER_COLOR                          ((_CP_GRAY << 4) | _CP_GRAY)
#else
#define _WIN0_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#endif
#define _WIN0_FUNC_CONTROL                          (_BLEND_ENABLE | _GRADIENT_DISABLE | _GRADIENT_DIRECTION_H | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN0_GRADIENT_CONTROL0                     (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_3 | _R_GRADIENT_INC | _G_GRADIENT_INC | _B_GRADIENT_INC)
#define _WIN0_GRADIENT_CONTROL1                     (_3_LEVEL_RER_GRADIENT)

#define _WIN0_ROTATE_BORDER_PIXEL                   (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN0_ROTATE_BORDER_COLOR                   ((_CP_DARKBLUE << 4)  |_CP_DARKBLUE)
#define _WIN0_ROTATE_FUNC_CONTROL                   (_BLEND_ENABLE | _GRADIENT_ENABLE | _GRADIENT_DIRECTION_V | _BORDER_ENABLE | _SHADOW_3)
#define _WIN0_ROTATE_GRADIENT_CONTROL0              (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_4 | _R_GRADIENT_DEC | _G_GRADIENT_DEC | _B_GRADIENT_DEC)
#define _WIN0_ROTATE_GRADIENT_CONTROL1              (_3_LEVEL_RER_GRADIENT)

#define _WIN1_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#if(_OSD_3D_FUNCTION == _ON)
#define _WIN1_BORDER_COLOR                          ((_CP_GRAY << 4) | _CP_GRAY)
#else
#define _WIN1_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#endif
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

#if(_OSD_3D_FUNCTION == _ON)
#define _WIN5_BORDER_PIXEL                          (_BORDER0_1_PIXEL | _BORDER1_1_PIXEL)
#define _WIN5_BORDER_COLOR                          ((_CP_SELECTBLUE << 4) | _CP_SELECTBLUE)
#define _WIN5_FUNC_CONTROL                          (_BLEND_DISABLE | _GRADIENT_ENABLE | _GRADIENT_DIRECTION_V | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN5_GRADIENT_CONTROL0                     (_R_GRADIENT_ENABLE | _G_GRADIENT_ENABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_1 | _R_GRADIENT_DEC | _G_GRADIENT_DEC | _B_GRADIENT_DEC)
#define _WIN5_GRADIENT_CONTROL1                     (_8_LEVEL_RER_GRADIENT)

#define _WIN6_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN6_BORDER_COLOR                          ((_CP_SELECTBLUE << 4) | _CP_SELECTBLUE)
#define _WIN6_FUNC_CONTROL                          (_BLEND_DISABLE | _GRADIENT_ENABLE | _GRADIENT_DIRECTION_V | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN6_GRADIENT_CONTROL0                     (_R_GRADIENT_ENABLE | _G_GRADIENT_ENABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_1 | _R_GRADIENT_DEC | _G_GRADIENT_DEC | _B_GRADIENT_DEC)
#define _WIN6_GRADIENT_CONTROL1                     (_8_LEVEL_RER_GRADIENT)
#endif // End of #if(_OSD_3D_FUNCTION == _ON)

#define _WIN7_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN7_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN7_FUNC_CONTROL                          (_BLEND_ENABLE)
#define _WIN7_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN7_GRADIENT_CONTROL1                     (_DISABLE)

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

//void RTDOsdDisplayDrawWindow(BYTE ucIndex, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor, BYTE ucBorderPixel, BYTE ucBorderColor, BYTE ucWinFuncControl, BYTE ucGradientCon0, BYTE ucGradientCon1)
#define _ROTATE_WINDOW_OFFSET                       7

//void RTDOsdDisplaySetPosition(BYTE ucType, WORD usX, WORD usY)
#define _MAIN_WINDOW_SIZE_X                         336
#define _MAIN_WINDOW_SIZE_Y                         544

#define _HOTKEY_WINDOW_SIZE_X                       192
#define _HOTKEY_WINDOW_SIZE_Y                       272

#define _MESSAGE_WINDOW_SIZE_X                      240
#define _MESSAGE_WINDOW_SIZE_Y                      182

#define _LOGO_WINDOW_SIZE_X                         840
#define _LOGO_WINDOW_SIZE_Y                         176
//=========== OSD Font Icon Address ======================//
#define _1BIT_FONT_START_ADDRESS                    0x00
#define _1BIT_ICON_START                            0x02
#define _2BIT_ICON_START_ADDRESS                    0x7F
#define _2BIT_ICON_OFFSET                           0x7F
#define _2BIT_ICON_START                            0x00

//=============== 1Bit Icon ========================
#define _UP_ICON0                                   (_1BIT_ICON_START + 0)
#define _UP_ICON1                                   (_1BIT_ICON_START + 1)
#define _UP_ICON2                                   (_1BIT_ICON_START + 2)
#define _UP_ICON3                                   (_1BIT_ICON_START + 3)
#define _UP_ICON_END                                (_1BIT_ICON_START + 4)

#define _DOWN_ICON0                                 (_UP_ICON_END + 0)
#define _DOWN_ICON1                                 (_UP_ICON_END + 1)
#define _DOWN_ICON2                                 (_UP_ICON_END + 2)
#define _DOWN_ICON3                                 (_UP_ICON_END + 3)
#define _DOWN_ICON_END                              (_UP_ICON_END + 4)

#define _LEFT_ICON0                                 (_DOWN_ICON_END + 0)
#define _LEFT_ICON1                                 (_DOWN_ICON_END + 1)
#define _LEFT_ICON2                                 (_DOWN_ICON_END + 2)
#define _LEFT_ICON3                                 (_DOWN_ICON_END + 3)
#define _LEFT_ICON_END                              (_DOWN_ICON_END + 4)

#define _RIGHT_ICON0                                (_LEFT_ICON_END + 0)
#define _RIGHT_ICON1                                (_LEFT_ICON_END + 1)
#define _RIGHT_ICON2                                (_LEFT_ICON_END + 2)
#define _RIGHT_ICON3                                (_LEFT_ICON_END + 3)
#define _RIGHT_ICON_END                             (_LEFT_ICON_END + 4)

#define _MENU_ICON0                                 (_RIGHT_ICON_END + 0)
#define _MENU_ICON1                                 (_RIGHT_ICON_END + 1)
#define _MENU_ICON2                                 (_RIGHT_ICON_END + 2)
#define _MENU_ICON3                                 (_RIGHT_ICON_END + 3)
#define _MENU_ICON_END                              (_RIGHT_ICON_END + 4)

#define _EXIT_ICON0                                 (_MENU_ICON_END + 0)
#define _EXIT_ICON1                                 (_MENU_ICON_END + 1)
#define _EXIT_ICON2                                 (_MENU_ICON_END + 2)
#define _EXIT_ICON3                                 (_MENU_ICON_END + 3)
#define _EXIT_ICON_END                              (_MENU_ICON_END + 4)

#define _BAR_L                                      (_EXIT_ICON_END + 0)
#define _BAR0                                       (_EXIT_ICON_END + 1)
#define _BAR1                                       (_EXIT_ICON_END + 2)
#define _BAR2                                       (_EXIT_ICON_END + 3)
#define _BAR3                                       (_EXIT_ICON_END + 4)
#define _BAR4                                       (_EXIT_ICON_END + 5)
#define _BAR5                                       (_EXIT_ICON_END + 6)
#define _BAR6                                       (_EXIT_ICON_END + 7)
#define _BAR7                                       (_EXIT_ICON_END + 8)
#define _BAR8                                       (_EXIT_ICON_END + 9)
#define _BAR9                                       (_EXIT_ICON_END + 10)
#define _BAR10                                      (_EXIT_ICON_END + 11)
#define _BAR_R                                      (_EXIT_ICON_END + 12)
#define _BAR_END                                    (_EXIT_ICON_END + 13)
#define _BRACE_L                                    (_BAR_END)
#define _BRACE_R                                    (_BAR_END + 1)
#define _BRACE_END                                  (_BAR_END + 2)
//=============== 2Bit Icon ========================
#define _RTK_ICON0                                  (_2BIT_ICON_START + 0)
#define _RTK_ICON1                                  (_2BIT_ICON_START + 1)
#define _RTK_ICON2                                  (_2BIT_ICON_START + 2)
#define _RTK_ICON3                                  (_2BIT_ICON_START + 3)
#define _RTK_ICON4                                  (_2BIT_ICON_START + 4)
#define _RTK_ICON5                                  (_2BIT_ICON_START + 5)
#define _RTK_ICON6                                  (_2BIT_ICON_START + 6)
#define _RTK_ICON7                                  (_2BIT_ICON_START + 7)
#define _RTK_ICON8                                  (_2BIT_ICON_START + 8)
#define _RTK_ICON9                                  (_2BIT_ICON_START + 9)
#define _RTK_ICON10                                 (_2BIT_ICON_START + 10)
#define _RTK_ICON11                                 (_2BIT_ICON_START + 11)
#define _RTK_ICON12                                 (_2BIT_ICON_START + 12)
#define _RTK_ICON13                                 (_2BIT_ICON_START + 13)
#define _RTK_ICON14                                 (_2BIT_ICON_START + 14)
#define _RTK_ICON15                                 (_2BIT_ICON_START + 15)
#define _RTK_ICON16                                 (_2BIT_ICON_START + 16)
#define _RTK_ICON17                                 (_2BIT_ICON_START + 17)
#define _RTK_ICON18                                 (_2BIT_ICON_START + 18)
#define _RTK_ICON19                                 (_2BIT_ICON_START + 19)
#define _RTK_ICON20                                 (_2BIT_ICON_START + 20)
#define _RTK_ICON21                                 (_2BIT_ICON_START + 21)
#define _RTK_ICON22                                 (_2BIT_ICON_START + 22)
#define _RTK_ICON23                                 (_2BIT_ICON_START + 23)
#define _RTK_ICON24                                 (_2BIT_ICON_START + 24)
#define _RTK_ICON_END                               (_2BIT_ICON_START + 25)

#define _MAIN_MENU_2BIT_ICON_START                  (_2BIT_ICON_START + _RTK_ICON_END)

#define _PICTURE_ICON0                              (_MAIN_MENU_2BIT_ICON_START + 0)
#define _PICTURE_ICON1                              (_MAIN_MENU_2BIT_ICON_START + 1)
#define _PICTURE_ICON2                              (_MAIN_MENU_2BIT_ICON_START + 2)
#define _PICTURE_ICON3                              (_MAIN_MENU_2BIT_ICON_START + 3)
#define _PICTURE_ICON4                              (_MAIN_MENU_2BIT_ICON_START + 4)
#define _PICTURE_ICON5                              (_MAIN_MENU_2BIT_ICON_START + 5)
#define _PICTURE_ICON6                              (_MAIN_MENU_2BIT_ICON_START + 6)
#define _PICTURE_ICON7                              (_MAIN_MENU_2BIT_ICON_START + 7)
#define _PICTURE_ICON8                              (_MAIN_MENU_2BIT_ICON_START + 8)
#define _PICTURE_ICON9                              (_MAIN_MENU_2BIT_ICON_START + 9)
#define _PICTURE_ICON10                             (_MAIN_MENU_2BIT_ICON_START + 10)
#define _PICTURE_ICON11                             (_MAIN_MENU_2BIT_ICON_START + 11)
#define _PICTURE_ICON_END                           (_MAIN_MENU_2BIT_ICON_START + 12)

#define _DISPLAY_ICON0                              (_PICTURE_ICON_END + 0)
#define _DISPLAY_ICON1                              (_PICTURE_ICON_END + 1)
#define _DISPLAY_ICON2                              (_PICTURE_ICON_END + 2)
#define _DISPLAY_ICON3                              (_PICTURE_ICON_END + 3)
#define _DISPLAY_ICON4                              (_PICTURE_ICON_END + 4)
#define _DISPLAY_ICON5                              (_PICTURE_ICON_END + 5)
#define _DISPLAY_ICON6                              (_PICTURE_ICON_END + 6)
#define _DISPLAY_ICON7                              (_PICTURE_ICON_END + 7)
#define _DISPLAY_ICON8                              (_PICTURE_ICON_END + 8)
#define _DISPLAY_ICON9                              (_PICTURE_ICON_END + 9)
#define _DISPLAY_ICON10                             (_PICTURE_ICON_END + 10)
#define _DISPLAY_ICON11                             (_PICTURE_ICON_END + 11)
#define _DISPLAY_ICON_END                           (_PICTURE_ICON_END + 12)

#define _COLOR_ICON0                                (_DISPLAY_ICON_END + 0)
#define _COLOR_ICON1                                (_DISPLAY_ICON_END + 1)
#define _COLOR_ICON2                                (_DISPLAY_ICON_END + 2)
#define _COLOR_ICON3                                (_DISPLAY_ICON_END + 3)
#define _COLOR_ICON4                                (_DISPLAY_ICON_END + 4)
#define _COLOR_ICON5                                (_DISPLAY_ICON_END + 5)
#define _COLOR_ICON6                                (_DISPLAY_ICON_END + 6)
#define _COLOR_ICON7                                (_DISPLAY_ICON_END + 7)
#define _COLOR_ICON8                                (_DISPLAY_ICON_END + 8)
#define _COLOR_ICON9                                (_DISPLAY_ICON_END + 9)
#define _COLOR_ICON10                               (_DISPLAY_ICON_END + 10)
#define _COLOR_ICON11                               (_DISPLAY_ICON_END + 11)
#define _COLOR_ICON_END                             (_DISPLAY_ICON_END + 12)

#define _ADVANCE_ICON0                              (_COLOR_ICON_END + 0)
#define _ADVANCE_ICON1                              (_COLOR_ICON_END + 1)
#define _ADVANCE_ICON2                              (_COLOR_ICON_END + 2)
#define _ADVANCE_ICON3                              (_COLOR_ICON_END + 3)
#define _ADVANCE_ICON4                              (_COLOR_ICON_END + 4)
#define _ADVANCE_ICON5                              (_COLOR_ICON_END + 5)
#define _ADVANCE_ICON6                              (_COLOR_ICON_END + 6)
#define _ADVANCE_ICON7                              (_COLOR_ICON_END + 7)
#define _ADVANCE_ICON8                              (_COLOR_ICON_END + 8)
#define _ADVANCE_ICON9                              (_COLOR_ICON_END + 9)
#define _ADVANCE_ICON10                             (_COLOR_ICON_END + 10)
#define _ADVANCE_ICON11                             (_COLOR_ICON_END + 11)
#define _ADVANCE_ICON_END                           (_COLOR_ICON_END + 12)

#define _INPUT_ICON0                                (_ADVANCE_ICON_END + 0)
#define _INPUT_ICON1                                (_ADVANCE_ICON_END + 1)
#define _INPUT_ICON2                                (_ADVANCE_ICON_END + 2)
#define _INPUT_ICON3                                (_ADVANCE_ICON_END + 3)
#define _INPUT_ICON4                                (_ADVANCE_ICON_END + 4)
#define _INPUT_ICON5                                (_ADVANCE_ICON_END + 5)
#define _INPUT_ICON6                                (_ADVANCE_ICON_END + 6)
#define _INPUT_ICON7                                (_ADVANCE_ICON_END + 7)
#define _INPUT_ICON8                                (_ADVANCE_ICON_END + 8)
#define _INPUT_ICON9                                (_ADVANCE_ICON_END + 9)
#define _INPUT_ICON10                               (_ADVANCE_ICON_END + 10)
#define _INPUT_ICON11                               (_ADVANCE_ICON_END + 11)
#define _INPUT_ICON_END                             (_ADVANCE_ICON_END + 12)

#define _AUDIO_ICON0                                (_INPUT_ICON_END + 0)
#define _AUDIO_ICON1                                (_INPUT_ICON_END + 1)
#define _AUDIO_ICON2                                (_INPUT_ICON_END + 2)
#define _AUDIO_ICON3                                (_INPUT_ICON_END + 3)
#define _AUDIO_ICON4                                (_INPUT_ICON_END + 4)
#define _AUDIO_ICON5                                (_INPUT_ICON_END + 5)
#define _AUDIO_ICON6                                (_INPUT_ICON_END + 6)
#define _AUDIO_ICON7                                (_INPUT_ICON_END + 7)
#define _AUDIO_ICON8                                (_INPUT_ICON_END + 8)
#define _AUDIO_ICON9                                (_INPUT_ICON_END + 9)
#define _AUDIO_ICON10                               (_INPUT_ICON_END + 10)
#define _AUDIO_ICON11                               (_INPUT_ICON_END + 11)
#define _AUDIO_ICON_END                             (_INPUT_ICON_END + 12)

#define _OTHER_ICON0                                (_AUDIO_ICON_END + 0)
#define _OTHER_ICON1                                (_AUDIO_ICON_END + 1)
#define _OTHER_ICON2                                (_AUDIO_ICON_END + 2)
#define _OTHER_ICON3                                (_AUDIO_ICON_END + 3)
#define _OTHER_ICON4                                (_AUDIO_ICON_END + 4)
#define _OTHER_ICON5                                (_AUDIO_ICON_END + 5)
#define _OTHER_ICON6                                (_AUDIO_ICON_END + 6)
#define _OTHER_ICON7                                (_AUDIO_ICON_END + 7)
#define _OTHER_ICON8                                (_AUDIO_ICON_END + 8)
#define _OTHER_ICON9                                (_AUDIO_ICON_END + 9)
#define _OTHER_ICON10                               (_AUDIO_ICON_END + 10)
#define _OTHER_ICON11                               (_AUDIO_ICON_END + 11)
#define _OTHER_ICON_END                             (_AUDIO_ICON_END + 12)

#define _INFORMATION_ICON0                          (_OTHER_ICON_END + 0)
#define _INFORMATION_ICON1                          (_OTHER_ICON_END + 1)
#define _INFORMATION_ICON2                          (_OTHER_ICON_END + 2)
#define _INFORMATION_ICON3                          (_OTHER_ICON_END + 3)
#define _INFORMATION_ICON4                          (_OTHER_ICON_END + 4)
#define _INFORMATION_ICON5                          (_OTHER_ICON_END + 5)
#define _INFORMATION_ICON6                          (_OTHER_ICON_END + 6)
#define _INFORMATION_ICON7                          (_OTHER_ICON_END + 7)
#define _INFORMATION_ICON8                          (_OTHER_ICON_END + 8)
#define _INFORMATION_ICON9                          (_OTHER_ICON_END + 9)
#define _INFORMATION_ICON10                         (_OTHER_ICON_END + 10)
#define _INFORMATION_ICON11                         (_OTHER_ICON_END + 11)
#define _INFORMATION_ICON_END                       (_OTHER_ICON_END + 12)

#define _Logo_0x00                                  0x00
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c)
#define _Logo_0x1d                                  (_Logo_0x00 + 0x1d)
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50_End                              (_Logo_0x00 + 0x50)

#define _Logo1_0x00                                 (_Logo_0x50_End + 0x00)
#define _Logo1_0x01                                 (_Logo1_0x00 + 0x01)
#define _Logo1_0x02                                 (_Logo1_0x00 + 0x02)
#define _Logo1_0x03                                 (_Logo1_0x00 + 0x03)
#define _Logo1_0x04                                 (_Logo1_0x00 + 0x04)
#define _Logo1_0x05                                 (_Logo1_0x00 + 0x05)
#define _Logo1_0x06                                 (_Logo1_0x00 + 0x06)
#define _Logo1_0x07                                 (_Logo1_0x00 + 0x07)
#define _Logo1_0x08                                 (_Logo1_0x00 + 0x08)
#define _Logo1_0x09                                 (_Logo1_0x00 + 0x09)
#define _Logo1_0x0a                                 (_Logo1_0x00 + 0x0a)
#define _Logo1_0x0b                                 (_Logo1_0x00 + 0x0b)
#define _Logo1_0x0c                                 (_Logo1_0x00 + 0x0c)
#define _Logo1_0x0d                                 (_Logo1_0x00 + 0x0d)
#define _Logo1_0x0e                                 (_Logo1_0x00 + 0x0e)
#define _Logo1_0x0f                                 (_Logo1_0x00 + 0x0f)
#define _Logo1_0x10                                 (_Logo1_0x00 + 0x10)
#define _Logo1_0x11                                 (_Logo1_0x00 + 0x11)
#define _Logo1_0x12                                 (_Logo1_0x00 + 0x12)
#define _Logo1_0x13                                 (_Logo1_0x00 + 0x13)
#define _Logo1_0x14                                 (_Logo1_0x00 + 0x14)
#define _Logo1_0x15                                 (_Logo1_0x00 + 0x15)
#define _Logo1_0x16                                 (_Logo1_0x00 + 0x16)
#define _Logo1_0x17                                 (_Logo1_0x00 + 0x17)
#define _Logo1_0x18                                 (_Logo1_0x00 + 0x18)
#define _Logo1_0x19                                 (_Logo1_0x00 + 0x19)
#define _Logo1_0x1a                                 (_Logo1_0x00 + 0x1a)
#define _Logo1_0x1b                                 (_Logo1_0x00 + 0x1b)
#define _Logo1_0x1c                                 (_Logo1_0x00 + 0x1c)
#define _Logo1_0x1d                                 (_Logo1_0x00 + 0x1d)
#define _Logo1_0x1e                                 (_Logo1_0x00 + 0x1e)
#define _Logo1_0x1f                                 (_Logo1_0x00 + 0x1f)
#define _Logo1_0x20                                 (_Logo1_0x00 + 0x20)
#define _Logo1_0x21                                 (_Logo1_0x00 + 0x21)
#define _Logo1_0x22                                 (_Logo1_0x00 + 0x22)
#define _Logo1_0x23                                 (_Logo1_0x00 + 0x23)
#define _Logo1_0x24                                 (_Logo1_0x00 + 0x24)
#define _Logo1_0x25                                 (_Logo1_0x00 + 0x25)
#define _Logo1_0x26                                 (_Logo1_0x00 + 0x26)
#define _Logo1_0x27                                 (_Logo1_0x00 + 0x27)
#define _Logo1_0x28                                 (_Logo1_0x00 + 0x28)
#define _Logo1_0x29                                 (_Logo1_0x00 + 0x29)
#define _Logo1_0x2a                                 (_Logo1_0x00 + 0x2a)
#define _Logo1_0x2b                                 (_Logo1_0x00 + 0x2b)
#define _Logo1_0x2c                                 (_Logo1_0x00 + 0x2c)
#define _Logo1_0x2d                                 (_Logo1_0x00 + 0x2d)
#define _Logo1_0x2e                                 (_Logo1_0x00 + 0x2e)
#define _Logo1_0x2f                                 (_Logo1_0x00 + 0x2f)
#define _Logo1_0x30                                 (_Logo1_0x00 + 0x30)
#define _Logo1_0x31                                 (_Logo1_0x00 + 0x31)
#define _Logo1_0x32                                 (_Logo1_0x00 + 0x32)
#define _Logo1_0x33                                 (_Logo1_0x00 + 0x33)
#define _Logo1_0x34                                 (_Logo1_0x00 + 0x34)
#define _Logo1_0x35                                 (_Logo1_0x00 + 0x35)
#define _Logo1_0x36                                 (_Logo1_0x00 + 0x36)
#define _Logo1_0x37                                 (_Logo1_0x00 + 0x37)
#define _Logo1_0x38                                 (_Logo1_0x00 + 0x38)
#define _Logo1_0x39                                 (_Logo1_0x00 + 0x39)
#define _Logo1_0x3a                                 (_Logo1_0x00 + 0x3a)
#define _Logo1_0x3b                                 (_Logo1_0x00 + 0x3b)
#define _Logo1_0x3c                                 (_Logo1_0x00 + 0x3c)
#define _Logo1_0x3d                                 (_Logo1_0x00 + 0x3d)
#define _Logo1_0x3e                                 (_Logo1_0x00 + 0x3e)
#define _Logo1_0x3f                                 (_Logo1_0x00 + 0x3f)
#define _Logo1_0x40                                 (_Logo1_0x00 + 0x40)
#define _Logo1_0x41                                 (_Logo1_0x00 + 0x41)
#define _Logo1_0x42                                 (_Logo1_0x00 + 0x42)
#define _Logo1_0x43                                 (_Logo1_0x00 + 0x43)
#define _Logo1_0x44                                 (_Logo1_0x00 + 0x44)
#define _Logo1_0x45                                 (_Logo1_0x00 + 0x45)
#define _Logo1_0x46                                 (_Logo1_0x00 + 0x46)

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

//------------------------------------------------------
// Definitions of OSD Slider Function Used by RTDOsdDisplaySlider()
//------------------------------------------------------
#define _SLIDER_RESOLUTION                          (10)

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

#define _OSD_ROTATE_FUNCTION                        _ON
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

//--------------------------------------------------
// Definations of HL window Border Size
//--------------------------------------------------
#define _HL_WIN_BORDER_SIZE                         2

//--------------------------------------------------
// Define OSD SOURCE PORT
//--------------------------------------------------
enum OSDSourcePortType
{
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    _OSD_SOURCE_PORT_0,
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    _OSD_SOURCE_PORT_1,
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    _OSD_SOURCE_PORT_2,
#endif
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
    _ASPECT_RATIO_ORIGIN,
    _ASPECT_RATIO_AMOUNT = _ASPECT_RATIO_ORIGIN,
};

//--------------------------------------------------
// Definitions of Color Temperature
//--------------------------------------------------
enum OSDColortemptureDef
{
    _CT_9300,
    _CT_7500,        
    _CT_6500,
    _CT_5800,
    _CT_SRGB,
    _CT_USER,
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

#if(_OCC_SUPPORT == _ON)
    _PCM_OSD_SRGB,
    _PCM_OSD_ADOBE_RGB,
#endif

    _PCM_OSD_USER,
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
    BYTE ucOsdColorFormat : 2;
    BYTE ucOsdsixColor : 3;

    BYTE ucOsdState;
    BYTE ucOsdEventMsg;
    BYTE ucOsdKeyMessage;
    BYTE ucOsdKeyControl;
    BYTE ucOsdSixColorHue;
    BYTE ucOsdSixColorSaturation;
    BYTE ucOsd3DEffectRealValue;
}StructOsdInfo;


enum OSDFontDef
{
    _ = 0,
    _0_,_1_,_2_,_3_,_4_,_5_,_6_,_7_,_8_,_9_,
    _A_, _B_, _C_, _D_, _E_, _F_, _G_, _H_, _I_, _J_, _K_, _L_, _M_, _N_, _O_, _P_, _Q_, _R_, _S_, _T_, _U_, _V_, _W_, _X_, _Y_, _Z_,
    _a_, _b_, _c_, _d_, _e_, _f_, _g_, _h_, _i_, _j_, _k_, _l_, _m_, _n_, _o_, _p_, _q_, _r_, _s_, _t_, _u_, _v_, _w_, _x_, _y_, _z_,
    _A0_,_a0_, _a1_, _a2_, _a3_, _a4_,_c0_, _E0_, _e0_, _e1_, _e2_, _n0_, _u0_, _u1_, _u2_, _o0_, _o1_, _o2_, _o3_,_i0_,

    _UPDOT_,                //  '
    _DOT_,                  //  .
    _LEFT_BRACE_,           //  (
    _RIGHT_BRACE_,          //  )
    _AND_,                  //  /
    _COLON_,                //  :
    _AT_0_,                 //  @
    _COMMA_,                //  ,
    _SLINE_,                //  -
    _SHIFT_LEFT_,           //  <<
    _SHIFT_RIGHT_,          //  >>
    _SEPERATE_,             //;
    _QUERY_,                //  ?  
};


enum OSDFontDefChinese
{
    _CH_ = 0,
    _CH_0_,_CH_1_,_CH_2_,_CH_3_,_CH_4_,_CH_5_,_CH_6_,_CH_7_,_CH_8_,_CH_9_,
    _CH_A_, _CH_B_, _CH_C_, _CH_D_, _CH_E_, _CH_F_, _CH_G_, _CH_H_, _CH_I_, _CH_K_, _CH_L_, _CH_M_, _CH_N_, _CH_O_, _CH_P_, _CH_R_, _CH_S_, _CH_T_, _CH_U_, _CH_V_, _CH_W_, _CH_Y_,
    _CH_a_, _CH_c_, _CH_d_, _CH_e_, _CH_g_, _CH_h_, _CH_i_, _CH_l_, _CH_m_, _CH_n_, _CH_o_, _CH_p_, _CH_r_, _CH_s_, _CH_t_, _CH_u_, _CH_v_, _CH_y_,

    _CH_COLON_,                //  :
    _CH_DOT_,
    
    _CH_0x00,
    _CH_0x01,
    _CH_0x02,
    _CH_0x03,
    _CH_0x04,
    _CH_0x05,
    _CHT_0x00,
    _CHT_0x01,
    _CHT_0x02,
    _CHT_0x03,
    _CHT_0x04,
    _CHT_0x05,
    _CHT_0x06,
    _CHT_0x07,
    _CHT_0x08,
    _CHT_0x09,
    _CHT_0x0A,
    _CHT_0x0B,
    _CHT_0x0C,
    _CHT_0x0D,
    _CHT_0x0E,
    _CHT_0x0F,
    _CHT_0x10,
    _CHT_0x11,
    _CHT_0x12,
    _CHT_0x13,
    _CHT_0x14,
    _CHT_0x15,
    _CHT_0x16,
    _CHT_0x17,
    _CHT_0x18,
    _CHT_0x19,
    _CHT_0x1A,
    _CHT_0x1B,
    _CHT_0x1C,
    _CHT_0x1D,
    _CHT_0x1E,
    _CHT_0x1F,
    _CHT_0x20,
    _CHT_0x21,
    _CHT_0x22,
    _CHT_0x23,
    _CHT_0x24,
    _CHT_0x25,
    _CHT_0x26,
    _CHT_0x27,
    _CHT_0x28,
    _CHT_0x29,
    _CHT_0x2A,
    _CHT_0x2B,
    _CHT_0x2C,
    _CHT_0x2D,
    _CHT_0x2E,
    _CHT_0x2F,
    _CHT_0x30,
    _CHT_0x31,
    _CHT_0x32,
    _CHT_0x33,
    _CHT_0x34,
    _CHT_0x35,
    _CHT_0x36,
    _CHT_0x37,
    _CHT_0x38,
    _CHT_0x39,
    _CHT_0x3A,
    _CHT_0x3B,
    _CHT_0x3C,
    _CHT_0x3D,
    _CHT_0x3E,
    _CHT_0x3F,
    _CHT_0x40,
    _CHT_0x41,
    _CHT_0x42,
    _CHT_0x43,
    _CHT_0x44,
    _CHT_0x45,
    _CHT_0x46,
    _CHT_0x47,
    _CHT_0x48,
    _CHT_0x49,
    _CHT_0x4A,
    _CHT_0x4B,
    _CHT_0x4C,
    _CHT_0x4D,
    _CHT_0x4E,
    _CHT_0x4F,
    _CHT_0x50,
    _CHT_0x51,
    _CHT_0x52,
    _CHT_0x53,
    _CHT_0x54,
    _CHT_0x55,
    _CHT_0x56,
    _CHT_0x57,
    _CHT_0x58,
    _CHT_0x59,
    _CHT_0x5A,
    _CHT_0x5B,
    _CHT_0x5C,
    _CHT_0x5D,
    _CHT_0x5E,
    _CHT_0x5F,
    _CHT_0x60,
    _CHT_0x61,
    _CHT_0x62,
    _CHT_0x63,
    _CHT_0x64,
    _CHT_0x65,
    _CHT_0x66,
    _CHT_0x67,
    _CHT_0x68,
    _CHT_0x69,
    _CHT_0x6A,
    _CHT_0x6B,
    _CHT_0x6C,
    _CHT_0x6D,
    _CHT_0x6E,
    _CHT_0x6F,
    _CHT_0x70,
    _CHT_0x71,
    _CHT_0x72,
    _CHT_0x73,
    _CHT_0x74,
    _CHT_0x75,
    _CHT_0x76,
    _CHT_0x77,
    _CHT_0x78,
    _CHT_0x79,
    _CHT_0x7A,
    _CHT_0x7B,
    _CHT_0x7C,
    _CHT_0x7D,
    _CHT_0x7E,
    _CHT_0x7F,
    _CHT_0x80,
    _CHT_0x81,
    _CHT_0x82,
    _CHT_0x83,
    _CHT_0x84,
    _CHT_0x85,
    _CHT_0x86,
    _CHT_0x87,
    _CHT_0x88,
    _CHT_0x89,
    _CHT_0x8A,
    _CHT_0x8B,
    _CHT_0x8C,
    _CHT_0x8D,
    _CHT_0x8E,
    _CHT_0x8F,
    _CHT_0x90,
    _CHT_0x91,
    _CHT_0x92,
    _CHT_0x93,
    _CHT_0x94,
    _CHT_0x95,
    _CHT_0x96,
    _CHT_0x97,
    _CHT_0x98,
    _CHT_0x99,
    _CHT_0x9A,
    _CHT_0x9B,
    _CHT_0x9C,
    _CHT_0x9D,
    _CHT_0x9E,
    _CHT_0x9F,
    _CHT_0xA0,
    _CHT_0xA1,
    _CHT_0xA2,
    _CHT_0xA3,
    _CHT_0xA4,
    _CHT_0xA5,
    _CHT_0xA6,
    _CHT_0xA7,
    _CHT_0xA8,
    _CHT_0xA9,
    _CHT_0xAA,
    _CHT_0xAB,
    _CHT_0xAC,
    _CHT_0xAD,
    _CHT_0xAE,
    _CHT_0xAF,
    _CHT_0xB0,
    _CHT_0xB1,
    _CHT_0xB2,
    _CHT_0xB3,
    _CHT_0xB4,
    _CHT_0xB5,
    _CHT_0xB6,
    _CHT_0xB7,
    _CHT_0xB8,
    _CHT_0xB9,
    _CHT_0xBA,
    _CHT_0xBB,
    _CHT_0xBC,
    _CHT_0xBD,
    _CHT_0xBE,
    _CHT_0xBF,
    _CHT_0xC0,
    _CHT_0xC1,
};

enum OSDColorPaletteDef
{
    _CP_BG = 0,
    _CP_BLACK = 0,
    _CP_WHITE,
    _CP_RED,
    _CP_GREEN,
    _CP_BLUE,
    _CP_YELLOW,
    _CP_GRAY,
    _CP_DARKBLUE,
    _CP_LIGHTBLUE,
    _CP_SELECTBOTTOM,
    _CP_PINK,
    _CP_RED_1,
    _CP_GREEN_1,
    _CP_ORANGE_L,
    _CP_ORANGE_H,

#if(_OSD_3D_FUNCTION == _OFF)
    _CP_GRAY_1,

#else
    _CP_SELECTBLUE,

#endif // End of #if(_OSD_3D_FUNCTION == _OFF)
};

typedef enum
{
    _MENU_NONE,
    _OSD_MAIN_PICTURE,
    _OSD_MAIN_DISPLAY,
    _OSD_MAIN_COLOR,
    _OSD_MAIN_ADVANCE,
    _OSD_MAIN_INPUT,
    _OSD_MAIN_AUDIO,
    _OSD_MAIN_OTHERS,
    _OSD_MAIN_INFORMATION,
    _OSD_MAIN_FACTORY,

    _OSD_PICTURE_BACKLIGHT,
    _OSD_PICTURE_BRIGHTNESS,
    _OSD_PICTURE_CONTRAST,
    _OSD_PICTURE_SHARPNESS,

    _OSD_PICTURE_BACKLIGHT_ADJUST,    
    _OSD_PICTURE_BRIGHTNESS_ADJUST,
    _OSD_PICTURE_CONTRAST_ADJUST,
    _OSD_PICTURE_SHARPNESS_ADJUST,

    _OSD_DISPLAY_AUTO,
    _OSD_DISPLAY_HPOSITION,
    _OSD_DISPLAY_VPOSITION,
    _OSD_DISPLAY_CLOCK,
    _OSD_DISPLAY_PHASE,
    
    _OSD_DISPLAY_HPOSITION_ADJUST,
    _OSD_DISPLAY_VPOSITION_ADJUST,
    _OSD_DISPLAY_CLOCK_ADJUST,
    _OSD_DISPLAY_PHASE_ADJUST,

    _OSD_COLOR_GAMMA,
    _OSD_COLOR_COLORTEMP,
    _OSD_COLOR_COLOREFFECT,
    _OSD_COLOR_DEMO,
    _OSD_COLOR_FORMAT,
    _OSD_COLOR_PCM,
    _OSD_COLOR_HUE,
    _OSD_COLOR_SATURATION,
    
    _OSD_COLOR_GAMMA_SELECT,
    _OSD_COLOR_COLORTEMP_SELECT,
    _OSD_COLOR_COLOREFFECT_SELECT,
    _OSD_COLOR_DEMO_SELECT,
    _OSD_COLOR_FORMAT_SELECT,
    _OSD_COLOR_PCM_SELECT,
    _OSD_COLOR_HUE_ADJUST,
    _OSD_COLOR_SATURATION_ADJUST,
    _OSD_COLOR_COLORTEMP_USER_R,
    _OSD_COLOR_COLORTEMP_USER_G,
    _OSD_COLOR_COLORTEMP_USER_B,
    _OSD_COLOR_COLORTEMP_USER_R_ADJUST,
    _OSD_COLOR_COLORTEMP_USER_G_ADJUST,
    _OSD_COLOR_COLORTEMP_USER_B_ADJUST,
    _OSD_COLOR_COLOREFFECT_USER_SIXCOLOR,
    _OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_HUE,
    _OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SATURATION,
    _OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SELECT,
    _OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_HUE_ADJUST,
    _OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SATURATION_ADJUST,
    
    _OSD_ADVANCE_ASPECTRATIO,
    _OSD_ADVANCE_OVERSCAN,
    _OSD_ADVANCE_OVERDRIVE,
    _OSD_ADVANCE_ENERGY_STAR,
    _OSD_ADVANCE_DDCCI,
    _OSD_ADVANCE_ULTRA_VIVID,
#if(_OSD_3D_FUNCTION == _ON)    
    _OSD_ADVANCE_3D,
#endif

    _OSD_ADVANCE_ASPECTRATIO_SELECT,
    _OSD_ADVANCE_OVERSCAN_SELECT,
    _OSD_ADVANCE_OVERDRIVE_SELECT,
    _OSD_ADVANCE_ENERGY_STAR_SELECT,
    _OSD_ADVANCE_DDCCI_SELECT,
    _OSD_ADVANCE_ULTRA_VIVID_SELECT,
#if(_OSD_3D_FUNCTION == _ON)    
    _OSD_ADVANCE_3D_SELECT,
#endif

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    _OSD_ASPECT_ORIGIN_RATIO,    
#endif

    _OSD_ADVANCE_OD_GAIN_ADJUST,

#if(_OSD_3D_FUNCTION == _ON)    
    _OSD_ADVANCE_3D_LR,
    _OSD_ADVANCE_3D_EFFECT,
    _OSD_ADVANCE_3D_FORMAT,
    _OSD_ADVANCE_3D_3DTO2D,
    _OSD_ADVANCE_3D_LR_SELECT,
    _OSD_ADVANCE_3D_EFFECT_ADJUST,
    _OSD_ADVANCE_3D_FORMAT_SELECT,
    _OSD_ADVANCE_3D_3DTO2D_SELECT,
#if(_2D_TO_3D_FUNCTION == _ON)
    _OSD_ADVANCE_3D_CONVERGENCE,
    _OSD_ADVANCE_3D_CONVERGENCE_SELECT,
    _OSD_ADVANCE_3D_CONVERGENCE_MODE,
    _OSD_ADVANCE_3D_CONVERGENCE_MODE_SELECT,
#endif
#endif

    _OSD_INPUT_AUTO,

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    _OSD_INPUT_A0,    
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    _OSD_INPUT_D0,
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    _OSD_INPUT_D1,
#endif

    _OSD_AUDIO_VOLUME,
    _OSD_AUDIO_MUTE,
    _OSD_AUDIO_STANDALONE,
    _OSD_AUDIO_SOURCE,
    _OSD_AUDIO_SOUNDMODE,
    _OSD_AUDIO_VOLUME_ADJUST,
    _OSD_AUDIO_MUTE_SELECT,
    _OSD_AUDIO_STANDALONE_SELECT,
    _OSD_AUDIO_SOURCE_SELECT,
    _OSD_AUDIO_SOUNDMODE_SELECT,

    _OSD_OTHER_RESET,
    _OSD_OTHER_MENUTIME,
    _OSD_OTHER_OSD_H_POS,
    _OSD_OTHER_OSD_V_POS,
    _OSD_OTHER_LANGUAGE,
    _OSD_OTHER_TRANS,
    _OSD_OTHER_ROTATE,

#if(_OSD_3D_FUNCTION == _ON)    
    _OSD_OTHER_3DOSD,
#endif

    _OSD_OTHER_MENUTIME_ADJUST,
    _OSD_OTHER_OSD_H_POS_ADJUST,
    _OSD_OTHER_OSD_V_POS_ADJUST,
    _OSD_OTHER_LANGUAGE_SELECT,
    _OSD_OTHER_TRANS_ADJUST,
    _OSD_OTHER_ROTATE_SELECT,

#if(_OSD_3D_FUNCTION == _ON)
    _OSD_OTHER_3DOSD_SELECT,
#endif

    _OSD_AUTO_SOURCE_HOTKEY,

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    _OSD_A0_HOTKEY,
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    _OSD_D0_HOTKEY,
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    _OSD_D1_HOTKEY,
#endif

    _MAIN_MENU_STATE_END,    
};

typedef enum
{
    _FONT1_GLOBAL,
    _REALTEK_2BIT_ICON,
    _MAIN_MENU_2BIT_ICON,
    _REALTEK_1BIT_LOGO0,
    _REALTEK_1BIT_LOGO1,      
};


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
    _OSD_STRING_PCM,
    _OSD_STRING_ASPECT_RATIO,
    _OSD_STRING_OVER_DRIVE,
    _OSD_STRING_ULTRA_VIVID,
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

    _OSD_STRING_ASPECT_ORIGIN_RATIO,
};

typedef enum
{
    _WIN_0,
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
    _PALETTE_0,
};

typedef enum
{
    _ICON_1BIT_UP,
    _ICON_1BIT_DOWN,
    _ICON_1BIT_LEFT,
    _ICON_1BIT_RIGHT,
    _ICON_1BIT_MENU,
    _ICON_1BIT_EXIT,
    _ICON_1BIT_LOGO_0,
    _ICON_1BIT_LOGO_1,


    _ICON_2BIT_PICTURE,
    _ICON_2BIT_DISPLAY,
    _ICON_2BIT_COLOR,
    _ICON_2BIT_ADVANCE,
    _ICON_2BIT_INPUT,
    _ICON_2BIT_AUDIO,
    _ICON_2BIT_OTHER,
    _ICON_2BIT_INFORMATION,
    _ICON_2BIT_REALTEK,
};

enum OSDLanguageDef
{
    _ENGLISH = 0,
    _FRENCH,
    _GERMAN,
    _SPANISH,
    _CHINESE_T,
    _CHINESE_S,
    _JAPAN,

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
    _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG,
};


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#ifndef __RTD_DDCCI__
extern bit g_bForcePowSavStatus;
#endif

#ifndef __RTD_OSD__
extern StructOsdInfo g_stOsdInfo;
extern WORD g_usAdjustValue;
extern WORD g_usBackupValue;
#endif

#ifndef __RTD_OSDFUNC__
extern WORD xdata g_usFontSelectStart;
extern WORD xdata g_usFontTableStart;
extern BYTE xdata g_ucOsdWidth;
extern BYTE xdata g_ucOsdHeight;
extern BYTE g_ucFontPointer0;
extern BYTE g_ucFontPointer1;
extern BYTE g_ucFontPointer2;
#endif
//----------------------------------------------------------------------------------------
// Extern Tables from RTDOsdFont.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDFONT__
extern BYTE code tFONT_GLOBAL[];
extern BYTE code tICON_REALTEK_2BIT_ICON[];
extern BYTE code tICON_MAIN_MENU_2BIT_ICON[];
extern BYTE code tICON_REALTEK_1BIT_LOGO0[];
extern BYTE code tICON_REALTEK_1BIT_LOGO1[];
#endif

//----------------------------------------------------------------------------------------
// Extern Tables from RTDOsdTable.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDTABLE__
extern BYTE code tPALETTE_0[];
extern BYTE code tFONT_EUROPE[];
extern BYTE code tFONT_CHINESE[];
extern BYTE code tOSD_CHARWIDTH_EUROPE[][2];
extern BYTE code tOSD_CHARWIDTH_CHINESE[][2];
extern code BYTE *tOSD_MENU_TITLE_TABLE[];
extern code BYTE *tOSD_PICTURE_PAGE_TABLE[];
extern code BYTE *tOSD_DISPLAY_PAGE_TABLE[];
extern code BYTE *tOSD_COLOR_PAGE_TABLE[];
extern code BYTE *tOSD_ADVANCE_PAGE_TABLE[];
extern code BYTE *tOSD_INPUT_PAGE_TABLE[];
extern code BYTE *tOSD_INPUT_MESSAGE_TABLE[];
extern code BYTE *tOSD_AUDIO_PAGE_TABLE[];
extern code BYTE *tOSD_AUDIO_SOURCE_TABLE[];
extern code BYTE *tOSD_OTHER_PAGE_TABLE[];
extern code BYTE *tOSD_ON_OFF_TABLE[];
extern BYTE code tOSD_LANGUAGE_TABLE[];
extern code BYTE *tOSD_GAMMA_SELECT_TABLE[];
extern code BYTE *tOSD_COLOR_TEMPERATURE_TABLE[];
extern code BYTE *tOSD_COLOR_MODE_TABLE[];
extern code BYTE *tOSD_COLOR_DEMO_MODE_TABLE[];
extern code BYTE *tOSD_COLOR_FORMAT_TABLE[];
extern code BYTE *tOSD_COLOR_PCM_TABLE[];
extern code BYTE *tOSD_ASPECT_RATIO_TABLE[];
extern code BYTE *tOSD_OVER_DRIVE_TABLE[];
extern code BYTE *tOSD_ULTRA_VIVID_TABLE[];
extern code BYTE *tOSD_RGB_TABLE[];
extern code BYTE *tOSD_FACTORY_TABLE[];
extern code BYTE tsOSD_ASPECT_ORIGIN_RATIO_TABLE[];

extern BYTE code twOSD_WIN0[];
extern BYTE code twOSD_WIN1[];
extern BYTE code twOSD_WIN2[];
extern BYTE code twOSD_WIN3[];

#if(_OSD_3D_FUNCTION == _ON)
extern BYTE code twOSD_WIN5[];
extern BYTE code twOSD_WIN6[];
#endif

extern BYTE code twOSD_WIN7[];

extern BYTE code twOSD_WIN0_TRANS[];
extern BYTE code twOSD_WIN1_TRANS[];
extern BYTE code twOSD_WIN2_TRANS[];
extern BYTE code twOSD_WIN3_TRANS[];
extern BYTE code twOSD_WIN4_TRANS[];
extern BYTE code twOSD_WIN5_TRANS[];
extern BYTE code twOSD_WIN6_TRANS[];
extern BYTE code twOSD_WIN7_TRANS[];

extern BYTE code tiOSD_UP_ICON[];
extern BYTE code tiOSD_DOWN_ICON[];
extern BYTE code tiOSD_LEFT_ICON[];
extern BYTE code tiOSD_RIGHT_ICON[];
extern BYTE code tiOSD_MENU_ICON[];
extern BYTE code tiOSD_EXIT_ICON[];

extern BYTE code tiOSD_REALTEK_ICON[];
extern BYTE code tiOSD_REALTEK_1BIT_LOGO0[];
extern BYTE code tiOSD_REALTEK_1BIT_LOGO1[];

extern BYTE code tiOSD_PICTURE_ICON[];
extern BYTE code tiOSD_DISPLAY_ICON[];
extern BYTE code tiOSD_COLOR_ICON[];
extern BYTE code tiOSD_ADVANCE_ICON[];
extern BYTE code tiOSD_INPUT_ICON[];
extern BYTE code tiOSD_AUDIO_ICON[];
extern BYTE code tiOSD_OTHER_ICON[];
extern BYTE code tiOSD_INFORMATION_ICON[];

extern BYTE code tsOSD_NO_CABLE[];
extern BYTE code tsOSD_NO_SIGNAL[];
extern BYTE code tsOSD_NO_SUPPORT[];
extern BYTE code tsOSD_AUTO_ADJUSTMENT[];
extern BYTE code tsOSD_AUTO_COLOR[];
extern BYTE code tsOSD_DDCCI[];
extern BYTE code tsOSD_GO_TO_POWER_SAVING_MODE[];

extern code BYTE *tOSD_3D_ITEM_TABLE[];
extern code BYTE *tOSD_3D_PAGE_TABLE[];
extern code BYTE *tOSD_3D_LR_SELECT_TABLE[];
extern code BYTE *tOSD_3D_CONVERGENCE_TABLE[];
extern code BYTE *tOSD_3D_CONVERGENCE_SELECT_TABLE[];
extern code BYTE *tOSD_3D_FORMAT_SELECT_TABLE[];
extern code BYTE *tOSD_SIX_COLOR_PAGE_TABLE[];
extern code BYTE *tOSD_COLOR_SIXCOLOR_TABLE[];

#endif


//----------------------------------------------------------------------------------------
// Extern Tables from RTDOsdACTIONFLOW.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDACTIONFLOW__
extern code void (*OperationTable[][4])(void);
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
extern void RTDKeyInitial(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from RTDOsd.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSD__
//============Main None==============//
extern void RTDOsdNoneMenu(void);
extern void RTDOsdNoneLeft(void);
extern void RTDOsdNoneRight(void);
extern void RTDOsdNoneExit(void);

//============Main Picture==============//
extern void RTDOsdMainPictureMenu(void);
extern void RTDOsdMainPictureLeft(void);
extern void RTDOsdMainPictureRight(void);
extern void RTDOsdMainPictureExit(void);
//============Main Display==============//
extern void RTDOsdMainDisplayMenu(void);
extern void RTDOsdMainDisplayLeft(void);
extern void RTDOsdMainDisplayRight(void);
extern void RTDOsdMainDisplayExit(void);
//============Main Color==============//
extern void RTDOsdMainColorMenu(void);
extern void RTDOsdMainColorLeft(void);
extern void RTDOsdMainColorRight(void);
extern void RTDOsdMainColorExit(void);
//============Main Advance==============//
extern void RTDOsdMainAdvanceMenu(void);
extern void RTDOsdMainAdvanceLeft(void);
extern void RTDOsdMainAdvanceRight(void);
extern void RTDOsdMainAdvanceExit(void);
//============Main Input==============//
extern void RTDOsdMainInputMenu(void);
extern void RTDOsdMainInputLeft(void);
extern void RTDOsdMainInputRight(void);
extern void RTDOsdMainInputExit(void);
//============Main Audio==============//
extern void RTDOsdMainAudioMenu(void);
extern void RTDOsdMainAudioLeft(void);
extern void RTDOsdMainAudioRight(void);
extern void RTDOsdMainAudioExit(void);
//============Main Others==============//
extern void RTDOsdMainOthersMenu(void);
extern void RTDOsdMainOthersLeft(void);
extern void RTDOsdMainOthersRight(void);
extern void RTDOsdMainOthersExit(void);
//============Main Information==============//
extern void RTDOsdMainInformationMenu(void);
extern void RTDOsdMainInformationLeft(void);
extern void RTDOsdMainInformationRight(void);
extern void RTDOsdMainInformationExit(void);
//============Main Factory==============//
extern void RTDOsdMainFactoryMenu(void);
extern void RTDOsdMainFactoryLeft(void);
extern void RTDOsdMainFactoryRight(void);
extern void RTDOsdMainFactoryExit(void);
//============Picture Backlight==============//
extern void RTDOsdPictureBacklightMenu(void);
extern void RTDOsdPictureBacklightLeft(void);
extern void RTDOsdPictureBacklightRight(void);
extern void RTDOsdPictureBacklightExit(void);

//============Picture Brightness==============//
extern void RTDOsdPictureBrightnessMenu(void);
extern void RTDOsdPictureBrightnessLeft(void);
extern void RTDOsdPictureBrightnessRight(void);
extern void RTDOsdPictureBrightnessExit(void);
//============Picture Contrast==============//
extern void RTDOsdPictureContrastMenu(void);
extern void RTDOsdPictureContrastLeft(void);
extern void RTDOsdPictureContrastRight(void);
extern void RTDOsdPictureContrastExit(void);
//============Picture Sharpness==============//
extern void RTDOsdPictureSharpnessMenu(void);
extern void RTDOsdPictureSharpnessLeft(void);
extern void RTDOsdPictureSharpnessRight(void);
extern void RTDOsdPictureSharpnessExit(void);
//============Picture Backlight Adjust==============//
extern void RTDOsdPictureBacklightAdjustMenu(void);
extern void RTDOsdPictureBacklightAdjustLeft(void);
extern void RTDOsdPictureBacklightAdjustRight(void);
extern void RTDOsdPictureBacklightAdjustExit(void);
//============Picture Brightness Adjust==============//
extern void RTDOsdPictureBrightnessAdjustMenu(void);
extern void RTDOsdPictureBrightnessAdjustLeft(void);
extern void RTDOsdPictureBrightnessAdjustRight(void);
extern void RTDOsdPictureBrightnessAdjustExit(void);
//============Picture Contrast Adjust==============//
extern void RTDOsdPictureContrastAdjustMenu(void);
extern void RTDOsdPictureContrastAdjustLeft(void);
extern void RTDOsdPictureContrastAdjustRight(void);
extern void RTDOsdPictureContrastAdjustExit(void);
//============Picture Sharpness Adjust==============//
extern void RTDOsdPictureSharpnessAdjustMenu(void);
extern void RTDOsdPictureSharpnessAdjustLeft(void);
extern void RTDOsdPictureSharpnessAdjustRight(void);
extern void RTDOsdPictureSharpnessAdjustExit(void);

//============Display Auto==============//
extern void RTDOsdDisplayAutoMenu(void);
extern void RTDOsdDisplayAutoLeft(void);
extern void RTDOsdDisplayAutoRight(void);
extern void RTDOsdDisplayAutoExit(void);
//============Display H Position==============//
extern void RTDOsdDisplayHPositionMenu(void);
extern void RTDOsdDisplayHPositionLeft(void);
extern void RTDOsdDisplayHPositionRight(void);
extern void RTDOsdDisplayHPositionExit(void);
//============Display V Position==============//
extern void RTDOsdDisplayVPositionMenu(void);
extern void RTDOsdDisplayVPositionLeft(void);
extern void RTDOsdDisplayVPositionRight(void);
extern void RTDOsdDisplayVPositionExit(void);
//============Display Clock==============//
extern void RTDOsdDisplayClockMenu(void);
extern void RTDOsdDisplayClockLeft(void);
extern void RTDOsdDisplayClockRight(void);
extern void RTDOsdDisplayClockExit(void);
//============Display Phase==============//
extern void RTDOsdDisplayPhaseMenu(void);
extern void RTDOsdDisplayPhaseLeft(void);
extern void RTDOsdDisplayPhaseRight(void);
extern void RTDOsdDisplayPhaseExit(void);
//============Display H Position Adjust==============//
extern void RTDOsdDisplayHPositionAdjustMenu(void);
extern void RTDOsdDisplayHPositionAdjustLeft(void);
extern void RTDOsdDisplayHPositionAdjustRight(void);
extern void RTDOsdDisplayHPositionAdjustExit(void);
//============Display V Position Adjust==============//
extern void RTDOsdDisplayVPositionAdjustMenu(void);
extern void RTDOsdDisplayVPositionAdjustLeft(void);
extern void RTDOsdDisplayVPositionAdjustRight(void);
extern void RTDOsdDisplayVPositionAdjustExit(void);
//============Display Clock Adjust==============//
extern void RTDOsdDisplayClockAdjustMenu(void);
extern void RTDOsdDisplayClockAdjustLeft(void);
extern void RTDOsdDisplayClockAdjustRight(void);
extern void RTDOsdDisplayClockAdjustExit(void);
//============Display Phase Adjust==============//
extern void RTDOsdDisplayPhaseAdjustMenu(void);
extern void RTDOsdDisplayPhaseAdjustLeft(void);
extern void RTDOsdDisplayPhaseAdjustRight(void);
extern void RTDOsdDisplayPhaseAdjustExit(void);
//============Color Gamma==============//
extern void RTDOsdColorGammaMenu(void);
extern void RTDOsdColorGammaLeft(void);
extern void RTDOsdColorGammaRight(void);
extern void RTDOsdColorGammaExit(void);
//============Color Colortemp==============//
extern void RTDOsdColorColortempMenu(void);
extern void RTDOsdColorColortempLeft(void);
extern void RTDOsdColorColortempRight(void);
extern void RTDOsdColorColortempExit(void);
//============Color Effect==============//
extern void RTDOsdColorEffectMenu(void);
extern void RTDOsdColorEffectLeft(void);
extern void RTDOsdColorEffectRight(void);
extern void RTDOsdColorEffectExit(void);
//============Color Demo==============//
extern void RTDOsdColorDemoMenu(void);
extern void RTDOsdColorDemoLeft(void);
extern void RTDOsdColorDemoRight(void);
extern void RTDOsdColorDemoExit(void);
//============Color Format==============//
extern void RTDOsdColorFormatMenu(void);
extern void RTDOsdColorFormatLeft(void);
extern void RTDOsdColorFormatRight(void);
extern void RTDOsdColorFormatExit(void);
//============Color PCM==============//
extern void RTDOsdColorPCMMenu(void);
extern void RTDOsdColorPCMLeft(void);
extern void RTDOsdColorPCMRight(void);
extern void RTDOsdColorPCMExit(void);
//============Color Hue==============//
extern void RTDOsdColorHueMenu(void);
extern void RTDOsdColorHueLeft(void);
extern void RTDOsdColorHueRight(void);
extern void RTDOsdColorHueExit(void);
//============Color Saturation==============//
extern void RTDOsdColorSaturationMenu(void);
extern void RTDOsdColorSaturationLeft(void);
extern void RTDOsdColorSaturationRight(void);
extern void RTDOsdColorSaturationExit(void);
//============Color Gamma Adjust==============//
extern void RTDOsdColorGammaAdjustMenu(void);
extern void RTDOsdColorGammaAdjustLeft(void);
extern void RTDOsdColorGammaAdjustRight(void);
extern void RTDOsdColorGammaAdjustExit(void);
//============Color Colortemp Select==============//
extern void RTDOsdColorColortempSelectMenu(void);
extern void RTDOsdColorColortempSelectLeft(void);
extern void RTDOsdColorColortempSelectRight(void);
extern void RTDOsdColorColortempSelectExit(void);
//============Color Color Effect Select==============//
extern void RTDOsdColorColorEffectSelectMenu(void);
extern void RTDOsdColorColorEffectSelectLeft(void);
extern void RTDOsdColorColorEffectSelectRight(void);
extern void RTDOsdColorColorEffectSelectExit(void);
//============Color Demo Select==============//
extern void RTDOsdColorDemoSelectMenu(void);
extern void RTDOsdColorDemoSelectLeft(void);
extern void RTDOsdColorDemoSelectRight(void);
extern void RTDOsdColorDemoSelectExit(void);
//============Color Format Select==============//
extern void RTDOsdColorFormatSelectMenu(void);
extern void RTDOsdColorFormatSelectLeft(void);
extern void RTDOsdColorFormatSelectRight(void);
extern void RTDOsdColorFormatSelectExit(void);
//============Color PCM Select==============//
extern void RTDOsdColorPCMSelectMenu(void);
extern void RTDOsdColorPCMSelectLeft(void);
extern void RTDOsdColorPCMSelectRight(void);
extern void RTDOsdColorPCMSelectExit(void);
//============Color Hue Adjust==============//
extern void RTDOsdColorHueAdjustMenu(void);
extern void RTDOsdColorHueAdjustLeft(void);
extern void RTDOsdColorHueAdjustRight(void);
extern void RTDOsdColorHueAdjustExit(void);
//============Color Saturation Adjust==============//
extern void RTDOsdColorSaturationAdjustMenu(void);
extern void RTDOsdColorSaturationAdjustLeft(void);
extern void RTDOsdColorSaturationAdjustRight(void);
extern void RTDOsdColorSaturationAdjustExit(void);
//============Color Colortemp RTD R==============//
extern void RTDOsdColorColortempUserRMenu(void);
extern void RTDOsdColorColortempUserRLeft(void);
extern void RTDOsdColorColortempUserRRight(void);
extern void RTDOsdColorColortempUserRExit(void);
//============Color Colortemp RTD G==============//
extern void RTDOsdColorColortempUserGMenu(void);
extern void RTDOsdColorColortempUserGLeft(void);
extern void RTDOsdColorColortempUserGRight(void);
extern void RTDOsdColorColortempUserGExit(void);
//============Color Colortemp User B==============//
extern void RTDOsdColorColortempUserBMenu(void);
extern void RTDOsdColorColortempUserBLeft(void);
extern void RTDOsdColorColortempUserBRight(void);
extern void RTDOsdColorColortempUserBExit(void);
//============Color Colortemp User R Adjust==============//
extern void RTDOsdColorColortempUserRAdjustMenu(void);
extern void RTDOsdColorColortempUserRAdjustLeft(void);
extern void RTDOsdColorColortempUserRAdjustRight(void);
extern void RTDOsdColorColortempUserRAdjustExit(void);
//============Color Colortemp User G Adjust==============//
extern void RTDOsdColorColortempUserGAdjustMenu(void);
extern void RTDOsdColorColortempUserGAdjustLeft(void);
extern void RTDOsdColorColortempUserGAdjustRight(void);
extern void RTDOsdColorColortempUserGAdjustExit(void);
//============Color Colortemp User B Adjust==============//
extern void RTDOsdColorColortempUserBAdjustMenu(void);
extern void RTDOsdColorColortempUserBAdjustLeft(void);
extern void RTDOsdColorColortempUserBAdjustRight(void);
extern void RTDOsdColorColortempUserBAdjustExit(void);
//============Color Color Effect Six Color ==============//
extern void RTDOsdColorColorEffectSixColorMenu(void);
extern void RTDOsdColorColorEffectSixColorLeft(void);
extern void RTDOsdColorColorEffectSixColorRight(void);
extern void RTDOsdColorColorEffectSixColorExit(void);
//============Color Color Effect Six Color Hue ==============//
extern void RTDOsdColorColorEffectSixColorHueMenu(void);
extern void RTDOsdColorColorEffectSixColorHueLeft(void);
extern void RTDOsdColorColorEffectSixColorHueRight(void);
extern void RTDOsdColorColorEffectSixColorHueExit(void);
//============Color Color Effect Six Color Saturation ==============//
extern void RTDOsdColorColorEffectSixColorSaturationMenu(void);
extern void RTDOsdColorColorEffectSixColorSaturationLeft(void);
extern void RTDOsdColorColorEffectSixColorSaturationRight(void);
extern void RTDOsdColorColorEffectSixColorSaturationExit(void);
//============Color Color Effect Six Color Select==============//
extern void RTDOsdColorColorEffectSixColorSelectMenu(void);
extern void RTDOsdColorColorEffectSixColorSelectLeft(void);
extern void RTDOsdColorColorEffectSixColorSelectRight(void);
extern void RTDOsdColorColorEffectSixColorSelectExit(void);
//============Color Color Effect Six Color Hue Adjust==============//
extern void RTDOsdColorColorEffectSixColorHueAdjustMenu(void);
extern void RTDOsdColorColorEffectSixColorHueAdjustLeft(void);
extern void RTDOsdColorColorEffectSixColorHueAdjustRight(void);
extern void RTDOsdColorColorEffectSixColorHueAdjustExit(void);
//============Color Color Effect Six Color Saturation Adjust==============//
extern void RTDOsdColorColorEffectSixColorSaturationAdjustMenu(void);
extern void RTDOsdColorColorEffectSixColorSaturationAdjustLeft(void);
extern void RTDOsdColorColorEffectSixColorSaturationAdjustRight(void);
extern void RTDOsdColorColorEffectSixColorSaturationAdjustExit(void);

//============Advance Aspect Ratio==============//
extern void RTDOsdAdvanceAspectRatioMenu(void);
extern void RTDOsdAdvanceAspectRatioLeft(void);
extern void RTDOsdAdvanceAspectRatioRight(void);
extern void RTDOsdAdvanceAspectRatioExit(void);
//============Advance Oversacn==============//
extern void RTDOsdAdvanceOversacnMenu(void);
extern void RTDOsdAdvanceOversacnLeft(void);
extern void RTDOsdAdvanceOversacnRight(void);
extern void RTDOsdAdvanceOversacnExit(void);
//============Advance Overdrive==============//
extern void RTDOsdAdvanceOverdriveMenu(void);
extern void RTDOsdAdvanceOverdriveLeft(void);
extern void RTDOsdAdvanceOverdriveRight(void);
extern void RTDOsdAdvanceOverdriveExit(void);
//============Advance Energy Star==============//
extern void RTDOsdAdvanceESMenu(void);
extern void RTDOsdAdvanceESLeft(void);
extern void RTDOsdAdvanceESRight(void);
extern void RTDOsdAdvanceESExit(void);
//============Advance DDCCI==============//
extern void RTDOsdAdvanceDdcciMenu(void);
extern void RTDOsdAdvanceDdcciLeft(void);
extern void RTDOsdAdvanceDdcciRight(void);
extern void RTDOsdAdvanceDdcciExit(void);
//============Advance Ultra Vivid==============//
extern void RTDOsdAdvanceUltraVividMenu(void);
extern void RTDOsdAdvanceUltraVividLeft(void);
extern void RTDOsdAdvanceUltraVividRight(void);
extern void RTDOsdAdvanceUltraVividExit(void);
//============Advance 3D==============//
extern void RTDOsdAdvance3DMenu(void);
extern void RTDOsdAdvance3DLeft(void);
extern void RTDOsdAdvance3DRight(void);
extern void RTDOsdAdvance3DExit(void);

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
//============OSD Aspect Original Ratio==============//
extern void RTDOsdAspectOriginalRatioMenu(void);
extern void RTDOsdAspectOriginalRatioLeft(void);
extern void RTDOsdAspectOriginalRatioRight(void);
extern void RTDOsdAspectOriginalRatioExit(void);
#endif

//============Advance Aspect Ratio Select==============//
extern void RTDOsdAdvanceAspectRatioSelectMenu(void);
extern void RTDOsdAdvanceAspectRatioSelectLeft(void);
extern void RTDOsdAdvanceAspectRatioSelectRight(void);
extern void RTDOsdAdvanceAspectRatioSelectExit(void);
//============Advance Oversacn Select==============//
extern void RTDOsdAdvanceOversacnSelectMenu(void);
extern void RTDOsdAdvanceOversacnSelectLeft(void);
extern void RTDOsdAdvanceOversacnSelectRight(void);
extern void RTDOsdAdvanceOversacnSelectExit(void);
//============Advance Overdrive Select==============//
extern void RTDOsdAdvanceOverdriveSelectMenu(void);
extern void RTDOsdAdvanceOverdriveSelectLeft(void);
extern void RTDOsdAdvanceOverdriveSelectRight(void);
extern void RTDOsdAdvanceOverdriveSelectExit(void);
//============Advance Energy Star Select==============//
extern void RTDOsdAdvanceESSelectMenu(void);
extern void RTDOsdAdvanceESSelectLeft(void);
extern void RTDOsdAdvanceESSelectRight(void);
extern void RTDOsdAdvanceESSelectExit(void);
//============Advance DDCCI Select==============//
extern void RTDOsdAdvanceDdcciSelectMenu(void);
extern void RTDOsdAdvanceDdcciSelectLeft(void);
extern void RTDOsdAdvanceDdcciSelectRight(void);
extern void RTDOsdAdvanceDdcciSelectExit(void);
//============Advance Ultra Vivid Select==============//
extern void RTDOsdAdvanceUltraVividSelectMenu(void);
extern void RTDOsdAdvanceUltraVividSelectLeft(void);
extern void RTDOsdAdvanceUltraVividSelectRight(void);
extern void RTDOsdAdvanceUltraVividSelectExit(void);

#if(_OSD_3D_FUNCTION == _ON)        
//============Advance 3D Select==============//
extern void RTDOsdAdvance3DSelectMenu(void);
extern void RTDOsdAdvance3DSelectLeft(void);
extern void RTDOsdAdvance3DSelectRight(void);
extern void RTDOsdAdvance3DSelectExit(void);
#endif // End of #if(_OSD_3D_FUNCTION == _ON)

//============Advance OD Gain Adjust==============//
extern void RTDOsdAdvanceOdGainAdjustMenu(void);
extern void RTDOsdAdvanceOdGainAdjustLeft(void);
extern void RTDOsdAdvanceOdGainAdjustRight(void);
extern void RTDOsdAdvanceOdGainAdjustExit(void);

#if(_OSD_3D_FUNCTION == _ON)
//============Advance 3D LR==============//
extern void RTDOsdAdvance3DLRMenu(void);
extern void RTDOsdAdvance3DLRLeft(void);
extern void RTDOsdAdvance3DLRRight(void);
extern void RTDOsdAdvance3DLRExit(void);
//============Advance 3D Effect==============//
extern void RTDOsdAdvance3DEffectMenu(void);
extern void RTDOsdAdvance3DEffectLeft(void);
extern void RTDOsdAdvance3DEffectRight(void);
extern void RTDOsdAdvance3DEffectExit(void);
//============Advance 3D Format==============//
extern void RTDOsdAdvance3DFormatMenu(void);
extern void RTDOsdAdvance3DFormatLeft(void);
extern void RTDOsdAdvance3DFormatRight(void);
extern void RTDOsdAdvance3DFormatExit(void);
//============Advance 3D 3DTO2D==============//
extern void RTDOsdAdvance3D3DTO2DMenu(void);
extern void RTDOsdAdvance3D3DTO2DLeft(void);
extern void RTDOsdAdvance3D3DTO2DRight(void);
extern void RTDOsdAdvance3D3DTO2DExit(void);
//============Advance 3D LR Adjus==============//
extern void RTDOsdAdvance3DLRSelectMenu(void);
extern void RTDOsdAdvance3DLRSelectLeft(void);
extern void RTDOsdAdvance3DLRSelectRight(void);
extern void RTDOsdAdvance3DLRSelectExit(void);
//============Advance 3D Effect Adjust==============//
extern void RTDOsdAdvance3DEffectAdjustMenu(void);
extern void RTDOsdAdvance3DEffectAdjustLeft(void);
extern void RTDOsdAdvance3DEffectAdjustRight(void);
extern void RTDOsdAdvance3DEffectAdjustExit(void);
//============Advance 3D Format Select==============//
extern void RTDOsdAdvance3DFormatSelectMenu(void);
extern void RTDOsdAdvance3DFormatSelectLeft(void);
extern void RTDOsdAdvance3DFormatSelectRight(void);
extern void RTDOsdAdvance3DFormatSelectExit(void);
//============Advance 3D 3DTO2D Select==============//
extern void RTDOsdAdvance3D3DTO2DSelectMenu(void);
extern void RTDOsdAdvance3D3DTO2DSelectLeft(void);
extern void RTDOsdAdvance3D3DTO2DSelectRight(void);
extern void RTDOsdAdvance3D3DTO2DSelectExit(void);

#if(_2D_TO_3D_FUNCTION == _ON)
//============Advance 3D Convergence==============//
extern void RTDOsdAdvance3DConvergenceMenu(void);
extern void RTDOsdAdvance3DConvergenceLeft(void);
extern void RTDOsdAdvance3DConvergenceRight(void);
extern void RTDOsdAdvance3DConvergenceExit(void);
//============Advance 3D Convergence Select==============//
extern void RTDOsdAdvance3DConvergenceSelectMenu(void);
extern void RTDOsdAdvance3DConvergenceSelectLeft(void);
extern void RTDOsdAdvance3DConvergenceSelectRight(void);
extern void RTDOsdAdvance3DConvergenceSelectExit(void);
//============Advance 3D Convergence Mode==============//
extern void RTDOsdAdvance3DConvergenceModeMenu(void);
extern void RTDOsdAdvance3DConvergenceModeLeft(void);
extern void RTDOsdAdvance3DConvergenceModeRight(void);
extern void RTDOsdAdvance3DConvergenceModeExit(void);
//============Advance 3D Convergence Mode Select==============//
extern void RTDOsdAdvance3DConvergenceModeSelectMenu(void);
extern void RTDOsdAdvance3DConvergenceModeSelectLeft(void);
extern void RTDOsdAdvance3DConvergenceModeSelectRight(void);
extern void RTDOsdAdvance3DConvergenceModeSelectExit(void);
#endif // End of #if(_2D_TO_3D_FUNCTION == _ON)
#endif // End of #if(_OSD_3D_FUNCTION == _ON)

//============Input Auto==============//
extern void RTDOsdInputAutoMenu(void);
extern void RTDOsdInputAutoLeft(void);
extern void RTDOsdInputAutoRight(void);
extern void RTDOsdInputAutoExit(void);
//============Input A0==============//
extern void RTDOsdInputA0Menu(void);
extern void RTDOsdInputA0Left(void);
extern void RTDOsdInputA0Right(void);
extern void RTDOsdInputA0Exit(void);
//============Input D0==============//
extern void RTDOsdInputD0Menu(void);
extern void RTDOsdInputD0Left(void);
extern void RTDOsdInputD0Right(void);
extern void RTDOsdInputD0Exit(void);
//============Input D1==============//
extern void RTDOsdInputD1Menu(void);
extern void RTDOsdInputD1Left(void);
extern void RTDOsdInputD1Right(void);
extern void RTDOsdInputD1Exit(void);

//============Audio Volume==============//
extern void RTDOsdAudioVolumeMenu(void);
extern void RTDOsdAudioVolumeLeft(void);
extern void RTDOsdAudioVolumeRight(void);
extern void RTDOsdAudioVolumeExit(void);
//============Audio Mute==============//
extern void RTDOsdAudioMuteMenu(void);
extern void RTDOsdAudioMuteLeft(void);
extern void RTDOsdAudioMuteRight(void);
extern void RTDOsdAudioMuteExit(void);
//============Audio StandAlone==============//
extern void RTDOsdAudioStandAloneMenu(void);
extern void RTDOsdAudioStandAloneLeft(void);
extern void RTDOsdAudioStandAloneRight(void);
extern void RTDOsdAudioStandAloneExit(void);
//============Audio Source==============//
extern void RTDOsdAudioSourceMenu(void);
extern void RTDOsdAudioSourceLeft(void);
extern void RTDOsdAudioSourceRight(void);
extern void RTDOsdAudioSourceExit(void);
//============Audio Sound Mode==============//
extern void RTDOsdAudioSoundModeMenu(void);
extern void RTDOsdAudioSoundModeLeft(void);
extern void RTDOsdAudioSoundModeRight(void);
extern void RTDOsdAudioSoundModeExit(void);
//============Audio Volume Adjust==============//
extern void RTDOsdAudioVolumeAdjustMenu(void);
extern void RTDOsdAudioVolumeAdjustLeft(void);
extern void RTDOsdAudioVolumeAdjustRight(void);
extern void RTDOsdAudioVolumeAdjustExit(void);
//============Audio Mute Select==============//
extern void RTDOsdAudioMuteSelectMenu(void);
extern void RTDOsdAudioMuteSelectLeft(void);
extern void RTDOsdAudioMuteSelectRight(void);
extern void RTDOsdAudioMuteSelectExit(void);
//============Audio StandAlone Select==============//
extern void RTDOsdAudioStandAloneSelectMenu(void);
extern void RTDOsdAudioStandAloneSelectLeft(void);
extern void RTDOsdAudioStandAloneSelectRight(void);
extern void RTDOsdAudioStandAloneSelectExit(void);
//============Audio Source==============//
extern void RTDOsdAudioSourceSelectMenu(void);
extern void RTDOsdAudioSourceSelectLeft(void);
extern void RTDOsdAudioSourceSelectRight(void);
extern void RTDOsdAudioSourceSelectExit(void);
//============Audio Sound Mode Select==============//
extern void RTDOsdAudioSoundModeSelectMenu(void);
extern void RTDOsdAudioSoundModeSelectLeft(void);
extern void RTDOsdAudioSoundModeSelectRight(void);
extern void RTDOsdAudioSoundModeSelectExit(void);

//============Other Reset==============//
extern void RTDOsdOtherResetMenu(void);
extern void RTDOsdOtherResetLeft(void);
extern void RTDOsdOtherResetRight(void);
extern void RTDOsdOtherResetExit(void);
//============Other Menu Time==============//
extern void RTDOsdOtherMenuTimeMenu(void);
extern void RTDOsdOtherMenuTimeLeft(void);
extern void RTDOsdOtherMenuTimeRight(void);
extern void RTDOsdOtherMenuTimeExit(void);
//============Other H Position==============//
extern void RTDOsdOtherHPositionMenu(void);
extern void RTDOsdOtherHPositionLeft(void);
extern void RTDOsdOtherHPositionRight(void);
extern void RTDOsdOtherHPositionExit(void);
//============Other V Position==============//
extern void RTDOsdOtherVPositionMenu(void);
extern void RTDOsdOtherVPositionLeft(void);
extern void RTDOsdOtherVPositionRight(void);
extern void RTDOsdOtherVPositionExit(void);
//============Other Language==============//
extern void RTDOsdOtherLanguageMenu(void);
extern void RTDOsdOtherLanguageLeft(void);
extern void RTDOsdOtherLanguageRight(void);
extern void RTDOsdOtherLanguageExit(void);
//============Other Trans==============//
extern void RTDOsdOtherTransMenu(void);
extern void RTDOsdOtherTransLeft(void);
extern void RTDOsdOtherTransRight(void);
extern void RTDOsdOtherTransExit(void);
//============Other Rotate==============//
extern void RTDOsdOtherRotateMenu(void);
extern void RTDOsdOtherRotateLeft(void);
extern void RTDOsdOtherRotateRight(void);
extern void RTDOsdOtherRotateExit(void);
//============Other 3D OSD==============//
extern void RTDOsdOther3DOSDMenu(void);
extern void RTDOsdOther3DOSDLeft(void);
extern void RTDOsdOther3DOSDRight(void);
extern void RTDOsdOther3DOSDExit(void);
//============Other Menu Time Adjust==============//
extern void RTDOsdOtherMenuTimeAdjustMenu(void);
extern void RTDOsdOtherMenuTimeAdjustLeft(void);
extern void RTDOsdOtherMenuTimeAdjustRight(void);
extern void RTDOsdOtherMenuTimeAdjustExit(void);
//============Other H Position Adjust==============//
extern void RTDOsdOtherHPositionAdjustMenu(void);
extern void RTDOsdOtherHPositionAdjustLeft(void);
extern void RTDOsdOtherHPositionAdjustRight(void);
extern void RTDOsdOtherHPositionAdjustExit(void);
//============Other V Position Adjust==============//
extern void RTDOsdOtherVPositionAdjustMenu(void);
extern void RTDOsdOtherVPositionAdjustLeft(void);
extern void RTDOsdOtherVPositionAdjustRight(void);
extern void RTDOsdOtherVPositionAdjustExit(void);
//============Other Language Select==============//
extern void RTDOsdOtherLanguageSelectMenu(void);
extern void RTDOsdOtherLanguageSelectLeft(void);
extern void RTDOsdOtherLanguageSelectRight(void);
extern void RTDOsdOtherLanguageSelectExit(void);
//============Other Trans Adjust==============//
extern void RTDOsdOtherTransAdjustMenu(void);
extern void RTDOsdOtherTransAdjustLeft(void);
extern void RTDOsdOtherTransAdjustRight(void);
extern void RTDOsdOtherTransAdjustExit(void);
//============Other Rotate Select==============//
extern void RTDOsdOtherRotateSelectMenu(void);
extern void RTDOsdOtherRotateSelectLeft(void);
extern void RTDOsdOtherRotateSelectRight(void);
extern void RTDOsdOtherRotateSelectExit(void);
//============Other 3D OSD Select==============//
extern void RTDOsdOther3DOSDSelectMenu(void);
extern void RTDOsdOther3DOSDSelectLeft(void);
extern void RTDOsdOther3DOSDSelectRight(void);
extern void RTDOsdOther3DOSDSelectExit(void);
//============Picture Brightness Adjust==============//
extern void RTDOsdPictureBrightnessAdjMenu(void);
extern void RTDOsdPictureBrightnessAdjLeft(void);
extern void RTDOsdPictureBrightnessAdjRight(void);
extern void RTDOsdPictureBrightnessAdjExit(void);

//============Hot Key Auto Source==============//
extern void RTDOsdHotKeyAutoSourceMenu(void);
extern void RTDOsdHotKeyAutoSourceLeft(void);
extern void RTDOsdHotKeyAutoSourceRight(void);
extern void RTDOsdHotKeyAutoSourceExit(void);
//============Hot Key A0==============//
extern void RTDOsdHotKeyA0Menu(void);
extern void RTDOsdHotKeyA0Left(void);
extern void RTDOsdHotKeyA0Right(void);
extern void RTDOsdHotKeyA0Exit(void);
//============Hot Key D0==============//
extern void RTDOsdHotKeyD0Menu(void);
extern void RTDOsdHotKeyD0Left(void);
extern void RTDOsdHotKeyD0Right(void);
extern void RTDOsdHotKeyD0Exit(void);
//============Hot Key D1==============//
extern void RTDOsdHotKeyD1Menu(void);
extern void RTDOsdHotKeyD1Left(void);
extern void RTDOsdHotKeyD1Right(void);
extern void RTDOsdHotKeyD1Exit(void);
#endif


//----------------------------------------------------------------------------------------
// Extern functions from RTDOsdFunc.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDFUNC__
extern void RTDOsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
extern void RTDOsdFuncSetPosition(WORD usX, WORD usY);
extern void RTDOsdFuncPutChar(BYTE ucRow, BYTE ucCol, BYTE ucChar, BYTE ucColor);
extern BYTE RTDOsdFuncGetOsdFontPointer(BYTE ucPointerSelect);
extern BYTE RTDOsdFuncSetOsdFontPointer(BYTE ucPointerSelect,BYTE ucPointer);
//extern void RTDOsdDisplayDrawWindowPixel(BYTE ucIndex, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor, BYTE ucBorderPixel, BYTE ucBorderColor, BYTE ucWinFuncControl, BYTE ucGradientCon0, BYTE ucGradientCon1);
//extern void RTDOsdDisplayDrawWindow(BYTE ucIndex, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucBorderPixel, BYTE ucBorderColor, BYTE ucWinFuncControl, BYTE ucGradientCon0, BYTE ucGradientCon1);
extern void RTDOsdFuncCloseWindow(BYTE ucIndex);
extern void RTDOsdFuncDisableOsd(void);
extern void RTDOsdFuncEnableOsd(void);
extern void RTDOsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucColor);
extern void RTDOsdFuncPutIcon1Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
extern void RTDOsdFuncPutIcon2Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
extern void RTDOsdFuncSet2BitIconOffset(BYTE ucOffset);
extern void RTDOsdFuncOsdTransparency(BYTE ucTrans);
extern void RTDOsdFuncOsdBlending(BYTE ucType);
extern void RTDOsdFuncClearOsdFont(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucChar);

//extern void RTDOsdFuncOsdDataPortWrite(WORD usLength, BYTE *pArray);
//extern void CFontFxLoadFontAddress(WORD usOffset);

#if(_OSD_3D_FUNCTION == _ON)
extern void RTDOsdFuncHLine(BYTE ucRow, BYTE ucCol, BYTE ucType, BYTE ucData);
#endif // End of #if(_OSD_3D_FUNCTION == _ON)

#endif


//----------------------------------------------------------------------------------------
// Extern functions from RTDOsdDisplay.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDDISPLAY__
extern void RTDOsdDispMainMenu(void);
extern void RTDOsdDispSelectItem(BYTE ucOsdstate);
extern void RTDOsdDispWindowZoomOut(BYTE ucOsdstate);
extern void RTDOsdDispPageItem(BYTE ucOsdstate);
extern void RTDOsdDispChangeKeyPadIcon(void);
extern void RTDOsdDispBackToMainIten(BYTE ucOsdstate);
extern void RTDOsdDispSliderAndNumber(BYTE ucOsdState, WORD usValue);
extern void RTDOsdDispOsdFunctionAdjust(BYTE ucOsdState);
extern void RTDOsdDispPressKey(void);
extern void RTDOsdDispOsdRotateSwitch(void);

#if(_OSD_3D_FUNCTION == _ON)
extern void RTDOsdDispOsd3DOSDSwitch(void);
#endif

extern void RTDOsdDispInputSourceHotKeyPage(void);
extern BYTE RTDOsdDisplayJudgeSourceType(void);
extern void RTDOsdDisplayTimingAndInputSource(void);
extern void RTDOsdDisplayNoSupportProc(void);
extern void RTDOsdDisplayFailSafeProc(void);
extern void RTDOsdDisplayNoSignalProc(void);
extern void RTDOsdDisplayNoCableProc(void);
extern void RTDOsdDisplayWakeUpShowSource();

#if(_VGA_SUPPORT == _ON) 
extern void RTDOsdDisplayAutoProc(void);
extern void RTDOsdDisplayAutoBalanceProc(void);
#endif

extern void RTDOsdDisplayShowLogo(void);
extern void RTDOsdDisplayOsdMessage(BYTE ucMessage);
extern void RTDOsdDisplayWakeUpSwitchDdcciPort();
extern void RTDOsdDisplayPowerSavingProc(void);
extern void RTDOsdDisplayBraceLR(BYTE ucRow);
extern void RTDOsdDisplaySetPosition(BYTE ucType, WORD usHPos, WORD usVPos);
extern void RTDOsdDisplayEnableOsdMove(WORD usX, WORD usY);
extern void RTDOsdDisplayDisableOsdMove(WORD usX, WORD usY);
extern void RTDOsdDisplayDisableOsd(void);
extern void RTDOsdDisplaySlider(BYTE ucRow, BYTE ucCol, BYTE ucLength, WORD usValue, WORD usMax, WORD usMin, BYTE ucColor);
extern WORD RTDOsdDisplayDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle);
extern void RTDOsdDisplayWindowZoomIn(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void RTDOsdDisplayWindowZoomOut(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void RTDOsdDisplayDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void RTDOsdDisplayPageItemUnselect(void);
extern void RTDOsdDisplayClearOSDPage(void);
extern void RTDOsdDisplayClear2BitIcon(void);
extern void RTDOsdDisplaySixColorGetOneColor(BYTE ucColor);
extern void RTDOsdDisplaySixColorSetOneColor(BYTE ucColor);

#if(_OSD_3D_FUNCTION == _ON)
extern void RTDOsdDisplay3DEffectRealValueUpdate();
extern void RTDOsdDisplayPageItemSelect3D(BYTE ucRow, BYTE ucCol);
extern void RTDOsdDisplayPageItemSelectUn3D(BYTE ucOsdstate);
#endif // End of #if(_OSD_3D_FUNCTION == _ON)

#endif

//----------------------------------------------------------------------------------------
// Extern functions from RTDOsdFont.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDFONT__
extern void RTDOsdFontLoadFont(BYTE ucState);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from RTDOsdTableFunc.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_OSDTABLEFUNC__
extern void RTDOsdTableFuncShowNumber(BYTE ucRow, BYTE ucCol, DWORD usValue, BYTE ucPar ,BYTE ucFontPoint);
extern BYTE RTDOsdTableFuncVideoResolution(void);
extern void RTDOsdTableFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, BYTE ucLanguage);
extern void RTDOsdTableFuncPutStringCenter(BYTE ucRow, BYTE ucColStart, BYTE ucColEnd, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, SBYTE ucCenterOffset , BYTE ucLanguage);
extern void RTDOsdTableFuncDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void RTDOsdTableFuncSetColorPalette(BYTE ucPaletteIndex, BYTE ucColorPalette);
extern void RTDOsdTableFuncPutIcon1BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
extern void RTDOsdTableFuncPutIcon2BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
#endif

#endif//#if(_OSD_TYPE == _REALTEK_2011_OSD)
