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

#define __RL6001_SERIES_SDRAM__

#include "ScalerFunctionInclude.h"


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
// Definitions of SDRAM spread spectrum range
#define _MCLK_SPREAD_SPECTRUM_RANGE             (3)

// Definitions of SDRAM Latency
#define _ROW_RD_DELAY                           (3)  // 0~2:Reserved, 3~5:3~5 MCLK, 6~7:Reserved
#define _ROW_WR_DELAY                           (2)  // 0~1:Reserved, 2~5:2~5 MCLK, 6~7:Reserved
#define _SDR_ROW_DELAY                          ((_ROW_RD_DELAY << 3) | (_ROW_WR_DELAY))
#define _SDR_COL_DELAY                          ((3 << 5) | 0x04) // 0~1:Reserved, 2~3:2~3 MCLK, 4~7:Reserved

// Definitions of MPLL N Code
#define _MPLL_N_CODE                            (2)

//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerSDRAMInitialTable(void);
#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
void ScalerSDRAMPowerControl(bit bOn);
void ScalerSDRAMInitial(void);
void ScalerSDRAMSetMPLLOffset(WORD usMclkOffset);
void ScalerSDRAMSetMPLLFreq(DWORD ulFreq);
void ScalerSDRAMReset(void);
void ScalerSDRAMDelay200Us(void);

#if(_FRC_SUPPORT == _ON)
DWORD ScalerSDRAMAddressConversion(DWORD ulTotalSize);
#endif

#if((_FRC_SUPPORT == _ON) || (_OD_SUPPORT == _ON))
DWORD ScalerSDRAMCalculateNumberAndRemain(DWORD ulTotalSize, BYTE ucLength, bit bDummy);
#endif

#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
void ScalerSDRAMInitialTable(void)
{
    // SDRAM Control Power Up Initial
    ScalerSetByte(P5_B7_SDRF_IN1_LINE_NUM_H, 0x40);
    ScalerSetByte(P5_BC_SDRF_MN_PRERD_VST_H, 0x00);
    ScalerSetByte(P5_BD_SDRF_MN_PRERD_VST_L, 0x02);    
    ScalerSetByte(P5_CD_SDRF_MN_LINE_NUM_H, 0x00);
    ScalerSetByte(P5_B9_SDRF_IN1_SDR_CTRL, 0x82);
    ScalerSetByte(P5_CF_SDRF_MN_DISP_CTRL, 0x05);
    ScalerSetByte(P5_E4_SDRF_MN_ONEF_DHF_H, 0x00); 
    ScalerSetByte(P5_D0_SDRF_MN_SDR_STATUS, 0x10);

    // Wait double buffer
    ScalerTimerPollingFlagProc(_SDRAM_DISPLAY_SETTING_READY_TIME, P5_D0_SDRF_MN_SDR_STATUS, _BIT4, 0);    
}

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
//--------------------------------------------------
// Description  : SDRAM Power On/Off
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSDRAMPowerControl(bit bOn)
{
    if(bOn == _ON)
    {
        // Set MPLL CLK
        ScalerSDRAMSetMPLLFreq((DWORD)_MEMORY_SPEED * 1000);

        // Precharge Power Down inactive
        ScalerSetBit(P4_B7_SDR_POWER_CTRL0, ~_BIT7, 0x00); 

        // Pin share SDRAM
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
        ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)
        ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
#endif

        // Set SDRAM control register
        ScalerSDRAMInitial();

        // Reset SDRAM
        ScalerSDRAMReset();
    }
    else
    {
#if(_SDRAM_SIZE_CONFIG == _1M_32BIT)
        // Enable OD memory access to ensure that SDRAM enters power down correctly.
        ScalerSetBit(P3_A2_LS_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
        ScalerSetBit(P3_A1_LS_CTRL0, ~_BIT6, _BIT6);
        
        // Wait 2 DVS for Double Buffer Apply
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
#endif

        ScalerADCBandgap(_ON);
   
        // Set MPLL CLK
        ScalerSDRAMSetMPLLFreq((DWORD)_MEMORY_SPEED * 1000);
                
        // Pin share MCM SDRAM
        ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~_BIT2, _BIT2); 

        // Deep Power Down for 1M32
#if(_SDRAM_SIZE_CONFIG == _1M_32BIT)
        ScalerSetBit(P4_B7_SDR_POWER_CTRL0, ~(_BIT5 | _BIT4), _BIT5);
#endif

        // Precharge Power Down
        ScalerSetBit(P4_B7_SDR_POWER_CTRL0, ~_BIT7, _BIT7);

        // Pin share no SDRAM
        ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~_BIT2, 0x00);

        // Power off MPLL
        ScalerSetBit(P0_F8_MPLL_WD, ~_BIT0, _BIT0);
    }
}

//--------------------------------------------------
// Description  : SDRAM initial
// Input Value  : NONE
// Output Value : NONE
//--------------------------------------------------
void ScalerSDRAMInitial(void)
{
    //===================
    // Set SDRAM Size
    //===================
    ScalerSetByte(P4_A1_SDR_CTRL0, _SDR_ROW_DELAY);
    ScalerSetByte(P4_A2_SDR_CTRL1, _SDR_COL_DELAY);
    ScalerSetByte(P4_A3_SDR_AREF_TIME, 0x0D);
    ScalerSetByte(P4_A4_SDR_PRCG, 0x83);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x23);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x63);
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x83);
#endif

    ScalerSetByte(P4_A6_SDR_SLEW_RATE, 0x00);	

    //===================
    // Set SDRAM Token ring
    //===================
    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0xC0);
    ScalerSetByte(P4_AA_SDR_RSC_AREF, 0x11);
    ScalerSetByte(P4_AB_SDR_RSC_MCU, 0x22);

#if((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _OFF))
    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x00);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x00);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x44);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x88);
#elif((_OD_SUPPORT == _OFF) && (_FRC_SUPPORT == _ON))
    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x44);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x88);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x00);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);
#elif((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _ON))
    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x40);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x80);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x04);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x08);
#endif

    //===================
    // Set MCLK phase
    //===================
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x00);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
     ScalerSetByte(P4_C1_SDR_CLK_DLY2, 0x14);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, 0x14);
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, 0x00);
#endif
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetByte(P4_C3_DQS0_DLY2, 0x2C);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)

#if(_SDRAM_1M32_NEW_VENDOR_SUPPORT == _ON)
    ScalerSetByte(P4_C3_DQS0_DLY2, 0x26);
#else
    ScalerSetByte(P4_C3_DQS0_DLY2, 0x34);
#endif

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    ScalerSetByte(P4_C3_DQS0_DLY2, 0x2D);
#endif

    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetByte(P4_C5_DQS1_DLY2, 0x2C);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)

#if(_SDRAM_1M32_NEW_VENDOR_SUPPORT == _ON)
    ScalerSetByte(P4_C5_DQS1_DLY2, 0x26);
#else
    ScalerSetByte(P4_C5_DQS1_DLY2, 0x34);
#endif

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    ScalerSetByte(P4_C5_DQS1_DLY2, 0x2D);
#endif

    ScalerSetByte(P4_C6_DQS2_DLY1, 0x00);
    ScalerSetByte(P4_C7_DQS2_DLY2, 0x00);	
    ScalerSetByte(P4_C8_DQS3_DLY1, 0x00);	
    ScalerSetByte(P4_C9_DQS3_DLY2, 0x00);	

    //===================
    // Set MCLK spread spectrum function
    //===================
    ScalerSetByte(P0_FC_MCLK_SPREAD_SPECTRUM, (_MCLK_SPREAD_SPECTRUM_RANGE << 4) | 0x05);
}

//--------------------------------------------------
// Description  : Adjust Mclk offset
// Input Value  : Dclk offset
// Output Value : None
//--------------------------------------------------
void ScalerSDRAMSetMPLLOffset(WORD usMclkOffset)
{
    ScalerSetBit(P0_FA_MCLK_FINE_TUNE_OFFSET_MSB, 0xf0, HIBYTE(usMclkOffset) & 0x0f);
    ScalerSetByte(P0_FB_MCLK_FINE_TUNE_OFFSET_LSB, LOBYTE(usMclkOffset));
    ScalerSetBit(P0_FC_MCLK_SPREAD_SPECTRUM, ~(_BIT2 | _BIT0), _BIT2 | _BIT0);
}

//--------------------------------------------------
// Description  : Set display clock (Dclk)/memory clock(Mclk) frequency in kHz
// Input Value  : ulFreq    --> Target Dclk/Mclk frequency
// Output Value : None
//--------------------------------------------------
void ScalerSDRAMSetMPLLFreq(DWORD ulFreq)
{
    WORD usMcode = 0;
    BYTE ucDiv = 0;
    BYTE ucCount = 0x80;

    // Disable DDS spread spectrum output function
    ScalerSetBit(P0_FC_MCLK_SPREAD_SPECTRUM, ~_BIT0, 0x00);

    usMcode = ulFreq * 8 * _MPLL_N_CODE * 16 / ((DWORD)_EXT_XTAL * 15);

    if((ulFreq / 1000) < 67)
    {
        ucDiv = 4;
        usMcode = usMcode;
    }
    else if((ulFreq / 1000) < 135)
    {
        ucDiv = 2;
        usMcode = (usMcode + 1) >> 1;
    }
    else
    {
        ucDiv = 1; // Output DPLL/2 for DCLK
        usMcode = (usMcode + 2) >> 2; // Round to integer        
    }
    // Set M Code
    ScalerSetByte(P0_F5_MPLL_M, (usMcode - 2));

    // Set N Code
    switch(ucDiv)
    {
        case 1:
            pData[0] = 0x00;
            break;

        case 2:
            pData[0] = 0x10;
            break;

        case 4:
            pData[0] = 0x20;
            break;

        case 8:
            pData[0] = 0x30;
            break;

        default:
            break;
    }

    pData[0] |= (_MPLL_N_CODE - 2);
    ScalerSetByte(P0_F6_MPLL_N, pData[0]);

    // New Formula : Icp * N_Code / M_Code = 0.5 * Fxtal / 27MHz (for xtal not 27MHz)
    // Icp     = M_Code / N_Code * 0.5 * Fxtal / 27MHz
    // Original Formula : M_Code/Ich = 10.67 must be constant
    // Icp     = M_Code * 100 / 1067
    // Icp     = 2.5u + DPLL_IP[0]*2.5u + DPLL_IP[1]*5u + DPLL_IP[2]*10u (A)
    pData[0] = ((DWORD)usMcode / _MPLL_N_CODE * 2 * _EXT_XTAL / _XTAL27000K);

    pData[1] = 0x00;

    if(pData[0] >= 10)
    {
        pData[0] -= 10;
    }

    if(pData[0] >= 40) // 2bit fractional part
    {
        pData[0] -= 40;
        pData[1] |= 0x04;
    }

    if(pData[0] >= 20) // 2bit fractional part
    {
        pData[0] -= 20;
        pData[1] |= 0x02;
    }

    if(pData[0] >= 10) // 2bit fractional part
    {
        pData[0] -= 10;
        pData[1] |= 0x01;
    }

    // Set Current Control
    ScalerSetByte(P0_F7_MPLL_CRNT, (0x70 | pData[1]));

    // Power up MPLL
    ScalerSetByte(P0_F8_MPLL_WD, 0x18);

    //  For low temp power on
    while((bit)ScalerGetBit(P0_F8_MPLL_WD, _BIT0) && (ucCount > 0))
    {
        ScalerSetBit(P0_F8_MPLL_WD, ~_BIT2, _BIT2);
        ScalerTimerDelayXms(2);
        ScalerSetBit(P0_F8_MPLL_WD, ~_BIT2, 0x00);
        ucCount --;
    }

    // Calibration Setting
    ScalerSetBit(P0_F9_MPLL_CAL, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT2), _BIT7);  // Set VCO DEFAULT MODE
    ScalerTimerDelayXms(1);
    ScalerSetBit(P0_F9_MPLL_CAL, ~_BIT2, _BIT2); // Reg MPLL_CMPEN
    ScalerTimerDelayXms(1);
    ScalerSetBit(P0_F9_MPLL_CAL, ~_BIT3, _BIT3); // Reg MPLL_CALLCH
    ScalerTimerDelayXms(1);
    ScalerSetBit(P0_F9_MPLL_CAL, ~_BIT4, _BIT4); // Reg MPLL_CALSW

    // Calculate MPLL Output Freq. According to current Settings
    ((DWORD *)pData)[0] = (DWORD)_EXT_XTAL * 1000 / (ucDiv * 2) * usMcode / _MPLL_N_CODE;
    // Offset resolution (Dclk / 2^15) in Hz
    ((DWORD *)pData)[1] = ((DWORD *)pData)[0] >> 15;

    // Target frequency of Dclk in Hz
    usMcode = (((DWORD *)pData)[0] - (ulFreq * 1000)) / ((DWORD *)pData)[1];
    usMcode = usMcode & 0x0FFF;

    // Set Mpll Offset
    ScalerSDRAMSetMPLLOffset(usMcode);

    // Enable DDS Spread Spectrum Output
    ScalerSetBit(P0_FC_MCLK_SPREAD_SPECTRUM, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : SDRAM reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSDRAMReset(void)
{
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, _BIT4);
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, 0x00);
    ScalerSDRAMDelay200Us();
    ScalerSetBit(P4_A6_SDR_SLEW_RATE, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : SDRAM Test Delay 200us
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMDelay200Us(void)
{
    BYTE ucCnt = 0;

    for(ucCnt = 0; ucCnt < 10; ucCnt++)
    {
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
    }
}

#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Transfer the Memory Size to Address
// Input Value  : ulTotalSize --> Total Memory size
// Output Value : Line Step Address or Block Step Address
//--------------------------------------------------
DWORD ScalerSDRAMAddressConversion(DWORD ulTotalSize)
{
#if(_SDRAM_SIZE_CONFIG >= _2M_32BIT)
    ulTotalSize = (((ulTotalSize & 0xFFFF00) << 1) | LOBYTE(ulTotalSize));
#else
    ulTotalSize = (((ulTotalSize & 0x000100) << 1) | ((ulTotalSize & 0xFFFE00) << 2) | LOBYTE(ulTotalSize));
#endif

	if((ulTotalSize & 0x7FF) > 0)
	{
		ulTotalSize = (((ulTotalSize >> 11) + 1) << 11) & 0xFFFFF800;
	}
	
	return ulTotalSize;	
}

#endif // End of #if(_FRC_SUPPORT == _ON)

#if((_FRC_SUPPORT == _ON) || (_OD_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Calculate the number and remain
// Input Value  : ulTotalSize --> Image total size
//                ucLength --> Length of SDRAM access
// Output Value : Number and Remain
//--------------------------------------------------
DWORD ScalerSDRAMCalculateNumberAndRemain(DWORD ulTotalSize, BYTE ucLength, bit bDummy)
{
    if(bDummy)
    {
        if (ulTotalSize & 0x03)
        {
            (ulTotalSize += 4 - (ulTotalSize & 0x03));
        }
    }

    if((ulTotalSize % ucLength) != 0)
    {
        PDATA_WORD(0) = ulTotalSize / ucLength;
        pData[2] = ulTotalSize % ucLength;
    }
    else
    {
        ulTotalSize = ulTotalSize - ucLength;
        PDATA_WORD(0) = ulTotalSize / ucLength;
        pData[2] = ucLength;
    }

    return (((DWORD)pData[2] << 16) | PDATA_WORD(0));
}

#endif // End of #if((_FRC_SUPPORT == _ON) || #if(_OD_SUPPORT == _ON))

#endif //___#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)

