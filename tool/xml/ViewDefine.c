#include "Global.h"
#include "Project.h"
#include "customer_cfg.h"

#include "Panel_List.h"
#include "Global_Default_Config.h"

//定义分辨率提示
#if ((_PANEL_DH_WIDTH == 640)&&(_PANEL_DV_HEIGHT== 480))
#define PANEL_RESOLUTION_STR "640x480"
#elif ((_PANEL_DH_WIDTH == 800)&&(_PANEL_DV_HEIGHT == 600))
#define PANEL_RESOLUTION_STR "800x600"
#elif ((_PANEL_DH_WIDTH == 852)&&(_PANEL_DV_HEIGHT == 480))
#define PANEL_RESOLUTION_STR "852x480"
#elif ((_PANEL_DH_WIDTH == 960)&&(_PANEL_DV_HEIGHT == 540))
#define PANEL_RESOLUTION_STR "960x540"
#elif ((_PANEL_DH_WIDTH == 1024)&&(_PANEL_DV_HEIGHT == 576))
#define PANEL_RESOLUTION_STR "1024x576"
#elif ((_PANEL_DH_WIDTH == 1024)&&(_PANEL_DV_HEIGHT == 502))
#define PANEL_RESOLUTION_STR "1024x502"
#elif ((_PANEL_DH_WIDTH == 1024)&&(_PANEL_DV_HEIGHT == 600))
#define PANEL_RESOLUTION_STR "1024x600"
#elif ((_PANEL_DH_WIDTH == 1024)&&(_PANEL_DV_HEIGHT == 768))
#define PANEL_RESOLUTION_STR "1024x768"
#elif ((_PANEL_DH_WIDTH == 1152)&&(_PANEL_DV_HEIGHT == 768))
#define PANEL_RESOLUTION_STR "1152x768"
#elif ((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 720))
#define PANEL_RESOLUTION_STR "1280x720"
#elif ((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 768))
#define PANEL_RESOLUTION_STR "1280x768"
#elif ((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 800))
#define PANEL_RESOLUTION_STR "1280x800"
#elif ((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 854))
#define PANEL_RESOLUTION_STR "1280x854"
#elif ((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 960))
#define PANEL_RESOLUTION_STR "1280x960"
#elif ((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 1024))
#define PANEL_RESOLUTION_STR "1280x1024"
#elif ((_PANEL_DH_WIDTH == 1366)&&(_PANEL_DV_HEIGHT == 768))
#define PANEL_RESOLUTION_STR "1366x768"
#elif ((_PANEL_DH_WIDTH == 1380)&&(_PANEL_DV_HEIGHT == 768))
#define PANEL_RESOLUTION_STR "1380x768"
#elif ((_PANEL_DH_WIDTH == 1400)&&(_PANEL_DV_HEIGHT == 1050))
#define PANEL_RESOLUTION_STR "1400x1050"
#elif ((_PANEL_DH_WIDTH == 1440)&&(_PANEL_DV_HEIGHT == 900))
#define PANEL_RESOLUTION_STR "1440x900"
#elif ((_PANEL_DH_WIDTH == 1440)&&(_PANEL_DV_HEIGHT == 960))
#define PANEL_RESOLUTION_STR "1440x960"
#elif ((_PANEL_DH_WIDTH == 1600)&&(_PANEL_DV_HEIGHT == 900))
#define PANEL_RESOLUTION_STR "1600x900"
#elif ((_PANEL_DH_WIDTH == 1600)&&(_PANEL_DV_HEIGHT == 1200))
#define PANEL_RESOLUTION_STR "1600x1200"
#elif ((_PANEL_DH_WIDTH == 1680)&&(_PANEL_DV_HEIGHT == 945))
#define PANEL_RESOLUTION_STR "1680x945"
#elif ((_PANEL_DH_WIDTH == 1680)&&(_PANEL_DV_HEIGHT == 1050))
#define PANEL_RESOLUTION_STR "1680x1050"
#elif ((_PANEL_DH_WIDTH == 1920)&&(_PANEL_DV_HEIGHT == 1080))
#define PANEL_RESOLUTION_STR "1920x1080"
#elif ((_PANEL_DH_WIDTH == 1920)&&(_PANEL_DV_HEIGHT == 1200))
#define PANEL_RESOLUTION_STR "1920x1200"
#elif ((_PANEL_DH_WIDTH == 2048)&&(_PANEL_DV_HEIGHT == 1152))
#define PANEL_RESOLUTION_STR "2048x1152"
#elif ((_PANEL_DH_WIDTH == 1600)&&(_PANEL_DV_HEIGHT == 1024))
#define PANEL_RESOLUTION_STR "1600x1024"
#elif ((_PANEL_DH_WIDTH == 800)&&(_PANEL_DV_HEIGHT == 480))
#define PANEL_RESOLUTION_STR "800x480"
#elif ((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 600))
#define PANEL_RESOLUTION_STR "1280x600"
#elif ((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 390))
#define PANEL_RESOLUTION_STR "1280x390"
#elif ((_PANEL_DH_WIDTH == 2048)&&(_PANEL_DV_HEIGHT == 1536))
#define PANEL_RESOLUTION_STR "2048x1536"
#elif ((_PANEL_DH_WIDTH == 1024)&&(_PANEL_DV_HEIGHT == 480))
#define PANEL_RESOLUTION_STR "1024x480"
#elif ((_PANEL_DH_WIDTH == 1280)&&(_PANEL_DV_HEIGHT == 480))
#define PANEL_RESOLUTION_STR "1280x480"
#elif ((_PANEL_DH_WIDTH == 1680)&&(_PANEL_DV_HEIGHT == 342))
#define PANEL_RESOLUTION_STR "1680x342"
#elif ((_PANEL_DH_WIDTH == 1366)&&(_PANEL_DV_HEIGHT == 1024))
#define PANEL_RESOLUTION_STR "1366x1024"
#elif ((_PANEL_DH_WIDTH == 2560)&&(_PANEL_DV_HEIGHT == 1080))
#define PANEL_RESOLUTION_STR "2560x1080"
#elif ((_PANEL_DH_WIDTH == 2560)&&(_PANEL_DV_HEIGHT == 1440))
#define PANEL_RESOLUTION_STR "2560x1440"
#else
#define PANEL_RESOLUTION_STR "2560x1080"
#endif
 

#define _OSD_LANGUAGE_DEFAULT    CVT_DEF_OSD_LANG

#if (_OSD_LANGUAGE_DEFAULT == _ENGLISH)
#define DEFAULT_OSD_LANGUAGE_NAME "ENGLISH"
#define CVT_DEF_LANG "ENGLISH"
#elif _OSD_LANGUAGE_DEFAULT==_CHINESE_S
#define DEFAULT_OSD_LANGUAGE_NAME "SIP_CHINESE"
#define CVT_DEF_LANG "CHINESE_SIMPLIFIED"
#elif _OSD_LANGUAGE_DEFAULT==_GERMAN
#define DEFAULT_OSD_LANGUAGE_NAME "GERMAN"
#define CVT_DEF_LANG "GERMAN"
#elif _OSD_LANGUAGE_DEFAULT==_FRENCH
#define DEFAULT_OSD_LANGUAGE_NAME "FRENCH"
#define CVT_DEF_LANG "FRENCH"
#elif _OSD_LANGUAGE_DEFAULT== _ITALIAN
#define DEFAULT_OSD_LANGUAGE_NAME "ITALIAN"
#define CVT_DEF_LANG "ITALIAN"
#elif _OSD_LANGUAGE_DEFAULT==_SPANISH
#define DEFAULT_OSD_LANGUAGE_NAME "SPANISH"
#define CVT_DEF_LANG "SPANISH"
#elif _OSD_LANGUAGE_DEFAULT==_POLISH
#define DEFAULT_OSD_LANGUAGE_NAME "POLISH"
#define CVT_DEF_LANG "POLISH"
#else
#error "Please define default language"
#endif

#pragma message("ocs_check_start")
#pragma message("分辨率--------:"PANEL_RESOLUTION_STR"")
#pragma message("PANEL_RES "PANEL_RESOLUTION_STR"")


#pragma message("背光控制方式--:")
#pragma message("1.频率(单位Hz):")
#pragma message("CVT_BLACKLIGHT_PWM_FREQ")
#pragma message(CVT_DEF_PANEL_CONF_PWM_FREQ)
#pragma message("2.工厂BACKLIGHT值:")
#pragma message("CVT_DEF_BACKLIGHT")
#pragma message(CVT_DEF_BACKLIGHT_VALUE)
#pragma message("3.最大占空比:")
//#pragma message("CVT_DEF_CURRENT_REF_DUTY")
//#pragma message(CVT_DEF_REF_DUTY)

#pragma message("$=========================== OSD语言 ===========================")
#pragma message("$默认语言:"DEFAULT_OSD_LANGUAGE_NAME"")
#pragma message("CVT_DEF_LANG "CVT_DEF_LANG"")
#if CVT_EN_LANG_ENGLISH
#pragma message("$--------LANG_ENGLISH_ENABLE")
#endif
#if CVT_EN_LANG_GERMAN
#pragma message("$--------LANG_GERMAN_ENABLE")
#endif
#if CVT_EN_LANG_FRANCE
#pragma message("$--------LANG_FRENCH_ENABLE")
#endif
#if CVT_EN_LANG_ITALIAN
#pragma message("$--------LANG_ITALIAN_ENABLE")
#endif
#if CVT_EN_LANG_SPANISH
#pragma message("$--------LANG_SPANISH_ENABLE")
#endif
#if CVT_EN_LANG_RUSSIA 
#pragma message("$--------LANG_RUSSIAN_ENABLE")
#endif
#if CVT_EN_LANG_DUTCH
#pragma message("$--------LANG_DUTCH_ENABLE")
#endif
#if CVT_EN_LANG_SUOMALAINEN
#pragma message("$--------LANG_SUOMALAINEN_ENABLE")
#endif
#if CVT_EN_LANG_TURKISH
#pragma message("$--------LANG_TURKISH_ENABLE")
#endif
#if CVT_EN_LANG_POLISH
#pragma message("$--------LANG_POLISH_ENABLE")
#endif
#if CVT_EN_LANG_PORTUGUES
#pragma message("$--------LANG_PORTUGUESE_ENABLE")
#endif
#if CVT_EN_LANG_TCHINA
#pragma message("$--------LANG_CHINESE_TRADITIONAL_ENABLE")
#endif
#if CVT_EN_LANG_SCHINA 
#pragma message("$--------LANG_CHINESE_SIMPLIFIED_ENABLE")
#endif
#if CVT_EN_LANG_JAPANESE 
#pragma message("$--------LANG_JAPANESE_ENABLE")
#endif
#if CVT_EN_LANG_BRAZIPORTUGUESE 
#pragma message("$--------LANG_BRAZIPORTUGUESE_ENABLE")
#endif
#if CVT_EN_LANG_KOREA 
#pragma message("$--------LANG_KOREAN_ENABLE")
#endif

#pragma message("$=========================== 软件SOURCE定义===========================")
#if CVT_EN_DP_SOURCE
#pragma message("$---------------(DP)ENABLE_DP")
#endif

#if CVT_EN_VGA_SOURCE
#pragma message("$---------------(VGA)ENABLE_VGA")
#endif

#if CVT_EN_HDMI1_SOURCE
#pragma message("$---------------(HDMI)ENABLE_HDMI")
#endif

#if CVT_EN_HDMI2_SOURCE
#pragma message("$---------------(HDMI2)ENABLE_HDMI2")
#endif

#if CVT_EN_DVI_SOURCE
#pragma message("$---------------(DVI)ENABLE_DVI")
#endif

#pragma message("$=========================== 按键定义(k0~k5)==========================")
#pragma message("${")
#pragma message("CVT_KEYPAD_TYPE "CVT_DEF_KEYPAD_ADC_TYPE"")
#pragma message(KEY_AD_K0)
#pragma message(KEY_AD_K1)
#pragma message(KEY_AD_K2)
#pragma message(KEY_AD_K3)
#pragma message(KEY_AD_K4)
#pragma message(KEY_AD_K5)
#pragma message("$}")

#pragma message("$=========================== 主板==========================")
#pragma message("${")
#pragma message("$板卡----------:"BOARD_NAME"")
#pragma message("MAIN_BOARD "BOARD_NAME"")
#pragma message("$芯片类型------:"CVT_DEF_CHIP_NAME"")
#pragma message("CHIP_NAME "CVT_DEF_CHIP_NAME"")
#pragma message("$}")

#pragma message("屏------------:"PanelName"")
#pragma message("PANEL_TYPE "PanelName"")

#pragma message("$=========================== LOGO==========================")
#pragma message("LOGO_TYPE "CVT_DEF_LOGO_TYPE"")
#pragma message("$=========================== 菜单样式==========================")
#pragma message("MENU_STYLE "MENU_TYPE"")

/*
#define CVT_EN_FIXED_BUILD_TIME
#pragma message("Fixed_Checksum "CVT_DEF_FIXED_CHECKSUM"")
#endif
*/ 

#pragma message("SW_HDCP "StrToVal(CVT_DEF_XML_SW_HDCP)"")
#pragma message("SW_AAC "CVT_DEF_XML_SW_AAC"")
#pragma message("SW_DOLBY "StrToVal(CVT_DEF_XML_SW_DOLBY)"")
#pragma message("SW_Chipset_SubCode "CVT_DEF_XML_SW_CHIPSET_SUBCODE"")
#pragma message("SW_PWM_Freq "StrToVal(CVT_DEF_PANEL_CONF_PWM_FREQ)"")

#ifndef CVT_DEF_CUSTOMER_MSG1
#define CVT_DEF_CUSTOMER_MSG1       "可定义CVT_DEF_CUSTOMER_MSG1至CVT_DEF_CUSTOMER_MSG10来描述"
#endif

#pragma message("$===========================客户特殊信息==========================")
#pragma message("${")
#pragma message("CUSTOMER_MSG")
#ifdef CVT_DEF_CUSTOMER_MSG1
#pragma message("MSG:"CVT_DEF_CUSTOMER_MSG1"")
#endif

#pragma message("$}")

#define SVN_URL_COM "SVN_URL tv@git.gz.cvte.cn/RTD2270/source/base/code.git -b lenovo"
#pragma message(SVN_URL_COM)

#pragma message("ocs_check_end")
#ifndef CVT_DEF_ModeID2Str_In_BIN
#define CVT_DEF_ModeID2Str_In_BIN       Maco2Str(CUSTOMER_ID)
#endif
#pragma message("BIN_NAME "CVT_DEF_ModeID2Str_In_BIN"")

