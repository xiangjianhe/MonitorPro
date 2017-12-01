#ifndef _CustomerCVT_H_
#define _CustomerCVT_H_
#include "Global_Product_Define.h"

//---------------------------------------------------------------------------------
// Compile Project RL6230_Project
//---------------------------------------------------------------------------------
#define CP269141_MP_RT2270C_PA553_1A_ENGLIST_PNL_1920_1080                          6230001 // Compile Project+ Number [6230 + 001]
#define CP269141_MP_RT2270C_PA553_1A_ENGLIST_PNL_CMI_M195FGE_L20_1600_900           6230002 // Compile Project+ Number [6230 + 002]
#define CP269141_MP_RT2270C_PA553_1A_ENGLIST_PNL_AUO_M195RTN01_0_1600_900           6230003 // Compile Project+ Number [6230 + 003]
#define CP285123_MP_RT2270C_PA553_1A_ENGLIST_PNL_AUO_M195RTN01_0_1600_900           6230004 // Compile Project+ Number [6230 + 003]
#define CP291865_MP_RT2270C_PA553_1A_SCHIESE_PNL_CMI_M195FGE_L20_1600_900           6230005 // Compile Project+ Number [6230 + 002]
#define CP291864_MP_RT2270C_PA553_1A_SCHIESE_PNL_AUO_M195RTN01_0_1600_900           6230006 // Compile Project+ Number [6230 + 003]


//---------------------------------------------------------------------------------
// Compile Project RL6336_Project
//---------------------------------------------------------------------------------
#define CP000000_MP_RT2281C_PA553_1A_ENGLIST_PNL_1920_1080                          6336001 // Compile Project+ Number [6336 + 001]

#define CUSTOMER_ID                          CP291865_MP_RT2270C_PA553_1A_SCHIESE_PNL_CMI_M195FGE_L20_1600_900                    


//---------------------------------------------------------------------------------
#if(CUSTOMER_ID == CP269141_MP_RT2270C_PA553_1A_ENGLIST_PNL_1920_1080)
#define CVT_DEF_ModeID2Str_In_BIN            Maco2Str(CP269141_MP_RT2270C_PA553_1A_ENGLIST_PNL_1920_1080)

#define CVT_DEF_CHIP_NAME                    "RTD2270CLW-CG"
#define CVT_DEF_OCS_ID                       "CP269141"
#define CVT_DEF_BOARD_TYPE                   ID_BD_CVT_MP_RT2270C_PA553_1A_A1
#define BOARD_NAME                           "MP.RT2270C.PA553B"
#define CVT_DEF_SW_CHIPSET_SUBCODE           "A1"
#define CVT_DEF_PANEL_TYPE                   _TPV_BOE_HT215F01_100 
#define CVT_EN_VGA_SOURCE                    ENABLE

#define CVT_DEF_KEYPAD_ADC_TYPE              KEYPAD_ADC_CVT_DEFAULT

#define CVT_DEF_OSD_LANG                     _ENGLISH

#define CVT_EN_UART_DEBUG                    DISABLE

#define _BACKLIGHT_MAX                       255
#define _BACKLIGHT_MIN                       50
#define _BACKLIGHT_CENTER                    230

#define CVT_DEF_BACKLIGHT                    80
#define CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER   DISABLE
#define CVT_EN_ON_LINE_WRITE_EDID            ENABLE

#elif(CUSTOMER_ID == CP269141_MP_RT2270C_PA553_1A_ENGLIST_PNL_CMI_M195FGE_L20_1600_900)
#define CVT_DEF_ModeID2Str_In_BIN            Maco2Str(CP269141_MP_RT2270C_PA553_1A_ENGLIST_PNL_CMI_M195FGE_L20_1600_900)

#define CVT_DEF_CHIP_NAME                    "RTD2270CLW-CG"
#define CVT_DEF_OCS_ID                       "CP269141"
#define CVT_DEF_BOARD_TYPE                   ID_BD_CVT_MP_RT2270C_PA553_1A_A1
#define BOARD_NAME                           "MP.RT2270C.PA553B"
#define CVT_DEF_SW_CHIPSET_SUBCODE           "A1"
#define CVT_DEF_PANEL_TYPE                   _FOX_CMI_M195FGE_L20 
#define CVT_EN_VGA_SOURCE                    ENABLE

#define CVT_DEF_KEYPAD_ADC_TYPE              KEYPAD_ADC_CVT_DEFAULT

#define CVT_DEF_OSD_LANG                     _ENGLISH

#define CVT_EN_UART_DEBUG                    DISABLE

#define _BACKLIGHT_MAX                       250
#define _BACKLIGHT_MIN                       50
#define _BACKLIGHT_CENTER                    230

#define CVT_DEF_BACKLIGHT                    80
#define CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER   DISABLE
#define CVT_EN_ON_LINE_WRITE_EDID            ENABLE

#elif(CUSTOMER_ID == CP269141_MP_RT2270C_PA553_1A_ENGLIST_PNL_AUO_M195RTN01_0_1600_900)
#define CVT_DEF_ModeID2Str_In_BIN            Maco2Str(CP269141_MP_RT2270C_PA553_1A_ENGLIST_PNL_AUO_M195RTN01_0_1600_900)

#define CVT_DEF_CHIP_NAME                    "RTD2270CLW-CG"
#define CVT_DEF_OCS_ID                       "CP269141"
#define CVT_DEF_BOARD_TYPE                   ID_BD_CVT_MP_RT2270C_PA553_1A_A1
#define BOARD_NAME                           "MP.RT2270C.PA553B"
#define CVT_DEF_SW_CHIPSET_SUBCODE           "A1"
#define CVT_DEF_PANEL_TYPE                   _TPV_AUO_M195RTN01_0 
#define CVT_EN_VGA_SOURCE                    ENABLE

#define CVT_DEF_KEYPAD_ADC_TYPE              KEYPAD_ADC_CVT_DEFAULT

#define CVT_DEF_OSD_LANG                     _ENGLISH

#define CVT_EN_UART_DEBUG                    DISABLE

#define _BACKLIGHT_MAX                       245//255
#define _BACKLIGHT_MIN                       50
#define _BACKLIGHT_CENTER                    225

#define CVT_DEF_BACKLIGHT                    80
#define CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER   DISABLE
#define CVT_EN_ON_LINE_WRITE_EDID            ENABLE

#elif(CUSTOMER_ID == CP285123_MP_RT2270C_PA553_1A_ENGLIST_PNL_AUO_M195RTN01_0_1600_900)
#define CVT_DEF_ModeID2Str_In_BIN            Maco2Str(CP285123_MP_RT2270C_PA553_1A_ENGLIST_PNL_AUO_M195RTN01_0_1600_900)

#define CVT_DEF_CHIP_NAME                    "RTD2270CLW-CG"
#define CVT_DEF_OCS_ID                       "CP285123"
#define CVT_DEF_BOARD_TYPE                   ID_BD_CVT_MP_RT2270C_PA553_1A_A1
#define BOARD_NAME                           "MP.RT2270C.PA553B"
#define CVT_DEF_SW_CHIPSET_SUBCODE           "A1"
#define CVT_DEF_PANEL_TYPE                   _TPV_AUO_M195RTN01_0 
#define CVT_EN_VGA_SOURCE                    ENABLE

#define CVT_DEF_KEYPAD_ADC_TYPE              KEYPAD_ADC_CVT_DEFAULT

#define CVT_DEF_OSD_LANG                     _ENGLISH

#define CVT_EN_UART_DEBUG                    DISABLE

#define _BACKLIGHT_MAX                       245//255
#define _BACKLIGHT_MIN                       50
#define _BACKLIGHT_CENTER                    225

#define CVT_DEF_BACKLIGHT                    80
#define CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER   DISABLE
#define CVT_EN_ON_LINE_WRITE_EDID            ENABLE
#elif(CUSTOMER_ID == CP291865_MP_RT2270C_PA553_1A_SCHIESE_PNL_CMI_M195FGE_L20_1600_900)
#define CVT_DEF_ModeID2Str_In_BIN            Maco2Str(CP291865_MP_RT2270C_PA553_1A_SCHIESE_PNL_CMI_M195FGE_L20_1600_900)

#define CVT_DEF_CHIP_NAME                    "RTD2270CLW-CG"
#define CVT_DEF_OCS_ID                       "CP291865"
#define CVT_DEF_BOARD_TYPE                   ID_BD_CVT_MP_RT2270C_PA553_1A_A1
#define BOARD_NAME                           "MP.RT2270C.PA553B"
#define CVT_DEF_SW_CHIPSET_SUBCODE           "A1"
#define CVT_DEF_PANEL_TYPE                   _FOX_CMI_M195FGE_L20 
#define CVT_EN_VGA_SOURCE                    ENABLE

#define CVT_DEF_KEYPAD_ADC_TYPE              KEYPAD_ADC_CVT_DEFAULT

#define CVT_DEF_OSD_LANG                     _CHINESE_S

#define CVT_EN_UART_DEBUG                    DISABLE

#define _BACKLIGHT_MAX                       250
#define _BACKLIGHT_MIN                       50
#define _BACKLIGHT_CENTER                    230

#define CVT_DEF_BACKLIGHT                    80
#define CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER   DISABLE
#define CVT_EN_ON_LINE_WRITE_EDID            ENABLE
#elif(CUSTOMER_ID == CP291864_MP_RT2270C_PA553_1A_SCHIESE_PNL_AUO_M195RTN01_0_1600_900)
#define CVT_DEF_ModeID2Str_In_BIN            Maco2Str(CP291864_MP_RT2270C_PA553_1A_SCHIESE_PNL_AUO_M195RTN01_0_1600_900)

#define CVT_DEF_CHIP_NAME                    "RTD2270CLW-CG"
#define CVT_DEF_OCS_ID                       "CP291864"
#define CVT_DEF_BOARD_TYPE                   ID_BD_CVT_MP_RT2270C_PA553_1A_A1
#define BOARD_NAME                           "MP.RT2270C.PA553B"
#define CVT_DEF_SW_CHIPSET_SUBCODE           "A1"
#define CVT_DEF_PANEL_TYPE                   _TPV_AUO_M195RTN01_0 
#define CVT_EN_VGA_SOURCE                    ENABLE

#define CVT_DEF_KEYPAD_ADC_TYPE              KEYPAD_ADC_CVT_DEFAULT

#define CVT_DEF_OSD_LANG                     _CHINESE_S

#define CVT_EN_UART_DEBUG                    DISABLE

#define _BACKLIGHT_MAX                       245//255
#define _BACKLIGHT_MIN                       50
#define _BACKLIGHT_CENTER                    225

#define CVT_DEF_BACKLIGHT                    80
#define CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER   DISABLE
#define CVT_EN_ON_LINE_WRITE_EDID            ENABLE

#elif(CUSTOMER_ID == CP000000_MP_RT2281C_PA553_1A_ENGLIST_PNL_1920_1080)
#define CVT_DEF_ModeID2Str_In_BIN            Maco2Str(CP000000_MP_RT2281C_PA553_1A_ENGLIST_PNL_1920_1080)

#define CVT_DEF_CHIP_NAME                    "RTD2281CL"
#define CVT_DEF_OCS_ID                       "CP000000"
#define CVT_DEF_BOARD_TYPE                   ID_BD_CVT_MP_RT2281C_PA553_1A_A1
#define BOARD_NAME                           "MP_RT2281C_PA553"
#define CVT_DEF_SW_CHIPSET_SUBCODE           "A1"
#define CVT_DEF_PANEL_TYPE                   _TPV_BOE_HT215F01_100 
#define CVT_EN_VGA_SOURCE                    ENABLE

#define CVT_DEF_KEYPAD_ADC_TYPE              KEYPAD_ADC_CVT_DEFAULT

#define CVT_DEF_OSD_LANG                     _ENGLISH

#define CVT_EN_UART_DEBUG                    DISABLE

#define _BACKLIGHT_MAX                       255
#define _BACKLIGHT_MIN                       50
#define _BACKLIGHT_CENTER                    230

#define CVT_DEF_BACKLIGHT                    80
#define CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER   DISABLE

//---------------------------------------------------------------------------------
#else
#error "No Default CUS ID"
#endif
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
//==============================common define start================================
//---------------------------------------------------------------------------------
// language
#define CVT_EN_LANG_ENGLISH                 ENABLE
#define CVT_EN_LANG_RUSSIA                  ENABLE

#define CVT_EN_LANG_GERMAN                  ENABLE
#define CVT_EN_LANG_FRANCE                  ENABLE
#define CVT_EN_LANG_SPANISH                 ENABLE
#define CVT_EN_LANG_ITALIAN                 ENABLE
#define CVT_EN_LANG_DUTCH                   DISABLE
#define CVT_EN_LANG_SUOMALAINEN             DISABLE
#define CVT_EN_LANG_TURKISH                 DISABLE
#define CVT_EN_LANG_POLISH                  DISABLE
#define CVT_EN_LANG_PORTUGUES               DISABLE
#define CVT_EN_LANG_TCHINA                  DISABLE

#define CVT_EN_LANG_SCHINA                  ENABLE
#define CVT_EN_LANG_JAPANESE                ENABLE
#define CVT_EN_LANG_BRAZIPORTUGUESE         DISABLE
#define CVT_EN_LANG_KOREA                   DISABLE

// keypad
#if (CVT_DEF_KEYPAD_ADC_TYPE == KEYPAD_ADC_CVT_DEFAULT)
#define KEY_AD_K0                           KEY_EXIT//_EXIT_KEY_MASK//AUTO
#define KEY_AD_K1                           KEY_LEFT//_LEFT_KEY_MASK//LEFT 
#define KEY_AD_K2                           KEY_NONE
#define KEY_AD_K3                           KEY_POWER//_POWER_KEY_MASK//RIGHT 
#define KEY_AD_K4                           KEY_MENU//_MENU_KEY_MASK//MENU 
#define KEY_AD_K5                           KEY_RIGHT//_RIGHT_KEY_MASK//RIGHT
#define KEY_AD_K6                           KEY_NONE
#define KEY_AD_K7                           KEY_NONE
#else
#error "Please define KEYPAD"
#endif

//---------------------------------------------------------------------------------
#endif
