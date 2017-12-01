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
// ID Code      : UserOSDFunc.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDFUNC__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2011_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
WORD xdata g_usFontSelectStart = 0;
WORD xdata g_usFontTableStart = 0;
BYTE xdata g_ucOsdWidth = 0;
BYTE xdata g_ucOsdHeight = 0;
BYTE g_ucFontPointer0 = _OSD_PAGE_0_START;
BYTE g_ucFontPointer1 = _OSD_PAGE_1_START;
BYTE g_ucFontPointer2 = _OSD_PAGE_2_START;
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void RTDOsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
void RTDOsdFuncSetPosition(WORD usX, WORD usY);
void RTDOsdFuncPutChar(BYTE ucRow, BYTE ucCol, BYTE ucChar, BYTE ucColor);
BYTE RTDOsdFuncGetOsdFontPointer(BYTE ucPointerSelect);
BYTE RTDOsdFuncSetOsdFontPointer(BYTE ucPointerSelect,BYTE ucPointer);
void RTDOsdFuncCloseWindow(BYTE ucIndex);
void RTDOsdFuncDisableOsd(void);
void RTDOsdFuncEnableOsd(void);
void RTDOsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucColor);
void RTDOsdFuncPutIcon1Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
void RTDOsdFuncPutIcon2Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
void RTDOsdFuncSet2BitIconOffset(BYTE ucOffset);
void RTDOsdFuncOsdTransparency(BYTE ucTrans);
void RTDOsdFuncOsdBlending(BYTE ucType);
void RTDOsdFuncClearOsdFont(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucChar);

#if(_OSD_3D_FUNCTION == _ON)
void RTDOsdFuncHLine(BYTE ucRow, BYTE ucCol, BYTE ucType, BYTE ucData);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor)
{
    BYTE ucI = 0;
    BYTE ucTmp = 0x88;
    
#if(_OSD_ROTATE_FUNCTION == _ON)
    if(GET_OSD_ROTATE_STATUS() == _TRUE)
    {
        ucI = ucWidth;
        ucWidth = ucHeight;
        ucHeight = ucI;
        ucTmp = 0x58;
    }
#endif

    // Row Command
    for(ucI = 0; ucI < ucHeight; ucI++)
    {
        ScalerOsdCommandAllByte(ucI, 0x80, ucTmp, ucWidth);        
    }

    // Row Command end
    ScalerOsdCommandByte(ucHeight, _OSD_BYTE0, 0x00);

    // Frame Control (set font start address)
    g_usFontSelectStart = ucHeight + 1;
    g_usFontTableStart = g_usFontSelectStart + (WORD)(ucWidth * ucHeight);
    ScalerOsdFrameControlAllByte(0x004, _OSD_WITHOUT_DB, (BYTE)g_usFontSelectStart, ((g_usFontSelectStart >> 4) & 0xf0) | (g_usFontTableStart & 0x0f), g_usFontTableStart >> 4);

    // Character Command initial
#if(_OSD_ROTATE_FUNCTION == _ON)    
    if(GET_OSD_ROTATE_STATUS() == _TRUE)
    {
        ucTmp = 0x8e;
    }
    else
#endif        
    {
        ucTmp = 0x8c;
    }

    ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE0, ucTmp, (WORD)ucWidth*ucHeight);   // 1bit¡Bwidth 12pixels
    ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE1, 0, (WORD)ucWidth*ucHeight);      // char initial
    ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE2, ucColor, (WORD)ucWidth*ucHeight);  // color initial

    g_ucOsdWidth = ucWidth;
    g_ucOsdHeight = ucHeight;

    ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, 0x10);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncSetPosition(WORD usX, WORD usY)
{
    ScalerOsdScrambleDoubleBufferDepth(3);
    ScalerOsdFrameControlAllByte(0x000, _OSD_WITH_DB, usY >> 3, usX >> 2, ((usX & 0x0003) << 6) | ((usY & 0x07) << 3) | 0x01);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerOsdScrambleDoubleBufferDepth(6);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncPutChar(BYTE ucRow, BYTE ucCol, BYTE ucChar, BYTE ucColor)
{
    WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
    BYTE ucTmp = 0x8c;
    
#if(_OSD_ROTATE_FUNCTION == _ON)
    if(GET_OSD_ROTATE_STATUS() == _TRUE)
    {
        usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
        ucTmp = 0x8e;
    }
#endif

    ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucTmp, ucChar, ucColor);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE RTDOsdFuncGetOsdFontPointer(BYTE ucPointerSelect)
{
    BYTE ucPointer = 0;
    
    if(ucPointerSelect == _PFONT_PAGE_0)
    {
        ucPointer = g_ucFontPointer0;
    }
    else if(ucPointerSelect  == _PFONT_PAGE_1)
    {
        ucPointer = g_ucFontPointer1;
    }
    else if(ucPointerSelect == _PFONT_PAGE_2)
    {
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_1)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_1;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_2)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_2;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_3)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_3;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_4)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_4;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_5)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_5;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_6)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_6;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_7)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_7;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_8)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_8;
        ucPointer = g_ucFontPointer2;
    }

    return ucPointer;    
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE RTDOsdFuncSetOsdFontPointer(BYTE ucPointerSelect,BYTE ucPointer)
{
    ucPointer++;

    if(ucPointerSelect == _PFONT_PAGE_0)
    {
        if(ucPointer >= _OSD_PAGE_0_END)
        {
            ucPointer = _OSD_PAGE_0_START;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_1)
    {
        if(ucPointer >= _OSD_PAGE_1_END)
        {
            ucPointer = _OSD_PAGE_1_START;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_2)
    {
        if(ucPointer >= _OSD_PAGE_2_END)
        {
            ucPointer = _OSD_PAGE_2_START;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_1)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_1_END)
        {
            ucPointer = _SUB_PAGE_ITEM_1;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_2)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_2_END)
        {
            ucPointer = _SUB_PAGE_ITEM_2;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_3)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_3_END)
        {
            ucPointer = _SUB_PAGE_ITEM_3;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_4)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_4_END)
        {
            ucPointer = _SUB_PAGE_ITEM_4;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_5)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_5_END)
        {
            ucPointer = _SUB_PAGE_ITEM_5;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_6)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_6_END)
        {
            ucPointer = _SUB_PAGE_ITEM_6;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_7)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_7_END)
        {
            ucPointer = _SUB_PAGE_ITEM_7;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_8)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_8_END)
        {
            ucPointer = _SUB_PAGE_ITEM_8;
        }
    }
    
    return ucPointer;        
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncCloseWindow(BYTE ucIndex)
{
    if(ucIndex == _WIN_ALL)
    {
        for(ucIndex = 0; ucIndex < 10; ucIndex++)
        {
            ScalerOsdFrameControlByte((0x100 + ((ucIndex & 0x0f) * 4) + 3), _OSD_BYTE2, 0x00);
        }

        for(ucIndex = 0; ucIndex < 10; ucIndex++)
        {
            ScalerOsdFrameControlByte((0x100 + (((ucIndex & 0x80) >> 7) * 0x100) + ((ucIndex & 0x0f) * 4) + 3), _OSD_BYTE2, 0x00);
        }

        for(ucIndex = 0; ucIndex < 9; ucIndex++)
        {
            ScalerOsdFrameControlByte((0x200+((ucIndex&0x0f)*4)+3), _OSD_BYTE2, 0x00);
        }

        for(ucIndex=0;ucIndex<9;ucIndex++)
        {
            ScalerOsdFrameControlByte((0x200 + (((ucIndex & 0x80) >> 7) * 0x100) + ((ucIndex & 0x0f) * 4) + 3), _OSD_BYTE2, 0x00);
        }        
    }
    else
    {
//        ucIndex &= 0x0f;
        ScalerOsdFrameControlByte((0x100 + (((ucIndex & 0x80) >> 7) * 0x100) + ((ucIndex & 0x0f) * 4) + 3), _OSD_BYTE2, 0x00);
    }
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncDisableOsd(void)
{ 
#if(_OSD_3D_FUNCTION == _ON)
    ScalerOsdFrameControlByte(0x017, _OSD_BYTE0, 0x02);//3D OSD disable
#endif //End of #if(_OSD_3D_FUNCTION == _ON)

    ScalerOsdDisableOsd();      
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncEnableOsd(void)
{
#if(_OSD_3D_FUNCTION == _ON)
    if(GET_OSD_3DOSD_STATUS())
    {
        ScalerOsdFrameControlByte(0x017, _OSD_BYTE0, 0x03);//3D OSD Enable
    }
#endif //End of #if(_OSD_3D_FUNCTION == _ON)

    ScalerOsdEnableOsd();
}
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucColor)
{
    WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;
    BYTE ucHeightCount = 0;
    BYTE ucWidthCount = 0;

#if(_OSD_ROTATE_FUNCTION == _ON)
    if(GET_OSD_ROTATE_STATUS() == _ON)
    {
        for(ucWidthCount = 0; ucWidthCount < ucWidth; ucWidthCount++)
        {
            usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol - ucWidthCount) * g_ucOsdWidth + ucRow + g_usFontSelectStart;
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x8E, ucHeight);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE2, ucColor, ucHeight);            
        }
    }
    else
#endif       
    {
        for(ucHeightCount = 0; ucHeightCount < ucHeight; ucHeightCount++)
        {
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x8C, ucWidth);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE2, ucColor, ucWidth);
            usOsdAddr += g_ucOsdWidth;
        }
    }
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncPutIcon1Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground)
{
    WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
    BYTE xdata ucByte0 = 0x8c;
    BYTE xdata ucByte2 = 0;
    
#if(_OSD_ROTATE_FUNCTION == _ON)
    if(GET_OSD_ROTATE_STATUS() == _TRUE)
    {
        usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
        ucByte0 = 0x8e; 
    }
#endif

    ucForeground &= 0x0f;
    
    ucByte2 = ((ucForeground  << 4) | ucBackground);
    ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncPutIcon2Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3)
{
    WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
    BYTE xdata ucByte0 = 0;
    BYTE xdata ucByte2 = 0;

    bit bpaletteindex = (bit)(ucColor0 & _BIT4);
    
#if(_OSD_ROTATE_FUNCTION == _ON)
    if(GET_OSD_ROTATE_STATUS() == _TRUE)
    {
        usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
    }
#endif

    ucColor0 &= 0x0f;
    
    ucByte0 = (_BIT7|_BIT5) | ((ucColor0 & _BIT3) << 3) | ((BYTE)bpaletteindex << 4) | ((ucColor3 & 0x07) << 1) | ((ucColor0 & _BIT2) >> 2);

    ucByte2 = ((ucColor0 & 0x03) << 6) | ((ucColor2 & 0x07) << 3) | (ucColor1 & 0x07);
    ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon|((ucColor1 & _BIT3) << 4), ucByte2);        
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncSet2BitIconOffset(BYTE ucOffset)
{
    ScalerOsdFrameControlByte(0x00B, _OSD_BYTE1, ucOffset);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncOsdTransparency(BYTE ucTrans)
{
    ScalerOsdSetTransparency(ucTrans);
}

//--------------------------------------------------
// Description	: 
// Input Value	: 	Blending type1:Only windows blending.
//					Blending type2:All blending.
//					Blending type3:Windows & Character background blending.
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncOsdBlending(BYTE ucType)
{
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, 0x10);
    ScalerOsdWindow7SpecialFunction(_OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_ALL);
    ScalerOsdSetTransparencyType(ucType);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdFuncClearOsdFont(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucChar)
{
    WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;
    BYTE ucHeightCount = 0;
    BYTE ucWidthCount = 0;
    
#if(_OSD_ROTATE_FUNCTION == _ON)    
    if(GET_OSD_ROTATE_STATUS() == _ON)
    {
        for(ucWidthCount = 0; ucWidthCount < ucWidth; ucWidthCount++)
        {
            usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol - ucWidthCount) * g_ucOsdWidth + ucRow + g_usFontSelectStart;
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x8E, ucHeight);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE1, ucChar, ucHeight);            
        }
    }
    else
#endif        
    {
        for(ucHeightCount = 0; ucHeightCount < ucHeight; ucHeightCount++)
        {
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x8C, ucWidth);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE1, ucChar, ucWidth);
            usOsdAddr += g_ucOsdWidth;
        }
    }
}

#if(_OSD_3D_FUNCTION == _ON)
void RTDOsdFuncHLine(BYTE ucRow, BYTE ucCol, BYTE ucType, BYTE ucData)
{
    WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;

    ScalerOsdCommandByte(usOsdAddr, ucType, ucData);
}
#endif // End of #if(_OSD_3D_FUNCTION == _ON)

#endif//#if(_OSD_TYPE == _REALTEK_2011_OSD)
