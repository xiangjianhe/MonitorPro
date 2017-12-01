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
// ID Code      : ScalerColorInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern EnumColorSpace ScalerColorGetColorSpace(void);
extern void ScalerColor422To444(void);
extern void ScalerColorBriConSetCoef(EnumBriConCoefType enumCoefSet, BYTE *pData);
extern void ScalerColorBriConOff(void);

#if(_I_DITHER_SUPPORT == _ON) 
extern void ScalerColorIDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE ucBankNum);
#endif

#if(_D_DITHER_SUPPORT == _ON)
extern void ScalerColorDDither(bit bOn);
#endif

#if(_GAMMA_FUNCTION == _ON)
extern void ScalerColorOutputGammaAdjust(BYTE *pGammaTableArray, BYTE ucBankNum);

#if(_GAMMA_WRITE_FUNCTION == _ON)
extern void ScalerColorOutputGammaWriteTable(BYTE *pGammaData, EnumGammaChannel enumGammaChannel, BYTE ucOffset, WORD usDataLength);
#endif

#endif

#if((_GAMMA_FUNCTION == _ON) || (_PCM_FUNCTION == _ON))
extern void ScalerColorOutputGamma(bit bOn);
#endif

#if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))
extern void ScalerColorSRGB(bit bOn);
#endif

#if(_GLOBAL_HUE_SATURATION == _ON) 
extern void ScalerColorSRGBSetGlobalHueSat(SWORD shDeltaHue, WORD usDeltaSat);
#endif

#if(_DCC_FUNCTION == _ON)
extern void ScalerColorDCC(bit bOn);
extern void ScalerColorDCCAdjust(BYTE *pDccTable, BYTE ucBankAddress, BYTE ucAdjustOption);
#endif // End of #if(_DCC_FUNCTION == _ON)

#if(_DCC_HISTOGRM_INFO == _ON)
extern void ScalerColorDCCHistoSetting(void);
#endif // End of #if(_DCC_HISTOGRM_INFO == _ON)

#if((_DCC_FUNCTION == _ON) || (_DCC_HISTOGRM_INFO == _ON))
extern void ScalerColorDCCNormalizeFactorAdjust(void);
#endif // End of #if((_DCC_FUNCTION == _ON) || (_DCC_HISTOGRM_INFO == _ON))

#if(_YPEAKING_SUPPORT == _ON)
extern void ScalerColorYpeaking(bit bOn);
extern void ScalerColorYpeakingAdjust(EnumYpeakingMode enumYPeakMode, BYTE ucGain, EnumYpeakingCoeffResolution enumResolution, BYTE *pAddress, WORD usWriteLength, BYTE ucBankNum);
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
extern void ScalerColorHLWBriConAdjust(EnumBriConHLWType enumHLWActive);

#if(_GAMMA_FUNCTION == _ON)
extern void ScalerColorHLWOutputGammaAdjust(EnumHLWType enumHLWActive);
#endif // End of #if(_GAMMA_FUNCTION == _ON)

#if(_GLOBAL_HUE_SATURATION == _ON)
extern void ScalerColorHLWSRGBAdjust(EnumHLWType enumHLWActive);
#endif // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if((_ICM_SUPPORT == _ON) || (_DCC_FUNCTION == _ON))
extern void ScalerColorHLWICMDCCAdjust(EnumHLWType enumHLWActive);
#endif // End of #if((_ICM_SUPPORT == _ON) || (_DCC_FUNCTION == _ON))

#if(_DCR_SUPPORT == _ON)
extern void ScalerColorHLWDCRAdjust(EnumHLWType enumHLWActive);
#endif // End of #if(_DCR_SUPPORT == _ON)

#if(_YPEAKING_SUPPORT == _ON)
extern void ScalerColorHLWYpeakingAdjust(EnumHLWType enumHLWActive);
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#endif // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

#if(_YPBPR_SUPPORT == _ON)
extern void ScalerColorSetColorimetry(bit bHDTVMode);
#endif // End of #if(_YPBPR_SUPPORT == _ON)

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
extern BYTE ScalerColorGetRGBQuantizationRange(void);
#endif // End of #if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
extern bit ScalerColorGetYCCQuantizationRange(void);
#endif // End of #if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
