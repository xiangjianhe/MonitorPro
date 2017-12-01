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
// ID Code      : RL6229_Series_ADC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6229_SERIES_ADC__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
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
void ScalerADCBandgap(bit bSelect);

#if(_VGA_SUPPORT == _ON)
void ScalerADCOutputClkSetting(void);
void ScalerADCPowerSetting(void);
void ScalerADCBiasCurrentSetting(void);
void ScalerADCPGAAdjust(BYTE ucAdcPGA);
void ScalerADCGainAdjust(BYTE *pGainMSB, BYTE *pGainLSB);
void ScalerADCOffsetAdjust(BYTE *pOffsetMSB, BYTE *pOffsetLSB);
void ScalerADCClampMode(EnumColorSpace enumColorFormat);

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
bit ScalerADCGetClampToTopStatus(void);
void ScalerADCSetClampToTopStatus(bit bEn);
#endif

void ScalerADCBandWidthSetting(DWORD ulAdcClock);
void ScalerADCDCRestoreEn(bit bEn);
void ScalerADCSOGClampEn(bit bEn);
void ScalerADCPGAbyPassSetting(void);
void ScalerADCSchmittTriggerSetting(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Power On/Off ADC Bandgap.
// Input Value  : On or Off
// Output Value : None
//--------------------------------------------------
void ScalerADCBandgap(bit bSelect)
{
    if(bSelect == _ON)
    {
        // ADC Bandgap On
        ScalerSetBit(P0_C6_ADC_POWER, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

        // Bit2: SOG0 Bias Current from ADC
        // Bit0: Bias Current of SOG normal
        ScalerSetBit(P0_D5_ADC_CLAMP_CTRL1, ~(_BIT2 | _BIT0), _BIT2);

        // ADC Regulator Output Not Short to Ground
        ScalerSetBit(P0_DA_TEST_PTN_HPOS_L, ~_BIT4, 0x00);
    }
    else
    {
        // ADC Regulator Output Not Short to Ground
        ScalerSetBit(P0_DA_TEST_PTN_HPOS_L, ~_BIT4, 0x00);

        // Bit2: SOG0 Bias Current from POR
        // Bit0: Bias Current of SOG standby
        ScalerSetBit(P0_D5_ADC_CLAMP_CTRL1, ~(_BIT2 | _BIT0), _BIT0);

        // ADC Bandgap Off
        ScalerSetBit(P0_C6_ADC_POWER, ~(_BIT4 | _BIT3), 0x00);
    }
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Intial adc output clock setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerADCOutputClkSetting(void)
{
    // Clock polarity select negative
    ScalerSetBit(P0_BB_ADC_2X_SAMPLE, ~(_BIT5 | _BIT4 | _BIT1 | _BIT0), 0x00);

    // Output clock divider Polarity Normal, Duty Staiblizer is 50%
    ScalerSetByte(P0_BC_ADC_CLOCK, 0x01);
}

//--------------------------------------------------
// Description  : ADC Power Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerADCPowerSetting(void)
{
    // ADC bandgap/BIAS control
    ScalerSetBit(P0_DA_TEST_PTN_HPOS_L, ~_BIT0, 0x00);

    //ADC Clock Power On, SOG_ADC0 Power On, R/G/B ADC Power On
    ScalerSetBit(P0_C6_ADC_POWER, ~(_BIT6 | _BIT5 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | _BIT2 | _BIT1 | _BIT0));
}

//--------------------------------------------------
// Description  : Intial adc Bias current setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerADCBiasCurrentSetting(void)
{
    // Set VCM voltage 700mV
    ScalerSetBit(P0_C8_ADC_I_BAIS1, ~(_BIT5 | _BIT4), _BIT4);

    // Set ADC eLDO 1.3V
    ScalerSetBit(P0_C9_ADC_I_BAIS2, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // Set SF Bias current relation control register
    ScalerSetBit(P0_DA_TEST_PTN_HPOS_L, ~_BIT5, 0x00);
    ScalerSetBit(P0_CA_ADC_I_BAIS3, ~(_BIT7 | _BIT6), _BIT6);

    // Disable SF bandwidth
    ScalerSetBit(P0_CB_ADC_I_BAIS4, ~_BIT3, 0x00);

    // Set ib_vb 40uA
    ScalerSetBit(P0_DB_TEST_PTN_RD, ~_BIT3, _BIT3);

    // Vrefp/Vrefn bias current doubled
    ScalerSetBit(P0_DB_TEST_PTN_RD, ~_BIT2, _BIT2);
}

//--------------------------------------------------
// Description  : Adjust ADC PGA
// Input Value  : PGA
// Output Value : None
//--------------------------------------------------
void ScalerADCPGAAdjust(BYTE ucAdcPGA)
{
    // Set ADC PGA
    ScalerSetBit(P0_CE_ADC_CTL_RGB, 0x0F, (ucAdcPGA << 4) & 0xF0);
}

//--------------------------------------------------
// Description  : Adjust ADC gain
// Input Value  : pGainMSB ---> R/G/B Gain coefficient MSB
//                pGainLSB ---> R/G/B Gain coefficient LSB
// Output Value : None
//--------------------------------------------------
void ScalerADCGainAdjust(BYTE *pGainMSB, BYTE *pGainLSB)
{
    // Set ADC Gain High Byte Factor
    ScalerSetByte(P0_C0_RED_GAIN_MSG, pGainMSB[0]);
    ScalerSetByte(P0_C1_GRN_GAIN_MSG, pGainMSB[1]);
    ScalerSetByte(P0_C2_BLU_GAIN_MSG, pGainMSB[2]);

    // Set ADC Gain Low Byte Factor
    ScalerSetByte(P0_BE_ADC_RGB_GAIN_LSB, ((pGainLSB[0] & 0x03) << 4) | ((pGainLSB[1] & 0x03) << 2) | (pGainLSB[2] & 0x03));
}

//--------------------------------------------------
// Description  : Adjust ADC offset
// Input Value  : pGainMSB ---> R/G/B Offset coefficient MSB
//                pGainLSB ---> R/G/B Offset coefficient LSB
// Output Value : None
//--------------------------------------------------
void ScalerADCOffsetAdjust(BYTE *pOffsetMSB, BYTE *pOffsetLSB)
{
    // Set ADC Gain High Byte Factor
    ScalerSetByte(P0_C3_RED_OFFSET_MSG, pOffsetMSB[0]);
    ScalerSetByte(P0_C4_GRN_OFFSET_MSG, pOffsetMSB[1]);
    ScalerSetByte(P0_C5_BLU_OFFSET_MSG, pOffsetMSB[2]);

    // Set ADC Offset Low Byte Factor
    ScalerSetByte(P0_BF_ADC_RGB_OFFSET_LSB, ((pOffsetLSB[0] & 0x03) << 4) | ((pOffsetLSB[1] & 0x03) << 2) | (pOffsetLSB[2] & 0x03));
}

//--------------------------------------------------
// Description  : ADC color format setting
// Input Value  : ucColorFormat ---> SOY or VGA sync type format
// Output Value : None
//--------------------------------------------------
void ScalerADCClampMode(EnumColorSpace enumColorFormat)
{
#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
    if(ScalerADCGetClampToTopStatus() == _TRUE)
    {
        return;
    }
#endif

    if(enumColorFormat == _COLOR_SPACE_YPBPR)
    {
        // Red Channel Set Ypbpr Clamp Mode
        ScalerSetBit(P0_CF_ADC_CTL_RED, ~_BIT7, _BIT7);

        // Green Channel Set RGB Clamp Mode
        ScalerSetBit(P0_D0_ADC_CTL_GRN, ~_BIT7, 0x00);

        // Blue Channel Set Ypbpr Clamp Mode
        ScalerSetBit(P0_D1_ADC_CTL_BLU, ~_BIT7, _BIT7);
    }
    else // RGB format
    {
        // Red Channel Set RGB Clamp Mode
        ScalerSetBit(P0_CF_ADC_CTL_RED, ~_BIT7, 0x00);

        // Green Channel Set RGB Clamp Mode
        ScalerSetBit(P0_D0_ADC_CTL_GRN, ~_BIT7, 0x00);

        // Blue Channel Set RGB Clamp Mode
        ScalerSetBit(P0_D1_ADC_CTL_BLU, ~_BIT7, 0x00);
    }
}

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get clamp-to-top status
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerADCGetClampToTopStatus(void)
{
    return (ScalerGetBit(P0_D6_ADC_CLAMP_CTRL2, (_BIT2 | _BIT1 | _BIT0)) != 0x00);
}

//--------------------------------------------------
// Description  : Set clamp-to-top status
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerADCSetClampToTopStatus(bit bEn)
{
    if(bEn == _TRUE)
    {
        // Enable clamp-to-top
        ScalerSetBit(P0_D6_ADC_CLAMP_CTRL2, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

        // Enable YPbPr clamp
        ScalerSetBit(P0_CF_ADC_CTL_RED, ~_BIT7, _BIT7);
        ScalerSetBit(P0_D0_ADC_CTL_GRN, ~_BIT7, _BIT7);
        ScalerSetBit(P0_D1_ADC_CTL_BLU, ~_BIT7, _BIT7);
    }
    else
    {
        // Disable clamp-to-top
        ScalerSetBit(P0_D6_ADC_CLAMP_CTRL2, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        // Restore to RGB/YPbPr clamp, according to D-domain YUV2RGB block & I/D-domain RGB2YUB blocks
        if((ScalerGetBit(P14_A1_SR_YCC2RGB_CTRL, _BIT0) == ScalerGetBit(CM_9C_YUV2RGB_CTRL, _BIT0)) ||
           (ScalerGetBit(P14_A1_SR_YCC2RGB_CTRL, _BIT0) == (ScalerGetBit(P14_A0_SR_RGB2YCC_CTRL, _BIT3) >> 3)))
        {
            pData[0] = 0; // RGB
        }
        else
        {
            pData[0] = _BIT7; // YPbPr
        }

        ScalerSetBit(P0_CF_ADC_CTL_RED, ~_BIT7, pData[0]);
        ScalerSetBit(P0_D0_ADC_CTL_GRN, ~_BIT7, 0x00);
        ScalerSetBit(P0_D1_ADC_CTL_BLU, ~_BIT7, pData[0]);
    }
}
#endif

//--------------------------------------------------
// Description  : ADC bandwidth and bias current setting
// Input Value  : ulAdcClock ---> ADC Clock frequency
// Output Value : None
//--------------------------------------------------
void ScalerADCBandWidthSetting(DWORD ulAdcClock)
{
#if(_VGA_ADC_SF_SHA_LPF_UNDER_25MHZ_SUPPORT == _ON)

    if(ulAdcClock < 26)
    {
        // Set SF LPF Bandwidth to 158MHz
        ScalerSetBit(P0_D6_ADC_CLAMP_CTRL2, ~_BIT5, 0x00);
        ScalerSetBit(P0_D3_ADC_DCR_CTRL, ~(_BIT2 | _BIT1), _BIT1);

        // Enable SF bandwidth
        ScalerSetBit(P0_CB_ADC_I_BAIS4, ~_BIT3, _BIT3);

        // Set SHA LPF Reset switches BW parameter to 150MHz
        ScalerSetBit(P0_CE_ADC_CTL_RGB, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
    }
    else
    {
        // Disable SF bandwidth
        ScalerSetBit(P0_CB_ADC_I_BAIS4, ~_BIT3, 0x00);

        // Set SHA LPF Reset switches BW parameter to maximum
        ScalerSetBit(P0_CE_ADC_CTL_RGB, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
    }
#else
    // Set SHA LPF Reset switches BW parameter to maximum
    ScalerSetBit(P0_CE_ADC_CTL_RGB, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
#endif

    // Set SHA LPF Sampling switches BW parameter according differential pixel clock to reduce high frequency noise
    if(ulAdcClock < 75)
    {
        ScalerSetBit(P0_DD_TEST_PTN_BD, ~(_BIT7 | _BIT6), 0x00);
    }
    else if(ulAdcClock < 125)
    {
        ScalerSetBit(P0_DD_TEST_PTN_BD, ~(_BIT7 | _BIT6), _BIT7);
    }
    else
    {
        ScalerSetBit(P0_DD_TEST_PTN_BD, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    }

    // Set Bias current according differential pixel clock.
    if(ulAdcClock < 150)
    {
        ScalerSetByte(P0_CA_ADC_I_BAIS3, 0x5C);
    }
    else
    {
        ScalerSetByte(P0_CA_ADC_I_BAIS3, 0x5E);
    }
}

//--------------------------------------------------
// Description  : DC restore
// Input Value  : bEn---> Disable or enable dcrestore function
// Output Value : None
//--------------------------------------------------
void ScalerADCDCRestoreEn(bit bEn)
{
    if(bEn)
    {
        /*
        // Disable First DC Restore circut
        ScalerSetBit(P0_D3_ADC_DCR_CTRL, ~_BIT4, 0x00);

        // Enable SOG Second DC Restore circut
        ScalerSetBit(P0_DE_TEST_PATTERN_CTRL, ~_BIT2, _BIT2);
        */

        // Enable First DC Restore circut
        ScalerSetBit(P0_D3_ADC_DCR_CTRL, ~_BIT4, _BIT4);
    }
    else
    {
        // Disable First DC Restore circut
        ScalerSetBit(P0_D3_ADC_DCR_CTRL, ~_BIT4, 0x00);

		/*
        // Disable SOG Second DC Restore circut
        ScalerSetBit(P0_DE_TEST_PATTERN_CTRL, ~_BIT2, 0x00);
		*/
    }
}

//--------------------------------------------------
// Description  : SOG Clamp Control
// Input Value  : bEn---> Disable or enable SOG clamp
// Output Value : None
//--------------------------------------------------
void ScalerADCSOGClampEn(bit bEn)
{
    if(bEn)
    {
        // Enable SOG Clamp
        ScalerSetBit(P0_D4_ADC_CLAMP_CTRL0, ~_BIT4, _BIT4);

        // 0x19 * 10 = 250mV = [(100 + X) + (400 - X)] / 2;
        // 250mV is fit to Both DC Restore and Clamp Mode.
        if(ScalerGetBit(P0_D7_ADC_SOG_DAC_SOY_CONTROL, 0x3F) < 0x19)
        {
            pData[0] = 0x19 - ScalerGetBit(P0_D7_ADC_SOG_DAC_SOY_CONTROL, 0x3F);

            // Chanage SOG DAC Setting to 250mV smoothly
            while(pData[0]--)
            {
                ScalerSetBit(P0_D7_ADC_SOG_DAC_SOY_CONTROL, ~(0x3F), (0x19 - pData[0]));

                // Delay 1ms for clamp mode rising.
                ScalerTimerDelayXms(1);
            }
        }
    }
    else
    {
        // Disable SOG Clamp
        ScalerSetBit(P0_D4_ADC_CLAMP_CTRL0, ~_BIT4, 0x00);
    }
}

//--------------------------------------------------
// Description  : PGA by pass setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerADCPGAbyPassSetting(void)
{
    // 6229 have no PGA by pass option
}

//--------------------------------------------------
// Description  : ADC Schmitt Trigger Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerADCSchmittTriggerSetting(void)
{
    // Enable Schmitt Trigger and Select New Mode
    ScalerSetBit(P0_F4_HS_SCHMITT_TRIGGER_CTRL, ~(_BIT7 | _BIT5), (_BIT7 | _BIT5));

    // HS Schimmit Tigger Polarity Select
    ScalerSetBit(P0_F4_HS_SCHMITT_TRIGGER_CTRL, ~_BIT6, (_A0_HS_SCHMITT_TRIGGER_POLARITY_SEL << 6));

    // HS Schimmit Tigger Vth Fine tune
    ScalerSetBit(P0_F4_HS_SCHMITT_TRIGGER_CTRL, ~_BIT4, (_A0_HS_SCHMITT_TRIGGER_VTH_FINE_TUNE << 4));

    // HS Schimmit Trigger Positive Vth Setting
    ScalerSetBit(P0_F4_HS_SCHMITT_TRIGGER_CTRL, ~(_BIT3 | _BIT2), (_A0_HS_SCHMITT_TRIGGER_POSITIVE_VTH << 2));

    // HS Schimmit Trigger Negative Vth Setting
    ScalerSetBit(P0_F4_HS_SCHMITT_TRIGGER_CTRL, ~(_BIT1 | _BIT0), (_A0_HS_SCHMITT_TRIGGER_NEGATIVE_VTH));
}

#endif // End of #if(_VGA_SUPPORT == _ON)
