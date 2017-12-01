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
// ID Code      : RL6297_Series_Color.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6297_SERIES_COLOR__

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

#define _DIG_FILTER_BGAIN                   0
#define _DIG_FILTER_GGAIN                   1
#define _DIG_FILTER_RGAIN                   2
#define _DIG_FILTER_RGB_CHANNEL             3

#define _DIG_FILTER_THRESHOLD1              30
#define _DIG_FILTER_OFFSET                  5
#define _DIG_FILTER_DELTA                   5

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
// STRUCT / TYPE / ENUM DEFINITTIONS
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

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
BYTE code tCOLOR_CONV_YUV2RGB_ITU709_RGBLIMIT[] =
{
    4, _NON_AUTOINC,    CM_9F_PAGE_SEL,                     0x14,
    25, _AUTOINC,       P14_A2_YUB_RGB_COEF_K11_HSB,        0x04, 0xA8, 0x07, 0x2c, 0x00, 0xda, 0x02, 0x22, 0x08, 
                                                            0x73, 0x3F, 0x00, 0x3F, 0x00, 0x3F, 0x00, 0x02, 0x54, 
                                                            0x02, 0x54, 0x02, 0x54,
    _END
};
#endif // End of #if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)

#if((_ULTRA_VIVID_SUPPORT == _ON) || (_RGB_QUANTIZATION_RANGE_SUPPORT == _ON))
BYTE code tCOLOR_CONV_RGB2YUV_ITU709[] =  //enable RGB2YUV
{
    33,  _NON_AUTOINC,   CM_9D_YUV_RGB_ACCESS,      0x00, 0xBB, 0x02, 0x75, 0x00, 0x3F, //h00~h02
                                                    0xFF, 0x99, 0xFE, 0xA6, 0x01, 0xC1, //h10~h12
                                                    0x01, 0xC1, 0xFE, 0x68, 0xFF, 0xD7, //h20~h22
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Roffset~B0ffset
                                                    0x02, 0x00, 0x02, 0x00, 0x02, 0x00, //Rgain~Bgain
    _END
};
#endif // End of #if((_ULTRA_VIVID_SUPPORT == _ON) || (_RGB_QUANTIZATION_RANGE_SUPPORT == _ON))

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
BYTE code tCOLOR_CONV_YUV2RGB_ITU601_YUVFULL[] =
{
    4,  _NON_AUTOINC,   CM_9F_PAGE_SEL,                     0x14,
    25, _AUTOINC,       P14_A2_YUB_RGB_COEF_K11_HSB,        0x04, 0x00, 0x05, 0x9c, 0x01, 0x60, 0x02, 0xdb, 0x07, 
                                                            0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
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
#endif //End of #if(_SIX_COLOR_SUPPORT == _ON)

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

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

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
void ScalerColorDigitalFilterEnhancePhaseAdjust(BYTE *pucBGRGain);
#endif

#endif  // End of #if(_VGA_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON)
bit ScalerColorGetIColorConvertStatus(void);
void ScalerColorIDitherOn(BYTE *pDitherTable, BYTE ucBankNum);
void ScalerColorIDitherOff(void);
#endif

#if(_D_DITHER_SUPPORT == _ON)
void ScalerColorDDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE *pThresholdTable, BYTE ucBankNum);
void ScalerColorDDitherAdjustPRShift(BYTE ucShiftOffset, bit bPRShiftEn);
#endif

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
void ScalerColorUltraVividAdjust(BYTE *pUltraVividSetting1, BYTE *pUltraVividSetting2, BYTE *pUltraVividSetting3, BYTE *pUltraVividSetting4, BYTE *pUltraVividCDSSetting, BYTE ucBankNum);
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
void ScalerColorHLW(bit bOn);
void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight);
void ScalerColorHLWBorderAdjust(BYTE ucBorderEn, BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue);

#if(_ULTRA_VIVID_SUPPORT == _ON)
void ScalerColorHLWUltraVividAdjust(EnumHLWType enumHLWActive);
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#endif  // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

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
#if((_ULTRA_VIVID_SUPPORT == _ON) || (_RGB_QUANTIZATION_RANGE_SUPPORT == _ON))
    // Enable YUV/RGB coefficient Access
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT4 | _BIT3));

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
#endif
        {
            // Load Table for RGB Quantization Full Range Case
            ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709, sizeof(tCOLOR_CONV_YUV2RGB_ITU709), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }                    

        // Set YCbCr Clamp
        ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));                
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

#if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if((ScalerColorUltraVividGetStatus() == _ON) || (GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE))
        {
            // Enable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);            
        }
        else
        {
            // Disable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);
        }
#else
        if(ScalerColorUltraVividGetStatus() == _ON)
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

#elif(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if(GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE)
        {
            // Enable I-Domain RGB2YUV
            ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);            
        }
        else
        {
            // Disable I-Domain RGB2YUV for UltraVivid
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
    
    ScalerTimerWaitForEvent(_EVENT_DVS);


    //////////////////////////////
    // D-Domain Color Conversion//
    //////////////////////////////
    if(enumColorFormat == _COLOR_SPACE_RGB)
    {

#if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if((ScalerColorUltraVividGetStatus() == _ON) || (GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE))
        {
            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#else
        if(ScalerColorUltraVividGetStatus() == _ON)
        {
            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#endif

#elif(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if(GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE)
        {
            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, _BIT0);
        }
        else
        {
            // Disable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
        }
#else
        // Disable D-Domain YUV2RGB
        ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~_BIT0, 0x00); 
#endif
    }
    else
    {
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

#endif  // End of #if(_VGA_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON) 
//--------------------------------------------------
// Description  : Get I-Domain Color Space Conversion/Ultravivid Status
// Input Value  : None
// Output Value : _ON / _OFF
//--------------------------------------------------
bit ScalerColorGetIColorConvertStatus(void)
{
    return (bit)ScalerGetBit(CM_9C_YUV2RGB_CTRL, _BIT0);
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
#endif    //#if(_SIX_COLOR_SUPPORT == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Disable UltraVivid
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorUltraVividOff(void)
{
    // Disable LSR
    ScalerSetBit(P14_C0_LSR_CTRL, ~(_BIT7), 0x00);

    //For double buffer
    ScalerVgipDoubleBufferApply();

    // Wait DVS for Ultravivid Settings to become effective    
    ScalerTimerWaitForEvent(_EVENT_DVS);
}

//--------------------------------------------------
// Description  : Get UltraVivid Status
// Input Value  : None
// Output Value : ON/OFF
//--------------------------------------------------
bit ScalerColorUltraVividGetStatus(void)
{
    if(ScalerGetBit(P14_C0_LSR_CTRL, _BIT7) == 0x00)
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
void ScalerColorUltraVividAdjust(BYTE *pUltraVividSetting1, BYTE *pUltraVividSetting2, BYTE *pUltraVividSetting3, BYTE *pUltraVividSetting4, BYTE *pUltraVividCDSSetting, BYTE ucBankNum)                                    
{     
    pUltraVividCDSSetting = pUltraVividCDSSetting;

    if(GET_V_SCALE_UP())
    {
        ScalerGetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_03_SU_VER_SCA_H, 2, pData, _AUTOINC);
        pData[0] = ((pData[0] << 4) | (pData[1] >> 4));

        if(pData[0] < 170)  // IVHeight/DVHeight < 2/3
        {
            ScalerBurstWrite(pUltraVividSetting1, 61, ucBankNum, P11_B9_SCALER_PEAKING_C0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }
        else    // IVHeight/DVHeight <= 1
        {
            ScalerBurstWrite(pUltraVividSetting2, 61, ucBankNum, P11_B9_SCALER_PEAKING_C0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }                
    }
    else if(GET_V_SCALE_DOWN())
    {
        ScalerBurstWrite(pUltraVividSetting3, 61, ucBankNum, P11_B9_SCALER_PEAKING_C0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    }
    else // by pass
    {
        ScalerBurstWrite(pUltraVividSetting4, 61, ucBankNum, P11_B9_SCALER_PEAKING_C0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    }      

    //For double buffer
    ScalerVgipDoubleBufferApply();

    // Wait DVS for Ultravivid Settings to become effective
    ScalerTimerWaitForEvent(_EVENT_DVS);
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
        //LSR
        ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~_BIT7, _BIT7);
#endif

    }
    else
    {
        ScalerSetBit(CM_60_HW_ACCESS_PORT, ~_BIT6, 0x00);

#if(_ULTRA_VIVID_SUPPORT == _ON)        
        //LSR
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
    DWORD ulScale = 0;
    BYTE pucTemp[8];
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

    //Horizontal refers to timing of S domain
    if(GET_H_SCALE_UP() == _TRUE)
    {
        ScalerGetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, 3, &pucTemp[5], _AUTOINC);

        ulScale = (((DWORD)(pucTemp[5] & 0x0F) << 16) | ((DWORD)pucTemp[6] << 8) | (pucTemp[7])); 

        usHPos = (ulScale * usHPos) >> 20;
        usHWidth = (ulScale * usHWidth) >> 20;            
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
    ScalerWrite(P11_CC_VPK_VCTI_HLW_H_START_HIGH, 8, pucTemp, _AUTOINC);
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
            break;

        case _INSIDE_WINDOW:
            ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), _BIT7);
            break;

        case _OUTSIDE_WINDOW:
            ScalerSetBit(P11_B9_SCALER_PEAKING_C0, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);
            break;

        default:
            break;
    }   
}
#endif // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

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
