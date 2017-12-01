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
// ID Code      : RL6001_Demo_1A1DVI1H.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PCB_TYPE == _PCB_TPV_715G7430_6230_A)

#define _EXT_XTAL                               _XTAL14318K     


//--------------------------------------------------
// Input Port Define
//--------------------------------------------------
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _EMBEDDED_DDCRAM_A0_SIZE                _EDID_SIZE_NONE
#define _EMBEDDED_DDCRAM_A0_LOCATION            _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0

//--------------------------------------------------
// Input Port Search Priority Define
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _A0_INPUT_PORT

//--------------------------------------------------
// Analog Signal Swap Options
//--------------------------------------------------
#define _A0_INPUT_SWAP_RG                       _OFF                        
#define _A0_INPUT_SWAP_RB                       _OFF                        
#define _A0_INPUT_SWAP_GB                       _OFF    

//--------------------------------------------------
// Analog Hsync Schmitt Trigger Control
//--------------------------------------------------
#define _A0_HS_SCHMITT_TRIGGER_POLARITY_SEL     _POSITIVE
#define _A0_HS_SCHMITT_TRIGGER_VTH_FINE_TUNE    _DISABLE
#define _A0_HS_SCHMITT_TRIGGER_POSITIVE_VTH     _HS_SCHMITT_TRIGGER_LEVEL_10
#define _A0_HS_SCHMITT_TRIGGER_NEGATIVE_VTH     _HS_SCHMITT_TRIGGER_LEVEL_01

//--------------------------------------------------
// Definitions for Display Interface
//--------------------------------------------------
#define _LVDS_EO_SWAP                           _ENABLE             // Display Data Port Even/Odd Data Swap              
#define _LVDS_RB_SWAP                           _DISABLE            // Display Data Port Red/Blue Data Swap              
#define _LVDS_ML_SWAP                           _DISABLE            // Display Data Port MSB/LSB Data Swap    

#define _LVDS_DVS_INVERT                        _DISABLE            // DVS Output Invert Enable                
#define _LVDS_DHS_INVERT                        _DISABLE            // DHS Output Invert Enable                
#define _LVDS_DEN_INVERT                        _DISABLE            // DEN Output Invert Enable     

//--------------------------------------------------
// Definitions for LVDS
//--------------------------------------------------
#define _LVDS_MIRROR                            _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE

//--------------------------------------------------
// Definitions for LVDS EMI
//--------------------------------------------------
#define _LVDS_DATA_DRIV_CONTROL                 _LVDS_DRIV_CONTROL_3_0                  
#define _LVDS_CLK_DRIV_CONTROL                  _LVDS_DRIV_CONTROL_3_0                   

#define _LVDS_VCM_CONTROL                       _LVDS_VCM_HIGH                             
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_CAP_CONTROL                       _ENABLE
#define _LVDS_TERMINATION_CONTROL               _ENABLE

//--------------------------------------------------
// System Data Storage Options
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16               
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _SW_IIC_PIN_GPIO 

//-------------------------------------------------
// Sofware and Hardware IIC Options
//-------------------------------------------------
#define _SW_IIC_SUPPORT                         _ON
#define _SW_IIC_CLK_DIV                         _DIV_1                           

#define _HW_IIC_SUPPORT                         _OFF
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K

//--------------------------------------------------
// Definitions for PWM Setting
//--------------------------------------------------
#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _ON
#define _PWM4_EN                                _OFF
#define _PWM5_EN                                _OFF

#define _PWM0_PSAV_EN                           _OFF
#define _PWM1_PSAV_EN                           _OFF
#define _PWM2_PSAV_EN                           _OFF
#define _PWM3_PSAV_EN                           _OFF
#define _PWM4_PSAV_EN                           _OFF
#define _PWM5_PSAV_EN                           _OFF

#define _PWM0_RST_BY_DVS                        _OFF
#define _PWM1_RST_BY_DVS                        _OFF
#define _PWM2_RST_BY_DVS                        _OFF
#if(_BACKLIGHT_PWM_FREQ_SELECT == _PWMFREQ22K)//Ada.chen 20150519 modify backlight PWM freq= 22k
#define _PWM3_RST_BY_DVS                        _OFF
#else
#define _PWM3_RST_BY_DVS                        _ON
#endif
#define _PWM4_RST_BY_DVS                        _OFF
#define _PWM5_RST_BY_DVS                        _OFF

#define _BACKLIGHT_PWM                          _PWM3
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

//--------------------------------------------------
// Definitions for Low Speed ADC
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT	                _ON

//--------------------------------------------------
// RL6230 Series Pin Share
//--------------------------------------------------
//--------------------------------------------------
// RTD2270L_M Pin Share
//--------------------------------------------------
// NC Pin
#define _PIN_4                                  (0 & 0x03)  // 0 ~ 2 (0: P1D3i, 1: P1D3o<open-drain>, 2: P1D3o<push-pull>, )

// DDC
#define _PIN_18                                 (4 & 0x07)  // 0 ~ 3 (0: P3D1i, 1: P3D1o<open-drain>, 2: P3D1o<push-pull>, 3: TXD<open-drain>, 4: DDCSDA)
#define _PIN_19                                 (4 & 0x07)  // 0 ~ 3 (0: P3D0i, 1: P3D0o<open-drain>, 2: P3D0o<push-pull>, 3: RXD<open-drain>, 4: DDCSCL)

// DDC_WP
#define _PIN_20                                 (1 & 0x07)  // 0 ~ 4 (0: P5D0i, 1: P5D0o<open-drain>, 2: P5D0o<push-pull>, 3: PWM0<open-drain>, 4: PWM0<push-pull>)

// Cable Detect
#define _PIN_25                                 (0 & 0x03)  // 0 ~ 3 (0: P3D6i, 1: P3D6o<open-drain>, 2: P3D6o<push-pull>, 3: I2C_MDL_1<O>)

// Panel Enable
#define _PIN_26                                 (2 & 0x03)  // 0 ~ 3 (0: P3D7i, 1: P3D7o<open-drain>, 2: P3D7o<push-pull>, 3: I2C_MDA_1<open-drain>)

// NC Pin
#define _PIN_27                                 (0 & 0x07)  // 0 ~ 4 (0: P5D1i, 1: P5D1o<open-drain>, 2: P5D1o<push-pull>, 3: PWM1<open-drain>, 4: PWM1<push-pull>)

// FLASH_WP
#define _PIN_28                                 (2 & 0x07)  // 0 ~ 4 (0: P5D2i, 1: P5D2o<open-drain>, 2: P5D2o<push-pull>, 3: PWM2<open-drain>, 4: PWM2<push-pull>)

// NC Pin
#define _PIN_29                                 (2 & 0x03)  // 0 ~ 3 (0: P1D0i, 1: P1D0o<open-drain>, 2: P1D0o<push-pull>, 3: T2<I>)

// LVDS
#define _PIN_33                                 (3 & 0x03)  // 0 ~ 3 (0: P8D0i, 1: reserved, 2: P8D0o<push-pull>, 3: LVDS_TXE,)
#define _PIN_34                                 (3 & 0x03)  // 0 ~ 3 (0: P8D1i, 1: reserved, 2: P8D1o<push-pull>, 3: LVDS_TXE,)
#define _PIN_35                                 (3 & 0x03)  // 0 ~ 3 (0: P8D2i, 1: reserved, 2: P8D2o<push-pull>, 3: LVDS_TXE,)
#define _PIN_36                                 (3 & 0x03)  // 0 ~ 3 (0: P8D3i, 1: reserved, 2: P8D3o<push-pull>, 3: LVDS_TXE,)
#define _PIN_37                                 (3 & 0x03)  // 0 ~ 3 (0: P8D4i, 1: reserved, 2: P8D4o<push-pull>, 3: LVDS_TXE,)
#define _PIN_38                                 (3 & 0x03)  // 0 ~ 3 (0: P8D5i, 1: reserved, 2: P8D5o<push-pull>, 3: LVDS_TXE,)
#define _PIN_39                                 (3 & 0x03)  // 0 ~ 3 (0: P8D6i, 1: reserved, 2: P8D6o<push-pull>, 3: LVDS_TXE,)
#define _PIN_40                                 (3 & 0x03)  // 0 ~ 3 (0: P8D7i, 1: reserved, 2: P8D7o<push-pull>, 3: LVDS_TXE,)

// BL_EN
#define _PIN_55                                 (2 & 0x03)  // 0 ~ 3 (0: P3D3i, 1: P3D3o<open-drain>, 2: P3D3o<push-pull>, 3: INT1,)

// BL_ADJ
#define _PIN_56                                 (3 & 0x07)  // 0 ~ 5 (0: P5D3i, 1: P5D3o<open-drain>, 2: P5D3o<push-pull>, 3: PWM3<open-drain>, 4: PWM3<push-pull>, 5: CLKO1<O>)

// NC
#define _PIN_57                                 (2 & 0x03)  // 0 ~ 3 (0: P6D0i, 1: P6D0o<open-drain>, 2: P6D0o<push-pull>, 3: ADC0,)

// AD_KEY
#define _PIN_58                                 (3 & 0x03)  // 0 ~ 3 (0: P6D1i, 1: P6D1o<open-drain>, 2: P6D1o<push-pull>, 3: ADC1,)

// AD_KEY
#define _PIN_59                                 (3 & 0x07)  // 0 ~ 4 (0: P6D2i, 1: P6D2o<open-drain>, 2: P6D2o<push-pull>, 3: ADC2, 4:I2C_MDL_2A<open-drain>, )



// PC99_DET
// EEPROM WP

// LED BLUE
#define _PIN_60                                 (1 & 0x07)  // 0 ~ 4 (0: P6D3i, 1: P6D3o<open-drain>, 2: P6D3o<push-pull>, 3: ADC3, 4:I2C_MDA_2A<open-drain>, )

// LED ORANGE
#define _PIN_61                                 (1 & 0x07)  // 0 ~ 4 (0: P5D4i, 1: P5D4o<open-drain>, 2: P5D4o<push-pull>, 3: PWM4B<open-drain>, 4: PWM4B<push-pull>, )

// NC Pin
#define _PIN_62                                 (0 & 0x07)  // 0 ~ 6 (0: P5D5i, 1: P5D5o<open-drain>, 2: P5D5o<push-pull>, 3: PWM5<open-drain>, 4: PWM5<push-pull>, 5: TCON9<push-pull>, 6: I2C_MDL_2B<open-drain>)

// POWER KEY
#define _PIN_63                                 (0 & 0x07)  // 0 ~ 6 (0: P3D2i, 1: P3D2o<open-drain>, 2: P3D2o<push-pull>, 3: INT0, 4: TCON7, 5: reserved, 6: I2C_MDA_2B<open-drain>)

// NC Pin
#define _PIN_64                                 (0 & 0x03)  // 0 ~ 3 (0: P1D1i, 1: P1D1o<open-drain>, 2: P1D1o<push-pull>, 3: T2EX<I>)


//-----------------------------------------------
// Macro of Pcb Gpio Inital Setting
//-----------------------------------------------

// Enable Write Protect for EEPROM and FLASH
#define PCB_GPIO_INITIAL_SETTING()              {\
                                                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_ENABLE); \
                                                    PCB_PANEL_POWER(_PANEL_CONTROL_OFF); \
                                                    PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF); \
                                                    PCB_LED_OFF(); \                                                    
                                                }  

////////////////////////////////////////////////////////////////////////////
// Pin4,Pin26,Pin28,Pin60,Pin59 Disable pull up control                   //
// Pin55,Pin61,Pin56,Pin20,Disable pull Down control                      //
////////////////////////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~_BIT3, 0x00); \ 
                                                    ScalerSetBit(P10_B4_PIN_DRIVING_CTRL2, ~_BIT7, 0x00); \    
                                                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT3| _BIT2), 0x00);  \
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT3, 0x00); \    
                                                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT4 | _BIT3 | _BIT0), 0x00); \    
                                                }

///////////////////////////////////////////////////////////////////////////
// Pin4,Pin26,Pin28,Pin60,Pin59 Enable pull up control                   //
// Pin55,Pin61,Pin56,Pin20,enable pull Down control                      //
///////////////////////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~_BIT3, _BIT3);             \ 
                                                    ScalerSetBit(P10_B4_PIN_DRIVING_CTRL2, ~_BIT7, _BIT7);            \    
                                                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT3| _BIT2), (_BIT3| _BIT2));       \
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT3, _BIT3);             \    
                                                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT4 | _BIT3 | _BIT0), (_BIT4 | _BIT3 | _BIT0));             \    
                                                }

///////////////////////////////////////////////////////////////////////
// Pin4,Pin26,Pin28,Pin60,Pin59 Enable pull up control               //
// Pin55,Pin61,Pin56,Pin20,enable pull Down control                  //
///////////////////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~_BIT3, _BIT3);             \ 
                                                    ScalerSetBit(P10_B4_PIN_DRIVING_CTRL2, ~_BIT7, _BIT7);            \    
                                                    ScalerSetBit(P10_B8_PIN_SHARE_CTRL15, ~(_BIT3| _BIT2), (_BIT3| _BIT2));       \
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT3, _BIT3);             \    
                                                    ScalerSetBit(P10_B7_PIN_SHARE_CTRL14, ~(_BIT4 | _BIT3 | _BIT0), (_BIT4 | _BIT3 | _BIT0));             \    
                                                }          

#define PCB_GPIO_SETTING_POWER_AC_ON()          {\
                                                    PCB_GPIO_SETTING_POWER_DOWN();\
                                                }

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
#if(_BACKLIGHT_PWM_FREQ_SELECT == _PWMFREQ22K)//Ada.chen 20150519 modify backlight PWM freq= 22k
#define PCB_PWM_SETTING()                       {\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 22000); \
                                                }
#else
#define PCB_PWM_SETTING()                       {\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 240); \
                                                }
#endif
//--------------------------------------------------
// Macro of IIC
//--------------------------------------------------
sbit bSWIIC_SYS_EEPROM_SCL                      = P1 ^ 1; // NC PIN
sbit bSWIIC_SYS_EEPROM_SDA                      = P1 ^ 1; // NC PIN

#define PCB_SW_IIC_SDA_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SDA = _TRUE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SDA_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SDA = _FALSE;        \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SDA_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_EEPROM_SDA;             \
                                                    }                                          \
                                                }

#define PCB_SW_IIC_SCL_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SCL = _TRUE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SCL_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SCL = _FALSE;        \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SCL_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_EEPROM_SCL;             \
                                                    }                                          \
                                                }

//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
#define bFLASH_WRITE_PROTECT                    (MCU_PORT52_PIN_REG_FFC1)   // Pin28 P5.2

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = x;   \
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//----------------------------------------------- 
sbit bEEPROM_WRITE_PROTECT                      = P1 ^ 1; // NC PIN

#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = x;  \
                                                }

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_PORT50_PIN_REG_FFC5)   // Pin20 P5.0

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = x;    \
                                                }


//-----------------------------------------------
// Macro of Input Connect Detect
//-----------------------------------------------
sbit bA0_CONNECT                                = P3 ^ 6; // Pin 25, P3.6

#define PCB_A0_PIN()                            (SET_A0_CABLE_STATUS(!bA0_CONNECT))


//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   (MCU_PORT63_PIN_REG_FFCA) // BLUE Pin60 P6.3
#define bLED2                                   (MCU_PORT54_PIN_REG_FFC3) // ORANGE Pin61 P5.4

#define _LED_ON                                 0       // Power on  state for LED
#define _LED_OFF                                1       // Power off state for LED

#define PCB_LED_ACTIVE()                        {\
                                                    bLED1 = _LED_ON;                \
                                                    bLED2 = _LED_OFF;               \
                                                }

#define PCB_LED_IDLE()                          {\
                                                    bLED1 = _LED_ON;               \
                                                    bLED2 = _LED_OFF;                \
                                                }

#define PCB_LED_ON()                            {\
                                                    bLED1 = _LED_ON;               \
                                                    bLED2 = _LED_OFF;                \
                                                }

#define PCB_LED_POWER_SAVING()                  {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_ON;                \
                                                }

#define PCB_LED_OFF()                           {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_OFF;               \
                                                }

#define PCB_LED_TYPE1()                         {\
                                                }

#define PCB_LED_TYPE2()                         {\
                                                }

#define PCB_LED_TYPE3()                         {\
                                                }

#define PCB_LED_TYPE4()                         {\
                                                }

#define PCB_LED_TYPE5()                         {\
                                                }

#define PCB_LED_TYPE_FLASH()                    {\
                                                }

#define PCB_LED_TYPE_PWM(x)                     {\
                                                }

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
// Must Check Whether _LOW_SPEED_ADC_SUPPORT is Supported
#define _AD_KEY_SUPPORT                         _ON

#define AD_KEY0                                 (_FALSE)
#define AD_KEY1                                 (MCU_ADC1_RESULT_FF0A)
#define AD_KEY2                                 (MCU_ADC2_RESULT_FF0B)
#define AD_KEY3                                 (_FALSE)

#define PCB_ADKEY0()                            (AD_KEY0)
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)
#define PCB_ADKEY3()                            (AD_KEY3)

sbit bPOWER_KEY                                = P3 ^ 2;// Pin 63, P3.2

#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0 <= ucV1) && (ucV1 < 0x20))       \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x40 <= ucV1) && (ucV1 < 0x80))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;     \
                                                                                                       \
                                                                if(0x00 == bPOWER_KEY)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x40 <= ucV2) && (ucV2 < 0x80))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if((0x00 <= ucV2) && (ucV2 < 0x20))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                            }

//--------------------------------------------------
// Definitions of Touch Key
//--------------------------------------------------
#define _TOUCH_KEY_SUPPORT                      _OFF

#define _TOUCHPAD_DRICE_ADDRESS                 0x50

#define PCB_TOUCHPAD_IIC_SDA_SET()              (_FALSE)
#define PCB_TOUCHPAD_IIC_SDA_CLR()              (_FALSE)
#define PCB_TOUCHPAD_IIC_SDA_CHK()              (_FALSE)

#define PCB_TOUCHPAD_IIC_SCL_SET()              (_FALSE)
#define PCB_TOUCHPAD_IIC_SCL_CLR()              (_FALSE)
#define PCB_TOUCHPAD_IIC_SCL_CHK()              (_FALSE)

#define _PCB_TOUCH_KEY_INIT_TABLE               0x00
#define PCB_GET_TOUCH_KEY_STATE()               (_FALSE)


//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
sbit bPANELPOWER                                = P3 ^ 7; //  Pin 26, P3.7

#define _PANEL_CONTROL_ON                       1       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      0       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = x;                \
                                                }

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
sbit bBACKLIGHTPOWER                            = P3 ^ 3; // Pin 55, P3.3

#define _LIGHT_CONTROL_ON                       0       // Light on  state for backlight inverter
#define _LIGHT_CONTROL_OFF                      1       // Light off state for backlight inverter

#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = x;                \
                                                }

#if(_BACKLIGHT_PWM_FREQ_SELECT == _PWMFREQ22K)//Ada.chen 20150519 modify backlight PWM freq= 22k
#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if(x == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                        ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 22000); \
                                                    }\
                                                    else\
                                                    {\
                                                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                    }\
                                                    bBACKLIGHTPOWER = x;            \
                                                }
#else
#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if(x == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                        if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)\
                                                        {\
                                                            ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, (WORD)((GET_INPUT_TIMING_VFREQ() * 40) / 100)); \
                                                        }\
                                                        else\
                                                        {\
                                                            ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 240); \
                                                        }\
                                                    }\
                                                    else\
                                                    {\
                                                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                    }\
                                                    bBACKLIGHTPOWER = x;            \
                                                }
#endif

//-----------------------------------------------
#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_PWM3H_DUT_FF4E = x;         \
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_PWM3H_DUT_FF4E)

//-----------------------------------------------
// Macro of Power Board Low Power Pin High/Low
//-----------------------------------------------
#define _LOW_POWER_ON                           1       // Low power on state
#define _LOW_POWER_OFF                          0       // Low power off state

#define PCB_POWERBOARD_LOWPOWER(x)              {\
                                                }

//-----------------------------------------------
// Macro of Usb Hub High/Low
//-----------------------------------------------
#define PCB_USB_DETECT()                        (_FALSE)

#define _USB_POWER_ON                           1       // USB power on state
#define _USB_POWER_OFF                          0       // USB power off state

#define PCB_USB_POWER(x)                        {\
                                                }
//-----------------------------------------------
// Macro of Dynamic High/Low
//-----------------------------------------------
#define _BACKLIGHT_HIGH_DYNAMIC_ON              30
#define _BACKLIGHT_HIGH_DYNAMIC_OFF             216

#define PCB_BACKLIGHT_HIGH_DYNAMIC(x)           {\
                                                }

#endif // End of #if(_PCB_TYPE == _RL6230_DEMO_1A)

