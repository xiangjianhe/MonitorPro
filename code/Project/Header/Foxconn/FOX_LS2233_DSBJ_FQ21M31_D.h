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
// ID Code      : RL6336_Project.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PROJECT == _FOX_LS2233_DSBJ_FQ21M31_D)


//--------------------------------------------------
//  Pcb Define
//--------------------------------------------------
#define _PCB_TYPE                                               _RL6336_FOXCONN_LEN_LS2233_PCB


//--------------------------------------------------
//  Panel Define
//--------------------------------------------------
#define _PANEL_TYPE                                             _FOX_DSBJ_FQ21M31_D
#define _PANEL_POW_SEQ_FAST_MODE                                _ON     

//--------------------------------------------------
//  Panel Switch Slew Rate Control Define
//--------------------------------------------------
#define _PANEL_SWITCH_PAD_SUPPORT                               _OFF

//--------------------------------------------------
//  Osd Define
//--------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////
// Guideline to use _NONE_OSD:                                                          //
// 1. De-Select the following folders to be built in                                    //
//    RTD2011Function/RTD2011Osd/RTDFactory                                             //
// 2. Select the following folders to be built in                                       //
//    NoneFunction/NoneOsd/NoneFactory                                                  //
// 3. Modify BL51 Misc Setting                                                          //
//    Replace BANK2(...) with                                                           //
//    BANK2(?CO?USERCOMMONDDCCIFUNCTION, ?CO?UserCommonNVRamSYSTEM, ?CO?NONEUSERADJUST)//
//    Remove BANK3(...)                                                                 //
// 4. Change Related Project Define as                                                  //
//    #define _OSD_TYPE                               _NONE_OSD                         //
//    #define _OSD_INCLUDE                            "NoneInclude.h"                   //
//    #define _USER_FUNCTION_INCLUDE                  "NoneUserInclude.h"               //
//    #define _USER_TIMER_INCLUDE                     "NoneTimerInclude.h"              //
//    #define _FACTORY_INCLUDE                        "NoneFactoryInclude.h"            //
//////////////////////////////////////////////////////////////////////////////////////////

#define _OSD_TYPE                                               _LEONVO_GREEN_OSD

#define _OSD_INCLUDE                                            "LenovoGreenInclude.h"
#define _USER_FUNCTION_INCLUDE                                  "LenovoGreenUserInclude.h"
#define _USER_TIMER_INCLUDE                                     "LenovoGreenTimerInclude.h"
#define _FACTORY_INCLUDE                                        "FoxconnFactoryInclude.h"

//-------------------------------------------------
// Define DDCCI 
//-------------------------------------------------
#define _DDCCI_RXBUF_LENGTH                                     44
#define _DDCCI_TXBUF_LENGTH                                     44
#define _DDCCI_TIMEOUT_LIMIT                                    500 // 0~65535ms

#define _CAPABILITIES_STRING_VGA                                "(prot(monitor)type(LCD)model(LEN LS2233)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0E 10 12 14(01 05 06 08 0B) 16 18 1A 1E 20 30 3E 52 60(01 03) AC AE B2 B6 C6 C8 C9 CA CC(02 03 04 05 06 09 0A 0D) D6(01 02 03 04 05) DF)mswhql(1)asset_eep(40)mccs_ver(2.1))"
#define _CAPABILITIES_STRING_DVI                                "(prot(monitor)type(LCD)model(LEN LS2233)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 10 12 14(01 05 06 08 0B) 16 18 1A 52 60(01 03) AC AE B2 B6 C6 C8 CA CC(02 03 04 05 06 09 0A 0D) D6(01 02 03 04 05) DF)mswhql(1)asset_eep(40)mccs_ver(2.1))"
#define _CAPABILITIES_STRING_HDMI                               ""
                                                    

//--------------------------------------------------
//  Digital Functional Support Define
//--------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////////
// When the following functions are disabled:                                        //
// _GLOBAL_HUE_SATURATION                                                            //
// _DCC_FUNCTION                                                                     //
// _I_DITHER_SUPPORT                                                                 //
// _SIX_COLOR_SUPPORT                                                                //
// Please remove ?CO?SCALERCOLOR and ?CO?RL6xxx_SERIES_COLOR from BANK1 in BL51 Misc //
///////////////////////////////////////////////////////////////////////////////////////
#define _D_DITHER_SUPPORT                                       _ON
#define _GAMMA_FUNCTION                                         _OFF
#define _COLOR_FORMAT_CONVERT                                   _ON                        
#define _DCR_SUPPORT                                            _OFF
#define _DCC_HISTOGRM_INFO                                      _OFF
#define _DCC_FUNCTION                                           _OFF
#define _ICM_SUPPORT                                            _OFF
#define _HIGHLIGHT_WINDOW_SUPPORT                               _OFF
#define _SIX_COLOR_SUPPORT                                      _OFF

//--------------------------------------------------
// Definitions of Ypeaking 
//--------------------------------------------------
#define _YPEAKING_SUPPORT                                       _OFF

#define _YPEAKING_CORING_MIN                                    3   //effective:0~31
#define _YPEAKING_MAX_POS                                       20  //effective:0~255
#define _YPEAKING_MAX_NEG                                       -40 //effective:-128~127

//-------------------------------------------------
// Hue and Saturation Options
//-------------------------------------------------
#define _GLOBAL_HUE_SATURATION                                  _ON    

#define _SATURATION_MAX                                         200
#define _SATURATION_MIN                                         0

#define _HUE_MAX                                                230
#define _HUE_MIN                                                30

//-------------------------------------------------
// OGC and OCC Options
//-------------------------------------------------
#define _OGC_SUPPORT                                            _OFF
#define _OGC_DICOM_SUPPORT                                      _OFF                       
#define _OGC_FLASH_PAGE                                         10
#define _OGC_TOTAL_GAMMA                                        5   //effective: 3 or 5

//-------------------------------------------------
// Engery Star - DCR Options
//-------------------------------------------------
////////////////////////////////////////////////////////
//  DCR     |                                         //
//  REB     |                                         //
//  average |                                         //
//  value   |                                         //
//          |                                         //
//          |                                         //
//          |----------|------------|----------> PWM  //
//                    TH1          TH2                //
//          |<-Scale1->|<--Scale2-->|<-Scale3->|      //
////////////////////////////////////////////////////////

#define _ENERGY_STAR_SUPPORT                                    _OFF

// Definition of Adjustable Step Size.
#define _ES_DCR_STEP_RANGE_SCALE_1                              (1)
#define _ES_DCR_STEP_RANGE_SCALE_2                              (2)
#define _ES_DCR_STEP_RANGE_SCALE_3                              (3)

// Definition of Threshold of Setting Different Step Size. 
#define _ES_DCR_STEP_RANGE_THRESHOLD_1                          (85)    // Digital code
#define _ES_DCR_STEP_RANGE_THRESHOLD_2                          (210)   // Digital code

// Definitions of Backlight Min Value.
#define _ES_DCR_ACTIVE_BACKLIGHT_MIN                            (16)    // Range: 0 ~ 255

// Avoid picture flick on toggle point
// if abs(Pre_Frame - Cur_Frame) > _ES_DCR_FRAME_DIFFERENCE_DIRECT_SET_THRESHOLD, 
// then apply direct to taget backlight value.
#define _ES_DCR_FRAME_DIFFERENCE_DIRECT_SET_THRESHOLD           (200)   // Digital code

// if (abs(Pre_Frame - Cur_Frame) > _ES_DCR_FRAME_DIFFERENCE_THRESHOLD_MIN),
// then adjust to Taget PWM value step by step.
#define _ES_DCR_FRAME_DIFFERENCE_THRESHOLD_MIN                  (10)    // Digital code

// Definition of Adjust PWM Time.
#define _ES_DCR_ADJUST_TIME                                     (2)    // unit: DVSync time

#define _ES_DCR_MEASURE_THRESHOLD_1                             (0x08)
#define _ES_DCR_MEASURE_THRESHOLD_2                             (0x60)

//--------------------------------------------------
// Aspect Ratio Support
//--------------------------------------------------
#define _ASPECT_RATIO_SUPPORT                                   _ON    

//--------------------------------------------------
// Overscan Support
//--------------------------------------------------
#define _OVERSCAN_H_RATIO                                       30                        
#define _OVERSCAN_V_RATIO                                       30                        

#define _OVERSCAN_VGA_SUPPORT                                   _OFF                        
#define _OVERSCAN_DVI_SUPPORT                                   _OFF                        
#define _OVERSCAN_HDMI_SUPPORT                                  _OFF                        

//--------------------------------------------------
// Total Display Lines for Input Timing 640x350
//--------------------------------------------------                                      
#define _640_X_350_V_HEIGHT                                     400

//--------------------------------------------------
// Mode Search condition reference by picture width
//--------------------------------------------------                                      
#define _MODE_SEARCH_BY_ACTIVE_MEASURE_SUPPORT                  _OFF

//-------------------------------------------------
// Spread Spectrum Options
//-------------------------------------------------
#define _DCLK_SPREAD_RANGE                                      6    // 0~15, 0 ~ disable, 15 ~ 7.50%             
#define _DCLK_SPREAD_SPEED                                      _SPEED_33K

//-------------------------------------------------
// Kernel EEPROM Storage Start Address
//-------------------------------------------------
#define _EEPROM_KERNEL_START_ADDRESS                            (_EEPROM_PAGE0_BANK0)

//-------------------------------------------------
// EEPROM Emulation and Flash Options
//-------------------------------------------------
#define _SYSTEM_EEPROM_EMULATION_SUPPORT                        _ON
#define _FLASH_ACCESS_FUNCTION_SUPPORT                          _ON
#define _EEPROM_ACCESS_FUNCTION_SUPPORT                         _ON
#define _FLASH_CLK_SPEED                                        _FLASH_FAST_SPEED                 

#define _FLASH_TYPE_W25X20A_OR_W25X21CL                         _FLASH_W25X21CL
#define _FLASH_TYPE_W25X40CL_OR_W25X41CL                        _FLASH_W25X40CL         
#define _FLASH_TYPE_EN25F20A_OR_EN25F20                         _FLASH_EN25F20A
#define _FLASH_TYPE_GD25Q40B_OR_GD25Q41                         _FLASH_GD25Q41

#define _START_OF_PAGEID                                        _PAGEID_0
#define _END_OF_PAGEID                                          _PAGEID_0
#define _CHECKSUM_VERSIONCODE_ID                                _PAGEID_0

//--------------------------------------------------
// Definitions of Flash Bank Location
//--------------------------------------------------
#define _SYSTEM_EEPROM_EMULATION_FLASH_BANK                     3
#define _OGC_FLASH_BANK                                         3
#define _EEPROM_HDCP_KEY_FLASH_BANK                             3

//--------------------------------------------------
// Definitions of Flash Page Configuration
//--------------------------------------------------
#define _SYSTEM_EEPROM_EMULATION_START_PAGE                     13
#define _SYSTEM_EEPROM_EMULATION_END_PAGE                       14

//--------------------------------------------------
// Timing Support
//--------------------------------------------------
#define _OOR_H_FREQ_UPPER_BOUND                                 1100       // Unit in 0.1 kHZ
#define _OOR_H_FREQ_LOWER_BOUND                                 100        // Unit in 0.1 kHZ
#define _OOR_V_FREQ_UPPER_BOUND                                 855        // Unit in 0.1 HZ
#define _OOR_V_FREQ_LOWER_BOUND                                 450        // Unit in 0.1 HZ
#define _OOR_H_WIDTH_UPPER_BOUND                                2048       // Unit in pixel
#define _OOR_V_HEIGHT_LOWER_BOUND                               240        // Unit in line

#define _FAIL_SAVE_H_FREQ_UPPER_BOUND                           1000       // Unit in 0.1 kHZ
#define _FAIL_SAVE_H_FREQ_LOWER_BOUND                           110        // Unit in 0.1 kHZ
#define _FAIL_SAVE_V_FREQ_UPPER_BOUND                           756        // Unit in 0.1 HZ
#define _FAIL_SAVE_V_FREQ_LOWER_BOUND                           495        // Unit in 0.1 HZ

#define _INPUTCLOCK_RANG_VGA                                    2100      // Unit in 0.1 MHz
#define _INPUTCLOCK_RANG_DVI                                    1650      // Unit in 0.1 MHz
#define _INPUTCLOCK_RANG_HDMI                                   2250      // Unit in 0.1 MHz


//-------------------------------------------------
// Definition of Auto Search STYLE 
//-------------------------------------------------
#define _SOURCE_AUTO_SEARCH_STYLE                               _SOURCE_POLLING_AFTER_NOSIGNAL_STATE                                

//-------------------------------------------------
// Definitions of Required Default Search Time when Using _SOURCE_POLLING_AFTER_NOSIGNAL_STATE
//-------------------------------------------------
#define _SOURCE_DEFAULT_SEARCH_TIME_VGA                         SEC(0.5)
#define _SOURCE_DEFAULT_SEARCH_TIME_TMDS                        SEC(2)

//-------------------------------------------------
// Define Required Wait Time Before Entering Active State
//-------------------------------------------------
#define _WAIT_TIME_TO_ACTIVE_VGA                                SEC(0.05)
#define _WAIT_TIME_TO_ACTIVE_DVI                                SEC(0.1)
#define _WAIT_TIME_TO_ACTIVE_HDMI                               SEC(0.1)


//--------------------------------------------------
// VGA YPBPR Support  
//--------------------------------------------------
#define _YPBPR_SUPPORT                                          _ON
#define _SOG_SUPPORT                                            _ON
#define _VGA_COMPOSITE_SUPPORT                                  _ON

//--------------------------------------------------
// VGA RGB/YPBPR Default Values  
//--------------------------------------------------
#define _ADC_RGB_DEFAULT_PGA_VALUE                              4   // 0 ~ 7
#define _ADC_RGB_DEFAULT_RED_GAIN                               128
#define _ADC_RGB_DEFAULT_GREEN_GAIN                             128
#define _ADC_RGB_DEFAULT_BLUE_GAIN                              128
#define _ADC_RGB_DEFAULT_RED_OFFSET                             128
#define _ADC_RGB_DEFAULT_GREEN_OFFSET                           128
#define _ADC_RGB_DEFAULT_BLUE_OFFSET                            128

#define _ADC_YPBPR_DEFAULT_PGA_VALUE                            4   // 0 ~ 7
#define _ADC_YPBPR_DEFAULT_Y_GAIN                               159
#define _ADC_YPBPR_DEFAULT_PB_GAIN                              154
#define _ADC_YPBPR_DEFAULT_PR_GAIN                              154
#define _ADC_YPBPR_DEFAULT_Y_OFFSET                             112
#define _ADC_YPBPR_DEFAULT_PB_OFFSET                            128
#define _ADC_YPBPR_DEFAULT_PR_OFFSET                            128

//--------------------------------------------------
// VGA SELF_CALIBRATION Support 
//--------------------------------------------------
#define _ADC_SELF_CALIBRATION                                   _ON
#define _CALIBRATION_R_GAIN_BIAS                                (0) // Needs modification for EVERY single source
#define _CALIBRATION_G_GAIN_BIAS                                (0) // Needs modification for EVERY single source
#define _CALIBRATION_B_GAIN_BIAS                                (0) // Needs modification for EVERY single source
#define _CALIBRATION_R_OFFSET_BIAS                              (0) // Needs modification for EVERY single source
#define _CALIBRATION_G_OFFSET_BIAS                              (0) // Needs modification for EVERY single source
#define _CALIBRATION_B_OFFSET_BIAS                              (0) // Needs modification for EVERY single source

//--------------------------------------------------
// VGA YPBPR Auto Color Method Select
//--------------------------------------------------
#define _YPBPR_AUTO_METHOD                                      _YPBPR_AUTO_BY_SOURCE
#define _AUTO_PB_GAIN_BIAS                                      (4)
#define _AUTO_PR_GAIN_BIAS                                      (4)
#define _AUTO_Y_GAIN_BIAS                                       (0)
#define _AUTO_PB_OFFSET_BIAS                                    (0)
#define _AUTO_PR_OFFSET_BIAS                                    (0)
#define _AUTO_Y_OFFSET_BIAS                                     (-16)

//--------------------------------------------------
// Auto Color Gain/offset Tolerance(128 +/- Tolerance)
//--------------------------------------------------
#define _ADC_WHITEBALANCE_TOLERANCE                             75

//--------------------------------------------------
// Auto Adjust Clock Setup
//--------------------------------------------------
#define _AUTO_CLOCK_STEP                                        2 // 1 or 2
#define _AUTO_CLOCK_RANGE                                       95 // Set Clock Non-adjusting Range (%) by the active region
#define _AUTO_TOLERANCE_PIXEL                                   2 // Definitions Of tolerance pixel for Auto Clock
#define _AUTO_CLOCK_SAVE_VALUE_OPTION                           _CLOCK_SAVE_PERCENT_VALUE

//-------------------------------------------------
// Define Max Adjustable H Position Range
//-------------------------------------------------
#define _MAX_H_POSITION_RANGE                                   100 // Pixel
#define _MAX_V_POSITION_RANGE                                   100 // Line

//--------------------------------------------------
// Definitions of Digital Filter
//--------------------------------------------------
#define _DIG_FILTER_PHASE_THD                                   192 //effective:0~255
#define _DIG_FILTER_PHASE_DIV_VALUE                             1 //effective:0~3

#define _DIG_FILTER_PHASE_ENABLE                                _ENABLE 
#define _DIG_FILTER_NSMEAR_ENABLE                               _ENABLE 
#define _DIG_FILTER_PSMEAR_ENABLE                               _ENABLE 
#define _DIG_FILTER_NRING_ENABLE                                _ENABLE 
#define _DIG_FILTER_PRING_ENABLE                                _ENABLE 
#define _DIG_FILTER_EXTENSION_ENABLE                            _ENABLE 
#define _DIG_FILTER_ENHANCE_PHASE_ENABLE                        _ENABLE

//-------------------------------------------------
// TMDS Options  
//-------------------------------------------------
#define _DVI_DE_ONLY_SUPPORT                                    _ON     
#define _HDMI_FROM_DVI_CONNECT                                  _ON 

//--------------------------------------------------
// TMDS CTS Options  
//--------------------------------------------------
#define _TMDS_HDCP_FEATURE                                      _HDCP_FEATURE_BY_INPUT   
#define _TMDS_Z0_POWER_SAVING_OPTION                            _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS

//-------------------------------------------------
// EDID Options
//-------------------------------------------------
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
#define _EEPROM_EDID_A0_ADDRESS                                 (_EEPROM_PAGE7_BANK0)
#else
#define _EEPROM_EDID_A0_ADDRESS                                 (_MISC_PAGE * _FLASH_PAGE_SIZE)
#endif
#define _EEPROM_EDID_D0_ADDRESS                                 (_EEPROM_EDID_A0_ADDRESS + _EMBEDDED_DDCRAM_A0_SIZE)
#define _EEPROM_EDID_D1_ADDRESS                                 (_EEPROM_EDID_D0_ADDRESS + _EMBEDDED_DDCRAM_D0_SIZE)

//-------------------------------------------------
// HDCP Key Options
//-------------------------------------------------
#define _WRITE_HDCP_TO_SYSTEM_EEPROM                            _OFF
#define _HDCP_KEY_LOCATION                                      _TABLE_LOCATION_SYSTEM_EEPROM
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
#define _EEPROM_HDCP_KEY_ADDRESS                                (_EEPROM_PAGE6_BANK1)
#else
#define _EEPROM_HDCP_KEY_ADDRESS                                (_EEPROM_EDID_D1_ADDRESS + _EMBEDDED_DDCRAM_D1_SIZE)
#endif

//-------------------------------------------------
// Instant Timer Events Options
// Add ?PR?USERINTERFACETIMER0INSTANTACCESS_TIMER0?RTD2011USERINTERFACE
//     ?PR?USERINTERFACETIMER1INSTANTACCESS_TIMER1?RTD2011USERINTERFACE
// To Link File Bank 0 In Order to Increase Efficiency
//-------------------------------------------------
#define _INSTANT_TIMER_EVENT_0                                  _OFF

#if(_DCR_SUPPORT == _ON)
#define _INSTANT_TIMER_EVENT_1                                  _ON
#else
#define _INSTANT_TIMER_EVENT_1                                  _OFF
#endif
//--------------------------------------------------
// Definitions of _VGA_CHROMA_PATTERN12_SUPPORT
//--------------------------------------------------
#define _VGA_CHROMA_PATTERN12_SUPPORT                           _ON
//--------------------------------------------------
// High Charge Pump Current for 25MHz --> only effected in RL6096
//--------------------------------------------------
#define _TMDS_25M_HIGH_CHARGE_PUMP_CURRENT                      _ON

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
// Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
// Factory Mode Owner
//----------------------------------------------------------------------------------------------------
#define _OWNER_NONE										0
#define _OWNER_RTK										1
#define _OWNER_TPV										2
#define _OWNER_FOXCONN                                  3 
#define _OWNER_WISTRON       					        4

//-------------------------------------------------
// Digital Port Setting for OSD Input source switch sub menu.
// Description  : The _DVI_PORT,_HDMI_PORT,_DP_PORT,_NONE_PORT defines can't be changed.
//-------------------------------------------------
#define _DVI_PORT                                       2//_SOURCE_DVI
#define _HDMI_PORT                                      3//_SOURCE_HDMI
#define _DP_PORT                                        4//_SOURCE_DP
#define _NONE_PORT                                      5//_SOURCE_NONE
//--------------------------------------------------
// Definitions for Language Logo setting 
//--------------------------------------------------
#define _NONE_LOGO										0
#define _IBM_THINKVISION_LENOVO							1
#define _LENOVO											2
#define _LENOVO_THINKVISION								3
#define _LENOVO_THINKVISION_EPA							4
#define _LENOVO_2015                                    5
#define _LENOVO_2015_EPA                                6

//----------------------------------------------------------------------------------------------------
// Definitions for Language Type setting 
//----------------------------------------------------------------------------------------------------
#define _8_LAN                                          0//_ENGLISH,_FRENCH,_ITALIAN,_CHINESE_S,_SPANISH,_JAPAN,_GERMAN,_RUSSIAN,
#define _2_LAN                                          1//_CHINESE_S,_ENGLISH

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#define _FACTORY_MODE_OWNER								_OWNER_FOXCONN
#define _OSD_ROTATE_FUNCTION							_OFF
#define OOR_DCLK_CHECK                                  _OFF// Definitions of OOR Dclk Auto Adjust
#define _INPUT_PORT_MAX                                 2
#define _DIGITAL1_TYPE                                  _DVI_PORT
#define _DIGITAL2_TYPE                                  _NONE_PORT
#define _LOGO_TYPE                                      _LENOVO//_IBM_THINKVISION_LENOVO
#define _LANGUAGE_TYPE                                  _8_LAN
#define _LANGUAGE_DEFAULT                               _ENGLISH
#define _USER_DCR_FUNCTION							    _OFF

#if((_LOGO_TYPE == _IBM_THINKVISION_LENOVO) || (_LOGO_TYPE == _LENOVO))
#define _EPA_LOGO                                       _OFF
#endif

#define _LOW_BLUE_LIGHT_FUNCTION                         _ON

//--------------------------------------------------
// Definitions of LBL hot key OSD H Position Range
//--------------------------------------------------
#define _OSD_LBL_H_POS                                  904
#define _OSD_LBL_V_POS                                  8

//--------------------------------------------------
// Version Code of NVRam
//--------------------------------------------------
#define _CHECKSUM                                       0x29
#define _VERSION_CODE                                   0xaf

//Facory OSD
#define _FACTORY_PROJECT_NAME                           _L,_S,_2,_2,_3,_3,_SPACE,_W,_i,_d,_e
#define _FACTORY_PANNEL_NAME							_D,_S,_B,_J,_SPACE,_F,_Q,_2,_1,_M,_3,_1,_D
#define _IC_SERIES                                      _R,_T,_D,_2,_2,_8,_1,_C,_L
#define _FW_RELEASE_DATE                                _2,_0,_1,_5,_0,_7,_0,_3
#define _FW_VERSION                                     _L,_D, _2, _DOT, _0
#define _DDCCI_FIRMWARE_VERSION							0x0200//	0x0301 

//User OSD
#define _MODEL_NAME                                     _bL_, _bS_,_b2_, _b2_, _b3_, _b3_, ___,_bW_,_bi_,_bd_,_be_
#define _MICROCODE                                      _bL_,_bD_, _b2_, _DOT, _b0_
//Facory Command
#define FacoryVersion1                                  'L' //Facory Command show Version
#define FacoryVersion2                                  'D' //Facory Command show Version
#define FacoryVersion3                                  '2' //Facory Command show Version
#define FacoryVersion4                                  '.' //Facory Command show Version
#define FacoryVersion5                                  '0' //Facory Command show Version

#define FacoryBomH1                                     '7'
#define FacoryBomH2                                     '9'
#define FacoryBomH3                                     '0'
#define FacoryBomH4                                     'F'
#define FacoryBomH5                                     'H'
#define FacoryBomH6                                     '1'
#define FacoryBomH7                                     '3'
#define FacoryBomH8                                     '0'

#define FacoryBomL1                                     '0'
#define FacoryBomL2                                     'H'
#define FacoryBomL3                                     '0'
#define FacoryBomL4                                     '0'
#define FacoryBomL5                                     'R'
#define FacoryBomL6                                     '0'
#define FacoryBomL7                                     '0'

//----------------------------------------------------------------------------------------------------
// Definitions for Panel Contrast
//----------------------------------------------------------------------------------------------------
#define _COLOR_TEMP_DEF									_CT_6500

#define _OSD_CONTRAST_DEF_VALUE                         85    //_CONTRAST_VGA
#define _OSD_BRIGHTNESS_DEF_VALUE                       80

//LowBlueLight Contrast Backlight  DEF
#define _LBL_CONTRAST_DEF                               85    
#define _LBL_BRIGHTNESS_DEF                             80

#define _CONTRAST_CHANG_POINT_ANALOG					100
#define _CONTRAST_MAX_ANALOG							116
#define _CONTRAST_MIN_ANALOG							40

#define _CONTRAST_CHANG_POINT_DIGITAL					100
#define _CONTRAST_MAX_DIGITAL							116
#define _CONTRAST_MIN_DIGITAL							40

//----------------------------------------------------
// Brightness PWM Table
//----------------------------------------------------
#define _PWM_B00                                        70//|00
#define _PWM_B10                                        71//|10
#define _PWM_B20                                        74//|20
#define _PWM_B30                                        81 //|30
#define _PWM_B40                                        91//|40
#define _PWM_B50                                        107 //|50
#define _PWM_B60                                        125 //|60
#define _PWM_B70                                        150 //|70
#define _PWM_B80                                        179 //|80
#define _PWM_B90                                        214 //|90
#define _PWM_B100                                       255 //|100

#define MIN_BACKLIGHT_PWM                               _PWM_B00
//-----------------------------------------------------------------------------------------------------------
#if((_PWM_B50>_PWM_B60)||(_PWM_B60>_PWM_B70)||(_PWM_B70>_PWM_B80)||(_PWM_B80>_PWM_B90)||(_PWM_B90>_PWM_B100))
  #error: PWM data error!!!
#endif

//==================================================================
// COLOR TEMP DEFAULT DATA
// Definitions Colortemp RGB value for each project
//==================================================================
#define _CT7200_LenovoPrj_RED                                   124
#define _CT7200_LenovoPrj_GREEN                                 128
#define _CT7200_LenovoPrj_BLUE                                  124

#define _CTSRGB_LenovoPrj_RED                                   128
#define _CTSRGB_LenovoPrj_GREEN                                 128
#define _CTSRGB_LenovoPrj_BLUE                                  128

#define _CT6500_LenovoPrj_RED                                   128
#define _CT6500_LenovoPrj_GREEN                                 128
#define _CT6500_LenovoPrj_BLUE                                  128

#define _CT9300_LenovoPrj_RED                                   110
#define _CT9300_LenovoPrj_GREEN                                 118
#define _CT9300_LenovoPrj_BLUE                                  128

#define _CTUSER_LenovoPrj_RED                                   128
#define _CTUSER_LenovoPrj_GREEN                                 128
#define _CTUSER_LenovoPrj_BLUE                                  128

#define _CTLOWBLUELIGHT_RED                                     128
#define _CTLOWBLUELIGHT_GREEN                                   109
#define _CTLOWBLUELIGHT_BLUE                                    84

//-------------------------------------------------
//define Audio
//-------------------------------------------------
#define _AUDIO_ADJUST_FUNCTION_SUPPORT				            _OFF
#define _AUDIO_EXTERNAL_AMP_SUPPORT								_OFF
#define _ANALOG_VOLUME_MUTE										0x0000

//==================================================================
// Fine tuning OSD H position by pixel
//==================================================================
#define _OSD_POSITION_FONT_A_H_DELAY_                           1

#endif // End of #if(_PROJECT == _FOX_E2013W_CMI_M195FGE_L20)

