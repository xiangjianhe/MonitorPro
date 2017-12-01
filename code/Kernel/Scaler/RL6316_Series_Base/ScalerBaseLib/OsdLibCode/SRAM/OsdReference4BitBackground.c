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
// ID Code      : OsdReference4BitBackground.c
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
void ScalerReference4BitBackground(EnumOsd4BitBackgroundType EnumOsd4BitBackgroundType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : EnumOsd4BitBackgroundType -> _OSD_4BIT_BACKGROUND_TO_BYTE2 or _OSD_4BIT_BACKGROUND_TO_BYTE0
// Output Value :
//--------------------------------------------------
void ScalerReference4BitBackground(EnumOsd4BitBackgroundType EnumOsd4BitBackgroundType)
{
    BYTE ucTemp = 0;
    ucTemp = (ScalerOsdFrameControlByteGet(0x002, _OSD_BYTE1) & ~_BIT2) | ((BYTE)EnumOsd4BitBackgroundType << 2);
    ScalerOsdFrameControlByte(0x002, _OSD_BYTE1, ucTemp);
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerReference4BitBackground(_OSD_4BIT_BACKGROUND_TO_BYTE0);
*/


