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
// ID Code      : RL6297_Series_Color_Interface.h No.0000
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
extern void ScalerColorSpaceConvertLoadTable(void);
extern void ScalerColorSpaceConvert(EnumColorSpace enumColorFormat);

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
extern void ScalerColorSpaceConvertSetRGBLimitRange(bit bEnable);
#endif // End of #if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
extern void ScalerColorSpaceConvertSetYCCFullRange(bit bEnable);
#endif

#if(_VGA_SUPPORT == _ON)
extern void ScalerColorDigitalFilter(bit bOn);
extern void ScalerColorDigitalFilterAdjust(void);

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
extern void ScalerColorDigitalFilterEnhancePhaseAdjust(BYTE *pucBGRGain);
#endif

#endif  // End of #if(_VGA_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON) 
extern bit ScalerColorGetIColorConvertStatus(void);
extern void ScalerColorIDitherOn(BYTE *pDitherTable, BYTE ucBankNum);
extern void ScalerColorIDitherOff(void);
#endif

#if(_D_DITHER_SUPPORT == _ON)
extern void ScalerColorDDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE *pThresholdTable, BYTE ucBankNum);
#endif // End of #if(_D_DITHER_SUPPORT == _ON)

#if(_PCM_FUNCTION == _ON)
extern void ScalerColorPCMAdjust(EnumPCMType enumPCMMode, BYTE *pIGammaTableArray, BYTE *pOGammaTableArray, BYTE *pColorMatrixArray, BYTE ucBankNum);
extern void ScalerColorPCMInputGamma(bit bOn);

#if(_OCC_SUPPORT == _ON)
extern void ScalerColorPCMInputGammaLoadTable(bit bPCMType);
#endif

extern void ScalerColorPCMOutputGammaAdjust(BYTE *pGammaTableArray, BYTE ucBankNum);
extern void ScalerColorPCMSRGBAdjust(BYTE *pColorMatrixArray, BYTE ucBankNum);
#endif  // End of #if(_PCM_FUNCTION == _ON)

#if(_DCR_SUPPORT == _ON)
extern void ScalerColorDCROnOff(bit bOnOff);
extern void ScalerColorDCRThresholdAdjust(BYTE ucThreshold1, BYTE ucThreshold2);
extern DWORD ScalerColorDCRReadResult(EnumDCRAdjOption enumAdjustOption);
#endif

#if(_DCC_HISTOGRM_INFO == _ON)
extern void ScalerColorDCCGetHistoInfo(BYTE *pucReadArray);
#endif // End of #if(_DCC_HISTOGRM_INFO == _ON)

#if(_ICM_SUPPORT == _ON)
extern void ScalerColorICM(bit bOn);
extern void ScalerColorICMLoadTable(BYTE *pICMTable, BYTE ucBankNum, BYTE ucCMSel);
extern void ScalerColorICMAdjust(WORD usAdjustOption);
#endif

#if(_SIX_COLOR_SUPPORT == _ON)
extern void ScalerColorSixColorAdjust(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition); 
extern void ScalerColorSixColorEnable(void);
#endif // End of #if(_SIX_COLOR_SUPPORT == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)
extern void ScalerColorUltraVividOff(void);
extern void ScalerColorUltraVividAdjust(BYTE *pUltraVividSetting1, BYTE *pUltraVividSetting2, BYTE *pUltraVividSetting3, BYTE *pUltraVividSetting4, BYTE *pUltraVividCDSSetting, BYTE ucBankNum);
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
extern void ScalerColorHLW(bit bOn);
extern void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight);
extern void ScalerColorHLWBorderAdjust(BYTE ucBorderEn, BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue);

#if(_ULTRA_VIVID_SUPPORT == _ON)
extern void ScalerColorHLWUltraVividAdjust(EnumHLWType enumHLWActive);
#endif

#endif

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
extern void ScalerColorSpaceConvertDDomainDisable(void);
#endif // End of #if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
