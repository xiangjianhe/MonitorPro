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

#define __RL6229_SERIES_QC__

#include "ScalerFunctionInclude.h"

#if(_FACTORY_RTD_QC_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _TEST_PASS                                      0
#define _TEST_FAIL                                      1

//****************************************************************************
// SDRAM Auto K QC Test
//****************************************************************************
#define _SDRAM_PHASE_CALIBRATION_QC                     _ON 

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)  

// Definitions of SDRAM spread spectrum range
#define _MCLK_SPREAD_SPECTRUM_RANGE                     (0) // Disable MCLK spread specturm
                              
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
#define _TEST_DATA_MAX                                  (16)
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
#define _TEST_DATA_MAX                                  (32) 
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
#define _TEST_DATA_MAX                                  (32)
#endif

#define _DEFAULT_CONFLICT_AREA                          (10)

#endif

//----------------------------------------------------------------------------
// BIST QC Test
//----------------------------------------------------------------------------
#define _BIST_TIMEOUT                                   60

#define _GRAY                                           0
#define _MASS                                           1

#define _MSB                                            0
#define _LSB                                            1

// Defineions of SDRAM parameter
#define _ROW_RD_DELAY                                   (3)  // 0~2:Reserved, 3~5:3~5 MCLK, 6~7:Reserved
#define _ROW_WR_DELAY                                   (3)  // 0~1:Reserved, 2~5:2~5 MCLK, 6~7:Reserved
#define _SDR_ROW_DELAY                                  ((_ROW_RD_DELAY << 3) | (_ROW_WR_DELAY))
#define _SDR_COL_DELAY                                  ((3 << 5) | 0x04) // 0~1:Reserved, 2~3:2~3 MCLK, 4~7:Reserved

// Definitions of MPLL N Code
#define _MPLL_N_CODE                                    (2)

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
typedef enum
{
    _VGIP_MASK_ACTIVE_SPACE_0 = 0,
    _VGIP_MASK_ACTIVE_SPACE_1,
    _VGIP_MASK_ACTIVE_SPACE_2,
    _VGIP_MASK_ACTIVE_SPACE_3,
} EnumVgipMaskActiveSpaceNum;


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Description  : SDRAM Auto K Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

BYTE code tSDRAM_PATTERN[16] = {0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc};

#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)

BYTE code tSDRAM_PATTERN[32] = {0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc,
                                0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc};

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

BYTE code tSDRAM_PATTERN[32] = {0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc,
                                0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc};
#endif

#endif

//--------------------------------------------------
// Description  : I Domain DLCTI Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------

BYTE code tQC_IDLCTI_SETTING_1[] = 
{	
     0x05,0x3F,0x05,0x01,0x90,0x00,
	 0x78,0x00,0xCD,0x01,0xCE,0x01,
	 0xEF,0x01,0xF0,0x01,0xEA,       //IDLTI (17)

	 0x81,0x1E,0x0A,0x1E,0x0A,0x00,
	 0x08,0xFF,0x3C,0x08,0x16,0x08,
	 0x44,0x48,                      //IDCTI (14)
	 
};
BYTE code tQC_IDLCTI_SETTING_2[] = 
{	
     0x0B,0x3F,0x05,0x01,0x90,0x00,
	 0x78,0x00,0xCD,0x01,0xCE,0x01,
	 0xEF,0x01,0xF0,0x01,0xEA,       //IDLTI (17)

	 0x82,0x1E,0x0A,0x1E,0x0A,0x00,
	 0x08,0xFF,0x3C,0x08,0x16,0x08,
	 0x44,0x48,                      //IDCTI (14)
	 
};


BYTE code tQC_IDLCTI_HLW[] = 
{	
     0x00,0x10,0x00,0xA0,0x00,0x10,0x00,0xA0, //IDLCTI HLW Setting (8)		 
};
//--------------------------------------------------
// Description  : VPK VCTI Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------

BYTE code tQC_VPK_VCTI_SETTING[] = 
{	
     //VPK VCTI(19) start from 0x11B9
     0x28,0xFF,0x3C,0x08,0x10,0x08,0x44,
     0x48,0x02,0x0A,0x18,0x00,0x0A,0x00,0x96,0x00,0x00,0x00,0x64,	 
};
BYTE code tQC_VPK_VCTI_HLW[] = 
{	
     //VPK VCTI HLW (8) start from 0x11CC
     0x00,0x40,0x02,0x07,0x00,0x55,0x02,0xAA
      
};


//--------------------------------------------------
// Description  : Super Resolution Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------

BYTE code tQC_SR_SETTING_PAGE11_1[] = 
{				     
     //DDLCTI(9) start from 0x11F0
	 0x3F,0x2A,0x61,0x1E,0x07,0x1E,0x0A,0x1E,0x0A 
};

BYTE code tQC_SR_SETTING_PAGE12_1[] = 
{				     
     //SHP(43) start from 0x12A0
	 0xDF,0x00,0x40,0x00,0x7E,0x01,0xB7,0x0A,0x00,0x00,0x00,0x00,0x30,0x40,0x00,0x48,
	 0x00,0x60,0x10,0x00,0x50,0x00,0x16,0x00,0x61,0x06,0x00,0x06,0x00,0x05,0x00,0x64,
	 0x04,0x28,0x00,0x10,0x00,0x40,0x01,0x00,0x00,0x40,0x08,0x08,0x00,0x00,0xFF,0x00,	 
};

BYTE code tQC_SR_SETTING_PAGE13_1[] = 
{				     
     //SHP(69) start from 0x13A0
	 0x70,0x31,0x01,0xE0,0x01,0x68,0x02,0x8A,0x02,0x30,0x03,0xE8,0x02,0x58,0x01,0xCC,
	 0x01,0x68,0x00,0x26,0x36,0x00,0x34,0x00,0x42,0x10,0x00,0x12,0x22,0x00,0x16,0x00,
	 0x2E,0x10,0x01,0xE0,0x01,0x68,0x02,0x8A,0x02,0x30,0x03,0xE8,0x02,0x58,0x01,0xCC,
	 0x01,0x68,0x00,0x00,0x3E,0x33,0x31,0x31,0xFF,0x42,0xFF,0xFF,0xFF,0xFF,0x00,0x03,
	 0x40,0xFF,0xFF,0x14,0x14,
};

BYTE code tQC_SR_SETTING_PAGE11_2[] = 
{				     
     //DDLCTI(9) start from 0x11F0
	 0x39,0x2A,0x65,0x1E,0x07,0x1E,0x0A,0x1E,0x0A 
};

BYTE code tQC_SR_SETTING_PAGE12_2[] = 
{				     
     //SHP(43) start from 0x12A0
	 0xDF,0x00,0x40,0x00,0x7E,0x01,0xB7,0x0A,0x00,0x00,0x00,0x00,0x30,0x40,0x00,0x48,
	 0x00,0x60,0x10,0x00,0x50,0x00,0x16,0x00,0x61,0x06,0x00,0x06,0x00,0x05,0x00,0x64,
	 0x04,0x28,0x00,0x10,0x00,0x40,0x01,0x00,0x74,0x40,0x08,0x08,0x00,0x00,0xFF,0x00,	 
};

BYTE code tQC_SR_SETTING_PAGE13_2[] = 
{				     
     //SHP(69) start from 0x13A0
	 0x70,0x31,0x01,0xE0,0x01,0x68,0x02,0x8A,0x02,0x30,0x03,0xE8,0x02,0x58,0x01,0xCC,
	 0x01,0x68,0x00,0x26,0x36,0x00,0x34,0x00,0x42,0x10,0x00,0x12,0x22,0x00,0x16,0x00,
	 0x2E,0x10,0x01,0xE0,0x01,0x68,0x02,0x8A,0x02,0x30,0x03,0xE8,0x02,0x58,0x01,0xCC,
	 0x01,0x68,0x00,0x00,0x3F,0x33,0x31,0x31,0xFF,0x42,0xFF,0xFF,0xFF,0xFF,0x00,0x04,
	 0x40,0xFF,0xFF,0x14,0x14,
};

//--------------------------------------------------
// Description  : ADC Histogram Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_ADCH_SETTING_FUNC1A[] = 
{				     
   //ADC Histogram window setting(8),  start from 0x1EA0
   0x07,0x80,0x00,0x64,0x00,0x96,0x00,0x96,   
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
// Description  : I Dither Offset Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_IDITHER_TEMOFFSET[] = 
{
    0xFF, 0xFF, 0xFF, 0xFF,
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

    0x63, 0x27, 0x93, 0x1E, 0x36, 0x2D, 0xD8, 0x4E, 0x36, 0x2D, 0xD2, 0x39,
    0x1E, 0x8D, 0x39, 0x87, 0x36, 0xB1, 0x9C, 0xD2, 0x87, 0x27, 0x1B, 0xD8,   
    
    0xE1, 0xF7, 0xE6, 0xB7, 0x27, 0xB9, 0x8C, 0x8E, 0xD2, 0xEB, 0x3C, 0xA6,
    0x30, 0x56, 0xAD, 0xC6, 0x61, 0xFB, 0xCB, 0x39, 0x6C, 0x5D, 0x03, 0x02,
    
    0xD2, 0xD8, 0x93, 0xB4, 0x2D, 0x39, 0x9C, 0x2D, 0xC9, 0x4B, 0xD2, 0x87,
    0x27, 0xE1, 0xC6, 0x93, 0x2D, 0x9C, 0xD8, 0xC6, 0x1B, 0x36, 0x93, 0x1E,    
};

//--------------------------------------------------
// Description  : Dither Offset Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_DITHER_TEMOFFSET[] = 
{
    0xE4, 0xE4, 0xE4, 0xE4,
};

//--------------------------------------------------
// Description  : Dither THD Table Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_DITHER_THD[] = 
{
    0x00, 0x15, 0x01, 0x35, 0x01, 0x12,
};


BYTE code tQC_DITHER_NEWFUNC1_MSB_CRC_TABLE[] =
{
    0xe9, 0xb6, 0x95,
    0x24, 0x8b, 0x10,
    0xff, 0x02, 0xae,
    0x46, 0x21, 0x6d,
    0xe9, 0xb6, 0x95,
    0x24, 0x8b, 0x10,
    0xff, 0x02, 0xae,
    0x46, 0x21, 0x6d,
    0xe9, 0xb6, 0x95,
    0x24, 0x8b, 0x10,
    0xff, 0x02, 0xae,
    0x46, 0x21, 0x6d,
    0xe9, 0xb6, 0x95,
    0x24, 0x8b, 0x10,
    0xff, 0x02, 0xae,
    0x46, 0x21, 0x6d,
    0xe9, 0xb6, 0x95,
    0x24, 0x8b, 0x10,
    0xff, 0x02, 0xae,
    0x46, 0x21, 0x6d,
    0xe9, 0xb6, 0x95,
    0x24, 0x8b, 0x10,
    0xff, 0x02, 0xae,
    0x46, 0x21, 0x6d,
};

BYTE code tQC_DITHER_NEWFUNC1_LSB_CRC_TABLE[] =
{
    0x18, 0xe7, 0xf8,
    0x6a, 0xb3, 0xe5,
    0xee, 0x5a, 0x47,
    0xff, 0x70, 0xb8,
    0x18, 0xe7, 0xf8,
    0x6a, 0xb3, 0xe5,
    0xee, 0x5a, 0x47,
    0xff, 0x70, 0xb8,
    0x18, 0xe7, 0xf8,
    0x6a, 0xb3, 0xe5,
    0xee, 0x5a, 0x47,
    0xff, 0x70, 0xb8,
    0x18, 0xe7, 0xf8,
    0x6a, 0xb3, 0xe5,
    0xee, 0x5a, 0x47,
    0xff, 0x70, 0xb8,
    0x18, 0xe7, 0xf8,
    0x6a, 0xb3, 0xe5,
    0xee, 0x5a, 0x47,
    0xff, 0x70, 0xb8,
    0x18, 0xe7, 0xf8,
    0x6a, 0xb3, 0xe5,
    0xee, 0x5a, 0x47,
    0xff, 0x70, 0xb8,
};

BYTE code tQC_DITHER_NEWFUNC2_MSB_CRC_TABLE[] =
{
    0xd1, 0x89, 0x89,
    0xd1, 0x89, 0x89,
    0xd1, 0x89, 0x89,
    0xd1, 0x89, 0x89,
    0xd4, 0x0a, 0x34,
    0xd4, 0x0a, 0x34,
    0xd4, 0x0a, 0x34,
    0xd4, 0x0a, 0x34,
    0x31, 0x9a, 0xd9,
    0x31, 0x9a, 0xd9,
    0x31, 0x9a, 0xd9,
    0x31, 0x9a, 0xd9,
    0xcb, 0xaa, 0x0e,
    0xcb, 0xaa, 0x0e,
    0xcb, 0xaa, 0x0e,
    0xcb, 0xaa, 0x0e,
    0x8a, 0x7a, 0x17,
    0x8a, 0x7a, 0x17,
    0x8a, 0x7a, 0x17,
    0x8a, 0x7a, 0x17,
    0x96, 0x2f, 0x5f,
    0x96, 0x2f, 0x5f,
    0x96, 0x2f, 0x5f,
    0x96, 0x2f, 0x5f,
    0x29, 0x18, 0xb7,
    0x29, 0x18, 0xb7,
    0x29, 0x18, 0xb7,
    0x29, 0x18, 0xb7,
    0x59, 0xf2, 0x47,
    0x59, 0xf2, 0x47,
    0x59, 0xf2, 0x47,
    0x59, 0xf2, 0x47,
    0xd1, 0x86, 0xd9,
    0xd1, 0x86, 0xd9,
    0xd1, 0x86, 0xd9,
    0xd1, 0x86, 0xd9,
    0x2e, 0xab, 0x2e,
    0x2e, 0xab, 0x2e,
    0x2e, 0xab, 0x2e,
    0x2e, 0xab, 0x2e,
    0x32, 0x69, 0x12,
    0x32, 0x69, 0x12,
    0x32, 0x69, 0x12,
    0x32, 0x69, 0x12,
    0xc8, 0xa1, 0x8f,
    0xc8, 0xa1, 0x8f,
    0xc8, 0xa1, 0x8f,
    0xc8, 0xa1, 0x8f,
    0xab, 0xa6, 0xbe,
    0xab, 0xa6, 0xbe,
    0xab, 0xa6, 0xbe,
    0xab, 0xa6, 0xbe,
    0x8a, 0xc5, 0xe6,
    0x8a, 0xc5, 0xe6,
    0x8a, 0xc5, 0xe6,
    0x8a, 0xc5, 0xe6,
    0x25, 0x27, 0xe3,
    0x25, 0x27, 0xe3,
    0x25, 0x27, 0xe3,
    0x25, 0x27, 0xe3,
    0x8a, 0x80, 0x42,
    0x8a, 0x80, 0x42,
    0x8a, 0x80, 0x42,
    0x8a, 0x80, 0x42,
    0xcf, 0xb5, 0x32,
    0xcf, 0xb5, 0x32,
    0xcf, 0xb5, 0x32,
    0xcf, 0xb5, 0x32,
    0xe4, 0x8c, 0xcc,
    0xe4, 0x8c, 0xcc,
    0xe4, 0x8c, 0xcc,
    0xe4, 0x8c, 0xcc,
    0x27, 0x80, 0x9b,
    0x27, 0x80, 0x9b,
    0x27, 0x80, 0x9b,
    0x27, 0x80, 0x9b,
    0xdd, 0x20, 0xfe,
    0xdd, 0x20, 0xfe,
    0xdd, 0x20, 0xfe,
    0xdd, 0x20, 0xfe,
    0x72, 0x55, 0xa9,
    0x72, 0x55, 0xa9,
    0x72, 0x55, 0xa9,
    0x72, 0x55, 0xa9,
    0xda, 0xa3, 0xb1,
    0xda, 0xa3, 0xb1,
    0xda, 0xa3, 0xb1,
    0xda, 0xa3, 0xb1,
    0x84, 0xe0, 0xcf,
    0x84, 0xe0, 0xcf,
    0x84, 0xe0, 0xcf,
    0x84, 0xe0, 0xcf,
    0x07, 0xaa, 0x0d,
    0x07, 0xaa, 0x0d,
    0x07, 0xaa, 0x0d,
    0x07, 0xaa, 0x0d,
};

BYTE code tQC_DITHER_NEWFUNC2_LSB_CRC_TABLE[] =
{
    0x4a, 0x76, 0xb6,
    0x4a, 0x76, 0xb6,
    0x4a, 0x76, 0xb6,
    0x4a, 0x76, 0xb6,
    0x41, 0xf3, 0x27,
    0x41, 0xf3, 0x27,
    0x41, 0xf3, 0x27,
    0x41, 0xf3, 0x27,
    0x7d, 0x75, 0xfd,
    0x7d, 0x75, 0xfd,
    0x7d, 0x75, 0xfd,
    0x7d, 0x75, 0xfd,
    0x68, 0x44, 0x76,
    0x68, 0x44, 0x76,
    0x68, 0x44, 0x76,
    0x68, 0x44, 0x76,
    0x3b, 0xfc, 0xcb,
    0x3b, 0xfc, 0xcb,
    0x3b, 0xfc, 0xcb,
    0x3b, 0xfc, 0xcb,
    0x35, 0x93, 0x42,
    0x35, 0x93, 0x42,
    0x35, 0x93, 0x42,
    0x35, 0x93, 0x42,
    0xa0, 0x49, 0x24,
    0xa0, 0x49, 0x24,
    0xa0, 0x49, 0x24,
    0xa0, 0x49, 0x24,
    0xad, 0x82, 0xc6,
    0xad, 0x82, 0xc6,
    0xad, 0x82, 0xc6,
    0xad, 0x82, 0xc6,
    0x3e, 0x67, 0x22,
    0x3e, 0x67, 0x22,
    0x3e, 0x67, 0x22,
    0x3e, 0x67, 0x22,
    0xc1, 0x42, 0xcb,
    0xc1, 0x42, 0xcb,
    0xc1, 0x42, 0xcb,
    0xc1, 0x42, 0xcb,
    0x01, 0xdb, 0xa1,
    0x01, 0xdb, 0xa1,
    0x01, 0xdb, 0xa1,
    0x01, 0xdb, 0xa1,
    0x0b, 0x95, 0x62,
    0x0b, 0x95, 0x62,
    0x0b, 0x95, 0x62,
    0x0b, 0x95, 0x62,
    0x4e, 0x6d, 0xcc,
    0x4e, 0x6d, 0xcc,
    0x4e, 0x6d, 0xcc,
    0x4e, 0x6d, 0xcc,
    0x65, 0xa3, 0xe8,
    0x65, 0xa3, 0xe8,
    0x65, 0xa3, 0xe8,
    0x65, 0xa3, 0xe8,
    0x42, 0x22, 0xba,
    0x42, 0x22, 0xba,
    0x42, 0x22, 0xba,
    0x42, 0x22, 0xba,
    0x06, 0xe8, 0xa7,
    0x06, 0xe8, 0xa7,
    0x06, 0xe8, 0xa7,
    0x06, 0xe8, 0xa7,
    0xed, 0x3a, 0xad,
    0xed, 0x3a, 0xad,
    0xed, 0x3a, 0xad,
    0xed, 0x3a, 0xad,
    0x17, 0x8a, 0x19,
    0x17, 0x8a, 0x19,
    0x17, 0x8a, 0x19,
    0x17, 0x8a, 0x19,
    0x1e, 0x12, 0x56,
    0x1e, 0x12, 0x56,
    0x1e, 0x12, 0x56,
    0x1e, 0x12, 0x56,
    0xbe, 0xf7, 0x90,
    0xbe, 0xf7, 0x90,
    0xbe, 0xf7, 0x90,
    0xbe, 0xf7, 0x90,
    0xc5, 0xf6, 0x7f,
    0xc5, 0xf6, 0x7f,
    0xc5, 0xf6, 0x7f,
    0xc5, 0xf6, 0x7f,
    0xd3, 0x8b, 0x06,
    0xd3, 0x8b, 0x06,
    0xd3, 0x8b, 0x06,
    0xd3, 0x8b, 0x06,
    0x68, 0xde, 0x1e,
    0x68, 0xde, 0x1e,
    0x68, 0xde, 0x1e,
    0x68, 0xde, 0x1e,
    0x18, 0xa5, 0xca,
    0x18, 0xa5, 0xca,
    0x18, 0xa5, 0xca,
    0x18, 0xa5, 0xca,
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
    0xE0, 0xE5, 0xEA, 0x00,
    0x10, 0x00, 0x00,
    0xAF, 0x4B, 0xCB, 0xDD,
};

//--------------------------------------------------
// Description  : ICM Setting
// Input Value  : None
// Output Value : None
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
// Description  : Contrast & Brightness Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_CON_BRI_SETTING[] =
{
    // Change CTS/BRI setting parameter    
    0xAA,0x55,0xAA,0x55,0xAA,0x55,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x44,0x88,0x44,0x88,0x44,0x88,
    0x3F,0x1F,0x00,0x42,0x00,0x85,0x00,0x42,0x00,0x41,0x00,0x20,0x00,0x41,
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
    0x01, 0x90, 0x00, 0x24, 0x01, 0x05, 0x1F, 0xAB,
    0x01, 0xFE, 0x01, 0xDF, 0x00, 0x55, 0x00, 0x55,
    0x00, 0x07, 0x01, 0xF3, 0x00, 0x25, 0x05, 0x00,
    0x00, 0x00,
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

#if((_SDRAM_SIZE_CONFIG == _1M_16BIT) || (_SDRAM_SIZE_CONFIG == _1M_32BIT) || (_SDRAM_SIZE_CONFIG == _2M_32BIT))
BYTE code tOD_QC_TABLE[] =
{
    0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x04,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
    0x09,0x05,0x00,0x01,0x00,0x02,0x06,0x03,0x06,0x06,0x06,0x03,0x06,0x06,0x06,0x06,0x06,
    0x0B,0x07,0x04,0x00,0x01,0x04,0x04,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x10,
    0x11,0x0F,0x09,0x04,0x00,0x03,0x06,0x05,0x0C,0x0C,0x0C,0x0C,0x0C,0x0F,0x13,0x19,0x1C,
    0x1B,0x14,0x0D,0x08,0x03,0x00,0x03,0x06,0x0D,0x0D,0x0D,0x10,0x12,0x17,0x1C,0x23,0x26,
	0x15,0x18,0x12,0x0D,0x08,0x04,0x00,0x03,0x08,0x0D,0x0F,0x12,0x17,0x1B,0x1E,0x2A,0x2C,
    0x17,0x1C,0x1B,0x14,0x0F,0x0A,0x05,0x00,0x04,0x08,0x0D,0x11,0x17,0x1D,0x1F,0x2A,0x32,
    0x1B,0x21,0x20,0x1E,0x16,0x12,0x0D,0x07,0x00,0x04,0x09,0x0F,0x15,0x1D,0x21,0x2B,0x34,
    0x1F,0x20,0x20,0x21,0x1B,0x1B,0x14,0x0E,0x08,0x00,0x06,0x0D,0x14,0x1E,0x22,0x2A,0x35,
    0x24,0x1F,0x1F,0x21,0x1E,0x1E,0x1B,0x15,0x0F,0x08,0x00,0x06,0x10,0x1B,0x22,0x2A,0x34,
    0x22,0x1A,0x1B,0x20,0x21,0x1F,0x1B,0x18,0x12,0x0F,0x08,0x00,0x09,0x17,0x21,0x29,0x30,	
    0x1A,0x18,0x19,0x1E,0x20,0x20,0x1E,0x19,0x15,0x10,0x0D,0x08,0x00,0x0D,0x1F,0x24,0x2C,
    0x16,0x16,0x15,0x16,0x16,0x16,0x17,0x16,0x16,0x14,0x12,0x0D,0x09,0x00,0x0D,0x1C,0x23,
    0x13,0x10,0x12,0x11,0x12,0x12,0x12,0x12,0x11,0x11,0x10,0x0D,0x0A,0x09,0x00,0x10,0x1A,
    0x11,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0A,0x0B,0x0B,0x0B,0x0A,0x09,0x08,0x00,0x0F,
    0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x00,				   
};
#endif // #if((_SDRAM_SIZE_CONFIG == _1M_16BIT) || (_SDRAM_SIZE_CONFIG == _1M_32BIT)||(_SDRAM_SIZE_CONFIG == _2M_32BIT))

//--------------------------------------------------
// Description  : Scale Down Mode CRC Table
// Input Value  : None
// Output Value : None
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
// Description  : APD setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tADJPIXDET_SETTING[] =
{
    //******  D-domain PG.  ************
    4,  _NON_AUTOINC,               0x9f,                   0x07,    
    14, _AUTOINC,                   0xf0,                   0x04, 0x04, 0xe0, 0x01, 0x03, 0x02, 0x10,  0x10, 0x01, 0x01, 0x00,
    4,  _NON_AUTOINC,               0xf0,                   0x84,

    //******  Display format, 1920x24  ************   
    4,  _NON_AUTOINC,               0x2A,                   0x00,
    10, _NON_AUTOINC,               0x2B,                   0x07, 0xD0, 0x05, 0x00, 0x14, 0x00, 0x14,
    4,  _NON_AUTOINC,               0x2A,                   0x07,
    10, _NON_AUTOINC,               0x2B,                   0x07, 0x94, 0x07, 0x94, 0x00, 0x30, 0x03,
    4,  _NON_AUTOINC,               0x2A,                   0x0e,
    11, _NON_AUTOINC,               0x2B,                   0x00, 0x0a, 0x00, 0x0a, 0x00, 0x22, 0x00, 0x22,
    //4,  _NON_AUTOINC,               0x2A,                   0xc0,

    //******  all digital func disable   ************
    4,  _NON_AUTOINC,               0x89,                   0x00, //i-dither
    4,  _NON_AUTOINC,               0x6a,                   0x00, //D-dither

    4,  _NON_AUTOINC,               0x28,                   0x8f,
    4,  _NON_AUTOINC,               0x28,                   0x87,

    //******  APD  ************
    4,  _NON_AUTOINC,               0x9f,                   0x15,
    11,  _AUTOINC,                  0xD0,                   0xc4,0x20, 0x0c, 0x20, 0x00, 0x01,0x00,0x00,

    _END

};



//--------------------------------------------------
// Description  : APD setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tADJPIXDET_SETTING2[] =
{
    //******  D-domain PG.  ************
    4,  _NON_AUTOINC,               0x9f,                   0x07,    
    14, _AUTOINC,                   0xf0,                   0x04, 0x04, 0x0e, 0x01, 0x03, 0x02, 0x10,  0x10, 0x01, 0x01, 0x00,
    4,  _NON_AUTOINC,               0xf0,                   0x84,

    //******  Display format, 1920x24  ************   
    4,  _NON_AUTOINC,               0x2A,                   0x00,
    10, _NON_AUTOINC,               0x2B,                   0x07, 0xD0, 0x05, 0x00, 0x14, 0x00, 0x14,
    4,  _NON_AUTOINC,               0x2A,                   0x07,
    10, _NON_AUTOINC,               0x2B,                   0x07, 0x94, 0x07, 0x94, 0x00, 0x30, 0x03,
    4,  _NON_AUTOINC,               0x2A,                   0x0e,
    11, _NON_AUTOINC,               0x2B,                   0x00, 0x0a, 0x00, 0x0a, 0x00, 0x22, 0x00, 0x22,
    //4,  _NON_AUTOINC,               0x2A,                   0xc0,

    //******  all digital func disable   ************
    4,  _NON_AUTOINC,               0x89,                   0x00, //i-dither
    4,  _NON_AUTOINC,               0x6a,                   0x00, //D-dither

    4,  _NON_AUTOINC,               0x28,                   0x8f,
    4,  _NON_AUTOINC,               0x28,                   0x87,

    //******  APD  ************
    4,  _NON_AUTOINC,               0x9f,                   0x15,
    11,  _AUTOINC,                  0xD0,                   0xc4,0x20, 0x0c, 0x20, 0x00, 0x01,0x00,0x00,

    _END

};

#if(_LVDS_EO_CLK_MERGE == _DISABLE)
/*
//----------------------------------------------------------------------------------------------------
// mLVDS_6x Tables 
//----------------------------------------------------------------------------------------------------
BYTE code tQC_MLVDS6X[] =
{
    // pin share
    5,	_AUTOINC,	    0x8B,	0xA0, 0xFA,     // power-on lvds e/o //reset WD

    // Display PLL 
    // M N just useful for SD test , ICD simulation is depand upon "PERD_DPLL"
    // M=54+2=56, N=0+2=2
    // dpll: 14.318*56/2/2 = 200 MHz(FT even/odd pattern)
    // dclk: (single port) = 200/2 = 100 Mhz(FT even/odd pattern)

    //150MHz
    4,	_AUTOINC,	    0x9F,	0x01,

    4,	_AUTOINC,	    0xBF,	0x24, //M=54+2  // M= 54+2 test_cycle=2200~2295     
    4,	_AUTOINC,	    0xC0,	0x00, //N=0+2 div2  // N= 0+2  div 2
    4,	_AUTOINC,	    0xC1,	0x71,   // Icp = 7.4 ,Icp = 2.5+5                 
    4,	_AUTOINC,	    0xC2,	0x19,   // power down dpll
    4,	_AUTOINC,	    0xC2,	0x18,     // Power on DPLL

    // ----------- calibration start ------------------
    //--NO REPLACE--//  CC 00 10
    4,	_AUTOINC,	    0xC3,	0x85, 	// CMP enable	// 1000us -> 200us
    //--NO REPLACE--//  CC 00 09
    4,	_AUTOINC,	    0xC3,	0x8D, 	// latchca libration	// 1100us -> 201us
    //--NO REPLACE--//  CC 00 09
    4,	_AUTOINC,	    0xC3,	0x9D, 	// calibration valid	// 1200us -> 202us
    //--NO REPLACE--//  CC 00 09
    // ----------- calibration end ------------------



    5,	_AUTOINC,	    0x28,	0x23, 0x00, // NO frame sync, eo no swap
                

    // display format
    4,	_AUTOINC,	    0x28,	0x08,	// frame sync
    4,	_AUTOINC,	    0x2A,	0x00,
    5,	_NON_AUTOINC,	0x2B,	0x05, 0x8C,	// total disp hori. pixels
    5,	_AUTOINC,	    0x2A,	0x02, 0x14, // hs end
    4,	_AUTOINC,	    0x2A,	0x03,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x22,	// hori bkg start 
    4,	_AUTOINC,	    0x2A,	0x05,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x22,	// hori act start
    4,	_AUTOINC,	    0x2A,	0x07,
    5,	_NON_AUTOINC,	0x2B,	0x05, 0x7A,	// hori act end 	
    4,	_AUTOINC,	    0x2A,	0x09,
    5,	_NON_AUTOINC,	0x2B,	0x05, 0x7A,	// hori bkg end		
    4,	_AUTOINC,	    0x2A,	0x0B,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x1B,	// vert. total
    5,	_AUTOINC,	    0x2A,	0x0D, 0x02, // vs end
    4,	_AUTOINC,	    0x2A,	0x0E,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x02,	// vert bkg start
    4,	_AUTOINC,	    0x2A,	0x10,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x02,	// vert act start
    4,	_AUTOINC,	    0x2A,	0x12,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x1A,	// vert act end		
    4,	_AUTOINC,	    0x2A,	0x14,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x1A,	// vert bkg end	
    5,	_AUTOINC,	    0x2A,	0x20, 0x03, //<cchild_debug> Dclk polarity inv disable    8825~8920

    4,	_AUTOINC,	    0x40,	0x00,	// ivs to dvs

    // fixed last line for free-run mode
    4,	_AUTOINC,	    0x9F,	0x01,
    7,	_AUTOINC,	    0xC7,	0x50, 0x1C, 0x8C, 0x02,


    4,	_AUTOINC,	    0x28,	0x87,    // free-run mode, force-to-background, single output, force enable
    4,	_AUTOINC,	    0x29,	0x00,



    //**************************************************************991130 start
    5,	_AUTOINC,	    0x8B,	0x00, 0x01,  // lvds mode
    4,	_AUTOINC,       0x9F,   0x07,
    14,	_AUTOINC,       0xF0,   0x85, 0x05, 0x05, 0x00, 0x04, 0x08, 0x01, 0x01, 0x01, 0x01, 0x00,
    
    5,	_AUTOINC,       0x8B,   0x00, 0x03,
    5,	_AUTOINC,       0x8B,   0xA0, 0x7A,
    5,	_AUTOINC,       0x8B,   0x01, 0x00,
    5,	_AUTOINC,       0x8B,   0x02, 0x00,
    5,	_AUTOINC,       0x8B,   0x03, 0x00,
    5,	_AUTOINC,       0x8B,   0x04, 0x02,
    5,	_AUTOINC,       0x8B,   0x05, 0x00,
    5,	_AUTOINC,       0x8B,   0x06, 0x2D,
    5,	_AUTOINC,       0x8B,   0x07, 0x28,
    5,	_AUTOINC,       0x8B,   0x09, 0xB8,
    5,	_AUTOINC,       0x8B,   0x0A, 0xBE,
    5,	_AUTOINC,       0x8B,   0x26, 0x73,
    5,	_AUTOINC,       0x8B,   0x0F, 0x00,
    5,	_AUTOINC,       0x8B,   0x10, 0x71,
    5,	_AUTOINC,       0x8B,   0x11, 0x49,
    5,	_AUTOINC,       0x8B,   0x12, 0xE0,
    5,	_AUTOINC,       0x8B,   0x13, 0x00,
    5,	_AUTOINC,       0x8B,   0x14, 0x00,
    5,	_AUTOINC,       0x8B,   0x15, 0x30,
    5,	_AUTOINC,       0x8B,   0x16, 0x00,
    5,	_AUTOINC,       0x8B,   0x17, 0x30,
    5,	_AUTOINC,       0x8B,   0x18, 0x00,
    5,	_AUTOINC,       0x8B,   0x19, 0x00,
    5,	_AUTOINC,       0x8B,   0x1A, 0x00,
    5,	_AUTOINC,       0x8B,   0x1D, 0x30,
    5,	_AUTOINC,       0x8B,   0x1E, 0xCC,
    5,	_AUTOINC,       0x8B,   0x20, 0x10,
    5,	_AUTOINC,       0x8B,   0x21, 0x80,
    5,	_AUTOINC,       0x8B,   0x22, 0x00,
    5,	_AUTOINC,       0x8B,   0x23, 0xFF,
    5,	_AUTOINC,       0x8B,   0x24, 0x00,
    5,	_AUTOINC,       0x8B,   0x25, 0x00,
    5,	_AUTOINC,       0x8B,   0x27, 0x0F,
    5,	_AUTOINC,       0x8B,   0x28, 0x3F,
    5,	_AUTOINC,       0x8B,   0x29, 0xFF,
    5,	_AUTOINC,       0x8B,   0x2A, 0x00,
    5,	_AUTOINC,       0x8B,   0xA0, 0xFA,
    5,	_AUTOINC,       0x8B,   0xA1, 0x14,
    5,	_AUTOINC,       0x8B,   0xA2, 0x13,
    5,	_AUTOINC,       0x8B,   0xA3, 0x00,
    5,	_AUTOINC,       0x8B,   0xA4, 0x80,
    5,	_AUTOINC,       0x8B,   0xA5, 0x80,
    5,	_AUTOINC,       0x8B,   0xA6, 0x01,
    5,	_AUTOINC,       0x8B,   0xA9, 0x00,


    4,	_AUTOINC,       0x9F,   0x15,
    4,	_AUTOINC,       0xA1,   0x50,
    5,	_AUTOINC,       0xA3,   0x68, 0x00,
    5,	_AUTOINC,       0xA3,   0x69, 0x00,
    5,	_AUTOINC,       0xA3,   0x6A, 0x24,
    5,	_AUTOINC,       0xA3,   0x6B, 0x00,
    5,	_AUTOINC,       0xA3,   0x6C, 0x05,
    5,	_AUTOINC,       0xA3,   0x6D, 0x8C,
    5,	_AUTOINC,       0xA3,   0x6E, 0x80,
    
    //TP1
    5,	_AUTOINC,       0xA3,   0x38, 0x02,
    5,	_AUTOINC,       0xA3,   0x39, 0x00,
    5,	_AUTOINC,       0xA3,   0x3A, 0x1A,
    5,	_AUTOINC,       0xA3,   0x3B, 0xAA,
    5,	_AUTOINC,       0xA3,   0x3C, 0x22,
    5,	_AUTOINC,       0xA3,   0x3D, 0xB0,   
    5,	_AUTOINC,       0xA3,   0x3E, 0x80,
    
    //VSYNC
    5,	_AUTOINC,       0xA3,   0x60, 0x00,
    5,	_AUTOINC,       0xA3,   0x61, 0x00,
    5,	_AUTOINC,       0xA3,   0x62, 0x01,
    5,	_AUTOINC,       0xA3,   0x63, 0x0A,
    5,	_AUTOINC,       0xA3,   0x64, 0x00,
    5,	_AUTOINC,       0xA3,   0x65, 0x14,
    5,	_AUTOINC,       0xA3,   0x66, 0x80,

    // Pingshare setting
    4,  _AUTOINC,                   0x9F,                   0x10,
    4,  _AUTOINC,                   0xDA,                   0x05,           // pin63 -> pin65  (TCON1)
    4,  _AUTOINC,                   0xE1,                   0x05,           // pin64 -> pin72  (TCON6)
        
    //**************************************************************991130 end
    // Start CRC
    4,	_AUTOINC,	    0x2C,	0x81,
    4,	_AUTOINC,	    0x9F,	0x15,
    4,	_AUTOINC,	    0xB0,	0x10, //Start LVDS CRC

    _END 
};
*/

//----------------------------------------------------------------------------------------------------
// mLVDS_7x Tables
//----------------------------------------------------------------------------------------------------
BYTE code tQC_MLVDS7X[] =
{ 
    // RL6229 lvds_ft even 75MHz pattern
     
    // pin share
    5,  _AUTOINC,                   0x8B,                   0xA0, 0xFA,     // power-on lvds e/o //reset WD
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

    5,  _AUTOINC,                   0x28,                   0x23, 0x00,      // NO frame sync, eo no swap

    // display format
    4,  _AUTOINC,                   0x28,                   0x08,           // frame sync
    4,  _AUTOINC,                   0x2A,                   0x00,
    5,  _NON_AUTOINC,               0x2B,                   0x05, 0x8C,      // total disp hori. pixels
    5,  _AUTOINC,                   0x2A,                   0x02, 0x14,     // hs end
    4,  _AUTOINC,                   0x2A,                   0x03,
    5,  _NON_AUTOINC,               0x2B,                   0x00, 0x22,      // hori bkg start 
    4,  _AUTOINC,                   0x2A,                   0x05,
    5,  _NON_AUTOINC,               0x2B,                   0x00, 0x22,      // hori act start
    4,  _AUTOINC,                   0x2A,                   0x07,
    5,  _NON_AUTOINC,               0x2B,                   0x05, 0x7A,      // hori act end 
    4,  _AUTOINC,                   0x2A,                   0x09,
    5,  _NON_AUTOINC,               0x2B,                   0x05, 0x7A,      // hori bkg end 
    4,  _AUTOINC,                   0x2A,                   0x0B,
    5,  _NON_AUTOINC,               0x2B,                   0x00, 0x1B,      // vert. total
    5,  _AUTOINC,                   0x2A,                   0x0D, 0x02,      // vs end
    4,  _AUTOINC,                   0x2A,                   0x0E,
    5,  _NON_AUTOINC,               0x2B,                   0x00, 0x02,      // vert bkg start
    4,  _AUTOINC,                   0x2A,                   0x10,
    5,  _NON_AUTOINC,               0x2B,                   0x00, 0x02,      // vert act start
    4,  _AUTOINC,                   0x2A,                   0x12,
    5,  _NON_AUTOINC,               0x2B,                   0x00, 0x1A,      // vert act end 
    4,  _AUTOINC,                   0x2A,                   0x14,
    5,  _NON_AUTOINC,               0x2B,                   0x00, 0x1A,      // vert bkg end 
    5,  _AUTOINC,                   0x2A,                   0x20, 0x03,      //<cchild_debug> Dclk polarity inv disable    8825~8920

    4,  _AUTOINC,                   0x40,                   0x00,           // ivs to dvs

    // fixed last line for free-run mode
    4,  _AUTOINC,                   0x9F,                   0x01,
    7,  _AUTOINC,                   0xC7,                   0x50, 0x1C, 0x8C, 0x02,

    4,  _AUTOINC,                   0x28,                   0x87,           // free-run mode, force-to-background, single output, force enable
    4,  _AUTOINC,                   0x29,                   0x00,

    //**************************************************************
    5,  _AUTOINC,                   0x8B,                   0x00, 0x01,      // lvds mode
    4,  _AUTOINC,                   0x9F,                   0x07,
    14, _AUTOINC,                   0xF0,                   0x85, 0x05, 0x05, 0x00, 0x04, 0x08, 0x01, 0x01, 0x01, 0x01, 0x00,

    // LVDS setting
    5,  _AUTOINC,                   0x8B,                   0x00, 0x03,
    5,  _AUTOINC,                   0x8B,                   0xA0, 0x7A,
    5,  _AUTOINC,                   0x8B,                   0x01, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x02, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x03, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x04, 0x56,
    5,  _AUTOINC,                   0x8B,                   0x05, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x06, 0x36,
    5,  _AUTOINC,                   0x8B,                   0x07, 0x30,
    5,  _AUTOINC,                   0x8B,                   0x09, 0xB8,
    5,  _AUTOINC,                   0x8B,                   0x0A, 0xBE,
    5,  _AUTOINC,                   0x8B,                   0x26, 0xBB,
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
    5,  _AUTOINC,                   0x8B,                   0x1D, 0x33,
    5,  _AUTOINC,                   0x8B,                   0x1E, 0x66,
    5,  _AUTOINC,                   0x8B,                   0x20, 0x10,
    5,  _AUTOINC,                   0x8B,                   0x21, 0x80,
    5,  _AUTOINC,                   0x8B,                   0x22, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x23, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x24, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x25, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x27, 0x0F,
    5,  _AUTOINC,                   0x8B,                   0x28, 0x3F,
    5,  _AUTOINC,                   0x8B,                   0x29, 0xFF,
    5,  _AUTOINC,                   0x8B,                   0x2A, 0x00,
    5,  _AUTOINC,                   0x8B,                   0xA0, 0xFA,
    5,  _AUTOINC,                   0x8B,                   0xA1, 0x14,
    5,  _AUTOINC,                   0x8B,                   0xA2, 0x13,
    5,  _AUTOINC,                   0x8B,                   0xA3, 0x00,
    5,  _AUTOINC,                   0x8B,                   0xA4, 0x80,
    5,  _AUTOINC,                   0x8B,                   0xA5, 0x80,
    5,  _AUTOINC,                   0x8B,                   0xA6, 0x01,
    5,  _AUTOINC,                   0x8B,                   0xA9, 0x00,
   
    // TCON setting
    4,  _AUTOINC,                   0x9F,                   0x15,
    4,  _AUTOINC,                   0xA1,                   0x50,
    5,  _AUTOINC,                   0xA3,                   0x68, 0x00,
    5,  _AUTOINC,                   0xA3,                   0x69, 0x00,
    5,  _AUTOINC,                   0xA3,                   0x6A, 0x24,
    5,  _AUTOINC,                   0xA3,                   0x6B, 0x00,
    5,  _AUTOINC,                   0xA3,                   0x6C, 0x05,
    5,  _AUTOINC,                   0xA3,                   0x6D, 0x8C,
    5,  _AUTOINC,                   0xA3,                   0x6E, 0x80,
    
    // TP1
    5,  _AUTOINC,                   0xA3,                   0x38, 0x02,
    5,  _AUTOINC,                   0xA3,                   0x39, 0x00,
    5,  _AUTOINC,                   0xA3,                   0x3A, 0x1A,
    5,  _AUTOINC,                   0xA3,                   0x3B, 0xAA,
    5,  _AUTOINC,                   0xA3,                   0x3C, 0x22,
    5,  _AUTOINC,                   0xA3,                   0x3D, 0xB0,
    5,  _AUTOINC,                   0xA3,                   0x3E, 0x80,
    
    // VSYNC
    5,  _AUTOINC,                   0xA3,                   0x60, 0x00,
    5,  _AUTOINC,                   0xA3,                   0x61, 0x00,
    5,  _AUTOINC,                   0xA3,                   0x62, 0x01,
    5,  _AUTOINC,                   0xA3,                   0x63, 0x0A,
    5,  _AUTOINC,                   0xA3,                   0x64, 0x00,
    5,  _AUTOINC,                   0xA3,                   0x65, 0x14,
    5,  _AUTOINC,                   0xA3,                   0x66, 0x80,

    // Pingshare setting
    4,  _AUTOINC,                   0x9F,                   0x10,
    4,  _AUTOINC,                   0xDA,                   0x05,           // pin63 -> pin65  (TCON1)
    4,  _AUTOINC,                   0xE1,                   0x05,           // pin64 -> pin72  (TCON6)

    // Start CRC
    4,  _AUTOINC,                   0x2C,                   0x81,
    4,  _AUTOINC,                   0x9F,                   0x15,
    4,  _AUTOINC,                   0xB0,                   0x10,           //Start LVDS CRC
  
    _END
 	
};

/*
//----------------------------------------------------------------------------------------------------
// mLVDS_8x Tables         
//----------------------------------------------------------------------------------------------------
BYTE code tQC_MLVDS8X[] =
{
    // pin share
    5,	_AUTOINC,	0x8B,	0xA0, 0xFA,     // power-on lvds e/o //reset WD

    // Display PLL 
    // M N just useful for SD test , ICD simulation is depand upon "PERD_DPLL"
    // M=54+2=56, N=0+2=2
    // dpll: 14.318*56/2/2 = 200 MHz(FT even/odd pattern)
    // dclk: (single port) = 200/2 = 100 Mhz(FT even/odd pattern)

    //150MHz
    4,	_AUTOINC,	0x9F,	0x01,
    4,  _AUTOINC,   0xBF,   0x1A, //M=54+2  // M= 54+2 test_cycle=2200~2295         
    4,  _AUTOINC,   0xC0,   0x00, //N=0+2 div2  // N= 0+2  div 2
    4,  _AUTOINC,   0xC1,   0x70,   // Icp = 7.4 ,Icp = 2.5+5                       
    4,	_AUTOINC,	0xC2,	0x19,   // power down dpll

    4,	_AUTOINC,	0xC2,	0x18,     // Power on DPLL

    // ----------- calibration start ------------------
    //--NO REPLACE--//  CC 00 10
    4,	_AUTOINC,	0xC3,	0x85, 	// CMP enable	// 1000us -> 200us
    //--NO REPLACE--//  CC 00 09
    4,	_AUTOINC,	0xC3,	0x8D, 	// latchca libration	// 1100us -> 201us
    //--NO REPLACE--//  CC 00 09
    4,	_AUTOINC,	0xC3,	0x9D, 	// calibration valid	// 1200us -> 202us
    //--NO REPLACE--//  CC 00 09
    // ----------- calibration end ------------------



    5,	_AUTOINC,	    0x28,	0x23, 0x00, // NO frame sync, eo no swap
                

    // display format
    4,	_AUTOINC,	    0x28,	0x08,	// frame sync
    4,	_AUTOINC,	    0x2A,	0x00,
    5,	_NON_AUTOINC,	0x2B,	0x05, 0x8C,	// total disp hori. pixels
    5,	_AUTOINC,	    0x2A,	0x02, 0x14,	// hs end
    4,	_AUTOINC,	    0x2A,	0x03,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x22,	// hori bkg start 
    4,	_AUTOINC,	    0x2A,	0x05,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x22,	// hori act start
    4,	_AUTOINC,	    0x2A,	0x07,
    5,	_NON_AUTOINC,	0x2B,	0x05, 0x7A,	// hori act end 	
    4,	_AUTOINC,	    0x2A,	0x09,
    5,	_NON_AUTOINC,	0x2B,	0x05, 0x7A,	// hori bkg end		
    4,	_AUTOINC,	    0x2A,	0x0B,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x1B,	// vert. total
    5,	_AUTOINC,	    0x2A,	0x0D, 0x02,	// vs end
    4,	_AUTOINC,	    0x2A,	0x0E,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x02,	// vert bkg start
    4,	_AUTOINC,	    0x2A,	0x10,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x02,	// vert act start
    4,	_AUTOINC,	    0x2A,	0x12,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x1A,	// vert act end		
    4,	_AUTOINC,	    0x2A,	0x14,
    5,	_NON_AUTOINC,	0x2B,	0x00, 0x1A,	// vert bkg end	
    5,	_AUTOINC,	    0x2A,	0x20, 0x03, //<cchild_debug> Dclk polarity inv disable    8825~8920


    4,	_AUTOINC,	0x40,	0x00,	// ivs to dvs

    // fixed last line for free-run mode
    4,	_AUTOINC,	0x9F,	0x01,
    7,	_AUTOINC,	0xC7,	0x50, 0x1C, 0x8C, 0x02,

    4,	_AUTOINC,	0x28,	0x87,    // free-run mode, force-to-background, single output, force enable
    4,	_AUTOINC,	0x29,	0x00,


       //**************************************************************
    5,	_AUTOINC,	0x8B,	0x00,0x01,  // lvds mode
    4,	_AUTOINC,   0x9F,   0x07,
    14,	_AUTOINC,   0xF0,   0x85, 0x05, 0x05, 0x00, 0x04, 0x08, 0x01, 0x01, 0x01, 0x01, 0x00,
    	
    5,	_AUTOINC,   0x8B,   0x00, 0x03,
    5,	_AUTOINC,   0x8B,   0xA0, 0x7A,
    5,	_AUTOINC,   0x8B,   0x01, 0x00,
    5,	_AUTOINC,   0x8B,   0x02, 0x00,
    5,	_AUTOINC,   0x8B,   0x03, 0x00,
    5,	_AUTOINC,   0x8B,   0x04, 0x02,
    5,	_AUTOINC,   0x8B,   0x05, 0x00,
    5,	_AUTOINC,   0x8B,   0x06, 0x2D,
    5,	_AUTOINC,   0x8B,   0x07, 0x28,
    5,	_AUTOINC,   0x8B,   0x09, 0xB8,
    5,	_AUTOINC,   0x8B,   0x0A, 0xBE,
    5,	_AUTOINC,   0x8B,   0x26, 0x3B,
    5,	_AUTOINC,   0x8B,   0x0F, 0xC6,
    5,	_AUTOINC,   0x8B,   0x10, 0x71,
    5,	_AUTOINC,   0x8B,   0x11, 0x49,
    5,	_AUTOINC,   0x8B,   0x12, 0xE0,
    5,	_AUTOINC,   0x8B,   0x13, 0x00,
    5,	_AUTOINC,   0x8B,   0x14, 0x00,
    5,	_AUTOINC,   0x8B,   0x15, 0x30,
    5,	_AUTOINC,   0x8B,   0x16, 0x00,
    5,	_AUTOINC,   0x8B,   0x17, 0x30,
    5,	_AUTOINC,   0x8B,   0x18, 0x00,
    5,	_AUTOINC,   0x8B,   0x19, 0x00,
    5,	_AUTOINC,   0x8B,   0x1A, 0x00,
    5,	_AUTOINC,   0x8B,   0x1D, 0x33,
    5,	_AUTOINC,   0x8B,   0x1E, 0x00,
    5,	_AUTOINC,   0x8B,   0x20, 0x10,
    5,	_AUTOINC,   0x8B,   0x21, 0x80,
    5,	_AUTOINC,   0x8B,   0x22, 0x00,
    5,	_AUTOINC,   0x8B,   0x23, 0xFF,
    5,	_AUTOINC,   0x8B,   0x24, 0x00,
    5,	_AUTOINC,   0x8B,   0x25, 0x00,
    5,	_AUTOINC,   0x8B,   0x27, 0x0F,
    5,	_AUTOINC,   0x8B,   0x28, 0x3F,
    5,	_AUTOINC,   0x8B,   0x29, 0xFF,
    5,	_AUTOINC,   0x8B,   0x2A, 0x00,
    5,	_AUTOINC,   0x8B,   0xA0, 0xFA,
    5,	_AUTOINC,   0x8B,   0xA1, 0x14,
    5,	_AUTOINC,   0x8B,   0xA2, 0x13,
    5,	_AUTOINC,   0x8B,   0xA3, 0x00,
    5,	_AUTOINC,   0x8B,   0xA4, 0x80,
    5,	_AUTOINC,   0x8B,   0xA5, 0x80,
    5,	_AUTOINC,   0x8B,   0xA6, 0x01,
    5,	_AUTOINC,   0x8B,   0xA9, 0x00,


    4,	_AUTOINC,   0x9F,   0x15,
    4,	_AUTOINC,   0xA1,   0x50,
    5,	_AUTOINC,   0xA3,   0x68, 0x00,
    5,	_AUTOINC,   0xA3,   0x69, 0x00,
    5,	_AUTOINC,   0xA3,   0x6A, 0x24,
    5,	_AUTOINC,   0xA3,   0x6B, 0x00,
    5,	_AUTOINC,   0xA3,   0x6C, 0x05,
    5,	_AUTOINC,   0xA3,   0x6D, 0x8C,
    5,	_AUTOINC,   0xA3,   0x6E, 0x80,
    
    //TP1
    5,	_AUTOINC,   0xA3,   0x38, 0x02,
    5,	_AUTOINC,   0xA3,   0x39, 0x00,
    5,	_AUTOINC,   0xA3,   0x3A, 0x1A,
    5,	_AUTOINC,   0xA3,   0x3B, 0xAA,
    5,	_AUTOINC,   0xA3,   0x3C, 0x22,
    5,	_AUTOINC,   0xA3,   0x3D, 0xB0,
    5,	_AUTOINC,   0xA3,   0x3E, 0x80,

    //VSYNC
    5,	_AUTOINC,   0xA3,   0x60, 0x00,
    5,	_AUTOINC,   0xA3,   0x61, 0x00,
    5,	_AUTOINC,   0xA3,   0x62, 0x01,
    5,	_AUTOINC,   0xA3,   0x63, 0x0A,
    5,	_AUTOINC,   0xA3,   0x64, 0x00,
    5,	_AUTOINC,   0xA3,   0x65, 0x14,
    5,	_AUTOINC,   0xA3,   0x66, 0x80,


    // Pingshare setting
    4,  _AUTOINC,                   0x9F,                   0x10,
    4,  _AUTOINC,                   0xDA,                   0x05,           // pin63 -> pin65  (TCON1)
    4,  _AUTOINC,                   0xE1,                   0x05,           // pin64 -> pin72  (TCON6)


    //**************************************************************

    // Start CRC
    4,	_AUTOINC,	0x2C,	0x81,
    4,	_AUTOINC,	0x9F,	0x15,
    4,	_AUTOINC,	0xB0,	0x10, //Start LVDS CRC

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

BYTE code tQC_MLVDS7X[] =
{
   // RL6229 lvds_ft even 75MHz pattern
     
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
    5,  _AUTOINC,                   0x8B,                   0x04, 0xBE, // Jeyu
    5,  _AUTOINC,                   0x8B,                   0x05, 0x00,
    5,  _AUTOINC,                   0x8B,                   0x06, 0x37, // Jeyu
    5,  _AUTOINC,                   0x8B,                   0x07, 0x38, // Jeyu
    //5,  _AUTOINC,                   0x8B,                   0x09, 0xB8,
    //5,  _AUTOINC,                   0x8B,                   0x0A, 0xBE,
    //5,  _AUTOINC,                   0x8B,                   0x26, 0xBB,
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
    //5,  _AUTOINC,                   0x8B,                   0x1D, 0x33,
    //5,  _AUTOINC,                   0x8B,                   0x1E, 0x66,
    //5,  _AUTOINC,                   0x8B,                   0x20, 0x10,
    //5,  _AUTOINC,                   0x8B,                   0x21, 0x80,
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
#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
BYTE g_ucSdrCasLatnQC = _SDR_CAS_LATN;
BYTE g_ucSdrClkDly1QC = _SDR_CLK_DLY1;
BYTE g_ucSdrClkDly2QC = _SDR_CLK_DLY2;
BYTE g_ucDqsFineDlyQC = _SDR_DQS_DLY;
BYTE g_ucConflictAreaQC = _DEFAULT_CONFLICT_AREA;
StructSDRAMCalControl g_stSDRAMCtrl = {0};
#endif

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
bit ScalerQCIDLCTITest(void);
bit ScalerQCSuperResolutionTest(void);
bit ScalerQCYpeakingVCTITest(void);
bit ScalerQCADCHTest(void);

#if((_SDRAM_SIZE_CONFIG == _1M_32BIT) || (_SDRAM_SIZE_CONFIG == _2M_32BIT))
void ScalerQCFRCDither(void);
void ScalerQCFRCRecoverSetting(void);
bit ScalerQCFRCTest(void);
#endif

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
bit ScalerQCDDitherTest(void);
void ScalerQCODDDomainPattern1(void); 
void ScalerQCODDDomainPattern2(void);
bit ScalerQCLiveshowTest(void);
bit ScalerQCDisplayConversionTest(void);

void ScalerQCVgipMaskActiveSpace(EnumVgipMaskActiveSpaceNum enumActiveSpaceNum, WORD usPosition, WORD usLength);
bit ScalerQCScaleDownTest(void);

bit ScalerQCAPDTest(void);
bit ScalerQCDisplayConversionTest(void);
bit ScalerQCIDomainYUVtoRGBTest(void);
bit ScalerQCTwoThreeDimensionTest(void);
bit ScalerQCDepthOfFieldTest(void);
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

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)

void ScalerQCSDRAMDelay200Us(void);
void ScalerQCSDRAMDelay1ms(void);
void ScalerQCSDRAMResetAcc(void);
void ScalerQCSDRAMClearFifo(void);
void ScalerQCSDRAMTokenPhaseSet(void);
void ScalerQCSDRAMWritePattern(void);
void ScalerQCSDRAMMpllSet(BYTE ucMCLK);
void ScalerQCSDRAMDefaultTokenRing(void);
void ScalerQCSDRAMDefaultPhase(void);
BYTE ScalerQCSDRAMPhaseCount(bit bDBBufferFlag);
bit ScalerQCSDRAMMCUMode(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL, bit bWriteMcuFlag);
bit ScalerQCSDRAMOnlineMCUMode(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL);
void ScalerQCSDRAMWrPatternOnce(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL);
DWORD ScalerQCSDRAMWritePhaseSearch(void);
void ScalerQCSDRAMReadPhaseSearch( BYTE ucHighDutyWidth, BYTE ucMclkCyle, BYTE ucWriteMove);
bit ScalerQCSDRAM1NsCheck(void);
bit ScalerQCSDRAMPhaseSearch(void);
bit ScalerQCSDRAMPhaseOnLine(DWORD ulAddress);
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

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ucResult = (ucResult | ((BYTE)ScalerQCSDRAMPhaseSearch() << 5));
#endif

    ucResult = (ucResult | ((BYTE)ScalerQCBistTest() << 7));                    // BIST Test
    ucResult = (ucResult | ScalerQCIDomainRandomGenTest());    	                // I Domain Random Generator Test
    ucResult = (ucResult | ScalerQC422to444Test());    	    	                // YUV 422 to 444 Test
    ucResult = (ucResult | ScalerQCIDomainYUVtoRGBTest());                      // I Domain YUVtoRGB Test    
    ucResult = (ucResult | ScalerQCDigitalFilterTest());    	                // Digital Filter Test
    ucResult = (ucResult | ScalerQCColorConversionTest());    	                // Color Conversion Test
    ucResult = (ucResult | ScalerQCTwoThreeDimensionTest());                    // 2Dto3D Test
    ucResult = (ucResult | ScalerQCDepthOfFieldTest());                         // Depth Of Field Test    

    ucResult = (ucResult | ScalerQCIDitherTest());    	    	                // I Dither Test
	ucResult = (ucResult | ScalerQCIDLCTITest());                               //I Domain DLCTI Test
    
#if((_SDRAM_SIZE_CONFIG == _1M_32BIT) || (_SDRAM_SIZE_CONFIG == _2M_32BIT))    
    ucResult = (ucResult | ((BYTE)ScalerQCFRCTest() << 2));    	                // FRC Test
#endif
    
	ucResult = (ucResult | ((BYTE)ScalerQCYpeakingVCTITest() << 1));            //VPK_VCTI Test
	ucResult = (ucResult | ((BYTE)ScalerQCSuperResolutionTest() << 1));			//Super Resolution Test        
    ucResult = (ucResult | ((BYTE)ScalerQCScaleUpTest() << 1));    	            // Scale Up Test
    ucResult = (ucResult | ((BYTE)ScalerQCHLWTest() << 1));                     // Highlight Window Test    
    ucResult = (ucResult | ((BYTE)ScalerQCDDomainPGTest() << 1));               // D Domain Pattern Generator Test
    ucResult = (ucResult | ((BYTE)ScalerQCDCRTest() << 1));    	                // DCR Test
    ucResult = (ucResult | ((BYTE)ScalerQCDCCTest() << 1));    	                // DCC Test
    ucResult = (ucResult | ((BYTE)ScalerQCICMTest() << 1));    	                // ICM Test
    ucResult = (ucResult | ((BYTE)ScalerQCCABCTest() << 1));    	            // CABC Test    
    ucResult = (ucResult | ((BYTE)ScalerQCConBriTest() << 1));    	            // Contrast & Brightness Test
    ucResult = (ucResult | ((BYTE)ScalerQCsRGBTest() << 1));    	            // sRGB Test        
    ucResult = (ucResult | ((BYTE)ScalerQCGammaTest() << 1));    	            // Output Gamma Test
    ucResult = (ucResult | ((BYTE)ScalerQCPCMTest() << 1));    	                // PCM tTest
    ucResult = (ucResult | ((BYTE)ScalerQCDDitherTest() << 3));    	            // D Ditehr Test
    ucResult = (ucResult | ((BYTE)ScalerQCDisplayConversionTest() << 1));
    ucResult = (ucResult | ((BYTE)ScalerQCOSDTest() << 3));    	                // OSD Test

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)    
    ucResult = (ucResult | ((BYTE)ScalerQCLiveshowTest() << 2));                // LiveShow(OD) Test
#endif    
    
    ucResult = (ucResult | ((BYTE)ScalerQCAPDTest() << 4));                     // Adjacent Pix distance(APD) Test    
         
#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ucResult = (ucResult | ((BYTE)ScalerQCSDRAMPhaseOnLine(0x00) << 5));

    if(GET_CAS_CHANGE_STATUS() == _TRUE)
    {
        ucResult = (ucResult | ((BYTE)ScalerQCSDRAMPhaseOnLine(0x00) << 5));
    }

#endif

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
/*
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
*/
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

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)    
    // Test OD SRAM
    ScalerSetBit(P3_AF_LS_BIST_CTRL, ~_BIT1, _BIT1);
    ScalerTimerDelayXms(10);
    
    if(ScalerGetBit(P3_AF_LS_BIST_CTRL, _BIT0) != _BIT0)
    {
        DebugMessageScaler("5. OD SRAM Bist Fail", 0x00);
        ucBistResult |= _BIT5;         
    }
    ScalerSetBit(P3_AF_LS_BIST_CTRL, ~_BIT1, 0x00);
#endif
    
    // Test SDRAM Controller
    // IN1 BIST Test
    ScalerSetBit(P5_A1_SDRF_IN1_FIFO_STATUS, ~_BIT5, _BIT5);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P5_A1_SDRF_IN1_FIFO_STATUS, _BIT7, 0x00) == _TRUE)
    {
        if(ScalerGetBit(P5_A1_SDRF_IN1_FIFO_STATUS, _BIT6) != _BIT6)
        {
            DebugMessageScaler("5. SDRAM IN1 Bist Fail", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    else
    {
        DebugMessageScaler("5. SDRAM IN1 Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }    
    ScalerSetBit(P5_A1_SDRF_IN1_FIFO_STATUS, ~_BIT5, 0x00);

    // MN BIST Test
    ScalerSetBit(P5_A2_SDRF_MAIN_FIFO_STATUS, ~_BIT5, _BIT5);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P5_A2_SDRF_MAIN_FIFO_STATUS, _BIT7, 0x00) == _TRUE)
    {
        if(ScalerGetBit(P5_A2_SDRF_MAIN_FIFO_STATUS, _BIT6) != _BIT6)
        {
            DebugMessageScaler("5. SDRAM MN Bist Fail", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    else
    {
        DebugMessageScaler("5. SDRAM MN Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }    
    ScalerSetBit(P5_A1_SDRF_IN1_FIFO_STATUS, ~_BIT5, 0x00);

    // SR BIST Test
    ScalerSetBit(P12_A1_SR_SHP_BIST_CTRL, ~_BIT3, _BIT3);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P12_A1_SR_SHP_BIST_CTRL, _BIT2, _BIT2) == _TRUE)
    {
        if(ScalerGetBit(P12_A1_SR_SHP_BIST_CTRL, _BIT1) != 0x00)
        {
            DebugMessageScaler("5. SR Bist Even Fail", 0x00);
            ucBistResult |= _BIT7;
        }
        
        if(ScalerGetBit(P12_A1_SR_SHP_BIST_CTRL, _BIT0) != 0x00)
        {
            DebugMessageScaler("5. SR Bist Odd Fail", 0x00);
            ucBistResult |= _BIT7;
        }        
    }
    else
    {
        DebugMessageScaler("5. SR Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT7;
    }    
    ScalerSetBit(P12_A1_SR_SHP_BIST_CTRL, ~_BIT3, 0x00);
    
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
    BYTE ucWaitType = _EVENT_DVS;
    
    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
    	    
    if(ucCRCSelect == _I_DOMAIN_CRC)
    {
        ucWaitType = _EVENT_IVS;

        ScalerSetByte(CM_8D_PS_ACCESS_PORT, 0x07);
        ScalerSetBit(CM_8E_PS_DATA_PORT, ~_BIT5, _BIT5);
        ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x01);     
    }
    else if(ucCRCSelect == _M_DOMAIN_CRC)
    {
        ucWaitType = _EVENT_DVS;        

        ScalerSetByte(CM_8D_PS_ACCESS_PORT, 0x07);
        ScalerSetBit(CM_8E_PS_DATA_PORT, ~_BIT5, _BIT5);
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
    ScalerSetByte(CM_96_M_DITHERING_CTRL1, 0x00);    // Disable M Domain Dither

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
    ScalerSetByte(P3_A1_LS_CTRL0, 0x00);    	    // Disable LiveShow

    //---------------------SDRAM--------------------//
    ScalerSetByte(CM_26_I_YUV444TO422, 0x00);    	// Disable FRC YUV444to422 
    ScalerSetByte(P5_CF_SDRF_MN_DISP_CTRL, 0x05);    // Disable FRC YUV422to444
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

    DebugMessageScaler("5. Digital Filter End", 0x00);    
    
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. Digital Filter PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
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

    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_IDITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

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
// Description  : I_DLCTI Test 
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCIDLCTITest(void)
{	
    BYTE ucData = 0;

    DebugMessageScaler("5. I_DLCTI Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerWrite(P11_A1_I_DLTI_CTRL_0,17, &tQC_IDLCTI_SETTING_1[0], _AUTOINC);    //IDLTI table1
    ScalerWrite(P11_B3_I_DCTI_CTRL,14, &tQC_IDLCTI_SETTING_1[17], _AUTOINC);   //IDCTI table1
    ScalerWrite(P11_D4_IDCLTI_HLW_HOR_START_H,14, &tQC_IDLCTI_HLW[0], _AUTOINC);        //IDCTI HLW table


    ScalerSetByte(P11_DC_IDCLTI_HLW_CTRL, 0x00);          //disable HLW

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    //0. IDomainRandomGen(_MASS) + IDither(_MSB) + Setting1 + I_Domain_CRC 	
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_0", 0x00);  	
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x6A, 0x03, 0x00, _I_DOMAIN_CRC) << 0));

    //1. IDomainRandomGen(_MASS) + IDither(_MSB) + Setting1 + I_Domain_CRC + HLW(in)	
    ScalerSetByte(P11_DC_IDCLTI_HLW_CTRL,0x02);      //enable HLW(inside)
    DebugMessageScaler("5. Mode_1", 0x00);	
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x56, 0x76, 0x42, _I_DOMAIN_CRC) << 1));

    ScalerWrite(P11_A1_I_DLTI_CTRL_0,17, &tQC_IDLCTI_SETTING_2[0],_AUTOINC);    //IDLTI table2
    ScalerWrite(P11_B3_I_DCTI_CTRL,14, &tQC_IDLCTI_SETTING_2[17],_AUTOINC);   //IDCTI table2

    //2. IDomainRandomGen(_MASS) + IDither(_LSB) + Setting2 + I_Domain_CRC
    ScalerQCIDitherOn(_LSB);
    ScalerSetByte(P11_DC_IDCLTI_HLW_CTRL, 0x00); 
    DebugMessageScaler("5. Mode_2", 0x00);  	
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x02, 0x5B, 0x35, _I_DOMAIN_CRC) << 2));

    //3. IDomainRandomGen(_MASS) + IDither(_LSB) + Setting2 + I_Domain_CRC + HLW(out)	
    ScalerSetByte(P11_DC_IDCLTI_HLW_CTRL, 0x03);     //enable HLW(outside)
    DebugMessageScaler("5. Mode_3", 0x00);	
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x65, 0xE6, 0x2E, _I_DOMAIN_CRC) << 3));


    ScalerSetByte(P11_A1_I_DLTI_CTRL_0, 0x00);       //disable IDLTI
    ScalerSetByte(P11_B3_I_DCTI_CTRL, 0x00);       //disable IDCTI
    ScalerSetByte(P11_DC_IDCLTI_HLW_CTRL, 0x00);       //disable HLW
    ScalerQCIDomainRandomGenOff();
    ScalerQCCheckCRCOff();  
    ScalerQCIDitherOff();
	
    DebugMessageScaler("5. I_DLCTI End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. I_DLCTI PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. I_DLCTI FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : VPK_VCTI Test 
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCYpeakingVCTITest(void)
{
    BYTE ucData = 0;
    BYTE ucTemp[3] = {0};

    ucTemp[0] = ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES);
    ucTemp[1] = ScalerGetByte(CM_41_IV_DV_DELAY_CLK_ODD);    
       
    ScalerSetByte(P1_C6_DCLK_SPREAD_SPECTRUM, 0x04);// Display LVDS expread spectrum

    // 2D 4Line VSU
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xC4);

    DebugMessageScaler("5. VPK/VCTI Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerQCDDitherOn(_MSB);

    // VPK/VCTI Setting 
    ScalerWrite(P11_B9_SCALER_PEAKING_C0,19, tQC_VPK_VCTI_SETTING, _AUTOINC);    
    ScalerWrite(P11_CC_VPK_VCTI_HLW_H_START_HIGH,8, tQC_VPK_VCTI_HLW, _AUTOINC);    

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    // IRandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x58, 0x01, 0x1B, _D_DOMAIN_CRC) << 0));

    // IRandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), _BIT7);	
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x5F, 0x57, 0xF7, _D_DOMAIN_CRC) << 1));

    // IRandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)

    ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));	
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x97, 0x5C, 0xE0, _D_DOMAIN_CRC) << 2));

    // IRandomGen +  DDither(_LSB)
    ScalerQCDDitherOn(_LSB);
    ScalerQCHighlightWindowOff();
    ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), 0x00);	
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x5B, 0x60, 0xBC, _D_DOMAIN_CRC) << 3));

    // IRandomGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), _BIT7);	
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x71, 0x79, 0x74, _D_DOMAIN_CRC) << 4));

    ScalerSetByte(P11_B9_SCALER_PEAKING_C0, 0x00);     //disable VPK
    ScalerSetByte(P11_C1_SR_VCTI_CTRL, 0x00);          //disable VCTI

    ScalerQCIDomainRandomGenOff();
    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCCheckCRCOff();   

    DebugMessageScaler("5. VPK/VCTI End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. VPK/VCTI PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. VPK/VCTI FAIL", 0x00);
        return _TEST_FAIL;
    }	   
}
//--------------------------------------------------
// Description  : Super Resolution Test 
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCSuperResolutionTest(void)
{
    BYTE ucData = 0;

    DebugMessageScaler("5. Super Resolution Start", 0x00);
    ScalerQCDDomainPatternGenOn();
    ScalerQCDDitherOn(_LSB);

    // Set SuperResolution setting1 
    ScalerWrite(P11_F0_D_DLTI_OPTIONS,9, tQC_SR_SETTING_PAGE11_1, _AUTOINC);    
    ScalerWrite(P12_A0_SR_SHP_CTRL,43, tQC_SR_SETTING_PAGE12_1, _AUTOINC);   
    ScalerWrite(P13_A0_SR_CDS_CTRL,69, tQC_SR_SETTING_PAGE13_1, _AUTOINC);       

    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    // DPatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xB5, 0xAB, 0x43, _D_DOMAIN_CRC) << 0));

    // DPatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);	
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT3 | _BIT2), _BIT2);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT1 | _BIT0), _BIT0);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x02, 0x2E, 0xB9, _D_DOMAIN_CRC) << 1));

    // DPatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerQCDDitherOn(_MSB);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT3 | _BIT2), _BIT3);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT1 | _BIT0), _BIT1);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF4, 0x71, 0x94, _D_DOMAIN_CRC) << 2));

    // DPatternGen + HLW(_IN/OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT3 | _BIT2), 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT1 | _BIT0), 0x00);
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x1E, 0xF5, 0xAA, _D_DOMAIN_CRC) << 3));

    ScalerQCHighlightWindowOff();
    ScalerQCDDomainPatternGenOff();
    ScalerQCIDomainRandomGenOn(_MASS);
    // Set SuperResolution setting2 
    ScalerWrite(P11_F0_D_DLTI_OPTIONS,9, tQC_SR_SETTING_PAGE11_2, _AUTOINC);    
    ScalerWrite(P12_A0_SR_SHP_CTRL,43, tQC_SR_SETTING_PAGE12_2, _AUTOINC);   
    ScalerWrite(P13_A0_SR_CDS_CTRL,69, tQC_SR_SETTING_PAGE13_2, _AUTOINC);   
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    // IRandomGen + DDither(_MSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x1E, 0xD7, 0x1C, _D_DOMAIN_CRC) << 4));

    // IRandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);	
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT3 | _BIT2), _BIT2);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT1 | _BIT0), _BIT0);

    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x7A, 0x2E, 0x53, _D_DOMAIN_CRC) << 5));

    // IRandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerQCDDitherOn(_LSB);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT3 | _BIT2), _BIT3);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT1 | _BIT0), _BIT1);
    DebugMessageScaler("5. Mode_6", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xED, 0xAC, 0x08, _D_DOMAIN_CRC) << 6));

    // IRandomGen + HLW(_IN/OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT3 | _BIT2), 0x00);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT1 | _BIT0), 0x00);
    DebugMessageScaler("5. Mode_7", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFC, 0x3D, 0x0C, _D_DOMAIN_CRC) << 7));

    ScalerSetByte(P11_F0_D_DLTI_OPTIONS, 0x00);          //disable D_DLTI
    ScalerSetByte(P11_F4_D_DCTI_CTRL, 0x00);          //disable D_DCTI
    ScalerSetByte(P12_A0_SR_SHP_CTRL, 0x00);          //disable SHP
    ScalerQCIDomainRandomGenOff();
    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCCheckCRCOff();   

    DebugMessageScaler("5. Super Resolution End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. Super Resolution PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. Super Resolution FAIL", 0x00);
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
    BYTE ucHStart = 0;
    BYTE ucVStart = 0;

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
        ucHStart = g_stActiveRegion.usHActiveStart;
        ucVStart = g_stActiveRegion.usVActiveStart;
    }

    // Get Input Status
    if(ScalerGetBit(CM_03_STATUS1, (_BIT2 | _BIT1 | _BIT0)) != (_BIT2 | _BIT1 | _BIT0))
    {
        DebugMessageScaler("6. Fail Mode - No Input!!", 0x00);
        DebugMessageScaler("6. ADC Histogram FAIL", 0x00); 
        return _TEST_FAIL;
    }

    ucHStart = ucHStart - 42;
    ucVStart = ucVStart + 110;

    // Set ADC Histogram parameter 
    ScalerWrite(P1E_A0_HIST_BON_WIDTH_H,8, tQC_ADCH_SETTING_FUNC1A, _AUTOINC);    
    ScalerSetByte(P1E_A4_HIST_HOR_START_H, (ucHStart & 0xF00) >> 4);
    ScalerSetByte(P1E_A5_HIST_HOR_START_L, ucHStart & 0x0FF);
    ScalerSetByte(P1E_A6_HIST_VER_START_H, (ucVStart & 0xF00) >> 4);
    ScalerSetByte(P1E_A7_HIST_VER_START_L, ucVStart & 0x0FF);
         

    //Enable Func1a  
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~_BIT2, _BIT2);	
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
        (pData[7] != 0x00) || (pData[8] != 0x21) || (pData[9] != 0x00) || (pData[10] != 0x2C) || (pData[11] != 0x00) || (pData[12] != 0xB1) || (pData[13] != 0x01) ||
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
        (pData[7] != 0x00) || (pData[8] != 0x63) || (pData[9] != 0x00) || (pData[10] != 0x00) || (pData[11] != 0x00) || (pData[12] != 0x00) || (pData[13] != 0x01) ||
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

    if((pData[0] != 0x0A) || (pData[1] != 0x28) || (pData[2] != 0x0C) || (pData[3] != 0xE4) || (pData[4] != 0x11) || (pData[5] != 0x30) || (pData[6] != 0x3F) ||
        (pData[7] != 0xFF) || (pData[8] != 0x00) || (pData[9] != 0x01))
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

    if((pData[0] != 0x10) || (pData[1] != 0xBC) || (pData[2] != 0x13) || (pData[3] != 0x78) || (pData[4] != 0x17) || (pData[5] != 0xC4) || (pData[6] != 0x3F) ||
        (pData[7] != 0xFF) || (pData[8] != 0x01) || (pData[9] != 0x11))
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

#if((_SDRAM_SIZE_CONFIG == _1M_32BIT) || (_SDRAM_SIZE_CONFIG == _2M_32BIT))
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
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);    
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)
    ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
#endif

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

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, g_ucSdrCasLatnQC);
#else 	
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);		
#endif
	
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, g_ucSdrCasLatnQC);
#else 	
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);		
#endif


#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, g_ucSdrCasLatnQC);
#else 	
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);		
#endif

#endif
    
    ScalerSetByte(P4_A6_SDR_SLEW_RATE, 0x00);    
    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x03);
    // Set SDRAM Token ring
    // OD = _OFF & FRC = _ON
    ScalerSetByte(P4_AA_SDR_RSC_AREF, 0x11);
    ScalerSetByte(P4_AB_SDR_RSC_MCU, 0x22);
    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x44);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x88);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x00);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);

    // Set MCLK phase
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x00);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, g_ucSdrClkDly1QC);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, g_ucSdrClkDly2QC);
    ScalerSetByte(P4_C3_DQS0_DLY2, g_ucDqsFineDlyQC);

#else
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);

#endif

#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, g_ucSdrClkDly1QC);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, g_ucSdrClkDly2QC);
    ScalerSetByte(P4_C3_DQS0_DLY2, g_ucDqsFineDlyQC);
    ScalerSetByte(P4_C5_DQS1_DLY2, g_ucDqsFineDlyQC);

#else
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);
    ScalerSetByte(P4_C5_DQS1_DLY2, _SDR_DQS_DLY);

#endif

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, g_ucSdrClkDly1QC);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, g_ucSdrClkDly2QC);
    ScalerSetByte(P4_C3_DQS0_DLY2, g_ucDqsFineDlyQC);
    ScalerSetByte(P4_C5_DQS1_DLY2, g_ucDqsFineDlyQC);

#else
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);
    ScalerSetByte(P4_C5_DQS1_DLY2, _SDR_DQS_DLY);

#endif

#endif

    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
    ScalerSetByte(P4_C6_DQS2_DLY1, 0x00);
    ScalerSetByte(P4_C7_DQS2_DLY2, 0x00);    
    ScalerSetByte(P4_C8_DQS3_DLY1, 0x00);    
    ScalerSetByte(P4_C9_DQS3_DLY2, 0x00);    

    ScalerTimerDelayXms(100);    
    
    //-----------------------------------
    // Check CRC
    //-----------------------------------    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x5C, 0x7E, 0xA0, _D_DOMAIN_CRC) << 0));
    DebugMessageScaler("5. Mode_0", ucData);
    
    //-----------------------------------
    // FRC 6 Bit Frame Setting    
    //-----------------------------------
    // Input : 1280x1024, Line mode, Single buffer
    ScalerSetByte(P5_A6_SDRF_IN1_PXL_NUM_H, 0x05);
    ScalerSetByte(P5_A7_SDRF_IN1_PXL_NUM_L, 0x00);    
    ScalerSetByte(P5_A8_SDRF_IN1_WATER_LEVEL, 0xA0);
    ScalerSetByte(P5_A9_SDRF_IN1_WR_NUM_H, 0x00);
    ScalerSetByte(P5_AA_SDRF_IN1_WR_NUM_L, 0x02);
    ScalerSetByte(P5_AB_SDRF_IN1_WR_LEN, 0xA0);
    ScalerSetByte(P5_AC_SDRF_IN1_WR_REMAIN, 0xA0);
    ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, 0x00);
    ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, 0x00);
    ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, 0x00);
    ScalerSetByte(P5_B0_SDRF_IN1_LINE_STEP_H, 0x08);
    ScalerSetByte(P5_B1_SDRF_IN1_LINE_STEP_L, 0x00);
    ScalerSetByte(P5_B2_SDRF_IN1_BLOCK_STEP_H, 0x04);
    ScalerSetByte(P5_B3_SDRF_IN1_BLOCK_STEP_L, 0x00);
    ScalerSetByte(P5_B4_SDRF_IN1_BL2_ADDR_H, 0x20);
    ScalerSetByte(P5_B5_SDRF_IN1_BL2_ADDR_M, 0x00);
    ScalerSetByte(P5_B6_SDRF_IN1_BL2_ADDR_L, 0x00);
    ScalerSetByte(P5_B7_SDRF_IN1_LINE_NUM_H, 0x04);
    ScalerSetByte(P5_B8_SDRF_IN1_LINE_NUM_L, 0x00);
    ScalerSetByte(P5_B9_SDRF_IN1_SDR_CTRL, 0x82);
//    ScalerSetByte(P5_BB_SDRF_IN1_SDR_STATUS, 0x04);

    // Display : 1280x1024, Line mode, Single buffer
    ScalerSetByte(P5_BC_SDRF_MN_PRERD_VST_H, 0x00);
    ScalerSetByte(P5_BD_SDRF_MN_PRERD_VST_L, 0x03);
    ScalerSetByte(P5_BE_SDRF_MN_PXL_NUM_H, 0x05);
    ScalerSetByte(P5_BF_SDRF_MN_PXL_NUM_L, 0x00);
    ScalerSetByte(P5_C0_SDRF_MN_WTLVL, 0xA0);
    ScalerSetByte(P5_C2_SDRF_MN_READ_NUM_H, 0x00);
    ScalerSetByte(P5_C3_SDRF_MN_READ_NUM_L, 0x02);
    ScalerSetByte(P5_C4_SDRF_MN_READ_LEN, 0xA0);
    ScalerSetByte(P5_C5_SDRF_MN_READ_REMAIN, 0xA0);
    ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, 0x00);
    ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, 0x00);
    ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, 0x00);
    ScalerSetByte(P5_C9_SDRF_MN_LINE_STEP_H, 0x08);
    ScalerSetByte(P5_CA_SDRF_MN_LINE_STEP_L, 0x00);
    ScalerSetByte(P5_CB_SDRF_MN_BLOCK_STEP_H, 0x04);    // Block step[22:19]
    ScalerSetByte(P5_CC_SDRF_MN_BLOCK_STEP_L, 0x00);    // Block step[18:11]
    ScalerSetByte(P5_EB_SDRF_MN_BLOCK_STEP_BANK, 0x00); // Block step[10:8]
    ScalerSetByte(P5_EC_SDRF_MN_BLOCK_STEP_COL, 0x00);  // Block step[7:0]    	    
    ScalerSetByte(P5_CD_SDRF_MN_LINE_NUM_H, 0x04);
    ScalerSetByte(P5_CE_SDRF_MN_LINE_NUM_L, 0x00);
    ScalerSetByte(P5_CF_SDRF_MN_DISP_CTRL, 0x09);
    ScalerSetByte(P5_D0_SDRF_MN_SDR_STATUS, 0x11); // Set input RGB 6 bit
    
    //-----------------------------------
    // FRC Dither Setting
    //-----------------------------------
    ScalerQCFRCDither();
    
    ScalerTimerDelayXms(100);

    //-----------------------------------
    // Check CRC
    //-----------------------------------    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xE5, 0x2B, 0x5D, _D_DOMAIN_CRC) << 1));
    DebugMessageScaler("5. Mode_1", ucData);

    //-----------------------------------
    // Recover FRC Setting
    //-----------------------------------
    ScalerQCFRCRecoverSetting();   

    DebugMessageScaler("5. FRC End", 0x00);
    
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. FRC PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. FRC FAIL", 0x00);
        return _TEST_FAIL;
    }
}
#endif // End of #if((_SDRAM_SIZE_CONFIG == _1M_32BIT) || (_SDRAM_SIZE_CONFIG == _2M_32BIT))

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
       
    ScalerSetByte(P1_C6_DCLK_SPREAD_SPECTRUM, 0x04);// Display LVDS expread spectrum

    // 2D 4Line VSU
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xC4);
    
    DebugMessageScaler("5. Mode_0", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);	    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x20, 0x00, 0xA5, _D_DOMAIN_CRC) << 0));

    // 3D 2Line VSU
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xE1);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xFC);
    ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
    
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_SU_COEF_2L_2, 128, GET_CURRENT_BANK_NUMBER(), CM_36_FILTER_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);    
    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0]+1);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucTemp[1]);  

    ucFlag = 16;
    for(ucI = 0; ucI < 15; ucI++)
    {
        ScalerSetByte(CM_02_STATUS0, 0x00);
        ScalerTimerWaitForEvent(_EVENT_DVS);    	    	
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        
        if(ScalerGetByte(CM_02_STATUS0) & 0x03)
        {         
            ucFlag++;                    
        }   
        else
        {
            if(ucFlag > 16)
            {
                ucFlag = 16;
            }
            else
            {
                ucFlag--;
                break;
            }           
        }
        
        if(ucI * 0x10 > 0xFF - ucTemp[1])
        {
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0] + 2);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 - (0xFF - ucTemp[1]));
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }
        else
        {
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0] + 1);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI*0x10 + ucTemp[1]);
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }        
    }    
    
    DebugMessageScaler("5. Mode_1", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);	    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xA4, 0x20, 0x3E, _D_DOMAIN_CRC) << 1));
    
    // 2D 3Line VSU
    ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0x44);
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~(_BIT6), _BIT6);

    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_SU_COEF_3L_2, 128, GET_CURRENT_BANK_NUMBER(), CM_36_FILTER_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);     

    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0]);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucTemp[1]);  

    ucFlag = 16;
    for(ucI = 0; ucI < 15; ucI++)
    {
        ScalerSetByte(CM_02_STATUS0, 0x00);
        ScalerTimerWaitForEvent(_EVENT_DVS);    	    	
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        
        if(ScalerGetByte(CM_02_STATUS0) & 0x03)
        {         
            ucFlag++;    
        }   
        else
        {
            if(ucFlag > 16)
            {
                ucFlag = 16;
            }
            else
            {
                ucFlag--;
                break;
            }           
        }
        
        if(ucI * 0x10 > 0xFF - ucTemp[1])
        {
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0] + 1);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 - (0xFF - ucTemp[1]));
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }
        else
        {
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 + ucTemp[1]);
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }        
    }      
    
    DebugMessageScaler("5. Mode_2", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);	    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x02, 0x45, 0xFE, _D_DOMAIN_CRC) << 2));    
  
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~(_BIT6), 0x00);
    
    // 3D 3Line VSU            
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xE1);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0x7C);
    ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);  
    
    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0]+1);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucTemp[1]);  

    ucFlag = 16;
    for(ucI = 0; ucI < 15; ucI++)
    {
        ScalerSetByte(CM_02_STATUS0, 0x00);
        ScalerTimerWaitForEvent(_EVENT_DVS);    	    	
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
       
        if(ScalerGetByte(CM_02_STATUS0) & 0x03)
        {         
            ucFlag++;          
        }   
        else
        {
            if(ucFlag > 16)
            {
                ucFlag = 16;
            }
            else
            {
                ucFlag--;
                break;
            }           
        }
        
        if(ucI * 0x10 > 0xFF - ucTemp[1])
        {
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0] + 2);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 - (0xFF - ucTemp[1]));
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }
        else
        {
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0] + 1);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 + ucTemp[1]);
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }        
    } 
    
    DebugMessageScaler("5. Mode_3", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);	    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xA9, 0x1B, 0x96, _D_DOMAIN_CRC) << 3));   

    // 3D 3Line VSU + H By Line SU
    ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), _BIT2); 
    ScalerSetBit(CM_35_FILTER_CTRL, ~_BIT3, _BIT3);    
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xE1);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0x7C);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_12_SU_H_COEF_INI_VALUE_ODD, 0x61);
    
    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0]+1);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucTemp[1]);  

    ucFlag = 16;
    for(ucI = 0; ucI < 15; ucI++)
    {
        ScalerSetByte(CM_02_STATUS0, 0x00);
        ScalerTimerWaitForEvent(_EVENT_DVS);    	    	
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        
        if(ScalerGetByte(CM_02_STATUS0) & 0x03)
        {         
            ucFlag++;           
        }   
        else
        {
            if(ucFlag > 16)
            {
                ucFlag = 16;
            }
            else
            {
                ucFlag--;
                break;
            }           
        }
        
        if(ucI * 0x10 > 0xFF - ucTemp[1])
        {
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0] + 2);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 - (0xFF - ucTemp[1]));
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }
        else
        {
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0]+1);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 + ucTemp[1]);
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }        
    } 
    
    DebugMessageScaler("5. Mode_4", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);	    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x81, 0xBE, 0x17, _D_DOMAIN_CRC) << 4)); 
    
    // 3D 3Line VSU + Internal odd-signal inverse for by_line_scale_up
    ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), _BIT2); 
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT3 | _BIT0), _BIT3 | _BIT0);     

    DebugMessageScaler("5. Mode_5", 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS);	    
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x56, 0x62, 0xF3, _D_DOMAIN_CRC) << 5)); 
    
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT3 | _BIT0), 0x00);    

    // 3D 3Line VSU + LineSwitch
    ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT0); 

    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, 0x01);
    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 

    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0]+1);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucTemp[1]);  

    ucFlag = 16;
    for(ucI = 0; ucI < 15; ucI++)
    {
        ScalerSetByte(CM_02_STATUS0, 0x00);
        ScalerTimerWaitForEvent(_EVENT_DVS);    	    	
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
        
        if(ScalerGetByte(CM_02_STATUS0) & 0x03)
        {         
            ucFlag++;           
        }   
        else
        {
            if(ucFlag > 16)
            {
                ucFlag = 16;
            }
            else
            {
                ucFlag--;
                break;
            }           
        }
        
        if(ucI * 0x10 > 0xFF - ucTemp[1])
        {
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0] + 2);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 - (0xFF - ucTemp[1]));
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }
        else
        {
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0] + 1);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucI * 0x10 + ucTemp[1]);
            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
        }        
    } 
    DebugMessageScaler("5. Mode_6", 0x00); 
    ScalerTimerWaitForEvent(_EVENT_DVS);	    	   
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x38, 0xFB, 0x04, _D_DOMAIN_CRC) << 6));     
 
    ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);  
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xC4);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xC4);

    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, ucTemp[0]);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, ucTemp[1]);  
    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5); 
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

    ScalerQCDDomainPatternGenOn();
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

    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x76, 0xB6, 0x83, _D_DOMAIN_CRC) << 4));
    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xD5, 0xC1, 0xC2, _D_DOMAIN_CRC) << 5));
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3);
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0xFF);
    DebugMessageScaler("5. Mode_6", 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x99, 0x5B, 0x5E, _D_DOMAIN_CRC) << 6));
    // PatternGen + HLW(_IN/OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0x00);
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x00);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x02);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, 0x5C);
    DebugMessageScaler("5. Mode_7", 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xD5, 0x74, 0x46, _D_DOMAIN_CRC) << 7));

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
   // ScalerQCIDomainRandomGenOn(_MASS);
 
    // Fill DCR table
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x00);                   
    ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x08);     
 
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x04);                   
    ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x90);     
 
    ScalerSetByte(P7_D8_DCR_ACCESS_PORT , 0x01);                   
 // ScalerSetByte(P7_D9_DCR_DATA_PORT   , 0x20);
 /*
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
    if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x05||pData[3]!=0x2A||pData[4]!=0x10||pData[5]!=0x07||pData[6]!=0xB5||
       pData[7]!=0xFE||pData[8]!=0x89||pData[9]!=0x00||pData[10]!=0x4B||pData[11]!=0xB1||pData[12]!=0x00||pData[13]!=0xB8||
       pData[14]!=0x40||pData[15]!=0x77||pData[16]!=0x4B||pData[17]!=0x46||pData[18]!=0x4D||pData[19]!=0xA2||pData[20]!=0xFF||
       pData[21]!=0x00||pData[22]!=0x4B||pData[23]!=0xFE||pData[24]!=0x4D||pData[25]!=0xF0||pData[26]!=0xFF||pData[27]!=0x00||
       pData[28]!=0x4B||pData[29]!=0x90||pData[30]!=0x4D||pData[31]!=0xA4||pData[32]!=0xFF||pData[33]!=0x00)
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
  */
     
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
    if(pData[0]!=0x08||pData[1]!=0x90||pData[2]!=0x05||pData[3]!=0x2B||pData[4]!=0x24||pData[5]!=0x07||pData[6]!=0xB3||
       pData[7]!=0x96||pData[8]!=0x6C||pData[9]!=0x00||pData[10]!=0x51||pData[11]!=0xD8||pData[12]!=0x00||pData[13]!=0xBF||
       pData[14]!=0x64||pData[15]!=0xFC||pData[16]!=0x50||pData[17]!=0xB2||pData[18]!=0x50||pData[19]!=0xB8||pData[20]!=0xFF||
       pData[21]!=0x00||pData[22]!=0x4F||pData[23]!=0x92||pData[24]!=0x51||pData[25]!=0xD8||pData[26]!=0xFF||pData[27]!=0x00||
       pData[28]!=0x51||pData[29]!=0xD8||pData[30]!=0x4F||pData[31]!=0x92||pData[32]!=0xFF||pData[33]!=0x00)
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
    ucError = (BYTE)ScalerQCCheckCRCOn(0xA8, 0x2C, 0x6E, _D_DOMAIN_CRC);

    //dy = (6dU+dV)/8,delta = -256~255, Neg Compensate,     
    ScalerSetByte(P7_D0_ICM_CTRL,  0xFF); 
    ScalerSetBit(P7_D1_ICM_SEL, ~_BIT4, _BIT4);    //delta UV *4
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~_BIT7, _BIT7);// Neg Compensate 
    ScalerSetBit(P7_D4_ICM_NEW_MODE, ~_BIT1, _BIT1); // buffer != 0
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_1", ucError1);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x7E, 0x75, 0x73, _D_DOMAIN_CRC)<<1);     

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
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x20, 0x00, 0xAD, _D_DOMAIN_CRC)<<2);

       
    // Random + Highlight Window   

    ScalerQCHighlightWindowOn();

    // Random + Highlight Window + MSB  Inside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_3", ucError1);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x8F, 0x88, 0x85, _D_DOMAIN_CRC)<<3);      

    // Random + Highlight Window + MSB  Outside Window  
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT3); // 10 outside window
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    DebugMessageScaler("5. New ICM Case_4", ucError1);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x1A, 0xC1, 0x88, _D_DOMAIN_CRC)<<4);       

    // D-domain PG + Highlight Window + LSB Outside Window
    ScalerQCIDomainRandomGenOff();
    ScalerQCDDomainPatternGenOn();
    ScalerQCDDitherOn(_LSB);
    ScalerTimerDelayXms(50);
    DebugMessageScaler("5. New ICM Case_5", ucError1);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0x9D, 0x07, 0x22, _D_DOMAIN_CRC)<<5);   // remain 10     

    // D-PG+HW+LSB  Inside Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), _BIT2); // 01 inside window
    DebugMessageScaler("5. New ICM Case_6", ucError1);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xFB, 0xD1, 0xAC, _D_DOMAIN_CRC)<<6);      

    // D-PG+HW+LSB  Full Window
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), 0); // 00 Full window
    DebugMessageScaler("5. New ICM Case_7", ucError1);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ucError = ucError | ((BYTE)ScalerQCCheckCRCOn(0xE6, 0x1B, 0x38, _D_DOMAIN_CRC)<<7); 

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
    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerQCHighlightWindowOn();

    // RandomGen + IN/OUT WINDOW
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

    if((pData[0] != 0x00) || (pData[1] != 0x02) || (pData[2] != 0x5E) || (pData[3] != 0x00) || (pData[4] !=0x00) || (pData[5] != 0x00) || (pData[6] != 0x01) ||
       (pData[7] != 0x03) || (pData[8] != 0x07) || (pData[9] != 0x10) || (pData[10] != 0x20) || (pData[11] !=0x37) || (pData[12] != 0x55) || (pData[13] != 0x76) ||
       (pData[14] != 0x9A) || (pData[15] != 0xBE) || (pData[16] != 0xDE) || (pData[17] != 0xF5))
    {
        ucData = ucData | _BIT0;
    }

    // Disabled CABC Histogram
    ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT2, 0x00);

    // RandomGen + INSIDE WINDOW
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


    if((pData[0] != 0x00) || (pData[1] != 0x0C) || (pData[2] != 0x56) || (pData[3] != 0x00) || (pData[4] != 0x00) || (pData[5] != 0x00) || (pData[6] != 0x01) ||
       (pData[7] != 0x03) || (pData[8] != 0x08) || (pData[9] != 0x10) ||(pData[10] != 0x20) || (pData[11] != 0x38) || (pData[12] != 0x56) || (pData[13] != 0x77) ||
       (pData[14] != 0x9B) ||(pData[15] != 0xBF) || (pData[16] != 0xDF) || (pData[17] != 0xF5))
    {
        ucData = ucData | _BIT1;
    }

    // Disabled CABC Histogram
    ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT2, 0x00);

    // RandomGen + OUTSIDE WINDOW
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


    if((pData[0] != 0x00) || (pData[1] != 0x03) || (pData[2] != 0x02) || (pData[3] != 0x00) || (pData[4] != 0x00) || (pData[5] != 0x00) || (pData[6] != 0x01) ||
       (pData[7] != 0x03) || (pData[8] != 0x07) || (pData[9] != 0x10) || (pData[10] != 0x20) ||(pData[11] != 0x37) || (pData[12] != 0x55) || (pData[13] != 0x76) ||
       (pData[14] != 0x9A) || (pData[15] != 0xBE) || (pData[16] != 0xDE) || (pData[17] != 0xF5))
    {
        ucData = ucData | _BIT2;
    }

    // Disabled CABC Histogram
    ScalerSetBit(P7_DB_CABC_CTRL, ~_BIT2, 0x00);
    ScalerQCIDomainRandomGenOff();
    ScalerQCHighlightWindowOff();

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

    ScalerQCDDomainPatternGenOn();
    ScalerQCDDitherOn(_LSB);
    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x4F, 0x38, 0x1D, _D_DOMAIN_CRC) << 0));
    // PatternGen + HLW(_IN(A)/OUTSIDE(A)_WINDOW + Bottom&Right border) + DDither(_LSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), 0x00);
    DebugMessageScaler("5. Mode_6", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFB, 0xC7, 0x09, _D_DOMAIN_CRC) << 1));
    // PatternGen + HLW(_INSIDE(B)_WINDOW + Top&Left border) + DDither(_LSB)
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_7", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xE1, 0x6E, 0x7F, _D_DOMAIN_CRC) << 2));
    // PatternGen + HLW(_OUTSIDE(A)_WINDOW + Bottom&Left border) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_8", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x14, 0x47, 0x27, _D_DOMAIN_CRC) << 3));
    // PatternGen + HLW(_IN(B)/OUTSIDE(A)_WINDOW + Top&Right border) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_08_HW_BORDER_WIDTH, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_9", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x40, 0xB2, 0x56, _D_DOMAIN_CRC) << 4));

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
// Output Value : None
//--------------------------------------------------
bit ScalerQCGammaTest(void)
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF3, 0x11, 0x7E, _D_DOMAIN_CRC) << 0));

    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x9A, 0xA0, 0xA0, _D_DOMAIN_CRC) << 1));
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xCF, 0xF4, 0xB2, _D_DOMAIN_CRC) << 2));
    // RandomGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xCC, 0x45, 0xAC, _D_DOMAIN_CRC) << 3));
    
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

    DebugMessageScaler("5. Output Gamma End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. Output Gamma PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. Output Gamma FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : sRGB Matrix Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCsRGBTest(void)
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x55, 0x68, 0xCB, _D_DOMAIN_CRC) << 0));

    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x70, 0xB9, 0x99, _D_DOMAIN_CRC) << 1));
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x62, 0x5B, 0xC2, _D_DOMAIN_CRC) << 2));
    // RandomGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xBF, 0x13, 0x51, _D_DOMAIN_CRC) << 3));
    
    ScalerQCHighlightWindowOff();
    ScalerQCIDomainRandomGenOff();
    
    ScalerQCDDomainPatternGenOn();
    ScalerQCDDitherOn(_LSB);
    
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT6, _BIT6); // Bit Left Shift
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT6 | _BIT5), _BIT5); // 2-bit Shift-left

    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x97, 0x4C, 0xBB, _D_DOMAIN_CRC) << 4));
    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x8E, 0xEE, 0xE1, _D_DOMAIN_CRC) << 5));
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_6", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x86, 0xC7, 0x49, _D_DOMAIN_CRC) << 6));
    // PatternGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_7", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x40, 0x7D, 0x74, _D_DOMAIN_CRC) << 7));
   
    // R Offset
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

bit ScalerQCPCMTest(void)
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
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x49, 0xED, 0x2B, _D_DOMAIN_CRC) << 0));

    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // RandomGen + HLW(_INSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x9B, 0x75, 0x88, _D_DOMAIN_CRC) << 1));
    // RandomGen + HLW(_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xEB, 0x7F, 0x7E, _D_DOMAIN_CRC) << 2));
    // RandomGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_MSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xDD, 0xFB, 0xFC, _D_DOMAIN_CRC) << 3));
    
    ScalerQCHighlightWindowOff();
    ScalerQCIDomainRandomGenOff();
        
    ScalerQCDDomainPatternGenOn();
    ScalerQCDDitherOn(_LSB);
    
    // PatternGen + DDither(_LSB)
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x5B, 0xED, 0x79, _D_DOMAIN_CRC) << 1));
    
    ScalerQCHighlightWindowOn();
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), _BIT7);
    
    // PatternGen + HLW(_INSIDE_WINDOW) + DDither(_LSB)
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2B, 0x40, 0xA4, _D_DOMAIN_CRC) << 5));
    // PatternGen + HLW(_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
	DebugMessageScaler("5. Mode_6", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x57, 0xB2, 0x4B, _D_DOMAIN_CRC) << 6));
	// PatternGen + HLW(_IN/_OUTSIDE_WINDOW) + DDither(_LSB)
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
	ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
	DebugMessageScaler("5. Mode_7", 0x00);
	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x34, 0xA6, 0x33, _D_DOMAIN_CRC) << 7));
	
    // R Offset
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

    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT6, 0x00); // Disable Input Gamma
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT2, 0x00); // Disable sRGB
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, 0x00); // Disable Output Gamma
    ScalerQCDDomainPatternGenOff();
    ScalerQCDDitherOff();
    ScalerQCHighlightWindowOff();
    ScalerQCCheckCRCOff();

    DebugMessageScaler("5. PCM End", 0x00);    
    if(ucData == 0x00)
    {
        DebugMessageScaler("6. PCM PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. PCM FAIL", 0x00);
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
    BYTE ucCnt = 0;
    BYTE ucTableCnt = 0;
    BYTE ucDataTemp[3] = {0};    
    
    DebugMessageScaler("5. D Dither Start", 0x00);

    ScalerQCDDomainPatternGenOn();

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
    // sign, multi-seq, share-seq, inv seq, inv1, keep 4 , pr2
    ScalerSetBit(CM_67_GAMMA_CTRL, ~(_BIT1 | _BIT0), _BIT1 | _BIT0);
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT7 | _BIT4 | _BIT3), _BIT4);
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

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
//--------------------------------------------------
// Description  : Enable D Domain Pattern1 for LiveShow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCODDDomainPattern1(void)
{
	ScalerSetByte(P7_F0_DISP_PG_R_CTRL, 0x04);
	ScalerSetByte(P7_F1_DISP_PG_G_CTRL, 0x04);
	ScalerSetByte(P7_F2_DISP_PG_B_CTRL, 0x04);
	ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, 0x00);
	ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, 0x00);
	ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, 0x00);
	ScalerSetByte(P7_F6_DISP_PG_PIXEL_DELTA, 0x01);
	ScalerSetByte(P7_F7_DISP_PG_LINE_DELTA, 0x01);
	ScalerSetByte(P7_F8_DISP_PG_PIXEL_STEP_MSB, 0x01);
	ScalerSetByte(P7_F9_DISP_PG_LINE_STEP_MSB, 0x01);
	ScalerSetByte(P7_FA_DISP_PG_STEP_LSB, 0x00);

	ScalerSetBit(P7_F0_DISP_PG_R_CTRL, ~_BIT7, _BIT7);
}

//--------------------------------------------------
// Description  : Enable D Domain Pattern2 for LiveShow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCODDDomainPattern2(void)
{
	ScalerSetByte(P7_F0_DISP_PG_R_CTRL, 0x01);
	ScalerSetByte(P7_F1_DISP_PG_G_CTRL, 0x01);
	ScalerSetByte(P7_F2_DISP_PG_B_CTRL, 0x01);
	ScalerSetByte(P7_F3_DISP_PG_R_INITIAL, 0x00);
	ScalerSetByte(P7_F4_DISP_PG_G_INITIAL, 0x00);
	ScalerSetByte(P7_F5_DISP_PG_B_INITIAL, 0x00);
	ScalerSetByte(P7_F6_DISP_PG_PIXEL_DELTA, 0x01);
	ScalerSetByte(P7_F7_DISP_PG_LINE_DELTA, 0x01);
	ScalerSetByte(P7_F8_DISP_PG_PIXEL_STEP_MSB, 0x01);
	ScalerSetByte(P7_F9_DISP_PG_LINE_STEP_MSB, 0x01);
	ScalerSetByte(P7_FA_DISP_PG_STEP_LSB, 0x00);

	ScalerSetBit(P7_F0_DISP_PG_R_CTRL, ~_BIT7, _BIT7);
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

	// Load OD LUT Table
	ScalerSetBit(P3_BF_LS_LUT_CTRL, ~(_BIT7 | _BIT6), _BIT7);
	ScalerBurstWrite(tOD_QC_TABLE, sizeof(tOD_QC_TABLE), GET_CURRENT_BANK_NUMBER(), P3_C0_LS_LUT_DATA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
	ScalerRead(P3_BF_LS_LUT_CTRL, 1, &ucData, _NON_AUTOINC);

	if((ucData & 0x02) != 0x00)
	{
		DebugMessageScaler("5. 3.Liveshow Write LUT Fail", 0x00);
	}

	ScalerSetBit(P3_BF_LS_LUT_CTRL, ~(_BIT7 | _BIT6), 0x00);

    //-----------------------------------
    // SDRAM Setting
    //-----------------------------------
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)
    ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
#endif

	ScalerTimerDelayXms(50);

    // Reset SDRAM
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, _BIT4);
    ScalerTimerDelayXms(50);
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, 0x00);

    // Set FIFO freq. = MPLL
    ScalerSetByte(CM_22_FIFO_FREQUENCY, 0x4C);

	// Set SDRAM Size
	ScalerSetByte(P4_A1_SDR_CTRL0, _SDR_ROW_DELAY);
	ScalerSetByte(P4_A2_SDR_CTRL1, _SDR_COL_DELAY);
	ScalerSetByte(P4_A3_SDR_AREF_TIME, 0x0D);
	ScalerSetByte(P4_A4_SDR_PRCG, 0x83);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, g_ucSdrCasLatnQC);
#else 	
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);		
#endif
	
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, g_ucSdrCasLatnQC);
#else 	
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);		
#endif

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, g_ucSdrCasLatnQC);
#else 	
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);		
#endif

#endif

	ScalerSetByte(P4_A6_SDR_SLEW_RATE, 0x00);
    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x03);
	// Set SDRAM Token ring
	// OD = _OFF & FRC = _ON
	ScalerSetByte(P4_AA_SDR_RSC_AREF, 0xFF);
	ScalerSetByte(P4_AB_SDR_RSC_MCU, 0x20);
	ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x00);
	ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x00);
	ScalerSetByte(P4_B0_SDR_RSC_RD, 0xAA);
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x55);

	// Set MCLK phase
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, g_ucSdrClkDly1QC);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, g_ucSdrClkDly2QC);
    ScalerSetByte(P4_C3_DQS0_DLY2, g_ucDqsFineDlyQC);

#else
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);

#endif

#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, g_ucSdrClkDly1QC);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, g_ucSdrClkDly2QC);
    ScalerSetByte(P4_C3_DQS0_DLY2, g_ucDqsFineDlyQC);
    ScalerSetByte(P4_C5_DQS1_DLY2, g_ucDqsFineDlyQC);

#else
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);
    ScalerSetByte(P4_C5_DQS1_DLY2, _SDR_DQS_DLY);

#endif

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, g_ucSdrClkDly1QC);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, g_ucSdrClkDly2QC);
    ScalerSetByte(P4_C3_DQS0_DLY2, g_ucDqsFineDlyQC);
    ScalerSetByte(P4_C5_DQS1_DLY2, g_ucDqsFineDlyQC);

#else
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);
    ScalerSetByte(P4_C5_DQS1_DLY2, _SDR_DQS_DLY);

#endif

#endif

    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
    ScalerSetByte(P4_C6_DQS2_DLY1, 0x00);
    ScalerSetByte(P4_C7_DQS2_DLY2, 0x00);
    ScalerSetByte(P4_C8_DQS3_DLY1, 0x00);
    ScalerSetByte(P4_C9_DQS3_DLY2, 0x00);
 
	ScalerTimerDelayXms(100); 

	ScalerSetByte(P3_A6_LS_WTLVL_W, 0x30);
    ScalerSetByte(P3_A7_LS_WTLVL_R, 0x60);
	ScalerSetByte(P3_AA_LS_MEM_FIFO_RW_LEN, 0x60);
	ScalerSetByte(P3_AC_LS_MEM_START_ADDR_H, 0x00);
	ScalerSetByte(P3_AD_LS_MEM_START_ADDR_M, 0x00);
	ScalerSetByte(P3_AE_LS_MEM_START_ADDR_L, 0x00);

	ucData = 0x00;

    DebugMessageScaler("5. Mode_0", 0x00);

	ScalerSetByte(P3_A8_LS_MEM_FIFO_RW_NUM_H, 0x08);
	ScalerSetByte(P3_A9_LS_MEM_FIFO_RW_NUM_L, 0xF8);
	ScalerSetByte(P3_AB_LS_MEM_FIFO_RW_REMAIN, 0x54);

	ScalerSetBit(P3_A2_LS_CTRL1, 0x00, (_BIT7 | _BIT6 | _BIT4 | _BIT3));
	ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x5D);
	ScalerSetBit(P3_B0_LS_FRAME0, 0x00, (_BIT5));
	ScalerSetBit(P3_B1_LS_FRAME1, 0x00, (_BIT5 | _BIT1));
	ScalerSetBit(P3_B2_LS_FRAME2, 0x00, (_BIT6 | _BIT5 | _BIT4));
	ScalerSetBit(P3_B3_LS_FRAME4, 0x00, 0x09);
	ScalerSetBit(P3_B4_LS_FRAME5, 0x00, (_BIT6 | 0x01));

	ScalerSetBit(P3_A1_LS_CTRL0, 0x00, (_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT1 | _BIT0));

	ScalerQCODDDomainPattern2();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerQCODDDomainPattern1();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF7, 0xC2, 0x22, _D_DOMAIN_CRC) << 0));
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x55);

    DebugMessageScaler("5. Mode_1", 0x00);
	ScalerSetByte(P3_A8_LS_MEM_FIFO_RW_NUM_H, 0x0A);
	ScalerSetByte(P3_A9_LS_MEM_FIFO_RW_NUM_L, 0x17);
	ScalerSetByte(P3_AB_LS_MEM_FIFO_RW_REMAIN, 0x60);

	ScalerSetBit(P3_A2_LS_CTRL1, 0x00, (_BIT7 | _BIT6 | _BIT5 | _BIT4));
	ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x01);
	ScalerSetBit(P3_B0_LS_FRAME0, 0x00, (_BIT6 | _BIT5 | _BIT4));
	ScalerSetBit(P3_B1_LS_FRAME1, 0x00, (_BIT7 | _BIT5 | _BIT3 | _BIT1));
	ScalerSetBit(P3_B2_LS_FRAME2, 0x00, (_BIT7 | _BIT6 | _BIT4 | _BIT2 | _BIT1 | _BIT0));
	ScalerSetBit(P3_B3_LS_FRAME4, 0x00, (_BIT4 | 0x0F));
	ScalerSetBit(P3_B4_LS_FRAME5, 0x00, (0x03));

	ScalerSetBit(P3_A1_LS_CTRL0, 0x00, (_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT1));

	ScalerQCODDDomainPattern2();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerQCODDDomainPattern1();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x77, 0xC3, 0x26, _D_DOMAIN_CRC) << 1));    
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x55);

    DebugMessageScaler("5. Mode_2", 0x00);
	ScalerSetByte(P3_A8_LS_MEM_FIFO_RW_NUM_H, 0x0A);
	ScalerSetByte(P3_A9_LS_MEM_FIFO_RW_NUM_L, 0x79);
	ScalerSetByte(P3_AB_LS_MEM_FIFO_RW_REMAIN, 0x08);

	ScalerSetBit(P3_A2_LS_CTRL1, 0x00, (_BIT7 | _BIT6 | _BIT4 | 0x01));
	ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x40);
	ScalerSetBit(P3_B0_LS_FRAME0, 0x00, (_BIT6 | _BIT5 | _BIT4 | 0x02));
	ScalerSetBit(P3_B1_LS_FRAME1, 0x00, (_BIT7 | _BIT6 | _BIT3 | _BIT2));
	ScalerSetBit(P3_B2_LS_FRAME2, 0x00, 0x00);
	ScalerSetBit(P3_B3_LS_FRAME4, 0x00, (_BIT5 | _BIT4 | 0x06));
	ScalerSetBit(P3_B4_LS_FRAME5, 0x00, (_BIT6 | 0x02));

	ScalerSetBit(P3_A1_LS_CTRL0, 0x00, (_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT0));

	ScalerQCODDDomainPattern2();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerQCODDDomainPattern1();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x21, 0xAD, 0xA8, _D_DOMAIN_CRC) << 2));		
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x55);

    DebugMessageScaler("5. Mode_3", 0x00);
	ScalerSetByte(P3_A8_LS_MEM_FIFO_RW_NUM_H, 0x0A);
	ScalerSetByte(P3_A9_LS_MEM_FIFO_RW_NUM_L, 0xA7);
	ScalerSetByte(P3_AB_LS_MEM_FIFO_RW_REMAIN, 0x34);

	ScalerSetBit(P3_A2_LS_CTRL1, 0x00, (_BIT7 | _BIT6 | _BIT4 | _BIT3 | 0x01));
	ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0xFF);
	ScalerSetBit(P3_B0_LS_FRAME0, 0x00, (_BIT7 | _BIT4 | 0x04));
	ScalerSetBit(P3_B1_LS_FRAME1, 0x00, (_BIT7 | _BIT6 | _BIT3 | _BIT2));
	ScalerSetBit(P3_B2_LS_FRAME2, 0x00, (_BIT7));
	ScalerSetBit(P3_B3_LS_FRAME4, 0x00, (_BIT5 | 0x01));
	ScalerSetBit(P3_B4_LS_FRAME5, 0x00, (_BIT6 | 0x01));

	ScalerSetBit(P3_A1_LS_CTRL0, 0x00, (_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT0));

	ScalerQCODDDomainPattern2();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerQCODDDomainPattern1();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xD7, 0x9B, 0x3E, _D_DOMAIN_CRC) << 3));		
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x55);

    DebugMessageScaler("5. Mode_4", 0x00);
	ScalerSetByte(P3_A8_LS_MEM_FIFO_RW_NUM_H, 0x0A);
	ScalerSetByte(P3_A9_LS_MEM_FIFO_RW_NUM_L, 0xA7);
	ScalerSetByte(P3_AB_LS_MEM_FIFO_RW_REMAIN, 0x34);

	ScalerSetBit(P3_A2_LS_CTRL1, 0x00, (_BIT7 | _BIT6 | _BIT4));
	ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x63);
	ScalerSetBit(P3_B0_LS_FRAME0, 0x00, (_BIT4 | 0x06));
	ScalerSetBit(P3_B1_LS_FRAME1, 0x00, (_BIT7 | _BIT5 | _BIT3 | _BIT1));
	ScalerSetBit(P3_B2_LS_FRAME2, 0x00, (_BIT6));
	ScalerSetBit(P3_B3_LS_FRAME4, 0x00, (_BIT5 | 0x0E));
	ScalerSetBit(P3_B4_LS_FRAME5, 0x00, (_BIT6));

	ScalerSetBit(P3_A1_LS_CTRL0, 0x00, (_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT0));

	ScalerQCODDDomainPattern2();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerQCODDDomainPattern1();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x2F, 0xEC, 0x7D, _D_DOMAIN_CRC) << 4));		
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x55);

    DebugMessageScaler("5. Mode_5", 0x00);
	ScalerSetByte(P3_A8_LS_MEM_FIFO_RW_NUM_H, 0x07);
	ScalerSetByte(P3_A9_LS_MEM_FIFO_RW_NUM_L, 0xD9);
	ScalerSetByte(P3_AB_LS_MEM_FIFO_RW_REMAIN, 0x4C);

	ScalerSetBit(P3_A2_LS_CTRL1, 0x00, (_BIT7 | _BIT6));
	ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x40);
	ScalerSetBit(P3_B0_LS_FRAME0, 0x00, (_BIT5 | _BIT4 | 0x08));
	ScalerSetBit(P3_B1_LS_FRAME1, 0x00, (_BIT7 | _BIT5 | _BIT3 | _BIT1));
	ScalerSetBit(P3_B2_LS_FRAME2, 0x00, (_BIT6));
	ScalerSetBit(P3_B3_LS_FRAME4, 0x00, (_BIT4 | 0x08));
	ScalerSetBit(P3_B4_LS_FRAME5, 0x00, (0x01));

	ScalerSetBit(P3_A1_LS_CTRL0, 0x00, (_BIT7 | _BIT6 | _BIT5));

	ScalerQCODDDomainPattern2();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerQCODDDomainPattern1();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x4A, 0x9A, 0x3E, _D_DOMAIN_CRC) << 5));	
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x55);

    DebugMessageScaler("5. Mode_6", 0x00);
	ScalerQCHighlightWindowOn();
	ScalerSetByte(P3_A8_LS_MEM_FIFO_RW_NUM_H, 0x06);
	ScalerSetByte(P3_A9_LS_MEM_FIFO_RW_NUM_L, 0xBA);
	ScalerSetByte(P3_AB_LS_MEM_FIFO_RW_REMAIN, 0x40);

	ScalerSetBit(P3_A2_LS_CTRL1, 0x00, (_BIT7));
	ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x40);
	ScalerSetBit(P3_B0_LS_FRAME0, 0x00, (_BIT5 | _BIT4 | _BIT0));
	ScalerSetBit(P3_B1_LS_FRAME1, 0x00, (_BIT7 | _BIT3));
	ScalerSetBit(P3_B2_LS_FRAME2, 0x00, (_BIT4));
	ScalerSetBit(P3_B3_LS_FRAME4, 0x00, (0x08));
	ScalerSetBit(P3_B4_LS_FRAME5, 0x00, (_BIT6 | 0x02));

	ScalerSetBit(P3_A1_LS_CTRL0, 0x00, (_BIT7 | _BIT6 | _BIT5 | 0x03));

	ScalerQCODDDomainPattern2();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerTimerWaitForEvent(_EVENT_DVS);
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);
	ScalerTimerWaitForEvent(_EVENT_DVS); 
	ScalerQCODDDomainPattern1();
	ScalerTimerWaitForEvent(_EVENT_DVS); 
   	ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xCF, 0x74, 0x49, _D_DOMAIN_CRC) << 6));		
	ScalerSetByte(P4_B1_SDR_RSC_WR, 0x55);

    DebugMessageScaler("5. Mode_7", 0x00);
    ScalerQCHighlightWindowOn();

    ScalerSetBit(P3_A2_LS_CTRL1, 0x00, (_BIT6));

    ScalerQCODDDomainPattern2();
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    ScalerQCODDDomainPattern1();
    ScalerTimerWaitForEvent(_EVENT_DVS); 
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x81, 0x07, 0xF2, _D_DOMAIN_CRC) << 7));   
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x55);
 
    ScalerSetByte(P3_A1_LS_CTRL0, 0x00);
    ScalerQCHighlightWindowOff();
    ScalerQCDDomainPatternGenOff();
	ScalerQCCheckCRCOff(); 

    DebugMessageScaler("5. Liveshow End", 0x00);	
	if(ucData == 0x00)
	{
        DebugMessageScaler("6. Liveshow PASS", 0x00);	
	    return _TEST_PASS;
	}
	else
	{
	    DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. Liveshow FAIL", 0x00);	
	    return _TEST_FAIL;
	}
}
#endif // End of #if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)

bit ScalerQCDisplayConversionTest(void)
{
    BYTE ucData = 0;

    DebugMessageScaler("5. Display Conversion Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    // LVDS + Single port + Table1
    DebugMessageScaler("5. Mode_0", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x87);
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
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A8_TCON_LVDS_CTRL8, ~(_BIT5), 0x00);    	    	// LVDS Bypass

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x54,0x4A,0x9D,0x6F,
                                                    0x6F,0x31,0x5D,0x52,0xCA,0x05,0x00,0x00,
    	    	    	                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00) << 0));

    // LVDS + Single port + Table2
    DebugMessageScaler("5. Mode_1", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT0);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x65,0xF9,0xEE,0xDA,
                                                    0x6A,0xE4,0x5D,0x52,0x3C,0x7F,0x00,0x00,
    	    	    	                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00) << 1));

    // LVDS + Dual port + Table1
    DebugMessageScaler("5. Mode_2", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x88);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, _BIT2);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), 0x00);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x56,0x74,0xBB,0x07,
                                                    0xA2,0xA8,0x4C,0x46,0xA9,0x79,0x95,0xCA,
    	    	    	                            0x6D,0xE3,0x58,0x21,0x4C,0x46,0x33,0x6E) << 2));


    // LVDS + Dual port + Table2
    DebugMessageScaler("5. Mode_3", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT0);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x50,0xEA,0x85,0xBE,
                                                    0x1F,0x7E,0x4C,0x46,0xB9,0x3F,0x60,0x6D,
    	    	    	                            0x49,0x76,0x21,0x15,0x4C,0x46,0xEE,0xD7) << 3));

    // LVDS + Single port + Table3
    DebugMessageScaler("5. Mode_4", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x87);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, 0x00);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT1), _BIT1);    	    // 10-bit
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A8_TCON_LVDS_CTRL8, ~(_BIT5), _BIT5);    	    	// LVDS Bypass
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), 0x00);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x33,0xDC,0x71,0x8E,0x97,0x69,0xE9,0xFB,
                                                    0xA9,0xED,0x9A,0x87,0x00,0x00,0x00,0x00,
    	    	    	                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00) << 4));

    // LVDS + Single port + Table4
    DebugMessageScaler("5. Mode_5", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT0);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x2E,0x3A,0x01,0xA3,0x23,0x11,0xE9,0xFB,
                                                    0xF3,0x07,0xD2,0x97,0x00,0x00,0x00,0x00,
    	    	    	                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00) << 5));

    ScalerQCDDomainPatternGenOn();

    // LVDS + Dual port + Table3
    DebugMessageScaler("5. Mode_6", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x88);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, _BIT2);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A8_TCON_LVDS_CTRL8, ~(_BIT5), 0x00);    	    	// LVDS Bypass
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), 0x00);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x04,0xD6,0x47,0x3F,0xFD,0xFE,0x4C,0x46,
                                                    0xBD,0x6C,0x4D,0x7D,0xCA,0x21,0x68,0x15,
    	    	    	                            0x30,0xF5,0x4C,0x46,0x50,0x0C,0x3B,0xCD) << 6));

    // LVDS + Dual port + Table4
    DebugMessageScaler("5. Mode_7", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT0);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x9D,0x0B,0xB4,0xA6,0x04,0x0E,0x4C,0x46,
                                                    0x97,0x2F,0x1B,0xEB,0x8F,0x31,0x22,0xE8,
    	    	    	                            0x93,0x47,0x4C,0x46,0x79,0x8A,0x29,0x6E) << 7));


    ScalerQCDDomainPatternGenOff();

    // LVDS + Single port + Table1
    DebugMessageScaler("5. Mode_8", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x87);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, 0x00);    	    	    	      // Single/Dual port
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), _BIT0);    	// LVDS
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT1), 0x00);    	    // 8-bit
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1E_LVDS_CTR, 0xE3);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A4_TCON_LVDS_CTRL4, 0xBF);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A5_TCON_LVDS_CTRL5, 0xBF);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT6);    // Mirror & Table
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), _BIT7);    	    // PN Swap
    //ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1), _BIT1);    	    	// Panel Inverse
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A8_TCON_LVDS_CTRL8, ~(_BIT5), 0x00);    	    	// LVDS Bypass

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x00,0x00,0x00,0x00,0x00,0x00,0x37,0x4C,
    	    	    	                            0xDF,0x7F,0x39,0xFF,0x47,0xCC,0x78,0xC3) << 0));


    // LVDS + Single port + Table2
    DebugMessageScaler("5. Mode_9", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), (_BIT6 | _BIT0));    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x00,0x00,0x00,0x00,0x00,0x00,0xA8,0xC3,
    	    	    	                            0xDF,0x7F,0xDB,0xC5,0x33,0x25,0x7E,0x7A) << 1));


    // LVDS + Dual port + Table1
    DebugMessageScaler("5. Mode_10", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x88);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, _BIT2);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT6);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x1F,0x06,0x83,0x86,
                                                    0x16,0xCE,0x9A,0x54,0xF6,0x0A,0x1A,0xE7,
    	    	    	                            0x83,0x86,0xF8,0xF1,0x02,0x9C,0xC3,0x6A) << 2));


    // LVDS + Dual port + Table2
    DebugMessageScaler("5. Mode_11", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), (_BIT6 | _BIT0));    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x24,0xAC,0x83,0x86,
                                                    0xBD,0x5F,0xA5,0xB4,0xB3,0xB6,0x22,0xFB,
    	    	    	                            0x83,0x86,0xE2,0x06,0x8F,0xE1,0xE2,0x3E) << 3));


    // LVDS + Single port + Table3
    DebugMessageScaler("5. Mode_12", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x87);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, 0x00);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT1), _BIT1);    	    // 10-bit
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT1), 0x00);    	    	// Panel Inverse
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A8_TCON_LVDS_CTRL8, ~(_BIT5), _BIT5);    	    	// LVDS Bypass
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT6);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x00,0x00,0x00,0x00,0x30,0x0F,0xD9,0x25,
    	    	    	                            0xF0,0x11,0x5C,0x31,0x4E,0xD5,0x7E,0xDF) << 4));
    // LVDS + Single port + Table4
    DebugMessageScaler("5. Mode_13", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), (_BIT6 | _BIT0));    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x00,0x00,0x00,0x00,0x0A,0x68,0x5F,0x38,
    	    	    	                            0xF0,0x11,0xB9,0x29,0xC1,0x8C,0x6C,0xFE) << 5));

    ScalerQCDDomainPatternGenOn();

    // LVDS + Dual port + Table3
    DebugMessageScaler("5. Mode_14", 0x00);
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x88);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, _BIT2);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A8_TCON_LVDS_CTRL8, ~(_BIT5), 0x00);    	    	// LVDS Bypass
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), _BIT6);    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x2F,0x70,0x33,0x42,0x83,0x86,0x58,0x76,
                                                    0x9C,0x3C,0x3C,0xC0,0x9A,0xFA,0x69,0x87,
    	    	    	                            0x83,0x86,0x5E,0xE6,0xBE,0xBE,0x39,0xBD) << 6));

    // LVDS + Dual port + Table4
    DebugMessageScaler("5. Mode_15", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), (_BIT6 | _BIT0));    // Mirror & Table

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x37,0x38,0xF3,0xD1,0x83,0x86,0xD0,0x85,
                                                    0x32,0x3D,0xF8,0xC8,0x0E,0x1C,0x5A,0xD7,
    	    	    	                            0x83,0x86,0x95,0x47,0xE7,0xC5,0x2C,0x97) << 7));

    ScalerQCDDomainPatternGenOff();
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, 0x88);
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, _BIT2);    	    	    	      // Single/Dual port
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT1), 0x00);    	    // 8-bit
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A4_TCON_LVDS_CTRL4, 0x80);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A5_TCON_LVDS_CTRL5, 0x80);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), 0x00);    // Mirror & Table
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A8_TCON_LVDS_CTRL8, ~(_BIT5), 0x00);    	    	// LVDS Bypass

    /*
    // miniLVDS + Single 3 + type1(CMO)
    DebugMessageScaler("5. Mode_16", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));    	// miniLVDS
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1D_MLVDS_CTRL2, 0xAA);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), 0x00);    	    // PN Swap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));    	    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);    	    


    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    	    	    	                            0x9E,0xC4,0x1F,0xF8,0xA2,0x64,0xD4,0xD2) << 0));


    // miniLVDS + Single 3 + type2(AUO)
    DebugMessageScaler("5. Mode_17", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT3 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x00,0x00,0x00,0x00,0x1F,0xF8,0x00,0x00,
    	    	    	                            0x9E,0xC4,0xA2,0x64,0xD4,0xD2,0x00,0x00) << 1));


    // miniLVDS + Single 6 + type1(CMO)
    DebugMessageScaler("5. Mode_18", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x02,
                                                    0x88,0xF2,0xF5,0x0E,0xD2,0x51,0x00,0x00,
    	    	    	                            0x00,0x00,0x55,0x1A,0x8D,0xDF,0x81,0x9D) << 2));


    // miniLVDS + Single 6 + type2(AUO)
    DebugMessageScaler("5. Mode_19", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT3 | _BIT1));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x88,0xF2,0xF5,0x0E,0xD2,0x51,0x00,0x00,
    	    	    	                            0x07,0x02,0x55,0x1A,0x8D,0xDF,0x81,0x9D) << 3));


    // miniLVDS + Dual 3 + type1(CMO)
    DebugMessageScaler("5. Mode_20", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x02,
                                                    0x2D,0x8F,0x90,0x99,0xD2,0xF9,0x00,0x00,
    	    	    	                            0x07,0x02,0x2A,0x35,0xFB,0xF7,0xD6,0xA7) << 4));


    // miniLVDS + Dual 3 + type2(AUO)
    DebugMessageScaler("5. Mode_21", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT3 | _BIT1 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x2D,0x8F,0x07,0x02,
                                                    0x90,0x99,0xD2,0xF9,0x2A,0x35,0x00,0x00,
    	    	    	                            0x07,0x02,0xFB,0xF7,0xD6,0xA7,0x00,0x00) << 5));

    // miniLVDS + Single 3 + type1(CMO)
    DebugMessageScaler("5. Mode_22", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), _BIT7);    	    // PN Swap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT0));    	    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));    	    


    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x97,0xD6,0x94,0x0B,0xDD,0x71,0x00,0x00,
    	    	    	                            0x9E,0xC4,0x00,0x00,0x00,0x00,0x00,0x00) << 6));

    // miniLVDS + Single 3 + type2(AUO)
    DebugMessageScaler("5. Mode_23", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x00,0x00,0x00,0x00,0x97,0xD6,0x00,0x00,
    	    	    	                            0x9E,0xC4,0x94,0x0B,0xDD,0x71,0x00,0x00) << 7));

    // miniLVDS + Single 6 + type1(CMO)
    DebugMessageScaler("5. Mode_24", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x6F,0x02,0xA6,0xC7,
                                                    0xD7,0x91,0x00,0x00,0xA9,0x70,0x00,0x00,
    	    	    	                            0x61,0x6C,0x60,0x0D,0x07,0x02,0x00,0x00) << 0));

    // miniLVDS + Single 6 + type2(AUO)
    DebugMessageScaler("5. Mode_25", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT1));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x6F,0x02,0xA6,0xC7,0xD7,0x91,0x00,0x00,
    	    	    	                            0x07,0x02,0xA9,0x70,0x61,0x6C,0x60,0x0D) << 1));


    // miniLVDS + Dual 3 + type1(CMO)
    DebugMessageScaler("5. Mode_26", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0xFD,0xDD,0x7F,0xFD,
                                                    0x75,0xEC,0x07,0x02,0x76,0x00,0x00,0x00,
    	    	    	                            0x2D,0xE1,0xCA,0xE7,0x07,0x02,0x00,0x00) << 2));


    // miniLVDS + Dual 3 + type2(AUO)
    DebugMessageScaler("5. Mode_27", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT1 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x76,0x00,
                                                    0x2D,0xE1,0x07,0x02,0xCA,0xE7,0x00,0x00,
    	    	    	                            0xFD,0xDD,0x7F,0xFD,0x07,0x02,0x75,0xEC) << 3));

    // miniLVDS + Dual 3 + type1(CMO)
    DebugMessageScaler("5. Mode_28", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0xA8,0x00,0x7E,0x35,
                                                    0x61,0xF2,0x07,0x02,0x76,0x00,0x00,0x00,
    	    	    	                            0x2D,0xE1,0xCA,0xE7,0x07,0x02,0x00,0x00) << 4));


    // miniLVDS + Dual 3 + type2(AUO)
    DebugMessageScaler("5. Mode_29", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x76,0x00,
                                                    0x2D,0xE1,0x07,0x02,0xCA,0xE7,0x00,0x00,
    	    	    	                            0xA8,0x00,0x7E,0x35,0x07,0x02,0x61,0xF2) << 5));

    // miniLVDS + Single 3 + type1(CMO)
    DebugMessageScaler("5. Mode_30", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), (_BIT5 | _BIT4));    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT0));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x03,0x0D,0x8D,0xF3,0x44,0x44,0x00,0x00,
    	    	    	                            0x57,0xC4,0x00,0x00,0x00,0x00,0x00,0x00) << 6));

    // miniLVDS + Single 3 + type2(AUO)
    DebugMessageScaler("5. Mode_31", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0x00,0x00,0x00,0x00,0x03,0x0D,0x00,0x00,
    	    	    	                            0x57,0xC4,0x8D,0xF3,0x44,0x44,0x00,0x00) << 7));


    // miniLVDS + Single 6 + type1(CMO)
    DebugMessageScaler("5. Mode_32", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT1));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0xFD,0x20,0x22,0xD4,
                                                    0xE5,0x41,0x00,0x00,0x3A,0x02,0x00,0x00,
    	    	    	                            0xC8,0xB5,0x2C,0x17,0xBC,0x8C,0x00,0x00) << 0));


    // miniLVDS + Single 6 + type2(AUO)
    DebugMessageScaler("5. Mode_33", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT1));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                                    0xFD,0x20,0x22,0xD4,0xE5,0x41,0x00,0x00,
    	    	    	                            0xBC,0x8C,0x3A,0x02,0xC8,0xB5,0x2C,0x17) << 1));

    // miniLVDS + Dual 3 + type1(CMO)
    DebugMessageScaler("5. Mode_34", 0x00);
    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT1 | _BIT0));    	    

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x77,0xA6,0xA4,0xFF,
                                                    0x92,0x61,0xBC,0x8C,0xC2,0x74,0x00,0x00,
    	    	    	                            0x61,0x28,0x42,0x24,0xBC,0x8C,0x00,0x00) << 2));


    // miniLVDS + Dual 3 + type2(AUO)
    DebugMessageScaler("5. Mode_35", 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT1 | _BIT0));    	

    ucData = (ucData | ((BYTE)ScalerQCminiLVDSCRCOn(0x00,0x00,0x00,0x00,0x00,0x00,0xC2,0x74,
                                                    0x61,0x28,0xBC,0x8C,0x42,0x24,0x00,0x00,
    	    	    	                            0x77,0xA6,0xA4,0xFF,0xBC,0x8C,0x92,0x61) << 3));
*/

    ScalerSetBit(CM_29_VDISP_SIGINV, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    	  // RLSwap, RBSwap, MLSwap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7), 0x00);    	    // PN Swap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_26_MLVDS_CTRL0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));    	    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_2B_MLVDS_CTRL3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), (_BIT0));    	// LVDS
    ScalerQCIDomainRandomGenOff();
    ScalerQCminiLVDSCRCOff();

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
// Description  : Set VGIP Mask Active Space
// Input Value  : mask start pos and length
// Output Value : None
//--------------------------------------------------
void ScalerQCVgipMaskActiveSpace(EnumVgipMaskActiveSpaceNum enumActiveSpaceNum, WORD usPosition, WORD usLength)
{
    switch(enumActiveSpaceNum)
    {
        case _VGIP_MASK_ACTIVE_SPACE_0:

            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_20_ACTIVE_SPACE_LINE0_M, (((HIBYTE(usLength) & 0x0F) << 4) | ((HIBYTE(usPosition) & 0x0F))));
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_21_ACTIVE_SPACE_LINE0_L, LOBYTE(usPosition));
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_22_ACTIVE_SPACE_LEN0_L, LOBYTE(usLength));
            
            break;
            
        case _VGIP_MASK_ACTIVE_SPACE_1:

            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_23_ACTIVE_SPACE_LINE1_M, (((HIBYTE(usLength) & 0x0F) << 4) | ((HIBYTE(usPosition) & 0x0F))));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_24_ACTIVE_SPACE_LINE1_L, LOBYTE(usPosition));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_25_ACTIVE_SPACE_LEN1_L, LOBYTE(usLength));                  

            break;

        case _VGIP_MASK_ACTIVE_SPACE_2:
            
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_26_ACTIVE_SPACE_LINE2_M, (((HIBYTE(usLength) & 0x0F) << 4) | ((HIBYTE(usPosition) & 0x0F))));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_27_ACTIVE_SPACE_LINE2_L, LOBYTE(usPosition));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_28_ACTIVE_SPACE_LEN2_L, LOBYTE(usLength));                              

            break;

        case _VGIP_MASK_ACTIVE_SPACE_3:

            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_29_ACTIVE_SPACE_LINE3_M, (((HIBYTE(usLength) & 0x0F) << 4) | ((HIBYTE(usPosition) & 0x0F))));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2A_ACTIVE_SPACE_LINE3_L, LOBYTE(usPosition));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2B_ACTIVE_SPACE_LEN3_L, LOBYTE(usLength));                              

            break;

        default:
            break;
    }
}

bit ScalerQCScaleDownTest(void)
{
    WORD usData = 0;   

    DebugMessageScaler("5. Scale down Start", 0x00);

    // Clear Input Status
    ScalerSetBit(CM_03_STATUS1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
    
    ScalerQCIDomainRandomGenOn(_MASS);
    
    // **************************************//
    // mask 100 for pr interlace pr
    // **************************************//
    DebugMessageScaler("5. Mode_0", 0x00);
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_0, 265, 6);
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_1, 536, 544);
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_2, 0, 544);
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_3, 809, 6);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, _BIT3 | _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 1);

    // v factor 0x21EB9 530->500
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x1E);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xB9);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x04);

    // h factor 0x124925
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x25);    

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7 | _BIT6 | (0x20));

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), _BIT4);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(530));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(530));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(500));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(500));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckFSCrc(tQC_SCALEDOWN_MODE0_CRC, sizeof(tQC_SCALEDOWN_MODE0_CRC) / 3,  _I_DOMAIN_CRC, 1) << 0));
    
    // Get Input Status
    if(ScalerGetBit(CM_03_STATUS1, (_BIT2 | _BIT1 | _BIT0)) != (_BIT2 | _BIT1 | _BIT0))
    {
        DebugMessageScaler("6. Fail Mode - No Input!!", 0x00);
        DebugMessageScaler("6. Scale down FAIL", 0x00);    
        return _TEST_FAIL;
    }
    
    // **************************************//
    // mask 101 for shutter
    // **************************************//
    DebugMessageScaler("5. Mode_1", 0x00);
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_0, 535, 545);
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_1, 0, 545);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, _BIT3 | _BIT1 | _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 2);

    // v factor 0x223D7 535->500
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x23);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xD7);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x00);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(540));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(540));
         
    usData = (usData | ((BYTE)ScalerQCCheckFSCrc(tQC_SCALEDOWN_MODE1_CRC, sizeof(tQC_SCALEDOWN_MODE1_CRC) / 3,  _I_DOMAIN_CRC, 1) << 1));

    // **************************************//
    // mask 110 for sbs shutter
    // **************************************//
    DebugMessageScaler("5. Mode_2", 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, _BIT6 | _BIT3 | _BIT2 | _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x10);

    // v factor 0x20EA1 1080->1050
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x0E);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xA1);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x00);

    // h factor 0x124925 960->900
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x11);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x11);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x12);    

    // H SBS Reset 960
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x03);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0xC0);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x00);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(960));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(960));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1080));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1080));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(900));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(900));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1050));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1050));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckFSCrc(tQC_SCALEDOWN_MODE2_CRC, sizeof(tQC_SCALEDOWN_MODE2_CRC) / 3,  _I_DOMAIN_CRC, 1) << 2));

    // **************************************//
    // mask 111 for interleave shutter
    // **************************************//
    DebugMessageScaler("5. Mode_3", 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL,   _BIT3 | _BIT2 | _BIT1 | _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x10);

    // v factor 0x228F6 540->500
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x28);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xF6);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x00);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x25);    

    // H SBS Reset
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x00);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(540));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(540));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(500));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(500));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckFSCrc(tQC_SCALEDOWN_MODE3_CRC, sizeof(tQC_SCALEDOWN_MODE3_CRC) / 3,  _I_DOMAIN_CRC, 1) << 3));

    // **************************************//
    // input frame sequential ,for pr
    // **************************************//
    DebugMessageScaler("5. Mode_4", 0x00);
    // product LR Signal
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_0, 0, 0);
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_1, 0, 0);    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL,   _BIT3 |  _BIT1 | _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x3F);

    // v factor 0x41D42 1080->525
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x04);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x1D);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0x42);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x00);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x25);    

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7 | _BIT6);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x00);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1080));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1080));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(525));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(525));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckFSCrc(tQC_SCALEDOWN_MODE4_CRC, sizeof(tQC_SCALEDOWN_MODE4_CRC) / 3,  _I_DOMAIN_CRC, 1) << 4));

    // **************************************//
    // 2D
    // **************************************//
    DebugMessageScaler("5. Mode_5", 0x00); 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL,   0x00);

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

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, 0x00);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x00);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1080));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1080));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1050));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1050));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckCRCOn(0x0D, 0x3C, 0xCF, _I_DOMAIN_CRC) << 5));

    // **************************************//
    // FP2 Mask000, PR
    // **************************************//
    DebugMessageScaler("5. Mode_6", 0x00);
    // product LR Signal
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_0, 535, 10);        
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x20);

    // v factor 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x09);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xC1);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x04);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x25);    

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7 | _BIT6);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), _BIT4);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1070));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1070));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1050));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1050));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckCRCOn(0xF7, 0x69, 0x74, _I_DOMAIN_CRC) << 6));

    // **************************************//
    // FP2 Mask001, PR
    // **************************************//
    DebugMessageScaler("5. Mode_7", 0x00);
    // product LR Signal
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_0, 535, 5); 
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_1, 1075, 5);       
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, _BIT1 | _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x20);

    // v factor 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x09);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xC1);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x04);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x25);    

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7 | _BIT6);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), _BIT4);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1070));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1070));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1050));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1050));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckCRCOn(0xA3, 0x80, 0xE3, _I_DOMAIN_CRC) << 7));

    // **************************************//
    // FP2 Mask010, PR
    // **************************************//
    DebugMessageScaler("5. Mode_8", 0x00);
    // product LR Signal
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_0, 0, 5); 
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_1, 540, 5);       
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, _BIT2 | _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x20);

    // v factor 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x09);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xC1);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x04);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x25);    

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7 | _BIT6);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), _BIT4);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1070));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1070));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1050));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1050));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckCRCOn(0xC7, 0x7B, 0x67, _I_DOMAIN_CRC) << 8));

    // **************************************//
    // FP4 Mask011, Video conpensation, PR
    // **************************************//
    DebugMessageScaler("5. Mode_9", 0x00);
    // product LR Signal
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_0, 267, 4); 
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_1, 538, 4); 
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_2, 809, 4);      
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, _BIT2 | _BIT1 | _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x20);

    // v factor 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x09);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xC6);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x04);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x25);    

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7 | _BIT6);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), _BIT5);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1068));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1068));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1048));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1048));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT2 | _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckCRCOn(0x8D, 0xF8, 0x8C, _I_DOMAIN_CRC) << 9));

    // **************************************//
    // tnb Mask000, PR
    // **************************************//
    DebugMessageScaler("5. Mode_10", 0x00);
    // product LR Signal
    ScalerQCVgipMaskActiveSpace(_VGIP_MASK_ACTIVE_SPACE_0, 540, 0);       
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, _BIT0); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x00);

    // v factor 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x0E);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xA1);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x04);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x25);    

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), _BIT4);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1080));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1080));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1050));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1050));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckCRCOn(0x03, 0xD2, 0x5E, _I_DOMAIN_CRC) << 10));

    // **************************************//
    // sbs, PR
    // **************************************//
    DebugMessageScaler("5. Mode_11", 0x00);          
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, 0x00); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x00);

    // v factor 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x04);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x1D);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0x42);

    //h L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x00);

    // h factor 0x124925 1920->1680
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x10);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x2B);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x1E);    

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, _BIT4 | HIBYTE(960));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, LOBYTE(960));

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7 | _BIT6 | 0x3F);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), _BIT5 | _BIT4);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(960));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(960));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(2160));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(2160));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(950));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(950));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1050));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1050));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, _BIT7);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckCRCOn(0x11, 0xDC, 0xA8, _I_DOMAIN_CRC) << 11));

    // **************************************//
    // sbs, quin R01 L10, PR
    // **************************************//
    DebugMessageScaler("5. Mode_12", 0x00);          
    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, _BIT6 | 0x2F);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x0D);
       
    usData = (usData | ((BYTE)ScalerQCCheckCRCOn(0x19,0x06,0xA3, _I_DOMAIN_CRC) << 12));

    // **************************************//
    // Line interleave, PR
    // **************************************//
    DebugMessageScaler("5. Mode_13", 0x00);          
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, 0x00); 

    // v L phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x01);

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

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, _BIT7);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x00);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1080));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1080));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1050));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1050));     

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, _BIT7);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);    

    usData = (usData | ((BYTE)ScalerQCCheckCRCOn(0xFB, 0x77, 0x90, _I_DOMAIN_CRC) << 13));


    // Recovery
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x0E);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0xA1);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x12);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x49);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x45);    

    // Enable I domain share display line buffer & MAC when vertical scale down
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5); 

    // mask
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, 0x00); 

    // H R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, 0x00);

    // H Quincunx ctrl
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, 0x00);

    // H SBS Reset 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, 0x00);

    // v R phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, 0x00);

    // Input format
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x00);    

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(1920));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(1080));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(1080));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(1680));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(1680));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(1050));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(1050));

    // Enable H Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);    

    // Enable V Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);   

    ScalerTimerWaitForEvent(_EVENT_DVS);    	    	
    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerSetByte(CM_02_STATUS0, 0x00);
    ScalerSetByte(CM_03_STATUS1, 0x00);

    ScalerQCIDomainRandomGenOff();
    ScalerQCCheckCRCOff(); 

    DebugMessageScaler("5. Scale down End", 0x00); 
    if(usData == 0x00)
    {
        DebugMessageScaler("6. Scale down PASS", 0x00);    
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", usData);
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

//--------------------------------------------------
// Description  : IDomain YUVtoRGB Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCIDomainYUVtoRGBTest(void)
{
    BYTE ucData = 0;
    
    DebugMessageScaler("5. IDomain YUVtoRGB Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);
    
    // K11 High Byte
    ScalerSetByte(P1A_A2_YUV_RGB_COEF_K11_HSB, 0x04);
    // K11 Low Byte
    ScalerSetByte(P1A_A3_YUV_RGB_COEF_K11_LSB, 0xA8);
    
    // K13 High Byte
    ScalerSetByte(P1A_A4_YUV_RGB_COEF_K13_HSB, 0x06);
    // K13 Low Byte
    ScalerSetByte(P1A_A5_YUV_RGB_COEF_K13_LSB, 0x87);

    // K22 High Byte
    ScalerSetByte(P1A_A6_YUV_RGB_COEF_K22_HSB, 0x01);
    // K22 Low Byte
    ScalerSetByte(P1A_A7_YUV_RGB_COEF_K22_LSB, 0x91);
    
    // K23 High Byte
    ScalerSetByte(P1A_A8_YUV_RGB_COEF_K23_HSB, 0x03);
    // K23 Low Byte
    ScalerSetByte(P1A_A9_YUV_RGB_COEF_K23_LSB, 0x40);

    // K32 High Byte
    ScalerSetByte(P1A_AA_YUV_RGB_COEF_K32_HSB, 0x08);
    // K32 Low Byte
    ScalerSetByte(P1A_AB_YUV_RGB_COEF_K32_LSB, 0x11);

    // R Offset High Byte
    ScalerSetByte(P1A_AC_YUV_RGB_R_OFFSET_HSB, 0x0E);
    // R Offset Low Byte
    ScalerSetByte(P1A_AD_YUV_RGB_R_OFFSET_LSB, 0x0A);

    // G Offset High Byte
    ScalerSetByte(P1A_AE_YUV_RGB_G_OFFSET_HSB, 0x0A);
    // G Offset Low Byte
    ScalerSetByte(P1A_AF_YUV_RGB_G_OFFSET_LSB, 0x92);

    // B Offset High Byte
    ScalerSetByte(P1A_B0_YUV_RGB_B_OFFSET_HSB, 0x11);
    // B Offset Low Byte
    ScalerSetByte(P1A_B1_YUV_RGB_B_OFFSET_LSB, 0x18);

    // R Gain High Byte
    ScalerSetByte(P1A_B2_YUV_RGB_R_GAIN_HSB, 0x00);
    // R Gain Low Byte
    ScalerSetByte(P1A_B3_YUV_RGB_R_GAIN_LSB, 0xB9);

    // G Gain High Byte
    ScalerSetByte(P1A_B4_YUV_RGB_G_GAIN_HSB, 0x00);
    // G Gain Low Byte
    ScalerSetByte(P1A_B5_YUV_RGB_G_GAIN_LSB, 0xDA);

    // B Gain High Byte
    ScalerSetByte(P1A_B6_YUV_RGB_B_GAIN_HSB, 0x00);
    // B Gain Low Byte
    ScalerSetByte(P1A_B7_YUV_RGB_B_GAIN_LSB, 0xA2);

    // Enable Y signed, Y clamp, CbCr clamp
    ScalerSetBit(P1A_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT3 | _BIT2 | _BIT1);
    
    // Enable YUV2RGB & Cyberlink Modification Data Content
    ScalerSetBit(P1A_A0_IFC_GENERAL, ~(_BIT7 | _BIT3), _BIT7 | _BIT3);
    
    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x8A, 0xBC, 0x85, _I_DOMAIN_CRC) << 0));
    
    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xD7, 0x4A, 0x62, _I_DOMAIN_CRC) << 1));
    
    // Disable Y signed, Y clamp, CbCr clamp
    ScalerSetBit(P1A_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1), 0x00);
    
    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xB1, 0x5A, 0xB7, _I_DOMAIN_CRC) << 2));
    
    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x0C, 0x4A, 0x45, _I_DOMAIN_CRC) << 3));

    // Disable YUV2RGB & Cyberlink Modification Data Content
    ScalerSetBit(P1A_A0_IFC_GENERAL, ~(_BIT7 | _BIT3), 0x00);

    ScalerQCIDitherOff();
    ScalerQCIDomainRandomGenOff();   
    ScalerQCCheckCRCOff();

    DebugMessageScaler("5. IDomain YUVtoRGB End", 0x00);
    if(ucData == 0)
    {
        DebugMessageScaler("6. IDomain YUVtoRGB PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. IDomain YUVtoRGB FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : 2Dto3D Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCTwoThreeDimensionTest(void)
{
    BYTE ucData = 0;
    
    DebugMessageScaler("5. TwoThreeDimension Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);
    
    // Set 2Dto3D output format - Line interleave (PR)
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT5, _BIT5);

    // Enable double buffer
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT0, 0x00);    

    // Clear input LR signal toggle flag
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT1, _BIT1);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    
    // No LR signal
    if(ScalerGetBit(P1C_A1_2D_TO_3D_CTL2, _BIT1) == 0x00)
    {
        // L/R flag reference to self generation
        ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT3, _BIT3);
    }
    else // LR signal occurs
    {
        // L/R flag reference to original
        ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT3, 0x00);
    }
    
    // Set chroma weight and depth gain
    ScalerSetByte(P1C_A2_2D_TO_3D_CTL3, 0xBF);
    
    // Select LPF weighting
    ScalerSetByte(P1C_A3_2D_TO_3D_CTL4, 0x63);                
    ScalerSetByte(P1C_A4_2D_TO_3D_CTL5, 0x20);
    // Enable LPF
    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT6, _BIT6);
    
    // Set rendering mode - repeat left and current pixel
    ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~_BIT0, _BIT0);

    // Enable depth mode
    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT4, _BIT4);
            
    // Double buffer ready 
    ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT7, _BIT7);

    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x97, 0xCE, 0x47, _I_DOMAIN_CRC) << 0));

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xBB, 0x1C, 0x47, _I_DOMAIN_CRC) << 1));
  
    // Set rendering mode - repeat left pixel
    ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~_BIT0, 0x00);
    
    // Enable fraction mode
    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT7, _BIT7);

    // Enable depth sign
    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT5, _BIT5);
    
    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x20, 0x8D, 0x54, _I_DOMAIN_CRC) << 2));
    
    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xFF, 0x19, 0xCA, _I_DOMAIN_CRC) << 3));
    
    // Set 2Dto3D output format - Frame sequential (Shutter)
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT5, 0x00);

    // Set rendering mode - repeat left and current pixel
    ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~_BIT0, _BIT0);

    // Disable fraction mode
    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT7, 0x00);

    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_4", 0x00);
    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x01);    
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);    
    pData[0] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[1] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[2] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    ScalerTimerWaitForEvent(_EVENT_IVS);    
    pData[3] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[4] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[5] = ScalerGetByte(CM_2D_OP_CRC_CKSM);    
    if(((pData[0] == 0x86) && (pData[1] == 0x8F) && (pData[2] == 0xA0) && (pData[3] == 0x24) && (pData[4] == 0x4A) && (pData[5] == 0x93)) ||
       ((pData[3] == 0x86) && (pData[4] == 0x8F) && (pData[5] == 0xA0) && (pData[0] == 0x24) && (pData[1] == 0x4A) && (pData[2] == 0x93)))
    {
        DebugMessageScaler("5. ===Pass===", 0x00);
    }
    else
    {
        DebugMessageScaler("5. ===pData[0]===", pData[0]); 
        DebugMessageScaler("5. ===pData[1]===", pData[1]); 
        DebugMessageScaler("5. ===pData[2]===", pData[2]); 
        DebugMessageScaler("5. ===pData[3]===", pData[3]); 
        DebugMessageScaler("5. ===pData[4]===", pData[4]); 
        DebugMessageScaler("5. ===pData[5]===", pData[5]);         
        DebugMessageScaler("5. ===Fail===", 0x00);            
        ucData = (ucData | _BIT4);
    }        
  
    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_5", 0x00);

    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x01);    
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);    
    pData[0] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[1] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[2] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    ScalerTimerWaitForEvent(_EVENT_IVS);    
    pData[3] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[4] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[5] = ScalerGetByte(CM_2D_OP_CRC_CKSM);    
    if(((pData[0] == 0xF7) && (pData[1] == 0xD5) && (pData[2] == 0xDA) && (pData[3] == 0x23) && (pData[4] == 0x2A) && (pData[5] == 0x67)) ||
       ((pData[3] == 0xF7) && (pData[4] == 0xD5) && (pData[5] == 0xDA) && (pData[0] == 0x23) && (pData[1] == 0x2A) && (pData[2] == 0x67)))
    {
        DebugMessageScaler("5. ===Pass===", 0x00);
    }
    else
    {
        DebugMessageScaler("5. ===pData[0]===", pData[0]); 
        DebugMessageScaler("5. ===pData[1]===", pData[1]); 
        DebugMessageScaler("5. ===pData[2]===", pData[2]); 
        DebugMessageScaler("5. ===pData[3]===", pData[3]); 
        DebugMessageScaler("5. ===pData[4]===", pData[4]); 
        DebugMessageScaler("5. ===pData[5]===", pData[5]);         
        DebugMessageScaler("5. ===Fail===", 0x00);            
        ucData = (ucData | _BIT5);
    }

    // Shift Step
    ScalerSetByte(P1C_A0_2D_TO_3D_CTL1, 0x10);

    // L Offset
    ScalerSetByte(P1C_A6_2D_TO_3D_CTL7, 0x00);
    ScalerSetByte(P1C_A7_2D_TO_3D_CTL8, 0x05);
    
    // R Offset
    ScalerSetByte(P1C_A8_2D_TO_3D_CTL9, 0x00);
    ScalerSetByte(P1C_A9_2D_TO_3D_CTL10, 0x03);
    
    // L Initial Phase
    ScalerSetByte(P1C_AA_2D_TO_3D_CTL11, 0x2B);
    
    // R Initial Phase
    ScalerSetByte(P1C_AB_2D_TO_3D_CTL12, 0x1C);
    
    // Capture Width
    ScalerSetByte(P1C_AC_2D_TO_3D_CTL13, 0x04);
    ScalerSetByte(P1C_AD_2D_TO_3D_CTL14, 0x00);
    
    // Enable shift mode
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, _BIT6);

    // Double buffer ready 
    ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT7, _BIT7);

    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_6", 0x00);

    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x01);    
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);    
    pData[0] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[1] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[2] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    ScalerTimerWaitForEvent(_EVENT_IVS);    
    pData[3] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[4] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[5] = ScalerGetByte(CM_2D_OP_CRC_CKSM);    
    if(((pData[0] == 0x4D) && (pData[1] == 0xC2) && (pData[2] == 0x61) && (pData[3] == 0xF9) && (pData[4] == 0xA1) && (pData[5] == 0x54)) ||
       ((pData[3] == 0x4D) && (pData[4] == 0xC2) && (pData[5] == 0x61) && (pData[0] == 0xF9) && (pData[1] == 0xA1) && (pData[2] == 0x54)))
    {
        DebugMessageScaler("5. ===Pass===", 0x00);
    }
    else
    {
        DebugMessageScaler("5. ===pData[0]===", pData[0]); 
        DebugMessageScaler("5. ===pData[1]===", pData[1]); 
        DebugMessageScaler("5. ===pData[2]===", pData[2]); 
        DebugMessageScaler("5. ===pData[3]===", pData[3]); 
        DebugMessageScaler("5. ===pData[4]===", pData[4]); 
        DebugMessageScaler("5. ===pData[5]===", pData[5]); 
        DebugMessageScaler("5. ===Fail===", 0x00);            
        ucData = (ucData | _BIT6);
    }    

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_7", 0x00);

    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x00);
    ScalerSetByte(CM_2C_OP_CRC_CTRL, 0x01);    
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);    
    pData[0] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[1] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[2] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    ScalerTimerWaitForEvent(_EVENT_IVS);    
    pData[3] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[4] = ScalerGetByte(CM_2D_OP_CRC_CKSM);
    pData[5] = ScalerGetByte(CM_2D_OP_CRC_CKSM);    
    if(((pData[0] == 0x94) && (pData[1] == 0x65) && (pData[2] == 0xB3) && (pData[3] == 0xC6) && (pData[4] == 0x9F) && (pData[5] == 0xD7)) ||
       ((pData[3] == 0x94) && (pData[4] == 0x65) && (pData[5] == 0xB3) && (pData[0] == 0xC6) && (pData[1] == 0x9F) && (pData[2] == 0xD7)))
    {
        DebugMessageScaler("5. ===Pass===", 0x00);
    }
    else
    {
        DebugMessageScaler("5. ===pData[0]===", pData[0]); 
        DebugMessageScaler("5. ===pData[1]===", pData[1]); 
        DebugMessageScaler("5. ===pData[2]===", pData[2]); 
        DebugMessageScaler("5. ===pData[3]===", pData[3]); 
        DebugMessageScaler("5. ===pData[4]===", pData[4]); 
        DebugMessageScaler("5. ===pData[5]===", pData[5]);         
        DebugMessageScaler("5. ===Fail===", 0x00);            
        ucData = (ucData | _BIT7);
    }

    // Shift Step
    ScalerSetByte(P1C_A0_2D_TO_3D_CTL1, 0x00);

    // Disable depth mode
    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT4, 0x00);
    
    // Disable shift mode
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, 0x00);
            
    // Double buffer ready 
    ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT7, _BIT7);

    ScalerQCIDitherOff();
    ScalerQCIDomainRandomGenOff();   
    ScalerQCCheckCRCOff();

    DebugMessageScaler("5. TwoThreeDimension End", 0x00);
    if(ucData == 0)
    {
        DebugMessageScaler("6. TwoThreeDimension PASS", 0x00);
    	return _TEST_PASS;
    }
    else
    {    
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. TwoThreeDimension FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Depth Of Field Test 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCDepthOfFieldTest(void)
{
    BYTE ucData = 0;
    BYTE ucCRC[3] = 0;
    
    DebugMessageScaler("5. DepthOfField Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);
    
    // Enable double buffer
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT0, 0x00);
    
    // Clear input LR signal toggle flag
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT1, _BIT1);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    
    // No LR signal
    if(ScalerGetBit(P1C_A1_2D_TO_3D_CTL2, _BIT1) == 0x00)
    {
        // L/R flag reference to self generation
        ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT3, _BIT3);
    }
    else // LR signal occurs
    {
        // L/R flag reference to original
        ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT3, 0x00);
    }
    
    // Support line interleave input format
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT2, 0x00);
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT3, _BIT3);
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT4, 0x00);
    
    // L Offset
    ScalerSetByte(P1C_A6_2D_TO_3D_CTL7, 0x00);
    ScalerSetByte(P1C_A7_2D_TO_3D_CTL8, 0x05);
    
    // R Offset
    ScalerSetByte(P1C_A8_2D_TO_3D_CTL9, 0x00);
    ScalerSetByte(P1C_A9_2D_TO_3D_CTL10, 0x03);
    
    // L Initial Phase
    ScalerSetByte(P1C_AA_2D_TO_3D_CTL11, 0x2B);
    
    // R Initial Phase
    ScalerSetByte(P1C_AB_2D_TO_3D_CTL12, 0x1C);
    
    // Capture Width
    ScalerSetByte(P1C_AC_2D_TO_3D_CTL13, 0x04);
    ScalerSetByte(P1C_AD_2D_TO_3D_CTL14, 0xF6);
    
    // Enable shift mode
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, _BIT6);
    
    // Double buffer ready 
    ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT7, _BIT7);

    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x40, 0xBC, 0x0E, _I_DOMAIN_CRC) << 0));

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xB1, 0xDC, 0x1F, _I_DOMAIN_CRC) << 1));

    // Support top-and-bottom and frame-packing input format
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT2, 0x00);
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT3, 0x00);
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT4, _BIT4);
    
    // Scale down for top-and-bottom setting 
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_20_ACTIVE_SPACE_LINE0_M, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_21_ACTIVE_SPACE_LINE0_L, 0x00);
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, ~_BIT0, _BIT0);
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x10);

    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF6, 0x13, 0x0D, _I_DOMAIN_CRC) << 2));

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x4F, 0x4D, 0x54, _I_DOMAIN_CRC) << 3));

    // Scale down for frame-packing setting
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_22_ACTIVE_SPACE_LEN0_L, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_20_ACTIVE_SPACE_LINE0_M, 0x02);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_21_ACTIVE_SPACE_LINE0_L, 0x00);
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, ~_BIT0, _BIT0);
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x10);

    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xF6, 0x13, 0x0D, _I_DOMAIN_CRC) << 4));

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_5", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x4F, 0x4D, 0x54, _I_DOMAIN_CRC) << 5));

    // Support side-by-side input format
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT2, _BIT2);
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT3, 0x00);
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT4, 0x00);

    // Capture Width
    ScalerSetByte(P1C_AC_2D_TO_3D_CTL13, 0x02);
    ScalerSetByte(P1C_AD_2D_TO_3D_CTL14, 0x70);

    // Capture Width (SBS)
    ScalerSetByte(P1C_AE_2D_TO_3D_CTL15, 0x02);
    ScalerSetByte(P1C_AF_2D_TO_3D_CTL16, 0x80);

    // Double buffer ready 
    ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT7, _BIT7);

    // Check CRC
    ScalerQCIDitherOn(_MSB);
    DebugMessageScaler("5. Mode_6", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0x81, 0x9B, 0x70, _I_DOMAIN_CRC) << 6));

    ScalerQCIDitherOn(_LSB);
    DebugMessageScaler("5. Mode_7", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCheckCRCOn(0xA6, 0x8F, 0x96, _I_DOMAIN_CRC) << 7));
    
    // Disable shift mode
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, 0x00);

    ScalerSetByte(P1C_A1_2D_TO_3D_CTL2, 0x00); 
    ScalerSetByte(P1C_A5_2D_TO_3D_CTL6, 0x00);
    
    // Double buffer ready 
    ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT7, _BIT7);

    ScalerQCIDitherOff();
    ScalerQCIDomainRandomGenOff();   
    ScalerQCCheckCRCOff();

    DebugMessageScaler("5. DepthOfField End", 0x00);
    if(ucData == 0)
    {
        DebugMessageScaler("6. DepthOfField PASS", 0x00);
    	return _TEST_PASS;
    }
    else
    {
        DebugMessageScaler("6. Fail Mode", ucData);
        DebugMessageScaler("6. DepthOfField FAIL", 0x00);
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
            DebugMessageScaler("5. DP Abuf Bist Fail", 0x00);
            ucResult |= _BIT1;
        }
    }
    else
    {
        DebugMessageScaler("5. DP Abuf Bist Fail", 0x00);
        ucResult |= _BIT1;
    }

    // Test HDCP BIST
    ScalerSetBit(PC_E9_DP_HDCP_BIST, ~_BIT2, _BIT2);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, PC_E9_DP_HDCP_BIST, _BIT1, _BIT1) == _TRUE)
    {
        if(ScalerGetBit(PC_E9_DP_HDCP_BIST, _BIT0) != 0x00)
        {
            DebugMessageScaler("5. DP Abuf Bist Fail", 0x00);
            ucResult |= _BIT3;
        }
    }
    else
    {
        DebugMessageScaler("5. DP Abuf Bist Fail", 0x00);
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

//-------------------------------------------------- 
// Description  : FPGA for mLVDS6x configuration setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/*
void ScalerQCFPGA6xTable(void)
{
    ScalerQCFPGASetByte(0x00, 0x40);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x00, 0x41);
    ScalerTimerDelayXms(50);
    ScalerQCFPGASetByte(0x01, 0x05);
    ScalerQCFPGASetByte(0x02, 0x58);
    ScalerTimerDelayXms(20);

    ScalerQCFPGASetByte(0x30, 0x95);//10_E2-    //8_E0-
    ScalerQCFPGASetByte(0x31, 0x87);//10_E2+    //8_E0+
    ScalerQCFPGASetByte(0x32, 0x9A);//10_EC-    //8_E1-
    ScalerQCFPGASetByte(0x33, 0x1B);//10_EC+    //8_E1+
    ScalerQCFPGASetByte(0x34, 0x00);//10_E3-    //8_E2-
    ScalerQCFPGASetByte(0x35, 0x87);//10_E3+    //8_E2+
    ScalerQCFPGASetByte(0x36, 0x00);//10_E0-    //None
    ScalerQCFPGASetByte(0x37, 0x87);//10_E0+    //None
    ScalerQCFPGASetByte(0x38, 0xC8);//10_E1-    //None    //0xF3
    ScalerQCFPGASetByte(0x39, 0xF4);//10_E1+    //None    //0xA3
    ScalerQCFPGASetByte(0x3a, 0xC8);//10_O1-    //8_O0-
    ScalerQCFPGASetByte(0x3b, 0xF4);//10_O1+    //8_O0+
    ScalerQCFPGASetByte(0x3c, 0x4C);//10_O2-    //8_O1-
    ScalerQCFPGASetByte(0x3d, 0xEF);//10_O2+    //8_O1+
    ScalerQCFPGASetByte(0x3e, 0x27);//10_OC-    //8_O2-
    ScalerQCFPGASetByte(0x3f, 0xC3);//10_OC+    //8_O2+
    ScalerQCFPGASetByte(0x40, 0xC8);//10_O4-    //8_O3-
    ScalerQCFPGASetByte(0x41, 0xF4);//10_O4+    //8_O3+
    ScalerQCFPGASetByte(0x42, 0x95);//10_O0-    //8_E3-
    ScalerQCFPGASetByte(0x43, 0x87);//10_O0+    //8_E3+

    ScalerQCFPGASetByte(0x0f, 0x04);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x0f, 0x00);
    ScalerTimerDelayXms(50);
}
*/
//-------------------------------------------------- 
// Description  : FPGA for mLVDS7x configuration setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGA7xTable(void)
{

#if(_LVDS_EO_CLK_MERGE == _ENABLE)
    ScalerQCFPGASetByte(0x00, 0x01);
    ScalerTimerDelayXms(200);
    ScalerQCFPGASetByte(0x00, 0x1E);
    ScalerTimerDelayXms(200);
    ScalerQCFPGASetByte(0x00, 0x3E);
    ScalerTimerDelayXms(200);
    ScalerQCFPGASetByte(0x10, 0x11);
    ScalerTimerDelayXms(50);
#else
    ScalerQCFPGASetByte(0x00, 0x80);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x00, 0x81);
    ScalerTimerDelayXms(50);
    ScalerQCFPGASetByte(0x01, 0x05);
    ScalerQCFPGASetByte(0x02, 0x58);
    ScalerTimerDelayXms(20);

    ScalerQCFPGASetByte(0x30, 0x48);//10_E2-    //8_E0-
    ScalerQCFPGASetByte(0x31, 0x82);//10_E2+    //8_E0+
    ScalerQCFPGASetByte(0x32, 0x47);//10_EC-    //8_E1-
    ScalerQCFPGASetByte(0x33, 0x1E);//10_EC+    //8_E1+
    ScalerQCFPGASetByte(0x34, 0x62);//10_E3-    //8_E2-
    ScalerQCFPGASetByte(0x35, 0xE3);//10_E3+    //8_E2+
    ScalerQCFPGASetByte(0x36, 0x62);//10_E0-    //None
    ScalerQCFPGASetByte(0x37, 0xE3);//10_E0+    //None
    ScalerQCFPGASetByte(0x38, 0xF5);//10_E1-    //None    //0x45
    ScalerQCFPGASetByte(0x39, 0x3F);//10_E1+    //None    //0x4C
    ScalerQCFPGASetByte(0x3a, 0xF5);//10_O1-    //8_O0-
    ScalerQCFPGASetByte(0x3b, 0x3F);//10_O1+    //8_O0+
    ScalerQCFPGASetByte(0x3c, 0x71);//10_O2-    //8_O1-
    ScalerQCFPGASetByte(0x3d, 0x24);//10_O2+    //8_O1+
    ScalerQCFPGASetByte(0x3e, 0xA5);//10_OC-    //8_O2-
    ScalerQCFPGASetByte(0x3f, 0x69);//10_OC+    //8_O2+
    ScalerQCFPGASetByte(0x40, 0xF5);//10_O4-    //8_O3-
    ScalerQCFPGASetByte(0x41, 0x3F);//10_O4+    //8_O3+
    ScalerQCFPGASetByte(0x42, 0x48);//10_O0-    //8_E3-
    ScalerQCFPGASetByte(0x43, 0x82);//10_O0+    //8_E3+

    ScalerQCFPGASetByte(0x0f, 0x04);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x0f, 0x00);
    ScalerTimerDelayXms(50);
#endif

}

//-------------------------------------------------- 
// Description  : FPGA for mLVDS8x configuration setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/*
void ScalerQCFPGA8xTable(void)
{
    ScalerQCFPGASetByte(0x00, 0x00);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x00, 0x01);
    ScalerTimerDelayXms(50);
    ScalerQCFPGASetByte(0x01, 0x05);
    ScalerQCFPGASetByte(0x02, 0x58);
    ScalerTimerDelayXms(20);

    ScalerQCFPGASetByte(0x30, 0xF2);//10_E2-    //8_E0-
    ScalerQCFPGASetByte(0x31, 0x9B);//10_E2+    //8_E0+
    ScalerQCFPGASetByte(0x32, 0xFD);//10_EC-    //8_E1-
    ScalerQCFPGASetByte(0x33, 0x07);//10_EC+    //8_E1+
    ScalerQCFPGASetByte(0x34, 0xD8);//10_E3-    //8_E2-
    ScalerQCFPGASetByte(0x35, 0xFA);//10_E3+    //8_E2+
    ScalerQCFPGASetByte(0x36, 0xD8);//10_E0-    //None
    ScalerQCFPGASetByte(0x37, 0xFA);//10_E0+    //None
    ScalerQCFPGASetByte(0x38, 0x76);//10_E1-    //None    //0xCC
    ScalerQCFPGASetByte(0x39, 0x23);//10_E1+    //None    //0x96
    ScalerQCFPGASetByte(0x3a, 0x76);//10_O1-    //8_O0-
    ScalerQCFPGASetByte(0x3b, 0x23);//10_O1+    //8_O0+
    ScalerQCFPGASetByte(0x3c, 0xF2);//10_O2-    //8_O1-
    ScalerQCFPGASetByte(0x3d, 0x38);//10_O2+    //8_O1+
    ScalerQCFPGASetByte(0x3e, 0x26);//10_OC-    //8_O2-
    ScalerQCFPGASetByte(0x3f, 0x75);//10_OC+    //8_O2+
    ScalerQCFPGASetByte(0x40, 0x76);//10_O4-    //8_O3-
    ScalerQCFPGASetByte(0x41, 0x23);//10_O4+    //8_O3+
    ScalerQCFPGASetByte(0x42, 0xF2);//10_O0-    //8_E3-
    ScalerQCFPGASetByte(0x43, 0x9B);//10_O0+    //8_E3+

    ScalerQCFPGASetByte(0x0f, 0x04);
    ScalerTimerDelayXms(300);
    ScalerQCFPGASetByte(0x0f, 0x00);
    ScalerTimerDelayXms(50);
}
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
    BYTE ucCheck[25];
    
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
    ScalerQCFPGARead(0x16, &ucCheck[11]);
    DebugMessageScaler("5. FPGA_0x16=", ucCheck[11]);
    ScalerQCFPGARead(0x17, &ucCheck[12]);
    DebugMessageScaler("5. FPGA_0x17=", ucCheck[12]);
    ScalerQCFPGARead(0x18, &ucCheck[13]);
    DebugMessageScaler("5. FPGA_0x18=", ucCheck[13]);
    ScalerQCFPGARead(0x19, &ucCheck[14]);
    DebugMessageScaler("5. FPGA_0x19=", ucCheck[14]);
    ScalerQCFPGARead(0x1A, &ucCheck[15]);
    DebugMessageScaler("5. FPGA_0x1A=", ucCheck[15]);
    ScalerQCFPGARead(0x1B, &ucCheck[16]);
    DebugMessageScaler("5. FPGA_0x1B=", ucCheck[16]);
    ScalerQCFPGARead(0x1C, &ucCheck[17]);
    DebugMessageScaler("5. FPGA_0x1C=", ucCheck[17]);
    ScalerQCFPGARead(0x1D, &ucCheck[18]);
    DebugMessageScaler("5. FPGA_0x1D=", ucCheck[18]);
    ScalerQCFPGARead(0x1E, &ucCheck[19]);
    DebugMessageScaler("5. FPGA_0x1E=", ucCheck[19]);
    ScalerQCFPGARead(0x1F, &ucCheck[20]);
    DebugMessageScaler("5. FPGA_0x1F=", ucCheck[20]);
    ScalerQCFPGARead(0x20, &ucCheck[21]);
    DebugMessageScaler("5. FPGA_0x20=", ucCheck[21]);
    ScalerQCFPGARead(0x21, &ucCheck[22]);
    DebugMessageScaler("5. FPGA_0x21=", ucCheck[22]);
    ScalerQCFPGARead(0x22, &ucCheck[23]);
    DebugMessageScaler("5. FPGA_0x22=", ucCheck[23]);
    ScalerQCFPGARead(0x23, &ucCheck[24]);
    DebugMessageScaler("5. FPGA_0x23=", ucCheck[24]);

    if(ucType == _MLVDS6X)
    {
        if((ucCheck[0] == 0x41) && (ucCheck[1] == 0x05) && (ucCheck[2] == 0x58) && (ucCheck[3] == 0x08) && (ucCheck[4] == 0x08) &&
           (ucCheck[5] == 0x95) && (ucCheck[6] == 0x87) && (ucCheck[7] == 0x9A) && (ucCheck[8] == 0x1B) && (ucCheck[9] == 0x00) &&
           (ucCheck[10] == 0x87) && (ucCheck[11] == 0x00) && (ucCheck[12] == 0x87) && (ucCheck[13] == 0xC8) && (ucCheck[14] == 0xF4) &&
           (ucCheck[15] == 0xC8) && (ucCheck[16] == 0xF4) && (ucCheck[17] == 0x4C) && (ucCheck[18] == 0xEF) && (ucCheck[19] == 0x27) &&
           (ucCheck[20] == 0xC3) && (ucCheck[21] == 0xC8) && (ucCheck[22] == 0xF4) && (ucCheck[23] == 0x95) && (ucCheck[24] == 0x87))
        {
            DebugMessageScaler("5. FPGA6x Content Pass", 0x00);
            *pucPass |= _TEST_PASS;
        }
        else
        {
            DebugMessageScaler("5. FPGA6x Content Fail", 0x00);
            *pucPass |= _TEST_FAIL;
        }
    }

    else if(ucType == _MLVDS7X)
    {
        if((ucCheck[0] == 0x81) && (ucCheck[1] == 0x05) && (ucCheck[2] == 0x58) && (ucCheck[3] == 0x08) && (ucCheck[4] == 0x08) &&
           (ucCheck[5] == 0x48) && (ucCheck[6] == 0x82) && (ucCheck[7] == 0x47) && (ucCheck[8] == 0x1E) && (ucCheck[9] == 0x62) &&
           (ucCheck[10] == 0xE3) && (ucCheck[11] == 0x62) && (ucCheck[12] == 0xE3) && (ucCheck[13] == 0xF5) && (ucCheck[14] == 0x3F) &&
           (ucCheck[15] == 0xF5) && (ucCheck[16] == 0x3F) && (ucCheck[17] == 0x71) && (ucCheck[18] == 0x24) && (ucCheck[19] == 0xA5) &&
           (ucCheck[20] == 0x69) && (ucCheck[21] == 0xF5) && (ucCheck[22] == 0x3F) && (ucCheck[23] == 0x48) && (ucCheck[24] == 0x82))
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
    else
    {
        if((ucCheck[0] == 0x01) && (ucCheck[1] == 0x05) && (ucCheck[2] == 0x58) && (ucCheck[3] == 0x08) && (ucCheck[4] == 0x08) &&
           (ucCheck[5] == 0xF2) && (ucCheck[6] == 0x9B) && (ucCheck[7] == 0xFD) && (ucCheck[8] == 0x07) && (ucCheck[9] == 0xD8) &&
           (ucCheck[10] == 0xFA) && (ucCheck[11] == 0xD8) && (ucCheck[12] == 0xFA) && (ucCheck[13] == 0x76) && (ucCheck[14] == 0x23) &&
           (ucCheck[15] == 0x76) && (ucCheck[16] == 0x23) && (ucCheck[17] == 0xF2) && (ucCheck[18] == 0x38) && (ucCheck[19] == 0x26) &&
           (ucCheck[20] == 0x75) && (ucCheck[21] == 0x76) && (ucCheck[22] == 0x23) && (ucCheck[23] == 0xF2) && (ucCheck[24] == 0x9B))
        {
            DebugMessageScaler("5. FPGA8x Content Pass", 0x00);
            *pucPass |= _TEST_PASS;
        }
        else
        {
            DebugMessageScaler("5. FPGA8x Content Fail", 0x00);
            *pucPass |= _TEST_FAIL;
        }
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

        if((ucCheck[0] == 0x7B) && (ucCheck[1] == 0x09) && (ucCheck[2] == 0x60) && (ucCheck[3] == 0xB4) && (ucCheck[4] == 0xCB) && (ucCheck[5] == 0x46))
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

    /*
    ScalerBurstWrite(tQC_MLVDS6X, sizeof(tQC_MLVDS6X), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH); 
    ScalerQCFPGA6xTable();
    ScalerQCFPGAContent(_MLVDS6X, &ucPass);
    */
     
#if(_LVDS_EO_CLK_MERGE == _ENABLE)
    ScalerBurstWrite(tQC_COMMONMLVDS, sizeof(tQC_COMMONMLVDS), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH); 
#endif

    ScalerBurstWrite(tQC_MLVDS7X, sizeof(tQC_MLVDS7X), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerTimerDelayXms(1); 
    ScalerQCFPGA7xTable();
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

#if(_SDRAM_PHASE_CALIBRATION_QC == _ON)

//--------------------------------------------------
// Description  : SDRAM Test Delay 200us
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMDelay200Us(void)
{
    BYTE ucCnt = 0;

    for(ucCnt = 0; ucCnt < 10; ucCnt++)
    {
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
    }
}

//--------------------------------------------------
// Description  : SDRAM Test Delay 1ms
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMDelay1ms(void)
{
    BYTE ucCnt = 0;

    for(ucCnt = 0; ucCnt < 14; ucCnt++)
    {
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
    }
}

//--------------------------------------------------
// Description  : SDRAM accelerate reset
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMResetAcc(void)
{
    ScalerSetByte(P4_A4_SDR_PRCG, 0x93);
    ScalerSetByte(P4_A4_SDR_PRCG, 0x83);
    ScalerQCSDRAMDelay200Us();
    ScalerSetBit(P4_A6_SDR_SLEW_RATE, (~_BIT0), (_BIT0));
}

//--------------------------------------------------
// Description  : SDRAM token ring and phase initial
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMTokenPhaseSet(void)
{
    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x00);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x00);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x00);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x23);
#else
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x83);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x40);
#endif

    ScalerSetByte(P4_BE_SDR_PHASE_CAL, 0x00);
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x00);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, 0x00);
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x40);
    ScalerSetByte(P4_C3_DQS0_DLY2, 0x00);
    ScalerSetByte(P4_C5_DQS1_DLY2, 0x00);
    ScalerQCSDRAMResetAcc();
}

//--------------------------------------------------
// Description  : Clear SDRAM fifo
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMClearFifo(void)
{
    BYTE ucCnt = 0;

    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    for(ucCnt = 0; ucCnt < _TEST_DATA_MAX; ucCnt++)
    {
        ScalerSetByte(P4_BC_SDR_DATA_BUF, 0x00);
    }
}

//--------------------------------------------------
// Description  : Write SDRAM  test pattern
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMWritePattern(void)
{
    BYTE ucCnt = 0;

    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    for(ucCnt = 0; ucCnt < _TEST_DATA_MAX; ucCnt++)
    {
        ScalerSetByte(P4_BC_SDR_DATA_BUF, tSDRAM_PATTERN[ucCnt]);
    }

    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x80);
}

//--------------------------------------------------
// Description  : Set mpll
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMMpllSet(BYTE ucMCLK)
{
  BYTE ucMcode = 0;
  WORD usMPLLOffset = 0;

#if(_EXT_XTAL == _XTAL14318K)
    if(ucMCLK == _MEMORY_SPEED_215MHZ)
    {
        ucMcode = 0x3E;
    }
    else if(ucMCLK == _MEMORY_SPEED_198MHZ)
    {
        ucMcode = 0x39;
    }
    else if(ucMCLK == _MEMORY_SPEED_220MHZ)
    {
        ucMcode = 0x40;
    }
    else if(ucMCLK == _MEMORY_SPEED_100MHZ)
    {
        ucMcode = 0x1C;
    }
    else
    {
        usMPLLOffset = ((WORD)(ScalerGetByte(P0_FA_MCLK_FINE_TUNE_OFFSET_MSB) & 0x0F) << 8) + ScalerGetByte(P0_FB_MCLK_FINE_TUNE_OFFSET_LSB);
        ucMcode = (((DWORD)ucMCLK * 4 * 1000 / _EXT_XTAL) * 32768 + (32768 - usMPLLOffset) / 2) / (32768 - usMPLLOffset) - 2;
    }

    ScalerSetByte(P0_F5_MPLL_M, ucMcode);
#else
    #warning 'You must set M code value there.'
#endif

    ScalerSetByte(P0_F6_MPLL_N, 0x00);
    Delay5us(g_ucDelay5usN);
    Delay5us(g_ucDelay5usN);
    Delay5us(g_ucDelay5usN);
}

//--------------------------------------------------
// Description  : Recover page 4 register setting
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMDefaultTokenRing(void)
{
    ScalerSetByte(P4_A6_SDR_SLEW_RATE, 0x00);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetByte(P4_BD_SDR_MCU_RD_LEN, 0x04);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
    ScalerSetByte(P4_BD_SDR_MCU_RD_LEN, 0x02);
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    ScalerSetByte(P4_BD_SDR_MCU_RD_LEN, 0x02);
#else
    #warning You must set value there.
#endif


#if((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _OFF))

    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x00);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x00);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x44);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x88);

#elif((_OD_SUPPORT == _OFF) && (_FRC_SUPPORT == _ON))

    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x44);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x88);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x00);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);

#elif((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _ON))

    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x40);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x80);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x04);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x08);
#endif
}

//--------------------------------------------------
// Description  : Load default sdram phase
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMDefaultPhase(void)
{
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);
    ScalerSetByte(P4_C5_DQS1_DLY2, _SDR_DQS_DLY);
#else
    #warning You must set value there.
#endif

    ScalerQCSDRAMResetAcc();
}

//--------------------------------------------------
// Description  : K sdram phase count
// Input Value  : void
// Output Value : Phase count
//--------------------------------------------------
BYTE ScalerQCSDRAMPhaseCount(bit bDBBufferFlag)
{
    BYTE ucPhcalCnt = 0x00;
    BYTE ucDealyMaxTemp = 45;
    WORD usDelayUnit = 0x00;

    if(bDBBufferFlag == _FALSE)
    {
        ScalerSetByte(P4_BE_SDR_PHASE_CAL, 0x04);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
    }

    ucPhcalCnt = ScalerGetByte(P4_BF_SDR_CAL_RESULT) & 0x7F;

    if((ucPhcalCnt == 0x00) || (ScalerGetBit(P4_BE_SDR_PHASE_CAL, _BIT2) == _BIT2))
    {
        ScalerSetByte(P4_BE_SDR_PHASE_CAL, 0x00);
        return ucDealyMaxTemp;
    }

    usDelayUnit = (WORD)1000 * 50 / ucPhcalCnt * 20 / _M2PLL_CLK_MHZ;
    ScalerSetByte(P4_BE_SDR_PHASE_CAL, 0x00);

    return (WORD)1000 * 50 / _MEMORY_SPEED * 20 / usDelayUnit;
}

//--------------------------------------------------
// Description  : Mcu mode test
// Input Value  : ucAddrH    --> SDRAM address.
//                ucAddrM    --> SDRAM address.
//                ucAddrL    --> SDRAM address.
//                bWriteMcuFlag    --> Write or read flag.
//
// Output Value : Test result
//--------------------------------------------------
bit ScalerQCSDRAMMCUMode(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL, bit bWriteMcuFlag)
{
    bit bResult = _SUCCESS;
    BYTE ucValue = 0;
    BYTE ucCnt = 0;

    if(bWriteMcuFlag == _TRUE)
    {
        ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
        ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
        ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
        ScalerQCSDRAMWritePattern();

        ScalerQCSDRAMMpllSet(100);
        ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x00);
        ScalerSetByte(P4_C1_SDR_CLK_DLY2, 0x00);
        ScalerQCSDRAMResetAcc();
    }

    ScalerQCSDRAMClearFifo();
    ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
    ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
    ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0xA0);

    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    for(ucCnt = 0; ucCnt < _TEST_DATA_MAX; ucCnt++)
    {
        ucValue = ScalerGetByte(P4_BC_SDR_DATA_BUF);

        if(ucValue != tSDRAM_PATTERN[ucCnt])
        {
            bResult = _FAIL;
            break;
        }
    }

    if(bWriteMcuFlag == _TRUE)
    {
        ScalerQCSDRAMClearFifo();
        ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
        ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
        ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
        ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
        ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x80);
    }

    return  bResult;
}

//--------------------------------------------------
// Description  : On line mode test
// Input Value  : ucAddrH    --> SDRAM address.
//                ucAddrM    --> SDRAM address.
//                ucAddrL    --> SDRAM address.
//
// Output Value : Test result
//--------------------------------------------------
bit ScalerQCSDRAMOnlineMCUMode(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL)
{
    bit bResult = _SUCCESS;
    BYTE ucValue = 0;
    BYTE ucCnt = 0;

    ScalerQCSDRAMClearFifo();

    ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
    ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
    ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0xA0);
    Delay5us(g_ucDelay5usN);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    ScalerQCSDRAMDelay1ms();

    for(ucCnt = 0; ucCnt < _TEST_DATA_MAX; ucCnt++)
    {
        ucValue = ScalerGetByte(P4_BC_SDR_DATA_BUF);

        if(ucValue != tSDRAM_PATTERN[ucCnt])
        {
            bResult = _FAIL;
            break;
        }
    }

    return  bResult;
}

//--------------------------------------------------
// Description  : Write test pattern into SDRAM
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMWrPatternOnce(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL)
{
    ScalerQCSDRAMClearFifo();

    ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
    ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
    ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x80);
    Delay5us(g_ucDelay5usN);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    ScalerQCSDRAMDelay1ms();

    ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
    ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
    ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
    ScalerQCSDRAMWritePattern();
    Delay5us(g_ucDelay5usN);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    ScalerQCSDRAMDelay1ms();
}

//--------------------------------------------------
// Description  : SDRAM write phase search
// Input Value  : void
// Output Value : SDRAM mclk cycle and good write phase range
//--------------------------------------------------
DWORD ScalerQCSDRAMWritePhaseSearch(void)
{
    bit bClkInvGoodStart = _FALSE;
    bit bClkInvGoodStartTemp = _FALSE;
    bit bClkGoodStart = _FALSE;
    bit bWritePhaseFlag = _FALSE;
    bit bGoodStartFlag = _FALSE;
    BYTE ucSdrMclkFineTune = 0;
    BYTE ucChangeState = 0;
    BYTE ucRow = 0;
    BYTE ucBestWriteCount = 0;
    BYTE ucTransientStart = 0;
    BYTE ucTransientEnd = 0;
    BYTE ucDataStart = 0;
    BYTE ucDataEnd = 0;
    BYTE ucDebounceT = 0;
    BYTE ucMclkCycle = 0;
    BYTE ucDataSkewA = 0;
    BYTE ucDataSkewC = 0;

    ScalerSetBit(P0_FC_MCLK_SPREAD_SPECTRUM, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT0), (_BIT2 | _BIT0));
    ScalerQCSDRAMTokenPhaseSet();

    ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x00);
    ScalerQCSDRAMResetAcc();

    // Step1:Jude bad start or good start
    for(ucRow = 0; ucRow < 255; ucRow++)
    {
        if(ucSdrMclkFineTune > 254)
        {
            break;
        }

        ScalerQCSDRAMMpllSet(_MEMORY_SPEED);
        ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucSdrMclkFineTune);
        ScalerQCSDRAMResetAcc();

        bWritePhaseFlag = ScalerQCSDRAMMCUMode((ucRow >> 6), ((ucRow & 0x3F) << 2), 0x00, _TRUE);

        if(bWritePhaseFlag == _FALSE)
        {
            bClkGoodStart = _FALSE;
            bGoodStartFlag = _FALSE;
            ucSdrMclkFineTune++;
            break;
        }

        if(bWritePhaseFlag == _TRUE)
        {
            if(bGoodStartFlag == _FALSE)
            {
                bGoodStartFlag = _TRUE;
                ucDebounceT = 1;
            }
            else
            {
                ucDebounceT++;

                if(ucDebounceT > 4)
                {
                    bClkGoodStart = _TRUE;
                    ucSdrMclkFineTune++;
                    break;
                }
            }
        }

        ucSdrMclkFineTune++;
    }

    // Step2:Search transient time and data width
    if(bClkGoodStart == _TRUE)
    {
        for(ucRow = 0; ucRow < 255; ucRow++)
        {
            if(ucSdrMclkFineTune > 254)
            {
                break;
            }

            ScalerQCSDRAMMpllSet(_MEMORY_SPEED);
            ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucSdrMclkFineTune);
            ScalerQCSDRAMResetAcc();

            bWritePhaseFlag = ScalerQCSDRAMMCUMode((ucRow >> 6), ((ucRow & 0x3F) << 2), 0x00, _TRUE);

            if(bWritePhaseFlag == _TRUE)
            {
                if(bGoodStartFlag == _FALSE)
                {
                    bGoodStartFlag = _TRUE;
                    ucDebounceT = 1;
                }
                else
                {
                    ucDebounceT++;

                    if((ucChangeState == 1) && (ucDebounceT > 4))
                    {
                        ucChangeState = 2;
                        ucTransientEnd = ucSdrMclkFineTune - (ucDebounceT - 1);
                        ucDataStart = ucTransientEnd;
                    }
                }
            }
            else if((bGoodStartFlag == _TRUE) && (bWritePhaseFlag == _FALSE))
            {
                bGoodStartFlag = _FALSE;

                if(ucDebounceT > 4)
                {
                    if(ucChangeState == 0)
                    {
                        ucChangeState = 1;
                        ucTransientStart = ucSdrMclkFineTune;
                    }
                    else if(ucChangeState == 2)
                    {
                        ucDataEnd = ucSdrMclkFineTune;
                        break;
                    }
                }
            }

            ucSdrMclkFineTune++;
        }
    }
    else
    {
        for(ucRow = 0; ucRow < 255; ucRow++)
        {
            if(ucSdrMclkFineTune > 254)
            {
                break;
            }

            ScalerQCSDRAMMpllSet(_MEMORY_SPEED);
            ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucSdrMclkFineTune);
            ScalerQCSDRAMResetAcc();

            bWritePhaseFlag = ScalerQCSDRAMMCUMode((ucRow >> 6), ((ucRow & 0x3F) << 2), 0x00, _TRUE);

            if(bWritePhaseFlag == _TRUE)
            {
                if(bGoodStartFlag == _FALSE)
                {
                    bGoodStartFlag = _TRUE;
                    ucDebounceT = 1;
                }
                else
                {
                    ucDebounceT++;

                    if(ucDebounceT > 4)
                    {
                        if(ucChangeState == 0)
                        {
                            ucChangeState = 1;
                            ucDataStart = ucSdrMclkFineTune - (ucDebounceT - 1);
                        }
                        else if(ucChangeState == 2)
                        {
                            ucTransientEnd = ucSdrMclkFineTune - (ucDebounceT - 1);
                            break;
                        }
                    }
                }
            }
            else if((bGoodStartFlag == _TRUE) && (bWritePhaseFlag == _FALSE))
            {
                bGoodStartFlag = _FALSE;

                if(ucDebounceT > 4)
                {
                    if(ucChangeState == 1)
                    {
                        ucChangeState = 2;
                        ucTransientStart = ucSdrMclkFineTune;
                        ucDataEnd = ucSdrMclkFineTune;
                    }
                }
            }

            ucSdrMclkFineTune++;
        }
    }

    // Step3:Measure mclk duty
    bGoodStartFlag = _FALSE;
    ucChangeState = 0;
    ucSdrMclkFineTune = 0;
    ucDebounceT = 0;

    for(ucRow = 0; ucRow < 255; ucRow++)
    {
        if(ucSdrMclkFineTune > 254)
        {
            break;
        }

        ScalerQCSDRAMMpllSet(_MEMORY_SPEED);
        ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x80);
        ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucSdrMclkFineTune);
        ScalerQCSDRAMResetAcc();

        bWritePhaseFlag = ScalerQCSDRAMMCUMode((ucRow >> 6), ((ucRow & 0x3F) << 2), 0x00, _TRUE);

        if((ucSdrMclkFineTune == 0) && (bWritePhaseFlag == _FALSE))
        {
            bClkInvGoodStart = _FALSE;
        }

        if(bWritePhaseFlag == _TRUE)
        {
            if(bGoodStartFlag == _FALSE)
            {
                bGoodStartFlag = _TRUE;
                ucDebounceT = 1;

                if(ucSdrMclkFineTune == 0)
                {
                    bClkInvGoodStartTemp = _TRUE;
                }
            }
            else
            {
                ucDebounceT++;

                if(ucDebounceT > 4)
                {
                    if(bClkInvGoodStartTemp == _TRUE)
                    {
                        bClkInvGoodStart = _TRUE;
                        bClkInvGoodStartTemp = _FALSE;
                    }

                    if(((bClkInvGoodStart == _FALSE) && (bClkGoodStart == _TRUE)) || (ucChangeState == 1))
                    {
                        ucDataSkewC = ucSdrMclkFineTune - (ucDebounceT - 1);
                        break;
                    }
                }
            }
        }
        else if((bGoodStartFlag == _TRUE) && (bWritePhaseFlag == _FALSE))
        {
            bGoodStartFlag = _FALSE;

            if(ucDebounceT > 4)
            {
                if(bClkGoodStart == _TRUE)
                {
                    ucDataSkewC = ucSdrMclkFineTune;
                    break;
                }
                else
                {
                    ucChangeState = 1;
                }
            }
            else
            {
                if(bClkInvGoodStartTemp == _TRUE)
                {
                    bClkInvGoodStart = _FALSE;
                    bClkInvGoodStartTemp = _FALSE;
                }
            }
        }

        ucSdrMclkFineTune++;
    }

    // Step4: Calculate MclkCycle and write move
    ucMclkCycle = (ucTransientEnd - ucTransientStart) + (ucDataEnd - ucDataStart);
    ucBestWriteCount = ((ucDataStart + ucDataEnd) / 2) % ucMclkCycle;

    // Calculate 2.0ns Write Delay Uint, backup ucRow
    ucRow = ((DWORD)2 * ucMclkCycle * _MEMORY_SPEED + 500) / 1000;

    if(bClkGoodStart == _TRUE)
    {
        if(bClkInvGoodStart == _FALSE)
        {
            ucDataSkewA = ucTransientEnd;
        }
        else
        {
            ucDataSkewA = ucTransientStart;
        }
    }
    else
    {
        ucDataSkewA = ucDataStart;
    }

    // Back up ucHighDutyWidth
    ucChangeState = abs(ucDataSkewA - ucDataSkewC);

    ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucBestWriteCount);
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
    ScalerQCSDRAMResetAcc();

    DebugMessageScaler("5.ucTransientStart", ucTransientStart);
    DebugMessageScaler("5.ucTransientEnd", ucTransientEnd);
    DebugMessageScaler("5.ucDataStart", ucDataStart);
    DebugMessageScaler("5.ucDataEnd", ucDataEnd);
    DebugMessageScaler("5.ucDataSkewA", ucDataSkewA);
    DebugMessageScaler("5.ucDataSkewC", ucDataSkewC);
    DebugMessageScaler("5.ucHighDutyWidth", ucChangeState);
    DebugMessageScaler("5.ucMclkCycle", ucMclkCycle);
    DebugMessageScaler("5.ucBestWriteCount", ucBestWriteCount);
    DebugMessageScaler("5.ucRow", ucRow);

    if(ucMclkCycle >= ((ucTransientEnd - ucTransientStart) + ucRow))
    {
        return ((((DWORD)(ucMclkCycle - (ucTransientEnd - ucTransientStart) - ucRow)) >> 1)  << 16) | ((WORD)ucMclkCycle << 8) | ucChangeState;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : SDRAM read phase research
// Input Value  : ucHalfMclk    --> Mclk cycle.
//                ucWriteMove    --> Good write phase range.
// Output Value : void
//--------------------------------------------------
void ScalerQCSDRAMReadPhaseSearch( BYTE ucHighDutyWidth, BYTE ucMclkCyle, BYTE ucWriteMove)
{
    bit bIndex = _FALSE;
    bit bReadPhaseFlag = _FALSE;
    bit bReadPhaseFlag_last = _FALSE;
    bit bGoodStartFlag = _FALSE;
    bit bWriteInverL = _FALSE;
    bit bWriteInverR = _FALSE;
    bit bConflictArea = _FALSE;
    BYTE ucSdrDqsFineDly = 0;
    BYTE ucSdrDqsFineDlyMax = 0;
    BYTE ucBestWriteCount = 0;
    BYTE ucBestReadPhase = 0;
    BYTE ucSdrCasLatn = 0;
    BYTE ucBestSdrCasLatn = 0;
    BYTE ucStart = 0;
    BYTE ucEnd = 0;
    BYTE ucMaxWinS = 0;
    BYTE ucMaxWinE = 0;
    BYTE ucMaxWinWidth = 0;
    BYTE ucWrToRdDelayUnit = 0;
    BYTE uc2NsReadDelayUnit = 0;
    BYTE ucLRShift = 0;
    BYTE ucWritePhaseTemp = 0;
    BYTE ucLRShiftTemp = 0;

    ucBestWriteCount = ScalerGetByte(P4_C1_SDR_CLK_DLY2);
    ucSdrDqsFineDlyMax = ScalerQCSDRAMPhaseCount(_FALSE);

    // Calculate 2.0ns
    uc2NsReadDelayUnit = ((DWORD)2 * ucSdrDqsFineDlyMax * _MEMORY_SPEED + 500) / 1000;
    ucWrToRdDelayUnit = (WORD)ucMclkCyle * 100 / ucSdrDqsFineDlyMax;
    ScalerQCSDRAMMpllSet(_MEMORY_SPEED);
    ScalerQCSDRAMWrPatternOnce(0x00, 0x00, 0x00);

    for(ucBestReadPhase = 1; ucBestReadPhase < 8; ucBestReadPhase += 2)
    {
        for(ucSdrDqsFineDly = 0; ucSdrDqsFineDly <= ucSdrDqsFineDlyMax; ucSdrDqsFineDly++)
        {
            ucSdrCasLatn = ScalerGetByte(P4_A5_SDR_MEM_TYPE);
            ucSdrCasLatn = ((ucSdrCasLatn & 0xF8) | ucBestReadPhase);
            ScalerSetByte(P4_A5_SDR_MEM_TYPE, ucSdrCasLatn);
            ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly);
            ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDly);

            bReadPhaseFlag = ScalerQCSDRAMMCUMode(0x00, 0x00, 0x00, _FALSE);

            if(bIndex == _TRUE)
            {
                if((bReadPhaseFlag_last == _FALSE) && (bReadPhaseFlag == _TRUE) && (bGoodStartFlag == _FALSE))
                {
                    ucStart = ucSdrDqsFineDly;
                    bGoodStartFlag = _TRUE;
                }

                if((bReadPhaseFlag_last == _TRUE) && (bReadPhaseFlag == _FALSE) && (bGoodStartFlag == _TRUE))
                {
                    bGoodStartFlag = _FALSE;

                    if(ucSdrDqsFineDly == 0)
                    {
                        ucEnd = ucSdrDqsFineDlyMax;
                        ucSdrCasLatn = ucSdrCasLatn - 2;
                        bConflictArea = _TRUE;
                    }
                    else
                    {
                        ucEnd = ucSdrDqsFineDly - 1;

                        if(bConflictArea == _TRUE)
                        {
                            g_ucConflictAreaQC = ucStart;
                        }
                    }

                    // Threshold = 2
                    if(((ucEnd - ucStart + 3) >= ucMaxWinWidth) && (ucStart > 1))
                    {
                        ucMaxWinWidth = ucEnd - ucStart + 1;
                        ucMaxWinS = ucStart;
                        ucMaxWinE = ucEnd;
                        ucBestSdrCasLatn = ucSdrCasLatn;
                    }
                }
            }

            bReadPhaseFlag_last = bReadPhaseFlag;
            bIndex = _TRUE;
        }
    }

    if(ucMaxWinWidth >= uc2NsReadDelayUnit)
    {
        ucBestReadPhase = (ucMaxWinS + ucMaxWinE) >> 1;
        ScalerSetByte(P4_A5_SDR_MEM_TYPE, ucBestSdrCasLatn);
        ScalerSetByte(P4_C3_DQS0_DLY2, ucBestReadPhase);
        ScalerSetByte(P4_C5_DQS1_DLY2, ucBestReadPhase);
        ScalerQCSDRAMResetAcc();
    }
    else
    {
        if((ucSdrDqsFineDlyMax - ucMaxWinE) > (ucMaxWinS - 6))
        {
            //read delay unit to write delay unit
            ucLRShift = ((WORD)(uc2NsReadDelayUnit - ucMaxWinWidth) * ucWrToRdDelayUnit + 50) / 100;

            if(ucLRShift <= ucWriteMove)
            {
                ucLRShiftTemp = ucLRShift;

                if((ucBestWriteCount + ucLRShift) >= ucHighDutyWidth)
                {
                    ucWritePhaseTemp = ucBestWriteCount + ucLRShift - ucHighDutyWidth;
                    bWriteInverR = _TRUE;
                }
                else
                {
                    ucWritePhaseTemp = ucBestWriteCount + ucLRShift;
                    bWriteInverR = _FALSE;
                }
            }
            else
            {
                ucLRShiftTemp = ucWriteMove;

                if((ucBestWriteCount + ucWriteMove) >= ucHighDutyWidth)
                {
                    ucWritePhaseTemp = ucBestWriteCount + ucWriteMove - ucHighDutyWidth;
                    bWriteInverR = _TRUE;
                }
                else
                {
                    ucWritePhaseTemp = ucBestWriteCount + ucWriteMove;
                    bWriteInverR = _FALSE;
                }
            }

            ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucWritePhaseTemp);

            if(bWriteInverR == _TRUE)
            {
                ScalerSetByte(P4_C0_SDR_CLK_DLY1, ScalerGetByte(P4_C0_SDR_CLK_DLY1) ^ 0x80);
            }

            ucBestReadPhase = ((WORD)ucMaxWinS + ucMaxWinE + (WORD)ucLRShiftTemp * 100 / ucWrToRdDelayUnit + 1) >> 1;
            ScalerSetByte(P4_A5_SDR_MEM_TYPE, ucBestSdrCasLatn);
            ScalerSetByte(P4_C3_DQS0_DLY2, ucBestReadPhase);
            ScalerSetByte(P4_C5_DQS1_DLY2, ucBestReadPhase);
            ScalerQCSDRAMResetAcc();
        }
        else
        {
            ucLRShift = ((WORD)(uc2NsReadDelayUnit - ucMaxWinWidth) * ucWrToRdDelayUnit + 50) / 100;

            if(ucLRShift <= ucWriteMove)
            {
                ucLRShiftTemp = ucLRShift;

                if(ucBestWriteCount < ucLRShift)
                {
                    ucWritePhaseTemp = ucBestWriteCount + (ucMclkCyle - ucHighDutyWidth) - ucLRShift;
                    bWriteInverL = _TRUE;
                }
                else
                {
                    ucWritePhaseTemp = ucBestWriteCount - ucLRShift;
                    bWriteInverL = _FALSE;
                }
            }
            else
            {
                ucLRShiftTemp = ucWriteMove;

                if(ucBestWriteCount < ucWriteMove )
                {
                    ucWritePhaseTemp = ucBestWriteCount + (ucMclkCyle - ucHighDutyWidth) - ucWriteMove;
                    bWriteInverL = _TRUE;
                }
                else
                {
                    ucWritePhaseTemp = ucBestWriteCount - ucWriteMove;
                    bWriteInverL = _FALSE;
                }
            }

            ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucWritePhaseTemp);

            if(bWriteInverL == _TRUE)
            {
                ScalerSetByte(P4_C0_SDR_CLK_DLY1, ScalerGetByte(P4_C0_SDR_CLK_DLY1) ^ 0x80);
            }

            ucBestReadPhase = ((WORD)ucMaxWinS + ucMaxWinE - ((WORD)ucLRShiftTemp * 100 / ucWrToRdDelayUnit)) >> 1;
            ScalerSetByte(P4_A5_SDR_MEM_TYPE, ucBestSdrCasLatn);
            ScalerSetByte(P4_C3_DQS0_DLY2, ucBestReadPhase);
            ScalerSetByte(P4_C5_DQS1_DLY2, ucBestReadPhase);
            ScalerQCSDRAMResetAcc();
        }
    }

    g_ucSdrClkDly1QC = ScalerGetByte(P4_C0_SDR_CLK_DLY1);
    g_ucSdrClkDly2QC = ScalerGetByte(P4_C1_SDR_CLK_DLY2);
    g_ucSdrCasLatnQC = ScalerGetByte(P4_A5_SDR_MEM_TYPE);
    g_ucDqsFineDlyQC = ScalerGetByte(P4_C3_DQS0_DLY2);

    DebugMessageScaler("5.g_ucConflictAreaQC", g_ucConflictAreaQC);
    DebugMessageScaler("5.g_ucSdrClkDly1", g_ucSdrClkDly1QC);
    DebugMessageScaler("5.g_ucSdrClkDly2", g_ucSdrClkDly2QC);
    DebugMessageScaler("5.g_ucSdrCasLatn", g_ucSdrCasLatnQC);
    DebugMessageScaler("5.g_ucDqsFineDly", g_ucDqsFineDlyQC);
    DebugMessageScaler("5.ucWriteMove", ucWriteMove);
    DebugMessageScaler("5.uc2NsReadDelayUnit", uc2NsReadDelayUnit);
    DebugMessageScaler("5.ucMaxWinWidth", ucMaxWinWidth);
    DebugMessageScaler("5.ucSdrDqsFineDlyMax", ucSdrDqsFineDlyMax);
    DebugMessageScaler("5.ucLRShift", ucLRShift);
}

//--------------------------------------------------
// Description  : Check sdram data width
// Input Value  : void
// Output Value : Check result.
//--------------------------------------------------
bit ScalerQCSDRAM1NsCheck(void)
{
    bit bReadPhaseFlagLeft = _FALSE;
    bit bReadPhaseFlagRight = _FALSE;
    BYTE uc1NsReadDelayUnit = 0;
    BYTE ucSdrDqsFineDlyMax = 0;
    BYTE ucSdrDqsFineDly = 0;
    BYTE ucSdrDqsFineDlyTemp = 0;

    ucSdrDqsFineDlyMax = ScalerQCSDRAMPhaseCount(_FALSE);

    // Calculate 1.0ns
    uc1NsReadDelayUnit = ((WORD)ucSdrDqsFineDlyMax * _MEMORY_SPEED + 500) / 1000;
    ucSdrDqsFineDly = ScalerGetByte(P4_C3_DQS0_DLY2);

    if((ucSdrDqsFineDly > (8 + (uc1NsReadDelayUnit + 1) >> 1)) && ((ucSdrDqsFineDly + (uc1NsReadDelayUnit + 1) >> 1) <= ucSdrDqsFineDlyMax))
    {
        ucSdrDqsFineDlyTemp = ucSdrDqsFineDly - ((uc1NsReadDelayUnit + 1) >> 1);
        ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDlyTemp);
        ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDlyTemp);
        bReadPhaseFlagLeft = ScalerQCSDRAMMCUMode(0x00, 0x00, 0x00, _FALSE);

        ucSdrDqsFineDlyTemp = ucSdrDqsFineDly + ((uc1NsReadDelayUnit + 1) >> 1);
        ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDlyTemp);
        ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDlyTemp);
        bReadPhaseFlagRight = ScalerQCSDRAMMCUMode(0x00, 0x00, 0x00, _FALSE);
    }
    else
    {
        return _FAIL;
    }

    if((bReadPhaseFlagLeft == _FALSE) || (bReadPhaseFlagRight == _FALSE))
    {
        return _FAIL;
    }
    else
    {
        ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly);
        ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDly);
    }

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : SDRAM phase calibration
// Input Value  : void
// Output Value : Check result.
//--------------------------------------------------
bit ScalerQCSDRAMPhaseSearch(void)
{
    bit bReadPhaseFlag = _FALSE;
    bit b1NSCheckFlag = _FALSE;
    BYTE ucMclkCyle = 0;
    BYTE ucWriteMove = 0;
    BYTE ucHighDutyWidth = 0;
    DWORD ulMclkDutyWriteMove = 0;


    DebugMessageScaler("6. SDRAM phase auto calibration start", 0x00);
    ulMclkDutyWriteMove = ScalerQCSDRAMWritePhaseSearch();

    if(ulMclkDutyWriteMove > 0)
    {
        ucHighDutyWidth = (BYTE)(ulMclkDutyWriteMove & 0x000000FF);
        ucMclkCyle =  (BYTE)((ulMclkDutyWriteMove & 0x0000FF00) >> 8);
        ucWriteMove = (BYTE)((ulMclkDutyWriteMove & 0x00FF0000) >> 16);

        DebugMessageScaler("5.ucHighDutyWidth", ucHighDutyWidth);
        DebugMessageScaler("5.ucMclkCyle", ucMclkCyle);
        DebugMessageScaler("5.ucWriteMove", ucWriteMove);

        ScalerQCSDRAMReadPhaseSearch(ucHighDutyWidth, ucMclkCyle, ucWriteMove);

        bReadPhaseFlag = ScalerQCSDRAMMCUMode(0x00, 0x00, 0x00, _FALSE);


        if(bReadPhaseFlag == _TRUE)
        {
            b1NSCheckFlag = ScalerQCSDRAM1NsCheck();

            if(b1NSCheckFlag == _FALSE)
            {
                 DebugMessageScaler("5. Read phase 1NS recheck fail!!!", 0x00);
            }
        }
        else
        {
            DebugMessageScaler("5. Read phase calibration fail!!!", 0x00);
        }
    }
    else
    {
       DebugMessageScaler("5. Write phase calibration fail!!!", 0x00);
    }

    if((bReadPhaseFlag == _FALSE) || (b1NSCheckFlag == _FALSE) || (ulMclkDutyWriteMove == 0))
    {
        g_ucSdrCasLatnQC = _SDR_CAS_LATN;
        g_ucSdrClkDly1QC = _SDR_CLK_DLY1;
        g_ucSdrClkDly2QC = _SDR_CLK_DLY2;
        g_ucDqsFineDlyQC = _SDR_DQS_DLY;
        ScalerQCSDRAMDefaultPhase();
        ScalerQCSDRAMDefaultTokenRing();
        DebugMessageScaler("6. SDRAM auto calibration fail!!!", 0x00);
        DebugMessageScaler("6. SDRAM phase auto calibration End", 0x00);

        return _TEST_FAIL;
    }
    else
    {
        ScalerQCSDRAMDefaultTokenRing();
        DebugMessageScaler("6. SDRAM auto calibration pass!!!", 0x00);
        DebugMessageScaler("6. SDRAM phase auto calibration End", 0x00);

        return _TEST_PASS;
    }

    ScalerQCSDRAMDefaultTokenRing();

    //===================
    // Set MCLK spread spectrum function
    //===================
    ScalerSetBit(P0_FC_MCLK_SPREAD_SPECTRUM, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT0), ((_MCLK_SPREAD_SPECTRUM_RANGE << 4) | _BIT2 | _BIT0));
}

//--------------------------------------------------
// Description  : SDRAM read phase OnLine  Search
// Input Value  : ulAddress    --> SDRAM address
// Output Value : Search result.
//--------------------------------------------------
bit ScalerQCSDRAMPhaseOnLine(DWORD ulAddress)
{
    bit bPassFlag = _FALSE;
    BYTE ucSdrDqsFineDlyM[2] = {0, 0};
    BYTE ucSdrDqsFineDly[2] = {1, 1};
    BYTE ucLRShift = 1;
    BYTE ucVWidthR = 0;
    BYTE ucVWidthL = 0;
    BYTE ucSdrDqsFineDlyMax = 0;
    BYTE uc1NsReadDelayUnit = 0;
    BYTE ucMcuTokenTemp = 0;
    BYTE ucODGain = 0;

    DebugMessageScaler("6. SDRAM phase on line start", 0x00);
    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x00);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x00);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x00);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);

    ucMcuTokenTemp = ScalerGetByte(P4_AB_SDR_RSC_MCU);
    ScalerSetByte(P4_AB_SDR_RSC_MCU, 0xFF);

    ucSdrDqsFineDlyMax = ScalerQCSDRAMPhaseCount(_TRUE);

    // Claculate 1.0ns
    uc1NsReadDelayUnit = ((WORD)ucSdrDqsFineDlyMax * _MEMORY_SPEED + 500) / 1000;
    ScalerSetBit(P4_BD_SDR_MCU_RD_LEN, ~_BIT7, _BIT7);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

    ucSdrDqsFineDlyM[0] = ScalerGetByte(P4_C3_DQS0_DLY2);
    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);

    ScalerQCSDRAMWrPatternOnce(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
    bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

    if(bPassFlag == _TRUE)
    {
        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= (uc1NsReadDelayUnit >> 1)))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= uc1NsReadDelayUnit))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) > ucSdrDqsFineDlyMax)
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (g_ucConflictAreaQC + ((uc1NsReadDelayUnit  + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);
                }
                else
                {
                    ScalerQCSDRAMDefaultPhase();
                    ScalerQCSDRAMDefaultTokenRing();
                    DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
                    DebugMessageScaler("6. SDRAM phase on line End", 0x00);
                    return _TEST_FAIL;
                }
            }
            else if(ucSdrDqsFineDlyM[0] < (uc1NsReadDelayUnit + g_ucConflictAreaQC))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);
                }
                else
                {
                    ScalerQCSDRAMDefaultPhase();
                    ScalerQCSDRAMDefaultTokenRing();
                    DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
                    DebugMessageScaler("6. SDRAM phase on line End", 0x00);
                    return _TEST_FAIL;
                }
            }
            else
            {
                ScalerQCSDRAMDefaultPhase();
                ScalerQCSDRAMDefaultTokenRing();
                DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
                DebugMessageScaler("6. SDRAM phase on line End", 0x00);
                return _TEST_FAIL;
            }

            ScalerQCSDRAMDefaultTokenRing();
            return _TEST_PASS;
        }
        else
        {
            ScalerQCSDRAMDefaultPhase();
            ScalerQCSDRAMDefaultTokenRing();
            DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
            DebugMessageScaler("6. SDRAM phase on line End", 0x00);
            SET_CAS_CHANGE_STATUS(_FALSE);
            return _TEST_FAIL;
        }
    }

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] <= 1) || (ucLRShift > 10))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == 0)
        {
            break;
        }

        ucVWidthL++;
    }

    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] >= (ucSdrDqsFineDlyMax - 1)) || (ucLRShift > 10))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == 0)
        {
            break;
        }

        ucVWidthR++;
    }

    ucVWidthL = ucVWidthL << 1;
    ucVWidthR = ucVWidthR << 1;
    ucSdrDqsFineDly[0] = ((ucSdrDqsFineDlyM[0] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[0]) >> 1);

    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), (_BIT4 | _BIT1));
    ucODGain = ScalerGetByte(P3_A3_LS_DELTA_GAIN);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x00);

    ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly[0]);
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~_BIT0, _BIT0);

    // Wait phase update
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, ucODGain);
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), 0x00);

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

    ucSdrDqsFineDlyM[0] = ScalerGetByte(P4_C3_DQS0_DLY2);
    ucSdrDqsFineDlyM[1] = ScalerGetByte(P4_C5_DQS1_DLY2);
    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);

    ScalerQCSDRAMWrPatternOnce(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
    bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

    if(bPassFlag == _TRUE)
    {
        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= (uc1NsReadDelayUnit >> 1)) && (ucSdrDqsFineDlyM[0] >= (uc1NsReadDelayUnit >> 1)))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit >> 1) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= uc1NsReadDelayUnit) && (ucSdrDqsFineDlyM[0] >= uc1NsReadDelayUnit))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) > ucSdrDqsFineDlyMax)
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (g_ucConflictAreaQC + ((uc1NsReadDelayUnit  + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);
                }
                else
                {
                    ScalerQCSDRAMDefaultPhase();
                    ScalerQCSDRAMDefaultTokenRing();
                    DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
                    DebugMessageScaler("6. SDRAM phase on line End", 0x00);
                    return _TEST_FAIL;
                }
            }
            else if(ucSdrDqsFineDlyM[0] < (uc1NsReadDelayUnit + g_ucConflictAreaQC))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);
                }
                else
                {
                    ScalerQCSDRAMDefaultPhase();
                    ScalerQCSDRAMDefaultTokenRing();
                    DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
                    DebugMessageScaler("6. SDRAM phase on line End", 0x00);
                    return _TEST_FAIL;
                }
            }
            else
            {
                ScalerQCSDRAMDefaultPhase();
                ScalerQCSDRAMDefaultTokenRing();
                DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
                DebugMessageScaler("6. SDRAM phase on line End", 0x00);
                return _TEST_FAIL;
            }

            ScalerQCSDRAMDefaultTokenRing();
            return _TEST_PASS;
        }
        else
        {
            ScalerQCSDRAMDefaultPhase();
            ScalerQCSDRAMDefaultTokenRing();
            DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
            DebugMessageScaler("6. SDRAM phase on line End", 0x00);
            SET_CAS_CHANGE_STATUS(_FALSE);;
            return _TEST_FAIL;
        }
    }

    for(ucLRShift = 1; ucLRShift <= 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] <= 1) || (ucSdrDqsFineDly[1] <= 1) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _FALSE)
        {
            break;
        }

        ucVWidthL++;
    }

    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);
    ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
    ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];

    for(ucLRShift = 1; ucLRShift <= 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] >= (ucSdrDqsFineDlyMax - 1)) || (ucSdrDqsFineDly[1] >= (ucSdrDqsFineDlyMax - 1)) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerQCSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _FALSE)
        {
            break;
        }

        ucVWidthR++;
    }

    ucVWidthL = ucVWidthL << 1;
    ucVWidthR = ucVWidthR << 1;
    ucSdrDqsFineDly[0] = ((ucSdrDqsFineDlyM[0] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[0]) >> 1);
    ucSdrDqsFineDly[1] = ((ucSdrDqsFineDlyM[1] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[1]) >> 1);

    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), (_BIT4 | _BIT1));
    ucODGain = ScalerGetByte(P3_A3_LS_DELTA_GAIN);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x00);

    ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly[0]);
    ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDly[1]);
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~_BIT0, _BIT0);

    // Wait phase update
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, ucODGain);
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), 0x00);

#else
    #warning You must set value there.
#endif

    DebugMessageScaler("5.read ucVWidth", ((WORD)ucVWidthL << 8) | ucVWidthR);
    ScalerSetByte(P4_AB_SDR_RSC_MCU, ucMcuTokenTemp);

    if((ucVWidthL + ucVWidthR + 1) >= uc1NsReadDelayUnit)
    {
        DebugMessageScaler("6. SDRAM phase on line pass!!!", 0x00);
        DebugMessageScaler("6. SDRAM phase on line End", 0x00);
        ScalerQCSDRAMDefaultTokenRing();
        return _TEST_PASS;
    }
    else
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDly[0] - g_ucConflictAreaQC) <= (ucSdrDqsFineDlyMax - ucSdrDqsFineDly[0]))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);
                }
                else
                {
                    ScalerQCSDRAMDefaultPhase();
                    ScalerQCSDRAMDefaultTokenRing();
                    DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
                    DebugMessageScaler("6. SDRAM phase on line End", 0x00);
                    return _TEST_FAIL;
                }
            }
            else
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (g_ucConflictAreaQC + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);
                }
                else
                {
                    ScalerQCSDRAMDefaultPhase();
                    ScalerQCSDRAMDefaultTokenRing();
                    DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
                    DebugMessageScaler("6. SDRAM phase on line End", 0x00);
                    return _TEST_FAIL;
                }
            }

            ScalerQCSDRAMDefaultTokenRing();
            DebugMessageScaler("6. SDRAM phase on line pass!!!", 0x00);
            DebugMessageScaler("6. SDRAM phase on line End", 0x00);
            return _TEST_PASS;
        }
        else
        {
            ScalerQCSDRAMDefaultPhase();
            ScalerQCSDRAMDefaultTokenRing();
            DebugMessageScaler("6. SDRAM phase on line fail!!!", 0x00);
            DebugMessageScaler("6. SDRAM phase on line End", 0x00);
            SET_CAS_CHANGE_STATUS(_FALSE);
            return _TEST_FAIL;
        }
    }
}

#endif  // End of #if(_SDRAM_PHASE_CALIBRATION_QC == _ON)

#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)
