/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6096_Series_Pin_Mapping.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#ifdef _80PIN_PIN_22

#undef _LVDS_EO_CLK_MERGE
#define _LVDS_EO_CLK_MERGE                      _ENABLE

//--------------------------------------------------
// Bonded Pin Mapping Table
//--------------------------------------------------
#if(_PCB_SYS_EEPROM_IIC == _HW_IIC_80PIN_PIN_25_26)
#undef _PCB_SYS_EEPROM_IIC
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_42_43                     
#elif(_PCB_SYS_EEPROM_IIC == _HW_IIC_80PIN_PIN_32_33)
#undef _PCB_SYS_EEPROM_IIC
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_56_57
#endif

#define _PIN_39                                 _80PIN_PIN_22        
#define _PIN_40                                 _80PIN_PIN_23        
#define _PIN_41                                 _80PIN_PIN_24        
#define _PIN_42                                 _80PIN_PIN_25        
#define _PIN_43                                 _80PIN_PIN_26        
#define _PIN_48                                 _80PIN_PIN_27        
#define _PIN_51                                 _80PIN_PIN_28        
#define _PIN_52                                 _80PIN_PIN_29        
#define _PIN_53                                 _80PIN_PIN_30        
#define _PIN_55                                 _80PIN_PIN_31        
#define _PIN_56                                 _80PIN_PIN_32        
#define _PIN_57                                 _80PIN_PIN_33        
#define _PIN_58                                 _80PIN_PIN_34        
#define _PIN_59                                 _80PIN_PIN_35        

#define _PIN_58_59_DDC1_to_52_53                _80PIN_PIN_34_35_DDC1_to_29_30

#define _PIN_63                                 _80PIN_PIN_39        
#define _PIN_64                                 _80PIN_PIN_40        
#define _PIN_74_75_76_77_78_79_80_81_82_83      _80PIN_PIN_41_42_43_44_45_46_47_48    
#define _PIN_74                                 _80PIN_PIN_41        
#define _PIN_75                                 _80PIN_PIN_42        
#define _PIN_78                                 _80PIN_PIN_43        
#define _PIN_79                                 _80PIN_PIN_44        
#define _PIN_103                                _80PIN_PIN_59
#define _PIN_108                                _80PIN_PIN_62        
#define _PIN_109                                _80PIN_PIN_63        
#define _PIN_110_111_112_113_114_MIRROR         _80PIN_PIN_64_65_66_67_MIRROR
#define _PIN_110                                _80PIN_PIN_64        
#define _PIN_112                                _80PIN_PIN_65        
#define _PIN_113                                _80PIN_PIN_66        
#define _PIN_114                                _80PIN_PIN_67        
#define _PIN_119                                _80PIN_PIN_72        
#define _PIN_121                                _80PIN_PIN_74        
#define _PIN_122                                _80PIN_PIN_75        

//--------------------------------------------------
// Not Bonded Pin
//--------------------------------------------------

#define _PIN_31                                 (1 & 0x03) // Page 10-0xB7[7:6]
// 0 ~ 3 (0: PDD7i<I>, 1: PDD7o<PP>, 2: PDD7o<OD>, 3: Reserved)

#define _PIN_32                                 (1 & 0x03) // Page 10-0xB7[5:4]
// 0 ~ 3 (0: PDD6i<I>, 1: PDD6o<PP>, 2: PDD6o<OD>, 3: Reserved)

#define _PIN_33                                 (1 & 0x03) // Page 10-0xB7[3:2]
// 0 ~ 3 (0: PDD5i<I>, 1: PDD5o<PP>, 2: PDD5o<OD>, 3: Reserved)

#define _PIN_34                                 (1 & 0x03) // Page 10-0xB7[1:0]
// 0 ~ 3 (0: PDD4i<I>, 1: PDD4o<PP>, 2: PDD4o<OD>, 3: Reserved)

#define _PIN_35                                 (1 & 0x03) // Page 10-0xB8[7:6]
// 0 ~ 3 (0: PDD3i<I>, 1: PDD3o<PP>, 2: PDD3o<OD>, 3: Reserved)

#define _PIN_36                                 (1 & 0x03) // Page 10-0xB8[5:4]
// 0 ~ 3 (0: PDD2i<I>, 1: PDD2o<PP>, 2: PDD2o<OD>, 3: Reserved)

#define _PIN_37                                 (1 & 0x03) // Page 10-0xB8[3:2]
// 0 ~ 3 (0: PDD1i<I>, 1: PDD1o<PP>, 2: PDD1o<OD>, 3: Reserved)

#define _PIN_44                                 (2 & 0x07) // Page 10-0xA8[7:5]
// 0 ~ 4 (0: PBD4i<I>, 1: PBD4o<OD>, 2: PBD4o<PP>, 3: Reserved, 4: Reserved, 7: TCON3)

#define _PIN_45                                 (2 & 0x03) // Page 10-0xA1[7:6]
// 0 ~ 3 (0: PBD3i<I>, 1: PBD3o<OD>, 2: PBD3o<PP>, 3: Reserved)

#define _PIN_46                                 (2 & 0x03) // Page 10-0xA3[7:6]
// 0 ~ 3 (0: PBD2i<I>, 1: PBD2o<OD>, 2: PBD2o<PP>, 3: Reserved)

#define _PIN_47                                 (2 & 0x03) // Page 10-0xA6[7:6]
// 0 ~ 3 (0: PBD1i<I>, 1: PBD1o<OD>, 2: PBD1o<PP>, 3: Reserved)

#define _PIN_50                                 (0 & 0x07) // Page 10-0xAB[7:5]
// 0 ~ 5 (0: P6D0i<I>, 1: P6D0o<OD>, 2: P6D0o<PP>, 3: ADCA0<I>, 4: Reserved,
//        5: VCLK<I>)

#define _PIN_54                                 (2 & 0x03) // Page 10-0xA0[1:0]
// 0 ~ 3 (0: P6D4i<I>, 1: P6D4o<OD>, 2: P6D4o<PP>, 3: TCON7)


#define _PIN_65                                 (1 & 0x07) // Page 10-0xB1[7:5]
// 0 ~ 7 (0: P1D1i<I>, 1: P1D1o<PP>, 2: PWM1<PP>, 3: T2EX<I>, 4: TCON1<O>,
//        5: TCON7<O>, 6: WS<O>, 7: PWM1<OD>)

#define _PIN_66                                 (1 & 0x07) // Page 10-0xA4[5:3]
// 0 ~ 6 (0: P1D2i<I>, 1: P1D2o<PP>, 2: P1D2o<OD>, 3: CLKO<O>, 4: SCK<O>, 
//        5: TCON2<O>, 6: TCON4<O>)

// IIS_MCK
#define _PIN_67                                 (1 & 0x07) // Page 10-0xA4[2:0]
// 0 ~ 5 (0: P1D3i<I>, 1: P1D3o<PP>, 2: P1D3o<OD>, 3: MCK<O>, 4: TCON5<O>, 
//        5: TCON9<O>)

#define _PIN_68                                 (1 & 0x07) // Page 10-0xA7[5:3]
// 0 ~ 6 (0: P1D4i<I>, 1: P1D4o<PP>, 2: P1D4o<OD>, 3: Reserved, 4: TCON3<O>, 
//        5: TCON13<O>, 6: Reserved)

// IIS SD1
#define _PIN_69                                 (1 & 0x07) // Page 10-0xA5[5:3]
// 0 ~ 7 (0: P1D5i<I>, 1: P1D5o<PP> , 2: Reserved, 3: Reserved, 4: TCON3<O>, 
//        5: TCON7<O>, 6: Reserved, 7: IICSCL<OD>)

// IIS SD2
#define _PIN_70                                 (1 & 0x07) // Page 10-0xA5[2:0]
// 0 ~ 7 (0: P1D6i<I>, 1: P1D6o<PP>, 2: Reserved, 3: Reserved, 4: TCON9<O>, 
//        5: TCON11<O>, 6: Reserved, 7: IICSDA<OD>)
// IIC function needs to be selected for both pins (69 & 70)

#define _PIN_71                                 (1 & 0x07) // Page 10-0xA7[2:0]
// 0 ~ 7 (0: P1D7i<I>, 1: P1D7o<PP>, 2: PWM5<PP>, 3: SD3<O>, 4: TCON8<O>, 
//        5: TCON10<O>, 6: SPDIF3<O>, 7: PWM1<PP>)

#define _PIN_72                                 (1 & 0x07) // Page 10-0xB2[7:5]
// 0 ~ 5 (0: PCD2i<I>, 1: PCD2o<PP>, 2: TCON6<O>, 3:TCON12<O>, 4: PWM3<PP>, 
//        5: PWM3<OD>)

#define _PIN_96                                 (1 & 0x03) // Page 10-0xA8[4:3]
// 0 ~ 3 (0: P5D2i<I>, 1: P5D2o<PP>, 2: DCLK<O>, 3: PWM0<PP>)

#define _PIN_97                                 (1 & 0x07) // Page 10-0xA8[2:0]
// 0 ~ 5 (0: P5D3i<I>, 1: P5D3o<PP>, 2: Reserved, 3: PWM1<PP>, 4: DVS<O>, 
//        5: PWM1<OD>)

#define _PIN_98                                 (1 & 0x03) // Page 10-0xAA[7:6]
// 0 ~ 3 (0: P5D4i<I>, 1: P5D4o<PP>, 2: Reserved, 3: PWM2<PP>)

#define _PIN_99                                 (1 & 0x07) // Page 10-0xA9[5:3]
// 0 ~ 6 (0: P5D5i<I>, 1: P5D5o<PP>, 2: Reserved, 3: PWM3<PP>, 4: TCON6<O>, 
//        5: TCON11<O> , 6: PWM3<OD>)

#define _PIN_100                                (1 & 0x07) // Page 10-0xA9[2:0]
// 0 ~ 6 (0: P5D6i<I>, 1: P5D6o<PP>, 2: Reserved, 3: PWM4<PP>, 4: TCON3<O>,
//        5: TCON12<O>, 6: PWM4<OD>)

#define _PIN_101                                (1 & 0x03) // Page 10-0xAB[4:3]
// 0 ~ 3 (0: P5D7i<I>, 1: P5D7o<PP>, 2: TCON0<O>, 3: PWM5<PP>)

#define _PIN_102                                (1 & 0x07) // Page 10-0xAA[5:3]
// 0 ~ 7 (0: P7D6i<I>, 1: P7D6o<PP>, 2: Reserved, 3: PWM0<PP>, 4: Reserved, 
//        5: Reserved, 6: TCON10<O>, 7: PWM0<OD>)

#define _PIN_104                                (1 & 0x07) // Page 10-0xAC[3:1]
// 0 ~ 7 (0: P7D4i<I>, 1: P7D4o<PP>, 2: P7D4o<OD>, 3: Reserved, 4: IRQB<O>, 
//        5: TCON5<O>, 6: Reserved, 7: IICSDA<OD>)
// IIC function needs to be selected for both pins (103 & 104)

#define _PIN_105                                (1 & 0x07) // Page 10-0xAA[2:0]
// 0 ~ 6 (0: P8D0i<I>, 1: P8D0o<PP>, 2: Reserved, 3: TCON9<O>, 4: Reserved, 
//        5: Reserved)

#define _PIN_111                                (2 & 0x07) // Page 10-0xAE[6:4]
// 0 ~ 7 (0: P3D4i<I>, 1: P3D4o<OD>, 2: P3D4o<PP>, 3: T0<I>, 4: TCON4<O>, 
//        5: Reserved, 6: Reserved, 7: TCON7<O>)

#define _PIN_123                                (2 & 0x07) // Page 10-0xB1[3:2]
// 0 ~ 3 (0: P7D1i<I>, 1: P7D1o<OD>, 2: P7D1o<PP>, 3: Reserved, 4: DDCSCL2<OD>)

#define _PIN_124                                (2 & 0x07) // Page 10-0xB1[1:0]
// 0 ~ 3 (0: P7D0i<I>, 1: P7D0o<OD>, 2: P7D0o<PP>, 3: Reserved, 4: DDCSDA2<OD>)
// DDC2 function needs to be selected for both pins (123 & 124)

#define _PIN_126                                (2 & 0x07) // Page 10-0xA1[2:0]
// 0 ~ 6 (0: PCD0i<I>, 1: PCD0o<OD>, 2: PCD0o<PP>, 3: PWM1<PP>, 4: Reserved,
//        5: Reserved, 6: PWM1<OD>)

#endif // End of #ifdef _80PIN_PIN_21

