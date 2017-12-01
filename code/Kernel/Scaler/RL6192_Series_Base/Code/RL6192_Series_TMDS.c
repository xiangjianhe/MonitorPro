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
// ID Code      : RL6192_Series_TMDS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6192_SERIES_TMDS__

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
void ScalerTmdsSetPorchColor(EnumColorSpace enumColorFormat);

#if(_HDMI_SUPPORT == _ON)
void ScalerTmdsHdmiVideoSetting(void);
void ScalerTmdsHdmiPacketDetect(bit bWait);
void ScalerTmdsHdmiPacketDetectEvent(void);
BYTE ScalerTmdsHdmiGetAVIInfo(EnumAviInfoContent enumContent);
bit ScalerTmdsHdmiColorInfoChanged(void);
BYTE ScalerTmdsHdmiGetColorDepth(void);
void ScalerTmdsHdmiSetDeepColorPll(WORD usTmdsClkCount, BYTE ucColorDepth);
bit ScalerTmdsHdmiDeepColorProc(void);
bit ScalerTmdsHdmiWaitDeepColorPllLock(void);
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

    ScalerTmdsHdmiWatchDog((_HDMI_AVI_INFO_VARIATION_WD | _HDMI_AV_MUTE_WD), _DISABLE); 

    // Clear Info Packet SRAM
    ScalerSetBit(P2_AD_CPS, ~_BIT3, _BIT3);
    ScalerSetBit(P2_AD_CPS, ~_BIT3, 0x00);
    
    // Deep Color Mode clock and detection auto
    ScalerSetBit(P2_B8_TMDS_DPC1, ~(_BIT3 | _BIT2), _BIT2);

    // Enable BCH Detection
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_02_HDMI_BCHCR, ~(_BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT2 | _BIT1));

    // DVI mode don't disable Audio Clk
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, ~_BIT5, _BIT5);

    // Set Video Watch Dog New Mode
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_32_HDMI_WDCR1, ~_BIT5, _BIT5);  
    
    // Specify Packet Detect Type
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_43_HDMI_PTRSV0, _HDMI_AVI_INFO_TYPE);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_44_HDMI_PTRSV1, _HDMI_GENERAL_CONTROL_TYPE);
    
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
#if((_D1_DDC_CHANNEL_SEL == _DDC2) || (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2))           
        ScalerSetBit(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), 0x00);
#elif((_D1_DDC_CHANNEL_SEL == _DDC3) || (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3))
        ScalerSetBit(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1), _BIT1);
#endif
    }        
    // Set HDCP DDC Debounce, TMDS Function
    ScalerSetBit(P2_AC_Z0CC2, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

    // Set HDCP BCAPS
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

#endif // End of #if(_HDMI_SUPPORT == _ON)

    // Enable New Advance Cipher Mode, Enable HDCP Module
    ScalerSetBit(P2_C0_HDCP_CTRL, ~(_BIT7 | _BIT0), (_BIT7 | _BIT0));

    // MAC Select to HDMI
    ScalerSetBit(PC_A1_DP_CTL, ~_BIT5, _BIT5);

    // Enable MAC Input
    ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Set MAC Signal Swap
    ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~(_BIT6 | _BIT5), ((ucInputPort == _D0_INPUT_PORT) ? ((_D0_TMDS_BR_SWAP << 6) | (_D0_TMDS_PN_SWAP << 5)) : ((_D1_TMDS_BR_SWAP << 6) | (_D1_TMDS_PN_SWAP << 5))));

    // Auto switch to DVI when no signal
    ScalerSetBit(P2_AD_CPS, ~_BIT2, _BIT2);

    // Detec TMDS Format by both Video and Data Island Guard Band
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_00_HDMI_SCR, ~(_BIT4 | _BIT1), _BIT1);

    // Clear BCH Error in DVI Mode
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_02_HDMI_BCHCR, ~_BIT6, _BIT6);
    
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

#if(_DP_DUAL_MODE_SUPPORT == _ON)

    // Enable Rx_En for Clk pair Z0
    ScalerSetBit(PB_B4_DP_PWR_CTL, ~_BIT0, _BIT0);

    // Choose Measure Clk to TMDS Clk
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), (_BIT5 | _BIT4));

#else

    // Enable Rx_En for Clk pair Z0
    ScalerSetBit(PB_B4_DP_PWR_CTL, ~_BIT3, _BIT3);

    // Choose Measure Clk to TMDS Clk
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), 0x00);

#endif

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
    BYTE ucTemp = 0;

    ///////////////
    // Rx CMU en //
    ///////////////
    
#if(_DP_DUAL_MODE_SUPPORT == _ON)
    // Enable Rx_EN, CMU_EN
    ScalerSetByte_EXINT0(PB_B4_DP_PWR_CTL, 0xFF);
#else
    // Enable Rx_EN, CMU_EN
    ScalerSetByte_EXINT0(PB_B4_DP_PWR_CTL, 0x7F);
#endif    


    ////////////////
    // EQ Setting //
    ////////////////

    if((GET_INPUT_PIXEL_CLK() >= 240) && (GET_INPUT_PIXEL_CLK() < 1000)) // 25~100MHz
    {
        ScalerSetByte_EXINT0(PB_B1_DP_OOBS_SGN_DET, 0x82);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 1000) && (GET_INPUT_PIXEL_CLK() < 3400)) // 100~340MHz
    {
        ScalerSetByte_EXINT0(PB_B1_DP_OOBS_SGN_DET, 0xE2);
    }


    /////////////////
    // CDR Setting //
    /////////////////

    // Select CDR 1pf cs 46pF
    ScalerSetBit_EXINT0(PB_A4_DP_FLD_00, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);

    // Disable Loop Capacitor
    ScalerSetBit_EXINT0(PB_AA_DP_FLD_06, ~_BIT0, 0x00);
    
    // reg_xtal_sel = 0
    ScalerSetBit_EXINT0(PB_A9_DP_FLD_05, ~_BIT0, 0x00);

    if((GET_INPUT_PIXEL_CLK() >= 240) && (GET_INPUT_PIXEL_CLK() < 500)) // 25~50MHz (Considering 25MHz clk may shift)
    {
        // Enable CDR 1pf cp 1pF, CDR1pf cp 0.5pF
        ScalerSetBit_EXINT0(PB_A4_DP_FLD_00, ~(_BIT7 | _BIT5), (_BIT7 | _BIT5));

        // Enable Loop Capacitor
        ScalerSetBit_EXINT0(PB_AA_DP_FLD_06, ~_BIT0, _BIT0);
        
        // VCO Setting
        ScalerSetByte_EXINT0(PB_A5_DP_FLD_01, 0x81);

        // CDR Setting
        ScalerSetByte_EXINT0(PB_A6_DP_FLD_02, 0xA4);

        // reg_xtal_sel = 1
        ScalerSetBit_EXINT0(PB_A9_DP_FLD_05, ~_BIT0, _BIT0);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 500) && (GET_INPUT_PIXEL_CLK() < 1000)) // 50~100MHz
    {
        // VCO Setting
        ScalerSetByte_EXINT0(PB_A5_DP_FLD_01, 0x41);

        // CDR Setting
        ScalerSetByte_EXINT0(PB_A6_DP_FLD_02, 0xA4);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 1000) && (GET_INPUT_PIXEL_CLK() < 2000)) // 100~200MHz
    {
        // VCO Setting
        ScalerSetByte_EXINT0(PB_A5_DP_FLD_01, 0x71);

        // CDR Setting
        ScalerSetByte_EXINT0(PB_A6_DP_FLD_02, 0x10);        
    }
    else if((GET_INPUT_PIXEL_CLK() >= 2000) && (GET_INPUT_PIXEL_CLK() < 3400)) // 200~340MHz
    {
        // VCO Setting
        ScalerSetByte_EXINT0(PB_A5_DP_FLD_01, 0x31);

        // CDR Setting
        ScalerSetByte_EXINT0(PB_A6_DP_FLD_02, 0x10);        
    }

    // Set FLD Counter
    ScalerSetBit_EXINT0(PB_C8_CMU_08, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerSetByte_EXINT0(PB_C9_TX, 0x3F);
    ScalerSetByte_EXINT0(PB_CA_SSCG, 0x3F);

    // Crystal Input
    ScalerSetBit_EXINT0(PB_AB_DP_FLD_07, ~_BIT6, _BIT6);

    // FLD Auto Mode
    ScalerSetBit_EXINT0(PB_AF_DP_RXMISC_02, ~_BIT7, _BIT7);

    // Passive EQ
    ScalerSetBit_EXINT0(PB_AD_DP_FLD_09, ~_BIT3, _BIT3);


    //////////////
    // K Offset //
    //////////////
    
    // Toggle K Offset
    ScalerSetBit_EXINT0(PB_B2_DP_ADP_EQ, ~_BIT6, 0x00);
    ScalerSetBit_EXINT0(PB_B2_DP_ADP_EQ, ~_BIT6, _BIT6);    

    // Waiting for K Offset 
    for(ucTemp = 0; ucTemp <= 10; ucTemp++)
    {
        _nop_();
    }  
    

    ///////////////
    // FLD Reset //
    ///////////////
    
    // FLD Reset
    ScalerSetBit_EXINT0(PB_B5_DP_2D_SWITCH, ~_BIT0, 0x00);
    ScalerSetBit_EXINT0(PB_B5_DP_2D_SWITCH, ~_BIT0, _BIT0);    

    // Waiting for FLD Reset
    for(ucTemp = 0; ucTemp <= 80; ucTemp++)
    {
        _nop_();
    }      
    
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

#if(_DP_DUAL_MODE_SUPPORT == _ON)
    // Enable Rx_EN, CMU_EN
    ScalerSetByte(PB_B4_DP_PWR_CTL, 0xFF);
#else
    // Enable Rx_EN, CMU_EN
    ScalerSetByte(PB_B4_DP_PWR_CTL, 0x7F);
#endif

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
    
#if(_DP_DUAL_MODE_SUPPORT == _ON)
    // Enable Rx_EN, CMU_EN
    ScalerSetByte_EXINT0(PB_B4_DP_PWR_CTL, 0xFF);
#else
    // Enable Rx_EN, CMU_EN
    ScalerSetByte_EXINT0(PB_B4_DP_PWR_CTL, 0x7F);
#endif

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
    SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

    ScalerTmdsSetPorchColor(GET_COLOR_SPACE());    
}    

//--------------------------------------------------
// Description  : Set Back Ground Color
// Input Value  : Current Color Space
// Output Value : None
//--------------------------------------------------
void ScalerTmdsSetPorchColor(EnumColorSpace enumColorFormat)
{
    // Manual Set Background Color Enable
    ScalerSetBit(P2_B9_TMDS_OUT_CTRL, ~_BIT7, 0x00);

    if((enumColorFormat == _COLOR_SPACE_YCBCR444) || (enumColorFormat == _COLOR_SPACE_YCBCR422))
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

        pData[0] = ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE);

        // Get Color Space
        if(pData[0] != _AVI_COLOR_SPACE_RGB)
        {
            // YCbCr 422
            if(pData[0] == _AVI_COLOR_SPACE_YCC_422)
            {
                DebugMessageDigital("Get Color Space YUV422", pData[0]);
                SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
            }
            else
            {
                DebugMessageDigital("Get Color Space YUV444", pData[0]);
                SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
            }

            switch(ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_COLORIMETRY))
            {
                case _AVI_COLORIMETRY_NONE:

                    DebugMessageDigital("No Colorimetry Specified", 0x00);
                    SET_COLORIMETRY(_COLORIMETRY_NONE);
                    
                    break;

                case _AVI_COLORIMETRY_ITU601:

                    DebugMessageDigital("Get Colorimetry 601",0x00);
                    SET_COLORIMETRY(_COLORIMETRY_ITU601);
                    
                    break;

                case _AVI_COLORIMETRY_ITU709:

                    DebugMessageDigital("Get Colorimetry 709", 0x00);
                    SET_COLORIMETRY(_COLORIMETRY_ITU709);
                    
                    break;

                case _AVI_COLORIMETRY_EXTENDED:
                    
                    DebugMessageDigital("Get Colorimetry Extended", 0x00);
                    SET_COLORIMETRY(_COLORIMETRY_EXT);

                    pData[1] = ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY);

                    // Get extended colorimetry
                    if(pData[1] == _AVI_COLORIMETRY_EXT_XVYCC709)    // xvYCC709
                    {
                        SET_EXT_COLORIMETRY(_COLORIMETRY_XVYCC709);
                    }
                    else if(pData[1] == _AVI_COLORIMETRY_EXT_XVYCC601)    // xvYCC601
                    {
                        SET_EXT_COLORIMETRY(_COLORIMETRY_XVYCC601);
                    }
                    
                    break;

                default:
                    break;
            }  

            switch(ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION))
            {
                case _AVI_YCC_QUANTIZATION_FULL:

                    SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);
                    break;
                    
                case _AVI_YCC_QUANTIZATION_LIMITED:
                default:
                    
                    SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);
                    break;                    
            }
        }
        else    // Color Space RGB
        {
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);

            switch(ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION))
            {
                case _AVI_RGB_QUANTIZATION_LIMITED:

                    DebugMessageDigital("Get RGB LIMIT RANGE", 0x00);
                    SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_LIMIT_RANGE);

                    break;
                    
                case _AVI_RGB_QUANTIZATION_FULL:

                    DebugMessageDigital("Get RGB FULL RANGE", 0x00);
                    SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                    break;

                case _AVI_RGB_QUANTIZATION_DEFAULT:
                    
                    DebugMessageDigital("Get RGB DEFAULT RANGE", 0x00);
                    SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_DEFAULT_RANGE);
                    
                    break;

                case _AVI_RGB_QUANTIZATION_RESERVED:

                    DebugMessageDigital("Get RGB RESERVED RANGE", 0x00);
                    SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);
                    
                    break;
                                                                                
            }           
        }            
    }    
    else    // No Info Frame Received
    {
        // Mannal Set Color Space and disable pixel  repetition
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_51_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT2), 0x00);
        
        // Disable down sampling
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_50_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 |_BIT0), 0x00);

        // Waiting for down sampling  effect
        ScalerTimerDelayXms(20);
        
        SET_COLOR_SPACE(_COLOR_SPACE_RGB);
        SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);
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

            // Waiting for Down Sampling Effect
            ScalerTimerDelayXms(20);
            
            ScalerTmdsHdmiWatchDog(_HDMI_AVI_INFO_VARIATION_WD, _DISABLE);  

            CLR_HDMI_AVI_INFO_FRAME_RECEIVED();                 
        }

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
// Description  : Get HDMI AVI Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerTmdsHdmiGetAVIInfo(EnumAviInfoContent enumContent)
{       
    if(GET_HDMI_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        switch(enumContent)
        {
            case _AVI_INFO_COLOR_SPACE:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x04, (_BIT6 | _BIT5)) >> 5);

            case _AVI_INFO_COLORIMETRY:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x05, (_BIT7 | _BIT6)) >> 6);

            case _AVI_INFO_EXTENDED_COLORIMETRY:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x06, (_BIT6 | _BIT5 | _BIT4)) >> 4);
                
            case _AVI_INFO_RGB_QUANTIZATION:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x06, (_BIT3 | _BIT2)) >> 2); 

            case _AVI_INFO_YCC_QUANTIZATION:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x08, (_BIT7 | _BIT6)) >> 6); 

            case _AVI_INFO_SCAN_INFO:

                return ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x04, (_BIT1 | _BIT0));             

            case _AVI_INFO_IT_CONTENT:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x06, _BIT7) >> 7);
                
            default:

                break;
        }
    }

    return 0xFF;    
    
}

//--------------------------------------------------
// Description  : Detect HDMI Colo Info 
// Input Value  : None
// Output Value : _TRUE => Current Color Info is different from previous setting
//--------------------------------------------------    
bit ScalerTmdsHdmiColorInfoChanged(void)
{        
    // Check Color Space
    if(ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE) != GET_COLOR_SPACE())
    {
        DebugMessageDigital("Color Space Changed", 0x00);
        return _TRUE;
    }

    if(GET_COLOR_SPACE() != _COLOR_SPACE_RGB)
    {
        // Check Colorimetry
        if(ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_COLORIMETRY) != GET_COLORIMETRY())
        {
            DebugMessageDigital("Colorimetry Changed", 0x00);
            return _TRUE;
        }
        else
        {
            if(GET_COLORIMETRY() == _COLORIMETRY_EXT)
            {
                if(ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY) != GET_EXT_COLORIMETRY())
                {
                    DebugMessageDigital("Ext Colorimetry Changed", 0x00);
                    return _TRUE;
                }
            }
        }

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
        pData[0] = ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION);

        if(((GET_COLOR_YCC_QUANTIZATION_RANGE() == _YCC_QUANTIZATION_LIMIT_RANGE) && (pData[0] != _AVI_YCC_QUANTIZATION_LIMITED)) || 
            ((GET_COLOR_YCC_QUANTIZATION_RANGE() == _YCC_QUANTIZATION_FULL_RANGE) && (pData[0] != _AVI_YCC_QUANTIZATION_FULL)))
        {
            DebugMessageDigital("YCC Quantizatoin Range Changed", pData[0]);            
            return _TRUE;
        }
#endif        

    }
    
#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)    

    else
    {
        pData[0] = ScalerTmdsHdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION);
        
        if(((GET_COLOR_RGB_QUANTIZATION_RANGE() == _RGB_QUANTIZATION_LIMIT_RANGE) && (pData[0] != _AVI_RGB_QUANTIZATION_LIMITED)) ||
            ((GET_COLOR_RGB_QUANTIZATION_RANGE() == _RGB_QUANTIZATION_FULL_RANGE) && (pData[0] != _AVI_RGB_QUANTIZATION_FULL)) ||
            ((GET_COLOR_RGB_QUANTIZATION_RANGE() == _RGB_QUANTIZATION_DEFAULT_RANGE) && (pData[0] != _AVI_RGB_QUANTIZATION_DEFAULT)) ||
            ((GET_COLOR_RGB_QUANTIZATION_RANGE() == _RGB_QUANTIZATION_RESERVED) && (pData[0] != _AVI_RGB_QUANTIZATION_RESERVED)))
        {
            DebugMessageDigital("RGB Quantizatoin Range Changed", pData[0]);
            return _TRUE;
        }
    }
#endif

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
// Description  : Set Deep Color PLL
// Input Value  : usTmdsClkCount, ucColorDepth
// Output Value : None
//--------------------------------------------------
void ScalerTmdsHdmiSetDeepColorPll(WORD usTmdsClkCount, BYTE ucColorDepth)
{
    DWORD ulTmdsClkValue = 0;    
    BYTE ucM = 0;
    BYTE ucN = 0;
    BYTE ucDivS = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Fref = TMDS_clk
    // 10bit: PLL freq = 8 / 10 * TMDS_clk
    // 12bit: PLL freq = 8 / 12 * TMDS_clk
    // 16bit: PLL freq = 8 / 16 * TMDS_clk
    // 
    // PLL freq = M / N * TMDS_clk / div_s / div_o, let div_o = 1
    //
    // note 1.   Fref / N = TMDS_clk / N >= 5
    // note 2_a. 10bit : (M / N / div_s) = 8 / 10 = 32 / 40 or 16 / 20, let M = 32 or 16.
    // note 2_b. 12bit : (M / N / div_s) = 8 / 12 = 32 / 48 or 16 / 24, let M = 32 or 16.
    // note 2_b. 16bit : (M / N / div_s) = 8 / 16 = 24 / 48 or 16 / 32, let M = 24 or 16.
    // note 3.   N <= 17, div_s = 2X
    // note 4.   270MHz < M / N * Fref < 540MHz    
    ////////////////////////////////////////////////////////////////////////////////////////////////  

    // TMDS_clk, unit:kHz
    ulTmdsClkValue = (DWORD)_GDI_CLK_KHZ * 1024 / usTmdsClkCount;
    
    switch(ucColorDepth)
    {
        case _COLOR_DEPTH_10_BITS:

            // Check note 4. for Max N for M = 32
            if((ulTmdsClkValue * 32 / 10) <= 540000)
            {
                // All Possible N for M = 32
                pData[0] = 10;
                pData[1] =  5;
                pData[2] =  4;
                pData[3] =  2;

                // Default M/ N/ DivS
                ucM = 32;
                ucN = pData[3];
                ucDivS = 40 / ucN;            

                PDATA_DWORD(2) = ulTmdsClkValue * ucM;
                
                for(pData[15] = 0; pData[15] <= 3; pData[15]++)
                {  
                    // Check note 1.
                    if((ulTmdsClkValue / pData[pData[15]]) > 5000)
                    {   
                        // Check note 4. for each possible N
                        if(((PDATA_DWORD(2) / pData[pData[15]]) >= 270000) && ((PDATA_DWORD(2) / pData[pData[15]]) < 540000))
                        {
                            ucN = pData[pData[15]];
                            ucDivS = 40 / ucN;
                            break;
                        }
                    }
                }
            }
            else
            {                                
                // All Possible N for M = 16
                pData[0] = 10;
                pData[1] =  5;
                pData[2] =  2;

                // Default M/ N/ DivS
                ucM = 16;
                ucN = pData[2];
                ucDivS = 20 / ucN;            

                PDATA_DWORD(2) = ulTmdsClkValue * ucM;
                
                for(pData[15] = 0; pData[15] <= 2; pData[15]++)
                {  
                    // Check note 1.
                    if((ulTmdsClkValue / pData[pData[15]]) > 5000)
                    {   
                        // Check note 4. for each possible N
                        if(((PDATA_DWORD(2) / pData[pData[15]]) >= 270000) && ((PDATA_DWORD(2) / pData[pData[15]]) < 540000))
                        {
                            ucN = pData[pData[15]];
                            ucDivS = 20 / ucN;
                            break;
                        }
                    }
                }
            }
         
            break;

        case _COLOR_DEPTH_12_BITS:

            // Check note 4. for Max N for M = 32
            if((ulTmdsClkValue * 32 / 12) <= 540000)
            {
                // All Possible N for M = 32
                pData[0] = 12;
                pData[1] =  8;
                pData[2] =  6;
                pData[3] =  4;
                pData[4] =  3;
                pData[5] =  2;

                // Default M/ N/ DivS
                ucM = 32;
                ucN = pData[5];
                ucDivS = 48 / ucN; 

                PDATA_DWORD(2) = ulTmdsClkValue * ucM;
                
                for(pData[15] = 0; pData[15] <= 5; pData[15]++)
                {              
                    // Check note 1.
                    if((ulTmdsClkValue / pData[pData[15]]) > 5000)
                    {     
                        // Check note 4. for each possible N
                        if(((PDATA_DWORD(2) / pData[pData[15]]) >= 270000) && ((PDATA_DWORD(2) / pData[pData[15]]) < 540000))
                        {
                            ucN = pData[pData[15]];
                            ucDivS = 48 / ucN;
                            break;
                        }
                    }
                }
            }
            else
            {
                // All Possible N for M = 16
                pData[0] = 12;
                pData[1] =  6;
                pData[2] =  4;
                pData[3] =  3;
                pData[4] =  2;

                // Default M/ N/ DivS
                ucM = 16;
                ucN = pData[4];
                ucDivS = 24 / ucN; 

                PDATA_DWORD(2) = ulTmdsClkValue * ucM;
                
                for(pData[15] = 0; pData[15] <= 5; pData[15]++)
                {              
                    // Check note 1.
                    if((ulTmdsClkValue / pData[pData[15]]) > 5000)
                    {                
                        // Check note 4. for each possible N
                        if(((PDATA_DWORD(2) / pData[pData[15]]) >= 270000) && ((PDATA_DWORD(2) / pData[pData[15]]) < 540000))
                        {
                            ucN = pData[pData[15]];
                            ucDivS = 24 / ucN;
                            break;
                        }
                    }
                }
            }

            break;

        case _COLOR_DEPTH_16_BITS:

            // Check note 4. for Max N for M = 24
            if((ulTmdsClkValue * 24 / 12) <= 540000)
            {
                // All Possible N for M = 24
                pData[0] = 12;
                pData[1] =  8;
                pData[2] =  6;
                pData[3] =  4;
                pData[4] =  3;
                pData[5] =  2;

                // Default M/ N/ DivS
                ucM = 24;
                ucN = pData[5];
                ucDivS = 48 / ucN; 

                PDATA_DWORD(2) = ulTmdsClkValue * ucM;
                
                for(pData[15] = 0; pData[15] <= 5; pData[15]++)
                {   
                    // Check note 1.
                    if((ulTmdsClkValue / pData[pData[15]]) > 5000)
                    {
                        // Check note 4. for each possible N
                        if(((PDATA_DWORD(2) / pData[pData[15]]) >= 270000) && ((PDATA_DWORD(2) / pData[pData[15]]) < 540000))
                        {
                            ucN = pData[pData[15]];
                            ucDivS = 48 / ucN;
                            break;
                        }
                    }
                }            
            }
            else
            {
                // All Possible N for M = 16
                pData[0] = 16;
                pData[1] =  8;
                pData[2] =  4;
                pData[3] =  2;

                // Default M/ N/ DivS
                ucM = 16;
                ucN = pData[3];
                ucDivS = 32 / ucN; 

                PDATA_DWORD(2) = ulTmdsClkValue * ucM;
                
                for(pData[15] = 0; pData[15] <= 5; pData[15]++)
                {   
                    // Check note 1.
                    if((ulTmdsClkValue / pData[pData[15]]) > 5000)
                    {                    
                        // Check note 4. for each possible N
                        if(((PDATA_DWORD(2) / pData[pData[15]]) >= 270000) && ((PDATA_DWORD(2) / pData[pData[15]]) < 540000))
                        {
                            ucN = pData[pData[15]];
                            ucDivS = 32 / ucN;
                            break;
                        }
                    }
                }            
            }
           
            break;  

        default:

            break;
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    // New Formula : Icp * N_Code / M_Code = 0.5 * Fref / 27MHz (for xtal not 27MHz)        //
    // Fref    = GDI_clk * 1024 / TMDS_count                                                //
    // Icp     = M_Code / N_Code * 0.5 * Fxtal / 27MHz                                      //
    // Icp     = 2.5u + DPLL_IP[0] * 2.5u + DPLL_IP[1] * 5u + DPLL_IP[2] * 10u (A)          //
    //////////////////////////////////////////////////////////////////////////////////////////
 
    pData[5] = (DWORD)ucM * _GDI_CLK_KHZ * 1024 / usTmdsClkCount * 20 / ucN / 2 / _XTAL27000K;
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
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_52_MN_SCLKG_DIVS, (ucDivS >> 1));

    // Set DPPLL Div_O.
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_70_MN_SCLKG_PLL_PWR, ~(_BIT1 | _BIT0), (0 & (_BIT1 | _BIT0)));

    // Offset Value Setting
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_55_MN_SCLKG_OFFS_L, 0);
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_54_MN_SCLKG_OFFS_M, 0);
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_53_MN_SCLKG_OFFS_H, ~(_BIT2 | _BIT1 | _BIT0), 0x0);
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_56_MN_SCLKG_TRK_CTRL, ~(_BIT1 | _BIT0), 0x0);

    // Enable phase swallow
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_67_MN_SCLKG_SDM_CTRL, ~(_BIT5 | _BIT4), _BIT4);

    // Set DPPLL M Code    
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_51_MN_SCLKG_DIVM, ucM - 2);

    // PLL Input Clock select to Link Clock, Output Clock Select to PLL Clock, N Code, Double Buffer.
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_50_MN_SCLKG_CTRL, ~(0xFF), (_BIT7 | _BIT4 | ((ucN - 2) & 0x0F)));

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
}

bit ScalerTmdsHdmiDeepColorProc(void)
{
    // Enable Deep Color Block        
    ScalerTmdsHdmiSetDeepColorPll(g_usTmdsClkCount, GET_COLOR_DEPTH());

    // Wait for Phase lock
    if(ScalerTmdsHdmiWaitDeepColorPllLock() == _FALSE)
    {
        return _FALSE;
    }
    
    return _TRUE;
}

//--------------------------------------------------
// Description  : Wait for Deep Color PLL Phase Lock
// Input Value  : None
// Output Value : _TRUE = > Phase Locked
//--------------------------------------------------
bit ScalerTmdsHdmiWaitDeepColorPllLock(void)
{
    pData[0] = 0;
        
    do
    {
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_82_HDMI_DPC_SET2, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

        // Delay for PLL Phase Lock
        ScalerTimerDelayXms(2);
        
        pData[0]++;
    }
    while((ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_82_HDMI_DPC_SET2, _BIT1) != 0) && (pData[0] <= 15));

    if(pData[0] > 15)
    {
        return _FALSE;        
    }
    
    return _TRUE;
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

        // Enable Video/Audio Output
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~(_BIT5 | _BIT3), (_BIT5 | _BIT3));

        // Enable RGB Output
        ScalerSetBit(P2_A6_TMDS_OUTPUT_CTRL, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

        // Enable AVMute Watch Dog
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~_BIT7, _BIT7);       
    }            
}

//--------------------------------------------------
// Description  : Hdmi Enable Watch Dog
// Input Value  : ucWDType => Watch Dog type, bEnable => Enable watch dog flag
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

#elif((_D1_DDC_CHANNEL_SEL == _DDC2) || (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2)) // Elif of #if(_D0_DDC_CHANNEL_SEL == _DDC2)
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

#elif((_D1_DDC_CHANNEL_SEL == _DDC3) || (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3)) // Elif of #if(_D0_DDC_CHANNEL_SEL == _DDC3)
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
