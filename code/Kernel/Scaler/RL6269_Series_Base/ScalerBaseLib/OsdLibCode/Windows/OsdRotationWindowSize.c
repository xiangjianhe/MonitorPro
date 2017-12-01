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
// ID Code      : OsdRotationWindowSize.c
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
void ScalerOsdRotationWindowSize(EnumOsdMapType enumOsdMapType, WORD usLength, WORD Width);


//--------------------------------------------------
// Description  : Set window rotate reference size
// Input Value  : enumOsdMapType -> _OSD_A or _OSD_B
//                usLength       -> Horizontal max size
//                Width          -> Vertical max size
// Output Value : 
//--------------------------------------------------
void ScalerOsdRotationWindowSize(EnumOsdMapType enumOsdMapType, WORD usLength, WORD Width)
{
    if(ScalerOsdFrameControlByteGet(0x016, _OSD_BYTE0) & ~(_BIT0) != _BIT0)
    {
        if((ScalerOsdFrameControlByteGet(0x016, _OSD_BYTE0) & _BIT4) == _BIT4)  // CW   _OSD_ROTATE_DEGREE_90
        {
            Width = Width + GET_OSD_POSITION_OFFSET_H() + GET_OSD_WINDOW_START_OFFSET() - 1;
        }
        else                                                                    // CCW  _OSD_ROTATE_DEGREE_270
        {
            usLength++;
        }
    }

    ScalerOsdFrameControlAllByte(0x013 + (BYTE)enumOsdMapType, _OSD_WITHOUT_DB, ((usLength &0xF00) >> 4) | ((Width &0xF00) >> 8), (usLength &0x0FF), (Width &0x0FF));
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdRotationWindowSize(_OSD_A, XEND(400), YEND(500));
*/



