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
// ID Code      : RL6373_Series_SyncProc_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Sync Processor Clock Frequency
//--------------------------------------------------
#define _SYNC_PRO_CLK_DIV                           (ScalerGetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_0A_DEVS_CAP_NUM_H, 0xF0) >> 4) // Sync Pro Clock Divider   
#define _SYNC_PRO_USE_M2PLL_CLK                     ((bit)ScalerGetBit(CM_4C_VSYNC_COUNTER_LEVEL_MSB, _BIT3) ? _TRUE : _FALSE)    
#define _SYNC_PROC_CLK                              (DWORD)((bit)ScalerGetBit(P1_E5_M2PLL_WD, _BIT0) ? _EXT_XTAL : (_SYNC_PRO_USE_M2PLL_CLK ? (((DWORD)1000 * _M2PLL_CLK_MHZ ) / _SYNC_PRO_CLK_DIV) : _EXT_XTAL))

//--------------------------------------------------
// Definitions of Debounce Width And High Pulse Width Counter
//--------------------------------------------------
#define _MIN_SYNC_HIGHPULSE_WIDTH                   173 // Unit ns, Represent the shortest high pulse width
#define _MIN_SYNC_HIGHPULSE_CNT                     (((WORD)((DWORD)_MIN_SYNC_HIGHPULSE_WIDTH * _SYNC_PROC_CLK / 1000000)) & 0x7FF)
#define _MIN_SYNC_HIGHPULSE_CNT_PS                  (((WORD)((DWORD)_MIN_SYNC_HIGHPULSE_WIDTH * _INTERNAL_OSC_XTAL / (0x01 << _IOSC_DIV) / 1000000)) & 0x7FF)
                                                    
//--------------------------------------------------
// Definitions Of Capture window initial width tolerance
//--------------------------------------------------
#define _CAP_WINDOW_WIDTH_DEFAULT                   (0x08) // Unit: syncprocessor clock
#define _CAP_WINDOW_WIDTH_TOR                       2 // Unit: syncprocessor clock

//--------------------------------------------------
// Definitions Of Analog Measure Tolerance
//--------------------------------------------------
#define _ANALOG_MEASURE_HS_TOR                      (2 + (GET_SYNC_H_PERIOD() >> 5)) // Unit: syncprocessor clock

//--------------------------------------------------
// Definitions Of Sync Processor Auto Run Polling Time, Target 120ms
// Auto Run Typer Time Out Base Counter(0x200000) Reference 27M Crystal About 80ms:                                                                            //
// 120 = 80 + 40(Tolerance), _XTAL27000K / _MCU_XTAL Is Linear Operator
//--------------------------------------------------
#define _AUTO_RUN_POLLING_TIME                      ((WORD)((DWORD)120 * _XTAL27000K / _SYNC_PROC_CLK))

//--------------------------------------------------
// Definitions Of Sync Measure Polling Time
// Unit: ms (512 * Time Clk) + 10(tolerance)
// Time Clk = 1/SYNC_CLK * 4096
//--------------------------------------------------
#define _MEASURE_TIMEOUT                            (WORD)(((DWORD)4096 * 512) / _SYNC_PROC_CLK) + 10

//--------------------------------------------------
// Definitions Of Active Measure Target
//--------------------------------------------------
#define _MEASURE_TARGET_INPUT                       0
#define _MEASURE_TARGET_DISPLAY                     1

//--------------------------------------------------
// Definitions Of VGA noise margin
//--------------------------------------------------
#define _VGA_NOISE_MARGIN                           0x40

//--------------------------------------------------
// Definitions Of Signal Detected Pad Flag In Sleep Mode
//--------------------------------------------------
#define _HSYNC_DETECTED_FLG                         _BIT7
#define _SOG_DETECTED_FLG                           _BIT6
#define _VS_DETECTED_FLG                            _BIT5
                                                    
//--------------------------------------------------
// Definitions Of Signal Detected Pad Flag In Sleep Mode
//--------------------------------------------------
#define _HS_OVERFLOW                                _BIT0
#define _HS_NOTSTABLE                               _BIT1
#define _HS_NOVS                                    _BIT2
#define _HS_VS_ERROR                                _BIT3
#define _HS_STABLE_HIGHPERIOD_ERROR                 _BIT4
#define _VS_HIGHPERIOD_ERROR                        _BIT5
                                                    
#define _UNKNOWN_ERROR                              _BIT7

//--------------------------------------------------
// Noise width definitions
//--------------------------------------------------
#define _NOISE_WIDTH_AFTER_HSYNC                    0x3C
#define _NOISE_WIDTH_AFTER_VSYNC                    0x01

//--------------------------------------------------
// Noise Delay before hs definitions, Unit: ns
//--------------------------------------------------
#define _NOISE_DELAY_BEFORE_HSYNC_POSITIVE          80 // Unit: ns
#define _NOISE_DELAY_BEFORE_HSYNC_NEGTIVE           100 // Unit: ns

//--------------------------------------------------
// Phas delay
//--------------------------------------------------
#define _PHASE_DELAY_TIME_VALUE                     390 // 296 = 64 * 4.63 (Unit: ns)         
#define _PHASE_DELAY_HALF_PERIOD_SHIFT              ((ScalerGetBit(P0_BB_ADC_2X_SAMPLE, _BIT5) == _BIT5) ? 32 : 0)


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

enum MeasureSourceDef
{
    _MEASURE_TMDS = 0,
    _MEASURE_VIDEO8,
    _MEASURE_ADC,
    _MEASURE_CS_RAW,
};

enum MeasureActiveRegionDef
{
    _MEASURE_ACT_REGION_INPUT = 0,
    _MEASURE_ACT_REGION_DISPLAY,
};

enum MeasureTimeClockDef
{
    _MEASURE_TIME_CLK_2048 = 0,
    _MEASURE_TIME_CLK_4096,
};

enum MeasureHSyncMaxDeltaDef
{
    _MEASURE_HSYNC_MAX_DELTA_DONT_CARE = 0,
    _MEASURE_HSYNC_MAX_DELTA_4_CLK,
    _MEASURE_HSYNC_MAX_DELTA_8_CLK,    
    _MEASURE_HSYNC_MAX_DELTA_16_CLK,    
};

enum MeasureVSyncMaxDeltaDef
{
    _MEASURE_VSYNC_MAX_DELTA_DONT_CARE = 0,
    _MEASURE_VSYNC_MAX_DELTA_2_HSYNC,
    _MEASURE_VSYNC_MAX_DELTA_4_HSYNC,    
    _MEASURE_VSYNC_MAX_DELTA_8_HSYNC,    
};

#ifndef __RL6373_SERIES_SYNCPROC__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
extern void ScalerSyncProcClampPosSetting(WORD usClampPosStart, WORD usClampPosEnd);
extern WORD ScalerSyncProcGetClampEndPosition(void);
extern WORD ScalerSyncProcMeasureIHFreqByStableMeasure(void);
extern void ScalerSyncProcPulseDetectEnable(BYTE ucEnable);
extern void ScalerSyncProcSetDebounce(BYTE ucDebounce);

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
extern bit ScalerSyncProcCheckPorchChange(void);
#endif

extern void ScalerSyncProcDownCounterSetting(void);
#endif // End of #if(_VGA_SUPPORT == _ON)

#endif // End of #ifndef __RL6373_SERIES_SYNCPROC__
