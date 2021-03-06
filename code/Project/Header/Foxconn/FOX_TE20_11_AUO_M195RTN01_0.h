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
// ID Code      : RL6230_Project.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PROJECT == _FOX_TE20_11_AUO_M195RTN01_0)


//--------------------------------------------------
//  Pcb Define
//--------------------------------------------------
#define _PCB_TYPE                                               _RL6230_FOXCONN_LEN_V20_10_PCB

//--------------------------------------------------
//  Panel Define
//--------------------------------------------------
#define _PANEL_TYPE                                             _FOX_AUO_M195RTN01_0
#define _PANEL_POW_SEQ_FAST_MODE                                _OFF     

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

#define _OSD_TYPE                                               _LENOVO_2014_OSD

#define _OSD_INCLUDE                                            "Lenovo2014Include.h"
#define _USER_FUNCTION_INCLUDE                                  "Lenovo2014UserInclude.h"
#define _USER_TIMER_INCLUDE                                     "Lenovo2014TimerInclude.h"
#define _FACTORY_INCLUDE                                        "FoxconnFactoryInclude.h"

//-------------------------------------------------
// Define DDCCI 
//-------------------------------------------------
#define _DDCCI_RXBUF_LENGTH                                     44
#define _DDCCI_TXBUF_LENGTH                                     44
#define _DDCCI_TIMEOUT_LIMIT                                    500 // 0~65535ms

#define _CAPABILITIES_STRING_VGA 								"(port(monitor)type(LCD)model(LEN TE20-11)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0E 10 12 14(01 05 06 08 0B) 16 18 1A 1E 20 30 3E 52 AC AE B2 B6 C6 C8 C9 CC(02 03 04 05 06 09 0A 0D) D6(01 02 03 04 05) DF FF)mswhql(1)asset_eep(40)mccs_ver(2.1))"

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
#define _I_DITHER_SUPPORT                                       _ON
#define _D_DITHER_SUPPORT                                       _ON
#define _GAMMA_FUNCTION                                         _OFF
#define _PCM_FUNCTION                                           _OFF
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
#define _GLOBAL_HUE_SATURATION                                  _OFF   

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
#define _DCLK_SPREAD_RANGE                                      7//6    // 0~15, 0 ~ disable, 15 ~ 7.50%  //20160309EMI           
#define _DCLK_SPREAD_SPEED                                      _SPEED_66K

//-------------------------------------------------
// Kernel EEPROM Storage Start Address
//-------------------------------------------------
#define _EEPROM_KERNEL_START_ADDRESS                            (_EEPROM_PAGE0_BANK0)

//-------------------------------------------------
// EEPROM Emulation and Flash Options
//-------------------------------------------------
#define _SYSTEM_EEPROM_EMULATION_SUPPORT                        _OFF
#define _FLASH_ACCESS_FUNCTION_SUPPORT                          _OFF
#define _EEPROM_ACCESS_FUNCTION_SUPPORT                         _OFF
#define _FLASH_CLK_SPEED                                        _FLASH_FAST_SPEED                 

#define _FLASH_TYPE_W25X20A_OR_W25X21CL                         _FLASH_W25X20A
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

#define _INPUTCLOCK_RANG_VGA                                    2050      // Unit in 0.1 MHz

//-------------------------------------------------
// Definition of Auto Search STYLE 
//-------------------------------------------------
#define _SOURCE_AUTO_SEARCH_STYLE                               _SOURCE_POLLING_IN_SEARCH_STATE                                

//-------------------------------------------------
// Definitions of Required Default Search Time when Using _SOURCE_POLLING_AFTER_NOSIGNAL_STATE
//-------------------------------------------------
#define _SOURCE_DEFAULT_SEARCH_TIME_VGA                         SEC(0.5)

//-------------------------------------------------
// Define Required Wait Time Before Entering Active State
//-------------------------------------------------
#define _WAIT_TIME_TO_ACTIVE_VGA                                SEC(0.05)

//--------------------------------------------------
// VGA YPBPR Support  
//--------------------------------------------------
#define _YPBPR_SUPPORT                                          _ON
#define _SOG_SUPPORT                                            _ON
#define _VGA_COMPOSITE_SUPPORT                                  _ON

//--------------------------------------------------
// VGA ADC Noise Reduction by Histogram Support
//--------------------------------------------------
#define _ADCNR_BY_HISTOGRAM_SUPPORT                             _OFF
#define _ADCNR_LEVELED_PATTERN_SUPPORT                          _OFF
#define _ADCNR_VERTICAL_BOUNDARY_TYPE                           _NR_V_BOUNDARY_FULL

//--------------------------------------------------
// VGA RGB/YPBPR Default Values  
//--------------------------------------------------
#define _ADC_RGB_DEFAULT_PGA_VALUE                              8
#define _ADC_RGB_DEFAULT_RED_GAIN                               128
#define _ADC_RGB_DEFAULT_GREEN_GAIN                             128
#define _ADC_RGB_DEFAULT_BLUE_GAIN                              128
#define _ADC_RGB_DEFAULT_RED_OFFSET                             128
#define _ADC_RGB_DEFAULT_GREEN_OFFSET                           128
#define _ADC_RGB_DEFAULT_BLUE_OFFSET                            128

#define _ADC_YPBPR_DEFAULT_PGA_VALUE                            8
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
#define _CALIBRATION_R_GAIN_BIAS                                (-3) // Needs modification for EVERY single source
#define _CALIBRATION_G_GAIN_BIAS                                (-3) // Needs modification for EVERY single source
#define _CALIBRATION_B_GAIN_BIAS                                (-3) // Needs modification for EVERY single source
#define _CALIBRATION_R_OFFSET_BIAS                              (1) // Needs modification for EVERY single source
#define _CALIBRATION_G_OFFSET_BIAS                              (1) // Needs modification for EVERY single source
#define _CALIBRATION_B_OFFSET_BIAS                              (1) // Needs modification for EVERY single source

//--------------------------------------------------
// VGA YPBPR Auto Color Method Select
//--------------------------------------------------
#define _YPBPR_AUTO_METHOD                                      _YPBPR_AUTO_BY_SOURCE
#define _AUTO_PB_GAIN_BIAS                                      (4)
#define _AUTO_PR_GAIN_BIAS                                      (4)
#define _AUTO_Y_GAIN_BIAS                                       (1)
#define _AUTO_PB_OFFSET_BIAS                                    (14)
#define _AUTO_PR_OFFSET_BIAS                                    (14)
#define _AUTO_Y_OFFSET_BIAS                                     (-16)

//--------------------------------------------------
// Auto Color Gain/offset Tolerance(128 +/- Tolerance)
//--------------------------------------------------
#define _ADC_WHITEBALANCE_TOLERANCE                             45

//--------------------------------------------------
// Auto Adjust Clock Setup
//--------------------------------------------------
#define _AUTO_CLOCK_STEP                                        1 // 1 or 2
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
#define _DIG_FILTER_PHASE_THD                                   5//5 //effective:0~7
#define _DIG_FILTER_PHASE_DIV_VALUE                             3//0 //effective:0~3

#define _DIG_FILTER_PHASE_ENABLE                                _ENABLE 
#define _DIG_FILTER_NSMEAR_ENABLE                               _ENABLE 
#define _DIG_FILTER_PSMEAR_ENABLE                               _ENABLE 
#define _DIG_FILTER_NRING_ENABLE                                _ENABLE 
#define _DIG_FILTER_PRING_ENABLE                                _ENABLE 
#define _DIG_FILTER_EXTENSION_ENABLE                            _ENABLE 

//-------------------------------------------------
// EDID Options
//-------------------------------------------------
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
#define _EEPROM_EDID_A0_ADDRESS                                 (_EEPROM_PAGE7_BANK0)
#else
#define _EEPROM_EDID_A0_ADDRESS                                 (_MISC_PAGE * _FLASH_PAGE_SIZE)
#endif

//--------------------------------------------------
// Definitions of _VGA_CHROMA_PATTERN12_SUPPORT
//--------------------------------------------------
#define _VGA_CHROMA_PATTERN12_SUPPORT                           _ON

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
#define _NONE_LOGO                                      0
#define _IBM_THINKVISION_LENOVO                         1
#define _LENOVO                                         2
#define _LENOVO_THINKVISION								3
#define _LENOVO_THINKVISION_EPA							4
#define _LENOVO_2015                                    5
#define _LENOVO_2015_EPA                                6
//----------------------------------------------------------------------------------------------------
// Definitions for Language Type setting 
//----------------------------------------------------------------------------------------------------
#define _8_LAN                                          0//_ENGLISH,_FRENCH,_ITALIAN,_CHINESE_S,_SPANISH,_JAPAN,_GERMAN,_RUSSIAN,
#define _2_LAN                                          1//_CHINESE_S,_ENGLISH
#define _1_LAN											2//_CHINESE_S,

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#define _FACTORY_MODE_OWNER								_OWNER_FOXCONN
#define _OSD_ROTATE_FUNCTION							_OFF
#define OOR_DCLK_CHECK                                  _OFF// Definitions of OOR Dclk Auto Adjust
#define _INPUT_PORT_MAX                                 1
#define _DIGITAL1_TYPE                                  _NONE_PORT
#define _DIGITAL2_TYPE                                  _NONE_PORT
#define _LOGO_TYPE                                      _LENOVO_2015_EPA
#define _LANGUAGE_TYPE                                  _8_LAN
#define _LANGUAGE_DEFAULT                               _ENGLISH
#define _USER_DCR_FUNCTION							    _ON

#if((_LOGO_TYPE == _IBM_THINKVISION_LENOVO) || (_LOGO_TYPE == _LENOVO))
#define _EPA_LOGO                                       _ON
#endif

#define _OD_OSD_SUPPORT                                  _OFF
//==================================================================
// Auot Power Down Function
//==================================================================
#define _AUTO_POWER_DOWN                                  _ON
#define _AUTO_POWER_DOWN_DEF							  _OFF

//==================================================================
// Fine tuning OSD H position by pixel
//==================================================================
#define _OSD_POSITION_FONT_A_H_DELAY_                           1

//20130312 Abel DCR Modify
//--------------------------------------------------
// Definitions for DCR Panel ON/OFF Timer
//--------------------------------------------------
#if(_USER_DCR_FUNCTION == _ON)
#undef _DCR_SUPPORT
#define _DCR_SUPPORT											_ON

#define _BACKLIGHT_OFF_TIMER                                    1500 // _BACKLIGHT_OFF_TIMER * _INSTANT_TIMER_EVENT_1 (ms)
#define _DCR_PANEL_ON_OFF							            _ON    
#else
#define _DCR_PANEL_ON_OFF							            _OFF 
#endif

//-------------------------------------------------
// Instant Timer Events Options
// Add ?PR?USERINTERFACETIMER0INSTANTACCESS_TIMER0?RTD2011USERINTERFACE
//     ?PR?USERINTERFACETIMER1INSTANTACCESS_TIMER1?RTD2011USERINTERFACE
// To Link File Bank 0 In Order to Increase Efficiency
//-------------------------------------------------
#define _INSTANT_TIMER_EVENT_0                                  _OFF
#if(((_USER_DCR_FUNCTION == _ON) && (_DCR_PANEL_ON_OFF == _ON)) || ( _AUTO_POWER_DOWN ==_ON))
#define _INSTANT_TIMER_EVENT_1                                  _ON
#else
#define _INSTANT_TIMER_EVENT_1                                  _OFF
#endif

//-------------------------------------------------
//define for lenovo the keypad are aligned with the OSD ICON
//-------------------------------------------------
#define _NAVIGATE_ICON_POSITION_CONTROL							_ON

//20141124 Abel Test
#define _ICON_BLANK1_PIXEL                                      10
#define _ICON_BLANK2_PIXEL                                      15
#define _ICON_BLANK3_PIXEL                                      10
#define _ICON_BLANK4_PIXEL                                      12
#define _ICON_BLANK5_PIXEL                                      20

#define _NAVIGATE_ICON_EXIT_COL_POSITION						4
#define _NAVIGATE_ICON_LEFT_COL_POSITION						11
#define _NAVIGATE_ICON_RIGHT_COL_POSITION						18
#define _NAVIGATE_ICON_ENTER_COL_POSITION						25
#define _NAVIGATE_ICON_POWER_COL_POSITION						31
#define _AFTER_NAVIGATE_ICON_POWER_COL_POSITION                 34 

#define _TEXT_BLANK1_PIXEL                                      13
#define _TEXT_BLANK2_PIXEL                                      12
#define _NAVIGATE_TEXT_EXIT_COL_POSITION						1
#define _NAVIGATE_TEXT_ENTER_COL_POSITION						24
#define _AFTER_NAVIGATE_TEXT_ENTER_COL_POSITION                 32 

//-------------------------------------------------
//define Audio
//-------------------------------------------------
#define _AUDIO_ADJUST_FUNCTION_SUPPORT							_OFF
#define _AUDIO_EXTERNAL_AMP_SUPPORT								_OFF          
#define _ANALOG_VOLUME_MUTE										0x0000

//==================================================================
//==================================================================
//==================================================================
//==================================================================
#define _COLOR_TEMP_DEF									_CT_6500
#define _OSD_CONTRAST_DEF_VALUE                         85    //_CONTRAST_VGA
#define _OSD_BRIGHTNESS_DEF_VALUE                       80

#define _LOW_BLUE_LIGHT_FUNCTION                     	_ON
#define _LBL_HOTKEY_FUNCTION                            _OFF

//==================================================================
//==================================================================
//--------------------------------------------------
// Version Code of NVRam
//--------------------------------------------------
#define _CHECKSUM                                       0x86
#define _VERSION_CODE                                   0xaf

//Facory OSD
#define _FACTORY_PROJECT_NAME                           _T,_E,_2,_0,_MINUS,_1,_1
#define _IC_SERIES                                      _R,_T,_D,_2,_2,_8,_0,_D,_L,_W
#define _FACTORY_PANNEL_NAME							_A,_U,_O,_SPACE,_M,_1,_9,_5,_R,_T,_N,_0,_1,_DOT,_0
#define _FW_VERSION                                     _L,_A, _1, _DOT, _0
#define _FW_RELEASE_DATE                                _2,_0,_1,_7,_0,_7,_3,_1
#define _DDCCI_FIRMWARE_VERSION							0x0100  //Ver 1.00	

//User OSD
#define _MODEL_NAME                                     _T_, _E_, _2_, _0_, _LINE, _1_,_1_
#define _MICROCODE                                      _L_,_A_, _1_, _DOT, _0_
//Facory Command
#define FacoryVersion1                                  'L' //Facory Command show Version
#define FacoryVersion2                                  'A' //Facory Command show Version
#define FacoryVersion3                                  '1' //Facory Command show Version
#define FacoryVersion4                                  '.' //Facory Command show Version
#define FacoryVersion5                                  '0' //Facory Command show Version

#define FacoryBomH1                                     '7'
#define FacoryBomH2                                     '9'
#define FacoryBomH3                                     '0'
#define FacoryBomH4                                     'F'
#define FacoryBomH5                                     '3'
#define FacoryBomH6                                     '1'
#define FacoryBomH7                                     '3'
#define FacoryBomH8                                     '0'

#define FacoryBomL1                                     '0'
#define FacoryBomL2                                     'A'
#define FacoryBomL3                                     '0'
#define FacoryBomL4                                     '0'
#define FacoryBomL5                                     'R'
#define FacoryBomL6                                     '0'
#define FacoryBomL7                                     '0'
//----------------------------------------------------------------------------------------------------
// Definitions for Panel Contrast
//----------------------------------------------------------------------------------------------------
#define _CONTRAST_CHANG_POINT_ANALOG					102
#define _CONTRAST_MAX_ANALOG							116
#define _CONTRAST_MIN_ANALOG							40

#define _CONTRAST_CHANG_POINT_DIGITAL					100
#define _CONTRAST_MAX_DIGITAL							120
#define _CONTRAST_MIN_DIGITAL							40

#define _LOW_BLUE_LIGHT_BACKLIGHT                       50
#define _LOW_BLUE_LIGHT_CONTRAST                        _OSD_CONTRAST_DEF_VALUE

//----------------------------------------------------
// Brightness PWM Table
//----------------------------------------------------
#define _PWM_B00                                        96//|00
#define _PWM_B10                                        97//|10
#define _PWM_B20                                        101//|20
#define _PWM_B30                                        107 //|30
#define _PWM_B40                                        116//|40
#define _PWM_B50                                        129 //|50
#define _PWM_B60                                        145 //|60
#define _PWM_B70                                        166 //|70
#define _PWM_B80                                        208 //|80
#define _PWM_B90                                        218 //|90
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
#define _CT7200_LenovoPrj_RED                                   112
#define _CT7200_LenovoPrj_GREEN                                 116
#define _CT7200_LenovoPrj_BLUE                                  128

#define _CTSRGB_LenovoPrj_RED                                   126
#define _CTSRGB_LenovoPrj_GREEN                                 126
#define _CTSRGB_LenovoPrj_BLUE                                  128

#define _CT6500_LenovoPrj_RED                                   126
#define _CT6500_LenovoPrj_GREEN                                 126
#define _CT6500_LenovoPrj_BLUE                                  128

#define _CT9300_LenovoPrj_RED                                   100
#define _CT9300_LenovoPrj_GREEN                                 104
#define _CT9300_LenovoPrj_BLUE                                  128

#define _CTUSER_LenovoPrj_RED                                   128
#define _CTUSER_LenovoPrj_GREEN                                 128
#define _CTUSER_LenovoPrj_BLUE                                  128

#define _CTLOWBLUELIGHT_RED                                     128
#define _CTLOWBLUELIGHT_GREEN                                   109
#define _CTLOWBLUELIGHT_BLUE                                    84

#endif // End of #if(_PROJECT == _RL6229_PROJECT)
