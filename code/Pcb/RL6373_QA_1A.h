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
// ID Code      : RL6373_QA_1A.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PCB_TYPE == _RL6373_QA_1A)

#define _EXT_XTAL                               ((DWORD)ScalerLCTankGetClock())     


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
#define _LVDS_EO_SWAP                           _DISABLE            // Display Data Port Even/Odd Data Swap              
#define _LVDS_RB_SWAP                           _DISABLE            // Display Data Port Red/Blue Data Swap              
#define _LVDS_ML_SWAP                           _DISABLE            // Display Data Port MSB/LSB Data Swap    

#define _LVDS_DVS_INVERT                        _DISABLE            // DVS Output Invert Enable                
#define _LVDS_DHS_INVERT                        _DISABLE            // DHS Output Invert Enable                
#define _LVDS_DEN_INVERT                        _DISABLE            // DEN Output Invert Enable                

#define _LVDS_MIRROR                            _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE

#define _LVDS_EA_PHASE                          _LVDS_PI_PHASE_N1   // TQFP pin39,40
#define _LVDS_EB_PHASE                          _LVDS_PI_PHASE_0   // TQFP pin41,42              
#define _LVDS_EC_PHASE                          _LVDS_PI_PHASE_N1   // TQFP pin43,44
#define _LVDS_ED_PHASE                          _LVDS_PI_PHASE_N1   // TQFP pin45,46
#define _LVDS_EE_PHASE                          _LVDS_PI_PHASE_N1   // TQFP pin47,48
#define _LVDS_OA_PHASE                          _LVDS_PI_PHASE_N2   // TQFP pin31,32
#define _LVDS_OB_PHASE                          _LVDS_PI_PHASE_N2   // TQFP pin33,34               
#define _LVDS_OC_PHASE                          _LVDS_PI_PHASE_N2   // TQFP pin35,36
#define _LVDS_OD_PHASE                          _LVDS_PI_PHASE_N2   // TQFP pin37,38

#define _LVDS_PHASE_N1_SELECT                   _LVDS_PHASE0        // Only Phase 0 ~ 16 can be used
#define _LVDS_PHASE_N2_SELECT                   _LVDS_PHASE5        // Only Phase 0 ~ 16 can be used

//--------------------------------------------------
// Definitions for LVDS EMI
//--------------------------------------------------
#define _LVDS_DATA_DRIV_CONTROL                 _LVDS_DRIV_CONTROL_3_0                  
#define _LVDS_CLK_DRIV_CONTROL                  _LVDS_DRIV_CONTROL_3_0                   

#define _LVDS_VCM_CONTROL                       _LVDS_VCM_HIGH                             
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_1
#define _LVDS_TERMINATION_CONTROL               _ENABLE

//--------------------------------------------------
// System Data Storage Options
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16               
#define _EEPROM_SLAVE_ADDRESS                   0xA0
//#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_64PIN_PIN_29_30
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_25_26

//-------------------------------------------------
// Sofware and Hardware IIC Options
//-------------------------------------------------
#define _SW_IIC_SUPPORT                         _OFF
#define _SW_IIC_CLK_DIV                         _DIV_1   

#define _HW_IIC_SUPPORT                         _ON
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K

//--------------------------------------------------
// Definitions for PWM Setting
//--------------------------------------------------
#define _PWM0_EN                                _ON
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _OFF
#define _PWM5_EN                                _OFF

#define _PWM0_PSAV_EN                           _OFF
#define _PWM1_PSAV_EN                           _OFF
#define _PWM2_PSAV_EN                           _OFF
#define _PWM3_PSAV_EN                           _OFF
#define _PWM4_PSAV_EN                           _OFF
#define _PWM5_PSAV_EN                           _OFF

#define _PWM0_RST_BY_DVS                        _ON
#define _PWM1_RST_BY_DVS                        _OFF
#define _PWM2_RST_BY_DVS                        _OFF
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _OFF
#define _PWM5_RST_BY_DVS                        _OFF

#define _BACKLIGHT_PWM                          _PWM0
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

//--------------------------------------------------
// Definitions for Low Speed ADC
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _ON

#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
//--------------------------------------------------
// Definitions for Eled PCB Related
//--------------------------------------------------
#define _ELED_PCB_VI_VOLTAGE                    12                              // 12~19 Unit: Voltage
#define _ELED_PCB_INDUCTOR_VALUE                22                              // 22~47 Unit: Hunry
#define _ELED_PCB_RSENSE_VALUE                  5                               // 5~10 Unit: 0.01ohm
#define _ELED_PCB_OVP_RATION                    47                              // 27~50 OVP_R1 = 180K, OVP_R2 = 3.9K (OVP_R1 + OVP_R2)/OVP_R2 
#define _ELED_PCB_OVP_TRIGGER_LEVEL             (_PANEL_ELED_VOUT_MAX * 115)    // panel Vmax * X where X is the OVP Tolerance Range
#define _ELED_VOUT_CAPACITOR                    _OFF                            // _ON:Vout Capacitor on; _OFF:Vout Capacitor Off
#define _ELED_VFB_RESISTOR                      _VFB_RESISTOR_3_OHM             // 5 or 10 VFB Resistor
#define _ELED_DIMMING_PWM                       _DIMMING_PWM_240                // 180 or 240Hz Dimming PWM Frequency
#define _ELED_BOOSTER_PWM                       _BOOSTER_PWM_300K               // 300 or 400KHz Booster PWM Frequency

#if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)
#define _ELED_VREF_INITIAL_CURRENT              _VREF_INITIAL_1_UA
#define _ELED_LED_DRIVER_MIN_PWM_DUTY           20                  // Min Current = _PANEL_ELED_STRING_CURRENT x _ELED_LED_DRIVER_MIN_PWM_DUTY / 256
#elif(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _ANALOG_DIMMING)
#define _ELED_VREF_INITIAL_CURRENT              _VREF_INITIAL_1_UA
#define _ELED_LED_DRIVER_MIN_VOLTAGE            (6 * _ELED_VREF_INITIAL_CURRENT)

#endif // End of #if(_PANEL_EMBEDDED_LED_DRIVER_DIMMING_SEL == _DIGITAL_DIMMING)

//--------------------------------------------------
// Definitions for Eled PCB LED String Support
//--------------------------------------------------
#define _ELED_STRING0                           _ON
#define _ELED_STRING1                           _ON
#define _ELED_STRING2                           _ON
#define _ELED_STRING3                           _ON
#endif

//--------------------------------------------------
// RL6373 Series Pin Share
//--------------------------------------------------
// <OD>:open-drain  <PP>:push-pull
// LED2
#define _PIN_19                                      (2 & 0x07) // Page 10-0xA2[2:0]
// 0 ~ 7 (0: P5D0i<I>, 1: P5D0o<OD>, 2: P5D0o<PP>, 3: TCON[1]<O>, 4: PWM0<OD>, 5: PWM0<PP>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>)

// FLASH_WP
#define _PIN_20                                      (2 & 0x0F) // Page 10-0xAA[3:0]
// 0 ~ 10 (0: P3D2i<I>, 1: P3D2o<OD>, 2: P3D2o<PP>, 3: TCON[5]<O>, 4: PWM0<OD>, 5: PWM0<PP>, 6: INT0<I>, 7: T2<I>, 8:DHS<O>, 9: TEST_PIN2<O>, 10: TEST_PIN3<O>)

// AD_KEY
#define _PIN_27                                      (3 & 0x07) // Page 10-0xA5[2:0]
// 0 ~ 5 (0: P6D1i<I>, 1: P6D1o<OD>, 2: P6D1o<PP>, 3: ADCA0(8bit)<I>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>)

// LED1
#define _PIN_28                                      (2 & 0x07) // Page 10-0xA6[2:0]
// 0 ~ 5 (0: P6D2i<I>, 1: P6D2o<OD>, 2: P6D2o<PP>, 3: ADCA1(8bit)<I>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>)

// DDCSCL
#define _PIN_29                                      (9 & 0x0F) // Page 10-0xA8[3:0]
// 0 ~ 10 (0: P5D4i<I>, 1: P5D4o<OD>, 2: P5D4o<PP>, 3: TCON[11]<O>, 4: PWM3<OD>, 5: PWM3<PP>, 6: RXD <O>, 7: TEST_PIN2<O>, 8: TEST_PIN3<O>, 9: DDCSCL, 10: IICSCL)

// DDCSDA
#define _PIN_30                                      (9 & 0x0F) // Page 10-0xA9[2:0]
// 0 ~ 10 (0: P5D5i<I>, 1: P5D5o<OD>, 2: P5D5o<PP>, 3: TCON[13]<O>, 4: TXD <IO>, 5: TEST_PIN2<O>, 6: TEST_PIN3<O>, 9: DDCSDA, 10: IICSCL)

// TXO3+
#define _PIN_31                                      (0 & 0x07) // Page 10-0xAE[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P8D0i<I>, 2: P8D0o<OD>, 3: P8D0o<PP>, 4: PWM3<OD>, 5: PWM3<PP>)

// TXO3-
#define _PIN_32                                      (0 & 0x07) // Page 10-0xAF[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P8D1i<I>, 2: P8D1o<OD>, 3: P8D1o<PP>, 4: PWM3<OD>, 5: PWM3<PP>)

// TXO2+
#define _PIN_33                                      (0 & 0x07) // Page 10-0xB0[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P8D2i<I>, 2: P8D2o<OD>, 3: P8D2o<PP>, 4: PWM2<OD>, 5: PWM2<PP>)

// TXO2-
#define _PIN_34                                      (0 & 0x07) // Page 10-0xB1[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P8D3i<I>, 2: P8D3o<OD>, 3: P8D3o<PP>, 4: PWM2<OD>, 5: PWM2<PP>)

// TXO1+
#define _PIN_35                                      (0 & 0x07) // Page 10-0xB2[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P8D4i<I>, 2: P8D4o<OD>, 3: P8D4o<PP>, 4: PWM1<OD>, 5: PWM1<PP>)

// TXO1-
#define _PIN_36                                      (0 & 0x07) // Page 10-0xB3[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P8D5i<I>, 2: P8D5o<OD>, 3: P8D5o<PP>, 4: PWM1<OD>, 5: PWM1<PP>)

// TXO0+
#define _PIN_37                                      (0 & 0x07) // Page 10-0xB4[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P8D6i<I>, 2: P8D6o<OD>, 3: P8D6o<PP>, 4: PWM0<OD>, 5: PWM0<PP>)

// TXO0-
#define _PIN_38                                      (0 & 0x07) // Page 10-0xB5[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P8D7i<I>, 2: P8D7o<OD>, 3: P8D7o<PP>, 4: PWM0<OD>, 5: PWM0<PP>)


/////////////////////////////  open/short pinshare  ///////////////////////////////

// AVS0
#define _PIN_8                                       (0 & 0x03) // Page 10-0xBF[1:0]
// 0 ~ 1 (0: AVS0<I>, 1: P5D1i<I>)

// AHS0
#define _PIN_9                                       (0 & 0x03) // Page 10-0xC0[1:0]
// 0 ~ 1 (0: AHS0<I>, 1: P5D2i<I>)

// B0-
#define _PIN_10                                       (0 & 0x03) // Page 10-0xC1[1:0]
// 0 ~ 1 (0: B0-<I>, 1: P5D7i<I>)

// B0+
#define _PIN_11                                       (0 & 0x03) // Page 10-0xC2[1:0]
// 0 ~ 3 (0: B0+<I>, 1: P6D4i<I>, 2: P6D4o<OD>, 3: P6D4o<PP>)

// G0-
#define _PIN_12                                      (0 & 0x03) // Page 10-0xC3[1:0]
// 0 ~ 1 (0: G0-<I>, 1: P6D5i<I>)

// G0+
#define _PIN_13                                      (0 & 0x03) // Page 10-0xC4[1:0]
// 0 ~ 3 (0: G0+<I>, 1: P6D6i<I>, 2: P6D6o<OD>, 3: P6D6o<PP>)

// SOG0
#define _PIN_14                                      (0 & 0x03) // Page 10-0xC5[1:0]
// 0 ~ 1 (0: SOG0<I>, 1: P6D7i<I>)

// Ro-
#define _PIN_15                                      (0 & 0x03) // Page 10-0xC6[1:0]
// 0 ~ 1 (0: R0-<I>, 1: P7D0i<I>)

// Ro+
#define _PIN_16                                      (0 & 0x03) // Page 10-0xC7[1:0]
// 0 ~ 3 (0: R0+<I>, 1: P7D1i<I>, 2: P7D1o<OD>, 3: P7D1o<PP>)

// TXE3+
#define _PIN_39                                      (0 & 0x07) // Page 10-0xC8[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P3D1i<I>, 2: P3D1o<OD>, 3: P3D1o<PP>, 4: PWM4<OD>, 5: PWM4<PP>)

// TXE3-
#define _PIN_40                                      (0 & 0x07) // Page 10-0xC9[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P1D2i<I>, 2: P1D2o<OD>, 3: P1D2o<PP>, 4: PWM4<OD>, 5: PWM4<PP>)

// TXEC+
#define _PIN_41                                      (0 & 0x07) // Page 10-0xCA[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P1D4i<I>, 2: P1D4o<OD>, 3: P1D4o<PP>, 4: PWM3<OD>, 5: PWM3<PP>)

// TXEC-
#define _PIN_42                                      (0 & 0x07) // Page 10-0xCB[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P1D0i<I>, 2: P1D0o<OD>, 3: P1D0o<PP>, 4: PWM3<OD>, 5: PWM3<PP>)

// TXE2+
#define _PIN_43                                      (0 & 0x07) // Page 10-0xCC[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P1D5i<I>, 2: P1D5o<OD>, 3: P1D5o<PP>, 4: PWM2<OD>, 5: PWM2<PP>)

// TXE2-
#define _PIN_44                                      (0 & 0x07) // Page 10-0xCD[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P1D6i<I>, 2: P1D6o<OD>, 3: P1D6o<PP>, 4: PWM2<OD>, 5: PWM2<PP>)

// TXE1+
#define _PIN_45                                      (0 & 0x07) // Page 10-0xCE[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P1D7i<I>, 2: P1D7o<OD>, 3: P1D7o<PP>, 4: PWM1<OD>, 5: PWM1<PP>)

// TXE1-
#define _PIN_46                                      (0 & 0x07) // Page 10-0xCF[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P3D4i<I>, 2: P3D4o<OD>, 3: P3D4o<PP>, 4: PWM1<OD>, 5: PWM1<PP>)

// TXE0+
#define _PIN_47                                      (0 & 0x07) // Page 10-0xD0[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P3D5i<I>, 2: P3D5o<OD>, 3: P3D5o<PP>, 4: PWM0<OD>, 5: PWM0<PP>)

// TXE0-
#define _PIN_48                                      (0 & 0x07) // Page 10-0xD1[2:0]
// 0 ~ 5 (0: Hi-Z, 1: P3D7i<I>, 2: P3D7o<OD>, 3: P3D7o<PP>, 4: PWM0<OD>, 5: PWM0<PP>)


//-----------------------------------------------
// Macro of Pcb Gpio Inital Setting
//-----------------------------------------------

// Enable Write Protect for EEPROM and FLASH
#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
#define PCB_GPIO_INITIAL_SETTING()              {\
                                                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_ENABLE); \
                                                    PCB_PANEL_POWER(_PANEL_CONTROL_OFF); \
                                                    PCB_LED_OFF(); \
                                                }

#else
#define PCB_GPIO_INITIAL_SETTING()              {\
                                                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_ENABLE); \
                                                    PCB_PANEL_POWER(_PANEL_CONTROL_OFF); \
                                                    PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF); \
                                                    PCB_LED_OFF(); \                                                    
                                                }
#endif // #endif (_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)

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
#define bSWIIC_SYS_EEPROM_SCL                   (MCU_PORT54_PIN_REG_FFC3) // Pin29 P5.4
#define bSWIIC_SYS_EEPROM_SDA                   (MCU_PORT55_PIN_REG_FFC4) // Pin30 P5.5

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
sbit bFLASH_WRITE_PROTECT                       = P3 ^ 2; //TQFP Pin 20, P3.2

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = x;   \    
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//----------------------------------------------- 
#define bEEPROM_WRITE_PROTECT                   (MCU_PORT53_PIN_REG_FFC2) // none

#define _EEPROM_WP_ENABLE                       1       // WP High state for Eeprom
#define _EEPROM_WP_DISABLE                      0       // WP Low state for Eeprom

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = x;  \       
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
#define PCB_A0_PIN()                            (SET_A0_CABLE_STATUS(ScalerSLPCableDetectHit()))

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   (MCU_PORT62_PIN_REG_FFC9)  // TQFP Pin28, P6.2
#define bLED2                                   (MCU_PORT56_PIN_REG_FFC5)  // TQFP pin19, P5.0


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
                                                    ScalerSLPLedLevelMode(_LED_ON);  \
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
// Support count of  low speed ADC : 3
#define _AD_KEY_SUPPORT                         _ON

#define AD_KEY2                                 (ScalerSarAdcCodeValue())
#define AD_KEY1                                 (_FALSE)
#define AD_KEY0                                 (_FALSE)

#define PCB_ADKEY0()                            (_FALSE)
#define PCB_ADKEY1()                            (_FALSE)
#define PCB_ADKEY2()                            (AD_KEY2)
#define PCB_ADKEY3()                            ((BYTE)ScalerSLPPowerKeyHit())

#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if(ucV3 == 0x01)                        \
                                                                    ucKeyState |= _POWER_KEY_MASK;      \
                                                                                                        \
                                                                if((0x02 <= ucV2) && (ucV2 < 0x06))     \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;      \
                                                                                                        \
                                                                if((0x07 <= ucV2) && (ucV2 < 0xC))     \
                                                                    ucKeyState |= _LEFT_KEY_MASK;       \
                                                                                                        \
                                                                if((0x0D <= ucV2) && (ucV2 < 0x11))     \
                                                                    ucKeyState |= _EXIT_KEY_MASK;       \
                                                                                                        \
                                                                if((0x13 <= ucV2) && (ucV2 < 0x17))     \
                                                                    ucKeyState |= _MENU_KEY_MASK;       \
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
#define bPANELPOWER                             (MCU_PORT53_PIN_REG_FFC2)   // none

#define _PANEL_CONTROL_ON                       0       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      1       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = x;                \
                                                }

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)

#define bBACKLIGHTPOWER                         (MCU_PORT53_PIN_REG_FFC2)    // none

#define _LIGHT_CONTROL_ON                       0       // Light on  state for backlight inverter
#define _LIGHT_CONTROL_OFF                      1       // Light off state for backlight inverter
                                               
#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if(x == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                    }\
                                                    else\
                                                    {\
                                                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                    }\
                                                    ScalerELEDControl(x);\
                                                }

//-----------------------------------------------
#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    ScalerELEDBacklightAdjust(x);\                                                    
                                                    x = ScalerELEDGetBacklightPWM();\
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (ScalerELEDGetBacklightPWM())

#else
#define bBACKLIGHTPOWER                         (MCU_PORT53_PIN_REG_FFC2)    // none

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
                                                    MCU_PWM0H_DUT_FF4A = x;         \
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_PWM0H_DUT_FF4A)

#endif // #endif (_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)

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

//-----------------------------------------------
// Macro of PCB power detect
//-----------------------------------------------
#define PCB_POWER_5V_DETECT()                   (ScalerSLPPC99PowerDetect())

#endif // End of #if(_PCB_TYPE == _RL6373_QA_1A)

