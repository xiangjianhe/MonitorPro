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
// ID Code      : RL6269_Series_AutoFunc.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6269_SERIES_AUTOFUNC__

#include "ScalerFunctionInclude.h"

#if(_VGA_SUPPORT == _ON)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

#if(_ADC_SELF_CALIBRATION == _ON)
#define GET_CALIBRATION_STATUS()                 (ScalerGetBit(P0_CD_ADC_V_BIAS1, _BIT7) == _BIT7)
#endif

#if(_YPBPR_SUPPORT == _ON)
#define _AUTO_Y_MAX_LEVEL                        235
#define _AUTO_PBPR_MAX_LEVEL                     240
#define GET_TUNE_YPBPR_STATUS()                  (ScalerGetBit(P0_CF_ADC_CTL_RED, _BIT7) == _BIT7)
#endif

#define _DEFAULT_GAIN                            0xFF
#define _DEFAULT_OFFSET                          0x40
#define _DEFAULT_SHA                             8
#define _AUTO_RGB_MAX_LEVEL                      255

#define _ADC_MAXIMUM_TOLERANCE                   60
#define _MARGIN_FOR_SHA_CHANGE                   8
#define _BLACK_LEVEL_THRESHOLD                   32
#define _USER_ADJUST_OFFSET_RANGE                5

#if(_PANEL_ADC_OFFSET_BIAS < 0)
#undef _PANEL_ADC_OFFSET_BIAS
#define _PANEL_ADC_OFFSET_BIAS                   0
#elif(_PANEL_ADC_OFFSET_BIAS > _USER_ADJUST_OFFSET_RANGE)
#undef _PANEL_ADC_OFFSET_BIAS
#define _PANEL_ADC_OFFSET_BIAS                   _USER_ADJUST_OFFSET_RANGE
#endif

#if(_PANEL_ADC_GAIN_BIAS > 0)
#undef _PANEL_ADC_GAIN_BIAS
#define _PANEL_ADC_GAIN_BIAS                     (0)
#endif

#define GET_AUTO_RESULT_DWORD()                  (*((volatile DWORD xdata *)(CM_84_AUTO_PHASE_3)))
#define GET_AUTO_RESULT_WORD2()                  (*((volatile WORD xdata *)(CM_84_AUTO_PHASE_3)))
#define GET_AUTO_RESULT_WORD1()                  (*((volatile WORD xdata *)(CM_85_AUTO_PHASE_2)))
#define GET_AUTO_RESULT_WORD0()                  (*((volatile WORD xdata *)(CM_86_AUTO_PHASE_1)))
#define GET_AUTO_RESULT_MAX()                    ScalerGetByte(CM_87_AUTO_PHASE_0)
#define GET_AUTO_RESULT_MIN()                    (ScalerGetByte(CM_87_AUTO_PHASE_0) ^ 0xFF)
#define GET_ADC_SHA_GAIN()                       ((ScalerGetByte(P0_CE_ADC_CTL_RGB) & 0xF0) >> 4)
#define GET_AUTO_ADC_GAIN()                      (ScalerGetByte((P0_C2_BLU_GAIN_MSG - ScalerGetBit(CM_7A_AUTO_ADJ_CTRL0, (_BIT1 | _BIT0)))))
#define GET_AUTO_ADC_OFFSET()                    (ScalerGetByte((P0_C5_BLU_OFFSET_MSG - ScalerGetBit(CM_7A_AUTO_ADJ_CTRL0, (_BIT1 | _BIT0)))))
#define SET_AUTO_ADC_GAIN(ucValue)               (ScalerSetByte((P0_C2_BLU_GAIN_MSG - ScalerGetBit(CM_7A_AUTO_ADJ_CTRL0, (_BIT1 | _BIT0))), ucValue))
#define SET_AUTO_ADC_OFFSET(ucValue)             (ScalerSetByte((P0_C5_BLU_OFFSET_MSG - ScalerGetBit(CM_7A_AUTO_ADJ_CTRL0, (_BIT1 | _BIT0))), ucValue))
#define SET_AUTO_ADC_CHANNEL(ucColor)            (ScalerSetBit(CM_7A_AUTO_ADJ_CTRL0, ~(_BIT1 | _BIT0), ((ucColor == _AUTO_BLUE_CHANNEL) ? 0 : ((ucColor == _AUTO_GREEN_CHANNEL) ? 1 : 2))))
#define SET_AUTO_ADC_NEXT_CHANNEL()              (ScalerSetBit(CM_7A_AUTO_ADJ_CTRL0, ~(_BIT1 | _BIT0), ((ScalerGetBit(CM_7A_AUTO_ADJ_CTRL0, ~(_BIT1 | _BIT0)) + 1) % 3)))

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//--------------------------------------------------
// Definitions of stages in auto-color process
//--------------------------------------------------
typedef enum
{
    _AUTO_COLOR_TUNING = 0x00,
    _AUTO_COLOR_CHECK_SHA_GAIN,
    _AUTO_COLOR_CHECK_G_OFFSET,
    _AUTO_COLOR_COMPENSTE,
}EnumAutoColorTuningStage;

//--------------------------------------------------
// Definitions image auto-function boundary setting
//--------------------------------------------------
typedef enum
{
    _MEASURE_ACTIVE_REGION = 0x00,
    _MEASURE_PORCH_REGION,
    _MEASURE_MANUAL_REGION,
}EnumMeasureBoundary;

//--------------------------------------------------
// Definitions image auto-function measure types
//--------------------------------------------------
typedef enum
{
    _MEASURE_MAX = 0x00,
    _MEASURE_RGB_MIN,
    _MEASURE_YPBPR_MIN,
    _MEASURE_MANUAL,
}EnumMeasureType;

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
EnumAutoResult ScalerAutoDoWhiteBalance(EnumAutoColorType enumAutoType);
EnumAutoResult ScalerAutoBalanceHandler(EnumAutoColorType enumAutoType);
void ScalerAutoInitializeAutoColor(EnumAutoColorType enumAutoType);
EnumAutoResult ScalerAutoUpdateAdcGain(BYTE ucGainBias);
EnumAutoResult ScalerAutoCompensateRGB(EnumAutoColorType enumAutoType);
EnumAutoResult ScalerAutoHardwareAbl(BYTE ucTarget, BYTE ucFrameCount);
void ScalerAutoSearchShaGain(void);
EnumAutoResult ScalerAutoUpdateShaGain(BYTE ucShaGain, EnumShaGainOptions enumType);
BYTE ScalerAutoConvertShaGain(BYTE ucValue, EnumADCGainOffset enumType, BYTE ucShaFrom, BYTE ucShaTo);
BYTE ScalerAutoConvertAdcGainStep(BYTE ucGain, BYTE ucTarget, BYTE ucCurrent);
EnumAutoResult ScalerAutoCompensateChannel(BYTE ucColor, EnumAutoColorType enumAutoType);
EnumAutoResult ScalerAutoCompensateOffset(BYTE ucColor);
void ScalerAutoSetBoundary(EnumMeasureBoundary enumBounary);
EnumAutoResult ScalerAutoCompareMeasure(EnumMeasureType enumType);
EnumAutoResult ScalerAutoAccumulationMeasure(EnumMeasureType enumType, BYTE ucThreshold);
EnumAutoResult ScalerAutoMainToneMeasure(BYTE ucStartLevel, BYTE *ucMainTone);
void ScalerAutoGetAutoColorResult(StructAdcDataType *stAdcData);

#if(_YPBPR_SUPPORT == _ON)

#if(_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE)
EnumAutoResult ScalerAutoCompensateYPbPr(EnumAutoColorType enumAutoType);
#endif

#if(_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_FORMULA)
StructAdcDataType ScalerAutoBalanceYPbPrFromFormula(StructAdcDataType *stAdcData);
#endif

#endif // End of #if(_YPBPR_SUPPORT == _ON)

#if(_ADC_SELF_CALIBRATION == _ON)
EnumAutoResult ScalerAutoUpdateAdcGainCalibrationRGB(BYTE ucGainBias);
EnumAutoResult ScalerAutoCompensateCalibrationRGB(EnumAutoColorType enumAutoType);
void ScalerAutoInitializeCalibration(void);
void ScalerAutoResetCalibration(void);
EnumAutoResult ScalerAutoAblMeasure(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : ADC AutoWhiteBalance
// Input Value  : enumAutoType -> auto color for RGB / YPbPr / Self-calibration
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoDoWhiteBalance(EnumAutoColorType enumAutoType)
{
    EnumAutoResult enumResult = 0;
    BYTE ucAdcSwapStatus = 0;
    BYTE ucClampEnd = 0;

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
    // For clamp-to-top case, do nothing.
    if(ScalerADCGetClampToTopStatus() == _TRUE)
    {
        return _AUTO_SUCCESS;
    }
#endif    

    // Store ADC channel swapping, and clamp end
    ucAdcSwapStatus = ScalerGetBit(CM_16_IPH_ACT_WID_H, (_BIT6 | _BIT5 | _BIT4));
    ScalerGetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_01_SYNC_G_CLAMP_END, 1, &ucClampEnd, _AUTOINC);

    // Initialization for auto-color
    ScalerAutoInitializeAutoColor(enumAutoType);

    // Perform auto-color process    
    enumResult = ScalerAutoBalanceHandler(enumAutoType);
    
#if(_ADC_SELF_CALIBRATION == _ON)
    ScalerAutoResetCalibration();
#endif

    // Restore ADC channel swapping
    ScalerSetBit(CM_16_IPH_ACT_WID_H, ~(_BIT6 | _BIT5 | _BIT4), ucAdcSwapStatus);

    // Restore ADC clamp end; Disable clamp before adjustment
    ScalerSetBit(CM_48_SYNC_INVERT, ~_BIT2, 0x00);
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_01_SYNC_G_CLAMP_END, ucClampEnd);
    ScalerSetBit(CM_48_SYNC_INVERT, ~_BIT2, _BIT2);

    return enumResult;
}

//--------------------------------------------------
// Description  : ADC Auto Balance for RGB / YPbPr color spaces
// Input Value  : enumAutoType: RGB / YPBPR / self-calibration
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoBalanceHandler(EnumAutoColorType enumAutoType)
{
    BYTE ucIndex = 0;
    BYTE ucTarget = 0;
    BYTE ucABLFrame = 0;
    BYTE ucGainBias = 0;
    EnumAutoResult (*pucFunctionUpdateGain)(BYTE) = 0;
    EnumAutoResult (*pucFunctionCompensate)(EnumAutoColorType) = 0;

    // Select functions to update gain & compensate
    switch(enumAutoType)
	{
#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))
		case _AUTO_TUNE_YPBPR:
		case _AUTO_TUNE_YPBPR_GAIN_ONLY:            
            pucFunctionUpdateGain = &ScalerAutoUpdateAdcGain;
            pucFunctionCompensate = &ScalerAutoCompensateYPbPr;
			break;
#endif            
#if(_ADC_SELF_CALIBRATION == _ON)            
        case _AUTO_CALIBRATE_RGB:
            pucFunctionUpdateGain = &ScalerAutoUpdateAdcGainCalibrationRGB;
            pucFunctionCompensate = &ScalerAutoCompensateCalibrationRGB; 
			break;
#endif            
        case _AUTO_TUNE_RGB:
        case _AUTO_TUNE_RGB_GAIN_ONLY:            
            pucFunctionUpdateGain = &ScalerAutoUpdateAdcGain;
            pucFunctionCompensate = &ScalerAutoCompensateRGB; 
			break;

		default:			
		    return _AUTO_FAIL;
	}

    // Default target black value for both RGB & YPbPr
    ucTarget = 16;
    ucABLFrame = 2;
    ucGainBias = 5;
    
    for(ucIndex = 0; ucIndex < 4; ++ucIndex)
    {
        if((enumAutoType != _AUTO_TUNE_RGB_GAIN_ONLY) && (enumAutoType != _AUTO_TUNE_YPBPR_GAIN_ONLY))
        {
            // Adjust offset by ABL
            if(ScalerAutoHardwareAbl(ucTarget, ucABLFrame) == _AUTO_FAIL)
            {
                return _AUTO_FAIL;
            }        
        }

        // Adjust gain by auto-function 
        if(pucFunctionUpdateGain(ucGainBias) == _AUTO_FAIL)
        {
            return _AUTO_FAIL;
        }        

        // Auto-tuning process control
        switch(ucIndex)
        {
            case _AUTO_COLOR_TUNING:            
                if(enumAutoType != _AUTO_TUNE_YPBPR)
                {
                    ucTarget = 4;                
                }
                ucGainBias = 1;
                ucABLFrame = ((enumAutoType == _AUTO_CALIBRATE_RGB) ? 2 : 1);
                break;
            
            case _AUTO_COLOR_CHECK_SHA_GAIN:            
                if((enumAutoType == _AUTO_TUNE_RGB) || (enumAutoType == _AUTO_TUNE_YPBPR))
                {       
                    ScalerAutoSearchShaGain();
                }
                break;
            
            case _AUTO_COLOR_CHECK_G_OFFSET: 
                // Do nothing
                break;
            
            case _AUTO_COLOR_COMPENSTE:
            default:
                if(pucFunctionCompensate(enumAutoType) == _AUTO_FAIL)
                {
                    return _AUTO_FAIL;
                }
                break;           
        }
    }
        
    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Initialization for auto-color process
// Input Value  : enumAutoType: initialize type for auto-color
// Output Value : none
//--------------------------------------------------
void ScalerAutoInitializeAutoColor(EnumAutoColorType enumAutoType)
{
    BYTE ucClampEnd = 0;
    
#if(_ADC_SELF_CALIBRATION == _ON)
    if(enumAutoType == _AUTO_CALIBRATE_RGB)
    {
        // Enable calibration related setting
        ScalerAutoInitializeCalibration();
    }
    else
    {
        // Disable calibration voltage
        ScalerAutoResetCalibration();            
    }
#endif  

    // Enlarge clamp end    
    PDATA_WORD(0) = (WORD)((DWORD)GET_INPUT_TIMING_HTOTAL() * GET_INPUT_TIMING_HSYNCWIDTH() / GET_SYNC_H_PERIOD());
    PDATA_WORD(0) = ((GET_INPUT_TIMING_HSTART() - PDATA_WORD(0)) >> 1);
    ucClampEnd = ((PDATA_WORD(0) > 128) ? 128 : pData[1]);
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_01_SYNC_G_CLAMP_END, ucClampEnd);        

    // Load default ADC gain
    ScalerSetByte(P0_C0_RED_GAIN_MSG, _DEFAULT_GAIN);
    ScalerSetByte(P0_C1_GRN_GAIN_MSG, _DEFAULT_GAIN);
    ScalerSetByte(P0_C2_BLU_GAIN_MSG, _DEFAULT_GAIN);
    ScalerSetByte(P0_BE_ADC_RGB_GAIN_LSB, 0x00);

    // Load default ADC offset & SHA gain
    if((enumAutoType != _AUTO_TUNE_RGB_GAIN_ONLY) && (enumAutoType != _AUTO_TUNE_YPBPR_GAIN_ONLY))
    {
        ScalerSetByte(P0_C3_RED_OFFSET_MSG, _DEFAULT_OFFSET);
        ScalerSetByte(P0_C4_GRN_OFFSET_MSG, _DEFAULT_OFFSET);
        ScalerSetByte(P0_C5_BLU_OFFSET_MSG, _DEFAULT_OFFSET);
        ScalerSetByte(P0_BF_ADC_RGB_OFFSET_LSB, 0x00);
        ScalerSetByte(P0_DC_TEST_PTN_GD, 0x00); // Offset LSB 11

        // Load the default SHA gain
        ScalerADCPGAAdjust(_DEFAULT_SHA);        
    }

    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);  

    // Disable ADC channel swapping
    ScalerSetBit(CM_16_IPH_ACT_WID_H, ~(_BIT6 | _BIT5 | _BIT4), 0x00);        

    // Set ABL vertical start; Average 4 lines
    pData[0] = ((GET_INPUT_TIMING_VSTART() / 2) > 8) ? 8 : ((GET_INPUT_TIMING_VSTART() / 2) + 1);
    ScalerSetBit(P0_E3_ABL_CTRL2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | (pData[0] & 0x1F)));

    // Select RGB or YPbPr mode; Off-line ABL; 64-pixels in each line; Clear status;
    ScalerSetBit(P0_E2_ABL_CTRL1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), ((enumAutoType == _AUTO_TUNE_YPBPR) ? (_BIT7 | _BIT5) : (_BIT5)));

    // ABL starts at 4 pixels after the reference signal in each line
    ScalerSetByte(P0_E6_ABL_CTRL5, (ucClampEnd + 4));
    ScalerSetBit(P0_EF_ABL_CTRL8, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00); // EQ condition old mode

    // ABL old mode
    ScalerSetBit(P0_EC_ABL_R_NOISE_VALUE, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // Trigger status after max frame reached; Average value; HS trailing edge; EQ_MGN(0~3) = 0
    ScalerSetBit(P0_E8_ABL_CTRL7, ~(_BIT6 | _BIT5 | _BIT2 | _BIT1 | _BIT0), _BIT2);

    // Max frame/field count = 7; H width x1;
    ScalerSetBit(P0_E7_ABL_CTRL6, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));       
}

//--------------------------------------------------
// Description  : Update ADC gain for RGB / YPbPr color space
// Input Value  : ucGainBias: bias for RGB max level
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoUpdateAdcGain(BYTE ucGainBias)
{     
    BYTE ucGain = 0;
    BYTE ucMax = 0;
    BYTE ucIndex = 0;

    // Set to R channel for auto-balance new mode
    SET_AUTO_ADC_CHANNEL(_AUTO_RED_CHANNEL);

    // Enable image auto-balance new mode
    ScalerSetBit(CM_76_RED_NOISE_MARGIN, ~_BIT0, _BIT0);

    if(ScalerAutoCompareMeasure(_MEASURE_MAX) == _AUTO_FAIL)
    {
        ScalerSetBit(CM_76_RED_NOISE_MARGIN, ~_BIT0, 0);            
        return _AUTO_FAIL;
    }

    for(ucIndex = 0; ucIndex < 3; ++ucIndex)
    {      
        ucGain = ScalerGetByte(P0_C0_RED_GAIN_MSG + ucIndex);
        ucMax = ScalerGetByte(CM_84_AUTO_PHASE_3 + ucIndex);

#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))
        if(GET_TUNE_YPBPR_STATUS() == _TRUE)
        {
            if(ucIndex == 1)
            {
                pData[0] = _AUTO_Y_MAX_LEVEL - ucGainBias; // Y max level
            }
            else
            {
                pData[0] = _AUTO_PBPR_MAX_LEVEL - ucGainBias; // Pb/Pr max level         
            }
        }
        else
#endif        
        {
            pData[0] = _AUTO_RGB_MAX_LEVEL - ucGainBias; // RGB max level
        }
        
        // Check source validity; More consider needed
        if(ucMax < _ADC_MAXIMUM_TOLERANCE)
        {
            return _AUTO_FAIL;
        }      

        // Update ADC gain according to max level & measured maximum
        if(ucMax < pData[0])
        {
            ucMax = ScalerAutoConvertAdcGainStep(ucGain, pData[0], ucMax);        

#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))
            if((GET_TUNE_YPBPR_STATUS() == _TRUE) && (ucIndex != 1))            
            {
                // Gain step = STEP(1.75) for Pb/Pr channels
                ucMax = (BYTE)(((WORD)ucMax << 1) - (ucMax >> 2));
            }                                  
#endif            
            ucGain -= ((ucMax == 0) ? 1 : ucMax);            
        }
        else 
        {      
            // Target value exceeded. Rewind gain.        
            ucGain += (ucMax - pData[0]);
        }    
        
        ScalerSetByte(P0_C0_RED_GAIN_MSG + ucIndex, ucGain);
    }    

    // Disaable image auto-balance new mode
    ScalerSetBit(CM_76_RED_NOISE_MARGIN, ~_BIT0, 0);    
    
    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Color compensating for RGB channels
// Input Value  : enumAutoType -> auto-color type
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoCompensateRGB(EnumAutoColorType enumAutoType)
{
    if(ScalerAutoCompensateChannel(_AUTO_RED_CHANNEL, enumAutoType) == _AUTO_SUCCESS)
    {
        if(ScalerAutoCompensateChannel(_AUTO_GREEN_CHANNEL, enumAutoType) == _AUTO_SUCCESS)
        {
            if(ScalerAutoCompensateChannel(_AUTO_BLUE_CHANNEL, enumAutoType) == _AUTO_SUCCESS)    
            {
                return _AUTO_SUCCESS;
            }
        }
    }

    return _AUTO_FAIL;
}

//--------------------------------------------------
// Description  : Use ABL function to measure 256 pixels in the porch region and adjust offset accordingly
// Input Value  : ucTarget -> target value for ABL (1~16)
//                ucFrameCount -> total frame for ABL excution (1~7)
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoHardwareAbl(BYTE ucTarget, BYTE ucFrameCount)
{
    // Disable ABL
    ScalerSetBit(P0_E2_ABL_CTRL1, ~_BIT0, 0x00);
   
    // Set target value
    ScalerSetBit(P0_E4_ABL_CTRL3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), ((ucTarget - 1) << 4));

    // Reset ABL flag
    ScalerSetBit(P0_E2_ABL_CTRL1, ~(_BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT2 | _BIT1));

    // Start ABL
    ScalerSetBit(P0_E2_ABL_CTRL1, ~_BIT0, _BIT0);

    // For frame count = 0, wait 1 IVS
    if(ucFrameCount == 0x00)
    {
        ScalerTimerWaitForEvent(_EVENT_IVS);
    }

    // Wait until target frame count reached
    pData[0] = 0; // Valid frame counter
    pData[1] = 0; // Total frame counter
    while(pData[0] < ucFrameCount)    
    {
        if((ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE) || ((++pData[1]) > 8))
        {
            return _AUTO_FAIL;
        }

        // Check target value status
        if((ScalerGetBit(P0_E2_ABL_CTRL1, (_BIT3 | _BIT2 | _BIT1)) == (_BIT3 | _BIT2 | _BIT1)) ||
           (ScalerGetBit(P0_E2_ABL_CTRL1, _BIT0) == 0x00))
        {
            break;
        }

        // Check black level saturation
        if((ScalerGetByte(P0_E9_ABL_R_VALUE) == 0x00) || (ScalerGetByte(P0_EA_ABL_G_VALUE) == 0x00) || (ScalerGetByte(P0_EB_ABL_B_VALUE) == 0x00))
        {
            continue;
        }
        else
        {
            ++pData[0];
        }
    }

    // Wait additional 0.5 frame (for 60Hz)
    ScalerTimerDelayXms(9);

    // Stop ABL
    ScalerSetBit(P0_E2_ABL_CTRL1, ~_BIT0, 0x00);

    // Wait until ABL stop	
    ScalerTimerWaitForEvent(_EVENT_IVS);

    // Reset ADC offset LSB
    ScalerSetBit(P0_BF_ADC_RGB_OFFSET_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    

    // Further offset adjustment is needed only for RGB
#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))    
    if(GET_TUNE_YPBPR_STATUS() == _FALSE)
#endif    
    {
        --ucTarget;    
        ScalerSetByte(P0_C3_RED_OFFSET_MSG, (ScalerGetByte(P0_C3_RED_OFFSET_MSG) + ucTarget));
        ScalerSetByte(P0_C5_BLU_OFFSET_MSG, (ScalerGetByte(P0_C5_BLU_OFFSET_MSG) + ucTarget));          
        ScalerSetByte(P0_C4_GRN_OFFSET_MSG, (ScalerGetByte(P0_C4_GRN_OFFSET_MSG) + ucTarget));        
    }

    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Search in all SHA gains(3~0) and choose the maximum available one
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerAutoSearchShaGain(void)
{
    BYTE ucIndex = 0;

    if(ScalerAutoUpdateShaGain(GET_ADC_SHA_GAIN(), _SHA_GAIN_CHECK_MODE) == _AUTO_FAIL)
    {
        ucIndex = 13;    
        while(ucIndex != 0)
        {
            --ucIndex;
            if(ScalerAutoUpdateShaGain(ucIndex, _SHA_GAIN_CHECK_MODE) == _AUTO_SUCCESS)
            {
                ScalerAutoUpdateShaGain(ucIndex, _SHA_GAIN_WRITE_MODE);
                return;
            }
        }
    }
}

//--------------------------------------------------
// Description  : Update gain & offset according to new SHA gain
// Input Value  : ucShaGain -> target SHA gain (0 ~ 10)
//                 enumType -> _SHA_GAIN_CHECK_MODE: check target SHA gain, but not apply
//                             _SHA_GAIN_WRITE_MODE: check target SHA gain & apply it
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoUpdateShaGain(BYTE ucShaGain, EnumShaGainOptions enumType)
{
    BYTE ucIndex = 0;
    BYTE ucGainOffset[6] = {0};

    // Load ADC gain & offset
    ScalerRead(P0_C0_RED_GAIN_MSG, 6, ucGainOffset, _AUTOINC);
    
    // Calculate gain & offset according to target SHA gain
    if(ucShaGain != GET_ADC_SHA_GAIN())
    {        
        for(ucIndex = 0; ucIndex < 3; ++ucIndex)
        {
            // Calculate offset only for RGB & Y
#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))            
            if((GET_TUNE_YPBPR_STATUS() == _FALSE) || (ucIndex == 1))
#endif            
            {
                ucGainOffset[ucIndex + 3] = ScalerAutoConvertShaGain(ucGainOffset[ucIndex + 3], _ADC_OFFSET, GET_ADC_SHA_GAIN(), ucShaGain);
            }

            // Calculate gain
            ucGainOffset[ucIndex] = ScalerAutoConvertShaGain(ucGainOffset[ucIndex], _ADC_GAIN, GET_ADC_SHA_GAIN(), ucShaGain);
        }
    }

    // Check gain & offset range in _CHECK_MODE
    if(enumType == _SHA_GAIN_CHECK_MODE)
    {
        for(ucIndex = 0; ucIndex < 6; ++ucIndex)
        {
            if((ucGainOffset[ucIndex] < (128 - _ADC_WHITEBALANCE_TOLERANCE)) || 
               (ucGainOffset[ucIndex] > (128 + _ADC_WHITEBALANCE_TOLERANCE)))
            {
                return _AUTO_FAIL;
            }
        }
    }
    else if(ucShaGain != GET_ADC_SHA_GAIN())
    {
#if(_ADC_SELF_CALIBRATION == _ON)
        if(GET_CALIBRATION_STATUS() != _TRUE)
#endif        
        {
            // Apply margin values for gain & offset
            ucGainOffset[0] += _MARGIN_FOR_SHA_CHANGE;
            ucGainOffset[1] += _MARGIN_FOR_SHA_CHANGE;
            ucGainOffset[2] += _MARGIN_FOR_SHA_CHANGE;

            ucGainOffset[3] -= _MARGIN_FOR_SHA_CHANGE;
            ucGainOffset[4] -= _MARGIN_FOR_SHA_CHANGE;
            ucGainOffset[5] -= _MARGIN_FOR_SHA_CHANGE;     
        }

        ScalerWrite(P0_C0_RED_GAIN_MSG, 6, ucGainOffset, _AUTOINC);
        ScalerADCPGAAdjust(ucShaGain);
    }
    
    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Calculate ADC gain/offset according to SHA gain
// Input Value  : ucValue -> gain/offset value
//                enumType -> indicate gain or offset
//                ucShaFrom -> convert from
//                ucShaTo -> convert to
// Output Value : converted value
//--------------------------------------------------
BYTE ScalerAutoConvertShaGain(BYTE ucValue, EnumADCGainOffset enumType, BYTE ucShaFrom, BYTE ucShaTo)
{   
    if(ucShaFrom != ucShaTo)
    {
        if(ucShaTo > 10)
        {
            // 11~12 -> [1.35:1.5] * 2000
            PDATA_WORD(0) = 2700 + (ucShaTo - 11) * 300;
        }
        else
        {
            // 0~10 -> [0.792:1.208] * 2000
            PDATA_WORD(0) = 1585 + ucShaTo * 83;
        }

        if(ucShaFrom > 10)
        {
            PDATA_WORD(1) = 2700 + (ucShaFrom - 11) * 300;        
        }
        else
        {
            PDATA_WORD(1) = 1585 + ucShaFrom * 83;        
        }        
        
        if(enumType == _ADC_GAIN)
        {
            ucValue = (BYTE)((((DWORD)ucValue + 64) * PDATA_WORD(0) / PDATA_WORD(1)) - 64); // Gain
        }
        else
        {
            ucValue = (BYTE)((DWORD)ucValue * PDATA_WORD(1) / PDATA_WORD(0)); // Offset
        }
    }

    return ucValue;
}

//--------------------------------------------------
// Description  : Calculate ADC gain/offset according to SHA gain
// Input Value  : ucGain    -> ADC gain value
//                ucTarget  -> target level
//                ucCurrent -> measured current status
// Output Value : converted gain step
//--------------------------------------------------
BYTE ScalerAutoConvertAdcGainStep(BYTE ucGain, BYTE ucTarget, BYTE ucCurrent)
{    
    BYTE ucResult = 0;

    if(ucTarget > ucCurrent)
    {
        ucResult = (BYTE)(((DWORD)(ucTarget - ucCurrent) * ((WORD)ucGain + 64)) / ucTarget);
    }

    return ucResult;
}
      
//--------------------------------------------------
// Description  : Color compensation for a particular ADC channel
// Input Value  : ucColor -> select a color channel
//                enumAutoType -> auto-color type
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoCompensateChannel(BYTE ucColor, EnumAutoColorType enumAutoType)
{
    BYTE ucMainTone = 0;
    BYTE ucGain = 0;
    
    // Set channel for image auto-function
    SET_AUTO_ADC_CHANNEL(ucColor);
    ucGain = GET_AUTO_ADC_GAIN();
    
    // Measure main-tone for max
    if(ScalerAutoMainToneMeasure(255, &ucMainTone) == _AUTO_FAIL)
    {
        return _AUTO_FAIL;
    }

    if(enumAutoType == _AUTO_TUNE_RGB_GAIN_ONLY)
    {
        // Measure the average min value
        if(ScalerAutoAccumulationMeasure(_MEASURE_RGB_MIN, 0) == _AUTO_FAIL)
        {
            return _AUTO_FAIL;
        }        
    }
    else
    {
        // Compensate offset
        if(ScalerAutoCompensateOffset(ucColor) == _AUTO_FAIL)
        {
            return _AUTO_FAIL;
        }
    }

    // Update gain from swing = main-tone for max - average min
    ucGain -= ScalerAutoConvertAdcGainStep(ucGain, 255, HIBYTE(((WORD)ucMainTone << 8) - GET_AUTO_RESULT_WORD0()));
    SET_AUTO_ADC_GAIN(ucGain);

    if(enumAutoType != _AUTO_TUNE_RGB_GAIN_ONLY)
    {
        // Double-check for offset
        if(ScalerAutoCompensateOffset(ucColor) == _AUTO_FAIL)
        {
            return _AUTO_FAIL;
        }

        // Set gain bias level from current black level
        pData[9] = (GET_AUTO_RESULT_WORD0() > (WORD)_BLACK_LEVEL_THRESHOLD) + _PANEL_ADC_OFFSET_BIAS;

        // Adjust ADC offset by panel defined bias
        SET_AUTO_ADC_OFFSET(GET_AUTO_ADC_OFFSET() + _PANEL_ADC_OFFSET_BIAS);        

        // Adjust ADC gain by calculated bias
        pData[9] = ScalerAutoConvertAdcGainStep(ucGain, 255, (255 - pData[9]));
        SET_AUTO_ADC_GAIN(ucGain - pData[9]);        
    }

    ucGain += ((SBYTE)_PANEL_ADC_GAIN_BIAS);
    SET_AUTO_ADC_GAIN(ucGain);
    
    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Compensation for 0-level
// Input Value  : ucColor: select a color channel
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoCompensateOffset(BYTE ucColor)
{
    BYTE ucOffset = 0;
    WORD usResult = 0;

    SET_AUTO_ADC_CHANNEL(ucColor);
    ucOffset = GET_AUTO_ADC_OFFSET();
    
    // Measure the average min value
    if(ScalerAutoAccumulationMeasure(_MEASURE_RGB_MIN, 0) == _AUTO_FAIL)
    {
        return _AUTO_FAIL;
    }
    usResult = GET_AUTO_RESULT_WORD0();

    if(HIBYTE(usResult) > 0)
    {
        // Increase offset by (minimum - 1)
        ucOffset += ((HIBYTE(usResult) == 1) ? 1 : (HIBYTE(usResult) - 1));    
    }
    else if(usResult > (WORD)_BLACK_LEVEL_THRESHOLD)
    {
        ++ucOffset;
    }

    SET_AUTO_ADC_OFFSET(ucOffset);
    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Set boundary for image auto-function measure
// Input Value  : enumBoundary -> boundary type selection
// Output Value : None
//--------------------------------------------------
void ScalerAutoSetBoundary(EnumMeasureBoundary enumBoundary)
{
    switch(enumBoundary)
    {
        case _MEASURE_PORCH_REGION:
            ScalerMeasureAutoFuncHBoundInitial(GET_INPUT_TIMING_HSTART(), (GET_INPUT_TIMING_HSTART() + 127));

            PDATA_WORD(0) = ((GET_INPUT_TIMING_VSTART() / 2) > 8) ? 8 : ((GET_INPUT_TIMING_VSTART() / 2) + 1); // V start            
            ScalerMeasureAutoFuncVBoundInitial(PDATA_WORD(0), (PDATA_WORD(0) + 1));            
            break;

        case _MEASURE_ACTIVE_REGION:
            ScalerMeasureAutoFuncHBoundInitial(GET_INPUT_TIMING_HSTART(), (GET_INPUT_TIMING_HSTART() + GET_INPUT_TIMING_HWIDTH()));
            ScalerMeasureAutoFuncVBoundInitial(GET_INPUT_TIMING_VSTART(), (GET_INPUT_TIMING_VSTART() + GET_INPUT_TIMING_VHEIGHT()));            
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Measure the maximum / minimum value using compare measure
// Input Value  : enumType -> measure for maximum / minimum value
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoCompareMeasure(EnumMeasureType enumType)
{  
    BYTE ucMeasureType = 0;

    // Stop image auto-function measure
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, 0x00);

    // Disable field select; Enable LPF filter; Disable hardware acceleration;
    ScalerSetBit(CM_7A_AUTO_ADJ_CTRL0, ~(_BIT7 | _BIT5 | _BIT4), _BIT5);  

    switch(enumType)
    {            
        case _MEASURE_RGB_MIN:
            pData[0] = _MEASURE_PORCH_REGION;
            ucMeasureType = 0;
            break;
            
        case _MEASURE_YPBPR_MIN:                           
            pData[0] = _MEASURE_ACTIVE_REGION;
            ucMeasureType = 0;            
            break;

        case _MEASURE_MAX:
        default:        
            pData[0] = _MEASURE_ACTIVE_REGION;
            ucMeasureType = _BIT5;
            break;          
    }   

    // Set measure boundary
    ScalerAutoSetBoundary(pData[0]);

    // Normal boundary; Software mode; Measure maximum / minimum; Compare mode; Auto-balance; Start measure;
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT7| _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT1 | _BIT0), (ucMeasureType | _BIT0));     

    if(ScalerMeasureAutoFuncWaitFinish() == _FALSE)
    {
        return _AUTO_FAIL;
    }

    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Measure the maximum / minimum value using compare measure
// Input Value  : enumType -> maximum / minimum measure,
//                ucThreshold  -> threshold for accumulation samples
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoAccumulationMeasure(EnumMeasureType enumType, BYTE ucThreshold)
{
    // Stop image auto-function measure
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, 0x00);

    // Disable field select; Disable LPF filter; Disable hardware acceleration;
    ScalerSetBit(CM_7A_AUTO_ADJ_CTRL0, ~(_BIT7 | _BIT5 | _BIT4), 0x00);

    switch(enumType)
    {
        case _MEASURE_YPBPR_MIN:
            // Measure the pixel number BELOW the threshold
            ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT5, 0x00);
            ucThreshold ^= 0xFF;
            pData[0] = _MEASURE_ACTIVE_REGION;
            break;
                    
        case _MEASURE_RGB_MIN:
            pData[0] = _MEASURE_PORCH_REGION;
            break;

        case _MEASURE_MAX:
        default:
            pData[0] = _MEASURE_ACTIVE_REGION;
            break;
    }

    // Set measure boundary
    ScalerAutoSetBoundary(pData[0]);

    // Set threshold
    ScalerSetByte(CM_79_DIFF_THRESHOLD, ucThreshold);    

    // Normal boundary; Software mode; Measure maximum; Accumulation mode; Auto-balance; Start auto-function
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT7| _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT0));    

    if(ScalerMeasureAutoFuncWaitFinish() == _FALSE)
    {
        return _AUTO_FAIL;
    }

    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Search for ADC main tone between (start_level - 4) & start_level
// Input Value  : ucStartLevel -> search start level (must >= 4)
//                ucMainTone   -> address for main tone within search levels
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoMainToneMeasure(BYTE ucStartLevel, BYTE *ucMainTone)
{
    BYTE ucIndex = 0;

    // Stop auto-function
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, 0x00);

    ScalerAutoSetBoundary(_MEASURE_MAX);

    // Set default values
    *ucMainTone = 3;    
    PDATA_DWORD(1) = 0; // Previous sum
    PDATA_DWORD(2) = 0; // Previous level
    PDATA_DWORD(3) = 0; // Max difference
    if(ucStartLevel != 255)
    {
        ++ucStartLevel;
    }
    
    // Default threshold at start_level
    ScalerSetByte(CM_79_DIFF_THRESHOLD, ucStartLevel);    

    // Disable field select; Disable LPF filter; Disable hardware acceleration;
    ScalerSetBit(CM_7A_AUTO_ADJ_CTRL0, ~(_BIT7 | _BIT5 | _BIT4), 0x00);

    // HW auto for 5 steps; Step size = 1;
    ScalerSetByte(CM_7B_HW_AUTO_PHASE_CTRL0, 0x20);

    // Initial phase = current phase
    ScalerSetByte(CM_7C_HW_AUTO_PHASE_CTRL1, (ScalerGetByte(P1_B4_PLLPHASE_CTRL1) & ~(_BIT7)));
    
    // HW auto-phase; Max value; Accumulation; Auto-balance; Start auto-function;
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | _BIT4 | _BIT0));
  
    if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FAIL)
    {
        return _AUTO_FAIL;
    }
   
    for(ucIndex = 0; ucIndex < 5; ++ucIndex)
    {
        if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FAIL)
        {
            return _AUTO_FAIL;
        }
        // Decrease threshold
        ScalerSetByte(CM_79_DIFF_THRESHOLD, (ScalerGetByte(CM_79_DIFF_THRESHOLD) - 1));        

        // Get pixel count for current level
        PDATA_DWORD(0) = (GET_AUTO_RESULT_DWORD() - PDATA_DWORD(1)) / (ucStartLevel - ucIndex);

        // Store current accumulation result
        PDATA_DWORD(1) = GET_AUTO_RESULT_DWORD();

        // If start-level != 255, skip the first iteration.
        if((ucIndex == 0) && (ucStartLevel != 255))
        {
            continue;
        }        

        // If the measured pixels is less than 2 vertical line, ignore it.
        if(PDATA_DWORD(0) < (GET_INPUT_TIMING_VHEIGHT() << 1))
        {
            PDATA_DWORD(0) = 0;
        }

        if(PDATA_DWORD(0) < PDATA_DWORD(2))
        {
            // Pixel decreases. Stop main-tone search.
            break;
        }

        PDATA_DWORD(2) = PDATA_DWORD(0) - PDATA_DWORD(2);

        // Compare the difference between successive levels & the maximum difference
        if(PDATA_DWORD(2) > PDATA_DWORD(3))
        {
            PDATA_DWORD(3) = PDATA_DWORD(2);
            *ucMainTone = ucIndex;
        }

        // Store current level
        PDATA_DWORD(2) = PDATA_DWORD(0);
    }

    // Stop auto-function        
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, 0x00);
    
    *ucMainTone = (ucStartLevel - *ucMainTone);
    
    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Return the auto-color result
// Input Value  : stAdcData -> ADC data structure pointer
// Output Value : None
//--------------------------------------------------
void ScalerAutoGetAutoColorResult(StructAdcDataType *stAdcData)
{
    ScalerRead(P0_C0_RED_GAIN_MSG, 3, stAdcData->ucAdcGainMSB, _AUTOINC);
    ScalerRead(P0_C3_RED_OFFSET_MSG, 3, stAdcData->ucAdcOffsetMSB, _AUTOINC);    
    stAdcData->ucAdcPGA = GET_ADC_SHA_GAIN();    
    stAdcData->ucAdcGainLSB[0] = 0;
    stAdcData->ucAdcGainLSB[1] = 0;
    stAdcData->ucAdcGainLSB[2] = 0;
    stAdcData->ucAdcOffsetLSB[0] = 0;
    stAdcData->ucAdcOffsetLSB[1] = 0;
    stAdcData->ucAdcOffsetLSB[2] = 0;
}

#if(_YPBPR_SUPPORT == _ON)

#if(_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE)
//--------------------------------------------------
// Description  : Compensate ADC gain / offset for YPbPr color space
// Input Value  : enumAutoType -> auto-color type
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoCompensateYPbPr(EnumAutoColorType enumAutoType)
{
    BYTE ucGain = 0;
    BYTE ucMainTone = 0;
    BYTE ucMaxLevel = 0;
    BYTE ucIndex = 0;

    if(enumAutoType != _AUTO_TUNE_YPBPR_GAIN_ONLY)
    {
        // Double check for offset
        if(ScalerAutoHardwareAbl(16, 2) == _AUTO_FAIL)
        {
            return _AUTO_FAIL;
        }
    }

    // Compensate starts from Y channel
    SET_AUTO_ADC_CHANNEL(_AUTO_GREEN_CHANNEL);
    ucMaxLevel = _AUTO_Y_MAX_LEVEL;

    for(ucIndex = 0; ucIndex < 3; ++ucIndex)    
    {
        ucGain = GET_AUTO_ADC_GAIN();

        // Measure main tone for each channel
        if(ScalerAutoMainToneMeasure(ucMaxLevel, &ucMainTone) == _AUTO_FAIL)
        {
            return _AUTO_FAIL;
        }                
        ucMaxLevel = ScalerAutoConvertAdcGainStep(ucGain, ucMaxLevel, ucMainTone);

        SET_AUTO_ADC_GAIN(ucGain - ucMaxLevel);        
        SET_AUTO_ADC_NEXT_CHANNEL();
        ucMaxLevel = _AUTO_PBPR_MAX_LEVEL;        
    }
   
    return _AUTO_SUCCESS;    
}
#endif // End of #if(_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE)

#if(_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_FORMULA)
//--------------------------------------------------
// Description  : Calculate ADC gain/offset for YPbPr from RGB auto-color result 
// Input Value  : stAdcData: balanced gain/offset for RGB
// Output Value : balanced gain/offset for YPbPr from calculation
//--------------------------------------------------
StructAdcDataType ScalerAutoBalanceYPbPrFromFormula(StructAdcDataType * stAdcData)
{
    StructAdcDataType stYPbPrData = {0};
    
    stYPbPrData = *stAdcData;
  
    // Check for B/R swap. Assume default: Pr, Y, Pb
    stYPbPrData.ucAdcOffsetMSB[0] = ScalerAutoConvertShaGain(stAdcData->ucAdcOffsetMSB[0], _ADC_OFFSET, stAdcData->ucAdcPGA, _DEFAULT_SHA) + _AUTO_PR_OFFSET_BIAS; // Pr
    stYPbPrData.ucAdcOffsetMSB[2] = ScalerAutoConvertShaGain(stAdcData->ucAdcOffsetMSB[2], _ADC_OFFSET, stAdcData->ucAdcPGA, _DEFAULT_SHA) + _AUTO_PB_OFFSET_BIAS; // Pb
    stYPbPrData.ucAdcGainMSB[0] += (BYTE)(((DWORD)stYPbPrData.ucAdcGainMSB[0] + 64) * 31 / 224) + _AUTO_PR_GAIN_BIAS; // Pr
    stYPbPrData.ucAdcGainMSB[2] += (BYTE)(((DWORD)stYPbPrData.ucAdcGainMSB[2] + 64) * 31 / 224) + _AUTO_PB_GAIN_BIAS; // Pb
    
    stYPbPrData.ucAdcOffsetMSB[1] = stYPbPrData.ucAdcOffsetMSB[1] + _AUTO_Y_OFFSET_BIAS;// Y
    stYPbPrData.ucAdcGainMSB[1] += (BYTE)(((DWORD)stYPbPrData.ucAdcGainMSB[1] + 64) * 36 / 219) + _AUTO_Y_GAIN_BIAS; // Y
    
    return stYPbPrData;
}
#endif
#endif //  End of #if(_YPBPR_SUPPORT == _ON)

#if(_ADC_SELF_CALIBRATION == _ON)
//--------------------------------------------------
// Description  : Update ADC gain for RGB self-calibration
// Input Value  : ucBias: bias level from max level
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoUpdateAdcGainCalibrationRGB(BYTE ucGainBias)
{
    BYTE ucIndex = 0;
    BYTE ucGain = 0;

    // Measure maximum value for RGB
    if(ScalerAutoAblMeasure() == _AUTO_FAIL)
    {
        return _AUTO_FAIL;
    }

    // Update gain for each channel
    for(ucIndex = 0; ucIndex < 3; ++ucIndex)
    {      
        ucGain = ScalerGetByte(P0_C0_RED_GAIN_MSG + ucIndex);
        pData[0] = ScalerGetByte(P0_E9_ABL_R_VALUE + ucIndex); // RGB max value
        pData[1] = _AUTO_RGB_MAX_LEVEL - ucGainBias; // RGB target value
        
        // Update ADC gain according to max level & measured maximum
        if(pData[0] < pData[1])
        {
            // Calculate gain step
            pData[2] = ScalerAutoConvertAdcGainStep(ucGain, pData[1], pData[0]);        

            if(pData[2] == 0x00)
            {
                --ucGain;
            }
            else
            {
                ucGain -= pData[2];
            }           
        }
        else 
        {      
            // Target value exceeded. Rewind gain.        
            ucGain += (pData[0] - pData[1]);
        }    

        // Apply gain step
        ScalerSetByte((P0_C0_RED_GAIN_MSG + ucIndex), ucGain);
    }    

    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Compensate ADC gain / offset for RGB self-calibration
// Input Value  : enumAutoType -> auto-color type
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoCompensateCalibrationRGB(EnumAutoColorType enumAutoType)
{     
    enumAutoType = enumAutoType;
    
    // Apply gain bias
    ScalerSetByte(P0_C0_RED_GAIN_MSG, (ScalerGetByte(P0_C0_RED_GAIN_MSG) + _CALIBRATION_R_GAIN_BIAS));
    ScalerSetByte(P0_C1_GRN_GAIN_MSG, (ScalerGetByte(P0_C1_GRN_GAIN_MSG) + _CALIBRATION_G_GAIN_BIAS));
    ScalerSetByte(P0_C2_BLU_GAIN_MSG, (ScalerGetByte(P0_C2_BLU_GAIN_MSG) + _CALIBRATION_B_GAIN_BIAS));

    // Check offset original signal level
    ScalerSetBit(P0_D2_ADC_SOG_CMP, ~(_BIT4 | _BIT2 | _BIT1 | _BIT0), 0x00);
    if(ScalerAutoHardwareAbl(4, 4) == _AUTO_FAIL)
    {
        return _AUTO_FAIL;
    }

    // Apply R & B offset bias
    ScalerSetByte(P0_C3_RED_OFFSET_MSG, (ScalerGetByte(P0_C3_RED_OFFSET_MSG) - _CALIBRATION_R_OFFSET_BIAS));
    ScalerSetByte(P0_C4_GRN_OFFSET_MSG, (ScalerGetByte(P0_C4_GRN_OFFSET_MSG) - _CALIBRATION_G_OFFSET_BIAS));    
    ScalerSetByte(P0_C5_BLU_OFFSET_MSG, (ScalerGetByte(P0_C5_BLU_OFFSET_MSG) - _CALIBRATION_B_OFFSET_BIAS));

    return _AUTO_SUCCESS;
}

//--------------------------------------------------
// Description  : Initialization for ADC self-calibration
// Input Value  : none
// Output Value : _AUTO_FAIL or _AUTO_SUCCESS
//--------------------------------------------------
void ScalerAutoInitializeCalibration(void)
{
    // Initial VGA data path
    ScalerSyncVgaScanInitial();
    ScalerADCClampMode(_COLOR_SPACE_RGB);

    // Enable calibration mode; Enable calibration voltage; Set voltage low; Voltage from 3.3V
    ScalerSetBit(P0_CD_ADC_V_BIAS1, ~_BIT7, _BIT7);
    ScalerSetByte(P0_D2_ADC_SOG_CMP, (_BIT7 | _BIT5 | _BIT4));    

    // Calibration new-mode
    ScalerSetBit(P0_D8_TEST_PTN_POS_H, ~_BIT2, _BIT2);

    // Set DPLL free-run    
    ScalerMDomainSetDisplayFormat(_FREE_RUN_NO_INPUT);

    // Disable DPLL spread spectrum
    ScalerPllSetDpllSsc(_DCLK_SPREAD_SPEED, _OFF);    
    
    // Switch sync-processor HS/VS source from D-domain
    ScalerSetBit(CM_0B_POWER_CTRL2, ~_BIT1, _BIT1);
    ScalerSetBit(CM_47_SYNC_SELECT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT2));
    ScalerSetBit(CM_48_SYNC_INVERT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT2));
    ScalerSetBit(CM_49_SYNC_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));

    // Set APLL H total = Display H total
    ScalerAPLLAdjust(_PANEL_DH_TOTAL, (WORD)((DWORD)_PANEL_PIXEL_CLOCK * 10000 / _PANEL_DH_TOTAL));

    // Set ADC bandwidth according to DPLL rate
    ScalerADCBandWidthSetting(_PANEL_PIXEL_CLOCK);
    
    // Disable double buffer; Input ADC pixel format; Enable input sampling;
    ScalerSetBit(CM_10_VGIP_CTRL, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0), _BIT0); 
}

//--------------------------------------------------
// Description  : Reset for ADC self-calibration
// Input Value  : none
// Output Value : _AUTO_FAIL or _AUTO_SUCCESS
//--------------------------------------------------
void ScalerAutoResetCalibration(void)
{
    // Turn off calibration signal
    ScalerSetByte(P0_D2_ADC_SOG_CMP, 0x00); 
    ScalerSetBit(P0_CD_ADC_V_BIAS1, ~_BIT7, 0x00);

    // Set sync processsor HS/VS source from ADC
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT2, 0x00);
}

//--------------------------------------------------
// Description  : Measure the average value using ABL
// Input Value  : none
// Output Value : _AUTO_SUCCESS or _AUTO_FAIL
//--------------------------------------------------
EnumAutoResult ScalerAutoAblMeasure(void)
{
    BYTE ucOffset[3] = {0};

    // Set calibration voltage to high
    ScalerSetBit(P0_D2_ADC_SOG_CMP, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // Store offset
    ScalerRead(P0_C3_RED_OFFSET_MSG, 3, ucOffset, _AUTOINC);

    // Measure RGB max using ABL
    if(ScalerAutoHardwareAbl(16, 0) == _AUTO_FAIL)
    {
        return _AUTO_FAIL;
    }
    
    // Restore offset
    ScalerWrite(P0_C3_RED_OFFSET_MSG, 3, ucOffset, _AUTOINC);

    // Set calibration voltage to low
    ScalerSetBit(P0_D2_ADC_SOG_CMP, ~(_BIT2 | _BIT1 | _BIT0), 0x00);        
    
    return _AUTO_SUCCESS;
}
#endif // End of #if(_ADC_SELF_CALIBRATION == _ON)
#endif // End of #if(_VGA_SUPPORT == _ON)
