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
// ID Code      : RL6373_Series_ELED.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6373_SERIES_LCTANK__

#include "ScalerFunctionInclude.h"

#if(_LC_TANK_SUPPORT == _ON)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _ONE_DEGREE_GAP                 6100
//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
DWORD g_ulInitialActiveRegionCount = 0;
DWORD g_ulCurrentActiveRegionCount = 0;
WORD g_usDpllInitialOffset = 0;
WORD g_usInitialThermalCode = 0;
DWORD g_ulInitialDacpllNFCode = 0;
DWORD g_ulCurrentDacpllNFCode = 0;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerLCTankInitial(void);
void ScalerLCTankFrequencyCalibation(void);
WORD ScalerLCTankGetClock(void);
void ScalerPowerLCTankPower(BYTE ucOn);
void ScalerLCTankDpllOffsetRegulationInitial(void);
void ScalerLCTankDpllOffsetRegulation_TIMER1(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : LC Tank Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerLCTankInitial(void)
{
#if 0 // output the LC tank freq.

    ScalerSetByte(P10_AA_PIN_SHARE_CTRL0A, 0x09);
    ScalerSetDataPortByte(CM_8D_PS_ACCESS_PORT, _CM_8E_PT_00_PS_TEST_MODE, 0x0E);
    ScalerSetDataPortByte(CM_8D_PS_ACCESS_PORT, 0x0E, 0x80);
    ScalerSetDataPortByte(CM_8D_PS_ACCESS_PORT, 0x10, 0xD0);

#endif
    
    // Set Resolution to 9.10
    ScalerSetBit(P65_A7_T_SENSOR_CONFIG,~(_BIT7 | _BIT6), 0);

    // Get Initial Thermal Code from efuse
    ScalerRead(P24_AC_EFUSE_DATA6, 3, pData, _AUTOINC); 
    if((pData[0] == 0x00) && (pData[1] == 0x00) && (pData[2] == 0x00))
    {
        // Initial to 40 degree (40+273=333)
        g_usInitialThermalCode = 313;   
    }
    else
    {
        if(pData[0] == 0x02)
        {
            g_usInitialThermalCode = PDATA_DWORD(0) >> 17;
        }
        else if(pData[0] == 0x04)
        {
            g_usInitialThermalCode = PDATA_DWORD(0) >> 18;
        }
    }
    
    // Get Initial DAC PLL N.F Code (Prototype : 0x0NNFFFFF)
    ScalerRead(P24_AF_EFUSE_DATA9, 5, pData, _AUTOINC);

    if((pData[4] & 0x0F) == 0x00)
    {
        ScalerSetBit(P66_B1_LC_CTRL0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
    }
    else
    {
        ScalerSetBit(P66_B1_LC_CTRL0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (pData[4] & 0x0F));
    }

    if((pData[0] == 0x00) && (pData[1] == 0x00) && (pData[2] == 0x00) && (pData[3] == 0x00))
    {
        g_ulInitialDacpllNFCode = 0x22059039;
    }
    else
    {
        g_ulInitialDacpllNFCode = PDATA_DWORD(0);
    }

    g_ulCurrentDacpllNFCode = g_ulInitialDacpllNFCode;
    
    // Write DAC PLL N.F to register
    ScalerSetByte(P66_AA_TRACKING_1, (BYTE)((g_ulCurrentDacpllNFCode & 0xFF000000) >> 24));
    ScalerSetByte(P66_AB_TRACKING_2, (BYTE)((g_ulCurrentDacpllNFCode & 0x00FF0000) >> 16));
    ScalerSetByte(P66_AC_TRACKING_3, (BYTE)((g_ulCurrentDacpllNFCode & 0x0000FF00) >> 8));
    ScalerSetByte(P66_AD_TRACKING_4, (BYTE)((g_ulCurrentDacpllNFCode & 0x000000FF)));
    ScalerSetBit(P66_A9_LOAD_NF_CODE, ~_BIT0, _BIT0);

    // Initial A!EAlpha = 8882 (08AC8000)
    ScalerSetByte(P65_A9_T_SENSOR_A_ALPHA_1,0x08);
    ScalerSetByte(P65_AA_T_SENSOR_A_ALPHA_2,0xAC);
    ScalerSetByte(P65_AB_T_SENSOR_A_ALPHA_3,0x80);
    ScalerSetByte(P65_AC_T_SENSOR_A_ALPHA_4,0x00);

    // Initial B (offset) = -52 (0x3E6000)
    ScalerSetByte(P65_AD_T_SENSOR_B_1,0x3E);
    ScalerSetByte(P65_AE_T_SENSOR_B_2,0x60);
    ScalerSetByte(P65_AF_T_SENSOR_B_3,0x00);

    // Initial Alpha-Beta-Gamma = 8.1 (0x40C631)
    ScalerSetByte(P65_B0_T_SENSOR_R_1,0x40);
    ScalerSetByte(P65_B1_T_SENSOR_R_2,0xC6);
    ScalerSetByte(P65_B2_T_SENSOR_R_3,0x31);

    // Initial Beta = 0x200000
    ScalerSetByte(P65_B3_T_SENSOR_S_1,0x20);
    ScalerSetByte(P65_B4_T_SENSOR_S_2,0x00);
    ScalerSetByte(P65_B5_T_SENSOR_S_3,0x00);
    
    // Initial DC offset = 0x200000
    ScalerSetByte(P65_B7_T_SENSOR_DC_OFFSET_1,0x20);
    ScalerSetByte(P65_B8_T_SENSOR_DC_OFFSET_2,0x00);
    ScalerSetByte(P65_B9_T_SENSOR_DC_OFFSET_3,0x00);
}

//--------------------------------------------------
// Description  : LC Tank Frequency Calibration
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerLCTankFrequencyCalibation(void)
{
    WORD usThermalCode = 0;

    // Enable Measure Thermal Sensor Measure
    ScalerSetBit(P65_BD_T_SENSOR_CT_OUT1, ~_BIT7, _BIT7);

    // Pop Up Thermal Sensor thermal code
    if(ScalerTimerPollingFlagProc(100, P65_BD_T_SENSOR_CT_OUT1, _BIT7, _FALSE))
    {
        usThermalCode = ((WORD)((((WORD)ScalerGetByte(P65_BD_T_SENSOR_CT_OUT1) & 0x07) << 8) | ((WORD)ScalerGetByte(P65_BE_T_SENSOR_CT_OUT2))) / 4);
    }
    else
    {
        return;
    }

    if(usThermalCode > g_usInitialThermalCode)
    {
        PDATA_DWORD(0) = g_ulInitialDacpllNFCode + (DWORD)(usThermalCode - g_usInitialThermalCode) * _ONE_DEGREE_GAP;

        // Get new DAC PLL NF code
        for(pData[10] = ((BYTE)((PDATA_DWORD(0) & 0x00F00000) >> 20)); pData[10] > 0; pData[10]--)
        {
            if(((BYTE)((PDATA_DWORD(0) & 0x00F00000) >> 20)) > 0)
            {
                PDATA_DWORD(0) += 16777216;
            }
        }
    }
    else
    {
        PDATA_DWORD(0) = g_ulInitialDacpllNFCode - (DWORD)(g_usInitialThermalCode - usThermalCode) * _ONE_DEGREE_GAP;
    }

    // Write DAC PLL N.F to register
    ScalerSetByte(P66_AA_TRACKING_1, (BYTE)((PDATA_DWORD(0) & 0xFF000000) >> 24));
    ScalerSetByte(P66_AB_TRACKING_2, (BYTE)((PDATA_DWORD(0) & 0x00FF0000) >> 16));
    ScalerSetByte(P66_AC_TRACKING_3, (BYTE)((PDATA_DWORD(0) & 0x0000FF00) >> 8));
    ScalerSetByte(P66_AD_TRACKING_4, (BYTE)((PDATA_DWORD(0) & 0x000000FF)));
    
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerSetBit(P66_A9_LOAD_NF_CODE, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : None
// Input Value  : None
// Output Value : None
//--------------------------------------------------
WORD ScalerLCTankGetClock(void)
{
    WORD usThermalCode = 0;
    WORD usXTAL = 0;

    // Enable Measure Thermal Sensor Measure
    ScalerSetBit(P65_BD_T_SENSOR_CT_OUT1, ~_BIT7, _BIT7);

    // Pop Up Thermal Sensor thermal code
    if(ScalerTimerPollingFlagProc(100, P65_BD_T_SENSOR_CT_OUT1, _BIT7, 0))
    {
        usThermalCode = (((WORD)ScalerGetByte(P65_BD_T_SENSOR_CT_OUT1) & 0x0007) << 6) | (((WORD)ScalerGetByte(P65_BE_T_SENSOR_CT_OUT2) & 0x00FF) >> 2);
    }
    else
    {
        return _XTAL14318K;   
    }
    

    // **********  Calculate current clock & return **********
    if(g_usInitialThermalCode > usThermalCode)
    {
        usXTAL = _XTAL14318K + (g_usInitialThermalCode - usThermalCode) * 23 / 10;
    }
    else
    {
        usXTAL = _XTAL14318K - (usThermalCode - g_usInitialThermalCode) * 23 / 10;
    }

    return ((WORD)usXTAL);
}

//--------------------------------------------------
// Description  : LC Tank Power
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerLCTankPower(BYTE ucOn)
{
    if(ucOn == _ON)
    {
        // Enable LC Tank & LDO Power
        ScalerSetBit(P66_B5_LC_CTRL4, ~(_BIT7 | _BIT5), (_BIT7 | _BIT5));

        // Enable DAC PLL Power
        ScalerSetBit(P66_A3_PLL_5, ~_BIT5, _BIT5);

        // Enable DAC PLL LDO Power
        ScalerSetBit(P66_A4_PLL_6, ~_BIT3, _BIT3);

        // Enable Thermal Sensor Power
        ScalerSetBit(P65_A0_T_SENSOR_BIAS, ~_BIT3, _BIT3);

    }
    else
    {
        // Disable LC Tank & LDO Power
        ScalerSetBit(P66_B5_LC_CTRL4, ~(_BIT7 | _BIT5), 0x00);

        // Disable DAC PLL Power
        ScalerSetBit(P66_A3_PLL_5, ~_BIT5, 0x00);

        // Disable DAC PLL LDO Power
        ScalerSetBit(P66_A4_PLL_6, ~_BIT3, 0x00);

        // Disable Thermal Sensor Power
        ScalerSetBit(P65_A0_T_SENSOR_BIAS, ~_BIT3, 0x00);

    }
}

//--------------------------------------------------
// Description  : Store initial active region count & DPLL offset status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerLCTankDpllOffsetRegulationInitial(void)
{
    // Enable active region measure
    ScalerSetBit(CM_50_STABLE_PERIOD_H, ~_BIT4, _BIT4);

    // Set active region target to "input active region"
    ScalerSetBit(CM_47_SYNC_SELECT, ~_BIT1, 0x00);
    ScalerSetBit(CM_5A_SYNC_TEST_MISC, ~(_BIT5 | _BIT4), 0x00);

    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);

    // Pop out active region measure result
    ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT6, _BIT6);
    ScalerSetByte(CM_59_MEAS_ACTIVE_REGION_H, 0x00);

    // Get Input Active Measure Clk Count
    ((BYTE *)(&g_ulInitialActiveRegionCount))[0] = 0;
    ((BYTE *)(&g_ulInitialActiveRegionCount))[1] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
    ((BYTE *)(&g_ulInitialActiveRegionCount))[2] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
    ((BYTE *)(&g_ulInitialActiveRegionCount))[3] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);        

    // Store initial DPLL offset
    g_usDpllInitialOffset = 32768 - (((WORD)(ScalerGetByte(P1_C4_DCLK_FINE_TUNE_OFFSET_MSB) & 0x0F) << 8) | ScalerGetByte(P1_C5_DCLK_FINE_TUNE_OFFSET_LSB));

    g_ulCurrentActiveRegionCount = g_ulInitialActiveRegionCount;

}

//--------------------------------------------------
// Description  : Regulate DPLL offset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerLCTankDpllOffsetRegulation_TIMER1(void)
{
    DWORD ulDiffOffsetNew;
    DWORD ulLocalCount;

    // Skip regulation if not in frame sync mode, or being forced to background color
    if(ScalerGetBit(CM_28_VDISP_CTRL, (_BIT5 | _BIT3)) == _BIT3)
    {
        // Pop out current region count
        ScalerSetBit(CM_52_MEAS_HS_PER_H, ~_BIT6, _BIT6);
        ScalerSetByte(CM_59_MEAS_ACTIVE_REGION_H, 0x00);

        // Get Input Active Measure Clk Count
        ((BYTE *)(&ulLocalCount))[0] = 0;
        ((BYTE *)(&ulLocalCount))[1] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
        ((BYTE *)(&ulLocalCount))[2] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);
        ((BYTE *)(&ulLocalCount))[3] = ScalerGetByte(CM_59_MEAS_ACTIVE_REGION_H);        

        // Skip regulation when active count difference is too small
        if(ABSDWORD(g_ulCurrentActiveRegionCount, ulLocalCount) > 0x08)
        {
            // Update current count
            g_ulCurrentActiveRegionCount = ulLocalCount;

            /////////////////////////////////////////////////////////////////////////
            // DiffOffset_New = (global count) * DiffOffset_global / (current count);
            /////////////////////////////////////////////////////////////////////////
            ulDiffOffsetNew = (((((BYTE *)(&g_ulInitialActiveRegionCount))[1]) * (DWORD)g_usDpllInitialOffset) << 8);
            ulDiffOffsetNew = ((ulDiffOffsetNew / g_ulCurrentActiveRegionCount) << 8) + (((ulDiffOffsetNew % g_ulCurrentActiveRegionCount) << 8) / g_ulCurrentActiveRegionCount);
            ulDiffOffsetNew += ((DWORD)g_usDpllInitialOffset * (((WORD *)(&g_ulInitialActiveRegionCount))[1])) / g_ulCurrentActiveRegionCount;

            // Calculate new offset = 32768 - (offset diff + 1)
            ((BYTE *)(&ulDiffOffsetNew))[2] = ~(((BYTE *)(&ulDiffOffsetNew))[2]);
            ((BYTE *)(&ulDiffOffsetNew))[3] = ~(((BYTE *)(&ulDiffOffsetNew))[3]);

            // Apply DPLL Offset for last-line
            ScalerSetBit(P1_C4_DCLK_FINE_TUNE_OFFSET_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (((BYTE *)(&ulDiffOffsetNew))[2]) & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
            ScalerSetByte(P1_C5_DCLK_FINE_TUNE_OFFSET_LSB, ((BYTE *)(&ulDiffOffsetNew))[3]);
            ScalerSetBit(P1_C6_DCLK_SPREAD_SPECTRUM, ~_BIT2, _BIT2);
        }
    }

#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)

    if(((ScalerGetByte(P16_D9_LEDBC_ABNORMAL_STATUS_3) & _BIT0) + ((ScalerGetByte(P16_D9_LEDBC_ABNORMAL_STATUS_3) & _BIT1) >> 1) +
        ((ScalerGetByte(P16_D9_LEDBC_ABNORMAL_STATUS_3) & _BIT2) >> 2) + ((ScalerGetByte(P16_D9_LEDBC_ABNORMAL_STATUS_3) & _BIT3) >> 3)) >= 2)
    {
        // LED_OPEN De-bounce Time 144us
        ScalerSetBit(P16_C5_LEDBC_ADVREF3, ~(_BIT6 | _BIT5), _BIT5);

        // OVP Set To Max Value
        ScalerSetBit(P16_C1_LEDBC_ADVREF7, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2));
    }

    if(((ScalerGetByte(P16_D9_LEDBC_ABNORMAL_STATUS_3) & _BIT0) + ((ScalerGetByte(P16_D9_LEDBC_ABNORMAL_STATUS_3) & _BIT1) >> 1) +
        ((ScalerGetByte(P16_D9_LEDBC_ABNORMAL_STATUS_3) & _BIT2) >> 2) + ((ScalerGetByte(P16_D9_LEDBC_ABNORMAL_STATUS_3) & _BIT3) >> 3)) >= 3)
    {
        // Check All Short happened or not
        if(ScalerGetBit(P16_AD_LEDBC_ANALOG_RESERVED_6, _BIT1) == _BIT1)
        {
            // Disable LED Booster En
            ScalerSetBit(P16_A0_LEDBC_DRIVER_CTRL1, ~_BIT5, 0x00);
        }
    }

#endif

}
#endif // End of #if(_LC_TANK_SUPPORT == _ON)