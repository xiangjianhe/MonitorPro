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
// ID Code      : RL6316_Series_Memory.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6316_SERIES_MEMORY__

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
    // Disable Coefficient Access & set H/V Scale Up to use coefficient table 1
    ScalerSetBit(CM_35_FILTER_CTRL, ~_BIT7, 0x00);
    // H 128tap,table0;  V 96taps,table 1.  bit5,bit4 reserved.
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
        // Disable I domain share display line buffer & MAC when vertical scale down
        ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, 0x00);
    }    
    else
    {
        // Enable Full Line Buffer
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT4, _BIT4);

        // Disable Series Four Line Buffer
        ScalerSetDataPortBit(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_00_DISP_DH_TOTAL_H, ~_BIT7, 0x00);                  
        
        if(GET_V_SCALE_DOWN() == _TRUE)
        {
            // Enable I domain share display line buffer & MAC when vertical scale down
            ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);
        }
        else
        {
            // Disable I domain share display line buffer & MAC when vertical scale down
            ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, 0x00);
        }
    }
}

//--------------------------------------------------
// Description  : Set FIFO Clock
// Input Value  : Target FIFO Clock
// Output Value : None
//--------------------------------------------------
void ScalerMemorySetFIFOFreq(EnumScalerFIFOFreq enFIFOFreq)
{
    switch(enFIFOFreq)
    {
        case _SCALER_FIFO_FREQ_M2PLL:
            ScalerSetBit(CM_22_FIFO_FREQUENCY, ~(_BIT1 | _BIT0), 0x00);
            break;

        case _SCALER_FIFO_FREQ_MPLL: // 6316 do not have MPLL
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
    
    ScalerGetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 1, &ucTemp[2], _NON_AUTOINC);

    // All Calculation is Based on a 128 Multiplier
    // Calculate VFCI
    ((WORD *)ucTemp)[1] = ((WORD)ucTemp[2] << 8) / 256 / 2;

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
    
    DebugMessageFS("Calculated Max", ucMax);
    DebugMessageFS("Calculated Min", ucMin);    

    // Get FIFO Input Width
    ScalerGetDataPortByte(CM_30_FIFO_ACCESS_PORT, _CM_31_PT_00_FIFO_DRL_H_BSU, 2, ucTemp, _AUTOINC);    
    ucTemp[0] = (ucTemp[0] >> 4) & 0x0F;      

    ((WORD *)ucTemp)[1] = (((WORD *)ucTemp)[1] * 100) >> 7;
        
    // Target Dt = 2 - (Max + Min) / 2 + VFCI + FIFODepth/2FIFOHWidth - VSF * (DHactiveEnd + DHstart)/2DHtotal
    ((WORD *)ucTemp)[0] = 200 - ((WORD)(ucMax + ucMin) * 100 >> 8) + ((WORD *)ucTemp)[1] + (DWORD)_FIFO_SIZE * 50 / ((WORD *)ucTemp)[0] - (DWORD)g_stMDomainInputData.usVHeight * (2 * g_stMDomainOutputData.usHStart + g_stMDomainOutputData.usHWidth) / g_stMDomainOutputData.usVHeight * 50 / g_stMDomainOutputData.usHTotal;

    DebugMessageFS("2. Target Dt Value", ((WORD *)ucTemp)[0]);
    
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
    
    // Compensate Dt = Original Dt + ((Target Last Line - Current Last Line) * DVHeight / DVTotal * IVHeight / DVHeight * IHTotal / DHTotal) / 2
    PDATA_DWORD(0) = (SDWORD)PDATA_DWORD(0) + ((((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine) * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVTotal * g_stMDomainInputData.usHTotal / g_stMDomainOutputData.usHTotal) >> 1);

    DebugMessageFS("Last Line Difference", ((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine));
    DebugMessageFS("Dt Compensate Value", (((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine) * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVTotal * g_stMDomainInputData.usHTotal / g_stMDomainOutputData.usHTotal) >> 1);
    
    DebugMessageFS("Compensated Dt", PDATA_DWORD(0));    
    
    pData[0] = (BYTE)((PDATA_DWORD(0) - (g_stMDomainInputData.usHTotal >> 1) - 64) / g_stMDomainInputData.usHTotal);
    pData[1] = (PDATA_DWORD(0) - ((DWORD)g_stMDomainInputData.usHTotal * pData[0]) + 8) >> 4;    
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
        if(GET_V_SCALE_DOWN() == _TRUE)    // Vertical Scaling Down
        {
            PDATA_DWORD(1) += (g_stMDomainInputData.usHTotal >> 1) + ((DWORD)g_stMDomainInputData.usHTotal * g_stMDomainInputData.usVHeight / (g_stMDomainOutputData.usVHeight * 2));
        }
        else    // Vertical Scaling Bypass
        {
            PDATA_DWORD(1) += (g_stMDomainInputData.usHTotal >> 1) + g_stMDomainInputData.usHTotal / 2 ;            
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

        // Modify DVSt
        g_stMDomainOutputData.usVStart += pData[5];

        // Modify IVS2DVS Delay
        PDATA_DWORD(0) -= (DWORD)pData[5] * g_stMDomainInputData.usHTotal * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVHeight;    
    }

    if(GET_INTERLACED_MODE() == _TRUE)
    {
        // Disable Video Compensation when VGA Input
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT7, 0x00);

        // Disable Frame Sync Fine Tune
        ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~_BIT1, 0x00);
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
        pData[5] = (PDATA_DWORD(0) - (g_stMDomainInputData.usHTotal >> 1) - 64) / g_stMDomainInputData.usHTotal;
        pData[6] = (PDATA_DWORD(0) - ((DWORD)g_stMDomainInputData.usHTotal * pData[5]) + 8) >> 4;

        ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[5]);
        ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, (pData[6] - 1));

        pData[6] = pData[6] - ((g_stMDomainInputData.usHTotal + 16) >> 5);

        // Aviod setting CR42 by negative value cause frame sync error
        pData[6] = (pData[6] == 0 ? 1 : pData[6]);
        ScalerSetByte(CM_42_IV_DV_DELAY_CLK_EVEN, (pData[6] - 1));
    }
    else
    {
        pData[5] = (PDATA_DWORD(0) / g_stMDomainInputData.usHTotal);
        pData[6] = (PDATA_DWORD(0) - ((DWORD)g_stMDomainInputData.usHTotal * pData[5]) + 8) >> 4;

        // Aviod setting CR41 by negative value cause frame sync error
        pData[6] = (pData[6] == 0 ? 1 : pData[6]);
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
}
