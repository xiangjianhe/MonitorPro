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
// ID Code      : ScalerPower.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_POWER__

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
void ScalerPowerXtalPower(BYTE ucOn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Xtal Power Control.
// Input Value  : ucOn    --> On/Off Select.
// Output Value : None
//--------------------------------------------------
void ScalerPowerXtalPower(BYTE ucOn)
{   
    if(ucOn == _ON)
    {
        if(ScalerGetBit(CM_09_POWER_CTRL0, _BIT2) == _BIT2)
        { 
            // Bit0~1 : 00 --> XI/XO Pad Driving to Strong
            ScalerSetBit(P0_F3_POWER_ON_RESET, ~(_BIT1 | _BIT0), 0x00);

            // Power On External Xtal 
            ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT2, 0x00);

            // Waiting for xtal stable.
            ScalerTimerDelayXms(6);
        }

        // Bit0~1 : 00 --> XI/XO Pad Driving to weak
        ScalerSetBit(P0_F3_POWER_ON_RESET, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
    }
    else
    {
        // Power down External Xtal 
        ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT2, _BIT2);

        // Bit0~1 : 00 --> XI/XO Pad Driving to weak
        ScalerSetBit(P0_F3_POWER_ON_RESET, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
    }
}
