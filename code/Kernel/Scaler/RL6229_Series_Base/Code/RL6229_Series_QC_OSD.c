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
// ID Code      : RL6229_Series_QC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6229_SERIES_QC_OSD__

#include "ScalerFunctionInclude.h"

#if(_FACTORY_RTD_QC_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _TEST_PASS                                      0
#define _TEST_FAIL                                      1

#define _FRAME_DELAY_TIME                               30
#define _CRC_DELAY_TIME      	    	                30
#define _DISPLAY_DELAY_TIME                             1000

//----------------------------------------------------------------------------
// OSD QC Test Required Definition
//----------------------------------------------------------------------------

// Row Command Byte0 Bit[7]
#define _ROW_START                                      (0x01 << 7)
#define _ROW_END                                        (0x00 << 7)

// Row Command Byte0 Bit[6]
#define _VBI_ENABLE                                     (0x01 << 6)
#define _VBI_DISABLE                                    (0x00 << 6)

// Row Command Byte0 Bit[5]
#define _1BITFONT_SELECT_0_511                          (0x00 << 5)
#define _1BITFONT_SELECT_512_1023                       (0x01 << 5)

// Row Command Byte0 Bit[4:2]
#define _CHARACTER_TYPE_NONE                            (0x00 << 2) // 000
#define _CHARACTER_TYPE_BORDER                          (0x01 << 2) // 001
#define _CHARACTER_TYPE_LEFTTOP                         (0x04 << 2) // 100
#define _CHARACTER_TYPE_LEFTBOTTOM                      (0x05 << 2) // 101
#define _CHARACTER_TYPE_RIGHTTOP                        (0x06 << 2) // 110
#define _CHARACTER_TYPE_RIGHTBOTTOM                     (0x07 << 2) // 111

// Row Command Byte0 Bit[1:0]
#define _DOUBLE_CHAR_WIDTH_X1                           (0x00 << 1)
#define _DOUBLE_CHAR_WIDTH_X2                           (0x01 << 1)

#define _DOUBLE_CHAR_HEIGHT_X1                          0x00
#define _DOUBLE_CHAR_HEIGHT_X2                          0x01

// Row Command Byte1 Bit[7:3]
#define ROWHEIGHT(x)                                    (((x - 1) & 0x1f) << 3)
// Row Command Byte2 Bit[7:0]
#define ROWLENGTH(x)                                    x
// Row Command Byte1 Bit[2:0]
#define COLSPACE(x)                                     (x & 0x07)

#define _DIAPLAYZONE_MIDDLE                             0x00 // 00
#define _DIAPLAYZONE_LEFT                               0x01 // 01
#define _DIAPLAYZONE_RIGHT                              0x02 // 10
#define _DIAPLAYZONE_RESERVED                           0x03 // 11

#define _ROLL_UP_FUNCTION                               0x00
#define _POP_ON_FUNCTION                                0x01
#define _BASE0_SELECT                                   0x00
#define _BASE1_SELECT                                   0x01

#define  _1BIT_TYPE1            (((0x00 & 0x04) << 5) | ((0x00 & 0x03) << 4)) // 000 color: 16-31 font: 0-255
#define  _1BIT_TYPE2            (((0x01 & 0x04) << 5) | ((0x01 & 0x03) << 4)) // blank
#define  _1BIT_TYPE3            (((0x02 & 0x04) << 5) | ((0x02 & 0x03) << 4)) // 010 color: 0-15 font: 256-511
#define  _1BIT_TYPE4            (((0x03 & 0x04) << 5) | ((0x03 & 0x03) << 4)) // 011 color: 16-31 font: 256-511
#define  _1BIT_TYPE5            (((0x04 & 0x04) << 5) | ((0x04 & 0x03) << 4)) // 100 color: 0-15 font: 0-255 
#define  _1BIT_TYPE6            (((0x01 & 0x04) << 5) | ((0x01 & 0x03) << 4)) | 0x01 // align function

#define  _4BIT_TYPE             (((0x05 & 0x04) << 5) | ((0x05 & 0x03) << 4)) // 101 color: 0-63 font: 0-255
#define  _2BIT_TYPE1            (((0x06 & 0x04) << 5) | ((0x06 & 0x03) << 4)) // 110 color: 0-15 font: 0-254
#define  _2BIT_TYPE2            (((0x07 & 0x04) << 5) | ((0x07 & 0x03) << 4)) // 111 color: 16-31 font: 0-254

// 1 bit font
#define _NO_BLINK_FORFB         (((0x00 & 0x02) << 5) | ((0x00 & 0x01) << 2)) // bit6/2 00
#define _ONLY_BLINK_FORF        (((0x01 & 0x02) << 5) | ((0x01 & 0x01) << 2)) // bit6/2 01
#define _ONLY_BLINK_FORB        (((0x02 & 0x02) << 5) | ((0x02 & 0x01) << 2)) // bit6/2 10
#define _BOTH_BLINK_FORB        (((0x03 & 0x02) << 5) | ((0x03 & 0x01) << 2)) // bit6/2 11
#define _UNDERLINE_ENABLE       (0x01 << 1)

#define  CHAR_WIDTH(x)          (x)
#define  CHARSELECT(x)          (x)
#define  COLORSELECT(x, y)      (((x & 0x0f) << 4) | (y & 0x0f))

// blank color
#define  BLANKCOLOR(x)          (x & 0x3f)

// 4 bit font
#define  FOURBITBGCOLOR(x)      (x & 0x0f)
#define  _4BIT_BLINKING_ENABLE  (0x01 << 6)

//--------------------------------------------------
// Description  : Load OSD NOMAL FONTDATA_TABLE1
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDNOMALFONTDATA_TABLE1[] =
{
    // 0x403
    0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,     // map of "A",     // FONT 0    	    	    	    	    	    
    0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
        	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,     // map of "n",  // FONT 1
    0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,    	    	    	    	    	    	    
    0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
        	    	    	    	    
    0x0c, 0x00, 0x00, 0x0c, 0xc0, 0x00, 0x0c, 0xc0, 0x00,     // map of "d",  // FONT 2
    0xfc, 0xc3, 0x1e, 0x0c, 0xc6, 0x31, 0x0c, 0xc6, 0x60,    	    	    	    	    	    	    
    0x1c, 0xc7, 0x60, 0xec, 0xc1, 0x3f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x81, 0x0f,     // map of "e",  // FONT 3    	    	    	    	    	    	
    0x1c, 0xc3, 0x38, 0xf0, 0x83, 0x33, 0x84, 0x03, 0x3c,    	    	    	    	    	    	    
    0xf0, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x83, 0x33,     // map of "r",  // FONT 4    	    	    	    	    	    	
    0x18, 0x83, 0x39, 0x00, 0x03, 0x30, 0x00, 0x03, 0x30,    	    	    	    	    	    	    
    0x00, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x81, 0x03,     // map of "s",  // FONT 5    	    	    	    	    	    	    
    0x00, 0x83, 0x39, 0xf0, 0x00, 0x3e, 0x18, 0x82, 0x01,    	    	    	    	    	    	    
    0xf0, 0x81, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
        	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0x0f,     // map of "o",  // FONT 6    
    0x0c, 0xc3, 0x19, 0x0c, 0xc3, 0x30, 0x98, 0xc3, 0x30,    	    	    	    	    	    	    
    0xf0, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
        	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,     // map of "n",  // FONT 7    	    	    	    	    	    
    0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,    	    	    	    	    	    	    
    0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x14, 0xc5, 0x60,     // map of "M" 2-bit,  // FONT 8,9(4) 
    0x14, 0x45, 0x51, 0xa4, 0x44, 0x4a, 0x04, 0x44, 0x40,    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x0e, 0x4e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0xa0, 0x00, 0x0a, 0x00, 0x00, 0x04,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x14, 0xc5, 0x60,     // map of "M" 2-bit,  // FONT 10,11(5)     	    	    	    	    	    
    0x14, 0x45, 0x51, 0xa4, 0x44, 0x4a, 0x04, 0x44, 0x44,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x0e, 0x4e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     // map of "-" 2-bit,  // FONT 12,13(6)    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x40, 0x35, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    

    0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x04, 0x81, 0x10,     // map of "P" 2-bit,  // FONT 14,15(7)    	    	    	    	    	    	
    0x04, 0x41, 0x10, 0xf0, 0x81, 0x10, 0x00, 0x01, 0x10,    	    	    	    	    	    	    
    0xe0, 0x07, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    

    0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x08, 0x82, 0x20,     // map of "D" 2-bit,  // FONT 16,17(8)    	    	    	    	    	    	
    0x04, 0x42, 0x20, 0x04, 0x42, 0x20, 0x08, 0x42, 0x20,    	    	    	    	    	    	    
    0xf0, 0x87, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x08, 0x82, 0x20,     // map of "D" 2-bit,  // FONT 18,19(9)    	    	    	    	    	    	
    0x04, 0x42, 0x20, 0x04, 0x42, 0x20, 0x08, 0x42, 0x20,    	    	    	    	    	    	    
    0xf0, 0x87, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x40, 0x00, 0x34,     // map of "1" 2-bit,  // FONT 20,21(10)    	    	    	    	    	    	    
    0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04,    	    	    	    	    	    	    
    0x40, 0x00, 0x04, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     // map of "-" 2-bit,  // FONT 22,23(11)    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x40, 0x35, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    

    0x00, 0x00, 0x00, 0xe8, 0x00, 0x00, 0x08, 0x82, 0x11,     // map of "S" 2-bit,  // FONT 24,25(12)    	    	    	    	    	    
    0x00, 0x03, 0x20, 0x18, 0x00, 0x0e, 0x08, 0x82, 0x00,    	    	    	    	    	    	    
    0xe0, 0x02, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
            	    	    	    
    0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x08, 0x82, 0x20,     // map of "D" 2-bit,  // FONT 26,27(13)    	    	    	    	    	    	
    0x04, 0x42, 0x20, 0x04, 0x42, 0x20, 0x08, 0x42, 0x20,    	    	    	    	    	    	    
    0xf0, 0x87, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    

    0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x02, 0x00,     // test font "E" 4-bit,  //  FONT 28,29,30,31(7)    	    	    	    	    	    	
    0x00, 0x02, 0x00, 0x00, 0x02, 0x1e, 0x00, 0x02, 0x00,    	    	    	    	    	    	    
    0x00, 0x03, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x02, 0x20, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x20,    	    	    	    	    	    	    
    0x00, 0x02, 0x20, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x01, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00,    	    

    0x00, 0x00, 0x00, 0x18, 0x82, 0x20, 0x10, 0x01, 0x31,     // test font "X" 4-bit,  //  FONT 32,33,34,35(8)    	    	    	    	    	    
    0xa0, 0x00, 0x1b, 0x60, 0x00, 0x0e, 0xb0, 0x00, 0x0e,    	    	    	    	    	    	    
    0x0c, 0x81, 0x19, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,     // test font "T" 4-bit,  //  FONT 36,37,38,39(9)    	    	    	    	    	    	    	
    0x40, 0x00, 0x04, 0x60, 0x00, 0x04, 0x60, 0x00, 0x06,    	    	    	    	    	    	    
    0x20, 0x00, 0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0xc0, 0x31, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     // test font ":" 4-bit,  //  FONT 40,41,42,43(10)    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x0e,    	    	    	    	    	    	    
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x0e,    	    	    	    	    	    	    
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x04,    	    	    	    	    	    	    
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
         
    0x00, 0x00, 0x00, 0x0c, 0x03, 0x10, 0x00, 0x02, 0x20,     // test font "5" 4-bit,  //  FONT 44,45,46,47(11)    	    	    	    	    	    	    	
    0x00, 0x02, 0x20, 0x00, 0x03, 0x20, 0x00, 0x00, 0x01,    	    	    	    	    	    	    
    0x10, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0xfc, 0x03, 0x10, 0x00, 0x02, 0x20,    	    	    	    	    	    	    
    0x00, 0x02, 0x20, 0x00, 0x00, 0x20, 0x08, 0x80, 0x00,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0xfc, 0x03, 0x10, 0x00, 0x02, 0x20,    	    	    	    	    	    	    
    0x00, 0x02, 0x20, 0xf0, 0x00, 0x20, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,    	    	    	    	    	    	    
    0x00, 0x02, 0x20, 0xf0, 0x00, 0x20, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,     // test font "4" 4-bit,  //  FONT 48,49,50,51(12)    	    	    	    	    	    	    
    0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20,    	    	    	    	    	    	    
    0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x01, 0x10,    	    	    	    	    	    	    
    0x18, 0x00, 0x00, 0x00, 0x80, 0x01, 0x1c, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x01, 0x10,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x01,    	    	    	    	    	    	    
    0x10, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0x0c, 0x83, 0x0f, 0x08, 0x40, 0x20,     // test font "2" 4-bit,  //  FONT 52,53,54,55(13)    	    	    	    	    	    	    	    	
    0x18, 0x80, 0x00, 0x30, 0x00, 0x01, 0x60, 0x00, 0x02,    	    	    	    	    	    	    
    0xc0, 0x00, 0x04, 0x00, 0x80, 0x0f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	

    0x00, 0x00, 0x00, 0x0c, 0x80, 0x01, 0x04, 0x40, 0x00,     // test font "3" 4-bit,  //  FONT 56,57,58,59(14)    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x0c, 0x80, 0x0f, 0x04, 0x40, 0x00,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x20,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x30, 0x00, 0x01, 0x18, 0x00, 0x01,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,
};

//--------------------------------------------------
// Description  : Load OSD NOMAL FONTDATA_TABLE2
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDNOMALFONTDATA_TANLE2[] =
{
    // 0xD03
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,     // map of "n",  // FONT 256
    0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,    	    	    	    	    	    	    
    0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    
};

//--------------------------------------------------
// Description  : Load OSD NOMAL FONTDATA_TABLE3
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDNOMALFONTDATA_TANLE3[] = 
{
    // 0x1213
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0x0f,     // map of "o",  // FONT 400    
    0x0c, 0xc3, 0x19, 0x0c, 0xc3, 0x30, 0x98, 0xc3, 0x30,    	    	    	    	    	    	    
    0xf0, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,       
};

//--------------------------------------------------
// Description  : Load OSD NOMAL FONTDATA_TABLE4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDNOMALFONTDATA_TANLE4[] = 
{
    // 0x191b
    0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,     // map of "A",     // FONT 600    	    	    	    	    	    
    0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,   
};

//--------------------------------------------------
// Description  : Row command for OsdTestFrame6
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDROWMAPAPPLY_FRAME6[] =
{
    0x83, 0xF0, 0x04,  // row 0, h*1 = 30,  w*2, no effect , col space = 0, length = 4
    0x80, 0xF0, 0x05,  // row 0, h*1 = 30,  w*1, no effect , col space = 0, length = 5
    0x00, 0x00, 0x00,  // end, no font
};

//--------------------------------------------------
// Description  : Character command for OsdTestFrame6
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDCHARACTERCOMMAND_FRAME6[] =
{
    // row 0, 4 font
    0x8f, 0x01, 0x23, 
    0x8e, 0x02, 0xe5, 
    0x8d, 0x03, 0x17, 
    0x8c, 0x04, 0x8f,  

        // row 1, 5 font
    0x8f, 0x06, 0x32, // 1-bit font
    0x8e, 0x05, 0x5e, // 1-bit font
    0x9f, 0x02, 0x67, // 4- bit font 
    0x8c, 0x06, 0xf8, // 1- bit font
    0xA1, 0x00, 0x67, // 2- bit font
};

//--------------------------------------------------
// Description  : Load OSD WVLCCOMPRESSED_TABLE
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDHWVLCCOMPRESSED_TABLE[] =
{
    // vlc code
    0x01,0x8c,0x3f,0x67,0xe4,0x92,0xbd,0x5a,
    // font data  // font map " ABCD"  //  " ABCD" 9*5= 45 = 0x2D (have a blank)
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0xb6,0x72,
    0xe9,0x4e,0xe8,0x4e,0x5c,0xdd,0x27,0xa3,0x3b,0xe1,0xea,0xfd,
    0xb2,0xcf,0xac,0x02,0x80,0xa7,0xdd,0xb3,0xaa,0x3b,0x4f,0xad,
    0xae,0xa4,0x6a,0x76,0x52,0x35,0x93,0x94,0x7b,0x56,0x6a,0x29,
    0x53,0x00,0xf0,0x2c,0x71,0xb0,0x37,0x74,0x43,0x37,0x74,0x73,
    0xbf,0x67,0x5b,0xca,0x14,0x00,0xd4,0x55,0x7b,0x56,0xcd,0xc9,
    0x53,0x95,0x24,0x55,0x49,0x52,0x95,0x24,0xe5,0x7e,0x4f,0x6a,
    0x29,0x9f,0x02,0xfe,0xff,   
};

//--------------------------------------------------
// Description  : Load OSD NOMAL FONTDATA_TABLE6
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDNOMALFONTDATA_TANLE6[]=
{
    0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,     // map of "A",  // FONT 5    	    	    	    	    	    
    0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
            	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,     // map of "n" ,  // FONT 6
    0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,    	    	    	    	    	    	    
    0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x81, 0x03,     // map of "s",  // FONT 7    	    	    	    	    	    	    
    0x00, 0x83, 0x39, 0xf0, 0x00, 0x3e, 0x18, 0x82, 0x01,    	    	    	    	    	    	    
    0xf0, 0x81, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x0c, 0x80, 0x01, 0x04, 0x40, 0x00,     //  FONT 8,9,10,11(3)    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x0c, 0x80, 0x0f, 0x04, 0x40, 0x00,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x20,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x30, 0x00, 0x01, 0x18, 0x00, 0x01,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,    
};

//--------------------------------------------------
// Description  : Load OSD NOMAL FONTDATA_TABLE2 for frame6
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDNOMALFONTDATA_TANLE2_FRAME6[]=
{
    // font base address = 0x400, 0x88*9*2 = 2448 = 0x990,0x990 +0x400 = 0xD90, 
    0x00, 0x00, 0x00, 0x80, 0x0d, 0x30, 0xc0, 0x00, 0x18,     // map of "X" 2-bit,
    0x73, 0x00, 0x0c, 0x30, 0xec, 0x3f, 0x18, 0x80, 0x03,    
    0x0d, 0xc0, 0x00, 0x06, 0x70, 0x00, 0x00, 0x00, 0x00,    
    0x00, 0x00, 0x00, 0xb6, 0xfd, 0x30, 0xc8, 0xc0, 0x18,    
    0x70, 0x00, 0x0d, 0xb0, 0x00, 0x07, 0x18, 0x81, 0x13,    
    0x0d, 0xc7, 0x20, 0xc6, 0x73, 0xf8, 0x00, 0x00, 0x00,    
};

//--------------------------------------------------
// Description  : OSD Font Width table
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_FONT_WIDTH[]=
{
    11, 7, 4, 10, 10, 10, 10,
};

//--------------------------------------------------
// Description  : Load OSD Font Table for recorder
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_FONT_DATA[]=        
{
    // ========Address -- (00),
    0x00,0x00,0x00,
    0x07,0x0f,0x08,
    0x76,0xf0,0xcc,
    0x66,0x00,0xcc,
    0x77,0xff,0x8c,
    0x66,0x00,0xe6,
    0x67,0x0f,0x6c,
    0x70,0xf0,0x80,
    0x00,0x00,0x00,
    
    // ========Address -- (01),
    0x80,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x33,0x6e,0x00,
    0x33,0x80,0x00,
    0x33,0x00,0x00,
    0x33,0x00,0x00,
    0x30,0x00,0x00,
    0x00,0x00,0x00,
    
    // ========Address -- (02),
    0x00,0x00,0x00,
    0x03,0x00,0x00,
    0x30,0x00,0x00,
    0x33,0x00,0x00,
    0x33,0x00,0x00,
    0x33,0x00,0x00,
    0x33,0x00,0x00,
    0x30,0x00,0x00,
    0x00,0x00,0x00,
    
    // ========Address -- (03),
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x13,0xff,0x08,
    0x30,0x17,0x88,
    0x13,0xf9,0x88,
    0x33,0x1f,0x88,
    0x10,0xe0,0xc0,
    0x00,0x00,0x00,
    
    // ========Address -- (04),
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x33,0x7f,0x8c,
    0x33,0x80,0xcc,
    0x33,0x00,0xcc,
    0x33,0x00,0xcc,
    0x30,0x00,0xc0,
    0x00,0x00,0x00,
    
    // ========Address -- (05),
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x33,0x7f,0x8c,
    0x33,0x80,0xcc,
    0x33,0x00,0xcc,
    0x33,0x00,0xcc,
    0x30,0x00,0xc0,
    0x00,0x00,0x00,
    
    // ========Address -- (06),
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x13,0xff,0x08,
    0x30,0x17,0x88,
    0x13,0xf9,0x88,
    0x33,0x1f,0x88,
    0x10,0xe0,0xc0,
    0x00,0x00,0x00,
};    

//**************************Define of Window Style*******************************/
#define WINNO(x) (x)
#define COLOR00(x)                                  (x)
#define COLOR01(x)                                  (x)
#define COLOR10(x)                                  (x)
#define COLOR11(x)                                  (x)
#define _WIN_SHADOW_TYPE1                           0x00
#define _WIN_SHADOW_TYPE2                           0x01
#define _WIN_SHADOW_TYPE3                           0x02
#define _WIN_SHADOW_TYPE4                           0x03
#define _WIN_3DBUTTON_TYPE1                         0x04
#define _WIN_3DBUTTON_TYPE2                         0x05
#define _WIN_RESEVERD                               0x06
#define _WIN_BORDER                                 0x07


//----------------------Window 0--------------------------------------
// 0x103h Byte0 Bit[5] + 0x103h Byte1 Bit[4:0]
#define _WIN0_COLOR                                 0x04

//----------------------window type-----------------------------------
#define _WIN0_STYLE                                 _WIN_BORDER

#define _WIN0_SHADOW_COLOR                          0x1f       // 3f
#define _WIN0_BORDER_COLOR                          0x01
#define _WIN0_SHADOW_WIDTH                          0x07      // 000-111
#define _WIN0_SHADOW_HEIGHT                         0x07      // 000-111
#define _WIN0_SHADOW_ENABLE                         0x01

//----------------------grident function------------------------------
#define _WIN0_R_GRIDENT_POLARITY                    0x01      // 0: decrease, 1: increase
#define _WIN0_G_GRIDENT_POLARITY                    0x01      // 0: decrease, 1: increase
#define _WIN0_B_GRIDENT_POLARITY                    0x01      // 0: decrease, 1: increase
#define _WIN0_GRIDENT_LEVEL                         0x03      // 00-11: 1-4

#define _WIN0_R_GRIDENT_ENABLE                      0x01
#define _WIN0_G_GRIDENT_ENABLE                      0x01
#define _WIN0_B_GRIDENT_ENABLE                      0x01

#define _WIN0_PERGRADIENT_LEVEL                     0x00     // 000-111
#define _WIN0_GRIDENT_ENABLE                        0x01
#define _WIN0_GRIDENT_DIRECTION                     0x00

#define _WIN0_STATURATED_ENABLE                     0x01
#define _WIN0_REVERSEDCOLORMODE_ENABLE              0x01

//--------------------------------------------------
// Description  : OSD window0 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN0_STYLE[] =
{
     // window0 Address:0x100/0x103
     WINNO(0),
    // 100h-byte0  
    ((_WIN0_SHADOW_COLOR & 0x10) << 3) | ((_WIN0_BORDER_COLOR & 0x10) << 2) | ((_WIN0_SHADOW_WIDTH & 0x07) << 3) | (_WIN0_SHADOW_HEIGHT & 0x07),
    // 100h-byte1
    ((_WIN0_SHADOW_COLOR & 0x0f) << 4) | (_WIN0_BORDER_COLOR & 0x0f),
    // 100h-byte2
    ((_WIN0_R_GRIDENT_POLARITY & 0x01) << 7) | ((_WIN0_G_GRIDENT_POLARITY & 0x01) << 6) | ((_WIN0_B_GRIDENT_POLARITY & 0x01) << 5) | 
    ((_WIN0_GRIDENT_LEVEL & 0x07) << 3) | ((_WIN0_R_GRIDENT_ENABLE & 0x01) << 2) | ((_WIN0_G_GRIDENT_ENABLE & 0x01) << 1) | (_WIN0_B_GRIDENT_ENABLE & 0x01),

    // 103h-byte0 
    ((_WIN0_SHADOW_COLOR & 0x20) << 2) | ((_WIN0_BORDER_COLOR & 0x20) << 1) | (_WIN0_COLOR & 0x20) | ((_WIN0_STATURATED_ENABLE & 0x01) << 4) | ((_WIN0_REVERSEDCOLORMODE_ENABLE & 0x01) << 3)|0x04,
    // 103h-byte1
    ((_WIN0_PERGRADIENT_LEVEL & 0x07) << 5) | (_WIN0_COLOR & 0x1F),
    // 103h-bye2
    ((_WIN0_GRIDENT_ENABLE & 0x01) << 6) | ((_WIN0_GRIDENT_DIRECTION & 0x01) << 5) | ((_WIN0_SHADOW_ENABLE & 0x01) << 4) | ((_WIN0_STYLE & 0x07) << 1) | 0x01,
};


//----------------------Window 1--------------------------------------
#define _WIN1_COLOR                      0x22

//----------------------Window type-----------------------------------
#define _WIN1_STYLE                      _WIN_SHADOW_TYPE2

#define _WIN1_SHADOW_COLOR               0x3d
#define _WIN1_BORDER_COLOR               0x3c
#define _WIN1_SHADOW_WIDTH               0x00      // 000-111
#define _WIN1_SHADOW_HEIGHT              0x07      // 000-111
#define _WIN1_SHADOW_ENABLE              0x01

//----------------------Window 1 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window1 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN1_STYLE[] =
{

    WINNO(1), 
    //0x104h,Byte0/Byte1/Byte2
    ((_WIN1_SHADOW_COLOR & 0x10) << 3) | ((_WIN1_BORDER_COLOR & 0x10) << 2) | ((_WIN1_SHADOW_WIDTH & 0x07) << 3) | (_WIN1_SHADOW_HEIGHT & 0x07),
    ((_WIN1_SHADOW_COLOR & 0x0f) << 4) | (_WIN1_BORDER_COLOR & 0x0f),
    0x00,
    //window 0x107h,Byte0/Byte1/Byte2
    ((_WIN1_SHADOW_COLOR & 0x20) << 2) | ((_WIN1_BORDER_COLOR & 0x20) << 1) | (_WIN1_COLOR & 0x20)|0x04,
    (_WIN1_COLOR & 0x1F),
    ((_WIN1_SHADOW_ENABLE & 0x01) << 4) | ((_WIN1_STYLE & 0x07) << 1) | 0x01,
};
  
//--------------------------------------------------------------------

//----------------------Window 2--------------------------------------
#define _WIN2_COLOR                      0x23

//----------------------Window type-----------------------------------
#define _WIN2_STYLE                      _WIN_SHADOW_TYPE3

#define _WIN2_SHADOW_COLOR               0x3b
#define _WIN2_BORDER_COLOR               0x3a
#define _WIN2_SHADOW_WIDTH               0x01      // 000-111
#define _WIN2_SHADOW_HEIGHT              0x06      // 000-111
#define _WIN2_SHADOW_ENABLE              0x01

//----------------------Window 2 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window2 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN2_STYLE[] =
{
    WINNO(2),
    
    ((_WIN2_SHADOW_COLOR & 0x10) << 3) | ((_WIN2_BORDER_COLOR & 0x10) << 2) | ((_WIN2_SHADOW_WIDTH & 0x07) << 3) | (_WIN2_SHADOW_HEIGHT & 0x07),
    ((_WIN2_SHADOW_COLOR & 0x0f) << 4) | (_WIN2_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN2_SHADOW_COLOR & 0x20) << 2) | ((_WIN2_BORDER_COLOR & 0x20) << 1) | (_WIN2_COLOR & 0x20),
    (_WIN2_COLOR & 0x1F),
    ((_WIN2_SHADOW_ENABLE & 0x01) << 4) | ((_WIN2_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 3--------------------------------------
#define _WIN3_COLOR                      0x24

//----------------------Window type-----------------------------------
#define _WIN3_STYLE                      _WIN_SHADOW_TYPE4

#define _WIN3_SHADOW_COLOR               0x39
#define _WIN3_BORDER_COLOR               0x38
#define _WIN3_SHADOW_WIDTH               0x02      // 000-111
#define _WIN3_SHADOW_HEIGHT              0x05      // 000-111
#define _WIN3_SHADOW_ENABLE              0x01

//----------------------Window 3 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window3 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN3_STYLE[] =
{
    WINNO(3),
    
    ((_WIN3_SHADOW_COLOR & 0x10) << 3) | ((_WIN3_BORDER_COLOR & 0x10) << 2) | ((_WIN3_SHADOW_WIDTH & 0x07) << 3) | (_WIN3_SHADOW_HEIGHT & 0x07),
    ((_WIN3_SHADOW_COLOR & 0x0f) << 4) | (_WIN3_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN3_SHADOW_COLOR & 0x20) << 2) | ((_WIN3_BORDER_COLOR & 0x20) << 1) | (_WIN3_COLOR & 0x20),
    (_WIN3_COLOR & 0x1F),
    ((_WIN3_SHADOW_ENABLE & 0x01) << 4) | ((_WIN3_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 4--------------------------------------
#define _WIN4_COLOR                      0x25

//----------------------Window type-----------------------------------
#define _WIN4_STYLE                      _WIN_3DBUTTON_TYPE1

#define _WIN4_SHADOW_COLOR               0x37
#define _WIN4_BORDER_COLOR               0x36
#define _WIN4_SHADOW_WIDTH               0x05      // 000-111
#define _WIN4_SHADOW_HEIGHT              0x04      // 000-111
#define _WIN4_SHADOW_ENABLE              0x01

//----------------------Window 4 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window4 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN4_STYLE[] =
{
    WINNO(4),
    
    ((_WIN4_SHADOW_COLOR & 0x10) << 3) | ((_WIN4_BORDER_COLOR & 0x10) << 2) | ((_WIN4_SHADOW_WIDTH & 0x07) << 3) | (_WIN4_SHADOW_HEIGHT & 0x07),
    ((_WIN4_SHADOW_COLOR & 0x0f) << 4) | (_WIN4_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN4_SHADOW_COLOR & 0x20) << 2) | ((_WIN4_BORDER_COLOR & 0x20) << 1) | (_WIN4_COLOR & 0x20),
    (_WIN4_COLOR & 0x1F),
    ((_WIN4_SHADOW_ENABLE & 0x01) << 4) | ((_WIN4_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 5--------------------------------------
#define _WIN5_COLOR                   0x26

//----------------------Window type-----------------------------------
#define _WIN5_STYLE                   _WIN_3DBUTTON_TYPE2

#define _WIN5_SHADOW_COLOR            0x35
#define _WIN5_BORDER_COLOR            0x34
#define _WIN5_SHADOW_WIDTH            0x04      // 000-111
#define _WIN5_SHADOW_HEIGHT           0x04      // 000-111
#define _WIN5_SHADOW_ENABLE           0x01

//----------------------Grident function------------------------------
#define _WIN5_R_GRIDENT_POLARITY      0x01      // 0: decrease, 1: increase
#define _WIN5_G_GRIDENT_POLARITY      0x00      // 0: decrease, 1: increase
#define _WIN5_B_GRIDENT_POLARITY      0x01      // 0: decrease, 1: increase
#define _WIN5_GRIDENT_LEVEL           0x01      // 00-11: 1-4

#define _WIN5_R_GRIDENT_ENABLE        0x01
#define _WIN5_G_GRIDENT_ENABLE        0x01
#define _WIN5_B_GRIDENT_ENABLE        0x01

#define _WIN5_PERGRADIENT_LEVEL       0x02     // 000-111
#define _WIN5_GRIDENT_ENABLE          0x01
#define _WIN5_GRIDENT_DIRECTION       0x01

#define _WIN5_STATURATED_ENABLE          0x00
#define _WIN5_REVERSEDCOLORMODE_ENABLE   0x00

//--------------------------------------------------
// Description  : OSD window5 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN5_STYLE[] =
{
    WINNO(5),

    ((_WIN5_SHADOW_COLOR & 0x10) << 3) | ((_WIN5_BORDER_COLOR & 0x10) << 2) | ((_WIN5_SHADOW_WIDTH & 0x07) << 3) | (_WIN5_SHADOW_HEIGHT & 0x07),
    ((_WIN5_SHADOW_COLOR & 0x0f) << 4) | (_WIN5_BORDER_COLOR & 0x0f),
    ((_WIN5_R_GRIDENT_POLARITY & 0x01) << 7) | ((_WIN5_G_GRIDENT_POLARITY & 0x01) << 6) | ((_WIN5_B_GRIDENT_POLARITY & 0x01) << 5) | 
    ((_WIN5_GRIDENT_LEVEL & 0x07) << 3) | ((_WIN5_R_GRIDENT_ENABLE & 0x01) << 2) | ((_WIN5_G_GRIDENT_ENABLE & 0x01) << 1) | (_WIN5_B_GRIDENT_ENABLE & 0x01),

    ((_WIN5_SHADOW_COLOR & 0x20) << 2) | ((_WIN5_BORDER_COLOR & 0x20) << 1) | (_WIN5_COLOR & 0x20) | ((_WIN5_STATURATED_ENABLE & 0x01) << 4) | ((_WIN5_REVERSEDCOLORMODE_ENABLE & 0x01) << 3),
    ((_WIN5_PERGRADIENT_LEVEL & 0x07) << 5) | (_WIN5_COLOR & 0x1F),
    ((_WIN5_GRIDENT_ENABLE & 0x01) << 6) | ((_WIN5_GRIDENT_DIRECTION & 0x01) << 5) | ((_WIN5_SHADOW_ENABLE & 0x01) << 4) | ((_WIN5_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 6--------------------------------------
#define _WIN6_COLOR                   0x27

//----------------------Window type-----------------------------------
#define _WIN6_STYLE                   _WIN_BORDER

#define _WIN6_SHADOW_COLOR            0x33
#define _WIN6_BORDER_COLOR            0x32
#define _WIN6_SHADOW_WIDTH            0x02      // 000-111
#define _WIN6_SHADOW_HEIGHT           0x02      // 000-111
#define _WIN6_SHADOW_ENABLE           0x01

//----------------------Grident function------------------------------
#define _WIN6_R_GRIDENT_POLARITY      0x01      // 0: decrease, 1: increase
#define _WIN6_G_GRIDENT_POLARITY      0x00      // 0: decrease, 1: increase
#define _WIN6_B_GRIDENT_POLARITY      0x00      // 0: decrease, 1: increase
#define _WIN6_GRIDENT_LEVEL           0x00      // 00-11: 1-4

#define _WIN6_R_GRIDENT_ENABLE        0x01
#define _WIN6_G_GRIDENT_ENABLE        0x01
#define _WIN6_B_GRIDENT_ENABLE        0x01

#define _WIN6_PERGRADIENT_LEVEL       0x01     // 000-111
#define _WIN6_GRIDENT_ENABLE          0x01
#define _WIN6_GRIDENT_DIRECTION       0x00

#define _WIN6_STATURATED_ENABLE          0x01
#define _WIN6_REVERSEDCOLORMODE_ENABLE   0x01

//--------------------------------------------------
// Description  : OSD window6 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN6_STYLE[] =
{
    WINNO(6),

    ((_WIN6_SHADOW_COLOR & 0x10) << 3) | ((_WIN6_BORDER_COLOR & 0x10) << 2) | ((_WIN6_SHADOW_WIDTH & 0x07) << 3) | (_WIN6_SHADOW_HEIGHT & 0x07),
    ((_WIN6_SHADOW_COLOR & 0x0f) << 4) | (_WIN6_BORDER_COLOR & 0x0f),
    ((_WIN6_R_GRIDENT_POLARITY & 0x01) << 7) | ((_WIN6_G_GRIDENT_POLARITY & 0x01) << 6) | ((_WIN6_B_GRIDENT_POLARITY & 0x01) << 5) | 
    ((_WIN6_GRIDENT_LEVEL & 0x07) << 3) | ((_WIN6_R_GRIDENT_ENABLE & 0x01) << 2) | ((_WIN6_G_GRIDENT_ENABLE & 0x01) << 1) | (_WIN6_B_GRIDENT_ENABLE & 0x01),

    ((_WIN6_SHADOW_COLOR & 0x20) << 2) | ((_WIN6_BORDER_COLOR & 0x20) << 1) | (_WIN6_COLOR & 0x20) | ((_WIN6_STATURATED_ENABLE & 0x01) << 4) | ((_WIN6_REVERSEDCOLORMODE_ENABLE & 0x01) << 3),
    ((_WIN6_PERGRADIENT_LEVEL & 0x07) << 5) | (_WIN6_COLOR & 0x1F),
    ((_WIN6_GRIDENT_ENABLE & 0x01) << 6) | ((_WIN6_GRIDENT_DIRECTION & 0x01) << 5) | ((_WIN6_SHADOW_ENABLE & 0x01) << 4) | ((_WIN6_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 7--------------------------------------
#define _WIN7_COLOR                   0x28

//----------------------Window type-----------------------------------
#define _WIN7_STYLE                   _WIN_SHADOW_TYPE1

#define _WIN7_SHADOW_COLOR            0x31
#define _WIN7_BORDER_COLOR            0x30
#define _WIN7_SHADOW_WIDTH            0x06      // 000-111
#define _WIN7_SHADOW_HEIGHT           0x01      // 000-111
#define _WIN7_SHADOW_ENABLE           0x01

//----------------------Grident function------------------------------
#define _WIN7_R_GRIDENT_POLARITY      0x00      // 0: decrease, 1: increase
#define _WIN7_G_GRIDENT_POLARITY      0x01      // 0: decrease, 1: increase
#define _WIN7_B_GRIDENT_POLARITY      0x01      // 0: decrease, 1: increase
#define _WIN7_GRIDENT_LEVEL           0x00      // 00-11: 1-4

#define _WIN7_R_GRIDENT_ENABLE        0x01
#define _WIN7_G_GRIDENT_ENABLE        0x01
#define _WIN7_B_GRIDENT_ENABLE        0x01

#define _WIN7_PERGRADIENT_LEVEL       0x06     // 000-111
#define _WIN7_GRIDENT_ENABLE          0x01
#define _WIN7_GRIDENT_DIRECTION       0x01

#define _WIN7_STATURATED_ENABLE          0x01
#define _WIN7_REVERSEDCOLORMODE_ENABLE   0x01

//--------------------------------------------------
// Description  : OSD window7 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN7_STYLE[] =
{
    WINNO(7),

    ((_WIN7_SHADOW_COLOR & 0x10) << 3) | ((_WIN7_BORDER_COLOR & 0x10) << 2) | ((_WIN7_SHADOW_WIDTH & 0x07) << 3) | (_WIN7_SHADOW_HEIGHT & 0x07),
    ((_WIN7_SHADOW_COLOR & 0x0f) << 4) | (_WIN7_BORDER_COLOR & 0x0f),
    ((_WIN7_R_GRIDENT_POLARITY & 0x01) << 7) | ((_WIN7_G_GRIDENT_POLARITY & 0x01) << 6) | ((_WIN7_B_GRIDENT_POLARITY & 0x01) << 5) | 
    ((_WIN7_GRIDENT_LEVEL & 0x07) << 3) | ((_WIN7_R_GRIDENT_ENABLE & 0x01) << 2) | ((_WIN7_G_GRIDENT_ENABLE & 0x01) << 1) | (_WIN7_B_GRIDENT_ENABLE & 0x01),

    ((_WIN7_SHADOW_COLOR & 0x20) << 2) | ((_WIN7_BORDER_COLOR & 0x20) << 1) | (_WIN7_COLOR & 0x20) | ((_WIN7_STATURATED_ENABLE & 0x01) << 4) | ((_WIN7_REVERSEDCOLORMODE_ENABLE & 0x01) << 3),
    ((_WIN7_PERGRADIENT_LEVEL & 0x07) << 5) | (_WIN7_COLOR & 0x1F),
    ((_WIN7_GRIDENT_ENABLE & 0x01) << 6) | ((_WIN7_GRIDENT_DIRECTION & 0x01) << 5) | ((_WIN7_SHADOW_ENABLE & 0x01) << 4) | ((_WIN7_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 8--------------------------------------
#define _WIN8_COLOR                   0x29

//----------------------Window type-----------------------------------
#define _WIN8_STYLE                   _WIN_SHADOW_TYPE2

#define _WIN8_SHADOW_COLOR            0x25
#define _WIN8_BORDER_COLOR            0x27
#define _WIN8_SHADOW_WIDTH            0x07      // 000-111
#define _WIN8_SHADOW_HEIGHT           0x00      // 000-111
#define _WIN8_SHADOW_ENABLE           0x01

//----------------------Grident function------------------------------
#define _WIN8_R_GRIDENT_POLARITY      0x00      // 0: decrease, 1: increase
#define _WIN8_G_GRIDENT_POLARITY      0x01      // 0: decrease, 1: increase
#define _WIN8_B_GRIDENT_POLARITY      0x00      // 0: decrease, 1: increase
#define _WIN8_GRIDENT_LEVEL           0x02      // 00-11: 1-4

#define _WIN8_R_GRIDENT_ENABLE        0x01
#define _WIN8_G_GRIDENT_ENABLE        0x01
#define _WIN8_B_GRIDENT_ENABLE        0x01

#define _WIN8_PERGRADIENT_LEVEL       0x04     // 000-111
#define _WIN8_GRIDENT_ENABLE          0x01
#define _WIN8_GRIDENT_DIRECTION       0x00

#define _WIN8_STATURATED_ENABLE          0x01 // 0x00
#define _WIN8_REVERSEDCOLORMODE_ENABLE   0x01 // 0x00

//--------------------------------------------------
// Description  : OSD window8 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN8_STYLE[] =
{
    WINNO(8),

    ((_WIN8_SHADOW_COLOR & 0x10) << 3) | ((_WIN8_BORDER_COLOR & 0x10) << 2) | ((_WIN8_SHADOW_WIDTH & 0x07) << 3) | (_WIN8_SHADOW_HEIGHT & 0x07),
    ((_WIN8_SHADOW_COLOR & 0x0f) << 4) | (_WIN8_BORDER_COLOR & 0x0f),
    ((_WIN8_R_GRIDENT_POLARITY & 0x01) << 7) | ((_WIN8_G_GRIDENT_POLARITY & 0x01) << 6) | ((_WIN8_B_GRIDENT_POLARITY & 0x01) << 5) | 
    ((_WIN8_GRIDENT_LEVEL & 0x07) << 3) | ((_WIN8_R_GRIDENT_ENABLE & 0x01) << 2) | ((_WIN8_G_GRIDENT_ENABLE & 0x01) << 1) | (_WIN8_B_GRIDENT_ENABLE & 0x01),

    ((_WIN8_SHADOW_COLOR & 0x20) << 2) | ((_WIN8_BORDER_COLOR & 0x20) << 1) | (_WIN8_COLOR & 0x20) | ((_WIN8_STATURATED_ENABLE & 0x01) << 4) | ((_WIN8_REVERSEDCOLORMODE_ENABLE & 0x01) << 3),
    ((_WIN8_PERGRADIENT_LEVEL & 0x07) << 5) | (_WIN8_COLOR & 0x1F),
    ((_WIN8_GRIDENT_ENABLE & 0x01) << 6) | ((_WIN8_GRIDENT_DIRECTION & 0x01) << 5) | ((_WIN8_SHADOW_ENABLE & 0x01) << 4) | ((_WIN8_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 9--------------------------------------
#define _WIN9_COLOR                   0x2a

//----------------------Window type-----------------------------------
#define _WIN9_STYLE                   _WIN_SHADOW_TYPE3

#define _WIN9_SHADOW_COLOR            0x3d
#define _WIN9_BORDER_COLOR            0x3c
#define _WIN9_SHADOW_WIDTH            0x04      // 000-111
#define _WIN9_SHADOW_HEIGHT           0x03      // 000-111
#define _WIN9_Shadow_Enable           0x01

//----------------------Grident function------------------------------
#define _WIN9_R_GRIDENT_POLARITY      0x00      // 0: decrease, 1: increase
#define _WIN9_G_GRIDENT_POLARITY      0x00      // 0: decrease, 1: increase
#define _WIN9_B_GRIDENT_POLARITY      0x00      // 0: decrease, 1: increase
#define _WIN9_GRIDENT_LEVEL           0x02      // 00-11: 1-4

#define _WIN9_R_GRIDENT_ENABLE        0x01
#define _WIN9_G_GRIDENT_ENABLE        0x01
#define _WIN9_B_GRIDENT_ENABLE        0x01

#define _WIN9_PERGRADIENT_LEVEL       0x07     // 000-111
#define _WIN9_GRIDENT_ENABLE          0x01
#define _WIN9_GRIDENT_DIRECTION       0x01

#define _WIN9_STATURATED_ENABLE          0x01    // 0x00
#define _WIN9_REVERSEDCOLORMODE_ENABLE   0x01   // 0x00

//--------------------------------------------------
// Description  : OSD window9 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN9_STYLE[] =
{
    WINNO(9),

    ((_WIN9_SHADOW_COLOR & 0x10) << 3) | ((_WIN9_BORDER_COLOR & 0x10) << 2) | ((_WIN9_SHADOW_WIDTH & 0x07) << 3) | (_WIN9_SHADOW_HEIGHT & 0x07),
    ((_WIN9_SHADOW_COLOR & 0x0f) << 4) | (_WIN9_BORDER_COLOR & 0x0f),
    ((_WIN9_R_GRIDENT_POLARITY & 0x01) << 7) | ((_WIN9_G_GRIDENT_POLARITY & 0x01) << 6) | ((_WIN9_B_GRIDENT_POLARITY & 0x01) << 5) | 
    ((_WIN9_GRIDENT_LEVEL & 0x07) << 3) | ((_WIN9_R_GRIDENT_ENABLE & 0x01) << 2) | ((_WIN9_G_GRIDENT_ENABLE & 0x01) << 1) | (_WIN9_B_GRIDENT_ENABLE & 0x01),

    ((_WIN9_SHADOW_COLOR & 0x20) << 2) | ((_WIN9_BORDER_COLOR & 0x20) << 1) | (_WIN9_COLOR & 0x20) | ((_WIN9_STATURATED_ENABLE & 0x01) << 4) | ((_WIN9_REVERSEDCOLORMODE_ENABLE & 0x01) << 3),
    ((_WIN9_PERGRADIENT_LEVEL & 0x07) << 5) | (_WIN9_COLOR & 0x1F),
    ((_WIN9_GRIDENT_ENABLE & 0x01) << 6) | ((_WIN9_GRIDENT_DIRECTION & 0x01) << 5) | ((_WIN9_Shadow_Enable & 0x01) << 4) | ((_WIN9_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 4 - 1 --------------------------------------
#define _WIN41_COLOR                      0x00

//----------------------Window type-----------------------------------
#define _WIN41_STYLE                      _WIN_SHADOW_TYPE1

#define _WIN41_SHADOW_COLOR               0x3f
#define _WIN41_BORDER_COLOR               0x3f
#define _WIN41_SHADOW_WIDTH               0x07      // 000-111
#define _WIN41_SHADOW_HEIGHT              0x07      // 000-111
#define _WIN41_SHADOW_ENABLE              0x01

//----------------------Window 4-1 has no grident function--------------
//--------------------------------------------------
// Description  : OSD window4-1 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN41_STYLE[] =
{
    WINNO(1),
    
    ((_WIN41_SHADOW_COLOR & 0x10) << 3) | ((_WIN41_BORDER_COLOR & 0x10) << 2) | ((_WIN41_SHADOW_WIDTH & 0x07) << 3) | (_WIN41_SHADOW_HEIGHT & 0x07),
    ((_WIN41_SHADOW_COLOR & 0x0f) << 4) | (_WIN41_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN41_SHADOW_COLOR & 0x20) << 2) | ((_WIN41_BORDER_COLOR & 0x20) << 1) | (_WIN41_COLOR & 0x20),
    (_WIN41_COLOR & 0x1F),
    ((_WIN41_SHADOW_ENABLE & 0x01) << 4) | ((_WIN41_STYLE & 0x07) << 1) | 0x01,
};
    
//--------------------------------------------------------------------
//----------------------Window 4 - 2--------------------------------------
#define _WIN42_COLOR                      0x20

//----------------------Window type-----------------------------------
#define _WIN42_STYLE                      _WIN_SHADOW_TYPE2

#define _WIN42_SHADOW_COLOR               0x3e
#define _WIN42_BORDER_COLOR               0x30
#define _WIN42_SHADOW_WIDTH               0x07      // 000-111
#define _WIN42_SHADOW_HEIGHT              0x07      // 000-111
#define _WIN42_SHADOW_ENABLE              0x01

//----------------------Window 4-2 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window4-2 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN42_STYLE[] =
{
    WINNO(2),
    
    ((_WIN42_SHADOW_COLOR & 0x10) << 3) | ((_WIN42_BORDER_COLOR & 0x10) << 2) | ((_WIN42_SHADOW_WIDTH & 0x07) << 3) | (_WIN42_SHADOW_HEIGHT & 0x07),
    ((_WIN42_SHADOW_COLOR & 0x0f) << 4) | (_WIN42_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN42_SHADOW_COLOR & 0x20) << 2) | ((_WIN42_BORDER_COLOR & 0x20) << 1) | (_WIN42_COLOR & 0x20),
    (_WIN42_COLOR & 0x1F),
    ((_WIN42_SHADOW_ENABLE & 0x01) << 4) | ((_WIN42_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 4-3--------------------------------------
#define _WIN43_COLOR                      0x03

//----------------------Window type-----------------------------------
#define _WIN43_STYLE                      _WIN_SHADOW_TYPE3

#define _WIN43_SHADOW_COLOR               0x3d
#define _WIN43_BORDER_COLOR               0x20
#define _WIN43_SHADOW_WIDTH               0x07      // 000-111
#define _WIN43_SHADOW_HEIGHT              0x07      // 000-111
#define _WIN43_SHADOW_ENABLE              0x01

//----------------------Window 4 -3 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window4-3 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN43_STYLE[] =
{
    WINNO(3),
    
    ((_WIN43_SHADOW_COLOR & 0x10) << 3) | ((_WIN4_BORDER_COLOR & 0x10) << 2) | ((_WIN43_SHADOW_WIDTH & 0x07) << 3) | (_WIN43_SHADOW_HEIGHT & 0x07),
    ((_WIN43_SHADOW_COLOR & 0x0f) << 4) | (_WIN4_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN43_SHADOW_COLOR & 0x20) << 2) | ((_WIN43_BORDER_COLOR & 0x20) << 1) | (_WIN43_COLOR & 0x20),
    (_WIN43_COLOR & 0x1F),
    ((_WIN43_SHADOW_ENABLE & 0x01) << 4) | ((_WIN43_STYLE & 0x07) << 1) | 0x01,
};   


//--------------------------------------------------------------------
//----------------------Window 4 - 4--------------------------------------
#define _WIN44_COLOR                      0x0C

//----------------------Window type-----------------------------------
#define _WIN44_STYLE                      _WIN_SHADOW_TYPE4

#define _WIN44_SHADOW_COLOR               0x3C
#define _WIN44_BORDER_COLOR               0x20
#define _WIN44_SHADOW_WIDTH               0x05      // 000-111
#define _WIN44_SHADOW_HEIGHT              0x05      // 000-111
#define _WIN44_SHADOW_ENABLE              0x01

//----------------------Window 4-4 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window4-4 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN44_STYLE[] =
{
    WINNO(4),
    
    ((_WIN44_SHADOW_COLOR & 0x10) << 3) | ((_WIN44_BORDER_COLOR & 0x10) << 2) | ((_WIN44_SHADOW_WIDTH & 0x07) << 3) | (_WIN44_SHADOW_HEIGHT & 0x07),
    ((_WIN44_SHADOW_COLOR & 0x0f) << 4) | (_WIN44_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN44_SHADOW_COLOR & 0x20) << 2) | ((_WIN44_BORDER_COLOR & 0x20) << 1) | (_WIN44_COLOR & 0x20),
    (_WIN44_COLOR & 0x1F),
    ((_WIN44_SHADOW_ENABLE & 0x01) << 4) | ((_WIN44_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 4-5--------------------------------------
#define _WIN45_COLOR                      0x33

//----------------------Window type-----------------------------------
#define _WIN45_STYLE                      _WIN_3DBUTTON_TYPE1

#define _WIN45_SHADOW_COLOR               0x3f
#define _WIN45_BORDER_COLOR               0x00
#define _WIN45_SHADOW_WIDTH               0x05      // 000-111
#define _WIN45_SHADOW_HEIGHT              0x05      // 000-111
#define _WIN45_SHADOW_ENABLE              0x01

//----------------------Window 4-5 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window4-5 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN45_STYLE[] =
{
    WINNO(5),
    
    ((_WIN45_SHADOW_COLOR & 0x10) << 3) | ((_WIN45_BORDER_COLOR & 0x10) << 2) | ((_WIN45_SHADOW_WIDTH & 0x07) << 3) | (_WIN45_SHADOW_HEIGHT & 0x07),
    ((_WIN45_SHADOW_COLOR & 0x0f) << 4) | (_WIN45_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN45_SHADOW_COLOR & 0x20) << 2) | ((_WIN45_BORDER_COLOR & 0x20) << 1) | (_WIN45_COLOR & 0x20),
    (_WIN45_COLOR & 0x1F),
    ((_WIN45_SHADOW_ENABLE & 0x01) << 4) | ((_WIN45_STYLE & 0x07) << 1) | 0x01,
};
    

//--------------------------------------------------------------------
//----------------------Window 4 - 6--------------------------------------
#define _WIN46_COLOR                      0x3c

//----------------------Window type-----------------------------------
#define _WIN46_STYLE                      _WIN_3DBUTTON_TYPE2

#define _WIN46_SHADOW_COLOR               0x3f
#define _WIN46_BORDER_COLOR               0x00
#define _WIN46_SHADOW_WIDTH               0x04      // 000-111
#define _WIN46_SHADOW_HEIGHT              0x04      // 000-111
#define _WIN46_SHADOW_ENABLE              0x01

//----------------------Window 4 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window4-6 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN46_STYLE[] =
{
    WINNO(6),
    
    ((_WIN46_SHADOW_COLOR & 0x10) << 3) | ((_WIN46_BORDER_COLOR & 0x10) << 2) | ((_WIN46_SHADOW_WIDTH & 0x07) << 3) | (_WIN46_SHADOW_HEIGHT & 0x07),
    ((_WIN46_SHADOW_COLOR & 0x0f) << 4) | (_WIN46_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN46_SHADOW_COLOR & 0x20) << 2) | ((_WIN46_BORDER_COLOR & 0x20) << 1) | (_WIN46_COLOR & 0x20),
    (_WIN46_COLOR & 0x1F),
    ((_WIN46_SHADOW_ENABLE & 0x01) << 4) | ((_WIN46_STYLE & 0x07) << 1) | 0x01,
};
 
//--------------------------------------------------------------------
//----------------------Window 4 - 7--------------------------------------
#define _WIN47_COLOR                      0x00

//----------------------Window type-----------------------------------
#define _WIN47_STYLE                      _WIN_RESEVERD // (border)

#define _WIN47_SHADOW_COLOR               0x3f
#define _WIN47_BORDER_COLOR               0x3f
#define _WIN47_SHADOW_WIDTH               0x07      // 000-111
#define _WIN47_SHADOW_HEIGHT              0x07      // 000-111
#define _WIN47_SHADOW_ENABLE              0x01

//----------------------Window 4-7 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window4-7 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN47_STYLE[] =
{
    WINNO(7),
    
    ((_WIN47_SHADOW_COLOR & 0x10) << 3) | ((_WIN47_BORDER_COLOR & 0x10) << 2) | ((_WIN47_SHADOW_WIDTH & 0x07) << 3) | (_WIN47_SHADOW_HEIGHT & 0x07),
    ((_WIN47_SHADOW_COLOR & 0x0f) << 4) | (_WIN47_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN47_SHADOW_COLOR & 0x20) << 2) | ((_WIN47_BORDER_COLOR & 0x20) << 1) | (_WIN47_COLOR & 0x20),
    (_WIN47_COLOR & 0x1F),
    ((_WIN47_SHADOW_ENABLE & 0x01) << 4) | ((_WIN47_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 4 - 8--------------------------------------
#define _WIN48_COLOR                      0x3f

//----------------------Window type-----------------------------------
#define _WIN48_STYLE                      _WIN_BORDER

#define _WIN48_SHADOW_COLOR               0x00
#define _WIN48_BORDER_COLOR               0x00
#define _WIN48_SHADOW_WIDTH               0x03      // 000-111
#define _WIN48_SHADOW_HEIGHT              0x03      // 000-111
#define _WIN48_SHADOW_ENABLE              0x01

//----------------------Window 4 has no grident function--------------

//--------------------------------------------------
// Description  : OSD window4-8 style
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN48_STYLE[] =
{
    WINNO(8),
    
    ((_WIN48_SHADOW_COLOR & 0x10) << 3) | ((_WIN48_BORDER_COLOR & 0x10) << 2) | ((_WIN48_SHADOW_WIDTH & 0x07) << 3) | (_WIN48_SHADOW_HEIGHT & 0x07),
    ((_WIN48_SHADOW_COLOR & 0x0f) << 4) | (_WIN48_BORDER_COLOR & 0x0f),
    0x00,

    ((_WIN48_SHADOW_COLOR & 0x20) << 2) | ((_WIN48_BORDER_COLOR & 0x20) << 1) | (_WIN48_COLOR & 0x20),
    (_WIN48_COLOR & 0x1F),
    ((_WIN48_SHADOW_ENABLE & 0x01) << 4) | ((_WIN48_STYLE & 0x07) << 1) | 0x01,
};

//--------------------------------------------------
// Description  : Row command
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDROWMAPAPPLY[] =
{
    /* row 0*/   _ROW_START,                                                                           ROWHEIGHT(17),               ROWLENGTH(8),
    /* row 1*/   _ROW_START | _CHARACTER_TYPE_BORDER | _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2, ROWHEIGHT(19) | COLSPACE(7), ROWLENGTH(8),
    /* row 2*/   _ROW_START | _CHARACTER_TYPE_LEFTTOP,                                                 ROWHEIGHT(21) | COLSPACE(6), ROWLENGTH(8),
    /* row 3*/   _ROW_START | _CHARACTER_TYPE_LEFTBOTTOM,                                              ROWHEIGHT(23) | COLSPACE(5), ROWLENGTH(8),
    /* row 4*/   _ROW_START | _CHARACTER_TYPE_RIGHTTOP,                                                ROWHEIGHT(25) | COLSPACE(4), ROWLENGTH(8),
    /* row 5*/   _ROW_START | _CHARACTER_TYPE_RIGHTBOTTOM,                                             ROWHEIGHT(27) | COLSPACE(3), ROWLENGTH(8),
    /* row 6*/   _ROW_START | _CHARACTER_TYPE_NONE | _DOUBLE_CHAR_HEIGHT_X2 ,                          ROWHEIGHT(19) | COLSPACE(7), ROWLENGTH(8),
    /* row 7*/   _ROW_START,                                                                           ROWHEIGHT(17),               ROWLENGTH(4),
    /* row 8*/   _ROW_START | _1BITFONT_SELECT_512_1023,                                               ROWHEIGHT(17),               ROWLENGTH(4),
    /* row 9*/   _ROW_START | _VBI_ENABLE,                                                             ROWHEIGHT(17),               ROWLENGTH(4),
    /* row 10*/  _ROW_START | _VBI_ENABLE | _1BITFONT_SELECT_512_1023,                                 ROWHEIGHT(17),               ROWLENGTH(4), 
    /* row 11*/  _ROW_START,                                                                           ROWHEIGHT(17),               ROWLENGTH(3),
    /* row 12*/  _ROW_START,                                                                           ROWHEIGHT(19),               ROWLENGTH(6),
    
    /* row end*/ _ROW_END,                                                                             0x00,                        0x00,
}; 

//--------------------------------------------------
// Description  : Character command
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDCHARACTERCOMMAND_TABLE1[] =  // 3x8 = 24
{
    // row 0: 8 font 
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x00, 0x00),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x01), COLORSELECT(0x01, 0x02),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x02), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x03), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x04), COLORSELECT(0x07, 0x08),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x05), COLORSELECT(0x09, 0x0a),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x06), COLORSELECT(0x0b, 0x0c),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x07), COLORSELECT(0x0d, 0x0e),

    // row 1: 8 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x00, 0x00),
    _1BIT_TYPE1 | CHAR_WIDTH(0x04), CHARSELECT(0x01), COLORSELECT(0x02, 0x03),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0a), CHARSELECT(0x02), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE1 | CHAR_WIDTH(0x05), CHARSELECT(0x03), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0b), CHARSELECT(0x04), COLORSELECT(0x07, 0x08),
    _1BIT_TYPE1 | CHAR_WIDTH(0x06), CHARSELECT(0x05), COLORSELECT(0x09, 0x0a),
    _1BIT_TYPE1 | CHAR_WIDTH(0x09), CHARSELECT(0x06), COLORSELECT(0x0b, 0x0c),
    _1BIT_TYPE1 | CHAR_WIDTH(0x07), CHARSELECT(0x07), COLORSELECT(0x0e, 0x0f),

    // row 2: 8 font
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x00, 0x01),
    _1BIT_TYPE5 | CHAR_WIDTH(0x04), CHARSELECT(0x01), COLORSELECT(0x02, 0x03),
    _1BIT_TYPE5 | CHAR_WIDTH(0x0a), CHARSELECT(0x02), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE5 | CHAR_WIDTH(0x05), CHARSELECT(0x03), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE5 | CHAR_WIDTH(0x0b), CHARSELECT(0x04), COLORSELECT(0x07, 0x08),
    _1BIT_TYPE5 | CHAR_WIDTH(0x06), CHARSELECT(0x05), COLORSELECT(0x09, 0x0a),
    _1BIT_TYPE5 | CHAR_WIDTH(0x09), CHARSELECT(0x06), COLORSELECT(0x0b, 0x0c),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x07), COLORSELECT(0x0e, 0x0f),
    
    // row 3 2-bit font color select 0-15  : 8 font
    _2BIT_TYPE1 | ((COLOR00(0x04) & 0x08) << 3) | ((COLOR11(0x00) & 0x07) << 1) | ((COLOR00(0x04) & 0x04) >> 2), 
    ((COLOR01(0x03) & 0x08) << 6) | CHARSELECT(0x04), 
    ((COLOR00(0x04) & 0x03) << 6) | ((COLOR10(0x04) & 0x07) << 3) | (COLOR01(0x03) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x0d) & 0x08) << 3) | ((COLOR11(0x09) & 0x07) << 1) | ((COLOR00(0x0d) & 0x04) >> 2), 
    ((COLOR01(0x05) & 0x08) << 6) | CHARSELECT(0x05), 
    ((COLOR00(0x0d) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x05) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x05) & 0x08) << 3) | ((COLOR11(0x02) & 0x07) << 1) | ((COLOR00(0x05) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x06), 
    ((COLOR00(0x05) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x07) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x0e) & 0x08) << 3) | ((COLOR11(0x0b) & 0x07) << 1) | ((COLOR00(0x0e) & 0x04) >> 2), 
    ((COLOR01(0x01) & 0x08) << 6) | CHARSELECT(0x07), 
    ((COLOR00(0x0e) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x01) & 0x07),
        
    _2BIT_TYPE1 | ((COLOR00(0x06) & 0x08) << 3) | ((COLOR11(0x04) & 0x07) << 1) | ((COLOR00(0x06) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x08), 
    ((COLOR00(0x06) & 0x03) << 6) | ((COLOR10(0x05) & 0x07) << 3) | (COLOR01(0x03) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x0f) & 0x08) << 3) | ((COLOR11(0x0d) & 0x07) << 1) | ((COLOR00(0x0f) & 0x04) >> 2), 
    ((COLOR01(0x05) & 0x08) << 6) | CHARSELECT(0x09), 
    ((COLOR00(0x0f) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x05) & 0x07),

    _2BIT_TYPE1 | ((COLOR00(0x07) & 0x08) << 3) | ((COLOR11(0x06) & 0x07) << 1) | ((COLOR00(0x07) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x0a), 
    ((COLOR00(0x07) & 0x03) << 6) | ((COLOR10(0x05) & 0x07) << 3) | (COLOR01(0x07) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x08) & 0x08) << 3) | ((COLOR11(0x0f) & 0x07) << 1) | ((COLOR00(0x08) & 0x04) >> 2), 
    ((COLOR01(0x01) & 0x08) << 6) | CHARSELECT(0x0b), 
    ((COLOR00(0x08) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x01) & 0x07),

    // row 4, 2-bit font color select 16-31 : 8 font 
    _2BIT_TYPE2 | ((COLOR00(0x00) & 0x08) << 3) | ((COLOR11(0x01) & 0x07) << 1) | ((COLOR00(0x00) & 0x04) >> 2), 
    ((COLOR01(0x0e) & 0x08) << 6) | CHARSELECT(0x04), 
    ((COLOR00(0x00) & 0x03) << 6) | ((COLOR10(0x0c) & 0x07) << 3) | (COLOR01(0x0e) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x09) & 0x08) << 3) | ((COLOR11(0x0a) & 0x07) << 1) | ((COLOR00(0x09) & 0x04) >> 2), 
    ((COLOR01(0x0d) & 0x08) << 6) | CHARSELECT(0x05), 
    ((COLOR00(0x09) & 0x03) << 6) | ((COLOR10(0x08) & 0x07) << 3) | (COLOR01(0x0d) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x01) & 0x08) << 3) | ((COLOR11(0x03) & 0x07) << 1) | ((COLOR00(0x01) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x06), 
    ((COLOR00(0x09) & 0x03) << 6) | ((COLOR10(0x04) & 0x07) << 3) | (COLOR01(0x07) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x0a) & 0x08) << 3) | ((COLOR11(0x0c) & 0x07) << 1) | ((COLOR00(0x0a) & 0x04) >> 2), 
    ((COLOR01(0x01) & 0x08) << 6) | CHARSELECT(0x07), 
    ((COLOR00(0x0a) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x01) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x02) & 0x08) << 3) | ((COLOR11(0x05) & 0x07) << 1) | ((COLOR00(0x02) & 0x04) >> 2), 
    ((COLOR01(0x03) & 0x08) << 6) | CHARSELECT(0x08), 
    ((COLOR00(0x02) & 0x03) << 6) | ((COLOR10(0x05) & 0x07) << 3) | (COLOR01(0x03) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x0b) & 0x08) << 3) | ((COLOR11(0x0e) & 0x07) << 1) | ((COLOR00(0x0b) & 0x04) >> 2), 
    ((COLOR01(0x05) & 0x08) << 6) | CHARSELECT(0x09), 
    ((COLOR00(0x0b) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x05) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x07) & 0x08) << 3) | ((COLOR11(0x06) & 0x07) << 1) | ((COLOR00(0x07) & 0x04) >> 2), 
    ((COLOR01(0x0f) & 0x08) << 6) | CHARSELECT(0x0a), 
    ((COLOR00(0x07) & 0x03) << 6) | ((COLOR10(0x0d) & 0x07) << 3) | (COLOR01(0x0f) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x08) & 0x08) << 3) | ((COLOR11(0x08) & 0x07) << 1) | ((COLOR00(0x08) & 0x04) >> 2), 
    ((COLOR01(0x03) & 0x08) << 6) | CHARSELECT(0x0b), 
    ((COLOR00(0x02) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x01) & 0x07),
   
    // row 5 : 8 font
    _4BIT_TYPE | FOURBITBGCOLOR(0x00), CHARSELECT(0x07), 0x00,
    _4BIT_TYPE | FOURBITBGCOLOR(0x01), CHARSELECT(0x08), 0x55,
    _4BIT_TYPE | FOURBITBGCOLOR(0x02), CHARSELECT(0x09), 0xaa,
    _4BIT_TYPE | FOURBITBGCOLOR(0x03), CHARSELECT(0x0a), 0xff,
    _4BIT_TYPE | FOURBITBGCOLOR(0x04), CHARSELECT(0x0b), 0x22,
    _4BIT_TYPE | FOURBITBGCOLOR(0x05), CHARSELECT(0x0c), 0x44,
    _4BIT_TYPE | FOURBITBGCOLOR(0x06), CHARSELECT(0x0d), 0x66,
    _4BIT_TYPE | FOURBITBGCOLOR(0x07), CHARSELECT(0x0e), 0x88,

    // row 6 : 8 font
    _4BIT_TYPE | FOURBITBGCOLOR(0x08), CHARSELECT(0x07), 0x33,
    _4BIT_TYPE | FOURBITBGCOLOR(0x09), CHARSELECT(0x08), 0x11,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0a), CHARSELECT(0x09), 0xbb,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0b), CHARSELECT(0x0a), 0xcc,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0c), CHARSELECT(0x0b), 0x01,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0d), CHARSELECT(0x0c), 0x23,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0e), CHARSELECT(0x0d), 0x45,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0f), CHARSELECT(0x0e), 0x67,

    // row 7 : 4 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1 "n"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1  "n"
    _1BIT_TYPE3 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"

    // row 8 : 4 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE3 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"


    // row 9 : 4 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x02, 0x0b),  // FONT 400 "0"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x02, 0x0b),  // FONT 400 "0"
    _1BIT_TYPE3 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"

    // row 10 : 4 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x02, 0x0b),  // FONT 400 "0"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x02, 0x0b),  // FONT 400 "0"
    _1BIT_TYPE3 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"

    // row 11  // blank : 3 font
    _1BIT_TYPE2, CHARSELECT(0x10), BLANKCOLOR(0x12), 
    _1BIT_TYPE2, CHARSELECT(0x12), BLANKCOLOR(0x00), 
    _1BIT_TYPE2, CHARSELECT(0x16), BLANKCOLOR(0x3f), 

    // row 12  : 6 font for OSD Reorder function
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x3c), COLORSELECT(0x02, 0x0f), 
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x3d), COLORSELECT(0x0b, 0x01), 
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x3e), COLORSELECT(0x00, 0x0c), 

    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x3f), COLORSELECT(0x0a, 0x03), 
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x40), COLORSELECT(0x05, 0x0b), 
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x41), COLORSELECT(0x0f, 0x04),
};

//----------------------Window 4 - 1 --------------------------------------
#define _WIN41_COLOR_FRAME4                      0x21

//----------------------Window type-----------------------------------
#define _WIN41_STYLE_FRAME4                      _WIN_BORDER

#define _WIN41_SHADOW_COLOR_FRAME4               0x00
#define _WIN41_BORDER_COLOR_FRAME4               0x00
#define _WIN41_SHADOW_WIDTH_FRAME4               0x00      // 000-111
#define _WIN41_SHADOW_HEIGHT_FRAME4              0x00      // 000-111
#define _WIN41_SHADOW_ENABLE_FRAME4              0x00

//----------------------Window 4-1 has no grident function--------------
//--------------------------------------------------
// Description  : OSD window4-1 style  for OSDTestFrame4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN41_STYLE_FRAME4[] =
{
    WINNO(1),
    
    ((_WIN41_SHADOW_COLOR_FRAME4 & 0x10) << 3) | ((_WIN41_BORDER_COLOR_FRAME4 & 0x10) << 2) | ((_WIN41_SHADOW_WIDTH_FRAME4 & 0x07) << 3) | (_WIN41_SHADOW_HEIGHT_FRAME4 & 0x07),
    ((_WIN41_SHADOW_COLOR_FRAME4 & 0x0f) << 4) | (_WIN41_BORDER_COLOR_FRAME4 & 0x0f),
    0x00,

    ((_WIN41_SHADOW_COLOR_FRAME4 & 0x20) << 2) | ((_WIN41_BORDER_COLOR_FRAME4 & 0x20) << 1) | (_WIN41_COLOR_FRAME4 & 0x20),
    (_WIN41_COLOR_FRAME4 & 0x1F),
    ((_WIN41_SHADOW_ENABLE_FRAME4 & 0x01) << 4) | ((_WIN41_STYLE_FRAME4 & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 4 - 2 --------------------------------------
#define _WIN42_COLOR_FRAME4                      0x2c

//----------------------Window type-----------------------------------
#define _WIN42_STYLE_FRAME4                      _WIN_SHADOW_TYPE1

#define _WIN42_SHADOW_COLOR_FRAME4               0x00
#define _WIN42_BORDER_COLOR_FRAME4               0x00
#define _WIN42_SHADOW_WIDTH_FRAME4               0x00      // 000-111
#define _WIN42_SHADOW_HEIGHT_FRAME4              0x00      // 000-111
#define _WIN42_SHADOW_ENABLE_FRAME4              0x00

//----------------------Window 4-1 has no grident function--------------
//--------------------------------------------------
// Description  : OSD window4-2 style  for OSDTestFrame4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN42_STYLE_FRAME4[] =
{
    WINNO(2),
    
    ((_WIN42_SHADOW_COLOR_FRAME4 & 0x10) << 3) | ((_WIN42_BORDER_COLOR_FRAME4 & 0x10) << 2) | ((_WIN42_SHADOW_WIDTH_FRAME4 & 0x07) << 3) | (_WIN42_SHADOW_HEIGHT_FRAME4 & 0x07),
    ((_WIN42_SHADOW_COLOR_FRAME4 & 0x0f) << 4) | (_WIN42_BORDER_COLOR_FRAME4 & 0x0f),
    0x00,

    ((_WIN42_SHADOW_COLOR_FRAME4 & 0x20) << 2) | ((_WIN42_BORDER_COLOR_FRAME4 & 0x20) << 1) | (_WIN42_COLOR_FRAME4 & 0x20),
    (_WIN42_COLOR_FRAME4 & 0x1F),
    ((_WIN42_SHADOW_ENABLE_FRAME4 & 0x01) << 4) | ((_WIN42_STYLE_FRAME4 & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 4 - 3 --------------------------------------
#define _WIN43_COLOR_FRAME4                      0x25

//----------------------Window type-----------------------------------
#define _WIN43_STYLE_FRAME4                      _WIN_RESEVERD

#define _WIN43_SHADOW_COLOR_FRAME4               0x00
#define _WIN43_BORDER_COLOR_FRAME4               0x00
#define _WIN43_SHADOW_WIDTH_FRAME4               0x00      // 000-111
#define _WIN43_SHADOW_HEIGHT_FRAME4              0x00      // 000-111
#define _WIN43_SHADOW_ENABLE_FRAME4              0x00

//----------------------Window 4-1 has no grident function--------------
//--------------------------------------------------
// Description  : OSD window4-3 style  for OSDTestFrame4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN43_STYLE_FRAME4[] =
{
    WINNO(3),
    
    ((_WIN43_SHADOW_COLOR_FRAME4 & 0x10) << 3) | ((_WIN43_BORDER_COLOR_FRAME4 & 0x10) << 2) | ((_WIN43_SHADOW_WIDTH_FRAME4 & 0x07) << 3) | (_WIN43_SHADOW_HEIGHT_FRAME4 & 0x07),
    ((_WIN43_SHADOW_COLOR_FRAME4 & 0x0f) << 4) | (_WIN43_BORDER_COLOR_FRAME4 & 0x0f),
    0x00,

    ((_WIN43_SHADOW_COLOR_FRAME4 & 0x20) << 2) | ((_WIN43_BORDER_COLOR_FRAME4 & 0x20) << 1) | (_WIN43_COLOR_FRAME4 & 0x20),
    (_WIN43_COLOR_FRAME4 & 0x1F),
    ((_WIN43_SHADOW_ENABLE_FRAME4 & 0x01) << 4) | ((_WIN43_STYLE_FRAME4 & 0x07) << 1) | 0x01,
};

//--------------------------------------------------
// Description  : Row command for OSDTestFrame4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDROWMAPAPPLY_FRAME4[] =
{
    0x87, 0xF3, 0x08,  // row 0, h*2 = 17,  w*2, board(001)             , col space = 0, length = 8
    0x9F, 0xF3, 0x08,  // row 1, h*2 = 17,  w*2, shadow(right-bottom), col space = 0, length = 8
    0x87, 0xd3, 0x08,  // row 2, h*2 = 28,  w*2, shadow(right-bottom), col space = 3, length = 8

    // for test write protection function
    0x80, 0x90, 0x08,  // row 3, h*1 = 18,  w*1, no effect           , col space = 0, length = 8

    0x00, 0x00, 0x00,  // row end
};

//--------------------------------------------------
// Description  : Character command for OSDTestFrame4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDCHARACTERCOMMAND_FRAME4[] =
{
    // 0x103
    // row 0, 8 font
    0x0c, 0x00, 0x23, // char width: 13, 1bit font, form 0~255, color: 16~31
    0x88, 0x01, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x02, 0x23, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x03, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15  
    0x88, 0x00, 0x23, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x01, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x02, 0x67, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x03, 0x89, // char width: 9, 1bit font, form 0~255, color: 0~15

    // row 1, 8 font
    0x0c, 0x00, 0x23, // char width: 13, 1bit font, form 0~255, color: 16~31
    0x88, 0x01, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x02, 0x23, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x03, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15  
    0x88, 0x00, 0x23, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x01, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x02, 0x67, // char width: 9, 1bit font, form 0~255, color: 0~15
    0x88, 0x03, 0x89, // char width: 9, 1bit font, form 0~255, color: 0~15
                                
    // row 2, 8 font                          // 4bit font,
    0x90, 0x01, 0x00, 
    0x91, 0x01, 0x55, 
    0x92, 0x02, 0xaa, 
    0x93, 0x02, 0xff,    
    0x94, 0x03, 0x22, 
    0x95, 0x03, 0x44, 
    0x96, 0x01, 0x66, 
    0x97, 0x01, 0x88,

    // modify 20101011 start
    // test the 011h write protection function
    // row 3, 8 font                          // 1bit font,
    0x0c, 0x00, 0x28, // char width: 12, 1bit font, form 0~255, color: 16~31
    0x8C, 0x01, 0x49, // char width: 12, 1bit font, form 0~255, color: 0~15
    0x10, 0x10, 0x12, // Blank, the color is the index of 0x02
    0x10, 0x12, 0x20, // Blank, the color is the index of 0x00 
    0x0c, 0x00, 0x28, // char width: 12, 1bit font, form 0~255, color: 16~31
    0x8C, 0x01, 0x49, // char width: 12, 1bit font, form 0~255, color: 0~15
    // color palette 0-15,  byte0-bit4=0,
    // 2-bit font 00-0011, 
    //            01-1100, 
    //            10-1011, 
    //            11-0101,
    0xAA, 0x08, 0xDC, // 2-bit
    // color palette 16-31,  byte0-bit4=1,
    // 2-bit font 00-0011, 
    //            01-0100, 
    //            10-0011, 
    //            11-0101,
    0xBA, 0x08, 0xDC, // 2-bit
};

//--------------------------------------------------
// Description  : Load font table for OSDTestFrame4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDNOMALFONTDATA_TABLE_FRAME4[] =
{
    // 0x403
    0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,     // map of "A",     // FONT 0    	    	    	    	    	    
    0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
            	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,     // map of "n",  // FONT 1
    0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,    	    	    	    	    	    	    
    0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
            	    	    	    	    
    0x0c, 0x00, 0x00, 0x0c, 0xc0, 0x00, 0x0c, 0xc0, 0x00,     // map of "d",  // FONT 2
    0xfc, 0xc3, 0x1e, 0x0c, 0xc6, 0x31, 0x0c, 0xc6, 0x60,    	    	    	    	    	    	    
    0x1c, 0xc7, 0x60, 0xec, 0xc1, 0x3f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x81, 0x0f,     // map of "e",  // FONT 3    	    	    	    	    	    	
    0x1c, 0xc3, 0x38, 0xf0, 0x83, 0x33, 0x84, 0x03, 0x3c,    	    	    	    	    	    	    
    0xf0, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     
    0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x02, 0x00,     // test font "E" 4-bit,  //  FONT 28,29,30,31(7)    	    	    	    	    	    	
    0x00, 0x02, 0x00, 0x00, 0x02, 0x1e, 0x00, 0x02, 0x00,    // byte2-bit[1:0]    	    	    	    	    	    	
    0x00, 0x03, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x02, 0x20, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x20,    	    	    	    	    	    	    
    0x00, 0x02, 0x20, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x01, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00,
        
    0x00, 0x00, 0x00, 0x18, 0x82, 0x20, 0x10, 0x01, 0x31,     // test font "X" 4-bit,  //  FONT 32,33,34,35(8)    	    	    	    	    	    
    0xa0, 0x00, 0x1b, 0x60, 0x00, 0x0e, 0xb0, 0x00, 0x0e,    	    	    	    	    	    	    
    0x0c, 0x81, 0x19, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,     // test font "T" 4-bit,  //  FONT 36,37,38,39(9)    	    	    	    	    	    	    	
    0x40, 0x00, 0x04, 0x60, 0x00, 0x04, 0x60, 0x00, 0x06,    	    	    	    	    	    	    
    0x20, 0x00, 0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0xc0, 0x31, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x14, 0xc5, 0x60,     // map of "M" 2-bit,  // FONT 9 
    0x14, 0x45, 0x51, 0xa4, 0x44, 0x4a, 0x04, 0x44, 0x40,    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x0e, 0x4e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0xa0, 0x00, 0x0a, 0x00, 0x00, 0x04,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};  

//--------------------------------------------------
// Description  : Row command for OSDTestFrame5
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDROWMAPAPPLY_FRAME5[] =
{
    /* row 0*/   _ROW_START | _VBI_ENABLE | _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,            ROWHEIGHT(31), ROWLENGTH(0x05),
    /* row 1*/   _ROW_START | _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                          ROWHEIGHT(31), ROWLENGTH(0x02),
    /* row 2*/   _ROW_START | _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                          ROWHEIGHT(31), ROWLENGTH(0x05),
    /* row 3*/   _ROW_START | _CHARACTER_TYPE_BORDER | _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2, ROWHEIGHT(31), ROWLENGTH(0x0a), 
    /* row end*/ _ROW_END,                                                                             0x00,          0x00,
};

//--------------------------------------------------
// Description  : Character command for OSDTestFrame5
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDCHARACTERCOMMAND_FRAME5[] =
{
    // row 0
    _1BIT_TYPE5 | _UNDERLINE_ENABLE,                    CHARSELECT(0x00), COLORSELECT(0x01, 0x06),
    _1BIT_TYPE5 | _ONLY_BLINK_FORF | _UNDERLINE_ENABLE, CHARSELECT(0x01), COLORSELECT(0x03, 0x02),
    _1BIT_TYPE5 | _ONLY_BLINK_FORB | _UNDERLINE_ENABLE, CHARSELECT(0x00), COLORSELECT(0x05, 0x0a),
    _1BIT_TYPE5 | _BOTH_BLINK_FORB | _UNDERLINE_ENABLE,CHARSELECT(0x00), COLORSELECT(0x04, 0x06),
    _4BIT_TYPE  | _4BIT_BLINKING_ENABLE,CHARSELECT(0x03), 0x67,
    
     // row 1 2-bit font color select 0-15 
    _2BIT_TYPE1 | ((COLOR00(0x01) & 0x08) << 3) | ((COLOR11(0x06) & 0x07) << 1) | ((COLOR00(0x01) & 0x04) >> 2), 
    ((COLOR01(0x04) & 0x08) << 6) | CHARSELECT(0x03), 
    ((COLOR00(0x01) & 0x03) << 6) | ((COLOR10(0x04) & 0x07) << 3) | (COLOR01(0x07) & 0x07),

    _2BIT_TYPE1 | ((COLOR00(0x05) & 0x08) << 3) | ((COLOR11(0x01) & 0x07) << 1) | ((COLOR00(0x05) & 0x04) >> 2), 
    ((COLOR01(0x04) & 0x08) << 6) | CHARSELECT(0x04), 
    ((COLOR00(0x05) & 0x03) << 6) | ((COLOR10(0x04) & 0x07) << 3) | (COLOR01(0x07) & 0x07),

    // row 2
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x01, 0x06),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x01), COLORSELECT(0x02, 0x03),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0a), CHARSELECT(0x01), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x02), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0b), CHARSELECT(0x03), COLORSELECT(0x07, 0x08),

    // row 3
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x00), COLORSELECT(0x01, 0x0f),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x01), COLORSELECT(0x02, 0x0e),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x01), COLORSELECT(0x03, 0x0f),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x02), COLORSELECT(0x05, 0x00),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x03), COLORSELECT(0x07, 0x00),

    // row 4
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x00), COLORSELECT(0x01, 0x0e),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x01), COLORSELECT(0x02, 0x0f),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x01), COLORSELECT(0x03, 0x00),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x02), COLORSELECT(0x05, 0x00),
    _1BIT_TYPE1 | CHAR_WIDTH(0x0f), CHARSELECT(0x03), COLORSELECT(0x07, 0x00),
};

//--------------------------------------------------
// Description  : Load font table for OSDTestFrame5
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDNOMALFONTDATA_FRAME5[] =
{
    // 0x1403  , 16x27
    0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,     // map of "A",  // FONT 0    	    	    	    	    	    
    0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,    

    0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,     // map of "A",  // FONT 1    	    	    	    	    	    
    0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,     // map of "A",  // FONT 2    	    	    	    	    	    
    0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,     // map of "A",  // FONT 3    	    	    	    	    	    
    0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x14, 0xc5, 0x60,     // map of "M" 2-bit,  // FONT 4,5(4) 
    0x14, 0x45, 0x51, 0xa4, 0x44, 0x4a, 0x04, 0x44, 0x40,    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x0e, 0x4e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0xa0, 0x00, 0x0a, 0x00, 0x00, 0x04,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    

    0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x08, 0x82, 0x20,     // map of "D" 2-bit,  // FONT 6,7(5)    	    	    	    	    	    	
    0x04, 0x42, 0x20, 0x04, 0x42, 0x20, 0x08, 0x42, 0x20,    	    	    	    	    	    	    
    0xf0, 0x87, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     // map of "-" 2-bit,  // FONT 8,9(6)    	    	    	    	    	    	
    0x00, 0x00, 0x00, 0x00, 0x40, 0x35, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    

    0x00, 0x00, 0x00, 0xe8, 0x00, 0x00, 0x08, 0x82, 0x11,     // map of "S" 2-bit,  // FONT 10,11(7)    	    	    	    	    	    
    0x00, 0x03, 0x20, 0x18, 0x00, 0x0e, 0x08, 0x82, 0x00,    	    	    	    	    	    	    
    0xe0, 0x02, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        
    0x00, 0x00, 0x00, 0x0c, 0x80, 0x01, 0x04, 0x40, 0x00,     // test font "3" 4-bit ,  //  FONT 12,13,14,15(3)    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x0c, 0x80, 0x0f, 0x04, 0x40, 0x00,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x20,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    	    	    	    	    	    	    
    0x00, 0x00, 0x00, 0x30, 0x00, 0x01, 0x18, 0x00, 0x01,    	    	    	    	    	    	    
    0x08, 0x80, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,
};

//--------------------------------------------------------------------
//----------------------Window 0--------------------------------------
#define _WIN0_COLOR_FRAME5                   0x01

//----------------------window type-----------------------------------
#define _WIN0_STYLE_FRAME5                   _WIN_3DBUTTON_TYPE1

#define _WIN0_SHADOW_COLOR_FRAME5            0x0f
#define _WIN0_BORDER_COLOR_FRAME5            0x08
#define _WIN0_SHADOW_WIDTH_FRAME5            0x07      // 000-111
#define _WIN0_SHADOW_HEIGHT_FRAME5           0x07      // 000-111
#define _WIN0_SHADOW_ENABLE_FRAME5           0x01

//----------------------grident function------------------------------
#define _WIN0_R_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN0_G_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN0_B_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN0_GRIDENT_LEVEL_FRAME5           0x00      // 00-11: 1-4

#define _WIN0_R_GRIDENT_ENABLE_FRAME5        0x00
#define _WIN0_G_GRIDENT_ENABLE_FRAME5        0x00
#define _WIN0_B_GRIDENT_ENABLE_FRAME5        0x00

#define _WIN0_PERGRADIENT_LEVEL_FRAME5       0x03     // 000-111
#define _WIN0_GRIDENT_ENABLE_FRAME5          0x00
#define _WIN0_GRIDENT_DIRECTION_FRAME5       0x00

#define _WIN0_STATURATED_ENABLE_FRAME5          0x00
#define _WIN0_REVERSEDCOLORMODE_ENABLE_FRAME5   0x00

#define _WIN0_BlendingEnable_FRAME5          0x01

//--------------------------------------------------
// Description  : Window0 style for OSDTestFrame5
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN0_STYLE_FRAME5[] =
{
    WINNO(0),
    
    // 100h-byte0
    ((_WIN0_SHADOW_COLOR_FRAME5 & 0x10) << 3) | ((_WIN0_BORDER_COLOR_FRAME5 & 0x10) << 2) | ((_WIN0_SHADOW_WIDTH_FRAME5 & 0x07) << 3) | (_WIN0_SHADOW_HEIGHT_FRAME5 & 0x07),
    // 100h-byte1
    ((_WIN0_SHADOW_COLOR_FRAME5 & 0x0f) << 4) | (_WIN0_BORDER_COLOR_FRAME5 & 0x0f),
    // 100h-byte2
    ((_WIN0_R_GRIDENT_POLARITY_FRAME5 & 0x01) << 7) | ((_WIN0_G_GRIDENT_POLARITY_FRAME5 & 0x01) << 6) | ((_WIN0_B_GRIDENT_POLARITY_FRAME5 & 0x01) << 5) | 
    ((_WIN0_GRIDENT_LEVEL_FRAME5 & 0x07) << 3) | ((_WIN0_R_GRIDENT_ENABLE_FRAME5 & 0x01) << 2) | ((_WIN0_G_GRIDENT_ENABLE_FRAME5 & 0x01) << 1) | (_WIN0_B_GRIDENT_ENABLE_FRAME5 & 0x01),

    // 103h-byte0 
    ((_WIN0_SHADOW_COLOR_FRAME5 & 0x20) << 2) | ((_WIN0_BORDER_COLOR_FRAME5 & 0x20) << 1) | (_WIN0_COLOR_FRAME5 & 0x20) | ((_WIN0_STATURATED_ENABLE_FRAME5 & 0x01) << 4) | ((_WIN0_REVERSEDCOLORMODE_ENABLE_FRAME5 & 0x01) << 3),
    // 103h-byte1
    ((_WIN0_PERGRADIENT_LEVEL_FRAME5 & 0x07) << 5) | (_WIN0_COLOR_FRAME5 & 0x1F),
    // 103h-bye2
    ((_WIN0_BlendingEnable_FRAME5 & 0x01) << 7) | ((_WIN0_GRIDENT_ENABLE_FRAME5 & 0x01) << 6) | ((_WIN0_GRIDENT_DIRECTION_FRAME5 & 0x01) << 5) | ((_WIN0_SHADOW_ENABLE_FRAME5 & 0x01) << 4) | ((_WIN0_STYLE_FRAME5 & 0x07) << 1) | 0x01,
};

//--------------------------------------------------
// Description  : Row command for OSDTestFrame7
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDROWMAPAPPLY_FRAME7[] =
{
    /* row 0*/   _ROW_START| _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                                             ROWHEIGHT(17) | COLSPACE(6),   ROWLENGTH(8),
    /* row 1*/   _ROW_START| _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                                             ROWHEIGHT(19) | COLSPACE(6),   ROWLENGTH(8),
    /* row 2*/   _ROW_START| _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                                             ROWHEIGHT(21) | COLSPACE(6),   ROWLENGTH(8),
    /* row 3*/   _ROW_START| _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                                             ROWHEIGHT(23) | COLSPACE(5),   ROWLENGTH(8),
    /* row 4*/   _ROW_START| _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                                             ROWHEIGHT(25) | COLSPACE(6),   ROWLENGTH(8),
    /* row 5*/   _ROW_START| _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                                             ROWHEIGHT(27) | COLSPACE(6),   ROWLENGTH(8),
    /* row 6*/   _ROW_START| _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                                             ROWHEIGHT(19) | COLSPACE(6),   ROWLENGTH(8),
    /* row 7*/   _ROW_START| _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2,                                             ROWHEIGHT(17) | COLSPACE(6),   ROWLENGTH(8),
    /* row 8*/   _ROW_START| _DOUBLE_CHAR_WIDTH_X2 | _DOUBLE_CHAR_HEIGHT_X2| _1BITFONT_SELECT_512_1023,                  ROWHEIGHT(17) | COLSPACE(6),   ROWLENGTH(8), 
    /* row end*/ _ROW_END,                                               0x00,                          0x00,
}; 

//--------------------------------------------------
// Description  : Character command for OSDTestFrame7
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDCHARACTERCOMMAND_FRAME7[] =  // 3x8 = 24
{
    // row 0: 8 font 
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x00, 0x00),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x01), COLORSELECT(0x01, 0x02),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x02), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x03), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x04), COLORSELECT(0x07, 0x08),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x05), COLORSELECT(0x09, 0x0a),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x06), COLORSELECT(0x0b, 0x0c),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x07), COLORSELECT(0x0d, 0x0e),

    // row 1: 8 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x00, 0x00),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x01), COLORSELECT(0x02, 0x03),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x02), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x03), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x04), COLORSELECT(0x07, 0x08),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x05), COLORSELECT(0x09, 0x0a),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x06), COLORSELECT(0x0b, 0x0c),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x07), COLORSELECT(0x0e, 0x0f),

    // row 2: 8 font
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x00, 0x01),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x01), COLORSELECT(0x02, 0x03),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x02), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x03), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x04), COLORSELECT(0x07, 0x08),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x05), COLORSELECT(0x09, 0x0a),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x06), COLORSELECT(0x0b, 0x0c),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x07), COLORSELECT(0x0e, 0x0f),

    // row 3 2-bit font color select 0-15  : 8 font
    _2BIT_TYPE1 | ((COLOR00(0x04) & 0x08) << 3) | ((COLOR11(0x00) & 0x07) << 1) | ((COLOR00(0x04) & 0x04) >> 2), 
    ((COLOR01(0x03) & 0x08) << 6) | CHARSELECT(0x04), 
    ((COLOR00(0x04) & 0x03) << 6) | ((COLOR10(0x04) & 0x07) << 3) | (COLOR01(0x03) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x0d) & 0x08) << 3) | ((COLOR11(0x09) & 0x07) << 1) | ((COLOR00(0x0d) & 0x04) >> 2), 
    ((COLOR01(0x05) & 0x08) << 6) | CHARSELECT(0x05), 
    ((COLOR00(0x0d) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x05) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x05) & 0x08) << 3) | ((COLOR11(0x02) & 0x07) << 1) | ((COLOR00(0x05) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x06), 
    ((COLOR00(0x05) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x07) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x0e) & 0x08) << 3) | ((COLOR11(0x0b) & 0x07) << 1) | ((COLOR00(0x0e) & 0x04) >> 2), 
    ((COLOR01(0x01) & 0x08) << 6) | CHARSELECT(0x07), 
    ((COLOR00(0x0e) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x01) & 0x07),
        
    _2BIT_TYPE1 | ((COLOR00(0x06) & 0x08) << 3) | ((COLOR11(0x04) & 0x07) << 1) | ((COLOR00(0x06) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x08), 
    ((COLOR00(0x06) & 0x03) << 6) | ((COLOR10(0x05) & 0x07) << 3) | (COLOR01(0x03) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x0f) & 0x08) << 3) | ((COLOR11(0x0d) & 0x07) << 1) | ((COLOR00(0x0f) & 0x04) >> 2), 
    ((COLOR01(0x05) & 0x08) << 6) | CHARSELECT(0x09), 
    ((COLOR00(0x0f) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x05) & 0x07),

    _2BIT_TYPE1 | ((COLOR00(0x07) & 0x08) << 3) | ((COLOR11(0x06) & 0x07) << 1) | ((COLOR00(0x07) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x0a), 
    ((COLOR00(0x07) & 0x03) << 6) | ((COLOR10(0x05) & 0x07) << 3) | (COLOR01(0x07) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x08) & 0x08) << 3) | ((COLOR11(0x0f) & 0x07) << 1) | ((COLOR00(0x08) & 0x04) >> 2), 
    ((COLOR01(0x01) & 0x08) << 6) | CHARSELECT(0x0b), 
    ((COLOR00(0x08) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x01) & 0x07),

    // row 4, 2-bit font color select 16-31 : 8 font 
    _2BIT_TYPE2 | ((COLOR00(0x00) & 0x08) << 3) | ((COLOR11(0x01) & 0x07) << 1) | ((COLOR00(0x00) & 0x04) >> 2), 
    ((COLOR01(0x0e) & 0x08) << 6) | CHARSELECT(0x04), 
    ((COLOR00(0x00) & 0x03) << 6) | ((COLOR10(0x0c) & 0x07) << 3) | (COLOR01(0x0e) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x09) & 0x08) << 3) | ((COLOR11(0x0a) & 0x07) << 1) | ((COLOR00(0x09) & 0x04) >> 2), 
    ((COLOR01(0x0d) & 0x08) << 6) | CHARSELECT(0x05), 
    ((COLOR00(0x09) & 0x03) << 6) | ((COLOR10(0x08) & 0x07) << 3) | (COLOR01(0x0d) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x01) & 0x08) << 3) | ((COLOR11(0x03) & 0x07) << 1) | ((COLOR00(0x01) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x06), 
    ((COLOR00(0x09) & 0x03) << 6) | ((COLOR10(0x04) & 0x07) << 3) | (COLOR01(0x07) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x0a) & 0x08) << 3) | ((COLOR11(0x0c) & 0x07) << 1) | ((COLOR00(0x0a) & 0x04) >> 2), 
    ((COLOR01(0x01) & 0x08) << 6) | CHARSELECT(0x07), 
    ((COLOR00(0x0a) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x01) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x02) & 0x08) << 3) | ((COLOR11(0x05) & 0x07) << 1) | ((COLOR00(0x02) & 0x04) >> 2), 
    ((COLOR01(0x03) & 0x08) << 6) | CHARSELECT(0x08), 
    ((COLOR00(0x02) & 0x03) << 6) | ((COLOR10(0x05) & 0x07) << 3) | (COLOR01(0x03) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x0b) & 0x08) << 3) | ((COLOR11(0x0e) & 0x07) << 1) | ((COLOR00(0x0b) & 0x04) >> 2), 
    ((COLOR01(0x05) & 0x08) << 6) | CHARSELECT(0x09), 
    ((COLOR00(0x0b) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x05) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x07) & 0x08) << 3) | ((COLOR11(0x06) & 0x07) << 1) | ((COLOR00(0x07) & 0x04) >> 2), 
    ((COLOR01(0x0f) & 0x08) << 6) | CHARSELECT(0x0a), 
    ((COLOR00(0x07) & 0x03) << 6) | ((COLOR10(0x0d) & 0x07) << 3) | (COLOR01(0x0f) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x08) & 0x08) << 3) | ((COLOR11(0x08) & 0x07) << 1) | ((COLOR00(0x08) & 0x04) >> 2), 
    ((COLOR01(0x03) & 0x08) << 6) | CHARSELECT(0x0b), 
    ((COLOR00(0x02) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x01) & 0x07),
    
    // row 5 : 8 font
    _4BIT_TYPE | FOURBITBGCOLOR(0x00), CHARSELECT(0x07), 0x00,
    _4BIT_TYPE | FOURBITBGCOLOR(0x01), CHARSELECT(0x08), 0x55,
    _4BIT_TYPE | FOURBITBGCOLOR(0x02), CHARSELECT(0x09), 0xaa,
    _4BIT_TYPE | FOURBITBGCOLOR(0x03), CHARSELECT(0x0a), 0xff,
    _4BIT_TYPE | FOURBITBGCOLOR(0x04), CHARSELECT(0x0b), 0x22,
    _4BIT_TYPE | FOURBITBGCOLOR(0x05), CHARSELECT(0x0c), 0x44,
    _4BIT_TYPE | FOURBITBGCOLOR(0x06), CHARSELECT(0x0d), 0x66,
    _4BIT_TYPE | FOURBITBGCOLOR(0x07), CHARSELECT(0x0e), 0x88,

    // row 6 : 8 font
    _4BIT_TYPE | FOURBITBGCOLOR(0x08), CHARSELECT(0x07), 0x33,
    _4BIT_TYPE | FOURBITBGCOLOR(0x09), CHARSELECT(0x08), 0x11,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0a), CHARSELECT(0x09), 0xbb,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0b), CHARSELECT(0x0a), 0xcc,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0c), CHARSELECT(0x0b), 0x01,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0d), CHARSELECT(0x0c), 0x23,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0e), CHARSELECT(0x0d), 0x45,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0f), CHARSELECT(0x0e), 0x67,

    // row 7 : 4 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1 "n"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1  "n"
    _1BIT_TYPE2 | 0x02,            CHARSELECT(0x10), BLANKCOLOR(0x12), 
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1 "n"
    _1BIT_TYPE3 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1 "n"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1  "n"
   
    // row 8 : 4 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    //_1BIT_TYPE2 |0x01, CHARSELECT(0x04), BLANKCOLOR(0x12), 
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE3 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 780 "d"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 780 "d"
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 780 "d"

};

//--------------------------------------------------
// Description  : Window0 style for OSDTestFrame7
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN0_STYLEFRAME7[] =
{
     
     WINNO(0),
    // 100h-byte0  
    ((_WIN0_SHADOW_COLOR & 0x10) << 3) | ((_WIN0_BORDER_COLOR & 0x10) << 2) | ((_WIN0_SHADOW_WIDTH & 0x07) << 3) | (_WIN0_SHADOW_HEIGHT & 0x07),
    // 100h-byte1
    ((_WIN0_SHADOW_COLOR & 0x0f) << 4) | (_WIN0_BORDER_COLOR & 0x0f),
    // 100h-byte2
    ((_WIN0_R_GRIDENT_POLARITY & 0x01) << 7) | ((_WIN0_G_GRIDENT_POLARITY & 0x01) << 6) | ((_WIN0_B_GRIDENT_POLARITY & 0x01) << 5) | 
    ((_WIN0_GRIDENT_LEVEL & 0x07) << 3) | ((_WIN0_R_GRIDENT_ENABLE & 0x00) << 2) | ((_WIN0_G_GRIDENT_ENABLE & 0x00) << 1) | (_WIN0_B_GRIDENT_ENABLE & 0x00),

    //103h-byte0 
    ((_WIN0_SHADOW_COLOR & 0x20) << 2) | ((_WIN0_BORDER_COLOR & 0x20) << 1) | (_WIN0_COLOR & 0x20) | ((_WIN0_STATURATED_ENABLE & 0x01) << 4) | ((_WIN0_REVERSEDCOLORMODE_ENABLE & 0x01) << 3),
    //103h-byte1
    ((_WIN0_PERGRADIENT_LEVEL & 0x07) << 5) | (_WIN0_COLOR & 0x1F),
    //103h-bye2
    ((_WIN0_GRIDENT_ENABLE & 0x01) << 6) | ((_WIN0_GRIDENT_DIRECTION & 0x01) << 5) | ((_WIN0_SHADOW_ENABLE & 0x01) << 4) | ((_WIN0_STYLE & 0x07) << 1) | 0x01,
};


//--------------------------------------------------------------------
//----------------------Window 6-------------------------------------
#define _WIN6_COLOR_FRAME5                 0x0F //0x30

//----------------------window type-----------------------------------
#define _WIN6_STYLE_FRAME5                   _WIN_BORDER

#define _WIN6_SHADOW_COLOR_FRAME5            0x3f
#define _WIN6_BORDER_COLOR_FRAME5            0x3f
#define _WIN6_SHADOW_WIDTH_FRAME5            0x07      // 000-111
#define _WIN6_SHADOW_HEIGHT_FRAME5           0x07      // 000-111
#define _WIN6_SHADOW_ENABLE_FRAME5           0x01

//----------------------grident function------------------------------
#define _WIN6_R_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN6_G_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN6_B_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN6_GRIDENT_LEVEL_FRAME5           0x00      // 00-11: 1-4

#define _WIN6_R_GRIDENT_ENABLE_FRAME5        0x00
#define _WIN6_G_GRIDENT_ENABLE_FRAME5        0x00
#define _WIN6_B_GRIDENT_ENABLE_FRAME5        0x00

#define _WIN6_PERGRADIENT_LEVEL_FRAME5       0x00     // 000-111
#define _WIN6_GRIDENT_ENABLE_FRAME5          0x00
#define _WIN6_GRIDENT_DIRECTION_FRAME5       0x00

#define _WIN6_STATURATED_ENABLE_FRAME5          0x00
#define _WIN6_REVERSEDCOLORMODE_ENABLE_FRAME5   0x00

//--------------------------------------------------
// Description  : Window6 style for OSDTestFrame5
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN6_STYLE_FRAME5[] =
{
    WINNO(6),
    
    // 100h-byte0
    ((_WIN6_SHADOW_COLOR_FRAME5 & 0x10) << 3) | ((_WIN6_BORDER_COLOR_FRAME5 & 0x10) << 2) | ((_WIN6_SHADOW_WIDTH_FRAME5 & 0x07) << 3) | (_WIN6_SHADOW_HEIGHT_FRAME5 & 0x07),
    // 100h-byte1
    ((_WIN6_SHADOW_COLOR_FRAME5 & 0x0f) << 4) | (_WIN6_BORDER_COLOR_FRAME5 & 0x0f),
    // 100h-byte2
    ((_WIN6_R_GRIDENT_POLARITY_FRAME5 & 0x01) << 7) | ((_WIN6_G_GRIDENT_POLARITY_FRAME5 & 0x01) << 6) | ((_WIN6_B_GRIDENT_POLARITY_FRAME5 & 0x01) << 5) | 
    ((_WIN6_GRIDENT_LEVEL_FRAME5 & 0x07) << 3) | ((_WIN6_R_GRIDENT_ENABLE_FRAME5 & 0x01) << 2) | ((_WIN6_G_GRIDENT_ENABLE_FRAME5 & 0x01) << 1) | (_WIN6_B_GRIDENT_ENABLE_FRAME5 & 0x01),

    // 103h-byte0 
    ((_WIN6_SHADOW_COLOR_FRAME5 & 0x20) << 2) | ((_WIN6_BORDER_COLOR_FRAME5 & 0x20) << 1) | (_WIN6_COLOR_FRAME5 & 0x20) | ((_WIN6_STATURATED_ENABLE_FRAME5 & 0x01) << 4) | ((_WIN6_REVERSEDCOLORMODE_ENABLE_FRAME5 & 0x01) << 3),
    // 103h-byte1
    ((_WIN6_PERGRADIENT_LEVEL_FRAME5 & 0x07) << 5) | (_WIN6_COLOR_FRAME5 & 0x1F),
    // 103h-bye2
    ((_WIN6_GRIDENT_ENABLE_FRAME5 & 0x01) << 6) | ((_WIN6_GRIDENT_DIRECTION_FRAME5 & 0x01) << 5) | ((_WIN6_SHADOW_ENABLE_FRAME5 & 0x01) << 4) | ((_WIN6_STYLE_FRAME5 & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 7-------------------------------------
#define _WIN7_COLOR_FRAME5                   0x01

//----------------------window type-----------------------------------
#define _WIN7_STYLE_FRAME5                   _WIN_SHADOW_TYPE1

#define _WIN7_SHADOW_COLOR_FRAME5            0x38       // 0x3f
#define _WIN7_BORDER_COLOR_FRAME5            0x1e
#define _WIN7_SHADOW_WIDTH_FRAME5            0x07      // 000-111
#define _WIN7_SHADOW_HEIGHT_FRAME5           0x07      // 000-111
#define _WIN7_SHADOW_ENABLE_FRAME5           0x01

//----------------------grident function------------------------------
#define _WIN7_R_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN7_G_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN7_B_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN7_GRIDENT_LEVEL_FRAME5           0x00      // 00-11: 1-4

#define _WIN7_R_GRIDENT_ENABLE_FRAME5        0x00
#define _WIN7_G_GRIDENT_ENABLE_FRAME5        0x00
#define _WIN7_B_GRIDENT_ENABLE_FRAME5        0x00

#define _WIN7_PERGRADIENT_LEVEL_FRAME5       0x00     // 000-111
#define _WIN7_GRIDENT_ENABLE_FRAME5          0x01
#define _WIN7_GRIDENT_DIRECTION_FRAME5       0x00

#define _WIN7_STATURATED_ENABLE_FRAME5          0x01
#define _WIN7_REVERSEDCOLORMODE_ENABLE_FRAME5   0x00

//--------------------------------------------------
// Description  : Window7 style for OSDTestFrame5
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN7_STYLE_FRAME5[] =
{
    WINNO(7),
    
    // 100h-byte0
    ((_WIN7_SHADOW_COLOR_FRAME5 & 0x10) << 3) | ((_WIN7_BORDER_COLOR_FRAME5 & 0x10) << 2) | ((_WIN7_SHADOW_WIDTH_FRAME5 & 0x07) << 3) | (_WIN7_SHADOW_HEIGHT_FRAME5 & 0x07),
    // 100h-byte1
    ((_WIN7_SHADOW_COLOR_FRAME5 & 0x0f) << 4) | (_WIN7_BORDER_COLOR_FRAME5 & 0x0f),
    // 100h-byte2
    ((_WIN7_R_GRIDENT_POLARITY_FRAME5 & 0x01) << 7) | ((_WIN7_G_GRIDENT_POLARITY_FRAME5 & 0x01) << 6) | ((_WIN7_B_GRIDENT_POLARITY_FRAME5 & 0x01) << 5) | 
    ((_WIN7_GRIDENT_LEVEL_FRAME5 & 0x07) << 3) | ((_WIN7_R_GRIDENT_ENABLE_FRAME5 & 0x01) << 2) | ((_WIN7_G_GRIDENT_ENABLE_FRAME5 & 0x01) << 1) | (_WIN7_B_GRIDENT_ENABLE_FRAME5 & 0x01),

    // 103h-byte0 
    ((_WIN7_SHADOW_COLOR_FRAME5 & 0x20) << 2) | ((_WIN7_BORDER_COLOR_FRAME5 & 0x20) << 1) | (_WIN7_COLOR_FRAME5 & 0x20) | ((_WIN7_STATURATED_ENABLE_FRAME5 & 0x01) << 4) | ((_WIN7_REVERSEDCOLORMODE_ENABLE_FRAME5 & 0x01) << 3),
    // 103h-byte1
    ((_WIN7_PERGRADIENT_LEVEL_FRAME5 & 0x07) << 5) | (_WIN7_COLOR_FRAME5 & 0x1F),
    // 103h-bye2
    ((_WIN7_GRIDENT_ENABLE_FRAME5 & 0x01) << 6) | ((_WIN7_GRIDENT_DIRECTION_FRAME5 & 0x01) << 5) | ((_WIN7_SHADOW_ENABLE_FRAME5 & 0x01) << 4) | ((_WIN7_STYLE_FRAME5 & 0x07) << 1) | 0x01,
};

//--------------------------------------------------------------------
//----------------------Window 8-------------------------------------
#define _WIN8_COLOR_FRAME5                   0x21

//----------------------window type-----------------------------------
#define _WIN8_STYLE_FRAME5                   _WIN_BORDER

#define _WIN8_SHADOW_COLOR_FRAME5            0x30
#define _WIN8_BORDER_COLOR_FRAME5            0x30
#define _WIN8_SHADOW_WIDTH_FRAME5            0x07      // 000-111
#define _WIN8_SHADOW_HEIGHT_FRAME5           0x07      // 000-111
#define _WIN8_SHADOW_ENABLE_FRAME5           0x01

//----------------------grident function------------------------------
#define _WIN8_R_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN8_G_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN8_B_GRIDENT_POLARITY_FRAME5      0x00      // 0: decrease, 1: increase
#define _WIN8_GRIDENT_LEVEL_FRAME5           0x00      // 00-11: 1-4

#define _WIN8_R_GRIDENT_ENABLE_FRAME5        0x00
#define _WIN8_G_GRIDENT_ENABLE_FRAME5        0x00
#define _WIN8_B_GRIDENT_ENABLE_FRAME5        0x00

#define _WIN8_PERGRADIENT_LEVEL_FRAME5       0x00     // 000-111
#define _WIN8_GRIDENT_ENABLE_FRAME5          0x00
#define _WIN8_GRIDENT_DIRECTION_FRAME5       0x00

#define _WIN8_STATURATED_ENABLE_FRAME5          0x01
#define _WIN8_REVERSEDCOLORMODE_ENABLE_FRAME5   0x01

//--------------------------------------------------
// Description  : Window8 style for OSDTestFrame5
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN8_STYLE_FRAME5[] =
{
    WINNO(8),
    
    // 100h-byte0
    ((_WIN8_SHADOW_COLOR_FRAME5 & 0x10) << 3) | ((_WIN8_BORDER_COLOR_FRAME5 & 0x10) << 2) | ((_WIN8_SHADOW_WIDTH_FRAME5 & 0x07) << 3) | (_WIN8_SHADOW_HEIGHT_FRAME5 & 0x07),
    // 100h-byte1
    ((_WIN8_SHADOW_COLOR_FRAME5 & 0x0f) << 4) | (_WIN8_BORDER_COLOR_FRAME5 & 0x0f),
    // 100h-byte2
    ((_WIN8_R_GRIDENT_POLARITY_FRAME5 & 0x01) << 7) | ((_WIN8_G_GRIDENT_POLARITY_FRAME5 & 0x01) << 6) | ((_WIN8_B_GRIDENT_POLARITY_FRAME5 & 0x01) << 5) | 
    ((_WIN8_GRIDENT_LEVEL_FRAME5 & 0x07) << 3) | ((_WIN8_R_GRIDENT_ENABLE_FRAME5 & 0x01) << 2) | ((_WIN8_G_GRIDENT_ENABLE_FRAME5 & 0x01) << 1) | (_WIN8_B_GRIDENT_ENABLE_FRAME5 & 0x01),

    // 103h-byte0 
    ((_WIN8_SHADOW_COLOR_FRAME5 & 0x20) << 2) | ((_WIN8_BORDER_COLOR_FRAME5 & 0x20) << 1) | (_WIN8_COLOR_FRAME5 & 0x20) | ((_WIN8_STATURATED_ENABLE_FRAME5 & 0x01) << 4) | ((_WIN8_REVERSEDCOLORMODE_ENABLE_FRAME5 & 0x01) << 3),
    // 103h-byte1
    ((_WIN8_PERGRADIENT_LEVEL_FRAME5 & 0x07) << 5) | (_WIN8_COLOR_FRAME5 & 0x1F),
    // 103h-bye2
    ((_WIN8_GRIDENT_ENABLE_FRAME5 & 0x01) << 6) | ((_WIN8_GRIDENT_DIRECTION_FRAME5 & 0x01) << 5) | ((_WIN8_SHADOW_ENABLE_FRAME5 & 0x01) << 4) | ((_WIN8_STYLE_FRAME5 & 0x07) << 1) | 0x01,
}; 


//----------------------Window 9-------------------------------------
#define _WIN9_COLOR_FRAME6                   0x2a

//----------------------window type-----------------------------------
#define _WIN9_STYLE_FRAME6                   _WIN_3DBUTTON_TYPE2

#define _WIN9_SHADOW_COLOR_FRAME6            0x2d
#define _WIN9_BORDER_COLOR_FRAME6            0x2c
#define _WIN9_SHADOW_WIDTH_FRAME6            0x00      // 000-111
#define _WIN9_SHADOW_HEIGHT_FRAME6           0x00      // 000-111
#define _WIN9_Shadow_Enable_FRAME6           0x01

//----------------------grident function------------------------------
#define _WIN9_R_GRIDENT_POLARITY_FRAME6      0x00      // 0: decrease, 1: increase
#define _WIN9_G_GRIDENT_POLARITY_FRAME6      0x00      // 0: decrease, 1: increase
#define _WIN9_B_GRIDENT_POLARITY_FRAME6      0x00      // 0: decrease, 1: increase
#define _WIN9_GRIDENT_LEVEL_FRAME6           0x00      // 00-11: 1-4

#define _WIN9_R_GRIDENT_ENABLE_FRAME6        0x00
#define _WIN9_G_GRIDENT_ENABLE_FRAME6        0x00
#define _WIN9_B_GRIDENT_ENABLE_FRAME6        0x00

#define _WIN9_PERGRADIENT_LEVEL_FRAME6       0x00     // 000-111
#define _WIN9_GRIDENT_ENABLE_FRAME6          0x00
#define _WIN9_GRIDENT_DIRECTION_FRAME6       0x00

#define _WIN9_STATURATED_ENABLE_FRAME6          0x00
#define _WIN9_REVERSEDCOLORMODE_ENABLE_FRAME6   0x00

//--------------------------------------------------
// Description  : Window9 style for OSDTestFrame6
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSD_WIN9_STYLE_FRAME5[] =
{
    WINNO(9),
    
    // 100h-byte0
    ((_WIN9_SHADOW_COLOR_FRAME6 & 0x10) << 3) | ((_WIN9_BORDER_COLOR_FRAME6 & 0x10) << 2) | ((_WIN9_SHADOW_WIDTH_FRAME6 & 0x07) << 3) | (_WIN9_SHADOW_HEIGHT_FRAME6 & 0x07),
    // 100h-byte1
    ((_WIN9_SHADOW_COLOR_FRAME6 & 0x0f) << 4) | (_WIN9_BORDER_COLOR_FRAME6 & 0x0f),
    // 100h-byte2
    ((_WIN9_R_GRIDENT_POLARITY_FRAME6 & 0x01) << 7) | ((_WIN9_G_GRIDENT_POLARITY_FRAME6 & 0x01) << 6) | ((_WIN9_B_GRIDENT_POLARITY_FRAME6 & 0x01) << 5) | 
    ((_WIN9_GRIDENT_LEVEL_FRAME6 & 0x07) << 3) | ((_WIN9_R_GRIDENT_ENABLE_FRAME6 & 0x01) << 2) | ((_WIN9_G_GRIDENT_ENABLE_FRAME6 & 0x01) << 1) | (_WIN9_B_GRIDENT_ENABLE_FRAME6 & 0x01),

    // 103h-byte0 
    ((_WIN9_SHADOW_COLOR_FRAME6 & 0x20) << 2) | ((_WIN9_BORDER_COLOR_FRAME6 & 0x20) << 1) | (_WIN9_COLOR_FRAME6 & 0x20) | ((_WIN9_STATURATED_ENABLE_FRAME6 & 0x01) << 4) | ((_WIN9_REVERSEDCOLORMODE_ENABLE_FRAME6 & 0x01) << 3),
    // 103h-byte1
    ((_WIN9_PERGRADIENT_LEVEL_FRAME6 & 0x07) << 5) | (_WIN9_COLOR_FRAME6 & 0x1F),
    // 103h-bye2
    ((_WIN9_GRIDENT_ENABLE_FRAME6 & 0x01) << 6) | ((_WIN9_GRIDENT_DIRECTION_FRAME6 & 0x01) << 5) | ((_WIN9_Shadow_Enable_FRAME6 & 0x01) << 4) | ((_WIN9_STYLE_FRAME6 & 0x07) << 1) | 0x01,
};  

//--------------------------------------------------
// Description  : Character command for OSDTestFrame10
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_OSDCHARACTERCOMMAND_FRAME10[] =  // 3x8 = 24
{
    // row 0: 8 font 
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x00, 0x00),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x01), COLORSELECT(0x01, 0x02),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x02), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x03), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x04), COLORSELECT(0x07, 0x08),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x05), COLORSELECT(0x09, 0x0a),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x06), COLORSELECT(0x0b, 0x0c),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x07), COLORSELECT(0x0d, 0x0e),

    // row 1: 8 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x00, 0x00),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x01), COLORSELECT(0x02, 0x03),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x02), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x03), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x04), COLORSELECT(0x07, 0x08),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x05), COLORSELECT(0x09, 0x0a),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x06), COLORSELECT(0x0b, 0x0c),
    _1BIT_TYPE1 | CHAR_WIDTH(0x08), CHARSELECT(0x07), COLORSELECT(0x0e, 0x0f),

    // row 2: 8 font
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x00), COLORSELECT(0x00, 0x01),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x01), COLORSELECT(0x02, 0x03),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x02), COLORSELECT(0x03, 0x04),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x03), COLORSELECT(0x05, 0x06),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x04), COLORSELECT(0x07, 0x08),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x05), COLORSELECT(0x09, 0x0a),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x06), COLORSELECT(0x0b, 0x0c),
    _1BIT_TYPE5 | CHAR_WIDTH(0x08), CHARSELECT(0x07), COLORSELECT(0x0e, 0x0f),

    // row 3 2-bit font color select 0-15  : 8 font
    _2BIT_TYPE1 | ((COLOR00(0x04) & 0x08) << 3) | ((COLOR11(0x00) & 0x07) << 1) | ((COLOR00(0x04) & 0x04) >> 2), 
    ((COLOR01(0x03) & 0x08) << 6) | CHARSELECT(0x04), 
    ((COLOR00(0x04) & 0x03) << 6) | ((COLOR10(0x04) & 0x07) << 3) | (COLOR01(0x03) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x0d) & 0x08) << 3) | ((COLOR11(0x09) & 0x07) << 1) | ((COLOR00(0x0d) & 0x04) >> 2), 
    ((COLOR01(0x05) & 0x08) << 6) | CHARSELECT(0x05), 
    ((COLOR00(0x0d) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x05) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x05) & 0x08) << 3) | ((COLOR11(0x02) & 0x07) << 1) | ((COLOR00(0x05) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x06), 
    ((COLOR00(0x05) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x07) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x0e) & 0x08) << 3) | ((COLOR11(0x0b) & 0x07) << 1) | ((COLOR00(0x0e) & 0x04) >> 2), 
    ((COLOR01(0x01) & 0x08) << 6) | CHARSELECT(0x07), 
    ((COLOR00(0x0e) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x01) & 0x07),
        
    _2BIT_TYPE1 | ((COLOR00(0x06) & 0x08) << 3) | ((COLOR11(0x04) & 0x07) << 1) | ((COLOR00(0x06) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x08), 
    ((COLOR00(0x06) & 0x03) << 6) | ((COLOR10(0x05) & 0x07) << 3) | (COLOR01(0x03) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x0f) & 0x08) << 3) | ((COLOR11(0x0d) & 0x07) << 1) | ((COLOR00(0x0f) & 0x04) >> 2), 
    ((COLOR01(0x05) & 0x08) << 6) | CHARSELECT(0x09), 
    ((COLOR00(0x0f) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x05) & 0x07),

    _2BIT_TYPE1 | ((COLOR00(0x07) & 0x08) << 3) | ((COLOR11(0x06) & 0x07) << 1) | ((COLOR00(0x07) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x0a), 
    ((COLOR00(0x07) & 0x03) << 6) | ((COLOR10(0x05) & 0x07) << 3) | (COLOR01(0x07) & 0x07),
    
    _2BIT_TYPE1 | ((COLOR00(0x08) & 0x08) << 3) | ((COLOR11(0x0f) & 0x07) << 1) | ((COLOR00(0x08) & 0x04) >> 2), 
    ((COLOR01(0x01) & 0x08) << 6) | CHARSELECT(0x0b), 
    ((COLOR00(0x08) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x01) & 0x07),

    // row 4, 2-bit font color select 16-31 : 8 font 
    _2BIT_TYPE2 | ((COLOR00(0x00) & 0x08) << 3) | ((COLOR11(0x01) & 0x07) << 1) | ((COLOR00(0x00) & 0x04) >> 2), 
    ((COLOR01(0x0e) & 0x08) << 6) | CHARSELECT(0x04), 
    ((COLOR00(0x00) & 0x03) << 6) | ((COLOR10(0x0c) & 0x07) << 3) | (COLOR01(0x0e) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x09) & 0x08) << 3) | ((COLOR11(0x0a) & 0x07) << 1) | ((COLOR00(0x09) & 0x04) >> 2), 
    ((COLOR01(0x0d) & 0x08) << 6) | CHARSELECT(0x05), 
    ((COLOR00(0x09) & 0x03) << 6) | ((COLOR10(0x08) & 0x07) << 3) | (COLOR01(0x0d) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x01) & 0x08) << 3) | ((COLOR11(0x03) & 0x07) << 1) | ((COLOR00(0x01) & 0x04) >> 2), 
    ((COLOR01(0x07) & 0x08) << 6) | CHARSELECT(0x06), 
    ((COLOR00(0x09) & 0x03) << 6) | ((COLOR10(0x04) & 0x07) << 3) | (COLOR01(0x07) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x0a) & 0x08) << 3) | ((COLOR11(0x0c) & 0x07) << 1) | ((COLOR00(0x0a) & 0x04) >> 2), 
    ((COLOR01(0x01) & 0x08) << 6) | CHARSELECT(0x07), 
    ((COLOR00(0x0a) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x01) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x02) & 0x08) << 3) | ((COLOR11(0x05) & 0x07) << 1) | ((COLOR00(0x02) & 0x04) >> 2), 
    ((COLOR01(0x03) & 0x08) << 6) | CHARSELECT(0x08), 
    ((COLOR00(0x02) & 0x03) << 6) | ((COLOR10(0x05) & 0x07) << 3) | (COLOR01(0x03) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x0b) & 0x08) << 3) | ((COLOR11(0x0e) & 0x07) << 1) | ((COLOR00(0x0b) & 0x04) >> 2), 
    ((COLOR01(0x05) & 0x08) << 6) | CHARSELECT(0x09), 
    ((COLOR00(0x0b) & 0x03) << 6) | ((COLOR10(0x01) & 0x07) << 3) | (COLOR01(0x05) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x07) & 0x08) << 3) | ((COLOR11(0x06) & 0x07) << 1) | ((COLOR00(0x07) & 0x04) >> 2), 
    ((COLOR01(0x0f) & 0x08) << 6) | CHARSELECT(0x0a), 
    ((COLOR00(0x07) & 0x03) << 6) | ((COLOR10(0x0d) & 0x07) << 3) | (COLOR01(0x0f) & 0x07),

    _2BIT_TYPE2 | ((COLOR00(0x08) & 0x08) << 3) | ((COLOR11(0x08) & 0x07) << 1) | ((COLOR00(0x08) & 0x04) >> 2), 
    ((COLOR01(0x03) & 0x08) << 6) | CHARSELECT(0x0b), 
    ((COLOR00(0x02) & 0x03) << 6) | ((COLOR10(0x00) & 0x07) << 3) | (COLOR01(0x01) & 0x07),
    
    // row 5 : 8 font
    _4BIT_TYPE | FOURBITBGCOLOR(0x00), CHARSELECT(0x07), 0x00,
    _4BIT_TYPE | FOURBITBGCOLOR(0x01), CHARSELECT(0x08), 0x55,
    _4BIT_TYPE | FOURBITBGCOLOR(0x02), CHARSELECT(0x09), 0xaa,
    _4BIT_TYPE | FOURBITBGCOLOR(0x03), CHARSELECT(0x0a), 0xff,
    _4BIT_TYPE | FOURBITBGCOLOR(0x04), CHARSELECT(0x0b), 0x22,
    _4BIT_TYPE | FOURBITBGCOLOR(0x05), CHARSELECT(0x0c), 0x44,
    _4BIT_TYPE | FOURBITBGCOLOR(0x06), CHARSELECT(0x0d), 0x66,
    _4BIT_TYPE | FOURBITBGCOLOR(0x07), CHARSELECT(0x0e), 0x88,

    // row 6 : 8 font
    _4BIT_TYPE | FOURBITBGCOLOR(0x08), CHARSELECT(0x07), 0x33,
    _4BIT_TYPE | FOURBITBGCOLOR(0x09), CHARSELECT(0x08), 0x11,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0a), CHARSELECT(0x09), 0xbb,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0b), CHARSELECT(0x0a), 0xcc,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0c), CHARSELECT(0x0b), 0x01,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0d), CHARSELECT(0x0c), 0x23,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0e), CHARSELECT(0x0d), 0x45,
    _4BIT_TYPE | FOURBITBGCOLOR(0x0f), CHARSELECT(0x0e), 0x67,

    // row 7 : 4 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1 "n"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1  "n"
    _1BIT_TYPE2 | 0x02,             CHARSELECT(0x10), BLANKCOLOR(0x12),  
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1 "n"
    _1BIT_TYPE3 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 400 "0"
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1 "n"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x01), COLORSELECT(0x02, 0x0b),  // FONT 1  "n"
   
    // row 8 : 4 font
    _1BIT_TYPE1 | CHAR_WIDTH(0x0a), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE5 | CHAR_WIDTH(0x09), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE6,            CHARSELECT(0x04), BLANKCOLOR(0x12),     
    _1BIT_TYPE3 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 780 "d"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 780 "d"
    _1BIT_TYPE1 | CHAR_WIDTH(0x0c), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE5 | CHAR_WIDTH(0x0c), CHARSELECT(0x58), COLORSELECT(0x02, 0x0b),  // FONT 600  "A"
    _1BIT_TYPE4 | CHAR_WIDTH(0x0c), CHARSELECT(0x90), COLORSELECT(0x03, 0x0f),  // FONT 780 "d"
};

typedef struct
{
    BYTE b6ShadowColor : 6;
    BYTE b6BorderColor : 6;
    BYTE b6WindowColor : 6;
    BYTE b3ShaBorWidth : 3;
    BYTE b3ShaBorHeight : 3;

    BYTE b1RGradientPloarity : 1;
    BYTE b1GGradientPloarity : 1;
    BYTE b1BGradientPloarity : 1;

    BYTE b2GradientLevel : 2;
    BYTE b1RGradientEn : 1;
    BYTE b1GGradientEn : 1;
    BYTE b1BGradientEn : 1;

    BYTE b1SaturatedEn : 1;
    BYTE b1ReversedEn : 1;
    BYTE b1WinRefDelay : 1;
    BYTE b1WinBorderPri : 1;
    BYTE b1GradientLevelExt : 1;
    BYTE b3GradientPerLevel : 3;
    BYTE b1BlendFuncEn : 1;
    BYTE b1GradientFuncEn : 1;
    BYTE b1GradientDirect : 1;
    BYTE b1ShadowBorder3DEn : 1;
    BYTE b3WinType : 3;
    BYTE b1WindowEn : 1;

    WORD b12WindowHStart : 12;
    WORD b12WindowVStart : 12;
    WORD b12WindowHEnd : 12;
    WORD b12WindowVEnd : 12;
      
} QCOSDWindowInfo;


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

// OSD Related Test Functions
void ScalerQCOsdOverlayEnable(bit bEnable, bit bOsdCircuitEnable);
void ScalerQCOsdSetBlendingLevel(BYTE ucLevel);
void ScalerQCOsdLoadColorPalatte();
void ScalerQCOsdSetRowCommand(BYTE *pRowMapTable, BYTE ucRowNumber);
void ScalerQCOsdSetCharacterCommand(BYTE *pCharTable, WORD usAddress, WORD usTableLength);
void ScalerQCOsdFirstSetPosition(WORD usHorizontalOffset, WORD usVerticalOffset);
void ScalerQCOsdSetDisplayZone(BYTE ucDisplayType);
void ScalerQCOsdSecondSetPosition(WORD usHorizontalOffset, WORD usVerticalOffset);
void ScalerQCOsdEnableWindowHighThanFont(BYTE ucWinNum, bit ucEnable);
void ScalerQCOsdSetBlendingType2(BYTE ucColorLUT, bit bEnable, BYTE ucColorType);
void ScalerQCOsdSetCharShadowBorderColor(BYTE ucColorSelect);
void ScalerQCOsdVerticalStartInputSourceSelect(bit bEnable);
void ScalerQCOsdSetBlendingType1(BYTE ucType);
void ScalerQCOsdDoubleWidthHeightEnable(BYTE ucEnable);
void ScalerQCOsdRotatedFunctionEnable(bit bEnable);
void ScalerQCOsdBlinkingFunctionEnable(bit bEnable);
void ScalerQCOsdSetBaseAddressOffset(WORD usFontSelectAddress, WORD usFontBaseAddress);
void ScalerQCOsdSpecialFunctionSelect(BYTE ucTypeSelect, bit bEnable);
void ScalerQCOsdVerticalBoundaryFunctionEnable(bit bEnable);
void ScalerQCOsd2OSDFontFuncitonEnable(bit bEnable);
void ScalerQCOsdFontARefSelect(bit bEnable);
void ScalerQCOsdFontBRefSelect(bit bEnable);
void ScalerQCOsdDisplayBaseSelect(BYTE ucBaseSelect);
void ScalerQCOsdSetRowCommandBase0(BYTE ucRowCommand);
void ScalerQCOsdSetRowCommandBase1(BYTE ucRowCommand);
void ScalerQCOsdSetFontSelectBase0(WORD usBaseAddress);
void ScalerQCOsdSetFontSelectBase1(WORD usBaseAddress);
void ScalerQCOsdSetVBoundary(WORD usUpperBoundary, WORD usLowerBoundary);
void ScalerQCOsdSetWin7SpecialBlending(BYTE ucType, BYTE ucFontBlendingType);
void ScalerQCOsdSetWin6SpecialBlending(BYTE ucFontBlendingType, bit bEnable);
void ScalerQCOsdSet2BitFontCharSelectOffset(BYTE ucOffset);
void ScalerQCOsdSetFontABDelay(WORD usHorDelay, WORD usVerDelay, BYTE ucFontAB);
void ScalerQCOsdSetHighLightWindow(BYTE ucWinNum, BYTE ucFColor, BYTE ucBColor, BYTE ucBorderColor, bit bEnable);
void ScalerQCOsdBlankCommand64ColorEnable(bit bEnable);
void ScalerQCOsd2BitCharCommandSwapFunctionEnable(bit bEnable);
void ScalerQCOsdSetWPFunction(BYTE ucByteSelect, BYTE ucBitSelect, bit bEnable);
void ScalerQCOsdSetWPFunctionTestFont(WORD usAddress, BYTE ucByteSelect, BYTE ucValue);
void ScalerQCOsdPannelPitchSet(WORD usHorizontalPitch, WORD usVerticalPitch);
void ScalerQCOsdSetOsdLengthWidth(WORD usLength, WORD usWidth, BYTE ucFontOsdNumber);
void ScalerQCOsdSetRowNumber(BYTE ucRowNumber, BYTE ucFontIndex);
void ScalerQCOsdNewRotatedFunctionControl(BYTE ucRotateDirection, BYTE ucFontMapEnable, BYTE ucFontACommandEnable, BYTE ucFontBCommandEnable, bit bEnable);
void ScalerQCOsd3DFunctionControl(BYTE ucInputMode, BYTE ucOutputMode, bit bEnable);
void ScalerQCOsdDrawWindow(WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE *pStyle, BYTE ucAddWin);
void ScalerQCOsdSetWindowSpecialColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue, BYTE ucWinIndex);
void ScalerQCOsdEnableWindowChessBoardFunction(BYTE ucColor1, BYTE ucColor2, BYTE ucWinIndex, BYTE ucAddWin, bit bEnable);
void ScalerQCOsdDisableWindow(BYTE ucWinNumber, BYTE ucAddWin, bit bEnable);
void ScalerQCOsdGradientExtension(BYTE ucWinNumber, BYTE ucRed, BYTE ucGreen, BYTE ucBlue, bit bEnable);
void ScalerQCOsdGridFunction(BYTE ucWinNumber, BYTE ucGridWidth, BYTE ucGridColor, BYTE ucEnable, BYTE ucGridOffset, WORD ucGridPitch);
void ScalerQCOsdWindow3DFunction(BYTE ucWinNumber, WORD usWindowShift, BYTE ucAddWin);
void ScalerQCOsdWindowRotationFunction(BYTE ucWinNumber, BYTE ucAddWin, bit bEnable);
void ScalerQCOsdLoadFontData(BYTE *pFontData, WORD usAddress, WORD usFontNumber, BYTE ucRoateted, BYTE ucCompression);
void ScalerQCOsdFxPutProporString(BYTE *pArray, WORD usFontPointer, BYTE ucLength);

void ScalerQCOsdSetWindowRefAndBorderPri(BYTE ucWinNum, BYTE ucWinExt, bit bWinRef, bit bBorderPri);
void ScalerQCOsd4BitFontBackGroundRef(bit bTypeSel);
void ScalerQCOsdHDelayStepUnit(bit bTypeSel);
void ScalerQCOsdDrawWin(BYTE ucWinNum, BYTE ucWinExt, QCOSDWindowInfo *stOSDInfo);

void ScalerQCOsdTestFrame0(void);
void ScalerQCOsdTestFrame1(void);
void ScalerQCOsdTestFrame2(void);
void ScalerQCOsdTestFrame3(void);
void ScalerQCOsdTestFrame4(void);
void ScalerQCOsdTestFrame5(void);
void ScalerQCOsdTestFrame6(void);
void ScalerQCOsdTestFrame7(void);
void ScalerQCOsdTestFrame8(void);
void ScalerQCOsdTestFrame9(void);
void ScalerQCOsdTestFrame10(void);

bit ScalerQCOsdTestProc(void);    
bit ScalerQCOSDTest(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//---------------------------------------------------------
//                  OSD Test Functions
//---------------------------------------------------------

//-----------------------------------------
// Description  : Overlay Port Enable
// Input Value  : ucEnable              
// Output Value : None
//-----------------------------------------
void ScalerQCOsdOverlayEnable(bit bEnable, bit bOsdCircuitEnable)
{    
	ScalerTimerWaitForEvent(_EVENT_DVS);

	if(bEnable == _DISABLE)
    {        
        ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT0, bEnable);
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x00);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
     
    pData[2] = (pData[0] & ~_BIT0) | bOsdCircuitEnable;
	    	    	    	    	    	      
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x00);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    if(bEnable == _ENABLE)
    {
        ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT0, bEnable);
        ScalerTimerWaitForEvent(_EVENT_DVS);
    } 
}

//-----------------------------------------
// Description  : Set Blending Level
// Input Value  : ucLevel              
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetBlendingLevel(BYTE ucLevel)
{      
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~(_BIT4 | _BIT3 | _BIT2), ((ucLevel & 0x07) << 2));
}

//-----------------------------------------
// Description  : Load Color Palatte
// Input Value  : None              
// Output Value : None
//-----------------------------------------
void ScalerQCOsdLoadColorPalatte(void)
{   
    pData[0] = 0;
    
    for(PDATA_WORD(2) = 0; PDATA_WORD(2) < 256; PDATA_WORD(2) += 85)
    {
    	for(PDATA_WORD(3) = 0; PDATA_WORD(3) < 256; PDATA_WORD(3) += 85)
    	{
    	    for(PDATA_WORD(4) = 0; PDATA_WORD(4) < 256; PDATA_WORD(4) += 85)
    	    {  
    	    	ScalerSetByte(CM_6E_OVERLAY_LUT_ADDR, (0x80 | pData[0]));        
    	    	pData[1] = PDATA_WORD(2);
    	    	pData[2] = PDATA_WORD(3);
    	    	pData[3] = PDATA_WORD(4);
    	    	ScalerWrite(CM_6F_COLOR_LUT_PORT, 3, &pData[1], _NON_AUTOINC);    
    	    	pData[0] += 1;                
    	    }
    	}
    }    	
    ScalerSetByte(CM_6E_OVERLAY_LUT_ADDR, 0x00);
}

//-----------------------------------------
// Description  : Set Row Command
// Input Value  : *pRowMapTable,
//                ucRowNumber
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetRowCommand(BYTE *pRowMapTable, BYTE ucRowNumber)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xD0);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x00);    

    ScalerWrite(CM_92_OSD_DATA_PORT, (ucRowNumber * 3), pRowMapTable, _NON_AUTOINC);
}

//-----------------------------------------
// Description  : Set Character Command
// Input Value  : *pCharTable,
//                usAddress,
//                usTableLength
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetCharacterCommand(BYTE *pCharTable, WORD usAddress, WORD usTableLength)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, (0xD0 | (HIBYTE(usAddress) & 0x0F)));
    ScalerSetByte(CM_91_OSD_ADDR_LSB, LOBYTE(usAddress)); 
    
    ScalerWrite(CM_92_OSD_DATA_PORT, usTableLength, pCharTable, _NON_AUTOINC);    
}

//-----------------------------------------
// Description  : Set first OSD reference Position
// Input Value  : usHorizontalOffset,
//                usVerticalOffset,
// Output Value : None
//-----------------------------------------
void ScalerQCOsdFirstSetPosition(WORD usHorizontalOffset, WORD usVerticalOffset)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);    
    
    if((pData[0] & _BIT4) == _BIT4)
    {    
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x00);            
    	
    	pData[0] = (BYTE)(usVerticalOffset >> 3);                                    
    	pData[1] = (BYTE)(usHorizontalOffset >> 2);                 
    	pData[2] = ((BYTE)((usHorizontalOffset & 0x03) << 6)) | ((BYTE)((usVerticalOffset & 0x07) << 3)) | 0x01;
    	ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
    	
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);  
        pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);   
    	
    	pData[2] = (pData[0] & (~( _BIT3 | _BIT2))) | ((BYTE)((usHorizontalOffset & 0xC00) >> 8));  
    	
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);  
    	ScalerWrite(CM_92_OSD_DATA_PORT, 1, &pData[2], _NON_AUTOINC); 
        
    	// Frame control register 000h has their own double buffer, must wait for next dvs
    	ScalerTimerWaitForEvent(_EVENT_DVS);
    }
    else
    {    
    	usHorizontalOffset = usHorizontalOffset / 4; 
    	usVerticalOffset = usVerticalOffset; 
    
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x00);  
        
    	pData[0] = (BYTE)(usVerticalOffset >> 3);                                                                                                    //First Vertical Delay[10:3]
    	pData[1] = (BYTE)(usHorizontalOffset >> 2);                                                                                   //First Horizontal Delay [9:2]
    	pData[2] = ((BYTE)((usHorizontalOffset & 0x03) << 6)) | ((BYTE)((usVerticalOffset & 0x07) << 3)) | 0x01;    
    	ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
    	    
    	ScalerTimerWaitForEvent(_EVENT_DVS);
    }           
}

//-----------------------------------------
// Description  : Set OSD DisplayZone
// Input Value  : usDisplayType
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetDisplayZone(BYTE ucDisplayType)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x00);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0] & (~(_BIT1 | _BIT2))) | ((ucDisplayType & 0x03) << 1);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x00);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);
	ScalerTimerWaitForEvent(_EVENT_DVS);
}

//-----------------------------------------
// Description  : Set second OSD reference Position
// Input Value  : usHorizontalOffset,
//                usVerticalOffset
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSecondSetPosition(WORD usHorizontalOffset, WORD usVerticalOffset)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    

    if( (pData[0] & _BIT4) == _BIT4)
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x01);           
    	
    	pData[0] = (BYTE)(usVerticalOffset >> 3);                                                                                                   
    	pData[1] = (BYTE)(usHorizontalOffset >> 2);                                                                                  
    	pData[2] = ((BYTE)((usHorizontalOffset & 0x03) << 6)) | ((BYTE)((usVerticalOffset & 0x07) << 3));
    	ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
    	
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);   
        pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    	pData[2] = (pData[0] & (~( _BIT1 | _BIT0)))  | ((usHorizontalOffset & 0xC00) >> 10);                      
    	
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);   
        ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);
    	    
    	ScalerTimerWaitForEvent(_EVENT_DVS);
    }
    else
    {
    	usHorizontalOffset = usHorizontalOffset / 4; 
    	usVerticalOffset = usVerticalOffset; 
    	
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x01);   
    	
    	pData[0] = usVerticalOffset >> 3;                                                                                                   
    	pData[1] = (BYTE)(usHorizontalOffset >> 2);                                                                                  
    	pData[2] = ((BYTE)((usHorizontalOffset & 0x03) << 6)) | ((BYTE)((usVerticalOffset & 0x07) << 3));
    	ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);        

    	// Frame control register 000h has their own double buffer, must wait for next dvs
    	ScalerTimerWaitForEvent(_EVENT_DVS);
    }
            
}

//-----------------------------------------
// Description  : set window priority high than window
// Input Value  : ucWinNum,
//                bEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdEnableWindowHighThanFont(BYTE ucWinNum, bit bEnable)
{
    if((ucWinNum == WINNO(2)) || (ucWinNum == WINNO(8)) || (ucWinNum == WINNO(9)))
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
        pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    	if(ucWinNum == WINNO(8))
    	{
    	    pData[2] = (pData[0] & (~_BIT6)) | (((BYTE)bEnable) << 6);
    	}
    	else if(ucWinNum == WINNO(9))
    	{
            pData[2] = (pData[0] & (~_BIT5)) | (((BYTE)bEnable) << 5);
    	}
    	else if(ucWinNum == WINNO(2))
    	{
            pData[2] = (pData[0] & (~_BIT7)) | (((BYTE)bEnable) << 7);
    	}

        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
        ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);        
    }
    else if((ucWinNum == WINNO(4)) || (ucWinNum == WINNO(3)))
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
        pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
        
    	if(ucWinNum == WINNO(3))
    	{
            pData[2] = (pData[0] & (~_BIT0)) | (bEnable);
    	}
    	else if(ucWinNum == WINNO(4))
    	{
            pData[2] = (pData[0] & (~_BIT1)) | (((BYTE)bEnable) << 1);
    	}

        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
        ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);    
    }     
}

//-----------------------------------------
// Description  : Blending type2 setting
// Input Value  : ucColorLUT,
//                bEnable,
//                ucColorType 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetBlendingType2(BYTE ucColorLUT, bit bEnable, BYTE ucColorType)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0] & (~(_BIT4 | _BIT3 | _BIT2))) | ((ucColorType & 0x01) << 4) | ((ucColorLUT & 0x30) >> 2);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);    

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);   

    pData[2] = (pData[0] & (~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0))) | (((BYTE)bEnable) << 7) | (ucColorLUT & 0x0f);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);    
}

//-----------------------------------------
// Description  : Set Char Shadow/Border Color
// Input Value  : uc_COLORSELECT
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetCharShadowBorderColor(BYTE ucColorSelect)
{   
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);    

    pData[2] = (pData[0] & (~(_BIT0 | _BIT1))) | ((ucColorSelect & 0x30) >> 4); 

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);    

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    pData[2] = (pData[0] & 0x0F) | ((ucColorSelect & 0x0F) << 4); 

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]); 
}

//-----------------------------------------
// Description  : Select Vertical Start Input Source
// Input Value  : ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdVerticalStartInputSourceSelect(bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0]  & (~_BIT4)) | (((BYTE)bEnable) << 4);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);    
}

//-----------------------------------------
// Description  : Blending type1  setting
// Input Value  : ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetBlendingType1(BYTE ucType) 
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);    

    pData[2] = (pData[0] & (~(_BIT3 | _BIT2))) | ((ucType & 0x03) << 2);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);        
}

//-----------------------------------------
// Description  : Double OSD Width/Height
// Input Value  : ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdDoubleWidthHeightEnable(BYTE ucEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    pData[2] = (pData[0] & (~(_BIT0 | _BIT1))) | (ucEnable & 0x03);  

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);
}

//-----------------------------------------
// Description  : Enable Rotated Function
// Input Value  : ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdRotatedFunctionEnable(bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);    
  
    pData[2] = (pData[0] & (~_BIT0)) | bEnable;  

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);    
}

//-----------------------------------------
// Description  : Enable Blinking Function
// Input Value  : ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdBlinkingFunctionEnable(bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);    

    pData[2] = (pData[0] & (~_BIT1)) | (((BYTE)bEnable) << 1);
    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);    
}
   
//-----------------------------------------
// Description  : Set OSD font A Select Address and Font Base Address
// Input Value  : usFontSelectAddress,
//                usFontBaseAddress
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetBaseAddressOffset(WORD usFontSelectAddress, WORD usFontBaseAddress)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x04);       
    
    pData[0] = (BYTE)usFontSelectAddress;   
    pData[1] = ((usFontSelectAddress & 0x0F00) >> 4) | (usFontBaseAddress & 0x000F);
    pData[2] = ((usFontBaseAddress & 0x0FF0) >> 4);  //
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0B);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    pData[2] = (((usFontBaseAddress>>8) & 0x10) << 3) | (pData[0] & 0x7F); 

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0B);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);        
}

//-----------------------------------------
// Description  : Set OSD font B Select Address and Font Base Address
// Input Value  : usFontSelectAddress,
//                usFontBaseAddress
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSpecialFunctionSelect(BYTE ucTypeSelect, bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);    
    
    pData[2] = (pData[0] & (~(_BIT6 | _BIT7))) | ((ucTypeSelect & 0x01) << 6) | (((BYTE)bEnable) << 7);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);    
}

//-----------------------------------------
// Description  : Enable Vertical Boundary Function 
// Input Value  : ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdVerticalBoundaryFunctionEnable(bit bEnable)
{    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);  

    pData[2]  = (pData[0] & (~_BIT5)) | (((BYTE)bEnable) << 5);
    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]); 
}

//-----------------------------------------
// Description  : Enable 2 OSD Font Funciton 
// Input Value  : ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsd2OSDFontFuncitonEnable(bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);  

    pData[2] = (pData[0] & (~_BIT3)) | (((BYTE)bEnable) << 3);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]); 
}

//-----------------------------------------
// Description  : Font A reference OSD delay select
// Input Value  : ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdFontARefSelect(bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT); 

    pData[2] = (pData[0] & (~_BIT2)) | (((BYTE)bEnable) << 2);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]); 
}

//-----------------------------------------
// Description  : Font B reference OSD delay select
// Input Value  : ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdFontBRefSelect(bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    pData[2] = (pData[0] & (~_BIT1)) | (((BYTE)bEnable) << 1);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]); 
}

//-----------------------------------------
// Description  : Display Base Select 
// Input Value  : ucBaseSelect
// Output Value : None
//-----------------------------------------
void ScalerQCOsdDisplayBaseSelect(BYTE ucBaseSelect)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0] & (~_BIT0)) | (ucBaseSelect & 0x01);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]); 
}

//-----------------------------------------
// Description  : Set Row Command Base 0
// Input Value  : ucRowCommand
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetRowCommandBase0(BYTE ucRowCommand)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    ScalerSetByte(CM_92_OSD_DATA_PORT,ucRowCommand);  
}

//-----------------------------------------
// Description  : Set Row Command Base 1
// Input Value  : ucRowCommand
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetRowCommandBase1(BYTE ucRowCommand)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x08);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, ucRowCommand);  
}

//-----------------------------------------
// Description  : Set Font Select Base 0
// Input Value  : usBaseAddress
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetFontSelectBase0(WORD usBaseAddress)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x09);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0] & 0x0F) | ((usBaseAddress & 0x0F00) >> 4);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x09);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);     

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x09);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, LOBYTE(usBaseAddress));  
}

//-----------------------------------------
// Description  : Set Font Select Base 1
// Input Value  : usBaseAddress
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetFontSelectBase1(WORD usBaseAddress)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x09);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    pData[2] = (pData[0] & 0xF0) | ((usBaseAddress & 0x0F00) >> 8);
    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x09);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);  

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x09);   
    ScalerSetByte(CM_92_OSD_DATA_PORT, LOBYTE(usBaseAddress));  
}

//-----------------------------------------
// Description  : Set OSD Vertical Upper Boundary
// Input Value  : usUpperBoundary,
//                usLowerBoundary
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetVBoundary(WORD usUpperBoundary, WORD usLowerBoundary)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0A);   
    
    pData[0] = ((usUpperBoundary & 0x0700) >> 4) | ((usLowerBoundary & 0x0700) >> 8);  
    
    pData[1] = (BYTE)usUpperBoundary;
    pData[2] = (BYTE)usLowerBoundary;
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
}

//-----------------------------------------
// Description  : Set Window 7 Special Blending    fuction
// Input Value  : ucType,
//                ucFontBlendingType
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetWin7SpecialBlending(BYTE ucType, BYTE ucFontBlendingType)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0] & (~(_BIT7 | _BIT6 | _BIT5))) | ((ucType & 0x03) << 5);  
    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);    

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0B);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    pData[2] = (pData[0] & (~(_BIT5 | _BIT4))) | ((ucFontBlendingType & 0x03) << 4);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0B); 
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);
}

//-----------------------------------------
// Description  : Set Window 6 Special Blending    fuction
// Input Value  : ucFontBlendingType,
//                ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetWin6SpecialBlending(BYTE ucFontBlendingType, bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0B);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0] & (~(_BIT6 | _BIT3 | _BIT2))) | (((BYTE)bEnable) << 6) | ((ucFontBlendingType & 0x03) << 2);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0B); 
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);
}

//-----------------------------------------
// Description  : Set 2-Bit Font Character Select Offset
// Input Value  : ucOffset
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSet2BitFontCharSelectOffset(BYTE ucOffset)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0B); 
    ScalerSetByte(CM_92_OSD_DATA_PORT, ucOffset);
}

//-----------------------------------------
// Description  : Set FONT A/B horizontal/vertical delay
// Input Value  : usHorDelay,
//                usVerDelay,
//                ucFontAB
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetFontABDelay(WORD usHorDelay, WORD usVerDelay, BYTE ucFontAB)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);

    if(ucFontAB == 0)
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0C); // Font A: 0x0C
    }
    else
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x0D); // Font B: 0x0D
    }

    pData[0] = ((usHorDelay & 0x0F00) >> 4) | ((usVerDelay & 0x0F00) >> 8);
    pData[1] = (BYTE)usHorDelay;
    pData[2] = (BYTE)usVerDelay;
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
}

//-----------------------------------------
// Description  : Set Window HighLight fuction
// Input Value  : ucWinNum,
//                ucFColor,
//                ucBorderColor,
//                ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetHighLightWindow(BYTE ucWinNum, BYTE ucFColor, BYTE ucBColor, BYTE ucBorderColor, bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, (0x0D + ucWinNum));    

    pData[0] = (((BYTE)bEnable) << 6) | (ucFColor & 0x3F); 
    pData[1] = ucBColor & 0x3f;
    pData[2] = ucBorderColor & 0x3f;
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
}

//-----------------------------------------
// Description  : Enable Blank Command 64 Color
// Input Value  : ucWinNum,
//                ucFColor,
//                ucBorderColor,
//                ucEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdBlankCommand64ColorEnable(bit bEnable)
{    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x11);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0] & (~_BIT5)) | (((BYTE)bEnable) << 5);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x11);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);        
}

//-----------------------------------------
// Description  : 2-bit font character command extend character select
// Input Value  : ucEnable,              
// Output Value : None
//-----------------------------------------
void ScalerQCOsd2BitCharCommandSwapFunctionEnable(bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x11);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    pData[2] = (pData[0] & (~_BIT3)) | (((BYTE)bEnable) << 3);
    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x11);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]); 
}

//-----------------------------------------
// Description  : Set registers for write-protection function
// Input Value  : ucByteSelect, 
//                ucBitSelect
//                ucEnable            
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetWPFunction(BYTE ucByteSelect, BYTE ucBitSelect, bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x11);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0] & (~(_BIT2 | _BIT1 | _BIT0))) | bEnable | ((ucByteSelect & 0x03) << 1);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x11);  
    
    pData[0] = pData[2];
    pData[1] = ucBitSelect;
    pData[2] = 0x00;
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
}

//-----------------------------------------
// Description  : Write Protection Function Test
// Input Value  : usAddress, 
//                ucByteSelect
//                ucValue1,
//                ucValue2           
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetWPFunctionTestFont(WORD usAddress, BYTE ucByteSelect, BYTE ucValue)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, (((ucByteSelect & 0x03) << 6) | _BIT4 | (HIBYTE(usAddress & 0x0F))));
    ScalerSetByte(CM_91_OSD_ADDR_LSB, LOBYTE(usAddress));      
    ScalerSetByte(CM_92_OSD_DATA_PORT, ucValue);
}

//-----------------------------------------
// Description  : Set Pannel Pitch 
// Input Value  : usHorizontalPitch,  
//                usVerticalPitch              
// Output Value : None
//-----------------------------------------
void ScalerQCOsdPannelPitchSet(WORD usHorizontalPitch, WORD usVerticalPitch)    
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x12);    

    pData[0] = ((BYTE)((usHorizontalPitch & 0x0700) >> 4)) | ((BYTE)((usVerticalPitch & 0x0700) >> 8)) ;
    pData[1] = (BYTE)(usHorizontalPitch & 0x00FF);                          
    pData[2] = (BYTE)(usVerticalPitch & 0x00FF);      
       
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
}

//-----------------------------------------
// Description  : Set Osd Length and Width
// Input Value  : usLength,  
//                usWidth,
//                ucFontOsdNumber              
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetOsdLengthWidth(WORD usLength, WORD usWidth, BYTE ucFontOsdNumber)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);

    if(ucFontOsdNumber == 0x01)
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x13); // first OSD
    }

    if(ucFontOsdNumber == 0x02)
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x14); // Second OSD
    }

    pData[0] = ((BYTE)((usLength & 0x0F00) >> 4)) | ((BYTE)((usWidth & 0x0F00) >> 8));
    pData[1] = (BYTE)usLength;
    pData[2] = (BYTE)usWidth;
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
}

//-----------------------------------------
// Description  : Set Font A/B row total number
// Input Value  : rowNumber,  
//                ucFontIndex,             
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetRowNumber(BYTE ucRowNumber, BYTE ucFontIndex) 
{
    if(ucFontIndex == 0x00)
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    }
    else if(ucFontIndex == 0x01)
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    }
    else if(ucFontIndex == 0x02)
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    }

    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x15);
    ScalerSetByte(CM_92_OSD_DATA_PORT, ucRowNumber);    
}

//-----------------------------------------
// Description  : OSD rotation function control
// Input Value  : ucRotateDirection,  
//                ucFontMapEnable, 
//                ucFontACommandEnable,
//                ucFontBCommandEnable,   
//                ucEnable       
// Output Value : None
//-----------------------------------------
void ScalerQCOsdNewRotatedFunctionControl(BYTE ucRotateDirection, BYTE ucFontMapEnable, BYTE ucFontACommandEnable, BYTE ucFontBCommandEnable, bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x16);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);    
   
    pData[2] = (pData[0] & (~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0))) | ((ucRotateDirection & 0x01) << 4) | ((ucFontMapEnable & 0x01) << 3) | ((ucFontACommandEnable & 0x01) << 2 ) | ((ucFontBCommandEnable & 0x01) << 1) | bEnable;          

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x16);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);       
}

//-----------------------------------------
// Description  : OSD 3D function control
// Input Value  : ucInputMode,  
//                ucOutputMode, 
//                ucEnable,     
// Output Value : None
//-----------------------------------------
void ScalerQCOsd3DFunctionControl(BYTE ucInputMode, BYTE ucOutputMode, bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x17);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);    
    
    pData[2] = (pData[0] & (~( _BIT2 | _BIT1 | _BIT0))) | ((ucInputMode & 0x01) << 2) | ((ucOutputMode & 0x01) << 1) | bEnable;          

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x17);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);       
}

//-----------------------------------------
// Description  : Draw Window
// Input Value  : usXStart,  
//                usYStart, 
//                usXEnd, 
//                usYEnd
//                *pStyle
//                ucAddWin
// Output Value : None
//-----------------------------------------
void ScalerQCOsdDrawWindow(WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE *pStyle, BYTE ucAddWin)
{
    BYTE cnt0 = 0;
    BYTE cnt1 = 0;

    cnt0 = ScalerGetBit(CM_6C_OVERLAY_CTRL, _BIT0);
 
    if((ucAddWin & 0x01) == 0x01)  
    {
       
        pData[0] = (cnt0 == 0x00) ? 0xC2 : 0xE2;  
        pData[1] = ((*(pStyle) - 1) * 4) + 1;  
    }
    else  //window 0-9   window 4-1頁position 仇峽0x101
    {
        pData[0] = (cnt0 == 0x00) ? 0xC1 : 0xE1;
        pData[1] = ((*(pStyle)) * 4) + 1;
    }
    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, pData[0]);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, pData[1]);

    ScalerSetBit(CM_93_OSD_SCRAMBLE, ~(_BIT2 | _BIT1 | _BIT0), 0x05);

    pData[0] = ((usXStart & 0xF00) >> 4) | ((usYStart & 0xF00) >> 8);
    pData[1] = (usXStart & 0x0FF);
    pData[2] = (usYStart & 0x0FF);
    
    pData[3] = ((usXEnd & 0xF00) >> 4) | ((usYEnd & 0xF00) >> 8);
    pData[4] = (usXEnd & 0x0FF);
    pData[5] = (usYEnd & 0x0FF);
    ScalerWrite(CM_92_OSD_DATA_PORT, 6, pData, _NON_AUTOINC);

    if(cnt0 == 0x01)
    {        
        ScalerTimerPollingFlagProc(40, CM_93_OSD_SCRAMBLE, _BIT4, 0);
    }
   
    for(cnt1 = 0; cnt1 < 2; cnt1++)
    {
        if((ucAddWin & 0x01) == 0x01)  
        {
            pData[0] = 0xC2; 
            pData[1] = ((*(pStyle) - 1) * 4) + (cnt1 * 3);
        }
        else                                       
        {
            pData[0] = 0xC1;
            pData[1] = ((*(pStyle)) * 4) + (cnt1 * 3);
        }
        
        ScalerSetByte(CM_90_OSD_ADDR_MSB, pData[0]);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, pData[1]);

        for(cnt0 = 0; cnt0 < 3; cnt0++)
        {
            pData[cnt0] = (*(pStyle + ((cnt1 * 3) + cnt0) + 1));
        }

        ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
    }

    ScalerTimerWaitForEvent(_EVENT_DVS);
}

//-----------------------------------------
// Description  : Set Window Special Color
// Input Value  : ucRed,  
//                ucGreen, 
//                ucBlue,  
//                ucWinIndex   
// Output Value : None
//----------------------------------------- 
void ScalerQCOsdSetWindowSpecialColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue, BYTE ucWinIndex)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC1);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, (ucWinIndex * 2 + 0x50));
    
    pData[0] = ucRed;
    pData[1] = ucGreen;
    pData[2] = ucBlue;
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
}

//-----------------------------------------
// Description  : Enable Window ChessBoard Function
// Input Value  : ucColor1,  
//                ucColor2, 
//                ucWinIndex,  
//                ucEnable
//                ucAddWin   
// Output Value : None
//----------------------------------------- 
void ScalerQCOsdEnableWindowChessBoardFunction(BYTE ucColor1, BYTE ucColor2, BYTE ucWinIndex, BYTE ucAddWin, bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC1);

    if((ucAddWin & _BIT0) == _BIT0)
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (ucWinIndex * 2 + 0x62)); // window 4-1~4-8   
    }
    else
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (ucWinIndex * 2 + 1 + 0x50)); // window 8/9  
    }	  
   
    pData[0] = ((BYTE)bEnable) << 7;
    pData[1] = ucColor1 & 0x3f;
    pData[2] = ucColor2 & 0x3f;
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);
}

//-----------------------------------------
// Description  : Disable Window
// Input Value  : ucWinNumber,  
//                ucEnable, 
//                ucAddWin,  
// Output Value : None
//----------------------------------------- 
void ScalerQCOsdDisableWindow(BYTE ucWinNumber, BYTE ucAddWin, bit bEnable)
{
   
    if((ucAddWin & _BIT0) == _BIT0)  // window 4-1~4-8   
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x82);  
        ScalerSetByte(CM_91_OSD_ADDR_LSB, ((ucWinNumber - 1) * 4 + 3));     
    }
    else                                   // window 0~9
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x81);  
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (ucWinNumber * 4 + 3));
    }

    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    pData[2] = (pData[0] & (~_BIT0)) | bEnable;   // close window

    if((ucAddWin & _BIT0) == _BIT0)
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x82);  
        ScalerSetByte(CM_91_OSD_ADDR_LSB, ((ucWinNumber - 1) * 4 + 3));        
    }
    else
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x81);  
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (ucWinNumber * 4 + 3));
    }

    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);
}

//-----------------------------------------
// Description  : Window   gradient level  extension
// Input Value  : ucWinNumber,  
//                Red, 
//                Green,  
//    	    	  Blue,
//                  ucEnable
// Output Value : None
//----------------------------------------- 
void ScalerQCOsdGradientExtension(BYTE ucWinNumber, BYTE ucRed, BYTE ucGreen, BYTE ucBlue, bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x01);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, (ucWinNumber * 4 + 3));    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);
    
    pData[2] = (pData[0] & (~_BIT0)) | bEnable | _BIT4 | _BIT3;   
    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x01);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, (ucWinNumber * 4 + 3));  
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);
    
    if(ucWinNumber == 0x00)
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC1);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x74);  
    	
    	pData[0] = ucRed;
    	pData[1] = ucGreen;
    	pData[2] = ucBlue;
    	ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);    
    }
    else if((ucWinNumber == 0x05 ) || (ucWinNumber == 0x06) || (ucWinNumber == 0x07) || (ucWinNumber == 0x08) || (ucWinNumber == 0x09))
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC1);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (0x97 + (ucWinNumber - 5) * 7)); 
    	
    	pData[0] = ucRed;
    	pData[1] = ucGreen;
    	pData[2] = ucBlue;
    	ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);     
    }     
}

//-----------------------------------------
// Description  : Set window grid function
// Input Value  : ucWinNumber,  
//                GridWidth, 
//                GridColor,  
//    	    	  ucEnable,
//                  GridOffset,
//                GridPitch
// Output Value : None
//----------------------------------------- 
void ScalerQCOsdGridFunction(BYTE ucWinNumber, BYTE ucGridWidth, BYTE ucGridColor, BYTE ucEnable, BYTE ucGridOffset, WORD ucGridPitch)
{
    if((ucWinNumber == 0x02) || (ucWinNumber == 0x03) || (ucWinNumber == 0x04))
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC1);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (0x83 + (ucWinNumber - 2) * 7)); 
        
        pData[0] =((ucGridWidth & 0x03) << 6) | (ucGridColor & 0x3F);
        pData[1] =((ucEnable & 0x01) << 7)|((ucEnable & 0x02) << 5) | (ucGridOffset & 0x3F) ;
        pData[2] = (BYTE)ucGridPitch; 
        ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);     
        
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x01);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (0x84 + (ucWinNumber - 2) * 7)); 
        ScalerSetByte(CM_92_OSD_DATA_PORT, (((BYTE)(ucGridPitch >> 7)) | 0x01));     
    }
}

//-----------------------------------------
// Description  : Set window 3D function
// Input Value  : ucWinNumber,  
//                windowShift, 
//                ucAddWin,  
// Output Value : None
//----------------------------------------- 
void ScalerQCOsdWindow3DFunction(BYTE ucWinNumber, WORD usWindowShift, BYTE ucAddWin)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC2);    

    if((ucAddWin & _BIT0) == _BIT0) // window 4-1~4-8   
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (0x78 + (ucWinNumber - 1) * 4));     
    }
    else // window 0~9  
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (0x50 + ucWinNumber * 4));
    }

    pData[0] = HIBYTE(usWindowShift);
    pData[1] = LOBYTE(usWindowShift);
    pData[2] = 0x00;
    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC); 
}

//-----------------------------------------
// Description  : Set window rotation function
// Input Value  : ucWinNumber,  
//                ucEnable, 
//                ucAddWin,  
// Output Value : None
//----------------------------------------- 
void ScalerQCOsdWindowRotationFunction(BYTE ucWinNumber, BYTE ucAddWin, bit bEnable)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x01);     
    
    if((ucAddWin & _BIT0) == _BIT0) // window 4-1~4-8  
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (0xBD + (ucWinNumber - 1) * 7)); 
    }
    else // window 0~9   
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (0x77 + ucWinNumber * 7));             
    }

    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    pData[2] = (pData[0] & (~_BIT0)) | bEnable;   

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x01);     
    
    if((ucAddWin & _BIT0) == _BIT0) // window 4-1~4-8  
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (0xBD + (ucWinNumber - 1) * 7)); 
    }
    else // window 0~9   
    {
        ScalerSetByte(CM_91_OSD_ADDR_LSB, (0x77 + ucWinNumber * 7));             
    }

    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);     
}

//-----------------------------------------
// Description  : Load Font Data
// Input Value  : *pFontData,  
//                usAddress, 
//                usFontNumber, 
//                ucRoateted,
//                ucCompression
// Output Value : None
//-----------------------------------------
void ScalerQCOsdLoadFontData(BYTE *pFontData, WORD usAddress, WORD usFontNumber, BYTE ucRoateted, BYTE ucCompression)
{
    BYTE ucTemp = 0;
    WORD usAddressTemp = 0;

	//Address:0x003h Byte2 Bit[7:6]/Bit[2]/Bit[0]
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);    	
	
    if((ucRoateted & _BIT1) == _BIT1)
    {
	    pData[2] = (pData[0] & (~(_BIT6 | _BIT7))) | _BIT0 | _BIT2 | ((ucRoateted & 0x03) << 6);  
    }
    else
    {
        pData[2] = (pData[0] & (~(_BIT7 | _BIT6 | _BIT2 | _BIT0)));
    }
	
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);  
 
    if((ucCompression & _BIT0) == _BIT0)
    { 
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0xC0);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x05);  
    	ScalerWrite(CM_92_OSD_DATA_PORT, 8, pFontData, _NON_AUTOINC); 
        ScalerSetByte(CM_92_OSD_DATA_PORT, 0x01);
    }
    else          //-------------------------------------------
    {
        ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
        ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x07);

        if(ucRoateted != 0)
        { 
	    	ScalerSetByte(CM_92_OSD_DATA_PORT, _BIT1 | _BIT0);        
        }
        else
        {
            ScalerSetByte(CM_92_OSD_DATA_PORT, 0x00);
        }
    }

    ScalerSetByte(CM_90_OSD_ADDR_MSB, (0xD0 | (HIBYTE(usAddress) & 0x0F)));
    ScalerSetByte(CM_91_OSD_ADDR_LSB, LOBYTE(usAddress));    
    
    if(usAddress > 0x1000) // 12288
    {
    	ScalerSetBit(CM_93_OSD_SCRAMBLE, ~_BIT3, _BIT3);
    
	    if((ucCompression & _BIT0) == _BIT0)
	    {
	    
	         ScalerWrite(CM_92_OSD_DATA_PORT, usFontNumber - 8, pFontData + 8, _NON_AUTOINC);  
	    }
	    else
	    {
	         ScalerWrite(CM_92_OSD_DATA_PORT, usFontNumber, pFontData, _NON_AUTOINC);
	    }
	    
	    ScalerSetBit(CM_93_OSD_SCRAMBLE, ~_BIT3, 0x00);
    }
    else
    {
	    if((ucCompression & _BIT0) == _BIT0)
	    {
	         ScalerWrite(CM_92_OSD_DATA_PORT, usFontNumber - 8, pFontData + 8, _NON_AUTOINC);
	    }
	    else
	    {
	        ScalerWrite(CM_92_OSD_DATA_PORT, usFontNumber, pFontData, _NON_AUTOINC);
        }
    }
    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x07);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, 0x00);    

    pData[2] = (pData[0] & (~(_BIT7 | _BIT6 | _BIT2 | _BIT0)));
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x03);    
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[2]);       
}

//-----------------------------------------
// Description  : OSD reorder test
// Input Value  : *pArray,  
//                usFontPointer, 
//                ucLength, 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdFxPutProporString(BYTE *pArray, WORD usFontPointer, BYTE ucLength)
{ 
    BYTE ucAccBitCnt = 0;
    BYTE ucFontCnt = 0;
    BYTE ucLoadBitCnt = 0;
    BYTE ucTemp[27];
    BYTE ucBitTemp = 0;
    BYTE ucCnt = 0;
    
    // global nibble reorder enable   input reorder&Output reorder
    MCU_TRIPLE_BYTES_OP_FF03 |= _BIT7; 

    while(ucFontCnt < ucLength)
    {     
        ucLoadBitCnt = tQC_OSD_FONT_WIDTH[ucFontCnt];

        if(ucAccBitCnt == 0)
        {
            ucAccBitCnt = ucLoadBitCnt;
        }

        MCU_TRIPLE_BYTES_OP_FF03 |= _BIT3; // first bits shift direction: left shift
        MCU_TRIPLE_BYTES_OP_FF03 &= ~_BIT2;// left bits shift direction: rigth shift 
        MCU_SHIFT_BITS_NUM_FF04 = ((ucLoadBitCnt - ucAccBitCnt) << 4) | ucAccBitCnt; // first bits shift and second bits shift
        ucAccBitCnt += tQC_OSD_FONT_WIDTH[ucFontCnt + 1];
    
        for(pData[4] = 0; pData[4] < 9; pData[4]++)
        {
            MCU_TRIPLE_BYTES_OP_FF03 |= _BIT0; // restart from last three bytes
            
            MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + ucFontCnt * 27 + pData[4] * 3);
            MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + ucFontCnt * 27 + pData[4] * 3 + 1);
            MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + ucFontCnt * 27 + pData[4] * 3 + 2);

            if(ucFontCnt < ucLength - 1)
            {
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + 1) * 27 + pData[4] * 3);
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + 1) * 27 + pData[4] * 3 + 1);
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + 1) * 27 + pData[4] * 3 + 2);  
            }
            else
            {
                MCU_INPUT_TRIPLE_BYTES_FF06 = 0x00;
                MCU_INPUT_TRIPLE_BYTES_FF06 = 0x00;
                MCU_INPUT_TRIPLE_BYTES_FF06 = 0x00;
            }

            ucBitTemp = ucAccBitCnt;
            ucCnt = 2;
            
            while((ucBitTemp < 12) && (ucFontCnt < (ucLength - 1)))
            {
                MCU_BYTE_ADDRESS_FF05 = (ucBitTemp << 4) | ucBitTemp;// third bits shift and left bits shift
            
                ucBitTemp += tQC_OSD_FONT_WIDTH[ucFontCnt + ucCnt];
                
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + ucCnt) * 27 + pData[4] * 3);
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + ucCnt) * 27 + pData[4] * 3 + 1);
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + ucCnt) * 27 + pData[4] * 3 + 2); 
                ucCnt++;
            }    	

            ucTemp[pData[4] * 3] = MCU_RESULT_TRIPLE_BYTES_FF07;
            ucTemp[pData[4] * 3 + 1] = MCU_RESULT_TRIPLE_BYTES_FF07;
            ucTemp[pData[4] * 3 + 2] = MCU_RESULT_TRIPLE_BYTES_FF07;       
        }
        
        ucFontCnt += ucCnt - 2 + 1; 
        ucAccBitCnt = ucBitTemp; 
		    
        if(ucAccBitCnt < 12)
        {
            ucAccBitCnt = 0;
        }
        else if(ucAccBitCnt == 12)
        {
            ucFontCnt++;
            ucAccBitCnt = 0;
        }
        else
        {
            ucAccBitCnt = ucAccBitCnt - 12;
        }
        
       ScalerSetByte(CM_90_OSD_ADDR_MSB, (HIBYTE(usFontPointer) & 0x0F) | 0xD0);
       ScalerSetByte(CM_91_OSD_ADDR_LSB, LOBYTE(usFontPointer));
        // write to sram
        for(pData[4] = 0; pData[4] < 9; pData[4]++)
        {
            pData[0] = ((ucTemp[pData[4] * 3 + 1] & 0x0F) << 4) | (ucTemp[pData[4] * 3 + 2] & 0x0F);
            pData[1] = (ucTemp[pData[4] * 3 + 2] & 0xF0) | (ucTemp[pData[4] * 3] & 0x0F);
            pData[2] = (ucTemp[pData[4] * 3] & 0xF0)| ((ucTemp[pData[4] * 3 + 1] & 0xF0) >> 4);
            ucTemp[pData[4] * 3] = pData[0];
            ucTemp[pData[4] * 3 + 1] = pData[1];
            ucTemp[pData[4] * 3 + 2] = pData[2];
        }

        ScalerWrite(CM_92_OSD_DATA_PORT, 27, ucTemp, _NON_AUTOINC);
        usFontPointer += 9;
    }  
}

//-----------------------------------------
// Description  : Win 7 mask option
// Input Value  : bOption : _FALSE/_TRUE
//                  _FALSE mask all windows and fonts
//                  _TRUE  mask all transparent fonts  
// Output Value : None
//-----------------------------------------
void ScalerQCOSDSelectWin7MaskOption(bit bOption)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);      
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    if(bOption == _FALSE)
    {
        pData[0] = pData[0] & (~_BIT3);
    }
    else
    {
        pData[0] = pData[0] | _BIT3;
    }
      
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[0]);
}

//-----------------------------------------
// Description  : set Border priority high than window and ref
// Input Value  : ucWinNum,
//                bEnable
// Output Value : None
//-----------------------------------------
void ScalerQCOsdSetWindowRefAndBorderPri(BYTE ucWinNum, BYTE ucWinExt, bit bWinRef, bit bBorderPri)
{  
    if((ucWinNum == 4) && (ucWinExt != 0x00))
    {
        pData[0] = 0x02; 
        pData[1] = (ucWinExt - 1) * 4 + 3;
    }
    else                                       
    {
        pData[0] = 0x01;
        pData[1] = ucWinNum * 4 + 3;
    }
    
    ScalerSetByte(CM_90_OSD_ADDR_MSB, pData[0]);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, pData[1]);

	if((ucWinNum == 4) && (ucWinExt != 0x00))
	{
    	pData[0] = (((BYTE)bWinRef) << 2) | (((BYTE)bBorderPri) << 1);
	}
	else
	{
		pData[0] = (((BYTE)bWinRef) << 2);
	}

    ScalerWrite(CM_92_OSD_DATA_PORT, 1, pData, _NON_AUTOINC); 
}

//-----------------------------------------
// Description  : 4-bit font background Ref
// Input Value  : bType select
// Output Value : None
//----------------------------------------- 
void ScalerQCOsd4BitFontBackGroundRef(bit bTypeSel)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);      
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    if(bTypeSel == _FALSE)
    {
        pData[0] = pData[0] & (~_BIT2);
    }
    else
    {
        pData[0] = pData[0] | _BIT2;
    }
      
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x40);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[0]);    
}

//-----------------------------------------
// Description  : H Delay step unit
// Input Value  : bType select
// Output Value : None
//----------------------------------------- 
void ScalerQCOsdHDelayStepUnit(bit bTypeSel)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);      
    pData[0] = ScalerGetByte(CM_92_OSD_DATA_PORT);

    if(bTypeSel == _FALSE)
    {
        pData[0] = pData[0] & (~_BIT4);
    }
    else
    {
        pData[0] = pData[0] | _BIT4;
    }
      
    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x00);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x02);
    ScalerSetByte(CM_92_OSD_DATA_PORT, pData[0]);    
}

//-----------------------------------------
// Description  : Border initial
// Input Value  : all
// Output Value : None
//----------------------------------------- 
void ScalerQCOsdDrawWin(BYTE ucWinNum, BYTE ucWinExt, QCOSDWindowInfo *stOSDInfo)
{
    if((ucWinNum == 4) && (ucWinExt != 0x00))
    {
        pData[0] = 0xC2; 
        pData[1] = (ucWinExt - 1) * 4 + 0;
    }
    else                                       
    {
        pData[0] = 0xC1;
        pData[1] = ucWinNum * 4 + 0;
    }

    ScalerSetByte(CM_90_OSD_ADDR_MSB, pData[0]);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, pData[1]);

    pData[0] = ((((BYTE)stOSDInfo->b6ShadowColor) & _BIT4) << 3) | ((((BYTE)stOSDInfo->b6BorderColor) & _BIT4) << 2) \
              | ((((BYTE)stOSDInfo->b3ShaBorWidth) & 0x07) << 3) | (((BYTE)stOSDInfo->b3ShaBorHeight) & 0x07);
    pData[1] = ((((BYTE)stOSDInfo->b6ShadowColor) & 0x0F) << 4) | ((((BYTE)stOSDInfo->b6BorderColor) & 0x0F));
    pData[2] = (((BYTE)stOSDInfo->b1RGradientPloarity) << 7) | (((BYTE)stOSDInfo->b1GGradientPloarity) << 6) | (((BYTE)stOSDInfo->b1BGradientPloarity) << 5) \
              | ((((BYTE)stOSDInfo->b2GradientLevel) & 0x03) << 3) | (((BYTE)stOSDInfo->b1RGradientEn) << 2) | (((BYTE)stOSDInfo->b1GGradientEn) << 1) | (stOSDInfo->b1GGradientEn);

    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);  
  
    if((ucWinNum == 4) && (ucWinExt != 0x00))
    {
        pData[0] = 0xC2; 
        pData[1] = (ucWinExt - 1) * 4 + 1;
    }
    else                                       
    {
        pData[0] = 0xC1;
        pData[1] = ucWinNum * 4 + 1;
    }   

    ScalerSetByte(CM_90_OSD_ADDR_MSB, pData[0]);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, pData[1]);    

    pData[0] = ((((WORD)stOSDInfo->b12WindowHStart) & 0xF00) >> 4) | ((((WORD)stOSDInfo->b12WindowVStart) & 0xF00) >> 8);
    pData[1] = ((WORD)stOSDInfo->b12WindowHStart) & 0x00FF;
    pData[2] = ((WORD)stOSDInfo->b12WindowVStart) & 0x00FF;

    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);    

    if((ucWinNum == 4) && (ucWinExt != 0x00))
    {
        pData[0] = 0xC2; 
        pData[1] = (ucWinExt - 1) * 4 + 2;
    }
    else                                       
    {
        pData[0] = 0xC1;
        pData[1] = ucWinNum * 4 + 2;
    }   

    ScalerSetByte(CM_90_OSD_ADDR_MSB, pData[0]);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, pData[1]);    

    pData[0] = ((((WORD)stOSDInfo->b12WindowHEnd) & 0xF00) >> 4) | ((((WORD)stOSDInfo->b12WindowVEnd) & 0xF00) >> 8);
    pData[1] = ((WORD)stOSDInfo->b12WindowHEnd) & 0x00FF;
    pData[2] = ((WORD)stOSDInfo->b12WindowVEnd) & 0x00FF;

    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);  
    
    if((ucWinNum == 4) && (ucWinExt != 0x00))
    {
        pData[0] = 0xC2; 
        pData[1] = (ucWinExt - 1) * 4 + 3;
    }
    else                                       
    {
        pData[0] = 0xC1;
        pData[1] = ucWinNum * 4 + 3;
    }   

    ScalerSetByte(CM_90_OSD_ADDR_MSB, pData[0]);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, pData[1]);    


    pData[0] = ((((BYTE)stOSDInfo->b6ShadowColor) & _BIT5) << 2) | ((((BYTE)stOSDInfo->b6BorderColor) & _BIT5) << 1) \
              | (((BYTE)stOSDInfo->b6WindowColor) & _BIT5) | (((BYTE)stOSDInfo->b1SaturatedEn) << 4) \
              | (((BYTE)stOSDInfo->b1ReversedEn) << 3) | (((BYTE)stOSDInfo->b1WinRefDelay) << 2) | (((BYTE)stOSDInfo->b1WinBorderPri) << 1) | stOSDInfo->b1GradientLevelExt;
    pData[1] = ((stOSDInfo->b3GradientPerLevel & 0x07) << 5) | (stOSDInfo->b6WindowColor & 0x1F);
    pData[2] = (((BYTE)stOSDInfo->b1BlendFuncEn) << 7) | (((BYTE)stOSDInfo->b1GradientFuncEn) << 6) \
              | (((BYTE)stOSDInfo->b1GradientDirect) << 5) | (((BYTE)stOSDInfo->b1ShadowBorder3DEn) << 4) \
              | ((((BYTE)stOSDInfo->b3WinType) & 0x07) << 1) | stOSDInfo->b1WindowEn;

    ScalerWrite(CM_92_OSD_DATA_PORT, 3, pData, _NON_AUTOINC);  
}

//-----------------------------------------
// Description  : OSD  test    frame 0
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame0(void)
{
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(9), 0x00, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(8), 0x00, _ENABLE);
    
    ScalerQCOsdFirstSetPosition(156, 71);  
    ScalerQCOsdSecondSetPosition(200, 200);  
    ScalerQCOsdSetDisplayZone(_DIAPLAYZONE_MIDDLE);     

    ScalerQCOSDSelectWin7MaskOption(_FALSE);

    ScalerDDomainBackgroundEnable(_ENABLE);
    ScalerDDomainBackgroundSetColor(0x55, 0x66, 0x77);
    ScalerQCOsdSetBlendingLevel(0x02); 
    ScalerQCOsdSetBlendingType1(0x01);
    ScalerQCOsdSetBlendingType2(0x3f, _ENABLE, 0x01);    
    ScalerQCOsdSetWin6SpecialBlending(0x01, _ENABLE);
    ScalerQCOsdSetWin7SpecialBlending(0x01, 0x00);    
     
    ScalerQCOsdSetCharShadowBorderColor(0x34);
    ScalerQCOsdVerticalStartInputSourceSelect(_DISABLE);    	    	      	    	    	      
    ScalerQCOsdVerticalBoundaryFunctionEnable(_ENABLE);
    ScalerQCOsdSetBaseAddressOffset(0x103, 0x403);   
    ScalerQCOsdSetRowCommandBase0(0x01);
    ScalerQCOsdSetRowCommandBase1(0x00);  
    ScalerQCOsdSetFontSelectBase0(0x10b);
    ScalerQCOsdSetFontSelectBase1(0x103); 
    ScalerQCOsdSetVBoundary(0x100, 0x350); 
    ScalerQCOsdSetFontABDelay(0x101, 0x1B5, 0);
    ScalerQCOsdSetFontABDelay(0x1ff, 0x1CC, 1);
    ScalerQCOsdSet2BitFontCharSelectOffset(0x01);

    ScalerQCOsdPannelPitchSet(0x424, 0x424);
    ScalerQCOsdGridFunction(WINNO(2), 0x00, 0x1f, 0x03, 0x1f, 0xcff);
    ScalerQCOsdGridFunction(WINNO(3), 0x00, 0x1f, 0x03, 0x1f, 0xcff);
    ScalerQCOsdGridFunction(WINNO(4), 0x00, 0x1f, 0x03, 0x1f, 0xcff);
     
    // Window 0/1/2/3/4/5/6/7/8/9
    ScalerQCOsdDrawWindow(0x101, 0x101, 0x201, 0x201, tQC_OSD_WIN0_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x11f, 0x11f, 0x21f, 0x21f, tQC_OSD_WIN1_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x13d, 0x13d, 0x23d, 0x23d, tQC_OSD_WIN2_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x15b, 0x15b, 0x25b, 0x25b, tQC_OSD_WIN3_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x179, 0x179, 0x279, 0x279, tQC_OSD_WIN4_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x197, 0x197, 0x279, 0x279, tQC_OSD_WIN5_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x1b5, 0x1b5, 0x2b5, 0x2b5, tQC_OSD_WIN6_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x1d3, 0x1d3, 0x2d3, 0x2d3, tQC_OSD_WIN7_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x1f1, 0x1f1, 0x2f1, 0x2f1, tQC_OSD_WIN8_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x20f, 0x20f, 0x30f, 0x30f, tQC_OSD_WIN9_STYLE, 0x00);

    // Window Special Color 0/5/6/7/8/9  saturated color
    ScalerQCOsdSetWindowSpecialColor(0xff, 0xff, 0xff, WINNO(0));
    ScalerQCOsdSetWindowSpecialColor(0x87, 0x12, 0x46, WINNO(5));
    ScalerQCOsdSetWindowSpecialColor(0x12, 0x87, 0x94, WINNO(6));
    ScalerQCOsdSetWindowSpecialColor(0x34, 0x56, 0x78, WINNO(7));
    ScalerQCOsdSetWindowSpecialColor(0x78, 0x65, 0x34, WINNO(8));
    ScalerQCOsdSetWindowSpecialColor(0x64, 0x34, 0x98, WINNO(9));

    // Window 4-1~4-8   
    ScalerQCOsdDrawWindow(0x1A0, 0x11F, 0x2A0, 0x21F, tQC_OSD_WIN41_STYLE, 0x01);    	
    ScalerQCOsdDrawWindow(0x1D0, 0x13D, 0x2D0, 0x23D, tQC_OSD_WIN42_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x200, 0x15B, 0x300, 0x25B, tQC_OSD_WIN43_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x230, 0x179, 0x330, 0x279, tQC_OSD_WIN44_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x250, 0x197, 0x350, 0x297, tQC_OSD_WIN45_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x270, 0x1B5, 0x370, 0x2B5, tQC_OSD_WIN46_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x2A0, 0x1D3, 0x3A0, 0x2D3, tQC_OSD_WIN47_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x2D0, 0x20F, 0x3D0, 0x30F, tQC_OSD_WIN48_STYLE, 0x01);    
    
    // Set row command
    ScalerQCOsdSetRowCommand(tQC_OSDROWMAPAPPLY, (sizeof(tQC_OSDROWMAPAPPLY) / 3));    
    // Set character command
    ScalerQCOsdSetCharacterCommand(tQC_OSDCHARACTERCOMMAND_TABLE1, 0x103, sizeof(tQC_OSDCHARACTERCOMMAND_TABLE1));   
    // Load Normal font data
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TABLE1, 0x403, sizeof(tQC_OSDNOMALFONTDATA_TABLE1), 0x00, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE2, 0xD03, sizeof(tQC_OSDNOMALFONTDATA_TANLE2), 0x00, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE3, 0x1213, sizeof(tQC_OSDNOMALFONTDATA_TANLE3), 0x00, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE4, 0x191B, sizeof(tQC_OSDNOMALFONTDATA_TANLE4), 0x00, 0x00);

    ScalerQCOsdFxPutProporString(tQC_OSD_FONT_DATA, (0x403 + 0x21C), 7);

    ScalerQCOsdSetWPFunction(0x02, 0xFF, _ENABLE);
    ScalerQCOsdSetWPFunctionTestFont(0x00, 0x02, 0x00);
    ScalerQCOsdSetWPFunction(0x00, 0x00, _DISABLE);
   
    ScalerQCOsdSetWPFunction(0x01, 0xFF, _ENABLE);
    ScalerQCOsdSetWPFunctionTestFont(0x00, 0x01, 0x00);
    ScalerQCOsdSetWPFunction(0x00, 0x00, _DISABLE);
    
    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);
    ScalerQCOsd2OSDFontFuncitonEnable(_ENABLE);
}

//-----------------------------------------
// Description  : OSD  test    frame 1
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame1(void)
{    
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);
    
    ScalerQCOsdSetDisplayZone(_DIAPLAYZONE_LEFT);    
    // window2、3、4、8、9 high than font   
    ScalerQCOsdEnableWindowHighThanFont(WINNO(2), _ENABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(3), _ENABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(4), _ENABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(8), _ENABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(9), _ENABLE);
     
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(1), 0x01, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(2), 0x01, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(3), 0x01, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(4), 0x01, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(5), 0x01, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(6), 0x01, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(7), 0x01, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(8), 0x01, _ENABLE);
    
    // disable 2 OSD font function 
    ScalerQCOsd2OSDFontFuncitonEnable(_DISABLE);
    // enable special function roll up  
    ScalerQCOsdSpecialFunctionSelect(_POP_ON_FUNCTION, _ENABLE);  
    // select base0
    ScalerQCOsdDisplayBaseSelect(_BASE0_SELECT);    
    // Display Row: 3-4-5-6-7-8-0-1-2
    ScalerQCOsdSetRowCommandBase0(0x03);
    ScalerQCOsdSetFontSelectBase0(0x11b);
    ScalerQCOsdSetRowCommandBase1(0x08); 
    ScalerQCOsdSetFontSelectBase1(0x13b);

    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);  
}

//-----------------------------------------
// Description  : OSD  test    frame 2
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame2(void)
{
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);
    ScalerQCOsdSetDisplayZone(_DIAPLAYZONE_LEFT); 
    // window2、3、4、8、9 low than font
    ScalerQCOsdEnableWindowHighThanFont(WINNO(2), _DISABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(3), _DISABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(4), _DISABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(8), _DISABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(9), _DISABLE);

    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(1), 0x01, _DISABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(2), 0x01, _DISABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(3), 0x01, _DISABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(4), 0x01, _DISABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(5), 0x01, _DISABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(6), 0x01, _DISABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(7), 0x01, _DISABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(8), 0x01, _DISABLE);
    // enable special function POP On // select base0
    ScalerQCOsdSpecialFunctionSelect(_ROLL_UP_FUNCTION, _ENABLE);
     
    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);
}

//-----------------------------------------
// Description  : OSD  test    frame 3
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame3(void)
{
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);
    ScalerQCOsdSetDisplayZone(_DIAPLAYZONE_LEFT); 
    // Select base 1
    ScalerQCOsdSetRowCommandBase0(0x02);
    ScalerQCOsdSetFontSelectBase0(0x113);  
    ScalerQCOsdSetRowCommandBase1(0x05);
    ScalerQCOsdSetFontSelectBase1(0x12b);
    ScalerQCOsdDisplayBaseSelect(_BASE1_SELECT);

    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);
}

//-----------------------------------------
// Description  : OSD  test    frame 4
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame4(void)
{
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE); 
      
    ScalerQCOsdFirstSetPosition((0x27 * 4), 0x47);  // 39x4 =156
    
    ScalerDDomainBackgroundEnable(_ENABLE);
    ScalerDDomainBackgroundSetColor(0xaa, 0xaa, 0xaa);    

    // disable osd special function
    ScalerQCOsdSpecialFunctionSelect(_ROLL_UP_FUNCTION, _DISABLE);
    ScalerQCOsdBlankCommand64ColorEnable(_ENABLE);
    ScalerQCOsd2BitCharCommandSwapFunctionEnable(_ENABLE);     
    ScalerQCOsdSetCharShadowBorderColor(0x33);
    ScalerQCOsdSetBaseAddressOffset(0x103, 0x403);

    // set font AB delay 
    ScalerQCOsdSetFontABDelay(0x00, 0x00, 0x00);
    ScalerQCOsdSetFontABDelay(0x00, 0x00, 0x01);

    // disable vertical boundary function
    ScalerQCOsdVerticalBoundaryFunctionEnable(_DISABLE);
    // row character command
    ScalerQCOsdSetRowCommand(tQC_OSDROWMAPAPPLY_FRAME4, sizeof(tQC_OSDROWMAPAPPLY_FRAME4));
    ScalerQCOsdSetCharacterCommand(tQC_OSDCHARACTERCOMMAND_FRAME4, 0x103, sizeof(tQC_OSDCHARACTERCOMMAND_FRAME4));
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TABLE_FRAME4, 0x403, sizeof(tQC_OSDNOMALFONTDATA_TABLE_FRAME4), 0x00, 0x00);

    // Window 4-1 ~ window 4-3
    ScalerQCOsdDrawWindow(0x25, 0x30, 0xf0, 0x70, tQC_OSD_WIN41_STYLE_FRAME4, 0x01);
    ScalerQCOsdDrawWindow(0x70, 0x05, 0x90, 0x50, tQC_OSD_WIN42_STYLE_FRAME4, 0x01);
    ScalerQCOsdDrawWindow(0x80, 0x10, 0xf0, 0x60, tQC_OSD_WIN43_STYLE_FRAME4, 0x01);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x00, WINNO(1), 0x01, _DISABLE);
      
    // High light window function
    ScalerQCOsdSetHighLightWindow(WINNO(0x01), 0x3f, 0x00, 0x14, _ENABLE);
    ScalerQCOsdSetHighLightWindow(WINNO(0x02), 0x13, 0x01, 0x3f, _ENABLE);
    ScalerQCOsdSetHighLightWindow(WINNO(0x03), 0x07, 0x0f, 0x0c, _ENABLE);

    //disable grid fuction
    ScalerQCOsdGridFunction(WINNO(2), 0x00, 0x1f, 0x00, 0x1f, 0xcff);
    ScalerQCOsdGridFunction(WINNO(3), 0x00, 0x1f, 0x00, 0x1f, 0xcff);
    ScalerQCOsdGridFunction(WINNO(4), 0x00, 0x1f, 0x00, 0x1f, 0xcff);
    
    // close the window
    ScalerQCOsdDisableWindow(WINNO(0), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(1), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(2), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(3), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(4), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(5), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(6), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(7), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(8), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(9), 0x00, _DISABLE);
    
    ScalerQCOsdDisableWindow(WINNO(4), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(5), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(6), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(7), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(8), 0x01, _DISABLE);

    ScalerQCOsdOverlayEnable(_ENABLE ,_ENABLE);
}

//-----------------------------------------
// Description  : OSD  test    frame 5
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame5(void)
{
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);

    ScalerDDomainBackgroundEnable(_ENABLE);
    ScalerDDomainBackgroundSetColor(0x28, 0x28, 0x55);        
    
    ScalerQCOsdBlinkingFunctionEnable(_DISABLE);
    ScalerQCOsdSetCharShadowBorderColor(0x33);

    ScalerQCOsd2BitCharCommandSwapFunctionEnable(_DISABLE);
    ScalerQCOsd2OSDFontFuncitonEnable(_DISABLE);
    ScalerQCOsdSpecialFunctionSelect(_POP_ON_FUNCTION, _DISABLE);
    ScalerQCOsdVerticalBoundaryFunctionEnable(_DISABLE);
    ScalerQCOsdSetVBoundary(0x00, 0x00);
    ScalerQCOsdSetDisplayZone(_DIAPLAYZONE_MIDDLE);
    ScalerQCOsdSet2BitFontCharSelectOffset(0x01);
    
    ScalerQCOSDSelectWin7MaskOption(_TRUE);

    ScalerQCOsdSetBlendingLevel(0x07);
    ScalerQCOsdSetBaseAddressOffset(0x100, 0x1403);

    ScalerQCOsdSetRowCommand(tQC_OSDROWMAPAPPLY_FRAME5, sizeof(tQC_OSDROWMAPAPPLY_FRAME5) / 3);
    ScalerQCOsdSetCharacterCommand(tQC_OSDCHARACTERCOMMAND_FRAME5, 0x100, sizeof(tQC_OSDCHARACTERCOMMAND_FRAME5));
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_FRAME5, 0x1403, sizeof(tQC_OSDNOMALFONTDATA_FRAME5), 0x00, 0x00);

    ScalerQCOsdDrawWindow(0x00, 0x00, 0x201, 0x201, tQC_OSD_WIN0_STYLE_FRAME5, 0x00);
    ScalerQCOsdDrawWindow(0x00, 0x00, 0x150, 0x190, tQC_OSD_WIN6_STYLE_FRAME5, 0x00);
    ScalerQCOsdDrawWindow(0x60, 0x50, 0x100, 0x190, tQC_OSD_WIN7_STYLE_FRAME5, 0x00);  
    ScalerQCOsdDrawWindow(0x00, 0xa0, 0x20, 0x110, tQC_OSD_WIN8_STYLE_FRAME5, 0x00);

    ScalerQCOsdDisableWindow(WINNO(1), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(2), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(3), 0x01, _DISABLE);
   
    ScalerQCOsdEnableWindowHighThanFont(WINNO(8), _ENABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(9), _DISABLE);
    
    // blending function
    ScalerQCOsdSetBlendingType1(0x03);
    
    // color LUT = 0x3f, enable, bit[5:4] enable
    ScalerQCOsdSetBlendingType2(0x3f, _ENABLE, 0x01);
    
    // enable window 6 special function, both blending for F/B
    ScalerQCOsdSetWin6SpecialBlending(0x03, _ENABLE);

    // window 7 mask region transparent
    ScalerQCOsdSetWin7SpecialBlending(0x03, 0x03);
    
    // blinking function
    ScalerQCOsdBlinkingFunctionEnable(_ENABLE);

    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);
}

//-----------------------------------------
// Description  : Close some OSD  test    frame 5 setting
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdCloseTestFrame5(void)
{
    ScalerQCOsdBlinkingFunctionEnable(_DISABLE);
    ScalerQCOSDSelectWin7MaskOption(_FALSE);
}

//-----------------------------------------
// Description  : OSD  test    frame 6
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame6(void)
{      
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);

    ScalerDDomainBackgroundEnable(_ENABLE);
    ScalerDDomainBackgroundSetColor(0x55, 0x66, 0x77);        

    ScalerQCOsdFirstSetPosition(0x30, 0x30);
    ScalerQCOsdBlinkingFunctionEnable(_DISABLE);
    ScalerQCOsdSetDisplayZone(_DIAPLAYZONE_RIGHT);
    
    ScalerQCOsdSet2BitFontCharSelectOffset(0x88);
    ScalerQCOsd2OSDFontFuncitonEnable(_DISABLE);
    ScalerQCOsdSpecialFunctionSelect(_POP_ON_FUNCTION, _DISABLE);
    ScalerQCOsdVerticalBoundaryFunctionEnable(_DISABLE);

    ScalerQCOsdSetFontABDelay(0x55, 0x55, 0x00);
    ScalerQCOsdSetBaseAddressOffset(0x100, 0x400);
    
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(9), 0x00, _ENABLE);
    ScalerQCOsdGridFunction(WINNO(2), 0x00, 0x1f, 0x00, 0x1f, 0xcff);
    ScalerQCOsdGridFunction(WINNO(3), 0x00, 0x1f, 0x00, 0x1f, 0xcff);
    ScalerQCOsdGridFunction(WINNO(4), 0x00, 0x1f, 0x00, 0x1f, 0xcff);
       
    // close the window
    ScalerQCOsdDisableWindow(WINNO(0), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(1), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(2), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(3), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(4), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(5), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(6), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(7), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(8), 0x00, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(9), 0x00, _DISABLE);

    ScalerQCOsdDisableWindow(WINNO(1), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(2), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(3), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(4), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(5), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(6), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(7), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(8), 0x01, _DISABLE);

    ScalerQCOsdDrawWindow(0x100, 0x100, 0x18f, 0x18f, tQC_OSD_WIN9_STYLE, 0x00);    
    ScalerQCOsdSetRowCommand(tQC_OSDROWMAPAPPLY_FRAME6, sizeof(tQC_OSDROWMAPAPPLY_FRAME6));
    ScalerQCOsdSetCharacterCommand(tQC_OSDCHARACTERCOMMAND_FRAME6, 0x100, sizeof(tQC_OSDCHARACTERCOMMAND_FRAME6));
        
    ScalerQCOsdLoadFontData(tQC_OSDHWVLCCOMPRESSED_TABLE, 0x400, sizeof(tQC_OSDHWVLCCOMPRESSED_TABLE), 0x03, 0x01);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE6, 0x42d, sizeof(tQC_OSDNOMALFONTDATA_TANLE6), 0x02, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE2_FRAME6, 0xd90, sizeof(tQC_OSDNOMALFONTDATA_TANLE2_FRAME6), 0x02, 0x00);

    ScalerQCOsdRotatedFunctionEnable(_ENABLE);

    // width and height double pixel
    ScalerQCOsdDoubleWidthHeightEnable(0x03);
    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);
}


//-----------------------------------------
// Description  : OSD  test    frame 7
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame7(void)
{   
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);

    ScalerQCOsdFirstSetPosition(150, 20);  // 39x4 =156    
    ScalerQCOsdSecondSetPosition(100, 20);
    ScalerQCOsdSetDisplayZone(_DIAPLAYZONE_MIDDLE);       //    _DIAPLAYZONE_MIDDLE
    //Display zone
    ScalerDDomainBackgroundEnable(_ENABLE);
    ScalerDDomainBackgroundSetColor(0x55, 0x66, 0x77);
              	    	    	      
    ScalerQCOsd2OSDFontFuncitonEnable(_ENABLE);
    ScalerQCOsdVerticalBoundaryFunctionEnable(_DISABLE);
    ScalerQCOsdSetBaseAddressOffset(0x103, 0x403);   
    ScalerQCOsdSetRowCommandBase0(0x01);
    ScalerQCOsdSetRowCommandBase1(0x00);  
    ScalerQCOsdSetFontSelectBase0(0x10b);
    ScalerQCOsdSetFontSelectBase1(0x103); 
    ScalerQCOsdSetFontABDelay(0x101, 0x1B5, 0);
    ScalerQCOsdSetFontABDelay(0x2ff, 0x1b1, 1);    
    ScalerQCOsdFontBRefSelect(_ENABLE);
    ScalerQCOsdFontARefSelect(_DISABLE);    
    // 3D fuction
    ScalerQCOsd3DFunctionControl(0x01, 0x01, _ENABLE);
    ScalerQCOsdWindow3DFunction(WINNO(0), 0x010, 0x00);
    ScalerQCOsdWindow3DFunction(WINNO(1), 0x010, 0x00); 
    ScalerQCOsdSetOsdLengthWidth(0x500, 0x400, 0x01);
    ScalerQCOsdSetOsdLengthWidth(0x500, 0x400, 0x02);
    	    	    	    	    	    	    	    	    	  
    ScalerQCOsdSetRowNumber(0x09, 0x00); 
    ScalerQCOsdSetRowNumber(0x08, 0x01); 
    ScalerQCOsdSetRowNumber(0x09, 0x02); 

    ScalerQCOsdWindowRotationFunction(WINNO(0), 0x00, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(1), 0x00, _ENABLE);
    ScalerQCOsdNewRotatedFunctionControl(0x00, 0x00, 0x00, 0x00, _DISABLE);

    ScalerQCOsdSetRowCommand(tQC_OSDROWMAPAPPLY_FRAME7, (sizeof(tQC_OSDROWMAPAPPLY_FRAME7) / 3)); 
    // Set character command
    ScalerQCOsdSetCharacterCommand(tQC_OSDCHARACTERCOMMAND_FRAME7, 0x103, sizeof(tQC_OSDCHARACTERCOMMAND_FRAME7));   
    // Load Normal font data
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TABLE1, 0x403, sizeof(tQC_OSDNOMALFONTDATA_TABLE1), 0x00, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE2, 0xD03, sizeof(tQC_OSDNOMALFONTDATA_TANLE2), 0x00, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE3, 0x1213, sizeof(tQC_OSDNOMALFONTDATA_TANLE3), 0x00, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE4, 0x191b, sizeof(tQC_OSDNOMALFONTDATA_TANLE4), 0x00, 0x00);       
      
    ScalerQCOsdPannelPitchSet(0x424, 0x424);
    ScalerQCOsdGridFunction(WINNO(2), 0x00, 0x1f, 0x03, 0x1f, 0xcff);
    ScalerQCOsdGridFunction(WINNO(3), 0x00, 0x1f, 0x03, 0x1f, 0xcff);
    ScalerQCOsdGridFunction(WINNO(4), 0x00, 0x1f, 0x03, 0x1f, 0xcff);
    
    // Window 0/1/2/3/4/5/6/7/8/9
    ScalerQCOsdDrawWindow(0x101, 0x101, 0x201, 0x201, tQC_OSD_WIN0_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x11f, 0x11f, 0x21f, 0x21f, tQC_OSD_WIN1_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x13d, 0x13d, 0x23d, 0x23d, tQC_OSD_WIN2_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x15b, 0x15b, 0x25b, 0x25b, tQC_OSD_WIN3_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x179, 0x179, 0x279, 0x279, tQC_OSD_WIN4_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x197, 0x197, 0x279, 0x279, tQC_OSD_WIN5_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x1b5, 0x1b5, 0x2b5, 0x2b5, tQC_OSD_WIN6_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x1d3, 0x1d3, 0x2d3, 0x2d3, tQC_OSD_WIN7_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x1f1, 0x1f1, 0x2f1, 0x2f1, tQC_OSD_WIN8_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x20f, 0x20f, 0x30f, 0x30f, tQC_OSD_WIN9_STYLE, 0x00);
    
    // Window 4-1~4-8   
    ScalerQCOsdDrawWindow(0x1a0, 0x11f, 0x2a0, 0x21f, tQC_OSD_WIN41_STYLE, 0x01);    	
    ScalerQCOsdDrawWindow(0x1d0, 0x13d, 0x2d0, 0x23d, tQC_OSD_WIN42_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x200, 0x15b, 0x300, 0x25b, tQC_OSD_WIN43_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x230, 0x179, 0x330, 0x279, tQC_OSD_WIN44_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x250, 0x197, 0x350, 0x297, tQC_OSD_WIN45_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x270, 0x1b5, 0x370, 0x2b5, tQC_OSD_WIN46_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x2a0, 0x1d3, 0x3a0, 0x2d3, tQC_OSD_WIN47_STYLE, 0x01);
    ScalerQCOsdDrawWindow(0x2d0, 0x20f, 0x3d0, 0x30f, tQC_OSD_WIN48_STYLE, 0x01);

    // Window Special Color 0/5/6/7/8/9  saturated color
    ScalerQCOsdSetWindowSpecialColor(0xff, 0xff, 0xff, WINNO(0));
    ScalerQCOsdSetWindowSpecialColor(0x87, 0x12, 0x46, WINNO(5));
    ScalerQCOsdSetWindowSpecialColor(0x12, 0x87, 0x94, WINNO(6));
    ScalerQCOsdSetWindowSpecialColor(0x34, 0x56, 0x78, WINNO(7));
    ScalerQCOsdSetWindowSpecialColor(0x78, 0x65, 0x34, WINNO(8));
    ScalerQCOsdSetWindowSpecialColor(0x64, 0x34, 0x98, WINNO(9));

    // window 
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(9), 0x00, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(8), 0x00, _ENABLE);
    
    ScalerQCOsdWindowRotationFunction(WINNO(0), 0x00, _DISABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(1), 0x00, _DISABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(2), 0x00, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(3), 0x00, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(4), 0x00, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(5), 0x00, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(6), 0x00, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(7), 0x00, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(8), 0x00, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(9), 0x00, _ENABLE);

    ScalerQCOsdWindowRotationFunction(WINNO(1), 0x01, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(2), 0x01, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(3), 0x01, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(4), 0x01, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(5), 0x01, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(6), 0x01, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(7), 0x01, _ENABLE);
    ScalerQCOsdWindowRotationFunction(WINNO(8), 0x01, _ENABLE);
    	
    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);
}

//-----------------------------------------
// Description  : OSD  test    frame 8
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame8(void)
{
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);
    	
    ScalerTimerDelayXms(10);
    ScalerQCOsdRotatedFunctionEnable(_ENABLE);
    ScalerTimerDelayXms(10);
    ScalerQCOsdNewRotatedFunctionControl(0x00, 0x01, 0x01, 0x01, _ENABLE);

    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);
}

//-----------------------------------------
// Description  : OSD  test    frame 9
// Input Value  : None 
// Output Value : None
//-----------------------------------------
void ScalerQCOsdTestFrame9(void)
{
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);
    	
    ScalerQCOsdFirstSetPosition(156, 71);  // 39x4 =156     
    ScalerQCOsdSecondSetPosition(200, 200);

    ScalerQCOsdSetDisplayZone(_DIAPLAYZONE_MIDDLE);       //    _DIAPLAYZONE_MIDDLE
    ScalerDDomainBackgroundEnable(_ENABLE);
    ScalerDDomainBackgroundSetColor(0x55, 0x66, 0x77);             	          	    	    	      
  
    ScalerQCOsdDisableWindow(WINNO(1), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(2), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(3), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(4), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(5), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(6), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(7), 0x01, _DISABLE);
    ScalerQCOsdDisableWindow(WINNO(8), 0x01, _DISABLE);
  
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(9), 0x00, _DISABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(8), 0x00, _DISABLE);    
    // gradient extension
    ScalerQCOsdGradientExtension(WINNO(0), 0x10, 0x10, 0x10, _ENABLE);
    ScalerQCOsdGradientExtension(WINNO(5), 0x0A, 0x0A, 0x0A, _ENABLE);
    ScalerQCOsdGradientExtension(WINNO(6), 0x02, 0x12, 0x02, _ENABLE);
    ScalerQCOsdGradientExtension(WINNO(7), 0x0E, 0x0E, 0x0E, _ENABLE);    
    ScalerQCOsdGradientExtension(WINNO(8), 0x20, 0x16, 0x12, _ENABLE);
    ScalerQCOsdGradientExtension(WINNO(9), 0x0E, 0x0E, 0x0E, _ENABLE);

    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);
}

void ScalerQCOsdTestFrame10(void)
{
    BYTE ucCnt = 0;
    QCOSDWindowInfo stOSDInfo = {0};
                  
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);
        
    ScalerQCOsdHDelayStepUnit(1);
    ScalerQCOsdFirstSetPosition(150, 20);     
    ScalerQCOsdSecondSetPosition(200, 42);
    ScalerQCOsdSetDisplayZone(_DIAPLAYZONE_MIDDLE);       //    _DIAPLAYZONE_MIDDLE

    ScalerQCOsdDoubleWidthHeightEnable(0x00);
    ScalerQCOsdSet2BitFontCharSelectOffset(0x01);

    ScalerDDomainBackgroundEnable(_ENABLE);
    ScalerDDomainBackgroundSetColor(0x53, 0x46, 0x87);

    ScalerQCOsd2OSDFontFuncitonEnable(_ENABLE);
    ScalerQCOsdVerticalBoundaryFunctionEnable(_DISABLE);
    ScalerQCOsdSetBaseAddressOffset(0x103, 0x403);   
    ScalerQCOsdSetRowCommandBase0(0x01);
    ScalerQCOsdSetRowCommandBase1(0x00);  
    ScalerQCOsdSetFontSelectBase0(0x10b);
    ScalerQCOsdSetFontSelectBase1(0x103); 
    ScalerQCOsdSetFontABDelay(0x101, 0x1B5, 0);
    ScalerQCOsdSetFontABDelay(0x2ff, 0x1b1, 1);    
    ScalerQCOsdFontBRefSelect(_ENABLE);
    ScalerQCOsdFontARefSelect(_DISABLE);
  
    ScalerQCOsdSetRowCommand(tQC_OSDROWMAPAPPLY_FRAME7, (sizeof(tQC_OSDROWMAPAPPLY_FRAME7) / 3)); 

    // Set character command
    ScalerQCOsdSetCharacterCommand(tQC_OSDCHARACTERCOMMAND_FRAME10, 0x103, sizeof(tQC_OSDCHARACTERCOMMAND_FRAME10)); 
      
    // Load Normal font data
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TABLE1, 0x403, sizeof(tQC_OSDNOMALFONTDATA_TABLE1), 0x00, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE2, 0xD03, sizeof(tQC_OSDNOMALFONTDATA_TANLE2), 0x00, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE3, 0x1213, sizeof(tQC_OSDNOMALFONTDATA_TANLE3), 0x00, 0x00);
    ScalerQCOsdLoadFontData(tQC_OSDNOMALFONTDATA_TANLE4, 0x191b, sizeof(tQC_OSDNOMALFONTDATA_TANLE4), 0x00, 0x00);       
  
    ScalerQCOsdEnableWindowHighThanFont(WINNO(2), _ENABLE);
    ScalerQCOsdEnableWindowHighThanFont(WINNO(9), _ENABLE);

    // Window 0/1/2/3/4/5/6/7/8/9    
    ScalerQCOsdDrawWindow(0x01, 0x12, 0x51, 0x61, tQC_OSD_WIN0_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x1f, 0x13, 0x11f, 0x62, tQC_OSD_WIN1_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x33d, 0x214, 0x36d, 0x293, tQC_OSD_WIN2_STYLE, 0x00);  
    ScalerQCOsdDrawWindow(0x5b, 0x15, 0x15b, 0x54, tQC_OSD_WIN3_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x79, 0x16, 0x179, 0x45, tQC_OSD_WIN4_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x97, 0x17, 0x179, 0x56, tQC_OSD_WIN5_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0xb5, 0x18, 0x1b5, 0x67, tQC_OSD_WIN6_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0xd3, 0x19, 0x1d3, 0x77, tQC_OSD_WIN7_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0xf1, 0x1a, 0x1f1, 0x56, tQC_OSD_WIN8_STYLE, 0x00);
    ScalerQCOsdDrawWindow(0x35f, 0x21b, 0x38f, 0x305, tQC_OSD_WIN9_STYLE, 0x00);

    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(9), 0x00, _ENABLE);
    ScalerQCOsdEnableWindowChessBoardFunction(0x00, 0x0f, WINNO(8), 0x00, _DISABLE); 
           
    // Window Special Color 0/5/6/7/8/9  saturated color
    ScalerQCOsdSetWindowSpecialColor(0xff, 0xff, 0xff, WINNO(0));
    ScalerQCOsdSetWindowSpecialColor(0x87, 0x12, 0x46, WINNO(5));
    ScalerQCOsdSetWindowSpecialColor(0x12, 0x87, 0x94, WINNO(6));
    ScalerQCOsdSetWindowSpecialColor(0x34, 0x56, 0x78, WINNO(7));
    ScalerQCOsdSetWindowSpecialColor(0x78, 0x65, 0x34, WINNO(8));
    ScalerQCOsdSetWindowSpecialColor(0x64, 0x34, 0x98, WINNO(9));  
    
    ScalerQCOsd4BitFontBackGroundRef(1);    
    
    for(ucCnt = 1; ucCnt < 10; ucCnt++)
    {
        ScalerQCOsdSetWindowRefAndBorderPri(WINNO(ucCnt), 0, 1, 0);
    }
 
    ScalerQCOsdSetHighLightWindow(WINNO(0x01), 0x3f, 0x00, 0x14, _ENABLE);
    ScalerQCOsdSetHighLightWindow(WINNO(0x02), 0x13, 0x01, 0x3f, _DISABLE);
    ScalerQCOsdSetHighLightWindow(WINNO(0x03), 0x27, 0x0f, 0x0c, _DISABLE);

    stOSDInfo.b1ShadowBorder3DEn = _TRUE;
    stOSDInfo.b3WinType = 0x07; // Border
    stOSDInfo.b1WinBorderPri = _TRUE;
    stOSDInfo.b1WinRefDelay = _TRUE;
            
    for(ucCnt = 1; ucCnt < 9; ucCnt++)
    {
        stOSDInfo.b1WindowEn = ucCnt % 2;
        stOSDInfo.b6BorderColor = ucCnt * 2;
        stOSDInfo.b3ShaBorWidth = (ucCnt - 1) & 0x07;
        stOSDInfo.b3ShaBorHeight = (10 - ucCnt) & 0x07;
        stOSDInfo.b6WindowColor = (ucCnt * 13 + 1) & 0x3F;
        stOSDInfo.b12WindowHStart = 0xD0 + (BYTE)ucCnt * 20;
        stOSDInfo.b12WindowVStart = 0x130 + (BYTE)ucCnt *25;
        stOSDInfo.b12WindowHEnd = 0x300 + (BYTE)ucCnt * 23;
        stOSDInfo.b12WindowVEnd = 0x210 + (BYTE)ucCnt * 24;
       
        ScalerQCOsdDrawWin(WINNO(4), ucCnt, &stOSDInfo);
    } 
    
    ScalerQCOsdOverlayEnable(_ENABLE, _ENABLE);        
}

//-----------------------------------------
// Description  : OSD test function
// Input Value  : None
// Output Value : None
//-----------------------------------------
bit ScalerQCOsdTestProc(void)
{
    WORD usData = 0;

    ScalerSetByte(CM_60_HW_ACCESS_PORT, 0x00);
    ScalerSetByte(CM_62_COLOR_CTRL, 0x00);
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x00);
    ScalerSetByte(CM_6A_DITHERING_CTRL1, 0x00);

    ScalerSetByte(CM_90_OSD_ADDR_MSB, 0x80);
    ScalerSetByte(CM_91_OSD_ADDR_LSB, 0x00);
    ScalerSetByte(CM_92_OSD_DATA_PORT, 0x01);  // OSD Must be Activated

    ScalerTimerWaitForEvent(_EVENT_DVS);    	
    ScalerQCOsdLoadColorPalatte();
    
     // enable osd
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);
     
    // frame 0
    DebugMessageScaler("5.OsdTestFrame0 Start", 0x00);
    ScalerQCOsdTestFrame0();
    ScalerTimerWaitForEvent(_EVENT_DVS);
    
    if(ScalerQCCheckCRCOn(0xE7, 0x44, 0x05, _D_DOMAIN_CRC))
    {
        usData |= _BIT0;
    }
  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5.OsdTestFrame0 END", 0x00);

    // frame 1
    DebugMessageScaler("5.OsdTestFrame1 Start", 0x00);
    ScalerQCOsdTestFrame1();
    ScalerTimerDelayXms(_FRAME_DELAY_TIME);

    if(ScalerQCCheckCRCOn(0xEF, 0x15, 0x8F, _D_DOMAIN_CRC))
    {
        usData |= _BIT1;
    }

	ScalerTimerDelayXms(_FRAME_DELAY_TIME);
    DebugMessageScaler("5.OsdTestFrame1 End", 0x00);
	    
    // frame 2
    DebugMessageScaler("5.OsdTestFrame2 Start", 0x00);
    ScalerQCOsdTestFrame2();
    ScalerTimerDelayXms(_FRAME_DELAY_TIME);

    if(ScalerQCCheckCRCOn(0x79, 0x9B, 0x78, _D_DOMAIN_CRC))
    {
        usData |= _BIT2;
    }

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);    
    DebugMessageScaler("5.OsdTestFrame2 End", 0x00); 

    // frame 3
    DebugMessageScaler("5.OsdTestFrame3 Start", 0x00);
    ScalerQCOsdTestFrame3();

    if(ScalerQCCheckCRCOn(0x4A, 0x73, 0x82, _D_DOMAIN_CRC))
    {
        usData |= _BIT3;
    }

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);
    DebugMessageScaler("5.OsdTestFrame3 End", 0x00);

    // frame9
    DebugMessageScaler("5.OsdTestFrame9 Start", 0x00);
    ScalerQCOsdTestFrame9();

    if(ScalerQCCheckCRCOn(0xAA, 0xC6, 0xCD , _D_DOMAIN_CRC))
    {
        usData |= _BIT4;
    }

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);
    DebugMessageScaler("5.OsdTestFrame9 End", 0x00); 
	   	 
    // frame 4
    DebugMessageScaler("5.OsdTestFrame4 Start", 0x00);
    ScalerQCOsdTestFrame4();

    if(ScalerQCCheckCRCOn(0x56, 0x9E, 0x6B, _D_DOMAIN_CRC))
    {
        usData |= _BIT5;
    }

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);
    DebugMessageScaler("5.OsdTestFrame4 End", 0x00);    

    // frame 5
    DebugMessageScaler("5.OsdTestFrame5 Start", 0x00);
    ScalerQCOsdTestFrame5();
            
    // blinking function    
    for(pData[0] = 0; pData[0] < 68; pData[0]++)    // Wait 64 frame
    {
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }

    if(ScalerQCCheckCRCOn(0xF2, 0x21, 0x43, _D_DOMAIN_CRC))
    {
        usData |= _BIT6;
    }

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);
    ScalerQCOsdCloseTestFrame5();
	
    DebugMessageScaler("5.OsdTestFrame5 End", 0x00);

    // frame7
    DebugMessageScaler("5.OsdTestFrame7 Start", 0x00);
    ScalerQCOsdTestFrame7(); 
    ScalerTimerDelayXms(_FRAME_DELAY_TIME);

    if(ScalerQCCheckCRCOn(0xBC, 0xB0, 0xD9, _D_DOMAIN_CRC))
    {
        usData |= _BIT7;
    }
    	
    ScalerTimerDelayXms(_FRAME_DELAY_TIME);
    DebugMessageScaler("5.OsdTestFrame7 End", 0x00);

    // frame8
    DebugMessageScaler("5.OsdTestFrame8 Start", 0x00);
    ScalerQCOsdTestFrame8();
    ScalerTimerDelayXms(_FRAME_DELAY_TIME);

    if(ScalerQCCheckCRCOn(0x14, 0x25, 0x8B, _D_DOMAIN_CRC))
    {
        usData |= _BIT8;
    }

    DebugMessageScaler("5.OsdTestFrame8 End", 0x00);
    ScalerTimerDelayXms(10);
    ScalerQCOsdRotatedFunctionEnable(_DISABLE);
    ScalerQCOsdNewRotatedFunctionControl(0x00, 0x00, 0x00, 0x00, _DISABLE);
    ScalerTimerDelayXms(10);
    	    
    // frame 6
    DebugMessageScaler("5.OsdTestFrame6 Start", 0x00);
    ScalerQCOsdTestFrame6(); 

    if(ScalerQCCheckCRCOn(0x7E, 0x87, 0x1C, _D_DOMAIN_CRC))    //     
    {
        usData |= _BIT9;
    } 

    DebugMessageScaler("5.OsdTestFrame6 End", 0x00);    	

    // frame 10
    DebugMessageScaler("5.OsdTestFrame10 Start", 0x00);

    ScalerQCOsdTestFrame10();  

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);  

    if(ScalerQCCheckCRCOn(0x14, 0x4D, 0x70, _D_DOMAIN_CRC))    //     
    {
        usData |= _BIT10;
    } 
           
    DebugMessageScaler("5.OsdTestFrame10 End", 0x00); 
   
    ScalerQCOsdOverlayEnable(_DISABLE, _DISABLE);                                    
    ScalerDDomainBackgroundEnable(0);

    if(usData == 0)
    {
        DebugMessageScaler("6.Osd Test Pass", 0);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6.Fail Mode", usData);
        DebugMessageScaler("6.Osd Test Fail", 0);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// QC Process
//--------------------------------------------------
bit ScalerQCOSDTest(void)
{
    bit result = 0;
    
    DebugMessageScaler("5. OSD Start", 0x00);
   
    result = ScalerQCOsdTestProc();
        	
    DebugMessageScaler("5. OSD End", 0x00);

    return result;
}

#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)
