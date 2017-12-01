/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : ScalerSyncInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Define for SPD Packet Type
//--------------------------------------------------
#if(_FREESYNC_SUPPORT == _ON)
#define _SPD_INFO_TYPE                              0x83
#endif

//--------------------------------------------------
// Definitions of Hsync Type Detection Auto Run Result
//--------------------------------------------------
#define _NO_SIGNAL                                  0
#define _NOT_SUPPORT                                1
#define _YPBPR_SYNC                                 2
#define _SERRATION_CS                               3
#define _XOR_OR_TYPE_CS_WITH_EQR                    4
#define _XOR_OR_TYPE_CS_WITHOUT_EQR                 5
#define _SEPARATE_HSYNC                             6
#define _HSYNC_WITHOUT_VS                           7

//--------------------------------------------------
// Definitions of V-Sync width & total limitations
//--------------------------------------------------
#define _MAX_VSYNC_TOTAL                            (1646 * 1.1)  // 2560x1600@60 + 10%
#define _MIN_VSYNC_TOTAL                            (262 * 0.9)   // 1440x480i - 10%
#define _MAX_VSYNC_HIGH_PERIOD                      12 // Unit capture window

//--------------------------------------------------
// Definitions of DP Link Training Stage
//--------------------------------------------------
#define _DP_TRAINING_PATTERN_END                    0
#define _DP_TRAINING_PATTERN_1                      1  
#define _DP_TRAINING_PATTERN_2                      2

//--------------------------------------------------
// Definitions of DP Link Traiinng Status
//--------------------------------------------------
#define _DP_LINK_TRAINING_NONE                      0
#define _DP_NORMAL_TRAINING_PATTERN_1_PASS          1
#define _DP_NORMAL_TRAINING_PATTERN_1_FAIL          2
#define _DP_FAKE_TRAINING_PATTERN_1_PASS            3
#define _DP_FAKE_TRAINING_PATTERN_1_FAIL            4
#define _DP_NORMAL_TRAINING_PATTERN_2_PASS          5
#define _DP_NORMAL_TRAINING_PATTERN_2_FAIL          6
#define _DP_FAKE_TRAINING_PATTERN_2_PASS            7
#define _DP_FAKE_TRAINING_PATTERN_2_FAIL            8
#define _DP_NORMAL_LINK_TRAINING_PASS               9
#define _DP_FAKE_LINK_TRAINING_PASS                 10
#define _DP_LINK_TRAINING_FAIL                      11
#define _DP_LINK_STATUS_FAIL                        12

//--------------------------------------------------
// Definitions of MHL Status
//--------------------------------------------------
#define _MHL_STATE_INITIAL                          0
#define _MHL_STATE_WAKE_UP_DONE                     1
#define _MHL_STATE_DISCOVERY_DONE                   2
#define _MHL_STATE_DEV_CAP_RDY                      3
#define _MHL_STATE_HPD_DONE                         4
#define _MHL_STATE_PATH_EN_DONE                     5
#define _MHL_STATE_DONE                             6

//--------------------------------------------------
// Definitions of MHL Port Valid
//--------------------------------------------------
#define _MHL_PORT_VALID                             ((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) + (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))

//--------------------------------------------------
// Macro of Input Pixel Clk (Unit in 0.1MHz)
//--------------------------------------------------
#define GET_INPUT_PIXEL_CLK()                        (g_usInputPixelClk)
#define SET_INPUT_PIXEL_CLK(x)                       (g_usInputPixelClk = x)
#define CLR_INPUT_PIXEL_CLK()                        (g_usInputPixelClk = 0)

#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Macro of Digital Input Port Switch
//--------------------------------------------------
#define GET_D0_PORT_DIGITAL_SWITCH()                 ((g_ucDigitalSwitch & _BIT7) >> 7)
#define SET_D0_PORT_DIGITAL_SWITCH()                 (g_ucDigitalSwitch |= _BIT7)
#define CLR_D0_PORT_DIGITAL_SWITCH()                 (g_ucDigitalSwitch &= ~_BIT7)

#define GET_D1_PORT_DIGITAL_SWITCH()                 ((g_ucDigitalSwitch & _BIT6) >> 6)
#define SET_D1_PORT_DIGITAL_SWITCH()                 (g_ucDigitalSwitch |= _BIT6)
#define CLR_D1_PORT_DIGITAL_SWITCH()                 (g_ucDigitalSwitch &= ~_BIT6)

#define GET_DIGITAL_PORT_SWITCH_TO_D0()              ((g_ucDigitalSwitch & _BIT5) >> 5)
#define SET_DIGITAL_PORT_SWITCH_TO_D0()              (g_ucDigitalSwitch |= _BIT5)
#define CLR_DIGITAL_PORT_SWITCH_TO_D0()              (g_ucDigitalSwitch &= ~_BIT5)

#define GET_DIGITAL_PORT_SWITCH_TO_D1()              ((g_ucDigitalSwitch & _BIT4) >> 4)
#define SET_DIGITAL_PORT_SWITCH_TO_D1()              (g_ucDigitalSwitch |= _BIT4)
#define CLR_DIGITAL_PORT_SWITCH_TO_D1()              (g_ucDigitalSwitch &= ~_BIT4)

#define GET_DIGITAL_PORT_SWITCH_TO_D2()              ((g_ucDigitalSwitch & _BIT3) >> 3)
#define SET_DIGITAL_PORT_SWITCH_TO_D2()              (g_ucDigitalSwitch |= _BIT3)
#define CLR_DIGITAL_PORT_SWITCH_TO_D2()              (g_ucDigitalSwitch &= ~_BIT3)

#define GET_DIGITAL_PORT_SWITCH_TO_D3()              ((g_ucDigitalSwitch & _BIT2) >> 2)
#define SET_DIGITAL_PORT_SWITCH_TO_D3()              (g_ucDigitalSwitch |= _BIT2)
#define CLR_DIGITAL_PORT_SWITCH_TO_D3()              (g_ucDigitalSwitch &= ~_BIT2)

#define GET_HDMI_HOTPLUG_TOGGLE()                    ((g_ucHDMIHotPlug & _BIT7) >> 7)
#define SET_HDMI_HOTPLUG_TOGGLE()                    (g_ucHDMIHotPlug |= _BIT7)
#define CLR_HDMI_HOTPLUG_TOGGLE()                    (g_ucHDMIHotPlug &= ~_BIT7)

#define GET_HDMI_HOTPLUG_TIME()                      ((WORD)(g_ucHDMIHotPlug & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) * 100)
#define SET_HDMI_HOTPLUG_TIME(x)                     (g_ucHDMIHotPlug = (g_ucHDMIHotPlug & ~(_BIT3 | _BIT2 | _BIT1 | _BIT0)) | (x))
#endif

#if(_TMDS_TOGGLE_Z0_AFTER_WAKING_UP == _ON)
#define GET_TMDS_D0_TOGGLE_Z0()                      (g_bTmdsD0Z0Toggle)
#define SET_TMDS_D0_TOGGLE_Z0()                      (g_bTmdsD0Z0Toggle = _TRUE)
#define CLR_TMDS_D0_TOGGLE_Z0()                      (g_bTmdsD0Z0Toggle = _FALSE)

#define GET_TMDS_D1_TOGGLE_Z0()                      (g_bTmdsD1Z0Toggle)
#define SET_TMDS_D1_TOGGLE_Z0()                      (g_bTmdsD1Z0Toggle = _TRUE)
#define CLR_TMDS_D1_TOGGLE_Z0()                      (g_bTmdsD1Z0Toggle = _FALSE)

#define GET_TMDS_TOGGLE_Z0_EVENT()                   (g_bTmdsGlobalZ0Toggle)
#define SET_TMDS_TOGGLE_Z0_EVENT()                   (g_bTmdsGlobalZ0Toggle = _TRUE)
#define CLR_TMDS_TOGGLE_Z0_EVENT()                   (g_bTmdsGlobalZ0Toggle = _FALSE)
#endif

#if(_MHL_SUPPORT == _ON)
#define GET_MHL_PROCESS_STATE(x)                     (g_stMHLProcess[x].b3MHLProcessState)
#define SET_MHL_PROCESS_STATE(x, y)                  (g_stMHLProcess[x].b3MHLProcessState = (y))

#define GET_MHL_READY_TO_TRANSMIT(x)                 (g_stMHLProcess[x].b1MHLTransmitStatus)
#define SET_MHL_READY_TO_TRANSMIT(x, y)              (g_stMHLProcess[x].b1MHLTransmitStatus = (y))

#define GET_MHL_READY_TO_RESEND(x)                   (g_stMHLProcess[x].b1MHLResendStatus)
#define SET_MHL_READY_TO_RESEND(x, y)                (g_stMHLProcess[x].b1MHLResendStatus = (y))

#define GET_MHL_PORT_ACTIVE()                        (g_bMHLPortActive)
#define SET_MHL_PORT_ACTIVE(x)                       (g_bMHLPortActive = (x))
#endif

#if(_FREESYNC_SUPPORT == _ON)
#if((_DP_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON))
#define GET_FREESYNC_ENABLED()                              ((bit)(GET_DP_FREESYNC_ENABLED() | GET_HDMI_FREESYNC_ENABLED()))
#define CLR_FREESYNC_ENABLED()                              {\
                                                                CLR_DP_FREESYNC_ENABLED();\
                                                                CLR_HDMI_FREESYNC_ENABLED();\
                                                            }
#elif(_DP_FREESYNC_SUPPORT == _ON)
#define GET_FREESYNC_ENABLED()                              (GET_DP_FREESYNC_ENABLED())
#define CLR_FREESYNC_ENABLED()                              {\
                                                                CLR_DP_FREESYNC_ENABLED();\
                                                            }
#else
#define GET_FREESYNC_ENABLED()                              (GET_HDMI_FREESYNC_ENABLED())
#define CLR_FREESYNC_ENABLED()                              {\
                                                                CLR_HDMI_FREESYNC_ENABLED();\
                                                            }
#endif

#define GET_FREESYNC_SUPPORT()                              (g_ucFREESYNCSupport)
#define SET_FREESYNC_SUPPORT(x)                             (g_ucFREESYNCSupport = (bit)(x))

#if(_HDMI_FREESYNC_SUPPORT == _ON)
#define GET_HDMI_FREESYNC_ENABLED()                         (g_stHDMIFREESYNCInfo.b1HDMIFREESYNCEnable)
#define SET_HDMI_FREESYNC_ENABLED()                         (g_stHDMIFREESYNCInfo.b1HDMIFREESYNCEnable = _ENABLE)
#define CLR_HDMI_FREESYNC_ENABLED()                         (g_stHDMIFREESYNCInfo.b1HDMIFREESYNCEnable = _DISABLE)

#if(_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE)
#define GET_HDMI_FREESYNC_VCP()                             (g_ucHDMIFREESYNCVCPReceive)
#endif

#define GET_TMDS_RX0_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX0SPDInfoFrameReceived)
#define SET_TMDS_RX0_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX0SPDInfoFrameReceived = _TRUE)
#define CLR_TMDS_RX0_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX0SPDInfoFrameReceived = _FALSE)

#define GET_TMDS_RX1_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX1SPDInfoFrameReceived)
#define SET_TMDS_RX1_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX1SPDInfoFrameReceived = _TRUE)
#define CLR_TMDS_RX1_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX1SPDInfoFrameReceived = _FALSE)

#define GET_TMDS_RX2_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX2SPDInfoFrameReceived)
#define SET_TMDS_RX2_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX2SPDInfoFrameReceived = _TRUE)
#define CLR_TMDS_RX2_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX2SPDInfoFrameReceived = _FALSE)

#define GET_TMDS_RX3_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX3SPDInfoFrameReceived)
#define SET_TMDS_RX3_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX3SPDInfoFrameReceived = _TRUE)
#define CLR_TMDS_RX3_SPD_INFO_FRAME_RECEIVED()              (g_stHDMIFREESYNCInfo.b1HDMIRX3SPDInfoFrameReceived = _FALSE)

#define GET_TMDS_RX0_FREESYNC_SUPPORT()                     (g_stHDMIFREESYNCInfo.b1HDMIRX0FREESYNCSupport)
#define SET_TMDS_RX0_FREESYNC_SUPPORT(x)                    (g_stHDMIFREESYNCInfo.b1HDMIRX0FREESYNCSupport = (x))
#define CLR_TMDS_RX0_FREESYNC_SUPPORT()                     (g_stHDMIFREESYNCInfo.b1HDMIRX0FREESYNCSupport = _FALSE)

#define GET_TMDS_RX1_FREESYNC_SUPPORT()                     (g_stHDMIFREESYNCInfo.b1HDMIRX1FREESYNCSupport)
#define SET_TMDS_RX1_FREESYNC_SUPPORT(x)                    (g_stHDMIFREESYNCInfo.b1HDMIRX1FREESYNCSupport = (x))
#define CLR_TMDS_RX1_FREESYNC_SUPPORT()                     (g_stHDMIFREESYNCInfo.b1HDMIRX1FREESYNCSupport = _FALSE)

#define GET_TMDS_RX2_FREESYNC_SUPPORT()                     (g_stHDMIFREESYNCInfo.b1HDMIRX2FREESYNCSupport)
#define SET_TMDS_RX2_FREESYNC_SUPPORT(x)                    (g_stHDMIFREESYNCInfo.b1HDMIRX2FREESYNCSupport = (x))
#define CLR_TMDS_RX2_FREESYNC_SUPPORT()                     (g_stHDMIFREESYNCInfo.b1HDMIRX2FREESYNCSupport = _FALSE)

#define GET_TMDS_RX3_FREESYNC_SUPPORT()                     (g_stHDMIFREESYNCInfo.b1HDMIRX3FREESYNCSupport)
#define SET_TMDS_RX3_FREESYNC_SUPPORT(x)                    (g_stHDMIFREESYNCInfo.b1HDMIRX3FREESYNCSupport = (x))
#define CLR_TMDS_RX3_FREESYNC_SUPPORT()                     (g_stHDMIFREESYNCInfo.b1HDMIRX3FREESYNCSupport = _FALSE)
#endif
#endif // End of #if(_FREESYNC_SUPPORT == _ON)


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE b3MHLProcessState : 3;
    BYTE b1MHLTransmitStatus : 1;
    BYTE b1MHLResendStatus : 1;
} StructMHLProcessInfo;

#if(_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Struct for DP FREESYNC Support
//--------------------------------------------------
typedef struct
{
    BYTE b1DPFREESYNCEnable : 1;
    BYTE b1DPMSTFREESYNCEnable : 1;
    BYTE b1DPRX0FREESYNCSupport : 1;
    BYTE b1DPRX1FREESYNCSupport : 1;
    BYTE b1DPRX0FREESYNCCapabilitySwitch : 1;
    BYTE b1DPRX1FREESYNCCapabilitySwitch : 1;
} StructDPFREESYNCENABLE;

//--------------------------------------------------
// Struct for HDMI FREESYNC Support
//--------------------------------------------------
typedef struct
{
    BYTE b1HDMIFREESYNCEnable : 1;
    BYTE b1HDMIRX0SPDInfoFrameReceived : 1;
    BYTE b1HDMIRX1SPDInfoFrameReceived : 1;
    BYTE b1HDMIRX2SPDInfoFrameReceived : 1;
    BYTE b1HDMIRX3SPDInfoFrameReceived : 1;

    BYTE b1HDMIRX0FREESYNCSupport : 1;
    BYTE b1HDMIRX1FREESYNCSupport : 1;
    BYTE b1HDMIRX2FREESYNCSupport : 1;
    BYTE b1HDMIRX3FREESYNCSupport : 1;
} StructHDMIFREESYNCENABLE;
#endif

#ifndef __SCALER_SYNC__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

extern WORD idata g_usInputPixelClk;

#if(_VGA_SUPPORT == _ON)
extern WORD idata g_usAdcClockLimit;
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
extern BYTE xdata g_ucDigitalSwitch;
extern BYTE xdata g_ucHDMIHotPlug;

#if(_FREESYNC_SUPPORT == _ON)

#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern StructHDMIFREESYNCENABLE g_stHDMIFREESYNCInfo;

#if(_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE)
extern BYTE g_ucHDMIFREESYNCVCPReceive;
#endif
#endif

extern BYTE g_ucFREESYNCSupport;
extern WORD g_usFREESYNCVFreq;
#endif // End of #if(_FREESYNC_SUPPORT == _ON)

#endif

#if(_MHL_SUPPORT == _ON)
extern StructMHLProcessInfo g_stMHLProcess[_MHL_PORT_VALID];
extern bit g_bMHLPortActive;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerSyncVgaScanInitial(void);
extern WORD ScalerSyncGetDeVsyncWidth(void);
extern void ScalerSyncInterlaceInitial(BYTE ucSourceType);
extern bit ScalerSyncInterlaceCheck(BYTE ucSourceType);
extern void ScalerSyncResetProc(void);
extern void ScalerSyncTmdsVideoDetectEvent();
#endif // End of #ifndef __SCALER_SYNC__
