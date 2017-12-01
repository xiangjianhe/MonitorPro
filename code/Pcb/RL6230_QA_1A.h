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

#if(_PCB_TYPE == _RL6230_QA_1A)

#define _EXT_XTAL                               _XTAL14318K     


//--------------------------------------------------
// Input Port Define
//--------------------------------------------------
////////////////////////////////////////////////////////
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
#define _LVDS_EO_SWAP                           _ENABLE            // Display Data Port Even/Odd Data Swap              
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
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _OFF
#define _PWM5_EN                                _ON

#define _PWM0_PSAV_EN                           _OFF
#define _PWM1_PSAV_EN                           _OFF
#define _PWM2_PSAV_EN                           _OFF
#define _PWM3_PSAV_EN                           _OFF
#define _PWM4_PSAV_EN                           _OFF
#define _PWM5_PSAV_EN                           _OFF

#define _PWM0_RST_BY_DVS                        _OFF
#define _PWM1_RST_BY_DVS                        _OFF
#define _PWM2_RST_BY_DVS                        _OFF
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _OFF
#define _PWM5_RST_BY_DVS                        _ON

#define _BACKLIGHT_PWM                          _PWM5
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

//--------------------------------------------------
// Definitions for Low Speed ADC
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _OFF

//--------------------------------------------------
// RL6230 Series Pin Share
//--------------------------------------------------
//--------------------------------------------------
// RTD2270L_M Pin Share
//--------------------------------------------------
// BL_EN
#define _PIN_4                                  (0 & 0x03)  // 0 ~ 2 (0: P1D3i, 1: P1D3o<open-drain>, 2: P1D3o<push-pull>, )

// DCC
#define _PIN_18                                 (4 & 0x07)  // 0 ~ 3 (0: P3D1i, 1: P3D1o<open-drain>, 2: P3D1o<push-pull>, 3: TXD<open-drain>, 4: DDCSDA)
#define _PIN_19                                 (4 & 0x07)  // 0 ~ 3 (0: P3D0i, 1: P3D0o<open-drain>, 2: P3D0o<push-pull>, 3: RXD<open-drain>, 4: DDCSCL)

// KEY5
#define _PIN_20                                 (0 & 0x07)  // 0 ~ 4 (0: P5D0i, 1: P5D0o<open-drain>, 2: P5D0o<push-pull>, 3: PWM0<open-drain>, 4: PWM0<push-pull>)

// NC Pin
#define _PIN_25                                 (0 & 0x03)  // 0 ~ 3 (0: P3D6i, 1: P3D6o<open-drain>, 2: P3D6o<push-pull>, 3: I2C_MDL_1<O>)
#define _PIN_26                                 (0 & 0x03)  // 0 ~ 3 (0: P3D7i, 1: P3D7o<open-drain>, 2: P3D7o<push-pull>, 3: I2C_MDA_1<open-drain>)

// KEY4
#define _PIN_27                                 (0 & 0x07)  // 0 ~ 4 (0: P5D1i, 1: P5D1o<open-drain>, 2: P5D1o<push-pull>, 3: PWM1<open-drain>, 4: PWM1<push-pull>)

// KEY3
#define _PIN_28                                 (0 & 0x07)  // 0 ~ 4 (0: P5D2i, 1: P5D2o<open-drain>, 2: P5D2o<push-pull>, 3: PWM2<open-drain>, 4: PWM2<push-pull>)

// EEPROM IICSDA 
#define _PIN_29                                 (1 & 0x03)  // 0 ~ 3 (0: P1D0i, 1: P1D0o<open-drain>, 2: P1D0o<push-pull>, 3: T2<I>)

// LVDS
#define _PIN_33                                 (3 & 0x03)  // 0 ~ 3 (0: P8D0i, 1: reserved, 2: P8D0o<push-pull>, 3: LVDS_TXE,)
#define _PIN_34                                 (3 & 0x03)  // 0 ~ 3 (0: P8D1i, 1: reserved, 2: P8D1o<push-pull>, 3: LVDS_TXE,)
#define _PIN_35                                 (3 & 0x03)  // 0 ~ 3 (0: P8D2i, 1: reserved, 2: P8D2o<push-pull>, 3: LVDS_TXE,)
#define _PIN_36                                 (3 & 0x03)  // 0 ~ 3 (0: P8D3i, 1: reserved, 2: P8D3o<push-pull>, 3: LVDS_TXE,)
#define _PIN_37                                 (3 & 0x03)  // 0 ~ 3 (0: P8D4i, 1: reserved, 2: P8D4o<push-pull>, 3: LVDS_TXE,)
#define _PIN_38                                 (3 & 0x03)  // 0 ~ 3 (0: P8D5i, 1: reserved, 2: P8D5o<push-pull>, 3: LVDS_TXE,)
#define _PIN_39                                 (3 & 0x03)  // 0 ~ 3 (0: P8D6i, 1: reserved, 2: P8D6o<push-pull>, 3: LVDS_TXE,)
#define _PIN_40                                 (3 & 0x03)  // 0 ~ 3 (0: P8D7i, 1: reserved, 2: P8D7o<push-pull>, 3: LVDS_TXE,)

// LED2
#define _PIN_55                                 (1 & 0x03)  // 0 ~ 3 (0: P3D3i, 1: P3D3o<open-drain>, 2: P3D3o<push-pull>, 3: INT1,)

// KEY2
#define _PIN_56                                 (0 & 0x07)  // 0 ~ 5 (0: P5D3i, 1: P5D3o<open-drain>, 2: P5D3o<push-pull>, 3: PWM3<open-drain>, 4: PWM3<push-pull>, 5: CLKO1<O>)

// NC Pin
#define _PIN_57                                 (3 & 0x03)  // 0 ~ 3 (0: P6D0i, 1: P6D0o<open-drain>, 2: P6D0o<push-pull>, 3: ADC0,)

// VGA_CABLE_DET
#define _PIN_58                                 (0 & 0x03)  // 0 ~ 3 (0: P6D1i, 1: P6D1o<open-drain>, 2: P6D1o<push-pull>, 3: ADC1,)

// RW_PD
#define _PIN_59                                 (1 & 0x07)  // 0 ~ 4 (0: P6D2i, 1: P6D2o<open-drain>, 2: P6D2o<push-pull>, 3: ADC2, 4:I2C_MDL_2A<open-drain>, )

// PANEL_ON
#define _PIN_60                                 (2 & 0x07)  // 0 ~ 4 (0: P6D3i, 1: P6D3o<open-drain>, 2: P6D3o<push-pull>, 3: ADC3, 4:I2C_MDA_2A<open-drain>, )

// KEY1
#define _PIN_61                                 (0 & 0x07)  // 0 ~ 4 (0: P5D4i, 1: P5D4o<open-drain>, 2: P5D4o<push-pull>, 3: PWM4B<open-drain>, 4: PWM4B<push-pull>, )

// BL_ADJ
#define _PIN_62                                 (4 & 0x07)  // 0 ~ 6 (0: P5D5i, 1: P5D5o<open-drain>, 2: P5D5o<push-pull>, 3: PWM5<open-drain>, 4: PWM5<push-pull>, 5: TCON9<push-pull>, 6: I2C_MDL_2B<open-drain>)

// LED1
#define _PIN_63                                 (1 & 0x07)  // 0 ~ 6 (0: P3D2i, 1: P3D2o<open-drain>, 2: P3D2o<push-pull>, 3: INT0, 4: TCON7, 5: reserved, 6: I2C_MDA_2B<open-drain>)

// EEPROM IICSCL 
#define _PIN_64                                 (1 & 0x03)  // 0 ~ 3 (0: P1D1i, 1: P1D1o<open-drain>, 2: P1D1o<push-pull>, 3: T2EX<I>)


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

////////////////////////////////////////////////////////////////////////
// Pin41~48 Function Select to user defined                           //
// Pin39~40,50~53,65~66,69~70,96~97,100~101 disable pull up control   //
// Pin67~68,71~72,98~99,102~103 disable pull down control             // 
////////////////////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                }

///////////////////////////////////////////////////////////////////////
// Pin39~40,50~53,65~66,69~70,96~97,100~101 enable pull up control   //
// Pin67~68,71~72,98~99,102~103 enable pull down control             // 
///////////////////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                }

///////////////////////////////////////////////////////////////////////
// Pin39~40,50~53,65~66,69~70,96~97,100~101 enable pull up control   //
// Pin67~68,71~72,98~99,102~103 enable pull down control             // 
///////////////////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                }

#define PCB_GPIO_SETTING_POWER_AC_ON()          {\
                                                }

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
#define PCB_PWM_SETTING()                       {\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 240); \
                                                }

//--------------------------------------------------
// Macro of IIC
//--------------------------------------------------
sbit bSWIIC_SYS_EEPROM_SCL                      = P1 ^ 1; // Pin64 P1.1
sbit bSWIIC_SYS_EEPROM_SDA                      = P1 ^ 0; // Pin29 P1.0

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
#define bFLASH_WRITE_PROTECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//----------------------------------------------- 
#define bEEPROM_WRITE_PROTECT                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _EEPROM_WP_ENABLE                       1       // WP High state for Eeprom
#define _EEPROM_WP_DISABLE                      0       // WP Low state for Eeprom

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                }

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)    {\
                                               }


//-----------------------------------------------
// Macro of Input Connect Detect
//-----------------------------------------------
#define bA0_CONNECT                             (MCU_PORT61_PIN_REG_FFC8) // Pin 58, P6.1

#define PCB_A0_PIN()                            (SET_A0_CABLE_STATUS(!bA0_CONNECT))

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
sbit bLED1                                      = P3 ^ 2;   // Pin 63
sbit bLED2                                      = P3 ^ 3;   // Pin 55

#define _LED_ON                                 0       // Power on  state for LED
#define _LED_OFF                                1       // Power off state for LED

#define PCB_LED_ACTIVE()                        {\
                                                    bLED1 = _LED_ON;                \
                                                    bLED2 = _LED_OFF;               \
                                                }

#define PCB_LED_IDLE()                          {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_ON;                \
                                                }

#define PCB_LED_ON()                            {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_ON;                \
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
// Must Check Wether _LOW_SPEED_ADC_SUPPORT is Supported
#define _AD_KEY_SUPPORT                         _OFF

#define bPOWER_KEY                              (MCU_PORT54_PIN_REG_FFC3 & 0x01)
#define bMENU_KEY                               (MCU_PORT53_PIN_REG_FFC2 & 0x01)
#define bEXIT_KEY                               (MCU_PORT52_PIN_REG_FFC1 & 0x01)
#define bLEFT_KEY                               (MCU_PORT51_PIN_REG_FFC6 & 0x01)
#define bRIGHT_KEY                              (MCU_PORT50_PIN_REG_FFC5 & 0x01)

#define AD_KEY2                                 (_FALSE)
#define AD_KEY1                                 (_FALSE)
#define AD_KEY0                                 (_FALSE)

#define PCB_ADKEY0()                            (AD_KEY1)
#define PCB_ADKEY1()                            (AD_KEY0)
#define PCB_ADKEY2()                            (AD_KEY2)
#define PCB_ADKEY3()                            (_FALSE)

#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if(!bRIGHT_KEY)					                 \
                                                                    ucKeyState = ucKeyState | _RIGHT_KEY_MASK;	 \
                                                                                                                 \
                                                                if(!bLEFT_KEY)						             \
                                                                    ucKeyState = ucKeyState | _LEFT_KEY_MASK;	 \
                                                                                                                 \
                                                                if(!bEXIT_KEY)						             \
                                                                    ucKeyState = ucKeyState | _EXIT_KEY_MASK;	 \
                                                                                                                 \
                                                                if(!bMENU_KEY)						             \
                                                                    ucKeyState = ucKeyState | _MENU_KEY_MASK;	 \
                                                                                                                 \
                                                                if(!bPOWER_KEY)						             \
                                                                    ucKeyState = ucKeyState | _POWER_KEY_MASK;	 \
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
#define bPANELPOWER                             (MCU_PORT63_PIN_REG_FFCA)   // Pin60 P6.3

#define _PANEL_CONTROL_ON                       0       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      1       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = x;                \
                                                }

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
sbit bBACKLIGHTPOWER                            = P1 ^ 3;   // Pin4 P1.3

#define _LIGHT_CONTROL_ON                       0       // Light on  state for backlight inverter
#define _LIGHT_CONTROL_OFF                      1       // Light off state for backlight inverter

#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = x; \
                                                }
                                                
#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if(x == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                        if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)\
                                                        {\
                                                            ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, (WORD)((GET_INPUT_TIMING_VFREQ() * 60) / 100)); \
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

//-----------------------------------------------
#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_PWM5H_DUT_FF51 = x;         \
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_PWM5H_DUT_FF51)

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

#endif // End of #if(_PCB_TYPE == _RL6230_QA_1A)

