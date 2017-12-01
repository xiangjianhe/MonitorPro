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
// ID Code      : RL6229_Series_VGIP_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of VGIP IH Capture Start Min Value
//--------------------------------------------------
#define _VGIP_IH_CAPTURE_MIN_VALUE                  12
#define _VGIP_IV_CAPTURE_MIN_VALUE                  4

//--------------------------------------------------
// Definitions of VGIP IV Capture Start Max Value
//--------------------------------------------------
#define _VGIP_IV_CAPTURE_MAX_VALUE                  240

//--------------------------------------------------
// Definitions of VGIP IHDelay Max Value
//--------------------------------------------------
#define _VGIP_IH_DELAY_MAX_VALUE                    511

//--------------------------------------------------
// Definitions of HS Phase Delay Calibration
//--------------------------------------------------
#define _HS_DELAY_DVTOTAL                           (100) // line
#define _HS_DELAY_TARGET_DHFREQ                     (3600) // 0.1KHz
#define _HS_DELAY_DHTOTAL                           ((WORD)(GET_D_CLK_FREQ() * 10 / _HS_DELAY_TARGET_DHFREQ)) // pixel
#define _HS_DELAY_REAL_DHFREQ                       ((WORD)(GET_D_CLK_FREQ() * 10 / _HS_DELAY_DHTOTAL)) // 0.1kHz
#define _HS_DELAY_ICLK_RATE                         (200) // MHz
#define _HS_DELAY_IHTOTAL                           ((DWORD)_HS_DELAY_DHTOTAL * 1000 * _HS_DELAY_ICLK_RATE / GET_D_CLK_FREQ())

#define SET_HS_DELAY_LATCH_EDGE()                   {\
                                                        ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~_BIT3, 0x00);\
                                                    }

#define SAVE_HS_DELAY_SETTING(pucBackup)            {\
                                                        ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_00_DISP_DH_TOTAL_H, 3, pucBackup, _AUTOINC);\
                                                        pucBackup[3] = ScalerGetByte(P1_C6_DCLK_SPREAD_SPECTRUM);\
                                                        pucBackup[4] = ScalerGetByte(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M);\
                                                        pucBackup[5] = ScalerGetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L);\
                                                        pucBackup[6] = ScalerGetByte(P1_C9_EVEN_FIX_LASTLINE_LENGTH_L);\
                                                    }

#define LOAD_HS_DELAY_SETTING(pucBackup)            {\
                                                        ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_00_DISP_DH_TOTAL_H, pucBackup[0]);\
                                                        ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, pucBackup[1]);\
                                                        ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_02_DISP_DHS_END, pucBackup[2]);\
                                                        ScalerSetByte(P1_C6_DCLK_SPREAD_SPECTRUM, pucBackup[3]);\
                                                        ScalerSetBit(P1_C6_DCLK_SPREAD_SPECTRUM, ~_BIT2, _BIT2);\
                                                        ScalerSetByte(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, pucBackup[4]);\
                                                        ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, pucBackup[5]);\
                                                        ScalerSetByte(P1_C9_EVEN_FIX_LASTLINE_LENGTH_L, pucBackup[6]);\
                                                    }

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

enum MeasureFieldDetModeDef
{
    _MEASURE_FIELD_DET_LINE_COUNT = 0,
    _MEASURE_FIELD_DET_VS_POS,
};


#ifndef __RL6229_SERIES_VGIP__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern WORD ScalerVgipGetCaptureVHeight(void);
extern void ScalerVgipInputInitial(BYTE ucSourceType);
extern void ScalerVgipModifyPolarity(BYTE ucSourceType);

#if(_VGA_SUPPORT == _ON)
extern void ScalerVgipModifyVsLatchEdge(bit bWait);
#endif

extern WORD ScalerVgipGetCaptureVStartPosition(void);
extern WORD ScalerVgipGetCaptureVDelay(void);
extern void ScalerVgipSetCaptureVDelay(WORD usIVSDelay);
extern WORD ScalerVgipGetCaptureHStartPosition(void);
extern WORD ScalerVgipGetCaptureHDelay(void);
extern void ScalerVgipSetCaptureHDelay(WORD usIHSDelay);
extern void ScalerVgipDoubleBufferApply(void);
extern void ScalerVgipDoubleBufferEnable(bit bEn);
extern WORD ScalerVgipGetCaptureHStartPosition(void);

#endif // End of #ifndef __RL6229_SERIES_VGIP__
