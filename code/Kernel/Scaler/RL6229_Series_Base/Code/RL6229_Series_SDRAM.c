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

#define __RL6229_SERIES_SDRAM__

#include "ScalerFunctionInclude.h"


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
// Definitions of SDRAM spread spectrum range
#define _MCLK_SPREAD_SPECTRUM_RANGE                 (0) // Disable MCLK spread specturm

// Definitions of SDRAM Latency
#define _ROW_RD_DELAY                               (3)  // 0~2:Reserved, 3~5:3~5 MCLK, 6~7:Reserved
#define _ROW_WR_DELAY                               (3)  // 0~1:Reserved, 2~5:2~5 MCLK, 6~7:Reserved
#define _SDR_ROW_DELAY                              ((_ROW_RD_DELAY << 3) | (_ROW_WR_DELAY))
#define _SDR_COL_DELAY                              ((3 << 5) | 0x04) // 0~1:Reserved, 2~3:2~3 MCLK, 4~7:Reserved

// Definitions of MPLL N Code
#define _MPLL_N_CODE                                (2)

#if(_SDRAM_PHASE_CALIBRATION == _ON)

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
#define _TEST_DATA_MAX                              (16)
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
#define _TEST_DATA_MAX                              (32) 
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
#define _TEST_DATA_MAX                              (32)
#endif

#define _DEFAULT_CONFLICT_AREA                      (10)

#endif

//****************************************************************************
// CODE TABLES
//****************************************************************************

#if(_SDRAM_PHASE_CALIBRATION == _ON)
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

BYTE code tSDRAM_PATTERN[16] = {0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc};

#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)

BYTE code tSDRAM_PATTERN[32] = {0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc,
                                0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc};

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

BYTE code tSDRAM_PATTERN[32] = {0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc,
                               0x33, 0x33, 0x33, 0x33, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc, 0xcc, 0xcc};
#endif
#endif

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_SDRAM_PHASE_CALIBRATION == _ON)
BYTE g_ucSdrCasLatn = _SDR_CAS_LATN;                      // 0xA5
BYTE g_ucSdrClkDly1 = _SDR_CLK_DLY1;                      // 0xC0
BYTE g_ucSdrClkDly2 = _SDR_CLK_DLY2;                      // 0xC1
BYTE g_ucDqsFineDly = _SDR_DQS_DLY;                       // 0xC3
BYTE g_ucPhaseCycle = 0;
BYTE g_ucPhaseCntCheck = 0;
BYTE g_ucPhaseCntRef = 0;
BYTE g_ucConflictArea = _DEFAULT_CONFLICT_AREA;
StructSDRAMCalControl g_stSDRAMCtrl = {0};
#endif

#if((_SDRAM_PHASE_CALIBRATION == _ON) || (_OD_SUPPORT == _ON))
DWORD g_ulSdrThreeBlockAddr1 = 0x00;

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
// For FRC HW auto block toggle in 24Hz
DWORD g_ulSdrThreeBlockAddr2 = 0x00;
DWORD g_ulSdrThreeBlockAddr3 = 0x00;
#endif
#endif

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

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
#if((_OD_SUPPORT == _ON) || (_SDRAM_PHASE_CALIBRATION == _ON))
void ScalerSDRAMCalculateODThreeBlockAddress(DWORD ulBlockStep);
void ScalerSDRAMSetODThreeBlockAddress(void);
#endif

DWORD ScalerSDRAMAddressConversion(DWORD ulTotalSize);
StructSDRAMLineBlockStep ScalerSDRAMCalculateLineStepAndBlockStep(WORD usHorSize, WORD usVerSize);
void ScalerSDRAMSetFrameTrackingEnable(bit bEn);
void ScalerSDRAMFrameTracking(void);
void ScalerSDRAMSetDisplayAutoBlkToggleEnable(bit bEn);
void ScalerSDRAMSetHWAutoBlockToggle(void);
WORD ScalerSDRAMGetMNRatio(void);
#endif

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON) || (_OD_SUPPORT == _ON))
DWORD ScalerSDRAMCalculateNumberAndRemain(DWORD ulTotalSize, BYTE ucLength, bit bDummy);
#endif

#if(_3D_SUPPORT == _ON)
WORD ScalerSDRAMCalculateLineSizeAlignToRow(WORD usHWidth, bit bUpBound);
#endif

#endif

#if(_SDRAM_PHASE_CALIBRATION == _ON)
#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
DWORD ScalerSDRAMSelectThreeBlock(void);
#endif

void ScalerSDRAMPhaseCntCheck(BYTE ucCheckTime); 
void ScalerSDRAMClearFifo(void);
void ScalerSDRAMTokenPhaseSet(void);
void ScalerSDRAMWritePattern(void);
void ScalerSDRAMMpllSet(BYTE ucMCLK);
void ScalerSDRAMDefaultTokenRing(void);
void ScalerSDRAMDefaultPhase(void);
BYTE ScalerSDRAMPhaseCount(bit bDBBufferFlag);
bit ScalerSDRAMMCUMode(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL, bit bWriteMcuFlag);
bit ScalerSDRAMOnlineMCUMode(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL);
DWORD ScalerSDRAMWritePhaseSearch(void);
void ScalerSDRAMWrPatternOnce(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL);
void ScalerSDRAMReadPhaseSearch(BYTE ucHighDutyWidth, BYTE ucMclkCyle, BYTE ucWriteMove);
bit ScalerSDRAM1NsCheck(void);
void ScalerSDRAMPhaseSearch(void);
bit ScalerSDRAMPhaseOnLine(DWORD ulAddress);
void ScalerSDRAMUpdateCAS(bit bChangeCasFlag);
bit ScalerSDRAMPhaseDCOnCheck(DWORD ulAddress);
#endif // End of #if(_SDRAM_PHASE_CALIBRATION == _ON)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
void ScalerSDRAMInitialTable(void)
{
    // SDRAM Control Initial
    ScalerSetByte(P5_B7_SDRF_IN1_LINE_NUM_H, 0x40);
    ScalerSetByte(P5_BC_SDRF_MN_PRERD_VST_H, 0x00);
    ScalerSetByte(P5_BD_SDRF_MN_PRERD_VST_L, 0x02);
    ScalerSetByte(P5_CD_SDRF_MN_LINE_NUM_H, 0x00);
    ScalerSetByte(P5_B9_SDRF_IN1_SDR_CTRL, 0x82);
    ScalerSetByte(P5_CF_SDRF_MN_DISP_CTRL, 0x05);
    ScalerSetByte(P5_E4_SDRF_MN_ONEF_DHF_H, 0x00); 
    ScalerSetByte(P5_D0_SDRF_MN_SDR_STATUS, 0x10);    

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))
    Scaler3DSetDisplayLRFlagEnable(_DISABLE);
#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)

    // Disable M:N frame tracking
    ScalerSDRAMSetFrameTrackingEnable(_DISABLE);

    // Disable HW auto block toggle
    ScalerSDRAMSetDisplayAutoBlkToggleEnable(_DISABLE);
#else
    // Wait double buffer
    ScalerTimerPollingFlagProc(_SDRAM_DISPLAY_SETTING_READY_TIME, P5_D0_SDRF_MN_SDR_STATUS, _BIT4, 0);
#endif  // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))  

#if(_SDRAM_PHASE_CALIBRATION == _ON)
    g_ulSdrThreeBlockAddr1 = _SDRAM_PHASE_ON_LINE_ADDRESS; 
#endif
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
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
        ScalerSetBit(P10_C0_PIN_SHARE_SDRAM_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
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

        // Deep Power Down for 2M32
#if((_SDRAM_SIZE_CONFIG == _2M_32BIT) || (_SDRAM_SIZE_CONFIG == _1M_32BIT))
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

#if(_SDRAM_PHASE_CALIBRATION == _ON)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, g_ucSdrCasLatn);
#else     
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);    
#endif

    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x0C);
    
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 

#if(_SDRAM_PHASE_CALIBRATION == _ON)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, g_ucSdrCasLatn);
#else     
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);    
#endif

    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x06); 
    
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION == _ON)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, g_ucSdrCasLatn);
#else     
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);    
#endif

    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x0D);

#endif
    
    ScalerSetByte(P4_A6_SDR_SLEW_RATE, 0x00);    

    //===================
    // Set SDRAM Token ring
    //===================
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

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetByte(P4_BD_SDR_MCU_RD_LEN, 0x04);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
    ScalerSetByte(P4_BD_SDR_MCU_RD_LEN, 0x02);
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    ScalerSetByte(P4_BD_SDR_MCU_RD_LEN, 0x02);
#else
    #warning "You must set value there."
#endif

    //===================
    // Set MCLK phase
    //===================    

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

#if(_SDRAM_PHASE_CALIBRATION == _ON)
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, g_ucSdrClkDly1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, g_ucSdrClkDly2);
    ScalerSetByte(P4_C3_DQS0_DLY2, g_ucDqsFineDly);

#else
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);

#endif

#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 

#if(_SDRAM_PHASE_CALIBRATION == _ON) 
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, g_ucSdrClkDly1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, g_ucSdrClkDly2);
    ScalerSetByte(P4_C3_DQS0_DLY2, g_ucDqsFineDly);
    ScalerSetByte(P4_C5_DQS1_DLY2, g_ucDqsFineDly); 
#else
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);
    ScalerSetByte(P4_C5_DQS1_DLY2, _SDR_DQS_DLY); 
#endif


#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

#if(_SDRAM_PHASE_CALIBRATION == _ON)
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, g_ucSdrClkDly1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, g_ucSdrClkDly2);
    ScalerSetByte(P4_C3_DQS0_DLY2, g_ucDqsFineDly);
    ScalerSetByte(P4_C5_DQS1_DLY2, g_ucDqsFineDly);

#else
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);
    ScalerSetByte(P4_C5_DQS1_DLY2, _SDR_DQS_DLY);

#endif

#endif

    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
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
    BYTE pData[8];
    
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

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
#if((_OD_SUPPORT == _ON) || (_SDRAM_PHASE_CALIBRATION == _ON))
//--------------------------------------------------
// Description  : Set OD address of 3 block toggle 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSDRAMCalculateODThreeBlockAddress(DWORD ulBlockStep)
{
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    // Avoid OD data overlap R image before R output in LR display.
    if((GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR) &&
       ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)))
    {
        pData[0] = (WORD)_3_BLOCK_OD_MARGIN * _BIT_PER_PIXEL / _MEMORY_BUS_WIDTH;
        
        ulBlockStep -= (pData[0] << 1);         
    }
#endif
    
    //=========================================
    // Set OD 1st Address
    //=========================================
    // Get 3rd Write Address
    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT3);
    pData[0] = ScalerGetByte(P5_AD_SDRF_IN1_MEM_ADDR_H);
    pData[1] = ScalerGetByte(P5_AE_SDRF_IN1_MEM_ADDR_M);
    pData[2] = ScalerGetByte(P5_AF_SDRF_IN1_MEM_ADDR_L);
 
#if((_FRC_SUPPORT == _ON) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)))
    // FRC On + 3D PR Case
    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || 
       (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) ||
       ((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)) ||
       ((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))))
#elif((_FRC_SUPPORT == _OFF) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)))
    // FRC Off + 3D PR Case
    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || 
       (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) ||
       ((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)))
#elif((_FRC_SUPPORT == _ON) && (_3D_SUPPORT == _OFF))
    // FRC On + 3D Off Case : 24->60Hz / 24->72Hz uses HW auto 3 block toggle
    if((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))
#else
    // FRC On + 3D shutter case
    // FRC Off + 3D Shutter case
    if((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF)))
#endif    
    {
        // Set OD address = 3D 1st Read Address + Blockstep
        g_ulSdrThreeBlockAddr1 = ((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | pData[2]) >> 1) + ulBlockStep;
    }
    else
    {
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
        // Avoid OD size > R image size
        if((GET_ASPECT_ORIGIN_MODE() == _TRUE) && (g_stMDomainOutputData.usVHeight < _PANEL_DV_HEIGHT))
        {
            // Set OD address = 3D 1st Read Address + Blockstep
            g_ulSdrThreeBlockAddr1 = ((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | pData[2]) >> 1) + ulBlockStep;
        }
        else
#endif // End of #if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)  
        {
            // Set OD address = 3D 1st Read Address + 1 / 2 * BlockStep
            g_ulSdrThreeBlockAddr1 = ((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | pData[2]) >> 1) + (ulBlockStep >> 1);
        }
    }

    //=========================================
    // Set OD 2nd Address
    //=========================================
    // Get lst Write Address
    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
    pData[0] = ScalerGetByte(P5_AD_SDRF_IN1_MEM_ADDR_H);
    pData[1] = ScalerGetByte(P5_AE_SDRF_IN1_MEM_ADDR_M);
    pData[2] = ScalerGetByte(P5_AF_SDRF_IN1_MEM_ADDR_L);    

#if((_FRC_SUPPORT == _ON) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)))
    // FRC On + 3D PR Case
    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || 
       (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) ||
       ((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)) ||
       ((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))))
#elif((_FRC_SUPPORT == _OFF) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)))
    // FRC Off + 3D PR Case
    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || 
       (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) ||
       ((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)))
#elif((_FRC_SUPPORT == _ON) && (_3D_SUPPORT == _OFF))
    // FRC On + 3D Off Case : 24->60Hz / 24->72Hz uses HW auto 3 block toggle
    if((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))
#else
    // FRC On + 3D shutter case
    // FRC Off + 3D Shutter case
    if((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF)))
#endif    
    {
        // Set OD address = 3D 2nd Read Address + BlockStep
        g_ulSdrThreeBlockAddr2 = ((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | pData[2]) >> 1) + ulBlockStep;
    }
    else
    {
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
        // Avoid OD size > R image size
        if((GET_ASPECT_ORIGIN_MODE() == _TRUE) && (g_stMDomainOutputData.usVHeight < _PANEL_DV_HEIGHT))
        {
            // Set OD address = 3D 2nd Read Address + BlockStep
            g_ulSdrThreeBlockAddr2 = ((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | pData[2]) >> 1) + ulBlockStep;
        }
        else
#endif   
        {
            // Set OD address = 3D 2nd Read Address + 1 / 2 * BlockStep
            g_ulSdrThreeBlockAddr2 = ((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | pData[2]) >> 1) + (ulBlockStep >> 1);
        }
    }

    //=========================================
    // Set OD 3rd Address
    //=========================================
    // Get 2nd Write Address
    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT2);
    pData[0] = ScalerGetByte(P5_AD_SDRF_IN1_MEM_ADDR_H);
    pData[1] = ScalerGetByte(P5_AE_SDRF_IN1_MEM_ADDR_M);
    pData[2] = ScalerGetByte(P5_AF_SDRF_IN1_MEM_ADDR_L);    

#if((_FRC_SUPPORT == _ON) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)))
    // FRC On + 3D PR Case
    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || 
       (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) ||
       ((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)) ||
       ((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))))
#elif((_FRC_SUPPORT == _OFF) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)))
    // FRC Off + 3D PR Case
    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || 
       (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) ||
       ((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)))
#elif((_FRC_SUPPORT == _ON) && (_3D_SUPPORT == _OFF))
    // FRC On + 3D Off Case : 24->60Hz / 24->72Hz uses HW auto 3 block toggle
    if((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))
#else
    // FRC On + 3D shutter case
    // FRC Off + 3D Shutter case
    if((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF)))
#endif    
    {
        // Set OD address = 3D 3rd Read Address + BlockStep
        g_ulSdrThreeBlockAddr3 = ((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | pData[2]) >> 1) + ulBlockStep;
    }
    else
    {
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
        // Avoid OD size > R image size            
        if((GET_ASPECT_ORIGIN_MODE() == _TRUE) && (g_stMDomainOutputData.usVHeight < _PANEL_DV_HEIGHT))
        {
            // Set OD address = 3D 3rd Read Address + BlockStep
            g_ulSdrThreeBlockAddr3 = ((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | pData[2]) >> 1) + ulBlockStep;
        }
        else
#endif
        {
            // Set OD address = 3D 3rd Read Address + 1 / 2 * BlockStep
            g_ulSdrThreeBlockAddr3 = ((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | pData[2]) >> 1) + (ulBlockStep >> 1);
        }
    }

    DebugMessageFRC("3Block-addr1", g_ulSdrThreeBlockAddr1);
    DebugMessageFRC("3Block-addr2", g_ulSdrThreeBlockAddr2);    
    DebugMessageFRC("3Block-addr3", g_ulSdrThreeBlockAddr3);        
}

//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
void ScalerSDRAMSetODThreeBlockAddress(void)
{
    StructSDRAMLineBlockStep stStep;
    
#if((_FRC_SUPPORT == _ON) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)))
    // FRC On + 3D PR Case
    if((GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT) ||
       ((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))))
#elif((_FRC_SUPPORT == _OFF) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))) 
    // FRC Off + 3D PR Case
    if(GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT)
#elif((_FRC_SUPPORT == _ON) && (_3D_SUPPORT == _OFF))
    // FRC On Case + 3D Off : 24->60Hz / 24->72Hz uses HW auto 3 block toggle
    if((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))
#else
    // FRC Off + 3D Shutter Case
    // FRC On + 3D Shutter Case
    if((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF)))
#endif
    {
        // Get FIFO input size
        ScalerGetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, 1, &pData[0], _NON_AUTOINC);
        ScalerGetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, 1, &pData[1], _NON_AUTOINC);
        ScalerGetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, 1, &pData[2], _NON_AUTOINC);
        ScalerGetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, 1, &pData[3], _NON_AUTOINC);

        // Get FIFO input H Width
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
        if((GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR) &&
           ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)))
        {
            // Avoid OD data overlap R image before R output in LR display.
            PDATA_WORD(3) = ((pData[0] << 8) | pData[1]) + _3_BLOCK_OD_MARGIN;
        }
        else
#endif
        {
            PDATA_WORD(3) = ((pData[0] << 8) | pData[1]);
        }
        
        // Get FIFO input V Height
        PDATA_WORD(4) = (pData[2] << 8) | pData[3];

        // Frame mode
        if(ScalerGetBit(P5_B7_SDRF_IN1_LINE_NUM_H, _BIT4) == _BIT4)
        {
            // One Frame total pixel for SDRAM (unit : 64 bits)
            PDATA_DWORD(0) = ((DWORD)PDATA_WORD(3) * PDATA_WORD(4) * _BIT_PER_PIXEL % 64) ?
                                  (((DWORD)PDATA_WORD(3) * PDATA_WORD(4) * _BIT_PER_PIXEL / 64) + 1) :
                                  ((DWORD)PDATA_WORD(3) * PDATA_WORD(4) * _BIT_PER_PIXEL / 64);            
                                  
            stStep.ulBlockStep = ScalerSDRAMAddressConversion((PDATA_DWORD(0) * 64 / _MEMORY_BUS_WIDTH)); 
        }
        else        
        {
            // Calculate Block Step
            // One line total pixel for SDRAM (unit : 64 bits)
            PDATA_WORD(3) = ((DWORD)PDATA_WORD(3) * _BIT_PER_PIXEL % 64) ?
                                  (((DWORD)PDATA_WORD(3) * _BIT_PER_PIXEL / 64) + 1) :
                                  ((DWORD)PDATA_WORD(3) * _BIT_PER_PIXEL / 64);            
                                  
            stStep = ScalerSDRAMCalculateLineStepAndBlockStep(PDATA_WORD(3), PDATA_WORD(4));    
        }

#if(_FRC_SUPPORT == _ON) 
#if(_3D_SUPPORT == _ON)
        if(GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT)
#endif
        {
            if((WORD)(stStep.ulBlockStep & 0x7FF) > 0)
            {
                stStep.ulBlockStep = ((((stStep.ulBlockStep >> 11) + 1) << 11) & 0xFFFFF800);
            }
        }
#endif

        pData[0] = (BYTE)(stStep.ulBlockStep & 0xFF);
        stStep.ulBlockStep = ((stStep.ulBlockStep >> 1) & 0xFFFFFF00) | pData[0];

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
        // 3D PR
        if((((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF)) && 
            ((GET_3D_INPUT_FORMAT() != _FRAME_PACKING) || ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))) ||
           ((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))
#elif((_FRC_SUPPORT == _ON) && (_3D_SUPPORT == _OFF))
        // FRC On + 3D Off
        if(((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF)))
#else
        // 3D Shutter
        if((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF)))
#endif
        {
            // Set OD 3 Block Address
            ScalerSDRAMCalculateODThreeBlockAddress(stStep.ulBlockStep);
        }
        else
        {
            // Get 3D Write Address
            ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
            pData[0] = ScalerGetByte(P5_AD_SDRF_IN1_MEM_ADDR_H);
            pData[1] = ScalerGetByte(P5_AE_SDRF_IN1_MEM_ADDR_M);
            pData[2] = ScalerGetByte(P5_AF_SDRF_IN1_MEM_ADDR_L);

            // Address = 3D write address + Block step
            g_ulSdrThreeBlockAddr1 = (((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8)) >> 1) | (DWORD)pData[2]) + stStep.ulBlockStep;

#if(_OD_SUPPORT == _ON)
            // Set OD address
            ScalerSetByte(P3_AC_LS_MEM_START_ADDR_H, ((g_ulSdrThreeBlockAddr1 >> 16) & 0xFF));
            ScalerSetByte(P3_AD_LS_MEM_START_ADDR_M, ((g_ulSdrThreeBlockAddr1 >> 8) & 0xFF));
            ScalerSetByte(P3_AE_LS_MEM_START_ADDR_L, (g_ulSdrThreeBlockAddr1 & 0xFF));
#endif

        }
    }
}
#endif

//--------------------------------------------------
// Description  : Transfer the Memory Size to Address
// Input Value  : ulTotalSize --> Total Memory size
// Output Value : Line Step Address or Block Step Address
//--------------------------------------------------
DWORD ScalerSDRAMAddressConversion(DWORD ulTotalSize)
{
#if(_SDRAM_SIZE_CONFIG >= _2M_32BIT)
    return (((ulTotalSize & 0xFFFF00) << 1) | LOBYTE(ulTotalSize));
#else
    return (((ulTotalSize & 0x000100) << 1) | ((ulTotalSize & 0xFFFE00) << 2) | LOBYTE(ulTotalSize));
#endif
}

//--------------------------------------------------
// Description  : Calculate the Line Step and Block Step
// Input Value  : usHorSize --> Horizontal size
//                usVerSize --> Vertical size
// Output Value : Line Step and Block Step
//--------------------------------------------------
StructSDRAMLineBlockStep ScalerSDRAMCalculateLineStepAndBlockStep(WORD usHorSize, WORD usVerSize)
{
    StructSDRAMLineBlockStep stStep;
    
    stStep.usLineStep = usHorSize;

    if(stStep.usLineStep & 0x03)
    {
        stStep.usLineStep += (4 - (stStep.usLineStep & 0x03));
    }

    stStep.usLineStep = stStep.usLineStep * 64 / _MEMORY_BUS_WIDTH;

#if(_3D_SUPPORT == _ON)
    	// Align HWidth with 0.5/0.75/1/1.25/1.5 row to avoid Bank address.
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
        if((((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && 
            (GET_MEMORY_DVF_SELECT() != _1_IVF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) ||
            ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) && (GET_INTERLACED_MODE() == _TRUE)))
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
        // Frame Packing interlace mode + 2D display uses FRC's double buffer mode.
        // 6229 FRC's double buffer mode cannot have Bank address.
        if((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && 
            (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) &&
            (GET_INTERLACED_MODE() == _TRUE))
#endif            
        {
            // Align HWidth with 0.25/0.5/0.75/1/1.25/1.5 row
            if(stStep.usLineStep <= (_MEMORY_COL_PER_BANK))
            {
                 stStep.usLineStep = _MEMORY_COL_PER_BANK;
            }
            else if(stStep.usLineStep <= (2 * _MEMORY_COL_PER_BANK))
            {
                 stStep.usLineStep = 2 * _MEMORY_COL_PER_BANK;
            }
            else if(stStep.usLineStep <= (3 * _MEMORY_COL_PER_BANK))
            {
                 stStep.usLineStep = 3 * _MEMORY_COL_PER_BANK;
            }
            else if(stStep.usLineStep <= (4 * _MEMORY_COL_PER_BANK))
            {
                 stStep.usLineStep = 4 * _MEMORY_COL_PER_BANK;
            }
            else if(stStep.usLineStep <= (5 * _MEMORY_COL_PER_BANK))
            {
                 stStep.usLineStep = 5 * _MEMORY_COL_PER_BANK;
            }
            else if(stStep.usLineStep <= (6 * _MEMORY_COL_PER_BANK))
            {
                 stStep.usLineStep = 6 * _MEMORY_COL_PER_BANK;
            } 
        }
#endif        

    stStep.ulBlockStep = (DWORD)usVerSize * stStep.usLineStep;

    stStep.usLineStep = ScalerSDRAMAddressConversion(stStep.usLineStep);    
    stStep.ulBlockStep = ScalerSDRAMAddressConversion(stStep.ulBlockStep);    
    
    return stStep;    
}

//--------------------------------------------------
// Description  : M:N frame tracking 
// Input Value  : En: enable / disable
// Output Value : None
//--------------------------------------------------
void ScalerSDRAMSetFrameTrackingEnable(bit bEn)
{
    // Enable/Disable M:N frame tracking function
    ScalerSetDataPortBit(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_25_MN_FRAME_RATE_EN, ~_BIT7, (BYTE)bEn << 7);
}    

//--------------------------------------------------
// Description  : Set M:N frame tracking
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSDRAMFrameTracking(void)
{
    BYTE ucM = 1;
    BYTE ucN = 1;

    PDATA_WORD(0) = ScalerSDRAMGetMNRatio();
    
    ucM = (PDATA_WORD(0) >> 8) & 0xFF;
    ucN = PDATA_WORD(0) & 0xFF;
    
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    if(GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL)
    {
       ucM = 2;
       ucN = 2;
    }
#endif
    
    // Set to read DVTotal result
    ScalerSetBit(CM_44_LAST_LINE_H, ~_BIT7, _BIT7);

    // Wait DVS for get correct data
    ScalerTimerWaitForEvent(_EVENT_DVS);

    // Read DVTotal result
    ScalerRead(CM_44_LAST_LINE_H, 2, &pData[2], _AUTOINC);

    // DVTotal value
    PDATA_WORD(1) &= 0x0fff;

    PDATA_WORD(0) = PDATA_WORD(0) * ucM / ucN;               
    PDATA_WORD(1) = PDATA_WORD(1) * ucM / ucN;    

    if(PDATA_WORD(1) < (g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight))
    {
        DebugMessageFRC("FrameTrack-DVT-Error", PDATA_WORD(1));
        PDATA_WORD(1) = (g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) + 1;        
    }
 
    // Set DVTotal
    ScalerSetBit(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (pData[2] & 0x0F));
    ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, pData[3]);

    // Set M:N frame tracking function
    // Set ivs skipped, M = register value +1
    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_26_M_FOR_MN_FRAME_RATE);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, (ucM - 1));

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_27_N_FOR_MN_FRAME_RATE);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, (ucN - 1));     
}

//--------------------------------------------------
// Description  : Set display adderss for auto block toggle   
// Input Value  : En: enable / disable
// Output Value : None
//--------------------------------------------------
void ScalerSDRAMSetDisplayAutoBlkToggleEnable(bit bEn)
{
    // Enable M:N HW auto toggle's double buffer
    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~_BIT5, _BIT5);        
    
    if(bEn == _ENABLE)
    {
        // Input Hardware auto toggle address enable
        ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~_BIT4, _BIT4);
    
        // Display Hardware auto toggle among address enable
        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~_BIT4, _BIT4);    
    }
    else
    {
        // Input Hardware auto toggle address disable
        ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~_BIT4, 0x00);
    
        // Display Hardware auto toggle among address disable
        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~_BIT4, 0x00);            
    }
    
    // Hardware auto toggle M:N double buffer ready
    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~_BIT6, _BIT6);

    // Wait dobule buffer
    ScalerTimerPollingFlagProc(_M_N_AUTO_BLK_TOGGLE_STABLE_TIME, P5_BA_SDRF_IN1_MADDR_TOG_CTL, _BIT6, 0);
}


//--------------------------------------------------
// Description  : Set auto block toggle
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSDRAMSetHWAutoBlockToggle(void)
{
    BYTE ucM = 1;
    BYTE ucN = 1;

    PDATA_WORD(0) = ScalerSDRAMGetMNRatio();
    
    ucM = (PDATA_WORD(0) >> 8) & 0xFF;
    ucN = PDATA_WORD(0) & 0xFF;    

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    if(GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL)
    {
        ucM = 1;
        ucN = 2;
    }
#endif

    // IVS to DVS shift value for hardware auto toggle among three initial read address
    if(GET_MEMORY_DVF_SELECT() == _3_IVF)
    {
        // Set Shift = 2 
        ScalerSetBit(P5_CB_SDRF_MN_BLOCK_STEP_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 2 << 4);    
    }
    else
    {
        // Set Shift = 0 
        // _2_5_IVF  
        ScalerSetBit(P5_CB_SDRF_MN_BLOCK_STEP_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0 << 4);                    
    }

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    if(GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL)
    {
        // Set Shift = 1 
        ScalerSetBit(P5_CB_SDRF_MN_BLOCK_STEP_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 1 << 4);    
    }
#endif    

    // Multiple of hardware auto toggle among three initial read address, it is (N/M - 1)
    PDATA_WORD(0) = ucN / ucM - 1;
    
    ScalerSetBit(P5_BE_SDRF_MN_PXL_NUM_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), ((WORD *)pData)[0] << 4);

    // Remain of hardware auto toggle among three initial read address, and it is (N%M)/N * 2^10.(11bit in total)    
    PDATA_WORD(0) = ((ucN % ucM) << 10) / ucN;
    PDATA_WORD(0) += 1;
    
    ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT7 | _BIT6 | _BIT5), ((pData[0] << 5) & 0xFF));
    ScalerSetByte(P5_FF_SDRF_MN_MADDR_TOG_REM, (pData[1] & 0xFF));
}

//--------------------------------------------------
// Description  : Get M:N ratio
// Input Value  : None
// Output Value : M << 8 | N
//--------------------------------------------------
WORD ScalerSDRAMGetMNRatio(void)
{
    BYTE ucM = 1;
    BYTE ucN = 1;
    
    switch(GET_MEMORY_DVF_SELECT())
    {
        case _2_IVF:

            ucM = 1;
            ucN = 2;
            
            break;

        case _3_IVF:

            ucM = 1;
            ucN = 3;            

            break;
            
        case _2_5_IVF:

            ucM = 2;
            ucN = 5;            

            break;

        default:

            break;
    }   

    return ((ucM << 8) | (ucN));
}
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON) || (_OD_SUPPORT == _ON))
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
#endif // #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON) || (_OD_SUPPORT == _ON)

#if(_3D_SUPPORT == _ON)
//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
WORD ScalerSDRAMCalculateLineSizeAlignToRow(WORD usHWidth, bit bUpBound)
{
    BYTE ucIdx;
    WORD usAlignHSize = 0;

    usHWidth = (DWORD)usHWidth * _BIT_PER_PIXEL / _MEMORY_BIT_NUM;
    
    // Align HWidth with 0.25/0.5/0.75/1/1.25/1.5 row
    if(bUpBound == _TRUE)
    {
        for(ucIdx = 1; ucIdx <=6 ; ucIdx++)
        {
            usAlignHSize = (ucIdx * _MEMORY_COL_PER_BANK);
            
            if(usHWidth <= usAlignHSize)
            {
                break;
            }
        }
    }
    else
    {
        for(ucIdx = 2; ucIdx <= 7; ucIdx++)
        {
            usAlignHSize = (ucIdx * _MEMORY_COL_PER_BANK);
            
            if(usHWidth < usAlignHSize)
            {
                usAlignHSize = (usAlignHSize - _MEMORY_COL_PER_BANK);
                break;
            }
        }
    }

    usAlignHSize = (DWORD)usAlignHSize * _MEMORY_BIT_NUM / _BIT_PER_PIXEL;
    return usAlignHSize;
}
#endif // #if(_3D_SUPPORT == _ON)

#endif //___#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)

#if(_SDRAM_PHASE_CALIBRATION == _ON)
#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get FRC read block index
// Input Value  : void
// Output Value : void
//--------------------------------------------------
DWORD ScalerSDRAMSelectThreeBlock(void)
{
    switch(ScalerGetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, (_BIT1 | _BIT0)))
    {
        case 0:
            return g_ulSdrThreeBlockAddr1;

        case 1:
            return g_ulSdrThreeBlockAddr2;

        case 2:
            return g_ulSdrThreeBlockAddr3;

        default:
            break;
    }
}
#endif

//--------------------------------------------------
// Description  : SDRAM Test Delay 1ms
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMDelay1ms(void)
{
    BYTE ucCnt = 0;

    for(ucCnt = 0; ucCnt < 14; ucCnt++)
    {
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);
    }
}

//--------------------------------------------------
// Description  : SDRAM token ring and phase initial
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMTokenPhaseSet(void)
{
    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x00);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x00);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x00);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x23);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x63); 
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x40);
#else
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x83);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x40);
#endif

    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x03);    
    ScalerSetByte(P4_BE_SDR_PHASE_CAL, 0x00);
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x00);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, 0x00);
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x40);
    ScalerSetByte(P4_C3_DQS0_DLY2, 0x00);
    ScalerSetByte(P4_C5_DQS1_DLY2, 0x00);
    ScalerSDRAMReset();
}

//--------------------------------------------------
// Description  : Clear SDRAM fifo
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMClearFifo(void)
{
    BYTE ucCnt = 0;

    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    for(ucCnt = 0; ucCnt < _TEST_DATA_MAX; ucCnt++)
    {
        ScalerSetByte(P4_BC_SDR_DATA_BUF, 0x00);
    }
}

//--------------------------------------------------
// Description  : Write SDRAM  test pattern
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMWritePattern(void)
{
    BYTE ucCnt = 0;

    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    for(ucCnt = 0; ucCnt < _TEST_DATA_MAX; ucCnt++)
    {
        ScalerSetByte(P4_BC_SDR_DATA_BUF, tSDRAM_PATTERN[ucCnt]);
    }

    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x80);
}

//--------------------------------------------------
// Description  : Set mpll
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMMpllSet(BYTE ucMCLK)
{
    BYTE ucMcode = 0;
    WORD usMPLLOffset = 0;

#if(_EXT_XTAL == _XTAL14318K)
    if(ucMCLK == _MEMORY_SPEED_215MHZ)
    {
        ucMcode = 0x3E;
    }
    else if(ucMCLK == _MEMORY_SPEED_198MHZ)
    {
        ucMcode = 0x39;
    }
    else if(ucMCLK == _MEMORY_SPEED_220MHZ)
    {
        ucMcode = 0x40;
    }
    else if(ucMCLK == _MEMORY_SPEED_100MHZ)
    {
        ucMcode = 0x1C;
    }
    else
    {
        usMPLLOffset = ((WORD)(ScalerGetByte(P0_FA_MCLK_FINE_TUNE_OFFSET_MSB) & 0x0F) << 8) + ScalerGetByte(P0_FB_MCLK_FINE_TUNE_OFFSET_LSB);
        ucMcode = (((DWORD)ucMCLK * 4 * 1000 / _EXT_XTAL) * 32768 + (32768 - usMPLLOffset) >> 1) / (32768 - usMPLLOffset) - 2;
    }

    ScalerSetByte(P0_F5_MPLL_M, ucMcode);
#else
    #warning "You must set M code value there."
#endif

    ScalerSetByte(P0_F6_MPLL_N, 0x00);
    Delay5us(g_ucDelay5usN);
    Delay5us(g_ucDelay5usN);
    Delay5us(g_ucDelay5usN);
}

//--------------------------------------------------
// Description  : Recover page 4 register setting
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMDefaultTokenRing(void)
{
    ScalerSetByte(P4_A6_SDR_SLEW_RATE, 0x00);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    ScalerSetByte(P4_BD_SDR_MCU_RD_LEN, 0x04);
    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x0C);
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
    ScalerSetByte(P4_BD_SDR_MCU_RD_LEN, 0x02);
    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x06); 
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    ScalerSetByte(P4_BD_SDR_MCU_RD_LEN, 0x02);
    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x0D);
#else
    #warning "You must set P4_BD_ value there."
#endif


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
}

//--------------------------------------------------
// Description  : Load default sdram phase
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMDefaultPhase(void)
{
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);

#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);
    ScalerSetByte(P4_C5_DQS1_DLY2, _SDR_DQS_DLY);

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)

    ScalerSetByte(P4_A5_SDR_MEM_TYPE, _SDR_CAS_LATN);
    ScalerSetByte(P4_C0_SDR_CLK_DLY1, _SDR_CLK_DLY1);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, _SDR_CLK_DLY2);
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
    ScalerSetByte(P4_C3_DQS0_DLY2, _SDR_DQS_DLY);
    ScalerSetByte(P4_C5_DQS1_DLY2, _SDR_DQS_DLY);
#else
    #warning "You must set value there."
#endif

    ScalerSDRAMReset();
}

//--------------------------------------------------
// Description  : K sdram phase count
// Input Value  : void
// Output Value : Phase count
//--------------------------------------------------
BYTE ScalerSDRAMPhaseCount(bit bDBBufferFlag)
{
    BYTE ucPhcalCnt = 0x00;
    BYTE ucDealyMaxTemp = 45;
    WORD usDelayUnit = 0x00;
    
    if(bDBBufferFlag == _FALSE)
    {
        ScalerSetByte(P4_BE_SDR_PHASE_CAL, 0x04);
        Delay5us(g_ucDelay5usN);
        Delay5us(g_ucDelay5usN);   
    }
   
    ucPhcalCnt = ScalerGetByte(P4_BF_SDR_CAL_RESULT) & 0x7F;

    if((ucPhcalCnt == 0x00) || (ScalerGetBit(P4_BE_SDR_PHASE_CAL, _BIT2) == _BIT2))
    {
        ScalerSetByte(P4_BE_SDR_PHASE_CAL, 0x00);
        return ucDealyMaxTemp;
    }

    usDelayUnit = (WORD)1000 * 50 / ucPhcalCnt * 20 / _M2PLL_CLK_MHZ;
    ScalerSetByte(P4_BE_SDR_PHASE_CAL, 0x00);

    return (WORD)1000 * 50 / _MEMORY_SPEED * 20 / usDelayUnit;
}

//--------------------------------------------------
// Description  : Mcu mode test
// Input Value  : ucAddrH    --> SDRAM address.
//                ucAddrM    --> SDRAM address.
//                ucAddrL    --> SDRAM address.
//                bWriteMcuFlag    --> Write or read flag.
//
// Output Value : Test result
//--------------------------------------------------
bit ScalerSDRAMMCUMode(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL, bit bWriteMcuFlag)
{
    bit bResult = _SUCCESS;
    BYTE ucValue = 0;
    BYTE ucCnt = 0;

    if(bWriteMcuFlag == _TRUE)
    {
        ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
        ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
        ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
        ScalerSDRAMWritePattern();

        ScalerSDRAMMpllSet(100);
        ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x00);
        ScalerSetByte(P4_C1_SDR_CLK_DLY2, 0x00);
        ScalerSDRAMReset();
    }

    ScalerSDRAMClearFifo();
    ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
    ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
    ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0xA0);

    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    for(ucCnt = 0; ucCnt < _TEST_DATA_MAX; ucCnt++)
    {
        ucValue = ScalerGetByte(P4_BC_SDR_DATA_BUF);

        if(ucValue != tSDRAM_PATTERN[ucCnt])
        {
            bResult = _FAIL;
            break;
        }
    }

    if(bWriteMcuFlag == _TRUE)
    {
        ScalerSDRAMClearFifo();
        ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
        ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
        ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
        ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
        ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x80);
    }

    return bResult;
}

//--------------------------------------------------
// Description  : On line mode test
// Input Value  : ucAddrH    --> SDRAM address.
//                ucAddrM    --> SDRAM address.
//                ucAddrL    --> SDRAM address.
//
// Output Value : Test result
//--------------------------------------------------
bit ScalerSDRAMOnlineMCUMode(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL)
{
    bit bResult = _SUCCESS;
    BYTE ucValue = 0;
    BYTE ucCnt = 0;

    ScalerSDRAMClearFifo();

    ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
    ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
    ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0xA0);
    Delay5us(g_ucDelay5usN);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    ScalerSDRAMDelay1ms();
                   
    for(ucCnt = 0; ucCnt < _TEST_DATA_MAX; ucCnt++)
    {
        ucValue = ScalerGetByte(P4_BC_SDR_DATA_BUF);

        if(ucValue != tSDRAM_PATTERN[ucCnt])
        {
            bResult = _FAIL;
            break;
        }
    }

    return bResult;
}

//--------------------------------------------------
// Description  : Write test pattern into SDRAM
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMWrPatternOnce(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL)
{
    ScalerSDRAMClearFifo();

    ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
    ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
    ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x80);
    Delay5us(g_ucDelay5usN);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);
 
    ScalerSDRAMDelay1ms();              
   
    ScalerSetByte(P4_B8_SDR_ADDR_H, ucAddrH);
    ScalerSetByte(P4_B9_SDR_ADDR_M, ucAddrM);
    ScalerSetByte(P4_BA_SDR_ADDR_L, ucAddrL);
    ScalerSDRAMWritePattern();
    Delay5us(g_ucDelay5usN);
    ScalerSetByte(P4_BB_SDR_ACCESS_CMD, 0x00);

    ScalerSDRAMDelay1ms();                      
}

//--------------------------------------------------
// Description  : SDRAM write phase search
// Input Value  : void
// Output Value : SDRAM mclk cycle and good write phase range
//--------------------------------------------------
DWORD ScalerSDRAMWritePhaseSearch(void)
{
    bit bClkInvGoodStart = _FALSE;
    bit bClkInvGoodStartTemp = _FALSE;
    bit bClkGoodStart = _FALSE;
    bit bWritePhaseFlag = _FALSE;
    bit bGoodStartFlag = _FALSE;
    BYTE ucSdrMclkFineTune = 0;
    BYTE ucChangeState = 0;
    BYTE ucRow = 0;
    BYTE ucBestWriteCount = 0;
    BYTE ucTransientStart = 0;
    BYTE ucTransientEnd = 0;
    BYTE ucDataStart = 0;
    BYTE ucDataEnd = 0;
    BYTE ucDebounceT = 0;
    BYTE ucMclkCycle = 0;
    BYTE ucDataSkewA = 0;
    BYTE ucDataSkewC = 0;

    ScalerSetBit(P0_FC_MCLK_SPREAD_SPECTRUM, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT0), (_BIT2 | _BIT0));
    ScalerSDRAMTokenPhaseSet();

    ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x00);
    ScalerSDRAMReset();
    
    // Step1:Jude bad start or good start
    for(ucRow = 0; ucRow < 255; ucRow++)
    {
        if(ucSdrMclkFineTune > 254)
        {
            break;
        }

        ScalerSDRAMMpllSet(_MEMORY_SPEED);
        ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucSdrMclkFineTune);
        ScalerSDRAMReset();

        bWritePhaseFlag = ScalerSDRAMMCUMode((ucRow >> 6), ((ucRow & 0x3F) << 2), 0x00, _TRUE);

        if(bWritePhaseFlag == _FALSE)
        {
            bClkGoodStart = _FALSE;
            bGoodStartFlag = _FALSE;
            ucSdrMclkFineTune++;
            break;
        }

        if(bWritePhaseFlag == _TRUE)
        {
            if(bGoodStartFlag == _FALSE)
            {
                bGoodStartFlag = _TRUE;
                ucDebounceT = 1;
            }
            else
            {
                ucDebounceT++;
    
                if(ucDebounceT > 4)
                {
                    bClkGoodStart = _TRUE;
                    ucSdrMclkFineTune++;
                    break;
                }
            }
        }

        ucSdrMclkFineTune++;
    }
    
    // Step2:Search transient time and data width
    if(bClkGoodStart == _TRUE)
    {
        for(ucRow = 0; ucRow < 255; ucRow++)
        {
            if(ucSdrMclkFineTune > 254)
            {
                break;
            }
    
            ScalerSDRAMMpllSet(_MEMORY_SPEED);
            ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucSdrMclkFineTune);
            ScalerSDRAMReset();
    
            bWritePhaseFlag = ScalerSDRAMMCUMode((ucRow >> 6), ((ucRow & 0x3F) << 2), 0x00, _TRUE);
    
            if(bWritePhaseFlag == _TRUE)
            {
                if(bGoodStartFlag == _FALSE)
                {
                    bGoodStartFlag = _TRUE;
                    ucDebounceT = 1;
                }
                else
                {
                    ucDebounceT++;
        
                    if((ucChangeState == 1) && (ucDebounceT > 4))
                    {
                        ucChangeState = 2;
                        ucTransientEnd = ucSdrMclkFineTune - (ucDebounceT - 1);
                        ucDataStart = ucTransientEnd;  
                    }
                }
            }
            else if((bGoodStartFlag == _TRUE) && (bWritePhaseFlag == _FALSE))
            {
                bGoodStartFlag = _FALSE;
    
                if(ucDebounceT > 4)
                {
                    if(ucChangeState == 0)
                    {
                        ucChangeState = 1;    
                        ucTransientStart = ucSdrMclkFineTune;
                    }
                    else if(ucChangeState == 2)
                    {  
                        ucDataEnd = ucSdrMclkFineTune;
                        break;
                    }
                }
            }

            ucSdrMclkFineTune++;
        }
    }
    else
    {
        for(ucRow = 0; ucRow < 255; ucRow++)
        {
            if(ucSdrMclkFineTune > 254)
            {
                break;
            }
    
            ScalerSDRAMMpllSet(_MEMORY_SPEED);
            ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucSdrMclkFineTune);
            ScalerSDRAMReset();
    
            bWritePhaseFlag = ScalerSDRAMMCUMode((ucRow >> 6), ((ucRow & 0x3F) << 2), 0x00, _TRUE);
        
            if(bWritePhaseFlag == _TRUE)
            {
                if(bGoodStartFlag == _FALSE)
                {
                    bGoodStartFlag = _TRUE;
                    ucDebounceT = 1;
                }
                else
                {
                    ucDebounceT++;
        
                    if(ucDebounceT > 4)
                    {
                        if(ucChangeState == 0)
                        {
                            ucChangeState = 1;
                            ucDataStart = ucSdrMclkFineTune - (ucDebounceT - 1);
                        }
                        else if(ucChangeState == 2)
                        {   
                            ucTransientEnd = ucSdrMclkFineTune - (ucDebounceT - 1);
                            break;
                        }   
                    }
                }
            }
            else if((bGoodStartFlag == _TRUE) && (bWritePhaseFlag == _FALSE))
            {
                bGoodStartFlag = _FALSE;
    
                if(ucDebounceT > 4)
                {
                    if(ucChangeState == 1)
                    {
                        ucChangeState = 2;    
                        ucTransientStart = ucSdrMclkFineTune;
                        ucDataEnd = ucSdrMclkFineTune; 
                    }
                }
            }

            ucSdrMclkFineTune++;
        }
    }

    // Step3:Measure mclk duty
    bGoodStartFlag = _FALSE;
    ucChangeState = 0;
    ucSdrMclkFineTune = 0;
    ucDebounceT = 0;

    for(ucRow = 0; ucRow < 255; ucRow++)
    {
        if(ucSdrMclkFineTune > 254)
        {
            break;
        }

        ScalerSDRAMMpllSet(_MEMORY_SPEED);
        ScalerSetByte(P4_C0_SDR_CLK_DLY1, 0x80);
        ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucSdrMclkFineTune);
        ScalerSDRAMReset();

        bWritePhaseFlag = ScalerSDRAMMCUMode((ucRow >> 6), ((ucRow & 0x3F) << 2), 0x00, _TRUE);

        if((ucSdrMclkFineTune == 0) && (bWritePhaseFlag == _FALSE))
        {
            bClkInvGoodStart = _FALSE;
        }

        if(bWritePhaseFlag == _TRUE) 
        {
            if(bGoodStartFlag == _FALSE)
            {
                bGoodStartFlag = _TRUE;
                ucDebounceT = 1;

                if(ucSdrMclkFineTune == 0)
                {
                    bClkInvGoodStartTemp = _TRUE;
                }
            }        
            else
            {
                ucDebounceT++;
    
                if(ucDebounceT > 4)
                {
                    if(bClkInvGoodStartTemp == _TRUE)
                    {
                        bClkInvGoodStart = _TRUE;
                        bClkInvGoodStartTemp = _FALSE;
                    }

                    if(((bClkInvGoodStart == _FALSE) && (bClkGoodStart == _TRUE)) || (ucChangeState == 1))
                    {
                        ucDataSkewC = ucSdrMclkFineTune - (ucDebounceT - 1);
                        break;
                    }                          
                }            
            }
        }
        else if((bGoodStartFlag == _TRUE) && (bWritePhaseFlag == _FALSE))
        {
            bGoodStartFlag = _FALSE;

            if(ucDebounceT > 4)
            {
                if(bClkGoodStart == _TRUE)
                {
                    ucDataSkewC = ucSdrMclkFineTune;
                    break;
                }
                else 
                {
                    ucChangeState = 1;
                }  
            }
            else
            {
                if(bClkInvGoodStartTemp == _TRUE)
                {
                    bClkInvGoodStart = _FALSE;
                    bClkInvGoodStartTemp = _FALSE;
                }
            }
        }

        ucSdrMclkFineTune++;
    }

    // Step4: Calculate MclkCycle and write move
    ucMclkCycle = (ucTransientEnd - ucTransientStart) + (ucDataEnd - ucDataStart);
    ucBestWriteCount = ((ucDataStart + ucDataEnd) / 2) % ucMclkCycle;

    // Calculate 2.0ns Write Delay Uint, backup ucRow
    ucRow = ((DWORD)2 * ucMclkCycle * _MEMORY_SPEED + 500) / 1000;

    if(bClkGoodStart == _TRUE)
    {
        if(bClkInvGoodStart == _FALSE)
        {
            ucDataSkewA = ucTransientEnd;
        }
        else
        {
            ucDataSkewA = ucTransientStart;
        }
    }
    else
    {
        ucDataSkewA = ucDataStart;
    }

    // Back up ucHighDutyWidth
    ucChangeState = abs(ucDataSkewA - ucDataSkewC);

    ScalerSDRAMMpllSet(_MEMORY_SPEED);
    ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucBestWriteCount);
    ScalerSetByte(P4_C2_DQS0_DLY1, 0x00);
    ScalerSetByte(P4_C4_DQS1_DLY1, 0x00);
    ScalerSDRAMReset();

    DebugMessageSDRAM("Step3:ucHighDutyWidth", ucChangeState);
    DebugMessageSDRAM("Step4:ucMclkCycle", ucMclkCycle);
    DebugMessageSDRAM("Step3:Transient Time", (ucTransientEnd - ucTransientStart));

    if(ucMclkCycle >= ((ucTransientEnd - ucTransientStart) + ucRow))
    {
        return ((((DWORD)(ucMclkCycle - (ucTransientEnd - ucTransientStart) - ucRow)) >> 1)  << 16) | ((WORD)ucMclkCycle << 8) | ucChangeState; 
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : SDRAM read phase research
// Input Value  : ucHalfMclk    --> Mclk cycle.
//                ucWriteMove    --> Good write phase range.
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMReadPhaseSearch(BYTE ucHighDutyWidth, BYTE ucMclkCyle, BYTE ucWriteMove)
{
    bit bIndex = _FALSE;
    bit bReadPhaseFlag = _FALSE;
    bit bReadPhaseFlag_last = _FALSE;
    bit bGoodStartFlag = _FALSE;
    bit bWriteInverL = _FALSE;
    bit bWriteInverR = _FALSE;
    bit bConflictArea = _FALSE;
    BYTE ucSdrDqsFineDly = 0;
    BYTE ucSdrDqsFineDlyMax = 0;
    BYTE ucBestWriteCount = 0;
    BYTE ucBestReadPhase = 0;
    BYTE ucSdrCasLatn = 0;
    BYTE ucBestSdrCasLatn = 0;
    BYTE ucStart = 0;
    BYTE ucEnd = 0;
    BYTE ucMaxWinS = 0;
    BYTE ucMaxWinE = 0;
    BYTE ucMaxWinWidth = 0;
    BYTE ucWrToRdDelayUnit = 0;
    BYTE uc2NsReadDelayUnit = 0;
    BYTE ucLRShift = 0;
    BYTE ucWritePhaseTemp = 0;
    BYTE ucLRShiftTemp = 0;

    ucBestWriteCount = ScalerGetByte(P4_C1_SDR_CLK_DLY2);
    ucSdrDqsFineDlyMax = ScalerSDRAMPhaseCount(_FALSE);
    
    // Calculate 2.0ns
    uc2NsReadDelayUnit = ((DWORD)2 * ucSdrDqsFineDlyMax * _MEMORY_SPEED + 500) / 1000;
    ucWrToRdDelayUnit = (WORD)ucMclkCyle * 100 / ucSdrDqsFineDlyMax;
    ScalerSDRAMWrPatternOnce(0x00, 0x00, 0x00);

    for(ucBestReadPhase = 1; ucBestReadPhase < 8; ucBestReadPhase += 2)
    {
        for(ucSdrDqsFineDly = 0; ucSdrDqsFineDly <= ucSdrDqsFineDlyMax; ucSdrDqsFineDly++)
        {
            ucSdrCasLatn = ScalerGetByte(P4_A5_SDR_MEM_TYPE);
            ucSdrCasLatn = ((ucSdrCasLatn & 0xF8) | ucBestReadPhase);
            ScalerSetByte(P4_A5_SDR_MEM_TYPE, ucSdrCasLatn);
            ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly);
            ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDly);

            bReadPhaseFlag = ScalerSDRAMMCUMode(0x00, 0x00, 0x00, _FALSE);

            if(bIndex == _TRUE)
            {
                if((bReadPhaseFlag_last == _FALSE) && (bReadPhaseFlag == _TRUE) && (bGoodStartFlag == _FALSE))
                {
                    ucStart = ucSdrDqsFineDly;
                    bGoodStartFlag = _TRUE;
                }

                if((bReadPhaseFlag_last == _TRUE) && (bReadPhaseFlag == _FALSE) && (bGoodStartFlag == _TRUE))
                {
                    bGoodStartFlag = _FALSE;

                    if(ucSdrDqsFineDly == 0)
                    {
                        ucEnd = ucSdrDqsFineDlyMax;
                        ucSdrCasLatn = ucSdrCasLatn - 2;
                        bConflictArea = _TRUE;
                    }
                    else
                    {
                        ucEnd = ucSdrDqsFineDly - 1;

                        if(bConflictArea == _TRUE)
                        {
                            g_ucConflictArea = ucStart;
                        }
                    }

                    // Threshold = 2
                    if(((ucEnd - ucStart + 3) >= ucMaxWinWidth) && (ucStart > 1))
                    {
                        ucMaxWinWidth = ucEnd - ucStart + 1;
                        ucMaxWinS = ucStart;
                        ucMaxWinE = ucEnd;
                        ucBestSdrCasLatn = ucSdrCasLatn;
                    }
                }
            }

            bReadPhaseFlag_last = bReadPhaseFlag;
            bIndex = _TRUE;
        }
    }

    if(ucMaxWinWidth >= uc2NsReadDelayUnit)
    {
        ucBestReadPhase = (ucMaxWinS + ucMaxWinE) >> 1;
        ScalerSetByte(P4_A5_SDR_MEM_TYPE, ucBestSdrCasLatn);
        ScalerSetByte(P4_C3_DQS0_DLY2, ucBestReadPhase);
        ScalerSetByte(P4_C5_DQS1_DLY2, ucBestReadPhase);
        ScalerSDRAMReset();
    }
    else
    {
        if((ucSdrDqsFineDlyMax - ucMaxWinE) > (ucMaxWinS - 6))
        {
            //read delay unit to write delay unit
            ucLRShift = ((WORD)(uc2NsReadDelayUnit - ucMaxWinWidth) * ucWrToRdDelayUnit + 50) / 100; 

            if(ucLRShift <= ucWriteMove)
            {
                ucLRShiftTemp = ucLRShift;

                if((ucBestWriteCount + ucLRShift) >= ucHighDutyWidth)
                {
                    ucWritePhaseTemp = ucBestWriteCount + ucLRShift - ucHighDutyWidth;
                    bWriteInverR = _TRUE;
                }
                else
                {
                    ucWritePhaseTemp = ucBestWriteCount + ucLRShift;
                    bWriteInverR = _FALSE;
                }
            }
            else
            {
                ucLRShiftTemp = ucWriteMove;

                if((ucBestWriteCount + ucWriteMove) >= ucHighDutyWidth)
                {
                    ucWritePhaseTemp = ucBestWriteCount + ucWriteMove - ucHighDutyWidth;
                    bWriteInverR = _TRUE;
                }
                else
                {
                    ucWritePhaseTemp = ucBestWriteCount + ucWriteMove;
                    bWriteInverR = _FALSE;
                }
            }

            ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucWritePhaseTemp);

            if(bWriteInverR == _TRUE)
            {
                ScalerSetByte(P4_C0_SDR_CLK_DLY1, ScalerGetByte(P4_C0_SDR_CLK_DLY1) ^ 0x80);
            }

            ucBestReadPhase = ((WORD)ucMaxWinS + ucMaxWinE + (WORD)ucLRShiftTemp * 100 / ucWrToRdDelayUnit + 1) >> 1;
            ScalerSetByte(P4_A5_SDR_MEM_TYPE, ucBestSdrCasLatn);
            ScalerSetByte(P4_C3_DQS0_DLY2, ucBestReadPhase);
            ScalerSetByte(P4_C5_DQS1_DLY2, ucBestReadPhase);
            ScalerSDRAMReset();
        }
        else
        {
            ucLRShift = ((WORD)(uc2NsReadDelayUnit - ucMaxWinWidth) * ucWrToRdDelayUnit + 50) / 100;

            if(ucLRShift <= ucWriteMove)
            {
                ucLRShiftTemp = ucLRShift;

                if(ucBestWriteCount < ucLRShift)
                {
                    ucWritePhaseTemp = ucBestWriteCount + (ucMclkCyle - ucHighDutyWidth) - ucLRShift;
                    bWriteInverL = _TRUE;
                }
                else
                {
                    ucWritePhaseTemp = ucBestWriteCount - ucLRShift;
                    bWriteInverL = _FALSE;
                }
            }
            else
            {
                ucLRShiftTemp = ucWriteMove;

                if(ucBestWriteCount < ucWriteMove )
                {
                    ucWritePhaseTemp = ucBestWriteCount + (ucMclkCyle - ucHighDutyWidth) - ucWriteMove;
                    bWriteInverL = _TRUE;
                }
                else
                {
                    ucWritePhaseTemp = ucBestWriteCount - ucWriteMove;
                    bWriteInverL = _FALSE;
                }
            }

            ScalerSetByte(P4_C1_SDR_CLK_DLY2, ucWritePhaseTemp);

            if(bWriteInverL == _TRUE)
            {
                ScalerSetByte(P4_C0_SDR_CLK_DLY1, ScalerGetByte(P4_C0_SDR_CLK_DLY1) ^ 0x80);
            }

            ucBestReadPhase = ((WORD)ucMaxWinS + ucMaxWinE - ((WORD)ucLRShiftTemp * 100 / ucWrToRdDelayUnit)) >> 1;
            ScalerSetByte(P4_A5_SDR_MEM_TYPE, ucBestSdrCasLatn);
            ScalerSetByte(P4_C3_DQS0_DLY2, ucBestReadPhase);
            ScalerSetByte(P4_C5_DQS1_DLY2, ucBestReadPhase);
            ScalerSDRAMReset();
        }
    }

    g_ucSdrClkDly1 = ScalerGetByte(P4_C0_SDR_CLK_DLY1);
    g_ucSdrClkDly2 = ScalerGetByte(P4_C1_SDR_CLK_DLY2);
    g_ucSdrCasLatn = ScalerGetByte(P4_A5_SDR_MEM_TYPE);
    g_ucDqsFineDly = ScalerGetByte(P4_C3_DQS0_DLY2);

    DebugMessageSDRAM("g_ucConflictArea", g_ucConflictArea);
    DebugMessageSDRAM("g_ucSdrClkDly1", g_ucSdrClkDly1);
    DebugMessageSDRAM("g_ucSdrClkDly2", g_ucSdrClkDly2);
    DebugMessageSDRAM("g_ucSdrCasLatn", g_ucSdrCasLatn);
    DebugMessageSDRAM("g_ucDqsFineDly", g_ucDqsFineDly);
    DebugMessageSDRAM("ucWriteMove", ucWriteMove);
    DebugMessageSDRAM("ucSdrDqsFineDlyMax", ucSdrDqsFineDlyMax);
    DebugMessageSDRAM("ucLRShift", ucLRShift);
}

//--------------------------------------------------
// Description  : Check sdram data width
// Input Value  : void
// Output Value : Check result.
//--------------------------------------------------
bit ScalerSDRAM1NsCheck(void)
{
    bit bReadPhaseFlagLeft = _FALSE;
    bit bReadPhaseFlagRight = _FALSE;
    BYTE uc1NsReadDelayUnit = 0;
    BYTE ucSdrDqsFineDlyMax = 0;
    BYTE ucSdrDqsFineDly = 0;
    BYTE ucSdrDqsFineDlyTemp = 0;

    ucSdrDqsFineDlyMax = ScalerSDRAMPhaseCount(_FALSE);

    // Calculate 1.0ns
    uc1NsReadDelayUnit = ((WORD)ucSdrDqsFineDlyMax * _MEMORY_SPEED + 500) / 1000;
    ucSdrDqsFineDly = ScalerGetByte(P4_C3_DQS0_DLY2);

    if((ucSdrDqsFineDly > (8 + (uc1NsReadDelayUnit + 1) >> 1)) && ((ucSdrDqsFineDly + (uc1NsReadDelayUnit + 1) >> 1) <= ucSdrDqsFineDlyMax))
    {
        ucSdrDqsFineDlyTemp = ucSdrDqsFineDly - ((uc1NsReadDelayUnit + 1) >> 1);
        ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDlyTemp);
        ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDlyTemp);
        bReadPhaseFlagLeft = ScalerSDRAMMCUMode(0x00, 0x00, 0x00, _FALSE);

        ucSdrDqsFineDlyTemp = ucSdrDqsFineDly + ((uc1NsReadDelayUnit + 1) >> 1);
        ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDlyTemp);
        ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDlyTemp);
        bReadPhaseFlagRight = ScalerSDRAMMCUMode(0x00, 0x00, 0x00, _FALSE);
    }
    else
    {
        return _FAIL;
    }

    if((bReadPhaseFlagLeft == _FALSE) || (bReadPhaseFlagRight == _FALSE))
    {
        return _FAIL;
    }
    else
    {
        ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly);
        ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDly);
    }

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : SDRAM phase calibration
// Input Value  : void
// Output Value : void.
//--------------------------------------------------
void ScalerSDRAMPhaseSearch(void)
{
    bit bReadPhaseFlag = _FALSE;
    bit b1NSCheckFlag = _FALSE;
    BYTE ucMclkCyle = 0;
    BYTE ucWriteMove = 0;
    BYTE ucHighDutyWidth = 0;
    DWORD ulMclkDutyWriteMove = 0;

    ulMclkDutyWriteMove = ScalerSDRAMWritePhaseSearch();

    if(ulMclkDutyWriteMove > 0)
    {
        ucHighDutyWidth = (BYTE)(ulMclkDutyWriteMove & 0x000000FF);
        ucMclkCyle =  (BYTE)((ulMclkDutyWriteMove & 0x0000FF00) >> 8);
        ucWriteMove = (BYTE)((ulMclkDutyWriteMove & 0x00FF0000) >> 16);

        ScalerSDRAMReadPhaseSearch(ucHighDutyWidth, ucMclkCyle, ucWriteMove);

        bReadPhaseFlag = ScalerSDRAMMCUMode(0x00, 0x00, 0x00, _FALSE);

        if(bReadPhaseFlag == _TRUE)
        {
            b1NSCheckFlag = ScalerSDRAM1NsCheck();
        }
    }

    if((bReadPhaseFlag == _FALSE) || (b1NSCheckFlag == _FALSE) || (ulMclkDutyWriteMove == 0))
    {
        g_ucSdrCasLatn = _SDR_CAS_LATN;
        g_ucSdrClkDly1 = _SDR_CLK_DLY1;
        g_ucSdrClkDly2 = _SDR_CLK_DLY2;
        g_ucDqsFineDly = _SDR_DQS_DLY;
        ScalerSDRAMDefaultPhase();
    }

    ScalerSDRAMDefaultTokenRing();

    //===================
    // Set MCLK spread spectrum function
    //===================
    ScalerSetBit(P0_FC_MCLK_SPREAD_SPECTRUM, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT0), ((_MCLK_SPREAD_SPECTRUM_RANGE << 4) | _BIT2 | _BIT0));
}

//--------------------------------------------------
// Description  : SDRAM phase online
// Input Value  : void
// Output Value : void.
//--------------------------------------------------
void ScalerSDRAMPhaseOnLineTimer(void)
{     
#if(_OD_SUPPORT == _ON)
    bit bODStatus = 0;
#endif   

    if((((g_ucPhaseCycle + 1) % 9) == 0) || ((GET_CAS_CHANGE_STATUS() == _TRUE) && (((g_ucPhaseCycle - 1) % 9) == 0)))
    {
        if(((g_ucPhaseCycle + 1) % 9) == 0)
        {
            // Ready for CAS change
            SET_CAS_CHANGE_STATUS(_FALSE);
        }

        if((GET_CAS_CHANGE_STATUS() == _TRUE) && (((g_ucPhaseCycle - 1) % 9) == 0))
        {
            // SDRAM change CAS
            ScalerSDRAMUpdateCAS(_TRUE);
        }
        else
        {
            ScalerSDRAMUpdateCAS(_FALSE);
        }
    }  
    else if(((g_ucPhaseCycle % 9) == 0 || ((GET_CAS_CHANGE_STATUS() == _TRUE) && (((g_ucPhaseCycle - 2) % 9) == 0))))   
    {

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
#if((_FRC_SUPPORT == _ON) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)))
        // FRC On + 3D PR Case
        if((GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT) ||
           ((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))))
#elif((_FRC_SUPPORT == _OFF) && ((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))) 
        // FRC Off + 3D PR Case
        if(GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT)
#elif((_FRC_SUPPORT == _ON) && (_3D_SUPPORT == _OFF))
        // FRC On Case + 3D Off : 24->60Hz / 24->72Hz uses HW auto 3 block toggle
        if((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF))
#else
        // FRC Off + 3D Shutter Case
        // FRC On + 3D Shutter Case
        if((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && ((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF)))
#endif
        {
                        
#if(_OD_SUPPORT == _ON)
            // Backup OD status
            // Frame sync check P3_A1[7:6]. FRC check CR08[3].
            bODStatus = (bit)(ScalerODGetEnable() | (ScalerGetBit(CM_08_NEW_ADDED_STATUS1, _BIT3)));

            // Disable OD in FRC and all 3D timing(different LR/RL memory layout). 
            if(bODStatus != _OFF)
            {
                // Set OD Off
                ScalerODControl(_OFF);
            }
#endif
                        
            if(GET_MEMORY_DVF_SELECT() == _2_5_IVF)
            {
                // Wait DEN start event
                ScalerTimerWaitForEvent(_EVENT_DEN_START);

                // Get current free run DVS counter
                ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_28_FREE_RUN_DVS_CNT, 1, &pData[0], _NON_AUTOINC);                   
                pData[0] = pData[0] + 1;        
                    
                switch(pData[0])
                {
                    case 5:
                        // Wait DEN start event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                                    
                    case 1:
                        // Wait DEN start event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                                    
                    case 2:
                        // Wait DEN start event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START); 
                                                      
                    case 3:
                        // Wait DEN start event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                                    
                    case 4:
                        if(ScalerSDRAMPhaseOnLine(ScalerSDRAMSelectThreeBlock()) == _FALSE)
                        {
                            DebugMessageSDRAM("SDRAM on line _24_TO_60 fail!", 1);
                        }

                    break;
                                    
                    default:
                        break;                    
                }
            }                    
            else if(GET_MEMORY_DVF_SELECT() == _3_IVF)
            {
                // Wait DEN start event
                ScalerTimerWaitForEvent(_EVENT_DEN_START);

                // Get current free run DVS counter
                ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_28_FREE_RUN_DVS_CNT, 1, &pData[0], _NON_AUTOINC);                    
                pData[0] = pData[0] + 1;        
                    
                switch(pData[0])
                {
                    case 3:
                        // Wait DEN start event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                                    
                    case 1:
                        // Wait DEN start event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);          
                                    
                    case 2:
                        if(ScalerSDRAMPhaseOnLine(ScalerSDRAMSelectThreeBlock()) == _FALSE)
                        {
                            DebugMessageSDRAM("SDRAM on line _3_IVF fail!", 1);
                        } 
                            
                        break;
                                    
                    default:
                            break;                    
                }
            }
            else
            {
                if(ScalerSDRAMPhaseOnLine(g_ulSdrThreeBlockAddr1) == _FALSE)
                {
                    DebugMessageSDRAM("SDRAM read phase 3D FRC case fail!", 1);
                }
            }
                        
#if(_OD_SUPPORT == _ON)
            // Recovery OD status
            if(bODStatus != _OFF)
            {
                ScalerODControl(_ON);
            }
#endif            
        }
        else
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
        {
            if(ScalerSDRAMPhaseOnLine(g_ulSdrThreeBlockAddr1) == _FALSE)
            {
                DebugMessageSDRAM("SDRAM read phase general case fail!", 1);
            }
        }

    } //End of if((g_ucPhaseCycle % 9) == 0) 
            	    
    if(g_ucPhaseCycle >= 20)
    {
        g_ucPhaseCntRef = ScalerSDRAMPhaseCount(_TRUE);   
        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CALIBRATION);
        g_ucPhaseCntCheck = 0;
        ScalerTimerActiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CNT_CHECK);             
    }    
    else 
    {   
        g_ucPhaseCycle++;     
        ScalerTimerActiveTimerEvent(SEC(60), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);
    }    
}

//--------------------------------------------------
// Description  : SDRAM Update CAS latency
// Input Value  : void
// Output Value : void.
//--------------------------------------------------
void ScalerSDRAMUpdateCAS(bit bChangeCasFlag)
{
#if(_OD_SUPPORT == _ON)
    BYTE ucODGain = ScalerGetByte(P3_A3_LS_DELTA_GAIN);
#endif
    
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x00);
   
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~_BIT2, _BIT2);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    if(bChangeCasFlag == _TRUE)
    {
        ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~_BIT1, 0x00);
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        
        ScalerSetByte(P4_A5_SDR_MEM_TYPE, ScalerGetByte(P4_CA_SEC_DQS0_DLY));
        ScalerSetByte(P4_C3_DQS0_DLY2, ScalerGetByte(P4_CB_SEC_DQS1_DLY));
        ScalerSetByte(P4_C5_DQS1_DLY2, ScalerGetByte(P4_CB_SEC_DQS1_DLY));
    }

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP); 

#if(_OD_SUPPORT == _ON)
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, ucODGain);
#endif

    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT3), 0x00);
}


//--------------------------------------------------
// Description  : SDRAM phase count check
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void ScalerSDRAMPhaseCntCheck(BYTE ucCheckTime)
{
    BYTE ucPhaseCntRefTemp = 0;

    if(g_ucPhaseCntCheck >= ucCheckTime)
    {        
        g_ucPhaseCntCheck = 0;
        ScalerSDRAMUpdateCAS(_FALSE);
        ucPhaseCntRefTemp = ScalerSDRAMPhaseCount(_TRUE);

        PDATA_WORD(0) = (WORD)1000 * 50 / _MEMORY_SPEED * 20 / ucPhaseCntRefTemp;
        PDATA_WORD(1) = (WORD)1000 * 50 / _MEMORY_SPEED * 20 / g_ucPhaseCntRef;
        
        // 0.4ns
        if((abs(PDATA_WORD(0) - PDATA_WORD(1)) * ScalerGetByte(P4_C3_DQS0_DLY2)) > 400)  
        {
            g_ucPhaseCycle = 17;
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PHASE_CNT_CHECK);
            ScalerTimerActiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);

            DebugMessageSDRAM("Phase count change too large!!", 1);
        }
        else
        {
            ScalerTimerActiveTimerEvent(SEC(60), _SCALER_TIMER_EVENT_PHASE_CNT_CHECK);
            DebugMessageSDRAM("Next 60 minute!!", 1);
        }
    }
    else
    {
        g_ucPhaseCntCheck++;
        ScalerTimerActiveTimerEvent(SEC(60), _SCALER_TIMER_EVENT_PHASE_CNT_CHECK);
    }       
}

//--------------------------------------------------
// Description  : SDRAM read phase OnLine  Search
// Input Value  : ulAddress    --> SDRAM address
// Output Value : Search result.
//--------------------------------------------------
bit ScalerSDRAMPhaseOnLine(DWORD ulAddress)
{
    bit bPassFlag = _FALSE;
    BYTE ucSdrDqsFineDlyM[2] = {0, 0};
    BYTE ucSdrDqsFineDly[2] = {1, 1};
    BYTE ucLRShift = 1;
    BYTE ucVWidthR = 0;
    BYTE ucVWidthL = 0;
    BYTE ucSdrDqsFineDlyMax = 0;
    BYTE uc1NsReadDelayUnit = 0;
    BYTE ucMcuTokenTemp = 0;
    BYTE ucODGain = 0;

    ucMcuTokenTemp = ScalerGetByte(P4_AB_SDR_RSC_MCU);
    ScalerSetByte(P4_AB_SDR_RSC_MCU, 0xFF);

    ucSdrDqsFineDlyMax = ScalerSDRAMPhaseCount(_TRUE);

    // Claculate 1.0ns
    uc1NsReadDelayUnit = ((WORD)ucSdrDqsFineDlyMax * _MEMORY_SPEED + 500) / 1000;
    ScalerSetBit(P4_BD_SDR_MCU_RD_LEN, ~_BIT7, _BIT7);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    
    ucSdrDqsFineDlyM[0] = ScalerGetByte(P4_C3_DQS0_DLY2);
    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    
    ScalerSDRAMWrPatternOnce(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
    bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

    if(bPassFlag == _TRUE)
    {
        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }
        
        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= (uc1NsReadDelayUnit >> 1)))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= uc1NsReadDelayUnit))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) > ucSdrDqsFineDlyMax)
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);

                    DebugMessageSDRAM("SDRAM change CAS", 1);
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    return _FAIL;  
                }
            }
            else if(ucSdrDqsFineDlyM[0] < (uc1NsReadDelayUnit + g_ucConflictArea))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3) 
                {               
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);

                    DebugMessageSDRAM("SDRAM change CAS", 1);
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    return _FAIL;    
                }
            }
            else
            {
                ScalerSDRAMDefaultPhase();
                return _FAIL;
            }

            return _SUCCESS;    
            
        }
        else
        {
            SET_CAS_CHANGE_STATUS(_FALSE);
            ScalerSDRAMDefaultPhase();
            return _FAIL;
        }
    }

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] <= 1) || (ucLRShift > 10))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == 0)
        {  
    	    break;
        }

        ucVWidthL++;
    }

    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] >= (ucSdrDqsFineDlyMax - 1)) || (ucLRShift > 10))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == 0)
        { 
    	    break;
        }

        ucVWidthR++;
    }
    
    ucVWidthL = ucVWidthL << 1;
    ucVWidthR = ucVWidthR << 1;
    ucSdrDqsFineDly[0] = ((ucSdrDqsFineDlyM[0] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[0]) >> 1);

    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), (_BIT4 | _BIT1));
    ucODGain = ScalerGetByte(P3_A3_LS_DELTA_GAIN);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x00);

    ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly[0]);
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~_BIT0, _BIT0);

    // Wait phase update
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP); 
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, ucODGain);
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), 0x00);

#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
    ucSdrDqsFineDlyM[0] = ScalerGetByte(P4_C3_DQS0_DLY2);
    ucSdrDqsFineDlyM[1] = ScalerGetByte(P4_C5_DQS1_DLY2);
    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);

    ScalerSDRAMWrPatternOnce(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
    bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

    if(bPassFlag == _TRUE)
    {
        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= (uc1NsReadDelayUnit >> 1)) && (ucSdrDqsFineDlyM[1] >= (uc1NsReadDelayUnit >> 1)))            
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax))            
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= uc1NsReadDelayUnit) && (ucSdrDqsFineDlyM[1] >= uc1NsReadDelayUnit))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) > ucSdrDqsFineDlyMax)
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (g_ucConflictArea + ((uc1NsReadDelayUnit  + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);

                    DebugMessageSDRAM("SDRAM change CAS", 1);
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    return _FAIL;  
                }
            }
            else if(ucSdrDqsFineDlyM[0] < (uc1NsReadDelayUnit + g_ucConflictArea))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3) 
                {               
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);

                    DebugMessageSDRAM("SDRAM change CAS", 1);
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    return _FAIL;    
                }
            }
            else
            {
                ScalerSDRAMDefaultPhase();
                return _FAIL;
            }
            
            return _SUCCESS;   
        }
        else
        {
            SET_CAS_CHANGE_STATUS(_FALSE);
            ScalerSDRAMDefaultPhase();
            return _FAIL;
        }
    }

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] <= 1) || (ucSdrDqsFineDly[1] <= 1) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
        
        if(bPassFlag == _FALSE)
        {
            break;
        }
        
        ucVWidthL++;
    }

    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);
    ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
    ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] >= (ucSdrDqsFineDlyMax - 1)) || (ucSdrDqsFineDly[1] >= (ucSdrDqsFineDlyMax - 1)) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _FALSE)
        {
            break;
        }

        ucVWidthR++;
    }
    
    ucVWidthL = ucVWidthL << 1;
    ucVWidthR = ucVWidthR << 1;
    ucSdrDqsFineDly[0] = ((ucSdrDqsFineDlyM[0] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[0]) >> 1);
    ucSdrDqsFineDly[1] = ((ucSdrDqsFineDlyM[1] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[1]) >> 1);
    
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), (_BIT4 | _BIT1));
    ucODGain = ScalerGetByte(P3_A3_LS_DELTA_GAIN);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x00);

    ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly[0]);
    ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDly[1]); 
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~_BIT0, _BIT0);

    // Wait phase update
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP); 
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, ucODGain);
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), 0x00);

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    
    ucSdrDqsFineDlyM[0] = ScalerGetByte(P4_C3_DQS0_DLY2);
    ucSdrDqsFineDlyM[1] = ScalerGetByte(P4_C5_DQS1_DLY2);
    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);

    ScalerSDRAMWrPatternOnce(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
    bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

    if(bPassFlag == _TRUE)
    {
        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= (uc1NsReadDelayUnit >> 1)) && (ucSdrDqsFineDlyM[1] >= (uc1NsReadDelayUnit >> 1)))            
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax))            
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= uc1NsReadDelayUnit) && (ucSdrDqsFineDlyM[1] >= uc1NsReadDelayUnit))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) > ucSdrDqsFineDlyMax)
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (g_ucConflictArea + ((uc1NsReadDelayUnit  + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);

                    DebugMessageSDRAM("SDRAM change CAS", 1);
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    return _FAIL;  
                }
            }
            else if(ucSdrDqsFineDlyM[0] < (uc1NsReadDelayUnit + g_ucConflictArea))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3) 
                {               
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);

                    DebugMessageSDRAM("SDRAM change CAS", 1);
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    return _FAIL;    
                }
            }
            else
            {
                ScalerSDRAMDefaultPhase();
                return _FAIL;
            }
            
            return _SUCCESS;   
        }
        else
        {
            SET_CAS_CHANGE_STATUS(_FALSE);
            ScalerSDRAMDefaultPhase();
            return _FAIL;
        }
    }

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] <= 1) || (ucSdrDqsFineDly[1] <= 1) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
        
        if(bPassFlag == _FALSE)
        {
            break;
        }
        
        ucVWidthL++;
    }

    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);
    ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
    ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] >= (ucSdrDqsFineDlyMax - 1)) || (ucSdrDqsFineDly[1] >= (ucSdrDqsFineDlyMax - 1)) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _FALSE)
        {
            break;
        }

        ucVWidthR++;
    }
    
    ucVWidthL = ucVWidthL << 1;
    ucVWidthR = ucVWidthR << 1;
    ucSdrDqsFineDly[0] = ((ucSdrDqsFineDlyM[0] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[0]) >> 1);
    ucSdrDqsFineDly[1] = ((ucSdrDqsFineDlyM[1] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[1]) >> 1);
    
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), (_BIT4 | _BIT1));
    ucODGain = ScalerGetByte(P3_A3_LS_DELTA_GAIN);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, 0x00);

    ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly[0]);
    ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDly[1]); 
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~_BIT0, _BIT0);

    // Wait phase update
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // Wait _EVENT_DEN_STOP to change P3_A3_LS_DELTA_GAIN
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP); 
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, ucODGain);
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), 0x00);

#else
    #warning "You must set value there."
#endif // End of #if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

    ScalerSetByte(P4_AB_SDR_RSC_MCU, ucMcuTokenTemp);
    DebugMessageSDRAM("On line read ucVWidth", (((WORD)ucVWidthL << 8) | ucVWidthR));

    if((ucVWidthL + ucVWidthR + 1) >= uc1NsReadDelayUnit)
    {
        return _SUCCESS;
    }
    else
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDly[0] - g_ucConflictArea) <= (ucSdrDqsFineDlyMax - ucSdrDqsFineDly[0]))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3) 
                {               
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);

                    DebugMessageSDRAM("SDRAM change CAS", 1);
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    return _FAIL;    
                }
            }
            else
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_CA_SEC_DQS0_DLY, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_CB_SEC_DQS1_DLY, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerTimerReactiveTimerEvent(SEC(10), _SCALER_TIMER_EVENT_PHASE_CALIBRATION);

                    DebugMessageSDRAM("SDRAM change CAS", 1);
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    return _FAIL;  
                }
            }
    
            return _SUCCESS;        
        }
        else
        {
            SET_CAS_CHANGE_STATUS(_FALSE);
            ScalerSDRAMDefaultPhase();
            return _FAIL;       
        }
    }
}

//--------------------------------------------------
// Description  : SDRAM DC on read phase OnLine  Search
// Input Value  : ulAddress    --> SDRAM address
// Output Value : Search result.
//--------------------------------------------------
bit ScalerSDRAMPhaseDCOnCheck(DWORD ulAddress)
{
    bit bPassFlag = _FALSE;
    BYTE ucSdrDqsFineDlyM[2];
    BYTE ucSdrDqsFineDly[2];
    BYTE ucLRShift = 1;
    BYTE ucVWidthR = 0;
    BYTE ucVWidthL = 0;
    BYTE ucSdrDqsFineDlyMax = 0;
    BYTE uc1NsReadDelayUnit = 0;

    ucSdrDqsFineDlyM[0] = 0;
    ucSdrDqsFineDlyM[1] = 0;
    ucSdrDqsFineDly[0] = 1;
    ucSdrDqsFineDly[1] = 1;

    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0x00);
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x00);
    ScalerSetByte(P4_B0_SDR_RSC_RD, 0x00);
    ScalerSetByte(P4_B1_SDR_RSC_WR, 0x00);

    ucSdrDqsFineDlyMax = ScalerSDRAMPhaseCount(_FALSE);

    // Claculate 1.0ns
    uc1NsReadDelayUnit = ((WORD)ucSdrDqsFineDlyMax * _MEMORY_SPEED + 500) / 1000;
    ScalerSetBit(P4_BD_SDR_MCU_RD_LEN, ~_BIT7, _BIT7);

#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
    
    ucSdrDqsFineDlyM[0] = ScalerGetByte(P4_C3_DQS0_DLY2);
    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    
    ScalerSDRAMWrPatternOnce(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
    bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

    if(bPassFlag == _TRUE)
    {
        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }
        
        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= (uc1NsReadDelayUnit >> 1)))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= uc1NsReadDelayUnit))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) > ucSdrDqsFineDlyMax)
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_A5_SDR_MEM_TYPE, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_C3_DQS0_DLY2, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSetByte(P4_C5_DQS1_DLY2, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSDRAMDefaultTokenRing();
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    ScalerSDRAMDefaultTokenRing();
                    return _FAIL;  
                }
            }
            else if(ucSdrDqsFineDlyM[0] < (uc1NsReadDelayUnit + g_ucConflictArea))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3) 
                {               
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_A5_SDR_MEM_TYPE, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_C3_DQS0_DLY2, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSetByte(P4_C5_DQS1_DLY2, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSDRAMDefaultTokenRing();
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    ScalerSDRAMDefaultTokenRing();
                    return _FAIL;    
                }
            }
            else
            {
                ScalerSDRAMDefaultPhase();
                ScalerSDRAMDefaultTokenRing();
                return _FAIL; 
            }

            return _SUCCESS;
        }
        else
        {   
            SET_CAS_CHANGE_STATUS(_FALSE);
            ScalerSDRAMDefaultPhase();
            ScalerSDRAMDefaultTokenRing();
            return _FAIL; 
        }   
    }

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] <= 1) || (ucLRShift > 10))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == 0)
        {  
            break;
        }

        ucVWidthL++;
    }

    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] >= (ucSdrDqsFineDlyMax - 1)) || (ucLRShift > 10))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == 0)
        { 
            break;
        }

        ucVWidthR++;
    }
    
    ucVWidthL = ucVWidthL << 1;
    ucVWidthR = ucVWidthR << 1;
    ucSdrDqsFineDly[0] = ((ucSdrDqsFineDlyM[0] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[0]) >> 1);

    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), 0x00);
    ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly[0]);

#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
    ucSdrDqsFineDlyM[0] = ScalerGetByte(P4_C3_DQS0_DLY2);
    ucSdrDqsFineDlyM[1] = ScalerGetByte(P4_C5_DQS1_DLY2);
    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);

    ScalerSDRAMWrPatternOnce(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
    bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

    if(bPassFlag == _TRUE)
    {
        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= (uc1NsReadDelayUnit >> 1)) && (ucSdrDqsFineDlyM[1] >= (uc1NsReadDelayUnit >> 1)))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= uc1NsReadDelayUnit) && (ucSdrDqsFineDlyM[1] >= uc1NsReadDelayUnit))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) > ucSdrDqsFineDlyMax)
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_A5_SDR_MEM_TYPE, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_C3_DQS0_DLY2, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSetByte(P4_C5_DQS1_DLY2, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSDRAMDefaultTokenRing();
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    ScalerSDRAMDefaultTokenRing();
                    return _FAIL;  
                }
            }
            else if(ucSdrDqsFineDlyM[0] < (uc1NsReadDelayUnit + g_ucConflictArea))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3) 
                {               
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_A5_SDR_MEM_TYPE, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_C3_DQS0_DLY2, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSetByte(P4_C5_DQS1_DLY2, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSDRAMDefaultTokenRing();
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    ScalerSDRAMDefaultTokenRing();
                    return _FAIL;    
                }
            }
            else
            {
                ScalerSDRAMDefaultPhase();
                ScalerSDRAMDefaultTokenRing();
                return _FAIL; 
            }

            return _SUCCESS;
        }
        else
        {   
            SET_CAS_CHANGE_STATUS(_FALSE);
            ScalerSDRAMDefaultPhase();
            ScalerSDRAMDefaultTokenRing();
            return _FAIL; 
        }   
    }

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] <= 1) || (ucSdrDqsFineDly[1] <= 1) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
        
        if(bPassFlag == _FALSE)
        {
            break;
        }
        
        ucVWidthL++;
    }

    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);
    ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
    ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] >= (ucSdrDqsFineDlyMax - 1)) || (ucSdrDqsFineDly[1] >= (ucSdrDqsFineDlyMax - 1)) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _FALSE)
        {
            break;
        }

        ucVWidthR++;
    }
    
    ucVWidthL = ucVWidthL << 1;
    ucVWidthR = ucVWidthR << 1;
    ucSdrDqsFineDly[0] = ((ucSdrDqsFineDlyM[0] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[0]) >> 1);
    ucSdrDqsFineDly[1] = ((ucSdrDqsFineDlyM[1] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[1]) >> 1);
    
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), 0x00);
    ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly[0]);
    ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDly[1]); 

#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    
    ucSdrDqsFineDlyM[0] = ScalerGetByte(P4_C3_DQS0_DLY2);
    ucSdrDqsFineDlyM[1] = ScalerGetByte(P4_C5_DQS1_DLY2);
    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);

    ScalerSDRAMWrPatternOnce(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
    bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

    if(bPassFlag == _TRUE)
    {
        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1)) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= (uc1NsReadDelayUnit >> 1)) && (ucSdrDqsFineDlyM[1] >= (uc1NsReadDelayUnit >> 1)))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (uc1NsReadDelayUnit >> 1);
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (uc1NsReadDelayUnit >> 1);
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax) && ((ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit) <= ucSdrDqsFineDlyMax))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if((ucSdrDqsFineDlyM[0] >= uc1NsReadDelayUnit) && (ucSdrDqsFineDlyM[1] >= uc1NsReadDelayUnit))
        {
            ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - uc1NsReadDelayUnit;
            ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - uc1NsReadDelayUnit;
            ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
            ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);
        }

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _TRUE)
        {
            ucSdrDqsFineDlyM[0] = ucSdrDqsFineDly[0];
            ucSdrDqsFineDlyM[1] = ucSdrDqsFineDly[1];
        }
    }

    if(bPassFlag == _FALSE)
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        {
            if((ucSdrDqsFineDlyM[0] + uc1NsReadDelayUnit) > ucSdrDqsFineDlyMax)
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_A5_SDR_MEM_TYPE, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_C3_DQS0_DLY2, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSetByte(P4_C5_DQS1_DLY2, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSDRAMDefaultTokenRing();
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    ScalerSDRAMDefaultTokenRing();
                    return _FAIL;  
                }
            }
            else if(ucSdrDqsFineDlyM[0] < (uc1NsReadDelayUnit + g_ucConflictArea))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3) 
                {               
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_A5_SDR_MEM_TYPE, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_C3_DQS0_DLY2, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSetByte(P4_C5_DQS1_DLY2, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSDRAMDefaultTokenRing();
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    ScalerSDRAMDefaultTokenRing();
                    return _FAIL;    
                }
            }
            else
            {
                ScalerSDRAMDefaultPhase();
                ScalerSDRAMDefaultTokenRing();
                return _FAIL; 
            }

            return _SUCCESS;
        }
        else
        {   
            SET_CAS_CHANGE_STATUS(_FALSE);
            ScalerSDRAMDefaultPhase();
            ScalerSDRAMDefaultTokenRing();
            return _FAIL; 
        }   
    }

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] <= 1) || (ucSdrDqsFineDly[1] <= 1) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] - (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] - (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));
        
        if(bPassFlag == _FALSE)
        {
            break;
        }
        
        ucVWidthL++;
    }

    ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDlyM[0]);
    ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDlyM[1]);
    ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0];
    ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1];

    for(ucLRShift = 1; ucLRShift < 255; ucLRShift++)
    {
        if((ucSdrDqsFineDly[0] >= (ucSdrDqsFineDlyMax - 1)) || (ucSdrDqsFineDly[1] >= (ucSdrDqsFineDlyMax - 1)) || (ucLRShift > 8))
        {
            break;
        }

        ucSdrDqsFineDly[0] = ucSdrDqsFineDlyM[0] + (ucLRShift << 1);
        ucSdrDqsFineDly[1] = ucSdrDqsFineDlyM[1] + (ucLRShift << 1);
        ScalerSetByte(P4_CA_SEC_DQS0_DLY, ucSdrDqsFineDly[0]);
        ScalerSetByte(P4_CB_SEC_DQS1_DLY, ucSdrDqsFineDly[1]);

        bPassFlag = ScalerSDRAMOnlineMCUMode(((ulAddress >> 16) & 0xFF), ((ulAddress >> 8) & 0xFF), (ulAddress & 0xFF));

        if(bPassFlag == _FALSE)
        {
            break;
        }

        ucVWidthR++;
    }
    
    ucVWidthL = ucVWidthL << 1;
    ucVWidthR = ucVWidthR << 1;
    ucSdrDqsFineDly[0] = ((ucSdrDqsFineDlyM[0] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[0]) >> 1);
    ucSdrDqsFineDly[1] = ((ucSdrDqsFineDlyM[1] - ucVWidthL + ucVWidthR + ucSdrDqsFineDlyM[1]) >> 1);
    
    ScalerSetBit(P4_BE_SDR_PHASE_CAL, ~(_BIT4 | _BIT1), 0x00);
    ScalerSetByte(P4_C3_DQS0_DLY2, ucSdrDqsFineDly[0]);
    ScalerSetByte(P4_C5_DQS1_DLY2, ucSdrDqsFineDly[1]); 

#else
    #warning "You must set value there."
#endif // End of #if(_SDRAM_SIZE_CONFIG == _1M_16BIT)

    DebugMessageSDRAM("DC ON read ucVWidth", (((WORD)ucVWidthL << 8) | ucVWidthR));

    if((ucVWidthL + ucVWidthR + 1) >= uc1NsReadDelayUnit)
    {   
        ScalerSDRAMDefaultTokenRing();
        return _SUCCESS;
    }
    else
    {
        if(GET_CAS_CHANGE_STATUS() == _FALSE)
        { 
            if((ucSdrDqsFineDly[0] - g_ucConflictArea) <= (ucSdrDqsFineDlyMax - ucSdrDqsFineDly[0]))
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) >= 3) 
                {               
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_A5_SDR_MEM_TYPE, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) - 2));
                    ScalerSetByte(P4_C3_DQS0_DLY2, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSetByte(P4_C5_DQS1_DLY2, (ucSdrDqsFineDlyMax - ((uc1NsReadDelayUnit + 1) >> 1)));
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    ScalerSDRAMDefaultTokenRing();
                    return _FAIL;    
                }
            }
            else
            {
                if((ScalerGetByte(P4_A5_SDR_MEM_TYPE) & 0x07) <= 5)
                {
                    SET_CAS_CHANGE_STATUS(_TRUE);
                    ScalerSetByte(P4_A5_SDR_MEM_TYPE, (ScalerGetByte(P4_A5_SDR_MEM_TYPE) + 2));
                    ScalerSetByte(P4_C3_DQS0_DLY2, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                    ScalerSetByte(P4_C5_DQS1_DLY2, (g_ucConflictArea + ((uc1NsReadDelayUnit + 1) >> 1)));
                }
                else
                {
                    ScalerSDRAMDefaultPhase();
                    ScalerSDRAMDefaultTokenRing();
                    return _FAIL;  
                }
            }
    
            ScalerSDRAMDefaultTokenRing();
            return _SUCCESS;        
        }
        else
        {
            SET_CAS_CHANGE_STATUS(_FALSE);
            ScalerSDRAMDefaultPhase(); 
            ScalerSDRAMDefaultTokenRing();
            return _FAIL;       
        }
    }
}
#endif


