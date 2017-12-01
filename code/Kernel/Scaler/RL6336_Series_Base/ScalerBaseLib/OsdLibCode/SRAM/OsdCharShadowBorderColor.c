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
// ID Code      : OsdCharShadowBorderColor.c
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
void ScalerOsdCharShadowBorderColor(BYTE ucIndex);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Osd character shadow/border color
// Input Value  : ucIndex -> CharShadowBorderColor LUT index (0~63)   
// Output Value : 
//--------------------------------------------------
void ScalerOsdCharShadowBorderColor(BYTE ucIndex)
{
    BYTE ucTemp = 0;

    ucTemp = ScalerOsdFrameControlByteGet(0x002, _OSD_BYTE2) & ~(_BIT1 | _BIT0);
    ucTemp = ucTemp | ((ucIndex & (_BIT5 | _BIT4)) >> 4);
    ScalerOsdFrameControlByte(0x002, _OSD_BYTE2, ucTemp);

    ucTemp = ScalerOsdFrameControlByteGet(0x003, _OSD_BYTE1) & ~(_BIT7 | _BIT6 | _BIT5 | _BIT4);
    ucTemp = ucTemp | ((ucIndex & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 4);
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE1, ucTemp);
}


