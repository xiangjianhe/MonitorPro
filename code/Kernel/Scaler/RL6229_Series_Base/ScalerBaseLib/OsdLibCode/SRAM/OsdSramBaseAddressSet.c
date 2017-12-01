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
// ID Code      : OsdSramBaseAddressSet.c
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
void ScalerOsdSramBaseAddressSet(EnumOsdMapType enumOsdMapType, WORD ucRowCommandStart, WORD ucCharactorCommandStart, WORD ucFontStart);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Row command & Charactor command & Font base address
// Input Value  : enumOsdMapType          -> _OSD_A or _OSD_B
//                ucRowCommandStart       -> Row command start address
//                ucCharactorCommandStart -> Charactor command start address
//                ucFontStart             -> Font start address
// Output Value : 
//--------------------------------------------------
void ScalerOsdSramBaseAddressSet(EnumOsdMapType enumOsdMapType, WORD ucRowCommandStart, WORD ucCharactorCommandStart, WORD ucFontStart)
{
    BYTE ucTemp = 0;

    ucTemp = (ScalerOsdFrameControlByteGet(0x00B, _OSD_BYTE0) & ~(_BIT7)) ;
    ucTemp = (ucFontStart & 0x1000) >> 5;
    ScalerOsdFrameControlByte(0x00B, _OSD_BYTE0, ucTemp);

    if(enumOsdMapType == _OSD_A)
    {
        ScalerOsdFrameControlAllByte(0x004, _OSD_WITHOUT_DB, (ucCharactorCommandStart & 0x0FF), (((ucCharactorCommandStart & 0xF00) >> 4) | (ucFontStart & 0x00F)), ((ucFontStart & 0xFF0) >> 4));

        ScalerOsdFrameControlByte(0x008, _OSD_BYTE1, ucRowCommandStart);
        ScalerOsdFrameControlByte(0x009, _OSD_BYTE0, ((ucCharactorCommandStart & 0xF00) >> 4)| (ScalerOsdFrameControlByteGet(0x009, _OSD_BYTE0) & 0x0F));
        ScalerOsdFrameControlByte(0x009, _OSD_BYTE1, (ucCharactorCommandStart & 0x0FF));
    }
    else if(enumOsdMapType == _OSD_B)
    {
        ScalerOsdFrameControlByte(0x008, _OSD_BYTE2, ucRowCommandStart);
        ScalerOsdFrameControlByte(0x009, _OSD_BYTE0, ((ucCharactorCommandStart & 0xF00) >> 8)| (ScalerOsdFrameControlByteGet(0x009, _OSD_BYTE0) & 0xF0));
        ScalerOsdFrameControlByte(0x009, _OSD_BYTE2, (ucCharactorCommandStart & 0x0FF));
    }
}
