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
// ID Code      : RL6230_Series_Pinshare.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6230_SERIES_PINSHARE__

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
    // Check if pin 18-19 are assigned to DDC1
#if(_PIN_18 == 4) && (_PIN_19 == 4)
    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#else
    ScalerSetByte(P10_A0_PIN_SHARE_CTRL00, ((BYTE)_PIN_19 << 2) | (_PIN_18));
    ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~_BIT4, _BIT4);
#endif

    ScalerSetByte(P10_A1_PIN_SHARE_CTRL01, ((BYTE)_PIN_20 << 5) | (_PIN_29 << 3) | (_PIN_25 << 1));

    ScalerSetByte(P10_A2_PIN_SHARE_CTRL02, ((BYTE)_PIN_26 << 6) | (_PIN_27 << 3) | (_PIN_28));

    ScalerSetByte(P10_A3_PIN_SHARE_CTRL03, ((BYTE)_PIN_33 << 6) | (_PIN_34 << 4) | (_PIN_35 << 2) | (_PIN_36));

    ScalerSetByte(P10_A4_PIN_SHARE_CTRL04, ((BYTE)_PIN_37 << 6) | (_PIN_38 << 4) | (_PIN_39 << 2) | (_PIN_40));

    ScalerSetByte(P10_A5_PIN_SHARE_CTRL05, ((BYTE)_PIN_55 << 6) | (_PIN_56 << 3));

    ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, ((BYTE)_PIN_57 << 3) | (_PIN_58 << 1));

    ScalerSetByte(P10_A7_PIN_SHARE_CTRL07, ((BYTE)_PIN_59 << 5) | (_PIN_60 << 1));

    ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, ((BYTE)_PIN_61 << 3) | (_PIN_62));

    ScalerSetByte(P10_A9_PIN_SHARE_CTRL09, ((BYTE)_PIN_63 << 5) | (_PIN_64 << 3));

    ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, (BYTE)_PIN_4 << 4);

    // DDC Driving Current Set High
    ScalerSetBit(P10_B0_PIN_SHARE_CTRL10, ~_BIT5, _BIT5);

    // Set Pin configure to AC ON
    ScalerPinshareConfig(_POWER_STATUS_AC_ON);

    // Pin Config adjust sample (this is a ineffective configuration example aviod uncall worning)
    ScalerPinshareAdjustConfig(_CONFIG_PIN_START, _GPI);
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
    ucHwIICPinNum = ucHwIICPinNum;
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
            ScalerSetByte(P10_A0_PIN_SHARE_CTRL00, ((BYTE)_GPIO_OPEN_DRAIN << 2) | (_GPIO_OPEN_DRAIN));
            ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~_BIT4, _BIT4); // Disable DDC1
        break;

        case _DDC1_SWITCH_DDC:
            ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~_BIT4, 0x00); // Enable DDC1
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
        case _CONFIG_PIN_4:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT5 | _BIT4), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT5 | _BIT4), _BIT4);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT5 | _BIT4), _BIT5);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_20:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);
                    break;

                case _PWM0_OD:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));
                    break;

                case _PWM0_PP:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT7 | _BIT6 | _BIT5), _BIT7);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_25:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT2 | _BIT1), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT2 | _BIT1), _BIT1);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT2 | _BIT1), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_26:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT7 | _BIT6), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT7 | _BIT6), _BIT6);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT7 | _BIT6), _BIT7);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_27:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT5 | _BIT4 | _BIT3), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT5 | _BIT4 | _BIT3), _BIT3);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
                    break;

                case _PWM1_OD:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));
                    break;

                case _PWM1_PP:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_28:

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

                case _PWM2_OD:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM2_PP:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_29:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT4 | _BIT3), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT4 | _BIT3), _BIT3);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT4 | _BIT3), _BIT4);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_55:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT7 | _BIT6), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT7 | _BIT6), _BIT6);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT7 | _BIT6), _BIT7);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_56:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT5 | _BIT4 | _BIT3), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT5 | _BIT4 | _BIT3), _BIT3);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);

                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_61:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT5 | _BIT4 | _BIT3), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT5 | _BIT4 | _BIT3), _BIT3);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
                    break;

                case _PWM4_OD:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));
                    break;

                case _PWM4_PP:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_62:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM5_OD:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM5_PP:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_63:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_64:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT4 | _BIT3), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT4 | _BIT3), _BIT3);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT4 | _BIT3), _BIT4);
                    break;

                default:
                    break;
            }

            break;

        default:
            break;
    }
}
