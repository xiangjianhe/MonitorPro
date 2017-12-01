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
// ID Code      : OsdSramAddressCount.c
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
BYTE ucColAMax = 0;
BYTE ucColBMax = 0;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerOsdSramAddressCount(BYTE ucRow, BYTE ucCol, EnumOsdWriteType enumOsdWriteType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : ucRow. ucCol.     -> Just that !!
//                enumOsdWriteType  -> _OSD_BYTE0 or _OSD_BYTE1 or _OSD_BYTE2
// Output Value :
//--------------------------------------------------
void ScalerOsdSramAddressCount(BYTE ucRow, BYTE ucCol, EnumOsdWriteType enumOsdWriteType)
{
    WORD xdata ucCharCommandStartAddress = 0;
    BYTE xdata ucColSize = 0;
    BYTE xdata ucByte0 = 0;
    BYTE xdata ucByte1 = 0;
    BYTE xdata ucByte2 = 0;

    if((ScalerOsdFrameControlByteGet(0x008, _OSD_BYTE0) & _BIT3) == _BIT3)
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, (_OSD_BYTEALL & 0xf0) | 0x00);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x09);
        ucByte0 = ScalerGetByte(CM_92_OSD_DATA_PORT);
        ucByte1 = ScalerGetByte(CM_92_OSD_DATA_PORT);
        ucByte2 = ScalerGetByte(CM_92_OSD_DATA_PORT);

        if(ucRow >= _OSD_MAP_B_ROW_OFFSET)
        {
            ucRow -= _OSD_MAP_B_ROW_OFFSET;
            ucColSize = GET_OSD_MAPB_COL_MAX();
            ucCharCommandStartAddress = ((ucByte0 & 0x0F) << 8) | ucByte2;
        }
        else
        {
            ucColSize = GET_OSD_MAPA_COL_MAX();
            ucCharCommandStartAddress = ((ucByte0 & 0xF0) << 4) | ucByte1;
        }
    }
    else
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, (_OSD_BYTEALL & 0xf0) | 0x00);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x04);
        ucByte0 = ScalerGetByte(CM_92_OSD_DATA_PORT);
        ucByte1 = ScalerGetByte(CM_92_OSD_DATA_PORT);
        ucByte2 = ScalerGetByte(CM_92_OSD_DATA_PORT);
        ucColSize = GET_OSD_MAPA_COL_MAX();

        ucCharCommandStartAddress = ((ucByte1 & 0xF0) << 4) | ucByte0;
    }

    ucCharCommandStartAddress = ucCharCommandStartAddress + (ucRow * ucColSize) + ucCol;

    ScalerSetBit(CM_93_OSD_SCRAMBLE, ~_BIT3, (ucCharCommandStartAddress & 0x1000) >> 9);
    ScalerOsdAddrMsb((HIBYTE(ucCharCommandStartAddress) & 0x000f) | _OSD_SRAM | enumOsdWriteType);
    ScalerOsdAddrLsb(LOBYTE(ucCharCommandStartAddress));
}


