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
// ID Code      : RL6336_Series_GDIPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6336_SERIES_GDIPHY__

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
        // [3] rx_en[3] = 1 --> Enable Power Control for Clock Lane 
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
        return;
    }

    if(bSelect == _ON)
    {
        
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
        if((ScalerGetByte(PB_B7_Z0_2) & 0xF0) == 0x00)
        {
            SET_TMDS_Z0_ASSERTED();
            CLR_TMDS_HPD_TRIGGER_EVENT();

            // Clear AKSV, Ri, BKSV Flag
            ScalerSetBit(P2_A9_TMDS_ACC1, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            g_bTmdsD1DdcDetected = _FALSE;    

            // Enable DDC Toggle IRQ
            MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
            MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
        }
#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

        // Port 1 Z0 Enable
        ScalerSetBit(PB_B7_Z0_2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
    }
    else
    {
        
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
        // Disable DDC Toggle IRQ 
        MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT3 | _BIT1);

#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

        // Port 1 Z0 Disable
        ScalerSetBit(PB_B7_Z0_2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

        // Disable HDCP Module
        ScalerSetBit(P2_C0_HDCP_CTRL, ~_BIT0, 0x00);      
    }
}

//--------------------------------------------------
// Description  : GDI 2D Switch 
// Input Value  : D0/D1 Port Select
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhy2DSwitch(BYTE ucPortSelect)
{
    ucPortSelect = ucPortSelect;
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
    ScalerSetBit(PB_B2_EQ_2, ~(_BIT6 | _BIT5), 0x00); 
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
    ScalerSetBit(PB_B2_EQ_2, ~(_BIT6 | _BIT5), 0x00); 

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
        // [3] bg_current_en = 1 --> Enable GDI Bandgap Current 
        ScalerSetBit(PB_BB_BANDGAP, ~_BIT3, _BIT3);  

        // [7:5] sel_ldo_vref[2:0] = 3'b100 --> CMU's LDO Output Voltage = 1.8V
        // [4] pow_cmu_ldo = 1 --> Enable CMU's LDO
        ScalerSetBit(PB_A0_CMU_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT4));  

        // [4] psm = 0 --> Disable PSM Mode
        ScalerSetBit(PB_BB_BANDGAP, ~_BIT4, 0x00);

        // [7] dfe_re_en = 1 --> Write dfe_rl and dfe_rs from dfe_rc_code
        ScalerSetBit(PB_B8_Z0_3, ~_BIT7, _BIT7);
        ScalerSetByte(PB_B7_Z0_2, ScalerGetByte(PB_B7_Z0_2) | ((((ScalerGetByte(PB_B8_Z0_3) >> 3) & 0x0C) | ((ScalerGetByte(PB_B8_Z0_3) >> 5) & 0x03)) & 0x0F));

        // [3] en_freeze_PLL = 0 --> Disable PFD
        ScalerSetBit(PB_AB_CDR_3, ~_BIT3, 0x00);

        // [3] enhance_ckbufbias = 1 --> Clock Lane Input Buffer Bias Current * 1.5
        ScalerSetBit(PB_A5_CMU_5, ~_BIT3, _BIT3); 

        // [3:0] Z0_adjr = 6 
        ScalerSetBit(PB_B6_Z0_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));

        if(ScalerGetBit(PB_B7_Z0_2, _BIT7) == _BIT7)
        {
            // Enable D1 RGB Z0
            ScalerSetBit(PB_B7_Z0_2, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        }                   
    }
    else
    {
        // [3] enhance_ckbufbias = 0 --> Clock Lane Input Buffer Bias Current *1
        ScalerSetBit(PB_A5_CMU_5, ~_BIT3, 0x00);    

        // [4] psm = 1 --> CDR in PSM Mode
        ScalerSetBit(PB_BB_BANDGAP, ~_BIT4, _BIT4);

        // [3] bg_current_en = 0 --> Disable GDI Bandgap Current  
        ScalerSetBit(PB_BB_BANDGAP, ~_BIT3, 0x00);     

        // [4] pow_cmu_ldo = 0 --> Disable CMU's LDO
        ScalerSetBit(PB_A0_CMU_0, ~_BIT4, 0x00);  

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

        // Disable D1 RGB Z0
        ScalerSetBit(PB_B7_Z0_2, ~(_BIT6 | _BIT5 | _BIT4), 0x00);          
#endif
    }
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
