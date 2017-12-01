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
// ID Code      : RL6373_Series_Pinshare.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6373_SERIES_PINSHARE__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _GPIO_OPEN_DRAIN                        1

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
void ScalerPinshareInitial(void);
void ScalerPinshareConfig(BYTE ucPorStatus);

#if(_HW_IIC_SUPPORT == _ON)
void ScalerPinshareHwIICPin(BYTE ucHwIICPinNum);
#endif

void ScalerPinshareGpioDdcPinSwitch(BYTE ucPinType);
void ScalerPinshareAdjustConfig(EnumConfigPin enumConfigPin, EnumPinConfigTyte enumConfigTyte);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Pinshare Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPinshareInitial(void)
{
    ScalerSetByte(P10_A2_PIN_SHARE_CTRL02, (BYTE)_PIN_19);
    ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, (BYTE)_PIN_20);
    ScalerSetByte(P10_A5_PIN_SHARE_CTRL05, (BYTE)_PIN_27);
    ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, (BYTE)_PIN_28);

    // Check if pin 29-30 are assigned to DDC1 / IIC
#if(_PIN_29== 9) && (_PIN_30== 9)
    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#elif(_PIN_29== 10) && (_PIN_30 == 10)
    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT7 | _BIT6), _BIT7);
#else
    ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, (BYTE)_PIN_29);
    ScalerSetByte(P10_A9_PIN_SHARE_CTRL09, (BYTE)_PIN_30);
    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT7 | _BIT6), _BIT6);
#endif

    ScalerSetByte(P10_AE_PIN_SHARE_CTRL0E, (BYTE)_PIN_31);
    ScalerSetByte(P10_AF_PIN_SHARE_CTRL0F, (BYTE)_PIN_32);
    ScalerSetByte(P10_B0_PIN_SHARE_CTRL10, (BYTE)_PIN_33);
    ScalerSetByte(P10_B1_PIN_SHARE_CTRL11, (BYTE)_PIN_34);
    ScalerSetByte(P10_B2_PIN_SHARE_CTRL12, (BYTE)_PIN_35);
    ScalerSetByte(P10_B3_PIN_SHARE_CTRL13, (BYTE)_PIN_36);
    ScalerSetByte(P10_B4_PIN_SHARE_CTRL14, (BYTE)_PIN_37);
    ScalerSetByte(P10_B5_PIN_SHARE_CTRL15, (BYTE)_PIN_38);

    ScalerSetByte(P10_BF_PIN_SHARE_CTRL17, (BYTE)_PIN_8);
    ScalerSetByte(P10_C0_PIN_SHARE_CTRL18, (BYTE)_PIN_9);
    ScalerSetByte(P10_C1_PIN_SHARE_CTRL19, (BYTE)_PIN_10);
    ScalerSetByte(P10_C2_PIN_SHARE_CTRL1A, (BYTE)_PIN_11);
    ScalerSetByte(P10_C3_PIN_SHARE_CTRL1B, (BYTE)_PIN_12);
    ScalerSetByte(P10_C4_PIN_SHARE_CTRL1C, (BYTE)_PIN_13);
    ScalerSetByte(P10_C5_PIN_SHARE_CTRL1D, (BYTE)_PIN_14);
    ScalerSetByte(P10_C6_PIN_SHARE_CTRL1E, (BYTE)_PIN_15);
    ScalerSetByte(P10_C7_PIN_SHARE_CTRL1F, (BYTE)_PIN_16);
    ScalerSetByte(P10_C8_PIN_SHARE_CTRL20, (BYTE)_PIN_39);
    ScalerSetByte(P10_C9_PIN_SHARE_CTRL21, (BYTE)_PIN_40);
    ScalerSetByte(P10_CA_PIN_SHARE_CTRL22, (BYTE)_PIN_41);
    ScalerSetByte(P10_CB_PIN_SHARE_CTRL23, (BYTE)_PIN_42);
    ScalerSetByte(P10_CC_PIN_SHARE_CTRL24, (BYTE)_PIN_43);
    ScalerSetByte(P10_CD_PIN_SHARE_CTRL25, (BYTE)_PIN_44);
    ScalerSetByte(P10_CE_PIN_SHARE_CTRL26, (BYTE)_PIN_45);
    ScalerSetByte(P10_CF_PIN_SHARE_CTRL27, (BYTE)_PIN_46);
    ScalerSetByte(P10_D0_PIN_SHARE_CTRL28, (BYTE)_PIN_47);
    ScalerSetByte(P10_D1_PIN_SHARE_CTRL29, (BYTE)_PIN_48);

    // DDC Driving Current Set High
    ScalerSetBit(P10_B7_PIN_DRIVING_CTRL0, ~_BIT2, _BIT2);

    // Xtal Spread Spectrum Disable
    ScalerSetBit(P10_BA_PIN_XTAL_SPREAD_CTRL, ~_BIT3, 0x00);

    // Set Pin configure to AC ON
    ScalerPinshareConfig(_POWER_STATUS_AC_ON);

    // Pin Config adjust sample (this is a ineffective configuration example aviod uncall worning)
    ScalerPinshareAdjustConfig(_CONFIG_PIN_START, _GPI);

    // In Order To Fix LVDS Glitch After 1.2V POR Ready
    ScalerSetBit(CM_01_HOST_CTRL, ~_BIT3, _BIT3);
}

//--------------------------------------------------
// Description  : Low Leakage or Normal Pin Config.
// Input Value  : ON --> Low Leakage Config. ; OFF --> Normal Operation
// Output Value : None
//--------------------------------------------------
void ScalerPinshareConfig(BYTE ucPorStatus)
{
    // GPIO Config
    if(ucPorStatus == _POWER_STATUS_NORMAL)
    {
        PCB_GPIO_SETTING_POWER_NORMAL();
    }
    else if(ucPorStatus == _POWER_STATUS_SAVING)
    {
        PCB_GPIO_SETTING_POWER_SAVING();
    }
    else if(ucPorStatus == _POWER_STATUS_AC_ON)
    {
        PCB_GPIO_SETTING_POWER_AC_ON();
    }
    else // Power Down
    {
        PCB_GPIO_SETTING_POWER_DOWN();
    }
}

#if(_HW_IIC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set HW IIC Pin Out
// Input Value  : Pins for HW IIC
// Output Value : None
//--------------------------------------------------
void ScalerPinshareHwIICPin(BYTE ucHwIICPinNum)
{
    // Set the selected HwIICPinNum to IIC output
    // Set the others as GPI
    switch(ucHwIICPinNum)
    {
        case _HW_IIC_64PIN_PIN_29_30:

        ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT7 | _BIT6), _BIT7);

            break;

        default:

            break;
    }
}
#endif  // End of #if(_HW_IIC_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Switch DDC pin to GPIO or viceversa
// Input Value  : ucPinType --> _PIN_58/59-121/122-123/124_GPIO/DDC
// Output Value : None
//--------------------------------------------------
void ScalerPinshareGpioDdcPinSwitch(BYTE ucPinType)
{
    switch(ucPinType)
    {
        case _DDC1_SWITCH_GPIO:

            ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, (BYTE)_GPIO_OPEN_DRAIN);
            ScalerSetByte(P10_A9_PIN_SHARE_CTRL09, (BYTE)_GPIO_OPEN_DRAIN);
            ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT7 | _BIT6), _BIT6); // Disable DDC1
        break;

        case _DDC1_SWITCH_DDC:
            ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT7 | _BIT6), 0x00); // Enable DDC1
        break;

        default:
        break;
    }
}

//--------------------------------------------------
// Description  : Adjust pin share config
// Input Value  : enumConfigPin  --> Pin num
//                enumConfigTyte --> Pin type(GPIO/PWM..Etc.)
// Output Value : None
//--------------------------------------------------
void ScalerPinshareAdjustConfig(EnumConfigPin enumConfigPin, EnumPinConfigTyte enumConfigTyte)
{
    switch(enumConfigPin)
    {
        case _CONFIG_PIN_19:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_20:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM0_OD:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                case _PWM0_PP:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

                default:
                    break;
            }

            break;

        default:
            break;
    }
}