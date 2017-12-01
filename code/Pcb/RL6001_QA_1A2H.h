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
// ID Code      : RL6001_QA_1A2H.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PCB_TYPE == _RL6001_QA_1A2H)

#define _EXT_XTAL                               _XTAL14318K      


//--------------------------------------------------
// Input Port Define
//--------------------------------------------------
////////////////////////////////////////////////////////
//If _A0_INPUT_PORT_TYPE is _A0_NO_PORT               //
//Please remove the following functions from BL51 Misc//
//BANK0 --> ?CO?USERCOMMONMODESEARCH                  //
//BANK0 --> ?CO?RL6001_SERIES_AUTOFUNC                //
//BANK0 --> ?CO?RL6001_SERIES_PLL                     //
//Otherwise, if _A0_INPUT_PORT_TYPE is _A0_VGA_PORT   //
//Please add the above functions to BL51 Misc         //
////////////////////////////////////////////////////////
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _EMBEDDED_DDCRAM_A0_SIZE                _EDID_SIZE_NONE
#define _EMBEDDED_DDCRAM_A0_LOCATION            _EDID_TABLE_LOCATION_CODE

#define _D0_INPUT_PORT_TYPE                     _D0_HDMI_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC2
#define _EMBEDDED_DDCRAM_D0_SIZE                _EDID_SIZE_NONE
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
#define _LVDS_EO_SWAP                           _DISABLE        // Display Data Port Even/Odd Data Swap              
#define _LVDS_RB_SWAP                           _DISABLE        // Display Data Port Red/Blue Data Swap              
#define _LVDS_ML_SWAP                           _DISABLE        // Display Data Port MSB/LSB Data Swap    

#define _LVDS_DVS_INVERT                        _DISABLE        // DVS Output Invert Enable                
#define _LVDS_DHS_INVERT                        _DISABLE        // DHS Output Invert Enable                
#define _LVDS_DEN_INVERT                        _DISABLE        // DEN Output Invert Enable                

#define _LVDS_MIRROR                            _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE

//--------------------------------------------------
// Definitions for LVDS EMI
//--------------------------------------------------
#define _LVDS_DATA_DRIV_CONTROL                 _LVDS_DRIV_CONTROL_3_5                  
#define _LVDS_CLK_DRIV_CONTROL                  _LVDS_DRIV_CONTROL_3_5                   

#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL

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
#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _ON
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
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _ON
#define _PWM5_RST_BY_DVS                        _OFF

#define _AUDIO_VOLUME_PWM                       _NO_PWM        
#define _AUDIO_VOLUME_PWM_INVERSE               _OFF

#define _BACKLIGHT_PWM                          _PWM4
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

//--------------------------------------------------
// Definitions for Low Speed ADC
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _OFF

//--------------------------------------------------
// RL6001 Series Pin Share
//--------------------------------------------------
// <OD>:open-drain  <PP>:push-pull

// GPIO 31~38
#define _P31_39_SEL                             (1 & 0x01) // Page 10-B9[6]
// 0 ~ 1 (0: Video8, 1: Normal function)

// NC Pin
#define _PIN_31                                 (0 & 0x03) // Page 10-0xB7[7:6]
// 0 ~ 3 (0: PDD7i<I>, 1: PDD7o<PP>, 2: PDD7o<OD>, 3: Reserved)
#define _PIN_32                                 (0 & 0x03) // Page 10-0xB7[5:4]
// 0 ~ 3 (0: PDD6i<I>, 1: PDD6o<PP>, 2: PDD6o<OD>, 3: Reserved)
#define _PIN_33                                 (0 & 0x03) // Page 10-0xB7[3:2]
// 0 ~ 3 (0: PDD5i<I>, 1: PDD5o<PP>, 2: PDD5o<OD>, 3: Reserved)
#define _PIN_34                                 (0 & 0x03) // Page 10-0xB7[1:0]
// 0 ~ 3 (0: PDD4i<I>, 1: PDD4o<PP>, 2: PDD4o<OD>, 3: Reserved)
#define _PIN_35                                 (0 & 0x03) // Page 10-0xB8[7:6]
// 0 ~ 3 (0: PDD3i<I>, 1: PDD3o<PP>, 2: PDD3o<OD>, 3: Reserved)
#define _PIN_36                                 (0 & 0x03) // Page 10-0xB8[5:4]
// 0 ~ 3 (0: PDD2i<I>, 1: PDD2o<PP>, 2: PDD2o<OD>, 3: Reserved)
#define _PIN_37                                 (0 & 0x03) // Page 10-0xB8[3:2]
// 0 ~ 3 (0: PDD1i<I>, 1: PDD1o<PP>, 2: PDD1o<OD>, 3: Reserved)
#define _PIN_39                                 (0 & 0x03) // Page 10-0xB8[1:0]
// 0 ~ 3 (0: PDD0i<I>, 1: PDD0o<PP>, 2: PDD0o<OD>, 3: Reserved)

// NC Pin
#define _PIN_40                                 (0 & 0x03) // Page 10-0xB9[1:0]
// 0 ~ 3 (0: PCD4i<I>, 1: PCD4o<PP>, 2: PCD4o<OD>, 3: VCLK)

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
#define _PIN_41                                 (0 & 0x03) // Page 10-0xA0[7:6]
// 0 ~ 3 (0: PBD7i<I>, 1: PBD7o<OD>, 2: PBD7o<PP>, 3: TCON5<O>)

// Line In
#define _PIN_42                                 (0 & 0x03) // Page 10-0xA0[5:4]
// 0 ~ 3 (0: PBD6i<I>, 1: PBD6o<OD>, 2: PBD6o<PP>, 3: IICSCL<OD>)
#define _PIN_43                                 (0 & 0x03) // Page 10-0xA0[3:2]
// 0 ~ 3 (0: PBD5i<I>, 1: PBD5o<OD>, 2: PBD5o<PP>, 3: IICSDA<OD>)

// NC Pin
#define _PIN_44                                 (0 & 0x07) // Page 10-0xA8[7:5]
// 0 ~ 4 (0: PBD4i<I>, 1: PBD4o<OD>, 2: PBD4o<PP>, 3: WS<O>, 4: SPDIF3<O>)

// HDMI HPD_1
#define _PIN_45                                 (2 & 0x03) // Page 10-0xA1[7:6]
// 0 ~ 3 (0: PBD3i<I>, 1: PBD3o<OD>, 2: PBD3o<PP>, 3: SCK<O>)

// HDMI_POWER_1
#define _PIN_46                                 (0 & 0x03) // Page 10-0xA3[7:6]
// 0 ~ 3 (0: PBD2i<I>, 1: PBD2o<OD>, 2: PBD2o<PP>, 3: MCK<O>)

// AUDIO HOUT
#define _PIN_47                                 (0 & 0x03) // Page 10-0xA6[7:6]
// 0 ~ 3 (0: PBD1i<I>, 1: PBD1o<OD>, 2: PBD1o<PP>, 3: SD0<O>)
#define _PIN_48                                 (0 & 0x03) // Page 10-0xA7[7:6]
// 0 ~ 3 (0: PBD0i<I>, 1: PBD0o<OD>, 2: PBD0o<PP>, 3: PWM0<PP>)

// AD KEY
#define _PIN_50                                 (3 & 0x07) // Page 10-0xAB[7:5]
// 0 ~ 5 (0: P6D0i<I>, 1: P6D0o<OD>, 2: P6D0o<PP>, 3: ADCA0<I>, 4: Reserved,
//        5: VCLK<I>)
#define _PIN_51                                 (3 & 0x03) // Page 10-0xA3[5:4]
// 0 ~ 3 (0: P6D1i<I>, 1: P6D1o<OD>, 2: P6D1o<PP>, 3: ADCA1<I>)

// AD_KEY_LED1
#define _PIN_52                                 (2 & 0x03) // Page 10-0xA4[7:6]
// 0 ~ 3 (0: P6D2i<I>, 1: P6D2o<OD>, 2: P6D2o<PP>, 3: ADCA2<I>)

// DP_SINK_ASS_1
#define _PIN_53                                 (0 & 0x03) // Page 10-0xA5[7:6]
// 0 ~ 3 (0: P6D3i<I>, 1: P6D3o<OD>, 2: P6D3o<PP>, 3: ADCA3<I>)

// onPanel_5V
#define _PIN_54                                 (1 & 0x03) // Page 10-0xA0[1:0]
// 0 ~ 3 (0: P6D4i<I>, 1: P6D4o<OD>, 2: P6D4o<PP>, 3: Reserved)

// onBACKLITE
#define _PIN_55                                 (1 & 0x07) // Page 10-0xA6[5:3]
// 0 ~ 7 (0: P6D5i<I>, 1: P6D5o<OD>, 2: P6D5o<PP>, 3: PWM1<OD>, 4: PWM1<PP>, 
//        5: PWM5<PP>, 6: TCON0<O>, 7: TCON5<O>)

// EESCL
#define _PIN_56                                 (6 & 0x07) // Page 10-0xAF[6:4]
// 0 ~ 5 (0: P6D6i<I>, 1: P6D6o<OD>, 2: P6D6o<PP>, 3: Reserved, 4: TCON1<O>, 
//        5: TCON4<O>, 6: IICSCL<OD>)

// EESDA
#define _PIN_57                                 (6 & 0x07) // Page 10-0xAF[3:1]
// 0 ~ 5 (0: P6D7i<I>, 1: P6D7o<OD>, 2: P6D7o<PP>, 3: Reserved, 4: TCON9<O>, 
//        5: TCON11<O>, 6: IICSDA<OD>)
// IIC function needs to be selected for both pins (56 & 57)

// DDCSCL1
#define _PIN_58                                 (6 & 0x07) // Page 10-0xA2[6:4]
// 0 ~ 5 (0: P3D0i<I>, 1: P3D0o<OD>, 2: P3D0o<PP>, 3: RXD<OD>, 4: TCON7<O>, 
//        5: TCON10<O>, 6: DDCSCL1<OD>)

// DDCSDA1
#define _PIN_59                                 (6 & 0x07) // Page-10-0xA2[3:1]
// 0 ~ 5 (0: P3D1i<I>, 1: P3D1o<OD>, 2: P3D1o<PP>, 3: TXD<OD>, 4: TCON3<O>, 
//        5: TCON5<O>, 6: DDCSDA1<OD>)
// DDC1 function needs to be selected for both pins (58 & 59)

// When Page 10-0xA2[0] = 1 && Pin 55 = 1, Disable ddc function of Pin 58, Pin 59
// and swap to Pin 52, Pin 53
#define _PIN_58_59_DDC1_to_52_53                (0 & 0x01) // Page 10-0xA2[0]
// 0 ~ 1 (0: Disable, 1: Enable)

// Menu Key
#define _PIN_63                                 (0 & 0x07) // Page 10-0xA6[2:0]
// 0 ~ 7 (0: PCD3i<I>, 1: PCD3o<OD>, 2: PCD3o<PP>, 3: PWM2<PP> , 4: TCON1<O>, 
//        5: TCON8<O>, 6: PWM2<OD>, 7: INT0<I>)

// Power Key
#define _PIN_64                                 (0 & 0x0F) // Page 10-0xA3[3:0]
// 0 ~ 10(0: P1D0i<I>, 1: P1D0o<OD>, 2: P1D0o<PP>, 3: T2<I>, 4: SD0<O>,
//        5: SPDIF0<O>, 6: TCON0<O>, 7: PWM0<PP>, 8: TCON7<O>, 9: PWM0<OD>,
//        10: INT1<I>)

// RW_PD for EXT_MCU
#define _PIN_65                                 (1 & 0x07) // Page 10-0xB1[7:5]
// 0 ~ 7 (0: P1D1i<I>, 1: P1D1o<PP>, 2: PWM1<PP>, 3: T2EX<I>, 4: TCON1<O>,
//        5: TCON7<O>, 6: WS<O>, 7: PWM1<OD>)

// onPANEL_12V for EXT_MCU
#define _PIN_66                                 (1 & 0x07) // Page 10-0xA4[5:3]
// 0 ~ 6 (0: P1D2i<I>, 1: P1D2o<PP>, 2: P1D2o<OD>, 3: CLKO<O>, 4: SCK<O>, 
//        5: TCON2<O>, 6: TCON4<O>)

// VGA_CABLE_DET
#define _PIN_67                                 (0 & 0x07) // Page 10-0xA4[2:0]
// 0 ~ 5 (0: P1D3i<I>, 1: P1D3o<PP>, 2: P1D3o<OD>, 3: MCK<O>, 4: TCON5<O>, 
//        5: TCON9<O>)

// NC Pin
#define _PIN_68                                 (0 & 0x07) // Page 10-0xA7[5:3]
// 0 ~ 6 (0: P1D4i<I>, 1: P1D4o<PP>, 2: P1D4o<OD>, 3: SD0<O>, 4: TCON3<O>, 
//        5: TCON13<O>, 6: SPDIF0<O>)

// NC Pin
#define _PIN_69                                 (0 & 0x07) // Page 10-0xA5[5:3]
// 0 ~ 7 (0: P1D5i<I>, 1: P1D5o<PP> , 2: P1D5o<OD>, 3: SD1<O>, 4: TCON3<O>, 
//        5: TCON7<O>, 6: SPDIF1<O>, 7: IICSCL<OD>)

// HDMI_HPD_0
#define _PIN_70                                 (1 & 0x07) // Page 10-0xA5[2:0]
// 0 ~ 7 (0: P1D6i<I>, 1: P1D6o<PP>, 2: P1D6o<OD>, 3: SD2<O>, 4: TCON9<O>, 
//        5: TCON11<O>, 6: SPDIF2<O>, 7: IICSDA<OD>)
// IIC function needs to be selected for both pins (69 & 70)

// HDMI_POWER_0
#define _PIN_71                                 (0 & 0x07) // Page 10-0xA7[2:0]
// 0 ~ 7 (0: P1D7i<I>, 1: P1D7o<PP>, 2: PWM5<PP>, 3: SD3<O>, 4: TCON8<O>, 
//        5: TCON10<O>, 6: SPDIF3<O>, 7: PWM1<PP>)

// NC Pin
#define _PIN_72                                 (0 & 0x07) // Page 10-0xB2[7:5]
// 0 ~ 5 (0: PCD2i<I>, 1: PCD2o<PP>, 2: TCON6<O>, 3:TCON12<O>, 4: PWM3<PP>, 
//        5: PWM3<OD>)

#define _PIN_74_75_76_77_78_79_80_81_82_83      (0 & 0x03) // Page 10-0xA9[7:6]
// 0 ~ 3 (0: Hi-Z, 1: GPI, 2: GPO<PP>, 3:GP<OD>)
// (Pin74-Pin78 P9.0~P9.4)
// (Pin79-Pin83 PA.0~PA.4)
// Active if single-port LVDS without E/O swap and global power saving/down disabled
// (For Pin 74,75,78,79 , Page 10-0xB6[7:0] is effective only if Page 10-0xA9[7:6]=2'b10)
// Pin 74,75,78,79: Pin share for P9PAo(push-pull) ,Audio IIS and Audio SPDIF .
#define _PIN_74                                 (0 & 0x03) // Page 10-0xB6[7:6]
// 0 ~ 3 (0: P9D0o<PP>, 1: IIS_SD0<O>, 2: SPDIF0<O>, 3: Reserved)
#define _PIN_75                                 (0 & 0x03) // Page 10-0xB6[5:4]
// 0 ~ 3 (0: P9D1o<PP>, 1: IIS_MCK<O>, 2: SPDIF1<O>, 3: Reserved)
#define _PIN_78                                 (0 & 0x03) // Page 10-0xB6[3:2]
// 0 ~ 3 (0: P9D4o<PP>, 1: IIS_SCK<O>, 2: SPDIF2<O>, 3: Reserved)
#define _PIN_79                                 (0 & 0x03) // Page 10-0xB6[1:0]
// 0 ~ 3 (0: PAD0o<PP>, 1: IIS_WS<O>, 2: SPDIF3<O>, 3: Reserved)

// Exit Key
#define _PIN_96                                 (0 & 0x03) // Page 10-0xA8[4:3]
// 0 ~ 3 (0: P5D2i<I>, 1: P5D2o<PP>, 2: DCLK<O>, 3: PWM0<PP>)

// NC Pin
#define _PIN_97                                 (0 & 0x07) // Page 10-0xA8[2:0]
// 0 ~ 5 (0: P5D3i<I>, 1: P5D3o<PP>, 2: P5D3o<OD>, 3: PWM1<PP>, 4: DVS<O>, 
//        5: PWM1<OD>)

// NC Pin
#define _PIN_98                                 (0 & 0x03) // Page 10-0xAA[7:6]
// 0 ~ 3 (0: P5D4i<I>, 1: P5D4o<PP>, 2: P5D4o<OD>, 3: PWM2<PP>)

// NC Pin
#define _PIN_99                                 (0 & 0x07) // Page 10-0xA9[5:3]
// 0 ~ 6 (0: P5D5i<I>, 1: P5D5o<PP>, 2: P5D5o<OD>, 3: PWM3<PP>, 4: TCON6<O>, 
//        5: TCON11<O> , 6: PWM3<OD>)

// ADJBACKLITE
#define _PIN_100                                (6 & 0x07) // Page 10-0xA9[2:0]
// 0 ~ 6 (0: P5D6i<I>, 1: P5D6o<PP>, 2: P5D6o<OD>, 3: PWM4<PP>, 4: TCON3<O>,
//        5: TCON12<O>, 6: PWM4<OD>)

// Right Key
#define _PIN_101                                (0 & 0x03) // Page 10-0xAB[4:3]
// 0 ~ 3 (0: P5D7i<I>, 1: P5D7o<PP>, 2: TCON0<O>, 3: PWM5<PP>)

// NC Pin
#define _PIN_102                                (0 & 0x07) // Page 10-0xAA[5:3]
// 0 ~ 7 (0: P7D6i<I>, 1: P7D6o<PP>, 2: P7D6o<OD>, 3: PWM0<PP>, 4: SD3<O>, 
//        5: SPDIF3<O>, 6: TCON10<O>, 7: PWM0<OD>)

// VIDEO_PD
#define _PIN_103                                (1 & 0x07) // Page 10-0xAC[6:4]
// 0 ~ 7 (0: P7D5i<I>, 1: P7D5o<PP>, 2: P7D5o<OD>, 3: PWM1<PP>, 4: SD2<O>, 
//        5: SPDIF2<O>, 6: TCON8<O>, 7: IICSCL<OD>)

// Left Key
#define _PIN_104                                (0 & 0x07) // Page 10-0xAC[3:1]
// 0 ~ 7 (0: P7D4i<I>, 1: P7D4o<PP>, 2: P7D4o<OD>, 3: SD1<O>, 4: IRQB<O>, 
//        5: TCON5<O>, 6: SPDIF1<O>, 7: IICSDA<OD>)
// IIC function needs to be selected for both pins (103 & 104)

// AUDIO
#define _PIN_105                                (0 & 0x07) // Page 10-0xAA[2:0]
// 0 ~ 6 (0: P8D0i<I>, 1: P8D0o<PP>, 2: P8D0o<OD>, 3: TCON9<O>, 4: SD0<O>, 
//        5: SPDIF0<O>, 6: AUX_TXDATA)

// NC Pin
#define _PIN_108                                (1 & 0x07) // Page 10-0xAB[2:0]
// 0 ~ 6 (0: P8D1i<I>, 1: P8D1o<PP>, 2: PBD1o<OD>, 3: CLKO<O>, 4: MCK<O>, 
//        5: TCON7<O>, 6: AUX_OE<I>)

// LED5
#define _PIN_109                                (1 & 0x07) // Page 10-0xAD[6:4]
// 0 ~ 6 (0: P3D2i<I>, 1: P3D2o<PP>, 2: P3D2o<OD>, 3 INT0<I>, 4: TCON3<O>, 
//        5: SCK<O>, 6: AUX_D1<O>)

// IIS_MIRROR
#define _PIN_110_111_112_113_114_MIRROR         (0 & 0x01) // Page 10-0xAD[7]
// 0 ~ 1 (0: Pin 110 WS , Pin 111 SD0, Pin 112 SD1, Pin 113 SD2, Pin 114 SD3,
//        1: Pin 110 SD1, Pin 111 SD0, Pin 112 WS, Pin 113 SCK, Pin 114 MCK)

#if(_PIN_110_111_112_113_114_MIRROR == 0)
// LED6
#define _PIN_110                                (1 & 0x07) // Page 10-0xAD[2:0]
// 0 ~ 7 (0: P3D3i<I>, 1: P3D3o<OD>, 2: P3D3o<PP>, 3: INT1<I>, 4: TCON6<O>, 
//        5: WS<O>, 6: TCON2<O>, 7: TCON7<O>)
// LED7
#define _PIN_111                                (1 & 0x07) // Page 10-0xAE[6:4]
// 0 ~ 7 (0: P3D4i<I>, 1: P3D4o<OD>, 2: P3D4o<PP>, 3: T0<I>, 4: TCON4<O>, 
//        5: SD0<O>, 6: SPDIF0<O>, 7: TCON7<O>)
// LED8
#define _PIN_112                                (1 & 0x07) // Page 10-0xAE[2:0]
// 0 ~ 7 (0: P3D5i<I>, 1: P3D5o<OD>, 2: P3D5o<PP>, 3: T1<I>, 4: TCON9<O>, 
//        5: SD1<O>, 6: SPDIF1<O>, 7: TCON5<O>)
// LED9
#define _PIN_113                                (1 & 0x07) // Page 10-0xB0[7:5]
// 0 ~ 7 (0: P3D6i<I>, 1: P3D6o<OD>, 2: P3D6o<PP>, 3: TCON1<O>, 4: SD2<O>, 
//        5: SPDIF2<O>, 6: AUX_D2<O>, 7:TCON11<O>)
// NC Pin
#define _PIN_114                                (0 & 0x07) // Page 10-0xB2[4:2]
// 0 ~ 7 (0: P3D7i<I>, 1: P3D7o<OD>, 2: P3D7o<PP>, 3: TCON13<O>,4: SD3<O>, 
//        5: SPDIF3<O>, 6: PWM4<PP>, 7:TCON0<O>)
#else
// LED6
#define _PIN_110                                (1 & 0x07) // Page 10-0xAD[2:0]
// 0 ~ 7 (0: P3D3i<I>, 1: P3D3o<OD>, 2: P3D3o<PP>, 3: INT1<I>, 4: TCON6<O>, 
//        5: SD1<O>, 6: TCON2<O>, 7: TCON7<O>)
// LED7
#define _PIN_111                                (1 & 0x07) // Page 10-0xAE[6:4]
// 0 ~ 7 (0: P3D4i<I>, 1: P3D4o<OD>, 2: P3D4o<PP>, 3: T0<I>, 4: TCON4<O>, 
//        5: SD0<O>, 6: SPDIF0<O>, 7: TCON7<O>)
// LED8
#define _PIN_112                                (1 & 0x07) // Page 10-0xAE[2:0]
// 0 ~ 7 (0: P3D5i<I>, 1: P3D5o<OD>, 2: P3D5o<PP>, 3: T1<I>, 4: TCON9<O>, 
//        5: WS<O>, 6: SPDIF1<O>, 7: TCON5<O>)
// LED9
#define _PIN_113                                (1 & 0x07) // Page 10-0xB0[7:5]
// 0 ~ 7 (0: P3D6i<I>, 1: P3D6o<OD>, 2: P3D6o<PP>, 3: TCON1<O>, 4: SCK<O>, 
//        5: SPDIF2<O>, 6: AUX_D2<O>, 7:TCON11<O>)
// NC Pin
#define _PIN_114                                (0 & 0x07) // Page 10-0xB2[4:2]
// 0 ~ 7 (0: P3D7i<I>, 1: P3D7o<OD>, 2: P3D7o<PP>, 3: TCON13<O>,4: MCK<O>, 
//        5: SPDIF3<O>, 6: PWM4<PP>, 7:TCON0<O>)
#endif

// Power On Latch
#define _PIN_119                                (0 & 0x07) // Page 10-0xA1[5:3]
// 0 ~ 5 (0: Reserved, 1: PCD1o<OD>, 2: PCD1o<PP>, 3: PWM5<PP>,4: SPIF1<O>, 
//        5: PWM5<OD>)

// DDCSCL3
#define _PIN_121                                (4 & 0x07) // Page 10-0xB0[3:2]
// 0 ~ 3 (0: P7D3i<I>, 1: P7D3o<OD>, 2: P7D3o<PP>, 3: AUX_CH_P1, 4: DDCSCL3<OD>)
// DDCSDA3
#define _PIN_122                                (4 & 0x07) // Page 10-0xB0[1:0]
// 0 ~ 3 (0: P7D2i<I>, 1: P7D2o<OD>, 2: P7D2o<PP>, 3: AUX_CH_N1, 4: DDCSDA3<OD>)
// DDC3 function needs to be selected for both pins (121 & 122)

// DDCSCL2
#define _PIN_123                                (4 & 0x07) // Page 10-0xB1[3:2]
// 0 ~ 3 (0: P7D1i<I>, 1: P7D1o<OD>, 2: P7D1o<PP>, 3: AUX_CH_N0, 4: DDCSCL2<OD>)
// DDCSDA2
#define _PIN_124                                (4 & 0x07) // Page 10-0xB1[1:0]
// 0 ~ 3 (0: P7D0i<I>, 1: P7D0o<OD>, 2: P7D0o<PP>, 3: AUX_CH_P0, 4: DDCSDA2<OD>)
// DDC2 function needs to be selected for both pins (123 & 124)

// CEC
#define _PIN_126                                (1 & 0x07) // Page 10-0xA1[2:0]
// 0 ~ 6 (0: PCD0i<I>, 1: PCD0o<OD>, 2: PCD0o<PP>, 3: PWM1<PP>, 4: Reserved,
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
                                                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH); \ 
                                                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH); \ 
                                                    PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF); \
                                                    PCB_LED_OFF(); \                                                    
                                                }

////////////////////////////////////////////////////////////////////////
// Pin41~48 Function Select to user defined                           //
// Pin39~40,50~53,65~66,69~70,96~97,100~101 disable pull up control   //
// Pin67~68,71~72,98~99,102~103 disable pull down control             // 
////////////////////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~(_BIT7 | _BIT0), 0x00); \
                                                    ScalerSetBit(P10_B9_PIN_SHARE_CTRL16, ~(_BIT5 | _BIT4 | _BIT1 | _BIT0), ((BYTE)_P41_48_SEL << 4)| (_PIN_40));    \
                                                    ScalerSetByte(P10_BB_PIN_PULLUP_CTRL4, 0x00); \
                                                }

///////////////////////////////////////////////////////////////////////
// Pin39~40,50~53,65~66,69~70,96~97,100~101 enable pull up control   //
// Pin67~68,71~72,98~99,102~103 enable pull down control             // 
///////////////////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~(_BIT7 | _BIT0), _BIT7 | _BIT0); \
                                                    ScalerSetByte(P10_BB_PIN_PULLUP_CTRL4, 0xFF);\    
                                                }

///////////////////////////////////////////////////////////////////////
// Pin39~40,50~53,65~66,69~70,96~97,100~101 enable pull up control   //
// Pin67~68,71~72,98~99,102~103 enable pull down control             //
///////////////////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~(_BIT7 | _BIT0), _BIT7 | _BIT0); \
                                                    ScalerSetByte(P10_BB_PIN_PULLUP_CTRL4, 0xFF); \
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
                                                    bFLASH_WRITE_PROTECT = x;   \
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
#define bEDID_WRITE_PROTECT                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)    // 

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
#define bDP_PIN15_CONNECT                       (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bDP_PIN16_CONNECT                       (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bDP_PIN17_CONNECT                       (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

sbit bA0_CONNECT                                = P1 ^ 3; // Pin 67, P1.3
#define bD0_CONNECT                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
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
sbit bD0_HPD                                    = P1 ^ 6; // Pin 70, P1.6
#define _D0_HOT_PLUG_HIGH                       1       // D0 Switch High state
#define _D0_HOT_PLUG_LOW                        0       // D0 Switch Low state

#define PCB_D0_HOTPLUG(x)                       {\
                                                    bD0_HPD = x;                    \
                                                }

#define bD1_HPD                                 (MCU_PORT_PB3_PIN_REG_FF8C) // Pin 45, PB.3
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
#define AD_KEY1                                 (MCU_ADC1_RESULT_FF0A) // Pin 51, P6.1

sbit bPOWER_KEY                                 = P1 ^ 0; // Pin 64, P1.0
#define bMENU_KEY                               (MCU_PORTC3_PIN_REG_FFA0) // Pin 63, PC.3
#define bEXIT_KEY                               (MCU_PORT52_PIN_REG_FFC1) // Pin 96, P5.2
#define bLEFT_KEY                               (MCU_PORT74_PIN_REG_FFD3) // Pin 104, P7.4
#define bRIGHT_KEY                              (MCU_PORT57_PIN_REG_FFC6) // Pin 101, P5.7


#define PCB_ADKEY0()                            (AD_KEY0)
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (_FALSE)
#define PCB_ADKEY3()                            (_FALSE)


#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if(!bRIGHT_KEY)                                  \
                                                                    ucKeyState = ucKeyState | _RIGHT_KEY_MASK;   \
                                                                                                                 \
                                                                if(!bLEFT_KEY)                                   \
                                                                    ucKeyState = ucKeyState | _LEFT_KEY_MASK;    \
                                                                                                                 \
                                                                if(!bEXIT_KEY)                                   \
                                                                    ucKeyState = ucKeyState | _EXIT_KEY_MASK;    \
                                                                                                                 \
                                                                if(!bMENU_KEY)                                   \
                                                                    ucKeyState = ucKeyState | _MENU_KEY_MASK;    \
                                                                                                                 \
                                                                if(!bPOWER_KEY)                                  \
                                                                    ucKeyState = ucKeyState | _POWER_KEY_MASK;   \
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
#define bPANELPOWER                             (MCU_PORT64_PIN_REG_FFCB) // Pin 54, P6.4

#define _PANEL_CONTROL_ON                       0       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      1       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = x;                \
                                                }

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_PORT65_PIN_REG_FFCC) // Pin 55, P6.5

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

#endif // End of #if(_PCB_TYPE == _RL6001_QA_1A2H)

