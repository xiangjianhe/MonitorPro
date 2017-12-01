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
// ID Code      : ScalerColor.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COLOR__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _DCC_HISTO_YMAX_LB                    0x00
#define _DCC_HISTO_YMIN_HB                    0xFF

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_GLOBAL_HUE_SATURATION == _ON)
BYTE code ucCosCurveAngle[] = {0, 6, 12, 18, 24, 30, 37, 44, 52, 60, 68, 78, 90};
WORD code usCosCurveValue[] = {1024, 1018, 1002, 974, 935, 887, 818, 737, 630, 512, 384, 213, 0};

BYTE code ucSinCurveAngle[] = {0, 6, 12, 18, 24, 30, 37, 44, 52, 60, 68, 78, 90};
WORD code usSinCurveValue[] = {0, 107, 213, 316, 416, 512, 616, 711, 807, 887, 949, 1002, 1024};

// 1->1024
SWORD code tYUV2RGB[][3] =
{
    { 1024,      0,    1436 },
    { 1024,  - 352,   - 731 },
    { 1024,   1815,       0 }
};

// 1->1024
SWORD code tRGB2YUV[][3] =
{
    {  306,    601,     117},
    {- 173,  - 339,     512},
    {  512,  - 429,   -  83}
};
#endif

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE idata g_ucColorInfo = 0;
BYTE idata g_ucColorInfo2 = 0;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
EnumColorSpace ScalerColorGetColorSpace(void);
void ScalerColor422To444(void);
void ScalerColorBriConSetCoef(EnumBriConCoefType enumCoefSet, BYTE *pData);
void ScalerColorBriConOff(void);

#if(_I_DITHER_SUPPORT == _ON) 
void ScalerColorIDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE ucBankNum);
#endif

#if(_D_DITHER_SUPPORT == _ON)
void ScalerColorDDither(bit bOn);
#endif

#if(_GAMMA_FUNCTION == _ON)
void ScalerColorOutputGammaAdjust(BYTE *pGammaTableArray, BYTE ucBankNum);

#if(_GAMMA_WRITE_FUNCTION == _ON)
void ScalerColorOutputGammaWriteTable(BYTE *pGammaData, EnumGammaChannel enumGammaChannel, BYTE ucOffset, WORD usDataLength);
#endif  // End of #if(_GAMMA_WRITE_SUPPORT == _ON)

#endif // End of #if(_GAMMA_FUNCTION == _ON)

#if((_GAMMA_FUNCTION == _ON) || (_PCM_FUNCTION == _ON))
void ScalerColorOutputGamma(bit bOn);
void ScalerColorOutputGammaChannelCtrl(BYTE ucColorChannel, BYTE ucOffset, bit bLocation);
#endif  // End of #if((_GAMMA_FUNCTION == _ON) || (_PCM_FUNCTION == _ON))

#if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))
void ScalerColorSRGB(bit bOn);
#endif  // End of #if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))

#if(_GLOBAL_HUE_SATURATION == _ON)
SWORD ScalerColorSRGBCosine(SWORD shDegree);
SWORD ScalerColorSRGBSine(SWORD shDegree);
void ScalerColorSRGBMatrixMultiply(SWORD(*shArrayA)[3], SWORD(*shArrayB)[3], SWORD(*shArrayC)[3]);
void ScalerColorSRGBSetGlobalHueSat(SWORD shDeltaHue, WORD usDeltaSat);
#endif // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if(_DCC_FUNCTION == _ON)
void ScalerColorDCC(bit bOn);
void ScalerColorDCCAdjust(BYTE *pDccTable, BYTE ucBankAddress, BYTE ucAdjustOption);
#endif // End of #if(_DCC_FUNCTION == _ON)

#if(_DCC_HISTOGRM_INFO == _ON)
void ScalerColorDCCHistoSetting(void);
#endif // End of #if(_DCC_HISTOGRM_INFO == _ON)

#if((_DCC_FUNCTION == _ON) || (_DCC_HISTOGRM_INFO == _ON))
void ScalerColorDCCNormalizeFactorAdjust(void);
#endif // End of #if((_DCC_FUNCTION == _ON) || (_DCC_HISTOGRM_INFO == _ON))

#if(_YPEAKING_SUPPORT == _ON)
void ScalerColorYpeaking(bit bOn);
void ScalerColorYpeakingAdjust(EnumYpeakingMode enumYPeakMode, BYTE ucGain, EnumYpeakingCoeffResolution enumResolution, BYTE *pAddress, WORD usWriteLength, BYTE ucBankNum);
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
void ScalerColorHLWBriConAdjust(EnumBriConHLWType enumHLWActive);

#if(_GAMMA_FUNCTION == _ON)
void ScalerColorHLWOutputGammaAdjust(EnumHLWType enumHLWActive);
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
void ScalerColorHLWSRGBAdjust(EnumHLWType enumHLWActive);
#endif

#if((_ICM_SUPPORT == _ON) || (_DCC_FUNCTION == _ON))
void ScalerColorHLWICMDCCAdjust(EnumHLWType enumHLWActive);
#endif 

#if(_DCR_SUPPORT == _ON)
void ScalerColorHLWDCRAdjust(EnumHLWType enumHLWActive);
#endif

#if(_YPEAKING_SUPPORT == _ON)
void ScalerColorHLWYpeakingAdjust(EnumHLWType enumHLWActive);
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#endif // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

#if (_YPBPR_SUPPORT == _ON)
void ScalerColorSetColorimetry(bit bHDTVMode);
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
BYTE ScalerColorGetRGBQuantizationRange(void);
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
bit ScalerColorGetYCCQuantizationRange(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Return Current Color Space for Upper Layer
// Input Value  : None
// Output Value : Current Color Space
//--------------------------------------------------
EnumColorSpace ScalerColorGetColorSpace(void)
{
    return GET_COLOR_SPACE();
}

//--------------------------------------------------
// Description  : Judge Whether to Enable YUV 422 to 444 Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColor422To444(void)
{    
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422)
    {
        // Enable YUV 422 to 444 function
        ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~(_BIT3 | _BIT2 | _BIT1), _BIT3);
    }
    else
    {
        // Disable YUV 422 to 444 function
        ScalerSetBit(CM_1F_V8_YUV_CONVERSION, ~_BIT3, 0x00);
    }    
}

//--------------------------------------------------
// Description  : Set Brightness/Contrast Data and Enable Brightness/Contrast
// Input Value  : pData --> Brightness/Contrast Value
// Output Value : None
//--------------------------------------------------
void ScalerColorBriConSetCoef(EnumBriConCoefType enumCoefSet, BYTE *pData)
{
    // Enable Brightness/Contrast access port
    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT7, _BIT7);

    switch(enumCoefSet)
    {
        case _BRIGHTNESS_COEF_A:

            // Access Brightness/Contrast Data Port
            ScalerSetBit(CM_64_CB_ACCESS_PORT, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CM_65_PT_00_CB_BRI_R_COEF_A);

            break;

        case _BRIGHTNESS_COEF_B:
            
            // Access Brightness/Contrast Data Port
            ScalerSetBit(CM_64_CB_ACCESS_PORT, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CM_65_PT_06_CB_BRI_R_COEF_B);

            break;

        case _CONTRAST_COEF_A:
            
            // Access Brightness/Contrast Data Port
            ScalerSetBit(CM_64_CB_ACCESS_PORT, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CM_65_PT_03_CB_CTS_R_COEF_A);

            break;

        case _CONTRAST_COEF_B:
            
            // Access Brightness/Contrast Data Port
            ScalerSetBit(CM_64_CB_ACCESS_PORT, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CM_65_PT_09_CB_CTS_R_COEF_B);

            break;

        default:
            break;
    }

    // Set Brightness/Contrast Coefficient
    ScalerWrite(CM_65_CB_DATA_PORT, 3, pData, _NON_AUTOINC);

    // Disable Brightness/Contrast Access Port
    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT7, 0x00);

    // Enable Brightness/Contrast
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

}

//--------------------------------------------------
// Description  : Disable Contrast and Brightness
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorBriConOff(void)
{
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT1 | _BIT0), 0x00);
}

#if(_I_DITHER_SUPPORT == _ON) 
//--------------------------------------------------
// Description  : Set IDithering Tables and Enable IDither
// Input Value  : Dithering tables
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE ucBankNum)
{
    // Set I-Dither Table
    if(pDitherTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
        ScalerBurstWrite(pDitherTable, 24, ucBankNum, CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
    
    // Set I-Dither Sequence Table
    if(pDitherSeqTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
        ScalerBurstWrite(pDitherSeqTable, 24, ucBankNum, CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
    
    // Set I-Dither Temporal Table
#if(_I_DITHER_TEMP == _ENABLE)
    if(pDitherTempoffsetTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
        ScalerBurstWrite(pDitherTempoffsetTable, 24, ucBankNum, CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
#else
    if(pDitherTempoffsetTable != _NULL_POINTER)
    {
    
    }
#endif

    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ((_I_DITHER_TEMP << 4) | (_I_DITHER_VALUE_SIGN << 3) | (_I_DITHER_V_FRAME_MOD << 1) | ( _I_DITHER_H_FRAME_MOD)));

    // Enable I Dither
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~_BIT5, _BIT5);
}
#endif // End of #if(_I_DITHER_SUPPORT == _ON) 

#if(_D_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable DDither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDDither(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(CM_6A_DITHERING_CTRL1, ~_BIT5, _BIT5);
    }
    else
    {
        ScalerSetBit(CM_6A_DITHERING_CTRL1, ~_BIT5, 0x00);
    }
}
#endif // End of #if(_D_DITHER_SUPPORT == _ON)

#if(_GAMMA_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Adjust output gamma
// Input Value  : Gamma table type and gamma tables
// Output Value : None
//--------------------------------------------------
void ScalerColorOutputGammaAdjust(BYTE *pGammaTableArray, BYTE ucBankNum)
{
    // Enable Gamma access
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, _BIT7); 

    // Load gamma table of R Channel
    ScalerColorOutputGammaChannelCtrl(_GAMMA_RED_CHANNEL, 0x00, _GAMMA_WRITE_TO_SRAM);
    ScalerBurstWrite(pGammaTableArray, 387, ucBankNum, CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Load gamma table of G Channel
    ScalerColorOutputGammaChannelCtrl(_GAMMA_GREEN_CHANNEL, 0x00, _GAMMA_WRITE_TO_SRAM);
    ScalerBurstWrite(pGammaTableArray + 387, 387, ucBankNum, CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);   

    // Load gamma table of B Channel
    ScalerColorOutputGammaChannelCtrl(_GAMMA_BLUE_CHANNEL, 0x00, _GAMMA_WRITE_TO_SRAM);
    ScalerBurstWrite(pGammaTableArray + (387 * 2), 387, ucBankNum, CM_66_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);    

    // Disable Port Access
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, 0x00);

    // Set sRGB before Contrast/Brightness
    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT6, 0x00);
}

#if(_GAMMA_WRITE_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Adjust output gamma by selecting Channel/Offset/Length
// Input Value  : 
// Output Value : None
//--------------------------------------------------
void ScalerColorOutputGammaWriteTable(BYTE *pGammaData, EnumGammaChannel enumGammaChannel, BYTE ucOffset, WORD usDataLength)
{
    // Enable Gamma access
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, _BIT7); 

    // Set Gamma Channel
    ScalerColorOutputGammaChannelCtrl(enumGammaChannel, ucOffset, _GAMMA_WRITE_TO_SRAM);

    // Write Gamma LUT
    ScalerWrite(CM_66_GAMMA_PORT, usDataLength, pGammaData, _NON_AUTOINC);

    // Disable Port Access
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT7, 0x00);

    // Set sRGB before Contrast/Brightness
    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT6, 0x00);
}
#endif  // End of #if(_GAMMA_WRITE_SUPPORT == _ON)

#endif // End of #if(_GAMMA_FUNCTION == _ON)

#if((_GAMMA_FUNCTION == _ON) || (_PCM_FUNCTION == _ON))
//--------------------------------------------------
// Description  : Enable/Disable output gamma
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorOutputGamma(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, _BIT6);
    }
    else
    {
        ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT6, 0x00);
    }
}

//--------------------------------------------------
// Description  : Switch Gamma Channel
// Input Value  : ucColorChannel: 0- Red, 1- Green, 2- Blue;  
//                bLocation: 0-Write to SDRAM, 1- Write to LATCH
// Output Value : None
//--------------------------------------------------
void ScalerColorOutputGammaChannelCtrl(BYTE ucColorChannel, BYTE ucOffset, bit bLocation)
{
    // Write To SDRAM or Latch
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT2, ((BYTE)bLocation << 2));

    // Select Channel 
    ScalerSetBit(CM_67_GAMMA_CTRL, ~(_BIT5 | _BIT4), (ucColorChannel & 0x03) << 4);

    // Specify address
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT3, _BIT3);
    ScalerSetByte(CM_66_GAMMA_PORT, ucOffset);
    ScalerSetBit(CM_67_GAMMA_CTRL, ~_BIT3, 0x00);
}
#endif  // End of #if((_GAMMA_FUNCTION == _ON) || (_PCM_FUNCTION == _ON))

#if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))
//--------------------------------------------------
// Description  : Enable/Disable sRGB function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorSRGB(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT7 | _BIT2), (_BIT7 | _BIT2));
    }
    else
    {
        ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT2, 0x00);
    }
}
#endif  // End of #if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))

#if(_GLOBAL_HUE_SATURATION == _ON)
//--------------------------------------------------
// Description  : Calculate Cos(x)
// Input Value  : shDegree x (in 360 unit)
// Output Value : SWORD Cos(x)
//--------------------------------------------------
SWORD ScalerColorSRGBCosine(SWORD shDegree)
{
    BYTE ucI = 0;
    BYTE ucQuadrant = 0;
    BYTE ucDegreeTemp = 0;
    BYTE ucDegreeSpan = 0;
    SWORD shCosValueSpan = 0;
    SWORD shCosValue = 0;

    if(shDegree < 0)
    {
        shDegree += 360;
    }

    shDegree = shDegree % 360;
    
    // Locate degree on which quadrant
    ucQuadrant = (BYTE)(shDegree / 90);
    ucQuadrant++;

    switch(ucQuadrant)
    {
        // First quadrant
        case 1:

            shDegree = shDegree;
            
            break;

        // Second quadrant
        case 2:

            shDegree = 180 - shDegree;
            
            break;

        // Third quadrant
        case 3:

            shDegree = shDegree - 180;
            
            break;

        // Forth quadrant
        case 4:

            shDegree = 360 - shDegree;
            
            break;

        default:
            
            break;
    }

    // Locate degree on which quadrant
    if(shDegree <= ucCosCurveAngle[0])
    {
        shCosValue = usCosCurveValue[0];
    }
    else
    {
        for(ucI = 0; ucCosCurveAngle[ucI] < shDegree; ucI++)
        {
            ;
        }

        ucI--;
        
        ucDegreeTemp = shDegree - ucCosCurveAngle[ucI];
        ucDegreeSpan = ucCosCurveAngle[ucI+1] - ucCosCurveAngle[ucI];
        shCosValueSpan = usCosCurveValue[ucI+1] - usCosCurveValue[ucI];
        shCosValue = usCosCurveValue[ucI] + (SWORD)ucDegreeTemp * shCosValueSpan / ucDegreeSpan;
    }

    if((ucQuadrant == 2) || (ucQuadrant == 3))
    {
        shCosValue = shCosValue * (-1);
    }

    return shCosValue;
}

//--------------------------------------------------
// Description  : Calculate Sin(x)
// Input Value  : shDegree x (in 360 unit)
// Output Value : SWORD Sin(x)
//--------------------------------------------------
SWORD ScalerColorSRGBSine(SWORD shDegree)
{
    BYTE ucI = 0;
    BYTE ucQuadrant = 0;
    BYTE ucDegreeTemp = 0;
    BYTE ucDegreeSpan = 0;
    WORD usSinValueSpan = 0;
    SWORD shSinValue = 0;


    if(shDegree < 0)
    {
        shDegree += 360;
    }

    shDegree = shDegree % 360;

    // Locate degree on which quadrant
    ucQuadrant = (BYTE)(shDegree / 90);
    ucQuadrant++;

    switch(ucQuadrant)
    {
        // First quadrant
        case 1:

            shDegree = shDegree;
            
            break;

        // Second quadrant
        case 2:

            shDegree = 180 - shDegree;
            
            break;

        // Third quadrant
        case 3:

            shDegree = shDegree - 180;
            
            break;

        // Forth quadrant
        case 4:

            shDegree = 360 - shDegree;
            
            break;

        default:
            
            break;
    }

    // Locate degree on which quadrant
    if(shDegree <= ucSinCurveAngle[0])
    {
        shSinValue = usSinCurveValue[0];
    }
    else
    {
        for(ucI = 0; ucSinCurveAngle[ucI] < shDegree; ucI++)
        {
            ;
        }

        ucI--;

        ucDegreeTemp = shDegree - ucSinCurveAngle[ucI];
        ucDegreeSpan = ucSinCurveAngle[ucI+1] - ucSinCurveAngle[ucI];
        usSinValueSpan = usSinCurveValue[ucI+1] - usSinCurveValue[ucI];
        shSinValue = usSinCurveValue[ucI] + (WORD)ucDegreeTemp * usSinValueSpan / ucDegreeSpan; 
    }

    if((ucQuadrant == 3) || (ucQuadrant == 4))
    {
        shSinValue = shSinValue * (-1);
    }

    return shSinValue;
}

//--------------------------------------------------
// Description  : Do matrix multiply(3x3)  C = A*B
// Input Value  : shArrayA, shArrayB
// Output Value : shArrayC
//--------------------------------------------------
void ScalerColorSRGBMatrixMultiply(SWORD(*shArrayA)[3], SWORD(*shArrayB)[3], SWORD(*shArrayC)[3])
{
    BYTE ucI = 0;
    BYTE ucJ = 0;

    for(ucJ = 0; ucJ < 3; ucJ++)
    {
        for(ucI = 0; ucI < 3; ucI++)
        {
            PDATA_DWORD(ucI) = (((SDWORD)shArrayA[ucI][0] * shArrayB[0][ucJ] + 2) >> 2) +
                               (((SDWORD)shArrayA[ucI][1] * shArrayB[1][ucJ] + 2) >> 2) +
                               (((SDWORD)shArrayA[ucI][2] * shArrayB[2][ucJ] + 2) >> 2);
        }

        for(ucI = 0; ucI < 3; ucI++)
        {
            shArrayC[ucI][ucJ] = (SWORD)((PDATA_DWORD(ucI) + 128) >> 8);
        }
    }
}

//--------------------------------------------------
// Description  : Set global Hue&Sat
// Input Value  : DeltaHue(-180~180), DeltaSat(0-330)  
// Default Value: Delta Hue = 0, Delta Sat = 100;
// Notice !! Rightnow the Hue/Sat value is saved to NVRAM as BYTE, if you 
// want to expand the Range, please edit relative functions and parameters.
// Output Value : pColorMatrix(3x3, set to sRGB Matrix)
//--------------------------------------------------
void ScalerColorSRGBSetGlobalHueSat(SWORD shDeltaHue, WORD usDeltaSat)
{
    SWORD sMATRIX[3][3] = {0};
    SWORD sTempBuff[3][3] = {0};
    BYTE ucI = 0;
    BYTE ucJ = 0;
    BYTE ucShiftleft = 0;
    BYTE pColorMatrix[18] = {0}; 

    // 1->1024
    sMATRIX[0][0] = 1024;
    sMATRIX[0][1] = 0;
    sMATRIX[0][2] = 0;
    sMATRIX[1][0] = 0;
    sMATRIX[1][1] = (DWORD)usDeltaSat * 1024 / 100;
    sMATRIX[1][2] = 0;
    sMATRIX[2][0] = 0;
    sMATRIX[2][1] = 0;
    sMATRIX[2][2] = sMATRIX[1][1];

    ScalerColorSRGBMatrixMultiply(sMATRIX, tRGB2YUV, sTempBuff);

    sMATRIX[0][0] = 1024;
    sMATRIX[0][1] = 0;
    sMATRIX[0][2] = 0;
    sMATRIX[1][0] = 0;
    sMATRIX[1][1] = ScalerColorSRGBCosine(shDeltaHue);
    sMATRIX[1][2] = (-1) * ScalerColorSRGBSine(shDeltaHue);
    sMATRIX[2][0] = 0;
    sMATRIX[2][1] = (-1) * sMATRIX[1][2];
    sMATRIX[2][2] = sMATRIX[1][1];

    ScalerColorSRGBMatrixMultiply(sMATRIX, sTempBuff, sTempBuff);
    ScalerColorSRGBMatrixMultiply(tYUV2RGB, sTempBuff, sTempBuff);	
    
    // set 1+RR,  1+GG, 1+BB
    for(ucI = 0; ucI < 3; ucI++)
    {
        for(ucJ = 0; ucJ < 3; ucJ++)
        {
            if(ucI == ucJ)
            {
                sTempBuff[ucI][ucJ] -= 1024;
            }

            if(sTempBuff[ucI][ucJ] >= 0)
            {
                sTempBuff[ucI][ucJ] = ((sTempBuff[ucI][ucJ] + 8) / 16);
            }
            else
            {
                sTempBuff[ucI][ucJ] = ((sTempBuff[ucI][ucJ] - 8) / 16);   
            }

            if(sTempBuff[ucI][ucJ] > 255)
            {
                sTempBuff[ucI][ucJ] = 255;
            }
            else if(sTempBuff[ucI][ucJ] < -256)
            {
                sTempBuff[ucI][ucJ] = -256;
            }

            // Set sign byte  XXH
            pColorMatrix[2 * (3 * ucI + ucJ)] = (sTempBuff[ucI][ucJ] < 0) ? 1 : 0; 

            // Set data byte XXL
            pColorMatrix[2 * (3 * ucI + ucJ) + 1] = (BYTE)sTempBuff[ucI][ucJ];

        }
    }

    ScalerColorSRGBAdjust(pColorMatrix);
}
#endif // End of #if(_GLOBAL_HUE_SATURATION == _ON)


#if(_DCC_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Enable/Disable DCC Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDCC(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(P7_C8_DCC_CTRL1, ~_BIT7, _BIT7);
    }
    else
    {
        ScalerSetBit(P7_C8_DCC_CTRL1, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust DCC Parameter
// Input Value  : pDccTable -> DCC control&user_curve register table
//                ucBankAddress -> Bank address
//                ucAdjustOption -> 
//                        _BIT7: _BURSTWRITE_FROM_FLASH / _BURSTWRITE_FROM_XRAM
//                        _BIT6: Y_FORMULA -> 0: Y = (2R+5G+B)/8, 1: Y = (5R+8G+3B)/16 
//                        _BIT5: SOFT_CLAMP -> 0: Disable, 1: Enable
//                        _BIT4: DCC_MODE -> 0:Auto Mode, 1: Manual Mode
//                        _BIT3: SCENE_CHANGE -> 0: Disable, 1: Enable
//                        _BIT1: Saturation Compensation -> 0: Disable, 1: Enable
//                        _BIT0: BLD_MODE -> 0: old mode, 1: new mode    
// Output Value : None
//--------------------------------------------------
void ScalerColorDCCAdjust(BYTE *pDccTable, BYTE ucBankAddress, BYTE ucAdjustOption)
{
    // Fill DCC control table
    // Select page0
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x03);
    ScalerBurstWrite(pDccTable, 1, ucBankAddress, P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, (bit)(ucAdjustOption & _BIT7));
    ScalerSetDataPortBit(P7_C9_DCC_ACCESS_PORT, 0x04, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x05);
    ScalerBurstWrite(&pDccTable[2], 7, ucBankAddress, P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, (bit)(ucAdjustOption & _BIT7));

    // Set Y max lower bound and Y min higher bound
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_07_Y_MAX_LB);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, _DCC_HISTO_YMAX_LB);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, _DCC_HISTO_YMIN_HB);

    // Fill DCC user curve table
    // Select page1
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE1);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, 0x00);
    ScalerBurstWrite(&pDccTable[9], 23, ucBankAddress, P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, (bit)(ucAdjustOption & _BIT7));

    ScalerSetBit(P7_C8_DCC_CTRL1, ~(_BIT5 | _BIT4), ((ucAdjustOption & 0x03) << 4));
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (ucAdjustOption & 0x78) | _BIT7);
    ScalerTimerPollingFlagProc(50, P7_C7_DCC_CTRL0, _BIT7, _BIT7);

    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerBurstWrite(&pDccTable[1], 1, ucBankAddress, P7_CA_DCC_DATA_PORT, _BURSTWRITE_DATA_COMMON, (bit)(ucAdjustOption & _BIT7));
}
#endif // End of #if(_DCC_FUNCTION == _ON)

#if(_DCC_HISTOGRM_INFO == _ON)
//--------------------------------------------------
// Description  : Set Y_MAX_LB, Y_MIN_HB
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDCCHistoSetting(void)
{
    // Set Y max lower bound and Y min higher bound
    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_07_Y_MAX_LB);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, _DCC_HISTO_YMAX_LB);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, _DCC_HISTO_YMIN_HB);

    // Enable DCC
    ScalerSetBit(P7_C7_DCC_CTRL0, ~_BIT7, _BIT7);
}
#endif // End of #if(_DCC_HISTOGRM_INFO == _ON)

#if((_DCC_FUNCTION == _ON) || (_DCC_HISTOGRM_INFO == _ON))
//--------------------------------------------------
// Description  : Adjust Normalize Factor
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDCCNormalizeFactorAdjust(void)
{
    WORD usHWidth = 0;
    WORD usVHeight = 0;

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    WORD usHStart = 0;
    WORD usHEnd = 0;
    WORD usVStart = 0;
    WORD usVEnd = 0;
    BYTE ucBorder = 0;

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
                    PDATA_DWORD(0)  = ((DWORD)4194304 * 255 / usHWidth / usVHeight) & 0x3fffff;
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
                    PDATA_DWORD(0)  = ((DWORD)4194304 * 255 / usHWidth / usVHeight) & 0x3fffff;
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

                    // Calculate Outside Count
                    PDATA_DWORD(1) =  ((DWORD)(g_stMDomainOutputData.usHWidth)*(DWORD)(g_stMDomainOutputData.usVHeight)) -  (DWORD)usHWidth*(DWORD)usVHeight;
                    PDATA_DWORD(0)  = ((DWORD)4194304 * 255 / PDATA_DWORD(1)) & 0x3fffff;
                    break;

                default:
                    
                    usHWidth = g_stMDomainOutputData.usHWidth;
                    usVHeight = g_stMDomainOutputData.usVHeight;
                    PDATA_DWORD(0)  = ((DWORD)4194304 * 255 / usHWidth / usVHeight) & 0x3fffff;
                    break;
        }
        ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    }
    else
    {
        usHWidth = g_stMDomainOutputData.usHWidth;   
        usVHeight = g_stMDomainOutputData.usVHeight; 
        PDATA_DWORD(0)  = ((DWORD)4194304 * 255 / usHWidth / usVHeight) & 0x3fffff;
    }
#else
    usHWidth = g_stMDomainOutputData.usHWidth;   
    usVHeight = g_stMDomainOutputData.usVHeight; 
    PDATA_DWORD(0)  = ((DWORD)4194304 * 255 / usHWidth / usVHeight) & 0x3fffff;
#endif

    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_00_NOR_FACTOR_H);
    ScalerWrite(P7_CA_DCC_DATA_PORT, 3, &pData[1], _NON_AUTOINC); 
}
#endif // End of #if((_DCC_FUNCTION == _ON) || (_DCC_HISTOGRM_INFO == _ON))

#if(_YPEAKING_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Ypeaking enable/disable function.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorYpeaking(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT6, _BIT6);
    }
    else
    {
        ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT6, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set Ypeaking Coefficient Filter and Resolution
// Input Value  : Coefficient Filter and Resolution
// Output Value : None
//--------------------------------------------------
void ScalerColorYpeakingAdjust(EnumYpeakingMode enumYPeakMode, BYTE ucGain, EnumYpeakingCoeffResolution enumResolution, BYTE *pAddress, WORD usWriteLength, BYTE ucBankNum)
{
    if(enumYPeakMode == _YPEAKING_GAIN_MODE)
    {
        if(ucGain > 126)
        {
            ucGain = 126;
        }
        else if((ucGain < 14) && (ucGain > 0))
        {
            ucGain = 14;
        }
        else if(ucGain == 0)
        {
            ScalerColorYpeaking(_OFF);            
            return;       
        }

        pData[0] = ucGain & 0x7E;

        if((ucGain & _BIT0) == _TRUE)
        {
            pData[1] = (SWORD)0 - (pData[0] >> 1);
            pData[2] = 0;
        }
        else
        {
            pData[1] = (SWORD)0 - ((pData[0] + 4) >> 1);
            pData[2] = 2;
        }

        pData[3] = (BYTE)_YPEAKING_CORING_MIN;
        pData[4] = (BYTE)_YPEAKING_MAX_POS;
        pData[5] = (SBYTE)_YPEAKING_MAX_NEG;

        ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~(_BIT7 | _BIT5 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | (enumResolution << 5)));
        ScalerWrite(P7_D7_PKING_DATA_PORT, 6, pData, _NON_AUTOINC);
        ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), 0x00);
    }
    else if(enumYPeakMode == _YPEAKING_TABLE_MODE)
    {
        // Set Coefficient table 1
        ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT7, _BIT7); 
        ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerBurstWrite(pAddress, usWriteLength, ucBankNum, P7_D7_PKING_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
        
        // Disable Coefficient Access & set H/V Scale Up to use coefficient table 1
        ScalerSetBit(P7_D6_PKING_ACCESS_PORT, ~_BIT7, 0x00);
    }

    ScalerColorYpeaking(_ON); 
}
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set contrast/backlight Highlight Window
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWBriConAdjust(EnumBriConHLWType enumHLWActive)         
{
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT7 | _BIT6), ((enumHLWActive & 0x03) << 6));   
}

#if(_GAMMA_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Adjust output gamma Highlight Window
// Input Value  : Highlight Window Active Area
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWOutputGammaAdjust(EnumHLWType enumHLWActive)
{
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT5 | _BIT4) , ((enumHLWActive & 0x03) << 4));    
}
#endif // End of #if(_GAMMA_FUNCTION == _ON)

#if(_GLOBAL_HUE_SATURATION == _ON)
//--------------------------------------------------
// Description  : Adjust SRGB Highlight Window
// Input Value  : Highlight Window Active Area
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWSRGBAdjust(EnumHLWType enumHLWActive)
{
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT7| _BIT6) , ((enumHLWActive & 0x03) << 6));    
}
#endif // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if((_ICM_SUPPORT == _ON) || (_DCC_FUNCTION == _ON))
//--------------------------------------------------
// Description  : Adjust ICM/DCC Highlight Window Active Region
// Input Value  : Highlight Window Actvie Region Option
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWICMDCCAdjust(EnumHLWType enumHLWActive)
{
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT3 | _BIT2), ((enumHLWActive & 0x03) << 2));
}
#endif // End of #if((_ICM_SUPPORT == _ON) || (_DCC_FUNCTION == _ON))

#if(_DCR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set DCR Highlight Window
// Input Value  : Highlight Window Active Region
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWDCRAdjust(EnumHLWType enumHLWActive)
{
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0D_HW_WINDOW_CTRL1, ~(_BIT5 | _BIT4), ((enumHLWActive & 0x03) << 4));
}
#endif // End of #if(_DCR_SUPPORT == _ON)

#if(_YPEAKING_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Ypeaking HLW.
// Input Value  : Ypeaking table
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWYpeakingAdjust(EnumHLWType enumHLWActive)
{        
    ScalerSetDataPortBit(CM_60_HW_ACCESS_PORT, _CM_61_PT_0C_HW_WINDOW_CTRL0, ~(_BIT1| _BIT0) , enumHLWActive);             
}                                                                   
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#endif // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

#if(_YPBPR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Colorimetry
// Input Value  : bHDTVMode ---> HD TV Mode Flag
// Output Value : None
//--------------------------------------------------
void ScalerColorSetColorimetry(bit bHDTVMode)
{
    if(bHDTVMode == _TRUE)
    {
        SET_COLORIMETRY(_COLORIMETRY_ITU709);
    }
    else
    {
        SET_COLORIMETRY(_COLORIMETRY_ITU601);
    }
}
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get RGB Quantization Range
// Input Value  : None
// Output Value : Full/Limited/Default/Reserved
//--------------------------------------------------
BYTE ScalerColorGetRGBQuantizationRange(void)
{
    return GET_COLOR_RGB_QUANTIZATION_RANGE();
}
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get YCC Quantization Range
// Input Value  : None
// Output Value : Full/Limited
//--------------------------------------------------
bit ScalerColorGetYCCQuantizationRange(void)
{
    return GET_COLOR_YCC_QUANTIZATION_RANGE();
}
#endif

