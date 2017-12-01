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
// ID Code      : OsdWindow7SpecialFunction.c
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
void ScalerOsdWindow7SpecialFunction(EnumOsdWindow7FunctionType enumOsdWindow7FunctionType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window 7 Special function
// Input Value  : enumOsdWindow7FunctionType   -> _OSD_WINDOW_7_FUNCTION_DISABLE                        or _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BOTH                  or 
//                                                _OSD_WINDOW_7_FUNCTION_NO_BLENDING_FOREGROUND         or _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BACKGROUND            or
//                                                _OSD_WINDOW_7_FUNCTION_BLENDING_BOTH                  or _OSD_WINDOW_7_FUNCTION_MASK_REGION_APPEAR                or
//                                                _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_ALL    or _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_FONT
// Output Value :  
//--------------------------------------------------
void ScalerOsdWindow7SpecialFunction(EnumOsdWindow7FunctionType enumOsdWindow7FunctionType)
{
    BYTE ucTemp = 0;

    ucTemp = ScalerOsdFrameControlByteGet(0x003, _OSD_BYTE0) & ~(_BIT6 | _BIT5);

    if((enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BOTH) || (enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_NO_BLENDING_FOREGROUND) || (enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BACKGROUND) || (enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_BLENDING_BOTH))
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, (ucTemp | _BIT5));

        ucTemp = (ScalerOsdFrameControlByteGet(0x00B, _OSD_BYTE0) & ~(_BIT5 | _BIT4)) | ((enumOsdWindow7FunctionType - _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BOTH) << 4);
        ScalerOsdFrameControlByte(0x00B, _OSD_BYTE0, ucTemp);        
    }
    else if(enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_MASK_REGION_APPEAR)
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, (ucTemp | _BIT6));
    }
    else if((enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_ALL) || (enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_FONT))
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, (ucTemp | _BIT6 | _BIT5));

        ucTemp = (ScalerOsdFrameControlByteGet(0x002, _OSD_BYTE1) & ~_BIT3) | ((enumOsdWindow7FunctionType - _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_ALL) << 3);
        ScalerOsdFrameControlByte(0x002, _OSD_BYTE1, ucTemp);        
    }
    else
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, ucTemp);
    }
}


/* 
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdWindow7SpecialFunction(_OSD_WINDOW_7_FUNCTION_DISABLE);
*/
