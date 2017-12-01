/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : UserOSDFunc.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDFUNC__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LENOVO_2014_OSD)

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

#if 1   //alex.huang 20120111
BYTE xdata g_ucOsdMap = 0;
#endif
/*
BYTE xdata g_ucOsdFlyH = _OSD_FLY_H_STEP/2;
BYTE xdata g_ucOsdFlyV = _OSD_FLY_V_STEP/2;
BYTE xdata g_ucOsdFlyState = 0xC0; //0xC0 = SET_OSD_FLY_H_STATE() SET_OSD_FLY_V_STATE()//Eli 20120927
bit g_bStopOsdFlyH = 0;
bit g_bStopOsdFlyV = 0;
*/

BYTE g_ucFontPointer0 = _OSD_PAGE_0_START;
BYTE g_ucFontPointer1 = _OSD_PAGE_1_START;
BYTE g_ucFontPointer2 = _OSD_PAGE_2_START;
BYTE g_ucFontPointer3 = _OSD_PAGE_3_START;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdFuncSetPosition(WORD usX, WORD usY);
void OsdFuncCloseWindow(BYTE ucIndex);
void OsdFuncDisableOsd(void);
void OsdFuncEnableOsd(void);
//void OsdFuncSet2BitIconOffset(BYTE ucOffset);
void OsdFuncOsdTransparency(BYTE ucTrans);
void OsdFuncOsdBlending(BYTE ucType);

#if 1   //alex.huang 20120111
void OsdFuncApplyMap(BYTE ucOsdMapType);
WORD OsdFuncCalcStartAddress(BYTE ucRow, BYTE ucCol);
void OsdFunc1bitColor(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucForegroundColor, BYTE ucBackgroundColor);
void OsdFuncBlank(BYTE ucRow,BYTE ucCol, BYTE ucPiexl,BYTE ucHeight,BYTE ucColor);
void OsdFunc1bitByte0(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucByte0);
void OsdFunc1bitChar(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucChar);
void OsdFunc1bitItemApplyChar(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucChar);
#endif

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdFuncSetPosition(WORD usX, WORD usY)
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
void OsdFuncCloseWindow(BYTE ucIndex)
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
void OsdFuncDisableOsd(void)
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
void OsdFuncEnableOsd(void)
{
#if(_OSD_3D_FUNCTION == _ON)
    if(GET_OSD_3DOSD_STATUS())
    {
        ScalerOsdFrameControlByte(0x017, _OSD_BYTE0, 0x03);//3D OSD Enable
    }
#endif //End of #if(_OSD_3D_FUNCTION == _ON)

#if 1   //alex.huang 20130731 for fine tuning OSD H position 2 pixel
    ScalerOsdPosition(_OSD_POSITION_FONT_A,X_POS(_OSD_POSITION_FONT_A_H_DELAY_),Y_POS(0));
#endif

    ScalerOsdEnableOsd();
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
/*
void OsdFuncSet2BitIconOffset(BYTE ucOffset)
{
    ScalerOsdFrameControlByte(0x00B, _OSD_BYTE1, ucOffset);
}
*/
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdFuncOsdTransparency(BYTE ucTrans)
{
    ScalerOsdSetTransparency(ucTrans);
    ScalerOsdSetTransparencyType(_OSD_TRANSPARENCY_ALL);
}

//--------------------------------------------------
// Description	: 
// Input Value	: 	Blending type1:Only windows blending.
//					Blending type2:All blending.
//					Blending type3:Windows & Character background blending.
// Output Value : None
//--------------------------------------------------
void OsdFuncOsdBlending(BYTE ucType)
{
//    ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, 0x70);//Window 7 mask region transparent.
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE1, ucType);
}

#if 1   //alex.huang 20120111
WORD code tOSD_OSDMAP_INF[][2] =
{
    {_OSD_MAP0_Height, 0},
    {_OSD_MAP1_Height, 0},
    {_OSD_MAP2_Height, 0},
    {0, 0},
    {0, 0},
    {0, 0},
};

BYTE code tOSD_ROW_COMMAND0[] =
{
    5,_AUTOINC,0x90,0xD0,0x00,
    (_OSD_MAP0_Height * 3 + 3 + 3),_NON_AUTOINC,0x92,

    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),

    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),

    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),

    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),

    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),

    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),

    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),
    ROW_COMMAND_HEIGHT18(WIDTH(_OSD_MAP0_Width)),

    ROW_COMMAND_END,_END
};

BYTE code tOSD_ROW_COMMAND1[] =
{
    5,_AUTOINC,0x90,0xD0,0x00,
    36,_NON_AUTOINC,0x92, // Row number = 10, 10*3+3+3=36
    ROW_COMMAND_HEIGHT22(_OSD_MSG_COL),
    ROW_COMMAND_HEIGHT18(_OSD_MSG_COL),
    ROW_COMMAND_HEIGHT18(_OSD_MSG_COL),
    ROW_COMMAND_HEIGHT18(_OSD_MSG_COL),
    ROW_COMMAND_HEIGHT18(_OSD_MSG_COL),
    ROW_COMMAND_HEIGHT18(_OSD_MSG_COL),
    ROW_COMMAND_HEIGHT18(_OSD_MSG_COL),
    ROW_COMMAND_HEIGHT18(_OSD_MSG_COL),
//    ROW_COMMAND_HEIGHT18(_OSD_MSG_COL),
//    ROW_COMMAND_HEIGHT18(_OSD_MSG_COL),
    ROW_COMMAND_END,
   _END,
};

BYTE code tOSD_ROW_COMMAND2[] =
{
    5,_AUTOINC,0x90,0xD0,0x00,
    33,_NON_AUTOINC,0x92, // Row number = 9, 9*3+3+3=33
    ROW_COMMAND_HEIGHT18(55),
    ROW_COMMAND_HEIGHT18(55),
    ROW_COMMAND_HEIGHT18(55),
    ROW_COMMAND_HEIGHT18(55),
    ROW_COMMAND_HEIGHT18(55),
    ROW_COMMAND_HEIGHT18(55),
    ROW_COMMAND_HEIGHT18(55),
    ROW_COMMAND_HEIGHT18(55),
    ROW_COMMAND_HEIGHT18(55),
    ROW_COMMAND_END,
   _END,
};


#if 1   //alex.huang 20140909

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#define    _Logo_0x00        0x00+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x01        0x01+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x02        0x02+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x03        0x03+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x04        0x04+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x05        0x05+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x06        0x06+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x07        0x07+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x08        0x08+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x09        0x09+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0a        0x0a+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0b        0x0b+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0c        0x0c+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0d        0x0d+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0e        0x0e+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0f        0x0f+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x10        0x10+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x11        0x11+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x12        0x12+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x13        0x13+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x14        0x14+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x15        0x15+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x16        0x16+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x17        0x17+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x18        0x18+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x19        0x19+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1a        0x1a+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1b        0x1b+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1c        0x1c+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1d        0x1d+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1e        0x1e+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1f        0x1f+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x20        0x20+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x21        0x21+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x22        0x22+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x23        0x23+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x24        0x24+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x25        0x25+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x26        0x26+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x27        0x27+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x28        0x28+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x29        0x29+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2a        0x2a+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2b        0x2b+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2c        0x2c+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2d        0x2d+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2e        0x2e+_1BIT_EPA_LOG_ICON_START

#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)
//20120801 Abel 1Bit Logo Modify
BYTE code LENOVO_LOGO_COMMAND[]=
{
#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))
    //////////////////////////////////////////////////
    //row 0
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xd6,0xd7,        

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    
    //////////////////////////////////////////////////
    //row 1
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xd8,0xd9,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    

    //////////////////////////////////////////////////
    //row 2 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xda,0xdb,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    

    //////////////////////////////////////////////////
    //row 3 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xdc,0xdd,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    

    //////////////////////////////////////////////////
    //row 4 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xde,0xdf,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    
    //////////////////////////////////////////////////
    //row 5 (1bit字4個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe0,0xe1,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,

    //////////////////////////////////////////////////
    //row 6
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe2,0xe3, 
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,

    //////////////////////////////////////////////////
    //row 7
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe4,0xe5,   
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,

    //////////////////////////////////////////////////
    //row 8
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe6,0xe7,0xe8,   
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,            
    //////////////////////////////////////////////////
    //row 9
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe9,0xea,0xeb,0xec,0xed,    
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,          
    //////////////////////////////////////////////////
    //row 10
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xee,0xef,0xf0,0xf1,0xf2,     
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,   

    //////////////////////////////////////////////////
    //row 11
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xf3,0xf4,0xf5,     
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,      
    //////////////////////////////////////////////////
    //row 12
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xf6,0xf7,0xf8,      
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,    
    //////////////////////////////////////////////////
    //row 13
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xf9,0xfa,0xfb,      
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 14    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(0)),       //FONTBYTE1, 文字Index
        53,_NON_AUTOINC,0x92,
        0x00,0x01,0x01,0x01,0x01,0x01,0x02,0x03,0x04,0x05,0x06,0x06,0x06,0x07,0x08,0x09,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x0a,0x04,0x0b,0x06,0x06,0x06,0x0c,0x04,0x0d,0x06,0x0e,0x04,0x0f,0x10,0x11,0x12,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x7f,0x80,0x81,0x82,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(13)),      //FONTBYTE2, 文字顏色(紅色點)
        6,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
        
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(67)),     //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(67)),     //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x00,0x01,0x02,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 15      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(0)),      //FONTBYTE1, 文字Index
        53,_NON_AUTOINC,0x92,      
        0x13,0x14,0x15,0x16,0x17,0x14,0x18,0x19,0x16,0x1a,0x06,0x06,0x06,0x1b,0x1c,0x1d,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x1e,0x16,0x1f,0x06,0x06,0x06,0x20,0x16,0x21,0x06,0x22,0x16,0x23,0x24,0x25,0x26,0x06, 0x06,0x06,0x06,0x06,0x06,0x06,0x83,0x84,0x85,0x86,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(13)),     //FONTBYTE2, 文字顏色(紅色點)
        6,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
        
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x03,0x04,0x05,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 16        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(0)),      //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,                                                                                                                                                                                                                                  
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x06,0x2f,0x2f,0x30,0x31,0x32,0x33,0x1e,0x16,0x1f,0x34,0x2d,0x35,0x36,0x16,0x37,0x06,0x38,0x16,0x39,0x3a,0x2d,0x3b,0x06,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x2d,0x8e,0x06,0x8f,0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x2d,0x99,   

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
            
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x06,0x07,0x08,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 17     
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(0)),     //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x3c,0x3d,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x40,0x41,0x16,0x42,0x1e,0x16,0x1f,0x43,0x16,0x44,0x45,0x16,0x46,0x47,0x16,0x16,0x48,0x19,0x16,0x1a,0x06,0x9a,0x16,0x9b,0x9c,0x16,0x9d,0x9e,0x16,0x16,0x06,0x9f,0x16,0xa0,0xa1,0x16,0xa2,0x49,0x16,0xa3,0xa4,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x09,0x0a,0x0b,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 18      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x1f,0x4b,0x16,0x4c,0x4d,0x16,0x4e,0x4f,0x16,0x50,0x06,0x19,0x16,0x1a,0x06,0xa6,0x16,0xa7,0x9e,0x16,0x3f,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x0c,0x0d,0x0e,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 19  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,     
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x51,0x16,0x52,0x06,0x53,0x16,0x54,0x55,0x16,0x56,0x06,0x19,0x16,0x1a,0x06,0xab,0xac,0xad,0xae,0xaf,0xb0,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,   

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x0f,0x10,0x11,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 20      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x57,0x16,0x58,0x06,0x59,0x16,0x5a,0x5b,0x16,0x5c,0x06,0x19,0x16,0x1a,0x06,0x06,0xb1,0xb2,0x16,0xb3,0xb4,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                   
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x12,0x13,0x14,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 21  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(0)),   //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x5d,0x5e,0x5f,0x60,0x61,0x5e,0x16,0x62,0x16,0x63,0x06,0x19,0x16,0x1a,0x06,0xb5,0xb6,0xb7,0xb8,0x16,0xb9,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,    

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(64)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x15,0x16,0x17,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 22  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x1f,0x64,0x16,0x65,0x06,0x66,0x16,0x67,0x16,0x68,0x06,0x19,0x16,0x1a,0x06,0xba,0x16,0xaa,0xbb,0x16,0x3f,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(64)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
        
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x18,0x19,0x1a,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    //////////////////////////////////////////////////
    //row 23      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x1f,0x69,0x16,0x6a,0x06,0x6b,0x16,0x16,0x16,0x6c,0x06,0x19,0x16,0x1a,0x06,0xbc,0x16,0xbd,0xbe,0x16,0xbf,0x9e,0x16,0x16,0x06,0xc0,0x16,0xc1,0xc2,0x16,0xc3,0x49,0x16,0xaa,0x06,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(64)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x1b,0x1c,0x1d,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 24      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(0)),    //FONTBYTE1, 文字Index
        67,_NON_AUTOINC,0x92,  
        0x06,0x06,0x6d,0x6e,0x6f,0x06,0x06,0x70,0x6e,0x71,0x72,0x6e,0x6f,0x73,0x6e,0x74,0x06,0x6e,0x75,0x06,0x76,0x6e,0x77,0x78,0x6e,0x79,0x7a,0x6e,0x7b,0x06,0x7c,0x6e,0x6e,0x6e,0x7d,0x06,0x70,0x6e,0x7e,0x06,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0x6e,0x6e,0x06,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0x6e,0xd2,0x06,0x6e,0xd3,0xd4,0xd5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(64)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
            
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x1e,0x1f,0x20,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    
#if(_EPA_LOGO==_ON)	
    //EPA LOGO
    //////////////////////////////////////////////////
    //row 26  
        //顯示sion
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,    
    
    //////////////////////////////////////////////////
    //row 27
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,    
    
    
    //////////////////////////////////////////////////
    //row 28
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 29
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 30
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 31
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 32
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))

    //////////////////////////////////////////////////
    //row 0
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x00,0x01,0x02,0x02,0x02,      

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,    
    //////////////////////////////////////////////////
    //row 1
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x03,0x04,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 2 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x05,0x06,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 3 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x07,0x08,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 4 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x09,0x0a,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
    //////////////////////////////////////////////////
    //row 5 (1bit字4個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x0b,0x0c,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 6
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x0d,0x0e,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 7
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x0f,0x10,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 8
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x11,0x12,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 9
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x13,0x14,0x15,0x16,0x17, 
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 10
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x18,0x19,0x1a,0x1b,0x1c,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 11
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x1d,0x1e,0x1f,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 12
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x20,0x21,0x22,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 13
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x23,0x24,0x25,0x02,0x02,   
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 14
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x26,0x27,0x28,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 15    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(0)),       //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,
        0x00,0x01,0x01,0x01,0x01,0x01,0x02,0x03,0x04,0x05,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x07,0x04,0x08,0x06,0x06,0x06,0x09,0x04,0x0a,0x06,0x0b,0x04,0x0c,0x0d,0x0e,0x0f,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x10,0x0e,0x11,    0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,          

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(14)),   //FONTBYTE0, 屬性(紅色點)
        6,_NON_AUTOINC,0x92,
        0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(14)),   //FONTBYTE1, 文字Index(紅色點)
        6,_NON_AUTOINC,0x92,  
        0x29,0x2a,0x2b,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(14)),      //FONTBYTE2, 文字顏色(紅色點)
        6,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
 
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(70)),     //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xa4,0xa5,0xa6,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 16      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(0)),      //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x12,0x13,0x14,0x15,0x16,0x13,0x17,0x18,0x15,0x19,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x1a,0x15,0x1b,0x06,0x06,0x06,0x1c,0x15,0x1d,0x06,0x1e,0x15,0x1f,0x20,0x21,0x22,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x23,0x21,0x22,      0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,    

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(14)),   //FONTBYTE0, 屬性(紅色點)
        6,_NON_AUTOINC,0x92,
        0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(14)),   //FONTBYTE1, 文字Index(紅色點)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2d,0x2e,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(14)),      //FONTBYTE2, 文字顏色(紅色點)
        6,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xa7,0xa8,0xa9,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 17        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(0)),      //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,                                                                                                                                                                                                                                  
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x25,0x26,0x27,0x28,0x06,0x29,0x2a,0x2b,0x2c,0x2a,0x2d,0x2e,0x2f,0x30,0x06,0x1a,0x15,0x1b,0x31,0x2a,0x32,0x33,0x15,0x34,0x06,0x35,0x15,0x36,0x37,0x2a,0x38,0x06,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x37,0x2a,0x38,    0x06,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,0xb5,0xb6,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xb7,0xb8,0xb9,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 18     
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(0)),     //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x3f,0x40,0x15,0x41,0x06,0x1a,0x15,0x1b,0x42,0x15,0x43,0x44,0x15,0x15,0x06,0x1a,0x15,0x1b,0x45,0x15,0x46,0x47,0x15,0x48,0x06,0x49,0x15,0x4a,0x4b,0x15,0x4c,0x06,0x4d,0x15,0x4e,0x4f,0x15,0x50,0x4b,0x15,0x4c,    0x06,0xba,0xbb,0xbc,0xbd,0xbb,0xbe,0xbf,0xbb,0xc0,0xc1,0xc2,0xbb,0xc3,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
   
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xc4,0xc5,0xc6,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 19      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x1b,0x52,0x15,0x53,0x54,0x15,0x55,0x06,0x56,0x15,0x57,0x4b,0x15,0x4c,0x06,0x15,0x15,0x58,0x18,0x15,0x59,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
   
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xcd,0xce,0xcf,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 20  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,     
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x5a,0x15,0x5b,0x06,0x5c,0x15,0x5d,0x5e,0x15,0x15,0x5f,0x4b,0x15,0x4c,0x06,0x60,0x15,0x61,0x62,0x63,0x64,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
   
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xd0,0xd1,0xd2,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 21      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x65,0x15,0x66,0x06,0x67,0x15,0x15,0x68,0x15,0x69,0x06,0x4b,0x15,0x4c,0x06,0x6a,0x6b,0x15,0x6c,0x6d,0x06,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xd3,0xd4,0xd5,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 22  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(0)),   //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x6e,0x15,0x6f,0x06,0x06,0x70,0x15,0x71,0x15,0x72,0x06,0x4b,0x15,0x4c,0x06,0x06,0x73,0x74,0x15,0x75,0x76,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xd6,0xd7,0xd8,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 23  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x77,0x78,0x15,0x79,0x06,0x7a,0x15,0x7b,0x15,0x7c,0x06,0x4b,0x15,0x4c,0x06,0x15,0x15,0x7d,0x7e,0x15,0x59,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xd9,0xda,0xdb,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    //////////////////////////////////////////////////
    //row 24      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x1b,0x7f,0x15,0x80,0x06,0x81,0x15,0x15,0x15,0x82,0x06,0x4b,0x15,0x4c,0x06,0x15,0x15,0x06,0x24,0x15,0x59,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
   
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xdc,0xdd,0xde,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 25      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,  
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x1b,0x83,0x15,0x84,0x06,0x85,0x15,0x15,0x15,0x86,0x06,0x4b,0x15,0x4c,0x06,0x87,0x15,0x88,0x89,0x8a,0x8b,0x4b,0x15,0x4c,    0x06,0xdf,0xbb,0xe0,0xe1,0xe2,0xe3,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0xe4,0xe5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xe6,0xe7,0xe8,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 26      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,  
        0x06,0x06,0x8c,0x8d,0x8e,0x06,0x06,0x8f,0x90,0x91,0x92,0x90,0x90,0x06,0x93,0x8d,0x94,0x95,0x8d,0x8e,0x06,0x8d,0x8d,0x06,0x96,0x90,0x97,0x98,0x90,0x99,0x06,0x8f,0x90,0x90,0x90,0x9a,0x06,0x9b,0x8d,0x9c,0x06,0x9d,0x9e,0x9f,0xa0,0xa1,0x06,0xa2,0x8d,0xa3,    0x06,0xe9,0xea,0xeb,0xec,0xed,0x06,0xee,0xef,0xf0,0x06,0xf1,0xef,0xf2,0xf3,0xf4,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x06,0xf5,0xf6,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,

#if(_EPA_LOGO==_ON)	
    //EPA LOGO
    //////////////////////////////////////////////////
    //row 28  
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,    
    
    //////////////////////////////////////////////////
    //row 29
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,    
    
    
    //////////////////////////////////////////////////
    //row 30
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 31
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 32
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 33
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 34
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif

#elif((_PANEL_DH_WIDTH == 1280) && (_PANEL_DV_HEIGHT == 1024))
    //Logo1280x1024 視窗大小非正方形32字高
    //////////////////////////////////////////////////
    //row 0(9字,1~4blank=20字,5blank=18字)      
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xe4,0x00,0x01,        
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 1(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x03,0x04,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 2(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x05,0x06,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 3(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x07,0x08,
          
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 4(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x09,0x0a,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
    
    //////////////////////////////////////////////////
    //row 5(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x0b,0x0c,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
    
    //////////////////////////////////////////////////
    //row 6(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x0d,0x0e,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
      
    //////////////////////////////////////////////////
    //row 7(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x0f,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
    
    //////////////////////////////////////////////////
    //row 8(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x11,0x12,0x13,0x14,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 9(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x15,0x16,0x17,0x18,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 10(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x19,0x1a,0x1b,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 11(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x1c,0x1d,0x1e,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 12(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x1f,0x20,0x21,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,
    
    //////////////////////////////////////////////////   
    //row 13(64字) 
        //顯示ThinkVision 
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
        47,_NON_AUTOINC,0x92, 
        0x40,0x41,0x41,0x41,0x41,0x42,0x43,0x44,0x45,0x46,0x46,0x47,0x48,0x49,0x4a,0x46,0x46,0x46,0x46,0x46,0x4b,0x44,0x4c,0x46,0x46,0x4d,0x41,0x4e,0x46,0x4f,0x41,0x50,0x51,0x52,0x53,0x46,0x46,0x46,0x46,0x46,0x54,0x55,0x56,0x57,
        
        //紅點
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+COL(11)),   //FONTBYTE2, 文字顏色
        7,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,0x50,
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x22,0x23,0x24,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,       
    
    
    //////////////////////////////////////////////////
    //row 14(64字) 
        //顯示ThinkVision      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE),   //FONTBYTE1, 文字Index
        47,_NON_AUTOINC,0x92,      
        0x58,0x59,0x5a,0x5b,0x59,0x5c,0x5d,0x5a,0x5e,0x46,0x46,0x46,0x5f,0x60,0x61,0x46,0x46,0x46,0x46,0x46,0x62,0x5a,0x63,0x46,0x46,0x64,0x5a,0x65,0x46,0x66,0x5a,0x67,0x68,0x69,0x6a,0x46,0x46,0x46,0x46,0x46,0x6b,0x6c,0x6d,0x6e,
    
        //紅點
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE+COL(11)),   //FONTBYTE2,  文字顏色
        7,_NON_AUTOINC,0x92,      
        0x50,0x50,0x50,0x50,
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x25,0x26,0x27,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 15(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x70,0x71,0x72,0x73,0x74,0x75,0x46,0x76,0x77,0x78,0x79,0x7a,0x62,0x5a,0x63,0x7b,0x7c,0x7d,0x7e,0x7f,0x46,0x80,0x5a,0x81,0x82,0x7c,0x83,0x84,0x85,0x86,0x87,0x88,0x46,0x89,0x8a,0x46,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x44,0x02,0x03,0x04,0x05,
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x28,0x29,0x2a,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 16(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x91,0x92,0x5a,0x93,0x94,0x6f,0x46,0x5a,0x95,0x96,0x5a,0x97,0x62,0x5a,0x63,0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,0xa0,0xa1,0x5a,0xa2,0x5d,0x5a,0xa3,0xa4,0x5a,0x93,0xa5,0x6f,0xa6,0x5a,0xa7,0xa8,0x5a,0xa9,0xaa,0x5a,0x06,0x07,0x5a,0x08,
        
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x2b,0x2c,0x2d,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,        
    
    //////////////////////////////////////////////////
    //row 17(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0xae,0xaf,0xb0,0x46,0xb1,0x5a,0xb2,0xb3,0xb4,0x46,0xa1,0x5a,0xa2,0xb5,0x5a,0xb6,0xb7,0xb8,0xb9,0xa5,0x6f,0xad,0x5a,0xac,0xba,0x5a,0x97,0xaa,0x5a,0x08,0x62,0x5a,0x08, 
        
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x2e,0x2f,0x30,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40, 
    
    //////////////////////////////////////////////////
    //row 18(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0xbb,0x5a,0xbc,0x46,0xbd,0x5a,0xbe,0x5a,0xbf,0x46,0xa1,0x5a,0xa2,0xc0,0xc1,0x5a,0xc2,0xc3,0x46,0xa5,0x6f,0xad,0x5a,0xac,0xba,0x5a,0x97,0xaa,0x5a,0x08,0x62,0x5a,0x08,   
        
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x31,0x32,0x33,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,       
    
    
    //////////////////////////////////////////////////
    //row 19(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0xc4,0x5a,0xc5,0x46,0xc6,0x5a,0xc7,0x5a,0xc8,0x46,0xa1,0x5a,0xa2,0xc9,0xca,0xcb,0x5a,0xcc,0xcd,0xa5,0x6f,0xad,0x5a,0xac,0xba,0x5a,0x97,0xaa,0x5a,0x08,0x62,0x5a,0x08, 
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x34,0x35,0x36,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,        
    
    
    //////////////////////////////////////////////////
    //row 20(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0x63,0xce,0xcf,0x73,0xd0,0x5a,0xd1,0x5a,0xd2,0x46,0xa1,0x5a,0xa2,0x5d,0x5a,0x93,0xd3,0x5a,0x93,0xa5,0x6f,0xad,0x5a,0xac,0xba,0x5a,0x97,0xaa,0x5a,0x08,0x62,0x5a,0x08, 
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x37,0x38,0x39,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,        
    
    
    //////////////////////////////////////////////////
    //row 21(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0x63,0xd4,0x5a,0xd5,0xd6,0x5a,0x5a,0x5a,0xd7,0x46,0xa1,0x5a,0xa2,0xd8,0x5a,0xd9,0xda,0x5a,0xdb,0xa5,0x6f,0xdc,0x5a,0xdd,0xde,0x5a,0xdf,0xaa,0x5a,0x08,0x62,0x5a,0x08,     
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x3a,0x3b,0x3c,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,    
    
    //////////////////////////////////////////////////
    //row 22(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9+COL(48)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        12,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x8c,0x2c,0x8c,0x8c,0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9),   //FONTBYTE1, 文字Index
        60,_NON_AUTOINC,0x92,      
        0x46,0x46,0xe0,0xe1,0x46,0x46,0xe2,0xe0,0xe3,0xe4,0xe0,0xe5,0xe6,0xe1,0x46,0xe0,0xe7,0xe8,0xe0,0xe9,0xea,0xe0,0xeb,0xec,0xe0,0xed,0xee,0xe0,0xe0,0xe0,0xef,0x46,0xf0,0xe0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0x46,0xf7,0xe1,0x46,0xf8,0xf9,0xfa,0xfb,0x00,0x01,0xe0,0x09,0xea,0xe0,0x09,0x0a,0x0b,
        
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x3d,0x3e,0x3f,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,   
        
#if(_EPA_LOGO==_ON)	
    //EPA LOGO
    //////////////////////////////////////////////////
    //row 24  
        //顯示sion
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 25
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    
    //////////////////////////////////////////////////
    //row 26
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 27
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 28
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 29
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 30
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif
        
#elif((_PANEL_DH_WIDTH == 1680) && (_PANEL_DV_HEIGHT == 1050))
//Logo1680x1050 視窗大小非正方形28字高
//////////////////////////////////////////////////
//row 0(12字,1~6blank=20字,7blank=8字)      
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x00,0x01,        

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,         

//////////////////////////////////////////////////
//row 1(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x07,0x08,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,     
    
//////////////////////////////////////////////////
//row 2(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x0e,0x0f,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,       

//////////////////////////////////////////////////
//row 3(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
    13,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x1b,0x1c,0x1d,
      
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    13,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,        

//////////////////////////////////////////////////
//row 4(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x22,0x23,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,         

//////////////////////////////////////////////////
//row 5(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
    13,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x28,0x29,0x2a,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    13,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,      

//////////////////////////////////////////////////
//row 6(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x2f,0x30,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,

//////////////////////////////////////////////////
//row 7(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
    13,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x35,0x36,0x37,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    13,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 8(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x03,0x04,0x05,0x06,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 9(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
    15,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x09,0x0a,0x0b,0x0c,0x0d,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    15,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 10(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
    15,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x10,0x11,0x12,0x13,0x14,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    15,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 11(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x17,0x18,0x19,0x1a,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,      

//////////////////////////////////////////////////
//row 12(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x1e,0x1f,0x20,0x21,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,  
    
//////////////////////////////////////////////////
//row 13(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x24,0x25,0x26,0x27,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,         


//////////////////////////////////////////////////
//row 14(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x2b,0x2c,0x2d,0x2e,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,         

//////////////////////////////////////////////////
//row 15       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,     
    0x70,0x71,0x71,0x71,0x71,0x71,0x71,0x72,0x73,0x74,0x75,0x02,0x02,0x02,0x02,0x77,0x78,0x79,0x7a,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x7b,0x74,0x7c,0x02,0x02,0x02,0x7d,0x74,0x74,0x7e,0x02,0x7f,0x74,0x74,0x80,0x81,0x82,0x83,
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(15)),  //FONTBYTE2, 屬性(使用char blank顏色設定)
    7,_NON_AUTOINC,0x92,     
    0x50,0x50,0x50,0x50,
    
    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(53)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    6,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(53)),   //FONTBYTE1, 文字Index
    6,_NON_AUTOINC,0x92,      
    0x01,0x02,0x03,
 
    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x31,0x32,0x33,0x34,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 16       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x84,0x85,0x85,0x85,0x85,0x85,0x85,0x86,0x87,0x85,0x88,0x02,0x2,0x02,0x02,0x89,0x85,0x85,0x8a,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x8b,0x85,0x8c,0x02,0x02,0x02,0x8d,0x85,0x85,0x8e,0x02,0x8f,0x85,0x90,0x91,0x92,0x85,0x93, 
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(15)),  //FONTBYTE2, 屬性(使用char blank顏色設定)
    7,_NON_AUTOINC,0x92,     
    0x50,0x50,0x50,0x50,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(53)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    6,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(53)),   //FONTBYTE1, 文字Index
    6,_NON_AUTOINC,0x92,      
    0x04,0x05,0x06,
 
    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x38,0x39,0x2d,0x3a,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,   
    
//////////////////////////////////////////////////
//row 17       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x94,0x95,0x96,0x85,0x85,0x97,0x95,0x98,0x87,0x85,0x88,0x99,0x9a,0x9b,0x02,0x9c,0x9d,0x9e,0x9f,0x02,0x02,0x02,0x02,0xa0,0xa1,0x02,0x02,0x8b,0x85,0x8c,0x02,0xa2,0xa2,0xa3,0x85,0x85,0xa4,0x02,0xa5,0x85,0xa6,0x02,0xa7,0xa8,0xa9, 

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(15)),  //FONTBYTE2, 屬性(使用char blank顏色設定)
    7,_NON_AUTOINC,0x92,     
    0x50,0x50,0x50,0x50,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(47)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    26,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(47)),   //FONTBYTE1, 文字Index
    26,_NON_AUTOINC,0x92,      
    0x07,0x08,0x09,0x0a,0x00,0x00,0x0b,0x0c,0x0d,0x00,0x00,0x0e,0x0f,0x10,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x13,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x3b,0x3c,0x3d,0x3e,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 18       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0xac,0xad,0x85,0xae,0xaf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0x85,0xb3,0x85,0x85,0xb4,0x02,0x8b,0x85,0x8c,0xb5,0x85,0x85,0xb6,0xb7,0x85,0xb8,0x02,0xb9,0x85,0xba,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(46)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    28,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(46)),   //FONTBYTE1, 文字Index
    28,_NON_AUTOINC,0x92,      
    0x14,0x15,0x05,0x05,0x16,0x17,0x00,0x18,0x05,0x19,0x00,0x1a,0x1b,0x05,0x05,0x1c,0x1d,0x00,0x1e,0x05,0x1f,0x20,0x05,0x05,0x21, 

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x3f,0x40,0x41,0x42,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 19       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0xbc,0xbd,0xbe,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc0,0xc1,0xc2,0x85,0x88,0x02,0x8b,0x85,0x8c,0xc3,0x85,0xc4,0x02,0xc5,0x85,0xc6,0x02,0xc7,0x85,0xc8,0x02,0xbb,0x85,0x8c, 

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92,      
    0x22,0x05,0x05,0x23,0x24,0x05,0x25,0x00,0x18,0x05,0x19,0x00,0x26,0x05,0x27,0x28,0x05,0x05,0x29,0x1e,0x05,0x2a,0x2b,0x2c,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x43,0x44,0x45,0x46,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 20       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0x8c,0xcb,0x85,0xcc,0x02,0xcd,0x85,0xce,0x02,0xcf,0x85,0xd0,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92, 
    0x2d,0x05,0x05,0x2e,0x2f,0x05,0x05,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,    

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x47,0x48,0x49,0x4a,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 21       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0xd1,0xd2,0x85,0xd3,0x02,0xd4,0x85,0xd5,0xd6,0x85,0x85,0xd7,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92, 
    0x34,0x35,0x05,0x36,0x37,0x38,0x39,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x4b,0x4c,0x4d,0x4e,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 22       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0xd8,0x85,0xd9,0xda,0x02,0xdb,0x85,0xdc,0xdd,0x85,0x85,0xde,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(46)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    28,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(46)),   //FONTBYTE1, 文字Index
    28,_NON_AUTOINC,0x92, 
    0x3a,0x3b,0x05,0x3c,0x3d,0x3e,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,
    
    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x4f,0x50,0x51,0x52,
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 23      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0xdf,0x85,0x85,0xe0,0x02,0xe1,0x85,0x85,0xe2,0x85,0x85,0xe3,0x02,0xbb,0x85,0x8c,
    
    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(47)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    27,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(47)),   //FONTBYTE1, 文字Index
    27,_NON_AUTOINC,0x92, 
    0x3f,0x40,0x05,0x05,0x41,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x53,0x54,0x55,0x56,
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 24      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0x8c,0xe4,0x85,0xe5,0x02,0xe6,0x85,0x85,0xe7,0x85,0xe8,0x02,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92, 
    0x42,0x43,0x43,0x44,0x45,0x05,0x46,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x57,0x4d,0x58,0x59,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 25      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10),         //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0x8c,0xe9,0x85,0xea,0x02,0xeb,0x85,0x85,0x85,0x85,0xec,0x02,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92,    
    0x2d,0x05,0x05,0x32,0x47,0x05,0x05,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x5a,0x5b,0x5c,0x5d,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 26      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11),         //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0x8c,0xed,0x85,0x85,0xee,0x02,0xef,0x85,0x85,0x85,0xf0,0x02,0x02,0xbb,0x85,0x8c,
    
    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92,    
    0x48,0x05,0x05,0x49,0x4a,0x05,0x4b,0x00,0x18,0x05,0x19,0x00,0x4c,0x05,0x4d,0x4e,0x05,0x05,0x4f,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x5e,0x5f,0x60,0x61,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 27      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12),         //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xf1,0xf2,0xf2,0xf3,0x02,0x02,0xf4,0xf5,0xf6,0x02,0xf7,0xf5,0xf8,0xf9,0xf2,0xf2,0xfa,0xfb,0xf2,0x65,0x02,0x66,0xf2,0x67,0x02,0x68,0xf2,0x69,0x6a,0x6b,0xf2,0x6c,0x02,0x6d,0xf5,0xf5,0xf5,0x6e,0x02,0x02,0x6f,0xf2,0x69, 
   
    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(46)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    30,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(46)),   //FONTBYTE1, 文字Index
    30,_NON_AUTOINC,0x92,    
    0x50,0x51,0x52,0x53,0x54,0x55,0x00,0x56,0x57,0x58,0x00,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x00,0x5f,0x57,0x60,0x00,0x5f,0x57,0x58,0x61,0x62,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x02,0x62,0x63,0x64,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,

#if(_EPA_LOGO==_ON)	
//EPA LOGO
//////////////////////////////////////////////////
//row 30  
    //顯示sion

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,  

//////////////////////////////////////////////////
//row 31

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 


//////////////////////////////////////////////////
//row 32

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 

//////////////////////////////////////////////////
//row 33

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,  

//////////////////////////////////////////////////
//row 34

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 35

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 36

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,      
#endif

#elif((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
      //Logo19200x1080 視窗大小非正方形32字高
    //////////////////////////////////////////////////
    //row 0(13字,1~6blank=20字,7blank=19字)      
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x00,0x01,0x02,        

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 1(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x06,0x07,0x08,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 2(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x0f,0x10,0x11,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 3(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x18,0x19,0x1a,
          
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 4(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x1f,0x20,0x21,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 5(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x26,0x27,0x28,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,               

    //////////////////////////////////////////////////
    //row 6(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x2d,0x2e,0x2f,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

      
    //////////////////////////////////////////////////
    //row 7(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x34,0x35,0x36,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 8(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x3b,0x3c,0x3d,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 9(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x42,0x43,0x44,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 10(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x04,0x05,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 11(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
        16,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        16,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 12(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
        16,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x12,0x13,0x14,0x15,0x16,0x17,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        16,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 13(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x1b,0x1c,0x1d,0x1e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 14(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x22,0x23,0x24,0x25,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 15(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x29,0x2A,0x2b,0x2c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,      
        
    //////////////////////////////////////////////////
    //row 16(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*16),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*16),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x30,0x31,0x32,0x33,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*16),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 17(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*17),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*17),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x37,0x38,0x39,0x3a,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*17),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       
        
    //////////////////////////////////////////////////
    //row 18(89字)       
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18),          //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x75,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x77,0x78,0x79,0x7a,0x03,0x03,0x03,0x03,0x7b,0x7c,0x7d,0x7e,0x7f,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x80,0x79,0x79,0x81,0x03,0x03,0x03,0x82,0x79,0x79,0x83,0x03,0x84,0x79,0x79,0x85,

        //改變顏色(紅點)
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(16)),          //FONTBYTE1, 文字Index
        8,_NON_AUTOINC,0x92,      
        0x50,0x50,0x50,0x50,0x50,

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        19,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(45)),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,      
        0x05,0x06,0x07,0x08,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x0a,0x0b,0x0c,0x0d,
      
        //blank設定    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x3e,0x3f,0x40,0x41,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 19(89字)  
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE),   //FONTBYTE0, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x86,0x87,0x87,0x87,0x87,0x87,0x87,0x87,0x88,0x89,0x87,0x8a,0x03,0x03,0x03,0x03,0x8b,0x8c,0x87,0x8d,0x8e,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x8f,0x87,0x87,0x90,0x03,0x03,0x03,0x91,0x87,0x87,0x92,0x03,0x93,0x87,0x87,0x94,    

        //改變顏色(紅點)
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(16)),          //FONTBYTE1, 文字Index
        8,_NON_AUTOINC,0x92,      
        0x50,0x50,0x50,0x50,0x50,

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        19,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(45)),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,      
        0x0e,0x0f,0x10,0x11,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x12,0x10,0x10,0x14,//0x13,0x14,
     
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x45,0x46,0x0a,0x47,
       
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,


    //////////////////////////////////////////////////
    //row 20(89字)    
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2),   //FONTBYTE0, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x95,0x96,0x96,0x87,0x87,0x97,0x96,0x96,0x98,0x89,0x87,0x8a,0x03,0x99,0x9a,0x03,0x03,0x9b,0x9c,0x9d,0x03,0x03,0x03,0x03,0x03,0x9e,0x9f,0x03,0x03,0x8f,0x87,0x87,0x90,0x03,0x03,0x03,0xa0,0x87,0x87,0xa1,0x03,0xa2,0x87,0x87,0xa3,    

        //改變顏色(紅點)
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(16)),          //FONTBYTE1, 文字Index
        8,_NON_AUTOINC,0x92,      
        0x50,0x50,0x50,0x50,0x50,
        
        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        19,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(45)),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,      
        0x15,0x16,0x17,0x18,0x09,0x09,0x19,0x1a,0x1b,0x1c,0x09,0x09,0x1d,0x1e,0x1f,0x20,
     
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x48,0x49,0x4a,0x4b,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 21(89字)    
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0xa4,0xa5,0x87,0x87,0xa6,0x03,0xa7,0x87,0xa8,0x03,0xa9,0xaa,0xab,0xac,0xad,0x87,0xae,0x03,0x8f,0x87,0x87,0x90,0xaf,0x87,0x87,0xb0,0x87,0x87,0xb1,0x03,0xb2,0x87,0x87,0xb3,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x09,0x29,0x2a,0x10,0x10,0x2b,0x2c,0x2d,0x2e,0x10,0x10,0x2f,0x09,0x30,0x31,0x10,0x10,0x10,0x32,0x33,0x09,0x34,0x10,0x35,0x36,0x10,0x10,0x37,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x4c,0x4d,0x4e,0x4f,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 22(89字)      
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0xb4,0xb5,0xb6,0x87,0xb7,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xb9,0xba,0xbb,0x87,0x87,0xbc,0x8f,0x87,0x87,0x90,0xbd,0x87,0xbe,0x03,0xbf,0x87,0xc0,0x03,0xc1,0x87,0x87,0xc2,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x38,0x10,0x10,0x39,0x3a,0x10,0x10,0x3b,0x2e,0x10,0x10,0x3c,0x3d,0x3e,0x10,0x3f,0x40,0x10,0x10,0x41,0x09,0x34,0x10,0x42,0x43,0x44,0x10,0x45,
        
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x50,0x51,0x52,0x53,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,    

    //////////////////////////////////////////////////
    //row 23(89字)   
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xc3,0xc4,0x87,0xc5,0x03,0xc6,0x87,0xc7,0x03,0xc8,0x87,0x87,0xc9,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x46,0x10,0x10,0x47,0x09,0x10,0x10,0x48,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(80)),   //FONTBYTE0, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x54,0x55,0x0a,0x56,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,    
      
    //////////////////////////////////////////////////
    //row 24(89字)    
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6),          //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xca,0x87,0x87,0xcb,0x03,0xcc,0x87,0x87,0xcd,0xce,0x87,0xcf,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x4b,0x4c,0x10,0x4d,0x4e,0x4f,0x50,0x51,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,
     
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x57,0x58,0x59,0x5a,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     
      
    //////////////////////////////////////////////////
    //row 25(89字)     
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xd0,0x87,0xd1,0xd2,0x03,0xd3,0x87,0x87,0xd4,0xd5,0x87,0xd6,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+13*18+89*7+COL(45)),                                     //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x09,0x52,0x53,0x10,0x54,0x55,0x09,0x09,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x09,0x5b,0x5c,0x5d,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     
      
    //////////////////////////////////////////////////
    //row 26(89字)    
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xd7,0x87,0xd8,0xd9,0x03,0xda,0x87,0x87,0xdb,0x87,0x87,0xdc,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x09,0x09,0x56,0x57,0x10,0x10,0x58,0x59,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x5e,0x5f,0x60,0x61,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     
       
    //////////////////////////////////////////////////
    //row 27(89字)    
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xdd,0x87,0x87,0xde,0x03,0xdf,0x87,0x87,0xe0,0x87,0x87,0xe1,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x5a,0x5b,0x5b,0x5c,0x5d,0x10,0x10,0x5e,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x62,0x63,0x64,0x65,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     

    //////////////////////////////////////////////////
    //row 28(89字)   
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10),          //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xe2,0x87,0x87,0xe3,0x03,0xe4,0x87,0x87,0xe5,0x87,0x87,0xe6,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x46,0x10,0x10,0x5f,0x60,0x10,0x10,0x48,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,
        
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x66,0x67,0x68,0x69,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     
       
    //////////////////////////////////////////////////
    //row 29(89字)     
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0x90,0xe7,0x87,0xe8,0x03,0xe9,0x87,0x87,0x87,0x87,0x87,0xea,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x46,0x10,0x10,0x5f,0x2e,0x10,0x10,0x48,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x6a,0x6b,0x6c,0x6d,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     

    //////////////////////////////////////////////////
    //row 30(89字)    
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12),            //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0x90,0xeb,0x87,0xec,0xed,0x03,0xee,0x87,0x87,0x87,0x87,0xef,0x03,    
      
        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        37,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(45)),   //FONTBYTE1, 文字Index
        37,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x61,0x62,0x10,0x63,0x64,0x10,0x10,0x65,0x2e,0x10,0x10,0x3c,0x66,0x67,0x10,0x68,0x69,0x10,0x10,0x6a,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,0x09,0x6b,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x6e,0x6f,0x70,0x71,   
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,   

    //////////////////////////////////////////////////
    //row 31(89字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(33)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        14,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,0x8c,0x2c,0x8c,0x8c,0x8c,0x2c,0x2c,   
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0xf0,0xf0,0xf1,0x03,0x03,0x03,0xf2,0xf0,0xf3,0x03,0xf4,0xf0,0xf5,0x03,0xf6,0xf0,0xf7,0x03,0xf4,0xf0,0xf5,0x03,0xf8,0xf0,0xf0,0xf9,0xfa,0xf0,0xf0,0xfb,0x00,0xf0,0xf0,0x01,0x03,0x02,0xf0,0xf0,0xf0,0x03,0x04,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        38,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(45)),   //FONTBYTE1, 文字Index
        38,_NON_AUTOINC,0x92,      
        0x6c,0x50,0x50,0x6d,0x09,0x6e,0x6f,0x70,0x71,0x72,0x73,0x74,0x75,0x50,0x50,0x76,0x09,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x09,0x7e,0x50,0x7f,0x09,0x80,0x50,0x81,0x09,0x82,0x83,
      
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(80)),    //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(80)),    //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x03,0x72,0x73,0x74,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,   


#if(_EPA_LOGO==_ON)	
//EPA LOGO
//////////////////////////////////////////////////
//row 26  
    //顯示sion

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 

//////////////////////////////////////////////////
//row 27

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   

//////////////////////////////////////////////////
//row 28

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 29

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 30

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 31

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 32

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif

#endif

    _END,
};

#elif(_LOGO_TYPE == _LENOVO)

BYTE code LENOVO_LOGO_COMMAND[]=
{
    //////////////////////////////////////////////////
    //row 0
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x00,0x01,0x02,0x03,0x04,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    //////////////////////////////////////////////////
    //row 1
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x00,0x06,0x03,0x03,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,
    0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x21,
    0x23,0x00,0x24,0x21,0x21,0x27,0x28,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    //////////////////////////////////////////////////
    //row 2
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x2F,0x30,0x03,0x31,0x32,0x33,0x03,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x03,0x3B,
    0x3C,0x3D,0x03,0x03,0x3E,0x3F,0x03,0x40,0x41,0x00,0x42,0x03,0x03,0x43,0x03,0x03,
    0x44,0x45,0x46,0x03,0x47,0x48,0x03,0x40,0x41,0x00,0x42,0x03,0x03,0x69,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    //////////////////////////////////////////////////
    //row 3
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x4D,0x03,0x03,0x4E,0x4F,0x03,0x03,0x50,0x51,0x52,0x53,0x54,0x55,0x03,0x03,0x56,
    0x57,0x58,0x03,0x59,0x5A,0x5B,0x03,0x5C,0x5D,0x5E,0x03,0x5F,0x60,0x61,0x03,0x03,
    0x62,0x63,0x64,0x65,0x66,0x67,0x03,0x5C,0x5D,0x5E,0x03,0x5F,0x60,0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    //////////////////////////////////////////////////
    //row 4
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x6D,0x4c,0x4c,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x6e,0x6f,0x26,0x68,0x22,
    0x25,0x26,0x26,0x29,0x00,0x2A,0x2B,0x2C,0x2D,0x2E,0x49,0x4A,0x00,0x00,0x4B,0x4C,
    0x4c,0x4c,0x6A,0x00,0x00,0x6B,0x6C,0x2C,0x2D,0x2E,0x49,0x4A,0x00,0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,

#if(_EPA_LOGO==_ON)	
    //////////////////////////////////////////////////
    //row 5
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////
    //row 6
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*1),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*1),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////
    //row 7
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////
    //row 8
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////
    //row 9
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////

    //EPA LOGO
    //////////////////////////////////////////////////
    //row 10  
    //顯示sion

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 

    //////////////////////////////////////////////////
    //row 11

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   

    //////////////////////////////////////////////////
    //row 12

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 13

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 14

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 15

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 16

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif

    _END,

};

#endif

#else
//------------------------------------
//Main menulogo
//------------------------------------
// 20110915 Lexie, B010 modify poweron LOGO

BYTE code LENOVO_LOGO_COMMAND[]=
{

//////////////////////////////////////////////////
    //row0
    
    5,_AUTOINC,0x90,0x10,0x0A,  //FONTBYTE0(10),
    58,_NON_AUTOINC,0x92,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,
//    0x8c,_REPEAT_,55,
//    _NEXT_,
    
    5,_AUTOINC,0x90,0x50,0x0A,  //FONTBYTE1(10),
    58,_NON_AUTOINC,0x92,
    0x00,0x00,LOGO_1bit(0x00),LOGO_1bit(0x01),LOGO_1bit(0x01),LOGO_1bit(0x01),LOGO_1bit(0x02),0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,
//    0x00,0x00,LOGO_1bit(0x00),LOGO_1bit(0x01),_REPEAT_,3,LOGO_1bit(0x02),0x00,_REPEAT_,48,  //1~7
//    _NEXT_,

    5,_AUTOINC,0x90,0x90,0x0A,  //FONTBYTE2(10),
    58,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,
//    0x10,_REPEAT_,55,
//    _NEXT_,

//////////////////////////////////////////////////
    //row 1
    5,_AUTOINC,0x90,0x10,0x41,  //FONTBYTE0(65),
    58,_NON_AUTOINC,0x92,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,
//    0x8c,_REPEAT_,55,
//    _NEXT_,

    5,_AUTOINC,0x90,0x50,0x41,  //FONTBYTE1(65),
    13,_NON_AUTOINC,0x92,
    0x00,0x00,LOGO_1bit(0x03),0x00,0x00,0x00,LOGO_1bit(0x04),0x00,0x00,0x00,
//    0x00,0x00,LOGO_1bit(0x03),0x00,_REPEAT_,3,LOGO_1bit(0x04),0x00,_REPEAT_,3,  // 1~10
//    _NEXT_,

    5,_AUTOINC,0x90,0x90,0x41,  //FONTBYTE2(65),
    12,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x01,0x01,0x01,0x10,0x10,0x10,
//    0x10,_REPEAT_,3,0x01,_REPEAT_,3,0x10,_REPEAT_,3,
//    _NEXT_,

//////////////////////////////////////////////////
    //row 2
    5,_AUTOINC,0x90,0x10,0x78,  //FONTBYTE0(120),
    58,_NON_AUTOINC,0x92,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,
//    0x8c,_REPEAT_,55,
//    _NEXT_,

    5,_AUTOINC,0x90,0x50,0x78,  //FONTBYTE1(120),
    56,_NON_AUTOINC,0x92,
    0x00,0x00,LOGO_1bit(0x05),0x00,0x00,LOGO_1bit(0x06),LOGO_1bit(0x07),LOGO_1bit(0x08),LOGO_1bit(0x09),LOGO_1bit(0x0a),
    LOGO_1bit(0x0b),LOGO_1bit(0x0c),LOGO_1bit(0x0d),LOGO_1bit(0x0e),LOGO_1bit(0x0f),LOGO_1bit(0x10),LOGO_1bit(0x11),LOGO_1bit(0x12),LOGO_1bit(0x13),LOGO_1bit(0x14),
    LOGO_1bit(0x15),LOGO_1bit(0x0d),LOGO_1bit(0x16),LOGO_1bit(0x0e),LOGO_1bit(0x17),LOGO_1bit(0x18),LOGO_1bit(0x19),LOGO_1bit(0x1a),LOGO_1bit(0x1b),LOGO_1bit(0x0b),
    LOGO_1bit(0x1c),LOGO_1bit(0x0d),LOGO_1bit(0x1d),LOGO_1bit(0x1e),LOGO_1bit(0x1f),LOGO_1bit(0x20),LOGO_1bit(0x20),LOGO_1bit(0x21),0x00,LOGO_1bit(0x22),
    LOGO_1bit(0x23),LOGO_1bit(0x20),LOGO_1bit(0x20),LOGO_1bit(0x24),LOGO_1bit(0x25),LOGO_1bit(0x09),LOGO_1bit(0x26),LOGO_1bit(0x27),LOGO_1bit(0x28),LOGO_1bit(0x0d),
    LOGO_1bit(0x29),LOGO_1bit(0x2a),LOGO_1bit(0x2b),
//    0x00,0x00,LOGO_1bit(0x05),0x00,0x00,LOGO_1bit(0x06),LOGO_1bit(0x07),LOGO_1bit(0x08),LOGO_1bit(0x09),LOGO_1bit(0x0a),   //1~10
//    LOGO_1bit(0x0b),LOGO_1bit(0x0c),LOGO_1bit(0x0d),LOGO_1bit(0x0e),LOGO_1bit(0x0f),LOGO_1bit(0x10),LOGO_1bit(0x11),LOGO_1bit(0x12),LOGO_1bit(0x13),LOGO_1bit(0x14), //11~20
//    LOGO_1bit(0x15),LOGO_1bit(0x0d),LOGO_1bit(0x16),LOGO_1bit(0x0e),LOGO_1bit(0x17),LOGO_1bit(0x18),LOGO_1bit(0x19),LOGO_1bit(0x1a),LOGO_1bit(0x1b),LOGO_1bit(0x0b), //21~30
//    LOGO_1bit(0x1c),LOGO_1bit(0x0d),LOGO_1bit(0x1d),LOGO_1bit(0x1e),LOGO_1bit(0x1f),LOGO_1bit(0x20),LOGO_1bit(0x20),LOGO_1bit(0x21),0x00,LOGO_1bit(0x22),   //31~40
//    LOGO_1bit(0x23),LOGO_1bit(0x20),LOGO_1bit(0x20),LOGO_1bit(0x24),LOGO_1bit(0x25),LOGO_1bit(0x09),LOGO_1bit(0x26),LOGO_1bit(0x27),LOGO_1bit(0x28),LOGO_1bit(0x0d), //41~50
//    LOGO_1bit(0x29),LOGO_1bit(0x2a),LOGO_1bit(0x2b),    //51~53
//    _NEXT_,

    5,_AUTOINC,0x90,0x90,0x78,  //FONTBYTE2(120),
    56,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x01,0x01,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,
//    0x10,_REPEAT_,3,0x01,0x01,0x10,_REPEAT_,5, //1~10
//    0x10,_REPEAT_,10,    //11~20
//    0x10,_REPEAT_,10,    //21~30
//    0x10,_REPEAT_,10,    //31~40
//    0x10,_REPEAT_,10,    //41~50
//    0x10,_REPEAT_,3,    //51~53
//    _NEXT_,
      
//////////////////////////////////////////////////
    //row 3
    5,_AUTOINC,0x90,0x10,0xAF,  //FONTBYTE0(175),
    56,_NON_AUTOINC,0x92,
    0x8c,0x8c,0x8c,0x8c,0x8c,0xa0,0xa0,0x8c,0xa0,0xa0,
    0x8c,0xa6,0xa6,0xa6,0xa6,0xa6,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,
//    0x8c,_REPEAT_,5,    // 1~5
//    0xa0,0xa0,0x8c,0xa0,0xa0,0x8c,0xa6,_REPEAT_,5,   // 6~16
//    0x8c,_REPEAT_,11,   // 17~27
//    0x8c,_REPEAT_,11,   // 18~28
//    0x8c,_REPEAT_,11,   //19~29
//    0x8c,_REPEAT_,4,    // 30~33
//    _NEXT_,

    5,_AUTOINC,0x90,0x50,0xAF,  //FONTBYTE1(175),
    56,_NON_AUTOINC,0x92,
    0x00,LOGO_1bit(0x2c),0x00,0x00,0x00,LOGO_2bit(0x00),LOGO_2bit(0x01),LOGO_1bit(0x3e),LOGO_2bit(0x02),LOGO_2bit(0x03),
    LOGO_1bit(0x4a),LOGO_2bit(0x04),LOGO_2bit(0x05),LOGO_2bit(0x06),LOGO_2bit(0x07),LOGO_2bit(0x08),0x00,0x00,LOGO_1bit(0x06),0x00,
    LOGO_1bit(0x2d),0x00,0x00,LOGO_1bit(0x2e),LOGO_1bit(0x2f),LOGO_1bit(0x30),0x00,LOGO_1bit(0x31),LOGO_1bit(0x32),0x00,
    LOGO_1bit(0x33),0x00,0x00,LOGO_1bit(0x31),LOGO_1bit(0x34),0x00,0x00,LOGO_1bit(0x35),LOGO_1bit(0x36),LOGO_1bit(0x37),
    0x00,LOGO_1bit(0x38),LOGO_1bit(0x39),LOGO_1bit(0x3a),0x00,0x00,LOGO_1bit(0x3b),0x00,LOGO_1bit(0x3c),0x00,
    0x00,0x00,LOGO_1bit(0x3d),
//    0x00,LOGO_1bit(0x2c),0x00,0x00,0x00,    //1~5
//    LOGO_2bit(0x00),LOGO_2bit(0x01),LOGO_1bit(0x3e),LOGO_2bit(0x02),LOGO_2bit(0x03),LOGO_1bit(0x4a),LOGO_2bit(0x04),LOGO_2bit(0x05),LOGO_2bit(0x06),LOGO_2bit(0x07),
//    LOGO_2bit(0x08),  // 6~16
//    0x00,0x00,LOGO_1bit(0x06),0x00,LOGO_1bit(0x2d),0x00,0x00,LOGO_1bit(0x2e),LOGO_1bit(0x2f),LOGO_1bit(0x30),0x00,  //17~27
//    LOGO_1bit(0x31),LOGO_1bit(0x32),0x00,LOGO_1bit(0x33),0x00,0x00,LOGO_1bit(0x31),LOGO_1bit(0x34),0x00,0x00,LOGO_1bit(0x35),    //18~28
//    LOGO_1bit(0x36),LOGO_1bit(0x37),0x00,LOGO_1bit(0x38),LOGO_1bit(0x39),LOGO_1bit(0x3a),0x00,0x00,LOGO_1bit(0x3b),0x00,LOGO_1bit(0x3c),//19~29
//    0x00,0x00,0x00,LOGO_1bit(0x3d), // 30~33
//    _NEXT_,

    5,_AUTOINC,0x90,0x90,0xAF,  //FONTBYTE2(175),
    56,_NON_AUTOINC,0x92,
    0x10,0x10,0x01,0x01,0x01,0x21,0x21,0x14,0x21,0x21,
    0x40,0x21,0x21,0x21,0x21,0x21,0x01,0x01,0x10,0x10,
    0x10,0x01,0x01,0x10,0x10,0x10,0x01,0x10,0x10,0x10,
    0x10,0x01,0x01,0x10,0x10,0x01,0x01,0x10,0x10,0x10,
    0x01,0x10,0x10,0x10,0x01,0x01,0x10,0x10,0x10,0x01,
    0x01,0x01,0x10,

//    0x10,0x10,0x01,0x01,0x01, //1~5
//    0x21,0x21,0x14,0x21,0x21,0x40,0x21,_REPEAT_,5,  //6~16
//    0x01,0x01,0x10,0x10,0x10,0x01,0x01,0x10,0x10,0x10,0x01,    //17~27
//    0x10,_REPEAT_,4,0x01,0x01,0x10,0x10,0x01,0x01,0x10, //18~28
//    0x10,0x10,0x01,0x10,_REPEAT_,3,0x01,0x01,0x10,_REPEAT_,3,   //19~29
//    0x01,_REPEAT_,3,0x10,   //30~33
//    _NEXT_,

//////////////////////////////////////////////////
    //row 4
    5,_AUTOINC,0x90,0x10,0xE6,  //FONTBYTE0(230),
    56,_NON_AUTOINC,0x92,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0xa0,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0xa0,0xa0,0x8c,0x8c,0xa0,0x8c,0x8c,
    0x8c,0x8c,0xa0,0xa0,0xa0,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0xa6,0xa0,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0xa0,0xa0,0x8c,
//    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c, // 1~7
//    0x8c,_REPEAT_,7,   // 8~14
//    0xa0,0x8c,_REPEAT_,8,0xa0,   //15~24
//    0xa0,0x8c,0x8c,0xa0,0x8c,_REPEAT_,3,0x8c,0xa0,0xa0,   //25~34
//    0xa0,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0xa6, //35~42
//    0xa0,0x8c,_REPEAT_,7,0xa0,_REPEAT_,2,0x8c,  //43~53
//    _NEXT_,

    5,_AUTOINC,0x90,0x50,0xE6,  //FONTBYTE1(230),
    56,_NON_AUTOINC,0x92,
    0x00,LOGO_1bit(0x4b),0x00,0x00,LOGO_1bit(0x4c),LOGO_1bit(0x4d),0x00,0x00,LOGO_1bit(0x4e),LOGO_1bit(0x4f),
    LOGO_1bit(0x50),LOGO_1bit(0x51),LOGO_1bit(0x52),LOGO_1bit(0x53),LOGO_2bit(0x09),LOGO_1bit(0x3f),LOGO_1bit(0x40),LOGO_1bit(0x41),LOGO_1bit(0x54),LOGO_1bit(0x55),
    LOGO_1bit(0x56),LOGO_1bit(0x42),LOGO_1bit(0x43),LOGO_2bit(0x0a),LOGO_2bit(0x0b),LOGO_1bit(0x44),LOGO_1bit(0x45),LOGO_2bit(0x0c),LOGO_1bit(0x57),LOGO_1bit(0x58),
    LOGO_1bit(0x59),LOGO_1bit(0x46),LOGO_2bit(0x0d),LOGO_2bit(0x0e),LOGO_2bit(0x0f),0x00,0x00,LOGO_1bit(0x5a),LOGO_1bit(0x5b),0x00,
    LOGO_1bit(0x6e),LOGO_2bit(0x10),LOGO_2bit(0x11),LOGO_1bit(0x47),LOGO_1bit(0x48),LOGO_1bit(0x49),LOGO_1bit(0x5c),LOGO_1bit(0x5d),LOGO_1bit(0x5e),LOGO_1bit(0x42),
    LOGO_2bit(0x12),LOGO_2bit(0x13),0x00,
//    0x00,LOGO_1bit(0x4b),0x00,0x00,LOGO_1bit(0x4c),LOGO_1bit(0x4d),0x00,    // 1~7
//    0x00,LOGO_1bit(0x4e),LOGO_1bit(0x4f),LOGO_1bit(0x50),LOGO_1bit(0x51),LOGO_1bit(0x52),LOGO_1bit(0x53),   // 8~14
//    LOGO_2bit(0x09),LOGO_1bit(0x3f),LOGO_1bit(0x40),LOGO_1bit(0x41),LOGO_1bit(0x54),LOGO_1bit(0x55),LOGO_1bit(0x56),LOGO_1bit(0x42),LOGO_1bit(0x43),
//    LOGO_2bit(0x0a),  //15~24
//    LOGO_2bit(0x0b),LOGO_1bit(0x44),LOGO_1bit(0x45),LOGO_2bit(0x0c),LOGO_1bit(0x57),LOGO_1bit(0x58),LOGO_1bit(0x59),LOGO_1bit(0x46),LOGO_2bit(0x0d),
//    LOGO_2bit(0x0e),  //25~34
//    LOGO_2bit(0x0f),0x00,0x00,LOGO_1bit(0x5a),LOGO_1bit(0x5b),0x00,LOGO_1bit(0x6e),LOGO_2bit(0x10), //35~42
//    LOGO_2bit(0x11),LOGO_1bit(0x47),LOGO_1bit(0x48),LOGO_1bit(0x49),LOGO_1bit(0x5c),LOGO_1bit(0x5d),LOGO_1bit(0x5e),LOGO_1bit(0x42),LOGO_2bit(0x12),
//    LOGO_2bit(0x13),0x00,    //43~53
//    _NEXT_,

    5,_AUTOINC,0x90,0x90,0xE6,  //FONTBYTE2(230),
    56,_NON_AUTOINC,0x92,
    0x10,0x40,0x04,0x04,0x40,0x40,0x04,0x04,0x40,0x40,
    0x40,0x40,0x40,0x40,0x21,0x14,0x14,0x14,0x40,0x40,
    0x40,0x14,0x14,0x21,0x21,0x14,0x14,0x21,0x40,0x40,
    0x40,0x14,0x21,0x21,0x21,0x04,0x04,0x40,0x40,0x04,
    0x04,0x21,0x21,0x14,0x14,0x14,0x40,0x40,0x40,0x14,
    0x21,0x21,0x10,
//    0x10,0x40,0x04,0x04,0x40,0x40,0x04,  // 1~7
//    0x04,0x40,_REPEAT_,6,   // 8~14
//    0x21,0x14,0x14,0x14,0x40,0x40,0x40,0x14,0x14,0x21,    //15~24
//    0x21,0x14,0x14,0x21,0x40,_REPEAT_,3,0x14,0x21,0x21,    //25~34
//    0x21,0x04,0x04,0x40,0x40,0x04,0x04,0x21,    //35~42
//    0x21,0x14,0x14,0x14,0x40,0x40,0x40,0x14,0x21,_REPEAT_,2,0x10,  //43~53
//    _NEXT_,

//////////////////////////////////////////////////
    //row 5
    5,_AUTOINC,0x90,0x11,0x1D,  //FONTBYTE0(285),
    56,_NON_AUTOINC,0x92,
    0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,
    0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0x8c,0xa4,
    0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,
    0xa4,0xa4,0xa4,0x8c,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,
    0xa4,0x8c,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,0xa4,
    0xa4,0x8c,0x8c,
//    0xa4,_REPEAT_,10, // 1~10
//    0xa4,_REPEAT_,8,0x8c,0xa4,  // 11~20
//    0xa4,_REPEAT_,10, // 21~30
//    0xa4,_REPEAT_,3,0x8c,0xa4,_REPEAT_,6, // 31~40
//    0xa4,0x8c,0xa4,_REPEAT_,8, // 41~50
//    0xa4,0x8c,0x8c,         //51~53
//    _NEXT_,

    5,_AUTOINC,0x90,0x51,0x1D,  //FONTBYTE1(285),
    56,_NON_AUTOINC,0x92,
    LOGO_2bit(0x14),LOGO_2bit(0x15),LOGO_2bit(0x15),LOGO_2bit(0x15),LOGO_2bit(0x16),LOGO_2bit(0x17),LOGO_2bit(0x18),LOGO_2bit(0x19),LOGO_2bit(0x1a),LOGO_2bit(0x1a),
    LOGO_2bit(0x1b),LOGO_2bit(0x1c),LOGO_2bit(0x1d),LOGO_2bit(0x1e),LOGO_2bit(0x1f),LOGO_2bit(0x20),LOGO_2bit(0x20),LOGO_2bit(0x21),0x00,LOGO_2bit(0x22),
    LOGO_2bit(0x23),LOGO_2bit(0x23),LOGO_2bit(0x23),LOGO_2bit(0x24),LOGO_2bit(0x17),LOGO_2bit(0x25),LOGO_2bit(0x26),LOGO_2bit(0x27),LOGO_2bit(0x27),LOGO_2bit(0x27),
    LOGO_2bit(0x28),LOGO_2bit(0x29),LOGO_2bit(0x2a),0x00,LOGO_2bit(0x2b),LOGO_2bit(0x23),LOGO_2bit(0x23),LOGO_2bit(0x23),LOGO_2bit(0x23),LOGO_2bit(0x23),
    LOGO_2bit(0x2c),0x00,LOGO_2bit(0x17),LOGO_2bit(0x25),LOGO_2bit(0x26),LOGO_2bit(0x27),LOGO_2bit(0x27),LOGO_2bit(0x27),LOGO_2bit(0x28),LOGO_2bit(0x29),
    LOGO_2bit(0x2d),0x00,0x00,
//    LOGO_2bit(0x14),LOGO_2bit(0x15),_REPEAT_,3,LOGO_2bit(0x16),LOGO_2bit(0x17),LOGO_2bit(0x18),LOGO_2bit(0x19),LOGO_2bit(0x1a),LOGO_2bit(0x1a), // 1~10
//    LOGO_2bit(0x1b),LOGO_2bit(0x1c),LOGO_2bit(0x1d),LOGO_2bit(0x1e),LOGO_2bit(0x1f),LOGO_2bit(0x20),LOGO_2bit(0x20),LOGO_2bit(0x21),
//    0x00,LOGO_2bit(0x22),  // 11~20
//    LOGO_2bit(0x23),_REPEAT_,3,LOGO_2bit(0x24),LOGO_2bit(0x17),LOGO_2bit(0x25),LOGO_2bit(0x26),LOGO_2bit(0x27),_REPEAT_,3,  // 21~30
//    LOGO_2bit(0x28),LOGO_2bit(0x29),LOGO_2bit(0x2a),0x00,LOGO_2bit(0x2b),LOGO_2bit(0x23),_REPEAT_,5,  // 31~40
//    LOGO_2bit(0x2c),0x00,LOGO_2bit(0x17),LOGO_2bit(0x25),LOGO_2bit(0x26),LOGO_2bit(0x27),_REPEAT_,3,LOGO_2bit(0x28),LOGO_2bit(0x29),  // 41~50
//    LOGO_2bit(0x2d),0x00,0x00,  // 51~53 
//    _NEXT_,

    5,_AUTOINC,0x90,0x91,0x1D,  //FONTBYTE2(285),
    56,_NON_AUTOINC,0x92,
    0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,
    0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x10,0x21,
    0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,
    0x21,0x21,0x21,0x10,0x21,0x21,0x21,0x21,0x21,0x21,
    0x21,0x10,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,
    0x21,0x10,0x10,
//    0x21,_REPEAT_,10,// 1~10
//    0x21,_REPEAT_,8,0x10,0x21,  // 11~20
//    0x21,_REPEAT_,10,// 21~30
//    0x21,_REPEAT_,3,0x10,0x21,_REPEAT_,6, // 31~40
//    0x21,0x10,0x21,_REPEAT_,8,// 41~50
//    0x21,0x10,0x10, //51~53
//    _NEXT_,

//////////////////////////////////////////////////
    //row6
    5,_AUTOINC,0x90,0x11,0x54,  //FONTBYTE0(340),
    55,_NON_AUTOINC,0x92,
    0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
    0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
    0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
    0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
    0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
    0xaa,0xaa,
//    0xaa,_REPEAT_,5,   //1~5
//    0xaa,_REPEAT_,9,   //6~14
//    0xaa,_REPEAT_,10,   //7~16
//    0xaa,_REPEAT_,10,   //17~26
//    0xaa,_REPEAT_,8,   //27~34
//    0xaa,_REPEAT_,10,   //35~44
//    _NEXT_,
    
    5,_AUTOINC,0x90,0x51,0x54,  //FONTBYTE1(340),
    55,_NON_AUTOINC,0x92,
    LOGO_2bit(0x2e),LOGO_2bit(0x2f),LOGO_2bit(0x30),LOGO_2bit(0x30),LOGO_2bit(0x31),LOGO_2bit(0x32),LOGO_2bit(0x50),LOGO_2bit(0x30),LOGO_2bit(0x33),LOGO_2bit(0x34),
    LOGO_2bit(0x35),LOGO_2bit(0x36),LOGO_2bit(0x37),LOGO_2bit(0x38),LOGO_2bit(0x39),LOGO_2bit(0x3d),LOGO_2bit(0x3d),LOGO_2bit(0x3a),LOGO_2bit(0x3b),LOGO_2bit(0x3c),
    LOGO_2bit(0x51),LOGO_2bit(0x3d),LOGO_2bit(0x3d),LOGO_2bit(0x3e),LOGO_2bit(0x3f),LOGO_2bit(0x30),LOGO_2bit(0x30),LOGO_2bit(0x40),LOGO_2bit(0x41),LOGO_2bit(0x42),
    LOGO_2bit(0x30),LOGO_2bit(0x43),LOGO_2bit(0x44),LOGO_2bit(0x45),LOGO_2bit(0x46),LOGO_2bit(0x3d),LOGO_2bit(0x3d),LOGO_2bit(0x3d),LOGO_2bit(0x3d),LOGO_2bit(0x3d),
    LOGO_2bit(0x47),LOGO_2bit(0x48),LOGO_2bit(0x49),LOGO_2bit(0x4a),LOGO_2bit(0x3d),LOGO_2bit(0x3d),LOGO_2bit(0x4b),LOGO_2bit(0x4c),LOGO_2bit(0x4d),LOGO_2bit(0x3d),
    LOGO_2bit(0x4e),LOGO_2bit(0x4f),
//    LOGO_2bit(0x2e),LOGO_2bit(0x2f),LOGO_2bit(0x30),LOGO_2bit(0x30),LOGO_2bit(0x31), // 1~5
//    LOGO_2bit(0x32),LOGO_2bit(0x50),LOGO_2bit(0x30),LOGO_2bit(0x33),LOGO_2bit(0x34),LOGO_2bit(0x35),LOGO_2bit(0x36),LOGO_2bit(0x37),LOGO_2bit(0x38), //6~14 
//    LOGO_2bit(0x39),LOGO_2bit(0x3d),LOGO_2bit(0x3d),LOGO_2bit(0x3a),LOGO_2bit(0x3b),LOGO_2bit(0x3c),LOGO_2bit(0x51),LOGO_2bit(0x3d),_REPEAT_,2,LOGO_2bit(0x3e),//7~16 
//    LOGO_2bit(0x3f),LOGO_2bit(0x30),LOGO_2bit(0x30),LOGO_2bit(0x40),LOGO_2bit(0x41),LOGO_2bit(0x42),LOGO_2bit(0x30),LOGO_2bit(0x43),LOGO_2bit(0x44),
//    LOGO_2bit(0x45),//17~26
//    LOGO_2bit(0x46),LOGO_2bit(0x3d),_REPEAT_,5,LOGO_2bit(0x47),LOGO_2bit(0x48), //27~34
//    LOGO_2bit(0x49),LOGO_2bit(0x4a),LOGO_2bit(0x3d),LOGO_2bit(0x3d),LOGO_2bit(0x4b),LOGO_2bit(0x4c),LOGO_2bit(0x4d),LOGO_2bit(0x3d),LOGO_2bit(0x4e),
//    LOGO_2bit(0x4f),//35~44 
//    _NEXT_,

    5,_AUTOINC,0x90,0x91,0x54,  //FONTBYTE2(340),
    55,_NON_AUTOINC,0x92,
    0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,
    0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,
    0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,
    0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,
    0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,0x2b,
    0x2b,0x2b,
//    0x2b,_REPEAT_,5,   //1~5
//    0x2b,_REPEAT_,9,   //6~14
//    0x2b,_REPEAT_,10,   //7~16
//    0x2b,_REPEAT_,10,   //17~26
//    0x2b,_REPEAT_,8,   //27~34
//    0x2b,_REPEAT_,10,   //35~44
//    _NEXT_,

//////////////////////////////////////////////////
    // row7
    5,_AUTOINC,0x90,0x11,0x8B,  //FONTBYTE0(395),
    56,_NON_AUTOINC,0x92,
    0x8c,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x8c,
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x8c,
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x8c,0x90,0x90,
    0x90,0x90,0x90,

//    0x8c,0x90,_REPEAT_,5,
//    0x90,_REPEAT_,13,
//    0x8c,0x90,_REPEAT_,9,
//    0x8c,0x90,_REPEAT_,17,
//    0x8c,0x90,_REPEAT_,5,    //row 1 and row 2 and row3 and row4
//    _NEXT_,
    
    5,_AUTOINC,0x90,0x51,0x8B,  //FONTBYTE1(395),
    56,_NON_AUTOINC,0x92,
    0x00,LOGO_4bit(0x00),LOGO_4bit(0x01),LOGO_4bit(0x01),LOGO_4bit(0x01),LOGO_4bit(0x02),LOGO_4bit(0x01),LOGO_4bit(0x01),LOGO_4bit(0x03),LOGO_4bit(0x04),
    LOGO_4bit(0x05),LOGO_4bit(0x06),LOGO_4bit(0x07),LOGO_4bit(0x08),LOGO_4bit(0x09),LOGO_4bit(0x0a),LOGO_4bit(0x0b),LOGO_4bit(0x01),LOGO_4bit(0x0c),0x00,
    LOGO_4bit(0x0d),LOGO_4bit(0x01),LOGO_4bit(0x0e),LOGO_4bit(0x0f),LOGO_4bit(0x10),LOGO_4bit(0x11),LOGO_4bit(0x01),LOGO_4bit(0x12),LOGO_4bit(0x13),0x00,
    LOGO_4bit(0x14),LOGO_4bit(0x01),LOGO_4bit(0x15),LOGO_4bit(0x16),LOGO_4bit(0x17),LOGO_4bit(0x01),LOGO_4bit(0x01),LOGO_4bit(0x18),LOGO_4bit(0x19),LOGO_4bit(0x01),
    LOGO_4bit(0x01),LOGO_4bit(0x1a),LOGO_4bit(0x1b),LOGO_4bit(0x1c),LOGO_4bit(0x1d),LOGO_4bit(0x01),LOGO_4bit(0x1e),0x00,LOGO_4bit(0x1f),LOGO_4bit(0x01),
    LOGO_4bit(0x20),LOGO_4bit(0x21),LOGO_4bit(0x22),
//    0x00,LOGO_4bit(0x00),LOGO_4bit(0x01),_REPEAT_,3,LOGO_4bit(0x02),
//    LOGO_4bit(0x01),LOGO_4bit(0x01),LOGO_4bit(0x03),LOGO_4bit(0x04),LOGO_4bit(0x05),LOGO_4bit(0x06),LOGO_4bit(0x07),LOGO_4bit(0x08),LOGO_4bit(0x09),
//    LOGO_4bit(0x0a),LOGO_4bit(0x0b),LOGO_4bit(0x01),LOGO_4bit(0x0c),0x00,LOGO_4bit(0x0d),LOGO_4bit(0x01),LOGO_4bit(0x0e),LOGO_4bit(0x0f),
//    LOGO_4bit(0x10),LOGO_4bit(0x11),LOGO_4bit(0x01),LOGO_4bit(0x12),LOGO_4bit(0x13),0x00,LOGO_4bit(0x14),LOGO_4bit(0x01),LOGO_4bit(0x15),LOGO_4bit(0x16),
//    LOGO_4bit(0x17),LOGO_4bit(0x01),LOGO_4bit(0x01),LOGO_4bit(0x18),LOGO_4bit(0x19),LOGO_4bit(0x01),LOGO_4bit(0x01),LOGO_4bit(0x1a),LOGO_4bit(0x1b),
//    LOGO_4bit(0x1c),LOGO_4bit(0x1d),LOGO_4bit(0x01),LOGO_4bit(0x1e),0x00,LOGO_4bit(0x1f),LOGO_4bit(0x01),LOGO_4bit(0x20),LOGO_4bit(0x21),LOGO_4bit(0x22),
//    _NEXT_,

    5,_AUTOINC,0x90,0x91,0x8B,  //FONTBYTE2(395),
    56,_NON_AUTOINC,0x92,
    0x10,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,
    0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x10,
    0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x10,
    0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,
    0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x10,0x55,0x55,
    0x55,0x55,0x55,
//    0x10,0x55,_REPEAT_,5,
//    0x55,_REPEAT_,13,
//    0x10,0x55,_REPEAT_,9,
//    0x10,0x55,_REPEAT_,17,
//    0x10,0x55,_REPEAT_,5,
//    _NEXT_,

//////////////////////////////////////////////////
    // row8
    5,_AUTOINC,0x90,0x11,0xC2,  //FONTBYTE0(450),
    58,_NON_AUTOINC,0x92,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,0x8c,
    0x8c,0x8c,0x8c,0x8c,0x8c,
//    0x8c,_REPEAT_,55,   //row 1 and row 2 and row3 and row4
//    _NEXT_,

    5,_AUTOINC,0x90,0x51,0xC2,  //FONTBYTE1(450),
    56,_NON_AUTOINC,0x92,
    0x00,LOGO_1bit(0x5f),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x61),LOGO_1bit(0x62),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x63),
    0x00,LOGO_1bit(0x64),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x65),LOGO_1bit(0x66),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x67),0x00,
    LOGO_1bit(0x64),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x68),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x61),0x00,
    LOGO_1bit(0x64),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x69),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x6a),0x00,LOGO_1bit(0x6b),
    LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x6c),LOGO_1bit(0x62),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x61),0x00,LOGO_1bit(0x64),LOGO_1bit(0x60),
    LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x6d),

//    0x00,LOGO_1bit(0x5f),LOGO_1bit(0x60),_REPEAT_,3,LOGO_1bit(0x61),LOGO_1bit(0x62),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x63),
//    0x00,LOGO_1bit(0x64),LOGO_1bit(0x60),_REPEAT_,2,LOGO_1bit(0x65),LOGO_1bit(0x66),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x67),0x00,
//    LOGO_1bit(0x64),LOGO_1bit(0x60),_REPEAT_,3,LOGO_1bit(0x68),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x61),0x00,
//    LOGO_1bit(0x64),LOGO_1bit(0x60),_REPEAT_,3,LOGO_1bit(0x69),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x6a),0x00,LOGO_1bit(0x6b),
//    LOGO_1bit(0x60),_REPEAT_,2,LOGO_1bit(0x6c),LOGO_1bit(0x62),LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x61),0x00,LOGO_1bit(0x64),LOGO_1bit(0x60),
//    LOGO_1bit(0x60),LOGO_1bit(0x60),LOGO_1bit(0x6d),
//    _NEXT_,

    5,_AUTOINC,0x90,0x91,0xC2,  //FONTBYTE2(450),
    58,_NON_AUTOINC,0x92,
    0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
    0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
    0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
    0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
    0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
    0xF0,0xF0,0xF0,0xF0,0xF0,
//    0xf0,_REPEAT_,55,    //11~20
//    _NEXT_,

    _END,
};
#endif

#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)

//20120801 Abel 1Bit Logo Modify
//Logo視窗大小Row Command
BYTE code tROW_COMMAND_MAP1[] =
{
#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))
    //Logo1440x900視窗大小114字寬x25字高
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 0
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 1
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 2
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 3
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 4
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 5
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 6
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 7
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 8
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 9
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 10
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 11
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 12
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 13
    
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 14   
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 15
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 16
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 17
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 18
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 19
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 20
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 21
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 22
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 23
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 24       
    
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 25
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 26
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 27
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 33

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))
    //Logo1600x900
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 0
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 1
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 2
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 3
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 4
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 5
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 6
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 7
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 8
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 9
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 10
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 11
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 12
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 13
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 14
    
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 15   
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 16
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 17
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 18
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 19
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 20
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 21
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 22
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 23
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 24
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 25       
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 26     
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 27
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 33
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 34
	
#elif((_PANEL_DH_WIDTH == 1280) && (_PANEL_DV_HEIGHT == 1024))
    //Logo1280x1024 區塊非正方形23字高
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 0
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 1
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 2
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 3
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 4
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 5
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 6
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 7
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 8
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 9
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 10
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 11
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 12
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 13
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 14	
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 15
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 16
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 17
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 18
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 19
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 20
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 21
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 22
    
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 24
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 25
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 26
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 27
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32
	
#elif((_PANEL_DH_WIDTH == 1680) && (_PANEL_DV_HEIGHT == 1050))
    //Logo1680x1050 區塊非正方形28字高
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 0
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 1
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 2
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 3
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 4
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 5
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 6
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 7
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 8
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 9
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 10
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 11
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 12
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 13
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 14	
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 15
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 16
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 17
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 18
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 19
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 20
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 21
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 22
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 23
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 24
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 25
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 26
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 27
    
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 33
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 34
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 35
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 36

#elif((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
    //Logo19200x1080 視窗大小非正方形32字高
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 0
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 1
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 2
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 3
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 4
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 5
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 6
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 7
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 8
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 9
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 10
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 11
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 12
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 13
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 14	
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 15
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 16
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 17
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 18
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 19
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 20
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 21
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 22
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 23
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 24
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 25
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 26
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 27
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 28
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 29
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 30
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 31

    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 24
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 25
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 26
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 27
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32

#endif
    
};

#elif(_LOGO_TYPE == _LENOVO)

BYTE code tROW_COMMAND_MAP1[] =
{
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 0
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 1
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 2
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 3
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 4
#if(_EPA_LOGO == _ON)	
    //ROW SPACE
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 5
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 6
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 7
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 8
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 9
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 10
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 11
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 12
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 13
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 14
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 15
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 16
#endif
};

#endif

// 20110915 Lexie, B010 end
void OsdFuncApplyMap(BYTE ucOsdMapType)
{
    BYTE i = 0;

    g_ucOsdMap = ucOsdMapType;

    switch(ucOsdMapType)
    {
        case _OSD_MAP0://MainMenu
            // Row Command
            ScalerOsdBurstWriteDataPort(tOSD_ROW_COMMAND0, sizeof(tOSD_ROW_COMMAND0), GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            // Frame Control (set font start address)
            g_usFontSelectStart = _OSD_MAP0_Height + 1;
            g_usFontTableStart = g_usFontSelectStart + _OSD_MAP0_CharNumber;
            ScalerOsdFrameControlAllByte(0x004, _OSD_WITHOUT_DB, (BYTE)g_usFontSelectStart, ((g_usFontSelectStart >> 4) & 0xf0) | (g_usFontTableStart & 0x0f), g_usFontTableStart >> 4);
            // Character Command initial
            ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE0, 0x8c, _OSD_MAP0_CharNumber);    // 1bit、width 12pixels
            ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE1, 0, _OSD_MAP0_CharNumber);       // char initial
            ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE2, 0x10, _OSD_MAP0_CharNumber);    // color initial
            g_ucOsdHeight = _OSD_MAP0_Height;
            g_ucOsdWidth = _OSD_MAP0_Width;    
//            ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, 0x50);    //Window 7 mask region appear
            break;

        case _OSD_MAP1:// MSG OSD
            // Row Command
            ScalerOsdBurstWriteDataPort(tOSD_ROW_COMMAND1, sizeof(tOSD_ROW_COMMAND1), GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            // Frame Control (set font start address)
            g_usFontSelectStart = _OSD_MAP1_Height + 1;
            g_usFontTableStart = g_usFontSelectStart + _OSD_MAP1_CharNumber;
            ScalerOsdFrameControlAllByte(0x004, _OSD_WITHOUT_DB, (BYTE)g_usFontSelectStart, ((g_usFontSelectStart >> 4) & 0xf0) | (g_usFontTableStart & 0x0f), g_usFontTableStart >> 4);
            g_ucOsdHeight = _OSD_MSG_ROW;
            g_ucOsdWidth = _OSD_MSG_COL;           
            // Character Command initial
            ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE0, 0x8c, _OSD_MAP1_CharNumber);    // 1bit、width 12pixels
            ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE1, 0, _OSD_MAP1_CharNumber);       // char initial
            ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE2, 0x10, _OSD_MAP1_CharNumber);    // color initial
//            ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, 0x10);
            break;

        case _OSD_MAP2:// LOGO OSD
#if((_LOGO_TYPE != _LENOVO_THINKVISION_EPA) && (_LOGO_TYPE != _LENOVO_THINKVISION) && (_LOGO_TYPE != _LENOVO_2015_EPA)&& (_LOGO_TYPE != _LENOVO_2015))
            // Row Command
            ScalerOsdBurstWriteDataPort(tOSD_ROW_COMMAND2, sizeof(tOSD_ROW_COMMAND2), GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            // Frame Control (set font start address)
            g_usFontSelectStart = _OSD_MAP2_Height + 1;
            g_usFontTableStart = g_usFontSelectStart + _OSD_MAP2_CharNumber;
            ScalerOsdFrameControlAllByte(0x004, _OSD_WITHOUT_DB, (BYTE)g_usFontSelectStart, ((g_usFontSelectStart >> 4) & 0xf0) | (g_usFontTableStart & 0x0f), g_usFontTableStart >> 4);
            // Character Command initial
            ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE0, 0x8c, _OSD_MAP2_CharNumber);    // 1bit、width 12pixels
            ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE1, 0, _OSD_MAP2_CharNumber);       // char initial
            ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE2, 0x10, _OSD_MAP2_CharNumber);    // color initial
            ScalerOsdBurstWriteDataPort(LENOVO_LOGO_COMMAND, sizeof(LENOVO_LOGO_COMMAND), GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
//            ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, 0x10);
#endif
            break;

        case _OSD_MAP3:
            break;

        case _OSD_MAP4:
            break;

        case _OSD_MAP5:
            break;

        case _OSD_LOGO_MAP:
#if((_LOGO_TYPE != _LENOVO_THINKVISION_EPA) && (_LOGO_TYPE != _LENOVO_THINKVISION) && (_LOGO_TYPE != _LENOVO_2015_EPA)&& (_LOGO_TYPE != _LENOVO_2015))
           g_ucOsdHeight = sizeof(tROW_COMMAND_MAP1)/3;
           g_ucOsdWidth = tROW_COMMAND_MAP1[2];    
        
           // row command
           for(i=0;i<g_ucOsdHeight;i++)
           {
               ScalerOsdCommandAllByte(i, tROW_COMMAND_MAP1[(i*3)+0], tROW_COMMAND_MAP1[(i*3)+1], tROW_COMMAND_MAP1[(i*3)+2]);
           }
        
           // row command end
           ScalerOsdCommandByte(g_ucOsdHeight, _OSD_BYTE0, _ROW_END);
        
        
           // calc char start address
           g_usFontSelectStart = g_ucOsdHeight + 1;
        
           // calc font start address
           g_usFontTableStart = g_usFontSelectStart;
           
           for(i=0;i<g_ucOsdHeight;i++)
           {
               g_usFontTableStart += tROW_COMMAND_MAP1[(i*3)+2];
           }

           ScalerOsdFrameControlAllByte(0x004, _OSD_WITHOUT_DB, (BYTE)g_usFontSelectStart, ((g_usFontSelectStart >> 4) & 0xf0) | (g_usFontTableStart & 0x0f), g_usFontTableStart >> 4);
#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)
           
           // char command initial(所有都填空白)   
#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))
           // char byte 0 = _AT_NORMAL(0x8c) (1440x900 空白在0x06)         
           ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x06, COLOR(_CP_LOGO_IBM_GRAY_224, _CP_BG), (g_usFontTableStart-g_usFontSelectStart));
#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))
           // char byte 0 = _AT_NORMAL(0x8c) (1440x900 空白在0x06)         
           ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x06, COLOR(_CP_LOGO_IBM_GRAY_224, _CP_BG), (g_usFontTableStart-g_usFontSelectStart));         
#elif((_PANEL_DH_WIDTH == 1280) && (_PANEL_DV_HEIGHT == 1024))
           //1280x1024 空白在0x02
           ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x02, COLOR(_CP_LOGO_IBM_GRAY_224, _CP_BG), (g_usFontTableStart-g_usFontSelectStart)); 
#elif((_PANEL_DH_WIDTH == 1680) && (_PANEL_DV_HEIGHT == 1050))
           //1680x1050 空白在0x02
           ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x02, COLOR(_CP_LOGO_IBM_GRAY_224, _CP_BG), (g_usFontTableStart-g_usFontSelectStart)); 
#elif((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
           //1920x1080 空白在0x03
           ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x03, COLOR(_CP_LOGO_IBM_GRAY_224, _CP_BG), (g_usFontTableStart-g_usFontSelectStart));
#endif

#elif(_LOGO_TYPE == _LENOVO)
			ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x03, COLOR(_CP_LOGO_LENOVO_LOGO_BLUE3, _CP_BG), (g_usFontTableStart-g_usFontSelectStart));
			
#endif
			ScalerOsdBurstWriteDataPort(LENOVO_LOGO_COMMAND, sizeof(LENOVO_LOGO_COMMAND), GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);					   
#endif
            break;

        default:
            break;
    }
}

BYTE code tOSD_ROWCHARNUM_TABLE_MAP0[]=
{
    _OSD_MAP0_Width, //row0
    _OSD_MAP0_Width, //row1
    _OSD_MAP0_Width, //row2

    _OSD_MAP0_Width, //row3
    _OSD_MAP0_Width, //row4
    _OSD_MAP0_Width, //row5

    _OSD_MAP0_Width, //row6
    _OSD_MAP0_Width, //row7
    _OSD_MAP0_Width, //row8

    _OSD_MAP0_Width, //row9
    _OSD_MAP0_Width, //row10
    _OSD_MAP0_Width, //row11

    _OSD_MAP0_Width, //row12
    _OSD_MAP0_Width, //row13
    _OSD_MAP0_Width, //row14

    _OSD_MAP0_Width, //row15

    _OSD_MAP0_Width, //row16
    _OSD_MAP0_Width, //row17
    _OSD_MAP0_Width, //row18
    _OSD_MAP0_Width, //row19

};

BYTE code tOSD_ROWCHARNUM_TABLE_MAP1[]=
{
    _OSD_MSG_COL, //row0
    _OSD_MSG_COL, //row1
    _OSD_MSG_COL, //row2
    _OSD_MSG_COL, //row3
    _OSD_MSG_COL, //row4
    _OSD_MSG_COL, //row5
    _OSD_MSG_COL, //row6
    _OSD_MSG_COL, //row7
};

BYTE code tOSD_ROWCHARNUM_TABLE_MAP2[]=
{
    55, //row0
    55, //row1
    55, //row2
    55, //row3
    55, //row4
    55, //row5
    55, //row6
    55, //row7
    55, //row8
};


code BYTE *tOSD_ROWCHARNUM_TABLE[] =
{
    tOSD_ROWCHARNUM_TABLE_MAP0,
    tOSD_ROWCHARNUM_TABLE_MAP1,
    tOSD_ROWCHARNUM_TABLE_MAP2,
};

WORD OsdFuncCalcStartAddress(BYTE ucRow, BYTE ucCol)
{
    WORD xdata usStartAddr = 0;
    BYTE xdata ucTemp = 0;

    usStartAddr = tOSD_OSDMAP_INF[g_ucOsdMap][0] + 1;

#if 1   //alex.huang 20140828

    if(g_ucOsdMap == _OSD_MAP0)
    {
        usStartAddr += _OSD_MAP0_Width * ucRow;
    }
    else if(g_ucOsdMap == _OSD_MAP1)
    {
        usStartAddr += _OSD_MSG_COL * ucRow;
    }
    else if(g_ucOsdMap == _OSD_MAP2)
    {
        usStartAddr += 55 * ucRow;
    }
#else
    for(ucTemp = 0; ucTemp < ucRow; ucTemp++)
    {
        usStartAddr += tOSD_ROWCHARNUM_TABLE[g_ucOsdMap][ucTemp];
    }
#endif
    usStartAddr += ucCol;

    return usStartAddr;
}

void OsdFunc1bitColor(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucForegroundColor, BYTE ucBackgroundColor)
{
    BYTE xdata ucCntY = 0;
    BYTE xdata ucTemp = 0;

    ucTemp = ((ucForegroundColor & 0x0f) << 4) | (ucBackgroundColor & 0x0f);

    for(ucCntY = 0; ucCntY < ucSizeH; ucCntY++)
    {
        ScalerOsdCharCommandByteSeries(OsdFuncCalcStartAddress((ucRow + ucCntY),ucCol), _OSD_BYTE2, ucTemp, ucSizeW);
    }
}

void OsdFuncBlank(BYTE ucRow,BYTE ucCol, BYTE ucPiexl,BYTE ucHeight,BYTE ucColor)
{
    BYTE xdata ucCntY = 0;

    for(ucCntY = 0;ucCntY < ucHeight;ucCntY++)
    {
        ScalerOsdCommandAllByte(OsdFuncCalcStartAddress((ucRow + ucCntY),ucCol), 0x10,ucPiexl,ucColor);
    }
}

void OsdFunc1bitByte0(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucByte0)
{
    BYTE xdata ucCntY = 0;

    for(ucCntY = 0; ucCntY < ucSizeH; ucCntY++)
    {
        ScalerOsdCharCommandByteSeries(OsdFuncCalcStartAddress((ucRow + ucCntY),ucCol), _OSD_BYTE0, ucByte0, ucSizeW);
    }
}

void OsdFunc1bitChar(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucChar)
{
    BYTE xdata ucCntY = 0;

    for(ucCntY = 0; ucCntY < ucSizeH; ucCntY++)
    {
        ScalerOsdCharCommandByteSeries(OsdFuncCalcStartAddress((ucRow + ucCntY),ucCol), _OSD_BYTE1, ucChar, ucSizeW);
    }
}

void OsdFunc1bitItemApplyChar(BYTE ucRow, BYTE ucCol, BYTE ucSizeW, BYTE ucSizeH, BYTE ucChar)
{
    BYTE xdata ucCntX = 0;
    BYTE xdata ucCntY = 0;

    for(ucCntY = 0; ucCntY < ucSizeH; ucCntY++)
    {
        for(ucCntX = 0; ucCntX < ucSizeW; ucCntX++)
        {
            ScalerOsdCharCommandByteSeries(OsdFuncCalcStartAddress((ucRow + ucCntY),(ucCol + ucCntX)), _OSD_BYTE1, ucChar, 1);
            if(ucChar != 0)
            {
                ucChar++;
            }
        }
    }
}

#endif

#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
