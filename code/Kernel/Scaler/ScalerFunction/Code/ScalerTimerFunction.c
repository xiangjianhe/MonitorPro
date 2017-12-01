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
// ID Code      : ScalerTimerFunction.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_TIMERFUNCTION__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Instant Timer0/1
//--------------------------------------------------
// Active Mode
#define _TIMER_COUNT_TEMP                       ((DWORD)12 * _M2PLL_PLL_N * _M2PLL_PLL_O * _FLASH_CLK_DIV * _MCU_CLK_DIV)

// Power Saving/Down Mode
#define _TIMER_COUNT_PS_TEMP                    ((DWORD)12 * _FLASH_CLK_PS_DIV * _MCU_CLK_PS_DIV)

// Power Saving/Down Fast Mode for DP Aux Handshake
#define _TIMER_COUNT_PS_FAST_TEMP               ((DWORD)12 * _FLASH_CLK_PS_FAST_DIV * _MCU_CLK_PS_DIV)

// Initial Mode
#define _TIMER_COUNT_IN_TEMP                    ((DWORD)12 * _FLASH_CLK_IN_DIV * _MCU_CLK_IN_DIV)

// Active Mode --> for switching to a higher flash speed when OSD is used
#if(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
#define _TIMER_COUNT_OSD_TEMP                   ((DWORD)12 * _M2PLL_PLL_N * _M2PLL_PLL_O * _FLASH_CLK_FAST_DIV * _MCU_CLK_FAST_DIV)
#endif

#define _TIMER_COUNT_TEMP_PS_FAST1              (_IDLE_TIME * _FLASH_CLK_PS_FAST_DIV / _FLASH_CLK_PS_DIV)
#define _TIMER_COUNT_TEMP_PS_FAST2              ((WORD)(((DWORD)_INTERNAL_OSC_XTAL + (_TIMER2_COUNT_PS_FAST_TEMP / 2)) / _TIMER2_COUNT_PS_FAST_TEMP))
#define _TIMER_COUNT_TEMP_PS                    ((WORD)(((DWORD)_INTERNAL_OSC_XTAL  + (_TIMER2_COUNT_PS_TEMP / 2)) / _TIMER2_COUNT_PS_TEMP))

#define _TIMER01_TEMP_COUNT_NORMAL              (((DWORD)_EXT_XTAL * _M2PLL_PLL_M + (_TIMER_COUNT_TEMP / 2)) / _TIMER_COUNT_TEMP)
#define _TIMER01_TEMP_COUNT_PS_FAST             (((DWORD)_INTERNAL_OSC_XTAL + (_TIMER_COUNT_PS_FAST_TEMP / 2)) / _TIMER_COUNT_PS_FAST_TEMP)
#define _TIMER01_TEMP_COUNT_PS                  (((DWORD)_INTERNAL_OSC_XTAL + (_TIMER_COUNT_PS_TEMP / 2)) / _TIMER_COUNT_PS_TEMP)
#define _TIMER01_TEMP_COUNT_OSD                 (((DWORD)_EXT_XTAL * _M2PLL_PLL_M  + (_TIMER_COUNT_OSD_TEMP / 2)) / _TIMER_COUNT_OSD_TEMP)

//--------------------------------------------------
// Definitions of Timer1 for Serial Port
//--------------------------------------------------
// Active Mode
#define _TIMER1_UART_COUNT_TEMP                 ((DWORD)12 * 16 * _M2PLL_PLL_N * _M2PLL_PLL_O * _FLASH_CLK_DIV * _MCU_CLK_DIV * _UART_BAUD_RATE_POWER_NORMAL / 1000)
#define _TIMER1_UART_COUNT_BYTE                 (0x100 - ((BYTE)(((DWORD)_EXT_XTAL * _M2PLL_PLL_M + (_TIMER1_UART_COUNT_TEMP / 2)) / _TIMER1_UART_COUNT_TEMP)))


// Power Saving/Down Mode
#define _TIMER1_UART_COUNT_PS_TEMP              ((DWORD)12 * 16 * _FLASH_CLK_PS_DIV * _MCU_CLK_PS_DIV * _UART_BAUD_RATE_POWER_SAVING / 1000)
#define _TIMER1_UART_COUNT_PS_BYTE              (0x100 - ((BYTE)(((DWORD)_INTERNAL_OSC_XTAL  + (_TIMER1_UART_COUNT_PS_TEMP / 2)) / _TIMER1_UART_COUNT_PS_TEMP)))


// Power Saving/Down Fast Mode for DP Aux Handshake
#define _TIMER1_UART_COUNT_PS_FAST_TEMP         ((DWORD)12 * 16 * _FLASH_CLK_PS_FAST_DIV * _MCU_CLK_PS_DIV * _UART_BAUD_RATE_POWER_SAVING / 1000)
#define _TIMER1_UART_COUNT_PS_FAST_BYTE         (0x100 - ((BYTE)(((DWORD)_INTERNAL_OSC_XTAL  + (_TIMER1_UART_COUNT_PS_FAST_TEMP / 2)) / _TIMER1_UART_COUNT_PS_FAST_TEMP)))


// Initial Mode
#define _TIMER1_UART_COUNT_IN_TEMP              ((DWORD)12 * 16  * _FLASH_CLK_IN_DIV * _MCU_CLK_IN_DIV * _UART_BAUD_RATE_POWER_NORMAL / 1000)
#define _TIMER1_UART_COUNT_IN_BYTE              (0x100 - ((BYTE)(((DWORD)_EXT_XTAL  + (_TIMER1_UART_COUNT_IN_TEMP / 2)) / _TIMER1_UART_COUNT_IN_TEMP)))


// Active Mode --> for switching to a higher flash speed when OSD is used
#if(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
#define _TIMER1_UART_COUNT_OSD_TEMP             ((DWORD)12 * 16  * _M2PLL_PLL_N * _M2PLL_PLL_O * _FLASH_CLK_FAST_DIV * _MCU_CLK_FAST_DIV * _UART_BAUD_RATE_POWER_NORMAL / 1000)
#define _TIMER1_UART_COUNT_OSD_BYTE             (0x100 - ((BYTE)((((DWORD)_EXT_XTAL * _M2PLL_PLL_M + (_TIMER1_UART_COUNT_OSD_TEMP / 2)) / _TIMER1_UART_COUNT_OSD_TEMP))))
#endif

//--------------------------------------------------
// Definitions of Timer2
//--------------------------------------------------
#define _EVENT_TIME_MAX                         61000	// Please do not modify this value.


// Active Mode
#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
#define _TIMER2_COUNT_TEMP                      ((DWORD)12 * 4 * _M2PLL_PLL_N * _M2PLL_PLL_O * _FLASH_CLK_DIV * _MCU_CLK_DIV)
#else
#define _TIMER2_COUNT_TEMP                      ((DWORD)12 * _M2PLL_PLL_N * _M2PLL_PLL_O * _FLASH_CLK_DIV * _MCU_CLK_DIV)
#endif
#define _TIMER2_COUNT_NUM                       (0xFFFF - ((WORD)(((DWORD)_EXT_XTAL * _M2PLL_PLL_M + (_TIMER2_COUNT_TEMP / 2)) / _TIMER2_COUNT_TEMP)))

#define _TIMER2_COUNT_LBYTE                     (_TIMER2_COUNT_NUM & 0x00FF)
#define _TIMER2_COUNT_HBYTE                     (_TIMER2_COUNT_NUM >> 8)


// Power Saving/Down Mode
#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
#define _TIMER2_COUNT_PS_TEMP                   ((DWORD)12 * 4 * _FLASH_CLK_PS_DIV * _MCU_CLK_PS_DIV)
#else
#define _TIMER2_COUNT_PS_TEMP                   ((DWORD)12 * _FLASH_CLK_PS_DIV * _MCU_CLK_PS_DIV)
#endif
#define _TIMER2_COUNT_PS_NUM                    (0xFFFF - ((WORD)(((DWORD)_INTERNAL_OSC_XTAL  + (_TIMER2_COUNT_PS_TEMP / 2)) / _TIMER2_COUNT_PS_TEMP)))

#define _TIMER2_COUNT_PS_LBYTE                  (_TIMER2_COUNT_PS_NUM & 0x00FF)
#define _TIMER2_COUNT_PS_HBYTE                  (_TIMER2_COUNT_PS_NUM >> 8)


// Power Saving/Down Fast Mode for DP Aux Handshake
#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
#define _TIMER2_COUNT_PS_FAST_TEMP              ((DWORD)12 * 4 * _FLASH_CLK_PS_FAST_DIV * _MCU_CLK_PS_DIV)
#else
#define _TIMER2_COUNT_PS_FAST_TEMP              ((DWORD)12 * _FLASH_CLK_PS_FAST_DIV * _MCU_CLK_PS_DIV)
#endif
#define _TIMER2_COUNT_PS_FAST_NUM               (0xFFFF - ((WORD)(((DWORD)_INTERNAL_OSC_XTAL  + (_TIMER2_COUNT_PS_FAST_TEMP / 2)) / _TIMER2_COUNT_PS_FAST_TEMP)))

#define _TIMER2_COUNT_PS_FAST_LBYTE             (_TIMER2_COUNT_PS_FAST_NUM & 0x00FF)
#define _TIMER2_COUNT_PS_FAST_HBYTE             (_TIMER2_COUNT_PS_FAST_NUM >> 8)


// Initial Mode
#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
#define _TIMER2_COUNT_IN_TEMP                   ((DWORD)12 * 4 * _FLASH_CLK_IN_DIV * _MCU_CLK_IN_DIV)
#else
#define _TIMER2_COUNT_IN_TEMP                   ((DWORD)12 * _FLASH_CLK_IN_DIV * _MCU_CLK_IN_DIV)
#endif
#define _TIMER2_COUNT_IN_NUM                    (0xFFFF - ((WORD)(((DWORD)_EXT_XTAL  + (_TIMER2_COUNT_IN_TEMP / 2)) / _TIMER2_COUNT_IN_TEMP)))

#define _TIMER2_COUNT_IN_LBYTE                  (_TIMER2_COUNT_IN_NUM & 0x00FF)
#define _TIMER2_COUNT_IN_HBYTE                  (_TIMER2_COUNT_IN_NUM >> 8)


// Idle Mode
#define _IDLE_TIME                              100 // 100ms
#define _TIMER2_COUNT_IDLE_NUM                  (0xFFFF - ((WORD)((((DWORD)_INTERNAL_OSC_XTAL  + (_TIMER2_COUNT_PS_TEMP / 2)) / _TIMER2_COUNT_PS_TEMP) * _IDLE_TIME)))

#define _TIMER2_COUNT_IDLE_LBYTE                (_TIMER2_COUNT_IDLE_NUM & 0x00FF)
#define _TIMER2_COUNT_IDLE_HBYTE                (_TIMER2_COUNT_IDLE_NUM >> 8)


// Active Mode --> for switching to a higher flash speed when OSD is used
#if(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
#define _TIMER2_COUNT_OSD_TEMP                  ((DWORD)12 * 4 * _M2PLL_PLL_N * _M2PLL_PLL_O * _FLASH_CLK_FAST_DIV * _MCU_CLK_FAST_DIV)
#else
#define _TIMER2_COUNT_OSD_TEMP                  ((DWORD)12 * _M2PLL_PLL_N * _M2PLL_PLL_O * _FLASH_CLK_FAST_DIV * _MCU_CLK_FAST_DIV)
#endif
#define _TIMER2_COUNT_OSD_NUM                   (0xFFFF - ((WORD)(((DWORD)_EXT_XTAL * _M2PLL_PLL_M + (_TIMER2_COUNT_OSD_TEMP / 2)) / _TIMER2_COUNT_OSD_TEMP)))

#define _TIMER2_COUNT_OSD_LBYTE                 (_TIMER2_COUNT_OSD_NUM & 0x00FF)
#define _TIMER2_COUNT_OSD_HBYTE                 (_TIMER2_COUNT_OSD_NUM >> 8)
#endif

//--------------------------------------------------
// Definitions of TimeOut
//--------------------------------------------------
#if(_FLASH_CLK_SPEED == _FLASH_FAST_SPEED)
#define _TIMER_EVENT_TIMEOUT_ACTIVE             3500
#else
#define _TIMER_EVENT_TIMEOUT_ACTIVE             2400
#endif

#define _TIMER_EVENT_TIMEOUT_PS                 530
#define _TIMER_EVENT_TIMEOUT_FAST_PS            2100

#if(_FLASH_CLK_SPEED == _FLASH_FAST_SPEED)
#define _TIMER_POLLING_FLAG_TIMEOUT_ACTIVE      30
#else
#define _TIMER_POLLING_FLAG_TIMEOUT_ACTIVE      19
#endif

#define _TIMER_POLLING_FLAG_TIMEOUT_PS          5
#define _TIMER_POLLING_FLAG_TIMEOUT_FAST_PS     20


//--------------------------------------------------
// Macro of Timer Event Structure
//--------------------------------------------------
#define GET_EVENT_VALID(x)                      (g_stTimerEvent[x].b1EventValid)
#define SET_EVENT_VALID(x)                      (g_stTimerEvent[x].b1EventValid = _TRUE)
#define CLR_EVENT_VALID(x)                      (g_stTimerEvent[x].b1EventValid = _FALSE)

#define GET_EVENT_ID(x)                         (g_stTimerEvent[x].b7EventID)
#define SET_EVENT_ID(x, y)                      (g_stTimerEvent[x].b7EventID = y)

#define GET_EVENT_TIME(x)                       (g_stTimerEvent[x].usTime)
#define SET_EVENT_TIME(x, y)                    (g_stTimerEvent[x].usTime = y)
//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
bit g_bNotifyTimer2Int = _FALSE;
StructTimerEventTableType g_stTimerEvent[_TIMER_EVENT_COUNT];

volatile WORD data g_usTimerCounter = 0;

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
BYTE data g_ucTimerQuarterCount = 0;
#endif

#if((_INSTANT_TIMER_EVENT_0 == _ON) || (_INSTANT_TIMER_EVENT_1 == _ON))
EnumScalerTimerOperationMode g_enumTimerMode = _TIMER_OPERATION_INITIAL_MODE;
#endif

#if(_INSTANT_TIMER_EVENT_0 == _ON)
BYTE g_ucTimerCountHByte0 = 0;
BYTE g_ucTimerCountLByte0 = 0;
WORD g_usTimerPreviousCount0 = 0;
WORD g_usTimerBackupCount0 = 0;
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
BYTE g_ucTimerCountHByte1 = 0;
BYTE g_ucTimerCountLByte1 = 0;
WORD g_usTimerPreviousCount1 = 0;
WORD g_usTimerBackupCount1 = 0;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_INSTANT_TIMER_EVENT_0 == _ON)
void ScalerTimer0SetTimerCount(EnumInstTimerCounter enumTimerCount);
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
void ScalerTimer1SetTimerCount(EnumInstTimerCounter enumTimerCount);
#endif

void ScalerTimerSetTimerCount(EnumScalerTimerOperationMode enumOperationMode);

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
void ScalerTimerAddTimerCounter(void);
#endif

void ScalerTimerEventProc(EnumScalerTimerEventID enumEventID);
WORD ScalerTimerGetEventTime(BYTE ucEventIndex);
void ScalerTimerClrEventValid(BYTE ucEventIndex);
bit ScalerTimerCheckEventValid(BYTE ucEventIndex);
void ScalerTimerActiveTimerEvent(WORD usTime, BYTE ucEventID);
void ScalerTimerReactiveTimerEvent(WORD usTime, BYTE ucEventID);
void ScalerTimerCancelTimerEvent(BYTE ucEventID);
WORD ScalerTimerCheckTimerEvent(WORD usTime);
WORD ScalerTimerGetTimerCounter(void);
BYTE ScalerTimerGetEventID(BYTE ucEventIndex);
void ScalerTimerInitialTimerEvent(void);
void ScalerTimerDelayXms(WORD usNum);
bit ScalerTimerPollingFlagProc(WORD usTimeout, WORD ucRegister, BYTE ucBit, bit bSuccess);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
bit ScalerTimerPollingDataBitFlagProc(WORD usTimeout, WORD usRegister, BYTE ucValue, BYTE ucBit, bit bSuccess);
#endif
bit ScalerTimerWaitForEvent(EnumWaitEventType enumEvent);
void ScalerTimerWaitForActiveTimerEvent(BYTE ucEventID);
void ScalerTimerClrEventStatus(EnumWaitEventType enumEvent);
BYTE ScalerTimerGetEventStatus(EnumWaitEventType enumEvent);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_INSTANT_TIMER_EVENT_0 == _ON)
//--------------------------------------------------
// Description  : Timer0 Set Timer Counter
// Input Value  : ucCounter --> Counter in ms (1~30ms)
//                Stops Timer0 if ucCounter = 0
// Output Value : None
//--------------------------------------------------
void ScalerTimer0SetTimerCount(EnumInstTimerCounter enumTimerCount)
{
    if(enumTimerCount == _TIMER_OFF)
    {
        // Stop Timer 0
        TR0 = _OFF;
    }
    else
    {
        if(enumTimerCount == _TIMER_COUNT_BY_DEN_STOP)
        {
            PDATA_WORD(0) = (WORD)(((DWORD)_PANEL_DH_TOTAL * _PANEL_DV_TOTAL * 1000) / GET_D_CLK_FREQ()) - 9;
        }
        else
        {
            // Counter must be under 30ms
            if(enumTimerCount > 30000)
            {
                enumTimerCount = 30000;
            }

            PDATA_WORD(0) = enumTimerCount;
        }

        g_usTimerPreviousCount0 = PDATA_WORD(0);

        // Check if MCU Clk Source
        if(((MCU_CTRL_FFED & 0x3C) >> 2) == _FLASH_CLK_PS_FAST_DIV)
        {
            PDATA_WORD(0) = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_PS_FAST * PDATA_WORD(0)) / 1000));
        }
        else if((MCU_CTRL_FFED & _BIT1) == _BIT1)
        {
            PDATA_WORD(0) = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_NORMAL * PDATA_WORD(0)) / 1000));
        }
        else
        {
            PDATA_WORD(0) = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_PS * PDATA_WORD(0)) / 1000));
        }

        // Disable Timer 0
        ET0 = _DISABLE;

        // Stop Timer 0
        TR0 = _OFF;

        // Clear overflow flag
        TF0 = 0;

        g_ucTimerCountLByte0 = PDATA_WORD(0) & 0x00FF;
        g_ucTimerCountHByte0 = PDATA_WORD(0) >> 8;

        TL0 = g_ucTimerCountLByte0;
        TH0 = g_ucTimerCountHByte0;

        // Enable interrupt of Timer0
        ET0 = _ENABLE;

        if(enumTimerCount == _TIMER_COUNT_BY_DEN_STOP)
        {
            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        }
        
        // Run Timer 0
        TR0 = _ON;
    }
}
#endif // End of #if(_INSTANT_TIMER_EVENT_0 == _ON)

#if(_INSTANT_TIMER_EVENT_1 == _ON)
//--------------------------------------------------
// Description  : Timer1 Set Timer Counter
// Input Value  : ucCounter --> Counter in ms (max = 30ms)
//                Stops Timer1 if ucCounter = 0
// Output Value : None
//--------------------------------------------------
void ScalerTimer1SetTimerCount(EnumInstTimerCounter enumTimerCount)
{
    if(enumTimerCount == _TIMER_OFF)
    {
        // Stop Timer 1
        TR1 = _OFF;
    }
    else
    {
        if(enumTimerCount == _TIMER_COUNT_BY_DEN_STOP)
        {
            PDATA_WORD(0) = (WORD)(((DWORD)_PANEL_DH_TOTAL * _PANEL_DV_TOTAL * 1000) / GET_D_CLK_FREQ()) - 9;
        }
        else
        {
            // Counter must be under 30ms
            if(enumTimerCount > 30000)
            {
                enumTimerCount = 30000;
            }

            PDATA_WORD(0) = enumTimerCount;
        }

        g_usTimerPreviousCount1 = PDATA_WORD(0);

        // Check if MCU Clk Source
        if(((MCU_CTRL_FFED & 0x3C) >> 2) == _FLASH_CLK_PS_FAST_DIV)
        {
            PDATA_WORD(0) = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_PS_FAST * PDATA_WORD(0)) / 1000));
        }
        else if((MCU_CTRL_FFED & _BIT1) == _BIT1)
        {
            PDATA_WORD(0) = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_NORMAL * PDATA_WORD(0)) / 1000));
        }
        else
        {
            PDATA_WORD(0) = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_PS * PDATA_WORD(0)) / 1000));
        }

        // Disable Timer 1
        ET1 = _DISABLE;

        // Stop Timer 1
        TR1 = _OFF;

        // Clear overflow flag
        TF1 = 0;

        g_ucTimerCountLByte1 = PDATA_WORD(0) & 0x00FF;
        g_ucTimerCountHByte1 = PDATA_WORD(0) >> 8;

        TL1 = g_ucTimerCountLByte1;
        TH1 = g_ucTimerCountHByte1;

        // Enable interrupt of Timer1
        ET1 = _ENABLE;

        // Run Timer 0
        if(enumTimerCount == _TIMER_COUNT_BY_DEN_STOP)
        {
            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        }

        // Run Timer 1
        TR1 = _ON;
    }
}
#endif // End of #if(_INSTANT_TIMER_EVENT_1 == _ON)

//--------------------------------------------------
// Description  : Set Time Count for Timer2
// Input Value  : OperationMode --> Initial/Normal/Saving
// Output Value : None
//--------------------------------------------------
void ScalerTimerSetTimerCount(EnumScalerTimerOperationMode enumOperationMode)
{
#if(_INSTANT_TIMER_EVENT_0 == _ON)
    bit bTR0Info = TR0;
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
    bit bTR1Info = TR1;
#endif

    switch(enumOperationMode)
    {
        case _TIMER_OPERATION_INITIAL_MODE:

            pData[4] = _TIMER2_COUNT_IN_LBYTE;
            pData[5] = _TIMER2_COUNT_IN_HBYTE;
            pData[6] = _TIMER2_COUNT_IN_LBYTE;
            pData[7] = _TIMER2_COUNT_IN_HBYTE;
            
#if(_UART_SUPPORT == _ON)
            pData[8] = _TIMER1_UART_COUNT_IN_BYTE;
#endif
            break;

        case _TIMER_OPERATION_POWER_NORMAL_MODE:
            pData[4] = _TIMER2_COUNT_LBYTE;
            pData[5] = _TIMER2_COUNT_HBYTE;
            pData[6] = _TIMER2_COUNT_LBYTE;
            pData[7] = _TIMER2_COUNT_HBYTE; 

#if((_INSTANT_TIMER_EVENT_0 == _ON) || (_INSTANT_TIMER_EVENT_1 == _ON))
            if(g_enumTimerMode != _TIMER_OPERATION_POWER_NORMAL_MODE)
            {
                g_enumTimerMode = _TIMER_OPERATION_POWER_NORMAL_MODE;
                
#if(_INSTANT_TIMER_EVENT_0 == _ON)
                if(bTR0Info == _ON)
                {
                    g_usTimerBackupCount0 = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_NORMAL * g_usTimerPreviousCount0) / 1000));
                }
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
                if(bTR1Info == _ON)
                {
                    g_usTimerBackupCount1 = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_NORMAL * g_usTimerPreviousCount1) / 1000));
                }
#endif
            }
#endif

#if(_UART_SUPPORT == _ON)
            pData[8] = _TIMER1_UART_COUNT_BYTE;
#endif
            break;

        case _TIMER_OPERATION_POWER_SAVING_MODE:

            if(((MCU_CTRL_FFED & 0x3C) >> 2) == _FLASH_CLK_PS_FAST_DIV)
            {
                pData[4] = _TIMER2_COUNT_PS_FAST_LBYTE;
                pData[5] = _TIMER2_COUNT_PS_FAST_HBYTE;
                pData[6] = _TIMER2_COUNT_PS_FAST_LBYTE;
                pData[7] = _TIMER2_COUNT_PS_FAST_HBYTE; 

#if((_INSTANT_TIMER_EVENT_0 == _ON) || (_INSTANT_TIMER_EVENT_1 == _ON))
                if(g_enumTimerMode != _TIMER_OPERATION_POWER_SAVING_FAST_MODE)
                {
                    g_enumTimerMode = _TIMER_OPERATION_POWER_SAVING_FAST_MODE;

#if(_INSTANT_TIMER_EVENT_0 == _ON)
                    if(bTR0Info == _ON)
                    {
                        g_usTimerBackupCount0 = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_PS_FAST * g_usTimerPreviousCount0) / 1000));
                    }
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
                    if(bTR1Info == _ON)
                    {
                        g_usTimerBackupCount1 = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_PS_FAST * g_usTimerPreviousCount1) / 1000));
                    }
#endif
                }
#endif

#if(_UART_SUPPORT == _ON)
                pData[8] = _TIMER1_UART_COUNT_PS_FAST_BYTE;
#endif
            }
            else
            {
                pData[4] = _TIMER2_COUNT_PS_LBYTE;
                pData[5] = _TIMER2_COUNT_PS_HBYTE;
                pData[6] = _TIMER2_COUNT_PS_LBYTE;
                pData[7] = _TIMER2_COUNT_PS_HBYTE; 

#if((_INSTANT_TIMER_EVENT_0 == _ON) || (_INSTANT_TIMER_EVENT_1 == _ON))
                if(g_enumTimerMode != _TIMER_OPERATION_POWER_SAVING_MODE)
                {
                    g_enumTimerMode = _TIMER_OPERATION_POWER_SAVING_MODE;
#if(_INSTANT_TIMER_EVENT_0 == _ON)
                    if(bTR0Info == _ON)
                    {
                        g_usTimerBackupCount0 = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_PS * g_usTimerPreviousCount0) / 1000));
                    }
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
                    if(bTR1Info == _ON)
                    {
                        g_usTimerBackupCount1 = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_PS * g_usTimerPreviousCount1) / 1000));
                    }
#endif
                }
#endif

#if(_UART_SUPPORT == _ON)
                pData[8] = _TIMER1_UART_COUNT_PS_BYTE;
#endif
            }

            break;

        case _TIMER_OPERATION_POWER_IDLE_MODE:
            
            pData[4] = _TIMER2_COUNT_IDLE_LBYTE;
            pData[5] = _TIMER2_COUNT_IDLE_HBYTE;
            pData[6] = _TIMER2_COUNT_PS_LBYTE;
            pData[7] = _TIMER2_COUNT_PS_HBYTE;

            break;

#if(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
        case _TIMER_OPERATION_OSD_MODE:
            pData[4] = _TIMER2_COUNT_OSD_LBYTE;
            pData[5] = _TIMER2_COUNT_OSD_HBYTE;
            pData[6] = _TIMER2_COUNT_OSD_LBYTE;
            pData[7] = _TIMER2_COUNT_OSD_HBYTE;

#if((_INSTANT_TIMER_EVENT_0 == _ON) || (_INSTANT_TIMER_EVENT_1 == _ON))
            if(g_enumTimerMode != _TIMER_OPERATION_OSD_MODE)
            {
                g_enumTimerMode = _TIMER_OPERATION_OSD_MODE;
#if(_INSTANT_TIMER_EVENT_0 == _ON)
                if(bTR0Info == _ON)
                {
                    g_usTimerBackupCount0 = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_OSD * g_usTimerPreviousCount0) / 1000));
                }
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
                if(bTR1Info == _ON)
                {
                    g_usTimerBackupCount1 = 0xFFFF - ((WORD)((_TIMER01_TEMP_COUNT_OSD * g_usTimerPreviousCount1) / 1000));
                }
#endif
            }
#endif

#if(_UART_SUPPORT == _ON)
            pData[8] = _TIMER1_UART_COUNT_OSD_BYTE;
#endif
            break;
#endif

        default:
            // Default case set to initial mode
            pData[4] = _TIMER2_COUNT_IN_LBYTE;
            pData[5] = _TIMER2_COUNT_IN_HBYTE;
            pData[6] = _TIMER2_COUNT_IN_LBYTE;
            pData[7] = _TIMER2_COUNT_IN_HBYTE;
            
            break;
    }

    // Disable Timer 2
    ET2 = _DISABLE;

    // Stop Timer 2
    TR2 = _OFF;

    // Clear overflow flag
    TF2 = 0;
    
    TL2 = pData[4];
    TH2 = pData[5];
    RCAP2L = pData[6];
    RCAP2H = pData[7];

    g_bNotifyTimer2Int = _FALSE;
    
    // Enable interrupt of Timer2
    ET2 = _ENABLE;
    
    // Run Timer2
    TR2 = _ON;
    
#if(_INSTANT_TIMER_EVENT_0 == _ON)
    if((bTR0Info == _ON) && (enumOperationMode != _TIMER_OPERATION_INITIAL_MODE) && (enumOperationMode != _TIMER_OPERATION_POWER_IDLE_MODE))
    {
        // Do not load Timer Counter if Calculated Timer Counter is the same as Previous Timer Counter
        if(g_usTimerBackupCount0 != (((WORD)g_ucTimerCountHByte0 << 8) | g_ucTimerCountLByte0))
        {
            // Disable Timer 0
            ET0 = _DISABLE;

            // Stop Timer 0
            TR0 = _OFF;

            // Clear overflow flag
            TF0 = 0;

            // Load Timer Counter
            g_ucTimerCountLByte0 = g_usTimerBackupCount0 & 0x00FF;
            g_ucTimerCountHByte0 = g_usTimerBackupCount0 >> 8;
            TL0 = g_ucTimerCountLByte0;
            TH0 = g_ucTimerCountHByte0;
            
            // Enable interrupt of Timer0
            ET0 = _ENABLE;

            // Run Timer 0
            TR0 = _ON;
        }
    }
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
    if((bTR1Info == _ON) && (enumOperationMode != _TIMER_OPERATION_INITIAL_MODE) && (enumOperationMode != _TIMER_OPERATION_POWER_IDLE_MODE))
    {
        // Do not load Timer Counter if Calculated Timer Counter is the same as Previous Timer Counter
        if(g_usTimerBackupCount1 != (((WORD)g_ucTimerCountHByte1 << 8) | g_ucTimerCountLByte1))
        {
            // Disable Timer 1
            ET1 = _DISABLE;

            // Stop Timer 1
            TR1 = _OFF;

            // Clear overflow flag
            TF1 = 0;

            // Load Timer Counter
            g_ucTimerCountLByte1 = g_usTimerBackupCount1 & 0x00FF;
            g_ucTimerCountHByte1 = g_usTimerBackupCount1 >> 8;
            TL1 = g_ucTimerCountLByte1;
            TH1 = g_ucTimerCountHByte1;

            // Enable interrupt of Timer1
            ET1 = _ENABLE;

            // Run Timer 1
            TR1 = _ON;
        }
    }
#endif

#if(_UART_SUPPORT == _ON)
    // Stop Timer1
    TR1 = _OFF;

    // Clear overflow flag
    TF1 = 0;

    TL1 = pData[8];
    TH1 = pData[8];

    // Run Timer1
    TR1 = _ON;
#endif

}

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
//--------------------------------------------------
// Description  : Add Timer Counter according to timer2
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTimerAddTimerCounter(void)
{
    WORD usTemp = 0;

    if(((MCU_CTRL_FFED & 0x3C) >> 2) == _FLASH_CLK_PS_FAST_DIV)
    {
        if(g_bNotifyTimer2Int == _TRUE)
        {
            // Timer Counter 
            g_usTimerCounter += _TIMER_COUNT_TEMP_PS_FAST1 - 1; 
        }
        else
        {
            usTemp = (((WORD)(_TIMER2_COUNT_IDLE_HBYTE << 8) & 0xFF00) | (_TIMER2_COUNT_IDLE_LBYTE));
            usTemp = (((WORD)(TH2 << 8) & 0xFF00) | (TL2)) - usTemp;
            usTemp = usTemp / _TIMER_COUNT_TEMP_PS_FAST2;
          
            // Timer Counter 
            g_usTimerCounter += usTemp; 
        }
    }
    else
    {
        if(g_bNotifyTimer2Int == _TRUE)
        {
            // Timer Counter 
            g_usTimerCounter += _IDLE_TIME - 1; 
        }
        else
        {
            usTemp = (((WORD)(_TIMER2_COUNT_IDLE_HBYTE << 8) & 0xFF00) | (_TIMER2_COUNT_IDLE_LBYTE));
            usTemp = (((WORD)(TH2 << 8) & 0xFF00) | (TL2)) - usTemp;
            usTemp = usTemp / _TIMER_COUNT_TEMP_PS;
          
            // Timer Counter 
            g_usTimerCounter += usTemp; 
        }
    }
}
#endif // End of #if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)

//--------------------------------------------------
// Description  : Scaler Timer Event Process
// Input Value  : enumEventID --> Event to be processed
// Output Value : None
//--------------------------------------------------
void ScalerTimerEventProc(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
        case _SCALER_TIMER_EVENT_TMDS_VIDEO_DETECT:
        
            ScalerSyncTmdsVideoDetectEvent();
            break;

#if(_HDMI_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_TMDS_HDMI_PACKET_DETECT:
        
            ScalerTmdsHdmiPacketDetectEvent();
            break;            
#endif // End of #if(_HDMI_SUPPORT == _ON) 

#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))       

#if(_AUDIO_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_AUDIO_LOAD_STABLE_I_CODE:

            ScalerAudioLoadStableICodeEvent();
            break;            
#endif // End of #if(_AUDIO_SUPPORT == _ON)

#if(_DP_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_DP_HOTPLUG_ASSERTED:
            ScalerDpHotPlugEvent(_DP_HPD_ASSERTED);
            break;

        case _SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT:
            ScalerDpHotPlugEvent(_DP_HDCP_LONG_HPD_EVENT);
            break;

        case _SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ:
            ScalerDpLinkStatusIRQ();
            break;            
#endif  

#if((_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0) || (_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _SCALER_TIMER_EVENT_D0_PORT_DIGITAL_SWITCH:
            SET_D0_PORT_DIGITAL_SWITCH();
            break;    
#endif

#if((_D2_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1) || (_D3_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D1))
        case _SCALER_TIMER_EVENT_D1_PORT_DIGITAL_SWITCH:
            SET_D1_PORT_DIGITAL_SWITCH();
            break;
#endif   

#if((_VGA_SUPPORT == _ON) && (_ADCNR_BY_HISTOGRAM_SUPPORT == _ON))
        case _SCALER_TIMER_EVENT_NR_DETECTION_FINISHED:
            ScalerNrTimerEvent();
            break;
#endif

#if(_SDRAM_PHASE_CALIBRATION == _ON)
        case _SCALER_TIMER_EVENT_PHASE_CALIBRATION: 
            ScalerSDRAMPhaseOnLineTimer();
            break;

        case _SCALER_TIMER_EVENT_PHASE_CNT_CHECK:

            // Check phase count every 60 minute
            ScalerSDRAMPhaseCntCheck(60);
            break;
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
        case _SCALER_TIMER_EVENT_MHL_D0_READY_TO_TRANSMIT:

            SET_MHL_READY_TO_TRANSMIT(0, _TRUE);
            break;

        case _SCALER_TIMER_EVENT_MHL_D0_RECONNECT_1K:

#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
            if(((ScalerGetByte(P28_A7_CBUS0_CTRL_07) & 0x38) >> 3) == 0x02)
            {
                ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT5, 0x00);
                ScalerTimerDelayXms(52);
                ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT5, _BIT5);
            }
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
            if(((ScalerGetByte(P29_A7_CBUS1_CTRL_07) & 0x38) >> 3) == 0x02)
            {
                ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT5, 0x00);
                ScalerTimerDelayXms(52);
                ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT5, _BIT5);
            }
#endif

            break;

        case _SCALER_TIMER_EVENT_MHL_D0_ACTIVE_VBUS:

            if(GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)
            {
                // GPIO Select to Hot Plug
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
                ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, 0x00);
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
                ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, 0x00);
#endif
                SET_D0_MHL_VBUS_SWITCH(_MHL_VBUS_ON);
            }
            
            break;
#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
        case _SCALER_TIMER_EVENT_MHL_D1_READY_TO_TRANSMIT:

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
            SET_MHL_READY_TO_TRANSMIT(1, _TRUE);
#else
            SET_MHL_READY_TO_TRANSMIT(0, _TRUE);
#endif

            break;

        case _SCALER_TIMER_EVENT_MHL_D1_RECONNECT_1K:

#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
            if(((ScalerGetByte(P28_A7_CBUS0_CTRL_07) & 0x38) >> 3) == 0x02)
            {
                ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT5, 0x00);
                ScalerTimerDelayXms(52);
                ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT5, _BIT5);
            }
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
            if(((ScalerGetByte(P29_A7_CBUS1_CTRL_07) & 0x38) >> 3) == 0x02)
            {
                ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT5, 0x00);
                ScalerTimerDelayXms(52);
                ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT5, _BIT5);
            }
#endif

            break;

        case _SCALER_TIMER_EVENT_MHL_D1_ACTIVE_VBUS:

            if(GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)
            {
                // GPIO Select to Hot Plug
#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
                ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, 0x00);
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
                ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, 0x00);
#endif
 
                SET_D1_MHL_VBUS_SWITCH(_MHL_VBUS_ON);
            }
            
            break;
#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

#if((_DCC_HISTOGRM_INFO == _ON) && (_DCC_HISTOGRAM_THD_CHANGE == _ON))
        case _SCALER_TIMER_EVENT_DCC_HISTOGRAM_THD_CHANGE:
            ScalerColorDCCChangeHistogramThd();            
            ScalerTimerReactiveTimerEvent((WORD)(((DWORD)_PANEL_DH_TOTAL * _PANEL_DV_TOTAL * 2) / GET_D_CLK_FREQ()), _SCALER_TIMER_EVENT_DCC_HISTOGRAM_THD_CHANGE);

            break;
#endif

        default:
            break;
    }    
}

//--------------------------------------------------
// Description  : Get Event Time
// Input Value  : ucEventIndex --> Event which time is needed
// Output Value : Event Time
//--------------------------------------------------
WORD ScalerTimerGetEventTime(BYTE ucEventIndex)
{
    return GET_EVENT_TIME(ucEventIndex);
}

//--------------------------------------------------
// Description  : Clear Event Time
// Input Value  : ucEventIndex --> Event which time is needed to be cleared
// Output Value : None
//--------------------------------------------------
void ScalerTimerClrEventValid(BYTE ucEventIndex)
{
    CLR_EVENT_VALID(ucEventIndex);
}

//--------------------------------------------------
// Description  : Check if Event is Valid
// Input Value  : ucEventIndex --> Event to be checked
// Output Value : Validity(_TRUE/_FALSE)
//--------------------------------------------------
bit ScalerTimerCheckEventValid(BYTE ucEventIndex)
{
    return GET_EVENT_VALID(ucEventIndex);;
}

//--------------------------------------------------
// Description  : Active Timer Event
// Input Value  : usTime --> Time to active Timer Event
//				  ucEventID --> Event to be actived
// Output Value : None
//--------------------------------------------------
void ScalerTimerActiveTimerEvent(WORD usTime, BYTE ucEventID)
{
    BYTE ucEventIndex = 0;

    // Search for Existing Event with the same Event ID
    for(ucEventIndex = 0; ucEventIndex < _TIMER_EVENT_COUNT; ucEventIndex++)
    {
        if(GET_EVENT_VALID(ucEventIndex) == _TRUE)
        {
            if(GET_EVENT_ID(ucEventIndex) == ucEventID)
            {
                return;
            }
        }
    }

    // Choose any Vacant Storage for Event
    for(ucEventIndex = 0; ucEventIndex < _TIMER_EVENT_COUNT; ucEventIndex++)
    {
        if(GET_EVENT_VALID(ucEventIndex) == _FALSE)
        {
            SET_EVENT_VALID(ucEventIndex);
            SET_EVENT_ID(ucEventIndex, ucEventID);
            SET_EVENT_TIME(ucEventIndex, (WORD)((DWORD)(ScalerTimerCheckTimerEvent(usTime)) + usTime));
            return;
        }
    }

    DebugMessageSystem("No More Available Storage for Simultaneous Event!!!!!!", 0x00);
}

//--------------------------------------------------
// Description  : Reactive a timer for an event. If the event is exist,
//                this function will reset the executing time and restart.
// Input Value  : usTime    --> Unit in 1ms, range in 0.01 ~ 61 sec
//                Event     --> Execute Event while timeup
// Output Value : None
//--------------------------------------------------
void ScalerTimerReactiveTimerEvent(WORD usTime, BYTE ucEventID)
{
    BYTE ucEventIndex = 0;

    // Search for Existing Event with the same Event ID
    for(ucEventIndex = 0; ucEventIndex < _TIMER_EVENT_COUNT; ucEventIndex++)
    {
        if(GET_EVENT_VALID(ucEventIndex) == _TRUE)
        {
            if(GET_EVENT_ID(ucEventIndex) == ucEventID)
            {
                SET_EVENT_TIME(ucEventIndex, (WORD)((DWORD)(ScalerTimerCheckTimerEvent(usTime)) + usTime));
                return;
            }
        }
    }    

    // Choose any Vacant Storage for Event
    for(ucEventIndex = 0; ucEventIndex < _TIMER_EVENT_COUNT; ucEventIndex++)
    {
        if(GET_EVENT_VALID(ucEventIndex) == _FALSE)
        {
            SET_EVENT_VALID(ucEventIndex);
            SET_EVENT_ID(ucEventIndex, ucEventID);
            SET_EVENT_TIME(ucEventIndex, (WORD)((DWORD)(ScalerTimerCheckTimerEvent(usTime)) + usTime));
            return;
        }
    }   
}

//--------------------------------------------------
// Description  : Cancel an event
// Input Value  : Event     --> Event which we want to cancel
// Output Value : None
//--------------------------------------------------
void ScalerTimerCancelTimerEvent(BYTE ucEventID)
{
    BYTE ucEventIndex = 0;
    
    // Search for Existing Event with the same Event ID
    for(ucEventIndex = 0; ucEventIndex < _TIMER_EVENT_COUNT; ucEventIndex++)
    {
        if(GET_EVENT_VALID(ucEventIndex) == _TRUE)
        {
            if(GET_EVENT_ID(ucEventIndex) == ucEventID)
            {
                CLR_EVENT_VALID(ucEventIndex);
                return;
            }
        }
    }      
}

//--------------------------------------------------
// Description  : Check timer and events. We have to run this function when setting up a timer for an event.
// Input Value  : usTime    --> Unit in 1ms, range in 0.001 ~ 61sec
// Output Value : Return usPresentTime
//--------------------------------------------------
WORD ScalerTimerCheckTimerEvent(WORD usTime)
{
    BYTE ucTimerEventCnt = 0;
    WORD usPresentTime = 0;

    usPresentTime = ScalerTimerGetTimerCounter();
    
    if(usTime > _EVENT_TIME_MAX) 
    {
        usTime = _EVENT_TIME_MAX;
    }
   
    if(((usPresentTime + usTime) > _EVENT_TIME_MAX) || // Size Limit of Timer Counter             
       ((usPresentTime + usTime) < usPresentTime)) // Timer Counter Overflow
    { 
        g_usTimerCounter = 0;
    
        // Reset Timer Event Counter
        for(ucTimerEventCnt = 0; ucTimerEventCnt < _TIMER_EVENT_COUNT; ucTimerEventCnt++)
        {
            if(GET_EVENT_VALID(ucTimerEventCnt) == _TRUE)
            {
                if(GET_EVENT_TIME(ucTimerEventCnt) > usPresentTime)
                {
                    SET_EVENT_TIME(ucTimerEventCnt, (GET_EVENT_TIME(ucTimerEventCnt) - usPresentTime));
                }
                else
                {
                    SET_EVENT_TIME(ucTimerEventCnt, 0);
                }
            }
        }
        
        usPresentTime = 0;
    }    

    return usPresentTime;
}


//--------------------------------------------------
// Description  : Get Timer Counter.
// Input Value  : None
// Output Value : Timer Counter
//--------------------------------------------------
WORD ScalerTimerGetTimerCounter(void)
{
    WORD usPresentTime = g_usTimerCounter;
   
    // When get counter,timer interrupt maybe change counter.
    // Get twice to avoid it.
    if(abs(g_usTimerCounter - usPresentTime) > 0x7F)
    {
        usPresentTime = g_usTimerCounter;
    } 

    return usPresentTime;
}

//--------------------------------------------------
// Description  : Get Event ID
// Input Value  : Referenced Event Index
// Output Value : Stored Event ID
//--------------------------------------------------
BYTE ScalerTimerGetEventID(BYTE ucEventIndex)
{
    return GET_EVENT_ID(ucEventIndex);
}

//--------------------------------------------------
// Description  : Initial timer and events. We have to run this function at firmware startup
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTimerInitialTimerEvent(void)
{
    BYTE ucTimerEventCnt = 0;

    for(ucTimerEventCnt = 0; ucTimerEventCnt < _TIMER_EVENT_COUNT; ucTimerEventCnt++)
    {
        CLR_EVENT_VALID(ucTimerEventCnt);
    }

    TR2 = 1;
}

//--------------------------------------------------
// Description  : Timer Delay
// Input Value  : usNum --> Delay in ms
// Output Value : None
//--------------------------------------------------
void ScalerTimerDelayXms(WORD usNum)
{
    if(usNum)
    {
        g_bNotifyTimer2Int = _FALSE;

        while(_TRUE)
        {
            if(g_bNotifyTimer2Int)
            {
                g_bNotifyTimer2Int = _FALSE;

                if(--usNum)
                {
                }
                else
                {
                    return;
                }
            }
        }
    }
}

//----------------------------------------------------------------------
// Description  : Polling Scaler Flag Process
// Input Value  : ucTimeout --> Timeout number (Max: 255 ms)
//                ucRegister--> Current Register
//                ucBit     --> Polling Bit
//                bSuccess  --> 1 or 0 when finished for Polling Bit
// Output Value : Return _TRUE while polling success, _FALSE for timeout
//----------------------------------------------------------------------
bit ScalerTimerPollingFlagProc(WORD usTimeout, WORD ucRegister, BYTE ucBit, bit bSuccess)
{
    DWORD ulTimeTemp = 0;

    if((MCU_CTRL_FFED & _BIT1) == _BIT1) // CPU clock come from M2PLL, base on 24.3M
    {
        ulTimeTemp = _TIMER_POLLING_FLAG_TIMEOUT_ACTIVE * usTimeout;
    }
    else // CPU clock come from internal or external crystal clock, base on 3.5M
    {
        if((ScalerGetBit(CM_0B_POWER_CTRL2, _BIT0) == _BIT0) && (((MCU_CTRL_FFED & 0x3C) >> 2) == _FLASH_CLK_PS_FAST_DIV)) // 27MHz and flash clock div = 1 --> for DP Case
        {            
            ulTimeTemp = _TIMER_POLLING_FLAG_TIMEOUT_FAST_PS * usTimeout;
        }
        else
        {
            ulTimeTemp = _TIMER_POLLING_FLAG_TIMEOUT_PS * usTimeout;
        }
    }
    
    do
    {
        if(((bit)ScalerGetBit(ucRegister, ucBit) ^ bSuccess) == _FALSE)
        {
            return _TRUE;
        }
        
        Delay5us(g_ucDelay5usN);
    }
    while(--ulTimeTemp);

    return _FALSE;
}

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//----------------------------------------------------------------------
// Description  : Polling Scaler Flag Process
// Input Value  : ucTimeout --> Timeout number (Max: 255 ms)
//                ucRegister--> Current Register
//                ucBit     --> Polling Bit
//                bSuccess  --> 1 or 0 when finished for Polling Bit
// Output Value : Return _TRUE while polling success, _FALSE for timeout
//----------------------------------------------------------------------
bit ScalerTimerPollingDataBitFlagProc(WORD usTimeout, WORD usRegister, BYTE ucValue, BYTE ucBit, bit bSuccess)
{
    WORD usTimeElapsed = 0;
    WORD usPreviousTime = 0;

    usPreviousTime = g_usTimerCounter;

    do
    {
        if(((bit)ScalerGetDataPortBit(usRegister, ucValue, ucBit) ^ bSuccess) == _FALSE)
        {
            return _TRUE;
        }

        if(usPreviousTime != g_usTimerCounter)
        {
            usTimeElapsed++;
            usPreviousTime = g_usTimerCounter;
        }
    }
    while(usTimeElapsed <= usTimeout);

    return _FALSE;
}
#endif
//--------------------------------------------------
// Description  : Hold until the specified event occurs
// Input Value  : enumEvent   --> Specified event
// Output Value : Return _TRUE if event occurs
//--------------------------------------------------
bit ScalerTimerWaitForEvent(EnumWaitEventType enumEvent)
{
    WORD usTimeOutCnt = 0; 
    BYTE ucTemp = 0;

    if((enumEvent == _EVENT_DVS) || (enumEvent == _EVENT_DEN_START) || (enumEvent == _EVENT_DEN_STOP))
    {
        if(ScalerGetBit(CM_28_VDISP_CTRL, _BIT0) == 0x00)
        {
            return _FALSE;
        }
    }
    
    if((MCU_CTRL_FFED & _BIT1) == _BIT1) // CPU clock come from M2PLL, base on 24.3M
    {
        usTimeOutCnt = _TIMER_EVENT_TIMEOUT_ACTIVE;
    }
    else // CPU clock come from internal or external crystal clock, base on 3.5M
    {
        if((ScalerGetBit(CM_0B_POWER_CTRL2, _BIT0) == _BIT0) && (((MCU_CTRL_FFED & 0x3C) >> 2) == _FLASH_CLK_PS_FAST_DIV)) // 27MHz and flash clock div = 1 --> for DP Case
        {            
            usTimeOutCnt = _TIMER_EVENT_TIMEOUT_FAST_PS;
        }
        else
        {
            usTimeOutCnt = _TIMER_EVENT_TIMEOUT_PS;
        }
    }

    // Clear status (status register will be cleared after write)
    ScalerTimerClrEventStatus(_EVENT_ALL);

    do
    {
        Delay5us(g_ucDelay5usN);
        ucTemp = ScalerTimerGetEventStatus(enumEvent);
    }
    while((ucTemp == 0) && (--usTimeOutCnt != 0));

    return ((usTimeOutCnt != 0) && (ucTemp != 0)) ? _TRUE : _FALSE;
}

//--------------------------------------------------
// Description  : Check if Event is Valid
// Input Value  : ucEventID --> Event which has been activated
// Output Value : None
//--------------------------------------------------
void ScalerTimerWaitForActiveTimerEvent(BYTE ucEventID)
{
    BYTE ucEventIndex = 0;

    // Search Correponding EventID and wait until it finished
    for(ucEventIndex = 0; ucEventIndex < _TIMER_EVENT_COUNT; ucEventIndex++)
    {
        if(GET_EVENT_ID(ucEventIndex) == ucEventID)
        {
            if(GET_EVENT_VALID(ucEventIndex) == _TRUE)
            {
                if(ScalerTimerGetEventTime(ucEventIndex) > g_usTimerCounter)
                {
                    ScalerTimerDelayXms((ScalerTimerGetEventTime(ucEventIndex) - g_usTimerCounter));
                }
                               
                ScalerTimerCancelTimerEvent(ucEventID);
                return;
            }
        }
    }
}

//--------------------------------------------------
// Description  : Clear Event Status
// Input Value  : enumEvent   --> Specified event
// Output Value : None
//--------------------------------------------------
void ScalerTimerClrEventStatus(EnumWaitEventType enumEvent)
{
    ScalerSetBit(CM_03_STATUS1, ~enumEvent, 0x00);
}

//--------------------------------------------------
// Description  : Hold until the specified event occurs
// Input Value  : enumEvent   --> Specified event
// Output Value : Return _TRUE if event occurs
//--------------------------------------------------
BYTE ScalerTimerGetEventStatus(EnumWaitEventType enumEvent)
{
    return (ScalerGetByte(CM_03_STATUS1) & enumEvent);
}
