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
// ID Code      : RL6192_Series_SyncProc.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6192_SERIES_SYNCPROC__

#include "ScalerFunctionInclude.h"

#if(_VGA_SUPPORT == _ON)
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
void ScalerSyncProcClampPosSetting(WORD usClampPosStart, WORD usClampPosEnd);
WORD ScalerSyncProcGetClampEndPosition(void);
void ScalerSyncProcClearSyncChangeStatus(void);
WORD ScalerSyncProcMeasureIHFreqByStableMeasure(void);
void ScalerSyncProcPulseDetectEnable(BYTE ucEnable);
void ScalerSyncProcSetDebounce(BYTE ucDebounce);

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
void ScalerSyncProcSetPorchVoltage(void);
bit ScalerSyncProcCheckPorchChange(void);
#endif

void ScalerSyncProcDownCounterSetting(void);
DWORD ScalerSyncProcGetCurrentClockFreq(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Clamp Position setting
// Input Value  : usClampPosStart --> Clamp Position Start
//                  usClampPosEnd --> Clamp Position End
// Output Value : None
//--------------------------------------------------
void ScalerSyncProcClampPosSetting(WORD usClampPosStart, WORD usClampPosEnd)
{
    // Y/G Clamp Position LSB
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_00_SYNC_G_CLAMP_START, LOBYTE(usClampPosStart));
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_01_SYNC_G_CLAMP_END, LOBYTE(usClampPosEnd));
 
    // Pb/B Clamp Position LSB
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_02_SYNC_BR_CLAMP_START, LOBYTE(usClampPosStart));
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_03_SYNC_BR_CLAMP_END, LOBYTE(usClampPosEnd));

    // Y/G Clamp Position MSB
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_0D_G_CLAMP_START_H, (((HIBYTE(usClampPosStart) << 4) & 0xF0) | (HIBYTE(usClampPosEnd) & 0x0F)));

    // Pb/B Clamp Position MSB
    ScalerSetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_0E_BR_CLAMP_START_H, (((HIBYTE(usClampPosStart) << 4) & 0xF0) | (HIBYTE(usClampPosEnd) & 0x0F)));
}

//--------------------------------------------------
// Description  : Get Clamp End Position
// Input Value  : None
// Output Value : Clamp Position End
//--------------------------------------------------
WORD ScalerSyncProcGetClampEndPosition(void)
{
    // Get Y/G clamp end position
    pData[0] = ScalerGetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_0D_G_CLAMP_START_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0));    
    ScalerGetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_01_SYNC_G_CLAMP_END, 1, &pData[1], _NON_AUTOINC);    

    // Get BR/PbPr clamp end position
    pData[2] = ScalerGetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_0E_BR_CLAMP_START_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0));    
    ScalerGetDataPortByte(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_03_SYNC_BR_CLAMP_END, 1, &pData[3], _NON_AUTOINC);    

    // Return the larger clamp end
    if(PDATA_WORD(0) > PDATA_WORD(1))
    {
        return PDATA_WORD(0);
    }
    else
    {
        return PDATA_WORD(1);        
    }
}

//-------------------------------------------------------------------
// Description  : Clear Sync change status
// Input Value  : None
// Output Value : None
//-------------------------------------------------------------------
void ScalerSyncProcClearSyncChangeStatus(void) 
{
    ScalerSetBit(CM_4E_HSYNC_TYPE_DETECTION_FLAG, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));
}

//-------------------------------------------------------------------
// Description  : Calculate H freq by stable measure
// Input Value  : None
// Output Value : H Freq
//-------------------------------------------------------------------
WORD ScalerSyncProcMeasureIHFreqByStableMeasure(void)
{
    // Calculate input H-Sync Frequency
    return (WORD)((_SYNC_PROC_CLK * 10 * 2 / (((WORD)(ScalerGetByte(CM_50_STABLE_PERIOD_H) & 0x07) << 8) | ScalerGetByte(CM_51_STABLE_PERIOD_L)) + 1) / 2);
}

//-------------------------------------------------------------------
// Description  : Enable / disable sync pulse detect
// Input Value  : Enbale or disable detect
// Output Value : None
//-------------------------------------------------------------------
void ScalerSyncProcPulseDetectEnable(BYTE ucEnable)
{
    if(ucEnable == _ENABLE)
    {
        ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_19_HS_DETECT_SETTING, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    }
    else
    {
        ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_19_HS_DETECT_SETTING, ~(_BIT7 | _BIT6), 0x00);
    }
}

//-------------------------------------------------------------------
// Description  : Set sync detect debounce
// Input Value  : Debounce width
// Output Value : None
//-------------------------------------------------------------------
void ScalerSyncProcSetDebounce(BYTE ucDebounce)
{
    // Set input H-Sync Debounce width for decomposite & stable measure & auto run block
    ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_09_SYNC_DETECT_TOLERANCE_SET, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ucDebounce & 0x1F);

    // Set input H-Sync debounce for predetect 
    ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_19_HS_DETECT_SETTING, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucDebounce & 0x0F);
}

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initial porch voltage check for non-SOG sync type
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncProcSetPorchVoltage(void)
{
    // NOP for sync type SOG
    if(ScalerGetBit(CM_47_SYNC_SELECT, _BIT4) != _BIT4)
    {    
        // Power up SOG 
        ScalerSetBit(P0_C6_ADC_POWER, ~_BIT5, _BIT5);

        // Set SOG detect debounce to 0x0F; Enable SOG detect
        ScalerSetDataPortBit(CM_5C_SYNC_PROC_ACCESS_PORT, _CM_5D_PT_19_HS_DETECT_SETTING, ~(_BIT6 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
        
        // Set SOG compare level to 0
        ScalerSetByte(P0_D7_ADC_SOG_DAC_SOY_CONTROL, 0x00);

        // Clear SOG detect flag
        ScalerSetBit(CM_5B_HS_DETECT, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    } 
}

//--------------------------------------------------
// Description  : Monitor porch voltage status change
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerSyncProcCheckPorchChange(void)
{
    BYTE ucIndex = 3;

    // Check SOG detect flag only for non-SOG cases
    if(ScalerGetBit(CM_47_SYNC_SELECT, _BIT4) == 0x00)
    {
        do
        {
            // Check if clamp-to-top status is inline with SOG detect flag
            if(((ScalerGetBit(CM_5B_HS_DETECT, _BIT6) == 0x00) ^ (ScalerGetBit(P0_D6_ADC_CLAMP_CTRL2, (_BIT2 | _BIT1 | _BIT0)) == 0x00)) == _TRUE)
            {
                // Clear SOG detect flag
                ScalerSetBit(CM_5B_HS_DETECT, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

                --ucIndex;    

                if(ucIndex == 0x00)
                {
                    break;
                }

                // Wait for some time; 
                ScalerTimerDelayXms(2);        
            }
            else
            {
                break;
            }
        }
        while(ucIndex != 0x00);

        // Clear SOG detect flag
        ScalerSetBit(CM_5B_HS_DETECT, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));            
    }

    return (ucIndex == 0x00);
}
#endif

//--------------------------------------------------
// Description  : Down counter Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncProcDownCounterSetting(void)
{
    // Down Counter reference  CR4C[2:0] + CR4D[7:0]
    ScalerSetBit(CM_5B_HS_DETECT, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

    // Pop Up Stable Value
    ScalerSetBit(CM_4F_STABLE_MEASURE, ~_BIT1, _BIT1);

    // Get 1/3 stable period
    PDATA_WORD(0) = ((((WORD)(ScalerGetByte(CM_50_STABLE_PERIOD_H) & 0x07) << 8) | ScalerGetByte(CM_51_STABLE_PERIOD_L)) + 1) / 3;

    // Set VSync Counter level
    ScalerSetBit(CM_4C_VSYNC_COUNTER_LEVEL_MSB, ~(_BIT2 | _BIT1 | _BIT0), (BYTE)(PDATA_WORD(0) >> 8) & 0x07);
    ScalerSetByte(CM_4D_VSYNC_COUNTER_LEVEL_LSB, (BYTE)(PDATA_WORD(0)));
}

//--------------------------------------------------
// Description  : Get Current Sync Proc Clock Frequency
// Input Value  : None
// Output Value : Return Current Sync Proc Clock
//--------------------------------------------------
DWORD ScalerSyncProcGetCurrentClockFreq(void)
{
    return _SYNC_PROC_CLK;
}

#endif // End of #if(_VGA_SUPPORT == _ON)


