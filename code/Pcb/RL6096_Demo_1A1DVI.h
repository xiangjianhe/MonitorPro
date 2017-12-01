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
// ID Code      : RL6096_Demo_1A1DVI.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PCB_TYPE == _RL6096_DEMO_1A1DVI)

#define _EXT_XTAL                               _XTAL14318K     


//--------------------------------------------------
// Input Port Define
//--------------------------------------------------
////////////////////////////////////////////////////////
//If _A0_INPUT_PORT_TYPE is _A0_NO_PORT               //
//Please remove the following functions from BL51 Misc//
//BANK0 --> ?CO?USERCOMMONMODESEARCH                  //
//BANK0 --> ?CO?RL6096_SERIES_AUTOFUNC                //
//BANK0 --> ?CO?RL6096_SERIES_PLL                     //
//Otherwise, if _A0_INPUT_PORT_TYPE is _A0_VGA_PORT   //
//Please add the above functions to BL51 Misc         //
////////////////////////////////////////////////////////
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _EMBEDDED_DDCRAM_A0_SIZE                _EDID_SIZE_NONE
#define _EMBEDDED_DDCRAM_A0_LOCATION            _EDID_TABLE_LOCATION_CODE

#define _D1_INPUT_PORT_TYPE                     _D1_DVI_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC3
#define _EMBEDDED_DDCRAM_D1_SIZE                _EDID_SIZE_NONE
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

//--------------------------------------------------
// Definitions for LVDS EMI
//--------------------------------------------------
#define _LVDS_DATA_DRIV_CONTROL                 _LVDS_DRIV_CONTROL_2_5                  
#define _LVDS_CLK_DRIV_CONTROL                  _LVDS_DRIV_CONTROL_2_5                   

#define _LVDS_VCM_CONTROL                       _LVDS_VCM_HIGH                             
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_3
#define _LVDS_CAP_CONTROL                       _ENABLE

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

#define _BACKLIGHT_PWM                          _PWM4
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

//--------------------------------------------------
// Definitions for Low Speed ADC
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _ON

//--------------------------------------------------
// RL6001 Series Pin Share
//--------------------------------------------------
// <OD>:open-drain  <PP>:push-pull

// NC PIN
#define _PIN_31                                 (0 & 0x03) // Page 10-0xB7[7:6]
// 0 ~ 3 (0: PDD7i<I>, 1: PDD7o<PP>, 2: PDD7o<OD>, 3: Reserved)

// VGA_CABLE_DET
#define _PIN_32                                 (0 & 0x03) // Page 10-0xB7[5:4]
// 0 ~ 3 (0: PDD6i<I>, 1: PDD6o<PP>, 2: PDD6o<OD>, 3: Reserved)

// NC PIN
#define _PIN_33                                 (0 & 0x03) // Page 10-0xB7[3:2]
// 0 ~ 3 (0: PDD5i<I>, 1: PDD5o<PP>, 2: PDD5o<OD>, 3: Reserved)

#define _PIN_34                                 (0 & 0x03) // Page 10-0xB7[1:0]
// 0 ~ 3 (0: PDD4i<I>, 1: PDD4o<PP>, 2: PDD4o<OD>, 3: Reserved)

// NC PIN
#define _PIN_35                                 (0 & 0x03) // Page 10-0xB8[7:6]
// 0 ~ 3 (0: PDD3i<I>, 1: PDD3o<PP>, 2: PDD3o<OD>, 3: Reserved)
#define _PIN_36                                 (0 & 0x03) // Page 10-0xB8[5:4]
// 0 ~ 3 (0: PDD2i<I>, 1: PDD2o<PP>, 2: PDD2o<OD>, 3: Reserved)
#define _PIN_37                                 (0 & 0x03) // Page 10-0xB8[3:2]
// 0 ~ 3 (0: PDD1i<I>, 1: PDD1o<PP>, 2: PDD1o<OD>, 3: Reserved)

// Audio_SDA
#define _PIN_39                                 (0 & 0x03) // Page 10-0xB8[1:0]
// 0 ~ 3 (0: PDD0i<I>, 1: PDD0o<PP>, 2: PDD0o<OD>, 3: Reserved)

// Audio_SCL
#define _PIN_40                                 (0 & 0x03) // Page 10-0xB9[1:0]
// 0 ~ 3 (0: PCD4i<I>, 1: PCD4o<PP>, 2: PCD4o<OD>, 3: Reserved)

// NC Pin
#define _PIN_41                                 (0 & 0x03) // Page 10-0xA0[7:6]
// 0 ~ 3 (0: PBD7i<I>, 1: PBD7o<OD>, 2: PBD7o<PP>, 3: TCON5<O>)

// Line In
#define _PIN_42                                 (0 & 0x03) // Page 10-0xA0[5:4]
// 0 ~ 3 (0: PBD6i<I>, 1: PBD6o<OD>, 2: PBD6o<PP>, 3: IICSCL<OD>)

// bLED1
#define _PIN_43                                 (1 & 0x03) // Page 10-0xA0[3:2]
// 0 ~ 3 (0: PBD5i<I>, 1: PBD5o<OD>, 2: PBD5o<PP>, 3: IICSDA<OD>)

// bLED2
#define _PIN_44                                 (1 & 0x07) // Page 10-0xA8[7:5]
// 0 ~ 4 (0: PBD4i<I>, 1: PBD4o<OD>, 2: PBD4o<PP>, 3: Reserved, 4: Reserved, 7: TCON3)

// Speaker Out
#define _PIN_45                                 (0 & 0x03) // Page 10-0xA1[7:6]
// 0 ~ 3 (0: PBD3i<I>, 1: PBD3o<OD>, 2: PBD3o<PP>, 3: PWM3<OD>)
#define _PIN_46                                 (0 & 0x03) // Page 10-0xA3[7:6]
// 0 ~ 3 (0: PBD2i<I>, 1: PBD2o<OD>, 2: PBD2o<PP>, 3: Reserved)

// Head phone out
#define _PIN_47                                 (0 & 0x03) // Page 10-0xA6[7:6]
// 0 ~ 3 (0: PBD1i<I>, 1: PBD1o<OD>, 2: PBD1o<PP>, 3: PWM4<OD>)
#define _PIN_48                                 (0 & 0x03) // Page 10-0xA7[7:6]
// 0 ~ 3 (0: PBD0i<I>, 1: PBD0o<OD>, 2: PBD0o<PP>, 3: PWM0<PP>)

// V5A
#define _PIN_50                                 (0 & 0x07) // Page 10-0xAB[7:5]
// 0 ~ 5 (0: P6D0i<I>, 1: P6D0o<OD>, 2: P6D0o<PP>, 3: ADCA0<I>, 4: Reserved,
//        5: Reserved)

// KEY1
#define _PIN_51                                 (3 & 0x03) // Page 10-0xA3[5:4]
// 0 ~ 3 (0: P6D1i<I>, 1: P6D1o<OD>, 2: P6D1o<PP>, 3: ADCA1<I>)

// KEY0
#define _PIN_52                                 (3 & 0x03) // Page 10-0xA4[7:6]
// 0 ~ 3 (0: P6D2i<I>, 1: P6D2o<OD>, 2: P6D2o<PP>, 3: ADCA2<I>)

// SOG_DT
#define _PIN_53                                 (0 & 0x03) // Page 10-0xA5[7:6]
// 0 ~ 3 (0: P6D3i<I>, 1: P6D3o<OD>, 2: P6D3o<PP>, 3: ADCA3<I>)

// EDID_WP
#define _PIN_54                                 (1 & 0x03) // Page 10-0xA0[1:0]
// 0 ~ 3 (0: P6D4i<I>, 1: P6D4o<OD>, 2: P6D4o<PP>, 3: TCON7)

// Panel On
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

// NC Pin
#define _PIN_63                                 (0 & 0x07) // Page 10-0xA6[2:0]
// 0 ~ 7 (0: PCD3i<I>, 1: PCD3o<OD>, 2: PCD3o<PP>, 3: PWM2<PP> , 4: TCON1<O>, 
//        5: TCON8<O>, 6: PWM2<OD>, 7: INT0<I>)

// SYSTEM_EEPROM_WP
#define _PIN_64                                 (1 & 0x0F) // Page 10-0xA3[3:0]
// 0 ~ 10(0: P1D0i<I>, 1: P1D0o<OD>, 2: P1D0o<PP>, 3: T2<I>, 4: reserved,
//        5: reserved, 6: TCON0<O>, 7: PWM0<PP>, 8: TCON7<O>, 9: PWM0<OD>,
//        10: INT1<I>, 15: DPLL Output Test Mode)

// IIS_WS
#define _PIN_65                                 (0 & 0x07) // Page 10-0xB1[7:5]
// 0 ~ 7 (0: P1D1i<I>, 1: P1D1o<PP>, 2: PWM1<PP>, 3: T2EX<I>, 4: TCON1<O>,
//        5: TCON7<O>, 6: reserved, 7: PWM1<OD>)

// IIS_SCK
#define _PIN_66                                 (0 & 0x07) // Page 10-0xA4[5:3]
// 0 ~ 6 (0: P1D2i<I>, 1: P1D2o<PP>, 2: Reserved, 3: CLKO<O>, 4: Reserved, 
//        5: TCON2<O>, 6: TCON4<O>)

// IIS_MCK
#define _PIN_67                                 (0 & 0x07) // Page 10-0xA4[2:0]
// 0 ~ 5 (0: P1D3i<I>, 1: P1D3o<PP>, 2: Reserved, 3: Reserved, 4: TCON5<O>, 
//        5: TCON9<O>)

// IIS SD0
#define _PIN_68                                 (0 & 0x07) // Page 10-0xA7[5:3]
// 0 ~ 6 (0: P1D4i<I>, 1: P1D4o<PP>, 2: Reserved, 3: Reserved, 4: TCON3<O>, 
//        5: TCON13<O>, 6: Reserved)

// IIS SD1
#define _PIN_69                                 (0 & 0x07) // Page 10-0xA5[5:3]
// 0 ~ 7 (0: P1D5i<I>, 1: P1D5o<PP> , 2: Reserved, 3: Reserved, 4: TCON3<O>, 
//        5: TCON7<O>, 6: Reserved, 7: IICSCL<OD>)

// IIS SD2
#define _PIN_70                                 (0 & 0x07) // Page 10-0xA5[2:0]
// 0 ~ 7 (0: P1D6i<I>, 1: P1D6o<PP>, 2: Reserved, 3: Reserved, 4: TCON9<O>, 
//        5: TCON11<O>, 6: Reserved, 7: IICSDA<OD>)
// IIC function needs to be selected for both pins (69 & 70)

// IIS SD3
#define _PIN_71                                 (0 & 0x07) // Page 10-0xA7[2:0]
// 0 ~ 7 (0: P1D7i<I>, 1: P1D7o<PP>, 2: PWM5<PP>, 3: Reserved, 4: TCON8<O>, 
//        5: TCON10<O>, 6: Reserved, 7: PWM1<PP>)

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
// 0 ~ 3 (0: P9D0o<PP>, 1: Reserved, 2: Reserved, 3: Reserved)
#define _PIN_75                                 (0 & 0x03) // Page 10-0xB6[5:4]
// 0 ~ 3 (0: P9D1o<PP>, 1: Reserved, 2: Reserved, 3: Reserved)
#define _PIN_78                                 (0 & 0x03) // Page 10-0xB6[3:2]
// 0 ~ 3 (0: P9D4o<PP>, 1: Reserved, 2: Reserved, 3: Reserved)
#define _PIN_79                                 (0 & 0x03) // Page 10-0xB6[1:0]
// 0 ~ 3 (0: PAD0o<PP>, 1: Reserved, 2: Reserved, 3: Reserved)

// NC Pin
#define _PIN_96                                 (0 & 0x03) // Page 10-0xA8[4:3]
// 0 ~ 3 (0: P5D2i<I>, 1: P5D2o<PP>, 2: DCLK<O>, 3: PWM0<PP>)
#define _PIN_97                                 (0 & 0x07) // Page 10-0xA8[2:0]
// 0 ~ 5 (0: P5D3i<I>, 1: P5D3o<PP>, 2: Reserved, 3: PWM1<PP>, 4: DVS<O>, 
//        5: PWM1<OD>)
#define _PIN_98                                 (0 & 0x03) // Page 10-0xAA[7:6]
// 0 ~ 3 (0: P5D4i<I>, 1: P5D4o<PP>, 2: Reserved, 3: PWM2<PP>)
#define _PIN_99                                 (0 & 0x07) // Page 10-0xA9[5:3]
// 0 ~ 6 (0: P5D5i<I>, 1: P5D5o<PP>, 2: Reserved, 3: PWM3<PP>, 4: TCON6<O>, 
//        5: TCON11<O> , 6: PWM3<OD>)
#define _PIN_100                                (0 & 0x07) // Page 10-0xA9[2:0]
// 0 ~ 6 (0: P5D6i<I>, 1: P5D6o<PP>, 2: Reserved, 3: PWM4<PP>, 4: TCON3<O>,
//        5: TCON12<O>, 6: PWM4<OD>)
#define _PIN_101                                (0 & 0x03) // Page 10-0xAB[4:3]
// 0 ~ 3 (0: P5D7i<I>, 1: P5D7o<PP>, 2: TCON0<O>, 3: PWM5<PP>)
#define _PIN_102                                (0 & 0x07) // Page 10-0xAA[5:3]
// 0 ~ 7 (0: P7D6i<I>, 1: P7D6o<PP>, 2: Reserved, 3: PWM0<PP>, 4: Reserved, 
//        5: Reserved, 6: TCON10<O>, 7: PWM0<OD>)

// SHDN_AMP
#define _PIN_103                                (0 & 0x07) // Page 10-0xAC[6:4]
// 0 ~ 7 (0: P7D5i<I>, 1: P7D5o<PP>, 2: Reserved, 3: PWM1<PP>, 4: Reserved, 
//        5: Reserved, 6: TCON8<O>, 7: IICSCL<OD>)

// AUDIO_STB
#define _PIN_104                                (0 & 0x07) // Page 10-0xAC[3:1]
// 0 ~ 7 (0: P7D4i<I>, 1: P7D4o<PP>, 2: PWM2<PP>, 3: Reserved, 4: IRQB<O>, 
//        5: TCON5<O>, 6: Reserved, 7: IICSDA<OD>)
// IIC function needs to be selected for both pins (103 & 104)

// AUDIO_MUTE
#define _PIN_105                                (0 & 0x07) // Page 10-0xAA[2:0]
// 0 ~ 6 (0: P8D0i<I>, 1: P8D0o<PP>, 2: Reserved, 3: TCON9<O>, 4: PWM0<PP>, 
//        5: PWM0<OD>)

// FLASH_WP
#define _PIN_108                                (1 & 0x07) // Page 10-0xAB[2:0]
// 0 ~ 6 (0: P8D1i<I>, 1: P8D1o<PP>, 2: Reserved, 3: CLKO<O>, 4: Reserved, 
//        5: TCON7<O>)

// LED2
#define _PIN_109                                (0 & 0x07) // Page 10-0xAD[6:4]
// 0 ~ 6 (0: P3D2i<I>, 1: P3D2o<PP>, 2: Reserved, 3 INT0<I>, 4: TCON3<O>, 
//        5: Reserved)

// LED1
#define _PIN_110                                (0 & 0x07) // Page 10-0xAD[2:0]
// 0 ~ 7 (0: P3D3i<I>, 1: P3D3o<OD>, 2: P3D3o<PP>, 3: INT1<I>, 4: TCON6<O>, 
//        5: Reserved, 6: TCON2<O>, 7: TCON7<O>)
// DVI_HOT_PLUG
#define _PIN_111                                (1 & 0x07) // Page 10-0xAE[6:4]
// 0 ~ 7 (0: P3D4i<I>, 1: P3D4o<OD>, 2: P3D4o<PP>, 3: T0<I>, 4: TCON4<O>, 
//        5: Reserved, 6: Reserved, 7: TCON7<O>)
// DVI_CABLE_DET
#define _PIN_112                                (0 & 0x07) // Page 10-0xAE[2:0]
// 0 ~ 7 (0: P3D5i<I>, 1: P3D5o<OD>, 2: P3D5o<PP>, 3: T1<I>, 4: TCON9<O>, 
//        5: Reserved, 6: Reserved, 7: TCON5<O>)
// BL_EN
#define _PIN_113                                (1 & 0x07) // Page 10-0xB0[7:5]
// 0 ~ 7 (0: P3D6i<I>, 1: P3D6o<OD>, 2: P3D6o<PP>, 3: TCON1<O>, 4: PWM3<PP>, 
//        5: PWM3<OD>, 6: Reserved, 7:TCON11<O>)
// BL_ADJ
#define _PIN_114                                (6 & 0x07) // Page 10-0xB2[4:2]
// 0 ~ 7 (0: P3D7i<I>, 1: P3D7o<OD>, 2: P3D7o<PP>, 3: TCON13<O>,4: Reserved, 
//        5: Reserved, 6: PWM4<PP>, 7:TCON0<O>)

// V33P
#define _PIN_119                                (0 & 0x07) // Page 10-0xA1[5:3]
// 0 ~ 5 (0: Reserved, 1: PCD1o<OD>, 2: PCD1o<PP>, 3: PWM5<PP>,4: Reserved, 
//        5: PWM5<OD>)

// DDCSCL3
#define _PIN_121                                (4 & 0x07) // Page 10-0xB0[3:2]
// 0 ~ 3 (0: P7D3i<I>, 1: P7D3o<OD>, 2: P7D3o<PP>, 3: Reserved, 4: DDCSCL3<OD>)
// DDCSDA3
#define _PIN_122                                (4 & 0x07) // Page 10-0xB0[1:0]
// 0 ~ 3 (0: P7D2i<I>, 1: P7D2o<OD>, 2: P7D2o<PP>, 3: Reserved, 4: DDCSDA3<OD>)
// DDC3 function needs to be selected for both pins (121 & 122)

// DDCSDA2
#define _PIN_123                                (0 & 0x07) // Page 10-0xB1[3:2]
// 0 ~ 3 (0: P7D1i<I>, 1: P7D1o<OD>, 2: P7D1o<PP>, 3: Reserved, 4: DDCSDA2<OD>
// DDCSCL2
#define _PIN_124                                (0 & 0x07) // Page 10-0xB1[1:0]
// 0 ~ 3 (0: P7D0i<I>, 1: P7D0o<OD>, 2: P7D0o<PP>, 3: Reserved, 4: DDCSCL2<OD>)
// DDC2 function needs to be selected for both pins (123 & 124)

// NC Pin
#define _PIN_126                                (0 & 0x07) // Page 10-0xA1[2:0]
// 0 ~ 6 (0: PCD0i<I>, 1: PCD0o<OD>, 2: PCD0o<PP>, 3: PWM1<PP>, 4: Reserved,
//        5: Reserved, 6: PWM1<OD>)

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
                                                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH); \ 
                                                    PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF); \
                                                    PCB_LED_OFF(); \                                                    
                                                }

////////////////////////////////////////
// Pin39~40,50~53 Function Normal     //
// Pin41~48 Function Select to Audio  //
// Pin65~72,96~103 Normal Operation   //
////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT7, 0x00);    \
                                                    ScalerSetBit(P10_BD_PIN_PULLUP_CTRL5, ~(_BIT6 | _BIT4 | _BIT2 | _BIT0), 0x00);    \
                                                    ScalerSetBit(P10_BE_PIN_PULLUP_CTRL6, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), 0x00); \
                                                }

////////////////////////////////////////////////////////
// Pin39~40 pull up control --> GPIO Function Disable //
// Pin65~72,96~103 pull up Control                    //
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                    ScalerSetBit(P10_BD_PIN_PULLUP_CTRL5, ~(_BIT6 | _BIT4 | _BIT2 | _BIT0), _BIT6 | _BIT4 | _BIT2 | _BIT0);    \
                                                    ScalerSetBit(P10_BE_PIN_PULLUP_CTRL6, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), _BIT7 | _BIT5 | _BIT3 | _BIT1); \
                                                }

////////////////////////////////////////////////////////
// Pin50~53 pull up control --> GPIO Function Disable //
// Pin39~40 pull up control --> GPIO Function Disable //
// Pin65~72,96~103 pull up Control                    //
////////////////////////////////////////////////////////
#define PCB_GPIO_SETTING_POWER_DOWN()            {\
                                                    ScalerSetBit(P10_B5_PIN_DRIVING_CTRL3, ~_BIT7, _BIT7);    \
                                                    ScalerSetBit(P10_BD_PIN_PULLUP_CTRL5, ~(_BIT6 | _BIT4 | _BIT2 | _BIT0), _BIT6 | _BIT4 | _BIT2 | _BIT0);    \
                                                    ScalerSetBit(P10_BE_PIN_PULLUP_CTRL6, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), _BIT7 | _BIT5 | _BIT3 | _BIT1); \
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
#define bFLASH_WRITE_PROTECT                    (MCU_PORT81_PIN_REG_FFD7)   // Pin 108 P8.1

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = x;   \
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
sbit bEEPROM_WRITE_PROTECT                      = P1 ^ 0; // Pin 64, P1.0

#define _EEPROM_WP_ENABLE                       1       // WP High state for Eeprom
#define _EEPROM_WP_DISABLE                      0       // WP Low state for Eeprom

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = x;  \
                                                }

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_PORT64_PIN_REG_FFCB)    // Pin 54, P6.4

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = x;\
                                                }

#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = x;\
                                                }

//-----------------------------------------------
// Macro of Input Connect Detect
//-----------------------------------------------
#define bA0_CONNECT                             (MCU_PORT_PD6_PIN_REG_FF78) // Pin 32, PD.6
sbit bD1_CONNECT                                = P3 ^ 5; // Pin 112, P3.5

#define PCB_A0_PIN()                            (SET_A0_CABLE_STATUS(!bA0_CONNECT))
#define PCB_D1_PIN()                            (SET_D1_CABLE_STATUS(!bD1_CONNECT))

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
sbit bD1_HPD                                    = P3 ^ 4; // Pin 111, P3.4 for DVI hot plug
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
#define bLED1                                   (MCU_PORT_PB4_PIN_REG_FF8B) // Pin 44, PB.4
#define bLED2                                   (MCU_PORT_PB5_PIN_REG_FF8A) // Pin 43, PB.5

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
#define _AD_KEY_SUPPORT                         _ON

#define AD_KEY2                                 (MCU_ADC2_RESULT_FF0B)
#define AD_KEY1                                 (MCU_ADC1_RESULT_FF0A)

#define PCB_ADKEY0()                            (_FALSE)
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)
#define PCB_ADKEY3()                            (_FALSE)

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
#define bPANELPOWER                             (MCU_PORT65_PIN_REG_FFCC) //  Pin 55, P6.5

#define _PANEL_CONTROL_ON                       0       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      1       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = x;                \
                                                }

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
sbit bBACKLIGHTPOWER                            = P3 ^ 6; // Pin 113, P3.6

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

#endif // End of #if(_PCB_TYPE == _RL6096_DEMO_1A1DVI)

