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
// ID Code      : ScalerOsdChange1BitColorFont256_511.c
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
void ScalerOsdChange1BitColorFont256_511(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucForegroundColor, BYTE ucBackgroundColor);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : ucRow. ucCol. ucLength. ucHeight.     -> Just that !!
//                ucForegroundColor. ucBackgroundColor  -> Color number
// Output Value :
//--------------------------------------------------
void ScalerOsdChange1BitColorFont256_511(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucForegroundColor, BYTE ucBackgroundColor)
{
    BYTE ucTemp = 0;
    BYTE ucColorByte0 = 0x20;
    bit bColorPalette16to31 = _FALSE;
    bit bOSDEn = _FALSE;

    bOSDEn = (ScalerOsdFrameControlByteGet(0x000, _OSD_BYTE2) & (_BIT0));
    
    if((ucForegroundColor >= 16) && (ucBackgroundColor >= 16))
    {
        ucColorByte0 = 0x30;
        ucForegroundColor -= 16;
        ucBackgroundColor -= 16;

        // Set OSD Circuit Enable for Write-Protection Function effective in OSD enable.
        bColorPalette16to31 = _TRUE;
        ScalerOsdCircuitActivated(_ENABLE);
    }

    for(ucTemp = 0; ucTemp < ucHeight; ucTemp++)
    {
        ScalerOsdSramDataValue(ucRow + ucTemp, ucCol, ucLength, ((ucForegroundColor << 4) | ucBackgroundColor), _OSD_BYTE2);
    }

    ScalerOsdWriteProtection(_ENABLE, _OSD_BYTE0, (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    for(ucTemp = 0; ucTemp < ucHeight; ucTemp++)
    {
        if(bColorPalette16to31 == _TRUE)
        {
            ScalerOsdSramDataValue(ucRow + ucTemp, ucCol, ucLength, ucColorByte0, _OSD_BYTE0);
        }
    }

    ScalerOsdWriteProtection(_DISABLE, _OSD_BYTE0, (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Recovery OSD Status
    ScalerOsdCircuitActivated(bOSDEn);
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdChange1BitColorFont256_511(ROW(0), COL(0), LENGTH(1), HEIGHT(1), FGCOLOR(3), BGCOLOR(4));
*/

