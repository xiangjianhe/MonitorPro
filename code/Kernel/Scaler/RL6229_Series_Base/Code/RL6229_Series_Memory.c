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
// ID Code      : RL6229_Series_Memory.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6229_SERIES_MEMORY__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _SEARCH_LINE_STEP                       1 
#define _DELAY_SEARCH_TIME                      10

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerMemorySetScalingCoef(BYTE *pAddress1, BYTE *pAddress2, WORD usWriteLength, BYTE ucBankNum);
void ScalerMemorySetUpLineBuffer(void);
void ScalerMemorySetFIFOFreq(EnumScalerFIFOFreq enFIFOFreq);
void ScalerMemoryInitial(void);
WORD ScalerMemoryGetScaleUpDt(void);
void ScalerMemoryCompensateDtForLastLine(DWORD ulTargetLastLine, DWORD ulCurrentLastLine);
void ScalerMemoryFrameSyncSetDt(void);
void ScalerMemorySetFifoCapture(WORD usHWidth, WORD usVHeight);

#if(_2D_TO_3D_FUNCTION == _ON)
void ScalerMemoryFrameSyncTuneDt(void);
BYTE ScalerMemoryFrameSyncTest(DWORD ulDelayTime);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Set Scaling Up Coeffitient Table
// Input Value  : Table Number to be chosen
// Output Value : None
//--------------------------------------------------
void ScalerMemorySetScalingCoef(BYTE *pAddress1, BYTE *pAddress2, WORD usWriteLength, BYTE ucBankNum)
{    
    // Set Coefficient table 1
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6), _BIT7);    
    ScalerBurstWrite(pAddress1, usWriteLength, ucBankNum, CM_36_FILTER_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    
    // Set Coefficient table 2
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(pAddress2, usWriteLength, ucBankNum, CM_36_FILTER_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Disable Coefficient Access
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT7 | _BIT6), 0x00);
    
#if(_3D_SUPPORT == _ON)        

#if((_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_NORMAL) || (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))

    // Set H/V Scale Up to use coefficient table 1
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT5 | _BIT4), 0x00); 

#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

#if(_2D_TO_3D_FUNCTION == _ON)

    // PR no 3D ||  2D DIsplay || shutter panel: 00,  other 01
    if(((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && (GET_2DTO3D_ENABLE() == _DISABLE)) || ((GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT) && (GET_3D_OUTPUT_SEQUENCE()) == _3D_DISPLAY_2D))
    {
        // Set H/V Scale Up to use coefficient table 1
        ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT5 | _BIT4), 0x00); 
    }
    else
    {
        // Set HSU to use coefficient table 1 & set VSU to use coefficient table 2
        ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT5 | _BIT4), _BIT4);     
    }

#else

    // PR no 3D ||  2D DIsplay || shutter panel: 00,  other 01
    if((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) || ((GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT) && (GET_3D_OUTPUT_SEQUENCE()) == _3D_DISPLAY_2D))
    {
        // Set H/V Scale Up to use coefficient table 1
        ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT5 | _BIT4), 0x00); 
    }
    else
    {
        // Set HSU to use coefficient table 1 & set VSU to use coefficient table 2
        ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT5 | _BIT4), _BIT4);     
    }
    
#endif // End of #if(_2D_TO_3D_FUNCTION == _ON)

#endif // End of #if((_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_NORMAL) ||  (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))

#else // Else of #if(_3D_SUPPORT == _ON)

    // Set HSU to use coefficient table 1 & set VSU to use coefficient table 2
    ScalerSetBit(CM_35_FILTER_CTRL, ~(_BIT5 | _BIT4), _BIT4);   

#endif // End of #if(_3D_SUPPORT == _ON)

}

//--------------------------------------------------
// Description  : Set Up Line Buffer Regarding Current Scaling option
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemorySetUpLineBuffer(void)
{
    if(GET_V_SCALE_UP()== _TRUE)
    {
        // Disable Full Line Buffer
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT4, 0x00);

        // Disable Series Four Line Buffer
        ScalerSetDataPortBit(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_00_DISP_DH_TOTAL_H, ~_BIT7, 0x00);
    }    
    else
    {
        // Enable Full Line Buffer
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT4, _BIT4);

        // Disable Series Four Line Buffer
        ScalerSetDataPortBit(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_00_DISP_DH_TOTAL_H, ~_BIT7, 0x00);            
    }
}

//--------------------------------------------------
// Description  : SDRAM Fifo Freq Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemorySetFIFOFreq(EnumScalerFIFOFreq enFIFOFreq)
{
    switch(enFIFOFreq)
    {
        case _SCALER_FIFO_FREQ_M2PLL:
            ScalerSetBit(CM_22_FIFO_FREQUENCY, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
            break;

        case _SCALER_FIFO_FREQ_MPLL:
            ScalerSetBit(CM_22_FIFO_FREQUENCY, ~(_BIT1 | _BIT0), 0x00);
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : M Domain Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemoryInitial(void)
{
	ScalerSDRAMInitialTable();
}

//--------------------------------------------------
// Description  : Calculate Dt Value for Scale Up
// Input Value  : None
// Output Value : Calculated Dt in 0.01 Lines
//--------------------------------------------------
WORD ScalerMemoryGetScaleUpDt(void)
{
    BYTE ucMax = 0;
    BYTE ucMin = 100;
    BYTE ucCount = 0;
    BYTE ucTemp[6];
    WORD usDtMinOri = 0;
    WORD usDtMinMod = 0;
    WORD usDtMax = 0; 
 
    // All Calculation is Based on a 128 Multiplier
    // Calculate VFCI
    ((WORD *)ucTemp)[1] = ((WORD)g_ucVFCI << 8) / 256 / 2;

    // Since MSB would be Eliminated by Mod, Only WORD is Required
    ((WORD *)ucTemp)[2] = ((DWORD)g_stMDomainInputData.usVHeight << 13) / g_stMDomainOutputData.usVHeight;
    
    // Get Min and Max Value
    do
    {
        // (VFCI + n * VSF) mod 1
        ucTemp[0] = (((WORD *)ucTemp)[1] + (((WORD)ucCount * ((WORD *)ucTemp)[2]) >> 6)) & 0x7F;

        if(ucTemp[0] > ucMax)
        {
            ucMax = ucTemp[0];
        }

        if(ucTemp[0] < ucMin)
        {
            ucMin = ucTemp[0];
        }

        ucCount++;
    }while(ucCount < 255);

    DebugMessageFS("5.Calculated Max", ucMax);
    DebugMessageFS("5.Calculated Min", ucMin); 
    DebugMessageFS("5.VFCI", ((WORD *)ucTemp)[1]); 
 
    // Get FIFO Input Width
    ScalerGetDataPortByte(CM_30_FIFO_ACCESS_PORT, _CM_31_PT_00_FIFO_DRL_H_BSU, 2, ucTemp, _AUTOINC);    
    ucTemp[0] = (ucTemp[0] >> 4) & 0x0F;       

    // Change Base From 128 to 100
    ((WORD *)ucTemp)[1] = (((WORD *)ucTemp)[1] * 100) >> 7;
    ucMax = ((WORD)ucMax * 100) >> 7;
    ucMin = ((WORD)ucMin * 100) >> 7;    

#if(_3D_SUPPORT == _ON)    
    if(ScalerScalingGetScalingUpType() == _VSU_3D_3LINE_COEF)
    { 
        // Dt min = 4 + (2 * VFCI - 2 * min - VSF * (DHTotal + DHActiveEnd) / DHTotal) 
        usDtMinOri = 400 + ((WORD *)ucTemp)[1] * 2 - 2 * ucMin - (DWORD)g_stMDomainInputData.usVHeight * (g_stMDomainOutputData.usHTotal + g_stMDomainOutputData.usHStart + g_stMDomainOutputData.usHWidth) / g_stMDomainOutputData.usVHeight * 100 / g_stMDomainOutputData.usHTotal;
        DebugMessageScaler("5.Alia Target 3D Dt Value min original", usDtMinOri);
        
        // Dt min = 4 + (2 * VFCI - 2 * min - 1 - VSF * DHActiveSt / DHTotal) 
        usDtMinMod = 400 + ((WORD *)ucTemp)[1] * 2 - 2 * ucMin - 100 - (DWORD)g_stMDomainInputData.usVHeight * (g_stMDomainOutputData.usHStart) / g_stMDomainOutputData.usVHeight * 100 / g_stMDomainOutputData.usHTotal;
        DebugMessageScaler("5.Alia Target 3D Dt Value min modify", usDtMinMod);
 
        // Dt max = 4 + FIFODepth / FIFOWIDTH - 2 * (max - VFCI) - VSF * DHActiveSt / DHTotal 
        usDtMax = 390 + (DWORD)_FIFO_SIZE * 100 / ((WORD *)ucTemp)[0] - 2 * (ucMax - ((WORD *)ucTemp)[1]) - (DWORD)g_stMDomainInputData.usVHeight * (g_stMDomainOutputData.usHStart)/ g_stMDomainOutputData.usVHeight * 100 / g_stMDomainOutputData.usHTotal;
        DebugMessageScaler("5.Alia Target 3D Dt Value max", usDtMax);
 
        ((WORD *)ucTemp)[0] = (((usDtMinOri > usDtMinMod) ? usDtMinOri : usDtMinMod) + usDtMax) >> 1;
        DebugMessageFS("5. Target 3D Dt Value", ((WORD *)ucTemp)[0]);  
        
    }
    else
    {                                       
        // Target Dt = 2 - (Max + Min) / 2 + VFCI + FIFODepth / 2FIFOHWidth - VSF * (DHactiveEnd + DHstart)/2DHtotal
        ((WORD *)ucTemp)[0] = 200 - ((ucMax + ucMin) >> 1) + ((WORD *)ucTemp)[1] + (DWORD)_FIFO_SIZE * 50 / ((WORD *)ucTemp)[0] - (DWORD)g_stMDomainInputData.usVHeight * (2 * g_stMDomainOutputData.usHStart + g_stMDomainOutputData.usHWidth) / g_stMDomainOutputData.usVHeight * 50 / g_stMDomainOutputData.usHTotal;

        DebugMessageFS("5.Target Dt Value", ((WORD *)ucTemp)[0]);            
    }
#else

    // Target Dt = 2 - (Max + Min) / 2 + VFCI + FIFODepth / 2FIFOHWidth - VSF * (DHactiveEnd + DHstart)/2DHtotal
    ((WORD *)ucTemp)[0] = 200 - ((ucMax + ucMin) >> 1) + ((WORD *)ucTemp)[1] + (DWORD)_FIFO_SIZE * 50 / ((WORD *)ucTemp)[0] - (DWORD)g_stMDomainInputData.usVHeight * (2 * g_stMDomainOutputData.usHStart + g_stMDomainOutputData.usHWidth) / g_stMDomainOutputData.usVHeight * 50 / g_stMDomainOutputData.usHTotal;

    DebugMessageFS("5.Target Dt Value", ((WORD *)ucTemp)[0]);  
    
#endif
    
    return ((WORD *)ucTemp)[0];    
}

//--------------------------------------------------
// Description  : Compensate Last Line Fine Tune
// Input Value  : Target Last Line, Current Last Line
// Output Value : None
//--------------------------------------------------
void ScalerMemoryCompensateDtForLastLine(DWORD ulTargetLastLine, DWORD ulCurrentLastLine)
{
    // Get Initial Dt Fine Tune Value
    PDATA_DWORD(0) = (DWORD)ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES) * g_stMDomainInputData.usHTotal + ((DWORD)ScalerGetByte(CM_41_IV_DV_DELAY_CLK_ODD) + 1) * 16;

    DebugMessageFS("Original Dt", PDATA_DWORD(0));

#if(_2D_TO_3D_FUNCTION == _ON)

    // Compensate value = ((Target Last Line - Current Last Line) * DVHeight / DVTotal * IVHeight / DVHeight * IHTotal / DHTotal) / 2
    g_ulLastLineCompen = ((((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine) * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVTotal * g_stMDomainInputData.usHTotal / g_stMDomainOutputData.usHTotal) >> 1);
        
    // Compensate Dt = Original Dt + Compensate value
    PDATA_DWORD(0) = (SDWORD)PDATA_DWORD(0) + g_ulLastLineCompen;

#else

    // Compensate value = ((Target Last Line - Current Last Line) * DVHeight / DVTotal * IVHeight / DVHeight * IHTotal / DHTotal) / 2
    (SDWORD)PDATA_DWORD(2) = ((((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine) * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVTotal * g_stMDomainInputData.usHTotal / g_stMDomainOutputData.usHTotal) >> 1);
    
    // Compensate Dt = Original Dt + Compensate value
    PDATA_DWORD(0) = (SDWORD)PDATA_DWORD(0) + (SDWORD)PDATA_DWORD(2);

#endif   

    DebugMessageFS("Last Line Difference", ((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine));
    DebugMessageFS("Dt Compensate Value", (((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine) * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVTotal * g_stMDomainInputData.usHTotal / g_stMDomainOutputData.usHTotal) >> 1);
    
    DebugMessageFS("Compensated Dt", PDATA_DWORD(0));    
    
    pData[0] = (BYTE)((PDATA_DWORD(0) - (g_stMDomainInputData.usHTotal >> 1) - 64) / g_stMDomainInputData.usHTotal);
    pData[1] = (BYTE)((PDATA_DWORD(0) - ((DWORD)g_stMDomainInputData.usHTotal * pData[0]) + 8) >> 4);           
    pData[2] = pData[1] - ((g_stMDomainInputData.usHTotal + 16) >> 5);

    // Apply updated Delay
    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[0]);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, pData[1]);
    ScalerSetByte(CM_42_IV_DV_DELAY_CLK_EVEN, pData[2]); 
}

//--------------------------------------------------
// Description  : Setup Frame Sync Dt
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemoryFrameSyncSetDt(void)
{
    DWORD ulIVStoDVSPixels;

    // Calculate DVS to DH Active in ICLK
    PDATA_DWORD(0) = ((DWORD)g_stMDomainOutputData.usHTotal * g_stMDomainOutputData.usVStart) + g_stMDomainOutputData.usHStart;
    PDATA_DWORD(0) = PDATA_DWORD(0) * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVHeight * g_stMDomainInputData.usHTotal / g_stMDomainOutputData.usHTotal;
    
    // Calculate IVS to IH Active in ICLK
    PDATA_DWORD(1) = ((DWORD)g_stMDomainInputData.usHTotal * g_stMDomainInputData.usVStart) + g_stMDomainInputData.usHStart;    
    
    // Frame Sync Memory Settings
    if(GET_V_SCALE_UP() == _TRUE)    // Vertical Scaling Up
    {   
        PDATA_DWORD(1) += (DWORD)g_stMDomainInputData.usHTotal * (ScalerMemoryGetScaleUpDt() - 100) / 100;
    }
    else
    {        
        // Vertical Scaling Down
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))  
        if((GET_V_SCALE_DOWN() == _TRUE) || (GET_V_SCALE_DOWN_2_DIFF_PHASE() == _TRUE))   
#else
        if(GET_V_SCALE_DOWN() == _TRUE)
#endif
        {
#if(_2D_TO_3D_FUNCTION == _ON)
            PDATA_DWORD(1) += g_stMDomainInputData.usHTotal + ((DWORD)g_stMDomainInputData.usHTotal * 8 / 10) + ((DWORD)g_stMDomainInputData.usHTotal * g_stMDomainInputData.usVHeight / (g_stMDomainOutputData.usVHeight * 2));
#else  
            PDATA_DWORD(1) += g_stMDomainInputData.usHTotal + ((DWORD)g_stMDomainInputData.usHTotal * g_stMDomainInputData.usVHeight / (g_stMDomainOutputData.usVHeight * 2));
#endif            
        }
        else    // Vertical Scaling Bypass
        {
            PDATA_DWORD(1) += g_stMDomainInputData.usHTotal + g_stMDomainInputData.usHTotal / 2;            
        }
    }

    // If DVSt > (IVSt + Dt) means no further IVS2DVSDelay can be added!!
    // Preserve 2 line margin in advance
    PDATA_DWORD(3) = PDATA_DWORD(0) + 2 * g_stMDomainInputData.usHTotal;
       
    if(PDATA_DWORD(3) > PDATA_DWORD(1))
    {      
        // Calculate insufficient line number
        pData[8] = (PDATA_DWORD(3) - PDATA_DWORD(1)) / g_stMDomainInputData.usHTotal + 1;

        DebugMessageFS("2. No Further IVS2DVSDelay Can Be Added", pData[8]);
        
        // Enlarge IVSt for insufficient lines
        g_stMDomainInputData.usVStart += pData[8];
        ScalerSetBit(CM_18_IPV_ACT_STA_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(g_stMDomainInputData.usVStart) & 0x0F));
        ScalerSetByte(CM_19_IPV_ACT_STA_L, LOBYTE(g_stMDomainInputData.usVStart));

        // Modify Original (IVSt + Dt) Value
        PDATA_DWORD(1) += pData[8] * g_stMDomainInputData.usHTotal;
    }    
      
    // Set IVS to DVS Delay
    PDATA_DWORD(0) = PDATA_DWORD(1) - PDATA_DWORD(0);

    DebugMessageFS("Target IVS to DVS Delay Value", PDATA_DWORD(0));

    // Get Current IVS2DVS Delay + DVS Width in Input Lines (Get Ceiling Value) + 1 line for margin
    pData[5] = (PDATA_DWORD(0) + (DWORD)_PANEL_DV_SYNC_HEIGHT * g_stMDomainInputData.usVHeight * g_stMDomainInputData.usHTotal / g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usHTotal + 1;
    
    // Enlarge DVSt if IVS2DVS Delay + DVS Width is larger than IVSt
    if(pData[5] >= g_stMDomainInputData.usVStart)
    {
        DebugMessageFS("2. Target IVS2DVS Delay too Large", pData[5]);

        // Get the difference between IVS2DVS Delay and IVSt
        pData[5] = pData[5] - g_stMDomainInputData.usVStart + 1; 

        // Get Required Increment of DVSt
        pData[5] = pData[5] * g_stMDomainOutputData.usVHeight / g_stMDomainInputData.usVHeight + 1;

        DebugMessageFS("2. Required Modification on DVSt", pData[5]);
        
        // Modify DVSt
        g_stMDomainOutputData.usVStart += pData[5];

        // Modify IVS2DVS Delay
        PDATA_DWORD(0) -= (DWORD)pData[5] * g_stMDomainInputData.usHTotal * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVHeight;    
    }

    // Store IVS-to-DVS pixels
    ulIVStoDVSPixels = PDATA_DWORD(0);

    // Before is frame sync mode, current is frame sync mode, check IVS2DVS delay change
    if(ScalerGetBit(CM_28_VDISP_CTRL, _BIT3) == _BIT3)
    {
        // Calculate current frame sync fine-tune value
        pData[5] = (PDATA_DWORD(0) / g_stMDomainInputData.usHTotal);
        pData[6] = (PDATA_DWORD(0) - ((DWORD)g_stMDomainInputData.usHTotal * pData[5]) + 8) >> 4;

        // Get Old IVS2DVS + IVSdelay
        PDATA_DWORD(0) = (((WORD)((ScalerGetByte(CM_3E_IVS2DVS_DEALY_LINES_H)) & 0x0F) << 8) | ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES)) + ScalerVgipGetCaptureVDelay();    

        // old > new, Calculate old and new (IVS2DVS + IVSdelay) diff, new IVSdelay = 0
        PDATA_DWORD(0) -= (PDATA_DWORD(0) > pData[5]) ? pData[5] : PDATA_DWORD(0); 

        // (IVS2DVS + IVSdelay) diff (D_line)
        PDATA_DWORD(0) = PDATA_DWORD(0) * g_stMDomainOutputData.usVBackHeight / g_stMDomainInputData.usVHeight;

        // Display front porch
        PDATA_DWORD(2) = (DWORD)(g_stMDomainOutputData.usVTotal - g_stMDomainOutputData.usVBackHeight - g_stMDomainOutputData.usVStart);                

        // (IVS2DVS + IVSdelay) diff > Display front porch
        if(PDATA_DWORD(0) > PDATA_DWORD(2))
        {   
            ScalerSetBit(CM_44_LAST_LINE_H, ~_BIT7, _BIT7);
            
            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);

            // Current DVtotal
            PDATA_WORD(7) = (((ScalerGetByte(CM_44_LAST_LINE_H) & 0x0F) << 8) | ScalerGetByte(CM_45_LAST_LINE_L));              
            PDATA_WORD(0) = 2 * PDATA_WORD(7) - PDATA_DWORD(0);

            ScalerSetBit(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(PDATA_WORD(0))) & 0x0F);
            ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, (LOBYTE(PDATA_WORD(0))));    

            ScalerTimerWaitForEvent(_EVENT_DEN_STOP); 

            ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT3, 0x00);

            ScalerSetByte(CM_3E_IVS2DVS_DEALY_LINES_H, 0x00);    
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[5]);

            // Aviod setting CR41 by negative value cause frame sync error
            pData[6] = (pData[6] == 0 ? 1 : pData[6]);
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, (pData[6] - 1));

            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5);

            // Wait double buffer
            ScalerTimerWaitForEvent(_EVENT_IVS);  
            ScalerTimerWaitForEvent(_EVENT_IVS);  

            ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT3, _BIT3);                
        }
    } 

#if(_3D_SUPPORT == _ON)
    if((GET_INTERLACED_MODE() == _TRUE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D))
#else
    if(GET_INTERLACED_MODE() == _TRUE)
#endif
    {
        // VGA Input or Prefered Timing
        if((ScalerGetBit(CM_10_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) || (GET_INPUT_TIMING_HWIDTH() == _PANEL_DH_WIDTH))
        {
            // Disable Video Compensation
            ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT7, 0x00);
        }
        else
        {
            // Enable Video Compensation According to Odd Field Delay One Line
            ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT7, _BIT7);
        }
    
        // Video Compensation on Even Field
        if(ScalerGetBit(CM_32_SCALE_CTRL, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6))
        {
            // Enable Frame Sync Fine Tune on Odd Field
            ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
        }
        // Video Compensation on Odd Field
        else if(ScalerGetBit(CM_32_SCALE_CTRL, (_BIT7 | _BIT6)) == _BIT7)    
        {
            // Enable Frame Sync Fine Tune on Even Field
            ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~(_BIT1 | _BIT0), _BIT1);
        }
        else
        {
            // Disable Frame Sync Fine Tune
            ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~_BIT1, 0x00);
        }        
    }   
    else
    {    
        // Disable Frame Sync Fine Tune
        ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~_BIT1, 0x00);

        // Disable Video Compensation
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT7, 0x00);
    }

    // Calculate frame sync fine-tune value
    if(ScalerGetBit(CM_43_FS_DELAY_FINE_TUNING, _BIT1) == _BIT1)
    {
        // Preserve 0.5 lines + 64 pixel in Fine Tune Byte
        pData[5] = (ulIVStoDVSPixels - (g_stMDomainInputData.usHTotal >> 1) - 64) / g_stMDomainInputData.usHTotal;
        pData[6] = (ulIVStoDVSPixels - ((DWORD)g_stMDomainInputData.usHTotal * pData[5]) + 8) >> 4;

        ScalerSetByte(CM_3E_IVS2DVS_DEALY_LINES_H, 0x00);
        ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[5]);
        ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, (pData[6] - 1));

        pData[6] = pData[6] - ((g_stMDomainInputData.usHTotal + 16) >> 5);

        // Aviod setting CR42 by negative value cause frame sync error
        pData[6] = (pData[6] == 0 ? 1 : pData[6]);
        ScalerSetByte(CM_42_IV_DV_DELAY_CLK_EVEN, (pData[6] - 1));
    }
    else
    {
        pData[5] = (ulIVStoDVSPixels / g_stMDomainInputData.usHTotal);
        pData[6] = (ulIVStoDVSPixels - ((DWORD)g_stMDomainInputData.usHTotal * pData[5]) + 8) >> 4;

        // Aviod setting CR41 by negative value cause frame sync error
        pData[6] = (pData[6] == 0 ? 1 : pData[6]);
        ScalerSetByte(CM_3E_IVS2DVS_DEALY_LINES_H, 0x00);
        ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[5]);
        ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, (pData[6] - 1));
    }
}

//--------------------------------------------------
// Description  : Set FIFO Capture
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerMemorySetFifoCapture(WORD usHWidth, WORD usVHeight)
{
    ScalerSetByte(CM_30_FIFO_ACCESS_PORT, _CM_31_PT_00_FIFO_DRL_H_BSU);
    ScalerSetByte(CM_31_FIFO_DATA_PORT, (((HIBYTE(usHWidth) & 0x0F) << 4) | (HIBYTE(usVHeight) & 0x0F)));
    ScalerSetByte(CM_31_FIFO_DATA_PORT, LOBYTE(usHWidth));
    ScalerSetByte(CM_31_FIFO_DATA_PORT, LOBYTE(usVHeight));   

    ScalerSetBit(P5_A6_SDRF_IN1_PXL_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(usHWidth) & 0x0F));
    ScalerSetByte(P5_A7_SDRF_IN1_PXL_NUM_L, LOBYTE(usHWidth));
    ScalerSetBit(P5_BE_SDRF_MN_PXL_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(usHWidth) & 0x0F));    
    ScalerSetByte(P5_BF_SDRF_MN_PXL_NUM_L, LOBYTE(usHWidth));      
}

#if(_2D_TO_3D_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Adjust Dclk offset to meet frame sync
// Input Value  : None
// Output Value : Return 0 if success
//--------------------------------------------------
void ScalerMemoryFrameSyncTuneDt(void)
{
    DWORD ulDelayTime = 0;
    WORD usSearchStep = 0;
    BYTE ucCount = 0;   

    // Get Initial Dt Fine Tune Value
    ulDelayTime = (DWORD)ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES) * g_stMDomainInputData.usHTotal + ((DWORD)ScalerGetByte(CM_41_IV_DV_DELAY_CLK_ODD) + 1) * 16;

    // Let Search Step be 0.1 input line
    usSearchStep = g_stMDomainInputData.usHTotal / 10;
    
    pData[0] = ScalerMemoryFrameSyncTest(ulDelayTime);
    
    DebugMessageFS("2. Initial Test Result", pData[0]);   

    switch(pData[0])
    {
        // Initial Dt is OK
        case 0x00:
            
            return;
            
            break;

        // Buffer Underflow => Delay Too Small
        case _BIT0:

            // Enlarge Delay until No Underflow
            ucCount = _DELAY_SEARCH_TIME;            
            do
            {
                DebugMessageFS("2. Underflow Tune Dt", ucCount); 
                
                ulDelayTime += usSearchStep * _SEARCH_LINE_STEP;
                pData[0] = ScalerMemoryFrameSyncTest(ulDelayTime);

                // No Underflow
                if(pData[0] != _BIT0)
                {
                    // Overflow
                    if(pData[0] == _BIT1)
                    {
                        // Minus 0.5 line if Overflow
                        ulDelayTime -= (usSearchStep * _SEARCH_LINE_STEP) >> 1;
                    }
                    break;
                }
            }
            while(--ucCount);
                        
            break;
            
        // Buffer Overflow => Delay Too Large
        case _BIT1:
            
            // Shrink Delay until No Overflow
            ucCount = _DELAY_SEARCH_TIME;            
            do
            {
                ulDelayTime -= usSearchStep * _SEARCH_LINE_STEP;
                pData[0] = ScalerMemoryFrameSyncTest(ulDelayTime);

                // No Overflow
                if(pData[0] != _BIT1)
                {
                    // Underflow
                    if(pData[0] == _BIT0)
                    {
                        // Plus 0.5 line if Underflow
                        ulDelayTime += (usSearchStep * _SEARCH_LINE_STEP) >> 1;
                    }                    
                    break;
                }
            }
            while(--ucCount);

            
            break;
            
        default:
            break;            
    }

    pData[0] = (BYTE)((ulDelayTime - (g_stMDomainInputData.usHTotal >> 1) - 64) / g_stMDomainInputData.usHTotal);
    pData[1] = (ulDelayTime - ((DWORD)g_stMDomainInputData.usHTotal * pData[0]) + 8) >> 4;
    
    // Apply updated Delay
    ScalerSetByte(CM_3E_IVS2DVS_DEALY_LINES_H, 0x00);    
    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[0]);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, (pData[1] - 1));
    pData[1] = pData[1] - ((g_stMDomainInputData.usHTotal + 16) >> 5);
    ScalerSetByte(CM_42_IV_DV_DELAY_CLK_EVEN, (pData[1] - 1));
    
    // Apply Double Buffer
    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5);
}

//--------------------------------------------------
// Description  : Apply Target Delay and Test whether Frame Sync is OK
// Input Value  : Target Delay Time
// Output Value : Return 0 Line Buffer Status
//--------------------------------------------------
BYTE ScalerMemoryFrameSyncTest(DWORD ulDelayTime)
{
    pData[0] = ulDelayTime / g_stMDomainInputData.usHTotal;
    pData[1] = (((ulDelayTime - (DWORD)pData[0] * g_stMDomainInputData.usHTotal) + 8) >> 4);

    if(pData[1] == 0x00)
    {
        pData[0] -= 1;
        pData[1] += g_stMDomainInputData.usHTotal >> 4;
    }            
        
    // Set Target Delay
    ScalerSetByte(CM_3E_IVS2DVS_DEALY_LINES_H, 0x00);    
    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[0]);
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, (pData[1] - 1));

    // Apply Double Buffer
    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5);
    
    ScalerTimerWaitForEvent(_EVENT_IVS);    
    
    // Clear Buffer Status
    ScalerSetByte(CM_02_STATUS0, 0x00);

    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);

    return (ScalerGetByte(CM_02_STATUS0) & 0x03);
}
#endif // End of #if(_2D_TO_3D_FUNCTION == _ON)
