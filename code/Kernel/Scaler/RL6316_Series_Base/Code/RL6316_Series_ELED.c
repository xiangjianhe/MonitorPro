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
// ID Code      : RL6316_Series_ELED.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6316_SERIES_ELED__

#include "ScalerFunctionInclude.h"

#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
//--------------------------------------------------
// Definitions of ELED Booster State
//--------------------------------------------------
typedef enum
{
    _ELED_BOOSTING_STATE = 0x00,
    _ELED_STEADY_STATE,
}EnumLedBoosterStatus;
//--------------------------------------------------
// Definitions of ELED Protect Mode
//--------------------------------------------------
typedef enum
{
    _ELED_PROTECT_HW_MODE = 0x00,
    _ELED_PROTECT_FW_MODE,
}EnumLedProtectCondition;

//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerELEDInitial(void);
void ScalerELEDControl(bit bOn);
void ScalerELEDIntHandler_EXINT0(void);
void ScalerELEDBacklightAdjust(BYTE ucBacklight);
BYTE ScalerELEDGetBacklightPWM(void);
void ScalerELEDFeedbackParameter(void);
void ScalerELEDB3B4Parameter(void);
WORD ScalerELEDB5Parameter(DWORD ulTempMin);
WORD ScalerELEDB1B2Parameter(DWORD ulTempMin);
void ScalerELEDB6Parameter(WORD usVsense, WORD usParameterB1B2, WORD usParameterB5);
void ScalerELEDCurrentParameter(void);
void ScalerELEDDimmingClk(void);
void ScalerELEDOxpParameter(void);
void ScalerELEDSetOvp(EnumLedBoosterStatus enumBoosterStatus);
void ScalerELEDSetOcp(EnumLedBoosterStatus enumBoosterStatus);
void ScalerELEDSetOsp(void);
void ScalerELEDSetOtp(void);
void ScalerELEDSetLedShort(void);
void ScalerELEDProtectEn(void);
void ScalerELEDHwProtect(EnumLedProtectCondition enumProtectMode);
void ScalerELEDSetOvpEn(bit bOn);
void ScalerELEDSetOcpEn(bit bOn);
void ScalerELEDSetOspEn(bit bOn);
void ScalerELEDSetOtpEn(bit bOn);
void ScalerELEDSetLedShortEn(bit bOn);

#if(_PANEL_EMBEDDED_LED_DRIVER_OPEN_SUPPORT == _ON)
void ScalerELEDSetLedOpen(EnumLedProtectCondition enumProtectMode);
void ScalerELEDSetLedOpenEn(bit bOn);
#endif

void ScalerELEDBoosterVdetCompensation(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : LED Backlight Driver Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerELEDInitial(void)
{
    // LED Booster & LED Power off 
    ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // Set Analog Code Vref Clk for CKDD
    ScalerSetBit(P16_AA_LEDBC_ANALOG_RESERVED_3, ~(_BIT4 | _BIT3), 0x00);

    // Set Booster PWM Gated Signal 
    ScalerSetBit(P16_AA_LEDBC_ANALOG_RESERVED_3, ~_BIT5, 0x00);
    
    // Set LED Booster Parameter
    ScalerELEDFeedbackParameter();

    // Set LED OXP Parameter
    ScalerELEDOxpParameter();

    // Set LED OXP Protection on/off
    ScalerELEDProtectEn();

    // Soft Start Clock Div 256
    ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~_BIT0, 0x00);
    ScalerSetBit(P16_D6_LEDBC_PROTECT_CTRL_2, ~_BIT5, _BIT5);

    // Soft Start Enable
    ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT6, 0x00);


#if(_ELED_VFB_INTERNAL_RESISTOR == _ENABLE)

    // LED VFB Internal Resistor Enable 
    ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~_BIT1, _BIT1);

#else

    // LED VFB Internal Resistor Disable 
    ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~_BIT1, 0x00);
#endif


    // Enable Digital Dimming Vref Reference CKDD1   
    ScalerSetBit(P16_C7_LEDBC_ADVREF1, ~_BIT7, 0x00);

    // Fix Booster Glitch Enable   
    ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

    // Set LED_EN Select New Mode
    ScalerSetBit(P16_C4_LEDBC_ADVREF4, ~_BIT3, _BIT3);

    if(ScalerGetByte(CM_0F_ID_REG_02) >= 0x62)
    {
        // Set LED Vim Reference Voltage For Check Booster Ready or Not
        ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~_BIT4, 0x00);
        ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    }   

    // Set Dimming Minimum Current For Code0 Initial Value
#if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)
	ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~(_BIT6 | _BIT5 | _BIT4), 0x00);

#elif(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _ANALOG_DIMMING)

#if(_ELED_VREF_INITIAL_SHORT_RESISTOR == _VREF_SHORT_10_R)
    ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~(_BIT6 | _BIT5 | _BIT4), _BIT5);

#elif(_ELED_VREF_INITIAL_SHORT_RESISTOR == _VREF_SHORT_5_R)
    ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~(_BIT6 | _BIT5 | _BIT4), _BIT4);

#elif(_ELED_VREF_INITIAL_SHORT_RESISTOR == _VREF_SHORT_0_R)
    ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~(_BIT6 | _BIT5 | _BIT4), 0x00);

#endif // End of #if(_ELED_VREF_INITIAL_SHORT_RESISTOR == _VREF_SHORT_10R)

#endif // End of #if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)

    // Set Dimming Vref Current
#if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)
    ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~_BIT7, 0x00);
	ScalerSetBit(P16_C7_LEDBC_ADVREF1, ~(_BIT1 | _BIT0), _BIT1);

#elif(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _ANALOG_DIMMING)

#if(_ELED_VREF_INITIAL_CURRENT == _VREF_INITIAL_3_UA)
    ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~_BIT7, 0x00);
	ScalerSetBit(P16_C7_LEDBC_ADVREF1, ~(_BIT1 | _BIT0), _BIT1);

#elif(_ELED_VREF_INITIAL_CURRENT == _VREF_INITIAL_2P5_UA)
    ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~_BIT7, 0x00);
	ScalerSetBit(P16_C7_LEDBC_ADVREF1, ~(_BIT1 | _BIT0), _BIT0);

#elif(_ELED_VREF_INITIAL_CURRENT == _VREF_INITIAL_2_UA)
    ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~_BIT7, _BIT7);
	ScalerSetBit(P16_C7_LEDBC_ADVREF1, ~(_BIT1 | _BIT0), 0x00);

#endif // End of #if(_ELED_VREF_INITIAL_CURRENT == _VREF_INITIAL_3_UA)

#endif // End of #if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)

    
}

//--------------------------------------------------
// Description  : LED Backlight Control
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerELEDControl(bit bOn)
{
    if(bOn == _LIGHT_CONTROL_ON)
    {
        // Avoid to enable backlgiht double times
        if(ScalerGetBit(P16_A0_LEDBC_DRIVER_CTRL1, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6))
        {
            return;
        }
        
        // Set OVP Reference Voltage
        ScalerELEDSetOvp(_ELED_BOOSTING_STATE);

        // Set OCP Reference Voltage
        ScalerELEDSetOcp(_ELED_BOOSTING_STATE);
    
        // Set OVP En/Dn
        ScalerELEDSetOvpEn(_ON);

        // Set OCP En/Dn
        ScalerELEDSetOcpEn(_ON);
        
        // Set OSP En/Dn
        ScalerELEDSetOspEn(_ON);

        // Set OTP En/Dn
        ScalerELEDSetOtpEn(_OFF);

        // Set LED_SHORT En/Dn
        ScalerELEDSetLedShortEn(_OFF);

#if(_PANEL_EMBEDDED_LED_DRIVER_OPEN_SUPPORT == _ON)

        // Set LED_OPEN Verference Voltage
        ScalerELEDSetLedOpen(_ELED_BOOSTING_STATE);

        // Set LED_OPEN En/Dn
        ScalerELEDSetLedOpenEn(_ON);
#endif

        // Soft Start Enable
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT6, 0x00);
    
#if(_ANALOG_DIMMING == _ON)
        // Digital Dimming 100% for Analog Dimming Adjust
        ScalerSetByte(P16_E3_LEDBC_LED_PWM0_DUT, 0x00);
#endif    
        // Enable LED Power
        ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~_BIT7 , _BIT7);

        // At Least 40us For LED Power Ready
        for(pData[0] = 0; pData[0] <= 100; pData[0]++)
        {
            _nop_();
        }
        
        // Enable LED Driver
        ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~_BIT6, _BIT6);

		// At Least 1ms For Booster On De-Gltich
		ScalerTimerDelayXms(1);

        // Enable LED Booster En
        ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~_BIT5, _BIT5);
		
        // For OTP and LED_Short Detect
        ScalerTimerDelayXms(20);

        // Restore OVP/OCP Debounce time 10us
        ScalerELEDSetOvp(_ELED_STEADY_STATE);
        ScalerELEDSetOcp(_ELED_STEADY_STATE);
        
        // Enable OTP & LED_Short
        ScalerELEDSetOtpEn(_ON);
        ScalerELEDSetLedShortEn(_ON);

        // Booster Vdet Compensation
        ScalerELEDBoosterVdetCompensation();

#if(_PANEL_EMBEDDED_LED_DRIVER_OPEN_SUPPORT == _ON)

        // Set LED_OPEN Verference Voltage
        ScalerELEDSetLedOpen(_ELED_STEADY_STATE);
#endif

        if(ScalerGetByte(CM_0F_ID_REG_02) >= 0x62)
        {
            // Check Booster Finish or Not
            if(ScalerTimerPollingFlagProc(20, P16_AD_LEDBC_ANALOG_RESERVED_6, _BIT0, _TRUE) == _FALSE)
            {
               // Disable LED Booster En
               ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~_BIT5, 0x00);
            }
        }
    }
    else
    {
        // Avoid to disable backlgiht double times
        if(ScalerGetBit(P16_A0_LEDBC_DRIVER_CTRL1, (_BIT7 | _BIT6)) == 0x00)
        {
            return;
        }
        
        // Disable LED Booster En
        ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~_BIT5, 0x00);

		// At Least 10ms For Booster Off De-Gltich
		ScalerTimerDelayXms(10);
		 
        // Disable LED Boost Driver & LED Power
        ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~(_BIT7 | _BIT6), 0x00);
       
        // Set OVP En/Dn
        ScalerELEDSetOvpEn(_OFF);

        // Set OCP En/Dn
        ScalerELEDSetOcpEn(_OFF);
        
        // Set OSP En/Dn
        ScalerELEDSetOspEn(_OFF);

        // Set OTP En/Dn
        ScalerELEDSetOtpEn(_OFF);

        // Set LED_SHORT En/Dn
        ScalerELEDSetLedShortEn(_OFF);

#if(_PANEL_EMBEDDED_LED_DRIVER_OPEN_SUPPORT == _ON)

        // Set LED_OPEN En/Dn
        ScalerELEDSetLedOpenEn(_OFF);
#endif
    }
}

//--------------------------------------------------
// Description  : LED Backlight Control Interrupt Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerELEDIntHandler_EXINT0(void) using 1
{
    // Check OXP Flags
    if((((ScalerGetByte_EXINT0(P16_BE_LEDBC_OXP_REG_1) & 0xC0) != 0x00) || ((ScalerGetByte_EXINT0(P16_BF_LEDBC_OXP_REG_2) & 0xC0) != 0x00)) && (ScalerGetBit_EXINT0(P16_BB_LEDBC_OCP_IRQ, _BIT7) == _BIT7))
    {
        // Disable LED IRQ
        ScalerSetBit_EXINT0(P16_BB_LEDBC_OCP_IRQ, ~_BIT7, 0x00);

        // Disable LED Boost Driver & LED Power
        ScalerSetBit_EXINT0(P16_A0_LEDBC_DRIVER_CTRL1, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
    }
}

//--------------------------------------------------
// Description  : LED Backlight Adjust
// Input Value  : Adjust value for LED Backlight
// Output Value : None
//--------------------------------------------------
void ScalerELEDBacklightAdjust(BYTE ucBacklight)
{
    
#if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _ANALOG_DIMMING)

#if((_ELED_VFB_RESISTOR == _VFB_RESISTOR_10_OHM) || (_ELED_VFB_RESISTOR == _VFB_RESISTOR_3_OHM) || (_ELED_VFB_RESISTOR == _VFB_RESISTOR_4_OHM))

    pData[0] = ((((WORD)_PANEL_ELED_STRING_NUMBER * _PANEL_ELED_STRING_CURRENT * _ELED_VFB_RESISTOR) / _ELED_PCB_CURRENT_CHANNEL) * 10 - _ELED_LED_DRIVER_MIN_VOLTAGE) / (2 * _ELED_VREF_INITIAL_CURRENT);
    pData[1] = (BYTE)((WORD)(pData[0] * (ucBacklight + 1)) / 255);

#else

    pData[0] = ((((WORD)_PANEL_ELED_STRING_NUMBER * _PANEL_ELED_STRING_CURRENT * _ELED_VFB_RESISTOR) / _ELED_PCB_CURRENT_CHANNEL) * 10 - _ELED_LED_DRIVER_MIN_VOLTAGE) / _ELED_VREF_INITIAL_CURRENT;
    pData[1] = (BYTE)((WORD)(pData[0] * (ucBacklight + 1)) / 255);

#endif

    pData[3] = ScalerGetByte(P16_C8_LEDBC_ADVREF0);
    pData[4] = 4;

    // When Analog Dimming Code > 4 Fix Booster Glitch Disable
    if(abs(pData[1] - pData[3]) >= pData[4])
    {
        ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~(_BIT3 | _BIT2), 0x00);        
    }

    // When Analog Dimming Code > 4 For Adjust Max Code 4 Step By Step
    for(pData[5] = 0; pData[5] < (256 / pData[4]); pData[5] += 1)
    {
        if(abs(pData[1] - pData[3]) >= pData[4])
        {
            if(pData[1] >= pData[3])
            {
                pData[3] += pData[4];
            }
            else
            {
                pData[3] -= pData[4];
            }

            ScalerTimerDelayXms(4);
            ScalerSetByte(P16_C8_LEDBC_ADVREF0, pData[3]);
        }
        else
        {
            ScalerSetByte(P16_C8_LEDBC_ADVREF0, pData[1]);
            break;
        }
    }

    // When Backlight < 90% Disable Fix Glitch Fucntion
    if(pData[1] < (BYTE)(((WORD)pData[0] * 9) / 10))
    {
        // Fix Booster Glitch Disable
        ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~(_BIT3 | _BIT2), 0x00);        
    }
    else
    {
        // Fix Booster Glitch Enable
        ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));         
    }
 
#elif(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)
    
    ucBacklight = 255 - ucBacklight;
        
    if(ucBacklight >= (255 - _ELED_LED_DRIVER_MIN_PWM_DUTY))
    {
        ucBacklight = (255 - _ELED_LED_DRIVER_MIN_PWM_DUTY);
    }

    ScalerSetByte(P16_E3_LEDBC_LED_PWM0_DUT, ucBacklight); 
    
#endif

}

//--------------------------------------------------
// Description  : Get Current Backlight PWM Setting
// Input Value  : None
// Output Value : PWM Setting
//--------------------------------------------------
BYTE ScalerELEDGetBacklightPWM(void)
{
    
#if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _ANALOG_DIMMING)

    return (ScalerGetByte(P16_C8_LEDBC_ADVREF0));
    
#elif(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)

    return (255 - ScalerGetByte(P16_E3_LEDBC_LED_PWM0_DUT));

#endif

}

//------------------------------------------------------------------------
// Description  : LED Backlight Feedback Parameter
// Input Value  : None
// Output Value : None
//------------------------------------------------------------------------
void ScalerELEDFeedbackParameter(void)
{
    WORD usVsense = 0;
    WORD usVrampMin = 0;
    WORD usParameterB5 = 0;
    WORD usParameterB1B2 = 0;

    PDATA_DWORD(0) = (((DWORD)_PANEL_ELED_STRING_NUMBER * _PANEL_ELED_STRING_CURRENT * _PANEL_ELED_VOUT_TYPICAL) / _ELED_PCB_VI_VOLTAGE);
    PDATA_DWORD(1) = ((DWORD)_ELED_PCB_VI_VOLTAGE * (1000 - (((DWORD)_ELED_PCB_VI_VOLTAGE * 1000) / _PANEL_ELED_VOUT_TYPICAL))) * 1000 / ((DWORD)2 * _ELED_PCB_INDUCTOR_VALUE * _ELED_BOOSTER_PWM);

    usVsense = ((WORD)_ELED_PCB_RSENSE_VALUE * (PDATA_DWORD(0) + PDATA_DWORD(1))) / 100;
    usVrampMin = (_ELED_PCB_RSENSE_VALUE * (((DWORD)(_PANEL_ELED_VOUT_TYPICAL - _ELED_PCB_VI_VOLTAGE) * 1000000) / ((DWORD)2 * _ELED_PCB_INDUCTOR_VALUE * _ELED_BOOSTER_PWM))) / 100;

    //Set B5 Parameter
    PDATA_DWORD(2) = 500 * 100 / usVrampMin;
    usParameterB5 = ScalerELEDB5Parameter(PDATA_DWORD(2));

    //Set B1/B2 Parameter
    PDATA_DWORD(3) = ((DWORD)usVrampMin * usParameterB5);
    usParameterB1B2 = ScalerELEDB1B2Parameter(PDATA_DWORD(3));

    //Set B6 Parameter
    ScalerELEDB6Parameter(usVsense, usParameterB1B2, usParameterB5);

    //Set B3/B4 Parameter
    ScalerELEDB3B4Parameter();
    
    //Set LED Total Current
    ScalerELEDCurrentParameter();

    //Set Booster Clk & Dimming Clk Select just for initial value 240Hz
    ScalerELEDDimmingClk();
}

//--------------------------------------------------
// Description  : LED Backlight B3B4 Parameter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerELEDB3B4Parameter(void)
{
    ScalerSetByte(P16_B3_LEDBC_V2I_S_1, 0x11);
    ScalerSetByte(P16_B4_LEDBC_V2I_S_2, 0x02);
}

//--------------------------------------------------
// Description  : LED Backlight B5 Parameter
// Input Value  : Compensation Min value
// Output Value : None
//--------------------------------------------------
WORD ScalerELEDB5Parameter(DWORD ulTempMin)
{
    if(ulTempMin < 50)
    {
        PDATA_WORD(0) = 100;
        ScalerSetByte(P16_B5_LEDBC_V2I_R_1, 0x00);        
    }
    else if(ulTempMin < 100)
    {
        PDATA_WORD(0) = 100;
        ScalerSetByte(P16_B5_LEDBC_V2I_R_1, 0x00);  
    }
    else if(ulTempMin < 200)
    {
        PDATA_WORD(0) = 200;
        ScalerSetByte(P16_B5_LEDBC_V2I_R_1, 0x01);  
    }
    else if(ulTempMin < 400)
    {
        PDATA_WORD(0) = 400;
        ScalerSetByte(P16_B5_LEDBC_V2I_R_1, 0x03);  
    }
    else if(ulTempMin < 800)
    {
        PDATA_WORD(0) = 800;
        ScalerSetByte(P16_B5_LEDBC_V2I_R_1, 0x07);  
    }
    else if(ulTempMin < 1600)
    {
        PDATA_WORD(0) = 1600;
        ScalerSetByte(P16_B5_LEDBC_V2I_R_1, 0x0F); 
    }
    else if(ulTempMin < 3200)
    {
        PDATA_WORD(0) = 3200;
        ScalerSetByte(P16_B5_LEDBC_V2I_R_1, 0x1F); 
    }
    else
    {
        PDATA_WORD(0) = 3200;
        ScalerSetByte(P16_B5_LEDBC_V2I_R_1, 0x1F); 
    }

    return (PDATA_WORD(0) / 100);
}

//----------------------------------------------------------
// Description  : LED Backlight B1B2 Parameter
// Input Value  : Compensation Min and Max value, BoosterPWM
// Output Value : None
//----------------------------------------------------------
WORD ScalerELEDB1B2Parameter(DWORD ulTempMin)
{
    BYTE  ucCountb1 = 0;
    BYTE  ucCountb2 = 0;

    PDATA_DWORD(1) = (ulTempMin + (ulTempMin * 2)) / 2;
    
    for(ucCountb1 = 1; ucCountb1 <= 16; ucCountb1 <<= 1)
    {
        PDATA_DWORD(0) = ((DWORD)(2000 + (125 * 15)) * ucCountb1) / (((WORD)5 * _ELED_BOOSTER_PWM * 4) / 1000); 

        if(PDATA_DWORD(0) >= PDATA_DWORD(1))
        {
            ScalerSetByte(P16_B1_LEDBC_SAW_WAVE_1, (0xE0 + ucCountb1));
            break;
        }
    }

    for(ucCountb2 = 0; ucCountb2 <= 15; ucCountb2++)
    {
        PDATA_DWORD(0) = ((DWORD)(2000 + (125 * ucCountb2)) * ucCountb1) / (((WORD)5 * _ELED_BOOSTER_PWM * 4) / 1000);

        if(PDATA_DWORD(0) >= PDATA_DWORD(1))
        {
            ScalerSetByte(P16_B2_LEDBC_SAW_WAVE_2, ucCountb2);
            break;
        }
    }

    return PDATA_DWORD(0);
}

//----------------------------------------------------
// Description  : LED Backlight B6 Parameter
// Input Value  : Vsense, B1B2 Parameter, B5 Parameter
// Output Value : None
//----------------------------------------------------
void ScalerELEDB6Parameter(WORD usVsense, WORD usParameterB1B2, WORD usParameterB5)
{
    BYTE ucCountb6 = 0;
    
#if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)

    for(ucCountb6 = 0; ucCountb6 <= 7; ucCountb6++)
    {
        PDATA_WORD(0) = ((DWORD)usVsense * (ucCountb6 + 1)) + ((DWORD)usParameterB1B2 * (ucCountb6 + 1)) / usParameterB5;

        if(PDATA_WORD(0) > 300)
        {
            ScalerSetByte(P16_B6_LEDBC_V2I_R_2, 0x81 + (ucCountb6 * 16));
            break;
        }
    }

#elif(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _ANALOG_DIMMING)

    usVsense = usVsense;
    usParameterB1B2 = usParameterB1B2;
    usParameterB5 = usParameterB5;

    ScalerSetByte(P16_B6_LEDBC_V2I_R_2, 0xB1);

#endif

}

//-----------------------------------------------------
// Description  : LED Backlight Total Current
// Input Value  : String, StringCurrent, VFB, IcChannel
// Output Value : None
//-----------------------------------------------------
void ScalerELEDCurrentParameter(void)
{
    // Vfb Refrence Voltage 0.15V
    ScalerSetBit(P16_D5_LEDBC_PROTECT_CTRL_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
        
    // Vdet Refrence Voltage 0.6V
    ScalerSetBit(P16_D6_LEDBC_PROTECT_CTRL_2, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

#if((_ELED_VFB_RESISTOR == _VFB_RESISTOR_10_OHM) || (_ELED_VFB_RESISTOR == _VFB_RESISTOR_3_OHM) || (_ELED_VFB_RESISTOR == _VFB_RESISTOR_4_OHM))

    // Vref Voltage double
    ScalerSetBit(P16_C0_LEDBC_ADV_CTRL, ~_BIT5, _BIT5);

#if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)

    PDATA_WORD(0) = ((((WORD)_PANEL_ELED_STRING_NUMBER * _PANEL_ELED_STRING_CURRENT * _ELED_VFB_RESISTOR) / _ELED_PCB_CURRENT_CHANNEL) * 10 - 450) / (2 * 30);

#elif(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _ANALOG_DIMMING)

	PDATA_WORD(0) = ((((WORD)_PANEL_ELED_STRING_NUMBER * _PANEL_ELED_STRING_CURRENT * _ELED_VFB_RESISTOR) / _ELED_PCB_CURRENT_CHANNEL) * 10 - _ELED_LED_DRIVER_MIN_VOLTAGE) / (2 * _ELED_VREF_INITIAL_CURRENT);

#endif

#else // Else of #if((_ELED_VFB_RESISTOR == _VFB_RESISTOR_10_OHM) || (_ELED_VFB_RESISTOR == _VFB_RESISTOR_3_OHM) || (_ELED_VFB_RESISTOR == _VFB_RESISTOR_4_OHM))

    // Vref Voltage no double
    ScalerSetBit(P16_C0_LEDBC_ADV_CTRL, ~_BIT5, 0x00);

#if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)

	PDATA_WORD(0) = ((((WORD)_PANEL_ELED_STRING_NUMBER * _PANEL_ELED_STRING_CURRENT * _ELED_VFB_RESISTOR) / _ELED_PCB_CURRENT_CHANNEL) * 10 - 450) / 30;

#elif(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _ANALOG_DIMMING)

    PDATA_WORD(0) = ((((WORD)_PANEL_ELED_STRING_NUMBER * _PANEL_ELED_STRING_CURRENT * _ELED_VFB_RESISTOR) / _ELED_PCB_CURRENT_CHANNEL) * 10 - _ELED_LED_DRIVER_MIN_VOLTAGE) / _ELED_VREF_INITIAL_CURRENT;

#endif

#endif // End of #if((_ELED_VFB_RESISTOR == _VFB_RESISTOR_10_OHM) || ((_ELED_VFB_RESISTOR == _VFB_RESISTOR_4_OHM) && (_PANEL_ELED_STRING_NUMBER * _PANEL_ELED_STRING_CURRENT >= 300)))

    // Set Total Current
    ScalerSetBit(P16_C8_LEDBC_ADVREF0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), PDATA_WORD(0));
    
    ScalerRead(P24_A7_EFUSE_DATA1, 5, pData, _AUTOINC);

    if((pData[0] == 0x00) && (pData[1] == 0x00) && (pData[2] == 0x00) && (pData[3] == 0x00) && (pData[4] == 0x00))
    {

// E-fuse Resistor by each IC different
#if(_ELED_VFB_RESISTOR == _VFB_RESISTOR_3_OHM)

        ScalerSetByte(P24_A6_EFUSE_DATA0, 0x76);
        ScalerSetByte(P24_A7_EFUSE_DATA1, 0x76);
        ScalerSetByte(P24_A8_EFUSE_DATA2, 0x76);
        ScalerSetByte(P24_A9_EFUSE_DATA3, 0x76);
        ScalerSetByte(P24_AA_EFUSE_DATA4, 0x08);
        
#elif(_ELED_VFB_RESISTOR == _VFB_RESISTOR_4_OHM)

        ScalerSetByte(P24_A6_EFUSE_DATA0, 0x4E);
        ScalerSetByte(P24_A7_EFUSE_DATA1, 0x4E);
        ScalerSetByte(P24_A8_EFUSE_DATA2, 0x4E);
        ScalerSetByte(P24_A9_EFUSE_DATA3, 0x4E);
        ScalerSetByte(P24_AA_EFUSE_DATA4, 0x08);
        
#elif(_ELED_VFB_RESISTOR == _VFB_RESISTOR_5_OHM)

        ScalerSetByte(P24_A6_EFUSE_DATA0, 0x42);
        ScalerSetByte(P24_A7_EFUSE_DATA1, 0x42);
        ScalerSetByte(P24_A8_EFUSE_DATA2, 0x42);
        ScalerSetByte(P24_A9_EFUSE_DATA3, 0x42);
        ScalerSetByte(P24_AA_EFUSE_DATA4, 0x08);

#elif(_ELED_VFB_RESISTOR == _VFB_RESISTOR_10_OHM)

#endif
    }
    
    // Decide Turn on IC Channel 0~7-> low active
    ScalerSetByte(P16_B7_LEDBC_VMINSDISB, ~((_ELED_STRING0) | (_ELED_STRING1 << 1) | (_ELED_STRING2 << 2) | (_ELED_STRING3 << 3)));
}

//-----------------------------------------------------
// Description  : LED Booster and Dimming Clk
// Input Value  : Booster PWM
// Output Value : None
//-----------------------------------------------------
void ScalerELEDDimmingClk(void)
{
    // Set Booster PWM Frequency
    pData[0] = ((((DWORD)(_M2PLL_CLK_MHZ * 1000) / 20) + (_ELED_BOOSTER_PWM / 2)) / _ELED_BOOSTER_PWM) - 1;

    ScalerSetByte(P16_A2_LEDBC_DIG_DIV, pData[0]);
            
    // Set Dimming PWM Frequency
    ScalerSetByte(P16_DD_LEDBC_LED_PWM_CTRL, 0xA0);

#if(_ELED_DIMMING_PWM == _DIMMING_PWM_240)

    ScalerSetByte(P16_DE_LEDBC_LED_PWM_N_MSB, 0x18);
    ScalerSetByte(P16_DF_LEDBC_LED_PWM_N_LSB, 0xEE);

#elif(_ELED_DIMMING_PWM == _DIMMING_PWM_180)

    ScalerSetByte(P16_DE_LEDBC_LED_PWM_N_MSB, 0x28);
    ScalerSetByte(P16_DF_LEDBC_LED_PWM_N_LSB, 0x93);

#endif

    // Enable Dimming LED_PWM0~7 Output
    ScalerSetByte(P16_E2_LEDBC_LED_PWM_EN, ((_ELED_STRING0) | (_ELED_STRING1 << 1) | (_ELED_STRING2 << 2) | (_ELED_STRING3 << 3)));

    // LED PWM active low
    ScalerSetByte(P16_E1_LEDBC_LED_PWML, 0xFF);

    // Set PWM1~7 Initial Duty
	ScalerSetByte(P16_E4_LEDBC_LED_PWM1_DUT, 0x7F);
	ScalerSetByte(P16_E5_LEDBC_LED_PWM2_DUT, 0x7F);
	ScalerSetByte(P16_E6_LEDBC_LED_PWM3_DUT, 0x7F);
	ScalerSetByte(P16_E7_LEDBC_LED_PWM4_DUT, 0x7F);
	ScalerSetByte(P16_E8_LEDBC_LED_PWM5_DUT, 0x7F);
	ScalerSetByte(P16_E9_LEDBC_LED_PWM6_DUT, 0x7F);
	ScalerSetByte(P16_EA_LEDBC_LED_PWM7_DUT, 0x7F);
}

//----------------------------------------------------------
// Description  : LED Backlight Oxp Parameter
// Input Value  : VOUT, OVP_RATIO
// Output Value : None
//----------------------------------------------------------
void ScalerELEDOxpParameter(void)
{
    // Set OVP Reference Voltage
    ScalerELEDSetOvp(_ELED_BOOSTING_STATE);

    // Set OCP Reference Voltage
    ScalerELEDSetOcp(_ELED_BOOSTING_STATE);
    
    // Set OSP Reference Voltage
    ScalerELEDSetOsp();

    // Set OTP Reference Voltage
    ScalerELEDSetOtp();

    // Set LED_SHORT Reference Voltage
    ScalerELEDSetLedShort();
}

//----------------------------------------------------------
// Description  : LED Backlight OVp Parameter
// Input Value  : VOUT, OVP_RATIO
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetOvp(EnumLedBoosterStatus enumBoosterStatus)
{
    BYTE ucOvpCount = 0;
    BYTE ucOvpParameter = 0;

    if(enumBoosterStatus == _ELED_BOOSTING_STATE)
    {
        // Set OVP Histeresis 25mV
        ScalerSetBit(P16_BD_LEDBC_OVP, ~(_BIT3 | _BIT2), 0x00);
        
        // Set OVP De-bounce Time 40us
        ScalerSetBit(P16_BF_LEDBC_OXP_REG_2, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));

        if(ScalerGetByte(CM_0F_ID_REG_02) >= 0x62)
        {
#if(_PANEL_ELED_VOUT_MAX >= 22)

            // Set LED OVP Tigger Voltage For High Loading Panel
            ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~_BIT7, _BIT7);
            
            // Set OVP Tigger Voltage Over _ELED_PCB_OVP_TRIGGER_LEVEL
            for(ucOvpCount = 54; ucOvpCount <= 180; ucOvpCount += 2)
            {
                if(((WORD)_ELED_PCB_OVP_RATION * ucOvpCount) >= _ELED_PCB_OVP_TRIGGER_LEVEL)
                {
                    ScalerSetBit(P16_C1_LEDBC_ADVREF7, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), ucOvpParameter << 2);
                    break;
                }

                ucOvpParameter++;
            }

            if(((WORD)_ELED_PCB_OVP_RATION * 180) < _ELED_PCB_OVP_TRIGGER_LEVEL)
            {
                ScalerSetBit(P16_C1_LEDBC_ADVREF7, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2));
            }
#else

            // Set LED OVP Tigger Voltage For Low Loading Panel
            ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~_BIT7, 0x00);

            // Set OVP Tigger Voltage Over _ELED_PCB_OVP_TRIGGER_LEVEL
            for(ucOvpCount = 30; ucOvpCount <= 51; ucOvpCount += 3)
            {
                if(((WORD)_ELED_PCB_OVP_RATION * ucOvpCount) >= _ELED_PCB_OVP_TRIGGER_LEVEL)
                {
                    ScalerSetBit(P16_BA_LEDBC_CURRENT_CTRL, ~(_BIT2 | _BIT1 | _BIT0), ucOvpParameter);
                    break;
                }

                ucOvpParameter++;
            }

            if(((WORD)_ELED_PCB_OVP_RATION * 51) < _ELED_PCB_OVP_TRIGGER_LEVEL)
            {
                ScalerSetBit(P16_BA_LEDBC_CURRENT_CTRL, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            }
#endif
        }
        else
        {
            // Set OVP Tigger Voltage Over _ELED_PCB_OVP_TRIGGER_LEVEL
            for(ucOvpCount = 54; ucOvpCount <= 180; ucOvpCount += 2)
            {
                if(((WORD)_ELED_PCB_OVP_RATION * ucOvpCount) >= _ELED_PCB_OVP_TRIGGER_LEVEL)
                {
                    ScalerSetBit(P16_C1_LEDBC_ADVREF7, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), ucOvpParameter << 2);
                    break;
                }

                ucOvpParameter++;
            }

            if(((WORD)_ELED_PCB_OVP_RATION * 180) < _ELED_PCB_OVP_TRIGGER_LEVEL)
            {
                ScalerSetBit(P16_C1_LEDBC_ADVREF7, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2));
            }
        }
    }
    else if(enumBoosterStatus == _ELED_STEADY_STATE)
    {
#if(_ELED_VOUT_CAPACITOR == _ON)

        // Restore OVP Debounce time 10us
        ScalerSetBit(P16_BF_LEDBC_OXP_REG_2, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
#else

        // Restore OVP Debounce time from 10us to 40us For Samsung Turn Off Big Capacity
        ScalerSetBit(P16_BF_LEDBC_OXP_REG_2, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));
#endif
    }
}

//----------------------------------------------------------
// Description  : LED Backlight Ocp Parameter
// Input Value  : None
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetOcp(EnumLedBoosterStatus enumBoosterStatus)
{
    if(enumBoosterStatus == _ELED_BOOSTING_STATE)
    {
        // Set OCP Histeresis 50mV
        ScalerSetBit(P16_BB_LEDBC_OCP_IRQ, ~(_BIT6 | _BIT5), _BIT5);

        // Set OCP De-bounce Time 1ms
        ScalerSetBit(P16_BE_LEDBC_OXP_REG_1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));

        // Set OCP Tigger Voltage Over 4A
        ScalerSetBit(P16_BB_LEDBC_OCP_IRQ, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
    }
    else if(enumBoosterStatus == _ELED_STEADY_STATE)
    {
        // Restore OCP Debounce time 10us
        ScalerSetBit(P16_BE_LEDBC_OXP_REG_1, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
    }
}

//----------------------------------------------------------
// Description  : LED Backlight Osp Parameter
// Input Value  : None
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetOsp(void)
{
    // Set OSP Histeresis 50mV
    ScalerSetBit(P16_BD_LEDBC_OVP, ~(_BIT7 | _BIT6), _BIT6);

    // Set OSP De-bounce Time 2ms
    ScalerSetBit(P16_BF_LEDBC_OXP_REG_2, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // Set OSP Tigger Voltage under 1.25V
    ScalerSetBit(P16_BD_LEDBC_OVP, ~(_BIT5 | _BIT4), 0x00);
}

//----------------------------------------------------------
// Description  : LED Backlight Otp Parameter
// Input Value  : None
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetOtp(void)
{
    // Set OTP Histeresis 50mV
    ScalerSetBit(P16_BC_LEDBC_OTP, ~(_BIT5 | _BIT4), _BIT4);

    // Set OTP De-bounce Time 1ms
    ScalerSetBit(P16_BE_LEDBC_OXP_REG_1, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));

    // Set OTP Tigger temperautre 150C
    ScalerSetBit(P16_BC_LEDBC_OTP, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
}

//----------------------------------------------------------
// Description  : LED Backlight LED_Short Parameter
// Input Value  : None
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetLedShort(void)
{
    // Set LED_Short Histeresis 50mV
    ScalerSetBit(P16_B9_LEDBC_V_COMP, ~(_BIT3 | _BIT2), _BIT2);

#if(_ELED_VOUT_CAPACITOR == _ON)

    // Set LED_Short de-bounce count 4 times
    ScalerSetBit(P16_C4_LEDBC_ADVREF4, ~(_BIT5 | _BIT4), _BIT4);

    // Set LED_Short Tigger Voltage 4.5V
    ScalerSetBit(P16_D5_LEDBC_PROTECT_CTRL_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
    
#else

    // Set LED_Short de-bounce count 16 times
    ScalerSetBit(P16_C4_LEDBC_ADVREF4, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

    // Set LED_Short Tigger Voltage 4.5V
    ScalerSetBit(P16_D5_LEDBC_PROTECT_CTRL_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));    


#endif
}

//----------------------------------------------------------
// Description  : LED Backlight Oxp Enable/Disable
// Input Value  : VOUT, OVP_RATIO
// Output Value : None
//----------------------------------------------------------
void ScalerELEDProtectEn(void)
{
    // OXP All Enable Bit
    ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT7, _BIT7);

    // Set Protect HW mode
    ScalerELEDHwProtect(_ELED_PROTECT_HW_MODE);
}

//----------------------------------------------------------
// Description  : LED Backlight HW Protect En
// Input Value  : bon
// Output Value : None
//----------------------------------------------------------
void ScalerELEDHwProtect(EnumLedProtectCondition enumProtectMode)
{
    if(enumProtectMode == _ELED_PROTECT_HW_MODE)
    {
        // Enable HW mode Protect
        ScalerSetBit(P16_A1_LEDBC_DRIVER_CTRL2, ~_BIT3, _BIT3);
    }
    else if(enumProtectMode == _ELED_PROTECT_FW_MODE)
    {
        // Enable FW mode Protect IRQ
        ScalerGlobalIRQControl(_ENABLE);
        ScalerSetBit(P16_BB_LEDBC_OCP_IRQ, ~_BIT7, _BIT7);
        EX0 = 1;
    }
}
//----------------------------------------------------------
// Description  : LED Backlight Ovp Protect En
// Input Value  : bon
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetOvpEn(bit bOn)
{
    // Write One Clear OVP Flag
    ScalerSetBit(P16_BF_LEDBC_OXP_REG_2, ~_BIT7, _BIT7);
    
    if(bOn == _ON)
    {
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT2, 0x00);
    }
    else
    {
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT2, _BIT2);
    }
}

//----------------------------------------------------------
// Description  : LED Backlight Ocp Protect En
// Input Value  : bon
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetOcpEn(bit bOn)
{
    // Write One Clear OCP Flag
    ScalerSetBit(P16_BE_LEDBC_OXP_REG_1, ~_BIT6, _BIT6);
    
    if(bOn == _ON)
    {
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT3, 0x00);
    }
    else
    {
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT3, _BIT3);
    }
}

//----------------------------------------------------------
// Description  : LED Backlight Osp Protect En
// Input Value  : bon
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetOspEn(bit bOn)
{
    // Write One Clear OSP Flag

    ScalerSetBit(P16_BF_LEDBC_OXP_REG_2, ~_BIT6, _BIT6);

    if(bOn == _ON)
    {
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT1, 0x00);
    }
    else
    {
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT1, _BIT1);
    }
}

//----------------------------------------------------------
// Description  : LED Backlight Otp Protect En
// Input Value  : bon
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetOtpEn(bit bOn)
{
    // Write One Clear OTP Flag
    ScalerSetBit(P16_BE_LEDBC_OXP_REG_1, ~_BIT7, _BIT7);
    
    if(bOn == _ON)
    {
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT4, 0x00);
    }
    else
    {
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT4, _BIT4);
    }
}

//----------------------------------------------------------
// Description  : LED Backlight LED_SHORT Protect En
// Input Value  : bon
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetLedShortEn(bit bOn)
{
    // Write One Clear LED_SHORT Flag
    ScalerSetBit(P16_DA_LEDBC_LED_SHORT_DETECT_STA, ~_BIT7, _BIT7);
    
    if(bOn == _ON)
    {
        ScalerSetByte(P16_A7_LEDBC_ANALOG_RESERVED_0, 0x00);
        ScalerSetBit(P16_A8_LEDBC_ANALOG_RESERVED_1, ~_BIT6, _BIT6);
    }
    else
    {
        ScalerSetByte(P16_A7_LEDBC_ANALOG_RESERVED_0, 0xFF);
        ScalerSetBit(P16_A8_LEDBC_ANALOG_RESERVED_1, ~_BIT6, 0x00);
    }
}

#if(_PANEL_EMBEDDED_LED_DRIVER_OPEN_SUPPORT == _ON)
//----------------------------------------------------------
// Description  : LED Backlight LED_OPEN Reference Voltage
// Input Value  : enumBoosterStatus
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetLedOpen(EnumLedBoosterStatus enumBoosterStatus)
{
    BYTE ucOvpCount = 0;
    BYTE ucOvpParameter = 0;

    if(enumBoosterStatus == _ELED_BOOSTING_STATE)
    {
        if(ScalerGetByte(CM_0F_ID_REG_02) >= 0x62)
        {
#if(_PANEL_ELED_VOUT_TYPICAL >= 25)

            // Set LED Vim Voltage Tigger Voltage For High Loading Panel
            ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~_BIT4, _BIT4);

            // Set LED_OPEN Tigger Voltage
            for(ucOvpCount = 54; ucOvpCount <= 180; ucOvpCount += 2)
            {
                if(((WORD)_ELED_PCB_OVP_RATION * ucOvpCount) >= (WORD)_PANEL_ELED_VOUT_TYPICAL * 100)
                {
                    ScalerSetBit(P16_B8_LEDBC_VMINSENREF, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (ucOvpParameter - 1));
                    break;
                }

                ucOvpParameter++;
            }

            if(((DWORD)_ELED_PCB_OVP_RATION * 180) < ((DWORD)_PANEL_ELED_VOUT_TYPICAL * 100))
            {
                ScalerSetBit(P16_B8_LEDBC_VMINSENREF, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
            }
#else
            // Set LED Vim Voltage Tigger Voltage For Low Loading Panel
            ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~_BIT4, 0x00);

            // Set LED_OPEN Tigger Voltage
            for(ucOvpCount = 30; ucOvpCount <= 51; ucOvpCount += 3)
            {
                if(((WORD)_ELED_PCB_OVP_RATION * ucOvpCount) >= (WORD)_PANEL_ELED_VOUT_TYPICAL * 100)
                {
                    ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~(_BIT2 | _BIT1 | _BIT0), ucOvpParameter);
                    break;
                }

                ucOvpParameter++;
            }

            if(((WORD)_ELED_PCB_OVP_RATION * 180) < ((WORD)_PANEL_ELED_VOUT_TYPICAL * 100))
            {
                ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            }
#endif
        }
        else
        {
            // Set LED_OPEN Tigger Voltage
        for(ucOvpCount = 54; ucOvpCount <= 180; ucOvpCount += 2)
        {
            if(((WORD)_ELED_PCB_OVP_RATION * ucOvpCount) >= (WORD)_PANEL_ELED_VOUT_TYPICAL * 100)
            {
                ScalerSetBit(P16_B8_LEDBC_VMINSENREF, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (ucOvpParameter - 1));
                break;
            }

            ucOvpParameter++;
        }

            if(((DWORD)_ELED_PCB_OVP_RATION * 180) < ((DWORD)_PANEL_ELED_VOUT_TYPICAL * 100))
            {
                ScalerSetBit(P16_B8_LEDBC_VMINSENREF, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
            }
        }
    }
    else if(enumBoosterStatus == _ELED_STEADY_STATE)
    {
        if(ScalerGetByte(CM_0F_ID_REG_02) >= 0x62)
        {
            ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~_BIT4, 0x00);
            ScalerSetBit(P16_C6_LEDBC_ADVREF2, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        }
        else
        {
            ScalerSetBit(P16_B8_LEDBC_VMINSENREF, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        }
    }
}

//----------------------------------------------------------
// Description  : LED Backlight LED_OPEN Protect En
// Input Value  : bon
// Output Value : None
//----------------------------------------------------------
void ScalerELEDSetLedOpenEn(bit bOn)
{
    BYTE ucOvpCount = 0;
    BYTE ucOvpParameter = 0;
    
    if(bOn == _ON)
    {
        // Enable LED Open Function & Detect Manner From Vdet Pin
        ScalerSetBit(P16_AA_LEDBC_ANALOG_RESERVED_3, ~_BIT0, 0x00);
        ScalerSetBit(P16_C7_LEDBC_ADVREF1, ~_BIT3, _BIT3);

        // Set LED_OPEN Current Control Enable
        ScalerSetByte(P16_A9_LEDBC_ANALOG_RESERVED_2, 0xFF);
        
        // Set LED_Open Histeresis 50mV
        ScalerSetBit(P16_B9_LEDBC_V_COMP, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Vfb Refrence Voltage 0.1V
        ScalerSetBit(P16_D5_LEDBC_PROTECT_CTRL_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

        // Set LED_Open De-bounce Time
        ScalerSetBit(P16_C7_LEDBC_ADVREF1, ~_BIT6, _BIT6);
        
#if(_ELED_VOUT_CAPACITOR == _ON)

        // LED_OPEN De-bounce Time 1us
        ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~(_BIT6 | _BIT5), _BIT5);
#else

        // LED_OPEN De-bounce Time 8us
        ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~(_BIT6 | _BIT5), _BIT6);
#endif
    }
    else
    {
        // Disable LED Open Function
        ScalerSetBit(P16_AA_LEDBC_ANALOG_RESERVED_3, ~_BIT0, _BIT0);
        ScalerSetBit(P16_C7_LEDBC_ADVREF1, ~_BIT3, 0x00);

        // Set LED_OPEN Current Control Disable
        ScalerSetByte(P16_A9_LEDBC_ANALOG_RESERVED_2, 0x00);

        ScalerSetBit(P16_B8_LEDBC_VMINSENREF, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    }
}
#endif // End of #if(_PANEL_EMBEDDED_LED_DRIVER_OPEN_SUPPORT == _ON)

//----------------------------------------------------------
// Description  : LED Backlight Booster Compensation
// Input Value  : None
// Output Value : None
//----------------------------------------------------------
void ScalerELEDBoosterVdetCompensation(void)
{
    // Vdet Voltage = 0.6V
    pData[0] = 6;

#if(_ELED_VOUT_CAPACITOR == _ON)

	// Vdet Voltage = 0.8V 
	pData[2] = 3;
#else

    if(ScalerGetByte(CM_0F_ID_REG_02) >= 0x62)
    {
        // Vdet Voltage = 1V for samsung turn off big capacity
        pData[2] = 6;
    }       
    else
    {
        // Vdet Voltage = 1.2V for samsung turn off big capacity
        pData[2] = 9;
    }
#endif // End of #if(_ELED_VOUT_CAPACITOR == _ON)

    for(pData[1] = 0; pData[1] < pData[2]; pData[1]++)
    {
        ScalerSetBit(P16_D6_LEDBC_PROTECT_CTRL_2, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[0]);
        
        pData[0] += 1;

        ScalerTimerDelayXms(20);
    }
}
#endif // End of #if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
