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
// ID Code      : OsdFrameControlAllByte.c
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
void ScalerOsdFrameControlAllByte(WORD usAddr, BYTE ucDoubleBuffer, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Frame Control All Byte
// Input Value  : usAddr         -> FramControl address
//                ucDoubleBuffer -> _OSD_WITHOUT_DB or _OSD_WITH_DB
//                ucByte0        -> Byte0 Data
//                ucByte1        -> Byte1 Data
//                ucByte2        -> Byte2 Data
// Output Value : 
//--------------------------------------------------
void ScalerOsdFrameControlAllByte(WORD usAddr, BYTE ucDoubleBuffer, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2)
{
    ScalerOsdWriteAllByte(_OSD_WF_CONTROL | _OSD_BYTEALL | ucDoubleBuffer, usAddr, ucByte0, ucByte1, ucByte2);
}
