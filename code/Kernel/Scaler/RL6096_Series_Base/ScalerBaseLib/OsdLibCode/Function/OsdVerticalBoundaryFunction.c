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
// ID Code      : OsdVerticalBoundaryFunction.c
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
void ScalerOsdVerticalBoundary(bit bEnable);
void ScalerOsdVerticalBoundarySize(WORD usUpperBoundary, WORD usLowerBoundary);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set vertical boundary function
// Input Value  : bEnable   -> _ENABLE or _DISABLE
// Output Value :  
//--------------------------------------------------
void ScalerOsdVerticalBoundary(bit bEnable)
{
    BYTE ucTemp = 0;

    ucTemp = ((ScalerOsdFrameControlByteGet(0x008, _OSD_BYTE0) & ~_BIT5) | (BYTE)bEnable << 5);
    ScalerOsdFrameControlByte(0x008, _OSD_BYTE0, ucTemp);        
}


/* 
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdVerticalBoundary(_ENABLE);
*/


//--------------------------------------------------
// Description  : Set vertical boundary size
// Input Value  : usUpperBoundary -> 0 ~ 2047
//                usLowerBoundary -> 0 ~ 2047
// Output Value :  
//--------------------------------------------------
void ScalerOsdVerticalBoundarySize(WORD usUpperBoundary, WORD usLowerBoundary)
{
    BYTE ucTemp[3] = 0;

    ucTemp[0] = HIBYTE(usUpperBoundary) << 4 | HIBYTE(usLowerBoundary);
    ucTemp[1] = LOBYTE(usUpperBoundary);
    ucTemp[2] = LOBYTE(usLowerBoundary);

    ScalerOsdFrameControlAllByte(0x00A, _OSD_WITHOUT_DB, ucTemp[0], ucTemp[1], ucTemp[2]);
}


/* 
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdVerticalBoundarySize(YSTART(100), YEND(1000));
*/

