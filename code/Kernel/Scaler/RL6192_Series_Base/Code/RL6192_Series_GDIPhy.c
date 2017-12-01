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
// ID Code      : RL6192_Series_GDIPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6192_SERIES_GDIPHY__

#include "ScalerFunctionInclude.h"

#if(_DIGITAL_PORT_SUPPORT == _ON)
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


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerGDIDigitalPhySwitch(BYTE ucInputPortType);
void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bSelect);
void ScalerGDIPhy2DSwitch(BYTE ucPortSelect);
void ScalerGDIPhyPowerSavingProc(void);
void ScalerGDIPhyPowerOffProc(void);
void ScalerGDIBandgap(bit bSelect);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : GDI Digital PHY Switch
// Input Value  : InputPortType
// Output Value : None
//--------------------------------------------------
void ScalerGDIDigitalPhySwitch(BYTE ucInputPortType)
{
    ucInputPortType = ucInputPortType;
    
#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
    if((ucInputPortType == _D0_DVI_PORT) || (ucInputPortType == _D1_DVI_PORT) || (ucInputPortType == _D2_DVI_PORT) || (ucInputPortType == _D3_DVI_PORT) ||
        (ucInputPortType == _D0_HDMI_PORT) || (ucInputPortType == _D1_HDMI_PORT) || (ucInputPortType == _D2_HDMI_PORT) || (ucInputPortType == _D3_HDMI_PORT))
    {
        // Current SI at DP
        if((bit)(ScalerGetBit(PB_E0_DIG00, _BIT4)) != _BIT4)
        {
            // Disable Rx_En and CMU_En
            ScalerSetByte(PB_B4_DP_PWR_CTL, 0x00);

            // Disable Port 0,1 Z0
            ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT4 | _BIT5 | _BIT6 | _BIT7), 0x00);
            ScalerSetBit(PB_B7_DP_CEC, ~(_BIT4 | _BIT5 | _BIT6 | _BIT7), 0x00);      

            // Dual Mode Disable and Analog Select to HDMI
            ScalerSetBit(PB_AC_DP_FLD_08, ~(_BIT3 | _BIT4), 0x00);            
        }

        // Digital PHY Lane Swap Setting
        ScalerSetByte(PB_D0_RX_BIST_00, 0xE4);       

        // Digital PHY P/N Swap Setting
        ScalerSetBit(PB_D1_RX_BIST_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);        

        // Switch to HDMI
        ScalerSetBit(PB_E0_DIG00, ~_BIT4, _BIT4);
        ScalerSetBit(PB_B4_DP_PWR_CTL, ~_BIT3, _BIT3);
    }
#if(_DP_DUAL_MODE_SUPPORT == _ON) 
    else if((ucInputPortType == _D1_DP_DUAL_PORT) && (GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS))
    {
        DebugMessageDigital("7. wuzanne test : Digital Port Switch To DP Dual HDMI", 0);

        // Current SI at DP
        if((bit)(ScalerGetBit(PB_E0_DIG00, _BIT4)) != _BIT4)
        {
            // Disable Rx_En and CMU_En
            ScalerSetByte(PB_B4_DP_PWR_CTL, 0x00);

            // Disable Port 0,1 Z0
            ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT4 | _BIT5 | _BIT6 | _BIT7), 0x00);
            ScalerSetBit(PB_B7_DP_CEC, ~(_BIT4 | _BIT5 | _BIT6 | _BIT7), 0x00);      
        }

        // Dual Mode Disable and Analog Select to HDMI
        ScalerSetBit(PB_AC_DP_FLD_08, ~(_BIT3 | _BIT4), (_BIT3 | _BIT4));	

        ScalerSetByte(PB_D0_RX_BIST_00, 0x1B);
        
        // Switch to HDMI
        ScalerSetBit(PB_E0_DIG00, ~_BIT4, _BIT4);
        ScalerSetBit(PB_B4_DP_PWR_CTL, ~_BIT0, _BIT0);          
    }
#endif

#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
}

//--------------------------------------------------
// Description  : GDI Z0 Switch 
// Input Value  : D0/D1 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bSelect)
{
    if(ucPortSelect == _D0_INPUT_PORT)
    {
        if(bSelect == _ON)
        {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))
            if((ScalerGetByte(PB_B6_DP_Z0_CALIBRATION) & 0xF0) == 0x00)
            {
                SET_TMDS_Z0_ASSERTED();
                CLR_TMDS_HPD_TRIGGER_EVENT();
                
                ScalerSetBit(P2_A9_TMDS_ACC1, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                g_bTmdsD0DdcDetected = _FALSE;
                
                // Enable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;                                                    
#endif                                 
            }
#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            if(ScalerGetBit(PB_B6_DP_Z0_CALIBRATION, _BIT7) == 0x00)
            {
                // Port 0 Z0 Enable
                ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
            // Disable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
            MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT3 | _BIT1);
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
            MCU_HDMI_EDID_IRQ_FFE5 &= ~(_BIT3 | _BIT1);                                                    
#endif      

#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            // Port 0 Z0 Disable
            ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            if((ScalerGetByte(PB_B7_DP_CEC) & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00)
            {
                // Disable HDCP Module
                ScalerSetBit(P2_C0_HDCP_CTRL, ~_BIT0, 0x00);
            } 
        }
    }
    else if(ucPortSelect == _D1_INPUT_PORT)
    {
        if(bSelect == _ON)
        {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
            if((ScalerGetByte(PB_B7_DP_CEC) & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00)
            {
                SET_TMDS_Z0_ASSERTED();
                CLR_TMDS_HPD_TRIGGER_EVENT();
                
                ScalerSetBit(P2_A9_TMDS_ACC1, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                g_bTmdsD1DdcDetected = _FALSE;    

                // Enable DDC Toggle IRQ
#if((_D1_DDC_CHANNEL_SEL == _DDC2) || (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2))
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
#elif((_D1_DDC_CHANNEL_SEL == _DDC3) || (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3))
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;
#endif                
            }
#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            if(ScalerGetBit(PB_B7_DP_CEC, _BIT7) == 0x00)
            {
                // Port 1 Z0 Enable
                ScalerSetBit(PB_B7_DP_CEC, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
            // Disable DDC Toggle IRQ 
#if((_D1_DDC_CHANNEL_SEL == _DDC2) || (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2))
            MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT3 | _BIT1);
#elif((_D1_DDC_CHANNEL_SEL == _DDC3) || (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3))
            MCU_HDMI_EDID_IRQ_FFE5 &= ~(_BIT3 | _BIT1);
#endif

#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            // Port 1 Z0 Disable
            ScalerSetBit(PB_B7_DP_CEC, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            if((ScalerGetByte(PB_B6_DP_Z0_CALIBRATION) & 0xF0) == 0x00)
            {
                // Disable HDCP Module
                ScalerSetBit(P2_C0_HDCP_CTRL, ~_BIT0, 0x00);
            } 
        }
    }    
}

//--------------------------------------------------
// Description  : GDI 2D Switch 
// Input Value  : D0/D1 Port Select
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhy2DSwitch(BYTE ucPortSelect)
{
    if(ucPortSelect == _D0_INPUT_PORT)
    {
        if(ScalerGetBit(PB_B5_DP_2D_SWITCH, _BIT2) != 0x00)
        {
            // Switch to Port 0
            ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT2, 0x00);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
            CLR_TMDS_PHY_SET();
            
            g_usTmdsClkCount = 0;
#endif
            DebugMessageDigital("7. wuanne test : 2D Switch to D0", 0);
        }
    }
    else
    {
        if(ScalerGetBit(PB_B5_DP_2D_SWITCH, _BIT2) != _BIT2)
        {
            // Switch to Port 1
            ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT2, _BIT2);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
            CLR_TMDS_PHY_SET();

            g_usTmdsClkCount = 0;
#endif
            DebugMessageDigital("7. wuanne test : 2D Switch to D1", 0);                
        }
    }
}

//--------------------------------------------------
// Description  : GDI Power Saving Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyPowerSavingProc(void)
{
    // Disable R/G/B RX_EN, Disable R/G/B/Clock CMU_EN
#if(_DP_DUAL_MODE_SUPPORT == _ON)
    ScalerSetByte(PB_B4_DP_PWR_CTL, 0x01); 
#else
    ScalerSetByte(PB_B4_DP_PWR_CTL, 0x08); 
#endif
}

//--------------------------------------------------
// Description  : GDI Power Off Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyPowerOffProc(void)
{
    // Disable RX_EN and CMU_EN
    ScalerSetByte(PB_B4_DP_PWR_CTL, 0x00);

    CLR_DIGITAL_PORT_SWITCH_TO_D0();
    CLR_DIGITAL_PORT_SWITCH_TO_D1();
    CLR_DIGITAL_PORT_SWITCH_TO_D2();
    CLR_DIGITAL_PORT_SWITCH_TO_D3();       
}

//--------------------------------------------------
// Description  : GDI Bandgap Power On/Off
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerGDIBandgap(bit bSelect)
{
    if(bSelect == _ON)
    {
        // GDI BG Power On 
        ScalerSetByte(PB_BB_DP_RESERVED_01, 0xC1);

        // Disable GDI from POR Bandgap
        ScalerSetBit(PB_A9_DP_FLD_05, ~_BIT7, 0x00);

        // Toggle K Offset Enable
        ScalerSetBit(PB_B2_DP_ADP_EQ, ~_BIT6, _BIT6);
        ScalerSetBit(PB_B2_DP_ADP_EQ, ~_BIT6, 0x00);
        ScalerSetBit(PB_B2_DP_ADP_EQ, ~_BIT6, _BIT6);      

        // RXBIST Clock from Analog
        ScalerSetBit(PB_E2_DIG02, ~_BIT0, 0x00);        
        
        // Bandgap External Resistor 6.2k Connect to VDD
        ScalerSetBit(PB_A0_DP_CDR_00, ~_BIT3, _BIT3);

        // loop_ok_in_regb, reg_loop_f_sel, vr_reg[0]
        ScalerSetBit(PB_A9_DP_FLD_05, ~(_BIT6 | _BIT5 | _BIT1), (_BIT5 | _BIT1));   

        // bpdgain = 1, Binary PD UP/DN pulse div3, ib90 = 90uA, ib25 = 25uA
        ScalerSetBit(PB_AA_DP_FLD_06, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT7 | _BIT6 | _BIT4 | _BIT2));

        // Rx Amplifier Input Common Mode Volatge = 0.95V, Z0 Reset Signal from RxEn, Disable vco_vc Control        
        ScalerSetBit(PB_AB_DP_FLD_07, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3));

        // Disable cdrcpop, Disable eqcpop, CDR CP CSOP Input From Cs, Disable cp_adj_en, adp_time
        ScalerSetBit(PB_AD_DP_FLD_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

        // CDR/EQ CP Vref --> 0x55V, Vcp-Vcn = 0.2V, clock edge align with data edge.
        ScalerSetBit(PB_AE_DP_RXMISC_01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT0), (_BIT3 | _BIT0));

        // Parameter Manual Set, Calib_time Setting, VCO Band Note Reset when FLD Detect Unlock
        ScalerSetBit(PB_AF_DP_RXMISC_02, ~(_BIT6 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT2 | _BIT1 | _BIT0));

        // Disable eq_autoselrange
        ScalerSetBit(PB_B0_DP_OOBS_RXAMP, ~_BIT0, 0x00);

        // EQ offset Calibration Select Auto Mode, Adaptive EQ Loop Filter C --> 10p, Charge Pump Current 5uA
        ScalerSetBit(PB_B2_DP_ADP_EQ, ~(_BIT5 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT2 | _BIT1));

        // tp1_det_manual, tp1_det_manual_sel
        ScalerSetBit(PB_FF_RXBIST_0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));  

        // Offset Calibration Current Range --> +/-45uA
        ScalerSetBit(PB_BA_DP_RESERVED_00, ~(_BIT3 | _BIT2), _BIT3);   

        if(ScalerGetBit(PB_B6_DP_Z0_CALIBRATION, _BIT7) == _BIT7)
        {
            // Enable D0 RGB Z0
            ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        }        

        if(ScalerGetBit(PB_B7_DP_CEC, _BIT7) == _BIT7)
        {
            // Enable D1 RGB Z0
            ScalerSetBit(PB_B7_DP_CEC, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        }            

        // Disable Aux Power Saving Mode
        ScalerSetBit_EXINT0(PB_F1_AUX_2, ~_BIT1, 0x00);

        // Switch Aux PHY to GDI BandGap
        ScalerSetBit_EXINT0(PB_F2_AUX_3, ~_BIT7, 0x00);

        // Aux Common Mode Voltage Bias Current Select to 1050uA@1.2V
        ScalerSetBit_EXINT0(PB_F3_AUX_4, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    }
    else
    {
        // Enable GDI from POR Bandgap 
        ScalerSetBit(PB_A9_DP_FLD_05, ~_BIT7, _BIT7);

        // Enable CDR PSM 
        ScalerSetBit(PB_BB_DP_RESERVED_01, ~_BIT2, _BIT2); 

        // Disable GDI Band Gap and 3.3V to 1.2V regulator
        ScalerSetBit(PB_BB_DP_RESERVED_01, ~(_BIT7 | _BIT0), 0x00); 

        // RXBIST Clock from Tx clock --> for more power consumption
        ScalerSetBit(PB_E2_DIG02, ~_BIT0, _BIT0);   

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

        // Disable D0 RGB Z0
        ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT6 | _BIT5 | _BIT4), 0x00);

        // Disable D1 RGB Z0
        ScalerSetBit(PB_B7_DP_CEC, ~(_BIT6 | _BIT5 | _BIT4), 0x00);        
#endif
    }
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
