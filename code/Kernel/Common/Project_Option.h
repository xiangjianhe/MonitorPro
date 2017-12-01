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
// ID Code      : Project_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// Definitions by Project
//****************************************************************************
//--------------------------------------------------
//  Panel Define
//--------------------------------------------------
#ifndef _PANEL_EMBEDDED_LED_DRIVER_SUPPORT
#define _PANEL_EMBEDDED_LED_DRIVER_SUPPORT                      _OFF
#endif

//--------------------------------------------------
//  HP Source Scan Define Option
//--------------------------------------------------
#ifndef _HP_SOURCE_SCAN_SUPPORT
#define _HP_SOURCE_SCAN_SUPPORT                                 _OFF
#endif

//-------------------------------------------------
// Definitions of Required Default Search Time when NOT Using _SOURCE_POLLING_IN_SEARCH_STATE
//-------------------------------------------------
#ifndef _SOURCE_DEFAULT_SEARCH_TIME_VGA
#define _SOURCE_DEFAULT_SEARCH_TIME_VGA                         SEC(0.5)
#endif

#ifndef _SOURCE_DEFAULT_SEARCH_TIME_TMDS
#define _SOURCE_DEFAULT_SEARCH_TIME_TMDS                        SEC(2)
#endif

#ifndef _SOURCE_DEFAULT_SEARCH_TIME_DP
#define _SOURCE_DEFAULT_SEARCH_TIME_DP                          SEC(2) 
#endif

//-------------------------------------------------
// Definitions of Required Default Search Time when No Cable
//-------------------------------------------------
#ifndef _SOURCE_DEFAULT_SEARCH_TIME_VGA_NO_CABLE
#define _SOURCE_DEFAULT_SEARCH_TIME_VGA_NO_CABLE                SEC(0.5)
#endif

#ifndef _SOURCE_DEFAULT_SEARCH_TIME_TMDS_NO_CABLE
#define _SOURCE_DEFAULT_SEARCH_TIME_TMDS_NO_CABLE               SEC(0.5)
#endif

#ifndef _SOURCE_DEFAULT_SEARCH_TIME_DP_NO_CABLE
#define _SOURCE_DEFAULT_SEARCH_TIME_DP_NO_CABLE                 SEC(0.5) 
#endif

//-------------------------------------------------
// Definitions of Required Time to Auto Search for Asus
//-------------------------------------------------
#ifndef _SOURCE_ASUS_START_AUTO_TIME
#define _SOURCE_ASUS_START_AUTO_TIME                            SEC(2)
#endif

//--------------------------------------------------
//  Digital Functional Support Define
//--------------------------------------------------
#ifndef _I_DITHER_SUPPORT
#define _I_DITHER_SUPPORT                                       _OFF
#endif

#ifndef _PCM_FUNCTION
#define _PCM_FUNCTION                                           _OFF
#endif

#ifndef _RGB_QUANTIZATION_RANGE_SUPPORT
#define _RGB_QUANTIZATION_RANGE_SUPPORT                         _OFF
#endif

#ifndef _YCC_QUANTIZATION_RANGE_SUPPORT
#define _YCC_QUANTIZATION_RANGE_SUPPORT                         _OFF
#endif

#ifndef _ULTRA_VIVID_SUPPORT
#define _ULTRA_VIVID_SUPPORT                                    _OFF     
#endif

#ifndef _ICM_BRI_SUPPORT
#define _ICM_BRI_SUPPORT                                        _OFF
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)

#if((_SCALER_TYPE == _RL6192_SERIES) || (_SCALER_TYPE == _RL6229_SERIES))
#define _ULTRA_VIVID_TABLE_TYPE                                 _ULTRA_VIVID_GEN_0
#elif(_SCALER_TYPE == _RL6297_SERIES)
#define _ULTRA_VIVID_TABLE_TYPE                                 _ULTRA_VIVID_GEN_1
#elif(_SCALER_TYPE == _RL6269_SERIES)
#define _ULTRA_VIVID_TABLE_TYPE                                 _ULTRA_VIVID_GEN_2
#endif

#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#ifndef _YPEAKING_SUPPORT
#define _YPEAKING_SUPPORT                                       _OFF    
#endif

#ifndef _SIX_COLOR_SUPPORT
#define _SIX_COLOR_SUPPORT                                      _OFF
#endif

#if(_SIX_COLOR_SUPPORT == _ON)
#undef _ICM_SUPPORT
#define _ICM_SUPPORT                                            _ON
#endif

#if((_SCALER_TYPE == _RL6001_SERIES) || (_SCALER_TYPE == _RL6096_SERIES) || (_SCALER_TYPE == _RL6192_SERIES) || \
    (_SCALER_TYPE == _RL6213_SERIES) || (_SCALER_TYPE == _RL6229_SERIES) || (_SCALER_TYPE == _RL6230_SERIES) || \
    (_SCALER_TYPE == _RL6269_SERIES) || (_SCALER_TYPE == _RL6297_SERIES))        
#define _SCALING_UP_TYPE                                        _SU_GEN_0 // H_SU: 128 taps, V_SU: 128 taps
#elif((_SCALER_TYPE == _RL6316_SERIES) || (_SCALER_TYPE == _RL6373_SERIES))
#define _SCALING_UP_TYPE                                        _SU_GEN_1 // H_SU: 128 taps, V_SU: 96 taps
#elif(_SCALER_TYPE == _RL6336_SERIES)
#define _SCALING_UP_TYPE                                        _SU_GEN_2 // H_SU: 96 taps, V_SU: 96 taps
#endif


#if(_ICM_SUPPORT == _ON)

#if((_SCALER_TYPE == _RL6001_SERIES) || (_SCALER_TYPE == _RL6192_SERIES) || \
    (_SCALER_TYPE == _RL6096_SERIES) || (_SCALER_TYPE == _RL6213_SERIES) || (_SCALER_TYPE == _RL6336_SERIES))
#define _ICM_TABLE_TYPE                                         _ICM_GEN_0
#elif((_SCALER_TYPE == _RL6230_SERIES) || (_SCALER_TYPE == _RL6229_SERIES) || \
      (_SCALER_TYPE == _RL6297_SERIES))
#define _ICM_TABLE_TYPE                                         _ICM_GEN_1
#elif(_SCALER_TYPE == _RL6269_SERIES || (_SCALER_TYPE == _RL6316_SERIES) || (_SCALER_TYPE == _RL6373_SERIES))
#define _ICM_TABLE_TYPE                                         _ICM_GEN_2
#endif

#endif  // End of #if(_ICM_SUPPORT == _ON)

#if((_SCALER_TYPE == _RL6336_SERIES) && (_DCC_HISTOGRM_INFO == _ON))
#define _DCC_HISTOGRAM_THD_CHANGE                               _ON
#else
#define _DCC_HISTOGRAM_THD_CHANGE                               _OFF
#endif

#ifndef _DIG_FILTER_ENHANCE_PHASE_ENABLE
#define _DIG_FILTER_ENHANCE_PHASE_ENABLE                        _DISABLE
#endif

#ifndef _RINGING_FILTER_SUPPORT
#define _RINGING_FILTER_SUPPORT                                 _OFF
#endif

#define _SATURATION_CENTER                                      ((_SATURATION_MAX + _SATURATION_MIN) / 2)
#define _HUE_CENTER                                             ((_HUE_MAX + _HUE_MIN) / 2)

#ifndef _GAMMA_WRITE_FUNCTION
#define _GAMMA_WRITE_FUNCTION                                   _OFF
#endif

/*
#if(_ENERGY_STAR_SUPPORT == _ON)
#undef _DCR_SUPPORT
#define _DCR_SUPPORT                                            _ON
#endif
*/

//-------------------------------------------------
// OGC and OCC Options
//-------------------------------------------------
#ifndef _OCC_SUPPORT
#define _OCC_SUPPORT                                            _OFF
#endif

#if(_OGC_SUPPORT == _ON)
#undef _GAMMA_FUNCTION
#define _GAMMA_FUNCTION                                         _ON
#endif

#if(_OCC_SUPPORT == _ON)
#undef _PCM_FUNCTION
#define _PCM_FUNCTION                                           _ON
#endif

#if(_OGC_DICOM_SUPPORT == _ON)
#undef _GAMMA_FUNCTION
#define _GAMMA_FUNCTION                                         _ON
#endif

#if((_SCALER_TYPE == _RL6001_SERIES) || (_SCALER_TYPE == _RL6096_SERIES) || (_SCALER_TYPE == _RL6213_SERIES) || \
    (_SCALER_TYPE == _RL6230_SERIES)) 
#define _DDOMAIN_COLORSPACECONVERT                              _OFF
#else
#define _DDOMAIN_COLORSPACECONVERT                              _ON
#endif
//-------------------------------------------------
// Define DDCCI 
//-------------------------------------------------
#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))

#if(_DDCCI_RXBUF_LENGTH < 125)
#undef _DDCCI_RXBUF_LENGTH
#define _DDCCI_RXBUF_LENGTH                                     125
#endif

#endif

//--------------------------------------------------
// Aspect Ratio Support
//--------------------------------------------------
#ifndef _ASPECT_ORIGINAL_MODE_SUPPORT
#define _ASPECT_ORIGINAL_MODE_SUPPORT                           _OFF
#endif

//--------------------------------------------------
// Overscan Support
//--------------------------------------------------
#ifndef _OVERSCAN_DVI_SUPPORT
#define _OVERSCAN_DVI_SUPPORT                                   _OFF
#endif

#ifndef _OVERSCAN_HDMI_SUPPORT
#define _OVERSCAN_HDMI_SUPPORT                                  _OFF                        
#endif

#ifndef _OVERSCAN_DP_SUPPORT
#define _OVERSCAN_DP_SUPPORT                                    _OFF                                             
#endif

//-------------------------------------------------
// Audio Related Option
//-------------------------------------------------
#ifndef _AUDIO_SUPPORT
#define _AUDIO_SUPPORT                                          _OFF 
#define _EMBEDDED_DAC_SUPPORT                                   _OFF
#define _SLEEP_AUDIO_SUPPORT                                    _OFF                       
#define _PS_AUDIO_INPUT                                         _PS_AUDIO_LINE_IN
#endif

#if(_AUDIO_SUPPORT == _OFF)
#undef _EMBEDDED_DAC_SUPPORT
#define _EMBEDDED_DAC_SUPPORT                                   _OFF

#undef _SLEEP_AUDIO_SUPPORT
#define _SLEEP_AUDIO_SUPPORT                                    _OFF
#endif

#if(_EMBEDDED_DAC_SUPPORT == _OFF)
#undef _PS_AUDIO_INPUT
#define _PS_AUDIO_INPUT                                         _PS_AUDIO_DP
#endif

#if(_AUDIO_SUPPORT == _ON)
#if((_SCALER_TYPE == _RL6001_SERIES) || (_SCALER_TYPE == _RL6192_SERIES))
#undef _DIGITAL_AUDIO_VOLUME_RESOLUTION
#define _DIGITAL_AUDIO_VOLUME_RESOLUTION                        _AUDIO_VOLUME_8BIT
#endif

#if((_DIGITAL_AUDIO_VOLUME_RESOLUTION == _AUDIO_VOLUME_8BIT) && (_DIGITAL_VOLUME_MAX > 0x00FF))
#undef _DIGITAL_VOLUME_MAX
#define _DIGITAL_VOLUME_MAX                                     0x00FF
#endif

#if(_DIGITAL_AUDIO_VOLUME_RESOLUTION == _AUDIO_VOLUME_14BIT)
#define _AUDIO_DVC_SUPPORT                      _ON
#else
#define _AUDIO_DVC_SUPPORT                      _OFF
#endif

#if(_AUDIO_DVC_SUPPORT == _ON)
#ifndef _DVC_ADJUST_TYPE
#define _DVC_ADJUST_TYPE                        _DB_GAIN // For mute
#endif

#ifndef _DB_GAIN_DOWN_VALUE
#define _DB_GAIN_DOWN_VALUE                     _DB_GAIN_1_8_DB // Volume up step for _DB_GAIN mode
#endif

#ifndef _DB_GAIN_UP_VALUE
#define _DB_GAIN_UP_VALUE                       _DB_GAIN_1_8_DB // Volume down step for _DB_GAIN mode
#endif

#ifndef _VOLUME_STEP_SIZE_VALUE
#define _VOLUME_STEP_SIZE_VALUE                 (0x0040 & 0x3FFF) // Volume step for _VOLUME_STEP_SIZE mode
#endif

#endif // End of #if(_AUDIO_DVC_SUPPORT == _ON)
#endif

// Generate Internal Digital Audio Sequence for Speaker or DAC Test
#ifndef _INTERNAL_AUDIO_TEST_SUPPORT
#define _INTERNAL_AUDIO_TEST_SUPPORT                            _OFF
#endif

//--------------------------------------------------
// SDRAM Size Config
//--------------------------------------------------
#ifndef _SDRAM_SIZE_CONFIG
#define _SDRAM_SIZE_CONFIG                                      _NO_MEMORY
#endif

//--------------------------------------------------
// 1M32 SDRAM Vendor Select (Only for RL6001)
//--------------------------------------------------
#ifndef _SDRAM_1M32_NEW_VENDOR_SUPPORT
#define _SDRAM_1M32_NEW_VENDOR_SUPPORT                          _OFF
#endif

//--------------------------------------------------
// SDRAM Related Function Config
//--------------------------------------------------
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
#undef _FRC_SUPPORT
#define _FRC_SUPPORT                                            _OFF

#undef _3D_SUPPORT
#define _3D_SUPPORT                                             _OFF
#endif

//-------------------------------------------------
// SDRAM calibration
//-------------------------------------------------

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)

#if(_SCALER_TYPE == _RL6001_SERIES)
#define _SDRAM_PHASE_CALIBRATION                                _OFF
#else
#define _SDRAM_PHASE_CALIBRATION                                _ON

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
// 2047 row, Bank1, 248 column (remain 8 cell)
#define _SDRAM_PHASE_ON_LINE_ADDRESS                            (0x1FFDF7) 
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
// 2047 row, Bank1, 248 column (remain 8 cell)
#define _SDRAM_PHASE_ON_LINE_ADDRESS                            (0x1FFDF7) 
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
// 2047 row, Bank3, 248 column (remain 8 cell)
#define _SDRAM_PHASE_ON_LINE_ADDRESS                            (0x1FFFF7) 
#endif

#endif

#else 
#define _SDRAM_PHASE_CALIBRATION                                _OFF
#endif

//-------------------------------------------------
// OD Support Define  
//-------------------------------------------------
#ifndef _OD_SUPPORT
#define _OD_SUPPORT                                             _OFF
#endif

#if(_OD_SUPPORT == _ON)

#if(_SCALER_TYPE == _RL6001_SERIES)
#define _OD_TABLE_TYPE                                          _OD_GEN_0
#elif((_SCALER_TYPE == _RL6229_SERIES) || (_SCALER_TYPE == _RL6269_SERIES))
#define _OD_TABLE_TYPE                                          _OD_GEN_1
#else
#warning "_OD_TABLE_TYPE not selected!!"
#endif

#endif  // End of #if(_OD_SUPPORT == _ON)

//-------------------------------------------------
// FRC Support Define  
//-------------------------------------------------
#ifndef _FRC_SUPPORT
#define _FRC_SUPPORT                                            _OFF     
#endif

//--------------------------------------------------
// 3D Support Define
//--------------------------------------------------
#ifndef _3D_SUPPORT
#define _3D_SUPPORT                                             _OFF
#endif

#ifndef _2D_TO_3D_FUNCTION
#define _2D_TO_3D_FUNCTION                                      _OFF
#endif

//--------------------------------------------------
// freesync Support Define
//--------------------------------------------------
#ifndef _HDMI_FREESYNC_SUPPORT
#define _HDMI_FREESYNC_SUPPORT                                  _OFF
#endif

#ifndef _HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD
#define _HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD                 _EDID_SWITCH_MODE
#endif

#ifndef _DP_FREESYNC_SUPPORT
#define _DP_FREESYNC_SUPPORT                                    _OFF
#endif

//-------------------------------------------------
// FreeSync Option
//-------------------------------------------------
#if((_DP_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_SUPPORT == _ON))
#define _FREESYNC_SUPPORT                                       _ON
#else
#define _FREESYNC_SUPPORT                                       _OFF
#endif


#if((_SCALER_TYPE != _RL6336_SERIES) && (_FREESYNC_SUPPORT == _ON))
#warning "Only RL6336 Support Freesync!!"
#endif

//-------------------------------------------------
// EEPROM Emulation and Flash Options
//-------------------------------------------------
#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
#undef _FLASH_ACCESS_FUNCTION_SUPPORT
#define _FLASH_ACCESS_FUNCTION_SUPPORT                          _ON
#endif

//-------------------------------------------------
// Flash Enable Write protect
//-------------------------------------------------
#ifndef _FLASH_WR_PROTECT
#define _FLASH_WR_PROTECT                                       _OFF
#endif

//-------------------------------------------------
// Prevent EEPROM Emulation and OGC page overlap 
// Prevent EEPROM Emulation page overstep the boundary
//-------------------------------------------------
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)

#if((_OGC_FLASH_BANK == _SYSTEM_EEPROM_EMULATION_FLASH_BANK) && \
    ((_SYSTEM_EEPROM_EMULATION_END_PAGE >= _OGC_FLASH_PAGE) && \
    (_SYSTEM_EEPROM_EMULATION_START_PAGE < (_OGC_FLASH_PAGE + (((_OGC_SUPPORT == _ON) ? 2:0) + (((_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON)) ? 1:0))))))
#error "System eeprom emulation page and OGC flash page overlap!!"
#endif

#if(_SYSTEM_EEPROM_EMULATION_END_PAGE > 14)
#error "System eeprom emulation end page error !!"
#endif

#if((_SYSTEM_EEPROM_EMULATION_END_PAGE - _SYSTEM_EEPROM_EMULATION_START_PAGE) < (_END_OF_PAGEID - _START_OF_PAGEID + 1))
#warning "Flash page number and page id number warning!!"
#endif

#endif

//--------------------------------------------------
// VGA Options  
//--------------------------------------------------
#if(_YPBPR_SUPPORT == _ON)
#undef _SOG_SUPPORT
#define _SOG_SUPPORT                                            _ON     
#endif

//--------------------------------------------------
// VGA ADC Noise Reduction by Histogram Support
//--------------------------------------------------
#ifndef _ADCNR_BY_HISTOGRAM_SUPPORT
#define _ADCNR_BY_HISTOGRAM_SUPPORT                             _OFF
#endif

//--------------------------------------------------
// VGA Chroma Pattern 12 Support
//--------------------------------------------------
#ifndef _VGA_CHROMA_PATTERN12_SUPPORT
#define _VGA_CHROMA_PATTERN12_SUPPORT                           _OFF
#endif

//--------------------------------------------------
// VGA 25MHz Noise Reduce by SF/SHA LPF Setting 
//--------------------------------------------------
#ifndef _VGA_ADC_SF_SHA_LPF_UNDER_25MHZ_SUPPORT                         
#define _VGA_ADC_SF_SHA_LPF_UNDER_25MHZ_SUPPORT                 _OFF
#endif

//--------------------------------------------------
// VGA custom auto-color Support
//--------------------------------------------------
#ifndef _VGA_CUSTOM_AUTOCOLOR_SUPPORT
#define _VGA_CUSTOM_AUTOCOLOR_SUPPORT                           _OFF
#endif

#if(_VGA_CUSTOM_AUTOCOLOR_SUPPORT == _ON)
#ifndef _VGA_CUSTOM_AUTOCOLOR_PATTERN_SETTING
#define _VGA_CUSTOM_AUTOCOLOR_PATTERN_SETTING                   _ON
#endif
#endif

//--------------------------------------------------
// VGA Fixed Position When Auto Clock Abort --> for DELL
//--------------------------------------------------
#ifndef _VGA_AUTO_CLOCK_ABORT_FIXED_POSITION                 
#define _VGA_AUTO_CLOCK_ABORT_FIXED_POSITION                    _OFF
#endif

//--------------------------------------------------
// TMDS Options  
//--------------------------------------------------
#ifndef _HDMI_FROM_DVI_CONNECT
#define _HDMI_FROM_DVI_CONNECT                                  _OFF
#endif

//--------------------------------------------------
// TMDS Z0 Optioin
//--------------------------------------------------
#ifndef _TMDS_Z0_POWER_SAVING_OPTION
#define _TMDS_Z0_POWER_SAVING_OPTION                            _ALL_CHANNEL_CONNECTED_FOR_CTS
#endif

//--------------------------------------------------
// High Charge Pump Current for 25MHz --> only effected in RL6096
//--------------------------------------------------
#ifndef _TMDS_25M_HIGH_CHARGE_PUMP_CURRENT
#define _TMDS_25M_HIGH_CHARGE_PUMP_CURRENT                      _OFF
#endif

//--------------------------------------------------
// TMDS Toggle Z0 When Waking Up from Power Saving --> for Acer Spec
//--------------------------------------------------
#ifndef _TMDS_TOGGLE_Z0_AFTER_WAKING_UP
#define _TMDS_TOGGLE_Z0_AFTER_WAKING_UP                         _OFF
#endif

//--------------------------------------------------
// DP Options  
//--------------------------------------------------
#ifndef _DP_ASSR_MODE_SUPPORT
#define _DP_ASSR_MODE_SUPPORT                                   _OFF

#elif(_SCALER_TYPE == _RL6001_SERIES)
#undef _DP_ASSR_MODE_SUPPORT
#define _DP_ASSR_MODE_SUPPORT                                   _OFF
#endif

#ifndef _DP_DELL_D3_TEST_SUPPORT                                    
#define _DP_DELL_D3_TEST_SUPPORT                                _OFF
#endif

#ifndef _DP_DCOFF_HPD_FORCE_HIGH              
#define _DP_DCOFF_HPD_FORCE_HIGH                                _OFF
#endif

//--------------------------------------------------
// MHL Packed Pixel Mode Support
//--------------------------------------------------
#ifndef _MHL_CBUS_CTS_MODE
#define _MHL_CBUS_CTS_MODE                                      _OFF
#endif

#if(_MHL_CBUS_CTS_MODE == _ON)
#warning "MHL CBUS CTS Mode is Enabled!! Only Used for CTS!!!"
#endif

#ifndef _MHL_PP_MODE_SUPPORT
#define _MHL_PP_MODE_SUPPORT                                    _ON
#endif

//-------------------------------------------------
// HDCP Key Options
//-------------------------------------------------
#ifndef _WRITE_HDCP_TO_SYSTEM_EEPROM
#define _WRITE_HDCP_TO_SYSTEM_EEPROM                            _OFF
#endif

#ifndef _HDCP_KEY_LOCATION
#define _HDCP_KEY_LOCATION                                      _TABLE_LOCATION_SYSTEM_EEPROM
#endif

//--------------------------------------------------
// Aspect Ratio Define Protection
//--------------------------------------------------
#if((_ASPECT_ORIGINAL_MODE_SUPPORT == _ON) && (_ASPECT_RATIO_SUPPORT == _OFF))
#undef _ASPECT_RATIO_SUPPORT
#define _ASPECT_RATIO_SUPPORT                                   _ON
#endif

//--------------------------------------------------
// 3D Define Protection
//--------------------------------------------------
#if((_2D_TO_3D_FUNCTION == _ON) && (_3D_SUPPORT == _OFF))
#undef _3D_SUPPORT
#define _3D_SUPPORT                                             _ON
#endif

//--------------------------------------------------
// EEPROM Access Function Define Protection
//--------------------------------------------------
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
#undef _EEPROM_ACCESS_FUNCTION_SUPPORT
#define _EEPROM_ACCESS_FUNCTION_SUPPORT                         _ON
#endif

//--------------------------------------------------
// Flash Access Function Define Protection
//--------------------------------------------------
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
#undef _FLASH_ACCESS_FUNCTION_SUPPORT
#define _FLASH_ACCESS_FUNCTION_SUPPORT                          _ON
#endif

//-------------------------------------------------
// System Timer 250us Option(For IR Application)
// Add ?PR?USERINTERFACETIMER2INSTANTACCESS_TIMER2?RTD2011USERINTERFACE
// To Link File Bank 0 In Order to Increase Efficiency
//-------------------------------------------------
#ifndef _SYSTEM_TIMER_QUARTER_RESOLUTION
#define _SYSTEM_TIMER_QUARTER_RESOLUTION                        _OFF
#endif

//--------------------------------------------------
// OSD Position Align Option
//--------------------------------------------------
#ifndef _OSD_POSITION_SELF_ALIGNMENT
#define _OSD_POSITION_SELF_ALIGNMENT                            _OFF
#endif

//--------------------------------------------------
// DDCCI Auto Switch Option
//--------------------------------------------------
#if((_SCALER_TYPE == _RL6001_SERIES) || (_SCALER_TYPE == _RL6192_SERIES) || (_SCALER_TYPE == _RL6096_SERIES) || \
    (_SCALER_TYPE == _RL6213_SERIES) || (_SCALER_TYPE == _RL6230_SERIES) || (_SCALER_TYPE == _RL6316_SERIES) || \
    (_SCALER_TYPE == _RL6373_SERIES))
#undef _DDCCI_AUTO_SWITCH_SUPPORT
#define _DDCCI_AUTO_SWITCH_SUPPORT                             _OFF
#else

#ifndef _DDCCI_AUTO_SWITCH_SUPPORT
#define _DDCCI_AUTO_SWITCH_SUPPORT                             _OFF
#endif

#endif                               

//-------------------------------------------------
// Definitions of Required Default Search Time for all Port
//-------------------------------------------------
#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)
#ifndef _SOURCE_DEFAULT_SEARCH_TIME_ALL_PORT                        
#define _SOURCE_DEFAULT_SEARCH_TIME_ALL_PORT                   SEC(2)    
#endif
#endif

//--------------------------------------------------
// Double Check NVRAM Port When Searching In Polling Mode
//--------------------------------------------------
#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
#undef _SOURCE_DOUBLE_CHECK_NVRAM_PORT_SUPPORT                 
#define _SOURCE_DOUBLE_CHECK_NVRAM_PORT_SUPPORT                _OFF 
#else

#ifndef _SOURCE_DOUBLE_CHECK_NVRAM_PORT_SUPPORT
#define _SOURCE_DOUBLE_CHECK_NVRAM_PORT_SUPPORT                _OFF
#endif

#if(_SOURCE_DOUBLE_CHECK_NVRAM_PORT_SUPPORT == _ON)
#ifndef _SOURCE_DOUBLE_CHECK_SEARCH_TIME_NVRAM_PORT
#define _SOURCE_DOUBLE_CHECK_SEARCH_TIME_NVRAM_PORT            SEC(0.5)
#endif
#endif

#endif

//--------------------------------------------------
// Definitions of Digital Filter Coefficients for High Frequency Phase
//--------------------------------------------------
#ifndef _DIG_FILTER_PHASE_HIGHFREQ_ADCCLOCKTHD
#define _DIG_FILTER_PHASE_HIGHFREQ_ADCCLOCKTHD                   0 // effective:0~210 (MHz)
#else

#ifndef _DIG_FILTER_PHASE_HIGHFREQ_THD 
#if((_SCALER_TYPE == _RL6001_SERIES) || (_SCALER_TYPE == _RL6096_SERIES) || (_SCALER_TYPE == _RL6192_SERIES) || \
    (_SCALER_TYPE == _RL6213_SERIES) || (_SCALER_TYPE == _RL6229_SERIES) || (_SCALER_TYPE == _RL6230_SERIES))
#define _DIG_FILTER_PHASE_HIGHFREQ_THD                           3   // effective:0~7
#elif((_SCALER_TYPE == _RL6297_SERIES) || (_SCALER_TYPE == _RL6269_SERIES) || (_SCALER_TYPE == _RL6316_SERIES) || \
      (_SCALER_TYPE == _RL6336_SERIES) || (_SCALER_TYPE == _RL6373_SERIES))
#define _DIG_FILTER_PHASE_HIGHFREQ_THD                           160 // effective:0~255
#endif
#endif

#ifndef _DIG_FILTER_PHASE_HIGHFREQ_DIV_VALUE
#define _DIG_FILTER_PHASE_HIGHFREQ_DIV_VALUE                     0   // effective:0~3
#endif

#endif

//--------------------------------------------------
// Definitions of Display Garbage Prevent Method
//--------------------------------------------------
#ifndef _DISPLAY_PREVENT_GARBAGE_METHOD
#define _DISPLAY_PREVENT_GARBAGE_METHOD                         _GARBAGE_PREVENT_BY_WATCH_DOG
#endif

//--------------------------------------------------
// UART Support
//--------------------------------------------------
#ifndef _UART_SUPPORT
#define _UART_SUPPORT                                           _OFF
#define _UART_BAUD_RATE_POWER_NORMAL                            9600 // 5000 ~ 200000Baud (Unit in Baud)
#define _UART_BAUD_RATE_POWER_SAVING                            9600 // 1000 ~ 60000Baud (Unit in Baud)
#endif

//--------------------------------------------------
// Definitions of Super Low Power
//--------------------------------------------------
#ifndef _SUPER_LOW_POWER_SUPPORT
#define _SUPER_LOW_POWER_SUPPORT                                _OFF
#endif

//--------------------------------------------------
// Definitions of LC Tank
//--------------------------------------------------
#if(_SCALER_TYPE == _RL6373_SERIES)
#define _LC_TANK_SUPPORT                                        _ON
#else
#define _LC_TANK_SUPPORT                                        _OFF
#endif

//--------------------------------------------------
// Definitions of Effuse Support
//--------------------------------------------------
#if((_SCALER_TYPE == _RL6269_SERIES) || (_SCALER_TYPE == _RL6316_SERIES) || (_SCALER_TYPE == _RL6373_SERIES))
#define _EFFUSE_FUNCTION_SUPPORT                                _ON
#else
#define _EFFUSE_FUNCTION_SUPPORT                                _OFF
#endif

//--------------------------------------------------
// QC Define
//--------------------------------------------------
// Must Specify QC Code Bank in Keil C BL51 Misc By Adding ?CO?RL6xxx_SERIES_QC to BANK3
// For RL6229, Add ?CO?RL6229_SERIES_QC_OSD to BANK2
// Must Remove ?CO?SCALERCOLOR from Bank 1
// Must Use _NONE_OSD
// Must Use _AU_LVDS_22_WSXGA_QC as Panel Type
#define _FACTORY_RTD_QC_SUPPORT                     _OFF

// Turn unnecessary function off for QC
#if(_FACTORY_RTD_QC_SUPPORT == _ON)
#undef _SDRAM_PHASE_CALIBRATION
#define _SDRAM_PHASE_CALIBRATION                    _OFF 

#undef _I_DITHER_SUPPORT
#define _I_DITHER_SUPPORT                           _OFF

#undef _D_DITHER_SUPPORT
#define _D_DITHER_SUPPORT                           _OFF

#undef _GAMMA_FUNCTION
#define _GAMMA_FUNCTION                             _OFF

#undef _PCM_FUNCTION
#define _PCM_FUNCTION                               _OFF

#undef _COLOR_FORMAT_CONVERT
#define _COLOR_FORMAT_CONVERT                       _OFF

#undef _ULTRA_VIVID_SUPPORT
#define _ULTRA_VIVID_SUPPORT                        _OFF

#undef _DCR_SUPPORT
#define _DCR_SUPPORT                                _OFF

#undef _DCC_HISTOGRM_INFO
#define _DCC_HISTOGRM_INFO                          _OFF

#undef _DCC_FUNCTION
#define _DCC_FUNCTION                               _OFF

#undef _ICM_SUPPORT
#define _ICM_SUPPORT                                _OFF

#undef _HIGHLIGHT_WINDOW_SUPPORT
#define _HIGHLIGHT_WINDOW_SUPPORT                   _OFF

#undef _SIX_COLOR_SUPPORT
#define _SIX_COLOR_SUPPORT                          _OFF

#undef _DIG_FILTER_ENHANCE_PHASE_ENABLE
#define _DIG_FILTER_ENHANCE_PHASE_ENABLE            _DISABLE

#undef _RINGING_FILTER_SUPPORT
#define _RINGING_FILTER_SUPPORT                     _OFF

#undef _GLOBAL_HUE_SATURATION
#define _GLOBAL_HUE_SATURATION                      _OFF

#undef _OGC_SUPPORT
#define _OGC_SUPPORT                                _OFF

#undef _OCC_SUPPORT
#define _OCC_SUPPORT                                _OFF

#undef _OGC_DICOM_SUPPORT
#define _OGC_DICOM_SUPPORT                          _OFF

#undef _FLASH_ACCESS_FUNCTION_SUPPORT
#define _FLASH_ACCESS_FUNCTION_SUPPORT              _OFF

#undef _ENERGY_STAR_SUPPORT
#define _ENERGY_STAR_SUPPORT                        _OFF

#undef _3D_SUPPORT
#define _3D_SUPPORT                                 _OFF

#undef _2D_TO_3D_FUNCTION
#define _2D_TO_3D_FUNCTION                          _OFF

#undef _ASPECT_ORIGINAL_MODE_SUPPORT
#define _ASPECT_ORIGINAL_MODE_SUPPORT               _OFF

#undef _INSTANT_TIMER_EVENT_0
#define _INSTANT_TIMER_EVENT_0                      _OFF

#undef _INSTANT_TIMER_EVENT_1
#define _INSTANT_TIMER_EVENT_1                      _OFF
#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)

