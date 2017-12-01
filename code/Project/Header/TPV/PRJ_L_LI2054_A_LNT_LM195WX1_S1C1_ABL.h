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
// ID Code      : _PRJ_L_LI2054_A_LNT_LM195WX1_S2A1_ABL.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PROJECT == _PRJ_L_LI2054_A_LNT_LM195WX1_S1C1_ABL)

//--------------------------------------------------
//  Pcb Define
//--------------------------------------------------
#define _PCB_TYPE                                               _PCB_TPV_715G7826_6229_A


//--------------------------------------------------
//  Panel Define
//--------------------------------------------------
#define _PANEL_TYPE                                             _TPV_LNT_LM195WX1_S1C1
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
//    BANK2(?CO?USERCOMMONDDCCIFUNCTION, ?CO?USERCOMMONEEPROMSYSTEM, ?CO?NONEUSERADJUST)// 
//    Remove BANK3(...)                                                                 //
// 4. Change Related Project Define as                                                  //
//    #define _OSD_TYPE                               _NONE_OSD                         //
//    #define _OSD_INCLUDE                            "NoneInclude.h"                   //
//    #define _USER_FUNCTION_INCLUDE                  "NoneUserInclude.h"               //
//    #define _USER_TIMER_INCLUDE                     "NoneTimerInclude.h"              //
//    #define _FACTORY_INCLUDE                        "NoneFactoryInclude.h"            //
//////////////////////////////////////////////////////////////////////////////////////////

#define _OSD_TYPE                                               _LENOVO_ORG_OSD

#define _OSD_ROTATE_FUNCTION									_OFF

#define _OSD_INCLUDE                                            "LenovoOrgInclude.h"
#define _USER_FUNCTION_INCLUDE                                  "LenovoOrgUserInclude.h"
#define _USER_TIMER_INCLUDE                                     "LenovoOrgTimerInclude.h"
#define _FACTORY_INCLUDE                                        "TPVFactoryInclude.h"
#define _FACTORY_COMMAND_INCLUDE                                "FacOption_LI2054_A_6229.h"


//-------------------------------------------------
// Define DDCCI 
//-------------------------------------------------
#define _DDCCI_RXBUF_LENGTH                                     41
#define _DDCCI_TXBUF_LENGTH                                     41
#define _DDCCI_TIMEOUT_LIMIT                                    500 // 0~65535ms
//Eli 20130426 delete 5000 K.
//Eli 20130426 delete VCP Command 87 (sharpness).
//Eli 20130426 delete VCP Command 60 (0F 11).
//Robert Wang 20130520 modify language
#define _CAPABILITIES_STRING_VGA                                "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 0E 10 12 14(01 05 06 08 0B) 16 18 1A 1E 1F 20 30 3E 52 60(01) AC AE B2 B6 C6 C8 CA CC(02 03 04 05 06 09 0A 0D) D6(01 04 05) DF FD FF)mswhql(1)asset_eep(40)mccs_ver(2.2))"
//#define _CAPABILITIES_STRING_DVI                                "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 10 12 14(01 05 06 08 0B) 16 18 1A 52 60(01 03) AC AE B2 B6 C6 C8 CA CC(02 03 04 05 06 09 0A 0D) D6(01 04) DF FD FF)mswhql(1)asset_eep(40)mccs_ver(2.2))"
//#define _CAPABILITIES_STRING_HDMI                               "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 10 12 14(01 05 06 08 0B) 16 18 1A 52 60(01 03) AC AE B2 B6 C6 C8 CA CC(02 03 04 05 06 09 0A 0D) D6(01 04) DF FD FF)mswhql(1)asset_eep(40)mccs_ver(2.2))"
//#define _CAPABILITIES_STRING_DP                                 "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 10 12 14(01 05 06 08 0B) 16 18 1A 52 60(01 03) AC AE B2 B6 C6 C8 CA CC(02 03 04 05 06 09 0A 0D) D6(01 04) DF FD FF)mswhql(1)asset_eep(40)mccs_ver(2.2))"
                                                    

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
#define _I_DITHER_SUPPORT                                       _ON
#define _D_DITHER_SUPPORT                                       _ON
#define _GAMMA_FUNCTION                                         _OFF                                                                
#define _PCM_FUNCTION                                           _OFF
#define _COLOR_FORMAT_CONVERT                                   _OFF                        
#define _RGB_QUANTIZATION_RANGE_SUPPORT                         _OFF
#define _YCC_QUANTIZATION_RANGE_SUPPORT                         _OFF
#define _ULTRA_VIVID_SUPPORT                                    _ON     
#define _DCR_SUPPORT                                            _OFF
#define _DCC_HISTOGRM_INFO                                      _OFF
#define _DCC_FUNCTION                                           _ON
#define _ICM_SUPPORT                                            _OFF
#define _HIGHLIGHT_WINDOW_SUPPORT                               _ON
#define _SIX_COLOR_SUPPORT                                      _OFF

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

#define _OCC_SUPPORT                                            _OFF                       

//==================================================================
// Definitions for User DCR Function setting //Robert Wang 20131225 modify
//==================================================================
#define _USER_DCR_FUNCTION							            _ON//_OFF

#if(_USER_DCR_FUNCTION == _ON)
#undef _DCR_SUPPORT
#define _DCR_SUPPORT                                            _ON

#define _BACKLIGHT_OFF_TIMER                                    1500 // _BACKLIGHT_OFF_TIMER * _INSTANT_TIMER_EVENT_1 (ms)
#define _DCR_PANEL_ON_OFF							            _ON   
#else
#define _DCR_PANEL_ON_OFF							            _OFF 
#endif
#define _USER_DCR_OSD_FUNCTION							        _OFF

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
#define _ASPECT_ORIGINAL_MODE_SUPPORT                           _OFF

//--------------------------------------------------
// Overscan Support
//--------------------------------------------------
#define _OVERSCAN_H_RATIO                                       30                        
#define _OVERSCAN_V_RATIO                                       30      

#define _OVERSCAN_VGA_SUPPORT                                   _OFF
#define _OVERSCAN_DVI_SUPPORT                                   _OFF                        
#define _OVERSCAN_HDMI_SUPPORT                                  _OFF                        
#define _OVERSCAN_DP_SUPPORT                                    _OFF                        
                    
//--------------------------------------------------
// Total Display Lines for Input Timing 640x350
//--------------------------------------------------                                      
#define _640_X_350_V_HEIGHT                                     400

//--------------------------------------------------
// Mode Search condition reference by picture width
//--------------------------------------------------                                      
#define _MODE_SEARCH_BY_ACTIVE_MEASURE_SUPPORT                  _OFF

//--------------------------------------------------
// Audio Related Option
//--------------------------------------------------
#define _AUDIO_SUPPORT                                          _OFF 
           
#define _EMBEDDED_DAC_SUPPORT                                   _OFF//_ON
#define _SLEEP_AUDIO_SUPPORT                                    _OFF                        
#define _PS_AUDIO_INPUT                                         _PS_AUDIO_LINE_IN                     

#define _ANALOG_VOLUME_MAX                                      0x0037 // MAX: 0x0037
#define _ANALOG_VOLUME_MIN                                      0x0000
#define _ANALOG_VOLUME_CENTER                                   ((_ANALOG_VOLUME_MAX + _ANALOG_VOLUME_MIN) / 2)

#define _DIGITAL_AUDIO_VOLUME_RESOLUTION                        _AUDIO_VOLUME_14BIT
#define _DIGITAL_VOLUME_MAX                                     0x3FFF // _AUDIO_VOLUME_8BIT MAX:0x00FF, _AUDIO_VOLUME_14BIT MAX:0x3FFF
#define _DIGITAL_VOLUME_MIN                                     0x0000
#define _DIGITAL_VOLUME_CENTER                                  ((_DIGITAL_VOLUME_MAX + _DIGITAL_VOLUME_MIN) / 2)

//--------------------------------------------------
// Memory Config
//--------------------------------------------------
#define _SDRAM_SIZE_CONFIG                                      _1M_16BIT
#define _SDRAM_ACCEPTABLE_HSD_RATIO                             65 // HSD coef/100

//-------------------------------------------------
// OD Support Define  
//-------------------------------------------------
#define _OD_SUPPORT                                             _ON
#define _OD_OSD_SUPPORT                                         _ON

//-------------------------------------------------
// FRC Support Define  
//-------------------------------------------------
#define _FRC_SUPPORT                                            _OFF
                          
//--------------------------------------------------
// 3D Support Define
//--------------------------------------------------
#define _3D_SUPPORT                                             _OFF
#define _2D_TO_3D_FUNCTION                                      _OFF

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
#define _FLASH_ACCESS_FUNCTION_SUPPORT							_ON //20121008 HDCP key write modify
#define _EEPROM_ACCESS_FUNCTION_SUPPORT                         _OFF
#define _FLASH_CLK_SPEED                                        _FLASH_FAST_SPEED                 

#define _FLASH_TYPE_W25X20A_OR_W25X21CL                         _FLASH_W25X20A
#define _FLASH_TYPE_W25X40CL_OR_W25X41CL                        _FLASH_W25X41CL         
#define _FLASH_TYPE_EN25F20A_OR_EN25F20                         _FLASH_EN25F20A
#define _FLASH_TYPE_GD25Q40B_OR_GD25Q41                         _FLASH_GD25Q41

#define _START_OF_PAGEID                                        _PAGEID_0
#define _END_OF_PAGEID                                          _PAGEID_0
#define _CHECKSUM_VERSIONCODE_ID                                _PAGEID_0

//--------------------------------------------------
// Definitions of Flash Bank Location
//--------------------------------------------------
#define _SYSTEM_EEPROM_EMULATION_FLASH_BANK                     7
#define _OGC_FLASH_BANK                                         7
#define _EEPROM_HDCP_KEY_FLASH_BANK                             7

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
#define _OOR_V_FREQ_UPPER_BOUND                                 860        // Unit in 0.1 HZ
#define _OOR_V_FREQ_LOWER_BOUND                                 230        // Unit in 0.1 HZ
#define _OOR_H_WIDTH_UPPER_BOUND                                2048       // Unit in pixel
#define _OOR_V_HEIGHT_LOWER_BOUND                               240        // Unit in line

#define _FAIL_SAVE_H_FREQ_UPPER_BOUND                           1000       // Unit in 0.1 kHZ
#define _FAIL_SAVE_H_FREQ_LOWER_BOUND                           110        // Unit in 0.1 kHZ
#define _FAIL_SAVE_V_FREQ_UPPER_BOUND                           758        // Unit in 0.1 HZ
#define _FAIL_SAVE_V_FREQ_LOWER_BOUND                           495        // Unit in 0.1 HZ

#define _INPUTCLOCK_RANG_VGA                                    2100       // Unit in 0.1 MHz
#define _INPUTCLOCK_RANG_DVI                                    1650       // Unit in 0.1 MHz
#define _INPUTCLOCK_RANG_HDMI                                   2250       // Unit in 0.1 MHz
#define _INPUTCLOCK_RANG_DP                                     2250       // Unit in 0.1 MHz

//-------------------------------------------------
// Definition of Auto Search STYLE 
//-------------------------------------------------
#define _SOURCE_AUTO_SEARCH_STYLE                               _SOURCE_POLLING_IN_SEARCH_STATE                                

//-------------------------------------------------
// Definitions of Required Default Search Time when Using _SOURCE_POLLING_AFTER_NOSIGNAL_STATE
//-------------------------------------------------
#define _SOURCE_DEFAULT_SEARCH_TIME_VGA                         SEC(0.5)
#define _SOURCE_DEFAULT_SEARCH_TIME_TMDS                        SEC(2) 
#define _SOURCE_DEFAULT_SEARCH_TIME_DP                          SEC(2) 


//-------------------------------------------------
// Define Required Wait Time Before Entering Active State
//-------------------------------------------------
#define _WAIT_TIME_TO_ACTIVE_VGA                                SEC(0.05)
#define _WAIT_TIME_TO_ACTIVE_DVI                                SEC(0.1)
#define _WAIT_TIME_TO_ACTIVE_HDMI                               SEC(0.1)
#define _WAIT_TIME_TO_ACTIVE_DP                                 SEC(0.1)
                        

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
#define _ADC_RGB_DEFAULT_PGA_VALUE                              8   // 0 ~ 15
#define _ADC_RGB_DEFAULT_RED_GAIN                               128
#define _ADC_RGB_DEFAULT_GREEN_GAIN                             128
#define _ADC_RGB_DEFAULT_BLUE_GAIN                              128
#define _ADC_RGB_DEFAULT_RED_OFFSET                             128
#define _ADC_RGB_DEFAULT_GREEN_OFFSET                           128
#define _ADC_RGB_DEFAULT_BLUE_OFFSET                            128

#define _ADC_YPBPR_DEFAULT_PGA_VALUE                            8   // 0 ~ 15
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
#define _AUTO_PB_GAIN_BIAS                                      (2)
#define _AUTO_PR_GAIN_BIAS                                      (2)
#define _AUTO_Y_GAIN_BIAS                                       (2)
#define _AUTO_PB_OFFSET_BIAS                                    (12)
#define _AUTO_PR_OFFSET_BIAS                                    (12)
#define _AUTO_Y_OFFSET_BIAS                                     (-16)

//--------------------------------------------------
// Auto Color Gain/offset Tolerance(128 +/- Tolerance)
//--------------------------------------------------
#define _ADC_WHITEBALANCE_TOLERANCE                             45

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
#define _DIG_FILTER_PHASE_THD                                   6 //effective:0~7
#define _DIG_FILTER_PHASE_DIV_VALUE                             1 //effective:0~3
#define _DIG_FILTER_PHASE_ENABLE                                _ENABLE 
#define _DIG_FILTER_NSMEAR_ENABLE                               _ENABLE 
#define _DIG_FILTER_PSMEAR_ENABLE                               _ENABLE 
#define _DIG_FILTER_NRING_ENABLE                                _ENABLE 
#define _DIG_FILTER_PRING_ENABLE                                _ENABLE 
#define _DIG_FILTER_EXTENSION_ENABLE                            _ENABLE 

//-------------------------------------------------
// TMDS Options  
//-------------------------------------------------
#define _DVI_DE_ONLY_SUPPORT                                    _OFF   
#define _HDMI_FROM_DVI_CONNECT                                  _OFF     

//--------------------------------------------------
// TMDS CTS Options  
//--------------------------------------------------
#define _TMDS_HDCP_FEATURE                                      _HDCP_FEATURE_BY_INPUT
#define _TMDS_Z0_POWER_SAVING_OPTION                            _ALL_CHANNEL_CONNECTED_FOR_CTS

//-------------------------------------------------
// DP Capability Options
//-------------------------------------------------
#define _DP_LINK_CLK_RATE                                       _DP_HIGH_SPEED_270Mhz                        
#define _DP_MAIN_LINK_LANES                                     _DP_FOUR_LANE                        

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
#define _HDCP_KEY_LOCATION                                      _TABLE_LOCATION_USER   //20121018_2 HDCP KEY Modify
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
#define _EEPROM_HDCP_KEY_ADDRESS                                (_EEPROM_PAGE6_BANK1)
#else
#define _EEPROM_HDCP_KEY_ADDRESS                                (_EEPROM_EDID_D1_ADDRESS + _EMBEDDED_DDCRAM_D1_SIZE)
#endif
 
//-------------------------------------------------
// Instant Timer Events Options (enable --> unit:ms, disable --> _OFF
//-------------------------------------------------
#define _INSTANT_TIMER_EVENT_0                                  _OFF
#if ((_USER_DCR_FUNCTION == _ON) && (_DCR_PANEL_ON_OFF == _ON))
#define _INSTANT_TIMER_EVENT_1                                  _ON
#else
#define _INSTANT_TIMER_EVENT_1                                  _OFF
#endif

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
// Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

//==================================================================
// Version Code of NVRam
//==================================================================
#define _CHECKSUM                                               0x11
#define _VERSION_CODE                                           0x22

//==================================================================
//  For Lenovo Fac Define
//==================================================================
#define _OWNER_NONE                                             0
#define _OWNER_RTK                                              1
#define _OWNER_TPV                                              2
#define _OWNER_FOXCONN                                          3
#define _OWNER_WISTRON       					                4

#define _FACTORY_MODE_OWNER                                     _OWNER_TPV

//==================================================================
//_b0_~_b9_ only for Lenovo Green OSD
//==================================================================
#define _MODEL_NAME												_bL_, _bI_, _2_, _0_, _5_, _4_
#define _MICROCODE												_bL_,_bG_, _0_, _DOT, _1_

#define _FACTORY_PROJECT_NAME                                   _L,_I,_2,_0,_5,_4
#define _FW_RELEASE_DATE                                        _2,_0,_1,_6,_0,_2,_0,_4
#define _FW_VERSION                                             _L,_G,_0,_DOT,_1
#define _DDCCI_FIRMWARE_VERSION							        0x0001  //Ver 0.01	
#define _IC_SERIES                                      		_R,_T,_D,_2,_2,_8,_1,_L,_R

#define _PANNEL_NAME 											'L','M','1','9','5','W','X','1'

//==================================================================
// Digital Port Setting for OSD Input source switch sub menu.
// Description  : The _DVI_PORT,_HDMI_PORT,_DP_PORT,_NONE_PORT defines can't be changed.
//==================================================================
#define _DVI_PORT                                               2//_SOURCE_DVI
#define _HDMI_PORT                                              3//_SOURCE_HDMI
#define _DP_PORT                                                4//_SOURCE_DP
#define _NONE_PORT                                              5//_SOURCE_NONE

#define _INPUT_PORT_MAX                                         1
#define _DIGITAL1_TYPE                                          _NONE_PORT
#define _DIGITAL2_TYPE                                          _NONE_PORT

//==================================================================
// Definitions for Language Logo setting 
//==================================================================
#define _NONE_LOGO                                              0
#define _IBM_THINKVISION_LENOVO                                 1
#define _LENOVO                                                 2
#define _LENOVO_THINKVISION										3
#define _LENOVO_THINKVISION_EPA									4
#define _LENOVO_2015                                            5
#define _LENOVO_2015_EPA                                        6

#define _LOGO_TYPE                                              _LENOVO_2015_EPA

#if((_LOGO_TYPE == _IBM_THINKVISION_LENOVO) || (_LOGO_TYPE == _LENOVO))
#define _EPA_LOGO                                               _ON
#endif

//==================================================================
// Definitions for Language Type setting 
//==================================================================
#define _8_LAN                                                  0//_ENGLISH,_FRENCH,_ITALIAN,_CHINESE_S,_SPANISH,_JAPAN,_GERMAN,_RUSSIAN,
#define _2_LAN                                                  1//_CHINESE_S,_ENGLISH

#define _LANGUAGE_TYPE                                          _8_LAN

//==================================================================
// Definitions for Language default setting
//==================================================================
#define _LANGUAGE_DEFAULT                                       _ENGLISH

//==================================================================
// Definitions for Panel Contrast
//==================================================================
#define _COLOR_TEMP_DEF                                         _CT_6500

//#define MAX_CONTRAST_RATIO                                      115//133 // 1.75(unit 1/100)
//#define DEF_CONTRAST_RATIO                                      100//104//101 // 1.00(unit 1/100)
//#define MIN_CONTRAST_RATIO                                      15//15  // 0.5(unit 1/100)

#define MAX_CONTRAST_TO_REG_VALUE             					115
#define MIN_CONTRAST_TO_REG_VALUE              					15
#define DEF_CONTRAST_TO_REG_VALUE               				100
 
#define MAX_CONTRAST_TO_INTERNET_VALUE  						115
#define MIN_CONTRAST_TO_INTERNET_VALUE   						15
#define DEF_CONTRAST_TO_INTERNET_VALUE    						100
 
#define MAX_CONTRAST_TO_VIDEO_VALUE                  			115
#define MIN_CONTRAST_TO_VIDEO_VALUE                   			15
#define DEF_CONTRAST_TO_VIDEO_VALUE             				100
 
#define MAX_CONTRAST_TO_SPLIT_VALUE           					115
#define MIN_CONTRAST_TO_SPLIT_VALUE            					15
#define DEF_CONTRAST_TO_SPLIT_VALUE             				100

#define _OSD_BRIGHTNESS_DEF_VALUE                               50
#define _OSD_CONTRAST_DEF_VALUE                                 50  //_CONTRAST

#define _OSD_BRIGHTNESS_WEB_VALUE                               70
#define _OSD_CONTRAST_WEB_VALUE                                 60  

#define _OSD_BRIGHTNESS_VIDEO_VALUE                             90
#define _OSD_CONTRAST_VIDEO_VALUE                               65  

#define _OSD_BRIGHTNESS_SPLIT_VALUE                             90
#define _OSD_CONTRAST_SPLIT_VALUE                               65  

#define _LOW_BLUE_LIGHT_FUNCTION                        		_ON

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
#define _LBL_BRIGHTNESS_DEF_VALUE                       		25
#define _LBL_CONTRAST_DEF_VALUE                                 _OSD_CONTRAST_DEF_VALUE    
#endif

//==================================================================
//OSD OD Gain Default Value
//==================================================================
#define _OD_MULTI_SELECT                                        _ON
#define _OSD_OD_DEF_VALUE										_OD_NORMAL

#define _OD_OFF                                                 0
#define _OD_NORMAL                                              1
#define _OD_EXTREME                                             2

#define _OD_NORMAL_GAIN                                         0x30//6.51ms
#define _OD_EXTREME_GAIN                                        0x60// 4.88ms

//==================================================================
// Brightness PWM Table
//==================================================================
#define _PWM_B00                                                0x58 //|00
#define _PWM_B10                                                0x6C//0x58 //|10
#define _PWM_B20                                                0x81//0x5B //|20
#define _PWM_B30                                                0x96//0x63 //|30
#define _PWM_B40                                                0xAA//0x6D //|40
#define _PWM_B50                                                0xB4//0xBF//0x7B //|50
#define _PWM_B60                                                0xBD//0xC6//0x8D //|60
#define _PWM_B70                                                0xC6//0xCE//0x9A //|70
#define _PWM_B80                                                0xDE//0xBF //|80
#define _PWM_B90                                                0xF6//0xEE//0xDE //|90
#define _PWM_B100                                               0xFF //|100

#define MIN_BACKLIGHT_PWM                                       _PWM_B00

#if((_PWM_B50>_PWM_B60)||(_PWM_B60>_PWM_B70)||(_PWM_B70>_PWM_B80)||(_PWM_B80>_PWM_B90)||(_PWM_B90>_PWM_B100))
  #error: PWM data error!!!
#endif  

//==================================================================
// Definitions of OOR Dclk Auto Adjust
//==================================================================
#define OOR_DCLK_CHECK                                  		_ON

//==================================================================
// Definitions of _VGA_CHROMA_PATTERN12_SUPPORT
//==================================================================
#define _VGA_CHROMA_PATTERN12_SUPPORT                           _ON

//==================================================================
// COLOR TEMP DEFAULT DATA
// Definitions Colortemp RGB value for each project
//==================================================================
#define _CT7200_LenovoPrj_RED                                   115
#define _CT7200_LenovoPrj_GREEN                                 121
#define _CT7200_LenovoPrj_BLUE                                  128

#define _CTSRGB_LenovoPrj_RED                                   128
#define _CTSRGB_LenovoPrj_GREEN                                 128
#define _CTSRGB_LenovoPrj_BLUE                                  128

#define _CT6500_LenovoPrj_RED                                   128
#define _CT6500_LenovoPrj_GREEN                                 128
#define _CT6500_LenovoPrj_BLUE                                  128

#define _CT9300_LenovoPrj_RED                                   105//98
#define _CT9300_LenovoPrj_GREEN                                 115//109
#define _CT9300_LenovoPrj_BLUE                                  128

#define _CTUSER_LenovoPrj_RED                                   0x80
#define _CTUSER_LenovoPrj_GREEN                                 0x80
#define _CTUSER_LenovoPrj_BLUE                                  0x80

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)

#define _CTLOWBLUELIGHT_RED								  		128
#define _CTLOWBLUELIGHT_GREEN							   		128
#define _CTLOWBLUELIGHT_BLUE							   		85

#endif

//-------------------------------------------------
//define Audio
//-------------------------------------------------
#define _AUDIO_ADJUST_FUNCTION_SUPPORT				            _OFF
#define _AUDIO_EXTERNAL_AMP_SUPPORT								_OFF
#define _ANALOG_VOLUME_MUTE										0x0000

//==================================================================
// Fine tuning OSD H position by pixel
//==================================================================
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
#define _OSD_POSITION_FONT_A_H_DELAY_                           1
#else
#define _OSD_POSITION_FONT_A_H_DELAY_                           0
#endif

//==================================================================
// Panel VCOM Function
//==================================================================
#define _PANEL_VCOM_ADJUST_FUNCTION						        _ON

//-------------------------------------------------
//Definitions for panel backlight PWM ferq.
//-------------------------------------------------
#define _PWMFREQIVF                                             0
#define _PWMFREQ20K                                             1
#define _PWMFREQ22K                                             2

#define _BACKLIGHT_PWM_FREQ_SELECT                              _PWMFREQ20K

//==================================================================
// Auot Power Down Function
//==================================================================
#define _AUTO_POWER_DOWN                                        _OFF

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
// Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo Lenovo
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

                                                
#endif // End of #if(_PROJECT == _PRJ_L_LI2054_A_LNT_LM195WX1_S2A1_ABL)
