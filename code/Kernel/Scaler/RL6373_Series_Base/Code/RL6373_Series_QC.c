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
// ID Code      : RL6373_Series_QC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6373_SERIES_QC__

#include "ScalerFunctionInclude.h"

#if(_FACTORY_RTD_QC_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _TEST_PASS                                      0
#define _TEST_FAIL                                      1

//----------------------------------------------------------------------------
// BIST QC Test
//----------------------------------------------------------------------------
#define _BIST_TIMEOUT                                   60

#define _GRAY                                           0
#define _MASS                                           1

#define _MSB                                            0
#define _LSB                                            1


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Code Tables of I-Dither 10 -> 8
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_TABLE[] =
{
    // 10 --> 8
    0x01, 0x32, 0x12, 0x03, 0x23, 0x10, 0x30, 0x21,
    0x23, 0x10, 0x30, 0x21, 0x01, 0x32, 0x12, 0x03,
    0x30, 0x21, 0x01, 0x32, 0x12, 0x03, 0x23, 0x10,
};

//--------------------------------------------------
// Code Tables of I-Dither Sequence
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_SEQ_TABLE[] =
{
    0xE4, 0xA2, 0x05, 0x37, 0xF6, 0x31, 0x69, 0xCB, 0x1F, 0xD2, 0xB0, 0xE6,
    0x45, 0x1B, 0x87, 0xC6, 0x9E, 0xB4, 0xC6, 0x38, 0xD4, 0xDB, 0x12, 0x1B,
};

//--------------------------------------------------
// Code Tables of I-Dither Offset
//--------------------------------------------------
BYTE code tQC_IDITHER_TEMOFFSET[] = 
{
    0xFF, 0xFF, 0xFF, 0xFF,
};

//--------------------------------------------------
// Code Tables of D-Dither 10 -> 8
//--------------------------------------------------
BYTE code tQC_D_DOMAIN_DITHER_TABLE[] =
{
    // 10 --> 8
    0x01, 0x32, 0x12, 0x03, 0x23, 0x10, 0x30, 0x21,
    0x23, 0x10, 0x30, 0x21, 0x01, 0x32, 0x12, 0x03,
    0x30, 0x21, 0x01, 0x32, 0x12, 0x03, 0x23, 0x10,
};

//--------------------------------------------------
// Code Tables of D-Dither 10 -> 6
//--------------------------------------------------
BYTE code tQC_D_DOMAIN_DITHER_10_6_TABLE[] = 
{
    // 10 --> 6
    0x07, 0xF8, 0x69, 0x1E, 0xAD, 0x52, 0xC3, 0xB4,
    0xAD, 0x52, 0xC3, 0xB4, 0x07, 0xF8, 0x69, 0x1E,
    0xAD, 0x52, 0x69, 0x1E, 0xC3, 0xB4, 0x07, 0xF8,
};

//--------------------------------------------------
// Code Tables of D-Dither Sequence
//--------------------------------------------------
BYTE code tQC_D_DOMAIN_DITHER_SEQ_TABLE[] =
{
    0xE4, 0xA2, 0x05, 0x37, 0xF6, 0x31, 0x69, 0xCB, 0x1F, 0xD2, 0xB0, 0xE6,
    0x45, 0x1B, 0x87, 0xC6, 0x9E, 0xB4, 0xC6, 0x38, 0xD4, 0xDB, 0x12, 0x1B,

    0x63, 0x27, 0x93, 0x1E, 0x36, 0x2D, 0xD8, 0x4E, 0x36, 0x2D, 0xD2, 0x39,
    0x1E, 0x8D, 0x39, 0x87, 0x36, 0xB1, 0x9C, 0xD2, 0x87, 0x27, 0x1B, 0xD8,   
    
    0xE1, 0xF7, 0xE6, 0xB7, 0x27, 0xB9, 0x8C, 0x8E, 0xD2, 0xEB, 0x3C, 0xA6,
    0x30, 0x56, 0xAD, 0xC6, 0x61, 0xFB, 0xCB, 0x39, 0x6C, 0x5D, 0x03, 0x02,
    
    0xD2, 0xD8, 0x93, 0xB4, 0x2D, 0x39, 0x9C, 0x2D, 0xC9, 0x4B, 0xD2, 0x87,
    0x27, 0xE1, 0xC6, 0x93, 0x2D, 0x9C, 0xD8, 0xC6, 0x1B, 0x36, 0x93, 0x1E,    
};

//--------------------------------------------------
// Code Tables of D-Dither Offset
//--------------------------------------------------
BYTE code tQC_DITHER_TEMOFFSET[] = 
{
    0xE4, 0xE4, 0xE4, 0xE4,
};

//--------------------------------------------------
// Code Tables of D-Dither THD
//--------------------------------------------------
BYTE code tQC_DITHER_THD[] = 
{
    0x00, 0x15, 0x01, 0x35, 0x01, 0x12,
};


BYTE code tQC_DITHER_NEWFUNC1_MSB_CRC_TABLE[] =
{
    0x56, 0x21, 0x66,
    0x64, 0x97, 0x2b,
    0xd9, 0xe0, 0x03,
    0xed, 0xea, 0x85,
    0x56, 0x21, 0x66,
    0x64, 0x97, 0x2b,
    0xd9, 0xe0, 0x03,
    0xed, 0xea, 0x85,
    0x56, 0x21, 0x66,
    0x64, 0x97, 0x2b,
    0xd9, 0xe0, 0x03,
    0xed, 0xea, 0x85,
    0x56, 0x21, 0x66,
    0x64, 0x97, 0x2b,
    0xd9, 0xe0, 0x03,
    0xed, 0xea, 0x85,
    0x56, 0x21, 0x66,
    0x64, 0x97, 0x2b,
    0xd9, 0xe0, 0x03,
    0xed, 0xea, 0x85,
    0x56, 0x21, 0x66,
    0x64, 0x97, 0x2b,
    0xd9, 0xe0, 0x03,
    0xed, 0xea, 0x85,
};

BYTE code tQC_DITHER_NEWFUNC1_LSB_CRC_TABLE[] =
{
    0x8e, 0xac, 0x01,
    0xe4, 0x4b, 0xd6,
    0xdc, 0xf9, 0xcb,
    0xe4, 0xa7, 0xfd,
    0x8e, 0xac, 0x01,
    0xe4, 0x4b, 0xd6,
    0xdc, 0xf9, 0xcb,
    0xe4, 0xa7, 0xfd,
    0x8e, 0xac, 0x01,
    0xe4, 0x4b, 0xd6,
    0xdc, 0xf9, 0xcb,
    0xe4, 0xa7, 0xfd,
    0x8e, 0xac, 0x01,
    0xe4, 0x4b, 0xd6,
    0xdc, 0xf9, 0xcb,
    0xe4, 0xa7, 0xfd,
    0x8e, 0xac, 0x01,
    0xe4, 0x4b, 0xd6,
    0xdc, 0xf9, 0xcb,
    0xe4, 0xa7, 0xfd,
    0x8e, 0xac, 0x01,
    0xe4, 0x4b, 0xd6,
    0xdc, 0xf9, 0xcb,
    0xe4, 0xa7, 0xfd,
};

BYTE code tQC_DITHER_NEWFUNC2_MSB_CRC_TABLE[] =
{
    0x92, 0x82, 0xfd,
    0x92, 0x82, 0xfd,
    0x92, 0x82, 0xfd,
    0x92, 0x82, 0xfd,
    0xdd, 0x9f, 0x15,
    0xdd, 0x9f, 0x15,
    0xdd, 0x9f, 0x15,
    0xdd, 0x9f, 0x15,
    0x69, 0x04, 0xe5,
    0x69, 0x04, 0xe5,
    0x69, 0x04, 0xe5,
    0x69, 0x04, 0xe5,
    0xa6, 0xde, 0x00,
    0xa6, 0xde, 0x00,
    0xa6, 0xde, 0x00,
    0xa6, 0xde, 0x00,
    0x2a, 0x5e, 0x34,
    0x2a, 0x5e, 0x34,
    0x2a, 0x5e, 0x34,
    0x2a, 0x5e, 0x34,
    0xc7, 0xaa, 0x8d,
    0xc7, 0xaa, 0x8d,
    0xc7, 0xaa, 0x8d,
    0xc7, 0xaa, 0x8d,
    0xbe, 0xf1, 0x4c,
    0xbe, 0xf1, 0x4c,
    0xbe, 0xf1, 0x4c,
    0xbe, 0xf1, 0x4c,
    0xcd, 0x40, 0x8e,
    0xcd, 0x40, 0x8e,
    0xcd, 0x40, 0x8e,
    0xcd, 0x40, 0x8e,
    0x23, 0x9d, 0x41,
    0x23, 0x9d, 0x41,
    0x23, 0x9d, 0x41,
    0x23, 0x9d, 0x41,
    0xac, 0x1f, 0x6b,
    0xac, 0x1f, 0x6b,
    0xac, 0x1f, 0x6b,
    0xac, 0x1f, 0x6b,
    0x1b, 0xba, 0x71,
    0x1b, 0xba, 0x71,
    0x1b, 0xba, 0x71,
    0x1b, 0xba, 0x71,
    0xed, 0x23, 0xa7,
    0xed, 0x23, 0xa7,
    0xed, 0x23, 0xa7,
    0xed, 0x23, 0xa7,
    0x66, 0x86, 0x44,
    0x66, 0x86, 0x44,
    0x66, 0x86, 0x44,
    0x66, 0x86, 0x44,
    0x14, 0x73, 0xb6,
    0x14, 0x73, 0xb6,
    0x14, 0x73, 0xb6,
    0x14, 0x73, 0xb6,
    0xf5, 0x76, 0xc6,
    0xf5, 0x76, 0xc6,
    0xf5, 0x76, 0xc6,
    0xf5, 0x76, 0xc6,
    0x91, 0x98, 0x85,
    0x91, 0x98, 0x85,
    0x91, 0x98, 0x85,
    0x91, 0x98, 0x85,
    0x6a, 0x2a, 0x82,
    0x6a, 0x2a, 0x82,
    0x6a, 0x2a, 0x82,
    0x6a, 0x2a, 0x82,
    0xb3, 0x9d, 0x57,
    0xb3, 0x9d, 0x57,
    0xb3, 0x9d, 0x57,
    0xb3, 0x9d, 0x57,
    0x42, 0xa1, 0x34,
    0x42, 0xa1, 0x34,
    0x42, 0xa1, 0x34,
    0x42, 0xa1, 0x34,
    0x05, 0x7c, 0x64,
    0x05, 0x7c, 0x64,
    0x05, 0x7c, 0x64,
    0x05, 0x7c, 0x64,
    0x91, 0x85, 0xdd,
    0x91, 0x85, 0xdd,
    0x91, 0x85, 0xdd,
    0x91, 0x85, 0xdd,
    0x3c, 0x49, 0x5a,
    0x3c, 0x49, 0x5a,
    0x3c, 0x49, 0x5a,
    0x3c, 0x49, 0x5a,
    0xde, 0xdc, 0x87,
    0xde, 0xdc, 0x87,
    0xde, 0xdc, 0x87,
    0xde, 0xdc, 0x87,
    0x4a, 0x2e, 0x18,
    0x4a, 0x2e, 0x18,
    0x4a, 0x2e, 0x18,
    0x4a, 0x2e, 0x18,
};

BYTE code tQC_DITHER_NEWFUNC2_LSB_CRC_TABLE[] =
{
    0xa2, 0xdc, 0x83,
    0xa2, 0xdc, 0x83,
    0xa2, 0xdc, 0x83,
    0xa2, 0xdc, 0x83,
    0xa1, 0x3a, 0xbd,
    0xa1, 0x3a, 0xbd,
    0xa1, 0x3a, 0xbd,
    0xa1, 0x3a, 0xbd,
    0xbd, 0x43, 0x6f,
    0xbd, 0x43, 0x6f,
    0xbd, 0x43, 0x6f,
    0xbd, 0x43, 0x6f,
    0x9d, 0xb8, 0x63,
    0x9d, 0xb8, 0x63,
    0x9d, 0xb8, 0x63,
    0x9d, 0xb8, 0x63,
    0x9c, 0x4a, 0x58,
    0x9c, 0x4a, 0x58,
    0x9c, 0x4a, 0x58,
    0x9c, 0x4a, 0x58,
    0x15, 0x5e, 0x1c,
    0x15, 0x5e, 0x1c,
    0x15, 0x5e, 0x1c,
    0x15, 0x5e, 0x1c,
    0xa6, 0x91, 0x9a,
    0xa6, 0x91, 0x9a,
    0xa6, 0x91, 0x9a,
    0xa6, 0x91, 0x9a,
    0x24, 0x47, 0xa8,
    0x24, 0x47, 0xa8,
    0x24, 0x47, 0xa8,
    0x24, 0x47, 0xa8,
    0xe5, 0x2e, 0xb0,
    0xe5, 0x2e, 0xb0,
    0xe5, 0x2e, 0xb0,
    0xe5, 0x2e, 0xb0,
    0x4f, 0x6e, 0x16,
    0x4f, 0x6e, 0x16,
    0x4f, 0x6e, 0x16,
    0x4f, 0x6e, 0x16,
    0xfc, 0xc4, 0x55,
    0xfc, 0xc4, 0x55,
    0xfc, 0xc4, 0x55,
    0xfc, 0xc4, 0x55,
    0xae, 0x57, 0xd2,
    0xae, 0x57, 0xd2,
    0xae, 0x57, 0xd2,
    0xae, 0x57, 0xd2,
    0xe5, 0x0f, 0x35,
    0xe5, 0x0f, 0x35,
    0xe5, 0x0f, 0x35,
    0xe5, 0x0f, 0x35,
    0x4c, 0x51, 0xc6,
    0x4c, 0x51, 0xc6,
    0x4c, 0x51, 0xc6,
    0x4c, 0x51, 0xc6,
    0xde, 0xbe, 0xcd,
    0xde, 0xbe, 0xcd,
    0xde, 0xbe, 0xcd,
    0xde, 0xbe, 0xcd,
    0x64, 0xfd, 0x88,
    0x64, 0xfd, 0x88,
    0x64, 0xfd, 0x88,
    0x64, 0xfd, 0x88,
    0xee, 0x6c, 0xc6,
    0xee, 0x6c, 0xc6,
    0xee, 0x6c, 0xc6,
    0xee, 0x6c, 0xc6,
    0xf7, 0x59, 0x93,
    0xf7, 0x59, 0x93,
    0xf7, 0x59, 0x93,
    0xf7, 0x59, 0x93,
    0x72, 0x7e, 0x3d,
    0x72, 0x7e, 0x3d,
    0x72, 0x7e, 0x3d,
    0x72, 0x7e, 0x3d,
    0x42, 0xb5, 0xae,
    0x42, 0xb5, 0xae,
    0x42, 0xb5, 0xae,
    0x42, 0xb5, 0xae,
    0xa8, 0x32, 0x97,
    0xa8, 0x32, 0x97,
    0xa8, 0x32, 0x97,
    0xa8, 0x32, 0x97,
    0xa3, 0x7f, 0x45,
    0xa3, 0x7f, 0x45,
    0xa3, 0x7f, 0x45,
    0xa3, 0x7f, 0x45,
    0x04, 0x0c, 0x12,
    0x04, 0x0c, 0x12,
    0x04, 0x0c, 0x12,
    0x04, 0x0c, 0x12,
    0x9d, 0xbc, 0xc9,
    0x9d, 0xbc, 0xc9,
    0x9d, 0xbc, 0xc9,
    0x9d, 0xbc, 0xc9,
};

BYTE code tQC_DITHER_NEWFUNC3_MSB_CRC_TABLE[] =
{
    0x92, 0x82, 0xfd,
    0x93, 0x5d, 0x72,
	0x4e, 0x1b, 0xc8,
	0x4b, 0x2a, 0x67,
	0x2a, 0x5e, 0x34,
	0xd4, 0xa4, 0x90,
	0x4a, 0xd0, 0x88,
	0xe5, 0xce, 0xe6,
	0x23, 0x9d, 0x41,
	0xb9, 0x7b, 0x89,
	0x11, 0x1f, 0xc3,
	0xa6, 0x46, 0x7e,
	0x66, 0x86, 0x44,
	0xca, 0x83, 0xc4,
	0xe0, 0x85, 0xa0,
	0x8b, 0xc5, 0x77,
	0x6a, 0x2a, 0x82,
	0x49, 0x40, 0x15,
	0xe1, 0xc2, 0x84,
	0xf8, 0x4f, 0xd8,
	0x91, 0x85, 0xdd,
	0x77, 0x06, 0x39,
	0x65, 0x90, 0x84,
	0x9c, 0x46, 0x41,
};

BYTE code tQC_DITHER_NEWFUNC3_LSB_CRC_TABLE[] =
{
 	0xa2, 0xdc, 0x83,
	0x5e, 0x44, 0x4d,
	0x98, 0xa9, 0xa6,
	0x34, 0x29, 0x05,
	0x9c, 0x4a, 0x58,
	0x51, 0xe5, 0x1e,
	0x89, 0xde, 0x9e,
	0x79, 0x47, 0xba,
	0xe5, 0x2e, 0xb0,
	0xc9, 0x6b, 0x51,
	0xe2, 0x8d, 0xa9,
	0x95, 0x56, 0x92,
	0xe5, 0x0f, 0x35,
	0xfd, 0x60, 0xea,
	0x45, 0x33, 0x03,
	0x3c, 0xdf, 0x13,
	0xee, 0x6c, 0xc6,
	0x69, 0x32, 0x9f,
	0xf8, 0x07, 0x86,
	0xc5, 0x61, 0x70,
	0xa8, 0x32, 0x97,
	0x3a, 0x33, 0x14,
	0xd1, 0xd2, 0xdc,
	0xdf, 0xa4, 0x82,
};

//--------------------------------------------------
// Code Tables of HLW
//--------------------------------------------------
BYTE code tQC_HIGHLIGHT_WINDOW_SETTING[] =
{
    0x00,0x55,0x02,0xAA,0x00,0x55,0x02,0xAA,0x0F,0x3F,0x3F,0x3F,0x00,0x00,
};

//--------------------------------------------------
// Code Tables of DCC
//--------------------------------------------------
BYTE code tQC_DCC_SETTING1[] =        
{
    //control
    0x00, 0x00, 0xC0,
    0x00, 0xFF, 0x00,
    0x00, 0x00, 0xFF,

    //usercurve
    0x0F, 0x1F, 0x30, 0x40,
    0x50, 0x60, 0x70, 0x80,
    0x90, 0xA0, 0xB0, 0xC0,
    0xD0, 0xE0, 0xF0, 0x00,
    0x00, 0xFF, 0x00,
    0x50, 0x14, 0x34, 0xAA,
};

BYTE code tQC_DCC_SETTING2[] =        
{
    //control
    0x8F, 0x00, 0x00,
    0xB4, 0xCE, 0x1E,
    0x00, 0x00, 0xFF,

    //usercurve
    0x10, 0x20, 0x30, 0x40,
    0x50, 0x60, 0x70, 0x80,
    0x90, 0xA0, 0xB0, 0xC0,
    0xD0, 0xE0, 0xF0, 0x00,
    0x10, 0x00, 0x10,
    0x50, 0x14, 0x34, 0xAA,
};

BYTE code tQC_DCC_SETTING3[] =        
{
    //control
    0x00, 0x00, 0x00,
    0x00, 0xF8, 0x08,
    0x00, 0x00, 0xFF,

    //usercurve
    0x11, 0x22, 0x33, 0x44,
    0x55, 0x66, 0x77, 0x80,
    0x90, 0xA0, 0xB0, 0xC0,
    0xD0, 0xE0, 0xF0, 0x00,
    0x10, 0x00, 0x10,
    0x50, 0x14, 0x34, 0x77,
};

BYTE code tQC_DCC_SETTING4[] =        
{
    //control
    0x00, 0x00, 0xC0,
    0x00, 0xF8, 0x08,
    0x00, 0x00, 0xFF,

    //usercurve
    0x08, 0x25, 0x40, 0x56,
    0x60, 0x70, 0x80, 0x90,
    0xA0, 0xB0, 0xC0, 0xD0,
    0xD8, 0xE0, 0xE8, 0xF0,
    0x08, 0x1C, 0x10,
    0x50, 0x14, 0x34, 0x00,
};

BYTE code tQC_DCC_SETTING5[] =       
{
    //control
    0x00, 0x00, 0xC0,
    0x4B, 0xF8, 0x08,
    0x00, 0x00, 0xFF,

    //usercurve
    0x21, 0x32, 0x43, 0x59,
    0x67, 0x78, 0x89, 0x9A,
    0xAB, 0xBC, 0xCD, 0xDE,
    0xE0, 0xE5, 0xEA, 0xFF,  
    0x10, 0x00, 0x00,
    0xAF, 0x4B, 0xCB, 0xDD,
};

//--------------------------------------------------
// Code Tables of ICM
//--------------------------------------------------
BYTE code tQC_New_SCM_Modify0[] =
{
    0x15, 0x20, 0x0F, 0x00, 0x41, 0x00, 0x01, 0x00, 0x28, 0x00, 0x78,
    0xBF, 0xD7, 0xAF, 0xCF, 0x9F, 0xC7, 0x8F, 0xC0,                                    
    0x00, 0xAF, 0x00, 0x9F, 0x00, 0x8F, 0x00, 0x80,                                    
    0xBF, 0x28, 0xAF, 0x30, 0x9F, 0x38, 0x8F, 0x40,                                    
    0x09, 0xB5, 0x0B, 0xA6, 0x0D, 0x97, 0x0F, 0x89,                                    
    0x00, 0x50, 0x00, 0x60, 0x00, 0x70, 0x00, 0x7F,
    0x80, 0x01, 0xFE, 0x00, 0x03, 0x00, 0xFF, 0x01, 0x0C, 0x00, 0x0C, 0x01, 0x05,
};

BYTE code tQC_New_SCM_Modify1[] =
{
    0x14, 0x41, 0xD0, 0x00, 0x41, 0x00, 0x01, 0x00, 0x28, 0x00, 0x78,
    0x00, 0x50, 0x00, 0x60, 0x00, 0x70, 0x00, 0x7F,                                    
    0xF4, 0x49, 0xF1, 0x58, 0xEE, 0x66, 0xEB, 0x74,                                    
    0x0B, 0x49, 0x0E, 0x58, 0x11, 0x66, 0x14, 0x74,
    0xE4, 0x3F, 0xDD, 0x4B, 0xD6, 0x58, 0xCF, 0x64,
    0x28, 0x38, 0x31, 0x43, 0x3B, 0x4E, 0x45, 0x58,
    0x80, 0x01, 0xFE, 0x00, 0x03, 0x00, 0xFF, 0x01, 0x0C, 0x00, 0x0C, 0x01, 0x05,
};

BYTE code tQC_New_SCM_Modify2[] =
{
    0x04, 0x91, 0x08, 0x00, 0xD4, 0x00, 0x0A, 0x00, 0x14, 0x00, 0x1E,
    0x40, 0x28, 0x50, 0x30, 0x60, 0x38, 0x70, 0x40,
    0x00, 0x50, 0x00, 0x60, 0x00, 0x70, 0x00, 0x7F,
    0x40, 0xD7, 0x50, 0xCF, 0x60, 0xC7, 0x70, 0xC0,
    0xFB, 0x4D, 0xF9, 0x5D, 0xF8, 0x6C, 0xF7, 0x7B,
    0x00, 0xAF, 0x00, 0x9F, 0x00, 0x8F, 0x00, 0x80,
    0x80, 0x01, 0xFE, 0x00, 0x03, 0x00, 0xFF, 0x01, 0x0C, 0x00, 0x0C, 0x01, 0x05,
};

BYTE code tQC_New_SCM_Modify3[] =
{
    0x08, 0xA3, 0x88, 0x00, 0xD4, 0x00, 0x0A, 0x00, 0x14, 0x00, 0x1E, 
    0x40, 0x28, 0x50, 0x30, 0x60, 0x38, 0x70, 0x40,
    0x33, 0x30, 0x3F, 0x3A, 0x4C, 0x44, 0x59, 0x4D,
    0x40, 0x20, 0x50, 0x27, 0x60, 0x2D, 0x70, 0x33,
    0x28, 0x38, 0x31, 0x43, 0x3B, 0x4E, 0x45, 0x58,
    0x40, 0xF3, 0x50, 0xF0, 0x60, 0xEE, 0x70, 0xEB,
    0x80, 0x01, 0xFE, 0x00, 0x03, 0x00, 0xFF, 0x01, 0x0C, 0x00, 0x0C, 0x01, 0x05,
};

BYTE code tQC_New_SCM_Modify4[] =
{
    0x00, 0xC2, 0x8D, 0x00, 0xF3, 0x00, 0xC8, 0x01, 0xF4, 0x02, 0x58,
    0x40, 0xD7, 0x50, 0xCF, 0x60, 0xC7, 0x70, 0xC0,
    0x40, 0xE6, 0x50, 0xE1, 0x60, 0xDC, 0x70, 0xD7,
    0x2C, 0xCA, 0x37, 0xC0, 0x42, 0xB5, 0x4D, 0xAB,
    0x40, 0xF3, 0x50, 0xF0, 0x60, 0xEE, 0x70, 0xEB,
    0x12, 0xBA, 0x16, 0xAC, 0x1A, 0x9E, 0x1F, 0x91,
    0x80, 0x01, 0xFE, 0x00, 0x03, 0x00, 0xFF, 0x01, 0x0C, 0x00, 0x0C, 0x01, 0x05,
};

BYTE code tQC_New_SCM_Modify5[] =
{
    0x01, 0xC6, 0x88, 0x00, 0xF3, 0x00, 0xC8, 0x01, 0xF4, 0x02, 0x58,
    0x00, 0xAF, 0x00, 0x9F, 0x00, 0x8F, 0x00, 0x80,
    0x09, 0xB5, 0x0C, 0xA6, 0x0E, 0x97, 0x10, 0x89,
    0xE7, 0xBE, 0xE2, 0xB1, 0xDC, 0xA4, 0xD6, 0x98,
    0x12, 0xBA, 0x16, 0xAC, 0x1A, 0x9E, 0x1F, 0x91,
    0xDC, 0xC5, 0xD3, 0xB9, 0xCA, 0xAE, 0xC2, 0xA3,
    0x80, 0x01, 0xFE, 0x00, 0x03, 0x00, 0xFF, 0x01, 0x0C, 0x00, 0x0C, 0x01, 0x05,
};

BYTE code tQC_New_SCM_Modify6[] =
{
    0x04, 0x21, 0x0D, 0x04, 0xD0, 0x00, 0x01, 0x00, 0x02, 0x00, 0x1E,
    0xF7, 0xEF, 0xEF, 0xDF, 0xE7, 0xCF, 0xDF, 0xBF, 
    0xEF, 0x00, 0xDF, 0x00, 0xCF, 0x00, 0xBF, 0x00,
    0x08, 0xEF, 0x10, 0xDF, 0x18, 0xCF, 0x20, 0xBF,
    0xF0, 0x02, 0xE1, 0x05, 0xD2, 0x07, 0xC4, 0x09,
    0x10, 0x00, 0x20, 0x00, 0x30, 0x00, 0x40, 0x00,
    0x80, 0x01, 0xFE, 0x00, 0x03, 0x00, 0xFF, 0x01, 0x0C, 0x00, 0x0C, 0x01, 0x05,
};

BYTE code tQC_New_SCM_Modify7[] =
{
    0x00, 0x32, 0xB0, 0x04, 0xD0, 0x00, 0x01, 0x00, 0x02, 0x00, 0x1E,
    0x10, 0x00, 0x20, 0x00, 0x30, 0x00, 0x40, 0x00,
    0x0F, 0xFC, 0x1D, 0xF9, 0x2C, 0xF7, 0x3A, 0xF4,
    0x0F, 0x03, 0x1D, 0x06, 0x2C, 0x09, 0x3A, 0x0B,
    0x0D, 0xF8, 0x19, 0xF1, 0x26, 0xEA, 0x32, 0xE4,
    0x0B, 0x0A, 0x16, 0x14, 0x21, 0x1E, 0x2C, 0x28,
    0x80, 0x01, 0xFE, 0x00, 0x03, 0x00, 0xFF, 0x01, 0x0C, 0x00, 0x0C, 0x01, 0x05,
};


BYTE code tQC_SCM_Modify0[] =
{
    0x02, 0x7D, 0xEE, 0x00, 0xD2, 0x00, 0x96, 0x01, 0x2C, 0x02, 0x00,
    0xBF, 0xD7, 0xAF, 0xCF, 0x9F, 0xC7, 0x8F, 0xC0,                                    
    0x00, 0xAF, 0x00, 0x9F, 0x00, 0x8F, 0x00, 0x80,                                    
    0xBF, 0x28, 0xAF, 0x30, 0x9F, 0x38, 0x8F, 0x40,                                    
    0x09, 0xB5, 0x0B, 0xA6, 0x0D, 0x97, 0x0F, 0x89,                                    
    0x00, 0x50, 0x00, 0x60, 0x00, 0x70, 0x00, 0x7F,
    0x80, 0x01, 0xFF, 0x00, 0xF5, 0x00, 0x11, 0x01, 0x80, 0x00, 0x2E, 0x00, 0xF8,
};

BYTE code tQC_SCM_Modify1[] =
{
    0x03, 0xC1, 0xD8, 0x00, 0xD2, 0x00, 0x96, 0x01, 0x2C, 0x02, 0x00,
    0x00, 0x50, 0x00, 0x60, 0x00, 0x70, 0x00, 0x7F,                                    
    0xF4, 0x49, 0xF1, 0x58, 0xEE, 0x66, 0xEB, 0x74,                                    
    0x0B, 0x49, 0x0E, 0x58, 0x11, 0x66, 0x14, 0x74,
    0xE4, 0x3F, 0xDD, 0x4B, 0xD6, 0x58, 0xCF, 0x64,
    0x28, 0x38, 0x31, 0x43, 0x3B, 0x4E, 0x45, 0x58,
    0x80, 0x01, 0xFF, 0x00, 0xF5, 0x00, 0x11, 0x01, 0x80, 0x00, 0x2E, 0x00, 0xF8,
};

BYTE code tQC_SCM_Modify2[] =
{
    0x04, 0x31, 0xC9, 0x03, 0x54, 0x00, 0x32, 0x00, 0x78, 0x00, 0xC8,
    0x40, 0x28, 0x50, 0x30, 0x60, 0x38, 0x70, 0x40,
    0x00, 0x50, 0x00, 0x60, 0x00, 0x70, 0x00, 0x7F,
    0x40, 0xD7, 0x50, 0xCF, 0x60, 0xC7, 0x70, 0xC0,
    0xFB, 0x4D, 0xF9, 0x5D, 0xF8, 0x6C, 0xF7, 0x7B,
    0x00, 0xAF, 0x00, 0x9F, 0x00, 0x8F, 0x00, 0x80,
    0x80, 0x01, 0xFF, 0x00, 0xF5, 0x00, 0x11, 0x01, 0x80, 0x00, 0x2E, 0x00, 0xF8,
};

BYTE code tQC_SCM_Modify3[] =
{
    0x05, 0x51, 0xBA, 0x03, 0x54, 0x00, 0x32, 0x00, 0x78, 0x00, 0xC8, 
    0x40, 0x28, 0x50, 0x30, 0x60, 0x38, 0x70, 0x40,
    0x33, 0x30, 0x3F, 0x3A, 0x4C, 0x44, 0x59, 0x4D,
    0x40, 0x20, 0x50, 0x27, 0x60, 0x2D, 0x70, 0x33,
    0x28, 0x38, 0x31, 0x43, 0x3B, 0x4E, 0x45, 0x58,
    0x40, 0xF3, 0x50, 0xF0, 0x60, 0xEE, 0x70, 0xEB,
    0x80, 0x01, 0xFF, 0x00, 0xF5, 0x00, 0x11, 0x01, 0x80, 0x00, 0x2E, 0x00, 0xF8,
};

BYTE code tQC_SCM_Modify4[] =
{
    0x16, 0x2B, 0xAB, 0x0C, 0xEE, 0x00, 0x01, 0x00, 0x3F, 0x00, 0x40,
    0x40, 0xD7, 0x50, 0xCF, 0x60, 0xC7, 0x70, 0xC0,
    0x40, 0xE6, 0x50, 0xE1, 0x60, 0xDC, 0x70, 0xD7,
    0x2C, 0xCA, 0x37, 0xC0, 0x42, 0xB5, 0x4D, 0xAB,
    0x40, 0xF3, 0x50, 0xF0, 0x60, 0xEE, 0x70, 0xEB,
    0x12, 0xBA, 0x16, 0xAC, 0x1A, 0x9E, 0x1F, 0x91,
    0x80, 0x01, 0xFF, 0x00, 0xF5, 0x00, 0x11, 0x01, 0x80, 0x00, 0x2E, 0x00, 0xF8,
};

BYTE code tQC_SCM_Modify5[] =
{
    0x17, 0x6F, 0x9C, 0x0C, 0xEE, 0x00, 0x01, 0x00, 0x3F, 0x00, 0x40,
    0x00, 0xAF, 0x00, 0x9F, 0x00, 0x8F, 0x00, 0x80,
    0x09, 0xB5, 0x0C, 0xA6, 0x0E, 0x97, 0x10, 0x89,
    0xE7, 0xBE, 0xE2, 0xB1, 0xDC, 0xA4, 0xD6, 0x98,
    0x12, 0xBA, 0x16, 0xAC, 0x1A, 0x9E, 0x1F, 0x91,
    0xDC, 0xC5, 0xD3, 0xB9, 0xCA, 0xAE, 0xC2, 0xA3,
    0x80, 0x01, 0xFF, 0x00, 0xF5, 0x00, 0x11, 0x01, 0x80, 0x00, 0x2E, 0x00, 0xF8,
};

BYTE code tQC_SCM_Modify6[] =
{
    0x00, 0x00, 0x00, 0x0F, 0xA0, 0x00, 0x32, 0x00, 0x64, 0x00, 0x8C,
    0xF7, 0xEF, 0xEF, 0xDF, 0xE7, 0xCF, 0xDF, 0xBF, 
    0xEF, 0x00, 0xDF, 0x00, 0xCF, 0x00, 0xBF, 0x00,
    0x08, 0xEF, 0x10, 0xDF, 0x18, 0xCF, 0x20, 0xBF,
    0xF0, 0x02, 0xE1, 0x05, 0xD2, 0x07, 0xC4, 0x09,
    0x10, 0x00, 0x20, 0x00, 0x30, 0x00, 0x40, 0x00,
    0x80, 0x01, 0xFF, 0x00, 0xF5, 0x00, 0x11, 0x01, 0x80, 0x00, 0x2E, 0x00, 0xF8,
};

BYTE code tQC_SCM_Modify7[] =
{
    0x09, 0x01, 0x00, 0x0F, 0xA0, 0x00, 0x32, 0x00, 0x64, 0x00, 0x8C,
    0x10, 0x00, 0x20, 0x00, 0x30, 0x00, 0x40, 0x00,
    0x0F, 0xFC, 0x1D, 0xF9, 0x2C, 0xF7, 0x3A, 0xF4,
    0x0F, 0x03, 0x1D, 0x06, 0x2C, 0x09, 0x3A, 0x0B,
    0x0D, 0xF8, 0x19, 0xF1, 0x26, 0xEA, 0x32, 0xE4,
    0x0B, 0x0A, 0x16, 0x14, 0x21, 0x1E, 0x2C, 0x28,
    0x80, 0x01, 0xFF, 0x00, 0xF5, 0x00, 0x11, 0x01, 0x80, 0x00, 0x2E, 0x00, 0xF8,
};


BYTE code tQC_New_ICM_Modify0[] =
{
    0xF8, 0xF0,    0xF0, 0xE0,    0xE8, 0xD0,    0xE0, 0xC0,    0xD8, 0xB0,    0xD0, 0xA0,    0xC8, 0x90,    0xC0, 0x81,
    0xF6, 0xF4,    0xEC, 0xE8,    0xE2, 0xDC,    0xD8, 0xD0,    0xCE, 0xC3,    0xC4, 0xB8,    0xBA, 0xAC,    0xB0, 0xA0,
    0xFC, 0xF0,    0xF8, 0xE0,    0xF4, 0xD0,    0xF0, 0xC0,    0xED, 0xB0,    0xE9, 0xA0,    0xE5, 0x90,    0xE2, 0x81,
    0xF4, 0xF7,    0xE8, 0xEE,    0xDD, 0xE5,    0xD1, 0xDC,    0xC6, 0xD4,    0xBA, 0xCB,    0xAE, 0xC2,    0xA4, 0xBA,
    0x00, 0xF0,    0xFF, 0xE0,    0x00, 0xD0,    0xFF, 0xC0,    0xFF, 0xB0,    0xFF, 0xA0,    0xFF, 0x90,    0xFF, 0x81,
    0x03, 0xFD,    0x04, 0xFC,    0x01, 0x42,    0x05, 0xCB,    0x00, 0x06,
    0x00, 0x52,    0x00, 0x80,    0x02, 0x80,    0x03, 0x80,    0x04, 0x80,
    0x92, 0x74,    0x00, 0x01,    0x01, 0xFE,    0x01, 0xFD,
//82,   128,   640,   896,   1152
};

BYTE code tQC_New_ICM_Modify1[] =
{
    0x08, 0xF0,    0x10, 0xE0,    0x18, 0xD0,    0x20, 0xC0,    0x28, 0xAF,    0x30, 0xA0,    0x38, 0x90,    0x3F, 0x81,
    0x03, 0xF0,    0x07, 0xE0,    0x0B, 0xD0,    0x0F, 0xC0,    0x13, 0xB0,    0x16, 0xA0,    0x1A, 0x90,    0x1E, 0x81,
    0x0A, 0xF4,    0x14, 0xE8,    0x1D, 0xDC,    0x28, 0xD0,    0x32, 0xC3,    0x3C, 0xB8,    0x46, 0xAC,    0x4F, 0xA0,
    0x00, 0xF0,    0x00, 0xE0,    0x00, 0xD0,    0x00, 0xC0,    0x00, 0xB0,    0x00, 0xA0,    0x00, 0x90,    0x00, 0x81,
    0x0B, 0xF7,    0x17, 0xEE,    0x22, 0xE5,    0x2E, 0xDC,    0x3A, 0xD4,    0x45, 0xCB,    0x51, 0xC2,    0x5C, 0xBA,
    0x0C, 0x02,    0x0D, 0x7F,    0x0A, 0xC1,    0x00, 0x06,    0x09, 0xBB,
    0x04, 0xEE,    0x00, 0x00,    0x00, 0x40,    0x00, 0x80,    0x00, 0x80,
    0x93, 0x55,    0x01, 0x2D,    0x00, 0xDA,    0x01, 0x63,
//1262,   0,   64,   128,   128
};

BYTE code tQC_New_ICM_Modify2[] =
{
    0x10, 0x00,    0x20, 0x00,    0x30, 0x00,    0x40, 0x00,    0x50, 0x00,    0x60, 0x00,    0x70, 0x00,    0x7F, 0x00,
    0x0E, 0xFC,    0x1C, 0xF9,    0x2A, 0xF6,    0x39, 0xF2,    0x47, 0xEF,    0x56, 0xEC,    0x64, 0xE8,    0x71, 0xE5,
    0x0E, 0x03,    0x1C, 0x06,    0x2A, 0x0A,    0x39, 0x0D,    0x47, 0x10,    0x56, 0x14,    0x64, 0x17,    0x71, 0x1A,
    0x0C, 0xF9,    0x19, 0xF3,    0x26, 0xED,    0x33, 0xE6,    0x40, 0xE0,    0x4D, 0xDA,    0x59, 0xD3,    0x65, 0xCD,
    0x0C, 0x06,    0x19, 0x0C,    0x26, 0x13,    0x33, 0x19,    0x40, 0x1F,    0x4D, 0x26,    0x59, 0x2C,    0x65, 0x32,
    0x08, 0x04,    0x08, 0xBA,    0x08, 0xB7,    0x09, 0xBB,    0x0A, 0x79,
    0x07, 0xC0,    0x00, 0x00,    0x00, 0x40,    0x00, 0x80,    0x00, 0x80,
    0x9C, 0x46,    0x01, 0x00,    0x00, 0x05,    0x00, 0x0E,
//1984,   0,   64,   128,   128
};

BYTE code tQC_New_ICM_Modify3[] =
{
    0x08, 0x10,    0x10, 0x20,    0x18, 0x30,    0x20, 0x40,    0x27, 0x50,    0x30, 0x60,    0x38, 0x70,    0x3F, 0x7F,
    0x0A, 0x0C,    0x14, 0x18,    0x1D, 0x24,    0x28, 0x30,    0x32, 0x3C,    0x3C, 0x48,    0x46, 0x54,    0x4F, 0x5F,
    0x03, 0x10,    0x07, 0x20,    0x0B, 0x30,    0x0F, 0x40,    0x13, 0x50,    0x16, 0x60,    0x1A, 0x70,    0x1E, 0x7F,
    0x0B, 0x08,    0x17, 0x11,    0x22, 0x1A,    0x2E, 0x23,    0x3A, 0x2B,    0x45, 0x34,    0x51, 0x3D,    0x5C, 0x45,
    0x00, 0x10,    0x00, 0x20,    0x00, 0x30,    0x00, 0x40,    0x00, 0x50,    0x00, 0x60,    0x00, 0x70,    0x00, 0x7F,
    0x0C, 0x03,    0x0B, 0x2B,    0x0C, 0xC7,    0x0A, 0x79,    0x01, 0x3C,
    0x08, 0x52,    0x00, 0x80,    0x02, 0x80,    0x02, 0xC0,    0x03, 0x00,
    0xA5, 0x70,    0x01, 0x00,    0x00, 0x0B,    0x00, 0xFF,
//2130,   128,   640,   704,   768
};

BYTE code tQC_New_ICM_Modify4[] =
{
    0xF8, 0x10,    0xF0, 0x20,    0xE8, 0x30,    0xE0, 0x40,    0xD8, 0x50,    0xD0, 0x60,    0xC8, 0x70,    0xC0, 0x7F,
    0xFC, 0x10,    0xF8, 0x20,    0xF4, 0x30,    0xF0, 0x40,    0xED, 0x50,    0xE9, 0x60,    0xE5, 0x70,    0xE2, 0x7F,
    0xF6, 0x0C,    0xEC, 0x18,    0xE2, 0x24,    0xD8, 0x30,    0xCE, 0x3C,    0xC4, 0x48,    0xBA, 0x54,    0xB0, 0x5F,
    0x00, 0x10,    0xFF, 0x20,    0x00, 0x30,    0xFF, 0x40,    0xFF, 0x50,    0xFF, 0x60,    0xFF, 0x70,    0xFF, 0x7F,
    0xF4, 0x08,    0xE8, 0x11,    0xDD, 0x1A,    0xD1, 0x23,    0xC6, 0x2B,    0xBA, 0x34,    0xAE, 0x3D,    0xA4, 0x45,
    0x03, 0xFE,    0x02, 0x88,    0x05, 0x42,    0x01, 0x3C,    0x06, 0xE6,
    0x0B, 0xEE,    0x01, 0x00,    0x01, 0x40,    0x01, 0xC0,    0x01, 0xC0, 
    0xAE, 0x46,    0x01, 0x80,    0x00, 0x0E,    0x01, 0x9F,
//3054,   256,   320,   448,   448
};

BYTE code tQC_New_ICM_Modify5[] =
{
    0xF0, 0x00,    0xE0, 0x00,    0xD0, 0x00,    0xC0, 0x00,    0xB0, 0x00,    0xA0, 0x00,    0x90, 0x00,    0x81, 0x00,
    0xF1, 0x03,    0xE3, 0x06,    0xD5, 0x0A,    0xC6, 0x0D,    0xB8, 0x10,    0xAA, 0x14,    0x9B, 0x17,    0x8E, 0x1A,
    0xF1, 0xFC,    0xE3, 0xF9,    0xD5, 0xF6,    0xC6, 0xF2,    0xB8, 0xEF,    0xAA, 0xEC,    0x9B, 0xE8,    0x8E, 0xE5,
    0xF3, 0x06,    0xE6, 0x0C,    0xD9, 0x13,    0xCC, 0x19,    0xBF, 0x1F,    0xB3, 0x26,    0xA6, 0x2C,    0x9A, 0x32,
    0xF3, 0xF9,    0xE6, 0xF3,    0xD9, 0xED,    0xCC, 0xE6,    0xBF, 0xE0,    0xB3, 0xDA,    0xA6, 0xD3,    0x9A, 0xCD,
    0x07, 0xFC,    0x07, 0x6B,    0x06, 0x84,    0x06, 0xE6,    0x05, 0xCB,
    0x0E, 0x00,    0x00, 0x00,    0x02, 0x00,    0x02, 0x40,    0x02, 0x40,
    0x87, 0x00,    0x00, 0x05,    0x01, 0xFC,    0x00, 0x06,
//3897,   100,   199,   475,   621
};

BYTE code tQC_ICM_Modify0[] =
{
    0x02, 0xD2, 0x1D,
    0xF7, 0xFF, 0xEF, 0xFF,    0xE7, 0xFF, 0xDF, 0xFE,
    0xD7, 0xFE, 0xCF, 0xFE,    0xC7, 0xFE, 0xBF, 0xFD,    
    0xF8, 0x02, 0xF1, 0x04,    0xEA, 0x06, 0xE3, 0x08,    
    0xDC, 0x0A, 0xD5, 0x0C,    0xCE, 0x0E, 0xC7, 0x0F,    
    0xF9, 0xFC, 0xF3, 0xF9,    0xED, 0xF6, 0xE6, 0xF2,    
    0xE0, 0xEF, 0xDA, 0xEC,    0xD4, 0xE9, 0xCD, 0xE5,
    0x80, 0x70, 0x00, 0x01,    0x01, 0xFE, 0x01, 0xFD,
};

BYTE code tQC_ICM_Modify1[] =
{
    0x05, 0x2E, 0xB4,
    0xFC, 0xF9, 0xF9, 0xF2,    0xF5, 0xEB, 0xF2, 0xE4,    
    0xEE, 0xDD, 0xEB, 0xD6,    0xE8, 0xD0, 0xE4, 0xC9,    
    0xFB, 0xFA, 0xF6, 0xF5,    0xF1, 0xF0, 0xEC, 0xEA,    
    0xE8, 0xE5, 0xE3, 0xE0,    0xDE, 0xDA, 0xDA, 0xD5,    
    0xFF, 0xF9, 0xFE, 0xF3,    0xFE, 0xEC, 0xFD, 0xE6,    
    0xFD, 0xDF, 0xFC, 0xD8,    0xFB, 0xD2, 0xFB, 0xCC,        
    0x81, 0x64, 0x01, 0x2D,    0x00, 0xDA, 0x01, 0x63,
};

BYTE code tQC_ICM_Modify2[] =
{
    0x08, 0x00, 0x00,
    0x03, 0xF9, 0x06, 0xF2, 0x0A, 0xEC, 0x0D, 0xE5,    
    0x10, 0xDE, 0x13, 0xD8, 0x17, 0xD1, 0x1A, 0xCB,    
    0x01, 0xF9, 0x03, 0xF3, 0x04, 0xEC, 0x06, 0xE6,    
    0x08, 0xDF, 0x09, 0xD8, 0x0B, 0xD2, 0x0C, 0xCB,    
    0x05, 0xFB, 0x0B, 0xF7, 0x10, 0xF3, 0x16, 0xEE,    
    0x1B, 0xEA, 0x21, 0xE6, 0x26, 0xE1, 0x2C, 0xDD,    
    0x8A, 0x55, 0x01, 0x00, 0x00, 0x05, 0x00, 0x0E,
};                   

BYTE code tQC_ICM_Modify3[] =
{
    0x0A, 0xD2, 0x1E,
    0x08, 0x00, 0x10, 0x00, 0x18, 0x00, 0x20, 0x01,    
    0x28, 0x01, 0x30, 0x01, 0x38, 0x01, 0x40, 0x02,
    0x07, 0xFE, 0x0E, 0xFC, 0x15, 0xFA, 0x1C, 0xF8,    
    0x23, 0xF6, 0x2A, 0xF4, 0x32, 0xF2, 0x38, 0xF0,
    0x06, 0x03, 0x0C, 0x06, 0x12, 0x09, 0x19, 0x0D,    
    0x1F, 0x10, 0x25, 0x13, 0x2C, 0x17, 0x32, 0x1A,    
    0x93, 0x46, 0x01, 0x00, 0x00, 0x0B, 0x00, 0xFF,
};

BYTE code tQC_ICM_Modify4[] =
{
    0x0D, 0x2E, 0x43,
    0x03, 0x06, 0x06, 0x0D, 0x0A, 0x14, 0x0D, 0x1B,    
    0x11, 0x22, 0x14, 0x29, 0x18, 0x30, 0x1B, 0x36,    
    0x04, 0x05, 0x09, 0x0A, 0x0E, 0x10, 0x13, 0x15,    
    0x17, 0x1A, 0x1C, 0x20, 0x21, 0x25, 0x25, 0x2A,    
    0x00, 0x06, 0x01, 0x0D, 0x01, 0x13, 0x02, 0x1A,    
    0x03, 0x21, 0x03, 0x27, 0x04, 0x2E, 0x04, 0x34,
    0x9C, 0x07, 0x01, 0x80, 0x00, 0x0E, 0x01, 0x9F,    
};

BYTE code tQC_ICM_Modify5[] =
{
    0x00, 0x00, 0x0C,
    0xFC, 0x06, 0xF9, 0x0D, 0xF6, 0x13, 0xF2, 0x1A,    
    0xEF, 0x21, 0xEC, 0x27, 0xE8, 0x2E, 0xE5, 0x34,    
    0xFE, 0x06, 0xFC, 0x0D, 0xFB, 0x13, 0xF9, 0x1A,    
    0xF8, 0x21, 0xF6, 0x27, 0xF4, 0x2E, 0xF3, 0x34,    
    0xFA, 0x04, 0xF4, 0x08, 0xEF, 0x0D, 0xE9, 0x11,    
    0xE4, 0x15, 0xDE, 0x1A, 0xD9, 0x1E, 0xD4, 0x22,
    0x85, 0x00, 0x00, 0x05, 0x01, 0xFC, 0x00, 0x06,    
};

//--------------------------------------------------
// Code Tables of Contrast & Brightness
//--------------------------------------------------
BYTE code tQC_CON_BRI_SETTING[] =
{
    // Change CTS/BRI setting parameter    
    0xAA,0x55,0xAA,0x55,0xAA,0x55,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x44,0x88,0x44,0x88,0x44,0x88,
    0x3F,0x1F,0x00,0x42,0x00,0x85,0x00,0x42,0x00,0x41,0x00,0x20,0x00,0x41,
};

//--------------------------------------------------
// Code Tables of Output Gamma
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
// Code Tables of sRGB Matrix
//--------------------------------------------------
BYTE code tSRGBMatrix[] =
{
    0x01, 0x90, 0x00, 0x24, 0x01, 0x05, 0x1F, 0xAB,
    0x01, 0xFE, 0x01, 0xDF, 0x00, 0x55, 0x00, 0x55,
    0x00, 0x07, 0x01, 0xF3, 0x00, 0x25, 0x05, 0x00,
    0x00, 0x00,
};

//--------------------------------------------------
// Code Tables of Input Gamma
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
BYTE code tQC_SU_COEF_4L_2[] =
{
    0xFB, 0x0F, 0xFE, 0x0F, 0xFD, 0x0F, 0xFC, 0x0F, 0xFB, 0x0F, 0xFA, 0x0F, 0xF7, 0x0F, 0xF5, 0x0F,
    0xF1, 0x0F, 0xED, 0x0F, 0xE9, 0x0F, 0xE4, 0x0F, 0xDE, 0x0F, 0xD9, 0x0F, 0xD3, 0x0F, 0xCD, 0x0F,
    0xC7, 0x0F, 0xDB, 0x0F, 0xF0, 0x0F, 0x0C, 0x00, 0x27, 0x00, 0x49, 0x00, 0x6B, 0x00, 0x93, 0x00,
    0xBC, 0x00, 0xEA, 0x00, 0x16, 0x01, 0x49, 0x01, 0x7A, 0x01, 0xB0, 0x01, 0xE3, 0x01, 0x1C, 0x02,
    0x84, 0x04, 0x78, 0x04, 0x6C, 0x04, 0x57, 0x04, 0x42, 0x04, 0x23, 0x04, 0x04, 0x04, 0xDC, 0x03,
    0xB4, 0x03, 0x86, 0x03, 0x59, 0x03, 0x26, 0x03, 0xF4, 0x02, 0xBD, 0x02, 0x89, 0x02, 0x50, 0x02,
    0xBA, 0x0F, 0xAF, 0x0F, 0xA7, 0x0F, 0xA1, 0x0F, 0x9C, 0x0F, 0x9A, 0x0F, 0x9A, 0x0F, 0x9C, 0x0F,
    0x9F, 0x0F, 0xA3, 0x0F, 0xA8, 0x0F, 0xAD, 0x0F, 0xB4, 0x0F, 0xBA, 0x0F, 0xC1, 0x0F, 0xC7, 0x0F,   
};

BYTE code tQC_SU_COEF_3L_2[] =
{
    0xDB, 0x0F, 0xDA, 0x0F, 0xD8, 0x0F, 0xD5, 0x0F, 0xD1, 0x0F, 0xCD, 0x0F, 0xC9, 0x0F, 0xC5, 0x0F,
    0xC0, 0x0F, 0xBD, 0x0F, 0xBA, 0x0F, 0xB7, 0x0F, 0xB7, 0x0F, 0xB9, 0x0F, 0xBD, 0x0F, 0xC0, 0x0F, 
    0x28, 0x02, 0x65, 0x02, 0x90, 0x02, 0xCD, 0x02, 0xF7, 0x02, 0x31, 0x03, 0x58, 0x03, 0x8D, 0x03,
    0xB0, 0x03, 0xE0, 0x03, 0xFC, 0x03, 0x25, 0x04, 0x39, 0x04, 0x5A, 0x04, 0x64, 0x04, 0x76, 0x04, 
    0xFD, 0x01, 0xC1, 0x01, 0x98, 0x01, 0x5E, 0x01, 0x38, 0x01, 0x02, 0x01, 0xDF, 0x00, 0xAE, 0x00, 
    0x90, 0x00, 0x63, 0x00, 0x4A, 0x00, 0x24, 0x00, 0x10, 0x00, 0xED, 0x0F, 0xDF, 0x0F, 0xCA, 0x0F, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

BYTE code tQC_SU_COEF_2L_2[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x82, 0x0F, 0x97, 0x0F, 0xA4, 0x0F, 0xCE, 0x0F, 0xE8, 0x0F, 0x1A, 0x00, 0x3B, 0x00, 0x73, 0x00,
    0x98, 0x00, 0xD2, 0x00, 0xF8, 0x00, 0x32, 0x01, 0x58, 0x01, 0x91, 0x01, 0xB5, 0x01, 0xEE, 0x01,
    0x7E, 0x04, 0x69, 0x04, 0x5C, 0x04, 0x32, 0x04, 0x18, 0x04, 0xE6, 0x03, 0xC5, 0x03, 0x8D, 0x03,
    0x68, 0x03, 0x2E, 0x03, 0x08, 0x03, 0xCE, 0x02, 0xA8, 0x02, 0x6F, 0x02, 0x4B, 0x02, 0x12, 0x02, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//--------------------------------------------------
// Code Tables of Scale Down
//--------------------------------------------------
BYTE code tQC_SCALEDOWN_MODE0_CRC[] = 
{
    0xC9, 0x3E, 0x68,
    0xC1, 0xA8, 0x9A,
};

BYTE code tQC_SCALEDOWN_MODE1_CRC[] = 
{
    0x8D, 0xEA, 0x1C,
    0x47, 0xDD, 0x5B,
};

BYTE code tQC_SCALEDOWN_MODE2_CRC[] = 
{
    0x75, 0x17, 0x94,
    0xE4, 0xF7, 0x7C,
};

BYTE code tQC_SCALEDOWN_MODE3_CRC[] = 
{
    0x91, 0x67, 0xAC,
    0x79, 0xF6, 0x95,
};

BYTE code tQC_SCALEDOWN_MODE4_CRC[] = 
{
    0x30, 0x62, 0xEC,
    0xF4, 0xCD, 0x72,
};

//----------------------------------------------------------------------------------------------------
// LVDS Common Table 
//----------------------------------------------------------------------------------------------------
BYTE code tQC_COMMONMLVDS[] =
{ 
    5,	_AUTOINC,	0x28,	0x23,0x00, // NO frame sync, eo no swap
                
    4,	_AUTOINC,       0x28,   0x08,	    // frame sync
    4,	_AUTOINC,       0x2A,   0x00,
    5,	_NON_AUTOINC,   0x2B,   0x06,0xC0,	// total disp hori. pixels = 1728
    4,	_AUTOINC,       0x2A,   0x02,
    4,	_NON_AUTOINC,   0x2B,   0x60,	    // hs end
    4,	_AUTOINC,       0x2A,   0x03,
    5,	_NON_AUTOINC,   0x2B,   0x01,0x25,	// hori bkg start 
    4,	_AUTOINC,       0x2A,   0x05,
    5,	_NON_AUTOINC,   0x2B,   0x01,0x25,	// hori act start
    4,	_AUTOINC,       0x2A,   0x07,
    5,	_NON_AUTOINC,   0x2B,   0x05,0x25,	// hori act end 	
    4,	_AUTOINC,       0x2A,   0x09,
    5,	_NON_AUTOINC,   0x2B,   0x05,0x25,	// hori bkg end		
    4,	_AUTOINC,       0x2A,   0x0B,
    5,	_NON_AUTOINC,   0x2B,   0x03,0x30,	// vert. total  = 816
    4,	_AUTOINC,       0x2A,   0x0D,
    4,	_NON_AUTOINC,   0x2B,   0x04,	    // vs end
    4,	_AUTOINC,       0x2A,   0x0E,
    5,	_NON_AUTOINC,   0x2B,   0x00,0x2F,	// vert bkg start
    4,	_AUTOINC,       0x2A,   0x10,
    5,	_NON_AUTOINC,   0x2B,   0x00,0x2F,	// vert act start
    4,	_AUTOINC,       0x2A,   0x12,
    5,	_NON_AUTOINC,   0x2B,   0x03,0x2F,	// vert act end		
    4,	_AUTOINC,       0x2A,   0x14,
    5,	_NON_AUTOINC,   0x2B,   0x03,0x2F,	// vert bkg end	
    4,	_AUTOINC,       0x2A,   0x20,
    4,	_NON_AUTOINC,   0x2B,   0x00, 	    //<cchild_debug> Dclk polarity inv disable    8825~8920

    4,	_AUTOINC,	0x40,	0x02,	        // ivs to dvs

    // fixed last line for free-run mode
    4,	_AUTOINC,	0x9F,	0x01,
    7,	_AUTOINC,	0xC7,	0x63,0x30,0xC0,0x02,

    4,	_AUTOINC,	0x28,	0x87,    // free-run mode, force-to-background, single output, force enable
    4,	_AUTOINC,	0x29,	0x00,

    4,	_AUTOINC, 0x9F, 0x07,
    //10,	_AUTOINC, 0xF0, 0x81, 0x01, 0x01, 0xF6, 0x04, 0xFC, 0x00,
    //10,	_AUTOINC, 0xF0, 0x85, 0x05, 0x05, 0x00, 0x04, 0x08, 0x01,
    16,	_AUTOINC, 0xF0, 0x85, 0x05, 0x05, 0x00, 0x04, 0x08, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x15,
    _END
 
};

//----------------------------------------------------------------------------------------------------
// LVDS_7x Table
//----------------------------------------------------------------------------------------------------
BYTE code tQC_MLVDS7X[] =
{ 
    // Display PLL
    // M=37+2=39, N=0+2=5
    // dpll: 14.318*52/2/2 = 196 MHz(FT even/odd pattern)
    // dclk: (dual port) = 93 Mhz
    4,	_AUTOINC,	0x9F,	0x01,

    4,	_AUTOINC,	0xBF,	0x32,       //M=50+2 
    4,	_AUTOINC,	0xC0,	0x00,       //N=0+2 div2
    4,	_AUTOINC,	0xC1,	0x72,       // Icp = 7.5
    4,	_AUTOINC,	0xC4,	0x10,       // offset = 0
    4,	_AUTOINC,	0xC5,	0x00,       // offset = 0

    4,	_AUTOINC,	0xC2,	0x09,       // power down dpll
    4,	_AUTOINC,	0xC2,	0x08,       // Power on DPLL

    // ----------- calibration start ------------------
    //--NO REPLACE--//  CC 00 10
    4,	_AUTOINC,	0xC3,	0x85, 	    // CMP enable	
    //--NO REPLACE--//  CC 00 09
    4,	_AUTOINC,	0xC3,	0x8D, 	    // latchca libration
    //--NO REPLACE--//  CC 00 09
    4,	_AUTOINC,	0xC3,	0x9D, 	    // calibration valids
    //--NO REPLACE--//  CC 00 09
    // ----------- calibration end ------------------

    //-------- LVDS -------------------------------------------------------------//
    5,	_AUTOINC,	0x8B,	0x00,0x01,  // lvds mode
    5,	_AUTOINC,	0x8B,	0xA1,0xA7,
    5,	_AUTOINC,	0x8B,	0xA2,0x53,
    5,	_AUTOINC,	0x8B,	0xA3,0x26,
    5,	_AUTOINC,	0x8B,	0xA4,0x80,
    5,	_AUTOINC,	0x8B,	0xA5,0x80,
    5,	_AUTOINC,	0x8B,	0xA6,0x52,
    5,	_AUTOINC,	0x8B,	0xA7,0x36,
    5,	_AUTOINC,	0x8B,	0xA8,0x00,
    5,	_AUTOINC,	0x8B,	0xA9,0x01,
    5,	_AUTOINC,	0x8B,	0xAA,0x01,

    5,	_AUTOINC,	0x8B,	0xAF,0x9C,
    5,	_AUTOINC,	0x8B,	0xB4,0x00,
    5,	_AUTOINC,	0x8B,	0xB5,0x30,
    5,	_AUTOINC,	0x8B,	0xB6,0x00,
    5,	_AUTOINC,	0x8B,	0xB7,0x6E,
    5,	_AUTOINC,	0x8B,	0xB8,0x0A,
    5,	_AUTOINC,	0x8B,	0xB9,0x88,
    5,	_AUTOINC,	0x8B,	0xBA,0xFF,

    5,	_AUTOINC,	0x8B,	0xBB,0x00,
    5,	_AUTOINC,	0x8B,	0xBC,0x01,
    5,	_AUTOINC,	0x8B,	0xBE,0x00,
    5,	_AUTOINC,	0x8B,	0xC0,0x00,

    5,	_AUTOINC,	0x8B,	0xA0,0xB2,   // LVDS E/O/IBGen power
    5,	_AUTOINC,	0x8B,	0xA0,0xF2,   // pll power 


    //---------------------------------------------------------------------//
    // Start CRC
    4,	_AUTOINC,	0x2C,	0x81,

    _END
};

//LVDS end

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE ScalerQCA0PortTest(void);
bit ScalerQCBistTest(void);
void ScalerQCIDomainRandomGenOn(bit bRandomSelect);
void ScalerQCIDomainRandomGenOff(void);
void ScalerQCDDomainPatternGenOn(void);
void ScalerQCDDomainPatternGenOff(void);
void ScalerQCDDomainRandomGenOn(bit bRandomSelect);
void ScalerQCIDitherOn(bit bOutputSelect);
void ScalerQCIDitherOff(void);
void ScalerQCDDitherOn(bit bOutputSelect);
void ScalerQCDDitherOff(void);
void ScalerQCHighlightWindowOn(void);
void ScalerQCHighlightWindowOff(void);
bit ScalerQCCheckCRCOn(BYTE ucCRC1,BYTE ucCRC2, BYTE ucCRC3, BYTE ucCRCSelect);
void ScalerQCCheckCRCOff(void);
bit ScalerQCCheckFSCrc(BYTE *pTableAddr, WORD usTableLen, BYTE ucCRCSelect, BYTE ucStartCRCNum);
bit ScalerQCminiLVDSCRCOn(BYTE ucCRC0, BYTE ucCRC1, BYTE ucCRC2, BYTE ucCRC3, BYTE ucCRC4, BYTE ucCRC5, BYTE ucCRC6, BYTE ucCRC7, 
                          BYTE ucCRC8, BYTE ucCRC9, BYTE ucCRC10, BYTE ucCRC11, BYTE ucCRC12, BYTE ucCRC13, BYTE ucCRC14, BYTE ucCRC15,
                          BYTE ucCRC16, BYTE ucCRC17, BYTE ucCRC18, BYTE ucCRC19, BYTE ucCRC20, BYTE ucCRC21, BYTE ucCRC22, BYTE ucCRC23);
void ScalerQCminiLVDSCRCOff(void);
void ScalerQCAllDigitalFunctionDisable(void);
bit ScalerQCIDomainRandomGenTest(void);
bit ScalerQC422to444Test(void);
bit ScalerQCRingingFilterTest(void);
bit ScalerQCDigitalFilterTest(void);
bit ScalerQCColorConversionTest(void);
bit ScalerQCIDitherTest(void);
bit ScalerQCScaleUpTest(void);
bit ScalerQCHLWTest(void);
bit ScalerQCDDomainPGTest(void);
bit ScalerQCDCRTest(void);
bit ScalerQCDCCTest(void); 
//YiZhu add start
bit ScalerQCYPeakingTest(void);
//YiZhu add end
bit ScalerQCICMTest(void);
bit ScalerQCConBriTest(void);
bit ScalerQCGammaTest(void);
bit ScalerQCsRGBTest(void);
bit ScalerQCPCMTest(void);
void ScalerQCPCMAdjustSU(bit bIs3L);
bit ScalerQCDDitherTest(void);
bit ScalerQCDisplayConversionTest(void);
bit ScalerQCScaleDownTest(void);
bit ScalerQCDisplayConversionTest(void);

void ScalerQCIICSDA(bit ucset);
void ScalerQCFPGA7xTable(void);
void ScalerQCFPGACLRSCLK(void);
void ScalerQCFPGAConent(BYTE *pucpass);
BYTE ScalerQCFPGAGetByte(void);
void ScalerQCFPGARead(BYTE ucAddr, BYTE *pucArray);
void ScalerQCFPGAReadStop(void);
void ScalerQCFPGASendAddr(BYTE ucAddr, bit ucReadWrite, bit ucAutoInc);
void ScalerQCFPGASendByte(BYTE ucValue);
void ScalerQCFPGASetByte(BYTE ucAddr, BYTE ucValue);
void ScalerQCFPGASetSCLK(void);
void ScalerQCFPGAWriteStop(void);
bit ScalerQCmLVDS(void);

#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
bit ScalerQCeLED(void);
void ScalerQCeLEDControl(bit bOn);
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
      
    ucResult = (ucResult | ((BYTE)ScalerQCBistTest() << 7));                    // BIST Test
    ucResult = (ucResult | ScalerQCIDomainRandomGenTest());                     // I Domain Random Generator Test
    ucResult = (ucResult | ScalerQC422to444Test());                             // YUV 422 to 444 Test
    ucResult = (ucResult | ScalerQCRingingFilterTest());                        // Ringing Filter Test
    ucResult = (ucResult | ScalerQCDigitalFilterTest());                        // Digital Filter Test
    ucResult = (ucResult | ScalerQCColorConversionTest());                      // Color Conversion Test                    
    ucResult = (ucResult | ScalerQCIDitherTest());                              // I Dither Test   

    ucResult = (ucResult | ((BYTE)ScalerQCScaleUpTest() << 1));                 // Scale Up Test

    ucResult = (ucResult | ((BYTE)ScalerQCHLWTest() << 1));                     // Highlight Window Test

    ucResult = (ucResult | ((BYTE)ScalerQCDDomainPGTest() << 1));               // D Domain Pattern Generator Test    
    ucResult = (ucResult | ((BYTE)ScalerQCDCRTest() << 2));                     // DCR Test
    ucResult = (ucResult | ((BYTE)ScalerQCDCCTest() << 2));                     // DCC Test
    //YiZhu add start
    ucResult = (ucResult | ((BYTE)ScalerQCYPeakingTest() << 2));                // YPeaking Test
    //YiZhu add end
    ucResult = (ucResult | ((BYTE)ScalerQCICMTest() << 2));                     // ICM Test    
    ucResult = (ucResult | ((BYTE)ScalerQCConBriTest() << 2));                  // Contrast & Brightness Test
    ucResult = (ucResult | ((BYTE)ScalerQCsRGBTest() << 2));                    // sRGB Test    
    ucResult = (ucResult | ((BYTE)ScalerQCGammaTest() << 2));                   // Output Gamma Test      
    ucResult = (ucResult | ((BYTE)ScalerQCPCMTest() << 2));                     // PCM tTest
    ucResult = (ucResult | ((BYTE)ScalerQCDDitherTest() << 2));                 // D Diher Test   
    ucResult = (ucResult | ((BYTE)ScalerQCDisplayConversionTest() << 1));       // Display Conversion
    ucResult = (ucResult | ((BYTE)ScalerQCOSDTest() << 3));                     // OSD Test
    
	ucResult = (ucResult | ((BYTE)ScalerQCScaleDownTest() << 4));               // Scaler down Test

#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
    ucResult = (ucResult | ((BYTE)ScalerQCeLED() << 6));                        // eLED Test
#endif

    ucResult = (ucResult | ((BYTE)ScalerQCmLVDS()<< 5));                        // mLVDS Test


    return ucResult;
}

//----------------------------------------------------------------------------
// Indivisual Test Block Process
//----------------------------------------------------------------------------
//--------------------------------------------------
// Description  : Test All Memory BIST
// Input Value  : None
// Output Value : TEST_PASS or TEST_FAIL
//--------------------------------------------------
bit ScalerQCBistTest(void)
{    
    BYTE ucBistResult = 0;    
            
    // Test Frame Sync 4 Line Buffer
    ScalerSetBit(CM_44_LAST_LINE_H, ~_BIT5, _BIT5);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, CM_44_LAST_LINE_H, _BIT5, 0x00) == _TRUE)
    {
        // BIST Fail
        if(ScalerGetBit(CM_44_LAST_LINE_H, _BIT4) != _BIT4)
        {
            DebugMessageScaler("5. Line buffer Bist Fail", 0x00);            
            ucBistResult |= _BIT0;
        }
    }
    else
    {
        DebugMessageScaler("5. Line buffer Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }
    
    // Test Gamma Table SRAM
    ScalerSetBit(CM_68_GAMMA_BIST, ~_BIT2, _BIT2);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, CM_68_GAMMA_BIST, _BIT1, 0x00) == _TRUE)
    {
        // BIST Fail
        if(ScalerGetBit(CM_68_GAMMA_BIST, _BIT0) != _BIT0)
        {
            DebugMessageScaler("5. Gamma Bist Fail", 0x00);            
            ucBistResult |= _BIT1;
        }
    }
    else
    {
        DebugMessageScaler("5. Gamma Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    ScalerSetBit(CM_68_GAMMA_BIST, ~_BIT2, 0x00);

    // Test DCC SRAM
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
    ScalerSetDataPortBit(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P3_00_SRAM_BIST, ~_BIT7, _BIT7);
    ScalerTimerDelayXms(10);
    if(ScalerGetDataPortBit(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P3_00_SRAM_BIST, _BIT1) == 0x00)
    {
        if(ScalerGetDataPortBit(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P3_00_SRAM_BIST, _BIT0) != _BIT0)
        {
            DebugMessageScaler("5. DCC SRAM Bist Fail", 0x00);
            ucBistResult |= _BIT1;                            
        }
    }
    else
    {
        DebugMessageScaler("5. DCC SRAM Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;        
    }
    ScalerSetDataPortBit(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P3_00_SRAM_BIST, ~_BIT7, 0x00);    

    // Test OSD SRAM
    ScalerSetBit(CM_93_OSD_SCRAMBLE, ~_BIT7, _BIT7);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, CM_93_OSD_SCRAMBLE, _BIT7, 0x00) == _TRUE)
    {
        if(ScalerGetBit(CM_93_OSD_SCRAMBLE, _BIT6) != _BIT6)
        {
            DebugMessageScaler("5. OSD Bist Fail", 0x00);
            ucBistResult |= _BIT3;
        }
    }
    else
    {
        DebugMessageScaler("5. OSD Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT3;
    }

    if((bit)ucBistResult == 0x00)
    {
        DebugMessageScaler("6. Bist PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Bist Fail Mode", ucBistResult);
        DebugMessageScaler("6. Bist FAIL", 0x00);    
        return _TEST_FAIL;
    }   

    // Test ADCNR SRAM
    ScalerSetBit(P2A_B3_ADCNR_DEBUG_MODE_CTRL1, ~_BIT5, _BIT5);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2A_B3_ADCNR_DEBUG_MODE_CTRL1, _BIT4, 0x00) == _TRUE)
    {
        // BIST Fail
        if(ScalerGetBit(P2A_B3_ADCNR_DEBUG_MODE_CTRL1, _BIT3) != _BIT3)
        {
            DebugMessageScaler("5. Statistic Sram Bist Fail", 0x00);            
            ucBistResult |= _BIT4;
        }
        if(ScalerGetBit(P2A_B3_ADCNR_DEBUG_MODE_CTRL1, _BIT2) != _BIT2)
        {
            DebugMessageScaler("5. Mapping Table Sram Bist Fail", 0x00);            
            ucBistResult |= _BIT4;
        }
    }
    else
    {
        DebugMessageScaler("5. ADCNR Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT4;
    }
    ScalerSetBit(P2A_B3_ADCNR_DEBUG_MODE_CTRL1, ~_BIT5, 0x00);    
}

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
    // Wendy add 20120914 Start
    ScalerSetByte(P7_FB_DISP_PG_RANDOM_CTRL, 0x00);
    ScalerSetByte(P7_FC_DISP_PG_INITIAL_LSB, 0x00);
    // Wendy add 20120914 End
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
// Description  : Enable D Domain Random PG With 10-bit Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCDDomainRandomGenOn(bit bRandomSelect)
{
    // Set initial Value
    ScalerSetBit(P7_F0_DISP_PG_R_CTRL, ~_BIT6, _BIT6);
    ScalerSetBit(P7_F1_DISP_PG_G_CTRL, ~_BIT6, _BIT6);
    ScalerSetBit(P7_F2_DISP_PG_B_CTRL, ~_BIT6, _BIT6);
    ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, 0x00);
    ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, 0x00);
    ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, 0x00);
    ScalerSetByte(P7_FC_DISP_PG_INITIAL_LSB, 0x15);  

    if(bRandomSelect == _GRAY)
    {
        ScalerSetByte(P7_FB_DISP_PG_RANDOM_CTRL, 0x00);    // R=G=B
    }
    else
    {
        ScalerSetByte(P7_FB_DISP_PG_RANDOM_CTRL, 0x40);    // R!=G!=B
    }

    ScalerSetBit(P7_F0_DISP_PG_R_CTRL, ~_BIT7, _BIT7); // Enable
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
    BYTE ucWaitType = _EVENT_DVS;

    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
        
    if(ucCRCSelect == _I_DOMAIN_CRC)
    {
        ucWaitType = _EVENT_IVS;

        ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, 0x07, ~(_BIT5 | _BIT3), (_BIT5 | _BIT3));
        ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x01);     
    }
    else if(ucCRCSelect == _M_DOMAIN_CRC)
    {
        ucWaitType = _EVENT_DVS;        

        ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, 0x07, ~_BIT5, _BIT5);
        ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x41);
    }
    else if(ucCRCSelect == _D_DOMAIN_CRC)
    {
        ucWaitType = _EVENT_DVS;
        ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, 0x07, ~(_BIT5 | _BIT3), 0x00);
        ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x81);
    }

    ScalerTimerWaitForEvent(ucWaitType);                
    ScalerTimerWaitForEvent(ucWaitType);
            
    ScalerRead(CM_2D_OP_CRC_CKSM, 3, pData, _NON_AUTOINC);
    
    ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, 0x07, ~(_BIT5|_BIT3), 0x00);
    
    if((pData[0] == ucCRC1) && (pData[1] == ucCRC2) && (pData[2] == ucCRC3))    
    {
        DebugMessageScaler("5. ===Pass===",0x00);

        return _TEST_PASS;
    }
    else 
    {
        DebugMessageScaler("5. ucData[0]",pData[0]);
        DebugMessageScaler("5. ucData[1]",pData[1]);
        DebugMessageScaler("5. ucData[2]",pData[2]);

        return _TEST_FAIL;
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
    ScalerSetBit(CM_8E_PS_DATA_PORT, ~(_BIT5|_BIT3), 0x00);
    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
}

//--------------------------------------------------
// Description  : Enable CRC 
// Input Value  : ucCRCSelect ---> 0: _I_DOMAIN_CRC,  1: _M_DOMAIN_CRC, 2: _D_DOMAIN_CRC
// Output Value : 0: _FALSE, 1: _TRUE
//--------------------------------------------------
bit ScalerQCCheckFSCrc(BYTE *pTableAddr, WORD usTableLen, BYTE ucCRCSelect, BYTE ucStartCRCNum)
{
    BYTE ucCnt = 0;
    BYTE ucWaitType = _EVENT_DVS;
    BYTE ucDataTemp[3] = {0};
    bit bCheckFailFlag = _FAIL;
    BYTE ucStartCnt = 0;
        
    // Start CRC
    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
            
    if(ucCRCSelect == _I_DOMAIN_CRC)
    {
        ucWaitType = _EVENT_IVS;
        ScalerSetByte(CM_8D_PS_ACCESS_PORT, 0x07);
        ScalerSetBit(CM_8E_PS_DATA_PORT, ~(_BIT5|_BIT3), _BIT5|_BIT3);
        ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x01);     
    }
    else if(ucCRCSelect == _M_DOMAIN_CRC)
    {
        ucWaitType = _EVENT_DVS;
        ScalerSetByte(CM_8D_PS_ACCESS_PORT, 0x07);
        ScalerSetBit(CM_8E_PS_DATA_PORT, ~(_BIT5), _BIT5);
        ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x41);
    }
    else if(ucCRCSelect == _D_DOMAIN_CRC)
    {
        ucWaitType = _EVENT_DVS;
	ScalerSetBit(CM_8E_PS_DATA_PORT, ~(_BIT5|_BIT3), 0x00);
        ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x81);
    }    
                
    ScalerTimerWaitForEvent(ucWaitType);    

    // Get Start CRC Time Pos
    do
    {
        ScalerTimerWaitForEvent(ucWaitType);
        ScalerRead(CM_2D_OP_CRC_CKSM, 3, ucDataTemp, _NON_AUTOINC);
            
        if((ucDataTemp[0] == *(pTableAddr + (ucStartCnt * 3))) && (ucDataTemp[1] == *(pTableAddr + (ucStartCnt * 3) + 1)) && (ucDataTemp[2] == *(pTableAddr + (ucStartCnt * 3) + 2)))
        {

            ucStartCnt++;

            if(ucStartCnt >= ucStartCRCNum)
            {
                  bCheckFailFlag = _SUCCESS;
                break;              
            }
        }
        else
        {
            ucStartCnt = 0;
        }
            
        ucCnt++;        
    }while(ucCnt < (usTableLen + 12));

    ucCnt = ucStartCnt;    

    if(bCheckFailFlag == _SUCCESS)
    {        
        do
        {
            ScalerTimerWaitForEvent(ucWaitType);
            ScalerRead(CM_2D_OP_CRC_CKSM, 3, ucDataTemp, _NON_AUTOINC);

            if((ucDataTemp[0] != *(pTableAddr + (ucCnt * 3))) || (ucDataTemp[1] != *(pTableAddr + (ucCnt * 3) + 1)) || (ucDataTemp[2] != *(pTableAddr + (ucCnt * 3) + 2)))
            {
                bCheckFailFlag = _FAIL;
                break;
            }    
            
            ucCnt++;
        }while(ucCnt < (usTableLen));    
    }

    if(bCheckFailFlag == _SUCCESS)
    {
        DebugMessageScaler("5. ===Pass===",0x00);
        return _FALSE;
    }

    return _TRUE; 
}



//--------------------------------------------------
// Description  : Disable All Digital Function & Watch Dog 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCAllDigitalFunctionDisable(void)
{
    ScalerSetByte(CM_0C_WATCH_DOG_CTRL0, 0x00);        // Disable Watch Dog
    ScalerSetByte(CM_0D_WATCH_DOG_CTRL1, 0x00);        // Disable Watch Dog

    ScalerQCCheckCRCOff();                            // Disable CRC Check
   
    ScalerSetByte(CM_28_VDISP_CTRL, 0x0F);            //VDIS_CTRL,       
                                                    //Frame Sync Mode Enable
                                                    //Display Output Double Port Enable
                                                    //Display Output Run Enable
                                                    //Display Timing Run Enable

    //--------------------I Domain------------------//
    ScalerQCIDomainRandomGenOff();                    // Disable I Domain Random Generator
    ScalerSetByte(CM_1F_V8_YUV_CONVERSION, 0x00);   // Disable YUV422 to 444
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL, 0x70);    
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, 0x00); // Y(G)/Pb(B)/Pr(R) Function Disable//Initial Value=0
    ScalerSetByte(P25_A0_RFILTER_CTRL,0x00);        //Disable Ringing Filter
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL, 0x00); // Disable Digital Filter
    ScalerSetByte(CM_89_I_DITHERING_CTRL1, 0x00);    // Disable I Domain Dither
    //--------------------D Domain------------------//
   
    ScalerQCHighlightWindowOff();                      // Disable Highlight Window
    ScalerQCDDomainPatternGenOff();                     // Disable D Domain Pattern Generator
    ScalerSetByte(P14_A1_SR_YCC2RGB_CTRL, 0x00);     // Disable YUVtRGB_D
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT, 0x00);    	// Disable DCR
    ScalerSetByte(P7_C7_DCC_CTRL0, 0x00);             // Disable DCC
    
    ScalerSetByte(P7_D6_PKING_ACCESS_PORT, 0x00);    // Disable Y-Peaking
    ScalerSetByte(P7_D0_ICM_CTRL, 0x80);
    ScalerSetByte(P7_D1_ICM_SEL, 0x00);
    ScalerSetByte(P7_D0_ICM_CTRL, 0x00);                     // Disable ICM
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);   
    ScalerSetByte(P7_D4_ICM_NEW_MODE, 0x00);        // Disable New ICM
    ScalerSetByte(P7_DB_CABC_CTRL, 0x00);              // Disable CABC
    ScalerSetByte(P9_A1_INPUT_GAMMA_CTRL, 0x00);    // Disable Input Gamma
    ScalerSetByte(CM_62_COLOR_CTRL, 0x00);            // Disable sRGB/Contrast/Brightness
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x00);            // Disable Output Gamma
    ScalerSetByte(CM_6C_OVERLAY_CTRL, 0x00);        // Disable OSD
    ScalerSetByte(CM_6A_DITHERING_CTRL1, 0x00);        // Disable D Domain Dither
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
    
    DebugMessageScaler("5. I Domain Random Generator End", 0x00);
    
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. I Domain Random Generator Pass", 0x00);       
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. I Domain Random Generator Fail", 0x00);
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

    ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);                     // Enable YUV422 to 444
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
    
    DebugMessageScaler("5. YUV422 to 444 End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. YUV422 to 444 PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. YUV422 to 444 FAIL", 0x00);
        return _TEST_FAIL;
    }

}
//--------------------------------------------------
// Description  : RingingFilter Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCRingingFilterTest(void)        
{
    BYTE ucData = 0;

    DebugMessageScaler("5. Ringing Filter Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);
    
    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xE0); 
    ScalerSetByte(P25_A1_RFILTER_THD, 0x23); 
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x0C); 
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01); 
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01); 
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00); 
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_0", 0x00);  // normal
    ucData = (ucData | ((WORD)ScalerQCCheckCRCOn(0x9F, 0x45, 0x2C, _I_DOMAIN_CRC) << 0));
    
    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xC0); 
    ScalerSetByte(P25_A1_RFILTER_THD, 0x23); 
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x0C); 
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01); 
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01); 
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00); 
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_1", 0x00);  // disable JumpJudgment En
    ucData = (ucData | ((WORD)ScalerQCCheckCRCOn(0xA5, 0xEB, 0x74, _I_DOMAIN_CRC) << 1));

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xC0); 
    ScalerSetByte(P25_A1_RFILTER_THD, 0x23); 
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x0C); 
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01); 
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01); 
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x07); 
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_2", 0x00);  // Enable Factor=1
    ucData = (ucData | ((WORD)ScalerQCCheckCRCOn(0x94, 0x1F, 0x67, _I_DOMAIN_CRC) << 2));

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xA0); 
    ScalerSetByte(P25_A1_RFILTER_THD, 0x50); 
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x0C); 
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x00); 
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01); 
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00); 
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_3", 0x00);  // Fixing Offset Range
    ucData = (ucData | ((WORD)ScalerQCCheckCRCOn(0xEC, 0x94, 0xB4, _I_DOMAIN_CRC) << 3));

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xA0); 
    ScalerSetByte(P25_A1_RFILTER_THD, 0xB4); 
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x06); 
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01); 
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01); 
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00); 
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_4", 0x00);  // big threshold, small offset Coef, DiffThreshold_UB/LB
    ucData = (ucData | ((WORD)ScalerQCCheckCRCOn(0x27, 0x38, 0x07, _I_DOMAIN_CRC) << 4));

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xE0); 
    ScalerSetByte(P25_A1_RFILTER_THD, 0x14); 
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x02); 
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x12); 
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01); 
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01); 
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x08); 
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_4", 0x00);  // Enable DiffFactor=0 when pixels=2
    ucData = (ucData | ((WORD)ScalerQCCheckCRCOn(0x7E, 0xE6, 0x80, _I_DOMAIN_CRC) << 5));

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xB0); 
    ScalerSetByte(P25_A1_RFILTER_THD, 0x96); 
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x02); 
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x00); 
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01); 
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x04); 
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_6", 0x00);  // big threshold, small coef, R disable, THD_Factor=1
    ucData = (ucData | ((WORD)ScalerQCCheckCRCOn(0x20, 0x32, 0x60, _I_DOMAIN_CRC) << 6));

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xC0); 
    ScalerSetByte(P25_A1_RFILTER_THD, 0x50); 
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x1E); 
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04); 
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x00); 
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01); 
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00); 
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_7", 0x00);  // big coef
    ucData = (ucData | ((WORD)ScalerQCCheckCRCOn(0xD2, 0x4D, 0x19, _I_DOMAIN_CRC) << 7));
        
    ScalerSetByte(P25_A0_RFILTER_CTRL, 0x00); // Disable Ringing Filter

    ScalerQCIDomainRandomGenOff();   
    ScalerQCCheckCRCOff();   

    DebugMessageScaler("5.Ringing Filter End", 0x00);       
    
    if(ucData == 0x0000)
    {
        DebugMessageScaler("6. Ringing Filter PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. Ringing Filter FAIL", 0x00);
        return _TEST_FAIL;
    }       

}

//--------------------------------------------------
// Description  : DigitalFilter Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCDigitalFilterTest(void)
{
    WORD usData = 0;

    DebugMessageScaler("5. Digital Filter Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);

    //Digital Filter For Phase
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Disable Digital Filter
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Y/Pb/Pr Function Disable //Initial Value=0
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x00); // Disable Digital Filter
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Digital Filter Coefficient
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xF0); 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x10); // Enable Phase subFunction
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x80); 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x11);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // disable New Phase Mode EN    
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x90); // Set Old Phase Threshold 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x32); 
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
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0x05, 0x0F, 0xC4, _I_DOMAIN_CRC) << 0));

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
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0xEE, 0xFB, 0x41, _I_DOMAIN_CRC) << 1));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x04); // only reduce ringing condition + mismatch
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_2", 0x00);
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0xEE, 0xFB, 0x41, _I_DOMAIN_CRC) << 2));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x08); // only reduce smear condition + mismatch
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_3", 0x00);
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0xEE, 0xFB, 0x41, _I_DOMAIN_CRC) << 3));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x0C); //  no adjust  + mismatch
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_4", 0x00);
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0xEE, 0xFB, 0x41, _I_DOMAIN_CRC) << 4));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x02); // disable + noise reduction
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_5", 0x00);
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0x61, 0xFC, 0x40, _I_DOMAIN_CRC) << 5));

    //Digital Filter For NEW Phase
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Disable Digital Filter
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Y/Pb/Pr Function Disable //Initial Value=0
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x00); // Disable Digital Filter
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Digital Filter Coefficient
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xF0); 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x10); // Enable Phase subFunction
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x80); 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x90); // Set Old Phase Threshold 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x32); 
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

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x11);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x80); // New Phase Mode EN  
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x21);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x1E); // Threshold Of R  
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x31);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x05); // Offset Of R  
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x41);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x19); // Gain Of R  

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x51);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x50); // Threshold Of G  
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x61);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x07); // Offset Of G  
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x71);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x05); // Gain Of G  

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x81);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x01); // Threshold Of B  
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x91);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x01); // Offset Of B  
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0xA1);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xFF); // Gain Of B  

    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_6", 0x00);  // Double Side + Double Gain
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0xCA, 0x30, 0xDB, _I_DOMAIN_CRC) << 6));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x11);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xC0); // Single Side + Double Gain
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_7", 0x00);
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0x86, 0xBB, 0xB8, _I_DOMAIN_CRC) << 7));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x11);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xA0); // Double Side + Single Gain
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_8", 0x00);
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0xAE, 0x6D, 0x92, _I_DOMAIN_CRC) << 8));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x11);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xE0); // Single Side + Single Gain
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_9", 0x00);
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0xBA, 0x29, 0x94, _I_DOMAIN_CRC) << 9));

    
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Disable Digital Filter
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Y/Pb/Pr Function Disable //Initial Value=0
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x00); // Disable Digital Filter
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Digital Filter Coefficient
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xF0); 
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x10); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x80); // Enable Phase subFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x20); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x90); // Enable negative semar sunFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x30); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xA4); // Enable positive semar sunFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x40); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xB8); // Enable negative ringing subFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x50); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xBC); // Enable positive ringing subFunction (0xd0:80   0xb0:48)
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x60); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x80); // Enable mismatch subFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x80); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xE0); // Enable Noise Reduction subFunction

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x04); // only reduce ringing condition

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x11);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x80); // New Phase Mode EN  
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_10", 0x00);  // Double Side + Double Gain + other function   
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0xBD, 0x7D, 0x02, _I_DOMAIN_CRC) << 10));

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x00); // disable Two condition occur continuous (ringing to smear)

    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x11);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xA0);
    
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x81);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x10); // Threshold Of B  
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_11", 0x00);  // Double Side + Single Gain + other function   
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0x66, 0x2C, 0x5D, _I_DOMAIN_CRC) << 11));
   
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x40); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Enable negative ringing subFunction
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x50); 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Enable positive ringing subFunction (0xd0:80   0xb0:48)
    
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x11);                                                                 
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0xC0); // Single Side + Double Gain + other function
    
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. Mode_12", 0x00);  // Double Side + Double Gain + other function   
    usData = (usData | ((WORD)ScalerQCCheckCRCOn(0xA4, 0x51, 0x26, _I_DOMAIN_CRC) << 12));
    
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x70); // Disable Digital Filter
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT,0x00); // Y/Pb/Pr Function Disable //Initial Value=0
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL,0x00); // Disable Digital Filter
               
    ScalerQCIDomainRandomGenOff();   
    ScalerQCCheckCRCOff();   

    DebugMessageScaler("5. Digital Filter End", 0x00);       
    
    if(usData == 0x0000)
    {
        DebugMessageScaler("6. Digital Filter PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", usData);
        DebugMessageScaler("6. Digital Filter FAIL", 0x00);
        return _TEST_FAIL;
    }       
}

//----------------------------------------------------------------------------
// Color Conversion Test
//----------------------------------------------------------------------------
bit ScalerQCColorConversionTest(void)
{
    BYTE ucResult = _TEST_PASS;
    BYTE ucBackup0x14A1 = 0;

    DebugMessageScaler("5. Color Conversion Start", 0x00);

    // Backup register 0x14A1, which will be used here
    ucBackup0x14A1 = ScalerGetByte(P14_A1_SR_YCC2RGB_CTRL);

    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);

    // Enable YUV2RGB_D Conversion
    ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
    
    // K11 high
    ScalerSetByte(P14_A2_YUB_RGB_COEF_K11_HSB, 0x04);
    // K11 low
    ScalerSetByte(P14_A3_YUV_RGB_COEF_K11_LSB, 0xA8);
    // K13 high
    ScalerSetByte(P14_A4_YUV_RGB_COEF_K13_HSB, 0x06);
    // K13 low
    ScalerSetByte(P14_A5_YUV_RGB_COEF_K13_LSB, 0x87);
    // K22 high
    ScalerSetByte(P14_A6_YUV_RGB_COEF_K22_HSB, 0x01);
    // K22 low
    ScalerSetByte(P14_A7_YUV_RGB_COEF_K22_LSB, 0x91);
    // K23 high
    ScalerSetByte(P14_A8_YUV_RGB_COEF_K23_HSB, 0x03);
    // K23 low
    ScalerSetByte(P14_A9_YUV_RGB_COEF_K23_LSB, 0x40);
    // K32 high
    ScalerSetByte(P14_AA_YUV_RGB_COEF_K32_HSB, 0x08);
    // K32 low
    ScalerSetByte(P14_AB_YUV_RGB_COEF_K32_LSB, 0x11);
    // R offset high
    ScalerSetByte(P14_AC_YUV_RGB_R_OFFSET_HSB, 0x0E);
    // R offset low
    ScalerSetByte(P14_AD_YUV_RGB_R_OFFSET_LSB, 0x0A);
    // G offset high
    ScalerSetByte(P14_AE_YUV_RGB_G_OFFSET_HSB, 0x0A);
    // G offset low
    ScalerSetByte(P14_AF_YUV_RGB_G_OFFSET_LSB, 0x92);
    // B offset high
    ScalerSetByte(P14_B0_YUV_RGB_B_OFFSET_HSB, 0x11);
    // B offset low
    ScalerSetByte(P14_B1_YUV_RGB_B_OFFSET_LSB, 0x18);
    // R gain high
    ScalerSetByte(P14_B2_YUV_RGB_R_GAIN_HSB, 0x00);
    // R gain low
    ScalerSetByte(P14_B3_YUV_RGB_R_GAIN_LSB, 0xB9);
    // G gain high
    ScalerSetByte(P14_B4_YUV_RGB_G_GAIN_HSB, 0x00);
    // G gain low
    ScalerSetByte(P14_B5_YUV_RGB_G_GAIN_LSB, 0xDA);
    // B gain high
    ScalerSetByte(P14_B6_YUV_RGB_B_GAIN_HSB, 0x00);
    // B gain low
    ScalerSetByte(P14_B7_YUV_RGB_B_GAIN_LSB, 0xA2);


    //////////////////////////////////////////////////////////////////
    // case 0: YUV->RGB, enable Y Clamp, enable CbCr Clamp, D Dither MSB
    ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1), (_BIT2 | _BIT1));
    ScalerQCDDitherOn(_MSB);
    
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageScaler("5. Mode_0", 0x00);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0x4E, 0x22, 0xD4, _D_DOMAIN_CRC));

    //////////////////////////////////////////////////////////////////
    // case 1: YUV->RGB, enable Y Clamp, enable CbCr Clamp, D Dither LSB
    ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1), (_BIT2 | _BIT1));
    ScalerQCDDitherOn(_LSB);
    
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageScaler("5. Mode_1", 0x00);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0xF4, 0x66, 0x5E, _D_DOMAIN_CRC) << 1);
    ScalerQCDDitherOff();
    
    //////////////////////////////////////////////////////////////////
    // case 2: YUV->RGB, enable Y Clamp, enable CbCr Clamp, enable Y_Signed
    ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT2 | _BIT1));

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageScaler("5. Mode_2", 0x00);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0x3E, 0x87, 0x69, _D_DOMAIN_CRC) << 2);

    //////////////////////////////////////////////////////////////////
    // case 3: YUV->RGB, enable CbCr Clamp
    ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT2);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageScaler("5. Mode_3", 0x00);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0xA6, 0xE3, 0xEA, _D_DOMAIN_CRC) << 3);

    // Recover register 0x14A1
    ScalerSetByte(P14_A1_SR_YCC2RGB_CTRL, ucBackup0x14A1);

    ScalerQCDDitherOff();
    ScalerQCDDomainPatternGenOff();
    ScalerQCCheckCRCOff();

    DebugMessageScaler("5. Color Conversion End", 0x00);
    if(ucResult == 0)
    {
        DebugMessageScaler("6. Color Conversion PASS", 0x00);
        return _TEST_PASS;        
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucResult);
        DebugMessageScaler("6. Color Conversion FAIL", 0x00);
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
    ScalerBurstWrite(tQC_IDITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
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
    ScalerQCIDomainRandomGenOff();

    DebugMessageScaler("5. I Dither End", 0x00);    
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. I Dither PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. I Dither FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : ScaleUp Test 
// Input Value  : None
// Output Value : TEST_PASS/TEST_FAIL
//--------------------------------------------------
bit ScalerQCScaleUpTest(void)
{
    BYTE ucData = 0;
    BYTE ucI = 0;
    BYTE ucFlag = 0;
    DebugMessageScaler("5. Scale Up Start", 0x00);
    
    ScalerQCIDomainRandomGenOn(_MASS);
   
    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT4, 0x00);   
       
    ScalerSetByte(P1_C6_DCLK_SPREAD_SPECTRUM, 0x04);// Display LVDS expread spectrum

    // 2D 3Line VSU
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0x44);

    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6), _BIT7);
    
    ScalerBurstWrite(tQC_SU_COEF_4L_2, 128, GET_CURRENT_BANK_NUMBER(), CM_36_FILTER_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);

    ScalerBurstWrite(tQC_SU_COEF_3L_2, 128, GET_CURRENT_BANK_NUMBER(), CM_36_FILTER_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6), 0x00);
     
    DebugMessageScaler("5. Mode_0", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xD2, 0xAB, 0xC0, _D_DOMAIN_CRC) << 2));    

    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);  
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xC4);
    ScalerSetByte(P1_C6_DCLK_SPREAD_SPECTRUM, (_DCLK_SPREAD_RANGE << 4 ) | _BIT2);// Display LVDS expread spectrum    
       
    ScalerQCIDomainRandomGenOff();   
    ScalerQCCheckCRCOff();   

    DebugMessageScaler("5. Scale Up End", 0x00);      
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. Scale Up PASS", 0x00);    
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. Scale Up FAIL", 0x00);    
        return _TEST_FAIL;
    }            
}

//--------------------------------------------------
// Description  : Highlight Window
// Input Value  : None
// Output Value : None
//--------------------------------------------------    
bit ScalerQCHLWTest(void)
{
    BYTE ucData = 0;

    DebugMessageScaler("5. Highlight Window Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerQCHighlightWindowOn();

    // RandomGen + HLW(Four border);
    DebugMessageScaler("5. Mode_0", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x20, 0x82, 0x9A, _D_DOMAIN_CRC) << 0));

    // RandomGen + HLW(Bottom & Right border);
    DebugMessageScaler("5. Mode_1", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xCA, 0xF1, 0x33, _D_DOMAIN_CRC) << 1));

    // RandomGen + HLW(Top & Right border);
    DebugMessageScaler("5. Mode_2", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT4));
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x0F, 0x24, 0xD2, _D_DOMAIN_CRC) << 2));

    // RandomGen + HLW(Top & Left border);
    DebugMessageScaler("5. Mode_3", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x08, 0xDD, 0x2A, _D_DOMAIN_CRC) << 3));

    // RandomGen + HLW(Bottom & Left border);
    DebugMessageScaler("5. Mode_4", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x81, 0x33, 0x62, _D_DOMAIN_CRC) << 4));

    ScalerQCIDomainRandomGenOff();
    ScalerQCHighlightWindowOff();

    DebugMessageScaler("5. Highlight Window End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. Highlight Window PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. Highlight Window FAIL", 0x00);
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

    // Random  
    ScalerQCDDomainRandomGenOn(_MASS); // 
    DebugMessageScaler("5. D PG Case_0", ucError);
    ucError = (BYTE)ScalerQCCheckCRCOn(0x41, 0xF9, 0x6D, _D_DOMAIN_CRC); 


    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    
    ScalerQCDDitherOn(_LSB);  // 10bit LSB
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. D PG Case_1", ucError);
    ucError |= ((BYTE)ScalerQCCheckCRCOn(0xA2, 0xDC, 0x83, _D_DOMAIN_CRC) << 1); 
    
    ScalerQCDDitherOff();

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    
    ScalerQCDDomainRandomGenOn(_GRAY); 
    DebugMessageScaler("5. D PG Case_2", ucError);
    ucError |= ((BYTE)ScalerQCCheckCRCOn(0xB8, 0x2F, 0xBB, _D_DOMAIN_CRC) << 2); 

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    // Pattern Gen
    ScalerQCDDomainPatternGenOn();    
    DebugMessageScaler("5. D PG Case_3", ucError);
    ucError |= ((BYTE)ScalerQCCheckCRCOn(0xD2, 0x5A, 0x4A, _D_DOMAIN_CRC) << 3); 
    
    
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

 
    ScalerQCDDitherOn(_LSB);  // 10bit LSB
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. D PG Case_4", ucError);
    ucError |= ((BYTE)ScalerQCCheckCRCOn(0x9D, 0xB3, 0xEB, _D_DOMAIN_CRC) << 4); 

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
    ScalerSetByte(P7_FB_DISP_PG_RANDOM_CTRL, 0x00);
    ScalerSetByte(P7_FC_DISP_PG_INITIAL_LSB, 0x36);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. D PG Case_5", ucError);
    ucError = ucError|((BYTE)ScalerQCCheckCRCOn(0x29, 0xD4, 0x5f, _D_DOMAIN_CRC) << 5);  

 
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
    ScalerSetByte(P7_FB_DISP_PG_RANDOM_CTRL, 0x00);
    ScalerSetByte(P7_FC_DISP_PG_INITIAL_LSB, 0x1D);

    
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. D PG Case_6", ucError);
    ucError = ucError|((BYTE)ScalerQCCheckCRCOn(0x59, 0xE1, 0x0B,  _D_DOMAIN_CRC) << 6);  // Wendy add 20120914
    

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
    ScalerSetByte(P7_FB_DISP_PG_RANDOM_CTRL, 0x00);
    ScalerSetByte(P7_FC_DISP_PG_INITIAL_LSB, 0x03F);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. D PG Case_7", ucError);
    ucError = ucError|((BYTE)ScalerQCCheckCRCOn(0xE3, 0xFF, 0x7D, _D_DOMAIN_CRC) << 7); 


    ScalerQCDDomainPatternGenOff();

    DebugMessageScaler("5. D Domain PG End", 0x00);
    if(ucError == 0)
    {
        DebugMessageScaler("6. D Domain PG PASS", 0x00);
        return _TEST_PASS;
        
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucError);
        DebugMessageScaler("6. D Domain PG FAIL", 0x00);
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
    ScalerQCDDomainRandomGenOn(_MASS); 
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

    ScalerSetByte(P7_C7_DCC_CTRL0, 0x90);
    ScalerSetByte(P7_C8_DCC_CTRL1, 0x80);

    // RandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x05, 0x2C, 0x7E, _D_DOMAIN_CRC) << 0));

    // RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2);
    // Fill DCC control table
    // Select page0
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x0B);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x28);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_DCC_SETTING2, 9, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Fill DCC user curve table
    // Select page1
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1|_BIT0), _PAGE1);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerBurstWrite(&tQC_DCC_SETTING2[9], 23, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_C7_DCC_CTRL0, 0xE4);
    ScalerSetByte(P7_C8_DCC_CTRL1, 0xB0);
    DebugMessageScaler("5. Mode_1", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x55, 0x8D, 0x1D, _D_DOMAIN_CRC) << 1));
     
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3);
    // Fill DCC control table
    // Select page0
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x03);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_DCC_SETTING3, 9, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Fill DCC user curve table
    // Select page1
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1|_BIT0), _PAGE1);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerBurstWrite(&tQC_DCC_SETTING3[9], 23, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_C7_DCC_CTRL0, 0x84);
    ScalerSetByte(P7_C8_DCC_CTRL1, 0xB0);
    DebugMessageScaler("5. Mode_2", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x59, 0x06, 0x2A, _D_DOMAIN_CRC) << 2));

    // RandomGen + HLW(_IN/OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0x00);
    // Fill DCC control table
    // Select page0
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x38);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_DCC_SETTING4, 9, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Fill DCC user curve table
    // Select page1
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1|_BIT0), _PAGE1);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerBurstWrite(&tQC_DCC_SETTING4[9], 23, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_C7_DCC_CTRL0, 0x94);
    ScalerSetByte(P7_C8_DCC_CTRL1, 0xB0);
    DebugMessageScaler("5. Mode_3", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2B, 0x23, 0xD9, _D_DOMAIN_CRC) << 3));
    
    ScalerQCHighlightWindowOff();
    ScalerQCDDitherOn(_LSB);

    // Fill DCC control table
    // Select page0
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x5C);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_DCC_SETTING5, 9, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Fill DCC user curve table
    // Select page1
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1|_BIT0), _PAGE1);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerBurstWrite(&tQC_DCC_SETTING5[9], 23, GET_CURRENT_BANK_NUMBER(), P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_C7_DCC_CTRL0, 0xE0);
    ScalerSetByte(P7_C8_DCC_CTRL1, 0x90);

    // D_RandomGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFD, 0x23, 0xA4, _D_DOMAIN_CRC) << 4));
    // D_RandomGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2);
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x0B);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x1C);
    DebugMessageScaler("5. Mode_5", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEF, 0xEC, 0x91, _D_DOMAIN_CRC) << 5));
    // D_RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3);
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0xFF);
    DebugMessageScaler("5. Mode_6", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x94, 0xB2, 0xDF, _D_DOMAIN_CRC) << 6));
    // D_RandomGen + HLW(_IN/OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0x00);
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x5C);
    DebugMessageScaler("5. Mode_7", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x91, 0xF0, 0x4C, _D_DOMAIN_CRC) << 7));

    ScalerSetBit(P7_C7_DCC_CTRL0, ~_BIT7, 0x00);                   // Disable DCC
    ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCCheckCRCOff();   

    DebugMessageScaler("5. DCC End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. DCC PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. DCC FAIL", 0x00);
        return _TEST_FAIL;
    }       
}
//YiZhu add start
//--------------------------------------------------
// Description  : YPeaking Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCYPeakingTest(void)
{
    BYTE ucData = 0;

    DebugMessageScaler("5. YPeaking Start", 0x00);
    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);

    ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_00_PEAKING_COEF0, 0x7E);
    ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_01_PEAKING_COEF1, 0xD2);
    ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_02_PEAKING_COEF2, 0xC1);
    ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_03_PEAKING_MIN, 0x1F);
    ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_04_PEAKING_MAX_POS, 0x25);
    ScalerSetDataPortByte(P7_D6_PKING_ACCESS_PORT, _P7_D7_PT_05_PEAKING_MAX_REG, 0xE3);


    ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~(_BIT7 |  _BIT5 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT6, _BIT6);              // Enable YPeaking & coring

    // RandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x6E, 0x87, 0xD2, _D_DOMAIN_CRC) << 0));

    // RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT1 | _BIT0), _BIT0);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF8, 0xAD, 0x3B, _D_DOMAIN_CRC) << 1));

    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT5, _BIT5);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT1 | _BIT0), _BIT1);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x57, 0xEC, 0x3E, _D_DOMAIN_CRC) << 2));


    ScalerQCHighlightWindowOff();

    ScalerQCDDitherOn(_LSB);

    // PatternGen + DDither(_LSB)
    ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT5, 0x00);
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFD, 0xBC, 0x95, _D_DOMAIN_CRC) << 3));

    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT1 | _BIT0), _BIT0);
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF9, 0x87, 0x8D, _D_DOMAIN_CRC) << 4));

    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT5, _BIT5);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT1 | _BIT0), _BIT1);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xBE, 0x31, 0x08, _D_DOMAIN_CRC) << 5));	

    ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~(_BIT6 | _BIT5), 0x00);           // Disable Ypeaking & coring
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

//YiZhu add end
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
	ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT3, _BIT3);
	ScalerQCDDomainRandomGenOn(_MASS);
 
    // Fill DCR table
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);                   
    ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x09);     
 
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x04);                   
    ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x95);     
 
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);                    
 
    // RandomGen
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. Mode_0", 0x00);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    

    if((pData[0]!=0x09) || (pData[1]!=0x95) || (pData[2]!=0x1A) || (pData[3]!=0xE7) || (pData[4]!=0x31) || (pData[5]!=0x28) || (pData[6]!=0x46) ||
       (pData[7]!=0xB2) || (pData[8]!=0x65) || (pData[9]!=0x01) || (pData[10]!=0x5B) || (pData[11]!=0x6A) || (pData[12]!=0x03) || (pData[13]!=0x62) ||
       (pData[14]!=0x50) || (pData[15]!=0xE1) || (pData[16]!=0xFF) || (pData[17]!=0xFF) || (pData[18]!=0xFF) || (pData[19]!=0xFF) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0xFF) || (pData[23]!=0xFF) || (pData[24]!=0xFF) || (pData[25]!=0xFF) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0xFF) || (pData[29]!=0xFF) || (pData[30]!=0xFF) || (pData[31]!=0xFF) || (pData[32]!=0xFF) || (pData[33]!=0x00))
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

    if((pData[0]!=0x09) || (pData[1]!=0x95) || (pData[2]!=0x1A) || (pData[3]!=0xE7) || (pData[4]!=0x31) || (pData[5]!=0x28) || (pData[6]!=0x46) ||
       (pData[7]!=0xB2) || (pData[8]!=0x65) || (pData[9]!=0x01) || (pData[10]!=0x5B) || (pData[11]!=0x6A) || (pData[12]!=0x03) || (pData[13]!=0x62) ||
       (pData[14]!=0x50) || (pData[15]!=0xE1) || (pData[16]!=0xFF) || (pData[17]!=0xFF) || (pData[18]!=0xFF) || (pData[19]!=0xFF) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0xFF) || (pData[23]!=0xFF) || (pData[24]!=0xFF) || (pData[25]!=0xFF) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0xFF) || (pData[29]!=0xFF) || (pData[30]!=0xFF) || (pData[31]!=0xFF) || (pData[32]!=0xFF) || (pData[33]!=0x00))
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

    if((pData[0]!=0x09) || (pData[1]!=0x95) || (pData[2]!=0x05) || (pData[3]!=0x2A) || (pData[4]!=0x7E) || (pData[5]!=0x07) || (pData[6]!=0xB9) ||
       (pData[7]!=0x94) || (pData[8]!=0xB2) || (pData[9]!=0x00) || (pData[10]!=0x42) || (pData[11]!=0xA0) || (pData[12]!=0x00) || (pData[13]!=0xA6) ||
       (pData[14]!=0x15) || (pData[15]!=0x63) || (pData[16]!=0x52) || (pData[17]!=0xED) || (pData[18]!=0x52) || (pData[19]!=0xAD) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0x53) || (pData[23]!=0x0E) || (pData[24]!=0x52) || (pData[25]!=0xC7) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0x53) || (pData[29]!=0x21) || (pData[30]!=0x52) || (pData[31]!=0xD8) || (pData[32]!=0xFF) || (pData[33]!=0x00))
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

    if((pData[0]!=0x09) || (pData[1]!=0x95) || (pData[2]!=0x15) || (pData[3]!=0x30) || (pData[4]!=0xD6) || (pData[5]!=0x1F) || (pData[6]!=0xBC) ||
       (pData[7]!=0x37) || (pData[8]!=0x53) || (pData[9]!=0x01) || (pData[10]!=0x11) || (pData[11]!=0x9C) || (pData[12]!=0x02) || (pData[13]!=0xAA) ||
       (pData[14]!=0x50) || (pData[15]!=0x5C) || (pData[16]!=0xFF) || (pData[17]!=0xFF) || (pData[18]!=0xFF) || (pData[19]!=0xFF) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0xFF) || (pData[23]!=0xFF) || (pData[24]!=0xFF) || (pData[25]!=0xFF) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0xFF) || (pData[29]!=0xFF) || (pData[30]!=0xFF) || (pData[31]!=0xFF) || (pData[32]!=0xFF) || (pData[33]!=0x00))
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
    
    // D_RandomGen 
	ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT3, 0x00);
    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);                   
    ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x08);     
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x04);                   
    ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x60);     
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. Mode_4", 0x00);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    

    if((pData[0]!=0x08) || (pData[1]!=0x60) || (pData[2]!=0x1A) || (pData[3]!=0xE8) || (pData[4]!=0x37) || (pData[5]!=0x28) || (pData[6]!=0x46) ||
       (pData[7]!=0xD4) || (pData[8]!=0xBA) || (pData[9]!=0x0D) || (pData[10]!=0x6D) || (pData[11]!=0x4D) || (pData[12]!=0x19) || (pData[13]!=0x91) ||
       (pData[14]!=0x1D) || (pData[15]!=0xFF) || (pData[16]!=0xFF) || (pData[17]!=0xFF) || (pData[18]!=0xFF) || (pData[19]!=0xFF) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0xFF) || (pData[23]!=0xFF) || (pData[24]!=0xFF) || (pData[25]!=0xFF) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0xFF) || (pData[29]!=0xFF) || (pData[30]!=0xFF) || (pData[31]!=0xFF) || (pData[32]!=0xFF) || (pData[33]!=0x00))
    {
    	    ucData= ucData | _BIT4;
    	    DebugMessageScaler("5. ===Fail===",0x00);
    }
    else
    {
        DebugMessageScaler("5. ===Pass===",0x00);
    }

    // D_RandomGen + HLW(_IN/OUTSIDE_WINDOW)
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

    if((pData[0]!=0x08) || (pData[1]!=0x60) || (pData[2]!=0x1A) || (pData[3]!=0xE8) || (pData[4]!=0x37) || (pData[5]!=0x28) || (pData[6]!=0x46) ||
       (pData[7]!=0xD4) || (pData[8]!=0xBA) || (pData[9]!=0x0D) || (pData[10]!=0x6D) || (pData[11]!=0x4D) || (pData[12]!=0x19) || (pData[13]!=0x91) ||
       (pData[14]!=0x1D) || (pData[15]!=0xFF) || (pData[16]!=0xFF) || (pData[17]!=0xFF) || (pData[18]!=0xFF) || (pData[19]!=0xFF) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0xFF) || (pData[23]!=0xFF) || (pData[24]!=0xFF) || (pData[25]!=0xFF) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0xFF) || (pData[29]!=0xFF) || (pData[30]!=0xFF) || (pData[31]!=0xFF) || (pData[32]!=0xFF) || (pData[33]!=0x00))
    {
    	    ucData= ucData | _BIT5;
    	    DebugMessageScaler("5. ===Fail===",0x00);
    }
    else
    {
        DebugMessageScaler("5. ===Pass===",0x00);
    }
    
    // D_RandomGen + HLW(_INSIDE_WINDOW)
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);
    DebugMessageScaler("5. Mode_6", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x02);  
    ScalerRead(P7_D9_DCR_DATA_PORT, 34, pData, _NON_AUTOINC);    

    if((pData[0]!=0x08) || (pData[1]!=0x60) || (pData[2]!=0x05) || (pData[3]!=0x2A) || (pData[4]!=0xA7) || (pData[5]!=0x07) || (pData[6]!=0xB9) ||
       (pData[7]!=0x9A) || (pData[8]!=0x0F) || (pData[9]!=0x02) || (pData[10]!=0x92) || (pData[11]!=0x36) || (pData[12]!=0x04) || (pData[13]!=0xE4) ||
       (pData[14]!=0x93) || (pData[15]!=0x44) || (pData[16]!=0x52) || (pData[17]!=0xED) || (pData[18]!=0x52) || (pData[19]!=0xAD) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0x53) || (pData[23]!=0x0E) || (pData[24]!=0x52) || (pData[25]!=0xC7) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0x53) || (pData[29]!=0x21) || (pData[30]!=0x52) || (pData[31]!=0xD8) || (pData[32]!=0xFF) || (pData[33]!=0x00))
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

    if((pData[0]!=0x08) || (pData[1]!=0x60) || (pData[2]!=0x15) || (pData[3]!=0x31) || (pData[4]!=0xAF) || (pData[5]!=0x1F) || (pData[6]!=0xBC) ||
       (pData[7]!=0x53) || (pData[8]!=0xC4) || (pData[9]!=0x0A) || (pData[10]!=0x95) || (pData[11]!=0xC7) || (pData[12]!=0x14) || (pData[13]!=0x28) ||
       (pData[14]!=0x71) || (pData[15]!=0x61) || (pData[16]!=0xFF) || (pData[17]!=0xFF) || (pData[18]!=0xFF) || (pData[19]!=0xFF) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0xFF) || (pData[23]!=0xFF) || (pData[24]!=0xFF) || (pData[25]!=0xFF) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0xFF) || (pData[29]!=0xFF) || (pData[30]!=0xFF) || (pData[31]!=0xFF) || (pData[32]!=0xFF) || (pData[33]!=0x00))
    {
    	    ucData= ucData | _BIT7;
    	    DebugMessageScaler("5. ===Fail===",0x00);
    }
    else
    {
        DebugMessageScaler("5. ===Pass===",0x00);
    }

    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);    	           // Disable DCR Messure
    ScalerQCDDomainPatternGenOff();
    ScalerQCHighlightWindowOff();

    DebugMessageScaler("5. DCR End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. DCR PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. DCR FAIL", 0x00);
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
    WORD usError = 0;
    
    DebugMessageScaler("5. ICM Start", 0x00);

    // Old ICM
    // Random + MSB
    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);

    ScalerSetByte(P7_D1_ICM_SEL, 0x00);                // CM0 Block0
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify0, 51, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x67);
    ScalerBurstWrite(&tQC_ICM_Modify0[51], 8, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x01);                // CM1
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify1, 51, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x67);
    ScalerBurstWrite(&tQC_ICM_Modify1[51], 8, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x02);                // CM2
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify2, 51, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x67);
    ScalerBurstWrite(&tQC_ICM_Modify2[51], 8, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x03);                // CM3
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify3, 51, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x67);
    ScalerBurstWrite(&tQC_ICM_Modify3[51], 8, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x04);                // CM4
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify4, 51, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x67);
    ScalerBurstWrite(&tQC_ICM_Modify4[51], 8, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x05);                // CM5
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify5, 51, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x67);
    ScalerBurstWrite(&tQC_ICM_Modify5[51], 8, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    //dy = (8dU+dV)/8,delta = -256~255
    ScalerSetByte(P7_D0_ICM_CTRL,  0xBF);          // Enable CM0~CM4
    ScalerSetBit(P7_D1_ICM_SEL, ~_BIT3, _BIT3);    //Enable CM5
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~_BIT7, _BIT7);   
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_0", usError);
    usError = (WORD)ScalerQCCheckCRCOn(0xFE, 0x63, 0x4A, _D_DOMAIN_CRC); 

    //dy = (6dU+dV)/8,delta = -256~254, 
    ScalerSetByte(P7_D0_ICM_CTRL,  0xDF); 
    ScalerSetBit(P7_D1_ICM_SEL, ~_BIT4, _BIT4);    //delta UV *4
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~_BIT7, 0x00); 
    ScalerSetBit(P7_D4_ICM_NEW_MODE, ~_BIT0, _BIT0);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_1", usError);
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x25, 0xEC, 0x7B, _D_DOMAIN_CRC) << 1);   
            
    // Random + Highlight Window + MSB  Full Window   
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 full window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_2", usError);
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x78, 0x67, 0xCD, _D_DOMAIN_CRC) << 2);     
      
    // Random + Highlight Window + MSB  Inside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_3", usError); 
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x27, 0x34, 0xE9, _D_DOMAIN_CRC) << 3);    

    // Random + Highlight Window + MSB  Outside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3); // 10 outside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_4", usError); 
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x61, 0xD1, 0x95, _D_DOMAIN_CRC) << 4);   
      
    // D_Random + Highlight Window + LSB Outside Window
    ScalerQCDDitherOn(_LSB);
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. ICM Case_5", usError);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0xA0, 0x7A, 0x7D, _D_DOMAIN_CRC) << 5);

    // D_Random + HW + LSB  Inside Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    DebugMessageScaler("5. ICM Case_6", usError);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x3E, 0x93, 0xA0, _D_DOMAIN_CRC) << 6);

    // D_Random + HW + LSB  Full Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 Full window
    DebugMessageScaler("5. ICM Case_7", usError);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0xC4, 0xF5, 0x9D, _D_DOMAIN_CRC) << 7);

    // Disable ICM CM    
    ScalerSetByte(P7_D0_ICM_CTRL, 0x80);  
    ScalerSetByte(P7_D1_ICM_SEL,  0x00); 
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT,  0x00);

    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();

    // New ICM
    // Random + MSB
    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);
       
    ScalerSetByte(P7_D0_ICM_CTRL, 0x00);  
    ScalerSetByte(P7_D1_ICM_SEL,  0x00); 
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT,  0x00);

    ScalerSetByte(P7_D1_ICM_SEL, 0x00);                // CM0
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);    
    ScalerBurstWrite(tQC_New_ICM_Modify0, sizeof(tQC_New_ICM_Modify0), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x01);                // CM1
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify1, sizeof(tQC_New_ICM_Modify1), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x02);                // CM2
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify2, sizeof(tQC_New_ICM_Modify2), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x03);                // CM3
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify3, sizeof(tQC_New_ICM_Modify3), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x04);                // CM4
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify4, sizeof(tQC_New_ICM_Modify4), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x05);                // CM5
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify5, sizeof(tQC_New_ICM_Modify5), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    //dy = (8dU+dV)/8,delta = -256~255 
    ScalerSetByte(P7_D0_ICM_CTRL,  0xFF);         // Enable CM0~CM4
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT3 | _BIT4), _BIT3 | _BIT4);   //Enable CM5
    ScalerSetByte(P7_D4_ICM_NEW_MODE, 0x07);      // Enable New ICM Mode, buffer offset == 1,Max Compensate on
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_0", usError);
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0xD0, 0x1B, 0xE3, _D_DOMAIN_CRC) << 8);

    //dy = (6dU+dV)/8,delta = -256~255, Neg Compensate off,     
    ScalerSetByte(P7_D0_ICM_CTRL,  0xBF); 
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_1", usError);
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0xD0, 0x1B, 0xE3, _D_DOMAIN_CRC) << 8);
              
    // Random + Highlight Window   
    ScalerQCHighlightWindowOn();

    // Random + Highlight Window + MSB  Full
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 full window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_2", usError);
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x77, 0x00, 0x2A, _D_DOMAIN_CRC) << 10);

    // Random + Highlight Window + MSB  Inside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_3", usError); 
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x0B, 0x5C, 0xC7, _D_DOMAIN_CRC) << 11);    

    // Random + Highlight Window + MSB  Outside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3); // 10 outside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_4", usError);
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x42, 0xDE, 0x5C, _D_DOMAIN_CRC) << 12);      

    // D_Random + Highlight Window + LSB Outside Window
    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_LSB);
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. New ICM Case_5", usError);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x27, 0x67, 0x61, _D_DOMAIN_CRC) << 13);

    // D_Random + HW + LSB  Inside Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    DebugMessageScaler("5. New ICM Case_6", usError);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0x91, 0x03, 0xD6, _D_DOMAIN_CRC) << 14);

    // D_Random + HW + LSB  Full Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 Full window
    DebugMessageScaler("5. New ICM Case_7", usError);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    usError = usError | ((WORD)ScalerQCCheckCRCOn(0xEC, 0x78, 0xF7, _D_DOMAIN_CRC) << 15);

    // Disable ICM
    ScalerSetBit(P7_D1_ICM_SEL,  ~(_BIT3), 0x00); 
    ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT4|_BIT3|_BIT2|_BIT1|_BIT0), 0x00);   
    ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT7), 0x00);     

    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCDDomainPatternGenOff();
    ScalerQCCheckCRCOff();      

      DebugMessageScaler("5. ICM End", 0x00);
    
    if(usError == 0)
    {
        DebugMessageScaler("6. ICM PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", usError);
        DebugMessageScaler("6. ICM FAIL", 0x00);
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
    ScalerBurstWrite(tQC_CON_BRI_SETTING, 32, GET_CURRENT_BANK_NUMBER(), CM_65_CB_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));              // Enable Contrast & Brightness
    // RandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xC3, 0x31, 0x50, _D_DOMAIN_CRC) << 0));
    // RandomGen + HLW(_IN(A)/OUTSIDE(A)_WINDOW + Bottom&Right border) + DDither(_MSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), 0x00);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x7D, 0xA1, 0x6F, _D_DOMAIN_CRC) << 1));
    // RandomGen + HLW(_INSIDE(B)_WINDOW + Top&Left border) + DDither(_MSB)
    ScalerQCHighlightWindowOn();
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x76, 0x42, 0x76, _D_DOMAIN_CRC) << 2));
    // RandomGen + HLW(_OUTSIDE(A)_WINDOW + Bottom&Left border) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xD4, 0x7F, 0x6A, _D_DOMAIN_CRC) << 3));
    // RandomGen + HLW(_IN(B)/OUTSIDE(A)_WINDOW + Top&Right border) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x33, 0x93, 0x76, _D_DOMAIN_CRC) << 4));
    
    ScalerQCHighlightWindowOff();
    ScalerQCIDomainRandomGenOff();

    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_LSB);
    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x20, 0x8A, 0x89, _D_DOMAIN_CRC) << 0));  //Ryan for 6247 Con/Bri QC D-domain RandomGen
    // PatternGen + HLW(_IN(A)/OUTSIDE(A)_WINDOW + Bottom&Right border) + DDither(_LSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), 0x00);
    DebugMessageScaler("5. Mode_6", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xA7, 0x22, 0x28, _D_DOMAIN_CRC) << 1));  //Ryan for 6247 Con/Bri QC D-domain RandomGen
    // PatternGen + HLW(_INSIDE(B)_WINDOW + Top&Left border) + DDither(_LSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_7", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEF, 0xE6, 0x6C, _D_DOMAIN_CRC) << 2));    //Ryan for 6247 Con/Bri QC D-domain RandomGen
    // PatternGen + HLW(_OUTSIDE(A)_WINDOW + Bottom&Left border) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_8", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xB8, 0xFD, 0xEA, _D_DOMAIN_CRC) << 3));  //Ryan for 6247 Con/Bri QC D-domain RandomGen
    // PatternGen + HLW(_IN(B)/OUTSIDE(A)_WINDOW + Top&Right border) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_9", 0x00);                     
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xBA, 0x1E, 0xEB, _D_DOMAIN_CRC) << 4));  //Ryan for 6247 Con/Bri QC D-domain RandomGen

    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT1 | _BIT0), 0x00);                   // Disable Contrast & Brightness
    ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCCheckCRCOff();   

    DebugMessageScaler("5. Contrast/Brightness End", 0x00);
    if(ucData == 0x00)
    {
       DebugMessageScaler("6. Contrast/Brightness PASS", 0x00);
       return _TEST_PASS;
    }
    else
    {
       DebugMessageScaler("6. Fail Mode", ucData);
       DebugMessageScaler("6. Contrast/Brightness FAIL", 0x00);
       return _TEST_FAIL;
    }       
}

//--------------------------------------------------
// Description  : Output Gamma Test 
// Input Value  : Gamma table type and gamma tables
// Output Value : _TEST_FAIL or _TEST_PASS
//--------------------------------------------------
bit ScalerQCGammaTest(void)
{
    BYTE ucData = 0;
    BYTE ucData1 = 0;

    DebugMessageScaler("5. Output Gamma Start", 0x00);    
    ScalerQCDDomainRandomGenOn(_MASS);  

    // Share one line buffer Start
    ScalerQCPCMAdjustSU(_ON); // 3L 
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x80);
    ScalerBurstWrite(&tOutputGammaR[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x90);
    ScalerBurstWrite(&tOutputGammaG[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0xA0);
    ScalerBurstWrite(&tOutputGammaB[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, 0x00); // Disable Access Port
    
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, _BIT6); // Enable Output Gamma
    
    DebugMessageScaler("5. GammaMode_00", 0x00);

    ucData1 =  (BYTE)ScalerQCCheckCRCOn(0x33, 0xD2, 0x62, _D_DOMAIN_CRC) << 0; // I-domain: 0x09, 0x79, 0xC8
   
    ScalerQCPCMAdjustSU(_OFF); // 4L  
    
    // Share one line buffer End
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x80);
    ScalerBurstWrite(&tOutputGammaR[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x90);
    ScalerBurstWrite(&tOutputGammaG[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0xA0);
    ScalerBurstWrite(&tOutputGammaB[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, 0x00); // Disable Access Port
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, _BIT6); // Enable Output Gamma

    ScalerQCDDitherOn(_MSB);
    
    // RandomGen + DDither(_MSB)
    DebugMessageScaler("5. GammaMode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x07, 0xEC, 0xFA, _D_DOMAIN_CRC) << 0)); // I-Random: 0xA9, 0xB1, 0x05, 

    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xBA, 0x05, 0xD0, _D_DOMAIN_CRC) << 1)); // I-Random:0x2F, 0x93, 0x65,
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xAE, 0xF3, 0xBD, _D_DOMAIN_CRC) << 2)); // I-Random:0x5B, 0x11, 0x88,
    // RandomGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2A, 0x74, 0xDC, _D_DOMAIN_CRC) << 3)); // I-Random:0x82, 0xF4, 0x9D,
    
    ScalerQCHighlightWindowOff();

    ScalerQCDDitherOn(_LSB);
    
    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x53, 0xD2, 0x4A, _D_DOMAIN_CRC) << 4)); // D domain 0x13, 0x16, 0xA1
    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xC0, 0x76, 0xF6, _D_DOMAIN_CRC) << 5));// D domain 0xEA, 0x85, 0xD4, 
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
    DebugMessageScaler("5. Mode_6", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xC4, 0x8A, 0x76, _D_DOMAIN_CRC) << 6));// D domain 0x77, 0x16, 0x4D,
    // PatternGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    DebugMessageScaler("5. Mode_7", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x5E, 0xE0, 0xC0, _D_DOMAIN_CRC) << 7));// D domain 0x1D, 0x5E, 0x2F, 
    
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, 0x00); // Disable Output Gamma
    ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCCheckCRCOff();

    DebugMessageScaler("5. Output Gamma End", 0x00);
    if((ucData == 0x00)&&(ucData1 == 0))
    {
        DebugMessageScaler("6. Output Gamma PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. Fail Mode1", ucData1);
        DebugMessageScaler("6. Output Gamma FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : sRGB Matrix Test 
// Input Value  : None
// Output Value : _TEST_FAIL or _TEST_PASS
//--------------------------------------------------
bit ScalerQCsRGBTest(void)
{
    BYTE ucData = 0;

    DebugMessageScaler("5. sRGB Start", 0x00);
    ScalerQCDDomainRandomGenOn(_MASS);
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x0D, 0x90, 0x8A, _D_DOMAIN_CRC) << 0)); // I-domain:0x8E, 0x5E, 0x5A,

    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2F, 0x2E, 0x08, _D_DOMAIN_CRC) << 1));  // Wendy add 20120914
    
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xD4, 0xE7, 0xB0, _D_DOMAIN_CRC) << 2)); // Wendy add 20120914
    
    // RandomGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xC5, 0x4B, 0x09, _D_DOMAIN_CRC) << 3)); // I-domain:0x8D, 0x13, 0x16,
    
    ScalerQCHighlightWindowOff();

    ScalerQCDDitherOn(_LSB);
    
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT6, _BIT6); // Bit Left Shift
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT6 | _BIT5), _BIT5); // 2-bit Shift-left

    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x31, 0xEC, 0x61, _D_DOMAIN_CRC) << 4)); // I-domain:0x97, 0x4C, 0xBB,
    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xCD, 0x3A, 0x82, _D_DOMAIN_CRC) << 5)); // Wendy add 20120914
    
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_6", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xB2, 0x2D, 0xB2, _D_DOMAIN_CRC) << 6)); // Wendy add 20120914
    
    // PatternGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_7", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x25, 0x0B, 0x70, _D_DOMAIN_CRC) << 7)); // I-domain:0x40, 0x7D, 0x74,
   
    // R Offset  // Write 00
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x20);
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, &tSRGBMatrix[24], _NON_AUTOINC);
    
    // G Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x28); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, &tSRGBMatrix[24], _NON_AUTOINC);

    // B Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x30); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, &tSRGBMatrix[24], _NON_AUTOINC);

    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT7, _BIT7); // sRGB Matrix Ready to Write   
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x00); // Disable Access Port
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT6, 0x00); // Normal sRGB Precision
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT2, 0x00); // Disable sRGB
    ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCCheckCRCOff();

    DebugMessageScaler("5. sRGB End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. sRGB PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. sRGB FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : PCM Matrix Test 
// Input Value  : None
// Output Value : _TEST_FAIL or _TEST_PASS
//--------------------------------------------------
bit ScalerQCPCMTest(void)
{
    BYTE ucData = 0;
    BYTE ucData1 = 0;
    
    DebugMessageScaler("5. PCM Start", 0x00);

    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT6, _BIT6); // Wendy add 20120914
    
    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);
    
    // Input Gamma Table
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT7, _BIT7);
    ScalerBurstWrite(tInputGamma, 99, GET_CURRENT_BANK_NUMBER(), P9_A0_INPUT_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerWrite(P9_A2_INPUT_GAMMA_LOW_THRE, 1, &tInputGamma[99], _NON_AUTOINC);
    ScalerWrite(P9_A3_INPUT_GAMMA_HIGH_THRE, 1, &tInputGamma[100], _NON_AUTOINC);
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT7, 0x00);
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT6, _BIT6); // Enable Input Gamma

    PDATA_WORD(0) = 0;
    // sRGB Matrix
    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT6, _BIT6);
    
    // RR, RG, RB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x08);  
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &tSRGBMatrix[0], _NON_AUTOINC);
    // R Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x20);
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);
    
    // GR, GG, GB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x10); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &tSRGBMatrix[8], _NON_AUTOINC);
    // G Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x28); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);
    
    // BR, BG, BB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x18); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &tSRGBMatrix[16], _NON_AUTOINC);
    // B Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x30); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);

    
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
    
    // D-RandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x07, 0xFB, 0x55, _D_DOMAIN_CRC) << 0));

    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // D-RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x41, 0x6C, 0x86, _D_DOMAIN_CRC) << 1));
    
    // D-RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xE4, 0x1D, 0x36, _D_DOMAIN_CRC) << 2));
    // D-RandomGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x9B, 0xF3, 0x01, _D_DOMAIN_CRC) << 3));
    
    ScalerQCHighlightWindowOff();

    ScalerQCDDitherOn(_LSB);
    
    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x41, 0xAD, 0x4F, _D_DOMAIN_CRC) << 1)); 
    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2D, 0x25, 0x5A, _D_DOMAIN_CRC) << 5)); 
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
	DebugMessageScaler("5. Mode_6", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x7A, 0x3B, 0xCD, _D_DOMAIN_CRC) << 6)); 
	// PatternGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
	DebugMessageScaler("5. Mode_7", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x0D, 0x02, 0xD7, _D_DOMAIN_CRC) << 7)); 
    
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT6, 0x00); // Disable Input Gamma
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT2, 0x00); // Disable sRGB
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, 0x00); // Disable Output Gamma
    ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCCheckCRCOff();

    DebugMessageScaler("5. PCM End", 0x00);    
    if((ucData == 0x00)&&(ucData1 == 0))
    {
        DebugMessageScaler("6. PCM PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. Fail Mode1", ucData1);
        DebugMessageScaler("6. PCM FAIL", 0x00);
        return _TEST_FAIL;
    }
}


//--------------------------------------------------
// Description  : Switch 3L / 4L  SU
// Input Value  : bIs3L = 1, Switch to 3L; = 0, switch to 4L 
// Output Value : None
//--------------------------------------------------
void ScalerQCPCMAdjustSU(bit bIs3L)
{
    BYTE ucData = 0;
    BYTE ucTemp[3] = {0};
    BYTE ucI = 0;
    BYTE ucFlag = 0;
    
    ucTemp[0] = ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES);
    ucTemp[1] = ScalerGetByte(CM_41_IV_DV_DELAY_CLK_ODD);    

    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT4, 0x00);   
       
    ScalerSetByte(P1_C6_DCLK_SPREAD_SPECTRUM, 0x04);// Display LVDS expread spectrum
    
    if(bIs3L == _ON)
    {
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xC4);

        // 2D 3Line VSU
        ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~(_BIT6), _BIT6);
        
        ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));    
        ScalerBurstWrite(tQC_SU_COEF_3L_2, 128, GET_CURRENT_BANK_NUMBER(), CM_36_FILTER_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
        ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);

        ucFlag = 16;
        for(ucI = 0; ucI < 15; ucI++)
        {
            ScalerSetByte(CM_02_STATUS0, 0x00);
            ScalerTimerWaitForEvent(_EVENT_DVS);    	    	
            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);
            
            if(ScalerGetByte(CM_02_STATUS0) & 0x01)
            {         
                ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 + ucTemp[1]);
                ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5);   
            }   
            else if(ScalerGetByte(CM_02_STATUS0) & 0x02)
            {
                ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucTemp[1] - ucI * 0x10);
                ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
            }
            else
            {
                break;
            }     
        }    
    }
    else
    {
        ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~(_BIT6), 0x00);
        ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);   
        ScalerSetByte(P1_C6_DCLK_SPREAD_SPECTRUM, (_DCLK_SPREAD_RANGE << 4 ) | _BIT2);// Display LVDS expread spectrum    
        
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
    BYTE ucCnt = 0;
    BYTE ucTableCnt = 0;
    BYTE ucDataTemp[3] = {0};    
    
    DebugMessageScaler("5. D Dither Start", 0x00);

    ScalerQCDDomainRandomGenOn(_MASS);

    ScalerSetBit(CM_67_GAMMA_CTRL, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7 | _BIT4 | _BIT3), 0x00);
    ScalerSetBit(CM_6B_DITHERING_CTRL2, 0x00, _BIT0);
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~(_BIT7 | _BIT6), 0x00);

    // Load table
    // 6 bit test
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_D_DOMAIN_DITHER_10_6_TABLE, sizeof(tQC_D_DOMAIN_DITHER_10_6_TABLE), GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_D_DOMAIN_DITHER_SEQ_TABLE, sizeof(tQC_D_DOMAIN_DITHER_SEQ_TABLE), GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_DITHER_TEMOFFSET, sizeof(tQC_DITHER_TEMOFFSET), GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), 0x00);
    
    ScalerSetBit(CM_6B_DITHERING_CTRL2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7);
    ScalerBurstWrite(tQC_DITHER_THD, sizeof(tQC_DITHER_THD), GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_6B_DITHERING_CTRL2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // enable thd
    //MSB
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7), 0x00);
    ScalerSetBit(CM_6B_DITHERING_CTRL2, ~_BIT2, _BIT2);
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT4);
	ScalerSetBit(CM_6A_DITHERING_CTRL1, ~_BIT5, _BIT5);
    
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckFSCrc(tQC_DITHER_NEWFUNC1_MSB_CRC_TABLE, sizeof(tQC_DITHER_NEWFUNC1_MSB_CRC_TABLE) / 3, _D_DOMAIN_CRC, 1) << 0));

    // LSB
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7), _BIT7);
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT4);
	ScalerSetBit(CM_6A_DITHERING_CTRL1, ~_BIT5, _BIT5);
                                                        
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckFSCrc(tQC_DITHER_NEWFUNC1_LSB_CRC_TABLE, sizeof(tQC_DITHER_NEWFUNC1_LSB_CRC_TABLE) / 3, _D_DOMAIN_CRC, 1) << 1));

    ScalerQCDDitherOff();

    // 8 bit test  
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_D_DOMAIN_DITHER_TABLE, sizeof(tQC_D_DOMAIN_DITHER_TABLE), GET_CURRENT_BANK_NUMBER(), CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    // New Function
    // sign, multi-seq, share-seq, inv seq, inv1, keep 4 
    ScalerSetBit(CM_67_GAMMA_CTRL, ~(_BIT1 | _BIT0), _BIT1);
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7 | _BIT4 | _BIT3), 0x00);
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT3);
    ScalerSetBit(CM_6B_DITHERING_CTRL2, 0x00, _BIT3| _BIT1 | _BIT0);
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);
	ScalerSetBit(CM_6A_DITHERING_CTRL1, ~_BIT5, _BIT5);

    // MSB
    DebugMessageScaler("5. Mode_2", 0x00);
    ScalerSetBit(CM_68_GAMMA_BIST, ~_BIT7, 0x00);   
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ucData = (ucData | ((BYTE)ScalerQCCheckFSCrc(tQC_DITHER_NEWFUNC2_MSB_CRC_TABLE, sizeof(tQC_DITHER_NEWFUNC2_MSB_CRC_TABLE) / 3, _D_DOMAIN_CRC, 4) << 2));

    // LSB
    DebugMessageScaler("5. Mode_3", 0x00);
    ScalerSetBit(CM_68_GAMMA_BIST, ~_BIT7, _BIT7);   
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ucData = (ucData | ((BYTE)ScalerQCCheckFSCrc(tQC_DITHER_NEWFUNC2_LSB_CRC_TABLE, sizeof(tQC_DITHER_NEWFUNC2_LSB_CRC_TABLE) / 3, _D_DOMAIN_CRC, 4) << 3));   
	 

    //V_frame mod , H_frame mode,temporal ,sign, multi-seq, share-seq, inv seq, inv1,  not keep 4 

    ScalerSetBit(CM_67_GAMMA_CTRL, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7 | _BIT4 | _BIT3), 0x00);
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT4 | _BIT3 | _BIT1 | _BIT0);
    ScalerSetBit(CM_6B_DITHERING_CTRL2, 0x00, _BIT3| _BIT1 | _BIT0);
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);
	ScalerSetBit(CM_6A_DITHERING_CTRL1, ~_BIT5, _BIT5);

    // MSB
    DebugMessageScaler("5. Mode_4", 0x00);
    ScalerSetBit(CM_68_GAMMA_BIST, ~_BIT7, 0x00);   
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ucData = (ucData | ((BYTE)ScalerQCCheckFSCrc(tQC_DITHER_NEWFUNC3_MSB_CRC_TABLE, sizeof(tQC_DITHER_NEWFUNC3_MSB_CRC_TABLE) / 3, _D_DOMAIN_CRC, 4) << 2));

    // LSB
    DebugMessageScaler("5. Mode_5", 0x00);
    ScalerSetBit(CM_68_GAMMA_BIST, ~_BIT7, _BIT7);   
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ucData = (ucData | ((BYTE)ScalerQCCheckFSCrc(tQC_DITHER_NEWFUNC3_LSB_CRC_TABLE, sizeof(tQC_DITHER_NEWFUNC3_LSB_CRC_TABLE) / 3, _D_DOMAIN_CRC, 4) << 3));   
	 
 	 
    // disable dither
    ScalerSetBit(CM_67_GAMMA_CTRL, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7 | _BIT4 | _BIT3), 0x00);
    ScalerSetBit(CM_6B_DITHERING_CTRL2, 0x00, _BIT0);
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~(_BIT7 | _BIT6), 0x00);

    ScalerQCDDitherOff();
    ScalerQCDDomainPatternGenOff();
    ScalerQCCheckCRCOff(); 

    ScalerQCIDomainRandomGenOn(_MASS);  

    DebugMessageScaler("5. D Dither End", 0x00);  
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. D Dither PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. D Dither FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Display Conversion Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCDisplayConversionTest(void)
{
    BYTE ucData = 0;
   
    DebugMessageScaler("5. Display Conversion Start", 0x00);

    ScalerQCDDomainRandomGenOn(_MASS);

    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT4, 0x00);  
    
    // LVDS + DataBitInverse
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	  // EOSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT,_CM_8C_PT_AF_TCON_LVDS_CTRL15,~_BIT0 ,_BIT0);  // Data Bit inverse
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), _BIT0);    	// LVDS

    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xCD, 0xEB, 0x33, _D_DOMAIN_CRC) << 0));//0xCD, 0xEB, 0x33,
 
    
    // LVDS +EOSwap+RBSwap+MLSwap
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4),(_BIT6 | _BIT5 | _BIT4));    	  // EOSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT,_CM_8C_PT_AF_TCON_LVDS_CTRL15,~_BIT0 ,0x00);   // Data Bit inverse 
    DebugMessageScaler("5. Mode_1", 0x00);

    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x6B, 0x88, 0xDD, _D_DOMAIN_CRC) << 1));//0x6B, 0x88, 0xDD,


    // LVDS +EOSwap+RBSwap+MLSwap+DataBitInverse
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4),(_BIT6 | _BIT5 | _BIT4));    	  // EOSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT,_CM_8C_PT_AF_TCON_LVDS_CTRL15,~_BIT0 ,_BIT0);  // Data Bit inverse
    DebugMessageScaler("5. Mode_2", 0x00);

    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xE7, 0x9A, 0x83, _D_DOMAIN_CRC) << 1));//0xE7, 0x9A, 0x83, 
  
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4),0x00);    	  // EOSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT,_CM_8C_PT_AF_TCON_LVDS_CTRL15,~_BIT0 ,0x00);   // Data Bit Inverse
    DebugMessageScaler("5. Display Conversion End", 0x00);  
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. Display Conversion PASS", 0x00);    
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. Display Conversion FAIL", 0x00);    
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Scale Down Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCScaleDownTest(void)
{
    bit bData = 0;   

    DebugMessageScaler("5. Scale down Start", 0x00);

    // Clear Input Status
    ScalerSetBit(CM_03_STATUS1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
    
    ScalerQCIDomainRandomGenOn(_MASS);
    
    // **************************************//
    // 2D
    // **************************************//
    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x05);

    // v factor 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0xAA);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xAB);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x10);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x14);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x00);  
	
	ScalerSetDataPortByte(CM_30_FIFO_ACCESS_PORT, 0x00, 0x43);  
	ScalerSetDataPortByte(CM_30_FIFO_ACCESS_PORT, 0x01, 0x00);
    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down    
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    bData = (bData | ((BYTE)ScalerQCCheckCRCOn(0x58, 0xE9, 0x0C, _I_DOMAIN_CRC)));

	ScalerSetDataPortByte(CM_30_FIFO_ACCESS_PORT, 0x00, 0x54);  
	ScalerSetDataPortByte(CM_30_FIFO_ACCESS_PORT, 0x01, 0x00);	
	ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
	ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, 0x00);

    ScalerTimerWaitForEvent(_EVENT_DVS);                
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerSetByte(CM_02_STATUS0, 0x00);
    ScalerSetByte(CM_03_STATUS1, 0x00);

    ScalerQCIDomainRandomGenOff();
    ScalerQCCheckCRCOff(); 

    DebugMessageScaler("5. Scale down End", 0x00); 
    if(bData == 0x00)
    {
        DebugMessageScaler("6. Scale down PASS", 0x00);    
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", 0x01);
        DebugMessageScaler("6. Scale down FAIL", 0x00);    
        return _TEST_FAIL;
    }            
}


//-------------------------------------------------- 
// Description  : Setting data with IIC_SDA 
// Input Value  : bset  -->  Set bit of IIC_SDA
// Output Value : None
//--------------------------------------------------
void ScalerQCIICSDA(bit ucset)
{   
    if(ucset == 1)
    {
        PCB_SW_IIC_SDA_SET();
    }

    else
    {
        PCB_SW_IIC_SDA_CLR();
    }
}


//-------------------------------------------------- 
// Description  : FPGA for mLVDS7x configuration setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGA7xTable(void)
{
    ScalerQCFPGASetByte(0x00, 0x01);
    ScalerTimerDelayXms(200);
    ScalerQCFPGASetByte(0x00, 0x1E);
    ScalerTimerDelayXms(200);
    ScalerQCFPGASetByte(0x00, 0x3E);
    ScalerTimerDelayXms(200);
    ScalerQCFPGASetByte(0x10, 0x11);
    ScalerTimerDelayXms(50);

}



//-------------------------------------------------- 
// Description  : Clear CLK with IIC_SCL 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGACLRSCLK(void)
{
    PCB_SW_IIC_SCL_CLR();
    PCB_SW_IIC_SCL_CLR();
    PCB_SW_IIC_SCL_CLR();
    PCB_SW_IIC_SCL_CLR();
    PCB_SW_IIC_SCL_CLR();
}

//-------------------------------------------------- 
// Description  : The content of FPGA's setting
// Input Value  : check  --> checking the FPGA's register
//                type   --> select the type of mLVDS 6x/7x/8x
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGAContent(BYTE *pucPass)
{
    BYTE ucCheck[6];

    ScalerQCFPGARead(0x11, &ucCheck[0]);
    DebugMessageScaler("5. FPGA_0x11=", ucCheck[0]);
    ScalerQCFPGARead(0x12, &ucCheck[1]);
    DebugMessageScaler("5. FPGA_0x12=", ucCheck[1]);
    ScalerQCFPGARead(0x13, &ucCheck[2]);
    DebugMessageScaler("5. FPGA_0x13=", ucCheck[2]);
    ScalerQCFPGARead(0x14, &ucCheck[3]);
    DebugMessageScaler("5. FPGA_0x14=", ucCheck[3]);
    ScalerQCFPGARead(0x15, &ucCheck[4]);
    DebugMessageScaler("5. FPGA_0x15=", ucCheck[4]);
    ScalerQCFPGARead(0x16, &ucCheck[5]);
    DebugMessageScaler("5. FPGA_0x16=", ucCheck[5]);


    if((ucCheck[0] == 0x3B) && (ucCheck[1] == 0x73) && (ucCheck[2] == 0x6D) && (ucCheck[3] == 0xB4) && (ucCheck[4] == 0xCB) && (ucCheck[5] == 0x46))

    {

    DebugMessageScaler("5. FPGA7x Content Pass", 0x00);
    *pucPass |= _TEST_PASS;

    }
    else
    {
        
    DebugMessageScaler("5. FPGA7x Content Fail", 0x00);
    *pucPass |= _TEST_FAIL;

    }

}

//-------------------------------------------------- 
// Description  : Get the data of FPGA's register 
// Input Value  : None
// Output Value : Data of FPGA's register
//--------------------------------------------------
BYTE ScalerQCFPGAGetByte(void)
{
    BYTE ucValue = 0;
    BYTE ucChk = 0;

    ScalerSetByte(P10_AC_PIN_SHARE_CTRL0C, 0x00); // Page 10-B4 Pin 53

    ScalerQCFPGACLRSCLK();
    PCB_SW_IIC_SDA_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT0;
    }
    ScalerQCFPGASetSCLK();
    PCB_SW_IIC_SDA_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT1;
    }
    ScalerQCFPGACLRSCLK();
    PCB_SW_IIC_SDA_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT2;
    }
    ScalerQCFPGASetSCLK();
    PCB_SW_IIC_SDA_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT3;
    }
    ScalerQCFPGACLRSCLK();
    PCB_SW_IIC_SDA_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT4;
    }
    ScalerQCFPGASetSCLK();
    PCB_SW_IIC_SDA_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT5;
    }
    ScalerQCFPGACLRSCLK();
    PCB_SW_IIC_SDA_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT6;
    }
    ScalerQCFPGASetSCLK();
    PCB_SW_IIC_SDA_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT7;
    }
    ScalerQCFPGACLRSCLK();
    
    ScalerSetByte(P10_AC_PIN_SHARE_CTRL0C, 0x02); // Page 10-AC Pin 35
    return ucValue;
}

//--------------------------------------------------
// Description  : Read data from registers of scaler and put it into an reading data array
// Input Value  : ucAddr    --> Start address of register
//                pArray    --> Pointer of the reading data array
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGARead(BYTE ucAddr, BYTE *pucArray)
{
    ScalerQCFPGASendAddr(ucAddr, _READ, _NON_AUTOINC);
    *pucArray = ScalerQCFPGAGetByte();
    ScalerQCFPGAReadStop(); 
}

//-------------------------------------------------- 
// Description  : Stop reading the FPGA's register 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGAReadStop(void)
{
    ScalerQCIICSDA(_HIGH);
    ScalerQCIICSDA(_LOW);
    ScalerQCIICSDA(_HIGH);
    PCB_SW_IIC_SCL_SET();
}

//-------------------------------------------------- 
// Description  : The address of the FPGA's register
// Input Value  : ucAddr      --> Start address of register
//                bReadWrite  --> Setting the read/write command to FPGA
//                bAutoInc    --> Setting the auto/non-auto increase command to FPGA
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASendAddr(BYTE ucAddr, bit ucReadWrite, bit ucAutoInc)
{
    PCB_SW_IIC_SCL_SET();
    ScalerQCIICSDA(_HIGH);
    ScalerQCIICSDA(_LOW);
    ScalerQCIICSDA(_HIGH);

    ScalerQCFPGASendByte(ucAddr);

    ScalerQCIICSDA(ucReadWrite);
    PCB_SW_IIC_SCL_CLR();
    ScalerQCIICSDA(ucAutoInc);
    PCB_SW_IIC_SCL_SET();
    ScalerQCIICSDA(_HIGH);
}

//-------------------------------------------------- 
// Description  : Send the data to FPGA's register 
// Input Value  : ucValue  --> The data of FPGA's register where you want to write
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASendByte(BYTE ucValue)
{
    ScalerQCIICSDA((bit)(ucValue & _BIT0));
    PCB_SW_IIC_SCL_CLR();
    ScalerQCIICSDA((bit)(ucValue & _BIT1));
    PCB_SW_IIC_SCL_SET();
    ScalerQCIICSDA((bit)(ucValue & _BIT2));
    PCB_SW_IIC_SCL_CLR();
    ScalerQCIICSDA((bit)(ucValue & _BIT3));
    PCB_SW_IIC_SCL_SET();
    ScalerQCIICSDA((bit)(ucValue & _BIT4));
    PCB_SW_IIC_SCL_CLR();
    ScalerQCIICSDA((bit)(ucValue & _BIT5));
    PCB_SW_IIC_SCL_SET();
    ScalerQCIICSDA((bit)(ucValue & _BIT6));
    PCB_SW_IIC_SCL_CLR();
    ScalerQCIICSDA((bit)(ucValue & _BIT7));
    PCB_SW_IIC_SCL_SET();
}

//--------------------------------------------------
// Description  : Write a data array into registers of scaler
// Input Value  : ucAddr    --> Start address of register
//                ucValue   --> Pointer of the writing data array
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASetByte(BYTE ucAddr, BYTE ucValue)
{  
    ScalerQCFPGASendAddr(ucAddr, _WRITE, _NON_AUTOINC);
    ScalerQCFPGASendByte(ucValue);
    ScalerQCFPGAWriteStop();

    //DebugMessageScaler("5. ScalerQCFPGASetByte", 0x00);

}

//-------------------------------------------------- 
// Description  : Setting CLK of IIC_SCL 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASetSCLK(void)
{
    PCB_SW_IIC_SCL_SET();
    PCB_SW_IIC_SCL_SET();
    PCB_SW_IIC_SCL_SET();
    PCB_SW_IIC_SCL_SET();
    PCB_SW_IIC_SCL_SET();
}

//-------------------------------------------------- 
// Description  : Stop writting the FPGA's register 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGAWriteStop(void)
{
    PCB_SW_IIC_SCL_CLR();
    PCB_SW_IIC_SCL_SET();
    ScalerQCIICSDA(_HIGH);
    ScalerQCIICSDA(_LOW);
    ScalerQCIICSDA(_HIGH);
}

//-------------------------------------------------- 
// Description  : The EQC of FPGA with mLVDS 6x/7x/8x
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCmLVDS(void)
{ 
    BYTE ucScl = 0x00;
    BYTE ucSda = 0x00;
    BYTE ucPass = 0;
    BYTE test = 0;

    ScalerRead(P10_AB_PIN_SHARE_CTRL0B, 1, &ucScl, _AUTOINC);    // Page 10-AB Pin 34
    ScalerRead(P10_AC_PIN_SHARE_CTRL0C, 1, &ucSda, _AUTOINC);    // Page 10-AC Pin 35
    ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, 0x02);
    ScalerSetByte(P10_AC_PIN_SHARE_CTRL0C, 0x02);
    ScalerTimerDelayXms(1); 

    ScalerBurstWrite(tQC_COMMONMLVDS, sizeof(tQC_COMMONMLVDS), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH); 

    ScalerBurstWrite(tQC_MLVDS7X, sizeof(tQC_MLVDS7X), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH); 
    
    /*// Jeyu_test_start
    ScalerQCFPGA7xTable();
    while(1)    
    {   
        //ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, 0x00);
        //ScalerSetByte(P10_AC_PIN_SHARE_CTRL0C, 0x00);
        while (test < 250)
        {
            ScalerDebug();
            test = test + 1;
        }
 
        
        ScalerQCFPGAContent(&ucPass);

        test = 0;
    }
    // Jeyu_test_end*/
    ScalerTimerDelayXms(1); 

    ScalerQCFPGA7xTable();
    ScalerQCFPGAContent(&ucPass);
   
    if(ucPass == _TEST_FAIL)
    {
        DebugMessageScaler("6. FPGA for LVSD Fail ", 0x00);
    }
    else
    {
        DebugMessageScaler("6. FPGA for LVSD ucPass ", 0x00);
    }
    
    ScalerSetByte(P10_AB_PIN_SHARE_CTRL0B, ucScl);
    ScalerSetByte(P10_AC_PIN_SHARE_CTRL0C, ucSda);
    ScalerTimerDelayXms(1); 

    return ucPass;

}



#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
//-------------------------------------------------- 
// Description  : The EQC of eLED
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCeLED(void)
{
    BYTE ucPass = 0;
    
    ScalerELEDInitial();

    ScalerQCeLEDControl(_LIGHT_CONTROL_ON);

    // Normal eLED Dislay Test
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    if(ScalerGetByte(P16_A0_LEDBC_DRIVER_CTRL1) == 0x3C)
    {
        ucPass |= _BIT1;

        DebugMessageScaler("eLED Normal Display Fial", ucPass);

        return ucPass;
    }
    else
    {
        ScalerTimerDelayXms(500);
        ScalerSetByte(P16_A0_LEDBC_DRIVER_CTRL1, 0x1C);
        ScalerSetBit(P16_D5_LEDBC_PROTECT_CTRL_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
        ScalerTimerDelayXms(500);
        ScalerQCeLEDControl(_LIGHT_CONTROL_ON);
    }

    // eLED Short Event Test
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);    

    if(ScalerGetByte(P16_D9_LEDBC_ABNORMAL_STATUS_3) != 0x01)
    {
        ScalerSetByte(P16_A0_LEDBC_DRIVER_CTRL1, 0x1C);
        
        ucPass |= _BIT2;

        DebugMessageScaler("eLED Short Event Fial", ucPass);

        return ucPass;
    }
    else
    {
        ScalerTimerDelayXms(500);
        ScalerSetByte(P16_B7_LEDBC_VMINSDISB, 0xFF);
    }

    // eLED OVP Event Test
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    
    if(ScalerGetByte(P16_A0_LEDBC_DRIVER_CTRL1) != 0x3C)
    {
        ucPass |= _BIT3;

        DebugMessageScaler("eLED OVP Fial", ucPass);

        return ucPass;
    }
    else
    {
        ScalerSetBit(P16_BF_LEDBC_OXP_REG_2, ~_BIT7, _BIT7);
        ScalerSetByte(P16_B7_LEDBC_VMINSDISB, 0x00);

        DebugMessageScaler("eLED Test PASS", 0x00);
        
        ucPass = _TEST_PASS;
    }

    return ucPass;
}

//-------------------------------------------------- 
// Description  : The EQC of eLED
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCeLEDControl(bit bOn)
{
    if(bOn == _LIGHT_CONTROL_ON)
    {
        // Booster New mode or Old mode
        ScalerELEDBoosterAlignDimming(_ELED_BOOSTING_STATE);
        
        // Set OVP Reference Voltage
        ScalerELEDSetOvp(_ELED_BOOSTING_STATE);

        // Set OCP Reference Voltage
        ScalerELEDSetOcp(_ELED_BOOSTING_STATE);
    
        // Set OVP En/Dn
        ScalerELEDSetOvpEn(_ON);

        // Set OCP En/Dn
        ScalerELEDSetOcpEn(_ON);

        // Set LED_SHORT En/Dn
        ScalerELEDSetLedShortEn(_OFF);

        // Soft Start Enable
        ScalerSetBit(P16_D4_LEDBC_PROTECT_SWITCH, ~_BIT6, 0x00);

        // Enable LED Power
        ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~(_BIT7 | _BIT5), _BIT7 | _BIT5);

        // At Least 40us For LED Power Ready
        for(pData[0] = 0; pData[0] <= 100; pData[0]++)
        {
            _nop_();
        }
        
        // Enable LED Driver
        ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~_BIT6, _BIT6);

        // Booster New mode
        ScalerELEDBoosterAlignDimming(_ELED_STEADY_STATE);

        // For OTP and LED_Short Detect
        ScalerTimerDelayXms(20);

        // Restore OVP/OCP Debounce time 10us
        ScalerELEDSetOvp(_ELED_STEADY_STATE);
        ScalerELEDSetOcp(_ELED_STEADY_STATE);
        
        ScalerELEDSetLedShortEn(_ON);
    }
    else
    {
        // Disable LED Boost Driver & LED Power
        ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

        // Set OVP En/Dn
        ScalerELEDSetOvpEn(_OFF);

        // Set OCP En/Dn
        ScalerELEDSetOcpEn(_OFF);

        // Set LED_SHORT En/Dn
        ScalerELEDSetLedShortEn(_OFF);
    }
}
#endif // End of #if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)

#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)
