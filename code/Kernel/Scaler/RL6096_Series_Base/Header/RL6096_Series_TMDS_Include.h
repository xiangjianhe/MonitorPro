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
// ID Code      : RL6096_Series_TMDS_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Define for Clk Freq Detection
//--------------------------------------------------
#define _TMDS_FREQ_NORMAL_OFFSET                    0x7F // 340MHz * 0.01 / 24.3KHz
#define _TMDS_FREQ_NORMAL_UPPER_BOUND               0x38D7 // 340 * (1.04) * 1000 / 24.3
#define _TMDS_FREQ_NORMAL_LOWER_BOUND               0x03DC // 25 * (0.96) * 1000 / 24.3
                                                    
#if(_INTERNAL_OSC_XTAL == _IOSC27000K)              
                                                    
#define _TMDS_FREQ_PS_UPPER_BOUND                   0x38D7 // 1000 * 340 * 1.04 / (27 * 0.9) = 14551
#define _TMDS_FREQ_PS_LOWER_BOUND                   0x0328 // 1000 * 25 * 0.96 / (27 * 1.1) = 808
                                                    
#elif(_INTERNAL_OSC_XTAL == _IOSC14318K)            
                                                    
#define _TMDS_FREQ_PS_UPPER_BOUND                   0x6B30 // 1000 * 340 * 1.04 / (14.318 * 0.9) = 27440
#define _TMDS_FREQ_PS_LOWER_BOUND                   0x05F3 // 1000 * 25 * 0.96 / (14.318 * 1.1) = 1523

#endif

//--------------------------------------------------
// Define for Video Detect
//--------------------------------------------------
#define _TMDS_VIDEO_DATA_NONE                       0
#define _TMDS_VIDEO_DATA_DE_ONLY                    1
#define _TMDS_VIDEO_DATA_RGBHV                      2

//--------------------------------------------------
// Define for Watch Dog Type
//--------------------------------------------------
#define _HDMI_AVI_INFO_VARIATION_WD                 _BIT0
#define _HDMI_AV_MUTE_WD                            _BIT1

//--------------------------------------------------
// Macro of PHY Set Flag
//--------------------------------------------------
#define GET_TMDS_PHY_SET()                          (g_bTmdsPhySet)
#define SET_TMDS_PHY_SET()                          (g_bTmdsPhySet = _TRUE)
#define CLR_TMDS_PHY_SET()                          (g_bTmdsPhySet = _FALSE)

//--------------------------------------------------
// Macro of TMDS Video Detecting Flag
//--------------------------------------------------
#define GET_TMDS_RGBHV_DETECTING()                 (bit)(g_ucTmdsCtrl & _BIT3)
#define SET_TMDS_RGBHV_DETECTING()                 (g_ucTmdsCtrl |= _BIT3)
#define CLR_TMDS_RGBHV_DETECTING()                 (g_ucTmdsCtrl &= ~_BIT3)

//--------------------------------------------------
// Macro of Packet Detecting Flag
//--------------------------------------------------
#define GET_HDMI_PACKET_DETECTING()                 (bit)(g_ucTmdsCtrl & _BIT4)
#define SET_HDMI_PACKET_DETECTING()                 (g_ucTmdsCtrl |= _BIT4)
#define CLR_HDMI_PACKET_DETECTING()                 (g_ucTmdsCtrl &= ~_BIT4)

//--------------------------------------------------
// Macro of AVI Info Frame Received Flag
//--------------------------------------------------
#define GET_HDMI_AVI_INFO_FRAME_RECEIVED()          (bit)(g_ucTmdsCtrl & _BIT5)
#define SET_HDMI_AVI_INFO_FRAME_RECEIVED()          (g_ucTmdsCtrl |= _BIT5)
#define CLR_HDMI_AVI_INFO_FRAME_RECEIVED()          (g_ucTmdsCtrl &= ~_BIT5)

//--------------------------------------------------
// Macro of GCP Received Flag
//--------------------------------------------------
#define GET_HDMI_GCP_RECEIVED()                     (bit)(g_ucTmdsCtrl & _BIT0)
#define SET_HDMI_GCP_RECEIVED()                     (g_ucTmdsCtrl |= _BIT0)
#define CLR_HDMI_GCP_RECEIVED()                     (g_ucTmdsCtrl &= ~_BIT0)

//--------------------------------------------------
// Macro of the Fiset Time of Z0 Asserted
//--------------------------------------------------
#define GET_TMDS_Z0_ASSERTED()                      (bit)(g_ucTmdsCtrl & _BIT7)
#define SET_TMDS_Z0_ASSERTED()                      (g_ucTmdsCtrl |= _BIT7)
#define CLR_TMDS_Z0_ASSERTED()                      (g_ucTmdsCtrl &= ~_BIT7)

//--------------------------------------------------
// Macro of HPD Evnet Trigger
//--------------------------------------------------
#define GET_TMDS_HPD_TRIGGER_EVENT()                (bit)(g_ucTmdsCtrl & _BIT2)
#define SET_TMDS_HPD_TRIGGER_EVENT()                (g_ucTmdsCtrl |= _BIT2)
#define CLR_TMDS_HPD_TRIGGER_EVENT()                (g_ucTmdsCtrl &= ~_BIT2)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __RL6096_SERIES_TMDS__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

extern bit g_bTmdsPhySet;
extern WORD g_usTmdsClkCount;
extern BYTE g_ucTmdsCtrl;
extern bit g_bTmdsD0DdcDetected; 
extern bit g_bTmdsD1DdcDetected; 
extern bit g_bTmdsD2DdcDetected; 
extern bit g_bTmdsD3DdcDetected;  

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerTmdsInitial(BYTE ucInputPort);
extern void ScalerTmdsInterruptInitial(void);

extern bit ScalerTmdsCheckCDRStable(WORD usClkCount);
extern WORD ScalerTmdsMeasureClk(BYTE ucMeasureClk);
extern WORD ScalerTmdsMeasureClk_EXINT0(BYTE ucMeasureClk);
extern BYTE ScalerTmdsFormatDetect(void);
extern void ScalerTmdsDviVideoSetting(void);
extern void ScalerTmdsPowerSavingProc(void);
extern void ScalerTmdsPowerOffProc(void);

#if(_HDMI_SUPPORT == _ON)
extern void ScalerTmdsHdmiVideoSetting(void);
extern void ScalerTmdsHdmiPacketDetect(bit bWait);
extern void ScalerTmdsHdmiPacketDetectEvent(void);
extern bit ScalerTmdsHdmiColorInfoChanged(void);
extern BYTE ScalerTmdsHdmiGetColorDepth(void);
extern bit ScalerTmdsHdmiDeepColorProc(void);
extern void ScalerTmdsHdmiAVMuteProc(void);
extern void ScalerTmdsHdmiWatchDog(BYTE ucWDType, bit bEnable);
#endif

extern void ScalerTmdsFreqDetectDisable(void);
extern void ScalerTmdsFirstActiveProc(BYTE ucSourceType);
extern bit ScalerTmdsHdcpEnabled(void);

#endif // End of #ifndef __RL6096_SERIES_TMDS__
