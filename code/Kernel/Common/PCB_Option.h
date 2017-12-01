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
// ID Code      : PCB_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// Definitions by PCB
//****************************************************************************
//--------------------------------------------------
// Input Port Define
//--------------------------------------------------
#ifndef _A0_INPUT_PORT_TYPE
#define _A0_INPUT_PORT_TYPE                     _A0_NO_PORT
#endif

#ifndef _EMBEDDED_DDCRAM_A0_SIZE
#define _EMBEDDED_DDCRAM_A0_SIZE                _EDID_SIZE_NONE
#endif

#ifndef _EMBEDDED_DDCRAM_A0_LOCATION
#define _EMBEDDED_DDCRAM_A0_LOCATION            _EDID_TABLE_LOCATION_CODE
#endif

#ifndef _D0_INPUT_PORT_TYPE
#define _D0_INPUT_PORT_TYPE                     _D0_NO_PORT
#endif

#ifndef _D0_DDC_CHANNEL_SEL
#define _D0_DDC_CHANNEL_SEL                     _NO_DDC
#endif

#ifndef _D0_CBUS_CHANNEL_SEL
#define _D0_CBUS_CHANNEL_SEL                    _NO_CBUS
#endif

#ifndef _EMBEDDED_DDCRAM_D0_SIZE
#define _EMBEDDED_DDCRAM_D0_SIZE                _EDID_SIZE_NONE
#endif

#ifndef _EMBEDDED_DDCRAM_D0_LOCATION
#define _EMBEDDED_DDCRAM_D0_LOCATION            _EDID_TABLE_LOCATION_CODE
#endif

#ifndef _EMBEDDED_DDCRAM_D0_MHL_SIZE
#define _EMBEDDED_DDCRAM_D0_MHL_SIZE            _EDID_SIZE_NONE
#endif

#ifndef _EMBEDDED_DDCRAM_D0_MHL_LOCATION
#define _EMBEDDED_DDCRAM_D0_MHL_LOCATION        _EDID_TABLE_LOCATION_CODE
#endif

#ifndef _D1_INPUT_PORT_TYPE
#define _D1_INPUT_PORT_TYPE                     _D1_NO_PORT
#endif

#ifndef _D1_DDC_CHANNEL_SEL
#define _D1_DDC_CHANNEL_SEL                     _NO_DDC
#endif

#ifndef _D1_CBUS_CHANNEL_SEL
#define _D1_CBUS_CHANNEL_SEL                    _NO_CBUS
#endif

#ifndef _EMBEDDED_DDCRAM_D1_SIZE
#define _EMBEDDED_DDCRAM_D1_SIZE                _EDID_SIZE_NONE
#endif

#ifndef _EMBEDDED_DDCRAM_D1_LOCATION
#define _EMBEDDED_DDCRAM_D1_LOCATION            _EDID_TABLE_LOCATION_CODE
#endif

#ifndef _EMBEDDED_DDCRAM_D1_MHL_SIZE
#define _EMBEDDED_DDCRAM_D1_MHL_SIZE            _EDID_SIZE_NONE
#endif

#ifndef _EMBEDDED_DDCRAM_D1_MHL_LOCATION
#define _EMBEDDED_DDCRAM_D1_MHL_LOCATION        _EDID_TABLE_LOCATION_CODE
#endif

#ifndef _D2_INPUT_PORT_TYPE
#define _D2_INPUT_PORT_TYPE                     _D2_NO_PORT
#endif

#ifndef _D2_INPUT_PORT_SWITCH_FROM
#define _D2_INPUT_PORT_SWITCH_FROM              _SWITCH_NONE
#endif

#ifndef _D3_INPUT_PORT_TYPE
#define _D3_INPUT_PORT_TYPE                     _D3_NO_PORT
#endif

#ifndef _D3_INPUT_PORT_SWITCH_FROM
#define _D3_INPUT_PORT_SWITCH_FROM              _SWITCH_NONE
#endif

//--------------------------------------------------
// Input Port Search Group Define (Must Start From Valid Port)
//--------------------------------------------------
#ifndef _D0_INPUT_PORT_GROUP
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#endif

#ifndef _D1_INPUT_PORT_GROUP
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#endif

#ifndef _D2_INPUT_PORT_GROUP
#define _D2_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#endif

#ifndef _D3_INPUT_PORT_GROUP
#define _D3_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#endif

#ifndef _A0_INPUT_PORT_GROUP
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#endif

//--------------------------------------------------
// Input Port Search Priority Define
//--------------------------------------------------
#ifndef _INPUT_PORT_SEARCH_PRI_0
#define _INPUT_PORT_SEARCH_PRI_0                _A0_INPUT_PORT
#endif

#ifndef _INPUT_PORT_SEARCH_PRI_1
#define _INPUT_PORT_SEARCH_PRI_1                _A0_INPUT_PORT
#endif

#ifndef _INPUT_PORT_SEARCH_PRI_2
#define _INPUT_PORT_SEARCH_PRI_2                _A0_INPUT_PORT
#endif

#ifndef _INPUT_PORT_SEARCH_PRI_3
#define _INPUT_PORT_SEARCH_PRI_3                _A0_INPUT_PORT
#endif

#ifndef _INPUT_PORT_SEARCH_PRI_4
#define _INPUT_PORT_SEARCH_PRI_4                _A0_INPUT_PORT
#endif

//--------------------------------------------------
// Analog Signal Swap Options
//--------------------------------------------------
#ifndef _A0_INPUT_SWAP_RG
#define _A0_INPUT_SWAP_RG                       _OFF
#endif

#ifndef _A0_INPUT_SWAP_RB
#define _A0_INPUT_SWAP_RB                       _OFF
#endif

#ifndef _A0_INPUT_SWAP_GB
#define _A0_INPUT_SWAP_GB                       _OFF
#endif

//--------------------------------------------------
// TMDS Signal Swap Select
//--------------------------------------------------
#ifndef _D0_TMDS_BR_SWAP
#define _D0_TMDS_BR_SWAP                        _OFF
#endif

#ifndef _D0_TMDS_PN_SWAP
#define _D0_TMDS_PN_SWAP                        _OFF
#endif

#ifndef _D1_TMDS_BR_SWAP
#define _D1_TMDS_BR_SWAP                        _OFF
#endif

#ifndef _D1_TMDS_PN_SWAP
#define _D1_TMDS_PN_SWAP                        _OFF
#endif

//--------------------------------------------------
// DP Connector Swap Select
//--------------------------------------------------
#ifndef _PCB_DP_CONNECTOR_SWAP
#define _PCB_DP_CONNECTOR_SWAP                  _OFF
#endif

//--------------------------------------------------
// LVDS PCB Setting
//--------------------------------------------------
#if((_SCALER_TYPE != _RL6230_SERIES) && (_SCALER_TYPE != _RL6316_SERIES) && (_SCALER_TYPE != _RL6336_SERIES) && (_SCALER_TYPE != _RL6373_SERIES))
#ifndef _LVDS_EO_CLK_MERGE
#define _LVDS_EO_CLK_MERGE                      _DISABLE
#endif
#endif

//--------------------------------------------------
// LVDS EMI Setting
//--------------------------------------------------
#if(_LVDS_VCM_CONTROL == _LVDS_VCM_USER)
#if(_SCALER_TYPE != _RL6336_SERIES)
#warning "This Scaler Type Can Not Support LVDS VCM User Mode!!!"
#endif
#endif

#ifndef _LVDS_VCM_USER_LEVEL
#define _LVDS_VCM_USER_LEVEL                    0x06
#endif

#if(_LVDS_VCM_USER_LEVEL > 0xF)
#warning "LVDS VCM Selection Exceed The Maximum Value"
#endif

#ifndef _LVDS_SR_CONTROL
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#endif

#ifndef _LVDS_SHAPE_ADJUSTMENT
#define _LVDS_SHAPE_ADJUSTMENT                  _LVDS_SHAPE_FAST_TO_SLOW
#endif

#ifndef _LVDS_CAP_CONTROL
#define _LVDS_CAP_CONTROL                       _DISABLE
#endif

#ifndef _LVDS_TERMINATION_CONTROL
#define _LVDS_TERMINATION_CONTROL               _DISABLE
#endif

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#ifndef _PWM4_EN
#define _PWM4_EN                                _OFF
#endif

#ifndef _PWM5_EN
#define _PWM5_EN                                _OFF
#endif

#ifndef _PWM4_PSAV_EN
#define _PWM4_PSAV_EN                           _OFF
#endif

#ifndef _PWM5_PSAV_EN
#define _PWM5_PSAV_EN                           _OFF
#endif

#ifndef _PWM4_RST_BY_DVS
#define _PWM4_RST_BY_DVS                        _OFF
#endif

#ifndef _PWM5_RST_BY_DVS
#define _PWM5_RST_BY_DVS                        _OFF
#endif

#if((_PWM0_EN == _ON) || (_PWM0_PSAV_EN == _ON) || (_PWM1_EN == _ON) || (_PWM1_PSAV_EN == _ON) || \
    (_PWM2_EN == _ON) || (_PWM2_PSAV_EN == _ON) || (_PWM3_EN == _ON) || (_PWM3_PSAV_EN == _ON) || \
    (_PWM4_EN == _ON) || (_PWM4_PSAV_EN == _ON) || (_PWM5_EN == _ON) || (_PWM5_PSAV_EN == _ON))
#define _PWM_FUNCTION_SUPPORT                   _ON
#else
#define _PWM_FUNCTION_SUPPORT                   _OFF
#endif

//-----------------------------------------------
// Macro of System Power Process
//-----------------------------------------------
#ifndef PCB_GPIO_SETTING_POWER_AC_ON
#define PCB_GPIO_SETTING_POWER_AC_ON()          {\
                                                }
#endif

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#ifndef PCB_EEPROM_WRITE_PROTECT_DETECT
#define PCB_EEPROM_WRITE_PROTECT_DETECT()       {\
                                                }
#endif

#ifndef PCB_EEPROM_WRITE_PROTECT
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                }
#endif

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#ifndef PCB_A0_EDID_EEPROM_WRITE_PROTECT
#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                }
#endif

#ifndef PCB_D0_EDID_EEPROM_WRITE_PROTECT
#define PCB_D0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                }
#endif

#ifndef PCB_D1_EDID_EEPROM_WRITE_PROTECT
#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                }
#endif

//-----------------------------------------------
// Macro of Input Connect Detect
//-----------------------------------------------
#ifndef PCB_A0_PIN
#define PCB_A0_PIN()                            {\
                                                }
#endif

#ifndef PCB_D0_PIN
#define PCB_D0_PIN()                            {\
                                                }
#endif

#ifndef PCB_D1_PIN
#define PCB_D1_PIN()                            {\
                                                }
#endif

#ifndef PCB_D2_PIN
#define PCB_D2_PIN()                            {\
                                                }
#endif

#ifndef PCB_D3_PIN
#define PCB_D3_PIN()                            {\
                                                }
#endif

//-----------------------------------------------
// Macro of MHL/HDMI Detection
//-----------------------------------------------
#ifndef SET_D0_TMDS_SWITCH
#define SET_D0_TMDS_SWITCH(x)                   {\
                                                }
#endif

#ifndef SET_D1_TMDS_SWITCH
#define SET_D1_TMDS_SWITCH(x)                   {\
                                                }
#endif

#ifndef SET_D0_MHL_VBUS_SWITCH
#define SET_D0_MHL_VBUS_SWITCH(x)               {\
                                                }
#endif

#ifndef SET_D1_MHL_VBUS_SWITCH
#define SET_D1_MHL_VBUS_SWITCH(x)               {\
                                                }
#endif

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#ifndef PCB_D0_HOTPLUG
#define PCB_D0_HOTPLUG(x)                       {\
                                                }
#endif

#ifndef PCB_D1_HOTPLUG
#define PCB_D1_HOTPLUG(x)                       {\
                                                }
#endif

#ifndef PCB_D2_HOTPLUG
#define PCB_D2_HOTPLUG(x)                       {\
                                                }
#endif

#ifndef PCB_D3_HOTPLUG
#define PCB_D3_HOTPLUG(x)                       {\
                                                }
#endif

//-----------------------------------------------
// Macro of Input Port D2 Digital Switch
//-----------------------------------------------
#ifndef PCB_DIGITAL_D2_SWITCH_POWER
#define PCB_DIGITAL_D2_SWITCH_POWER(x)          {\
                                                }
#endif

#ifndef PCB_DIGITAL_D2_SWITCH_TO_HIZ
#define PCB_DIGITAL_D2_SWITCH_TO_HIZ()          {\
                                                }
#endif

//-----------------------------------------------
// Macro of Input Port D3 Digital Switch
//-----------------------------------------------
#ifndef PCB_DIGITAL_D3_SWITCH_POWER
#define PCB_DIGITAL_D3_SWITCH_POWER(x)          {\
                                                }
#endif

#ifndef PCB_DIGITAL_D3_SWITCH_TO_HIZ
#define PCB_DIGITAL_D3_SWITCH_TO_HIZ()          {\
                                                }
#endif

//-----------------------------------------------
// Macro of Digital Port Switch
//-----------------------------------------------
#ifndef PCB_DIGITAL_SWITCH_TO_D0
#define PCB_DIGITAL_SWITCH_TO_D0()              {\
                                                }
#endif

#ifndef PCB_DIGITAL_SWITCH_TO_D0_IDLE
#define PCB_DIGITAL_SWITCH_TO_D0_IDLE()         {\
                                                }
#endif

#ifndef PCB_DIGITAL_SWITCH_TO_D1
#define PCB_DIGITAL_SWITCH_TO_D1()              {\
                                                }
#endif

#ifndef PCB_DIGITAL_SWITCH_TO_D1_IDLE
#define PCB_DIGITAL_SWITCH_TO_D1_IDLE()         {\
                                                }
#endif

#ifndef PCB_DIGITAL_SWITCH_TO_D2
#define PCB_DIGITAL_SWITCH_TO_D2()              {\
                                                }
#endif

#ifndef PCB_DIGITAL_SWITCH_TO_D3
#define PCB_DIGITAL_SWITCH_TO_D3()              {\
                                                }
#endif

//--------------------------------------------------
// Audio option setting
//--------------------------------------------------
#ifndef _AUDIO_VOLUME_PWM
#define _AUDIO_VOLUME_PWM                        _NO_PWM
#endif

#ifndef _AUDIO_VOLUME_PWM_INVERSE
#define _AUDIO_VOLUME_PWM_INVERSE               _OFF
#endif

#ifndef _SPEAKER_OUTPUT_LR_SWAP
#define _SPEAKER_OUTPUT_LR_SWAP                                 _OFF
#endif

#ifndef _HEADPHONE_OUTPUT_LR_SWAP
#define _HEADPHONE_OUTPUT_LR_SWAP                               _OFF
#endif

//--------------------------------------------------
// PCB power detect
//--------------------------------------------------
#ifndef PCB_POWER_5V_DETECT
#define PCB_POWER_5V_DETECT()                   (_TRUE)
#endif

//--------------------------------------------------
// PCB EDID WP STATUS
//--------------------------------------------------
#define EDID_WP_STATUS()                        (bEDID_WRITE_PROTECT & _BIT0)

//--------------------------------------------------
// Package option setting
//--------------------------------------------------
#if(_SCALER_TYPE == _RL6096_SERIES)
#include "RL6096_Series_Pin_Mapping.h"
#endif

#if(_SCALER_TYPE == _RL6229_SERIES)
#include "RL6229_Series_Pin_Mapping.h"
#endif

#if(_SCALER_TYPE == _RL6297_SERIES)
#include "RL6297_Series_Pin_Mapping.h"
#endif

#if(_SCALER_TYPE == _RL6316_SERIES)
#include "RL6316_Series_Pin_Mapping.h"
#endif

#if(_SCALER_TYPE == _RL6336_SERIES)
#include "RL6336_Series_Pin_Mapping.h"
#endif

#if(_SCALER_TYPE == _RL6373_SERIES)
#include "RL6373_Series_Pin_Mapping.h"
#endif

//--------------------------------------------------
// ELED option setting
//--------------------------------------------------
#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)

#if((_SCALER_TYPE == _RL6316_SERIES) | (_SCALER_TYPE == _RL6373_SERIES))
#define _ELED_PCB_CURRENT_CHANNEL               ((_ELED_STRING0) + (_ELED_STRING1) + (_ELED_STRING2) + (_ELED_STRING3))
#elif(_SCALER_TYPE == _RL6269_SERIES)
#define _ELED_PCB_CURRENT_CHANNEL               (((_ELED_STRING0) + (_ELED_STRING1) + (_ELED_STRING2) + (_ELED_STRING3)) * 2)
#endif

#endif

#ifndef _ELED_VFB_INTERNAL_RESISTOR
#define _ELED_VFB_INTERNAL_RESISTOR             _ENABLE
#endif

#ifndef _ELED_STRING4
#define _ELED_STRING4                           _OFF
#endif

#ifndef _ELED_STRING5
#define _ELED_STRING5                           _OFF
#endif

#ifndef _ELED_STRING6
#define _ELED_STRING6                           _OFF
#endif

#ifndef _ELED_STRING7
#define _ELED_STRING7                           _OFF
#endif
//--------------------------------------------------
// Enum of Pins support user to adjust configuration
//--------------------------------------------------
#if(_SCALER_TYPE == _RL6001_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_PIN_31,
    _CONFIG_PIN_32,
    _CONFIG_PIN_33,
    _CONFIG_PIN_34,
    _CONFIG_PIN_35,
    _CONFIG_PIN_36,
    _CONFIG_PIN_37,
    _CONFIG_PIN_39,
    _CONFIG_PIN_40,
    _CONFIG_PIN_54,
    _CONFIG_PIN_55,
    _CONFIG_PIN_63,
    _CONFIG_PIN_72,
    _CONFIG_PIN_96,
    _CONFIG_PIN_97,
    _CONFIG_PIN_98,
    _CONFIG_PIN_99,
    _CONFIG_PIN_100,
    _CONFIG_PIN_101,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6096_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_128PIN_PIN_31,
    _CONFIG_128PIN_PIN_32,
    _CONFIG_128PIN_PIN_33,
    _CONFIG_128PIN_PIN_34,
    _CONFIG_128PIN_PIN_35,
    _CONFIG_128PIN_PIN_36,
    _CONFIG_128PIN_PIN_37,
    _CONFIG_128PIN_PIN_39,
    _CONFIG_128PIN_PIN_40,
    _CONFIG_128PIN_PIN_41,
    _CONFIG_128PIN_PIN_42,
    _CONFIG_128PIN_PIN_43,
    _CONFIG_128PIN_PIN_44,
    _CONFIG_128PIN_PIN_45,
    _CONFIG_128PIN_PIN_46,
    _CONFIG_128PIN_PIN_47,
    _CONFIG_128PIN_PIN_48,
    _CONFIG_128PIN_PIN_54,
    _CONFIG_128PIN_PIN_55,
    _CONFIG_128PIN_PIN_56,
    _CONFIG_128PIN_PIN_57,
    _CONFIG_128PIN_PIN_63,
    _CONFIG_128PIN_PIN_64,
    _CONFIG_128PIN_PIN_65,
    _CONFIG_128PIN_PIN_66,
    _CONFIG_128PIN_PIN_67,
    _CONFIG_128PIN_PIN_68,
    _CONFIG_128PIN_PIN_69,
    _CONFIG_128PIN_PIN_70,
    _CONFIG_128PIN_PIN_71,
    _CONFIG_128PIN_PIN_72,
    _CONFIG_128PIN_PIN_96,
    _CONFIG_128PIN_PIN_97,
    _CONFIG_128PIN_PIN_98,
    _CONFIG_128PIN_PIN_99,
    _CONFIG_128PIN_PIN_100,
    _CONFIG_128PIN_PIN_101,
    _CONFIG_128PIN_PIN_102,
    _CONFIG_128PIN_PIN_103,
    _CONFIG_128PIN_PIN_104,
    _CONFIG_128PIN_PIN_105,
    _CONFIG_128PIN_PIN_108,
    _CONFIG_128PIN_PIN_109,
    _CONFIG_128PIN_PIN_110,
    _CONFIG_128PIN_PIN_111,
    _CONFIG_128PIN_PIN_112,
    _CONFIG_128PIN_PIN_113,
    _CONFIG_128PIN_PIN_114,
    _CONFIG_128PIN_PIN_126,
    _CONFIG_80PIN_PIN_22,
    _CONFIG_80PIN_PIN_23,
    _CONFIG_80PIN_PIN_24,
    _CONFIG_80PIN_PIN_25,
    _CONFIG_80PIN_PIN_26,
    _CONFIG_80PIN_PIN_27,
    _CONFIG_80PIN_PIN_31,
    _CONFIG_80PIN_PIN_32,
    _CONFIG_80PIN_PIN_33,
    _CONFIG_80PIN_PIN_39,
    _CONFIG_80PIN_PIN_40,
    _CONFIG_80PIN_PIN_62,
    _CONFIG_80PIN_PIN_63,
    _CONFIG_80PIN_PIN_64,
    _CONFIG_80PIN_PIN_65,
    _CONFIG_80PIN_PIN_66,
    _CONFIG_80PIN_PIN_67,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6213_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_PIN_33,
    _CONFIG_PIN_34,
    _CONFIG_PIN_35,
    _CONFIG_PIN_36,
    _CONFIG_PIN_37,
    _CONFIG_PIN_39,
    _CONFIG_PIN_40,
    _CONFIG_PIN_56,
    _CONFIG_PIN_57,
    _CONFIG_PIN_41,
    _CONFIG_PIN_48,
    _CONFIG_PIN_54,
    _CONFIG_PIN_55,
    _CONFIG_PIN_61,
    _CONFIG_PIN_63,
    _CONFIG_PIN_64,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6192_SERIES)
typedef enum
{
    _CONFIG_PIN_START= 0,
    _CONFIG_PIN_31,
    _CONFIG_PIN_32,
    _CONFIG_PIN_33,
    _CONFIG_PIN_34,
    _CONFIG_PIN_35,
    _CONFIG_PIN_36,
    _CONFIG_PIN_37,
    _CONFIG_PIN_39,
    _CONFIG_PIN_40,
    _CONFIG_PIN_54,
    _CONFIG_PIN_55,
    _CONFIG_PIN_56,
    _CONFIG_PIN_57,
    _CONFIG_PIN_63,
    _CONFIG_PIN_72,
    _CONFIG_PIN_96,
    _CONFIG_PIN_97,
    _CONFIG_PIN_98,
    _CONFIG_PIN_99,
    _CONFIG_PIN_100,
    _CONFIG_PIN_101,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6230_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_PIN_4,
    _CONFIG_PIN_20,
    _CONFIG_PIN_25,
    _CONFIG_PIN_26,
    _CONFIG_PIN_27,
    _CONFIG_PIN_28,
    _CONFIG_PIN_29,
    _CONFIG_PIN_55,
    _CONFIG_PIN_56,
    _CONFIG_PIN_61,
    _CONFIG_PIN_62,
    _CONFIG_PIN_63,
    _CONFIG_PIN_64,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6229_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_128PIN_PIN_31,
    _CONFIG_128PIN_PIN_32,
    _CONFIG_128PIN_PIN_33,
    _CONFIG_128PIN_PIN_34,
    _CONFIG_128PIN_PIN_35,
    _CONFIG_128PIN_PIN_36,
    _CONFIG_128PIN_PIN_39,
    _CONFIG_128PIN_PIN_40,
    _CONFIG_128PIN_PIN_54,
    _CONFIG_128PIN_PIN_55,
    _CONFIG_128PIN_PIN_63,
    _CONFIG_128PIN_PIN_72,
    _CONFIG_128PIN_PIN_101,
    _CONFIG_128PIN_PIN_108,
    _CONFIG_128PIN_PIN_109,
    _CONFIG_128PIN_PIN_114,
    _CONFIG_128PIN_PIN_126,
    _CONFIG_76PIN_PIN21,
    _CONFIG_76PIN_PIN22,
    _CONFIG_76PIN_PIN23,
    _CONFIG_76PIN_PIN30,
    _CONFIG_76PIN_PIN37,
    _CONFIG_76PIN_PIN38,
    _CONFIG_76PIN_PIN59,
    _CONFIG_76PIN_PIN60,
    _CONFIG_76PIN_PIN61,
    _CONFIG_76PIN_PIN63,
    _CONFIG_76PIN_PIN68,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6297_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_128PIN_PIN_31,
    _CONFIG_128PIN_PIN_32,
    _CONFIG_128PIN_PIN_33,
    _CONFIG_128PIN_PIN_34,
    _CONFIG_128PIN_PIN_35,
    _CONFIG_128PIN_PIN_36,
    _CONFIG_128PIN_PIN_37,
    _CONFIG_128PIN_PIN_39,
    _CONFIG_128PIN_PIN_40,
    _CONFIG_128PIN_PIN_54,
    _CONFIG_128PIN_PIN_55,
    _CONFIG_128PIN_PIN_63,
    _CONFIG_128PIN_PIN_72,
    _CONFIG_128PIN_PIN_96,
    _CONFIG_128PIN_PIN_97,
    _CONFIG_128PIN_PIN_98,
    _CONFIG_128PIN_PIN_99,
    _CONFIG_128PIN_PIN_100,
    _CONFIG_128PIN_PIN_101,
    _CONFIG_76PIN_PIN21,
    _CONFIG_76PIN_PIN22,
    _CONFIG_76PIN_PIN23,
    _CONFIG_76PIN_PIN24,
    _CONFIG_76PIN_PIN25,
    _CONFIG_76PIN_PIN30,
    _CONFIG_76PIN_PIN37,
    _CONFIG_76PIN_PIN38,
    _CONFIG_76PIN_PIN59,
    _CONFIG_76PIN_PIN60,
    _CONFIG_76PIN_PIN61,
    _CONFIG_76PIN_PIN63,
    _CONFIG_76PIN_PIN68,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6269_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_PIN_1,

    _CONFIG_PIN_26,
    _CONFIG_PIN_27,
    _CONFIG_PIN_51,
    _CONFIG_PIN_54,
    _CONFIG_PIN_64,
    _CONFIG_PIN_87,
    _CONFIG_PIN_89,
    _CONFIG_PIN_90,
    _CONFIG_PIN_91,
    _CONFIG_PIN_93,
    _CONFIG_PIN_94,
    _CONFIG_PIN_95,
    _CONFIG_PIN_97,
    _CONFIG_PIN_99,
    _CONFIG_PIN_101,
    _CONFIG_PIN_102,
    _CONFIG_PIN_105,
    _CONFIG_PIN_106,
    _CONFIG_PIN_107,
    _CONFIG_PIN_109,
    _CONFIG_PIN_110,
    _CONFIG_PIN_119,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6316_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_PIN_4,
    _CONFIG_PIN_20,
    _CONFIG_PIN_25,
    _CONFIG_PIN_26,
    _CONFIG_PIN_27,
    _CONFIG_PIN_28,
    _CONFIG_PIN_29,
    _CONFIG_PIN_55,
    _CONFIG_PIN_56,
    _CONFIG_PIN_61,
    _CONFIG_PIN_62,
    _CONFIG_PIN_63,
    _CONFIG_PIN_64,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6336_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_76PIN_PIN21,
    _CONFIG_76PIN_PIN22,
    _CONFIG_76PIN_PIN23,
    _CONFIG_76PIN_PIN26,
    _CONFIG_76PIN_PIN30,
    _CONFIG_76PIN_PIN37,
    _CONFIG_76PIN_PIN38,
    _CONFIG_76PIN_PIN58,
    _CONFIG_76PIN_PIN59,
    _CONFIG_76PIN_PIN60,
    _CONFIG_76PIN_PIN61,
    _CONFIG_76PIN_PIN62,
    _CONFIG_76PIN_PIN63,
    _CONFIG_76PIN_PIN68,
} EnumConfigPin;
#elif(_SCALER_TYPE == _RL6373_SERIES)
typedef enum
{
    _CONFIG_PIN_START = 0,
    _CONFIG_PIN_19,
    _CONFIG_PIN_20,
} EnumConfigPin;

#endif
