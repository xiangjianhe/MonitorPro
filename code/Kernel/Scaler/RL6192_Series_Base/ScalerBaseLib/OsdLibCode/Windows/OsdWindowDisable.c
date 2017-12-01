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
// ID Code      : OsdWindowDisable.c
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
void ScalerOsdWindowDisable(EnumOsdWindowsType enumOsdWindowsType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Disable window 
// Input Value  : enumOsdWindowsType -> _OSD_WINDOW_0,   _OSD_WINDOW_1,   _OSD_WINDOW_2,   _OSD_WINDOW_3,   _OSD_WINDOW_4,   _OSD_WINDOW_5, 
//                                      _OSD_WINDOW_6,   _OSD_WINDOW_7,   _OSD_WINDOW_8,   _OSD_WINDOW_9,   _OSD_WINDOW_4_1, _OSD_WINDOW_4_2,
//                                      _OSD_WINDOW_4_3, _OSD_WINDOW_4_4, _OSD_WINDOW_4_5, _OSD_WINDOW_4_6, _OSD_WINDOW_4_7, _OSD_WINDOW_4_8,
//                                      _OSD_WINDOW_ALL,
// Output Value :  
//--------------------------------------------------
void ScalerOsdWindowDisable(EnumOsdWindowsType enumOsdWindowsType)
{
    WORD usWinTemp = 0;

    if(enumOsdWindowsType == _OSD_WINDOW_ALL)
    {
        for(usWinTemp = 0; usWinTemp < 10; usWinTemp++)
        {
            ScalerOsdFrameControlByte((0x103 + usWinTemp * 4), _OSD_BYTE2, 0x00);

            if(usWinTemp < 8)
            {
                ScalerOsdFrameControlByte((0x203 + usWinTemp * 4), _OSD_BYTE2, 0x00);
            }
        }
    }
    else
    { 
        if(enumOsdWindowsType >= _OSD_WINDOW_4_1)
        {
            usWinTemp = 0x203 + ((enumOsdWindowsType - _OSD_WINDOW_4_1) * 4);
        }
        else
        {
            usWinTemp = 0x103 + (enumOsdWindowsType * 4);
        }
        ScalerOsdFrameControlByte(usWinTemp, _OSD_BYTE2, 0x00);
    }
}



/* 
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdWindowDisable(_OSD_WINDOW_0);
*/
