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
// ID Code      : RL6229_Series_VGIP.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6229_SERIES_VGIP__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

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

#if(_3D_SUPPORT == _ON)
void ScalerVgipMaskFunctionEnable(EnumMaskTypeDef enumMaskType, bit bMaskEnable);
void ScalerVgipMaskActiveSpace(EnumMaskActiveSpaceNum enumActiveSpaceNum, WORD usPosition, WORD usLength);
void ScalerVgipMaskSignal(void);
#endif

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
    // Let IHStart Can be Smaller (Make FP Block Reference to HS Rising)
    ScalerSetBit(CM_16_IPH_ACT_WID_H, ~_BIT0, _BIT0);
        
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
#endif // #if(_VGA_SUPPORT == _ON)

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

#if(_3D_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Set VGIP Mask Active Space
// Input Value  : mask start pos and length
// Output Value : None
//--------------------------------------------------
void ScalerVgipMaskFunctionEnable(EnumMaskTypeDef enumMaskType, bit bMaskEnable)
{
    if(bMaskEnable == _ENABLE)
    {     
        ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (((enumMaskType & (_BIT2 | _BIT1 | _BIT0)) << 1) | _BIT0));
    }
    else
    {
        ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_0, 0x00, 0x00);
        ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_1, 0x00, 0x00);
        ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_2, 0x00, 0x00);
        ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_3, 0x00, 0x00); 
    }
}

//--------------------------------------------------
// Description  : Set VGIP Mask Active Space
// Input Value  : mask start pos and length
// Output Value : None
//--------------------------------------------------
void ScalerVgipMaskActiveSpace(EnumMaskActiveSpaceNum enumActiveSpaceNum, WORD usPosition, WORD usLength)
{
    switch(enumActiveSpaceNum)
    {
        case _MASK_ACTIVE_SPACE_0:

            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_20_ACTIVE_SPACE_LINE0_M, (((HIBYTE(usLength) & 0x0F) << 4) | ((HIBYTE(usPosition) & 0x0F))));
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_21_ACTIVE_SPACE_LINE0_L, LOBYTE(usPosition));
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_22_ACTIVE_SPACE_LEN0_L, LOBYTE(usLength));
            
            break;
            
        case _MASK_ACTIVE_SPACE_1:

            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_23_ACTIVE_SPACE_LINE1_M, (((HIBYTE(usLength) & 0x0F) << 4) | ((HIBYTE(usPosition) & 0x0F))));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_24_ACTIVE_SPACE_LINE1_L, LOBYTE(usPosition));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_25_ACTIVE_SPACE_LEN1_L, LOBYTE(usLength));                  

            break;

        case _MASK_ACTIVE_SPACE_2:
            
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_26_ACTIVE_SPACE_LINE2_M, (((HIBYTE(usLength) & 0x0F) << 4) | ((HIBYTE(usPosition) & 0x0F))));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_27_ACTIVE_SPACE_LINE2_L, LOBYTE(usPosition));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_28_ACTIVE_SPACE_LEN2_L, LOBYTE(usLength));                              

            break;

        case _MASK_ACTIVE_SPACE_3:

            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_29_ACTIVE_SPACE_LINE3_M, (((HIBYTE(usLength) & 0x0F) << 4) | ((HIBYTE(usPosition) & 0x0F))));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2A_ACTIVE_SPACE_LINE3_L, LOBYTE(usPosition));  
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2B_ACTIVE_SPACE_LEN3_L, LOBYTE(usLength));                              

            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Set Vgip mask function
// Input Value  : mask pos
// Output Value : None
//--------------------------------------------------
void ScalerVgipMaskSignal(void)
{
    BYTE ucActiveSpaceLen = 0; // Active space

    if(GET_3D_MISC_DOUBLE_BUFFER() == _FALSE)
    {
        // Disable Mask function
        ScalerVgipMaskFunctionEnable(0, _DISABLE); 

        // Input format set frame sequential
        ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), 0x00);        
    }
   
    switch(GET_3D_INPUT_FORMAT())
    {
        case _FRAME_PACKING:

            // 1080p (45 / 2205) = 720p (30 / 1470) = 1 / 49
            ucActiveSpaceLen = g_stMDomainInputData.usVHeight / 49;

            if((g_stMDomainInputData.usVHeight == 1005) || (g_stMDomainInputData.usVHeight == 1028))
            {
                // 480p, 480i
                ucActiveSpaceLen = 45;
            }
            else if((g_stMDomainInputData.usVHeight == 1201) || (g_stMDomainInputData.usVHeight == 1226))
            {
                // 576p, 576i
                ucActiveSpaceLen = 49;
            }
    				
            // 4 field
            if(GET_INTERLACED_MODE() == _TRUE)
            {
                ucActiveSpaceLen = ucActiveSpaceLen / 2 + 1;
                
                // FP : 1080i / 480i / 576i
                if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)
                {
                    g_stMDomainInputData.usVHeight = (g_stMDomainInputData.usVHeight - (ucActiveSpaceLen * 3 - 1)) >> 2;

                    /*
                    // Input (Lo + Le), Display (Lo or Le)
                    // Mask Ro and Re
                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_0, (g_stMDomainInputData.usVHeight) , (g_stMDomainInputData.usVHeight + (ucActiveSpaceLen << 1) - 1));
                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_1, (g_stMDomainInputData.usVHeight * 3 + (ucActiveSpaceLen << 1) - 1) , (g_stMDomainInputData.usVHeight + ucActiveSpaceLen));

                    ScalerVgipMaskFunctionEnable(_MASK_TYPE_TWO_SECTION_KEEP_ODD_TWO_SET, _ENABLE);   

                    g_stMDomainInputData.usVHeight = g_stMDomainInputData.usVHeight << 1;                    
                    */

                    // Input (Ro + Re), Display (Ro or Re)
                    // Mask Lo and Le
                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_0, 0x00 , (g_stMDomainInputData.usVHeight + ucActiveSpaceLen));
                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_1, (g_stMDomainInputData.usVHeight * 2 + ucActiveSpaceLen) , (g_stMDomainInputData.usVHeight + (ucActiveSpaceLen << 1) - 1));

                    ScalerVgipMaskFunctionEnable(_MASK_TYPE_TWO_SECTION_KEEP_ODD_TWO_SET, _ENABLE);   

                    g_stMDomainInputData.usVHeight = g_stMDomainInputData.usVHeight << 1;                    
                }
                else
                {
                    g_stMDomainInputData.usVHeight = (g_stMDomainInputData.usVHeight - (ucActiveSpaceLen * 3 - 1)) >> 1;

                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_0, 0x00, ((g_stMDomainInputData.usVHeight >> 1) + ucActiveSpaceLen));
                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_1, (g_stMDomainInputData.usVHeight + ucActiveSpaceLen), (ucActiveSpaceLen - 1));
                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_2, (((g_stMDomainInputData.usVHeight >> 1) * 3) + (ucActiveSpaceLen << 1) - 1), ((g_stMDomainInputData.usVHeight >> 1) + ucActiveSpaceLen));                      

                    ScalerVgipMaskFunctionEnable(_MASK_TYPE_THREE_SECTION_EVERYFRAME_THREE_SET, _ENABLE);   

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

                    // Input format set 2 field
                    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), _BIT4); 
#endif
                }

                break;
            }  
            
        case _TOP_AND_BOTTOM:

            // 2 field
            if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)
            {
                g_stMDomainInputData.usVHeight = (g_stMDomainInputData.usVHeight - ucActiveSpaceLen) / 2;

                // Mask L image
                ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_0, 0x00, (g_stMDomainInputData.usVHeight + ucActiveSpaceLen));
                ScalerVgipMaskFunctionEnable(_MASK_TYPE_ONE_SECTION_ONE_SET, _ENABLE);
            }
            else
            {
                g_stMDomainInputData.usVHeight -= ucActiveSpaceLen;

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
                
                ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_0, (g_stMDomainInputData.usVHeight >> 1), ucActiveSpaceLen);
                ScalerVgipMaskFunctionEnable(_MASK_TYPE_ONE_SECTION_ONE_SET, _ENABLE);

#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES) 

                if(GET_MEMORY_DVF_SELECT() == _1_IVF)
                {
                    // Mask L image
                    g_stMDomainInputData.usVHeight = g_stMDomainInputData.usVHeight >> 1;

                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_0, g_stMDomainInputData.usVHeight, (ucActiveSpaceLen + g_stMDomainInputData.usVHeight));
                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_1, 0x00, (ucActiveSpaceLen + g_stMDomainInputData.usVHeight));
                    
                    ScalerVgipMaskFunctionEnable(_MASK_TYPE_TWO_DIFF_SECTION_ALTFRAME_TWO_SET, _ENABLE); 
                }
                else
                {
                    // Mask Active Space
                    ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_0, (g_stMDomainInputData.usVHeight >> 1), ucActiveSpaceLen);                    
                    ScalerVgipMaskFunctionEnable(_MASK_TYPE_ONE_SECTION_ONE_SET, _ENABLE);            
                }
#endif

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

                // Input format set 2 field
                ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), _BIT4); 

#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
            }                  
            
            break;

        case _SIDE_BY_SIDE_HALF:
        
            if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)
            {
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
                // Disable Mask function
                ScalerVgipMaskFunctionEnable(_MASK_TYPE_ONE_SECTION_ONE_SET, _DISABLE); 
#endif
            }
            else
            {

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

                    // Input format set SBS
                    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4)); 

#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)                     
                if(GET_MEMORY_DVF_SELECT() == _1_IVF)
                {
                    // get width
                    g_stMDomainInputData.usHWidth = g_stMDomainInputData.usHWidth >> 1;
                    // Set Reset function before 2Dto3D adjust shift mode.
                    // (Because 2Dto3D shift mode will modify HWidth)
                    // (Mask = _MASK_TYPE_SBS_ALTFRAME refer to SBS reset length)
                    Scaler3DSBSHReset(g_stMDomainInputData.usHWidth);
                    
                    ScalerVgipMaskFunctionEnable(_MASK_TYPE_SBS_ALTFRAME, _ENABLE);
                }
#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
            }
			
            break;

        case _LINE_INTERLACE:
        
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
            if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
            {
                if(GET_MEMORY_DVF_SELECT() == _1_IVF)
                {
                    g_stMDomainInputData.usVHeight = (g_stMDomainInputData.usVHeight >> 1);

                    ScalerVgipMaskFunctionEnable(_MASK_TYPE_LINE_INTERLEAVE_ALTFRAME, _ENABLE);  
                }
            }
#endif
            
            break;
            
        case _FRAME_SEQUENTIAL:
            
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

            if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)
            {
                // Mask L frame
                ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_0, 0x00, g_stMDomainInputData.usVHeight);
                ScalerVgipMaskActiveSpace(_MASK_ACTIVE_SPACE_1, 0x00, 0x00);
                ScalerVgipMaskFunctionEnable(_MASK_TYPE_TWO_DIFF_SECTION_ALTFRAME_TWO_SET, _ENABLE);   
            }
            
#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

            break;
            
        default:            
            // do nothing
            break;            
    }
} 
#endif // #if(_3D_SUPPORT == _ON)
