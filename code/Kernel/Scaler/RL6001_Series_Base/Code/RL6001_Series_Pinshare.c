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
// ID Code      : RL6001_Series_Pinshare.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6001_SERIES_PINSHARE__

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
    ScalerSetByte(P10_A0_PIN_SHARE_CTRL00, ((BYTE)_PIN_41 << 6) | (_PIN_42 << 4) | (_PIN_43 << 2) | (_PIN_54)); // Page 10-A0 Pin 41,42,43,54
    ScalerSetByte(P10_A1_PIN_SHARE_CTRL01, ((BYTE)_PIN_45 << 6) | (_PIN_119 << 3) | (_PIN_126)); // Page 10-A1 Pin 45,119,126

    // Check if pin 58-59 are assigned to DDC1
#if(_PIN_58 == 6) && (_PIN_59 == 6)
    ScalerSetByte(P10_A2_PIN_SHARE_CTRL02, ((BYTE)_PIN_58_59_DDC1_to_52_53)); // Page 10-A2 Pin 58,59
    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#else
    ScalerSetByte(P10_A2_PIN_SHARE_CTRL02, ((BYTE)_PIN_58 << 4) | (_PIN_59 << 1) | (_PIN_58_59_DDC1_to_52_53)); // Page 10-A2 Pin 58,59
    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~_BIT7, _BIT7); // Disable DDC1
#endif

    ScalerSetByte(P10_A3_PIN_SHARE_CTRL03, ((BYTE)_PIN_46 << 6) | (_PIN_51 << 4) | (_PIN_64)); // Page 10-A3 Pin 46,51,64
    ScalerSetByte(P10_A4_PIN_SHARE_CTRL04, ((BYTE)_PIN_52 << 6) | (_PIN_66 << 3) | (_PIN_67)); // Page 10-A4 Pin 52,66,67
    ScalerSetByte(P10_A5_PIN_SHARE_CTRL05, ((BYTE)_PIN_53 << 6) | (_PIN_69 << 3) | (_PIN_70)); // Page 10-A5 Pin 53,69,70
    ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, ((BYTE)_PIN_47 << 6) | (_PIN_55 << 3) | (_PIN_63)); // Page 10-A6 Pin 47,55,63
    ScalerSetByte(P10_A7_PIN_SHARE_CTRL07, ((BYTE)_PIN_48 << 6) | (_PIN_68 << 3) | (_PIN_71)); // Page 10-A7 Pin 48,68,71
    ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, ((BYTE)_PIN_44 << 5) | (_PIN_96 << 3) | (_PIN_97)); // Page 10-A8 Pin 44,96,97
    ScalerSetByte(P10_A9_PIN_SHARE_CTRL09, ((BYTE)_PIN_74_75_76_77_78_79_80_81_82_83 << 6) | (_PIN_99 << 3) | (_PIN_100)); // Page 10-A9 Pin 74~83,99,100
    ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, ((BYTE)_PIN_98 << 6) | (_PIN_102 << 3) | (_PIN_105)); // Page 10-AA Pin 98,102,105
    ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, ((BYTE)_PIN_50 << 5) | (_PIN_101 << 3) | (_PIN_108)); // Page 10-AB Pin 50,101,108
    ScalerSetByte(P10_AC_PIN_SHARE_CTRL0C, ((BYTE)_PIN_103 << 4) | (_PIN_104 << 1)); // Page 10-AC Pin 103,104
    ScalerSetByte(P10_AD_PIN_SHARE_CTRL0D, ((BYTE)_PIN_110_111_112_113_114_MIRROR << 7) | (_PIN_109 << 4) | (_PIN_110)); // Page 10-AD Pin110~114 Mirror,109,110
    ScalerSetByte(P10_AE_PIN_SHARE_CTRL0E, ((BYTE)_PIN_111 << 4) | (_PIN_112)); // Page 10-AE Pin 111,112

    // Check if pin 56-57 are assigned to IIC
#if(_PIN_56 == 6) && (_PIN_57 == 6)
    ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~_BIT7, _BIT7); // Enable IIC
#else
	ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), ((BYTE)_PIN_56 << 4) | (_PIN_57 << 1)); // Page 10-AF Pin 56,57
#endif

    // Check if pin 121-122 are assigned to DDC3
#if(_PIN_121 == 4) && (_PIN_122 == 4)
    ScalerSetByte(P10_B0_PIN_SHARE_CTRL10, ((BYTE)_PIN_113 << 5)); // Page 10-B0 Pin 113
    ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#else
    ScalerSetByte(P10_B0_PIN_SHARE_CTRL10, ((BYTE)_PIN_113 << 5) | (_PIN_121 << 2) | (_PIN_122)); // Page 10-B0 Pin 113,121,122
    ScalerSetBit(P10_B0_PIN_SHARE_CTRL10, ~_BIT4, _BIT4); // Disable DDC3
#endif

// Check if pin 123-124 are assigned to DDC2
#if(_PIN_123 == 4) && (_PIN_124 == 4)
    ScalerSetByte(P10_B1_PIN_SHARE_CTRL11, ((BYTE)_PIN_65 << 5)); // Page 10-B1 Pin 65
    ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#else
    ScalerSetByte(P10_B1_PIN_SHARE_CTRL11, ((BYTE)_PIN_65 << 5) | (_PIN_123 << 2) | (_PIN_124)); // Page 10-B1 Pin 65,123,124
    ScalerSetBit(P10_B1_PIN_SHARE_CTRL11, ~_BIT4, _BIT4); // Disable DDC2
#endif

    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), ((BYTE)_PIN_72 << 5) | (_PIN_114 << 2)); // Page 10-B2 Pin 72,114
    ScalerSetByte(P10_B6_PIN_SHARE_CTRL13, ((BYTE)_PIN_74 << 6) | (_PIN_75 << 4) | (_PIN_78 << 2) | (_PIN_79)); // Page 10-B6 Pin 74,75,78,79
    ScalerSetByte(P10_B7_PIN_SHARE_CTRL14, ((BYTE)_PIN_31 << 6) | (_PIN_32 << 4) | (_PIN_33 << 2) | (_PIN_34)); // Page 10-B7 Pin 31,32,33,34
    ScalerSetByte(P10_B8_PIN_SHARE_CTRL15, ((BYTE)_PIN_35 << 6) | (_PIN_36 << 4) | (_PIN_37 << 2) | (_PIN_39)); // Page 10-B8 Pin 35,36,37,39
    ScalerSetBit(P10_B9_PIN_SHARE_CTRL16, ~(_BIT6 | _BIT5 | _BIT4 | _BIT1 | _BIT0), ((BYTE)_P31_39_SEL << 6) | ((BYTE)_P41_48_SEL << 4) | (_PIN_40)); // Page 10-B9 Pin 40

    // DDC Driving Current Set High
    ScalerSetBit(P10_B3_PIN_DRIVING_CTRL1, ~_BIT5, _BIT5);
    ScalerSetBit(P10_B4_PIN_DRIVING_CTRL2, ~_BIT3, _BIT3);

    // Xtal Spread Spectrum Disable
    ScalerSetBit(P10_B9_PIN_SHARE_CTRL16, ~_BIT3, 0x00);

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
// Input Value  : ucHwIICPinNum --> Pin42_43/56_57/69_70/103_104
// Output Value : None
//--------------------------------------------------
void ScalerPinshareHwIICPin(BYTE ucHwIICPinNum)
{
    // Set the selected HwIICPinNum to IIC output
    // Set the others as GPI
    switch(ucHwIICPinNum)
    {
        case _HW_IIC_PIN_42_43:

        ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

#if((_PIN_56 == 6) && (_PIN_57 == 6))
        ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);
#endif

#if((_PIN_69 == 7) && (_PIN_70 == 7))
        ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#endif

#if((_PIN_103 == 7) && (_PIN_104 == 7))
        ScalerSetBit(P10_AC_PIN_SHARE_CTRL0C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);
#endif

            break;

        case _HW_IIC_PIN_56_57:

        ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT7);

#if((_PIN_42 == 3) && (_PIN_43 == 3))
        ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
#endif

#if((_PIN_69 == 7) && (_PIN_70 == 7))
        ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#endif

#if((_PIN_103 == 7) && (_PIN_104 == 7))
        ScalerSetBit(P10_AC_PIN_SHARE_CTRL0C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);
#endif
            break;

        case _HW_IIC_PIN_69_70:

        ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));

#if((_PIN_42 == 3) && (_PIN_43 == 3))
        ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
#endif

#if((_PIN_56 == 6) && (_PIN_57 == 6))
        ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);
#endif

#if((_PIN_103 == 7) && (_PIN_104 == 7))
        ScalerSetBit(P10_AC_PIN_SHARE_CTRL0C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);
#endif

            break;

        case _HW_IIC_PIN_103_104:

        ScalerSetBit(P10_AC_PIN_SHARE_CTRL0C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1));

#if((_PIN_42 == 3) && (_PIN_43 == 3))
        ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
#endif

#if((_PIN_56 == 6) && (_PIN_57 == 6))
        ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);
#endif

#if((_PIN_69 == 7) && (_PIN_70 == 7))
        ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#endif

            break;

        default:

            break;
    }
}
#endif  // End of #if(_HW_IIC_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Switch DDC pin to GPIO or viceversa
// Input Value  : Pins for HW IIC
// Output Value : None
//--------------------------------------------------
void ScalerPinshareGpioDdcPinSwitch(BYTE ucPinType)
{
    switch(ucPinType)
    {
        case _DDC1_SWITCH_GPIO:
            ScalerSetByte(P10_A2_PIN_SHARE_CTRL02, ((BYTE)_GPIO_OPEN_DRAIN << 4) | (_GPIO_OPEN_DRAIN << 1) | (_PIN_58_59_DDC1_to_52_53)); // Page 10-A2 Pin 58,59
            ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~_BIT7, _BIT7); // Disable DDC1
        break;

        case _DDC1_SWITCH_DDC:
            ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~_BIT7, 0x00); // Enable DDC1
        break;

        case _DDC2_SWITCH_GPIO:
            ScalerSetByte(P10_B1_PIN_SHARE_CTRL11, ((BYTE)_PIN_65 << 5) | (_GPIO_OPEN_DRAIN << 2) | (_GPIO_OPEN_DRAIN)); // Page 10-B1 Pin 65,123,124
            ScalerSetBit(P10_B1_PIN_SHARE_CTRL11, ~_BIT4, _BIT4); // Disable DDC2
        break;

        case _DDC2_SWITCH_DDC:
            ScalerSetBit(P10_B1_PIN_SHARE_CTRL11, ~_BIT4, 0x00); // Enable DDC2
        break;

        case _DDC3_SWITCH_GPIO:
            ScalerSetByte(P10_B0_PIN_SHARE_CTRL10, ((BYTE)_PIN_113 << 5) | (_GPIO_OPEN_DRAIN << 2) | (_GPIO_OPEN_DRAIN)); // Page 10-B0 Pin 113,121,122
            ScalerSetBit(P10_B0_PIN_SHARE_CTRL10, ~_BIT4, _BIT4); // Disable DDC3
        break;

        case _DDC3_SWITCH_DDC:
            ScalerSetBit(P10_B0_PIN_SHARE_CTRL10, ~_BIT4, 0x00); // Enable DDC3
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
         case _CONFIG_PIN_31:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT7 | _BIT6), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT7 | _BIT6), _BIT6);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT7 | _BIT6), _BIT7);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_32:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT5 | _BIT4), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT5 | _BIT4), _BIT4);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT5 | _BIT4), _BIT5);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_33:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT3 | _BIT2), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT3 | _BIT2), _BIT2);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT3 | _BIT2), _BIT3);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_34:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_35:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT7 | _BIT6), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT7 | _BIT6), _BIT6);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT7 | _BIT6), _BIT7);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_36:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT5 | _BIT4), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT5 | _BIT4), _BIT4);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT5 | _BIT4), _BIT5);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_37:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT3 | _BIT2), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT3 | _BIT2), _BIT2);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT3 | _BIT2), _BIT3);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_39:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_40:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B9_PIN_SHARE_CTRL16, ~(_BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B9_PIN_SHARE_CTRL16, ~(_BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B9_PIN_SHARE_CTRL16, ~(_BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_54:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_55:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT5 | _BIT4 | _BIT3), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT5 | _BIT4 | _BIT3), _BIT3);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
                    break;

                case _PWM1_OD:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));
                    break;

                case _PWM1_PP:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
                    break;

                case _PWM5_PP:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT3));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_63:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM2_PP:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM2_OD:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_72:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT7 | _BIT6 | _BIT5), _BIT7);
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT5));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_96:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT4 | _BIT3), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT4 | _BIT3), _BIT3);
                    break;

                case _PWM0_PP:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_97:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM1_PP:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM1_OD:
                    ScalerSetBit(P10_A8_PIN_SHARE_CTRL08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_98:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT7 | _BIT6), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT7 | _BIT6), _BIT6);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT7 | _BIT6), _BIT7);
                    break;

                case _PWM2_PP:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_99:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT5 | _BIT4 | _BIT3), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT5 | _BIT4 | _BIT3), _BIT3);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_100:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM4_PP:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM4_OD:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_101:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_AB_PIN_SHARE_CTRL0B, ~(_BIT4 | _BIT3), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_AB_PIN_SHARE_CTRL0B, ~(_BIT4 | _BIT3), _BIT3);
                    break;

                case _PWM5_PP:
                    ScalerSetBit(P10_AB_PIN_SHARE_CTRL0B, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
                    break;

                default:
                    break;
            }

            break;

        default:
            break;
    }
}
