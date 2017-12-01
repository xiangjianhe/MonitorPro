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
// ID Code      : RL6230_Series_PLL.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6230_SERIES_PLL__

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
#define _DPLL_SET_VCO_BAND                          1
#define _DPLL_SET_FREQ                              2
#define _DPLL_SET_POWER_ON                          3
#define _DPLL_SET_OFFSET                            4

//--------------------------------------------------
// Definations of DPLL Change
//--------------------------------------------------
#define _DPLL_FREQ_CHG_OVER_10PER                   0
#define _DPLL_FREQ_CHG_UNDER_10PER                  1

//--------------------------------------------------
// Definations of DPLL Range
//--------------------------------------------------
#define _DPLL_BOUNDRY_0                              28125
#define _DPLL_BOUNDRY_1                              33750
#define _DPLL_BOUNDRY_2                              56250
#define _DPLL_BOUNDRY_3                              67500
#define _DPLL_BOUNDRY_4                             112500
#define _DPLL_BOUNDRY_5                             135000
#define _DPLL_BOUNDRY_6                             225000

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    WORD usPEValue;
    WORD usPreHTotal;
    DWORD ulDivider;
} StructAdjustApllData;

//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructAdjustApllData g_stApllData = {0};

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerPllSetDpllReset(void);
void ScalerPllSetDpllOffset(WORD usOffset);
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
// Description  : Adjust DPLL Spread Spectrum
// Input Value  : Spread Spectrum Range
// Output Value : None
//--------------------------------------------------
void ScalerPllSetDpllReset(void)
{
    // Power Down DPLL
    ScalerSetBit(P1_C2_DPLL_WD, ~_BIT0, _BIT0);

    // Reset DPLL M Code
    ScalerSetByte(P1_BF_DPLL_M, 0x00);

    // Set DPLL BPN
    ScalerSetBit(P1_C0_DPLL_N, ~_BIT6, 0x00);

    // Reset DPLL Output Divier
    ScalerSetBit(P1_C0_DPLL_N, ~(_BIT5 | _BIT4), 0x00);

    // Reset DPLL N Code
    ScalerSetBit(P1_C0_DPLL_N, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // DPLL Bypass Calibration 
    ScalerSetBit(P1_C3_DPLL_CAL, ~_BIT5, _BIT5);

    // Disable DPLL Calibration Mode
    ScalerSetBit(P1_C3_DPLL_CAL, ~(_BIT4 | _BIT3 | _BIT2), 0x00);

    // Set Test Mode DCLK Divider = 2
    ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, _CM_8E_PT_06_PS_SELECT_TSTINCLOCK, ~_BIT1, 0x00);

    // Disable DPLL WD Reset, DPLL WD Set Normal, DPLL Freq Tuning Down, DPLL Reset VCO Normal
    ScalerSetBit(P1_C2_DPLL_WD, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT1), (_BIT4 | _BIT3));
    
    // Enable DDS Spread Spectrum Output, Disable fixed last line
    ScalerSetBit(P1_CA_EVEN_FIXED_LAST_LINE_CTRL, ~(_BIT1 | _BIT0), _BIT0);            
}

//--------------------------------------------------
// Description  : Adjust DPLL Offset
// Input Value  : Target Offset Value
// Output Value : None
//--------------------------------------------------
void ScalerPllSetDpllOffset(WORD usOffset)
{
    ScalerSetBit(P1_C4_DCLK_FINE_TUNE_OFFSET_MSB, 0xF0, (HIBYTE(usOffset) & 0x0F));
    ScalerSetByte(P1_C5_DCLK_FINE_TUNE_OFFSET_LSB, LOBYTE(usOffset));
    ScalerSetBit(P1_C6_DCLK_SPREAD_SPECTRUM, ~_BIT2, _BIT2);
}


//--------------------------------------------------
// Description  : Adjust DPLL Spread Spectrum
// Input Value  : Spread Spectrum Range
// Output Value : None
//--------------------------------------------------
void ScalerPllSetDpllSsc(bit bDclkSpreadSpeed, BYTE ucSpreadRange)
{
    ScalerSetBit(P1_C6_DCLK_SPREAD_SPECTRUM, 0x0F, ((ucSpreadRange << 4) & 0xF0));
    ScalerSetBit(P1_C6_DCLK_SPREAD_SPECTRUM, ~_BIT3, (((BYTE)bDclkSpreadSpeed << 3) & _BIT3));    
    ScalerSetBit(P1_C6_DCLK_SPREAD_SPECTRUM, ~_BIT2, _BIT2);
}

//--------------------------------------------------
// Description  : Set DPLL Freq
// Input Value  : Target Freq
// Output Value : None
//--------------------------------------------------
void ScalerPllSetDpllFreq(DWORD ulFreq)
{
    WORD usMcode = 0;
    BYTE ucDPLLSettingState = _DPLL_SET_POWER_OFF;
    bit bLVDSPower = 0;

    bLVDSPower = ScalerGetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, _BIT0);

    // usMcode = 16*real Mcode, for accuracy
    usMcode = ((ulFreq << 4) * 2 * 16 / ((DWORD)_EXT_XTAL * 15)); 

    // DPLL_VCO_clk_now
    PDATA_DWORD(0) = ulFreq * 16 / 15;

    if(bLVDSPower == _ON)
    {
        // DPLL_VCO_clk_before
        PDATA_DWORD(1) = (DWORD)(ScalerGetByte(P1_BF_DPLL_M) + 2) * _XTAL14318K / ((ScalerGetByte(P1_C0_DPLL_N) & 0x0F) + 2) / (1 << ((ScalerGetByte(P1_C0_DPLL_N) & 0x30) >> 4)) / 2;      

        if(ABSDWORD(PDATA_DWORD(0), PDATA_DWORD(1)) <= (PDATA_DWORD(1) / 10)) 
        {
            pData[14] = _DPLL_FREQ_CHG_UNDER_10PER;       
        }
        else
        {
            pData[14] = _DPLL_FREQ_CHG_OVER_10PER;
        } 
    }
    else
    {
        pData[14] = _DPLL_FREQ_CHG_OVER_10PER;
    }

    pData[15] = 0;

    // DPLL freq change under 10%, VCO band and div_o keep as before
    if(pData[14] == _DPLL_FREQ_CHG_UNDER_10PER)
    {
        // pData[15]: [5:4]=DPLL_O[1:0],[1:0]=DPLL VCO band  
        pData[15] = ((ScalerGetByte(P1_C0_DPLL_N) & 0x30) | ((ScalerGetByte(P1_C3_DPLL_CAL) & 0xC0) >> 6));            

        switch(((pData[15] & 0x30) >> 4))
        {
            case 0:
                
                pData[14] = 8;
                break;

            case 1:

                pData[14] = 4;
                break;

            case 2:
                
                pData[14] = 2;
                break;

            case 3:

                pData[14] = 1;
                break;

            default:

                break;
        }

        usMcode = (usMcode + (pData[14] >> 1)) / pData[14];

        if((usMcode - 2) == ScalerGetByte(P1_BF_DPLL_M))
        {
            ucDPLLSettingState = _DPLL_SET_OFFSET;
        }
        else
        {
            ucDPLLSettingState = _DPLL_SET_FREQ;
        }          
    }
    else
    {
        // pData[15]: [5:4]=DPLL_O[1:0],[1:0]=DPLL VCO band  
        if(PDATA_DWORD(0) < _DPLL_BOUNDRY_0) // DPLL_VCO = 2^3 * 2 * f_target
        {
            pData[15] = ((3 << 4) | (2)); 
        }
        else if(PDATA_DWORD(0) < _DPLL_BOUNDRY_1) // DPLL_VCO = 2^3 * 2 * f_target
        {
            pData[15] = ((3 << 4) | (3)); 
        }
        else if(PDATA_DWORD(0) < _DPLL_BOUNDRY_2) // DPLL_VCO = 2^2 * 2 * f_target
        {
            pData[15] = ((2 << 4) | (2));
        }
        else if(PDATA_DWORD(0) < _DPLL_BOUNDRY_3) // DPLL_VCO = 2^2 * 2 * f_target
        {
            pData[15] = ((2 << 4) | (3));
        }
        else if(PDATA_DWORD(0) < _DPLL_BOUNDRY_4) // DPLL_VCO = 2^1 * 2 * f_target
        {
            pData[15] = ((1 << 4) | (2)); 
        }
        else if(PDATA_DWORD(0) < _DPLL_BOUNDRY_5) // DPLL_VCO = 2^1 * 2 * f_target
        {
            pData[15] = ((1 << 4) | (3));
        }
        else if(PDATA_DWORD(0) < _DPLL_BOUNDRY_6) // DPLL_VCO = 2^0 * 2 * f_target
        {
            pData[15] = ((0 << 4) | (2));
        }    
        else // DPLL_VCO = 1 * 2 * f_target
        {
            pData[15] = ((0 << 4) | (3));
        }   

        switch(((pData[15] & 0x30) >> 4))
        {
            case 0:
                
                pData[14] = 8;
                break;

            case 1:

                pData[14] = 4;
                break;

            case 2:
                
                pData[14] = 2;
                break;

            case 3:

                pData[14] = 1;
                break;

            default:

                break;
        }

        usMcode = (usMcode + (pData[14] >> 1)) / pData[14];
    }   
 
    // Set DPLL Reference Clk to XTAL
    ScalerSetBit(P1_D4_DPLL_RESULT, ~_BIT7, 0x00);

    // Set DPLL test mode div=2
    ScalerSetDataPortBit(CM_8D_PS_ACCESS_PORT, _CM_8E_PT_06_PS_SELECT_TSTINCLOCK, ~_BIT1, 0x00);
    
    switch(ucDPLLSettingState)
    {
        case _DPLL_SET_POWER_OFF:

            // Wait DEN STOP
            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);             

            // Power Down LVDS
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~_BIT0, 0x00);

            // Power Down DPLL
            ScalerSetBit(P1_C2_DPLL_WD, ~_BIT0, _BIT0);             

        case _DPLL_SET_VCO_BAND:

            // Manual set VCO band
            ScalerSetBit(P1_C3_DPLL_CAL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), ((pData[15] & 0x03) << 6) | _BIT5);
            
        case _DPLL_SET_FREQ:

            // New Formula : Icp * N_Code / M_Code = 0.5 * Fxtal / 27MHz (for xtal not 27MHz) 
            // Icp = M_Code / N_Code * 0.5 * Fxtal / 27MHz, N_code = 2
            // Icp set 2.5uA, 5uA, 7.5uA, 10uA......            
            pData[0] = (DWORD)usMcode * _EXT_XTAL * 20 / 2 / 2 / _XTAL27000K;
            pData[1] = (pData[0] + 25) / 50;
            pData[1] -= (pData[1] == 0) ? 0 : 1;

            // Set M Code
            ScalerSetByte(P1_BF_DPLL_M, (usMcode - 2));
            
            // Set N Code and Output divider
            ScalerSetByte(P1_C0_DPLL_N, (pData[15] & 0x30));

            // Set Icp
            ScalerSetByte(P1_C1_DPLL_CRNT, (0x70 | (pData[1] & 0x07)));           

        case _DPLL_SET_POWER_ON:

            // Power Up DPLL
            ScalerSetBit(P1_C2_DPLL_WD, ~_BIT0, 0x00);            

        case _DPLL_SET_OFFSET:

            // Calculate DPLL Output Freq. According to current Settings
            PDATA_DWORD(0) = (DWORD)_EXT_XTAL * 1000 / ((1 << ((pData[15] & 0x30) >> 4)) * 2) * usMcode / 2;

            // Offset resolution (Dclk / 2^15) in Hz
            PDATA_DWORD(1) = PDATA_DWORD(0) >> 15;

            // Target frequency of Dclk in Hz
            PDATA_WORD(0) = (PDATA_DWORD(0) - (ulFreq * 1000)) / PDATA_DWORD(1);
            PDATA_WORD(0) = PDATA_WORD(0) & 0x0fff;    

            // Set Dpll Offset
            ScalerPllSetDpllOffset(PDATA_WORD(0));            
         
            break;

        default:

            break;
    }

    // Set LVDS power
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~_BIT0, bLVDSPower);

    // For RL6230 B Version Special Issue (Background clolor can't be used for aspect ratio Edge region)
    // ======== Start ====================
#if(_ASPECT_RATIO_SUPPORT == _ON)
    // Get Display V Active Start
    ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_10_DISP_DV_ACT_STA_H, 2, &pData[4], _AUTOINC);    

    // Get Display V Active End
    ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_12_DISP_DV_ACT_END_H, 2, &pData[6], _AUTOINC);  

    pData[0] = pData[5];
    pData[1] = ((pData[4] & 0x0F) | ((pData[6] & 0x0F) << 4));
    pData[2] = pData[7];
       
    // Get Display H Active Start
    ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_05_DISP_DH_ACT_STA_H, 2, &pData[6], _AUTOINC);  

    // Get Display H Active End
    ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_07_DISP_DH_ACT_END_H, 2, &pData[8], _AUTOINC);  

    // TCON[13] delay 41 pixels reference DHS
    ((WORD *)pData)[3] += 41;
    ((WORD *)pData)[4] += 41;
    
    pData[3] = pData[9];
    pData[4] = ((pData[6] & 0x0F) << 4) | (pData[8] & 0x0F);
    pData[5] = pData[7];

    // Set TCON[13] Timing  
    ScalerSetByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_70_TCON_TCON13_VPOSITION);
    ScalerWrite(CM_8C_TCON_DATA_PORT, 6, pData, _NON_AUTOINC);

    // _BIT7: Enable Timing Controller Function, _BIT5: Inactive Period Data Controlled by internal TCON [13]
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT7 | _BIT5), (_BIT7 | _BIT5));

    // _BIT7: Enable TCON[13]
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, 0x76, ~_BIT7, _BIT7);
#endif // End of #if(_ASPECT_RATIO_SUPPORT == _ON)
    // ======== End ====================

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
    WORD usDiffOffsetOld = 0;
    WORD usDiffOffsetNew = 0;

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

    // Get current (2^15 - offset)
    usDiffOffsetOld = 32768 - (((WORD)(ScalerGetByte(P1_C4_DCLK_FINE_TUNE_OFFSET_MSB) & 0x0F) << 8) | ScalerGetByte(P1_C5_DCLK_FINE_TUNE_OFFSET_LSB));

    DebugMessageFS("Original offset", 32768 - usDiffOffsetOld);

    /////////////////////////////////////////////////////////////////////////
    //
    //                                (2^15 - offset_old)
    // Offset bias =  -------------------------------------------------------
    //               input_act_region / abs(disp_act_region - input_act_region)
    //
    /////////////////////////////////////////////////////////////////////////
    PDATA_WORD(0) = (WORD)((((DWORD)usDiffOffsetOld << 16) / ((g_ulActiveRegionBackUp << 8) / labs(PDATA_DWORD(3) - g_ulActiveRegionBackUp)) + (WORD)0x0080) >> 8);

    // Calcuate new offset
    if(PDATA_DWORD(3) > g_ulActiveRegionBackUp)
    {
        usDiffOffsetNew = usDiffOffsetOld + PDATA_WORD(0);
    }
    else
    {
        usDiffOffsetNew = usDiffOffsetOld - PDATA_WORD(0);        
    }
   
#if(_2D_TO_3D_FUNCTION == _ON)
    if(GET_INTERLACED_MODE() == _TRUE)
    {
        // Apply Offset for last-line
        ScalerPllSetDpllOffset(32768 - usDiffOffsetNew);

        DebugMessageFS("New offset", 32768 - usDiffOffsetNew);

        // Calculate Modified DClk by offset
        SET_D_CLK_FREQ((GET_D_CLK_FREQ() / usDiffOffsetOld) * usDiffOffsetNew + ((GET_D_CLK_FREQ() % usDiffOffsetOld) * usDiffOffsetNew) / usDiffOffsetOld);

        g_ulLastLineCompen = 0;        
        return;
    }
#endif

    /////////////////////////////////////////////////////////////////////////
    // Fine Tune Last Line to Panel Target
    // Dtotal = DHtotal * DV count + Last-line    
    //
    // Dtotal' = Dtotal * (2^15 - offset_new) / (2^15 - offset_old)
    //         = round(Dtotal / (2^15 - offset_old)) * (2^15 - offset_new) + round((Dtotal % (2^15 - offset_old)) * (2^15 - offset_new) / (2^15 - offset_old))    
    //
    // estimated last line = Dtotal' % DHtotal
    //    
    // offset bias = abs(Dtotal_old - Dtotal_new) / Dtotal * (2^15 - offset_old)
    /////////////////////////////////////////////////////////////////////////

    // Calculate Dtotal
    PDATA_DWORD(3) = (DWORD)usDVtotal * g_stMDomainOutputData.usHTotal + usLastLine;

    // Calculate Dtotal'
    PDATA_WORD(2) = PDATA_DWORD(3) / usDiffOffsetOld; // ratio
    PDATA_WORD(3) = PDATA_DWORD(3) % usDiffOffsetOld; // remainder
    PDATA_DWORD(3) = (DWORD)PDATA_WORD(2) * usDiffOffsetNew + ((DWORD)PDATA_WORD(3) * usDiffOffsetNew) / usDiffOffsetOld;

    // Calculate new last-line
    usLastLine = PDATA_DWORD(3) % g_stMDomainOutputData.usHTotal;

    DebugMessageFS("Estimated last-line", usLastLine);

    // Calculate modified Dtotal
    PDATA_DWORD(2) = PDATA_DWORD(3) - usLastLine + _LAST_LINE_TARGET;  // - 

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
    
    // Calculate offset bias
    PDATA_WORD(0) = (((labs(PDATA_DWORD(3) - PDATA_DWORD(2)) * (usDiffOffsetNew << 1) / PDATA_DWORD(3)) + 1) >> 1);

    if(PDATA_DWORD(3) > PDATA_DWORD(2))
    {
        usDiffOffsetNew = usDiffOffsetNew - PDATA_WORD(0);
    }
    else
    {
        usDiffOffsetNew = usDiffOffsetNew + PDATA_WORD(0);        
    }

    // Apply Offset for last-line
    ScalerPllSetDpllOffset(32768 - usDiffOffsetNew);

    DebugMessageFS("New offset", 32768 - usDiffOffsetNew);

    // Calculate Modified DClk by offset
    SET_D_CLK_FREQ((GET_D_CLK_FREQ() / usDiffOffsetOld) * usDiffOffsetNew + ((GET_D_CLK_FREQ() % usDiffOffsetOld) * usDiffOffsetNew) / usDiffOffsetOld);

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

        DebugMessageAnalog("Adjust APLL Clock Fail PDF", 0);

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
        DebugMessageAnalog("Adjust APLL Clock Fail Unlock", 0);
        
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
        ScalerTimerWaitForEvent(_EVENT_IVS);

        // The slowest timing is 576i, IHFreq = 15.63k =>(5(V-Sync Pulse) + 1 (Coast falling edge)) * 1 / 15.63 = 384us
        // The fastedt timing is 2048x1536-60_RB, IHFreq = 94.77k =>(5(V-Sync Pulse) + 1 (Coast falling edge)) * 1 / 94.77 = 63us
        ScalerTimerDelayXms(2);

        // Use force apll setting method.
        ScalerSetBit(P1_AA_FAST_PLL_CTRL, ~(_BIT4 | _BIT5 | _BIT6), (_BIT4 | _BIT5 | _BIT6));
    }
    else
    {
        // Set the fast PLL setting by double buffer method
        ScalerSetBit(P1_AA_FAST_PLL_CTRL, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));
    }

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

    if(ucLeftBound < ucRightBound) // case1
    {
        if(ucPhase <= ucLeftBound)
        {
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), 0x00);
        }
        else if((ucPhase > ucLeftBound) && (ucPhase <= ucRightBound))
        {
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
        }
        else if(ucPhase > ucRightBound)
        {
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), _BIT4);
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
            ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3), 0x00);
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
}

#endif // End of #if(_VGA_SUPPORT == _ON)
