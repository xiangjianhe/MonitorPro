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
// ID Code      : RL6297_Series_Pin_Mapping.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#ifdef _76PIN_PIN_21

#undef _LVDS_EO_CLK_MERGE
#define _LVDS_EO_CLK_MERGE                      _ENABLE

//--------------------------------------------------
// Bonded Pin Mapping Table
//--------------------------------------------------
#if(_PCB_SYS_EEPROM_IIC == _HW_IIC_76PIN_PIN_24_25)
#undef _PCB_SYS_EEPROM_IIC
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_42_43                     
#elif(_PCB_SYS_EEPROM_IIC == _HW_IIC_76PIN_PIN_31_32)
#undef _PCB_SYS_EEPROM_IIC
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_56_57
#endif

#define _PIN_39                                 _76PIN_PIN_21        
#define _PIN_40                                 _76PIN_PIN_22        
#define _PIN_41                                 _76PIN_PIN_23        
#define _PIN_42                                 _76PIN_PIN_24       
#define _PIN_43                                 _76PIN_PIN_25        
#define _PIN_50                                 _76PIN_PIN_27        
#define _PIN_51                                 _76PIN_PIN_28        
#define _PIN_52                                 _76PIN_PIN_29        
#define _PIN_55                                 _76PIN_PIN_30        
#define _PIN_56                                 _76PIN_PIN_31        
#define _PIN_57                                 _76PIN_PIN_32        
#define _PIN_58                                 _76PIN_PIN_33        
#define _PIN_59                                 _76PIN_PIN_34        
#define _PIN_63                                 _76PIN_PIN_37        
#define _PIN_64                                 _76PIN_PIN_38        
#define _PIN_74_75_76_77_78_79_80_81_82_83      _76PIN_PIN_39_40_41_42_43_44_45_46   
#define _PIN_74                                 _76PIN_PIN_39        
#define _PIN_75                                 _76PIN_PIN_40        
#define _PIN_78                                 _76PIN_PIN_41        
#define _PIN_79                                 _76PIN_PIN_42        
#define _PIN_109                                _76PIN_PIN_58        
#define _PIN_110                                _76PIN_PIN_59
#define _PIN_111                                _76PIN_PIN_60
#define _PIN_112                                _76PIN_PIN_61        
#define _PIN_113                                _76PIN_PIN_62        
#define _PIN_114                                _76PIN_PIN_63        
#define _PIN_119                                _76PIN_PIN_68        
#define _PIN_121                                _76PIN_PIN_70        
#define _PIN_122                                _76PIN_PIN_71        

//--------------------------------------------------
// Not Bonded Pin
//--------------------------------------------------

#define _PIN_31                                 (1 & 0x07) // Page 10-0xB7[7:6]
// 0 ~ 6 (0: PDD7i<I>, 1: PDD7o<PP>, 2: PDD7o<OD>, 3: TCON[6]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_32                                 (1 & 0x07) // Page 10-0xB7[5:4]
// 0 ~ 6 (0: PDD6i<I>, 1: PDD6o<PP>, 2: PDD6o<OD>, 3: TCON[7]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_33                                 (1 & 0x07) // Page 10-0xB7[3:2]
// 0 ~ 6 (0: PDD5i<I>, 1: PDD5o<PP>, 2: PDD5o<OD>, 3: TCON[8]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_34                                 (1 & 0x07) // Page 10-0xB7[1:0]
// 0 ~ 6 (0: PDD4i<I>, 1: PDD4o<PP>, 2: PDD4o<OD>, 3: TCON[9]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_35                                 (1 & 0x07) // Page 10-0xB8[7:6]
// 0 ~ 6 (0: PDD3i<I>, 1: PDD3o<PP>, 2: PDD3o<OD>, 3: TCON[0]<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_36                                 (1 & 0x07) // Page 10-0xB8[5:4]
// 0 ~ 6 (0: PDD2i<I>, 1: PDD2o<PP>, 2: PDD2o<OD>, 3: TCON[10]<O>,4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_37                                 (1 & 0x0F) // Page 10-0xB8[3:2]
// 0 ~ 8 (0: PDD1i<I>, 1: PDD1o<PP>, 2: PDD1o<OD>, 3: TCON[4]<O>, 4: FIELD <O>, 5: L_R<O>, 6: TEST_PIN0<O>, 7: TEST_PIN1<O>, 8: DUMMY<O>)

#define _P41_48_SEL                             (2 & 0x03) // Page 10-0xB9[5:4]
// 0 ~ 3 (0: Video8, 1: Audio, 2: Normal function, 3: Reserved)

// NC Pin
#define _PIN_44                                 (1 & 0x0F) // Page 10-0xA8[7:5]
// 0 ~ 9 (0: PBD4i<I>, 1: PBD4o<PP>, 2: PBD4o<OD>, 3: WS<O>, 4: SPDIF3<O>, 5: PWM5<PP>, 6: PWM5<OD>,7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>)

#define _PIN_45                                 (1 & 0x07) // Page 10-0xA1[7:6]
// 0 ~ 6 (0: PBD3i<I>, 1: PBD3o<PP>, 2: PBD3o<OD>, 3: SCK<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_46                                 (1 & 0x07) // Page 10-0xA3[7:6]
// 0 ~ 6 (0: PBD2i<I>, 1: PBD2o<PP>, 2: PBD2o<OD>, 3: MCK<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_47                                 (1 & 0x07) // Page 10-0xA6[7:6]
// 0 ~ 6 (0: PBD1i<I>, 1: PBD1o<PP>, 2: PBD1o<OD>, 3: SD0<O>, 4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_48                                 (1 & 0x07) // Page 10-0xA7[7:6]
// 0 ~ 7 (0: PBD0i<I>, 1: PBD0o<PP>, 2: PBD0o<OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>)

#define _PIN_53                                 (1 & 0x07) // Page 10-0xA5[7:6]
// 0 ~ 6 (0: P6D3i<I>, 1: P6D3o<PP>, 2: P6D3o<OD>, 3: ADCA3<I>,4: TEST_PIN0<O>, 5: TEST_PIN1<O>, 6: DUMMY<O>)

#define _PIN_54                                 (1 & 0x07) // Page 10-0xA0[1:0]
// 0 ~ 6 (0: P6D4i<I>, 1: P6D4o<PP>, 2: P6D4o<OD>, 3: PWM4<PP>, 4: PWM4<OD>,5: TEST_PIN0<O>, 6: TEST_PIN1<O>, 7: DUMMY<O>)

#define _PIN_58_59_DDC1_to_52_53                (0 & 0x01) // Page 10-0xA2[0]
// 0 ~ 1 (0: Disable, 1: Enable)

#define _PIN_65                                 (1 & 0x0F) // Page 10-0xB1[7:5]
// 0 ~ 11 (0: P1D1i<I>, 1: P1D1o<PP>, 2: P1D1o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON1<O>, 6: TCON7<O>, 7: T2EX<I>,8: WS<O>,9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>)

#define _PIN_66                                 (1 & 0x0F) // Page 10-0xA4[5:3]
// 0 ~ 10 (0: P1D2i<I>, 1: P1D2o<PP>, 2: P1D2o<OD>, 3: CLKO<O>, 4: SCK<O>, 
//        5: TCON2<O>, 6: TCON4<O>,7:TCON16<O>,8: TEST_PIN0<O>, 9: TEST_PIN1<O>, 10: DUMMY<O>)

#define _PIN_67                                 (1 & 0x0F) // Page 10-0xA4[2:0]
// 0 ~ 9 (0: P1D3i<I>, 1: P1D3o<PP>, 2: P1D3o<OD>, 3: MCK<O>, 4: TCON5<O>, 
//        5: TCON9<O>,6: TCON12<O>, 7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>)

#define _PIN_68                                 (1 & 0x0F) // Page 10-0xA7[5:3]
// 0 ~ 11 (0: P1D4i<I>, 1: P1D4o<PP>, 2: P1D4o<OD>, 3: SD0<O>, 4: TCON3<O>, 
//        5: TCON13<O>, 6: SPDIF0<O>, 7:TCON14<O>, 8:TCON15<O>,9: TEST_PIN0<O>, 10: TEST_PIN1<O>, 11: DUMMY<O>)

#define _PIN_69                                 (1 & 0x0F) // Page 10-0xA5[5:3]
// 0 ~ 11 (0: P1D5i<I>, 1: P1D5o<PP> , 2: P1D5o<OD>, 3: SD1<O>, 4: TCON3<O>, 
//        5: TCON7<O>, 6: SPDIF1<O>, 7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>, 10:IIC)

#define _PIN_70                                 (1 & 0x0F) // Page 10-0xA5[2:0]
// 0 ~ 11 (0: P1D6i<I>, 1: P1D6o<PP>, 2: P1D6o<OD>, 3: SD2<O>, 4: TCON9<O>, 
//        5: TCON11<O>, 6: SPDIF2<O>, 7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>, 10:IIC)
// IIC function needs to be selected for both pins (69 & 70)

#define _PIN_71                                 (1 & 0x0F) // Page 10-0xA7[2:0]
// 0 ~ 13 (0: P1D7i<I>, 1: P1D7o<PP>, 2: P1D7o<OD>, 3: PWM1<PP>, 4: PWM1<OD>, 
//        5: PWM5<PP>, 6: PWM5<OD>, 7: TCON8<O>,8: TCON10<O>, 9: SD3<O>, 10: SPDIF3<O>, 11: TEST_PIN0<O>, 12: TEST_PIN1<O>, 13: DUMMY<O>)

#define _PIN_72                                 (1 & 0x0F) // Page 10-0xB2[7:5]
// 0 ~ 9 (0: PCD2i<I>, 1: PCD2o<PP>, 2: PCD2o<OD>, 3:PWM3<PP>, 4: PWM3<OD>, 
//        5: TCON6<O>, 6: TCON12<O>, 7: TEST_PIN0<O>, 8: TEST_PIN1<O>, 9: DUMMY<O>)

#define _PIN_96                                 (1 & 0x07) // Page 10-0xA8[4:3]
// 0 ~ 7 (0: P5D2i<I>, 1: P5D2o<PP>, 2: P5D2o<OD>, 3: PWM0<PP>,4: PWM0<OD>, 5: TEST_PIN2<O>, 6: TEST_PIN3<O>, 7: DUMMY<O>)

#define _PIN_97                                 (1 & 0x0F) // Page 10-0xA8[2:0]
// 0 ~ 8 (0: P5D3i<I>, 1: P5D3o<PP>, 2: P5D3o<OD>, 3: PWM1<PP>, 4: PWM1<OD>, 5:TCONS0<O>,  6: TEST_PIN2<O>, 7: TEST_PIN3<O>, 8: DUMMY<O>) 

#define _PIN_98                                 (1 & 0x0F) // Page 10-0xAA[7:6]
// 0 ~ 9 (0: P5D4i<I>, 1: P5D4o<PP>, 2: P5D4o<OD>, 3: PWM2<PP>, 4: PWM2<OD>, 5: TCON13<O>, 6: TCON15<O> ,7: TEST_PIN2<O>, 8: TEST_PIN3<O>, 9: DUMMY<O>) )

#define _PIN_99                                 (1 & 0x0F) // Page 10-0xA9[5:3]
// 0 ~ 9 (0: P5D5i<I>, 1: P5D5o<PP>, 2: P5D5o<OD>, 3: PWM3<PP>, 4: PWM3<OD>, 5: TCON0<O>, 
//        6: TCON6<O>, 7: TCON11<O>, 8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 20: DUMMY<O>) ))

#define _PIN_100                                (1 & 0x1F) // Page 10-0xA9[2:0]
// 0 ~ 16 (0: P5D6i<I>, 1: P5D6o<PP>, 2: P5D6o<OD>, 3: PWM4<PP>, 4: PWM4<OD>, 5: TCONS1<O>, 
//         6: TCON3<O>, 7 :TCON12<O>, 8: Reserved, 9: DHS<O>, 10:DVS<O>, 11: DENA<O>, 
//         12: DCLK <O>, 13: Reserved <O> ,14: TEST_PIN2<O>, 15: TEST_PIN3<O>, 16: DUMMY<O>) )

#define _PIN_101                                (1 & 0x0F) // Page 10-0xAB[4:3]
// 0 ~ 12 (0: P5D7i<I>, 1: P5D7o<PP>, 2: P5D7o<OD>, 3: PWM5<PP>,4: PWM5<OD>, 5: TCON14<O>, 6: DHS<O>, 7:DVS<O>, 8: DENA<O>, 9: DCLK <O> ,10: TEST_PIN2<O>, 11: TEST_PIN3<O>, 12: DUMMY<O>) 

#define _PIN_102                                (1 & 0x0F) // Page 10-0xAA[5:3]
// 0 ~ 10 (0: P7D6i<I>, 1: P7D6o<PP>, 2: P7D6o<OD>, 3: PWM0<PP>, 4: PWM0<OD>, 
//        5: TCON10<O>, 6: SD3<O>, 7: SPDIF3<O>,8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 10: DUMMY<O>)

#define _PIN_103                                (1 & 0x0F) // Page 10-0xAC[6:4]
// 0 ~ 10 (0: P7D5i<I>, 1: P7D5o<PP>, 2: P7D5o<OD>, 3: PWM1<PP>, 4: PWM1<OD>, 
//        5: TCON8<O>, 6: SD2<O>, 7: SPDIF2<O>,8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 10: DUMMY<O>, 11: IIC, 12:IIC_AUX) 

#define _PIN_104                                (1 & 0x0F) // Page 10-0xAC[3:1]
// 0 ~ 9 (0: P7D4i<I>, 1: P7D4o<PP>, 2: P7D4o<OD>, 3: SD1<O>, 4: IRQB<O>, 
//        5: TCON5<O>, 6: SPDIF1<O>,7: TEST_PIN2<O>, 8: TEST_PIN3<O>, 9: DUMMY<O>, 10: IIC, 11:IIC_AUX) 
// IIC function needs to be selected for both pins (103 & 104)

#define _PIN_105                                (1 & 0x0F) // Page 10-0xAA[2:0]
// 0 ~ 10 (0: P8D0i<I>, 1: P8D0o<PP>, 2: P8D0o<OD>, 3: TCON9<O>, 4: SD0<O>, 
//         5: SPDIF0<O>, 6: Reserved, 7: TCON6<O>, 8: TEST_PIN2<O>, 9: TEST_PIN3<O>, 10: DUMMY<O>) 

#define _PIN_108                                (1 & 0x0F) // Page 10-0xAB[2:0]
// 0 ~ 11 (0: P8D1i<I>, 1: P8D1o<PP>, 2: PBD1o<OD>, 3: CLKO<O>, 4: MCK<O>, 
//         5: TCON7<O>, 6: Reserved, 7: TEST_PIN2<O>, 8: TEST_PIN3<O>, 9: DUMMY<O>) 

#define _PIN_123                                (1 & 0x07) // Page 10-0xB1[3:2]
// 0 ~ 3 (0: P7D1i<I>, 1: P7D1o<PP>, 2: P7D1o<OD>, 3: AUX_CH_N0, 4: TEST_PIN2<O>, 5: TEST_PIN3<O>, 6: DUMMY<O>, 7:DDCSCL2) 

#define _PIN_124                                (1 & 0x07) // Page 10-0xB1[1:0]
// 0 ~ 3 (0: P7D0i<I>, 1: P7D0o<PP>, 2: P7D0o<PP>, 3: AUX_CH_P0, 4: TEST_PIN2<O>, 5: TEST_PIN3<O>, 6: DUMMY<O>, 7:DDCSDA2) 
// DDC2 function needs to be selected for both pins (123 & 124)

#define _PIN_126                                (1 & 0x0F) // Page 10-0xA1[2:0]
// 0 ~ 6 (0: PCD0i<I>, 1: PCD0o<PP>, 2: PCD0o<OD>, 3: PWMO<PP>, 4: PWMO<OD>, 5: PWM1<PP>, 6: PWM1<OD>,
//        7: TCON14<O> ,8: SPDIF2<O>, 5: CEC<IO>, 6: TEST_PIN2<O>, 7: TEST_PIN3<O>, 8: DUMMY<O>) 

#endif // End of #ifdef _76PIN_PIN_21

