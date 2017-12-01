#ifndef _KEYPAD_DEF_H_
#define _KEYPAD_DEF_H_

#if (CVT_DEF_KEYPAD_ADC_TYPE == KEYPAD_ADC_CVT_DEFAULT)
#define ADC_CH1_K0      		0x03 //CVT KEYPAD K0
#define ADC_CH1_K1      		0x2C //CVT KEYPAD K1        
#define ADC_CH1_K2      		0x6A //CVT KEYPAD K2 
#define ADC_CH1_K3      		0x98   
#define ADC_CH1_MAX             0xFF

#define ADC_CH2_K0      		0x03   //CVT KEYPAD K6 
#define ADC_CH2_K1      		0x2C   //CVT KEYPAD K5        
#define ADC_CH2_K2      		0x6A   //CVT KEYPAD K4 
#define ADC_CH2_K3      		0x98   //CVT KEYPAD K3    
#define ADC_CH2_MAX             0xFF
#else
#error "Please define keypad！"
#endif


//**************************************************************************//
// The keystroke algorithm takes 2 different ways
//  
//**************************************************************************//

#define ADC_CH1_L0      		((ADC_CH1_K0+ADC_CH1_K1)/2)
#define ADC_CH1_L1      		((ADC_CH1_K1+ADC_CH1_K2)/2)        
#define ADC_CH1_L2      		((ADC_CH1_K2+ADC_CH1_K3)/2) 
#define ADC_CH1_L3      		((ADC_CH1_K3+ADC_CH2_MAX)/2)   

#define ADC_CH2_L0      		((ADC_CH2_K0+ADC_CH2_K1)/2) 
#define ADC_CH2_L1      		((ADC_CH2_K1+ADC_CH2_K2)/2)       
#define ADC_CH2_L2      		((ADC_CH2_K2+ADC_CH2_K3)/2) 
#define ADC_CH2_L3      		((ADC_CH2_K3+ADC_CH2_MAX)/2)          

#endif
