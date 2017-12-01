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
// ID Code      : OsdWindowGradientStep.c
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
void ScalerOsdWindowGradientStep(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ucStep);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window gradient step extension
// Input Value  : bEnable    -> _ENABLE or _DISABLE
//                enumOsdWindowsType -> _OSD_WINDOW_0, _OSD_WINDOW_5, _OSD_WINDOW_6, _OSD_WINDOW_7, _OSD_WINDOW_8, _OSD_WINDOW_9
//                ucStep           -> extended gradient step (0 ~ 255)  
// Output Value :  
//--------------------------------------------------
void ScalerOsdWindowGradientStep(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ucStep)
{
    WORD usTempWindowNumber = 0;

    usTempWindowNumber = 0x176 + (enumOsdWindowsType * 7);

    ScalerOsdFrameControlByte(usTempWindowNumber, _OSD_BYTE1, ucStep);        
    ScalerOsdFrameControlByte((usTempWindowNumber + 1), _OSD_BYTE0, (BYTE)bEnable << 4);        
}


/* 
//--------------------------------------------------
// example
//--------------------------------------------------
    SET_OSD_WINDOW_GRADIENT_ENABLE_R(_ENABLE);
    SET_OSD_WINDOW_GRADIENT_ENABLE(_ENABLE);
    SET_OSD_WINDOW_NUMBER(5);
    SET_OSD_WINDOW_COLOR(4);
    SET_OSD_WINDOW_ENABLE(_ENABLE);
    ScalerOsdDrawWindow(XSTART(100), YSTART(200), XEND(300), YEND(400));
    ScalerOsdWindowGradientStep(_ENABLE, _OSD_WINDOW_5, 200);
*/
