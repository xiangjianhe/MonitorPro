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
// ID Code      : RTDOSDTable.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDTABLE__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LENOVO_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _RGB_MENU_BG                0,0,0           //menu background color
#define _RGB_ITEM_UNSEL_BG          114,114,114     //item unselect background color
#define _RGB_ITEM_SEL_BG            112,160,192     //item select background color
#define _RGB_FOCUS_FRAME            192,240,240     //item frame color
#define _RGB_HIGHLIGHT_BG           64,144,224      //item window highlight background color

#define _RGB_BLACK                  0x00,0x00,0x00
#define _RGB_WHITE                  0xff,0xff,0xff
#define _RGB_YELLOW                 0xff,0x9c,0x00

#if 0
#define _RGB_GRAY_1                 0x20,0x20,0x20  //menu selected background grey
#define _RGB_GRAY_2                 0x5e,0x5e,0x5e  //bottom font"ok left right exit",lock "color" icon for 2bit
#define _RGB_GRAY_5                 0xc0,0xc0,0xc0  //color icon when unselected
#define _RGB_YELLOW                 0xff,0x9c,0x00  //Icon Selected
#define _RGB_YELLOW_1               0x73,0x4c,0x0e  //enter next menu,icon unselected
#define _RGB_YELLOW_2               0xd1,0x87,0x0f  //color icon when selected
#define _RGB_YELLOW_3               0xa8,0x87,0x58  //color icon when enter 3rd menu
#define _RGB_TITLE_GRAY             0xbf,0xbf,0xbf  //top title gray
#endif

#define _RGB_Unused                 0x00,0xff,0x00  //Unused


#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)
#define _RGB_LOGO_IBM_NONE              0xff,0xff,0x00
#define _RGB_LOGO_IBM_BLACK             0x00,0x00,0x00
#define _RGB_LOGO_IBM_WHITE             0xff,0xff,0xff
#define _RGB_LOGO_IBM_GRAY_79           0x4f,0x4f,0x4f
#define _RGB_LOGO_IBM_GRAY_224          0xe0,0xe0,0xe0
#define _RGB_LOGO_IBM_RED_255           0xff,0x00,0x00
#define _RGB_LOGO_IBM_EPA_BLUE          0x06,0xaf,0xec
#elif(_LOGO_TYPE == _LENOVO)
#define _RGB_LOGO_LENOVO_NONE           0xff,0xff,0x00
#define _RGB_LOGO_LENOVO_BLACK          0x00,0x00,0x00
#define _RGB_LOGO_LENOVO_WHITE          0xff,0xff,0xff
#define _RGB_LOGO_LENOVO_EPA_BLUE       0x06,0xaf,0xec
#define _RGB_LOGO_LENOVO_BLUE1          0x1B,0x7F,0xAA
#define _RGB_LOGO_LENOVO_BLUE2          0x7B,0xB2,0xC0
#define _RGB_LOGO_LENOVO_BLUE3          0x2A,0x5F,0xAA
#endif

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************

BYTE code tPALETTE_0[] =
{
    _RGB_Unused,
    _RGB_ITEM_UNSEL_BG,
    _RGB_ITEM_SEL_BG,
    _RGB_FOCUS_FRAME,
    _RGB_HIGHLIGHT_BG,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,

    _RGB_MENU_BG,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_BLACK,
    _RGB_WHITE,
    _RGB_YELLOW,
};

BYTE code tPALETTE_1[] =
{
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,

    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
};

BYTE code tPALETTE_2[] =
{
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,

    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
};

BYTE code tPALETTE_3[] =
{
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,

    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
    _RGB_Unused,
};

BYTE code tPALETTE_LOGO[] =
{
#if 1   //alex.huang 20140909

#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)

    _RGB_LOGO_IBM_BLACK,
    _RGB_LOGO_IBM_NONE,
    _RGB_LOGO_IBM_NONE,
    _RGB_LOGO_IBM_GRAY_224,
    _RGB_LOGO_IBM_GRAY_79,
    _RGB_LOGO_IBM_RED_255,
    _RGB_LOGO_IBM_NONE,
    _RGB_LOGO_IBM_NONE,
    
    _RGB_LOGO_IBM_NONE,
    _RGB_LOGO_IBM_NONE,
    _RGB_LOGO_IBM_EPA_BLUE,
    _RGB_LOGO_IBM_WHITE,	
    _RGB_LOGO_IBM_NONE,
    _RGB_LOGO_IBM_NONE,
    _RGB_LOGO_IBM_NONE,
    _RGB_LOGO_IBM_NONE,
    
#elif(_LOGO_TYPE == _LENOVO)

    _RGB_LOGO_LENOVO_BLACK,
    _RGB_LOGO_LENOVO_BLUE2,
    _RGB_LOGO_LENOVO_BLUE1,
    _RGB_LOGO_LENOVO_BLUE3,
    _RGB_LOGO_LENOVO_NONE,
    _RGB_LOGO_LENOVO_NONE,
    _RGB_LOGO_LENOVO_NONE,
    _RGB_LOGO_LENOVO_NONE,
    
    _RGB_LOGO_LENOVO_NONE,
    _RGB_LOGO_LENOVO_NONE,
    _RGB_LOGO_LENOVO_EPA_BLUE,
    _RGB_LOGO_LENOVO_WHITE,	
    _RGB_LOGO_LENOVO_NONE,
    _RGB_LOGO_LENOVO_NONE,
    _RGB_LOGO_LENOVO_NONE,
    _RGB_LOGO_LENOVO_NONE,

#elif(_LOGO_TYPE == _LENOVO_THINKVISION_EPA)

#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))

	0x00,0x00,0x00,
	0x80,0x00,0x00,
	0x00,0x80,0x00,
	0x80,0x80,0x00,
	0x00,0x00,0x80,
	0x80,0x00,0x80,
	0x00,0x80,0x80,
	0x80,0x80,0x80,
	0xc0,0xc0,0xc0,
	0xff,0x00,0x00,
	0x00,0xff,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0xff,
	0xff,0x00,0xff,
	0x06,0xaf,0xec,
	0xff,0xff,0xff,

#elif((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))

	0x00,0x00,0x00,
	0x80,0x00,0x00,
	0x00,0x80,0x00,
	0x80,0x80,0x00,
	0x00,0x00,0x80,
	0x80,0x00,0x80,
	0x00,0x80,0x80,
	0x80,0x80,0x80,
	0xc0,0xc0,0xc0,
	0xff,0x00,0x00,
	0x00,0xff,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0xff,
	0xff,0x00,0xff,
	0x06,0xaf,0xec,
	0xff,0xff,0xff,
	
#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))
	0x00,0x00,0x00,
	0x80,0x00,0x00,
	0x00,0x80,0x00,
	0x80,0x80,0x00,
	0x00,0x00,0x80,
	0x80,0x00,0x80,
	0x00,0x80,0x80,
	0x80,0x80,0x80,
	0xc0,0xc0,0xc0,
	0xff,0x00,0x00,
	0x00,0xff,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0xff,
	0xff,0x00,0xff,
	0x06,0xaf,0xec,
	0xff,0xff,0xff,

#elif((_PANEL_DH_WIDTH == 1280) && (_PANEL_DV_HEIGHT == 1024))

	0x00,0x00,0x00,
	0x80,0x00,0x00,
	0x00,0x80,0x00,
	0x80,0x80,0x00,
	0x00,0x00,0x80,
	0x80,0x00,0x80,
	0x00,0x80,0x80,
	0x80,0x80,0x80,
	0xc0,0xc0,0xc0,
	0xff,0x00,0x00,
	0x00,0xff,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0xff,
	0xff,0x00,0xff,
	0x06,0xaf,0xec,
	0xff,0xff,0xff,

#endif

#elif(_LOGO_TYPE == _LENOVO_THINKVISION)

#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))

	0x00,0x00,0x00,
	0x80,0x00,0x00,
	0x00,0x80,0x00,
	0x80,0x80,0x00,
	0x00,0x00,0x80,
	0x80,0x00,0x80,
	0x00,0x80,0x80,
	0x80,0x80,0x80,
	0xc0,0xc0,0xc0,
	0xff,0x00,0x00,
	0x00,0xff,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0xff,
	0xff,0x00,0xff,
	0x00,0xff,0xff,
	0xff,0xff,0xff,

#endif

#elif(_LOGO_TYPE == _LENOVO_2015)
#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))

	0x00,0x00,0x00,
	0x80,0x00,0x00,
	0x00,0x80,0x00,
	0x80,0x80,0x00,
	0x00,0x00,0x80,
	0x80,0x00,0x80,
	0x00,0x80,0x80,
	0x80,0x80,0x80,
	0xc0,0xc0,0xc0,
	0xff,0x00,0x00,
	0x00,0xff,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0xff,
	0xff,0x00,0xff,
	0x00,0xff,0xff,
	0xff,0xff,0xff,

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))

	0x00,0x00,0x00,
	0x80,0x00,0x00,
	0x00,0x80,0x00,
	0x80,0x80,0x00,
	0x00,0x00,0x80,
	0x80,0x00,0x80,
	0x00,0x80,0x80,
	0x80,0x80,0x80,
	0xc0,0xc0,0xc0,
	0xff,0x00,0x00,
	0x00,0xff,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0xff,
	0xff,0x00,0xff,
	0x00,0xff,0xff,
	0xff,0xff,0xff,

#endif

#elif(_LOGO_TYPE == _LENOVO_2015_EPA)
#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))

	0x00,0x00,0x00,
	0x80,0x00,0x00,
	0x00,0x80,0x00,
	0x80,0x80,0x00,
	0x00,0x00,0x80,
	0x80,0x00,0x80,
	0x00,0x80,0x80,
	0x80,0x80,0x80,
	0xc0,0xc0,0xc0,
	0xff,0x00,0x00,
	0x00,0xff,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0xff,
	0xff,0x00,0xff,
	0x06,0xaf,0xec,
	0xff,0xff,0xff,

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))

	0x00,0x00,0x00,
	0x80,0x00,0x00,
	0x00,0x80,0x00,
	0x80,0x80,0x00,
	0x00,0x00,0x80,
	0x80,0x00,0x80,
	0x00,0x80,0x80,
	0x80,0x80,0x80,
	0xc0,0xc0,0xc0,
	0xff,0x00,0x00,
	0x00,0xff,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0xff,
	0xff,0x00,0xff,
	0x06,0xaf,0xec,
	0xff,0xff,0xff,

#endif

#endif

#else
//--------------------
//Color Palette for logo 
//--------------------
// 20110915 Lexie, B010 modify poweron LOGO

    0x00,0x00,0x00, //0
    0xff,0xff,0xff, //1     
    0x20,0x20,0x20, //2 ,20
    0x1e,0x1e,0x1e, //0x89,0x8b,0x8d, //3 ,137 139 141
    0xc8,0xc8,0xc8, //4 ,200 200 200    
    0x1c,0x1c,0x1c, //5 ,40 40 40
    0x32,0x32,0x32, //6 ,66 66 66
    0x1a,0x1a,0x1a, //7 ,10 10 10

    0x17,0x17,0x17, //8 ,17 17 17
    0x15,0x15,0x15, //9 ,30 30 30
    0x12,0x12,0x12, //a ,33 33 33
    0x10,0x10,0x10, //b ,37 37 37
    0x0b,0x0b,0x0b, //d ,9 11 10
    0x0b,0x0b,0x0b, //d ,9 11 10
    0x09,0x09,0x09, //e ,45 45 45
    0x06,0x06,0x06, //f ,47 47 47
#endif
};

BYTE code tPALETTE_INPUT[] =
{
    0x40,0x90,0xe0,
    0xff,0xff,0xff,
    0x00,0x80,0x00,
    0x80,0x80,0x00,
    0x00,0x00,0x80,
    0x80,0x00,0x80,
    0x00,0x80,0x80,
    0x80,0x80,0x80,

    0xc0,0xc0,0xc0,
    0xff,0x00,0x00,
    0x00,0xff,0x00,
    0xff,0xff,0x00,
    0x00,0x00,0xff,
    0xff,0x00,0xff,
    0x40,0x90,0xe0,       //0x00,0xff,0xff,
    0xff,0xff,0xff,
};

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
BYTE code tPALETTE_LOW_BLUE_LIGHT[] =
{
    0x40,0x90,0xe0,
    0x80,0x00,0x00,
    0x00,0x80,0x00,
    0x80,0x80,0x00,
    0x00,0x00,0x80,
    0x80,0x00,0x80,
    0x00,0x80,0x80,
    0x80,0x80,0x80,
    0xc0,0xc0,0xc0,
    0xff,0x00,0x00,
    0x00,0xff,0x00,
    0xff,0xff,0x00,
    0x00,0x00,0xff,
    0xff,0x00,0xff,
    0x00,0xff,0xff,
    0xff,0xff,0xff,
};
#endif

BYTE code twOSD_WIN0[] =
{
    _WIN0,
    _WIN0_BORDER_PIXEL,
    _WIN0_BORDER_COLOR,
    _WIN0_FUNC_CONTROL,
    _WIN0_GRADIENT_CONTROL0,
    _WIN0_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN1[] =
{
    _WIN1,
    _WIN1_BORDER_PIXEL,
    _WIN1_BORDER_COLOR,
    _WIN1_FUNC_CONTROL,
    _WIN1_GRADIENT_CONTROL0,
    _WIN1_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN2[] =
{
    _WIN2,
    _WIN2_BORDER_PIXEL,
    _WIN2_BORDER_COLOR,
    _WIN2_FUNC_CONTROL,
    _WIN2_GRADIENT_CONTROL0,
    _WIN2_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN3[] =
{
    _WIN3,
    _WIN3_BORDER_PIXEL,
    _WIN3_BORDER_COLOR,
    _WIN3_FUNC_CONTROL,
    _WIN3_GRADIENT_CONTROL0,
    _WIN3_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN4[] =
{
    _WIN4,
    _WIN4_BORDER_PIXEL,
    _WIN4_BORDER_COLOR,
    _WIN4_FUNC_CONTROL,
    _WIN4_GRADIENT_CONTROL0,
    _WIN4_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN41[] =
{
    _WIN41,
    _WIN41_BORDER_PIXEL,
    _WIN41_BORDER_COLOR,
    _WIN41_FUNC_CONTROL,
    _WIN41_GRADIENT_CONTROL0,
    _WIN41_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN5[] =
{
    _WIN5,
    _WIN5_BORDER_PIXEL,
    _WIN5_BORDER_COLOR,
    _WIN5_FUNC_CONTROL,
    _WIN5_GRADIENT_CONTROL0,
    _WIN5_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN6[] =
{
    _WIN6,
    _WIN6_BORDER_PIXEL,
    _WIN6_BORDER_COLOR,
    _WIN6_FUNC_CONTROL,
    _WIN6_GRADIENT_CONTROL0,
    _WIN6_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN7[] =
{
    _WIN7,
    _WIN7_BORDER_PIXEL,
    _WIN7_BORDER_COLOR,
    _WIN7_FUNC_CONTROL,
    _WIN7_GRADIENT_CONTROL0,
    _WIN7_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN8[] =
{
    _WIN8,
    _WIN8_BORDER_PIXEL,
    _WIN8_BORDER_COLOR,
    _WIN8_FUNC_CONTROL,
    _WIN8_GRADIENT_CONTROL0,
    _WIN8_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN9[] =
{
    _WIN9,
    _WIN9_BORDER_PIXEL,
    _WIN9_BORDER_COLOR,
    _WIN9_FUNC_CONTROL,
    _WIN9_GRADIENT_CONTROL0,
    _WIN9_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN0_TRANS[] =
{
    _WIN0_TRANS,
    _WIN0_TRANS_BORDER_PIXEL,
    _WIN0_TRANS_BORDER_COLOR,
    _WIN0_TRANS_FUNC_CONTROL,
    _WIN0_TRANS_GRADIENT_CONTROL0,
    _WIN0_TRANS_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN1_TRANS[] =
{
    _WIN1_TRANS,
    _WIN1_TRANS_BORDER_PIXEL,
    _WIN1_TRANS_BORDER_COLOR,
    _WIN1_TRANS_FUNC_CONTROL,
    _WIN1_TRANS_GRADIENT_CONTROL0,
    _WIN1_TRANS_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN2_TRANS[] =
{
    _WIN2_TRANS,
    _WIN2_TRANS_BORDER_PIXEL,
    _WIN2_TRANS_BORDER_COLOR,
    _WIN2_TRANS_FUNC_CONTROL,
    _WIN2_TRANS_GRADIENT_CONTROL0,
    _WIN2_TRANS_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN3_TRANS[] =
{
    _WIN3_TRANS,
    _WIN3_TRANS_BORDER_PIXEL,
    _WIN3_TRANS_BORDER_COLOR,
    _WIN3_TRANS_FUNC_CONTROL,
    _WIN3_TRANS_GRADIENT_CONTROL0,
    _WIN3_TRANS_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN4_TRANS[] =
{
    _WIN4_TRANS,
    _WIN4_TRANS_BORDER_PIXEL,
    _WIN4_TRANS_BORDER_COLOR,
    _WIN4_TRANS_FUNC_CONTROL,
    _WIN4_TRANS_GRADIENT_CONTROL0,
    _WIN4_TRANS_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN5_TRANS[] =
{
    _WIN5_TRANS,
    _WIN5_TRANS_BORDER_PIXEL,
    _WIN5_TRANS_BORDER_COLOR,
    _WIN5_TRANS_FUNC_CONTROL,
    _WIN5_TRANS_GRADIENT_CONTROL0,
    _WIN5_TRANS_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN6_TRANS[] =
{
    _WIN6_TRANS,
    _WIN6_TRANS_BORDER_PIXEL,
    _WIN6_TRANS_BORDER_COLOR,
    _WIN6_TRANS_FUNC_CONTROL,
    _WIN6_TRANS_GRADIENT_CONTROL0,
    _WIN6_TRANS_GRADIENT_CONTROL1,
};

BYTE code twOSD_WIN7_TRANS[] =
{
    _WIN7_TRANS,
    _WIN7_TRANS_BORDER_PIXEL,
    _WIN7_TRANS_BORDER_COLOR,
    _WIN7_TRANS_FUNC_CONTROL,
    _WIN7_TRANS_GRADIENT_CONTROL0,
    _WIN7_TRANS_GRADIENT_CONTROL1,
};

#if 1
//--------------------------------------------------
// Text Width Table Used by COsdFxLoadText()
//--------------------------------------------------
BYTE code tOSD_CHARWIDTH_TABLE_GLOBLE[][2] =
{
    {0x00, (8<<4) | 4},
/*
    {_0_, (8<<4) | 9},
    {_1_, (8<<4) | 8},
    {_2_, (8<<4) | 9},
    {_3_, (8<<4) | 9},
    {_4_, (8<<4) | 9},
    {_5_, (8<<4) | 9},
    {_6_, (8<<4) | 9},
    {_7_, (8<<4) | 9},
    {_8_, (8<<4) | 9},
    {_9_, (8<<4) | 9},
*/
    {GLOBAL(0x0E), (8<<4) | 6},// " / "
    {GLOBAL(0x0F), (8<<4) | 6},// " ' "
    {GLOBAL(0x1A), (8<<4) | 6},// " - "
    {GLOBAL(0x1B), (8<<4) | 6},// "  "
    {GLOBAL(0x1C), (8<<4) | 6},// " , "
    {GLOBAL(0x1D), (8<<4) | 6},// " ( "
    {GLOBAL(0x1E), (8<<4) | 6},// " ) "
    {GLOBAL(0x1F), (8<<4) | 6},// " , "
    {GLOBAL(0x20), (8<<4) | 6},// " . "
    {GLOBAL(0x35), (8<<4) | 6},// " : "


    {_END_, _END_},
};

BYTE code tOSD_CHARWIDTH_TABLE_WEST[][2] =
{
    {_END_, _END_},
};

BYTE code tOSD_CHARWIDTH_TABLE_CHS[][2] =
{
    {_END_, _END_},
};

BYTE code tOSD_CHARWIDTH_TABLE_JAP[][2] =
{
    {_END_, _END_},
};

BYTE code tOSD_CHARWIDTH_TABLE_RUS[][2] =
{
    {RUS(0x00), (8<<4) | 12},
    {RUS(0x01), (8<<4) | 10},
    {RUS(0x02), (8<<4) | 11},
    {RUS(0x03), (8<<4) | 11},
    {RUS(0x04), (8<<4) | 10},
    {RUS(0x05), (8<<4) | 10},
    {RUS(0x06), (8<<4) | 11},
    {RUS(0x07), (8<<4) | 10},
    {RUS(0x08), (8<<4) | 9},
    {RUS(0x09), (8<<4) | 10},
    {RUS(0x0a), (8<<4) | 9},
    {RUS(0x0b), (8<<4) | 10},
    {RUS(0x0c), (8<<4) | 9},
    {RUS(0x0d), (8<<4) | 12},
    {RUS(0x0e), (8<<4) | 10},
    {RUS(0x0f), (8<<4) | 11},
    {RUS(0x10), (8<<4) | 9},
    {RUS(0x11), (8<<4) | 4},
    {RUS(0x12), (8<<4) | 9},
    {RUS(0x13), (8<<4) | 9},
    {RUS(0x14), (8<<4) | 10},
    {RUS(0x15), (8<<4) | 10},
    {RUS(0x16), (8<<4) | 10},
    {RUS(0x17), (8<<4) | 10},
    {RUS(0x18), (8<<4) | 8},
    {RUS(0x19), (8<<4) | 8},
    {RUS(0x1a), (8<<4) | 8},
    {RUS(0x1b), (8<<4) | 8},
    {RUS(0x1c), (8<<4) | 9},
    {RUS(0x1d), (8<<4) | 8},
    {RUS(0x1e), (8<<4) | 9},
    {RUS(0x1f), (8<<4) | 7},
    {RUS(0x20), (8<<4) | 7},
    {RUS(0x21), (8<<4) | 8},
    {RUS(0x22), (8<<4) | 8},
    {RUS(0x23), (8<<4) | 7},
    {RUS(0x24), (8<<4) | 7},
    {RUS(0x25), (8<<4) | 7},
    {RUS(0x26), (8<<4) | 8},
    {RUS(0x27), (8<<4) | 11},
    {RUS(0x28), (8<<4) | 9},
    {RUS(0x29), (8<<4) | 8},
    {RUS(0x2a), (8<<4) | 8},
    {RUS(0x2b), (8<<4) | 8},
    {RUS(0x2c), (8<<4) | 9},
    {RUS(0x2d), (8<<4) | 9},
    {RUS(0x2e), (8<<4) | 7},
    {RUS(0x2f), (8<<4) | 7},
    {RUS(0x30), (8<<4) | 7},
    {RUS(0x31), (8<<4) | 11},
    {RUS(0x32), (8<<4) | 10},
    {RUS(0x33), (8<<4) | 8},
    {RUS(0x34), (8<<4) | 7},
    {RUS(0x35), (8<<4) | 10},
    {RUS(0x36), (8<<4) | 4},
    {RUS(0x37), (8<<4) | 10},
    {RUS(0x38), (8<<4) | 11},

    {RUS_T(0x00), (8<<4) | 12},
    {RUS_T(0x01), (8<<4) | 10},
    {RUS_T(0x02), (8<<4) | 12},
    {RUS_T(0x03), (8<<4) | 12},
    {RUS_T(0x04), (8<<4) | 12},
    {RUS_T(0x05), (8<<4) | 12},
    {RUS_T(0x06), (8<<4) | 12},
    {RUS_T(0x07), (8<<4) | 12},
    {RUS_T(0x08), (8<<4) | 12},
    {RUS_T(0x09), (8<<4) | 12},
    {RUS_T(0x0a), (8<<4) | 12},
    {RUS_T(0x0b), (8<<4) | 12},
    {RUS_T(0x0c), (8<<4) | 11},
    {RUS_T(0x0d), (8<<4) | 4},
    {RUS_T(0x0e), (8<<4) | 12},
    {RUS_T(0x0f), (8<<4) | 12},
    {RUS_T(0x10), (8<<4) | 12},
    {RUS_T(0x11), (8<<4) | 12},
    {RUS_T(0x12), (8<<4) | 12},
    {RUS_T(0x13), (8<<4) | 12},
    {RUS_T(0x14), (8<<4) | 12},
    {RUS_T(0x15), (8<<4) | 4},
    {RUS_T(0x16), (8<<4) | 12},
    {RUS_T(0x17), (8<<4) | 11},
    {RUS_T(0x18), (8<<4) | 12},
    {RUS_T(0x19), (8<<4) | 11},
    {RUS_T(0x1a), (8<<4) | 12},
    {RUS_T(0x1b), (8<<4) | 11},
    {RUS_T(0x1c), (8<<4) | 12},
    {RUS_T(0x1d), (8<<4) | 10},
    {RUS_T(0x1e), (8<<4) | 10},
    {RUS_T(0x1f), (8<<4) | 12},
    {RUS_T(0x20), (8<<4) | 11},
    {RUS_T(0x21), (8<<4) | 10},
    {RUS_T(0x22), (8<<4) | 11},
    {RUS_T(0x23), (8<<4) | 11},
    {RUS_T(0x24), (8<<4) | 10},
    {RUS_T(0x25), (8<<4) | 11},
    {RUS_T(0x26), (8<<4) | 11},
    {RUS_T(0x27), (8<<4) | 11},
    {RUS_T(0x28), (8<<4) | 11},
    {RUS_T(0x29), (8<<4) | 10},
    {RUS_T(0x2a), (8<<4) | 9},
    {RUS_T(0x2b), (8<<4) | 9},
    {RUS_T(0x2c), (8<<4) | 11},
    {RUS_T(0x2d), (8<<4) | 11},
    {RUS_T(0x2e), (8<<4) | 11},
    {RUS_T(0x2f), (8<<4) | 10},
    {RUS_T(0x30), (8<<4) | 10},
    {RUS_T(0x31), (8<<4) | 12},
    {RUS_T(0x32), (8<<4) | 11},
    {RUS_T(0x33), (8<<4) | 11},
    {RUS_T(0x34), (8<<4) | 11},
    {RUS_T(0x35), (8<<4) | 10},
    {RUS_T(0x36), (8<<4) | 11},
    {RUS_T(0x37), (8<<4) | 4},
    {RUS_T(0x38), (8<<4) | 4},
    {RUS_T(0x39), (8<<4) | 10},
    {RUS_T(0x3A), (8<<4) | 10},
    {RUS_T(0x3B), (8<<4) | 7},
    {RUS_T(0x3C), (8<<4) | 10},
    {RUS_T(0x3D), (8<<4) | 7},
    {RUS_T(0x3E), (8<<4) | 10},
    {RUS_T(0x3F), (8<<4) | 10},
    {RUS_T(0x40), (8<<4) | 12},
    
    {_END_, _END_},
};

BYTE code tOSD_BUTTON_EXIT_ICON[]=
{
    _ButtonIconExit_0, _ButtonIconExit_1, _ButtonIconExit_2, _NEXT_,
    _ButtonIconExit_3, _ButtonIconExit_4, _ButtonIconExit_5, _END_,
};

BYTE code tOSD_BUTTON_LEFT_ICON[]=
{
    _ButtonIconLeft_0, _ButtonIconLeft_1, _ButtonIconLeft_2, _NEXT_,
    _ButtonIconLeft_3, _ButtonIconLeft_4, _ButtonIconLeft_5, _END_,
};

BYTE code tOSD_BUTTON_RIGHT_ICON[]=
{
    _ButtonIconRight_0, _ButtonIconRight_1, _ButtonIconRight_2, _NEXT_,
    _ButtonIconRight_3, _ButtonIconRight_4, _ButtonIconRight_5, _END_,
};

BYTE code tOSD_BUTTON_OK_ICON[]=
{
    _ButtonIconOk_0, _ButtonIconOk_1, _ButtonIconOk_2, _NEXT_,
    _ButtonIconOk_3, _ButtonIconOk_4, _ButtonIconOk_5, _END_,
};

BYTE code tOSD_BUTTON_POWER_ICON[]=
{
    _ButtonIconPower_0, _ButtonIconPower_1, _ButtonIconPower_2, _NEXT_,
    _ButtonIconPower_3, _ButtonIconPower_4, _ButtonIconPower_5, _END_,
};

//--------------------------------------------------
// Message Table
//--------------------------------------------------
//20140912 Abel Modify
BYTE code tOSD_POWER_SAVING_STR[]=
{
    _P_, _o_, _w1_, _w2_, _e_, _r_, __6, _S_, _a_, _v_, _i_, _n_, _g_, __6, _M_, _o_, _d_, _e_, _END_,//_ENGLISH     
    _M_, _o_, _d_, _e_, __6, _SP_p_e_, _c_, _o_, _n_, _o_, _m_, _i_, _e_ ,__6, _d_, _SP_up_dot_, _SP_p_e_, _n_, _e_, _r_, _g_, _i_, _e_,_END_,    //_FRENCH              
    _M_, _o_, _d_, _o_, __6, _r_, _i_, _s_, _p_, _a_,_r_, _m_, _i_, _o_, __6, _e_, _n_, _e_, _r_, _g_, _i_, _a_,_END_,                   //_ITALIAN         
    _CHT_29, _CHT_0D, _CHT_2A, _CHT_2B,_CHT_2C, _END_,        //_CHINESE_S     
    _M_, _o_, _d_, _o_, __6, _a_, _h_, _o_, _r_, _r_, _o_, __6, _d_, _e_, __6, _e_, _n_, _e_, _r_, _g_, _SP_p_i_, _a_, _END_,//_SPANISH(Esp)    
    _JAP_079, _JAP_07A, _JAP_07B, _JAP_07C, _JAP_07D, _JAP_07E, _JAP_029, _JAP_02A, _JAP_02B, _END_,            //_JAPAN           
    _S_, _t_, _a_, _n_, _d_, _a_, _r_, _d_, _e_, _i_, _n_, _s_, _t_,_DOT/*//ym20141125 .  _e_, _l_, _l_, _u_, _n_, _g_*/,_END_,                            //_GERMAN(Deu)
    _RUS_62, _RUS_53, _o_, _RUS_56, _o_, _RUS_55, _RUS_58, _RUS_65, _RUS_56, _RUS_52, _RUS_57, __6, _p_, _e_, _RUS_60, _RUS_61, _RUS_58, _RUS_55, __6, _RUS_5E, _RUS_58, _RUS_54, _a_, _RUS_56, _RUS_58, _RUS_59, _END_,   //_RUSSIAN  
};

BYTE code tOSD_NO_CONNECTION_STR[]= 
{
    _N_, _o_, __6, _C_, _o_, _n_, _n_, _e_, _c_, _t_, _i_, _o_, _n_, _END_,//_ENGLISH     
    _C_, _SP_A_a_, _b_, _l_, _e_, __6, _d_, _e_, __6, _s_, _i_, _g_, _n_, _a_, _l_, __6, _n_, _o_, _n_, __6, _c_, _o_, _n_, _n_, _e_, _c_, _t_, _SP_p_e_, _END_,  //_FRENCH              
    _N_, _e_, _s_, _s_, _u_, _n_, __6, _c_, _o_, _l_, _l_,_e_, _g_,_a_, _m_, _e_, _n_, _t_, _o_, _END_,   //_ITALIAN         
    _CHT_29, _CHT_0D, _CHT_2D, _CHT_2A, _CHT_2E, _CHT_2F, _END_,                 //_CHINESE_S     
    _N_, _o_, __6, _h_, _a_, _y_, __6, _c_, _o_, _n_, _e_,_x_, _i_, _SP_p_o_, _n_ ,_END_,                             //_SPANISH(Esp)    
    _JAP_08E, _JAP_08F, _JAP_090, _JAP_091, _JAP_084, _JAP_085, _JAP_086, _JAP_092, _JAP_093, _JAP_062, _JAP_063, _JAP_094, _JAP_095, _JAP_096, _JAP_097, _PERIOD, _END_,   //_JAPAN           
    _K_, _e_, _i_, _n_, _e_, __6, _V_, _e_,_r_, _b_, _i_, _n_, _d_, _u_, _n_, _g_, __6, _LINE, _END_,                    //_GERMAN(Deu)
    _RUS_5D, _o_, _RUS_5B, _RUS_53, _RUS_5A, _RUS_5C, _RUS_65, _e_, _RUS_56, _RUS_58, _e_, __6, _o_, _RUS_54, _c_, _y_, _RUS_54, _c_, _RUS_54, _RUS_50, _y_, _e_, _RUS_54, _DOT, _END_,   //_RUSSIAN  
};

BYTE code tOSD_CHECK_CABLE_STR[] = 
{
    _C_, _h_, _e_, _c_, _k_, __6, _S_, _i_, _g_, _n_, _a_, _l_, __6, _C_, _a_, _b_, _l_, _e_, _END_,//_ENGLISH     
    _END_, //_FRENCH          
    _V_, _e_, _r_, _i_, _f_, _i_, _c_, _a_, _r_, _e_,__6, _i_, _l_, __6, _c_, _a_, _v_, _o_, __6, _d_, _i_, __6, _s_, _e_, _g_, _n_, _a_, _l_, _e_, _END_,//_ITALIAN         
    _CHT_30, _CHT_31, _CHT_29, _CHT_0D, _CHT_2D, _END_,                 //_CHINESE_S     
    _R_, _e_, _v_, _i_, _s_, _e_, __6, _e_, _l_, __6, _c_, _a_, _b_, _l_,  _e_, __6, _d_, _e_, __6, _s_, _e_, _SP_s_n_, _a_, _l_, _END_, //_SPANISH(Esp)    
    _JAP_098, _JAP_099, _JAP_09A, _JAP_09B, _JAP_09C, _JAP_02A, _JAP_09D,_JAP_09E, _JAP_02D, _JAP_02E, _JAP_0C7,_JAP_0A0, _JAP_0A1, _JAP_06C, _JAP_033, _JAP_087, _JAP_092, _JAP_093, _JAP_0BE, _JAP_0A2, _JAP_084, _JAP_062, _PERIOD, _END_,  //_JAPAN  
    _S_, _i_, _g_, _n_, _a_, _l_, _k_, _a_, _b_, _e_, _l_, __6, _SP_dd_u_, _b_, _e_, _r_, _p_, _r_, _SP_dd_u_, _f_, _e_, _n_, _END_,        //_GERMAN(Deu)
    _RUS_5D, _p_, _o_, _RUS_50, _e_, _p_, _RUS_51, _RUS_54, _e_, __6, _c_, _RUS_58, _RUS_68, _RUS_56, _a_, _RUS_5A, _RUS_51, _RUS_56, _RUS_52, _RUS_57, __6, _RUS_53, _a_, _RUS_66, _e_, _RUS_5A, _RUS_51, _END_,   //_RUSSIAN 
};

BYTE code tOSD_INPUT_NOT_SUPPORT_STR_0[]=
{
    _I_, _n_, _p_, _u_, _t_, __6, _S_, _i_, _g_, _n_, _a_, _l_, __6, _O_, _u_, _t_, __6, _o_, _f_, __6, _R_, _a_, _n_, _g_, _e_, _END_,//_ENGLISH     
    _S_, _i_, _g_, _n_, _a_, _l_, __6, _d_, _SP_up_dot_, _e_, _n_, _t_, _r_, _SP_p_e_, _e_, __6, _h_, _o_, _r_, _s_, __6, _d_, _e_, _s_, __6, _v_, _a_, _l_, _e_, _u_, _r_, _s_, __6,  _a_, _u_, _t_, _o_, _r_, _i_, _s_, _SP_p_e_, _e_, _s_, _END_, //_FRENCH          
    _S_, _e_, _g_, _n_, _a_, _l_, _e_, __6, _d_, _i_, __6, _i_, _n_, _p_, _u_, _t_, __6, _f_, _u_, _o_, _r_, _i_, __6, _s_, _c_, _a_, _l_, _a_, _END_,  //_ITALIAN         
    _CHT_2B, _CHT_2C, _CHT_29, _CHT_0D, _CHT_32, _CHT_33, _CHT_34, _CHT_35, _END_,                 //_CHINESE_S     
    _S_, _e_, _SP_s_n_, _a_, _l_, __6, _d_, _e_, __6, _e_, _n_, _t_, _r_, _a_, _d_, _a_, __6, _f_, _u_, _e_, _r_, _a_, __6, _d_, _e_, __6, _r_, _a_, _n_, _g_, _o_, _END_,   //_PANISH(Esp)    
    _JAP_0A4, _JAP_0A5, _JAP_07D, _JAP_07E, _JAP_098, _JAP_099, _JAP_09A, _JAP_09B, _JAP_0A6, _JAP_0A7, _JAP_0A8, _JAP_0A9, _JAP_0AA, _JAP_0AB, _END_,   //_JAPAN           
    _E_, _i_, _n_, _g_, _a_, _n_, _g_, _s_, _s_, _i_, _g_, _n_, _a_, _l_, __6, _a_, _u_, _SP_beta_, _e_, _r_, _h_, _a_, _l_, _b_, __6, _d_, _e_, _s_, __6, _g_, _SP_dd_u_, _l_, _t_, _i_, _g_, _e_, _n_, __6, _B_, _e_, _r_, _e_, _i_, _c_, _h_, _s_,_END_,//_GERMAN(Deu)
    _B_, _x_, _o_, _RUS_5B, _RUS_56, _o_, _RUS_57, __6, _c_, _RUS_58, _RUS_68, _RUS_56, _a_, _RUS_5A, __6, _RUS_50, _RUS_56, _e_, __6, _RUS_5B, _o_, _RUS_5E, _y_, _c_, _RUS_54, _RUS_58, _RUS_55, _o_, _RUS_68, _o_, __6, _RUS_5B, _RUS_58, _a_, _RUS_5E, _a_, _RUS_63, _o_, _RUS_56, _a_, _END_, //_RUSSIAN 
};

#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
#define _RESOLUTION         _1_, _9_, _2_, _0_, _x_, _1_, _0_, _8_, _0_

#elif((_PANEL_DH_WIDTH == 1680) && (_PANEL_DV_HEIGHT == 1050))
#define _RESOLUTION         _1_, _6_, _8_, _0_, _x_, _1_, _0_, _5_, _0_

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))
#define _RESOLUTION         _1_, _6_, _0_, _0_, _x_, _9_, _0_, _0_

#elif((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))
#define _RESOLUTION         _1_, _4_, _4_, _0_, _x_, _9_, _0_, _0_

#elif((_PANEL_DH_WIDTH == 1280) && (_PANEL_DV_HEIGHT == 1024))
#define _RESOLUTION         _1_, _2_, _8_, _0_, _x_, _1_, _0_, _2_, _4_

#elif((_PANEL_DH_WIDTH == 1366) && (_PANEL_DV_HEIGHT == 768))
#define _RESOLUTION         _1_, _3_, _6_, _6_, _x_, _7_, _6_, _8_

#else                                                         
    #warning "tOSD_INPUT_NOT_SUPPORT_STR_1"
#endif   

BYTE code tOSD_INPUT_NOT_SUPPORT_STR_1[]=
{
    _P_, _l_, _e_, _a_, _s_, _e_, __6, _c_, _h_, _a_, _n_, _g_, _e_, __6, _t_, _o_, __6, _RESOLUTION, _AT_SIGN1, _AT_SIGN2, _6_, _0_, _H_, _z_, _END_, //_ENGLISH  
    _V_, _e_, _u_, _i_, _l_, _l_, _e_, _z_, __6, _m_, _o_, _d_, _i_, _f_, _i_, _e_, _r_, __6, _e_, _n_, __6, _RESOLUTION, __6, _AT_SIGN1, _AT_SIGN2, __6, _6_, _0_, _H_, _z_, _END_,            //_FRENCH                                                                                                                                                                                      
    _R_, _e_, _g_, _o_, _l_, _a_, _r_, _e_, __6, _a_, __6, _RESOLUTION, __6, _AT_SIGN1, _AT_SIGN2, __6, _6_, _0_, _H_, _z_, _END_, //_ITALIAN                                                                                                                                                                                            
    _CHT_0E, _CHT_0F,_CHT_3D, __6, _RESOLUTION, _AT_SIGN1, _AT_SIGN2, _6_, _0_, _H_, _z_, _END_,//_CHINESE_S   
    _P_, _o_, _r_, __6, _f_, _a_, _v_, _o_, _r_, _COMMA, __6, _c_, _a_, _m_, _b_, _i_, _e_, __6, _a_, __6, _RESOLUTION, __6, _AT_SIGN1, _AT_SIGN2, __6, _6_, _0_, _H_, _z_, _END_,                 //_PANISH(Esp)                                                                                                                                                                                    
    _JAP_04A, _JAP_04B,_JAP_04C, _JAP_04D, _JAP_084, _JAP_085, _JAP_086, _JAP_0C3, __6, _RESOLUTION, _AT_SIGN1, _AT_SIGN2, _6_, _0_, _H_, _z_, _END_,//_JAPAN     
    _B_, _i_, _t_, _t_, _e_, __6, _SP_dd_a_, _n_, _d_, _e_, _r_, _n_, __6, _S_, _i_, _e_, __6, _a_, _u_, _f_, __6, _RESOLUTION, __6, _AT_SIGN1, _AT_SIGN2, __6, _6_, _0_, _H_, _z_, _END_,//_GERMAN(Deu)      
    _RUS_69, _RUS_63, _RUS_55, _e_, _RUS_56, _RUS_58, _RUS_54, _e_, __6, _RUS_56, _a_, __6, _RESOLUTION, __6, _AT_SIGN1, _AT_SIGN2, __6, _6_, _0_, _H_, _z_, _END_,//_RUSSIAN     
};

BYTE code tOSD_OSD_LOCKED_STR[] =
{
    _M_, _e_, _n_, _u_, __6, _i_, _s_, __6, _L_, _o_, _c_, _k_, _e_, _d_, _END_,//_ENGLISH     
    _L_, _e_, __6, _m_, _e_,_n_, _u_, __6, _e_, _s_, _t_, __6, _v_, _e_, _r_, _r_, _o_, _u_, _i_, _l_, _l_, _SP_p_e_,_END_,              //_FRENCH              
    _M_, _e_, _n_, _u_, __6, _b_, _l_, _o_, _c_, _c_, _a_, _t_, _o_, _END_,         //_ITALIAN         
    _CHT_36, _CHT_37, _CHT_38, _CHT_39, _END_,   //_CHINESE_S       
    _E_, _l_, __6, _m_, _e_, _n_, _SP_p_u_, __6, _e_, _s_, _t_, _SP_p_a_, __6, _b_, _l_, _o_, _q_, _u_, _e_, _a_, _d_, _o_, _END_,          //_SPANISH(Esp)    
    _JAP_07F, _JAP_080,_JAP_081,_JAP_02A,_JAP_082, _JAP_083,_JAP_034,_JAP_06C, _JAP_033, _JAP_084, _JAP_085, _JAP_086,_JAP_063, _JAP_087, _JAP_088, _JAP_089, _PERIOD, _END_,                     //_JAPAN   
    _M_, _e_, _n_, _SP_dd_u_, __6,  _i_, _s_, _t_, __6, _g_, _e_, _s_, _p_, _e_, _r_, _r_, _t_, _END_,                        //_GERMAN(Deu)
    _M_, _e_, _RUS_56, _RUS_5C, __6, _RUS_63, _a_, _RUS_66, _RUS_5A, _o_, _RUS_53, _RUS_58, _p_, _o_, _RUS_50, _a_, _RUS_56, _o_, _END_, //_RUSSIAN            
};

BYTE code tOSD_OSD_UNLOCKED_STR[] =
{
    _M_, _e_, _n_, _u_, __6, _i_, _s_, __6, _U_, _n_, _l_, _o_, _c_, _k_, _e_, _d_, _END_,//_ENGLISH     
    _L_, _e_, __6, _m_, _e_,_n_, _u_, __6, _e_, _s_, _t_, __6, _d_, _SP_p_e_, _v_, _e_, _r_, _r_, _o_, _u_, _i_, _l_, _l_, _SP_p_e_,_END_,   //_FRENCH 
    _M_, _e_, _n_, _u_, __6, _s_, _b_, _l_, _o_, _c_, _c_, _a_, _t_, _o_, _END_,             //_ITALIAN                                                
    _CHT_36, _CHT_37, _CHT_3A, _CHT_39, _END_,   //_CHINESE_S                                                                                                                                   
    _E_, _l_, __6, _m_, _e_, _n_, _SP_p_u_, __6, _e_, _s_, _t_, _SP_p_a_, __6, _d_, _e_, _s_, _b_, _l_, _o_, _q_, _u_, _e_, _a_, _d_, _o_, _END_,   //_SPANISH(Esp) 
    _JAP_07F, _JAP_080,_JAP_081,_JAP_02A,_JAP_082, _JAP_083,_JAP_034,_JAP_06C, _JAP_033, _JAP_08A, _JAP_08B, _JAP_08C, _JAP_08D, _JAP_084, _JAP_085, _JAP_086,_JAP_063, _JAP_087, _JAP_088, _JAP_089, _PERIOD, _END_,  //_JAPAN          
    _M_, _e_, _n_, _SP_dd_u_, __6,  _i_, _s_, _t_, __6, _f_, _r_, _e_, _i_, _g_, _e_, _g_, _e_, _b_, _e_, _n_, _END_,     //_GERMAN(Deu) 
    _M_, _e_, _RUS_56, _RUS_5C, __6, _p_, _a_, _RUS_63, _RUS_66, _RUS_5A, _o_, _RUS_53, _RUS_58, _p_, _o_, _RUS_50, _a_, _RUS_56, _o_, _END_, //_RUSSIAN            
};


BYTE code tOSD_AUTO_POWER_DOWN_STR[] =
{
    _T_, _h_, _e_, __6, _m_, _o_, _n_, _i_, _t_, _o_, _r_, __6, _i_, _s_, __6, _t_, _u_, _r_, _n_, _i_,_n_, _g_, __6, _o_, _f_, _f_, _END_,//_ENGLISH     
    _L_, _e_, __6, _m_, _o_, _n_, _i_, _t_, _e_, _u_, _r_, __6, _s_, _SP_up_dot_,_SP_p_e_, _t_, _e_, _i_, _n_, _t_,_END_,   //_FRENCH 
    _S_, _p_, _e_, _g_, _n_, _i_, _m_, _e_, _n_, _t_, _o_, __6, _d_, _e_, _l_, __6, _m_, _o_, _n_, _i_, _t_, _o_, _r_, __6, _i_, _n_, __6, _c_, _o_, _r_, _s_, _o_, _END_,             //_ITALIAN                                                
    _CHT_46, _CHT_47, _CHT_3B, _CHT_48, _CHT_49, _CHT_4A, _CHT_4B, _END_,   //_CHINESE_S                                                                                                                                   
    _E_, _l_, __6, _m_, _o_, _n_, _i_, _t_, _o_, _r_, __6, _e_, _s_, _t_, _SP_p_a_, __6, _a_, _p_, _a_, _g_, _a_, _d_, _o_, _END_,   //_SPANISH(Esp) 
    _JAP_029, _JAP_080,_JAP_0C6, _JAP_02A, _JAP_0C7,_JAP_071, _JAP_0C8, _JAP_0C9, _JAP_087, _JAP_092, _JAP_093, _JAP_062, _JAP_063, _JAP_064, _END_,  //_JAPAN          
    _D_, _e_, _r_, __6, _M_, _o_, _n_, _i_, _t_, _o_, _r_, __6, _s_, _c_, _h_, _a_, _l_, _t_, _e_, _t_, __6, _s_, _i_, _c_, _h_, __6, _a_, _u_, _s_, _END_,     //_GERMAN(Deu) 
    _M_, _o_, _RUS_56, _RUS_58, _RUS_54, _o_, _p_, __6,  _o_, _RUS_54, _RUS_53, _RUS_5A, _RUS_5C, _RUS_65, _a_, _e_, _RUS_54, _c_, _RUS_59, _END_, //_RUSSIAN            
};

    
BYTE code tOSD_DDCCI_ENABLE_STR[] =
{
	_D_, _D_, _C_, _SLASH,_C_, _I_, __6, _E_, _n_, _a_, _b_, _l_, _e_, _END_,        //_ENGLISH     
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _A_, _l_, _l_, _u_, _m_, _SP_p_e_, _END_,  //_FRENCH    
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _A_, _c_, _c_, _e_, _s_, _o_, _END_,       //_ITALIAN         
    _D_, _D_, _CHT_25, _SLASH, _CHT_25, _I_,_CHT_3C, _END_,                          //_CHINESE_S                         //_CHINESE_S       
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _E_, _n_, _c_, _e_,_n_, _d_, _i_, _d_, _o_, _END_,  //_SPANISH(Esp)    
    _D_, _D_, _JAP_048,_SLASH,_JAP_048,_I_,_JAP_0AE, _JAP_0AF,_JAP_0B0,_JAP_0B1, _END_,      //_JAPAN           
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _E_, _i_, _n_, _END_,                               //_GERMAN(Deu)
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _RUS_5E, _o_, _RUS_5B, _RUS_53, _RUS_5A, _RUS_5C, _RUS_65, _e_, _RUS_56, _END_,       //_RUSSIAN           
};

BYTE code tOSD_DDCCI_DISABLE_STR[] =
{
	_D_, _D_, _C_, _SLASH,_C_, _I_, __6, _D_, _i_, _s_, _a_, _b_, _l_, _e_, _END_,    //_ENGLISH     
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _E_, _t_, _e_, _i_, _n_, _t_, _END_,        //_FRENCH                                   
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _S_, _p_, _e_, _n_, _t_, _o_, _END_,        //_ITALIAN                                  
    _D_, _D_, _CHT_25, _SLASH, _CHT_25, _I_,_CHT_3B, _END_,                           //_CHINESE_S                                                                                                                  
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _D_, _e_, _s_, _a_,_c_, _t_, _i_, _v_, _a_, _d_,_o_, _END_,  //_SPANISH(Esp)
    _D_, _D_, _JAP_048,_SLASH,_JAP_048,_I_, _JAP_0AC, _JAP_0AD ,_JAP_0AE, _JAP_0AF,_JAP_0B0,_JAP_0B1, _END_,       //_JAPAN  
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _A_, _u_, _s_, _END_,                       //_GERMAN(Deu)                                                
    _D_, _D_, _C_, _SLASH, _C_, _I_, __6, _o_, _RUS_54, _RUS_53, _RUS_5A, _RUS_5C, _RUS_65, _e_, _RUS_56, _END_,//_RUSSIAN                   
};

BYTE code tOSD_AUTOMATIC[]= 
{
    _I_, _m_, _a_, _g_, _e_, __6, _S_, _e_, _t_, _u_, _p_, _COLON,__6, _A_, _u_, _t_, _o_, _m_, _a_, _t_, _i_, _c_, _END_,//_ENGLISH     
    _C_, _o_, _n_, _f_,_i_, _g_, _u_, _r_,_a_, _t_, _i_, _o_,_n_, __6, _d_, _e_, __6, _I_, _SP_up_dot_, _i_, _m_, _a_, _g_,_e_, _COLON, __6, _A_, _u_, _t_, _o_, _m_, _a_, _t_, _i_, _q_, _u_, _e_, _END_,  //_FRENCH                                                                               
    _I_, _m_, _p_, _o_, _s_, _t_, _a_, _z_, _i_, _o_,_n_, _e_, __6, _i_, _m_, _m_,_a_, _g_, _i_, _n_, _e_, _COLON, __6, _A_, _u_, _t_, _o_, _m_, _a_, _t_, _i_, _c_, _o_, _END_,            //_ITALIAN                                                                              
    _CHT_17, _CHT_18, _CHT_3E, _CHT_3F, _COMMA, __6, _CHT_40, _CHT_41, _CHT_3E, _CHT_3F, _END_,                                     //_CHINESE_                                                                                
    _C_, _o_, _n_, _f_, _i_,_g_, _u_, _r_, _a_, _c_,_i_, _SP_p_o_, _n_, __6, _d_, _e_, __6, _l_, _a_, __6, _i_, _m_, _a_, _g_, _e_, _n_, _COLON, __6, _A_, _u_, _t_, _o_, _m_, _SP_p_a_, _t_, _i_, _c_, _a_, _END_,     //_PANISH(Esp)                  
    _JAP_036, _JAP_037, _JAP_04E, _JAP_04F, _JAP_03E, _JAP_03F, _JAP_05C, _JAP_05D, _JAP_05E, _JAP_04A, _JAP_04B , _JAP_04C, _JAP_04D, _JAP_05F, _JAP_060, _JAP_061, _JAP_062, _JAP_063, _JAP_064, _JAP_065,_END_,//_JAPAN                                                                                             
    _B_, _i_, _l_, _d_, _a_, _u_, _f_, _b_, _a_, _u_, _COLON, __6, _A_, _u_, _t_, _o_, _m_, _a_, _t_,_i_, _s_, _c_, _h_, _END_, //_GERMAN(Deu)                                                                          
    _H_, _a_, _c_, _RUS_54, _p_, _o_, _RUS_57, _RUS_53, _a_, __6, _RUS_58, _RUS_63, _o_, _RUS_66, _p_, _a_, _RUS_60, _RUS_61, _e_, _RUS_56, _RUS_58, _RUS_59, _COLON, __6, _A_, _RUS_50, _RUS_54, _o_, _RUS_55, _a_, _RUS_54, _RUS_58, _RUS_65, _e_, _c_, _RUS_53, _a_, _RUS_59, _END_,             //_RUSSIAN  
};

BYTE code tOSD_PLEASE_WAIT[]=
{
    _O_, _p_, _t_, _i_, _m_, _i_, _z_, _i_, _n_, _g_, __6, _i_, _m_, _a_, _g_, _e_, _COMMA,_p_, _l_, _e_, _a_, _s_, _e_, __6, _w1_, _w2_, _a_, _i_, _t_, _DOT, _DOT, _DOT, _END_,//_ENGLISH     
    _O_, _p_, _t_, _i_, _m_, _i_, _s_, _a_,_t_, _i_, _o_, _n_, __6, _d_, _e_, __6, _I_, _SP_up_dot_, _i_, _m_, _a_, _g_, _e_, __6, _e_, _n_, __6, _c_, _o_, _u_, _r_, _s_, _COMMA, __6, _v_, _e_, _u_, _i_, _l_, _l_, _e_, _z_, __6, _p_, _a_, _t_, _i_, _e_, _n_, _t_, _e_, _r_, _DOT, _DOT, _DOT, _END_,  //_FRENCH                        
    _O_, _t_, _t_, _i_, _m_, _i_, _z_, _z_, _a_, _z_,_i_, _o_, _n_, _e_, __6, _i_, _n_, __6, _c_, _o_, _r_,_s_, _o_, _DOT, __6, _A_, _t_, _t_, _e_, _n_, _d_, _e_, _r_, _e_, _DOT, _DOT, _DOT, _END_,   //_ITALIAN                        
    _CHT_10, _CHT_11, _CHT_1F, _CHT_20,_CHT_42, _COMMA, __6, _CHT_43, _CHT_44, _CHT_45, _DOT, _DOT, _DOT, _END_,                        //_CHINESE_      
    _O_, _p_, _t_, _i_, _m_, _i_, _z_, _a_, _n_, _d_,_o_, __6, _i_, _m_, _a_, _g_, _e_, _n_, _COMMA,__6, _p_, _o_, _r_, __6, _f_, _a_, _v_, _o_, _r_, __6, _e_, _s_, _p_, _e_, _r_, _e_, _DOT, _DOT, _DOT, _END_,         //_PANISH(Esp)        
    _JAP_036, _JAP_037, _JAP_038, _JAP_039, _JAP_03E, _JAP_03F, _JAP_0B2, _JAP_0B3, _JAP_0B4, _JAP_0B5, _JAP_0B6 , _JAP_0B7, _JAP_05F, _JAP_060, _JAP_061, _JAP_0BA, _JAP_092, _JAP_093, _JAP_062, _JAP_063, _JAP_064, _JAP_065, _COMMA_DUM, _JAP_087, _JAP_0BB, _JAP_0BC, _JAP_0BD, _JAP_0BE, _JAP_0BF, _JAP_0B8, _JAP_0B9, _JAP_0C0, _JAP_0BE, _JAP_0A2, _JAP_0A3, _JAP_084, _JAP_062, _DOT, _DOT, _DOT, _END_,   //_JAPAN                  
    _D_, _a_, _s_, __6, _B_, _i_, _l_, _d_, __6, _w1_, _w2_, _i_, _r_, _d_, __6,  _o_, _p_, _t_, _i_, _m_, _i_, _e_, _r_, _t_, _COMMA, __6, _b_, _i_, _t_, _t_, _e_, __6, _w1_, _w2_, _a_, _r_, _t_, _e_, _n_, __6, _S_,_i_, _e_, _DOT, _DOT, _DOT, _END_,   //_GERMAN(Deu)
    _o_, _RUS_5E, _RUS_54, _RUS_58, _RUS_55, _RUS_58, _RUS_63, _a_, _RUS_65, _RUS_58, _RUS_59, __6, _RUS_58, _RUS_63, _o_, _RUS_66, _p_, _a_, _RUS_60, _RUS_61, _e_, _RUS_56, _RUS_58, _RUS_59, _COMMA, __6, _RUS_5E, _o_, _RUS_5B, _o_, _RUS_60, _RUS_61, _RUS_5B, _RUS_58, _RUS_54, _e_, _DOT, _DOT, _DOT, _END_,  //_RUSSIAN    
};


BYTE code tOSD_sMODE[] =
{
    _M_, _o_, _d_, _e_, _END_,                                  //_ENGLISH 
    _M_, _o_, _d_, _e_, _END_,                                  //_FRENCH
    _M_, _o_, _d_, _o_, _END_,                                  //_ITALIAN
    _CHT_06, _CHT_07, _END_,                                    //_CHINESE_S                                                                                                                   
    _M_, _o_, _d_, _o_, _END_,                                  //_SPANISH(Esp)                                                                                                                        
    _JAP_029, _JAP_02A, _JAP_02B, _END_,                        //_JAPAN                                                                                                                               
    _M_, _o_, _d_, _u_, _s_ ,_END_,                             //_GERMAN(Deu)                                                                                                                               
    _P_, _e_, _RUS_60, _RUS_61, _RUS_58, _RUS_55, _END_,//_RUSSIAN             
};

BYTE code tOSD_sMODE_NAME[] =
{
    _M_, _o_, _d_, _e_, _l_, __6, _n_, _a_, _m_, _e_, _END_,                         //_ENGLISH
    _N_, _o_, _m_, __6, _d_, _u_, __6, _m_, _o_, _d_, _SP_n_e_, _l_, _e_, _END_,     //_FRENCH
    _N_, _o_, _m_, _e_, __6, _m_, _o_, _d_, _e_, _l_, _l_, _o_, _END_,               //_ITALIAN
    _CHT_08, _CHT_09, _CHT_0A, _END_,                                                //_CHINESE_S                                                                                                                                    
    _N_, _o_, _m_, _b_, _r_, _e_, __6,_d_, _e_, _l_, __6,_m_, _o_, _d_, _e_, _l_, _o_, _END_,   //_SPANISH(Esp)                                              
    _JAP_029, _JAP_0C4, _JAP_0C5, _JAP_02D, _JAP_02E, _JAP_02F, _JAP_030, _END_,     //_JAPAN                                                                                                                                        
    _M_, _o_, _d_, _e_, _l_, _l_, _n_, _a_, _m_, _e_, _END_,                                    //_GERMAN(Deu)                                                                           
    _H_, _a_, _RUS_63, _RUS_50, _a_, _RUS_56, _RUS_58, _e_, __6, _RUS_55, _o_, _RUS_5B, _e_, _RUS_5A, _RUS_58, _END_,    //_RUSSIAN                                
};

BYTE code tOSD_scMODE_NAME[] =
{
    _MODEL_NAME, _END_,
};

#if 0//((_PROJECT == _PRJ_L_T2254G_A_SEC_LTM220MT12) || (_PROJECT == _CVT_RL6230_PROJECT))   //µÍÐ¹Éä
BYTE code tOSD_sMODE_NAME_LOW_RADIATION[] =
{
	__6,__6,__6,__6,__6,_END_,
	__6,__6,__6,__6,__6,_END_,
	__6,__6,__6,__6,__6,_END_,
	_PARENT_OPEN,_CHT_4C, _CHT_4D, _CHT_4E,_PARENT_CLOSE, _END_,				//_CHINESE_S																												   
	__6,__6,__6,__6,__6,_END_,
	__6,__6,__6,__6,__6,_END_,
	__6,__6,__6,__6,__6,_END_,
	__6,__6,__6,__6,__6,_END_,
};
#endif

BYTE code tOSD_sMICROCODE[] =
{
    _M_, _i_, _c_, _r_, _o_, _c_, _o_, _d_, _e_, _END_,                         //_ENGLISH    
    _M_, _i_, _c_, _r_, _o_, _c_, _o_, _d_, _e_, _END_,                         //_FRENCH
    _M_, _i_, _c_, _r_, _o_, _c_, _o_, _d_, _i_, _c_, _e_, _END_,               //_ITALIAN
    _CHT_0B, _CHT_0C, _CHT_0D, _END_,                                           //_CHINESE_S                                                                                                                                       
    _M_, _i_, _c_, _r_, _o_, _c_, _SP_p_o_, _d_, _i_, _g_, _o_, _END_,          //_SPANISH(Esp)                                                                             
    _JAP_031, _JAP_032, _JAP_033, _JAP_034, _JAP_035, _JAP_02A, _JAP_02B, _END_,//_JAPAN                                                                                                                                        
    _M_,_i_,_k_,_r_,_o_,_c_,_o_,_d_,_e_,_END_,                                  //_GERMAN(Deu)                                                                             
    _M_, _RUS_58, _RUS_53, _p_, _o_, _RUS_53, _o_, _RUS_5B, _END_,    //_RUSSIAN                  
};

BYTE code tOSD_scMICROCODE[] =
{
    _MICROCODE, _END_,   
};

BYTE code tOSD_sEXIT[] = 
{ 
    _E_, _x_, _i_, _t_, _END_,                          //_ENGLISH
    _S_, _o_, _r_, _t_, _i_, _e_ ,_END_,                //_FRENCH    
    _E_, _s_, _c_, _i_, _END_,                          //_ITALIAN
    _CHT_02, _CHT_03, _END_,                            //_CHINESE_S     
    _S_,_a_,_l_,_i_,_r_,_END_,                          //_SPANISH(Esp)
    _JAP_022, _JAP_023, _JAP_024, _END_,                //_JAPAN        
    _V_,_e_,_r_,_l_,_a_,_s_,_s_,_e_,_n_,_END_,          //_GERMAN(Deu)
    _B_, _RUS_52, _x_, _o_, _RUS_5B, _END_,             //_RUSSIAN        
};

BYTE code tOSD_sCANCEL[] =
{                                                                
    _C_, _a_, _n_, _c_, _e_, _l_, _END_,                    //_ENGLISH 
    _A_, _n_, _n_, _u_, _l_, _e_, _r_,_END_,                //_FRENCH,   
    _A_, _n_, _n_, _u_, _l_, _l_, _a_,_END_,                //_ITALIAN,
    _CHT_04, _CHT_05, _END_,                                //_CHINESE_S 
    _C_, _a_, _n_, _c_, _e_, _l_, _a_, _r_, _END_,          //_SPANISH(Esp)
    _JAP_025, _JAP_026, _JAP_027, _JAP_028, _END_,          //_JAPAN,
    _A_, _b_, _b_, _r_, _DOT, _END_,     //_GERMAN(Deu)
    _O_, _RUS_54, _RUS_55, _e_, _RUS_56, _a_, _END_,        //_RUSSIAN    
};

BYTE code tOSD_sOK[] =
{                                               
    _O_, _K_, _END_,                                //_ENGLISH       
    _O_, _K_, _END_,                                //_FRENCH            
    _O_, _K_, _END_,                                //_ITALIAN       
    _CHT_00, _CHT_01, _END_,                        //_CHINESE_S     
    _A_, _c_, _e_, _p_, _t_, _a_, _r_, _END_,       //_SPANISH(Esp)
    _JAP_020, _JAP_021, _END_,                      //_JAPAN         
    _O_, _K_, _END_,                                //_GERMAN(Deu)   
    _O_, _K_, _END_,                                //_RUSSIAN       
};

#if(_USER_DCR_FUNCTION == _ON)
BYTE code tOSD_sDESCRIPTION_BRI_CON_DCR[] =
{
    _A_, _d_, _j_, _u_, _s_, _t_, _s_, __6, _o_, _v_, _e_, _r_, _a_, _l_, _l_, __6, _s_, _c_, _r_, _e_, _e_, _n_, __6, _B_, _r_, _i_, _g_, _h_, _t_, _n_, _e_, _s_, _s_, _SLASH, _C_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _SLASH, _D_, _C_, _R_, _END_,        
    _A_, _j_, _u_, _s_, _t_, _e_, _r_, __6, _l_, _e_, _s_, __6, _v_, _a_, _l_, _e_, _u_, _r_, _s_, __6, _g_, _SP_p_e_, _n_, _SP_p_e_, _r_, _a_, _l_, _e_, _s_, __6, _d_, _e_, __6, _l_, _u_, _m_, _i_, _n_, _o_, _s_, _i_, _t_, _SP_p_e_, _SLASH, _c_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _e_, _SLASH, _D_, _C_, _R_, _END_,                           //_FRENCH    
    _R_, _e_, _g_, _o_, _l_, _a_, _r_, _e_, __6, _l_, _u_, _m_, _i_, _n_, _o_, _s_, _i_, _t_, _SP_n_a_, _SLASH, _c_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _o_, _SLASH, _D_, _C_, _R_, __6, _t_, _o_, _t_, _a_, _l_, _i_, __6, _d_, _e_, _l_, _l_, _o_, __6, _s_, _c_, _h_, _e_, _r_, _m_, _o_, _END_,                           //_ITALIAN
    _CHT_0E, _CHT_0F, _CHT_10, _CHT_11,_CHT_0F, _CHT_12, _CHT_13, _CHT_14, _SLASH, _CHT_15, _CHT_16, _CHT_14, _SLASH, _D_, _CHT_25,_CHT_26, _END_,                 //_CHINESE_S     
    _A_, _j_, _u_, _s_, _t_, _a_, _r_, __6, _e_, _l_, __6, _b_, _r_, _i_, _l_, _l_, _o_, _COMMA, __6, _e_, _l_, __6, _c_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _e_, __6, _y_, __6, _D_, _C_, _R_, __6, _d_, _e_, __6, _l_, _a_, __6, _p_, _a_, _n_, _t_, _a_, _l_, _l_, _a_,_END_,                                      //_SPANISH(Esp)
    _JAP_036, _JAP_037,_JAP_038, _JAP_039, _JAP_03A, _JAP_03B, _JAP_03C, _JAP_03D, _JAP_03E, _JAP_03F, _JAP_040, _JAP_041, _JAP_042, _JAP_043, _SLASH, _JAP_035, _JAP_044,_JAP_045, _JAP_046, _JAP_047, _JAP_045, _SLASH, _D_, _JAP_048, _JAP_049, _JAP_03E, _JAP_03F, _JAP_04A, _JAP_04B, _JAP_04C, _JAP_04D, _END_,  //_JAPAN        
    _G_, _e_, _s_, _a_, _m_, _t_, _b_, _i_, _l_, _d_, _s_, _c_, _h_, _i_, _r_, _m_, __6, _a_, _n_, _p_, _a_, _s_, _s_, _e_, _n_, __6, _H_, _e_, _l_, _l_, _i_, _g_, _k_, _e_, _i_, _t_, _SLASH, _K_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _SLASH, _D_, _C_, _R_, _END_,       //_GERMAN(Deu)
    _O_, _RUS_54, _p_, _e_, _r_, _y_, _RUS_5A, _RUS_58, _p_, _y_, _RUS_57, _RUS_54, _e_, __6, _o_, _RUS_66, _RUS_5F, _y_, _RUS_5C, __6, _RUS_59, _p_, _RUS_53, _o_, _c_, _RUS_54, _RUS_51, _SLASH, _RUS_53, _o_, _RUS_56, _RUS_54, _p_, _a_, _c_, _RUS_54, _RUS_56, _o_, _c_, _RUS_54, _RUS_51, _SLASH, _D_, _C_, _R_, _END_,  //_RUSSIAN        
    
};
#else
BYTE code tOSD_sDESCRIPTION_BRI_CON_DCR[] =
{
    _A_, _d_, _j_, _u_, _s_, _t_, _s_, __6, _o_, _v_, _e_, _r_, _a_, _l_, _l_, __6, _s_, _c_, _r_, _e_, _e_, _n_, __6, _B_, _r_, _i_, _g_, _h_, _t_, _n_, _e_, _s_, _s_, _SLASH, _C_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _END_,        
    _A_, _j_, _u_, _s_, _t_, _e_, _r_, __6, _l_, _e_, _s_, __6, _v_, _a_, _l_, _e_, _u_, _r_, _s_, __6, _g_, _SP_p_e_, _n_, _SP_p_e_, _r_, _a_, _l_, _e_, _s_, __6, _d_, _e_, __6, _l_, _u_, _m_, _i_, _n_, _o_, _s_, _i_, _t_, _SP_p_e_, _SLASH, _c_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _e_, _END_,                           //_FRENCH    
    _R_, _e_, _g_, _o_, _l_, _a_, _r_, _e_, __6, _l_, _u_, _m_, _i_, _n_, _o_, _s_, _i_, _t_, _SP_n_a_, _SLASH, _c_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _o_,_END_,                           //_ITALIAN
    _CHT_0E, _CHT_0F, _CHT_10, _CHT_11,_CHT_0F, _CHT_12, _CHT_13, _CHT_14, _SLASH, _CHT_15, _CHT_16, _CHT_14,_END_,                 //_CHINESE_S     
    _A_, _j_, _u_, _s_, _t_, _a_, _r_, __6, _e_, _l_, __6, _b_, _r_, _i_, _l_, _l_, _o_, _COMMA, __6, _e_, _l_, __6, _c_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _e_, __6, _y_,_END_,                                      //_SPANISH(Esp)
    _JAP_036, _JAP_037,_JAP_038, _JAP_039, _JAP_03A, _JAP_03B, _JAP_03C, _JAP_03D, _JAP_03E, _JAP_03F, _JAP_040, _JAP_041, _JAP_042, _JAP_043, _SLASH, _JAP_035, _JAP_044,_JAP_045, _JAP_046, _JAP_047, _JAP_045, _END_,  //_JAPAN        
    _G_, _e_, _s_, _a_, _m_, _t_, _b_, _i_, _l_, _d_, _s_, _c_, _h_, _i_, _r_, _m_, __6, _a_, _n_, _p_, _a_, _s_, _s_, _e_, _n_, __6, _H_, _e_, _l_, _l_, _i_, _g_, _k_, _e_, _i_, _t_, _SLASH, _K_, _o_, _n_, _t_, _r_, _a_, _s_, _t_, _END_,       //_GERMAN(Deu)
    _O_, _RUS_54, _p_, _e_, _r_, _y_, _RUS_5A, _RUS_58, _p_, _y_, _RUS_57, _RUS_54, _e_, __6, _o_, _RUS_66, _RUS_5F, _y_, _RUS_5C, __6, _RUS_59, _p_, _RUS_53, _o_, _c_, _RUS_54, _RUS_51, _SLASH, _RUS_53, _o_, _RUS_56, _RUS_54, _p_, _a_, _c_, _RUS_54, _RUS_56, _o_, _c_, _RUS_54, _RUS_51, _END_,  //_RUSSIAN        
    
};
#endif
BYTE code tOSD_sDESCRIPTION_IMAGE_POSITION[] =
{
    _A_, _d_, _j_, _u_, _s_, _t_, _s_, __6, _i_, _m_, _a_, _g_, _e_, __6, _H_, _o_, _r_, _i_, _z_, _o_, _n_, _t_, _a_, _l_, _SLASH, _V_, _e_, _r_, _t_, _i_, _c_, _a_, _l_, __6, _p_, _o_, _s_, _i_, _t_, _i_, _o_, _n_, _END_,
    _A_, _j_, _u_, _s_, _t_, _e_, _r_, __6, _l_, _a_, __6, _p_, _o_, _s_, _i_, _t_, _i_, _o_, _n_, __6, _h_, _o_, _r_, _i_, _z_, _o_, _n_, _t_, _a_, _l_, _e_, _SLASH, _v_, _e_, _r_, _t_, _i_, _c_, _a_, _l_, _e_, __6, _d_, _e_, __6, _l_, _SP_up_dot_, _i_, _m_, _a_, _g_, _e_, _END_, // _FRENCH
    _R_, _e_, _g_, _o_, _l_, _a_, _r_, _e_, __6, _l_, _a_, __6, _p_, _o_, _s_, _i_, _z_, _i_, _o_, _n_, _e_, __6, _o_, _r_, _i_, _z_, _z_, _o_, _n_, _t_, _a_, _l_, _e_, _SLASH, _v_, _e_, _r_, _t_, _i_, _c_, _a_, _l_, _e_, __6, _d_, _e_, _l_, _l_, _SP_up_dot_, _i_, _m_, _m_, _a_, _g_, _i_, _n_, _e_, _END_, //_ITALIAN
    _CHT_0E, _CHT_0F, _CHT_17, _CHT_18,_CHT_19, _CHT_1A, _SLASH, _CHT_1B, _CHT_1C, _CHT_1D, _CHT_1E, _END_,                 //_CHINESE_S     
    _A_, _j_, _u_, _s_, _t_, _a_, _r_, __5, _l_, _a_, __5, _p_, _o_, _s_, _i_, _c_, _i_, _SP_p_o_, _n_, __5, _h_, _o_, _r_, _i_, _z_, _o_, _n_, _t_, _a_, _l_, __5, _y_, __5, _v_, _e_, _r_, _t_, _i_, _c_, _a_, _l_, __5, _p_, _o_, _s_, _i_, _t_, _i_, _o_, _n_, __5, _d_, _e_, __5, _l_, _a_, __5, _i_, _m_, _a_, _g_, _e_, _n_, _END_, //_SPANISH(Esp)
    _JAP_036, _JAP_037,_JAP_04E, _JAP_04F, _JAP_03E, _JAP_03F, _JAP_050, _JAP_051, _JAP_052, _JAP_053, _SLASH, _JAP_054, _JAP_055, _JAP_056, _JAP_057, _JAP_058, _JAP_059, _JAP_05A, _JAP_05B, _JAP_03E, _JAP_03F, _JAP_04A, _JAP_04B, _JAP_04C, _JAP_04D, _END_, //_JAPAN        
    _H_, _o_, _r_, _i_, _z_, _o_, _n_, _t_, _a_, _l_, _e_, _SLASH, _v_, _e_, _r_, _t_, _i_, _k_, _a_, _l_, _e_, __6, _B_, _i_, _l_, _d_, _p_, _o_, _s_, _i_, _t_, _i_, _o_, _n_, __6, _a_, _n_, _p_, _a_, _s_, _s_, _e_, _n_, _END_,       //_GERMAN(Deu)
//    _O_, _RUS_54, _p_, _e_, _r_, _y_, _RUS_5A, _RUS_58, _p_, _y_, _RUS_57, _RUS_54, _e_, __6, _RUS_5E, _o_, _RUS_5A, _o_, _RUS_60, _RUS_61, _e_, _RUS_56, _RUS_58, _e_, __6, _RUS_58, _RUS_63, _o_, _RUS_66, _p_, _a_, _RUS_60, _RUS_61, _e_, _RUS_56, _RUS_58, _RUS_59, __6, _RUS_5E, _o_, __6, _RUS_68, _o_, _p_, _RUS_58, _RUS_63, _o_, _RUS_56, _RUS_54, _a_, _RUS_5A, _RUS_58, _SLASH, _RUS_50, _e_, _p_, _RUS_54, _RUS_58, _RUS_53, _a_, _RUS_5A, _RUS_58, _END_,  //_RUSSIAN        
    _O_, _RUS_54, _p_, _e_, _r_, _y_, _RUS_5A, _RUS_58, _p_, _DOT, __6, _RUS_5E, _o_, _RUS_5A, _o_, _RUS_60, _RUS_61, _DOT, __6, _RUS_69, _RUS_63, _o_, _RUS_66, _p_, _a_, _RUS_60, _RUS_61, _DOT, __6, _RUS_5E, _o_, __6, _RUS_68, _o_, _p_, _RUS_58, _RUS_63, _DOT, _SLASH, _RUS_50, _e_, _p_, _RUS_54, _RUS_58, _RUS_53, _a_, _RUS_5A, _RUS_58, _END_,  //_RUSSIAN                 

};

BYTE code tOSD_sDESCRIPTION_IMAGE_SETUP[] =
{
    _O_, _p_, _t_, _i_, _m_, _i_, _z_, _e_, _s_, __6, _i_, _m_, _a_, _g_, _e_, _PARENT_OPEN, _s_, _i_, _z_, _e_, _COMMA, _p_, _o_, _s_, _i_, _t_, _i_, _o_, _n_, _COMMA, _p_, _h_, _a_, _s_, _e_, _COMMA, _a_, _n_, _d_, __6, _c_, _l_, _o_, _c_, _k_, _PARENT_CLOSE, _END_,  
    _O_, _p_, _t_, _i_, _m_, _i_, _s_, _e_, __6, _l_, _SP_up_dot_, _i_, _m_, _a_, _g_, _e_, _PARENT_OPEN, _t_, _a_, _i_, _l_, _l_, _e_, _COMMA, _p_, _o_, _s_, _i_, _t_, _i_, _o_, _n_, _COMMA, _p_, _h_, _a_, _s_, _e_, __6, _e_, _t_, __6, _h_, _o_, _r_, _l_, _o_, _g_, _e_, _PARENT_CLOSE, _END_,                           //_FRENCH    
    _O_, _t_, _t_, _i_, _m_, _i_, _z_, _z_, _a_, __6, _l_, _SP_up_dot_, _i_, _m_, _m_, _a_, _g_, _i_, _n_, _e_, _PARENT_OPEN, _d_, _i_, _m_, _e_, _n_, _s_, _i_, _o_, _n_, _e_, _COMMA, _p_, _o_, _s_, _i_, _z_, _i_, _o_, _n_, _e_, _COMMA, _f_, _a_, _s_, _e_, __6, _e_, __6, _o_, _r_, _o_, _l_, _o_, _g_, _i_, _o_, _PARENT_CLOSE, _END_,                           //_ITALIAN
    _CHT_10, _CHT_11, _CHT_1F, _CHT_20, _END_,  
    _O_, _p_, _t_, _i_, _m_, _i_, _z_, _a_, __6, _l_, _a_, __6, _i_, _m_, _a_, _g_, _e_, _n_, _PARENT_OPEN, _t_, _a_, _m_, _a_, _SP_s_n_, _o_, _COMMA, _p_, _o_, _s_, _i_, _c_, _i_, _SP_p_o_, _n_, _COMMA, _f_, _a_, _s_, _e_, __6, _y_, __6, _r_, _e_, _l_, _o_, _j_, _PARENT_CLOSE, _END_,                                      //_SPANISH(Esp)
    _JAP_036, _JAP_037,_JAP_04E, _JAP_04F, _JAP_03E, _JAP_03F, _JAP_05C, _JAP_05D,_JAP_05E, _JAP_04A, _JAP_04B, _JAP_04C,_JAP_04D,_JAP_05F,_JAP_060, _JAP_061, _JAP_062, _JAP_063,_JAP_064,_JAP_065, _PARENT_OPEN, _JAP_066, _JAP_067, _JAP_068, _JAP_069, _COMMA_DUM, _JAP_058, _JAP_059, _JAP_05A, _JAP_05B, _COMMA_DUM, _JAP_058, _JAP_06A, _JAP_06B, _COMMA_DUM, _JAP_033, _JAP_034, _JAP_06C, _JAP_033, _PARENT_CLOSE, _END_,   //_JAPAN        
    _B_, _i_, _l_, _d_, __6, _o_, _p_, _t_, _i_, _m_, _i_, _e_, _r_, _e_, _n_, _PARENT_OPEN, _g_, _r_, _SP_dd_o_, _SP_beta_, _e_, _COMMA, _p_, _o_, _s_, _i_, _t_, _i_, _o_, _n_, _COMMA, _p_, _h_, _a_, _s_, _e_, __6, _u_, _n_, _d_, __6, _t_, _a_, _k_, _t_, _g_, _e_, _b_, _e_, _r_, _PARENT_CLOSE, _END_,       //_GERMAN(Deu)
    //_O_, _RUS_5E, _RUS_54, _RUS_58, _RUS_55, _RUS_58, _RUS_63, _a_, _RUS_64, _RUS_58, _RUS_59, __6, _RUS_58, _RUS_63, _o_, _RUS_66, _p_, _a_, _RUS_60, _RUS_61, _e_, _RUS_56, _RUS_58, _RUS_59, _PARENT_OPEN, _p_, _a_, _RUS_63, _RUS_55, _e_, _p_, _COMMA, __6, _RUS_5E, _o_, _RUS_5E, _o_, _RUS_60, _RUS_61, _e_, _RUS_56, _RUS_58, _e_, _COMMA, __6, _RUS_67, _a_, _RUS_63, _a_, __6, _RUS_58, __6, _RUS_65, _a_, _c_, _RUS_54, _o_, _RUS_54, _a_, _PARENT_CLOSE, _DOT, _END_,  //_RUSSIAN                 
    _O_, _RUS_5E, _RUS_54, _RUS_58, _RUS_55, _RUS_58, _RUS_63, _DOT, __6, _RUS_58, _RUS_63, _o_, _RUS_66, _p_, _a_, _RUS_60, _RUS_61, _DOT, _PARENT_OPEN, _p_, _a_, _RUS_63, _RUS_55, _DOT, _COMMA, _RUS_5E, _o_, _RUS_5A, _o_, _RUS_60, _RUS_61, _DOT, _COMMA, _RUS_67, _a_, _RUS_63, _a_, __6, _RUS_58, __6, _RUS_65, _a_, _c_, _RUS_54, _o_, _RUS_54, _a_, _PARENT_CLOSE, _END_,  //_RUSSIAN                 
};

BYTE code tOSD_sDESCRIPTION_IMAGE_PROPERTIES[] =
{
    _A_, _d_, _j_, _u_, _s_, _t_, _s_, __6, _i_, _m_, _a_, _g_, _e_, __6, _p_, _r_, _o_, _p_, _e_, _r_, _t_, _i_, _e_, _s_, _END_,
    _A_, _j_, _u_, _s_, _t_, _e_, _r_, __6, _l_, _e_, _s_, __6, _p_, _r_, _o_, _p_, _r_, _i_, _SP_p_e_, _t_, _SP_p_e_, _s_, __6, _d_, _e_, __6, _l_, _SP_up_dot_, _i_, _m_, _a_, _g_, _e_, _END_,       //_FRENCH    
    _R_, _e_, _g_, _o_, _l_, _a_, _r_, _e_, __6, _l_, _e_, __6, _p_, _r_, _o_, _p_, _e_, _i_, _t_, _SP_n_a_, __6, _d_, _e_, _l_, _l_, _SP_up_dot_, _i_, _m_, _m_, _a_, _g_, _i_, _n_, _e_, _END_,       //_ITALIAN
    _CHT_0E, _CHT_0F, _CHT_17, _CHT_18,_CHT_21, _CHT_22, _END_,                 //_CHINESE_S     
    _A_, _j_, _u_, _s_, _t_, _a_, _r_, __6, _l_, _a_, _s_, __6, _p_, _r_, _o_, _p_, _i_, _e_, _d_, _a_, _d_, _e_, _s_, __6, _d_, _e_, __6, _l_, _a_, __6, _i_, _m_, _a_, _g_, _e_, _n_, _END_,           //_SPANISH(Esp)
    _JAP_036, _JAP_037, _JAP_04E, _JAP_04F, _JAP_03E, _JAP_03F, _JAP_06D, _JAP_034, _JAP_06E, _JAP_06F, _JAP_070, _JAP_03E, _JAP_03F, _JAP_04A, _JAP_04B, _JAP_04C, _JAP_04D, _END_,                                 //_JAPAN        
    _B_, _i_, _l_, _d_, _e_, _i_, _g_, _e_, _n_, _s_, _c_, _h_, _a_, _f_, _t_, _e_, _n_, __6, _a_, _n_, _p_, _a_, _s_, _s_, _e_, _n_, _END_,       //_GERMAN(Deu)
    _O_, _RUS_54, _p_, _e_, _r_, _y_, _RUS_5A, _RUS_58, _p_, _y_, _RUS_57, _RUS_54, _e_, __6, _c_, _RUS_50, _o_, _RUS_57, _c_, _RUS_54, _RUS_50, _a_, __6, _RUS_58, _RUS_63, _o_, _RUS_66, _p_, _a_, _RUS_60, _RUS_61, _e_, _RUS_56, _RUS_58, _RUS_59, _END_,  //_RUSSIAN                 
        
};

BYTE code tOSD_sDESCRIPTION_OPTION[] =
{
    _O_, _p_, _t_, _i_, _o_, _n_, _s_, _END_,                               //_ENGLISH
    _O_, _p_, _t_, _i_, _o_, _n_, _s_, _END_,                               //_FRENCH    
    _O_, _p_, _z_, _i_, _o_, _n_, _i_, _END_,                               //_ITALIAN
    _CHT_23, _CHT_24, _END_,                                                //_CHINESE_S     
    _O_, _p_, _c_, _i_, _o_, _n_, _e_, _s_ ,_END_,                          //_SPANISH(Esp)
    _JAP_071, _JAP_06D, _JAP_072, _JAP_073, _JAP_074, _END_,                //_JAPAN        
    _O_, _p_, _t_, _i_, _o_, _n_, _e_, _n_, _END_,                          //_GERMAN(Deu)
    _RUS_5D, _a_, _p_, _a_, _RUS_55, _e_, _RUS_54, _p_, _RUS_52, _END_,     //_RUSSIAN                     
};


BYTE code tOSD_sDESCRIPTION_FACTORY[] =
{
    _F_, _a_, _c_, _t_, _o_, _r_, _y_, _END_,
    _F_, _a_, _c_, _t_, _o_, _r_, _y_, _END_,                 //_FRENCH    
    _F_, _a_, _c_, _t_, _o_, _r_, _y_, _END_,                 //_ITALIAN
    _CHT_27, _CHT_28, _END_,                                  //_CHINESE_S     
    _F_, _a_, _c_, _t_, _o_, _r_, _y_,_END_,                  //_SPANISH(Esp)
    _JAP_075, _JAP_076, _JAP_077, _JAP_078, _END_,            //_JAPAN        
    _F_, _a_, _c_, _t_, _o_, _r_, _y_,_END_,                  //_GERMAN(Deu)
    _F_, _a_, _c_, _t_, _o_, _r_, _y_,_END_,                  //_RUSSIAN         
};


#endif
/*
BYTE code tOSD_ITEM_BRI_CON_DCR_0[]=
{
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _SLASH, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _SLASH, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _SLASH, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _SLASH, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _SLASH, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _SLASH, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _SLASH, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _SLASH, _END_,
};
*/
/*
BYTE code tOSD_ITEM_BRI_CON_DCR_1[]=
{
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _SLASH, _bD_, _bC_, _bR_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _SLASH, _bD_, _bC_, _bR_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _SLASH, _bD_, _bC_, _bR_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _SLASH, _bD_, _bC_, _bR_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _SLASH, _bD_, _bC_, _bR_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _SLASH, _bD_, _bC_, _bR_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _SLASH, _bD_, _bC_, _bR_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _SLASH, _bD_, _bC_, _bR_, _END_,
};

BYTE code tOSD_ITEM_IMAGE_POSITION[]=
{
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
};

BYTE code tOSD_ITEM_IMAGE_SETUP[]=
{
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
};

BYTE code tOSD_ITEM_IMAGE_PROPERTIES[]=
{
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _br_, _bo_, _bp_, _be_, _br_, _bt_, _bi_, _be_, _bs_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _br_, _bo_, _bp_, _be_, _br_, _bt_, _bi_, _be_, _bs_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _br_, _bo_, _bp_, _be_, _br_, _bt_, _bi_, _be_, _bs_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _br_, _bo_, _bp_, _be_, _br_, _bt_, _bi_, _be_, _bs_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _br_, _bo_, _bp_, _be_, _br_, _bt_, _bi_, _be_, _bs_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _br_, _bo_, _bp_, _be_, _br_, _bt_, _bi_, _be_, _bs_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _br_, _bo_, _bp_, _be_, _br_, _bt_, _bi_, _be_, _bs_, _END_,
    _bI_, _bm_, _ba_, _bg_, _be_, __4, _bP_, _br_, _bo_, _bp_, _be_, _br_, _bt_, _bi_, _be_, _bs_, _END_,
};

BYTE code tOSD_ITEM_OPTIONS[]=
{
    _bO_, _bp_, _bt_, _bi_, _bo_, _bn_, _bs_, _END_,
    _bO_, _bp_, _bt_, _bi_, _bo_, _bn_, _bs_, _END_,
    _bO_, _bp_, _bt_, _bi_, _bo_, _bn_, _bs_, _END_,
    _bO_, _bp_, _bt_, _bi_, _bo_, _bn_, _bs_, _END_,
    _bO_, _bp_, _bt_, _bi_, _bo_, _bn_, _bs_, _END_,
    _bO_, _bp_, _bt_, _bi_, _bo_, _bn_, _bs_, _END_,
    _bO_, _bp_, _bt_, _bi_, _bo_, _bn_, _bs_, _END_,
    _bO_, _bp_, _bt_, _bi_, _bo_, _bn_, _bs_, _END_,
};

BYTE code tOSD_ITEM_BRIGHTNESS[]=
{
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _END_,
    _bB_, _br_, _bi_, _bg_, _bh_, _bt_, _bn_, _be_, _bs_, _bs_, _END_,
};

BYTE code tOSD_ITEM_CONTRAST[]=
{
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _END_,
    _bC_, _bo_, _bn_, _bt_, _br_, _ba_, _bs_, _bt_, _END_,
};

BYTE code tOSD_ITEM_DCR[]=
{
    _bD_, _bC_, _bR_, _END_,
    _bD_, _bC_, _bR_, _END_,
    _bD_, _bC_, _bR_, _END_,
    _bD_, _bC_, _bR_, _END_,
    _bD_, _bC_, _bR_, _END_,
    _bD_, _bC_, _bR_, _END_,
    _bD_, _bC_, _bR_, _END_,
    _bD_, _bC_, _bR_, _END_,
};

BYTE code tOSD_ITEM_H_POSITION[]=
{
    _bH_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bH_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bH_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bH_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bH_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bH_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bH_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bH_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
};

BYTE code tOSD_ITEM_V_POSITION[]=
{
    _bV_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bV_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bV_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bV_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bV_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bV_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bV_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bV_, __4, _bP_, _bo_, _bs_, _bi_, _bt_, _bi_, _bo_, _bn_, _END_,
};

BYTE code tOSD_ITEM_AUTO_SETUP[]=
{
    _bA_, _bu_, _bt_, _bo_, _bm_, _ba_, _bt_, _bi_, _bc_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bA_, _bu_, _bt_, _bo_, _bm_, _ba_, _bt_, _bi_, _bc_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bA_, _bu_, _bt_, _bo_, _bm_, _ba_, _bt_, _bi_, _bc_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bA_, _bu_, _bt_, _bo_, _bm_, _ba_, _bt_, _bi_, _bc_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bA_, _bu_, _bt_, _bo_, _bm_, _ba_, _bt_, _bi_, _bc_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bA_, _bu_, _bt_, _bo_, _bm_, _ba_, _bt_, _bi_, _bc_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bA_, _bu_, _bt_, _bo_, _bm_, _ba_, _bt_, _bi_, _bc_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
    _bA_, _bu_, _bt_, _bo_, _bm_, _ba_, _bt_, _bi_, _bc_, __4, _bS_, _be_, _bt_, _bu_, _bp_, _END_,
};

BYTE code tOSD_ITEM_MANUAL[]=
{
    _bM_, _ba_, _bn_, _bu_, _ba_, _bl_, _END_,
    _bM_, _ba_, _bn_, _bu_, _ba_, _bl_, _END_,
    _bM_, _ba_, _bn_, _bu_, _ba_, _bl_, _END_,
    _bM_, _ba_, _bn_, _bu_, _ba_, _bl_, _END_,
    _bM_, _ba_, _bn_, _bu_, _ba_, _bl_, _END_,
    _bM_, _ba_, _bn_, _bu_, _ba_, _bl_, _END_,
    _bM_, _ba_, _bn_, _bu_, _ba_, _bl_, _END_,
    _bM_, _ba_, _bn_, _bu_, _ba_, _bl_, _END_,
};

BYTE code tOSD_ITEM_SCALING[]=
{
    _bS_, _bc_, _ba_, _bl_, _bi_, _bn_, _bg_, _END_,
    _bS_, _bc_, _ba_, _bl_, _bi_, _bn_, _bg_, _END_,
    _bS_, _bc_, _ba_, _bl_, _bi_, _bn_, _bg_, _END_,
    _bS_, _bc_, _ba_, _bl_, _bi_, _bn_, _bg_, _END_,
    _bS_, _bc_, _ba_, _bl_, _bi_, _bn_, _bg_, _END_,
    _bS_, _bc_, _ba_, _bl_, _bi_, _bn_, _bg_, _END_,
    _bS_, _bc_, _ba_, _bl_, _bi_, _bn_, _bg_, _END_,
    _bS_, _bc_, _ba_, _bl_, _bi_, _bn_, _bg_, _END_,
};

BYTE code tOSD_ITEM_COLOR[]=
{
    _bC_, _bo_, _bl_, _bo_, _br_, _END_,
    _bC_, _bo_, _bl_, _bo_, _br_, _END_,
    _bC_, _bo_, _bl_, _bo_, _br_, _END_,
    _bC_, _bo_, _bl_, _bo_, _br_, _END_,
    _bC_, _bo_, _bl_, _bo_, _br_, _END_,
    _bC_, _bo_, _bl_, _bo_, _br_, _END_,
    _bC_, _bo_, _bl_, _bo_, _br_, _END_,
    _bC_, _bo_, _bl_, _bo_, _br_, _END_,
};

BYTE code tOSD_ITEM_INPUT_SIGNAL[]=
{
    _bI_, _bn_, _bp_, _bu_, _bt_, __4, _bS_, _bi_, _bg_, _bn_, _ba_, _bl_, _END_,
    _bI_, _bn_, _bp_, _bu_, _bt_, __4, _bS_, _bi_, _bg_, _bn_, _ba_, _bl_, _END_,
    _bI_, _bn_, _bp_, _bu_, _bt_, __4, _bS_, _bi_, _bg_, _bn_, _ba_, _bl_, _END_,
    _bI_, _bn_, _bp_, _bu_, _bt_, __4, _bS_, _bi_, _bg_, _bn_, _ba_, _bl_, _END_,
    _bI_, _bn_, _bp_, _bu_, _bt_, __4, _bS_, _bi_, _bg_, _bn_, _ba_, _bl_, _END_,
    _bI_, _bn_, _bp_, _bu_, _bt_, __4, _bS_, _bi_, _bg_, _bn_, _ba_, _bl_, _END_,
    _bI_, _bn_, _bp_, _bu_, _bt_, __4, _bS_, _bi_, _bg_, _bn_, _ba_, _bl_, _END_,
    _bI_, _bn_, _bp_, _bu_, _bt_, __4, _bS_, _bi_, _bg_, _bn_, _ba_, _bl_, _END_,
};

BYTE code tOSD_ITEM_FACTORY_DEFAULT[]=
{
    _bF_, _ba_, _bc_, _bt_, _bo_, _br_, _by_, __4, _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bF_, _ba_, _bc_, _bt_, _bo_, _br_, _by_, __4, _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bF_, _ba_, _bc_, _bt_, _bo_, _br_, _by_, __4, _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bF_, _ba_, _bc_, _bt_, _bo_, _br_, _by_, __4, _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bF_, _ba_, _bc_, _bt_, _bo_, _br_, _by_, __4, _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bF_, _ba_, _bc_, _bt_, _bo_, _br_, _by_, __4, _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bF_, _ba_, _bc_, _bt_, _bo_, _br_, _by_, __4, _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bF_, _ba_, _bc_, _bt_, _bo_, _br_, _by_, __4, _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
};

BYTE code tOSD_ITEM_ACCESSIBILITY[]=
{
    _bA_, _bc_, _bc_, _be_, _bs_, _bs_, _bi_, _bb_, _bi_, _bl_, _bi_, _bt_, _by_, _END_,
    _bA_, _bc_, _bc_, _be_, _bs_, _bs_, _bi_, _bb_, _bi_, _bl_, _bi_, _bt_, _by_, _END_,
    _bA_, _bc_, _bc_, _be_, _bs_, _bs_, _bi_, _bb_, _bi_, _bl_, _bi_, _bt_, _by_, _END_,
    _bA_, _bc_, _bc_, _be_, _bs_, _bs_, _bi_, _bb_, _bi_, _bl_, _bi_, _bt_, _by_, _END_,
    _bA_, _bc_, _bc_, _be_, _bs_, _bs_, _bi_, _bb_, _bi_, _bl_, _bi_, _bt_, _by_, _END_,
    _bA_, _bc_, _bc_, _be_, _bs_, _bs_, _bi_, _bb_, _bi_, _bl_, _bi_, _bt_, _by_, _END_,
    _bA_, _bc_, _bc_, _be_, _bs_, _bs_, _bi_, _bb_, _bi_, _bl_, _bi_, _bt_, _by_, _END_,
    _bA_, _bc_, _bc_, _be_, _bs_, _bs_, _bi_, _bb_, _bi_, _bl_, _bi_, _bt_, _by_, _END_,
};

BYTE code tOSD_ITEM_INFORMATION[]=
{
    _bI_, _bn_, _bf_, _bo_, _br_, _bm_, _ba_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bn_, _bf_, _bo_, _br_, _bm_, _ba_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bn_, _bf_, _bo_, _br_, _bm_, _ba_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bn_, _bf_, _bo_, _br_, _bm_, _ba_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bn_, _bf_, _bo_, _br_, _bm_, _ba_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bn_, _bf_, _bo_, _br_, _bm_, _ba_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bn_, _bf_, _bo_, _br_, _bm_, _ba_, _bt_, _bi_, _bo_, _bn_, _END_,
    _bI_, _bn_, _bf_, _bo_, _br_, _bm_, _ba_, _bt_, _bi_, _bo_, _bn_, _END_,
};

BYTE code tOSD_ITEM_MENU_LANGUAGE[]=
{
    _bM_, _be_, _bn_, _bu_, __4, _bL_, _ba_, _bn_, _bg_, _bu_, _ba_, _bg_, _be_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bL_, _ba_, _bn_, _bg_, _bu_, _ba_, _bg_, _be_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bL_, _ba_, _bn_, _bg_, _bu_, _ba_, _bg_, _be_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bL_, _ba_, _bn_, _bg_, _bu_, _ba_, _bg_, _be_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bL_, _ba_, _bn_, _bg_, _bu_, _ba_, _bg_, _be_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bL_, _ba_, _bn_, _bg_, _bu_, _ba_, _bg_, _be_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bL_, _ba_, _bn_, _bg_, _bu_, _ba_, _bg_, _be_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bL_, _ba_, _bn_, _bg_, _bu_, _ba_, _bg_, _be_, _END_,
};

BYTE code tOSD_ITEM_ON[]=
{
    _bO_, _bn_, _END_,
    _bO_, _bn_, _END_,
    _bO_, _bn_, _END_,
    _bO_, _bn_, _END_,
    _bO_, _bn_, _END_,
    _bO_, _bn_, _END_,
    _bO_, _bn_, _END_,
    _bO_, _bn_, _END_,
};

BYTE code tOSD_ITEM_OFF[]=
{
    _bO_, _bf_, _bf_, _END_,
    _bO_, _bf_, _bf_, _END_,
    _bO_, _bf_, _bf_, _END_,
    _bO_, _bf_, _bf_, _END_,
    _bO_, _bf_, _bf_, _END_,
    _bO_, _bf_, _bf_, _END_,
    _bO_, _bf_, _bf_, _END_,
    _bO_, _bf_, _bf_, _END_,
};

BYTE code tOSD_ITEM_CLOCK[]=
{
    _bC_, _bl_, _bo_, _bc_, _bk_, _END_,
    _bC_, _bl_, _bo_, _bc_, _bk_, _END_,
    _bC_, _bl_, _bo_, _bc_, _bk_, _END_,
    _bC_, _bl_, _bo_, _bc_, _bk_, _END_,
    _bC_, _bl_, _bo_, _bc_, _bk_, _END_,
    _bC_, _bl_, _bo_, _bc_, _bk_, _END_,
    _bC_, _bl_, _bo_, _bc_, _bk_, _END_,
    _bC_, _bl_, _bo_, _bc_, _bk_, _END_,
};

BYTE code tOSD_ITEM_PHASE[]=
{
    _bP_, _bh_, _ba_, _bs_, _be_, _END_,
    _bP_, _bh_, _ba_, _bs_, _be_, _END_,
    _bP_, _bh_, _ba_, _bs_, _be_, _END_,
    _bP_, _bh_, _ba_, _bs_, _be_, _END_,
    _bP_, _bh_, _ba_, _bs_, _be_, _END_,
    _bP_, _bh_, _ba_, _bs_, _be_, _END_,
    _bP_, _bh_, _ba_, _bs_, _be_, _END_,
    _bP_, _bh_, _ba_, _bs_, _be_, _END_,
};

BYTE code tOSD_ITEM_PRESET_MODE[]=
{
    _bP_, _br_, _be_, _bs_, _be_, _bt_, __4, _bM_, _bo_, _bd_, _be_, _END_,
    _bP_, _br_, _be_, _bs_, _be_, _bt_, __4, _bM_, _bo_, _bd_, _be_, _END_,
    _bP_, _br_, _be_, _bs_, _be_, _bt_, __4, _bM_, _bo_, _bd_, _be_, _END_,
    _bP_, _br_, _be_, _bs_, _be_, _bt_, __4, _bM_, _bo_, _bd_, _be_, _END_,
    _bP_, _br_, _be_, _bs_, _be_, _bt_, __4, _bM_, _bo_, _bd_, _be_, _END_,
    _bP_, _br_, _be_, _bs_, _be_, _bt_, __4, _bM_, _bo_, _bd_, _be_, _END_,
    _bP_, _br_, _be_, _bs_, _be_, _bt_, __4, _bM_, _bo_, _bd_, _be_, _END_,
    _bP_, _br_, _be_, _bs_, _be_, _bt_, __4, _bM_, _bo_, _bd_, _be_, _END_,
};

BYTE code tOSD_ITEM_CUSTOM[]=
{
    _bC_, _bu_, _bs_, _bt_, _bo_, _bm_, _END_,
    _bC_, _bu_, _bs_, _bt_, _bo_, _bm_, _END_,
    _bC_, _bu_, _bs_, _bt_, _bo_, _bm_, _END_,
    _bC_, _bu_, _bs_, _bt_, _bo_, _bm_, _END_,
    _bC_, _bu_, _bs_, _bt_, _bo_, _bm_, _END_,
    _bC_, _bu_, _bs_, _bt_, _bo_, _bm_, _END_,
    _bC_, _bu_, _bs_, _bt_, _bo_, _bm_, _END_,
    _bC_, _bu_, _bs_, _bt_, _bo_, _bm_, _END_,
};

BYTE code tOSD_ITEM_ANALOG[]=
{
    _bA_, _bn_, _ba_, _bl_, _bo_, _bg_, _END_,
    _bA_, _bn_, _ba_, _bl_, _bo_, _bg_, _END_,
    _bA_, _bn_, _ba_, _bl_, _bo_, _bg_, _END_,
    _bA_, _bn_, _ba_, _bl_, _bo_, _bg_, _END_,
    _bA_, _bn_, _ba_, _bl_, _bo_, _bg_, _END_,
    _bA_, _bn_, _ba_, _bl_, _bo_, _bg_, _END_,
    _bA_, _bn_, _ba_, _bl_, _bo_, _bg_, _END_,
    _bA_, _bn_, _ba_, _bl_, _bo_, _bg_, _END_,
};

BYTE code tOSD_ITEM_DVI[]=
{
    _bD_, _bV_, _bI_, _END_,
    _bD_, _bV_, _bI_, _END_,
    _bD_, _bV_, _bI_, _END_,
    _bD_, _bV_, _bI_, _END_,
    _bD_, _bV_, _bI_, _END_,
    _bD_, _bV_, _bI_, _END_,
    _bD_, _bV_, _bI_, _END_,
    _bD_, _bV_, _bI_, _END_,
};

BYTE code tOSD_ITEM_HDMI[]=
{
    _bH_, _bD_, _bM_, _bI_, _END_,
    _bH_, _bD_, _bM_, _bI_, _END_,
    _bH_, _bD_, _bM_, _bI_, _END_,
    _bH_, _bD_, _bM_, _bI_, _END_,
    _bH_, _bD_, _bM_, _bI_, _END_,
    _bH_, _bD_, _bM_, _bI_, _END_,
    _bH_, _bD_, _bM_, _bI_, _END_,
    _bH_, _bD_, _bM_, _bI_, _END_,
};

BYTE code tOSD_ITEM_DISPLAY_PORT[]=
{
    _bD_, _bI_, _bS_, _bP_, _bL_, _bA_, _bY_, ___, _bP_, _bO_, _bR_, _bT_, _END_,
    _bD_, _bI_, _bS_, _bP_, _bL_, _bA_, _bY_, ___, _bP_, _bO_, _bR_, _bT_, _END_,
    _bD_, _bI_, _bS_, _bP_, _bL_, _bA_, _bY_, ___, _bP_, _bO_, _bR_, _bT_, _END_,
    _bD_, _bI_, _bS_, _bP_, _bL_, _bA_, _bY_, ___, _bP_, _bO_, _bR_, _bT_, _END_,
    _bD_, _bI_, _bS_, _bP_, _bL_, _bA_, _bY_, ___, _bP_, _bO_, _bR_, _bT_, _END_,
    _bD_, _bI_, _bS_, _bP_, _bL_, _bA_, _bY_, ___, _bP_, _bO_, _bR_, _bT_, _END_,
    _bD_, _bI_, _bS_, _bP_, _bL_, _bA_, _bY_, ___, _bP_, _bO_, _bR_, _bT_, _END_,
    _bD_, _bI_, _bS_, _bP_, _bL_, _bA_, _bY_, ___, _bP_, _bO_, _bR_, _bT_, _END_,
};


BYTE code tOSD_ITEM_LAN_ENGLISH[]=
{
    _bE_, _bn_, _bg_, _bl_, _bi_, _bs_, _bh_, _END_,
    _bE_, _bn_, _bg_, _bl_, _bi_, _bs_, _bh_, _END_,
    _bE_, _bn_, _bg_, _bl_, _bi_, _bs_, _bh_, _END_,
    _bE_, _bn_, _bg_, _bl_, _bi_, _bs_, _bh_, _END_,
    _bE_, _bn_, _bg_, _bl_, _bi_, _bs_, _bh_, _END_,
    _bE_, _bn_, _bg_, _bl_, _bi_, _bs_, _bh_, _END_,
    _bE_, _bn_, _bg_, _bl_, _bi_, _bs_, _bh_, _END_,
    _bE_, _bn_, _bg_, _bl_, _bi_, _bs_, _bh_, _END_,
};

BYTE code tOSD_ITEM_LAN_FRENCH[]=
{
    _bF_, _br_, _be_, _bn_, _bc_, _bh_, _END_,
    _bF_, _br_, _be_, _bn_, _bc_, _bh_, _END_,
    _bF_, _br_, _be_, _bn_, _bc_, _bh_, _END_,
    _bF_, _br_, _be_, _bn_, _bc_, _bh_, _END_,
    _bF_, _br_, _be_, _bn_, _bc_, _bh_, _END_,
    _bF_, _br_, _be_, _bn_, _bc_, _bh_, _END_,
    _bF_, _br_, _be_, _bn_, _bc_, _bh_, _END_,
    _bF_, _br_, _be_, _bn_, _bc_, _bh_, _END_,
};

BYTE code tOSD_ITEM_LAN_ITALIAN[]=
{
    _bI_, _bt_, _ba_, _bl_, _bi_, _ba_, _bn_, _END_,
    _bI_, _bt_, _ba_, _bl_, _bi_, _ba_, _bn_, _END_,
    _bI_, _bt_, _ba_, _bl_, _bi_, _ba_, _bn_, _END_,
    _bI_, _bt_, _ba_, _bl_, _bi_, _ba_, _bn_, _END_,
    _bI_, _bt_, _ba_, _bl_, _bi_, _ba_, _bn_, _END_,
    _bI_, _bt_, _ba_, _bl_, _bi_, _ba_, _bn_, _END_,
    _bI_, _bt_, _ba_, _bl_, _bi_, _ba_, _bn_, _END_,
    _bI_, _bt_, _ba_, _bl_, _bi_, _ba_, _bn_, _END_,
};

BYTE code tOSD_ITEM_LAN_CHINESE_S[]=
{
    _bC_, _bh_, _bi_, _bn_, _be_, _bs_, _be_, _END_,
    _bC_, _bh_, _bi_, _bn_, _be_, _bs_, _be_, _END_,
    _bC_, _bh_, _bi_, _bn_, _be_, _bs_, _be_, _END_,
    _bC_, _bh_, _bi_, _bn_, _be_, _bs_, _be_, _END_,
    _bC_, _bh_, _bi_, _bn_, _be_, _bs_, _be_, _END_,
    _bC_, _bh_, _bi_, _bn_, _be_, _bs_, _be_, _END_,
    _bC_, _bh_, _bi_, _bn_, _be_, _bs_, _be_, _END_,
    _bC_, _bh_, _bi_, _bn_, _be_, _bs_, _be_, _END_,
};

BYTE code tOSD_ITEM_LAN_SPANISH[]=
{
    _bS_, _bp_, _ba_, _bn_, _bi_, _bs_, _bh_, _END_,
    _bS_, _bp_, _ba_, _bn_, _bi_, _bs_, _bh_, _END_,
    _bS_, _bp_, _ba_, _bn_, _bi_, _bs_, _bh_, _END_,
    _bS_, _bp_, _ba_, _bn_, _bi_, _bs_, _bh_, _END_,
    _bS_, _bp_, _ba_, _bn_, _bi_, _bs_, _bh_, _END_,
    _bS_, _bp_, _ba_, _bn_, _bi_, _bs_, _bh_, _END_,
    _bS_, _bp_, _ba_, _bn_, _bi_, _bs_, _bh_, _END_,
    _bS_, _bp_, _ba_, _bn_, _bi_, _bs_, _bh_, _END_,
};

BYTE code tOSD_ITEM_LAN_JAPAN[]=
{
    _bJ_, _ba_, _bp_, _ba_, _bn_, _END_,
    _bJ_, _ba_, _bp_, _ba_, _bn_, _END_,
    _bJ_, _ba_, _bp_, _ba_, _bn_, _END_,
    _bJ_, _ba_, _bp_, _ba_, _bn_, _END_,
    _bJ_, _ba_, _bp_, _ba_, _bn_, _END_,
    _bJ_, _ba_, _bp_, _ba_, _bn_, _END_,
    _bJ_, _ba_, _bp_, _ba_, _bn_, _END_,
    _bJ_, _ba_, _bp_, _ba_, _bn_, _END_,
};

BYTE code tOSD_ITEM_LAN_GERMAN[]=
{
    _bG_, _be_, _br_, _bm_, _ba_, _bn_, _END_,
    _bG_, _be_, _br_, _bm_, _ba_, _bn_, _END_,
    _bG_, _be_, _br_, _bm_, _ba_, _bn_, _END_,
    _bG_, _be_, _br_, _bm_, _ba_, _bn_, _END_,
    _bG_, _be_, _br_, _bm_, _ba_, _bn_, _END_,
    _bG_, _be_, _br_, _bm_, _ba_, _bn_, _END_,
    _bG_, _be_, _br_, _bm_, _ba_, _bn_, _END_,
    _bG_, _be_, _br_, _bm_, _ba_, _bn_, _END_,
};

BYTE code tOSD_ITEM_LAN_RUSSIAN[]=
{
    _bR_, _bu_, _bs_, _bs_, _bi_, _ba_, _bn_, _END_,
    _bR_, _bu_, _bs_, _bs_, _bi_, _ba_, _bn_, _END_,
    _bR_, _bu_, _bs_, _bs_, _bi_, _ba_, _bn_, _END_,
    _bR_, _bu_, _bs_, _bs_, _bi_, _ba_, _bn_, _END_,
    _bR_, _bu_, _bs_, _bs_, _bi_, _ba_, _bn_, _END_,
    _bR_, _bu_, _bs_, _bs_, _bi_, _ba_, _bn_, _END_,
    _bR_, _bu_, _bs_, _bs_, _bi_, _ba_, _bn_, _END_,
    _bR_, _bu_, _bs_, _bs_, _bi_, _ba_, _bn_, _END_,
};

BYTE code tOSD_ITEM_FACTORY_CANCEL[]=
{
    _bC_, _ba_, _bn_, _bc_, _be_, _bl_, _END_,
    _bC_, _ba_, _bn_, _bc_, _be_, _bl_, _END_,
    _bC_, _ba_, _bn_, _bc_, _be_, _bl_, _END_,
    _bC_, _ba_, _bn_, _bc_, _be_, _bl_, _END_,
    _bC_, _ba_, _bn_, _bc_, _be_, _bl_, _END_,
    _bC_, _ba_, _bn_, _bc_, _be_, _bl_, _END_,
    _bC_, _ba_, _bn_, _bc_, _be_, _bl_, _END_,
    _bC_, _ba_, _bn_, _bc_, _be_, _bl_, _END_,
};

BYTE code tOSD_ITEM_FACTORY_RESET[]=
{
    _bR_, _be_, _bs_, _be_, _bt_, _END_,
    _bR_, _be_, _bs_, _be_, _bt_, _END_,
    _bR_, _be_, _bs_, _be_, _bt_, _END_,
    _bR_, _be_, _bs_, _be_, _bt_, _END_,
    _bR_, _be_, _bs_, _be_, _bt_, _END_,
    _bR_, _be_, _bs_, _be_, _bt_, _END_,
    _bR_, _be_, _bs_, _be_, _bt_, _END_,
    _bR_, _be_, _bs_, _be_, _bt_, _END_,
};

BYTE code tOSD_ITEM_REPEAT_RATE[]=
{
    _bB_, _bu_, _bt_, _bt_, _bo_, _bn_, __4, _br_, _be_, _bp_, _be_, _ba_, _bt_, __4, _br_, _ba_, _bt_, _be_, _END_,
    _bB_, _bu_, _bt_, _bt_, _bo_, _bn_, __4, _br_, _be_, _bp_, _be_, _ba_, _bt_, __4, _br_, _ba_, _bt_, _be_, _END_,
    _bB_, _bu_, _bt_, _bt_, _bo_, _bn_, __4, _br_, _be_, _bp_, _be_, _ba_, _bt_, __4, _br_, _ba_, _bt_, _be_, _END_,
    _bB_, _bu_, _bt_, _bt_, _bo_, _bn_, __4, _br_, _be_, _bp_, _be_, _ba_, _bt_, __4, _br_, _ba_, _bt_, _be_, _END_,
    _bB_, _bu_, _bt_, _bt_, _bo_, _bn_, __4, _br_, _be_, _bp_, _be_, _ba_, _bt_, __4, _br_, _ba_, _bt_, _be_, _END_,
    _bB_, _bu_, _bt_, _bt_, _bo_, _bn_, __4, _br_, _be_, _bp_, _be_, _ba_, _bt_, __4, _br_, _ba_, _bt_, _be_, _END_,
    _bB_, _bu_, _bt_, _bt_, _bo_, _bn_, __4, _br_, _be_, _bp_, _be_, _ba_, _bt_, __4, _br_, _ba_, _bt_, _be_, _END_,
    _bB_, _bu_, _bt_, _bt_, _bo_, _bn_, __4, _br_, _be_, _bp_, _be_, _ba_, _bt_, __4, _br_, _ba_, _bt_, _be_, _END_,
};

BYTE code tOSD_ITEM_MENU_TIMEOUT[]=
{
    _bM_, _be_, _bn_, _bu_, __4, _bt_, _bi_, _bm_, _be_, __4, _bo_, _bu_, _bt_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bt_, _bi_, _bm_, _be_, __4, _bo_, _bu_, _bt_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bt_, _bi_, _bm_, _be_, __4, _bo_, _bu_, _bt_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bt_, _bi_, _bm_, _be_, __4, _bo_, _bu_, _bt_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bt_, _bi_, _bm_, _be_, __4, _bo_, _bu_, _bt_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bt_, _bi_, _bm_, _be_, __4, _bo_, _bu_, _bt_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bt_, _bi_, _bm_, _be_, __4, _bo_, _bu_, _bt_, _END_,
    _bM_, _be_, _bn_, _bu_, __4, _bt_, _bi_, _bm_, _be_, __4, _bo_, _bu_, _bt_, _END_,
};

BYTE code tOSD_ITEM_NEUTRAL[]=
{
    _bN_, _be_, _bu_, _bt_, _br_, _ba_, _bl_, _END_,
    _bN_, _be_, _bu_, _bt_, _br_, _ba_, _bl_, _END_,
    _bN_, _be_, _bu_, _bt_, _br_, _ba_, _bl_, _END_,
    _bN_, _be_, _bu_, _bt_, _br_, _ba_, _bl_, _END_,
    _bN_, _be_, _bu_, _bt_, _br_, _ba_, _bl_, _END_,
    _bN_, _be_, _bu_, _bt_, _br_, _ba_, _bl_, _END_,
    _bN_, _be_, _bu_, _bt_, _br_, _ba_, _bl_, _END_,
    _bN_, _be_, _bu_, _bt_, _br_, _ba_, _bl_, _END_,
};

BYTE code tOSD_ITEM_sRGB[]=
{
    _bs_, _bR_, _bG_, _bB_, _END_,
    _bs_, _bR_, _bG_, _bB_, _END_,
    _bs_, _bR_, _bG_, _bB_, _END_,
    _bs_, _bR_, _bG_, _bB_, _END_,
    _bs_, _bR_, _bG_, _bB_, _END_,
    _bs_, _bR_, _bG_, _bB_, _END_,
    _bs_, _bR_, _bG_, _bB_, _END_,
    _bs_, _bR_, _bG_, _bB_, _END_,
};

BYTE code tOSD_ITEM_REDDISH[]=
{
    _bR_, _be_, _bd_, _bd_, _bi_, _bs_, _bh_, _END_,
    _bR_, _be_, _bd_, _bd_, _bi_, _bs_, _bh_, _END_,
    _bR_, _be_, _bd_, _bd_, _bi_, _bs_, _bh_, _END_,
    _bR_, _be_, _bd_, _bd_, _bi_, _bs_, _bh_, _END_,
    _bR_, _be_, _bd_, _bd_, _bi_, _bs_, _bh_, _END_,
    _bR_, _be_, _bd_, _bd_, _bi_, _bs_, _bh_, _END_,
    _bR_, _be_, _bd_, _bd_, _bi_, _bs_, _bh_, _END_,
    _bR_, _be_, _bd_, _bd_, _bi_, _bs_, _bh_, _END_,
};

BYTE code tOSD_ITEM_BLUISH[]=
{
    _bB_, _bl_, _bu_, _bi_, _bs_, _bh_, _END_,
    _bB_, _bl_, _bu_, _bi_, _bs_, _bh_, _END_,
    _bB_, _bl_, _bu_, _bi_, _bs_, _bh_, _END_,
    _bB_, _bl_, _bu_, _bi_, _bs_, _bh_, _END_,
    _bB_, _bl_, _bu_, _bi_, _bs_, _bh_, _END_,
    _bB_, _bl_, _bu_, _bi_, _bs_, _bh_, _END_,
    _bB_, _bl_, _bu_, _bi_, _bs_, _bh_, _END_,
    _bB_, _bl_, _bu_, _bi_, _bs_, _bh_, _END_,
};

BYTE code tOSD_ITEM_CUSTOM_R[]=
{
    _bR_, _be_, _bd_, _END_,
    _bR_, _be_, _bd_, _END_,
    _bR_, _be_, _bd_, _END_,
    _bR_, _be_, _bd_, _END_,
    _bR_, _be_, _bd_, _END_,
    _bR_, _be_, _bd_, _END_,
    _bR_, _be_, _bd_, _END_,
    _bR_, _be_, _bd_, _END_,
};

BYTE code tOSD_ITEM_CUSTOM_G[]=
{
    _bG_, _br_, _be_, _be_, _bn_, _END_,
    _bG_, _br_, _be_, _be_, _bn_, _END_,
    _bG_, _br_, _be_, _be_, _bn_, _END_,
    _bG_, _br_, _be_, _be_, _bn_, _END_,
    _bG_, _br_, _be_, _be_, _bn_, _END_,
    _bG_, _br_, _be_, _be_, _bn_, _END_,
    _bG_, _br_, _be_, _be_, _bn_, _END_,
    _bG_, _br_, _be_, _be_, _bn_, _END_,
};

BYTE code tOSD_ITEM_CUSTOM_B[]=
{
    _bB_, _bl_, _bu_, _be_, _END_,
    _bB_, _bl_, _bu_, _be_, _END_,
    _bB_, _bl_, _bu_, _be_, _END_,
    _bB_, _bl_, _bu_, _be_, _END_,
    _bB_, _bl_, _bu_, _be_, _END_,
    _bB_, _bl_, _bu_, _be_, _END_,
    _bB_, _bl_, _bu_, _be_, _END_,
    _bB_, _bl_, _bu_, _be_, _END_,
};

BYTE code tOSD_ITEM_REPEAT_DEFAULT[]=
{
    _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
    _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_,
};

BYTE code tOSD_ITEM_REPEAT_SLOW[]=
{
    _bS_, _bl_, _bo_, _bw_, _END_,
    _bS_, _bl_, _bo_, _bw_, _END_,
    _bS_, _bl_, _bo_, _bw_, _END_,
    _bS_, _bl_, _bo_, _bw_, _END_,
    _bS_, _bl_, _bo_, _bw_, _END_,
    _bS_, _bl_, _bo_, _bw_, _END_,
    _bS_, _bl_, _bo_, _bw_, _END_,
    _bS_, _bl_, _bo_, _bw_, _END_,
};
*/
//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
