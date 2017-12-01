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
// ID Code      : ScalerMeasureInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Macro of Sync Measurement Result
//--------------------------------------------------
#define GET_INPUT_TIMING_H_POLARITY()                (g_stInputTimingData.b1HSP)
#define GET_INPUT_TIMING_V_POLARITY()                (g_stInputTimingData.b1VSP)
#define GET_INPUT_TIMING_INTERLACE_FLG()             (g_stInputTimingData.b1Interlace)
#define GET_INPUT_TIMING_HFREQ()                     (g_stInputTimingData.usHFreq)
#define GET_INPUT_TIMING_HTOTAL()                    (g_stInputTimingData.usHTotal)
#define GET_INPUT_TIMING_HWIDTH()                    (g_stInputTimingData.usHWidth)
#define GET_INPUT_TIMING_HSTART()                    (g_stInputTimingData.usHStart)
#define GET_INPUT_TIMING_HSYNCWIDTH()                (g_stInputTimingData.usHSWidth)
#define GET_INPUT_TIMING_VFREQ()                     (g_stInputTimingData.usVFreq)
#define GET_INPUT_TIMING_VTOTAL()                    (g_stInputTimingData.usVTotal)
#define GET_INPUT_TIMING_VHEIGHT()                   (g_stInputTimingData.usVHeight)
#define GET_INPUT_TIMING_VSTART()                    (g_stInputTimingData.usVStart)
#define GET_INPUT_TIMING_VSYNCWIDTH()                (g_stInputTimingData.usVSWidth)

//--------------------------------------------------
// Macro of Sync Measurement Result
//--------------------------------------------------
#define GET_SYNC_H_POLARITY()                        (g_stMeasureSyncHV.b1HSP)
#define GET_SYNC_V_POLARITY()                        (g_stMeasureSyncHV.b1VSP)
#define GET_SYNC_H_PERIOD()                          (g_stMeasureSyncHV.usHSPeriod)
#define GET_SYNC_H_SYNCWIDTH()                       (g_stMeasureSyncHV.usHSWidth)
#define GET_SYNC_V_PERIOD()                          (g_stMeasureSyncHV.usVSPeriod)
#define GET_SYNC_V_SYNCWIDTH()                       (g_stMeasureSyncHV.usVSWidth)

//--------------------------------------------------
// Macro of Active Measurement Result
//--------------------------------------------------
// For Compiler, Delete later
#define GET_ACTIVE_V_START()                         (g_stActiveRegion.usVActiveStart)
#define GET_ACTIVE_V_END()                           (g_stActiveRegion.usVActiveEnd)
#define GET_ACTIVE_H_START()                         (g_stActiveRegion.usHActiveStart)
#define GET_ACTIVE_H_END()                           (g_stActiveRegion.usHActiveEnd)
#define GET_ACTIVE_H_WIDTH()                         ((g_stActiveRegion.usHActiveEnd - g_stActiveRegion.usHActiveStart) + 1)
#define GET_ACTIVE_V_HEIGHT()                        ((g_stActiveRegion.usVActiveEnd - g_stActiveRegion.usVActiveStart) + 1)

//--------------------------------------------------
// Macro of input timing infor. modification
//--------------------------------------------------
#define SET_INPUT_TIMING_HSTART(x)                   (g_stInputTimingData.usHStart = (x))
#define SET_INPUT_TIMING_HWIDTH(x)                   (g_stInputTimingData.usHWidth = (x))
#define SET_INPUT_TIMING_HTOTAL(x)                   (g_stInputTimingData.usHTotal = (x))

#define SET_INPUT_TIMING_VSTART(x)                   (g_stInputTimingData.usVStart = (x))
#define SET_INPUT_TIMING_VHEIGHT(x)                  (g_stInputTimingData.usVHeight = (x))
#define SET_INPUT_TIMING_VTOTAL(x)                   (g_stInputTimingData.usVTotal = (x))

//--------------------------------------------------
// Macro of input timing info Double Check
//--------------------------------------------------
#define GET_INPUT_TIMING_DOUBLE_CHECK()              (g_bInputTimingDoubleCheck)
#define SET_INPUT_TIMING_DOUBLE_CHECK()              (g_bInputTimingDoubleCheck = _TRUE)
#define CLR_INPUT_TIMING_DOUBLE_CHECK()              (g_bInputTimingDoubleCheck = _FALSE)


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __SCALER_MEASURE__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

extern StructAutoActiveData data g_stActiveRegion;
extern StructMeasureSyncData idata g_stMeasureSyncHV;
extern StructTimingInfo data g_stInputTimingData;

extern DWORD g_ulActiveRegionBackUp;
extern bit g_bInputTimingDoubleCheck;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern bit ScalerMeasureInputInfo(BYTE ucSourceType);
extern bit ScalerMeasureInputHV(EnumSyncMeasureAnalogDigitalSel enumMeasureType);

#if(_VGA_SUPPORT == _ON)
extern bit ScalerMeasureActiveRegion(EnumMeasureModeType enumMeasureType, EnumMeasureFieldSelect enumFieldSelect, EnumMeasureBoundType enumBoundType, WORD usHTotal);
#endif

extern bit ScalerMeasureTimingChange(BYTE ucSourceType);
extern bit ScalerMeasureActiveRegionChange(void);

extern void ScalerMeasureSetMeasure(EnumSyncMeasureAnalogDigitalSel enumMeasureType);
extern bit ScalerMeasureGetMeasureResult(StructMeasureSyncData *stMeasureSyncHV);
extern void ScalerMeasureSetRegionCount(bit bTarget, EnumActiveRegionType enumRegion);
extern DWORD ScalerMeasureGetRegionCountResult(bit bWait);
extern void ScalerMeasureSetAuto(EnumMeasureModeType enumMeasureType, EnumMeasureFieldSelect enumFieldSelect, EnumMeasureBoundType enumBoundType, WORD usHTotal);
extern bit ScalerMeasureGetAutoResult(StructAutoActiveData *stActiveRegion, bit bWait);

extern bit ScalerMeasureAutoFuncWaitFinish(void);
extern void ScalerMeasureAutoFuncHBoundInitial(WORD usHBoundStart, WORD usHBoundEnd);
extern void ScalerMeasureAutoFuncVBoundInitial(WORD usVBoundStart, WORD usVBoundEnd);

#if(_VGA_SUPPORT == _ON)
extern bit ScalerMeasureHWAutoPhaseSearch(EnumAutoPhaseSearchStep enumPhaseStep, BYTE *ucPhaseResult, DWORD *ulSODMax, DWORD *ulSODMin, EnumAutoPhaseSearchSODMethod enumSODMethod, BYTE ucSODThreshold);
extern bit ScalerMeasureAutoPhaseGetSOD(DWORD * ulSODValue);
#endif

#endif // End of #ifndef __SCALER_MEASURE__
