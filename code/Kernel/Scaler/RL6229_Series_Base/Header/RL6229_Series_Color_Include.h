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
// ID Code      : RL6229_Series_Color_Include.h No.0000
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

#if(_2D_TO_3D_FUNCTION == _ON)
//--------------------------------------------------
// Marco of 2DTO3D Detecting Flag
//--------------------------------------------------
#define GET_2DTO3D_ENABLE()                         (g_st2DTO3DStatus.b12DTO3DENABLE)
#define SET_2DTO3D_ENABLE()                         (g_st2DTO3DStatus.b12DTO3DENABLE = _ENABLE)
#define CLR_2DTO3D_ENABLE()                         (g_st2DTO3DStatus.b12DTO3DENABLE = _DISABLE) 

#define GET_2DTO3D_DEPTH()                          (g_st2DTO3DStatus.b12DTO3DDEPTH)
#define SET_2DTO3D_DEPTH()                          (g_st2DTO3DStatus.b12DTO3DDEPTH = _ENABLE)
#define CLR_2DTO3D_DEPTH()                          (g_st2DTO3DStatus.b12DTO3DDEPTH = _DISABLE) 

#define GET_2DTO3D_FIRST()                          (BYTE)(g_st2DTO3DStatus.b12DTO3DFIRST)
#define SET_2DTO3D_FIRST()                          (g_st2DTO3DStatus.b12DTO3DFIRST = _ENABLE)
#define CLR_2DTO3D_FIRST()                          (g_st2DTO3DStatus.b12DTO3DFIRST = _DISABLE) 
#endif

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

typedef struct
{
    BYTE b12DTO3DENABLE : 1;    
    BYTE b12DTO3DDEPTH : 1;
    BYTE b12DTO3DFIRST : 1;    
} Struct2DTO3DSTATUS;


#ifndef __RL6229_SERIES_COLOR__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

#if(_2D_TO_3D_FUNCTION == _ON)
extern Struct2DTO3DSTATUS g_st2DTO3DStatus;
#endif

#if(_3D_SUPPORT == _ON)
extern BYTE g_ucP1CA5;
#endif

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

#if((_3D_SUPPORT == _ON) && (_2D_TO_3D_FUNCTION == _ON))
extern void ScalerColorDepthOfFieldAdjust(void);
#endif

#endif // End of #ifndef __RL6229_SERIES_COLOR__
