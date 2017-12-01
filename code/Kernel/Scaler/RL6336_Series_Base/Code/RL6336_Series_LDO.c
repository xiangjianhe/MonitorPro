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
// ID Code      : RL6336_Series_LDO.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6336_SERIES_LDO__

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
bit ScalerLDOPC99PowerDetect(BYTE ucPowerStatus);


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
        switch(enumPorStatus)
        {
            case _POWER_STATUS_NORMAL:

                // Set LDO_A opamp current to normal; Set LDO voltage = 1.2V
                ScalerSetBit(P0_DF_EBD_REGLATOR_A_CTRL, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);

                // Set LDO_D opamp current to normal; Set to LDO_D max driving current; Set LDO_D ref. LDO_A
                ScalerSetBit(P0_E0_EBD_REGLATOR_DB_CTRL, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT2 | _BIT1));

                break;

            case _POWER_STATUS_OFF:
            case _POWER_STATUS_SAVING:

                // Set LDO_A opamp current to 1/14; Set LDO voltage = 1.2V
                ScalerSetBit(P0_DF_EBD_REGLATOR_A_CTRL, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

                // Set LDO_D opamp current to 1/14; Set to LDO_D min driving current; Set LDO_D ref. LDO_A
                ScalerSetBit(P0_E0_EBD_REGLATOR_DB_CTRL, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT5 | _BIT4 | _BIT3 | _BIT1));

                break;

            default:

                 break;
        }
    }
}

//--------------------------------------------------
// Description  : Detect for PCB 5V & turn off PC99 LDO
// Input Value  : None
// Output Value : _TRUE
//--------------------------------------------------
bit ScalerLDOPC99PowerDetect(BYTE ucPowerStatus)
{
    if(ucPowerStatus == _POWER_STATUS_AC_ON)
    {

#if(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
        if(PCB_POWER_5V_LEVEL() < PCB_POWER_5V_THRESHOLD)
        {
            // Toggle HDMI HPD for EDID compatibility under PC99 mode
            PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
            ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
            PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
        }
#endif

        while(PCB_POWER_5V_LEVEL() < PCB_POWER_5V_THRESHOLD)
        {
            ScalerDebug();
        }

        // Turn off PC99 LDO
        ScalerSetBit(P2B_A4_PC99_CTRL5, ~(_BIT1 | _BIT0), _BIT1);
    }

    return _TRUE;
}