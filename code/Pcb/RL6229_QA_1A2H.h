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
// ID Code      : RL6229_QA_1A2H.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PCB_TYPE == _RL6229_QA_1A2H)

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

#define _D0_INPUT_PORT_TYPE                     _D0_HDMI_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC2
#define _EMBEDDED_DDCRAM_D0_SIZE                _EDID_SIZE_256
#define _EMBEDDED_DDCRAM_D0_LOCATION            _EDID_TABLE_LOCATION_CODE

#define _D1_INPUT_PORT_TYPE                     _D1_HDMI_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC3
#define _EMBEDDED_DDCRAM_D1_SIZE                _EDID_SIZE_NONE
#define _EMBEDDED_DDCRAM_D1_LOCATION            _EDID_TABLE_LOCATION_CODE

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
#if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
#define _D0_TMDS_BR_SWAP                        _ON
#define _D0_TMDS_PN_SWAP                        _ON
#else
#define _D0_TMDS_BR_SWAP                        _OFF
#define _D0_TMDS_PN_SWAP                        _OFF
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
#define _D1_TMDS_BR_SWAP                        _ON
#define _D1_TMDS_PN_SWAP                        _ON
#else
#define _D1_TMDS_BR_SWAP                        _OFF
#define _D1_TMDS_PN_SWAP                        _OFF
#endif

//--------------------------------------------------
// Definitions for Display Interface
//--------------------------------------------------
#define	_LVDS_EO_SWAP	                        _DISABLE			// Display Data Port Even/Odd Data Swap              
#define	_LVDS_RB_SWAP	                        _DISABLE			// Display Data Port Red/Blue Data Swap              
#define	_LVDS_ML_SWAP	                        _DISABLE			// Display Data Port MSB/LSB Data Swap    

#define	_LVDS_DVS_INVERT	                    _DISABLE			// DVS Output Invert Enable                
#define	_LVDS_DHS_INVERT	                    _DISABLE			// DHS Output Invert Enable                
#define	_LVDS_DEN_INVERT	                    _DISABLE			// DEN Output Invert Enable                

#define _LVDS_MIRROR                            _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE

#define _LVDS_EA_PHASE                          _ENABLE        //pin86,87
#define _LVDS_EB_PHASE                          _ENABLE        //pin88,89
#define _LVDS_EC_PHASE                          _ENABLE        //pin90,91
#define _LVDS_ED_PHASE                          _ENABLE        //pin92,93
#define _LVDS_EE_PHASE                          _ENABLE        //pin94,95
#define _LVDS_EF_PHASE                          _ENABLE        //pin96,97
#define _LVDS_EG_PHASE                          _ENABLE        //pin98,99
#define _LVDS_OA_PHASE                          _ENABLE        //pin74,75
#define _LVDS_OB_PHASE                          _ENABLE        //pin76,77
#define _LVDS_OC_PHASE                          _ENABLE        //pin78,79
#define _LVDS_OD_PHASE                          _ENABLE        //pin80,81
#define _LVDS_OE_PHASE                          _ENABLE        //pin82,83

#define _LVDS_PHASE_SELECT                      _LVDS_PHASE0   // Only Phase 0 ~ 16 can be used

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
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_56_57

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
#define _PWM0_EN								_OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                               	_OFF
#define _PWM4_EN								_ON
#define _PWM5_EN                               	_OFF

#define _PWM0_PSAV_EN							_OFF
#define _PWM1_PSAV_EN							_OFF
#define _PWM2_PSAV_EN							_OFF
#define _PWM3_PSAV_EN							_OFF
#define _PWM4_PSAV_EN							_OFF
#define _PWM5_PSAV_EN							_OFF

#define _PWM0_RST_BY_DVS						_OFF
#define _PWM1_RST_BY_DVS						_OFF
#define _PWM2_RST_BY_DVS						_OFF
#define _PWM3_RST_BY_DVS						_OFF
#define _PWM4_RST_BY_DVS						_ON
#define _PWM5_RST_BY_DVS						_OFF

#define _AUDIO_VOLUME_PWM						_NO_PWM			
#define _AUDIO_VOLUME_PWM_INVERSE               _OFF

#define _BACKLIGHT_PWM                          _PWM4
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM_DUT_RESOLUTION						_PWM_8BIT

//--------------------------------------------------
// Definitions for Low Speed ADC
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _OFF

//--------------------------------------------------
// Definitions for 3D Shutter L/R Flag 
//--------------------------------------------------
#define _3D_SHUTTER_OUTPUT_LR_FLAG              _L_FRAME_LOW

//--------------------------------------------------
// RL6001 Series Pin Share
//--------------------------------------------------
// <OD>:open-drain  <PP>:push-pull

// GPIO 31~38
#define _P31_39_SEL                             (1 & 0x01) // Page 10-B9[6]
// 0 ~ 1 (0: Video8, 1: Normal function)

// NC Pin
#define _PIN_31                                 (0 & 0x07) // Page 10-0xA0[2:0]
// 0 ~ 6 (0: PDD7i<I>, 1: PDD7o<PP>, 2: PDD7o<OD>, 3: TCON[6]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)
#define _PIN_32                                 (0 & 0x07) // Page 10-0xA1[2:0]
// 0 ~ 6 (0: PDD6i<I>, 1: PDD6o<PP>, 2: PDD6o<OD>, 3: TCON[7]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)
#define _PIN_33                                 (0 & 0x07) // Page 10-0xA2[2:0]
// 0 ~ 6 (0: PDD5i<I>, 1: PDD5o<PP>, 2: PDD5o<OD>, 3: TCON[8]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)
#define _PIN_34                                 (0 & 0x07) // Page 10-0xA3[2:0]
// 0 ~ 6 (0: PDD4i<I>, 1: PDD4o<PP>, 2: PDD4o<OD>, 3: TCON[9]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)
#define _PIN_35                                 (0 & 0x07) // Page 10-0xA4[2:0]
// 0 ~ 6 (0: PDD3i<I>, 1: PDD3o<PP>, 2: PDD3o<OD>, 3: TCON[0]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)
#define _PIN_36                                 (0 & 0x07) // Page 10-0xA5[2:0]
// 0 ~ 6 (0: PDD2i<I>, 1: PDD2o<PP>, 2: PDD2o<OD>, 3: TCON[10]<O>,4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)
#define _PIN_37                                 (0 & 0x0F) // Page 10-0xA6[3:0]
// 0 ~ 8 (0: PDD1i<I>, 1: PDD1o<PP>, 2: PDD1o<OD>, 3: TCON[4]<O>, 4: FIELD <O>, 5: L_R<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>)
#define _PIN_39                                 (0 & 0x0F) // Page 10-0xA7[3:0]
// 0 ~ 8 (0: PDD0i<I>, 1: PDD0o<PP>, 2: PDD0o<OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: TCON[14]<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>)

// NC Pin
#define _PIN_40                                 (0 & 0x07) // Page 10-0xA8[2:0]
// 0 ~ 6 (0: PCD4i<I>, 1: PCD4o<PP>, 2: PCD4o<OD>, 3: VCLK, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#if(_EMBEDDED_DAC_SUPPORT == _ON)
// Audio 41~48
#define _P41_48_SEL                             (1 & 0x03) // Page 10-0xB9[5:4]
// 0 ~ 3 (0: Video8, 1: Audio, 2: Normal function, 3: Reserved)
#else
// Audio 41~48
#define _P41_48_SEL                             (2 & 0x03) // Page 10-0xB9[5:4]
// 0 ~ 3 (0: Video8, 1: Audio, 2: Normal function, 3: Reserved)
#endif

// NC Pin
#define _PIN_41                                 (0 & 0x07) // Page 10-0xA9[2:0]
// 0 ~ 6 (0: PBD7i<I>, 1: PBD7o<PP>, 2: PBD7o<OD>, 3: TCON5<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

// Line In
#define _PIN_42                                 (0 & 0x07) // Page 10-0xAA[2:0]
// 0 ~ 5 (0: PBD6i<I>, 1: PBD6o<PP>, 2: PBD6o<OD>, 3: TEST_PIN0<O>, 4: TEST_PIN1<O>, 5: DUMMY<O>, 6:IIC)
#define _PIN_43                                 (0 & 0x07) // Page 10-0xAB[2:0]
// 0 ~ 5 (0: PBD5i<I>, 1: PBD5o<PP>, 2: PBD5o<OD>, 3: TEST_PIN0<O>, 4: TEST_PIN1<O>, 5: DUMMY<O>, 6:IIC)

// NC Pin
#define _PIN_44                                 (0 & 0x0F) // Page 10-0xAC[3:0]
// 0 ~ 9 (0: PBD4i<I>, 1: PBD4o<PP>, 2: PBD4o<OD>, 3: WS<O>, 4: SPDIF3<O>, 5: PWM5<PP>, 6: PWM5<OD>,7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>)

// NC Pin
#define _PIN_45                                 (0 & 0x07) // Page 10-0xAD[2:0]
// 0 ~ 6 (0: PBD3i<I>, 1: PBD3o<PP>, 2: PBD3o<OD>, 3: SCK<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

// HDMI_POWER_1
#define _PIN_46                                 (0 & 0x07) // Page 10-0xAE[2:0]
// 0 ~ 6 (0: PBD2i<I>, 1: PBD2o<PP>, 2: PBD2o<OD>, 3: MCK<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

// AUDIO HOUT
#define _PIN_47                                 (0 & 0x07) // Page 10-0xAF[3:1]
// 0 ~ 6 (0: PBD1i<I>, 1: PBD1o<PP>, 2: PBD1o<OD>, 3: SD0<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)
#define _PIN_48                                 (0 & 0x07) // Page 10-0xB0[3:0]
// 0 ~ 7 (0: PBD0i<I>, 1: PBD0o<PP>, 2: PBD0o<OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>)

// AD KEY
#define _PIN_50                                 (3 & 0x07) // Page 10-0xB1[2:0]
// 0 ~ 7 (0: P6D0i<I>, 1: P6D0o<PP>, 2: P6D0o<OD>, 3: ADCA0<I>, 4: VCLK<I>,5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>)

// DP_SINK_ASS_2
#define _PIN_51                                 (0 & 0x07) // Page 10-0xB2[4:2]
// 0 ~ 6 (0: P6D1i<I>, 1: P6D1o<PP>, 2: P6D1o<OD>, 3: ADCA1<I>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

// HDMI HPD_1
#define _PIN_52                                 (1 & 0x07) // Page 10-0xD0[2:0]
// 0 ~ 6 (0: P6D2i<I>, 1: P6D2o<PP>, 2: P6D2o<OD>, 3: ADCA2<I>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

// DP_SINK_ASS_1
#define _PIN_53                                 (0 & 0x07) // Page 10-0xD1[2:0]
// 0 ~ 6 (0: P6D3i<I>, 1: P6D3o<PP>, 2: P6D3o<OD>, 3: ADCA3<I>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

// onPanel_5V
#define _PIN_54                                 (2 & 0x07) // Page 10-0xD2[2:0]
// 0 ~ 6 (0: P6D4i<I>, 1: P6D4o<PP>, 2: P6D4o<OD>, 3: PWM4<PP>, 4: PWM4<OD>,5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>)

// onBACKLITE
#define _PIN_55                                 (2 & 0x0F) // Page 10-0xD3[3:0]
// 0 ~ 11 (0: P6D5i<I>, 1: P6D5o<PP>, 2: P6D5o<OD>, 3: PWM1<PP>, 4: PWM1<OD>, 
//        5: PWM5<PP>, 6: PWM5<OD>, 7: TCON0<O>,8: TCON5<O>,9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>)

// EESCL
#define _PIN_56                                 (8 & 0x0F) // Page 10-0xD4[2:0]
// 0 ~ 7 (0: P6D6i<I>, 1: P6D6o<PP>, 2: P6D6o<OD>, 3: TCON1<O>, 4: TCON4<O>,5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>, 8:HWIIC, 9:IIC_AUX)

// EESDA
#define _PIN_57                                 (8 & 0x0F) // Page 10-0xD5[2:0]
// 0 ~ 7 (0: P6D7i<I>, 1: P6D7o<PP>, 2: P6D7o<OD>, 3: TCON9<O>, 4: TCON11<O>,5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>, 8:HWIIC, 9:IIC_AUX)
// IIC function needs to be selected for both pins (56 & 57)
																			  
// DDCSCL1
#define _PIN_58                                 (9 & 0x0F) // Page 10-0xD6[4:1]
// 0 ~ 9 (0: P3D0i<I>, 1: P3D0o<PP>, 2: P3D0o<OD>, 3: RXD<OD>, 4: TCON7<O>, 
//        5: TCON10<O>,6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>,9: DDCSCL1<OD>))

// DDCSDA1
#define _PIN_59                                 (9 & 0x0F) // Page-10-0xD7[3:0]
// 0 ~ 9 (0: P3D1i<I>, 1: P3D1o<PP>, 2: P3D1o<OD>, 3: TXD<OD>, 4: TCON3<O>, 
//        5: TCON5<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>,9: DDCSDA1<OD>))
// DDC1 function needs to be selected for both pins (58 & 59)

// When Page 10-0xD6[0] = 1 && Pin 55 = 1, Disable ddc function of Pin 58, Pin 59
// and swap to Pin 52, Pin 53
#define _PIN_58_59_DDC1_to_52_53    	    	(0 & 0x01) // Page 10-0xD6[0]
// 0 ~ 1 (0: Disable, 1: Enable)

// Menu Key
#define _PIN_63                                 (0 & 0x0F) // Page 10-0xD8[3:0]
// 0 ~ 11 (0: PCD3i<I>, 1: PCD3o<PP>, 2: PCD3o<OD>, 3: PWM2<PP> , 4: PWM2<OD>, 
//        5: TCON1<O>, 6: TCON8<O>, 7: TCON16<O>,8:INT0<I>,9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>)
// Power Key
#define _PIN_64                                 (0 & 0x1F) // Page 10-0xD9[4:0]
// 0 ~ 17(0: P1D0i<I>, 1: P1D0o<PP>, 2: P1D0o<OD>, 3: PWM0<PP>, 4: PWM0<OD>,
//        5: PWM3<PP>, 6: PWM3<OD>, 7: TCON0<O>, 8: TCON6<O>, 9: TCON7<O>,
//        10: TCON15<O>,11: SD0<O>, 12:SPDIF0<O>, 13:T2<I>, 14:INT1<I>,15: TEST_PIN0<O>, 16: TEST_PIN1<O>, 17: DUMMY<O>)

// RW_PD for EXT_MCU
#define _PIN_65                                 (1 & 0x0F) // Page 10-0xDA[3:0]
// 0 ~ 11 (0: P1D1i<I>, 1: P1D1o<PP>, 2: P1D1o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON1<O>, 6: TCON7<O>, 7: T2EX<I>,8: WS<O>,9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>)

// onPANEL_12V for EXT_MCU
#define _PIN_66                                 (2 & 0x0F) // Page 10-0xDB[3:0]
// 0 ~ 10 (0: P1D2i<I>, 1: P1D2o<PP>, 2: P1D2o<OD>, 3: CLKO<O>, 4: SCK<O>, 
//        5: TCON2<O>, 6: TCON4<O>,7:TCON16<O>,8: TEST_PIN0<O>, 9: TEST_PIN1<O>, 10: DUMMY<O> ,11: DDC2P)

// VGA_CABLE_DET
#define _PIN_67                                 (0 & 0x0F) // Page 10-0xDC[3:0]
// 0 ~ 9 (0: P1D3i<I>, 1: P1D3o<PP>, 2: P1D3o<OD>, 3: MCK<O>, 4: TCON5<O>, 
//        5: TCON9<O>,6: TCON12<O>, 7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>, 10: DDC2P)

// AMP_POWER
#define _PIN_68                                 (1 & 0x0F) // Page 10-0xDD[3:0]
// 0 ~ 11 (0: P1D4i<I>, 1: P1D4o<PP>, 2: P1D4o<OD>, 3: SD0<O>, 4: PWM0<PP>, 
//        5: PWM0<OD>, 6: SPDIF0<O>, 7:TCON14<O>, 8:TCON15<O>,9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>)

// MUTE_AMP_CTL
#define _PIN_69                                 (1 & 0x0F) // Page 10-0xDE[3:0]
// 0 ~ 11 (0: P1D5i<I>, 1: P1D5o<PP> , 2: P1D5o<OD>, 3: SD1<O>, 4: TCON3<O>, 
//        5: TCON7<O>, 6: SPDIF1<O>, 7: PWM2<PP>,8: PWM2<OD>,9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>, 12:DDC2P,13:IIC)

// STB_AMP_CTL
#define _PIN_70                                 (1 & 0x0F) // Page 10-0xDF[3:0]
// 0 ~ 11 (0: P1D6i<I>, 1: P1D6o<PP>, 2: P1D6o<OD>, 3: SD2<O>, 4: TCON9<O>, 
//        5: TCON11<O>, 6: SPDIF2<O>, 7: PWM4<PP>, 8: PWM4<OD>,9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>, 12:DDC2P,13:IIC)
// IIC function needs to be selected for both pins (69 & 70)

// NC Pin
#define _PIN_71                                 (0 & 0x0F) // Page 10-0xE0[3:0]
// 0 ~ 13 (0: P1D7i<I>, 1: P1D7o<PP>, 2: P1D7o<OD>, 3: PWM1<PP>, 4: PWM1<OD>, 
//        5: PWM5<PP>, 6: PWM5<OD>, 7: TCON8<O>,8: TCON10<O>, 9: SD3<O>, 10: SPDIF3<O>, 11: TEST_PIN0<O>, 12: TEST_PIN1<O>, 13: DUMMY<O>)

// NC Pin
#define _PIN_72                                 (1 & 0x0F) // Page 10-0xE1[3:0]
// 0 ~ 9 (0: PCD2i<I>, 1: PCD2o<PP>, 2: PCD2o<OD>, 3:PWM3<PP>, 4: PWM3<OD>, 
//        5: TCON6<O>, 6: TCON12<O>, 7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>)

#define _PIN_74_75_76_77_78_79_80_81_82_83      (0 & 0x03) // Page 10-0xE2[1:0]
// 0 ~ 3 (0: Hi-Z, 1: GPI, 2: GPO<PP>, 3:GP<OD>)
// (Pin74-Pin78 P9.0~P9.4)
// (Pin79-Pin83 PA.0~PA.4)
// Active if single-port LVDS without E/O swap and global power saving/down disabled
// (For Pin 74,75,78,79 , Page 10-0xB6[7:0] is effective only if Page 10-0xE2[1:0]=2'b10)
// Pin 74,75,78,79: Pin share for P9PAo(push-pull) ,Audio IIS and Audio SPDIF .
#define _PIN_74                                 (0 & 0x03) // Page 10-0xE3[7:6]
// 0 ~ 3 (0: P9D0o<PP>, 1: IIS_SD0<O>, 2: SPDIF0<O>, 3: DUMMY<O>)
#define _PIN_75                                 (0 & 0x03) // Page 10-0xE3[5:4]
// 0 ~ 3 (0: P9D1o<PP>, 1: IIS_MCK<O>, 2: SPDIF1<O>, 3: DUMMY<O>)
#define _PIN_78                                 (0 & 0x03) // Page 10-0xE3[3:2]
// 0 ~ 3 (0: P9D4o<PP>, 1: IIS_SCK<O>, 2: SPDIF2<O>,3: DUMMY<O>)
#define _PIN_79                                 (0 & 0x03) // Page 10-0xE3[1:0]
// 0 ~ 3 (0: PAD0o<PP>, 1: IIS_WS<O>, 2: SPDIF3<O>, 3: DUMMY<O>)

// NC Pin
#define _PIN_96                                 (0 & 0x0F) // Page 10-0xE4[3:0]
// 0 ~ 7 (0: P5D2i<I>, 1: P5D2o<PP>, 2: P5D2o<OD>, 3: PWM0<PP>,4: PWM0<OD>, 5: TEST_PIN2<O>, 6: TEST_PIN3<O>, 7: DUMMY<O>)

// NC Pin
#define _PIN_97                                 (0 & 0x0F) // Page 10-0xE5[3:0]
// 0 ~ 8 (0: P5D3i<I>, 1: P5D3o<PP>, 2: P5D3o<OD>, 3: PWM1<PP>, 4: PWM1<OD>, 5:TCONS0<O>,  6: TEST_PIN2<O>, 7: TEST_PIN3<O>, 8: DUMMY<O>) 


// NC Pin
#define _PIN_98                                 (0 & 0x0F) // Page 10-0xE6[3:0]
// 0 ~ 9 (0: P5D4i<I>, 1: P5D4o<PP>, 2: P5D4o<OD>, 3: PWM2<PP>, 4: PWM2<OD>, 5: TCON13<O>, 6: TCON15<O> ,7: TEST_PIN2<O>, 8: TEST_PIN3<O>, 9: DUMMY<O>) )

// NC Pin
#define _PIN_99                                 (0 & 0x0F) // Page 10-0xE7[3:0]
// 0 ~ 9 (0: P5D5i<I>, 1: P5D5o<PP>, 2: P5D5o<OD>, 3: PWM3<PP>, 4: PWM3<OD>, 5: TCON0<O>, 
//        6: TCON6<O>, 7: TCON11<O>, 8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 20: DUMMY<O>) ))

// ADJBACKLITE
#define _PIN_100                                (4 & 0x1F) // Page 10-0xE8[4:0]
// 0 ~ 16 (0: P5D6i<I>, 1: P5D6o<PP>, 2: P5D6o<OD>, 3: PWM4<PP>, 4: PWM4<OD>,
//        5: TCONS1<O>, 6: TCON3<O>,7 :TCON12<O>,8: FIELD<O>, 9: DHS<O>, 10:DVS<O>, 11: DENA<O>, 12: DCLK <O>, 13: L_R <O> ,14: TEST_PIN2<O>, 15: TEST_PIN3<O>, 16: DUMMY<O>) )

// NC Pin
#define _PIN_101                                (0 & 0x0F) // Page 10-0xE9[3:0]
// 0 ~ 12 (0: P5D7i<I>, 1: P5D7o<PP>, 2: P5D7o<OD>, 3: PWM5<PP>,4: PWM5<OD>, 5: TCON14<O>, 6: DHS<O>, 7:DVS<O>, 8: DENA<O>, 9: DCLK <O> ,10: TEST_PIN2<O>, 11: TEST_PIN3<O>, 12: DUMMY<O>) 

// DP_CABLE_DET
#define _PIN_102                                (0 & 0x0F) // Page 10-0xEA[3:0]
// 0 ~ 10 (0: P7D6i<I>, 1: P7D6o<PP>, 2: P7D6o<OD>, 3: PWM0<PP>, 4: PWM0<OD>, 
//        5: TCON10<O>, 6: SD3<O>, 7: SPDIF3<O>,8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 10: DUMMY<O>)

// HDMI Cable Detect
#define _PIN_103                                (0 & 0x0F) // Page 10-0xEB[3:0]
// 0 ~ 10 (0: P7D5i<I>, 1: P7D5o<PP>, 2: P7D5o<OD>, 3: PWM1<PP>, 4: PWM1<OD>, 
//        5: TCON8<O>, 6: SD2<O>, 7: SPDIF2<O>,8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 10: DUMMY<O>, 11: IIC, 12:IIC_AUX) 

// Left Key
#define _PIN_104                                (0 & 0x0F) // Page 10-0xEC[3:0]
// 0 ~ 9 (0: P7D4i<I>, 1: P7D4o<PP>, 2: P7D4o<OD>, 3: SD1<O>, 4: IRQB<O>, 
//        5: TCON5<O>, 6: SPDIF1<O>,7: TEST_PIN2<O>, 8: TEST_PIN3<O>, 9: DUMMY<O>, 10: IIC, 11:IIC_AUX) 
// IIC function needs to be selected for both pins (103 & 104)
															
// AUDIO
#define _PIN_105                                (0 & 0x0F) // Page 10-0xED[3:0]
// 0 ~ 10 (0: P8D0i<I>, 1: P8D0o<PP>, 2: P8D0o<OD>, 3: TCON9<O>, 4: SD0<O>, 
//         5: SPDIF0<O>, 6: AUX_TXDATA, 7: TCON6<O>, 8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 10: DUMMY<O>) 

// Right Key
#define _PIN_108                                (0 & 0x0F) // Page 10-0xEE[3:0]
// 0 ~ 11 (0: P8D1i<I>, 1: P8D1o<PP>, 2: PBD1o<OD>, 3: CLKO<O>, 4: MCK<O>, 
//         5: TCON7<O>, 6: AUX_OE<I>, 7: TEST_PIN2<O>, 8: TEST_PIN3<O>, 9: DUMMY<O>) 

// LED5
#define _PIN_109                                (2 & 0x0F) // Page 10-0xEF[3:0]
// 0 ~ 11 (0: P3D2i<I>, 1: P3D2o<PP>, 2: P3D2o<OD>, 3 INT0<I>, 4: TCON3<O>, 
//         5: SCK<O>, 6: AUX_D1<O>,7: PWM2<PP>, 8: PWM2<OD>,9: TEST_PIN2<O>, 10: TEST_PIN3<O>, 11: DUMMY<O>) 

// LED6
#define _PIN_110                                (2 & 0x0F) // Page 10-0xF0[3:0]
// 0 ~ 9 (0: P3D3i<I>, 1: P3D3o<PP>, 2: P3D3o<OD>, 3: TCON2<O>, 4: TCON6<O>, 
//        5: TCON7<O>, 6: INT1<I>, 7: WS<O>, 8: SD1<O>,9: TEST_PIN2<O>, 10: TEST_PIN3<O>, 11: DUMMY<O>) 
// LED7
#define _PIN_111                                (2 & 0x0F) // Page 10-0xF1[3:0]
// 0 ~ 10 (0: P3D4i<I>, 1: P3D4o<PP>, 2: P3D4o<OD>, 3: TCON4<O>, 4: TCON7<O>, 
//        5: T0<I>, 6: SD0<O>, 7: SPDIF<O>,8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 10: DUMMY<O>) 
// LED8
#define _PIN_112                                (2 & 0x0F) // Page 10-0xF2[3:0]
// 0 ~ 11 (0: P3D5i<I>, 1: P3D5o<PP>, 2: P3D5o<OD>, 3: TCON5<O>, 4: TCON9<O>, 
//        5: T1<O>, 6: SD1<O>, 7: SPDIF1<O>,8: WS<O>,9: TEST_PIN2<O>, 10: TEST_PIN3<O>, 11: DUMMY<O>) 
// LED9
#define _PIN_113                                (2 & 0x0F) // Page 10-0xF3[3:0]
// 0 ~ 11 (0: P3D6i<I>, 1: P3D6o<PP>, 2: P3D6o<OD>, 3: TCON1<O>, 4: TCON11<O>, 
//        5: SD2<O>, 6: SPDIF2<O>, 7: AUX_D2<O>, 8: SCK<O>,9: TEST_PIN2<O>, 10: TEST_PIN3<O>, 11: DUMMY<O>) 
// Exit Key
#define _PIN_114                                (0 & 0x0F) // Page 10-0xF4[3:0]
// 0 ~ 12 (0: P3D7i<I>, 1: P3D7o<PP>, 2: P3D7o<OD>, 3: PWM4<PP>,4: PWM4<OD>, 
//        5: TCON0<O>, 6: TCON13<O>, 7: SD3<O>), 8: SPDIF3<O>, 9: MCK<O>,10: TEST_PIN2<O>, 11: TEST_PIN3<O>, 12: DUMMY<O>) 


// Power On Latch
#define _PIN_119                                (0 & 0x0F) // Page 10-0xF5[3:0]
// 0 ~ 10 (0: Reserved, 1: PCD1o<PP>, 2: PCD1o<OD>, 3: PWM1<PP>,4: PWM1<OD>, 
//        5: PWM5<PP>,6: PWM5<OD>, 7: SPDIF1<O>,8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 10: DUMMY<O>)

// DDCSCL3
#define _PIN_121                                (7 & 0x07) // Page 10-0xF6[2:0]
// 0 ~ 6 (0: P7D3i<I>, 1: P7D3o<PP>, 2: P7D3o<OD>, 3: AUX_CH_P1, 4: TEST_PIN2<O>, 5: TEST_PIN3<O>, 6: DUMMY<O>, 7:DDCSCL3) 
// DDCSDA3
#define _PIN_122                                (7 & 0x07) // Page 10-0xF7[2:0]
// 0 ~ 6 (0: P7D2i<I>, 1: P7D2o<PP>, 2: P7D2o<OD>, 3: AUX_CH_N1, 4: TEST_PIN2<O>, 5: TEST_PIN3<O>, 6: DUMMY<O>, 7:DDCSDA3) 
// DDC3 function needs to be selected for both pins (121 & 122)

// AUX_CHN
#define _PIN_123                                (3 & 0x07) // Page 10-0xB1[3:2]
// 0 ~ 3 (0: P7D1i<I>, 1: P7D1o<PP>, 2: P7D1o<OD>, 3: AUX_CH_N0, 4: TEST_PIN2<O>, 5: TEST_PIN3<O>, 6: DUMMY<O>, 7:DDCSCL2) 
// AUX_CHP
#define _PIN_124                                (3 & 0x07) // Page 10-0xF9[2:0]
// 0 ~ 3 (0: P7D0i<I>, 1: P7D0o<PP>, 2: P7D0o<PP>, 3: AUX_CH_P0,  4: TEST_PIN2<O>, 5: TEST_PIN3<O>, 6: DUMMY<O>, 7:DDCSDA2) 
// DDC2 function needs to be selected for both pins (123 & 124)

// DP_HOT_PLUG
#define _PIN_126                                (1 & 0x0F) // Page 10-0xFA[3:0]
// 0 ~ 6 (0: PCD0i<I>, 1: PCD0o<PP>, 2: PCD0o<OD>, 3: PWMO<PP>, 4: PWMO<OD>,5: PWM1<PP>, 7: TCON14<O> ,8: SPDIF2<O>, 5: CEC<IO>,  6: TEST_PIN2<O>, 7: TEST_PIN3<O>, 8: DUMMY<O>) 
//        5:SPDIF2<O>, 6: PWM1<OD>)
//======================================================================================================
//======================================================================================================

//-----------------------------------------------
// Macro of Pcb Gpio Inital Setting
//-----------------------------------------------

// Enable Write Protect for EEPROM and FLASH
#define PCB_GPIO_INITIAL_SETTING()              {\
                                                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE); \
                                                    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_ENABLE); \
                                                    PCB_PANEL_POWER(_PANEL_CONTROL_OFF); \
                                                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW); \
                                                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH); \  
                                                    PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF); \
                                                    PCB_LED_OFF(); \                                                    
                                                }


///////////////////////////////////////
// Pin39~40,50~53 Function Normal	 //
// Pin41~48 Function Select to Audio //
// Pin65~72,96~103 Normal Operation	 //
///////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT0, 0x00);	\
                                                    ScalerSetBit(P10_B9_PIN_SHARE_CTRL16, ~(_BIT5 | _BIT4), ((BYTE)_P41_48_SEL << 4));	\
                                                    ScalerSetByte(P10_BB_PIN_PULLUP_CTRL4, 0x00);					\
                                                }

////////////////////////////////////////////////////////
// Pin39~40 pull up control --> GPIO Function Disable //
// Pin65~72,96~103 pull up Control					  //
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT0, _BIT0);	\
                                                    ScalerSetBit(P10_BB_PIN_PULLUP_CTRL4, ~(_BIT6 | _BIT2 | _BIT0), _BIT6 | _BIT2 | _BIT0);			\	
                                                }

////////////////////////////////////////////////////////
// Pin50~53 pull up control --> GPIO Function Disable //
// Pin39~40 pull up control --> GPIO Function Disable //
// Pin65~72,96~103 pull up Control					  //
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT0, _BIT0);	\
                                                    ScalerSetBit(P10_BB_PIN_PULLUP_CTRL4, ~(_BIT6 | _BIT2 | _BIT0), _BIT6 | _BIT2 | _BIT0);			\
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
#define bSWIIC_SYS_EEPROM_SCL                   (MCU_PORT66_PIN_REG_FFCD) // Pin 56, P6.6
#define bSWIIC_SYS_EEPROM_SDA                   (MCU_PORT67_PIN_REG_FFCE) // Pin 57, P6.7

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
#define bFLASH_WRITE_PROTECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)   //

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
sbit bEEPROM_WRITE_PROTECT                      = P1 ^ 1; // Pin 65, P1.1

#define _EEPROM_WP_ENABLE                       1       // WP High state for Eeprom
#define _EEPROM_WP_DISABLE                      0       // WP Low state for Eeprom

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = x;  \
                                                }

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)	// 

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                }

#define PCB_D0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                }

#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                }

//-----------------------------------------------
// Macro of Input Connect Detect
//-----------------------------------------------
#define bDP_PIN15_CONNECT                       (MCU_EMPTY_PIN_ASSIGN_ADDRESS) 
#define bDP_PIN16_CONNECT                       (MCU_EMPTY_PIN_ASSIGN_ADDRESS) 
#define bDP_PIN17_CONNECT                       (MCU_EMPTY_PIN_ASSIGN_ADDRESS) 

sbit bA0_CONNECT			                     = P1 ^ 3; // Pin 67, P1.3
#define bD0_CONNECT				                (MCU_EMPTY_PIN_ASSIGN_ADDRESS) 				
#define bD1_CONNECT                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS) 
#define bD2_CONNECT                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD3_CONNECT                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_A0_PIN()                            (SET_A0_CABLE_STATUS(!bA0_CONNECT))
#define PCB_D0_PIN()                            (SET_D0_CABLE_STATUS(!bD0_CONNECT))
#define PCB_D1_PIN()                            (SET_D1_CABLE_STATUS(!bD1_CONNECT))
#define PCB_D2_PIN()                            (SET_D2_CABLE_STATUS(_FALSE))
#define PCB_D3_PIN()                            (SET_D3_CABLE_STATUS(_FALSE))

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD0_HPD									(MCU_PORTC0_PIN_REG_FFA3) // Pin 126, PC.0
#define _D0_HOT_PLUG_HIGH                       1       // D0 Switch High state
#define _D0_HOT_PLUG_LOW                        0       // D0 Switch Low state

#define PCB_D0_HOTPLUG(x)                       {\
                                                    bD0_HPD = x;                    \
                                                }

#define bD1_HPD                                 (MCU_PORT62_PIN_REG_FFC9) // Pin 52, P6.2
#define _D1_HOT_PLUG_HIGH                       1       // D1 Switch High state
#define _D1_HOT_PLUG_LOW                        0       // D1 Switch Low state

#define PCB_D1_HOTPLUG(x)                       {\
                                                    bD1_HPD = x;                    \
                                                }

#define  bD2_HPD                                (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define _D2_HOT_PLUG_HIGH                       1       // D2 Switch High state
#define _D2_HOT_PLUG_LOW                        0       // D2 Switch Low state

#define PCB_D2_HOTPLUG(x)                       {\
                                                }


#define  bD3_HPD                                (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
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
sbit bLED1                                      = P3 ^ 2; // Pin 109, P3.2
sbit bLED2                                      = P3 ^ 3; // Pin 110, P3.3
sbit bLED3                                      = P3 ^ 4; // Pin 111, P3.4
sbit bLED4                                      = P3 ^ 5; // Pin 112, P3.5
sbit bLED5                                      = P3 ^ 6; // Pin 113, P3.6

#define _LED_ON                                 0       // Power on  state for LED
#define _LED_OFF                                1       // Power off state for LED

#define PCB_LED_ACTIVE()                        {\
                                                    bLED1 = _LED_ON;                \
                                                    bLED2 = _LED_OFF;               \
                                                    bLED3 = _LED_OFF;               \
                                                    bLED4 = _LED_OFF;               \
                                                    bLED5 = _LED_OFF;               \                                                    
                                                }

#define PCB_LED_IDLE()                          {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_ON;                \
                                                    bLED3 = _LED_OFF;               \
                                                    bLED4 = _LED_OFF;               \
                                                    bLED5 = _LED_OFF;               \                                                    
                                                }

#define PCB_LED_POWER_SAVING()                  {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_ON;                \
                                                    bLED3 = _LED_OFF;               \
                                                    bLED4 = _LED_OFF;               \
                                                    bLED5 = _LED_OFF;               \  
                                                }

#define PCB_LED_ON()                            {\
                                                    bLED1 = _LED_ON;               \
                                                    bLED2 = _LED_ON;               \
                                                    bLED3 = _LED_ON;               \
                                                    bLED4 = _LED_ON;               \
                                                    bLED5 = _LED_ON;               \                                                    
                                                }

#define PCB_LED_OFF()                           {\
                                                    bLED1 = _LED_OFF;               \
                                                    bLED2 = _LED_OFF;               \
                                                    bLED3 = _LED_OFF;               \
                                                    bLED4 = _LED_OFF;               \
                                                    bLED5 = _LED_OFF;               \                                                    
                                                }

#define PCB_LED_TYPE1()                         {\
                                                    bLED1 = _LED_ON;                \
                                                }

#define PCB_LED_TYPE2()                         {\
                                                    bLED2 = _LED_ON;                \    
                                                }

#define PCB_LED_TYPE3()                         {\
                                                    bLED3 = _LED_ON;                \
                                                }

#define PCB_LED_TYPE4()                         {\
                                                    bLED4 = _LED_ON;                \
                                                }

#define PCB_LED_TYPE5()                         {\
                                                    bLED5 = _LED_ON;                \
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

#define AD_KEY0                                 (MCU_ADC0_RESULT_FF09) // Pin 50, P6.0
#define AD_KEY1                               	(MCU_ADC1_RESULT_FF0A) // Pin 51, P6.1

sbit bPOWER_KEY                                 = P1 ^ 0; // Pin 64, P1.0
#define bMENU_KEY                               (MCU_PORTC3_PIN_REG_FFA0) // Pin 63, PC.3
sbit bEXIT_KEY                                  = P3 ^ 7; // P114, P3.7
#define bLEFT_KEY                               (MCU_PORT74_PIN_REG_FFD3) // Pin 104, P7.4
#define bRIGHT_KEY                              (MCU_PORT81_PIN_REG_FFD7) // Pin 108, P8.1

#define PCB_ADKEY0()                            (AD_KEY0)
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (_FALSE)
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
#define bPANELPOWER								(MCU_PORT64_PIN_REG_FFCB) // Pin 54, P6.4

#define _PANEL_CONTROL_ON                       0       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      1       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = x;                \
                                                }

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER							(MCU_PORT65_PIN_REG_FFCC) // Pin 55, P6.5

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
#define _AMP_POWER_ON                           0       // Amp on state
#define _AMP_POWER_OFF                          1       // Amp off state

#define PCB_AMP_POWER(x)                        {\
                                                }
//-----------------------------------------------
#define _AMP_STAND_BY_ON                        1       // Amp Stand By on state
#define _AMP_STAND_BY_OFF                       0       // Amp Stand By off state

#define PCB_AMP_STAND_BY(x)                     {\
                                                }
//-----------------------------------------------
#define _AMP_MUTE_ON                            0       // Amp Mute on state
#define _AMP_MUTE_OFF                           1       // Amp Mute off state

#define PCB_AMP_MUTE(x)                         {\
                                                }
//-----------------------------------------------
#define _VOLUME_MAX                             255
#define _VOLUME_MIN                             0

#define PCB_AUDIO_VOLUME_PWM(x)                 {\
                                                }

#define PCB_GET_AUDIO_VOLUME_PWM()              (0xFF)

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


#endif // End of #if(_PCB_TYPE == _RL6229_QA_1A2H)

