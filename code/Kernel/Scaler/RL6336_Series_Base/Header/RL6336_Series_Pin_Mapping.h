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
// ID Code      : RL6316_Series_Pin_Mapping.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#ifdef _64PIN_PIN_16

//--------------------------------------------------
// Bonded Pin Mapping Table
//--------------------------------------------------

#if(_PCB_SYS_EEPROM_IIC == _HW_IIC_64PIN_PIN_18_19)
#undef _PCB_SYS_EEPROM_IIC
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_76PIN_PIN_24_25
#elif(_PCB_SYS_EEPROM_IIC == _HW_IIC_64PIN_PIN_25_26)
#undef _PCB_SYS_EEPROM_IIC
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_76PIN_PIN_31_32
#endif

#define _PIN_21                                 _64PIN_PIN_16
#define _PIN_23                                 _64PIN_PIN_17
#define _PIN_24                                 _64PIN_PIN_18
#define _PIN_25                                 _64PIN_PIN_19
#define _PIN_26                                 _64PIN_PIN_20
#define _PIN_27                                 _64PIN_PIN_21
#define _PIN_28                                 _64PIN_PIN_22
#define _PIN_29                                 _64PIN_PIN_23
#define _PIN_30                                 _64PIN_PIN_24
#define _PIN_31                                 _64PIN_PIN_25
#define _PIN_32                                 _64PIN_PIN_26
#define _PIN_33                                 _64PIN_PIN_27
#define _PIN_34                                 _64PIN_PIN_28
#define _PIN_33_34_DDC1_to_28_29                _64PIN_PIN_27_28_DDC1_to_22_23
#define _PIN_38                                 _64PIN_PIN_32
#define _PIN_39                                 _64PIN_PIN_33
#define _PIN_40                                 _64PIN_PIN_34
#define _PIN_41                                 _64PIN_PIN_35
#define _PIN_42                                 _64PIN_PIN_36
#define _PIN_43                                 _64PIN_PIN_37
#define _PIN_44                                 _64PIN_PIN_38
#define _PIN_45                                 _64PIN_PIN_39
#define _PIN_46                                 _64PIN_PIN_40
#define _PIN_58                                 _64PIN_PIN_53
#define _PIN_59                                 _64PIN_PIN_54
#define _PIN_60                                 _64PIN_PIN_55
#define _PIN_61                                 _64PIN_PIN_56
#define _PIN_62                                 _64PIN_PIN_57
#define _PIN_63                                 _64PIN_PIN_58
#define _PIN_68                                 _64PIN_PIN_63

//--------------------------------------------------
// Not Bonded Pin
//--------------------------------------------------

#define _PIN_22                                 (1 & 0x07) // Page 10-0xA1[2:0]
// 0 ~ 4 (0: PCD4i<I>, 1: PCD4o<PP>, 2: PCD4o<OD>, 3: TEST_PIN0<O>, 4: TEST_PIN1<O>)

#define _PIN_37                                 (2 & 0x07) // Page 10-0xAE[3:0]
// 0 ~ 8 (0: PCD3i<I>, 1: PCD3o<OD>, 2: PCD3o<PP>, 3: PWM2<PP>, 
//        4: PWM2<OD>, 5: INT0<I>, 6: TCON8<O>, 7: TEST_PIN2<O>, 8:TEST_PIN3<O>)

// DDCSCL2
#define _PIN_70                                 (2 & 0x07) // Page 10-0xC0[2:0]
// 0 ~ 4 (0: P7D3i<I>, 1: P7D3o<OD>, 2: P7D3o<PP>,
//        3: TEST_PIN2<O>, 4:TEST_PIN3<O>, 5: DDC2<IO>)

// DDCSCA2
#define _PIN_71                                 (2 & 0x07) // Page 10-0xC1[2:0]
// 0 ~ 4 (0: P7D2i<I>, 1: P7D2o<OD>, 2: P7D2o<PP>,
//        3: TEST_PIN2<O>, 4:TEST_PIN3<O>, 5: DDC2<IO>)

#endif // End of #ifdef _64PIN_PIN_16
