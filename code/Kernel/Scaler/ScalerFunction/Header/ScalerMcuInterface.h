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
// ID Code      : ScalerMcuInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Macros of MCU Watch Dog
//--------------------------------------------------
#define CLR_MCU_WATCH_DOG()                            (MCU_WATCHDOG_TIMER_FFEA |= _BIT6)

//--------------------------------------------------
// Macros of DDC-CI
//--------------------------------------------------
#define GET_DDCCI_SLAVE_ADDRESS()                      (MCU_I2C_SET_SLAVE_FF23 & 0xFE)
#define GET_DDCCI_SUBADDRESS()                         (MCU_I2C_SUB_IN_FF24)
#define GET_DDCCI_DATA_IN()                            (MCU_I2C_DATA_IN_FF25)
#define GET_DDCCI_STATUS1()                            (MCU_I2C_STATUS_FF27)
#define GET_DDCCI_STATUS2()                            (MCU_I2C_STATUS2_FF29)
#define GET_DDCCI_IRQ_STATUS()                         (MCU_I2C_IRQ_CTRL2_FF2A)
#define GET_DDCCI_ACTIVE_CHANNEL()                     (((MCU_I2C_CHANNEL_CTRL_FF2B & _BIT0) == _BIT0) ? (_DDC3) : (MCU_I2C_SET_SLAVE_FF23 & _BIT0))

#define SET_DDCCI_SLAVE_ADDRESS(x)                     (MCU_I2C_SET_SLAVE_FF23 = ((x) & 0xFE))
#define SET_DDCCI_DATA_OUT(x)                          (MCU_I2C_DATA_OUT_FF26 = (x))
#define CLR_DDCCI_STATUS1(x)                           (MCU_I2C_STATUS_FF27 &= ~(x))
#define SET_DDCCI_STATUS2(x)                           (MCU_I2C_STATUS2_FF29 = (x))
#define SET_DDCCI_IRQ_STATUS(x)                        (MCU_I2C_IRQ_CTRL2_FF2A = (x))

//--------------------------------------------------
// Macros of 5us Delay
//--------------------------------------------------
#define Delay5us(N)                                     {\
                                                            g_ucDelay5usI = N;      \
                                                            while(--g_ucDelay5usI); \
                                                        }

//--------------------------------------------------
// Macros of SW IIC Status
//--------------------------------------------------
#if(_SW_IIC_SUPPORT == _ON)
#define GET_SW_IIC_STATUS()                             (g_ucSwIICStatus)
#define SET_SW_IIC_STATUS(x)                            (g_ucSwIICStatus = (x))
#endif

//--------------------------------------------------
// Macros of UART Status
//--------------------------------------------------
#if(_UART_SUPPORT == _ON)
#define GET_UART_TRANSMIT_STATUS()                      (TI)
#define CLR_UART_TRANSMIT_STATUS()                      (TI = 0)

#define GET_UART_RECEIVE_STATUS()                       (RI)
#define CLR_UART_RECEIVE_STATUS()                       (RI = 0)

#define GET_UART_DATA()                                 (SBUF)
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

extern BYTE data g_ucDelay5usN;
extern BYTE data g_ucDelay5usI;

#if(_SW_IIC_SUPPORT == _ON)
extern BYTE idata g_ucSwIICStatus;
#endif

#if(_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_A0[_EMBEDDED_DDCRAM_A0_SIZE];
#endif

#if(_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_D0[_EMBEDDED_DDCRAM_D0_SIZE];
#endif

#if(_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_D1[_EMBEDDED_DDCRAM_D1_SIZE];
#endif

#if(_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_MHL[_EMBEDDED_DDCRAM_D0_MHL_SIZE];
#elif(_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_MHL[_EMBEDDED_DDCRAM_D1_MHL_SIZE];
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerMcuInitial(void);
extern void ScalerMcuDdcDebounceSel(EnumClkSel enumClock);
extern void ScalerMcuDdcciSwitchPort(EnumDDCCIDebugMode enumMode, BYTE ucInputPort);
extern void ScalerMcuDdcciSendData(BYTE *pWriteArray);

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
extern void ScalerMcuDdcciReleaseScl(void);
extern void ScalerMcuDdcciHoldScl_EXINT1(void);
#endif 

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
extern BYTE ScalerMcuDdcciIntGetData_EXINT1(BYTE *pReadArray);
#endif

extern void ScalerMcuFlashClockDiv(EnumFlashClkDiv enumClkDiv);
extern void ScalerMcuClockDiv(EnumMcuClkDiv enumClkDiv);
extern void ScalerMcuClockSel(BYTE ucClock);

#if(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
extern void ScalerMcuSwitchFlashMcuFastSpeed(bit bEnable);
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
extern void ScalerMcuIntoIdle(void);
#endif

#if(_LOW_SPEED_ADC_SUPPORT == _ON)
extern void ScalerMcuSarAdcClkSel(EnumClkSel enumClock);
#endif

#if(_PWM_FUNCTION_SUPPORT == _ON)
extern void ScalerMcuPwmClockSel(EnumClkSel enumClock);
extern void ScalerMcuPwmAdjustFrequency(BYTE ucPwmType, WORD usFrequency);
#endif

extern void ScalerMcu5usDelayCalc(EnumClkSel enumClock);

#if(_SW_IIC_SUPPORT == _ON)
#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)
extern bit ScalerMcuIICWritePolling(BYTE ucSlaveAddr);
#endif
extern bit ScalerMcuIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE *pReadArray);
extern bit ScalerMcuIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE * pWriteArray);
#endif

#if(_HW_IIC_SUPPORT == _ON)
extern void ScalerMcuHwIICSetFreqDiv(EnumClkSel enumClock);
#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)
extern bit ScalerMcuHwIICWritePolling(BYTE ucSlaveAddr, BYTE ucSubAddrLength, BYTE ucHwIICPinNum);
#endif
extern bit ScalerMcuHwIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pReadArray, BYTE ucHwIICPinNum);
extern bit ScalerMcuHwIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pWriteArray, BYTE ucHwIICPinNum);
#endif

#if(_UART_SUPPORT == _ON)
extern bit ScalerMcuUartWrite(BYTE ucValue);
#endif

