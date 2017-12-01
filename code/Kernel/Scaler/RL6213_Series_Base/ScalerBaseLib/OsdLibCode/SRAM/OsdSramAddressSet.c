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
// ID Code      : OsdSramAddressSet.c
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
void ScalerOsdSramAddressSet(WORD usSramAddress, EnumOsdWriteType enumOsdWriteType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : usSramAddress -> SRAM address
//                enumOsdWriteType    -> _OSD_BYTE0 or _OSD_BYTE1 or _OSD_BYTE2 or _OSD_BYTEALL 
// Output Value :
//--------------------------------------------------
void ScalerOsdSramAddressSet(WORD usSramAddress, EnumOsdWriteType enumOsdWriteType)
{
    ScalerSetBit(CM_93_OSD_SCRAMBLE, ~_BIT3, (usSramAddress & 0x1000) >> 9);
    ScalerOsdAddrMsb((HIBYTE(usSramAddress) & 0x000f) | _OSD_SRAM | enumOsdWriteType);
    ScalerOsdAddrLsb(LOBYTE(usSramAddress));
}


