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
// ID Code      : OsdSetColorPalette.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "OSD_Lib_Extern.h"

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
void ScalerOsdSetColorPalette(BYTE ucIndex, BYTE ucColorR, BYTE ucColorG, BYTE ucColorB);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Color Palette
// Input Value  : ucIndex  -> Which palette
//                ucColorR -> Palette red data   (0 ~ 255)
//                ucColorG -> Palette green data (0 ~ 255)
//                ucColorB -> Palette blue data  (0 ~ 255)
// Output Value : 
//--------------------------------------------------
void ScalerOsdSetColorPalette(BYTE ucIndex, BYTE ucColorR, BYTE ucColorG, BYTE ucColorB)
{
    ScalerSetByte(CM_6E_OVERLAY_LUT_ADDR, (0x80 | ucIndex));
    ScalerSetByte(CM_6F_COLOR_LUT_PORT, ucColorR);
    ScalerSetByte(CM_6F_COLOR_LUT_PORT, ucColorG);
    ScalerSetByte(CM_6F_COLOR_LUT_PORT, ucColorB);
    ScalerSetByte(CM_6E_OVERLAY_LUT_ADDR, 0x00);
}
