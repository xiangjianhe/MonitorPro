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
// ID Code      : ScalerMeasure.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_MEASURE__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructAutoActiveData data g_stActiveRegion = {0};
StructMeasureSyncData idata g_stMeasureSyncHV = {0};
StructTimingInfo data g_stInputTimingData = {0};

DWORD g_ulActiveRegionBackUp = 0;
bit g_bInputTimingDoubleCheck = _FALSE;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerMeasureInputInfo(BYTE ucSourceType);

#if(_VGA_SUPPORT == _ON)
bit ScalerMeasureActiveRegion(EnumMeasureModeType enumMeasureType, EnumMeasureFieldSelect enumFieldSelect, EnumMeasureBoundType enumBoundType, WORD usHTotal);
#endif

bit ScalerMeasureTimingChange(BYTE ucSourceType);
bit ScalerMeasureActiveRegionChange(void);

void ScalerMeasureSetMeasure(EnumSyncMeasureAnalogDigitalSel enumMeasureType);
bit ScalerMeasureGetMeasureResult(StructMeasureSyncData *stMeasureSyncHV);
void ScalerMeasureSetRegionCount(bit bTarget, EnumActiveRegionType enumRegion);
DWORD ScalerMeasureGetRegionCountResult(bit bWait);
void ScalerMeasureSetAuto(EnumMeasureModeType enumMeasureType, EnumMeasureFieldSelect enumFieldSelect, EnumMeasureBoundType enumBoundType, WORD usHTotal);
bit ScalerMeasureGetAutoResult(StructAutoActiveData *stActiveRegion, bit bWait);
void ScalerMeasureUpdateInputTimingPolarity(BYTE ucSourceType, StructMeasureSyncData *stMeasureSyncHV);
void ScalerMeasureUpdateInputTimingData(StructMeasureSyncData *stMeasureSyncHV, StructAutoActiveData *stActiveRegion);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
bit ScalerMeasureCheckInterlaceVst(WORD usVstart);
bit ScalerMeasureCheckFirstLineShift(WORD usFrameHwidth);
#endif

bit ScalerMeasureAutoFuncWaitFinish(void);
void ScalerMeasureAutoFuncHBoundInitial(WORD usHBoundStart, WORD usHBoundEnd);
void ScalerMeasureAutoFuncVBoundInitial(WORD usVBoundStart, WORD usVBoundEnd);

#if(_VGA_SUPPORT == _ON)
bit ScalerMeasureHWAutoPhaseSearch(EnumAutoPhaseSearchStep enumPhaseStep, BYTE *ucPhaseResult, DWORD *ulSODMax, DWORD *ulSODMin, EnumAutoPhaseSearchSODMethod enumSODMethod, BYTE ucSODThreshold);
bit ScalerMeasureAutoPhaseGetSOD(DWORD * ulSODValue);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Measure Input Timing
// Input Value  : ucSourceType --> Input source type
// Output Value : _TURE => All Required Timing Info is done
//--------------------------------------------------
bit ScalerMeasureInputInfo(BYTE ucSourceType)
{
    DWORD ulActiveRegionCount[2];
    WORD usVstart = 0;

    ulActiveRegionCount[0] = 0;
    ulActiveRegionCount[1] = 0;

    //===========================================================================================
    // 0. Initialization
    //===========================================================================================

    // Enable Sync Processor Power
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT7, 0x00);

    // Bit6: Measure Time Clock = 4096 Xtal, Measure source select capture window
    ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_18_SYNC_TEST_MODE, ~(_BIT6 | _BIT3), (_BIT6 | _BIT3));

    // VSync Measure Invert Disable
    ScalerSetBit(CM_4F_STABLE_MEASURE, ~(_BIT2), 0x00);

    // Disable HS / DEN swap
    ScalerSetBit(CM_5A_SYNC_TEST_MISC, ~_BIT6, 0x00);

    // Initial VGIP for input signal pass through
    ScalerVgipInputInitial(ucSourceType);

    // Initial Interlace Check Block
    ScalerSyncInterlaceInitial(ucSourceType);    

    // Reset interlace flag
    g_stInputTimingData.b1Interlace = _FALSE;   

#if(_3D_SUPPORT == _ON)
    // Detect whether input timing is 3D before Interlace check for Frame packing
    Scaler3DDetect(ucSourceType);
#endif        

    switch(ucSourceType)
    {
#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

            // Special case for small DVS width
            if(ScalerGetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_05_SYNC_CLAMP_CTRL1, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6))
            {
                if(ScalerSyncGetDeVsyncWidth() >= 4)
                {
                    ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_05_SYNC_CLAMP_CTRL1, ~(_BIT7 | _BIT6), 0x00);
                }
            }
            
            // Set active measured V-Sync delay 3 lines for auto function
            ScalerSetBit(CM_1E_VGIP_HV_DELAY, ~(_BIT5 | _BIT4), _BIT4);

            // Switch Measure Input to ADC
            ScalerSetBit(CM_49_SYNC_CTRL, ~(_BIT1 | _BIT0), _BIT1);

            // Hsync Measure Source from SeHS or DeHS by CR49[6]
            ScalerSetBit(CM_49_SYNC_CTRL, ~_BIT2, _BIT2);

            // Enable IVS bypass
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT6, _BIT6);

            // Initial active region count block
            ScalerMeasureSetRegionCount(_MEASURE_TARGET_INPUT, _WHOLE_FRAME_TYPE);            
           			
            break;
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
        default:            

            // Set active measure V-Sync delay 0 lines for auto function
            ScalerSetBit(CM_1E_VGIP_HV_DELAY, ~(_BIT5 | _BIT4), 0x00);

            // Switch Measure Input to Digital
            ScalerSetBit(CM_49_SYNC_CTRL, ~(_BIT1 | _BIT0), 0x00);

            break;
#endif
    }

    //===========================================================================================
    // 1. Start measure block & region count(raw VS); pop-out result
    //===========================================================================================

    // Initial measure block
    ScalerMeasureSetMeasure(_ANALOG_MEASURE);

    // Wait for 2 raw IVS for digital; 3 for VGA
    if((ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE) ||
       (ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE) ||
       ((ucSourceType == _SOURCE_VGA) && (ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)))
    {
        return _FALSE;
    }
    
    // Pop out measure result
    if(ScalerMeasureGetMeasureResult(&g_stMeasureSyncHV) == _FALSE)
    {
        return _FALSE;
    }

#if(_VGA_SUPPORT == _ON)
    if(ucSourceType == _SOURCE_VGA)
    {
        ScalerTimerDelayXms(2);
        
        // Pop out active region count result (raw)
        ulActiveRegionCount[0] = ScalerMeasureGetRegionCountResult(_NOT_WAIT);    

        if(ulActiveRegionCount[0] == 0x00)
        {
            return _FALSE;
        }

        // Disable IVS bypass
        ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT6, 0x00);        
    }
#endif    

    //===========================================================================================
    // 2. Check VGIP HS/VS polarity
    //===========================================================================================

    // Update input timing polarity (MUST BE HERE)
    ScalerMeasureUpdateInputTimingPolarity(ucSourceType, &g_stMeasureSyncHV);

    // Modify VGIP sync polarity
    ScalerVgipModifyPolarity(ucSourceType);

    // Update input timing data from variable "g_stMeasureSyncHV"
    ScalerMeasureUpdateInputTimingData(&g_stMeasureSyncHV, &g_stActiveRegion);

    //===========================================================================================
    // 3. Start auto-function & check VGIP VS latch edge (VGA only)
    //===========================================================================================

    // Start auto-function measure
    switch(ucSourceType)
    {
#if(_VGA_SUPPORT == _ON)        
        case _SOURCE_VGA:

            // Analog measure
            ScalerMeasureSetAuto(_ANALOG_MODE_MEASURE, _NORMAL_MEASURE, _FULL_BOUNDARY, ScalerAPLLGetIHTotal());

            break;
#endif            

#if(_DIGITAL_PORT_SUPPORT == _ON)
        default:
            
            // Switch to digital measure for digital interfaces
            ScalerMeasureSetMeasure(_DIGITAL_MEASURE);
            
            // Set HW auto-phase: step = 10
            ScalerSetByte(CM_7B_HW_AUTO_PHASE_CTRL0, 0x48);
        
            // Digital measure
            ScalerMeasureSetAuto(_DIGITAL_MODE_MEASURE, _NORMAL_MEASURE, _FULL_BOUNDARY, 0x0FFF);

            // Stop auto-function
            ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, 0x00);

            // Enable auto-function with HW mode          
            ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT6 | _BIT0), (_BIT6 | _BIT0));        

            break;        
#endif            
    }

    // Wait for 1 latched IVS
    if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
    {
        return _FALSE;
    }

#if(_VGA_SUPPORT == _ON)
    if(ucSourceType == _SOURCE_VGA)
    {
        // Check IVS latch edge
        ScalerVgipModifyVsLatchEdge(_NOT_WAIT);

        // Add additional 1 frame if latch edge changed
        if(ScalerGetBit(CM_12_VGIP_DELAY_CTRL, _BIT2) == _BIT2)
        {
            // Wait for 1 latched IVS
            if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
            {
                return _FALSE;
            }            
        }
    }
#endif

    // Wait for 1 latched IVS
    if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
    {
        return _FALSE;
    }

    // Pop out auto-function result
    if(ScalerMeasureGetAutoResult(&g_stActiveRegion, _NOT_WAIT) == _FALSE)
    {
        return _FALSE;
    }

    //===========================================================================================
    // 4. Detect interlace format
    //===========================================================================================

    switch(ucSourceType)
    {
#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

            // Pop out active region count result (latched) for VGA
            ulActiveRegionCount[1] = ScalerMeasureGetRegionCountResult(_NOT_WAIT);
            
            // Stop region count
            ScalerSetBit(CM_50_STABLE_PERIOD_H, ~_BIT4, 0x00);

            // Calculate difference of V period
            PDATA_WORD(0) = (WORD)(ABSDWORD(ulActiveRegionCount[0], ulActiveRegionCount[1]) % g_stMeasureSyncHV.usHSPeriod);

            // Check half line length; flag interlace between [0.25:0.75] * H period
            if(abs(PDATA_WORD(0) - (g_stMeasureSyncHV.usHSPeriod >> 1)) < (g_stMeasureSyncHV.usHSPeriod >> 2))
            {
                DebugMessageScaler("Interlace: detect by half line", PDATA_WORD(0));
                g_stInputTimingData.b1Interlace = _TRUE;
            }

            break;
#endif  

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
        case _SOURCE_DVI:
        case _SOURCE_HDMI:

            // Measure H total & alternative V start for DVI/HDMI
            if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
            {
                return _FALSE;
            }
            
            // Get another V start
            usVstart = (((WORD)ScalerGetBit(CM_7E_V_START_END_H, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | ScalerGetByte(CM_7F_V_START_L));            

            // Stop auto-function
            ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, 0x00);

            // Check interlace by flag
            if(ScalerSyncInterlaceCheck(ucSourceType) == _TRUE)
            {
                DebugMessageScaler("Interlace: detect by flag", 0x00);
                g_stInputTimingData.b1Interlace = _TRUE;

                // Check Vstart under interlaced mode
                if(ScalerMeasureCheckInterlaceVst(usVstart) == _FALSE)
                {
                    return _FALSE;
                }
            }

            break;
#endif          

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:

            // Wait for 1 latched IVS
            if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
            {
                return _FALSE;
            }

            // Check interlace by flag
            if(ScalerSyncInterlaceCheck(ucSourceType) == _TRUE)
            {            
                DebugMessageScaler("Interlace: detect by flag", 0x00);
                g_stInputTimingData.b1Interlace = _TRUE;
            }
            
            break;
#endif

        default:

            // Check interlace by flag
            if(ScalerSyncInterlaceCheck(ucSourceType) == _TRUE)
            {            
                DebugMessageScaler("Interlace: detect by flag", 0x00);
                g_stInputTimingData.b1Interlace = _TRUE;
            }        

            break;
    }

    //===========================================================================================
    // 5. Update H total & double-check current timing
    //===========================================================================================

    switch(ucSourceType)
    {
#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

            // Double-check for timing change
            if(ScalerMeasureTimingChange(_SOURCE_VGA) == _TRUE)
            {
                return _FALSE;
            }
            
            g_stInputTimingData.usHTotal = ScalerAPLLGetIHTotal();        

            break;
#endif      
        
#if(_DIGITAL_PORT_SUPPORT == _ON)        
        default:

            // Pop-out & check digital measure result
            if((ScalerMeasureGetMeasureResult((StructMeasureSyncData *)pData) == _FALSE) ||
               (abs(((StructMeasureSyncData *)pData)->usVSPeriod - GET_ACTIVE_V_HEIGHT()) > 2))
            {
                return _FALSE;
            }
            
            if(abs(((StructMeasureSyncData *)pData)->usHSWidth - GET_ACTIVE_H_WIDTH()) > 2)
            {
#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
                if(((ucSourceType == _SOURCE_DVI) || (ucSourceType == _SOURCE_HDMI)) &&
                   (ScalerGetBit(P2_A7_POWER_ON_OFF_CTRL, _BIT7) == _BIT7) &&
                   (ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3)))
                {
                    // Check first line width for DVI/HDMI under DE-only mode with raw HS/VS
                    if(ScalerMeasureCheckFirstLineShift(((StructMeasureSyncData *)pData)->usHSWidth) == _TRUE)
                    {
                        // First line shift detected; Disable DE-only mode
                        ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~_BIT7, 0x00);
                    }
                }
#endif     
                return _FALSE;
            }

            // Get Htotal
            g_stInputTimingData.usHTotal = ((StructMeasureSyncData *)pData)->usHSPeriod;

            // Wait 1 IVS for on-line check
            ScalerTimerWaitForEvent(_EVENT_IVS);                    
                
            break;
#endif              
    }

    // Update input timing data
    ScalerMeasureUpdateInputTimingData(&g_stMeasureSyncHV, &g_stActiveRegion);

    return _TRUE;
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Measure Active Start / End using auto-funcgion
// Input Value  : EnumMeasureModeType --> Analog or Digital Mode Measure
//                EnumMeasureFieldSelect --> Measure for Even or Odd Field
//                EnumMeasureBoundType --> OverScan Boundary or Normal Boundary
//                usHTotal --> H Total
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerMeasureActiveRegion(EnumMeasureModeType enumMeasureType, EnumMeasureFieldSelect enumFieldSelect, EnumMeasureBoundType enumBoundType, WORD usHTotal)
{
    ScalerMeasureSetAuto(enumMeasureType, enumFieldSelect, enumBoundType, usHTotal);

    if(ScalerMeasureGetAutoResult(&g_stActiveRegion, _WAIT) == _FALSE)
    {
        return _FALSE;
    }
    else
    {
        return _TRUE;
    }
}
#endif

//--------------------------------------------------
// Description  : Check timing change
// Input Value  : None
// Output Value : _TRUE if HV timing Changed
//--------------------------------------------------
bit ScalerMeasureTimingChange(BYTE ucSourceType)
{
    bit bTimingChangeStatus = _FALSE;
    StructMeasureSyncData stMeasureSyncHV;

    // Measure timeout or overflow
    if((ScalerGetBit(CM_52_MEAS_HS_PER_H, _BIT4) != 0x00) || (ScalerGetBit(CM_54_MEAS_VS_PER_H, (_BIT5 | _BIT4)) != 0x00))
    {
        return _TRUE;
    }

    // Pop up if measure complete
    if(ScalerGetBit(CM_50_STABLE_PERIOD_H, _BIT7) == 0x00)
    {
        if(ScalerMeasureGetMeasureResult(&stMeasureSyncHV) == _FALSE)
        {
            return _FALSE;
        }

        // Check measured result by measure type
        if(ScalerGetBit(CM_47_SYNC_SELECT, _BIT0) == _BIT0)            
        {
            // Check digital measure result (no swap)
            bTimingChangeStatus = ((abs(stMeasureSyncHV.usHSPeriod - GET_INPUT_TIMING_HTOTAL()) > 2) || \
                                   (abs(stMeasureSyncHV.usVSPeriod - GET_INPUT_TIMING_VHEIGHT()) > 2) || \
                                   (abs(stMeasureSyncHV.usHSWidth - GET_INPUT_TIMING_HWIDTH()) > 2));
        }
        else
        {
#if(_FREESYNC_SUPPORT == _ON)
            if(GET_FREESYNC_ENABLED() == _TRUE)
            {
                // Check off-line measure result
                bTimingChangeStatus = ((stMeasureSyncHV.b1HSP != GET_SYNC_H_POLARITY()) ||
                                       (stMeasureSyncHV.b1VSP != GET_SYNC_V_POLARITY()));

                if(abs(stMeasureSyncHV.usVSPeriod - g_stInputTimingData.usVTotal) > 2)
                {
                    g_stInputTimingData.usVTotal = stMeasureSyncHV.usVSPeriod;
                    g_stInputTimingData.usVFreq = (_SYNC_PROC_CLK * 1000 * 10 * 2 / stMeasureSyncHV.usHSPeriod / stMeasureSyncHV.usVSPeriod + 1) / 2;
                }

                DebugMessageOsd("4.Alia IVfeq", g_stInputTimingData.usVFreq);
            }
            else
#endif
            {
                // Check analog measure result
                bTimingChangeStatus = ((abs(stMeasureSyncHV.usHSPeriod - GET_SYNC_H_PERIOD()) > _ANALOG_MEASURE_HS_TOR) || \
                                       (abs(stMeasureSyncHV.usVSPeriod - GET_SYNC_V_PERIOD()) > 2) || \
                                       (stMeasureSyncHV.b1HSP != GET_SYNC_H_POLARITY()) || \
                                       (stMeasureSyncHV.b1VSP != GET_SYNC_V_POLARITY()));
            }

        }

        // Toggle measure type for digital interface
        if(ucSourceType != _SOURCE_VGA)
        {
            if(ScalerGetBit(CM_47_SYNC_SELECT, _BIT0) == 0x00)
            {
                ScalerMeasureSetMeasure(_DIGITAL_MEASURE);
            }
            else
            {
                ScalerMeasureSetMeasure(_ANALOG_MEASURE);
            }
        }
    }
   
    return bTimingChangeStatus;
}

//--------------------------------------------------
// Description  : Check if active region changed
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerMeasureActiveRegionChange(void)
{
    // Pop out region count result
    PDATA_DWORD(0) = ScalerMeasureGetRegionCountResult(_NOT_WAIT);

    // Disable region count
    ScalerSetBit(CM_50_STABLE_PERIOD_H, ~_BIT4, 0x00);

    // Compare with stored input active region count   
    if(ABSDWORD(PDATA_DWORD(0), g_ulActiveRegionBackUp) > (g_ulActiveRegionBackUp >> 8))
    {
        return _TRUE;
    }  
    else
    {
        return _FALSE;
    }    
}

//--------------------------------------------------
// Description  : Set for Sync Processor Measure Input HV
// Input Value  : enumMeasureType --> Measure type
// Output Value : None
//--------------------------------------------------
void ScalerMeasureSetMeasure(EnumSyncMeasureAnalogDigitalSel enumMeasureType)
{       
    if(enumMeasureType == _ANALOG_MEASURE)
    {
        // Select to Analog Measure
        ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT0, 0x00);
    }
    else
    {
        // Select to Digital Measure
        ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT0, _BIT0);
    }

    // Disable Measure
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~(_BIT7 | _BIT5), 0x00);

    // Enable On Line Measure
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT7, _BIT7);
}

//--------------------------------------------------
// Description  : Pop Up Sync Processor Measure Result
// Input Value  : stMeasureSyncHV --> measure result
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerMeasureGetMeasureResult(StructMeasureSyncData *stMeasureSyncHV)
{
    if(ScalerTimerPollingFlagProc(_MEASURE_TIMEOUT, CM_50_STABLE_PERIOD_H, _BIT7, 0x00) == _FALSE)
    {        
        return _FALSE;
    }                

    // Check measure result status
    if((ScalerGetBit(CM_52_MEAS_HS_PER_H, _BIT4) != 0x00) ||
       (ScalerGetBit(CM_54_MEAS_VS_PER_H, (_BIT5 | _BIT4)) != 0x00))
    {
        return _FALSE;
    }
    
    // Pop up measurement result
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT6, _BIT6);

    if(ScalerGetBit(CM_10_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) // VGA measure
    {
        // Pop up stable measure result
        ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT1, _BIT1);

        // Polarity
        stMeasureSyncHV->b1HSP = (bit)ScalerGetBit(CM_4F_STABLE_MEASURE, _BIT6);
        stMeasureSyncHV->b1VSP = (bit)ScalerGetBit(CM_54_MEAS_VS_PER_H, _BIT7);

        // HSync Period
        stMeasureSyncHV->usHSPeriod = ((((WORD)ScalerGetByte(CM_50_STABLE_PERIOD_H) & 0x07) << 8) | (ScalerGetByte(CM_51_STABLE_PERIOD_L))) + 1;

        // HSync Pulse Width
        stMeasureSyncHV->usHSWidth = ((((WORD)ScalerGetByte(CM_4A_STABLE_HIGH_PERIOD_H) & 0x07) << 8) | (ScalerGetByte(CM_4B_STABLE_HIGH_PERIOD_L))) + 1;
    }
    else // TMDS measue
    {
        // Polarity
        stMeasureSyncHV->b1HSP = (bit)ScalerGetBit(CM_54_MEAS_VS_PER_H, _BIT6);
        stMeasureSyncHV->b1VSP = (bit)ScalerGetBit(CM_54_MEAS_VS_PER_H, _BIT7);

        // Set to read HSWidth
        ScalerSetBit(CM_58_MEAS_HS_VS_HI_SEL, ~_BIT0, 0x00);

        // HSync Period
        stMeasureSyncHV->usHSPeriod = ((((WORD)ScalerGetByte(CM_52_MEAS_HS_PER_H) & 0x0F) << 8) | (ScalerGetByte(CM_53_MEAS_HS_PER_L))) + 1;

        // HSync Pulse Width
        stMeasureSyncHV->usHSWidth = ((((WORD)ScalerGetByte(CM_56_MEAS_HS_VS_HI_H) & 0xF0) << 4) | (ScalerGetByte(CM_57_MEAS_HS_VS_HI_L))) + 1;
    }

    // Set to read VSWidth
    ScalerSetBit(CM_58_MEAS_HS_VS_HI_SEL, ~_BIT0, _BIT0);

    // VSync Period
    stMeasureSyncHV->usVSPeriod = ((((WORD)ScalerGetByte(CM_54_MEAS_VS_PER_H) & 0x0F) << 8) | (ScalerGetByte(CM_55_MEAS_VS_PER_L))) + 1;

    // VSync Pulse Width
    stMeasureSyncHV->usVSWidth = ((((WORD)ScalerGetByte(CM_56_MEAS_HS_VS_HI_H) & 0xF0) << 4) | (ScalerGetByte(CM_57_MEAS_HS_VS_HI_L))) + 1;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Set for Region Count Measure
// Input Value  : bTarget --> Measure type: digital or analog
//                ucRegion --> measure region type
// Output Value : None
//--------------------------------------------------
void ScalerMeasureSetRegionCount(bit bTarget, EnumActiveRegionType enumRegion)
{
    // Disable Active Region Measure
    ScalerSetBit(CM_50_STABLE_PERIOD_H, ~_BIT4, 0x00);

    // Select active region count source
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT1, ((bTarget == _MEASURE_TARGET_INPUT) ? 0x00 : _BIT1));

    // Select active region count type
    ScalerSetBit(CM_5A_SYNC_TEST_MISC, ~(_BIT5 | _BIT4), (enumRegion & (_BIT5 | _BIT4)));

    // Enable Active Region Measure
    ScalerSetBit(CM_50_STABLE_PERIOD_H, ~_BIT4, _BIT4);
}

//--------------------------------------------------
// Description  : Pop Up Region Count result
// Input Value  : bWait --> wait for additional frames or not
// Output Value : measure region count
//--------------------------------------------------
DWORD ScalerMeasureGetRegionCountResult(bit bWait)
{
    if(bWait == _WAIT)
    {
        if(ScalerGetBit(CM_47_SYNC_SELECT, _BIT1) == 0x00)
        {
            ScalerTimerWaitForEvent(_EVENT_IVS);
            ScalerTimerWaitForEvent(_EVENT_IVS);
        }
        else
        {
            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);
        }
    }

    // Pop up Measure Results
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT6, _BIT6);

    // Write to reset Measure Result pointer
    ScalerSetByte(CM_59_MEAS_ACTIVE_REGION_H, 0x00);

    // Get Active Measure Clk Count
    pData[0] = 0;
    pData[1] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
    pData[2] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
    pData[3] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);

    return PDATA_DWORD(0);
}

//--------------------------------------------------
// Description  : Initialization for Picture Position <easure by Auto Function Measure
// Input Value  : EnumMeasureModeType --> Analog or Digital Mode Measure
//                EnumMeasureFieldSelect --> Measure for Even or Odd Field
//                EnumMeasureBoundType --> OverScan Boundary or Normal Boundary
//                usHTotal --> H Total
// Output Value : None
//--------------------------------------------------
void ScalerMeasureSetAuto(EnumMeasureModeType enumMeasureType, EnumMeasureFieldSelect enumFieldSelect, EnumMeasureBoundType enumBoundType, WORD usHTotal)
{
    WORD usHLbound = 0;
    WORD usHRbound = 0;
    WORD usHSWidth = 0;
    WORD usVSWidth = 0;

    // Disable auto-function
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, 0x00);

    if(enumFieldSelect == _EVEN_FIELD_MEASURE)
    {
        // Field Select to Even, Disable LPF, Disable Accelecration Mode, Vertical Boundary Search 1 pixel, Select B channel
        ScalerSetByte(CM_7A_AUTO_ADJ_CTRL0, 0x80);
    }
    else if(enumFieldSelect == _ODD_FIELD_MEASURE)
    {
        // Field Select to Odd, Disable LPF, Disable Accelecration Mode, Vertical Boundary Search 1 pixel, Select B channel
        ScalerSetByte(CM_7A_AUTO_ADJ_CTRL0, 0xC0);
    }
    else
    {
        // Disable Field Select, Disable LPF, Disable Accelecration Mode, Vertical Boundary Search 1 pixel, Select B channel
        ScalerSetByte(CM_7A_AUTO_ADJ_CTRL0, 0x00);
    }

    if(enumMeasureType == _ANALOG_MODE_MEASURE)
    {
        // Convert to positive if input sync is negative.
        usHSWidth = GET_INPUT_TIMING_HSYNCWIDTH();

        // Sync Pulse should be smaller than 1/2 period.
        usVSWidth = GET_INPUT_TIMING_VSYNCWIDTH();

#if(_VGA_SUPPORT == _ON)
        // L Boundary position reference clamp signal end position add 0x05 tolerance
        // Notice: clamp signal start position reference HS trailing edge
        usHLbound = ScalerSyncProcGetClampEndPosition() + 0x05;
#endif

        // Calculate left boundary.
        // Unit Conversion Formula: Left Boundary = HPeriod Pixel Clock * (H-Sync Pulse Didth / H-Sync Period) + Clamp End
        usHLbound += (((DWORD)usHTotal * usHSWidth) / GET_SYNC_H_PERIOD());

        // Input signal is positive polarity
        if((bit)GET_INPUT_TIMING_H_POLARITY() == _TRUE)
        {
            usHRbound = (((DWORD)_NOISE_DELAY_BEFORE_HSYNC_POSITIVE * GET_INPUT_PIXEL_CLK()) / 10000) + 1;
        }
        else
        {
            usHRbound = (((DWORD)_NOISE_DELAY_BEFORE_HSYNC_NEGTIVE * GET_INPUT_PIXEL_CLK()) / 10000) + 1;
        }

        usHRbound = usHTotal - usHRbound;

    	// Set H boundary
        ScalerMeasureAutoFuncHBoundInitial(usHLbound, usHRbound);

        // Set V Boundary
        ScalerMeasureAutoFuncVBoundInitial((usVSWidth + _NOISE_WIDTH_AFTER_VSYNC), (GET_INPUT_TIMING_VTOTAL() - 2));

        // Set noice margin according to current clamp type for VGA
        ScalerRead(P0_CF_ADC_CTL_RED, 3, pData, _AUTOINC);

        if(((pData[0] & _BIT7) == _BIT7) && ((pData[2] & _BIT7) == _BIT7) && ((pData[1] & _BIT7) == 0x00))
        {
            // Set Noise Margin
            ScalerSetBit(CM_76_RED_NOISE_MARGIN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0xFC);
            ScalerSetBit(CM_77_GRN_NOISE_MARGIN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), ((_VGA_NOISE_MARGIN) & 0xFC));
            ScalerSetBit(CM_78_BLU_NOISE_MARGIN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0xFC);
        }
        else
        {
            // Set Noise Margin
            ScalerSetBit(CM_76_RED_NOISE_MARGIN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), ((_VGA_NOISE_MARGIN) & 0xFC));
            ScalerSetBit(CM_77_GRN_NOISE_MARGIN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), ((_VGA_NOISE_MARGIN) & 0xFC));
            ScalerSetBit(CM_78_BLU_NOISE_MARGIN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), ((_VGA_NOISE_MARGIN) & 0xFC));
        }

        // Analog Measure Mode, Select Software Mode, Select Software Mode, Select Auto Balance, Start Auto Function Measure
        ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT7 | _BIT6 | _BIT1), 0x00);
    }
    else
    {
    	// Set H boundary
        ScalerMeasureAutoFuncHBoundInitial(0x0002, usHTotal);

        // Set V Boundary
        ScalerMeasureAutoFuncVBoundInitial(0x0002, GET_INPUT_TIMING_VTOTAL());

        // Digital Measure Mode, Select Auto Balance, Start Auto Function Measure
        ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT7 | _BIT6 | _BIT1), _BIT7);
    }

    if(enumBoundType == _OVERSCAN_BOUNDARY)
    {
        if(g_stInputTimingData.usVHeight >= ScalerVgipGetCaptureVHeight())
        {
            // Set V Boundary
            ScalerMeasureAutoFuncVBoundInitial((usVSWidth + _NOISE_WIDTH_AFTER_VSYNC + ((g_stInputTimingData.usVHeight - ScalerVgipGetCaptureVHeight()) / 2)), (GET_INPUT_TIMING_VTOTAL() - 2 - ((g_stInputTimingData.usVHeight - ScalerVgipGetCaptureVHeight()) / 2)));

            // Analog Measure Mode, Select Software Mode, Select Software Mode, Select Auto Balance, Start Auto Function Measure
            ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT7 | _BIT6 | _BIT1), 0x00);
        }
    }

    // Start auto-function measure
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : Pop Up Auto-Function Result
// Input Value  : stActiveRegion --> measure result
//                bWait --> wait auto-function stop or not
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerMeasureGetAutoResult(StructAutoActiveData *stActiveRegion, bit bWait)
{
    BYTE ucVdelayCount = 0;
    BYTE ucRepeatCount = 0;

    while(ucRepeatCount < 2) // Maximum Measure Time is 2 times
    {
        if((bWait == _WAIT) || (ScalerGetBit(CM_7D_AUTO_ADJ_CTRL1, _BIT6) == 0x00))
        {
            if(ScalerMeasureAutoFuncWaitFinish() == _FALSE)
            {
                return _FALSE;
            }
        }

        // Calculate delay for auto-function VS
        switch(ScalerGetBit(CM_1E_VGIP_HV_DELAY, (_BIT5 | _BIT4)))
        {
            case 0x00:
                ucVdelayCount = 0;
                break;
                
            case _BIT4:           
                ucVdelayCount = 3;
                break;
                
            case _BIT5:
                ucVdelayCount = 7;            
                break;    
                
            case (_BIT5 | _BIT4): 
                ucVdelayCount = 15;            
                break;
        }

        stActiveRegion->usVActiveStart = (((WORD)(ScalerGetByte(CM_7E_V_START_END_H) & 0xF0) << 4) | ScalerGetByte(CM_7F_V_START_L)) + ucVdelayCount;
        stActiveRegion->usVActiveEnd = (((WORD)(ScalerGetByte(CM_7E_V_START_END_H) & 0x0F) << 8) | ScalerGetByte(CM_80_V_END_L)) + ucVdelayCount;

        DebugMessageAnalog("5.Active Measure V-ActiveStart", stActiveRegion->usVActiveStart);
        DebugMessageAnalog("5.Active Measure V-VActiveEnd", stActiveRegion->usVActiveEnd);
        
        if(ScalerGetBit(CM_7D_AUTO_ADJ_CTRL1, _BIT7) == _BIT7)
        {
            stActiveRegion->usHActiveStart = (((WORD)(ScalerGetByte(CM_81_H_START_END_H) & 0xF0) << 4) | ScalerGetByte(CM_82_H_START_L)) + 1;
            stActiveRegion->usHActiveEnd = (((WORD)(ScalerGetByte(CM_81_H_START_END_H) & 0x0F) << 8) | ScalerGetByte(CM_83_H_END_L)) + 1;
        }
        else
        {
            stActiveRegion->usHActiveStart = (((WORD)(ScalerGetByte(CM_81_H_START_END_H) & 0xF0) << 4) | ScalerGetByte(CM_82_H_START_L));
            stActiveRegion->usHActiveEnd = (((WORD)(ScalerGetByte(CM_81_H_START_END_H) & 0x0F) << 8) | ScalerGetByte(CM_83_H_END_L));
        }

        // Check auto-function measure result
        if((stActiveRegion->usVActiveStart == ucVdelayCount) ||
           (stActiveRegion->usVActiveEnd == ucVdelayCount)  ||
           (stActiveRegion->usHActiveStart == 0x00) ||
           (stActiveRegion->usHActiveEnd == 0x00))
        {                
            stActiveRegion->usHActiveStart = 0x00;
            stActiveRegion->usHActiveEnd = 0x00;
            stActiveRegion->usVActiveStart = 0x00;
            stActiveRegion->usVActiveEnd = 0x00;

            // Return fail for digital measure
            if(ScalerGetBit(CM_7D_AUTO_ADJ_CTRL1, _BIT7) == _BIT7)
            {
                return _FALSE;
            }
        }

#if(_VGA_SUPPORT == _ON)
        // Check auto-function boundary setting for analog measure
        if((ScalerGetBit(CM_7D_AUTO_ADJ_CTRL1, _BIT7) == 0x00) &&
           (ucRepeatCount == 0))
        {
            // Clear wait flag
            bWait = _NOT_WAIT;

            // Get current auto-function boundories
            PDATA_WORD(0) = ((((WORD)ScalerGetByte(CM_70_H_BOUNDARY_H) & 0xF0) << 4) | ScalerGetByte(CM_71_H_BOUNDARY_STA_L)); // H start
            PDATA_WORD(1) = ((((WORD)ScalerGetByte(CM_70_H_BOUNDARY_H) & 0x0F) << 8) | ScalerGetByte(CM_72_H_BOUNDARY_END_L)); // H end
            PDATA_WORD(2) = ((((WORD)ScalerGetByte(CM_73_V_BOUNDARY_H) & 0xF0) << 4) | ScalerGetByte(CM_74_V_BOUNDARY_STA_L)) + ucVdelayCount; // V start

            // Check auto-boundary H start
            if(stActiveRegion->usHActiveStart == PDATA_WORD(0))
            {
                // Set H start = H_width + H_clamp_end + 2
                PDATA_WORD(0) -= 3;

                bWait = _WAIT;
            }

            // Check auto-boundary H end
            if(stActiveRegion->usHActiveEnd == PDATA_WORD(1))
            {
                // Enlarge H R-Bounday delta = 1/2 noise margin width
                if(GET_INPUT_TIMING_H_POLARITY() == _TRUE)
                {
                    PDATA_WORD(1) += (((DWORD)_NOISE_DELAY_BEFORE_HSYNC_POSITIVE * GET_INPUT_PIXEL_CLK()) / 20000);
                }
                else
                {
                    PDATA_WORD(1) += (((DWORD)_NOISE_DELAY_BEFORE_HSYNC_NEGTIVE * GET_INPUT_PIXEL_CLK()) / 20000);
                }

                bWait = _WAIT;
            }

            // Check auto-boundary V start
            if(stActiveRegion->usVActiveStart == PDATA_WORD(2))
            {
                if(ScalerGetBit(CM_1E_VGIP_HV_DELAY, (_BIT5 | _BIT4)) != 0x00)
                {
                    // Disable IVS delay when V porch region is too short 
                    ScalerSetBit(CM_1E_VGIP_HV_DELAY, ~(_BIT5 | _BIT4), 0x00);
                    bWait = _WAIT;
                }
            }

            // Restart auto-function measure
            if(bWait == _WAIT)
            {            
                // Adjust auto-function H boundary
                ScalerMeasureAutoFuncHBoundInitial(PDATA_WORD(0), PDATA_WORD(1));

                // Restart auto-function measure
                ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, 0x00);
                ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, _BIT0);

                ++ucRepeatCount;
                continue;
            }
            else
            {
                break;
            }
        }
#endif

        break;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Update timing info HS/VS polarity
// Input Value  : ucSourceType --> source type
//                stMeasureSyncHV --> measured timing data
// Output Value : None
//--------------------------------------------------
void ScalerMeasureUpdateInputTimingPolarity(BYTE ucSourceType, StructMeasureSyncData *stMeasureSyncHV)
{
    switch(ucSourceType)
    {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))
        case _SOURCE_HDMI:
        case _SOURCE_DVI:

            if(ScalerGetBit(P2_A7_POWER_ON_OFF_CTRL, _BIT7) == _BIT7)
            {
                // Measure polarity only when raw HS/VS are available                
                if(ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
                {        
                    // Clear IVS status; Assue that a DE-only-VS just passed
                    ScalerSetByte(CM_03_STATUS1, 0x00);
                    
                    // Set to raw HS/VS
                    ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~_BIT7, 0x00);

                    // Set to analog measure
                    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT0, 0x00);

                    // Polling 3ms for raw IVS
                    ScalerTimerPollingFlagProc(4, CM_03_STATUS1, _BIT0, _TRUE);

                    // Toggle VS measure invert enable
                    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT2, (~ ScalerGetByte(CM_4F_STABLE_MEASURE) & _BIT2));
                    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT2, (~ ScalerGetByte(CM_4F_STABLE_MEASURE) & _BIT2));                

                    // Wait 3ms to allow at least 32 HS occur
                    ScalerTimerDelayXms(4);

                    // Toggle VS measure invert enable
                    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT2, (~ ScalerGetByte(CM_4F_STABLE_MEASURE) & _BIT2));
                    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT2, (~ ScalerGetByte(CM_4F_STABLE_MEASURE) & _BIT2));    

                    // Pop out HS polarity
                    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT6, _BIT6);
                    g_stInputTimingData.b1HSP = (ScalerGetBit(CM_54_MEAS_VS_PER_H, _BIT6) == _BIT6);
                    
                    // Resume DE-only mode
                    ScalerSetBit(P2_A7_POWER_ON_OFF_CTRL, ~_BIT7, _BIT7);

                    // VS polarity from TMDS MAC
                    g_stInputTimingData.b1VSP = (ScalerGetBit(P2_C0_HDCP_CTRL, _BIT5) == 0x00);        
                }   
                else
                {
                    // Positive HS/VS under DE-only mode
                    g_stInputTimingData.b1HSP = _TRUE;
                    g_stInputTimingData.b1VSP = _TRUE;
                }
            }
            else
            {
                g_stInputTimingData.b1HSP = stMeasureSyncHV->b1HSP;
                g_stInputTimingData.b1VSP = stMeasureSyncHV->b1VSP;
            }

            break;
#endif            

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:

            // Pop out DP polarity
            ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_00_MN_STRM_ATTR_CTRL, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            g_stInputTimingData.b1HSP = (ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_0A_MN_STRM_ATTR_HSW_M, _BIT7) == 0x00);
            g_stInputTimingData.b1VSP = (ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_14_MN_STRM_ATTR_VSW_M, _BIT7) == 0x00);

            break;
#endif            

#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:        

            // Get Raw HSync Polarity by SyncProcessor Auto Run            
            if(ScalerGetBit(CM_47_SYNC_SELECT, _BIT6) == _BIT6)
            {
                g_stInputTimingData.b1HSP = (bit)(stMeasureSyncHV->b1HSP ^ (((bit)ScalerGetBit(CM_48_SYNC_INVERT, _BIT3) ? _BIT0 : 0x00) ^ ((bit)ScalerGetBit(CM_50_STABLE_PERIOD_H, _BIT6) ? _BIT0 : 0x00)));
            }
            else
            {
                g_stInputTimingData.b1HSP = (bit)(stMeasureSyncHV->b1HSP ^ (((bit)ScalerGetBit(CM_48_SYNC_INVERT, _BIT3) ? _BIT0 : 0x00)));
            }

            g_stInputTimingData.b1VSP = (stMeasureSyncHV->b1VSP ^ (bit)ScalerGetBit(CM_4F_STABLE_MEASURE, _BIT2));
            
            break;
#endif            
    }
}

//--------------------------------------------------
// Description  : Update timing info from measure
// Input Value  : stMeasureSyncHV --> measure result
//                stActiveRegion --> auto-function result
//                stInputTimingData --> input timing data
// Output Value : None
//--------------------------------------------------
void ScalerMeasureUpdateInputTimingData(StructMeasureSyncData *stMeasureSyncHV, StructAutoActiveData *stActiveRegion)
{
    // Update measure block result
    if(ScalerGetBit(CM_49_SYNC_CTRL, (_BIT1 | _BIT0)) == _BIT1)
    {
        // Update analog measure result
        g_stInputTimingData.usHSWidth = (2 * stMeasureSyncHV->usHSWidth >= stMeasureSyncHV->usHSPeriod) ? (stMeasureSyncHV->usHSPeriod - stMeasureSyncHV->usHSWidth) : stMeasureSyncHV->usHSWidth;
    }
    else
    {   
        // Update digital measure result
        g_stInputTimingData.usHSWidth = (stMeasureSyncHV->b1HSP == _TRUE) ? stMeasureSyncHV->usHSWidth : (stMeasureSyncHV->usHSPeriod - stMeasureSyncHV->usHSWidth);
    }

    g_stInputTimingData.usVSWidth = ((stMeasureSyncHV->b1VSP == _TRUE) ? stMeasureSyncHV->usVSWidth : (stMeasureSyncHV->usVSPeriod - stMeasureSyncHV->usVSWidth));
    g_stInputTimingData.usHFreq = (_SYNC_PROC_CLK * 10 * 2 / stMeasureSyncHV->usHSPeriod + 1) / 2;
    g_stInputTimingData.usVFreq = (_SYNC_PROC_CLK * 1000 * 10 * 2 / stMeasureSyncHV->usHSPeriod / stMeasureSyncHV->usVSPeriod + 1) / 2;

    g_stInputTimingData.usVTotal = stMeasureSyncHV->usVSPeriod;    

    // Update auto-function result
    g_stInputTimingData.usHStart = stActiveRegion->usHActiveStart;
    g_stInputTimingData.usHWidth = (stActiveRegion->usHActiveEnd - stActiveRegion->usHActiveStart) + 1;
    g_stInputTimingData.usVStart = stActiveRegion->usVActiveStart;
    g_stInputTimingData.usVHeight = (stActiveRegion->usVActiveEnd - stActiveRegion->usVActiveStart) + 1;
}

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Check V start position for interlaced format
// Input Value  : usVstart --> alternative V start
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerMeasureCheckInterlaceVst(WORD usVstart)
{                
    if(abs(usVstart - g_stActiveRegion.usVActiveStart) == 0x01)
    {
        // Store the smaller Vstart
        if(usVstart < g_stActiveRegion.usVActiveStart)
        {
            --g_stActiveRegion.usVActiveStart;
            --g_stActiveRegion.usVActiveEnd;
        }

        // Enable ODD delay one line
        ScalerSetBit(CM_13_VGIP_ODD_CTRL, ~(_BIT7 |_BIT6), _BIT6);

        // Toggle Video Compensation field
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT6, (~(ScalerGetByte(CM_32_SCALE_CTRL)) & _BIT6));            

        // Wait 1 IVS if field source toggled
        if(ScalerGetBit(CM_13_VGIP_ODD_CTRL, _BIT0) != _BIT0)
        {
            if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
            {
                return _FALSE;
            }
        }

        // Start auto-function
        ScalerMeasureSetAuto(_DIGITAL_MODE_MEASURE, _NORMAL_MEASURE, _FULL_BOUNDARY, 0xFFF);        

        // Pop up auto-function result
        if(ScalerMeasureGetAutoResult((StructAutoActiveData *)pData, _WAIT) == _FALSE)
        {
            return _FALSE;
        }

        usVstart = ((StructAutoActiveData *)pData)->usVActiveStart;

        // Double-check delay-one-line field polarity
        if(usVstart != g_stActiveRegion.usVActiveStart)
        {                
            // Toggle delay-one-line field
            ScalerSetBit(CM_13_VGIP_ODD_CTRL, ~_BIT7, (~(ScalerGetByte(CM_13_VGIP_ODD_CTRL)) & _BIT7));
        }
    }    

    return _TRUE;    
}

//--------------------------------------------------
// Description  : Measure H width for the first line
// Input Value  : usFrameHwidth: H width from measure block
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerMeasureCheckFirstLineShift(WORD usFrameHwidth)
{
    // Stop auto-function; Set digital measure
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT7 | _BIT6 | _BIT0), _BIT7);
    
    // Set measure boundary to first line
    ScalerMeasureAutoFuncHBoundInitial(0x0002, 0x0FFF);
    ScalerMeasureAutoFuncVBoundInitial((GET_ACTIVE_V_START() + 1), GET_INPUT_TIMING_VTOTAL());

    // Start auto-function measure
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, _BIT0);

    if((ScalerTimerWaitForEvent(_EVENT_IVS) == _FAIL) ||
       (ScalerTimerWaitForEvent(_EVENT_IVS) == _FAIL))
    {
        return _FAIL;
    }

    // Calculate first H width
    PDATA_WORD(0) = ((((WORD)ScalerGetBit(CM_81_H_START_END_H, 0xF0)) << 4) | ScalerGetByte(CM_82_H_START_L)); // H st
    PDATA_WORD(1) = ((((WORD)ScalerGetBit(CM_81_H_START_END_H, 0x0F)) << 8) | ScalerGetByte(CM_83_H_END_L)); // H end
    PDATA_WORD(2) = (PDATA_WORD(1) - PDATA_WORD(0) + 1); // H width

    return (abs(PDATA_WORD(2) - usFrameHwidth) <= 1);
}

#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

//--------------------------------------------------
// Description  : Waiting for Auto Function Measure Finish
// Input Value  : None
// Output Value : True --> Measure Finish
//                False --> Measure Timeout or Fail
//--------------------------------------------------
bit ScalerMeasureAutoFuncWaitFinish(void)
{
    BYTE ucIvsCnt = 0;

    ucIvsCnt = (ScalerGetBit(CM_7A_AUTO_ADJ_CTRL0, _BIT1 | _BIT0) == 0x03) ? 3 : 1;
    ucIvsCnt = (ScalerGetBit(CM_7A_AUTO_ADJ_CTRL0, _BIT7) == _BIT7) ? ucIvsCnt * 2 : ucIvsCnt;
    ucIvsCnt += 2;

    do
    {

        if(ScalerGetBit(CM_10_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) // VGA Measure
        {
            if(ScalerGetBit(CM_4E_HSYNC_TYPE_DETECTION_FLAG, (_BIT7 | _BIT6 | _BIT5 | _BIT3)) != 0x00)
            {
                // Sync is changing
                return _FALSE;
            }
        }

        if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
        {
            return _FALSE;
        }

        if(ScalerGetBit(CM_7D_AUTO_ADJ_CTRL1, _BIT0) == 0x00)
        {
            return _TRUE;
        }
    }
    while(--ucIvsCnt);

    if(ucIvsCnt == 0)
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Initial H Boundary for Auto Function Measure
// Input Value  : H Boundary Start/End
// Output Value : None
//--------------------------------------------------
void ScalerMeasureAutoFuncHBoundInitial(WORD usHBoundStart, WORD usHBoundEnd)
{
	// Set H boundary
	ScalerSetByte(CM_70_H_BOUNDARY_H, (((HIBYTE(usHBoundStart) & 0x0F) << 4) | (HIBYTE(usHBoundEnd) & 0x0F)));
	ScalerSetByte(CM_71_H_BOUNDARY_STA_L, LOBYTE(usHBoundStart));
	ScalerSetByte(CM_72_H_BOUNDARY_END_L, LOBYTE(usHBoundEnd));
}

//--------------------------------------------------
// Description  : Initial V Boundary for Auto Function Measure
// Input Value  : V Boundary Start/End
// Output Value : None
//--------------------------------------------------
void ScalerMeasureAutoFuncVBoundInitial(WORD usVBoundStart, WORD usVBoundEnd)
{
	// Set H boundary
    ScalerSetByte(CM_73_V_BOUNDARY_H, (((HIBYTE(usVBoundStart) & 0x0F) << 4) | (HIBYTE(usVBoundEnd) & 0x0F)));
    ScalerSetByte(CM_74_V_BOUNDARY_STA_L, LOBYTE(usVBoundStart));
    ScalerSetByte(CM_75_V_BOUNDARY_END_L, LOBYTE(usVBoundEnd));
}


#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Phase, MaxSOD, MinSOD Search
// Input Value  : enumPhaseStep --> Hardware Auto Search Phase Step
//                ucPhaseResult --> Best Phase(with Max SOD)
//                ulSODMax --> Max SOD Value
//                ulSODMin --> Min SOD Value
//                enumSODMethod --> SOD or WSOD Selection
// Output Value : True --> SOD Measurement ok, False --> SOD Measurement Fail
//--------------------------------------------------
bit ScalerMeasureHWAutoPhaseSearch(EnumAutoPhaseSearchStep enumPhaseStep, BYTE *ucPhaseResult, DWORD *ulSODMax, DWORD *ulSODMin, EnumAutoPhaseSearchSODMethod enumSODMethod, BYTE ucSODThreshold)
{
    BYTE ucTargetPhase = 0;
    BYTE ucBestPhase = 0;
    BYTE ucPhaseStepNum = 0;
    DWORD ulSOD1st = 0;
    DWORD ulSOD2nd = 0;

    *ulSODMax = 0;

    *ulSODMin = 0xffffffff;

    // Set Difference Threshold
    ScalerSetByte(CM_79_DIFF_THRESHOLD, ucSODThreshold);

    // Hardware Auto Measure Trigger Select to IVS, Initial Phase --> 0.
    ScalerSetByte(CM_7C_HW_AUTO_PHASE_CTRL1, 0x00);

    // Field Select Disable, LPF Disable, 1 pixel over Threshold, Enable Accelaration Mode, Select R or G or B Channel
    ScalerSetByte(CM_7A_AUTO_ADJ_CTRL0, 0x10);

    ucPhaseStepNum = (64 / (1 << enumPhaseStep));

    if(ScalerGetBit(P1_B1_PLLDIV_H, _BIT4) == _BIT4)
    {
        enumPhaseStep = enumPhaseStep + 1;
    }

    // Set Phase Step and Number
    ScalerSetByte(CM_7B_HW_AUTO_PHASE_CTRL0, (enumPhaseStep & 0x07) | (((ucPhaseStepNum - 1) & 0x1f) << 3));

    enumPhaseStep = (1 << enumPhaseStep);

    // Hardware Auto Measure Setting, and stop Auto-Function Measure Function, Start Measure
    ScalerSetByte(CM_7D_AUTO_ADJ_CTRL1, 0x7B);

    ScalerTimerWaitForEvent(_EVENT_IVS);

    if(enumSODMethod == _PHASE_SEARCH_SOD)
    {
        do
        {
            if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
            {
                return _FALSE;
            }

            ScalerRead(CM_84_AUTO_PHASE_3, 4, pData, _AUTOINC);

            if(PDATA_DWORD(0) > *ulSODMax)
            {
                *ulSODMax = PDATA_DWORD(0);
                ucBestPhase = ucTargetPhase;
            }

            if(PDATA_DWORD(0) < *ulSODMin)
            {
                *ulSODMin = PDATA_DWORD(0);
            }

            ucTargetPhase += enumPhaseStep;

            ucPhaseStepNum--;
        }
        while(ucPhaseStepNum > 0);
    }
    else
    {
        ucPhaseStepNum = ucPhaseStepNum + 2;

        PDATA_DWORD(1) = 0;
        PDATA_DWORD(2) = 0;
        PDATA_DWORD(3) = 0;

        do
        {
            PDATA_DWORD(3) = PDATA_DWORD(2);

            PDATA_DWORD(2) = PDATA_DWORD(1);

            if(ucPhaseStepNum == 2)
            {
                PDATA_DWORD(1) = ulSOD1st;
            }
            else if(ucPhaseStepNum == 1)
            {
                PDATA_DWORD(1) = ulSOD2nd;
            }
            else
            {
                if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
                {
                    return _FALSE;
                }

                ScalerRead(CM_84_AUTO_PHASE_3, 4, pData, _AUTOINC);

                PDATA_DWORD(1) = PDATA_DWORD(0);

                if(ucTargetPhase == 0x00)
                {
                    ulSOD1st = PDATA_DWORD(0);
                }

                if(ucTargetPhase == enumPhaseStep)
                {
                    ulSOD2nd = PDATA_DWORD(0);
                }
            }

            if(PDATA_DWORD(2) > (ABSDWORD(PDATA_DWORD(3), PDATA_DWORD(2)) + ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))))
            {
                PDATA_DWORD(0) = PDATA_DWORD(2) - ((ABSDWORD(PDATA_DWORD(3), PDATA_DWORD(2)) + ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))));

                if(PDATA_DWORD(0) > *ulSODMax)
                {
                    *ulSODMax = PDATA_DWORD(0);

                    ucBestPhase = ucTargetPhase - enumPhaseStep;
                }
            }

            ucTargetPhase += enumPhaseStep;

            ucPhaseStepNum--;
        }
        while(ucPhaseStepNum > 0);
    }

    // Stop Hardware Auto-Function Measure
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT6 | _BIT0), 0x00); // wuzanne1493

    if(ScalerGetBit(P1_B1_PLLDIV_H, _BIT4) != 0x00) // DotClock < _APLL_VCO_DEVIDER_4_2_THERSHOLD
    {
        *ucPhaseResult = ((ucBestPhase / 2) % 64);
    }
    else
    {
        *ucPhaseResult = (ucBestPhase % 64);
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  :
// Input Value  : Firmware Auto Measure SOD Value
// Output Value : True --> Measure Success
//                False --> Measure Fail
//--------------------------------------------------
bit ScalerMeasureAutoPhaseGetSOD(DWORD * ulSODValue)
{
    // Firmware Measure Setting, and stop Auto-Function Measure Function, Start Measure
    ScalerSetByte(CM_7D_AUTO_ADJ_CTRL1, 0x3B);

    if(ScalerMeasureAutoFuncWaitFinish() == _FALSE)
    {
        // Hw Auto Status Initial
        ScalerSetByte(CM_7D_AUTO_ADJ_CTRL1, 0x00);

        return _FALSE;
    }

    // Get Phase Result
    ScalerRead(CM_84_AUTO_PHASE_3, 4, (BYTE *)ulSODValue, _AUTOINC);

    return _TRUE;
}
#endif // End of #if(_VGA_SUPPORT == _ON)
