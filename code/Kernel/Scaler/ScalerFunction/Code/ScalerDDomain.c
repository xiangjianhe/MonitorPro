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
// ID Code      : ScalerDDomain.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_DDOMAIN__

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
#if(_PANEL_EXIST_MULTIPANEL == _ON)
BYTE g_ucDDomainPanelIndex = 0;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerDDomainBackgroundEnable(bit bEnable);
void ScalerDDomainBackgroundSetColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue);
void ScalerDDomainPatternGenEnable(bit bEnable);
void ScalerDDomainPatternGenAdjustColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue);

#if(_OCC_SUPPORT == _ON)  
void ScalerDDomainPatternGenShowBatch7Pattern(BYTE ucRed, BYTE ucGreen, BYTE ucBlue); 
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Display Force to Background Enable
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDDomainBackgroundEnable(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Enable Force to Back Ground
        ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT5, _BIT5);
    }
    else
    {
        // Disable Force to Back Ground
        ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT5, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set Display Background Color
// Input Value  : RGB Color
// Output Value : None
//--------------------------------------------------
void ScalerDDomainBackgroundSetColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue)
{
    // Reset Port index
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT5, 0x00);    
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT5, _BIT5);

    ScalerSetByte(CM_6D_BGND_COLOR_CTRL, ucRed);
    ScalerSetByte(CM_6D_BGND_COLOR_CTRL, ucGreen);
    ScalerSetByte(CM_6D_BGND_COLOR_CTRL, ucBlue);    

    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT5, 0x00);        
}

//--------------------------------------------------
// Description  : Display Pattern Gen Enable
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDDomainPatternGenEnable(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Enable D Domain PG
        ScalerSetBit(P7_F0_DISP_PG_R_CTRL, ~_BIT7, _BIT7);
    }
    else
    {
        // Disable D Domain PG
        ScalerSetBit(P7_F0_DISP_PG_R_CTRL, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set Display Pattern Gen Color
// Input Value  : RGB Color
// Output Value : None
//--------------------------------------------------
void ScalerDDomainPatternGenAdjustColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue)
{
    ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, ucRed);
    ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, ucGreen);
    ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, ucBlue);
    ScalerSetBit(P7_FC_DISP_PG_INITIAL_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00); 
}

#if(_OCC_SUPPORT == _ON)      
//--------------------------------------------------
// Description  : Show OCC Patterns
// Input Value  : RGB Color
// Output Value : None
//--------------------------------------------------
void ScalerDDomainPatternGenShowBatch7Pattern(BYTE ucRed, BYTE ucGreen, BYTE ucBlue)
{
    ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, ucRed);
    ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, ucGreen);
    ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, ucBlue);
    ScalerSetByte(P7_F0_DISP_PG_R_CTRL, 0x80); 
    ScalerSetByte(P7_F1_DISP_PG_G_CTRL, 0x80);
    ScalerSetByte(P7_F2_DISP_PG_B_CTRL, 0x80);
}
#endif  // End of #if(_OCC_SUPPORT == _ON)

