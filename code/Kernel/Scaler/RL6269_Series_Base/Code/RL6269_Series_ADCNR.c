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
// ID Code      : RL6269_Series_ADCNR.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6269_SERIES_NOISE_REDUCTION__

#include "ScalerFunctionInclude.h"

#if((_VGA_SUPPORT == _ON) && (_ADCNR_BY_HISTOGRAM_SUPPORT == _ON))
//****************************************************************************
// DEFINITIONS / MACROS
//***************************************************************************

//--------------------------------------------------
// Definitions of NR pattern detect parameters
//--------------------------------------------------
#define _NR_TOLERANCE_PATTERN_BOUNCE                (3) // Timeout for ID detect
#define _NR_TOLERANCE_A_ERROR                       (4) // 0 ~ 7
#define _NR_TOLERANCE_STEP_ERROR                    (3) // 0 ~ 7
#define _NR_MAX_PQ_DETECT_AREA                      (16384) 
#define _NR_SCORING_THRESHOLD_FOR_LEVELED           (205) // 80%
#define _NR_MIN_COVERAGE_FOR_MONO                   (0.92 * _NR_MAX_PQ_DETECT_AREA) 
#define _NR_MIN_COVERAGE_FOR_LEVELED                (ScalerGetWord(P1E_C2_FUNC2_CTRL2) + (WORD)_NR_MAX_PQ_DETECT_AREA)
#define _NR_MIN_SUBTONE_DIFFERENCE                  (0.03 * _NR_MAX_PQ_DETECT_AREA)
#define _NR_MAX_MONO_PATTERN_VALUE                  (62) // 0 ~ 63

//--------------------------------------------------
// Definitions of NR macros
//--------------------------------------------------
#define SET_NR_PATTERN(x)                           (g_stNrData.ucNrID = (x))
#define GET_NR_PATTERN()                            (g_stNrData.ucNrID)
#define SET_NR_PATTERN_SAVED(x)                     (g_stNrData.ucNrMemory[0] = (x))
#define GET_NR_PATTERN_SAVED()                      (g_stNrData.ucNrMemory[0])
#define SET_NR_PATTERN_NOW(x)                       (g_stNrData.ucNrMemory[1] = (x))
#define GET_NR_PATTERN_NOW()                        (g_stNrData.ucNrMemory[1])
#define GET_NR_PATTERN_IS_MONO()                    (GET_NR_PATTERN() < 64)
#define GET_NR_PATTERN_IS_LEVELED()                 ((GET_NR_PATTERN() >= 64) && (GET_NR_PATTERN() != _NR_PATTERN_NONE))
#define GET_NR_PATTERN_IS_GRAY()                    (ScalerGetBit(P1E_B1_FUNC1_RESULT1, _BIT2) == _BIT2)
#define GET_NR_PATTERN_DIRECTION()                  ((GET_NR_PATTERN() & 0x18) >> 3)
#define GET_NR_PATTERN_LEVEL()                      ((GET_NR_PATTERN() & 0xE0) >> 5)
#define GET_NR_FLAG(x)                              ((g_stNrData.ucNrStatus & (x)) == (x))
#define SET_NR_FLAG(x)                              (g_stNrData.ucNrStatus |= (x))
#define CLR_NR_FLAG(x)                              (g_stNrData.ucNrStatus &= ~(x))
#define SET_NR_STATE(x)                             (g_stNrData.ucNrStatus = ((x) | (g_stNrData.ucNrStatus & (0x3F & ~_NR_FLAG_INITIALIZED)))) // Clear _NR_FLAG_INITIALIZED at the same time
#define GET_NR_STATE()                              (g_stNrData.ucNrStatus & 0xC0)
#define GET_NR_TONE(x)                              (ScalerGetWord(P1E_C7_TONE1_NUM_H + (((x) % 4) << 1)))
#define GET_NR_PREVIOUS_TONE(x)                     (((x) == 0) ? 0 : GET_NR_TONE((x) - 1))
#define GET_NR_NEXT_TONE(x)                         (((x) == 3) ? 0 : GET_NR_TONE((x) + 1))
#define GET_NR_ONE_FRAME_MS()                       ((WORD)625 / (BYTE)(GET_INPUT_TIMING_VFREQ() >> 4))
#define GET_NR_COUNTER()                            (g_stNrData.ucNrStatus & 0x03)
#define SET_NR_COUNTER(x)                           (g_stNrData.ucNrStatus = ((g_stNrData.ucNrStatus & 0xFC) | ((x) & 0x03)))
#define CLR_NR_COUNTER()                            (g_stNrData.ucNrStatus &= ~0x03)
#define INC_NR_COUNTER()                            (g_stNrData.ucNrStatus = ((GET_NR_COUNTER() == 3) ? g_stNrData.ucNrStatus : (g_stNrData.ucNrStatus + 1)))
#define DEC_NR_COUNTER()                            (g_stNrData.ucNrStatus = ((GET_NR_COUNTER() == 0) ? g_stNrData.ucNrStatus : (g_stNrData.ucNrStatus - 1)))
#define LOAD_NR_MIN_TONE()                          (ScalerSetBit(P1E_C4_FUNC2_CTRL4, ~(0x7F), ((ScalerGetByte(P1E_B3_MONO_REF_VALUE) <= 2) ? 0 : (ScalerGetByte(P1E_B3_MONO_REF_VALUE) - 2))))
#define GET_NR_LSB(chn)                             (g_stNrData.ucNrMemory[chn] & 0x03)
#define SET_NR_LSB(x, chn)                          (g_stNrData.ucNrMemory[chn] = ((g_stNrData.ucNrMemory[chn] & 0xFC) | ((x) & 0x03)))
#define GET_NR_SCORE(chn)                           (g_stNrData.ucNrMemory[chn] >> 2)
#define SET_NR_SCORE(x, chn)                        (g_stNrData.ucNrMemory[chn] = (((x) << 2) | (g_stNrData.ucNrMemory[chn] & 0x03)))
#define SET_NR_FINISHED(chn)                        (g_stNrData.ucNrMemory[chn] = 0xFF)
#define GET_NR_FINISHED(chn)                        (g_stNrData.ucNrMemory[chn] == 0xFF)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//--------------------------------------------------
// Definitions of NR direction ID
//--------------------------------------------------
typedef enum
{
    _NR_PATTERN_DOWN = 0x00,
    _NR_PATTERN_UP = 0X01,
    _NR_PATTERN_RIGHT = 0x02,
    _NR_PATTERN_LEFT = 0x03,
}EnumNrPatternDirections;

//--------------------------------------------------
// Definitions of NR level ID
//--------------------------------------------------
typedef enum
{
    _NR_PATTERN_8_LEVEL = 0x03,
    _NR_PATTERN_16_LEVEL = 0x04,
    _NR_PATTERN_32_LEVEL = 0x05,
    _NR_PATTERN_64_LEVEL = 0x06,
    _NR_PATTERN_NONE = 0xFE,
}EnumNrPatternLevels;

//--------------------------------------------------
// Definitions of NR algorithm states
//--------------------------------------------------
typedef enum
{
    _NR_STATE_GRAY_DETECT = 0x00,
    _NR_STATE_PATTERN_DETECT = 0x40,
    _NR_STATE_OFFSET_ADJUST = 0x80,
    _NR_STATE_MONITOR = 0xC0,
}EnumNrDetectState;

//--------------------------------------------------
// Definitions of NR algorithm flags
//--------------------------------------------------
typedef enum
{
    _NR_FLAG_INITIALIZED = _BIT2,
    _NR_FLAG_DONE_TIMER_EVENT = _BIT3,
    _NR_FLAG_VARYING_PATTERN = _BIT4,
}EnumNrFlagType;

//--------------------------------------------------
// Definitions of NR channels
//--------------------------------------------------
typedef enum
{
    _NR_R_CHANNEL = 0x00,
    _NR_G_CHANNEL = 0x01,
    _NR_B_CHANNEL = 0x02,
}EnumNrChannelId;

//--------------------------------------------------
// Definitions of NR LSB search results
//--------------------------------------------------
typedef enum
{
    _NR_RESULT_STOP_CHANNEL = 0x00,
    _NR_RESULT_STOP_ALL,
    _NR_RESULT_KEEP_SEARCHING,       // Johnny searcher
}EnumNrSearchResultStatus;

//--------------------------------------------------
// Definitions of NR global variables
//--------------------------------------------------
typedef struct
{
    BYTE ucNrStatus;                 // [7:6]: NR state; [5:2]: NR flag; [1:0]: NR counter
    BYTE ucNrID;                     // Detected pattern ID
    BYTE ucNrMemory[3];              // Memory space for NR
}StructNrInfo;

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructNrInfo g_stNrData = {0};

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerNrTimerEvent(void);
void ScalerNrInitial(void);
void ScalerNrGrayDetectInitial(void);
void ScalerNrGrayDetect(void);
void ScalerNrPatternDetectInitial(void);
void ScalerNrPatternDetect(void);
void ScalerNrOffsetAdjustInitial(void);
bit ScalerNrOffsetAdjust(void);
EnumNrSearchResultStatus ScalerNrPresearchCheck(BYTE *pucResult);
EnumNrSearchResultStatus ScalerNrSearchLsb(BYTE ucChannel);
void ScalerNrShiftCrosshair(void);
void ScalerNrSetBoundaryStart(WORD usHStart, WORD usVStart);
void ScalerNrSetBoundaryLength(WORD usHWidth, WORD usVHeight);
BYTE ScalerNrFindNextChannel(EnumNrChannelId enumCurrentChannel);

#if(_ADCNR_LEVELED_PATTERN_SUPPORT == _ON)
BYTE ScalerNrDetectLeveledPattern(void);
void ScalerNrSetLeveledBoundary(BYTE ucLevels);
void ScalerNrSetLeveledShiftStep(BYTE ucLevels);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Timer event handler function for NR.
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerNrTimerEvent(void)
{
    SET_NR_FLAG(_NR_FLAG_DONE_TIMER_EVENT);
}

//--------------------------------------------------
// Description  : Initial function for NR in first-time process
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerNrInitial(void)
{
    // Default in "gray detect" state; Clear timer flag
    SET_NR_STATE(_NR_STATE_GRAY_DETECT);
    CLR_NR_FLAG(_NR_FLAG_DONE_TIMER_EVENT);
}

//--------------------------------------------------
// Description  : Initial function for gray detect
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerNrGrayDetectInitial(void)
{
    // Stop histogram measure; Start gray detect
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~(_BIT3 | _BIT2 | _BIT1), _BIT2);

    // RGB-delta = 7; A-delta = _NR_TOLERANCE_A_ERROR
    ScalerSetByte(P1E_AD_FUNC1_CTRL1, ((7 << 3) | _NR_TOLERANCE_A_ERROR));

    // Reference value from first 4 pixels; Load default Step-delta; Step-inside-delta = 4;
    ScalerSetByte(P1E_AE_FUNC1_CTRL2, (_BIT6 | (_NR_TOLERANCE_STEP_ERROR << 3) | 5));

    // Group threshold = 2; A threshold = 7;
    ScalerSetByte(P1E_AF_FUNC1_CTRL3, ((2 << 3) | 7));

    // RGB over counter = 255;
    ScalerSetByte(P1E_B0_FUNC1_CTRL4, 0xFF);

#if(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_HALF)
    // Set gray detect boundary: start = 1/16, length = 3/8
    ScalerNrSetBoundaryStart(((GET_INPUT_TIMING_HWIDTH() >> 3) - 1), ((GET_INPUT_TIMING_VHEIGHT() >> 4) - 1));
    ScalerSetWord(P1E_A2_HIST_BON_HEIGHT_H, ((GET_INPUT_TIMING_VHEIGHT() >> 1) - (GET_INPUT_TIMING_VHEIGHT() >> 3) + 2));

#elif(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_UPPER_QUARTER)
    // Set gray detect boundary: start = 1/32, length = 3/16
    ScalerNrSetBoundaryStart(((GET_INPUT_TIMING_HWIDTH() >> 3) - 1), ((GET_INPUT_TIMING_VHEIGHT() >> 5) - 1));
    ScalerSetWord(P1E_A2_HIST_BON_HEIGHT_H, ((GET_INPUT_TIMING_VHEIGHT() >> 2) - (GET_INPUT_TIMING_VHEIGHT() >> 4) + 2));

#elif(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_LOWER_QUARTER)
    // Set gray detect boundary: start = 25/32, length = 3/16
    ScalerNrSetBoundaryStart(((GET_INPUT_TIMING_HWIDTH() >> 3) - 1),
                             ((GET_INPUT_TIMING_VHEIGHT() - (GET_INPUT_TIMING_VHEIGHT() >> 2)) + (GET_INPUT_TIMING_VHEIGHT() >> 5) - 1));
    ScalerSetWord(P1E_A2_HIST_BON_HEIGHT_H, ((GET_INPUT_TIMING_VHEIGHT() >> 2) - (GET_INPUT_TIMING_VHEIGHT() >> 4) + 2));

#else
    // Set gray detect boundary: start = 1/8, length = 3/4
    ScalerNrSetBoundaryStart(((GET_INPUT_TIMING_HWIDTH() >> 3) - 1), ((GET_INPUT_TIMING_VHEIGHT() >> 3) - 1));
    ScalerSetWord(P1E_A2_HIST_BON_HEIGHT_H, (GET_INPUT_TIMING_VHEIGHT() - (GET_INPUT_TIMING_VHEIGHT() >> 2) + 2));
#endif

    // Set gray detect H width = 3/4
    ScalerSetWord(P1E_A0_HIST_BON_WIDTH_H, (GET_INPUT_TIMING_HWIDTH() - (GET_INPUT_TIMING_HWIDTH() >> 2) + 2));
}

//--------------------------------------------------
// Description  : Gray detect function in main-loop. Trigger timer events after gray pattern detected.
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerNrGrayDetect(void)
{
    // Check if current pattern is gray
    if(GET_NR_PATTERN_IS_GRAY() == _FALSE)
    {
        if((GET_NR_STATE() != _NR_STATE_GRAY_DETECT) || (GET_NR_FLAG(_NR_FLAG_INITIALIZED) == _FALSE))
        {
            ScalerNrGrayDetectInitial();
            SET_NR_STATE(_NR_STATE_GRAY_DETECT);
            SET_NR_FLAG(_NR_FLAG_INITIALIZED);

            // Reset timer event
            CLR_NR_FLAG(_NR_FLAG_DONE_TIMER_EVENT);
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_NR_DETECTION_FINISHED);
        }

        return;
    }
    else if(GET_NR_STATE() == _NR_STATE_GRAY_DETECT)
    {
        SET_NR_STATE(_NR_STATE_PATTERN_DETECT);
    }

    // If measure had started but not yet finished, beat it.
    if((GET_NR_FLAG(_NR_FLAG_INITIALIZED) == _TRUE) &&
       ((GET_NR_FLAG(_NR_FLAG_DONE_TIMER_EVENT) == _FALSE) || (ScalerGetBit(P1E_AC_START_HIST_FUNC, (_BIT3 | _BIT1)) != 0x00)))
    {
        return;
    }

    // Perform initial/adjust/monitor actions accordingly
    if(GET_NR_FLAG(_NR_FLAG_INITIALIZED) == _FALSE)
    {
        if(GET_NR_STATE() == _NR_STATE_OFFSET_ADJUST)
        {
            ScalerNrOffsetAdjustInitial();
        }
        else
        {
            ScalerNrPatternDetectInitial();
        }

        // Flag "NR initialized" & reset counter
        SET_NR_FLAG(_NR_FLAG_INITIALIZED);
        CLR_NR_COUNTER();
    }
    else
    {
        if(GET_NR_STATE() == _NR_STATE_OFFSET_ADJUST)
        {
            if(ScalerNrOffsetAdjust() == _FALSE)
            {
                // Store pattern ID & switch to monitor state
                SET_NR_PATTERN_SAVED(GET_NR_PATTERN());
                SET_NR_STATE(_NR_STATE_MONITOR);
            }
        }
        else
        {
            ScalerNrPatternDetect();
        }
    }

    // Set timer event with duration = (frame period + 2ms)
    CLR_NR_FLAG(_NR_FLAG_DONE_TIMER_EVENT);
    ScalerTimerActiveTimerEvent((GET_NR_ONE_FRAME_MS() + 2), _SCALER_TIMER_EVENT_NR_DETECTION_FINISHED);
}

//--------------------------------------------------
// Description  : Initial function for pattern detect
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerNrPatternDetectInitial(void)
{
    // Set pattern detect boundary along with gray detect boundary
    ScalerNrGrayDetectInitial();

    // Set default detect crosshair
    ScalerNrShiftCrosshair();

    // Pattern detect starts from G channel
    ScalerSetBit(P1E_AD_FUNC1_CTRL1, ~(_BIT7 | _BIT6), (_NR_G_CHANNEL << 6));

    // Start test pattern detect
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~(_BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT2));

    // Reset pattern ID
    SET_NR_PATTERN(_NR_PATTERN_NONE);
}

//--------------------------------------------------
// Description  : Function for pattern detect/monitor state. Check detected pattern, if any.
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerNrPatternDetect(void)
{
    SET_NR_PATTERN_NOW(_NR_PATTERN_NONE);

    // Detect current pattern
    switch(ScalerGetBit(P1E_B1_FUNC1_RESULT1, (_BIT1 | _BIT0)))
    {
#if(_ADCNR_LEVELED_PATTERN_SUPPORT == _ON)       
        case _BIT0:
            SET_NR_PATTERN_NOW(ScalerNrDetectLeveledPattern());
            break;
#endif            

        case _BIT1:
            if(ScalerGetByte(P1E_B3_MONO_REF_VALUE) <= _NR_MAX_MONO_PATTERN_VALUE)
            {
                SET_NR_PATTERN_NOW(ScalerGetByte(P1E_B3_MONO_REF_VALUE));
            }

            break;
    }

    // Check for saved pattern in MONITOR state
    if((GET_NR_STATE() == _NR_STATE_MONITOR) &&
       (cabs(GET_NR_PATTERN_SAVED() - GET_NR_PATTERN_NOW()) <= GET_NR_FLAG(_NR_FLAG_VARYING_PATTERN)))
    {
        // Monitored pattern found. Reset counter.
        if(GET_NR_COUNTER() != 0)
        {
            SET_NR_PATTERN(_NR_PATTERN_NONE);
            CLR_NR_COUNTER();
        }
    }
    else
    {
        // Check pattern change
        if(GET_NR_PATTERN() == _NR_PATTERN_NONE)
        {
            if(GET_NR_PATTERN_NOW() != _NR_PATTERN_NONE)
            {
                SET_NR_PATTERN(GET_NR_PATTERN_NOW());
                INC_NR_COUNTER();
            }
        }
        else if(cabs(GET_NR_PATTERN() - GET_NR_PATTERN_NOW()) < 2)
        {
            INC_NR_COUNTER();
        }
        else
        {
            DEC_NR_COUNTER();
        }

        // Perform operations according to NR counter
        switch(GET_NR_COUNTER())
        {
            case 0:
                if(GET_NR_PATTERN() != _NR_PATTERN_NONE)
                {
                    SET_NR_PATTERN(_NR_PATTERN_NONE);
                }
                break;

            case _NR_TOLERANCE_PATTERN_BOUNCE:
                if(GET_NR_PATTERN() == 0x00)
                {
                    // NOP for MONO-0
                    SET_NR_STATE(_NR_STATE_MONITOR);
                }
                else
                {
                    // Reload pattern ID with current detected result
                    SET_NR_STATE(_NR_STATE_OFFSET_ADJUST);
                }

                return;
        }
    }

    // Shift detect crosshair
    ScalerNrShiftCrosshair();

    // Retart test pattern detect
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~(_BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT2));
}

//--------------------------------------------------
// Description  : Initial function of offset adjust state
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerNrOffsetAdjustInitial(void)
{
    if(GET_NR_PATTERN_IS_MONO() == _TRUE)
    {
#if(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_HALF)
        // Start = (1/4, 20), length = 128 x 128
        ScalerNrSetBoundaryStart((GET_INPUT_TIMING_HWIDTH() >> 1), 20);
        ScalerNrSetBoundaryLength(128, (_NR_MAX_PQ_DETECT_AREA / 128));

#elif(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_UPPER_QUARTER)
        // Start = (1/8, 20), length = 256 x 64
        ScalerNrSetBoundaryStart((GET_INPUT_TIMING_HWIDTH() >> 3), 20);
        ScalerNrSetBoundaryLength((_NR_MAX_PQ_DETECT_AREA / 64), 64);

#elif(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_LOWER_QUARTER)
        // Start = (1/8 , 20 + 3/4), length = 256 x 64
        ScalerNrSetBoundaryStart((GET_INPUT_TIMING_HWIDTH() >> 3), ((GET_INPUT_TIMING_VHEIGHT() - (GET_INPUT_TIMING_VHEIGHT() >> 2)) + 20));
        ScalerNrSetBoundaryLength((_NR_MAX_PQ_DETECT_AREA / 64), 64);

#else
        // Start = (1/2, 20), length = 64 x 256
        ScalerNrSetBoundaryStart((GET_INPUT_TIMING_HWIDTH() >> 1), 20);
        ScalerNrSetBoundaryLength(64, (_NR_MAX_PQ_DETECT_AREA / 64));
#endif

        // Set shift times to "0"
        ScalerSetBit(P1E_C1_FUNC2_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

        // Set waterlevel to 0
        ScalerSetWord(P1E_C2_FUNC2_CTRL2, 0x00);

        // Histogram starts from min tone
        ScalerSetBit(P1E_C4_FUNC2_CTRL4, ~_BIT7, _BIT7);

        // Load min-tone = (reference value - 2);
        LOAD_NR_MIN_TONE();

        // Set shift distance to 0
        ScalerSetWord(P1E_C5_SHIFT_A_H, 0x00);
    }
#if(_ADCNR_LEVELED_PATTERN_SUPPORT == _ON)           
    else
    {
        // Set histogram boundary shift
        ScalerNrSetLeveledShiftStep(GET_NR_PATTERN_LEVEL());

        // Set histogram boundary; Set shift times
        if(GET_NR_PATTERN_LEVEL() == _NR_PATTERN_32_LEVEL)
        {
            ScalerSetBit(P1E_C1_FUNC2_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 3);
            ScalerNrSetLeveledBoundary(_NR_PATTERN_64_LEVEL);
        }
        else
        {
            ScalerSetBit(P1E_C1_FUNC2_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 2);
            ScalerNrSetLeveledBoundary(GET_NR_PATTERN_LEVEL());
        }

        // Set water level
        ScalerSetWord(P1E_C2_FUNC2_CTRL2, ~((WORD)((DWORD)ScalerGetWord(P1E_A0_HIST_BON_WIDTH_H) * ScalerGetWord(P1E_A2_HIST_BON_HEIGHT_H) * _NR_SCORING_THRESHOLD_FOR_LEVELED >> 8)));

        // Histogram from first 4 pixels
        ScalerSetBit(P1E_C4_FUNC2_CTRL4, ~_BIT7, 0x00);
    }
#endif

    // Pre-load current LSB; Set score to 0;
    pData[0] = ScalerGetByte(P0_BF_ADC_RGB_OFFSET_LSB);
    g_stNrData.ucNrMemory[2] = (pData[0] & (_BIT1 | _BIT0));
    pData[0] = (pData[0] >> 2);
    g_stNrData.ucNrMemory[1] = (pData[0] & (_BIT1 | _BIT0));
    pData[0] = (pData[0] >> 2);    
    g_stNrData.ucNrMemory[0] = (pData[0] & (_BIT1 | _BIT0));

    // PQ judge starts from G channel;
    ScalerSetBit(P1E_C1_FUNC2_CTRL1, ~(_BIT5 | _BIT4), (_NR_G_CHANNEL << 4));

    // Pattern detect starts from R channel
    ScalerSetBit(P1E_AD_FUNC1_CTRL1, ~(_BIT7 | _BIT6), (_NR_R_CHANNEL << 6));

    // Pattern detect along the first row/colurm; Start test pattern detect & PQ judge
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1));

    // Clear VARYING_PATTERN flag
    CLR_NR_FLAG(_NR_FLAG_VARYING_PATTERN);
}

//--------------------------------------------------
// Description  : Adjust offset LSB according to PQ judge result
// Input Value  : none
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerNrOffsetAdjust(void)
{
    #define UC_NEXT_CHANNEL (pData[5])
    BYTE ucChannel = 0;
    ucChannel = (ScalerGetBit(P1E_C1_FUNC2_CTRL1, (_BIT5 | _BIT4)) >> 4);

    // Search LSB for current channel
    switch(ScalerNrSearchLsb(ucChannel))
    {
        case _NR_RESULT_STOP_CHANNEL:
            SET_NR_FINISHED(ucChannel);
            break;

        case _NR_RESULT_STOP_ALL:
            SET_NR_FLAG(_NR_FLAG_VARYING_PATTERN);
            return _FALSE;
    }

    // If all 3 channels are done, end searching
    if((GET_NR_FINISHED(_NR_R_CHANNEL) && GET_NR_FINISHED(_NR_G_CHANNEL) && GET_NR_FINISHED(_NR_B_CHANNEL)) == _TRUE)
    {
        return _FALSE;
    }

    // Find the next channel which is not done yet (order: G -> R -> B)
    UC_NEXT_CHANNEL = ScalerNrFindNextChannel(ucChannel);

    // Update NR counter if needed (1. * -> G; 2. B -> *; 3. R -> R)
    if((ucChannel == _NR_B_CHANNEL) || (UC_NEXT_CHANNEL == _NR_G_CHANNEL) || (UC_NEXT_CHANNEL == ucChannel))
    {
        if(GET_NR_COUNTER() == 3)
        {
            SET_NR_FLAG(_NR_FLAG_VARYING_PATTERN);
            return _FALSE;
        }
        else
        {
            INC_NR_COUNTER();
        }
    }

    // Switch PQ judge channel
    ScalerSetBit(P1E_C1_FUNC2_CTRL1, ~(_BIT5 | _BIT4), (UC_NEXT_CHANNEL << 4));

    // Switch pattern detect channel for mono patterns
    if(GET_NR_PATTERN_IS_MONO() == _TRUE)
    {
        ScalerSetBit(P1E_AD_FUNC1_CTRL1, ~(_BIT7 | _BIT6), (ScalerNrFindNextChannel(UC_NEXT_CHANNEL) << 6));

        // Load min tone
        LOAD_NR_MIN_TONE();
    }

    // Restart test pattern detect & PQ judge
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~(_BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT2 | _BIT1));

    return _TRUE;

    #undef UC_NEXT_CHANNEL
}

//--------------------------------------------------
// Description  : Check tone values before offset LSB search
// Input Value  : pucResult: search result
// Output Value : _NR_RESULT_STOP_CHANNEL, _NR_RESULT_STOP_ALL, or _NR_RESULT_KEEP_SEARCHING
//--------------------------------------------------
EnumNrSearchResultStatus ScalerNrPresearchCheck(BYTE *pucResult)
{
    #define UC_INDEX            (pData[0])    
    #define UC_MAX_TONE         (pData[1])
    #define US_ADDRESS          (PDATA_WORD(5))
    #define US_FIRST_TONE       (PDATA_WORD(6))
    #define US_SECOND_TONE      (PDATA_WORD(7))

    UC_MAX_TONE = 0;
    US_ADDRESS = P1E_C7_TONE1_NUM_H;
    US_FIRST_TONE = 0;
    US_SECOND_TONE = 0;
    
    // Search for largest & second largest tones    
    for(UC_INDEX = 0; UC_INDEX < 4; ++UC_INDEX)
    {
        if(ScalerGetWord(US_ADDRESS) > US_FIRST_TONE)
        {
            UC_MAX_TONE = UC_INDEX;
            US_SECOND_TONE = US_FIRST_TONE;
            US_FIRST_TONE = ScalerGetWord(US_ADDRESS);
        }
        else if(ScalerGetWord(US_ADDRESS) > US_SECOND_TONE)
        {
            US_SECOND_TONE = ScalerGetWord(US_ADDRESS);
        }

        US_ADDRESS += 2;
    }

    *pucResult = UC_MAX_TONE;

    // Check tone values
    if(GET_NR_PATTERN_IS_MONO() == _TRUE)
    {        
        // For mono pattern, check coverage for main + sub
        if(GET_NR_PREVIOUS_TONE(UC_MAX_TONE) > GET_NR_NEXT_TONE(UC_MAX_TONE))
        {
            US_SECOND_TONE = GET_NR_PREVIOUS_TONE(UC_MAX_TONE);
        }
        else
        {
            US_SECOND_TONE = GET_NR_NEXT_TONE(UC_MAX_TONE);
        }

        if((US_FIRST_TONE + US_SECOND_TONE) < _NR_MIN_COVERAGE_FOR_MONO)
        {
            // Coverage too low. Maybe mis-detect.
            return _NR_RESULT_STOP_ALL;
        }

        // Update pattern ID from G ref. value for mono pattern only
        if(ScalerGetBit(P1E_C1_FUNC2_CTRL1, (_BIT5 | _BIT4)) == (_NR_G_CHANNEL << 4))
        {
            SET_NR_PATTERN(ScalerGetBit(P1E_C4_FUNC2_CTRL4, 0x7F) + UC_MAX_TONE);
        }

        // If PQ > 96%, or the difference between sub-tones < 3%, stop searching.
        if((GET_NR_TONE(UC_MAX_TONE) > (_NR_MAX_PQ_DETECT_AREA * 0.96)) ||
           (abs(GET_NR_PREVIOUS_TONE(UC_MAX_TONE) - GET_NR_NEXT_TONE(UC_MAX_TONE)) < _NR_MIN_SUBTONE_DIFFERENCE))
        {
            return _NR_RESULT_STOP_CHANNEL;
        }
    }
#if(_ADCNR_LEVELED_PATTERN_SUPPORT == _ON)           
    else
    {
        // For leveled pattern, check coverage 1st & 2nd tone
        if((US_SECOND_TONE + US_FIRST_TONE) <= _NR_MIN_COVERAGE_FOR_LEVELED)
        {
            // Coverage too low. Maybe mis-detect.
            return _NR_RESULT_STOP_ALL;
        }
    }
#endif    

    return _NR_RESULT_KEEP_SEARCHING;

    #undef UC_INDEX
    #undef UC_MAX_TONE
    #undef US_ADDRESS 
    #undef US_FIRST_TONE
    #undef US_SECOND_TONE 
}

//--------------------------------------------------
// Description  : Adjust offset LSB according to measured score / PQ
// Input Value  : ucChannel: channel number (R: 0, G: 1, B: 2).
// Output Value : _NR_RESULT_STOP_CHANNEL, _NR_RESULT_STOP_ALL, or _NR_RESULT_KEEP_SEARCHING
//--------------------------------------------------
EnumNrSearchResultStatus ScalerNrSearchLsb(BYTE ucChannel)
{    
    #define UC_SCORE (pData[0])    
    #define UC_LSB_SHIFT_BITS (pData[1])
    #define UC_LSB_MASK (pData[2])
    #define UC_LSB_VALUE (pData[3])
    #define UC_PRECHECK_RESULT (pData[4])
    BYTE ucPresearchResult = 0;

    // Perform pre-search check
    if((UC_PRECHECK_RESULT = ScalerNrPresearchCheck(&ucPresearchResult)) != _NR_RESULT_KEEP_SEARCHING)
    {
        return UC_PRECHECK_RESULT;
    }

    // Read current score/PQ from registers
    if(GET_NR_PATTERN_IS_MONO() == _TRUE)
    {
        // Save bit 12~7 in 14-bit score, total 6 bits
        UC_SCORE = (LOBYTE(GET_NR_TONE(ucPresearchResult) >> 7) & 0x3F);
    }
#if(_ADCNR_LEVELED_PATTERN_SUPPORT == _ON)           
    else
    {
        switch(ucChannel)
        {
            case _NR_R_CHANNEL:
                UC_SCORE = ScalerGetBit(P1E_CF_HIST_SCORE1, 0x0F); // R score
                break;

            case _NR_G_CHANNEL:
                UC_SCORE = (ScalerGetBit(P1E_D0_HIST_SCORE2, 0xF0) >> 4); // G score
                break;

            case _NR_B_CHANNEL:
                UC_SCORE = ScalerGetBit(P1E_D0_HIST_SCORE2, 0x0F); // B score
                break;
        }

        // Maximum score for leveled pattern is (shift times + 1)
        if(UC_SCORE == (ScalerGetBit(P1E_C1_FUNC2_CTRL1, 0x0F) + 1))
        {
            return _NR_RESULT_STOP_CHANNEL;
        }
    }
#endif    

    UC_LSB_SHIFT_BITS = ((2 - ucChannel) << 1);
    UC_LSB_MASK = ((_BIT1 | _BIT0) << UC_LSB_SHIFT_BITS);
    UC_LSB_VALUE = ScalerGetBit(P0_BF_ADC_RGB_OFFSET_LSB, UC_LSB_MASK);

    // Compare with current max value; Store LSB if larger
    if(UC_SCORE > GET_NR_SCORE(ucChannel))
    {
        SET_NR_LSB((UC_LSB_VALUE >> UC_LSB_SHIFT_BITS), ucChannel);
        SET_NR_SCORE(UC_SCORE, ucChannel);
    }
    else
    {
        // Check if PQ decreased for mono pattern; Stop if so.
        if(GET_NR_PATTERN_IS_MONO() == _TRUE)
        {
            UC_LSB_VALUE = (GET_NR_LSB(ucChannel) << UC_LSB_SHIFT_BITS);
            ScalerSetBit(P0_BF_ADC_RGB_OFFSET_LSB, ~UC_LSB_MASK, (UC_LSB_VALUE & UC_LSB_MASK));
            return _NR_RESULT_STOP_CHANNEL;
        }
    }

    // Search for next LSB
    if(GET_NR_COUNTER() > 2)
    {
        // Timeout. Reload with the highest score
        UC_LSB_VALUE = (GET_NR_LSB(ucChannel) << UC_LSB_SHIFT_BITS);
    }
    else
    {
        if(GET_NR_PATTERN_IS_MONO() == _TRUE)
        {
            // Adjust LSB by sub-tone relationship.
            if(GET_NR_PREVIOUS_TONE(ucPresearchResult) > GET_NR_NEXT_TONE(ucPresearchResult))
            {
                UC_LSB_VALUE += 0x3F; // LSB - 1
            }
            else
            {
                UC_LSB_VALUE += 0x15; // LSB + 1
            }
        }
#if(_ADCNR_LEVELED_PATTERN_SUPPORT == _ON)               
        else
        {
            // Increase offset by (NR counter + 1)
            UC_LSB_VALUE += ((GET_NR_COUNTER() + 1) << UC_LSB_SHIFT_BITS);
        }
#endif        
    }

    ScalerSetBit(P0_BF_ADC_RGB_OFFSET_LSB, ~UC_LSB_MASK, (UC_LSB_VALUE & UC_LSB_MASK));
    return _NR_RESULT_KEEP_SEARCHING;

    #undef UC_SCORE
    #undef UC_LSB_SHIFT_BITS
    #undef UC_LSB_MASK
    #undef UC_LSB_VALUE
    #undef UC_PRECHECK_RESULT
}

//--------------------------------------------------
// Description  : Set pattern detect crosshair according to NR counter
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerNrShiftCrosshair(void)
{
    ScalerSetBit(P1E_AC_START_HIST_FUNC, ~_BIT0, _BIT0);

    switch(GET_NR_COUNTER())
    {
        case 0:
            // Center row/column
            ScalerSetWord(P1E_A8_DET_ROW_H, (ScalerGetWord(P1E_A2_HIST_BON_HEIGHT_H) >> 1));
            ScalerSetWord(P1E_AA_DET_COLUMN_H, (ScalerGetWord(P1E_A0_HIST_BON_WIDTH_H) >> 1));
            break;

        case 1:
            // Bottom row/column
            ScalerSetWord(P1E_A8_DET_ROW_H, ScalerGetWord(P1E_A2_HIST_BON_HEIGHT_H));
            ScalerSetWord(P1E_AA_DET_COLUMN_H, ScalerGetWord(P1E_A0_HIST_BON_WIDTH_H));
            break;

        default:
            // First row/column
            ScalerSetBit(P1E_AC_START_HIST_FUNC, ~_BIT0, 0x00);
            break;
    }
}

//--------------------------------------------------
// Description  : Set ADC histogram horizontal measure boundary
// Input Value  : usHStart/usVStart: H/V start position within capture window
// Output Value : none
//--------------------------------------------------
void ScalerNrSetBoundaryStart(WORD usHStart, WORD usVStart)
{
    ScalerSetWord(P1E_A4_HIST_HOR_START_H, (usHStart + ScalerVgipGetCaptureHDelay() + ScalerVgipGetCaptureHStartPosition()));
    ScalerSetWord(P1E_A6_HIST_VER_START_H, (usVStart + ScalerVgipGetCaptureVDelay() + ScalerVgipGetCaptureVStartPosition()));
}

//--------------------------------------------------
// Description  : Set ADC histogram vertical measure boundary
// Input Value  : usHWidth / usVheight: H/V boundary length; usLimit: max boundary area
// Output Value : none
//--------------------------------------------------
void ScalerNrSetBoundaryLength(WORD usHWidth, WORD usVHeight)
{
#if(_ADCNR_LEVELED_PATTERN_SUPPORT == _ON)           
    if(GET_NR_STATE() == _NR_STATE_OFFSET_ADJUST)
    {
        if(usHWidth > usVHeight)
        {
            PDATA_WORD(6) = (WORD)_NR_MAX_PQ_DETECT_AREA / usVHeight;

            if(usHWidth > PDATA_WORD(6))
            {
                usHWidth =  PDATA_WORD(6);
            }
        }
        else
        {
            PDATA_WORD(6) = (WORD)_NR_MAX_PQ_DETECT_AREA / usHWidth;

            if(usVHeight > PDATA_WORD(6))
            {
                usVHeight = PDATA_WORD(6);
            }
        }
    }
#endif

    ScalerSetWord(P1E_A0_HIST_BON_WIDTH_H, usHWidth);
    ScalerSetWord(P1E_A2_HIST_BON_HEIGHT_H, usVHeight);
}

//--------------------------------------------------
// Description  : Search next NR channel which is finished yet
// Input Value  : enumCurrentChannel: current channel ID
// Output Value : next valid channel
//--------------------------------------------------
BYTE ScalerNrFindNextChannel(EnumNrChannelId enumCurrentChannel)
{
    // Search order: G -> R -> B
    for(pData[3] = 1; pData[3] <= 3; ++pData[3])
    {
        enumCurrentChannel = ((enumCurrentChannel + 0x02) % 3);

        if(GET_NR_FINISHED(enumCurrentChannel) == _FALSE)
        {
            break;
        }
    }

    return enumCurrentChannel;
}

#if(_ADCNR_LEVELED_PATTERN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Discriminate leveled pattern after test pattern detection finished.
// Input Value  : none
// Output Value : Detected pattern ID
//--------------------------------------------------
BYTE ScalerNrDetectLeveledPattern(void)
{
    #define UC_GROUP_INDEX (pData[0])
    #define UC_GROUP_COUNT (pData[1])
    #define UC_STEP        (pData[2])
    #define UC_LEVEL       (pData[3])
    #define UC_IDEAL_STEP  (pData[4])
    #define US_A           (PDATA_WORD(6))    
    #define US_IDEAL_A     (PDATA_WORD(7))    

    // Search for group with the largest member number    
    UC_GROUP_INDEX = 2;
    if(ScalerGetByte(P1E_BE_COUNTER_1) > ScalerGetByte(P1E_BF_COUNTER_2))
    {
        if(ScalerGetByte(P1E_BE_COUNTER_1) > ScalerGetByte(P1E_C0_COUNTER_3))
        {
            UC_GROUP_INDEX = 0;
        }
    }
    else if(ScalerGetByte(P1E_BF_COUNTER_2) > ScalerGetByte(P1E_C0_COUNTER_3))
    {
        UC_GROUP_INDEX = 1;
    }

    // Get counter, A, and step
    UC_GROUP_COUNT = ScalerGetByte(P1E_BE_COUNTER_1 + UC_GROUP_INDEX); // Counter
    US_A = ScalerGetWord(P1E_B8_A_1_H + (UC_GROUP_INDEX << 1)); // A

    // Check sign of step
    UC_STEP = ScalerGetByte(P1E_B5_STEP_1 + UC_GROUP_INDEX); // Positive step
    if(ScalerGetBit(P1E_B4_STEP_H, (_BIT0 << (2 - UC_GROUP_INDEX))) != 0x00)
    {
        UC_STEP = ~UC_STEP; // Negative step
    }

    // Check counter range between 3 ~ 24
    if((UC_GROUP_COUNT < 3) || (UC_GROUP_COUNT > 24))
    {
        return _NR_PATTERN_NONE;
    }

#if(_ADCNR_VERTICAL_BOUNDARY_TYPE != _NR_V_BOUNDARY_FULL)
    if(ScalerGetBit(P1E_B2_FUNC1_RESULT2, _BIT1) == 0x00)
    {
        // For half & quarter regions, NOP for vertical levels
        return _NR_PATTERN_NONE;
    }
#endif

    // Find the nearst level configuration
    for(UC_LEVEL = _NR_PATTERN_8_LEVEL; UC_LEVEL <= _NR_PATTERN_32_LEVEL; ++UC_LEVEL)
    {
        if(UC_GROUP_COUNT <= ((0x01 << UC_LEVEL) - (0x01 << (UC_LEVEL - 2))))
        {
            break;
        }
    }

    // Set ideal step size for later tolerance check
    switch(UC_LEVEL)
    {
        case _NR_PATTERN_8_LEVEL:
            UC_IDEAL_STEP = 36; // Ideal step size
            break;

        case _NR_PATTERN_16_LEVEL:
            UC_IDEAL_STEP = 17;
            break;

        case _NR_PATTERN_32_LEVEL:
            UC_IDEAL_STEP = 8;
            break;
    }

    // Set ideal A for later tolerance check
#if(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_FULL)    
    if(ScalerGetBit(P1E_B2_FUNC1_RESULT2, _BIT1) == 0x00)
    {
        US_IDEAL_A = (GET_INPUT_TIMING_VHEIGHT() >> UC_LEVEL);
    }
    else
#endif        
    {
        US_IDEAL_A = (GET_INPUT_TIMING_HWIDTH() >> UC_LEVEL);
    }

    // Check step & A tolerance
    if((GET_NR_PATTERN() == _NR_PATTERN_NONE) ||
       ((GET_NR_PATTERN_DIRECTION() == ScalerGetBit(P1E_B2_FUNC1_RESULT2, (_BIT1 | _BIT0))) &&
        (GET_NR_PATTERN_LEVEL() == UC_LEVEL)))
    {
        if((abs(US_IDEAL_A - US_A) <= _NR_TOLERANCE_A_ERROR) &&
           (cabs(UC_IDEAL_STEP - UC_STEP) <= _NR_TOLERANCE_STEP_ERROR))
        {
            // Leveled pattern detected. Return new ID.
            return ((UC_LEVEL << 5) | (ScalerGetBit(P1E_B2_FUNC1_RESULT2, (_BIT1 | _BIT0)) << 3));
        }
    }

    return _NR_PATTERN_NONE;

    #undef UC_GROUP_INDEX
    #undef UC_GROUP_COUNT
    #undef UC_STEP        
    #undef UC_LEVEL       
    #undef UC_IDEAL_STEP  
    #undef US_A           
    #undef US_IDEAL_A    
}

//--------------------------------------------------
// Description  : Set ADC histogram measure boundary for leveled pattern
// Input Value  : ucLevels: boundary setting for certain level
// Output Value : none
//--------------------------------------------------
void ScalerNrSetLeveledBoundary(BYTE ucLevels)
{
    #define US_H_START PDATA_WORD(0)
    #define US_V_START PDATA_WORD(1)
    #define US_H_WIDTH PDATA_WORD(2)
    #define US_V_HEIGHT PDATA_WORD(3)

#if(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_FULL)    
    if((GET_NR_PATTERN_DIRECTION() & _BIT1) == 0x00)
    {
        // Up/Down: V height = 1/2 level height, V start = 1/4 level height
        US_V_HEIGHT = (GET_INPUT_TIMING_VHEIGHT() >> (ucLevels + 1));
        US_V_START = (US_V_HEIGHT >> 1);

        if(GET_NR_PATTERN_DIRECTION() == _NR_PATTERN_UP)
        {
            US_V_START = (GET_INPUT_TIMING_VHEIGHT() - US_V_HEIGHT - US_V_START); // Modify V start
        }

        // H start = 1/8 width, H width = 3/4 width
        US_H_START = (GET_INPUT_TIMING_HWIDTH() >> 3);
        US_H_WIDTH = (GET_INPUT_TIMING_HWIDTH() - (GET_INPUT_TIMING_HWIDTH() >> 2));
    }
    else
#endif        
    {
        // Left/Right: H width = 1/2 level width, H start = 1/4 level width
        US_H_WIDTH = (GET_INPUT_TIMING_HWIDTH() >> (ucLevels + 1));
        US_H_START = (US_H_WIDTH >> 1);

        if(GET_NR_PATTERN_DIRECTION() == _NR_PATTERN_LEFT)
        {
            US_H_START = (GET_INPUT_TIMING_HWIDTH() - US_H_WIDTH - US_H_START); // Modify H start
        }

#if(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_HALF)
        // V start = 1/16 height, V height = 3/8 height
        US_V_START = (GET_INPUT_TIMING_VHEIGHT() >> 4);
        US_V_HEIGHT = ((GET_INPUT_TIMING_VHEIGHT() >> 1) - (GET_INPUT_TIMING_VHEIGHT() >> 3));

#elif(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_UPPER_QUARTER)
        // V start = 1/32 height, V height = 3/16 height
        US_V_START = (GET_INPUT_TIMING_VHEIGHT() >> 5);
        US_V_HEIGHT = ((GET_INPUT_TIMING_VHEIGHT() >> 2) - (GET_INPUT_TIMING_VHEIGHT() >> 4));

#elif(_ADCNR_VERTICAL_BOUNDARY_TYPE == _NR_V_BOUNDARY_LOWER_QUARTER)
        // V start = 25/32 height, V height = 3/16 height
        US_V_START = (GET_INPUT_TIMING_VHEIGHT() - (GET_INPUT_TIMING_VHEIGHT() >> 2)) + (GET_INPUT_TIMING_VHEIGHT() >> 5);
        US_V_HEIGHT = ((GET_INPUT_TIMING_VHEIGHT() >> 2) - (GET_INPUT_TIMING_VHEIGHT() >> 4));

#else
        // V start = 1/8 height, V height = 3/4 height
        US_V_START = (GET_INPUT_TIMING_VHEIGHT() >> 3);
        US_V_HEIGHT = (GET_INPUT_TIMING_VHEIGHT() - (GET_INPUT_TIMING_VHEIGHT() >> 2));
#endif
    }

    ScalerNrSetBoundaryStart(US_H_START, US_V_START);
    ScalerNrSetBoundaryLength(US_H_WIDTH, US_V_HEIGHT);

    #undef US_H_START
    #undef US_V_START
    #undef US_H_WIDTH
    #undef US_V_HEIGHT
}

//--------------------------------------------------
// Description  : Set ADC histogram measure boundary for leveled pattern
// Input Value  : ucLevels: boundary setting for certain level
// Output Value : none
//--------------------------------------------------
void ScalerNrSetLeveledShiftStep(BYTE ucLevels)
{
    // Set shift direction
    ScalerSetBit(P1E_B2_FUNC1_RESULT2, ~(_BIT4 | _BIT3), (GET_NR_PATTERN_DIRECTION() << 3));

    if((GET_NR_PATTERN_DIRECTION() & _BIT1) == 0x00)
    {
        ScalerSetWord(P1E_C5_SHIFT_A_H, (GET_INPUT_TIMING_VHEIGHT() >> ucLevels)); // Shift step = level height
    }
    else
    {
        ScalerSetWord(P1E_C5_SHIFT_A_H, (GET_INPUT_TIMING_HWIDTH() >> ucLevels)); // Shift step = level width
    }
}
#endif // End of #if(_ADCNR_LEVELED_PATTERN_SUPPORT == _ON)
#endif // End of #if((_VGA_SUPPORT == _ON) && (_ADCNR_BY_HISTOGRAM_SUPPORT == _ON))
