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
// ID Code      : RL6001_Series_Reg.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6001_SERIES_REG__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _NUM_FONT_WIDTH_4_SERIAL                3

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE ScalerEnableAccessPort(WORD usAddr, BYTE ucValue);
void ScalerDisableAccessPort(WORD usAddr);
void ScalerWrite(WORD usAddr, WORD usLength, BYTE *pArray, bit bAutoInc);
void ScalerRead(WORD usAddr, WORD usLength, BYTE *pArray, bit bAutoInc);
void ScalerSetDataPortByte(WORD usAddr, BYTE ucValue1, BYTE ucValue2);
void ScalerGetDataPortByte(WORD usAddr, BYTE ucValue, WORD usLength, BYTE *pArray, bit bAutoInc);
void ScalerSetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd, BYTE ucOr);
BYTE ScalerGetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd);
BYTE ScalerBurstWriteTimeoutCal(void);
void ScalerBurstWrite(BYTE *pAddress, WORD usWriteLength, BYTE ucBankNum, WORD usHostAddr, BYTE ucTableType, bit bTableLocation);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable Access Port
// Input Value  : usAddr    --> Start address of register
//                ucValue   --> Data Port Value we want to set
// Output Value : Return Access Port Value
//--------------------------------------------------
BYTE ScalerEnableAccessPort(WORD usAddr, BYTE ucValue)
{
    volatile BYTE xdata * pucAddr = (volatile BYTE xdata *)usAddr;
 
    if((usAddr == CM_24_SCALE_DOWN_ACCESS_PORT) || (usAddr == CM_33_SU_ACCESS_PORT))
    {
        *pucAddr |= _BIT7;
        ucValue = ucValue | (*pucAddr & 0xE0) | _BIT7;
    }
 
    if((usAddr == CM_60_HW_ACCESS_PORT) || (usAddr == CM_64_CB_ACCESS_PORT))
    {
        *pucAddr |= _BIT7;        
        ucValue = ucValue | (*pucAddr & 0xF0) | _BIT7;
    }
 
    if(usAddr == P7_D6_PKING_ACCESS_PORT)
    {
        *pucAddr |= _BIT7;        
        ucValue = ucValue | (*pucAddr & 0xF8) | _BIT7;
    }
    
    return ucValue;
}


//--------------------------------------------------
// Description  : Disable Access Port
// Input Value  : usAddr   --> Start address of register
// Output Value : None
//--------------------------------------------------
void ScalerDisableAccessPort(WORD usAddr)
{
    if((usAddr == CM_24_SCALE_DOWN_ACCESS_PORT) || (usAddr == CM_33_SU_ACCESS_PORT) 
    || (usAddr == CM_60_HW_ACCESS_PORT) || (usAddr == CM_64_CB_ACCESS_PORT)
    || (usAddr == P7_D6_PKING_ACCESS_PORT))
    {
        (*(BYTE xdata *)usAddr) &= ~_BIT7;
    }
}

//--------------------------------------------------
// Description  : Write a data array into registers
// Input Value  : usAddr    --> Start address of register
//                usLength  --> Numbers of data we want to write
//                pArray    --> Pointer of the writing data array
//                bAutoInc  --> Address auto increasing select
// Output Value : None
//--------------------------------------------------
void ScalerWrite(WORD usAddr, WORD usLength, BYTE *pArray, bit bAutoInc)
{
    WORD usIndex = 0;
    volatile BYTE xdata * pucAddr = (volatile BYTE xdata *)usAddr;

    if(usLength > 0)
    {
        if(bAutoInc == _AUTOINC)
        {
            memcpy(pucAddr, pArray, usLength);
        }
        else
        {
            for(usIndex = 0; usIndex < usLength; usIndex++)
            {
                *pucAddr = *(pArray + usIndex);
            }
        }
    }
}           

//--------------------------------------------------
// Description  : Read data from registers of scaler and put it into an reading data array
// Input Value  : usAddr    --> Start address of register
//                usLength  --> Numbers of data we want to read
//                pArray    --> Pointer of the reading data array
//                bAutoInc  --> Address auto increasing select
// Output Value : None
//--------------------------------------------------
void ScalerRead(WORD usAddr, WORD usLength, BYTE *pArray, bit bAutoInc)
{
    WORD usIndex = 0;
    volatile BYTE xdata * pucAddr = (volatile BYTE xdata *)usAddr;

    if(usLength > 0)
    {
        if(bAutoInc == _AUTOINC)
        {
            memcpy(pArray, pucAddr, usLength);
        }
        else
        {
            for(usIndex = 0; usIndex < usLength; usIndex++)
            {
                *(pArray + usIndex) = *pucAddr;
            }
        }
    }
}

//--------------------------------------------------
// Description  : Set the value into selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue1  --> Data Port Value we want to set
//                ucValue2  --> Data Value we want to set
// Output Value : None
//--------------------------------------------------
void ScalerSetDataPortByte(WORD usAddr, BYTE ucValue1, BYTE ucValue2)
{
    volatile BYTE xdata * pucAddr = (volatile BYTE xdata *)usAddr;

    *pucAddr = ScalerEnableAccessPort(usAddr, ucValue1);
    *(pucAddr + 1) = ucValue2;
    ScalerDisableAccessPort(usAddr);
}

//--------------------------------------------------
// Description  : Get bytes from selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue   --> Data Port Address we want to Get
//                ucLength  --> Numbers of data we want to read
//                pArray    --> Pointer of the reading data array
//                bAutoInc  --> Address auto increasing select
// Output Value : None
//--------------------------------------------------
void ScalerGetDataPortByte(WORD usAddr, BYTE ucValue, WORD usLength, BYTE *pArray, bit bAutoInc)
{
    BYTE ucAccessValue = 0;
    WORD usIndex = 0;
    volatile BYTE xdata * pucAddr = (volatile BYTE xdata *)usAddr;

    if(usLength > 0)
    {
        ucAccessValue = ScalerEnableAccessPort(usAddr, ucValue);

        for(usIndex = 0; usIndex < usLength; usIndex++)
        {
            if(bAutoInc == _AUTOINC)
            {
                *pucAddr = ucAccessValue + usIndex;
            }
            else
            {
                *pucAddr = ucAccessValue;
            }

            *(pArray + usIndex) = *(pucAddr + 1);
        }

        ScalerDisableAccessPort(usAddr);
    }
}

//--------------------------------------------------
// Description  : Set some bits of selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue   --> Data Port Value we want to set
//                ucAnd     --> & operation
//                ucOr      --> | operation
// Output Value : None
//--------------------------------------------------
void ScalerSetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd, BYTE ucOr)
{
    BYTE ucValueTemp = 0;
    volatile BYTE xdata * pucAddr = (volatile BYTE xdata *)usAddr;

    *pucAddr = ScalerEnableAccessPort(usAddr, ucValue);
    ucValueTemp = *(pucAddr + 1);

    ucValueTemp = (ucValueTemp & ucAnd) | ucOr;

    *pucAddr = ScalerEnableAccessPort(usAddr, ucValue);
    *(pucAddr + 1) = ucValueTemp;

    ScalerDisableAccessPort(usAddr);
}

//--------------------------------------------------
// Description  : Set some bits of selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue   --> Data Port Value we want to set
//                ucAnd     --> & operation
// Output Value : Value after & operation
//--------------------------------------------------
BYTE ScalerGetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd)
{
    BYTE ucValueTemp = 0;
    volatile BYTE xdata * pucAddr = (volatile BYTE xdata *)usAddr;

    *pucAddr = ScalerEnableAccessPort(usAddr, ucValue);
    ucValueTemp = (*(pucAddr + 1)) & ucAnd;
    ScalerDisableAccessPort(usAddr);

    return ucValueTemp;
}

//--------------------------------------------------
// Description  : Calculate OSD Burst Write Timeout
// Input Value  : 
// Output Value : Burst Write Required Time
//--------------------------------------------------
BYTE ScalerBurstWriteTimeoutCal(void)
{
    BYTE ucData[2];

    ucData[0] = 0;
    ucData[1] = 0;    
        
    // time of mcu write cycle > 5.5 Tm2pll/2 +   4 * ( Tm2pll/2 +   (8 + 4 * _NUM_FONT_WIDTH_4_SERIAL)* Tdclk + 3.5 * Tm2pll/2)
    // ====> Tm2pll * FlashDiv * McuDiv * (0xFFFB * 2 + 4) > 11 * Tm2pll + 8 * Tm2pll + (32 + 16 *_NUM_FONT_WIDTH_4_SERIAL) * Tdclk + 28 * Tm2pll
    // ====> 0xFFFB > 47 / (2 * _FLASH_CLK_DIV * _MCU_CLK_DIV) + (16 + 8 *_NUM_FONT_WIDTH_4_SERIAL) * Tdclk / (_FLASH_CLK_DIV * _MCU_CLK_DIV * Tm2pll) - 2
    ((WORD *)ucData)[0] = (47 + ((WORD)2 * _FLASH_CLK_DIV * _MCU_CLK_DIV) - 1) / ((WORD)2 * _FLASH_CLK_DIV * _MCU_CLK_DIV) +
                          (((DWORD)16 + 8 * _NUM_FONT_WIDTH_4_SERIAL) * _M2PLL_CLK_MHZ + ((DWORD)_FLASH_CLK_DIV * _MCU_CLK_DIV * _PANEL_PIXEL_CLOCK_MIN - 1)) / ((DWORD)_FLASH_CLK_DIV * _MCU_CLK_DIV * _PANEL_PIXEL_CLOCK_MIN) - 1;

    if(((WORD *)ucData)[0] > 255)
    {
        ucData[0] = 255;
    }
    else
    {
        ucData[0] = ucData[1];
    }

    return ucData[0];
}

//--------------------------------------------------
// Description  : Set some bits of selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue   --> Data Port Value we want to set
//                ucAnd     --> & operation
// Output Value : Value after & operation
//--------------------------------------------------
void ScalerBurstWrite(BYTE *pAddress, WORD usWriteLength, BYTE ucBankNum, WORD usHostAddr, BYTE ucTableType, bit bTableLocation)
{
    BYTE ucTimeOut = 100;
    
    ScalerSetByte(CM_9F_PAGE_SEL, HIBYTE(usHostAddr));
    
    if(bTableLocation == _BURSTWRITE_FROM_XRAM)
    {
        ScalerWrite(usHostAddr, usWriteLength, pAddress, _NON_AUTOINC);
        return;
    }   

    // Disable burst write data and burst write command function.
    MCU_SCA_INF_CTRL_FFF3 &= 0xE7;

    if((ucTableType == _BURSTWRITE_DATA_COMMON) || (ucTableType == _BURSTWRITE_DATA_OSD))
    {
        MCU_SCA_INF_ADDR_FFF4 = usHostAddr;
    }
        
    MCU_SCA_INF_BWR_ADRH_FFF6 = ucBankNum;

    MCU_SCA_INF_BWR_ADRM_FFF7 = (BYTE)((((WORD)pAddress) & 0xFF00) >> 8);
    MCU_SCA_INF_BWR_ADRL_FFF8 = (BYTE)((((WORD)pAddress) & 0x00FF));

    MCU_SCA_INF_BWR_COUNT_H_FFF9 = (BYTE)(((usWriteLength) & 0xFF00) >> 8);
    MCU_SCA_INF_BWR_COUNT_L_FFFA = (BYTE)(((usWriteLength) & 0x00FF));

    if(ucTableType == _BURSTWRITE_DATA_OSD)
    {
        BYTE ucData = 0;
        
        ucData = ScalerBurstWriteTimeoutCal();
        
        if(ucData >= 2)
        {
            // Set the interval between two command for OSD Load Font data.
            MCU_SCA_INF_PERIOD_FFFB = ucData;
        }
        else
        {
            MCU_SCA_INF_PERIOD_FFFB = 0x02;
        }
    }
    else
    {
        MCU_SCA_INF_PERIOD_FFFB = 0x03;
    }

    if(ucTableType == _BURSTWRITE_COMMAND)
    {
        // Enable burst write command function, enable the function of releasing mcu by interrupt.
        MCU_SCA_INF_CTRL_FFF3 = 0x10;
	
        while(((MCU_SCA_INF_CTRL_FFF3 & _BIT4) == _BIT4) && (--ucTimeOut > 0))
        {
            // Restart Burst Write When Interrupted
            MCU_SCA_INF_CTRL_FFF3 |= _BIT4;
        }
    }
    else  // _BURSTWRITE_DATA_COMMON/OSD
    {
        // Enable burst write data function, disable auto address increase, enable the function of releasing mcu by interrupt.
        MCU_SCA_INF_CTRL_FFF3 = 0x28;

        while(((MCU_SCA_INF_CTRL_FFF3 & _BIT3) == _BIT3) && (--ucTimeOut > 0))
        {
            // Restart Burst Write When Interrupted
            MCU_SCA_INF_CTRL_FFF3 |= _BIT3;
        }
    }
}
