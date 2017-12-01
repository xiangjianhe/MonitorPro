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
// ID Code      : Osd2BitFontByte1Bit7Swap.c
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
void ScalerOsd2BitFontByte1Bit7Swap(EnumOsd2BitCharBit7Type enumOsd2BitCharBit7Type);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : enumOsd2BitCharBit7Type -> _OSD_2BIT_CHAR_BIT7_BY_CHANGE_PALETTE or _OSD_2BIT_CHAR_BIT7_BY_CHANGE_COLOR
// Output Value :
//--------------------------------------------------
void ScalerOsd2BitFontByte1Bit7Swap(EnumOsd2BitCharBit7Type enumOsd2BitCharBit7Type)
{
    BYTE ucTemp = 0;

    ucTemp = (ScalerOsdFrameControlByteGet(0x011, _OSD_BYTE0) & ~(_BIT3)) | (BYTE)enumOsd2BitCharBit7Type << 3;
    ScalerOsdFrameControlByte(0x011, _OSD_BYTE0, ucTemp);
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsd2BitFontByte1Bit7Swap(_OSD_2BIT_CHAR_BIT7_BY_SELECT_FONT);
*/

