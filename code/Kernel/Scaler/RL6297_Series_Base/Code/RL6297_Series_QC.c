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
// ID Code      : RL6297_Series_QC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6297_SERIES_QC__

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

//----------------------------------------------------------------------------
// HDMI QC Test
//----------------------------------------------------------------------------
#if(_HDMI_SUPPORT == _ON)
#define _HDMI_CRC0                   0xA8
#define _HDMI_CRC1                   0x69
#define _HDMI_CRC2                   0x3A
#define _HDMI_CRC3                   0xCD
#define _HDMI_CRC4                   0xB3
#define _HDMI_CRC5                   0x6A
#endif

//----------------------------------------------------------------------------
// DP QC Test
//----------------------------------------------------------------------------
#if(_DP_SUPPORT == _ON)
#define _DP_CRC0                    0x4D
#define _DP_CRC1                    0x81
#define _DP_CRC2                    0x4D
#define _DP_CRC3                    0x81
#define _DP_CRC4                    0x4D
#define _DP_CRC5                    0x81
#endif

//----------------------------------------------------------------------------
// LVDS QC Debugmessage
//----------------------------------------------------------------------------
#define _MLVDS6X                    0
#define _MLVDS7X                    1
#define _MLVDS8X                    2
#define _SIMPLE                     0
#define _DETAIL                     1

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Code Tables of Ultravivid
//--------------------------------------------------
BYTE code tQC_ULTRAVIVID_SETTING[] = 
{	
     //Ultravivid (26) start from 0x14C0~0x14D9
     0xF8,0x28,0x1B,0x01,0x01,0x78,0x00,0xD4,0x2D,0x12,
     0x06,0x07,0x00,0x11,0xA2,0xA2,0x94,0xB6,0x18,0x0C,
     0x16,0xC8,0x21,0x08,0x82,0x05,
     
     //Ultravivid (18) start from 0x14E0~0x14F1
     0x01,0x78,0x00,0x8F,0x29,0x1A,0x0E,0x07,0x04,0x16,
     0xF5,0xE3,0x3F,0x17,0x03,0x05,0x16,0x43,
     
};
BYTE code tQC_ULTRAVIVID_HLW[] = 
{	
     //VPK VCTI HLW (8) start from 0x11CC
     0x00,0xC8,0x01,0x90,0x00,0xC8,0x01,0x90,     
};

//--------------------------------------------------
// Code Tables of ADC Histogram
//--------------------------------------------------
BYTE code tQC_ADCH_SETTING_FUNC1A[] = 
{				     
   //ADC Histogram window setting(4),  start from 0x1EA0
   0x03,0xE8,0x01,0xF4,   
};

BYTE code tQC_ADCH_SETTING_FUNC1B[] = 
{				     
	//ADC Histogram Func1b parameter(4), start from 0x1EA8~0x1EAB
	0x00,0x05,0x00,0x05,

	//ADC Histogram Func1b_1 parameter(4), start from 0x1EAD~0x1EB0
    0x80,0x40,0x00,0x00,   

	//ADC Histogram Func1b_2 parameter(4), start from 0x1EAD~0x1EB0
    0x80,0x40,0x18,0x00,      	
};

BYTE code tQC_ADCH_SETTING_FUNC2[] = 
{				     
    //ADC Histogram Func2_1 parameter(6), start from 0x1EC1~0x1EC6
    0x20,0x00,0x00,0x00,0x00,0x00,

    //ADC Histogram Func2_2 parameter(6), start from 0x1EC1~0x1EC6
    0x30,0x06,0x94,0x00,0x07,0x80,
	
};

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
// Code Tables of I-Dither 10 -> 6
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_10_6_TABLE[] = 
{
    // 10 --> 6
    0x07, 0xF8, 0x69, 0x1E, 0xAD, 0x52, 0xC3, 0xB4,
    0xAD, 0x52, 0xC3, 0xB4, 0x07, 0xF8, 0x69, 0x1E,
    0xAD, 0x52, 0x69, 0x1E, 0xC3, 0xB4, 0x07, 0xF8,
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

BYTE code tQC_New_ICM_Modify0[] =
{
0xF7,0xEF,0xEF,0xDF,0xE7,0xCF,0xDF,0xBF,0xD7,0xAF,0xCF,0x9F,0xC7,0x8F,0xC0,0x80,
0xF5,0xF3,0xEB,0xE7,0xE1,0xDB,0xD7,0xCF,0xCD,0xC3,0xC3,0xB7,0xB9,0xAB,0xB0,0xA0,
0xFD,0xEF,0xFA,0xDF,0xF8,0xCF,0xF5,0xBF,0xF2,0xAF,0xF0,0x9F,0xED,0x8F,0xEB,0x80,
0xF3,0xF6,0xE8,0xEE,0xDC,0xE5,0xD1,0xDC,0xC5,0xD3,0xB9,0xCA,0xAE,0xC2,0xA3,0xBA,
0x00,0xEF,0xFF,0xDF,0x00,0xCF,0xFF,0xBF,0xFF,0xAF,0xFF,0x9F,0xFF,0x8F,0xFF,0x80,
0x03,0xFD,0x04,0xFC,0x01,0x42,0x05,0xCB,0x00,0x06,
0x01,0xA6,0x00,0x96,0x01,0x2C,0x01,0xF4,0x02,0x58,
//422,   150,   300,   500,   600
};

BYTE code tQC_New_ICM_Modify1[] =
{
0x08,0xEF,0x10,0xDF,0x18,0xCF,0x20,0xBF,0x28,0xAF,0x30,0x9F,0x38,0x8F,0x40,0x80,
0x05,0xEF,0x0A,0xDF,0x0F,0xCF,0x14,0xBF,0x19,0xAF,0x1E,0x9F,0x23,0x8F,0x28,0x80,
0x0B,0xF4,0x15,0xE9,0x20,0xDE,0x2A,0xD3,0x35,0xC8,0x3F,0xBD,0x4A,0xB2,0x54,0xA8,
0x00,0xEF,0xFF,0xDF,0x00,0xCF,0xFF,0xBF,0xFF,0xAF,0xFF,0x9F,0xFF,0x8F,0xFF,0x80,
0x0D,0xF8,0x19,0xF1,0x26,0xEA,0x32,0xE4,0x3F,0xDD,0x4B,0xD6,0x58,0xCF,0x64,0xC9,
0x0C,0x02,0x0D,0x7F,0x0A,0xC1,0x00,0x06,0x09,0xBB,
0x03,0xFE,0x00,0xC8,0x01,0x30,0x01,0xF4,0x02,0xBC,
//1022,   200,   304,   500,   700
};

BYTE code tQC_New_ICM_Modify2[] =
{
0x10,0x00,0x20,0x00,0x30,0x00,0x40,0x00,0x50,0x00,0x60,0x00,0x70,0x00,0x7F,0x00,
0x0F,0xFC,0x1D,0xF9,0x2C,0xF7,0x3A,0xF4,0x49,0xF1,0x58,0xEE,0x66,0xEB,0x74,0xE9,
0x0F,0x03,0x1D,0x06,0x2C,0x09,0x3A,0x0B,0x49,0x0E,0x58,0x11,0x66,0x14,0x74,0x16,
0x0D,0xF8,0x19,0xF1,0x26,0xEA,0x32,0xE4,0x3F,0xDD,0x4B,0xD6,0x58,0xCF,0x64,0xC9,
0x0B,0x0A,0x16,0x14,0x21,0x1E,0x2C,0x28,0x38,0x31,0x43,0x3B,0x4E,0x45,0x58,0x4E,
0x08,0x04,0x08,0xBA,0x08,0xB7,0x09,0xBB,0x0A,0x79,
0x06,0xBA,0x00,0xC8,0x01,0x46,0x01,0xC2,0x03,0x20,
//1722,   200,   326,   450,   800
};

BYTE code tQC_New_ICM_Modify3[] =
{
0x08,0x10,0x10,0x20,0x18,0x30,0x20,0x40,0x28,0x50,0x30,0x60,0x38,0x70,0x40,0x7F,
0x0A,0x0D,0x14,0x1A,0x1D,0x26,0x27,0x33,0x30,0x3F,0x3A,0x4C,0x44,0x59,0x4D,0x64,
0x07,0x10,0x0D,0x20,0x14,0x30,0x1A,0x40,0x20,0x50,0x27,0x60,0x2D,0x70,0x33,0x7F,
0x0B,0x0A,0x16,0x14,0x21,0x1E,0x2C,0x28,0x38,0x31,0x43,0x3B,0x4E,0x45,0x58,0x4E,
0xFD,0x10,0xFA,0x20,0xF8,0x30,0xF5,0x40,0xF3,0x50,0xF0,0x60,0xEE,0x70,0xEB,0x7F,
0x0C,0x03,0x0B,0x2B,0x0C,0xC7,0x0A,0x79,0x01,0x3C,
0x09,0xDA,0x00,0x7C,0x00,0xF8,0x01,0x2C,0x02,0x8A,
//2522,   124,   248,   300,   650
};

BYTE code tQC_New_ICM_Modify4[] =
{
0xF7,0x10,0xEF,0x20,0xE7,0x30,0xDF,0x40,0xD7,0x50,0xCF,0x60,0xC7,0x70,0xC0,0x7F,
0xFA,0x10,0xF5,0x20,0xF0,0x30,0xEB,0x40,0xE6,0x50,0xE1,0x60,0xDC,0x70,0xD7,0x7F,
0xF4,0x0B,0xEA,0x16,0xDF,0x21,0xD5,0x2C,0xCA,0x37,0xC0,0x42,0xB5,0x4D,0xAB,0x57,
0xFD,0x10,0xFA,0x20,0xF8,0x30,0xF5,0x40,0xF3,0x50,0xF0,0x60,0xEE,0x70,0xEB,0x7F,
0xF1,0x05,0xE4,0x09,0xD6,0x0D,0xC8,0x12,0xBA,0x16,0xAC,0x1A,0x9E,0x1F,0x91,0x23,
0x03,0xFE,0x02,0x88,0x05,0x42,0x01,0x3C,0x06,0xE6,
0x0C,0x64,0x00,0x64,0x00,0xCA,0x01,0x90,0x02,0xD5, 
//3172,   100,   202,   400,   725
};

BYTE code tQC_New_ICM_Modify5[] =
{
0xEF,0x00,0xDF,0x00,0xCF,0x00,0xBF,0x00,0xAF,0x00,0x9F,0x00,0x8F,0x00,0x80,0x00,
0xF0,0x02,0xE1,0x05,0xD3,0x07,0xC4,0x09,0xB5,0x0C,0xA6,0x0E,0x97,0x10,0x89,0x12,
0xF2,0xF9,0xE5,0xF3,0xD8,0xEE,0xCB,0xE7,0xBE,0xE2,0xB1,0xDC,0xA4,0xD6,0x98,0xD0,
0xF1,0x05,0xE4,0x09,0xD6,0x0D,0xC8,0x12,0xBA,0x16,0xAC,0x1A,0x9E,0x1F,0x91,0x23,
0xF3,0xF6,0xE8,0xEE,0xDC,0xE5,0xD1,0xDC,0xC5,0xD3,0xB9,0xCA,0xAE,0xC2,0xA3,0xBA,
0x07,0xFC,0x07,0x6B,0x06,0x84,0x06,0xE6,0x05,0xCB,
0x0F,0x39,0x00,0x64,0x00,0xC7,0x01,0xDB,0x02,0x6D,
//3897,   100,   199,   475,   621
};

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

//--------------------------------------------------
// Code Tables of APD
//--------------------------------------------------
BYTE code tADJPIXDET_SETTING[] =
{
    //******  D-domain PG.  ************
    4,  _NON_AUTOINC,               0x9f,                0x07,    
    14, _AUTOINC,                   0xf0,                0x04, 0x04, 0x20, 0x01, 0x03, 0x02, 0x10, 0x10, 0x01, 0x01, 0x00,
    4,  _NON_AUTOINC,               0xf0,                0x84,

    //******  Display format, 1920x24  ************   
    4,  _NON_AUTOINC,               0x2A,                0x00,
    10, _NON_AUTOINC,               0x2B,                0x07, 0xD0, 0x05, 0x00, 0x14, 0x00, 0x14,
    4,  _NON_AUTOINC,               0x2A,                0x07,
    10, _NON_AUTOINC,               0x2B,                0x07, 0x94, 0x07, 0x94, 0x00, 0x30, 0x03,
    4,  _NON_AUTOINC,               0x2A,                0x0e,
    11, _NON_AUTOINC,               0x2B,                0x00, 0x0a, 0x00, 0x0a, 0x00, 0x22, 0x00, 0x22,
    //4,  _NON_AUTOINC,               0x2A,                   0xc0,

    //******  all digital func disable   ************
    4,  _NON_AUTOINC,               0x89,                0x00, //i-dither
    4,  _NON_AUTOINC,               0x6a,                0x00, //D-dither

    4,  _NON_AUTOINC,               0x28,                0x8f,
    4,  _NON_AUTOINC,               0x28,                0x87,

    //******  APD  ************
    4,  _NON_AUTOINC,               0x9f,                0x15,
    11,  _AUTOINC,                  0xD0,                0xc4,0x20, 0x0c, 0x20, 0x00, 0x01,0x00,0x00,

    _END

};

BYTE code tADJPIXDET_SETTING2[] =
{
    //******  D-domain PG.  ************
    4,  _NON_AUTOINC,               0x9f,                0x07,    
    14, _AUTOINC,                   0xf0,                0x04, 0x04, 0x0e, 0x01, 0x03, 0x02, 0x10,  0x10, 0x01, 0x01, 0x00,
    4,  _NON_AUTOINC,               0xf0,                0x84,

    //******  Display format, 1920x24  ************   
    4,  _NON_AUTOINC,               0x2A,                0x00,
    10, _NON_AUTOINC,               0x2B,                0x07, 0xD0, 0x05, 0x00, 0x14, 0x00, 0x14,
    4,  _NON_AUTOINC,               0x2A,                0x07,
    10, _NON_AUTOINC,               0x2B,                0x07, 0x94, 0x07, 0x94, 0x00, 0x30, 0x03,
    4,  _NON_AUTOINC,               0x2A,                0x0e,
    11, _NON_AUTOINC,               0x2B,                0x00, 0x0a, 0x00, 0x0a, 0x00, 0x22, 0x00, 0x22,
    //4,  _NON_AUTOINC,               0x2A,                   0xc0,

    //******  all digital func disable   ************
    4,  _NON_AUTOINC,               0x89,                0x00, //i-dither
    4,  _NON_AUTOINC,               0x6a,                0x00, //D-dither

    4,  _NON_AUTOINC,               0x28,                0x8f,
    4,  _NON_AUTOINC,               0x28,                0x87,

    //******  APD  ************
    4,  _NON_AUTOINC,               0x9f,                0x15,
    11,  _AUTOINC,                  0xD0,                0xc4,0x20, 0x0c, 0x20, 0x00, 0x01,0x00,0x00,

    _END

};

#if(_LVDS_EO_CLK_MERGE == _DISABLE)
//----------------------------------------------------------------------------------------------------
// mLVDS Common Table 
//----------------------------------------------------------------------------------------------------
BYTE code tQC_COMMONMLVDS[] =
{
    5,	_AUTOINC,	0x28,	0x23,0x00, // NO frame sync, eo no swap
                
    // display format
    4,	_AUTOINC,       0x28,	0x08,	    // frame sync
    4,	_AUTOINC,       0x2A,	0x00,
    5,	_NON_AUTOINC,	0x2B,	0x05,0x8C,	// total disp hori. pixels
    4,	_AUTOINC,       0x2A,	0x02,
    4,	_NON_AUTOINC,	0x2B,	0x14,	    // hs end
    4,	_AUTOINC,       0x2A,	0x03,
    5,	_NON_AUTOINC,	0x2B,	0x00,0x22,	// hori bkg start 
    4,	_AUTOINC,       0x2A,	0x05,
    5,	_NON_AUTOINC,	0x2B,	0x00,0x22,	// hori act start
    4,	_AUTOINC,       0x2A,	0x07,
    5,	_NON_AUTOINC,	0x2B,	0x05,0x7A,	// hori act end 	
    4,	_AUTOINC,       0x2A,	0x09,
    5,	_NON_AUTOINC,	0x2B,	0x05,0x7A,	// hori bkg end		
    4,	_AUTOINC,       0x2A,	0x0B,
    5,	_NON_AUTOINC,	0x2B,	0x00,0x1B,	// vert. total
    4,	_AUTOINC,       0x2A,	0x0D,
    4,	_NON_AUTOINC,	0x2B,	0x02,	    // vs end
    4,	_AUTOINC,       0x2A,	0x0E,
    5,	_NON_AUTOINC,	0x2B,	0x00,0x02,	// vert bkg start
    4,	_AUTOINC,       0x2A,	0x10,
    5,	_NON_AUTOINC,	0x2B,	0x00,0x02,	// vert act start
    4,	_AUTOINC,       0x2A,	0x12,
    5,	_NON_AUTOINC,	0x2B,	0x00,0x1A,	// vert act end		
    4,	_AUTOINC,       0x2A,	0x14,
    5,	_NON_AUTOINC,	0x2B,	0x00,0x1A,	// vert bkg end	
    4,	_AUTOINC,       0x2A,	0x20,
    4,	_NON_AUTOINC,	0x2B,	0x03, 	    // <cchild_debug> Dclk polarity inv disable    8825~8920

    4,	_AUTOINC,	0x40,	0x00,	        // ivs to dvs

    // fixed last line for free-run mode
    4,	_AUTOINC,	0x9F,	0x01,
    7,	_AUTOINC,	0xC7,	0x50,0x1C,0x8C,0x02,

    4,	_AUTOINC,	0x28,	0x87,    // free-run mode, force-to-background, single output, force enable
    4,	_AUTOINC,	0x29,	0x00,

    4,	_AUTOINC,       0x9F, 0x07,
    14,	_AUTOINC,       0xF0, 0x85, 0x05, 0x05, 0x00, 0x04, 0x08, 0x01, 0x01, 0x01, 0x01, 0x00,

    // TCON0
    4,	_AUTOINC,       0x9F, 0x15,
    4,	_AUTOINC,       0xA1, 0x50,
    5,	_AUTOINC,       0xA3, 0x68, 0x00,
    5,	_AUTOINC,       0xA3, 0x69, 0x00,
    5,	_AUTOINC,       0xA3, 0x6A, 0x24,
    5,	_AUTOINC,       0xA3, 0x6B, 0x00,
    5,	_AUTOINC,       0xA3, 0x6C, 0x05,
    5,	_AUTOINC,       0xA3, 0x6D, 0x8C,
    5,	_AUTOINC,       0xA3, 0x6E, 0x80,
    // TP1
    5,	_AUTOINC,       0xA3, 0x38, 0x02,
    5,	_AUTOINC,       0xA3, 0x39, 0x00,
    5,	_AUTOINC,       0xA3, 0x3A, 0x1A,
    5,	_AUTOINC,       0xA3, 0x3B, 0xAA,
    5,	_AUTOINC,       0xA3, 0x3C, 0x22,
    5,	_AUTOINC,       0xA3, 0x3D, 0xB0,
    5,	_AUTOINC,       0xA3, 0x3E, 0x80,
    // VSYNC
    5,	_AUTOINC,       0xA3, 0x60, 0x00,
    5,	_AUTOINC,       0xA3, 0x61, 0x00,
    5,	_AUTOINC,       0xA3, 0x62, 0x01,
    5,	_AUTOINC,       0xA3, 0x63, 0x0A,
    5,	_AUTOINC,       0xA3, 0x64, 0x00,
    5,	_AUTOINC,       0xA3, 0x65, 0x14,
    5,	_AUTOINC,       0xA3, 0x66, 0x80,

    // Pingshare setting
    4,  _AUTOINC,       0x9F,   0x10,
    4,  _AUTOINC,       0xDA,   0x05,   // pin63 -> pin65  (TCON1)
    4,  _AUTOINC,       0xE1,   0x05,   // pin64 -> pin72  (TCON6)

    _END
};

/*
//----------------------------------------------------------------------------------------------------
// mLVDS_6x Table 
//----------------------------------------------------------------------------------------------------
BYTE code tQC_MLVDS6X[] =
{
    // Display PLL 
    4,	_AUTOINC,	0x9F,	0x01,
    4,	_AUTOINC,	0xBF,	0x36,   // M=54+2  // M= 54+2 test_cycle=2200~2295
    4,	_AUTOINC,	0xC0,	0x00,   // N=0+2 div2  // N= 0+2  div 2
    4,	_AUTOINC,	0xC1,	0x72,   // Icp = 7.4 ,Icp = 2.5+5
    4,	_AUTOINC,	0xC2,	0x09,   // power down dpll
    4,	_AUTOINC,	0xC2,	0x08,   // Power on DPLL

    // ----------- calibration start ------------------
    4,	_AUTOINC,	0xC3,	0x85, 	// CMP enable	// 1000us -> 200us
    4,	_AUTOINC,	0xC3,	0x8D, 	// latchca libration	// 1100us -> 201us
    4,	_AUTOINC,	0xC3,	0x9D, 	// calibration valid	// 1200us -> 202us
    // ----------- calibration end ------------------

    // mLVDS_6x setting	
    5,	_AUTOINC, 0x8B, 0x00, 0x07,
    5,	_AUTOINC, 0x8B, 0xA0, 0x38,
    5,	_AUTOINC, 0x8B, 0x01, 0x00,
    5,	_AUTOINC, 0x8B, 0x02, 0x00,
    5,	_AUTOINC, 0x8B, 0x03, 0x00,
    5,	_AUTOINC, 0x8B, 0x04, 0x02,
    5,	_AUTOINC, 0x8B, 0x05, 0x00,
    5,	_AUTOINC, 0x8B, 0x06, 0x2D,
    5,	_AUTOINC, 0x8B, 0x07, 0x28,
    5,	_AUTOINC, 0x8B, 0x09, 0xB8,
    5,	_AUTOINC, 0x8B, 0x0A, 0xB8,
    5,	_AUTOINC, 0x8B, 0x0D, 0xCC,
    5,	_AUTOINC, 0x8B, 0x0E, 0xCC,
    5,	_AUTOINC, 0x8B, 0x26, 0x73,
    5,	_AUTOINC, 0x8B, 0x0F, 0x18,
    5,	_AUTOINC, 0x8B, 0x10, 0xC1,
    5,	_AUTOINC, 0x8B, 0x11, 0xA9,
    5,	_AUTOINC, 0x8B, 0x12, 0xE0,
    5,	_AUTOINC, 0x8B, 0x13, 0x00,
    5,	_AUTOINC, 0x8B, 0x14, 0x00,
    5,	_AUTOINC, 0x8B, 0x15, 0x30,
    5,	_AUTOINC, 0x8B, 0x16, 0x00,
    5,	_AUTOINC, 0x8B, 0x17, 0x30,
    5,	_AUTOINC, 0x8B, 0x18, 0x00,
    5,	_AUTOINC, 0x8B, 0x19, 0xB8,
    5,	_AUTOINC, 0x8B, 0x1A, 0xB8,
    5,	_AUTOINC, 0x8B, 0x1B, 0x00,
    5,	_AUTOINC, 0x8B, 0x1D, 0x30,
    5,	_AUTOINC, 0x8B, 0x1E, 0xCC,
    5,	_AUTOINC, 0x8B, 0x20, 0x10,
    5,	_AUTOINC, 0x8B, 0x21, 0x80,
    5,	_AUTOINC, 0x8B, 0x22, 0x00,
    5,	_AUTOINC, 0x8B, 0x23, 0xFF,
    5,	_AUTOINC, 0x8B, 0x24, 0x00,
    5,	_AUTOINC, 0x8B, 0x25, 0x00,
    5,	_AUTOINC, 0x8B, 0x27, 0x0F,
    5,	_AUTOINC, 0x8B, 0x28, 0x3F,
    5,	_AUTOINC, 0x8B, 0x29, 0xFF,
    5,	_AUTOINC, 0x8B, 0x2A, 0x00,
    5,	_AUTOINC, 0x8B, 0xA0, 0xB8,
    5,	_AUTOINC, 0x8B, 0xA1, 0x16,
    5,	_AUTOINC, 0x8B, 0xA2, 0x12,
    5,	_AUTOINC, 0x8B, 0xA3, 0x00,
    5,	_AUTOINC, 0x8B, 0xA4, 0x80,
    5,	_AUTOINC, 0x8B, 0xA5, 0x80,
    5,	_AUTOINC, 0x8B, 0xA6, 0x01,
    5,	_AUTOINC, 0x8B, 0xA9, 0x00,

    // Start CRC
    4,	_AUTOINC,	0x2C,	0x81,

    4,	_AUTOINC,	0x9F,	0x15,
    4,	_AUTOINC,	0xB0,	0x10,   // Start LVDS CRC

    _END
};
*/

//----------------------------------------------------------------------------------------------------
// mLVDS_7x Table
//----------------------------------------------------------------------------------------------------
BYTE code tQC_MLVDS7X[] =
{ 
    // Display PLL 
    4,	_AUTOINC,	0x9F,	0x01,
    4,	_AUTOINC,	0xBF,	0x2E,   // M=54+2  // M= 54+2 test_cycle=2200~2295
    4,	_AUTOINC,	0xC0,	0x00,   // N=0+2 div2  // N= 0+2  div 2
    4,	_AUTOINC,	0xC1,	0x72,   // Icp = 7.4 ,Icp = 2.5+5
    4,	_AUTOINC,	0xC2,	0x09,   // power down dpll
    4,	_AUTOINC,	0xC2,	0x08,   // Power on DPLL

    // ----------- calibration start ------------------
    4,	_AUTOINC,	0xC3,	0x85, 	// CMP enable	// 1000us -> 200us
    4,	_AUTOINC,	0xC3,	0x8D, 	// latchca libration	// 1100us -> 201us
    4,	_AUTOINC,	0xC3,	0x9D, 	// calibration valid	// 1200us -> 202us
    // ----------- calibration end ------------------

    // mLVDS_7x setting	
    5,	_AUTOINC, 0x8B, 0x00, 0x07,
    5,	_AUTOINC, 0x8B, 0xA0, 0x38,
    5,	_AUTOINC, 0x8B, 0x01, 0x00,
    5,	_AUTOINC, 0x8B, 0x02, 0x00,
    5,	_AUTOINC, 0x8B, 0x03, 0x00,
    5,	_AUTOINC, 0x8B, 0x04, 0xAA,
    5,	_AUTOINC, 0x8B, 0x05, 0x00,
    5,	_AUTOINC, 0x8B, 0x06, 0x3F,
    5,	_AUTOINC, 0x8B, 0x07, 0x38,
    5,	_AUTOINC, 0x8B, 0x09, 0xB8,
    5,	_AUTOINC, 0x8B, 0x0A, 0xB8,
    5,	_AUTOINC, 0x8B, 0x0D, 0xCC,
    5,	_AUTOINC, 0x8B, 0x0E, 0xCC,
    5,	_AUTOINC, 0x8B, 0x26, 0xBB,
    5,	_AUTOINC, 0x8B, 0x0F, 0x9C,
    5,	_AUTOINC, 0x8B, 0x10, 0xC1,
    5,	_AUTOINC, 0x8B, 0x11, 0xA9,
    5,	_AUTOINC, 0x8B, 0x12, 0xE0,
    5,	_AUTOINC, 0x8B, 0x13, 0x00,
    5,	_AUTOINC, 0x8B, 0x14, 0x00,
    5,	_AUTOINC, 0x8B, 0x15, 0x30,
    5,	_AUTOINC, 0x8B, 0x16, 0x00,
    5,	_AUTOINC, 0x8B, 0x17, 0x30,
    5,	_AUTOINC, 0x8B, 0x18, 0x00,
    5,	_AUTOINC, 0x8B, 0x19, 0xB8,
    5,	_AUTOINC, 0x8B, 0x1A, 0xB8,
    5,	_AUTOINC, 0x8B, 0x1B, 0x55,
    5,	_AUTOINC, 0x8B, 0x1D, 0x33,
    5,	_AUTOINC, 0x8B, 0x1E, 0x66,
    5,	_AUTOINC, 0x8B, 0x20, 0x10,
    5,	_AUTOINC, 0x8B, 0x21, 0x80,
    5,	_AUTOINC, 0x8B, 0x22, 0x00,
    5,	_AUTOINC, 0x8B, 0x23, 0xFF,
    5,	_AUTOINC, 0x8B, 0x24, 0x00,
    5,	_AUTOINC, 0x8B, 0x25, 0x00,
    5,	_AUTOINC, 0x8B, 0x27, 0x0F,
    5,	_AUTOINC, 0x8B, 0x28, 0x3F,
    5,	_AUTOINC, 0x8B, 0x29, 0xFF,
    5,	_AUTOINC, 0x8B, 0x2A, 0x00,
    5,	_AUTOINC, 0x8B, 0xA0, 0xB8,
    5,	_AUTOINC, 0x8B, 0xA1, 0x16,
    5,	_AUTOINC, 0x8B, 0xA2, 0x12,
    5,	_AUTOINC, 0x8B, 0xA3, 0x00,
    5,	_AUTOINC, 0x8B, 0xA4, 0x80,
    5,	_AUTOINC, 0x8B, 0xA5, 0x80,
    5,	_AUTOINC, 0x8B, 0xA6, 0x01,
    5,	_AUTOINC, 0x8B, 0xA9, 0x00,

    // Start CRC
    4,	_AUTOINC,	0x2C,	0x81,

    4,	_AUTOINC,	0x9F,	0x15,
    4,	_AUTOINC,	0xB0,	0x10,   // Start LVDS CRC

    _END
};

/*
//----------------------------------------------------------------------------------------------------
// mLVDS_8x Table         
//----------------------------------------------------------------------------------------------------
BYTE code tQC_MLVDS8X[] =
{
    // Display PLL
    4,	_AUTOINC,	0x9F,	0x01,
    4,	_AUTOINC,	0xBF,	0x28,           // M=54+2  // M= 54+2 test_cycle=2200~2295
    4,	_AUTOINC,	0xC0,	0x00,           // N=0+2 div2  // N= 0+2  div 2
    4,	_AUTOINC,	0xC1,	0x71,           // Icp = 7.4 ,Icp = 2.5+5
    4,	_AUTOINC,	0xC2,	0x09,           // power down dpll
    4,	_AUTOINC,	0xC2,	0x08,           // Power on DPLL

    // ----------- calibration start ------------------
    4,	_AUTOINC,	0xC3,	0x85, 	        // CMP enable	// 1000us -> 200us
    4,	_AUTOINC,	0xC3,	0x8D, 	        // latchca libration	// 1100us -> 201us
    4,	_AUTOINC,	0xC3,	0x9D, 	        // calibration valid	// 1200us -> 202us
    // ----------- calibration end ------------------

    // mLVDS_8x setting	
    5,	_AUTOINC, 0x8B, 0x00, 0x07,
    5,	_AUTOINC, 0x8B, 0xA0, 0x38,
    5,	_AUTOINC, 0x8B, 0x01, 0x00,
    5,	_AUTOINC, 0x8B, 0x02, 0x00,
    5,	_AUTOINC, 0x8B, 0x03, 0x00,
    5,	_AUTOINC, 0x8B, 0x04, 0x02,
    5,	_AUTOINC, 0x8B, 0x05, 0x00,
    5,	_AUTOINC, 0x8B, 0x06, 0x2D,
    5,	_AUTOINC, 0x8B, 0x07, 0x28,
    5,	_AUTOINC, 0x8B, 0x09, 0xB8,
    5,	_AUTOINC, 0x8B, 0x0A, 0xB8,
    5,	_AUTOINC, 0x8B, 0x0D, 0xCC,
    5,	_AUTOINC, 0x8B, 0x0E, 0xCC,
    5,	_AUTOINC, 0x8B, 0x26, 0x3B,
    5,	_AUTOINC, 0x8B, 0x0F, 0xDE,
    5,	_AUTOINC, 0x8B, 0x10, 0xC1,
    5,	_AUTOINC, 0x8B, 0x11, 0xA9,
    5,	_AUTOINC, 0x8B, 0x12, 0xE0,
    5,	_AUTOINC, 0x8B, 0x13, 0x00,
    5,	_AUTOINC, 0x8B, 0x14, 0x00,
    5,	_AUTOINC, 0x8B, 0x15, 0x30,
    5,	_AUTOINC, 0x8B, 0x16, 0x00,
    5,	_AUTOINC, 0x8B, 0x17, 0x30,
    5,	_AUTOINC, 0x8B, 0x18, 0x00,
    5,	_AUTOINC, 0x8B, 0x19, 0xB8,
    5,	_AUTOINC, 0x8B, 0x1A, 0xB8,
    5,	_AUTOINC, 0x8B, 0x1B, 0x00,
    5,	_AUTOINC, 0x8B, 0x1D, 0x33,
    5,	_AUTOINC, 0x8B, 0x1E, 0x00,
    5,	_AUTOINC, 0x8B, 0x20, 0x10,
    5,	_AUTOINC, 0x8B, 0x21, 0x80,
    5,	_AUTOINC, 0x8B, 0x22, 0x00,
    5,	_AUTOINC, 0x8B, 0x23, 0xFF,
    5,	_AUTOINC, 0x8B, 0x24, 0x00,
    5,	_AUTOINC, 0x8B, 0x25, 0x00,
    5,	_AUTOINC, 0x8B, 0x27, 0x0F,
    5,	_AUTOINC, 0x8B, 0x28, 0x3F,
    5,	_AUTOINC, 0x8B, 0x29, 0xFF,
    5,	_AUTOINC, 0x8B, 0x2A, 0x00,
    5,	_AUTOINC, 0x8B, 0xA0, 0xB8,
    5,	_AUTOINC, 0x8B, 0xA1, 0x16,
    5,	_AUTOINC, 0x8B, 0xA2, 0x12,
    5,	_AUTOINC, 0x8B, 0xA3, 0x00,
    5,	_AUTOINC, 0x8B, 0xA4, 0x80,
    5,	_AUTOINC, 0x8B, 0xA5, 0x80,
    5,	_AUTOINC, 0x8B, 0xA6, 0x01,
    5,	_AUTOINC, 0x8B, 0xA9, 0x00,

    // Start CRC
    4,	_AUTOINC,	0x2C,	0x81,

    4,	_AUTOINC,	0x9F,	0x15,
    4,	_AUTOINC,	0xB0,	0x10,   // Start LVDS CRC

    _END
};
*/

#else
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
    4,	_NON_AUTOINC,   0x2B,   0x03, 	    // Jeyu

    4,	_AUTOINC,	0x40,	0x02,	        // ivs to dvs

    // fixed last line for free-run mode
    4,	_AUTOINC,	0x9F,	0x01,
    7,	_AUTOINC,	0xC7,	0x63,0x30,0xC0,0x02,

    4,	_AUTOINC,	0x28,	0x87,    // free-run mode, force-to-background, single output, force enable
    4,	_AUTOINC,	0x29,	0x00,

    4,	_AUTOINC, 0x9F, 0x07,

    14, _AUTOINC,   0xF0,   0x85, 0x05, 0x05, 0x00, 0x04, 0x08, 0x01, 0x01, 0x01, 0x01, 0x00,
    _END
};

//----------------------------------------------------------------------------------------------------
// mLVDS_7x Tables
//----------------------------------------------------------------------------------------------------
BYTE code tQC_MLVDS7X[] =
{ 
    // pin share
    //5,  _AUTOINC,                   0x8B,                   0xA0, 0xFA,     // power-on lvds e/o //reset WD
    // Display PLL 
    // M N just useful for SD test , ICD simulation is depand upon "PERD_DPLL"
    // M=46+2=48, N=0+2=2
    // dpll: (14.318*48/2/1)/2*(7/8)= 150 MHz(FT even/odd pattern)
    // dclk: (single port) = 150/2 = 75 Mhz(FT even/odd pattern)

    4,  _AUTOINC,                   0x9F,                   0x01,
    4,  _AUTOINC,                   0xBF,                   0x1E,           //M=46+2
    4,  _AUTOINC,                   0xC0,                   0x00,           //N=0+2 div1 
    4,  _AUTOINC,                   0xC1,                   0x71,           // Icp = 7.4 ,Icp = 2.5+5
    4,  _AUTOINC,                   0xC2,                   0x19,           // power down dpll
    4,  _AUTOINC,                   0xC2,                   0x18,           // Power on DPLL

    // ----------- calibration start ------------------
    4,  _AUTOINC,                   0xC3,                   0x85,           // CMP enable   // 1000us -> 200us
    4,  _AUTOINC,                   0xC3,                   0x8D,           // latchca libration    // 1100us -> 201us
    4,  _AUTOINC,                   0xC3,                   0x9D,           // calibration valid    // 1200us -> 202us
    // ----------- calibration end ------------------

    // LVDS setting
    5,  _AUTOINC,                   0x8B,                   0x00, 0x01,
    5,  _AUTOINC,                   0x8B,                   0xA0, 0x78,
    5,  _AUTOINC,                   0x8B,                   0x01, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x02, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x03, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x04, 0xBE,
    5,  _AUTOINC,                   0x8B,                   0x05, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x06, 0x37,
    5,  _AUTOINC,                   0x8B,                   0x07, 0x38,
    5,  _AUTOINC,                   0x8B,                   0x0F, 0x84,
    5,  _AUTOINC,                   0x8B,                   0x10, 0x71,
    5,  _AUTOINC,                   0x8B,                   0x11, 0x49,
    5,  _AUTOINC,                   0x8B,                   0x12, 0xE0,
    5,  _AUTOINC,                   0x8B,                   0x13, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x14, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x15, 0x30,
    5,  _AUTOINC,                   0x8B,                   0x16, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x17, 0x30,
    5,  _AUTOINC,                   0x8B,                   0x18, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x19, 0xF8,
    5,  _AUTOINC,                   0x8B,                   0x1A, 0xF8,
    5,  _AUTOINC,                   0x8B,                   0x22, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x23, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x24, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x25, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x27, 0x0F,
    5,  _AUTOINC,                   0x8B,                   0x28, 0x3F,
    5,  _AUTOINC,                   0x8B,                   0x29, 0xFF,
    5,  _AUTOINC,                   0x8B,                   0x2A, 0x00,
    5,  _AUTOINC,                   0x8B,                   0xA0, 0xF8,
    5,  _AUTOINC,                   0x8B,                   0xA1, 0x14,
    5,  _AUTOINC,                   0x8B,                   0xA2, 0x13,
    5,  _AUTOINC,                   0x8B,                   0xA3, 0x00,
    5,  _AUTOINC,                   0x8B,                   0xA4, 0x80,
    5,  _AUTOINC,                   0x8B,                   0xA5, 0x80,
    5,  _AUTOINC,                   0x8B,                   0xA6, 0x01,
    5,  _AUTOINC,                   0x8B,                   0xA9, 0x00,

    // Start CRC
    4,  _AUTOINC,                   0x2C,                   0x81,
  
    _END
};
#endif

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE ScalerQCA0PortTest(void);
BYTE ScalerQCD0PortTest(void);
BYTE ScalerQCD1PortTest(void);

#if(_AUDIO_SUPPORT == _ON)
BYTE ScalerQCAudioTest(void);
#endif

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
bit ScalerQCDigitalFilterTest(void);
bit ScalerQCColorConversionTest(void);
bit ScalerQCIDitherTest(void);
bit ScalerQCUltravividTest(void);
bit ScalerQCADCHTest(void);
bit ScalerQCScaleUpTest(void);
bit ScalerQCHLWTest(void);
bit ScalerQCDDomainPGTest(void);
bit ScalerQCDCRTest(void);
bit ScalerQCDCCTest(void);     
bit ScalerQCICMTest(void);
bit ScalerQCCABCTest(void);
bit ScalerQCConBriTest(void);
bit ScalerQCGammaTest(void);
bit ScalerQCsRGBTest(void);
bit ScalerQCPCMTest(void);
void ScalerQCPCMSetShareOneLBuf(BYTE ucMode, bit bDoubleBuf);
void ScalerQCPCMRunShareOneLBuf(BYTE ucMode);
void ScalerQCPCMAdjustSU(bit bIs3L);
bit ScalerQCDDitherTest(void);
bit ScalerQCDisplayConversionTest(void);

bit ScalerQCScaleDownTest(void);

bit ScalerQCAPDTest(void);
bit ScalerQCDisplayConversionTest(void);
#if(_HDMI_SUPPORT == _ON)
bit ScalerQCHdmiTest(void);
#endif

#if(_DP_SUPPORT == _ON)
bit ScalerQCDpTest(void);
#endif

void ScalerQCIICSDA(bit ucset);
//void ScalerQCFPGA6xTable(void);
void ScalerQCFPGA7xTable(void);
//void ScalerQCFPGA8xTable(void);
void ScalerQCFPGACLRSCLK(void);
void ScalerQCFPGAConent(BYTE uctype, BYTE uccontent, BYTE *pucpass);
BYTE ScalerQCFPGAGetByte(void);
void ScalerQCFPGARead(BYTE ucAddr, BYTE *pucArray);
void ScalerQCFPGAReadStop(void);
void ScalerQCFPGASendAddr(BYTE ucAddr, bit ucReadWrite, bit ucAutoInc);
void ScalerQCFPGASendByte(BYTE ucValue);
void ScalerQCFPGASetByte(BYTE ucAddr, BYTE ucValue);
void ScalerQCFPGASetSCLK(void);
void ScalerQCFPGAWriteStop(void);
bit ScalerQCmLVDS(void);

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
    ucResult = (ucResult | ScalerQCIDomainRandomGenTest());    	                // I Domain Random Generator Test
    ucResult = (ucResult | ScalerQC422to444Test());    	    	                // YUV 422 to 444 Test
    ucResult = (ucResult | ScalerQCDigitalFilterTest());    	                // Digital Filter Test
    ucResult = (ucResult | ScalerQCColorConversionTest());    	                // Color Conversion Test
    ucResult = (ucResult | ScalerQCIDitherTest());    	    	                // I Dither Test
    ucResult = (ucResult | ((BYTE)ScalerQCUltravividTest() << 1));			    //Super Resolution Test        
    ucResult = (ucResult | ((BYTE)ScalerQCScaleUpTest() << 1));    	            // Scale Up Test
    ucResult = (ucResult | ((BYTE)ScalerQCHLWTest() << 1));                     // Highlight Window Test    
    ucResult = (ucResult | ((BYTE)ScalerQCDDomainPGTest() << 1));               // D Domain Pattern Generator Test
    ucResult = (ucResult | ((BYTE)ScalerQCDCRTest() << 2));    	                // DCR Test
    ucResult = (ucResult | ((BYTE)ScalerQCDCCTest() << 2));    	                // DCC Test
    ucResult = (ucResult | ((BYTE)ScalerQCICMTest() << 2));    	                // ICM Test
    ucResult = (ucResult | ((BYTE)ScalerQCCABCTest() << 2));    	            // CABC Test    
    ucResult = (ucResult | ((BYTE)ScalerQCConBriTest() << 2));    	            // Contrast & Brightness Test
    ucResult = (ucResult | ((BYTE)ScalerQCsRGBTest() << 2));    	            // sRGB Test        
    ucResult = (ucResult | ((BYTE)ScalerQCGammaTest() << 2));    	            // Output Gamma Test
    ucResult = (ucResult | ((BYTE)ScalerQCPCMTest() << 2));    	                // PCM tTest
    ucResult = (ucResult | ((BYTE)ScalerQCDDitherTest() << 2));    	            // D Diher Test
    ucResult = (ucResult | ((BYTE)ScalerQCDisplayConversionTest() << 1));    
    ucResult = (ucResult | ((BYTE)ScalerQCOSDTest() << 3));    	                // OSD Test
    
    ucResult = (ucResult | ((BYTE)ScalerQCAPDTest() << 4));                     // Adjacent Pix distance(APD) Test    
    
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
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    ucResult |= ScalerQCDpTest();
#endif

    ScalerSetByte(PC_FC_R_RESERVE2, ucResult);
    return ucResult;
}

//--------------------------------------------------
// Description  : Test Process for A0 Port
// Input Value  : None
// Output Value : Test Result
//                _BIT0 => HDMI Test                  
//                _BIT1 => Scaler Down Test                
//                _BIT2 => ADC Histogram Test                
//--------------------------------------------------
BYTE ScalerQCD1PortTest(void)
{
    BYTE ucResult = 0x00;
    
#if(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
    ucResult |= ScalerQCHdmiTest();
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    ucResult |= ScalerQCDpTest();
#endif

    // Scale Down Test
    ucResult = (ucResult | ((BYTE)ScalerQCScaleDownTest() << 1));

    // ADC Histogram Test
    ucResult = (ucResult | ((BYTE)ScalerQCADCHTest() << 2));			   // ADC Histogram Test

    // mLVDS Test
    ucResult = (ucResult | ((BYTE)ScalerQCmLVDS() << 3));
    
    ScalerSetByte(PC_FD_R_RESERVE3, ucResult);
    return ucResult;
}

//----------------------------------------------------------------------------
// Indivisual Test Block Process
//----------------------------------------------------------------------------
#if(_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Test Process for Audio
// Input Value  : None
// Output Value : Test Result
//--------------------------------------------------
BYTE ScalerQCAudioTest(void)
{
    BYTE ucResult = 0x00;

    DebugMessageScaler("5. Audio Test Start", 0x00);

    // Pop Up Current Received Packets
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_91_AUDIO_FREQDET_RESULT_M, ~_BIT4, _BIT4);
    
    ScalerTimerDelayXms(5);

    ScalerGetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_91_AUDIO_FREQDET_RESULT_M, 2, pData, _AUTOINC);
    PDATA_WORD(0) = (PDATA_WORD(0) & 0x0FFF);
    DebugMessageScaler("5. Detected Packet No.", PDATA_WORD(0));

    if((PDATA_WORD(0) > 52) || (PDATA_WORD(0) < 46))
    {
        ucResult |= _TEST_FAIL;
    }    

    // Clear Audio FIFO Empty/Full Flag
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_04_HDMI_AFSR, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));
    
    ScalerTimerDelayXms(100);

    if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_04_HDMI_AFSR, (_BIT3 | _BIT2)) != 0x00)
    {
        ucResult |= _TEST_FAIL << 1;
    }

    if((bit)ucResult != _TEST_PASS)
    {
        DebugMessageScaler("6. Audio Test Fail", ucResult);
    }
    else
    {
        DebugMessageScaler("6. Audio Test Pass", ucResult);
    }

    return ucResult;
}
#endif

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
    
    // Test mLVDS SRAM
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_20_DIS_FORMAT1, ~_BIT3, _BIT3);
    ScalerTimerDelayXms(10);
    if(ScalerGetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_20_DIS_FORMAT1, _BIT2) == _BIT2)
    {
        if(ScalerGetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_20_DIS_FORMAT1, _BIT1) != 0x00)
        {
            DebugMessageScaler("5. Display SRAM Bist Fail", 0x00);
            ucBistResult |= _BIT2;                    
        }
    }
    else
    {
        DebugMessageScaler("5. Display SRAM Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT2;        
    }
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_20_DIS_FORMAT1, ~_BIT3, 0x00);
    
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

#if(_AUDIO_SUPPORT == _ON)
    // Test Hdmi Audio FIFO
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_11_HDMI_MCAPR, 0x1A);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, 0x90);    
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, 0x50);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_62_HDMI_AOCR, 0xFF);
    
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, 0x10);
    ScalerTimerDelayXms(2);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, 0x11);
    ScalerTimerDelayXms(2);    
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, 0x13);
    ScalerTimerDelayXms(1);    
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, 0x17);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, 0x68);
    
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_04_HDMI_AFSR, ~_BIT4, _BIT4);
    ScalerTimerDelayXms(10);
    if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_04_HDMI_AFSR, _BIT4) == 0x00)
    {
        if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_04_HDMI_AFSR, _BIT5) != _BIT5)
        {
            DebugMessageScaler("5. Audio FIFO Bist Fail", 0x00);
            ucBistResult |= _BIT4;
        }
    }
    else
    {
        DebugMessageScaler("5. Audio FIFO Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT4;
    }

    // Audio DAC BIST Test
    ScalerSetBit(P6_BF_BIST_CONTROL, ~_BIT7, _BIT7);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P6_BF_BIST_CONTROL, _BIT5, _BIT5) == _TRUE)
    {
        if(ScalerGetBit(P6_BF_BIST_CONTROL, _BIT4) != 0x00)
        {
            DebugMessageScaler("5. Audio DAC Bist Fail", 0x00);
            ucBistResult |= _BIT4;
        }
    }
    else
    {
        DebugMessageScaler("5. Audio DAC Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT4;
    }
    ScalerSetBit(P6_BF_BIST_CONTROL, ~_BIT7, 0x00);
#endif

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
    ScalerSetByte(P7_FB_DISP_PG_RANDOM_CTRL, 0x00);
    ScalerSetByte(P7_FC_DISP_PG_INITIAL_LSB, 0x00);

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

        ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, 0x07, ~_BIT5, _BIT5);
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
        
        ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x81);
    }

    ScalerTimerWaitForEvent(ucWaitType);    	    	
    ScalerTimerWaitForEvent(ucWaitType);
    	    
    ScalerRead(CM_2D_OP_CRC_CKSM, 3, pData, _NON_AUTOINC);
    
    ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, 0x07, ~_BIT5, 0x00);
    
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
    ScalerSetBit(CM_8E_PS_DATA_PORT, ~(_BIT5), 0x00);
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
        ScalerSetBit(CM_8E_PS_DATA_PORT, ~(_BIT5), _BIT5);
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
// Description  : Enable miniLVDSCRC
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCminiLVDSCRCOn(BYTE ucCRC0, BYTE ucCRC1, BYTE ucCRC2, BYTE ucCRC3, BYTE ucCRC4, BYTE ucCRC5, BYTE ucCRC6, BYTE ucCRC7, 
                          BYTE ucCRC8, BYTE ucCRC9, BYTE ucCRC10, BYTE ucCRC11, BYTE ucCRC12, BYTE ucCRC13, BYTE ucCRC14, BYTE ucCRC15,
    	    	    	  BYTE ucCRC16, BYTE ucCRC17, BYTE ucCRC18, BYTE ucCRC19, BYTE ucCRC20, BYTE ucCRC21, BYTE ucCRC22, BYTE ucCRC23)
{
    BYTE ucData[24] = 0;
    
    ScalerSetBit(P15_B0_OP_CRC_CTRL, ~_BIT4, _BIT4);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    
    if(ScalerGetBit(P15_B0_OP_CRC_CTRL, _BIT3) == _BIT3)
    {
    	ScalerRead(P15_B2_OP_CRC_RESULT0, 24, ucData, _AUTOINC);
    }

    if((ucData[0] == ucCRC0) && (ucData[1] == ucCRC1) && (ucData[2] == ucCRC2) && (ucData[3] == ucCRC3) && (ucData[4] == ucCRC4) && (ucData[5] == ucCRC5) &&
       (ucData[6] == ucCRC6) && (ucData[7] == ucCRC7) && (ucData[8] == ucCRC8) && (ucData[9] == ucCRC9) && (ucData[10] == ucCRC10) && (ucData[11] == ucCRC11) &&
       (ucData[12] == ucCRC12) && (ucData[13] == ucCRC13) && (ucData[14] == ucCRC14) && (ucData[15] == ucCRC15) && (ucData[16] == ucCRC16) && (ucData[17] == ucCRC17) &&
       (ucData[18] == ucCRC18) && (ucData[19] == ucCRC19) && (ucData[20] == ucCRC20) && (ucData[21] == ucCRC21) && (ucData[22] == ucCRC22) && (ucData[23] == ucCRC23))    
    {
        DebugMessageScaler("5. ===Pass===",0x00);

    	return _FALSE;
    }
    else 
    {
        DebugMessageScaler("5. ucData[0]",ucData[0]);
        DebugMessageScaler("5. ucData[1]",ucData[1]);
        DebugMessageScaler("5. ucData[2]",ucData[2]);
        DebugMessageScaler("5. ucData[3]",ucData[3]);
        DebugMessageScaler("5. ucData[4]",ucData[4]);
        DebugMessageScaler("5. ucData[5]",ucData[5]);
        DebugMessageScaler("5. ucData[6]",ucData[6]);
        DebugMessageScaler("5. ucData[7]",ucData[7]);
        DebugMessageScaler("5. ucData[8]",ucData[8]);
        DebugMessageScaler("5. ucData[9]",ucData[9]);
        DebugMessageScaler("5. ucData[10]",ucData[10]);
        DebugMessageScaler("5. ucData[11]",ucData[11]);
        DebugMessageScaler("5. ucData[12]",ucData[12]);
        DebugMessageScaler("5. ucData[13]",ucData[13]);
        DebugMessageScaler("5. ucData[14]",ucData[14]);
        DebugMessageScaler("5. ucData[15]",ucData[15]);
        DebugMessageScaler("5. ucData[16]",ucData[16]);
        DebugMessageScaler("5. ucData[17]",ucData[17]);
        DebugMessageScaler("5. ucData[18]",ucData[18]);
        DebugMessageScaler("5. ucData[19]",ucData[19]);
        DebugMessageScaler("5. ucData[20]",ucData[20]);
        DebugMessageScaler("5. ucData[21]",ucData[21]);
        DebugMessageScaler("5. ucData[22]",ucData[22]);
        DebugMessageScaler("5. ucData[23]",ucData[23]);

        return _TRUE;
    }
}

//--------------------------------------------------
// Description  : Disable miniLVDSCRC
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCminiLVDSCRCOff(void)
{
    ScalerSetByte(P15_B0_OP_CRC_CTRL, 0x00);
}

//--------------------------------------------------
// Description  : Disable All Digital Function & Watch Dog 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCAllDigitalFunctionDisable(void)
{
    ScalerSetByte(CM_0C_WATCH_DOG_CTRL0, 0x00);    	// Disable Watch Dog
    ScalerSetByte(CM_0D_WATCH_DOG_CTRL1, 0x00);    	// Disable Watch Dog

    ScalerQCCheckCRCOff();    	    	    	    // Disable CRC Check
   
    ScalerSetByte(CM_28_VDISP_CTRL, 0x0F);    	    //VDIS_CTRL,       
                                                    //Frame Sync Mode Enable
                                                    //Display Output Double Port Enable
                                                    //Display Output Run Enable
                                                    //Display Timing Run Enable

    //--------------------I Domain------------------//
    ScalerQCIDomainRandomGenOff();    	    	    // Disable I Domain Random Generator
    ScalerSetByte(CM_1F_V8_YUV_CONVERSION, 0x00);   // Disable YUV422 to 444
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL, 0x70);    
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, 0x00);    // Y(G)/Pb(B)/Pr(R) Function Disable//Initial Value=0
    ScalerSetByte(CM_98_DIGITAL_FILTER_CTRL, 0x00);    // Disable Digital Filter
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    ScalerSetByte(CM_9C_YUV2RGB_CTRL, 0x00);    	// Disable Color Conversion

    ScalerSetByte(CM_89_I_DITHERING_CTRL1, 0x00);    // Disable I Domain Dither
    //--------------------D Domain------------------//
    ScalerQCHighlightWindowOff();     	    	    // Disable Highlight Window
    ScalerQCDDomainPatternGenOff();    	    	    // Disable D Domain Pattern Generator

    ScalerSetByte(P7_D8_DCR_ACCESS_PORT, 0x00);    	// Disable DCR
    ScalerSetByte(P7_C7_DCC_CTRL0, 0x00);    	    // Disable DCC
    ScalerSetByte(P7_D6_PKING_ACCESS_PORT, 0x00);    // Disable Y-Peaking
    ScalerSetByte(P7_D0_ICM_CTRL, 0x80);
    ScalerSetByte(P7_D1_ICM_SEL, 0x00);
    ScalerSetByte(P7_D0_ICM_CTRL, 0x00);    	    // Disable ICM
    ScalerSetByte(P9_A1_INPUT_GAMMA_CTRL, 0x00);    // Disable Input Gamma
    ScalerSetByte(CM_62_COLOR_CTRL, 0x00);    	    // Disable sRGB/Contrast/Brightness
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x00);    	    // Disable Output Gamma
   
    ScalerSetByte(CM_6C_OVERLAY_CTRL, 0x00);    	// Disable OSD

    ScalerSetByte(CM_6A_DITHERING_CTRL1, 0x00);    	// Disable D Domain Dither
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

    ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);    	    	     // Enable YUV422 to 444
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
    BYTE ucBackup0x9C = 0;
    BYTE ucBackup0x1F = 0;

    DebugMessageScaler("5. Color Conversion Start", 0x00);

    // Backup register 0x9C & 0x1F, which will be used here
    ucBackup0x9C = ScalerGetByte(CM_9C_YUV2RGB_CTRL);
    ucBackup0x1F = ScalerGetByte(CM_1F_V8_YUV_CONVERSION);

    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerTimerDelayXms(50);

    // dfilter -> color_conversion -> dithering -> HSD
    ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~_BIT7, 0x00);

    ////////////////////////////////////////////////////////////////////
    // RGB -> YUV
    ////////////////////////////////////////////////////////////////////
    // Enable YUV2RGB coefficient access
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT3, _BIT3);
    
    // h00 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h00 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xD9);
    // h01 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x02);
    // h01 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xDC);
    // h02 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h02 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x49);
    // h10 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xFF);
    // h10 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x8B);
    // h11 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xFE);
    // h11 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x76);
    // h12 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x02);
    // h12 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h20 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x02);
    // h20 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h21 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xFE);
    // h21 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x2F);
    // h22 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xFF);
    // h22 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xD2);

    //////////////////////////////////////////////////////////////////
    // case 0: RGB->YUV, enable y out shift, enable CbCr out shift, I Dither MSB
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, 0x00, _BIT7 | _BIT6 | _BIT4 | _BIT0);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Color Con case", 0x00);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0xD4, 0xC2, 0x50, _I_DOMAIN_CRC));

    //////////////////////////////////////////////////////////////////
    // case 1: RGB->YUV, enable y out shift, enable CbCr out shift, I Dither LSB
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, 0x00, _BIT7 | _BIT6 | _BIT4 | _BIT0);
   
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Color Con case", 0x01);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0x61, 0x5D, 0x80, _I_DOMAIN_CRC) << 1);

    //////////////////////////////////////////////////////////////////
    // case 2: RGB->YUV, bypass y out shift, bypass CbCr out shift, I Dither MSB
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, 0x00, _BIT4 | _BIT0);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Color Con case", 0x02);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0x60, 0x0C, 0x03, _I_DOMAIN_CRC) << 2);

    //////////////////////////////////////////////////////////////////
    // case 3: RGB->YUV, bypass y out shift, bypass CbCr out shift, I Dither LSB
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, 0x00, _BIT4 | _BIT0);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Color Con case", 0x03);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0x03, 0xB3, 0x91, _I_DOMAIN_CRC) << 3);

    // Disable YUV2RGB conversion
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);


    ////////////////////////////////////////////////////////////////////
    // YUV -> RGB
    ////////////////////////////////////////////////////////////////////
    // Enable YUV2RGB coefficient access
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT3, _BIT3);
    
    // h00 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x04);
    // h00 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h01 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h01 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h02 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x07);
    // h02 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x2C);
    // h10 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x04);
    // h10 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h11 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xFF);
    // h11 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x26);
    // h12 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xFD);
    // h12 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0xDE);
    // h20 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x04);
    // h20 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h21 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x08);
    // h21 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x73);
    // h22 high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // h22 low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // R offset high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // R offset low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // G offset high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // G offset low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // B offset high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // B offset low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // R gain high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x02);
    // R gain low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // G gain high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x02);
    // G gain low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);
    // B gain high
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x02);
    // B gain low
    ScalerSetByte(CM_9D_YUV_RGB_ACCESS, 0x00);

    //////////////////////////////////////////////////////////////////
    // case 4: YUV->RGB, enable y gain/offset, enable CbCr clamp, I Dither MSB
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, 0x00, _BIT2 | _BIT1 | _BIT0);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Color Con case", 0x04);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0x24, 0xD7, 0x04, _I_DOMAIN_CRC) << 4);

    //////////////////////////////////////////////////////////////////
    // case 5: YUV->RGB, enable y gain/offset, enable CbCr clamp, I Dither LSB
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, 0x00, _BIT2 | _BIT1 | _BIT0);
   
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Color Con case", 0x05);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0xAC, 0x40, 0x13, _I_DOMAIN_CRC) << 5);

    //////////////////////////////////////////////////////////////////
    // case 6: YUV->RGB, bypass y gain/offset, bypass CbCr clamp, I Dither MSB
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, 0x00, _BIT0);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Color Con case", 0x06);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0x0D, 0x65, 0x72, _I_DOMAIN_CRC) << 6);

    //////////////////////////////////////////////////////////////////
    // case 7: YUV->RGB, bypass y gain/offset, bypass CbCr clamp, I Dither LSB
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, 0x00, _BIT0);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Color Con case", 0x07);
    ucResult = ucResult | ((BYTE)ScalerQCCheckCRCOn(0xDD, 0x25, 0x12, _I_DOMAIN_CRC) << 7);

    // Recover register 0x9C & 0x1F
    ScalerSetByte(CM_9C_YUV2RGB_CTRL, ucBackup0x9C);
    ScalerSetByte(CM_1F_V8_YUV_CONVERSION, ucBackup0x1F);

    ScalerQCIDitherOff();
    ScalerQCIDomainRandomGenOff();
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
// Description  : LSR Test 
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCUltravividTest(void)
{
	BYTE ucData = 0;
	BYTE ucTemp[3] = {0};

    ScalerQCIDomainRandomGenOn(_MASS);
	ScalerSetBit(CM_10_VGIP_CTRL,~_BIT4,0x00);

    ucTemp[0] = ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES);
    ucTemp[1] = ScalerGetByte(CM_41_IV_DV_DELAY_CLK_ODD);    
       
    ScalerSetByte(P1_C6_DCLK_SPREAD_SPECTRUM, 0x04);// Display LVDS expread spectrum

    // 2D 4Line VSU
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xC4);
	

	DebugMessageScaler("5. Ultravivid Start", 0x00);
	ScalerQCIDomainRandomGenOn(_MASS);
	ScalerQCDDitherOn(_MSB);

	// LSR Setting 
    ScalerWrite(P14_C0_LSR_CTRL,26,tQC_ULTRAVIVID_SETTING ,_AUTOINC);    
	ScalerWrite(P14_E0_SR_VER_SOB_THD2_MSB,18,&tQC_ULTRAVIVID_SETTING[26],_AUTOINC); 	
    ScalerWrite(P11_CC_VPK_VCTI_HLW_H_START_HIGH,8,tQC_ULTRAVIVID_HLW,_AUTOINC);    
	ScalerSetByte(P14_C0_LSR_CTRL,0xF8);
		
	ScalerTimerWaitForEvent(_EVENT_IVS);
	
	// IRandomGen + DDither(_MSB)
	DebugMessageScaler("5. Mode_0", 0x00);
	
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xCB, 0x76, 0x1B, _D_DOMAIN_CRC) << 0));

	// IRandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
	ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7|_BIT6), _BIT7);	
	DebugMessageScaler("5. Mode_1", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x8F, 0xFE, 0xF2, _D_DOMAIN_CRC) << 1));

	// IRandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)	
	ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7|_BIT6), _BIT7 | _BIT6);	
	DebugMessageScaler("5. Mode_2", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xE5, 0x8A, 0x71, _D_DOMAIN_CRC) << 2));
	
	// IRandomGen +  DDither(_LSB)
	ScalerQCDDitherOn(_LSB);
	ScalerQCHighlightWindowOff();
	ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7|_BIT6), 0x00);	
	DebugMessageScaler("5. Mode_3", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xC9, 0xF5, 0x01, _D_DOMAIN_CRC) << 3));
	
	// IRandomGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
	ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7|_BIT6), _BIT7);	
	DebugMessageScaler("5. Mode_4", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xA6, 0x10, 0x64, _D_DOMAIN_CRC) << 4));
    
	ScalerSetByte(P14_C0_LSR_CTRL,0x00);          //disable LSR
	
	ScalerQCIDomainRandomGenOff();
    ScalerQCDDitherOff();	
	ScalerQCCheckCRCOff();   

    DebugMessageScaler("5. Ultravivid End", 0x00);
	if(ucData == 0x00)
	{
	   DebugMessageScaler("6. Ultravivid PASS", 0x00);
	   return _TEST_PASS;
	}
	else
	{
	   DebugMessageScaler("6. Fail Mode", ucData);
	   DebugMessageScaler("6. Ultravivid FAIL", 0x00);
	   return _TEST_FAIL;
	}	   
}

//--------------------------------------------------
// Description  : ADC Histogram Test 
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCADCHTest(void)
{
    BYTE ucData = 0;
    WORD usHStart = 0;
    WORD usVStart = 0;
	
    ScalerQCAllDigitalFunctionDisable();
    ScalerQCIDomainRandomGenOff();
    ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();

    DebugMessageScaler("5. ADC Histogram Start", 0x00);

    // Clear Input Status
    ScalerSetBit(CM_03_STATUS1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    if(ScalerMeasureActiveRegion(_DIGITAL_MODE_MEASURE, _NORMAL_MEASURE, _FULL_BOUNDARY, GET_INPUT_TIMING_HTOTAL()) == _TRUE)
    {
        usHStart = g_stActiveRegion.usHActiveStart;
        usVStart = g_stActiveRegion.usVActiveStart;
    }

    // Get Input Status
    if(ScalerGetBit(CM_03_STATUS1, (_BIT2 | _BIT1 | _BIT0)) != (_BIT2 | _BIT1 | _BIT0))
    {
        DebugMessageScaler("6. Fail Mode - No Input!!", 0x00);
        DebugMessageScaler("6. ADC Histogram FAIL", 0x00); 
        return _TEST_FAIL;
    }

    usHStart = usHStart + 30;
    usVStart = usVStart + 30;
	
    // Set ADC Histogram parameter 
    ScalerWrite(P1E_A0_HIST_BON_WIDTH_H, 4, tQC_ADCH_SETTING_FUNC1A, _AUTOINC);  

    ScalerSetByte(P1E_A4_HIST_HOR_START_H, (usHStart & 0x0F00) >> 8);
    ScalerSetByte(P1E_A5_HIST_HOR_START_L, usHStart & 0x00FF);
    ScalerSetByte(P1E_A6_HIST_VER_START_H, (usVStart & 0x0F00) >> 8);
    ScalerSetByte(P1E_A7_HIST_VER_START_L, usVStart & 0x00FF);

    //Enable Func1a  
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~_BIT2, _BIT2);	
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerRead(P1E_B1_FUNC1_RESULT1, 1, pData, _AUTOINC); 

    if((pData[0] & _BIT2) != _BIT2) 
    {
        ucData |= _BIT0;
        DebugMessageScaler("5. ===ucFunc1a===", pData[0]);                 
        DebugMessageScaler("5. ===Func1a Fail===", 0x00);
    }
    else
    {
        DebugMessageScaler("5. ===Func1a Pass===", 0x00);
    }	

    //Enable Func1b
    //Pattern Func1b(1)
    ScalerWrite(P1E_A8_DET_ROW_H , 4, &tQC_ADCH_SETTING_FUNC1B[0], _AUTOINC); 
    ScalerWrite(P1E_AD_FUNC1_CTRL1, 4, &tQC_ADCH_SETTING_FUNC1B[4], _AUTOINC); 
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~_BIT3, _BIT3);
    	
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerRead(P1E_B1_FUNC1_RESULT1, 16, pData, _AUTOINC);
	
    if(((pData[0] & _BIT0) != _BIT0) || (pData[1] != 0x02) || (pData[2] != 0x00) || (pData[3] != 0x00) || (pData[4] != 0x01) || (pData[5] != 0x01) || (pData[6] != 0x01) ||
        (pData[7] != 0x00) || (pData[8] != 0x21) || (pData[9] != 0x00) || (pData[10] != 0x2C) || (pData[11] != 0x00) || (pData[12] != 0x69) || (pData[13] != 0x01) ||
        (pData[14] != 0x01) || (pData[15] != 0x01))
    {
        ucData |= _BIT1;
        DebugMessageScaler("5. ===ucFunc1b[0]===", pData[0]);        
        DebugMessageScaler("5. ===ucFunc1b[1]===", pData[1]);        
        DebugMessageScaler("5. ===ucFunc1b[2]===", pData[2]);        
        DebugMessageScaler("5. ===ucFunc1b[3]===", pData[3]);        
        DebugMessageScaler("5. ===ucFunc1b[4]===", pData[4]);        
        DebugMessageScaler("5. ===ucFunc1b[5]===", pData[5]);        
        DebugMessageScaler("5. ===ucFunc1b[6]===", pData[6]);        
        DebugMessageScaler("5. ===ucFunc1b[7]===", pData[7]);        
        DebugMessageScaler("5. ===ucFunc1b[8]===", pData[8]);                
        DebugMessageScaler("5. ===ucFunc1b[9]===", pData[9]);          
        DebugMessageScaler("5. ===ucFunc1b[10]===", pData[10]);          
        DebugMessageScaler("5. ===ucFunc1b[11]===", pData[11]);          
        DebugMessageScaler("5. ===ucFunc1b[12]===", pData[12]);         
        DebugMessageScaler("5. ===ucFunc1b[13]===", pData[13]);          
        DebugMessageScaler("5. ===ucFunc1b[14]===", pData[14]);          
        DebugMessageScaler("5. ===ucFunc1b[15]===", pData[15]);             
        DebugMessageScaler("5. ===Func1b(1) Fail===", 0x00);
    }
    else
    {
        DebugMessageScaler("5. ===Func1b(1) Pass===", 0x00);
    }   
   
    //Enable Func1b
    //Pattern Func1b(2)
    ScalerWrite(P1E_AD_FUNC1_CTRL1 , 4, &tQC_ADCH_SETTING_FUNC1B[8], _AUTOINC); 
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~_BIT3, _BIT3);

    ScalerTimerWaitForEvent(_EVENT_DVS);			
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerRead(P1E_B1_FUNC1_RESULT1, 16, pData, _AUTOINC);	

    if(((pData[0] & _BIT0) != 0x00) || (pData[1] != 0x00) || (pData[2] != 0x00) || (pData[3] != 0x00) || (pData[4] != 0x00) ||(pData[5] != 0x00) || (pData[6] != 0x00) || 
        (pData[7] != 0x01) || (pData[8] != 0xF3) || (pData[9] != 0x00) || (pData[10] != 0x00) || (pData[11] != 0x00) || (pData[12] != 0x00) || (pData[13] != 0x01) ||
        (pData[14] != 0x00) || (pData[15] != 0x00))
    {
        ucData |= _BIT2;
        DebugMessageScaler("5. ===ucFunc1b[0]===", pData[0]);        
        DebugMessageScaler("5. ===ucFunc1b[1]===", pData[1]);        
        DebugMessageScaler("5. ===ucFunc1b[2]===", pData[2]);        
        DebugMessageScaler("5. ===ucFunc1b[3]===", pData[3]);        
        DebugMessageScaler("5. ===ucFunc1b[4]===", pData[4]);        
        DebugMessageScaler("5. ===ucFunc1b[5]===", pData[5]);        
        DebugMessageScaler("5. ===ucFunc1b[6]===", pData[6]);        
        DebugMessageScaler("5. ===ucFunc1b[7]===", pData[7]);        
        DebugMessageScaler("5. ===ucFunc1b[8]===", pData[8]);                
        DebugMessageScaler("5. ===ucFunc1b[9]===", pData[9]);          
        DebugMessageScaler("5. ===ucFunc1b[10]===", pData[10]);          
        DebugMessageScaler("5. ===ucFunc1b[11]===", pData[11]);          
        DebugMessageScaler("5. ===ucFunc1b[12]===", pData[12]);         
        DebugMessageScaler("5. ===ucFunc1b[13]===", pData[13]);          
        DebugMessageScaler("5. ===ucFunc1b[14]===", pData[14]);          
        DebugMessageScaler("5. ===ucFunc1b[15]===", pData[15]);          

        DebugMessageScaler("5. ===Func1b(2) Fail===", 0x00);        
    }
    else
    {
        DebugMessageScaler("5. ===Func1b(2) Pass===", 0x00);
    }	

    //Enable Func2
    //Pattern Func2(1)
    ScalerWrite(P1E_C1_FUNC2_CTRL1, 6, &tQC_ADCH_SETTING_FUNC2[0], _AUTOINC);  
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~_BIT1, _BIT1);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);    	

    ScalerRead(P1E_C7_TONE1_NUM_H, 10, pData, _AUTOINC);    

    if((pData[0] != 0x32) || (pData[1] != 0xC8) || (pData[2] != 0x3F) || (pData[3] != 0xFF) || (pData[4] != 0x3F) || (pData[5] != 0xFF) || (pData[6] != 0x3F) ||
       (pData[7] != 0xFF) || (pData[8] != 0x00) || (pData[9] != 0x03))
    {
        ucData |= _BIT3;
        DebugMessageScaler("5. ===ucFunc2[0]===", pData[0]);        
        DebugMessageScaler("5. ===ucFunc2[1]===", pData[1]);        
        DebugMessageScaler("5. ===ucFunc2[2]===", pData[2]);        
        DebugMessageScaler("5. ===ucFunc2[3]===", pData[3]);        
        DebugMessageScaler("5. ===ucFunc2[4]===", pData[4]);        
        DebugMessageScaler("5. ===ucFunc2[5]===", pData[5]);        
        DebugMessageScaler("5. ===ucFunc2[6]===", pData[6]);        
        DebugMessageScaler("5. ===ucFunc2[7]===", pData[7]);        
        DebugMessageScaler("5. ===ucFunc2[8]===", pData[8]);                
        DebugMessageScaler("5. ===ucFunc2[9]===", pData[9]);                        
        DebugMessageScaler("5. ===Func2(1) Fail===", 0x00);
    }
    else
    {
        DebugMessageScaler("5. ===Func2(1) Pass===", 0x00);
    }   

    //Enable Func2
    //Pattern Func2(2)
    ScalerWrite(P1E_C1_FUNC2_CTRL1 ,6, &tQC_ADCH_SETTING_FUNC2[6], _AUTOINC);  
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~_BIT1, _BIT1);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerRead(P1E_C7_TONE1_NUM_H, 10, pData, _AUTOINC);  

    if((pData[0] != 0x39) || (pData[1] != 0x5C) || (pData[2] != 0x3F) || (pData[3] != 0xFF) || (pData[4] != 0x3F) || (pData[5] != 0xFF) || (pData[6] != 0x3F) ||
       (pData[7] != 0xFF) || (pData[8] != 0x03) || (pData[9] != 0x33))
    {
        ucData |= _BIT4;
        DebugMessageScaler("5. ===ucFunc2[0]===", pData[0]);        
        DebugMessageScaler("5. ===ucFunc2[1]===", pData[1]);        
        DebugMessageScaler("5. ===ucFunc2[2]===", pData[2]);        
        DebugMessageScaler("5. ===ucFunc2[3]===", pData[3]);        
        DebugMessageScaler("5. ===ucFunc2[4]===", pData[4]);        
        DebugMessageScaler("5. ===ucFunc2[5]===", pData[5]);        
        DebugMessageScaler("5. ===ucFunc2[6]===", pData[6]);        
        DebugMessageScaler("5. ===ucFunc2[7]===", pData[7]);        
        DebugMessageScaler("5. ===ucFunc2[8]===", pData[8]);                
        DebugMessageScaler("5. ===ucFunc2[9]===", pData[9]);           
        DebugMessageScaler("5. ===Func2(2) Fail===", 0x00);
    }
    else
    {
        DebugMessageScaler("5. ===Func2(2) Pass===", 0x00);        
    }   

    DebugMessageScaler("5. ADC Histogram End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. ADC Histogram PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. ADC Histogram FAIL", 0x00);
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
    BYTE ucTemp[3] = {0};
    BYTE ucI = 0;
    BYTE ucFlag = 0;
    DebugMessageScaler("5. Scale Up Start", 0x00);
    
    ScalerQCIDomainRandomGenOn(_MASS);

    ucTemp[0] = ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES);
    ucTemp[1] = ScalerGetByte(CM_41_IV_DV_DELAY_CLK_ODD);    

    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT4, 0x00);   
       
    ScalerSetByte(P1_C6_DCLK_SPREAD_SPECTRUM, 0x04);// Display LVDS expread spectrum

    // 2D 4Line VSU
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xC4);
    
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x20, 0x00, 0xA5, _D_DOMAIN_CRC) << 0));

    // 2D 3Line VSU
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0x44);
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~(_BIT6), _BIT6);

    ScalerSetBit(CM_38_PCM_SHARE_LINE_BUFFER, ~_BIT7, _BIT7);

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
    
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x02, 0x45, 0xFE, _D_DOMAIN_CRC) << 2));    
  
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~(_BIT6), 0x00);

    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);  
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xC4);
    ScalerSetBit(CM_38_PCM_SHARE_LINE_BUFFER, ~_BIT7, 0x00); 

    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0]);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucTemp[1]);  
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x99, 0x11, 0xBE, _D_DOMAIN_CRC) << 0));

    // RandomGen + HLW(Bottom & Right border);
    DebugMessageScaler("5. Mode_1", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x08, 0x2A, 0x43, _D_DOMAIN_CRC) << 1));

    // RandomGen + HLW(Top & Right border);
    DebugMessageScaler("5. Mode_2", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT4));
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x4E, 0xD4, 0x30, _D_DOMAIN_CRC) << 2));

    // RandomGen + HLW(Top & Left border);
    DebugMessageScaler("5. Mode_3", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x46, 0xE4, 0xC3, _D_DOMAIN_CRC) << 3));

    // RandomGen + HLW(Bottom & Left border);
    DebugMessageScaler("5. Mode_4", 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x6A, 0xD5, 0x69, _D_DOMAIN_CRC) << 4));

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
    ucError = ucError|((BYTE)ScalerQCCheckCRCOn(0x59, 0xE1, 0x0B,  _D_DOMAIN_CRC) << 6);  
    

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

    ScalerSetByte(P7_C7_DCC_CTRL0, 0x90);
    ScalerSetByte(P7_C8_DCC_CTRL1, 0x80);

    // RandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerTimerWaitForEvent(_EVENT_DVS);    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x1C, 0x73, 0x67, _D_DOMAIN_CRC) << 0));

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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x5E, 0x2F, 0x16, _D_DOMAIN_CRC) << 1));
	 
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3);
    // Fill DCC control table
    // Select page0
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x03);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x01);
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFC, 0x1A, 0xD8, _D_DOMAIN_CRC) << 2));

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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFD, 0x33, 0x83, _D_DOMAIN_CRC) << 3));
    
    ScalerQCHighlightWindowOff();
    ScalerQCIDomainRandomGenOff();

    ScalerQCDDomainRandomGenOn(_MASS);   
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

    ScalerSetBit(P7_C7_DCC_CTRL0, ~_BIT7, 0x00);    	           // Disable DCC
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

    if((pData[0]!=0x08) || (pData[1]!=0x90) || (pData[2]!=0x1A) || (pData[3]!=0xEA) || (pData[4]!=0x92) || (pData[5]!=0x28) || (pData[6]!=0x3F) ||
       (pData[7]!=0x06) || (pData[8]!=0xFF) || (pData[9]!=0x00) || (pData[10]!=0xAA) || (pData[11]!=0xE4) || (pData[12]!=0x01) || (pData[13]!=0x95) ||
       (pData[14]!=0x38) || (pData[15]!=0xB3) || (pData[16]!=0x5A) || (pData[17]!=0x02) || (pData[18]!=0x5D) || (pData[19]!=0x01) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0x5B) || (pData[23]!=0x57) || (pData[24]!=0x5E) || (pData[25]!=0x48) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0x5B) || (pData[29]!=0x49) || (pData[30]!=0x5E) || (pData[31]!=0x00) || (pData[32]!=0xFF) || (pData[33]!=0x00))
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

    if((pData[0]!=0x08) || (pData[1]!=0x90) || (pData[2]!=0x1A) || (pData[3]!=0xEA) || (pData[4]!=0x92) || (pData[5]!=0x28) || (pData[6]!=0x3F) ||
       (pData[7]!=0x06) || (pData[8]!=0xFF) || (pData[9]!=0x00) || (pData[10]!=0xAA) || (pData[11]!=0xE4) || (pData[12]!=0x01) || (pData[13]!=0x95) ||
       (pData[14]!=0x38) || (pData[15]!=0xB3) || (pData[16]!=0x5A) || (pData[17]!=0x02) || (pData[18]!=0x5D) || (pData[19]!=0x01) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0x5B) || (pData[23]!=0x57) || (pData[24]!=0x5E) || (pData[25]!=0x48) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0x5B) || (pData[29]!=0x49) || (pData[30]!=0x5E) || (pData[31]!=0x00) || (pData[32]!=0xFF) || (pData[33]!=0x00))
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

    if((pData[0]!=0x08) || (pData[1]!=0x90) || (pData[2]!=0x05) || (pData[3]!=0x2B) || (pData[4]!=0x23) || (pData[5]!=0x07) || (pData[6]!=0xB6) ||
       (pData[7]!=0x20) || (pData[8]!=0xCE) || (pData[9]!=0x00) || (pData[10]!=0x20) || (pData[11]!=0xA8) || (pData[12]!=0x00) || (pData[13]!=0x4D) ||
       (pData[14]!=0x6B) || (pData[15]!=0xAB) || (pData[16]!=0x11) || (pData[17]!=0x3C) || (pData[18]!=0x12) || (pData[19]!=0x29) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0x11) || (pData[23]!=0x02) || (pData[24]!=0x12) || (pData[25]!=0xBE) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0x10) || (pData[29]!=0xF2) || (pData[30]!=0x12) || (pData[31]!=0x98) || (pData[32]!=0xFF) || (pData[33]!=0x00))
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

    if((pData[0]!=0x08) || (pData[1]!=0x90) || (pData[2]!=0x15) || (pData[3]!=0x33) || (pData[4]!=0x83) || (pData[5]!=0x1F) || (pData[6]!=0xB7) ||
       (pData[7]!=0xA5) || (pData[8]!=0x74) || (pData[9]!=0x00) || (pData[10]!=0x86) || (pData[11]!=0xD7) || (pData[12]!=0x01) || (pData[13]!=0x3F) ||
       (pData[14]!=0xC2) || (pData[15]!=0x69) || (pData[16]!=0x47) || (pData[17]!=0x16) || (pData[18]!=0x49) || (pData[19]!=0x05) || (pData[20]!=0xFF) ||
       (pData[21]!=0x00) || (pData[22]!=0x48) || (pData[23]!=0x8E) || (pData[24]!=0x49) || (pData[25]!=0x9E) || (pData[26]!=0xFF) || (pData[27]!=0x00) ||
       (pData[28]!=0x48) || (pData[29]!=0x8C) || (pData[30]!=0x49) || (pData[31]!=0x91) || (pData[32]!=0xFF) || (pData[33]!=0x00))
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
    BYTE ucError = 0;
    BYTE ucError1 = 0;
    
    DebugMessageScaler("5. ICM Start", 0x00);

    // Old ICM
    // Random + MSB
    ScalerQCIDomainRandomGenOn(_MASS);
    
    ScalerSetByte(P7_D1_ICM_SEL, 0x00);    	    	// CM0
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify0, sizeof(tQC_ICM_Modify0), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x01);    	    	// CM1
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify1, sizeof(tQC_ICM_Modify1), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x02);    	    	// CM2
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify2, sizeof(tQC_ICM_Modify2), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x03);    	    	// CM3
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify3, sizeof(tQC_ICM_Modify3), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x04);    	    	// CM4
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify4, sizeof(tQC_ICM_Modify4), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x05);    	    	// CM5
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x00);
    ScalerBurstWrite(tQC_ICM_Modify5, sizeof(tQC_ICM_Modify5), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    //dy = (8dU+dV)/8,delta = -128~127
    ScalerSetByte(P7_D0_ICM_CTRL,  0x9f);          // Enable CM0~CM4
    ScalerSetBit(P7_D1_ICM_SEL, ~_BIT3, _BIT3);    //Enable CM5
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_0", ucError);
    ucError = (BYTE)ScalerQCCheckCRCOn(0xF0, 0x31, 0x03, _D_DOMAIN_CRC);     

    //dy = (6dU+dV)/8,delta = -256~254, 
    ScalerSetByte(P7_D0_ICM_CTRL,  0xff); 
    ScalerSetBit(P7_D1_ICM_SEL, ~_BIT4, _BIT4);    //delta UV *4
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_1", ucError);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x40, 0x3A, 0x17, _D_DOMAIN_CRC)<<1);      
            
    // Random + Highlight Window + MSB  Full Window   
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 full window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_2", ucError);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x36, 0x6A, 0x7E, _D_DOMAIN_CRC)<<2);       
      
    // Random + Highlight Window + MSB  Inside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_3", ucError);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x23, 0x56, 0xFD, _D_DOMAIN_CRC)<<3);      

    // Random + Highlight Window + MSB  Outside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3); // 10 outside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. ICM Case_4", ucError);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x8C, 0x2D, 0x3D, _D_DOMAIN_CRC)<<4);       
      
    // D_Random + Highlight Window + LSB Outside Window
    ScalerQCIDomainRandomGenOff();
    ScalerQCDDomainRandomGenOn(_MASS);
    
    ScalerQCDDitherOn(_LSB);
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. ICM Case_5", ucError);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xBF, 0x24, 0xAE, _D_DOMAIN_CRC)<<6);

    // D_Random + HW + LSB  Inside Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    DebugMessageScaler("5. ICM Case_6", ucError);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xF1, 0x3B, 0xFF, _D_DOMAIN_CRC)<<6);

    // D_Random + HW + LSB  Full Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 Full window
    DebugMessageScaler("5. ICM Case_7", ucError);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x14, 0x03, 0x11, _D_DOMAIN_CRC)<<6);

    // Disable ICM CM    
    ScalerSetByte(P7_D0_ICM_CTRL, 0x80);  
    ScalerSetByte(P7_D1_ICM_SEL,  0x00); 
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT,  0x00);

    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCDDomainPatternGenOff();

    // New ICM
    // Random + MSB
    ScalerQCIDomainRandomGenOn(_MASS);
    // Disable ICM CM    
    ScalerSetByte(P7_D0_ICM_CTRL, 0x00);  
    ScalerSetByte(P7_D1_ICM_SEL,  0x00); 
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT,  0x00);

    ScalerSetByte(P7_D1_ICM_SEL, 0x00);    	    	// CM0
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);    
    ScalerBurstWrite(tQC_New_ICM_Modify0, sizeof(tQC_New_ICM_Modify0), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x01);    	    	// CM1
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify1, sizeof(tQC_New_ICM_Modify1), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x02);    	    	// CM2
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify2, sizeof(tQC_New_ICM_Modify2), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x03);    	    	// CM3
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify3, sizeof(tQC_New_ICM_Modify3), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x04);    	    	// CM4
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify4, sizeof(tQC_New_ICM_Modify4), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetByte(P7_D1_ICM_SEL, 0x05);    	    	// CM5
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
    ScalerBurstWrite(tQC_New_ICM_Modify5, sizeof(tQC_New_ICM_Modify5), GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    //dy = (8dU+dV)/8,delta = -128~127 
    ScalerSetByte(P7_D0_ICM_CTRL,  0x9f);         // Enable CM0~CM4
    ScalerSetBit(P7_D1_ICM_SEL, ~_BIT3, _BIT3);   //Enable CM5
    ScalerSetByte(P7_D4_ICM_NEW_MODE, 0x04);      // Enable New ICM Mode, buffer offset == 0,Max Compensate off
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_0", ucError1);
    ucError = (BYTE)ScalerQCCheckCRCOn(0x1E, 0x9A, 0x88, _D_DOMAIN_CRC);

    //dy = (6dU+dV)/8,delta = -256~255, Neg Compensate,     
    ScalerSetByte(P7_D0_ICM_CTRL,  0xFF); 
    ScalerSetBit(P7_D1_ICM_SEL, ~_BIT4, _BIT4);    //delta UV *4
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~_BIT7, _BIT7);// Neg Compensate 
    ScalerSetBit(P7_D4_ICM_NEW_MODE, ~_BIT1, _BIT1); // buffer != 0
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_1", ucError1);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xE1, 0xE3, 0x50, _D_DOMAIN_CRC)<<1);    

    //dy = (6dU+dV)/8,delta = -128~127, Max Compensate, delta UV *4, buffer offset != 0 
    	
    ScalerSetBit(P7_D4_ICM_NEW_MODE, ~_BIT0, _BIT0);// Max Compensate Open
    ScalerSetBit(P7_D4_ICM_NEW_MODE, ~_BIT1, _BIT1);//buffer offset != 0  
    ScalerSetByte(P7_D0_ICM_CTRL,  0x00);   
    ScalerSetByte(P7_D0_ICM_CTRL,  0xDf);   
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~_BIT7, 0);// Neg Compensate off
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_2", ucError1);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x09, 0xDF, 0xF2, _D_DOMAIN_CRC)<<2);

       
    // Random + Highlight Window   

    ScalerQCHighlightWindowOn();

    // Random + Highlight Window + MSB  Inside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_3", ucError1);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x75, 0x75, 0xF8, _D_DOMAIN_CRC)<<4);     

    // Random + Highlight Window + MSB  Outside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3); // 10 outside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_4", ucError1);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xC4, 0xAA, 0x1F, _D_DOMAIN_CRC)<<5);      

    // D_Random + Highlight Window + LSB Outside Window
    ScalerQCIDomainRandomGenOff();
    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_LSB);
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. New ICM Case_5", ucError1);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x92, 0xBA, 0x4D, _D_DOMAIN_CRC)<<5); 

    // D_Random + HW + LSB  Inside Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    DebugMessageScaler("5. New ICM Case_6", ucError1);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x2E, 0x35, 0x36, _D_DOMAIN_CRC)<<6);

    // D_Random + HW + LSB  Full Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 Full window
    DebugMessageScaler("5. New ICM Case_7", ucError1);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xE6, 0x93, 0x3B, _D_DOMAIN_CRC)<<6);

    // Disable ICM
    ScalerSetBit(P7_D1_ICM_SEL,  ~(_BIT3), 0x00); 
    ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT4|_BIT3|_BIT2|_BIT1|_BIT0), 0x00);   
    ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT7), 0x00);   

    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCDDomainPatternGenOff();
    ScalerQCCheckCRCOff();      

  	DebugMessageScaler("5. ICM End", 0x00);
    
    if((ucError == 0)&&(ucError1 == 0))
    {
    	DebugMessageScaler("6. ICM PASS", 0x00);
    	return _TEST_PASS;
    }
    else
    {
    	DebugMessageScaler("6. Fail Mode", (ucError<<8) | ucError1);
        DebugMessageScaler("6. ICM FAIL", 0x00);
        return _TEST_FAIL;    
    }    
}

//--------------------------------------------------
// Description  : CABC Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCCABCTest(void)
{
    BYTE ucData = 0;
    BYTE pData[18] = 0;

    DebugMessageScaler("5. CABC Start", 0x00);
    ScalerQCDDomainRandomGenOn(_MASS);
    ScalerQCHighlightWindowOn();    

    // D_RandomGen + IN/OUT WINDOW
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), 0x00);

    // Setting Hormalized Factor
    ScalerSetDataPortByte(P7_DC_CABC_ADDRESS_PORT, _P7_DD_PT_00_NOR_FACTOR_H, 0x00);
    ScalerSetDataPortByte(P7_DC_CABC_ADDRESS_PORT, _P7_DD_PT_01_NOR_FACTOR_M, 0x02);
    ScalerSetDataPortByte(P7_DC_CABC_ADDRESS_PORT, _P7_DD_PT_02_NOR_FACTOR_L, 0x5E);

    // Enable CABC Histogram
    ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT2, _BIT2);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageScaler("5. Mode_0", 0x00);
    ScalerSetByte(P7_DC_CABC_ADDRESS_PORT , 0x00);  
    ScalerRead(P7_DD_CABC_DATA_PORT, 18, pData, _NON_AUTOINC);

    if((pData[0] != 0x00) || (pData[1] != 0x02) || (pData[2] != 0x5E) || (pData[3] != 0x00) || (pData[4] !=0x00) || (pData[5] != 0x02) || (pData[6] != 0x04) ||
       (pData[7] != 0x08) || (pData[8] != 0x0D) || (pData[9] != 0x15) || (pData[10] != 0x20) || (pData[11] !=0x2D) || (pData[12] != 0x3E) || (pData[13] != 0x52) ||
       (pData[14] != 0x6B) || (pData[15] != 0x88) || (pData[16] != 0xAA) || (pData[17] != 0xD2))
    {
        ucData = ucData | _BIT0;
    }

    // Disabled CABC Histogram
    ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT2, 0x00);

    // D_RandomGen + INSIDE WINDOW
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), _BIT4);

    // Setting Hormalized Factor
    ScalerSetDataPortByte(P7_DC_CABC_ADDRESS_PORT, _P7_DD_PT_00_NOR_FACTOR_H, 0x00);
    ScalerSetDataPortByte(P7_DC_CABC_ADDRESS_PORT, _P7_DD_PT_01_NOR_FACTOR_M, 0x0C);
    ScalerSetDataPortByte(P7_DC_CABC_ADDRESS_PORT, _P7_DD_PT_02_NOR_FACTOR_L, 0x56);

    // Enable CABC Histogram
    ScalerSetBit(P7_DB_CABC_CTRL, ~(_BIT2), _BIT2);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageScaler("5. Mode_1", 0x00);
    ScalerSetByte(P7_DC_CABC_ADDRESS_PORT , 0x00);  
    ScalerRead(P7_DD_CABC_DATA_PORT, 18, pData, _NON_AUTOINC);

    if((pData[0] != 0x00) || (pData[1] != 0x0C) || (pData[2] != 0x56) || (pData[3] != 0x00) || (pData[4] != 0x01) || (pData[5] != 0x02) || (pData[6] != 0x04) ||
       (pData[7] != 0x08) || (pData[8] != 0x0D) || (pData[9] != 0x15) ||(pData[10] != 0x20) || (pData[11] != 0x2D) || (pData[12] != 0x3E) || (pData[13] != 0x53) ||
       (pData[14] != 0x6B) ||(pData[15] != 0x89) || (pData[16] != 0xAB) || (pData[17] != 0xD2))
    {
        ucData = ucData | _BIT1;
    }

    // Disabled CABC Histogram
    ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT2, 0x00);

    // D_RandomGen + OUTSIDE WINDOW
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), _BIT5);

    // Setting Hormalized Factor
    ScalerSetDataPortByte(P7_DC_CABC_ADDRESS_PORT, _P7_DD_PT_00_NOR_FACTOR_H, 0x00);
    ScalerSetDataPortByte(P7_DC_CABC_ADDRESS_PORT, _P7_DD_PT_01_NOR_FACTOR_M, 0x03);
    ScalerSetDataPortByte(P7_DC_CABC_ADDRESS_PORT, _P7_DD_PT_02_NOR_FACTOR_L, 0x02);

    // Enable CABC Histogram
    ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT2, _BIT2);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageScaler("5. Mode_2", 0x00);
    ScalerSetByte(P7_DC_CABC_ADDRESS_PORT , 0x00);  
    ScalerRead(P7_DD_CABC_DATA_PORT, 18, pData, _NON_AUTOINC);

    if((pData[0] != 0x00) || (pData[1] != 0x03) || (pData[2] != 0x02) || (pData[3] != 0x00) || (pData[4] !=0x00) || (pData[5] != 0x02) || (pData[6] != 0x04) ||
       (pData[7] != 0x08) || (pData[8] != 0x0D) || (pData[9] != 0x15) || (pData[10] != 0x20) || (pData[11] !=0x2D) || (pData[12] != 0x3E) || (pData[13] != 0x52) ||
       (pData[14] != 0x6B) || (pData[15] != 0x88) || (pData[16] != 0xAA) || (pData[17] != 0xD2))
    {
        ucData = ucData | _BIT2;
    }

    // Disabled CABC Histogram
    ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT2, 0x00);
    ScalerQCIDomainRandomGenOff();
    ScalerQCHighlightWindowOff();
    ScalerQCDDomainPatternGenOff();

    DebugMessageScaler("5. CABC End", 0x00);    
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. CABC PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. CABC FAIL", 0x00);
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
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));    	      // Enable Contrast & Brightness
    // RandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x89, 0xFC, 0x41, _D_DOMAIN_CRC) << 0));
    // RandomGen + HLW(_IN(A)/OUTSIDE(A)_WINDOW + Bottom&Right border) + DDither(_MSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), 0x00);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x33, 0x76, 0xCD, _D_DOMAIN_CRC) << 1));
    // RandomGen + HLW(_INSIDE(B)_WINDOW + Top&Left border) + DDither(_MSB)
    ScalerQCHighlightWindowOn();
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x8F, 0x3F, 0x93, _D_DOMAIN_CRC) << 2));
    // RandomGen + HLW(_OUTSIDE(A)_WINDOW + Bottom&Left border) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEE, 0xED, 0x4B, _D_DOMAIN_CRC) << 3));
    // RandomGen + HLW(_IN(B)/OUTSIDE(A)_WINDOW + Top&Right border) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x03, 0x66, 0x24, _D_DOMAIN_CRC) << 4));
    
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEF, 0xE6, 0x6C, _D_DOMAIN_CRC) << 2));	//Ryan for 6247 Con/Bri QC D-domain RandomGen
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

    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT1 | _BIT0), 0x00);    	           // Disable Contrast & Brightness
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
    
    ScalerQCPCMSetShareOneLBuf(0, _FALSE); 

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x80);
    ScalerBurstWrite(&tOutputGammaR[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0x90);
    ScalerBurstWrite(&tOutputGammaG[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetByte(CM_67_GAMMA_CTRL, 0xA0);
    ScalerBurstWrite(&tOutputGammaB[24], 387, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, 0x00); // Disable Access Port
    
    ScalerQCPCMRunShareOneLBuf(0);

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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2F, 0x2E, 0x08, _D_DOMAIN_CRC) << 1)); // I-domain:0x77, 0x2B, 0xF8,
    
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xD4, 0xE7, 0xB0, _D_DOMAIN_CRC) << 2)); // I-domain:0x9A, 0x86, 0x00,
    
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xCD, 0x3A, 0x82, _D_DOMAIN_CRC) << 5)); // I-domain:0x8E, 0xEE, 0xE1,
    
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_6", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xB2, 0x2D, 0xB2, _D_DOMAIN_CRC) << 6)); // I-domain:0x86, 0xC7, 0x49,
    
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

    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);

    // Share one line buffer Start
    ScalerQCPCMAdjustSU(_ON); // 3L     
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    
    
    ScalerQCPCMSetShareOneLBuf(1, _FALSE);   

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    // input Gamma 
    ScalerSetBit(CM_67_GAMMA_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0xB0); 
    ScalerBurstWrite(tInputGamma, 101, GET_CURRENT_BANK_NUMBER(), CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    PDATA_WORD(0) = 0;
    // SRGB 
    ScalerSetBit(CM_67_GAMMA_CTRL, ~(_BIT7|_BIT6|_BIT5|_BIT4|_BIT3|_BIT2), 0xB4);
    ScalerWrite(CM_66_GAMMA_PORT, 6, &tSRGBMatrix[0], _NON_AUTOINC); // RR,RG, RB
    ScalerWrite(CM_66_GAMMA_PORT, 6, &tSRGBMatrix[8], _NON_AUTOINC); // GR, GG, GB
    ScalerWrite(CM_66_GAMMA_PORT, 6, &tSRGBMatrix[16], _NON_AUTOINC);// BR, BG, BB
    
    ScalerWrite(CM_66_GAMMA_PORT, 2, pData, _NON_AUTOINC);// R Offset    
    ScalerWrite(CM_66_GAMMA_PORT, 2, pData, _NON_AUTOINC);// G Offset
    ScalerWrite(CM_66_GAMMA_PORT, 2, pData, _NON_AUTOINC);// B Offset
    
    // Output Gamma 
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
    
    ScalerQCPCMRunShareOneLBuf(1);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
   
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, _BIT6); // Enable Output Gamma
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT2 | _BIT6), _BIT2); // Enable sRGB, normal precision
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT6, _BIT6); // Enable Input Gamma
    
    DebugMessageScaler("5. PCMMode_0", 0x00);

    ucData1 =  (BYTE)ScalerQCCheckCRCOn(0x1D, 0x73, 0xE2, _D_DOMAIN_CRC) << 0;
    
    ScalerQCPCMAdjustSU(_OFF); // 4L
    
    // Share one line buffer End
    ScalerQCIDomainRandomGenOff();
    
    ScalerQCDDomainRandomGenOn(_MASS);
   // ScalerQCDDitherOn(_MSB);
    
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x07, 0xFB, 0x55, _D_DOMAIN_CRC) << 0)); //I-Random 0x04, 0xAE, 0x61,

    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // D-RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x41, 0x6C, 0x86, _D_DOMAIN_CRC) << 1));//I-random : 0x91, 0x30, 0xCA,
    
    // D-RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xE4, 0x1D, 0x36, _D_DOMAIN_CRC) << 2)); // 0x57, 0x34, 0xC1, 
    // D-RandomGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x9B, 0xF3, 0x01, _D_DOMAIN_CRC) << 3));//0xA6, 0xBA, 0xE5
    
    ScalerQCHighlightWindowOff();

    ScalerQCDDitherOn(_LSB);
    
    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x41, 0xAD, 0x4F, _D_DOMAIN_CRC) << 1)); //0x5B, 0xED, 0x79, 
    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2D, 0x25, 0x5A, _D_DOMAIN_CRC) << 5));//0x2B, 0x40, 0xA4,
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
	DebugMessageScaler("5. Mode_6", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x7A, 0x3B, 0xCD, _D_DOMAIN_CRC) << 6));//0x57, 0xB2, 0x4B,
	// PatternGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
	DebugMessageScaler("5. Mode_7", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x0D, 0x02, 0xD7, _D_DOMAIN_CRC) << 7)); //0x34, 0xA6, 0x33,

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
// Description  : Set up Share one line buffer
// Input Value  : ucMode = 0 OGC, = 1 PCM; 
//                bDoubleBuf = _ON use double buffer; = _OFF No Double Buffer
// Output Value : None
//--------------------------------------------------
void ScalerQCPCMSetShareOneLBuf(BYTE ucMode, bit bDoubleBuf)
{
    BYTE ucTemp = 0;

    if(bDoubleBuf == _ON)
    {
        ScalerRead(CM_10_VGIP_CTRL, 1, &ucTemp, _NON_AUTOINC);
        ucTemp |= 0x10;
        ScalerSetByte(CM_10_VGIP_CTRL, ucTemp);// Enable double buffer
    }
    else
    {
        ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT4, 0x00);  
    }
    
    ucTemp = 0x80 | ((ucMode & 0x01) << 5);
    ScalerSetByte(CM_38_PCM_SHARE_LINE_BUFFER, ucTemp);
        
    if(bDoubleBuf == _ON)
    {
        ScalerRead(CM_10_VGIP_CTRL, 1, &ucTemp, _NON_AUTOINC);
        ucTemp |= 0x20;
        ScalerSetByte(CM_10_VGIP_CTRL, ucTemp);  // VGIP double buffer ready
    }
    
    ucTemp = 0;
    
    while((ucTemp & 0x80) != 0x80)
    {
        ScalerRead(CM_38_PCM_SHARE_LINE_BUFFER, 1, &ucTemp, _NON_AUTOINC);
    }
    
}

//--------------------------------------------------
// Description  : trigger line buffer to move data
// Input Value  : ucMode = 0 OGC, = 1 PCM; 
// Output Value : None
//--------------------------------------------------
void ScalerQCPCMRunShareOneLBuf(BYTE ucMode)
{
    BYTE ucTemp = 0;

    ucTemp = 0xC0 | (ucMode << 5);
    ScalerSetByte(CM_38_PCM_SHARE_LINE_BUFFER, ucTemp);

    ScalerRead(CM_38_PCM_SHARE_LINE_BUFFER, 1, &ucTemp, _NON_AUTOINC);

    while((ucTemp & 0x40) != 0)
    {
        ScalerRead(CM_38_PCM_SHARE_LINE_BUFFER, 1, &ucTemp, _NON_AUTOINC);      
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
    }
    else
    {
        ScalerSetBit(CM_38_PCM_SHARE_LINE_BUFFER, ~_BIT7, 0x00); 
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
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT5 | _BIT4);
    
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckFSCrc(tQC_DITHER_NEWFUNC1_MSB_CRC_TABLE, sizeof(tQC_DITHER_NEWFUNC1_MSB_CRC_TABLE) / 3, _D_DOMAIN_CRC, 1) << 0));

    // LSB
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7), _BIT7);
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT5 | _BIT4);
                                                        
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
    ScalerSetBit(CM_6A_DITHERING_CTRL1, 0x00, _BIT5 | _BIT3);
    ScalerSetBit(CM_6B_DITHERING_CTRL2, 0x00, _BIT3| _BIT1 | _BIT0);
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);

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
    BYTE ucFrontRed12 = 0;
    BYTE ucFrontGreen12 = 0;
    BYTE ucFrontBlue12 = 0;
    BYTE ucBackRed12 = 0; 
    BYTE ucBackGreen12 = 0; 
    BYTE ucBackBlue12 = 0;
    BYTE ucFrontRed34 = 0; 
    BYTE ucFrontGreen34 = 0;
    BYTE ucFrontBlue34 = 0;
    BYTE ucBackRed34 = 0; 
    BYTE ucBackGreen34 = 0; 
    BYTE ucBackBlue34 = 0;
    
    DebugMessageScaler("5. Display Conversion Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT4, 0x00);  
    
    // LVDS + Single port + Table1
    DebugMessageScaler("5. Mode_0", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x89);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, 0x00);    	    	    	      // Single/Dual port
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), _BIT0);    	// LVDS
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT1), 0x00);    	    // 8-bit
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1E_LVDS_CTR, 0xE3);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A4_TCON_LVDS_CTRL4, 0xBF);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A5_TCON_LVDS_CTRL5, 0xBF);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), 0x00);    // Mirror & Table
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), 0x00);    	    // PN Swap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1), 0x00);    	    	// Panel Inverse

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x54, 0x4A, 0x9D, 0x6F,
                                                    0x6F, 0x31, 0x5D, 0x52, 0xCA, 0x05, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) << 0));
    
    // LVDS + Single port + Table2
    DebugMessageScaler("5. Mode_1", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT0);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x65, 0xF9, 0xEE, 0xDA,
                                                    0x6A, 0xE4, 0x5D, 0x52, 0x3C, 0x7F, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) << 1));

    // LVDS + Dual port + Table1
    DebugMessageScaler("5. Mode_2", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x88);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, _BIT2);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), 0x00);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x56, 0x74, 0xBB, 0x07,
                                                    0xA2, 0xA8, 0x4C, 0x46, 0xA9, 0x79, 0x95, 0xCA,
    	    	    	                            0x6D, 0xE3, 0x58, 0x21, 0x4C, 0x46, 0x33, 0x6E) << 2));


    // LVDS + Dual port + Table2
    DebugMessageScaler("5. Mode_3", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT0);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x50, 0xEA, 0x85, 0xBE,
                                                    0x1F, 0x7E, 0x4C, 0x46, 0xB9, 0x3F, 0x60, 0x6D,
    	    	    	                            0x49, 0x76, 0x21, 0x15, 0x4C, 0x46, 0xEE, 0xD7) << 3));

/*
    // LVDS + Single port + Table1
    DebugMessageScaler("5. Mode_8", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x89);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, 0x00);    	    	    	      // Single/Dual port
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), _BIT0);    	// LVDS
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT1), 0x00);    	    // 8-bit
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1E_LVDS_CTR, 0xE3);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A4_TCON_LVDS_CTRL4, 0xBF);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A5_TCON_LVDS_CTRL5, 0xBF);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT6);    // Mirror & Table
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), _BIT7);    	    // PN Swap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1), _BIT1);    	    	// Panel Inverse

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0xAA,
    	    	    	                            0xDF, 0x7F, 0x76, 0x67, 0xA1, 0xA8, 0x55, 0x6C) << 0));


    // LVDS + Single port + Table2
    DebugMessageScaler("5. Mode_9", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), (_BIT6 | _BIT0));    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x3D,
    	    	    	                            0xDF, 0x7F, 0xDA, 0x3E, 0x48, 0x23, 0x8A, 0x4A) << 1));
    
    // LVDS + Dual port + Table1
    DebugMessageScaler("5. Mode_10", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x88);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, _BIT2);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT6);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x52, 0xDD, 0x83, 0x86,
                                                    0xCC, 0xF1, 0x99, 0x32, 0x59, 0xD2, 0x5C, 0x8C,
    	    	    	                            0x83, 0x86, 0xCE, 0xF9, 0x61, 0x78, 0x93, 0x47) << 2));

    // LVDS + Dual port + Table2
    DebugMessageScaler("5. Mode_11", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), (_BIT6 | _BIT0));    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x18, 0xA4, 0x83, 0x86,
                                                    0x79, 0x5D, 0xB8, 0x4A, 0xAB, 0x33, 0x78, 0xD9,
    	    	    	                            0x83, 0x86, 0x1E, 0xC0, 0x48, 0x5C, 0x43, 0xE8) << 3));

    ScalerQCDDomainPatternGenOff();
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x88);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, _BIT2);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT1), 0x00);    	    // 8-bit
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A4_TCON_LVDS_CTRL4, 0x80);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A5_TCON_LVDS_CTRL5, 0x80);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), 0x00);    // Mirror & Table

    // miniLVDS + Single 3 + type1(CMO)
    DebugMessageScaler("5. Mode_16", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));    	// miniLVDS
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1D_MLVDS_CTRL2, 0xAA);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), 0x00);    	    // PN Swap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));    	    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);    	    


    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0x9E, 0xC4, 0xA8, 0x4F, 0x16, 0xCA, 0xA6, 0xA6) << 0));

    // miniLVDS + Single 3 + type2(AUO)
    DebugMessageScaler("5. Mode_17", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT3 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0xA8, 0x4F, 0x00, 0x00,
    	    	    	                            0x9E, 0xC4, 0x16, 0xCA, 0xA6, 0xA6, 0x00, 0x00) << 1));


    // miniLVDS + Single 6 + type1(CMO)
    DebugMessageScaler("5. Mode_18", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02,
                                                    0x04, 0xD2, 0x94, 0xA4, 0x89, 0x77, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0x02, 0x18, 0xE7, 0x6B, 0x35, 0x4A) << 2));

    // miniLVDS + Single 6 + type2(AUO)
    DebugMessageScaler("5. Mode_19", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT3 | _BIT1));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x04, 0xD2, 0x94, 0xA4, 0x89, 0x77, 0x00, 0x00,
    	    	    	                            0x07, 0x02, 0x02, 0x18, 0xE7, 0x6B, 0x35, 0x4A) << 3));

    // miniLVDS + Dual 3 + type1(CMO)
    DebugMessageScaler("5. Mode_20", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02,
                                                    0xDC, 0xA4, 0xA9, 0x59, 0x58, 0x60, 0x00, 0x00,
    	    	    	                            0x07, 0x02, 0x60, 0x03, 0x9B, 0x2D, 0x74, 0x70) << 4));

    // miniLVDS + Dual 3 + type2(AUO)
    DebugMessageScaler("5. Mode_21", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT3 | _BIT1 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0xDC, 0xA4, 0x07, 0x02,
                                                    0xA9, 0x59, 0x58, 0x60, 0x60, 0x03, 0x00, 0x00,
    	    	    	                            0x07, 0x02, 0x9B, 0x2D, 0x74, 0x70, 0x00, 0x00) << 5));

    // miniLVDS + Single 3 + type1(CMO)
    DebugMessageScaler("5. Mode_22", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), _BIT7);    	    // PN Swap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT0));    	    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT0), _BIT0);      // data bit inversion


    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x49, 0xD6, 0xE0, 0x8D, 0x35, 0xB1, 0x00, 0x00,
    	    	    	                            0x9E, 0xC4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) << 6));

    // miniLVDS + Single 3 + type2(AUO)
    DebugMessageScaler("5. Mode_23", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x49, 0xD6, 0x00, 0x00,
    	    	    	                            0x9E, 0xC4, 0xE0, 0x8D, 0x35, 0xB1, 0x00, 0x00) << 7));

    // miniLVDS + Single 6 + type1(CMO)
    DebugMessageScaler("5. Mode_24", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x85, 0x30, 0xA0, 0x5D,
                                                    0x9C, 0xB5, 0x00, 0x00, 0xE6, 0x41, 0x00, 0x00,
    	    	    	                            0x43, 0x64, 0xFD, 0xBB, 0x07, 0x02, 0x00, 0x00) << 0));

    // miniLVDS + Single 6 + type2(AUO)
    DebugMessageScaler("5. Mode_25", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT1));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x85, 0x30, 0xA0, 0x5D, 0x9C, 0xB5, 0x00, 0x00,
    	    	    	                            0x07, 0x02, 0xE6, 0x41, 0x43, 0x64, 0xFD, 0xBB) << 1));

    // miniLVDS + Dual 3 + type1(CMO)
    DebugMessageScaler("5. Mode_26", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x04, 0x3B, 0x5D, 0x6D,
                                                    0x18, 0x04, 0x07, 0x02, 0xE1, 0xD7, 0x00, 0x00,
    	    	    	                            0xF4, 0x5F, 0x74, 0x3D, 0x07, 0x02, 0x00, 0x00) << 2));

    // miniLVDS + Dual 3 + type2(AUO)
    DebugMessageScaler("5. Mode_27", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT1 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE1, 0xD7,
                                                    0xF4, 0x5F, 0x07, 0x02, 0x74, 0x3D, 0x00, 0x00,
    	    	    	                            0x04, 0x3B, 0x5D, 0x6D, 0x07, 0x02, 0x18, 0x04) << 3));

    // miniLVDS + Dual 3 + type1(CMO)
    DebugMessageScaler("5. Mode_28", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1 | _BIT0), (_BIT1));
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), (_BIT5 | _BIT4));    	  // , RBSwap, MLSwap

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0xC0, 0x36, 0x80, 0xE9,
                                                    0xF8, 0x5C, 0x07, 0x02, 0xE1, 0xD7, 0x00, 0x00,
    	    	    	                            0xF4, 0x5F, 0x74, 0x3D, 0x07, 0x02, 0x00, 0x00) << 4));

    // miniLVDS + Dual 3 + type2(AUO)
    DebugMessageScaler("5. Mode_29", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT1 | _BIT0)); 

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE1, 0xD7,
                                                    0xF4, 0x5F, 0x07, 0x02, 0x74, 0x3D, 0x00, 0x00,
    	    	    	                            0xC0, 0x36, 0x80, 0xE9, 0x07, 0x02, 0xF8, 0x5C) << 5));

    // miniLVDS + Single 3 + type1(CMO)
    DebugMessageScaler("5. Mode_30", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), (_BIT5 | _BIT4));    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT0));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x0A, 0x09, 0xC5, 0x22, 0x73, 0x14, 0x00, 0x00,
    	    	    	                            0x57, 0xC4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) << 6));

    // miniLVDS + Single 3 + type2(AUO)
    DebugMessageScaler("5. Mode_31", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x0A, 0x09, 0x00, 0x00,
    	    	    	                            0x57, 0xC4, 0xC5, 0x22, 0x73, 0x14, 0x00, 0x00) << 7));

    // miniLVDS + Single 6 + type1(CMO)
    DebugMessageScaler("5. Mode_32", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT1));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x78, 0xBF, 0x25, 0xF8,
                                                    0xEA, 0x76, 0x00, 0x00, 0x66, 0xA4, 0x00, 0x00,
    	    	    	                            0x85, 0x0B, 0x1E, 0x9D, 0xBC, 0x8C, 0x00, 0x00) << 0));

    // miniLVDS + Single 6 + type2(AUO)
    DebugMessageScaler("5. Mode_33", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT1));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x78, 0xBF, 0x25, 0xF8, 0xEA, 0x76, 0x00, 0x00,
    	    	    	                            0xBC, 0x8C, 0x66, 0xA4, 0x85, 0x0B, 0x1E, 0x9D) << 1));

    // miniLVDS + Dual 3 + type1(CMO)
    DebugMessageScaler("5. Mode_34", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT1 | _BIT0));    	    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0)); 

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x92, 0xD1, 0x31, 0x76,
                                                    0x77, 0xF2, 0xBC, 0x8C, 0xA6, 0x7C, 0x00, 0x00,
    	    	    	                            0x9F, 0x77, 0xFA, 0x4B, 0xBC, 0x8C, 0x00, 0x00) << 2));

    // miniLVDS + Dual 3 + type2(AUO)
    DebugMessageScaler("5. Mode_35", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT1 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA6, 0x7C,
                                                    0x9F, 0x77, 0xBC, 0x8C, 0xFA, 0x4B, 0x00, 0x00,
    	    	    	                            0x92, 0xD1, 0x31, 0x76, 0xBC, 0x8C, 0x77, 0xF2) << 3));

    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), 0x00);    	    // PN Swap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));    	    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), (_BIT0));    	// LVDS

    // DuGate start **************************************************************************************************
    
    // DuGate S3 start *********************************************
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));// miniLVDS
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1D_MLVDS_CTRL2, 0xAA); //mLVDS clk
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x38, 0x05); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x39, 0x46); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3a, 0x05); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3b, 0x46); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x3c, ~(0x11), (0x11)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x3d, ~(0x22), (0x22)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x3e, ~(0x33), (0x33)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x3f, ~(0x44), (0x44)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x40, ~(0x55), (0x55)); 
    
    // miniLVDS + Single3 + type1(CMO) + Z1
    DebugMessageScaler("5. Mode_40", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT0), 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT3 | _BIT0));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1 | _BIT0), 0x00); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), 0x00); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), 0x00); 
    
    ucFrontRed12 = 1;
    ucFrontGreen12 = 3;
    ucFrontBlue12 = 5;
    ucBackRed12 = 2;
    ucBackGreen12 = 4;
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0x47, 0x27, 0x4c, 0x91, 0xca, 0xee, 0x88, 0xeb) << 0));

    // miniLVDS + Single3 + type1(CMO) + Z2
    DebugMessageScaler("5. Mode_41", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT5)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0x05, 0x0f, 0x92, 0x20, 0xa2, 0x67, 0x90, 0x0c) << 1));

    // miniLVDS + Single3 + type1(CMO) + Zz
    DebugMessageScaler("5. Mode_42", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT6)); 
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0x05, 0x0f, 0xf2, 0x80, 0x53, 0x35, 0xce, 0x94) << 2));

    // miniLVDS + Single3 + type1(CMO) + LG1
    DebugMessageScaler("5. Mode_43", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 2; 
    ucFrontBlue12 = 4;
    ucBackRed12 = 3; 
    ucBackGreen12 = 5; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 2; 
    ucFrontBlue34 = 4;
    ucBackRed34 = 3; 
    ucBackGreen34 = 5; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT4 | _BIT2));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xe5, 0x51, 0x65, 0x81, 0xd1, 0x30, 0x39, 0x13) << 3));

    // miniLVDS + Single3 + type1(CMO) + LG2
    DebugMessageScaler("5. Mode_44", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 4; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 3; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT4)); 
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xe5, 0x51, 0xe6, 0xc7, 0x73, 0xe6, 0x4f, 0x9e) << 4));

    // miniLVDS + Single3 + type1(CMO) + INL1
    DebugMessageScaler("5. Mode_45", 0x00);
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 2; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 1; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 5;    
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xe5, 0x51, 0x11, 0xb7, 0x13, 0xd9, 0x29, 0x31) << 5));

    // miniLVDS + Single3 + type2(AUO) + INL2
    DebugMessageScaler("5. Mode_46", 0x00);
    
    ucFrontRed12 =  2; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 6;
    ucBackRed12 = 1; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 5;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 4; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 3;
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), ( _BIT5 | _BIT4));    	   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT5 | _BIT4 | _BIT3 | _BIT0)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), _BIT7);    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT0), (_BIT0)); 
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x1d, 0x96, 0x00, 0x00,
    	    	    	                            0xe5, 0x51, 0x7f, 0x64, 0x20, 0xd7, 0x00, 0x00) << 6));

    // miniLVDS + Single3 + type2(AUO) + AUO1
    DebugMessageScaler("5. Mode_47", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT5));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0xf0, 0xc0, 0x00, 0x00,
    	    	    	                            0xe5, 0x51, 0x3a, 0x58, 0x8f, 0xb6, 0x00, 0x00) << 7));

    // miniLVDS + Single3 + type2(AUO) + AUO2
    DebugMessageScaler("5. Mode_48", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 2; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 1; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 5;    
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x91, 0x61, 0x00, 0x00,
    	    	    	                            0xe5, 0x51, 0xf9, 0x7c, 0xcb, 0x57, 0x00, 0x00) << 0));

    // miniLVDS + Single3 + type2(AUO) + AUO3
    DebugMessageScaler("5. Mode_49", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 2; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 1; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 5;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));   
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x91, 0x61, 0x00, 0x00,
    	    	    	                            0xe5, 0x51, 0xf9, 0x7c, 0xcb, 0x57, 0x00, 0x00) << 1));


    // miniLVDS + Single3 + type2(AUO) + AUO4
    DebugMessageScaler("5. Mode_50", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 6;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 5;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 4; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 2; 
    ucBackGreen34 = 3; 
    ucBackBlue34 = 5;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT5 | _BIT4));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0xe5, 0x47, 0x00, 0x00,
    	    	    	                            0xe5, 0x51, 0xe5, 0xa8, 0xcd, 0x61, 0x00, 0x00) << 2));

    // miniLVDS + Single3 + type2(AUO) + AUO5
    DebugMessageScaler("5. Mode_51", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 6;    
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x38, 0x2d, 0x00, 0x00,
    	    	    	                            0xe5, 0x51, 0x75, 0x5b, 0x4d, 0xf9, 0x00, 0x00) << 3));


    //DuGate S6 start *********************************************
    // miniLVDS + S6 + type1(CMO) + Z1
    DebugMessageScaler("5. Mode_52", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT0), 0x00); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT3 | _BIT1)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1 | _BIT0), 0x00);  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7));  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), 0x00);  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), 0x00);  
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9e, 0xc4,
                                                    0xf5, 0x18, 0xff, 0x6a, 0xa7, 0xd6, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0x42, 0xf3, 0xdd, 0x1d, 0x0e, 0x45) << 0));

    // miniLVDS + S6 + type1(CMO) + Z2
    DebugMessageScaler("5. Mode_53", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT5));  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe2, 0xed,
                                                    0x46, 0xdf, 0xb3, 0xfb, 0x57, 0x98, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0xfa, 0x93, 0x34, 0x4f, 0x3a, 0x8d) << 1));

    // miniLVDS + S6 + type1(CMO) + Zz
    DebugMessageScaler("5. Mode_54", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT6));    
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe2, 0xed,
                                                    0xd8, 0x71, 0xf6, 0xa5, 0x48, 0x95, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0xec, 0xf1, 0x9c, 0x18, 0x32, 0x64) << 2));

    // miniLVDS + S6 + type1(CMO) + LG1
    DebugMessageScaler("5. Mode_55", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 2; 
    ucFrontBlue12 = 4;
    ucBackRed12 = 3; 
    ucBackGreen12 = 5; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 2; 
    ucFrontBlue34 = 4;
    ucBackRed34 = 3; 
    ucBackGreen34 = 5; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT4 | _BIT2));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x3c,
                                                    0x30, 0xab, 0xd8, 0x6d, 0xcc, 0x27, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0xcf, 0x9b, 0x6b, 0x24, 0xd5, 0x2e) << 3));

    // miniLVDS + S6 + type1(CMO) + LG2
    DebugMessageScaler("5. Mode_56", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 4; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2;
    ucBackGreen34 = 3; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT4));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x3c,
                                                    0xa1, 0x0e, 0x02, 0x01, 0x77, 0x41, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0x11, 0x60, 0xc3, 0x84, 0x42, 0x50) << 4));

    // miniLVDS + S6 + type1(CMO) + INL1
    DebugMessageScaler("5. Mode_57", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4;
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 2; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 1; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 5;    
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x3c,
                                                    0xaa, 0xfc, 0xa0, 0xd2, 0x86, 0x89, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0x11, 0x60, 0xc3, 0x84, 0x06, 0xc0) << 5));

    // miniLVDS + S6 + type2(AUO) + INL2
    DebugMessageScaler("5. Mode_58", 0x00);
    
    ucFrontRed12 =  2; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 6;
    ucBackRed12 = 1; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 5;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 4; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 3; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), ( _BIT5 | _BIT4));    	   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT5 | _BIT4 | _BIT3 | _BIT1)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), _BIT7);    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT0), (_BIT0)); 
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0xa7, 0x3c, 0x21, 0xaf, 0x1f, 0xec, 0x00, 0x00
    	    	    	                            , 0x48, 0x3c, 0x51, 0x1e, 0x71, 0xdb, 0xea, 0x6c) << 6));

    // miniLVDS + S6 + type2(AUO) + AUO1
    DebugMessageScaler("5. Mode_59", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT5));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0xdf, 0x02, 0xc9, 0xf5, 0x76, 0x16, 0x00, 0x00,
    	    	    	                            0x48, 0x3c, 0x5b, 0x73, 0xfd, 0x24, 0x8e, 0x56) << 7));

    // miniLVDS + S6 + type2(AUO) + AUO2
    DebugMessageScaler("5. Mode_60", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 2; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 1; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 5;    
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0xaf, 0x9c, 0x2a, 0x26, 0xad, 0x46, 0x00, 0x00,
    	    	    	                            0x48, 0x3c, 0xcc, 0x99, 0x6d, 0x56, 0x5c, 0xf9) << 0));

    // miniLVDS + S6 + type2(AUO) + AUO3
    DebugMessageScaler("5. Mode_61", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 2; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 1; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 5;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));   
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0xaf, 0x9c, 0x2a, 0x26, 0xad, 0x46, 0x00, 0x00,
    	    	    	                            0x48, 0x3c, 0xcc, 0x99, 0x6d, 0x56, 0x5c, 0xf9) << 1));

    // miniLVDS + S6 + type2(AUO) + AUO4
    DebugMessageScaler("5. Mode_62", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 6;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 5;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 4; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 2; 
    ucBackGreen34 = 3; 
    ucBackBlue34 = 5;    
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT5 | _BIT4));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0xdc, 0x3a, 0x27, 0x4f, 0x51, 0x6e, 0x00, 0x00,
    	    	    	                            0x48, 0x3c, 0x51, 0x1a, 0xb9, 0x66, 0xe4, 0x7d) << 2));

    // miniLVDS + S6 + type2(AUO) + AUO5
    DebugMessageScaler("5. Mode_63", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 6;   
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0xcb, 0x71, 0x38, 0x77, 0x0d, 0x2a, 0x00, 0x00,
    	    	    	                            0x48, 0x3c, 0x38, 0x52, 0x1e, 0xc2, 0xc9, 0x11) << 3));

    // DuGate D3 start *********************************************
    // miniLVDS + D3 + type1(CMO) + Z1
    DebugMessageScaler("5. Mode_64", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT0), 0x00); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT3 | _BIT1 | _BIT0)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1 | _BIT0), 0x00);  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7));  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), 0x00);  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1;
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9e, 0xc4,
                                                    0x18, 0xfc, 0x06, 0x99, 0x36, 0x60, 0x00, 0x00,
    	    	    	                            0x9e, 0xc4, 0xad, 0x8f, 0x5d, 0xda, 0x3a, 0x6c) << 0));

    // miniLVDS + D3 + type1(CMO) + Z2
    DebugMessageScaler("5. Mode_65", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT5));  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (0));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9e, 0xc4,
                                                    0xec, 0xfd, 0xca, 0xf0, 0x42, 0x74, 0x00, 0x00,
    	    	    	                            0x9e, 0xc4, 0x46, 0x9e, 0xfd, 0xc7, 0x5f, 0x90) << 1));

    // miniLVDS + D3 + type1(CMO) + Zz
    DebugMessageScaler("5. Mode_66", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT6));     
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9e, 0xc4,
                                                    0xbe, 0x7b, 0x54, 0x91, 0xd6, 0xfb, 0x00, 0x00,
    	    	    	                            0x9e, 0xc4, 0x3b, 0x49, 0x71, 0x0a, 0x95, 0xb4) << 2));

    // miniLVDS + D3 + type1(CMO) + LG1
    DebugMessageScaler("5. Mode_67", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 2;
    ucFrontBlue12 = 4;
    ucBackRed12 = 3; 
    ucBackGreen12 = 5; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 2; 
    ucFrontBlue34 = 4;
    ucBackRed34 = 3; 
    ucBackGreen34 = 5; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT4 | _BIT2));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02,
                                                    0x9f, 0xde, 0x68, 0x31, 0xf6, 0xb3, 0x00, 0x00,
    	    	    	                            0x07, 0x02, 0x11, 0xf0, 0xa4, 0x72, 0x20, 0xa6) << 3));

    // miniLVDS + D3 + type1(CMO) + LG2
    DebugMessageScaler("5. Mode_68", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 4; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 3; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (0));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02,
                                                    0x80, 0x57, 0x60, 0xb2, 0x42, 0x13, 0x00, 0x00,
    	    	    	                            0x07, 0x02, 0xf6, 0x38, 0x64, 0x16, 0x17, 0xe3) << 4));

    // miniLVDS + D3 + type1(CMO) + INL1
    DebugMessageScaler("5. Mode_69", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4;
    ucFrontBlue12 = 5;
    ucBackRed12 = 2;
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 2; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 1; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 5; 
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02,
                                                    0xd7, 0xb8, 0xb3, 0x4f, 0x18, 0x6d, 0x00, 0x00,
    	    	    	                            0x07, 0x02, 0x31, 0xf5, 0x25, 0x85, 0xf5, 0xa8) << 5));

    // miniLVDS + D3 + type2(AUO) + INL2
    DebugMessageScaler("5. Mode_70", 0x00);
    
    ucFrontRed12 =  2; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 6;
    ucBackRed12 = 1; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 5;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 4; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 3; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), ( _BIT5 | _BIT4));    	   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT5 | _BIT4 | _BIT3 | _BIT1 | _BIT0)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), _BIT7);    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT0), (_BIT0)); 
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb1, 0x35,
                                                    0x58, 0x7d, 0x07, 0x02, 0x39, 0xd7, 0x00, 0x00
    	    	    	                            , 0x06, 0x5f, 0x14, 0x70, 0x07, 0x02, 0xb2, 0x15) << 6));

    // miniLVDS + D3 + type2(AUO) + AUO1
    DebugMessageScaler("5. Mode_71", 0x00);
    
    ucFrontRed12 = 1;
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 6;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), (0));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa3,
                                                    0x45, 0x4b, 0x07, 0x02, 0xc2, 0x2a, 0x00, 0x00,
    	    	    	                            0xcb, 0xcd, 0xea, 0x21, 0x07, 0x02, 0x22, 0x4f) << 7));

    // miniLVDS + D3 + type2(AUO) + AUO2
    DebugMessageScaler("5. Mode_72", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4;
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3;
    ucBackBlue12 = 6;
    ucFrontRed34 = 2; 
    ucFrontGreen34 = 3;
    ucFrontBlue34 = 6;
    ucBackRed34 = 1;
    ucBackGreen34 = 4; 
    ucBackBlue34 = 5;    
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8c, 0x79,
                                                    0xd7, 0x9d, 0x07, 0x02, 0x29, 0x79, 0x00, 0x00,
    	    	    	                            0x38, 0xba, 0x34, 0x06, 0x07, 0x02, 0xac, 0x83) << 0));

    // miniLVDS + D3 + type2(AUO) + AUO3
    DebugMessageScaler("5. Mode_73", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 4; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 2; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 6;
    ucBackRed34 = 1; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 5;
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));   
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8c, 0x79,
                                                    0xd7, 0x9d, 0x07, 0x02, 0x29, 0x79, 0x00, 0x00,
    	    	    	                            0x38, 0xba, 0x34, 0x06, 0x07, 0x02, 0xac, 0x83) << 1));

    // miniLVDS + D3 + type2(AUO) + AUO4
    DebugMessageScaler("5. Mode_74", 0x00);
    
    ucFrontRed12 = 1;
    ucFrontGreen12 = 4;
    ucFrontBlue12 = 6;
    ucBackRed12 = 2; 
    ucBackGreen12 = 3;
    ucBackBlue12 = 5;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 4;
    ucFrontBlue34 = 6;
    ucBackRed34 = 2; 
    ucBackGreen34 = 3; 
    ucBackBlue34 = 5;    
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), 0x00);  
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa3,
                                                    0xca, 0xab, 0x07, 0x02, 0xd2, 0x84, 0x00, 0x00,
    	    	    	                            0xcb, 0xcd, 0xca, 0x57, 0x07, 0x02, 0x3c, 0xd9) << 2));

    // miniLVDS + D3 + type2(AUO) + AUO5
    DebugMessageScaler("5. Mode_75", 0x00);
    
    ucFrontRed12 = 1; 
    ucFrontGreen12 = 3; 
    ucFrontBlue12 = 5;
    ucBackRed12 = 2; 
    ucBackGreen12 = 4; 
    ucBackBlue12 = 6;
    ucFrontRed34 = 1; 
    ucFrontGreen34 = 3; 
    ucFrontBlue34 = 5;
    ucBackRed34 = 2; 
    ucBackGreen34 = 4; 
    ucBackBlue34 = 6;   
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, ((ucFrontRed12 << 4) | ucFrontGreen12)); //subpix
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, ((ucFrontBlue12 << 4) | ucBackRed12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, ((ucBackGreen12 << 4) | ucBackBlue12));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, ((ucFrontRed34 << 4) | ucFrontGreen34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, ((ucFrontBlue34 << 4) | ucBackRed34));
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, ((ucBackGreen34 << 4) | ucBackBlue34));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa3,
                                                    0x45, 0x4b, 0x07, 0x02, 0xc2, 0x2a, 0x00, 0x00,
    	    	    	                            0xcb, 0xcd, 0xea, 0x21, 0x07, 0x02, 0x22, 0x4f) << 3));


    // Trigate start **************************************************************************************************
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));// miniLVDS
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1D_MLVDS_CTRL2, 0xAA); //mLVDS clk
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x30 , ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), 0x00);   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x31 , ~(_BIT6 | _BIT5 | _BIT4 | _BIT0), 0x00);  
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x44, 0x02); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x45, 0x30); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x46, 0x03); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x47, 0x84); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3a, 0x05); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3b, 0x46); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x48, 0x05); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x49, 0x46); 
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x4d, 0x5a); 
    
    // miniLVDS + Single3 + type1(CMO) + pixShft0
    DebugMessageScaler("5. Mode_80", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	  
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT0), 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT3 | _BIT0));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1 | _BIT0), 0x00); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), 0x00);   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x41, ~(_BIT7), _BIT7);   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT1));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xde, 0xf3, 0xa7, 0x1c, 0xbc, 0x49, 0x0f, 0xfe) << 0));

    // miniLVDS + Single3 + type1(CMO) + pixShft1
    DebugMessageScaler("5. Mode_81", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT2 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xde, 0xf3, 0xb2, 0xd3, 0x37, 0x95, 0xf3, 0xb0) << 1));

    // miniLVDS + Single3 + type1(CMO) + pixShft2
    DebugMessageScaler("5. Mode_82", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT2));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xde, 0xf3, 0x23, 0xbc, 0x40, 0x0b, 0xb7, 0x73) << 2));

    // miniLVDS + Single3 + type1(CMO) + pixShft3
    DebugMessageScaler("5. Mode_83", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xde, 0xf3, 0x36, 0x73, 0xcb, 0xd7, 0x4b, 0x3d) << 3));

    // miniLVDS + S6 + type1(CMO) + pixShft0
    DebugMessageScaler("5. Mode_84", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT3 | _BIT1));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x5d,
                                                    0xe5, 0x76, 0x85, 0xbe, 0x9e, 0xbc, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0x22, 0xe3, 0x96, 0x90, 0x9a, 0xb0) << 4));

    // miniLVDS + S6 + type1(CMO) + pixShft1
    DebugMessageScaler("5. Mode_85", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT2 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x5d,
                                                    0xb0, 0x72, 0xe5, 0xaa, 0xa4, 0xbf, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0xa0, 0xa3, 0x7f, 0xce, 0x48, 0x3e) << 5));

    // miniLVDS + S6 + type1(CMO) + pixShft2
    DebugMessageScaler("5. Mode_86", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT2));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x5d,
                                                    0x41, 0x95, 0x2c, 0x97, 0xb3, 0xd7, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0x46, 0x97, 0x9b, 0x01, 0x8e, 0x8e) << 6));

    // miniLVDS + S6 + type1(CMO) + pixShft3
    DebugMessageScaler("5. Mode_87", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x5d,
                                                    0xe5, 0x76, 0x85, 0xbe, 0x9e, 0xbc, 0x00, 0x00,
    	    	    	                            0x00, 0x00, 0x22, 0xe3, 0x96, 0x90, 0x9a, 0xb0) << 7));

    // miniLVDS + D3 + type1(CMO) + pixShft0
    DebugMessageScaler("5. Mode_88", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT3 | _BIT1 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x5d,
                                                    0x14, 0x9b, 0xcf, 0x5c, 0xcb, 0x76, 0x00, 0x00,
    	    	    	                            0x5e, 0x5d, 0x2b, 0xcd, 0xfc, 0xa3, 0x80, 0x47) << 0));

    // miniLVDS + D3 + type1(CMO) + pixShft1
    DebugMessageScaler("5. Mode_89", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT2 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x5d,
                                                    0xbf, 0x26, 0x02, 0xc0, 0x34, 0xec, 0x00, 0x00,
    	    	    	                            0x5e, 0x5d, 0x6b, 0xb1, 0x5f, 0xe3, 0xd2, 0xb7) << 1));

    // miniLVDS + D3 + type1(CMO) + pixShft2
    DebugMessageScaler("5. Mode_90", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT2));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x5d,
                                                    0xe4, 0x20, 0x1d, 0x53, 0x8e, 0x6b, 0x00, 0x00,
    	    	    	                            0x5e, 0x5d, 0x57, 0xdc, 0x79, 0xe4, 0x2f, 0x32) << 2));

    // miniLVDS + D3 + type1(CMO) + pixShft3
    DebugMessageScaler("5. Mode_91", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x5d,
                                                    0x14, 0x9b, 0xcf, 0x5c, 0xcb, 0x76, 0x00, 0x00,
    	    	    	                            0x5e, 0x5d, 0x2b, 0xcd, 0xfc, 0xa3, 0x80, 0x47) << 3));

    
    // miniLVDS + Single3 + type1(CMO) + pixShft4
    DebugMessageScaler("5. Mode_92", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT3 | _BIT0));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1 | _BIT0), (_BIT1)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xDE, 0xF3, 0x62, 0xF6, 0x55, 0x3A, 0xE7, 0x22) << 0));

    // miniLVDS + Single3 + type1(CMO) + pixShft5
    DebugMessageScaler("5. Mode_93", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xDE, 0xF3, 0xAE, 0xCD, 0x62, 0xF6, 0x55, 0x3A) << 1));

    // miniLVDS + Single3 + type1(CMO) + pixShft6
    DebugMessageScaler("5. Mode_94", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT2 | _BIT1));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xDE, 0xF3, 0xF3, 0xF0, 0xDF, 0xE4, 0xA8, 0xE9) << 2));

    // miniLVDS + Single3 + type1(CMO) + pixShft7
    DebugMessageScaler("5. Mode_95", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    	    	    	                            0xDE, 0xF3, 0x3F, 0xCB, 0xE8, 0x28, 0x1A, 0xF1) << 3));

    // miniLVDS + S6 + type1(CMO) + pixShft4
    DebugMessageScaler("5. Mode_96", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x0C,
                                                    0xAA, 0x8E, 0x8C, 0x9A, 0xF8, 0x82, 0x00, 0x00,
    	    	    	                            0x95, 0x0C, 0x3B, 0x98, 0xD5, 0x35, 0xFA, 0xDD) << 4));

    // miniLVDS + S6 + type1(CMO) + pixShft5
    DebugMessageScaler("5. Mode_97", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x0C,
                                                    0x3E, 0xE9, 0xDD, 0x42, 0x92, 0xF1, 0x00, 0x00,
    	    	    	                            0x95, 0x0C, 0x6F, 0x1C, 0xB4, 0xE3, 0x74, 0xB5) << 5));

    // miniLVDS + S6 + type1(CMO) + pixShft6
    DebugMessageScaler("5. Mode_98", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT2 | _BIT1));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x0C,
                                                    0x49, 0x25, 0xBD, 0x95, 0x1B, 0x58, 0x00, 0x00,
    	    	    	                            0x95, 0x0C, 0xE0, 0x67, 0x15, 0x63, 0x47, 0xB6) << 6));

    // miniLVDS + S6 + type1(CMO) + pixShft7
    DebugMessageScaler("5. Mode_99", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x0C,
                                                    0xAA, 0x8E, 0x8C, 0x9A, 0xF8, 0x82, 0x00, 0x00,
    	    	    	                            0x95, 0x0C, 0x3B, 0x98, 0xD5, 0x35, 0xFA, 0xDD) << 7));

    // miniLVDS + D3 + type1(CMO) + pixShft4
    DebugMessageScaler("5. Mode_100", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(0x3f), (_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x0C,
                                                    0xAA, 0x8E, 0x8C, 0x9A, 0xF8, 0x82, 0x00, 0x00,
    	    	    	                            0x95, 0x0C, 0x3B, 0x98, 0xD5, 0x35, 0xFA, 0xDD) << 0));

    // miniLVDS + D3 + type1(CMO) + pixShft5
    DebugMessageScaler("5. Mode_101", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x0C,
                                                    0x3E, 0xE9, 0xDD, 0x42, 0x92, 0xF1, 0x00, 0x00,
    	    	    	                            0x95, 0x0C, 0x6F, 0x1C, 0xB4, 0xE3, 0x74, 0xB5) << 1));

    // miniLVDS + D3 + type1(CMO) + pixShft2
    DebugMessageScaler("5. Mode_102", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT2 | _BIT1));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x0C,
                                                    0x49, 0x25, 0xBD, 0x95, 0x1B, 0x58, 0x00, 0x00,
    	    	    	                            0x95, 0x0C, 0xE0, 0x67, 0x15, 0x63, 0x47, 0xB6) << 2));

    // miniLVDS + D3 + type1(CMO) + pixShft7
    DebugMessageScaler("5. Mode_103", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x4c, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT0));
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x0C,
                                                    0xAA, 0x8E, 0x8C, 0x9A, 0xF8, 0x82, 0x00, 0x00,
    	    	    	                            0x95, 0x0C, 0x3B, 0x98, 0xD5, 0x35, 0xFA, 0xDD) << 3));

    // Trigate end **************************************************************************************************    
*/
    ScalerQCIDomainRandomGenOff();
    ScalerQCminiLVDSCRCOff();

    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, 0x05);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, 0x03);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x31, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x32, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x33, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x34, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x35, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x36, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x37, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x38, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x39, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3A, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3B, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3C, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3D, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3E, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x3F, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x40, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x41, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x44, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x45, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x46, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x47, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x48, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x49, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x4C, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, 0x4D, 0x00);
    
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
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x00);

    // v factor 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x0E);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xA1);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x00);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x25);    

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    bData = (bData | ((BYTE)ScalerQCCheckCRCOn(0x0D, 0x3C, 0xCF, _I_DOMAIN_CRC)));

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
// Description  : Adjacent Pix Distance (APD) Test
// Input Value  : None
// Output Value : _TRUE
//--------------------------------------------------
bit ScalerQCAPDTest(void)
{
    bit bPASS1 = _FALSE; 
    bit bPASS2 = _FALSE; 
    bit bPASS3 = _FALSE; 
    bit bPASS4 = _FALSE;
    
    DebugMessageScaler("5. APD Start", 0x00);    	
//**************  D-domian-1  ************************************
    ScalerBurstWrite(tADJPIXDET_SETTING, sizeof(tADJPIXDET_SETTING), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    ScalerTimerDelayXms(50);
    ScalerSetByte(P15_D0_PIXEL_DETECT_CTRL, 0xf0); //pop up    
    ScalerTimerDelayXms(30);
    ScalerRead(P15_D8_ACCUMULATIVE_COUNT, 4, pData, _AUTOINC); //ACC_CNT
    //ScalerTimerDelayXms(30);

    if((pData[0] == 0x00) && (pData[1] == 0x01) && (pData[2] == 0x67) && (pData[3] == 0xE8) && 
        (ScalerGetBit(P15_D0_PIXEL_DETECT_CTRL, _BIT4) == _BIT4))   
    { 
        bPASS1 = _TRUE;
    }
    else 
    {
        bPASS1 = _FALSE;
    }    

    ScalerSetByte(P15_D0_PIXEL_DETECT_CTRL, 0x80); //pixel based
    ScalerTimerDelayXms(50);
    ScalerSetByte(P15_D0_PIXEL_DETECT_CTRL, 0xa0); //pop up    
    ScalerTimerDelayXms(30);
    ScalerRead(P15_D8_ACCUMULATIVE_COUNT, 4, pData, _AUTOINC); //ACC_CNT

    if((pData[0] == 0x00) && (pData[1] == 0x00) && (pData[2] == 0x00) && (pData[3] == 0x00) &&
        (ScalerGetBit(P15_D0_PIXEL_DETECT_CTRL, _BIT4) == 0x00))   
    {
        bPASS2 = _TRUE;
    }
    else 
    {
        bPASS2 = _FALSE;
    }    
//**************  D-domian-2  ************************************
    ScalerBurstWrite(tADJPIXDET_SETTING2, sizeof(tADJPIXDET_SETTING2), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    ScalerTimerDelayXms(50);
    ScalerSetByte(P15_D0_PIXEL_DETECT_CTRL, 0xf0); //pop up    
    ScalerTimerDelayXms(30);
    ScalerRead(P15_D8_ACCUMULATIVE_COUNT, 4, pData, _AUTOINC); //ACC_CNT
    //ScalerTimerDelayXms(30); 0012828

    if((pData[0] == 0x00)&&(pData[1] == 0x01) && (pData[2] == 0x28) && (pData[3] == 0x28) &&
        (ScalerGetBit(P15_D0_PIXEL_DETECT_CTRL, _BIT4) == _BIT4))
    { 
        bPASS3 = _TRUE;
    }
    else 
    {
        bPASS3 = _FALSE;
    }    

    ScalerSetByte(P15_D0_PIXEL_DETECT_CTRL, 0x80); //pixel based
    ScalerTimerDelayXms(50);
    ScalerSetByte(P15_D0_PIXEL_DETECT_CTRL, 0xa0); //pop up    
    ScalerTimerDelayXms(30);
    ScalerRead(P15_D8_ACCUMULATIVE_COUNT, 4, pData, _AUTOINC); //ACC_CNT

    if((pData[0] == 0x00) && (pData[1] == 0x00) && (pData[2] == 0xB3) && (pData[3] == 0xE8) && 
        (ScalerGetBit(P15_D0_PIXEL_DETECT_CTRL, _BIT4) == 0x00))   
    {
        bPASS4 = _TRUE;
    }
    else 
    {
        bPASS4 = _FALSE;
    }    
    
//**************  D-domian-2 END ************************************

    DebugMessageScaler("5. APD End", 0x00); 
    if((bPASS1 == _TRUE) && (bPASS2 == _TRUE) && (bPASS3 == _TRUE) && (bPASS4 == _TRUE))   
    {
        DebugMessageScaler("6. APD ***Pass***",0x00);           

        return _TEST_PASS;
    }
    else 
    {
        DebugMessageScaler("6. APD ***Fail***",0x00);

        return _TEST_FAIL;
    }    

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
// Output Value : _TRUE
//--------------------------------------------------
bit ScalerQCHdmiTest(void)
{    
    // Read HDMI CRC Value
    ScalerSetBit(P2_A4_TMDS_CTRL, _BIT0, _BIT0);
    
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);    

    pData[0] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pData[1] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pData[2] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pData[3] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pData[4] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);
    pData[5] = ScalerGetByte(P2_A5_CRC_OUTPUT_BYTE_2);    

    ScalerSetBit(P2_A4_TMDS_CTRL, _BIT0, 0x00);

    DebugMessageScaler("5. HDMI Check CRC0", pData[0]);
    DebugMessageScaler("5. HDMI Check CRC1", pData[1]);
    DebugMessageScaler("5. HDMI Check CRC2", pData[2]);
    DebugMessageScaler("5. HDMI Check CRC3", pData[3]);
    DebugMessageScaler("5. HDMI Check CRC4", pData[4]);
    DebugMessageScaler("5. HDMI Check CRC5", pData[5]);    

    // Rearrange CRC Order
    switch(pData[0])
    {
        case _HDMI_CRC0:

            if((pData[0] == _HDMI_CRC0) && (pData[1] == _HDMI_CRC1) && (pData[2] == _HDMI_CRC2) &&
               (pData[3] == _HDMI_CRC3) && (pData[4] == _HDMI_CRC4) && (pData[5] == _HDMI_CRC5))
            {
                DebugMessageScaler("6. HDMI Test Pass", 0x00);
                return _TEST_PASS;
            }

            break;
            
        case _HDMI_CRC1:

            if((pData[0] == _HDMI_CRC1) && (pData[1] == _HDMI_CRC2) && (pData[2] == _HDMI_CRC3) &&
               (pData[3] == _HDMI_CRC4) && (pData[4] == _HDMI_CRC5) && (pData[5] == _HDMI_CRC0))
            {
                DebugMessageScaler("6. HDMI Test Pass", 0x00);
                return _TEST_PASS;
            }            

            break;
            
        case _HDMI_CRC2:

            if((pData[0] == _HDMI_CRC2) && (pData[1] == _HDMI_CRC3) && (pData[2] == _HDMI_CRC4) &&
               (pData[3] == _HDMI_CRC5) && (pData[4] == _HDMI_CRC0) && (pData[5] == _HDMI_CRC1))
            {
                DebugMessageScaler("6. HDMI Test Pass", 0x00);
                return _TEST_PASS;
            }            
            
            break;
            
        case _HDMI_CRC3:

            if((pData[0] == _HDMI_CRC3) && (pData[1] == _HDMI_CRC4) && (pData[2] == _HDMI_CRC5) &&
               (pData[3] == _HDMI_CRC0) && (pData[4] == _HDMI_CRC1) && (pData[5] == _HDMI_CRC2))
            {
                DebugMessageScaler("6. HDMI Test Pass", 0x00);
                return _TEST_PASS;
            }            
            
            break;
            
        case _HDMI_CRC4:
            
            if((pData[0] == _HDMI_CRC4) && (pData[1] == _HDMI_CRC5) && (pData[2] == _HDMI_CRC0) &&
               (pData[3] == _HDMI_CRC1) && (pData[4] == _HDMI_CRC2) && (pData[5] == _HDMI_CRC3))
            {
                DebugMessageScaler("6. HDMI Test Pass", 0x00);
                return _TEST_PASS;
            }            
            
            break;
            
        case _HDMI_CRC5:

            if((pData[0] == _HDMI_CRC5) && (pData[1] == _HDMI_CRC0) && (pData[2] == _HDMI_CRC1) &&
               (pData[3] == _HDMI_CRC2) && (pData[4] == _HDMI_CRC3) && (pData[5] == _HDMI_CRC4))
            {
                DebugMessageScaler("6. HDMI Test Pass", 0x00);
                return _TEST_PASS;
            }            
            break;     
            
        default:

            break;        
    }   

    DebugMessageScaler("6. HDMI Test Fail", 0x00);    

    return _TEST_FAIL;
}
#endif // End of #if(_HDMI_SUPPORT == _ON)


#if(_DP_SUPPORT == _ON)
//******************************************//
// DP Test condition--                    //
//         Timing : 1920x1080@60            //
//         Color Depth : 12 bit RGB         //
//         Pattern : Gamma Ramp wr=2.5      //
//         Source : VG-870                  //
//******************************************//

//--------------------------------------------------
// Description  : DP Test
// Input Value  : None
// Output Value : _TRUE
//--------------------------------------------------
bit ScalerQCDpTest(void)
{
    BYTE ucResult = 0;
    
    // Test Abuf BIST
    ScalerSetBit(PC_B2_DP_MEM_BIST, ~_BIT2, _BIT2);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, PC_B2_DP_MEM_BIST, _BIT2, 0x00) == _TRUE)
    {
        if(ScalerGetBit(PC_B2_DP_MEM_BIST, _BIT3) != _BIT3)
        {
            DebugMessageScaler("5. DP Abuf Bist Fail", 0x00);
            ucResult |= _BIT2;
        }
    }
    else
    {
        DebugMessageScaler("5. DP Abuf Bist Fail", 0x00);
        ucResult |= _BIT2;
    }
    
    // Test Vbuf BIST
    ScalerSetBit(PC_B2_DP_MEM_BIST, ~_BIT0, _BIT0);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, PC_B2_DP_MEM_BIST, _BIT0, 0x00) == _TRUE)
    {
        if(ScalerGetBit(PC_B2_DP_MEM_BIST, _BIT1) != _BIT1)
        {
            DebugMessageScaler("5. DP Vbuf Bist Fail", 0x00);
            ucResult |= _BIT1;
        }
    }
    else
    {
        DebugMessageScaler("5. DP Vbuf Bist Fail", 0x00);
        ucResult |= _BIT1;
    }

    // Test HDCP BIST
    ScalerSetBit(PC_E9_DP_HDCP_BIST, ~_BIT2, _BIT2);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, PC_E9_DP_HDCP_BIST, _BIT1, _BIT1) == _TRUE)
    {
        if(ScalerGetBit(PC_E9_DP_HDCP_BIST, _BIT0) != 0x00)
        {
            DebugMessageScaler("5. DP HDCP Bist Fail", 0x00);
            ucResult |= _BIT3;
        }
    }
    else
    {
        DebugMessageScaler("5. DP HDCP Bist Fail", 0x00);
        ucResult |= _BIT3;
    }
    ScalerSetBit(PC_E9_DP_HDCP_BIST, ~_BIT2, 0x00);    

    // Reserved for DP Test
    ScalerSetBit(PC_AB_DP_CRC, ~(_BIT7 | _BIT5), 0x00);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerSetBit(PC_AB_DP_CRC, ~(_BIT7 | _BIT5), (_BIT7 | _BIT5));
    
    if(ScalerTimerPollingFlagProc(80, PC_AB_DP_CRC, _BIT6, _TRUE) == _FALSE)
    {
        DebugMessageScaler("5. DP CRC Calculation Timeout", 0x00);        
        ucResult |= _BIT0;
    }
    else
    {
        if((ScalerGetByte(PC_AC_DP_CRC_R_H) != _DP_CRC0) || (ScalerGetByte(PC_AD_DP_CRC_R_L) != _DP_CRC1) || \
           (ScalerGetByte(PC_AE_DP_CRC_G_H) != _DP_CRC2) || (ScalerGetByte(PC_AF_DP_CRC_G_L) != _DP_CRC3) || \
           (ScalerGetByte(PC_B0_DP_CRC_B_H) != _DP_CRC4) || (ScalerGetByte(PC_B1_DP_CRC_B_L) != _DP_CRC5))
        {
            DebugMessageScaler("5. DP CRC Value Mismatch", 0x00);        
            ucResult |= _BIT0;
        }
    }
    
    if((bit)ucResult == 0x00)
    {
        DebugMessageScaler("6. DP Test PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. DP Fail Mode", ucResult);
        DebugMessageScaler("6. DP Test FAIL", 0x00);    
        return _TEST_FAIL;
    }
}
#endif

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

/*
#if(_LVDS_EO_CLK_MERGE == _DISABLE)
//-------------------------------------------------- 
// Description  : FPGA for mLVDS6x configuration setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGA6xTable(void)
{
    ScalerQCFPGASetByte(0x00, 0x40);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x00, 0x41);
    ScalerTimerDelayXms(50);
    ScalerQCFPGASetByte(0x01, 0x05);
    ScalerQCFPGASetByte(0x02, 0x58);
    ScalerTimerDelayXms(20);

    ScalerQCFPGASetByte(0x30, 0x9E);//10_E2-    //8_E0-
    ScalerQCFPGASetByte(0x31, 0x16);//10_E2+    //8_E0+
    ScalerQCFPGASetByte(0x32, 0x07);//10_EC-    //8_E1-
    ScalerQCFPGASetByte(0x33, 0x34);//10_EC+    //8_E1+
    ScalerQCFPGASetByte(0x34, 0x46);//10_E3-    //8_E2-
    ScalerQCFPGASetByte(0x35, 0x54);//10_E3+    //8_E2+
    ScalerQCFPGASetByte(0x36, 0x3F);//10_E0-    //None
    ScalerQCFPGASetByte(0x37, 0xB1);//10_E0+    //None
    ScalerQCFPGASetByte(0x38, 0x3F);//10_E1-    //None
    ScalerQCFPGASetByte(0x39, 0xB1);//10_E1+    //None
    ScalerQCFPGASetByte(0x3a, 0x56);//10_O1-    //8_O0-
    ScalerQCFPGASetByte(0x3b, 0x7D);//10_O1+    //8_O0+
    ScalerQCFPGASetByte(0x3c, 0x99);//10_O2-    //8_O1-
    ScalerQCFPGASetByte(0x3d, 0x48);//10_O2+    //8_O1+
    ScalerQCFPGASetByte(0x3e, 0x24);//10_OC-    //8_O2-
    ScalerQCFPGASetByte(0x3f, 0xA0);//10_OC+    //8_O2+
    ScalerQCFPGASetByte(0x40, 0x56);//10_O4-    //8_O3-
    ScalerQCFPGASetByte(0x41, 0x7D);//10_O4+    //8_O3+
    ScalerQCFPGASetByte(0x42, 0x9E);//10_O0-    //8_E3-
    ScalerQCFPGASetByte(0x43, 0x16);//10_O0+    //8_E3+

    ScalerQCFPGASetByte(0x0f, 0x04);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x0f, 0x00);
    ScalerTimerDelayXms(50);
}
#endif
*/

//-------------------------------------------------- 
// Description  : FPGA for mLVDS7x configuration setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGA7xTable(void)
{

#if(_LVDS_EO_CLK_MERGE == _DISABLE)
    ScalerQCFPGASetByte(0x00, 0x80);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x00, 0x81);
    ScalerTimerDelayXms(50);
    ScalerQCFPGASetByte(0x01, 0x05);
    ScalerQCFPGASetByte(0x02, 0x58);
    ScalerTimerDelayXms(20);

    ScalerQCFPGASetByte(0x30, 0x4E);//10_E2-    //8_E0-
    ScalerQCFPGASetByte(0x31, 0xEB);//10_E2+    //8_E0+
    ScalerQCFPGASetByte(0x32, 0xD7);//10_EC-    //8_E1-
    ScalerQCFPGASetByte(0x33, 0xC9);//10_EC+    //8_E1+
    ScalerQCFPGASetByte(0x34, 0x29);//10_E3-    //8_E2-
    ScalerQCFPGASetByte(0x35, 0xC8);//10_E3+    //8_E2+
    ScalerQCFPGASetByte(0x36, 0x3F);//10_E0-    //None
    ScalerQCFPGASetByte(0x37, 0xB1);//10_E0+    //None
    ScalerQCFPGASetByte(0x38, 0x3F);//10_E1-    //None
    ScalerQCFPGASetByte(0x39, 0xB1);//10_E1+    //None
    ScalerQCFPGASetByte(0x3a, 0x7F);//10_O1-    //8_O0-
    ScalerQCFPGASetByte(0x3b, 0x1C);//10_O1+    //8_O0+
    ScalerQCFPGASetByte(0x3c, 0xB0);//10_O2-    //8_O1-
    ScalerQCFPGASetByte(0x3d, 0x29);//10_O2+    //8_O1+
    ScalerQCFPGASetByte(0x3e, 0xB2);//10_OC-    //8_O2-
    ScalerQCFPGASetByte(0x3f, 0xA0);//10_OC+    //8_O2+
    ScalerQCFPGASetByte(0x40, 0x7F);//10_O4-    //8_O3-
    ScalerQCFPGASetByte(0x41, 0x1C);//10_O4+    //8_O3+
    ScalerQCFPGASetByte(0x42, 0x4E);//10_O0-    //8_E3-
    ScalerQCFPGASetByte(0x43, 0xEB);//10_O0+    //8_E3+

    ScalerQCFPGASetByte(0x0f, 0x04);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x0f, 0x00);
    ScalerTimerDelayXms(50);
#else
    ScalerQCFPGASetByte(0x00, 0x01);
    ScalerTimerDelayXms(200);
    ScalerQCFPGASetByte(0x00, 0x1E);
    ScalerTimerDelayXms(200);
    ScalerQCFPGASetByte(0x00, 0x3E);
    ScalerTimerDelayXms(200);
    ScalerQCFPGASetByte(0x10, 0x11);
    ScalerTimerDelayXms(50);
#endif

}

/*
#if(_LVDS_EO_CLK_MERGE == _DISABLE)
//-------------------------------------------------- 
// Description  : FPGA for mLVDS8x configuration setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGA8xTable(void)
{
    ScalerQCFPGASetByte(0x00, 0x00);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x00, 0x01);
    ScalerTimerDelayXms(50);
    ScalerQCFPGASetByte(0x01, 0x05);
    ScalerQCFPGASetByte(0x02, 0x58);
    ScalerTimerDelayXms(20);

    ScalerQCFPGASetByte(0x30, 0xF7);//10_E2-    //8_E0-
    ScalerQCFPGASetByte(0x31, 0x79);//10_E2+    //8_E0+
    ScalerQCFPGASetByte(0x32, 0x6E);//10_EC-    //8_E1-
    ScalerQCFPGASetByte(0x33, 0x5B);//10_EC+    //8_E1+
    ScalerQCFPGASetByte(0x34, 0x90);//10_E3-    //8_E2-
    ScalerQCFPGASetByte(0x35, 0x5A);//10_E3+    //8_E2+
    ScalerQCFPGASetByte(0x36, 0x3F);//10_E0-    //None
    ScalerQCFPGASetByte(0x37, 0xB1);//10_E0+    //None
    ScalerQCFPGASetByte(0x38, 0x3F);//10_E1-    //None
    ScalerQCFPGASetByte(0x39, 0xB1);//10_E1+    //None
    ScalerQCFPGASetByte(0x3a, 0xF8);//10_O1-    //8_O0-
    ScalerQCFPGASetByte(0x3b, 0x01);//10_O1+    //8_O0+
    ScalerQCFPGASetByte(0x3c, 0x37);//10_O2-    //8_O1-
    ScalerQCFPGASetByte(0x3d, 0x34);//10_O2+    //8_O1+
    ScalerQCFPGASetByte(0x3e, 0x35);//10_OC-    //8_O2-
    ScalerQCFPGASetByte(0x3f, 0xBD);//10_OC+    //8_O2+
    ScalerQCFPGASetByte(0x40, 0xF8);//10_O4-    //8_O3-
    ScalerQCFPGASetByte(0x41, 0x01);//10_O4+    //8_O3+
    ScalerQCFPGASetByte(0x42, 0xF7);//10_O0-    //8_E3-
    ScalerQCFPGASetByte(0x43, 0x79);//10_O0+    //8_E3+

    ScalerQCFPGASetByte(0x0f, 0x04);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x0f, 0x00);
    ScalerTimerDelayXms(50);
}
#endif
*/

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
void ScalerQCFPGAContent(BYTE ucType, BYTE *pucPass)
{

#if(_LVDS_EO_CLK_MERGE == _DISABLE)
    BYTE ucCheck[21];
    BYTE ucCRC[20];
    
    ScalerQCFPGARead(0x00, &ucCheck[0]);
    DebugMessageScaler("5. FPGA_0x00=", ucCheck[0]);
    ScalerQCFPGARead(0x01, &ucCheck[1]);
    DebugMessageScaler("5. FPGA_0x01=", ucCheck[1]);
    ScalerQCFPGARead(0x02, &ucCheck[2]);
    DebugMessageScaler("5. FPGA_0x02=", ucCheck[2]);
    ScalerQCFPGARead(0x08, &ucCheck[3]);
    DebugMessageScaler("5. FPGA_0x08=", ucCheck[3]);
    ScalerQCFPGARead(0x09, &ucCheck[4]);
    DebugMessageScaler("5. FPGA_0x09=", ucCheck[4]);
    ScalerQCFPGARead(0x10, &ucCheck[5]);
    DebugMessageScaler("5. FPGA_0x10=", ucCheck[5]);
    ScalerQCFPGARead(0x11, &ucCheck[6]);
    DebugMessageScaler("5. FPGA_0x11=", ucCheck[6]);
    ScalerQCFPGARead(0x12, &ucCheck[7]);
    DebugMessageScaler("5. FPGA_0x12=", ucCheck[7]);
    ScalerQCFPGARead(0x13, &ucCheck[8]);
    DebugMessageScaler("5. FPGA_0x13=", ucCheck[8]);
    ScalerQCFPGARead(0x14, &ucCheck[9]);
    DebugMessageScaler("5. FPGA_0x14=", ucCheck[9]);
    ScalerQCFPGARead(0x15, &ucCheck[10]);
    DebugMessageScaler("5. FPGA_0x15=", ucCheck[10]);
    ScalerQCFPGARead(0x1A, &ucCheck[11]);
    DebugMessageScaler("5. FPGA_0x1A=", ucCheck[11]);
    ScalerQCFPGARead(0x1B, &ucCheck[12]);
    DebugMessageScaler("5. FPGA_0x1B=", ucCheck[12]);
    ScalerQCFPGARead(0x1C, &ucCheck[13]);
    DebugMessageScaler("5. FPGA_0x1C=", ucCheck[13]);
    ScalerQCFPGARead(0x1D, &ucCheck[14]);
    DebugMessageScaler("5. FPGA_0x1D=", ucCheck[14]);
    ScalerQCFPGARead(0x1E, &ucCheck[15]);
    DebugMessageScaler("5. FPGA_0x1E=", ucCheck[15]);
    ScalerQCFPGARead(0x1F, &ucCheck[16]);
    DebugMessageScaler("5. FPGA_0x1F=", ucCheck[16]);
    ScalerQCFPGARead(0x20, &ucCheck[17]);
    DebugMessageScaler("5. FPGA_0x20=", ucCheck[17]);
    ScalerQCFPGARead(0x21, &ucCheck[18]);
    DebugMessageScaler("5. FPGA_0x21=", ucCheck[18]);
    ScalerQCFPGARead(0x22, &ucCheck[19]);
    DebugMessageScaler("5. FPGA_0x22=", ucCheck[19]);
    ScalerQCFPGARead(0x23, &ucCheck[20]);
    DebugMessageScaler("5. FPGA_0x23=", ucCheck[20]);

    ScalerRead(P15_B6_OP_CRC_RESULT4, 20, &ucCRC, _AUTOINC);

    if((ucCheck[1] == 0x05) && (ucCheck[2] == 0x58) && (ucCheck[3] == 0x08) && (ucCheck[4] == 0x08) &&
       (ucCheck[5] == ucCRC[0]) && (ucCheck[6] == ucCRC[1]) && (ucCheck[7] == ucCRC[2]) && (ucCheck[8] == ucCRC[3]) && 
       (ucCheck[9] == ucCRC[4]) && (ucCheck[10] == ucCRC[5]) && (ucCheck[11] == ucCRC[10]) && (ucCheck[12] == ucCRC[11]) && 
       (ucCheck[13] == ucCRC[12]) && (ucCheck[14] == ucCRC[13]) && (ucCheck[15] == ucCRC[14]) && (ucCheck[16] == ucCRC[15]) && 
       (ucCheck[17] == ucCRC[18]) && (ucCheck[18] == ucCRC[19]) && (ucCheck[19] == ucCRC[8]) && (ucCheck[20] == ucCRC[9]))
    {
        if(ucType == _MLVDS6X)
        {
            DebugMessageScaler("5. FPGA6x Content Pass", 0x00);
        }

        else if(ucType == _MLVDS7X)
        {
            DebugMessageScaler("5. FPGA7x Content Pass", 0x00);
        }

        else
        {
            DebugMessageScaler("5. FPGA8x Content Pass", 0x00);
        }
        *pucPass |= _TEST_PASS;
    }
    else
    {
        if(ucType == _MLVDS6X)
        {
            DebugMessageScaler("5. FPGA6x Content Fail", 0x00);
        }

        else if(ucType == _MLVDS7X)
        {
            DebugMessageScaler("5. FPGA7x Content Fail", 0x00);
        }

        else
        {
            DebugMessageScaler("5. FPGA8x Content Fail", 0x00);
        }
        *pucPass |= _TEST_FAIL;

    }
#else
    BYTE ucCheck[6];

    if(ucType == _MLVDS7X)
    {
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


        if((ucCheck[0] == 0xCF) && (ucCheck[1] == 0x22) && (ucCheck[2] == 0xAA) && (ucCheck[3] == 0x3B) && (ucCheck[4] == 0x73) && (ucCheck[5] == 0x6D))
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
#endif

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

    ScalerSetByte(P10_D5_PIN_SHARE_CTRL18, 0x00); // Page 10-D5 Pin 57

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
    
    ScalerSetByte(P10_D5_PIN_SHARE_CTRL18, 0x01); // Page 10-D5 Pin 57
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

    ScalerRead(P10_D4_PIN_SHARE_CTRL17, 1, &ucScl, _AUTOINC);    // Page 10-D4 Pin 56
    ScalerRead(P10_D5_PIN_SHARE_CTRL18, 1, &ucSda, _AUTOINC);    // Page 10-D5 Pin 57
    ScalerSetByte(P10_D4_PIN_SHARE_CTRL17, 0x01);
    ScalerSetByte(P10_D5_PIN_SHARE_CTRL18, 0x01);
    ScalerTimerDelayXms(1); 

    ScalerBurstWrite(tQC_COMMONMLVDS, sizeof(tQC_COMMONMLVDS), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH); 
/*
    ScalerBurstWrite(tQC_MLVDS6X, sizeof(tQC_MLVDS6X), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH); 
    ScalerQCFPGA6xTable();
    ScalerTimerDelayXms(1); 
    ScalerQCFPGAContent(_MLVDS6X, &ucPass);
*/     
    ScalerBurstWrite(tQC_MLVDS7X, sizeof(tQC_MLVDS7X), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH); 
    ScalerQCFPGA7xTable();
    ScalerTimerDelayXms(1); 
    ScalerQCFPGAContent(_MLVDS7X, &ucPass);
/*
    ScalerBurstWrite(tQC_MLVDS8X, sizeof(tQC_MLVDS8X), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH); 
    ScalerQCFPGA8xTable();
    ScalerQCFPGAContent(_MLVDS8X, &ucPass);
*/
    
    if(ucPass == _TEST_FAIL)
    {
        DebugMessageScaler("6. FPGA for mLVSD Fail ", 0x00);
    }
    else
    {
        DebugMessageScaler("6. FPGA for mLVSD ucPass ", 0x00);
    }
    
    ScalerSetByte(P10_D4_PIN_SHARE_CTRL17, ucScl);
    ScalerSetByte(P10_D5_PIN_SHARE_CTRL18, ucSda);
    ScalerTimerDelayXms(1); 
    return ucPass;
}

#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)
