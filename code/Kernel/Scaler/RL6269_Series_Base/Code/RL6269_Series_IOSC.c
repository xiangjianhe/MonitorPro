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
// ID Code      : RL6269_Series_IOSC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6269_SERIES_IOSC__

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
void ScalerIOSCTrimming(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Internal Oscillator Triming.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerIOSCTrimming(void)
{
    signed char cTempInx = 0;

#if(_INTERNAL_OSC_XTAL == _IOSC27000K)
    // Disable auto trimming.
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, 0x00);
    
    // 27Mhz
    ScalerSetBit(CM_0B_POWER_CTRL2, ~_BIT0, _BIT0); 

    // Enable IOSC
    ScalerSetBit(P6_A3_EMBEDDED_OSC_CTRL, ~_BIT7, _BIT7); 
    ScalerTimerDelayXms(2);

    // Trim Resolution select, Fosc=counter * Fxtal / 1000
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT5, 0x00); 
    // Wait time for Internal OSC Stable->15*2^10 Tref
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT4, _BIT4); 
    // Wait time for trimming->4*2^10 Tref
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2)); 
    // Set internal oscillator divider(Divider = 1)
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~(_BIT1 | _BIT0), _IOSC_DIV);

    // Trimming comparason target 0x75D
    ScalerSetByte(P6_A1_OSC_TRIM_CTRL1, 0x5D);
    ScalerSetBit(P6_A5_EMB_BGRES, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x07);   

    // Switch to hardware trimming result.
    ScalerSetBit(P6_A2_OSC_TRIM_CTRL2, ~_BIT7, 0x00); 

    // Thermal compensation factor
    ScalerSetBit(P6_A6_EMB_BGRES, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0)); 

    // Enable trimming
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, _BIT7);     

#elif(_INTERNAL_OSC_XTAL == _IOSC14318K)
    // Disable auto trimming.
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, 0x00);

    // 14.318M
    ScalerSetBit(CM_0B_POWER_CTRL2, ~_BIT0, 0x00);

    // Enable IOSC
    ScalerSetBit(P6_A3_EMBEDDED_OSC_CTRL, ~_BIT7, _BIT7);
    ScalerTimerDelayXms(2);

    // Trim Resolution select, Fosc=counter * Fxtal / 2000
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT5, _BIT5);
    // Wait time for Internal OSC Stable->15*2^10 Tref
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT4, _BIT4); 
    // Wait time for trimming->4*2^10 Tref
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));
    // Set internal oscillator divider(Divider = 1)
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~(_BIT1 | _BIT0), _IOSC_DIV);

    // Trimming comparason target 0x7D0
    ScalerSetByte(P6_A1_OSC_TRIM_CTRL1, 0xD0);
    ScalerSetBit(P6_A5_EMB_BGRES, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x07);   

     // Switch to hardware trimming result.
    ScalerSetBit(P6_A2_OSC_TRIM_CTRL2, ~_BIT7, 0x00);

    // Thermal compensation factor
    ScalerSetBit(P6_A6_EMB_BGRES, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0)); 

    // Switch to auto trimming.
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, _BIT7); 
#endif
    //-------Use manual mode go back recheck best step start --------

    // Wait for auto trimming stop, time-consuming ~= 3.36ms
    if(ScalerTimerPollingFlagProc(10, P6_A0_OSC_TRIM_CTRL0, _BIT6, _TRUE) == _FALSE)
    {
        return;
    }

    // Back up final result of auto trimming
    pData[0] = (ScalerGetBit(P6_A2_OSC_TRIM_CTRL2, (_BIT5 | _BIT4 | _BIT3)) >> 3) | (ScalerGetBit(P6_A2_OSC_TRIM_CTRL2, (_BIT2 | _BIT1 | _BIT0)) << 3);

    // Get target iosc cycle counter
    PDATA_WORD(5) = (ScalerGetBit(P6_A5_EMB_BGRES, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | ScalerGetByte(P6_A1_OSC_TRIM_CTRL1);

    // Initial variable
    PDATA_WORD(7) = 0xFFF;

    // Change to manual trimming mode
    ScalerSetBit(P6_A3_EMBEDDED_OSC_CTRL, ~_BIT6, 0x00);
    ScalerSetBit(P6_A2_OSC_TRIM_CTRL2, ~_BIT7, _BIT7);
    
    for(cTempInx = -1; cTempInx < 2; cTempInx++)
    {
        pData[1] = pData[0] + cTempInx;
        pData[2] = ((pData[1] & 0x38) >> 3) | ((pData[1] & 0x07) << 3);

        // Apply trimming step
        ScalerSetBit(P6_A3_EMBEDDED_OSC_CTRL, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[2] & 0x3F);

        // Restart trimming
        ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, 0x00);
        ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, _BIT7);

        // Polling trimming finished, time-cunsuming ~= 440us
        ScalerTimerPollingFlagProc(10, P6_A0_OSC_TRIM_CTRL0, _BIT6, _TRUE);

        // Get iosc cycle counter in current step 
        PDATA_WORD(6) = (ScalerGetBit(P6_A5_EMB_BGRES, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | ScalerGetByte(P6_A4_OSC_TRIM_CNT); 
                
        // Record minimum step
        if(ABSDWORD(PDATA_WORD(6),  PDATA_WORD(5)) < PDATA_WORD(7))
        {
            PDATA_WORD(7) = ABSDWORD(PDATA_WORD(6),  PDATA_WORD(5));
            pData[3] = pData[2];
        }
    }

    // Apply the best trimming step
    ScalerSetBit(P6_A3_EMBEDDED_OSC_CTRL, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[3] & 0x3F);
    //-------Use manual mode go back recheck best step end , total time-consuming ~= 5.36ms ----------
}
