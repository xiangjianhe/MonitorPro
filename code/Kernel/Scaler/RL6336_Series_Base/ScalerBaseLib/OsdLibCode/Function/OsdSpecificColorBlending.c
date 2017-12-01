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
// ID Code      : OsdSpecificColorBlending.c
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
void ScalerOsdSpecificColorBlending(bit bEnable, BYTE ucIndex);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set specific color blending 
// Input Value  :     bEnable -> _ENABLE or _DISABLE
//                    ucIndex -> BlendingColor LUT index (0~63)   
// Output Value :  
//--------------------------------------------------
void ScalerOsdSpecificColorBlending(bit bEnable, BYTE ucIndex)
{
    BYTE ucTemp = 0;

    ucTemp = ScalerOsdFrameControlByteGet(0x002, _OSD_BYTE2) & ~(_BIT4 | _BIT3 | _BIT2);
    ucTemp = ucTemp | _BIT4 | ((ucIndex & (_BIT5 | _BIT4)) >> 2);
    ScalerOsdFrameControlByte(0x002, _OSD_BYTE2, ucTemp);

    ucTemp = ScalerOsdFrameControlByteGet(0x003, _OSD_BYTE0) & ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
    ucTemp = ucTemp | ((BYTE)bEnable << 7) | (ucIndex & ~(_BIT5 | _BIT4));
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, ucTemp);
}


/* 
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdSpecificColorBlending(_ENABLE,15); 
*/
