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
// ID Code      : RL6213_Series_TMDS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6213_SERIES_TMDS__

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
void ScalerTmdsSetPhy_EXINT0(void);
void ScalerTmdsIntHandler_EXINT0(void);
bit ScalerTmdsCheckCDRStable(WORD usClkCount);
BYTE ScalerTmdsCheckCDRStable_EXINT0(WORD usClkCount);
WORD ScalerTmdsMeasureClk(BYTE ucMeasureClk);
WORD ScalerTmdsMeasureClk_EXINT0(BYTE ucMeasureClk);
BYTE ScalerTmdsFormatDetect(void);
void ScalerTmdsDviVideoSetting(void);
void ScalerTmdsSetPorchColor(void);

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

    // Set HS Width(DE only) and HDCP Reference VS
    ScalerSetBit(P2_AB_TMDS_ACC2, ~(_BIT7 | _BIT6), 0x00);

#if(_HDMI_SUPPORT == _ON)
    // Deep Color Mode clock and detection auto
    ScalerSetBit(P2_B8_TMDS_DPC1, ~(_BIT3 | _BIT2), _BIT2);

    // Enable BCH Detection
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_02_HDMI_BCHCR, ~(_BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT2 | _BIT1));

    // DVI mode don't disable Audio Clk
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, ~_BIT5, _BIT5);

    // Packet Variation Detect Disable
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_45_HDMI_PVGCR0, 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_46_HDMI_PVGCR1, 0x00);
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_47_HDMI_PVGCR2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#endif
    
    // Set HDCP DDC Channel
    if(ucInputPort == _D0_INPUT_PORT)
    {
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
        ScalerSetBit(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), 0x00);
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
        ScalerSetBit(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), _BIT1);
#endif
    }
    else
    {
#if(_D1_DDC_CHANNEL_SEL == _DDC2)            
        ScalerSetBit(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), 0x00);
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
        ScalerSetBit(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), _BIT1);
#endif
    }        
    
    // Set HDCP DDC Debounce, TMDS Function
    ScalerSetBit(P2_AC_Z0CC2, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

    // Set HDCP BCAPS
#if(_HDMI_SUPPORT == _ON)    
    ScalerSetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, 0x81);
#else
    ScalerSetDataPortByte(P2_C3_HDCP_ADDR_PORT, _P2_C4_PT_40_HDCP_BCAPS, 0x01);
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
    ScalerSetBit(PB_B4_DP_PWR_CTL, ~_BIT3, _BIT3);

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
// Description  : TMDS Set PHY Function (EXINT0 Only)
// Input Value  : Measured Clk Count for PHY Setting
// Output Value : None
//--------------------------------------------------
void ScalerTmdsSetPhy_EXINT0(void) using 1
{       
    // r_cont_divider
    ScalerSetByte_EXINT0(PB_C0_CMU_00, 0x80);
    ScalerSetByte_EXINT0(PB_C1_CMU_01, 0x92);
    ScalerSetByte_EXINT0(PB_C2_CMU_02, 0x0F);
    ScalerSetByte_EXINT0(PB_C3_CMU_03, 0x70);
    ScalerSetByte_EXINT0(PB_C4_CMU_04, 0x38);
    ScalerSetByte_EXINT0(PB_C5_CMU_05, 0x15);
    ScalerSetByte_EXINT0(PB_AA_DP_FLD_06, 0x10);   

    ScalerSetBit_EXINT0(PB_C7_CMU_07, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerSetByte_EXINT0(PB_C8_CMU_08, 0x3F);
    ScalerSetByte_EXINT0(PB_C9_TX, 0x3F);

    // Bypass TP1_DET_MANUAL
    ScalerSetBit_EXINT0(PB_D5_RX_BIST_05, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    
    // 25~50MHz (Considering 25MHz clk may shift)
    if((GET_INPUT_PIXEL_CLK() >= 240) && (GET_INPUT_PIXEL_CLK() < 500)) 
    {
        ScalerSetByte_EXINT0(PB_A1_DP_CDR_01, 0x84);
        ScalerSetByte_EXINT0(PB_A2_DP_CDR_02, 0xA9);
        ScalerSetByte_EXINT0(PB_A3_DP_CDR_03, 0xD5);
        ScalerSetBit_EXINT0(PB_A4_DP_FLD_00, ~_BIT0, _BIT0);
        ScalerSetByte_EXINT0(PB_AD_DP_FLD_09, 0x0F);
        ScalerSetByte_EXINT0(PB_B2_DP_ADP_EQ, 0x76);
        ScalerSetByte_EXINT0(PB_B8_DP_AUX_01, 0xC0);
        ScalerSetByte_EXINT0(PB_BA_DP_RESERVED_00, 0x88);
        ScalerSetByte_EXINT0(PB_BF_DP_RESERVED_05, 0xF4);
        ScalerSetByte_EXINT0(PB_AE_DP_RXMISC_01, 0x01);        
    }
    else if((GET_INPUT_PIXEL_CLK() >= 500) && (GET_INPUT_PIXEL_CLK() < 1000)) // 50~100MHz
    {
        ScalerSetByte_EXINT0(PB_A1_DP_CDR_01, 0x44);
        ScalerSetByte_EXINT0(PB_A2_DP_CDR_02, 0xA9);
        ScalerSetByte_EXINT0(PB_A3_DP_CDR_03, 0xD5);
        ScalerSetBit_EXINT0(PB_A4_DP_FLD_00, ~_BIT0, 0x00);
        ScalerSetByte_EXINT0(PB_AD_DP_FLD_09, 0x0F);
        ScalerSetByte_EXINT0(PB_B2_DP_ADP_EQ, 0x7E);
        ScalerSetByte_EXINT0(PB_B8_DP_AUX_01, 0xC0);
        ScalerSetByte_EXINT0(PB_BA_DP_RESERVED_00, 0x88);
        ScalerSetByte_EXINT0(PB_BF_DP_RESERVED_05, 0xF4);
        ScalerSetByte_EXINT0(PB_AE_DP_RXMISC_01, 0x01);                
    }
    else if((GET_INPUT_PIXEL_CLK() >= 1000) && (GET_INPUT_PIXEL_CLK() < 2000)) // 100~200MHz
    {
        ScalerSetByte_EXINT0(PB_A1_DP_CDR_01, 0x74);
        ScalerSetByte_EXINT0(PB_A2_DP_CDR_02, 0x11);
        ScalerSetByte_EXINT0(PB_A3_DP_CDR_03, 0xD4);
        ScalerSetBit_EXINT0(PB_A4_DP_FLD_00, ~_BIT0, 0x00);
        ScalerSetByte_EXINT0(PB_AD_DP_FLD_09, 0x0F);
        ScalerSetByte_EXINT0(PB_B2_DP_ADP_EQ, 0x76);
        ScalerSetByte_EXINT0(PB_B8_DP_AUX_01, 0x00);
        ScalerSetByte_EXINT0(PB_BA_DP_RESERVED_00, 0x88);
        ScalerSetByte_EXINT0(PB_BF_DP_RESERVED_05, 0xE4);
        ScalerSetByte_EXINT0(PB_AE_DP_RXMISC_01, 0x09);    
    }
    else if((GET_INPUT_PIXEL_CLK() >= 2000) && (GET_INPUT_PIXEL_CLK() < 3400)) // 200~340MHz
    {
        ScalerSetByte_EXINT0(PB_A1_DP_CDR_01, 0x34);
        ScalerSetByte_EXINT0(PB_A2_DP_CDR_02, 0x11);
        ScalerSetByte_EXINT0(PB_A3_DP_CDR_03, 0xD4);
        ScalerSetBit_EXINT0(PB_A4_DP_FLD_00, ~_BIT0, 0x00);
        ScalerSetByte_EXINT0(PB_AD_DP_FLD_09, 0x0F);
        ScalerSetByte_EXINT0(PB_B2_DP_ADP_EQ, 0x76);
        ScalerSetByte_EXINT0(PB_B8_DP_AUX_01, 0x00);
        ScalerSetByte_EXINT0(PB_BA_DP_RESERVED_00, 0x88);
        ScalerSetByte_EXINT0(PB_BF_DP_RESERVED_05, 0xF4);
        ScalerSetByte_EXINT0(PB_AE_DP_RXMISC_01, 0x09);            
    }

    ScalerSetByte_EXINT0(PB_AF_DP_RXMISC_02, 0xC7);
    ScalerSetBit_EXINT0(PB_A9_DP_FLD_05, ~_BIT5, 0x00);

    // Toggle Adaptive Equalizer offset calibration enable
    ScalerSetBit_EXINT0(PB_B2_DP_ADP_EQ, ~_BIT6, _BIT6);
    ScalerSetBit_EXINT0(PB_B2_DP_ADP_EQ, ~_BIT6, 0x00);
    ScalerSetBit_EXINT0(PB_B2_DP_ADP_EQ, ~_BIT6, _BIT6);
    
    // Reset PHY->MAC Interface
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
    ScalerSetByte(PB_B4_DP_PWR_CTL, 0x7F);

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
    ScalerSetByte_EXINT0(PB_B4_DP_PWR_CTL, 0x7F);

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
    if(ScalerGetBit(P2_CB_HDMI_SR, _BIT0) == _BIT0)
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
// Input Value  : Source Type
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
    
    ScalerTmdsSetPorchColor();    
}    

//--------------------------------------------------
// Description  : Set Back Ground Color
// Input Value  : Current Color Space
// Output Value : None
//--------------------------------------------------
void ScalerTmdsSetPorchColor(void)
{
    // Manual Set Background Color Enable
    ScalerSetBit(P2_B9_TMDS_OUT_CTRL, ~_BIT7, 0x00);

    // Set Background Color RGB Black
    ScalerSetByte(P2_BA_TMDS_ROUT_HIGH_BYTE, 0x00);
    ScalerSetByte(P2_BB_TMDS_ROUT_LOW_BYTE, 0x00);
    ScalerSetByte(P2_BC_TMDS_GOUT_HIGH_BYTE, 0x00);
    ScalerSetByte(P2_BD_TMDS_GOUT_LOW_BYTE, 0x00);
    ScalerSetByte(P2_BE_TMDS_BOUT_HIGH_BYTE, 0x00);
    ScalerSetByte(P2_BF_TMDS_BOUT_LOW_BYTE, 0x00);
}

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Video Setting
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiVideoSetting(void)
{
    ScalerTmdsDviVideoSetting();
}

//--------------------------------------------------
// Description  : Detect HDMI Info Frame
// Input Value  : bWait => Whether to wait then read
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiPacketDetect(bit bWait)
{
    bWait = bWait;

    CLR_HDMI_AVI_INFO_FRAME_RECEIVED();
    CLR_HDMI_GCP_RECEIVED();
    CLR_HDMI_PACKET_DETECTING();
}

//--------------------------------------------------
// Description  : HDMI Info Frame Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiPacketDetectEvent(void)
{
}

//--------------------------------------------------
// Description  : Detect HDMI Colo Info 
// Input Value  : None
// Output Value : _TRUE => Current Color Info is different from previous setting
//--------------------------------------------------    
bit ScalerTmdsHdmiColorInfoChanged(void)
{     
    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Color Depth
// Input Value  : None
// Output Value : Received Color Depth
//--------------------------------------------------
BYTE ScalerTmdsHdmiGetColorDepth(void)
{
    return _COLOR_DEPTH_8_BITS;
}


bit ScalerTmdsHdmiDeepColorProc(void)
{   
    return _TRUE;
}

//--------------------------------------------------
// Description  : Hdmi Handle AVMute Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiAVMuteProc(void)
{
}

//--------------------------------------------------
// Description  : Hdmi Enable Watch Dog
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiWatchDog(BYTE ucWDType, bit bEnable)
{
    ucWDType = ucWDType;
    bEnable = bEnable;
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
    MCU_HDMI_EDID_IRQ_FFE5 = ((MCU_HDMI_EDID_IRQ_FFE5 & ~(_BIT3 | _BIT1)) | (_BIT2 | _BIT0));
        
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
        
    // DDC2 Detect SCL Toggle
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
        MCU_HDMI_EDID_IRQ_FFE5 &= ~_BIT3;
               
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

    // DDC3 Detect SCL Toggle
    while((MCU_HDMI_EDID_IRQ_FFE5 & 0x0C) == 0x0C)
    {                        
        // Loop once for FW Debounce
        if(ucLoop == 0x00)
        {
            // Clear SCL Toggle
            MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
            
            // Delayed for about 70us            
            for(; ucLoop < 2; ucLoop++);
            
            continue;
        }
        
        // Disable SCL Toggle IRQ
        MCU_DVI_EDID_IRQ_FFE4 &= ~_BIT3;   
        MCU_HDMI_EDID_IRQ_FFE5 &= ~_BIT3;
        
#if(_D0_DDC_CHANNEL_SEL == _DDC3)
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

#elif(_D1_DDC_CHANNEL_SEL == _DDC3) // Elif of #if(_D0_DDC_CHANNEL_SEL == _DDC3)
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

#endif // End of #if(_D0_DDC_CHANNEL_SEL == _DDC3)

        return _TRUE;        
    }    

    // Clear SCL Toggle
    MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
    // Clear SCL Toggle            
    MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
    
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
