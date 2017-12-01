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

#if(_PCB_TYPE == _PCB_TPV_715G4032_6096_AD)

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
#define _D1_DDC_CHANNEL_SEL                     _DDC2
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
#if(_PANEL_TYPE == _TPV_SEC_LTM190BT07)
#define _LVDS_DATA_DRIV_CONTROL                 _LVDS_DRIV_CONTROL_3_0
#define _LVDS_CLK_DRIV_CONTROL                  _LVDS_DRIV_CONTROL_3_0    
#elif((_PANEL_TYPE == _TPV_LG_LM230WF5_TLF1) || (_PANEL_TYPE == _TPV_LG_LM230WF5_TLH1))
#define _LVDS_DATA_DRIV_CONTROL                 _LVDS_DRIV_CONTROL_3_5
#define _LVDS_CLK_DRIV_CONTROL                  _LVDS_DRIV_CONTROL_3_5    
#else
#define _LVDS_DATA_DRIV_CONTROL                 _LVDS_DRIV_CONTROL_2_5                  
#define _LVDS_CLK_DRIV_CONTROL                  _LVDS_DRIV_CONTROL_2_5                   
#endif
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_3
#define _LVDS_CAP_CONTROL                       _ENABLE

//--------------------------------------------------
// System Data Storage Options
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16               
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_56_57
      
//-------------------------------------------------
// Hardware IIC Options
//-------------------------------------------------
#define _SW_IIC_SUPPORT                         _ON
#define _SW_IIC_CLK_DIV                         _DIV_1                           

#define _HW_IIC_SUPPORT                         _ON
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K

//--------------------------------------------------
// Definitions for PWM Setting
//--------------------------------------------------
#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _ON
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

#define _PWM0_RST_BY_DVS                        _OFF
#define _PWM1_RST_BY_DVS                        _ON
#define _PWM2_RST_BY_DVS                        _OFF
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _OFF
#define _PWM5_RST_BY_DVS                        _OFF

#define _BACKLIGHT_PWM                          _PWM1
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

// VGA_CABLE_DET
#define _PIN_31                                 (0 & 0x03)  //0 ~ 3 (0: PDD7i, 1: PDD7o<push-pull>, 2:PDD7o<open-drain>, 3:reserved)
#define _PIN_32                                 (0 & 0x03) // Page 10-0xB7[5:4]
// 0 ~ 3 (0: PDD6i<I>, 1: PDD6o<PP>, 2: PDD6o<OD>, 3: Reserved)
#define _PIN_33                                 (0 & 0x03)  //0 ~ 3 (0: PDD5i, 1: PDD5o<push-pull>, 2:PDD5o<open-drain>, 3:reserved)
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
// 0 ~ 3 (0: PCD4i<I>, 1: PCD4o<PP>, 2: PCD4o<OD>, 3: VCLK)

// NC Pin
#define _PIN_41                                 (0 & 0x03) // Page 10-0xA0[7:6]
// 0 ~ 3 (0: PBD7i<I>, 1: PBD7o<OD>, 2: PBD7o<PP>, 3: TCON5<O>)

// Line In
#define _PIN_42                                 (0 & 0x03) // Page 10-0xA0[5:4]
// 0 ~ 3 (0: PBD6i<I>, 1: PBD6o<OD>, 2: PBD6o<PP>, 3: IICSCL<OD>)

// bLED1
#define _PIN_43                                 (0 & 0x03) // Page 10-0xA0[3:2]
// 0 ~ 3 (0: PBD5i<I>, 1: PBD5o<OD>, 2: PBD5o<PP>, 3: IICSDA<OD>)

// bLED2
#define _PIN_44                                 (0 & 0x07) // Page 10-0xA8[7:5]
// 0 ~ 4 (0: PBD4i<I>, 1: PBD4o<OD>, 2: PBD4o<PP>, 3: Reserved, 4: Reserved, 7: TCON3)

// Speaker Out
#define _PIN_45                                 (0 & 0x03) // Page 10-0xA1[7:6]
// 0 ~ 3 (0: PBD3i<I>, 1: PBD3o<OD>, 2: PBD3o<PP>, 3: Reserved)

//DVI HPD
#define _PIN_46                                 (1 & 0x03) // Page 10-0xA3[7:6]
// 0 ~ 3 (0: PBD2i<I>, 1: PBD2o<OD>, 2: PBD2o<PP>, 3: Reserved)

// EEPROM WP
#define _PIN_47                                 (1 & 0x03) // Page 10-0xA6[7:6]
// 0 ~ 3 (0: PBD1i<I>, 1: PBD1o<OD>, 2: PBD1o<PP>, 3: Reserved)
//Audio Pin(NC)
#define _PIN_48                                 (0 & 0x03) // Page 10-0xA7[7:6]
// 0 ~ 3 (0: PBD0i<I>, 1: PBD0o<OD>, 2: PBD0o<PP>, 3: PWM0<PP>)

// NC Pin
#define _PIN_50                                 (0 & 0x07) // Page 10-0xAB[7:5]
// 0 ~ 5 (0: P6D0i<I>, 1: P6D0o<OD>, 2: P6D0o<PP>, 3: ADCA0<I>, 4: Reserved,
//        5: VCLK<I>)

// KEY1
#define _PIN_51                                 (3 & 0x03) // Page 10-0xA3[5:4]
// 0 ~ 3 (0: P6D1i<I>, 1: P6D1o<OD>, 2: P6D1o<PP>, 3: ADCA1<I>)

// KEY0
#define _PIN_52                                 (3 & 0x03) // Page 10-0xA4[7:6]
// 0 ~ 3 (0: P6D2i<I>, 1: P6D2o<OD>, 2: P6D2o<PP>, 3: ADCA2<I>)

// SOG_DT
#define _PIN_53                                 (3 & 0x03) // Page 10-0xA5[7:6]
// 0 ~ 3 (0: P6D3i<I>, 1: P6D3o<OD>, 2: P6D3o<PP>, 3: ADCA3<I>)

// EDID_WP
#define _PIN_54                                 (1 & 0x03) // Page 10-0xA0[1:0]
// 0 ~ 3 (0: P6D4i<I>, 1: P6D4o<OD>, 2: P6D4o<PP>, 3: TCON7)

// Panel On
#define _PIN_55                                 (0 & 0x07) // Page 10-0xA6[5:3]
// 0 ~ 7 (0: P6D5i<I>, 1: P6D5o<OD>, 2: P6D5o<PP>, 3: PWM1<OD>, 4: PWM1<PP>, 
//        5: PWM5<PP>, 6: TCON0<O>, 7: TCON5<O>)

// EESCL
#define _PIN_56                                 (1 & 0x07) // Page 10-0xAF[6:4]
// 0 ~ 5 (0: P6D6i<I>, 1: P6D6o<OD>, 2: P6D6o<PP>, 3: Reserved, 4: TCON1<O>, 
//        5: TCON4<O>, 6: IICSCL<OD>)

// EESDA
#define _PIN_57                                 (1 & 0x07) // Page 10-0xAF[3:1]
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

//Panel power
#define _PIN_64                                 (2 & 0x0F) // Page 10-0xA3[3:0]
// 0 ~ 10(0: P1D0i<I>, 1: P1D0o<OD>, 2: P1D0o<PP>, 3: T2<I>, 4: SD0<O>,
//        5: SPDIF0<O>, 6: TCON0<O>, 7: PWM0<PP>, 8: TCON7<O>, 9: PWM0<OD>,
//        10: INT1<I>, 15: DPLL Output Test Mode)

// IIS_WS
#define _PIN_65                                 (0 & 0x07) // Page 10-0xB1[7:5]
// 0 ~ 7 (0: P1D1i<I>, 1: P1D1o<PP>, 2: PWM1<PP>, 3: T2EX<I>, 4: TCON1<O>,
//        5: TCON7<O>, 6: WS<O>, 7: PWM1<OD>)

// IIS_SCK
#define _PIN_66                                 (0 & 0x07) // Page 10-0xA4[5:3]
// 0 ~ 6 (0: P1D2i<I>, 1: P1D2o<PP>, 2: P1D2o<OD>, 3: CLKO<O>, 4: SCK<O>, 
//        5: TCON2<O>, 6: TCON4<O>)

// IIS_MCK
#define _PIN_67                                 (0 & 0x07) // Page 10-0xA4[2:0]
// 0 ~ 5 (0: P1D3i<I>, 1: P1D3o<PP>, 2: P1D3o<OD>, 3: MCK<O>, 4: TCON5<O>, 
//        5: TCON9<O>)

// IIS SD0
#define _PIN_68                                 (0 & 0x07) // Page 10-0xA7[5:3]
// 0 ~ 6 (0: P1D4i<I>, 1: P1D4o<PP>, 2: P1D4o<OD>, 3: Reserved, 4: TCON3<O>, 
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
#define _PIN_103                                (3 & 0x07) // Page 10-0xAC[6:4]
// 0 ~ 7 (0: P7D5i<I>, 1: P7D5o<PP>, 2: Reserved, 3: PWM1<PP>, 4: Reserved, 
//        5: Reserved, 6: TCON8<O>, 7: IICSCL<OD>)

//Backlight Power
#define _PIN_104                                (1 & 0x07) // Page 10-0xAC[3:1]
// 0 ~ 7 (0: P7D4i<I>, 1: P7D4o<PP>, 2: P7D4o<OD>, 3: Reserved, 4: IRQB<O>, 
//        5: TCON5<O>, 6: Reserved, 7: IICSDA<OD>)
// IIC function needs to be selected for both pins (103 & 104)

// NC
#define _PIN_105                                (0 & 0x07) // Page 10-0xAA[2:0]
// 0 ~ 6 (0: P8D0i<I>, 1: P8D0o<PP>, 2: Reserved, 3: TCON9<O>, 4: Reserved, 
//        5: Reserved)

// FLASH_WP
#define _PIN_108                                (1 & 0x07) // Page 10-0xAB[2:0]
// 0 ~ 6 (0: P8D1i<I>, 1: P8D1o<PP>, 2: Reserved, 3: CLKO<O>, 4: Reserved, 
//        5: TCON7<O>)

// NC
#define _PIN_109                                (0 & 0x07) // Page 10-0xAD[6:4]
// 0 ~ 6 (0: P3D2i<I>, 1: P3D2o<PP>, 2: Reserved, 3 INT0<I>, 4: TCON3<O>, 
//        5: Reserved)

// POWER KEY
#define _PIN_110                                (0 & 0x07) // Page 10-0xAD[2:0]
// 0 ~ 7 (0: P3D3i<I>, 1: P3D3o<OD>, 2: P3D3o<PP>, 3: INT1<I>, 4: TCON6<O>, 
//        5: Reserved, 6: TCON2<O>, 7: TCON7<O>)
// AUDIO MUTE(NC)
#define _PIN_111                                (0 & 0x07) // Page 10-0xAE[6:4]
// 0 ~ 7 (0: P3D4i<I>, 1: P3D4o<OD>, 2: P3D4o<PP>, 3: T0<I>, 4: TCON4<O>, 
//        5: Reserved, 6: Reserved, 7: TCON7<O>)
// DET_DVI5V
#define _PIN_112                                (0 & 0x07) // Page 10-0xAE[2:0]
// 0 ~ 7 (0: P3D5i<I>, 1: P3D5o<OD>, 2: P3D5o<PP>, 3: T1<I>, 4: TCON9<O>, 
//        5: Reserved, 6: Reserved, 7: TCON5<O>)
// DET_VGA5V
#define _PIN_113                                (0 & 0x07) // Page 10-0xB0[7:5]
// 0 ~ 7 (0: P3D6i<I>, 1: P3D6o<OD>, 2: P3D6o<PP>, 3: TCON1<O>, 4: Reserved, 
//        5: Reserved, 6: Reserved, 7:TCON11<O>)
// NC
#define _PIN_114                                (0 & 0x07) // Page 10-0xB2[4:2]
// 0 ~ 7 (0: P3D7i<I>, 1: P3D7o<OD>, 2: P3D7o<PP>, 3: TCON13<O>,4: Reserved, 
//        5: Reserved, 6: PWM4<PP>, 7:TCON0<O>)

// V33P
#define _PIN_119                                (1 & 0x07) // Page 10-0xA1[5:3]
// 0 ~ 5 (0: Reserved, 1: PCD1o<OD>, 2: PCD1o<PP>, 3: PWM5<PP>,4: Reserved, 
//        5: PWM5<OD>)

// DDCSCL3
#define _PIN_121                                (2 & 0x07) // Page 10-0xB0[3:2]
// 0 ~ 3 (0: P7D3i<I>, 1: P7D3o<OD>, 2: P7D3o<PP>, 3: Reserved, 4: DDCSCL3<OD>)
// DDCSDA3
#define _PIN_122                                (0 & 0x07) // Page 10-0xB0[1:0]
// 0 ~ 3 (0: P7D2i<I>, 1: P7D2o<OD>, 2: P7D2o<PP>, 3: Reserved, 4: DDCSDA3<OD>)
// DDC3 function needs to be selected for both pins (121 & 122)

// DDCSCL2
#define _PIN_123                                (4 & 0x07) // Page 10-0xB1[3:2]
// 0 ~ 3 (0: P7D1i<I>, 1: P7D1o<OD>, 2: P7D1o<PP>, 3: Reserved, 4: DDCSCL2<OD>)
// DDCSDA2
#define _PIN_124                                (4 & 0x07) // Page 10-0xB1[1:0]
// 0 ~ 3 (0: P7D0i<I>, 1: P7D0o<OD>, 2: P7D0o<PP>, 3: Reserved, 4: DDCSDA2<OD>)
// DDC2 function needs to be selected for both pins (123 & 124)

// LED1 Green
#define _PIN_126                                (2 & 0x07) // Page 10-0xA1[2:0]  //sally120523
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
sbit bDDC1IICSCL                                = P3^0;                   // Pin 58
sbit bDDC1IICSDA                                = P3^1;                   // Pin 59
#define bDDC2IICSCL                             (MCU_PORT70_PIN_REG_FFCF) // Pin 124
#define bDDC2IICSDA                             (MCU_PORT71_PIN_REG_FFD0) // Pin 123
//#define bDDC3IICSDA                             ()
//#define bDDC3IICSCL                             ()
//#define bPANELI2CSDA                            ()
//#define bPANELI2CSCL                            ()

#define PCB_SW_IIC_SDA_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          \
                                                        bSWIIC_SYS_EEPROM_SDA = _TRUE;         \
                                                    }                                          \
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)   \
													{										   \
														bDDC1IICSDA = _TRUE;		   		   \
													}										   \
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC2)   \
													{										   \
														bDDC2IICSDA = _TRUE;		   		   \
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
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC2)	\
													{										   \
														bDDC2IICSDA = _FALSE;				   \
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
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC2)	\
													{										   \
														x = bDDC2IICSDA;						\
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
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC2)	\
													{										   \
														bDDC2IICSCL = _TRUE;				   \
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
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC2)	\
													{										   \
														bDDC2IICSCL = _FALSE;				   \
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
													else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC2)	\
													{										   \
														x = bDDC2IICSCL;				   		\
													}										   \
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
#define bEEPROM_WRITE_PROTECT                   (MCU_PORT_PB1_PIN_REG_FF8E) // Pin_47

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
/*
sbit bA0_CONNECT                                =P3^6;
sbit bD1_CONNECT                                =P3^5;

#define PCB_A0_PIN()                            (SET_A0_CABLE_STATUS(!bA0_CONNECT))
#define PCB_D1_PIN()                            (SET_D1_CABLE_STATUS(!bD1_CONNECT))
*/
#define AD_CABLE_DETECT                         (MCU_ADC3_RESULT_FF0C)          //A-ADC3
//VGA_ON     VALUE = 0x81;
//DVI_ON     VALUE = 0xA3;
//VGA&DVI_ON VALUE = 0x64;
// 0.01294
#define _VGA_CONNECT_UP_BOUND                   0x8E// 1.83  
#define _VGA_CONNECT_LOW_BOUND                  0x72// 1.47
#define _DVI_CONNECT_UP_BOUND                   0xB4// 2.34
#define _DVI_CONNECT_LOW_BOUND                  0x92// 1.89
#define _VGA_DVI_CONNECT_UP_BOUND               0x6E// 1.43
#define _VGA_DVI_CONNECT_LOW_BOUND              0x58// 1.14


#define PCB_D1_PIN()                            ;//(MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_A0_PIN(){\
                        BYTE ucConnectAdcValue = 0;\
                        ScalerTimerDelayXms(1);\
                        ucConnectAdcValue = AD_CABLE_DETECT;\
                        ScalerTimerDelayXms(1);\
                        if(abs(AD_CABLE_DETECT - ucConnectAdcValue) < 12)\
                        {\
                            if((ucConnectAdcValue >= _VGA_DVI_CONNECT_LOW_BOUND) && (ucConnectAdcValue <= _VGA_DVI_CONNECT_UP_BOUND))\
                            {\
                                SET_A0_CABLE_STATUS(_TRUE);\
                                SET_D1_CABLE_STATUS(_TRUE);\             
                            }\        
                            else if((ucConnectAdcValue >= _VGA_CONNECT_LOW_BOUND) && (ucConnectAdcValue <= _VGA_CONNECT_UP_BOUND))\
                            {\
                                SET_A0_CABLE_STATUS(_TRUE);\
                                SET_D1_CABLE_STATUS(_FALSE);\    
                            }\
                            else if((ucConnectAdcValue >= _DVI_CONNECT_LOW_BOUND) && (ucConnectAdcValue <= _DVI_CONNECT_UP_BOUND))\
                            {\
                                SET_D1_CABLE_STATUS(_TRUE);\
                                SET_A0_CABLE_STATUS(_FALSE);\            
                            }\
                            else\
                            {\
                                SET_A0_CABLE_STATUS(_FALSE);\
                                SET_D1_CABLE_STATUS(_FALSE);\             
                            }\               
                        }\
                    }

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD1_HPD                                 (MCU_PORT_PB2_PIN_REG_FF8D)
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
#if((_PROJECT == _PRJ_L_LT2252W_AD_CMI_M220ZGE)||(_PROJECT == _PRJ_L_LT2252W_AD_SEC_LTM220MT09)||(_PROJECT == _PRJ_L_LS2013_AD))
//LT2252W
#define bLED2                                   (MCU_PORTC0_PIN_REG_FFA3) // pin_126  //PC.0
#define bLED1                                   (MCU_PORT73_PIN_REG_FFD2)       // Pin 121
#else
//LT1913P
#define bLED1                                   (MCU_PORTC0_PIN_REG_FFA3) // pin_126  //PC.0
#define bLED2                                   (MCU_PORT73_PIN_REG_FFD2)       // Pin 121
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
// Must Check Wether _LOW_SPEED_ADC_SUPPORT is Supported
#define _AD_KEY_SUPPORT                         _ON

#define AD_KEY2                                 (MCU_ADC2_RESULT_FF0B)
#define AD_KEY1                                 (MCU_ADC1_RESULT_FF0A)
sbit IO_PowerKey                                =P3 ^ 3;                        // Pin 110

#define PCB_ADKEY0()                            (_FALSE)
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)
#define PCB_ADKEY3()                            (_FALSE)


#if((_PROJECT == _PRJ_L_LT2252W_AD_CMI_M220ZGE)||(_PROJECT == _PRJ_L_LT2252W_AD_SEC_LTM220MT09))
//LT2252W
//Exit:  [0x0A]=0x81 KEY3
//Right: [0x0A]=0x6F KEY5
//Menu:  [0x0B]=0x81 KEY4
//Left:  [0x0B]=0x70 KEY2
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x60 <= ucV1) && (ucV1 < 0x78))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x79 <= ucV1) && (ucV1 < 0x88))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;     \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x60 <= ucV2) && (ucV2 < 0x78))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if((0x79 <= ucV2) && (ucV2 < 0x88))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                            }
#elif (_PROJECT == _PRJ_L_LS2013_AD)
//Exit:  [0x0A]=0x33 KEY1
//Left:  [0x0A]=0x70 KEY2
//Right: [0x0B]=0x33 KEY3
//Menu:  [0x0B]=0x6F KEY4

#if 0//Robert Wang test for a while(KEY:715G4407)
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x60 <= ucV1) && (ucV1 < 0x75))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if((0x78 <= ucV1) && (ucV1 < 0x90))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x60 <= ucV2) && (ucV2 < 0x75))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x78 <= ucV2) && (ucV2 < 0x90))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;     \
                                                            }

#else

#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x2B <= ucV1) && (ucV1 < 0x3B))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x68 <= ucV1) && (ucV1 < 0x78))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x2B <= ucV2) && (ucV2 < 0x3B))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;     \
                                                                                                       \
                                                                if((0x68 <= ucV2) && (ucV2 < 0x78))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                            }
#endif

#elif (_PROJECT == _PRJ_L_LT2013W_AD)
//Exit:  [0x0A]=0x70 KEY1
//Left:  [0x0B]=0x70 KEY2
//Right: [0x0B]=0x82 KEY3
//Menu:  [0x0A]=0x82 KEY4
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x67 <= ucV1) && (ucV1 < 0x78))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x7A <= ucV1) && (ucV1 < 0x8A))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x67 <= ucV2) && (ucV2 < 0x78))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x7A <= ucV2) && (ucV2 < 0x8A))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;     \
                                                            }

#elif ((_PROJECT == _PRJ_L_E2323S_AD_LG_LM230WF5_TLF1) || (_PROJECT == _PRJ_L_E2323S_AD_LG_LM230WF5_TLH1))//G6442
//Exit:  [0x0B]=?? KEY1
//Left:  [0x0A]=?? KEY2
//Right: [0x0B]=?? KEY3
//Menu:  [0x0A]=?? KEY4
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x20 <= ucV2) && (ucV2 < 0x5B))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x20 <= ucV1) && (ucV1 < 0x5B))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;      \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x5f <= ucV1) && (ucV1 < 0x8f))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x5f <= ucV2) && (ucV2 < 0x8f))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;    \
                                                            }

#else
//LT1913P
//Exit:  [0x0A]=0x6F _EXIT_KEY_MASK
//Right: [0x0A]=0x81 _MENU_KEY_MASK 
//Menu:  [0x0B]=0x6F _RIGHT_KEY_MASK
//Left:  [0x0B]=0x81 _LEFT_KEY_MASK
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((0x60 <= ucV1) && (ucV1 < 0x75))    \
                                                                    ucKeyState |= _EXIT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x78 <= ucV1) && (ucV1 < 0x90))    \
                                                                    ucKeyState |= _MENU_KEY_MASK;      \
                                                                                                       \
                                                                if(0x00 == IO_PowerKey)                \
                                                                    ucKeyState |= _POWER_KEY_MASK;     \
                                                                                                       \
                                                                if((0x60 <= ucV2) && (ucV2 < 0x75))    \
                                                                    ucKeyState |= _LEFT_KEY_MASK;      \
                                                                                                       \
                                                                if((0x78 <= ucV2) && (ucV2 < 0x90))    \
                                                                    ucKeyState |= _RIGHT_KEY_MASK;     \
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
sbit bPANELPOWER                                = P1 ^ 0;                       // Pin 64

#define _PANEL_CONTROL_ON                       1       // Power on  state for LCD panel
#define _PANEL_CONTROL_OFF                      0       // Power off state for LCD panel

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = x;                \
                                                }

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_PORT74_PIN_REG_FFD3)       // Pin 104

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

//-----------------------------------------------
#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_PWM1H_DUT_FF4B = x;         \
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 ;

//-----------------------------------------------
// Macro of Power Board Low Power Pin High/Lows
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

#endif // End of #if(_PCB_TYPE == _RTD2382D_DEMO_PCB)
