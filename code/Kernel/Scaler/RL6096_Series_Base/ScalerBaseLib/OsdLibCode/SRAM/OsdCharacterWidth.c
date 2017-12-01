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
// ID Code      : OsdCharactorWidth.c
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
void ScalerOsdCharacterWidth(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucLength);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : 
// Input Value  : ucRow, ucCol -> 1-bit font position
//                ucWidth      -> font width
//                ucLength     -> number of 1-bit font to be changed
// Output Value :
//--------------------------------------------------
void ScalerOsdCharacterWidth(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucLength)
{
    BYTE i = 0;
    bit bOSDEn = _FALSE;

    bOSDEn = (ScalerOsdFrameControlByteGet(0x000, _OSD_BYTE2) &  (_BIT0));

    // Set OSD Circuit Enable for Write-Protection Function effective in OSD enable.
    ScalerOsdCircuitActivated(_ENABLE);
    
    ScalerOsdWriteProtection(_ENABLE, _OSD_BYTE0, (_BIT7 | _BIT6 | _BIT5 |_BIT4));
    ScalerOsdSramAddressCount(ucRow, ucCol, _OSD_BYTE0);

    for(i = 0; i < ucLength; i++)
    {
        ScalerOsdDataPort(ucWidth);
    }

    ScalerOsdWriteProtection(_DISABLE, _OSD_BYTE0, (_BIT7 | _BIT6 | _BIT5 |_BIT4));

    // Recovery OSD Status
    ScalerOsdCircuitActivated(bOSDEn);
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdCharacterWidth(ROW_MAPA(0), COL(0), WIDTH(4), LENGTH(1));
*/

