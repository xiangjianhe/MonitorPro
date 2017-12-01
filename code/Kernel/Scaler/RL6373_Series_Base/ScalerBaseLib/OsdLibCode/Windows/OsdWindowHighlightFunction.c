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
// ID Code      : OsdWindowHighlightFunction.c
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
void ScalerOsdWindowHighlightFunction(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ucForegroundColor, BYTE BackgroundColor, BYTE CharactorBorderColor);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window highlight function
// Input Value  : bEnable              -> _ENABLE or _DISABLE
//                enumOsdWindowsType   -> _OSD_WINDOW_4_1 or _OSD_WINDOW_4_2 or _OSD_WINDOW_4_3
//                ucForegroundColor    -> 0 ~ 63
//                BackgroundColor      -> 0 ~ 63
//                CharactorBorderColor -> 0 ~ 63
// Output Value :  
//--------------------------------------------------
void ScalerOsdWindowHighlightFunction(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ucForegroundColor, BYTE BackgroundColor, BYTE CharactorBorderColor)
{
    ScalerOsdFrameControlAllByte(0x00E + (enumOsdWindowsType - _OSD_WINDOW_4_1), _OSD_WITHOUT_DB, (ucForegroundColor | (BYTE)bEnable << 6), BackgroundColor, CharactorBorderColor);
}


/* 
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdWindowHighlightFunction(_ENABLE, _OSD_WINDOW_4_1, 1, 3, 5);
*/


