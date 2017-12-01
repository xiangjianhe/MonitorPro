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
// ID Code      : RL6229_Series_Color.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6229_SERIES_COLOR__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Digital Filter
//--------------------------------------------------
#define _DIG_FILTER_NSMEAR_THD              4 //effective:0~7
#define _DIG_FILTER_NSMEAR_DIV_VALUE        1 //effective:0~3

#define _DIG_FILTER_PSMEAR_THD              4 //effective:0~7
#define _DIG_FILTER_PSMEAR_DIV_VALUE        1 //effective:0~3

#define _DIG_FILTER_NRING_THD               4 //effective:0~7
#define _DIG_FILTER_NRING_DIV_VALUE         1 //effective:0~3

#define _DIG_FILTER_PRING_THD               4 //effective:0~7
#define _DIG_FILTER_PRING_DIV_VALUE         1 //effective:0~3

//--------------------------------------------------
// Definitions of ICM
//--------------------------------------------------
#define _ICM_TABLE_SIZE                     100

//--------------------------------------------------
// Definitions of Six Color
//--------------------------------------------------
#define _SIX_COLOR_RIGHTBUFFER              0
#define _SIX_COLOR_RIGHTWIDTH               1
#define _SIX_COLOR_CENTER                   2
#define _SIX_COLOR_LEFTWIDTH                3
#define _SIX_COLOR_LEFTBUFFER               4

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


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

BYTE code tCOLOR_CONV_YUV2RGB_ITU709_YUVFULL[] =
{
    4, _NON_AUTOINC,    CM_9F_PAGE_SEL,                     0x14,
    25, _AUTOINC,       P14_A2_YUB_RGB_COEF_K11_HSB,        0x04, 0x00, 0x06, 0x4d, 0x00, 0xc0, 0x01, 0xdf, 0x07, 
                                                            0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 
                                                            0x02, 0x00, 0x02, 0x00,
    _END
};

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
BYTE code tCOLOR_CONV_YUV2RGB_ITU709_RGBLIMIT[] =
{
    4, _NON_AUTOINC,    CM_9F_PAGE_SEL,                     0x14,
    25, _AUTOINC,       P14_A2_YUB_RGB_COEF_K11_HSB,        0x04, 0x00, 0x06, 0x4d, 0x00, 0xc0, 0x01, 0xdf, 0x07, 
                                                            0x6c, 0x3F, 0x00, 0x3F, 0x00, 0x3F, 0x00, 0x02, 0x54, 
                                                            0x02, 0x54, 0x02, 0x54,
    _END
};
#endif // End of #if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)

#if((_ULTRA_VIVID_SUPPORT ==_ON) || (_2D_TO_3D_FUNCTION == _ON) || (_RGB_QUANTIZATION_RANGE_SUPPORT == _ON))
BYTE code tCOLOR_CONV_RGB2YUV_ITU709[] =  //enable RGB2YUV (Full Range Table)
{
    33,  _NON_AUTOINC,   CM_9D_YUV_RGB_ACCESS,              0x00, 0xD9, 0x02, 0xDC, 0x00, 0x49, //h00~h02
                                                            0xFF, 0x8B, 0xFE, 0x76, 0x02, 0x00, //h10~h12
                                                            0x02, 0x00, 0xFE, 0x2F, 0xFF, 0xD2, //h20~h22
                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Roffset~B0ffset
                                                            0x02, 0x00, 0x02, 0x00, 0x02, 0x00, //Rgain~Bgain                                                  
    _END
};
#endif // End of #if((_ULTRA_VIVID_SUPPORT ==_ON) || (_2D_TO_3D_FUNCTION == _ON) || (_RGB_QUANTIZATION_RANGE_SUPPORT == _ON))

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
BYTE code tCOLOR_CONV_YUV2RGB_ITU601_YUVFULL[] =
{
    4,  _NON_AUTOINC,   CM_9F_PAGE_SEL,                     0x14,
    25, _AUTOINC,       P14_A2_YUB_RGB_COEF_K11_HSB,        0x04, 0x00, 0x05, 0x9c, 0x01, 0x60, 0x02, 0xdb, 0x07, 
                                                            0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
                                                            0x02, 0x00, 0x02, 0x00,                                                 
    _END
};
#endif // End of #if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Code Tables of ByPass Dither
//--------------------------------------------------
BYTE code tDITHER_TABLE_ZERO[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};  
#endif // End of #if(_I_DITHER_SUPPORT == _ON)

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
// Code Tables of SixColor
//--------------------------------------------------
SWORD code tSIX_COLOR_DEFAULT_ANGLE[][5] = 
{
    {587,  0, 135, 482,  603},
    {1191, 0, 135, 260,  419},
    {1611, 0, 437, 884, 1023},
    {2635, 0, 135, 280,  369},
    {3005, 0, 369, 504,  745},
    {3751, 0, 345, 670,  932}
};                                
                                                          
SWORD code tSIX_COLOR_U_MAX[][5] = 
{
    {1251, 1251, 1019, 3955, 3562},
    {3562, 3562, 3077, 2861, 2636},
    {2636, 2636, 2056, 2649, 2845},
    {2845, 2845, 3077, 3595, 3886},
    {3886, 3886, 1019, 1251, 1578},
    {1578, 1578, 2040, 1603, 1251},
};

SWORD code tSIX_COLOR_U_MAX_8[][3] = 
{
    { 313,  255,  -35},
    {-134, -255, -310},
    {-366, -512, -363},
    {-313, -255, -125},
    { -52,  255,  313},
    { 396,  512,  402},
};

SWORD code tSIX_COLOR_V_MAX_8[][3] = 
{
    { 396,  512,  512},
    { 512,  512,  403},
    { 290,    0, -297},
    {-396, -512, -512},
    {-512, -512, -396},
    {-231,    0,  219},
};

SWORD code tSIX_COLOR_CTOC_DELTA_UV_DOWN[][2] = 
{
    {-447,    0}, //R-->Y
    {-179, -361}, //Y-->G
    { 226, -449}, //G-->C
    { 348,    0}, //C-->B
    { 193,  390}, //B-->M
    {-226,  449}, //M-->R
};

SWORD code tSIX_COLOR_RTOR_DELTA_UV_DOWN[][4] = 
{
    { -58,  116, -390,    0},    
    {-122,    0, -111, -221},         
    {-145, -291,  198, -396},    
    {  58, -116,  203,    0},         
    { 309,    0,  140,  280},    
    { 116,  232, -198,  396},        
};

SWORD code tSIX_COLOR_LTOL_DELTA_UV_DOWN[][2] =
{
    {-221,    0},     
    {-202, -404},       
    { 107, -215},    
    { 382,    0},
    { 198,  396},         
    {-146,  293},        
};

SWORD code tSIX_COLOR_CTOC_DELTA_UV_UP[][2] = 
{
    { 197, -397}, //R-->M
    { 358,    0}, //Y-->R
    { 229,  454}, //G-->Y
    {-177,  358}, //C-->G
    {-444,    0}, //B-->C
    {-227, -450}, //M-->B
};

SWORD code tSIX_COLOR_RTOR_DELTA_UV_UP[][2] = 
{
    { 198, -396},       
    { 390,    0},             
    { 111,  221},        
    {-198,  396},         
    {-203,    0},         
    {-140, -280},        
};

SWORD code tSIX_COLOR_LTOL_DELTA_UV_UP[][4] = 
{
    { 291,    0,  146, -293},   
    {  54,  108,  221,    0},    
    {-149,  297,  202,  404},    
    {-130,    0, -107,  215},    
    { -58, -116, -382,    0},        
    { 110, -219, -198, -396},    
};

//Osd Turning position to next CM
BYTE code tR_TURNING_POSITION_DOWN[] = {61, 66, 71, 68, 75, 69};   
BYTE code tL_TURNING_POSITION_UP[] = {27, 34, 29, 33, 39, 32};                                      
#endif     //End of #if(_SIX_COLOR_SUPPORT == _ON)

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_2D_TO_3D_FUNCTION == _ON)
Struct2DTO3DSTATUS g_st2DTO3DStatus = {0};
#endif

#if(_3D_SUPPORT == _ON)
BYTE g_ucP1CA5 = 0x00;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerColorSpaceConvertLoadTable(void);
void ScalerColorSpaceConvert(EnumColorSpace enumColorFormat);

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
void ScalerColorSpaceConvertSetRGBLimitRange(bit bEnable);
#endif // End of #if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
void ScalerColorSpaceConvertSetYCCFullRange(bit bEnable);
#endif

#if(_VGA_SUPPORT == _ON)
void ScalerColorDigitalFilter(bit bOn);
void ScalerColorDigitalFilterAdjust(void);
#endif

#if(_I_DITHER_SUPPORT == _ON) 
bit ScalerColorGetIColorConvertStatus(void);
void ScalerColorIDitherOn(BYTE *pDitherTable, BYTE ucBankNum);
void ScalerColorIDitherOff(void);
#endif

#if(_D_DITHER_SUPPORT == _ON)
void ScalerColorDDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE *pThresholdTable, BYTE ucBankNum);
void ScalerColorDDitherAdjustPRShift(BYTE ucShiftOffset, bit bPRShiftEn);

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
void ScalerColorDDither3DSetPRShift(void);
#endif

#endif // End of #if(_D_DITHER_SUPPORT == _ON)

#if(_PCM_FUNCTION == _ON)
void ScalerColorPCMAdjust(EnumPCMType enumPCMMode, BYTE *pIGammaTableArray, BYTE *pOGammaTableArray, BYTE *pColorMatrixArray, BYTE ucBankNum);
void ScalerColorPCMInputGamma(bit bOn);

#if(_OCC_SUPPORT == _ON)
void ScalerColorPCMInputGammaLoadTable(bit bPCMType);
#endif  // End of #if(_OCC_SUPPORT == _ON)

void ScalerColorPCMInputGammaAdjust(BYTE *pGammaTableArray, BYTE ucBankNum);
void ScalerColorPCMOutputGammaAdjust(BYTE *pGammaTableArray, BYTE ucBankNum);
void ScalerColorPCMSRGBAdjust(BYTE *pColorMatrixArray, BYTE ucBankNum);
#endif // End of #if(_PCM_FUNCTION == _ON)

#if(_GLOBAL_HUE_SATURATION == _ON)
void ScalerColorSRGBAdjust(BYTE *pSrgbArray);
#endif // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if(_DCR_SUPPORT == _ON)
void ScalerColorDCROnOff(bit bOnOff);
void ScalerColorDCRThresholdAdjust(BYTE ucThreshold1, BYTE ucThreshold2);
DWORD ScalerColorDCRReadResult(EnumDCRAdjOption enumAdjustOption);
#endif // End of #if(_DCR_SUPPORT == _ON)

#if(_DCC_HISTOGRM_INFO == _ON)
void ScalerColorDCCGetHistoInfo(BYTE *pucReadArray);
#endif // End of #if(_DCC_HISTOGRM_INFO == _ON)

#if(_ICM_SUPPORT == _ON)
void ScalerColorICM(bit bOn);
void ScalerColorICMLoadTable(BYTE *pICMTable, BYTE ucBankNum, BYTE ucCMSel);
void ScalerColorICMAdjust(WORD usAdjustOption);
#endif // End of #if(_ICM_SUPPORT == _ON)

#if(_SIX_COLOR_SUPPORT == _ON)
void ScalerColorSixColorAdjust(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition);
void ScalerColorSixColorICMLoad(BYTE *pucICMData, BYTE ucCMSel, BYTE ucLoadSelect);    
void ScalerColorSixColorSetAngleRB(BYTE ucCMSel);
void ScalerColorSixColorEnable(void);
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
void ScalerColorUltraVividOff(void);
bit ScalerColorUltraVividGetStatus(void);

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
void ScalerColorUltraVividAdjust(BYTE *pUltraVividSetting1, BYTE *pUltraVividSetting2, BYTE *pUltraVividSetting3, BYTE *pUltraVividSetting4, BYTE *pUltraVividCDSSetting, BYTE *pUltraVividHSRSetting, BYTE ucBankNum);
#else
void ScalerColorUltraVividAdjust(BYTE *pUltraVividSetting1, BYTE *pUltraVividSetting2, BYTE *pUltraVividSetting3, BYTE *pUltraVividSetting4, BYTE *pUltraVividCDSSetting, BYTE ucBankNum);
#endif 

#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
void ScalerColorHLW(bit bOn);
void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight);
void ScalerColorHLWBorderAdjust(BYTE ucBorderEn, BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue);

#if(_ULTRA_VIVID_SUPPORT == _ON)
void ScalerColorHLWUltraVividAdjust(EnumHLWType enumHLWActive);
#endif // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#endif  // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

#if(_3D_SUPPORT == _ON) 
void ScalerColorAdjust2DTo3DAnd3DEffect(void);
void ScalerColor2Dto3DInitial(void);
void ScalerColorDepthOfFieldAdjust(void);

#if(_2D_TO_3D_FUNCTION == _ON)
void ScalerColorTwoThreeDimensionAdjust(BYTE ucChromaWeight, BYTE ucLPFWeight, BYTE ucHoleFill);
#endif // End of #if(_2D_TO_3D_FUNCTION == _ON)
#endif // End of #if(_3D_SUPPORT == _ON) 

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Load Table for Color Space Conversion
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvertLoadTable(void)
{
#if((_ULTRA_VIVID_SUPPORT ==_ON) || (_2D_TO_3D_FUNCTION == _ON) || (_RGB_QUANTIZATION_RANGE_SUPPORT == _ON))
    // Enable YUV/RGB coefficient Access
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3), (_BIT6 | _BIT4 | _BIT3));

    // Load I-Domain RGB2YUV Table for UltraVivid or RGB Quantization Limit Range Case
    ScalerBurstWrite(tCOLOR_CONV_RGB2YUV_ITU709, sizeof(tCOLOR_CONV_RGB2YUV_ITU709), GET_CURRENT_BANK_NUMBER(), CM_9D_YUV_RGB_ACCESS, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    // Disable YUV/RGB coefficient Access
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT3, 0x00);    
#endif
}

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Color Convert YCC Full Range User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvertSetRGBLimitRange(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        SET_COLOR_RGB_LIMIT_RANGE_USER(_TRUE);
    }
    else
    {
        SET_COLOR_RGB_LIMIT_RANGE_USER(_FALSE);
    }
}
#endif // End of #if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Color Convert YCC Full Range User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvertSetYCCFullRange(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        SET_COLOR_YCC_FULL_RANGE_USER(_TRUE);
    }
    else
    {
        SET_COLOR_YCC_FULL_RANGE_USER(_FALSE);
    }
}
#endif // End of #if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Color Space Conversion function.
// Input Value  : Input Color Space
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvert(EnumColorSpace enumColorFormat)
{    
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    if(enumColorFormat == _COLOR_SPACE_RGB)
    {
#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if(GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE)
        {
            // Load Table for RGB Quantization Limit Range Case
            ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709_RGBLIMIT, sizeof(tCOLOR_CONV_YUV2RGB_ITU709_RGBLIMIT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }
        else
#endif // End of #if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        {
            ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709_YUVFULL, sizeof(tCOLOR_CONV_YUV2RGB_ITU709_YUVFULL), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }

        // Set CbCr Clamp
        ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT2);    
    }
    else
    {
#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)                
        if(GET_COLOR_YCC_FULL_RANGE_USER() == _TRUE)
        {
            switch(GET_COLORIMETRY())
            {
                case _COLORIMETRY_ITU601:
                    ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU601_YUVFULL, sizeof(tCOLOR_CONV_YUV2RGB_ITU601_YUVFULL), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
                    break;

                case _COLORIMETRY_ITU709:
                    ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709_YUVFULL, sizeof(tCOLOR_CONV_YUV2RGB_ITU709_YUVFULL), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
                    break;

                case _COLORIMETRY_EXT:
                    if(GET_EXT_COLORIMETRY() == _COLORIMETRY_XVYCC601)
                    {
                        ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU601_YUVFULL, sizeof(tCOLOR_CONV_YUV2RGB_ITU601_YUVFULL), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
                    }
                    else
                    {
                        ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709_YUVFULL, sizeof(tCOLOR_CONV_YUV2RGB_ITU709_YUVFULL), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
                    }
                    break;

                default:
                    ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709_YUVFULL, sizeof(tCOLOR_CONV_YUV2RGB_ITU709_YUVFULL), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
                    break;
            }     
            
            // Set YCbCr Clamp
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT3 | _BIT2 | _BIT1), _BIT2);              
        }
        else
#endif // End of #if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)             
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
    }

    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);

    //////////////////////////////
    // I-Domain Color Conversion//
    //////////////////////////////
    if(enumColorFormat == _COLOR_SPACE_RGB)
    {

#if(_2D_TO_3D_FUNCTION == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if((GET_2DTO3D_ENABLE() == _ON) || (ScalerColorUltraVividGetStatus() == _ON) || (GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE))
        {
            if((GET_V_SCALE_DOWN() == _TRUE) && (GET_2DTO3D_ENABLE() == _OFF))
            {
                // Disable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
            }
            else
            {
                // Enable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);            
            }
        }
        else
        {
            // Disable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
        }
#else
        if((GET_2DTO3D_ENABLE() == _ON) || (ScalerColorUltraVividGetStatus() == _ON))
        {
            if((GET_V_SCALE_DOWN() == _TRUE) && (GET_2DTO3D_ENABLE() == _OFF))
            {
                // Disable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
            }
            else
            {
                // Enable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);            
            }
        }
        else
        {
            // Disable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
        }
#endif

#elif(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if((GET_2DTO3D_ENABLE() == _ON) || (GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE))
        {
            if((GET_V_SCALE_DOWN() == _TRUE) && (GET_2DTO3D_ENABLE() == _OFF))
            {
                // Disable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
            }
            else
            {
                // Enable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);            
            }
        }
        else
        {
            // Disable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
        }
#else
        if(GET_2DTO3D_ENABLE() == _ON)
        {
            // Enable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);            
        }
        else
        {
            // Disable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
        }
#endif

#elif(_ULTRA_VIVID_SUPPORT == _ON)

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if((ScalerColorUltraVividGetStatus() == _ON) || (GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE))
        {
            if(GET_V_SCALE_DOWN() == _TRUE)
            {
                // Disable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
            }
            else
            {
                // Enable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);            
            }
        }
        else
        {
            // Disable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
        }
#else
        if(ScalerColorUltraVividGetStatus() == _ON)
        {
            if(GET_V_SCALE_DOWN() == _TRUE)
            {
                // Disable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
            }
            else
            {
                // Enable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);            
            }
        }
        else
        {
            // Disable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
        }
#endif

#elif(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if(GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE)
        {
            if(GET_V_SCALE_DOWN() == _TRUE)
            {
                // Disable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
            }
            else
            {
                // Enable I-Domain RGB2YUV
                ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);            
            }
        }
        else
        {
            // Disable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
        }
#else
        // Disable I-Domain RGB2YUV
        ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
#endif

    }
    else
    {
        // Disable I-Domain RGB2YUV
        ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
    }
    
#if((_OD_SUPPORT == _ON) || (_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
    switch(GET_MEMORY_DVF_SELECT())
    {
        case _2_IVF:        

            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);

            break;

        case _2_5_IVF:    

            ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_28_FREE_RUN_DVS_CNT, 1, &pData[0], _NON_AUTOINC);

            if(pData[0] == 4)
            {
                ScalerTimerWaitForEvent(_EVENT_DVS);
            }

            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);

            break;        

        case _3_IVF:

            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);            

            break;  

        default:

            ScalerTimerWaitForEvent(_EVENT_DVS);

            break;
    }    

#else

    ScalerTimerWaitForEvent(_EVENT_DVS);

#endif // End of #if((_OD_SUPPORT == _ON) || (_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

    //////////////////////////////
    // D-Domain Color Conversion//
    //////////////////////////////
    if(enumColorFormat == _COLOR_SPACE_RGB)
    {
        // Disable Y_OUT Shift
        ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT7, 0x00);

#if(_2D_TO_3D_FUNCTION == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if((GET_2DTO3D_ENABLE() == _ON) || (ScalerColorUltraVividGetStatus() == _ON) || (GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE))
        {
            if((GET_V_SCALE_DOWN() == _TRUE) && (GET_2DTO3D_ENABLE() == _OFF))
            {
                // Enable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));    
            }
            else
            {
                // Disable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
            }

            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain RGB2YUV
            ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#else
        if((GET_2DTO3D_ENABLE() == _ON) || (ScalerColorUltraVividGetStatus() == _ON))
        {
            if((GET_V_SCALE_DOWN() == _TRUE) && (GET_2DTO3D_ENABLE() == _OFF))
            {
                // Enable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));    
            }
            else
            {
                // Disable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
            }

            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain RGB2YUV
            ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#endif

#elif(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if((GET_2DTO3D_ENABLE() == _ON) || (GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE))
        {
            if((GET_V_SCALE_DOWN() == _TRUE) && (GET_2DTO3D_ENABLE() == _OFF))
            {
                // Enable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));    
            }
            else
            {
                // Disable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
            }

            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain RGB2YUV
            ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#else
        if(GET_2DTO3D_ENABLE() == _ON)
        {
            // Disable D-Domain RGB2YUV
            ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    

            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain RGB2YUV
            ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#endif

#elif(_ULTRA_VIVID_SUPPORT == _ON)

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if((ScalerColorUltraVividGetStatus() == _ON) || (GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE))
        {
            if(GET_V_SCALE_DOWN() == _TRUE)
            {
                // Enable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));    
            }
            else
            {
                // Disable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
            }

            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain RGB2YUV
            ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#else
        if(ScalerColorUltraVividGetStatus() == _ON)
        {
            if(GET_V_SCALE_DOWN() == _TRUE)
            {
                // Enable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));    
            }
            else
            {
                // Disable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
            }

            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain RGB2YUV
            ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#endif

#elif(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if(GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE)
        {
            if(GET_V_SCALE_DOWN() == _TRUE)
            {
                // Enable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));    
            }
            else
            {
                // Disable D-Domain RGB2YUV
                ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
            }

            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain RGB2YUV
            ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#else
        // Disable D-Domain RGB2YUV
        ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

        // Disable D-Domain YUV2RGB
        ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
#endif

    }
    else
    {
        // Enable Y_OUT Shift
        ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT7, _BIT7);

        // Disable D-Domain RGB2YUV
        ScalerSetBit(P14_A0_SR_RGB2YCC_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

        // Enable D-Domain YUV2RGB
        ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
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
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PHASE_HIGHFREQ_THD << 4) | (_DIG_FILTER_PHASE_HIGHFREQ_DIV_VALUE << 2) | _BIT7));
    }
    else
    {
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PHASE_THD << 4) | (_DIG_FILTER_PHASE_DIV_VALUE << 2) | _BIT7));
    }
#else
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PHASE_THD << 4) | (_DIG_FILTER_PHASE_DIV_VALUE << 2) | _BIT7));
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
#endif // End of #if(_VGA_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get I-Domain Color Space Conversion/Ultravivid Status
// Input Value  : None
// Output Value : _ON / _OFF
//--------------------------------------------------
bit ScalerColorGetIColorConvertStatus(void)
{
    // Check if Color Conversion / IDLTI / IDCTI are all disabled
    if((ScalerGetBit(CM_9C_YUV2RGB_CTRL, _BIT0) == _OFF) && ((ScalerGetBit(P11_A1_I_DLTI_CTRL_0, _BIT0) == _OFF) && (ScalerGetBit(P11_B3_I_DCTI_CTRL, _BIT7) == _OFF)))
    {
        return _OFF;
    }
    else
    {
        return _ON;
    }
}

//--------------------------------------------------
// Description  : Enable IDither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherOn(BYTE *pDitherTable, BYTE ucBankNum)
{
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(pDitherTable, 24, ucBankNum, CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), 0x00);
}

//--------------------------------------------------
// Description  : Disable IDither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherOff(void)
{      
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tDITHER_TABLE_ZERO, 24, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), 0x00);
}
#endif // End of #if(_I_DITHER_SUPPORT == _ON) 

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

#if(_DITHER_MULTI_SEQ_ENABLE == _DISABLE)
        ScalerBurstWrite(pDitherSeqTable, 24, ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
#else
        ScalerBurstWrite(pDitherSeqTable, (24 * 4), ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
#endif

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

#if(_D_DITHER_THRESHOLD_EN == _ENABLE)
    // Set D-Dither Threshold table
    if(pThresholdTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_6B_DITHERING_CTRL2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7);
        ScalerBurstWrite(pThresholdTable, 6, ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
#else
    if(pThresholdTable != _NULL_POINTER)
    {

    }
#endif

    ScalerSetBit(CM_6B_DITHERING_CTRL2, ~(_BIT7 | _BIT2 | _BIT0), (_D_DITHER_THRESHOLD_EN << 2) | _BIT0);

#if((_DISP_BIT_MODE == _DISP_18_BIT) && ((_DITHER_MULTI_SEQ_ENABLE == _ENABLE) || (_DITHER_SHARE_SEQ_ENABLE == _ENABLE) || (_DITHER_SEQ_INV_ENABLE == _ENABLE)))
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT1, _BIT1);
#else
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT1, 0x00);
#endif 

    ScalerSetBit(CM_6B_DITHERING_CTRL2, ~(_BIT3 | _BIT1), (_DITHER_SHARE_SEQ_ENABLE << 3) | (_DITHER_MULTI_SEQ_ENABLE << 1)); 
    
    // Set Inverse dither
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~(_BIT7 | _BIT6), (_DITHER_SEQ_INV_ENABLE << 7) | (_DITHER_SEQ_INV_MODE << 6));
    
    ScalerColorDDitherAdjustPRShift(0x00, _DISABLE);   

    // Enable D-Dither Function and Temporal Dither
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ((_D_DITHER_TEMP << 4) | (_D_DITHER_VALUE_SIGN << 3) | (_D_DITHER_V_FRAME_MOD << 1) | ( _D_DITHER_H_FRAME_MOD)));
}

//--------------------------------------------------
// Description  : Adjust D dither 
// Input Value  : Dithering PR Shift
// Output Value : None
//--------------------------------------------------
void ScalerColorDDitherAdjustPRShift(BYTE ucShiftOffset, bit bPRShiftEn)
{    
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT4 | _BIT3), (ucShiftOffset & 0x03) << 3);
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT0, bPRShiftEn);
}

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
//--------------------------------------------------
// Description  : Adjust D dither PR offset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDDither3DSetPRShift(void)
{
    if((GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
    {
        // set 3D PR offset
        ScalerColorDDitherAdjustPRShift(_DITHER_PR_SHIFT_VALUE, _ENABLE);
    }
    else
    {
        ScalerColorDDitherAdjustPRShift(0x00, _DISABLE);
    }
}
#endif // End of #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))

#endif // End of #if(_D_DITHER_SUPPORT == _ON)

#if(_PCM_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Set PCM(Input Gamma, Output Gamma, Color Matrix)
// Input Value  : PCM Type --> sRGB / AdobeRGB
//                Input Gamma Table  & its bank number
//                Output Gamma Table & its bank number
//                Color Matrix       & its bank number
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMAdjust(EnumPCMType enumPCMMode, BYTE *pIGammaTableArray, BYTE *pOGammaTableArray, BYTE *pColorMatrixArray, BYTE ucBankNum)
{
    // Set InputGamma LUT
    if(enumPCMMode == _PCM_USER_MODE)
    {
        ScalerColorPCMInputGammaAdjust(pIGammaTableArray, ucBankNum);
    }
    
#if(_OCC_SUPPORT == _ON)
    else
    {
        ScalerColorPCMInputGammaLoadTable((bit)enumPCMMode);
    }
#endif

    // Load Gamma table
    ScalerColorPCMOutputGammaAdjust(pOGammaTableArray, ucBankNum);
    
    // Set color Matrix
    ScalerColorPCMSRGBAdjust(pColorMatrixArray, ucBankNum);
}

//--------------------------------------------------
// Description  : Enable/Disable Input gamma
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMInputGamma(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT6, _BIT6);
    }
    else
    {
        ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT6, 0x00);
    }    
}

#if(_OCC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable sRGB function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMInputGammaLoadTable(bit bPCMType)
{
    ScalerColorPCMInputGammaAdjust(tPCM_INPUTGAMMA[bPCMType], GET_CURRENT_BANK_NUMBER());
}
#endif  // End of #if(_OCC_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Adjust Input gamma
// Input Value  : Gamma Table Bank and gamma table
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMInputGammaAdjust(BYTE *pGammaTableArray, BYTE ucBankNum)
{
    // Enable Input Gamma Port Access
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT7, _BIT7);

    // Load Input Gamma Table
    ScalerBurstWrite(pGammaTableArray, 99, ucBankNum, P9_A0_INPUT_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Load Threshold
    ScalerBurstWrite(pGammaTableArray + 99, 1, ucBankNum, P9_A2_INPUT_GAMMA_LOW_THRE, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);        
    ScalerBurstWrite(pGammaTableArray + 100, 1, ucBankNum, P9_A3_INPUT_GAMMA_HIGH_THRE, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);        

    // Disable Input Gamma Port Access
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT7, 0x00);
}

//--------------------------------------------------
// Description  : Adjust output gamma for PCM
// Input Value  : Gamma table type and gamma tables
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMOutputGammaAdjust(BYTE *pGammaTableArray, BYTE ucBankNum)
{
    // Enable Gamma access
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, _BIT7); 

    // Load gamma table of R Channel
    ScalerColorOutputGammaChannelCtrl(_GAMMA_RED_CHANNEL, 0x00, _GAMMA_WRITE_TO_LATCH);
    ScalerBurstWrite(pGammaTableArray, 24, ucBankNum, CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerColorOutputGammaChannelCtrl(_GAMMA_RED_CHANNEL, 0x00, _GAMMA_WRITE_TO_SRAM);
    ScalerBurstWrite(pGammaTableArray + 24, 387, ucBankNum, CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Load gamma table of G Channel
    ScalerColorOutputGammaChannelCtrl(_GAMMA_GREEN_CHANNEL, 0x00, _GAMMA_WRITE_TO_LATCH);
    ScalerBurstWrite(pGammaTableArray + 411, 24, ucBankNum, CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);   

    ScalerColorOutputGammaChannelCtrl(_GAMMA_GREEN_CHANNEL, 0x00, _GAMMA_WRITE_TO_SRAM);
    ScalerBurstWrite(pGammaTableArray + 411 + 24, 387, ucBankNum, CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);   

    // Load gamma table of B Channel
    ScalerColorOutputGammaChannelCtrl(_GAMMA_BLUE_CHANNEL, 0x00, _GAMMA_WRITE_TO_LATCH);
    ScalerBurstWrite(pGammaTableArray + 411 * 2, 24, ucBankNum, CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);    

    ScalerColorOutputGammaChannelCtrl(_GAMMA_BLUE_CHANNEL, 0x00, _GAMMA_WRITE_TO_SRAM);
    ScalerBurstWrite(pGammaTableArray + 411 * 2 + 24, 387, ucBankNum, CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);    

    // Disable Port Access
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, 0x00);
}

//--------------------------------------------------
// Description  : Write Color Matrix
// Input Value  : bIsAdobe: 1 = AdobeRGB, 0- sRGB
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMSRGBAdjust(BYTE *pColorMatrixArray, BYTE ucBankNum)
{    
    // Disable Access Port
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x00);

    // Set Contrast/Brightness before sRGB
    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT6, _BIT6);

    pData[0] = 0;
    pData[1] = 0;

    // R Offset 
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);

    // G Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT3));
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);

    // B Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);

    // RR, RG, RB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT3); 
    ScalerBurstWrite(pColorMatrixArray, 6, ucBankNum, CM_63_SRGB_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // GR, GG, GB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
    ScalerBurstWrite(pColorMatrixArray + 6, 6, ucBankNum, CM_63_SRGB_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // BR, BG, BB 
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3)); 
    ScalerBurstWrite(pColorMatrixArray + 12, 6, ucBankNum, CM_63_SRGB_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);  

    // Precision: 0 shift left / Normal, Disable Access Port and Apply Matrix
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT7);
}
#endif // End of #if(_PCM_FUNCTION == _ON)

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

#if(_DCR_SUPPORT == _ON)
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

#if(_DCC_HISTOGRM_INFO == _ON)
//--------------------------------------------------
// Description  : Get DCC S0~S6 Histogram infomation
// Input Value  : Pointer to get Ymax/Ymin/S0~S6
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

    for(ucI = 0; ucI < 9; ucI++)
    {
        pucReadArray[ucI] = ScalerGetByte(P7_CA_DCC_DATA_PORT);
    }
}
#endif // End of #if(_DCC_HISTOGRM_INFO == _ON)

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
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _P7_D3_PT_03_UV_OFFSET);
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

    // Disable Negative Compensate
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~(_BIT7), 0x00);

    // Enable ICM New Mode and UV Offset on Right/Left Buffer
    ScalerSetBit(P7_D4_ICM_NEW_MODE, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
}
#endif // End of #if(_ICM_SUPPORT == _ON)

#if(_SIX_COLOR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : 6 Color ICM adjust
// Input Value  : ucColorIndex --> Color Adjusted Now 
//                ucHuePosition --> Hue position after mapping 
//                ucSatPosition --> Sat position after mapping
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorAdjust(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition) 
{
    BYTE pucCentDeltaUV[16];
    BYTE ucLastIndex = 0;
    BYTE ucAxis = 0;
    BYTE ucPointIndex = 0;
    SWORD shDeltaSat = 0;
    SWORD shDeltaUmax1 = 0;
    SWORD shDeltaVmax1 = 0;
    SWORD shDeltaUmax = 0;
    SWORD shDeltaVmax = 0;
    SWORD shDeltaU = 0;
    SWORD shDeltaV = 0;
    BYTE ucTurningPositiongUp = 0;
    BYTE ucTurningPositiongDown = 0;
       
    ucLastIndex = (ucColorIndex == 0)? 5 : (ucColorIndex - 1);
    ucTurningPositiongUp = tL_TURNING_POSITION_UP[ucColorIndex];
    ucTurningPositiongDown = tR_TURNING_POSITION_DOWN[ucColorIndex];

    // Delta Saturation = (-512 * 200 + ((512 - (-512)) * ucSatPosition)) / 200
    shDeltaSat = ((SDWORD)-102400 + ((SDWORD)ucSatPosition << 10)) / 200;

    for(ucAxis = 1; ucAxis < 4; ucAxis++)
    {
        //Calculate Delta Hue of one Axis

        if(ucAxis == _SIX_COLOR_RIGHTWIDTH) 
        {
            if((ucHuePosition > 50) && (ucHuePosition <= ucTurningPositiongDown))
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][0] * (ucHuePosition - 50) / (ucTurningPositiongDown - 50);
                shDeltaVmax = (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][1] * (ucHuePosition - 50) / (ucTurningPositiongDown - 50);
            }
            else if(ucHuePosition > ucTurningPositiongDown)
            {
                shDeltaUmax = tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][0] + (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][2] * (ucHuePosition - ucTurningPositiongDown) / (100 - ucTurningPositiongDown);
                shDeltaVmax = tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][1] + (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][3] * (ucHuePosition - ucTurningPositiongDown) / (100 - ucTurningPositiongDown);
            }
            else if(ucHuePosition < 50)
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_UP[ucColorIndex][0] * (50 - ucHuePosition) / 50;
                shDeltaVmax = (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_UP[ucColorIndex][1] * (50 - ucHuePosition) / 50;                    
            }
            else
            {
                shDeltaUmax = 0;
                shDeltaVmax = 0;    
            }
        }
        else if(ucAxis == _SIX_COLOR_CENTER)
        {
            if(ucHuePosition > 50)
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_CTOC_DELTA_UV_DOWN[ucColorIndex][0] * (ucHuePosition - 50) / 50;
                shDeltaVmax = (SDWORD)tSIX_COLOR_CTOC_DELTA_UV_DOWN[ucColorIndex][1] * (ucHuePosition - 50) / 50;
            }
            else if(ucHuePosition < 50)
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_CTOC_DELTA_UV_UP[ucColorIndex][0] * (50 - ucHuePosition) / 50;
                shDeltaVmax = (SDWORD)tSIX_COLOR_CTOC_DELTA_UV_UP[ucColorIndex][1] * (50 - ucHuePosition) / 50;                    
            }
            else
            {
                shDeltaUmax = 0;
                shDeltaVmax = 0;    
            }
        }
        else
        {
            if(ucHuePosition > 50)
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_DOWN[ucColorIndex][0] * (ucHuePosition - 50) / 50;
                shDeltaVmax = (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_DOWN[ucColorIndex][1] * (ucHuePosition - 50) / 50;
            }
            else if((ucHuePosition< 50) && (ucHuePosition >= ucTurningPositiongUp))
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][0] * (50 - ucHuePosition) / (50 - ucTurningPositiongUp);
                shDeltaVmax = (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][1] * (50 - ucHuePosition) / (50 - ucTurningPositiongUp);                    
            }
            else if(ucHuePosition < ucTurningPositiongUp)
            {
                shDeltaUmax = tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][0] + (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][2] * (ucTurningPositiongUp - ucHuePosition) / ucTurningPositiongUp;
                shDeltaVmax = tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][1] + (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][3] * (ucTurningPositiongUp - ucHuePosition) / ucTurningPositiongUp;
            }
            else
            {
                shDeltaUmax = 0;
                shDeltaVmax = 0;    
            }                
        }

        shDeltaUmax1 = tSIX_COLOR_U_MAX_8[ucColorIndex][ucAxis - 1] + shDeltaUmax;
        shDeltaVmax1 = tSIX_COLOR_V_MAX_8[ucColorIndex][ucAxis - 1] + shDeltaVmax; 
        
        shDeltaUmax1 = (SDWORD)shDeltaSat * shDeltaUmax1 >> 9;
        shDeltaVmax1 = (SDWORD)shDeltaSat * shDeltaVmax1 >> 9; 
        
        shDeltaUmax = (shDeltaUmax1 + shDeltaUmax) >> 3;
        shDeltaVmax = (shDeltaVmax1 + shDeltaVmax) >> 3;            

        for(ucPointIndex = 0; ucPointIndex < 8; ucPointIndex++)
        {
            shDeltaU = (shDeltaUmax * (ucPointIndex + 1)) >> 3;
            shDeltaV = (shDeltaVmax * (ucPointIndex + 1)) >> 3;

            shDeltaU = MAXOF(-128, MINOF(127, shDeltaU));
            shDeltaV = MAXOF(-128, MINOF(127, shDeltaV));

            pucCentDeltaUV[ucPointIndex << 1] = shDeltaU & 0xFF;
            pucCentDeltaUV[(ucPointIndex << 1) + 1] = shDeltaV & 0xFF; 
        }

        ScalerColorSixColorICMLoad(pucCentDeltaUV, ucColorIndex, ucAxis);
        
        if(ucAxis == _SIX_COLOR_RIGHTWIDTH)
        {
            ScalerColorSixColorICMLoad(pucCentDeltaUV, ucColorIndex, _SIX_COLOR_RIGHTBUFFER);
            ScalerColorSixColorICMLoad(pucCentDeltaUV, ucLastIndex, _SIX_COLOR_LEFTBUFFER);
        }
    }
}

//--------------------------------------------------
// Description   : Fill 6 Color ICM Data
// Input Value   : pucICMData --> Point to ICM uvoffset  
//                 ucCMSel --> Color selected
//                   ucLoadSelect --> Axis selected
// Output Value  : None
//--------------------------------------------------
void ScalerColorSixColorICMLoad(BYTE *pucICMData, BYTE ucCMSel, BYTE ucLoadSelect)    
{
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), ucCMSel);

    switch(ucLoadSelect)
    {
        // Rightbuffer
        case 0:      
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x33);
            break;    

        // Rightwidth    
        case 1:      
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x13);
            break;    

        // Center    
        case 2:      
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
            break;    

        // Leftwidth        
        case 3:      
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x23);
            break;    

        // Leftbuffer    
        case 4:      
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x43);
            break;    
            
        default:
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x33);
            break;        
    }

    ScalerBurstWrite(pucICMData, 16, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_XRAM);  
}

//--------------------------------------------------
// Description  : Set range for one CM 
// Input Value  : ucCMSel --> Color selected
//                shRBuffer --> Right buffer hue
//                shRWidth --> Right range
//                shAngle --> Master Range
//                shLWidth --> Left Range
//                shLBuffer --> Left Buffer Range
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorSetAngleRB(BYTE ucCMSel)
{
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), ucCMSel);
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x53);

    //Master Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_CENTER]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_CENTER]) & 0xFF));
    
    //Rightwidth Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_RIGHTWIDTH]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_RIGHTWIDTH]) & 0xFF));
    
    //Leftwidth Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_LEFTWIDTH]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_LEFTWIDTH]) & 0xFF));
    
    //Rightbuffer Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_RIGHTBUFFER]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_RIGHTBUFFER]) & 0xFF));
    
    //Leftbuffer Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_LEFTBUFFER]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_LEFTBUFFER]) & 0xFF));

    //Right Buffer Hue
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_RIGHTBUFFER] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_RIGHTBUFFER] & 0xFF);
    
    //Right Width Range
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_RIGHTWIDTH] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_RIGHTWIDTH] & 0xFF);
    
    //Master Range
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_CENTER] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_CENTER] & 0xFF);
    
    //Left Width Range
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_LEFTWIDTH] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_LEFTWIDTH] & 0xFF);
    
    //Left Buffer Range
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_LEFTBUFFER] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_LEFTBUFFER] & 0xFF);
}

//--------------------------------------------------
// Description  : Enable ICM function 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorEnable(void)
{
    BYTE ucCmIndex = 0;

    //Enable x4、CM5
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT4 | _BIT3), _BIT4 | _BIT3);
    
    //Enable New ICM mode、buf_uvoffset
    ScalerSetBit(P7_D4_ICM_NEW_MODE, ~(_BIT2 | _BIT1), _BIT2 | _BIT1);
    
    //Enable ICM function、CM0~CM4、x2
    ScalerSetByte(P7_D0_ICM_CTRL, 0xBF);

    for(ucCmIndex = 0; ucCmIndex < 6; ucCmIndex++)
    {
        ScalerColorSixColorSetAngleRB(ucCmIndex);
    }
}
#endif //#if(_SIX_COLOR_SUPPORT == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Disable UltraVivid
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorUltraVividOff(void)
{
    // Disable IDLTI
    ScalerSetBit(P11_A1_I_DLTI_CTRL_0, ~_BIT0, 0x00);

    // Disable IDCTI
    ScalerSetBit(P11_B3_I_DCTI_CTRL, ~_BIT7, 0x00);

    // Disable VPK     
    ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~_BIT5, 0x00);

    // Disable VCTI
    ScalerSetBit(P11_C1_SR_VCTI_CTRL, ~_BIT1, 0x00);

    // Disable DDLTI
    ScalerSetBit(P11_F0_D_DLTI_OPTIONS, ~_BIT5, 0x00);

    // Disable DDCTI
    ScalerSetBit(P11_F4_D_DCTI_CTRL, ~_BIT1, 0x00);

    // Disable SHP
    ScalerSetBit(P12_A0_SR_SHP_CTRL, ~_BIT6, 0x00);

    ScalerTimerWaitForEvent(_EVENT_IVS);

    ScalerTimerWaitForEvent(_EVENT_DVS);
}

//--------------------------------------------------
// Description  : Get UltraVivid Status
// Input Value  : None
// Output Value : ON/OFF
//--------------------------------------------------
bit ScalerColorUltraVividGetStatus(void)
{
    if((ScalerGetBit(P11_A1_I_DLTI_CTRL_0, _BIT0) == 0x00) &&
       (ScalerGetBit(P11_B3_I_DCTI_CTRL, _BIT7) == 0x00) &&
       (ScalerGetBit(P11_B9_SCALER_PEAKING_C0, _BIT5) == 0x00) &&
       (ScalerGetBit(P11_C1_SR_VCTI_CTRL, _BIT1) == 0x00) &&
       (ScalerGetBit(P11_F0_D_DLTI_OPTIONS, _BIT5) == 0x00) &&
       (ScalerGetBit(P11_F4_D_DCTI_CTRL, _BIT1) == 0x00) &&
       (ScalerGetBit(P12_A0_SR_SHP_CTRL, _BIT6) == 0x00))
    {
        return _OFF;
    }
    else
    {
        return _ON;
    }
}

//--------------------------------------------------
// Description  : UltraVivid Adjust
// Input Value  : UltraVivid type/Color Space
// Output Value : None
//--------------------------------------------------
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)) 
void ScalerColorUltraVividAdjust(BYTE *pUltraVividSetting1, BYTE *pUltraVividSetting2, BYTE *pUltraVividSetting3, BYTE *pUltraVividSetting4, BYTE *pUltraVividCDSSetting, BYTE *pUltraVividHSRSetting, BYTE ucBankNum)
#else
void ScalerColorUltraVividAdjust(BYTE *pUltraVividSetting1, BYTE *pUltraVividSetting2, BYTE *pUltraVividSetting3, BYTE *pUltraVividSetting4, BYTE *pUltraVividCDSSetting, BYTE ucBankNum)                                    
#endif

{
    // Disable IDLTI
    ScalerSetBit(P11_A1_I_DLTI_CTRL_0, ~_BIT0, 0x00);

    // Disable IDCTI
    ScalerSetBit(P11_B3_I_DCTI_CTRL, ~_BIT7, 0x00);

    // Disable VPK     
    ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~_BIT5, 0x00);

    // Disable VCTI
    ScalerSetBit(P11_C1_SR_VCTI_CTRL, ~_BIT1, 0x00);

    // Disable DDLTI
    ScalerSetBit(P11_F0_D_DLTI_OPTIONS, ~_BIT5, 0x00);

    // Disable DDCTI
    ScalerSetBit(P11_F4_D_DCTI_CTRL, ~_BIT1, 0x00);

    // Disable SHP
    ScalerSetBit(P12_A0_SR_SHP_CTRL, ~_BIT6, 0x00);

    // Record the HLW setting
    pData[3] = ScalerGetBit(P11_B9_SCALER_PEAKING_C0, (_BIT7 | _BIT6));

    if(GET_V_SCALE_UP() == _TRUE)
    {
        ScalerGetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_03_SU_VER_SCA_H, 2, pData, _AUTOINC);
        pData[0] = ((pData[0] << 4) | (pData[1] >> 4));

        if(pData[0] < 170)  // IVHeight/DVHeight < 2/3
        {
            ScalerBurstWrite(pUltraVividSetting1, 42, ucBankNum, P11_B9_SCALER_PEAKING_C0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }
        else    // IVHeight/DVHeight <= 1
        {
            ScalerBurstWrite(pUltraVividSetting2, 42, ucBankNum, P11_B9_SCALER_PEAKING_C0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }

        if(GET_V_SCALE_DOWN() == _TRUE)
        {
            //Disable V-Peaking
            ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~_BIT5, 0x00);
        }              
    }
    else if(GET_V_SCALE_DOWN() == _TRUE)
    {
        ScalerBurstWrite(pUltraVividSetting3, 42, ucBankNum, P11_B9_SCALER_PEAKING_C0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

        //Disable V-Peaking
        ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~_BIT5, 0x00);
    }
    else // by pass
    {
        ScalerBurstWrite(pUltraVividSetting4, 128, ucBankNum, P11_B9_SCALER_PEAKING_C0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    }
    
    ScalerBurstWrite(pUltraVividCDSSetting, 29, ucBankNum, P13_A0_SR_CDS_CTRL, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    // 3D input (except 3Dto2D)   and 2Dto3D can't use V SR 
    if(((GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) || (_2D_TO_3D_FUNCTION == _ON))
    {
        ScalerBurstWrite(pUltraVividHSRSetting, 27, ucBankNum, P12_A0_SR_SHP_CTRL, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    
        // Disable V-Peaking
        ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~_BIT5, 0x00);

        // Disable Vertical Sharpness            
        ScalerSetBit(P12_B6_SR_PEAKING_EMF_RANGE, ~_BIT5, 0x00);  
    }    
#endif

    ScalerTimerWaitForEvent(_EVENT_IVS);

    ScalerTimerWaitForEvent(_EVENT_DVS);

    // Recover HLW setting
    ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), (pData[3] & (_BIT7 | _BIT6))); 
}
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

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

#if(_ULTRA_VIVID_SUPPORT == _ON)         
        //IDLCTI
        ScalerSetBit(P11_DC_IDCLTI_HLW_CTRL, ~_BIT1, _BIT1);

        //VPKVCTI
        ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~_BIT7, _BIT7);   
#endif

    }
    else
    {
        ScalerSetBit(CM_60_HW_ACCESS_PORT, ~_BIT6, 0x00);

#if(_ULTRA_VIVID_SUPPORT == _ON)         
        //IDLCTI
        ScalerSetBit(P11_DC_IDCLTI_HLW_CTRL, ~_BIT1, 0x00);

        //VPKVCTI
        ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~_BIT7, 0x00);
#endif        

    }
}

//--------------------------------------------------
// Description  : Adjust highlight window region
// Input Value  : usHPos, usHWidth, usVPos, usVHeight
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight)
{
    
#if(_ULTRA_VIVID_SUPPORT == _ON)
    BYTE pucTemp[8];
    DWORD ulScale = 0;
#endif            

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

#if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_ASPECT_RATIO_SUPPORT == _ON)
    if(g_stMDomainOutputData.usHWidth != _PANEL_DH_WIDTH)
    {
        ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_03_DISP_DH_BKGD_STA_H, 2, &pucTemp[0], _AUTOINC);
        usHPos = usHPos - (g_stMDomainOutputData.usHStart - (pucTemp[0] << 8 | pucTemp[1]));
    }
#endif
        
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    if(g_stMDomainOutputData.usVHeight!= _PANEL_DV_HEIGHT)
    {
        ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0E_DISP_DV_BKGD_STA_H, 2, &pucTemp[0], _AUTOINC);
        usVPos = usVPos - (g_stMDomainOutputData.usVStart - (pucTemp[0] << 8 | pucTemp[1]));
    }
#endif

    // Horizontal refers to timing of M domain
    if(GET_H_SCALE_UP() == _TRUE)
    {
        ScalerGetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, 3, &pucTemp[5], _AUTOINC);

        ulScale = (((DWORD)(pucTemp[5] & 0x0F) << 16) | ((DWORD)pucTemp[6] << 8) | (pucTemp[7])); 

        usHPos = (ulScale * usHPos) >> 20;
        usHWidth = (ulScale * usHWidth) >> 20;    
    }

    // (VPK VCTI) H refers to M domain V refers to D domain
    pData[8] = (BYTE)((usHPos >> 8) & 0x0F);
    pData[9] = (BYTE)(usHPos & 0xFF);
    pData[10] = (BYTE)(((usHPos + usHWidth) >> 8) & 0x0F);
    pData[11] = (BYTE)((usHPos + usHWidth) & 0xFF);
    pData[12] = (BYTE)((usVPos >> 8) & 0x0F);
    pData[13] = (BYTE)(usVPos & 0xFF);
    pData[14] = (BYTE)(((usVPos + usVHeight) >> 8) & 0x0F);
    pData[15] = (BYTE)((usVPos + usVHeight) & 0xFF);
    
    // (IDLCTI) H refers to I domain V refers to I domain
    if(GET_V_SCALE_UP() == _TRUE)
    {
        ScalerGetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_03_SU_VER_SCA_H, 3, &pucTemp[5], _AUTOINC);

        ulScale = (((DWORD)(pucTemp[5] & 0x0F) << 16) | ((DWORD)pucTemp[6] << 8) | (pucTemp[7])); 

        usVPos = (ulScale * usVPos) >> 20;
        usVHeight = (ulScale * usVHeight) >> 20;        
    }

    if(GET_V_SCALE_DOWN() == _TRUE)
    {
        ScalerGetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 3, &pucTemp[5], _AUTOINC);

        ulScale = (((DWORD)(pucTemp[5] & 0x07) << 16) | ((DWORD)pucTemp[6] << 8) | (pucTemp[7])); 

        usVPos = (ulScale * usVPos) >> 17;
        usVHeight = (ulScale * usVHeight) >> 17;    
    }
    if(GET_H_SCALE_DOWN() == _TRUE)
    {
        ScalerGetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 3, &pucTemp[5], _AUTOINC);
 
        ulScale = (((DWORD)(pucTemp[5] & 0xFF) << 16) | ((DWORD)pucTemp[6] << 8) | (pucTemp[7])); 
        
        usHPos = (ulScale * usHPos) >> 17;
        usHWidth = (ulScale * usHWidth) >> 17;
    }

    pucTemp[0] = (BYTE)((usHPos >> 8) & 0x0F);
    pucTemp[1] = (BYTE)(usHPos & 0xFF);
    pucTemp[2] = (BYTE)(((usHPos + usHWidth) >> 8) & 0x0F);
    pucTemp[3] = (BYTE)((usHPos + usHWidth) & 0xFF);
    pucTemp[4] = (BYTE)((usVPos >> 8) & 0x0F);
    pucTemp[5] = (BYTE)(usVPos & 0xFF);
    pucTemp[6] = (BYTE)(((usVPos + usVHeight) >> 8) & 0x0F);
    pucTemp[7] = (BYTE)((usVPos + usVHeight) & 0xFF);
    
#endif

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    ScalerWrite(CM_61_HW_DATA_PORT, 8, pData, _NON_AUTOINC);

    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), 0x00);
    
#if(_ULTRA_VIVID_SUPPORT == _ON)
    ScalerWrite(P11_D4_IDCLTI_HLW_HOR_START_H, 8, pucTemp, _AUTOINC);
    ScalerWrite(P11_CC_VPK_VCTI_HLW_H_START_HIGH, 8, &pData[8], _AUTOINC);
#endif
   
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

#if(_ULTRA_VIVID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set ultravivid Highlight Window
// Input Value  : Highlight Window Active Region
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWUltraVividAdjust(EnumHLWType enumHLWActive)
{
    switch(enumHLWActive)
    {
        case _FULL_WINDOW:
            ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetBit(P11_DC_IDCLTI_HLW_CTRL, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT3 | _BIT2), ((enumHLWActive & 0x03) << 2));
            ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT1 | _BIT0), (enumHLWActive & 0x03));
            break;

        case _INSIDE_WINDOW:
            ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), _BIT7);
            ScalerSetBit(P11_DC_IDCLTI_HLW_CTRL, ~(_BIT1 | _BIT0), _BIT1);
            ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT3 | _BIT2), ((enumHLWActive & 0x03) << 2));
            ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT1 | _BIT0), (enumHLWActive & 0x03));
            break;

        case _OUTSIDE_WINDOW:
            ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);
            ScalerSetBit(P11_DC_IDCLTI_HLW_CTRL, ~(_BIT1 | _BIT0), _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT3 | _BIT2), ((enumHLWActive & 0x03) << 2));
            ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT1 | _BIT0), (enumHLWActive & 0x03));
            break;

        default:
            break;
    }   
}
#endif // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#endif  // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

#if(_3D_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Adjust Two to Three Dimension Function
// Input Value  : None
// Output Value : None
//-------------------------------------------------- 
void ScalerColorAdjust2DTo3DAnd3DEffect(void)
{ 
    // Disable and reset depth mode
    g_ucP1CA5 = 0x00;
    
    if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
    {
        // 2D to 3D block initial
        ScalerColor2Dto3DInitial();  
    }

    // 3D to 2D Case No Needing to Set 2D to 3D Effect
    if(((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT)) || (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
    {
#if(_2D_TO_3D_FUNCTION == _ON)

        // first 2D switch to 2Dto3D
        if(((GET_2DTO3D_ENABLE() == _ENABLE) && (ScalerGetBit(P1C_A5_2D_TO_3D_CTL6, _BIT4) == 0x00)) || 
            ((GET_2DTO3D_ENABLE() == _DISABLE) && (ScalerGetBit(P1C_A5_2D_TO_3D_CTL6, _BIT4) == _BIT4)))
        {
            SET_2DTO3D_FIRST();
        }
        else
        {
            CLR_2DTO3D_FIRST();
        }

        if((GET_2DTO3D_ENABLE() == _ENABLE) || (GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT))
        {    
            if(GET_2DTO3D_ENABLE()== _ENABLE) 
            {
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

#if(_PANEL_PR_DIS_TYPE == _PANEL_PR_LR_DISPLAY)
                // at even line or L frame
                g_ucP1CA5 |= _BIT5;
#else   
                // at odd line or L frame
                g_ucP1CA5 &= ~_BIT5;
#endif

#else
                // at even line or L frame
                g_ucP1CA5 |= _BIT5;

#endif
            }

            // 2D, depth mode
            if(GET_2DTO3D_DEPTH() == _ENABLE) 
            {
                ScalerColorTwoThreeDimensionAdjust(_CHROMINANCE_1_4, _LPF_BLUR_MEDIUM, _FRACTION_INTERPOLATE);
                
                // Enable depth mode
                g_ucP1CA5 |= _BIT4;
            }
            else
            {
                // Disable depth mode
                g_ucP1CA5 &= ~_BIT4;            
            }

            if(GET_3D_SHIFT_MODE_EFFECT() != 0x00)
            {
                ScalerColorDepthOfFieldAdjust();
                
                // Enable shift mode
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, _BIT6);            
            }
            else
            {
                // Disable shift mode
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, 0x00);
            }
        }
        else
        {
            // Disable depth mode
            g_ucP1CA5 &= ~_BIT4;

            // Disable shift mode
            ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, 0x00); 
        }

        if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
        {
            ScalerSetByte(P1C_A5_2D_TO_3D_CTL6, g_ucP1CA5);        

#if(_2D_TO_3D_FUNCTION == _ON)    
            if((((GET_2DTO3D_ENABLE() == _ENABLE) && ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) || (ScalerGetBit(P1C_A1_2D_TO_3D_CTL2, _BIT5) == 0x00))) || 
                (GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT)) &&
                (((GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_3) || (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_4) || 
               (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_5)) && (GET_3D_SHIFT_MODE_EFFECT() != 0x00)))
#else            
            if(((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT)) &&
                (((GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_3) || (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_4) || 
               (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_5)) && (GET_3D_SHIFT_MODE_EFFECT() != 0x00)))
#endif        
            {
                // Double buffer ready and enable New Shift Mode
                ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~(_BIT7 | _BIT1), (_BIT7 | _BIT1)); 
            }
            else
            {
                // Double buffer ready 
                ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT7, _BIT7); 
            }
        } 
        else
        {
#if(_2D_TO_3D_FUNCTION == _ON)    
            if((((GET_2DTO3D_ENABLE() == _ENABLE) && ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) || (ScalerGetBit(P1C_A1_2D_TO_3D_CTL2, _BIT5) == 0x00))) || 
                (GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT)) &&
                (((GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_3) || (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_4) || 
               (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_5)) && (GET_3D_SHIFT_MODE_EFFECT() != 0x00)))
#else            
            if(((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT)) &&
                (((GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_3) || (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_4) || 
               (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_5)) && (GET_3D_SHIFT_MODE_EFFECT() != 0x00)))
#endif         
            {
                // Enable New Shift Mode
                ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT1, _BIT1); 
            }
            else
            {
                // Disable New Shift Mode
                ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT1, 0x00);
            }
        }
        
#else // Else of #if(_2D_TO_3D_FUNCTION == _ON)

        // Disable depth mode
        g_ucP1CA5 &= ~_BIT4;    
        
        if(GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT)
        {    
            if(GET_3D_SHIFT_MODE_EFFECT() != 0x00)
            {
                ScalerColorDepthOfFieldAdjust();
                
                // Enable shift mode
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, _BIT6);            
            }
            else
            {
                // Disable shift mode
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, 0x00);
            }
        }
        else
        {
            // Disable shift mode
            ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, 0x00); 
        }

        if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
        {
            ScalerSetByte(P1C_A5_2D_TO_3D_CTL6, g_ucP1CA5);        
            
            // Double buffer ready 
            ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT7, _BIT7); 
        }    
#endif // End of #if(_2D_TO_3D_FUNCTION == _ON)
    }
}

//--------------------------------------------------
// Description  : Set 2Dto3D Input
// Input Value  : None
// Output Value : None
//-------------------------------------------------- 
void ScalerColor2Dto3DInitial(void)
{
    // Disable 2Dto3D double buffer
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT0, _BIT0);
    
    // Disable shift mode
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT6, 0x00);

    // Reset shift step
    ScalerSetByte(P1C_A0_2D_TO_3D_CTL1, 0x00);

    // Reset shift direction
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);   
    
    // Set 2Dto3D input format
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~(_BIT4 | _BIT3 | _BIT2), 0x00);

    // Disable new shift mode
    ScalerSetBit(P1C_B0_2D_TO_3D_CTL17, ~_BIT1, 0x00);

    // Disable new mode
    ScalerSetBit(CM_16_IPH_ACT_WID_H, ~_BIT1, 0x00);
    
    switch(GET_3D_INPUT_FORMAT())
    {
        case _FRAME_PACKING:
        case _TOP_AND_BOTTOM:

            ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT4, _BIT4);

            break;

        case _LINE_INTERLACE:

            ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT3, _BIT3);

            break;

        case _SIDE_BY_SIDE_HALF:

            ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT2, _BIT2);

            break;

        default:

            break;
    } 

#if(_2D_TO_3D_FUNCTION == _ON)

    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT3, ((GET_2DTO3D_ENABLE() == _ENABLE) ? _BIT3 : 0x00));  

#endif

// Set 2Dto3D output format
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER) // Output format is line-interleave for PR panel
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT5, _BIT5);
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES) // Output format is frame-sequential for shutter glass
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT5, 0x00);    
#endif    

    // Enable 2Dto3D double buffer
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT0, 0x00);    
}

//--------------------------------------------------
// Description  : Adjust Depth Of Field Function
// Input Value  : I-Domain Horizontal Width and Vertical Height
// Output Value : I-Domain Horizontal Width
//--------------------------------------------------
void ScalerColorDepthOfFieldAdjust(void)
{
    // Enable double buffer
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT0, 0x00);

    // Wait for IVS to ensure depth mode enable or not
    ScalerTimerWaitForEvent(_EVENT_IVS);

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
    if((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) || (GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || 
        (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) || (GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL))
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
    if((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) || (GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL))
#endif        
    {    
        // Clear input LR signal toggle flag
        ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT1, _BIT1);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        
        // No LR signal
        if(ScalerGetBit(P1C_A1_2D_TO_3D_CTL2, _BIT1) == 0x00)
        {
            // L/R flag reference to self generation
            g_ucP1CA5 |= _BIT3;
        }
        else // LR signal occurs
        {
            // L/R flag reference to original
            g_ucP1CA5 &= ~_BIT3;
        }
    }       
    
    if(GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF)
    {
        ScalerSetByte(P1C_AE_2D_TO_3D_CTL15, HIBYTE(g_stMDomainInputData.usHWidth >> 1));
        ScalerSetByte(P1C_AF_2D_TO_3D_CTL16, LOBYTE(g_stMDomainInputData.usHWidth >> 1));
    }
    
    // Set offset and initial phase (Strength)
    PDATA_WORD(0) = 0x0000;
    PDATA_WORD(1) = 0x0000;

    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) || 
        (GET_3D_INPUT_FORMAT() == _FRAME_PACKING))
    {       
        PDATA_WORD(0) = ((((DWORD)g_stMDomainInputData.usHWidth) * GET_3D_SHIFT_MODE_EFFECT()) + 960) / 1920;
         
        // Calculate capture width 
        if(GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) 
        {
            PDATA_WORD(0) -= PDATA_WORD(0) % 2;
            
            g_stMDomainInputData.usHWidth = g_stMDomainInputData.usHWidth - (PDATA_WORD(0) << 1); 
            
            g_stMDomainInputData.usHWidth -= g_stMDomainInputData.usHWidth % 2;
        }
        else
        {
            g_stMDomainInputData.usHWidth = g_stMDomainInputData.usHWidth - PDATA_WORD(0);
        }
    }  
#if(_2D_TO_3D_FUNCTION == _ON)    
    else if(((GET_2DTO3D_ENABLE() == _ENABLE) && ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) || (ScalerGetBit(P1C_A1_2D_TO_3D_CTL2, _BIT5) == 0x00))) || 
            (GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT))
#else            
    else if((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT))             
#endif
    {
        if((GET_3D_SELECT_CONVERGENCE_MODE() == _LINEAR_MODE) || (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_1) || 
           (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_2))
        { 
            ////////// Horizontal shift start //////////
            // Shift step
            ScalerSetByte(P1C_A0_2D_TO_3D_CTL1, 0x00);

            PDATA_WORD(0) = ((((DWORD)g_stMDomainInputData.usHWidth) * GET_3D_SHIFT_MODE_EFFECT()) + 960) / 1920;

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

#if(_PANEL_PR_DIS_TYPE == _PANEL_PR_LR_DISPLAY)

            if(((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_LR) && (GET_3D_SELECT_CONVERGENCE() == _3D_OUT)) ||
               ((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_RL) && (GET_3D_SELECT_CONVERGENCE() == _3D_IN)))
            {
                PDATA_WORD(1) = PDATA_WORD(0); 
                PDATA_WORD(0) = 0x0000;
            } 
#else
            if(((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_RL) && (GET_3D_SELECT_CONVERGENCE() == _3D_IN)) ||
               ((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_LR) && (GET_3D_SELECT_CONVERGENCE() == _3D_OUT)))
            {
                PDATA_WORD(1) = PDATA_WORD(0); 
                PDATA_WORD(0) = 0x0000;
            } 
#endif

#else

            if(GET_3D_SELECT_CONVERGENCE() == _3D_OUT)
            {
                PDATA_WORD(1) = PDATA_WORD(0); 
                PDATA_WORD(0) = 0x0000;
            } 

#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

        }
        else if((GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_3) || (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_4) || 
                (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_5))
        {
            ////////// Slanting shift start //////////
            // Shift step
            pData[4] = ((((DWORD)g_stMDomainInputData.usHWidth) * GET_3D_SHIFT_MODE_EFFECT()) + 960) / 1920;
            ScalerSetByte(P1C_A0_2D_TO_3D_CTL1, pData[4]);
            DebugMessageScaler("Shift Step", pData[4]);

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

#if(_PANEL_PR_DIS_TYPE == _PANEL_PR_LR_DISPLAY)

            // Shift direction
            if(((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_LR) && (GET_3D_SELECT_CONVERGENCE() == _3D_IN)) ||
               ((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_RL) && (GET_3D_SELECT_CONVERGENCE() == _3D_OUT)))
            {
                if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
                {
                    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);
                }

                PDATA_WORD(0) = ((((DWORD)(g_stMDomainInputData.usVHeight >> 1)) * pData[4]) + 2048) / 4096; 
                PDATA_WORD(1) = 0x0001;
            }
            else
            {
                if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
                {
                    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, _BIT7);
                }
                                
                PDATA_WORD(1) = ((((DWORD)(g_stMDomainInputData.usVHeight >> 1)) * pData[4]) + 2048) / 4096; 
                PDATA_WORD(0) = 0x0001;
            } 
#else
            // Shift direction
            if(((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_RL) && (GET_3D_SELECT_CONVERGENCE() == _3D_IN)) ||
               ((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_LR) && (GET_3D_SELECT_CONVERGENCE() == _3D_OUT)))            
            {
                if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
                {
                    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, _BIT7);
                }

                PDATA_WORD(1) = ((((DWORD)(g_stMDomainInputData.usVHeight >> 1)) * pData[4]) + 2048) / 4096; 
                PDATA_WORD(0) = 0x0001;
            }
            else
            {
                if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
                {
                    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);
                }

                PDATA_WORD(0) = ((((DWORD)(g_stMDomainInputData.usVHeight >> 1)) * pData[4]) + 2048) / 4096; 
                PDATA_WORD(1) = 0x0001;
            }  
#endif    

#else // Else of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

            // Shift direction
            if(GET_3D_SELECT_CONVERGENCE() == _3D_OUT)
            {
                if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
                {
                    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, _BIT7);
                }
        
                PDATA_WORD(1) = ((((DWORD)(g_stMDomainInputData.usVHeight >> 1)) * pData[4]) + 2048) / 4096; 
                PDATA_WORD(0) = 0x0001;
            }
            else
            {
                if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
                {
                    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);
                }
                
                PDATA_WORD(0) = ((((DWORD)(g_stMDomainInputData.usVHeight >> 1)) * pData[4]) + 2048) / 4096; 
                PDATA_WORD(1) = 0x0001;
            }            

#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

            // TurnPoint Setting
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_20_ACTIVE_SPACE_LINE0_M, HIBYTE(g_stMDomainInputData.usVHeight >> 1));
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_21_ACTIVE_SPACE_LINE0_L, LOBYTE(g_stMDomainInputData.usVHeight >> 1));

            if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)        
            { 
                // Mask Active Space Enable
                ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, ~_BIT0, _BIT0);
               
                // Enable new mode
                ScalerSetBit(CM_16_IPH_ACT_WID_H, ~_BIT1, _BIT1);
            }
        }
                
        // Calculate capture width
        if(PDATA_WORD(0) > PDATA_WORD(1))
        {
            g_stMDomainInputData.usHWidth = g_stMDomainInputData.usHWidth - PDATA_WORD(0);           
        }
        else
        {
            g_stMDomainInputData.usHWidth = g_stMDomainInputData.usHWidth - PDATA_WORD(1);          
        }                           
    }
    else // if(GET_3D_INPUT_FORMAT() == _LINE_INTERLACE)
    {           
        PDATA_WORD(0) = ((((DWORD)g_stMDomainInputData.usHWidth) * GET_3D_SHIFT_MODE_EFFECT()) + 960) / 1920; 
        g_stMDomainInputData.usHWidth = g_stMDomainInputData.usHWidth - PDATA_WORD(0);                      
    }                                                                 
         
    // Active start for L
    ScalerSetByte(P1C_A6_2D_TO_3D_CTL7, pData[0]);
    ScalerSetByte(P1C_A7_2D_TO_3D_CTL8, pData[1]);
    // Initial phase for L
    ScalerSetByte(P1C_AA_2D_TO_3D_CTL11, 0x00);
    // Active start for R
    ScalerSetByte(P1C_A8_2D_TO_3D_CTL9, pData[2]);
    ScalerSetByte(P1C_A9_2D_TO_3D_CTL10, pData[3]);
    // Initial phase for R
    ScalerSetByte(P1C_AB_2D_TO_3D_CTL12, 0x00); 
   
    if(GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF)
    {
        g_stMDomainInputData.usHWidth -= ((g_stMDomainInputData.usHWidth % 4) ? 6 : 8);
        ScalerSetByte(P1C_AC_2D_TO_3D_CTL13, HIBYTE(g_stMDomainInputData.usHWidth >> 1));
        ScalerSetByte(P1C_AD_2D_TO_3D_CTL14, LOBYTE(g_stMDomainInputData.usHWidth >> 1));    
    }
    else
    { 
        ScalerSetByte(P1C_AC_2D_TO_3D_CTL13, HIBYTE(g_stMDomainInputData.usHWidth));
        ScalerSetByte(P1C_AD_2D_TO_3D_CTL14, LOBYTE(g_stMDomainInputData.usHWidth));    
    }       
}

#if(_2D_TO_3D_FUNCTION == _ON)

//--------------------------------------------------
// Description  : Adjust Two to Three Dimension Function
// Input Value  : None
// Output Value : None
//-------------------------------------------------- 
void ScalerColorTwoThreeDimensionAdjust(BYTE ucChromaWeight, BYTE ucLPFWeight, BYTE ucHoleFill)
{
    // Enable double buffer
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT0, 0x00);

    // Clear input LR signal toggle flag
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT1, _BIT1);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);

// Output format is line-interleave for PR panel
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER) 

    // L/R flag reference to original
    g_ucP1CA5 &= ~_BIT3;

// Output format is frame-sequential for shutter glass
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES) 
    
    // No LR signal
    if(ScalerGetBit(P1C_A1_2D_TO_3D_CTL2, _BIT1) == 0x00)
    {
        // L/R flag reference to self generation
        g_ucP1CA5 |= _BIT3;
    }
    else // LR signal occurs
    {
        // L/R flag reference to original
        g_ucP1CA5 &= ~_BIT3;
    }    
#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)    

    // Set chroma weight and depth gain, VGA depth gain need <= 8
    if((ScalerGetBit(CM_10_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) && (GET_3D_DEPTH_GAIN() > 0x08))
    {
        ScalerSetByte(P1C_A2_2D_TO_3D_CTL3, ((ucChromaWeight << 6) | 0x08));        
    }
    else
    {
        ScalerSetByte(P1C_A2_2D_TO_3D_CTL3, ((ucChromaWeight << 6) | GET_3D_DEPTH_GAIN()));
    }

    // Select LPF weighting
    switch(ucLPFWeight)
    {
        case _LPF_BLUR_STRONG:

            // C0:6, C1:3
            ScalerSetByte(P1C_A3_2D_TO_3D_CTL4, 0x63); 
            // C2:2                  
            ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT5);
            
            break;

        case _LPF_BLUR_MEDIUM:

            // C0:6, C1:4
            ScalerSetByte(P1C_A3_2D_TO_3D_CTL4, 0x64); 
            // C2:1                  
            ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);
            
            break;

        case _LPF_BLUR_WEAK:
        default:

            // C0:8, C1:4
            ScalerSetByte(P1C_A3_2D_TO_3D_CTL4, 0x84); 
            // C2:0
            ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
            
            break;
    }

    // Enable LPF
    g_ucP1CA5 |= _BIT6;
    
    // Select fraction mode and rendering mode
    switch(ucHoleFill)
    {
        case _INTEGER_LEFT:

            // Fraction mode disable
            g_ucP1CA5 &= ~_BIT7;
            
            // Repeat left pixel
            ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~_BIT0, 0x00);
            
            break;

        case _INTEGER_INTERPOLATE:

            // Fraction mode disable
            g_ucP1CA5 &= ~_BIT7;
            
            // Repeat left and current pixel
            ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~_BIT0, _BIT0); 
            
            break;

        case _FRACTION_LEFT:

            // Fraction mode enable
            g_ucP1CA5 |= _BIT7;
            
            // Repeat left pixel
            ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~_BIT0, 0x00); 
            
            break;

        case _FRACTION_INTERPOLATE:
        default:

            // Fraction mode enable
            g_ucP1CA5 |= _BIT7;
            
            // Repeat left and current pixel
            ScalerSetBit(P1C_A4_2D_TO_3D_CTL5, ~_BIT0, _BIT0);             
            
            break;
    }
}

#endif // End of #if((_2D_TO_3D_FUNCTION == _ON)

#endif // End of #if(_3D_SUPPORT == _ON)

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
