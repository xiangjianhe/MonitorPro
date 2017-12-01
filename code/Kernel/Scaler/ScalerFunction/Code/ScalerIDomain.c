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
// ID Code      : ScalerIDomain.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_IDOMAIN__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define GET_VGIP_INITIAL_VDELAY()                   (g_ucVgipVDelayInitial)
#define SET_VGIP_INITIAL_VDELAY(x)                  (g_ucVgipVDelayInitial = x)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucVgipVDelayInitial = 0;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerIDomainVgipSetInputCapture(void);
WORD ScalerIDomainVgipIHCaptureMaxEstimate(WORD usHPosition);
void ScalerIDomainVgipAdjustIHVDelay(void);
void ScalerIDomainFineTuneHCaptureStart(WORD usDeltaIHCapture);

#if(_VGA_SUPPORT == _ON)
WORD ScalerIDomainSearchHsEdge(void);
void ScalerIDomainModifyHsLatchEdgeDelay(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set VGIP Capture Window
// Input Value  : Capture Type, H/V Active and Start
// Output Value : None
//--------------------------------------------------
void ScalerIDomainVgipSetInputCapture(void)
{
    WORD xdata usIHDelay = 0;
    
#if(_2D_TO_3D_FUNCTION == _ON)
    if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE) // 3D Misc Double buffer disable    
#endif
    {
        // Set Analog Capture Type
        ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT1, 0x00);    
        
#if(_2D_TO_3D_FUNCTION == _ON)
        // For Frame packing 480p, VHeight = 1005
        if(GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT)
        {
            g_stMDomainInputData.usVHeight += g_stMDomainInputData.usVHeight % 2;
        }
#endif
    
        if(g_stMDomainInputData.usHStart <= _VGIP_IH_CAPTURE_MIN_VALUE)
        {
            g_stMDomainInputData.usHStart = _VGIP_IH_CAPTURE_MIN_VALUE + 1;
        }

        usIHDelay = g_stMDomainInputData.usHStart - ScalerIDomainVgipIHCaptureMaxEstimate(g_stMDomainInputData.usHStart);

        g_stMDomainInputData.usHStart = ScalerIDomainVgipIHCaptureMaxEstimate(g_stMDomainInputData.usHStart);
        
        // Set H Capture
        ScalerSetByte(CM_14_IPH_ACT_STA_H, (((HIBYTE(g_stMDomainInputData.usHWidth) & 0x0F) << 4) | (HIBYTE(g_stMDomainInputData.usHStart - 2) & 0x0F)));
        ScalerSetByte(CM_15_IPH_ACT_STA_L, LOBYTE(g_stMDomainInputData.usHStart - 2)); 
        ScalerSetByte(CM_17_IPH_ACT_WID_L, LOBYTE(g_stMDomainInputData.usHWidth));

        // Front Porch is Not Enough
        if(g_stMDomainInputData.usVStart + g_stMDomainInputData.usVHeight + 3 >= g_stMDomainInputData.usVTotal)
        {
            // Increase Front Porch by VDelay
            SET_VGIP_INITIAL_VDELAY(g_stMDomainInputData.usVStart + g_stMDomainInputData.usVHeight + 3 - g_stMDomainInputData.usVTotal);
            g_stMDomainInputData.usVStart -= GET_VGIP_INITIAL_VDELAY();
        }
        else
        {
            SET_VGIP_INITIAL_VDELAY(0);
        }

        // Check if V capture start exceeds maximum value
        if(g_stMDomainInputData.usVStart > _VGIP_IV_CAPTURE_MAX_VALUE)
        {
            SET_VGIP_INITIAL_VDELAY(GET_VGIP_INITIAL_VDELAY() + (BYTE)(g_stMDomainInputData.usVStart - _VGIP_IV_CAPTURE_MAX_VALUE));
            g_stMDomainInputData.usVStart = _VGIP_IV_CAPTURE_MAX_VALUE;
        }
   
        // Set V Capture
        ScalerSetByte(CM_18_IPV_ACT_STA_H, (((HIBYTE(g_stMDomainInputData.usVHeight) & 0x0F) << 4) | (HIBYTE(g_stMDomainInputData.usVStart) & 0x0F)));
        ScalerSetByte(CM_19_IPV_ACT_STA_L, LOBYTE(g_stMDomainInputData.usVStart));
        ScalerSetByte(CM_1B_IPV_ACT_LEN_L, LOBYTE(g_stMDomainInputData.usVHeight));
        
        ScalerVgipSetCaptureHDelay(usIHDelay);        
        ScalerVgipSetCaptureVDelay(GET_VGIP_INITIAL_VDELAY());    
        
        DebugMessageScaler("9. Set Capture usHWidth", g_stMDomainInputData.usHWidth);
        DebugMessageScaler("9. Set Capture usHStart", g_stMDomainInputData.usHStart);    
        DebugMessageScaler("9. Set Capture usVHeight", g_stMDomainInputData.usVHeight);
        DebugMessageScaler("9. Set Capture usVStart", g_stMDomainInputData.usVStart);
    }    
}

//--------------------------------------------------
// Description  : Estimate Max Allowable H Capture Start
// Input Value  : Current H Start
// Output Value : Max Allowable H Start
//--------------------------------------------------
WORD ScalerIDomainVgipIHCaptureMaxEstimate(WORD usHPosition)
{
    if(usHPosition <= (_VGIP_IH_DELAY_MAX_VALUE + _VGIP_IH_CAPTURE_MIN_VALUE - (_MAX_H_POSITION_RANGE / 2)))
    {
        return _VGIP_IH_CAPTURE_MIN_VALUE;
    }
    else
    {
        return (usHPosition - (_VGIP_IH_DELAY_MAX_VALUE - (_MAX_H_POSITION_RANGE / 2)));
    }
}

//--------------------------------------------------
// Description  : Adjust IVS/IHS Delay to Gain Largest Position-Adjusting Range
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerIDomainVgipAdjustIHVDelay(void)
{
#if((_3D_SUPPORT == _ON) || (_FRC_SUPPORT == _ON))
    if((GET_MEMORY_SELECT() != _FRAME_SYNC_LINE_BUFFER) && (GET_MEMORY_SELECT() != _FREE_RUN_NO_INPUT))
    {        
        // Set IVS Delay
        ScalerVgipSetCaptureVDelay(g_stMDomainInputData.usVStart - _VGIP_IV_CAPTURE_MIN_VALUE + GET_VGIP_INITIAL_VDELAY());
        
        // Set V Start
        g_stMDomainInputData.usVStart = _VGIP_IV_CAPTURE_MIN_VALUE;
        ScalerSetBit(CM_18_IPV_ACT_STA_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(g_stMDomainInputData.usVStart) & 0x0F));
        ScalerSetByte(CM_19_IPV_ACT_STA_L, LOBYTE(g_stMDomainInputData.usVStart));
    }
    else
    {        
        // Remain IVSt = Raw IVSt - IVSDelay
        g_stMDomainInputData.usVStart = g_stMDomainInputData.usVStart - ((WORD)ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES));

        if(g_stMDomainInputData.usVStart < _VGIP_IV_CAPTURE_MIN_VALUE)
        {
            DebugMessageScaler("VStart too Small", g_stMDomainInputData.usVStart);
            
            // Get Difference of Remain IVSt and _VGIP_IV_CAPTURE_MIN_VALUE
            pData[0] = _VGIP_IV_CAPTURE_MIN_VALUE - g_stMDomainInputData.usVStart;
            g_stMDomainInputData.usVStart = _VGIP_IV_CAPTURE_MIN_VALUE;
        }
        else
        {
            pData[0] = 0;
        }

        // Move Delay to ivs to dvs
        ScalerSetBit(CM_18_IPV_ACT_STA_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(g_stMDomainInputData.usVStart) & 0x0F));
        ScalerSetByte(CM_19_IPV_ACT_STA_L, LOBYTE(g_stMDomainInputData.usVStart));

        // Set IVS to DVS Delay
        ScalerVgipSetCaptureVDelay((WORD)(ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES) - pData[0]) + GET_VGIP_INITIAL_VDELAY());

        // Modify Corresponding IVS2DVS Delay
        ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[0]);
    }
    
#else // Else of #if((_3D_SUPPORT == _ON) || (_FRC_SUPPORT == _ON))
    
    // Remain IVSt = Raw IVSt - IVSDelay
    g_stMDomainInputData.usVStart = g_stMDomainInputData.usVStart - ((WORD)ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES));

    if(g_stMDomainInputData.usVStart < _VGIP_IV_CAPTURE_MIN_VALUE)
    {
        DebugMessageScaler("VStart too Small", g_stMDomainInputData.usVStart);
        
        // Get Difference of Remain IVSt and _VGIP_IV_CAPTURE_MIN_VALUE
        pData[0] = _VGIP_IV_CAPTURE_MIN_VALUE - g_stMDomainInputData.usVStart;
        g_stMDomainInputData.usVStart = _VGIP_IV_CAPTURE_MIN_VALUE;
    }
    else
    {
        pData[0] = 0;
    }

    // Move Delay to ivs to dvs
    ScalerSetBit(CM_18_IPV_ACT_STA_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(g_stMDomainInputData.usVStart) & 0x0F));
    ScalerSetByte(CM_19_IPV_ACT_STA_L, LOBYTE(g_stMDomainInputData.usVStart));

    // Set IVS to DVS Delay
    ScalerVgipSetCaptureVDelay((WORD)(ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES) - pData[0] + GET_VGIP_INITIAL_VDELAY()));

    // Modify Corresponding IVS2DVS Delay
    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[0]);

#endif // End of #if((_3D_SUPPORT == _ON) || (_FRC_SUPPORT == _ON))
}

//--------------------------------------------------
// Description  : Modify H Capture
// Input Value  : IH Capture Shift
// Output Value : None
//--------------------------------------------------
void ScalerIDomainFineTuneHCaptureStart(WORD usDeltaIHCapture)
{       
    PDATA_WORD(0) = usDeltaIHCapture + ScalerVgipGetCaptureHStartPosition() - 2;
    ScalerSetBit(CM_14_IPH_ACT_STA_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((HIBYTE(PDATA_WORD(0)) & 0x0F)));
    ScalerSetByte(CM_15_IPH_ACT_STA_L, LOBYTE(PDATA_WORD(0)));     
    
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, (ScalerGetByte(CM_41_IV_DV_DELAY_CLK_ODD) + ((BYTE)(usDeltaIHCapture / 16))));
    ScalerSetByte(CM_42_IV_DV_DELAY_CLK_EVEN, (ScalerGetByte(CM_42_IV_DV_DELAY_CLK_EVEN) + ((BYTE)(usDeltaIHCapture / 16))));         
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Find metastable phase for current APLL rate
// Input Value  : None
// Output Value : current HS delay value (0.01ns * 64)
//--------------------------------------------------
WORD ScalerIDomainSearchHsEdge(void)
{ 
    BYTE ucCurrPhase = 0;
    BYTE ucTargetPhase = 0xFF;
    DWORD ulMax = 0;

    // Stop auto-function; HW auto; Measure min; Accumulation
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT6 | _BIT4 | _BIT0), (_BIT6 | _BIT4));

    // Set VGIP latch edge
    SET_HS_DELAY_LATCH_EDGE();

    if(ScalerGetBit(CM_10_VGIP_CTRL, _BIT4) == _BIT4)
    {
        ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5);
    }

    // Enable I-domain pattern gen to output 0;
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_10_IPG_CTRL0, 0x07);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_11_IPG_CTRL1, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_12_IPG_RED_INIT, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_13_IPG_GREEN_INIT, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_14_IPG_BLUE_INIT, 0x00);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_15_IPG_RGB_INIT, 0x00);

    // Set auto-balance old mode
    ScalerSetByte(CM_76_RED_NOISE_MARGIN, 0x40);

    if(ScalerGetBit(P1_B1_PLLDIV_H, _BIT4) == _BIT4)
    {
        // Set phase step = 32, step size = 2
        ScalerSetByte(CM_7B_HW_AUTO_PHASE_CTRL0, 0xF9);
    }
    else
    {
        // Set phase step = 32, step size = 1
        ScalerSetByte(CM_7B_HW_AUTO_PHASE_CTRL0, 0xF8);
    }

    // Set auto function boundary to max
    ScalerMeasureAutoFuncHBoundInitial((ScalerGetWord(P1_B1_PLLDIV_H) & 0x0FFF), 0x0FFF);
    ScalerMeasureAutoFuncVBoundInitial(0x0000, 0x0FFF);

    // for each phase
    for(ucCurrPhase = 0; ucCurrPhase < 64; ++ucCurrPhase)
    {
        if((ucCurrPhase == 0) || (ucCurrPhase == 32))
        {
            // Stop auto-function
            ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, 0x00);

            if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
            {
                break;
            }

            // Set initial phase
            if(ScalerGetBit(P1_B1_PLLDIV_H, _BIT4) == _BIT4)
            {
                ScalerSetByte(CM_7C_HW_AUTO_PHASE_CTRL1, (ucCurrPhase << 1));
            }
            else
            {
                ScalerSetByte(CM_7C_HW_AUTO_PHASE_CTRL1, ucCurrPhase);
            }

            // Start auto-function
            ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~_BIT0, _BIT0);

            if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
            {
                break;
            }
        }

        if(ScalerTimerWaitForEvent(_EVENT_IVS) == _FALSE)
        {
            break;
        }

        // Pop out result
        PDATA_DWORD(0) = (*((volatile DWORD xdata *)(CM_84_AUTO_PHASE_3)));

        if(PDATA_DWORD(0) > ulMax)
        {
            ulMax = PDATA_DWORD(0);
            ucTargetPhase = ucCurrPhase;
        }
    }

    // Stop auto-function; Disable HW auto
    ScalerSetBit(CM_7D_AUTO_ADJ_CTRL1, ~(_BIT6 | _BIT0), 0x00);

    ucTargetPhase = (ucTargetPhase + _PHASE_DELAY_HALF_PERIOD_SHIFT) % 64;

    // Calculate HS delay (unit: 1/64 ns)
    if(ulMax == 0x00)
    {
        return ~0;
    }
    else
    {
        return (WORD)((DWORD)10000 * ucTargetPhase / GET_INPUT_PIXEL_CLK());
    }
}

//--------------------------------------------------
// Description  : HS delay Calibration
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerIDomainModifyHsLatchEdgeDelay(void)
{
    BYTE ucBackup[7];
    BYTE ucLoop = 0;

    if(g_usPhaseDelayTime != 0x00)
    {
        // HS delay already calibrated
        DebugMessageAnalog("HS Delay Value", g_usPhaseDelayTime);
        return;
    }

    /////////////////////////////////////////////////////////////////////////
    //1. Initial Display format/APLL/VGIP
    /////////////////////////////////////////////////////////////////////////

    // Backup Display format gen setting
    SAVE_HS_DELAY_SETTING(ucBackup);

    // Disable DPLL spread spectrum if enabled
    ScalerPllSetDpllSsc(_DCLK_SPREAD_SPEED, _OFF);

    // Set new DVtotal; Update last line = DHtotal
    ScalerSetByte(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, (HIBYTE((WORD)_HS_DELAY_DHTOTAL - 4) << 4) | (HIBYTE((WORD)_HS_DELAY_DVTOTAL) & 0x0F));
    ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, LOBYTE((WORD)_HS_DELAY_DVTOTAL));
    ScalerSetByte(P1_C9_EVEN_FIX_LASTLINE_LENGTH_L, LOBYTE((WORD)_HS_DELAY_DHTOTAL - 4));

    // Set new DHtotal
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_00_DISP_DH_TOTAL_H, HIBYTE((WORD)_HS_DELAY_DHTOTAL - 4));
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L, LOBYTE((WORD)_HS_DELAY_DHTOTAL - 4));
    ScalerSetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_02_DISP_DHS_END, 0x08);

    // ADC Clock Power On, SOG_ADC0 Power On, R/G/B ADC Power On
    ScalerSetBit(P0_C6_ADC_POWER, ~(_BIT6 | _BIT5 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | _BIT2 | _BIT1 | _BIT0));

    // Reset ADC clock delay
    ScalerSetBit(P0_D0_ADC_CTL_GRN, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

    // Adc output clock setting
    ScalerADCOutputClkSetting();

    // Switch sync-processor HS/VS source from D-domain; Bypass HS output
    ScalerSetBit(CM_0B_POWER_CTRL2, ~_BIT1, _BIT1);
    ScalerSetByte(CM_47_SYNC_SELECT, _BIT2);
    ScalerSetByte(CM_48_SYNC_INVERT, _BIT4);
    ScalerSetByte(CM_49_SYNC_CTRL, (_BIT2 | _BIT1));

    // Enable I-domain pattern gen; Disable double buffer; Enable ADC input;
    ScalerSetByte(CM_10_VGIP_CTRL, (_BIT7 | _BIT0));

    // Load default value
    g_usPhaseDelayTime = _PHASE_DELAY_TIME_VALUE;

    /////////////////////////////////////////////////////////////////////////
    //2. Detect HS/clock meta-stability
    /////////////////////////////////////////////////////////////////////////

    // Set APLL clock to target freq. by calculating IHtotal
    if(ScalerAPLLAdjust(_HS_DELAY_IHTOTAL, _HS_DELAY_REAL_DHFREQ) == _TRUE)
    {
        // Detect HS meta-stable
        while((ucLoop++) <= 5)
        {
            if((PDATA_WORD(0) = ScalerIDomainSearchHsEdge()) != ~0)
            {
                g_usPhaseDelayTime = PDATA_WORD(0);
                
                // Calculate current pixel clock period
                PDATA_WORD(0) = (WORD)((DWORD)640000 / GET_INPUT_PIXEL_CLK()); // 1T

                // Check whether HS delay over 1T
                if(abs(PDATA_WORD(0) + g_usPhaseDelayTime - _PHASE_DELAY_TIME_VALUE) < abs(g_usPhaseDelayTime - _PHASE_DELAY_TIME_VALUE))
                {
                    g_usPhaseDelayTime += PDATA_WORD(0);
                }
                break;
            }

            // Adjust ADC clock delay
            ScalerSetBit(P0_D0_ADC_CTL_GRN, ~(_BIT2 | _BIT1 | _BIT0), (ucLoop & 0x07));
        }
    }

    /////////////////////////////////////////////////////////////////////////
    //3. Restore default setting
    /////////////////////////////////////////////////////////////////////////

    // Disable VGIP
    ScalerSetByte(CM_10_VGIP_CTRL, 0x00);

    // Set sync processsor HS/VS source from ADC
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT2, 0x00);
    ScalerSetBit(CM_0B_POWER_CTRL2, ~_BIT1, 0x00);

    // Power down ADC VCM/ADC clock/SOG Power/RGB Channel
    ScalerSetBit(P0_C6_ADC_POWER, ~(_BIT6 | _BIT5 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Reset ADC clock delay
    ScalerSetBit(P0_D0_ADC_CTL_GRN, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

    // Power down APLL
    ScalerSetBit(P1_AF_PLL_WD, ~_BIT0, _BIT0);

    // Load DPLL setting
    LOAD_HS_DELAY_SETTING(ucBackup);

    DebugMessageAnalog("HS Delay Calibrated", g_usPhaseDelayTime);
}
#endif
