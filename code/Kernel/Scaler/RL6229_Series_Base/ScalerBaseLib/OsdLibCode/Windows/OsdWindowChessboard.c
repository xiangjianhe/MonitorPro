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
// ID Code      : OsdWindowChessboard.c
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
void ScalerOsdWindowChessboard(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ChessBoardColor1, BYTE ChessBoardColor2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window 6 Special function
// Input Value  : bEnable            -> _ENABLE or _DISABLE
//                enumOsdWindowsType -> _OSD_WINDOW_8   or _OSD_WINDOW_9   or _OSD_WINDOW_4_1 or _OSD_WINDOW_4_2 or _OSD_WINDOW_4_3 or
//                                      _OSD_WINDOW_4_4 or _OSD_WINDOW_4_5 or _OSD_WINDOW_4_6 or _OSD_WINDOW_4_7 or _OSD_WINDOW_4_8 
//                ChessBoardColor1   -> Color (0 ~ 63)
//                ChessBoardColor2   -> Color (0 ~ 63)
// Output Value :  
//--------------------------------------------------
void ScalerOsdWindowChessboard(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ChessBoardColor1, BYTE ChessBoardColor2)
{
    WORD usTemp = 0;

    if((enumOsdWindowsType == _OSD_WINDOW_8) || (enumOsdWindowsType == _OSD_WINDOW_9))
    {
        usTemp = 0x161 + (enumOsdWindowsType - _OSD_WINDOW_8) * 2;
    }
    else
    {
        usTemp = 0x164 + (enumOsdWindowsType - _OSD_WINDOW_4_1) * 2;
    }

    ScalerOsdFrameControlAllByte(usTemp, _OSD_WITHOUT_DB, (BYTE)bEnable << 7, ChessBoardColor1, ChessBoardColor2);
}


/* 
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdWindowChessboard(_ENABLE, _OSD_WINDOW_4_1, 0, 8);
*/
