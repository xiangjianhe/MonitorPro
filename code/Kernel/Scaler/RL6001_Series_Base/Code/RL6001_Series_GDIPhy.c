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
// ID Code      : RL6001_Series_GDIPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6001_SERIES_GDIPHY__

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
            
            ScalerSetBit(PB_D0_RX_BIST_00, ~(_BIT0 | _BIT1 | _BIT2 | _BIT3), 0x00);            

            // Dual Mode Disable and Analog Select to HDMI
            ScalerSetBit(PB_AC_DP_FLD_08, ~(_BIT3 | _BIT4), 0x00);            
        }

        // Digital PHY Lane Swap Setting
        ScalerSetByte(PB_CD_DP_RESERVED_07, 0xE4);

        // Digital PHY P/N Swap Setting
        ScalerSetBit(PB_CC_DP_RESERVED_06, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        
        // Switch to HDMI
        ScalerSetBit(PB_E0_DIG00, ~_BIT4, _BIT4);
        ScalerSetBit(PB_B4_DP_PWR_CTL, ~_BIT3, _BIT3);
    }
#endif
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

            if((ScalerGetByte(PB_D0_RX_BIST_00) & (_BIT0 | _BIT1 | _BIT2 | _BIT3)) == 0x00)
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
            if((ScalerGetByte(PB_D0_RX_BIST_00) & (_BIT0 | _BIT1 | _BIT2 | _BIT3)) == 0x00)
            {
                SET_TMDS_Z0_ASSERTED();
                CLR_TMDS_HPD_TRIGGER_EVENT();
                
                ScalerSetBit(P2_A9_TMDS_ACC1, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                g_bTmdsD1DdcDetected = _FALSE;    

                // Enable DDC Toggle IRQ
#if(_D1_DDC_CHANNEL_SEL == _DDC2)
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;
#endif                
            }

#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            if(ScalerGetBit(PB_D0_RX_BIST_00, _BIT3) == 0x00)
            {
                // Port 1 Z0 Enable
                ScalerSetBit(PB_D0_RX_BIST_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
            }
        }
        else
        {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
            // Disable DDC Toggle IRQ 
#if(_D1_DDC_CHANNEL_SEL == _DDC2)
            MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT3 | _BIT1);
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
            MCU_HDMI_EDID_IRQ_FFE5 &= ~(_BIT3 | _BIT1);
#endif

#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            // Port 1 Z0 Disable
            ScalerSetBit(PB_D0_RX_BIST_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

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
    ScalerSetByte(PB_B4_DP_PWR_CTL, 0x08); 
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

        // [5:4] rxcom_sel --> Rx Amplifier Input Common Mode Voltage Select to 0.95V
        // [3] rstb_Z0 --> Reset 50ohm Calibration
        // [2] z0_maunual --> Z0 50ohm Calibration Reset by RXEN
        ScalerSetBit(PB_A4_DP_FLD_00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT4 | _BIT3));

        // [6] loop_ok_in_regb
        // [5] reg_loop_f_sel
        // [1] vr_reg[0] -->  Enable Tp1 Input
        ScalerSetBit(PB_A9_DP_FLD_05, ~(_BIT6 | _BIT5 | _BIT1), (_BIT5 | _BIT1));   

        // [7] cdrcpop_en
        // [5] sel_csop_in --> CDR CP CSOP Input From Cs 
        // [4] cp_adj_en --> Disable cp_adj_en
        // [2:0] adp_atime
        ScalerSetBit(PB_AD_DP_FLD_09, ~(_BIT7 | _BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
        
        // [7:6] cpvref_sel --> 0.55V
        // [5:4] eqvref_sel --> 0.55V  
        // [3] eqvc_selini --> Vcp-Vcn = 0.2V
        // [0]sel_sync --> clock edge align with data edge.
        ScalerSetBit(PB_AE_DP_RXMISC_01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT0), (_BIT3 | _BIT0));

        // [6] loop_maunual --> Parameter Manual Set 
        // [4] band_rst --> VCO Band Not Reset when FLD Detect Unlock
        // [2:0] calib_time --> Calib_time Setting, 
        ScalerSetBit(PB_AF_DP_RXMISC_02, ~(_BIT6 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT2 | _BIT1 | _BIT0));

        // [2] eqsc
        // [1:0] eqcp_sel
        ScalerSetBit(PB_B2_DP_ADP_EQ, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));

        // [3:2] offset_idiv --> Offset Calibration Current Range --> +/-45uA
        ScalerSetBit(PB_BA_DP_RESERVED_00, ~(_BIT3 | _BIT2), _BIT3);    

        // [7:6] vdc16_sel
        // [2] sel_vp
        // [1:0] adppeak_sel
        ScalerSetBit(PB_BF_DP_RESERVED_05, ~(_BIT7 | _BIT6 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT6 | _BIT2));

        // [7] tp1_det_manual 
        // [6] tp1_det_manual_sel
        ScalerSetBit(PB_D5_RX_BIST_05, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));   

        if(ScalerGetBit(PB_B6_DP_Z0_CALIBRATION, _BIT7) == _BIT7)
        {
            // Enable D0 RGB Z0
            ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        }        

        if(ScalerGetBit(PB_D0_RX_BIST_00, _BIT3) == _BIT3)
        {
            // Enable D1 RGB Z0
            ScalerSetBit(PB_D0_RX_BIST_00, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
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

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

        // Disable D0 RGB Z0
        ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT6 | _BIT5 | _BIT4), 0x00);

        // Disable D1 RGB Z0
        ScalerSetBit(PB_D0_RX_BIST_00, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
#endif
    }
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
