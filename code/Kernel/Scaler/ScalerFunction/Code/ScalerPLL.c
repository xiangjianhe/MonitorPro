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
// ID Code      : ScalerPLL.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_PLL__

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
#if(_VGA_SUPPORT == _ON)
WORD g_usPhaseDelayTime = 0x00;
#endif


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerPllM2PLLPower(BYTE ucOn);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : M2PLL Power COntrol.
// Input Value  : ucOn    --> ON/OFF.
// Output Value : None
//--------------------------------------------------
void ScalerPllM2PLLPower(BYTE ucOn)
{  
    BYTE ucCount1ms = 0;
    
    if(ucOn == _ON)
    {
        // In fact, we can move the m/n code setting to scaler initial
        // Set M2PLL M Code
        ScalerSetByte(P1_E0_M2PLL_M, (_M2PLL_PLL_M - 2));

        // Set M2PLL N Code
        ScalerSetByte(P1_E1_M2PLL_N, (((_M2PLL_PLL_O >> 1) << 4) | (_M2PLL_PLL_N - 2)));

        // Set Rs, Cs, Icp
        ScalerSetByte(P1_E4_M2PLL_CRNT, 0x73);

        // Power On M2PLL
        ScalerSetBit(P1_E5_M2PLL_WD, ~_BIT0, 0x00);

        // Wait for M2PLL Stable (1ms)
        while((++ucCount1ms) < _INTERNAL_OSC_XTAL / (17 * 4 * (_FLASH_CLK_PS_DIV * _MCU_CLK_PS_DIV)))
        {
            _nop_();
            _nop_();
            _nop_();
            _nop_();
        }
    }
    else
    {        
        // Power Off M2PLL
        ScalerSetBit(P1_E5_M2PLL_WD, ~_BIT0, _BIT0);
    }
}
