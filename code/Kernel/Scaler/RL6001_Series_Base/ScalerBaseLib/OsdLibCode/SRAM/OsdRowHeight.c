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
// ID Code      : OsdRowHeight.c
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
void ScalerOsdRowHeight(BYTE ucRow, BYTE ucHeight, BYTE ucLength);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : 
// Input Value  : ucRow -> ROW_MAPA(x), ROW_MAPB(x)
//                ucHeight -> 1 ~ 32
//                ucLength -> number of row to be changed
// Output Value :
//--------------------------------------------------
void ScalerOsdRowHeight(BYTE ucRow, BYTE ucHeight, BYTE ucLength)
{
    BYTE i = 0;

    if(ucHeight > 32)
    {
        ucHeight = 32;
    }

    ucHeight--;

    if((ScalerOsdFrameControlByteGet(0x008, _OSD_BYTE0) & _BIT3) == _BIT3)
    {
        if(ucRow >= _OSD_MAP_B_ROW_OFFSET)
        {
            ScalerOsdSramAddressSet((ScalerOsdFrameControlByteGet(0x008, _OSD_BYTE2) + (ucRow - _OSD_MAP_B_ROW_OFFSET)), _OSD_BYTE1);
        }
        else
        {
            ScalerOsdSramAddressSet((ScalerOsdFrameControlByteGet(0x008, _OSD_BYTE1) + ucRow), _OSD_BYTE1);
        }
    }
    else
    {
        ScalerOsdSramAddressSet((0 + ucRow), _OSD_BYTE1);
    }
    
    for(i = 0; i < ucLength; i++)
    {
        ScalerOsdDataPort(ucHeight << 3);
    }
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdRowHeight(ROW_MAPA(0), HEIGHT(31), LENGTH(3));
*/

