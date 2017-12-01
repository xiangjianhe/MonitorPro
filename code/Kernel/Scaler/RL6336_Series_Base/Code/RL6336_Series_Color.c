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
// ID Code      : RL6336_Series_Color.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6336_SERIES_COLOR__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _DCC_HISTO_THD1                       0x20
#define _DCC_HISTO_THD2                       0xE0

//--------------------------------------------------
// Definitions of Digital Filter
//--------------------------------------------------
#define _DIG_FILTER_NSMEAR_THD                4 //effective:0~7
#define _DIG_FILTER_NSMEAR_DIV_VALUE          1 //effective:0~3

#define _DIG_FILTER_PSMEAR_THD                4 //effective:0~7
#define _DIG_FILTER_PSMEAR_DIV_VALUE          1 //effective:0~3

#define _DIG_FILTER_NRING_THD                 4 //effective:0~7
#define _DIG_FILTER_NRING_DIV_VALUE           1 //effective:0~3

#define _DIG_FILTER_PRING_THD                 4 //effective:0~7
#define _DIG_FILTER_PRING_DIV_VALUE           1 //effective:0~3

#define _DIG_FILTER_BGAIN                     0
#define _DIG_FILTER_GGAIN                     1
#define _DIG_FILTER_RGAIN                     2
#define _DIG_FILTER_RGB_CHANNEL               3

#define _DIG_FILTER_THRESHOLD1                30
#define _DIG_FILTER_OFFSET                    5
#define _DIG_FILTER_DELTA                     5

//--------------------------------------------------
// Definitions of ICM
//--------------------------------------------------
#define _ICM_TABLE_SIZE                       51

//--------------------------------------------------
// Definitions of Six Color
//--------------------------------------------------
#define _SIX_COLOR_R_HUE_LEFT_RANGE           512 
#define _SIX_COLOR_R_HUE_RIGHT_RANGE          256 
#define _SIX_COLOR_G_HUE_LEFT_RANGE           256
#define _SIX_COLOR_G_HUE_RIGHT_RANGE          512
#define _SIX_COLOR_B_HUE_LEFT_RANGE           256
#define _SIX_COLOR_B_HUE_RIGHT_RANGE          256 
#define _SIX_COLOR_C_HUE_LEFT_RANGE           512  
#define _SIX_COLOR_C_HUE_RIGHT_RANGE          512
#define _SIX_COLOR_M_HUE_LEFT_RANGE           512
#define _SIX_COLOR_M_HUE_RIGHT_RANGE          512
#define _SIX_COLOR_Y_HUE_LEFT_RANGE           256 
#define _SIX_COLOR_Y_HUE_RIGHT_RANGE          256

#define _SIX_COLOR_R_MASTER_DELHUE_MAX        158
#define _SIX_COLOR_G_MASTER_DELHUE_MAX        181
#define _SIX_COLOR_B_MASTER_DELHUE_MAX        181
#define _SIX_COLOR_C_MASTER_DELHUE_MAX        151
#define _SIX_COLOR_M_MASTER_DELHUE_MAX        181
#define _SIX_COLOR_Y_MASTER_DELHUE_MAX        173

#define _SIX_COLOR_R_MASTER_DELHUE_MIN        -181
#define _SIX_COLOR_G_MASTER_DELHUE_MIN        -173
#define _SIX_COLOR_B_MASTER_DELHUE_MIN        -151
#define _SIX_COLOR_C_MASTER_DELHUE_MIN        -181
#define _SIX_COLOR_M_MASTER_DELHUE_MIN        -181
#define _SIX_COLOR_Y_MASTER_DELHUE_MIN        -158

#define _SIX_COLOR_LEFT                       0
#define _SIX_COLOR_RIGHT                      1
#define _SIX_COLOR_CENTER                     2

#define _SIX_COLOR_LEFT_ENABLE                1
#define _SIX_COLOR_RIGHT_ENABLE               2
#define _SIX_COLOR_CENTER_ENABLE              4
#define _SIX_COLOR_HUE_ENABLE                 1
#define _SIX_COLOR_SAT_ENABLE                 2

#define _SIX_COLOR_RED                        0 	 
#define _SIX_COLOR_YELLOW                     1
#define _SIX_COLOR_GREEN                      2
#define _SIX_COLOR_CYAN                       3
#define _SIX_COLOR_BLUE                       4
#define _SIX_COLOR_MAGENTA                    5

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_SIX_COLOR_SUPPORT == _ON)
typedef struct
{
	// 0~4095. Magenta:0, Red:722, Yellow:1326, Green:2048, Cyan:2770, Blue:3374, Flesh-tone:962
	SWORD shCentDeltaHue;	
	SWORD shCentDeltaSat;	
} StructSixColorParameters;
#endif

//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Code Tables of Color Conversion
//--------------------------------------------------
BYTE code tCOLOR_CONV_YUV2RGB_ITU601[] =
{
    4,  _NON_AUTOINC,   CM_9F_PAGE_SEL,                     0x14,
    25, _AUTOINC,       P14_A2_YUB_RGB_COEF_K11_HSB,        0x04, 0xA8, 0x06, 0x62, 0x01, 0x91, 0x03, 0x40, 0x08, 
                                                            0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
                                                            0x02, 0x00, 0x02, 0x00,                                                 
    _END
 };
 
 BYTE code tCOLOR_CONV_YUV2RGB_ITU709[] =
 {
    4, _NON_AUTOINC,    CM_9F_PAGE_SEL,                     0x14,
    25, _AUTOINC,       P14_A2_YUB_RGB_COEF_K11_HSB,        0x04, 0xA8, 0x07, 0x2c, 0x00, 0xda, 0x02, 0x22, 0x08, 
                                                            0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 
                                                            0x02, 0x00, 0x02, 0x00,
    _END
};

#if(_OCC_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// PCM TABLE For OCC
//----------------------------------------------------------------------------------------------------
BYTE code tPCM_INPUTGAMMA_SRGB[] =
{
    0x00,0x00,0x14,
    0x02,0x80,0x3C,
    0x05,0x50,0x72,
    0x09,0x50,0xBE,
    0x0E,0xC1,0x20,
    0x15,0xA1,0x9B,
    0x1E,0x22,0x30,
    0x28,0x52,0xE1,
    0x34,0x53,0xAF,
    0x10,0x91,0x27,
    0x14,0x71,0x6A,
    0x18,0xE1,0xB5,
    0x1D,0xD2,0x08,
    0x23,0x52,0x64,
    0x29,0x52,0xC9,
    0x2F,0xE3,0x36,
    0x37,0x13,0xAE,
    0x3E,0xD1,0x0C,
    0x11,0xD1,0x2E,
    0x14,0x01,0x53,
    0x16,0x71,0x7B,
    0x18,0xF1,0xA5,
    0x1B,0xB1,0xD2,
    0x1E,0x92,0x01,
    0x21,0xA2,0x33,
    0x24,0xD2,0x68,
    0x28,0x32,0xA0,
    0x2B,0xC2,0xDA,
    0x2F,0x83,0x17,
    0x33,0x73,0x58,
    0x37,0x93,0x9B,
    0x3B,0xD3,0xE1,
    0x3F,0xC0,0x00,
    0x11,0x22,
};

BYTE code tPCM_INPUTGAMMA_ADOBERGB[] =
{
    0x00,0x00,0x06,
    0x00,0xE0,0x18,
    0x02,0x40,0x3C,
    0x05,0xA0,0x7F,
    0x0A,0xA0,0xDC,
    0x11,0x61,0x56,
    0x19,0xF1,0xEE,
    0x24,0x62,0xA5,
    0x30,0xD3,0x7C,
    0x3F,0x31,0x1D,
    0x13,0xF1,0x63,
    0x18,0x91,0xB2,
    0x1D,0xC2,0x09,
    0x23,0x82,0x69,
    0x29,0xC2,0xD2,
    0x30,0xA3,0x44,
    0x38,0x03,0xBF,
    0x10,0x01,0x11,
    0x12,0x21,0x34,
    0x14,0x71,0x5A,
    0x16,0xE1,0x82,
    0x19,0x71,0xAD,
    0x1C,0x31,0xDA,
    0x1F,0x22,0x0A,
    0x22,0x32,0x3C,
    0x25,0x62,0x70,
    0x28,0xC2,0xA8,
    0x2C,0x42,0xE1,
    0x2F,0xF3,0x1D,
    0x33,0xD3,0x5C,
    0x37,0xD3,0x9E,
    0x3B,0xF3,0xE2,
    0x3F,0xC0,0x00,
    0x12,0x21,
};

code BYTE *tPCM_INPUTGAMMA[] = 
{    
    tPCM_INPUTGAMMA_SRGB,
    tPCM_INPUTGAMMA_ADOBERGB,
};
#endif  // End of #if(_OCC_SUPPORT == _ON)

#if(_SIX_COLOR_SUPPORT == _ON)
//--------------------------------------------------
// Code Tables of Six Color
//--------------------------------------------------
WORD code tSIX_COLOR_DEFAULT_ANGLE[] = 
{
    722, 1330, 2048, 2770, 3374, 0,
};

WORD code usTanCurveAngle[] = 
{
       0,    2,    5,   10,  
      20,   30,   68,  137,  
     205,  210,  222,  256, 
     273,  341,  380,  421,
     462,  466,  501,  512,  
     552,  592,  610,  628, 
     673,  718,  722,  774,
     814,  818,  880,  887, 
     899,  910,  921,  933, 
     945,  956,  961,  966, 
     971,  974,  978,  981,  
     985,  989,  993,  997, 
    1001, 1007, 1013, 1024
};
WORD code usTanCurveValue[] = 
{
        0,     3,     8,    15, 
       31,    46,   105,   213, 
      325,   334,   354,   414, 
      445,   577,   659,   754,
      857,   868,   967,  1000, 
     1131,  1281,  1357,  1439, 
     1674,  1972,  2002,  2478,
     2996,  3059,  4453,  4688, 
     5151,  5660,  6276,  7117,
     8211,  9552, 10315, 11210,
    12273, 13012, 14148, 15138, 
    16695, 18608, 21013, 24130, 
    28332, 38338, 59258, 65535
};
                                                                                        
WORD code tSIX_COLOR_HUE_RANGE[][2] = 
{ 
    {_SIX_COLOR_R_HUE_LEFT_RANGE, _SIX_COLOR_R_HUE_RIGHT_RANGE},
    {_SIX_COLOR_Y_HUE_LEFT_RANGE, _SIX_COLOR_Y_HUE_RIGHT_RANGE},
    {_SIX_COLOR_G_HUE_LEFT_RANGE, _SIX_COLOR_G_HUE_RIGHT_RANGE},
    {_SIX_COLOR_C_HUE_LEFT_RANGE, _SIX_COLOR_C_HUE_RIGHT_RANGE},
    {_SIX_COLOR_B_HUE_LEFT_RANGE, _SIX_COLOR_B_HUE_RIGHT_RANGE},
    {_SIX_COLOR_M_HUE_LEFT_RANGE, _SIX_COLOR_M_HUE_RIGHT_RANGE},
};                       


SWORD code tSIX_COLOR_DELTA_HUE_MAX[] = 	
{ 
    _SIX_COLOR_R_MASTER_DELHUE_MAX, 
    _SIX_COLOR_Y_MASTER_DELHUE_MAX,
    _SIX_COLOR_G_MASTER_DELHUE_MAX,                                
    _SIX_COLOR_C_MASTER_DELHUE_MAX,
    _SIX_COLOR_B_MASTER_DELHUE_MAX,
    _SIX_COLOR_M_MASTER_DELHUE_MAX,                             
};
                           
SWORD code tSIX_COLOR_DELTA_HUE_MIN[] = 
{ 
    _SIX_COLOR_R_MASTER_DELHUE_MIN, 
    _SIX_COLOR_Y_MASTER_DELHUE_MIN,
    _SIX_COLOR_G_MASTER_DELHUE_MIN,
    _SIX_COLOR_C_MASTER_DELHUE_MIN,
    _SIX_COLOR_B_MASTER_DELHUE_MIN, 
    _SIX_COLOR_M_MASTER_DELHUE_MIN,                            
};  
                              
SWORD code tSIX_COLOR_DELTA_SATURATION[] = 
{
    32, 64, 96, 128, 160, 192, 224, 256,
};

SWORD code tSIX_COLOR_SATURATION[] = 
{
    64, 128, 192, 256, 320, 384, 448, 511,
};


SWORD code tSIX_COLOR_R_MASTER_UV[][2] = 
{ 
    {31,  64},
    {63,  128},
    {95,  192},
    {127, 256},
    {159, 320},
    {191, 384},
    {223, 448},
    {255, 511},
};
SWORD code tSIX_COLOR_R_RIGHT_UV[][2] = 
{ 
    {44,  40},
    {89,  78},
    {133, 118},
    {178, 156},
    {223, 194},
    {267, 234},
    {312, 272},
    {356, 310},
};

SWORD code tSIX_COLOR_Y_MASTER_UV[][2] = 
{ 
    {-32,  64},
    {-64,  128},
    {-96,  192},
    {-128, 256},
    {-161, 318},
    {-193, 382},
    {-225, 446},
    {-257, 508},
};
SWORD code tSIX_COLOR_Y_RIGHT_UV[][2] = 
{ 
    {-4,  64},
    {-9,  128},
    {-14, 192},
    {-19, 256},
    {-24, 320},
    {-29, 384},
    {-34, 448},
    {-39, 511},
};

SWORD code tSIX_COLOR_G_MASTER_UV[][2] = 
{ 
    {-64,  0},
    {-128, 0},
    {-192, 0},
    {-256, 0},
    {-320, 0},
    {-384, 0},
    {-448, 0},
    {-511, 0},
};
SWORD code tSIX_COLOR_G_RIGHT_UV[][2] = 
{ 
    {-42,  44},
    {-85,  86},
    {-128, 128},
    {-170, 172},
    {-213, 214},
    {-256, 256},
    {-298, 300},
    {-340, 342},
};

SWORD code tSIX_COLOR_C_MASTER_UV[][2] = 
{ 
    {-31,  -64},
    {-63,  -128},
    {-95,  -192},
    {-127, -256},
    {-159, -320},
    {-191, -384},
    {-223, -448},
    {-255, -511},
};
SWORD code tSIX_COLOR_C_RIGHT_UV[][2] = 
{ 
    {-54,  -20},
    {-109, -38},
    {-164, -56},
    {-219, -74},
    {-274, -92},
    {-329, -110},
    {-383, -130},
    {-437, -148},
};

SWORD code tSIX_COLOR_B_MASTER_UV[][2] = 
{ 
    {31,  -66},
    {63,  -130},
    {95,  -194},
    {127, -258},
    {159, -322},
    {191, -386},
    {223, -450},
    {255, -512},
};
SWORD code tSIX_COLOR_B_RIGHT_UV[][2] = 
{ 
    {4,  -64},
    {9,  -128},
    {13, -192},
    {18, -256},
    {22, -320},
    {27, -384},
    {31, -448},
    {36, -511},
};

SWORD code tSIX_COLOR_M_MASTER_UV[][2] = 
{ 
    {64,  0},
    {128, 0},
    {192, 0},
    {256, 0},
    {320, 0},
    {384, 0},
    {448, 0},
    {511, 0},
};
SWORD code tSIX_COLOR_M_RIGHT_UV[][2] = 
{ 
    {42,  -44},
    {85,  -86},
    {128, -128},
    {170, -172},
    {213, -214},
    {256, -256},
    {298, -300},
    {340, -342},
};

code SWORD *tUV_VALUE[] =
{
    tSIX_COLOR_R_MASTER_UV, tSIX_COLOR_R_RIGHT_UV,
    tSIX_COLOR_Y_MASTER_UV, tSIX_COLOR_Y_RIGHT_UV,
    tSIX_COLOR_G_MASTER_UV, tSIX_COLOR_G_RIGHT_UV,
    tSIX_COLOR_C_MASTER_UV, tSIX_COLOR_C_RIGHT_UV,
    tSIX_COLOR_B_MASTER_UV, tSIX_COLOR_B_RIGHT_UV,
    tSIX_COLOR_M_MASTER_UV, tSIX_COLOR_M_RIGHT_UV,
};
#endif // End of #if(_SIX_COLOR_SUPPORT == _ON)

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if((_DCC_HISTOGRM_INFO == _ON) && (_DCC_HISTOGRAM_THD_CHANGE == _ON))
BYTE g_ucS0HistogramResult = 0;
BYTE g_ucS6HistogramResult = 0;
#endif

#if(_SIX_COLOR_SUPPORT == _ON)
StructSixColorParameters g_stSixColor[6] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerColorSpaceConvertLoadTable(void);
void ScalerColorSpaceConvert(EnumColorSpace enumColorFormat);

#if(_VGA_SUPPORT == _ON)
void ScalerColorDigitalFilter(bit bOn);
void ScalerColorDigitalFilterAdjust(void);

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
void ScalerColorDigitalFilterEnhancePhaseAdjust(BYTE *pucBGRGain);
#endif

#endif

#if(_D_DITHER_SUPPORT == _ON)
void ScalerColorDDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE *pThresholdTable, BYTE ucBankNum);
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
void ScalerColorSRGBAdjust(BYTE *pSrgbArray);
#endif // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if((_DCR_SUPPORT == _ON)||(_ENERGY_STAR_SUPPORT == _ON))
void ScalerColorDCROnOff(bit bOnOff);
void ScalerColorDCRThresholdAdjust(BYTE ucThreshold1, BYTE ucThreshold2);
DWORD ScalerColorDCRReadResult(EnumDCRAdjOption enumAdjustOption);
#endif // End of #if(_DCR_SUPPORT == _ON)

#if((_DCC_HISTOGRM_INFO == _ON) && (_DCC_HISTOGRAM_THD_CHANGE == _ON))
void ScalerColorDCCChangeHistogramThd(void);
void ScalerColorDCCGetHistoInfo(BYTE *pucReadArray);
#endif // End of #if((_DCC_HISTOGRM_INFO == _ON) && (_DCC_HISTOGRAM_THD_CHANGE == _ON))

#if(_ICM_SUPPORT == _ON)
void ScalerColorICM(bit bOn);
void ScalerColorICMLoadTable(BYTE *pICMTable, BYTE ucBankNum, BYTE ucCMSel);
void ScalerColorICMAdjust(WORD usAdjustOption);
#endif // End of #if(_ICM_SUPPORT == _ON)

#if(_SIX_COLOR_SUPPORT == _ON)
void ScalerColorSixColorAdjust(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition); 
void ScalerColorSixColorGetDeltaUV(BYTE ucColorIndex, BYTE ucCenterRightLeft, SBYTE *pchDeltaUV, SWORD shRightDeltaHue, SWORD shRightDeltaSat, SWORD *pshUVValue);   
void ScalerColorSixColorSetDeltaUV(BYTE ucColorIndex, BYTE ucLeftCenterRight, SBYTE *pchDeltaUV);
void ScalerColorSixColorSetAngleRB(BYTE ucColorIndex);
void ScalerColorSixColorGetCurrentRightLastLeft(BYTE ucColorIndex, SBYTE *pchDeltaUV);
void ScalerColorSixColorInterplateLeftR(BYTE ucColorIndex, SBYTE *pchCentDeltaUV, SBYTE *pchDeltaUV);
void ScalerColorSixColorEnable(void);
BYTE ScalerColorSixColorLog2(WORD usData);
void ScalerColorSixColorHSToUV(SWORD shHue, SWORD shSat, SWORD *pshUout, SWORD *pshVout);
SDWORD ScalerColorSixColorTangent(SWORD shDegree);
#endif // End of #if(_SIX_COLOR_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
void ScalerColorHLW(bit bOn);
void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight);
void ScalerColorHLWBorderAdjust(BYTE ucBorderEn, BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue);
#endif // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Load Table for Color Space Conversion
// Input Value  : Input Color Space
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvertLoadTable(void)
{   
    // Load D-Domain YUV2RGB Table according to Colorimetry
    switch(GET_COLORIMETRY())
    {
        case _COLORIMETRY_ITU601:
            ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU601, sizeof(tCOLOR_CONV_YUV2RGB_ITU601), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            break;

        case _COLORIMETRY_ITU709:
            ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709, sizeof(tCOLOR_CONV_YUV2RGB_ITU709), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            break;

        case _COLORIMETRY_EXT:
            if(GET_EXT_COLORIMETRY() == _COLORIMETRY_XVYCC601)
            {
                ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU601, sizeof(tCOLOR_CONV_YUV2RGB_ITU601), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            }
            else
            {
                ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709, sizeof(tCOLOR_CONV_YUV2RGB_ITU709), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            }
            break;

        default:
            ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709, sizeof(tCOLOR_CONV_YUV2RGB_ITU709), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            break;
    }

    // Set YCbCr Clamp
    ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1), (_BIT2 | _BIT1));    
}

//--------------------------------------------------
// Description  : Color Space Conversion function.
// Input Value  : Input Color Space
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvert(EnumColorSpace enumColorFormat)
{
    ScalerTimerWaitForEvent(_EVENT_DVS);

    if((enumColorFormat == _COLOR_SPACE_YCBCR422) || (enumColorFormat == _COLOR_SPACE_YCBCR444) || (enumColorFormat == _COLOR_SPACE_YPBPR))
    {
        // Enable D-Domain YUV2RGB
        ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
    }
    else if(enumColorFormat == _COLOR_SPACE_RGB)
    {
        // Disable D-Domain YUV2RGB
        ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
    }    
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable digital filter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDigitalFilter(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        ScalerSetBit(CM_99_DIGITAL_FILTER_PORT, ~(_BIT7 | _BIT6 | _BIT5 ), (_BIT7 | _BIT6 | _BIT5));
    }
    else
    {
        ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        ScalerSetBit(CM_99_DIGITAL_FILTER_PORT, ~(_BIT7 | _BIT6 | _BIT5 ), 0x00);
    }
}

//-------------------------------------------------
// Description  : Set digital filter
// Input Value  : None
// Output Value : None
//-------------------------------------------------
void ScalerColorDigitalFilterAdjust(void)
{
    // Disable NR
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7);
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, 0x00);


#if(_DIG_FILTER_PHASE_ENABLE == _ENABLE)
    // Set phase  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);

#if(_DIG_FILTER_PHASE_HIGHFREQ_ADCCLOCKTHD != 0)     
    if((GET_INPUT_PIXEL_CLK() / 10) >= _DIG_FILTER_PHASE_HIGHFREQ_ADCCLOCKTHD)
    {
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PHASE_HIGHFREQ_DIV_VALUE << 2) | _BIT7));
        ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7 | _BIT4);
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, _DIG_FILTER_PHASE_HIGHFREQ_THD);
    }
    else
    {
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PHASE_DIV_VALUE << 2) | _BIT7));
        ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7 | _BIT4);
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, _DIG_FILTER_PHASE_THD);
    }
#else
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PHASE_DIV_VALUE << 2) | _BIT7));
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7 | _BIT4);
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, _DIG_FILTER_PHASE_THD);
#endif  // End of #if(_DIG_FILTER_PHASE_MODIFY_ADCCLOCKTHD != 0)

#endif  // End of #if(_DIG_FILTER_PHASE_ENABLE == _ENABLE)

#if(_DIG_FILTER_NSMEAR_ENABLE == _ENABLE)
    // Set negative smear  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT5);
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_NSMEAR_THD << 4) | (_DIG_FILTER_NSMEAR_DIV_VALUE << 2) | _BIT7));
#endif  // End of #if(_DIG_FILTER_NSMEAR_ENABLE == _ENABLE)

#if(_DIG_FILTER_PSMEAR_ENABLE == _ENABLE)
    // Set positive smear  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT5 | _BIT4));
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PSMEAR_THD << 4) | (_DIG_FILTER_PSMEAR_DIV_VALUE << 2) | _BIT7));
#endif  // End of #if(_DIG_FILTER_PSMEAR_ENABLE == _ENABLE)

#if(_DIG_FILTER_NRING_ENABLE == _ENABLE)
    // Set negative ring  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT6);
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_NRING_THD << 4) | (_DIG_FILTER_NRING_DIV_VALUE << 2) | _BIT7));
#endif  // End of #if(_DIG_FILTER_NRING_ENABLE == _ENABLE)

#if(_DIG_FILTER_PRING_ENABLE == _ENABLE)
    // Set positive ring  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PRING_THD << 4) | (_DIG_FILTER_PRING_DIV_VALUE << 2) | _BIT7));
#endif  // End of #if(_DIG_FILTER_PRING_ENABLE == _ENABLE)

#if(_DIG_FILTER_EXTENSION_ENABLE == _ENABLE)
    // Use extension data
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
    ScalerSetBit(CM_99_DIGITAL_FILTER_PORT, ~_BIT4, _BIT4);
#endif  // End of #if(_DIG_FILTER_EXTENSION_ENABLE == _ENABLE)

}

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
//--------------------------------------------------
// Description  : Enable IDither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDigitalFilterEnhancePhaseAdjust(BYTE *pucBGRGain)
{   
    BYTE ucI = 0;
    BYTE ucTHD1 = 0;
    WORD usTHD2 = 0;
    
    for(ucI = _DIG_FILTER_BGAIN; ucI < _DIG_FILTER_RGB_CHANNEL; ucI++)
    {
        if(pucBGRGain[ucI] < _DIG_FILTER_DELTA)
        {
            pucBGRGain[ucI] = 0;
            ucTHD1 = 0xDF;
        }
        else
        {
            usTHD2 = (WORD)(_DIG_FILTER_DELTA) * 512 / pucBGRGain[ucI];
            
            if(usTHD2 > 250)
            {
                pucBGRGain[ucI] = 0;
                ucTHD1 = 0xDF;
            }
            else if(usTHD2 > (_DIG_FILTER_THRESHOLD1 + 32))
            {
                ucTHD1 = usTHD2 - 32;
            }
            else
            {
                ucTHD1 = _DIG_FILTER_THRESHOLD1;
            }
        }   

        // Enable Port Access
        switch(ucI)
        {
            case _DIG_FILTER_BGAIN:

                ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT0));

                break;

            case _DIG_FILTER_GGAIN:

                ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT4 | _BIT0));

                break;

            case _DIG_FILTER_RGAIN:

                ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT5 | _BIT0));

                break;

            default:

                break;
        }

        // Set Threshold1
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ucTHD1);

        // Set Offset for Threshold2
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, _DIG_FILTER_OFFSET);

        // Set Gain2
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, pucBGRGain[ucI]);

        // Disable Port Access
        ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), 0x00);
    }

    // Enable Phase Mode
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, 0x80);

    // Select New Phase Mode
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT4 | _BIT0));
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, 0x80);
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), 0x00);
}
#endif  // End of #if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)

#endif // End of #if(_VGA_SUPPORT == _ON)


#if(_D_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust D dither 
// Input Value  : Dithering Tables
// Output Value : None
//--------------------------------------------------
void ScalerColorDDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE *pThresholdTable, BYTE ucBankNum)
{
    // Set D-Dither Table
    if(pDitherTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
        ScalerBurstWrite(pDitherTable, 24, ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }

    // Set D-Dither Seq Table
    if(pDitherSeqTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
        ScalerBurstWrite(pDitherSeqTable, 24, ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
    
#if(_D_DITHER_TEMP == _ENABLE)
    // Set D-Dither Temporal Offset Table
    if(pDitherTempoffsetTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
        ScalerBurstWrite(pDitherTempoffsetTable, 4, ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
#else
    if(pDitherTempoffsetTable != _NULL_POINTER)
    {
    
    }
#endif

    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), 0x00);

    if(pThresholdTable != _NULL_POINTER)
    {

    }

    // Enable D-Dither Function and Temporal Dither
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ((_D_DITHER_TEMP << 4) | (_D_DITHER_VALUE_SIGN << 3) | (_D_DITHER_V_FRAME_MOD << 1) | ( _D_DITHER_H_FRAME_MOD)));
}
#endif // End of #if(_D_DITHER_SUPPORT == _ON)

#if(_GLOBAL_HUE_SATURATION == _ON)
//--------------------------------------------------
// Description  : Adjust sRGB function
// Input Value  : sRGB Matrix
//                sRGB Precision Type
// Output Value : None
//--------------------------------------------------
void ScalerColorSRGBAdjust(BYTE *pSrgbArray)
{
    pData[0] = 0;
    pData[1] = 0;

    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT6, 0x00);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // R Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT5); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);

    // G Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT3); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);

    // B Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);
    
    // RR, RG, RB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT3);  
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &pSrgbArray[0], _NON_AUTOINC);
       
    // GR, GG, GB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT4); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &pSrgbArray[6], _NON_AUTOINC);

    // BR, BG, BB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT4 | _BIT3); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &pSrgbArray[12], _NON_AUTOINC);

    // Use 3bit shift for Hue adjust 
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT6, _BIT6);
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT6 | _BIT5), _BIT6);
    
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT7, _BIT7);

    // Disable Access Port
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x00);
}
#endif  // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if((_DCR_SUPPORT == _ON)||(_ENERGY_STAR_SUPPORT == _ON))
//--------------------------------------------------
// Description  : DCR ON or OFF
// Input Value  : _ON/ _OFF
// Output Value : None
//--------------------------------------------------
void ScalerColorDCROnOff(bit bOnOff)
{
    if(bOnOff == _OFF)
    {        
        ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT1 | _BIT0), 0x00);
    }
    else
    {
        if(ScalerGetBit(P7_D8_DCR_ACCESS_PORT, _BIT0) == 0x00)
        {
            // Set DCR enable
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT0), _BIT0);
            
		    // Wait DCR Measure Finish.
            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);            
        }
    }
}

//--------------------------------------------------
// Description  : Set DCR TH1 & TH2
// Input Value  : TH1 & TH2
// Output Value : None
//--------------------------------------------------
void ScalerColorDCRThresholdAdjust(BYTE ucThreshold1, BYTE ucThreshold2)
{
    // Force ucThreshold2 to an even value due to DCR bug
    ucThreshold2 = ((ucThreshold2 % 2) == 0) ? ucThreshold2 : ucThreshold2 + 1;
    
    ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_P7_D9_PT_00_DCR_THRESHOLD1 << 2));
    ScalerSetByte(P7_D9_DCR_DATA_PORT, ucThreshold1);
    ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_P7_D9_PT_01_DCR_THRESHOLD2 << 2));
    ScalerSetByte(P7_D9_DCR_DATA_PORT, ucThreshold2);
}

//--------------------------------------------------
// Description  : Read DCR Histogram Result
// Input Value  : DCR Histogram Information Option
// Output Value : DCR Histogram Information 
//--------------------------------------------------
DWORD ScalerColorDCRReadResult(EnumDCRAdjOption enumAdjustOption)
{
    switch(enumAdjustOption)
    {
        case _DCR_ABOVE_TH1_NUM:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_02_DCR_ABOVE_TH1_NUM2 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 3, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 8;
            break;

        case _DCR_ABOVE_TH1_VAL:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_05_DCR_ABOVE_TH1_VAL3 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 4, pData, _NON_AUTOINC);
            break;

        case _DCR_ABOVE_TH2_NUM:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_09_DCR_ABOVE_TH2_NUM2 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 3, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 8;
            break;

        case _DCR_ABOVE_TH2_VAL:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_0C_DCR_ABOVE_TH2_VAL3 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 4, pData, _NON_AUTOINC);
            break;

        case _HIGH_LV_NUM_R:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_10_DCR_HIGH_LV_NUM_R1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _LOW_LV_NUM_R:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_12_DCR_LOW_LV_NUM_R1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _HIGH_LV_VAL_R:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_14_DCR_HIGH_LV_VAL_R << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _LOW_LV_VAL_R:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_15_DCR_LOW_LV_VAL_R << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _HIGH_LV_NUM_G:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_16_DCR_HIGH_LV_NUM_G1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _LOW_LV_NUM_G:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_18_DCR_LOW_LV_NUM_G1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _HIGH_LV_VAL_G:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_1A_DCR_HIGH_LV_VAL_G << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _LOW_LV_VAL_G:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_1B_DCR_LOW_LV_VAL_G << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _HIGH_LV_NUM_B:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_1C_DCR_HIGH_LV_NUM_B1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _LOW_LV_NUM_B:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_1E_DCR_LOW_LV_NUM_B1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _HIGH_LV_VAL_B:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_20_DCR_HIGH_LV_VAL_B << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _LOW_LV_VAL_B:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_21_DCR_LOW_LV_VAL_B << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;
    }

    ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~_BIT1, 0x00);

    return PDATA_DWORD(0);
}
#endif // End of #if(_DCR_SUPPORT == _ON)

#if((_DCC_HISTOGRM_INFO == _ON) && (_DCC_HISTOGRAM_THD_CHANGE == _ON))
//--------------------------------------------------
// Description  : Change DCC Histogram Thd and Get Normalized S0 or S6
// Input Value  : None 
// Output Value : None
//--------------------------------------------------
void ScalerColorDCCChangeHistogramThd(void)
{
    WORD usHWidth = 0;
    WORD usVHeight = 0;
    BYTE ucI = 0;
    BYTE ucReadArray[3] = {0};

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    WORD usHStart = 0;
    WORD usHEnd = 0;
    WORD usVStart = 0;
    WORD usVEnd = 0;
    BYTE ucBorder = 0;
#endif

    if(ScalerGetBit(P7_C7_DCC_CTRL0, _BIT7) == 0x00)
    {   
        return ;
    }

    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_18_Y_HISTOGRAM_THD);
    if(ScalerGetByte(P7_CA_DCC_DATA_PORT) == _DCC_HISTO_THD1)
    {
        ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_18_Y_HISTOGRAM_THD);
        ScalerSetByte(P7_CA_DCC_DATA_PORT, _DCC_HISTO_THD2);
    }
    else
    {
        ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_18_Y_HISTOGRAM_THD);
        ScalerSetByte(P7_CA_DCC_DATA_PORT, _DCC_HISTO_THD1);   
    }

    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);

    // Pop out result
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_0C_POPUP_CTRL);
    ScalerGetByte(P7_CA_DCC_DATA_PORT);

    // Get Histogram Info
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_10_S0_VALUE);

    for(ucI = 0; ucI < 3; ucI++)
    {
        ucReadArray[ucI] = ScalerGetByte(P7_CA_DCC_DATA_PORT);
    }

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    // Check if highlight window on
    if(ScalerGetBit(CM_60_HW_ACCESS_PORT, _BIT6) != 0x00) 
    {
        ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT2)); 

        // Get highlight window type
        switch(ScalerGetBit(CM_61_HW_DATA_PORT, (_BIT3 | _BIT2)))
        {
                // Full region
                case 0x00:

                    usHWidth = g_stMDomainOutputData.usHWidth;
                    usVHeight = g_stMDomainOutputData.usVHeight;
                    break;

                // Inside window
                case _BIT2:

                    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    usHStart = (WORD)(ScalerGetByte(CM_61_HW_DATA_PORT) << 8) | (ScalerGetByte(CM_61_HW_DATA_PORT));
                    usHEnd = (WORD)(ScalerGetByte(CM_61_HW_DATA_PORT) << 8) | (ScalerGetByte(CM_61_HW_DATA_PORT));
                    usVStart = (WORD)(ScalerGetByte(CM_61_HW_DATA_PORT) << 8) | (ScalerGetByte(CM_61_HW_DATA_PORT));
                    usVEnd = (WORD)(ScalerGetByte(CM_61_HW_DATA_PORT) << 8) | (ScalerGetByte(CM_61_HW_DATA_PORT));
                    ucBorder = ScalerGetByte(CM_61_HW_DATA_PORT);
                    usHWidth = usHEnd + ucBorder - usHStart;
                    usVHeight = usVEnd + ucBorder - usVStart;
                    break;

                // Outside window
                case _BIT3:

                    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                    usHStart = (WORD)(ScalerGetByte(CM_61_HW_DATA_PORT) << 8) | (ScalerGetByte(CM_61_HW_DATA_PORT));            
                    usHEnd = (WORD)(ScalerGetByte(CM_61_HW_DATA_PORT) << 8) | (ScalerGetByte(CM_61_HW_DATA_PORT));
                    usVStart = (WORD)(ScalerGetByte(CM_61_HW_DATA_PORT) << 8) | (ScalerGetByte(CM_61_HW_DATA_PORT));
                    usVEnd = (WORD)(ScalerGetByte(CM_61_HW_DATA_PORT) << 8) | (ScalerGetByte(CM_61_HW_DATA_PORT));
                    ucBorder = ScalerGetByte(CM_61_HW_DATA_PORT);
                    usHWidth = usHEnd + ucBorder - usHStart;
                    usVHeight = usVEnd + ucBorder - usVStart;
                    break;

                default:
                    usHWidth = g_stMDomainOutputData.usHWidth;   
                    usVHeight = g_stMDomainOutputData.usVHeight; 
                    break;
        }

        ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    }
    else
    {
        usHWidth = g_stMDomainOutputData.usHWidth;   
        usVHeight = g_stMDomainOutputData.usVHeight; 
    }
#else
    usHWidth = g_stMDomainOutputData.usHWidth;   
    usVHeight = g_stMDomainOutputData.usVHeight; 
#endif
    
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_18_Y_HISTOGRAM_THD);
    if(ScalerGetByte(P7_CA_DCC_DATA_PORT) == _DCC_HISTO_THD2)
    {
        g_ucS0HistogramResult = ((((DWORD)ucReadArray[0]) << 16) | (((DWORD)ucReadArray[1]) << 8)  | (ucReadArray[2])) * 255 / usHWidth / usVHeight;
    }
    else
    {
        g_ucS6HistogramResult = ((((DWORD)ucReadArray[0]) << 16) | (((DWORD)ucReadArray[1]) << 8)  | (ucReadArray[2])) * 255 / usHWidth / usVHeight;
    }
}

//--------------------------------------------------
// Description  : Get DCC Ymax/Ymin and Y Histogram infomation
// Input Value  : Pointer to get Ymax/Ymin/Y Histogram 
// Output Value : None
//--------------------------------------------------
void ScalerColorDCCGetHistoInfo(BYTE *pucReadArray)
{
    BYTE ucI = 0;

    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);

    // Pop out result
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_0C_POPUP_CTRL);
    ScalerGetByte(P7_CA_DCC_DATA_PORT);

    // Get Histogram Info
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_0E_Y_MAX_VAL);

    for(ucI = 0; ucI < 5; ucI++)
    {
        pucReadArray[ucI] = ScalerGetByte(P7_CA_DCC_DATA_PORT);
    }

    pucReadArray[2] = g_ucS0HistogramResult;
    pucReadArray[8] = g_ucS6HistogramResult;

    pucReadArray[3] = 0;
    pucReadArray[4] = 0;
    pucReadArray[5] = 0;
    pucReadArray[6] = 0;
    pucReadArray[7] = 0;
}
#endif // End of #if((_DCC_HISTOGRM_INFO == _ON) && (_DCC_HISTOGRAM_THD_CHANGE == _ON))

#if(_ICM_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable ICM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorICM(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(P7_D0_ICM_CTRL, ~_BIT7, _BIT7);
    }
    else
    {
        ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT7), 0x00);
    }
}

//--------------------------------------------------
// Description   : Fill ICM table, Enable Local CM, Set adjust option
// Input Value   : None
// Output Value  : None
//--------------------------------------------------
void ScalerColorICMLoadTable(BYTE *pICMTable, BYTE ucBankNum, BYTE ucCMSel)
{
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), ucCMSel);
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _P7_D3_PT_00_MST_HUE_HB);
    ScalerBurstWrite(pICMTable, _ICM_TABLE_SIZE, ucBankNum, P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
}

//--------------------------------------------------
// Description  : Adjust ICM Function
// Input Value  : Adjust Option
// Output Value : None
//--------------------------------------------------
void ScalerColorICMAdjust(WORD usAdjustOption)
{
    ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (((BYTE)((bit)(usAdjustOption & _Y_CORRECTION_MODE)) << 6) |
                ((BYTE)((bit)(usAdjustOption & _UV_DELTA_RANGE)) << 5) | ((BYTE)((bit)(usAdjustOption & _CM0_ENABLE)) << 4) | ((BYTE)((bit)(usAdjustOption & _CM1_ENABLE)) << 3) | 
                ((BYTE)((bit)(usAdjustOption & _CM2_ENABLE)) << 2) | ((BYTE)((bit)(usAdjustOption & _CM3_ENABLE)) << 1) | ((BYTE)((bit)(usAdjustOption & _CM4_ENABLE)))));

    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT4 | _BIT3), (((BYTE)((bit)(usAdjustOption & _UV_DELTA_RANGE_EXTEND)) << 4) | ((BYTE)((bit)(usAdjustOption & _CM5_ENABLE)) << 3)));
}
#endif // End of #if(_ICM_SUPPORT == _ON)

#if(_SIX_COLOR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : 6 Color ICM hue adjust
// Input Value  : ucColorIndex --> R/G/B/C/M/Y
//                ucHuePosition --> Hue adjusted by user
//                ucSatPosition --> Saturation adjusted by user
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorAdjust(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition)
{
    BYTE ucScale = 0;
    BYTE ucLastIndex = 0;
    BYTE ucNextIndex = 0;
    SBYTE pchDeltaUV[16] = {0};  

    if(ucHuePosition > 50)
    {
        g_stSixColor[ucColorIndex].shCentDeltaHue = (SWORD)tSIX_COLOR_DELTA_HUE_MAX[ucColorIndex] * ((ucHuePosition - 50) * 2) / 100;
    }
    else
    {
        g_stSixColor[ucColorIndex].shCentDeltaHue = (SWORD)tSIX_COLOR_DELTA_HUE_MIN[ucColorIndex] * ((50 - ucHuePosition) * 2) / 100; 
    }    
	        
    if(ucSatPosition < 100)
    {       
        g_stSixColor[ucColorIndex].shCentDeltaHue = g_stSixColor[ucColorIndex].shCentDeltaHue * ucSatPosition / 100;
    } 

    // Delta Saturation = (-128 * 200 + ((127 - (-128)) * Sat) + 100) / 200
    g_stSixColor[ucColorIndex].shCentDeltaSat = ((SWORD)-25600 + ((SWORD)255 * ucSatPosition) + 100) / 200;
   
    ucLastIndex = (ucColorIndex == 0) ? 5 : (ucColorIndex - 1);
    ucNextIndex = (ucColorIndex == 5) ? 0 : (ucColorIndex + 1);
     
    ScalerColorSixColorGetDeltaUV(ucColorIndex, _SIX_COLOR_CENTER, pchDeltaUV, NULL, NULL, tUV_VALUE[2 * ucColorIndex]); 

    if(ucColorIndex == _SIX_COLOR_CYAN)
    {
        if((g_stSixColor[_SIX_COLOR_CYAN].shCentDeltaSat == -127) && (g_stSixColor[_SIX_COLOR_GREEN].shCentDeltaSat == -127))
        {
            pchDeltaUV[14] = 67;
            pchDeltaUV[15] = 124;
        }
     }
    
     ScalerColorSixColorSetDeltaUV(ucColorIndex, _SIX_COLOR_CENTER_ENABLE, pchDeltaUV); 
     ScalerColorSixColorGetCurrentRightLastLeft(ucColorIndex, pchDeltaUV);
     ScalerColorSixColorGetCurrentRightLastLeft(ucNextIndex, pchDeltaUV);    
}

//--------------------------------------------------
// Description  : Calculate U/V offset 
// Input Value  : ucColorIndex --> R/G/B/C/M/Y
//                ucCenterRightLeft --> _SIX_COLOR_CENTER / _SIX_COLOR_RIGHT
//                pchDeltaUV --> UV Value to be saved
//                shRightDeltaHue
//                shRightDeltaSat
//                pshUVValue --> Initial UV Value (Master / Right)
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorGetDeltaUV(BYTE ucColorIndex, BYTE ucCenterRightLeft, SBYTE *pchDeltaUV, SWORD shRightDeltaHue, SWORD shRightDeltaSat, SWORD *pshUVValue) 
{
    BYTE ucPointIndex = 0;
    SWORD shDeltaU = 0; 
    SWORD shDeltaV = 0;
    SWORD shHue = 0;
    SWORD shSat = 0;  

    switch(ucCenterRightLeft)
    {
        case _SIX_COLOR_CENTER:

            shHue = tSIX_COLOR_DEFAULT_ANGLE[ucColorIndex] + g_stSixColor[ucColorIndex].shCentDeltaHue;
            
            if(shHue < 0)
            {
                shHue += 4096;     
            }
            else if(shHue > 4096)
            {
                shHue -= 4096; 
            }
            
            for(ucPointIndex = 0; ucPointIndex < 8; ucPointIndex++)
            {   
                shSat = tSIX_COLOR_SATURATION[ucPointIndex] + (((SDWORD)g_stSixColor[ucColorIndex].shCentDeltaSat * tSIX_COLOR_DELTA_SATURATION[ucPointIndex]) >> 8);
                shSat = MAXOF(0, MINOF(511, shSat));

                ScalerColorSixColorHSToUV(shHue, shSat, &shDeltaU, &shDeltaV);              
                shDeltaU = shDeltaU - pshUVValue[2 * ucPointIndex];
                shDeltaV = shDeltaV - pshUVValue[2 * ucPointIndex + 1];

                shDeltaU = MAXOF(-128, MINOF(127, shDeltaU));
                shDeltaV = MAXOF(-128, MINOF(127, shDeltaV));
               
                // Download
                pchDeltaUV[ucPointIndex * 2] = shDeltaU & 0xFF;
                pchDeltaUV[ucPointIndex * 2 + 1] = shDeltaV & 0xFF;
            }
            
            break;

        case _SIX_COLOR_RIGHT:
     
            // Adjusted Point
            shHue = tSIX_COLOR_DEFAULT_ANGLE[ucColorIndex] - tSIX_COLOR_HUE_RANGE[ucColorIndex][_SIX_COLOR_RIGHT] + shRightDeltaHue;

            if(shHue < 0)
            {
                shHue += 4096;     
            }
            else if(shHue > 4096)
            {
                shHue -= 4096; 
            }
            
            // Calculate Right delta U/V
            for(ucPointIndex = 0; ucPointIndex < 8; ucPointIndex++)
            {
                shSat = tSIX_COLOR_SATURATION[ucPointIndex] + (((SDWORD)shRightDeltaSat * tSIX_COLOR_DELTA_SATURATION[ucPointIndex]) >> 8);
                shSat = MAXOF(0, MINOF(511, shSat));
              
                ScalerColorSixColorHSToUV(shHue, shSat, &shDeltaU, &shDeltaV);
                
                shDeltaU = shDeltaU - pshUVValue[2 * ucPointIndex];
                shDeltaV = shDeltaV - pshUVValue[2 * ucPointIndex + 1];
 
                shDeltaU = MAXOF(-128, MINOF(127, shDeltaU));
                shDeltaV = MAXOF(-128, MINOF(127, shDeltaV));
                
                // Down load
                pchDeltaUV[ucPointIndex * 2] = shDeltaU & 0xFF;
                pchDeltaUV[ucPointIndex * 2 + 1] = shDeltaV & 0xFF;    
            }
            
            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Download data to IC 
// Input Value  : ucColorIndex --> R/G/B/C/M/Y
//                ucLeftCenterRight --> _SIX_COLOR_CENTER_ENABLE/_SIX_COLOR_LEFT_ENABLE/_SIX_COLOR_RIGHT_ENABLE
//                pchDeltaUV --> DeltaUV
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorSetDeltaUV(BYTE ucColorIndex, BYTE ucLeftCenterRight, SBYTE *pchDeltaUV)
{     
    BYTE ucDataIndex = 0;
    BYTE ucData = 0;
    
    // Set Center & Left
    ScalerColorSixColorSetAngleRB(ucColorIndex); 

    switch(ucLeftCenterRight)
    {
        case _SIX_COLOR_CENTER_ENABLE:
            
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);    
            
            for(ucDataIndex = 0; ucDataIndex < 16; ucDataIndex++)
            {
                if(pchDeltaUV[ucDataIndex] < 0)
                {
                    ucData = pchDeltaUV[ucDataIndex] + 256; 
                }
                else
                {
                    ucData = pchDeltaUV[ucDataIndex];
                }            
                
                ScalerSetByte(P7_D3_ICM_DATA_PORT, ucData);
            }       
            
            break;

        case _SIX_COLOR_LEFT_ENABLE:

            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x23); 
            
            for(ucDataIndex = 0; ucDataIndex < 16; ucDataIndex++)
            {
                if(pchDeltaUV[ucDataIndex] < 0)
                {
                    ucData = pchDeltaUV[ucDataIndex] + 256;
                }
                else
                {
                    ucData = pchDeltaUV[ucDataIndex];
                }
                
                ScalerSetByte(P7_D3_ICM_DATA_PORT, ucData);
            }       

            break;

        case _SIX_COLOR_RIGHT_ENABLE:

            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x13);  

            for(ucDataIndex = 0; ucDataIndex < 16; ucDataIndex++)
            {
                if(pchDeltaUV[ucDataIndex] < 0)
                {
                    ucData = pchDeltaUV[ucDataIndex] + 256;
                }
                else
                {
                    ucData = pchDeltaUV[ucDataIndex];
                }
                
                ScalerSetByte(P7_D3_ICM_DATA_PORT, ucData);
            }       

            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Set range for one CM 
// Input Value  : ucColorIndex --> R/G/B/C/M/Y
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorSetAngleRB(BYTE ucColorIndex)
{
    // Set Page 7 D0,D1,D3-00,01,02
    BYTE ucLeftRange = 0;  
    BYTE ucRightRange = 0;

    // Enable CMn Port
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), ucColorIndex);
     
    // Access Port
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, _P7_D3_PT_00_MST_HUE_HB); 
     
    // Set Hue Angle 
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucColorIndex] >> 8);
    
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, _P7_D3_PT_01_MST_HUE_LB);  
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucColorIndex] & 0xFF);
     
    // Set range & buffer  
    ucLeftRange = (ScalerColorSixColorLog2(tSIX_COLOR_HUE_RANGE[ucColorIndex][_SIX_COLOR_LEFT])) << 6;
    ucRightRange = (ScalerColorSixColorLog2(tSIX_COLOR_HUE_RANGE[ucColorIndex][_SIX_COLOR_RIGHT])) << 2;  
   
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, _P7_D3_PT_02_HUB_SEL);    
    ScalerSetByte(P7_D3_ICM_DATA_PORT, (ucLeftRange | ucRightRange));
}

//--------------------------------------------------
// Description  : Calculate Hue/Sat offset of current right and last left axis 
// Input Value  : ucColorIndex --> R/G/B/C/M/Y
//                pchDeltaUV --> DeltaUV
// Output Value : None
//-------------------------------------------------- 
void ScalerColorSixColorGetCurrentRightLastLeft(BYTE ucColorIndex, SBYTE *pchDeltaUV)
{
    BYTE ucLastIndex = 0;
    BYTE ucCaseIndex = 0;
    SBYTE chCentDeltaUV[16] = {0};	
    SWORD shRightDeltaHue = 0;	
    SWORD shRightDeltaSat = 0;	

    ucLastIndex = (ucColorIndex == 0) ? 5 : (ucColorIndex - 1);
     
    //CM1_R = SatCM1/2;
    shRightDeltaHue = g_stSixColor[ucColorIndex].shCentDeltaHue / 2;                    
    
    if(((g_stSixColor[ucColorIndex].shCentDeltaSat * g_stSixColor[ucLastIndex].shCentDeltaSat > 0) && (ABSDWORD(g_stSixColor[ucLastIndex].shCentDeltaSat, 0) < (ABSDWORD(g_stSixColor[ucColorIndex].shCentDeltaSat, 0) / 2))) ||
       ((g_stSixColor[ucLastIndex].shCentDeltaSat >= 0) && (g_stSixColor[ucColorIndex].shCentDeltaSat <= 0)))
    { 
        shRightDeltaSat = g_stSixColor[ucColorIndex].shCentDeltaSat / 2;  
    }
    else 
    {
        shRightDeltaSat = g_stSixColor[ucLastIndex].shCentDeltaSat;
    }

    ScalerColorSixColorGetDeltaUV(ucColorIndex, _SIX_COLOR_RIGHT, pchDeltaUV, shRightDeltaHue, shRightDeltaSat, tUV_VALUE[2 * ucColorIndex + 1]);

    if(ucColorIndex == _SIX_COLOR_CYAN)  
    {
        if((g_stSixColor[ucColorIndex].shCentDeltaSat == -127) && (g_stSixColor[_SIX_COLOR_GREEN].shCentDeltaSat == -127))
        {
            pchDeltaUV[14] = 111;
            pchDeltaUV[15] = 34;
        }
    }

    ScalerColorSixColorSetDeltaUV(ucColorIndex, _SIX_COLOR_RIGHT_ENABLE, pchDeltaUV);	  
       
    // CM0_L = extrapolate_ (CM0_C & CM1_R); 
    ScalerColorSixColorGetDeltaUV(ucLastIndex, _SIX_COLOR_CENTER, chCentDeltaUV, NULL, NULL, tUV_VALUE[2 * ucLastIndex]);

    // Interpolate CM0_L        
    ScalerColorSixColorInterplateLeftR(ucLastIndex, chCentDeltaUV, pchDeltaUV);
    
    ScalerColorSixColorSetDeltaUV(ucLastIndex, _SIX_COLOR_LEFT_ENABLE, pchDeltaUV);
}

//--------------------------------------------------
// Description  : Calculate U/V offset of left axis 
// Input Value  : ucColorIndex --> R/G/B/C/M/Y
//                pchCentDeltaUV
//                pchDeltaUV --> DeltaUV
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorInterplateLeftR(BYTE ucColorIndex, SBYTE *pchCentDeltaUV, SBYTE *pchDeltaUV)
{
    BYTE ucDataIndex = 0;
    WORD usDeltaRange = 0;  
    WORD usDeltaAxis = 0;   
    BYTE ucNextIndex = 0;
    SWORD sDeltaValue = 0;
    
    if(ucColorIndex == 5)
    {
        ucNextIndex = 0;
    }
    else
    {
        ucNextIndex = ucColorIndex + 1;
    }
    
    usDeltaRange = tSIX_COLOR_HUE_RANGE[ucColorIndex][_SIX_COLOR_LEFT];
    
    if(ucNextIndex == 5)
    {
        usDeltaAxis = tSIX_COLOR_DEFAULT_ANGLE[ucColorIndex] + tSIX_COLOR_HUE_RANGE[ucColorIndex][_SIX_COLOR_LEFT] - (4096 - tSIX_COLOR_HUE_RANGE[ucNextIndex][_SIX_COLOR_RIGHT]);        
    }
    else
    {
        usDeltaAxis = tSIX_COLOR_DEFAULT_ANGLE[ucColorIndex] + tSIX_COLOR_HUE_RANGE[ucColorIndex][_SIX_COLOR_LEFT] - (tSIX_COLOR_DEFAULT_ANGLE[ucNextIndex] - tSIX_COLOR_HUE_RANGE[ucNextIndex][_SIX_COLOR_RIGHT]);
    }

    for(ucDataIndex = 0; ucDataIndex < 16; ucDataIndex++)
    {       
        sDeltaValue = ((SDWORD)usDeltaRange * pchDeltaUV[ucDataIndex] - (SDWORD)usDeltaAxis * pchCentDeltaUV[ucDataIndex]) / (SDWORD)(usDeltaRange - usDeltaAxis); 
        pchDeltaUV[ucDataIndex] = MAXOF(-128, MINOF(127, sDeltaValue));
    }
}

//--------------------------------------------------
// Description  : Enable ICM function 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorEnable(void)
{
    ScalerSetByte(P7_D0_ICM_CTRL, 0x9F);
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT3 | _BIT4), (_BIT3 | _BIT4));
}

//--------------------------------------------------
// Description  : Get the IC register set from left/right range value 
// Input Value  : Data to be calculated
// Output Value : None
//--------------------------------------------------
BYTE ScalerColorSixColorLog2(WORD usData)
{
    switch(usData)
    {
        case 0:
        case 64:
            
            return 0;
            
            break;

        case 128:
            
            return 1;
            
            break;

        case 256:
            
            return 2;    

            break;

        case 512:
            
            return 3;

            break;

        default:

            return 0xFF;
            
            break;
    }   
}

//--------------------------------------------------
// Description  : Hue/Sat convert to U/V
// Input Value  : Hue / Sat / U / V
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorHSToUV(SWORD shHue, SWORD shSat, SWORD *pshUout, SWORD *pshVout)
{
    SWORD shUTemp = 0;
    SWORD shVTemp = 0;
    SDWORD lTangent = 0; 

    lTangent = ScalerColorSixColorTangent(shHue); 

    if(shHue < 722)
    {
        shUTemp = 2 * (SDWORD)shSat * 1000 / (lTangent + 2000);
        shVTemp = (shSat - shUTemp) * 2;
    }
    else if(shHue < 1326)
    {
        shVTemp = shSat;  

        if(shHue != 1024)
        {
            shUTemp = (SDWORD)shVTemp * 1000 / lTangent;
        }
        else
        {
            shUTemp = 0;
        }
    }
    else if(shHue < 2048)
    {
        shUTemp = 2 * (SDWORD)shSat * 1000 / (lTangent - 2000);
        shVTemp = (shSat + shUTemp) * 2;
    }
    else if(shHue < 2770)
    {
        shUTemp = -2 * (SDWORD)shSat * 1000 / (lTangent + 2000);
        shVTemp = (-shSat - shUTemp) * 2;
    }
    else if(shHue < 3374)
    {
        shVTemp = -shSat;

        if(shHue != 3072)
        {
            shUTemp = (SDWORD)shVTemp * 1000 / lTangent;
        }
        else
        {
            shUTemp = 0;
        }
    }
    else 
    {
        shUTemp = -2 * (SDWORD)shSat * 1000 / (lTangent  - 2000);
        shVTemp = ( -shSat + shUTemp ) * 2;
    }

    *pshUout = MAXOF(-512, MINOF(511, shUTemp));   
    *pshVout = MAXOF(-512, MINOF(511, shVTemp));   
}

//--------------------------------------------------
// Description  : Calculate tangent value  
// Input Value  : shDegree --> Input angle(0~4095)
// Output Value : None
//--------------------------------------------------
SDWORD ScalerColorSixColorTangent(SWORD shDegree)
{
    BYTE ucIndex = 0;
    BYTE ucQuadrant = 0;
    WORD usDegreeTemp = 0;
    WORD usDegreeSpan = 0;
    WORD usTanValueSpan = 0;
    SDWORD lTanValue = 0;

    // Set degree to [0,4096)
    while(shDegree < 0)
    {
        shDegree += 4096;
    }

    shDegree = shDegree % 4096;

    // Locate degree on which quadrant
    ucQuadrant = (BYTE)(shDegree / 1024);
    ucQuadrant++;

    switch(ucQuadrant)
    {
        case 1:

            shDegree = shDegree;
            break;

        case 2:

            shDegree = 2048 - shDegree;
            break;

        case 3:

            shDegree = shDegree - 2048;
            break;

        case 4:

            shDegree = 4096 - shDegree;
            break;

        default:
            break;
    }

    // Locate degree on which quadrant
    if(shDegree <= usTanCurveAngle[0])
    {
        lTanValue = usTanCurveValue[0];
    }
    else
    {
        for(ucIndex = 0; usTanCurveAngle[ucIndex] < shDegree; ucIndex++)
        {
            ;
        }

        ucIndex--;

        usDegreeTemp = shDegree - usTanCurveAngle[ucIndex];
        usDegreeSpan = usTanCurveAngle[ucIndex + 1] - usTanCurveAngle[ucIndex];
        usTanValueSpan = usTanCurveValue[ucIndex + 1] - usTanCurveValue[ucIndex];
        lTanValue = usTanCurveValue[ucIndex] + (DWORD)usDegreeTemp * usTanValueSpan / usDegreeSpan;
    }

    if((ucQuadrant == 2) || (ucQuadrant == 4))
    {
        lTanValue = lTanValue * (-1);
    }

    return lTanValue;    
}
#endif  // End of #if(_SIX_COLOR_ICM_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable Highlight Window
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorHLW(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(CM_60_HW_ACCESS_PORT, ~_BIT6, _BIT6);
    }
    else
    {
        ScalerSetBit(CM_60_HW_ACCESS_PORT, ~_BIT6, 0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust highlight window region
// Input Value  : usHPos, usHWidth, usVPos, usVHeight
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight)
{
    if((usHWidth == 0) || (usVHeight == 0))
    {
        return;
    }

    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _CM_61_PT_00_HW_H_START_H);

    pData[0] = (BYTE)((usHPos >> 8) & 0x0F);
    pData[1] = (BYTE)(usHPos & 0xFF);
    pData[2] = (BYTE)(((usHPos + usHWidth) >> 8) & 0x0F);
    pData[3] = (BYTE)((usHPos + usHWidth) & 0xFF);
    pData[4] = (BYTE)((usVPos >> 8) & 0x0F);
    pData[5] = (BYTE)(usVPos & 0xFF);
    pData[6] = (BYTE)(((usVPos + usVHeight) >> 8) & 0x0F);
    pData[7] = (BYTE)((usVPos + usVHeight) & 0xFF);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    ScalerWrite(CM_61_HW_DATA_PORT, 8, pData, _NON_AUTOINC);

    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), 0x00);
}
//--------------------------------------------------
// Description  : Adjust Border Window Size
// Input Value  : ucBorderWidth, ucRed, ucGreen, ucBlue
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWBorderAdjust(BYTE ucBorderEn, BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue)
{
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _CM_61_PT_08_HW_BORDER_WIDTH);

    ScalerSetByte(CM_61_HW_DATA_PORT, ((~ucBorderEn & 0xF0) | (ucBorderWidth & 0x0F)));
    ScalerSetByte(CM_61_HW_DATA_PORT, (ucRed & 0x3F));
    ScalerSetByte(CM_61_HW_DATA_PORT, (ucGreen & 0x3F));
    ScalerSetByte(CM_61_HW_DATA_PORT, (ucBlue & 0x3F));    

    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), 0x00);
}

#endif // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
//--------------------------------------------------
// Description  : D Domain Color Space Conversion Off 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvertDDomainDisable(void)
{
    // Disable D-Domain YUV2RGB
    ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
}
#endif // End of #if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
