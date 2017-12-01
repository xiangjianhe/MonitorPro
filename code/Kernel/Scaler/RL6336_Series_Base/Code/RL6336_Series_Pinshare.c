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
// ID Code      : RL6336_Series_Pinshare.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6336_SERIES_PINSHARE__

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

#if(_PANEL_SWITCH_PAD_SUPPORT == _ON)
void ScalerPinsharePanelSwitchControl(bit bPanelControl);
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
    // Set SPL clock/data driving to 4mA
    ScalerSetBit(P10_C3_PIN_DRIVING_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT4 | _BIT1));

    // Pull high for unbound pin
    ScalerSetByte(P10_B8_PIN_SHARE_CTRL18, 0x01); // PP

    ScalerSetByte(P10_A5_PIN_SHARE_CTRL05, (BYTE)_PIN_21); // Page 10-A5 Pin 21
    ScalerSetByte(P10_A1_PIN_SHARE_CTRL01, (BYTE)_PIN_22); // Page 10-A1 Pin 22
    ScalerSetByte(P10_A2_PIN_SHARE_CTRL02, (BYTE)_PIN_23); // Page 10-A2 Pin 23
    ScalerSetByte(P10_A3_PIN_SHARE_CTRL03, (BYTE)_PIN_24); // Page 10-A3 Pin 24
    ScalerSetByte(P10_A4_PIN_SHARE_CTRL04, (BYTE)_PIN_25); // Page 10-A4 Pin 25
    ScalerSetByte(P10_A0_PIN_SHARE_CTRL00, (BYTE)_PIN_26); // Page 10-A0 Pin 26
    ScalerSetByte(P10_A6_PIN_SHARE_CTRL06, (BYTE)_PIN_27); // Page 10-A6 Pin 27
    ScalerSetByte(P10_A7_PIN_SHARE_CTRL07, (BYTE)_PIN_28); // Page 10-A7 Pin 28
    ScalerSetByte(P10_A8_PIN_SHARE_CTRL08, (BYTE)_PIN_29); // Page 10-A8 Pin 29
    ScalerSetByte(P10_A9_PIN_SHARE_CTRL09, (BYTE)_PIN_30); // Page 10-A9 Pin 30

    // Check if pin 31-32 are assigned to IIC
#if((_PIN_31 == 7) && (_PIN_32 == 5))
    ScalerSetBit(P10_AA_PIN_SHARE_CTRL0A, ~_BIT7, _BIT7);
#else
    ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, (BYTE)_PIN_31); // Page 10-AA Pin 31
    ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, (BYTE)_PIN_32); // Page 10-AB Pin 32
#endif

    // Check if pin 33-34 are assigned to DDC1
#if((_PIN_33 == 6) && (_PIN_34 == 8))
    ScalerSetBit(P10_AC_PIN_SHARE_CTRL0C, ~_BIT5, (_PIN_33_34_DDC1_to_28_29 << 5));
    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#else
    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
    ScalerSetBit(P10_AC_PIN_SHARE_CTRL0C, ~(_BIT2 | _BIT1 | _BIT0), (BYTE)_PIN_33); // Page 10-AC Pin 33
    ScalerSetByte(P10_AD_PIN_SHARE_CTRL0D, (BYTE)_PIN_34); // Page 10-AD Pin 34
#endif

    ScalerSetByte(P10_AE_PIN_SHARE_CTRL0E, (BYTE)_PIN_37); // Page 10-AE Pin 37

#if(_PANEL_SWITCH_PAD_SUPPORT == _ON)
    // Switch to panel swtich mode
    ScalerSetByte(P10_AF_PIN_SHARE_CTRL0F, 0x0B); // Page 10-AF Pin 38

    // Set panel switch driving current
    ScalerSetByte(P10_CF_PANEL_SWITCH_CTRL0, ((_PANEL_SWITCH_DRIVING << 3) | (_PANEL_SWITCH_CURRENT & 0x07)));

    // Default driving in panel switch mode
    ScalerSetBit(P10_C2_PIN_DRIVING_CTRL0, ~_BIT2, 0x00);
#else
    ScalerSetByte(P10_AF_PIN_SHARE_CTRL0F, (BYTE)_PIN_38); // Page 10-AF Pin 38

    // Default in open-drain mode
    ScalerSetBit(P10_C2_PIN_DRIVING_CTRL0, ~_BIT2, _BIT2);
#endif

    ScalerSetByte(P10_B0_PIN_SHARE_CTRL10, (BYTE)_PIN_39); // Page 10-B0 Pin 39
    ScalerSetByte(P10_B1_PIN_SHARE_CTRL11, (BYTE)_PIN_40); // Page 10-B1 Pin 40
    ScalerSetByte(P10_B2_PIN_SHARE_CTRL12, (BYTE)_PIN_41); // Page 10-B2 Pin 41
    ScalerSetByte(P10_B3_PIN_SHARE_CTRL13, (BYTE)_PIN_42); // Page 10-B3 Pin 42
    ScalerSetByte(P10_B4_PIN_SHARE_CTRL14, (BYTE)_PIN_43); // Page 10-B4 Pin 43
    ScalerSetByte(P10_B5_PIN_SHARE_CTRL15, (BYTE)_PIN_44); // Page 10-B5 Pin 44
    ScalerSetByte(P10_B6_PIN_SHARE_CTRL16, (BYTE)_PIN_45); // Page 10-B6 Pin 45
    ScalerSetByte(P10_B7_PIN_SHARE_CTRL17, (BYTE)_PIN_46); // Page 10-B7 Pin 46

    ScalerSetByte(P10_B9_PIN_SHARE_CTRL19, (BYTE)_PIN_58); // Page 10-B9 Pin 58
    ScalerSetByte(P10_BA_PIN_SHARE_CTRL1A, (BYTE)_PIN_59); // Page 10-BA Pin 59
    ScalerSetByte(P10_BB_PIN_SHARE_CTRL1B, (BYTE)_PIN_60); // Page 10-BB Pin 60
    ScalerSetByte(P10_BC_PIN_SHARE_CTRL1C, (BYTE)_PIN_61); // Page 10-BC Pin 61
    ScalerSetByte(P10_BD_PIN_SHARE_CTRL1D, (BYTE)_PIN_62); // Page 10-BD Pin 62
    ScalerSetByte(P10_BE_PIN_SHARE_CTRL1E, (BYTE)_PIN_63); // Page 10-BE Pin 63

    ScalerSetByte(P10_BF_PIN_SHARE_CTRL1F, (BYTE)_PIN_68); // Page 10-BF Pin 68

    // Check if pin 70-71 are assigned to DDC2
#if((_PIN_70 == 5) && (_PIN_71 == 5))
    ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#else
    ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
    ScalerSetBit(P10_C0_PIN_SHARE_CTRL20, ~(_BIT2 | _BIT1 | _BIT0), (BYTE)_PIN_70); // Page 10-C0 Pin 70
    ScalerSetByte(P10_C1_PIN_SHARE_CTRL21, (BYTE)_PIN_71); // Page 10-C1 Pin 71
#endif

    // DDC Driving Current Set High
    ScalerSetBit(P10_C2_PIN_DRIVING_CTRL0, ~_BIT3, _BIT3);
    ScalerSetBit(P10_C3_PIN_DRIVING_CTRL1, ~_BIT0, _BIT0);

    // Xtal Spread Spectrum Disable
    ScalerSetBit(P10_C6_XTAL_SPREAD_CTRL0, ~_BIT3, 0x00);

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

#if(_PANEL_SWITCH_PAD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Toggle panel power
// Input Value  : _PANEL_CONTROL_ON or _PANEL_CONTROL_OFF
// Output Value : None
//--------------------------------------------------
void ScalerPinsharePanelSwitchControl(bit bPanelControl)
{
    bPANELPOWER = bPanelControl;

    // Additional operations for panel switch function
    if(ScalerGetByte(P10_AF_PIN_SHARE_CTRL0F) == 0x0B)
    {
        if(bPanelControl == _PANEL_CONTROL_OFF)
        {
            // Switch to panel switch mode
            ScalerSetBit(P10_C2_PIN_DRIVING_CTRL0, ~_BIT2, 0x00);
        }
        else
        {
            // Wait for panel swith pad pull low
            ScalerTimerDelayXms(_PANEL_SWITCH_WAIT_TIME);

            // Pull down to 0V by open-drain mode
            ScalerSetBit(P10_C2_PIN_DRIVING_CTRL0, ~_BIT2, _BIT2);
        }
    }
}
#endif

//--------------------------------------------------
// Description  : Switch DDC pin to GPIO or viceversa
// Input Value  : DDC1/2 switch GPIO
// Output Value : None
//--------------------------------------------------
void ScalerPinshareGpioDdcPinSwitch(BYTE ucPinType)
{
    switch(ucPinType)
    {
        case _DDC1_SWITCH_GPIO:
            ScalerSetBit(P10_AC_PIN_SHARE_CTRL0C, ~(_BIT7 | _BIT5 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | (_PIN_33_34_DDC1_to_28_29 << 5) | _GPIO_OPEN_DRAIN)); // Disable DDC1, P10-AA, Pin31
            ScalerSetByte(P10_AD_PIN_SHARE_CTRL0D, _GPIO_OPEN_DRAIN); // Page 10-AB Pin 32
            break;

        case _DDC1_SWITCH_DDC:
            ScalerSetBit(P10_AC_PIN_SHARE_CTRL0C, ~_BIT7, 0x00); // Enable DDC1
            break;

        case _DDC2_SWITCH_GPIO:
            ScalerSetBit(P10_C0_PIN_SHARE_CTRL20, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _GPIO_OPEN_DRAIN)); // Disable DDC2, P10-C0, Pin70
            ScalerSetByte(P10_C1_PIN_SHARE_CTRL21, _GPIO_OPEN_DRAIN); // Page 10-C1 Pin 71
            break;

        case _DDC2_SWITCH_DDC:
            ScalerSetBit(P10_C0_PIN_SHARE_CTRL20, ~_BIT7, 0x00); // Enable DDC2
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
        case _CONFIG_76PIN_PIN21:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _PWM0_PP:
                    ScalerSetBit(P10_A5_PIN_SHARE_CTRL05, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN22:
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

        case _CONFIG_76PIN_PIN23:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A2_PIN_SHARE_CTRL02, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN26:
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

        case _CONFIG_76PIN_PIN30:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _PWM1_OD:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM1_PP:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_A9_PIN_SHARE_CTRL09, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

               default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN37:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_AE_PIN_SHARE_CTRL0E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_AE_PIN_SHARE_CTRL0E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_AE_PIN_SHARE_CTRL0E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _PWM2_PP:
                    ScalerSetBit(P10_AE_PIN_SHARE_CTRL0E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM2_OD:
                    ScalerSetBit(P10_AE_PIN_SHARE_CTRL0E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN38:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _PWM0_PP:
                    ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
                    break;

                case _PWM0_OD:
                    ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN58:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_B9_PIN_SHARE_CTRL19, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_B9_PIN_SHARE_CTRL19, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN59:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_BA_PIN_SHARE_CTRL1A, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_BA_PIN_SHARE_CTRL1A, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN60:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_BB_PIN_SHARE_CTRL1B, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_BB_PIN_SHARE_CTRL1B, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_BB_PIN_SHARE_CTRL1B, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN61:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_BC_PIN_SHARE_CTRL1C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_BC_PIN_SHARE_CTRL1C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_BC_PIN_SHARE_CTRL1C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _PWM2_PP:
                    ScalerSetBit(P10_BC_PIN_SHARE_CTRL1C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_BC_PIN_SHARE_CTRL1C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_BC_PIN_SHARE_CTRL1C, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN62:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_BD_PIN_SHARE_CTRL1D, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_BD_PIN_SHARE_CTRL1D, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_BD_PIN_SHARE_CTRL1D, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN63:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_BE_PIN_SHARE_CTRL1E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_BE_PIN_SHARE_CTRL1E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_BE_PIN_SHARE_CTRL1E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _PWM2_PP:
                    ScalerSetBit(P10_BE_PIN_SHARE_CTRL1E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_BE_PIN_SHARE_CTRL1E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_BE_PIN_SHARE_CTRL1E, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_76PIN_PIN68:
            switch(enumConfigTyte)
            {
                case _GPI:
                    ScalerSetBit(P10_BF_PIN_SHARE_CTRL1F, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    break;

                case _GPO_PP:
                    ScalerSetBit(P10_BF_PIN_SHARE_CTRL1F, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _GPO_OD:
                    ScalerSetBit(P10_BF_PIN_SHARE_CTRL1F, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                    break;

                case _PWM3_PP:
                    ScalerSetBit(P10_BF_PIN_SHARE_CTRL1F, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
                    break;

                case _PWM3_OD:
                    ScalerSetBit(P10_BF_PIN_SHARE_CTRL1F, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                default:
                    break;
            }

            break;

        default:
            break;
    }
}