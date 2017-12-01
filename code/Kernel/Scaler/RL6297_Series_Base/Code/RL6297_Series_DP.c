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
// ID Code      : RL6297_Series_DP.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6297_SERIES_DP__

#include "ScalerFunctionInclude.h"

#if(_DP_SUPPORT == _ON)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
bit g_bDpPSAuxToggle = _FALSE;
BYTE xdata g_ucDpLinkStatus01 = 0;
BYTE xdata g_ucDpLinkStatus23 = 0;
BYTE xdata g_ucDpLinkRequest01 = 0;
BYTE xdata g_ucDpLinkRequest23 = 0;
BYTE xdata g_ucDpTemp = 0;
BYTE xdata g_ucDpBackup[4] = {0};
BYTE xdata g_ucDpInfo = 0;
BYTE xdata g_ucDpLTStatus = _DP_LINK_TRAINING_NONE;
BYTE idata g_ucDpLane0FLDBandStatus = 0;
BYTE idata g_ucDpLane1FLDBandStatus = 0;
BYTE idata g_ucDpLane2FLDBandStatus = 0;
BYTE idata g_ucDpLane3FLDBandStatus = 0;
BYTE xdata g_ucDpPhyCtsCtrl = 0;
BYTE xdata g_ucDpMSAFailMacRsetCount = 0;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
//--------------------------------------------------
void ScalerDpInitial(void);
void ScalerDpAuxIntInitial(void);
void ScalerDpDpcdInitial(void);
void ScalerDpDpcdLinkStatusReset(void);
void ScalerDpHotPlugEvent(EnumDpHotPlugAssertType enumHpdType);
void ScalerDpLinkStatusIRQ(void);
void ScalerDpHotPlugDuration(WORD usMs);
void ScalerDpMacInitial(void);
void ScalerDpPhyInitial(void);
void ScalerDpIntHandler_EXINT0(void);
BYTE ScalerDpTrainingPattern1_EXINT0(EnumDpLinkTrainingType enumDpLtType);
BYTE ScalerDpTrainingPattern2_EXINT0(EnumDpLinkTrainingType enumDpLtType);
void ScalerDpTrainingPatternEnd_EXINT0(void);
void ScalerDpTp1SetPhy_EXINT0(EnumDpTp1FLDClk enumDpTp1Clk);
void ScalerDpTp2SetPhy_EXINT0(void);
void ScalerDpTp2SetPhyFLDBandDetect_EXINT0(void);
BYTE ScalerDpTp1PreCheck_EXINT0(void);
BYTE ScalerDpTp1Check_EXINT0(EnumDpLinkTrainingType enumDpLtType);
BYTE ScalerDpTp2Check_EXINT0(EnumDpLinkTrainingType enumDpLtType);
void ScalerDpRebuildPhy(BYTE ucDpcdRate, BYTE ucDpcdLane);
void ScalerDpRebuildPhyFLDBandDetect(void);
void ScalerDpSetDFEInitial_EXINT0(void);
void ScalerDpSetDFEInitial(EnumDpLinkRate enumDpLinkRate);
void ScalerDpValidSignalDetection(void);
bit ScalerDpCDRCheck(void);
bit ScalerDpMeasureLaneCDRClk(EnumDpLaneNumber enumDpLaneNumber);
bit ScalerDpAlignCheck(void);
bit ScalerDpDecodeCheck(void);
bit ScalerDpGetVideoStream(void);
bit ScalerDpMSACheck(void);
bit ScalerDpMiscCheck(void);
void ScalerDpDisplayFormatSetting(void);
DWORD ScalerDpGetBStoVSDelay(void);
bit ScalerDpInterlaceCheck(void);
void ScalerDpVideoSetting(void);
bit ScalerDpStreamClkRegenerate(void);
void ScalerDpAdjustVsyncDelay(void);
bit ScalerDpFifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition);
void ScalerDpSinkStatusSet(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);  
void ScalerDpCrcCalculate(void);
bit ScalerDpHdcpCheck(void);
bit ScalerDpHdcpMeasureCheck(void);
void ScalerDpCpIRQ(void);
bit ScalerDpHdcpEnebled(void);
void ScalerDpLowPowerCheck(BYTE ucPowerAction);

#if(_DP_DUAL_MODE_SUPPORT == _ON)
void ScalerDpDualModeTmdsSetting(void);
void ScalerDpDualModeDpSetting(void);
#endif

BYTE ScalerDpGetDpcdInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
BYTE ScalerDpGetDpcdInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
void ScalerDpSetDpcdValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
void ScalerDpSetDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
void ScalerDpPhyCtsTp1SetPhy(EnumDpTp1FLDClk enumDpTp1Clk);
void ScalerDpPhyCtsTp2SetPhy(void);
void ScalerDpPhyCtsTp2SetPhyFLDBandDetect(void);
bit ScalerDpPhyCtsTp1Check(void);
bit ScalerDpPhyCtsTp2Check(void);
void ScalerDpPhyCTS(void);

#if(_DP_ASSR_MODE_SUPPORT == _ON)
void ScalerDpASSRModeSetting(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Initial Setting for DP 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpInitial(void)
{        
    ScalerDpAuxIntInitial();
    
    ScalerDpDpcdInitial();

#if(_DP_ASSR_MODE_SUPPORT == _ON)
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x01, 0x0A, 0x00);
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
#endif

    SET_DP_LINK_TRAINING_STATUS(_DP_LINK_TRAINING_NONE);
    
    SET_DP_FAKE_LINK_TRAINING();
} 

//--------------------------------------------------
// Description  : Initial Setting for DP Digital Aux, Analog Aux, Aux INT 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpAuxIntInitial(void)
{
    // Digital Aux Power On, DPCD REG Power On, Aux Mac Clock Select to xclk.
    ScalerSetBit(PC_C0_DPCD_CTL, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT1 | _BIT0), _BIT4);              
     
    // Average 8 cycles as Start Postion, Aux Clk Select to 27MHz, no Swap
    ScalerSetByte(PA_D2_DP_AUX_DIG_PHY_2, 0xC0);    

    // Aux Clk Select Auto Mode, Aux New Mode
    ScalerSetBit(PA_D3_DP_AUX_DIG_PHY_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6)); 

    // HW Fake Link Training Disable. 
    ScalerSetBit(PC_C6_AUX_PHY_DIG2, ~(_BIT5 | _BIT4), 0x00);   

    // Set Aux Precharge Number.
    ScalerSetBit(PA_D4_DP_AUX_DIG_PHY_4, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));  

    // Aux Auto Mode, Using Default Average Number.
    ScalerSetByte(PA_D5_DP_AUX_DIG_PHY_5, 0x0D); 

    // Timeout Target, Enble Aux Channel.
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0), (_BIT7 | _BIT6 | _BIT4 | _BIT0));

    // Fast IIC Clock.
    ScalerSetByte(PC_D1_AUX_IIC_SET, 0x02);

    // Enable 068xxx INT
    ScalerSetBit(PC_DA_AUX_FIFO_RST, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

    // Not Reply when Aux Error.
    ScalerSetBit(PC_DB_AUX_STATUS, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    ScalerSetBit(PA_D6_DP_AUX_DIG_PHY_6, ~(_BIT7 | _BIT6), _BIT6);  
    
    // Disable other DPCD, Aux Timeout, Receiving Aux INT.
    ScalerSetBit(PC_DC_AUX_IRQ_STATUS, ~(_BIT5 | _BIT3 | _BIT2), 0x00);

    // Disable Aux Phy Int 
    ScalerSetBit(PA_D7_DP_AUX_DIG_PHY_7, ~_BIT7, 0x00);

    // Enable DPCD INT
    ScalerSetByte(PC_DE_AUX_DPCD_IRQ_EN, 0xE5);

    // Aux Ack Timer.
    ScalerSetByte(PC_F4_AUX_TX_TIMER, 0x24);

    // Enable Aux Error Handler.
    ScalerSetBit(PA_D8_DP_AUX_DIG_PHY_8, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4));

    // Toggle Aux Auto K
    ScalerSetBit(PB_F4_AUX_5, ~_BIT7, 0x00);
    ScalerSetBit(PB_F4_AUX_5, ~_BIT7, _BIT7);

    // Set VLDO, AUX ADJR, Rx common mode from 1.2V
    ScalerSetByte(PB_F0_AUX_1, 0xF3);

    // Aux 50ohm auto K, Aux Vth-->50mV, Disable Enlarge Rx Termination R
    ScalerSetByte(PB_F1_AUX_2, 0x09);
    ScalerSetBit(PB_F5_HW_AUTO_PS, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT1 | _BIT0));

    // Switch Aux PHY to GDI BandGap
    ScalerSetBit_EXINT0(PB_F2_AUX_3, ~_BIT7, 0x00);

    // Aux comm current select max
    ScalerSetBit_EXINT0(PB_F3_AUX_4, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    ScalerSetBit(PB_EF_DIG_TX_04, ~(_BIT1 | _BIT0), _BIT0);    

    // AUX clock: 27 MHz
    ScalerSetBit(PB_E3_DIG03, ~(_BIT0 | _BIT1), _BIT0);

    // High aux Z0
    ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, _CM_8C_PT_02_TCON_LINE_THRESHOLD_MSB, ~_BIT5, _BIT5);

    // Internal IRQ Enable (Global)
    ScalerGlobalIRQControl(_ENABLE);

    // No reply if receive error, Single Endded Mode.
    ScalerSetBit(P2_E2_AUX_PS_DUMMY1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

    // Aux ps clk from IOSC
    ScalerSetBit(CM_0B_POWER_CTRL2, ~(_BIT5 | _BIT4), 0x00);

    // Enable INT0
    EX0 = 1;
}

//--------------------------------------------------
// Description  : DPCD Table Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpDpcdInitial(void)
{
    // DPCD Capability Field Initial
    ScalerDpSetDpcdValue(0x00, 0x00, 0x00, 0x11);
    
#if(_DP_LINK_CLK_RATE == _DP_LOW_SPEED_162Mhz)
    ScalerDpSetDpcdValue(0x00, 0x00, 0x01, 0x06);
#else
    ScalerDpSetDpcdValue(0x00, 0x00, 0x01, 0x0A);
#endif

#if(_DP_MAIN_LINK_LANES == _DP_ONE_LANE)
    ScalerDpSetDpcdValue(0x00, 0x00, 0x02, 0x81);
#elif(_DP_MAIN_LINK_LANES == _DP_TWO_LANE)
    ScalerDpSetDpcdValue(0x00, 0x00, 0x02, 0x82);
#else
    ScalerDpSetDpcdValue(0x00, 0x00, 0x02, 0x84);
#endif

    ScalerDpSetDpcdValue(0x00, 0x00, 0x03, 0x01);
    ScalerDpSetDpcdValue(0x00, 0x00, 0x04, 0x01);
    ScalerDpSetDpcdValue(0x00, 0x00, 0x05, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x00, 0x06, 0x01);
    ScalerDpSetDpcdValue(0x00, 0x00, 0x07, 0x80);
    ScalerDpSetDpcdValue(0x00, 0x00, 0x08, 0x02);
    ScalerDpSetDpcdValue(0x00, 0x00, 0x09, 0x00);

#if(_AUDIO_SUPPORT == _ON)
    ScalerDpSetDpcdValue(0x00, 0x00, 0x0A, 0x06);
#else
    ScalerDpSetDpcdValue(0x00, 0x00, 0x0A, 0x00);
#endif
   
    ScalerDpSetDpcdValue(0x00, 0x00, 0x0B, 0x00);

#if(_DP_ASSR_MODE_SUPPORT == _ON)
    ScalerDpSetDpcdValue(0x00, 0x00, 0x0D, 0x01);
#endif

    // DPCD Link Status Field Setting
    ScalerDpSetDpcdValue(0x00, 0x02, 0x00, 0x41);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x01, 0x00);    
    ScalerDpSetDpcdValue(0x00, 0x02, 0x05, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x08, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x09, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x0A, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x0B, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x10, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x11, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x12, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x13, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x14, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x15, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x16, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x17, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x46, 0x20);

    // Sink IEEE OUI
    ScalerDpSetDpcdValue(0x00, 0x04, 0x00, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x04, 0x01, 0xE0);
    ScalerDpSetDpcdValue(0x00, 0x04, 0x02, 0x4C);
}

//--------------------------------------------------
// Description  : DPCD Link Status Field Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpDpcdLinkStatusReset(void)
{
    ScalerDpSetDpcdValue(0x00, 0x02, 0x01, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x02, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x03, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x04, 0x80);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x05, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x06, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x02, 0x07, 0x00);

    ScalerSetBit(PC_BD_DPCD_600_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));
    ScalerSetBit(PC_BD_DPCD_600_CTRL, ~_BIT3, 0x00);

    SET_DP_LINK_TRAINING_STATUS(_DP_LINK_TRAINING_NONE);    
}

//--------------------------------------------------
// Description  : Dp HotPlug Event
// Input Value  : Hot Plug Type
// Output Value : None
//--------------------------------------------------
void ScalerDpHotPlugEvent(EnumDpHotPlugAssertType enumHpdType)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    if(GET_D0_CABLE_STATUS() == _TRUE)   
#elif((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT))
    if(GET_D1_CABLE_STATUS() == _TRUE)  
#endif 
    {
        SET_DP_VALID_VIDEO_CHECK();
    }
    
    ScalerDpDpcdLinkStatusReset();

#if(_DP_ASSR_MODE_SUPPORT == _ON)
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);
    ScalerDpSetDpcdValue(0x00, 0x01, 0x0A, 0x00);
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
#endif

#if(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC2)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC2)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3)))
    // Reset DDC2 
    MCU_DVI_DDC_CTRL1_FF1F |= _BIT1;
#elif(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC3)) || \
      ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC3)) || \
      ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2)))
    // Reset DDC3
    MCU_HDMI_DDC_CTRL1_FF2D |= _BIT1;
#endif

    if(enumHpdType == _DP_LONG_HPD_EVENT)
    {
        ScalerDpHotPlugDuration(200);
    }
    else if(enumHpdType == _DP_HDCP_LONG_HPD_EVENT)
    {
        ScalerDpHotPlugDuration(800);    
    }
    else
    {
        ScalerDpHotPlugDuration(0);
    }   
}

//--------------------------------------------------
// Description  : Dp Interrupt Request
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpLinkStatusIRQ(void)
{       
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);

    if((GET_DP_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_FAIL) || (GET_DP_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
    {
        ScalerDpDpcdLinkStatusReset();

        ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
        
        ScalerDpHotPlugDuration(1);
    }

    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
}

//--------------------------------------------------
// Description  : Hot Plug Low Pulse Duration
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpHotPlugDuration(WORD usMs)
{
    ScalerTimerDelayXms(1);

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    if(GET_D0_CABLE_STATUS() == _TRUE)
    {
        if(usMs != 0)
        {
            PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
            ScalerTimerDelayXms(usMs);
        }
        
        PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
    }    
#elif((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT))
    if(GET_D1_CABLE_STATUS() == _TRUE)
    {
        if(usMs != 0)
        {
            PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
            ScalerTimerDelayXms(usMs);
        }
        
        PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);        
    }     
#endif        
}

//--------------------------------------------------
// Description  : Dp Mac Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpMacInitial(void)
{
    // DP Power On
    ScalerSetBit(PC_A1_DP_CTL, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // DP Lane Swap Setting
    ScalerSetByte(PC_A4_LANE_SWAP, 0x1B);

    // DP RGB and CLK Output Enable
    ScalerSetBit(PC_A2_DP_OUTPUT_CTL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    // DP 4-layer De-Skew select
    ScalerSetByte(PC_A8_MIN_DE_SKEW, 0x18);

    // 0x00:disable error correction, 0xF4:enable all error correction
    ScalerSetByte(PC_A9_MN_ERRC, 0x20);              

    CLR_DP_MSA_FAIL_MAC_RESET_COUNT();
}
//--------------------------------------------------
// Description  : DP Phy Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpPhyInitial(void)
{
    // [6] lpf_cs60p_sel =1 select CDR lpf sc 46pF     
    // [4:3] Enable Stage1 High Boost Mode, Disable Stage2 High Boost Mode
    // [2] TP1 Signal to Lock FLD After LEQ
    ScalerSetBit(PB_A4_CDR_2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT4 | _BIT2));

    // [2:0] Calib_time
    ScalerSetBit(PB_AF_RXMISC_2, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // FLD Xtal Divider select 1
    ScalerSetBit(PB_A9_CDR_7, ~_BIT0, 0x00);
    
    // [0] cpsc = 0 1st order loop capacitor 
    ScalerSetBit(PB_AA_CDR_8, ~_BIT0, 0x00);
    
    // [6] Disable Ultra Low Rate
    ScalerSetBit(PB_AD_RXMISC_0, ~_BIT6, 0x00);

    // Disable Stage3 Booster 
    ScalerSetBit(PB_B1_EQ_1, ~_BIT5, 0x00);

    // Enable Tap1/2, Disable Tap3/4
    ScalerSetBit(PB_B0_EQ_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6));
    
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
    // Digital PHY Lane Swap Setting
    ScalerSetByte(PB_D0_RXMISC_3, 0x1B);  

    // Digital PHY P/N Swap Setting
    ScalerSetBit(PB_D1_RXMISC_4, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
#else
    // Digital PHY Lane Swap Setting
    ScalerSetByte(PB_D0_RXMISC_3, 0xE4);    
#endif
   
}

//--------------------------------------------------
// Description  : DP Interrupt Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpIntHandler_EXINT0(void) using 1
{        
    if(ScalerGetBit_EXINT0(PA_DA_DP_AUX_DIG_PHY_A, (_BIT4 | _BIT0)) == (_BIT4 | _BIT0))
    {
        if(ScalerGetBit_EXINT0(PA_D9_DP_AUX_DIG_PHY_9, (_BIT3 | _BIT2| _BIT1 | _BIT0)) == 0x00)
        {
            if((MCU_CTRL_FFED & _BIT1) == 0x00)
            {
                MCU_CTRL_FFED = (_FLASH_CLK_PS_FAST_DIV << 2) | (MCU_CTRL_FFED & 0xC3);  
            }

            // Disable Aux INT
            ScalerSetBit_EXINT0(PA_DA_DP_AUX_DIG_PHY_A, ~_BIT4, 0x00);

            // Enable GDI BandGap
            ScalerSetBit_EXINT0(PB_F4_AUX_5, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

            // Disable GDI Power Saving
            ScalerSetBit_EXINT0(PB_F4_AUX_5, ~_BIT4, 0x00);

            // Disable Aux Power Saving Mode
            ScalerSetBit_EXINT0(PB_F1_AUX_2, ~_BIT1, 0x00);

            // Switch Aux PHY to GDI BandGap
            ScalerSetBit_EXINT0(PB_F2_AUX_3, ~_BIT7, 0x00);

            // Aux comm current select max
            ScalerSetBit_EXINT0(PB_F3_AUX_4, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            SET_DP_PS_AUX_TOGGLE();        

            IP = 0xA0;

            return;
        }
        else
        {
            // Clear Aux INT flag
            ScalerSetBit_EXINT0(PA_DA_DP_AUX_DIG_PHY_A, ~_BIT0, _BIT0);

            // Clear Manchester/Stop pattern/Sync_end pattern/Byte boundary check Error
            ScalerSetBit_EXINT0(PA_D9_DP_AUX_DIG_PHY_9, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

            return;
        }  
    }

    // Aux Firmware Control -> Reply Defer
    ScalerSetBit_EXINT0(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);

    g_ucDpBackup[0] = ScalerGetByte_EXINT0(PC_B3_DP_ACCESS_PORT);
    g_ucDpBackup[1] = ScalerGetByte_EXINT0(PC_C1_DPCD_ACCESS_PORT_H);
    g_ucDpBackup[2] = ScalerGetByte_EXINT0(PC_C2_DPCD_ACCESS_PORT_M);
    g_ucDpBackup[3] = ScalerGetByte_EXINT0(PC_C3_DPCD_ACCESS_PORT_L);

    ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_CC_DP_IRQ_CTRL0);
        
    g_ucDpTemp = ScalerGetByte_EXINT0(PC_B4_DP_DATA_PORT);
        
    if((g_ucDpTemp & _BIT7) == _BIT7)
    {        
        if((MCU_CTRL_FFED & _BIT1) == 0x00)
        {
            MCU_CTRL_FFED = (_FLASH_CLK_PS_FAST_DIV << 2) | (MCU_CTRL_FFED & 0xC3);  
        }
    
        // Clear DP Global Flag & Force Disable Fifo Under/Overflow INT
        ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_CC_DP_IRQ_CTRL0);
        ScalerSetByte_EXINT0(PC_B4_DP_DATA_PORT, 0x80);

        if((ScalerGetByte_EXINT0(PC_DD_AUX_DPCD_IRQ) & (_BIT7 | _BIT6 | _BIT5)) != 0x00 ) // Write Link Config Field into INT0
        {               
            // Clear Flag
            ScalerSetBit_EXINT0(PC_DD_AUX_DPCD_IRQ, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));            

            switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x02) & 0x03)
            {                
                case _DP_TRAINING_PATTERN_1:

                    if(GET_DP_FAKE_LINK_TRAINING() == _FALSE)
                    {   
                        if(GET_DP_LINK_TRAINING_STATUS() != _DP_NORMAL_TRAINING_PATTERN_1_PASS)
                        {                                   
                            if(ScalerDpTrainingPattern1_EXINT0(_DP_NORMAL_LT) == _TRUE)
                            {                                
                                SET_DP_LINK_TRAINING_STATUS(_DP_NORMAL_TRAINING_PATTERN_1_PASS);
                            }
                            else
                            {
                                SET_DP_LINK_TRAINING_STATUS(_DP_NORMAL_TRAINING_PATTERN_1_FAIL);    
                            }
                        }
                    }
                    else
                    {   
                        if(GET_DP_LINK_TRAINING_STATUS() != _DP_FAKE_TRAINING_PATTERN_1_PASS)
                        {                              
                            if(ScalerDpTrainingPattern1_EXINT0(_DP_FAKE_LT) == _TRUE)
                            {
                                SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_TRAINING_PATTERN_1_PASS);
                            }
                            else
                            {
                                SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_TRAINING_PATTERN_1_FAIL);    
                            }
                        }
                    }
                    
                    break;
                    
                case _DP_TRAINING_PATTERN_2:

                    if((GET_DP_FAKE_LINK_TRAINING() == _FALSE) && 
                        ((GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_TRAINING_PATTERN_1_PASS) || 
                        (GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_TRAINING_PATTERN_2_FAIL)))
                    {
                        if(ScalerDpTrainingPattern2_EXINT0(_DP_NORMAL_LT) == _TRUE)
                        {
                            SET_DP_LINK_TRAINING_STATUS(_DP_NORMAL_TRAINING_PATTERN_2_PASS);
                        }
                        else
                        {
                            SET_DP_LINK_TRAINING_STATUS(_DP_NORMAL_TRAINING_PATTERN_2_FAIL);
                        }
                    }
                    else if((GET_DP_LINK_TRAINING_STATUS() == _DP_FAKE_TRAINING_PATTERN_1_PASS) || 
                            (GET_DP_LINK_TRAINING_STATUS() == _DP_FAKE_TRAINING_PATTERN_2_FAIL) ||
                            (GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_TRAINING_PATTERN_1_PASS) ||
                            (GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_TRAINING_PATTERN_2_FAIL))
                    {
                        if(ScalerDpTrainingPattern2_EXINT0(_DP_FAKE_LT) == _TRUE)
                        {
                            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_TRAINING_PATTERN_2_PASS);
                        }
                        else
                        {
                            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_TRAINING_PATTERN_2_FAIL);
                        }
                    }
                    
                    break;
                    
                case _DP_TRAINING_PATTERN_END:                    

                    ScalerDpTrainingPatternEnd_EXINT0();
 
                    if(GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_TRAINING_PATTERN_2_PASS)
                    {
                        ScalerSetBit_EXINT0(PC_BD_DPCD_600_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));
                        ScalerSetBit_EXINT0(PC_BD_DPCD_600_CTRL, ~_BIT3, 0x00);
                        
                        if(GET_DP_FAKE_LINK_TRAINING() == _FALSE)
                        {
                            SET_DP_LINK_TRAINING_STATUS(_DP_NORMAL_LINK_TRAINING_PASS);
                        }
                        else
                        {
                            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);
                        }
                    }
                    else if(GET_DP_LINK_TRAINING_STATUS() == _DP_FAKE_TRAINING_PATTERN_2_PASS)
                    {
                        ScalerSetBit_EXINT0(PC_BD_DPCD_600_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));
                        ScalerSetBit_EXINT0(PC_BD_DPCD_600_CTRL, ~_BIT3, 0x00);
                        
                        SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);                       
                    }
                    else if((GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_TRAINING_PATTERN_1_FAIL) || 
                            (GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_TRAINING_PATTERN_2_FAIL) ||
                            (GET_DP_LINK_TRAINING_STATUS() == _DP_FAKE_TRAINING_PATTERN_1_FAIL) || 
                            (GET_DP_LINK_TRAINING_STATUS() == _DP_FAKE_TRAINING_PATTERN_2_FAIL)) 
                    {
                        SET_DP_LINK_TRAINING_STATUS(_DP_LINK_TRAINING_FAIL);
                    }
                    
                    break;
                default:
                    break;
            }
        }

        if(ScalerGetBit_EXINT0(PC_DD_AUX_DPCD_IRQ, _BIT0) == _BIT0) // Write 00600h into INT0
        {
            // Clear Flag
            ScalerSetBit_EXINT0(PC_DD_AUX_DPCD_IRQ, ~_BIT0, _BIT0);

            if((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x06, 0x00) & (_BIT1 | _BIT0)) == _BIT1)
            {
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x01, 0x00);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x00);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x00);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x80);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x05, 0x00);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x06, 0x00);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x00);
                
                SET_DP_LINK_TRAINING_STATUS(_DP_LINK_TRAINING_NONE);
            }          
            else if((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x06, 0x00) & (_BIT1 | _BIT0)) == _BIT0)
            { 
                if(GET_DP_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE)
                {
                    SET_DP_VALID_VIDEO_CHECK();
                }                
            }
        }

        if(ScalerGetBit_EXINT0(PC_DA_AUX_FIFO_RST, _BIT1) == _BIT1) // Write 68xxxh into INT0
        {
            // Clear Flag
            ScalerSetBit_EXINT0(PC_DA_AUX_FIFO_RST, ~_BIT1, _BIT1);

            // Clear Integrity Failure Flag
            ScalerSetBit_EXINT0(PC_E4_HDCP_INTGT_VRF, ~_BIT1, _BIT1);

            if(GET_DP_FAKE_LINK_TRAINING() == _TRUE)
            {
                // DP Mac Clock Select to Xtal Clock
                ScalerSetBit_EXINT0(PC_F6_AUX_ERROR_HANDLE2, ~_BIT4, _BIT4);
            }
        }

        if(ScalerGetBit_EXINT0(PC_DD_AUX_DPCD_IRQ, _BIT2) == _BIT2) // Write 00270h into INT0
        {
            // Clear Flag
            ScalerSetBit_EXINT0(PC_DD_AUX_DPCD_IRQ, ~_BIT2, _BIT2);

            // Clear TEST_CRC_COUNT
            ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x46, 0x20);            
        }    
    }

    ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, g_ucDpBackup[0]);
    ScalerSetByte_EXINT0(PC_C1_DPCD_ACCESS_PORT_H, g_ucDpBackup[1]);
    ScalerSetByte_EXINT0(PC_C2_DPCD_ACCESS_PORT_M, g_ucDpBackup[2]);
    ScalerSetByte_EXINT0(PC_C3_DPCD_ACCESS_PORT_L, g_ucDpBackup[3]);

    // Aux Hardware Control
    ScalerSetBit_EXINT0(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);

}

//--------------------------------------------------
// Description  : Check Dp Training Pattern 1
// Input Value  : Normal or Fake LT
// Output Value : TRUE --> TP1 Pass
//--------------------------------------------------
BYTE ScalerDpTrainingPattern1_EXINT0(EnumDpLinkTrainingType enumDpLtType) using 1
{
    if(enumDpLtType == _DP_NORMAL_LT)
    {
        ScalerDpTp1SetPhy_EXINT0(_DP_FLD_REF_D10_2);

        if( ScalerDpTp1PreCheck_EXINT0() == _FALSE)
        {
            ScalerDpTp1SetPhy_EXINT0(_DP_FLD_REF_XTAL);
        }    
    }

    if(ScalerDpTp1Check_EXINT0(enumDpLtType) == _TRUE)
    {
        return _TRUE;
    }        
    
    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Dp Training Pattern 2
// Input Value  : Normal or Fake LT
// Output Value : TRUE --> TP2 Pass
//--------------------------------------------------
BYTE ScalerDpTrainingPattern2_EXINT0(EnumDpLinkTrainingType enumDpLtType) using 1
{    
    if(enumDpLtType == _DP_NORMAL_LT)
    {
        ScalerDpTp2SetPhy_EXINT0();           

        ScalerDpTp2SetPhyFLDBandDetect_EXINT0();        
    }
    
    if(ScalerDpTp2Check_EXINT0(enumDpLtType) == _TRUE)
    {
        return _TRUE;            
    }
    
    return _FALSE;
}

//--------------------------------------------------
// Description  : Settings after Link Training Pass
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpTrainingPatternEnd_EXINT0(void) using 1
{
    switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & 0x1F)
    {
        case _DP_ONE_LANE:            
            ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~(_BIT4 | _BIT3), _BIT3);                            
            break;
            
        case _DP_TWO_LANE:
            ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~(_BIT4 | _BIT3), _BIT4);            
            break;

        case _DP_FOUR_LANE:    
        default:
            ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));            
            break;
    }

    // De-Skew Circuit Reset
    ScalerSetBit_EXINT0(PC_BB_DP_RESERVE1, ~_BIT5, 0x00);
    ScalerSetBit_EXINT0(PC_BB_DP_RESERVE1, ~_BIT5, _BIT5);

    // DP Mac Reset
    ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~_BIT6, _BIT6);
    ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~_BIT6, 0x00);

    // Secondary Data Reset (DP Audio Block)
    ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_92_AUD_BUF_STATUS);
    ScalerSetByte_EXINT0(PC_B4_DP_DATA_PORT, 0xFC);    
    ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_92_AUD_BUF_STATUS);
    ScalerSetByte_EXINT0(PC_B4_DP_DATA_PORT, 0xF8);     

    // Set Lane0 Clk Inverse
    ScalerSetBit_EXINT0(PC_A7_DP_LANE_CLK_INV, ~(_BIT7 | _BIT3), _BIT7);
    
    if((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & _BIT7) == _BIT7)
    {
        // Enable Enhancement Control Mode --> Digital PHY
        ScalerSetBit_EXINT0(PB_E0_DIG00, ~_BIT5, _BIT5);

        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~_BIT2, _BIT2);
    }
    else
    {
        // Enable Enhancement Control Mode --> Digital PHY
        ScalerSetBit_EXINT0(PB_E0_DIG00, ~_BIT5, 0x00);
        
        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~_BIT2, 0x00);
    }    
    
    if((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x02) & _BIT5) == _BIT5)
    {
        // Disable Scrambling
        ScalerSetBit_EXINT0(PB_E2_DIG02, ~_BIT7, _BIT7);
    }
    else
    {
        // Enable Scrambling
        ScalerSetBit_EXINT0(PB_E2_DIG02, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : DP Phy Setting in TP1
// Input Value  : FLD Reference Clock
// Output Value : None
//--------------------------------------------------
void ScalerDpTp1SetPhy_EXINT0(EnumDpTp1FLDClk enumDpTp1Clk) using 1
{
    ///////////////////////////
    // RX CMU EN & Mac Power //
    ///////////////////////////
    
    // Disable RX_EN and CMU_EN
    ScalerSetByte_EXINT0(PB_B4_POWER_0, 0x00);

    // Disable Auto k-offset(foreground)
    ScalerSetBit_EXINT0(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);   

    // Dual Mode Disable and Analog Select to DP
    ScalerSetBit_EXINT0(PB_AC_CDR_A, ~(_BIT3 | _BIT4), _BIT4);            

    // Digital PHY Select to DP
    ScalerSetBit_EXINT0(PB_E0_DIG00, ~_BIT4, 0x00);
    
    switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & 0x1F)
    {               
        case _DP_ONE_LANE:

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
            ScalerSetByte_EXINT0(PB_B4_POWER_0, 0x88);
#else
            ScalerSetByte_EXINT0(PB_B4_POWER_0, 0x11);
#endif              
            ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~(_BIT4 | _BIT3), _BIT3);
                            
            break;
            
        case _DP_TWO_LANE:

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
            ScalerSetByte_EXINT0(PB_B4_POWER_0, 0xCC);
#else
            ScalerSetByte_EXINT0(PB_B4_POWER_0, 0x33);
#endif
            ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~(_BIT4 | _BIT3), _BIT4);
            
            break;

        case _DP_FOUR_LANE:    
        default:

            ScalerSetByte_EXINT0(PB_B4_POWER_0, 0xFF);
            
            ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
            
            break;
    }     


    /////////////////
    // CDR Setting //
    /////////////////
    
    if(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x00) == 0x0A) // HBR
    {        
        // [7:6] High Bit Rate(2.7G)
        ScalerSetBit_EXINT0(PB_AC_CDR_A, ~(_BIT6 | _BIT7), _BIT6);

        // [7:6] vco_div = 00 VCO/1
        // [5] sel_bb = 1 BB PD
        // [4] sel_half = 1 full rate
        // [1:0] kvco = 1 526MHz/V
        ScalerSetByte_EXINT0(PB_A5_CDR_3, 0x31);

        // [7:4] cp_sel = 0001 7.5uA
        // [3:1] cpsr = 101 1k
        ScalerSetByte_EXINT0(PB_A6_CDR_4, 0x1A);
    }
    else // RBR
    {        
        // [7:6] Low Bit rate(1.62G)
        ScalerSetBit_EXINT0(PB_AC_CDR_A, ~(_BIT6 | _BIT7), 0x00);

        // [7:6] vco_div = 01 VCO/2
        // [5] sel_bb = 1 BB PD
        // [4] sel_half = 1 half rate
        // [1:0] kvco = 1 526MHz/V
        ScalerSetByte_EXINT0(PB_A5_CDR_3, 0x71);

        // [7:4] cp_sel = 0001 7.5uA
        // [3:1] cpsr = 000 2k
        ScalerSetByte_EXINT0(PB_A6_CDR_4, 0x10);
    }

    if(enumDpTp1Clk == _DP_FLD_REF_D10_2)
    {
        // D10.2 lock FLD
        ScalerSetBit_EXINT0(PB_AB_CDR_9, ~_BIT6, 0x00);

        // For RBR
        ScalerSetBit_EXINT0(PB_C8_FLD_CONT_0, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT2 | _BIT0));
        ScalerSetByte_EXINT0(PB_C9_FLD_CONT_1, 0x0D);
        ScalerSetByte_EXINT0(PB_CA_FLD_CONT_2, 0x86);

        // For HBR
        ScalerSetBit_EXINT0(PB_CB_FLD_CONT_3, ~(_BIT7 | _BIT6), _BIT7);
        ScalerSetByte_EXINT0(PB_CC_FLD_CONT_4, 0x0D);
        ScalerSetByte_EXINT0(PB_CD_FLD_CONT_5, 0x86);
    }
    else if(enumDpTp1Clk == _DP_FLD_REF_XTAL)
    {
        // Xtal lock FLD  
        ScalerSetBit_EXINT0(PB_AB_CDR_9, ~_BIT6, _BIT6);

        // For RBR
        ScalerSetBit_EXINT0(PB_C8_FLD_CONT_0, ~(_BIT7 | _BIT6), _BIT7);
        ScalerSetByte_EXINT0(PB_C9_FLD_CONT_1, 0x2B);
        ScalerSetByte_EXINT0(PB_CA_FLD_CONT_2, 0x31);
           
        // For HBR
        ScalerSetBit_EXINT0(PB_CB_FLD_CONT_3, ~(_BIT7 | _BIT6), _BIT7);
        ScalerSetByte_EXINT0(PB_CC_FLD_CONT_4, 0x2B);
        ScalerSetByte_EXINT0(PB_CD_FLD_CONT_5, 0x1D);        
    }        


    /////////////////////
    // Rx Misc Setting //
    /////////////////////
    
    // [7] FLD Auto Mode
    ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~_BIT7, _BIT7);

    // [4] Enable cp_adj_en : Add CP Current During FLD Lock Band
    // [3] Enable Adaptation when FLD Auto Mode
    ScalerSetBit_EXINT0(PB_AD_RXMISC_0, ~(_BIT4 | _BIT3), _BIT4); 
   
    // Disable De-Scrambling, Disable Commoa Detection
    ScalerSetBit_EXINT0(PB_E2_DIG02, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    if((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & _BIT7) == _BIT7)
    {
        // Enable Enhancement Control Mode --> Digital PHY
        ScalerSetBit_EXINT0(PB_E0_DIG00, ~_BIT5, _BIT5);

        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~_BIT2, _BIT2);
    }
    else
    {
        // Enable Enhancement Control Mode --> Digital PHY
        ScalerSetBit_EXINT0(PB_E0_DIG00, ~_BIT5, 0x00);

        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~_BIT2, 0x00);
    }   


    /////////////////
    // DFE Setting //
    /////////////////   
    
    // Set DFE Initial
    ScalerDpSetDFEInitial_EXINT0();

      
    //////////////
    // K Offset //
    ////////////// 

    // [5] Foreground Calibration Auto Mode
    ScalerSetBit_EXINT0(PB_B2_EQ_2, ~(_BIT6 | _BIT5), _BIT5);

    // [6] Enable offset Calibration
    ScalerSetBit_EXINT0(PB_B2_EQ_2, ~_BIT6, _BIT6);
    
    // Waiting for K Offset 
    for(g_ucDpTemp = 0; g_ucDpTemp <= 10; g_ucDpTemp++)
    {
        _nop_();
    } 


    ///////////////
    // FLD Reset //
    /////////////// 
    
    // sel_cktp1   
    ScalerSetBit_EXINT0(PB_A9_CDR_7, ~_BIT4, _BIT4);

    // FLD Reset
    ScalerSetBit_EXINT0(PB_B5_DP_2D_SWITCH, ~_BIT0, 0x00);
    ScalerSetBit_EXINT0(PB_B5_DP_2D_SWITCH, ~_BIT0, _BIT0);

    // Enable DFE Adpatation
    ScalerSetByte_EXINT0(P1D_A1_L0_DFE_EN_2, 0x61);
    ScalerSetByte_EXINT0(P1D_B1_L1_DFE_EN_2, 0x61);
    ScalerSetByte_EXINT0(P1D_C1_L2_DFE_EN_2, 0x61);
    ScalerSetByte_EXINT0(P1D_D1_L3_DFE_EN_2, 0x61);      

    // Waiting for the FLD Band Searching
    for(g_ucDpTemp = 0; g_ucDpTemp <= 30; g_ucDpTemp++)
    {
        _nop_();
    }

    // Disable_cktp1   
    ScalerSetBit_EXINT0(PB_A9_CDR_7, ~_BIT4, 0x00);

    // Disable Adaptation
    ScalerSetByte_EXINT0(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte_EXINT0(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte_EXINT0(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte_EXINT0(P1D_D1_L3_DFE_EN_2, 0x00);   

    // [4] Disable cp_adj_en : Add CP Current During FLD Lock Band
    // [3] Disable Adaptation when FLD Auto Mode
    ScalerSetBit_EXINT0(PB_AD_RXMISC_0, ~(_BIT4 | _BIT3), _BIT3); 
    
    // DP Mac Clock Select to Link Clock
    ScalerSetBit_EXINT0(PC_F6_AUX_ERROR_HANDLE2, ~_BIT4, 0x00);    
}

//--------------------------------------------------
// Description  : DP Phy Setting in TP2
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpTp2SetPhy_EXINT0(void) using 1
{
    // Disable De-Scrambling, Enable Commoa Detection
    ScalerSetBit_EXINT0(PB_E2_DIG02, ~(_BIT7 | _BIT6), _BIT7);
                     
    if(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x00) == 0x0A)
    {   
        // Charge Pump Current and Resistor Double
        ScalerSetByte_EXINT0(PB_A6_CDR_4, 0x30);
    }
    else
    {
        // Charge Pump Current and Resistor Double
        ScalerSetByte_EXINT0(PB_A6_CDR_4, 0x32);
    }

    // Manual band 
    ScalerSetByte_EXINT0(PB_DC_VCO_4, ScalerGetByte_EXINT0(PB_D8_VCO_0));
    ScalerSetByte_EXINT0(PB_DD_VCO_5, ScalerGetByte_EXINT0(PB_D9_VCO_1));
    ScalerSetByte_EXINT0(PB_DE_VCO_6, ScalerGetByte_EXINT0(PB_DA_VCO_2));
    ScalerSetByte_EXINT0(PB_DF_VCO_7, ScalerGetByte_EXINT0(PB_DB_VCO_3));
                        
    // [7] auto_mode = 0 FLD Manual Mode
    // [5] cp_en_manual = 0 --> Disable Manual Enable CP
    // [4] adp_en_manual = 0 --> Disable  adaptation.
    // [3] calib_manual = 0 --> Disable Calibration Manual    
    ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3), 0x00);

    // Set DFE Initial
    ScalerDpSetDFEInitial_EXINT0();

    // Enable Adaptation
    ScalerSetByte_EXINT0(P1D_A1_L0_DFE_EN_2,0xE7);
    ScalerSetByte_EXINT0(P1D_B1_L1_DFE_EN_2,0xE7);
    ScalerSetByte_EXINT0(P1D_C1_L2_DFE_EN_2,0xE7);
    ScalerSetByte_EXINT0(P1D_D1_L3_DFE_EN_2,0xE7);   
    
    // [5] cp_en_manual = 1 --> Manual Enable CP
    ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~_BIT5, _BIT5);   

    // [4] adp_en_manual = 1 --> Close CDR loop. Enable adaptation.
    ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~_BIT4, _BIT4);   
    
    // [3] calib_manual = 1 --> Calibration Manual
    ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~_BIT3, _BIT3);
    
    // Waiting for Adaptation
    for(g_ucDpTemp = 0; g_ucDpTemp <= 5; g_ucDpTemp++)
    {
        _nop_();
    }
    
    // Disable Adaptation 
    ScalerSetByte_EXINT0(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte_EXINT0(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte_EXINT0(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte_EXINT0(P1D_D1_L3_DFE_EN_2, 0x00); 

    // Reload Tap0 to Initial Value
    ScalerSetByte_EXINT0(P1D_A4_L0_INIT_2, 0x15);
    ScalerSetByte_EXINT0(P1D_B4_L1_INIT_2, 0x15);
    ScalerSetByte_EXINT0(P1D_C4_L2_INIT_2, 0x15); 
    ScalerSetByte_EXINT0(P1D_D4_L3_INIT_2, 0x15);
        
    ScalerSetBit_EXINT0(P1D_AA_L0_INIT_8, ~_BIT0, _BIT0);
    ScalerSetBit_EXINT0(P1D_BA_L1_INIT_8, ~_BIT0, _BIT0);
    ScalerSetBit_EXINT0(P1D_CA_L2_INIT_8, ~_BIT0, _BIT0);
    ScalerSetBit_EXINT0(P1D_DA_L3_INIT_8, ~_BIT0, _BIT0);

    ScalerSetBit_EXINT0(P1D_AA_L0_INIT_8, ~_BIT0, 0x00); 
    ScalerSetBit_EXINT0(P1D_BA_L1_INIT_8, ~_BIT0, 0x00); 
    ScalerSetBit_EXINT0(P1D_CA_L2_INIT_8, ~_BIT0, 0x00); 
    ScalerSetBit_EXINT0(P1D_DA_L3_INIT_8, ~_BIT0, 0x00);
     
    // Disable Adaptation
    ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~_BIT4, 0x00);
         
    if((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & _BIT7) == _BIT7)
    {
        // Enable Enhancement Control Mode --> Digital PHY
        ScalerSetBit_EXINT0(PB_E0_DIG00, ~_BIT5, _BIT5);

        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~_BIT2, _BIT2);
    }
    else
    {
        // Enable Enhancement Control Mode --> Digital PHY
        ScalerSetBit_EXINT0(PB_E0_DIG00, ~_BIT5, 0x00);

        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit_EXINT0(PC_A1_DP_CTL, ~_BIT2, 0x00);
    }   

    if(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x00) == 0x0A)
    {   
        // Charge Pump Current and Resistor Recover
        ScalerSetByte_EXINT0(PB_A6_CDR_4, 0x1A);
    }
    else
    {
        // Charge Pump Current and Resistor Recover
        ScalerSetByte_EXINT0(PB_A6_CDR_4, 0x10);
    }

    // [5] Foreground Calibration Auto Mode
    ScalerSetBit_EXINT0(PB_B2_EQ_2, ~(_BIT6 | _BIT5), _BIT5);

    // [6] Enable offset Calibration
    ScalerSetBit_EXINT0(PB_B2_EQ_2, ~_BIT6, _BIT6);
    
    // Waiting for K Offset 
    for(g_ucDpTemp = 0; g_ucDpTemp <= 10; g_ucDpTemp++)
    {
        _nop_();
    }     
}

//--------------------------------------------------
// Description  : DP FLD Band Detection in TP2
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpTp2SetPhyFLDBandDetect_EXINT0(void) using 1
{
    BYTE ucCounter = 0;
    BYTE ucEQCRCStatus = 0;

    g_ucDpLane0FLDBandStatus = 0;
    g_ucDpLane1FLDBandStatus = 0;
    g_ucDpLane2FLDBandStatus = 0;
    g_ucDpLane3FLDBandStatus = 0;    

    for(ucCounter = 0; ucCounter <= 5; ucCounter++)
    {               
        // [5] cp_en_manual = 0 --> Disable Manual Enable CP
        // [3] calib_manual = 0 --> Disable Calibration Manual    
        ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~(_BIT5 | _BIT3), 0x00);
        
        // Manual band 
        ScalerSetByte_EXINT0(PB_DC_VCO_4, (ScalerGetByte_EXINT0(PB_D8_VCO_0) - 2 + ucCounter));
        ScalerSetByte_EXINT0(PB_DD_VCO_5, (ScalerGetByte_EXINT0(PB_D9_VCO_1) - 2 + ucCounter));
        ScalerSetByte_EXINT0(PB_DE_VCO_6, (ScalerGetByte_EXINT0(PB_DA_VCO_2) - 2 + ucCounter));
        ScalerSetByte_EXINT0(PB_DF_VCO_7, (ScalerGetByte_EXINT0(PB_DB_VCO_3) - 2 + ucCounter));

        // [5] cp_en_manual = 1 --> Manual Enable CP
        ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~_BIT5, _BIT5);

        // Waiting for VCO Stable
        for(g_ucDpTemp = 0; g_ucDpTemp <= 0; g_ucDpTemp++)
        {
            _nop_();
        }
        
        // [3] calib_manual = 1 --> Calibration Manual
        ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~_BIT3, _BIT3);
                
        // Enable EQ-CRC and Clear EQ-CRC Status
        ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ScalerSetByte_EXINT0(PC_B4_DP_DATA_PORT, 0x8F);     
        ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ScalerSetByte_EXINT0(PC_B4_DP_DATA_PORT, 0x8F);         

        for(g_ucDpTemp = 0; g_ucDpTemp <= 2; g_ucDpTemp++)
        {
            _nop_();
        }

        ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ucEQCRCStatus = ScalerGetByte_EXINT0(PC_B4_DP_DATA_PORT);

        // Disable EQ-CRC
        ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ScalerSetByte_EXINT0(PC_B4_DP_DATA_PORT, 0x0F);                

        // Lane0 EQ-CRC Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if((ucEQCRCStatus & _BIT0) == 0x00)
#else
        if((ucEQCRCStatus & _BIT3) == 0x00)
#endif
        {
            if((g_ucDpLane0FLDBandStatus & _BIT7) == 0x00)
            {
                g_ucDpLane0FLDBandStatus |= _BIT7;
                
                if(ucCounter == 5)
                {
                    g_ucDpLane0FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    g_ucDpLane0FLDBandStatus += ucCounter;
                }  
            }
            else if((g_ucDpLane0FLDBandStatus & _BIT6) == _BIT6)
            {
                g_ucDpLane0FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                g_ucDpLane0FLDBandStatus += ucCounter;
            }
        }
        else
        {
            if(((g_ucDpLane0FLDBandStatus & _BIT7) == _BIT7) && ((g_ucDpLane0FLDBandStatus & _BIT6) == 0x00))
            {
                g_ucDpLane0FLDBandStatus |= _BIT6;
                g_ucDpLane0FLDBandStatus += (ucCounter - 1);
            }
        }             

        // Lane1 EQ-CRC Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if((ucEQCRCStatus & _BIT1) == 0x00)
#else
        if((ucEQCRCStatus & _BIT2) == 0x00)
#endif
        {
            if((g_ucDpLane1FLDBandStatus & _BIT7) == 0x00)
            {
                g_ucDpLane1FLDBandStatus |= _BIT7;
                
                if(ucCounter == 5)
                {
                    g_ucDpLane1FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    g_ucDpLane1FLDBandStatus += ucCounter;
                }                         
            }
            else if((g_ucDpLane1FLDBandStatus & _BIT6) == _BIT6)
            {
                g_ucDpLane1FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                g_ucDpLane1FLDBandStatus += ucCounter;
            }
        }
        else
        {            
            if(((g_ucDpLane1FLDBandStatus & _BIT7) == _BIT7) && ((g_ucDpLane1FLDBandStatus & _BIT6) == 0x00))
            {
                g_ucDpLane1FLDBandStatus |= _BIT6;
                g_ucDpLane1FLDBandStatus += (ucCounter - 1);
            }
        }

        // Lane2 EQ-CRC Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if((ucEQCRCStatus & _BIT2) == 0x00)    
#else
        if((ucEQCRCStatus & _BIT1) == 0x00)
#endif
        {
            if((g_ucDpLane2FLDBandStatus & _BIT7) == 0x00)
            {
                g_ucDpLane2FLDBandStatus |= _BIT7;

                if(ucCounter == 5)
                {
                    g_ucDpLane2FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    g_ucDpLane2FLDBandStatus += ucCounter;
                }                        
            }
            else if((g_ucDpLane2FLDBandStatus & _BIT6) == _BIT6)
            {
                g_ucDpLane2FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                g_ucDpLane2FLDBandStatus += ucCounter;
            }
        }
        else
        {            
            if(((g_ucDpLane2FLDBandStatus & _BIT7) == _BIT7) && ((g_ucDpLane2FLDBandStatus & _BIT6) == 0x00))
            {
                g_ucDpLane2FLDBandStatus |= _BIT6;
                g_ucDpLane2FLDBandStatus += (ucCounter - 1);
            }
        }

        // Lane3 EQ-CRC Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if((ucEQCRCStatus & _BIT3) == 0x00)
#else
        if((ucEQCRCStatus & _BIT0) == 0x00)
#endif
        {
            if((g_ucDpLane3FLDBandStatus & _BIT7) == 0x00)
            {
                g_ucDpLane3FLDBandStatus |= _BIT7;
                
                if(ucCounter == 5)
                {
                    g_ucDpLane3FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    g_ucDpLane3FLDBandStatus += ucCounter;
                }                          
            }
            else if((g_ucDpLane3FLDBandStatus & _BIT6) == _BIT6)
            {
                g_ucDpLane3FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                g_ucDpLane3FLDBandStatus += ucCounter;
            }
        }
        else
        {                    
            if(((g_ucDpLane3FLDBandStatus & _BIT7) == _BIT7) && ((g_ucDpLane3FLDBandStatus & _BIT6) == 0x00))
            {
                g_ucDpLane3FLDBandStatus |= _BIT6;
                g_ucDpLane3FLDBandStatus += (ucCounter - 1);
            }
        }
    }    

    // [5] cp_en_manual = 0 --> Disable Manual Enable CP
    // [3] calib_manual = 0 --> Disable Calibration Manual    
    ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~(_BIT5 | _BIT3), 0x00);
        
    // Manual band
    if((g_ucDpLane0FLDBandStatus == 0) || ((g_ucDpLane0FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte_EXINT0(PB_DC_VCO_4, ScalerGetByte_EXINT0(PB_D8_VCO_0));            
    }
    else
    {
        ScalerSetByte_EXINT0(PB_DC_VCO_4, (ScalerGetByte_EXINT0(PB_D8_VCO_0) - 2 + (((g_ucDpLane0FLDBandStatus & 0x0F) + 1) / 2)));
    }

    // Manual band
    if((g_ucDpLane1FLDBandStatus == 0) || ((g_ucDpLane1FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte_EXINT0(PB_DD_VCO_5, ScalerGetByte_EXINT0(PB_D9_VCO_1));            
    }
    else
    {
        ScalerSetByte_EXINT0(PB_DD_VCO_5, (ScalerGetByte_EXINT0(PB_D9_VCO_1) - 2 + (((g_ucDpLane1FLDBandStatus & 0x0F) + 1) / 2)));
    }

    // Manual band
    if((g_ucDpLane2FLDBandStatus == 0) || ((g_ucDpLane2FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte_EXINT0(PB_DE_VCO_6, ScalerGetByte_EXINT0(PB_DA_VCO_2));            
    }
    else
    {
        ScalerSetByte_EXINT0(PB_DE_VCO_6, (ScalerGetByte_EXINT0(PB_DA_VCO_2) - 2 + (((g_ucDpLane2FLDBandStatus & 0x0F) + 1) / 2)));
    }

    // Manual band
    if((g_ucDpLane3FLDBandStatus == 0) || ((g_ucDpLane3FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte_EXINT0(PB_DF_VCO_7, ScalerGetByte_EXINT0(PB_DB_VCO_3));            
    }
    else
    {
        ScalerSetByte_EXINT0(PB_DF_VCO_7, (ScalerGetByte_EXINT0(PB_DB_VCO_3) - 2 + (((g_ucDpLane3FLDBandStatus & 0x0F) + 1) / 2)));     
    }

    // [5] cp_en_manual = 1 --> Manual Enable CP
    ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~_BIT5, _BIT5);

    // Waiting for VCO Stable
    for(g_ucDpTemp = 0; g_ucDpTemp <= 0; g_ucDpTemp++)
    {
        _nop_();
    }
    
    // [3] calib_manual = 1 --> Calibration Manual
    ScalerSetBit_EXINT0(PB_AF_RXMISC_2, ~_BIT3, _BIT3);   
}

//--------------------------------------------------
// Description  : Pre-Check Dp Training Pattern 1
// Input Value  : None
// Output Value : TRUE --> TP1 Pre-Check Pass
//--------------------------------------------------
BYTE ScalerDpTp1PreCheck_EXINT0(void) using 1
{
    switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & 0x1F)
    {               
        case _DP_FOUR_LANE:

            // Lane2 Check
            if((ScalerGetByte_EXINT0(PC_CE_LANE2_OUT) != 0x4A) && (ScalerGetByte_EXINT0(PC_CE_LANE2_OUT) != 0xB5))
            {
                return _FALSE;
            }
                                
            // Lane3 Check
            if((ScalerGetByte_EXINT0(PC_CF_LANE3_OUT) != 0x4A) && (ScalerGetByte_EXINT0(PC_CF_LANE3_OUT) != 0xB5))
            {
                return _FALSE;
            }
            
        case _DP_TWO_LANE:

            // Lane1 Check
            if((ScalerGetByte_EXINT0(PC_CD_LANE1_OUT) != 0x4A) && (ScalerGetByte_EXINT0(PC_CD_LANE1_OUT) != 0xB5))
            {
                return _FALSE;
            }                

        case _DP_ONE_LANE:    
        default:
            // Lane0 Check
            if((ScalerGetByte_EXINT0(PC_CC_LANE0_OUT) != 0x4A) && (ScalerGetByte_EXINT0(PC_CC_LANE0_OUT) != 0xB5))
            {
                return _FALSE;
            } 
            
            break;
    }
    
    return _TRUE; 
}

//--------------------------------------------------
// Description  : Check Dp Training Pattern 1
// Input Value  : Normal or Fake LT
// Output Value : TRUE --> TP1 Pass
//--------------------------------------------------
BYTE ScalerDpTp1Check_EXINT0(EnumDpLinkTrainingType enumDpLtType) using 1
{         
    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x00);
    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x00);                    
    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x80);

    if(enumDpLtType == _DP_NORMAL_LT)
    {
        if(GET_DP_LINK_TRAINING_STATUS() != _DP_NORMAL_TRAINING_PATTERN_1_FAIL)
        {            
            ScalerDpSetDpcdValue_EXINT0(0x00, 0x01, 0x03, 0x00);
            ScalerDpSetDpcdValue_EXINT0(0x00, 0x01, 0x04, 0x00);
            ScalerDpSetDpcdValue_EXINT0(0x00, 0x01, 0x05, 0x00);
            ScalerDpSetDpcdValue_EXINT0(0x00, 0x01, 0x06, 0x00);        
        }        

        g_ucDpLinkStatus01 = 0;
        g_ucDpLinkStatus23 = 0;
        g_ucDpLinkRequest01 = (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & 0x03) | ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) << 4) & 0x30);
        g_ucDpLinkRequest23 = (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & 0x03) | ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) << 4) & 0x30);
        
        switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & 0x1F)
        {               
            case _DP_FOUR_LANE:

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
                ScalerSetByte_EXINT0(P1D_F0_COEF_1, 0x40);
#else
                ScalerSetByte_EXINT0(P1D_F0_COEF_1, 0x80);
#endif
                // Lane2 Check
                if((ScalerGetByte_EXINT0(PC_CE_LANE2_OUT) == 0x4A) || (ScalerGetByte_EXINT0(PC_CE_LANE2_OUT) == 0xB5))
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & _BIT2) == _BIT2) || 
                        ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & (_BIT1 | _BIT0)) == (_BIT1 | _BIT0)) ||
                        ((ScalerGetByte_EXINT0(P1D_F1_COEF_2) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) >= 8))
                    {
                        g_ucDpLinkStatus23 = g_ucDpLinkStatus23 | 0x01;
                    }
                    else
                    {
                        g_ucDpLinkRequest23 = ((g_ucDpLinkRequest23 & 0xFC) | (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & (_BIT1 | _BIT0))) + 0x01;
                    }
                }
                else
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & _BIT2) != _BIT2) && 
                        ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpLinkRequest23 = ((g_ucDpLinkRequest23 & 0xFC) | (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & (_BIT1 | _BIT0))) + 0x01;
                    }
                }

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
                ScalerSetByte_EXINT0(P1D_F0_COEF_1, 0x00);
#else
                ScalerSetByte_EXINT0(P1D_F0_COEF_1, 0xC0);
#endif                
                // Lane3 Check
                if((ScalerGetByte_EXINT0(PC_CF_LANE3_OUT) == 0x4A) || (ScalerGetByte_EXINT0(PC_CF_LANE3_OUT) == 0xB5))
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) & _BIT2) == _BIT2) || 
                        ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) & (_BIT1 | _BIT0)) == (_BIT1 | _BIT0)) || 
                        ((ScalerGetByte_EXINT0(P1D_F1_COEF_2) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) >= 8))
                    {
                        g_ucDpLinkStatus23 = g_ucDpLinkStatus23 | 0x10;
                    }
                    else
                    {
                        g_ucDpLinkRequest23 = ((g_ucDpLinkRequest23 & 0xCF) | ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }
                }
                else
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) & _BIT2) != _BIT2) && 
                        ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpLinkRequest23 = ((g_ucDpLinkRequest23 & 0xCF) | ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }
                }
                
            case _DP_TWO_LANE:

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
                ScalerSetByte_EXINT0(P1D_F0_COEF_1, 0x80);
#else
                ScalerSetByte_EXINT0(P1D_F0_COEF_1, 0x40);
#endif
                // Lane1 Check
                if((ScalerGetByte_EXINT0(PC_CD_LANE1_OUT) == 0x4A) || (ScalerGetByte_EXINT0(PC_CD_LANE1_OUT) == 0xB5))
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & _BIT2) == _BIT2) || 
                       ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & (_BIT1 | _BIT0)) == (_BIT1 | _BIT0)) || 
                       ((ScalerGetByte_EXINT0(P1D_F1_COEF_2) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) >= 8))
                    {                    
                        g_ucDpLinkStatus01 = g_ucDpLinkStatus01 | 0x10;
                    }
                    else
                    {
                        g_ucDpLinkRequest01 = ((g_ucDpLinkRequest01 & 0xCF) | ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }    
                }
                else
                { 
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & _BIT2) != _BIT2) && 
                        ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpLinkRequest01 = ((g_ucDpLinkRequest01 & 0xCF) | ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }
                }                

            case _DP_ONE_LANE:    
            default:

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
                ScalerSetByte_EXINT0(P1D_F0_COEF_1, 0xC0);
#else
                ScalerSetByte_EXINT0(P1D_F0_COEF_1, 0x00);
#endif                                                
                // Lane0 Check
                if((ScalerGetByte_EXINT0(PC_CC_LANE0_OUT) == 0x4A) || (ScalerGetByte_EXINT0(PC_CC_LANE0_OUT) == 0xB5))
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & _BIT2) == _BIT2) || 
                        ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT1 | _BIT0)) == (_BIT1 | _BIT0)) || 
                        ((ScalerGetByte_EXINT0(P1D_F1_COEF_2) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) >= 8))
                        
                    {
                           g_ucDpLinkStatus01 = g_ucDpLinkStatus01 | 0x01;
                    }
                    else
                    {
                           g_ucDpLinkRequest01 = ((g_ucDpLinkRequest01 & 0xFC) | (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT1 | _BIT0))) + 0x01;
                    }
                }
                else
                {                   
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & _BIT2) != _BIT2) && 
                        ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpLinkRequest01 = ((g_ucDpLinkRequest01 & 0xFC) | (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT1 | _BIT0))) + 0x01;
                    }
                }

                break;
        }     

        ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, g_ucDpLinkStatus01);
        ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x03, g_ucDpLinkStatus23);
        ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpLinkRequest01);
        ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x07, g_ucDpLinkRequest23);  

        switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & 0x1F)
        {               
            case _DP_ONE_LANE:

                if((g_ucDpLinkStatus01 & _BIT0) == _BIT0)
                {
                    return _TRUE;
                }

                break;
                
            case _DP_TWO_LANE:

                if((g_ucDpLinkStatus01 & (_BIT4 | _BIT0)) == (_BIT4 | _BIT0))
                {
                    return _TRUE;
                }
                
                break;

            case _DP_FOUR_LANE:
            default:

                if(((g_ucDpLinkStatus01 & (_BIT4 | _BIT0)) == (_BIT4 | _BIT0)) && (((g_ucDpLinkStatus23 & (_BIT4 | _BIT0)) == (_BIT4 | _BIT0))))
                {
                    return _TRUE;
                }
                
                break;                
        }         
    }
    else
    {        
        if(GET_DP_LINK_TRAINING_STATUS() != _DP_FAKE_TRAINING_PATTERN_1_FAIL)
        {
            ScalerDpSetDpcdValue_EXINT0(0x00, 0x01, 0x03, 0x00);
            ScalerDpSetDpcdValue_EXINT0(0x00, 0x01, 0x04, 0x00);
            ScalerDpSetDpcdValue_EXINT0(0x00, 0x01, 0x05, 0x00);
            ScalerDpSetDpcdValue_EXINT0(0x00, 0x01, 0x06, 0x00);        
        } 
        
        switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & 0x1F)
        {               
            case _DP_ONE_LANE:

                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x06, 0x02);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x00);
                
                if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & _BIT2) == _BIT2) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT1 | _BIT0)) == (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT1 | _BIT0))))
                {
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x01);
                                        
                    return _TRUE;
                }

                break;
                
            case _DP_TWO_LANE:

                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x06, 0x22);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x00);

                if((((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & _BIT2) == _BIT2) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT1 | _BIT0)) == (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT1 | _BIT0))))
                && (((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & _BIT2) == _BIT2) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & (_BIT1 | _BIT0)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) >> 4) & (_BIT1 | _BIT0)))))
                {
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x11);

                    return _TRUE;
                }

                
                break;

            case _DP_FOUR_LANE:
            default:

                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x06, 0x22);              
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x22);              

                if((((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & _BIT2) == _BIT2) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT1 | _BIT0)) == (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT1 | _BIT0))))
                && (((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & _BIT2) == _BIT2) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & (_BIT1 | _BIT0)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) >> 4) & (_BIT1 | _BIT0))))
                && (((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & _BIT2) == _BIT2) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & (_BIT1 | _BIT0)) == (ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x07) & (_BIT1 | _BIT0))))
                &&(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) & _BIT2) == _BIT2) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) & (_BIT1 | _BIT0)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x07) >> 4) & (_BIT1 | _BIT0)))))
                {
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x11);
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x11);

                    return _TRUE;
                }
                
                break;                
        }
    }    

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Dp Training Pattern 2
// Input Value  : Normal or Fake LT
// Output Value : TRUE --> TP2 Pass
//--------------------------------------------------
BYTE ScalerDpTp2Check_EXINT0(EnumDpLinkTrainingType enumDpLtType) using 1
{
    BYTE ucEQCRCStatus = 0;
    
    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x80);

    if(enumDpLtType == _DP_NORMAL_LT)
    {
        g_ucDpLinkRequest01 = ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & 0x03) | 
                              ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) >> 1) & 0x0C) | 
                              ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) << 4) & 0x30) | 
                              ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) << 3) & 0xC0));
        
        g_ucDpLinkRequest23 = ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & 0x03) | 
                              ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) >> 1) & 0x0C) | 
                              ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) << 4) & 0x30) | 
                              ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) << 3) & 0xC0));
        
        // Enable EQ-CRC and Clear EQ-CRC Status
        ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ScalerSetByte_EXINT0(PC_B4_DP_DATA_PORT, 0x8F);     
        ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ScalerSetByte_EXINT0(PC_B4_DP_DATA_PORT, 0x8F); 
        
        for(g_ucDpTemp = 0; g_ucDpTemp <= 2; g_ucDpTemp++)
        {
            _nop_();
        }        

        ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ucEQCRCStatus = ScalerGetByte_EXINT0(PC_B4_DP_DATA_PORT);

        // Disable EQ-CRC
        ScalerSetByte_EXINT0(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ScalerSetByte_EXINT0(PC_B4_DP_DATA_PORT, 0x0F);                
      
        switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & 0x1F)
        {               
            case _DP_FOUR_LANE:

                // Lane2 EQ-CRC Check
                if((ucEQCRCStatus & _BIT1) == 0x00)
                {
                    g_ucDpLinkStatus23 = g_ucDpLinkStatus23 | 0x07;
                }
                else
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & _BIT5) != _BIT5) && 
                        (((g_ucDpLinkRequest23 & 0x03) + ((g_ucDpLinkRequest23 >> 2) & 0x03)) < 3)) 
                    {
                        g_ucDpLinkRequest23 = g_ucDpLinkRequest23 + 0x04;
                    }
                }

                // Lane3 EQ-CRC Check
                if((ucEQCRCStatus & _BIT0) == 0x00)
                {
                    g_ucDpLinkStatus23 = g_ucDpLinkStatus23 | 0x70;
                }
                else
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) & _BIT5) != _BIT5) && 
                        ((((g_ucDpLinkRequest23 >> 4) & 0x03) + ((g_ucDpLinkRequest23 >> 6) & 0x03)) < 3)) 
                    {
                        g_ucDpLinkRequest23 = g_ucDpLinkRequest23 + 0x40;
                    }
                }
                                
            case _DP_TWO_LANE:

                // Lane1 EQ-CRC Check
                if((ucEQCRCStatus & _BIT2) == 0x00)
                {
                    g_ucDpLinkStatus01 = g_ucDpLinkStatus01 | 0x70;
                }
                else
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & _BIT5) != _BIT5) && 
                        ((((g_ucDpLinkRequest01 >> 4) & 0x03) + ((g_ucDpLinkRequest01 >> 6) & 0x03)) < 3)) 
                    {
                        g_ucDpLinkRequest01 = g_ucDpLinkRequest01 + 0x40;
                    }
                }
                
            default:

                // Lane0 EQ-CRC Check
                if((ucEQCRCStatus & _BIT3) == 0x00)
                {
                    g_ucDpLinkStatus01 = g_ucDpLinkStatus01 | 0x07;
                }
                else
                {
                    if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & _BIT5) != _BIT5) && 
                        (((g_ucDpLinkRequest01 & 0x03) + ((g_ucDpLinkRequest01 >> 2) & 0x03)) < 3)) 
                    {
                        g_ucDpLinkRequest01 = g_ucDpLinkRequest01 + 0x04;
                    }                 
                }
                
                break;
        }     

        ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, g_ucDpLinkStatus01);
        ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x03, g_ucDpLinkStatus23);
        ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpLinkRequest01);
        ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x07, g_ucDpLinkRequest23);  

        switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & 0x1F)
        {               
            case _DP_ONE_LANE:

                if((g_ucDpLinkStatus01 & 0x07) == 0x07)
                {
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);
                    return _TRUE;
                }

                break;
                
            case _DP_TWO_LANE:

                if((g_ucDpLinkStatus01 & 0x77) == 0x77)
                {
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);                    
                    return _TRUE;
                }
                
                break;

            case _DP_FOUR_LANE:
            default:

                if(((g_ucDpLinkStatus01 & 0x77) == 0x77) && (((g_ucDpLinkStatus23 & 0x77) == 0x77)))
                {
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);                    
                    return _TRUE;
                }
                
                break;                
        }                             
    }
    else
    {
        ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x80);        

        switch(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & 0x1F)
        {               
            case _DP_ONE_LANE:

                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x01);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x00);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x06, 0x02);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x00);
                
                if(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & _BIT5) == _BIT5) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT4 | _BIT3)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) << 1) & (_BIT4 | _BIT3))))
                {
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x07);
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);                                        
                    
                    return _TRUE;
                }

                break;
                
            case _DP_TWO_LANE:

                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x11);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x00);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x06, 0x22);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x00);

                if((((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & _BIT5) == _BIT5) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT4 | _BIT3)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) << 1) & (_BIT4 | _BIT3))))
                && (((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & _BIT5) == _BIT5) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & (_BIT4 | _BIT3)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) >> 3) & (_BIT4 | _BIT3)))))
                {
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x77);
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);

                    return _TRUE;
                }

                
                break;

            case _DP_FOUR_LANE:
            default:

                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x11);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x11);
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x06, 0x22);              
                ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x22);              

                if((((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & _BIT5) == _BIT5) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x03) & (_BIT4 | _BIT3)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) << 1) & (_BIT4 | _BIT3))))
                && (((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & _BIT5) == _BIT5) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x04) & (_BIT4 | _BIT3)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x06) >> 3) & (_BIT4 | _BIT3))))
                && (((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & _BIT5) == _BIT5) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x05) & (_BIT4 | _BIT3)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x07) << 1) & (_BIT4 | _BIT3))))
                &&(((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) & _BIT5) == _BIT5) || ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x06) & (_BIT4 | _BIT3)) == ((ScalerDpGetDpcdInfo_EXINT0(0x00, 0x02, 0x07) >> 3) & (_BIT4 | _BIT3)))))
                {
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x77);
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x77);
                    ScalerDpSetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);

                    return _TRUE;
                }
                
                break;
        }       
    }    

    return _FALSE;
}

//--------------------------------------------------
// Description  : Rebuilding DP PHY
// Input Value  : DPCD Bit Rate and Lane Count
// Output Value : None
//--------------------------------------------------
void ScalerDpRebuildPhy(BYTE ucDpcdRate, BYTE ucDpcdLane)
{
    ///////////////////////////
    // RX CMU EN & Mac Power //
    ///////////////////////////
    
    // Disable RX_EN and CMU_EN
    ScalerSetByte(PB_B4_POWER_0, 0x00);

    // Disable Auto k-offset(foreground)
    ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);   
        
    // Dual Mode Disable and Analog Select to DP
    ScalerSetBit(PB_AC_CDR_A, ~(_BIT3 | _BIT4), _BIT4);            

    // Digital PHY Select to DP
    ScalerSetBit(PB_E0_DIG00, ~_BIT4, 0x00);
    
    switch(ucDpcdLane & 0x1F)
    {               
        case _DP_ONE_LANE:

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
            ScalerSetByte(PB_B4_POWER_0, 0x88);
#else
            ScalerSetByte(PB_B4_POWER_0, 0x11);
#endif            
            ScalerSetBit(PC_A1_DP_CTL, ~(_BIT4 | _BIT3), _BIT3);
                            
            break;
            
        case _DP_TWO_LANE:

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
            ScalerSetByte(PB_B4_POWER_0, 0xCC);
#else
            ScalerSetByte(PB_B4_POWER_0, 0x33);
#endif
            ScalerSetBit(PC_A1_DP_CTL, ~(_BIT4 | _BIT3), _BIT4);
            
            break;

        case _DP_FOUR_LANE:    
        default:

            ScalerSetByte(PB_B4_POWER_0, 0xFF);
            
            ScalerSetBit(PC_A1_DP_CTL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
            
            break;
    }


    /////////////////
    // CDR Setting //
    /////////////////

    if(ucDpcdRate == 0x0A) // HBR
    {        
        // [7:6] High Bit Rate(2.7G)
        ScalerSetBit(PB_AC_CDR_A, ~(_BIT6 | _BIT7), _BIT6);

        // [7:6] vco_div = 00 VCO/1
        // [5] sel_bb = 1 BB PD
        // [4] sel_half = 1 full rate
        // [1:0] kvco = 1 526MHz/V
        ScalerSetByte(PB_A5_CDR_3, 0x31);

        // [7:4] cp_sel = 0001 7.5uA
        // [3:1] cpsr = 101 1k
        ScalerSetByte(PB_A6_CDR_4, 0x1A);
    }
    else // RBR
    {        
        // [7:6] Low Bit rate(1.62G)
        ScalerSetBit(PB_AC_CDR_A, ~(_BIT6 | _BIT7), 0x00);

        // [7:6] vco_div = 01 VCO/2
        // [5] sel_bb = 1 BB PD
        // [4] sel_half = 1 half rate
        // [1:0] kvco = 1 526MHz/V
        ScalerSetByte(PB_A5_CDR_3, 0x71);

        // [7:4] cp_sel = 0001 7.5uA
        // [3:1] cpsr = 000 2k
        ScalerSetByte(PB_A6_CDR_4, 0x10);
    }

    // Xtal lock FLD  
    ScalerSetBit(PB_AB_CDR_9, ~_BIT6, _BIT6);

    // For RBR
    ScalerSetBit(PB_C8_FLD_CONT_0, ~(_BIT7 | _BIT6), _BIT7);
    ScalerSetByte(PB_C9_FLD_CONT_1, 0x2B);
    ScalerSetByte(PB_CA_FLD_CONT_2, 0x31);
       
    // For HBR
    ScalerSetBit(PB_CB_FLD_CONT_3, ~(_BIT7 | _BIT6), _BIT7);
    ScalerSetByte(PB_CC_FLD_CONT_4, 0x2B);
    ScalerSetByte(PB_CD_FLD_CONT_5, 0x1D);        


    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // [7] FLD Auto Mode
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT7, _BIT7);

    // [4] Enable cp_adj_en : Add CP Current During FLD Lock Band
    // [3] Enable Adaptation when FLD Auto Mode
    ScalerSetBit(PB_AD_RXMISC_0, ~(_BIT4 | _BIT3), _BIT4); 
   
    // Enable Commoa Detection
    ScalerSetBit(PB_E2_DIG02, ~_BIT6, 0x00);
    
    if((ucDpcdLane & _BIT7) == _BIT7)
    {
        // Enable Enhancement Control Mode --> Digital PHY
        ScalerSetBit(PB_E0_DIG00, ~_BIT5, _BIT5);

        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit(PC_A1_DP_CTL, ~_BIT2, _BIT2);
    }
    else
    {
        // Enable Enhancement Control Mode --> Digital PHY
        ScalerSetBit(PB_E0_DIG00, ~_BIT5, 0x00);

        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit(PC_A1_DP_CTL, ~_BIT2, 0x00);
    }        

    
    /////////////////
    // DFE Setting //
    /////////////////   

    // Set DFE Initial
    if(ucDpcdRate == 0x0A)
    {
        ScalerDpSetDFEInitial(_DP_LINK_HBR);
    }
    else
    {
        ScalerDpSetDFEInitial(_DP_LINK_RBR);
    }

    
    //////////////
    // K Offset //
    ////////////// 

    // [5] Foreground Calibration Auto Mode
    ScalerSetBit(PB_B2_EQ_2, ~(_BIT6 | _BIT5), _BIT5);

    // [6] Enable offset Calibration
    ScalerSetBit(PB_B2_EQ_2, ~_BIT6, _BIT6);
    
    // Waiting for K Offset 
    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        _nop_();
    } 

    
    ///////////////
    // FLD Reset //
    /////////////// 
    
    // FLD Reset
    ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT0, 0x00);
    ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT0, _BIT0);

    // Enable DFE Adpatation
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0xE7);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0xE7);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0xE7);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0xE7);

    // Waiting for the FLD Band Searching
    for(pData[0] = 0; pData[0] <= 100; pData[0]++)
    {
        _nop_();
    }

    // Disable Adaptation 
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);  
    
    // Reload Tap0 to Initial Value
    ScalerSetByte(P1D_A4_L0_INIT_2, 0x15);
    ScalerSetByte(P1D_B4_L1_INIT_2, 0x15);
    ScalerSetByte(P1D_C4_L2_INIT_2, 0x15); 
    ScalerSetByte(P1D_D4_L3_INIT_2, 0x15);
        
    ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT0, _BIT0);
    ScalerSetBit(P1D_BA_L1_INIT_8, ~_BIT0, _BIT0);
    ScalerSetBit(P1D_CA_L2_INIT_8, ~_BIT0, _BIT0);
    ScalerSetBit(P1D_DA_L3_INIT_8, ~_BIT0, _BIT0);

    ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT0, 0x00); 
    ScalerSetBit(P1D_BA_L1_INIT_8, ~_BIT0, 0x00); 
    ScalerSetBit(P1D_CA_L2_INIT_8, ~_BIT0, 0x00); 
    ScalerSetBit(P1D_DA_L3_INIT_8, ~_BIT0, 0x00);

    // [4] Disable cp_adj_en : Add CP Current During FLD Lock Band
    // [3] Disable Adaptation when FLD Auto Mode
    ScalerSetBit(PB_AD_RXMISC_0, ~(_BIT4 | _BIT3), _BIT3); 

    // DP Mac Clock Select to Link Clock
    ScalerSetBit(PC_F6_AUX_ERROR_HANDLE2, ~_BIT4, 0x00);            


    //////////////
    // K Offset //
    //////////////    

    // [5] Foreground Calibration Auto Mode
    ScalerSetBit(PB_B2_EQ_2, ~(_BIT6 | _BIT5), _BIT5);

    // [6] Enable offset Calibration
    ScalerSetBit(PB_B2_EQ_2, ~_BIT6, _BIT6);
    
    // Waiting for K Offset 
    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        _nop_();
    } 

    ScalerDpRebuildPhyFLDBandDetect();
}

//--------------------------------------------------
// Description  : DP FLD Band Detection Rebuild PHY
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRebuildPhyFLDBandDetect(void)
{
    BYTE ucCounter = 0;
    BYTE ucDpLane0FLDBandStatus = 0;
    BYTE ucDpLane1FLDBandStatus = 0;
    BYTE ucDpLane2FLDBandStatus = 0;
    BYTE ucDpLane3FLDBandStatus = 0;       
    
    // Reload Auto Band to Manual Band
    ScalerSetByte(PB_DC_VCO_4, ScalerGetByte(PB_D8_VCO_0));
    ScalerSetByte(PB_DD_VCO_5, ScalerGetByte(PB_D9_VCO_1));
    ScalerSetByte(PB_DE_VCO_6, ScalerGetByte(PB_DA_VCO_2));
    ScalerSetByte(PB_DF_VCO_7, ScalerGetByte(PB_DB_VCO_3));

    // [7] auto_mode = 0 FLD Manual Mode
    // [4] adp_en_manual = 0 --> Disable  adaptation.
    ScalerSetBit(PB_AF_RXMISC_2, ~(_BIT7 | _BIT4), 0x00);

    for(ucCounter = 0; ucCounter <= 5; ucCounter++)
    {        
        // [5] cp_en_manual = 0 --> Disable Manual Enable CP
        // [3] calib_manual = 0 --> Disable Calibration Manual    
        ScalerSetBit(PB_AF_RXMISC_2, ~(_BIT5 | _BIT3), 0x00);
        
        // Manual band 
        ScalerSetByte(PB_DC_VCO_4, (ScalerGetByte(PB_D8_VCO_0) - 2 + ucCounter));
        ScalerSetByte(PB_DD_VCO_5, (ScalerGetByte(PB_D9_VCO_1) - 2 + ucCounter));
        ScalerSetByte(PB_DE_VCO_6, (ScalerGetByte(PB_DA_VCO_2) - 2 + ucCounter));
        ScalerSetByte(PB_DF_VCO_7, (ScalerGetByte(PB_DB_VCO_3) - 2 + ucCounter));

        // [5] cp_en_manual = 1 --> Manual Enable CP         
        ScalerSetBit(PB_AF_RXMISC_2, ~_BIT5, _BIT5);

        // Waiting for VCO Stable
        for(pData[0] = 0; pData[0] <= 2; pData[0]++)
        {
            _nop_();
        }        
        
        // [3] calib_manual = 1 --> Calibration Manual   
        ScalerSetBit(PB_AF_RXMISC_2, ~_BIT3, _BIT3);

        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            _nop_();
        }        
                
        // Clear 8b/10b Decode Error Flag
        ScalerSetBit(PC_A5_DP_LANE_VALID, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
      
        for(pData[0] = 0; pData[0] <= 6; pData[0]++)
        {
            _nop_();
        }

        // Lane0 8b/10b Decode Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)        
        if(ScalerGetBit(PC_A5_DP_LANE_VALID, _BIT0) == 0x00)
#else
        if(ScalerGetBit(PC_A5_DP_LANE_VALID, _BIT3) == 0x00)
#endif
        {
            if((ucDpLane0FLDBandStatus & _BIT7) == 0x00)
            {
                ucDpLane0FLDBandStatus |= _BIT7;
                
                if(ucCounter == 5)
                {
                    ucDpLane0FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    ucDpLane0FLDBandStatus += ucCounter;
                }  
            }
            else if((ucDpLane0FLDBandStatus & _BIT6) == _BIT6)
            {
                ucDpLane0FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                ucDpLane0FLDBandStatus += ucCounter;
            }
        }
        else
        {
            if(((ucDpLane0FLDBandStatus & _BIT7) == _BIT7) && ((ucDpLane0FLDBandStatus & _BIT6) == 0x00))
            {
                ucDpLane0FLDBandStatus |= _BIT6;
                ucDpLane0FLDBandStatus += (ucCounter - 1);
            }
        }             

        // Lane1 8b/10b Decode Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if(ScalerGetBit(PC_A5_DP_LANE_VALID, _BIT1) == 0x00)
#else
        if(ScalerGetBit(PC_A5_DP_LANE_VALID, _BIT2) == 0x00)
#endif
        {
            if((ucDpLane1FLDBandStatus & _BIT7) == 0x00)
            {
                ucDpLane1FLDBandStatus |= _BIT7;
                
                if(ucCounter == 5)
                {
                    ucDpLane1FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    ucDpLane1FLDBandStatus += ucCounter;
                }                         
            }
            else if((ucDpLane1FLDBandStatus & _BIT6) == _BIT6)
            {
                ucDpLane1FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                ucDpLane1FLDBandStatus += ucCounter;
            }
        }
        else
        {            
            if(((ucDpLane1FLDBandStatus & _BIT7) == _BIT7) && ((ucDpLane1FLDBandStatus & _BIT6) == 0x00))
            {
                ucDpLane1FLDBandStatus |= _BIT6;
                ucDpLane1FLDBandStatus += (ucCounter - 1);
            }
        }

        // Lane2 8b/10b Decode Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)        
        if(ScalerGetBit(PC_A5_DP_LANE_VALID, _BIT2) == 0x00)
#else
        if(ScalerGetBit(PC_A5_DP_LANE_VALID, _BIT1) == 0x00)
#endif
        {
            if((ucDpLane2FLDBandStatus & _BIT7) == 0x00)
            {
                ucDpLane2FLDBandStatus |= _BIT7;

                if(ucCounter == 5)
                {
                    ucDpLane2FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    ucDpLane2FLDBandStatus += ucCounter;
                }                        
            }
            else if((ucDpLane2FLDBandStatus & _BIT6) == _BIT6)
            {
                ucDpLane2FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                ucDpLane2FLDBandStatus += ucCounter;
            }
        }
        else
        {            
            if(((ucDpLane2FLDBandStatus & _BIT7) == _BIT7) && ((ucDpLane2FLDBandStatus & _BIT6) == 0x00))
            {
                ucDpLane2FLDBandStatus |= _BIT6;
                ucDpLane2FLDBandStatus += (ucCounter - 1);
            }
        }

        // Lane3 8b/10b Decode Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if(ScalerGetBit(PC_A5_DP_LANE_VALID, _BIT3) == 0x00)
#else
        if(ScalerGetBit(PC_A5_DP_LANE_VALID, _BIT0) == 0x00)
#endif
        {
            if((ucDpLane3FLDBandStatus & _BIT7) == 0x00)
            {
                ucDpLane3FLDBandStatus |= _BIT7;
                
                if(ucCounter == 5)
                {
                    ucDpLane3FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    ucDpLane3FLDBandStatus += ucCounter;
                }                          
            }
            else if((ucDpLane3FLDBandStatus & _BIT6) == _BIT6)
            {
                ucDpLane3FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                ucDpLane3FLDBandStatus += ucCounter;
            }
        }
        else
        {                    
            if(((ucDpLane3FLDBandStatus & _BIT7) == _BIT7) && ((ucDpLane3FLDBandStatus & _BIT6) == 0x00))
            {
                ucDpLane3FLDBandStatus |= _BIT6;
                ucDpLane3FLDBandStatus += (ucCounter - 1);
            }
        }
    }    

    // [5] cp_en_manual = 0 --> Disable Manual Enable CP
    // [3] calib_manual = 0 --> Disable Calibration Manual    
    ScalerSetBit(PB_AF_RXMISC_2, ~(_BIT5 | _BIT3), 0x00);
        
    // Manual band
    if((ucDpLane0FLDBandStatus == 0) || ((ucDpLane0FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte(PB_DC_VCO_4, ScalerGetByte(PB_D8_VCO_0));            
    }
    else
    {
        ScalerSetByte(PB_DC_VCO_4, (ScalerGetByte(PB_D8_VCO_0) - 2 + (((ucDpLane0FLDBandStatus & 0x0F) + 1) / 2)));
    }

    // Manual band
    if((ucDpLane1FLDBandStatus == 0) || ((ucDpLane1FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte(PB_DD_VCO_5, ScalerGetByte(PB_D9_VCO_1));            
    }
    else
    {
        ScalerSetByte(PB_DD_VCO_5, (ScalerGetByte(PB_D9_VCO_1) - 2 + (((ucDpLane1FLDBandStatus & 0x0F) + 1) / 2)));
    }

    // Manual band
    if((ucDpLane2FLDBandStatus == 0) || ((ucDpLane2FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte(PB_DE_VCO_6, ScalerGetByte(PB_DA_VCO_2));            
    }
    else
    {
        ScalerSetByte(PB_DE_VCO_6, (ScalerGetByte(PB_DA_VCO_2) - 2 + (((ucDpLane2FLDBandStatus & 0x0F) + 1) / 2)));
    }

    // Manual band
    if((ucDpLane3FLDBandStatus == 0) || ((ucDpLane3FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte(PB_DF_VCO_7, ScalerGetByte(PB_DB_VCO_3));            
    }
    else
    {
        ScalerSetByte(PB_DF_VCO_7, (ScalerGetByte(PB_DB_VCO_3) - 2 + (((ucDpLane3FLDBandStatus & 0x0F) + 1) / 2)));     
    }

    // [5] cp_en_manual = 1 --> Manual Enable CP         
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT5, _BIT5);

    // Waiting for VCO Stable
    for(pData[0] = 0; pData[0] <= 2; pData[0]++)
    {
        _nop_();
    }        
    
    // [3] calib_manual = 1 --> Calibration Manual   
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT3, _BIT3);

    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        _nop_();
    }  
}

//--------------------------------------------------
// Description  : DP PHY DFE Initial Setting in TP2
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpSetDFEInitial_EXINT0(void) using 1
{        
    // Disable DFE Adaptation
    ScalerSetByte_EXINT0(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte_EXINT0(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte_EXINT0(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte_EXINT0(P1D_D1_L3_DFE_EN_2, 0x00);

    // [7] Positive Symbol-Rate Clock
    // [6] Enable Timer Control DFE Loop
    // [5:4] No Reduce Gain
    // [3] Disable Running Length Detection
    // [2] bypass Blank out Case-3 Symbol
    ScalerSetBit_EXINT0(P1D_A0_L0_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT6);
    ScalerSetBit_EXINT0(P1D_B0_L1_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT6);
    ScalerSetBit_EXINT0(P1D_C0_L2_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT6);
    ScalerSetBit_EXINT0(P1D_D0_L3_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT6);

    // [7:6] adapt_mode[1:0] = 2'b11 --> adapt_mode mode 3¡CAmplitude-based adaptation without independent LE loop      
    // [5] edge_det_mode =1 -->  Edge lead or lag data (0 : Edge lead data, 1 : Edge lag data)                                                                                                                                        
    // [4] transition_only = 0->1 -->  only transition bit is effective                                                                                                                                                                        
    // [3] le_auto_reload = 0 --> Enable auto-reload le coefficient when max-tap0 & max-le   
    // [2:0] Delay Time of Tap1+LE Loop After Tuning on Tap0
    ScalerSetBit_EXINT0(P1D_E0_MODE_TIMER, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0) , (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT1)); 
                                                                                                                                                                                                                      
    // Set DFE Delay Time
    ScalerSetByte_EXINT0(P1D_E1_TIMER, 0x01);    
    
    // Filter's Gain of Tap0/1
    ScalerSetBit_EXINT0(P1D_E2_GAIN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT4));

    // Filter's Gain of Tap2
    ScalerSetBit_EXINT0(P1D_E3_GAIN_2, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));

    // Filter's Gain of Servo-loop
    ScalerSetBit_EXINT0(P1D_E4_GAIN_3, ~(_BIT4 | _BIT3 | _BIT2), (_BIT3 | _BIT2));

    // Set Vth/Tap0/Tap1/Tap2 Max and Min Value
    ScalerSetByte_EXINT0(P1D_E6_LIMIT_1, 0xF5);
    ScalerSetByte_EXINT0(P1D_E7_LIMIT_2, 0xEE);
    ScalerSetByte_EXINT0(P1D_E8_LIMIT_3, 0x56);
    ScalerSetBit_EXINT0(P1D_E9_LIMIT_4, ~(_BIT7 | _BIT6), _BIT6);
    
    // Set Vth/Servo-loop/Tap Divider 
    ScalerSetByte_EXINT0(P1D_EC_LOOP_DIV_1, 0xA3);
    ScalerSetByte_EXINT0(P1D_ED_LOOP_DIV_2, 0xCA);


    /////////////////////////
    // DFE Code Initialize //
    /////////////////////////

    if(ScalerDpGetDpcdInfo_EXINT0(0x00, 0x01, 0x00) == 0x0A) // HBR
    {                                                
        ScalerSetByte_EXINT0(P1D_A2_L0_LIMIT_INIT, 0xFF); 
        ScalerSetByte_EXINT0(P1D_B2_L1_LIMIT_INIT, 0xFF); 
        ScalerSetByte_EXINT0(P1D_C2_L2_LIMIT_INIT, 0xFF); 
        ScalerSetByte_EXINT0(P1D_D2_L3_LIMIT_INIT, 0xFF); 

        ScalerSetByte_EXINT0(P1D_A3_L0_INIT_1, 0x0F); 
        ScalerSetByte_EXINT0(P1D_B3_L1_INIT_1, 0x0F); 
        ScalerSetByte_EXINT0(P1D_C3_L2_INIT_1, 0x0F); 
        ScalerSetByte_EXINT0(P1D_D3_L3_INIT_1, 0x0F); 
    }                                                                                                            
    else // RBR
    {                                                
        ScalerSetByte_EXINT0(P1D_A2_L0_LIMIT_INIT, 0x3F); 
        ScalerSetByte_EXINT0(P1D_B2_L1_LIMIT_INIT, 0x3F); 
        ScalerSetByte_EXINT0(P1D_C2_L2_LIMIT_INIT, 0x3F); 
        ScalerSetByte_EXINT0(P1D_D2_L3_LIMIT_INIT, 0x3F);

        ScalerSetByte_EXINT0(P1D_A3_L0_INIT_1, 0x8F); 
        ScalerSetByte_EXINT0(P1D_B3_L1_INIT_1, 0x8F); 
        ScalerSetByte_EXINT0(P1D_C3_L2_INIT_1, 0x8F); 
        ScalerSetByte_EXINT0(P1D_D3_L3_INIT_1, 0x8F);     
    }

    ScalerSetByte_EXINT0(P1D_A4_L0_INIT_2, 0x15);
    ScalerSetByte_EXINT0(P1D_B4_L1_INIT_2, 0x15);
    ScalerSetByte_EXINT0(P1D_C4_L2_INIT_2, 0x15); 
    ScalerSetByte_EXINT0(P1D_D4_L3_INIT_2, 0x15);    
     
    ScalerSetByte_EXINT0(P1D_A5_L0_INIT_3, 0x0C); 
    ScalerSetByte_EXINT0(P1D_B5_L1_INIT_3, 0x0C); 
    ScalerSetByte_EXINT0(P1D_C5_L2_INIT_3, 0x0C); 
    ScalerSetByte_EXINT0(P1D_D5_L3_INIT_3, 0x0C);  

    ScalerSetByte_EXINT0(P1D_A6_L0_INIT_4, 0x00); 
    ScalerSetByte_EXINT0(P1D_B6_L1_INIT_4, 0x00); 
    ScalerSetByte_EXINT0(P1D_C6_L2_INIT_4, 0x00); 
    ScalerSetByte_EXINT0(P1D_D6_L3_INIT_4, 0x00); 
                         
    ScalerSetByte_EXINT0(P1D_A9_L0_INIT_7, 0x08); 
    ScalerSetByte_EXINT0(P1D_B9_L1_INIT_7, 0x08); 
    ScalerSetByte_EXINT0(P1D_C9_L2_INIT_7, 0x08); 
    ScalerSetByte_EXINT0(P1D_D9_L3_INIT_7, 0x08); 
    
    // Load Intial DFE Code
    ScalerSetByte_EXINT0(P1D_AA_L0_INIT_8, 0xFF);
    ScalerSetByte_EXINT0(P1D_BA_L1_INIT_8, 0xFF);
    ScalerSetByte_EXINT0(P1D_CA_L2_INIT_8, 0xFF);
    ScalerSetByte_EXINT0(P1D_DA_L3_INIT_8, 0xFF);

    ScalerSetByte_EXINT0(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte_EXINT0(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte_EXINT0(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte_EXINT0(P1D_DA_L3_INIT_8, 0x00);   

    // DFE Loop Normal
    ScalerSetBit_EXINT0(P1D_EF_RESET_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));   
}

//--------------------------------------------------
// Description  : DP PHY DFE Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpSetDFEInitial(EnumDpLinkRate enumDpLinkRate)
{        
    // Disable DFE Adaptation
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);

    // [7] Positive Symbol-Rate Clock
    // [6] Enable Timer Control DFE Loop
    // [5:4] No Reduce Gain
    // [3] Disable Running Length Detection
    // [2] bypass Blank out Case-3 Symbol
    ScalerSetBit(P1D_A0_L0_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT6);
    ScalerSetBit(P1D_B0_L1_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT6);
    ScalerSetBit(P1D_C0_L2_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT6);
    ScalerSetBit(P1D_D0_L3_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT6);

    // [7:6] adapt_mode[1:0] = 2'b11 --> adapt_mode mode 3¡CAmplitude-based adaptation without independent LE loop      
    // [5] edge_det_mode =1 -->  Edge lead or lag data (0 : Edge lead data, 1 : Edge lag data)                                                                                                                                        
    // [4] transition_only = 0->1 -->  only transition bit is effective                                                                                                                                                                        
    // [3] le_auto_reload = 0 --> Enable auto-reload le coefficient when max-tap0 & max-le   
    // [2:0] Delay Time of Tap1+LE Loop After Tuning on Tap0
    ScalerSetBit(P1D_E0_MODE_TIMER, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0) , (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT1)); 
                                                                                                                                                                                                                      
    // Set DFE Delay Time
    ScalerSetByte(P1D_E1_TIMER, 0x01);    
    
    // Filter's Gain of Tap0/1
    ScalerSetBit(P1D_E2_GAIN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT4));

    // Filter's Gain of Tap2
    ScalerSetBit(P1D_E3_GAIN_2, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));

    // Filter's Gain of Servo-loop
    ScalerSetBit(P1D_E4_GAIN_3, ~(_BIT4 | _BIT3 | _BIT2), (_BIT3 | _BIT2));

    // Set Vth/Tap0/Tap1/Tap2 Max and Min Value
    ScalerSetByte(P1D_E6_LIMIT_1, 0xF5);
    ScalerSetByte(P1D_E7_LIMIT_2, 0xEE);
    ScalerSetByte(P1D_E8_LIMIT_3, 0x56);
    ScalerSetBit(P1D_E9_LIMIT_4, ~(_BIT7 | _BIT6), _BIT6);
    
    // Set Vth/Servo-loop/Tap Divider 
    ScalerSetByte(P1D_EC_LOOP_DIV_1, 0xA3);
    ScalerSetByte(P1D_ED_LOOP_DIV_2, 0xCA);


    /////////////////////////
    // DFE Code Initialize //
    /////////////////////////

    if(enumDpLinkRate == _DP_LINK_HBR) // HBR
    {                                                
        ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0xFF); 
        ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0xFF); 
        ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0xFF); 
        ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0xFF); 

        ScalerSetByte(P1D_A3_L0_INIT_1, 0x0F); 
        ScalerSetByte(P1D_B3_L1_INIT_1, 0x0F); 
        ScalerSetByte(P1D_C3_L2_INIT_1, 0x0F); 
        ScalerSetByte(P1D_D3_L3_INIT_1, 0x0F); 
    }                                                                                                            
    else // RBR
    {                                                
        ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x3F); 
        ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x3F); 
        ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x3F); 
        ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0x3F);

        ScalerSetByte(P1D_A3_L0_INIT_1, 0x8F); 
        ScalerSetByte(P1D_B3_L1_INIT_1, 0x8F); 
        ScalerSetByte(P1D_C3_L2_INIT_1, 0x8F); 
        ScalerSetByte(P1D_D3_L3_INIT_1, 0x8F);     
    }

    ScalerSetByte(P1D_A4_L0_INIT_2, 0x15);
    ScalerSetByte(P1D_B4_L1_INIT_2, 0x15);
    ScalerSetByte(P1D_C4_L2_INIT_2, 0x15); 
    ScalerSetByte(P1D_D4_L3_INIT_2, 0x15);    
     
    ScalerSetByte(P1D_A5_L0_INIT_3, 0x0C); 
    ScalerSetByte(P1D_B5_L1_INIT_3, 0x0C); 
    ScalerSetByte(P1D_C5_L2_INIT_3, 0x0C); 
    ScalerSetByte(P1D_D5_L3_INIT_3, 0x0C);  

    ScalerSetByte(P1D_A6_L0_INIT_4, 0x00); 
    ScalerSetByte(P1D_B6_L1_INIT_4, 0x00); 
    ScalerSetByte(P1D_C6_L2_INIT_4, 0x00); 
    ScalerSetByte(P1D_D6_L3_INIT_4, 0x00); 
                  
    ScalerSetByte(P1D_A9_L0_INIT_7, 0x08); 
    ScalerSetByte(P1D_B9_L1_INIT_7, 0x08); 
    ScalerSetByte(P1D_C9_L2_INIT_7, 0x08); 
    ScalerSetByte(P1D_D9_L3_INIT_7, 0x08); 
    
    // Load Intial DFE Code
    ScalerSetByte(P1D_AA_L0_INIT_8, 0xFF);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0xFF);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0xFF);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0xFF);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);   

    // DFE Loop Normal
    ScalerSetBit(P1D_EF_RESET_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));   
}

//--------------------------------------------------
// Description  : Check Valid Video Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpValidSignalDetection(void)
{      
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);
    
    if(GET_DP_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE)
    {        
        ScalerDpRebuildPhy(0x06, 0x84);
    }
    else
    {
        ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);

        return;
    }

    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);

    // De-Skew Circuit Reset
    ScalerSetBit(PC_BB_DP_RESERVE1, ~_BIT5, 0x00);
    ScalerSetBit(PC_BB_DP_RESERVE1, ~_BIT5, _BIT5);

    // Mac Reset After Link Clock Stable
    ScalerSetBit(PC_A1_DP_CTL, ~_BIT6, _BIT6);
    ScalerSetBit(PC_A1_DP_CTL, ~_BIT6, 0x00);

    // Secondary Data Reset (DP Audio Block)
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_92_AUD_BUF_STATUS, ~_BIT2, _BIT2);
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_92_AUD_BUF_STATUS, ~_BIT2, 0x00);
        
    ScalerSetBit(PC_B2_DP_MEM_BIST, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {        
        if(GET_DP_LINK_TRAINING_STATUS() != _DP_LINK_TRAINING_NONE)
        {
            return;
        }

        ScalerTimerDelayXms(1);        
    }
        
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);       

    if(GET_DP_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE)
    {   
        if(ScalerGetBit(PC_B2_DP_MEM_BIST, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == (_BIT7 | _BIT6 | _BIT5 | _BIT4))
        {
            ScalerDpSetDpcdValue(0x00, 0x01, 0x00, 0x06);

            ScalerDpSetDpcdValue(0x00, 0x01, 0x01, 0x84);

            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);

            DebugMessageDigital("7. wuzanne test : 4/L", 0);
        }
        else if(ScalerGetBit(PC_B2_DP_MEM_BIST, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6))
        {
            ScalerDpSetDpcdValue(0x00, 0x01, 0x00, 0x06);

            ScalerDpSetDpcdValue(0x00, 0x01, 0x01, 0x82);

            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);

            DebugMessageDigital("7. wuzanne test : 2/L", 0);
        }
        else if(ScalerGetBit(PC_B2_DP_MEM_BIST, _BIT7) == _BIT7)
        {
            ScalerDpSetDpcdValue(0x00, 0x01, 0x00, 0x06);

            ScalerDpSetDpcdValue(0x00, 0x01, 0x01, 0x81);

            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);

            DebugMessageDigital("7. wuzanne test : 1/L", 0);                
        }
    }
    else
    {
        ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);        

        return;
    }
        
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);        

    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);
    
    if(GET_DP_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE)
    {
        ScalerDpRebuildPhy(0x0A, 0x84);
    }
    else
    {
        ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);        
        
        return;
    }

    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);        

    // De-Skew Circuit Reset
    ScalerSetBit(PC_BB_DP_RESERVE1, ~_BIT5, 0x00);
    ScalerSetBit(PC_BB_DP_RESERVE1, ~_BIT5, _BIT5);
    
    // Mac Reset After Link Clock Stable
    ScalerSetBit(PC_A1_DP_CTL, ~_BIT6, _BIT6);
    ScalerSetBit(PC_A1_DP_CTL, ~_BIT6, 0x00);
    
    // Secondary Data Reset (DP Audio Block)
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_92_AUD_BUF_STATUS, ~_BIT2, _BIT2);
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_92_AUD_BUF_STATUS, ~_BIT2, 0x00);
    
    ScalerSetBit(PC_B2_DP_MEM_BIST, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        if(GET_DP_LINK_TRAINING_STATUS() != _DP_LINK_TRAINING_NONE)
        {
            return;
        }

        ScalerTimerDelayXms(1);
    }
        
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);       

    if(GET_DP_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE)
    {   
        if(ScalerGetBit(PC_B2_DP_MEM_BIST, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == (_BIT7 | _BIT6 | _BIT5 | _BIT4))
        {
            ScalerDpSetDpcdValue(0x00, 0x01, 0x00, 0x0A);

            ScalerDpSetDpcdValue(0x00, 0x01, 0x01, 0x84);

            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);

            DebugMessageDigital("7. wuzanne test : 4/H", 0);
        }
        else if(ScalerGetBit(PC_B2_DP_MEM_BIST, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6))
        {
            ScalerDpSetDpcdValue(0x00, 0x01, 0x00, 0x0A);

            ScalerDpSetDpcdValue(0x00, 0x01, 0x01, 0x82);

            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);

            DebugMessageDigital("7. wuzanne test : 2/H", 0);
        }
        else if(ScalerGetBit(PC_B2_DP_MEM_BIST, _BIT7) == _BIT7)
        {
            ScalerDpSetDpcdValue(0x00, 0x01, 0x00, 0x0A);

            ScalerDpSetDpcdValue(0x00, 0x01, 0x01, 0x81);

            SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);

            DebugMessageDigital("7. wuzanne test : 1/H", 0);
        }
    }
    else
    {
        ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);             
        
        return;
    }
    
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);             
}

//--------------------------------------------------
// Description  : Check Valid Lane CDR
// Input Value  : None
// Output Value : True --> CDR Lock
//--------------------------------------------------
bit ScalerDpCDRCheck(void)
{
    switch(ScalerDpGetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)
    {
        case _DP_ONE_LANE:

            if(ScalerDpMeasureLaneCDRClk(_DP_LANE0) == _TRUE)
            {
                return _TRUE;
            }
            
            break;

        case _DP_TWO_LANE:

            if((ScalerDpMeasureLaneCDRClk(_DP_LANE0) == _TRUE) 
                && (ScalerDpMeasureLaneCDRClk(_DP_LANE1) == _TRUE))
            {
                return _TRUE;
            }            

            break;

        case _DP_FOUR_LANE:
        default:

            if((ScalerDpMeasureLaneCDRClk(_DP_LANE0) == _TRUE) 
                && (ScalerDpMeasureLaneCDRClk(_DP_LANE1) == _TRUE) 
                && (ScalerDpMeasureLaneCDRClk(_DP_LANE2) == _TRUE) 
                && (ScalerDpMeasureLaneCDRClk(_DP_LANE3) == _TRUE))
            {
                return _TRUE;
            }            

            break;            
    }

    DebugMessageDigital("7. wuzanne test : DP CDR Unlock", 0);
    
    return _FALSE;    
}

//--------------------------------------------------
// Description : check DP CDR locked or unlocked
// Input Value  : DP Lane
// Output Value : True --> locked; False --> unlocked
//--------------------------------------------------
bit ScalerDpMeasureLaneCDRClk(EnumDpLaneNumber enumDpLaneNumber)
{
    BYTE ucDelayCount = 0;
    BYTE ucBackUp = 0;

    // Select reference clk to Xtal Clk and measure clk
    ScalerSetByte(P2_AD_CPS, ((ScalerGetByte(P2_AD_CPS) & ~(_BIT6 | _BIT5 | _BIT4)) | ((enumDpLaneNumber << 5) | _BIT4)));

    ucBackUp = ScalerGetByte(P2_C8_HDMI_APC);

    // Disable Auto Inc
    ScalerSetBit(P2_C8_HDMI_APC, ~_BIT0, 0x00);

    // Start Measure
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_28_HDMI_NTX1024TR0, ~_BIT3, _BIT3);

    // Delay at least 40us at Xtal = 27MHz
    for(ucDelayCount = 0; ucDelayCount <= 20; ucDelayCount++)
    {
        _nop_();

        if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_28_HDMI_NTX1024TR0, _BIT3) == 0x00)
        {
            break;
        }
    }

    ScalerSetByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_29_HDMI_NTX1024TR1);
    
    pData[0] = ScalerGetByte(P2_CA_HDMI_DATA_PORT);

    ScalerSetByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_28_HDMI_NTX1024TR0);
    
    pData[1] = ScalerGetByte(P2_CA_HDMI_DATA_PORT);

    ScalerSetByte(P2_C8_HDMI_APC, ucBackUp);    

    if(((pData[1] & 0x07) == 0x00) 
        && ((((ScalerDpGetDpcdInfo(0x00, 0x01, 0x00) & 0x06) == 0x06) && (pData[0] <= 0xB3) && (pData[0] >= 0xA1)) 
        || (((ScalerDpGetDpcdInfo(0x00, 0x01, 0x00) & 0x0A) == 0x0A) && (pData[0] <= 0x6B) && (pData[0] >= 0x61)) ))
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Valid Lane Alignment
// Input Value  : None
// Output Value : True --> Align
//--------------------------------------------------
bit ScalerDpAlignCheck(void)
{
    if(ScalerGetBit(PC_BB_DP_RESERVE1, _BIT3) == 0x00)
    {
        //return _FALSE;
    }
    
    return _TRUE;
}

//--------------------------------------------------
// Description : check DP 8b/10b Decode Error 
// Input Value  : None
// Output Value : True --> ok, False --> 8b/10b Decode Error
//--------------------------------------------------
bit ScalerDpDecodeCheck(void)
{
    pData[1] = 3;
    
    while(pData[1] > 0)
    {        
        // Clear 8b/10b Decode Error Flag
        ScalerSetBit(PC_A5_DP_LANE_VALID, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

        for(pData[0] = 0; pData[0] <= 20; pData[0]++)
        {
            _nop_();
        }

        switch(ScalerDpGetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)
        {
            case _DP_ONE_LANE:

                if(ScalerGetBit(PC_A5_DP_LANE_VALID, _BIT3) == 0x00)
                {
                    return _TRUE;
                }
                
                break;

            case _DP_TWO_LANE:

                if(ScalerGetBit(PC_A5_DP_LANE_VALID, (_BIT3 | _BIT2)) == 0x00)
                {
                    return _TRUE;
                }            

                break;

            case _DP_FOUR_LANE:
            default:

                if(ScalerGetBit(PC_A5_DP_LANE_VALID, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x00)
                {
                    return _TRUE;
                }            

                break;            
        }
        
        pData[1]--;
    }

    DebugMessageDigital("7. wuzanne test : DP 8b/10b Decode Error", 0);

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Dp Video Straam VBID
// Input Value  : None
// Output Value : True --> Get Video Stream
//--------------------------------------------------
bit ScalerDpGetVideoStream(void)
{
    if(ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_01_DP_VBID, _BIT3) == 0x00)
    {
        ScalerTimerDelayXms(30);
        
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Dp Video Straam VBID
// Input Value  : None
// Output Value : True --> Get Video Stream
//--------------------------------------------------
bit ScalerDpMSACheck(void)
{
    // Pop up Main Stream Attributes
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_00_MN_STRM_ATTR_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

    // Get Htotal
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_04_MN_STRM_ATTR_HTT_M, 2, &pData[0], _AUTOINC);

    // Get Hstart
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_06_MN_STRM_ATTR_HST_M, 2, &pData[2], _AUTOINC);

    // Get Hactive
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_08_MN_STRM_ATTR_HWD_M, 2, &pData[4], _AUTOINC);

    // Get HSW
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_0A_MN_STRM_ATTR_HSW_M, 2, &pData[6], _AUTOINC);

    // Get Vtotal
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_0C_MN_STRM_ATTR_VTTE_M, 2, &pData[8], _AUTOINC);

    // Get Vstart
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_10_MN_STRM_ATTR_VST_M, 2, &pData[10], _AUTOINC);

    // Get Vactive
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_12_MN_STRM_ATTR_VHT_M, 2, &pData[12], _AUTOINC);

    // Get VSW
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_14_MN_STRM_ATTR_VSW_M, 2, &pData[14], _AUTOINC);
                
    if((PDATA_WORD(0) == 0x00) || (PDATA_WORD(1) == 0x00) || (PDATA_WORD(2) == 0x00) || ((PDATA_WORD(3) & 0x7FFF) == 0x00) || 
       (PDATA_WORD(4) == 0x00) || (PDATA_WORD(5) == 0x00) || (PDATA_WORD(6) == 0x00) || ((PDATA_WORD(7) & 0x7FFF) == 0x00))
    {
        if((PDATA_WORD(0) == 0x00) && (PDATA_WORD(1) == 0x00) && (PDATA_WORD(2) == 0x00) && ((PDATA_WORD(3) & 0x7FFF) == 0x00) && 
           (PDATA_WORD(4) == 0x00) && (PDATA_WORD(5) == 0x00) && (PDATA_WORD(6) == 0x00) && ((PDATA_WORD(7) & 0x7FFF) == 0x00))
        {
            if((ScalerDpHdcpEnebled() == _TRUE) && (GET_DP_MSA_FAIL_MAC_RESET_COUNT() < 10))
            {
                ADD_DP_MSA_FAIL_MAC_RESET_COUNT();
            }
            else
            {
                CLR_DP_MSA_FAIL_MAC_RESET_COUNT();

                // Mac Reset
                ScalerSetBit(PC_A1_DP_CTL, ~_BIT6, _BIT6);
                ScalerTimerDelayXms(30);        
                ScalerSetBit(PC_A1_DP_CTL, ~_BIT6, 0x00);
            }
        }

        return _FALSE;
    }

    CLR_DP_MSA_FAIL_MAC_RESET_COUNT();

    // Get Mvid
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_16_MN_M_VID_H, 3, pData, _AUTOINC);

    if((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | ((DWORD)pData[2] << 0)) == 0x00)
    {
        return _FALSE;
    }

    // Get Nvid
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_19_MN_N_VID_H, 3, pData, _AUTOINC);

    if((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | ((DWORD)pData[2] << 0)) == 0x00)
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Check DP Misc Information
// Input Value  : None
// Output Value : True --> DP Misc Check Ok
//--------------------------------------------------
bit ScalerDpMiscCheck(void)
{
    // Pop up Main Stream Attributes
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_00_MN_STRM_ATTR_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));
    
    // Dynamic Range Check
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_02_MN_STRM_ATTR_MISC, 1, pData, _NON_AUTOINC);

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
    if((pData[0] & (_BIT2 | _BIT1)) == 0x00)
    {
        if(((GET_COLOR_RGB_QUANTIZATION_RANGE() == _RGB_QUANTIZATION_LIMIT_RANGE) && ((pData[0] & _BIT3) == 0x00)) || 
           ((GET_COLOR_RGB_QUANTIZATION_RANGE() == _RGB_QUANTIZATION_FULL_RANGE) && ((pData[0] & _BIT3) == _BIT3)))
        {
            return _FALSE;
        }
    }
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(((pData[0] & (_BIT2 | _BIT1)) == _BIT1) || ((pData[0] & (_BIT2 | _BIT1)) == _BIT2))
    {
        if(((GET_COLOR_YCC_QUANTIZATION_RANGE() == _YCC_QUANTIZATION_LIMIT_RANGE) && ((pData[0] & _BIT3) == 0x00)) || 
           ((GET_COLOR_YCC_QUANTIZATION_RANGE() == _YCC_QUANTIZATION_FULL_RANGE) && ((pData[0] & _BIT3) == _BIT3)))
        {
            return _FALSE;
        }
    }
#endif
    
    // Color Depth Check    
    if((((ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_02_MN_STRM_ATTR_MISC, 0xE0)) >> 5) & (0x07)) != 
        (ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_31_MN_PIX_REG_CTRL, 0x07)))
    {
        return _FALSE;
    }

    // Color Format Check
    if((((ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_02_MN_STRM_ATTR_MISC, 0x06)) << 2) & (0x18)) != 
        (ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_31_MN_PIX_REG_CTRL, 0x18)))
    {
        return _FALSE;
    } 

    // Get HSW
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_0A_MN_STRM_ATTR_HSW_M, 2, pData, _AUTOINC);

    // Get VSW
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_14_MN_STRM_ATTR_VSW_M, 2, &pData[2], _AUTOINC);

    if(((PDATA_WORD(0) & 0x7FFF) == 0x00) || ((PDATA_WORD(1) & 0x7FFF) == 0x00))
    {
        return _FALSE;
    }
    
    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Display Format Generator Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpDisplayFormatSetting(void)
{        
    // DP Display Format Generator Reset
    ScalerSetBit(PC_A3_DP_OUTPUT_CLK_CTL, ~_BIT4, _BIT4);
    ScalerSetBit(PC_A3_DP_OUTPUT_CLK_CTL, ~_BIT4, 0x00);

    // Start Generate Display Format, Set FrameSync Mode
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_35_MN_DPF_CTRL, 0xA0);

    PDATA_DWORD(0) = ScalerDpGetBStoVSDelay();

    // Set Odd Field BS to VS Delay
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_39_MN_OVBLK2VS_H, pData[1]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_3A_MN_OVBLK2VS_M, pData[2]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_3B_MN_OVBLK2VS_L, pData[3]);
    
    if(ScalerDpInterlaceCheck() == _TRUE) // Interlace
    {
        DebugMessageDigital("7. wuzanne test : IIIIIIterLace", 0);

        ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_39_MN_OVBLK2VS_H, 3, &pData[1], _AUTOINC);
        
        PDATA_DWORD(0) &= 0x00FFFFFF; 
        
        if(ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, _BIT0) == 0x00)
        {            
            // Get Mvid
            ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_16_MN_M_VID_H, 3, &pData[4], _AUTOINC);

            // Get Nvid
            ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_19_MN_N_VID_H, 3, &pData[7], _AUTOINC);

            // Get Htotal
            ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_04_MN_STRM_ATTR_HTT_M, 2, &pData[10], _AUTOINC);

            // BStoVSDelay = BStoVSDelay + (Nvid * 256 / Mvid) * ((DWORD)Htotal) / 256;
            PDATA_DWORD(0) = PDATA_DWORD(0) + (((((DWORD)pData[7] << 16) | ((DWORD)pData[8] << 8) | ((DWORD)pData[9] << 0)) * 256 / (((DWORD)pData[4] << 16) | ((DWORD)pData[5] << 8) | ((DWORD)pData[6] << 0))) * ((DWORD)PDATA_WORD(5)) / 256);
        }
    }
    else // Progressive
    { 
        DebugMessageDigital("7. wuzanne test : PPPPProgressive", 0);

        ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_39_MN_OVBLK2VS_H, 3, &pData[1], _AUTOINC);
        
        PDATA_DWORD(0) &= 0x00FFFFFF; 
         
        // Disable DP Interlace
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, ~(_BIT7 |  _BIT6), 0x00);                
    }

    // Set Even Field BS to VS Delay
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_36_MN_EVBLK2VS_H, pData[1]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_37_MN_EVBLK2VS_M, pData[2]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_38_MN_EVBLK2VS_L, pData[3]);

    //Set Htotal
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_04_MN_STRM_ATTR_HTT_M, 2, pData, _AUTOINC);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_3E_MN_DPF_HTT_M, pData[0]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_3F_MN_DPF_HTT_L, pData[1]);

    //Set Hstart
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_06_MN_STRM_ATTR_HST_M, 2, pData, _AUTOINC);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_40_MN_DPF_HST_M, pData[0]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_41_MN_DPF_HST_L, pData[1]);

    //Set Hactive
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_08_MN_STRM_ATTR_HWD_M, 2, pData, _AUTOINC);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_42_MN_DPF_HWD_M, pData[0]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_43_MN_DPF_HWD_L, pData[1]);

    //Set HSW
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_0A_MN_STRM_ATTR_HSW_M, 2, pData, _AUTOINC);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_44_MN_DPF_HSW_M, pData[0]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_45_MN_DPF_HSW_L, pData[1]);

    //Set Vtotal
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_0C_MN_STRM_ATTR_VTTE_M, 2, &pData[2], _AUTOINC);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_46_MN_DPF_VTT_M, pData[2]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_47_MN_DPF_VTT_L, pData[3]);

    //Set Vactive
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_12_MN_STRM_ATTR_VHT_M, 2, &pData[4], _AUTOINC);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_4A_MN_DPF_VHT_M, pData[4]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_4B_MN_DPF_VHT_L, pData[5]);

    //Set Vstart
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_10_MN_STRM_ATTR_VST_M, 2, pData, _AUTOINC);

    // Vtotal - Vstart - Vactive < 2 --> Last Line Issue
    if((PDATA_WORD(1) >= (PDATA_WORD(0) + PDATA_WORD(2))) &&
        (PDATA_WORD(0) >= 3) &&
        ((PDATA_WORD(1) - PDATA_WORD(0) - PDATA_WORD(2)) < 2) &&
        ((PDATA_WORD(0) - 3) > 2))
    {
        PDATA_WORD(0) = PDATA_WORD(0) - 2;
    }
    
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_48_MN_DPF_VST_M, pData[0]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_49_MN_DPF_VST_L, pData[1]);

    //Set VSW --> Negative and 3 Lines width.
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_4C_MN_DPF_VSW_M, 0x80);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_4D_MN_DPF_VSW_L, 0x03);  
    
    // Double Buffer to Apply Display Format Setting
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_35_MN_DPF_CTRL, ~_BIT6, _BIT6);
}

//--------------------------------------------------
// Description  : DP BS to VS Delay Calculation 
// Input Value  : None
// Output Value : BS to VS Delay
//--------------------------------------------------
DWORD ScalerDpGetBStoVSDelay(void)
{   
    DWORD ulVFrontPorch = 0;
    DWORD ulHFrontPorch = 0;
    WORD usFifoOffset = 0;

    // Get Mvid
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_16_MN_M_VID_H, 3, &pData[0], _AUTOINC);

    // Get Nvid
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_19_MN_N_VID_H, 3, &pData[3], _AUTOINC);

    // Get Vtotal
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_0C_MN_STRM_ATTR_VTTE_M, 2, &pData[6], _AUTOINC);

    // Get Vstart
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_10_MN_STRM_ATTR_VST_M, 2, &pData[8], _AUTOINC);

    // Get Vactive
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_12_MN_STRM_ATTR_VHT_M, 2, &pData[10], _AUTOINC);    

    // Get Htotal
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_04_MN_STRM_ATTR_HTT_M, 2, &pData[12], _AUTOINC);

    // Vtotal - Vstart - Vactive < 2 --> Last Line Issue
    if((PDATA_WORD(3) >= (PDATA_WORD(5) + PDATA_WORD(4))) &&
        (PDATA_WORD(4) >= 3) &&
        ((PDATA_WORD(3) - PDATA_WORD(5) - PDATA_WORD(4)) < 2) &&
        ((PDATA_WORD(4) - 3) > 2))
    {
        PDATA_WORD(4) = PDATA_WORD(4) - 2;
    }
    
    // VFrontPorch = ((((DWORD)(Vtotal - Vactive - Vstart)) * (Nvid * 256 / Mvid)) * ((DWORD)Htotal) / 256)
    ulVFrontPorch = ((((DWORD)(PDATA_WORD(3) - PDATA_WORD(5) - PDATA_WORD(4))) * 
                     ((((DWORD)pData[3] << 16) | ((DWORD)pData[4] << 8) | ((DWORD)pData[5] << 0)) * 256 / 
                     (((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | ((DWORD)pData[2] << 0)))) * 
                     ((DWORD)PDATA_WORD(6)) / 256);

    // Get Htotal
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_04_MN_STRM_ATTR_HTT_M, 2, &pData[6], _AUTOINC);

    // Get Hstart
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_06_MN_STRM_ATTR_HST_M, 2, &pData[8], _AUTOINC);

    // Get Hactive
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_08_MN_STRM_ATTR_HWD_M, 2, &pData[10], _AUTOINC);

    // HFrontPorch = (((DWORD)(g_usDpHtotal - g_usDpHactive - g_usDpHstart)) * g_ulDpNvidValue / g_ulDpMvidValue)
    ulHFrontPorch = (((DWORD)(PDATA_WORD(3) - PDATA_WORD(5) - PDATA_WORD(4))) * 
                      (((DWORD)pData[3] << 16) | ((DWORD)pData[4] << 8) | ((DWORD)pData[5] << 0)) / 
                      (((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | ((DWORD)pData[2] << 0)));

    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_02_MN_STRM_ATTR_MISC, 1, &pData[14], _NON_AUTOINC);

    switch(pData[14] & (_BIT7 | _BIT6 | _BIT5))
    {
        case 0x00:
            pData[15] = 6;
            break;
        case (_BIT5):
            pData[15] = 8;
            break;
        case (_BIT6):
            pData[15] = 10;
            break;
        case (_BIT6 | _BIT5):
            pData[15] = 12;
            break;
        case (_BIT7):
            pData[15] = 16;
            break;
        default:
            break;
    }  

    // DP fifo size = 360 x 64bit
    // FifoOffset = (1/2 * (360 * 64) / (3 * depth per color))
    usFifoOffset = ((3840) / (WORD)pData[15]);

    // FifoOffset = (1/2 * (360 * 64) / (3 * depth per color)) * g_ulDpNvidValue / g_ulDpMvidValue)
    usFifoOffset = ((DWORD)usFifoOffset * 
                    (((DWORD)pData[3] << 16) | ((DWORD)pData[4] << 8) | ((DWORD)pData[5] << 0)) / 
                    (((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | ((DWORD)pData[2] << 0)));

    return (ulVFrontPorch + ulHFrontPorch + (DWORD)usFifoOffset);
}

//--------------------------------------------------
// Description  : Check Dp Interlace by VBID or Measure 
// Input Value  : None
// Output Value : True --> Interlace
//--------------------------------------------------
bit ScalerDpInterlaceCheck(void)
{
    // Field inverse disable
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, ~_BIT4, 0x00);
    
    // Start to Measure Vertical BS to BS Counter by GDI Clock
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, ~_BIT7, _BIT7);

    pData[0] = 60;

    do
    {        
        if(ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, _BIT6) == _BIT6)
        {
            // Pop up Measure Result
            ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, ~_BIT5, _BIT5);
            
            break;
        }
        
        ScalerTimerDelayXms(1);        
    }
    while(--pData[0]);

    if(pData[0] == 0x00)
    {
        return _FALSE;      
    }

    // Get Measure Result
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, 3, &pData[5], _AUTOINC);

    // Get VBID
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_01_DP_VBID, 1, &pData[1], _NON_AUTOINC);

    // Delay 1 frame    
    ScalerTimerDelayXms((((PDATA_DWORD(1) & 0x001FFFFF) / (_GDI_CLK_KHZ)) + 2));

    // Pop up Measure Result
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, ~_BIT5, _BIT5);    

    // Get Measure Result
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, 3, &pData[9], _AUTOINC);

    // Get VBID
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_01_DP_VBID, 1, &pData[2], _NON_AUTOINC);    

    PDATA_DWORD(1) = (PDATA_DWORD(1) & 0x001FFFFF);
    PDATA_DWORD(2) = (PDATA_DWORD(2) & 0x001FFFFF);

    // Get Vtotal
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_0C_MN_STRM_ATTR_VTTE_M, 2, &pData[14], _AUTOINC);

    // Disable Measure Block
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, ~_BIT7, 0x00);

    DebugMessageDigital("7. wuzanne test : DelayTime", (((PDATA_DWORD(1) & 0x001FFFFF) / (_GDI_CLK_KHZ)) + 2));
    DebugMessageDigital("7. wuzanne test : PDATA_DWORD(0)", PDATA_DWORD(1));
    DebugMessageDigital("7. wuzanne test : PDATA_DWORD(1)", PDATA_DWORD(2));
    DebugMessageDigital("7. wuzanne test : PDATA_DWORD(ABS)", (ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))));
    DebugMessageDigital("7. wuzanne test : PDATA_DWORD(1 Line)", (PDATA_DWORD(1) / PDATA_WORD(7)));
    DebugMessageDigital("7. wuzanne test : 1 Line Tolerance", ((PDATA_DWORD(1) / PDATA_WORD(7)) >> 4));

    if(ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_01_DP_VBID, _BIT2) == _BIT2) // Interlace                 
    {
        if((pData[1] & _BIT1) != (pData[2] & _BIT1))
        {
            // Enable interlace mode, field reference VBID
            ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, ~(_BIT7 |  _BIT6), _BIT7);  
            
            if((ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, _BIT0) == 0x00) && 
                ((((pData[1] & _BIT1) == _BIT1) && ((pData[2] & _BIT1) == 0x00) && (PDATA_DWORD(1) < PDATA_DWORD(2))) ||
                 (((pData[1] & _BIT1) == 0x00) && ((pData[2] & _BIT1) == _BIT1) && (PDATA_DWORD(1) > PDATA_DWORD(2)))))
            {                
                // Field inverse enable
                ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, ~_BIT4, _BIT4);                  
            }
        }
        else
        {
            // Enable interlace mode, field reference HW
            ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, ~(_BIT7 |  _BIT6), (_BIT7 |  _BIT6)); 
        }        
      
        return _TRUE;
    }
    else if(ABSDWORD((ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))), (PDATA_DWORD(1) / PDATA_WORD(7))) < ((PDATA_DWORD(1) / PDATA_WORD(7)) >> 4))
    {
        // Enable interlace mode, field reference HW
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_03_MN_STRM_ATTR_MISC1, ~(_BIT7 |  _BIT6), (_BIT7 |  _BIT6));  
        
        return _TRUE;
    }
    
    return _FALSE;
}

//--------------------------------------------------
// Description  : DP Video Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpVideoSetting(void)
{
    // Get Misc
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_02_MN_STRM_ATTR_MISC, 1, pData, _NON_AUTOINC);

    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_31_MN_PIX_REG_CTRL, ((pData[0] >> 5) & (_BIT2 | _BIT1 | _BIT0)) | ((pData[0] << 2) & (_BIT4 | _BIT3)));

    if(((pData[0] & (_BIT2 | _BIT1)) == _BIT2) || ((pData[0] & (_BIT2 | _BIT1)) == _BIT1))
    {
        SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);

        // Check Dynamic Range
        if((pData[0] & _BIT3) == _BIT3)
        {
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);                
        }
        else
        {
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);                
        }

        if((pData[0] & _BIT4) == _BIT4)
        {
            SET_COLORIMETRY(_COLORIMETRY_ITU709);
        }
        else
        {
            SET_COLORIMETRY(_COLORIMETRY_ITU601);
        }

        // Set Porch Color 
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_75_MN_DPF_BG_RED_M, 0x80);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_76_MN_DPF_BG_RED_L, 0x00);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_77_MN_DPF_BG_GRN_M, 0x0F);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_78_MN_DPF_BG_GRN_L, 0x00);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_79_MN_DPF_BG_BLU_M, 0x80);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_7A_MN_DPF_BG_BLU_L, 0x00);        
    }
    else
    {
        SET_COLOR_SPACE(_COLOR_SPACE_RGB);

        // Check Dynamic Range
        if((pData[0] & _BIT3) == _BIT3)
        {
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_LIMIT_RANGE);
        }
        else
        {
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);
        }

        // Set Porch Color
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_75_MN_DPF_BG_RED_M, 0x00);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_76_MN_DPF_BG_RED_L, 0x00);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_77_MN_DPF_BG_GRN_M, 0x00);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_78_MN_DPF_BG_GRN_L, 0x00);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_79_MN_DPF_BG_BLU_M, 0x00);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_7A_MN_DPF_BG_BLU_L, 0x00);                
    }
}

//--------------------------------------------------
// Description  : DP Stream Clk PLL Setting
// Input Value  : None
// Output Value : True --> Stream CLK Regen. ok
//--------------------------------------------------
bit ScalerDpStreamClkRegenerate(void)
{
    DWORD ulStreamClkValue = 0;
    SDWORD ulOffsetValue = 0;
    DWORD ulIcodeValue = 0; 
    DWORD ulpllm = 0;
    DWORD ulXtal_clk = 0;
    DWORD g_ulDpMvidValue = 0;
    DWORD g_ulDpNvidValue = 0;
    BYTE ucpllo = 0;
    BYTE ucdivs = 0;
    BYTE ucdiv2 = 0;
    BYTE ucplln = 0;
    BYTE ucBuf = 0;
    BYTE ucdiv_pllo = 0;
    BYTE ucdiv_divs = 0;
    BYTE ucdpllvcomd = 0;

    // Get Mvid
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_16_MN_M_VID_H, 3, &pData[0], _AUTOINC);

    // Get Nvid
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_19_MN_N_VID_H, 3, &pData[3], _AUTOINC);

    g_ulDpMvidValue = (((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | ((DWORD)pData[2] << 0));

    g_ulDpNvidValue = (((DWORD)pData[3] << 16) | ((DWORD)pData[4] << 8) | ((DWORD)pData[5] << 0));

#if(_PCB_DP_CONNECTOR_SWAP == _ON)

    // Measure of Lane 0 Clk
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), _BIT7);
#else

    // Measure of Lane 0 Clk
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), (_BIT7 | _BIT5 | _BIT4));
#endif
    
    ScalerTimerDelayXms(2);

    // Pop up the result
    ScalerSetBit(P2_EC_HDMI_FREQDET_STABLE, ~_BIT7, _BIT7);

    PDATA_WORD(0) = (((WORD)(ScalerGetByte(P2_ED_HDMI_FREQDET_RESULT_M) & 0x7F) << 8) | (ScalerGetByte(P2_EE_HDMI_FREQDET_RESULT_L)));

    PDATA_DWORD(0) = (DWORD)(PDATA_WORD(0) * _GDI_CLK_KHZ);       

    ulXtal_clk = PDATA_DWORD(0) / 8 / 1000;

    // Calculate streamclk
    (DWORD)ulStreamClkValue = ((DWORD)g_ulDpMvidValue * (PDATA_DWORD(0) * 14 / g_ulDpNvidValue) / 14);

    SET_INPUT_PIXEL_CLK(ulStreamClkValue / 100000);
    
    ucdiv2 = 0;

    // Get DPLL parameter
    // If "400Mhz > ulStreamClkValue > 270Mhz"
    if((400000000 > ulStreamClkValue) && (ulStreamClkValue >= 270000000))
    {
        ucpllo = 0;
        ucdivs = 0;
        ucplln = 2;

        ucdiv_divs = 1;
        ucdiv_pllo = 1;

        ulpllm = ((((ulStreamClkValue * ucdiv_divs * ucdiv_pllo) / 1000) * ucplln) / (ulXtal_clk));

        while(ulpllm > 257)
        {
            return _FALSE;
        }
    }
    // If "270MHz > ulStreamClkValue > 8.4375Mhz"
    else if((ulStreamClkValue < 270000000) && (ulStreamClkValue >= 8437500))
    {
        ucpllo = 1;

        if((ulStreamClkValue < 270000000) && (ulStreamClkValue >= 135000000))
        {
            ucdivs = 0;
        }
        else if((ulStreamClkValue < 135000000) && (ulStreamClkValue >= 67500000))
        {
            ucdivs = 1;
        }
        else if((ulStreamClkValue < 67500000) && (ulStreamClkValue >= 33750000))
        {
            ucdivs = 2;
        }
        else if((ulStreamClkValue < 33750000) && (ulStreamClkValue >= 16875000))
        {
            ucdivs = 4;
        }
        else
        {
            ucdivs = 8;
        }

        // Because set 17 get minimum error for recovery stream clk , close to fact clk.
        ucplln = 2;

        if(ucdivs == 0)
        {
            ucdiv_divs = 1;
        }
        else
        {
            ucdiv_divs = 2 * ucdivs;
        }

        ucdiv_pllo = 1;

        if(ucpllo != 0)
        {
            ucdiv_pllo = 1;

            for(ucBuf = 0; ucBuf < ucpllo; ucBuf++)
            {
                ucdiv_pllo = 2 * ucdiv_pllo;
            }
        }

        ulpllm = ((((ulStreamClkValue * ucdiv_divs * ucdiv_pllo) / 1000) * ucplln) / (ulXtal_clk));

        while(ulpllm > 257)
        {
            return _FALSE;
        }
    }
    else
    {
        return _FALSE;
    }

    // offset = (m/n*f_ref - f)/(m/n*f_ref)*2^21 
    // seperate *2^21 to *32*16384*4
    ulOffsetValue = ((ulStreamClkValue * ucdiv_pllo * ucdiv_divs) - ((ulXtal_clk * 1000 / ucplln) * ulpllm)) * 32 / ulpllm * ucplln / ulXtal_clk * 16384 / 1000 * 4; 

    // Icp Formula : Icp * N / M * (27M / (Link_clk / 8)) = 0.5
    // Icp = 0.5 * M / N * ((Link_clk / 8) / 27M)
    // Icp   = 2.5u + D0[0] * 2.5u + D0[1] * 5u + D0[2] * 10u (A)
    // Icp = 2.5uA, 5uA, 7.5uA, 10uA......    
    pData[5] = (DWORD)ulpllm * ulXtal_clk * 20 / ucplln / 2 / _XTAL27000K;
    pData[5] = (pData[5] + 25) / 50;
    pData[5] -= (pData[5] == 0) ? 0 : 1;   
   
    // DPPLL Power Down
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_70_MN_SCLKG_PLL_PWR, 0x80);

    // Disable M/N Tracking 
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_56_MN_SCLKG_TRK_CTRL, ~(_BIT7 | _BIT1 | _BIT0), (_BIT1 | _BIT0));     

    // Set PLL Charge Pump Current
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_71_MN_SCLKG_PLL_CHP, (0x70 | (pData[5] & 0x07)));

    // Set VCOMD, phase Swallow Circuit Clock Select, SCLKGSTOP
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_72_MN_SCLKG_PLL_WD, ~(0x7F), 0x16);

    // Set DPPLL Div_2 & Div_s
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_52_MN_SCLKG_DIVS, (((ucdiv2) << 7) | ((ucdivs) << 0)));

    // Set DPPLL Div_O.
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_70_MN_SCLKG_PLL_PWR, ~(_BIT1 | _BIT0), (ucpllo & (_BIT1 | _BIT0)));

    // Offset Value Setting
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_55_MN_SCLKG_OFFS_L, (BYTE)ulOffsetValue);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_54_MN_SCLKG_OFFS_M, (BYTE)(ulOffsetValue >> 8));
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_53_MN_SCLKG_OFFS_H, ~(_BIT2 | _BIT1 | _BIT0), ((BYTE)(ulOffsetValue >> 16)) & (_BIT1 | _BIT0));

    // Enable phase swallow
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_67_MN_SCLKG_SDM_CTRL, ~(_BIT5 | _BIT4), _BIT4);

    // Set DPPLL M Code    
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_51_MN_SCLKG_DIVM, ulpllm - 2);

    // PLL Input Clock select to Link Clock, Output Clock Select to PLL Clock, N Code --> 2, Double Buffer.
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_50_MN_SCLKG_CTRL, ~(0xFF), (_BIT7 | _BIT4));

    // Load offset value
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_53_MN_SCLKG_OFFS_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT7);
    
    // Double Buffer for M/N Tracking
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_50_MN_SCLKG_CTRL, ~_BIT4, _BIT4);  

    // DPLL Power On
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_70_MN_SCLKG_PLL_PWR, ~_BIT7, 0x00);
    
    ScalerTimerDelayXms(2);


    ////////////////////////////////
    // DPPLL VCO Band Calibration //
    ////////////////////////////////
    
    // Reg DPLL_CMPEN
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_70_MN_SCLKG_PLL_PWR, ~_BIT2, _BIT2);

    ScalerTimerDelayXms(2);

    // Reg DPLL_CALLCH
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_70_MN_SCLKG_PLL_PWR, ~_BIT3, _BIT3);

    ScalerTimerDelayXms(2);
    
    // Reg DPLL_CALSW
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_70_MN_SCLKG_PLL_PWR, ~_BIT4, _BIT4);


    ////////////////////////////////
    // DPPLL M/N Tracking Setting //
    ////////////////////////////////

    // Don't Use M/N Tracking for Nvid > 0x40000 or Nvid < 0xFF
    if((g_ulDpNvidValue <= 0x40000) && (g_ulDpNvidValue >= 0xFF))
    {
        //////////////////// Enable M/N auto tracking /////////////////////////
        // I = (2^22)*( (Tdds / Tmn) * (1 / n), n = 8
        // 1. Fdds = 1/4 * Fvco = (ulLinkClkValue / 8) * (ulpllm / ucplln) / 4 --> Tdds = (32 / ulLinkClkValue) * (plln / ulpllm)
        // 2. Tmn = Nvid * (1 / ulLinkClkValue)
        // from1,2 we can get : I = (2^27) * (ucplln / ulpllm) / Nvid / n = (2^24) * (ucplln / ulpllm) / Nvid

        ulIcodeValue = (16777216 / g_ulDpNvidValue) * ucplln / ulpllm;  //I = (2^24) * (ucplln / ulpllm) / Nvid

        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_57_MN_SCLKG_TRK_MN_I_H, (BYTE)(ulIcodeValue >> 16));        
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_58_MN_SCLKG_TRK_MN_I_M, (BYTE)(ulIcodeValue >> 8));        
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_59_MN_SCLKG_TRK_MN_I_L, (BYTE)ulIcodeValue);              

        // Set P Code
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_5A_MN_SCLKG_TRK_MN_P_H, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_5B_MN_SCLKG_TRK_MN_P_M, 0xFF);        
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_5C_MN_SCLKG_TRK_MN_P_L, 0xFF);   

        // Enable M/N Tracking 
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_56_MN_SCLKG_TRK_CTRL, ~_BIT7, _BIT7);
        
        // Double Buffer for M/N Tracking
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_50_MN_SCLKG_CTRL, ~_BIT4, _BIT4);       

        // Phase Error Threshold of M/N Tracking --> 0x2A
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_5E_MN_SCLKG_TRK_MN_NLOCK, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

        pData[0] = 0;

        while(pData[0] < 10)
        {
            DebugMessageDigital("7. wuzanne test : Wait DPPLL M/N Tracking Stable", pData[0]);
            
            ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_5E_MN_SCLKG_TRK_MN_NLOCK, ~_BIT5, _BIT5);

            ScalerTimerDelayXms(30);

            if(ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_5E_MN_SCLKG_TRK_MN_NLOCK, _BIT5) == 0x00)
            {
                break;
            }
            
            pData[0]++;
        }            

        // Disable M/N Tracking 
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_56_MN_SCLKG_TRK_CTRL, ~_BIT7, 0x00);

        // Double Buffer for M/N Tracking Setting
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_50_MN_SCLKG_CTRL, ~_BIT4, _BIT4);              
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Adjust Vsync Delay 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpAdjustVsyncDelay(void)
{
    DWORD ulBStoVSDelayDeltaOverflow = 0;
    DWORD ulBStoVSDelayDeltaUnderflow = 0;

    // Get Mvid
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_16_MN_M_VID_H, 3, &pData[4], _AUTOINC);

    // Get Nvid
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_19_MN_N_VID_H, 3, &pData[7], _AUTOINC);
        
    if(ScalerGetBit(PC_A6_DP_LANE_LOCK, (_BIT3 | _BIT2)) == 0x00)// Fifo Ok
    {
        return;
    }        
    else if(ScalerGetBit(PC_A6_DP_LANE_LOCK, _BIT3) == _BIT3) // Fifo Overflow
    {
        // Get Htotal
        ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_04_MN_STRM_ATTR_HTT_M, 2, &pData[10], _AUTOINC);

        // (Nvid * 256 / Mvid) * ((DWORD)Htotal) / 256 --> 1 Line
        ulBStoVSDelayDeltaOverflow = (((((DWORD)pData[7] << 16) | ((DWORD)pData[8] << 8) | ((DWORD)pData[9] << 0)) * 256 / (((DWORD)pData[4] << 16) | ((DWORD)pData[5] << 8) | ((DWORD)pData[6] << 0))) * ((DWORD)PDATA_WORD(5)) / 256);
        
        DebugMessageDigital("7. wuzanne test : Fifo Overflow --> nVidia Case", ulBStoVSDelayDeltaOverflow);
    }
    else if(ScalerGetBit(PC_A6_DP_LANE_LOCK, _BIT2) == _BIT2) // Fifo Underflow
    {
        // Get Hactive
        ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_42_MN_DPF_HWD_M, 2, &pData[10], _AUTOINC);

        if(PDATA_WORD(5) != 1366)
        {
            return;
        }
        
        PDATA_WORD(5) = PDATA_WORD(5) - 2;
   
        // Set Hactive
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_42_MN_DPF_HWD_M, pData[10]);
        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_43_MN_DPF_HWD_L, pData[11]);
        
        // (Nvid * 2 / Mvid) --> 2 pixels
        ulBStoVSDelayDeltaUnderflow  = ((((DWORD)pData[7] << 16) | ((DWORD)pData[8] << 8) | ((DWORD)pData[9] << 0)) * 2) / (((DWORD)pData[4] << 16) | ((DWORD)pData[5] << 8) | ((DWORD)pData[6] << 0));  
            
        DebugMessageDigital("7. wuzanne test : Fifo Underflow --> QD882 Case", ulBStoVSDelayDeltaUnderflow);
    }

    // Get BStoVSDelay Even
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_36_MN_EVBLK2VS_H, 3, &pData[1], _AUTOINC);    

    // Get BStoVSDelay Odd
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_39_MN_OVBLK2VS_H, 3, &pData[5], _AUTOINC);    
    
    // BStoVSDelay = BStoVSDelay + (Nvid * 256 / Mvid) * ((DWORD)Htotal) / 256;
    PDATA_DWORD(0) = PDATA_DWORD(0) - ulBStoVSDelayDeltaOverflow + ulBStoVSDelayDeltaUnderflow;

    // BStoVSDelay = BStoVSDelay + (Nvid * 256 / Mvid) * ((DWORD)Htotal) / 256;
    PDATA_DWORD(1) = PDATA_DWORD(1) - ulBStoVSDelayDeltaOverflow + ulBStoVSDelayDeltaUnderflow;

    // Set Even Field BS to VS Delay
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_36_MN_EVBLK2VS_H, pData[1]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_37_MN_EVBLK2VS_M, pData[2]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_38_MN_EVBLK2VS_L, pData[3]);

    // Set Odd Field BS to VS Delay
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_39_MN_OVBLK2VS_H, pData[5]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_3A_MN_OVBLK2VS_M, pData[6]);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_3B_MN_OVBLK2VS_L, pData[7]);
    
    // Enable Double Buffer
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_35_MN_DPF_CTRL, ~_BIT6, _BIT6);

    ScalerTimerDelayXms(30);    
}

//--------------------------------------------------
// Description  : DP Video Fifo Check
// Input Value  : Fifo Check Condition
// Output Value : True --> Fifo not over/underflow
//--------------------------------------------------
bit ScalerDpFifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition)
{
    if(enumFifoCheckCondition == _DP_FIFO_DELAY_CHECK)
    {
        ScalerSetBit(PC_A6_DP_LANE_LOCK, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

        ScalerTimerDelayXms(30);
        
        pData[0] = 0;

        while(pData[0] < 6)
        {
            ScalerTimerDelayXms(10);

            if((ScalerGetBit(PC_A6_DP_LANE_LOCK, _BIT3) == _BIT3) || (ScalerGetBit(PC_A6_DP_LANE_LOCK, _BIT2) == _BIT2))
            {
                return _FALSE;
            }
            
            pData[0]++;
        }
    }
    else
    {
        if((ScalerGetBit(PC_A6_DP_LANE_LOCK, _BIT3) == _BIT3) || (ScalerGetBit(PC_A6_DP_LANE_LOCK, _BIT2) == _BIT2))
        {
            return _FALSE;
        }       
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Sink Status Setting
// Input Value  : Receive Port, Sync Status
// Output Value : None
//--------------------------------------------------
void ScalerDpSinkStatusSet(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync)  
{    
    if(enumInSync == _DP_SINK_IN_SYNC)
    {
        if(enumReceiverPort == _DP_SINK_REVEICE_PORT0)
        {                
            // Set Receive Port 0 in Sync
            ScalerDpSetDpcdValue(0x00, 0x02, 0x05, (ScalerDpGetDpcdInfo(0x00, 0x02, 0x05) | _BIT0));
        }
        else
        {
            // Set Receive Port 1 in Sync
            ScalerDpSetDpcdValue(0x00, 0x02, 0x05, (ScalerDpGetDpcdInfo(0x00, 0x02, 0x05) | _BIT1));
        }
    }
    else
    {
        if(enumReceiverPort == _DP_SINK_REVEICE_PORT0)
        {
            // Set Receive Port 0 Out of Sync
            ScalerDpSetDpcdValue(0x00, 0x02, 0x05, (ScalerDpGetDpcdInfo(0x00, 0x02, 0x05) & ~_BIT0));
        }
        else
        {
            // Set Receive Port 1 Out of Sync
            ScalerDpSetDpcdValue(0x00, 0x02, 0x05, (ScalerDpGetDpcdInfo(0x00, 0x02, 0x05) & ~_BIT1));
        }
    }
}

//--------------------------------------------------
// Description  : DP CRC Calculate
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpCrcCalculate(void)
{
    if((ScalerDpGetDpcdInfo(0x00, 0x02, 0x70) & _BIT0) == _BIT0)
    {
        DebugMessageDigital("7. wuzanne test : DP CRC Test Start", 0);

        // Start CRC Calculation
        ScalerSetBit(PC_AB_DP_CRC, ~_BIT7, _BIT7);    

        if(ScalerTimerPollingFlagProc(100, PC_AB_DP_CRC, _BIT6, _TRUE))
        {
            ScalerDpSetDpcdValue(0x00, 0x02, 0x40, ScalerGetByte(PC_AD_DP_CRC_R_L));
            ScalerDpSetDpcdValue(0x00, 0x02, 0x41, ScalerGetByte(PC_AC_DP_CRC_R_H));
            ScalerDpSetDpcdValue(0x00, 0x02, 0x42, ScalerGetByte(PC_AF_DP_CRC_G_L));
            ScalerDpSetDpcdValue(0x00, 0x02, 0x43, ScalerGetByte(PC_AE_DP_CRC_G_H));
            ScalerDpSetDpcdValue(0x00, 0x02, 0x44, ScalerGetByte(PC_B1_DP_CRC_B_L));
            ScalerDpSetDpcdValue(0x00, 0x02, 0x45, ScalerGetByte(PC_B0_DP_CRC_B_H));

            // Update _TEST_CRC_COUNT
            ScalerDpSetDpcdValue(0x00, 0x02, 0x46, 0x21);
        }

        // Stop CRC Calculation
        ScalerSetBit(PC_AB_DP_CRC, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Check DP Link Integrity 
// Input Value  : None
// Output Value : FALSE => DP Link Integrity Fail
//--------------------------------------------------
bit ScalerDpHdcpCheck(void)
{    
    // Set Lane0 Clk Inverse
    ScalerSetBit(PC_A7_DP_LANE_CLK_INV, ~(_BIT7 | _BIT3), _BIT7);
    
    if(ScalerGetBit(PC_EA_HDCP_DEBUG, (_BIT7 | _BIT6 | _BIT5)) == (_BIT7 | _BIT6 | _BIT5))
    {
        if(ScalerGetBit(PC_E4_HDCP_INTGT_VRF, _BIT1) == _BIT1)
        {
            if(ScalerDpHdcpMeasureCheck() == _FALSE)
            {
                return _FALSE;
            }            
        }
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP HDCP Measure Check
// Input Value  : None
// Output Value : FALSE => Measure Check Fail
//--------------------------------------------------
bit ScalerDpHdcpMeasureCheck(void)
{
    // Pop up Main Stream Attributes
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_00_MN_STRM_ATTR_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

    // Get MSA Vtotal
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_0C_MN_STRM_ATTR_VTTE_M, 2, &pData[10], _AUTOINC);

    if(PDATA_WORD(5) == 0)
    {
        return _FALSE;
    }

    // Start to Measure Vertical BS to BS Counter by GDI Clock
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, ~_BIT7, _BIT7);

    pData[0] = 60;

    do
    {        
        if(ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, _BIT6) == _BIT6)
        {
            // Pop up Measure Result
            ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, ~_BIT5, _BIT5);
            
            break;
        }
        
        ScalerTimerDelayXms(1);        
    }
    while(--pData[0]);

    if(pData[0] == 0x00)
    {
        return _FALSE;      
    }

    // Get Measure V BS TO BS Result
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A0_MN_MEAS_CTRL, 3, &pData[1], _AUTOINC);

    // Get Measure H BS TO BS Result
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_A3_MN_MEAS_HLN_M, 2, &pData[6], _AUTOINC);

    PDATA_DWORD(0) = (PDATA_DWORD(0) & 0x001FFFFF);
    PDATA_DWORD(1) = (PDATA_DWORD(1) & 0x0000FFFF);
    
    PDATA_WORD(2) = PDATA_DWORD(0) / PDATA_DWORD(1);

    // 2% Tolerance
    if((ABSDWORD(PDATA_WORD(2), PDATA_WORD(5))) > (PDATA_WORD(5) * 2 / 100)) 
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Content Protection Interrupt Request
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpCpIRQ(void)
{
    // Link Status CPIRQ Flag
    ScalerDpSetDpcdValue(0x00, 0x02, 0x01, 0x04);

    // Link Integrity Failure Flag by FW
    ScalerDpSetDpcdValue(0x06, 0x80, 0x29, 0x04);

    // Reset HDCP Block
    ScalerSetBit(PC_E3_HDCP_IRQ, ~_BIT1, _BIT1);
    ScalerSetBit(PC_E3_HDCP_IRQ, ~_BIT1, 0x00);

    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);

    // Clear Aksv
    ScalerDpSetDpcdValue(0x06, 0x80, 0x07, 0x00);
    ScalerDpSetDpcdValue(0x06, 0x80, 0x08, 0x00);
    ScalerDpSetDpcdValue(0x06, 0x80, 0x09, 0x00);
    ScalerDpSetDpcdValue(0x06, 0x80, 0x0A, 0x00);
    ScalerDpSetDpcdValue(0x06, 0x80, 0x0B, 0x00);
       
    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
    
    ScalerDpHotPlugDuration(1);
}

//--------------------------------------------------
// Description  : Check whether HDCP is enabled
// Input Value  : None
// Output Value : TRUE => HDCP Enabled
//--------------------------------------------------
bit ScalerDpHdcpEnebled(void)
{
    if(ScalerGetBit(PC_EA_HDCP_DEBUG, (_BIT7 | _BIT6 | _BIT5)) == (_BIT7 | _BIT6 | _BIT5))
    {
        return _TRUE;
    }
    
    return _FALSE;
}

//--------------------------------------------------
// Description  : Check DP Into Power Saving
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpLowPowerCheck(BYTE ucPowerAction)
{    
    SET_DP_FAKE_LINK_TRAINING();

    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, 0x00);
    
    if(GET_DP_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS)
    {
        SET_DP_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);
    }

    ScalerSetBit(PC_D0_AUX_MODE_SET, ~_BIT1, _BIT1);
    
    // Turn Off Output Clock
    ScalerSetBit(PC_A2_DP_OUTPUT_CTL, ~_BIT4, _BIT4);

    // Turn Off SCLK PLL
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_70_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    // Set end to idle trigger Aux Int, Clear Aux INT Flag
    ScalerSetBit(PA_DA_DP_AUX_DIG_PHY_A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));  

    // Clear Manchester/Stop pattern/Sync_end pattern/Byte boundary check Error
    ScalerSetBit(PA_D9_DP_AUX_DIG_PHY_9, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    ScalerTimerDelayXms(2);

    if(ScalerGetBit(PA_DA_DP_AUX_DIG_PHY_A, _BIT0) == 0x00)
    {
        // Mac Swicth To HDMI
        ScalerSetBit(PC_A1_DP_CTL, ~_BIT5, _BIT5);

        // Aux PHY Power Saving Mode
        ScalerSetBit(PB_F1_AUX_2, ~_BIT1, _BIT1);

        // Aux Bias Current From POR
        ScalerSetBit(PB_F2_AUX_3, ~_BIT7, _BIT7);

        // Aux comm current select min
        ScalerSetBit(PB_F3_AUX_4, ~(_BIT7 | _BIT6), 0x00);        

        // GDI Bandgap Disable
        ScalerGDIBandgap(_OFF);                

        if(ucPowerAction == _POWER_STATUS_SAVING)
        {
            ScalerGDIPhyPowerSavingProc();           
        }
        else
        {                        
            ScalerGDIPhyPowerOffProc();
        }

        IP = 0x81;

        CLR_DP_PS_AUX_TOGGLE();       
        
        // Enable Aux INT
        ScalerSetBit(PA_DA_DP_AUX_DIG_PHY_A, ~(_BIT4 | _BIT0), (_BIT4));       

        DebugMessageDigital("6. wuzanne test : Low Power Event", 0);
    }
    else
    {
        SET_DP_PS_AUX_TOGGLE();
    }
}

#if(_DP_DUAL_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp Dual Mode Switch to TMDS
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpDualModeTmdsSetting(void)
{
    PCB_D1_DP_DUAL_HDMI_SETTING();         
}

//--------------------------------------------------
// Description  : Dp Dual Mode Switch to DP
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpDualModeDpSetting(void)
{
    PCB_D1_DP_DUAL_DP_SETTING();
}
#endif

//--------------------------------------------------
// Description  : Get DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
// Output Value : DPCD Information
//--------------------------------------------------
BYTE ScalerDpGetDpcdInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL)
{
    ScalerSetByte(PC_C1_DPCD_ACCESS_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte(PC_C2_DPCD_ACCESS_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte(PC_C3_DPCD_ACCESS_PORT_L, ucDpcdAccessPortL);

    return ScalerGetByte(PC_C4_DPCD_DATA_PORT_L);
}

//--------------------------------------------------
// Description  : Get DPCD Table Information in INT0
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
// Output Value : DPCD Information
//--------------------------------------------------
BYTE ScalerDpGetDpcdInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL) using 1
{
    ScalerSetByte_EXINT0(PC_C1_DPCD_ACCESS_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte_EXINT0(PC_C2_DPCD_ACCESS_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte_EXINT0(PC_C3_DPCD_ACCESS_PORT_L, ucDpcdAccessPortL);

    return ScalerGetByte_EXINT0(PC_C4_DPCD_DATA_PORT_L);
}

//--------------------------------------------------
// Description  : Set DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
//                ucDpcdValue --> DPCD Value
// Output Value : None
//--------------------------------------------------
void ScalerDpSetDpcdValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue)
{
    ScalerSetByte(PC_C1_DPCD_ACCESS_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte(PC_C2_DPCD_ACCESS_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte(PC_C3_DPCD_ACCESS_PORT_L, ucDpcdAccessPortL);
    ScalerSetByte(PC_C4_DPCD_DATA_PORT_L, ucDpcdValue);
}

//--------------------------------------------------
// Description  : Set DPCD Table Information in INT0
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
//                ucDpcdValue --> DPCD Value
// Output Value : None
//--------------------------------------------------
void ScalerDpSetDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue) using 1
{
    ScalerSetByte_EXINT0(PC_C1_DPCD_ACCESS_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte_EXINT0(PC_C2_DPCD_ACCESS_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte_EXINT0(PC_C3_DPCD_ACCESS_PORT_L, ucDpcdAccessPortL);
    ScalerSetByte_EXINT0(PC_C4_DPCD_DATA_PORT_L, ucDpcdValue);
}

//--------------------------------------------------
// Description  : DP Phy Setting in TP1 for PHY CTS
// Input Value  : FLD Reference Clock
// Output Value : None
//--------------------------------------------------
void ScalerDpPhyCtsTp1SetPhy(EnumDpTp1FLDClk enumDpTp1Clk)
{
    ///////////////////////////
    // RX CMU EN & Mac Power //
    ///////////////////////////
    
    // Disable RX_EN and CMU_EN
    ScalerSetByte(PB_B4_POWER_0, 0x00);

    // Disable Auto k-offset(foreground)
    ScalerSetBit(PB_B2_EQ_2, ~(_BIT6 | _BIT5), 0x00);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

    // Dual Mode Disable and Analog Select to DP
    ScalerSetBit(PB_AC_CDR_A, ~(_BIT3 | _BIT4), _BIT4);            
    
    // Digital PHY Select to DP
    ScalerSetBit(PB_E0_DIG00, ~_BIT4, 0x00);
       
    switch(g_ucDpPhyCtsCtrl & 0x30)
    {
        case 0x00: // Lane0 Test
        
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
            ScalerSetByte(PB_B4_POWER_0, 0x88);
#else
            ScalerSetByte(PB_B4_POWER_0, 0x11);
#endif
            break;

        case 0x10: // Lane1 Test
        
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
            ScalerSetByte(PB_B4_POWER_0, 0x44);
#else
            ScalerSetByte(PB_B4_POWER_0, 0x22);
#endif
            break;
        
        case 0x20: // Lane2 Test

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
            ScalerSetByte(PB_B4_POWER_0, 0x22);
#else
            ScalerSetByte(PB_B4_POWER_0, 0x44);
#endif
            break; 
        
        case 0x30: // Lane3 Test

#if(_PCB_DP_CONNECTOR_SWAP == _ON)
            ScalerSetByte(PB_B4_POWER_0, 0x11);
#else
            ScalerSetByte(PB_B4_POWER_0, 0x88);
#endif
            break;

        default:

            break;
    }
    
    ScalerSetByte(PC_A1_DP_CTL, 0x1C);


    /////////////////
    // CDR Setting //
    /////////////////
        
    if((g_ucDpPhyCtsCtrl & _BIT6) == _BIT6) // HBR
    {        
        // [7:6] High Bit Rate(2.7G)
        ScalerSetBit(PB_AC_CDR_A, ~(_BIT6 | _BIT7), _BIT6);

        // [7:6] vco_div = 00 VCO/1
        // [5] sel_bb = 1 BB PD
        // [4] sel_half = 1 full rate
        // [1:0] kvco = 1 526MHz/V
        ScalerSetByte(PB_A5_CDR_3, 0x31);

        // [7:4] cp_sel = 0001 7.5uA
        // [3:1] cpsr = 101 1k
        ScalerSetByte(PB_A6_CDR_4, 0x1A);
    }
    else // RBR
    {        
        // [7:6] High Bit Rate(2.7G)
        ScalerSetBit(PB_AC_CDR_A, ~(_BIT6 | _BIT7), _BIT6);

        // [7:6] vco_div = 00 VCO/1
        // [5] sel_bb = 1 BB PD
        // [4] sel_half = 1 full rate
        // [1:0] kvco = 1 526MHz/V
        ScalerSetByte(PB_A5_CDR_3, 0x31);

        // [7:4] cp_sel = 0001 7.5uA
        // [3:1] cpsr = 101 1k
        ScalerSetByte(PB_A6_CDR_4, 0x1A);
    }

    if(enumDpTp1Clk == _DP_FLD_REF_D10_2)
    {
        // D10.2 Lock FLD
        ScalerSetBit(PB_AB_CDR_9, ~_BIT6, 0x00);

        // For RBR
        ScalerSetBit(PB_C8_FLD_CONT_0, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT2 | _BIT0));
        ScalerSetByte(PB_C9_FLD_CONT_1, 0x0D);
        ScalerSetByte(PB_CA_FLD_CONT_2, 0x86);

        // For HBR
        ScalerSetBit(PB_CB_FLD_CONT_3, ~(_BIT7 | _BIT6), _BIT7);
        ScalerSetByte(PB_CC_FLD_CONT_4, 0x0D);
        ScalerSetByte(PB_CD_FLD_CONT_5, 0x86);
    }
    else if(enumDpTp1Clk == _DP_FLD_REF_XTAL)
    {
        // Xtal Lock FLD  
        ScalerSetBit(PB_AB_CDR_9, ~_BIT6, _BIT6);

        // For RBR
        ScalerSetBit(PB_C8_FLD_CONT_0, ~(_BIT7 | _BIT6), _BIT7);
        ScalerSetByte(PB_C9_FLD_CONT_1, 0x2B);
        ScalerSetByte(PB_CA_FLD_CONT_2, 0x31);
           
        // For HBR
        ScalerSetBit(PB_CB_FLD_CONT_3, ~(_BIT7 | _BIT6), _BIT7);
        ScalerSetByte(PB_CC_FLD_CONT_4, 0x2B);
        ScalerSetByte(PB_CD_FLD_CONT_5, 0x1D); 
    }        


    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // [7] FLD Auto Mode
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT7, _BIT7);

    // [4] Enable cp_adj_en : Add CP Current During FLD Lock Band
    // [3] Enable Adaptation when FLD Auto Mode
    ScalerSetBit(PB_AD_RXMISC_0, ~(_BIT4 | _BIT3), _BIT4); 
    
    // Disable De-Scrambling, Disable Commoa Detection
    ScalerSetBit(PB_E2_DIG02, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Enable Enhancement Control Mode --> Digital PHY
    ScalerSetBit(PB_E0_DIG00, ~_BIT5, _BIT5);


    /////////////////
    // DFE Setting //
    /////////////////   

    // Set DFE Initial

    if((g_ucDpPhyCtsCtrl & _BIT6) == _BIT6) // HBR
    {
        ScalerDpSetDFEInitial(_DP_LINK_HBR);
    }
    else
    {
        ScalerDpSetDFEInitial(_DP_LINK_RBR);
    }
    

    //////////////
    // K Offset //
    ////////////// 

    // [5] Foreground Calibration Auto Mode
    ScalerSetBit(PB_B2_EQ_2, ~(_BIT6 | _BIT5), _BIT5);

    // [6] Enable offset Calibration
    ScalerSetBit(PB_B2_EQ_2, ~_BIT6, _BIT6);
    
    // Waiting for K Offset 
    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        _nop_();
    }     

    
    ///////////////
    // FLD Reset //
    /////////////// 

    // sel_cktp1   
    ScalerSetBit(PB_A9_CDR_7, ~_BIT4, _BIT4);

    // FLD Reset
    ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT0, 0x00);
    ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT0, _BIT0);
    
    // Enable DFE Adaptation
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x61);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x61);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x61);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x61);     
    
    // Waiting for the FLD Band Searching
    for(pData[0] = 0; pData[0] <= 100; pData[0]++)
    {
        _nop_();
    }

    // Disable_cktp1   
    ScalerSetBit(PB_A9_CDR_7, ~_BIT4, 0x00);

    // Disable Adaptation
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);       

    // [4] Disable cp_adj_en : Add CP Current During FLD Lock Band
    // [3] Disable Adaptation when FLD Auto Mode
    ScalerSetBit(PB_AD_RXMISC_0, ~(_BIT4 | _BIT3), _BIT3); 

    // DP Mac Clock Select to Link Clock
    ScalerSetBit(PC_F6_AUX_ERROR_HANDLE2, ~_BIT4, 0x00);                
}

//--------------------------------------------------
// Description  : DP Phy Setting in TP2 for PHY CTS
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpPhyCtsTp2SetPhy(void)
{
    // Disable De-Scrambling, Enable Commoa Detection
    ScalerSetBit(PB_E2_DIG02, ~(_BIT7 | _BIT6), _BIT7);

    if((g_ucDpPhyCtsCtrl & _BIT6) == _BIT6)
    {   
        // Charge Pump Current and Resistor Double
        ScalerSetByte(PB_A6_CDR_4, 0x30);
    }
    else
    {
        // Charge Pump Current and Resistor Double
        ScalerSetByte(PB_A6_CDR_4, 0x32);
    }
        
    // Manual band 
    switch(g_ucDpPhyCtsCtrl & 0x30)
    {
        case 0x00: // Lane0 Test
        
            ScalerSetByte(PB_DC_VCO_4, ScalerGetByte(PB_D8_VCO_0));

            break;

        case 0x10: // Lane1 Test

            ScalerSetByte(PB_DD_VCO_5, ScalerGetByte(PB_D9_VCO_1));

            break;

        case 0x20: // Lane2 Test

            ScalerSetByte(PB_DE_VCO_6, ScalerGetByte(PB_DA_VCO_2));

            break;

        case 0x30: // Lane3 Test

            ScalerSetByte(PB_DF_VCO_7, ScalerGetByte(PB_DB_VCO_3));

            break;

        default:

           break;
    }
        
    // [7] auto_mode = 0 FLD Manual Mode
    // [5] cp_en_manual = 0 --> Disable Manual Enable CP
    // [4] adp_en_manual = 0 --> Disable  adaptation.
    // [3] calib_manual = 0 --> Disable Calibration Manual    
    ScalerSetBit(PB_AF_RXMISC_2, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3), 0x00);

    // Set DFE Initial

    if((g_ucDpPhyCtsCtrl & _BIT6) == _BIT6) // HBR
    {
        ScalerDpSetDFEInitial(_DP_LINK_HBR);
    }
    else
    {
        ScalerDpSetDFEInitial(_DP_LINK_RBR);
    }

    // Enable Adaptation
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0xE7);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0xE7);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0xE7);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0xE7); 
    
    // [5] cp_en_manual = 1 --> Manual Enable CP
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT5, _BIT5);
    
    // [4] adp_en_manual = 1 --> Close CDR loop. Enable adaptation.
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT4, _BIT4);

    // [3] calib_manual = 1 --> Calibration Manual
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT3, _BIT3);
    
    // Waiting for Adaptation
    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        _nop_();
    }
    
    // Disable Adaptation 
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00); 

    // Disable Adaptation
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT4, 0x00);

    if((g_ucDpPhyCtsCtrl & _BIT6) == _BIT6)
    {   
        // Charge Pump Current and Resistor Double
        ScalerSetByte(PB_A6_CDR_4, 0x1A);
    }
    else
    {
        // Charge Pump Current and Resistor Double
        ScalerSetByte(PB_A6_CDR_4, 0x10);
    }
}

//--------------------------------------------------
// Description  : DP FLD Band Detection in Phy CTS TP2
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpPhyCtsTp2SetPhyFLDBandDetect(void)
{
    BYTE ucCounter = 0;
    BYTE ucEQCRCStatus = 0;
    BYTE ucDpLane0FLDBandStatus = 0;
    BYTE ucDpLane1FLDBandStatus = 0;
    BYTE ucDpLane2FLDBandStatus = 0;
    BYTE ucDpLane3FLDBandStatus = 0;       

    for(ucCounter = 0; ucCounter <= 5; ucCounter++)
    {        
        // [5] cp_en_manual = 0 --> Disable Manual Enable CP
        // [3] calib_manual = 0 --> Disable Calibration Manual    
        ScalerSetBit(PB_AF_RXMISC_2, ~(_BIT5 | _BIT3), 0x00);
        
        // Manual band 
        ScalerSetByte(PB_DC_VCO_4, (ScalerGetByte(PB_D8_VCO_0) - 2 + ucCounter));
        ScalerSetByte(PB_DD_VCO_5, (ScalerGetByte(PB_D9_VCO_1) - 2 + ucCounter));
        ScalerSetByte(PB_DE_VCO_6, (ScalerGetByte(PB_DA_VCO_2) - 2 + ucCounter));
        ScalerSetByte(PB_DF_VCO_7, (ScalerGetByte(PB_DB_VCO_3) - 2 + ucCounter));

        // [5] cp_en_manual = 1 --> Manual Enable CP         
        ScalerSetBit(PB_AF_RXMISC_2, ~_BIT5, _BIT5);

        // Waiting for VCO Stable
        for(pData[0] = 0; pData[0] <= 2; pData[0]++)
        {
            _nop_();
        }        
        
        // [3] calib_manual = 1 --> Calibration Manual   
        ScalerSetBit(PB_AF_RXMISC_2, ~_BIT3, _BIT3);
                
        // Enable EQ-CRC and Clear EQ-CRC Status
        ScalerSetByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ScalerSetByte(PC_B4_DP_DATA_PORT, 0x8F);     
        ScalerSetByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ScalerSetByte(PC_B4_DP_DATA_PORT, 0x8F);         

        for(pData[0] = 0; pData[0] <= 6; pData[0]++)
        {
            _nop_();
        }

        ScalerSetByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ucEQCRCStatus = ScalerGetByte(PC_B4_DP_DATA_PORT);

        // Disable EQ-CRC
        ScalerSetByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL);
        ScalerSetByte(PC_B4_DP_DATA_PORT, 0x0F);                

        // Lane0 EQ-CRC Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if((ucEQCRCStatus & _BIT0) == 0x00)
#else
        if((ucEQCRCStatus & _BIT3) == 0x00)
#endif
        {
            if((ucDpLane0FLDBandStatus & _BIT7) == 0x00)
            {
                ucDpLane0FLDBandStatus |= _BIT7;
                
                if(ucCounter == 5)
                {
                    ucDpLane0FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    ucDpLane0FLDBandStatus += ucCounter;
                }  
            }
            else if((ucDpLane0FLDBandStatus & _BIT6) == _BIT6)
            {
                ucDpLane0FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                ucDpLane0FLDBandStatus += ucCounter;
            }
        }
        else
        {
            if(((ucDpLane0FLDBandStatus & _BIT7) == _BIT7) && ((ucDpLane0FLDBandStatus & _BIT6) == 0x00))
            {
                ucDpLane0FLDBandStatus |= _BIT6;
                ucDpLane0FLDBandStatus += (ucCounter - 1);
            }
        }             

        // Lane1 EQ-CRC Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if((ucEQCRCStatus & _BIT1) == 0x00)
#else
        if((ucEQCRCStatus & _BIT2) == 0x00)
#endif
        {
            if((ucDpLane1FLDBandStatus & _BIT7) == 0x00)
            {
                ucDpLane1FLDBandStatus |= _BIT7;
                
                if(ucCounter == 5)
                {
                    ucDpLane1FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    ucDpLane1FLDBandStatus += ucCounter;
                }                         
            }
            else if((ucDpLane1FLDBandStatus & _BIT6) == _BIT6)
            {
                ucDpLane1FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                ucDpLane1FLDBandStatus += ucCounter;
            }
        }
        else
        {            
            if(((ucDpLane1FLDBandStatus & _BIT7) == _BIT7) && ((ucDpLane1FLDBandStatus & _BIT6) == 0x00))
            {
                ucDpLane1FLDBandStatus |= _BIT6;
                ucDpLane1FLDBandStatus += (ucCounter - 1);
            }
        }

        // Lane2 EQ-CRC Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if((ucEQCRCStatus & _BIT2) == 0x00)
#else
        if((ucEQCRCStatus & _BIT1) == 0x00)
#endif
        {
            if((ucDpLane2FLDBandStatus & _BIT7) == 0x00)
            {
                ucDpLane2FLDBandStatus |= _BIT7;

                if(ucCounter == 5)
                {
                    ucDpLane2FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    ucDpLane2FLDBandStatus += ucCounter;
                }                        
            }
            else if((ucDpLane2FLDBandStatus & _BIT6) == _BIT6)
            {
                ucDpLane2FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                ucDpLane2FLDBandStatus += ucCounter;
            }
        }
        else
        {            
            if(((ucDpLane2FLDBandStatus & _BIT7) == _BIT7) && ((ucDpLane2FLDBandStatus & _BIT6) == 0x00))
            {
                ucDpLane2FLDBandStatus |= _BIT6;
                ucDpLane2FLDBandStatus += (ucCounter - 1);
            }
        }

        // Lane3 EQ-CRC Check
#if(_PCB_DP_CONNECTOR_SWAP == _ON)
        if((ucEQCRCStatus & _BIT3) == 0x00)
#else
        if((ucEQCRCStatus & _BIT0) == 0x00)
#endif
        {
            if((ucDpLane3FLDBandStatus & _BIT7) == 0x00)
            {
                ucDpLane3FLDBandStatus |= _BIT7;
                
                if(ucCounter == 5)
                {
                    ucDpLane3FLDBandStatus += (2 * ucCounter);
                }
                else
                {
                    ucDpLane3FLDBandStatus += ucCounter;
                }                          
            }
            else if((ucDpLane3FLDBandStatus & _BIT6) == _BIT6)
            {
                ucDpLane3FLDBandStatus |= _BIT5;
            }
            else if(ucCounter == 5)
            {
                ucDpLane3FLDBandStatus += ucCounter;
            }
        }
        else
        {                    
            if(((ucDpLane3FLDBandStatus & _BIT7) == _BIT7) && ((ucDpLane3FLDBandStatus & _BIT6) == 0x00))
            {
                ucDpLane3FLDBandStatus |= _BIT6;
                ucDpLane3FLDBandStatus += (ucCounter - 1);
            }
        }
    }    

    // [5] cp_en_manual = 0 --> Disable Manual Enable CP
    // [3] calib_manual = 0 --> Disable Calibration Manual    
    ScalerSetBit(PB_AF_RXMISC_2, ~(_BIT5 | _BIT3), 0x00);

    // Manual band
    if((ucDpLane0FLDBandStatus == 0) || ((ucDpLane0FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte(PB_DC_VCO_4, ScalerGetByte(PB_D8_VCO_0));            
    }
    else
    {
        ScalerSetByte(PB_DC_VCO_4, (ScalerGetByte(PB_D8_VCO_0) - 2 + (((ucDpLane0FLDBandStatus & 0x0F) + 1) / 2)));
    }

    // Manual band
    if((ucDpLane1FLDBandStatus == 0) || ((ucDpLane1FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte(PB_DD_VCO_5, ScalerGetByte(PB_D9_VCO_1));            
    }
    else
    {
        ScalerSetByte(PB_DD_VCO_5, (ScalerGetByte(PB_D9_VCO_1) - 2 + (((ucDpLane1FLDBandStatus & 0x0F) + 1) / 2)));
    }

    // Manual band
    if((ucDpLane2FLDBandStatus == 0) || ((ucDpLane2FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte(PB_DE_VCO_6, ScalerGetByte(PB_DA_VCO_2));            
    }
    else
    {
        ScalerSetByte(PB_DE_VCO_6, (ScalerGetByte(PB_DA_VCO_2) - 2 + (((ucDpLane2FLDBandStatus & 0x0F) + 1) / 2)));
    }

    // Manual band
    if((ucDpLane3FLDBandStatus == 0) || ((ucDpLane3FLDBandStatus & _BIT5) == _BIT5))
    {
        ScalerSetByte(PB_DF_VCO_7, ScalerGetByte(PB_DB_VCO_3));            
    }
    else
    {
        ScalerSetByte(PB_DF_VCO_7, (ScalerGetByte(PB_DB_VCO_3) - 2 + (((ucDpLane3FLDBandStatus & 0x0F) + 1) / 2)));     
    }
    
    // [5] cp_en_manual = 1 --> Manual Enable CP         
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT5, _BIT5);

    // Waiting for VCO Stable
    for(pData[0] = 0; pData[0] <= 3; pData[0]++)
    {
        _nop_();
    }        
    
    // [3] calib_manual = 1 --> Calibration Manual   
    ScalerSetBit(PB_AF_RXMISC_2, ~_BIT3, _BIT3); 
}

//--------------------------------------------------
// Description  : Check Dp Training Pattern 1 for PHY CTS
// Input Value  : None
// Output Value : TRUE --> TP1 Pass
//--------------------------------------------------
bit ScalerDpPhyCtsTp1Check(void)
{
    // Check 8B/10B
    ScalerSetByte(PC_A5_DP_LANE_VALID , 0xFF);

    // Wait for FLD Reset
    ScalerTimerDelayXms(2);

    switch(g_ucDpPhyCtsCtrl & 0x30)
    {
        case 0x00: // Lane0 Test
        
            // EQ auto K,Check lane0 CRC
            pData[0] = ScalerGetByte(PC_CC_LANE0_OUT);
            pData[1] = 0x08;

            break;

        case 0x10: // Lane1 Test
            
            // EQ auto K,Check lane1 CRC
            pData[0] = ScalerGetByte(PC_CD_LANE1_OUT);
            pData[1] = 0x04;

            break;

        case 0x20: // Lane2 Test
            
            // EQ auto K,Check lane2 CRC
            pData[0] = ScalerGetByte(PC_CE_LANE2_OUT);
            pData[1] = 0x02;

            break;

        case 0x30: // Lane3 Test
            
            // EQ auto K,Check lane3 CRC
            pData[0] = ScalerGetByte(PC_CF_LANE3_OUT);
            pData[1] = 0x01;

            break;

        default:

            pData[1] = 0xFF;

            break;
    }

    if(((ScalerGetByte(PC_A5_DP_LANE_VALID) & pData[1]) == 0x00) && ((pData[0] == 0x4A) || (pData[0] == 0xB5)))
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Dp Training Pattern 2 for PHY CTS
// Input Value  : None
// Output Value : TRUE --> TP2 Pass
//--------------------------------------------------
bit ScalerDpPhyCtsTp2Check(void)
{
    // For Mac Lane 0 clk
    ScalerSetBit( PC_F6_AUX_ERROR_HANDLE2, ~_BIT4, _BIT4);

    // Write Clear EQ-CRC twice : for hardware bug
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL, 0x8F);   		    																																																												
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL, 0x8F); 
    
    ScalerTimerDelayXms(2);
                                    
    ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_B3_DP_EQ_CRC_CTRL, 1, pData , _NON_AUTOINC); 

    ScalerSetBit( PC_F6_AUX_ERROR_HANDLE2, ~_BIT4, 0x00);
    
    switch(g_ucDpPhyCtsCtrl & 0x30)
    {
        case 0x00: // Lane0 Test

            pData[1] = 0x08;

            break;

        case 0x10: // Lane1 Test

            pData[1] = 0x04;

            break;

        case 0x20: // Lane2 Test

            pData[1] = 0x02;

            break;

        case 0x30: // Lane3 Test

            pData[1] = 0x01;

            break;

        default:

            pData[0] = 0xFF;
            pData[1] = 0xFF;

            break;
    }

    if((pData[0] & pData[1]) != 0x00)
    {
        return _FALSE;
    }

    return _TRUE;           
}

//--------------------------------------------------
// Description  : DP PHY CTS Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpPhyCTS(void)
{
    // g_ucDpPhyCtsCtrl(Page0x0B A0[7] = 1 --> PHY CTS Enable Start
    // g_ucDpPhyCtsCtrl(B3-D5[2:0]) = 0x01 --> CDR
    // g_ucDpPhyCtsCtrl(B3-D5[2:0]) = 0x02 --> EQ CRC
    // g_ucDpPhyCtsCtrl(B3-D5[2:0]) = 0x03 --> PRBS7 Error Counter Reset and Counter Start
    // g_ucDpPhyCtsCtrl(B3-D5[2:0]) = 0x04 --> PRBS7 Error Counter Read
    // g_ucDpPhyCtsCtrl(B3-D5[2:0]) = 0x05 --> PHY CTS Disable    
    // g_ucDpPhyCtsCtrl(B3-D5[5:4]) = 00 --> lane0
    // g_ucDpPhyCtsCtrl(B3-D5[5:4]) = 01 --> lane1
    // g_ucDpPhyCtsCtrl(B3-D5[5:4]) = 10 --> lane2
    // g_ucDpPhyCtsCtrl(B3-D5[5:4]) = 11 --> lane3
    // g_ucDpPhyCtsCtrl(B3-D5[6]) = 1 --> High Rate
    // g_ucDpPhyCtsCtrl(B3-D5[6]) = 0 --> Low Rate
    g_ucDpPhyCtsCtrl = 0x00;
    
    EX0 = 0;           
                   
    while(GET_DP_PHY_CTS_FLG() == _TRUE)
    {
        ScalerDebug();

        ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D5_REV_PORT_5, 1, &g_ucDpPhyCtsCtrl , _NON_AUTOINC);
    
        switch(g_ucDpPhyCtsCtrl & 0x07)
        {
            case 0x01: // CDR Lock Check     

                ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D5_REV_PORT_5, (g_ucDpPhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0))); // Clear DP PHY CTS Phase Info   		    																																																												
                
                ScalerDpPhyCtsTp1SetPhy(_DP_FLD_REF_D10_2);
                
                if(ScalerDpPhyCtsTp1Check() == _TRUE)
                {
                    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D4_REV_PORT_4, 0x01);   		    																																																												
                }
                else
                {   
                    ScalerDpPhyCtsTp1SetPhy(_DP_FLD_REF_XTAL);

                    if(ScalerDpPhyCtsTp1Check() == _TRUE)
                    {
                        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D4_REV_PORT_4, 0x01);   		    																																																												
                    }
                    else
                    {
                        ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D4_REV_PORT_4, 0xFF);
                    }
                }
              
                break;
               
            case 0x02: // Symbol Lock Check
            
                ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D5_REV_PORT_5, (g_ucDpPhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0))); 

                ScalerDpPhyCtsTp2SetPhy();
                
                ScalerDpPhyCtsTp2SetPhyFLDBandDetect();
                
                if(ScalerDpPhyCtsTp2Check() == _TRUE)
                {
                    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D4_REV_PORT_4, 0x01); 
                }
                else
                {
                    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D4_REV_PORT_4, 0xFF); 
                }

                break;
      
            case 0x03:
                
                 ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D5_REV_PORT_5, (g_ucDpPhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0))); 
                
                 switch(g_ucDpPhyCtsCtrl & 0x30)
                 {
                    case 0x00: // Lane0 Test
                    
                        ScalerSetByte(PB_E5_DIG05, 0x00);

                        break;

                    case 0x10: // Lane1 Test

                        ScalerSetByte(PB_E5_DIG05, 0x20);

                        break;

                    case 0x20: // Lane2 Test

                        ScalerSetByte(PB_E5_DIG05, 0x40);

                        break;

                    case 0x30: // Lane3 Test

                        ScalerSetByte(PB_E5_DIG05, 0x60);

                        break;

                    default:
                        break;
                }
                 
                ScalerSetByte(PB_E2_DIG02, 0x84);
                ScalerSetByte(PB_E3_DIG03, 0x80);                
                ScalerSetByte(PB_E3_DIG03, 0x88);
                ScalerSetByte(PB_E3_DIG03, 0x08);

                ScalerTimerDelayXms(10);

                ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D4_REV_PORT_4, 0x00);
                
                break;

            case 0x04:

                ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D5_REV_PORT_5, (g_ucDpPhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0))); 
                
                if(ScalerGetByte(PB_E6_DIG06) != 0x00)
                {
                    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D4_REV_PORT_4, ScalerGetByte(PB_E8_DIG08)); 
                }
                else
                {
                    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D4_REV_PORT_4, 0xFF); 
                }
                
                break;
                
            case 0x05:
                
                g_ucDpPhyCtsCtrl = 0x00;

                // Clear DP PHY CTS Result
                ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D4_REV_PORT_4, 0x00);

                // Clear DP PHY CTS Control Register
                ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_D5_REV_PORT_5, 0x00);

                CLR_DP_PHY_CTS_FLG();
                
                break;  
          
            default:
                
                ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, 0xD0, 0x99);    

                break;
        }              
    }
}

#if(_DP_ASSR_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP ASSR Mode On/ Off
// Input Value  : _ON/ _OFF
// Output Value : None
//--------------------------------------------------
void ScalerDpASSRModeSetting(void)
{
    if((ScalerDpGetDpcdInfo(0x00, 0x01, 0x0A) & _BIT0) == _BIT0)
    {
        // Scramble seed equal to 0xFFFE
        ScalerSetBit_EXINT0(PB_E9_SSCG_DIG, ~_BIT0, 0x00);
    }
    else
    {
        // Scramble seed equal to 0xFFFF
        ScalerSetBit_EXINT0(PB_E9_SSCG_DIG, ~_BIT0, _BIT0);
    }
}
#endif // End of #if(_DP_ASSR_MODE_SUPPORT == _ON)

#endif // End for #if(_DP_SUPPORT == _ON)
