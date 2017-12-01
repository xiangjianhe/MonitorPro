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
// ID Code      : OsdDrawWindow.c
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
StructOsdWindow g_stOsdWindow = {0};


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerOsdDrawWindow(WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Draw window
// Input Value  : usXStart -> Horizontal start address
//                usYStart -> Vertical start address
//                usXEnd   -> Horizontal end address
//                usYEnd   -> Vertical end address
// Output Value :  
//--------------------------------------------------
void ScalerOsdDrawWindow(WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd)
{
    BYTE xdata ucpTemp[12] = {0};
    WORD usWinTemp = 0;
 
    if(GET_OSD_WINDOW_BUTTON_ENABLE() == _DISABLE)
    {
        SET_OSD_WINDOW_ENABLE(_ENABLE);
    }
     
    usXStart += (GET_OSD_POSITION_OFFSET_H() + GET_OSD_WINDOW_START_OFFSET());
    usXEnd += (GET_OSD_POSITION_OFFSET_H() + GET_OSD_WINDOW_START_OFFSET());

    if(GET_OSD_POSITION_OFFSET_V() != 0)
    {
        usYStart += (GET_OSD_POSITION_OFFSET_V() - 1);
        usYEnd += (GET_OSD_POSITION_OFFSET_V() - 1);
    }

    if(GET_OSD_WINDOW_NUMBER() >= _OSD_WINDOW_4_1)
    {
        usWinTemp = 0x200 + (((BYTE)GET_OSD_WINDOW_NUMBER() - _OSD_WINDOW_4_1) * 4);
    }
    else
    {
        usWinTemp = 0x100 + (GET_OSD_WINDOW_NUMBER() * 4);
    }
    ScalerOsdAddrMsb(0xC0 | (usWinTemp & 0xF00) >> 8);
    ScalerOsdAddrLsb((BYTE)usWinTemp & 0x0FF);
    
    ucpTemp[0]  = ((BYTE)GET_OSD_WINDOW_COLOR_SHADOW() & _BIT4) << 3 | ((BYTE)GET_OSD_WINDOW_COLOR_BORDER() & _BIT4) << 2 | (BYTE)GET_OSD_WINDOW_SHADOW_BORDER_PIXEL_WIDTH() << 3 | GET_OSD_WINDOW_SHADOW_BORDER_PIXEL_HEIGHT();
    ucpTemp[1]  = ((BYTE)GET_OSD_WINDOW_COLOR_SHADOW() & 0x0F) << 4 | ((BYTE)GET_OSD_WINDOW_COLOR_BORDER() & 0x0F);
    ucpTemp[2]  = ((BYTE)GET_OSD_WINDOW_GRADIENT_POLARITY_R() << 7 | (BYTE)GET_OSD_WINDOW_GRADIENT_POLARITY_G() << 6 | (BYTE)GET_OSD_WINDOW_GRADIENT_POLARITY_B() << 5 | (BYTE)GET_OSD_WINDOW_GRADIENT_LEVEL_SETP() << 3 | (BYTE)GET_OSD_WINDOW_GRADIENT_ENABLE_R() << 2   | (BYTE)GET_OSD_WINDOW_GRADIENT_ENABLE_G() << 1 | (BYTE)GET_OSD_WINDOW_GRADIENT_ENABLE_B());
    ucpTemp[3]  = ((usXStart &0xF00) >> 4) | ((usYStart &0xF00) >> 8);
    ucpTemp[4]  = (usXStart &0x0FF);
    ucpTemp[5]  = (usYStart &0x0FF);
    ucpTemp[6]  = ((usXEnd &0xF00) >> 4) | ((usYEnd &0xF00) >> 8);
    ucpTemp[7]  = (usXEnd &0x0FF);
    ucpTemp[8]  = (usYEnd &0x0FF);
    ucpTemp[9]  = (((BYTE)GET_OSD_WINDOW_COLOR_SHADOW() & _BIT5) << 2) | (((BYTE)GET_OSD_WINDOW_COLOR_BORDER() & _BIT5) << 1) | ((BYTE)GET_OSD_WINDOW_COLOR() & _BIT5) | ((BYTE)GET_OSD_WINDOW_GRADIENT_SATURATED_COLOR_MODE() <<4) | ((BYTE)GET_OSD_WINDOW_GRADIENT_REVERSED_COLOR_MODE() <<3)  | ((BYTE)GET_OSD_WINDOW_REFERENCE_DELAY() << 2)| (BYTE)GET_OSD_WINDOW_BORDER_PRIORITY() << 1 | ((BYTE)GET_OSD_WINDOW_GRADIENT_LEVEL_EXTENSION());
    ucpTemp[10] = (BYTE)GET_OSD_WINDOW_GRADIENT_LEVEL_PER() << 5 | (BYTE)GET_OSD_WINDOW_COLOR() & 0x1F;
    ucpTemp[11] = (BYTE)GET_OSD_WINDOW_BLEND_ENABLE() << 7 | (BYTE)GET_OSD_WINDOW_GRADIENT_ENABLE() << 6 | (BYTE)GET_OSD_WINDOW_GRADIENT_DIRECTION() << 5 | (BYTE)GET_OSD_WINDOW_BUTTON_ENABLE() << 4 | (BYTE)GET_OSD_WINDOW_BUTTON_TYPE() << 1 | (BYTE)GET_OSD_WINDOW_ENABLE();
   
    ScalerOsdBurstWriteDataPort(ucpTemp, 12, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_XRAM);

    usWinTemp = 0x177 + (GET_OSD_WINDOW_NUMBER() * 7);
    ScalerOsdFrameControlByte(usWinTemp, _OSD_BYTE0, GET_OSD_WINDOW_ROTATION_FUNCTION_ENABLE());

    memset (&g_stOsdWindow, 0x00, sizeof(g_stOsdWindow));
}


/* 
//--------------------------------------------------
// example 1
//--------------------------------------------------
    code StructOsdWindow g_stOsdWindowTest = { _OSD_WINDOW_6,                               // b5WindowNumber                     
                                               _ENABLE,                                     // b1WindowEnable                    
                                               9,                                           // b6WindowColor                                                    
                                               6,                                           // b6WindowColorShadow                
                                               0,                                           // b6WindowColorBorder                
                                               1,                                           // b3WindowShadowBorderPixelWidth     
                                               1,                                           // b3WindowShadowBorderPixelHeight    
                                               _OSD_WINDOW_GRADIENT_LEVEL_STEP_3,           // b2WindowGradientLevelStep      
                                               _OSD_WINDOW_GRADIENT_LEVEL_PER_5,            // b3WindowGradientLevelPer                                     
                                               _OSD_WINDOW_GRADIENT_POLARITY_DECREASE,      // b1WindowGradientPolarityR          
                                               _OSD_WINDOW_GRADIENT_POLARITY_INCREASE,      // b1WindowGradientPolarityG          
                                               _OSD_WINDOW_GRADIENT_POLARITY_INCREASE,      // b1WindowGradientPolarityB          
                                               _ENABLE,                                     // b1WindowGradientEnableR            
                                               _DISABLE,                                    // b1WindowGradientEnableG            
                                               _ENABLE,                                     // b1WindowGradientEnableB            
                                               0,                                           // b1WindowGradientSaturatedColorMode         
                                               0,                                           // b1WindowGradientReversedColorMode          
                                               0,                                           // b1WindowReferenceDelay                                               
                                               _OSD_WINDOW_GRADIENT_LEVEL_EXTENSION_8,      // b1WindowGradientLevelExtension     
                                               1,                                           // b1WindowBlend            
                                               1,                                           // b1WindowGradient         
                                               _OSD_WINDOW_GRADIENT_DIRECTION_HORIZONTAL,   // b1WindowGradientDirection
                                               1,                                           // b1WindowButtonEnable                                       
                                               _OSD_WINDOW_BUTTON_TYPE_3D_BUTTON_1,         // b3WindowType                      
                                               _ENABLE                                      // b1WindowRotationFunctionEnable             
                                             };
                                                          
    g_stOsdWindow = g_stOsdWindowTest;                                                               
    ScalerOsdDrawWindow(XSTART(100), YSTART(200), XEND(300), YEND(400));                             
                                                                                                                          
                                                                                         
//--------------------------------------------------
// example 2
//--------------------------------------------------
    SET_OSD_WINDOW_NUMBER(6);
    SET_OSD_WINDOW_ENABLE(_ENABLE);
    SET_OSD_WINDOW_COLOR(4);
    SET_OSD_WINDOW_ROTATION_FUNCTION_ENABLE(_ENABLE);
    ScalerOsdDrawWindow(XSTART(100), YSTART(200), XEND(300), YEND(400));

*/
