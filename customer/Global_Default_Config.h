#ifndef __GLOBAL_DEFAULT_CONFIG_H__
#define __GLOBAL_DEFAULT_CONFIG_H__

#include "Global_Product_Define.h"

#define ENABLE                                              1
#define DISABLE                                             0


/*****************CVT_DEF_CODE_VERSION****************************
(1)function:If changed,will load default edid ,for all source,must not be changed
(2)vaule:0x01~0xff
(3)author:yubaozhu
(4)date 20170622
*/
#define CVT_DEF_CODE_VERSION                                0x02

/*****************CVT_EN_DP_SOURCE****************************
(1)function
(2)vaule:
(3)author:yubaozhu
(4)date 20170622
**************************END********************************/
#ifndef CVT_EN_DP_SOURCE                                    
#define CVT_EN_DP_SOURCE                                    DISABLE
#endif

/*****************CVT_EN_DP_SOURCE****************************
(1)function
(2)vaule:
(3)author:yubaozhu
(4)date 20170622
**************************END********************************/
#ifndef CVT_EN_VGA_SOURCE                                    
#define CVT_EN_VGA_SOURCE                                    DISABLE
#endif

/*****************CVT_EN_DOLBY****************************
(1)function
(2)vaule:
(3)author:xiangjianhe
(4)date 20171122
**************************END********************************/
#ifndef CVT_EN_DOLBY                                    
#define CVT_EN_DOLBY                                        DISABLE
#endif


/*****************CVT_EN_DP_SOURCE****************************
(1)function
(2)vaule:
(3)author:yubaozhu
(4)date 20170622
**************************END********************************/
#ifndef CVT_EN_DVI_SOURCE                                    
#define CVT_EN_DVI_SOURCE                                    DISABLE
#endif

/*****************CVT_EN_DP_SOURCE****************************
(1)function
(2)vaule:
(3)author:yubaozhu
(4)date 20170622
**************************END********************************/                                    
#ifndef CVT_EN_HDMI1_SOURCE                                    
#define CVT_EN_HDMI1_SOURCE                                 DISABLE
#endif

/*****************CVT_EN_DP_SOURCE****************************
(1)function
(2)vaule:
(3)author:yubaozhu
(4)date 20170622
**************************END********************************/
#ifndef CVT_EN_HDMI2_SOURCE                                    
#define CVT_EN_HDMI2_SOURCE                                 DISABLE
#endif

/*================================
//����PWMƵ������(60~60khz)
=================================*/
#ifndef CVT_DEF_PANEL_CONF_PWM_FREQ
#define CVT_DEF_PANEL_CONF_PWM_FREQ                         25000
#endif

/****************CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER*****************
 (1)Ĭ��ֵ:ENABLE
 (2)��Χ˵��: ENABLE/DISABLE
 (3)��������: �ñ���ADJ�ڿ��Ʊ���Ŀ���
 (4)����&����:  xiangjianhe@20170522
*********************************************************/
#ifndef CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER
#define CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER                  DISABLE
#endif

/****************CVT_EN_ON_LINE_WRITE_EDID*****************
 (1)Ĭ��ֵ:ENABLE
 (2)��Χ˵��: ENABLE/DISABLE
 (3)��������: ��ԭ��������¼EDID
 (4)����&����:  xiangjianhe@20170523
*********************************************************/
#ifndef CVT_EN_ON_LINE_WRITE_EDID
#define CVT_EN_ON_LINE_WRITE_EDID                           DISABLE
#endif

/****************CVT_EN_ON_LINE_WRITE_EDID*****************
 (1)Ĭ��ֵ:DISABLE
 (2)��Χ˵��: ENABLE/DISABLE
 (3)��������: ���������Ҫ�Ǻ㷢���Ҫ����¼EDID Ҫ����5�룬����ֻ
 ��¼һ��ͨ����EDID��Ȼ��ͨ��ͬ���ķ�ʽʹ������ͨ����EDIDȫ��ͬ����ȥ
 ������ʹ���ٶ��ϸ����ˡ��Ż�������
 (4)����&����:  xiangjianhe@20170829
*********************************************************/
#ifndef CVT_EN_SYNC_EDID_SUPPORT
#define CVT_EN_SYNC_EDID_SUPPORT                            DISABLE
#endif

/****************CVT_EN_OSD_MENU_ALIGN_RIGHT*****************
 (1)Ĭ��ֵ:ENABLE
 (2)��Χ˵��: ENABLE/DISABLE
 (3)��������: Acer �˵�Ĭ�Ͽ��ұߣ��������HPOS���ڷ���
 (4)����&����:  xiangjianhe@20170526
*********************************************************/
#ifndef CVT_EN_OSD_MENU_ALIGN_RIGHT
#define CVT_EN_OSD_MENU_ALIGN_RIGHT                         ENABLE
#endif

/****************CVT_EN_AC_ON_KEYMENU_ENTER_FAC_BURNIN*****************
 (1)Ĭ��ֵ:ENABLE
 (2)��Χ˵��: ENABLE/DISABLE
 (3)��������: Acer �˵�AC�ϵ磬��סMenu����������
 (4)����&����:  xiangjianhe@20170601
*********************************************************/
#ifndef CVT_EN_AC_ON_KEYMENU_ENTER_FAC_BURNIN
#define CVT_EN_AC_ON_KEYMENU_ENTER_FAC_BURNIN               ENABLE
#endif

/****************CVT_EN_FACTORY_MODE*****************
 (1)Ĭ��ֵ:ENABLE
 (2)��Χ˵��: ENABLE/DISABLE
 (3)��������: Acer ���ӹ����˵�
 (4)����&����:  xiangjianhe@20170601
*********************************************************/
#ifndef CVT_EN_FACTORY_MODE
#define CVT_EN_FACTORY_MODE                                 ENABLE
#endif

/****************CVT_EN_DCR_SUPPORT************************
 (1)Ĭ��ֵ:ENABLE
 (2)��Χ˵��: ENABLE/DISABLE
 (3)��������: DCR���ܿ���
 (4)����&����:  xiangjianhe@20170622
*********************************************************/
#ifndef CVT_EN_DCR_SUPPORT
#define CVT_EN_DCR_SUPPORT                                  ENABLE
#endif

/****************CVT_EN_AUDIO_HEADPHONE_SPEAKER_SEPARATE_SUPPORT************************
 (1)Ĭ��ֵ:ENABLE
 (2)��Χ˵��: ENABLE/DISABLE
 (3)��������: TPA3136�������ȺͶ����Ƿֳ�2·��Ƶ������Ĭ�Ϻ�Ҫ�����ֳ����Ȼ��Ƕ������
 (4)����&����:  xiangjianhe@20170707
*********************************************************/
#ifndef CVT_EN_AUDIO_HEADPHONE_SPEAKER_SEPARATE_SUPPORT
#define CVT_EN_AUDIO_HEADPHONE_SPEAKER_SEPARATE_SUPPORT     ENABLE
#endif

/****************CVT_EN_HOTPLUS_STANDARD ************************
 (1)Ĭ��ֵ:ENABLE
 (2)��Χ˵��: ENABLE/DISABLE
 (3)��������: ����CVT��HPD�淶����
 (4)����&����:  xiangjianhe@20170714
*********************************************************/
#ifndef CVT_EN_HOTPLUS_STANDARD
#define CVT_EN_HOTPLUS_STANDARD                             ENABLE
#endif

/****************CVT_EN_ADJUST_BRIGHTNESS_REDUCED_RANGE ************************
 (1)Ĭ��ֵ:DISABLE
 (2)��Χ˵��: ENABLE/DISABLE [AOC���а������������ĵ�Ϊ��׼��������С����Ч����Χ����]
              �ͻ�����ֵSTEPΪ10,  �м�ֵ CENTRAL_STANDARD_VALUE ����Сϵ��ZOOM_RATION
              �˹����������ư������ع���Ч������ǿ�ң�������Сϵ��
 (3)��������: WORD UserAdjustReducedRangeFunction(WORD usBrightness)
 (4)����&����:  xiangjianhe@20170710
*********************************************************/
#ifndef CVT_EN_ADJUST_BRIGHTNESS_REDUCED_RANGE
#define CVT_EN_ADJUST_BRIGHTNESS_REDUCED_RANGE              DISABLE
#endif

/*************CVT_EN_TMDS_NOT_AUDIO_PACKET_SW_LINE_IN_AUDIO**********************
 (1)Ĭ��ֵ: ENABLE [CVT Standard]
 (2)��Χ˵��: ENABLE / DISABLE
 (3)��������: ����ͨ�����ȼ�⵱ǰTmdsͨ���Ƿ���������
 ������HDMIͨ������û��Ƶ����&&��Ƶ��ʽΪDVI���л���ģ������
 (4)����&����:  xiangjianhe@20170714
*********************************************************/
#ifndef CVT_EN_TMDS_NOT_AUDIO_PACKET_SW_LINE_IN_AUDIO
#define CVT_EN_TMDS_NOT_AUDIO_PACKET_SW_LINE_IN_AUDIO       DISABLE
#endif

/**************CVT_EN_BACKLING_PWM_FREQ_BY_VFREQ**********
 (1)Default Value: 1
 (2)Range: 0/1
 (3)Description: �˺���� BrightFreqByVfre ���ô��ݲ���
 (4)Author&Date:  HuangYong@2016/11/10
*********************************************************/
#ifndef CVT_EN_BACKLING_PWM_FREQ_BY_VFREQ
#define CVT_EN_BACKLING_PWM_FREQ_BY_VFREQ                   1   
#endif /* CVT_EN_BACKLING_PWM_FREQ_BY_VFREQ */

/***************CVT_EN_BACKLING_PWM_VSYNC_ALING***********
 (1)Default Value: 1
 (2)Range: 0/1
 (3)Description: �˺���� BRIGHTNESS_VSYNC_ALIG ���ô��ݲ���
 (4)Author&Date:  HuangYong@2016/11/10
*********************************************************/
#ifndef CVT_EN_BACKLING_PWM_VSYNC_ALING
#define CVT_EN_BACKLING_PWM_VSYNC_ALING                     1
#endif /* CVT_EN_BACKLING_PWM_VSYNC_ALING */

/*******************CVT_DEF_BACKLIGHT_VALUE***************
 (1)Default Value: 80
 (2)Range: 0~100
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_DEF_BACKLIGHT_VALUE
#define CVT_DEF_BACKLIGHT_VALUE                            80
#endif /* CVT_DEF_BACKLIGHT_VALUE */

/***********************CVT_EN_VGA_SOG********************
 (1)Default Value: 0
 (2)Range: 0/1
 (3)Description: Suport VGA SOG signal input
 (4)Author&Date:  HuangYong@2016/12/19
*********************************************************/
#ifndef CVT_EN_VGA_SOG
#define CVT_EN_VGA_SOG                                     DISABLE
#endif /* CVT_EN_VGA_SOG */

/********************CVT_DEF_CUS_ODM_NAME*****************
 (1)Default Value: ODM_OTHER
 (2)Range: 
 (3)Description: CUS ODM 
 (4)Author&Date:  HuangYong@2016/11/15
*********************************************************/
#ifndef CVT_DEF_CUS_ODM_NAME
#define CVT_DEF_CUS_ODM_NAME                                ODM_OTHER          
#endif /* CVT_DEF_CUS_ODM_NAME */

/******************CVT_DEF_CUS_MONITOR_NAME***************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/11/15
*********************************************************/
#ifndef CVT_DEF_CUS_MONITOR_NAME
#define CVT_DEF_CUS_MONITOR_NAME                            "XXXXXXXX"
#endif /* CVT_DEF_CUS_MONITOR_NAME */

/********************CVT_DEF_CUS_SW_VERSION****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/11/15
*********************************************************/
#ifndef CVT_DEF_CUS_SW_VERSION
#define CVT_DEF_CUS_SW_VERSION                              "010"    
#endif /* CVT_DEF_CUS_SW_VERSION */

/*****************CVT_DEF_CUS_SW_CHANGE_DATE**************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/11/15
*********************************************************/
#ifndef CVT_DEF_CUS_SW_CHANGE_DATE
#define CVT_DEF_CUS_SW_CHANGE_DATE                          "2016-11-15"
#endif /* CVT_DEF_CUS_SW_CHANGE_DATE */

/*****************CVT_DEF_KEYPAD_CONVERT_TYPE*************
 (1)Default Value: 
 (2)Range: 
 (3)Description: ���ø��ϰ����Ķ���
 (4)Author&Date:  HuangYong@2016/12/08
*********************************************************/
#ifndef CVT_DEF_KEYPAD_CONVERT_TYPE
#define CVT_DEF_KEYPAD_CONVERT_TYPE                     KEYPAD_CONVERT_CVT_DEFAULT     
#endif /* CVT_DEF_KEYPAD_CONVERT_TYPE */

/*******************CVT_DEF_KEYPAD_ADC_TYPE***************
 (1)Default Value: 
 (2)Range: 
 (3)Description: ����ADC�����ĵ�������
 (4)Author&Date:  HuangYong@2016/12/08
*********************************************************/
#ifndef CVT_DEF_KEYPAD_ADC_TYPE
#define CVT_DEF_KEYPAD_ADC_TYPE                         KEYPAD_ADC_CVT_DEFAULT
#endif /* CVT_DEF_KEYPAD_ADC_TYPE */

/*********************CVT_EN_LANG_ENGLISH*****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_ENGLISH
#define CVT_EN_LANG_ENGLISH                             ENABLE
#endif /* CVT_EN_LANG_ENGLISH */

/*********************CVT_EN_LANG_GERMAN******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_GERMAN
#define CVT_EN_LANG_GERMAN                              DISABLE
#endif /* CVT_EN_LANG_GERMAN */

/*********************CVT_EN_LANG_FRANCE******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_FRANCE
#define CVT_EN_LANG_FRANCE                              DISABLE
#endif /* CVT_EN_LANG_FRANCE */

/*********************CVT_EN_LANG_ITALIAN*****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_ITALIAN
#define CVT_EN_LANG_ITALIAN                             DISABLE
#endif /* CVT_EN_LANG_ITALIAN */

/*********************CVT_EN_LANG_SPANISH*****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_SPANISH
#define CVT_EN_LANG_SPANISH                             DISABLE    
#endif /* CVT_EN_LANG_SPANISH */

/*********************CVT_EN_LANG_SCHINA******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_SCHINA
#define CVT_EN_LANG_SCHINA                              DISABLE    
#endif /* CVT_EN_LANG_SCHINA */

/*********************CVT_EN_LANG_TCHINA******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_TCHINA
#define CVT_EN_LANG_TCHINA                              DISABLE
#endif /* CVT_EN_LANG_TCHINA */

/********************CVT_EN_LANG_JAPANESE*****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_JAPANESE
#define CVT_EN_LANG_JAPANESE                            DISABLE
#endif /* CVT_EN_LANG_JAPANESE */

/*********************CVT_EN_LANG_RUSSIA******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_RUSSIA
#define CVT_EN_LANG_RUSSIA                              DISABLE
#endif /* CVT_EN_LANG_RUSSIA */

/*********************CVT_EN_LANG_SWEDISH*****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_SWEDISH
#define CVT_EN_LANG_SWEDISH                             DISABLE
#endif /* CVT_EN_LANG_SWEDISH */

/*********************CVT_EN_LANG_FINNISH*****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_FINNISH
#define CVT_EN_LANG_FINNISH                             DISABLE
#endif /* CVT_EN_LANG_FINNISH */

/*********************CVT_EN_LANG_POLISH******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_POLISH
#define CVT_EN_LANG_POLISH                              DISABLE
#endif /* CVT_EN_LANG_POLISH */

/**********************CVT_EN_LANG_DUTCH******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_DUTCH
#define CVT_EN_LANG_DUTCH                               DISABLE
#endif /* CVT_EN_LANG_DUTCH */

/********************CVT_EN_LANG_PORTUGUES****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_PORTUGUES
#define CVT_EN_LANG_PORTUGUES                           DISABLE
#endif /* CVT_EN_LANG_PORTUGUES */

/********************CVT_EN_LANG_CZECH****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_CZECH
#define CVT_EN_LANG_CZECH                               DISABLE
#endif /* CVT_EN_LANG_CZECH */

/**********************CVT_EN_LANG_SUOMALAINEN******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_SUOMALAINEN
#define CVT_EN_LANG_SUOMALAINEN                          DISABLE
#endif /* CVT_EN_LANG_SUOMALAINEN */

/*********************CVT_EN_LANG_TURKISH*****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_TURKISH
#define CVT_EN_LANG_TURKISH                             DISABLE
#endif /* CVT_EN_LANG_TURKISH */

/*********************CVT_EN_LANG_BRAZIPORTUGUESE*****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_BRAZIPORTUGUESE
#define CVT_EN_LANG_BRAZIPORTUGUESE                      DISABLE
#endif /* CVT_EN_LANG_BRAZIPORTUGUESE */

/**********************CVT_EN_LANG_KOREA******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_LANG_KOREA
#define CVT_EN_LANG_KOREA                                DISABLE
#endif /* CVT_EN_LANG_KOREA */

/**********************CVT_DEF_OSD_LANG*******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_DEF_OSD_LANG
#define CVT_DEF_OSD_LANG                                DEF_LANG_ENGLISH                   
#endif /* CVT_DEF_OSD_LANG */

/********************CVT_EN_FAC_AUTO_TEST*****************
 (1)Default Value: 
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_FAC_AUTO_TEST
#define CVT_EN_FAC_AUTO_TEST                            DISABLE
#endif /* CVT_EN_FAC_AUTO_TEST */

/**********************CVT_EN_UART_DEBUG******************
 (1)Default Value: 
 (2)Range: 
 (3)Description: Debug.h [config]
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_EN_UART_DEBUG
#define CVT_EN_UART_DEBUG                               DISABLE
#endif /* CVT_EN_UART_DEBUG */

/******************CVT_DEF_HDCPKEY_USE_FROM***************
 (1)Default Value: HDCPKEY_IN_FLASH
 (2)Range: 
 (3)Description: 
 (4)Author&Date:  HuangYong@2016/12/09
*********************************************************/
#ifndef CVT_DEF_HDCPKEY_USE_FROM
#define CVT_DEF_HDCPKEY_USE_FROM                        HDCPKEY_IN_CODE
#endif /* CVT_DEF_HDCPKEY_USE_FROM */

/******************CVT_EN_MAIN_MENU_SOURCE_ITEM***************
 (1)Default Value: ENABLE
 (2)Range: 0/1
 (3)Description: �Ƿ���Ҫ�����˵�������SOURCE
 (4)Author&Date:  HuangYong@2016/12/22
*********************************************************/
#ifndef CVT_EN_MAIN_MENU_SOURCE_ITEM
#define CVT_EN_MAIN_MENU_SOURCE_ITEM                    ENABLE
#endif /* CVT_EN_MAIN_MENU_SOURCE_ITEM */

/**************CVT_EN_HOTKEY_INPUT_SOURCE_SELECT**********
 (1)Default Value: ENABLE
 (2)Range: 0/1
 (3)Description: �Ƿ�֧�ֿ�ݼ���������ͨ��
 (4)Author&Date:  HuangYong@2016/12/22
*********************************************************/
#ifndef CVT_EN_HOTKEY_INPUT_SOURCE_SELECT
#define CVT_EN_HOTKEY_INPUT_SOURCE_SELECT               ENABLE
#endif /* CVT_EN_HOTKEY_INPUT_SOURCE_SELECT */

/**************CVT_EN_AOC_MULTI_KEYPAD_SPECIAL**********
 (1)Default Value: DISABLE
 (2)Range: 0/1
 (3)Description: �Ƿ�֧��AOC ���ⰴ����(����֧�ָ���)   conflict with ENABLE_AllinOne_Key
 (4)Author&Date:  chenshaogui@2017/01/03
*********************************************************/
#ifndef CVT_EN_AOC_MULTI_KEYPAD_SPECIAL
#define CVT_EN_AOC_MULTI_KEYPAD_SPECIAL                 DISABLE
#endif /* CVT_EN_AOC_MULTI_KEYPAD_SPECIAL */

/**************CVT_EN_PRESS_MINUS_ACON_ENTER_FACTORYMENU**********
 (1)Default Value: ENABLE
 (2)Range: 0/1
 (3)Description:��"-"���β��Դ�ϵ翪�����빤���˵�
 (4)Author&Date:  chenshaogui@2017/01/05
*********************************************************/
#ifndef CVT_EN_PRESS_MINUS_ACON_ENTER_FACTORYMENU
#define CVT_EN_PRESS_MINUS_ACON_ENTER_FACTORYMENU        ENABLE
#endif /* CVT_EN_PRESS_MINUS_ACON_ENTER_FACTORYMENU */

/********************CVT_DEF_VOLUME_VALUE*****************
 (1)Default Value: 50
 (2)Range: 0~100
 (3)Description: ����Ĭ������
 (4)Author&Date:  HuangYong@2017/01/06
*********************************************************/
#ifndef CVT_DEF_VOLUME_VALUE
#define CVT_DEF_VOLUME_VALUE                            50
#endif /* CVT_DEF_VOLUME_VALUE */

/********************CVT_EN_VGAEDID_IN_FLASH*****************
 (1)Default Value: ENABLE
 (2)Range: 0/1
 (3)Description: VGA EDID����
 (4)Author&Date:  chenshaogui@2017/01/10
*********************************************************/
#ifndef CVT_EN_VGAEDID_IN_FLASH
#define CVT_EN_VGAEDID_IN_FLASH                          DISABLE
#endif /* CVT_EN_VGAEDID_IN_FLASH */

/********************CVT_EN_HDMIEDID_IN_FLASH*****************
 (1)Default Value: DISABLE
 (2)Range: 0/1
 (3)Description: HDMI EDID����
 (4)Author&Date:  chenshaogui@2017/01/10
*********************************************************/
#ifndef CVT_EN_HDMIEDID_IN_FLASH
#define CVT_EN_HDMIEDID_IN_FLASH                          DISABLE
#endif /* CVT_EN_HDMIEDID_IN_FLASH */

/********************CVT_EN_CVT_FACTORY_MENU*****************
 (1)Default Value: DISABLE
 (2)Range: 0/1
 (3)Description: ����CVT�����˵�
 (4)Author&Date:  chenshaogui@2017/01/12
*********************************************************/
#ifndef CVT_EN_CVT_FACTORY_MENU
#define CVT_EN_CVT_FACTORY_MENU                          DISABLE
#endif /* CVT_EN_CVT_FACTORY_MENU */

/********************CVT_DEF_PANEL_TYPE*****************
 (1)Default Value: PNL_GENERAL_1920_1080
 (2)Range:
 (3)Description:
 (4)Author&Date:  yubaozhu@2017/02/14
*********************************************************/
#ifndef CVT_DEF_PANEL_TYPE
#define CVT_DEF_PANEL_TYPE    PNL_GENERAL_1920_1080
#endif /* CVT_DEF_PANEL_TYPE */

/********************CVT_DEF_FIX_VERSION_NUMBER*****************
 (1)Default Value: 0xFF19
 (2)Range: 
 (3)Description: �̶���checksum
 (4)Author&Date:  bigzhanghao@2017/01/16
*********************************************************/
#ifndef CVT_DEF_FIX_VERSION_NUMBER
#define CVT_DEF_FIX_VERSION_NUMBER                        0xFF19
#endif /* CVT_DEF_FIX_VERSION_NUMBER */

/********************CVT_EN_FIX_CHECKSUM*****************
 (1)Default Value: DISABLE
 (2)Range: 0/1
 (3)Description: �����̶�checksum����
 (4)Author&Date:  hongzhipeng@2017/02/17
*********************************************************/
#ifndef CVT_EN_FIX_CHECKSUM
#define CVT_EN_FIX_CHECKSUM                              DISABLE
#endif /* CVT_EN_FIX_CHECKSUM */

/********************CVT_EN_CVT_EDID*****************
 (1)Default Value: DISABLE
 (2)Range:0/1 
 (3)Description: ʹ��CVT��EDID
 (4)Author&Date:  chenshaogui@2017/02/04
*********************************************************/
#ifndef CVT_EN_CVT_EDID
#define CVT_EN_CVT_EDID                                  DISABLE
#endif /* CVT_EN_CVT_EDID */
/********************CVT_EN_4K2K_MAX_60HZ_444*****************
 (1)Default Value: DISABLE
 (2)Range:0/1 
 (3)Description: ֧��4K2K_60HZ_444,���CVT_EN_4K2K_MAX_30HZ_444��CVT_EN_4K2K_MAX_60HZ_420���⣬��򿪺�CVT_EN_CVT_EDID
 (4)Author&Date:  chenshaogui@2017/02/04
*********************************************************/
#ifndef CVT_EN_4K2K_MAX_60HZ_444
#define CVT_EN_4K2K_MAX_60HZ_444                          DISABLE
#endif /* CVT_EN_4K2K_MAX_60HZ_444 */

/********************CVT_EN_4K2K_MAX_30HZ_444*****************
 (1)Default Value: DISABLE
 (2)Range:0/1 
 (3)Description: ֧��4K2K_60HZ_444,���CVT_EN_4K2K_MAX_60HZ_444��CVT_EN_4K2K_MAX_60HZ_420���⣬��򿪺�CVT_EN_CVT_EDID
 (4)Author&Date:  chenshaogui@2017/02/04
*********************************************************/
#ifndef CVT_EN_4K2K_MAX_30HZ_444
#define CVT_EN_4K2K_MAX_30HZ_444                          DISABLE
#endif /* CVT_EN_4K2K_MAX_30HZ_444 */

/********************CVT_EN_4K2K_MAX_60HZ_420*****************
 (1)Default Value: ENABLE
 (2)Range:0/1 
 (3)Description: ֧��4K2K_60HZ_420,���CVT_EN_4K2K_MAX_30HZ_444��CVT_EN_4K2K_MAX_60HZ_444���⣬��򿪺�CVT_EN_CVT_EDID
 (4)Author&Date:  chenshaogui@2017/02/04
*********************************************************/
#ifndef CVT_EN_4K2K_MAX_60HZ_420
#define CVT_EN_4K2K_MAX_60HZ_420                          ENABLE
#endif /* CVT_EN_4K2K_MAX_60HZ_420 */

/********************CVT_EN_EDID_DD_PLUS*****************
 (1)Default Value: DISABLE
 (2)Range:0/1 
 (3)Description: ֧��DD+ EDID,��򿪺�CVT_EN_CVT_EDID
 (4)Author&Date:  chenshaogui@2017/02/04
*********************************************************/
#ifndef CVT_EN_DD_PLUS
#define CVT_EN_DD_PLUS                                   DISABLE
#endif /* CVT_EN_EDID_DD_PLUS */

/********************CVT_EN_EDID_DD*****************
 (1)Default Value: DISABLE
 (2)Range:0/1 
 (3)Description: ֧��DD EDID,��򿪺�CVT_EN_CVT_EDID
 (4)Author&Date:  chenshaogui@2017/02/04
*********************************************************/
#ifndef CVT_EN_DD
#define CVT_EN_DD                                        DISABLE
#endif /* CVT_EN_EDID_DD */

/********************CVT_EN_3D_EDID*****************
 (1)Default Value: DISABLE
 (2)Range:0/1 
 (3)Description: ֧��3D EDID,��򿪺�CVT_EN_CVT_EDID
 (4)Author&Date:  chenshaogui@2017/02/04
*********************************************************/
#ifndef CVT_EN_3D_EDID
#define CVT_EN_3D_EDID                                   DISABLE
#endif /* CVT_EN_3D_EDID */

/********************CVT_DEF_MODEL_NAME*****************
 (1)Default Value: CVT-MODEL
 (2)Range:
 (3)Description: Defalt model name
 (4)Author&Date:  yubaozhu@2017/02/14
*********************************************************/
#ifndef CVT_DEF_MODEL_NAME
#define CVT_DEF_MODEL_NAME                              "CVT-MODEL"
#endif /* CVT_DEF_MODEL_NAME */

/********************CVT_EN_SHOW_CHIP_NAME*****************
 (1)Default Value: 1
 (2)Range:
 (3)Description: Whether show chip name or not
 (4)Author&Date:  yubaozhu@2017/02/14
*********************************************************/
#ifndef CVT_EN_SHOW_CHIP_NAME
#define CVT_EN_SHOW_CHIP_NAME                           ENABLE
#endif /* CVT_EN_SHOW_CHIP_NAME */


/********************CVT_DEF_PQ_TYPE*****************
 (1)Default Value: CVT_DEFAULT_PQ
 (2)Range:
 (3)Description: 
 (4)Author&Date:  yubaozhu@2017/02/14
*********************************************************/
#ifndef CVT_DEF_PQ_TYPE
#define CVT_DEF_PQ_TYPE                                 CVT_DEFAULT_PQ
#endif /* CVT_EN_SHOW_CHIP_NAME */

/********************CVT_DEF_CHIP_NAME*****************
 (1)Default Value: CVT-MODEL
 (2)Range:
 (3)Description: Defalt model name
 (4)Author&Date:  yubaozhu@2017/02/14
*********************************************************/
#ifndef CVT_DEF_CHIP_NAME
#define CVT_DEF_CHIP_NAME                               "CVT-CHIP"
#endif /* CVT_DEF_MODEL_NAME */

/********************CVT_DEF_SOFTWARE_VERSION*****************
 (1)Default Value: "V0.01"
 (2)Range:
 (3)Description: Default software version
 (4)Author&Date:  yubaozhu@2017/02/14
*********************************************************/
#ifndef CVT_DEF_SOFTWARE_VERSION
#define CVT_DEF_SOFTWARE_VERSION                        "V0.01"
#endif /* CVT_DEF_SOFTWARE_VERSION */

/********************CVT_DEF_MENU_TYPE*****************
 (1)Default Value: 
 (2)Range:
 (3)Description: 
 (4)Author&Date:  
*********************************************************/
#ifndef CVT_DEF_MENU_TYPE
#define CVT_DEF_MENU_TYPE                               AOC
#endif /* CVT_DEF_MENU_TYPE */

/****************CVT_EN_VOLUME_TABLE************
 (1)Default Value: "AOCLOGO"
 (2)Range:
 (3)Description:  REF DUTY 
 (4)Author&Date:  yubaozhu@2017/05/24
*********************************************************/
#ifndef CVT_EN_VOLUME_TABLE
#define CVT_EN_VOLUME_TABLE                             DISABLE
#endif /* CVT_EN_VOLUME_TABLE */

/****************CVT_EN_ACER_5KEY************
 (1)Default Value: "DISABLE"
 (2)Range:
 (3)Description:  Number of keys
 (4)Author&Date:  hexun@2017/06/12
*********************************************************/
#ifndef CVT_EN_ACER_5KEY                                   
#define CVT_EN_ACER_5KEY                                DISABLE                  
#endif

/**************CVT_EN_GAME_MODE_ITEM**********
 (1)Default Value: ENABLE
 (2)Range: 0/1
 (3)Description:  Add game item in the gaming item 
 (4)Author&Date:  hexun@2017/06/12
*********************************************************/
#ifndef CVT_EN_GAME_MODE_ITEM
#define CVT_EN_GAME_MODE_ITEM                           ENABLE
#endif

/**************CVT_EN_VAG_OSD_MENU**********
 (1)Default Value: DISABLE
 (2)Range: 0/1
 (3)Description:  Add menu item when it have the vga input
 (4)Author&Date: huyunhai@2017/06/23-.
*********************************************************/
#ifndef CVT_EN_VAG_OSD_MENU
#define CVT_EN_VAG_OSD_MENU                             DISABLE
#endif

/**************CVT_EN_BOARD_SN_LENGTH**********
 (1)Default Value: 17
 (2)Range: 0/1
 (3)Description:  The length of board SN number
 (4)Author&Date:  bigzhanghao@2017/06/26
*********************************************************/
#ifndef CVT_DEF_BOARD_SN_LENGTH
#define CVT_DEF_BOARD_SN_LENGTH                         (17)
#endif

/**************CVT_DEF_CUSTOMER_SN_LENGTH**********
 (1)Default Value: 22
 (2)Range: 0/1
 (3)Description:  The length of customer SN number
 (4)Author&Date:  bigzhanghao@2017/06/26
*********************************************************/
#ifndef CVT_DEF_CUSTOMER_SN_LENGTH
#define CVT_DEF_CUSTOMER_SN_LENGTH                      (22)
#endif

/***********************CVT_EN_AUDIO_SUPPORT*************
 (1)Default Value: ENABLE
 (2)Range: 0/1
 (3)Description: support audio function
 (4)Author&Date:  xiangjianhe@20170722
*********************************************************/
#ifndef CVT_EN_AUDIO_SUPPORT
#define CVT_EN_AUDIO_SUPPORT                            ENABLE
#endif /* CVT_EN_AUDIO_SUPPORT */

/*********************************************************
 (1)Ĭ��ֵ:100(0~100)
 (2)��Χ˵��: 0/1
 (3)��������: ����Ĭ��ֵ
 (4)����&����:  //(0~100)change xiangjianhe@20170330
*********************************************************/
#ifndef CVT_DEF_BACKLIGHT
#define CVT_DEF_BACKLIGHT                               100
#endif

/******************CVT_EN_BLUE_LIGHT**********************
 (1)Ĭ��ֵ:_ON
 (2)��Χ˵��: _OFF/_ON
 (3)��������: �Ƿ��Blue Light����
 (4)����&����:  //shenjian@20170814
*********************************************************/
#ifndef CVT_EN_BLUE_LIGHT
#define CVT_EN_BLUE_LIGHT                               _ON
#endif

/******************CVT_EN_FACTORY_ADJUST_BLUE_LIGHT******
 (1)Ĭ��ֵ:_ON
 (2)��Χ˵��: _OFF/_ON
 (3)��������: ��������Blue LightЧ��
 (4)����&����:  //shenjian@20170814
*********************************************************/
#ifndef CVT_EN_FACTORY_ADJUST_BLUE_LIGHT
#define CVT_EN_FACTORY_ADJUST_BLUE_LIGHT                _ON
#endif

/***********************CVT_DEF_XML_SW_AAC *************
 (1)Default Value:NO AAC
 (2)Range: NO AAC/
 (3)Description:
 (4)Author&Date:ACC  XML SETTING
*********************************************************/
#ifndef CVT_DEF_XML_SW_AAC
#define CVT_DEF_XML_SW_AAC            	                    "NO AAC"
#endif /* CVT_DEF_XML_SW_AAC */

/***********************CVT_DEF_XML_SW_DOLBY *************
 (1)Default Value:DISABLE
 (2)Range: 
 (3)Description:
 (4)Author&Date:SW_DOLBY  XML SETTING
*********************************************************/
#ifndef CVT_DEF_XML_SW_DOLBY
#define CVT_DEF_XML_SW_DOLBY            	                DISABLE
#endif /* CVT_DEF_XML_SW_DOLBY */

/***********************CVT_DEF_XML_SW_CHIPSET_SUBCODE *************
 (1)Default Value:DISABLE
 (2)Range: 
 (3)Description:
 (4)Author&Date:SW_Chipset_SubCode  XML SETTING
*********************************************************/
#ifndef CVT_DEF_XML_SW_CHIPSET_SUBCODE
#define CVT_DEF_XML_SW_CHIPSET_SUBCODE            	        "A1"
#endif /* CVT_DEF_XML_SW_CHIPSET_SUBCODE */

/***********************CVT_DEF_XML_SW_HDCP *************
 (1)Default Value:DISABLE
 (2)Range: 
 (3)Description:
 (4)Author&Date:SW_HDCP  XML SETTING
*********************************************************/
#ifndef CVT_DEF_XML_SW_HDCP
#define CVT_DEF_XML_SW_HDCP            	                    DISABLE
#endif /* CVT_DEF_XML_SW_HDCP */

#endif
