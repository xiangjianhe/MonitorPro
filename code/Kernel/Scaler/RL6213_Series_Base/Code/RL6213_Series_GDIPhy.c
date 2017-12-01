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
// ID Code      : RL6213_Series_GDIPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6213_SERIES_GDIPHY__

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
        if((bit)(ScalerGetBit(PB_E0_DIG00, _BIT4)) == _FALSE)
        {
            // Disable Rx_En and CMU_En
            ScalerSetByte(PB_B4_DP_PWR_CTL, 0x00);

            // Disable Port 0,1 Z0
            ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT4 | _BIT5 | _BIT6 | _BIT7), 0x00);
            
            ScalerSetBit(PB_AC_DP_FLD_08, ~(_BIT0 | _BIT1 | _BIT2 | _BIT3), 0x00);            

            // Dual Mode Disable and Analog Select to HDMI
            ScalerSetBit(PB_AC_DP_FLD_08, ~(_BIT3 | _BIT4), 0x00);            
        }

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
                
                ScalerSetBit(P2_AA_TMDS_ABC, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));
                ScalerSetBit(P2_AA_TMDS_ABC, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
                ScalerSetBit(P2_AA_TMDS_ABC, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

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

            if((ScalerGetByte(PB_AC_DP_FLD_08) & (_BIT0 | _BIT1 | _BIT2 | _BIT3)) == 0x00)
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
            if((ScalerGetByte(PB_AC_DP_FLD_08) & (_BIT0 | _BIT1 | _BIT2 | _BIT3)) == 0x00)
            {
                SET_TMDS_Z0_ASSERTED();
                CLR_TMDS_HPD_TRIGGER_EVENT();
                
                ScalerSetBit(P2_AA_TMDS_ABC, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));
                ScalerSetBit(P2_AA_TMDS_ABC, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
                ScalerSetBit(P2_AA_TMDS_ABC, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

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

            if(ScalerGetBit(PB_AC_DP_FLD_08, _BIT3) == 0x00)
            {
                // Port 1 Z0 Enable
                ScalerSetBit(PB_AC_DP_FLD_08, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
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
            ScalerSetBit(PB_AC_DP_FLD_08, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

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

        // Disable CDR PSM
        ScalerSetBit(PB_AC_DP_FLD_08, ~_BIT4, 0x00);

        // Toggle K Offset Enable
        ScalerSetBit(PB_B2_DP_ADP_EQ, ~_BIT6, _BIT6);
        ScalerSetBit(PB_B2_DP_ADP_EQ, ~_BIT6, 0x00);
        ScalerSetBit(PB_B2_DP_ADP_EQ, ~_BIT6, _BIT6);   

        if(ScalerGetBit(PB_B6_DP_Z0_CALIBRATION, _BIT7) == _BIT7)
        {
            // Enable D0 RGB Z0
            ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        }        

        if(ScalerGetBit(PB_AC_DP_FLD_08, _BIT3) == _BIT3)
        {
            // Enable D1 RGB Z0
            ScalerSetBit(PB_AC_DP_FLD_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
        }            
    }
    else
    {
        // Enable GDI from POR Bandgap 
        ScalerSetBit(PB_A9_DP_FLD_05, ~_BIT7, _BIT7);

        // Enable CDR PSM
        ScalerSetBit(PB_AC_DP_FLD_08, ~_BIT4, _BIT4);

        // Disable GDI Band Gap and 3.3V to 1.2V regulator
        ScalerSetBit(PB_BB_DP_RESERVED_01, ~(_BIT7 | _BIT0), 0x00); 

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

        // Disable D0 RGB Z0
        ScalerSetBit(PB_B6_DP_Z0_CALIBRATION, ~(_BIT6 | _BIT5 | _BIT4), 0x00);

        // Disable D1 RGB Z0
        ScalerSetBit(PB_AC_DP_FLD_08, ~(_BIT2 | _BIT1 | _BIT0), 0x00);        
#endif
    }
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
