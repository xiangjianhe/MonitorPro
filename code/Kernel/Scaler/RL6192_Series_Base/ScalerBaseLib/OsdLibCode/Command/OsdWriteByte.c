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
// ID Code      : OsdWriteByte.c
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
void ScalerOsdWriteByte(BYTE ucIndicate, WORD usAddr, BYTE ucData);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Write Byte
// Input Value  : ucIndicate -> CM_90_OSD_ADDR_MSB Hight Byte 
//                usAddr     -> SRAM address
//                ucData     -> ucIndicate's Data
// Output Value : 
//--------------------------------------------------
void ScalerOsdWriteByte(BYTE ucIndicate, WORD usAddr, BYTE ucData)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, (ucIndicate & 0xf0) | (BYTE)(usAddr>>8 & 0x0f));
    ScalerSetByte(CM_91_OSD_ADDR_LSB, (BYTE)usAddr);
    ScalerSetByte(CM_92_OSD_DATA_PORT, ucData);
}
