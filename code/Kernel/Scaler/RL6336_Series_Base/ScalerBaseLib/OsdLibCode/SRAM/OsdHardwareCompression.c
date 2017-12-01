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
// ID Code      : OsdHardwareCompression.c
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
void ScalerOsdHardwareCompression(BYTE *pArray, WORD usVLCTableSize, BYTE ucBankNum, WORD usOffset, WORD usFontTableStart, EnumOsdRotateType enumOsdRotateType, bit bTableLocation);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Osd Load Hardware VLC
// Input Value  : *pArray          -> VLC table
//                usVLCTableSize   -> Use VLC_TABLE_SIZE(VLC table)
//                ucBankNum        -> Bank number (GET_CURRENT_BANK_NUMBER())
//                usOffset         -> Font address
//                usFontTableStart -> Font base address
//                ucOsdRotateType  -> _OSD_ROTATE_DEGREE_0 or _OSD_ROTATE_DEGREE_90 or _OSD_ROTATE_DEGREE_270
//                bTableLocation   -> 
// Output Value : 
//--------------------------------------------------
void ScalerOsdHardwareCompression(BYTE *pArray, WORD usVLCTableSize, BYTE ucBankNum, WORD usOffset, WORD usFontTableStart, EnumOsdRotateType enumOsdRotateType, bit bTableLocation)
{
    BYTE xdata ucVlcType = 0x00;
    
    if(enumOsdRotateType == _OSD_ROTATE_DEGREE_90)
    {
        ucVlcType = _OSD_ROTATE_CW | _OSD_ROTATE_HARDWARE_ROTATION_ENABLE | _OSD_ROTATE_ROTATION;
    }
    else if(enumOsdRotateType == _OSD_ROTATE_DEGREE_270)
    {
        ucVlcType = _OSD_ROTATE_CCW | _OSD_ROTATE_HARDWARE_ROTATION_ENABLE | _OSD_ROTATE_ROTATION;
    }
    else
    {
        ucVlcType = _OSD_ROTATE_NO_SWAP;
    }

    // rotation
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, ucVlcType);       // Rotation

    // osd compression enable
    if(enumOsdRotateType != _OSD_ROTATE_DEGREE_0)
    {
        ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, (_OSD_DECODE_NON_COMPRESSED | _OSD_COMPRESSION_ENABLE));
    }
    else
    {
        ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, (_OSD_DECODE_NON_COMPRESSED | _OSD_COMPRESSION_DISABLE));
    }

    usFontTableStart = usFontTableStart + usOffset * 9;
    
    ScalerOsdSramAddressSet(usFontTableStart, _OSD_BYTEALL);

    ScalerOsdBurstWriteDataPort(pArray, usVLCTableSize, ucBankNum, _BURSTWRITE_DATA_OSD, bTableLocation);

    // OSD HW needs time to process it and then write decompressed data into SRAM.
    // The value 1ms is enough at all.
    ScalerTimerDelayXms(1);    
    
    // osd compression disable
    ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, (_OSD_DECODE_COMPRESSED | _OSD_COMPRESSION_DISABLE));

    if(enumOsdRotateType != _OSD_ROTATE_DEGREE_0)
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, _OSD_ROTATE_ROTATION);
    }
    else
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, _OSD_ROTATE_NORMAL);
    }
}

