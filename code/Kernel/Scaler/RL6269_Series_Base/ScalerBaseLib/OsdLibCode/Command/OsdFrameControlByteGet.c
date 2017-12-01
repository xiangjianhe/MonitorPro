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
// ID Code      : OsdFrameControlByteGet.c
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
BYTE ScalerOsdFrameControlByteGet(WORD usAddr, EnumOsdWriteType enumOsdWriteType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get OSD Frame Control Byte
// Input Value  : usAddr           -> FramControl address
//                enumOsdWriteType -> _OSD_BYTE0 or _OSD_BYTE1 or _OSD_BYTE2 or _OSD_BYTEALL 
// Output Value : FrameControl Value
//--------------------------------------------------
BYTE ScalerOsdFrameControlByteGet(WORD usAddr, EnumOsdWriteType enumOsdWriteType)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, (enumOsdWriteType & 0xf0) | (BYTE)(usAddr>>8 & 0x0f));
    ScalerSetByte(CM_91_OSD_ADDR_LSB, (BYTE)usAddr);
    return ScalerGetByte(CM_92_OSD_DATA_PORT);
}
