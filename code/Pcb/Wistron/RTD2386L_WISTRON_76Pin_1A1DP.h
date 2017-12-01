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
// ID Code      : RL6297_Demo_76Pin_1A1DP.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PCB_TYPE == _RTD2386L_WISTRON_76PIN_1A1DP)

#define _EXT_XTAL                               _XTAL14318K     


//--------------------------------------------------
// Input Port Define
//--------------------------------------------------
////////////////////////////////////////////////////////
//If _A0_INPUT_PORT_TYPE is _A0_NO_PORT               //
//Please remove the following functions from BL51 Misc//
//BANK0 --> ?CO?USERCOMMONMODESEARCH                  //
//BANK0 --> ?CO?RL6297_SERIES_AUTOFUNC                //
//BANK0 --> ?CO?RL6297_SERIES_PLL                     //
//Otherwise, if _A0_INPUT_PORT_TYPE is _A0_VGA_PORT   //
//Please add the above functions to BL51 Misc         //
////////////////////////////////////////////////////////
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _EMBEDDED_DDCRAM_A0_SIZE                _EDID_SIZE_NONE
#define _EMBEDDED_DDCRAM_A0_LOCATION            _EDID_TABLE_LOCATION_CODE

#define _D1_INPUT_PORT_TYPE                     _D1_DP_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC3
#define _EMBEDDED_DDCRAM_D1_SIZE                _EDID_SIZE_256
#define _EMBEDDED_DDCRAM_D1_LOCATION            _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _A0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _D1_INPUT_PORT

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

#define _LVDS_EA_PHASE                          _ENABLE             // pin86,87
#define _LVDS_EB_PHASE                          _DISABLE            // pin88,89               
#define _LVDS_EC_PHASE                          _ENABLE             // pin90,91
#define _LVDS_ED_PHASE                          _ENABLE             // pin92,93
#define _LVDS_EE_PHASE                          _ENABLE             // pin94,95
#define _LVDS_OA_PHASE                          _ENABLE             // pin74,75
#define _LVDS_OB_PHASE                          _DISABLE            // pin76,77              
#define _LVDS_OC_PHASE                          _ENABLE             // pin78,79
#define _LVDS_OD_PHASE                          _ENABLE             // pin80,81
#define _LVDS_OE_PHASE                          _ENABLE             // pin82,83

#define _LVDS_PHASE_SELECT                      _LVDS_PHASE0        // Only Phase 0 ~ 16 can be used

//--------------------------------------------------
// Definitions for LVDS EMI
//--------------------------------------------------
#define _LVDS_DATA_DRIV_CONTROL                 _LVDS_DRIV_CONTROL_3_0                  
#define _LVDS_CLK_DRIV_CONTROL                  _LVDS_DRIV_CONTROL_3_0                   

#define _LVDS_VCM_CONTROL                       _LVDS_VCM_HIGH                             
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_CAP_CONTROL                       _ENABLE
#define _LVDS_TERMINATION_CONTROL               _DISABLE

//--------------------------------------------------
// System Data Storage Options
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16               
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_76PIN_PIN_31_32
      
//-------------------------------------------------
// Sofware and Hardware IIC Options
//-------------------------------------------------
#define _SW_IIC_SUPPORT                         _ON
#define _SW_IIC_CLK_DIV                         _DIV_10                           

#define _HW_IIC_SUPPORT                         _ON
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K

//--------------------------------------------------
// Definitions for PWM Setting
//--------------------------------------------------
#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _ON
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _ON
#define _PWM5_EN                                _OFF

#define _PWM0_PSAV_EN                           _OFF
#define _PWM1_PSAV_EN                           _OFF
#define _PWM2_PSAV_EN                           _ON
#define _PWM3_PSAV_EN                           _OFF
#define _PWM4_PSAV_EN                           _OFF
#define _PWM5_PSAV_EN                           _OFF

#define _PWM0_RST_BY_DVS                        _OFF
#define _PWM1_RST_BY_DVS                        _OFF
#define _PWM2_RST_BY_DVS                        _OFF
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _ON
#define _PWM5_RST_BY_DVS                        _OFF

#define _BACKLIGHT_PWM                          _PWM4
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

//--------------------------------------------------
// Definitions for Low Speed ADC
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _ON
#define _TOUCH_KEY_SUPPORT                      _OFF

//--------------------------------------------------
// RL6297 Series Pin Share
//--------------------------------------------------
// <OD>:open-drain  <PP>:push-pull

// DDC_WPn
#define _76PIN_PIN_21                                 (2 & 0x0F) // Page 10-0xB8[1:0]
// 0 ~ 8 (0: PDD0i<I>, 1: PDD0o<PP>, 2: PDD0o<OD>, 3: TCON[14]<O>, 4: TEST_PIN0<O>,
//        5: TEST_PIN1<O>, 6: DUMMY<O>) 

// GREEN
#define _76PIN_PIN_22                                 (1 & 0x07) // Page 10-0xB9[1:0]////////////////2
// 0 ~ 6 (0: PCD4i<I>, 1: PCD4o<PP>, 2: PCD4o<OD>, 3: VCLK, 4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>) 

// KEY_POWER /BLUE
#define _76PIN_PIN_23                                 (1 & 0x07) // Page 10-0xA0[7:6]
// 0 ~ 6 (0: PBD7i<I>, 1: PBD7o<PP>, 2: PBD7o<OD>, 3: TCON5<O>, 4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>)

// VGA_CABLE_DET
#define _76PIN_PIN_24                                 (0 & 0x07) // Page 10-0xA0[5:4]
// 0 ~ 5 (0: PBD6i<I>, 1: PBD6o<PP>, 2: PBD6o<OD>, 3: TEST_PIN0<O>, 4: TEST_PIN1<O>, 
//        5: DUMMY<O>, 6:IIC) 

// USB_EN
#define _76PIN_PIN_25                                 (1 & 0x07) // Page 10-0xA0[3:2]
// 0 ~ 5 (0: PBD5i<I>, 1: PBD5o<PP>, 2: PBD5o<OD>, 3: TEST_PIN0<O>, 4: TEST_PIN1<O>, 
//        5: DUMMY<O>, 6:IIC) 

// USB_DET
#define _76PIN_PIN_27                                 (0 & 0x07) // Page 10-0xAB[7:5]
// 0 ~ 7 (0: P6D0i<I>, 1: P6D0o<PP>, 2: P6D0o<OD>, 3: ADCA0<I>, 4: VCLK<I>,
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>)  
#if(_TOUCH_KEY_SUPPORT == _ON)
// KEY_ADC1
#define _76PIN_PIN_28                                 (2 & 0x07) // Page 10-0xA3[5:4]
// 0 ~ 6 (0: P6D1i<I>, 1: P6D1o<PP>, 2: P6D1o<OD>, 3: ADCA1<I>,4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>)  

// KEY_ADC2
#define _76PIN_PIN_29                                 (2 & 0x07) // Page 10-0xA4[7:6]
// 0 ~ 6 (0: P6D2i<I>, 1: P6D2o<PP>, 2: P6D2o<OD>, 3: ADCA2<I>,4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>)
#else
// KEY_ADC1
#define _76PIN_PIN_28                                 (3 & 0x07) // Page 10-0xA3[5:4]
// 0 ~ 6 (0: P6D1i<I>, 1: P6D1o<PP>, 2: P6D1o<OD>, 3: ADCA1<I>,4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>)  

// KEY_ADC2
#define _76PIN_PIN_29                                 (3 & 0x07) // Page 10-0xA4[7:6]
// 0 ~ 6 (0: P6D2i<I>, 1: P6D2o<PP>, 2: P6D2o<OD>, 3: ADCA2<I>,4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>)
#endif
// WP_PRO / STANDBY_CTRL
#define _76PIN_PIN_30                                 (1 & 0x0F) // Page 10-0xA6[5:3]
// 0 ~ 11 (0: P6D5i<I>, 1: P6D5o<PP>, 2: P6D5o<OD>, 3: PWM1<PP>, 4: PWM1<OD>, 
//         5: PWM5<PP>, 6: PWM5<OD>, 7: TCON0<O>,8: TCON5<O>, 
//         9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>)

// EESCL
#define _76PIN_PIN_31                                 (8 & 0x0F) // Page 10-0xAF[6:4]
// 0 ~ 7 (0: P6D6i<I>, 1: P6D6o<PP>, 2: P6D6o<OD>, 3: TCON1<O>, 4: TCON4<O>,
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>, 8:HWIIC, 9:IIC_AUX)

// EESDA
#define _76PIN_PIN_32                                 (8 & 0x0F) // Page 10-0xAF[3:1]
// 0 ~ 7 (0: P6D7i<I>, 1: P6D7o<PP>, 2: P6D7o<OD>, 3: TCON9<O>, 4: TCON11<O>,
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>, 8:HWIIC, 9:IIC_AUX)
// IIC function needs to be selected for both pins (31 & 32)

// DDCSCL1
#define _76PIN_PIN_33                                 (9 & 0x0F) // Page 10-0xA2[6:4]
// 0 ~ 9 (0: P3D0i<I>, 1: P3D0o<PP>, 2: P3D0o<OD>, 3: RXD<OD>, 4: TCON7<O>, 
//        5: TCON10<O>,6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>, 9: DDCSCL1<OD>))

// DDCSDA1
#define _76PIN_PIN_34                                 (9 & 0x0F) // Page-10-0xA2[3:1]
// 0 ~ 9 (0: P3D1i<I>, 1: P3D1o<PP>, 2: P3D1o<OD>, 3: TXD<OD>, 4: TCON3<O>, 
//        5: TCON5<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>, 9: DDCSDA1<OD>))
// DDC1 function needs to be selected for both pins (33 & 34)         

// AMBER
#define _76PIN_PIN_37                                 (1 & 0x0F) // Page 10-D8 Pin 63  //////////////3
// 0 ~ 11 (0: PCD3i<I>, 1: PCD3o<PP>, 2: PCD3o<OD>, 3: PWM2<PP> , 4: PWM2<OD>, 
//         5: TCON1<O>, 6: TCON8<O>, 7: TCON16<O>, 8:INT0<I>, 
//         9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>)

// Panel On PANELVCC_EN
#define _76PIN_PIN_38                                 (1 & 0x1F) // Page 10-0xA3[3:0]
// 0 ~ 17(0: P1D0i<I>, 1: P1D0o<PP>, 2: P1D0o<OD>, 3: PWM0<PP>, 4: PWM0<OD>,
//        5: PWM3<PP>, 6: PWM3<OD>, 7: TCON0<O>, 8: TCON6<O>, 9: TCON7<O>,
//        10: TCON15<O>,11: Reserved, 12:Reserved, 13:T2<I>, 14:INT1<I>,
//        15: TEST_PIN0<O>, 16: TEST_PIN1<O>, 17: DUMMY<O>) 

#define _76PIN_PIN_39_40_41_42_43_44_45_46            (0 & 0x03) // Page 10-0xA9[7:6]
// 0 ~ 3 (0: Hi-Z, 1: GPI, 2: GPO<PP>, 3:GP<OD>)
// Active if single-port LVDS without E/O swap and global power saving/down disabled
#define _76PIN_PIN_39                                 (0 & 0x03) // Page 10-0xB6[7:6]
// 0 ~ 3 (0: P9D0o<PP>, 1: Reserved, 2: Reserved, 3: DUMMY<O>)
#define _76PIN_PIN_40                                 (0 & 0x03) // Page 10-0xB6[5:4]
// 0 ~ 3 (0: P9D1o<PP>, 1: Reserved, 2: Reserved, 3: DUMMY<O>) 
#define _76PIN_PIN_41                                 (0 & 0x03) // Page 10-0xB6[3:2]
// 0 ~ 3 (0: P9D4o<PP>, 1: Reserved, 2: Reserved, 3: DUMMY<O>) 
#define _76PIN_PIN_42                                 (0 & 0x03) // Page 10-0xB6[1:0]
// 0 ~ 3 (0: PAD0o<PP>, 1: Reserved, 2: Reserved, 3: DUMMY<O>)        

// FLASH_WP
#define _76PIN_PIN_58                                 (1 & 0x0F) // Page 10-0xAD[6:4]
// 0 ~ 11 (0: P3D2i<I>, 1: P3D2o<PP>, 2: P3D2o<OD>, 3 INT0<I>, 4: TCON3<O>, 
//         5: Reserved, 6: AUX_D1<O>, 7: PWM2<PP>, 8: PWM2<OD>,9: TEST_PIN2<O>,
//         10: TEST_PIN3<O>, 11: DUMMY<O>)  

// DP_SINK
#define _76PIN_PIN_59                                 (0 & 0x0F) // Page 10-0xAD[2:0]
// 0 ~ 9 (0: P3D3i<I>, 1: P3D3o<PP>, 2: P3D3o<OD>, 3: TCON2<O>, 4: TCON6<O>, 
//        5: TCON7<O>, 6: INT1<I>, 7: Reserved, 8: Reserved, 9: TEST_PIN2<O>, 
//        10: TEST_PIN3<O>, 11: DUMMY<O>) 

//DPRX_HPD
#define _76PIN_PIN_60                                 (1 & 0x0F) // Page 10-0xAE[6:4]
// 0 ~ 10 (0: P3D4i<I>, 1: P3D4o<PP>, 2: P3D4o<OD>, 3: TCON4<O>, 4: TCON7<O>, 
//         5: T0<I>, 6: Reserved, 7: Reserved,8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 
//         10: DUMMY<O>)

// DP_DET
#define _76PIN_PIN_61                                 (0 & 0x0F) // Page 10-0xAE[2:0]
// 0 ~ 11 (0: P3D5i<I>, 1: P3D5o<PP>, 2: P3D5o<OD>, 3: TCON5<O>, 4: TCON9<O>, 
//         5: T1<O>, 6: Reserved, 7: Reserved,8: Reserved,9: TEST_PIN2<O>, 
//         10: TEST_PIN3<O>, 11: DUMMY<O>) 

// BL_EN
#define _76PIN_PIN_62                                 (1 & 0x0F) // Page 10-0xB0[7:5]
// 0 ~ 11 (0: P3D6i<I>, 1: P3D6o<PP>, 2: P3D6o<OD>, 3: TCON1<O>, 4: TCON11<O>, 
//         5: Reserved, 6: Reserved, 7: AUX_D2<O>, 8: Reserved, 9: TEST_PIN2<O>,
//         10: TEST_PIN3<O>, 11: DUMMY<O>) 

// BL_ADJ
#define _76PIN_PIN_63                                 (3 & 0x0F) // // Page 10-F4 Pin 114 
// 0 ~ 12 (0: P3D7i<I>, 1: P3D7o<PP>, 2: P3D7o<OD>, 3: PWM4<PP>,4: PWM4<OD>, 
//         5: TCON0<O>, 6: TCON13<O>, 7: Reserved, 8: Reserved, 9: Reserved,
//         10: TEST_PIN2<O>, 11: TEST_PIN3<O>, 12: DUMMY<O>) 

// V33P
#define _76PIN_PIN_68                                 (0 & 0x0F) // Page 10-0xA1[5:3]
// 0 ~ 10 (0: Reserved, 1: PCD1o<PP>, 2: PCD1o<OD>, 3: PWM1<PP>, 4: PWM1<OD>, 
//         5: PWM5<PP>,6: PWM5<OD>, 7: Reserved,8: TEST_PIN2<O>, 9: TEST_PIN3<O>,
//         10: DUMMY<O>)

// AUX_CHP
#define _76PIN_PIN_70                                 (3 & 0x07) // Page 10-0xB0[3:2]
// 0 ~ 6 (0: P7D3i<I>, 1: P7D3o<PP>, 2: P7D3o<OD>, 3: AUX_CH_P1, 4: TEST_PIN2<O>,
//        5: TEST_PIN3<O>, 6: DUMMY<O>, 7:DDCSCL3) 
// AUX_CHN
#define _76PIN_PIN_71                                 (3 & 0x07) // Page 10-0xB0[1:0]
// 0 ~ 6 (0: P7D2i<I>, 1: P7D2o<PP>, 2: P7D2o<OD>, 3: AUX_CH_N1, 4: TEST_PIN2<O>, 
//        5: TEST_PIN3<O>, 6: DUMMY<O>, 7:DDCSDA3) 
// DDC3 function needs to be selected for both pins (70 & 71)

//======================================================================================================
//======================================================================================================

//-----------------------------------------------
// Macro of Pcb Gpio Inital Setting
//-----------------------------------------------

// Enable Write Protect for EEPROM and FLASH
#define PCB_GPIO_INITIAL_SETTING()              {\
                                                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_ENABLE); \
                                                    PCB_PANEL_POWER(_PANEL_CONTROL_OFF); \
                                                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW); \ 
                                                    PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF); \
                                                    PCB_LED_OFF(); \                                                    
                                                }

//////////////////////////////////////
// Pin39~40,50~53 Function Normal   //
// Pin65~72,96~103 Normal Operation //
//////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~(_BIT7 | _BIT0), 0x00);    \    
                                                    ScalerSetBit(P10_B9_PIN_SHARE_CTRL16, ~(_BIT5 | _BIT4), ((BYTE)_P41_48_SEL << 4));    \                                                
                                                    ScalerSetByte(P10_BB_PIN_PULLUP_CTRL4, 0x00);                    \    
                                                }

////////////////////////////////////////////////////////
// Pin39~40 pull up control --> GPIO Function Disable //
// Pin65~72,96~103 pull up Control                    //    
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT0, _BIT0);    \                                
                                                    ScalerSetByte(P10_BB_PIN_PULLUP_CTRL4, 0xFF);            \
                                                }

////////////////////////////////////////////////////////
// Pin50~53 pull up control --> GPIO Function Disable //
// Pin39~40 pull up control --> GPIO Function Disable //
// Pin65~72,96~103 pull up Control                    //
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_DOWN()            {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT0, _BIT0);    \
                                                    ScalerSetByte(P10_BB_PIN_PULLUP_CTRL4, 0xFF);            \
                                                }

#define PCB_GPIO_SETTING_POWER_AC_ON()          {\
                                                    PCB_GPIO_SETTING_POWER_DOWN();\
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
#define bSWIIC_SYS_EEPROM_SCL                   (MCU_PORT66_PIN_REG_FFCD) // Pin 31, P6.6
#define bSWIIC_SYS_EEPROM_SDA                   (MCU_PORT67_PIN_REG_FFCE) // Pin 32, P6.7

sbit bSWIIC_EDID_EEPROM_SCL_VGA                 = P3 ^ 0;//_76PIN_PIN_33
sbit bSWIIC_EDID_EEPROM_SDA_VGA                 = P3 ^ 1;//_76PIN_PIN_34

#define bSWIIC_TOUCH_KEY_SCL                    (MCU_PORT61_PIN_REG_FFC8)  //_76PIN_PIN_28
#define bSWIIC_TOUCH_KEY_SDA                    (MCU_PORT62_PIN_REG_FFC9) //_76PIN_PIN_29

#define PCB_SW_IIC_SDA_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SDA = _TRUE;         \
                                                    }                                          \ 
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_TOUCHKEY) \
                                                    {                                          \
                                                        bSWIIC_TOUCH_KEY_SDA = _TRUE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SDA_VGA = _TRUE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SDA_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SDA = _FALSE;        \
                                                    }   \
                                                     else if(GET_SW_IIC_STATUS() == _IIC_SYS_TOUCHKEY) \
                                                    {                                          \
                                                        bSWIIC_TOUCH_KEY_SDA = _FALSE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SDA_VGA = _FALSE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SDA_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_EEPROM_SDA;             \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_TOUCHKEY) \
                                                    {                                          \
                                                        x = bSWIIC_TOUCH_KEY_SDA;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        x = bSWIIC_EDID_EEPROM_SDA_VGA;         \
                                                    }                                          \
                                                }

#define PCB_SW_IIC_SCL_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SCL = _TRUE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_TOUCHKEY) \
                                                    {                                          \
                                                         bSWIIC_TOUCH_KEY_SCL=_TRUE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SCL_VGA = _TRUE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SCL_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SCL = _FALSE;        \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_TOUCHKEY) \
                                                    {                                          \
                                                         bSWIIC_TOUCH_KEY_SCL=_FALSE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SCL_VGA = _FALSE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SCL_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_EEPROM_SCL;             \
                                                    }                                          \
                                                     else if(GET_SW_IIC_STATUS() == _IIC_SYS_TOUCHKEY) \
                                                    {                                          \
                                                         x = bSWIIC_TOUCH_KEY_SCL;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        x = bSWIIC_EDID_EEPROM_SCL_VGA;         \
                                                    }                                          \
                                                }

#define VGA2Host()                              {\
                                                    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);\
                                                    SET_SW_IIC_STATUS(_IIC_FOR_DDC1);\
                                                }

#define VGA2Slave()                             {\
                                                    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);\
                                                    SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);\
                                                }

#define HDMI2Host()                             {\
                                                }

#define HDMI2Slave()                            {\
                                                }

#define DVI2Host()                              {\
                                                }

#define DVI2Slave()                             {\
                                                }


//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
sbit bFLASH_WRITE_PROTECT                       = P3 ^ 2;   // _76PIN_PIN_58, P3.2

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = x;   \
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_PORT65_PIN_REG_FFCC)  // _76PIN_PIN_30

#define _EEPROM_WP_ENABLE                       1       // WP High state for Eeprom
#define _EEPROM_WP_DISABLE                      0       // WP Low state for Eeprom

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = x;\
                                                }

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_PORT_PD0_PIN_REG_FF7E)    // _76PIN_PIN_21

#define _EDID_EEPROM_WP_HIGH                    1
#define _EDID_EEPROM_WP_LOW                     0
#define PCB_EDID_WRITE_PROTECT_DETECT()         (bEDID_WRITE_PROTECT)

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = x;\
                                                }

#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = x;\
                                                }

//-----------------------------------------------
// Macro of Input Connect Detect
//-----------------------------------------------
sbit bDP_PIN15_CONNECT                          = P3 ^ 3;  //_76PIN_PIN_59
sbit bDP_PIN16_CONNECT                          = P3 ^ 5;  //_76PIN_PIN_61
//#define bDP_PIN17_CONNECT                     (MCU_PORT62_PIN_REG_FFC9) // Pin 29, P6.2

#define bA0_CONNECT                             (MCU_PORT_PB6_PIN_REG_FF89) // _76PIN_PIN_24
#define bD1_CONNECT                             (((bit)bDP_PIN15_CONNECT == _TRUE) && ((bit)bDP_PIN16_CONNECT == _TRUE))// && ((bit)bDP_PIN17_CONNECT == _FALSE))

#define PCB_A0_PIN()                            (SET_A0_CABLE_STATUS(!bA0_CONNECT))
#define PCB_D1_PIN()                            (SET_D1_CABLE_STATUS(!bD1_CONNECT))

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
sbit bD1_HPD                                    = P3 ^ 4;  //_76PIN_PIN_60
#define _D1_HOT_PLUG_HIGH                       1       // D1 Switch High state
#define _D1_HOT_PLUG_LOW                        0       // D1 Switch Low state

#define PCB_D1_HOTPLUG(x)                       {\
                                                    bD1_HPD = x;                    \
                                                }

//-----------------------------------------------
// Macro of Digital Port Switch
//-----------------------------------------------
#define PCB_DIGITAL_SWITCH_TO_D1()              {\
                                                }

#define PCB_DIGITAL_SWITCH_TO_D1_IDLE()         {\   
                                                }

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   (MCU_PORTC3_PIN_REG_FFA0) // _76PIN_PIN_37 AMBER
#define bLED2                                   (MCU_PORT_PB7_PIN_REG_FF7F) // _76PIN_PIN_23 BLUE
#define bLED3                                   (MCU_PORTC4_PIN_REG_FFA4) //_76PIN_PIN_22  GREEN

#define _LED_ON                                 1       // Power on  state for LED
#define _LED_OFF                                0       // Power off state for LED


#define _LED_PWM_MAX                            255
#define _LED_PWM_MIN                            0

#define PCB_LED_ACTIVE()                        {\
								                        PCB_LED_ON()			\
							                    }

#define PCB_LED_IDLE()                          {\
								                        PCB_LED_TYPE_FLASH()	\
							                    }

#define PCB_LED_ON()                            {\
	                                                bLED3=_LED_ON; \
	                                                bLED1 =_LED_OFF;\
                                                }

#define PCB_LED_POWER_SAVING()                  {\
	                                              bLED3 =_LED_OFF;\
												  bLED1 =_LED_ON;\
                                                }

#define PCB_LED_OFF()                           {\
												  bLED3 =_LED_OFF;\
												  bLED1 =_LED_OFF;\
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
							                        MCU_PWM2H_DUT_FF4D = x;\
                                                }

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
// Must Check Wether _LOW_SPEED_ADC_SUPPORT is Supported
#define _AD_KEY_SUPPORT                         _ON

#define AD_KEY1                                 (MCU_ADC1_RESULT_FF0A)//_76PIN_PIN_28
#define AD_KEY2                                 (MCU_ADC2_RESULT_FF0B)//_76PIN_PIN_29
//#define bPOWER_KEY                              (MCU_PORT_PB7_PIN_REG_FF7F)//_76PIN_PIN_23

#define PCB_ADKEY0()                            (_FALSE)
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)
#define PCB_ADKEY3()                            (_FALSE)

#if(_TOUCH_KEY_SUPPORT == _OFF)
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x30 <= ucV1) && (ucV1 < 0x40))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;     \
                                                                                                       \
                                                                if((0x70 <= ucV1) && (ucV1 < 0x90))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x00 <= ucV2) && (ucV2 < 0x40))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if((0x70 <= ucV2) && (ucV2 < 0x89))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x90 <= ucV2) && (ucV2 < 0xB0))    \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                            }
#else
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                    			if(ucV0 &_BIT2)                             \    
                                                    				ucKeyState=ucKeyState|_EXIT_KEY_MASK;   \
                                                                                                            \
                                                    			if(ucV0 &_BIT3)                             \
                                                    				ucKeyState=ucKeyState|_MENU_KEY_MASK;   \
                                                                                                            \
                                                    			if(ucV0 &_BIT1)                             \
                                                    				ucKeyState=ucKeyState|_RIGHT_KEY_MASK;  \
                                                                                                            \
                                                    			if(ucV0 &_BIT0)                             \
                                                    				ucKeyState=ucKeyState|_LEFT_KEY_MASK;   \
                                                            }
#endif
//--------------------------------------------------
// Definitions of Touch Key
//--------------------------------------------------
#define _TOUCHPAD_DRICE_ADDRESS                 0x58

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
sbit bPANELPOWER                                = P1 ^ 0;   //  _76PIN_PIN_38

#define _PANEL_CONTROL_ON                       1       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      0       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = x;                \
                                                }

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
sbit bBACKLIGHTPOWER                            = P3 ^ 6; // _76PIN_PIN_62, P3.6

#define _LIGHT_CONTROL_ON                       1//0       // Light on  state for backlight inverter
#define _LIGHT_CONTROL_OFF                      0//1       // Light off state for backlight inverter

#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = x; \
                                                }
                                                
#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if(x == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                        if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)\
                                                        {\
                                                            ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, (WORD)((GET_INPUT_TIMING_VFREQ() * 2000) / 100)); \
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
                                                    MCU_PWM4H_DUT_FF50 = x;         \
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_PWM4H_DUT_FF50)

//-----------------------------------------------
// Macro of Power Board Low Power Pin High/Low
//-----------------------------------------------
#define _LOW_POWER_ON                           1       // Low power on state
#define _LOW_POWER_OFF                          0       // Low power off state

#define PCB_POWERBOARD_LOWPOWER(x)              {\
                                                }

//-----------------------------------------------
// Macro of Audio Amp High/Low
//-----------------------------------------------
#define PCB_AUDIO_DETECT()                      (_FALSE)

#define _AUDIO_POWER_ON                         0       // Audio Power on state
#define _AUDIO_POWER_OFF                        1       // Audio Power off state

#define PCB_AUDIO_POWER(x)                      {\
                                                }
//-----------------------------------------------
sbit bAmpPowe                                   = P3 ^ 3;//_PIN_119

#define _AMP_POWER_ON                           1       // Amp on state
#define _AMP_POWER_OFF                          0       // Amp off state

#define PCB_AMP_POWER(x)                        {\
                                                }
//-----------------------------------------------
#define _AMP_STAND_BY_ON                        1       // Amp Stand By on state
#define _AMP_STAND_BY_OFF                       0       // Amp Stand By off state

#define PCB_AMP_STAND_BY(x)                     {\
                                                }
//-----------------------------------------------
#define bPCBAMPMUTECONTROL                      (MCU_PORT56_PIN_REG_FFC5) // _PIN_100, P5.6

#define _AMP_MUTE_ON                            1       // Amp Mute on state
#define _AMP_MUTE_OFF                           0       // Amp Mute off state

#define PCB_AMP_MUTE(x)                         {\
                                                }


#define PCB_AUDIO_VOLUME_PWM(x)                 {\
                                                }


//-----------------------------------------------
// Macro of Usb Hub High/Low
//-----------------------------------------------
#define PCB_USB_DETECT()                        (MCU_PORT60_PIN_REG_FFC7)//_76PIN_PIN_27

#define _USB_POWER_ON                           1       // USB power on state
#define _USB_POWER_OFF                          0       // USB power off state

#define PCB_USB_POWER(x)                        {\
                                                }

//-----------------------------------------------
// Macro of Usb Hub High/Low
//-----------------------------------------------
#define PCB_USB_EN()                            (MCU_PORT_PB5_PIN_REG_FF8A)//_76PIN_PIN_25

//-----------------------------------------------
// Macro of Dynamic High/Low
//-----------------------------------------------
#define _BACKLIGHT_HIGH_DYNAMIC_ON              30
#define _BACKLIGHT_HIGH_DYNAMIC_OFF             216

#define PCB_BACKLIGHT_HIGH_DYNAMIC(x)           {\
                                                }

#endif // End of #if(_PCB_TYPE == _RL6297_DEMO_76PIN_1A1DP)

