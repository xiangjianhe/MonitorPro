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
// ID Code      : RL6336_Series_Color_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Colorimetry
//--------------------------------------------------
#define _COLORIMETRY_NONE                           0
#define _COLORIMETRY_ITU601                         1
#define _COLORIMETRY_ITU709                         2
#define _COLORIMETRY_EXT                            3
                                                    
#define _COLORIMETRY_XVYCC601                       0    
#define _COLORIMETRY_XVYCC709                       1

//--------------------------------------------------
// Definitions of Colorimetry
//--------------------------------------------------
#define _COLORIMETRY_NONE                           0
#define _COLORIMETRY_ITU601                         1
#define _COLORIMETRY_ITU709                         2
#define _COLORIMETRY_EXT                            3
                                                    
#define _COLORIMETRY_XVYCC601                       0    
#define _COLORIMETRY_XVYCC709                       1

//--------------------------------------------------
// Definitions of Color Depth
//--------------------------------------------------
#define _COLOR_DEPTH_8_BITS                         0
#define _COLOR_DEPTH_10_BITS                        1
#define _COLOR_DEPTH_12_BITS                        2
#define _COLOR_DEPTH_16_BITS                        3


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __RL6336_SERIES_COLOR__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_GLOBAL_HUE_SATURATION == _ON)
extern void ScalerColorSRGBAdjust(BYTE *pSrgbArray);
#endif // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
extern void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight);
extern void ScalerColorHLWBorderAdjust(BYTE ucBorderEn, BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue);
#endif

#if((_DCC_HISTOGRM_INFO == _ON) && (_DCC_HISTOGRAM_THD_CHANGE == _ON))
extern void ScalerColorDCCChangeHistogramThd(); 
#endif

#endif // End of #ifndef __RL6336_SERIES_COLOR__
