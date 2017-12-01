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
// ID Code      : ScalerColorInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _GAMMA_WRITE_TO_SRAM                        0
#define _GAMMA_WRITE_TO_LATCH                       1

//--------------------------------------------------
// Macro of Color Space
//--------------------------------------------------
#define GET_COLOR_SPACE()                           (g_ucColorInfo & (_BIT0 | _BIT1))
#define SET_COLOR_SPACE(x)                          (g_ucColorInfo = (g_ucColorInfo & ~(_BIT0 | _BIT1)) | (x))
#define CLR_COLOR_SPACE()                           (g_ucColorInfo &= ~(_BIT0 | _BIT1))

//--------------------------------------------------
// Macro of Colorimetry Data
//--------------------------------------------------
#define GET_COLORIMETRY()                           ((g_ucColorInfo & (_BIT2 | _BIT3)) >> 2)
#define SET_COLORIMETRY(x)                          (g_ucColorInfo = (g_ucColorInfo & ~(_BIT2 | _BIT3)) | ((x) << 2))
#define CLR_COLORIMETRY()                           (g_ucColorInfo &= ~(_BIT2 | _BIT3))

//--------------------------------------------------
// Macro of Extended Colorimetry
//--------------------------------------------------
#define GET_EXT_COLORIMETRY()                       ((g_ucColorInfo & _BIT4) >> 4)
#define SET_EXT_COLORIMETRY(x)                      (g_ucColorInfo = (g_ucColorInfo & ~_BIT4) | ((x) << 4))
#define CLR_EXT_COLORIMETRY()                       (g_ucColorInfo &= ~_BIT4)

//--------------------------------------------------
// Macro of Color Depth
//--------------------------------------------------
#define GET_COLOR_DEPTH()                           ((g_ucColorInfo & (_BIT5 | _BIT6)) >> 5)
#define SET_COLOR_DEPTH(x)                          (g_ucColorInfo = (g_ucColorInfo & ~(_BIT5 | _BIT6)) | ((x) << 5))
#define CLR_COLOR_DEPTH()                           (g_ucColorInfo &= ~(_BIT5 | _BIT6))

//--------------------------------------------------
// Macro of RGB Quantization Range
//--------------------------------------------------
#define GET_COLOR_RGB_QUANTIZATION_RANGE()          (g_ucColorInfo2 & (_BIT0 | _BIT1))
#define SET_COLOR_RGB_QUANTIZATION_RANGE(x)         (g_ucColorInfo2 = (g_ucColorInfo2 & ~(_BIT0 | _BIT1)) | (x))
#define CLR_COLOR_RGB_QUANTIZATION_RANGE()          (g_ucColorInfo2 &= ~(_BIT0 | _BIT1))

//--------------------------------------------------
// Macro of RGB Limit Range User
//--------------------------------------------------
#define GET_COLOR_RGB_LIMIT_RANGE_USER()            ((g_ucColorInfo2 & _BIT2) >> 2)
#define SET_COLOR_RGB_LIMIT_RANGE_USER(x)           (g_ucColorInfo2 = (g_ucColorInfo2 & ~_BIT2) | ((x) << 2))

//--------------------------------------------------
// Macro of YCC Quantization Range
//--------------------------------------------------
#define GET_COLOR_YCC_QUANTIZATION_RANGE()          ((g_ucColorInfo2 & _BIT4) >> 4)
#define SET_COLOR_YCC_QUANTIZATION_RANGE(x)         (g_ucColorInfo2 = (g_ucColorInfo2 & ~_BIT4) | ((x) << 4))

//--------------------------------------------------
// Macro of YCC Full Range User
//--------------------------------------------------
#define GET_COLOR_YCC_FULL_RANGE_USER()             ((g_ucColorInfo2 & _BIT3) >> 3)
#define SET_COLOR_YCC_FULL_RANGE_USER(x)            (g_ucColorInfo2 = (g_ucColorInfo2 & ~_BIT3) | ((x) << 3))

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

#ifndef __SCALER_COLOR__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

extern BYTE idata g_ucColorInfo;
extern BYTE idata g_ucColorInfo2;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if((_GAMMA_FUNCTION == _ON) || (_PCM_FUNCTION == _ON))
extern void ScalerColorOutputGammaChannelCtrl(BYTE ucColorChannel, BYTE ucOffset, bit bLocation);
#endif

#endif // End of #ifndef __SCALER_COLOR__
