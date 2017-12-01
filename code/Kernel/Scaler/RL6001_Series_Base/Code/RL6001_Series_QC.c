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
// ID Code      : RL6001_Series_QC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6001_SERIES_QC__

#include "ScalerFunctionInclude.h"

#if(_FACTORY_RTD_QC_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _TEST_PASS                                      0
#define _TEST_FAIL                                      1

#define _GRAY                                           0
#define _MASS                                           1

#define _MSB                                            0
#define _LSB                                            1

#define _I_DOMAIN_CRC  									0
#define _M_DOMAIN_CRC									1
#define _D_DOMAIN_CRC									2

// Defineions of SDRAM parameter
#define _ROW_RD_DELAY                                   (3)  // 0~2:Reserved, 3~5:3~5 MCLK, 6~7:Reserved
#define _ROW_WR_DELAY                                   (2)  // 0~1:Reserved, 2~5:2~5 MCLK, 6~7:Reserved
#define _SDR_ROW_DELAY                                  ((_ROW_RD_DELAY << 3) | (_ROW_WR_DELAY))
#define _SDR_COL_DELAY                                  ((3 << 5) | 0x04) // 0~1:Reserved, 2~3:2~3 MCLK, 4~7:Reserved

// Definitions of MPLL N Code
#define _MPLL_N_CODE                                    (2)

#define _FRAME_DELAY_TIME			 	 	            30
#define _CRC_DELAY_TIME  					            30
#define _DISPLAY_DELAY_TIME                             1000

//----------------------------------------------------------------------------
// HDMI QC Test
//----------------------------------------------------------------------------
#if(_HDMI_SUPPORT == _ON)
#define _HDMI_CRC0                   0x69
#define _HDMI_CRC1                   0x3A
#define _HDMI_CRC2                   0xCD
#define _HDMI_CRC3                   0xB3
#define _HDMI_CRC4                   0x6A
#define _HDMI_CRC5                   0xA8
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Description  : I Domain Dither Table 10 -> 8 Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_TABLE[] =
{
    // 10 --> 8
    0x01, 0x32, 0x12, 0x03, 0x23, 0x10, 0x30, 0x21,
    0x23, 0x10, 0x30, 0x21, 0x01, 0x32, 0x12, 0x03,
    0x30, 0x21, 0x01, 0x32, 0x12, 0x03, 0x23, 0x10,
};

//--------------------------------------------------
// Description  : I Domain Dither Table 10 -> 6 Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_10_6_TABLE[] = 
{
    // 10 --> 6
    0x07, 0xF8, 0x69, 0x1E, 0xAD, 0x52, 0xC3, 0xB4,
    0xAD, 0x52, 0xC3, 0xB4, 0x07, 0xF8, 0x69, 0x1E,
    0xAD, 0x52, 0x69, 0x1E, 0xC3, 0xB4, 0x07, 0xF8,
};

//--------------------------------------------------
// Description  : I Domain Dither Sequence Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_SEQ_TABLE[] =
{
    0xE4, 0xA2, 0x05, 0x37, 0xF6, 0x31, 0x69, 0xCB, 0x1F, 0xD2, 0xB0, 0xE6,
    0x45, 0x1B, 0x87, 0xC6, 0x9E, 0xB4, 0xC6, 0x38, 0xD4, 0xDB, 0x12, 0x1B,
};

//--------------------------------------------------
// Description  : D Domain Dither Table 10 -> 8 Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_D_DOMAIN_DITHER_TABLE[] =
{
    // 10 --> 8
    0x01, 0x32, 0x12, 0x03, 0x23, 0x10, 0x30, 0x21,
    0x23, 0x10, 0x30, 0x21, 0x01, 0x32, 0x12, 0x03,
    0x30, 0x21, 0x01, 0x32, 0x12, 0x03, 0x23, 0x10,
};

//--------------------------------------------------
// Description  : D Domain Dither Table 10 -> 6 Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_D_DOMAIN_DITHER_10_6_TABLE[] = 
{
    // 10 --> 6
    0x07, 0xF8, 0x69, 0x1E, 0xAD, 0x52, 0xC3, 0xB4,
    0xAD, 0x52, 0xC3, 0xB4, 0x07, 0xF8, 0x69, 0x1E,
    0xAD, 0x52, 0x69, 0x1E, 0xC3, 0xB4, 0x07, 0xF8,
};

//--------------------------------------------------
// Description  : D Domain Dither Sequence Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_D_DOMAIN_DITHER_SEQ_TABLE[] =
{
    0xE4, 0xA2, 0x05, 0x37, 0xF6, 0x31, 0x69, 0xCB, 0x1F, 0xD2, 0xB0, 0xE6,
    0x45, 0x1B, 0x87, 0xC6, 0x9E, 0xB4, 0xC6, 0x38, 0xD4, 0xDB, 0x12, 0x1B,
};

//--------------------------------------------------
// Description  : Dither Offset Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_DITHER_TEMOFFSET[] = 
{
    0xFF, 0xFF, 0xFF, 0xFF,
};
//--------------------------------------------------
// Description  : Highlight Window Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_HIGHLIGHT_WINDOW_SETTING[] =
{
    0x00,0x55,0x02,0xAA,0x00,0x55,0x02,0xAA,0x0F,0x3F,0x3F,0x3F,0x00,0x00,
};

//--------------------------------------------------
// Description  : DCC Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_DCC_SETTING1[] =		
{
    //control
    0x00, 0x00, 0x00,
    0x00, 0xFF, 0x08,
    0x00, 0x00, 0xFF,

    //usercurve
    0x10, 0x20, 0x30, 0x40,
    0x50, 0x60, 0x70, 0x80,
    0x90, 0xA0, 0xB0, 0xC0,
    0xD0, 0xE0, 0xF0, 0x00,
    0x00, 0x00, 0x00,
    0x50, 0x48, 0x34, 0xFF,
};

BYTE code tQC_DCC_SETTING2[] =	   
{
    //control
    0x84, 0x00, 0x00,
    0xB4, 0xFF, 0x08,
    0x00, 0x00, 0xFF,

    //usercurve
    0x10, 0x20, 0x30, 0x40,
    0x50, 0x60, 0x70, 0x80,
    0x85, 0x90, 0xA0, 0xB0, 
	0xC0, 0xD0, 0xE0, 0xF0, 
    0x00, 0x00, 0x20,
    0x50, 0x48, 0x34, 0x11,
};

//--------------------------------------------------
// Description  : ICM Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_ICM_Modify0[] =
{
	0x01, 0xa7, 0x53,
	0x09, 0x04, 0x10, 0x08, 0x19, 0x0a, 0x20, 0x0e, 
	0x1a, 0x08, 0x14, 0x01, 0x0d, 0xfa, 0x06, 0xf3, 
	0xf9, 0xfd, 0xf4, 0xfa, 0xed, 0xf7, 0xe8, 0xf5, 
	0xec, 0xf9, 0xf2, 0xfe, 0xf7, 0x02, 0xfd, 0x06, 
	0xf7, 0xf9, 0xee, 0xf3, 0xe4, 0xec, 0xdb, 0xe5, 
	0xe1, 0xf1, 0xe8, 0xfd, 0xef, 0x0a, 0xf5, 0x17, 
};

BYTE code tQC_ICM_Modify1[] =
{
	0x04, 0x31, 0x53,
	0x02, 0x0a, 0x03, 0x14, 0x04, 0x1e, 0x06, 0x28, 
	0x08, 0x1e, 0x0b, 0x14, 0x0e, 0x0a, 0x0f, 0x00, 
	0xff, 0xf8, 0xfe, 0xf1, 0xfd, 0xe9, 0xfc, 0xe2, 
	0xfb, 0xe9, 0xfa, 0xf1, 0xf9, 0xf8, 0xf8, 0x00, 
	0x01, 0xf3, 0x02, 0xe7, 0x02, 0xda, 0x03, 0xce, 
	0xfc, 0xda, 0xf5, 0xe7, 0xee, 0xf3, 0xe6, 0x00, 
};

BYTE code tQC_ICM_Modify2[] =
{
	0x06, 0xFC, 0x53,
	0xf9, 0x06, 0xf2, 0x0a, 0xea, 0x10, 0xe2, 0x15, 
	0xeb, 0x13, 0xf4, 0x11, 0xfd, 0x0f, 0x06, 0x0c, 
	0x06, 0xfc, 0x0b, 0xf8, 0x11, 0xf4, 0x16, 0xf1, 
	0x11, 0xf2, 0x09, 0xf5, 0x03, 0xf7, 0xfd, 0xfa, 
	0x0b, 0xfb, 0x15, 0xf7, 0x1f, 0xf3, 0x29, 0xee, 
	0x1d, 0xed, 0x0f, 0xed, 0x03, 0xed, 0xf5, 0xec 
};

BYTE code tQC_ICM_Modify3[] =
{
	0x09, 0xa6, 0x53,
	0xf7, 0xfc, 0xf0, 0xf9, 0xe7, 0xf5, 0xdf, 0xf1, 
	0xe6, 0xf9, 0xed, 0x00, 0xf3, 0x06, 0xfa, 0x0d, 
	0x06, 0x03, 0x0c, 0x06, 0x13, 0x09, 0x18, 0x0b, 
	0x13, 0x07, 0x0e, 0x03, 0x09, 0xfe, 0x03, 0xf9, 
	0x09, 0x07, 0x12, 0x0d, 0x1c, 0x14, 0x25, 0x1b, 
	0x1f, 0x0f, 0x18, 0x02, 0x12, 0xf6, 0x0b, 0xea, 
};

BYTE code tQC_ICM_Modify4[] =
{
	0x0C, 0x51, 0x53,
	0xff, 0xf6, 0xfe, 0xec, 0xfd, 0xe2, 0xfc, 0xd8, 
	0xf9, 0xe2, 0xf6, 0xec, 0xf3, 0xf6, 0xf0, 0x00, 
	0x00, 0x08, 0x02, 0x0f, 0x02, 0x17, 0x02, 0x1e, 
	0x04, 0x17, 0x05, 0x0f, 0x06, 0x08, 0x08, 0x00, 
	0xff, 0x0d, 0xfd, 0x19, 0xfb, 0x26, 0xfa, 0x32, 
	0x02, 0x26, 0x0a, 0x19, 0x12, 0x0d, 0x1a, 0x00,
};

BYTE code tQC_ICM_Modify5[] =
{
	0x0E, 0xDB, 0x53,
	0x07, 0xfa, 0x0e, 0xf5, 0x15, 0xef, 0x1d, 0xe9, 
	0x14, 0xeb, 0x0c, 0xee, 0x02, 0xf1, 0xf9, 0xf4, 
	0xfa, 0x05, 0xf5, 0x09, 0xf0, 0x0d, 0xeb, 0x11, 
	0xf0, 0x0f, 0xf7, 0x0b, 0xfd, 0x09, 0x03, 0x06, 
	0xf5, 0x05, 0xec, 0x09, 0xe1, 0x0f, 0xd7, 0x14, 
	0xe4, 0x13, 0xf1, 0x14, 0xfd, 0x14, 0x0a, 0x14 
};

//--------------------------------------------------
// Description  : Contrast & Brightness Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_CON_BRI_SETTING[] =
{
    0xAA,0x55,0xAA,0x55,0xAA,0x55,0x55,0xAA,0x55,0xAA,0x55,0xAA,
};

//--------------------------------------------------
// Description  : Output Gamma Table for R Channel
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tOutputGammaR[] =
{   
    0x00,   0x80,   0x0C,
    0x01,   0x00,   0x14,
    0x01,   0x80,   0x00,
    0x02,   0x90,   0x22,
    0x00,   0x00,   0x2F,
    0x04,   0x10,   0x4E,
    0x05,   0x90,   0x63,
    0x06,   0xB0,   0x72,
    0x00,   0x00,   0x00,
    0x07,   0x90,   0x91,
    0x0A,   0x40,   0xB5,
    0x0C,   0x30,   0xD1,
    0x0D,   0xC0,   0xE7,
    0x0F,   0x00,   0xFA,
    0x10,   0x31,   0x0D,
    0x11,   0x61,   0x22,
    0x12,   0xB1,   0x34,
    0x13,   0xD1,   0x45,
    0x14,   0xD1,   0x55,
    0x15,   0xD1,   0x65,
    0x16,   0xD1,   0x74,
    0x17,   0xB1,   0x82,
    0x18,   0x81,   0x8F,
    0x19,   0x51,   0x9B,
    0x1A,   0x01,   0xA6,
    0x1A,   0xC1,   0xB2,
    0x1B,   0x71,   0xBD,
    0x1C,   0x21,   0xC8,
    0x1C,   0xD1,   0xD2,
    0x1D,   0x71,   0xDD,
    0x1E,   0x21,   0xE7,
    0x1E,   0xC1,   0xF1,
    0x1F,   0x51,   0xFA,
    0x1F,   0xF2,   0x03,
    0x20,   0x82,   0x0D,
    0x21,   0x12,   0x15,
    0x21,   0xA2,   0x1E,
    0x22,   0x22,   0x26,
    0x22,   0xB2,   0x2F,
    0x23,   0x32,   0x37,
    0x23,   0xB2,   0x3F,
    0x24,   0x32,   0x47,
    0x24,   0xB2,   0x4F,
    0x25,   0x32,   0x57,
    0x25,   0xB2,   0x5F,
    0x26,   0x32,   0x67,
    0x26,   0xB2,   0x6E,
    0x27,   0x22,   0x76,
    0x27,   0x92,   0x7D,
    0x28,   0x02,   0x84,
    0x28,   0x72,   0x8B,
    0x28,   0xE2,   0x91,
    0x29,   0x52,   0x98,
    0x29,   0xB2,   0x9E,
    0x2A,   0x22,   0xA5,
    0x2A,   0x82,   0xAB,
    0x2A,   0xE2,   0xB1,
    0x2B,   0x42,   0xB7,
    0x2B,   0xA2,   0xBD,
    0x2C,   0x02,   0xC3,
    0x2C,   0x62,   0xC9,
    0x2C,   0xC2,   0xCF,
    0x2D,   0x22,   0xD5,
    0x2D,   0x82,   0xDB,
    0x2E,   0x42,   0xE7,
    0x2E,   0x92,   0xEC,
    0x2E,   0xE2,   0xF0,
    0x2F,   0x22,   0xF5,
    0x2F,   0x72,   0xF9,
    0x2F,   0xB2,   0xFD,
    0x2F,   0xE3,   0x00,
    0x30,   0x23,   0x04,
    0x30,   0x63,   0x07,
    0x30,   0x93,   0x0B,
    0x30,   0xD3,   0x0E,
    0x31,   0x03,   0x11,
    0x31,   0x33,   0x14,
    0x31,   0x63,   0x17,
    0x31,   0x93,   0x1A,
    0x31,   0xC3,   0x1D,
    0x31,   0xD3,   0x1E,
    0x31,   0xF3,   0x1F,
    0x32,   0x03,   0x21,
    0x32,   0x33,   0x24,
    0x32,   0x63,   0x27,
    0x32,   0x83,   0x2A,
    0x32,   0xB3,   0x2D,
    0x32,   0xE3,   0x2F,
    0x33,   0x13,   0x32,
    0x33,   0x43,   0x35,
    0x33,   0x63,   0x38,
    0x33,   0x93,   0x3B,
    0x33,   0xC3,   0x3D,
    0x33,   0xF3,   0x40,
    0x34,   0x23,   0x43,
    0x34,   0x43,   0x46,
    0x34,   0x73,   0x49,
    0x34,   0xA3,   0x4B,
    0x34,   0xD3,   0x4E,
    0x35,   0x03,   0x51,
    0x35,   0x23,   0x54,
    0x35,   0x53,   0x57,
    0x35,   0x83,   0x5A,
    0x35,   0xB3,   0x5C,
    0x35,   0xD3,   0x5E,
    0x35,   0xF3,   0x60,
    0x36,   0x13,   0x62,
    0x36,   0x43,   0x65,
    0x36,   0x63,   0x68,
    0x36,   0x93,   0x6B,
    0x36,   0xC3,   0x6E,
    0x37,   0x03,   0x71,
    0x37,   0x33,   0x74,
    0x37,   0x63,   0x78,
    0x37,   0x93,   0x7B,
    0x37,   0xD3,   0x7E,
    0x38,   0x03,   0x82,
    0x38,   0x43,   0x85,
    0x38,   0x73,   0x89,
    0x38,   0xB3,   0x8D,
    0x38,   0xF3,   0x91,
    0x39,   0x33,   0x95,
    0x39,   0x73,   0x99,
    0x39,   0xB3,   0x9D,
    0x39,   0xF3,   0xA1,
    0x3A,   0x33,   0xA5,
    0x3A,   0x83,   0xAA,
    0x3A,   0xD3,   0xB0,
    0x3B,   0x23,   0xB5,
    0x3B,   0x83,   0xBB,
    0x3B,   0xE3,   0xC2,
    0x3C,   0x63,   0xC9,
    0x3C,   0xE3,   0xD2,
    0x3D,   0x73,   0xDE,
    0x3E,   0x13,   0xE8,
    0x3F,   0x43,   0xF4,
    0x3F,   0x40,   0x00,
};

//--------------------------------------------------
// Description  : Output Gamma Table for G Channel
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tOutputGammaG[] =
{   
    0x00,   0x80,   0x0C,
    0x01,   0x00,   0x14,
    0x01,   0x80,   0x00,
    0x02,   0x80,   0x21,
    0x00,   0x00,   0x2E,
    0x03,   0xE0,   0x4A,
    0x05,   0x40,   0x5D,
    0x06,   0x40,   0x6B,
    0x00,   0x00,   0x00,
    0x07,   0x20,   0x88,
    0x09,   0xA0,   0xA9,
    0x0B,   0x70,   0xC3,
    0x0C,   0xF0,   0xD9,
    0x0E,   0x20,   0xEB,
    0x0F,   0x30,   0xFB,
    0x10,   0x31,   0x0B,
    0x11,   0x31,   0x1B,
    0x12,   0x51,   0x2D,
    0x13,   0x41,   0x3C,
    0x14,   0x31,   0x4A,
    0x15,   0x11,   0x58,
    0x15,   0xF1,   0x65,
    0x16,   0xC1,   0x72,
    0x17,   0x81,   0x7E,
    0x18,   0x31,   0x89,
    0x18,   0xF1,   0x94,
    0x19,   0x91,   0x9E,
    0x1A,   0x31,   0xA8,
    0x1A,   0xD1,   0xB2,
    0x1B,   0x71,   0xBC,
    0x1C,   0x01,   0xC5,
    0x1C,   0xA1,   0xCE,
    0x1D,   0x31,   0xD7,
    0x1D,   0xC1,   0xE0,
    0x1E,   0x51,   0xE9,
    0x1E,   0xD1,   0xF2,
    0x1F,   0x61,   0xFA,
    0x1F,   0xE2,   0x02,
    0x20,   0x62,   0x0A,
    0x20,   0xE2,   0x12,
    0x21,   0x62,   0x1A,
    0x21,   0xE2,   0x21,
    0x22,   0x52,   0x29,
    0x22,   0xC2,   0x30,
    0x23,   0x42,   0x37,
    0x23,   0xB2,   0x3F,
    0x24,   0x22,   0x46,
    0x24,   0x92,   0x4D,
    0x25,   0x12,   0x54,
    0x25,   0x82,   0x5B,
    0x25,   0xF2,   0x62,
    0x26,   0x62,   0x69,
    0x26,   0xC2,   0x70,
    0x27,   0x32,   0x76,
    0x27,   0xA2,   0x7D,
    0x28,   0x02,   0x83,
    0x28,   0x62,   0x89,
    0x28,   0xC2,   0x8F,
    0x29,   0x32,   0x96,
    0x29,   0x92,   0x9C,
    0x29,   0xE2,   0xA1,
    0x2A,   0x42,   0xA7,
    0x2A,   0xA2,   0xAD,
    0x2B,   0x02,   0xB3,
    0x2B,   0x52,   0xB8,
    0x2B,   0xB2,   0xBE,
    0x2C,   0x12,   0xC3,
    0x2C,   0x62,   0xC9,
    0x2C,   0xC2,   0xCE,
    0x2D,   0x12,   0xD4,
    0x2D,   0x62,   0xD9,
    0x2D,   0xC2,   0xE4,
    0x2E,   0x72,   0xE9,
    0x2E,   0xB2,   0xEE,
    0x2F,   0x02,   0xF2,
    0x2F,   0x42,   0xF6,
    0x2F,   0x82,   0xFA,
    0x2F,   0xC2,   0xFE,
    0x30,   0x03,   0x01,
    0x30,   0x33,   0x05,
    0x30,   0x73,   0x08,
    0x30,   0xA3,   0x0C,
    0x30,   0xD3,   0x0F,
    0x31,   0x03,   0x12,
    0x31,   0x33,   0x15,
    0x31,   0x63,   0x18,
    0x31,   0x93,   0x1B,
    0x31,   0xC3,   0x1D,
    0x31,   0xD3,   0x1E,
    0x31,   0xF3,   0x1F,
    0x32,   0x03,   0x21,
    0x32,   0x33,   0x24,
    0x32,   0x53,   0x27,
    0x32,   0x83,   0x29,
    0x32,   0xB3,   0x2C,
    0x32,   0xE3,   0x2F,
    0x33,   0x13,   0x32,
    0x33,   0x33,   0x35,
    0x33,   0x63,   0x38,
    0x33,   0x93,   0x3B,
    0x33,   0xC3,   0x3E,
    0x33,   0xF3,   0x40,
    0x34,   0x23,   0x43,
    0x34,   0x53,   0x46,
    0x34,   0x83,   0x49,
    0x34,   0xB3,   0x4C,
    0x34,   0xE3,   0x4F,
    0x35,   0x13,   0x52,
    0x35,   0x43,   0x55,
    0x35,   0x73,   0x59,
    0x35,   0xA3,   0x5C,
    0x35,   0xD3,   0x5E,
    0x35,   0xF3,   0x60,
    0x36,   0x13,   0x62,
    0x36,   0x43,   0x66,
    0x36,   0x73,   0x69,
    0x36,   0xB3,   0x6C,
    0x36,   0xE3,   0x70,
    0x37,   0x23,   0x74,
    0x37,   0x53,   0x77,
    0x37,   0x93,   0x7B,
    0x37,   0xD3,   0x7F,
    0x38,   0x13,   0x83,
    0x38,   0x63,   0x88,
    0x38,   0xA3,   0x8C,
    0x38,   0xF3,   0x91,
    0x39,   0x43,   0x96,
    0x39,   0x93,   0x9C,
    0x3A,   0x03,   0xA4,
    0x3A,   0x73,   0xAA,
    0x3A,   0xE3,   0xB1,
    0x3B,   0x53,   0xB9,
    0x3B,   0xE3,   0xC3,
    0x3C,   0x83,   0xCE,
    0x3D,   0x53,   0xDE,
    0x3E,   0x43,   0xF0,
    0x3F,   0x00,   0x00,
};

//--------------------------------------------------
// Description  : Output Gamma Table for B Channel
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tOutputGammaB[] =
{   
    0x00,   0x80,   0x0A,
    0x00,   0xD0,   0x0F,
    0x01,   0x10,   0x00,
    0x01,   0xF0,   0x19,
    0x00,   0x00,   0x23,
    0x03,   0x10,   0x3A,
    0x04,   0x20,   0x49,
    0x04,   0xF0,   0x55,
    0x00,   0x00,   0x00,
    0x05,   0xA0,   0x6B,
    0x07,   0xA0,   0x86,
    0x09,   0x20,   0x9C,
    0x0A,   0x50,   0xAE,
    0x0B,   0x60,   0xBD,
    0x0C,   0x40,   0xCB,
    0x0D,   0x20,   0xD8,
    0x0D,   0xE0,   0xE4,
    0x0E,   0x90,   0xEE,
    0x0F,   0x20,   0xF7,
    0x0F,   0xC1,   0x01,
    0x10,   0x61,   0x0B,
    0x11,   0x01,   0x15,
    0x11,   0xA1,   0x21,
    0x12,   0x61,   0x2B,
    0x13,   0x01,   0x34,
    0x13,   0x91,   0x3E,
    0x14,   0x21,   0x47,
    0x14,   0xB1,   0x50,
    0x15,   0x41,   0x58,
    0x15,   0xC1,   0x61,
    0x16,   0x51,   0x69,
    0x16,   0xD1,   0x71,
    0x17,   0x51,   0x79,
    0x17,   0xC1,   0x80,
    0x18,   0x41,   0x88,
    0x18,   0xB1,   0x8F,
    0x19,   0x21,   0x96,
    0x19,   0x91,   0x9C,
    0x19,   0xF1,   0xA3,
    0x1A,   0x61,   0xA9,
    0x1A,   0xC1,   0xB0,
    0x1B,   0x31,   0xB6,
    0x1B,   0x91,   0xBD,
    0x1C,   0x01,   0xC3,
    0x1C,   0x61,   0xC9,
    0x1C,   0xC1,   0xCF,
    0x1D,   0x21,   0xD5,
    0x1D,   0x81,   0xDB,
    0x1D,   0xE1,   0xE1,
    0x1E,   0x41,   0xE7,
    0x1E,   0xA1,   0xED,
    0x1F,   0x01,   0xF3,
    0x1F,   0x61,   0xF9,
    0x1F,   0xB1,   0xFE,
    0x20,   0x12,   0x04,
    0x20,   0x72,   0x0A,
    0x20,   0xC2,   0x0F,
    0x21,   0x22,   0x15,
    0x21,   0x72,   0x1A,
    0x21,   0xD2,   0x1F,
    0x22,   0x22,   0x24,
    0x22,   0x72,   0x2A,
    0x22,   0xC2,   0x2F,
    0x23,   0x22,   0x34,
    0x23,   0x72,   0x3A,
    0x23,   0xC2,   0x3F,
    0x24,   0x22,   0x44,
    0x24,   0x72,   0x49,
    0x24,   0xC2,   0x4F,
    0x25,   0x12,   0x54,
    0x25,   0x62,   0x59,
    0x25,   0xC2,   0x5E,
    0x26,   0x12,   0x64,
    0x26,   0x62,   0x69,
    0x26,   0xB2,   0x6E,
    0x27,   0x02,   0x73,
    0x27,   0x52,   0x78,
    0x27,   0xA2,   0x7D,
    0x27,   0xF2,   0x82,
    0x28,   0x42,   0x87,
    0x28,   0x92,   0x8C,
    0x28,   0xE2,   0x91,
    0x29,   0x32,   0x95,
    0x29,   0x82,   0x9A,
    0x29,   0xD2,   0x9F,
    0x2A,   0x12,   0xA3,
    0x2A,   0x62,   0xA8,
    0x2A,   0xA2,   0xAD,
    0x2A,   0xF2,   0xB2,
    0x2B,   0x42,   0xB6,
    0x2B,   0x92,   0xBB,
    0x2B,   0xD2,   0xC0,
    0x2C,   0x22,   0xC4,
    0x2C,   0x72,   0xC9,
    0x2C,   0xC2,   0xCE,
    0x2D,   0x02,   0xD3,
    0x2D,   0x52,   0xD7,
    0x2D,   0xA2,   0xDC,
    0x2E,   0x22,   0xE5,
    0x2E,   0x72,   0xE9,
    0x2E,   0xB2,   0xEE,
    0x2F,   0x02,   0xF2,
    0x2F,   0x42,   0xF6,
    0x2F,   0x82,   0xFA,
    0x2F,   0xC2,   0xFE,
    0x30,   0x03,   0x01,
    0x30,   0x33,   0x05,
    0x30,   0x73,   0x09,
    0x30,   0xA3,   0x0C,
    0x30,   0xE3,   0x10,
    0x31,   0x13,   0x13,
    0x31,   0x53,   0x16,
    0x31,   0x83,   0x1A,
    0x31,   0xB3,   0x1C,
    0x31,   0xD3,   0x1D,
    0x31,   0xE3,   0x1E,
    0x31,   0xF3,   0x20,
    0x32,   0x03,   0x22,
    0x32,   0x33,   0x25,
    0x32,   0x73,   0x28,
    0x32,   0xA3,   0x2C,
    0x32,   0xD3,   0x2F,
    0x33,   0x13,   0x33,
    0x33,   0x53,   0x37,
    0x33,   0x93,   0x3B,
    0x33,   0xD3,   0x3F,
    0x34,   0x13,   0x44,
    0x34,   0x63,   0x49,
    0x34,   0xB3,   0x4E,
    0x35,   0x13,   0x54,
    0x35,   0x73,   0x5A,
    0x36,   0x13,   0x66,
    0x36,   0xA3,   0x6F,
    0x37,   0x43,   0x7A,
    0x38,   0x03,   0x80,
    0x38,   0x03,   0x80,
    0x38,   0x00,   0x00,
};

//--------------------------------------------------
// Description  : sRGB Matrix Table
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tSRGBMatrix[] =
{
    0x01, 0x90, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00,
    0x01, 0xFE, 0x01, 0xDF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x07, 0x01, 0xF3, 0x00, 0x00, 0x00, 0x00,
};

//--------------------------------------------------
// Description  : Input Gamma Table and Setting 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tInputGamma[] =
{
    0x00, 0x00, 0x14,
    0x02, 0x80, 0x3C,
    0x05, 0x50, 0x72,
    0x09, 0x50, 0xBE,
    0x0E, 0xC1, 0x20,
    0x15, 0xA1, 0x9B,
    0x1E, 0x22, 0x30,
    0x28, 0x52, 0xE1,
    0x34, 0x53, 0xAF,
    0x10, 0x91, 0x27,
    0x14, 0x71, 0x6A,
    0x18, 0xE1, 0xB5,
    0x1D, 0xD2, 0x08,
    0x23, 0x52, 0x64,
    0x29, 0x52, 0xC9,
    0x2F, 0xE3, 0x36,
    0x37, 0x13, 0xAE,
    0x3E, 0xD1, 0x0C,
    0x11, 0xD1, 0x2E,
    0x14, 0x01, 0x53,
    0x16, 0x71, 0x7B,
    0x18, 0xF1, 0xA5,
    0x1B, 0xB1, 0xD2,
    0x1E, 0x92, 0x01,
    0x21, 0xA2, 0x33,
    0x24, 0xD2, 0x68,
    0x28, 0x32, 0xA0,
    0x2B, 0xC2, 0xDA,
    0x2F, 0x83, 0x17,
    0x33, 0x73, 0x58,
    0x37, 0x93, 0x9B,
    0x3B, 0xD3, 0xE1,
    0x3F, 0xC0, 0x00,
    0x11, 0x22,
};

#if((_SDRAM_SIZE_CONFIG == _1M_16BIT) || (_SDRAM_SIZE_CONFIG == _1M_32BIT)||(_SDRAM_SIZE_CONFIG == _2M_32BIT))
BYTE code tQC_OD_Token1[] = 
{	
     9,  _AUTOINC,       P4_A1_SDR_CTRL0,               _SDR_ROW_DELAY, _SDR_COL_DELAY, 0x0d, 0x83, 0x63, 0x00, 
     14, _AUTOINC,       P4_A7_SDR_AREF_CNT,            0xc0, 0x00, 0x00, 0x11, 0x22, 0x00, 0x00, 0x00, 0x00, 0x44, 0x88,
	 10,  _AUTOINC,      P4_C0_SDR_CLK_DLY1,            0x00, 0x14, 0x00, 0x34, 0x00, 0x34, 0x00, 0x00, 0x00, 0x00,
	//11,	_AUTOINC,	_P4_SDR_RSC_AREF_AA,	0x11,	0x00,	0x00,	0x00,	0x00,	0x00,	0x44,	0x88,
	_END
};

BYTE code tQC_OD_Token2[] = 
{	 
     9,  _AUTOINC,       P4_A1_SDR_CTRL0,               _SDR_ROW_DELAY, _SDR_COL_DELAY, 0x0d, 0x83, 0x23, 0x00, 
    14, _AUTOINC,        P4_A7_SDR_AREF_CNT,             0xc0, 0x00, 0x00, 0x11, 0x22, 0x00, 0x00, 0x00, 0x00, 0x44, 0x88,
    10,  _AUTOINC,       P4_C0_SDR_CLK_DLY1,            0x00, 0x14, 0x00, 0x2c, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x00,
	//11,	_AUTOINC,	_P4_SDR_RSC_AREF_AA,	0x11,	0x00,	0x00,	0x00,	0x00,	0x00,	0x44,	0x88,
	_END
};

BYTE code tQC_OD_FIFO1[] = 
{
//	12,	_AUTOINC,	_P3_LS_WTLVL_W_C0,		0x3C,	0x3C,	0x0B,	0xFF,	0x78,	0x78,	0x00,	0x00,	0x00,
	12,	_AUTOINC,	P3_C0_LS_WTLVL_W,		0x40,	0x40,	0x0F,	0x24,	0x80,	0x40,	0x00,	0x00,	0x00,

	_END
};

BYTE code tQC_OD_FIFO2[] = 
{
	12,	_AUTOINC,	P3_C0_LS_WTLVL_W,		0x40,	0x40,	0x0a,	0x18,	0x80,	0x40,	0x00,	0x00,	0x00,

	_END
};
  
BYTE code tQC_OD_YUV[] = 
{
	6,	_AUTOINC,	P3_CC_LS_FRAME0,		0x18,	0x99,	0x08,
	_END
};

BYTE code tQC_OD_YUVOFF[] = 
{
	6,	_AUTOINC,	P3_CC_LS_FRAME0,		0x00,	0x00,	0x00,
	_END
};

BYTE code tOD_TABLE_COMMON[] =
{
    0x00,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,
    0x04,0x00,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,
    0x09,0x05,0x00,0xFF,0x00,0xFE,0xFA,0xFD,0xFA,0xFA,0xFA,0xFD,0xFA,0xFA,0xFA,0xFA,0xFA,
    0x11,0x07,0x04,0x00,0xFF,0xFC,0xFC,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF0,
    0x17,0x0F,0x09,0x04,0x00,0xFD,0xFA,0xFB,0xF4,0xF4,0xF4,0xF4,0xF4,0xF1,0xED,0xE7,0xE4,
    0x1B,0x14,0x0D,0x08,0x03,0x00,0xFD,0xFA,0xF3,0xF3,0xF3,0xF0,0xEE,0xE9,0xE4,0xDD,0xDA,
    0x21,0x18,0x12,0x0D,0x08,0x04,0x00,0xFD,0xF8,0xF3,0xF1,0xEE,0xE9,0xE5,0xE2,0xD6,0xD4,
    0x27,0x1C,0x1B,0x14,0x0F,0x0A,0x05,0x00,0xFC,0xF8,0xF3,0xEF,0xE9,0xE3,0xE1,0xD6,0xCE,
    0x2B,0x21,0x20,0x1E,0x16,0x12,0x0D,0x07,0x00,0xFC,0xF7,0xF1,0xEB,0xE3,0xDF,0xD5,0xCC,
    0x2F,0x25,0x25,0x21,0x1B,0x1B,0x14,0x0E,0x08,0x00,0xFA,0xF3,0xEC,0xE2,0xDE,0xD6,0xCB,
    0x32,0x27,0x25,0x21,0x1E,0x1E,0x1B,0x15,0x0F,0x08,0x00,0xFA,0xF0,0xE5,0xDE,0xD6,0xCC,
    0x2E,0x26,0x25,0x23,0x21,0x1F,0x1B,0x18,0x12,0x0F,0x08,0x00,0xF7,0xE9,0xDF,0xD7,0xD0,
    0x29,0x24,0x24,0x23,0x20,0x20,0x1E,0x19,0x15,0x10,0x0D,0x08,0x00,0xF3,0xE1,0xDC,0xD4,
    0x24,0x21,0x20,0x1F,0x1D,0x1D,0x1B,0x19,0x17,0x14,0x12,0x0D,0x09,0x00,0xF3,0xE4,0xDD,
    0x1B,0x17,0x19,0x17,0x17,0x17,0x17,0x17,0x14,0x12,0x10,0x0D,0x0A,0x09,0x00,0xF0,0xE6,
    0x11,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0A,0x0B,0x0B,0x0B,0x0A,0x09,0x08,0x00,0xF1,
    0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x00,
};


code BYTE *tOD_TABLE[] =
{
    tOD_TABLE_COMMON,
};
#endif // End of #if((_SDRAM_SIZE_CONFIG == _1M_16BIT) || (_SDRAM_SIZE_CONFIG == _1M_32BIT)||(_SDRAM_SIZE_CONFIG == _2M_32BIT))

BYTE code tQC_OSD_TEST_FRAME0[]=
{
    4, _NON_AUTOINC, 0x6E, 0x00, // LUT must be double buffer
    ////////////////////Background & Alpha Blending////////////////////
    4, _NON_AUTOINC, 0x6c, 0x29, // bkg color access enable,OSD overlay enable
    		                     // blending level: 010 => 4/8
    6, _NON_AUTOINC, 0x6d, 0x55, 0x66, 0x77, // bkg color 85 grey

    ////////////////////Frame Control Registers////////////////////
    5, _AUTOINC,     0x90, 0xC0, 0x00, // frame control register
    6, _NON_AUTOINC, 0x92, 0x08, 0x09, 0xf9,  // 000h: delay V:71, H:39, disp_zone => middle, OSD circuit is activated
    
    5, _AUTOINC,     0x90, 0xC0, 0x02, 
    6, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x1f,  // 002h: match LSB [3:0], blending type 2 color [5:4]=10(win 8's border)
    5, _AUTOINC,     0x90, 0xC0, 0x03, 
    6, _NON_AUTOINC, 0x92, 0xAf, 0x44, 0x00,  // 003h: enable specific color blending
    										  // enable win7 special function (blending type 3)
    6, _NON_AUTOINC, 0x92, 0x03, 0x13, 0x40,  // 004h: fs_base = 0x103, fm_base = 0x403										  
    
    5, _AUTOINC,     0x90, 0xC0, 0x08,
    6, _NON_AUTOINC, 0x92, 0x28, 0x01, 0x00,  // 008h OSD 2 font funtction enable, row command base0 = 1, row command base1 = 0;
    6, _NON_AUTOINC, 0x92, 0x11, 0x0b, 0x03,  // 009h Font select base, font select base 0: 0x10b, font select base 1: 0x103
    6, _NON_AUTOINC, 0x92, 0x13, 0x55, 0x50,  // 00Ah
    6, _NON_AUTOINC, 0x92, 0x64, 0x00, 0x00,  // 00Bh: win 7 no blending for background 
    										  // 	   win 6 no blending for foreground
    6, _NON_AUTOINC, 0x92, 0x11, 0x01, 0xb5,  // 00Ch: font A delay
    6, _NON_AUTOINC, 0x92, 0x11, 0xff, 0xcc,  // OODh: font B delay 

    ////////////////////Window Control////////////////////
    5, _AUTOINC, 0x90,  0xC1, 0x00,  // window
    15, _NON_AUTOINC, 0x92,  0xFF, 0xFE, 0xFF,   0x11, 0x01, 0x01,  0x22, 0x01, 0x01, 0xF8, 0x01, 0x51, // win0
    15, _NON_AUTOINC, 0x92,  0xc7, 0xdc, 0x00,   0x11, 0x1F, 0x1F,  0x22, 0x1F, 0x1F, 0xE0, 0x02, 0x93, // win1
    15, _NON_AUTOINC, 0x92,  0xce, 0xba, 0x00,   0x11, 0x3D, 0x3D,  0x22, 0x3D, 0x3D, 0xE0, 0x03, 0x35, // win2
    15, _NON_AUTOINC, 0x92,  0xD5, 0x98, 0x00,   0x11, 0x5B, 0x5B,  0x22, 0x5B, 0x5B, 0xE0, 0x04, 0x97, // win3
    
    //15, _NON_AUTOINC, 0x92,  0xDC, 0x76, 0x00,   0x11, 0x79, 0x79,  0x22, 0x79, 0x79, 0xE0, 0x05, 0x19, // win4
    15, _NON_AUTOINC, 0x92,  0xEC, 0x76, 0x00,   0x11, 0x79, 0x79,  0x22, 0x79, 0x79, 0xE0, 0x05, 0x19, // win4  // 3D type 1, board: 5pixel

    //15, _NON_AUTOINC, 0x92,  0xE3, 0x54, 0xAF,   0x11, 0x97, 0x97,  0x22, 0x97, 0x97, 0xE8, 0x46, 0xFB, // win5
    15, _NON_AUTOINC, 0x92,  0xE4, 0x54, 0xAF,   0x11, 0x97, 0x97,  0x22, 0x97, 0x97, 0xE8, 0x46, 0xFB, // win5 // 3d type 1, board: 4pixel
   
    //15, _NON_AUTOINC, 0x92,  0xEA, 0x32, 0x87,   0x11, 0xB5, 0xB5,  0x22, 0xB5, 0xB5, 0xE0, 0x27, 0x5F, // win6 
    15, _NON_AUTOINC, 0x92,  0xD2, 0x32, 0x87,   0x11, 0xB5, 0xB5,  0x22, 0xB5, 0xB5, 0xE0, 0x27, 0x5F, // board 
    
    15, _NON_AUTOINC, 0x92,  0xF1, 0x10, 0x67,   0x11, 0xD3, 0xD3,  0x22, 0xD3, 0xD3, 0xE0, 0xC8, 0xF1, // win7
    15, _NON_AUTOINC, 0x92,  0x38, 0xFE, 0x57,   0x11, 0xF1, 0xF1,  0x22, 0xF1, 0xF1, 0xE0, 0x89, 0x53, // win8
    
    //15, _NON_AUTOINC, 0x92,  0x00, 0xDC, 0x1F,   0x22, 0x0F, 0x0F,  0x33, 0x0F, 0x0F, 0xE0, 0xEA, 0xF5, // win9
    15, _NON_AUTOINC, 0x92,  0xFF, 0xDC, 0x1F,   0x22, 0x0F, 0x0F,  0x33, 0x0F, 0x0F, 0xE0, 0xEA, 0xF5, // win9

    5, _AUTOINC,     0x90,  0xC1, 0x50,  // window special
    6, _NON_AUTOINC, 0x92,  0xff, 0xff, 0xff, // win0 
    5, _AUTOINC,     0x90,  0xC1, 0x5A,
    6, _NON_AUTOINC, 0x92,  0x87, 0x12, 0x46, // win5
    5, _AUTOINC,     0x90,  0xC1, 0x5C,
    6, _NON_AUTOINC, 0x92,  0x12, 0x87, 0x94, // win6
    5, _AUTOINC,     0x90,  0xC1, 0x5E,   
    6, _NON_AUTOINC, 0x92,  0x34, 0x56, 0x78, // win7
    5, _AUTOINC,     0x90,  0xC1, 0x60,
    6, _NON_AUTOINC, 0x92,  0x78, 0x65, 0x34, // win8
    5, _AUTOINC,     0x90,  0xC1, 0x62,
    6, _NON_AUTOINC, 0x92,  0x64, 0x34, 0x98, // win9

    
    // add for Brianna OSD function 2009/09/23 Start
    5, _AUTOINC, 0x90,  0xC2, 0x00,  // window 4-1~ 4-8
    // win4-1, H:(0x240, 0x340) V:(0x11F,0x21f), Type: shadow type 1, win color: 0x00, shadow color: 0x3f, pixel width: 8 pixels
    15, _NON_AUTOINC, 0x92,  0xFF, 0xFF, 0x00,   0x11, 0xA0, 0x1F,   0x22, 0xA0, 0x1F,  0xC0, 0x00, 0x11, // win4-1
    
    // Type: shadow type 2, win color: 0x30, shadow color: 0x3e, pixel width: 8 pixels
    15, _NON_AUTOINC, 0x92,  0xBF, 0xE0, 0x00,   0x11, 0xD0, 0x3D,   0x22, 0xD0, 0x3D,  0xE0, 0x10, 0x13, // win4-2
    
    // Type: shadow type 3, win color: 0x03, shadow color: 0x3d, pixel width: 8 pixels
    15, _NON_AUTOINC, 0x92,  0xBF, 0xD0, 0x00,   0x21, 0x00, 0x5B,   0x32, 0x00, 0x5B,  0xC0, 0x03, 0x15, // win4-3
    
    // Type: shadow type 4, win color: 0x0C, shadow color: 0x3c, pixel width: 5 pixels
    15, _NON_AUTOINC, 0x92,  0xA4, 0xC0, 0x00,   0x21, 0x30, 0x79,   0x32, 0x30, 0x79,  0xC0, 0x0C, 0x17, // win4-4
    
    // Type: 3D Button type 1, win color: 0x33, color1: 0x3F, color2: 0x00, pixel width: 6 pixels
    15, _NON_AUTOINC, 0x92,  0xAD, 0xF0, 0x00,   0x21, 0x50, 0x97,   0x32, 0x50, 0x97,  0xB0, 0x13, 0x19, // win4-5
    
    // Type: 3D Button type 2, win color: 0x3C, color1: 0x3F, color2: 0x00, pixel width: 4 pixels
    //15, _NON_AUTOINC, 0x92,  0x9C, 0xF0, 0x00,   0x21, 0x70, 0xB5,   0x32, 0x70, 0xB5,  0xB0, 0x1C, 0x1B, // win4-6
    15, _NON_AUTOINC, 0x92,  0xA4, 0xF0, 0x00,   0x21, 0x70, 0xB5,   0x32, 0x70, 0xB5,  0xB0, 0x1C, 0x1B, // win4-6
    
    // Type: reserved, win color: 0x3C, color1: 0x3F, color2: 0x00, pixel width: 3 pixels
    15, _NON_AUTOINC, 0x92,  0xFF, 0xFF, 0x00,   0x21, 0xA0, 0xD3,   0x32, 0xA0, 0xD3,  0xC0, 0x00, 0x1D, // win4-7
    
    // Type: Border, win color: 0x3F, color1: 0x00, color2: 0x00, pixel width: 4 pixels
    15, _NON_AUTOINC, 0x92,  0x1B, 0x00, 0x00,   0x22, 0xD0, 0x0F,   0x33, 0xD0, 0x0F,  0x20, 0x1F, 0x1F, // win4-8
    
    ////////////////////Row Command////////////////////
    5, _AUTOINC, 0x90,  0xD0, 0x00,  // row command base 0

    6, _NON_AUTOINC, 0x92, 0x80, 0x80, 0x08,  // row 0, h*1 = 17,  w*1, no effect         	, col space = 0, length = 8 
    6, _NON_AUTOINC, 0x92, 0x80, 0x80, 0x08,  // row 1, h*1 = 17,  w*1, no effect         	, col space = 0, length = 8 
    6, _NON_AUTOINC, 0x92, 0x87, 0x97, 0x08,  // row 2, h*2 = 19,  w*2, border         	    , col space = 7, length = 8
    6, _NON_AUTOINC, 0x92, 0x90, 0xa6, 0x08,  // row 3, h*1 = 21,  w*1, shadow(left-top)   	, col space = 6, length = 8
    6, _NON_AUTOINC, 0x92, 0x90, 0xa6, 0x08,  // row 4, h*1 = 21,  w*1, shadow(left-top)   	, col space = 6, length = 8
    
    6, _NON_AUTOINC, 0x92, 0x94, 0xb5, 0x08,  // row 5, h*1 = 25,  w*1, shadow(left-bottom) , col space = 5, length = 8
    6, _NON_AUTOINC, 0x92, 0x98, 0xc4, 0x08,  // row 6, h*1 = 27,  w*1, shadow(right-top)   , col space = 4, length = 8
    6, _NON_AUTOINC, 0x92, 0x9c, 0xd3, 0x08,  // row 7, h*1 = 28,  w*1, shadow(right-bottom), col space = 3, length = 8
    6, _NON_AUTOINC, 0x92, 0x81, 0x97, 0x08,  // row 8, h*2 = 19,  w*1, border         	    , col space = 7, length = 8
    6, _NON_AUTOINC, 0x92, 0x81, 0x97, 0x08,  // row 9, h*2 = 19,  w*1, border         	    , col space = 7, length = 8
    
    // add for Brianna OSD function 2009/09/23 Start
    6, _NON_AUTOINC, 0x92, 0x80, 0x80, 0x04,  // row 10, h*1 = 17, w*1, no effect         	, col space = 0, length = 4 // select 0-511
    6, _NON_AUTOINC, 0x92, 0xA0, 0x80, 0x04,  // row 11, h*1 = 17, w*1, no effect         	, col space = 0, length = 4, slect from 512-1023  // Test for 512 FONT
    // add for Brianna OSD function 2009/09/23 End
    
    6, _NON_AUTOINC, 0x92, 0x80, 0x80, 0x03,  // row 12, h*1 = 17, w*1, no effect         	, col space = 0, length = 3
	    
	6, _NON_AUTOINC, 0x92, 0x80, 0x90, 0x06,  // 20091014, "Brianna" for proper font test 0xff03-oxff07

    6, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00,  // row end, no font
    ///////////////////////////////////////////////////////////////////////

    5, _AUTOINC, 0x90, 0xD1, 0x03,  // font select base
    ////////////////////Character Command////////////////////
    // row 0, 8 font
    27, _NON_AUTOINC, 0x92, 0x0c, 0x00, 0x00, // char width: 13, 1bit font, form 0~255, color: 16~31
                            0x88, 0x01, 0x12, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x02, 0x34, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x03, 0x56, // char width: 9, 1bit font, form 0~255, color: 0~15  
                            0x88, 0x04, 0x78, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x05, 0x9A, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x06, 0xBC, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x07, 0xDE, // char width: 9, 1bit font, form 0~255, color: 0~15
                            
    // row 1, 8 font                          // 1bit font, form 0~255, color: 0~15
    27, _NON_AUTOINC, 0x92, 0x8c, 0x00, 0x00, // char width: 13, 
                            0x88, 0x01, 0x12, // char width: 9,
                            0x88, 0x02, 0x23, // char width: 9,
                            0x88, 0x03, 0x45, // char width: 9,   
                            0x88, 0x04, 0x23, // char width: 9,
                            0x88, 0x05, 0x45, // char width: 9,
                            0x88, 0x06, 0x67, // char width: 9,
                            0x88, 0x07, 0x89, // char width: 9,
                        
    // row 2, 8 font                          // 1bit font, form 0~255, color: 16~31
    27, _NON_AUTOINC, 0x92, 0x0c, 0x00, 0x01, // char width: 13,
                            0x04, 0x01, 0x23, // char width: 5,
                            0x0a, 0x02, 0x34, // char width: 11,
                            0x05, 0x03, 0x56, // char width: 6,  
                            0x0b, 0x04, 0x78, // char width: 13,
                            0x06, 0x05, 0x9a, // char width: 7,
                            0x09, 0x06, 0xbc, // char width: 10,
                            0x07, 0x07, 0xef, // char width: 8,
                                              
    // row 3, 8 font                          // 1bit font, form 0~255, color: 0~15                                                                                               
    27, _NON_AUTOINC, 0x92, 0x8c, 0x00, 0x01, 
                            0x84, 0x01, 0x23, 
                            0x8a, 0x02, 0x34, 
                            0x85, 0x03, 0x56,    
                            0x8b, 0x04, 0x78, 
                            0x86, 0x05, 0x9a, 
                            0x89, 0x06, 0xbc, 
                            0x87, 0x07, 0xef,                       
                        
    // row 4, 8 font                          // 1bit font, form 0~255, color: 0~15                                                                                               
    27, _NON_AUTOINC, 0x92, 0x8c, 0x00, 0x01, 
                            0x84, 0x01, 0x23, 
                            0x8a, 0x02, 0x34, 
                            0x85, 0x03, 0x56,    
                            0x8b, 0x04, 0x78, 
                            0x86, 0x05, 0x9a, 
                            0x89, 0x06, 0xbc, 
                            0x88, 0x07, 0xef,                       

    // row 5, 8 font                          // 2bit font, color palette: 0~15
    27, _NON_AUTOINC, 0x92, 0xA1, 0x04, 0x23, 
                            0xE3, 0x05, 0x45,
                            0xA5, 0x06, 0x67, 
                            0xE7, 0x07, 0x89,    
                            0xA9, 0x08, 0xab, 
                            0xEB, 0x09, 0xcd, 
                            0xAD, 0x0a, 0xef, 
                            0xEE, 0x0b, 0x01,                         
                        
    // row 6, 8 font                          // 2bit font, 
    27, _NON_AUTOINC, 0x92, 0xB2, 0x84, 0x23, // color palette: 0~15, F11:0001, B00: 0000, F10: 1100, F01:1011
                            0xF4, 0x85, 0x45, // color palette: 16~31, 
                            0xB6, 0x06, 0x67, // color palette: 0~15
                            0xF8, 0x07, 0x89, // color palette: 16~31   
                            0xBA, 0x08, 0xab, // color palette: 0~15
                            0xFC, 0x09, 0xcd, // color palette: 16~31
                            0xAD, 0x8a, 0xef, // color palette: 0~15
                            0xF0, 0x0b, 0x01, // color palette: 16~31    
                        
    // row 7, 8 font                          // 4bit font,
    27, _NON_AUTOINC, 0x92, 0x90, 0x07, 0x00, 
                            0x91, 0x08, 0x55, 
                            0x92, 0x09, 0xaa, 
                            0x93, 0x0a, 0xff,    
                            0x94, 0x0b, 0x22, 
                            0x95, 0x0c, 0x44, 
                            0x96, 0x0d, 0x66, 
                            0x97, 0x0e, 0x88,   

    // row 8, 8 font                          // 4bit font,                       
    27, _NON_AUTOINC, 0x92, 0x98, 0x07, 0x33, 
                            0x99, 0x08, 0x11, 
                            0x9a, 0x09, 0xbb, 
                            0x9b, 0x0a, 0xcc,    
                            0x9c, 0x0b, 0x01, 
                            0x9d, 0x0c, 0x23, 
                            0x9e, 0x0d, 0x45, 
                            0x9f, 0x0e, 0x67, 

    // row 9, 8 font                          // 4bit font,                       
    27, _NON_AUTOINC, 0x92, 0x98, 0x07, 0x33, 
                            0x99, 0x08, 0x11, 
                            0x9a, 0x09, 0xbb, 
                            0x9b, 0x0a, 0xcc,    
                            0x9c, 0x0b, 0x01, 
                            0x9d, 0x0c, 0x23, 
                            0x9e, 0x0d, 0x45, 
                            0x9f, 0x0e, 0x67, 
    

    // add for Brianna OSD function 2009/09/23 Start
    // row 10, 4 font
    15, _NON_AUTOINC, 0x92, 0x2c, 0x90, 0x2B, // 1-bit font, font select from 256-511, color palette 0-15, FONT 400 "0"
                            0x3c, 0x90, 0x2B, // 1-bit font, font select from 256-511, color palette 16-31, FONT 400 "0"
                            0x0C, 0x07, 0x27, // 1-bit font, font select from 0-255, color palette 16-31, FONT 7 "n"
                            0x8C, 0x07, 0x27, // 1-bit font, font select from 0-255, color palette 0-15, FoNT 7 "n"
    // row 11, 4 font
    15, _NON_AUTOINC, 0x92, 0x2c, 0x0C, 0x2F, // 1-bit font, font select from 768-1023, color palette 0-15,  FONT 780 "d"
                            0x3c, 0x0C, 0x2F, // 1-bit font, font select from 768-1023, color palette 16-31, FONT 780 "d"
                            0x0C, 0x58, 0x25, // 1-bit font, font select from 512-767, color palette 16-31, FONT 600 "A"
                            0x8C, 0x58, 0x25, // 1-bit font, font select from 512-767, color palette 0-15, FoNT 600 "A"
    // add for Brianna OSD function 2009/09/23 End
    
    // row 12, 3 font                        
    12, _NON_AUTOINC, 0x92, 0x10, 0x10, 0x12, // Blank
                            0x10, 0x12, 0x00, 
                            0x10, 0x16, 0x0f,
    // row 13, 6 font
    21, _NON_AUTOINC, 0x92, 0x0c, 0x3C, 0x2F, // 1-bit font, // 20091014
                            0x0c, 0x3D, 0xB1, // 1-bit font, 
                            0x0C, 0x3E, 0x0C, // 1-bit font, 
                            0x8C, 0x3F, 0xA3, 
							0x8C, 0x40, 0x5B,
							0x8C, 0x41, 0xF4,

    //********************************************************************************************************//
    5, _AUTOINC, 0x90, 0xD4, 0x03,  // font map
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,	 // map of "A",	 // FONT 0											
    12, _NON_AUTOINC, 0x92, 0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,																									
    12, _NON_AUTOINC, 0x92, 0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,																									
    													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,	 // map of "n",  // FONT 1
    12, _NON_AUTOINC, 0x92, 0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,													
    12, _NON_AUTOINC, 0x92, 0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																									
    									
    12, _NON_AUTOINC, 0x92, 0x0c, 0x00, 0x00, 0x0c, 0xc0, 0x00, 0x0c, 0xc0, 0x00,	 // map of "d",  // FONT 2
    12, _NON_AUTOINC, 0x92, 0xfc, 0xc3, 0x1e, 0x0c, 0xc6, 0x31, 0x0c, 0xc6, 0x60,													
    12, _NON_AUTOINC, 0x92, 0x1c, 0xc7, 0x60, 0xec, 0xc1, 0x3f, 0x00, 0x00, 0x00,													

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x81, 0x0f,	 // map of "e",  // FONT 3												
    12, _NON_AUTOINC, 0x92, 0x1c, 0xc3, 0x38, 0xf0, 0x83, 0x33, 0x84, 0x03, 0x3c,													
    12, _NON_AUTOINC, 0x92, 0xf0, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x83, 0x33,	 // map of "r",  // FONT 4												
    12, _NON_AUTOINC, 0x92, 0x18, 0x83, 0x39, 0x00, 0x03, 0x30, 0x00, 0x03, 0x30,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,						

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x81, 0x03,	 // map of "s",  // FONT 5													
    12, _NON_AUTOINC, 0x92, 0x00, 0x83, 0x39, 0xf0, 0x00, 0x3e, 0x18, 0x82, 0x01,													
    12, _NON_AUTOINC, 0x92, 0xf0, 0x81, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    							
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0x0f,	 // map of "o",  // FONT 6	
    12, _NON_AUTOINC, 0x92, 0x0c, 0xc3, 0x19, 0x0c, 0xc3, 0x30, 0x98, 0xc3, 0x30,													
    12, _NON_AUTOINC, 0x92, 0xf0, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    							
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,	 // map of "n",  // FONT 7											
    12, _NON_AUTOINC, 0x92, 0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,													
    12, _NON_AUTOINC, 0x92, 0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																			


    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x14, 0xc5, 0x60,	 // map of "M" 2-bit,  // FONT 8,9(4) 
    12, _NON_AUTOINC, 0x92, 0x14, 0x45, 0x51, 0xa4, 0x44, 0x4a, 0x04, 0x44, 0x40,																										
    12, _NON_AUTOINC, 0x92, 0x0e, 0x4e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																										
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																		
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x0a, 0x00, 0x00, 0x04,																																		
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																															

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x14, 0xc5, 0x60,	 // map of "M" 2-bit,  // FONT 10,11(5) 											
    12, _NON_AUTOINC, 0x92, 0x14, 0x45, 0x51, 0xa4, 0x44, 0x4a, 0x04, 0x44, 0x44,																									
    12, _NON_AUTOINC, 0x92, 0x0e, 0x4e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																				
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																									
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,			

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	 // map of "-" 2-bit,  // FONT 12,13(6)												
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x40, 0x35, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,			

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x04, 0x81, 0x10,	 // map of "P" 2-bit,  // FONT 14,15(7)												
    12, _NON_AUTOINC, 0x92, 0x04, 0x41, 0x10, 0xf0, 0x81, 0x10, 0x00, 0x01, 0x10,													
    12, _NON_AUTOINC, 0x92, 0xe0, 0x07, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																				
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																									
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x08, 0x82, 0x20,	 // map of "D" 2-bit,  // FONT 16,17(8)												
    12, _NON_AUTOINC, 0x92, 0x04, 0x42, 0x20, 0x04, 0x42, 0x20, 0x08, 0x42, 0x20,													
    12, _NON_AUTOINC, 0x92, 0xf0, 0x87, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																				
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																									
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x08, 0x82, 0x20,	 // map of "D" 2-bit,  // FONT 18,19(9)												
    12, _NON_AUTOINC, 0x92, 0x04, 0x42, 0x20, 0x04, 0x42, 0x20, 0x08, 0x42, 0x20,													
    12, _NON_AUTOINC, 0x92, 0xf0, 0x87, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																				
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																									
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x40, 0x00, 0x34,	 // map of "1" 2-bit,  // FONT 20,21(10)													
    12, _NON_AUTOINC, 0x92, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04,													
    12, _NON_AUTOINC, 0x92, 0x40, 0x00, 0x04, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																				
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																									
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,				

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	 // map of "-" 2-bit,  // FONT 22,23(11)												
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x40, 0x35, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xe8, 0x00, 0x00, 0x08, 0x82, 0x11,	 // map of "S" 2-bit,  // FONT 24,25(12)											
    12, _NON_AUTOINC, 0x92, 0x00, 0x03, 0x20, 0x18, 0x00, 0x0e, 0x08, 0x82, 0x00,													
    12, _NON_AUTOINC, 0x92, 0xe0, 0x02, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    							
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x08, 0x82, 0x20,	 // map of "D" 2-bit,  // FONT 26,27(13)												
    12, _NON_AUTOINC, 0x92, 0x04, 0x42, 0x20, 0x04, 0x42, 0x20, 0x08, 0x42, 0x20,													
    12, _NON_AUTOINC, 0x92, 0xf0, 0x87, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																				
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																									
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,			

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x02, 0x00,	 // test font "E" 4-bit,  //  FONT 28,29,30,31(7)												
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x00, 0x00, 0x02, 0x1e, 0x00, 0x02, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x03, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x20, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x20,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x20, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00,			

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x18, 0x82, 0x20, 0x10, 0x01, 0x31,	 // test font "X" 4-bit,  //  FONT 32,33,34,35(8)											
    12, _NON_AUTOINC, 0x92, 0xa0, 0x00, 0x1b, 0x60, 0x00, 0x0e, 0xb0, 0x00, 0x0e,													
    12, _NON_AUTOINC, 0x92, 0x0c, 0x81, 0x19, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,	 // test font "T" 4-bit,  //  FONT 36,37,38,39(9)														
    12, _NON_AUTOINC, 0x92, 0x40, 0x00, 0x04, 0x60, 0x00, 0x04, 0x60, 0x00, 0x06,													
    12, _NON_AUTOINC, 0x92, 0x20, 0x00, 0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x31, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																								

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	 // test font ":" 4-bit,  //  FONT 40,41,42,43(10)														
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x0e,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x0e,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x04,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													

     
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x10, 0x00, 0x02, 0x20,	 // test font "5" 4-bit,  //  FONT 44,45,46,47(11)														
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x20, 0x00, 0x03, 0x20, 0x00, 0x00, 0x01,													
    12, _NON_AUTOINC, 0x92, 0x10, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x10, 0x00, 0x02, 0x20,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x20, 0x00, 0x00, 0x20, 0x08, 0x80, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x10, 0x00, 0x02, 0x20,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x20, 0xf0, 0x00, 0x20, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x20, 0xf0, 0x00, 0x20, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,	 // test font "4" 4-bit,  //  FONT 48,49,50,51(12)													
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x01, 0x10,													
    12, _NON_AUTOINC, 0x92, 0x18, 0x00, 0x00, 0x00, 0x80, 0x01, 0x1c, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x01, 0x10,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x01,													
    12, _NON_AUTOINC, 0x92, 0x10, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,													

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0c, 0x83, 0x0f, 0x08, 0x40, 0x20,	 // test font "2" 4-bit,  //  FONT 52,53,54,55(13)																
    12, _NON_AUTOINC, 0x92, 0x18, 0x80, 0x00, 0x30, 0x00, 0x01, 0x60, 0x00, 0x02,													
    12, _NON_AUTOINC, 0x92, 0xc0, 0x00, 0x04, 0x00, 0x80, 0x0f, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0c, 0x80, 0x01, 0x04, 0x40, 0x00,	 // test font "3" 4-bit,  //  FONT 56,57,58,59(14)													
    12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0c, 0x80, 0x0f, 0x04, 0x40, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x20,													
    12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x01, 0x18, 0x00, 0x01,													
    12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,

    5, _AUTOINC, 0x90, 0xDD, 0x03,  // font map for 1 bit font
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,	 // map of "n",  // FONT 256
    12, _NON_AUTOINC, 0x92, 0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,													
    12, _NON_AUTOINC, 0x92, 0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																			

    4, _AUTOINC, 0x93, 0x08,  // Initial Address Higher Than 12K
    5, _AUTOINC, 0x90, 0xD2, 0x13,  // font map for 1 bit font
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0x0f,	 // map of "o",  // FONT 400	
    12, _NON_AUTOINC, 0x92, 0x0c, 0xc3, 0x19, 0x0c, 0xc3, 0x30, 0x98, 0xc3, 0x30,													
    12, _NON_AUTOINC, 0x92, 0xf0, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		
    4, _AUTOINC, 0x93, 0x00,  // Initial Address Higher Than 12K

    // add for Brianna OSD function 2009/09/23 Start
    4, _AUTOINC, 0x93, 0x08,  // Initial Address Higher Than 12K
    5, _AUTOINC, 0x90, 0xD9, 0x1B,  // font map for 1 bit font
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,	 // map of "A",	 // FONT 600											
    12, _NON_AUTOINC, 0x92, 0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,																									
    12, _NON_AUTOINC, 0x92, 0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,
    
    4, _AUTOINC, 0x93, 0x00,  // Initial Address Higher Than 12K 
    
    _END
};

// window 8/9 prior higher than font
// OSD special function enable, ROLL-UP
// OSD vertical boundary funciton enable
BYTE code tQC_OSD_TEST_FRAME1[]=
{
    ////////////////////Frame Control Registers////////////////////
    5, _AUTOINC,     0x90, 0x80, 0x00,
    4, _NON_AUTOINC, 0x92, 0xFB, //// 000h: delay V:71, H:39, disp_zone => left, OSD circuit is activated   
    5, _AUTOINC,     0x90, 0xC0, 0x02, // 
    6, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x6f,  // 002h: 
    										  // match LSB [3:0], blending type 2 color [5:4]=11(win 8's border)
    										  // Window 9 priority higher than font
    										  // Window 8 priority higher than font
    5, _AUTOINC,     0x90, 0xC0, 0x08,	
    6,_NON_AUTOINC,  0x92, 0xA0, 0x03, 0x05,  
    6,_NON_AUTOINC,  0x92, 0x11, 0x0B, 0x03, // vertical boundary funciton enable, display base 0, row base0: 2, row base1: 5
    
    _END	
};

// window 8/9 prior higher than font
// OSD special function enable, POP-ON
// OSD vertical boundary funciton enable
BYTE code tQC_OSD_TEST_FRAME2[]=
{
    ////////////////////Frame Control Registers////////////////////
    5, _AUTOINC,     0x90, 0x80, 0x00,
    4, _NON_AUTOINC, 0x92, 0xFB, //// 000h: delay V:71, H:39, disp_zone => left, OSD circuit is activated   
    5, _AUTOINC,     0x90, 0xC0, 0x02, // 
    6, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x6f,  // 002h: 
    										  // match LSB [3:0], blending type 2 color [5:4]=11(win 8's border)
    										  // Window 9 priority higher than font
    										  // Window 8 priority higher than font
    5, _AUTOINC,     0x90, 0xC0, 0x08,	
    6,_NON_AUTOINC,  0x92, 0xE0, 0x03, 0x05,  
    6,_NON_AUTOINC,  0x92, 0x11, 0x0B, 0x03, // vertical boundary funciton enable, display base 0, row base0: 2, row base1: 5
    
    _END	
};

// window 8/9 prior higher than font
// OSD special function enable, POP-ON
// OSD vertical boundary funciton enable
BYTE code tQC_OSD_TEST_FRAME3[]=
{
    ////////////////////Frame Control Registers////////////////////
    5, _AUTOINC,     0x90, 0x80, 0x00,
    4, _NON_AUTOINC, 0x92, 0xFB, //// 000h: delay V:71, H:39, disp_zone => left, OSD circuit is activated   
    5, _AUTOINC,     0x90, 0xC0, 0x02, // 
    6, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x6f,  // 002h: 
    										  // match LSB [3:0], blending type 2 color [5:4]=11(win 8's border)
    										  // Window 9 priority higher than font
    										  // Window 8 priority higher than font
    5, _AUTOINC,     0x90, 0xC0, 0x08,	
    6,_NON_AUTOINC,  0x92, 0xE1, 0x03, 0x05,  
    6,_NON_AUTOINC,  0x92, 0x11, 0x0B, 0x03, // vertical boundary funciton enable, display base 1, row base0: 2, row base1: 5
    
    _END	
};

// for font blinking function, font base address [12] -> 1
// the font select address more than 12k
// 00Bh-byte1 2-bit font char select offset
// blending function
// window 4-1~4-3 hightwindow enbale, overlap window priority
BYTE code tQC_OSD_TEST_FRAME5[] =
{
    4, _NON_AUTOINC, 0x6c, 0x2B, // bkg color access enable,OSD overlay enable
    6, _NON_AUTOINC, 0x6d, 0x00, 0xFF, 0xFF, // bkg color 85 grey
    
    5,	_AUTOINC,     0x90,	0x80,0x03, 
	4,	_NON_AUTOINC, 0x92,	0x00,  		       //Global Blinking Enable,
	5,	_AUTOINC,     0x90,	0xC0,0x04,
	6,  _NON_AUTOINC, 0x92, 0x00, 0x13, 0x40,  // 004h: fs_base = 100, fm_base=1403
	5,	_AUTOINC,     0x90,	0x00,0x08,
	4,  _NON_AUTOINC, 0x92, 0x00, 
	5,	_AUTOINC,     0x90,	0x00,0x0B, 
	4,	_NON_AUTOINC, 0x92,	0x80,                   //Global Blinking Enable, 
	5,	_AUTOINC,     0x90,	0xC0,0x0C, 
	6,	_NON_AUTOINC, 0x92,	0x00,0x00,0x00, 
	
	//	Row Command
	5, _AUTOINC,     0x90, 0xD0, 0x00,  		     // row command base 0
	6, _NON_AUTOINC, 0x92, 0xc3, 0xF0, 0x05,    // row 0, h*2 = 32,  w*2, no effect, col space = 0, length = 5, enable font VBI function
    6, _NON_AUTOINC, 0x92, 0x83, 0xF0, 0x02,    // row 1, h*2 = 32,  w*2, no effect, col space = 0, length = 2,
    6, _NON_AUTOINC, 0x92, 0x83, 0xF0, 0x05,    // row 2, h*2 = 32,  w*2, no effect, col space = 0, length = 5,

    6, _NON_AUTOINC, 0x92, 0x87, 0xF0, 0x0A,    // row 3, h*2 = 32,  w*2, no effect, col space = 0, length = 10, border
    
    6, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00,    // end, no font

    

    5, _AUTOINC,     0x90, 0x40, 0x0B,
    4, _NON_AUTOINC, 0x92, 0x01, // 00Bh-byte1: 2-bit font char select offset
	
	//   Character Command
	5, _AUTOINC, 0x90, 0xD1, 0x00,                     // font select base
	
	//  row 0, 4 font
	18, _NON_AUTOINC, 0x92, 0x82, 0x00, 0x16,  // 1-bit font, no blinking for F/B, under line enable
						    0x86, 0x01, 0x32,  // 1-bit font, only blinking for F, under line enable
						    0xC2, 0x00, 0x5A,  // 1-bit font, only blinking for B, under line enable
						    0xC6, 0x00, 0x46,  // 1-bit font, F/B blinking, under line enbale,
						    0xDf, 0x03, 0x67,  // 4-bit font, blinking, under line enbale,
	// row 1, 2 font					    
	9, _NON_AUTOINC, 0x92,					    
						    0xAD, 0x03, 0x67,  // 2-bit font, under line enbale, "-"
						    0xAD, 0x04, 0x67,  // 2-bit font, under line enbale, "S"

    // row 2, 5 font					    
	18, _NON_AUTOINC, 0x92,					    
						    0x0c, 0x00, 0x16, // char width: 13,
                            0x0F, 0x01, 0x23, // char width: 16,
                            0x0a, 0x01, 0x34, // char width: 11,
                            0x08, 0x02, 0x56, // char width: 9,  
                            0x0b, 0x03, 0x78, // char width: 13,


    // row 3, 10 font					    
	33, _NON_AUTOINC, 0x92,	0x0F, 0x00, 0x1F, // char width: 13,
                            0x0F, 0x01, 0x2E, // char width: 16,
                            0x0F, 0x01, 0x3F, // char width: 11,
                            0x0F, 0x02, 0x50, // char width: 9,  
                            0x0F, 0x03, 0x70, // char width: 13,
                            0x0F, 0x00, 0x1E, // char width: 13,
                            0x0F, 0x01, 0x2F, // char width: 16,
                            0x0F, 0x01, 0x30, // char width: 11,
                            0x0F, 0x02, 0x50, // char width: 9,  
                            0x0F, 0x03, 0x70, // char width: 13,
                            
	
	4, _AUTOINC, 0x93, 0x08,  		// Initial Address Higher Than 12K
	5, _AUTOINC, 0x90, 0xD4, 0x03,  // font map
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,	 // map of "A",  // FONT 0											
	12, _NON_AUTOINC, 0x92, 0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,																									
	12, _NON_AUTOINC, 0x92, 0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,	

	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,	 // map of "A",  // FONT 1											
	12, _NON_AUTOINC, 0x92, 0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,																									
	12, _NON_AUTOINC, 0x92, 0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,

	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,	 // map of "A",  // FONT 2											
	12, _NON_AUTOINC, 0x92, 0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,																									
	12, _NON_AUTOINC, 0x92, 0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,

	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,	 // map of "A",  // FONT 3											
	12, _NON_AUTOINC, 0x92, 0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,																									
	12, _NON_AUTOINC, 0x92, 0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x14, 0xc5, 0x60,	 // map of "M" 2-bit,  // FONT 4,5(4) 
    12, _NON_AUTOINC, 0x92, 0x14, 0x45, 0x51, 0xa4, 0x44, 0x4a, 0x04, 0x44, 0x40,																										
    12, _NON_AUTOINC, 0x92, 0x0e, 0x4e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																										
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																		
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x0a, 0x00, 0x00, 0x04,																																		
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																															

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x08, 0x82, 0x20,	 // map of "D" 2-bit,  // FONT 6,7(5)												
    12, _NON_AUTOINC, 0x92, 0x04, 0x42, 0x20, 0x04, 0x42, 0x20, 0x08, 0x42, 0x20,													
    12, _NON_AUTOINC, 0x92, 0xf0, 0x87, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																																				
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																									
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	 // map of "-" 2-bit,  // FONT 8,9(6)												
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x40, 0x35, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xe8, 0x00, 0x00, 0x08, 0x82, 0x11,	 // map of "S" 2-bit,  // FONT 10,11(7)											
    12, _NON_AUTOINC, 0x92, 0x00, 0x03, 0x20, 0x18, 0x00, 0x0e, 0x08, 0x82, 0x00,													
    12, _NON_AUTOINC, 0x92, 0xe0, 0x02, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    

	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0c, 0x80, 0x01, 0x04, 0x40, 0x00,	 // test font "3" 4-bit ,  //  FONT 12,13,14,15(3)													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0c, 0x80, 0x0f, 0x04, 0x40, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x20,													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x01, 0x18, 0x00, 0x01,													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,	
	4, _AUTOINC, 0x93, 0x00,      // Initial Address Higher Than 12K


    5, _AUTOINC,     0x90, 0xC0, 0x00, // frame control register
    6, _NON_AUTOINC, 0x92, 0x08, 0x09, 0xf9,  // 000h: delay V:71, H:39, disp_zone => middle, OSD circuit is activated

    ////////////////////Background & Alpha Blending////////////////////
    4, _NON_AUTOINC, 0x6c, 0x3D, // bkg color access enable,OSD overlay enable
    		                     // blending level: 111 => 7/8
    6, _NON_AUTOINC, 0x6d, 0x55, 0x66, 0x77, // bkg color 85 grey
    

    //////////////////////////////Blending function/////////////////////////////////////////
    5, _AUTOINC,      0x90, 0xC1, 0x00,  // window 0  
    // color index: 01, 
    // blending enbale, 3D Button type 1, window enbale
    // 3D button thickness width/height: 8 pixels
    // border color: 0x0F, 0x08, gradient disable
    15, _NON_AUTOINC, 0x92, 0x3F, 0xF8, 0x00,   0x00, 0x00, 0x00,  0x22, 0x01, 0x01, 0x00, 0x01, 0x99, // win0 (0,0)-(0x201,0x201)

    // color index: 0x30, 
    // blending disale, border, window enbale
    // border thickness width/height: 8 pixels
    // border color: 0x3F,
    5, _AUTOINC,      0x90, 0xC1, 0x18,  // window 6
    15, _NON_AUTOINC, 0x92, 0xFF, 0xFF, 0x00,   0x00, 0x00, 0x30,  0x00, 0x50, 0x90, 0xE0, 0x10, 0x1F, // win6 

    5, _AUTOINC,      0x90, 0xC1, 0x1C,  // window 7
    15, _NON_AUTOINC, 0x92, 0xFF, 0xFE, 0x00,   0x00, 0x60, 0x30,  0x10, 0x00, 0x90, 0x90, 0x01, 0x51, // win7

    5, _AUTOINC,      0x90, 0xC1, 0x20,  // window 8
    15, _NON_AUTOINC, 0x92, 0xFF, 0x00, 0x00,   0x00, 0x00, 0xA0,  0x01, 0x20, 0x10, 0xF8, 0x01, 0x1F, // win8

    5, _AUTOINC,      0x90, 0x81, 0x07,  // window 1
    4, _NON_AUTOINC,  0x92, 0x00,
    
    5, _AUTOINC,      0x90, 0x81, 0x0B,  // window 2
    4, _NON_AUTOINC,  0x92, 0x00,

    5, _AUTOINC,      0x90, 0x81, 0x0F,  // window 3
    4, _NON_AUTOINC,  0x92, 0x00,
    
    5, _AUTOINC,      0x90, 0x81, 0x12,  // window 4
    4, _NON_AUTOINC,  0x92, 0x00,
    
    5, _AUTOINC,      0x90, 0x81, 0x17,  // window 5
    4, _NON_AUTOINC,  0x92, 0x00,

    5, _AUTOINC,      0x90, 0x81, 0x27,  // window 9
    4, _NON_AUTOINC,  0x92, 0x00,
 
    
    5, _AUTOINC,      0x90, 0xC0, 0x02,
    6, _NON_AUTOINC,  0x92, 0x00, 0x00, 0x3D,//window 8 priority higher than font, char border color: 0x13, bit[5:4]= 01
    
	5, _AUTOINC,      0x90, 0xC0, 0x03,
    6, _NON_AUTOINC,  0x92, 0xEF, 0x3C, 0x02,// blending 2 enable, type2 color: 0x3F, window 7 blending enbale (mark transparent), blending type 1: window and character B blending
                                             // type 2 blending color is the window 6's border color
                                             // char border color: 0x13, bit[3:0]= 0011
    5, _AUTOINC,      0x90, 0x00, 0x0B,
    4, _NON_AUTOINC,  0x92, 0xFC, // window 6 special blending enable, both F/B, window 7 both F/B 

    // add for Brianna OSD function 2009/09/23 Start
    // for Brianna highlight window funtion window 4-1 ~ 4-3
    5, _AUTOINC,      0x90, 0xC2, 0x00,  // window 4-1
    15, _NON_AUTOINC,  0x92, 0xFF, 0x00, 0x00,   0x00, 0x25, 0xb0,  0x11, 0x00, 0x10, 0xf0, 0x01, 0x0F, // win4-1

    5, _AUTOINC,      0x90, 0xC2, 0x04,  // window 4-2
    15, _NON_AUTOINC,  0x92, 0xFF, 0x00, 0x00,   0x00, 0x70, 0xA0,  0x01, 0xA0, 0x00, 0xF8, 0x0C, 0x01, // win4-2

    5, _AUTOINC,      0x90, 0xC2, 0x08,  // window 4-3
    15, _NON_AUTOINC,  0x92, 0xFF, 0x00, 0x00,   0x00, 0x80, 0xC0,  0x01, 0xF0, 0x10, 0xF0, 0x05, 0x0D, // win4-3

    5, _AUTOINC,      0x90, 0x00, 0x0E,
    6, _NON_AUTOINC,  0x92, 0x7F, 0x00, 0x14, // high light win4-1 enable, F:0x3F, B:0x00(transparent), char Boarder:0x14
    5, _AUTOINC,      0x90, 0x00, 0x0F,
    6, _NON_AUTOINC,  0x92, 0x53, 0x01, 0x3F, // high light win4-2 enable, F:0x23, B:0x01, char Boarder:0x03
    5, _AUTOINC,      0x90, 0x00, 0x10,
    6, _NON_AUTOINC,  0x92, 0x47, 0x0F, 0x0C, // high light win4-3 enable, F:0x07, B:0x0F, char Boarder:0x0C                           
    // add for Brianna OSD function 2009/09/23 End
  
	_END
};


// window 4-1 ~ 4-3 highlight window function, adn window overlap priority, window 4-3 is the high
BYTE code tQC_OSD_TEST_FRAME7[] = 
{
    4, _NON_AUTOINC, 0x6c, 0x29, // bkg color access enable,OSD overlay enable
    		                     // blending level: 010 => 4/8
    6, _NON_AUTOINC, 0x6d, 0xAA, 0xAA, 0xAA, // bkg color 85 grey

    5, _AUTOINC,     0x90, 0xC0, 0x00, // frame control register
    6, _NON_AUTOINC, 0x92, 0x08, 0x09, 0xf9,  // 000h: delay V:71, H:39, disp_zone => middle, OSD circuit is activated

    5, _AUTOINC,     0x90, 0x80, 0x02,
    4, _NON_AUTOINC, 0x92, 0x03, 
    
    5, _AUTOINC,     0x90, 0x40, 0x03,
    4, _NON_AUTOINC, 0x92, 0x00,

    5, _AUTOINC,     0x90, 0xC0, 0x04,
    6, _NON_AUTOINC, 0x92, 0x03, 0x13, 0x40,  // 004h: fs_base = 0x103, fm_base = 0x403	

    5, _AUTOINC,     0x90, 0xD0, 0x00,  // row command
    6, _NON_AUTOINC, 0x92, 0x87, 0xF3, 0x08,  // row 0, h*2 = 17,  w*2, no effect         	, col space = 0, length = 8
    6, _NON_AUTOINC, 0x92, 0x9F, 0xF3, 0x08,  // row 1, h*2 = 17,  w*2, no effect         	, col space = 0, length = 8
    6, _NON_AUTOINC, 0x92, 0x87, 0xd3, 0x08,  // row 2, h*2 = 28,  w*2, shadow(right-bottom), col space = 3, length = 8
    
    6, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00,  // row end

    5, _AUTOINC, 0x90, 0xD1, 0x03,  // font select base
    ////////////////////Character Command////////////////////
    // row 0, 8 font
    27, _NON_AUTOINC, 0x92, 0x0c, 0x00, 0x23, // char width: 13, 1bit font, form 0~255, color: 16~31
                            0x88, 0x01, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x02, 0x23, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x03, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15  
                            0x88, 0x00, 0x23, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x01, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x02, 0x67, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x03, 0x89, // char width: 9, 1bit font, form 0~255, color: 0~15

    // row 1, 8 font
    27, _NON_AUTOINC, 0x92, 0x0c, 0x00, 0x23, // char width: 13, 1bit font, form 0~255, color: 16~31
                            0x88, 0x01, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x02, 0x23, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x03, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15  
                            0x88, 0x00, 0x23, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x01, 0x45, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x02, 0x67, // char width: 9, 1bit font, form 0~255, color: 0~15
                            0x88, 0x03, 0x89, // char width: 9, 1bit font, form 0~255, color: 0~15
                            
     // row 2, 8 font                          // 4bit font,
    27, _NON_AUTOINC, 0x92, 0x90, 0x01, 0x00, 
                            0x91, 0x01, 0x55, 
                            0x92, 0x02, 0xaa, 
                            0x93, 0x02, 0xff,    
                            0x94, 0x03, 0x22, 
                            0x95, 0x03, 0x44, 
                            0x96, 0x01, 0x66, 
                            0x97, 0x01, 0x88,
    

    5, _AUTOINC, 0x90, 0xD4, 0x03,  // font map
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,	 // map of "A",	 // FONT 0											
    12, _NON_AUTOINC, 0x92, 0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,																									
    12, _NON_AUTOINC, 0x92, 0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,																									
    													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,	 // map of "n",  // FONT 1
    12, _NON_AUTOINC, 0x92, 0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,													
    12, _NON_AUTOINC, 0x92, 0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,																									
    									
    12, _NON_AUTOINC, 0x92, 0x0c, 0x00, 0x00, 0x0c, 0xc0, 0x00, 0x0c, 0xc0, 0x00,	 // map of "d",  // FONT 2
    12, _NON_AUTOINC, 0x92, 0xfc, 0xc3, 0x1e, 0x0c, 0xc6, 0x31, 0x0c, 0xc6, 0x60,													
    12, _NON_AUTOINC, 0x92, 0x1c, 0xc7, 0x60, 0xec, 0xc1, 0x3f, 0x00, 0x00, 0x00,													

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x81, 0x0f,	 // map of "e",  // FONT 3												
    12, _NON_AUTOINC, 0x92, 0x1c, 0xc3, 0x38, 0xf0, 0x83, 0x33, 0x84, 0x03, 0x3c,													
    12, _NON_AUTOINC, 0x92, 0xf0, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x02, 0x00,	 // test font "E" 4-bit,  //  FONT 28,29,30,31(7)												
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x00, 0x00, 0x02, 0x1e, 0x00, 0x02, 0x00,	// byte2-bit[1:0]												
    12, _NON_AUTOINC, 0x92, 0x00, 0x03, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x20, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x20,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x02, 0x20, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00,
    
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x18, 0x82, 0x20, 0x10, 0x01, 0x31,	 // test font "X" 4-bit,  //  FONT 32,33,34,35(8)											
    12, _NON_AUTOINC, 0x92, 0xa0, 0x00, 0x1b, 0x60, 0x00, 0x0e, 0xb0, 0x00, 0x0e,													
    12, _NON_AUTOINC, 0x92, 0x0c, 0x81, 0x19, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													

    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,	 // test font "T" 4-bit,  //  FONT 36,37,38,39(9)														
    12, _NON_AUTOINC, 0x92, 0x40, 0x00, 0x04, 0x60, 0x00, 0x04, 0x60, 0x00, 0x06,													
    12, _NON_AUTOINC, 0x92, 0x20, 0x00, 0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x31, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
    12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	    

    // add for Brianna OSD function 2009/09/23 Start
    // for Brianna highlight window funtion window 4-1 ~ 4-3
    5, _AUTOINC,      0x90, 0xC2, 0x00,  // window 4-1
    15, _NON_AUTOINC,  0x92, 0xFF, 0x00, 0x00,   0x00, 0x25, 0x30,  0x00, 0xF0, 0x70, 0x00, 0x00, 0x0F, // win4-1

    5, _AUTOINC,      0x90, 0xC2, 0x04,  // window 4-2
    15, _NON_AUTOINC,  0x92, 0xFF, 0x00, 0x00,   0x00, 0x70, 0x05,  0x00, 0x90, 0x50, 0x50, 0x0C, 0x01, // win4-2

    5, _AUTOINC,      0x90, 0xC2, 0x08,  // window 4-3
    15, _NON_AUTOINC,  0x92, 0xFF, 0x00, 0x00,   0x00, 0x80, 0x10,  0x00, 0xF0, 0x60, 0xF8, 0x01, 0x0D, // win4-3

    5, _AUTOINC,      0x90, 0x00, 0x0E,
    6, _NON_AUTOINC,  0x92, 0x7F, 0x00, 0x14, // high light win4-1 enable, F:0x3F, B:0x00(transparent), char Boarder:0x14
    5, _AUTOINC,      0x90, 0x00, 0x0F,
    6, _NON_AUTOINC,  0x92, 0x53, 0x01, 0x3F, // high light win4-2 enable, F:0x23, B:0x01, char Boarder:0x03
    5, _AUTOINC,      0x90, 0x00, 0x10,
    6, _NON_AUTOINC,  0x92, 0x47, 0x0F, 0x0C, // high light win4-3 enable, F:0x07, B:0x0F, char Boarder:0x0C                            
    // add for Brianna OSD function 2009/09/23 End

    5, _AUTOINC,      0x90, 0x81, 0x03,  // window 0
    4, _NON_AUTOINC,  0x92, 0x00,

    5, _AUTOINC,      0x90, 0x81, 0x07,  // window 5
    4, _NON_AUTOINC,  0x92, 0x00,
    
    _END,
};


// for rotated function CCW and CW, decode compression data and decode mon-compressed data
// double width and double height enable for frame control register
// double pixel per clock
// 2-bit font char select offset bit[7]->1
BYTE code tQC_OSD_TEST_FRAME6[]=
{
	4, _NON_AUTOINC, 0x6c, 0x2B, // bkg color access enable,OSD overlay enable
			                     // blending level: 010 => 4/8	
			                     // dual pixels per clock
	5, _AUTOINC,        0x90, 0xC0, 0x00,           // frame control register
	6, _NON_AUTOINC,    0x92, 0x00, 0x00, 0x05,  // 000h: delay V:0, H:0, disp_zone => right, OSD circuit is activated	
	5, _AUTOINC,        0x90, 0xC0, 0x08,
	6, _NON_AUTOINC,    0x92, 0x00, 0x00, 0x00,  
	6, _NON_AUTOINC,    0x92, 0x00, 0x00, 0x00,  
	5, _AUTOINC,        0x90, 0xC0, 0x0c,
	6, _NON_AUTOINC,    0x92, 0x00, 0x55, 0x55,  // 00Ch: font A delay
	5, _AUTOINC,        0x90, 0xC0, 0x04,
	6, _NON_AUTOINC,0x92, 0x00, 0x10, 0x40,  // 004h: fs_base = 100, fm_base=400

	// ROW Command
	5, _AUTOINC, 	    0x90, 0xD0, 0x00,  		// row command base 0
	6, _NON_AUTOINC,    0x92, 0x83, 0xF0, 0x04,  // row 0, h*1 = 30,  w*2, no effect , col space = 0, length = 4
	6, _NON_AUTOINC,    0x92, 0x80, 0xF0, 0x05,  // row 0, h*1 = 30,  w*1, no effect , col space = 0, length = 5
	6, _NON_AUTOINC,    0x92, 0x00, 0x00, 0x00,  // end, no font

	// Character Command
	5, _AUTOINC,           0x90, 0xD1, 0x00,           // font select base
	// row 0, 4 font
	15, _NON_AUTOINC, 0x92, 0x8f, 0x01, 0x23, 
						    0x8e, 0x02, 0xe5, 
						    0x8d, 0x03, 0x17, 
						    0x8c, 0x04, 0x8f,  

	// row 1, 5 font
	18, _NON_AUTOINC, 0x92, 0x8f, 0x06, 0x32, // 1-bit font
							0x8e, 0x05, 0x5e, // 1-bit font
							0x9f, 0x02, 0x67, // 4- bit font 
							0x8c, 0x06, 0xf8, // 1- bit font
							0xA1, 0x00, 0x67, // 2- bit font
							  
	// font Data 0x400 for CCW " ABCD" 9*5= 45 = 0x2D (have a blank)
	5,	_AUTOINC,            0x90, 0xC0,0x03,
	6,	_NON_AUTOINC,        0x92, 0x00,0x00,0xc5,  //CW rotation, hardware rotation enable, rotation enable
	5,  _AUTOINC,            0x90, 0xC0,0x05,
	12, _NON_AUTOINC,        0x92, 0x01,0x8c,0x3f,0x67,0xe4,0x92,0xbd,0x5a,0x01,  // 007h: decode compressed data, Osd compression enable

	5,  _AUTOINC,      0x90, 0xD4, 0x00,                 // font map " ABCD"
	13, _NON_AUTOINC,  0x92, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0xb6,0x72,
	15, _NON_AUTOINC,  0x92, 0xe9,0x4e,0xe8,0x4e,0x5c,0xdd,0x27,0xa3,0x3b,0xe1,0xea,0xfd,
	15, _NON_AUTOINC,  0x92, 0xb2,0xcf,0xac,0x02,0x80,0xa7,0xdd,0xb3,0xaa,0x3b,0x4f,0xad,
	15, _NON_AUTOINC,  0x92, 0xae,0xa4,0x6a,0x76,0x52,0x35,0x93,0x94,0x7b,0x56,0x6a,0x29,
	15, _NON_AUTOINC,  0x92, 0x53,0x00,0xf0,0x2c,0x71,0xb0,0x37,0x74,0x43,0x37,0x74,0x73,
	15, _NON_AUTOINC,  0x92, 0xbf,0x67,0x5b,0xca,0x14,0x00,0xd4,0x55,0x7b,0x56,0xcd,0xc9,
	15, _NON_AUTOINC,  0x92, 0x53,0x95,0x24,0x55,0x49,0x52,0x95,0x24,0xe5,0x7e,0x4f,0x6a,
	8,  _NON_AUTOINC,  0x92, 0x29,0x9f,0x02,0xfe,0xff,   


	5,	_AUTOINC,        0x90,0x80,0x07,
	4,	_NON_AUTOINC, 	 0x92,0x00,         //Disable Compression
	5,	_AUTOINC,        0x90,0x80,0x07,
	4,	_NON_AUTOINC, 	 0x92,0x00,         //Disable Compression
		5,	_AUTOINC,        0x90,0x80,0x07,
	4,	_NON_AUTOINC, 	 0x92,0x00,         //Disable Compression
		5,	_AUTOINC,        0x90,0x80,0x07,
	4,	_NON_AUTOINC, 	 0x92,0x00,         //Disable Compression
		5,	_AUTOINC,        0x90,0x80,0x07,
	4,	_NON_AUTOINC, 	 0x92,0x00,         //Disable Compression
	//font Data for CW, 
	5,  _AUTOINC,        0x90, 0xC0, 0x03,
	6,  _NON_AUTOINC, 	 0x92, 0x00, 0x00,0x85,  //CCW rotation  
	5,  _AUTOINC,        0x90, 0xC0, 0x05,
	12, _NON_AUTOINC,    0x92, 0x01, 0x8c,0x3f,0x67,0xe4,0x92,0xbd,0x5a,0x03,  // 007h: decode non-compressed data, Osd compression enable

	5, _AUTOINC,       0x90, 0xD4, 0x2d,  		// font map
	12, _NON_AUTOINC,  0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xd0, 0x00, 0x07,	 // map of "A",  // FONT 5											
	12, _NON_AUTOINC,  0x92, 0x98, 0x81, 0x0d, 0xf8, 0x81, 0x19, 0x8c, 0xc7, 0x3f,																									
	12, _NON_AUTOINC,  0x92, 0x0c, 0xc6, 0x60, 0x06, 0x6c, 0xc0, 0x00, 0x00, 0x00,																									
														
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x83, 0x33,	 // map of "n" ,  // FONT 6
	12, _NON_AUTOINC, 0x92, 0x8c, 0xc3, 0x3c, 0x0c, 0xc3, 0x30, 0x0c, 0xc3, 0x30,													
	12, _NON_AUTOINC, 0x92, 0x0c, 0xc3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x81, 0x03,	 // map of "s",  // FONT 7													
	12, _NON_AUTOINC, 0x92, 0x00, 0x83, 0x39, 0xf0, 0x00, 0x3e, 0x18, 0x82, 0x01,													
	12, _NON_AUTOINC, 0x92, 0xf0, 0x81, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0c, 0x80, 0x01, 0x04, 0x40, 0x00,	 //  FONT 8,9,10,11(3)													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x0c, 0x80, 0x0f, 0x04, 0x40, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x20,													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x30, 0x00, 0x01, 0x10, 0x00, 0x01,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,													
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x30, 0x00, 0x01, 0x18, 0x00, 0x01,													
	12, _NON_AUTOINC, 0x92, 0x08, 0x80, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,	

    // font base address = 0x400, 0x88*9*2 = 2448 = 0x990,0x990 +0x400 = 0xD90, 
	5,  _AUTOINC,     0x90, 0xDD, 0x90,  // font map for 2 bit offset    
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0x80, 0x0d, 0x30, 0xc0, 0x00, 0x18,	 // map of "X" 2-bit,
	12, _NON_AUTOINC, 0x92, 0x73, 0x00, 0x0c, 0x30, 0xec, 0x3f, 0x18, 0x80, 0x03,	
	12, _NON_AUTOINC, 0x92, 0x0d, 0xc0, 0x00, 0x06, 0x70, 0x00, 0x00, 0x00, 0x00,	
	12, _NON_AUTOINC, 0x92, 0x00, 0x00, 0x00, 0xb6, 0xfd, 0x30, 0xc8, 0xc0, 0x18,	
	12, _NON_AUTOINC, 0x92, 0x70, 0x00, 0x0d, 0xb0, 0x00, 0x07, 0x18, 0x81, 0x13,	
	12, _NON_AUTOINC, 0x92, 0x0d, 0xc7, 0x20, 0xc6, 0x73, 0xf8, 0x00, 0x00, 0x00,	
     
	5, _AUTOINC,      0x90,0x80,0x07,
	4, _NON_AUTOINC,  0x92,0x00,         //Disable Compression
	
	5, _AUTOINC,      0x90,0xC0,0x03,
	6, _NON_AUTOINC,  0x92,0x00,0x03,0x01,  //Double width, Double Height, rotation  

	5, _AUTOINC,      0x90,0xC0,0x0b,
	6, _NON_AUTOINC,  0x92,0x00,0x88,0x00,  //font base address[12] = 0, 2-bit font char select offset[7:0] = 0x88 = 136


    5, _AUTOINC,      0x90, 0x82, 0x03,  // window 4-1
    4, _NON_AUTOINC,  0x92, 0x00,
    
    5, _AUTOINC,      0x90, 0x82, 0x07,  // window 4-2
    4, _NON_AUTOINC,  0x92, 0x00,

    5, _AUTOINC,      0x90, 0x81, 0x0B,  // window 4-3
    4, _NON_AUTOINC,  0x92, 0x00,
    
    5, _AUTOINC,      0x90, 0x81, 0x23,  // window 8
    4, _NON_AUTOINC,  0x92, 0x00,

    5, _AUTOINC,      0x90, 0x81, 0x03,  // window 0
    4, _NON_AUTOINC,  0x92, 0x00,

    5, _AUTOINC,      0x90, 0x81, 0x07,  // window 5
    4, _NON_AUTOINC,  0x92, 0x00,

    5, _AUTOINC,      0x90, 0x81, 0x1B,  // window 6
    4, _NON_AUTOINC,  0x92, 0x00,
    
    5, _AUTOINC,      0x90, 0x81, 0x1F,  // window 7
    4, _NON_AUTOINC,  0x92, 0x00,

    5, _AUTOINC,      0x90, 0xC1, 0x24,  // window 9
    15, _NON_AUTOINC, 0x92, 0x00, 0xDC, 0x1F,   0x00, 0x40, 0x40,  0x11, 0x0F, 0x0F, 0xE0, 0xEA, 0xF5, // win9
    
    5, _AUTOINC,      0x90, 0xC1, 0x63,  // window 9 special function
    6, _NON_AUTOINC,  0x92, 0x80, 0x30, 0x3F,    

	_END
};

BYTE code tOSD_FONT_WIDTH[]=
{
    11, 7, 4, 10, 10, 10, 10,
};

BYTE code tQC_OSD_FONT_DATA[]=         //"Brianna"
{
	//========Address -- (00),
	0x00,0x00,0x00,
	0x07,0x0f,0x08,
	0x76,0xf0,0xcc,
	0x66,0x00,0xcc,
	0x77,0xff,0x8c,
	0x66,0x00,0xe6,
	0x67,0x0f,0x6c,
	0x70,0xf0,0x80,
	0x00,0x00,0x00,
	
	//========Address -- (01),
	0x80,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x33,0x6e,0x00,
	0x33,0x80,0x00,
	0x33,0x00,0x00,
	0x33,0x00,0x00,
	0x30,0x00,0x00,
	0x00,0x00,0x00,

	
	//========Address -- (02),
	0x00,0x00,0x00,
	0x03,0x00,0x00,
	0x30,0x00,0x00,
	0x33,0x00,0x00,
	0x33,0x00,0x00,
	0x33,0x00,0x00,
	0x33,0x00,0x00,
	0x30,0x00,0x00,
	0x00,0x00,0x00,
	
	//========Address -- (03),
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x13,0xff,0x08,
	0x30,0x17,0x88,
	0x13,0xf9,0x88,
	0x33,0x1f,0x88,
	0x10,0xe0,0xc0,
	0x00,0x00,0x00,
	
	//========Address -- (04),
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x33,0x7f,0x8c,
	0x33,0x80,0xcc,
	0x33,0x00,0xcc,
	0x33,0x00,0xcc,
	0x30,0x00,0xc0,
	0x00,0x00,0x00,
	
	//========Address -- (05),
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x33,0x7f,0x8c,
	0x33,0x80,0xcc,
	0x33,0x00,0xcc,
	0x33,0x00,0xcc,
	0x30,0x00,0xc0,
	0x00,0x00,0x00,
	
	//========Address -- (06),
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

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE ScalerQCA0PortTest(void);
BYTE ScalerQCD0PortTest(void);
BYTE ScalerQCD1PortTest(void);
void ScalerQCIDomainRandomGenOn(bit bRandomSelect);
void ScalerQCIDomainRandomGenOff(void);
void ScalerQCDDomainPatternGenOn(void);
void ScalerQCDDomainPatternGenOff(void);
void ScalerQCIDitherOn(bit bOutputSelect);
void ScalerQCIDitherOff(void);
void ScalerQCDDitherOn(bit bOutputSelect);
void ScalerQCDDitherOff(void);
void ScalerQCHighlightWindowOn(void);
void ScalerQCHighlightWindowOff(void);
bit ScalerQCCheckCRCOn(BYTE ucCRC1,BYTE ucCRC2, BYTE ucCRC3, BYTE ucCRCSelect);
void ScalerQCCheckCRCOff(void);
void ScalerQCAllDigitalFunctionDisable(void);

bit ScalerQCIDomainRandomGenTest(void);
bit ScalerQC422to444Test(void);
bit ScalerQCDigitalFilterTest(void);
bit ScalerQCColorConversionTest(void);
bit ScalerQCIDitherTest(void);
bit ScalerQCScaleDownTest(void);
void ScalerQCFRCDither(void);
void ScalerQCFRCRecoverSetting(void);
bit ScalerQCFRCTest(void);
bit ScalerQCScaleUpTest(void);
bit ScalerQCDDomainPGTest(void);
bit ScalerQCYPeakingTest(void);
bit ScalerQCDCRTest(void);
bit ScalerQCDCCTest(void);	 
bit ScalerQCICMTest(void);
bit ScalerQCConBriTest(void);
bit ScalerQCsRGBTest();
bit ScalerQCGammaTest();
bit ScalerQCPCMTest();
bit ScalerQCDDitherTest(void);
bit ScalerQCLiveshowTest(void);
bit ScalerQCOSDTest(void);
#if(_HDMI_SUPPORT == _ON)
bit ScalerQCHdmiTest(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//----------------------------------------------------------------------------
// QC Main Flow Process
//----------------------------------------------------------------------------
//--------------------------------------------------
// Description  : Test Process for A0 Port
// Input Value  : None
// Output Value : Test Result
//--------------------------------------------------
BYTE ScalerQCA0PortTest(void)
{
    BYTE ucResult = 0x00;

	ScalerQCAllDigitalFunctionDisable();

	ucResult = (ucResult | ScalerQCIDomainRandomGenTest());			   // I Domain Random Generator Test
	ucResult = (ucResult | ScalerQC422to444Test());					   // YUV 422 to 444 Test
    ucResult = (ucResult | ScalerQCDigitalFilterTest());			   // Digital Filter Test
	ucResult = (ucResult | ScalerQCColorConversionTest());			   // Color Conversion Test
	ucResult = (ucResult | ScalerQCIDitherTest());					   // I Dither Test
	ucResult = (ucResult | ((BYTE)ScalerQCFRCTest() << 2));			   // FRC Test
	ucResult = (ucResult | ((BYTE)ScalerQCScaleUpTest() << 1));		   // Scale Up Test
	ucResult = (ucResult | ((BYTE)ScalerQCDDomainPGTest() << 1));	   // D Domain Pattern Generator Test
	ucResult = (ucResult | ((BYTE)ScalerQCYPeakingTest() << 1));	   // Y-peaking	Test
	ucResult = (ucResult | ((BYTE)ScalerQCDCRTest() << 1));			   // DCR Test
	ucResult = (ucResult | ((BYTE)ScalerQCDCCTest() << 1));			   // DCC Test
	ucResult = (ucResult | ((BYTE)ScalerQCICMTest() << 1));			   // ICM Test
    ucResult = (ucResult | ((BYTE)ScalerQCConBriTest() << 1));		   // Contrast & Brightness Test
	ucResult = (ucResult | ((BYTE)ScalerQCsRGBTest() << 1));		   // sRGB Test
	ucResult = (ucResult | ((BYTE)ScalerQCGammaTest() << 1));		   // Output Gamma Test
    ucResult = (ucResult | ((BYTE)ScalerQCPCMTest() << 1));			   // PCM tTest
    ucResult = (ucResult | ((BYTE)ScalerQCDDitherTest() << 1));		   // D Ditehr Test
    ucResult = (ucResult | ((BYTE)ScalerQCOSDTest() << 3));			   // OSD Test
    ucResult = (ucResult | ((BYTE)ScalerQCLiveshowTest() << 2));	   // LiveShow(OD) Test

    return ucResult;
}

//--------------------------------------------------
// Description  : Test Process for A0 Port
// Input Value  : None
// Output Value : Test Result
//                _BIT0 => HDMI Test
//--------------------------------------------------
BYTE ScalerQCD0PortTest(void)
{
    BYTE ucResult = 0x00;

#if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
    ucResult |= ScalerQCHdmiTest();
#endif

    return ucResult;
}

//--------------------------------------------------
// Description  : Test Process for A0 Port
// Input Value  : None
// Output Value : Test Result
//                _BIT0 => HDMI Test                  
//--------------------------------------------------
BYTE ScalerQCD1PortTest(void)
{
    BYTE ucResult = 0x00;

#if(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
    ucResult |= ScalerQCHdmiTest();
#endif
	ucResult = (ucResult | ((BYTE)ScalerQCScaleDownTest() << 1));

    return ucResult;
}

//----------------------------------------------------------------------------
// Indivisual Test Block Process
//----------------------------------------------------------------------------
//--------------------------------------------------
// Description  : Enable I Domain Random Generator
// Input Value  : bRandomSelect ---> 0: R = G = B, 1: R != G != B
// Output Value : None
//--------------------------------------------------
void ScalerQCIDomainRandomGenOn(bit bRandomSelect)
{
	if(bRandomSelect == _GRAY)
	{
	   ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_10_IPG_CTRL0, ~_BIT6, 0x00);
	}
	else
	{
	   ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_10_IPG_CTRL0, ~_BIT6, _BIT6);
	}

	ScalerSetBit(CM_24_SCALE_DOWN_ACCESS_PORT, ~_BIT7, 0x00);
	ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT7, _BIT7);
}

//--------------------------------------------------
// Description  : Disable I Domain Random Generator
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCIDomainRandomGenOff(void)
{
	ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_10_IPG_CTRL0, ~_BIT6, 0x00);
	ScalerSetBit(CM_24_SCALE_DOWN_ACCESS_PORT, ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

	ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT7, 0x00);
}

//--------------------------------------------------
// Description  : Enable D Domain Pattern Generator With 10-bit Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCDDomainPatternGenOn(void)
{
	ScalerSetByte(P7_F0_DISP_PG_R_CTRL, 0x0D);
	ScalerSetByte(P7_F1_DISP_PG_G_CTRL, 0x0D);
	ScalerSetByte(P7_F2_DISP_PG_B_CTRL, 0x0D);
	ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, 0x30);
	ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, 0x60);
	ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, 0x90);
	ScalerSetByte(P7_F6_DISP_PG_PIXEL_DELTA, 0x09);
	ScalerSetByte(P7_F7_DISP_PG_LINE_DELTA, 0x13);
	ScalerSetByte(P7_F8_DISP_PG_PIXEL_STEP_MSB, 0x01);
	ScalerSetByte(P7_F9_DISP_PG_LINE_STEP_MSB, 0x10);
	ScalerSetByte(P7_FA_DISP_PG_STEP_LSB, 0x00);

	ScalerSetBit(P7_F0_DISP_PG_R_CTRL, ~_BIT7, _BIT7);
}

//--------------------------------------------------
// Description  : Disable D Domain Pattern Generator
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCDDomainPatternGenOff(void)
{
	ScalerSetBit(P7_F0_DISP_PG_R_CTRL, ~_BIT7, 0x00);
}

//--------------------------------------------------
// Description  : Enable I Domain Dither
// Input Value  : bOutputSelect ---> 0: _MSB 8-bit, 1: _LSB 8-bit
// Output Value : None
//--------------------------------------------------
void ScalerQCIDitherOn(bit bOutputSelect)
{    
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_SEQ_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
	if(bOutputSelect == _MSB)
	{
		ScalerSetBit(CM_8A_I_DITHERING_CTRL2, ~(_BIT1 | _BIT0), _BIT0);
	}
	else
	{
		ScalerSetBit(CM_8A_I_DITHERING_CTRL2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
	}

    ScalerSetBit(CM_89_I_DITHERING_CTRL1, 0x00, _BIT5);

	ScalerSetByte(CM_02_STATUS0, 0x00);
    ScalerSetByte(CM_03_STATUS1, 0x00);
}

//--------------------------------------------------
// Description  : Disable I Domain Dither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCIDitherOff(void)
{
	ScalerSetByte(CM_89_I_DITHERING_CTRL1, 0x00);

	ScalerSetByte(CM_02_STATUS0, 0x00);
    ScalerSetByte(CM_03_STATUS1, 0x00);
}


//--------------------------------------------------
// Description  : Enable D Domain Dither
// Input Value  : bOutputSelect ---> 0: _MSB 8-bit, 1: _LSB 8-bit
// Output Value : None
//--------------------------------------------------
void ScalerQCDDitherOn(bit bOutputSelect)
{    
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_D_DOMAIN_DITHER_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_D_DOMAIN_DITHER_SEQ_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
	if(bOutputSelect == _MSB)
	{
		ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7), 0x00);
	}
	else
	{
		ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7), _BIT7);
	}

    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT5);
}

//--------------------------------------------------
// Description  : Disable D Domain Dither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCDDitherOff(void)
{
	ScalerSetByte(CM_6A_DITHERING_CTRL1, 0x00);
}

//--------------------------------------------------
// Description  : Enable Highlight Window
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCHighlightWindowOn(void)
{
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~_BIT7, _BIT7);
	ScalerBurstWrite(tQC_HIGHLIGHT_WINDOW_SETTING, 14, GET_CURRENT_BANK_NUMBER(), CM_61_HW_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7 | _BIT6), _BIT6);
}

//--------------------------------------------------
// Description  : Disable Highlight Window
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCHighlightWindowOff(void)
{
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~_BIT7, _BIT7);
    ScalerSetByte(CM_60_HW_ACCESS_PORT, 0x8C);
    ScalerSetByte(CM_61_HW_DATA_PORT, 0x00);
    ScalerSetByte(CM_60_HW_ACCESS_PORT, 0x8D);
    ScalerSetByte(CM_61_HW_DATA_PORT, 0x00);
    ScalerSetByte(CM_60_HW_ACCESS_PORT, 0x00);
}

//--------------------------------------------------
// Description  : Enable CRC 
// Input Value  : ucCRC1, ucCRC2, ucCRC3, ucCRCSelect ---> 0: _I_DOMAIN_CRC,  1: _M_DOMAIN_CRC, 2: _D_DOMAIN_CRC
// Output Value : 0: _FALSE, 1: _TRUE
//--------------------------------------------------
bit ScalerQCCheckCRCOn(BYTE ucCRC1,BYTE ucCRC2, BYTE ucCRC3, BYTE ucCRCSelect)
{
	BYTE ucData[3] = 0;

    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
			
	if(ucCRCSelect == _I_DOMAIN_CRC)
	{
	   ScalerSetByte(CM_8D_PS_ACCESS_PORT, 0x07);
	   ScalerSetBit(CM_8E_PS_DATA_PORT, ~(_BIT5), _BIT5);
       ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x01);     
    }
	else if(ucCRCSelect == _M_DOMAIN_CRC)
	{
	   ScalerSetByte(CM_8D_PS_ACCESS_PORT, 0x07);
	   ScalerSetBit(CM_8E_PS_DATA_PORT, ~(_BIT5), _BIT5);
       ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x41);
	}
	else if(ucCRCSelect == _D_DOMAIN_CRC)
	{
	   ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x81);
	}

	ScalerTimerWaitForEvent(_EVENT_DVS);				
    ScalerTimerWaitForEvent(_EVENT_DVS);
			
    ScalerRead(CM_2D_OP_CRC_CKSM, 3, ucData, _NON_AUTOINC);

	if((ucData[0] == ucCRC1)&&(ucData[1] == ucCRC2)&&(ucData[2] == ucCRC3))	
    {
	    DebugMessageScaler("5. ===Pass===",0x00);

		return _FALSE;
    }
	else 
	{
	    DebugMessageScaler("5. ucData[0]",ucData[0]);
        DebugMessageScaler("5. ucData[1]",ucData[1]);
        DebugMessageScaler("5. ucData[2]",ucData[2]);

    	return _TRUE;
	}
}

//--------------------------------------------------
// Description  : Disable CRC 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCCheckCRCOff(void)
{
    ScalerSetByte(CM_8D_PS_ACCESS_PORT, 0x07);
    ScalerSetBit(CM_8E_PS_DATA_PORT, ~(_BIT5), 0x00);
    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
}

//--------------------------------------------------
// Description  : Disable All Digital Function & Watch Dog 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCAllDigitalFunctionDisable(void)
{
    ScalerSetByte(CM_0C_WATCH_DOG_CTRL0, 0x00);		// Disable Watch Dog
    ScalerSetByte(CM_0D_WATCH_DOG_CTRL1, 0x00);		// Disable Watch Dog

    ScalerQCCheckCRCOff();							// Disable CRC Check
   
    ScalerSetByte(CM_28_VDISP_CTRL, 0x0F);			//VDIS_CTRL,       
                                                    //Frame Sync Mode Enable
                                                    //Display Output Double Port Enable
                                                    //Display Output Run Enable
                                                    //Display Timing Run Enable

    //--------------------I Domain------------------//
    ScalerQCIDomainRandomGenOff();					// Disable I Domain Random Generator
    ScalerSetByte(CM_1F_V8_YUV_CONVERSION, 0x00);   // Disable YUV422 to 444
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL, 0x70);	
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, 0x00);	// Y(G)/Pb(B)/Pr(R) Function Disable//Initial Value=0
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL, 0x00);	// Disable Digital Filter
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    ScalerSetByte(CM_9C_YUV2RGB_CTRL, 0x00);		// Disable Color Conversion

    ScalerSetByte(CM_89_I_DITHERING_CTRL1, 0x00);	// Disable I Domain Dither
    //--------------------D Domain------------------//
    ScalerSetByte(CM_96_M_DITHERING_CTRL1, 0x00);	// Disable M Domain Dither

    ScalerQCHighlightWindowOff(); 					// Disable Highlight Window
    ScalerQCDDomainPatternGenOff();					// Disable D Domain Pattern Generator

    ScalerSetByte(P7_D8_DCR_ACCESS_PORT, 0x00);		// Disable DCR
    ScalerSetByte(P7_C7_DCC_CTRL0, 0x00);		    // Disable DCC
    ScalerSetByte(P7_D6_PKING_ACCESS_PORT, 0x00);	// Disable Y-Peaking
    ScalerSetByte(P7_D0_ICM_CTRL, 0x80);
    ScalerSetByte(P7_D1_ICM_SEL, 0x00);
    ScalerSetByte(P7_D0_ICM_CTRL, 0x00);			// Disable ICM
    ScalerSetByte(P9_A1_INPUT_GAMMA_CTRL, 0x00);	// Disable Input Gamma
    ScalerSetByte(CM_62_COLOR_CTRL, 0x00);			// Disable sRGB/Contrast/Brightness
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x00);			// Disable Output Gamma
   
    ScalerSetByte(CM_6C_OVERLAY_CTRL, 0x00);		// Disable OSD

    ScalerSetByte(CM_6A_DITHERING_CTRL1, 0x00);		// Disable D Domain Dither
    ScalerSetByte(P3_A1_LS_CTRL0, 0x00);			// Disable LiveShow

    //---------------------SDRAM--------------------//
    ScalerSetByte(CM_26_I_YUV444TO422, 0x00);		// Disable FRC YUV444to422 
    ScalerSetByte(P5_CF_SDRF_MN_DISP_CTRL, 0x05);	// Disable FRC YUV422to444

    ScalerGlobalIRQControl(_DISABLE);	     		// Disable Interrupt
}

//--------------------------------------------------
// Description  : I Domain Random Generator Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCIDomainRandomGenTest(void)
{
	BYTE ucData = 0;

	DebugMessageScaler("5. I Domain Random Generator Start", 0x00);
	ScalerQCIDomainRandomGenOn(_GRAY);
	DebugMessageScaler("5. Mode_0", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF9, 0x94, 0x8F, _I_DOMAIN_CRC) << 0));

	ScalerQCIDomainRandomGenOn(_MASS);
	DebugMessageScaler("5. Mode_1", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x8D, 0xB1, 0x8A, _I_DOMAIN_CRC) << 1));

	ScalerQCIDitherOn(_LSB);
	DebugMessageScaler("5. Mode_2", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF7, 0xD5, 0xDA, _I_DOMAIN_CRC) << 2));

	ScalerQCIDomainRandomGenOn(_GRAY);
	ScalerQCIDitherOn(_LSB);
	DebugMessageScaler("5. Mode_3", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x15, 0x71, 0xFA, _I_DOMAIN_CRC) << 3));

	ScalerQCIDomainRandomGenOff();
	ScalerQCIDitherOff();
	ScalerQCCheckCRCOff();

	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. I Domain Random Generator End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. I Domain Random Generator End", 0x00);
	   return _TEST_FAIL;
	}	  
}

//--------------------------------------------------
// Description  : YUV422 to 444 Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQC422to444Test(void)
{
	BYTE ucData = 0;

	DebugMessageScaler("5. YUV422 to 444 Start", 0x00);
	ScalerQCIDomainRandomGenOn(_MASS);

	ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);					 // Enable YUV422 to 444
	DebugMessageScaler("5. Mode_0", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x87, 0x04, 0x05, _I_DOMAIN_CRC) << 0));

	ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));
	DebugMessageScaler("5. Mode_1", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xA7, 0xF0, 0x47, _I_DOMAIN_CRC) << 1));

	ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));
	DebugMessageScaler("5. Mode_2", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x52, 0x2D, 0x60, _I_DOMAIN_CRC) << 2));

	ScalerQCIDitherOn(_LSB);

	ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);
	DebugMessageScaler("5. Mode_3", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xAE, 0xC5, 0x2B, _I_DOMAIN_CRC) << 3));

	ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));
	DebugMessageScaler("5. Mode_4", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFA, 0xD9, 0xB1, _I_DOMAIN_CRC) << 4));

	ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));
	DebugMessageScaler("5. Mode_5", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x13, 0x4C, 0x77, _I_DOMAIN_CRC) << 5));

	ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);               // Disable YUV422 to 444
	ScalerQCIDomainRandomGenOff();
	ScalerQCIDitherOff();
	ScalerQCCheckCRCOff();

	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. YUV422 to 444 End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. YUV422 to 444 End", 0x00);
	   return _TEST_FAIL;
	}

}

//afu modify Start for QC 20111017 
//--------------------------------------------------
// Description  : DigitalFilter Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCDigitalFilterTest(void)
{
	BYTE ucData = 0;

	DebugMessageScaler("5. Digital Filter Start", 0x00);
	ScalerQCIDomainRandomGenOn(_MASS);

	//Digital Filter For Phase
	ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Disable Digital Filter
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Y/Pb/Pr Function Disable //Initial Value=0
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x00); // Disable Digital Filter
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Digital Filter Coefficient
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xF0); 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x10); // Enable Phase subFunction
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x90); 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x20);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Disbale negative semar sunFunction                           
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x30);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Disbale positive semar sunFunction                           
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x40);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Disbale negative ringing subFunction                         
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x50);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Disbale positive ringing subFunction                         
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x60);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Disbale mismatch subFunction                                 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x80);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Disbale Noise Reduction subFunction 
	
	ScalerTimerDelayXms(50);
	DebugMessageScaler("5. Mode_0", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x8D, 0xB1, 0x8A, _I_DOMAIN_CRC) << 0));

    //Digital Filter For Other Sub-Function(disable) 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Disable Digital Filter
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Y/Pb/Pr Function Disable //Initial Value=0
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x00); // Disable Digital Filter
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Digital Filter Coefficient
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xF0); 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x10); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Disbale Phase subFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x20); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x94); // Enable negative semar sunFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x30); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xA8); // Enable positive semar sunFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x40); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xBC); // Enable negative ringing subFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x50); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xb0); // Enable positive ringing subFunction (0xd0:80   0xb0:48)
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x60); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x80); // Enable mismatch subFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x80); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xE0); // Enable Noise Reduction subFunction

    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_1", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEE, 0xFB, 0x41, _I_DOMAIN_CRC) << 1));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x04); // only reduce ringing condition + mismatch
    
	ScalerTimerDelayXms(50);
	DebugMessageScaler("5. Mode_2", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEE, 0xFB, 0x41, _I_DOMAIN_CRC) << 2));

	ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x08); // only reduce smear condition + mismatch
    
	ScalerTimerDelayXms(50);
	DebugMessageScaler("5. Mode_3", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEE, 0xFB, 0x41, _I_DOMAIN_CRC) << 3));

	ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x0C); //  no adjust  + mismatch
    
	ScalerTimerDelayXms(50);
	DebugMessageScaler("5. Mode_4", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEE, 0xFB, 0x41, _I_DOMAIN_CRC) << 4));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x02); // disable + noise reduction
    
	ScalerTimerDelayXms(50);
	DebugMessageScaler("5. Mode_5", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x61, 0xFC, 0x40, _I_DOMAIN_CRC) << 5));

	ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Disable Digital Filter
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Y/Pb/Pr Function Disable //Initial Value=0
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x00); // Disable Digital Filter
		  	 
	ScalerQCIDomainRandomGenOff();   
	ScalerQCCheckCRCOff();   
	
	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. Digital Filter End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. Digital Filter End", 0x00);
	   return _TEST_FAIL;
	}	   

}

//----------------------------------------------------------------------------
// Color Conversion Test
//----------------------------------------------------------------------------
bit ScalerQCColorConversionTest(void)
{
    BYTE ucResult = _TEST_PASS;

    DebugMessageScaler("5. Color Conversion Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerTimerDelayXms(50);

    // Enable YUV2RGB coefficient access
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT1, _BIT1);
    
    // K11 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x07);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x04);
    
    // K11 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x0F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0xA7);
    
    // K13 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x17);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x06);
    
    // K13 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x1F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x87);
    
    // K22 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x27);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x01);
    
    // K22 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x2F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x9A);
    
    // K23 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x37);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x03);
    
    // K23 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x3F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x53);
    
    // K32 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x47);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x08);
    
    // K32 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x4F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x40);
    
    // R offset high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x57);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x00);
    
    // R offset low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x5F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x00);
    
    // G offset high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x67);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x00);
    
    // G offset low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x6F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x00);
    
    // B offset high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x77);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x00);
    
    // B offset low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x7F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x00);
    
    // R gain high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x87);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x02);
    
    // R gain low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x8F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x00);
    
    // G gain high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x97);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x02);
    
    // G gain low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x9F);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x00);
    
    // B gain high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xA7);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x02);
    
    // B gain low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xAF);
    ScalerSetByte(CM_9E_YUV_RGB_COEF_DATA, 0x00);
    
    // Enable Y signed, Y clamp, CbCr clamp
    ScalerSetBit(CM_9D_YUV_RGB_ACCESS, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
    
    // Enable YUV2RGB conversion & Disable YUV2RGB coefficient access
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~(_BIT1 | _BIT0), _BIT0|_BIT1); // 
   
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    // Check CRC
    DebugMessageScaler("5. Color Con case_0", ucResult);
    ucResult = ScalerQCCheckCRCOn(0x5A, 0x1E, 0x18, _I_DOMAIN_CRC);  

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Color Con case_1", ucResult);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0x78, 0x5A, 0xDB, _I_DOMAIN_CRC)<<1);

    // Disable YUV2RGB conversion
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS,  0x00); // 9D must be operated when 9C Enable YUV/RGB coefficient Access is on
    ScalerSetByte(CM_9C_YUV2RGB_CTRL,  0x00);      // turn off 

    ScalerQCIDitherOff();
    ScalerQCIDomainRandomGenOff();   
    ScalerQCCheckCRCOff();  
    
	if(ucResult == 0)
	{
		DebugMessageScaler("5. Color Conversion End", 0x00);
		return _TEST_PASS;		
	}
	else
	{
		DebugMessageScaler("5. Fail Mode", ucResult);
	   	DebugMessageScaler("5. Color Conversion End", 0x00);
	   	return _TEST_FAIL;	
	}
}

//--------------------------------------------------
// Description  : I Domain Dither Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCIDitherTest(void)
{
	BYTE ucData = 0;
	
	DebugMessageScaler("5. I Dither Start", 0x00);

	ScalerQCIDomainRandomGenOn(_MASS);
	
	// 8 bit dither test    
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_SEQ_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

#if(_I_DITHER_TEMP == _ON)
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_DITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
#endif

    // MSB
	ScalerSetBit(CM_8A_I_DITHERING_CTRL2, ~(_BIT1 | _BIT0), _BIT0);
	
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, 0x00, _BIT5 | (_I_DITHER_TEMP << 4));
    
	
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x98, 0x90, 0xEA, _I_DOMAIN_CRC) << 0));

    //LSB
	ScalerSetBit(CM_8A_I_DITHERING_CTRL2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
	
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xD9, 0x70, 0x5E, _I_DOMAIN_CRC) << 1));
   
	ScalerQCIDitherOff();
	ScalerQCCheckCRCOff();   

	// 6 bit dither test
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_10_6_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    // MSB
	ScalerSetBit(CM_8A_I_DITHERING_CTRL2, ~(_BIT1 | _BIT0), _BIT0);
	
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, 0x00, _BIT5 | (_I_DITHER_TEMP << 4));
    
	
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2C, 0x4F, 0x4C, _I_DOMAIN_CRC) << 2));

    //LSB
	ScalerSetBit(CM_8A_I_DITHERING_CTRL2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
	
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xB5, 0x71, 0x1B, _I_DOMAIN_CRC) << 3));
  
	ScalerQCIDitherOff();
	ScalerQCIDomainRandomGenOff();
	ScalerQCCheckCRCOff();   		 
	
	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. I Dither End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. I Dither End", 0x00);
	   return _TEST_FAIL;
	}
}

//--------------------------------------------------
// Description  : Set FRC Dither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFRCDither(void)
{
    ScalerSetBit(CM_96_M_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    ScalerWrite(CM_95_M_DITHERING_DATA_ACCESS, 24, (&tQC_D_DOMAIN_DITHER_SEQ_TABLE[0]), _NON_AUTOINC);

    ScalerSetBit(CM_96_M_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerWrite(CM_95_M_DITHERING_DATA_ACCESS, 24, (&tQC_I_DOMAIN_DITHER_TABLE[0]), _NON_AUTOINC);
    
#if( _D_DITHER_TEMP == _ENABLE )
    ScalerSetBit(CM_96_M_DITHERING_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerWrite(CM_95_M_DITHERING_DATA_ACCESS, 4, (&tQC_DITHER_TEMOFFSET[0]), _NON_AUTOINC);
#endif

    ScalerSetByte(CM_96_M_DITHERING_CTRL1, (0x20 | (_D_DITHER_TEMP << 4)));
}

//--------------------------------------------------
// Description  : Recover FRC setting 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFRCRecoverSetting(void)
{
    // FRC off & Frame Sync mode
	ScalerSetByte(P5_CF_SDRF_MN_DISP_CTRL, 0x07);

    // Double buffer enable
	ScalerSetByte(P5_D0_SDRF_MN_SDR_STATUS, 0x10);
    
	ScalerSetBit(CM_22_FIFO_FREQUENCY, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
    ScalerSetBit(CM_96_M_DITHERING_CTRL1, ~(_BIT5 | _BIT4), 0x00);
	ScalerTimerDelayXms(30);

    // Disable random gen.
    ScalerQCIDomainRandomGenOff();    
}

//--------------------------------------------------
// Description  : FRC QC test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCFRCTest(void)
{
    BYTE ucData = 0x00;
    
	DebugMessageScaler("5. FRC Start", 0x00);

    //-----------------------------------
    // Set Random Generator
    //-----------------------------------    
	ScalerQCIDomainRandomGenOn(_MASS);
    
    //-----------------------------------
    // SDRAM Setting
    //-----------------------------------
    // Pin share SDRAM : 1M x 32 SDRAM
    ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

	ScalerTimerDelayXms(50);

    // Reset SDRAM
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, _BIT4);
    ScalerTimerDelayXms(50);
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, 0x00);

    // Set FIFO freq. = MPLL
    ScalerSetByte(CM_22_FIFO_FREQUENCY, 0x04);
    
	// Set SDRAM Size
	ScalerSetByte(P4_A1_SDR_CTRL0, _SDR_ROW_DELAY);
	ScalerSetByte(P4_A2_SDR_CTRL1, _SDR_COL_DELAY);
	ScalerSetByte(P4_A3_SDR_AREF_TIME, 0x0D);
	ScalerSetByte(P4_A4_SDR_PRCG, 0x83);	
	ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x63);
	ScalerSetByte(P4_A6_SDR_SLEW_RATE, 0x00);	

	// Set SDRAM Token ring
	// OD = _OFF & FRC = _ON
	ScalerSetByte(P4_A7_SDR_AREF_CNT, 0xC0);
	ScalerSetByte(P4_AA_SDR_RSC_AREF, 0x11);
	ScalerSetByte(P4_AB_SDR_RSC_MCU, 0x22);

	ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x44);
	ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x88);
	ScalerSetByte(P4_B0_SDR_RSC_RD, 0x00);
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);

	// Set MCLK phase
	ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x00);	
	ScalerSetByte(P4_C1_SDR_CLK_DLY2, 0x14);
	ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
	ScalerSetByte(P4_C3_DQS0_DLY2, 0x34);
	ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
	ScalerSetByte(P4_C5_DQS1_DLY2, 0x34);
	ScalerSetByte(P4_C6_DQS2_DLY1, 0x00);
	ScalerSetByte(P4_C7_DQS2_DLY2, 0x00);	
	ScalerSetByte(P4_C8_DQS3_DLY1, 0x00);	
	ScalerSetByte(P4_C9_DQS3_DLY2, 0x00);	

	ScalerTimerDelayXms(100);    
    
    //-----------------------------------
    // Check CRC
    //-----------------------------------    
	DebugMessageScaler("5. Mode_0", ucData);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x56, 0x67, 0x17, _D_DOMAIN_CRC) << 0));
	
    //-----------------------------------
    // FRC 6 Bit Frame Setting
    //-----------------------------------
    ScalerSetByte(P5_A8_SDRF_IN1_WATER_LEVEL, 0xA0);
    ScalerSetByte(P5_A9_SDRF_IN1_WR_NUM_H, 0x08);
    ScalerSetByte(P5_AA_SDRF_IN1_WR_NUM_L, 0xFF);
    ScalerSetByte(P5_AB_SDRF_IN1_WR_LEN, 0xA0);
    ScalerSetByte(P5_AC_SDRF_IN1_WR_REMAIN, 0xA0);
    ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, 0x00);
    ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, 0x00);
    ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, 0x00);
    ScalerSetByte(P5_B0_SDRF_IN1_LINE_STEP_H, 0x08);
    ScalerSetByte(P5_B1_SDRF_IN1_LINE_STEP_L, 0xD0);
    ScalerSetByte(P5_B2_SDRF_IN1_BLOCK_STEP_H, 0x05);
    ScalerSetByte(P5_B3_SDRF_IN1_BLOCK_STEP_L, 0xA0);
    ScalerSetByte(P5_B4_SDRF_IN1_BL2_ADDR_H, 0x2D);
    ScalerSetByte(P5_B5_SDRF_IN1_BL2_ADDR_M, 0x00);
    ScalerSetByte(P5_B6_SDRF_IN1_BL2_ADDR_L, 0x00);
    ScalerSetByte(P5_B7_SDRF_IN1_LINE_NUM_H, 0x14);
    ScalerSetByte(P5_B8_SDRF_IN1_LINE_NUM_L, 0x00);
    ScalerSetByte(P5_B9_SDRF_IN1_SDR_CTRL, 0x82);
    ScalerSetByte(P5_BB_SDRF_IN1_SDR_STATUS, 0x04);
    ScalerSetByte(P5_BC_SDRF_MN_PRERD_VST_H, 0x00);
    ScalerSetByte(P5_BD_SDRF_MN_PRERD_VST_L, 0x03);
    ScalerSetByte(P5_BE_SDRF_MN_PXL_NUM_H, 0x05);
    ScalerSetByte(P5_BF_SDRF_MN_PXL_NUM_L, 0x00);
    ScalerSetByte(P5_C0_SDRF_MN_WTLVL, 0xA0);
    ScalerSetByte(P5_C2_SDRF_MN_READ_NUM_H, 0x08);
    ScalerSetByte(P5_C3_SDRF_MN_READ_NUM_L, 0xFF);
    ScalerSetByte(P5_C4_SDRF_MN_READ_LEN, 0xA0);
    ScalerSetByte(P5_C5_SDRF_MN_READ_REMAIN, 0xA0);
    ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, 0x00);
    ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, 0x00);
    ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, 0x00);
    ScalerSetByte(P5_C9_SDRF_MN_LINE_STEP_H, 0x08);
    ScalerSetByte(P5_CA_SDRF_MN_LINE_STEP_L, 0xD0);
    ScalerSetByte(P5_CB_SDRF_MN_BLOCK_STEP_H, 0x05);
    ScalerSetByte(P5_CC_SDRF_MN_BLOCK_STEP_L, 0xA0);
    ScalerSetByte(P5_CD_SDRF_MN_LINE_NUM_H, 0x14);
    ScalerSetByte(P5_CE_SDRF_MN_LINE_NUM_L, 0x00);
    ScalerSetByte(P5_CF_SDRF_MN_DISP_CTRL, 0x09);
    ScalerSetByte(P5_D0_SDRF_MN_SDR_STATUS, 0x11); // Set input RGB 6 bit


/*
    // Check CRC
    ucData = 0x00;
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x7E, 0x67, 0xC9, _D_DOMAIN_CRC) << 7));

	if(ucData != 0x00)
	{
	   DebugMessageScaler("5. FRC Fail Mode-test", ucData);
	   DebugMessageScaler("5. FEC End", 0x00);
       ScalerQCFRCRecoverSetting();
       
	   return _TEST_FAIL;
	}	   
*/
    //-----------------------------------
    // FRC Dither Setting
    //-----------------------------------
    ScalerQCFRCDither();
    
    ScalerTimerDelayXms(100);

    //-----------------------------------
    // Check CRC
    //-----------------------------------
	DebugMessageScaler("5. Mode_1", ucData);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x1C, 0x23, 0x17, _D_DOMAIN_CRC) << 1));

    //-----------------------------------
    // Recover FRC Setting
    //-----------------------------------
    ScalerQCFRCRecoverSetting();   

	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. FRC End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. YPeaking End", 0x00);
	   return _TEST_FAIL;
	}
}

//--------------------------------------------------
// Description  : ScaleUp Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCScaleUpTest(void)
{
    BYTE ucData = 0;
    DebugMessageScaler("5. Scale Up Start", 0x00);
    
    ScalerQCIDomainRandomGenOn(_MASS);
    
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x56, 0x67, 0x17, _D_DOMAIN_CRC) << 0));

	ScalerQCIDomainRandomGenOff();   
	ScalerQCCheckCRCOff();   
	
	if(ucData == 0x00)
	{
        DebugMessageScaler("5. Scale Up End", 0x00);	
	    return _TEST_PASS;
	}
	else
	{
	    DebugMessageScaler("5. Fail Mode", ucData);
        DebugMessageScaler("5. Scale Up End", 0x00);	
	    return _TEST_FAIL;
	}	        
}

//--------------------------------------------------
// Description  : D domain PG 
// Input Value  : None
// Output Value : None
//--------------------------------------------------	
bit ScalerQCDDomainPGTest(void)
{
	BYTE ucError = 0;
	
	DebugMessageScaler("5. D Domain PG Start", 0x00);
	
	ScalerQCDDomainPatternGenOn();	
	DebugMessageScaler("5. D PG Case_0", ucError);
	ucError = (BYTE)ScalerQCCheckCRCOn(0xD2, 0x5A, 0x4A, _D_DOMAIN_CRC); //D25A4A
	
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);

	ScalerQCDDitherOn(_LSB);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. D PG Case_1", ucError);
	ucError = ucError|((BYTE)ScalerQCCheckCRCOn(0x9D, 0xB3, 0xEB, _D_DOMAIN_CRC)<<1); 
	
	ScalerQCDDitherOff();

	ScalerSetByte(P7_F0_DISP_PG_R_CTRL, 0x8a);
	ScalerSetByte(P7_F1_DISP_PG_G_CTRL, 0x0a);
	ScalerSetByte(P7_F2_DISP_PG_B_CTRL, 0x0a);
	ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, 0xff);
	ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, 0x00);
	ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, 0x88);
	ScalerSetByte(P7_F6_DISP_PG_PIXEL_DELTA, 0x00);
	ScalerSetByte(P7_F7_DISP_PG_LINE_DELTA, 0x00);
	ScalerSetByte(P7_F8_DISP_PG_PIXEL_STEP_MSB, 0x05);
	ScalerSetByte(P7_F9_DISP_PG_LINE_STEP_MSB, 0x0a);
	ScalerSetByte(P7_FA_DISP_PG_STEP_LSB, 0x22);
	
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. D PG Case_2", ucError);
	ucError = ucError|((BYTE)ScalerQCCheckCRCOn(0x29, 0xD4, 0x5f,  _D_DOMAIN_CRC)<<2); 


	ScalerSetByte(P7_F0_DISP_PG_R_CTRL, 0x95);
	ScalerSetByte(P7_F1_DISP_PG_G_CTRL, 0x05);
	ScalerSetByte(P7_F2_DISP_PG_B_CTRL, 0x05);
	ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, 0x1a);
	ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, 0x67);
	ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, 0xf7);
	ScalerSetByte(P7_F6_DISP_PG_PIXEL_DELTA, 0x1b);
	ScalerSetByte(P7_F7_DISP_PG_LINE_DELTA, 0x80);
	ScalerSetByte(P7_F8_DISP_PG_PIXEL_STEP_MSB, 0x01);
	ScalerSetByte(P7_F9_DISP_PG_LINE_STEP_MSB, 0x11);
	ScalerSetByte(P7_FA_DISP_PG_STEP_LSB, 0x12);

	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. D PG Case_3", ucError);
	ucError = ucError|((BYTE)ScalerQCCheckCRCOn(0xab, 0x4a, 0x26,  _D_DOMAIN_CRC)<<3); 	
	

	ScalerSetByte(P7_F0_DISP_PG_R_CTRL, 0xa3);
	ScalerSetByte(P7_F1_DISP_PG_G_CTRL, 0x23);
	ScalerSetByte(P7_F2_DISP_PG_B_CTRL, 0x03);
	ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, 0x22);
	ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, 0x31);
	ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, 0xff);
	ScalerSetByte(P7_F6_DISP_PG_PIXEL_DELTA, 0x80);
	ScalerSetByte(P7_F7_DISP_PG_LINE_DELTA, 0x00);
	ScalerSetByte(P7_F8_DISP_PG_PIXEL_STEP_MSB, 0x0a);
	ScalerSetByte(P7_F9_DISP_PG_LINE_STEP_MSB, 0x0a);
	ScalerSetByte(P7_FA_DISP_PG_STEP_LSB, 0x11);

	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. D PG Case_4", ucError);
	ucError = ucError|((BYTE)ScalerQCCheckCRCOn(0xE3, 0xFF, 0x7D,  _D_DOMAIN_CRC)<<4); 	


	ScalerQCDDomainPatternGenOff();

	if(ucError == 0)
	{
		DebugMessageScaler("5. D Domain PG End", 0x00);
		return _TEST_PASS;
		
	}
	else
	{
		DebugMessageScaler("5. Fail Mode", ucError);
	   	DebugMessageScaler("5. D Domain PG End", 0x00);
	   	return _TEST_FAIL;	
	}	
}

//--------------------------------------------------
// Description  : YPeaking Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCYPeakingTest(void)
{
	BYTE ucData = 0;

	DebugMessageScaler("5. YPeaking Start", 0x00);
	ScalerQCIDomainRandomGenOn(_MASS);
	ScalerQCDDitherOn(_MSB);

	ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_00_PEAKING_COEF0, 0x7E);
	ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_01_PEAKING_COEF1, 0xD2);
	ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_02_PEAKING_COEF2, 0xC1);
	ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_03_PEAKING_MIN, 0x1F);
	ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_04_PEAKING_MAX_POS, 0x25);
	ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_05_PEAKING_MAX_REG, 0xE3);
	

	ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~(_BIT7 |  _BIT5 | _BIT2 | _BIT1 | _BIT0), 0x00);
	ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT6, _BIT6);			  // Enable YPeaking & coring

	// RandomGen + DDither(_MSB)
	DebugMessageScaler("5. Mode_0", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xDE, 0xEE, 0x3C, _D_DOMAIN_CRC) << 0));

	// RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
	ScalerQCHighlightWindowOn();
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT1 | _BIT0), _BIT0);
	DebugMessageScaler("5. Mode_1", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x82, 0xB3, 0x4F, _D_DOMAIN_CRC) << 1));

	// RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
	ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT5, _BIT5);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT1 | _BIT0), _BIT1);
	DebugMessageScaler("5. Mode_2", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x63, 0x86, 0xAF, _D_DOMAIN_CRC) << 2));

	
	ScalerQCHighlightWindowOff();
	ScalerQCIDomainRandomGenOff();

	ScalerQCDDomainPatternGenOn();
	ScalerQCDDitherOn(_LSB);

	// PatternGen + DDither(_LSB)
	ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT5, 0x00);
	DebugMessageScaler("5. Mode_3", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x87, 0xB8, 0xAA, _D_DOMAIN_CRC) << 3));

	// PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
	ScalerQCHighlightWindowOn();
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT1 | _BIT0), _BIT0);
	DebugMessageScaler("5. Mode_4", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x83, 0x07, 0xE6, _D_DOMAIN_CRC) << 4));

	// PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT5, _BIT5);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT1 | _BIT0), _BIT1);
	DebugMessageScaler("5. Mode_5", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x92, 0x5A, 0x2B, _D_DOMAIN_CRC) << 5));	

	ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~(_BIT6 | _BIT5), 0x00);			  	 // Disable Ypeaking & coring
	ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
	ScalerQCHighlightWindowOff();
	ScalerQCCheckCRCOff();   
	
	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. YPeaking End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. YPeaking End", 0x00);
	   return _TEST_FAIL;
	}	   
}

//--------------------------------------------------
// Description  : DCC Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCDCCTest(void)	
{
	BYTE ucData = 0;

	DebugMessageScaler("5. DCC Start", 0x00);
	ScalerQCIDomainRandomGenOn(_MASS);
	ScalerQCDDitherOn(_MSB);

    // Fill DCC control table
    // Select page0
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
	ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x5E);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_DCC_SETTING1, 9, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Fill DCC user curve table
    // Select page1
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1|_BIT0), _PAGE1);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerBurstWrite(&tQC_DCC_SETTING1[9], 23, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_C7_DCC_CTRL0, 0x80);
    ScalerSetByte(P7_C8_DCC_CTRL1, 0x90);

	// RandomGen + DDither(_MSB)
	DebugMessageScaler("5. Mode_0", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x1E, 0x28, 0x1F, _D_DOMAIN_CRC) << 0));

	// RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
	ScalerQCHighlightWindowOn();
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2);
	ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
	ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x0B);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x27);
	DebugMessageScaler("5. Mode_1", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x1B, 0xAC, 0x64, _D_DOMAIN_CRC) << 1));

	// RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3);
	ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
	ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x03);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x01);
	DebugMessageScaler("5. Mode_2", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xAB, 0x6F, 0x28, _D_DOMAIN_CRC) << 2));

	// RandomGen + HLW(_IN/OUTSIDE_WINDOW) + DDither(_MSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0x00);
	ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
	ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x5E);
	DebugMessageScaler("5. Mode_3", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF6, 0x2D, 0xEE, _D_DOMAIN_CRC) << 3));
	
	ScalerQCHighlightWindowOff();
	ScalerQCIDomainRandomGenOff();

	ScalerQCDDomainPatternGenOn();
	ScalerQCDDitherOn(_LSB);

    // Fill DCC control table
    // Select page0
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_DCC_SETTING2, 9, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Fill DCC user curve table
    // Select page1
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1|_BIT0), _PAGE1);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerBurstWrite(&tQC_DCC_SETTING2[9], 23, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_C7_DCC_CTRL0, 0xE5);
    ScalerSetByte(P7_C8_DCC_CTRL1, 0xB0);

	// PatternGen + DDither(_LSB)
	DebugMessageScaler("5. Mode_4", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x8A, 0xD0, 0x6A, _D_DOMAIN_CRC) << 4));
	// PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
	ScalerQCHighlightWindowOn();
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2);
	ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
	ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x0B);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x27);
	DebugMessageScaler("5. Mode_5", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF1, 0x8C, 0xC8, _D_DOMAIN_CRC) << 5));
	// PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3);
	ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
	ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x03);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x01);
	DebugMessageScaler("5. Mode_6", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xE0, 0x4B, 0xA5, _D_DOMAIN_CRC) << 6));
	// PatternGen + HLW(_IN/OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0x00);
	ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
	ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
	ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x5E);
	DebugMessageScaler("5. Mode_7", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x91, 0x0A, 0xDB, _D_DOMAIN_CRC) << 7));

	ScalerSetBit(P7_C7_DCC_CTRL0, ~_BIT7, 0x00);			  	 // Disable DCC
	ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
	ScalerQCHighlightWindowOff();
	ScalerQCCheckCRCOff();   
	
	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. DCC End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. DCC End", 0x00);
	   return _TEST_FAIL;
	}	   
}

//--------------------------------------------------
// Description  : DCR Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCDCRTest(void)	 
{
	BYTE ucData = 0;
    BYTE pData[34] = {0};

	DebugMessageScaler("5. DCR Start", 0x00);
	ScalerQCIDomainRandomGenOn(_MASS);
 
	// Fill DCR table
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);                   
    ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x08);     
 
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x04);                   
    ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x90);     
 
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);                   
 // ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x20);
 
	// RandomGen
 	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. Mode_0", 0x00);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    

	if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x1A||pData[3]!=0xE5||pData[4]!=0x49||pData[5]!=0x28||pData[6]!=0x3E||
	   pData[7]!=0x98||pData[8]!=0x55||pData[9]!=0x01||pData[10]!=0x8A||pData[11]!=0xB9||pData[12]!=0x03||pData[13]!=0xC1||
	   pData[14]!=0x4C||pData[15]!=0x2C||pData[16]!=0xFF||pData[17]!=0xFF||pData[18]!=0xFF||pData[19]!=0xFF||pData[20]!=0xFF||
	   pData[21]!=0x00||pData[22]!=0xFF||pData[23]!=0xFF||pData[24]!=0xFF||pData[25]!=0xFF||pData[26]!=0xFF||pData[27]!=0x00||
	   pData[28]!=0xFF||pData[29]!=0xFF||pData[30]!=0xFF||pData[31]!=0xFF||pData[32]!=0xFF||pData[33]!=0x00)
	{
			ucData= ucData | _BIT0;
	    	DebugMessageScaler("5. ===Fail===",0x00);
	}
	else
	{
	    DebugMessageScaler("5. ===Pass===",0x00);
	}          

	// RandomGen + HLW(_IN/OUTSIDE_WINDOW)
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);
	ScalerQCHighlightWindowOn();
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), 0x00);
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. Mode_1", 0x00);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    

	if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x1A||pData[3]!=0xE5||pData[4]!=0x49||pData[5]!=0x28||pData[6]!=0x3E||
	   pData[7]!=0x98||pData[8]!=0x55||pData[9]!=0x01||pData[10]!=0x8A||pData[11]!=0xB9||pData[12]!=0x03||pData[13]!=0xC1||
	   pData[14]!=0x4C||pData[15]!=0x2C||pData[16]!=0xFF||pData[17]!=0xFF||pData[18]!=0xFF||pData[19]!=0xFF||pData[20]!=0xFF||
	   pData[21]!=0x00||pData[22]!=0xFF||pData[23]!=0xFF||pData[24]!=0xFF||pData[25]!=0xFF||pData[26]!=0xFF||pData[27]!=0x00||
	   pData[28]!=0xFF||pData[29]!=0xFF||pData[30]!=0xFF||pData[31]!=0xFF||pData[32]!=0xFF||pData[33]!=0x00)
	{
			ucData= ucData | _BIT1;
			DebugMessageScaler("5. ===Fail===",0x00);
	}
	else
	{
	    DebugMessageScaler("5. ===Pass===",0x00);
	}
	
	// RandomGen + HLW(_INSIDE_WINDOW)
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);
	DebugMessageScaler("5. Mode_2", 0x00);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), _BIT4);
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    
	if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x05||pData[3]!=0xB5||pData[4]!=0xE4||pData[5]!=0x08||pData[6]!=0x87||
	   pData[7]!=0x3E||pData[8]!=0xB8||pData[9]!=0x00||pData[10]!=0x52||pData[11]!=0xE8||pData[12]!=0x00||pData[13]!=0xC9||
	   pData[14]!=0xB8||pData[15]!=0x76||pData[16]!=0x51||pData[17]!=0xD4||pData[18]!=0x54||pData[19]!=0x03||pData[20]!=0xFF||
	   pData[21]!=0x00||pData[22]!=0x52||pData[23]!=0x64||pData[24]!=0x54||pData[25]!=0xB5||pData[26]!=0xFF||pData[27]!=0x00||
	   pData[28]!=0x52||pData[29]!=0x77||pData[30]!=0x54||pData[31]!=0x40||pData[32]!=0xFF||pData[33]!=0x00)
	{
			ucData= ucData | _BIT2;
			DebugMessageScaler("5. ===Fail===",0x00);
	}
	else
	{
	    DebugMessageScaler("5. ===Pass===",0x00);
	}

	// RandomGen + HLW(_OUTSIDE_WINDOW)
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);
	DebugMessageScaler("5. Mode_3", 0x00);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), _BIT5);
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    
	if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x15||pData[3]!=0x2F||pData[4]!=0x65||pData[5]!=0x1F||pData[6]!=0xB7||
	   pData[7]!=0x59||pData[8]!=0x9D||pData[9]!=0x01||pData[10]!=0x37||pData[11]!=0xD1||pData[12]!=0x02||pData[13]!=0xF7||
	   pData[14]!=0x93||pData[15]!=0xB6||pData[16]!=0xFF||pData[17]!=0xFF||pData[18]!=0xFF||pData[19]!=0xFF||pData[20]!=0xFF||
	   pData[21]!=0x00||pData[22]!=0xFF||pData[23]!=0xFF||pData[24]!=0xFF||pData[25]!=0xFF||pData[26]!=0xFF||pData[27]!=0x00||
	   pData[28]!=0xFF||pData[29]!=0xFF||pData[30]!=0xFF||pData[31]!=0xFF||pData[32]!=0xFF||pData[33]!=0x00)
	{
			ucData= ucData | _BIT3;
			DebugMessageScaler("5. ===Fail===",0x00);
	} 
	else
	{
	    DebugMessageScaler("5. ===Pass===",0x00);
	}        
 	
	ScalerQCHighlightWindowOff();
	ScalerQCIDomainRandomGenOff();
	
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);
	ScalerQCDDomainPatternGenOn();
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. Mode_4", 0x00);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    
	if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x1A||pData[3]!=0xEA||pData[4]!=0xA0||pData[5]!=0x28||pData[6]!=0x50||
	   pData[7]!=0x49||pData[8]!=0xE0||pData[9]!=0x01||pData[10]!=0xB6||pData[11]!=0xDE||pData[12]!=0x04||pData[13]!=0x02||
	   pData[14]!=0x2A||pData[15]!=0x8A||pData[16]!=0xFF||pData[17]!=0xFF||pData[18]!=0xFF||pData[19]!=0xFF||pData[20]!=0xFF||
	   pData[21]!=0x00||pData[22]!=0xFF||pData[23]!=0xFF||pData[24]!=0xFF||pData[25]!=0xFF||pData[26]!=0xFF||pData[27]!=0x00||
	   pData[28]!=0xFF||pData[29]!=0xFF||pData[30]!=0xFF||pData[31]!=0xFF||pData[32]!=0xFF||pData[33]!=0x00)
	{
			ucData= ucData | _BIT4;
			DebugMessageScaler("5. ===Fail===",0x00);
	}
	else
	{
	    DebugMessageScaler("5. ===Pass===",0x00);
	}

	// PatternGen + HLW(_IN/OUTSIDE_WINDOW)
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);
	ScalerQCHighlightWindowOn();
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), 0x00);
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. Mode_5", 0x00);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    
	if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x1A||pData[3]!=0xEA||pData[4]!=0xA0||pData[5]!=0x28||pData[6]!=0x50||
	   pData[7]!=0x49||pData[8]!=0xE0||pData[9]!=0x01||pData[10]!=0xB6||pData[11]!=0xDE||pData[12]!=0x04||pData[13]!=0x02||
	   pData[14]!=0x2A||pData[15]!=0x8A||pData[16]!=0xFF||pData[17]!=0xFF||pData[18]!=0xFF||pData[19]!=0xFF||pData[20]!=0xFF||
	   pData[21]!=0x00||pData[22]!=0xFF||pData[23]!=0xFF||pData[24]!=0xFF||pData[25]!=0xFF||pData[26]!=0xFF||pData[27]!=0x00||
	   pData[28]!=0xFF||pData[29]!=0xFF||pData[30]!=0xFF||pData[31]!=0xFF||pData[32]!=0xFF||pData[33]!=0x00)
	{
			ucData= ucData | _BIT5;
			DebugMessageScaler("5. ===Fail===",0x00);
	}
	else
	{
	    DebugMessageScaler("5. ===Pass===",0x00);
	}
	
	// PatternGen + HLW(_INSIDE_WINDOW)
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);
	DebugMessageScaler("5. Mode_6", 0x00);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), _BIT4);
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    
	if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x05||pData[3]!=0xB7||pData[4]!=0x10||pData[5]!=0x08||pData[6]!=0x81||
	   pData[7]!=0xAE||pData[8]!=0x24||pData[9]!=0x00||pData[10]!=0x58||pData[11]!=0x78||pData[12]!=0x00||pData[13]!=0xCE||
	   pData[14]!=0xB4||pData[15]!=0x10||pData[16]!=0x5F||pData[17]!=0x98||pData[18]!=0x5D||pData[19]!=0x2C||pData[20]!=0xFF||
	   pData[21]!=0x00||pData[22]!=0x53||pData[23]!=0xAC||pData[24]!=0x56||pData[25]!=0x10||pData[26]!=0xFF||pData[27]!=0x00||
	   pData[28]!=0x56||pData[29]!=0x10||pData[30]!=0x53||pData[31]!=0xAC||pData[32]!=0xFF||pData[33]!=0x00)
	{
			ucData= ucData | _BIT6;
			DebugMessageScaler("5. ===Fail===",0x00);
	}
	else
	{
	    DebugMessageScaler("5. ===Pass===",0x00);
	}
	
	// PatternGen + HLW(_OUTSIDE_WINDOW)
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);
	DebugMessageScaler("5. Mode_7", 0x00);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), _BIT5);
	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    
	if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x15||pData[3]!=0x33||pData[4]!=0x90||pData[5]!=0x1F||pData[6]!=0xCE||
	   pData[7]!=0x9B||pData[8]!=0xBC||pData[9]!=0x01||pData[10]!=0x5E||pData[11]!=0x66||pData[12]!=0x03||pData[13]!=0x33||
	   pData[14]!=0x76||pData[15]!=0x7A||pData[16]!=0xFF||pData[17]!=0xFF||pData[18]!=0xFF||pData[19]!=0xFF||pData[20]!=0xFF||
	   pData[21]!=0x00||pData[22]!=0xFF||pData[23]!=0xFF||pData[24]!=0xFF||pData[25]!=0xFF||pData[26]!=0xFF||pData[27]!=0x00||
	   pData[28]!=0xFF||pData[29]!=0xFF||pData[30]!=0xFF||pData[31]!=0xFF||pData[32]!=0xFF||pData[33]!=0x00)
	{
			ucData= ucData | _BIT7;
			DebugMessageScaler("5. ===Fail===",0x00);
	}
	else
	{
	    DebugMessageScaler("5. ===Pass===",0x00);
	}

	ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);			  	 // Disable DCR Messure
	ScalerQCDDomainPatternGenOff();
	ScalerQCHighlightWindowOff();

	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. DCR End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. DCR End", 0x00);
	   return _TEST_FAIL;
	}
}

//--------------------------------------------------
// Description  : ICM Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCICMTest(void)
{
	BYTE ucError = 0;
	
	DebugMessageScaler("5. ICM Start", 0x00);

	// Random + MSB
	ScalerQCIDomainRandomGenOn(_MASS);
	
	ScalerSetByte(P7_D1_ICM_SEL, 0x00);				// CM0
	ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
 	ScalerBurstWrite(tQC_ICM_Modify0, sizeof(tQC_ICM_Modify0), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

	ScalerSetByte(P7_D1_ICM_SEL, 0x01);				// CM1
	ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
 	ScalerBurstWrite(tQC_ICM_Modify1, sizeof(tQC_ICM_Modify1), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

	ScalerSetByte(P7_D1_ICM_SEL, 0x02);				// CM2
	ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
 	ScalerBurstWrite(tQC_ICM_Modify2, sizeof(tQC_ICM_Modify2), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

	ScalerSetByte(P7_D1_ICM_SEL, 0x03);				// CM3
	ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
 	ScalerBurstWrite(tQC_ICM_Modify3, sizeof(tQC_ICM_Modify3), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

	ScalerSetByte(P7_D1_ICM_SEL, 0x04);				// CM4
	ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
 	ScalerBurstWrite(tQC_ICM_Modify4, sizeof(tQC_ICM_Modify4), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

	ScalerSetByte(P7_D1_ICM_SEL, 0x05);				// CM5
	ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
 	ScalerBurstWrite(tQC_ICM_Modify5, sizeof(tQC_ICM_Modify5), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

	 //dy = (8dU+dV)/8,delta = -128~127
	ScalerSetByte(P7_D0_ICM_CTRL,  0x9f);          // Enable CM0~CM4
    ScalerSetBit(P7_D1_ICM_SEL, ~_BIT3, _BIT3);    //Enable CM5
   	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
   	DebugMessageScaler("5. ICM Case_0", ucError);
   	ucError = (BYTE)ScalerQCCheckCRCOn(0xA2, 0xFA, 0xFE, _D_DOMAIN_CRC); 	

	 //dy = (6dU+dV)/8,delta = -256~254, 
    ScalerSetByte(P7_D0_ICM_CTRL,  0xff); 
    ScalerSetBit(P7_D1_ICM_SEL, ~_BIT4, _BIT4);    //delta UV *4
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. ICM Case_1", ucError);
   	ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xFD, 0x8D, 0x2B, _D_DOMAIN_CRC)<<1);  	
  	  	
	// Random + Highlight Window + MSB  Full Window   
	ScalerQCHighlightWindowOn();
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 full window
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. ICM Case_2", ucError);
   	ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x36, 0x4E, 0x6B, _D_DOMAIN_CRC)<<2);   	
  	
	// Random + Highlight Window + MSB  Inside Window  
  	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. ICM Case_3", ucError);
	ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x16, 0x66, 0xAC, _D_DOMAIN_CRC)<<3);  	

	// Random + Highlight Window + MSB  Outside Window  
  	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3); // 10 outside window
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	DebugMessageScaler("5. ICM Case_4", ucError);
	ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xD6, 0x5E, 0xB7, _D_DOMAIN_CRC)<<4);   	
  	
	// D-domain PG + Highlight Window + LSB Outside Window
	ScalerQCIDomainRandomGenOff();
	ScalerQCDDomainPatternGenOn();
	ScalerQCDDitherOn(_LSB);
	ScalerTimerDelayXms(50);
	DebugMessageScaler("5. ICM Case_5", ucError);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
   	ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xAA, 0x59, 0xB2, _D_DOMAIN_CRC)<<5);   // remain 10 	

	// D-PG+HW+LSB  Inside Window
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
	DebugMessageScaler("5. ICM Case_6", ucError);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x25, 0xC7, 0x98, _D_DOMAIN_CRC)<<6);  	

  	// D-PG+HW+LSB  Full Window
  	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 Full window
	DebugMessageScaler("5. ICM Case_7", ucError);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x0F, 0x53, 0x9C, _D_DOMAIN_CRC)<<7); 

	// Disable ICM
	ScalerSetBit(P7_D1_ICM_SEL,  ~(_BIT3), 0x00); 
  	ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT4|_BIT3|_BIT2|_BIT1|_BIT0), 0x00);   
  	ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT7), 0x00);   
  	
	ScalerQCDDitherOff();
	ScalerQCHighlightWindowOff();
	ScalerQCDDomainPatternGenOff();
	ScalerQCCheckCRCOff();  	

	if(ucError == 0)
	{
		DebugMessageScaler("5. ICM End", 0x00);
		return _TEST_PASS;
		
	}
	else
	{
		DebugMessageScaler("5. Fail Mode", ucError);
	   	DebugMessageScaler("5. ICM End", 0x00);
	   	return _TEST_FAIL;	
	}	
}

//--------------------------------------------------
// Description  : Contrast & Brightness Test 
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCConBriTest(void)
{
	BYTE ucData = 0;

	DebugMessageScaler("5. Contrast/Brightness Start", 0x00);
	ScalerQCIDomainRandomGenOn(_MASS);
	ScalerQCDDitherOn(_MSB);

	ScalerSetBit(CM_64_CB_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
	ScalerBurstWrite(tQC_CON_BRI_SETTING, 12, GET_CURRENT_BANK_NUMBER(), CM_65_CB_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
	ScalerSetBit(CM_64_CB_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
	ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));			  // Enable Contrast & Brightness
	// RandomGen + DDither(_MSB)
	DebugMessageScaler("5. Mode_0", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x40, 0x76, 0x71, _D_DOMAIN_CRC) << 0));
	// RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
	ScalerQCHighlightWindowOn();
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT6);
	DebugMessageScaler("5. Mode_1", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x26, 0x76, 0xB4, _D_DOMAIN_CRC) << 1));
	// RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT7);
	DebugMessageScaler("5. Mode_2", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFE, 0x6C, 0x3C, _D_DOMAIN_CRC) << 2));
	// RandomGen + HLW(_IN/OUTSIDE_WINDOW) + DDither(_MSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
	DebugMessageScaler("5. Mode_3", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2E, 0x6C, 0xF8, _D_DOMAIN_CRC) << 3));
	
	ScalerQCHighlightWindowOff();
	ScalerQCIDomainRandomGenOff();

	ScalerQCDDomainPatternGenOn();
	ScalerQCDDitherOn(_LSB);
	// PatternGen + DDither(_LSB)
	DebugMessageScaler("5. Mode_4", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x7B, 0x38, 0x4D, _D_DOMAIN_CRC) << 4));
	// PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
	ScalerQCHighlightWindowOn();
	ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT6);
	DebugMessageScaler("5. Mode_5", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x9A, 0x47, 0xAD, _D_DOMAIN_CRC) << 5));
	// PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT7);
	DebugMessageScaler("5. Mode_6", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xAC, 0x21, 0x8B, _D_DOMAIN_CRC) << 6));
	// PatternGen + HLW(_IN/OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
	DebugMessageScaler("5. Mode_7", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xB6, 0xAB, 0x90, _D_DOMAIN_CRC) << 7));

	ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT1 | _BIT0), 0x00);			  	 // Disable Contrast & Brightness
	ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
	ScalerQCHighlightWindowOff();
	ScalerQCCheckCRCOff();   
	
	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. Contrast/Brightness End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. Contrast/Brightness End", 0x00);
	   return _TEST_FAIL;
	}	   
}

//--------------------------------------------------
// Description  : Output Gamma Test 
// Input Value  : Gamma table type and gamma tables
// Output Value : None
//--------------------------------------------------
bit ScalerQCGammaTest()
{
    BYTE ucData = 0;

    DebugMessageScaler("5. Output Gamma Start", 0x00);    
    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);

    ScalerSetByte(CM_67_GAMMA_CTRL, 0x80);
    ScalerBurstWrite(&tOutputGammaR[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x90);
    ScalerBurstWrite(&tOutputGammaG[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0xA0);
    ScalerBurstWrite(&tOutputGammaB[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, 0x00); // Disable Access Port
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, _BIT6); // Enable Output Gamma
    
    // RandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xA9, 0xB1, 0x05, _D_DOMAIN_CRC) << 0));

    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2F, 0x93, 0x65, _D_DOMAIN_CRC) << 1));
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x5B, 0x11, 0x88, _D_DOMAIN_CRC) << 2));
    // RandomGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x82, 0xF4, 0x9D, _D_DOMAIN_CRC) << 3));
    
    ScalerQCHighlightWindowOff();
    ScalerQCIDomainRandomGenOff();
    
    ScalerQCDDomainPatternGenOn();
    ScalerQCDDitherOn(_LSB);
    
    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x13, 0x16, 0xA1, _D_DOMAIN_CRC) << 4));
    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEA, 0x85, 0xD4, _D_DOMAIN_CRC) << 5));
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
	DebugMessageScaler("5. Mode_6", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x77, 0x16, 0x4D, _D_DOMAIN_CRC) << 6));
	// PatternGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
	DebugMessageScaler("5. Mode_7", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x1D, 0x5E, 0x2F, _D_DOMAIN_CRC) << 7));
	
	ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, 0x00); // Disable Output Gamma
	ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
	ScalerQCHighlightWindowOff();
	ScalerQCCheckCRCOff();

	if(ucData == 0x00)
	{
	    DebugMessageScaler("5. Output Gamma End", 0x00);
	    return _TEST_PASS;
	}
	else
	{
	    DebugMessageScaler("5. Fail Mode", ucData);
	    DebugMessageScaler("5. Output Gamma End", 0x00);
	    return _TEST_FAIL;
	}
}

//--------------------------------------------------
// Description  : sRGB Matrix Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCsRGBTest()
{
    BYTE ucData = 0;
    
    DebugMessageScaler("5. sRGB Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);
    
    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT6, 0x00);
    
    // RR, RG, RB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x08);  
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &tSRGBMatrix[0], _NON_AUTOINC);
    // R Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x20);
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, &tSRGBMatrix[6], _NON_AUTOINC);
    
    // GR, GG, GB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x10); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &tSRGBMatrix[8], _NON_AUTOINC);
    // G Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x28); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, &tSRGBMatrix[14], _NON_AUTOINC);
    
    // BR, BG, BB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x18); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &tSRGBMatrix[16], _NON_AUTOINC);
    // B Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x30); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, &tSRGBMatrix[22], _NON_AUTOINC);    

    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT6, 0x00); // Normal sRGB Precision           
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT7, _BIT7); // sRGB Matrix Ready to Write   
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x00); // Disable Access Port
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT2, _BIT2); // Enable sRGB
    
    // RandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x1F, 0x86, 0x23, _D_DOMAIN_CRC) << 0));
    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xAC, 0x06, 0x34, _D_DOMAIN_CRC) << 1));
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x29, 0xF2, 0x0A, _D_DOMAIN_CRC) << 2));
    // RandomGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x73, 0x82, 0x4E, _D_DOMAIN_CRC) << 3));
    
    ScalerQCHighlightWindowOff();
    ScalerQCIDomainRandomGenOff();
    
    ScalerQCDDomainPatternGenOn();
    ScalerQCDDitherOn(_LSB);
    
    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x9A, 0x30, 0x8C, _D_DOMAIN_CRC) << 4));
    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x6C, 0xE1, 0xE0, _D_DOMAIN_CRC) << 5));
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
	DebugMessageScaler("5. Mode_6", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x61, 0xEF, 0x91, _D_DOMAIN_CRC) << 6));
	// PatternGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
	DebugMessageScaler("5. Mode_7", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x8D, 0xC3, 0xC7, _D_DOMAIN_CRC) << 7));
	
	ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT2, 0x00); // Disable sRGB
	ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
	ScalerQCHighlightWindowOff();
	ScalerQCCheckCRCOff();
	
	if(ucData == 0x00)
	{
	    DebugMessageScaler("5. sRGB End", 0x00);
	    return _TEST_PASS;
	}
	else
	{
	    DebugMessageScaler("5. Fail Mode", ucData);
	    DebugMessageScaler("5. sRGB End", 0x00);
	    return _TEST_FAIL;
	}
}

bit ScalerQCPCMTest()
{
    BYTE ucData = 0;
    
    DebugMessageScaler("5. PCM Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);

    // Input Gamma Table
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT7, _BIT7);
    ScalerBurstWrite(tInputGamma, 99, GET_CURRENT_BANK_NUMBER(), P9_A0_INPUT_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerWrite(P9_A2_INPUT_GAMMA_LOW_THRE, 1, &tInputGamma[99], _NON_AUTOINC);
    ScalerWrite(P9_A3_INPUT_GAMMA_HIGH_THRE, 1, &tInputGamma[100], _NON_AUTOINC);
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT7, 0x00);
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT6, _BIT6); // Enable Input Gamma
	
    // sRGB Matrix
    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT6, _BIT6);
    
    // RR, RG, RB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x08);  
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &tSRGBMatrix[0], _NON_AUTOINC);
    // R Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x20);
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, &tSRGBMatrix[6], _NON_AUTOINC);
    
    // GR, GG, GB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x10); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &tSRGBMatrix[8], _NON_AUTOINC);
    // G Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x28); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, &tSRGBMatrix[14], _NON_AUTOINC);
    
    // BR, BG, BB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x18); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &tSRGBMatrix[16], _NON_AUTOINC);
    // B Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x30); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, &tSRGBMatrix[22], _NON_AUTOINC);

    ScalerSetByte(CM_68_GAMMA_BIST, 0x00);
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT6, 0x00); // Normal sRGB Precision             
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT7, _BIT7); // sRGB Matrix Ready to Write   
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x00); // Disable Access Port
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT2, _BIT2); // Enable sRGB
    
    // Output Gamma Table   
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x84);
    ScalerBurstWrite(tOutputGammaR, 24, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x80);
    ScalerBurstWrite(&tOutputGammaR[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x94);
    ScalerBurstWrite(tOutputGammaG, 24, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x90);
    ScalerBurstWrite(&tOutputGammaG[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0xA4);
    ScalerBurstWrite(tOutputGammaB, 24, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetByte(CM_67_GAMMA_CTRL, 0xA0);
    ScalerBurstWrite(&tOutputGammaB[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, 0x00); // Disable Access Port
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, _BIT6); // Enable Output Gamma
    
    // RandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x08, 0xBD, 0x47, _D_DOMAIN_CRC) << 0));

    ScalerQCIDomainRandomGenOff();
        
    ScalerQCDDomainPatternGenOn();
    ScalerQCDDitherOn(_LSB);
    
    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x6C, 0x99, 0x6B, _D_DOMAIN_CRC) << 1));
    
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT6, 0x00); // Disable Input Gamma
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT2, 0x00); // Disable sRGB
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, 0x00); // Disable Output Gamma
	ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
	ScalerQCCheckCRCOff();
	
	if(ucData == 0x00)
	{
	    DebugMessageScaler("5. PCM End", 0x00);
	    return _TEST_PASS;
	}
	else
	{
	    DebugMessageScaler("5. Fail Mode", ucData);
	    DebugMessageScaler("5. PCM End", 0x00);
	    return _TEST_FAIL;
	}
}

//--------------------------------------------------
// Description  : D Domain Dither Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCDDitherTest(void)
{
	BYTE ucData = 0;
	
	DebugMessageScaler("5. D Dither Start", 0x00);

	ScalerQCDDomainPatternGenOn();

	// 8 bit test
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_D_DOMAIN_DITHER_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_D_DOMAIN_DITHER_SEQ_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

#if(_D_DITHER_TEMP == _ENABLE)
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_DITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
#endif

    //MSB
	ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7), 0x00);
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT5 | (_D_DITHER_TEMP << 4));
	
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x8F, 0x83, 0xC2, _D_DOMAIN_CRC) << 0));

    // LSB
	ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7), _BIT7);
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT5 | (_D_DITHER_TEMP << 4));
	
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFD, 0x65, 0x6A, _D_DOMAIN_CRC) << 1));

	ScalerQCDDitherOff();

    // 6 bit test
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_D_DOMAIN_DITHER_10_6_TABLE, 24, GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    //MSB
	ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7), 0x00);
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT5 | (_D_DITHER_TEMP << 4));
	
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x91, 0xE1, 0x10, _D_DOMAIN_CRC) << 2));

    // LSB
	ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7), _BIT7);
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT5 | (_D_DITHER_TEMP << 4));
	
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xC6, 0xA8, 0x81, _D_DOMAIN_CRC) << 3));

	ScalerQCDDitherOff();
	ScalerQCDDomainPatternGenOff();
	ScalerQCCheckCRCOff();   

	if(ucData == 0x00)
	{
	   DebugMessageScaler("5. D Dither End", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", ucData);
	   DebugMessageScaler("5. D Dither End", 0x00);
	   return _TEST_FAIL;
	}
}

//--------------------------------------------------
// Description  : OD Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCLiveshowTest(void)
{
	BYTE ucData = 0;
	
    DebugMessageScaler("5. Liveshow Start", 0x00);		

    ScalerQCIDomainRandomGenOn(_MASS);

    // Load od table
    ScalerSetBit(P3_AE_LS_LUT_ROW_ADDR, ~_BIT7, _BIT7);
    ScalerSetBit(P3_AF_LS_LUT_COL_ADDR, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerSetBit(P3_AE_LS_LUT_ROW_ADDR, 0xc0, 0x00);
    ScalerSetBit(P3_AF_LS_LUT_COL_ADDR, 0xc0, 0x00);
    ScalerWrite(P3_B0_LS_LUT_DATA, 288, tOD_TABLE[0], _NON_AUTOINC);   
    ScalerSetBit(P3_AE_LS_LUT_ROW_ADDR, ~_BIT7, 0x00);

    // Delta gain
    ScalerSetByte(P3_B1_LS_DELTA_GAIN, 0x30);			// Delta Gain

#if((_SDRAM_SIZE_CONFIG == _1M_32BIT) || (_SDRAM_SIZE_CONFIG == _2M_32BIT)) 

    ScalerBurstWrite(tQC_OD_Token1, sizeof(tQC_OD_Token1), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
					
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, _BIT4);		// Reset SDRAM
    ScalerTimerDelayXms(5);
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, 0x00);

    // 1Mx32 SDRAM
	ScalerSetByte(P10_C0_PIN_SHARE_SDRAM_CTRL0, 0x05);

    // Enable OD and delta gain
	ScalerSetByte(P3_A1_LS_CTRL0, _BIT7 | _BIT6 | _BIT3);				// No Compress & 8bit
	ScalerSetByte(P3_A2_LS_CTRL1, _BIT7 | _BIT6);

    ScalerBurstWrite(tQC_OD_FIFO2, sizeof(tQC_OD_FIFO2), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerBurstWrite(tQC_OD_YUV, sizeof(tQC_OD_YUV), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P3_A4_LS_CPRS_CTRL, ~_BIT4, _BIT4);  // OD-YUV path

	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerTimerWaitForEvent(_EVENT_DVS); 
    
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x62,0xA4,0xFC, _D_DOMAIN_CRC) << 0));

    ScalerSetByte(P3_A1_LS_CTRL0, 0x00);
    ScalerQCIDomainRandomGenOff();
	ScalerQCCheckCRCOff(); 
	
	if(ucData == 0x00)
	{
        DebugMessageScaler("5. Liveshow End", 0x00);	
	    return _TEST_PASS;
	}
	else
	{
	    DebugMessageScaler("5. Fail Mode", ucData);
        DebugMessageScaler("5. Liveshow End", 0x00);	
	    return _TEST_FAIL;
	}	
	

#elif(_SDRAM_SIZE_CONFIG == _1M_16BIT)

#endif
}

bit ScalerQCScaleDownTest(void)
{
    BYTE ucData = 0;
    DebugMessageScaler("5. Scale down Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);
    
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x0d,0x3C,0xCF, _D_DOMAIN_CRC) << 0));

    ScalerQCIDomainRandomGenOff();
	ScalerQCCheckCRCOff(); 
	
	if(ucData == 0x00)
	{
        DebugMessageScaler("5. Scale down End", 0x00);	
	    return _TEST_PASS;
	}
	else
	{
	    DebugMessageScaler("5. Fail Mode", ucData);
        DebugMessageScaler("5. Scale down End", 0x00);	
	    return _TEST_FAIL;
	}	        
}

void ScalerOsdFxPutProporString(BYTE *pArray, WORD usFontPointer, BYTE ucLength)
{
    BYTE ucAccBitCnt = 0;
    BYTE ucFontCnt = 0;
    BYTE ucLoadBitCnt = 0;
    BYTE ucTemp[27];
    BYTE pData[3] = {0};
    BYTE ucBitTemp = 0;
    BYTE ucCnt = 0;

    MCU_TRIPLE_BYTES_OP_FF03 |= _BIT7; // global nibble reorder enable
    //MCU_TRIPLE_BYTES_OP_FF03 |= _BIT6 | _BIT5;

    while(ucFontCnt < ucLength)
    {     
        ucLoadBitCnt = tOSD_FONT_WIDTH[ucFontCnt];
        if(ucAccBitCnt == 0)
        {
            ucAccBitCnt = ucLoadBitCnt;
        }

        MCU_TRIPLE_BYTES_OP_FF03 |= _BIT3; // first bits shift direction: left shift
        MCU_TRIPLE_BYTES_OP_FF03 &= ~_BIT2;// left bits shift direction: rigth shift 
        MCU_SHIFT_BITS_NUM_FF04 = ((ucLoadBitCnt - ucAccBitCnt) << 4) | ucAccBitCnt; // first bits shift and second bits shift
        ucAccBitCnt += tOSD_FONT_WIDTH[ucFontCnt + 1];
    
        for(pData[0] = 0; pData[0] < 9; pData[0]++)
        {
            MCU_TRIPLE_BYTES_OP_FF03 |= _BIT0; // restart from last three bytes

            //MCU_BYTE_ADDR_FF18 = 0x05; // OSDOSDresult triple bytes, byte1-byte2-byte0 ----> 0k
			//MCU_BYTE_ADDR_FF18 = 0x06; // OSDOSDresult triple bytes, byte2-byte1-byte0 ----> 0k
			//MCU_BYTE_ADDR_FF18 = 0x01; // input triple bytes, byte1-byte2-byte0 ----> 0k
			//MCU_BYTE_ADDR_FF18 = 0x02; // input triple bytes, byte2-byte1-byte0 ----> 0k
			//MCU_BYTE_ADDR_FF18 = 0x01; // input and OSDOSDresult triple bytes address 0---->0k
            
            MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + ucFontCnt*27 + i*3);
            MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + ucFontCnt*27 + i*3 + 1);
            MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + ucFontCnt*27 + i*3 + 2);

            if(ucFontCnt < ucLength - 1)
            {
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + 1)*27 + i*3);
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + 1)*27 + i*3 + 1);
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + 1)*27 + i*3 + 2);  
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
            
                ucBitTemp += tOSD_FONT_WIDTH[ucFontCnt + ucCnt];
                
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + ucCnt)*27 + i*3);
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + ucCnt)*27 + i*3 + 1);
                MCU_INPUT_TRIPLE_BYTES_FF06 =  *(pArray + (ucFontCnt + ucCnt)*27 + i*3 + 2); 
                ucCnt++;
            }		

            ucTemp[pData[0] * 3] = MCU_RESULT_TRIPLE_BYTES_FF07;
            ucTemp[pData[0] * 3 + 1] = MCU_RESULT_TRIPLE_BYTES_FF07;
            ucTemp[pData[0] * 3 + 2] = MCU_RESULT_TRIPLE_BYTES_FF07;
            
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
        
       ScalerSetByte(0x90, (HIBYTE(usFontPointer) & 0x000f) | 0xd0);
       ScalerSetByte(0x91, LOBYTE(usFontPointer));
        // write to sram
        for(pData[0] = 0; pData[0] < 9; pData[0]++)
        {
            pData[0] = ((ucTemp[pData[0] * 3 + 1] & 0x0f) << 4) | (ucTemp[pData[0] * 3 + 2] & 0x0f);
            pData[1] = (ucTemp[pData[0] * 3 + 2] & 0xf0) | (ucTemp[pData[0] * 3] & 0x0f);
            pData[2] = (ucTemp[pData[0] * 3] & 0xf0)| ((ucTemp[pData[0] * 3 + 1] & 0xf0) >> 4);
            ucTemp[pData[0] * 3] = pData[0];
            ucTemp[pData[0] * 3 + 1] = pData[1];
            ucTemp[pData[0] * 3 + 2] = pData[2];
        }
        ScalerWrite(0x92, 27, ucTemp, _NON_AUTOINC);
        usFontPointer += 9;
    }  
}

void CScalerCodeW(BYTE code *pArray)
{
    BYTE ucLength = 0;

    do
    {
        if((*pArray & 0xfc) == 0)
        {
            return;
        }

        ucLength = *pArray - 3;

        if((*(pArray + 1)) == _BURST)
        {
            MCU_SCA_INF_CTRL_FFF3 |= 0x20;

            MCU_SCA_INF_ADDR_FFF4 = *(pArray + 2);

            pArray += 3;

            do
            {
                MCU_SCA_INF_DATA_FFF5 = *pArray;
            }
            while(--ucLength);

            pArray++;
        }
        else if((*(pArray + 1) == _AUTOINC) || (*(pArray + 1) == _NON_AUTOINC))
        {
            if(*(pArray + 1) == _NON_AUTOINC)
            {
                MCU_SCA_INF_CTRL_FFF3 |= 0x20;
            }
            else
            {
                MCU_SCA_INF_CTRL_FFF3 &= 0xDF;
            }

            MCU_SCA_INF_ADDR_FFF4 = *(pArray + 2);

            pArray += 3;

            do
            {
                MCU_SCA_INF_DATA_FFF5 = *pArray++;
            }
            while(--ucLength);
        }

    }
    while(_TRUE);
}

bit OsdTest(void)
{
	int i,j,k;
	BYTE ucData = 0;
    BYTE pData[4] = {0};

    
	ScalerSetByte(0x60,0x00);
	ScalerSetByte(0x62,0x00);
	ScalerSetByte(0x67,0x00);
	ScalerSetByte(0x6A,0x00);
	
	
//For Color Palette Double Buffer//
	ScalerSetByte(0x90,0x80);
	ScalerSetByte(0x91,0x00);
	ScalerSetByte(0x92,0x01);  //OSD Must be Activated

	pData[0]=0;

	for(i=0;i<256;i+=85)
    {
		for(j=0;j<256;j+=85)
		{
			for(k=0;k<256;k+=85)
			{
				while(1)
				{
					ScalerTimerDelayXms(20);   // Delay for 15ms
    				if(!(bit)ScalerGetBit(0x6E,_BIT6)) // Check Double Buffer Has Been Clear
						break;				
				}								
				ScalerSetByte(0x6E, (0xc0 | pData[0])),  // LUT must be double buffer	   
				pData[0]+=1;
				pData[1]=i;
				pData[2]=j;
				pData[3]=k;
    			ScalerWrite(0x6F, 3, &pData[1], _NON_AUTOINC);											
			}
		}
	}
	
    ScalerSetByte(0x6E, 0x00);

    //ScalerBurstWrite(tQC_OSD_TEST_FRAME7, sizeof(tQC_OSD_TEST_FRAME7), GET_CURRENT_BANK_NUMBER(), 0x00, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    CScalerCodeW(tQC_OSD_TEST_FRAME7);
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xA6,0xF0,0x47, _D_DOMAIN_CRC) << 4));
 
    ScalerTimerDelayXms(_FRAME_DELAY_TIME);

    ScalerOsdFxPutProporString(tQC_OSD_FONT_DATA, 0x403 + 0x21C, 7);
    //ScalerBurstWrite(tQC_OSD_TEST_FRAME0, sizeof(tQC_OSD_TEST_FRAME0), GET_CURRENT_BANK_NUMBER(), 0x00, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    CScalerCodeW(tQC_OSD_TEST_FRAME0);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x50,0xaE,0x77, _D_DOMAIN_CRC) << 0));

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);

    //ScalerBurstWrite(tQC_OSD_TEST_FRAME1, sizeof(tQC_OSD_TEST_FRAME1), GET_CURRENT_BANK_NUMBER(), 0x00, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    CScalerCodeW(tQC_OSD_TEST_FRAME1);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x78,0x8D,0xA5, _D_DOMAIN_CRC) << 1));

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);
    
    //ScalerBurstWrite(tQC_OSD_TEST_FRAME2, sizeof(tQC_OSD_TEST_FRAME2), GET_CURRENT_BANK_NUMBER(), 0x00, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    CScalerCodeW(tQC_OSD_TEST_FRAME2);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF4,0x0F,0x7B, _D_DOMAIN_CRC) << 2));

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);

    //ScalerBurstWrite(tQC_OSD_TEST_FRAME3, sizeof(tQC_OSD_TEST_FRAME3), GET_CURRENT_BANK_NUMBER(), 0x00, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    CScalerCodeW(tQC_OSD_TEST_FRAME3);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x60,0xFD,0xE0, _D_DOMAIN_CRC) << 3));

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);

    //ScalerBurstWrite(tQC_OSD_TEST_FRAME5, sizeof(tQC_OSD_TEST_FRAME5), GET_CURRENT_BANK_NUMBER(), 0x00, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    CScalerCodeW(tQC_OSD_TEST_FRAME5);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x28,0x9E,0xD0, _D_DOMAIN_CRC) << 5));

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);
    
    for(i = 0; i < 65; i++)    // Wait 64 frame
    {
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }

    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x9F,0xE7,0x03, _D_DOMAIN_CRC) << 6));

    ScalerTimerDelayXms(_FRAME_DELAY_TIME);
   
//////////Rotation Start//////////       
    //ScalerBurstWrite(tQC_OSD_TEST_FRAME6, sizeof(tQC_OSD_TEST_FRAME6), GET_CURRENT_BANK_NUMBER(), 0x00, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    CScalerCodeW(tQC_OSD_TEST_FRAME6);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x91,0x6D,0x1D, _D_DOMAIN_CRC) << 7));

	ScalerSetByte(0x90,0x80);
	ScalerSetByte(0x91,0x00);
	ScalerSetByte(0x92,0x00);  //OSD disable
 	ScalerQCCheckCRCOff();
 	
	if(ucData == 0x00)
	{
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("5. Fail Mode", 0x00);
	   return _TEST_FAIL;
	}  
}
 extern void SysModeSetFreeRun(void);

//--------------------------------------------------
// QC Process
//--------------------------------------------------
bit ScalerQCOSDTest(void)
{
    bit result = 0;
    
    DebugMessageScaler("5. OSD Start", 0x00);
#if 0
    ScalerGlobalWatchDog(_DISABLE);
    SysModeSetFreeRun();
        ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT5, 0x00);    
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT5, _BIT5);

    ScalerSetByte(CM_6D_BGND_COLOR_CTRL, 0);
    ScalerSetByte(CM_6D_BGND_COLOR_CTRL, 0);
    ScalerSetByte(CM_6D_BGND_COLOR_CTRL, 0);    

    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT5, 0x00);   
    ScalerSetBit(CM_28_VDISP_CTRL, ~(_BIT5 | _BIT3 | _BIT1 | _BIT0), (_BIT5 | _BIT1 | _BIT0));

#else
	ScalerSetByte(P7_F0_DISP_PG_R_CTRL, 0x00);
	ScalerSetByte(P7_F1_DISP_PG_G_CTRL, 0x00);
	ScalerSetByte(P7_F2_DISP_PG_B_CTRL, 0x00);
	ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, 0x00);
	ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, 0x00);
	ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, 0x00);
	ScalerSetByte(P7_F6_DISP_PG_PIXEL_DELTA, 0x00);
	ScalerSetByte(P7_F7_DISP_PG_LINE_DELTA, 0x00);
	ScalerSetByte(P7_F8_DISP_PG_PIXEL_STEP_MSB, 0x00);
	ScalerSetByte(P7_F9_DISP_PG_LINE_STEP_MSB, 0x00);
	ScalerSetByte(P7_FA_DISP_PG_STEP_LSB, 0x00);

	ScalerSetBit(P7_F0_DISP_PG_R_CTRL, ~_BIT7, _BIT7);    
#endif    
   
    result = OsdTest();

    ScalerQCDDomainPatternGenOff();
    
    DebugMessageScaler("5. OSD End", 0x00);
	
    return result;
}

//----------------------------------------------------------------------------
// HDMI QC Test
//----------------------------------------------------------------------------
#if(_HDMI_SUPPORT == _ON)

//******************************************//
// HDMI Test condition--                    //
//         Timing : 1920x1080@60            //
//         Color Depth : 12 bit RGB         //
//         Pattern : Gamma Ramp wr=2.5      //
//         Source : VG-870                  //
//******************************************//

//--------------------------------------------------
// Description  : Hdmi Test
// Input Value  : None
// Output Value : TEST_PASS/FAIL
//--------------------------------------------------
bit ScalerQCHdmiTest(void)
{
    BYTE pucTemp[6] = {0};        
    
    // Read HDMI CRC Value
    ScalerSetBit(P2_A4_TMDS_CTRL, _BIT0, _BIT0);
    
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);    

    pucTemp[0] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pucTemp[1] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pucTemp[2] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pucTemp[3] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pucTemp[4] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pucTemp[5] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);    

    ScalerSetBit(P2_A4_TMDS_CTRL, _BIT0, 0x00);
    
    if((pucTemp[0] == _HDMI_CRC0) && (pucTemp[1] == _HDMI_CRC1) && (pucTemp[2] == _HDMI_CRC2) &&
       (pucTemp[3] == _HDMI_CRC3) && (pucTemp[4] == _HDMI_CRC4) && (pucTemp[5] == _HDMI_CRC5))
    {
        return _TEST_PASS;
    }

    return _TEST_FAIL;
}
#endif

#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)