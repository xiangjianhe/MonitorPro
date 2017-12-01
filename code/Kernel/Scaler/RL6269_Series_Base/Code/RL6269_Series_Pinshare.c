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
// ID Code      : RL6269_Series_Pinshare.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6269_SERIES_PINSHARE__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _GPIO_OPEN_DRAIN                        2

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
    ScalerSetByte(P10_A0_PIN_SHARE_CTRL00, (BYTE)_PIN_1);  // Page 10-A0 Pin 1
    ScalerSetByte(P10_A1_PIN_SHARE_CTRL01, (BYTE)_PIN_22); // Page 10-A1 Pin 22
    ScalerSetByte(P10_A3_PIN_SHARE_CTRL03, (BYTE)_PIN_24); // Page 10-A3 Pin 24
    ScalerSetByte(P10_A4_PIN_SHARE_CTRL04, (BYTE)_PIN_25); // Page 10-A4 Pin 25

    // Check if pin 26-27 are assigned to IIC
#if((_PIN_26 == 8) && (_PIN_27 == 8))
    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~_BIT7, _BIT7);  // Enable IIC
#else
    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), (BYTE)_PIN_26); // Page 10-A5 Pin 26
    ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, (BYTE)_PIN_27); // Page 10-A6 Pin 27
#endif

    // Check if pin 39-40 are assigned to IIC
#if((_PIN_39 == 7) && (_PIN_40 == 7))
    ScalerSetBit(P10_A7_PIN_SHARE_CTRL07, ~_BIT6, _BIT6); // Enable IIC
#else
    ScalerSetBit(P10_A7_PIN_SHARE_CTRL07, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), (BYTE)_PIN_39); // Page 10-A7 Pin 39
    ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, (BYTE)_PIN_40); // Page 10-A8 Pin 40
#endif

    ScalerSetByte(P10_A9_PIN_SHARE_CTRL09, (BYTE)_PIN_41); // Page 10-A9 Pin 41
    ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, (BYTE)_PIN_42); // Page 10-AA Pin 42
    ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, (BYTE)_PIN_43); // Page 10-AB Pin 43
    ScalerSetByte(P10_AC_PIN_SHARE_CTRL0C, (BYTE)_PIN_44); // Page 10-AC Pin 44
    ScalerSetByte(P10_AD_PIN_SHARE_CTRL0D, (BYTE)_PIN_45); // Page 10-AD Pin 45

    ScalerSetBit(P10_A7_PIN_SHARE_CTRL07, ~_BIT7, (BYTE)_P39_45_SEL << 7); // Page 10-A7 Pin 39~45 audio

    ScalerSetByte(P10_AE_PIN_SHARE_CTRL0E, (BYTE)_PIN_47); // Page 10-AE Pin 47
    ScalerSetByte(P10_AF_PIN_SHARE_CTRL0F, (BYTE)_PIN_48); // Page 10-AF Pin 48
    ScalerSetByte(P10_B0_PIN_SHARE_CTRL10, (BYTE)_PIN_49); // Page 10-B0 Pin 49
    ScalerSetByte(P10_B1_PIN_SHARE_CTRL11, (BYTE)_PIN_50); // Page 10-B1 Pin 50
    ScalerSetByte(P10_B2_PIN_SHARE_CTRL12, (BYTE)_PIN_51); // Page 10-B2 Pin 51

    // Check if pin 52-53 are assigned to IIC
#if((_PIN_52 == 6) && (_PIN_53 == 6))
    ScalerSetBit(P10_B3_PIN_SHARE_CTRL13, ~_BIT7, _BIT7); // Enable IIC
#else
    ScalerSetBit(P10_B3_PIN_SHARE_CTRL13, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), (BYTE)_PIN_52); // Page 10-B3 Pin 52
    ScalerSetByte(P10_B4_PIN_SHARE_CTRL14, (BYTE)_PIN_53); // Page 10-B4 Pin 53
#endif

    ScalerSetByte(P10_B5_PIN_SHARE_CTRL15, (BYTE)_PIN_54); // Page 10-B5 Pin 54

    // Check if pin 56-57 are assigned to DDC1
#if((_PIN_56 == 9) && (_PIN_57 == 9))
    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#else
    ScalerSetBit(P10_B6_PIN_SHARE_CTRL16, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | ((BYTE)_PIN_56))); // Page 10-B6 Pin 56[3:0]
    ScalerSetByte(P10_B7_PIN_SHARE_CTRL17, (BYTE)_PIN_57); // Page 10-B7 Pin 57
#endif

    // Check if pin 60~63 are assigned to SPI
#if((_PIN_60 == 10) && (_PIN_61 == 10) && (_PIN_62 == 10) && (_PIN_63 == 11))
    ScalerSetBit(P10_B8_PIN_SHARE_CTRL18, ~_BIT7, _BIT7); // Enable SPI
#else

    // Disable SPI
    ScalerSetBit(P10_B8_PIN_SHARE_CTRL18, ~_BIT7, 0x00);

    // Check if Pin 60-61 are assigned to UART
#if((_PIN_60 == 9) && (_PIN_61 == 9))
    ScalerSetBit(P10_B8_PIN_SHARE_CTRL18, ~(_BIT6 | _BIT5), _BIT6); // Enable UART
#elif((_PIN_60 == 8) && (_PIN_61 == 8)) // Check if Pin 60-61 are assigned to IIC
    ScalerSetBit(P10_B8_PIN_SHARE_CTRL18, ~(_BIT6 | _BIT5), _BIT5); // Enable IIC
#else
    ScalerSetBit(P10_B8_PIN_SHARE_CTRL18, ~(_BIT6 | _BIT5 | _BIT2 | _BIT1 | _BIT0), (BYTE)_PIN_60); // Page 10-B8 Pin 60
    ScalerSetByte(P10_B9_PIN_SHARE_CTRL19, (BYTE)_PIN_61); // Page 10-B9 Pin 61
#endif // End of #if((_PIN_60 == 9) && (_PIN_61 == 9))

    // Check if Pin 62-63 are assigned to UART
#if((_PIN_62 == 9) && (_PIN_63 == 10))
    ScalerSetBit(P10_BA_PIN_SHARE_CTRL1A, ~(_BIT7 | _BIT6), _BIT7); // Enable UART
#elif((_PIN_62 == 8) && (_PIN_63 == 9)) // Check if Pin 62-63 are assigned to IIC
    ScalerSetBit(P10_BA_PIN_SHARE_CTRL1A, ~(_BIT7 | _BIT6), _BIT6); // Enable IIC
#else
    ScalerSetBit(P10_BA_PIN_SHARE_CTRL1A, ~(_BIT7 | _BIT6 | _BIT2 | _BIT1 | _BIT0), (BYTE)_PIN_62); // Page 10-BA Pin 62
    ScalerSetByte(P10_BB_PIN_SHARE_CTRL1B, (BYTE)_PIN_63); // Page 10-BB Pin 63
#endif // Endo of #if((_PIN_62 == 9) && (_PIN_63 == 10))

#endif // End of #if((_PIN_60 == 10) && (_PIN_61 == 10) && (_PIN_62 == 10) && (_PIN_63 == 11))

    ScalerSetByte(P10_BC_PIN_SHARE_CTRL1C, (BYTE)_PIN_64); // Page 10-BC Pin 64
    ScalerSetByte(P10_BD_PIN_SHARE_CTRL1D, (BYTE)_PIN_65); // Page 10-BD Pin 65
    ScalerSetByte(P10_BE_PIN_SHARE_CTRL1E, (BYTE)_PIN_66); // Page 10-BE Pin 66
    ScalerSetByte(P10_BF_PIN_SHARE_CTRL1F, (BYTE)_PIN_67); // Page 10-BF Pin 67
    ScalerSetByte(P10_C0_PIN_SHARE_CTRL20, (BYTE)_PIN_68); // Page 10-C0 Pin 68
    ScalerSetByte(P10_C1_PIN_SHARE_CTRL21, (BYTE)_PIN_69); // Page 10-C1 Pin 69
    ScalerSetByte(P10_C2_PIN_SHARE_CTRL22, (BYTE)_PIN_70); // Page 10-C2 Pin 70
    ScalerSetByte(P10_C3_PIN_SHARE_CTRL23, (BYTE)_PIN_71); // Page 10-C3 Pin 71
    ScalerSetByte(P10_C4_PIN_SHARE_CTRL24, (BYTE)_PIN_72); // Page 10-C4 Pin 72
    ScalerSetByte(P10_C5_PIN_SHARE_CTRL25, (BYTE)_PIN_73); // Page 10-C5 Pin 73
    ScalerSetByte(P10_C6_PIN_SHARE_CTRL26, (BYTE)_PIN_74); // Page 10-C6 Pin 74
    ScalerSetByte(P10_C7_PIN_SHARE_CTRL27, (BYTE)_PIN_87); // Page 10-C7 Pin 87
    ScalerSetByte(P10_C8_PIN_SHARE_CTRL28, (BYTE)_PIN_88); // Page 10-C8 Pin 88
    ScalerSetByte(P10_CA_PIN_SHARE_CTRL2A, (BYTE)_PIN_90); // Page 10-CA Pin 90
    ScalerSetByte(P10_CB_PIN_SHARE_CTRL2B, (BYTE)_PIN_91); // Page 10-CB Pin 91
    ScalerSetByte(P10_CC_PIN_SHARE_CTRL2C, (BYTE)_PIN_92); // Page 10-CC Pin 92
    ScalerSetByte(P10_CE_PIN_SHARE_CTRL2E, (BYTE)_PIN_94); // Page 10-CE Pin 94
    ScalerSetByte(P10_CF_PIN_SHARE_CTRL2F, (BYTE)_PIN_95); // Page 10-CF Pin 95
    ScalerSetByte(P10_D0_PIN_SHARE_CTRL30, (BYTE)_PIN_96); // Page 10-D0 Pin 96
    ScalerSetByte(P10_D2_PIN_SHARE_CTRL32, (BYTE)_PIN_98); // Page 10-D2 Pin 98
    ScalerSetByte(P10_D3_PIN_SHARE_CTRL33, (BYTE)_PIN_99); // Page 10-D3 Pin 99
    ScalerSetByte(P10_D4_PIN_SHARE_CTRL34, (BYTE)_PIN_100); // Page 10-D4 Pin 100
    ScalerSetByte(P10_DC_PIN_SHARE_CTRL3C, (BYTE)_PIN_119); // Page 10-DC Pin 119

    // Check if pin 123-124 are assigned to DDC3
#if((_PIN_123 == 7) && (_PIN_124 == 7))
    ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#else
    ScalerSetBit(P10_DD_PIN_SHARE_CTRL3D, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | (BYTE)_PIN_123)); // Page 10-DD Pin 123[2:0]
    ScalerSetByte(P10_DE_PIN_SHARE_CTRL3E, (BYTE)_PIN_124); // Page 10-DE Pin 124
#endif

    // Check if pin 125-126 are assigned to DDC2
#if((_PIN_125 == 7) && (_PIN_126 == 7))
    ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#else
    ScalerSetBit(P10_DF_PIN_SHARE_CTRL3F, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | (BYTE)_PIN_125)); // Page 10-DF Pin 125[2:0]
    ScalerSetByte(P10_E0_PIN_SHARE_CTRL40, (BYTE)_PIN_126); // Page 10-E0 Pin 126
#endif

    // DDC Driving Current Set High
    ScalerSetBit(P10_E1_PIN_DRIVING_CTRL41, ~_BIT3, _BIT3);
    ScalerSetBit(P10_E2_PIN_DVIVING_CTRL42, ~_BIT0, _BIT0);

    // Xtal Spread Spectrum Disable
    ScalerSetBit(P10_E5_PIN_XTAL_SPREAD_CTRL45, ~_BIT3, 0x00);

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
// Input Value  : ucHwIICPinNum --> Pin26_27/39_40/52_53/60_61/62_63
// Output Value : None
//--------------------------------------------------
void ScalerPinshareHwIICPin(BYTE ucHwIICPinNum)
{
    // Set the selected HwIICPinNum to IIC output
    // Set the others as GPI
    switch(ucHwIICPinNum)
    {
        case _HW_IIC_PIN_26_27:

            ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~_BIT7, _BIT7);

#if((_PIN_39 == 7) && (_PIN_40 == 7))
            ScalerSetByte(P10_A7_PIN_SHARE_CTRL07, 0x00);
            ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, 0x00);
#endif

#if((_PIN_52 == 6) && (_PIN_53 == 6))
            ScalerSetByte(P10_B3_PIN_SHARE_CTRL13, 0x00);
            ScalerSetByte(P10_B4_PIN_SHARE_CTRL14, 0x00);
#endif

#if((_PIN_60 == 8) && (_PIN_61 == 8))
            ScalerSetByte(P10_B8_PIN_SHARE_CTRL18, 0x00);
            ScalerSetByte(P10_B9_PIN_SHARE_CTRL19, 0x00);
#endif

#if((_PIN_62 == 8) && (_PIN_63 == 9))
            ScalerSetByte(P10_BA_PIN_SHARE_CTRL1A, 0x00);
            ScalerSetByte(P10_BB_PIN_SHARE_CTRL1B, 0x00);
#endif

            break;

        case _HW_IIC_PIN_39_40:

            ScalerSetBit(P10_A7_PIN_SHARE_CTRL07, ~_BIT6, _BIT6);

#if((_PIN_26 == 8) && (_PIN_27 == 8))
            ScalerSetByte(P10_A5_PIN_SHARE_CTRL05, 0x00);
            ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, 0x00);
#endif

#if((_PIN_52 == 6) && (_PIN_53 == 6))
            ScalerSetByte(P10_B3_PIN_SHARE_CTRL13, 0x00);
            ScalerSetByte(P10_B4_PIN_SHARE_CTRL14, 0x00);
#endif

#if((_PIN_60 == 8) && (_PIN_61 == 8))
            ScalerSetByte(P10_B8_PIN_SHARE_CTRL18, 0x00);
            ScalerSetByte(P10_B9_PIN_SHARE_CTRL19, 0x00);
#endif

#if((_PIN_62 == 8) && (_PIN_63 == 9))
            ScalerSetByte(P10_BA_PIN_SHARE_CTRL1A, 0x00);
            ScalerSetByte(P10_BB_PIN_SHARE_CTRL1B, 0x00);
#endif

            break;

        case _HW_IIC_PIN_52_53:

            ScalerSetBit(P10_B3_PIN_SHARE_CTRL13, ~_BIT7, _BIT7);

#if((_PIN_26 == 8) && (_PIN_27 == 8))
            ScalerSetByte(P10_A5_PIN_SHARE_CTRL05, 0x00);
            ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, 0x00);
#endif

#if((_PIN_39 == 7) && (_PIN_40 == 7))
            ScalerSetByte(P10_A7_PIN_SHARE_CTRL07, 0x00);
            ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, 0x00);
#endif

#if((_PIN_60 == 8) && (_PIN_61 == 8))
            ScalerSetByte(P10_B8_PIN_SHARE_CTRL18, 0x00);
            ScalerSetByte(P10_B9_PIN_SHARE_CTRL19, 0x00);
#endif

#if((_PIN_62 == 8) && (_PIN_63 == 9))
            ScalerSetByte(P10_BA_PIN_SHARE_CTRL1A, 0x00);
            ScalerSetByte(P10_BB_PIN_SHARE_CTRL1B, 0x00);
#endif

            break;

        case _HW_IIC_PIN_60_61:

            ScalerSetBit(P10_B8_PIN_SHARE_CTRL18, ~(_BIT6 | _BIT5), _BIT5);

#if((_PIN_26 == 8) && (_PIN_27 == 8))
            ScalerSetByte(P10_A5_PIN_SHARE_CTRL05, 0x00);
            ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, 0x00);
#endif

#if((_PIN_39 == 7) && (_PIN_40 == 7))
            ScalerSetByte(P10_A7_PIN_SHARE_CTRL07, 0x00);
            ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, 0x00);
#endif

#if((_PIN_52 == 6) && (_PIN_53 == 6))
            ScalerSetByte(P10_B3_PIN_SHARE_CTRL13, 0x00);
            ScalerSetByte(P10_B4_PIN_SHARE_CTRL14, 0x00);
#endif

#if((_PIN_62 == 8) && (_PIN_63 == 9))
            ScalerSetByte(P10_BA_PIN_SHARE_CTRL1A, 0x00);
            ScalerSetByte(P10_BB_PIN_SHARE_CTRL1B, 0x00);
#endif

            break;

        case _HW_IIC_PIN_62_63:

            ScalerSetBit(P10_BA_PIN_SHARE_CTRL1A, ~(_BIT7 | _BIT6), _BIT6);

#if((_PIN_26 == 8) && (_PIN_27 == 8))
            ScalerSetByte(P10_A5_PIN_SHARE_CTRL05, 0x00);
            ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, 0x00);
#endif

#if((_PIN_39 == 7) && (_PIN_40 == 7))
            ScalerSetByte(P10_A7_PIN_SHARE_CTRL07, 0x00);
            ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, 0x00);
#endif

#if((_PIN_52 == 6) && (_PIN_53 == 6))
            ScalerSetByte(P10_B3_PIN_SHARE_CTRL13, 0x00);
            ScalerSetByte(P10_B4_PIN_SHARE_CTRL14, 0x00);
#endif

#if((_PIN_60 == 8) && (_PIN_61 == 8))
            ScalerSetByte(P10_B8_PIN_SHARE_CTRL18, 0x00);
            ScalerSetByte(P10_B9_PIN_SHARE_CTRL19, 0x00);
#endif

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
            ScalerSetBit(P10_B6_PIN_SHARE_CTRL16, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | ((BYTE)_GPIO_OPEN_DRAIN))); // Page 10-B6 Pin 56[3:0]
            ScalerSetByte(P10_B7_PIN_SHARE_CTRL17, (BYTE)_GPIO_OPEN_DRAIN); // Page 10-B7 Pin 57
        break;

        case _DDC1_SWITCH_DDC:
            ScalerSetBit(P10_B6_PIN_SHARE_CTRL16, ~_BIT7, 0x00); // Page 10-B6 Pin 56[3:0]
        break;

        case _DDC2_SWITCH_GPIO:
            ScalerSetBit(P10_DF_PIN_SHARE_CTRL3F, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | (BYTE)_GPIO_OPEN_DRAIN)); // Page 10-DF Pin 125[2:0]
            ScalerSetByte(P10_E0_PIN_SHARE_CTRL40, (BYTE)_GPIO_OPEN_DRAIN); // Page 10-E0 Pin 126
        break;

        case _DDC2_SWITCH_DDC:
            ScalerSetBit(P10_DF_PIN_SHARE_CTRL3F, ~_BIT7, 0x00); // Enable DDC
        break;

        case _DDC3_SWITCH_GPIO:
            ScalerSetBit(P10_DD_PIN_SHARE_CTRL3D, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | (BYTE)_GPIO_OPEN_DRAIN)); // Page 10-DD Pin 123[2:0]
            ScalerSetByte(P10_DE_PIN_SHARE_CTRL3E, (BYTE)_GPIO_OPEN_DRAIN); // Page 10-DE Pin 124
        break;

        case _DDC3_SWITCH_DDC:
            ScalerSetBit(P10_DD_PIN_SHARE_CTRL3D, ~_BIT7, 0x00); // Enable DDC
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
        case _CONFIG_PIN_1:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_26:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_27:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~_BIT7, 0x00);
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~_BIT7, 0x00);
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~_BIT7, 0x00);
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_51:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM0_PP:
                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM0_OD:
                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_54:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B5_PIN_SHARE_CTRL15, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B5_PIN_SHARE_CTRL15, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_B5_PIN_SHARE_CTRL15, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM0_PP:
                    ScalerSetBit(P10_B5_PIN_SHARE_CTRL15, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM0_OD:
                    ScalerSetBit(P10_B5_PIN_SHARE_CTRL15, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_64:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_BC_PIN_SHARE_CTRL1C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_BC_PIN_SHARE_CTRL1C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_BC_PIN_SHARE_CTRL1C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_87:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_C7_PIN_SHARE_CTRL27, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_C7_PIN_SHARE_CTRL27, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_C7_PIN_SHARE_CTRL27, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_89:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_C9_PIN_SHARE_CTRL29, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_C9_PIN_SHARE_CTRL29, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_C9_PIN_SHARE_CTRL29, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_90:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_CA_PIN_SHARE_CTRL2A, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_CA_PIN_SHARE_CTRL2A, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_CA_PIN_SHARE_CTRL2A, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM1_PP:
                    ScalerSetBit(P10_CA_PIN_SHARE_CTRL2A, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                case _PWM1_OD:
                    ScalerSetBit(P10_CA_PIN_SHARE_CTRL2A, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_91:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_CB_PIN_SHARE_CTRL2B, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_CB_PIN_SHARE_CTRL2B, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_CB_PIN_SHARE_CTRL2B, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

         case _CONFIG_PIN_93:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_CD_PIN_SHARE_CTRL2D, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_CD_PIN_SHARE_CTRL2D, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_CD_PIN_SHARE_CTRL2D, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

          case _CONFIG_PIN_94:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_CE_PIN_SHARE_CTRL2E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_CE_PIN_SHARE_CTRL2E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_CE_PIN_SHARE_CTRL2E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_CE_PIN_SHARE_CTRL2E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_CE_PIN_SHARE_CTRL2E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

                default:
                    break;
            }

            break;

          case _CONFIG_PIN_95:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_CF_PIN_SHARE_CTRL2F, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_CF_PIN_SHARE_CTRL2F, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_CF_PIN_SHARE_CTRL2F, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_97:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D1_PIN_SHARE_CTRL31, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D1_PIN_SHARE_CTRL31, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D1_PIN_SHARE_CTRL31, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_99:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL33, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL33, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL33, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_101:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D5_PIN_SHARE_CTRL35, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D5_PIN_SHARE_CTRL35, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D5_PIN_SHARE_CTRL35, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_102:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D6_PIN_SHARE_CTRL36, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D6_PIN_SHARE_CTRL36, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D6_PIN_SHARE_CTRL36, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_105:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D7_PIN_SHARE_CTRL37, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D7_PIN_SHARE_CTRL37, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D7_PIN_SHARE_CTRL37, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_106:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D8_PIN_SHARE_CTRL38, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D8_PIN_SHARE_CTRL38, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D8_PIN_SHARE_CTRL38, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_107:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL39, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL39, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL39, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_109:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_DA_PIN_SHARE_CTRL3A, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_DA_PIN_SHARE_CTRL3A, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_DA_PIN_SHARE_CTRL3A, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_110:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_DB_PIN_SHARE_CTRL3B, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_DB_PIN_SHARE_CTRL3B, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_DB_PIN_SHARE_CTRL3B, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_119:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_DC_PIN_SHARE_CTRL3C, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_DC_PIN_SHARE_CTRL3C, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_DC_PIN_SHARE_CTRL3C, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        default:
            break;

    }
}
