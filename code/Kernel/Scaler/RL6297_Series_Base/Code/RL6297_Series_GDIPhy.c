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
// ID Code      : RL6297_Series_GDIPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6297_SERIES_GDIPHY__

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
            ScalerSetByte(PB_B4_POWER_0, 0x00);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);               

            // Disable Port 0,1 Z0
            ScalerSetBit(PB_B6_Z0_0, ~(_BIT4 | _BIT5 | _BIT6 | _BIT7), 0x00);
            ScalerSetBit(PB_B7_Z0_1, ~(_BIT4 | _BIT5 | _BIT6 | _BIT7), 0x00);			

            // Dual Mode Disable and Analog Select to HDMI
            ScalerSetBit(PB_AC_CDR_A, ~(_BIT3 | _BIT4), 0x00);			
        }

        // Digital PHY Lane Swap Setting
        ScalerSetByte(PB_D0_RXMISC_3, 0xE4);    

        // Digital PHY P/N Swap Setting
        ScalerSetBit(PB_D1_RXMISC_4, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);        

        // Switch to HDMI
        ScalerSetBit(PB_E0_DIG00, ~_BIT4, _BIT4);
        ScalerSetBit(PB_B4_POWER_0, ~_BIT3, _BIT3);
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
            if((ScalerGetByte(PB_B6_Z0_0) & 0xF0) == 0x00)
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

            if(ScalerGetBit(PB_B6_Z0_0, _BIT7) == 0x00)
            {
                // Port 0 Z0 Enable
                ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
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
            ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            if((ScalerGetByte(PB_B7_Z0_1) & 0xF0) == 0x00)
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
            if((ScalerGetByte(PB_B7_Z0_1) & 0xF0) == 0x00)
            {
                SET_TMDS_Z0_ASSERTED();
                CLR_TMDS_HPD_TRIGGER_EVENT();
                
                ScalerSetBit(P2_A9_TMDS_ACC1, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                g_bTmdsD1DdcDetected = _FALSE;    

#if(_D1_DDC_CHANNEL_SEL == _DDC2)
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;
#endif                
            }
#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

                if(ScalerGetBit(PB_B7_Z0_1, _BIT7) == 0x00)
                {
                    // Port 1 Z0 Enable
                    ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
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
            ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
           
            if((ScalerGetByte(PB_B6_Z0_0) & 0xF0) == 0x00)
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
    ScalerSetByte(PB_B4_POWER_0, 0x08); 

    // Disable Auto k-offset(foreground)
    ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);       
}

//--------------------------------------------------
// Description  : GDI Power Off Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyPowerOffProc(void)
{
    // Disable RX_EN and CMU_EN
    ScalerSetByte(PB_B4_POWER_0, 0x00);

    // Disable Auto k-offset(foreground)
    ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);   
        
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
        // GDI Bandgap External Resistor 6.2k connect to VDD
        ScalerSetBit(PB_A0_SIG_DET, ~_BIT3, _BIT3);  

        // GDI BG Power On       
        ScalerSetBit(PB_F4_AUX_5, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

        // Disable GDI from POR Bandgap
        ScalerSetBit(PB_F4_AUX_5, ~_BIT4, 0x00);

        // Disable CDR PSM
        ScalerSetBit(PB_BB_BANDGAP, ~_BIT2, 0x00);

        // Apply RLRS Code
        ScalerSetBit(PB_B8_Z0_2, ~_BIT7, _BIT7);     
        ScalerSetByte(PB_B7_Z0_1, (ScalerGetByte(PB_B7_Z0_1)) | ((((ScalerGetByte(PB_B8_Z0_2) >> 3) & 0x0C) | ((ScalerGetByte(PB_B8_Z0_2) >> 5) & 0x03)) & 0x0F));  

        // Disable Auto k-offset(foreground)
        ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);                         

        // [0] Enable Servo Loop Adaptation
        ScalerSetBit(PB_A4_CDR_2, ~_BIT0, _BIT0);

        // [1] z0_autok = 1 --> 50ohm auto calibration (Default value = 1) 
        ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT1, _BIT1);

        // [7:6] z0_tune = 2'b11 --> 50ohm calibration target is 50ohm (Default value = 2'b11)
        ScalerSetBit(PB_B5_DP_2D_SWITCH, ~(_BIT6 | _BIT7), (_BIT6 | _BIT7));  

        // [5] p_channel = 1 switch p channel 50ohm z0         
        // [4] n_channel = 1 switch n channel 50ohm z0 
        ScalerSetBit(PB_B3_SINGLE_END, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));  

        // [6] Loop ok = 0
        // [5] reg_loop_f_sel = 1
        // [1] Enable TP1 Input(Valid Only DP Mode)
        ScalerSetBit(PB_A9_CDR_7, ~(_BIT6 | _BIT5 | _BIT1), (_BIT5 | _BIT1));

        // [5] use dp_rate_in(Valid Only DP Mode)
        ScalerSetBit(PB_AC_CDR_A, ~_BIT5, _BIT5);
        
        // [6] Loop_Manual = 1
        ScalerSetBit(PB_AF_RXMISC_2, ~_BIT6, _BIT6);    
        
        // tp1_det_manual, tp1_det_manual_sel
        ScalerSetBit(PB_FF_RXBIST_0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6)); 

        if(ScalerGetBit(PB_B6_Z0_0, _BIT7) == _BIT7)
        {
            // Enable D0 RGB Z0
            ScalerSetBit(PB_B6_Z0_0, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        }

        if(ScalerGetBit(PB_B7_Z0_1, _BIT7) == _BIT7)
        {
            // Enable D1 RGB Z0
            ScalerSetBit(PB_B7_Z0_1, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        }           

        // Disable Aux Power Saving Mode
        ScalerSetBit_EXINT0(PB_F1_AUX_2, ~_BIT1, 0x00);

        // Switch Aux PHY to GDI BandGap
        ScalerSetBit_EXINT0(PB_F2_AUX_3, ~_BIT7, 0x00);

        // Aux comm current select max
        ScalerSetBit_EXINT0(PB_F3_AUX_4, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));        
    }
    else
    {
        // Enable GDI from POR Bandgap 
        ScalerSetBit(PB_F4_AUX_5, ~_BIT4,_BIT4);

        // Enable CDR PSM
        ScalerSetBit(PB_BB_BANDGAP, ~_BIT2, _BIT2);

        // Disable GDI Band Gap and 3.3V to 1.2V regulator
        ScalerSetBit(PB_F4_AUX_5, ~_BIT3 , 0x00);       

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

        // Disable D0 RGB Z0
        ScalerSetBit(PB_B6_Z0_0, ~(_BIT6 | _BIT5 | _BIT4), 0x00);            

        // Disable D1 RGB Z0
        ScalerSetBit(PB_B7_Z0_1, ~(_BIT6 | _BIT5 | _BIT4), 0x00);  
#endif
    }
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
