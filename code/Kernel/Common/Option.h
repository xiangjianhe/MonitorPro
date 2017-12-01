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
// ID Code      : Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// General Definitions
//****************************************************************************
//--------------------------------------------------
// DDC Channel Select
//--------------------------------------------------
#define _DEBUG_DDC_CHANNEL_SEL                      _DDC1

//--------------------------------------------------
// Debug Message Supported
//--------------------------------------------------
#define _DEBUG_MESSAGE_ANALOG                       _OFF
#define _DEBUG_MESSAGE_DIGITAL                      _OFF
#define _DEBUG_MESSAGE_SCALER                       _OFF
#define _DEBUG_MESSAGE_SYSTEM                       _OFF
#define _DEBUG_MESSAGE_AUDIO                        _OFF
#define _DEBUG_MESSAGE_FRC                          _OFF
#define _DEBUG_MESSAGE_OSD                          _OFF
#define _DEBUG_MESSAGE_FRAME_SYNC                   _OFF
#define _DEBUG_MESSAGE_SDRAM                        _OFF

#if(_DEBUG_MESSAGE_ANALOG == _ON)
#define DebugMessageAnalog(x, y)                    ScalerDebugMessage((x), (y))
#else
#define DebugMessageAnalog(x, y)                    ;
#endif

#if(_DEBUG_MESSAGE_DIGITAL == _ON)
#define DebugMessageDigital(x, y)                   ScalerDebugMessage((x), (y))
#else
#define DebugMessageDigital(x, y)                   ;
#endif

#if(_DEBUG_MESSAGE_SCALER == _ON)
#define DebugMessageScaler(x, y)                    ScalerDebugMessage((x), (y))
#else
#define DebugMessageScaler(x, y)                    ;
#endif

#if(_DEBUG_MESSAGE_SYSTEM == _ON)
#define DebugMessageSystem(x, y)                    ScalerDebugMessage((x), (y))
#else
#define DebugMessageSystem(x, y)                    ;
#endif

#if(_DEBUG_MESSAGE_AUDIO == _ON)
#define DebugMessageAudio(x, y)                     ScalerDebugMessage((x), (y))
#else
#define DebugMessageAudio(x, y)                     ;
#endif

#if(_DEBUG_MESSAGE_FRC == _ON)
#define DebugMessageFRC(x, y)                        ScalerDebugMessage((x), (y))
#else
#define DebugMessageFRC(x, y)                        ;
#endif

#if(_DEBUG_MESSAGE_OSD == _ON)
#define DebugMessageOsd(x, y)                       ScalerDebugMessage((x), (y))
#else
#define DebugMessageOsd(x, y)                       ;
#endif

#if(_DEBUG_MESSAGE_FRAME_SYNC == _ON)
#define DebugMessageFS(x, y)                        ScalerDebugMessage((x), (y))
#else
#define DebugMessageFS(x, y)                        ;
#endif

#if(_DEBUG_MESSAGE_SDRAM == _ON)
#define DebugMessageSDRAM(x, y)                    ScalerDebugMessage((x), (y))
#else
#define DebugMessageSDRAM(x, y)                    ;
#endif

#if((_DEBUG_MESSAGE_ANALOG == _ON) || (_DEBUG_MESSAGE_DIGITAL == _ON) || (_DEBUG_MESSAGE_SCALER == _ON) || \
    (_DEBUG_MESSAGE_SYSTEM == _ON) || (_DEBUG_MESSAGE_AUDIO == _ON) || (_DEBUG_MESSAGE_FRC == _ON) || \
    (_DEBUG_MESSAGE_OSD == _ON) || (_DEBUG_MESSAGE_FRAME_SYNC == _ON) || (_DEBUG_MESSAGE_SDRAM == _ON))
#define _DEBUG_MESSAGE_SUPPORT                      _ON
#else
#define _DEBUG_MESSAGE_SUPPORT                      _OFF
#endif

//--------------------------------------------------
// Auto Define for Input Valid Port
//--------------------------------------------------
#define _INPUT_PORT_VALID                           ((_A0_INPUT_PORT_TYPE != _A0_NO_PORT) + (_D0_INPUT_PORT_TYPE != _D0_NO_PORT) + (_D1_INPUT_PORT_TYPE != _D1_NO_PORT) + (_D2_INPUT_PORT_TYPE != _D2_NO_PORT) + (_D3_INPUT_PORT_TYPE != _D3_NO_PORT))

//--------------------------------------------------
// Auto Define for Interface Support
//--------------------------------------------------
#if(_A0_INPUT_PORT_TYPE == _A0_VGA_PORT)
#define _VGA_PORT_EXIST                             _ON
#else
#define _VGA_PORT_EXIST                             _OFF
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || \
    (_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DVI_PORT))
#define _DVI_PORT_EXIST                             _ON
#else
#define _DVI_PORT_EXIST                             _OFF
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || \
    (_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || \
    (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT) || \
    (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT))
#define _HDMI_PORT_EXIST                            _ON
#else
#define _HDMI_PORT_EXIST                            _OFF
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_PORT) || \
    (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT))
#define _DP_PORT_EXIST                              _ON
#else
#define _DP_PORT_EXIST                              _OFF
#endif

#if((_DVI_PORT_EXIST == _ON) || (_HDMI_PORT_EXIST == _ON))
#define _DVI_SUPPORT                                _ON
#else
#define _DVI_SUPPORT                                _OFF
#endif

#if((_HDMI_PORT_EXIST == _ON) || ((_DVI_SUPPORT == _ON) && (_HDMI_FROM_DVI_CONNECT == _ON)) || \
    (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT))
#define _HDMI_SUPPORT                               _ON
#else
#define _HDMI_SUPPORT                               _OFF
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
#define _MHL_SUPPORT                                _ON
#else
#define _MHL_SUPPORT                                _OFF
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT)
#define _DP_DUAL_MODE_SUPPORT                       _ON
#else
#define _DP_DUAL_MODE_SUPPORT                       _OFF
#endif

#if(_DP_PORT_EXIST == _ON)
#define _DP_SUPPORT                                 _ON
#define _LOW_POWER_GDI_ISOLATION                    _OFF
#else
#define _DP_SUPPORT                                 _OFF

#if(_MHL_SUPPORT == _ON)
#define _LOW_POWER_GDI_ISOLATION                    _OFF
#else
#define _LOW_POWER_GDI_ISOLATION                    _ON
#endif

#endif

#if(_VGA_PORT_EXIST == _ON)
#define _VGA_SUPPORT                                _ON
#else
#define _VGA_SUPPORT                                _OFF

#undef _YPBPR_SUPPORT
#define _YPBPR_SUPPORT                              _OFF
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON) || (_DP_SUPPORT == _ON))
#define _DIGITAL_PORT_SUPPORT                       _ON
#else
#define _DIGITAL_PORT_SUPPORT                       _OFF
#endif

#if((_OVERSCAN_VGA_SUPPORT == _ON) || (_OVERSCAN_DVI_SUPPORT == _ON) || (_OVERSCAN_HDMI_SUPPORT == _ON) || (_OVERSCAN_DP_SUPPORT == _ON))
#define _OVERSCAN_SUPPORT                           _ON
#else
#define _OVERSCAN_SUPPORT                           _OFF
#endif

#if((_OD_SUPPORT == _ON) && (_ASPECT_ORIGINAL_MODE_SUPPORT == _ON))
#define _HIGHLIGHT_WINDOW_SUPPORT_FOR_OD            _ON
#else
#define _HIGHLIGHT_WINDOW_SUPPORT_FOR_OD            _OFF
#endif

//--------------------------------------------------
// Select DP Aux Channel DDC
//--------------------------------------------------
#if(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC2)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC2)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3)))

#define _AUX_DDC_CHANNEL                            _AUX_MAP_DDC2_PIN

#elif(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC3)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC3)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2)))

#define _AUX_DDC_CHANNEL                            _AUX_MAP_DDC3_PIN

#else

#define _AUX_DDC_CHANNEL                            _NO_AUX

#endif        

//--------------------------------------------------
// IOSC Options for DP
//--------------------------------------------------
#if((_DP_SUPPORT == _ON) || (_MHL_SUPPORT))
#define _INTERNAL_OSC_XTAL                          _IOSC27000K
#else
#define _INTERNAL_OSC_XTAL                          _IOSC14318K
#endif

//--------------------------------------------------
// Debug Option For MHL
//--------------------------------------------------
// If _MHL_DEBUG_WITHOUT_CBUS_MODE is supported
// MHL connection can be stablished without CBUS communication
#define _MHL_DEBUG_WITHOUT_CBUS_MODE                _OFF

//--------------------------------------------------
// ADC Sampling Limitation
//--------------------------------------------------
#define _ADC_SAMPLE_CLOCK_LIMIT                     2100000

//--------------------------------------------------
// ADC Limit Out Of Range
//--------------------------------------------------
#define _PIXEL_WIDTH_LIMIT                          3200

//--------------------------------------------------
// Enumerations of Timer Events
//--------------------------------------------------
typedef enum
{
    _SYSTEM_TIMER_EVENT_START = _USER_TIMER_EVENT_COUNT,
    _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING = _SYSTEM_TIMER_EVENT_START,
    _SYSTEM_TIMER_EVENT_SOURCE_HP_CANCEL_MANUAL_SWITCH_PORT,
    _SYSTEM_TIMER_EVENT_SOURCE_ASUS_START_AUTO,
    _SYSTEM_TIMER_EVENT_JUDGE_ACTIVE_STATE,
    _SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE,
    _SYSTEM_TIMER_EVENT_JUDGE_NOSIGNAL_STATE,    
    _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_INITIAL,
    _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_CHARGE,
    _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL,    
    _SYSTEM_TIMER_EVENT_END,
    _SYSTEM_TIMER_EVENT_COUNT,
} EnumSystemTimerEventID;

#if((_HP_SOURCE_SCAN_SUPPORT == _ON) || (_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ASUS_STYLE))
#define _SIMULTANEOUS_SYSTEM_EVENT_COUNT            4
#else
#define _SIMULTANEOUS_SYSTEM_EVENT_COUNT            3
#endif

typedef enum
{
    _SCALER_TIMER_EVENT_START = _SYSTEM_TIMER_EVENT_COUNT,
    _SCALER_TIMER_EVENT_TMDS_HDMI_PACKET_DETECT = _SCALER_TIMER_EVENT_START, 
    _SCALER_TIMER_EVENT_TMDS_VIDEO_DETECT,  
    _SCALER_TIMER_EVENT_AUDIO_LOAD_STABLE_I_CODE,
    _SCALER_TIMER_EVENT_DP_HOTPLUG_ASSERTED,
    _SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT,
    _SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ,    
    _SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH,
    _SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH,  
    _SCALER_TIMER_EVENT_NR_DETECTION_FINISHED,  
    _SCALER_TIMER_EVENT_PHASE_CALIBRATION,    
    _SCALER_TIMER_EVENT_PHASE_CNT_CHECK,
    _SCALER_TIMER_EVENT_MHL_D0_READY_TO_TRANSMIT,
    _SCALER_TIMER_EVENT_MHL_D0_RECONNECT_1K,
    _SCALER_TIMER_EVENT_MHL_D0_ACTIVE_VBUS,
    _SCALER_TIMER_EVENT_MHL_D1_READY_TO_TRANSMIT,
    _SCALER_TIMER_EVENT_MHL_D1_RECONNECT_1K,
    _SCALER_TIMER_EVENT_MHL_D1_ACTIVE_VBUS,
    _SCALER_TIMER_EVENT_DCC_HISTOGRAM_THD_CHANGE,
    _SCALER_TIMER_EVENT_END,
    _SCALER_TIMER_EVENT_COUNT = _SCALER_TIMER_EVENT_END,
} EnumScalerTimerEventID;

#define _SIMULTANEOUS_SCALER_EVENT_COUNT            (5 + (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) + (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))

#define _TIMER_EVENT_COUNT                          (_SIMULTANEOUS_USER_EVENT_COUNT + _SIMULTANEOUS_SYSTEM_EVENT_COUNT + _SIMULTANEOUS_SCALER_EVENT_COUNT)

//--------------------------------------------------
// Enumerations of Flash / MCU Speed
//--------------------------------------------------
typedef enum
{
#if(_FLASH_CLK_SPEED == _FLASH_FAST_SPEED)
    _FLASH_CLK_DIV = _DIV_5,
#elif(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
    _FLASH_CLK_DIV = _DIV_10,
    _FLASH_CLK_FAST_DIV = _DIV_5,
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
    _FLASH_CLK_PS_DIV = _DIV_1,
#else

#if(_INTERNAL_OSC_XTAL == _IOSC27000K)
    _FLASH_CLK_PS_DIV = _DIV_4,
#else
    _FLASH_CLK_PS_DIV = _DIV_2,
#endif

#endif

    _FLASH_CLK_IN_DIV = _DIV_1,
    _FLASH_CLK_PS_FAST_DIV = _DIV_1, // for DP 
} EnumFlashClkDiv;

typedef enum
{
#if(_FLASH_CLK_SPEED == _FLASH_FAST_SPEED)
    _MCU_CLK_DIV = _DIV_2,
#elif(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
    _MCU_CLK_DIV = _DIV_1,
    _MCU_CLK_FAST_DIV = _DIV_2,
#endif

    _MCU_CLK_PS_DIV = _DIV_2,

    _MCU_CLK_IN_DIV = _DIV_1,
} EnumMcuClkDiv;
