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
// ID Code      : RL6316_Series_Global.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6316_SERIES_GLOBAL__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

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
void ScalerGlobalSystemClkSel(EnumClkSel enumClockSel);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Internal Clock Selection.
// Input Value  : bSel    --> _TRUE: Xtal, _FALSE: M2PLL.
// Output Value : None
//--------------------------------------------------
void ScalerGlobalSystemClkSel(EnumClkSel enumClockSel)
{
    if(enumClockSel == _M2PLL_CLK)
    {
        // System clock select to M2PLL/div.
        ScalerM2PLLDiv(_DIV_9);
        
        // Bit2: Internal Xtal Freq. Select to M2PLL/div
        ScalerSetBit(CM_22_FIFO_FREQUENCY, ~_BIT2, _BIT2);

        // SyncProcessor Clock Divider
        ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_0A_DEVS_CAP_NUM_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT4));

        // Sync Processor Clock select to M2PLL
        ScalerSetBit(CM_4C_VSYNC_COUNTER_LEVEL_MSB, ~_BIT3, _BIT3);
    }
    else
    {
        // Internal Xtal Freq. Select to cystal.
        ScalerSetBit(CM_22_FIFO_FREQUENCY, ~_BIT2, 0x00);

        // Sync Processor Clock select to Xtal
        ScalerSetBit(CM_4C_VSYNC_COUNTER_LEVEL_MSB, ~_BIT3, 0x00);
    }
}

