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
// ID Code      : ScalerMDomainInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_INTERLACED_MODE()                        (g_stMDomainInputData.b1Interlace)

#define GET_H_SCALE_UP()                             (g_stMDomainInfo.b1HSU)
#define SET_H_SCALE_UP()                             (g_stMDomainInfo.b1HSU = _TRUE)
#define CLR_H_SCALE_UP()                             (g_stMDomainInfo.b1HSU = _FALSE)

#define GET_H_SCALE_DOWN()                           (g_stMDomainInfo.b1HSD)
#define SET_H_SCALE_DOWN()                           (g_stMDomainInfo.b1HSD = _TRUE)
#define CLR_H_SCALE_DOWN()                           (g_stMDomainInfo.b1HSD = _FALSE)

#define GET_V_SCALE_UP()                             (g_stMDomainInfo.b1VSU)
#define SET_V_SCALE_UP()                             (g_stMDomainInfo.b1VSU = _TRUE)
#define CLR_V_SCALE_UP()                             (g_stMDomainInfo.b1VSU = _FALSE)

#define GET_V_SCALE_DOWN()                           (g_stMDomainInfo.b1VSD)
#define SET_V_SCALE_DOWN()                           (g_stMDomainInfo.b1VSD = _TRUE)
#define CLR_V_SCALE_DOWN()                           (g_stMDomainInfo.b1VSD = _FALSE)

#if(_3D_SUPPORT == _ON)
#define GET_H_SCALE_DOWN_2_DIFF_PHASE()              (g_stMDomainInfo.b1HSD2DiffPhase)
#define SET_H_SCALE_DOWN_2_DIFF_PHASE()              (g_stMDomainInfo.b1HSD2DiffPhase = _TRUE)
#define CLR_H_SCALE_DOWN_2_DIFF_PHASE()              (g_stMDomainInfo.b1HSD2DiffPhase = _FALSE)

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
#define GET_V_SCALE_DOWN_2_DIFF_PHASE()              (g_stMDomainInfo.b1VSD2DiffPhase)
#define SET_V_SCALE_DOWN_2_DIFF_PHASE()              (g_stMDomainInfo.b1VSD2DiffPhase = _TRUE)
#define CLR_V_SCALE_DOWN_2_DIFF_PHASE()              (g_stMDomainInfo.b1VSD2DiffPhase = _FALSE)
#endif
#endif

#define GET_MEMORY_SELECT()                          (g_stMDomainInfo.b3MemorySelect)
#define SET_MEMORY_SELECT(x)                         (g_stMDomainInfo.b3MemorySelect = (x))
#define CLR_MEMORY_SELECT()                          (g_stMDomainInfo.b3MemorySelect = 0)

#if((_OD_SUPPORT == _ON) || (_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
#define GET_MEMORY_DVF_SELECT()                      (g_stMDomainInfo.b3DVFSelect)
#define SET_MEMORY_DVF_SELECT(x)                     (g_stMDomainInfo.b3DVFSelect = (x))
#define CLR_MEMORY_DVF_SELECT()                      (g_stMDomainInfo.b3DVFSelect = 0)
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

#define GET_MEMORY_CONFIG()                          (g_stMDomainInfo.b2MemoryConf)
#define SET_MEMORY_CONFIG(x)                         (g_stMDomainInfo.b2MemoryConf = (x))
#define CLR_MEMORY_CONFIG()                          (g_stMDomainInfo.b2MemoryConf = 0)

#if(_OD_SUPPORT == _ON)
#define GET_OD_USE_BIT()                             (g_ucMemoryODUseBit)
#define SET_OD_USE_BIT(x)                            (g_ucMemoryODUseBit = (x))
#define CLR_OD_USE_BIT()                             (g_ucMemoryODUseBit = 0)

#define GET_OD_USE_SPACE()                           (g_usMemoryODUseSpace)
#define SET_OD_USE_SPACE(x)                          (g_usMemoryODUseSpace = (x))
#define CLR_OD_USE_SPACE()                           (g_usMemoryODUseSpace = 0)

#define GET_OD_USE_BW()                              (g_usMemoryODUseBW)
#define SET_OD_USE_BW(x)                             (g_usMemoryODUseBW = (x))
#define CLR_OD_USE_BW()                              (g_usMemoryODUseBW = 0)
#endif


#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
#define GET_ASPECT_ORIGIN_MODE()                     (g_bAspectOriginMode)
#define SET_ASPECT_ORIGIN_MODE(x)                    (g_bAspectOriginMode = (x))
#endif

#define GET_D_CLK_FREQ()                             (g_ulDClkFreq)
#define SET_D_CLK_FREQ(x)                            (g_ulDClkFreq = (x))

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

typedef struct
{
    BYTE b3MemorySelect : 3;

#if((_OD_SUPPORT == _ON) || (_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))    
    BYTE b3DVFSelect : 3;
#endif

    BYTE b2MemoryConf : 2;    
    BYTE b1HSU : 1;
    BYTE b1HSD : 1;
    BYTE b1VSU : 1;
    BYTE b1VSD : 1;
    
#if(_3D_SUPPORT == _ON)
    BYTE b1HSD2DiffPhase : 1;

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
    BYTE b1VSD2DiffPhase : 1;
#endif
#endif
    
} StructMDomainInfo;
          

#ifndef __SCALER_MDOMAIN__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
extern bit idata g_bAspectOriginMode;
#endif

#if(_OD_SUPPORT == _ON)
extern BYTE idata g_ucMemoryODUseBit;
extern WORD idata g_usMemoryODUseSpace;
extern WORD idata g_usMemoryODUseBW;
#endif

#if((_OD_SUPPORT == _ON) || (_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
extern bit g_bDoubleFrame;
extern WORD idata g_usDVFreq;
#endif

extern DWORD idata g_ulDClkFreq;

extern StructMDomainInfo idata g_stMDomainInfo;
extern StructTimingInfo data g_stMDomainInputData;
extern StructDisplayInfo data g_stMDomainOutputData;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_ADC_SELF_CALIBRATION == _ON)
extern void ScalerMDomainSetDisplayFormat(BYTE ucMemorySel);
#endif

#endif // End of #ifndef __SCALER_MDOMAIN__
