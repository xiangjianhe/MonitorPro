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
// ID Code      : UserCommonAdjust.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_ADJUST__

#include "UserCommonInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_ENERGY_STAR_SUPPORT == _ON)
//--------------------------------------------------
// Macro of DCR RGB average value for Energy Star
//--------------------------------------------------
#define GET_ES_DCR_CUR_RGB_AVG_VALUE()              (g_stESDcrInfo.ucESDcrCurRGBAvgValue)
#define SET_ES_DCR_CUR_RGB_AVG_VALUE(x)             (g_stESDcrInfo.ucESDcrCurRGBAvgValue = (x))

//--------------------------------------------------
// Macro of DCR RGB average value for Energy Star
//--------------------------------------------------
#define GET_ES_DCR_PRE_RGB_AVG_VALUE()              (g_stESDcrInfo.ucESDcrPreRGBAvgValue)
#define SET_ES_DCR_PRE_RGB_AVG_VALUE(x)             (g_stESDcrInfo.ucESDcrPreRGBAvgValue = (x))
#endif // End of #if(_ENERGY_STAR_SUPPORT == _ON)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_ENERGY_STAR_SUPPORT == _ON)
StructESDcrInfo g_stESDcrInfo = {0};
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
WORD UserCommonAdjustGetAdcClockRange(BYTE ucPar);
void UserCommonAdjustClock(WORD usUserIHTotal);
void UserCommonAdjustPhase(BYTE ucPhase);
#endif

WORD UserCommonAdjustGetHPositionRange(BYTE ucPar);
WORD UserCommonAdjustGetHPositionHBiasValue(void);
WORD UserCommonAdjustGetVPositionRange(BYTE ucPar);
WORD UserCommonAdjustGetVPositionVBiasValue(void);
void UserCommonAdjustHPosition(BYTE ucUserHPosition);
void UserCommonAdjustVPosition(BYTE ucUserVPosition);

BYTE UserCommonAdjustRealValueToPercent(WORD usRealValue, WORD usMax, WORD usMin, WORD usCenter); // Wendy edit 20120222
WORD UserCommonAdjustPercentToRealValue(BYTE ucPercentValue, WORD usMax, WORD usMin, WORD usCenter);

#if(_OVERSCAN_SUPPORT == _ON)
void UserCommonAdjustOverScan(void);
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
void UserCommonAdjustUltraVivid(EnumColorSpace enumColorFormat);
#endif

#if(_I_DITHER_SUPPORT == _ON)
void UserCommonAdjustIDither(void);
#endif

#if(_ENERGY_STAR_SUPPORT == _ON)
void UserCommonAdjustESDcrSearchTargetPWM(void);
void UserCommonAdjustESDcrAdjust(void);
void UserCommonAdjustESDcrAdjustPWM(void);
void UserCommonAdjustESDcrProcess(bit bOnOff);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check if the ADC clock (IHTotal) is out of range. Range = (BackPorch + FrontPorch) * 2 / 5 .
// Input Value  : usClock   --> ADC Clock (IHTotal)
// Output Value : Return _TRUE if not out of range
//--------------------------------------------------
WORD UserCommonAdjustGetAdcClockRange(BYTE ucPar)
{
    WORD usDelta1 = 0;
    WORD usDelta2 = 0;
    WORD usDelta = 0;
    
    usDelta1 = GET_ADC_LIMIT_CLOCK() - g_stVGAModeUserData.usCenterClock;

    usDelta2 = g_stVGAModeUserData.usCenterClock - ScalerVgipGetCaptureHStartPosition() - ScalerVgipGetCaptureHWidth();

    usDelta = usDelta1 < usDelta2 ? usDelta1 : usDelta2;

    if(ucPar == _GET_CLOCKRANGE_MAX)
    {
        if(usDelta < _CLOCK_BIAS)
        {
            return (g_stVGAModeUserData.usCenterClock + usDelta);
        }
        else
        {
            return (g_stVGAModeUserData.usCenterClock + _CLOCK_BIAS);            
        }
    }
    else if(ucPar == _GET_CLOCKRANGE_MIN)
    {
        if(usDelta < _CLOCK_BIAS)
        {
            return (g_stVGAModeUserData.usCenterClock - usDelta);
        }
        else
        {
            return (g_stVGAModeUserData.usCenterClock - _CLOCK_BIAS);
        }
    }

    return (g_stVGAModeUserData.usCenterClock);
}

//--------------------------------------------------
// Description  : Adjust clock.
// Input Value  : usUserIHTotal --> OSD Value(0~100) or Real Value 
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustClock(WORD usUserIHTotal)
{
#if(_AUTO_CLOCK_SAVE_VALUE_OPTION == _CLOCK_SAVE_PERCENT_VALUE)    

    WORD usClockRangeMax = 0;
    WORD usClockRangeMin = 0;

    usClockRangeMax = UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MAX);
    usClockRangeMin = UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN); 
    usUserIHTotal = UserCommonAdjustPercentToRealValue((BYTE)usUserIHTotal, usClockRangeMax, usClockRangeMin, (((usClockRangeMax - usClockRangeMin) / 2) + usClockRangeMin));

#endif 

    ScalerGlobalWatchDog(_DISABLE);    
    
    ScalerAPLLFastLockAdjust(usUserIHTotal);        

    ScalerGlobalWatchDog(_ENABLE);         
}

//--------------------------------------------------
// Description  : Adjust phase
// Input Value  : ucPhase --> phase value
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustPhase(BYTE ucPhase)
{
    ucPhase = UserCommonAdjustPercentToRealValue(ucPhase, _ADJUST_PHASE_MAX, _ADJUST_PHASE_MIN, _ADJUST_PHASE_CENTER);
    
    ScalerGlobalWatchDog(_DISABLE);    

    ScalerPLLSetPhase(ucPhase, UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IVFREQ));

    ScalerGlobalWatchDog(_ENABLE);     
}

#endif // End of #if(_VGA_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Get Max or Min H-Position
// Input Value  : ucPar--> Max or Min paramater
// Output Value : Max or Min H-Position
//--------------------------------------------------
WORD UserCommonAdjustGetHPositionRange(BYTE ucPar)
{
    WORD usDeltaIHWidthOverScan = 0;
    WORD usIHWidth = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usIHWidth = UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IHWIDTH);
    }
    else
#endif
    {
        usIHWidth = GET_ACTIVE_H_WIDTH();
    }

#if(_OVERSCAN_SUPPORT == _ON)
    if(UserAdjustCheckOverScan() == _TRUE)
    {
        if(usIHWidth >= ScalerVgipGetCaptureHWidth())
        {
            usDeltaIHWidthOverScan = ((usIHWidth - ScalerVgipGetCaptureHWidth()) / 2);
        }
    }
#endif

#if(_3D_SUPPORT == _ON)
        if((Scaler3DGetInputFormat() == _SIDE_BY_SIDE_HALF) && (ScalerVgipGetCaptureHWidth() == (usIHWidth >> 1)))
        {
            usDeltaIHWidthOverScan = (usIHWidth - ScalerVgipGetCaptureHWidth());
        }
#endif

    if(ucPar == _GET_HPOSITIONRANGE_MAX)
    {
#if(_VGA_SUPPORT == _ON)
        if(SysSourceGetSourceType() == _SOURCE_VGA)
        {
                return (g_stVGAModeUserData.usCenterHPosition + usDeltaIHWidthOverScan + _HPOSITION_BIAS);
            }
        else
#endif
        {

                return (GET_ACTIVE_H_START() + usDeltaIHWidthOverScan + _HPOSITION_BIAS);
            }
        }        
    else if(ucPar == _GET_HPOSITIONRANGE_MIN)
    {
#if(_VGA_SUPPORT == _ON)
        if(SysSourceGetSourceType() == _SOURCE_VGA)
        {
                return (g_stVGAModeUserData.usCenterHPosition + usDeltaIHWidthOverScan - _HPOSITION_BIAS);
            }
            else
#endif
            {            
                return (GET_ACTIVE_H_START() + usDeltaIHWidthOverScan - _HPOSITION_BIAS);
            }
        }        
    else
    {
#if(_VGA_SUPPORT == _ON)
        if(SysSourceGetSourceType() == _SOURCE_VGA)
        {
                return (g_stVGAModeUserData.usCenterHPosition + usDeltaIHWidthOverScan);
            }
        else
#endif
        {
            
                return (GET_ACTIVE_H_START() + usDeltaIHWidthOverScan);

        }        
    }
}

//--------------------------------------------------
// Description  : Get HPosition H Bias Value
// Input Value  : None
// Output Value : H Bias Value
//--------------------------------------------------
WORD UserCommonAdjustGetHPositionHBiasValue(void)
{   
    WORD usHBias = 0;
    WORD usDeltaIHWidthOverScan = 0;
    WORD usIHWidth = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usIHWidth = UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IHWIDTH);
    }
    else
#endif
    {
        usIHWidth = GET_ACTIVE_H_WIDTH();
    }

#if(_OVERSCAN_SUPPORT == _ON)
    if(UserAdjustCheckOverScan() == _TRUE)
    {
        if(usIHWidth >= ScalerVgipGetCaptureHWidth())
        {
            usDeltaIHWidthOverScan = ((usIHWidth - ScalerVgipGetCaptureHWidth()) / 2);
        }
    }
#endif    

#if(_3D_SUPPORT == _ON)
        if((Scaler3DGetInputFormat() == _SIDE_BY_SIDE_HALF) && (ScalerVgipGetCaptureHWidth() == (usIHWidth >> 1)))
        {
            usDeltaIHWidthOverScan = (usIHWidth - ScalerVgipGetCaptureHWidth());
        }
#endif
        
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usHBias = ((g_stVGAModeUserData.usCenterHPosition + usDeltaIHWidthOverScan - ScalerVgipGetCaptureHStartPosition()) <= (_MAX_H_POSITION_RANGE / 2)) ? 
                  (g_stVGAModeUserData.usCenterHPosition + usDeltaIHWidthOverScan - ScalerVgipGetCaptureHStartPosition() - 1) : (_MAX_H_POSITION_RANGE / 2);
    }
    else
#endif
    {
        usHBias = (GET_ACTIVE_H_START() + usDeltaIHWidthOverScan - ScalerVgipGetCaptureHStartPosition()) <= (_MAX_H_POSITION_RANGE / 2) ? 
                  (GET_ACTIVE_H_START() + usDeltaIHWidthOverScan - ScalerVgipGetCaptureHStartPosition() - 1) : (_MAX_H_POSITION_RANGE / 2);
    }
        
    return usHBias;
}

//--------------------------------------------------
// Description  : Get Max or Min V-Position
// Input Value  : ucPar--> Max or Min paramater
// Output Value : Max or Min V-Position
//--------------------------------------------------
WORD UserCommonAdjustGetVPositionRange(BYTE ucPar)
{        
    WORD usDeltaIVHeightOverScan = 0;
    WORD usDeltaIVHeightUnderScan = 0;
    WORD usIVHeight = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usIVHeight = UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IVHEIGHT);
    }
    else
#endif
    {
        usIVHeight = GET_ACTIVE_V_HEIGHT();
    }
  
#if(_OVERSCAN_SUPPORT == _ON)    
    if(UserAdjustCheckOverScan() == _TRUE)
    {
        if(usIVHeight >= ScalerVgipGetCaptureVHeight())
        {
            usDeltaIVHeightOverScan = ((usIVHeight - ScalerVgipGetCaptureVHeight()) / 2);
        }    
    }
 #endif

    if(usIVHeight <= ScalerVgipGetCaptureVHeight())
    {
        usDeltaIVHeightUnderScan = ((ScalerVgipGetCaptureVHeight() - usIVHeight) / 2);
    }

    if(ucPar == _GET_VPOSITIONRANGE_MAX)
    {
#if(_VGA_SUPPORT == _ON)
        if(SysSourceGetSourceType() == _SOURCE_VGA)
        {
            return (g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan + _VPOSITION_BIAS); 
        }
        else
#endif
        {
            return (GET_ACTIVE_V_START() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan + _VPOSITION_BIAS);
        }
    }
    else if(ucPar == _GET_VPOSITIONRANGE_MIN)
    {
#if(_VGA_SUPPORT == _ON)
        if(SysSourceGetSourceType() == _SOURCE_VGA)
        {
            return (g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - _VPOSITION_BIAS);
        }
        else
#endif
        {
            return (GET_ACTIVE_V_START() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - _VPOSITION_BIAS); 
        }           
    }
    else
    {
#if(_VGA_SUPPORT == _ON)
        if(SysSourceGetSourceType() == _SOURCE_VGA)
        {
            return (g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan);
        }
        else
#endif
        {
            return (GET_ACTIVE_V_START() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan);
        }
    }
}

//--------------------------------------------------
// Description  : Get VPosition V Bias Value
// Input Value  : None
// Output Value : V Bias Value
//--------------------------------------------------
WORD UserCommonAdjustGetVPositionVBiasValue(void)
{
    WORD usVBias = 0;
    WORD usDeltaIVHeightOverScan = 0;
    WORD usDeltaIVHeightUnderScan = 0;
    WORD usIVHeight = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usIVHeight = UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IVHEIGHT);
    }
    else
#endif
    {
        usIVHeight = GET_ACTIVE_V_HEIGHT();
    }

#if(_OVERSCAN_SUPPORT == _ON)
    if(UserAdjustCheckOverScan() == _TRUE)
    {
        if(usIVHeight >= ScalerVgipGetCaptureVHeight())
        {
            usDeltaIVHeightOverScan = ((usIVHeight - ScalerVgipGetCaptureVHeight()) / 2);
        }    
    }
#endif

    if(usIVHeight <= ScalerVgipGetCaptureVHeight())
    {
        usDeltaIVHeightUnderScan = ((ScalerVgipGetCaptureVHeight() - usIVHeight) / 2);
    }

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usVBias = ((g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - ScalerVgipGetCaptureVStartPosition()) < (_MAX_V_POSITION_RANGE / 2)) ? 
                  (g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - ScalerVgipGetCaptureVStartPosition()) : (_MAX_V_POSITION_RANGE / 2);
    }
    else
#endif
    {
        usVBias = ((GET_ACTIVE_V_START() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - ScalerVgipGetCaptureVStartPosition()) < (_MAX_V_POSITION_RANGE / 2)) ? 
                  (GET_ACTIVE_V_START() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - ScalerVgipGetCaptureVStartPosition()) : (_MAX_V_POSITION_RANGE / 2);
    }
    
    return usVBias;
}

//--------------------------------------------------
// Description  : Adjust picture position.
// Input Value  : ucUserHPosition --> Current percentage of H position associate to OSD bar
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustHPosition(BYTE ucUserHPosition)
{
    WORD usTargetIHStart = 0;
    WORD usHPositionRangeMax = 0;
    WORD usHPositionRangeMin = 0;
    SWORD shHDelay = 0;

    // Disable Wach dog
    ScalerGlobalWatchDog(_DISABLE);

    usHPositionRangeMax = UserCommonAdjustGetHPositionRange(_GET_HPOSITIONRANGE_MAX);
    usHPositionRangeMin = UserCommonAdjustGetHPositionRange(_GET_HPOSITIONRANGE_MIN);

    usTargetIHStart = UserCommonAdjustPercentToRealValue((100 - ucUserHPosition), usHPositionRangeMax, usHPositionRangeMin, (((usHPositionRangeMax - usHPositionRangeMin) / 2) + usHPositionRangeMin));
        
    shHDelay = (SWORD)usTargetIHStart - (SWORD)ScalerVgipGetCaptureHStartPosition();

    if(ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR422)
    {
        shHDelay += ((shHDelay - ScalerVgipGetCaptureHDelay()) % 2);
    }

    // Can't set IH delay to 0 by HW limit 
    shHDelay = shHDelay < 1 ? 1 : shHDelay; 

    // Compensate IHS delay
    ScalerVgipSetCaptureHDelay(shHDelay);
    
    // Apply the above setting by setting Double Buffer Ready in VGIP
    ScalerVgipDoubleBufferApply(); 

    // Enable Wach dog
    ScalerGlobalWatchDog(_ENABLE);
}

//--------------------------------------------------
// Description  : Adjust picture position.
// Input Value  : ucUserVPosition --> Current percentage of V position associate to OSD bar
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustVPosition(BYTE ucUserVPosition)
{
    WORD usTargetIVStart = 0;
    SWORD shVDelayAdjustDeltaLimit = 0;
    WORD usVPositionRangeMax = 0;
    WORD usVPositionRangeMin = 0;
    SWORD shVDelay = 0;
    BYTE ucTimeoutCounter = 0;

    ScalerGlobalWatchDog(_DISABLE);

    usVPositionRangeMax = UserCommonAdjustGetVPositionRange(_GET_VPOSITIONRANGE_MAX);
    usVPositionRangeMin = UserCommonAdjustGetVPositionRange(_GET_VPOSITIONRANGE_MIN);

    usTargetIVStart = UserCommonAdjustPercentToRealValue(ucUserVPosition, usVPositionRangeMax, usVPositionRangeMin, (((usVPositionRangeMax - usVPositionRangeMin) / 2) + usVPositionRangeMin));
    
    shVDelay = (SWORD)usTargetIVStart - (SWORD)ScalerVgipGetCaptureVStartPosition();
        
    shVDelay = shVDelay < 0 ? 0 : shVDelay; 

    // Safe New V-Delay value must larger than DEN falling edge position plus 3 lines for 6229  
    shVDelayAdjustDeltaLimit = GET_INPUT_TIMING_VTOTAL() - GET_INPUT_TIMING_VHEIGHT() - ScalerVgipGetCaptureVStartPosition() - 3;
    
    // Keep at least one line for adjusting V-Position 
    if(shVDelayAdjustDeltaLimit <= 1)
    {
        shVDelayAdjustDeltaLimit = 1;    
    }

    ucTimeoutCounter = (abs(shVDelay - ScalerVgipGetCaptureVDelay()) / shVDelayAdjustDeltaLimit) + 1;

    do
    {        
        if(shVDelay > ScalerVgipGetCaptureVDelay())
        {            
            ScalerVgipSetCaptureVDelay(shVDelay);
        }
        else
        { 
            if((ScalerVgipGetCaptureVDelay() - shVDelay) <= shVDelayAdjustDeltaLimit)
            {
                ScalerVgipSetCaptureVDelay(shVDelay);                    
            }
            else
            {
                ScalerVgipSetCaptureVDelay(ScalerVgipGetCaptureVDelay() - shVDelayAdjustDeltaLimit);                    
            }            
        }    
        
        ScalerVgipDoubleBufferApply();         

        ucTimeoutCounter--;
    }    
    while((shVDelay != ScalerVgipGetCaptureVDelay()) && (ucTimeoutCounter > 0));

    ScalerTimerWaitForEvent(_EVENT_DVS);

    ScalerGlobalWatchDog(_ENABLE);    
}

//--------------------------------------------------
// Description  :  Calculate value to percent for input range for 2 Sectors
// Input Value  :  usRealValue --> input real value
//                 usMax       --> the max value
//                 usMin       --> the min value
//                 usCenter    --> the Center Value
// Output Value :  Percent
//--------------------------------------------------
BYTE UserCommonAdjustRealValueToPercent(WORD usRealValue, WORD usMax, WORD usMin, WORD usCenter)
{
    WORD usTemp = 0;
    usRealValue = MINOF(usRealValue, usMax);
    usRealValue = MAXOF(usRealValue, usMin);
	
    if((usMax <= usMin) || (usCenter <= usMin) || (usCenter >= usMax))
    {
        usTemp = 0;
    }
    else
    {
        if(usRealValue < usCenter)
        {
            usTemp = (((DWORD)(usRealValue - usMin) * 10000) / (usCenter - usMin)) / 2;
        }
        else if(usRealValue > usCenter) 
        {
            usTemp = (((DWORD)(usRealValue - usCenter) * 10000) / (usMax - usCenter)) / 2 + 5000;
        }
        else
        {
            return 50;
        }       
    }

    if((usTemp % 100) > 49)
    {
        usTemp = usTemp + 100;
    }

    usTemp = usTemp / 100;

    return ((BYTE)usTemp);
}

//--------------------------------------------------
// Description  :  Calculate percent to real value for input range for 2 Sectors
// Input Value  :  ucPercentValue --> input percent value
//                 usMax          --> the max value
//                 usMin          --> the min value
//                 usCenter       --> the Center Value
// Output Value :  Real value
//--------------------------------------------------
WORD UserCommonAdjustPercentToRealValue(BYTE ucPercentValue, WORD usMax, WORD usMin, WORD usCenter)
{
    DWORD ulTemp = 0;

    ucPercentValue = MINOF(100, ucPercentValue);

    if(ucPercentValue > 50)
    {
        ulTemp = (((DWORD)(ucPercentValue - 50) * (usMax - usCenter) * 10) / 50);
    }
    else if(ucPercentValue < 50)
    {
        ulTemp = (((DWORD)ucPercentValue * (usCenter - usMin) * 10) / 50);
    }
    else
    {
        return usCenter;
    }

    if((ulTemp % 10) > 5)
    {
        ulTemp = ulTemp + 10;
    }

    if(ucPercentValue > 50)
    {
        return (WORD)((ulTemp / 10) + usCenter);
    }
    else if(ucPercentValue < 50)
    {
        return (WORD)((ulTemp / 10) + usMin);
    }
}

#if(_OVERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Timing For Overscan
// Input Value  : Current Input Timing
// Output Value : Modified Input Timing
//--------------------------------------------------
void UserCommonAdjustOverScan(void)
{
    BYTE ucDelta = 0;
    
    if(UserAdjustCheckOverScan() == _TRUE)
    {
        // Modify Over Scanned H
        ucDelta = (BYTE)((DWORD)GET_MDOMAIN_INPUT_HWIDTH() * _OVERSCAN_H_RATIO / 1000);

        // Let Adjusted Value be 2's multiple
        ucDelta += ucDelta % 2;

        SET_MDOMAIN_INPUT_HSTART(GET_MDOMAIN_INPUT_HSTART() + ucDelta);
        SET_MDOMAIN_INPUT_HWIDTH(GET_MDOMAIN_INPUT_HWIDTH() - 2 * ucDelta);        
        
        // Modify Over Scanned V
        ucDelta = (BYTE)((DWORD)GET_MDOMAIN_INPUT_VHEIGHT() * _OVERSCAN_V_RATIO / 1000);
        
        SET_MDOMAIN_INPUT_VSTART(GET_MDOMAIN_INPUT_VSTART() + ucDelta);
        SET_MDOMAIN_INPUT_VHEIGHT(GET_MDOMAIN_INPUT_VHEIGHT() - 2 * ucDelta);                
    }        
}
#endif  // End of #if(_OVERSCAN_SUPPORT == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust UltraVivid
// Input Value  : UltraVivid Type / Color space
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustUltraVivid(EnumColorSpace enumColorFormat)
{
    UserAdjustUltraVivid(); 

    SysModeColorSpaceConvert(enumColorFormat);
}

#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check if I-dither needs to be turned off
// Input Value  : UltraVivid Type / Color space
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustIDither(void)
{
    if((SysSourceGetSourceType() == _SOURCE_VGA) && (ScalerColorGetIColorConvertStatus() == _OFF))
    {
        ScalerColorIDitherOff();
    }
    else
    {
        UserAdjustIDitherOn();
    }
}
#endif  // End of #if(_I_DITHER_SUPPORT == _ON)

#if(_ENERGY_STAR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Search target backlight value
// Input Value  : None
// Output Value : None
// Return Value : None
//--------------------------------------------------
void UserCommonAdjustESDcrSearchTargetPWM(void)
{
    // Search Backlight by Current Average (R+G+B) Value.
    if(GET_ES_DCR_CUR_RGB_AVG_VALUE() <= tENERGY_STAR_ACTIVE_RANGE[0])
    {
        // Set Min Value.
        SET_ES_DCR_PWM_TARGET_VALUE(tENERGY_STAR_BACKLIGHT_TABLE[0]);
    }
    else if(GET_ES_DCR_CUR_RGB_AVG_VALUE() > tENERGY_STAR_ACTIVE_RANGE[(sizeof(tENERGY_STAR_ACTIVE_RANGE) - 1)])
    {
        // Set Max Value.
        SET_ES_DCR_PWM_TARGET_VALUE(tENERGY_STAR_BACKLIGHT_TABLE[(sizeof(tENERGY_STAR_BACKLIGHT_TABLE) - 1)]);
    }
    else
    {
        for(pData[0] = (sizeof(tENERGY_STAR_ACTIVE_RANGE) - 1); pData[0] > 0; pData[0]--)
        {
            if((GET_ES_DCR_CUR_RGB_AVG_VALUE() > tENERGY_STAR_ACTIVE_RANGE[(pData[0] - 1)]) &&
               (GET_ES_DCR_CUR_RGB_AVG_VALUE() <= tENERGY_STAR_ACTIVE_RANGE[pData[0]]))
            {
                SET_ES_DCR_PWM_TARGET_VALUE(tENERGY_STAR_BACKLIGHT_TABLE[pData[0]]);
                break;
            }
        }
    }

    // Compute Target Backlight Value by OSD Backlight Setting.
    pData[0] = (WORD)UserInterfaceGetOSDBackightValue() * GET_ES_DCR_PWM_TARGET_VALUE() / 100;

    // Check Min Backlight Value.
    if(pData[0] < _ES_DCR_ACTIVE_BACKLIGHT_MIN)
    {
        pData[0] = _ES_DCR_ACTIVE_BACKLIGHT_MIN;
    }
    
    // Set Target Backlight Value.
    SET_ES_DCR_PWM_TARGET_VALUE(pData[0]);    
}

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
// Return Value : None
//--------------------------------------------------
void UserCommonAdjustESDcrAdjust(void)
{
    BYTE ucTemp = 0;

    // Check if DVS happened.
    ucTemp = ScalerTimerGetEventStatus(_EVENT_DVS);
    
    if(ucTemp != _EVENT_DVS)
    {
        return;
    }

    // Clear DVS Event.
    ScalerTimerClrEventStatus(_EVENT_DVS);

    // Set Previous Average (R+G+B) Value.
    SET_ES_DCR_PRE_RGB_AVG_VALUE(GET_ES_DCR_CUR_RGB_AVG_VALUE());

    // Get Current Average (R+G+B) Value.
    SET_ES_DCR_CUR_RGB_AVG_VALUE((DWORD)ScalerColorDCRReadResult(_DCR_ABOVE_TH1_VAL) / GET_MDOMAIN_OUTPUT_HWIDTH() / GET_MDOMAIN_OUTPUT_VHEIGHT() / 3);

    // Compute The Difference Between Current And Previous Frame.
    ucTemp = abs(GET_ES_DCR_PRE_RGB_AVG_VALUE() - GET_ES_DCR_CUR_RGB_AVG_VALUE());

    // Do Nothing in The Same Frame.
    if(ucTemp == 0)
    {
        return;
    }

    // Search Target Backlight Value.
    UserCommonAdjustESDcrSearchTargetPWM();

    // Condiser The Difference Value.
    if(ucTemp > _ES_DCR_FRAME_DIFFERENCE_DIRECT_SET_THRESHOLD)
    {
        // Directly Apply Backlight Value.
        SET_ES_DCR_PWM_ADJUST_VALUE(GET_ES_DCR_PWM_TARGET_VALUE());
        UserAdjustBacklight(GET_ES_DCR_PWM_ADJUST_VALUE());
    }
    else if(ucTemp > _ES_DCR_FRAME_DIFFERENCE_THRESHOLD_MIN)
    {
        // Active Event After DVS Time.
        ScalerTimerActiveTimerEvent((10000 / GET_MDOMAIN_INPUT_VFREQ()), _USER_TIMER_EVENT_ES_ADJUST);
    }
}

//--------------------------------------------------
// Description  : Adjust backlight step by step
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustESDcrAdjustPWM(void)
{
    if(GET_ES_DCR_PWM_ADJUST_VALUE() == GET_ES_DCR_PWM_TARGET_VALUE())
    {
        return;
    }
    
    // Adjust Backlight Value Step By Step.
    if(GET_ES_DCR_PWM_ADJUST_VALUE() > GET_ES_DCR_PWM_TARGET_VALUE())
    {
        // Consider The Different Adjustment Step.
        if(GET_ES_DCR_PWM_ADJUST_VALUE() <= _ES_DCR_STEP_RANGE_THRESHOLD_1)
        {
            pData[0] = ((GET_ES_DCR_PWM_ADJUST_VALUE() - _ES_DCR_STEP_RANGE_SCALE_1) >= GET_ES_DCR_PWM_TARGET_VALUE()) ?
                        (_ES_DCR_STEP_RANGE_SCALE_1):
                        (GET_ES_DCR_PWM_ADJUST_VALUE() - GET_ES_DCR_PWM_TARGET_VALUE());
        }
        else if(GET_ES_DCR_PWM_ADJUST_VALUE() <= _ES_DCR_STEP_RANGE_THRESHOLD_2) 
        {
            pData[0] = ((GET_ES_DCR_PWM_ADJUST_VALUE() - _ES_DCR_STEP_RANGE_SCALE_2) >= GET_ES_DCR_PWM_TARGET_VALUE()) ?
                        (_ES_DCR_STEP_RANGE_SCALE_2):
                        (GET_ES_DCR_PWM_ADJUST_VALUE() - GET_ES_DCR_PWM_TARGET_VALUE());
        }
        else
        {
            pData[0] = ((GET_ES_DCR_PWM_ADJUST_VALUE() - _ES_DCR_STEP_RANGE_SCALE_3) >= GET_ES_DCR_PWM_TARGET_VALUE()) ?
                        (_ES_DCR_STEP_RANGE_SCALE_3):
                        (GET_ES_DCR_PWM_ADJUST_VALUE() - GET_ES_DCR_PWM_TARGET_VALUE());
        }

        SET_ES_DCR_PWM_ADJUST_VALUE(GET_ES_DCR_PWM_ADJUST_VALUE() - pData[0]);
    }
    else
    {
        // Consider The Different Adjustment Step.
        if(GET_ES_DCR_PWM_ADJUST_VALUE() <= _ES_DCR_STEP_RANGE_THRESHOLD_1)
        {
            pData[0] = ((GET_ES_DCR_PWM_ADJUST_VALUE() + _ES_DCR_STEP_RANGE_SCALE_1) <= GET_ES_DCR_PWM_TARGET_VALUE()) ?
                        (_ES_DCR_STEP_RANGE_SCALE_1) :
                        (GET_ES_DCR_PWM_TARGET_VALUE() - GET_ES_DCR_PWM_ADJUST_VALUE());
        }
        else if(GET_ES_DCR_PWM_ADJUST_VALUE() <= _ES_DCR_STEP_RANGE_THRESHOLD_2) 
        {
            pData[0] = ((GET_ES_DCR_PWM_ADJUST_VALUE() + _ES_DCR_STEP_RANGE_SCALE_2) <= GET_ES_DCR_PWM_TARGET_VALUE()) ?
                        (_ES_DCR_STEP_RANGE_SCALE_2):
                        (GET_ES_DCR_PWM_TARGET_VALUE() - GET_ES_DCR_PWM_ADJUST_VALUE());
        }
        else
        {
            pData[0] = ((GET_ES_DCR_PWM_ADJUST_VALUE() + _ES_DCR_STEP_RANGE_SCALE_3) <= GET_ES_DCR_PWM_TARGET_VALUE()) ?
                        (_ES_DCR_STEP_RANGE_SCALE_3):
                        (GET_ES_DCR_PWM_TARGET_VALUE() - GET_ES_DCR_PWM_ADJUST_VALUE());
        }

        SET_ES_DCR_PWM_ADJUST_VALUE(GET_ES_DCR_PWM_ADJUST_VALUE() + pData[0]);
    }   

    // Set The Adjust Backlight Value.
    UserAdjustBacklight(GET_ES_DCR_PWM_ADJUST_VALUE());

    if(GET_ES_DCR_PWM_ADJUST_VALUE() != GET_ES_DCR_PWM_TARGET_VALUE())
    {
        // ((10000 / GET_MDOMAIN_INPUT_VFREQ()) * 2)
        // Active Event After 2*DVS Time.
        ScalerTimerActiveTimerEvent(((10000 / GET_MDOMAIN_INPUT_VFREQ()) * _ES_DCR_ADJUST_TIME), _USER_TIMER_EVENT_ES_ADJUST);
    }
}

//--------------------------------------------------
// Description  : Energy Star adjustment function on/off
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustESDcrProcess(bit bOnOff)
{
    if(bOnOff == _OFF)
    {
    
    	ScalerColorDCROnOff(_OFF);
        // Set Inital DCR Adjust Value.
        SET_ES_DCR_PWM_ADJUST_VALUE(UserInterfaceGetOSDBackightValue());

        // Cancel Event.
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_ES_ADJUST);

        // Set Backlight Value.
        UserAdjustBacklight(UserInterfaceGetOSDBackightValue());
    }
    else
    {
    
    	ScalerColorDCROnOff(_ON);
        // Set DCR Threshold.
        ScalerColorDCRThresholdAdjust(_ES_DCR_MEASURE_THRESHOLD_1, _ES_DCR_MEASURE_THRESHOLD_2);        

        // Get Current Average (R+G+B) Value.
        SET_ES_DCR_CUR_RGB_AVG_VALUE((DWORD)ScalerColorDCRReadResult(_DCR_ABOVE_TH1_VAL) / GET_MDOMAIN_OUTPUT_HWIDTH() / GET_MDOMAIN_OUTPUT_VHEIGHT() / 3);

        // Set Previous Average (R+G+B) Value.
        SET_ES_DCR_PRE_RGB_AVG_VALUE(GET_ES_DCR_CUR_RGB_AVG_VALUE());

        // Search Target Backlight Value.
        UserCommonAdjustESDcrSearchTargetPWM();

        // Set Inital DCR Adjust Value.
        SET_ES_DCR_PWM_ADJUST_VALUE(GET_ES_DCR_PWM_TARGET_VALUE());

        // Set Backlight Value.
        UserAdjustBacklight(GET_ES_DCR_PWM_TARGET_VALUE());
    }
}
#endif // End of #if(_ENERGY_STAR_SUPPORT == _ON)


