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
// ID Code      : RL6230_Series_VGIP.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6230_SERIES_VGIP__

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
void ScalerVgipInputInitial(BYTE ucSourceType);
void ScalerVgipModifyPolarity(BYTE ucSourceType);

#if(_VGA_SUPPORT == _ON)
void ScalerVgipModifyVsLatchEdge(bit bWait);
#endif

WORD ScalerVgipGetCaptureVStartPosition(void);
WORD ScalerVgipGetCaptureVHeight(void);
WORD ScalerVgipGetCaptureVDelay(void);
void ScalerVgipSetCaptureVDelay(WORD usIVSDelay);
WORD ScalerVgipGetCaptureHStartPosition(void);
WORD ScalerVgipGetCaptureHDelay(void);
void ScalerVgipSetCaptureHDelay(WORD usIHSDelay);
WORD ScalerVgipGetCaptureHWidth(void);
void ScalerVgipDoubleBufferApply(void);
void ScalerVgipDoubleBufferEnable(bit bEn);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initial for VGIP Input
// Input Value  : Input Source Type
// Output Value : None
//--------------------------------------------------
void ScalerVgipInputInitial(BYTE ucSourceType)
{
    // Set Input Pixel Format, Disable Double buffer, Analog Capture, and Start generate DE
    ScalerSetBit(CM_10_VGIP_CTRL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ((ucSourceType == _SOURCE_VGA) ? (_BIT0) : (_BIT2 | _BIT0)));

    // Reset field detect edge; Reset input VS polarity
    ScalerSetBit(CM_11_VGIP_SIGINV, ~(_BIT6 | _BIT5 | _BIT3), 0x00);

    // HS Sync Edge select to Positive, Disable 1 clock Delay Mode
    ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3 | _BIT2), 0x00);
            
    // Initial IVS/IHS Delay for Capture and Auto
    ScalerVgipSetCaptureHDelay(0x00);
    ScalerVgipSetCaptureVDelay(0x00);
}

//--------------------------------------------------
// Description  : Modify HS/VS Polarity
// Input Value  : Input Source Type
// Output Value : None
//--------------------------------------------------
void ScalerVgipModifyPolarity(BYTE ucSourceType)
{
    if(ScalerGetBit(CM_10_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) // VGA measure
    {
        if(((bit)GET_SYNC_H_POLARITY() ^ ScalerGetBit(CM_48_SYNC_INVERT, _BIT5)) == _POSITIVE)
        {        
            // HS No Invert
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT2, 0x00);
        }
        else           
        {
            // HS Invert 
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT2, _BIT2);
        }
    }
    else // Digital source
    {
        if((bit)GET_SYNC_H_POLARITY() == _POSITIVE)
        {        
            // HS No Invert
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT2, 0x00);
        }
        else           
        {
            // HS Invert 
            ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT2, _BIT2);
        }
    }

    if((ucSourceType == _SOURCE_DP) || (((bit)GET_SYNC_V_POLARITY() ^ (bit)ScalerGetBit(CM_4F_STABLE_MEASURE, _BIT2))  == _POSITIVE))
    {  
        // VS No Invert
        ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT3, 0x00);
    }
    else
    {
        // VS Invert
        ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT3, _BIT3);
    }
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify VS latch edge
// Input Value  : Input Source Type
// Output Value : None
//--------------------------------------------------
void ScalerVgipModifyVsLatchEdge(bit bWait)
{
    if(bWait == _WAIT)
    {
        ScalerTimerWaitForEvent(_EVENT_IVS);        
    }

    pData[0] = ScalerGetBit(CM_12_VGIP_DELAY_CTRL, (_BIT7 | _BIT6 | _BIT5));

    // Wait One More Frame in case of Interlaced Mode
    if(pData[0] == 0x00)
    {
        ScalerTimerWaitForEvent(_EVENT_IVS);

        pData[0] = ScalerGetBit(CM_12_VGIP_DELAY_CTRL, (_BIT7 | _BIT6 | _BIT5));        
    }
            
    // If the edge between H-Sync and V-Sync is too close.
    if((pData[0] == 0x00) || (pData[0] == 0xE0) || (pData[0] == 0x80) || (pData[0] == 0xC0))
    {
        // Field detection by hs positive edge 
        ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT5, _BIT5);
        
        // V-Sync latched by H-Sync positive edge
        ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~_BIT2, _BIT2);
    }        
    else
    {
        // Field detection by hs negative edge 
        ScalerSetBit(CM_11_VGIP_SIGINV, ~_BIT5, 0x00);

        // V-Sync latched by H-Sync negative edge
        ScalerSetBit(CM_12_VGIP_DELAY_CTRL, ~_BIT2, 0x00);
    }    
}
#endif

//--------------------------------------------------
// Description  : Get Capture V-Start Position 
// Input Value  : None
// Output Value : Capture Start
//--------------------------------------------------
WORD ScalerVgipGetCaptureVStartPosition(void)
{
    return (((ScalerGetByte(CM_18_IPV_ACT_STA_H) & 0x0F) << 8) | ScalerGetByte(CM_19_IPV_ACT_STA_L));
}

//--------------------------------------------------
// Description  : Get Capture V-Height Position 
// Input Value  : None
// Output Value : Capture Start
//--------------------------------------------------
WORD ScalerVgipGetCaptureVHeight(void)
{
    return (((ScalerGetByte(CM_18_IPV_ACT_STA_H) & 0xF0) << 4) | ScalerGetByte(CM_1B_IPV_ACT_LEN_L));
}

//--------------------------------------------------
// Description  : Get Capture V Delay 
// Input Value  : None
// Output Value : Capture V Delay
//--------------------------------------------------
WORD ScalerVgipGetCaptureVDelay(void)
{   
    return ((((WORD)(ScalerGetByte(CM_1E_VGIP_HV_DELAY) & _BIT1)) << 7) | ScalerGetByte(CM_1C_IVS_DELAY));    
}

//--------------------------------------------------
// Description  : Set Capture V Delay 
// Input Value  : usIVSDelay --> V Delay
// Output Value : None
//--------------------------------------------------
void ScalerVgipSetCaptureVDelay(WORD usIVSDelay)
{  
    ScalerSetBit(CM_1E_VGIP_HV_DELAY, ~_BIT1, (usIVSDelay >> 7) & _BIT1);
    ScalerSetByte(CM_1C_IVS_DELAY, LOBYTE(usIVSDelay));
}

//--------------------------------------------------
// Description  : Get Capture H-Start Position 
// Input Value  : None
// Output Value : Capture H Start
//--------------------------------------------------
WORD ScalerVgipGetCaptureHStartPosition(void)
{
    return ((((ScalerGetByte(CM_14_IPH_ACT_STA_H) & 0x0F) << 8) | ScalerGetByte(CM_15_IPH_ACT_STA_L)) + 2);
}

//--------------------------------------------------
// Description  : Set Capture V Delay 
// Input Value  : usIHSDelay --> H Delay
// Output Value : None
//--------------------------------------------------
void ScalerVgipSetCaptureHDelay(WORD usIHSDelay)
{
    if(usIHSDelay > _VGIP_IH_DELAY_MAX_VALUE) 
    {          
        ScalerIDomainFineTuneHCaptureStart(usIHSDelay - _VGIP_IH_DELAY_MAX_VALUE);

        usIHSDelay = _VGIP_IH_DELAY_MAX_VALUE;
    }

    ScalerSetBit(CM_1E_VGIP_HV_DELAY, ~_BIT0, HIBYTE(usIHSDelay) & _BIT0);
    ScalerSetByte(CM_1D_IHS_DELAY, LOBYTE(usIHSDelay));
}

//--------------------------------------------------
// Description  : Get Capture V Delay 
// Input Value  : None
// Output Value : H Delay
//--------------------------------------------------
WORD ScalerVgipGetCaptureHDelay(void)
{
    return (((ScalerGetByte(CM_1E_VGIP_HV_DELAY) & _BIT0) << 8) | ScalerGetByte(CM_1D_IHS_DELAY));
}

//--------------------------------------------------
// Description  : Get Capture H Width
// Input Value  : None
// Output Value : H capture Width
//--------------------------------------------------
WORD ScalerVgipGetCaptureHWidth(void)
{
    return (((ScalerGetByte(CM_14_IPH_ACT_STA_H) & 0xF0) << 4) | ScalerGetByte(CM_17_IPH_ACT_WID_L));
}

//--------------------------------------------------
// Description  : Apply double buffer
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerVgipDoubleBufferApply(void)
{
    if((bit)ScalerGetBit(CM_10_VGIP_CTRL, _BIT4))
    {
        ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5);

        ScalerTimerPollingFlagProc(60, CM_10_VGIP_CTRL, _BIT5, _FALSE);
    }
}

//--------------------------------------------------
// Description  : Disable double buffer
// Input Value  : bEn --> _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerVgipDoubleBufferEnable(bit bEn)
{
    if(bEn == _ENABLE)
    {
        ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT4, _BIT4);
    }
    else
    {
        ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT4, 0x00);
    }
}
