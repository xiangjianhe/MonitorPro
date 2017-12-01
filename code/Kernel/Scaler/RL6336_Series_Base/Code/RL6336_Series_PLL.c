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
// ID Code      : RL6336_Series_PLL.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6336_SERIES_PLL__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//----------------------------------------------------------------------------
// APLL Parameters
//----------------------------------------------------------------------------
#define _APLL_M_CODE                                25
#define _APLL_N_CODE                                2

#define _APLL_SUM_I_READ_COUNT                      3

//--------------------------------------------------
// Definations of APLL _G_VALUE_DIVIDER
//--------------------------------------------------
#define _G_VALUE_DIVIDER_0                          4
#define _G_VALUE_DIVIDER_1                          16
#define _G_VALUE_DIVIDER_2                          64
#define _G_VALUE_DIVIDER_3                          128
#define _G_VALUE_DIVIDER_4                          256
#define _G_VALUE_DIVIDER_5                          512

//--------------------------------------------------
// Definations of V Sync Pulse Width Compensate, APLL Stable Count
//--------------------------------------------------
#define _APLL_VS_WIDTH_COMPENSATE                   1
#define _ADJUST_APLL_STABLE_COUNT                   2

//--------------------------------------------------
// Definations of DPLL setting state
//--------------------------------------------------
#define _DPLL_SET_POWER_OFF                         0
#define _DPLL_SET_RC_IPI                            1
#define _DPLL_SET_FREQ                              2
#define _DPLL_SET_POWER_ON                          3

#define _DPLL_REG_POST_DIV_1                        0
#define _DPLL_REG_POST_DIV_2                        1

#define _DIV_M                                      _DIV_1  // DIV_M <= 17

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
typedef struct
{
    WORD usPEValue;
    WORD usPreHTotal;
    DWORD ulDivider;
} StructAdjustApllData;
#endif

//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
StructAdjustApllData g_stApllData = {0};
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerM2PLLDiv(BYTE ucDiv);
void ScalerPllSetDpllReset(void);
void ScalerPllSetNFCode(BYTE ucNCode, DWORD ulFCode);
BYTE ScalerPllGetNCode(void);
DWORD ScalerPllGetFCode(void);
void ScalerPllSetDpllSsc(bit bDclkSpreadSpeed, BYTE ucSpreadRange);
void ScalerPllSetDpllFreq(DWORD ulFreq);
void ScalerDPLLFineTuneFrameSync(void);

#if(_VGA_SUPPORT == _ON)
bit ScalerAPLLAdjust(WORD usCurrHTotal, WORD usCurrHFreq);
BYTE ScalerAPLLGetAPLLGValue(WORD *pDelta);
bit ScalerAPLLFastLockAdjust(WORD usCurrHTotal);
WORD ScalerAPLLGetIHTotal(void);
void ScalerPLLSetPhase(BYTE ucPhase, WORD usVfreq);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : System Clock Select From M2PLL Divider Control.
// Input Value  : ucDiv    --> Divider.
// Output Value : None
//--------------------------------------------------
void ScalerM2PLLDiv(BYTE ucDiv)
{
    // Internal Xtal Freq. From M2PLL divider
    ScalerSetBit(CM_22_FIFO_FREQUENCY, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), ucDiv << 3);
}

//--------------------------------------------------
// Description  : Set DPLL Freq
// Input Value  : Target Freq
// Description  : Adjust DPLL Spread Spectrum
// Input Value  : Spread Spectrum Range
// Output Value : None
//--------------------------------------------------
void ScalerPllSetDpllReset(void)
{
    // Power Down PLL
    ScalerSetBit(P1_D1_LVDSPLL_1, ~_BIT0, 0x00);

    // Disable SSCG
    ScalerSetBit(P1_CA_SSCG_0, ~_BIT7, 0x00);

    // Reset PLL N.F Code
    ScalerPllSetNFCode(0, 0);

    // Set Div_Post = 1
    ScalerSetBit(P1_D0_LVDSPLL_0, ~(_BIT6 | _BIT5), (_DPLL_REG_POST_DIV_1 << 5));

    // Set Div_M
    ScalerSetBit(P1_D0_LVDSPLL_0, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ((_DIV_M >= 2) ? (_DIV_M - 2) : (_BIT4)));

    // Set Div_Multi, double_port: 3.5x, single_port: 7x
    ScalerSetBit(P1_D1_LVDSPLL_1, ~(_BIT7 | _BIT6 | _BIT5), ((_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT) ? (_BIT5) : (_BIT5 | _BIT6)));

    // Set bouble buffer, Set DPLL Reference Clk to XTAL
    ScalerSetBit(P1_C0_DPLL_NF_0, ~(_BIT7 | _BIT4), _BIT7);

    // Set Test Mode DCLK Divider = 1
    ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, _CM_8E_PT_06_PS_SELECT_TSTINCLOCK, ~_BIT1, _BIT1);
}

//--------------------------------------------------
// Description  : Adjust DPLL Offset
// Input Value  : ucNCode: N - 2, 8-bit
//                ulFCode: F, 20-bit
// Output Value : None
//--------------------------------------------------
void ScalerPllSetNFCode(BYTE ucNCode, DWORD ulFCode)
{
    if(ucNCode < 10)
    {
        ucNCode = 10;
    }

    ScalerSetBit(P1_C0_DPLL_NF_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ucNCode & 0xF0) >> 4));
    ScalerSetByte(P1_C1_DPLL_NF_1, ((ucNCode & 0x0F) << 4) | ((ulFCode & 0xF0000) >> 16));
    ScalerSetByte(P1_C2_DPLL_NF_2, ((ulFCode & 0x0FF00) >> 8));
    ScalerSetByte(P1_C3_DPLL_NF_3, ((ulFCode & 0x000FF) >> 0));

    // Set double buffer
    ScalerSetBit(P1_C0_DPLL_NF_0, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | ((ucNCode & 0xF0) >> 4)));
}

//--------------------------------------------------
// Description  : Get DPLL N Code
// Input Value  : None
// Output Value : N code
//--------------------------------------------------
BYTE ScalerPllGetNCode(void)
{
    return (((ScalerGetByte(P1_C0_DPLL_NF_0) & 0x0F) << 4) | ((ScalerGetByte(P1_C1_DPLL_NF_1) & 0xF0) >> 4));
}

//--------------------------------------------------
// Description  : Get DPLL F Code
// Input Value  : None
// Output Value : F code
//--------------------------------------------------
DWORD ScalerPllGetFCode(void)
{
    return ((((DWORD)ScalerGetByte(P1_C1_DPLL_NF_1) & 0x0F) << 16) | (((DWORD)ScalerGetByte(P1_C2_DPLL_NF_2)) << 8) | (ScalerGetByte(P1_C3_DPLL_NF_3)));
}

//--------------------------------------------------
// Description  : Adjust DPLL Spread Spectrum
// Input Value  : Spread Spectrum Range
// Output Value : None
//--------------------------------------------------
void ScalerPllSetDpllSsc(bit bDclkSpreadSpeed, BYTE ucSpreadRange)
{
    // Disable SSCG, Disable SSCG_TBASE_CAL_EN
    ScalerSetBit(P1_CA_SSCG_0, ~(_BIT7 | _BIT2), 0x00);

    // Wait SSCG disalbe, SSCG disable at triangle center
    ScalerTimerPollingFlagProc(2, P1_CA_SSCG_0, _BIT7, 0x00);

    if(ucSpreadRange != _OFF)
    {
        // Set SSCG speed
        BYTE ucDclkSpreadSpeed = (bDclkSpreadSpeed == _SPEED_33K) ? 33 : 66;

        // calculate TBase with constant Fref
        PDATA_WORD(0) = (ScalerGetBit(P1_D0_LVDSPLL_0, _BIT4) == _BIT4) ? _EXT_XTAL : (_EXT_XTAL / ((ScalerGetByte(P1_D0_LVDSPLL_0) & 0x0F) + 2));

        PDATA_WORD(0) = PDATA_WORD(0) / ucDclkSpreadSpeed;

        // TBase must be a multiple of 4
        PDATA_WORD(0) = ((PDATA_WORD(0) + 2) >> 2) << 2;

        // Get current PLL N.F
        PDATA_DWORD(1) = ((((DWORD)ScalerPllGetNCode() + 2) << 20) | ScalerPllGetFCode());

        ///////////////////////////////////////////////////////////////////////////
        //
        // Calculate SSCG range step
        //
        // N.F * range = step * (TBASE / 2)
        // Step = SSCG_step * SSCG_weight, SSCG_step unit: 2^8, SSCG_weight min:1/8
        // Setp calculate use min unit: 2^8 / 8 = 2^5
        // range: 5 * ucSpreadRange / 1000.   ucSpreadRange = 15 --> range = 7.5%
        //
        ///////////////////////////////////////////////////////////////////////////

        PDATA_WORD(1) = (((PDATA_DWORD(1) >> 5) * 5 * ucSpreadRange * 2) / 1000 + (PDATA_WORD(0) / 2)) / PDATA_WORD(0);

        if((PDATA_WORD(1) / 255) <= 0)
        {
            pData[15] = 0;
        }
        else if((PDATA_WORD(1) / 255) < 2)
        {
            pData[15] = 1;
        }
        else if((PDATA_WORD(1) / 255) < 4)
        {
            pData[15] = 2;
        }
        else if((PDATA_WORD(1) / 255) < 8)
        {
            pData[15] = 3;
        }
        else if((PDATA_WORD(1) / 255) < 16)
        {
            pData[15] = 4;
        }
        else if((PDATA_WORD(1) / 255) < 32)
        {
            pData[15] = 5;
        }
        else
        {
            pData[15] = 6;
        }

        ScalerSetByte(P1_CB_SSCG_1, (PDATA_WORD(1) >> pData[15]));
        ScalerSetByte(P1_CC_SSCG_2, ((pData[15] & 0x07) << 5) | (HIBYTE(PDATA_WORD(0)) & 0x0F));
        ScalerSetByte(P1_CD_SSCG_3, LOBYTE(PDATA_WORD(0)));

        // Enable SSCG
        ScalerSetBit(P1_CA_SSCG_0, ~_BIT7, _BIT7);
    }
}

//--------------------------------------------------
// Description  : Set DPLL Freq
// Input Value  : Target Freq
// Output Value : None
//--------------------------------------------------
void ScalerPllSetDpllFreq(DWORD ulFreq)
{
    bit bLVDSPower = 0;
    BYTE ucNCode = 0;
    BYTE ucPostDivReg = 0;
    DWORD ulFCode = 0;
    BYTE ucDPLLSettingState = _DPLL_SET_POWER_OFF;

    ///////////////////////////////////////////////////////////////
    //
    // LVDS_PLL_Freq = (N.F) / Div_M * Fref / Div_Post
    // DPLL_Freq = LVDS_PLL_Freq / Div_Multi
    // Div_multi setting depend on _DISP_OUTPUT_PORT
    //
    // N.F = LVDS_PLL_Freq * Div_M / Fref * Div_Post
    //     = (DPLL_Freq * Div_Multi) * Div_M / Fref * Div_Post
    ///////////////////////////////////////////////////////////////

    // Calculate LVDS PLL frequency
    PDATA_DWORD(0) = (ulFreq * 7 / (1 << _DISP_OUTPUT_PORT));

    ucPostDivReg = ((PDATA_DWORD(0) <= 350000) ? _DPLL_REG_POST_DIV_2 : _DPLL_REG_POST_DIV_1);

    ucNCode = PDATA_DWORD(0) * _DIV_M * (1 << ucPostDivReg) / _EXT_XTAL;
    ulFCode = (((PDATA_DWORD(0) - ((DWORD)ucNCode / _DIV_M * _EXT_XTAL / (1 << ucPostDivReg))) << 18) * _DIV_M * (1 << ucPostDivReg) / _EXT_XTAL) << 2;

    bLVDSPower = ScalerGetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, _BIT6);

    // LVDS PLL Freq before
    PDATA_DWORD(1) = (DWORD)(ScalerPllGetNCode() + 2) / _DIV_M * _EXT_XTAL / (1 << ((ScalerGetBit(P1_D0_LVDSPLL_0, (_BIT6 | _BIT5))) >> 5)) +
                    (((ScalerPllGetFCode() >> 2) / _DIV_M * _EXT_XTAL / (1 << ((ScalerGetBit(P1_D0_LVDSPLL_0, (_BIT6 | _BIT5))) >> 5))) >> 18);

    // Overscan case, Freq change under 10 percent
    if((bLVDSPower == _ON) && (ABSDWORD(PDATA_DWORD(0), PDATA_DWORD(1)) <= (PDATA_DWORD(1) / 10)))
    {
        ucDPLLSettingState = _DPLL_SET_FREQ;
    }
    else
    {
        ucDPLLSettingState = _DPLL_SET_POWER_OFF;

        pData[15] = (BYTE)(((PDATA_DWORD(0) / 515 * 10) + 625) / 1250);
        pData[15] -= (pData[15] >= 1) ? 1 : 0;
    }

    switch(ucDPLLSettingState)
    {
        case _DPLL_SET_POWER_OFF:

            // Wait DEN STOP
            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

            // Power Down LVDS
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~_BIT6, 0x00);

            // Power Down PLL
            ScalerSetBit(P1_D1_LVDSPLL_1, ~_BIT0, 0x00);

        case _DPLL_SET_RC_IPI:

            ScalerSetBit(P1_D3_LVDSPLL_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), ((pData[15] & 0x1F) << 3));

        case _DPLL_SET_FREQ:

            // Set N.F code
            pData[0] = ucNCode - ((ucNCode >= 2) ? 2 : 0);
            ScalerPllSetNFCode(pData[0], ulFCode);

            // Set Post_div
            ScalerSetBit(P1_D0_LVDSPLL_0, ~(_BIT6 | _BIT5), (ucPostDivReg << 5));

        case _DPLL_SET_POWER_ON:

            // Power Up PLL
            ScalerSetBit(P1_D1_LVDSPLL_1, ~_BIT0, _BIT0);

            break;

        default:

            break;
    }

    // Apply DPLL double-buffer
    ScalerSetBit(P1_C0_DPLL_NF_0, ~_BIT7, _BIT7);

    pData[0] = ucNCode - ((ucNCode >= 2) ? 2 : 0);

    if((pData[0] != ScalerPllGetNCode()) || (ulFCode != ScalerPllGetFCode()))
    {
        // Apply N.F. Code Manually
        ScalerSetBit(P1_C4_SDM_0, ~_BIT5, _BIT5);
        ScalerPllSetNFCode(pData[0], ulFCode);
        ScalerSetBit(P1_C4_SDM_0, ~_BIT5, 0x00);
    }

    // Set LVDS power
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~_BIT6, ((BYTE)bLVDSPower << 6));
}

//--------------------------------------------------
// Description  : Set FrameSync offset to match I/D active time & last-line target
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDPLLFineTuneFrameSync(void)
{
    WORD usDVtotal = 0;
    WORD usLastLine = 0;

    DWORD ulN_FCodeOri = 0;
    DWORD ulN_FCodeNew = 0;

    // Temporary Enable Frame Sync Fine Tune for Interlace Mode in order to Get Equal Frame Period
    if(GET_INTERLACED_MODE() == _TRUE)
    {
        if(ScalerGetBit(CM_32_SCALE_CTRL, _BIT6) == _BIT6)
        {
            // Video Compensation on Even Field; Enable Last Line Measure on Odd Field
            ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~(_BIT7 | _BIT6), _BIT7);
        }
        else
        {
            // Video Compensation on Odd Field; Enable Last Line Measure on Even Field
            ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
        }
    }
    else
    {
        // Disable Last Line Measure by Field
        ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~(_BIT7 | _BIT6), 0x00);
    }

    // Switch active region count to "input active region"
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT1, 0x00);
    ScalerSetBit(CM_5A_SYNC_TEST_MISC, ~(_BIT5 | _BIT4), 0x00);
    ScalerSetBit(CM_50_STABLE_PERIOD_H, ~_BIT4, _BIT4);

    // Wait for input active region measure
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);

    // Pop up Input Active region Results
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT6, _BIT6);

    // Switch active region count to "display active region"
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT1, _BIT1);

    //=====================================
    // Wait for display active region measure
    //=====================================
    ScalerTimerWaitForEvent(_EVENT_DVS);

    // Get Input Active Measure Clk Count
    ScalerSetByte(CM_59_MEAS_ACTIVE_REGION_H, 0x00);
    ((BYTE *)(&g_ulActiveRegionBackUp))[0] = 0;
    ((BYTE *)(&g_ulActiveRegionBackUp))[1] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
    ((BYTE *)(&g_ulActiveRegionBackUp))[2] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
    ((BYTE *)(&g_ulActiveRegionBackUp))[3] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);

    ScalerTimerWaitForEvent(_EVENT_DVS);
    //=====================================

    // Pop up Display Active region Results
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT6, _BIT6);

    // Get Display Active Measure Clk Count
    ScalerSetByte(CM_59_MEAS_ACTIVE_REGION_H, 0x00);
    pData[12] = 0;
    pData[13] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
    pData[14] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
    pData[15] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);

    // Pop out last line
    ScalerSetBit(CM_44_LAST_LINE_H, ~_BIT7, _BIT7);
    usDVtotal = (((WORD)ScalerGetBit(CM_44_LAST_LINE_H, 0x0F) << 8) | ScalerGetByte(CM_45_LAST_LINE_L));

    ScalerSetBit(CM_44_LAST_LINE_H, ~_BIT7, 0x00);
    usLastLine = (((WORD)ScalerGetBit(CM_44_LAST_LINE_H, 0x0F) << 8) | ScalerGetByte(CM_45_LAST_LINE_L));

#if(_2D_TO_3D_FUNCTION == _OFF)
    if(GET_INTERLACED_MODE() == _TRUE)
    {
        // Disable Last Line Measure by Field
        ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~(_BIT7 | _BIT6), 0x00);
    }
#endif

    // Get current PLL N.F
    ulN_FCodeOri = ((((DWORD)ScalerPllGetNCode() + 2) << 20) | ScalerPllGetFCode());

    DebugMessageFS("Original N.F code", ulN_FCodeOri);

    //////////////////////////////////////////////////////////////////////////////////////////////
    //
    // a. D_Total / Dclk = disp_act_region / Xtal
    // b. Dclk * disp_act_region = constant = (N.F) * dis_act_region
    // c. Set target disp_act_region' = input_act_region
    // d. (N.F + N.F_bias) * input_act_region = (N.F) * dis_act_region
    // e. LVDS clk = 735M, N.F max 26bit.
    //
    // N.F bias * 2^6 = (N.F) * 2^6 / input_act_region * abs(disp_act_region - input_act_region)
    //
    //////////////////////////////////////////////////////////////////////////////////////////////

    PDATA_DWORD(0) = ((ulN_FCodeOri << 6) / g_ulActiveRegionBackUp * labs(PDATA_DWORD(3) - g_ulActiveRegionBackUp)) +
                     ((ulN_FCodeOri << 6) % g_ulActiveRegionBackUp * labs(PDATA_DWORD(3) - g_ulActiveRegionBackUp) / g_ulActiveRegionBackUp);

    PDATA_DWORD(0) = (PDATA_DWORD(0) + (1 << 5)) >> 6;
    DebugMessageFS("delta N.F_bias", (PDATA_DWORD(0)));

    // Calcuate new N.F
    if(PDATA_DWORD(3) > g_ulActiveRegionBackUp)
    {
        // N.F + N.F_bias
        ulN_FCodeNew = ulN_FCodeOri + PDATA_DWORD(0);
    }
    else
    {
        // N.F - N.F_bias
        ulN_FCodeNew = ulN_FCodeOri - PDATA_DWORD(0);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Fine Tune Last Line to Panel Target
    //
    // 1.Dtotal_ori = DHtotal * DV count + Last-line
    //
    // 2.Dtotal_ori / N.F_ori = Dtotal_1 / N.F_new
    //   Dtotal_1 = (N.F_new / N.F_ori) * Dtotal_ori
    //            = (disp_act_region / input_act_region) * Dtotal_ori
    //            = Dtotal_ori +- (abs(disp_act_region - input_act_region) / input_act_region) * Dtotal_ori
    //
    // 3.estimated last line = Dtotal' % DHtotal
    //
    // 4.According Panel target, calculate Dtotal_2
    //
    // 5.Dtotal_1 / N.F_new = Dtotal_2 / (N.F_new + N.F')
    //   N.F' = N.F_new * (Dtotal_2 - Dtotal_1) / Dtotal_1
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Calculate Dtotal_ori
    PDATA_DWORD(0) = (DWORD)usDVtotal * g_stMDomainOutputData.usHTotal + usLastLine;

    DebugMessageFS("Dtotal origin", PDATA_DWORD(0));

    if(ulN_FCodeNew >= ulN_FCodeOri)
    {
        // Calculate Dtotal_1
        PDATA_DWORD(3) = PDATA_DWORD(0) + PDATA_DWORD(0) * (labs(PDATA_DWORD(3) - g_ulActiveRegionBackUp)) / g_ulActiveRegionBackUp;
    }
    else
    {
        // Calculate Dtotal_1
        PDATA_DWORD(3) = PDATA_DWORD(0) - PDATA_DWORD(0) * (labs(PDATA_DWORD(3) - g_ulActiveRegionBackUp)) / g_ulActiveRegionBackUp;
    }

    DebugMessageFS("Dtotal_1", PDATA_DWORD(3));

    // Calculate new last-line
    usLastLine = PDATA_DWORD(3) % g_stMDomainOutputData.usHTotal;

    DebugMessageFS("Estimated last-line", usLastLine);

    // Calculate modified Dtotal_2 for fixed-last line
    PDATA_DWORD(2) = PDATA_DWORD(3) - usLastLine + _LAST_LINE_TARGET;

    DebugMessageFS("Dtotal_2", PDATA_DWORD(2));

    if(abs(usLastLine - _LAST_LINE_TARGET) > (g_stMDomainOutputData.usHTotal >> 1))
    {
        if(usLastLine > _LAST_LINE_TARGET)
        {
            PDATA_DWORD(2) += (DWORD)g_stMDomainOutputData.usHTotal;  // +
        }
        else
        {
            PDATA_DWORD(2) -= (DWORD)g_stMDomainOutputData.usHTotal;  // -
        }
    }

    // Calculate N.F bias
    PDATA_DWORD(0) = (ulN_FCodeNew / PDATA_DWORD(3) * labs(PDATA_DWORD(2) - PDATA_DWORD(3)))+
                     (ulN_FCodeNew % PDATA_DWORD(3) * labs(PDATA_DWORD(2) - PDATA_DWORD(3)) / PDATA_DWORD(3));

    // if Dtotal_2 > Dtotal_1 --> Dclk++
    if(PDATA_DWORD(2) > PDATA_DWORD(3))
    {
        ulN_FCodeNew += PDATA_DWORD(0);
    }
    else
    {
        ulN_FCodeNew -= PDATA_DWORD(0);
    }

    DebugMessageFS("New N.F_2", ulN_FCodeNew);

    // Apply new N.F for last-line
    pData[0] = ((ulN_FCodeNew & 0xff00000) >> 20) - ((((ulN_FCodeNew & 0xff00000) >> 20) >= 2) ? 2 : 0);
    ScalerPllSetNFCode(pData[0], (ulN_FCodeNew & 0xfffff));

    if(ulN_FCodeNew >= ulN_FCodeOri)
    {
        PDATA_DWORD(1) = GET_D_CLK_FREQ() + GET_D_CLK_FREQ() * (labs(ulN_FCodeNew - ulN_FCodeOri) >> 5) / ((ulN_FCodeOri) >> 5);
    }
    else
    {
        PDATA_DWORD(1) = GET_D_CLK_FREQ() - GET_D_CLK_FREQ() * (labs(ulN_FCodeNew - ulN_FCodeOri) >> 5) / ((ulN_FCodeOri) >> 5);
    }

    DebugMessageFS("New Dclk_2", PDATA_DWORD(1));

    // Calculate Modified DClk by offset
    SET_D_CLK_FREQ(PDATA_DWORD(1));

    // Modify Dt by new Dtotal & old Dtotal
    ScalerMemoryCompensateDtForLastLine(PDATA_DWORD(2), PDATA_DWORD(3));

    // Switch to "input active region"
    ScalerMeasureSetRegionCount(_MEASURE_TARGET_INPUT, _ACTIVE_REGION_TYPE);
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : ADC Clock adjust.
// Input Value  : usCurrHTotal    --> IHTotal.
// Output Value : Return _TRUE if adjust successful.
//--------------------------------------------------
bit ScalerAPLLAdjust(WORD usCurrHTotal, WORD usCurrHFreq)
{
    BYTE ucData[5] = {0};
    BYTE ucMcode = 0;
    SBYTE chKcode = 0;
    SBYTE chKValue = 0;
    WORD usIcode = 0;
    WORD usPcode = 0;
    DWORD ulOldPllDivider = 0;
    SDWORD shSumI = 0;
    SDWORD shTemp = 0;

    DebugMessageAnalog("APLL Clock", usCurrHTotal);

    // Disable new mode
    ScalerSetByte(P1_BB_DDS_MIX_4, 0x1b);

    // Disable Fast PLL Mechanism
    ScalerSetByte(P1_AA_FAST_PLL_CTRL, 0x00);

    // Power down APLL
    ScalerSetBit(P1_AF_PLL_WD, ~_BIT0, _BIT0);

    // APLL Inital Setting
    ScalerSetByte(P1_A0_PLL_DIV_CTRL, 0x08);

    // Adjust current resitor
    ScalerSetByte(P1_AE_PLL_CRNT, 0x63);

    // Set DDS Mix
    ScalerSetByte(P1_B8_DDS_MIX_1, 0x0E);
    ScalerSetByte(P1_B9_DDS_MIX_2, 0xFF);
    ScalerSetByte(P1_BA_DDS_MIX_3, 0xFF);

    // Set the divide number
    ScalerSetBit(P1_B1_PLLDIV_H, 0xf0, (BYTE)(((usCurrHTotal - 1) >> 8) & 0x0f));
    ScalerSetByte(P1_B2_PLLDIV_L, (BYTE)((usCurrHTotal - 1) & 0x00ff));

    // Get VCO Divider (ucData[0])
    ulOldPllDivider = (DWORD)usCurrHFreq * usCurrHTotal / 10; // ADC sampling clock, UNIT in KHz

    // Record Current Pixel Clock
    SET_INPUT_PIXEL_CLK(ulOldPllDivider / 100); // Unit: 0.1M Hz

    ucData[0] = ulOldPllDivider < _APLL_VCO_DEVIDER_4_2_THERSHOLD ? 4 : 2; // Vco_divider
    ScalerSetBit(P1_B1_PLLDIV_H, ~(_BIT6 | _BIT5 | _BIT4), (ucData[0] == 2) ? (_BIT6 | _BIT5) : (_BIT6 | _BIT5 | _BIT4));

    // Calculate (M + K/16) = IHF * usCurrHTotal * N1 * vco_divider / Fxtal
    ulOldPllDivider = ((ulOldPllDivider * _APLL_N_CODE * ucData[0]) << 10) / _EXT_XTAL;

    // Get M, K code, M + K/16 = pllclock / 1024
    ucMcode = ulOldPllDivider >> 10; // M code is the integer part.

    // K is the fraction part quantized by 16
    chKcode = ((DWORD)ulOldPllDivider - ((DWORD)ucMcode << 10)) >> 6;

    // Set K code within -8 to 7 due to 3 bits.
    if(chKcode > 7)
    {
        ucMcode += 1;
        chKcode -= 16;
    }
    else if(chKcode < -8)
    {
        ucMcode -= 1;
        chKcode += 16;
    }

    // Set N code
    ScalerSetBit(P1_AD_PLL_N, 0xf8, ((_APLL_N_CODE - 2) & 0x07));

    // Set M code
    ScalerSetByte(P1_AC_PLL_M, (ucMcode - 3));

    // Set K code
    ScalerSetBit(P1_AD_PLL_N, 0x0f, ((chKcode & 0x0f) << 4));

    // Enable PFD Calibration
    ScalerSetBit(P1_A4_PFD_CALIBRATED_RESULTS_H, ~_BIT7, 0x00);
    ScalerSetBit(P1_A4_PFD_CALIBRATED_RESULTS_H, ~_BIT7, _BIT7);

    // Get PFD Calibration result
    if(ScalerTimerPollingFlagProc(100, P1_A4_PFD_CALIBRATED_RESULTS_H, _BIT7, 0))
    {
        ScalerRead(P1_A4_PFD_CALIBRATED_RESULTS_H, 2, ucData, _AUTOINC);
        g_stApllData.usPEValue = ((WORD)(ucData[0] & 0x0F) << 8) | ucData[1];

        g_stApllData.usPEValue = (WORD)((DWORD)1000000 / ((DWORD)g_stApllData.usPEValue * _SYS_CLK_KHZ/ 1000)); // Unit : ps
    }
    else
    {
        ScalerSetBit(P1_A4_PFD_CALIBRATED_RESULTS_H, ~_BIT7, 0x00);

        return _FALSE;
    }

    ///////////////////////////////////////////////////////////////////////////////
    // Formula :                                                                 //
    //                                                                           //
    //  I_gain       Ths                    PE(UNIT)                   1         //
    // --------- x  ------- = ------------------------------------ x  -----      //
    //   2^22        Tbck        Txclk x 16N / (16M +- K) x 1/16       8         //
    //                                                                           //
    //  I_gain         Ths                      PE(UNIT)                   1     //
    // --------- x  ----------- = ------------------------------------ x  -----  //
    //   2^22       Tclk x N         Txclk x N / (M +- K/16) x 1/16        8     //
    //                                                                           //
    //                                                                           //
    //           2^22 x PE_U x (M +- K/16) x 2^4        1                        //
    // I_gain = ----------------------------------- x ------                     //
    //                        Ths                      2^3                       //
    //                                                                           //
    //           2^23 x PE_U x (M +- K/16)                                       //
    //       = -----------------------------                                     //
    //                      Ths                                                  //
    //                                                                           //
    //                                                                           //
    //       = IHF x 2^23 x PE_U x (M +- K/16)                                   //
    //                                                                           //
    //                                                                           //
    // I_gain = IHF x 2^23 x PE_U x (M +- K/16)                                  //
    // IHFreq/10 UNIT is KHz, so result has to multiply 10^2          //
    // (PE Value UNIT is ps, so result has to multiply 10^-12)                   //
    //                                                                           //
    // I_gain = 10^2 x 2^23 x 10^-12 x 2^-10 => 10^10 / 2^13 = 1220703           //
    //                                                                           //
    ///////////////////////////////////////////////////////////////////////////////

    // Calculate I code
    usIcode = (WORD)(((DWORD)usCurrHFreq * g_stApllData.usPEValue * (ulOldPllDivider >> 10)) / 1192);

    // Total gain = 3 / 8
    usIcode = (usIcode / 64) & 0x00007fff; // n = 64 x 8 = 512

    // The minimum value of I code is 1.
    if(usIcode < 1)
    {
        usIcode = 1;
    }

    // Set I code
    ScalerSetByte(P1_A1_I_CODE_M, (BYTE)(usIcode >> 8));
    ScalerSetByte(P1_A2_I_CODE_L, (BYTE)usIcode);

    // Calculate P code
    usPcode = (WORD)(((DWORD)191 * usIcode * _EXT_XTAL / ((_APLL_N_CODE * usCurrHFreq + 5) / 10)) >> 7); // Total Gain = 192/512

    // Get G value (ucData[0])
    ucData[0] = ScalerAPLLGetAPLLGValue(&usPcode);

    // Set G value
    ScalerSetByte(P1_B6_P_CODE_MAPPING_METHOD, (ucData[0] << 2));

    // Set P code
    ScalerSetByte(P1_A3_P_CODE, (BYTE)usPcode);

    // Power On APLL
    ScalerSetByte(P1_B4_PLLPHASE_CTRL1, 0x00);
    ScalerSetByte(P1_AA_FAST_PLL_CTRL, 0x00);

    // Power up APLL
    ScalerSetBit(P1_AF_PLL_WD, ~_BIT0, 0x00);

    // Check HS source
    if(ScalerGetBit(CM_47_SYNC_SELECT, _BIT2) == 0x00)
    {
        // Delay 100ms for APLL lock.
        ScalerTimerDelayXms(100);
    }
    else
    {
        BYTE ucPeLoopCnt = 10;

        // Start max phase error measure
        ScalerSetBit(P1_A8_PE_MAX_MEASURE_H, ~_BIT7, _BIT7);

        do
        {
            // Clear max phase error
            ScalerSetBit(P1_AA_FAST_PLL_CTRL, ~_BIT7, _BIT7);
            ScalerSetBit(P1_AA_FAST_PLL_CTRL, ~_BIT7, 0x00);

            ScalerTimerDelayXms(10);

        }while(((ucPeLoopCnt--) != 0x00) &&
               (ScalerGetByte(P1_A9_PE_MAX_MEASURE_L) > 0x20));

        // Stop max phase error measure
        ScalerSetBit(P1_A8_PE_MAX_MEASURE_H, ~_BIT7, 0x00);
    }

    // Check PLL lock already
    if(!ScalerTimerPollingFlagProc(100, P1_B8_DDS_MIX_1, _BIT0, 1))
    {
        return _FALSE;
    }

    // Get Sum_I (27 bits)
    for(ucData[4] = 0; ucData[4] < _APLL_SUM_I_READ_COUNT; ucData[4]++)
    {
        ScalerSetBit(P1_AA_FAST_PLL_CTRL, ~_BIT2, 0x00);

        ScalerSetByte(P1_AA_FAST_PLL_CTRL, 0x04);
        if(ScalerTimerPollingFlagProc(100, P1_AA_FAST_PLL_CTRL, _BIT2, 0)) // Check Measure Sum_I
        {
            ScalerSetByte(P1_AA_FAST_PLL_CTRL, 0x03);
            ScalerRead(P1_AB_FAST_PLL_SUM_I, 4, ucData, _NON_AUTOINC);

            ScalerSetBit(P1_AA_FAST_PLL_CTRL, ~_BIT1, 0x00); // Disable Port AB (Sum_I access port)

            shTemp = ((((DWORD)ucData[0] & 0x07) << 24) | ((DWORD)ucData[1] << 16) | ((DWORD)ucData[2] << 8) | ((DWORD)ucData[3]));

            // To check the signed bit (Bit_26) of SUM_I
            if(ucData[0] & _BIT2)
            {
                shTemp |= 0xF8000000;
            }

            shSumI += shTemp;
            shTemp = 0;
        }
        else
        {
            ScalerSetByte(P1_AA_FAST_PLL_CTRL, 0x00);
            return _FALSE;
        }
    }

    shSumI = shSumI / _APLL_SUM_I_READ_COUNT;

    // Get K Value (4 bits for bit25 ~ bit22) and Set Sum I
    if(shSumI < 0)
    {
        shSumI = 0 - shSumI;
        chKValue = 0 - (BYTE)((shSumI >> 22) & 0x000000FF);
        shSumI = 0x400000 - (shSumI & 0x003fffff); // 0x400000 = 2^22
        chKcode -= 1;
    }
    else
    {
        chKValue = (BYTE)((shSumI >> 22) & 0x000000FF);
    }

    // Compensate K Value
    chKcode = chKcode + chKValue;

    // Set K code >= 0
    if(chKcode < 0)
    {
        ucMcode -= 1;
        chKcode += 16;
    }

    // Get New PLL Divider
    g_stApllData.ulDivider = ((DWORD)ucMcode << (26 - 2)) + (((DWORD)chKcode & 0x0000000f) << (22 - 2)) + (((DWORD)shSumI & 0x003fffff) >> 2);

    // Save Old IH-Total
    g_stApllData.usPreHTotal = usCurrHTotal;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Get APLL G value
// Input Value  : The P code of APLL
// Output Value : G value
//--------------------------------------------------
BYTE ScalerAPLLGetAPLLGValue(WORD *pDelta)
{
    if(*pDelta == 0)
    {
        *pDelta = 0x01;
    }

    if(*pDelta > 255)
    {
        for(pData[0] = 9; pData[0] < 15; pData[0]++)
        {
            if((*pDelta >> pData[0]) == 0)
            {
                break;
            }
        }

        switch(pData[0] - 9)
        {
            case 0:
                *pDelta = (*pDelta + (_G_VALUE_DIVIDER_0 / 2)) / _G_VALUE_DIVIDER_0;
                break;

            case 1:
                *pDelta = (*pDelta + (_G_VALUE_DIVIDER_1 / 2)) / _G_VALUE_DIVIDER_1;
                break;

            case 2:
                *pDelta = (*pDelta + (_G_VALUE_DIVIDER_2 / 2)) / _G_VALUE_DIVIDER_2;
                break;

            case 3:
                *pDelta = (*pDelta + (_G_VALUE_DIVIDER_3 / 2)) / _G_VALUE_DIVIDER_3;
                break;

            case 4:
                *pDelta = (*pDelta + (_G_VALUE_DIVIDER_4 / 2)) / _G_VALUE_DIVIDER_4;
                break;

            case 5:
                *pDelta = (*pDelta + (_G_VALUE_DIVIDER_5 / 2)) / _G_VALUE_DIVIDER_5;
                break;

            default:
                break;
        }

        return (pData[0] - 7);
    }

    return 1;
}
//--------------------------------------------------
// Description  : ADC Clock Fast Lock adjust.
// Input Value  : usCurrHTotal    --> IHTotal.
// Output Value : Return _TRUE if adjust successful.
//--------------------------------------------------
bit ScalerAPLLFastLockAdjust(WORD usCurrHTotal)
{
    BYTE ucMcode = 0;
    SBYTE chKcode = 0;
    WORD usIcode = 0;
    WORD usPcode = 0;
    DWORD ulClockRatio = 0;

    // Enable Fast PLL Mechanism
    ScalerSetByte(P1_AA_FAST_PLL_CTRL, 0x22);

    // Calculate Clock Ratio = usCurrHTotal / Old IH-Total
    ulClockRatio = (((DWORD)0x01 << 30) / g_stApllData.usPreHTotal) * usCurrHTotal;

    // Calculate New PLL Divider = Old PLL Divider x (New Clock / Old IH-Total) = Old PLL Divider x Clock Ratio
    PDATA_DWORD(0) = ((g_stApllData.ulDivider & 0xffff0000) >> 16) * ((ulClockRatio & 0xffff0000) >> 16);
    PDATA_DWORD(1) = ((g_stApllData.ulDivider & 0xffff0000) >> 16) * ((ulClockRatio & 0x0000ffff) >> 0);
    PDATA_DWORD(1) += ((g_stApllData.ulDivider & 0x0000ffff) >> 0) * ((ulClockRatio & 0xffff0000) >> 16);
    PDATA_DWORD(2) = ((g_stApllData.ulDivider & 0x0000ffff) >> 0) * ((ulClockRatio & 0x0000ffff) >> 0);
    PDATA_DWORD(3) = (PDATA_DWORD(0) << (16 - 14)) + (PDATA_DWORD(1) >> 14) + (PDATA_DWORD(2) >> (16 + 14));

    // Get M code, K code
    ucMcode = pData[12];
    chKcode = ((pData[13] & 0xf0) >> 4) & 0x0f;

    if(chKcode > 7)
    {
        ucMcode += 1;
        chKcode -= 16;
    }

    // Set usCurrHTotal, M ocde, K code
    ScalerSetBit(P1_B1_PLLDIV_H, 0xf0, (BYTE)(((usCurrHTotal - 1) >> 8) & 0x000f));
    ScalerSetByte(P1_B2_PLLDIV_L, (BYTE)((usCurrHTotal - 1) & 0x00ff));
    ScalerSetByte(P1_AC_PLL_M, (ucMcode - 3));
    ScalerSetBit(P1_AD_PLL_N, 0x0f, ((chKcode & 0x0f) << 4));

    // Calculate Sum_I (22 bits)
    PDATA_DWORD(0) = (PDATA_DWORD(3) & 0x000FFFFF) << 2;

    // Set Sum_I (22 bits)
    ScalerSetBit(P1_AA_FAST_PLL_CTRL, ~_BIT1, _BIT1); // Enable Port AB (Sum_I access port)
    ScalerWrite(P1_AB_FAST_PLL_SUM_I, 4, pData, _NON_AUTOINC);

    ScalerSetBit(P1_AA_FAST_PLL_CTRL, ~_BIT1, 0x00); // Disable Port AB (Sum_I access port)

    // Read PFD Calibrated result
    ScalerSetBit(P1_A4_PFD_CALIBRATED_RESULTS_H, ~_BIT7, _BIT7); // Enable PFD Calibration
    if(ScalerTimerPollingFlagProc(100, P1_A4_PFD_CALIBRATED_RESULTS_H, _BIT7, 0))
    {
        ScalerRead(P1_A4_PFD_CALIBRATED_RESULTS_H, 2, pData, _AUTOINC);
        g_stApllData.usPEValue = ((WORD)(pData[0] & 0x0F) << 8) | pData[1];
        g_stApllData.usPEValue = (WORD)((DWORD)1000000 / ((DWORD)g_stApllData.usPEValue * _SYS_CLK_KHZ / 1000)); // Unit : ps
    }
    else
    {
        ScalerSetBit(P1_A4_PFD_CALIBRATED_RESULTS_H, ~_BIT7, 0x00);
        return _FALSE;
    }

    // Calculate I code
    usIcode = (WORD)(((((DWORD)GET_INPUT_TIMING_HFREQ() + 5) / 10) * g_stApllData.usPEValue * (PDATA_DWORD(3) / 100000)) / 20000);
    usIcode = (usIcode / 64) & 0x00007fff; // n = 64 x 8 = 512

    // The minimum value of I code is 1.
    if(usIcode < 1)
    {
        usIcode = 1;
    }

    // Set I code
    ScalerSetByte(P1_A1_I_CODE_M, (BYTE)(usIcode >> 8));
    ScalerSetByte(P1_A2_I_CODE_L, (BYTE)usIcode);

    // Calculate P code
    usPcode = (WORD)(((DWORD)191 * usIcode * _EXT_XTAL / ((_APLL_N_CODE * GET_INPUT_TIMING_HFREQ() + 5) / 10)) >> 7); // Total Gain = 192/512

    // Get G value (ucData[15])
    pData[15] = ScalerAPLLGetAPLLGValue(&usPcode);

    // Set G value
    ScalerSetByte(P1_B6_P_CODE_MAPPING_METHOD, (pData[15] << 2));

    // Set P code
    ScalerSetByte(P1_A3_P_CODE, (BYTE)usPcode);

    // Set the P code Maximum
    ScalerSetByte(P1_B9_DDS_MIX_2, 0xFF);
    ScalerSetByte(P1_BA_DDS_MIX_3, 0xFF);

    if((ScalerGetBit(CM_4E_HSYNC_TYPE_DETECTION_FLAG, _BIT0)) == _BIT0)
    {
        // APLL Setting Apply at the End of Coast Window
        ScalerSetBit(P1_A0_PLL_DIV_CTRL, ~_BIT0, _BIT0);
    }
    else
    {
        // APLL Setting Apply at the End of DEN
        ScalerSetBit(P1_A0_PLL_DIV_CTRL, ~_BIT0, 0x00);
    }

    // Set the fast PLL setting by double buffer method
    ScalerSetBit(P1_AA_FAST_PLL_CTRL, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));

    if(!ScalerTimerPollingFlagProc(100, P1_AA_FAST_PLL_CTRL, _BIT6, 0))
    {
        return _FALSE;
    }

    // Increase stable time after APLL setting to avoid frame sync error when watch dog on.
    // Calculate the delay waiting for APLL stable.
    // Delay 200 lines to make sure auto run ready.
    pData[0] = (BYTE)((WORD)2000 / GET_INPUT_TIMING_HFREQ()) + 1;
    pData[0] = (pData[0] < 3) ? 3 : pData[0];

    // Add fineTune display position for VGA interlace mode.
    // Additional delay for interlaced timings for 4 IVS, as mute was found during clock adjustment.
    pData[1] = (ScalerGetBit(CM_4C_VSYNC_COUNTER_LEVEL_MSB, 0xFF) & 0x70) >> 4;

    if(((bit)(ScalerGetBit(CM_1A_IPV_ACT_LEN_H, _BIT5)) == _TRUE)
    && ((pData[1] == _XOR_OR_TYPE_CS_WITH_EQR) || (pData[1] == _XOR_OR_TYPE_CS_WITHOUT_EQR)))
    {
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
    }

    ScalerTimerDelayXms(pData[0]);

    return _TRUE;
}


WORD ScalerAPLLGetIHTotal(void)
{
    return ((((WORD)(ScalerGetByte(P1_B1_PLLDIV_H)) & 0x000F) << 8) | ScalerGetByte(P1_B2_PLLDIV_L)) + 1;
}

//--------------------------------------------------
// Description  : Apply Phase setting.
// Input Value  : ucPhase    --> For Apply  Phase step.
// Output Value : None.
//--------------------------------------------------
void ScalerPLLSetPhase(BYTE ucPhase, WORD usVfreq)
{
    BYTE ucEdgePhase = 0;
    BYTE ucEdgePhaseTemp = 0;
    BYTE ucLeftBound = 0;
    BYTE ucRightBound = 0;
    DWORD ulDotClock = 0;

    ucPhase = ucPhase & 0x3f;

    ///////////////////////////////////////////////////////////////////////////////////////
    // Code below is to select stable HSYNC latch edge.                                  //
    // Calculating delay between input clock into ADC and output from ADC.               //
    // Original Formula :                                                                //
    // select = 64 * 6.95  * ulRate / 1000000;                                           //
    ///////////////////////////////////////////////////////////////////////////////////////

    // Get the current IHTotal of ADC
    ulDotClock = (DWORD)(ScalerAPLLGetIHTotal()) * ScalerSyncProcMeasureIHFreqByStableMeasure();
    PDATA_DWORD(0) = ((DWORD)ScalerAPLLGetIHTotal() * GET_INPUT_TIMING_VTOTAL() * usVfreq) / 1000;

    // Get phase delay count
    ucEdgePhase = (ulDotClock * g_usPhaseDelayTime / 10000000) + _PHASE_DELAY_HALF_PERIOD_SHIFT;

    // Get phase delay count reference mode table
    ucEdgePhaseTemp= (PDATA_DWORD(0) * g_usPhaseDelayTime / 10000000) + _PHASE_DELAY_HALF_PERIOD_SHIFT;

    DebugMessageAnalog("Measure edge phase", ucEdgePhase);
    DebugMessageAnalog("Mode table edge phase", ucEdgePhaseTemp);

    // Eliminate measurement error if difference of edge phase is small
    if(ABSDWORD(ucEdgePhase, ucEdgePhaseTemp) <= _PHASE_DELAY_EDGEPHASE_THRESHOLD)
    {
        ucEdgePhase = ucEdgePhaseTemp;
    }

    ucLeftBound = ((ucEdgePhase + 64 - 12) % 64);
    ucRightBound = ((ucEdgePhase + 12) % 64);

    // Adjust VGIP one-pixel delay
    if(ucLeftBound < ucRightBound) // case1
    {
        if(ucPhase <= ucLeftBound)
        {
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), _BIT3);
        }
        else if((ucPhase > ucLeftBound) && (ucPhase <= ucRightBound))
        {
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), _BIT3);
        }
        else if(ucPhase > ucRightBound)
        {
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
        }
    }
    else // case 2
    {
        if(ucPhase < ucRightBound)
        {
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), _BIT3);
        }
        else if((ucPhase >= ucRightBound) && (ucPhase < ucLeftBound))
        {
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
        }
        else if(ucPhase >= ucLeftBound)
        {
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
        }
    }

    // Phase Select Method for Look Up Table (default)
    ScalerSetBit(P1_B1_PLLDIV_H, ~_BIT6, (_ADCPLL_PHASE_METHOD_LOOKUPTABLE << 6) & _BIT6);

    // Set phase
    if(ScalerGetBit(P1_B1_PLLDIV_H, _BIT4) == _BIT4)
    {
        ScalerSetBit(P1_B4_PLLPHASE_CTRL1, _BIT7, ((ucPhase << 1) & (~_BIT7)));
    }
    else
    {
        ScalerSetBit(P1_B4_PLLPHASE_CTRL1, _BIT7, (ucPhase & (~_BIT7)));
    }

    // Apply the above setting by setting Double Buffer Ready in VGIP
    ScalerVgipDoubleBufferApply();

    // Adjust VGIP clock polarity right after double-buffer applied
    if(ucLeftBound < ucRightBound) // case1
    {
        if(ucPhase <= ucLeftBound)
        {
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT0, _BIT0);
        }
        else if((ucPhase > ucLeftBound) && (ucPhase <= ucRightBound))
        {
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT0, 0x00);
        }
        else if(ucPhase > ucRightBound)
        {
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT0, _BIT0);
        }
    }
    else // case 2
    {
        if(ucPhase < ucRightBound)
        {
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT0, 0x00);
        }
        else if((ucPhase >= ucRightBound) && (ucPhase < ucLeftBound))
        {
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT0, _BIT0);
        }
        else if(ucPhase >= ucLeftBound)
        {
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT0, 0x00);
        }
    }
}

#endif // End of #if(_VGA_SUPPORT == _ON)
