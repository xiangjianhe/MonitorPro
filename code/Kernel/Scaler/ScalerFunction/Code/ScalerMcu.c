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
// ID Code      : ScalerMcu.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_MCU__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions DDCCI Protocol Items
//--------------------------------------------------
#define _DCCCI_LENGTH                       1

//--------------------------------------------------
// Definitions PWM Frequency
//--------------------------------------------------
#define _PWM_FREQ_LOW_BOUND                 16
#define _PWM_FREQ_DVSRST_BOUND              1000
#define _PWM_FREQ_UPPER_BOUND               55000

//--------------------------------------------------
// Definitions of Hardware IIC Timings
//--------------------------------------------------
#if(_HW_IIC_SPEED == _HW_IIC_LOW_SPEED_100K)
#define _HW_IIC_SLPC_14318K                 0x26 // 38
#define _HW_IIC_SHPC_14318K                 0x22 // 34
#define _HW_IIC_SLPC_27000K                 0x2A // 42
#define _HW_IIC_SHPC_27000K                 0x23 // 35
#define _HW_IIC_STA_SUGPIO_C                0x24 // 36
#define _HW_IIC_TOR                         0x47 // 71                            
#else
#define _HW_IIC_SLPC_14318K                 0x0B // 11
#define _HW_IIC_SHPC_14318K                 0x03 // 3
#define _HW_IIC_SLPC_27000K                 0x0C // 12
#define _HW_IIC_SHPC_27000K                 0x04 // 4
#define _HW_IIC_STA_SUGPIO_C                0x08 // 8
#define _HW_IIC_TOR                         0x23 // 35
#endif

#define _HW_IIC_FTPC                        0x03 // 3                        
#define _HW_IIC_FD10_14318K                 0x01 // 1
#define _HW_IIC_FD10_27000K                 0x02 // 2

//--------------------------------------------------
// Definitions of Hardware IIC
//--------------------------------------------------
#define _HW_IIC_BUFFER_SIZE                 24
#define _HW_IIC_DELAY_TIME                  5

//--------------------------------------------------
// Definitions of Software IIC
//--------------------------------------------------
#define _IIC_POLLING_TIME                   50

#if((_INSTANT_TIMER_EVENT_1 == _ON) && (_UART_SUPPORT == _ON))
#error "Instant Timer1 cannot be used when UART is supported"
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
sfr CKCON = 0x8E;

BYTE idata g_ucDdcciCountEXINT;

BYTE data g_ucDelay5usN = 1;
BYTE data g_ucDelay5usI = 1;

#if(_SW_IIC_SUPPORT == _ON)
BYTE idata g_ucSwIICStatus = 0;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerMcuInitial(void);
void ScalerMcuDdcDebounceSel(EnumClkSel enumClock);
void ScalerMcuDdcciInitial(void);
void ScalerMcuDdcciSendData(BYTE *pWriteArray);

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
void ScalerMcuDdcciReleaseScl(void);
void ScalerMcuDdcciHoldScl_EXINT1(void);
#endif 

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
BYTE ScalerMcuDdcciIntGetData_EXINT1(BYTE *pReadArray);
#endif

void ScalerMcuFlashClockDiv(EnumFlashClkDiv enumClkDiv);
void ScalerMcuClockDiv(EnumMcuClkDiv enumClkDiv);
void ScalerMcuClockSel(BYTE ucClock);

#if(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
void ScalerMcuSwitchFlashMcuFastSpeed(bit bEnable);
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
void ScalerMcuIntoIdle(void);
#endif

#if(_LOW_SPEED_ADC_SUPPORT == _ON)
void ScalerMcuSarAdcClkSel(EnumClkSel enumClock);
#endif

#if(_PWM_FUNCTION_SUPPORT == _ON)
void ScalerMcuPwmClockSel(EnumClkSel enumClock);
void ScalerMcuPwmAdjustFrequency(BYTE ucPwmType, WORD usFrequency);
#endif

void ScalerMcu5usDelayCalc(EnumClkSel enumClock);

#if(_SW_IIC_SUPPORT == _ON)
BYTE ScalerMcuIICStart(BYTE ucSlaveAddr);
void ScalerMcuIICStop(void);
BYTE ScalerMcuIICGetAck(void);
void ScalerMcuIICSendAck(void);
void ScalerMcuIICSendNoAck(void);
BYTE ScalerMcuIICGetByte(void);
BYTE ScalerMcuIICSendByte(BYTE ucValue);
bit ScalerMcuIICWriteStart(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr);
#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)
bit ScalerMcuIICWritePolling(BYTE ucSlaveAddr);
#endif
bit ScalerMcuIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE *pReadArray);
bit ScalerMcuIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE * pWriteArray);
#endif

#if(_HW_IIC_SUPPORT == _ON)
void ScalerMcuHwIICInitial(void);
void ScalerMcuHwIICSetFreqDiv(EnumClkSel enumClock);
#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)
bit ScalerMcuHwIICWritePolling(BYTE ucSlaveAddr, BYTE ucSubAddrLength, BYTE ucHwIICPinNum);
#endif
bit ScalerMcuHwIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pReadArray, BYTE ucHwIICPinNum);
bit ScalerMcuHwIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pWriteArray, BYTE ucHwIICPinNum);
#endif

#if(_UART_SUPPORT == _ON)
bit ScalerMcuUartWrite(BYTE ucValue);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//------------------------------------------------------------------------------
// MCU initial function, must be called at first
// Since code banking can not work correctly before this function is called, 
// this function should stay in bank0.
//------------------------------------------------------------------------------
void ScalerMcuInitial(void)
{
    // Clear watchdog & Set CNT1 to max
    MCU_WATCHDOG_TIMER_FFEA |= _BIT6 | _BIT2 | _BIT1 | _BIT0;

    ScalerMcuFlashClockDiv(_FLASH_CLK_IN_DIV);
    ScalerMcuClockDiv(_MCU_CLK_IN_DIV);
    ScalerMcu5usDelayCalc(_EXT_XTAL_CLK);

    ////////////////////////
    // Bankswitch Settings//
    ////////////////////////
    
    // Enable address remapping to XDATA, enable global XRAM and XFR
    // Use Pbank_switch, enable bankswitching function
    MCU_BANK_SWITCH_CTRL_FFFC |= _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0;
    
    // Select XDATA BANK start
    MCU_BANK_START_FFFD = 0x00;
    
    // Select first bank number for XDATA access
    MCU_BANK_SEL_FFFE = 0x00; // Xdata_bank_sel: Bank0
    
    //////////////////
    //TIMER SETTINGS//
    //////////////////
    // Clock Control, Timer divide by 12 clock, MOVX duration = 2 machine cycles
    CKCON &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);

    // Disable all interrupts
    IE = 0x00;

    // Stop Timer0 and Clear Flag
    TR0 = _OFF;
    TF0 = _OFF;

    // Stop Timer1 and Clear Flag
    TR1 = _OFF;
    TF1 = _OFF;

    // Stop Timer2 and Clear Flag
    TR2 = _OFF;
    TF2 = _OFF;
    TCLK = 0;
    RCLK = 0; 

#if(_UART_SUPPORT == _ON)
    // Set Timer0 to Mode1 (16bit Counter)
    // Set Timer1 to Mode2 (8bit Counter with Auto-Reload)
    TMOD = 0x21;
#else
    // Set Timer0/1 to Mode1 (16bit counter)
    TMOD = 0x11;
#endif

    // Enable Timer2 AutoReload Mode
    T2CON &= ~_BIT0;
    
    // Set Interrupt Priority for Timer2
    PT0 = 0;
    PT1 = 0;
    PT2 = 1;
    
    // Enable global interrupt
    EA = _ENABLE; 

    // Load Timer2 Count Value
    ScalerTimerSetTimerCount(_TIMER_OPERATION_INITIAL_MODE);

    // Start watchdog
    MCU_WATCHDOG_TIMER_FFEA |= _BIT7; 

    /////////////////
    //UART Settings//
    /////////////////
#if(_UART_SUPPORT == _ON)
    // Set Serial Port to Mode 1
    SM0 = 0;
    SM1 = 1;

    // SMOD0 Set to 1
    PCON |= _BIT7;
    
    // RI will be only activated if a valid stop is received
    SM2 = 1;

    // Set Serial Port Receive Enable
    REN = _ENABLE;

    // Clear Transmit and Receive Flags
    TI = 0;
    RI = 0;

    // Enable Serial Port IRQ
    ES = _ENABLE;
#endif

    /////////////////////////
    //GPIO Control Settings//
    /////////////////////////

    ScalerMcuGpioInitial();

    PCB_GPIO_INITIAL_SETTING();
    
    ////////////////
    //ISP Settings//
    ////////////////
    
    ScalerMcuIspInitial();

    ///////////////////
    // Flash Settings//
    ///////////////////

    // Set Flash fast read mode and latch Flash SO data in falling edge
    MCU_READ_INSTRUCTION_FF6C |= _BIT6 | _BIT5;
    
    ////////////////
    //PWM Settings//
    ////////////////
    
#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)
    // Select 8 bit duty width type
    MCU_PWM_DUT_TYPE_FF53 |= (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
#else
    // Select 12 bit duty width type
    MCU_PWM_DUT_TYPE_FF53 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);

    // Enable double buffer mode
    MCU_PWM_EN_FF48 |= _BIT7;
#endif

    // Enable PWM reset by DVS
    MCU_PWM_VS_CTRL_FF47 = (((BYTE)_PWM5_RST_BY_DVS << 5) | ((BYTE)_PWM4_RST_BY_DVS << 4) | ((BYTE)_PWM3_RST_BY_DVS << 3) | ((BYTE)_PWM2_RST_BY_DVS << 2) | ((BYTE)_PWM1_RST_BY_DVS << 1) | ((BYTE)_PWM0_RST_BY_DVS));

    ////////////////
    //DDC Settings//
    ////////////////

    ScalerMcuDdcInitial();

    ///////////////////
    //DDC-CI Settings//
    ///////////////////

    ScalerMcuDdcciInitial();

    ////////////////
    //IIC Settings//
    ////////////////
#if(_HW_IIC_SUPPORT == _ON)    
    ScalerMcuHwIICInitial();
#endif

    ///////////////////
    //SARADC Settings//
    ///////////////////
#if(_LOW_SPEED_ADC_SUPPORT == _ON)
    // Set Threshold for Auto Mode
    MCU_ADC0_THRESHOLD_H_FF0F = 0x00;
    MCU_ADC0_THRESHOLD_L_FF10 = 0xFF;
    MCU_ADC1_THRESHOLD_H_FF11 = 0x00; 
    MCU_ADC1_THRESHOLD_L_FF12 = 0xFF; 
    MCU_ADC2_THRESHOLD_H_FF13 = 0x00; 
    MCU_ADC2_THRESHOLD_L_FF14 = 0xFF;
    MCU_ADC3_THRESHOLD_H_FF15 = 0x00;  
    MCU_ADC3_THRESHOLD_L_FF16 = 0xFF; 

    // Set Auto Mode
    MCU_AUTO_MODE_CTRL01_FF0E |= _BIT2;

    // Set Wait Time between measure
    MCU_CTRL0_WAIT_TIME_VAL_FF17 = 0x00;

    // Set ADC bias current to 5uA
    MCU_ADC_CTRL_FF08 &= ~(_BIT2 | _BIT1);
    
    // ADC Start Scan
    MCU_ADC_CTRL_FF08 |= _BIT7;
#endif

}

//--------------------------------------------------
// Description  : DDC Debounce Settings
// Input Value  : Clock --> _EXT_XTAL_CLK/_IOSC_CLK
// Output Value : None
//--------------------------------------------------
void ScalerMcuDdcDebounceSel(EnumClkSel enumClock)
{

#if(_INTERNAL_OSC_XTAL == _IOSC14318K)
    if((enumClock == _IOSC_CLK) || (enumClock == _EXT_XTAL_CLK))
    {
        // DDC1 De-bounce Reference Clock(14.318M) div by 2, latch 3 stages 
        MCU_ADC_DDC_CTRL1_FF1C &= ~_BIT7;
        MCU_ADC_DDC_CTRL1_FF1C |= (_BIT6 | _BIT5 | _BIT4);

#if(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC2)) || ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC2)))
        // DDC2 De-bounce Reference Clock(14.318M) div by 1, latch 1 stages 
        MCU_DVI_DDC_CTRL1_FF1F &= ~(_BIT7 | _BIT6);
        MCU_DVI_DDC_CTRL1_FF1F |= _BIT4;
#elif((((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)) && (_D0_DDC_CHANNEL_SEL == _DDC2)) || (((_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) && (_D1_DDC_CHANNEL_SEL == _DDC2)))
        // DDC2 De-bounce Reference Clock(14.318M) div by 2, latch 3 stages
        MCU_DVI_DDC_CTRL1_FF1F &= ~_BIT7;
        MCU_DVI_DDC_CTRL1_FF1F |= (_BIT6 | _BIT5 | _BIT4);
#endif

#if(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC3)) || ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC3)))
        // DDC3 De-bounce Reference Clock(14.318M) div by 1, latch 1 stages
        MCU_HDMI_DDC_CTRL1_FF2D &= ~(_BIT7 | _BIT6);
        MCU_HDMI_DDC_CTRL1_FF2D |= _BIT4;
#elif((((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)) && (_D0_DDC_CHANNEL_SEL == _DDC3)) || (((_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) && (_D1_DDC_CHANNEL_SEL == _DDC3)))
        // DDC3 De-bounce Reference Clock(14.318M) div by 2, latch 3 stages
        MCU_HDMI_DDC_CTRL1_FF2D &= ~_BIT7;
        MCU_HDMI_DDC_CTRL1_FF2D |= (_BIT6 | _BIT5 | _BIT4);
#endif

    }

#else    // End of #if(_INTERNAL_OSC_XTAL == _IOSC14318K)

    if(enumClock == _EXT_XTAL_CLK)
    {
        // DDC1 De-bounce Reference Clock(Xtal = 14.318M) div by 2, latch 3 stages 
        MCU_ADC_DDC_CTRL1_FF1C &= ~_BIT7;
        MCU_ADC_DDC_CTRL1_FF1C |= (_BIT6 | _BIT5 | _BIT4);

#if(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC2)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC2)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3)))
        // DDC2 De-bounce Reference Clock(Xtal = 14.318M) div by 1, latch 1 stages 
        MCU_DVI_DDC_CTRL1_FF1F &= ~(_BIT7 | _BIT6);
        MCU_DVI_DDC_CTRL1_FF1F |= _BIT4;
#elif((((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)) && (_D0_DDC_CHANNEL_SEL == _DDC2)) || \
      (((_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) && (_D1_DDC_CHANNEL_SEL == _DDC2)) || \
      ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2)))
        // DDC2 De-bounce Reference Clock(Xtal = 14.318M) div by 2, latch 3 stages
        MCU_DVI_DDC_CTRL1_FF1F &= ~_BIT7;
        MCU_DVI_DDC_CTRL1_FF1F |= (_BIT6 | _BIT5 | _BIT4);
#endif

#if(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC3)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC3)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2)))
        // DDC3 De-bounce Reference Clock(Xtal = 14.318M) div by 1, latch 1 stages
        MCU_HDMI_DDC_CTRL1_FF2D &= ~(_BIT7 | _BIT6);
        MCU_HDMI_DDC_CTRL1_FF2D |= _BIT4;
#elif((((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)) && (_D0_DDC_CHANNEL_SEL == _DDC3)) || \
      (((_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) && (_D1_DDC_CHANNEL_SEL == _DDC3)) || \
      ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3)))

        // DDC3 De-bounce Reference Clock(Xtal = 14.318M) div by 2, latch 3 stages
        MCU_HDMI_DDC_CTRL1_FF2D &= ~_BIT7;
        MCU_HDMI_DDC_CTRL1_FF2D |= (_BIT6 | _BIT5 | _BIT4);
#endif

    }
    else
    {
        // DDC1 De-bounce Reference Clock(IOSC = 27M) div by 4, latch 3 stages 
        MCU_ADC_DDC_CTRL1_FF1C |= (_BIT7 | _BIT6 | _BIT5 | _BIT4);
        
#if(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC2)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC2)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3)))
        // DDC2 De-bounce Reference Clock(IOSC = 27M) div by 2, latch 1 stages
        MCU_DVI_DDC_CTRL1_FF1F &= ~(_BIT7);
        MCU_DVI_DDC_CTRL1_FF1F |= (_BIT6 | _BIT4);
#elif((((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)) && (_D0_DDC_CHANNEL_SEL == _DDC2)) || \
      (((_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) && (_D1_DDC_CHANNEL_SEL == _DDC2)) || \
      ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2)))
        // DDC2 De-bounce Reference Clock(IOSC = 27M) div by 4, latch 3 stages
        MCU_DVI_DDC_CTRL1_FF1F |= (_BIT7 | _BIT6 | _BIT5 | _BIT4);
#endif

#if(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC3)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC3)) || \
    ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC3_TMDSDDC2)))
        // DDC3 De-bounce Reference Clock(IOSC = 27M) div by 2, latch 1 stages
        MCU_HDMI_DDC_CTRL1_FF2D &= ~(_BIT7);
        MCU_HDMI_DDC_CTRL1_FF2D |= (_BIT6 | _BIT4);
#elif((((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)) && (_D0_DDC_CHANNEL_SEL == _DDC3)) || \
      (((_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) && (_D1_DDC_CHANNEL_SEL == _DDC3)) || \
      ((_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (_D1_DDC_CHANNEL_SEL == _DPDDC2_TMDSDDC3)))
        // DDC3 De-bounce Reference Clock(IOSC = 27M) div by 4, latch 3 stages
        MCU_HDMI_DDC_CTRL1_FF2D |= (_BIT7 | _BIT6 | _BIT5 | _BIT4);
#endif

    }
    
#endif    // End of #if(_INTERNAL_OSC_XTAL == _IOSC14318K)    

}


//--------------------------------------------------
// Description  : DDC-CI Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuDdcciInitial(void)
{
    // Set slave address for debug tool
    MCU_I2C_SET_SLAVE_FF23 = 0x6A; 

#if(_DEBUG_DDC_CHANNEL_SEL == _DDC3)
    // DDC from DDC3 channel
    MCU_I2C_CHANNEL_CTRL_FF2B |= _BIT0;
#elif(_DEBUG_DDC_CHANNEL_SEL == _DDC2)
    // DDC from DDC2 channel
    MCU_I2C_CHANNEL_CTRL_FF2B &= ~_BIT0;
    MCU_I2C_SET_SLAVE_FF23 |= _BIT0;    
#else
    // DDC from DDC1 channel
    MCU_I2C_CHANNEL_CTRL_FF2B &= ~_BIT0;
    MCU_I2C_SET_SLAVE_FF23 &= ~_BIT0;    
#endif

    // Enable DDC-CI buffer auto reset
    MCU_I2C_IRQ_CTRL2_FF2A |= _BIT7; 

    // Clear DDCCI status
    MCU_I2C_STATUS_FF27 = 0x00; 
    pData[0] = MCU_I2C_DATA_IN_FF25;
    MCU_I2C_DATA_OUT_FF26 = 0x00;
    MCU_I2C_STATUS2_FF29 &= ~(_BIT5 | _BIT4);
    
    // Reset IIC Buffer
    MCU_I2C_IRQ_CTRL2_FF2A |= _BIT6; 
    
    // Enable STOP_I, D_IN_I, SUB_I interrupts
    MCU_I2C_IRQ_CTRL_FF28 |= _BIT4 | _BIT2 | _BIT1;     
    
    // Assign DDC-CI interrupts to int1 (IRQ2)
    MCU_IRQ_PRIORITY_FF01 |= _BIT0; 
    EX1 = 1;

    DebugMessageSystem("######    F/W START    ######", _OFF);

}

//--------------------------------------------------
// Description  : DDCCI switch DDC Port
// Input Value  : enumMode --> Debug or DDCCI Mode
//                ucInputPort --> Input Port Type
// Output Value : None
//--------------------------------------------------
void ScalerMcuDdcciSwitchPort(EnumDDCCIDebugMode enumMode, BYTE ucInputPort)
{
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    // Force to debug mode when debug message is enable
    enumMode = _DEBUG_MODE;
#endif    
    
    ScalerSelectDDCCIDebugMode(enumMode);

    // Disable STOP_I, D_IN_I, SUB_I interrupts
    MCU_I2C_IRQ_CTRL_FF28 &= ~(_BIT4 | _BIT3 | _BIT2 | _BIT1);
    
    if(enumMode == _DDCCI_MODE)
    {
        // Set slave address for DDCCI
        MCU_I2C_SET_SLAVE_FF23 = 0x6E;

        // Enable D_IN_I, SUB_I interrupts
        MCU_I2C_IRQ_CTRL_FF28 |= _BIT2 | _BIT1;
        
        switch(ucInputPort)
        {
            case _A0_INPUT_PORT:
    
                // DDCCI switch to DDC1
                MCU_I2C_CHANNEL_CTRL_FF2B &= (~_BIT0);
                MCU_I2C_SET_SLAVE_FF23 = MCU_I2C_SET_SLAVE_FF23 & (~_BIT0);
                
                break;
    
            case _D0_INPUT_PORT:
            
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
                // DDCCI switch to DDC2 if D0 is assigned to DDC2
                MCU_I2C_CHANNEL_CTRL_FF2B &= (~_BIT0);
                MCU_I2C_SET_SLAVE_FF23 |= _BIT0;
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
                // DDCCI switch to DDC3 if D0 is assigned to DDC3
                MCU_I2C_CHANNEL_CTRL_FF2B |= _BIT0;
                MCU_I2C_SET_SLAVE_FF23 &= ~_BIT0;
#endif
    
                break;
    
            case _D1_INPUT_PORT:
            
#if(_D1_DDC_CHANNEL_SEL == _DDC2)
                // DDCCI switch to DDC2 if D1 is assigned to DDC2
                MCU_I2C_CHANNEL_CTRL_FF2B &= (~_BIT0);
                MCU_I2C_SET_SLAVE_FF23 |= _BIT0;
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
                // DDCCI switch to DDC3 if D1 is assigned to DDC3
                MCU_I2C_CHANNEL_CTRL_FF2B |= _BIT0;
                MCU_I2C_SET_SLAVE_FF23 &= ~_BIT0;
#endif

                break;
        }
    
    }
    else
    {
        // Set slave address for debug tool
        MCU_I2C_SET_SLAVE_FF23 = 0x6A; 

        // Enable STOP_I, D_IN_I, SUB_I interrupts
        MCU_I2C_IRQ_CTRL_FF28 |= _BIT4 | _BIT2 | _BIT1;

#if(_DEBUG_DDC_CHANNEL_SEL == _DDC3)
        // DDC from DDC3 channel
        MCU_I2C_CHANNEL_CTRL_FF2B |= _BIT0;
#elif(_DEBUG_DDC_CHANNEL_SEL == _DDC2)
        // DDC from DDC2 channel
        MCU_I2C_CHANNEL_CTRL_FF2B &= ~_BIT0;
        MCU_I2C_SET_SLAVE_FF23 |= _BIT0;    
#else
        // DDC from DDC1 channel
        MCU_I2C_CHANNEL_CTRL_FF2B &= ~_BIT0;
        MCU_I2C_SET_SLAVE_FF23 &= ~_BIT0;    
#endif
    }
}

//--------------------------------------------------
// Description  : Send DDC Data
// Input Value  : pWriteArray --> Data to be sent
//                usTimeOutCnt --> Timeout
// Output Value : None
//--------------------------------------------------
void ScalerMcuDdcciSendData(BYTE *pWriteArray)
{
    WORD usTimeOutCnt = _DDCCI_TIMEOUT_LIMIT;
    BYTE ucDdcciCount = 0;

    // Reset ddc channel
    ScalerMcuDdcReset();

    // Enable mcu write
    MCU_I2C_IRQ_CTRL2_FF2A |= (_BIT6 | _BIT5);

    while(ucDdcciCount < ((pWriteArray[_DCCCI_LENGTH] & 0x7F) + 3))
    {
        // Load data to DDC-CI buffer until buffer full
        if((MCU_I2C_STATUS2_FF29 & _BIT2) == 0)
        {
            MCU_I2C_DATA_OUT_FF26 = pWriteArray[ucDdcciCount++];

            usTimeOutCnt = _DDCCI_TIMEOUT_LIMIT;
        }
        else
        {
            ScalerTimerDelayXms(1);

            usTimeOutCnt--;
        }

        if(usTimeOutCnt == 0)
        {
            break;
        }
    }

    // Disable mcu write
    MCU_I2C_IRQ_CTRL2_FF2A &= ~_BIT5;
}

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Release SCL
// Input Value  : NONE
// Output Value : NONE
//--------------------------------------------------
void ScalerMcuDdcciReleaseScl(void)
{
    if((MCU_I2C_CHANNEL_CTRL_FF2B & _BIT0) == _BIT0) // _DDC3_CHANNEL   
    { 
        MCU_HDMI_DDC_CTRL2_FF2E &= ~_BIT0;
    }
    else if((MCU_I2C_SET_SLAVE_FF23 & _BIT0) == _BIT0) // _DDC2_CHANNEL
    {
        MCU_DVI_DDC_CTRL2_FF20 &= ~_BIT0;
    }
    else // _DDC1_CHANNEL
    {
        MCU_ADC_DDC_CTRL2_FF1D &= ~_BIT0;
    }
}
//--------------------------------------------------
// Description  : hold SCL
// Input Value  : NONE
// Output Value : NONE
//--------------------------------------------------
void ScalerMcuDdcciHoldScl_EXINT1(void)
{
    if((MCU_I2C_CHANNEL_CTRL_FF2B & _BIT0) == _BIT0) // _DDC3_CHANNEL
    {
        MCU_HDMI_DDC_CTRL2_FF2E |= _BIT0;
    }
    else if((MCU_I2C_SET_SLAVE_FF23 & _BIT0) == _BIT0) // _DDC2_CHANNEL
    {
        MCU_DVI_DDC_CTRL2_FF20 |= _BIT0;
    }
    else // _DDC1_CHANNEL                             
    {
        MCU_ADC_DDC_CTRL2_FF1D |= _BIT0;
    }
}
#endif  // End of #if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Get DDC-CI Data in Interrupt Process
// Input Value  : pReadArray --> Data received
// Output Value : _SUCCESS or _FAIL
//--------------------------------------------------
BYTE ScalerMcuDdcciIntGetData_EXINT1(BYTE *pReadArray) using 2
{
    // Get DDC-CI Source Address
    if((MCU_I2C_STATUS_FF27 & _BIT1) == _BIT1)
    {
        g_ucDdcciCountEXINT = 0;

        // Save Address
        pReadArray[g_ucDdcciCountEXINT++] = MCU_I2C_SUB_IN_FF24;

        // Clear Flag
        MCU_I2C_STATUS_FF27 &= ~_BIT1;
    }

    if((MCU_I2C_STATUS_FF27 & _BIT2) == _BIT2)
    {
        // Save received data until buffer empty
        while((MCU_I2C_STATUS2_FF29 & _BIT1) == 0)
        {
            if(g_ucDdcciCountEXINT >= _DDCCI_RXBUF_LENGTH)
            {
                // Reset data buffer
                MCU_I2C_IRQ_CTRL2_FF2A |= _BIT6;
                
                g_ucDdcciCountEXINT = 0;
                
                break;
            }

            pReadArray[g_ucDdcciCountEXINT++] = MCU_I2C_DATA_IN_FF25;

            // All data are received
            if(((pReadArray[_DCCCI_LENGTH] & 0x7F) + 3) == g_ucDdcciCountEXINT)
            {
                // Reset data buffer
                MCU_I2C_IRQ_CTRL2_FF2A |= _BIT6;

                g_ucDdcciCountEXINT = 0;

        // Hold Scl for Display Calibration Process
#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))                       
                if((pReadArray[3] == 0xFC) && (pReadArray[2] == 0x03))
                {                               
                     ScalerMcuDdcciHoldScl_EXINT1();
                }
#endif

                return _SUCCESS;
            }        
        }
    }

    return _FAIL;
}

#endif // End of #if(_DEBUG_MESSAGE_SUPPORT == _OFF)

//--------------------------------------------------
// Description  : Set Flash Clock Divider.
// Input Value  : ClkDiv --> Flash Clock Divider
// Output Value : None
//--------------------------------------------------
void ScalerMcuFlashClockDiv(EnumFlashClkDiv enumClkDiv)
{
    enumClkDiv &= 0x0F;
    enumClkDiv = (enumClkDiv << 2);
    enumClkDiv |= (MCU_CTRL_FFED & 0xC3);
    MCU_CTRL_FFED = enumClkDiv;
}

//--------------------------------------------------
// Description  : Set Mcu Clock Divider.
// Input Value  : ClkDiv --> MCU Clock Divider
// Output Value : None
//--------------------------------------------------
void ScalerMcuClockDiv(EnumMcuClkDiv enumClkDiv)
{
    enumClkDiv &= 0x0F;
    enumClkDiv = (enumClkDiv << 2);
    enumClkDiv |= (MCU_CLOCK_CTRL_FFEE & 0xC3);
    MCU_CLOCK_CTRL_FFEE = enumClkDiv;
}

//--------------------------------------------------
// Description  : CPU Clock Select.
// Input Value  : Clock --> _M2PLL_CLK/_EXT_XTAL_CLK
// Output Value : None
//--------------------------------------------------
void ScalerMcuClockSel(BYTE ucClock)
{
    if(ucClock == _M2PLL_CLK)
    {
        // Bit1 : 1 --> CPU CLK Source Select to M2PLL
        MCU_CTRL_FFED |= _BIT1;
    }
    else
    {
        // Bit1 : 0 --> CPU CLK Source Select to Xtal
        MCU_CTRL_FFED &= ~_BIT1;
    }
}

#if(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
//--------------------------------------------------
// Description  : Set Flash & Mcu Divider when OSD is running.
// Input Value  : Fast or Low Speed
// Output Value : None
//--------------------------------------------------
void ScalerMcuSwitchFlashMcuFastSpeed(bit bEnable)
{
    // Only Take Effect when Flash Clk is From M2PLL
    if((MCU_CTRL_FFED & _BIT1) == _BIT1)
    {
        if(bEnable == _ENABLE)
        {
            // Don't Switch Again If It's Already Using Fast Div
            if(((MCU_CTRL_FFED & 0x3C) >> 2) != _FLASH_CLK_FAST_DIV)
            {
                // Switch Flash and MCU Clock to high speed
                ScalerMcuFlashClockDiv(_FLASH_CLK_FAST_DIV);
                ScalerMcuClockDiv(_MCU_CLK_FAST_DIV);

                // Reload Timer Count
                ScalerTimerSetTimerCount(_TIMER_OPERATION_OSD_MODE);                
            }
        }
        else if(bEnable == _DISABLE)
        {
            // Don't Switch Again If It's Already Using Normal Div
            if(((MCU_CTRL_FFED & 0x3C) >> 2) != _FLASH_CLK_DIV)
            {
                // Switch Flash and MCU Clock to high speed
                ScalerMcuFlashClockDiv(_FLASH_CLK_DIV);
                ScalerMcuClockDiv(_MCU_CLK_DIV);

                // Reload Timer Count
                ScalerTimerSetTimerCount(_TIMER_OPERATION_POWER_NORMAL_MODE);
            }
        }
    }
}
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
//--------------------------------------------------
// Description  : Enable MCU Into Idle Mode
// Input Value  : None.
// Output Value : None
//--------------------------------------------------
void ScalerMcuIntoIdle(void)
{
    // Enable MCU into idle mode.
    PCON |= _BIT0;
}
#endif

#if(_LOW_SPEED_ADC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : SARADC Clock Select.
// Input Value  : enumClock --> _M2PLL_CLK/_IOSC_CLK
// Output Value : None
//--------------------------------------------------
void ScalerMcuSarAdcClkSel(EnumClkSel enumClock)
{
    if(enumClock == _EXT_XTAL_CLK)
    {
        // ADC clk from external Xtal and div by 4 to obtain clk target 3MHz
        MCU_ADC_CLK_DIV_FF0D = 0x04;
    }
    else
    {
#if(_INTERNAL_OSC_XTAL == _IOSC14318K)
        // ADC clk from IOSC(14.318M) and div by 4 to obtain clk target 3MHz
        MCU_ADC_CLK_DIV_FF0D = 0x04;
#else
        // ADC clk from IOSC(27M) and div by 9 to obtain clk target 3MHz
        MCU_ADC_CLK_DIV_FF0D = 0x09;
#endif
    }
}

#endif  // End of #if(_LOW_SPEED_ADC_SUPPORT == _ON)

#if(_PWM_FUNCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : PWM Clock Switch.
// Input Value  : Clock --> _M2PLL_CLK/_EXT_XTAL_CLK(_IOSC_CLK)
// Output Value : None
//--------------------------------------------------
void ScalerMcuPwmClockSel(EnumClkSel enumClock)
{
    BYTE ucPWM_M = 0;
    WORD usPWM_N = 0;
    WORD usCLKDiv = 0;
    WORD usFrequency = 0;

    // Adjust PWMx divider: M & N
#if((_PWM0_EN == _ON) || (_PWM0_PSAV_EN == _ON))
    // Get PWM0 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_PWM03_M_FF3B & (_BIT1 | _BIT0)))
    // N = (((WORD)((MCU_PWM01_N_MSB_FF3D & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_PWM0_N_LSB_FF3E) + 1)
    usCLKDiv = (0x01 << (MCU_PWM03_M_FF3B & (_BIT1 | _BIT0))) * (((WORD)((MCU_PWM01_N_MSB_FF3D & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_PWM0_N_LSB_FF3E) + 1);

    if(enumClock == _IOSC_CLK)
    {
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To IOSC
        MCU_PWM_CK_SEL_FF3A &= ~_BIT0;
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To M2PLL
        MCU_PWM_CK_SEL_FF3A |= _BIT0;
    }
    
    ScalerMcuPwmAdjustFrequency(_PWM0, usFrequency);
#endif // End of #if((_PWM0_EN == _ON) || (_PWM0_PSAV_EN == _ON))

#if((_PWM1_EN == _ON) || (_PWM1_PSAV_EN == _ON))
    // Get PWM1 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_PWM03_M_FF3B & (_BIT3 | _BIT2)))
    // N = (((WORD)((MCU_PWM01_N_MSB_FF3D & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 8) | MCU_PWM1_N_LSB_FF3F) + 1)
    usCLKDiv = (0x01 << ((MCU_PWM03_M_FF3B & (_BIT3 | _BIT2)) >> 2)) * (((WORD)((MCU_PWM01_N_MSB_FF3D & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | MCU_PWM1_N_LSB_FF3F) + 1);

    if(enumClock == _IOSC_CLK)
    {
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To IOSC
        MCU_PWM_CK_SEL_FF3A &= ~_BIT1;
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To M2PLL
        MCU_PWM_CK_SEL_FF3A |= _BIT1;
    }
    
    ScalerMcuPwmAdjustFrequency(_PWM1, usFrequency);
#endif // End of #if((_PWM1_EN == _ON) || (_PWM1_PSAV_EN == _ON))

#if((_PWM2_EN == _ON) || (_PWM2_PSAV_EN == _ON))
    // Get PWM2 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_PWM03_M_FF3B & (_BIT5 | _BIT4)))
    // N = (((WORD)((MCU_PWM23_N_MSB_FF40 & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_PWM2_N_LSB_FF41) + 1)
    usCLKDiv = (0x01 << ((MCU_PWM03_M_FF3B & (_BIT5 | _BIT4)) >> 4)) * (((WORD)((MCU_PWM23_N_MSB_FF40 & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_PWM2_N_LSB_FF41) + 1);

    if(enumClock == _IOSC_CLK)
    {
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To IOSC
        MCU_PWM_CK_SEL_FF3A &= ~_BIT2;
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To M2PLL
        MCU_PWM_CK_SEL_FF3A |= _BIT2;
    }
    
    ScalerMcuPwmAdjustFrequency(_PWM2, usFrequency);
#endif // End of #if((_PWM2_EN == _ON) || (_PWM2_PSAV_EN == _ON))

#if((_PWM3_EN == _ON) || (_PWM3_PSAV_EN == _ON))
    // Get PWM3 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_PWM03_M_FF3B & (_BIT7 | _BIT6)))
    // N = (((WORD)((MCU_PWM23_N_MSB_FF40 & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | MCU_PWM3_N_LSB_FF42) + 1)
    usCLKDiv = (0x01 << ((MCU_PWM03_M_FF3B & (_BIT7 | _BIT6)) >> 6)) * (((WORD)((MCU_PWM23_N_MSB_FF40 & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | MCU_PWM3_N_LSB_FF42) + 1);

    if(enumClock == _IOSC_CLK)
    {
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To IOSC
        MCU_PWM_CK_SEL_FF3A &= ~_BIT3;
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To M2PLL
        MCU_PWM_CK_SEL_FF3A |= _BIT3;
    }
    
    ScalerMcuPwmAdjustFrequency(_PWM3, usFrequency);
#endif // End of #if((_PWM3_EN == _ON) || (_PWM3_PSAV_EN == _ON))

#if((_PWM4_EN == _ON) || (_PWM4_PSAV_EN == _ON))
    // Get PWM4 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_PWM45_M_FF3C & (_BIT1 | _BIT0)))
    // N = (((WORD)((MCU_PWM45_N_MSB_FF43 & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 8) | MCU_PWM4_N_LSB_FF44) + 1)
    usCLKDiv = (0x01 << (MCU_PWM45_M_FF3C & (_BIT1 | _BIT0))) * (((WORD)((MCU_PWM45_N_MSB_FF43 & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | MCU_PWM4_N_LSB_FF44) + 1);

    if(enumClock == _IOSC_CLK)
    {
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To IOSC
        MCU_PWM_CK_SEL_FF3A &= ~_BIT4;
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To M2PLL
        MCU_PWM_CK_SEL_FF3A |= _BIT4;
    }
    
    ScalerMcuPwmAdjustFrequency(_PWM4, usFrequency);
#endif // End of #if((_PWM4_EN == _ON) || (_PWM4_PSAV_EN == _ON))

#if((_PWM5_EN == _ON) || (_PWM5_PSAV_EN == _ON))
    // Get PWM5 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_PWM45_M_FF3C & (_BIT1 | _BIT0)))
    // N = (((WORD)((MCU_PWM45_N_MSB_FF43 & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_PWM4_N_LSB_FF44) + 1)
    usCLKDiv = (0x01 << ((MCU_PWM45_M_FF3C & (_BIT3 | _BIT2)) >> 2)) * (((WORD)((MCU_PWM45_N_MSB_FF43 & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_PWM5_N_LSB_FF45) + 1);

    if(enumClock == _IOSC_CLK)
    {
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To IOSC
        MCU_PWM_CK_SEL_FF3A &= ~_BIT5;
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;

        // Switch Clock To M2PLL
        MCU_PWM_CK_SEL_FF3A |= _BIT5;
    }
    
    ScalerMcuPwmAdjustFrequency(_PWM5, usFrequency);
#endif // End of #if((_PWM5_EN == _ON) || (_PWM5_PSAV_EN == _ON))

}

//--------------------------------------------------
// Description  : PWM Clock Switch.
// Input Value  : ucPwmType --> _BACKLIGHT_PWM/_AUDIO_VOLUME...
//                ucFrequency --> Frequency
// Output Value : None
//--------------------------------------------------
void ScalerMcuPwmAdjustFrequency(BYTE ucPwmType, WORD usFrequency)
{
    BYTE ucPWM_M = 0; 
    WORD usPWM_N = 0;

    // Set limit for Pwm frequency
    if(usFrequency < _PWM_FREQ_LOW_BOUND)
    {
        usFrequency = _PWM_FREQ_LOW_BOUND;
    }
    else if(usFrequency > _PWM_FREQ_UPPER_BOUND)
    {
        usFrequency = _PWM_FREQ_UPPER_BOUND;
    }

    if(usFrequency >= _PWM_FREQ_DVSRST_BOUND)
    {
    	// Disable PWM reset by DVS
#if(_BACKLIGHT_PWM == _PWM0)
    	MCU_PWM_VS_CTRL_FF47 &= ~_BIT0;

#elif(_BACKLIGHT_PWM == _PWM1)
    	MCU_PWM_VS_CTRL_FF47 &= ~_BIT1;

#elif(_BACKLIGHT_PWM == _PWM2)
    	MCU_PWM_VS_CTRL_FF47 &= ~_BIT2;

#elif(_BACKLIGHT_PWM == _PWM3)
    	MCU_PWM_VS_CTRL_FF47 &= ~_BIT3;

#elif(_BACKLIGHT_PWM == _PWM4)
    	MCU_PWM_VS_CTRL_FF47 &= ~_BIT4;

#elif(_BACKLIGHT_PWM == _PWM5)
    	MCU_PWM_VS_CTRL_FF47 &= ~_BIT5;		
#endif
    }
    else
    {
		// Enable PWM reset by DVS
#if(_BACKLIGHT_PWM == _PWM0)
    	MCU_PWM_VS_CTRL_FF47 |= ((BYTE)_PWM0_RST_BY_DVS);

#elif(_BACKLIGHT_PWM == _PWM1)
    	MCU_PWM_VS_CTRL_FF47 |= ((BYTE)_PWM1_RST_BY_DVS << 1);

#elif(_BACKLIGHT_PWM == _PWM2)
    	MCU_PWM_VS_CTRL_FF47 |= ((BYTE)_PWM2_RST_BY_DVS << 2);

#elif(_BACKLIGHT_PWM == _PWM3)
    	MCU_PWM_VS_CTRL_FF47 |= ((BYTE)_PWM3_RST_BY_DVS << 3);

#elif(_BACKLIGHT_PWM == _PWM4)
    	MCU_PWM_VS_CTRL_FF47 |= ((BYTE)_PWM4_RST_BY_DVS << 4);

#elif(_BACKLIGHT_PWM == _PWM5)
    	MCU_PWM_VS_CTRL_FF47 |= ((BYTE)_PWM5_RST_BY_DVS << 5);
#endif
    }

    // Check if PWM clk is M2PLL or IOSC
    if((MCU_PWM_CK_SEL_FF3A & ucPwmType) == ucPwmType)
    {
        for(ucPWM_M = 0; ucPWM_M < 4; ucPWM_M++)
        {
            // Calculate N Divider for M2PLL
            usPWM_N = ((DWORD)(((DWORD)_M2PLL_CLK_MHZ * 1000000) / ((DWORD)usFrequency * (0x01 << ucPWM_M) * _PWM_DUT_RESOLUTION)) - 1);

            if(usPWM_N < 4096)
            {
                break;
            }
        }
    }
    else
    {
        for(ucPWM_M = 0; ucPWM_M < 4; ucPWM_M++)
        {
#if(_INTERNAL_OSC_XTAL == _IOSC27000K)
            // Calculate N Divider for IOSC 27MHz
            usPWM_N = ((DWORD)(((DWORD)_IOSC27000K * 1000) / ((DWORD)usFrequency * (0x01 << ucPWM_M) * _PWM_DUT_RESOLUTION)) - 1);
#else
            // Calculate N Divider for IOSC 14.318MHz
            usPWM_N = ((DWORD)(((DWORD)_IOSC14318K * 1000) / ((DWORD)usFrequency * (0x01 << ucPWM_M) * _PWM_DUT_RESOLUTION)) - 1);

#endif
            if(usPWM_N < 4096)
            {
                break;
            }
        }
    }

    // Load M/N divider to corresponding register
    switch(ucPwmType)
    {
#if((_PWM0_EN == _ON) || (_PWM0_PSAV_EN == _ON))
        case _PWM0:

            MCU_PWM03_M_FF3B = (MCU_PWM03_M_FF3B & ~(_BIT1 | _BIT0)) | (ucPWM_M);
            MCU_PWM01_N_MSB_FF3D &= ~(_BIT3 | _BIT2 | _BIT1 | _BIT0);
            MCU_PWM01_N_MSB_FF3D |= (BYTE)((usPWM_N >> 8) & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
            MCU_PWM0_N_LSB_FF3E = (BYTE)usPWM_N;
            MCU_PWM_CK_FF49 |= _BIT0;

            break;
#endif

#if((_PWM1_EN == _ON) || (_PWM1_PSAV_EN == _ON))
        case _PWM1:

            MCU_PWM03_M_FF3B = (MCU_PWM03_M_FF3B & ~(_BIT3 | _BIT2)) | (ucPWM_M << 2);
            MCU_PWM01_N_MSB_FF3D &= ~(_BIT7 | _BIT6 | _BIT5 | _BIT4);
            MCU_PWM01_N_MSB_FF3D |= (BYTE)((usPWM_N >> 4) & (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            MCU_PWM1_N_LSB_FF3F = (BYTE)usPWM_N;
            MCU_PWM_CK_FF49 |= _BIT1;

            break;
#endif

#if((_PWM2_EN == _ON) || (_PWM2_PSAV_EN == _ON))
        case _PWM2:

            MCU_PWM03_M_FF3B = (MCU_PWM03_M_FF3B & ~(_BIT5 | _BIT4)) | (ucPWM_M << 4);
            MCU_PWM23_N_MSB_FF40 &= ~(_BIT3 | _BIT2 | _BIT1 | _BIT0);
            MCU_PWM23_N_MSB_FF40 |= (BYTE)((usPWM_N >> 8) & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
            MCU_PWM2_N_LSB_FF41 = (BYTE)usPWM_N;
            MCU_PWM_CK_FF49 |= _BIT2;

            break;
#endif

#if((_PWM3_EN == _ON) || (_PWM3_PSAV_EN == _ON))
        case _PWM3:
            
            MCU_PWM03_M_FF3B = (MCU_PWM03_M_FF3B & ~(_BIT7 | _BIT6)) | (ucPWM_M << 6);
            MCU_PWM23_N_MSB_FF40 &= ~(_BIT7 | _BIT6 | _BIT5 | _BIT4);
            MCU_PWM23_N_MSB_FF40 |= (BYTE)((usPWM_N >> 4) & (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            MCU_PWM3_N_LSB_FF42 = (BYTE)usPWM_N;
            MCU_PWM_CK_FF49 |= _BIT3;
            
            break;
#endif

#if((_PWM4_EN == _ON) || (_PWM4_PSAV_EN == _ON))
        case _PWM4:

            MCU_PWM45_M_FF3C = (MCU_PWM45_M_FF3C & ~(_BIT1 | _BIT0)) | (ucPWM_M);
            MCU_PWM45_N_MSB_FF43 &= ~(_BIT7 | _BIT6 | _BIT5 | _BIT4);
            MCU_PWM45_N_MSB_FF43 |= (BYTE)((usPWM_N >> 4) & (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            MCU_PWM4_N_LSB_FF44 = (BYTE)usPWM_N;
            MCU_PWM_CK_FF49 |= _BIT4;

            break;
#endif

#if((_PWM5_EN == _ON) || (_PWM5_PSAV_EN == _ON))
        case _PWM5:

            MCU_PWM45_M_FF3C = (MCU_PWM45_M_FF3C & ~(_BIT3 | _BIT2)) | (ucPWM_M << 2);
            MCU_PWM45_N_MSB_FF43 &= ~(_BIT3 | _BIT2 | _BIT1 | _BIT0);
            MCU_PWM45_N_MSB_FF43 |= (BYTE)((usPWM_N >> 8) & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
            MCU_PWM5_N_LSB_FF45 = (BYTE)usPWM_N;
            MCU_PWM_CK_FF49 |= _BIT5;

            break;
#endif

        default:
            
            break;
    }
}
#endif // End of #if(_PWM_FUNCTION_SUPPORT == _ON)

//--------------------------------------------------
// Description  : 5us Delay Calculation
// Input Value  : Clock --> _M2PLL_CLK/_IOSC_CLK
// Output Value : ucValue --> N = (DelayTime * FlashClock + 24)/80
//--------------------------------------------------
void ScalerMcu5usDelayCalc(EnumClkSel enumClock)
{
    BYTE ucFlashDiv = 0;

    ucFlashDiv = ((MCU_CTRL_FFED & 0x3C) >> 2);
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Chart :                                                                                                      //
    //                                                                                                              //
    //  INOSC                                                                                                       //
    //    14.318MHz ---|   |      |IOSC|            |   |                                                           //
    //                 |Mux|------|DIV | -----------|   |                                                           //
    //    27MHz     ---|   |      |    |            |   |  EMCU Crystal |   |                                       //
    //                CR0B[0]   Page6 CRA0[1:0]     |Mux|---------------|   |                                       //
    //                                              |   |               |   |                                       //
    //                   external-crystal-----------|   |               |   |       |Flash|      |MCU|              //
    //                                              |   |               |Mux|-------|DIV  |------|DIV|------8051    //
    //                                             CR09[3]              |   |       |     |   |  |   |              //
    //                                                                  |   |     0xFFED[5:2] | 0xFFEE[5:2]         //
    //                                                M2PLL-------------|   |                 |                     //
    //                                                                  |   |               Flash                   //
    //                                                                0xFFED[1]                                     //
    //                                                                                                              //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(enumClock == _M2PLL_CLK)
    {
        g_ucDelay5usN = (BYTE)(((DWORD)_M2PLL_CLK_MHZ / ucFlashDiv) & 0x000000FF);
    }
    else
    {
        g_ucDelay5usN = (BYTE)(((DWORD)_INTERNAL_OSC_XTAL / ucFlashDiv / 1000) & 0x000000FF);
    }

    ///////////////////////////////////////////////////////////////////////////////
    // Formula :                                                                 //
    //                                                                           //
    // #define Delay5us(N)\                                                      //
    //         g_ucDelay5usI = N;\                                               //
    //         while(--g_ucDelay5usI)                                            //
    //                                                                           //
    //              (24 + 32 + 80 * (N-1))                                       //
    //  DelayTime = ------------------------                                     //
    //                   FlashClock                                              //
    //                                                                           //
    //       DelayTime * FlashClock + 24                                         //
    //  N =  -----------------------------                                       //
    //                  80                                                       //
    //                                                                           //
    ///////////////////////////////////////////////////////////////////////////////
    g_ucDelay5usN = ((WORD)(_HW_IIC_DELAY_TIME * g_ucDelay5usN + 24) / 8);
    g_ucDelay5usN = (g_ucDelay5usN + 5) / 10;
}

#if(_SW_IIC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Software IIC Start
// Input Value  : ucSlaveAddr --> Slave Address
// Output Value : None
//--------------------------------------------------
BYTE ScalerMcuIICStart(BYTE ucSlaveAddr)
{
    BYTE ucTemp = 0;
    WORD usTimeOut = 0;

    if((MCU_CTRL_FFED & _BIT1) == _BIT1) // CPU clock come from M2PLL, base on 24.3M
    {
        usTimeOut = 700;
    }
    else // CPU clock come from internal or external crystal clock, base on 3.5M
    {
        if((ScalerGetBit(CM_0B_POWER_CTRL2, _BIT0) == _BIT0) && (((MCU_CTRL_FFED & 0x3C) >> 2) == _FLASH_CLK_PS_FAST_DIV)) // 27MHz and flash clock div = 1 --> for DP Case
        {            
            usTimeOut = 400;
        }
        else
        {
            usTimeOut = 100;
        }
    }

    PCB_SW_IIC_SCL_SET();
    PCB_SW_IIC_SDA_SET();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);

    PCB_SW_IIC_SCL_CHK(ucTemp);
    
    while(ucTemp == _LOW)
    {
        if(usTimeOut > 0)
        {
            usTimeOut--;
        }
        else
        {
            return _FAIL;
        }

        PCB_SW_IIC_SCL_CHK(ucTemp);
    }

    PCB_SW_IIC_SDA_CLR();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);

    PCB_SW_IIC_SCL_CLR();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);

    return ScalerMcuIICSendByte(ucSlaveAddr);
}

//--------------------------------------------------
// Description  : Software IIC Stop
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuIICStop(void)
{
    PCB_SW_IIC_SDA_CLR();
    PCB_SW_IIC_SCL_SET();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);

    PCB_SW_IIC_SDA_SET();
}

//--------------------------------------------------
// Description  : Software IIC Get Acknowledge
// Input Value  : None
// Output Value : ucAck --> 0: Ack / 1: Nack
//--------------------------------------------------
BYTE ScalerMcuIICGetAck(void)
{
    BYTE ucAck = 0;
    
    PCB_SW_IIC_SDA_SET();
    PCB_SW_IIC_SCL_SET();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);
    
    PCB_SW_IIC_SDA_CHK(ucAck);
    
    PCB_SW_IIC_SCL_CLR();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);

    PCB_SW_IIC_SDA_SET();

    return ucAck;
}

//--------------------------------------------------
// Description  : Software IIC Send Acknowledge
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuIICSendAck(void)
{    
    PCB_SW_IIC_SDA_CLR();
    PCB_SW_IIC_SCL_SET();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);

    PCB_SW_IIC_SCL_CLR();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);
}

//--------------------------------------------------
// Description  : Software IIC Send No-Acknowledge
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuIICSendNoAck(void)
{    
    PCB_SW_IIC_SDA_SET();
    PCB_SW_IIC_SCL_SET();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);

    PCB_SW_IIC_SCL_CLR();

    Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);
}

// Decrement an compile optimization level for Software IIC Delay timing
#pragma OT(8)

//--------------------------------------------------
// Description  : Software IIC Read 1 Byte
// Input Value  : None
// Output Value : ucValue --> Received Byte
//--------------------------------------------------
BYTE ScalerMcuIICGetByte(void)
{
    BYTE ucTemp = 0;
    BYTE ucCnt = 0;
    BYTE ucValue = 0;
    
    PCB_SW_IIC_SDA_SET();

    for(ucCnt = 0; ucCnt < 8; ucCnt++)
    {
        PCB_SW_IIC_SCL_SET();

        Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);

        PCB_SW_IIC_SDA_CHK(ucTemp);
        
        ucValue = (ucValue << 1) | ucTemp;

        PCB_SW_IIC_SCL_CLR();    

        Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);
    }

    return ucValue;
}

//--------------------------------------------------
// Description  : SoftWare IIC Write 1 Byte
// Input Value  : ucValue --> Data to be transmitted
// Output Value : None
//--------------------------------------------------
BYTE ScalerMcuIICSendByte(BYTE ucValue)
{
    BYTE ucCnt = 0;

    for(ucCnt = 0; ucCnt < 8; ucCnt++)
    {
        if((bit)(ucValue & _BIT7) == _HIGH)
        {
            PCB_SW_IIC_SDA_SET();
        }
        else
        {
            PCB_SW_IIC_SDA_CLR();
        }

        PCB_SW_IIC_SCL_SET();

        Delay5us(g_ucDelay5usN * _SW_IIC_CLK_DIV);

        PCB_SW_IIC_SCL_CLR();

        ucValue = ucValue << 1;
    }

    if(ScalerMcuIICGetAck() == _HIGH)
    {
        ScalerMcuIICStop();
        
        return _FAIL;
    }

    return _SUCCESS;
}

#pragma OT(9)

//--------------------------------------------------
// Description  : Polling internal write cycle finish
// Input Value  : ucSlaveAddr  --> Slave address
// Output Value : Polling result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuIICWriteStart(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr)
{
    if(ScalerMcuIICStart(ucSlaveAddr | _WRITE) == _FAIL)
    {
        return _FAIL;
    }

    switch(ucSubAddrLength)
    {
        case 1:
            
            if(ScalerMcuIICSendByte((BYTE)(usSubAddr)) == _FAIL)
            {
                return _FAIL;
            }

            break;

        case 2:

            if(ScalerMcuIICSendByte((BYTE)((usSubAddr & 0xFF00) >> 8)) == _FAIL)
            {
                return _FAIL;
            }
            else
            {
                if(ScalerMcuIICSendByte((BYTE)(usSubAddr)) == _FAIL)
                {
                    return _FAIL;
                }
            }
            
            break;

         default:

            break;

    }
    return _SUCCESS;
}

#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Polling internal write cycle finish
// Input Value  : ucSlaveAddr  --> Slave address
// Output Value : Polling result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuIICWritePolling(BYTE ucSlaveAddr)
{
    if(ScalerMcuIICStart(ucSlaveAddr | _WRITE) == _FAIL)
    {
        return _FAIL;
    }

    ScalerMcuIICStop();

    return _SUCCESS;
}
#endif

//--------------------------------------------------
// Description  : Read data from the selected device by Software IIC
// Input Value  : ucSlaveAddr  --> Slave address
//                ucSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{
    if(usLength == 0)
    {
        return _FAIL;
    }
    
    // Write Slave address and Sub-address
    if(ScalerMcuIICWriteStart(ucSlaveAddr, ucSubAddrLength, usSubAddr) == _FAIL)
    {
        return _FAIL;
    }

    // Write Slave address to read
    if(ScalerMcuIICStart(ucSlaveAddr | _READ) == _FAIL)
    {
        return _FAIL;
    }

    // Save received data
    while(--usLength)
    {
        *pReadArray++ = ScalerMcuIICGetByte();

        ScalerMcuIICSendAck();
    }

    *pReadArray++ = ScalerMcuIICGetByte();

    ScalerMcuIICSendNoAck();
    
    ScalerMcuIICStop();

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Write data to the selected device by Software IIC
// Input Value  : ucSlaveAddr  --> Slave address
//                usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE *pWriteArray)
{
    if(usLength == 0)
    {
        return _FAIL;
    }

    // Write Slave address and Sub-address
    if(ScalerMcuIICWriteStart(ucSlaveAddr, ucSubAddrLength, usSubAddr) == _FAIL)
    {
        return _FAIL;
    }

    // Send data
    while(usLength--)
    {
        if(ScalerMcuIICSendByte(*pWriteArray++) == _FAIL)
        {
            return _FAIL;
        }
    }

    ScalerMcuIICStop();

    return _SUCCESS;    
}

#endif    // End of #if(_SW_IIC_SUPPORT == _ON)

#if(_HW_IIC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Hardware IIC Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuHwIICInitial(void)
{
    // Reset IIC module
    MCU_I2C_CR0_FF55 &= _BIT7;
    
    // Enable IIC module and enable TOR
    MCU_I2C_CR0_FF55 |= (_BIT7 | _BIT0);
    
    // Set TOR: time-out = TOR x 2 x ((FD10+1)/input clk)
    MCU_I2C_CR1_FF56 = _HW_IIC_TOR;
    
    // Disable burst mode
    MCU_I2C_CR2_FF57 = 0x00;
    
    // Clear interrupts
    MCU_I2C_CR3_FF58 = 0x00;

    // Set fall time period count
    MCU_I2C_STR0_FF59 = _HW_IIC_FTPC;
    
    // Set STA setup time period count
    MCU_I2C_STR1_FF5A = _HW_IIC_STA_SUGPIO_C;
    
    // Set SCL high period count
    MCU_I2C_STR2_FF5B = _HW_IIC_SHPC_14318K;
    
    // Set SCL low period count
    MCU_I2C_STR3_FF5C = _HW_IIC_SLPC_14318K;
    
    // Set frequency divisor: ref = xtal/(FD10+1)
    MCU_I2C_CCR_FF5F = _HW_IIC_FD10_14318K;
}

//--------------------------------------------------
// Description  : Hardware IIC Clock Select
// Input Value  : Clock --> _EXT_XTAL_CLK/_IOSC_CLK
// Output Value : None
//--------------------------------------------------
void ScalerMcuHwIICSetFreqDiv(EnumClkSel enumClock)
{
#if(_INTERNAL_OSC_XTAL == _IOSC14318K)
    if((enumClock == _IOSC_CLK) || (enumClock == _EXT_XTAL_CLK))
    {
        // Set freq. divisor: ref = 14.318M/(FD10+1) = 7.16M(ref should be approx 10MHz)
        MCU_I2C_CCR_FF5F = _HW_IIC_FD10_14318K;
    
        // Set STA setup time period count
        MCU_I2C_STR1_FF5A = _HW_IIC_STA_SUGPIO_C;
    
        // Set SCL high period count
        MCU_I2C_STR2_FF5B = _HW_IIC_SHPC_14318K;
        
        // Set SCL low period count
        MCU_I2C_STR3_FF5C = _HW_IIC_SLPC_14318K;
    }
#else
    if(enumClock == _EXT_XTAL_CLK)
    {
        // Set freq. divisor: ref = XTAL/(FD10+1) = 7.16M(ref should be approx 10MHz)
        MCU_I2C_CCR_FF5F = _HW_IIC_FD10_14318K;

        // Set STA setup time period count
        MCU_I2C_STR1_FF5A = _HW_IIC_STA_SUGPIO_C;
        
        // Set SCL high period count
        MCU_I2C_STR2_FF5B = _HW_IIC_SHPC_14318K;
    
        // Set SCL low period count
        MCU_I2C_STR3_FF5C = _HW_IIC_SLPC_14318K;
    }
    else
    {
        // Set freq. divisor: ref = IOSC/(FD10+1) = 9M(ref should be approx 10MHz)
        MCU_I2C_CCR_FF5F = _HW_IIC_FD10_27000K;

        // Set STA setup time period count
        MCU_I2C_STR1_FF5A = _HW_IIC_STA_SUGPIO_C;

        // Set SCL high period count
        MCU_I2C_STR2_FF5B = _HW_IIC_SHPC_27000K;
        
        // Set SCL low period count
        MCU_I2C_STR3_FF5C = _HW_IIC_SLPC_27000K;
    }
#endif
}

#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Polling internal write cycle finish
// Input Value  : ucSlaveAddr  --> Slave address
// Output Value : Polling result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuHwIICWritePolling(BYTE ucSlaveAddr, BYTE ucSubAddrLength, BYTE ucHwIICPinNum)
{
    BYTE ucSubAddress = 0x00;
    BYTE ucLength = 0;
    BYTE ucTimeOutCnt = _IIC_POLLING_TIME;

    ScalerPinshareHwIICPin(ucHwIICPinNum);

    // Set 1 byte for FRSIB
    MCU_I2C_CR2_FF57 &= ~(_BIT1 | _BIT0);

    // Set no repeat start
    MCU_I2C_CR3_FF58 &= ~(_BIT4 | _BIT3);

    // Load Slave Address to IIC Buffer
    MCU_I2C_TD_FF5E = ucSlaveAddr | _WRITE;

    MCU_I2C_CR0_FF55 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1);

    switch(ucSubAddrLength)
    {
        case 0:

            break;

        case 1:

            // Set data length
            MCU_I2C_CR0_FF55 |= ucLength << 1;

            // Load Sub-Address to IIC Buffer
            MCU_I2C_TD_FF5E = (BYTE)(ucSubAddress);

            break;

        case 2:

            // Set data length
            MCU_I2C_CR0_FF55 |= (ucLength + 1) << 1;
        
            // Load First Sub-Address to IIC Buffer
            MCU_I2C_TD_FF5E = ucSubAddress;
        
            // Load Sub-Address to IIC Buffer
            MCU_I2C_TD_FF5E = ucSubAddress;
    
            break;
    
        default:

            break;
    }

    // IIC command Start
    MCU_I2C_CR0_FF55 |= _BIT6;

    // Wait until Master Transmit Complete
    while((MCU_I2C_SR_FF5D & 0x01) != 0x01)
    {
        ucTimeOutCnt--;

        Delay5us(g_ucDelay5usN);
    
        if(!ucTimeOutCnt)
        {
            return _FAIL;
        }
    }

    // Clear all flags
    MCU_I2C_SR_FF5D |= 0x07;
        
    return _SUCCESS;
}
#endif // End of #if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Read data from the selected device by IIC
// Input Value  : ucSlaveAddr  --> Slave address
//                ucSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuHwIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pReadArray, BYTE ucHwIICPinNum)
{
    BYTE ucI = 0;
    WORD usTimeOutCnt = 600;

    // Return fail if Data to be received is greater than IIC buffer size
    if(ucDataLength > _HW_IIC_BUFFER_SIZE)
    {
        return _FAIL;
    }

    ScalerPinshareHwIICPin(ucHwIICPinNum);

    switch(ucSubAddrLength)
    {
        case 0:

            // Set 1 byte for FRSIB
            MCU_I2C_CR2_FF57 &= ~(_BIT1 | _BIT0);

            // Set no repeat start
            MCU_I2C_CR3_FF58 &= ~(_BIT4 | _BIT3);

            // Load Slave Address to receive data
            MCU_I2C_TD_FF5E = ucSlaveAddr | _READ;
            
            break;

        case 1:

            // Set 2 bytes for FRSIB
            MCU_I2C_CR2_FF57 &= ~(_BIT1 | _BIT0);
            MCU_I2C_CR2_FF57 |= _BIT0;
            
            // Set one repeat start
            MCU_I2C_CR3_FF58 &= ~_BIT4;
            MCU_I2C_CR3_FF58 |= _BIT3;

            // Load Slave Address to IIC Buffer
            MCU_I2C_TD_FF5E = ucSlaveAddr | _WRITE;
            
            // Load Sub-Address to IIC Buffer
            MCU_I2C_TD_FF5E = (BYTE)(usSubAddr);

            // Load Slave Address to receive data
            MCU_I2C_TD_FF5E = ucSlaveAddr | _READ;

            break;

        case 2:

            // Set 3 bytes for FRSIB
            MCU_I2C_CR2_FF57 &= ~(_BIT1 | _BIT0);
            MCU_I2C_CR2_FF57 |= _BIT1;

            // Set one repeat start
            MCU_I2C_CR3_FF58 &= ~_BIT4;
            MCU_I2C_CR3_FF58 |= _BIT3;

            // Load Slave Address to IIC Buffer
            MCU_I2C_TD_FF5E = ucSlaveAddr | _WRITE;

            // Load First Sub-Address to IIC Buffer
            MCU_I2C_TD_FF5E = (BYTE)((usSubAddr & 0xFF00) >> 8);

            // Load Second Sub-Address to IIC Buffer
            MCU_I2C_TD_FF5E = (BYTE)(usSubAddr);
        
            // Load Slave Address to receive data
            MCU_I2C_TD_FF5E = ucSlaveAddr | _READ;

            break;

        default:

            break;
    }
        
    // Set data length
    MCU_I2C_CR0_FF55 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1);
    MCU_I2C_CR0_FF55 |= (ucDataLength - 1) << 1;
    
    // IIC command Start
    MCU_I2C_CR0_FF55 |= _BIT6;
    
    // Wait until Master Receive Complete
    while((MCU_I2C_SR_FF5D & 0x02) != 0x02)
    {
        // Return fail if Transaction Error happens
        if((MCU_I2C_SR_FF5D & 0x04) == 0x04)
        {
            // Reset(Block) IIC module
            MCU_I2C_CR0_FF55 &= ~_BIT7;

            // Enable IIC module
            MCU_I2C_CR0_FF55 |= _BIT7;

            return _FAIL;
        }

        if(usTimeOutCnt == 0)
        {
            return _FAIL;
        }
        else
        {
            usTimeOutCnt--;

            Delay5us(g_ucDelay5usN);
        }
        
    }
    
    // Save received data
    for(ucI = 0; ucI < ucDataLength; ucI++)
    {    
        *pReadArray = MCU_I2C_TD_FF5E;
        pReadArray++;
    }
    
    // Clear all flags
    MCU_I2C_SR_FF5D |= 0x07;

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Write data to the selected device by IIC
// Input Value  : ucSlaveAddr  --> Slave address
//                usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Write result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuHwIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pWriteArray, BYTE ucHwIICPinNum)
{
    BYTE ucI = 0;
    WORD usTimeOutCnt = 600;

    // Return fail if Sub-Address + Data to be trasmitted is greater than IIC buffer size
    if((ucDataLength + ucSubAddrLength + 1) > _HW_IIC_BUFFER_SIZE)
    {
        return _FAIL;
    }
    
    ScalerPinshareHwIICPin(ucHwIICPinNum);

    // Set 1 byte for FRSIB
    MCU_I2C_CR2_FF57 &= ~(_BIT1 | _BIT0);

    // Set no repeat start
    MCU_I2C_CR3_FF58 &= ~(_BIT4 | _BIT3);

    // Load Slave Address to IIC Buffer
    MCU_I2C_TD_FF5E = ucSlaveAddr | _WRITE;

    MCU_I2C_CR0_FF55 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1);

    switch(ucSubAddrLength)
    {
        case 0:

            // Set data length
            MCU_I2C_CR0_FF55 |= (ucDataLength - 1) << 1;

            break;

        case 1:

            // Load Sub-Address to IIC Buffer
            MCU_I2C_TD_FF5E = (BYTE)(usSubAddr);

            // Set data length
            MCU_I2C_CR0_FF55 |= ucDataLength << 1;

            break;

        case 2:

            // Load First Sub-Address to IIC Buffer
            MCU_I2C_TD_FF5E = (BYTE)((usSubAddr & 0xFF00) >> 8);
        
            // Load Second Sub-Address to IIC Buffer
            MCU_I2C_TD_FF5E = (BYTE)(usSubAddr);
    
            // Set data length
            MCU_I2C_CR0_FF55 |= (ucDataLength + 1) << 1;

            break;

        default:

            break;
    }
    
    // Load data to IIC buffer for transmission
    for(ucI = 0; ucI < ucDataLength; ucI++)
    {
        MCU_I2C_TD_FF5E = *pWriteArray;
        pWriteArray++;
    }

    // IIC command Start
    MCU_I2C_CR0_FF55 |= _BIT6;

    // Wait until Master Transmit Complete
    while((MCU_I2C_SR_FF5D & 0x01) != 0x01)
    {
        // Return fail if Transaction Error happens
        if((MCU_I2C_SR_FF5D & 0x04) == 0x04)
        {
            // Reset(Block) IIC module
            MCU_I2C_CR0_FF55 &= ~_BIT7;

            // Enable IIC module
            MCU_I2C_CR0_FF55 |= _BIT7;

            return _FAIL;
        }

        if(usTimeOutCnt == 0)
        {
            return _FAIL;
        }
        else
        {
            usTimeOutCnt--;

            Delay5us(g_ucDelay5usN);
        }
    }

    // Clear all flags
    MCU_I2C_SR_FF5D |= 0x07;

    return _SUCCESS;
}
#endif  // End of #if(_HW_IIC_SUPPORT == _ON)

#if(_UART_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Write data to the selected device by UART
// Input Value  : ucValue --> Data to be send
// Output Value : Write result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuUartWrite(BYTE ucValue)
{
    WORD usTimeOut = 1800;

    // Disable Serial Port IRQ
    ES = _DISABLE;

    // Clear Flag
    TI = 0;

    // Load Data to Serial Port Buffer
    SBUF = ucValue;

    do
    {
        Delay5us(g_ucDelay5usN);
    }
    while((TI == 0) && (--usTimeOut != 0));

    // Enable Serial Port IRQ
    ES = _ENABLE;

    return ((TI != 0) && (usTimeOut != 0)) ? _TRUE : _FALSE;
}
#endif
