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
// ID Code      : RL6336_Series_TMDS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6336_SERIES_TMDS__

#include "ScalerFunctionInclude.h"

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Measure Clk Source
//--------------------------------------------------
#define _CLK_SOURCE_RED                         0
#define _CLK_SOURCE_BLUE                        1
#define _CLK_SOURCE_GREEN                       2
#define _CLK_SOURCE_TMDS                        3

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
bit g_bTmdsPhySet = _FALSE;
BYTE g_ucTmdsCtrl = 0;
WORD g_usTmdsClkCount = 0;
bit g_bTmdsD0DdcDetected = 0;
bit g_bTmdsD1DdcDetected = 0;
bit g_bTmdsD2DdcDetected = 0;
bit g_bTmdsD3DdcDetected = 0;
    
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerTmdsInitial(BYTE ucInputPort);
void ScalerTmdsInterruptInitial(void);
void ScalerTmdsSetDFEInitial_EXINT0(void);
void ScalerTmdsDFEAdaptation_EXINT0(EnumDfeLaneNumber enumDfeLane);
void ScalerTmdsDFEAdaptation(EnumDfeLaneNumber enumDfeLane);
void ScalerTmdsSetPhy_EXINT0(void);
void ScalerTmdsIntHandler_EXINT0(void);
bit ScalerTmdsCheckCDRStable(WORD usClkCount);
BYTE ScalerTmdsCheckCDRStable_EXINT0(WORD usClkCount);
WORD ScalerTmdsMeasureClk(BYTE ucMeasureClk);
WORD ScalerTmdsMeasureClk_EXINT0(BYTE ucMeasureClk);
BYTE ScalerTmdsFormatDetect(void);
void ScalerTmdsDviVideoSetting(void);
void ScalerTmdsSetPorchColor(BYTE ucColorSpace);

#if(_HDMI_SUPPORT == _ON)
void ScalerTmdsHdmiVideoSetting(void);
void ScalerTmdsHdmiPacketDetect(bit bWait);
void ScalerTmdsHdmiPacketDetectEvent(void);
bit ScalerTmdsHdmiColorInfoChanged(void);
BYTE ScalerTmdsHdmiGetColorDepth(void);
bit ScalerTmdsHdmiDeepColorProc(void);
void ScalerTmdsHdmiAVMuteProc(void);
void ScalerTmdsHdmiWatchDog(BYTE ucWDType, bit bEnable);
#endif

void ScalerTmdsPowerSavingProc(void);
void ScalerTmdsPowerOffProc(void);
void ScalerTmdsFreqDetectDisable(void);
BYTE ScalerTmdsDdcDetect_EXINT1(void);
void ScalerTmdsFirstActiveProc(BYTE ucSourceType);
bit ScalerTmdsHdcpEnabled(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Initialize TMDS setting for search
// Input Value  : Current Search Port
// Output Value : None
//--------------------------------------------------
void ScalerTmdsInitial(BYTE ucInputPort)
{
    if(GET_TMDS_HPD_TRIGGER_EVENT() == _TRUE)
    {
        if(ucInputPort == _D0_INPUT_PORT)
        {
            PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);

            ScalerTimerDelayXms(200);

            PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);    
        }
        else if(ucInputPort == _D1_INPUT_PORT)
        {
            PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);

            ScalerTimerDelayXms(200);

            PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);    
        }
        else if(ucInputPort == _D2_INPUT_PORT)
        {
            PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);

            ScalerTimerDelayXms(200);

            PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);    
        }
        else if(ucInputPort == _D3_INPUT_PORT)
        {
            PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);

            ScalerTimerDelayXms(200);

            PCB_D3_HOTPLUG(_D3_HOT_PLUG_HIGH);    
        }
                           
        CLR_TMDS_HPD_TRIGGER_EVENT();
    }
    
    if(ucInputPort == _D2_INPUT_PORT)
    {
#if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
        ucInputPort = _D0_INPUT_PORT;
#elif(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
        ucInputPort = _D1_INPUT_PORT;
#endif
    }

    if(ucInputPort == _D3_INPUT_PORT)
    {
#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
        ucInputPort = _D0_INPUT_PORT;
#elif(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
        ucInputPort = _D1_INPUT_PORT;
#endif
    }  
    
    // Disable TMDS output
    ScalerSetBit(P2_A6_TMDS_OUTPUT_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);    

    // Set HS Width(DE only),RL6336 delete HDCP Vsync selection 
    ScalerSetBit(P2_AB_TMDS_ACC2, ~_BIT7, 0x00);

#if(_HDMI_SUPPORT == _ON)
    // Disable TMDS Watch Dog in TMDS Initial
    ScalerTmdsHdmiWatchDog((_HDMI_AVI_INFO_VARIATION_WD | _HDMI_AV_MUTE_WD), _DISABLE);
    
    // Deep Color Mode detection auto,RL6336 Deep color clock select has been deleted
    ScalerSetBit(P2_B8_TMDS_DPC1, ~_BIT2, _BIT2);

    // Enable BCH Detection
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_02_HDMI_BCHCR, ~(_BIT6 | _BIT3 | _BIT2 | _BIT1), (_BIT6 | _BIT3 | _BIT2 | _BIT1));

    // Set Video Watch Dog New Mode
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_32_HDMI_WDCR1, ~_BIT5, _BIT5); 

    // Specify Packet Detect Type
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_43_HDMI_PTRSV0, _AVI_INFO_TYPE);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_44_HDMI_PTRSV1, _GENERAL_CONTROL_TYPE);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_A5_HDMI_PTRSV3, _SPD_INFO_TYPE);
#endif

    // Packet Variation Detect Disable
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_45_HDMI_PVGCR0, 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_46_HDMI_PVGCR1, 0x00);
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_47_HDMI_PVGCR2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_A9_HDMI_PVSR4, ~(_BIT7 | _BIT6 | _BIT5), 0x00); 
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_AA_HDMI_PVGCR3, 0x00);    
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_AB_HDMI_PVGCR4, ~(_BIT7 | _BIT6 | _BIT5), 0x00);      
#endif
    
    // Set HDCP DDC Channel
    ScalerSetBit(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), _BIT1);
    
    // Set HDCP DDC Debounce, TMDS Function
    ScalerSetBit(P2_AC_Z0CC2, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));
    
    // Set HDCP Feature
#if(_HDMI_SUPPORT == _ON)    

#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_0)
    ScalerSetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, 0x81);
#elif(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_1)
    ScalerSetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, 0x83);
#else
    ScalerSetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, 0x81);
#endif

#else // Else of #if(_HDMI_SUPPORT == _ON)

#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_0)
    ScalerSetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, 0x01);
#elif(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_1)
    ScalerSetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, 0x03);
#else
    ScalerSetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, 0x01);
#endif

#endif

    // Enable New Advance Cipher Mode, Enable HDCP Module
    ScalerSetBit(P2_C0_HDCP_CTRL, ~(_BIT7 | _BIT0), (_BIT7 | _BIT0));

    // MAC Select to TMDS
    ScalerSetBit(PC_A1_DP_CTL, ~_BIT5, _BIT5);

    // Enable MAC Input
    ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Set MAC Signal Swap
    ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~(_BIT6 | _BIT5), ((ucInputPort == _D0_INPUT_PORT) ? ((_D0_TMDS_BR_SWAP << 6) | (_D0_TMDS_PN_SWAP << 5)) : ((_D1_TMDS_BR_SWAP << 6) | (_D1_TMDS_PN_SWAP << 5))));

    // Auto switch to DVI when no signal
    ScalerSetBit(P2_AD_CPS, ~_BIT2, _BIT2);

    // Detec TMDS Format by both Video and Data Island Guard Band
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, ~(_BIT4 | _BIT1), _BIT1);
    
    // Enable TMDS MAC Error Correction
    ScalerSetBit(P2_B7_UP_DOWN_CTRL2, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));
}

//--------------------------------------------------
// Description  : Initialize TMDS Interrupt Required Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsInterruptInitial(void)
{
    if(ScalerGetBit(P2_E6_HDMI_FREQDET_CTRL, _BIT1) == 0x00)
    {
        CLR_TMDS_PHY_SET();
    }

    // Enable Rx_En for Clk pair Z0
    ScalerSetBit(PB_B4_POWER_0, ~_BIT3, _BIT3);

    // Choose Measure Clk to TMDS Clk
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), 0x00);

    // Settings for IRQ set PHY
    // Consider using table to fill all required initial settings
    // Set pre-set threshold (225MHz * 0.01 * 1000/ GDI_CLK)
    ScalerSetByte(P2_E7_HDMI_FREQDET_OFFSET, (_TMDS_FREQ_NORMAL_OFFSET & 0x7F));

    // Set Upper Bound
    ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_NORMAL_UPPER_BOUND));
    ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_NORMAL_UPPER_BOUND));    

    // Set Lower Bound
    ScalerSetByte(P2_EA_HDMI_FREQDET_LOWER_M, HIBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));
    ScalerSetByte(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));

    // Set Stable Time (0x7F = about 5ms)
    ScalerSetByte(P2_EC_HDMI_FREQDET_STABLE, 0x7F);

    // Disable Freq. Unstable IRQ
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT1, 0x00);

    // Enable Freq. Stable IRQ
    ScalerSetBit(P2_EF_HDMI_FREQDET_RESERVED, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Clear IRQ Pending Flag
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_60_HDMI_INTCR, ~_BIT7, _BIT7);

    // Internal IRQ Enable (Global)
    ScalerGlobalIRQControl(_ENABLE);

    EX0 = 1;
    
    // Start Freq. Detection
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, _BIT7);    
}

//--------------------------------------------------
// Description  : TMDS DFE Initial Setting (EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsSetDFEInitial_EXINT0(void) using 1
{
    // Disable DFE Adaptation
    ScalerSetByte_EXINT0(P1D_A1_DFE_EN_2, 0x00);

    // [7] clk_inv = 1 --> Negative Symbol-Rate Clock
    // [6] timer_ctrl_en = 1 --> Enable Timer Control for DFE Loop
    // [5:4] reduce_adapt_gain[1:0] = 2'b00 --> No Reduce Gain
    // [3] rl_det_en = 0 --> Disable Running Length Detection
    // [2] rl_det_mode = 0 --> Bypass Case-3 Symbol
    ScalerSetBit_EXINT0(P1D_A0_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6));
    
    // [7:6] adapt_mode[1:0] = 2'b11 --> Amplitude-based Adaptation without Independent LE Loop      
    // [5] edge_det_mode = 1 --> Edge Lag Data                                                                              
    // [4] transition_only = 1 --> Only Transition Bit Is Effective                                                                                                                   
    // [3] le_auto_reload = 0 --> Disable Auto-reload LE Coefficient  
    // [2:0] tap1_delay[2:0] = 3'b010 --> Tap1+LE Delay 2us after Tap0 
    ScalerSetByte_EXINT0(P1D_E0_MODE_TIMER, 0xF2);                        

    // [0] tap0_notransition = 1 --> Transition bit is Ineffective on Tap0 
    ScalerSetBit_EXINT0(P1D_E1_TIMER, ~_BIT0, _BIT0);

    // Filter's Gain of Tap0/1
    ScalerSetBit_EXINT0(P1D_E2_GAIN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2) , (_BIT6| _BIT4));                        

    // Set Vth/Tap0/Tap1 Max and Min Value
    ScalerSetByte_EXINT0(P1D_E6_LIMIT_1, 0xF6);
    ScalerSetBit_EXINT0(P1D_EF_RESET_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
    ScalerSetByte_EXINT0(P1D_E7_LIMIT_2, 0xAE); 

    // Set Vth/Tap Divider
    ScalerSetBit_EXINT0(P1D_EC_LOOP_DIV_1, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
    ScalerSetByte_EXINT0(P1D_ED_LOOP_DIV_2, 0xCA);

    // Initial DFE Code
    ScalerSetBit_EXINT0(P1D_A3_INIT_1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerSetBit_EXINT0(P1D_A4_INIT_2, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

    if(GET_INPUT_PIXEL_CLK() > 1200)
    {
        ScalerSetBit_EXINT0(P1D_A5_INIT_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));
    }
    else if(GET_INPUT_PIXEL_CLK() > 450)
    {
        ScalerSetBit_EXINT0(P1D_A5_INIT_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
    }
    else
    {
        ScalerSetBit_EXINT0(P1D_A5_INIT_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
    }

    ScalerSetBit_EXINT0(P1D_A9_INIT_7, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);

    // Initial Reload
    ScalerSetBit_EXINT0(P1D_EF_RESET_1, ~_BIT0, 0x00); 
    ScalerSetBit_EXINT0(P1D_EF_RESET_1, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : TMDS DFE Adaptaion Loop (EXINT0 Only)
// Input Value  : enumDfeLane -> DFE lane number
// Output Value : NONE
//--------------------------------------------------
void ScalerTmdsDFEAdaptation_EXINT0(EnumDfeLaneNumber enumDfeLane) using 1
{
    BYTE ucTemp = 0; 
    BYTE ucVth = 0;
    BYTE ucTap0 = 0;

    // [4] dfe_clk_en = 0 --> Disable DFE CLK
    ScalerSetBit_EXINT0(P1D_B0_DFE_TIME_SHARING_EN, ~_BIT4, 0x00); 

    // Disable DFE Adaptation
    ScalerSetBit_EXINT0(P1D_A1_DFE_EN_2, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), 0x00);

    switch(enumDfeLane)
    {
        case _DFE_LANE2:

            // [3:2] tshare_lane[1;0] = 2'b10 --> Lane2 Adaptation
            ScalerSetBit_EXINT0(P1D_B0_DFE_TIME_SHARING_EN, ~(_BIT3 | _BIT2), _BIT3);

            break;

        case _DFE_LANE1:

            // [3:2] tshare_lane[1;0] = 2'b01 --> Lane1 Adaptation
            ScalerSetBit_EXINT0(P1D_B0_DFE_TIME_SHARING_EN, ~(_BIT3 | _BIT2), _BIT2);
            
            break;

        case _DFE_LANE0:
        default:

            // [3:2] tshare_lane[1;0] = 2'b00 --> Lane0 Adaptation
            ScalerSetBit_EXINT0(P1D_B0_DFE_TIME_SHARING_EN, ~(_BIT3 | _BIT2), 0x00);

            break;
    }

    // [4] dfe_clk_en = 1 --> Enable DFE CLK
    ScalerSetBit_EXINT0(P1D_B0_DFE_TIME_SHARING_EN, ~_BIT4, _BIT4); 

    // [5:4] reduce_adapt_gain[1:0] = 2'b00 --> Restore DFE Gain to 1
    ScalerSetBit_EXINT0(P1D_A0_DFE_EN_1, ~(_BIT5 | _BIT4), 0x00);

   // Enable Adaptation 
    if(GET_INPUT_PIXEL_CLK() > 800) // High Freq.
    {      
        // [7] tap1_en = 1 --> Enable DFE Tap1
        ScalerSetBit_EXINT0(PB_B0_EQ_0, ~_BIT7, _BIT7);

        // Enable the LE, Vth-adjust, tap0~1 DFE Adaptation
        ScalerSetBit_EXINT0(P1D_A1_DFE_EN_2, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), (_BIT7 | _BIT6 | _BIT1 | _BIT0));
    }
    else
    {
        // [7] tap1_en = 0 --> Disable DFE Tap1
        ScalerSetBit_EXINT0(PB_B0_EQ_0, ~_BIT7, 0x00);
        
        // Disable DFE Adaptation
        ScalerSetBit_EXINT0(P1D_A1_DFE_EN_2, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), 0x00);
    } 

    // Waiting for DFE Adaptation
    for(ucTemp = 0; ucTemp <= 80; ucTemp++)
    {
        _nop_();
    }

    // [5:4] reduce_adapt_gain[1:0] = 2'b10 --> Reduce DFE Gain to 1/4 
    ScalerSetBit_EXINT0(P1D_A0_DFE_EN_1, ~(_BIT5 | _BIT4), _BIT5);

    // Waiting for DFE Adaptation
    for(ucTemp = 0; ucTemp <= 20; ucTemp++)
    {
        _nop_();
    }

    // Disable Vth Adaptation
    ScalerSetBit_EXINT0(P1D_A1_DFE_EN_2, ~_BIT6, 0x00);
}

//--------------------------------------------------
// Description  : TMDS DFE Adaptaion Loop
// Input Value  : enumDfeLane -> DFE lane number
// Output Value : NONE
//--------------------------------------------------
void ScalerTmdsDFEAdaptation(EnumDfeLaneNumber enumDfeLane)
{
    BYTE ucTemp = 0; 
    BYTE ucVth = 0;
    BYTE ucTap0 = 0;

    // [4] dfe_clk_en = 0 --> Disable DFE CLK
    ScalerSetBit(P1D_B0_DFE_TIME_SHARING_EN, ~_BIT4, 0x00); 

    // Disable DFE Adaptation
    ScalerSetBit(P1D_A1_DFE_EN_2, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), 0x00);

    switch(enumDfeLane)
    {
        case _DFE_LANE2:

            // [3:2] tshare_lane[1;0] = 2'b10 --> Lane2 Adaptation
            ScalerSetBit(P1D_B0_DFE_TIME_SHARING_EN, ~(_BIT3 | _BIT2), _BIT3);

            break;

        case _DFE_LANE1:

            // [3:2] tshare_lane[1;0] = 2'b01 --> Lane1 Adaptation
            ScalerSetBit(P1D_B0_DFE_TIME_SHARING_EN, ~(_BIT3 | _BIT2), _BIT2);
            
            break;

        case _DFE_LANE0:
        default:

            // [3:2] tshare_lane[1;0] = 2'b00 --> Lane0 Adaptation
            ScalerSetBit(P1D_B0_DFE_TIME_SHARING_EN, ~(_BIT3 | _BIT2), 0x00);

            break;
    }

    // [4] dfe_clk_en = 1 --> Enable DFE CLK
    ScalerSetBit(P1D_B0_DFE_TIME_SHARING_EN, ~_BIT4, _BIT4); 

    // [7] tap1_en = 1 --> Enable DFE Tap1
    ScalerSetBit(PB_B0_EQ_0, ~_BIT7, _BIT7);

    // Enable the LE, tap0~1 DFE Adaptation
    ScalerSetBit(P1D_A1_DFE_EN_2, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));

    // Waiting for DFE Adaptation
    for(ucTemp = 0; ucTemp <= 80; ucTemp++)
    {
        _nop_();
    }
}

//--------------------------------------------------
// Description  : TMDS Set PHY Function (EXINT0 Only)
// Input Value  : Measured Clk Count for PHY Setting
// Output Value : None
//--------------------------------------------------
void ScalerTmdsSetPhy_EXINT0(void) using 1
{       
    BYTE ucTemp = 0; 

    ///////////////
    // RX CMU EN //
    ///////////////
    
    // [3:0] rx_en = 4'b1111 --> Enable RXEN for Lane0~3
    ScalerSetBit_EXINT0(PB_B4_POWER_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // [7] cmu_en[3] = 0 --> Disable Power Control for VCO of Lane3(Clock Lane)
    // [6:4] cmu_en[2:0] = 3'b001 > 3'b011 > 3'b111 --> Sequentially Enable Power Control for VCO of Lane0~2
    ScalerSetBit_EXINT0(PB_B4_POWER_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    ScalerSetBit_EXINT0(PB_B4_POWER_0, ~_BIT4, _BIT4);
    ScalerSetBit_EXINT0(PB_B4_POWER_0, ~_BIT5, _BIT5);
    ScalerSetBit_EXINT0(PB_B4_POWER_0, ~_BIT6, _BIT6);


    /////////////////
    // VCO Setting //
    /////////////////
    
    if((GET_INPUT_PIXEL_CLK() >= 150) && (GET_INPUT_PIXEL_CLK() < 225))
    {
        // [2:0] sel_rate[2:0] = 3'b011 --> VCO Divider = 8
        ScalerSetBit_EXINT0(PB_A1_CMU_1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

        // [7:4] pre_div[3:0] = 4'b0000 --> M = 2
        // [3] bypass_ckref = 1 --> CMU's pre-divider = 1
        ScalerSetBit_EXINT0(PB_A3_CMU_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT3);

        // [2] sel_lowkvco = 1 --> Low KVCO for 1.2G~1.8G
        // [1] sel_cp = 1 --> CMU's Loop Filter's Parallel Capacitor = 2pF
        ScalerSetBit_EXINT0(PB_A5_CMU_5, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

        // [7:3] sel_icp[4:0] = 5'b01111 --> Icp = 20uA
        // [2:0] sel_rs[2:0] = 3'b011 --> Rs = 10K
        ScalerSetByte_EXINT0(PB_A6_CMU_6, 0x7B);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 225) && (GET_INPUT_PIXEL_CLK() < 300))
    {
        // [2:0] sel_rate[2:0] = 3'b011 --> VCO Divider = 8
        ScalerSetBit_EXINT0(PB_A1_CMU_1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

        // [7:4] pre_div[3:0] = 4'b0000 --> M = 2
        // [3] bypass_ckref = 1 --> CMU's pre-divider = 1
        ScalerSetBit_EXINT0(PB_A3_CMU_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT3);
        
        // [2] sel_lowkvco = 0 --> High KVCO for 1.8G~2.4G
        // [1] sel_cp = 1 --> CMU's Loop Filter's Parallel Capacitor = 2pF
        ScalerSetBit_EXINT0(PB_A5_CMU_5, ~(_BIT2 | _BIT1), _BIT1);

        // [7:3] sel_icp[4:0] = 5'b01011 --> Icp = 15uA
        // [2:0] sel_rs[2:0] = 3'b011 --> Rs = 10K
        ScalerSetByte_EXINT0(PB_A6_CMU_6, 0x5B);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 300) && (GET_INPUT_PIXEL_CLK() < 450))
    {        
        // [2:0] sel_rate[2:0] = 3'b010 --> VCO Divider = 4
        ScalerSetBit_EXINT0(PB_A1_CMU_1, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

        // [7:4] pre_div[3:0] = 4'b0000 --> M = 2
        // [3] bypass_ckref = 0 --> CMU's pre-divider = M
        ScalerSetBit_EXINT0(PB_A3_CMU_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);

        // [2] sel_lowkvco = 1 --> Low KVCO for 1.2G~1.8G
        // [1] sel_cp = 1 --> CMU's Loop Filter's Parallel Capacitor = 2pF
        ScalerSetBit_EXINT0(PB_A5_CMU_5, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

        // [7:3] sel_icp[4:0] = 5'b01111 --> Icp = 20uA
        // [2:0] sel_rs[2:0] = 3'b011 --> Rs = 10K
        ScalerSetByte_EXINT0(PB_A6_CMU_6, 0x7B);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 450) && (GET_INPUT_PIXEL_CLK() < 600))
    {
        // [2:0] sel_rate[2:0] = 3'b010 --> VCO Divider = 4
        ScalerSetBit_EXINT0(PB_A1_CMU_1, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

        // [7:4] pre_div[3:0] = 4'b0000 --> M = 2
        // [3] bypass_ckref = 0 --> CMU's pre-divider = M
        ScalerSetBit_EXINT0(PB_A3_CMU_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);
        
        // [2] sel_lowkvco = 0 --> High KVCO for 1.8G~2.4G
        // [1] sel_cp = 1 --> CMU's Loop Filter's Parallel Capacitor = 2pF
        ScalerSetBit_EXINT0(PB_A5_CMU_5, ~(_BIT2 | _BIT1), _BIT1);

        // [7:3] sel_icp[4:0] = 5'b01011 --> Icp = 15uA
        // [2:0] sel_rs[2:0] = 3'b011 --> Rs = 10K
        ScalerSetByte_EXINT0(PB_A6_CMU_6, 0x5B);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 600) && (GET_INPUT_PIXEL_CLK() < 900))
    {
        // [2:0] sel_rate[2:0] = 3'b001 --> VCO Divider = 2
        ScalerSetBit_EXINT0(PB_A1_CMU_1, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);

        // [7:4] pre_div[3:0] = 4'b0010 --> M = 4
        // [3] bypass_ckref = 0 --> CMU's pre-divider = M
        ScalerSetBit_EXINT0(PB_A3_CMU_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT5);
      
        // [2] sel_lowkvco = 1 --> Low KVCO for 1.2G~1.8G
        // [1] sel_cp = 1 --> CMU's Loop Filter's Parallel Capacitor = 2pF
        ScalerSetBit_EXINT0(PB_A5_CMU_5, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

        // [7:3] sel_icp[4:0] = 5'b01111 --> Icp = 20uA
        // [2:0] sel_rs[2:0] = 3'b011 --> Rs = 10K
        ScalerSetByte_EXINT0(PB_A6_CMU_6, 0x7B);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 900) && (GET_INPUT_PIXEL_CLK() < 1200))
    {
        // [2:0] sel_rate[2:0] = 3'b001 --> VCO Divider = 2
        ScalerSetBit_EXINT0(PB_A1_CMU_1, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);

        // [7:4] pre_div[3:0] = 4'b0010 --> M = 4
        // [3] bypass_ckref = 0 --> CMU's pre-divider = M
        ScalerSetBit_EXINT0(PB_A3_CMU_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT5);
       
        // [2] sel_lowkvco = 0 --> High KVCO for 1.8G~2.4G
        // [1] sel_cp = 1 --> CMU's Loop Filter's Parallel Capacitor = 2pF
        ScalerSetBit_EXINT0(PB_A5_CMU_5, ~(_BIT2 | _BIT1), _BIT1);

        // [7:3] sel_icp[4:0] = 5'b01011 --> Icp = 15uA
        // [2:0] sel_rs[2:0] = 3'b011 --> Rs = 10K
        ScalerSetByte_EXINT0(PB_A6_CMU_6, 0x5B);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 1200) && (GET_INPUT_PIXEL_CLK() < 1800))
    {
        // [2:0] sel_rate[2:0] = 3'b000 --> VCO Divider = 1
        ScalerSetBit_EXINT0(PB_A1_CMU_1, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        // [7:4] pre_div[3:0] = 4'b0110 --> M = 8
        // [3] bypass_ckref = 0 --> CMU's pre-divider = M
        ScalerSetBit_EXINT0(PB_A3_CMU_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5));
        
        // [2] sel_lowkvco = 1 --> Low KVCO for 1.2G~1.8G
        // [1] sel_cp = 1 --> CMU's Loop Filter's Parallel Capacitor = 2pF
        ScalerSetBit_EXINT0(PB_A5_CMU_5, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

        // [7:3] sel_icp[4:0] = 5'b01111 --> Icp = 20uA
        // [2:0] sel_rs[2:0] = 3'b011 --> Rs = 10K
        ScalerSetByte_EXINT0(PB_A6_CMU_6, 0x7B);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 1800) && (GET_INPUT_PIXEL_CLK() < 2400))
    {
        // [2:0] sel_rate[2:0] = 3'b000 --> VCO Divider = 1
        ScalerSetBit_EXINT0(PB_A1_CMU_1, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        // [7:4] pre_div[3:0] = 4'b0110 --> M = 8
        // [3] bypass_ckref = 0 --> CMU's pre-divider = M
        ScalerSetBit_EXINT0(PB_A3_CMU_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5));
        
        // [2] sel_lowkvco = 0 --> High KVCO for 1.8G~2.4G
        // [1] sel_cp = 1 --> CMU's Loop Filter's Parallel Capacitor = 2pF
        ScalerSetBit_EXINT0(PB_A5_CMU_5, ~(_BIT2 | _BIT1), _BIT1);

        // [7:3] sel_icp[4:0] = 5'b01011 --> Icp = 15uA
        // [2:0] sel_rs[2:0] = 3'b011 --> Rs = 10K
        ScalerSetByte_EXINT0(PB_A6_CMU_6, 0x5B);
    }

    // [7] bypass_pi = 1 --> Bypass PI(Integer N PLL)
    // [6] sel_2xi = 0 --> Normal Bias Current for CMU's Phase Interpolator
    // [5] sel_ipi = 1 --> CMU's PI phase Uniformity Control
    ScalerSetBit_EXINT0(PB_A7_CMU_7, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT5));

    // [5] sel_2xi_data = 0 --> Normal Bias Current for CMU's Phase Rotator
    // [4] sel_ipi_data = 0 --> CMU's PR phase Uniformity Control
    ScalerSetBit_EXINT0(PB_A8_CDR_0, ~(_BIT5 | _BIT4), 0x00);

    // [7] BYPASS_PI_SDM = 1 --> Use the N_CODE as Output
    // [4] N_CODE[8] = 0
    ScalerSetBit_EXINT0(PB_EB_SDM_0, ~(_BIT7 | _BIT4), _BIT7);

    // [7:0] N_CODE[7:0] = 7'b00100110 --> CMU's Loop Divider Ratio N = 80
    ScalerSetByte_EXINT0(PB_EC_SDM_1, 0x26);

    // [0] PLL_WD_EN = 0 --> Disable WatchDog
    ScalerSetBit_EXINT0(PB_EE_WD_1, ~_BIT0, 0x00);


    /////////////////
    // DFE Setting //
    /////////////////  

    // Set DFE Initial Code
    ScalerTmdsSetDFEInitial_EXINT0();

    // [7] de_brank_en = 0 --> Disable DE Brank
    // [6] de_inverse = 0 --> Brank when DE is 1
    ScalerSetBit_EXINT0(P1D_A7_INIT_5, ~(_BIT7 | _BIT6), 0x00);
    
    // [4] dfe_clk_en = 1 --> Enable DFE CLK
    // [1] tshare_auto = 0 --> Disable Time-sharing Automation
    // [0] tshare_mode = 1 --> Enable DFE Time-sharing Mode
    ScalerSetBit_EXINT0(P1D_B0_DFE_TIME_SHARING_EN, ~(_BIT4 | _BIT1 | _BIT0), (_BIT4 | _BIT0)); 

    // [5:3] le_hi_boost_en[2:0] = 3'b100 --> Enable LEQ Stage 1 High-boost mode
    ScalerSetBit_EXINT0(PB_B1_EQ_1, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);

    if(GET_INPUT_PIXEL_CLK() > 1200)
    {   
        // [0] en_leq_lowpeak = 0 --> LEQ peaking = 1.1G
        ScalerSetBit_EXINT0(PB_AA_CDR_2, ~_BIT0, 0x00);
    }
    else
    {   
        // [0] en_leq_lowpeak = 1 --> LEQ peaking = 600M
        ScalerSetBit_EXINT0(PB_AA_CDR_2, ~_BIT0, _BIT0);
    }

    if(GET_INPUT_PIXEL_CLK() >= 2200)
    {
        // [1] CMP_HSMODE = 1 --> Only for 2.25GHz
        ScalerSetBit_EXINT0(PB_A9_CDR_1, ~_BIT1, _BIT1);

        // [1] VREF_SRC_L = 0 --> LDO_D = LDO_A * 0.95
        ScalerSetBit_EXINT0(P0_E0_EBD_REGLATOR_DB_CTRL, ~_BIT1, 0x00);

        // [2:0] LDO_A voltage = 1.27V
        ScalerSetBit_EXINT0(P0_DF_EBD_REGLATOR_A_CTRL, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
    }
    else
    {
        // [1] CMP_HSMODE = 0 --> For Other than 2.25GHz
        ScalerSetBit_EXINT0(PB_A9_CDR_1, ~_BIT1, 0x00);

        // [1] VREF_SRC_L = 1 --> LDO_D = LDO_A
        ScalerSetBit_EXINT0(P0_E0_EBD_REGLATOR_DB_CTRL, ~_BIT1, _BIT1);

        // [2:0] LDO_A voltage = 1.22V
        ScalerSetBit_EXINT0(P0_DF_EBD_REGLATOR_A_CTRL, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
    }


    /////////////////
    // CDR Setting //
    /////////////////

    // [0] CDR_PWRON = 1 --> CDR and Rx Sync Clock On
    ScalerSetBit_EXINT0(PB_C3_TMDS_CONT_3, ~_BIT0, _BIT0);

    // CDR_L0
    // [7] CDR_KD = 0 --> Differential Gain of CDR Filter KD = 0
    // [6:4] CDR_KP1[2:0] = 3'b001 --> Proportional Gain of Digital LPF KP1 = 1
    // [3] CDR_BPSDM = 1 --> Bypass SDM of Integral Path
    // [2:0] CDR_KP2[2:0] = 3'b000 --> Proportional Gain of Digital LPF KP2 = 0     
    ScalerSetByte_EXINT0(PB_C4_L0_CDR_0, 0x18);

    // [7:5] CDR_KI[2:0] = 3'b000 --> Integration Gain of Digital LPF KI = 0
    // [4] CDRCNT_INI = 0 --> CDR Data Counter Initial Value = 0
    // [2:0] DFECNT_INI[2:0] = 3'b101 --> CDR Data Counter Initial Value = 5
    ScalerSetBit_EXINT0(PB_C5_L0_CDR_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

    // CDR_L1
    ScalerSetByte_EXINT0(PB_CA_L1_CDR_0, 0x18);
    ScalerSetBit_EXINT0(PB_CB_L1_CDR_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
       
    // CDR_L2
    ScalerSetByte_EXINT0(PB_D3_L2_CDR_0, 0x18);
    ScalerSetBit_EXINT0(PB_D4_L2_CDR_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
   
    // [1] bypass_clk_rdy = 1 --> Manual Mode
    // [0] en_clkout_manual = 0 --> Disable Clkout 
    ScalerSetBit_EXINT0(PB_F8_CLK_TIMER, ~(_BIT1 | _BIT0), _BIT1); 

    // [1] bypass_eqen_rdy = 1 --> Manual Mode
    // [0] en_eqen_manual = 0 --> Disable Clkout
    ScalerSetBit_EXINT0(PB_F9_EQEN_TIMER, ~(_BIT1 | _BIT0), _BIT1); 

    // [1] bypass_data_rdy = 1 --> Manual Mode
    // [0] en_data_manual = 0 --> Disable Dataout
    ScalerSetBit_EXINT0(PB_FA_DATA_TIMER, ~(_BIT1 | _BIT0), _BIT1); 


    //////////////
    // K Offset //
    ////////////// 
    
    // [5] Foreground Calibration Auto Mode
    ScalerSetBit_EXINT0(PB_B2_EQ_2, ~(_BIT6 | _BIT5), _BIT5);

    // [6] Enable offset Calibration
    ScalerSetBit_EXINT0(PB_B2_EQ_2, ~_BIT6, _BIT6);
    
    // Waiting for K Offset 
    for(ucTemp = 0; ucTemp <= 10; ucTemp++)
    {
        _nop_();
    }  

    
    ////////////////
    // Close Loop //
    //////////////// 
    
    // [7] cmu_en[3] = 1 --> Enable Power Control for VCO of Lane3(Clock Lane), Start CDR Close Loop
    ScalerSetBit_EXINT0(PB_B4_POWER_0, ~_BIT7, _BIT7);
    
    // Clock Ready
    ScalerSetBit_EXINT0(PB_F8_CLK_TIMER, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
    
    // EQ Ready 
    ScalerSetBit_EXINT0(PB_F9_EQEN_TIMER, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));     

    ScalerTmdsDFEAdaptation_EXINT0(_DFE_LANE2);
    ScalerTmdsDFEAdaptation_EXINT0(_DFE_LANE1);
    ScalerTmdsDFEAdaptation_EXINT0(_DFE_LANE0);
   
    // Data Ready 
    ScalerSetBit_EXINT0(PB_FA_DATA_TIMER, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

    // Reset PHY -> MAC Interface
    ScalerSetBit_EXINT0(P2_A7_POWER_ON_OFF_CTRL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit_EXINT0(P2_A7_POWER_ON_OFF_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0)); 
}

//--------------------------------------------------
// Description  : TMDS Interrupt Process (EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsIntHandler_EXINT0(void) using 1
{
    BYTE ucBackUp[2];
    WORD usCount = 0;    

    ucBackUp[0] = ScalerGetByte_EXINT0(P2_C9_HDMI_ADDR_PORT);
    ucBackUp[1] = ScalerGetByte_EXINT0(P2_C8_HDMI_APC);

    // Freq. Stable Into IRQ
    if((ScalerGetByte_EXINT0(P2_EF_HDMI_FREQDET_RESERVED) & 0xC0) == 0xC0)
    {
        // Disable Freq Stable IRQ
        ScalerSetBit_EXINT0(P2_EF_HDMI_FREQDET_RESERVED, ~(_BIT7 | _BIT6), _BIT6);

        // Enable Freq unstable IRQ
        ScalerSetBit_EXINT0(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

        // Pop up Counter Value
        ScalerSetBit_EXINT0(P2_EC_HDMI_FREQDET_STABLE, ~_BIT7, _BIT7);

        usCount = (WORD)(((ScalerGetByte_EXINT0(P2_ED_HDMI_FREQDET_RESULT_M) & 0x7F) << 8) | ScalerGetByte_EXINT0(P2_EE_HDMI_FREQDET_RESULT_L));

        // TMDS_FREQ(MHz) = GDI_CLK(MHz) * CLK_COUNT / 1000
        SET_INPUT_PIXEL_CLK((((DWORD)_GDI_CLK_KHZ * usCount + 50000) / 100000));
        
        if((GET_TMDS_PHY_SET() == _FALSE) || ((bit)ScalerTmdsCheckCDRStable_EXINT0(g_usTmdsClkCount) == _FALSE))
        {
            g_usTmdsClkCount = ScalerTmdsMeasureClk_EXINT0(_CLK_SOURCE_TMDS);
                        
            ScalerTmdsSetPhy_EXINT0();
        }

        // Set Upper bound (allow 1/64 freq shift)
        ScalerSetByte_EXINT0(P2_E8_HDMI_FREQDET_UPPER_M, (HIBYTE(usCount + (usCount >> 6)) & 0x7F));
        ScalerSetByte_EXINT0(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(usCount + (usCount >> 6)));

        // Set Lower bound
        ScalerSetByte_EXINT0(P2_EA_HDMI_FREQDET_LOWER_M, (HIBYTE(usCount - (usCount >> 6)) & 0x7F));
        ScalerSetByte_EXINT0(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(usCount - (usCount >> 6)));
        
        SET_TMDS_PHY_SET();        
    }

    // Freq. Unstable Into IRQ
    if((ScalerGetByte_EXINT0(P2_E6_HDMI_FREQDET_CTRL) & 0x06) == 0x06)
    {
        // Clear Unstable IRQ Flag        
        ScalerSetBit_EXINT0(P2_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);

        // Ensure Freq really unstable
        if(abs(g_usTmdsClkCount - ScalerTmdsMeasureClk_EXINT0(_CLK_SOURCE_TMDS)) > (g_usTmdsClkCount >> 6))
        {
            // Disable RGB/clock Output to avoid garbage
            ScalerSetBit_EXINT0(P2_A6_TMDS_OUTPUT_CTRL, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);
            
            // Disable Freq. Unstable IRQ
            ScalerSetBit_EXINT0(P2_E6_HDMI_FREQDET_CTRL, ~_BIT1, 0x00);

            // Enable Freq. Stable IRQ
            ScalerSetBit_EXINT0(P2_EF_HDMI_FREQDET_RESERVED, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            // Set Upper bound
            ScalerSetByte_EXINT0(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_NORMAL_UPPER_BOUND));
            ScalerSetByte_EXINT0(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_NORMAL_UPPER_BOUND));

            // Set Lower bound
            ScalerSetByte_EXINT0(P2_EA_HDMI_FREQDET_LOWER_M, HIBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));
            ScalerSetByte_EXINT0(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));           

            CLR_TMDS_PHY_SET();
        }
    }

    // Disable Auto Inc
    ScalerSetBit_EXINT0(P2_C8_HDMI_APC, ~_BIT0, 0x00);
    
    // Clear IRQ Pending Flag
    ScalerSetByte_EXINT0(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_60_HDMI_INTCR);
    ScalerSetBit_EXINT0(P2_CA_HDMI_DATA_PORT, ~_BIT7, _BIT7);

    ScalerSetByte_EXINT0(P2_C8_HDMI_APC, ucBackUp[1]);        
    ScalerSetByte_EXINT0(P2_C9_HDMI_ADDR_PORT, ucBackUp[0]);
}

//--------------------------------------------------
// Description  : Check CDR Locked
// Input Value  : Measured Clk Count to be compared
// Output Value : _TRUE => Stable
//--------------------------------------------------
bit ScalerTmdsCheckCDRStable(WORD usClkCount)
{
    if(GET_INPUT_PIXEL_CLK() > 800) // High Freq.
    {
        ScalerTmdsDFEAdaptation(_DFE_LANE2);
        ScalerTmdsDFEAdaptation(_DFE_LANE1);
        ScalerTmdsDFEAdaptation(_DFE_LANE0);
    }
    
    // Check Current Measured Freq. is the same as previously locked
    if(abs(usClkCount - ScalerTmdsMeasureClk(_CLK_SOURCE_RED)) > (usClkCount >> 5))
    {
        DebugMessageDigital("R Channel CDR Unstable", ScalerTmdsMeasureClk(_CLK_SOURCE_RED));
        return _FALSE;
    }

    if(abs(usClkCount - ScalerTmdsMeasureClk(_CLK_SOURCE_BLUE)) > (usClkCount >> 5))
    {
        DebugMessageDigital("B Channel CDR Unstable", ScalerTmdsMeasureClk(_CLK_SOURCE_BLUE));
        return _FALSE;
    }

    if(abs(usClkCount - ScalerTmdsMeasureClk(_CLK_SOURCE_GREEN)) > (usClkCount >> 5))
    {
        DebugMessageDigital("G Channel CDR Unstable", ScalerTmdsMeasureClk(_CLK_SOURCE_GREEN));
        return _FALSE;
    }
    return _TRUE;
}

//--------------------------------------------------
// Description  : Check CDR Locked (EXINT0 Only)
// Input Value  : Measured Clk Count to be compared
// Output Value : _TRUE => Stable
//--------------------------------------------------
BYTE ScalerTmdsCheckCDRStable_EXINT0(WORD usClkCount) using 1
{
    // Check Current Measured Freq. is the same as previously locked
    if(abs(usClkCount - ScalerTmdsMeasureClk_EXINT0(_CLK_SOURCE_TMDS)) > (usClkCount >> 6))
    {
        return _FALSE;
    }

    if(abs(usClkCount - ScalerTmdsMeasureClk_EXINT0(_CLK_SOURCE_RED)) > (usClkCount >> 6))
    {
        return _FALSE;
    }

    if(abs(usClkCount - ScalerTmdsMeasureClk_EXINT0(_CLK_SOURCE_BLUE)) > (usClkCount >> 6))
    {
        return _FALSE;
    }

    if(abs(usClkCount - ScalerTmdsMeasureClk_EXINT0(_CLK_SOURCE_GREEN)) > (usClkCount >> 6))
    {
        return _FALSE;
    }
    return _TRUE;
}

//--------------------------------------------------
// Description  : Measure Clk
// Input Value  : Clk Source to be measured
// Output Value : Measured Clk Count
//--------------------------------------------------
WORD ScalerTmdsMeasureClk(BYTE ucMeasureClk)
{
    BYTE ucDelayCount = 0;

    // Enable Rx_EN, CMU_EN
    ScalerSetByte(PB_B4_POWER_0, 0xFF);

    // Select reference clk to Xtal Clk and measure clk
    ScalerSetBit(P2_AD_CPS, ~(_BIT6 | _BIT5 | _BIT4), ((ucMeasureClk << 5) | _BIT4));

    // Disable Auto Inc
    ScalerSetBit(P2_C8_HDMI_APC, ~_BIT0, 0x00);

    // Start Measure
    ScalerSetByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_28_HDMI_NTX1024TR0);
    ScalerSetBit(P2_CA_HDMI_DATA_PORT, ~_BIT3, _BIT3);

    // Delay at least 40us at Xtal = 27MHz
    for(ucDelayCount = 0; ucDelayCount <= 20; ucDelayCount++)
    {
        _nop_();

        if((ScalerGetBit(P2_CA_HDMI_DATA_PORT, _BIT3)) == 0x00)
        {
            break;
        }
    }

    // Enable Auto Inc
    ScalerSetBit(P2_C8_HDMI_APC, ~_BIT0, _BIT0);
    
    ScalerSetByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_28_HDMI_NTX1024TR0);
    
    return ((WORD)(ScalerGetByte(P2_CA_HDMI_DATA_PORT) & 0x07) << 8) | ScalerGetByte(P2_CA_HDMI_DATA_PORT);

}

//--------------------------------------------------
// Description  : Measure Clk (EXINT0 Only)
// Input Value  : Clk Source to be measured
// Output Value : Measured Clk Count
//--------------------------------------------------
WORD ScalerTmdsMeasureClk_EXINT0(BYTE ucMeasureClk) using 1
{
    BYTE ucDelayCount = 0;
    WORD usClkCount = 0;
    BYTE ucBackUp = 0;
    
    // Enable Rx_EN, CMU_EN
    ScalerSetByte_EXINT0(PB_B4_POWER_0, 0xFF);

    // Select reference clk to Xtal Clk and measure clk
    ScalerSetBit_EXINT0(P2_AD_CPS, ~(_BIT6 | _BIT5 | _BIT4), ((ucMeasureClk << 5) | _BIT4));

    ucBackUp = ScalerGetByte_EXINT0(P2_C8_HDMI_APC);
    
    // Disable Auto Inc
    ScalerSetBit_EXINT0(P2_C8_HDMI_APC, ~_BIT0, 0x00);

    // Start Measure
    ScalerSetByte_EXINT0(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_28_HDMI_NTX1024TR0);
    ScalerSetBit_EXINT0(P2_CA_HDMI_DATA_PORT, ~_BIT3, _BIT3);

    // Delay at least 40us at Xtal = 27MHz
    for(ucDelayCount = 0; ucDelayCount <= 20; ucDelayCount++)
    {
        _nop_();

        if((ScalerGetBit_EXINT0(P2_CA_HDMI_DATA_PORT, _BIT3)) == 0x00)
        {
            break;
        }
    }

    // Enable Auto Inc
    ScalerSetBit_EXINT0(P2_C8_HDMI_APC, ~_BIT0, _BIT0);
    
    ScalerSetByte_EXINT0(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_28_HDMI_NTX1024TR0);
    usClkCount = ((WORD)(ScalerGetByte_EXINT0(P2_CA_HDMI_DATA_PORT) & 0x07) << 8) | ScalerGetByte_EXINT0(P2_CA_HDMI_DATA_PORT);

    ScalerSetByte_EXINT0(P2_C8_HDMI_APC, ucBackUp);
    
    return usClkCount;

}

//--------------------------------------------------
// Description  : Detect TMDS Format
// Input Value  : None
// Output Value : Return DVI or HDMI format
//--------------------------------------------------
BYTE ScalerTmdsFormatDetect(void)
{
    // Polling at least 3 frame for HW auto detect TMDS format
    if(ScalerTimerPollingFlagProc(130, P2_CB_HDMI_SR, _BIT0, _TRUE) == _TRUE)
    {
        ScalerSetBit(P2_AF_TMDS_WDC, ~_BIT0, 0x00);            
        return _SOURCE_HDMI;
    }
    else
    {
        ScalerSetBit(P2_AF_TMDS_WDC, ~_BIT0, _BIT0);            
        return _SOURCE_DVI;
    }
}

//--------------------------------------------------
// Description  : TMDS Video Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsDviVideoSetting(void)
{
    // Manual Set Color Space and disable pixel repetition
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_51_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 |_BIT2), 0x00);

    // Disable Down Sampling
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_50_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 |_BIT0), 0x00);    

    // Waiting for Down Sampling Effect
    ScalerTimerDelayXms(20); 
    
    SET_COLOR_SPACE(_COLOR_SPACE_RGB);        
    
    ScalerTmdsSetPorchColor(GET_COLOR_SPACE());
}    

//--------------------------------------------------
// Description  : Set Back Ground Color
// Input Value  : Current Color Space
// Output Value : None
//--------------------------------------------------
void ScalerTmdsSetPorchColor(BYTE ucColorSpace)
{
    // Manual Set Background Color Enable
    ScalerSetBit(P2_B9_TMDS_OUT_CTRL, ~_BIT7, 0x00);

    if((ucColorSpace == _COLOR_SPACE_YCBCR444) || (ucColorSpace == _COLOR_SPACE_YCBCR422))
    {
        ScalerSetByte(P2_BA_TMDS_ROUT_HIGH_BYTE, 0x80);
        ScalerSetByte(P2_BB_TMDS_ROUT_LOW_BYTE, 0x00);
        ScalerSetByte(P2_BC_TMDS_GOUT_HIGH_BYTE, 0x0F);
        ScalerSetByte(P2_BD_TMDS_GOUT_LOW_BYTE, 0x00);
        ScalerSetByte(P2_BE_TMDS_BOUT_HIGH_BYTE, 0x80);
        ScalerSetByte(P2_BF_TMDS_BOUT_LOW_BYTE, 0x00);        
    }
    else
    {
        ScalerSetByte(P2_BA_TMDS_ROUT_HIGH_BYTE, 0x00);
        ScalerSetByte(P2_BB_TMDS_ROUT_LOW_BYTE, 0x00);
        ScalerSetByte(P2_BC_TMDS_GOUT_HIGH_BYTE, 0x00);
        ScalerSetByte(P2_BD_TMDS_GOUT_LOW_BYTE, 0x00);
        ScalerSetByte(P2_BE_TMDS_BOUT_HIGH_BYTE, 0x00);
        ScalerSetByte(P2_BF_TMDS_BOUT_LOW_BYTE, 0x00);
    }
}

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Video Setting
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiVideoSetting(void)
{
    if(GET_HDMI_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {    
        // Color Space Auto/ Pixel Repetition auto mode
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_51_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));

        ScalerGetDataPortByte(P2_CD_HDMI_PSAP, 0x04, 3, pData, _AUTOINC);

        // Get Color Space
        if((pData[0] & (_BIT6 | _BIT5)) != 0x00)
        {
            // YCbCr 422
            if((pData[0] & _BIT5) == _BIT5)
            {
                DebugMessageDigital("Get Color Space YUV422", pData[0]);
                SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
            }
            else
            {
                DebugMessageDigital("Get Color Space YUV444", pData[0]);
                SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
            }

            if((pData[1] & 0xC0) == 0x00)
            {
                DebugMessageDigital("No Colorimetry Specified", pData[1]);
                SET_COLORIMETRY(_COLORIMETRY_NONE);
            }
            else if((pData[1] & 0xC0) == 0xC0)    // Extended Colorimetry
            {
                DebugMessageDigital("Get Colorimetry Extended", pData[0]);
                SET_COLORIMETRY(_COLORIMETRY_EXT);

                // Get extended colorimetry
                if((pData[2] & 0x70) == 0x10)    // xvYCC709
                {
                    SET_EXT_COLORIMETRY(_COLORIMETRY_XVYCC709);
                }
                else if((pData[2] & 0x70) == 0x00)    // xvYCC601
                {
                    SET_EXT_COLORIMETRY(_COLORIMETRY_XVYCC601);
                }
            }
            else
            {
                // Get Normal Colorimetry
                if((pData[1] & _BIT6) == _BIT6)
                {
                    DebugMessageDigital("Get Colorimetry 601", pData[1]);
                    SET_COLORIMETRY(_COLORIMETRY_ITU601);
                }
                else
                {
                    DebugMessageDigital("Get Colorimetry 709", pData[1]);
                    SET_COLORIMETRY(_COLORIMETRY_ITU709);
                }
            }

        }
        else    // Color Space RGB
        {
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
        }            
    }    
    else    // No Info Frame Received
    {
        // Mannal Set Color Space and disable pixel repetition
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_51_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT2), 0x00);

        // Disable down sampling
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_50_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 |_BIT0), 0x00);  

        // Waiting for down sampling  effect
        ScalerTimerDelayXms(20);
        
        SET_COLOR_SPACE(_COLOR_SPACE_RGB);
    }

    ScalerTmdsSetPorchColor(GET_COLOR_SPACE());
}

//--------------------------------------------------
// Description  : Detect HDMI Info Frame
// Input Value  : bWait => Whether to wait then read
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiPacketDetect(bit bWait)
{
   if(bWait == _WAIT)
    {
        // Polling 3 frame for detect Packet signals
        if(ScalerTimerPollingFlagProc(130, P2_CC_HDMI_GPVS, (_BIT6 | _BIT5), _TRUE) == _TRUE)
        {
            // Both GCP & AVI infoframe packet have been received
            if(ScalerGetBit(P2_CC_HDMI_GPVS, (_BIT6 | _BIT5)) == (_BIT6 | _BIT5))
            {
                SET_HDMI_GCP_RECEIVED();

                SET_HDMI_AVI_INFO_FRAME_RECEIVED();
            }
            // Only AVI infoframe packet have been received
            else if(ScalerGetBit(P2_CC_HDMI_GPVS, (_BIT6 | _BIT5)) == _BIT5)
            {
                SET_HDMI_AVI_INFO_FRAME_RECEIVED();

                // Polling more 1 frame to wait GCP packet for HW can't update bit 6 & bit 5 simultaneously
                if(ScalerTimerPollingFlagProc(45, P2_CC_HDMI_GPVS, _BIT6, _TRUE) == _TRUE)
                {
                    SET_HDMI_GCP_RECEIVED();
                }
                else
                {
                    CLR_HDMI_GCP_RECEIVED();
                }
            }
            // Only GCP Packet have been received
            else if(ScalerGetBit(P2_CC_HDMI_GPVS, (_BIT6 | _BIT5)) == _BIT6)
            {
                SET_HDMI_GCP_RECEIVED();

                // Polling more 1 frame to wait AVI infoframe packet for HW can't update bit 6 & bit 5 simultaneously
                if(ScalerTimerPollingFlagProc(45, P2_CC_HDMI_GPVS, _BIT5, _TRUE) == _TRUE)
                {
                    SET_HDMI_AVI_INFO_FRAME_RECEIVED();
                }
                else
                {
                    CLR_HDMI_AVI_INFO_FRAME_RECEIVED();
                }                
            }
         }
        // Neither AVI infoframe nor GCP packet received 
        else
        {
            CLR_HDMI_GCP_RECEIVED();

            CLR_HDMI_AVI_INFO_FRAME_RECEIVED();
        }

#if(_HDMI_FREESYNC_SUPPORT == _ON)
#if(_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE)
        // Polling 3 frame for detect Packet signals P2_CA_00[7]
        if((GET_HDMI_FREESYNC_VCP() == 0x01) && (ScalerTimerPollingDataBitFlagProc(130, P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, _BIT7, _TRUE) == _TRUE))
#else
        // Polling 3 frame for detect Packet signals P2_CA_00[7]
        if(ScalerTimerPollingDataBitFlagProc(130, P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, _BIT7, _TRUE) == _TRUE)
#endif
        {
            SET_TMDS_RX0_SPD_INFO_FRAME_RECEIVED();
        }
        else
        {
            CLR_TMDS_RX0_SPD_INFO_FRAME_RECEIVED();
        }
#endif

        // Wait at least 3 frame for HW auto update color depth value
        ScalerTimerDelayXms(130);
        
        CLR_HDMI_PACKET_DETECTING();
    }
    else
    {            
        if(ScalerGetBit(P2_CC_HDMI_GPVS, _BIT6) == _BIT6)
        {
            ScalerTmdsHdmiWatchDog(_HDMI_AV_MUTE_WD, _ENABLE);
            
            SET_HDMI_GCP_RECEIVED();       
        }
        else
        {
            ScalerTmdsHdmiWatchDog(_HDMI_AV_MUTE_WD, _DISABLE);
        
            CLR_HDMI_GCP_RECEIVED();           
        }
        
        if(ScalerGetBit(P2_CC_HDMI_GPVS, _BIT5) == _BIT5)
        {
            // Color Space Auto/ Pixel Repetition auto mode
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_51_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));  
            
            ScalerTmdsHdmiWatchDog(_HDMI_AVI_INFO_VARIATION_WD, _ENABLE);

            SET_HDMI_AVI_INFO_FRAME_RECEIVED();                
        }
        else
        {
            // Mannal Set Color Space and disable pixel  repetition
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_51_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT2), 0x00);
    
            // Disable down sampling
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_50_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 |_BIT0), 0x00);

            // Waiting for down sampling effect
            ScalerTimerDelayXms(20);
            
            ScalerTmdsHdmiWatchDog(_HDMI_AVI_INFO_VARIATION_WD, _DISABLE);  

            CLR_HDMI_AVI_INFO_FRAME_RECEIVED();                 
        }

#if(_HDMI_FREESYNC_SUPPORT == _ON)
#if(_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE)
        if((GET_HDMI_FREESYNC_VCP() == 0x01) && (ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, _BIT7) == _BIT7))
#else
        if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, _BIT7) == _BIT7)
#endif
        {
            SET_TMDS_RX0_SPD_INFO_FRAME_RECEIVED();
        }
        else
        {
            CLR_TMDS_RX0_SPD_INFO_FRAME_RECEIVED();
        }
#endif

        // Clear Detection Flag
        ScalerSetBit(P2_CC_HDMI_GPVS, ~_BIT6, _BIT6);

        ScalerSetBit(P2_CC_HDMI_GPVS, ~_BIT5, _BIT5);

        SET_HDMI_PACKET_DETECTING();

        // Activate Packet Detection Event
        ScalerTimerActiveTimerEvent(SEC(0.13), _SCALER_TIMER_EVENT_TMDS_HDMI_PACKET_DETECT);
    }
}

//--------------------------------------------------
// Description  : HDMI Info Frame Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiPacketDetectEvent(void)
{
    CLR_HDMI_PACKET_DETECTING();
}

//--------------------------------------------------
// Description  : Detect HDMI Colo Info 
// Input Value  : None
// Output Value : _TRUE => Current Color Info is different from previous setting
//--------------------------------------------------    
bit ScalerTmdsHdmiColorInfoChanged(void)
{     
    ScalerGetDataPortByte(P2_CD_HDMI_PSAP, 0x04, 3, pData, _AUTOINC);
        
    // Check Color Space
    if((pData[0] & (_BIT6 | _BIT5)) >> 5 != GET_COLOR_SPACE())
    {
        DebugMessageDigital("Color Space Changed", pData[0]);
        return _TRUE;
    }

    if(GET_COLOR_SPACE() != _COLOR_SPACE_RGB)
    {
        // Check Colorimetry
        if((pData[1] & (_BIT7 | _BIT6)) >> 6 != GET_COLORIMETRY())
        {
            DebugMessageDigital("Colorimetry Changed", pData[1]);
            return _TRUE;
        }
        else
        {
            if(GET_COLORIMETRY() == _COLORIMETRY_EXT)
            {
                if(((pData[2] & 0x70) >> 4) != GET_EXT_COLORIMETRY())
                {
                    DebugMessageDigital("Ext Colorimetry Changed", pData[2]);
                    return _TRUE;
                }
            }
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Color Depth
// Input Value  : None
// Output Value : Received Color Depth
//--------------------------------------------------
BYTE ScalerTmdsHdmiGetColorDepth(void)
{
    if(GET_HDMI_GCP_RECEIVED() == _TRUE)
    {  
        if(ScalerGetBit(P2_B4_TMDS_DPC0, 0x07) == 0x05)
        {
            return _COLOR_DEPTH_10_BITS;
        }
        else if(ScalerGetBit(P2_B4_TMDS_DPC0, 0x07) == 0x06)
        {
            return _COLOR_DEPTH_12_BITS;
        }
        else if(ScalerGetBit(P2_B4_TMDS_DPC0, 0x07) == 0x07)
        {
            return _COLOR_DEPTH_16_BITS;
        }
    }

    return _COLOR_DEPTH_8_BITS;
}

//--------------------------------------------------
// Description  : Deep Color Mode Process
// Input Value  : None
// Output Value : _TRUE ==> Deep Color Mode process success
//--------------------------------------------------
bit ScalerTmdsHdmiDeepColorProc(void)
{   
    return _FALSE;
}

//--------------------------------------------------
// Description  : Hdmi Handle AVMute Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiAVMuteProc(void)
{
    // if AVMute Has been triggered
    if((ScalerGetBit(P2_CB_HDMI_SR, _BIT6) == 0x00) && (ScalerGetBit(P2_A6_TMDS_OUTPUT_CTRL, (_BIT6 | _BIT5 | _BIT4)) == 0x00))
    {
        // Clear AVMute Flag
        ScalerSetBit(P2_CB_HDMI_SR, ~_BIT7, _BIT7);
        
        // Disable AVMute Watch Dog
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~_BIT7, 0x00);

        // Enable Video Output
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~ _BIT3, _BIT3);

        // Enable RGB Output
        ScalerSetBit(P2_A6_TMDS_OUTPUT_CTRL, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

        // Enable AVMute Watch Dog
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~_BIT7, _BIT7);        
    }
}

//--------------------------------------------------
// Description  : Hdmi Enable Watch Dog
// Input Value  : unWDType ==> Watch Dog Type, bEnable ==> Enable flag
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiWatchDog(BYTE ucWDType, bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        if((ucWDType & _HDMI_AVI_INFO_VARIATION_WD) == _HDMI_AVI_INFO_VARIATION_WD)
        {
            if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_41_HDMI_VWDSR, _BIT0) == 0x00)
            {
                // Clear AVI Info Frame Variation flag
                ScalerSetBit(P2_CC_HDMI_GPVS, ~(_BIT6 | _BIT5 | _BIT0), _BIT0);
                
                if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422))
                {
                    // Enable Color Space/ Colorimetry Change Detection
                    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_45_HDMI_PVGCR0, ~(_BIT3 | _BIT0), (_BIT3 | _BIT0));
                }
                else
                {
                    // Enable Color Space Change Detection
                    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_45_HDMI_PVGCR0, ~(_BIT3 | _BIT0), _BIT0);
                }

                // Enable AVI Info Frame Variation Watch Dog
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_41_HDMI_VWDSR, ~_BIT0, _BIT0);    
            }           
        }

        if((ucWDType & _HDMI_AV_MUTE_WD) == _HDMI_AV_MUTE_WD)
        {
            if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, _BIT7) == 0x00)
            {
                // CLR AVMute Flag
                ScalerSetBit(P2_CB_HDMI_SR, ~_BIT7, _BIT7);
                
                // Enable AVMute WD
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~_BIT7, _BIT7);
            }         
        }
    }
    else
    {
        if((ucWDType & _HDMI_AVI_INFO_VARIATION_WD) == _HDMI_AVI_INFO_VARIATION_WD)
        {
            // Disable packet variation Watch Dog
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_41_HDMI_VWDSR, ~_BIT0, 0x00);

            ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_45_HDMI_PVGCR0, 0x00);

            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_46_HDMI_PVGCR1, ~_BIT0, 0x00);
        }

        if((ucWDType & _HDMI_AV_MUTE_WD) == _HDMI_AV_MUTE_WD)
        {
            // Disable AV Mute Watch Dog
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~_BIT7, 0x00);
        } 
    }
}

#endif // End of #if(_HDMI_SUPPORT == _ON)

//--------------------------------------------------
// Description  : TMDS Power Saving Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsPowerSavingProc(void)
{            
    // Switch TMDS Input/Output to Auto
    ScalerSetBit(P2_A6_TMDS_OUTPUT_CTRL, ~_BIT7, _BIT7);
    ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~_BIT4, _BIT4);

    ScalerTmdsFreqDetectDisable();

    // Set Freq. Stable Time: 10 times
    ScalerSetByte(P2_EC_HDMI_FREQDET_STABLE, 0x0A);

    // Set Freq. Shift Offset to Max
    ScalerSetByte(P2_E7_HDMI_FREQDET_OFFSET, 0x7F);

    // Set Counter Upper Bound
    ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_PS_UPPER_BOUND));
    ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_PS_UPPER_BOUND));

    // Set Counter Lower Bound
    ScalerSetByte(P2_EA_HDMI_FREQDET_LOWER_M, HIBYTE(_TMDS_FREQ_PS_LOWER_BOUND));
    ScalerSetByte(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(_TMDS_FREQ_PS_LOWER_BOUND));

#if(_LOW_POWER_GDI_ISOLATION == _ON)
    // HDCP Key Not Ready
    ScalerSetBit(P2_AE_TMDS_RPS, ~_BIT1, 0x00);
#endif
}

//--------------------------------------------------
// Description  : TMDS Power Off Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsPowerOffProc(void)
{
    // Disable EDID read/ SCL toggle IRQ
    MCU_DVI_EDID_IRQ_FFE4 = ((MCU_DVI_EDID_IRQ_FFE4 & ~(_BIT3 | _BIT1)) | (_BIT2 | _BIT0));
        
    ScalerTmdsFreqDetectDisable();
}

//--------------------------------------------------
// Description  : TMDS Freq. Detection IRQ Disable and Clear Clock Counter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsFreqDetectDisable(void)
{
    // Disable TMDS Freq. Detect IRQ
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT1, 0x00);
    ScalerSetBit(P2_EF_HDMI_FREQDET_RESERVED, ~_BIT7, 0x00);   
       
    // Clear TMDS Clk Count
    g_usTmdsClkCount = 0;
}

//--------------------------------------------------
// Description  : TMDS Power Saving Detect DDC Handshake
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerTmdsDdcDetect_EXINT1(void) using 2
{
    BYTE ucLoop = 0;
        
    // HDDC Detect SCL Toggle
    while((MCU_DVI_EDID_IRQ_FFE4 & 0x0C) == 0x0C)
    {
        // Loop once for FW Debounce
        if(ucLoop == 0x00)
        {
            // Clear SCL Toggle
            MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;

            // Delayed for about 70us
            for(; ucLoop < 2; ucLoop++);
            
            continue;
        }

        // Disable SCL Toggle IRQ
        MCU_DVI_EDID_IRQ_FFE4 &= ~_BIT3;                
        // Clear SCL Toggle
        MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
        
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
        if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
        {
            g_bTmdsD0DdcDetected = _TRUE;
        }
#if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
        if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
        {
            g_bTmdsD2DdcDetected = _TRUE;
        }        
#endif

#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)
        if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
        {
            g_bTmdsD3DdcDetected = _TRUE;
        }        
#endif

#elif(_D1_DDC_CHANNEL_SEL == _DDC2) // Elif of #if(_D0_DDC_CHANNEL_SEL == _DDC2)
        if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
        {
            g_bTmdsD1DdcDetected = _TRUE;
        }        
#if(_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
        if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
        {
            g_bTmdsD2DdcDetected = _TRUE;
        }        
#endif

#if(_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1)
        if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
        {
            g_bTmdsD3DdcDetected = _TRUE;
        }        
#endif

#endif // End of #if(_D0_DDC_CHANNEL_SEL == _DDC2)

        return _TRUE;
    }

    // Clear SCL Toggle
    MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
    
    return _FALSE;
}

//--------------------------------------------------
// Description  : Process Required when Switched to Active State
// Input Value  : Input Source
// Output Value : None
//--------------------------------------------------
void ScalerTmdsFirstActiveProc(BYTE ucSourceType)
{
    ucSourceType = ucSourceType;
}

//--------------------------------------------------
// Description  : Check whether HDCP is enabled
// Input Value  : None
// Output Value : TRUE => HDCP Enabled
//--------------------------------------------------
bit ScalerTmdsHdcpEnabled(void)
{
    BYTE ucHDCPFrameCount[2];

    ScalerGetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_C0_HDCP_FRAME_COUNTER, 1, &ucHDCPFrameCount[0], _NON_AUTOINC);

    // Wait 2Vsync to make sure frame counter changing, and timeout 45ms (margin + 1/24 frame+rate)
    ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT3);
    ScalerTimerPollingFlagProc(45, P2_A4_TMDS_CTRL, _BIT3, _TRUE);
    ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT3);
    ScalerTimerPollingFlagProc(45, P2_A4_TMDS_CTRL, _BIT3, _TRUE);

    ScalerGetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_C0_HDCP_FRAME_COUNTER, 1, &ucHDCPFrameCount[1], _NON_AUTOINC);

    if(ucHDCPFrameCount[0] != ucHDCPFrameCount[1])
    {
        return _TRUE;
    }
    
    return _FALSE;
}
#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
