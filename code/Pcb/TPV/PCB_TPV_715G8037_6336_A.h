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
// ID Code      : PCB_TPV_715G8037_6336_A.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PCB_TYPE == _PCB_TPV_715G8037_6336_A)

#define _EXT_XTAL                               _XTAL14318K


//--------------------------------------------------
// Input Port Define
//--------------------------------------------------
////////////////////////////////////////////////////////
//If _A0_INPUT_PORT_TYPE is _A0_NO_PORT               //
//Please remove the following functions from BL51 Misc//
//BANK0 --> ?CO?USERCOMMONMODESEARCH                  //
//BANK0 --> ?CO?RL6336_SERIES_AUTOFUNC                //
//BANK0 --> ?CO?RL6336_SERIES_PLL                     //
//Otherwise, if _A0_INPUT_PORT_TYPE is _A0_VGA_PORT   //
//Please add the above functions to BL51 Misc         //
////////////////////////////////////////////////////////
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _EMBEDDED_DDCRAM_A0_SIZE                _EDID_SIZE_NONE//Robert Wang 20140429
#define _EMBEDDED_DDCRAM_A0_LOCATION            _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
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

#define _LVDS_E0_PHASE                          _LVDS_PHASE0   // pin49,50  // Only Phase 0 ~ 7 can be used
#define _LVDS_E1_PHASE                          _LVDS_PHASE0   // pin47,48  // Only Phase 0 ~ 7 can be used
#define _LVDS_E2_PHASE                          _LVDS_PHASE0   // pin45,46  // Only Phase 0 ~ 7 can be used
#define _LVDS_EC_PHASE                          _LVDS_PHASE0   // pin43,44  // Only Phase 0 ~ 7 can be used
#define _LVDS_E3_PHASE                          _LVDS_PHASE0   // pin41,42  // Only Phase 0 ~ 7 can be used
#define _LVDS_O0_PHASE                          _LVDS_PHASE1   // pin39,40  // Only Phase 0 ~ 7 can be used
#define _LVDS_O1_PHASE                          _LVDS_PHASE1   // pin37,38  // Only Phase 0 ~ 7 can be used
#define _LVDS_O2_PHASE                          _LVDS_PHASE1   // pin35,36  // Only Phase 0 ~ 7 can be used
#define _LVDS_O3_PHASE                          _LVDS_PHASE1   // pin33,34  // Only Phase 0 ~ 7 can be used
//--------------------------------------------------
// Definitions for LVDS EMI
//--------------------------------------------------
#if((_PROJECT == _PRJ_L_F2014_A_LG_LM195WD1_TLA1) || (_PROJECT == _PRJ_L_F2014_A_AUO_M195RTN01_0) || (_PROJECT == _PRJ_L_F2014_A_INL_M195FGE_L20) || (_PROJECT == _PRJ_L_LS2014_A) || (_PROJECT == _PRJ_L_LS2014_A_LBL))
#define _LVDS_DRIV_CONTROL                      _LVDS_DRIV_CONTROL_3_0
#else
#define _LVDS_DRIV_CONTROL                      _LVDS_DRIV_CONTROL_2_5
#endif

#if((_PROJECT == _PRJ_L_LS2014_A) || (_PROJECT == _PRJ_L_LS2014_A_LBL))
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_1_45//_LVDS_VCM_FORTPV
#else
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL
#endif
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_TERMINATION_CONTROL               _ENABLE

//--------------------------------------------------
// System Data Storage Options
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _SW_IIC_PIN_GPIO// _HW_IIC_64PIN_PIN_25_26

//-------------------------------------------------
// Sofware and Hardware IIC Options
//-------------------------------------------------
#define _SW_IIC_SUPPORT                         _ON//Robert Wang 20140425 _OFF
#define _SW_IIC_CLK_DIV                         _DIV_1

#define _HW_IIC_SUPPORT                         _OFF//_ON
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K

//--------------------------------------------------
// Definitions for PWM Setting
//--------------------------------------------------
#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _ON

#define _PWM0_PSAV_EN                           _OFF
#define _PWM1_PSAV_EN                           _OFF
#define _PWM2_PSAV_EN                           _OFF
#define _PWM3_PSAV_EN                           _OFF

#define _PWM0_RST_BY_DVS                        _OFF
#define _PWM1_RST_BY_DVS                        _OFF
#define _PWM2_RST_BY_DVS                        _OFF
#if(_BACKLIGHT_PWM_FREQ_SELECT == _PWMFREQ22K)
#define _PWM3_RST_BY_DVS                        _OFF
#else
#define _PWM3_RST_BY_DVS                        _ON
#endif

#define _BACKLIGHT_PWM                          _PWM3
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

//--------------------------------------------------
// Definitions for Low Speed ADC
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _ON

//--------------------------------------------------
// RL6336 Series Pin Share //Robert Wang 20140425 modify
//--------------------------------------------------
// <OD>:open-drain  <PP>:push-pull

// SYSTEM_EEPROM_WP
#define _64PIN_PIN_16                                 (1 & 0x07) // Page 10-0xA5[2:0]
// 0 ~ 5 (0: PBD0i<I>, 1: PBD0o<OD>, 2: PBD0o<PP>, 3: PWM0<PP>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>)

// DET_VGA1
#define _64PIN_PIN_17                                 (0 & 0x07) // Page 10-0xA2[2:0]
// 0 ~ 5 (0: PBD7i<I>, 1: PBD7o<OD>, 2: PBD7o<PP>, 3: TCON13<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>)

// LED_O(NC)
#define _64PIN_PIN_18                                 (2 & 0x07) // Page 10-0xA3[2:0]
// 0 ~ 6 (0: PBD6i<I>, 1: PBD6o<OD>, 2: PBD6o<PP>, 3: IICSCL<IO>,
//                  4: TEST_PIN0<O>, 5:TEST_PIN1<O>, 6: RXD<OD>)

// LED_G/B
#define _64PIN_PIN_19                                 (2 & 0x07) // Page 10-0xA4[2:0]
// 0 ~ 6 (0: PBD5i<I>, 1: PBD5o<OD>, 2: PBD5o<PP>, 3: IICSDA<IO>,
//                  4: TEST_PIN0<O>, 5:TEST_PIN1<O>, 6: TXD<OD>)

// ADC_5V
#define _64PIN_PIN_20                                 (5 & 0x07) // Page 10-0xA0[2:0]
// 0 ~ 5 (0: PDD0i<I>, 1: PDD0o<PP>, 2: PDD0o<OD>, 3: TEST_PIN0<O>, 4:TEST_PIN1<O>, 5: PC99<I>)

// KEY_1
#define _64PIN_PIN_21                                 (3 & 0x07) // Page 10-0xA6[2:0]
// 0 ~ 6 (0: P6D1i<I>, 1: P6D1o<OD>, 2: P6D1o<PP>, 3: ADCA0<I>,
//                  4: TEST_PIN0<O>, 5:TEST_PIN1<O>, 6: VCLK<I>)

// KEY_0
#define _64PIN_PIN_22                                 (3 & 0x07) // Page 10-0xA7[2:0]
// 0 ~ 5 (0: P6D2i<I>, 1: P6D2o<OD>, 2: P6D2o<PP>, 3: ADCA1<I>,
//                  4: TEST_PIN0<O>, 5:TEST_PIN1<O>)

// PCB_5V_DETECT
#define _64PIN_PIN_23                                 (3 & 0x07) // Page 10-0xA8[2:0]
// 0 ~ 5 (0: P6D3i<I>, 1: P6D3o<OD>, 2: P6D3o<PP>, 3: ADCA2<I>,
//                  4: TEST_PIN0<O>, 5:TEST_PIN1<O>)

// EESCL
#define _64PIN_PIN_24                                 (1 & 0x0F) // Page 10-0xA9[3:0]
// 0 ~ 9 (0: P6D5i<I>, 1: P6D5o<OD>, 2: P6D5o<PP>,
//        3: PWM1<OD>, 4: PWM1<PP>, 5: PWM3<PP>, 6:TCON7<O>,
//        8: TEST_PIN0<O>, 9:TEST_PIN1<O>)

// EESDA
#define _64PIN_PIN_25                                 (1 & 0x07) // Page 10-0xAA[2:0]
// 0 ~ 6 (0: P6D6i<I>, 1: P6D6o<OD>, 2: P6D6o<PP>, 3: TCON8<O>,
//        4: TCON12, 5: TEST_PIN0<O>, 6:TEST_PIN1<O>, 7: IIC1<IO>)

// EDID_WP
#define _64PIN_PIN_26                                 (1 & 0x07) // Page 10-0xAB[2:0]
// 0 ~ 4 (0: P6D7i<I>, 1: P6D7o<OD>, 2: P6D7o<PP>,
//        3: TEST_PIN0<O>, 4:TEST_PIN1<O>, 5: IIC1<IO>)

// DDCSCL1
#define _64PIN_PIN_27                                 (6 & 0x07) // Page 10-0xAC[2:0]
// 0 ~ 5 (0: P3D0i<I>, 1: P3D0o<OD>, 2: P3D0o<PP>,
//        3: RXD<IO>, 4: TEST_PIN0<O>, 5:TEST_PIN1<O>, 6: DDC1<IO>)

// DDCSCA1
#define _64PIN_PIN_28                                 (8 & 0x0F) // Page 10-0xAD[2:0]
// 0 ~ 7 (0: P3D1i<I>, 1: P3D1o<OD>, 2: P3D1o<PP>, 3: TXD<IO>,
//        4: TCON11<O>, 5: TCON13<O>, 6: TEST_PIN2<O>, 7:TEST_PIN3<O>, 8: DDC1<IO>)

// When Page 10-0xAC[5] = 1 && Pin 24 = 1, Disable ddc function of Pin 27, Pin 28
// and swap to Pin 22, Pin 23
#define _64PIN_PIN_27_28_DDC1_to_22_23                (0 & 0x01) // Page 10-0xAC[5]
// 0 ~ 1 (0: Disable, 1: Enable)

// Panel EN
#define _64PIN_PIN_32                                 (2 & 0x0F) // Page 10-0xAF[3:0]
// 0 ~ 11 (0: P1D0i<I>, 1: P1D0o<OD>, 2: P1D0o<PP>, 3: T2<I>,
//        4: INT1<I>, 5: TCON7<O>, 6: PWM0<PP>, 7: PWM0<OD>, 8: DPLL_TEST_MODE,
//        9: TEST_PIN2<O>, 10:TEST_PIN3<O>, 11: PANEL_SW<OD>)

// LVDS_GPIO
#define _64PIN_PIN_33                                 (0 & 0x03) // Page 10-0xB0[1:0]
// 0 ~ 3 (0: HI-Z, 1: P9D0i<I>, 2: P9D0o<OD>, 3: P9D0o<PP>)

// LVDS_GPIO
#define _64PIN_PIN_34                                 (0 & 0x03) // Page 10-0xB1[1:0]
// 0 ~ 3 (0: HI-Z, 1: P9D1i<I>, 2: P9D1o<OD>, 3: P9D1o<PP>)

// LVDS_GPIO
#define _64PIN_PIN_35                                 (0 & 0x03) // Page 10-0xB2[1:0]
// 0 ~ 3 (0: HI-Z, 1: P9D4i<I>, 2: P9D4o<OD>, 3: P9D4o<PP>)

// LVDS_GPIO
#define _64PIN_PIN_36                                 (0 & 0x03) // Page 10-0xB3[1:0]
// 0 ~ 3 (0: HI-Z, 1: PAD0i<I>, 2: PAD0o<OD>, 3: PAD0o<PP>)

// LVDS_GPIO
#define _64PIN_PIN_37                                 (0 & 0x03) // Page 10-0xB4[1:0]
// 0 ~ 3 (0: HI-Z, 1: PAD1i<I>, 2: PAD1o<OD>, 3: PAD1o<PP>)

// LVDS_GPIO
#define _64PIN_PIN_38                                 (0 & 0x03) // Page 10-0xB5[1:0]
// 0 ~ 3 (0: HI-Z, 1: PAD2i<I>, 2: PAD2o<OD>, 3: PAD2o<PP>)

// LVDS_GPIO
#define _64PIN_PIN_39                                 (0 & 0x03) // Page 10-0xB6[1:0]
// 0 ~ 3 (0: HI-Z, 1: PAD3i<I>, 2: PAD3o<OD>, 3: PAD3o<PP>)

// LVDS GPIO
#define _64PIN_PIN_40                                 (0 & 0x03) // Page 10-0xB7[1:0]
// 0 ~ 3 (0: HI-Z, 1: PAD4i<I>, 2: PAD4o<OD>, 3: PAD4o<PP>)

// FLASH_WP
#define _64PIN_PIN_53                                 (1 & 0x07) // Page 10-0xB9[2:0]
// 0 ~ 5 (0: P3D4i<I>, 1: P3D4o<PP>, 2: CLKO<O>,
//        3: TEST_PIN2<O>, 4:TEST_PIN3<O>, 5: DCLK<O>)

// POWER KEY
#define _64PIN_PIN_54                                 (0 & 0x07) // Page 10-0xBA[2:0]
// 0 ~ 7 (0: P3D2i<I>, 1: P3D2o<PP>, 2: INT0<I>, 3: TCON11<O>,
//        4: TEST_PIN2<O>, 5:TEST_PIN3<O>, 6: DVS<O>, 7: T0<I>)

// P_SCL(NC)
#define _64PIN_PIN_55                                 (1 & 0x07) // Page 10-0xBB[2:0]
// 0 ~ 7 (0: P3D3i<I>, 1: P3D3o<OD>, 2: P3D3o<PP>, 3: INT1<I>,
//        4: TCON9<O>, 5: TEST_PIN2<O>, 6:TEST_PIN3<O>, 7: T2EX<I>)

// P_SDA(NC)
#define _64PIN_PIN_56                                 (1 & 0x0F) // Page 10-0xBC[3:0]
// 0 ~ 9 (0: P3D5i<I>, 1: P3D5o<OD>, 2: P3D5o<PP>, 3: T1<I>, 4: TCON13<O>,
//        5: PWM2<PP>, 6:PWM3<OD>, 7: PWM3<PP>, 8: TEST_PIN2<O>, 9:TEST_PIN3<O>)

// BL_EN
#define _64PIN_PIN_57                                 (2 & 0x07) // Page 10-0xBD[2:0]
// 0 ~ 5 (0: P3D6i<I>, 1: P3D6o<OD>, 2: P3D6o<PP>, 3: TCON8<O>, 4: TEST_PIN2<O>, 5:TEST_PIN3<O>)

// BL_ADJ(PP?)
#define _64PIN_PIN_58                                 (5 & 0x0F) // Page 10-0xBE[3:0]
// 0 ~ 8 (0: P3D7i<I>, 1: P3D7o<OD>, 2: P3D7o<PP>, 3: PWM2<PP>,
//        4: PWM3<OD>, 5: PWM3<PP>, 6: TCON7<O>, 7:TEST_PIN2<O>, 8:TEST_PIN3<O>)

// POWER_ON_LATCH
#define _64PIN_PIN_63                                 (1 & 0x07) // Page 10-0xBF[2:0]
// 0 ~ 6 (0: PCD1i<I>, 1: PCD1o<OD>, 2: PCD1o<PP>, 3: PWM3<PP>,
//        4: PWM3<OD>, 5: TEST_PIN2<O>, 6:TEST_PIN3<O>)

//======================================================================================================
//======================================================================================================

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

//////////////////////////////////////
//////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                }

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                }

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
#if 1//Robert Wang 20140522 Set SPL clock/data driving to 2mA
#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                    ScalerSetBit(P10_C3_PIN_DRIVING_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);\
                                                }
#else
#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                }
#endif

#define PCB_GPIO_SETTING_POWER_AC_ON()          {\
                                                    PCB_GPIO_SETTING_POWER_DOWN();\
                                                }

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
#if(_BACKLIGHT_PWM_FREQ_SELECT == _PWMFREQ22K)
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
#define bSWIIC_SYS_EEPROM_SCL                   (MCU_PORT65_PIN_REG_FFCC) // Pin 24, P6.5
#define bSWIIC_SYS_EEPROM_SDA                   (MCU_PORT66_PIN_REG_FFCD) // Pin 25, P6.6
sbit bDDC1IICSCL                                = P3^0;                   // Pin 27
sbit bDDC1IICSDA                                = P3^1;                   // Pin 28

#define PCB_SW_IIC_SDA_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SDA = _TRUE;         \
                                                    }                                          \
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)   \
													{										   \
														bDDC1IICSDA = _TRUE;		   		   \
													}										   \
                                                }
#define PCB_SW_IIC_SDA_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SDA = _FALSE;        \
                                                    }                                          \
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
													{										   \
														bDDC1IICSDA = _FALSE;				   \
													}										   \
                                                }
#define PCB_SW_IIC_SDA_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_EEPROM_SDA;             \
                                                    }                                          \
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
													{										   \
														x = bDDC1IICSDA;						\
													}										   \
                                                }

#define PCB_SW_IIC_SCL_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SCL = _TRUE;         \
                                                    }                                          \
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
													{										   \
														bDDC1IICSCL = _TRUE;				   \
													}										   \
                                                }
#define PCB_SW_IIC_SCL_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SCL = _FALSE;        \
                                                    }                                          \
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
													{										   \
														bDDC1IICSCL = _FALSE;				   \
													}										   \
												}
#define PCB_SW_IIC_SCL_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_EEPROM_SCL;             \
                                                    }                                          \
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
													{										   \
														x = bDDC1IICSCL;				   		\
													}										   \
                                                }

//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
sbit bFLASH_WRITE_PROTECT                       = P3 ^ 4;   // Pin 53 P3.4

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = x;   \
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_PORT_PB0_PIN_REG_FF8F) // Pin 16, PB.0

#define _EEPROM_WP_ENABLE                       0//1       // WP High state for Eeprom
#define _EEPROM_WP_DISABLE                      0       // WP Low state for Eeprom

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = x;  \
                                                }

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_PORT67_PIN_REG_FFCE) // Pin 26, P6.7

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = x;\
                                                }

//-----------------------------------------------
// Macro of Input Connect Detect
//-----------------------------------------------
#define bA0_CONNECT                             (MCU_PORT_PB7_PIN_REG_FF7F) // Pin 17, PB.7

#define PCB_A0_PIN()                            (SET_A0_CABLE_STATUS(!bA0_CONNECT))

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#if((_PROJECT == _PRJ_L_LT1953S_A_TPV_TPM190A1_MWW4) || (_PROJECT == _PRJ_L_F2014_A_LG_LM195WD1_TLA1) || (_PROJECT == _PRJ_L_F2014_A_AUO_M195RTN01_0) || (_PROJECT == _PRJ_L_F2014_A_INL_M195FGE_L20))
#define bLED1                                   (MCU_PORT_PB5_PIN_REG_FF8A) // Pin 19, PB.5
#define bLED2                                   (MCU_PORT_PB6_PIN_REG_FF89) // Pin 18, PB.6  
#else
#define bLED1                                   (MCU_PORT_PB6_PIN_REG_FF89) // Pin 18, PB.6
#define bLED2                                   (MCU_PORT_PB5_PIN_REG_FF8A) // Pin 19, PB.5   
#endif

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
                                                    bLED1 = _LED_ON;               \
                                                    bLED2 = _LED_OFF;               \
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
                                                    bLED2 = _LED_ON;                \
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
#define _AD_KEY_SUPPORT                         _ON

#define AD_KEY2                                 (MCU_ADC1_RESULT_FF0A) // Pin 22, ADC1
#define AD_KEY1                                 (MCU_ADC0_RESULT_FF09) // Pin 21, ADC0
sbit IO_PowerKey                                = P3 ^ 2;// Pin 54, P3.2

#define PCB_ADKEY0()                            (_FALSE)
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)
#define PCB_ADKEY3()                            (_FALSE)

#if((_PROJECT == _PRJ_L_LS2014_A) || (_PROJECT == _PRJ_L_LS2014_A_LBL))
//(KEY:715G6931)
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x00 <= ucV1) && (ucV1 < 0x30))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if((0x30 <= ucV1) && (ucV1 < 0x70))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;     \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x00 <= ucV2) && (ucV2 < 0x30))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x30 <= ucV2) && (ucV2 < 0x70))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                            }
#elif(_PROJECT == _PRJ_L_Module_Design_A_LNT_LM238WF2_S2H1)
//(KEY:715G7299)
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x00 <= ucV1) && (ucV1 < 0x30))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x60 <= ucV1) && (ucV1 < 0x80))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;     \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x00 <= ucV2) && (ucV2 < 0x30))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x60 <= ucV2) && (ucV2 < 0x80))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                            }
#elif(_PROJECT == _PRJ_L_LT1953S_A_TPV_TPM190A1_MWW4)

#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x40 <= ucV1) && (ucV1 < 0x61))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x64 <= ucV1) && (ucV1 < 0x80))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x40 <= ucV2) && (ucV2 < 0x61))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x64 <= ucV2) && (ucV2 < 0x80))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;      \
                                                            }
#elif((_PROJECT == _PRJ_L_F2014_A_LG_LM195WD1_TLA1) || (_PROJECT == _PRJ_L_F2014_A_AUO_M195RTN01_0) || (_PROJECT == _PRJ_L_F2014_A_INL_M195FGE_L20))

#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x40 <= ucV1) && (ucV1 < 0x5C))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x5D <= ucV1) && (ucV1 < 0x75))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;      \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x40 <= ucV2) && (ucV2 < 0x5C))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if((0x5D <= ucV2) && (ucV2 < 0x75))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                            }


#else
//RTD Key
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0 <= ucV1) && (ucV1 < 0x20))       \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x40 <= ucV1) && (ucV1 < 0x80))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;     \
                                                                                                       \
                                                                if((0x90 <= ucV1) && (ucV1 < 0xE0))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0 <= ucV2) && (ucV2 < 0x20))       \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x40 <= ucV2) && (ucV2 < 0x80))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if((0x90 <= ucV2) && (ucV2 < 0xE0))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                            }

#endif

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
sbit bPANELPOWER                                = P1 ^ 0; //  Pin 32, P1.0

#define _PANEL_CONTROL_ON                       1       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      0       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

#if 0//(_PANEL_SWITCH_PAD_SUPPORT == _ON)
#define PCB_PANEL_POWER(x)                      {\
                                                    ScalerPinsharePanelSwitchControl(x);\
                                                }
#else
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }
#endif

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
sbit bBACKLIGHTPOWER                            = P3 ^ 6; // Pin 57, P3.6

#define _LIGHT_CONTROL_ON                       1      // Light on  state for backlight inverter
#define _LIGHT_CONTROL_OFF                      0       // Light off state for backlight inverter

#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = x; \
                                                }

#if(_BACKLIGHT_PWM_FREQ_SELECT == _PWMFREQ22K)
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
//-----------------------------------------------
// Macro of PCB power detect
//-----------------------------------------------
#define PCB_POWER_5V_LEVEL()                    (0xFF)//Robert Wang 20140729
#define PCB_POWER_5V_THRESHOLD                  (0xC8)

#define PCB_POWER_5V_DETECT()                   (ScalerLDOPC99PowerDetect(GET_POWER_STATUS()))

#endif // End of #if(_PCB_TYPE == _PCB_TPV_715G8037_6336_A)
