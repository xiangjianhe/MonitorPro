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
// ID Code      : RL6297_Series_Pinshare.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6297_SERIES_PINSHARE__

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
    ScalerSetByte(P10_A0_PIN_SHARE_CTRL00, (BYTE)_PIN_31); // Page 10-A0 Pin 31
    ScalerSetByte(P10_A1_PIN_SHARE_CTRL01, (BYTE)_PIN_32); // Page 10-A1 Pin 32
	ScalerSetByte(P10_A2_PIN_SHARE_CTRL02, (BYTE)_PIN_33); // Page 10-A2 Pin 33
	ScalerSetByte(P10_A3_PIN_SHARE_CTRL03, (BYTE)_PIN_34); // Page 10-A3 Pin 34
    ScalerSetByte(P10_A4_PIN_SHARE_CTRL04, (BYTE)_PIN_35); // Page 10-A4 Pin 35
	ScalerSetByte(P10_A5_PIN_SHARE_CTRL05, (BYTE)_PIN_36); // Page 10-A5 Pin 36
	ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, (BYTE)_PIN_37); // Page 10-A6 Pin 37
    ScalerSetByte(P10_A7_PIN_SHARE_CTRL07, (BYTE)_PIN_39); // Page 10-A7 Pin 39
	ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, (BYTE)_PIN_40); // Page 10-A8 Pin 40
	ScalerSetByte(P10_A9_PIN_SHARE_CTRL09, (BYTE)_PIN_41); // Page 10-A9 Pin 41

	// Check if pin 42-43 are assigned to IIC
#if(_PIN_42 == 6) && (_PIN_43 == 6)
    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~_BIT7, _BIT7); // Enable IIC
#else
    ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, (BYTE)_PIN_42); // Page 10-AA Pin 42
	ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, (BYTE)_PIN_43); // Page 10-AB Pinv43
    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~_BIT7, 0x00); // Disable IIC
#endif

    ScalerSetByte(P10_AC_PIN_SHARE_CTRL0C, (BYTE)_PIN_44); // Page 10-AC Pin 44
    ScalerSetByte(P10_AD_PIN_SHARE_CTRL0D, (BYTE)_PIN_45); // Page 10-AD Pin 45
	ScalerSetByte(P10_AE_PIN_SHARE_CTRL0E, (BYTE)_PIN_46); // Page 10-AE Pin 46
	ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), ((BYTE)_PIN_47 << 1)); // Page 10-AF Pin 47
    ScalerSetByte(P10_B0_PIN_SHARE_CTRL10, (BYTE)_PIN_48); // Page 10-B0 Pin 48
	ScalerSetByte(P10_B1_PIN_SHARE_CTRL11, (BYTE)_PIN_50); // Page 10-B1 Pin 50
	ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), ((BYTE)_PIN_51 << 2)); // Page 10-B2 Pin 51

    ScalerSetBit(P10_B9_PIN_SHARE_CTRL16, ~(_BIT5 | _BIT4), (BYTE)_P41_48_SEL << 4); // Page 10-B9 Pin 40

	ScalerSetByte(P10_D0_PIN_SHARE_CTRL13, (BYTE)_PIN_52); // Page 10-D0 Pin 52
    ScalerSetByte(P10_D1_PIN_SHARE_CTRL14, (BYTE)_PIN_53); // Page 10-D1 Pin 53
	ScalerSetByte(P10_D2_PIN_SHARE_CTRL15, (BYTE)_PIN_54); // Page 10-D2 Pin 54
	ScalerSetByte(P10_D3_PIN_SHARE_CTRL16, (BYTE)_PIN_55); // Page 10-D3 Pin 55

	// Check if pin 56-57 are assigned to IIC or IIC_AUX
#if((_PIN_56 == 8) && (_PIN_57 == 8))
    ScalerSetBit(P10_D4_PIN_SHARE_CTRL17, ~(_BIT7 | _BIT6), _BIT6); // Enable HWIIC
#elif(_PIN_56 == 9) && (_PIN_57 == 9)
    ScalerSetBit(P10_D4_PIN_SHARE_CTRL17, ~(_BIT7 | _BIT6), _BIT7); // Enable IIC_AUX
#else
    ScalerSetByte(P10_D4_PIN_SHARE_CTRL17, (BYTE)_PIN_56); // Page 10-D4 Pin 56
	ScalerSetByte(P10_D5_PIN_SHARE_CTRL18, (BYTE)_PIN_57); // Page 10-D5 Pin 57
    ScalerSetBit(P10_D4_PIN_SHARE_CTRL17,  ~(_BIT7 | _BIT6), 0x00); // Disable HWIIC
#endif


    // Check if pin 58-59 are assigned to DDC1
#if(_PIN_58 == 9) && (_PIN_59 == 9)
    ScalerSetByte(P10_D6_PIN_SHARE_CTRL19, ((BYTE)_PIN_58_59_DDC1_to_52_53)); // Page 10-D6 Pin 58
    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#else
    ScalerSetByte(P10_D6_PIN_SHARE_CTRL19, ((BYTE)_PIN_58 << 1) | (_PIN_58_59_DDC1_to_52_53)); // Page 10-D6 Pin 58
	ScalerSetByte(P10_D7_PIN_SHARE_CTRL1A, (BYTE)_PIN_59); // Page 10-D6 Pin 59
    ScalerSetBit(P10_D6_PIN_SHARE_CTRL19, ~_BIT7, _BIT7); // Disable DDC1
#endif

	ScalerSetByte(P10_D8_PIN_SHARE_CTRL1B, (BYTE)_PIN_63); // Page 10-D8 Pin 63
    ScalerSetByte(P10_D9_PIN_SHARE_CTRL1C, (BYTE)_PIN_64); // Page 10-D9 Pin 64
    ScalerSetByte(P10_DA_PIN_SHARE_CTRL1D, (BYTE)_PIN_65); // Page 10-DA Pin 65
    ScalerSetByte(P10_DB_PIN_SHARE_CTRL1E, (BYTE)_PIN_66); // Page 10-D4 Pin 66
	ScalerSetByte(P10_DC_PIN_SHARE_CTRL1F, (BYTE)_PIN_67); // Page 10-D5 Pin 67
	ScalerSetByte(P10_DD_PIN_SHARE_CTRL20, (BYTE)_PIN_68); // Page 10-D8 Pin 68

    //check if pin 69-70 are assigned to  DDC2P or IIC
#if(_PIN_69 == 10) && (_PIN_70 == 10)
    ScalerSetBit(P10_DE_PIN_SHARE_CTRL21, ~_BIT7, _BIT7); // Enable IIC
#else
    ScalerSetByte(P10_DE_PIN_SHARE_CTRL21, (BYTE)_PIN_69); // Page 10-DE Pin 69
	ScalerSetByte(P10_DF_PIN_SHARE_CTRL22, (BYTE)_PIN_70); // Page 10-DF Pin 70
    ScalerSetBit(P10_DE_PIN_SHARE_CTRL21, ~_BIT7 , 0x00); // Disable DDC2P and IIC
#endif

    ScalerSetByte(P10_E0_PIN_SHARE_CTRL23, (BYTE)_PIN_71); // Page 10-E0 Pin 71
	ScalerSetByte(P10_E1_PIN_SHARE_CTRL24, (BYTE)_PIN_72); // Page 10-E1 Pin 72
	ScalerSetByte(P10_E2_PIN_SHARE_CTRL25, (BYTE)_PIN_74_75_76_77_78_79_80_81_82_83); // Page 10-E2 _PIN_74_75_76_77_78_79_80_81_82_83
	ScalerSetByte(P10_E3_PIN_SHARE_CTRL26, ((BYTE)_PIN_74 << 6 ) | ( _PIN_75 << 4 )| (_PIN_78 << 2)| (_PIN_79)); // Page 10-E3 _PIN_74_75_78_79
	ScalerSetByte(P10_E4_PIN_SHARE_CTRL27, (BYTE)_PIN_96); // Page 10-E4 _PIN_96
	ScalerSetByte(P10_E5_PIN_SHARE_CTRL28, (BYTE)_PIN_97); // Page 10-E5 Pin 97
	ScalerSetByte(P10_E6_PIN_SHARE_CTRL29, (BYTE)_PIN_98); // Page 10-E6 Pin 98
	ScalerSetByte(P10_E7_PIN_SHARE_CTRL2A, (BYTE)_PIN_99); // Page 10-E7 Pin 99
	ScalerSetByte(P10_E8_PIN_SHARE_CTRL2B, (BYTE)_PIN_100); // Page 10-E8 Pin 100
	ScalerSetByte(P10_E9_PIN_SHARE_CTRL2C, (BYTE)_PIN_101); // Page 10-E9 Pin 101
	ScalerSetByte(P10_EA_PIN_SHARE_CTRL2D, (BYTE)_PIN_102); // Page 10-EA Pin 102

    //check if pin 102-103 are assigned to  IIC or IIC_AUX
#if(_PIN_103 == 11) && (_PIN_104 == 10)
    ScalerSetBit(P10_EB_PIN_SHARE_CTRL2E, ~(_BIT7 | _BIT6), _BIT6); // Enable IIC
#elif(_PIN_103 == 12) && (_PIN_104 == 11)
    ScalerSetBit(P10_EB_PIN_SHARE_CTRL2E, ~(_BIT7 | _BIT6), _BIT7); // Enable IIC_AUX
#else
    ScalerSetByte(P10_EB_PIN_SHARE_CTRL2E, (BYTE)_PIN_103); // Page 10-EB Pin 103
	ScalerSetByte(P10_EC_PIN_SHARE_CTRL2F, (BYTE)_PIN_104); // Page 10-EC Pin 104
    ScalerSetBit(P10_EB_PIN_SHARE_CTRL2E, ~(_BIT7 | _BIT6), 0x00); // Disable DDC2P  and IIC_AUX
#endif

   	ScalerSetByte(P10_ED_PIN_SHARE_CTRL30, (BYTE)_PIN_105); // Page 10-ED Pin 105
	ScalerSetByte(P10_EE_PIN_SHARE_CTRL31, (BYTE)_PIN_108); // Page 10-EE Pin 108
	ScalerSetByte(P10_EF_PIN_SHARE_CTRL32, (BYTE)_PIN_109); // Page 10-EF Pin 109
	ScalerSetByte(P10_F0_PIN_SHARE_CTRL33, (BYTE)_PIN_110); // Page 10-F0 PIN 110
	ScalerSetByte(P10_F1_PIN_SHARE_CTRL34, (BYTE)_PIN_111); // Page 10-F1 Pin 111
	ScalerSetByte(P10_F2_PIN_SHARE_CTRL35, (BYTE)_PIN_112); // Page 10-F2 Pin 112
	ScalerSetByte(P10_F3_PIN_SHARE_CTRL36, (BYTE)_PIN_113); // Page 10-F3 Pin 113
	ScalerSetByte(P10_F4_PIN_SHARE_CTRL37, (BYTE)_PIN_114); // Page 10-F4 Pin 114
	ScalerSetByte(P10_F5_PIN_SHARE_CTRL38, (BYTE)_PIN_119); // Page 10-F5 PIN 119

    // Check if pin 121-122 are assigned to DDC3
#if(_PIN_121 == 7) && (_PIN_122 == 7)
    ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#else
	ScalerSetByte(P10_F6_PIN_SHARE_CTRL39, (BYTE)_PIN_121); // Page 10-F6 Pin 121
	ScalerSetByte(P10_F7_PIN_SHARE_CTRL3A, (BYTE)_PIN_122); // Page 10-F7 PIN 122
    ScalerSetBit(P10_F6_PIN_SHARE_CTRL39, ~_BIT7, _BIT7); // Disable DDC3
#endif

// Check if pin 123-124 are assigned to DDC2
#if(_PIN_123 == 7) && (_PIN_124 == 7)
    ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#else
	ScalerSetByte(P10_F8_PIN_SHARE_CTRL3B, (BYTE)_PIN_123); // Page 10-F6 Pin 123
	ScalerSetByte(P10_F9_PIN_SHARE_CTRL3C, (BYTE)_PIN_124); // Page 10-F7 PIN 124
    ScalerSetBit(P10_F8_PIN_SHARE_CTRL3B, ~_BIT7, _BIT7); // Disable DDC2
#endif

	ScalerSetByte(P10_FA_PIN_SHARE_CTRL3D, (BYTE)_PIN_126); // Page 10-FA Pin 126

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

        ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~_BIT7, _BIT7);

#if((_PIN_56 == 8) && (_PIN_57 == 8))
        ScalerSetByte(P10_D4_PIN_SHARE_CTRL17, 0x00);
        ScalerSetByte(P10_D5_PIN_SHARE_CTRL18, 0x00);
#endif

#if((_PIN_69 == 13) && (_PIN_70 == 13))
        ScalerSetByte(P10_DE_PIN_SHARE_CTRL21, 0x00);
        ScalerSetByte(P10_DF_PIN_SHARE_CTRL22, 0x00);
#endif

#if((_PIN_103 == 11) && (_PIN_104 == 10))
        ScalerSetByte(P10_EB_PIN_SHARE_CTRL2E, 0x00);
        ScalerSetByte(P10_EC_PIN_SHARE_CTRL2F, 0x00);
#endif

            break;

        case _HW_IIC_PIN_56_57:

        ScalerSetBit(P10_D4_PIN_SHARE_CTRL17, ~(_BIT7 | _BIT6), _BIT6);

#if((_PIN_42 == 6) && (_PIN_43 == 6))
        ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, 0x00);
        ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, 0x00);
#endif

#if((_PIN_69 == 13) && (_PIN_70 == 13))
        ScalerSetByte(P10_DE_PIN_SHARE_CTRL21, 0x00);
        ScalerSetByte(P10_DF_PIN_SHARE_CTRL22, 0x00);
#endif

#if((_PIN_103 == 11) && (_PIN_104 == 10))
        ScalerSetByte(P10_EB_PIN_SHARE_CTRL2E, 0x00);
        ScalerSetByte(P10_EC_PIN_SHARE_CTRL2F, 0x00);
#endif
            break;

        case _HW_IIC_PIN_69_70:

        ScalerSetBit(P10_DE_PIN_SHARE_CTRL21, ~_BIT7, _BIT7);

#if((_PIN_42 == 6) && (_PIN_43 == 6))
        ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, 0x00);
        ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, 0x00);
#endif

#if((_PIN_56 == 8) && (_PIN_57 == 8))
        ScalerSetByte(P10_D4_PIN_SHARE_CTRL17, 0x00);
        ScalerSetByte(P10_D5_PIN_SHARE_CTRL18, 0x00);
#endif

#if((_PIN_103 == 11) && (_PIN_104 == 10))
        ScalerSetByte(P10_EB_PIN_SHARE_CTRL2E, 0x00);
        ScalerSetByte(P10_EC_PIN_SHARE_CTRL2F, 0x00);
#endif

            break;

        case _HW_IIC_PIN_103_104:

        ScalerSetBit(P10_EB_PIN_SHARE_CTRL2E, ~(_BIT7 | _BIT6), _BIT6);

#if((_PIN_42 == 6) && (_PIN_43 == 6))
        ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, 0x00);
        ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, 0x00);
#endif

#if((_PIN_56 == 8) && (_PIN_57 == 8))
        ScalerSetByte(P10_D4_PIN_SHARE_CTRL17, 0x00);
        ScalerSetByte(P10_D5_PIN_SHARE_CTRL18, 0x00);
#endif

#if((_PIN_69 == 13) && (_PIN_70 == 13))
        ScalerSetByte(P10_DE_PIN_SHARE_CTRL21, 0x00);
        ScalerSetByte(P10_DF_PIN_SHARE_CTRL22, 0x00);
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
            ScalerSetByte(P10_D6_PIN_SHARE_CTRL19, ((BYTE)_GPIO_OPEN_DRAIN << 1) | (_PIN_58_59_DDC1_to_52_53)); // Page 10-D6 Pin 58
        	ScalerSetByte(P10_D7_PIN_SHARE_CTRL1A, (BYTE)_GPIO_OPEN_DRAIN); // Page 10-D6 Pin 59
            ScalerSetBit(P10_D6_PIN_SHARE_CTRL19, ~_BIT7, _BIT7); // Disable DDC1
        break;

        case _DDC1_SWITCH_DDC:
            ScalerSetBit(P10_D6_PIN_SHARE_CTRL19, ~_BIT7, 0x00); // Enable DDC1
        break;

        case _DDC2_SWITCH_GPIO:
        	ScalerSetByte(P10_F8_PIN_SHARE_CTRL3B, (BYTE)_GPIO_OPEN_DRAIN); // Page 10-F6 Pin 123
        	ScalerSetByte(P10_F9_PIN_SHARE_CTRL3C, (BYTE)_GPIO_OPEN_DRAIN); // Page 10-F7 PIN 124
            ScalerSetBit(P10_F8_PIN_SHARE_CTRL3B, ~_BIT7, _BIT7); // Disable DDC2
        break;

        case _DDC2_SWITCH_DDC:
            ScalerSetBit(P10_F8_PIN_SHARE_CTRL3B, ~_BIT7, 0x00); // Enable DDC2
        break;

        case _DDC3_SWITCH_GPIO:
        	ScalerSetByte(P10_F6_PIN_SHARE_CTRL39, (BYTE)_GPIO_OPEN_DRAIN); // Page 10-F6 Pin 121
        	ScalerSetByte(P10_F7_PIN_SHARE_CTRL3A, (BYTE)_GPIO_OPEN_DRAIN); // Page 10-F7 PIN 122
            ScalerSetBit(P10_F6_PIN_SHARE_CTRL39, ~_BIT7, _BIT7); // Disable DDC3
        break;

        case _DDC3_SWITCH_DDC:
            ScalerSetBit(P10_F6_PIN_SHARE_CTRL39, ~_BIT7, 0x00); // Enable DDC3
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
        case _CONFIG_128PIN_PIN_31:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A0_PIN_SHARE_CTRL00, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_32:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A1_PIN_SHARE_CTRL01, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_33:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_34:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A3_PIN_SHARE_CTRL03, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A3_PIN_SHARE_CTRL03, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A3_PIN_SHARE_CTRL03, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_35:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A4_PIN_SHARE_CTRL04, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A4_PIN_SHARE_CTRL04, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A4_PIN_SHARE_CTRL04, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_36:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_37:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A6_PIN_SHARE_CTRL06, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_39:
        case _CONFIG_76PIN_PIN21:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A7_PIN_SHARE_CTRL07, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A7_PIN_SHARE_CTRL07, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A7_PIN_SHARE_CTRL07, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_40:
        case _CONFIG_76PIN_PIN22:

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

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN23:

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

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN24:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN25:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_AB_PIN_SHARE_CTRL0B, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_AB_PIN_SHARE_CTRL0B, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_AB_PIN_SHARE_CTRL0B, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_54:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D2_PIN_SHARE_CTRL15, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D2_PIN_SHARE_CTRL15, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D2_PIN_SHARE_CTRL15, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM4_PP:
                    ScalerSetBit(P10_D2_PIN_SHARE_CTRL15, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM4_OD:
                    ScalerSetBit(P10_D2_PIN_SHARE_CTRL15, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_55:
        case _CONFIG_76PIN_PIN30:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL16, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL16, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL16, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM1_PP:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL16, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM1_OD:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL16, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                case _PWM5_PP:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL16, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

                case _PWM5_OD:
                    ScalerSetBit(P10_D3_PIN_SHARE_CTRL16, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_63:
        case _CONFIG_76PIN_PIN37:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D8_PIN_SHARE_CTRL1B, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D8_PIN_SHARE_CTRL1B, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D8_PIN_SHARE_CTRL1B, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM2_PP:
                    ScalerSetBit(P10_D8_PIN_SHARE_CTRL1B, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM2_OD:
                    ScalerSetBit(P10_D8_PIN_SHARE_CTRL1B, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN38:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL1C, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL1C, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL1C, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM0_PP:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL1C, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM0_OD:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL1C, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL1C, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_D9_PIN_SHARE_CTRL1C, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_72:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_E1_PIN_SHARE_CTRL24, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_E1_PIN_SHARE_CTRL24, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_E1_PIN_SHARE_CTRL24, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_E1_PIN_SHARE_CTRL24, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_E1_PIN_SHARE_CTRL24, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_96:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_E4_PIN_SHARE_CTRL27, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_E4_PIN_SHARE_CTRL27, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_E4_PIN_SHARE_CTRL27, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM0_PP:
                    ScalerSetBit(P10_E4_PIN_SHARE_CTRL27, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM0_OD:
                    ScalerSetBit(P10_E4_PIN_SHARE_CTRL27, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_97:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_E5_PIN_SHARE_CTRL28, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_E5_PIN_SHARE_CTRL28, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_E5_PIN_SHARE_CTRL28, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM1_PP:
                    ScalerSetBit(P10_E5_PIN_SHARE_CTRL28, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM1_OD:
                    ScalerSetBit(P10_E5_PIN_SHARE_CTRL28, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_98:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_E6_PIN_SHARE_CTRL29, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_E6_PIN_SHARE_CTRL29, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_E6_PIN_SHARE_CTRL29, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM2_PP:
                    ScalerSetBit(P10_E6_PIN_SHARE_CTRL29, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM2_OD:
                    ScalerSetBit(P10_E6_PIN_SHARE_CTRL29, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_99:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_E7_PIN_SHARE_CTRL2A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_E7_PIN_SHARE_CTRL2A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_E7_PIN_SHARE_CTRL2A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_E7_PIN_SHARE_CTRL2A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_E7_PIN_SHARE_CTRL2A, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_100:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_E8_PIN_SHARE_CTRL2B, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_E8_PIN_SHARE_CTRL2B, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_E8_PIN_SHARE_CTRL2B, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM4_PP:
                    ScalerSetBit(P10_E8_PIN_SHARE_CTRL2B, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM4_OD:
                    ScalerSetBit(P10_E8_PIN_SHARE_CTRL2B, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_128PIN_PIN_101:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_E9_PIN_SHARE_CTRL2C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_E9_PIN_SHARE_CTRL2C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_E9_PIN_SHARE_CTRL2C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM5_PP:
                    ScalerSetBit(P10_E9_PIN_SHARE_CTRL2C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM5_OD:
                    ScalerSetBit(P10_E9_PIN_SHARE_CTRL2C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN59:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_F0_PIN_SHARE_CTRL33, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_F0_PIN_SHARE_CTRL33, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_F0_PIN_SHARE_CTRL33, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN60:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_F1_PIN_SHARE_CTRL34, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_F1_PIN_SHARE_CTRL34, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_F1_PIN_SHARE_CTRL34, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN61:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_F2_PIN_SHARE_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_F2_PIN_SHARE_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_F2_PIN_SHARE_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN63:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_F4_PIN_SHARE_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_F4_PIN_SHARE_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_F4_PIN_SHARE_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM4_PP:
                    ScalerSetBit(P10_F4_PIN_SHARE_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM4_OD:
                    ScalerSetBit(P10_F4_PIN_SHARE_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN68:

            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_F5_PIN_SHARE_CTRL38, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_F5_PIN_SHARE_CTRL38, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_F5_PIN_SHARE_CTRL38, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _PWM1_PP:
                    ScalerSetBit(P10_F5_PIN_SHARE_CTRL38, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM1_OD:
                    ScalerSetBit(P10_F5_PIN_SHARE_CTRL38, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                case _PWM5_PP:
                    ScalerSetBit(P10_F5_PIN_SHARE_CTRL38, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

                case _PWM5_OD:
                    ScalerSetBit(P10_F5_PIN_SHARE_CTRL38, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
                    break;

                default:
                    break;
            }

            break;

        default:
            break;
    }
}

