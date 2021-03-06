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
// ID Code      : RL6213_Series_LDO.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6213_SERIES_LDO__

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
void ScalerLDOPowerControl(EnumPowerStatus enumPorStatus);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : LDO Power Control.
// Input Value  : ucPorStatus    --> _POWER_STATUS_NORMAL/_POWER_STATUS_SAVING/_POWER_STATUS_OFF Select.
// Output Value : None
//--------------------------------------------------
void ScalerLDOPowerControl(EnumPowerStatus enumPorStatus)
{  
    // Check LDO bounding option
    if(ScalerGetBit(CM_0B_POWER_CTRL2, _BIT2) == _BIT2)
    {
        // Set LDO voltage = 1.2V
        ScalerSetBit(P0_DF_EBD_REGLATOR_A_CTRL, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);

        switch(enumPorStatus)
        {
            case _POWER_STATUS_NORMAL:
                // Set opamp current to normal
                ScalerSetBit(P0_DF_EBD_REGLATOR_A_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x00);
                
                // Disconnect LDO_A and LDO_D
                ScalerSetBit(P0_DF_EBD_REGLATOR_A_CTRL, ~_BIT6, 0x00);
                
                // Set to LDO max driving current, it is necessary to set register bit by bit
                ScalerSetBit(P0_E0_EBD_REGLATOR_DB_CTRL, ~_BIT2, _BIT2);
                ScalerSetBit(P0_E0_EBD_REGLATOR_DB_CTRL, ~_BIT0, _BIT0);
                
                break;
                
            case _POWER_STATUS_OFF:
            case _POWER_STATUS_SAVING:
                // Connect LDO_A and LDO_D
                ScalerSetBit(P0_DF_EBD_REGLATOR_A_CTRL, ~_BIT6, _BIT6);
                
                // Set opamp current to 1/10
                ScalerSetBit(P0_DF_EBD_REGLATOR_A_CTRL, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT3));
                
                // Set to LDO min driving current
                ScalerSetBit(P0_E0_EBD_REGLATOR_DB_CTRL, ~_BIT0, 0x00);
                
                break;

            default:
                 break;
        }
    }
}

