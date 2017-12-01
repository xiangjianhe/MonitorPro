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
// ID Code      : OsdPosition.c
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
BYTE ucPositionOffsetH = 0;
BYTE ucPositionOffsetV = 0;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerOsdPosition(EnumOsdPositionType enumOsdPositionType, WORD usX, WORD usY);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set osd position
// Input Value  : enumOsdPositionType -> _OSD_POSITION_GLOBAL_A or _OSD_POSITION_GLOBAL_B or _OSD_POSITION_FONT_A or _OSD_POSITION_FONT_B
//                usX                 -> Horizontal delay value (min:2)
//                usY                 -> Vertical  delay value (min:1)
// Output Value : 
//--------------------------------------------------
void ScalerOsdPosition(EnumOsdPositionType enumOsdPositionType, WORD usX, WORD usY)
{
    BYTE ucTemp = 0;

    if((enumOsdPositionType == _OSD_POSITION_GLOBAL_A) || (enumOsdPositionType == _OSD_POSITION_GLOBAL_B))
    {
        if(usX < (3 + ((BYTE)ScalerOsdGetHorizontalDelayStep() * 9)))
        {
            usX = 3 + ((BYTE)ScalerOsdGetHorizontalDelayStep() * 9);
        }
        
        if(usY < 1)
        {
            usY = 1;
        }
    }
    else
    {
        usX += GET_OSD_POSITION_OFFSET_H();
        usY += GET_OSD_POSITION_OFFSET_V();
    }

    if(enumOsdPositionType == _OSD_POSITION_GLOBAL_A)
    {
        ucTemp = (ScalerOsdFrameControlByteGet(0x002, _OSD_BYTE0) & ~(_BIT3 | _BIT2)) | ((usX & 0xC00) >> 8);
        ScalerOsdFrameControlByte(0x002, _OSD_BYTE0, ucTemp);

        ucTemp = (ScalerOsdFrameControlByteGet(0x000, _OSD_BYTE2) & (_BIT2 | _BIT1));
        ScalerOsdFrameControlAllByte(0x000, _OSD_WITHOUT_DB, usY >> 3, usX >> 2, ((usX & 0x0003) << 6) | ((usY & 0x07) << 3) | ucTemp | _BIT0);
        
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }
    else if(enumOsdPositionType == _OSD_POSITION_GLOBAL_B)
    {
        ucTemp = (ScalerOsdFrameControlByteGet(0x002, _OSD_BYTE0) & ~(_BIT1 | _BIT0)) | ((usX & 0xC00) >> 10);
        ScalerOsdFrameControlByte(0x002, _OSD_BYTE0, ucTemp);

        ScalerOsdFrameControlAllByte(0x001, _OSD_WITHOUT_DB, usY >> 3, usX >> 2, ((usX & 0x0003) << 6) | ((usY & 0x07) << 3));
        
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }
    else if(enumOsdPositionType == _OSD_POSITION_FONT_A)
    {
        ScalerOsdScrambleDoubleBufferDepth(3);
        ScalerOsdFrameControlAllByte(0x00C, _OSD_WITH_DB, ((usX &0xF00) >> 4) | ((usY &0xF00) >> 8), (usX &0x0FF), (usY &0x0FF));
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }
    else if(enumOsdPositionType == _OSD_POSITION_FONT_B)
    {
        ScalerOsdScrambleDoubleBufferDepth(3);
        ScalerOsdFrameControlAllByte(0x00D, _OSD_WITH_DB, ((usX &0xF00) >> 4) | ((usY &0xF00) >> 8), (usX &0x0FF), (usY &0x0FF));
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdPosition(_OSD_POSITION_GLOBAL_A, XPOS(100), YPOS(100));
*/
