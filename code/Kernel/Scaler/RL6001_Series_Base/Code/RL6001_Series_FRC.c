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
// ID Code      : RL6001_Series_FRC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6001_SERIES_FRC__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _SDRAM_ACCESS_WRITE_LENGTH                  (0xA0)
#define _SDRAM_ACCESS_READ_LENGTH                   (0xFC)


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
#if(_FRC_SUPPORT == _ON)
void ScalerFRCCompareIHFandDHF(void);
void ScalerFRCOneFrameCtrl(DWORD ulIHF, DWORD ulDHF);
WORD ScalerFRCSetOneFrameDVTotal(void);
void ScalerFRCControl(WORD usHorSize, WORD usVerSize);
void ScalerFRCInputCtrl(WORD usHorSize, WORD usVerSize);
void ScalerFRCDisplayCtrl(WORD usHorSize, WORD usVerSize);
void ScalerFRCAdjustIVS2DVSDelay(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Compare which one of IHF and DHF is bigger, and see if they are too similar
// Input Value  : Display Clock
// Output Value : None
//--------------------------------------------------
void ScalerFRCCompareIHFandDHF(void)
{
    DWORD ulIHF = 0;
    DWORD ulDHF = 0;

    if(g_stMDomainOutputData.usVHeight > g_stMDomainInputData.usVHeight)
    {
        // IHF'
        ulIHF = (DWORD)g_stMDomainInputData.usHFreq; 
        // DHF'
        ulDHF = ((DWORD)GET_D_CLK_FREQ() / g_stMDomainOutputData.usHTotal * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVHeight * 10); 
    }
    else
    {
        // IHF'
        ulIHF = (DWORD)g_stMDomainInputData.usHFreq * g_stMDomainOutputData.usVHeight / g_stMDomainInputData.usVHeight; 
        // DHF'
        ulDHF = ((DWORD)GET_D_CLK_FREQ() / g_stMDomainOutputData.usHTotal * 10);
    }

    // Set FRC Style
    if(ulIHF > ulDHF)
    {
        // Set input fast than display
        ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT3, _BIT3);
    }
    else
    {
        // Set input slower than display
        ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT3, 0x00);
    }

    // Write in double buffer
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT4, _BIT4); 

    if(GET_MEMORY_SELECT() == _FRAME_SYNC_SDRAM)
    {
        // Set Frame sync when FRC
        ScalerSetBit(CM_28_VDISP_CTRL, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));
    }
    else
    {
        if(g_bDoubleFrame == _TRUE)
        {
            // Set Free Run when FRC
            ScalerSetBit(CM_28_VDISP_CTRL, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));  
        }
        else
        {
            ScalerFRCOneFrameCtrl(ulIHF, ulDHF);
        }
    }
}

//--------------------------------------------------
// Description  : Set OneFrame FRC
// Input Value  : IHF, DHF
// Output Value : None
//--------------------------------------------------
void ScalerFRCOneFrameCtrl(DWORD ulIHF, DWORD ulDHF)
{
    SWORD shMargin = 0;
    WORD usPreRead = 0;
    WORD usLeadingLine = 0;
    bit bAutoMode = 1; // 1:auto mode; 0:manual mode

    if(ulIHF > ulDHF)
    {
        usPreRead = g_stMDomainOutputData.usVStart - 3;
        ulIHF = (g_stMDomainInputData.usHFreq % 10) ? (g_stMDomainInputData.usHFreq / 10 + 1) : (g_stMDomainInputData.usHFreq / 10);
        shMargin = 0x02;
        ulDHF = ulDHF * g_stMDomainInputData.usVHeight / 10;
    }
    else
    {
        // forbidden lines
        usPreRead = ((DWORD)g_stMDomainOutputData.usVHeight * ulDHF / ulIHF - g_stMDomainOutputData.usVHeight); 
        usPreRead = (usPreRead < 10) ? 10 : usPreRead;

        if(g_stMDomainInputData.usVFreq > _PANEL_MAX_FRAME_RATE)
        {
            PDATA_WORD(0) = _PANEL_DV_TOTAL_MIN;
        
            // input frame leading lines in display
            usLeadingLine = (DWORD)(g_stMDomainInputData.usVFreq - _PANEL_MAX_FRAME_RATE) * PDATA_WORD(0) / g_stMDomainInputData.usVFreq; 
        }
        else if(g_stMDomainInputData.usVFreq < _PANEL_MIN_FRAME_RATE)
        {
            PDATA_WORD(0) = _PANEL_DV_TOTAL_MIN;

            // input frame leading lines in display
            usLeadingLine = (DWORD)(_PANEL_MAX_FRAME_RATE - g_stMDomainInputData.usVFreq) * PDATA_WORD(0) / g_stMDomainInputData.usVFreq; 
        }

        if(usPreRead <= g_stMDomainOutputData.usVStart)
        {
            if((usPreRead * 15 / 10) < usLeadingLine)
            {
                if((usPreRead * 15 / 10) > g_stMDomainOutputData.usVStart)
                {
                    usPreRead = 0;
                }
                else
                {
                    usPreRead = g_stMDomainOutputData.usVStart - usPreRead * 15 / 10;
                }
            }
            else if((usPreRead * 13 / 10) < usLeadingLine)
            {
                if((usLeadingLine - 1) > g_stMDomainOutputData.usVStart)
                {
                    usPreRead = 0;
                }
                else
                {
                    usPreRead = g_stMDomainOutputData.usVStart - (usLeadingLine - 1);
                }
            }
            else
            {
                if((usPreRead * 13 / 10) > g_stMDomainOutputData.usVStart)
                {
                    usPreRead = 0;
                }
                else
                {
                    usPreRead = g_stMDomainOutputData.usVStart - usPreRead * 13 / 10;
                }
            }

            ulIHF = (g_stMDomainInputData.usHFreq % 10) ? (g_stMDomainInputData.usHFreq / 10 + 1) : (g_stMDomainInputData.usHFreq / 10);
            shMargin = (SWORD)0 - (g_stMDomainOutputData.usVHeight - 1);
            ulDHF = ulDHF * g_stMDomainInputData.usVHeight / 10;
            bAutoMode = 0;

            ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT3, _BIT3);
        }
        else
        {
            usPreRead = (DWORD)(PDATA_WORD(0) - g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVHeight - 3;
            shMargin = usPreRead > 20 ? usPreRead - 20 : 0;
            usPreRead = g_stMDomainInputData.usVHeight;
            ulIHF = (DWORD)g_stMDomainInputData.usHFreq / 10;

            ulDHF = (ulDHF - g_stMDomainInputData.usHFreq) * g_stMDomainInputData.usVHeight / 10;
        }
    }

    ScalerSetByte(P5_E4_SDRF_MN_ONEF_DHF_H, (ulDHF >> 16) | ((BYTE)bAutoMode << 6) | _BIT7);
    ScalerSetByte(P5_E5_SDRF_MN_ONEF_DHF_M, (BYTE)(ulDHF >> 8));
    ScalerSetByte(P5_E6_SDRF_MN_ONEF_DHF_L, (BYTE)ulDHF);
    ScalerSetByte(P5_E7_SDRF_MN_ONEF_IHF, (BYTE)ulIHF);
    ScalerSetByte(P5_E8_SDRF_MN_LINE_MAGN_L, LOBYTE(shMargin));
    ScalerSetByte(P5_E9_SDRF_MN_ONEF_MAGN_H, (HIBYTE(shMargin) << 4) + HIBYTE(usPreRead));
    ScalerSetByte(P5_EA_SDRF_MN_PRRD_MAGN_L, LOBYTE(usPreRead));

    // Write in double buffer
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~(_BIT4 | _BIT0), _BIT4);

    // Disable Osd Overlay In Case of Garbage
    pData[0] = ScalerGetByte(CM_6C_OVERLAY_CTRL);

    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT0, 0x00);

    // Set Frame sync 
    ScalerSetBit(CM_28_VDISP_CTRL, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // Set Free Run
    ScalerSetBit(CM_28_VDISP_CTRL, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
    ScalerSetBit(CM_6C_OVERLAY_CTRL, ~_BIT0, (pData[0] & _BIT0));    
}

//-------------------------------------------------
// Description  : Calculate DVTotal for OneFrame FRC
// Input Value  : None
// Output Value : usDVTotal
//-------------------------------------------------
WORD ScalerFRCSetOneFrameDVTotal(void)
{
    WORD usIHF = 0;
    WORD usDHF = 0;
    WORD usDVTotal = 0;

    if((DWORD)g_stMDomainOutputData.usVHeight * 1066 / 1000 < _PANEL_DV_TOTAL)
    {
        usDHF = (DWORD)_PANEL_MAX_FRAME_RATE * _PANEL_DV_TOTAL / 1000;
    }
    else
    {
        usDHF = (DWORD)_PANEL_MAX_FRAME_RATE * (DWORD)g_stMDomainOutputData.usVHeight * 1066 / 1000 / 1000;
    }

    usIHF = (DWORD)g_stMDomainInputData.usVFreq * g_stMDomainInputData.usVTotal / 1000;

    // Frame Difference
    PDATA_DWORD(0) = (DWORD)1000 * ((DWORD)1000 * g_stMDomainInputData.usVFreq - (DWORD)1000 * _PANEL_MAX_FRAME_RATE) / ((DWORD)g_stMDomainInputData.usVFreq * _PANEL_MAX_FRAME_RATE);

    // Active Region Difference
    PDATA_DWORD(1) = (DWORD) 1000 * ((DWORD)g_stMDomainOutputData.usVHeight * usIHF - (DWORD)g_stMDomainInputData.usVHeight * usDHF) / ((DWORD)usIHF * usDHF);

    if((PDATA_DWORD(0) * 100 / PDATA_DWORD(1)) < 125)
    {
        usDVTotal = (DWORD)1000 * g_stMDomainOutputData.usVHeight / ((PDATA_DWORD(0) * 100 / 125) + ((DWORD)1000 * g_stMDomainInputData.usVHeight / usIHF)) * 1000 / _PANEL_MAX_FRAME_RATE;
    }
    else if((DWORD)g_stMDomainOutputData.usVHeight * 1066 / 1000 < _PANEL_DV_TOTAL)
    {
        usDVTotal = _PANEL_DV_TOTAL;
    }
    else
    {
        usDVTotal = (DWORD)g_stMDomainOutputData.usVHeight * 1066 / 1000;
    }

    if(usDVTotal > _PANEL_DV_TOTAL_MAX)
    {
        usDVTotal = _PANEL_DV_TOTAL_MAX;
    }
    else if(usDVTotal < _PANEL_DV_TOTAL_MIN)
    {
        usDVTotal = _PANEL_DV_TOTAL_MIN;
    }

    return usDVTotal;
}

//--------------------------------------------------
// Description  : FRC control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFRCControl(WORD usHorSize, WORD usVerSize)
{
    // Set FRC IVS2DVSDelay
    ScalerFRCAdjustIVS2DVSDelay();    
    
    // Enable display timing
    ScalerFRCCompareIHFandDHF();

    // Set up FRC Capture
    ScalerFRCInputCtrl(usHorSize, usVerSize);

    // Set up FRC Display
    ScalerFRCDisplayCtrl(usHorSize, usVerSize);
}

//--------------------------------------------------
// Description  : IN1 FIFO Setting for FRC Mode
// Input Value  : ucHorSize --> Horizontal size
//                ucVerSize --> Vertical Size
// Output Value : None
//--------------------------------------------------
void ScalerFRCInputCtrl(WORD usHorSize, WORD usVerSize)
{
    StructSDRAMLineBlockStep stStep;

    // Frame mode
    // One Frame total pixel for SDRAM (unit : 64 bits)
    PDATA_DWORD(0) = ((DWORD)usHorSize * usVerSize * _BIT_PER_PIXEL % 64) ?
                          (((DWORD)usHorSize * usVerSize * _BIT_PER_PIXEL / 64) + 1) :
                          ((DWORD)usHorSize * usVerSize * _BIT_PER_PIXEL / 64);

    // Set Frame mode
    ScalerSetBit(P5_B7_SDRF_IN1_LINE_NUM_H, ~_BIT4, _BIT4);  

    stStep.ulBlockStep = ScalerSDRAMAddressConversion((PDATA_DWORD(0) * 64 / _MEMORY_BUS_WIDTH));
    PDATA_DWORD(0) = ScalerSDRAMCalculateNumberAndRemain(PDATA_DWORD(0), _SDRAM_ACCESS_WRITE_LENGTH, 1);    

    ScalerSetByte(P5_A8_SDRF_IN1_WATER_LEVEL, _SDRAM_ACCESS_WRITE_LENGTH);
    ScalerSetByte(P5_A9_SDRF_IN1_WR_NUM_H, pData[2]);
    ScalerSetByte(P5_AA_SDRF_IN1_WR_NUM_L, pData[3]);
    ScalerSetByte(P5_AB_SDRF_IN1_WR_LEN, _SDRAM_ACCESS_WRITE_LENGTH);
    ScalerSetByte(P5_AC_SDRF_IN1_WR_REMAIN, pData[1]);
    ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 16));
    ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 8));
    ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 0));
    ScalerSetByte(P5_B0_SDRF_IN1_LINE_STEP_H, HIBYTE(stStep.usLineStep));
    ScalerSetByte(P5_B1_SDRF_IN1_LINE_STEP_L, LOBYTE(stStep.usLineStep));
    ScalerSetByte(P5_B2_SDRF_IN1_BLOCK_STEP_H, HIBYTE((WORD)(stStep.ulBlockStep >> 11) & 0xFFFF));
    ScalerSetByte(P5_B3_SDRF_IN1_BLOCK_STEP_L, LOBYTE((WORD)(stStep.ulBlockStep >> 11) & 0xFFFF));
    ScalerSetByte(P5_B4_SDRF_IN1_BL2_ADDR_H, (BYTE)((DWORD)stStep.ulBlockStep >> 16) & 0xFF);
    ScalerSetByte(P5_B5_SDRF_IN1_BL2_ADDR_M, (BYTE)((DWORD)stStep.ulBlockStep >> 8) & 0xFF);
    ScalerSetByte(P5_B6_SDRF_IN1_BL2_ADDR_L, (BYTE)((DWORD)stStep.ulBlockStep) & 0xFF);

    // Set line number
    ScalerSetBit(P5_B7_SDRF_IN1_LINE_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 |_BIT0), (usVerSize >> 8) & 0x0F);
    ScalerSetByte(P5_B8_SDRF_IN1_LINE_NUM_L, LOBYTE(usVerSize));

    if(g_bDoubleFrame == _TRUE)
    {
        // Double Buffer
        ScalerSetByte(P5_B9_SDRF_IN1_SDR_CTRL, 0xA2);
    }
    else
    {
        // Single Buffer
        ScalerSetByte(P5_B9_SDRF_IN1_SDR_CTRL, 0x82);
    }
}

//--------------------------------------------------
// Description  : MAIN FIFO Setting for FRC Mode
// Input Value  : usHorSize --> Horizontal size
//                usVerSize --> Vertical Size
// Output Value : None
//--------------------------------------------------
void ScalerFRCDisplayCtrl(WORD usHorSize, WORD usVerSize)
{
    StructSDRAMLineBlockStep stStep;

    // Frame mode
    // One Frame total pixel for SDRAM (unit : 64 bits)
    PDATA_DWORD(0) = ((DWORD)usHorSize * usVerSize * _BIT_PER_PIXEL % 64) ?
                          (((DWORD)usHorSize * usVerSize * _BIT_PER_PIXEL / 64) + 1) :
                          ((DWORD)usHorSize * usVerSize * _BIT_PER_PIXEL / 64);

    // Set Frame mode
    ScalerSetBit(P5_CD_SDRF_MN_LINE_NUM_H, ~_BIT4, _BIT4);  

    stStep.ulBlockStep = ScalerSDRAMAddressConversion((PDATA_DWORD(0) * 64 / _MEMORY_BUS_WIDTH));
    PDATA_DWORD(0) = ScalerSDRAMCalculateNumberAndRemain(PDATA_DWORD(0), _SDRAM_ACCESS_READ_LENGTH, 0);    

    pData[4] = (BYTE)(stStep.ulBlockStep & 0xFF);
    stStep.ulBlockStep = ((stStep.ulBlockStep >> 1) & 0xFFFFFF00) | pData[4];

    // BLOCK_STEP
    ScalerSetByte(P5_CB_SDRF_MN_BLOCK_STEP_H, HIBYTE((WORD)(stStep.ulBlockStep >> 10) & 0xFFFF));
    ScalerSetByte(P5_CC_SDRF_MN_BLOCK_STEP_L, LOBYTE((WORD)(stStep.ulBlockStep >> 10) & 0xFFFF));

    ScalerSetByte(P5_BC_SDRF_MN_PRERD_VST_H, HIBYTE(g_stMDomainOutputData.usVStart - 3));
    ScalerSetByte(P5_BD_SDRF_MN_PRERD_VST_L, LOBYTE(g_stMDomainOutputData.usVStart - 3));
    ScalerSetByte(P5_BE_SDRF_MN_PXL_NUM_H, (HIBYTE(usHorSize) & 0x0F));
    ScalerSetByte(P5_BF_SDRF_MN_PXL_NUM_L, LOBYTE(usHorSize));
    ScalerSetByte(P5_C0_SDRF_MN_WTLVL, _SDRAM_ACCESS_READ_LENGTH);
    ScalerSetByte(P5_C2_SDRF_MN_READ_NUM_H, pData[2]);
    ScalerSetByte(P5_C3_SDRF_MN_READ_NUM_L, pData[3]);
    ScalerSetByte(P5_C4_SDRF_MN_READ_LEN, _SDRAM_ACCESS_READ_LENGTH);
    ScalerSetByte(P5_C5_SDRF_MN_READ_REMAIN, pData[1]);
    ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 16));
    ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 8));
    ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 0));
    ScalerSetByte(P5_C9_SDRF_MN_LINE_STEP_H, HIBYTE(stStep.usLineStep));
    ScalerSetByte(P5_CA_SDRF_MN_LINE_STEP_L, LOBYTE(stStep.usLineStep));

    // Set line number
    ScalerSetBit(P5_CD_SDRF_MN_LINE_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 |_BIT0), (usVerSize >> 8) & 0x0F);
    ScalerSetByte(P5_CE_SDRF_MN_LINE_NUM_L, LOBYTE(usVerSize));
    
    // Set input format 24 bit
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT7, 0x00);    
    
    if(g_bDoubleFrame == _TRUE)
    {
        // Set Double buffer
        ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT6 | _BIT5 | _BIT4), _BIT6);    
    }
    else
    {
        // Single Buffer
        ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT6 | _BIT5 | _BIT4), 0x00);          
    }

    // Use information from Capture
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT2 | _BIT1), 0x00);       

    // Enable Display double buffer
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT4, _BIT4);

    // Wait double buffer
    ScalerTimerPollingFlagProc(_SDRAM_DISPLAY_SETTING_READY_TIME, P5_D0_SDRF_MN_SDR_STATUS, _BIT4, 0);
}

//--------------------------------------------------
// Description  : Adjust IVS2DVS Delay for Aspect Ratio Function
// Input Value  : ulFreq --> DCLK
// Output Value : IVS2DVS Delay Lines
//--------------------------------------------------
void ScalerFRCAdjustIVS2DVSDelay(void)
{
    // DHFreq
    PDATA_WORD(0) = ((DWORD)GET_D_CLK_FREQ() / g_stMDomainOutputData.usHTotal * 10); 

    PDATA_WORD(0) = (DWORD)(g_stMDomainInputData.usVTotal + g_stMDomainInputData.usVStart + g_stMDomainInputData.usVHeight) - (DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usHFreq / PDATA_WORD(0);

    // Set IVSToDVSDealy
    ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~_BIT1, 0x00);

    if(PDATA_WORD(0) > 255)
    {
        ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, (0xFE - 32));
    }
    else
    {
        ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, (PDATA_WORD(0) - 32));
    }
    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, 0x00);
}

#endif // End of #if(_FRC_SUPPORT == _ON)

