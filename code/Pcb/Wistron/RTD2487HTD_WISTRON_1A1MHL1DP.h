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
// ID Code      : RTD2487HTD_WISTRON_1A1MHL1DP.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PCB_TYPE == _RTD2487HTD_WISTRON_1A1MHL1DP)

#define _EXT_XTAL                               _XTAL14318K      


//--------------------------------------------------
// Input Port Define
//--------------------------------------------------
////////////////////////////////////////////////////////
//If _A0_INPUT_PORT_TYPE is _A0_NO_PORT               //
//Please remove the following functions from BL51 Misc//
//BANK0 --> ?CO?USERCOMMONMODESEARCH                  //
//BANK0 --> ?CO?RL6229_SERIES_AUTOFUNC                //
//BANK0 --> ?CO?RL6229_SERIES_PLL                     //
//Otherwise, if _A0_INPUT_PORT_TYPE is _A0_VGA_PORT   //
//Please add the above functions to BL51 Misc         //
////////////////////////////////////////////////////////
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _EMBEDDED_DDCRAM_A0_SIZE                _EDID_SIZE_NONE
#define _EMBEDDED_DDCRAM_A0_LOCATION            _EDID_TABLE_LOCATION_CODE

#define _D0_INPUT_PORT_TYPE                     _D0_MHL_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC3
#define _D0_CBUS_CHANNEL_SEL                    _CBUS1
#define _EMBEDDED_DDCRAM_D0_SIZE                _EDID_SIZE_NONE
#define _EMBEDDED_DDCRAM_D0_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _EMBEDDED_DDCRAM_D0_MHL_SIZE            _EDID_SIZE_256
#define _EMBEDDED_DDCRAM_D0_MHL_LOCATION        _EDID_TABLE_LOCATION_USER

#define _D1_INPUT_PORT_TYPE                     _D1_DP_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC2
#define _EMBEDDED_DDCRAM_D1_SIZE                _EDID_SIZE_256
#define _EMBEDDED_DDCRAM_D1_LOCATION            _EDID_TABLE_LOCATION_USER

#define _D2_INPUT_PORT_TYPE                     _D2_NO_PORT
#define _D2_INPUT_PORT_SWITCH_FROM              _SWITCH_NONE

#define _D3_INPUT_PORT_TYPE                     _D3_NO_PORT
#define _D3_INPUT_PORT_SWITCH_FROM              _SWITCH_NONE

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D2_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_2
#define _D3_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_2
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _VI_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_2

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _A0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _D0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_2                _D1_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_3                _D2_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_4                _D3_INPUT_PORT

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
// TMDS Signal Swap Select
//--------------------------------------------------
#define _D0_TMDS_BR_SWAP                        _ON
#define _D0_TMDS_PN_SWAP                        _ON

#define _D1_TMDS_BR_SWAP                        _ON
#define _D1_TMDS_PN_SWAP                        _ON

//--------------------------------------------------
// DP Signal Swap Select : DP PHY Lane, P/N Swap Setting
//--------------------------------------------------
#define _PCB_DP_CONNECTOR_SWAP                  _ON




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

#define _LVDS_EA_PHASE                          _LVDS_PI_PHASE_N1   // pin77,78
#define _LVDS_EB_PHASE                          _LVDS_PI_PHASE_N2   // pin79,80              
#define _LVDS_EC_PHASE                          _LVDS_PI_PHASE_N1   // pin81,82
#define _LVDS_ED_PHASE                          _LVDS_PI_PHASE_N1   // pin83,84
#define _LVDS_EE_PHASE                          _LVDS_PI_PHASE_N1   // pin85,86
#define _LVDS_OA_PHASE                          _LVDS_PI_PHASE_N1   // pin65,66
#define _LVDS_OB_PHASE                          _LVDS_PI_PHASE_N2   // pin67,68               
#define _LVDS_OC_PHASE                          _LVDS_PI_PHASE_N1   // pin69,70
#define _LVDS_OD_PHASE                          _LVDS_PI_PHASE_N1   // pin71,72
#define _LVDS_OE_PHASE                          _LVDS_PI_PHASE_N1   // pin73,74

#define _LVDS_PHASE_N1_SELECT                   _LVDS_PHASE0        // Only Phase 0 ~ 16 can be used
#define _LVDS_PHASE_N2_SELECT                   _LVDS_PHASE0        // Only Phase 0 ~ 16 can be used

//--------------------------------------------------
// Definitions for LVDS EMI
//--------------------------------------------------
#define _LVDS_DATA_DRIV_CONTROL                 _LVDS_DRIV_CONTROL_3_0                  
#define _LVDS_CLK_DRIV_CONTROL                  _LVDS_DRIV_CONTROL_3_0                   

#define _LVDS_VCM_CONTROL                       _LVDS_VCM_HIGH                             
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_TERMINATION_CONTROL               _ENABLE

//--------------------------------------------------
// System Data Storage Options
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16               
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_52_53

//-------------------------------------------------
// Sofware and Hardware IIC Options
//-------------------------------------------------
#define _SW_IIC_SUPPORT                         _ON
#define _SW_IIC_CLK_DIV                         _DIV_1                           

#define _HW_IIC_SUPPORT                         _ON
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

#define _AUDIO_VOLUME_PWM                       _NO_PWM            
#define _AUDIO_VOLUME_PWM_INVERSE               _OFF

#define _BACKLIGHT_PWM                          _PWM5
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

//--------------------------------------------------
// Definitions for Low Speed ADC
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _ON

//--------------------------------------------------
// Definitions for Eled PCB Related
//--------------------------------------------------
#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
#define _ELED_PCB_VI_VOLTAGE                    12      //12~19 Unit: Voltage
#define _ELED_PCB_INDUCTOR_VALUE                33      //33~47 Unit: Hunry
#define _ELED_PCB_RSENSE_VALUE                  10      //5~10 Unit: 0.01ohm
#define _ELED_PCB_OVP_RATION                    47      //27~50 OVP_R1 = 180K, OVP_R2 = 3.9K (OVP_R1 + OVP_R2)/OVP_R2 
#define _ELED_VFB_RESISTOR                      _VFB_RESISTOR_5_OHM    	// 5 or 10 VFB Resistor
#define _ELED_DIMMING_PWM                       _DIMMING_PWM_240        // 180 or 240Hz Dimming PWM Frequency
#define _ELED_BOOSTER_PWM                       _BOOSTER_PWM_300K       // 300 or 400KHz Booster PWM Frequency

//--------------------------------------------------
// Definitions for Eled PCB LED String Support
//--------------------------------------------------
#define _ELED_STRING0                           _ON
#define _ELED_STRING1                           _ON
#define _ELED_STRING2                           _ON
#define _ELED_STRING3                           _ON
#define _ELED_STRING4                           _ON
#define _ELED_STRING5                           _ON
#define _ELED_STRING6                           _ON
#define _ELED_STRING7                           _ON
#endif

// RL6269 Series Pin Share
//--------------------------------------------------
// <OD>:open-drain  <PP>:push-pull

// PS_CTRL
#define _PIN_1                                  (1 & 0x07) // Page 10-0xA0[2:0]
// 0 ~ 6 (0: PCD1i<I>, 1: PCD1o<PP>, 2: PCD1o<OD>, 3: CEC<IO>, 4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>)

// DP_HPD
#define _PIN_22                                 (1 & 0x0F) // Page 10-0xA1[3:0]
// 0 ~ 8 (0: PDD7i<I>, 1: PDD7o<PP>, 2: PDD7o<OD>, 3: TCON[0]<O>, 4: TCON[8]<O>, 
//        5: SPDIF0<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>)

// Power On Latch
#define _PIN_23                                 (0 & 0x0F) // Page 10-0xA2[3:0]
// 0 ~ 9 (0: Reserved, 1: PDD6o<PP>, 2: PDD6o<OD>, 3: TCON[1]<O>, 4: TCON[9]<O>,
//        5: SPDIF<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>)

// CBUS1/HDMI_HPD
#define _PIN_24                                 (2 & 0x0F) // Page 10-0xA3[3:0]
// 0 ~ 8 (0: PDD5i<I>, 1: PDD5o<PP>, 2: PDD5o<OD>, 3: TCON[2]<O>, 4: TCON[10]<O>,
//        5: SPDIF2<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>)

// HDMI_CAB_DET
#define _PIN_25                                 (0 & 0x0F) // Page 10-0xA4[3:0]
// 0 ~ 9 (0: PDD4i<I>, 1: PDD4o<PP>, 2: PDD4o<OD>, 3: TCON[3]<O>, 4: TCON[11]<O>, 
//        5: SPDIF3<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>, 9: VCLK<I>)

// ONELINK_DET
#define _PIN_26                                 (0 & 0x0F) // Page 10-0xA5[2:0]
// 0 ~ 7 (0: PDD3i<I>, 1: PDD3o<PP>, 2: PDD3o<OD>, 3: TCON[4]<O>, 4: TCON[12]<O>, 
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>, 8: IIC1<IO>)

// VGA_CAB_DET
#define _PIN_27                                 (0 & 0x0F) // Page 10-0xA6[2:0]
// 0 ~ 7 (0: PDD2i<I>, 1: PDD2o<PP>, 2: PDD2o<OD>, 3: TCON[5]<O>, 4: TCON[13]<O>, 
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>, 8: IIC1<IO>)

#if(_EMBEDDED_DAC_SUPPORT == _ON)
// Audio 39~45
#define _P39_45_SEL                             (1 & 0x01) // Page 10-0xA7[7]
// 0 ~ 1 (0: Normal Function, 1: Audio)
#else
// Audio 39~45
#define _P39_45_SEL                             (0 & 0x01) // Page 10-0xA7[7]
// 0 ~ 1 (0: Normal Function, 1: Audio)
#endif

// NC
#define _PIN_39                                 (0 & 0x07) // Page 10-0xA7[2:0]
// 0 ~ 6 (0: PDD1i<I>, 1: PDD1o<PP>, 2: PDD1o<OD>, 3: TCON[0]<O>, 4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>, 7: IIC2<IO>)
// NC
#define _PIN_40                                 (0 & 0x07) // Page 10-0xA8[2:0]
// 0 ~ 6 (0: PDD0i<I>, 1: PDD0o<PP>, 2: PDD0o<OD>, 3: TCON[1]<O>, 4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>, 7: IIC2<IO>)

// Audio_Ref
#define _PIN_41                                 (0 & 0x01) // Page 10-0xA9[1:0]
// 0 ~ 1 (0: PCD4i<I>, 1: DUMMY<O>)

// Audio_SpeakeroutL
#define _PIN_42                                 (0 & 0x03) // Page 10-0xAA[1:0]
// 0 ~ 2 (0: PBD7i<I>, 1: INT0_MHL0<I>, 2: DUMMY<O>)
// Audio_SpeskeroutR
#define _PIN_43                                 (0 & 0x03) // Page 10-0xAB[1:0]
// 0 ~ 2 (0: PBD6i<I>, 1: INT0_MHL1<I>, 2: DUMMY<O>)

// NC
#define _PIN_44                                 (0 & 0x01) // Page 10-0xAC[1:0]
// 0 ~ 1 (0: PBD5i<I>, 1: DUMMY<O>)
// NC
#define _PIN_45                                 (0 & 0x01) // Page 10-0xAD[1:0]
// 0 ~ 1 (0: PBD4i<I>, 1: DUMMY<O>)

// CD-Sense/MHL DET
#define _PIN_47                                 (0 & 0x07) // Page 10-0xAE[2:0]
// 0 ~ 6 (0: PBD3i<I>, 1: PBD3o<PP>, 2: PBD3o<OD>, 3: ADCA0(8bit)<I>, 4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>)

// ADC_Key1
#define _PIN_48                                 (3 & 0x07) // Page 10-0xAF[2:0]
// 0 ~ 6 (0: PBD2i<I>, 1: PBD2o<PP>, 2: PBD2o<OD>, 3: ADCA1(8bit)<I>, 4: TEST_PIN0<O>, 
//        5: TEST_PIN1<O>, 6: DUMMY<O>)

// ADC_Key2
#define _PIN_49                                 (3 & 0x07) // Page 10-0xB0[2:0]
// 0 ~ 7 (0: PBD1i<I>, 1: PBD1o<PP>, 2: PBD1o<OD>, 3: ADCA2(8bit)<I>, 4: INT0_MHL2<I>,
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>)

// VOIP_HOOK:NC
#define _PIN_50                                 (1 & 0x07) // Page 10-0xB1[2:0]
// 0 ~ 7 (0: PBD0i<I>, 1: PBD0o<PP>, 2: PBD0o<OD>, 3: ADCA3(8bit)<I>, 4: INT0_MHL3<I>, 
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>)

// DP_SINK_ASS_1
#define _PIN_51                                 (0 & 0x0F) // Page 10-0xB2[3:0]
// 0 ~ 9 (0: P1D0i<I>, 1: P1D0o<PP>, 2: P1D0o<OD>, 3: PWM0<PP>, 4: PWM0<OD>, 
//        5: TCON[0]<O>, 6: IR_Receiver<I>, 7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>)

// EEI2SCL
#define _PIN_52                                 (6 & 0x07) // Page 10-0xB3[2:0]
// 0 ~ 5 (0: P1D1i<I>, 1: P1D1o<PP>, 2: P1D1o<OD>, 3: TEST_PIN0<O>, 4: TEST_PIN1<O>, 
//        5: DUMMY<O>, 6: IIC3<IO>)

// EEI2SDA
#define _PIN_53                                 (6 & 0x07) // Page 10-0xB4[2:0]
// 0 ~ 5 (0: P1D2i<I>, 1: P1D2o<PP>, 2: P1D2o<OD>, 3: TEST_PIN0<O>, 4: TEST_PIN1<O>, 
//        5: DUMMY<O>, 6: IIC3<IO>)

// EEI2WP
#define _PIN_54                                 (2 & 0x0F) // Page 10-0xB5[3:0]
// 0 ~ 9 (0: P1D3i<I>, 1: P1D3o<PP>, 2: P1D3o<OD>, 3: PWM0<PP>, 4: PWM0<OD>,
//        5: TCON[0]<O>, 6: IRQB<O>, 7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>)

// DDCSCL1
#define _PIN_56                                 (9 & 0x0F) // Page 10-0xB6[3:0]
// 0 ~ 8 (0: P1D4i<I>, 1: P1D4o<PP>, 2: P1D4o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON[1]<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>, 9: DDC1<IO>)

// DDCSDA1
#define _PIN_57                                 (9 & 0x0F) // Page 10-0xB7[3:0]
// 0 ~ 8 (0: P1D5i<I>, 1: P1D5o<PP>, 2: P1D5o<OD>, 3: PWM2<PP>, 4: PWM2<OD>,
//        5: TCON[2]<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>, 9: DDC1<IO>)

// CODEC_SCL
#define _PIN_60                                 (2 & 0x0F) // Page 10-0xB8[2:0]
// 0 ~ 7 (0: P1D6i<I>, 1: P1D6o<PP>, 2: P1D6o<OD>, 3: TCON[3]<O>, 4: T2EX<I>, 
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>, 8: IIC4<IO>, 9: TXD<IO>, 10: SPI_CLK<O>)

// CODEC_SCL
#define _PIN_61                                 (2 & 0x0F) // Page 10-0xB9[2:0]
// 0 ~ 7 (0: P1D7i<I>, 1: P1D7o<PP>, 2: P1D7o<OD>, 3: TCON[4]<O>, 4: T0<I>, 
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>, 8: IIC4<IO>, 9: RXD<IO>, 10: SPI_SI<O>)

// CODEC_EN
#define _PIN_62                                 (1 & 0x0F) // Page 10-0xBA[2:0]
// 0 ~ 7 (0: P3D0i<I>, 1: P3D0o<PP>, 2: P3D0o<OD>, 3: TCON[5]<O>, 4: T1<I>, 
//        5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>, 8: IIC5<IO>, 9: TXD<IO>, 10: SPI_SO<I>)

// EDID_WP
#define _PIN_63                                 (2 & 0x0F) // Page 10-0xBB[3:0]
// 0 ~ 8 (0: P3D1i<I>, 1: P3D1o<PP>, 2: P3D1o<OD>, 3: TCON[6]<O>, 4: CLKO<O>, 
//        5: T2<I>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>, 9: IIC5<IO>,
//       10: TXD<IO>, 11: SPI_CEB0<O>)

// USB_CHA_SW/VOIP_MUTE:NC
#define _PIN_64                                 (2 & 0x0F) // Page 10-0xBC[3:0]
// 0 ~ 9 (0: PCD3i<I>, 1: PCD3o<PP>, 2: PCD3o<OD>, 3: INT0_0<I>, 4: TCON[7]<O>, 
//        5: CLKO<O>, 6: TEST_PIN2<O>, 7: TEST_PIN3<O>, 8: DUMMY<O>, 9: SPI_CEB1<O>)

// TXO3+_ 
#define _PIN_65                                 (0 & 0x0F) // Page 10-0xBD[3:0]
// 0 ~ 8 (0: Hi-Z <default>, 1: P9D0i <I> , 2: P9D0o<PP>, 3: P9D0o<OD>, 4: PWM0<PP>,
//        5: PWM0<OD>, 6: SPDIF0 <O>, 7: IIS_SD0 <O>, 8: DUMMY <O>)

// TXO3-
#define _PIN_66                                 (0 & 0x0F) // Page 10-0xBE[3:0]
// 0 ~ 8 (0: Hi-Z <default>, 1: P9D1i<I>, 2: P9D1o<PP>, 3: P9D1o<OD>, 4: PWM1<PP>,
//        5: PWM1<OD>, 6: SPDIF1<O>, 7: IIS_SD1<O>, 8: DUMMY<O>)

// TXOC+
#define _PIN_67                                 (0 & 0x0F) // Page 10-0xBF[3:0]
// 0 ~ 8 (0: Hi-Z <default>, 1: P9D2i<I>, 2: P9D2o<PP>, 3: P9D2o<OD>, 4: PWM2<PP>,
//        5: PWM2<OD>, 6: SPDIF2<O>, 7: IIS_SD2<O>, 8: DUMMY<O>)

// TXOC-
#define _PIN_68                                 (0 & 0x0F) // Page 10-0xC0[3:0]
// 0 ~ 8 (0: Hi-Z <default>, 1: P9D3i <I>, 2: P9D3o<PP>, 3: P9D3o<OD>, 4: PWM3<PP>,
//        5: PWM3<OD>, 6: SPDIF3<O>, 7: IIS_SD3<O>, 8: DUMMY<O>)

// TXO2+
#define _PIN_69                                 (0 & 0x07) // Page 10-0xC1[2:0]
// 0 ~ 7 (0: Hi-Z <default>, 1: P9D4i<I>, 2: P9D4o<PP>, 3: P9D4o<OD>, 4: PWM4<PP>,
//        5: PWM4<OD>, 6: IIS_SCK<O>, 7: DUMMY<O>)

// TXO2-
#define _PIN_70                                 (0 & 0x07) // Page 10-0xC2[2:0]
// 0 ~ 7 (0: Hi-Z<default>, 1: PAD0i<I>, 2: PAD0o<PP>, 3: PAD0o<OD>, 4: PWM5<PP>,
//        5: PWM5<OD>, 6: IIS_MCK<O>, 7: DUMMY<O>)

// TXO1+
#define _PIN_71                                 (0 & 0x07) // Page 10-0xC3[2:0]
// 0 ~ 7 (0: Hi-Z<default>, 1: PAD1i<I>, 2: PAD1o<PP>, 3: PAD1o<OD>, 4: PWM0<PP>,
//        5: PWM0<OD>, 6:  IIS_WS<O>, 7: DUMMY<O>)

// TXO1-
#define _PIN_72                                 (0 & 0x07) // Page 10-0xC4[2:0]
// 0 ~ 5 (0: Hi-Z<default>, 1: PAD2i<I>, 2: PAD2o<PP>, 3: PAD2o<OD>, 4:  TCON[8]<O>,
//        5: DUMMY<O>)

// TXO0+
#define _PIN_73                                 (0 & 0x07) // Page 10-0xC5[2:0]
// 0 ~ 5 (0: Hi-Z<default>, 1: PAD3i<I>, 2: PAD3o<PP>, 3: PAD3o<OD>, 4:  TCON[9]<O>,
//        5: DUMMY<O>)

// TXO0-
#define _PIN_74                                 (0 & 0x07) // Page 10-0xC6[2:0]
// 0 ~ 5 (0: Hi-Z<default>, 1: PAD4i<I>, 2: PAD4o<PP>, 3: PAD4o<OD>, 4:  TCON[10]<O>,
//        5: DUMMY<O>)

// USB_UP_SW
#define _PIN_87                                 (2 & 0x07) // Page 10-0xC7[2:0]
// 0 ~ 5 (0: P6D0i<I>, 1: P6D0o<PP>, 2: P6D0o<OD>, 3: TEST_PIN2<O>, 4: TEST_PIN3<O>, 
//        5: DUMMY<O>)

// Panel_Power_On
#define _PIN_88                                 (1 & 0x0F) // Page 10-0xC8[3:0]
// 0 ~ 11 (0: P6D1i<I>, 1: P6D1o<PP>, 2: P6D1o<OD>, 3: Reserved, 4: PWM0<PP>, 
//         5: PWM0<OD>, 6: SPDIF0<O>, 7: IIS_SD0<O>, 8: Reserved, 9: TEST_PIN2<O>, 
//        10: TEST_PIN3<O>, 11: DUMMY<O>)

// KEY_POWER
#define _PIN_90                                 (0 & 0x0F) // Page 10-0xCA[3:0]
// 0 ~ 13 (0: P6D3i<I>, 1: P6D3o<PP>, 2: P6D3o<OD>, 3: Reserved, 4: PWM1<PP>, 
//         5: PWM1<OD>, 6: SPDIF1<O>, 7: IIS_SD1<O>, 8: Reserved, 9: IR_Receiver<I>,
//        10: INT0_1<I>, 11: TEST_PIN2<O>, 12: TEST_PIN3<O>, 13: DUMMY<O>)

// USB_DET
#define _PIN_91                                 (0 & 0x07) // Page 10-0xCB[2:0]
// 0 ~ 5 (0: P6D4i<I>, 1: P6D4o<PP>, 2: P6D4o<OD>, 3: TEST_PIN2<O>, 4: TEST_PIN3<O>, 
//        5: DUMMY<O>)

// BL_EN
#define _PIN_92                                 (2 & 0x0F) // Page 10-0xCC[3:0]
// 0 ~ 11 (0: P6D5i<I>, 1: P6D5o<PP>, 2: P6D5o<OD>, 3: Reserved, 4: PWM2<PP>, 
//         5: PWM2<OD>, 6: SPDIF2<O>, 7: IIS_SD2<O>, 8: Reserved, 9: TEST_PIN2<O>, 
//        10: TEST_PIN3<O>, 11: DUMMY<O>)

// LED1:Amber
#define _PIN_94                                 (2 & 0x0F) // Page 10-0xCE[3:0]
// 0 ~ 11 (0: P6D7i<I>, 1: P6D7o<PP>, 2: P6D7o<OD>, 3: Reserved, 4: PWM3<PP>, 
//         5: PWM3<OD>, 6: SPDIF3<O>, 7: IIS_SD3<O>, 8: Reserved, 9: TEST_PIN2<O>, 
//        10: TEST_PIN3<O>, 11: DUMMY<O>)

// USB_BD_5V_EN
#define _PIN_95                                 (2 & 0x07) // Page 10-0xCF[2:0]
// 0 ~ 5 (0: PCD2i<I>, 1: PCD2o<PP>, 2: PCD2o<OD>, 3: TEST_PIN2<O>, 4: TEST_PIN3<O>, 
//        5: DUMMY<O>)

// LED2:Green
#define _PIN_96                                 (2 & 0x0F) // Page 10-0xD0[3:0]
// 0 ~ 10 (0: P5D2i<I>, 1: P5D2o<PP>, 2: P5D2o<OD>, 3: Reserved, 4: PWM4<PP>, 
//         5: PWM4<OD>, 6: IIS_SCK<O>, 7: Reserved,  8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 10: DUMMY<O>)

// BL_ADJ
#define _PIN_98                                 (4 & 0x0F) // Page 10-0xD2[3:0]
// 0 ~ 11 (0: P5D4i<I>, 1: P5D4o<PP>, 2: P5D4o<OD>, 3: Reserved, 4: PWM5<PP>, 
//         5: PWM5<OD>, 6: IIS_MCK<O>, 7: INT1_0<O>, 8: Reserved, 9: TEST_PIN2<O>, 
//        10: TEST_PIN3<O>, 11: DUMMY<O>)

// USB_EN
#define _PIN_99                                 (1 & 0x07) // Page 10-0xD3[2:0]
// 0 ~ 5 (0: P5D5i<I>, 1: P5D5o<PP>, 2: P5D5o<OD>, 3: TEST_PIN2<O>, 4: TEST_PIN3<O>, 
//        5: DUMMY<O>)

// MUTE POWER DOWN
#define _PIN_100                                (2 & 0x0F) // Page 10-0xD4[3:0]
// 0 ~ 13 (0: P5D6i<I>, 1: P5D6o<PP>, 2: P5D6o<OD>, 3: Reserved, 4: IIS_MCK<O>, 
//         5: INT0_2<I>, 6: Reserved, 7: DHS<O>, 8: DVS<O>, 9: DENA<O>, 
//        10: DCLK<O>, 11: TEST_PIN2<O>, 12: TEST_PIN3<O>, 13: DUMMY<O>)

//bAmpPowe
#define _PIN_119                                (1 & 0x07) // Page 10-0xDC[2:0]
// 0 ~ 7 (0: P3D3i<I>, 1: P3D3o<PP>, 2: P3D3o<OD>, 3: INT1_1 <I>, 4: T2<I>, 
//        5: TEST_PIN2<O>, 6: TEST_PIN3<O>, 7: DUMMY<O>)

// DDCSCL3
#define _PIN_123                                (7 & 0x07) // Page 10-0xDD[2:0]
// 0 ~ 6 (0: P3D4i<I>, 1: P3D4o<PP>, 2: P3D4o<OD>, 3: AUX_CH_P1, 4: TEST_PIN2<O>, 
//        5: TEST_PIN3<O>, 6: DUMMY<O>, 7: DDC3<IO>)

// DDCSDA3
#define _PIN_124                                (7 & 0x07) // Page 10-0xDD[2:0]
// 0 ~ 6 (0: P3D5i<I>, 1: P3D5o<PP>, 2: P3D5o<OD>, 3: AUX_CH_N1, 4: TEST_PIN2<O>, 
//        5: TEST_PIN3<O>, 6: DUMMY<O>, 7: DDC3<IO>)

// AUX_CHN
#define _PIN_125                                (3 & 0x07) // Page 10-0xDF[2:0]
// 0 ~ 6 (0: P3D6i<I>, 1: P3D6o<PP>, 2: P3D6o<OD>, 3: AUX_CH_N0, 4: TEST_PIN2<O>, 
//        5: TEST_PIN3<O>, 6: DUMMY<O>, 7: DDC2<IO>)

// AUX_CHP
#define _PIN_126                                (3 & 0x07) // Page 10-0xE0[2:0]
// 0 ~ 6 (0: P3D7i<I>, 1: P3D7o<PP>, 2: P3D7o<OD>, 3: AUX_CH_P0, 4: TEST_PIN2<O>, 
//        5: TEST_PIN3<O>, 6: DUMMY<O>, 7: DDC2<IO>)

//======================================================================================================
//======================================================================================================

//-----------------------------------------------
// Macro of Pcb Gpio Inital Setting
//-----------------------------------------------

// Enable Write Protect for EEPROM and FLASH
#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
#define PCB_GPIO_INITIAL_SETTING()              {\
                                                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_ENABLE); \
                                                    PCB_PANEL_POWER(_PANEL_CONTROL_OFF); \
                                                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW); \
                                                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW); \
                                                    PCB_ELED_SETTING_ENABLE(); \
                                                    SET_D1_TMDS_SWITCH(_TMDS_SWITCH_HPD); \
                                                    SET_D1_MHL_VBUS_SWITCH(_MHL_VBUS_OFF); \
                                                    SET_REGULATOR_5V_OUT(_REGULATOR_5V_OFF); \
                                                    PCB_AMP_MUTE(_AMP_MUTE_ON); \
                                                    PCB_LED_OFF(); \
                                                }

#else
#define PCB_GPIO_INITIAL_SETTING()              {\
                                                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_ENABLE); \
                                                    PCB_PANEL_POWER(_PANEL_CONTROL_OFF); \
                                                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW); \
                                                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW); \
                                                    PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF); \
                                                    PCB_GPIO_SETTING_ENABLE(); \
                                                    SET_D1_TMDS_SWITCH(_TMDS_SWITCH_HPD); \
                                                    SET_D1_MHL_VBUS_SWITCH(_MHL_VBUS_OFF); \
                                                    SET_REGULATOR_5V_OUT(_REGULATOR_5V_OFF); \
                                                    PCB_LED_OFF(); \
                                                    bPCBAMPMUTECONTROL = _AMP_MUTE_ON; \
                                                    PCB_AMP_POWER(_AMP_POWER_OFF);\
                                                    PCB_CODEC_ENABLE(_CODEC_DISABLE);\
                                                }
#endif // #endif (_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)


///////////////////////////////////////
// Pin39~40,50~53 Function Normal    //
// Pin41~48 Function Select to Audio //
// Pin65~72,96~103 Normal Operation  //
///////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                    ScalerSetBit(P10_E1_PIN_DRIVING_CTRL41, ~_BIT3, _BIT3);    \
                                                    ScalerSetBit(P10_E2_PIN_DVIVING_CTRL42, ~_BIT0, _BIT0);    \
                                                    PCB_SET_USB_CHA(_USB_CHA_NORMAL);\
                                                }

////////////////////////////////////////////////////////
// Pin39~40 pull up control --> GPIO Function Disable //
// Pin65~72,96~103 pull up Control                    //
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                    ScalerSetBit(P10_E1_PIN_DRIVING_CTRL41, ~_BIT3, 0x00);    \
                                                    ScalerSetBit(P10_E2_PIN_DVIVING_CTRL42, ~_BIT0, 0x00);    \
                                                    PCB_SET_USB_CHA(_USB_CHA_POWERSAVING);\
                                                }

////////////////////////////////////////////////////////
// Pin50~53 pull up control --> GPIO Function Disable //
// Pin39~40 pull up control --> GPIO Function Disable //
// Pin65~72,96~103 pull up Control                    //
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                    ScalerSetBit(P10_E1_PIN_DRIVING_CTRL41, ~_BIT3, 0x00);    \
                                                    ScalerSetBit(P10_E2_PIN_DVIVING_CTRL42, ~_BIT0, 0x00);    \
                                                }

#define PCB_GPIO_SETTING_POWER_AC_ON()          {\
                                                    PCB_GPIO_SETTING_POWER_DOWN();\
                                                }

////////////////////////////////////////////////////////
// Pin102/105/106/107/109 control -> eLED&GPIO Switch///
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_ENABLE()               {\
                                                    ScalerSetByte(P10_D6_PIN_SHARE_CTRL36, 0x01);    \
                                                    ScalerSetByte(P10_D7_PIN_SHARE_CTRL37, 0x00);    \
                                                    ScalerSetByte(P10_D8_PIN_SHARE_CTRL38, 0x00);    \
                                                    ScalerSetByte(P10_D9_PIN_SHARE_CTRL39, 0x00);    \
                                                    ScalerSetByte(P10_DA_PIN_SHARE_CTRL3A, 0x00);    \
                                                    ScalerSetBit(P16_C2_LEDBC_ADVREF6, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);    \
                                                    ScalerSetBit(P16_C3_LEDBC_ADVREF5, ~_BIT0, _BIT0);    \
                                                }

////////////////////////////////////////////////////////
// Pin102/105/106/107/109 control -> eLED&GPIO Switch///
////////////////////////////////////////////////////////
#define PCB_ELED_SETTING_ENABLE()               {\
                                                    ScalerSetByte(P10_D6_PIN_SHARE_CTRL36, 0x01);    \
                                                    ScalerSetByte(P10_D7_PIN_SHARE_CTRL37, 0x00);    \
                                                    ScalerSetByte(P10_D8_PIN_SHARE_CTRL38, 0x00);    \
                                                    ScalerSetByte(P10_D9_PIN_SHARE_CTRL39, 0x00);    \
                                                    ScalerSetByte(P10_DA_PIN_SHARE_CTRL3A, 0x00);    \
                                                    ScalerSetBit(P16_C2_LEDBC_ADVREF6, ~(_BIT7 | _BIT6), 0x00);    \
                                                    ScalerSetBit(P16_C3_LEDBC_ADVREF5, ~_BIT0, 0x00);    \
                                                }

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
#define PCB_PWM_SETTING()                       {\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 180); \
                                                }

//--------------------------------------------------
// Macro of IIC
//--------------------------------------------------
sbit bSWIIC_SYS_EEPROM_SCL                      = P1^1; // _PIN_52, P1.1
sbit bSWIIC_SYS_EEPROM_SDA                      = P1^2; // _PIN_53, P1.2

sbit bSWIIC_EDID_EEPROM_SCL_VGA                 = P1^4;//_PIN_56
sbit bSWIIC_EDID_EEPROM_SDA_VGA                 = P1^5;//_PIN_57

sbit bSWIIC_EDID_EEPROM_SCL_HDMI                = P3^4;//_PIN_123
sbit bSWIIC_EDID_EEPROM_SDA_HDMI                = P3^5;//_PIN_124

sbit bSWIIC_SYS_CODEC_SCL                       = P1^6;//_PIN_60
sbit bSWIIC_SYS_CODEC_SDA                       = P1^7;//_PIN_61

#define PCB_SW_IIC_SDA_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SDA = _TRUE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SDA_VGA = _TRUE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_CODEC) \
                                                    {                                          \
                                                        bSWIIC_SYS_CODEC_SDA = _TRUE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC3) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SDA_HDMI = _TRUE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SDA_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SDA = _FALSE;        \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SDA_VGA = _FALSE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_CODEC) \
                                                    {                                          \
                                                        bSWIIC_SYS_CODEC_SDA = _FALSE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC3) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SDA_HDMI = _FALSE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SDA_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_EEPROM_SDA;             \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        x = bSWIIC_EDID_EEPROM_SDA_VGA;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_CODEC) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_CODEC_SDA;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC3) \
                                                    {                                          \
                                                        x = bSWIIC_EDID_EEPROM_SDA_HDMI;         \
                                                    }                                          \
                                                }

#define PCB_SW_IIC_SCL_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SCL = _TRUE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SCL_VGA = _TRUE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_CODEC) \
                                                    {                                          \
                                                        bSWIIC_SYS_CODEC_SCL = _TRUE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC3) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SCL_HDMI = _TRUE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SCL_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SCL = _FALSE;        \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SCL_VGA = _FALSE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_CODEC) \
                                                    {                                          \
                                                        bSWIIC_SYS_CODEC_SCL = _FALSE;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC3) \
                                                    {                                          \
                                                        bSWIIC_EDID_EEPROM_SCL_HDMI = _FALSE;         \
                                                    }                                          \
                                                }
#define PCB_SW_IIC_SCL_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_EEPROM_SCL;             \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1) \
                                                    {                                          \
                                                        x = bSWIIC_EDID_EEPROM_SCL_VGA;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_CODEC) \
                                                    {                                          \
                                                        x = bSWIIC_SYS_CODEC_SCL;         \
                                                    }                                          \
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC3) \
                                                    {                                          \
                                                        x = bSWIIC_EDID_EEPROM_SCL_HDMI;         \
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
                                                    ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);\
                                                    SET_SW_IIC_STATUS(_IIC_FOR_DDC3);\
                                                }

#define HDMI2Slave()                            {\
                                                    ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);\
                                                    SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);\
                                                }

#define DVI2Host()                              {\
                                                }

#define DVI2Slave()                             {\
                                                }


#define CODEC2Host()                            {\
                                                    SET_SW_IIC_STATUS(_IIC_SYS_CODEC);\
                                                }

#define CODEC2Slave()                           {\
                                                    SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);\
                                                }
//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
#define bFLASH_WRITE_PROTECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS) // NC

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
sbit bEEPROM_WRITE_PROTECT                      = P1 ^ 3; // _PIN_54

#define _EEPROM_WP_ENABLE                       1       // WP High state for Eeprom
#define _EEPROM_WP_DISABLE                      0       // WP Low state for Eeprom

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = x;  \
                                                }

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
sbit bEDID_WRITE_PROTECT                        = P3 ^ 1;//_PIN_63
#define PCB_EDID_WRITE_PROTECT_DETECT()         (bEDID_WRITE_PROTECT)

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = x;\
                                                }

#define PCB_D0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = x;\
                                                }

#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = x;\
                                                }

//-----------------------------------------------
// Macro of Input Connect Detect
//-----------------------------------------------
#define bDP_PIN15_CONNECT                       (MCU_EMPTY_PIN_ASSIGN_ADDRESS) // NC
sbit bDP_PIN16_CONNECT                          = P1 ^ 0; // _PIN_51 DP cable detect by DP_SINK_ASS_1
#define bDP_PIN17_CONNECT                       (MCU_EMPTY_PIN_ASSIGN_ADDRESS) // NC

#define bA0_CONNECT                             (MCU_PORT_PD2_PIN_REG_FF7C) //_PIN_27
#define bD0_CONNECT                             (MCU_PORT_PD4_PIN_REG_FF7A) //_PIN_25 HDMI_CAB_DET
#define bD1_CONNECT                             ((bit)bDP_PIN16_CONNECT)

#define PCB_A0_PIN()                            (SET_A0_CABLE_STATUS(!bA0_CONNECT))
#define PCB_D0_PIN()                            (SET_D0_CABLE_STATUS((!bD0_CONNECT) || (PCB_D0_MHL_DETECT())))
#define PCB_D1_PIN()                            (SET_D1_CABLE_STATUS(!bD1_CONNECT))

//-----------------------------------------------       
// Macro of MHL/HDMI Detection
//-----------------------------------------------
#define _TMDS_HDMI_MODE                         0
#define _TMDS_MHL_MODE                          1

#define PCB_D0_MHL_DETECT()                     (MCU_PORT_PB3_PIN_REG_FF8C) // _PIN_47 CD-Sense

#define bD0_TMDS_SWITCH                         (MCU_PORTC1_PIN_REG_FFA2) // _PIN_1 PS_CTRL
#define _TMDS_SWITCH_CBUS                       1
#define _TMDS_SWITCH_HPD                        0

#define SET_D0_TMDS_SWITCH(x)                   (bD0_TMDS_SWITCH = x)

#define bD0_MHL_VBUS_SWITCH                     (bD0_TMDS_SWITCH) 
#define _MHL_VBUS_ON                            _TMDS_SWITCH_CBUS 
#define _MHL_VBUS_OFF                           _TMDS_SWITCH_HPD

#define SET_D0_MHL_VBUS_SWITCH(x)               {                                                   \
                                                   /*bD0_MHL_VBUS_SWITCH = x;  */                   \
                                                   /* SET_PCB_REGULATOR_5V(x);  */                  \
                                                }                                                   

#define SET_PCB_REGULATOR_5V(x)                 {                                                   \
                                                    if(bD0_MHL_VBUS_SWITCH == _MHL_VBUS_ON)         \
                                                    {                                               \
                                                        SET_REGULATOR_5V_OUT(_REGULATOR_5V_ON);     \
                                                    }                                               \
                                                    else                                            \
                                                    {                                               \
                                                        SET_REGULATOR_5V_OUT(_REGULATOR_5V_OFF);    \
                                                    }                                               \
                                                }

//-----------------------------------------------       
// Macro of 12V to 5V Regulator
//-----------------------------------------------
sbit bREGULATOR_5V                              = P1 ^ 7; // Pin61, P1.7
#define _REGULATOR_5V_ON                        0
#define _REGULATOR_5V_OFF                       1

#define SET_REGULATOR_5V_OUT(x)                 {}//(bREGULATOR_5V = x)

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD0_HPD                                 (MCU_PORT_PD5_PIN_REG_FF79) //_PIN_24
#define _D0_HOT_PLUG_HIGH                       1       // D0 Switch High state
#define _D0_HOT_PLUG_LOW                        0       // D0 Switch Low state

#define PCB_D0_HOTPLUG(x)                       {\
                                                    bD0_HPD = x;                    \
                                                }

#define bD1_HPD                                 (MCU_PORT_PD7_PIN_REG_FF77) // _PIN_22
#define _D1_HOT_PLUG_HIGH                       1       // D1 Switch High state
#define _D1_HOT_PLUG_LOW                        0       // D1 Switch Low state

#define PCB_D1_HOTPLUG(x)                       {\
                                                    bD1_HPD = x;                    \
                                                }

#define bD2_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define _D2_HOT_PLUG_HIGH                       1       // D2 Switch High state
#define _D2_HOT_PLUG_LOW                        0       // D2 Switch Low state

#define PCB_D2_HOTPLUG(x)                       {\
                                                }


#define bD3_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define _D3_HOT_PLUG_HIGH                       1       // D3 Switch High state
#define _D3_HOT_PLUG_LOW                        0       // D3 Switch Low state

#define PCB_D3_HOTPLUG(x)                       {\
                                                }

//-----------------------------------------------
// Macro of Input Port D2 Digital Switch
//-----------------------------------------------
#define bDIGITAL_D2_SWITCH_POWER                (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _DIGITAL_D2_SWITCH_POWER_ON             1
#define _DIGITAL_D2_SWITCH_POWER_DOWN           0

#define PCB_DIGITAL_D2_SWITCH_POWER(x)          {\
                                                }

#define bDIGITAL_D2_SWITCH_S1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bDIGITAL_D2_SWITCH_S2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_DIGITAL_D2_SWITCH_TO_HIZ()          {\
                                                }

//-----------------------------------------------
// Macro of Input Port D3 Digital Switch
//-----------------------------------------------
#define bDIGITAL_D3_SWITCH_POWER                (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _DIGITAL_D3_SWITCH_POWER_ON             1
#define _DIGITAL_D3_SWITCH_POWER_DOWN           0

#define PCB_DIGITAL_D3_SWITCH_POWER(x)          {\
                                                }

#define bDIGITAL_D3_SWITCH_S1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bDIGITAL_D3_SWITCH_S2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_DIGITAL_D3_SWITCH_TO_HIZ()          {\
                                                }

//-----------------------------------------------
// Macro of Digital Port Switch
//-----------------------------------------------
#define PCB_DIGITAL_SWITCH_TO_D0()              {\
                                                }

#define PCB_DIGITAL_SWITCH_TO_D0_IDLE()         {\
                                                }

#define PCB_DIGITAL_SWITCH_TO_D1()              {\
                                                }

#define PCB_DIGITAL_SWITCH_TO_D1_IDLE()         {\   
                                                }

#define PCB_DIGITAL_SWITCH_TO_D2()              {\
                                                }

#define PCB_DIGITAL_SWITCH_TO_D3()              {\
                                                }

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   (MCU_PORT52_PIN_REG_FFC1) // _PIN_96, Green
#define bLED2                                   (MCU_PORT67_PIN_REG_FFCE) // _PIN_94, Amber


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

#define PCB_LED_POWER_SAVING()                  {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_ON;                \ 
                                                }

#define PCB_LED_ON()                            {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_ON;               \                                                  
                                                }

#define PCB_LED_OFF()                           {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_OFF;               \                                                   
                                                }

#define PCB_LED_TYPE1()                         {\
													bLED1 = _LED_ON;				\
													bLED2 = _LED_ON;				\													
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
                                                    bLED1 = ~bLED1;                \
                                                    bLED2 = ~bLED2;                \    
                                                }

#define PCB_LED_TYPE_PWM(x)                     {\
                                                }

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
// Must Check Wether _LOW_SPEED_ADC_SUPPORT is Supported
#define _AD_KEY_SUPPORT                         _ON 

#define AD_KEY1                                 (MCU_ADC1_RESULT_FF0A) // Pin 49, PB.3
#define AD_KEY2                                 (MCU_ADC2_RESULT_FF0B) // Pin 48, PB.2
#define bPOWER_KEY                              (MCU_PORT63_PIN_REG_FFCA)//_PIN_90

#define PCB_ADKEY0()                            (_FALSE)
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)
#define PCB_ADKEY3()                            (_FALSE)


#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if(!bPOWER_KEY)                         \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x90 <= ucV1) && (ucV1 < 0xB0))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0xB0 <= ucV1) && (ucV1 < 0xD0))    \
                                                                    ucKeyState |= _UP_KEY_MASK;       \
                                                                                                       \
                                                                if((0xD0 <= ucV1) && (ucV1 < 0xF0))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;     \
                                                                                                       \
                                                                if((0x90 <= ucV2) && (ucV2 < 0xB0))    \
                                                                    ucKeyState |= _DOWN_KEY_MASK;      \
                                                                                                       \
                                                                if((0xB0 <= ucV2) && (ucV2 < 0xD0))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if((0xD0 <= ucV2) && (ucV2 < 0xF0))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
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
// Macro of add pattern on Panel backlight Power Up
//--------------------------------------------------
#define _PANEL_ON_ADD_PATTERN                   _ON

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             (MCU_PORT61_PIN_REG_FFC8) // _PIN_88

#define _PANEL_CONTROL_ON                       1       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      0       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = x;                \
                                                    if(x == _PANEL_CONTROL_ON)\
                                                    {\
                                                        ScalerDisplayLvdsStrongPullDown();\
                                                    }\
                                                }

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)

#define bBACKLIGHTPOWER                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS) 

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

#define bBACKLIGHTPOWER                         (MCU_PORT65_PIN_REG_FFCC) //_PIN_92

#define _LIGHT_CONTROL_ON                       0       // Light on  state for backlight inverter
#define _LIGHT_CONTROL_OFF                      1       // Light off state for backlight inverter

#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = x; \
                                                }

                                                                                            
#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if(x == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                        if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) && (GET_INPUT_TIMING_VFREQ() > 500))\
                                                        {\
                                                            ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, (WORD)((GET_INPUT_TIMING_VFREQ() * 30) / 100)); \
                                                        }\
                                                        else\
                                                        {\
                                                            ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 180); \
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

#endif // #endif (_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)

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
                                                    bAmpPowe=x;\
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

#if(_CODEC_CX2070X_SUPPORT == _ON)
#define PCB_AMP_MUTE(x)                         {\
                                                    bPCBAMPMUTECONTROL = x; \
                                                    if(x == _AMP_MUTE_ON)\
                                                        SET_OSD_MUTE_STATE(_ON);\
                                                    else\
                                                        SET_OSD_MUTE_STATE(_OFF);\
                                                }
#else
#define PCB_AMP_MUTE(x)                         {\
                                                    bPCBAMPMUTECONTROL = x; \
                                                }
#endif

#define PCB_AUDIO_VOLUME_PWM(x)                 {\
                                                }

#define PCB_GET_AUDIO_VOLUME_PWM()              (MCU_PWM0H_DUT_FF4A)


//-----------------------------------------------
// Macro of Usb Hub High/Low
//-----------------------------------------------
#define bUSB_DETECT                             (MCU_PORT64_PIN_REG_FFCB)//_PIN_91
#define PCB_USB_DETECT()                        (bUSB_DETECT)

//-----------------------------------------------
#define bUSB_POWER                              (MCU_PORTC2_PIN_REG_FFA1)//_PIN_95

#define _USB_POWER_ON                           1       // USB power on state
#define _USB_POWER_OFF                          0       // USB power off state
#define PCB_USB_POWER(x)                        {\
                                                    bUSB_POWER = x;\
                                                }
//-----------------------------------------------
#define bUSB_ENABLE                             (MCU_PORT55_PIN_REG_FFC4)//_PIN_99

#define _USB_ENABLE                             1      
#define _USB_DISABLE                            0     
#define PCB_USB_ENABLE(x)                       {\
                                                    bUSB_ENABLE = x;\
                                                }

//-----------------------------------------------
// Macro of CodeC
//-----------------------------------------------
sbit bCODEC_ENABLE                              = P3 ^ 0;//_PIN_62

#define _CODEC_ENABLE                           1      
#define _CODEC_DISABLE                          0     
#define PCB_CODEC_ENABLE(x)                     {\
                                                    bCODEC_ENABLE = x;\
                                                    if(x == _CODEC_DISABLE)\
                                                        PCB_SPK_MUTE_LED(_SPK_MUTE_OFF); \
                                                }

//-----------------------------------------------
// Macro of spk mute LED
//-----------------------------------------------
#define bSPK_MUTE_LED                          (MCU_PORTC3_PIN_REG_FFA0)//_PIN_64

#define _SPK_MUTE_ON                           0      
#define _SPK_MUTE_OFF                          1     
#define PCB_SPK_MUTE_LED(x)                    {\
                                                    bSPK_MUTE_LED = x;\
                                               }
/*
//Scaler GPO for VOIP LED,But PCB NC
//So,VOIP LED control by Codec GPO
//-----------------------------------------------
sbit bVOIP_MAC                                  = P3 ^ 0;//_PIN_119

#define _VOIP_MAC_ON                            1      
#define _VOIP_MAC_OFF                           0     
#define PCB_VOIP_MAC_LED(x)                     {\
                                                    bVOIP_MAC = x;\
                                                }
//-----------------------------------------------
#define bVOIP_HOOK                              (MCU_PORT_PB0_PIN_REG_FF8F)//_PIN_50

#define _VOIP_HOOK                              1      
#define _VOIP_CALL                              0     
#define PCB_VOIP_PHONE_LED(x)                   {\
                                                    bVOIP_HOOK = x;\
                                                }
*/
//-----------------------------------------------

//-----------------------------------------------
// Macro of ONELINK_DET
//-----------------------------------------------
#define bONELINK_DET                            (MCU_PORT_PD3_PIN_REG_FF7B)//_PIN_26

#define PCB_GET_ONELINK()                       (bONELINK_DET)

//-----------------------------------------------
// Macro of USB Upstream:DP from Onelink,other from P304
//-----------------------------------------------
#define bUSB_UPSTREAM                           (MCU_PORT60_PIN_REG_FFC7)//_PIN_87
#define PCB_GET_USB_UPSTREAM()                  (bUSB_UPSTREAM)

#define _USB_UPSTREAM_ONELINK                   1
#define _USB_UPSTREAM_P304                      0
#define PCB_SET_USB_UPSTREAM_SW(x)              {\
                                                    bUSB_UPSTREAM = x;\
                                                }

//-----------------------------------------------
// Macro of USB_CHA_SW
//-----------------------------------------------
#define bUSB_CHA_SW                             (MCU_PORT_PB0_PIN_REG_FF8F)//_PIN_50      //_PIN_64

#define _USB_CHA_NORMAL                         0      
#define _USB_CHA_POWERSAVING                    1     
#define PCB_SET_USB_CHA(x)                      {\
                                                    bUSB_CHA_SW = x;\
                                                }

//-----------------------------------------------
// Macro of Dynamic High/Low
//-----------------------------------------------
#define _BACKLIGHT_HIGH_DYNAMIC_ON              30
#define _BACKLIGHT_HIGH_DYNAMIC_OFF             216

#define PCB_BACKLIGHT_HIGH_DYNAMIC(x)           {\
                                                }

#endif // End of #if(_PCB_TYPE == _RTD247HTD_WISTRON_1A1MHL1DP)

