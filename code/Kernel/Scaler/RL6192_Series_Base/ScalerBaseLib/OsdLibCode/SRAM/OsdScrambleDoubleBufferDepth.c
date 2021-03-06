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
// ID Code      : OsdScrambleDoubleBufferDepth.c
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
void ScalerOsdScrambleDoubleBufferDepth(BYTE ucValue);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : OSD Scramble Double Buffer Depth
// Input Value  : ucValue -> 1 ~ 6
// Output Value : 
//--------------------------------------------------
void ScalerOsdScrambleDoubleBufferDepth(BYTE ucValue)
{
    WORD usTemp = 0;

    usTemp = ScalerGetByte(CM_93_OSD_SCRAMBLE);
    usTemp = (usTemp & 0xF8) | (((ucValue == 0) ? 0 : (ucValue - 1)) & 0x07);

    ScalerSetByte(CM_93_OSD_SCRAMBLE, usTemp);
}



