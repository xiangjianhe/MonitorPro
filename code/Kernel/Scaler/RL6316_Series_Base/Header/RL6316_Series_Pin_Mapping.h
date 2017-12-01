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

#ifdef _64PIN_PIN_13

//--------------------------------------------------
// Bonded Pin Mapping Table
//--------------------------------------------------
#if(_PCB_SYS_EEPROM_IIC == _HW_IIC_64PIN_PIN_25_26)
#undef _PCB_SYS_EEPROM_IIC
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_30_31
#elif(_PCB_SYS_EEPROM_IIC == _HW_IIC_64PIN_PIN_29_30)
#undef _PCB_SYS_EEPROM_IIC
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_34_35
#endif

#define _PIN_16                                 _64PIN_PIN_13
#define _PIN_18                                 _64PIN_PIN_15        
#define _PIN_19                                 _64PIN_PIN_16       
#define _PIN_26                                 _64PIN_PIN_22        
#define _PIN_27                                 _64PIN_PIN_23        
#define _PIN_28                                 _64PIN_PIN_24               
#define _PIN_30                                 _64PIN_PIN_25        
#define _PIN_31                                 _64PIN_PIN_26        
#define _PIN_33                                 _64PIN_PIN_28        
#define _PIN_34                                 _64PIN_PIN_29        
#define _PIN_35                                 _64PIN_PIN_30               

#define _PIN_37                                 _64PIN_PIN_31        
#define _PIN_38                                 _64PIN_PIN_32           
#define _PIN_39                                 _64PIN_PIN_33        
#define _PIN_40                                 _64PIN_PIN_34        
#define _PIN_41                                 _64PIN_PIN_35        
#define _PIN_42                                 _64PIN_PIN_36        
#define _PIN_43                                 _64PIN_PIN_37
#define _PIN_44                                 _64PIN_PIN_38        
#define _PIN_76                                 _64PIN_PIN_64        

#define _PIN_6                                  _64PIN_PIN_4        
#define _PIN_7                                  _64PIN_PIN_5        
#define _PIN_9                                  _64PIN_PIN_6        
#define _PIN_10                                 _64PIN_PIN_7        
#define _PIN_11                                 _64PIN_PIN_8
#define _PIN_12                                 _64PIN_PIN_9        
#define _PIN_13                                 _64PIN_PIN_10        
#define _PIN_14                                 _64PIN_PIN_11        
#define _PIN_15                                 _64PIN_PIN_12        

#define _PIN_47                                 _64PIN_PIN_39        
#define _PIN_48                                 _64PIN_PIN_40
#define _PIN_49                                 _64PIN_PIN_41
#define _PIN_50                                 _64PIN_PIN_42
#define _PIN_51                                 _64PIN_PIN_43
#define _PIN_52                                 _64PIN_PIN_44
#define _PIN_53                                 _64PIN_PIN_45
#define _PIN_54                                 _64PIN_PIN_46
#define _PIN_55                                 _64PIN_PIN_47
#define _PIN_56                                 _64PIN_PIN_48


//--------------------------------------------------
// Not Bonded Pin
//--------------------------------------------------

#define _PIN_29                                 (0& 0x07) // Page 10-0xA7[2:0]
// 0 ~ 5 (0: P6D3i<I>, 1: P6D3o<OD>, 2: P6D3o<PP>, 3: ADCA2(8bit)<I>, 4: TEST_PIN2<O>, 5: TEST_PIN3<O>)

#define _PIN_36                                 (0 & 0x0F) // Page 10-0xAD[3:0]
// 0 ~ 9 (0: P5D3i<I>, 1: P5D3o<OD>, 2: P5D3o<PP>, 3: TCON[0]<O>, 4: CLKO <O>, 5: INT1<I>, 6: T0<I>, 7:DCLK<O>, 8: TEST_PIN2<O>, 9: TEST_PIN3<O>)

#endif // End of #ifdef _80PIN_PIN_21

