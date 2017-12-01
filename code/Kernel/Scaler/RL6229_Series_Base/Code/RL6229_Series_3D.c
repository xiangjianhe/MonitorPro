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
// ID Code      : RL6229_Series_FRC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6229_SERIES_3D__

#include "ScalerFunctionInclude.h"

#if(_3D_SUPPORT == _ON)

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_NORMAL)
#warning "3D support on - please select panel type!"
#endif


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _3D_W_1ST_BLOCK_STA_ADDR_H                  (0x00) // 0 row
#define _3D_W_1ST_BLOCK_STA_ADDR_M                  (0x00)

#define _3D_W_2ND_BLOCK_STA_ADDR_H                  (0x2A) // 1365 row
#define _3D_W_2ND_BLOCK_STA_ADDR_M                  (0xA8) 

#define _3D_W_3RD_BLOCK_STA_ADDR_H                  (0x15) // 682 row
#define _3D_W_3RD_BLOCK_STA_ADDR_M                  (0x50) 

#define _3D_FP_DEN_ACTIVESPACE_RATIO                (48)
#define _IVS2DVS_DELAY_MARGIN                       (5)
#define _PREREAD_MARGIN                             (3)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

#if(_2D_TO_3D_FUNCTION == _ON)
BYTE g_ucIVstart = 0;
BYTE g_ucIVSDelay = 0;
BYTE g_ucDVstart = 0;
SDWORD g_ulLastLineCompen = 0;
#endif

Struct3DCtrlType g_st3DCtrl = {0};
Struct3DFormat g_stThreeD = {0};
Struct3DSelect g_st3DSelect = {0}; 

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
BYTE g_uc3DDVSCount = 0;
bit g_b3DIRQShiftStatus = _FALSE;
DWORD g_ul3D_W_2ND_BLOCK_STA_ADDR = 0;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void Scaler3DSelect(Enum3DAdvanceSupport enum3DOSDType, Enum3DFormatSelect enum3DOSDSelect, bit b3DPRDisplaySelect, bit b3D2DSelect);
void Scaler3DSetInOutFormat(Enum3DAdvanceSupport enum3DOSDType, Enum3DFormatSelect enum3DOSDSelect, bit b3DPRDisplaySelect, bit b3D2DSelect);
void Scaler3DSetConvEff(BYTE uc3DDepthGain, BYTE uc3DEffect, Enum3DSelectConvergence enumConvergence, Enum3DSelectConvergenceMode enumConvergenceMode);
void Scaler3DSetEffectDoubleBuffer(void);
BYTE Scaler3DTxInputFormat(void);
BYTE Scaler3DGetInputFormat(void);
void Scaler3DDetect(BYTE ucInputSource);
void Scaler3DSBSHReset(WORD usHWidth);
void Scaler3DAdjustWithoutMuteLineBuffer(void);
void Scaler3DAdjustWithoutMuteFrameBuffer(void);
void Scaler3DControl(WORD usInputHorSize, WORD usInputVerSize, WORD usOutputHorSize, WORD usOutputVerSize);

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
void Scaler3DSetInputAutoBlkTogglePRType(DWORD ulBlockStep);
void Scaler3DSetDisplayAutoBlkTogglePRType(DWORD ulBlockStep);
void Scaler3DAdjustIVS2DVSDelayPRType(void);
void Scaler3DInputCtrlPRType(WORD usHorSize, WORD usVerSize);
void Scaler3DDisplayCtrlPRType(WORD usHorSize, WORD usVerSize);
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
void Scaler3DSetInputAutoBlkToggleShutterType(void);
void Scaler3DSetDisplayAutoBlkToggleShutterType(void);
void Scaler3DSetHWAutoBlockToggleShutterType(void);
void Scaler3DAdjustIVS2DVSDelayShutterType(DWORD ulClk);
void Scaler3DInputCtrlShutterType(WORD usHorSize, WORD usVerSize);
void Scaler3DDisplayCtrlShutterType(WORD usHorSize, WORD usVerSize);
void Scaler3DSetDisplayLRFlagEnable(BYTE ucEn);
void Scaler3DIntHandler_EXINT0(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Select 3D input and display format according to OSD and Tx
// Input Value  : OSD select type
// Output Value : None
//--------------------------------------------------
void Scaler3DSelect(Enum3DAdvanceSupport enum3DOSDType, Enum3DFormatSelect enum3DOSDSelect, bit b3DPRDisplaySelect, bit b3D2DSelect)
{
    CLR_3D_SELECT_FORMAT();
    CLR_3D_SELCET_DISPLAY();

    switch(enum3DOSDType)
    {
        case _3D_ON:

            SET_3D_SELECT_FORMAT(enum3DOSDSelect);

            if(b3D2DSelect)
            {
                SET_3D_SELCET_DISPLAY(_3D_DISPLAY_2D);     
            }   
            else
            {
                SET_3D_SELCET_DISPLAY(b3DPRDisplaySelect);
            }
            
            break;

        case _3D_2D_TO_3D:

            SET_3D_SELCET_DISPLAY(b3DPRDisplaySelect);
            
            break;
    }

/*
#if( _PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
    CLR_3D_SELECT_FORMAT();
    CLR_3D_TO_2D_STATUS();
    
    SET_3D_SELECT_FORMAT(uc3DOSDSelect);
    SET_3D_TO_2D_STATUS(b3D2DSelect);

    b3DPRDisplaySelect = b3DPRDisplaySelect;
#endif
*/
}

//--------------------------------------------------
// Description  : Set 3D input and out format
// Input Value  : OSD select
// Output Value : None
//--------------------------------------------------
void Scaler3DSetInOutFormat(Enum3DAdvanceSupport enum3DOSDType, Enum3DFormatSelect enum3DOSDSelect, bit b3DPRDisplaySelect, bit b3D2DSelect)
{  
    CLR_3D_INPUT_FORMAT();
    CLR_3D_OUTPUT_SEQUENCE();    

#if(_2D_TO_3D_FUNCTION == _ON)
    CLR_2DTO3D_ENABLE();
    CLR_2DTO3D_DEPTH();
#endif

    //SET_3D_LR_CHANGE_STATUS(_3D_DISPLAY_RL);
    Scaler3DSelect(enum3DOSDType, enum3DOSDSelect, b3DPRDisplaySelect, b3D2DSelect);

    switch(enum3DOSDType)
    {
        case _3D_OFF:

            SET_3D_OUTPUT_SEQUENCE(_3D_DISPLAY_2D);

            break;
            
        case _3D_ON:
            
            switch(GET_3D_SELECT_FORMAT()) // OSD select 3D mode
            {
            	case _3D_MODE_FORMAT_SBS:

            	    SET_3D_INPUT_FORMAT(_SIDE_BY_SIDE_HALF);
            	    
            	    break;

            	case _3D_MODE_FORMAT_TNB:

            	    SET_3D_INPUT_FORMAT(_TOP_AND_BOTTOM);
            	    
            	    break;

            	case _3D_MODE_FORMAT_LINE_INTERLACE:

            	    SET_3D_INPUT_FORMAT(_LINE_INTERLACE);
            	    
            	    break;    

            	case _3D_MODE_FORMAT_AUTO:

                    SET_3D_INPUT_FORMAT(GET_3D_TX_INPUT_FORMAT());
                    
            	    break;    	    	

            	default:

            	    break;
            }
            
            if((GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT) && (GET_3D_SELECT_FORMAT() == _3D_MODE_FORMAT_AUTO))
            {
                SET_3D_OUTPUT_SEQUENCE(_3D_DISPLAY_2D);
            }
            else
            {
                SET_3D_OUTPUT_SEQUENCE(GET_3D_SELCET_DISPLAY());
            }

            break;

#if(_2D_TO_3D_FUNCTION == _ON)

        case _3D_2D_TO_3D:

            // Unsupport timing
            if((GET_INPUT_TIMING_HWIDTH() == 1680) && (GET_INPUT_TIMING_VHEIGHT() == 1050) && (GET_INPUT_TIMING_VFREQ() > 650))
            {

            }
            else if((GET_INPUT_TIMING_HWIDTH() < 1920) || (GET_INPUT_TIMING_VHEIGHT() <= 1080))
            {
                SET_2DTO3D_ENABLE();
                SET_2DTO3D_DEPTH();

                SET_3D_OUTPUT_SEQUENCE(GET_3D_SELCET_DISPLAY());
            }

            break;
            
#endif

        default:

            break;
    }

    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D))
    {
        g_stMDomainInputData.usHWidth /= 2;

        // Capture R image
        g_stMDomainInputData.usHStart += g_stMDomainInputData.usHWidth;
    }    
}

//--------------------------------------------------
// Description  : Set 3D, 2Dto3D output effect and convergence
// Input Value  : OSD select
// Output Value : None
//--------------------------------------------------
void Scaler3DSetConvEff(BYTE uc3DDepthGain, BYTE uc3DEffect, Enum3DSelectConvergence enumConvergence, Enum3DSelectConvergenceMode enumConvergenceMode)
{  
    SET_3D_DEPTH_GAIN(uc3DDepthGain);
    SET_3D_SHIFT_MODE_EFFECT(uc3DEffect);

#if(_2D_TO_3D_FUNCTION == _ON)

    SET_3D_SELECT_CONVERGENCE(enumConvergence);
    SET_3D_SELECT_CONVERGENCE_MODE(enumConvergenceMode);

#else

    enumConvergence = enumConvergence;
    enumConvergenceMode = enumConvergenceMode;

#endif
 
}

//--------------------------------------------------
// Description  : Set 3D Effect double buffer
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void Scaler3DSetEffectDoubleBuffer(void)
{  
    ScalerGlobalWatchDog(_DISABLE);
    
    SET_3D_MISC_DOUBLE_BUFFER();
}

//--------------------------------------------------
// Description  : 3D Tx Input Format
// Input Value  : None
// Output Value : 3D Tx Input Format
//--------------------------------------------------
BYTE Scaler3DTxInputFormat(void)
{
    return GET_3D_TX_INPUT_FORMAT();
}

//--------------------------------------------------
// Description  : 3D Tx Input Format
// Input Value  : None
// Output Value : 3D Tx Input Format
//--------------------------------------------------
BYTE Scaler3DGetInputFormat(void)
{
    return GET_3D_INPUT_FORMAT();
}

//--------------------------------------------------
// Description  : Detect HDMI 3D format
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void Scaler3DDetect(BYTE ucInputSource)
{
    SET_3D_TX_INPUT_FORMAT(_NO_3D_FORMAT);

    switch(ucInputSource)
    {

#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

            break;
#endif // End of #if(_VGA_SUPPORT == _ON)

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:

            break;            
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_HDMI_SUPPORT == _ON)
        case _SOURCE_HDMI:

            if(GET_HDMI_3D_INFO_RECEIVED() == _TRUE)
            {
                SET_3D_TX_INPUT_FORMAT(ScalerTmdsHdmiGet3DFormat());

                if(GET_3D_TX_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF)
                {
                    switch((ScalerGetByte(P1B_A2_HDMI_3D_FORMAT0)) & 0xF0)
                    {
                        case 0x00: // OLOR,hor-sub-sampling

                            SET_3D_EXT_DATA(_3D_EXT_OL_OR);

                            break;

                        case 0x10: // OLER,hor-sub-sampling

                            SET_3D_EXT_DATA(_3D_EXT_OL_ER);

                            break;  

                        case 0x20: // ELOR,hor-sub-sampling

                            SET_3D_EXT_DATA(_3D_EXT_EL_OR);

                            break; 

                        case 0x30: // ELER,hor-sub-sampling

                            SET_3D_EXT_DATA(_3D_EXT_EL_ER);

                            break;   

                        case 0x40: // OLOR,quin-sub-sampling

                            SET_3D_EXT_DATA(_3D_EXT_OL_OR_QUIN);

                            break;     

                        case 0x50: // OLER,quin-sub-sampling

                            SET_3D_EXT_DATA(_3D_EXT_OL_ER_QUIN);

                            break; 

                        case 0x60: // ELOR,quin-sub-sampling

                            SET_3D_EXT_DATA(_3D_EXT_EL_OR_QUIN);

                            break;

                        case 0x70: // ELER,quin-sub-sampling

                            SET_3D_EXT_DATA(_3D_EXT_EL_ER_QUIN);                                                                 

                            break;  

                        default:

                            break;                            
                    }
                }
            }

            break;
#endif // End of #if(_HDMI_SUPPORT == _ON)

        default:
            break;
        
    }

    DebugMessageDigital("Source 3D Detected", GET_3D_TX_INPUT_FORMAT());
}

//--------------------------------------------------
// Description  : sbs h reset
// Input Value  : reset pos
// Output Value : none
//--------------------------------------------------
void Scaler3DSBSHReset(WORD usHWidth)
{
    // Disable SBS Reset
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, ~_BIT4, 0x00);     
    
    if(GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF)
    {
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER) 

        if((GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D) && (GET_3D_SHIFT_MODE_EFFECT() == 0x00))
        {
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | HIBYTE(usHWidth))); 
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, LOBYTE(usHWidth));               
        }
                       
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES) 

        // shutter
        ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2F_H_SBS_RST_POS_M, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usHWidth)); 
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_30_H_SBS_RST_POS_L, LOBYTE(usHWidth));
          
#endif
    }
}

//--------------------------------------------------
// Description  : 2D/2Dto3D switch and effect adjust without mute
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void Scaler3DAdjustWithoutMuteLineBuffer(void)
{   
#if(_2D_TO_3D_FUNCTION == _ON)     
    BYTE ucIVstDelta = 0;
    BYTE ucDVstDelta = 0;
#endif

    // 2Dto3D Depth mode
    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT4, (g_ucP1CA5 & _BIT4));
 
#if(_2D_TO_3D_FUNCTION == _ON) 

    if((GET_2DTO3D_FIRST() == _TRUE) && (GET_V_SCALE_UP() == _TRUE))
    {  
        // Calculate DVS to DH Active in ICLK
        PDATA_DWORD(0) = ((DWORD)g_stMDomainOutputData.usHTotal * g_ucDVstart) + g_stMDomainOutputData.usHStart;
        PDATA_DWORD(0) = PDATA_DWORD(0) * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVHeight * g_stMDomainInputData.usHTotal / g_stMDomainOutputData.usHTotal; 
        
        // Calculate IVS to IH Active in ICLK
        PDATA_DWORD(1) = ((DWORD)g_stMDomainInputData.usHTotal * g_ucIVstart) + (ScalerGetByte(CM_15_IPH_ACT_STA_L) + 2);    
        
        // IVst + Dt + last line com
        PDATA_DWORD(2) = PDATA_DWORD(1) + (DWORD)g_stMDomainInputData.usHTotal * (ScalerMemoryGetScaleUpDt() - 100) / 100 + g_ulLastLineCompen;

        // IVst + Dt + last line com < DVst + 0.5line
        // 1. IVS2DVS > 0.5line
        //    IVst + Dt - DVst + 0.5line > 0
        //    IVst + Dt > DVst + 0.5line
        // if(IVst + Dt <= DVst) --> IVst++
        // 
        // 2. IVS2DVS + DVsyncWidth < IVst
        //    IVst + Dt - DVst + DVsyncWidth < IVst
        // if(IVst + Dt - DVst + DVsyncWidth >= IVst) --> DVst++        
        
        // IVst + Dt + last line com < DVst + 0.5line --> add IVst
        if(PDATA_DWORD(2) < (PDATA_DWORD(0) + ((g_stMDomainInputData.usHTotal >> 1) + 64)))
        {                       
            // (IVst + Dt) + Compensate value <= DVst
            ucIVstDelta = ((PDATA_DWORD(0) + ((g_stMDomainInputData.usHTotal >> 1) + 64)) - PDATA_DWORD(2)) / g_stMDomainInputData.usHTotal + 1;                                      

            PDATA_DWORD(2) += g_stMDomainInputData.usHTotal * ucIVstDelta;         
        }        
        else
        {         
            // IVS2DVS + Compensate value + DVsyncWidth
            PDATA_DWORD(3) = (PDATA_DWORD(2) + g_stMDomainInputData.usHTotal - PDATA_DWORD(0)) + g_ulLastLineCompen + ((DWORD)g_stMDomainInputData.usVHeight * g_stMDomainInputData.usHTotal * _PANEL_DV_SYNC_HEIGHT / g_stMDomainOutputData.usVHeight);

            // IVS2DVS + Compensate value + DVsyncWidth >= IVst --> add DVst
            if(PDATA_DWORD(3) >= PDATA_DWORD(1))
            {
                ucDVstDelta = (DWORD)g_stMDomainOutputData.usVHeight * (PDATA_DWORD(3) - PDATA_DWORD(1)) / g_stMDomainInputData.usVHeight / g_stMDomainInputData.usHTotal + 1;
                PDATA_DWORD(0) += (DWORD)g_stMDomainInputData.usHTotal * ucDVstDelta * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVHeight;
            }
        }

        DebugMessageFS("2. IVst delta", ucIVstDelta);
        DebugMessageFS("2. DVst delta", ucDVstDelta);

        // Modify IVst != current IVst
        if((g_ucIVstart + ucIVstDelta) != ScalerGetByte(CM_19_IPV_ACT_STA_L))
        {
            // Set IVst and IVsDelay
            ScalerSetByte(CM_19_IPV_ACT_STA_L, (g_ucIVstart + ucIVstDelta));
            ScalerSetByte(CM_1C_IVS_DELAY, (g_ucIVSDelay - ucIVstDelta));   
        }
        // IVS2DVS delay = (IVst + Dt) + Compensate value - DVst
        PDATA_DWORD(0) = PDATA_DWORD(2) - PDATA_DWORD(0); 
        
        DebugMessageFS("2. Calculated IVS2DVS", PDATA_DWORD(0));
        
        // Preserve 0.5 lines + 64 pixel in Fine Tune Byte
        pData[5] = (BYTE)((PDATA_DWORD(0) - (g_stMDomainInputData.usHTotal >> 1) - 64) / g_stMDomainInputData.usHTotal);
        pData[6] = (BYTE)((PDATA_DWORD(0) - ((DWORD)g_stMDomainInputData.usHTotal * pData[5]) + 8) >> 4); 
        pData[7] = pData[6] - ((g_stMDomainInputData.usHTotal + 16) >> 5);   
       
        // Apply updated Delay    
        ScalerSetByte(CM_3E_IVS2DVS_DEALY_LINES_H, 0x00);            
        ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[5]);
        ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, (pData[6] - 1));
        ScalerSetByte(CM_42_IV_DV_DELAY_CLK_EVEN, (pData[7] - 1));        
    }
    
#endif // End of #if(_2D_TO_3D_FUNCTION == _ON) 

    ScalerSetBit(P20_A2_3D_DDEA_DB_CTRL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6)); 

    // Wait IDEN STOP (for the following setting in porch area)
    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
    
    // Set VGIP double buffer ready
    ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5);

    // Set 3D misc double buffer ready
    ScalerSetBit(P20_A0_3D_IVS_DB_CTRL, ~_BIT6, _BIT6);      

    // Wait IDEN STOP 
    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);      
    
#if(_2D_TO_3D_FUNCTION == _ON)                
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT3, (GET_2DTO3D_ENABLE() ? _BIT3 : 0));
#endif

    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (g_ucP1CA5 & (~_BIT4)));           
    
    // Check new shift mode.
    if((ScalerGetBit(P1C_B0_2D_TO_3D_CTL17, _BIT1) == 0x00) && (ScalerGetBit(CM_16_IPH_ACT_WID_H, _BIT1) != 0x00))
    {
        // Mask Active Space Disable
        ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, ~_BIT0, 0x00);

        // Disable new mode
        ScalerSetBit(CM_16_IPH_ACT_WID_H, ~_BIT1, 0x00);
    }    
    else if((ScalerGetBit(P1C_B0_2D_TO_3D_CTL17, _BIT1) == _BIT1) && (ScalerGetBit(CM_16_IPH_ACT_WID_H, _BIT1) == 0x00))
    {
        // Mask Active Space Enable
        ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, ~_BIT0, _BIT0);
        
        // Enable new mode
        ScalerSetBit(CM_16_IPH_ACT_WID_H, ~_BIT1, _BIT1);
    }
    
    // Shift direction
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);
        
#if(_2D_TO_3D_FUNCTION == _ON)    
    if(((GET_2DTO3D_ENABLE() == _ENABLE) && ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) || (ScalerGetBit(P1C_A1_2D_TO_3D_CTL2, _BIT5) == 0x00))) || 
            (GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT))
#else            
    if((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT))             
#endif 
    {
        if((GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_3) || (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_4) || 
            (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_5))
        {
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

#if(_PANEL_PR_DIS_TYPE == _PANEL_PR_LR_DISPLAY)

            // Shift direction
            if(((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_LR) && (GET_3D_SELECT_CONVERGENCE() == _3D_IN)) ||
               ((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_RL) && (GET_3D_SELECT_CONVERGENCE() == _3D_OUT)))
            {
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);
            }
            else
            {
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, _BIT7);
            } 
#else
            // Shift direction
            if(((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_RL) && (GET_3D_SELECT_CONVERGENCE() == _3D_IN)) ||
               ((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_LR) && (GET_3D_SELECT_CONVERGENCE() == _3D_OUT)))            
            {
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, _BIT7);
            }
            else
            {
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);
            }  
#endif

#else
            // Shift direction
            ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, ((GET_3D_SELECT_CONVERGENCE() == _3D_OUT) ? _BIT7 : 0x00));

#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
        }        
    }

    // Wait 3D misc double buffer finish
    ScalerTimerPollingFlagProc(100, P20_A0_3D_IVS_DB_CTRL, _BIT6, 0);
    
#if(_2D_TO_3D_FUNCTION == _ON)

    ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_11_DISP_DV_ACT_STA_L, 1, &pData[5], _NON_AUTOINC);

    // Modify DVst != current DVst
    if((g_ucDVstart + ucDVstDelta) != pData[5])
    {   
        // Modify DVactive Setting
        PDATA_WORD(0) = g_ucDVstart + ucDVstDelta;
        PDATA_WORD(1) = PDATA_WORD(0) + g_stMDomainOutputData.usVHeight;

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_10_DISP_DV_ACT_STA_H);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, HIBYTE(PDATA_WORD(0)));  

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_11_DISP_DV_ACT_STA_L);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, LOBYTE(PDATA_WORD(0)));  

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_12_DISP_DV_ACT_END_H);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, HIBYTE(PDATA_WORD(1)));  

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_13_DISP_DV_ACT_END_L);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, LOBYTE(PDATA_WORD(1)));        
        
        // Modify DVbackground Setting
        ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0F_DISP_DV_BKGD_STA_L, 1, &pData[5], _NON_AUTOINC);
        PDATA_WORD(0) = pData[5] + ucDVstDelta;
        PDATA_WORD(1) = PDATA_WORD(0) + g_stMDomainOutputData.usVBackHeight;

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0E_DISP_DV_BKGD_STA_H);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, HIBYTE(PDATA_WORD(0)));  

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0F_DISP_DV_BKGD_STA_L);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, LOBYTE(PDATA_WORD(0)));  

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_14_DISP_DV_BKGD_END_H);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, HIBYTE(PDATA_WORD(1)));  

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_15_DISP_DV_BKGD_END_L);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, LOBYTE(PDATA_WORD(1)));         
    } 

    // Modify DHactive setting        
    // Display HStart
    PDATA_WORD(0) = g_stMDomainOutputData.usHStart + g_stMDomainOutputData.usHStart % 2;

    // Display HEnd
    PDATA_WORD(1) = PDATA_WORD(0) + g_stMDomainOutputData.usHWidth;

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_05_DISP_DH_ACT_STA_H);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[0]);  

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_06_DISP_DH_ACT_STA_L);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[1]);   

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_07_DISP_DH_ACT_END_H);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[2]);  

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_08_DISP_DH_ACT_END_L);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[3]);                
  
#endif
    
    if((GET_INTERLACED_MODE() == _TRUE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) && (ScalerGetBit(CM_10_VGIP_CTRL, (_BIT3 | _BIT2)) != 0x00) && (GET_INPUT_TIMING_HWIDTH() != _PANEL_DH_WIDTH))
    {
        // Enable Frame Sync Fine Tune
        ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~(_BIT1 | _BIT0), (_BIT1 | (bit)ScalerGetBit(CM_32_SCALE_CTRL, _BIT6)));
 
        // Enable Video Compensation
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT7, _BIT7);
    }
    else
    {
        // Disable Frame Sync Fine Tune
        ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~_BIT1, 0x00);
 
        // Disable Video Compensation
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : 2D/2Dto3D switch and effect adjust without mute
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void Scaler3DAdjustWithoutMuteFrameBuffer(void)
{   
    // 2Dto3D Depth mode
    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~_BIT4, (g_ucP1CA5 & _BIT4));
 
    // IDEN/DDEN double buffer
    ScalerSetBit(P20_A2_3D_DDEA_DB_CTRL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6)); 
    
    // Wait IDEN STOP (for the following setting in porch area)
    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);    

    // Set 3D misc double buffer ready
    ScalerSetBit(P20_A0_3D_IVS_DB_CTRL, ~_BIT6, _BIT6);      

    // Wait IDEN STOP 
    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);     

#if(_2D_TO_3D_FUNCTION == _ON)                
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT3, (GET_2DTO3D_ENABLE() ? _BIT3 : 0));
#endif

    ScalerSetBit(P1C_A5_2D_TO_3D_CTL6, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (g_ucP1CA5 & (~_BIT4)));           

    // Check new shift mode.
    if((ScalerGetBit(P1C_B0_2D_TO_3D_CTL17, _BIT1) == 0x00) && (ScalerGetBit(CM_16_IPH_ACT_WID_H, _BIT1) != 0x00))        
    {
        // Mask Active Space Disable
        ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, ~_BIT0, 0x00);

        // Disable new mode
        ScalerSetBit(CM_16_IPH_ACT_WID_H, ~_BIT1, 0x00);
    }    
    else if((ScalerGetBit(P1C_B0_2D_TO_3D_CTL17, _BIT1) == _BIT1) && (ScalerGetBit(CM_16_IPH_ACT_WID_H, _BIT1) == 0x00))        
    {
        // Mask Active Space Enable
        ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2C_ACTIVE_SPACE_CTRL, ~_BIT0, _BIT0);
        
        // Enable new mode
        ScalerSetBit(CM_16_IPH_ACT_WID_H, ~_BIT1, _BIT1);
    }
  
    // Shift direction
    ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);
  
#if(_2D_TO_3D_FUNCTION == _ON)    
    if(((GET_2DTO3D_ENABLE() == _ENABLE) && ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) || (ScalerGetBit(P1C_A1_2D_TO_3D_CTL2, _BIT5) == 0x00))) || 
       (GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT))
#else            
    if((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT))             
#endif 
    {
        if((GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_3) || (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_4) || 
           (GET_3D_SELECT_CONVERGENCE_MODE() == _NON_LINEAR_MODE_5))
        {
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

#if(_PANEL_PR_DIS_TYPE == _PANEL_PR_LR_DISPLAY)

            // Shift direction
            if(((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_LR) && (GET_3D_SELECT_CONVERGENCE() == _3D_IN)) ||
               ((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_RL) && (GET_3D_SELECT_CONVERGENCE() == _3D_OUT)))
            {
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);
            }
            else
            {
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, _BIT7);
            } 
#else
            // Shift direction
            if(((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_RL) && (GET_3D_SELECT_CONVERGENCE() == _3D_IN)) ||
               ((GET_3D_SELCET_DISPLAY() == _3D_DISPLAY_LR) && (GET_3D_SELECT_CONVERGENCE() == _3D_OUT)))            
            {
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, _BIT7);
            }
            else
            {
                ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, 0x00);
            }  
#endif

#else
            // Shift direction
            ScalerSetBit(P1C_A1_2D_TO_3D_CTL2, ~_BIT7, ((GET_3D_SELECT_CONVERGENCE() == _3D_OUT) ? _BIT7 : 0x00));

#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
        }        
    }       

    // Wait 3D misc double buffer finish
    ScalerTimerPollingFlagProc(100, P20_A0_3D_IVS_DB_CTRL, _BIT6, 0);

#if(_2D_TO_3D_FUNCTION == _ON)

    // Modify DHactive setting        
    // Display HStart
    PDATA_WORD(0) = g_stMDomainOutputData.usHStart + g_stMDomainOutputData.usHStart % 2;

    // Display HEnd
    PDATA_WORD(1) = PDATA_WORD(0) + g_stMDomainOutputData.usHWidth;

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_05_DISP_DH_ACT_STA_H);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[0]);

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_06_DISP_DH_ACT_STA_L);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[1]);  

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_07_DISP_DH_ACT_END_H);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[2]);

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_08_DISP_DH_ACT_END_L);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[3]);         
  
#endif
    
    if((GET_INTERLACED_MODE() == _TRUE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D))
    {
        // Enable Frame Sync Fine Tune
        ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~(_BIT1 | _BIT0), (_BIT1 | (bit)ScalerGetBit(CM_32_SCALE_CTRL, _BIT6)));
 
        // Enable Video Compensation
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT7, _BIT7);
    }
    else
    {
        // Disable Frame Sync Fine Tune
        ScalerSetBit(CM_43_FS_DELAY_FINE_TUNING, ~_BIT1, 0x00);
 
        // Disable Video Compensation
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : 3D control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void Scaler3DControl(WORD usInputHorSize, WORD usInputVerSize, WORD usOutputHorSize, WORD usOutputVerSize)
{
    //=============================   
    //          PR Type
    //=============================
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER) 

    if((GET_MEMORY_SELECT() == _FRAME_SYNC_SDRAM) || (GET_MEMORY_SELECT() == _MN_FRAME_SYNC_SDRAM))
    {
        // Set PR-3D IVS2DVSDelay
        Scaler3DAdjustIVS2DVSDelayPRType();
    }

    // Set up 3D Capture
    Scaler3DInputCtrlPRType(usInputHorSize, usInputVerSize);
    
    // Set up 3D Display
    Scaler3DDisplayCtrlPRType(usOutputHorSize, usOutputVerSize);

    // Set Frame tracking function for VFreq < 30Hz
    if(((GET_MEMORY_SELECT() == _MN_FRAME_SYNC_SDRAM) || 
       ((GET_3D_INPUT_FORMAT()== _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))) && 
       (GET_3D_MISC_DOUBLE_BUFFER() == _FALSE))
    {
        ScalerSDRAMFrameTracking();

        if(GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL)
        {
            // Wait input R image
            ScalerTimerPollingFlagProc(_M_N_AUTO_BLK_TOGGLE_STABLE_TIME, P20_A3_3D_L_R_STATUS0, _BIT7, 1);
        }    

        // Enable M:N frame tracking function
        ScalerSDRAMSetFrameTrackingEnable(_ENABLE);

        if((GET_MEMORY_DVF_SELECT() == _2_5_IVF) || 
           (GET_MEMORY_DVF_SELECT() == _3_IVF) || 
           ((GET_3D_INPUT_FORMAT()== _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))        
        {
#if((_OD_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
            // OD + FP 2D display use Single buffer read and write.
            // (if 3block toggle, OD data is overlay by next frame data)
            if((GET_3D_INPUT_FORMAT() != _FRAME_PACKING) ||
               ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))
#endif
            {
                ScalerSDRAMSetDisplayAutoBlkToggleEnable(_ENABLE);
            }
        }
    }

    //=============================   
    //          Shutter
    //=============================    
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES) // Else of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER) 

    g_uc3DDVSCount = 0;
    g_b3DIRQShiftStatus = _FALSE;

    // Set Shutter-3D IVS2DVSDelay
    Scaler3DAdjustIVS2DVSDelayShutterType(GET_D_CLK_FREQ());
    
    // Set up 3D Capture
    Scaler3DInputCtrlShutterType(usInputHorSize, usInputVerSize);

    // Set up 3D Display
    Scaler3DDisplayCtrlShutterType(usOutputHorSize, usOutputVerSize);

    // Set Frame tracking function for VFreq < 30Hz
    if(GET_MEMORY_SELECT() == _MN_FRAME_SYNC_SDRAM)
    {
        // Set Frame tracking parameters
        ScalerSDRAMFrameTracking();
        
         // Wait DVS (for sync Frame_Tracking and HW_Block_Toggle)  
        ScalerTimerWaitForEvent(_EVENT_DVS);
         
        // Enable Frame tracking function
        ScalerSDRAMSetFrameTrackingEnable(_ENABLE);

        switch(GET_3D_INPUT_FORMAT())
        {
            case _SIDE_BY_SIDE_HALF:
            case _LINE_INTERLACE:
                
                if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
                {
                    // Enable Display L/R flag
                    Scaler3DSetDisplayLRFlagEnable(_ENABLE);        
                }                    

                // Enable IVS IRQ
                ScalerGlobalSetInterrupt(_IRQ_IVS, _ENABLE);

                // Enable DVS IRQ
                ScalerGlobalSetInterrupt(_IRQ_DVS, _ENABLE);

                break;
                
            case _FRAME_PACKING:
            case _TOP_AND_BOTTOM:

                if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
                {                        
                    // Enable Display L/R flag
                    Scaler3DSetDisplayLRFlagEnable(_ENABLE);
                    
                    // Set display double buffer mode
                    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT6 | _BIT5 | _BIT4), _BIT6);

                    // Set input faster
                    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT3, _BIT3);  

                    // Enable Display double buffer
                    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT4, _BIT4);  
                }

                if(GET_MEMORY_DVF_SELECT() == _2_5_IVF)
                {
                    if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
                    {
                        // Enable DVS IRQ (before HW auto block toggle)
                        ScalerGlobalSetInterrupt(_IRQ_DVS, _ENABLE);                            
                    }
                    
                    // Enable HW auto block toggle
                    ScalerSDRAMSetDisplayAutoBlkToggleEnable(_ENABLE);
                }
                
                break;

            default:
                
                break;
        }
    }
    else
    {
        if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
        {
            // Enable Display L/R flag
            Scaler3DSetDisplayLRFlagEnable(_ENABLE);
        }
    }
    
#endif// End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)         
}

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
//--------------------------------------------------
// Description  : Set Input adderss for auto block toggle   
// Input Value  : ulBlockStep --> block step
// Output Value : None
//--------------------------------------------------
void Scaler3DSetInputAutoBlkTogglePRType(DWORD ulBlockStep)
{
    if(((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && 
       (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR)) 
    {
        // 1st Write Address
        PDATA_DWORD(0) = ((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_H << 16) + ((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_M << 8);
        PDATA_DWORD(0) += ulBlockStep;
        
        ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, pData[1]);
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, pData[2]);
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, pData[3]);
        DebugMessageFRC("-I_addr1 LR", PDATA_DWORD(0));
        
        // 2nd Write Address
        PDATA_DWORD(0) = ((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_H << 16) + ((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_M << 8);
        PDATA_DWORD(0) += ulBlockStep;
        
        ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT2);
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, pData[1]);
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, pData[2]);
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, pData[3]);
        DebugMessageFRC("-I_addr2 LR", PDATA_DWORD(0));
        
        // 3rd Write Address
        PDATA_DWORD(0) = ((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_H << 16) + ((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_M << 8);
        PDATA_DWORD(0) += ulBlockStep; 
        
        ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT3);
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, pData[1]);
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, pData[2]);
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, pData[3]);
        DebugMessageFRC("-I_addr3 LR", PDATA_DWORD(0));          
    }
    else
    {
        // 1st Write Address
        PDATA_DWORD(0) = ((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_H << 16) + ((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_M << 8);  
        
        ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, pData[1]);
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, pData[2]);
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, pData[3]);
        DebugMessageFRC("-I_addr1 RL", PDATA_DWORD(0));        
        
        // 2nd Write Address
        PDATA_DWORD(0) = ((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_H << 16) + ((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_M << 8);  
        
        ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT2);
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, pData[1]);
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, pData[2]);
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, pData[3]);
        DebugMessageFRC("-I_addr2 RL", PDATA_DWORD(0));        
        
        // 3rd Write Address
        PDATA_DWORD(0) = ((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_H << 16) + ((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_M << 8);  
        
        ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT3);
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, pData[1]);
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, pData[2]);
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, pData[3]);
        DebugMessageFRC("-I_addr3 RL", PDATA_DWORD(0));        
    }
}

//--------------------------------------------------
// Description  : Set display adderss for auto block toggle   
// Input Value  : ulBlockStep --> block step
// Output Value : None
//--------------------------------------------------
void Scaler3DSetDisplayAutoBlkTogglePRType(DWORD ulBlockStep)
{
    if(((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || 
        (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) || 
        (GET_3D_INPUT_FORMAT() == _FRAME_PACKING) ||
        (GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || 
        (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE)) && 
       (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL))
    {
        // 1st Read Address
        PDATA_DWORD(0) = (((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_H << 16) | ((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_M << 8) | 0x00);
        PDATA_DWORD(0) = ((PDATA_DWORD(0) >> 1) + (DWORD)ulBlockStep * 3);

        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
        ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, pData[1]);
        ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, pData[2]);
        ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, pData[3]);
        DebugMessageFRC("-D1_addr RL", PDATA_DWORD(0));        

        // 2nd Read Address
        PDATA_DWORD(0) = (((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_H << 16) | ((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_M << 8) | 0x00);
        PDATA_DWORD(0) = ((PDATA_DWORD(0) >> 1) + (DWORD)ulBlockStep * 3);

        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT2);
        ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, pData[1]);
        ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, pData[2]);
        ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, pData[3]);
        DebugMessageFRC("-D2_addr RL", PDATA_DWORD(0));        

        // 3rd Read Address
        PDATA_DWORD(0) = (((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_H << 16) | ((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_M << 8) | 0x00);
        PDATA_DWORD(0) = ((PDATA_DWORD(0) >> 1) + (DWORD)ulBlockStep * 3);

        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT3);
        ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, pData[1]);
        ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, pData[2]);
        ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, pData[3]);
        DebugMessageFRC("-D3_addr RL", PDATA_DWORD(0));        
    }
    else
    {
        // 1st Read Address
        PDATA_DWORD(0) = (((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_H << 16) | ((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_M << 8) | 0x00);
        PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);

        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
        ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, pData[1]);
        ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, pData[2]);
        ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, pData[3]);
        DebugMessageFRC("-D1_addr LR", PDATA_DWORD(0));        

        // 2nd Read Address
        PDATA_DWORD(0) = (((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_H << 16) | ((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_M << 8) | 0x00);
        PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1); 

        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT2);
        ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, pData[1]);
        ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, pData[2]);
        ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, pData[3]);
        DebugMessageFRC("-D2_addr LR", PDATA_DWORD(0));        

        // 3rd Read Address
        PDATA_DWORD(0) = (((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_H << 16) | ((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_M << 8) | 0x00);
        PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);    

        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT3);
        ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, pData[1]);
        ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, pData[2]);
        ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, pData[3]);    
        DebugMessageFRC("-D3_addr LR", PDATA_DWORD(0));        
    }    
}

//--------------------------------------------------
// Description  : Adjust IVS2DVS Delay for Aspect Ratio Function
// Input Value  : ulFreq --> DCLK
// Output Value : IVS2DVS Delay Lines
//--------------------------------------------------
void Scaler3DAdjustIVS2DVSDelayPRType(void)
{
    WORD usActiveSpace = 0;
    WORD usIVH;
    DWORD ulDActiveCount = 0;
    
    usIVH = g_stMDomainInputData.usVHeight;
    
    if(GET_3D_INPUT_FORMAT() == _FRAME_PACKING)
    {
        if(GET_INTERLACED_MODE() == _TRUE)
        {
            // Input (Ro + Re), Display (Ro or Re)
            usIVH = usIVH << 1;
        }
        
        // 1080p, 720p
        // DEN/ActiveSpace = _3D_FP_DEN_ACTIVESPACE_RATIO. e.g. 1080p: 2160/45 = 48
        usActiveSpace = (DWORD)usIVH / _3D_FP_DEN_ACTIVESPACE_RATIO;

        if(usIVH == 480)
        {
            usActiveSpace = 45;
        }
        else if(usIVH == 576)
        {
            usActiveSpace = 49;
        }
        
        if(GET_INTERLACED_MODE() == _TRUE)
        {
            usActiveSpace = usActiveSpace / 2 + 1;
        }
    }
    
    // DHFreq
    PDATA_WORD(2) = ((DWORD)GET_D_CLK_FREQ() * 10 / g_stMDomainOutputData.usHTotal); 
    
    DebugMessageFRC(" - ActiveSpace", usActiveSpace);
    DebugMessageFRC("ivs2dvs_DHF", PDATA_WORD(2));

    switch(GET_3D_INPUT_FORMAT())
    {
        case _TOP_AND_BOTTOM:
        case _FRAME_PACKING:
        case _FRAME_SEQUENTIAL:
            
            // TnB, FP :  60 to 60 Hz / 30Hz to 60Hz / 25Hz to 50Hz  
            if(GET_MEMORY_DVF_SELECT() == _1_IVF)
            {
                // IVS2DVSDelay + DVStart + DVH > IVT
                PDATA_WORD(1) = g_stMDomainInputData.usVTotal + _IVS2DVS_DELAY_MARGIN - (DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usHFreq / PDATA_WORD(2);

                // IVS2DVSDelay + DVStart > IVStart + half frame size
                PDATA_WORD(0) = ScalerVgipGetCaptureVStartPosition() + (usIVH / 2 + usActiveSpace + _IVS2DVS_DELAY_MARGIN) - (DWORD)g_stMDomainOutputData.usVStart * g_stMDomainInputData.usHFreq / PDATA_WORD(2);

                DebugMessageFRC("P1", PDATA_WORD(1));
                DebugMessageFRC("P0", PDATA_WORD(0));
                
                PDATA_WORD(0) = (PDATA_WORD(0) > PDATA_WORD(1)) ? (PDATA_WORD(0)) : PDATA_WORD(1);
                break;
            }
            else if(GET_MEMORY_DVF_SELECT() == _2_IVF)
            {
                // IVS2DVSDelay + DVStart > IVStart + half frame size
                PDATA_WORD(0) = ScalerVgipGetCaptureVStartPosition() + (usIVH / 2 + usActiveSpace + _IVS2DVS_DELAY_MARGIN) - (DWORD)g_stMDomainOutputData.usVStart * g_stMDomainInputData.usHFreq / PDATA_WORD(2);
                break;
            }
                       
        case _SIDE_BY_SIDE_HALF:
        case _LINE_INTERLACE:

            if(GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF)
            {
                // Recover IVH for Scaling down reset
                usIVH = usIVH / 2;
            }

            if(GET_MEMORY_DVF_SELECT() == _2_5_IVF)
            {
                // TnB, FP, SBS: 24Hz to 60Hz
                // 2IVTotal = IVS2DVSDelay + (DVTotal * 4 + DVStart + DVHeight) * IHF / DHF
                // (DVT = 2/5 * IVT)
                //  --> IVS2DVSDelay = (IVT * 2 / 3) - (DVStart + DVHeight) * IHF / DHF
                PDATA_WORD(0) = (g_stMDomainInputData.usVTotal * 2 / 5) - (DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usHFreq / PDATA_WORD(2);
            }
            else if(GET_MEMORY_DVF_SELECT() == _3_IVF)
            {
                // TnB, FP : 24Hz to 72Hz
                // SbS : 24Hz to 72Hz / 24Hz to 60Hz
                // IVTotal < IVS2DVSDelay + (DVTotal *2 + DVStart + DVHeight) * IHF / DHF
                // (DVT = 1 / 3 * IVT)
                // --> IVS2DVSDelay > (IVT * 1 / 3) - (DVStart + DVHeight) * IHF / DHF
                PDATA_WORD(0) = (g_stMDomainInputData.usVTotal * 1 / 3 + _IVS2DVS_DELAY_MARGIN) - (DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usHFreq / PDATA_WORD(2);
            }
            else if(GET_MEMORY_DVF_SELECT() == _1_IVF)
            {                    
                // Measure Display Active Region
                ScalerMeasureSetRegionCount(_MEASURE_TARGET_DISPLAY, _ACTIVE_REGION_TYPE);
                ulDActiveCount = ScalerMeasureGetRegionCountResult(_WAIT);

                DebugMessageFRC("ulIActiveCount", g_ulActiveRegionBackUp);
                DebugMessageFRC("ulDActiveCount", ulDActiveCount);
                
                if(g_ulActiveRegionBackUp >= ulDActiveCount)
                {
                    PDATA_WORD(0) = (DWORD)(ScalerVgipGetCaptureVStartPosition() + usIVH) - (DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usHFreq / PDATA_WORD(2);
                    PDATA_WORD(0) += g_stMDomainInputData.usVHeight / 100; // Margin
                }
                else
                {
                    PDATA_WORD(0) = (DWORD)(ScalerVgipGetCaptureVStartPosition() + g_stMDomainInputData.usVHeight / 100) - ((DWORD)g_stMDomainOutputData.usVStart * g_stMDomainInputData.usHFreq / PDATA_WORD(2));                    
                }
            }
            else
            {
                // IVStart + IVHeight < IVS2DVSDelay + (DVStart + DVHeight) * IHF / DHF
                // IVS2DVSDelay > IVStart + IVHeight - (DVStart + DVHeight) * IHF / DHF
                PDATA_WORD(0) = ScalerVgipGetCaptureVStartPosition() + (usIVH + _IVS2DVS_DELAY_MARGIN) - (DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usHFreq / PDATA_WORD(2);                                
            }             

            break;

        default:

            break;
    }
    
    if((PDATA_WORD(0) > 0xF00) || (PDATA_WORD(0) == 0))
    {
        PDATA_WORD(0) = 0x01;
    }

    // Before is frame sync mode, current is frame sync mode, check IVS2DVS delay change
    if((GET_MEMORY_SELECT() == _FRAME_SYNC_SDRAM) && (ScalerGetBit(CM_28_VDISP_CTRL, _BIT3) == _BIT3))
    {
        // Get old IVS2DVS setting
        PDATA_DWORD(1) = (((WORD)((ScalerGetByte(CM_3E_IVS2DVS_DEALY_LINES_H)) & 0x0F) << 8) | ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES));

        // old > new, Calculate old and new IVS2DVS diff. No need to consider IVSdelay( setting before in 3D case)
        PDATA_DWORD(1) -= (PDATA_DWORD(1) > PDATA_WORD(0)) ? PDATA_WORD(0) : PDATA_DWORD(1);    

        
        if((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D))
        {
            PDATA_WORD(7) = 2 * g_stMDomainInputData.usVHeight;
        }
        else if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
        {
            PDATA_WORD(7) = g_stMDomainInputData.usVHeight / 2;
        }
        else
        {
            PDATA_WORD(7) = g_stMDomainInputData.usVHeight;
        }

        // IVS2DVS diff (D_line)
        PDATA_DWORD(1) = PDATA_DWORD(1) * g_stMDomainOutputData.usVBackHeight / PDATA_WORD(7);

        // Display front porch (D_line)
        PDATA_DWORD(2) = (DWORD)(g_stMDomainOutputData.usVTotal - g_stMDomainOutputData.usVBackHeight - g_stMDomainOutputData.usVStart);        

        // IVS2DVS diff > Display front porch
        if(PDATA_DWORD(1) > PDATA_DWORD(2))
        { 
            ScalerSetBit(CM_44_LAST_LINE_H, ~_BIT7, _BIT7);
            
            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);

            // Current DVtotal
            PDATA_WORD(7) = (((ScalerGetByte(CM_44_LAST_LINE_H) & 0x0F) << 8) | ScalerGetByte(CM_45_LAST_LINE_L));
            PDATA_WORD(1) = 2 * PDATA_WORD(7) - PDATA_DWORD(1);

            ScalerSetBit(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(PDATA_WORD(1))) & 0x0F);
            ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, (LOBYTE(PDATA_WORD(1))));    

            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

            ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT3, 0x00);

            // Set IVSToDVSDealy
            ScalerSetBit(CM_3E_IVS2DVS_DEALY_LINES_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), pData[0] & 0x0F);
            ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[1]);     
            ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, 0x00);

            ScalerSetBit(CM_10_VGIP_CTRL, ~_BIT5, _BIT5);

            // Wait double buffer
            ScalerTimerWaitForEvent(_EVENT_IVS);  
            ScalerTimerWaitForEvent(_EVENT_IVS);              

            ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT3, _BIT3);                
            
            return;             
        } 
    }   
    
    // Set IVSToDVSDealy
    ScalerSetBit(CM_3E_IVS2DVS_DEALY_LINES_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), pData[0] & 0x0F);
    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[1]);

    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, 0x00);

    // Set Frame sync 
    ScalerSetBit(CM_28_VDISP_CTRL, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));    
}

//--------------------------------------------------
// Description  : FIFO Capture Setting for 3D Mode
// Input Value  : ucHorSize --> Horizontal size
//                ucVerSize --> Vertical Size
// Output Value : None
//--------------------------------------------------
void Scaler3DInputCtrlPRType(WORD usHorSize, WORD usVerSize)
{
    StructSDRAMLineBlockStep stStep;

    if((GET_3D_INPUT_FORMAT()== _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
    {
        usVerSize = usVerSize << 1;
    }

    DebugMessageFRC("I_H", usHorSize);
    DebugMessageFRC("I_V", usVerSize);
    
    // Line mode
    // One line total pixel for SDRAM (unit : 64 bits)
    PDATA_DWORD(0) = ((DWORD)usHorSize * _BIT_PER_PIXEL % 64) ? 
                     (((DWORD)usHorSize * _BIT_PER_PIXEL / 64) + 1) : 
                     ((DWORD)usHorSize * _BIT_PER_PIXEL / 64);

#if((_OD_SUPPORT == _ON) || (_SDRAM_PHASE_CALIBRATION == _ON))
    if(((GET_MEMORY_DVF_SELECT() == _2_5_IVF) || (GET_MEMORY_DVF_SELECT() == _3_IVF)) && 
       (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR) &&
       ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)))
    {
        // Avoid OD data overlap R image before R output in LR display.
        PDATA_DWORD(1) = (((DWORD)usHorSize + _3_BLOCK_OD_MARGIN) * _BIT_PER_PIXEL % 64) ? 
                         ((((DWORD)usHorSize + _3_BLOCK_OD_MARGIN) * _BIT_PER_PIXEL / 64) + 1) : 
                         (((DWORD)usHorSize + _3_BLOCK_OD_MARGIN) * _BIT_PER_PIXEL / 64);
                         
        // Calculate line step and block step
        stStep = ScalerSDRAMCalculateLineStepAndBlockStep(PDATA_DWORD(1), usVerSize);
    }
    else
#endif
    {
        // Calculate line step and block step
        stStep = ScalerSDRAMCalculateLineStepAndBlockStep(PDATA_DWORD(0), usVerSize);
    }

    DebugMessageFRC("I-Block", stStep.ulBlockStep);
    DebugMessageFRC("I-line", stStep.usLineStep);

    // Set Line mode
    ScalerSetBit(P5_B7_SDRF_IN1_LINE_NUM_H, ~_BIT4, 0x00);  
    	
    // Disable Half line process for Side-by-side
    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
    ScalerSetBit(P5_A5_SDRF_IN1_3D_FRC_CTL, ~_BIT0, 0x00);
    ScalerSetBit(P5_A6_SDRF_IN1_PXL_NUM_H, ~_BIT5, 0x00);

    // IVS ( between L and R ) mask disable
    ScalerSetBit(P5_A5_SDRF_IN1_3D_FRC_CTL, ~_BIT4, 0x00);       
    
    // Set line number
    ScalerSetBit(P5_B7_SDRF_IN1_LINE_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((usVerSize >> 8) & 0x0F));
    ScalerSetByte(P5_B8_SDRF_IN1_LINE_NUM_L, LOBYTE(usVerSize));

    // Calculate number and remain size
    PDATA_DWORD(0) = ScalerSDRAMCalculateNumberAndRemain(PDATA_DWORD(0), _SDRAM_ACCESS_WRITE_LENGTH, 1);

    ScalerSetByte(P5_A8_SDRF_IN1_WATER_LEVEL, _SDRAM_ACCESS_WRITE_LENGTH);
    ScalerSetByte(P5_A9_SDRF_IN1_WR_NUM_H, pData[2]);
    ScalerSetByte(P5_AA_SDRF_IN1_WR_NUM_L, pData[3]);
    ScalerSetByte(P5_AB_SDRF_IN1_WR_LEN, _SDRAM_ACCESS_WRITE_LENGTH);
    ScalerSetByte(P5_AC_SDRF_IN1_WR_REMAIN, pData[1]);
    ScalerSetByte(P5_B0_SDRF_IN1_LINE_STEP_H, HIBYTE(stStep.usLineStep));
    ScalerSetByte(P5_B1_SDRF_IN1_LINE_STEP_L, LOBYTE(stStep.usLineStep));
    ScalerSetByte(P5_B2_SDRF_IN1_BLOCK_STEP_H, HIBYTE((WORD)(stStep.ulBlockStep >> 11)));
    ScalerSetByte(P5_B3_SDRF_IN1_BLOCK_STEP_L, LOBYTE((WORD)(stStep.ulBlockStep >> 11)));
    ScalerSetByte(P5_B4_SDRF_IN1_BL2_ADDR_H, (BYTE)(stStep.ulBlockStep >> 16));
    ScalerSetByte(P5_B5_SDRF_IN1_BL2_ADDR_M, (BYTE)(stStep.ulBlockStep >> 8));
    ScalerSetByte(P5_B6_SDRF_IN1_BL2_ADDR_L, (BYTE)(stStep.ulBlockStep));

    // Set Capture address index = 0
    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);

    // Set Capture write address
    if((((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR))  ||
        ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_INTERLACED_MODE() == _TRUE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)) ||
        ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_INTERLACED_MODE() == _FALSE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR)))
    {
        // FP and TB use field merge mode (read form block 2 and 3), thus FRC writes in block2's address.
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, (BYTE)((DWORD)stStep.ulBlockStep >> 16));
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, (BYTE)((DWORD)stStep.ulBlockStep >> 8));
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, (BYTE)((DWORD)stStep.ulBlockStep >> 0));
    }
    else
    {
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 16));
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 8));
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 0));
    }
    
    // Set Pixel unmber = Input line pixel
    ScalerSetBit(P5_A6_SDRF_IN1_PXL_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((HIBYTE(usHorSize)) & 0x0F));
    ScalerSetByte(P5_A7_SDRF_IN1_PXL_NUM_L, LOBYTE(usHorSize));


    // 3D only uses Single Buffer mode
    ScalerSetBit(P5_B9_SDRF_IN1_SDR_CTRL, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);    

    // Set M:N auto block toggle
    if((GET_MEMORY_DVF_SELECT() == _2_5_IVF) || 
       (GET_MEMORY_DVF_SELECT() == _3_IVF) || 
       ((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))        
    {
#if(_OD_SUPPORT == _ON)
        // OD + FP 2D display use Single buffer read and write.
        // (if 3block toggle, OD data is overlay by next frame data)
        if((GET_3D_INPUT_FORMAT() != _FRAME_PACKING) ||
           ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))
#endif            
        {
            Scaler3DSetInputAutoBlkTogglePRType(stStep.ulBlockStep);
        }
    }    
    
    // disable freeze mode
    ScalerSetBit(P5_B9_SDRF_IN1_SDR_CTRL, ~(_BIT2), 0x00);    
    
    // Use IVS as synchronous reset
    ScalerSetBit(P5_B9_SDRF_IN1_SDR_CTRL, ~(_BIT1), _BIT1);    

    // Enable Capture block
    ScalerSetBit(P5_B9_SDRF_IN1_SDR_CTRL, ~(_BIT7), _BIT7);

    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) 
    {
        ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
        ScalerSetBit(P5_A5_SDRF_IN1_3D_FRC_CTL, ~_BIT0, _BIT0);

        if((GET_V_SCALE_DOWN() == _TRUE) || (GET_V_SCALE_DOWN_2_DIFF_PHASE() == _TRUE))
        {
            // SBS reset + VSD make R and L line too close to FRC dummy data overlay L line.
            // Thus set P5-A6[5] = 1 ( plus 23 cycle delay between R and L line)
            ScalerSetBit(P5_A6_SDRF_IN1_PXL_NUM_H, ~_BIT5, _BIT5);
        }
    }
    else if((GET_3D_INPUT_FORMAT()== _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
    {
        // IVS mask enable
        // (FS and FP can treat as the same case)
        ScalerSetBit(P5_A5_SDRF_IN1_3D_FRC_CTL, ~_BIT4, _BIT4);
    }
}

//--------------------------------------------------
// Description  : FIFO Display Setting for 3D Mode
// Input Value  : usHorSize --> Horizontal size
//                usVerSize --> Vertical Size
// Output Value : None
//--------------------------------------------------
void Scaler3DDisplayCtrlPRType(WORD usHorSize, WORD usVerSize)
{
    StructSDRAMLineBlockStep stStep;

    // Set line number    
    ScalerSetBit(P5_CD_SDRF_MN_LINE_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0),  HIBYTE(usVerSize) & 0x0F);
    ScalerSetByte(P5_CE_SDRF_MN_LINE_NUM_L, LOBYTE(usVerSize));

    if(((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) || 
       ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) ||
       ((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))
    {
        // field merge L image(1/2 frame size) and R image(1/2 frame size).
        usVerSize = usVerSize >> 1;
    }

    DebugMessageFRC("O_H", usHorSize);
    DebugMessageFRC("O_V", usVerSize);
    
    // Line mode
    // One line total pixel for SDRAM (unit : 64 bits)
    PDATA_DWORD(0) = ((DWORD)usHorSize * _BIT_PER_PIXEL % 64) ?
                     (((DWORD)usHorSize * _BIT_PER_PIXEL / 64) + 1) :
                     ((DWORD)usHorSize * _BIT_PER_PIXEL / 64);
    
#if((_OD_SUPPORT == _ON) || (_SDRAM_PHASE_CALIBRATION == _ON))
    if(((GET_MEMORY_DVF_SELECT() == _2_5_IVF) || (GET_MEMORY_DVF_SELECT() == _3_IVF)) && 
       (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR) &&
       ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)))
    {
        // Avoid OD data overlap R image before R output in LR display.
        PDATA_DWORD(1) = (((DWORD)usHorSize + _3_BLOCK_OD_MARGIN) * _BIT_PER_PIXEL % 64) ? 
                         ((((DWORD)usHorSize + _3_BLOCK_OD_MARGIN) * _BIT_PER_PIXEL / 64) + 1) : 
                         (((DWORD)usHorSize + _3_BLOCK_OD_MARGIN) * 3 * 8 / 64);
                         
        // Calculate Line step and block step
        stStep = ScalerSDRAMCalculateLineStepAndBlockStep(PDATA_DWORD(1), usVerSize);
    }
    else
#endif
    {
        // Calculate Line step and block step
        stStep = ScalerSDRAMCalculateLineStepAndBlockStep(PDATA_DWORD(0), usVerSize);
    }

    // Set Line mode
    ScalerSetBit(P5_CD_SDRF_MN_LINE_NUM_H, ~_BIT4, 0x00);

    // Calculation Number and Ramain
    PDATA_DWORD(0) = ScalerSDRAMCalculateNumberAndRemain(PDATA_DWORD(0), _SDRAM_ACCESS_READ_LENGTH, 0);

    // Set Number, Remain and Length
    ScalerSetByte(P5_C2_SDRF_MN_READ_NUM_H, pData[2]);
    ScalerSetByte(P5_C3_SDRF_MN_READ_NUM_L, pData[3]);
    ScalerSetByte(P5_C4_SDRF_MN_READ_LEN, _SDRAM_ACCESS_READ_LENGTH);
    ScalerSetByte(P5_C5_SDRF_MN_READ_REMAIN, pData[1]);

    // Set Pixel number of one line
    ScalerSetBit(P5_BE_SDRF_MN_PXL_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(usHorSize) & 0x0F));
    ScalerSetByte(P5_BF_SDRF_MN_PXL_NUM_L, LOBYTE(usHorSize));

    // SD engine rearrange SbS as line interleave
    if(((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)) ||
       ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)) ||
       ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)))
    {
        // For 2D, line step = 2 line, block step = usHorSize * usVerSize.
        // For RL, line step = 2 line, block step = l line.  

        if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)
        {   
            stStep.ulBlockStep = stStep.usLineStep;        
        }   

        pData[0] = (stStep.usLineStep & 0xFF); // Backup Column[7:0]
        stStep.usLineStep = ((((stStep.usLineStep >> 1) & 0xFF00) | pData[0]) << 1); // Column[8] is useless
        pData[0] = (stStep.usLineStep & 0xFF); // Backup Column[7:0]
        stStep.usLineStep = (((stStep.usLineStep & 0xFF00) << 1)  | pData[0]); // Recovery Colume[8] 
    }    

    pData[0] = (stStep.ulBlockStep & 0xFF);
    stStep.ulBlockStep = (((stStep.ulBlockStep >> 1) & 0xFFFFFF00) | pData[0]);

    DebugMessageFRC("O-Block", stStep.ulBlockStep);
    DebugMessageFRC("O-line", stStep.usLineStep);
    
    // Set address index = 0
    ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00); 
    
    // Set Block step
    if((((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) || (GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE)) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)) ||
       ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_INTERLACED_MODE() == _TRUE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR)) ||
       ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_INTERLACED_MODE() == _FALSE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)))
    {
        //==================================
        //
        //  --------------      <<<<<<--
        //  |  L image  |  Block3       | Actually, read data from Block2(lst) and Block3(2nd) respectively.
        //  --------------      <<<<<<-- 
        //  |  R image  |  Block2
        //  --------------
        //  |           |  Block1
        //  --------------      <<<<<<--  Set read start address.
        //  |           |  Block0
        //  --------------     
        //
        //==================================
        //Set Block step
        PDATA_DWORD(0) = ((~(stStep.ulBlockStep) + 1) & 0x3FFFFF);
        ScalerSetBit(P5_CB_SDRF_MN_BLOCK_STEP_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((BYTE)(PDATA_DWORD(0) >> 18) & 0x0F));  // Block step[22:19]
        ScalerSetByte(P5_CC_SDRF_MN_BLOCK_STEP_L, ((BYTE)(PDATA_DWORD(0) >> 10)));  // Block step[18:11]
        ScalerSetBit(P5_EB_SDRF_MN_BLOCK_STEP_BANK, ~(_BIT2 | _BIT1 | _BIT0), ((BYTE)((PDATA_DWORD(0) >> 8) & 0x03) << 1)); // Block step[10:8]
        ScalerSetByte(P5_EC_SDRF_MN_BLOCK_STEP_COL, (BYTE)PDATA_DWORD(0));          // Block step[7:0]    

        // Set display initial address
        PDATA_DWORD(0) =  (stStep.ulBlockStep * 3);
        ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, (BYTE)(PDATA_DWORD(0) >> 16));
        ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, (BYTE)(PDATA_DWORD(0) >> 8));
        ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, (BYTE)(PDATA_DWORD(0) >> 0));    
    }
    else
    {
        //Set Block step
        ScalerSetBit(P5_CB_SDRF_MN_BLOCK_STEP_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((BYTE)(stStep.ulBlockStep >> 18) & 0x0F));  // Block step[22:19]
        ScalerSetByte(P5_CC_SDRF_MN_BLOCK_STEP_L, (BYTE)((stStep.ulBlockStep) >> 10));  // Block step[18:11]
        ScalerSetBit(P5_EB_SDRF_MN_BLOCK_STEP_BANK, ~(_BIT2 | _BIT1 | _BIT0), ((BYTE)((stStep.ulBlockStep >> 8) & 0x03) << 1));   // Block step[10:8]
        ScalerSetByte(P5_EC_SDRF_MN_BLOCK_STEP_COL, (BYTE)stStep.ulBlockStep);          // Block step[7:0]    

        // Set display initial address
        ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 16));
        ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 8));
        ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 0));    
    }
    
    // Set Pre-read line
    ScalerSetByte(P5_BC_SDRF_MN_PRERD_VST_H, HIBYTE(g_stMDomainOutputData.usVStart - _PREREAD_MARGIN));
    ScalerSetByte(P5_BD_SDRF_MN_PRERD_VST_L, LOBYTE(g_stMDomainOutputData.usVStart - _PREREAD_MARGIN));

    // Set Water level
    ScalerSetByte(P5_C0_SDRF_MN_WTLVL, _SDRAM_ACCESS_READ_LENGTH);

    //Set Line step
    ScalerSetBit(P5_C9_SDRF_MN_LINE_STEP_H, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(stStep.usLineStep) & 0x3F));
    ScalerSetByte(P5_CA_SDRF_MN_LINE_STEP_L, LOBYTE(stStep.usLineStep));

    // Set M:N auto block toggle
    if((GET_MEMORY_DVF_SELECT() == _2_5_IVF) || 
       (GET_MEMORY_DVF_SELECT() == _3_IVF) || 
       ((GET_3D_INPUT_FORMAT()== _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))        
    {
#if(_OD_SUPPORT == _ON)  
        // OD + FP 2D display use Single buffer read and write.
        // (if 3block toggle, OD data is overlay by next frame data)
        if((GET_3D_INPUT_FORMAT() != _FRAME_PACKING) ||
            ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))
#endif 
        { 
            Scaler3DSetDisplayAutoBlkTogglePRType(stStep.ulBlockStep);
            ScalerSDRAMSetHWAutoBlockToggle();
        }
    }    

    // Set input format 24 / 18 / 16 bit
#if(_BIT_PER_PIXEL == 24)   
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT0, 0x00); 
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT7, 0x00);    
#elif(_BIT_PER_PIXEL == 18)
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT0, _BIT0);    
#elif(_BIT_PER_PIXEL == 16)
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT0, 0x00); 
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT7, _BIT7);    
#endif
    
    // Set input slower/faster
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT3, ((g_stMDomainInputData.usVFreq > _PANEL_MAX_FRAME_RATE) ? (_BIT3) : (0x00)));        

    if((((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) || (GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) ||
       ((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)) ||
       ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)))
    {
        // Set field merge mode
        ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT6 | _BIT5 | _BIT4), _BIT6 | _BIT5);    
    }
    else
    {
        if((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && 
           (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) &&
           (GET_INTERLACED_MODE() == _TRUE))
        {
            // Set line number    
            ScalerSetBit(P5_CD_SDRF_MN_LINE_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0),  HIBYTE(usVerSize) & 0x0F);
            ScalerSetByte(P5_CE_SDRF_MN_LINE_NUM_L, LOBYTE(usVerSize));
            
            // Input (Ro + Re), Single buffer  
            // Display (Ro or Re), Double buffer
            
            // Set input faster
            ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT3, _BIT3);
            
            // Set Double buffer
            ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT6 | _BIT5 | _BIT4), _BIT6);    
        }
        else
        {
            // Set Single buffer
            ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT6 | _BIT5 | _BIT4), 0x00);    
        }
    }
    
    // Use information from Capture
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT2 | _BIT1), 0x00);    
    
    // Enable Display
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT0, _BIT0);    

    // Enable Display double buffer
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT4, _BIT4); 

    // Wait double buffer
    ScalerTimerPollingFlagProc(_SDRAM_DISPLAY_SETTING_READY_TIME, P5_D0_SDRF_MN_SDR_STATUS, _BIT4, 0);
}

#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
//--------------------------------------------------
// Description  : Set Input adderss for auto block toggle   
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void Scaler3DSetInputAutoBlkToggleShutterType(void)
{
    // 1st Write Address
    PDATA_DWORD(0) = (((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_H << 16) + ((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_M << 8));
    
    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
    ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, pData[1]);
    ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, pData[2]);
    ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, pData[3]);
    DebugMessageFRC("-I_addr1", PDATA_DWORD(0));
    
    // 2nd Write Address
    PDATA_DWORD(0) = (((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_H << 16) + ((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_M << 8));
    
    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT2);
    ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, pData[1]);
    ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, pData[2]);
    ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, pData[3]);
    DebugMessageFRC("-I_addr2", PDATA_DWORD(0));
    
    // 3rd Write Address
    PDATA_DWORD(0) = (((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_H << 16) + ((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_M << 8));

    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT3);
    ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, pData[1]);
    ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, pData[2]);
    ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, pData[3]);
    DebugMessageFRC("-I_addr3", PDATA_DWORD(0));
}

//--------------------------------------------------
// Description  : Set display adderss for auto block toggle   
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void Scaler3DSetDisplayAutoBlkToggleShutterType(void)
{
    // 1st Read Address
    PDATA_DWORD(0) = (((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_H << 16) | ((DWORD)_3D_W_1ST_BLOCK_STA_ADDR_M << 8));
    PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);

    ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
    ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, pData[1]);
    ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, pData[2]);
    ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, pData[3]);
    DebugMessageFRC("-D_addr1", ((DWORD *)pData)[0]);

    // 2nd Read Address
    PDATA_DWORD(0) = (((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_H << 16) | ((DWORD)_3D_W_2ND_BLOCK_STA_ADDR_M << 8));
    PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1); 

    ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT2);
    ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, pData[1]);
    ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, pData[2]);
    ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, pData[3]);
    DebugMessageFRC("-D_addr2", ((DWORD *)pData)[0]);

    // 3rd Read Address
    PDATA_DWORD(0) = (((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_H << 16) | ((DWORD)_3D_W_3RD_BLOCK_STA_ADDR_M << 8));
    PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);    	

    ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT3);
    ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, pData[1]);
    ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, pData[2]);
    ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, pData[3]);    
    DebugMessageFRC("-D_addr3", ((DWORD *)pData)[0]);
}

//--------------------------------------------------
// Description  : Set auto block toggle
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void Scaler3DSetHWAutoBlockToggleShutterType(void)
{
    BYTE ucM = 1;
    BYTE ucN = 1;

    // Multiple of hardware auto toggle among three initial read address
    // Set Multiple = 2
    ScalerSetBit(P5_BE_SDRF_MN_PXL_NUM_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (1 << 4));
    
    // Set Shift = 0 
    ScalerSetBit(P5_CB_SDRF_MN_BLOCK_STEP_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (0 << 4));
    
    if((GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) && (GET_MEMORY_DVF_SELECT() == _2_5_IVF))
    {
        PDATA_WORD(0) = ScalerSDRAMGetMNRatio();

        ucM = ((PDATA_WORD(0) >> 8) & 0xFF);
        ucN = (PDATA_WORD(0) & 0xFF);
        
        // Remain of hardware auto toggle among three initial read address, and it is (N%M)/N * 2^10.(11bit in total)    
        PDATA_WORD(0) = (((ucN % ucM) << 10) / ucN);
        PDATA_WORD(0) += 1;
        
        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT7 | _BIT6 | _BIT5), ((pData[0] << 5) & 0xFF));
        ScalerSetByte(P5_FF_SDRF_MN_MADDR_TOG_REM, (pData[1] & 0xFF));
    }
    else
    {
        // Remain of hardware auto toggle among three initial read address, and it is (N%M)/N * 2^10.(11bit in total)    
        // Set Remain = 0
        ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
        ScalerSetByte(P5_FF_SDRF_MN_MADDR_TOG_REM, 0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust IVS2DVS Delay for Aspect Ratio Function
// Input Value  : ulFreq --> DCLK
// Output Value : IVS2DVS Delay Lines
//--------------------------------------------------
void Scaler3DAdjustIVS2DVSDelayShutterType(DWORD ulClk)
{
    WORD usActiveSpace = 0;
    WORD usIVH;

    usIVH = g_stMDomainInputData.usVHeight;

    if((((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && 
         ((GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) || (GET_MEMORY_DVF_SELECT() == _1_IVF))) ||
       ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_INTERLACED_MODE() == _TRUE)))
    {
        // Recovery IVH (VGIP Mask half frame)
        usIVH = usIVH << 1;
    }

    if(GET_3D_INPUT_FORMAT() == _FRAME_PACKING)
    {
        usActiveSpace = (DWORD)usIVH / _3D_FP_DEN_ACTIVESPACE_RATIO;

        if(usIVH == 960) // 480*2 = 960
        {
            // 480p
            usActiveSpace = 45;
        }
        else if(usIVH == 1152) // 576*2 = 1152
        {
            // 576p
            usActiveSpace = 49;
        }
        
        if(GET_INTERLACED_MODE() == _TRUE)
        {
            usActiveSpace = usActiveSpace / 2 + 1;
            
            // usIVH = Odd or Even field size.
            usIVH = usIVH >> 1;
        }
    }

    // DHFreq
    PDATA_WORD(0) = ((DWORD)ulClk * 10 / g_stMDomainOutputData.usHTotal); 
    
    DebugMessageFRC(" - interlace", GET_INTERLACED_MODE());
    DebugMessageFRC(" - ActiveSpace", usActiveSpace);
    DebugMessageFRC("ivs2dvs_IHF", g_stMDomainInputData.usHFreq);
    DebugMessageFRC("ivs2dvs_DHF", PDATA_WORD(0));

    switch(GET_3D_INPUT_FORMAT())
    {
        case _TOP_AND_BOTTOM:
        case _FRAME_PACKING:

            switch(GET_MEMORY_DVF_SELECT())
            {
                case _2_IVF:

                    if(GET_INTERLACED_MODE() != _TRUE)
                    {
                        // TB 25Hz / 30Hz
                        // IVS2DVSDelay + DVStart + DVHeight > IVStart + IVH/2
                        PDATA_WORD(2) = (ScalerVgipGetCaptureVStartPosition() + usIVH / 2 + usActiveSpace + _IVS2DVS_DELAY_MARGIN - 
                                        (DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usHFreq / PDATA_WORD(0));

                        PDATA_WORD(2) = (PDATA_WORD(2) > 0xF00) ? (1) : (PDATA_WORD(2));
                        
                        // IVS2DVSDelay + DVStart > IVStart
                        PDATA_WORD(1) = ScalerVgipGetCaptureVStartPosition() + _IVS2DVS_DELAY_MARGIN -
                                        (DWORD)g_stMDomainOutputData.usVStart * g_stMDomainInputData.usHFreq / PDATA_WORD(0);
                        
                        PDATA_WORD(1) = (PDATA_WORD(1) > 0xF00) ? (1) : (PDATA_WORD(1));
                        
                        PDATA_WORD(0) = (PDATA_WORD(2) > PDATA_WORD(1)) ? (PDATA_WORD(2)) : (PDATA_WORD(1));

                        DebugMessageFRC("1-end", PDATA_WORD(1));
                        DebugMessageFRC("2-start", PDATA_WORD(2));
                        
                        break;
                    }
                
                case _1_IVF:
                    
                    // IVS2DVSDelay + DVS > IVStart + IVH/2
                    PDATA_WORD(0) = (ScalerVgipGetCaptureVStartPosition() + usIVH / 2 + usActiveSpace + _IVS2DVS_DELAY_MARGIN - 
                                    (DWORD)g_stMDomainOutputData.usVStart * g_stMDomainInputData.usHFreq / PDATA_WORD(2));

                    break;

                case _2_5_IVF:

                    if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
                    {
                        // IVS2DVSDelay + DVTotal + DVStart + DVHeight > IVStart + IVH
                        PDATA_WORD(0) = (ScalerVgipGetCaptureVStartPosition() + usIVH + usActiveSpace + _IVS2DVS_DELAY_MARGIN) - ((DWORD)g_stMDomainInputData.usVTotal * 2 / 5) -
                                        (DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usHFreq / PDATA_WORD(0);
                    }
                    else
                    {
                        PDATA_WORD(0) = 1;
                    }
                    
                    break;
                    
                default:
                    
                    PDATA_WORD(0) = 1;
                    
                    break;
            }
            
            break; 

        case _SIDE_BY_SIDE_HALF:
        case _LINE_INTERLACE:

            switch(GET_MEMORY_DVF_SELECT())
            {
                case _1_IVF:
                    
                    // IVS2DVSDelay + DVStart + DVHeight = IVTotal
                    PDATA_WORD(0) = g_stMDomainInputData.usVTotal - (DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight) * g_stMDomainInputData.usHFreq / PDATA_WORD(0);
                    
                    break;

                case _2_5_IVF:
                    
                    // 2*IVTotal + IVStart + IVHeight < IVS2DVSDelay + (DVTotal * 6 + DVStart + DVHeight) * IHF / DHF
                    PDATA_WORD(0) = ScalerVgipGetCaptureVStartPosition() + g_stMDomainInputData.usVHeight + _IVS2DVS_DELAY_MARGIN - 
                                    ((DWORD)(g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight + _PANEL_DV_TOTAL) * g_stMDomainInputData.usHFreq / PDATA_WORD(0));
                    
                    break;
                    
                case _2_IVF:
                default:
                    
                    PDATA_WORD(0) = 0x01; // DVStart before IVStart
                    
                    break;
            }

            break;

        default:

            PDATA_WORD(0) = 0x01;
            
            break;
    }
    
    DebugMessageFRC("MAX delay", ((WORD *)pData)[0]);
    DebugMessageFRC("IVS", ScalerVgipGetCaptureVStartPosition());
    DebugMessageFRC("IVH", usIVH);
    DebugMessageFRC("IVT", g_stMDomainInputData.usVTotal);
    DebugMessageFRC("DVS", g_stMDomainOutputData.usVStart);
    DebugMessageFRC("DVH", g_stMDomainOutputData.usVHeight);        

    if((PDATA_WORD(0) > 0xF00) || (PDATA_WORD(0) == 0))
    {
        PDATA_WORD(0) = 0x01;
    }
    
    // Set IVSToDVSDealy
    ScalerSetBit(CM_3E_IVS2DVS_DEALY_LINES_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), pData[0] & 0x0F);
    ScalerSetByte(CM_40_IVS2DVS_DEALY_LINES, pData[1]);

    ScalerSetByte(CM_41_IV_DV_DELAY_CLK_ODD, 0x00);

    // Set Frame sync 
    ScalerSetBit(CM_28_VDISP_CTRL, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));        
}

//--------------------------------------------------
// Description  : FIFO Capture Setting for 3D Mode
// Input Value  : ucHorSize --> Horizontal size
//                ucVerSize --> Vertical Size
// Output Value : None
//--------------------------------------------------
void Scaler3DInputCtrlShutterType(WORD usHorSize, WORD usVerSize)
{
    StructSDRAMLineBlockStep stStep;

    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && 
       (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D) &&
       (GET_MEMORY_DVF_SELECT() != _1_IVF))
    {
        // FRC Half line process
        usHorSize = (usHorSize >> 1);
        usVerSize = (usVerSize << 1);
    }

    DebugMessageFRC("I_H", usHorSize);
    DebugMessageFRC("I_V", usVerSize);
    
    // Line mode
    // One line total pixel for SDRAM (unit : 64 bits)
    PDATA_DWORD(0) = ((DWORD)usHorSize * _BIT_PER_PIXEL % 64) ? 
                     (((DWORD)usHorSize * _BIT_PER_PIXEL / 64) + 1) : 
                     ((DWORD)usHorSize * _BIT_PER_PIXEL / 64);

    // Set Line mode
    ScalerSetBit(P5_B7_SDRF_IN1_LINE_NUM_H, ~_BIT4, 0x00);  
    	
    // Disable Half line process for Side-by-side
    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
    ScalerSetBit(P5_A5_SDRF_IN1_3D_FRC_CTL, ~_BIT0, 0x00);
    ScalerSetBit(P5_A6_SDRF_IN1_PXL_NUM_H, ~_BIT5, 0x00);
    
    // Set line number
    ScalerSetBit(P5_B7_SDRF_IN1_LINE_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((usVerSize >> 8) & 0x0F));
    ScalerSetByte(P5_B8_SDRF_IN1_LINE_NUM_L, LOBYTE(usVerSize));

    // Calculate Line step and Block step
    stStep = ScalerSDRAMCalculateLineStepAndBlockStep(PDATA_DWORD(0), usVerSize);
    
    DebugMessageFRC("I-Block", stStep.ulBlockStep);
    DebugMessageFRC("I-line", stStep.usLineStep);
    
    // Calculate Number of length and Ramain 
    PDATA_DWORD(0) = ScalerSDRAMCalculateNumberAndRemain(PDATA_DWORD(0), _SDRAM_ACCESS_WRITE_LENGTH, 1);

    ScalerSetByte(P5_A8_SDRF_IN1_WATER_LEVEL, _SDRAM_ACCESS_WRITE_LENGTH);
    ScalerSetByte(P5_A9_SDRF_IN1_WR_NUM_H, pData[2]);
    ScalerSetByte(P5_AA_SDRF_IN1_WR_NUM_L, pData[3]);
    ScalerSetByte(P5_AB_SDRF_IN1_WR_LEN, _SDRAM_ACCESS_WRITE_LENGTH);
    ScalerSetByte(P5_AC_SDRF_IN1_WR_REMAIN, pData[1]);
    ScalerSetByte(P5_B0_SDRF_IN1_LINE_STEP_H, HIBYTE(stStep.usLineStep));
    ScalerSetByte(P5_B1_SDRF_IN1_LINE_STEP_L, LOBYTE(stStep.usLineStep));
    ScalerSetByte(P5_B2_SDRF_IN1_BLOCK_STEP_H, HIBYTE((WORD)(stStep.ulBlockStep >> 11)));
    ScalerSetByte(P5_B3_SDRF_IN1_BLOCK_STEP_L, LOBYTE((WORD)(stStep.ulBlockStep >> 11)));

    // Set Capture address index = 0
    ScalerSetBit(P5_BA_SDRF_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);

    // Caluclate 2nd write address
    g_ul3D_W_2ND_BLOCK_STA_ADDR = (_FRC_1ST_BLOCK_STA_ADDR + stStep.ulBlockStep);

    DebugMessageFRC("I-1st-addr", _FRC_1ST_BLOCK_STA_ADDR);    
    DebugMessageFRC("I-2nd-addr", g_ul3D_W_2ND_BLOCK_STA_ADDR);

    // Consider display initial address
    if(((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE)) && (GET_MEMORY_DVF_SELECT() != _1_IVF))
    {
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, (BYTE)(g_ul3D_W_2ND_BLOCK_STA_ADDR >> 16));
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, (BYTE)(g_ul3D_W_2ND_BLOCK_STA_ADDR >> 8));
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, (BYTE)(g_ul3D_W_2ND_BLOCK_STA_ADDR)); 
    }
    else
    {
        ScalerSetByte(P5_AD_SDRF_IN1_MEM_ADDR_H, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 16));
        ScalerSetByte(P5_AE_SDRF_IN1_MEM_ADDR_M, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR >> 8));
        ScalerSetByte(P5_AF_SDRF_IN1_MEM_ADDR_L, (BYTE)(_FRC_1ST_BLOCK_STA_ADDR));    
    }

    // Set 2nd write address
    ScalerSetByte(P5_B4_SDRF_IN1_BL2_ADDR_H, (BYTE)(g_ul3D_W_2ND_BLOCK_STA_ADDR >> 16));
    ScalerSetByte(P5_B5_SDRF_IN1_BL2_ADDR_M, (BYTE)(g_ul3D_W_2ND_BLOCK_STA_ADDR >> 8));
    ScalerSetByte(P5_B6_SDRF_IN1_BL2_ADDR_L, (BYTE)(g_ul3D_W_2ND_BLOCK_STA_ADDR));

    // Set Pixel unmber = Input line pixel
    ScalerSetBit(P5_A6_SDRF_IN1_PXL_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((HIBYTE(usHorSize)) & 0x0F));
    ScalerSetByte(P5_A7_SDRF_IN1_PXL_NUM_L, LOBYTE(usHorSize));

    // Set Single Buffer
    ScalerSetBit(P5_B9_SDRF_IN1_SDR_CTRL, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);    

    // Set M:N auto block toggle
    if(((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) || (GET_3D_INPUT_FORMAT() == _FRAME_PACKING)) && (GET_MEMORY_DVF_SELECT() == _2_5_IVF))
    {
        Scaler3DSetInputAutoBlkToggleShutterType();
    }    	

    // Disable Freeze mode
    ScalerSetBit(P5_B9_SDRF_IN1_SDR_CTRL, ~(_BIT2), 0x00);    
    
    // Use IVS as synchronous reset
    ScalerSetBit(P5_B9_SDRF_IN1_SDR_CTRL, ~(_BIT1), _BIT1);    

    // Enable Capture block
    ScalerSetBit(P5_B9_SDRF_IN1_SDR_CTRL, ~(_BIT7), _BIT7);

    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && 
       (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D) &&
       (GET_MEMORY_DVF_SELECT() != _1_IVF)) 
    {
        // Enable Half line process
        ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
        ScalerSetBit(P5_A5_SDRF_IN1_3D_FRC_CTL, ~_BIT0, _BIT0);
    } 
}

//--------------------------------------------------
// Description  : FIFO Display Setting for 3D Mode
// Input Value  : usHorSize --> Horizontal size
//                usVerSize --> Vertical Size
// Output Value : None
//--------------------------------------------------
void Scaler3DDisplayCtrlShutterType(WORD usHorSize, WORD usVerSize)
{
    StructSDRAMLineBlockStep stStep;

    // Set line number    
    ScalerSetBit(P5_CD_SDRF_MN_LINE_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0),  HIBYTE(usVerSize) & 0x0F);
    ScalerSetByte(P5_CE_SDRF_MN_LINE_NUM_L, LOBYTE(usVerSize));

    DebugMessageFRC("O_H", usHorSize);
    DebugMessageFRC("O_V", usVerSize);

    // Line mode
    // One line total pixel for SDRAM (unit : 64 bits)
    PDATA_DWORD(0) = ((DWORD)usHorSize * _BIT_PER_PIXEL % 64) ?
                     (((DWORD)usHorSize * _BIT_PER_PIXEL / 64) + 1) :
                     ((DWORD)usHorSize * _BIT_PER_PIXEL / 64);
                     
    // Set Line mode
    ScalerSetBit(P5_CD_SDRF_MN_LINE_NUM_H, ~_BIT4, 0x00);

    // Calculate Line step and Block step
    stStep = ScalerSDRAMCalculateLineStepAndBlockStep(PDATA_DWORD(0), usVerSize);
    
    // Calculation Number of length and Ramain
    PDATA_DWORD(0) = ScalerSDRAMCalculateNumberAndRemain(PDATA_DWORD(0), _SDRAM_ACCESS_READ_LENGTH, 0);

    // Set Number, Remain and Length
    ScalerSetByte(P5_C2_SDRF_MN_READ_NUM_H, pData[2]);
    ScalerSetByte(P5_C3_SDRF_MN_READ_NUM_L, pData[3]);
    ScalerSetByte(P5_C4_SDRF_MN_READ_LEN, _SDRAM_ACCESS_READ_LENGTH);
    ScalerSetByte(P5_C5_SDRF_MN_READ_REMAIN, pData[1]);

    // Set Pixel number of one line
    ScalerSetBit(P5_BE_SDRF_MN_PXL_NUM_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(usHorSize) & 0x0F));
    ScalerSetByte(P5_BF_SDRF_MN_PXL_NUM_L, LOBYTE(usHorSize));

    // Set Display address index = 0
    ScalerSetBit(P5_C1_SDRF_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);

    // Consider display initial address
    if(((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE)) &&
       (GET_MEMORY_DVF_SELECT() != _1_IVF) &&
       (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
    {
        //line step = 2 line, block step = l line.          
        stStep.ulBlockStep = stStep.usLineStep;

        pData[0] = (stStep.usLineStep & 0xFF); // Backup Column[7:0]
        stStep.usLineStep = ((((stStep.usLineStep >> 1) & 0xFF00) | pData[0]) << 1); // Colume[8] is useless
        pData[0] = (stStep.usLineStep & 0xFF); // Backup Column[7:0]
        stStep.usLineStep = (((stStep.usLineStep & 0xFF00) << 1)  | pData[0]); // Recovery Colume[8] 
    }

    DebugMessageFRC("O-1st-addr", _FRC_1ST_BLOCK_STA_ADDR);
    DebugMessageFRC("O-2nd-addr", (((g_ul3D_W_2ND_BLOCK_STA_ADDR & 0xFFFFFE00) >> 1) | (g_ul3D_W_2ND_BLOCK_STA_ADDR & 0xFF)));

    // Set Display initial address
    ScalerSetByte(P5_C6_SDRF_MN_READ_ADDR_H, ((_FRC_1ST_BLOCK_STA_ADDR >> 17) & 0xFF));
    ScalerSetByte(P5_C7_SDRF_MN_READ_ADDR_M, ((_FRC_1ST_BLOCK_STA_ADDR >> 9) & 0xFF));
    ScalerSetByte(P5_C8_SDRF_MN_READ_ADDR_L, (_FRC_1ST_BLOCK_STA_ADDR & 0xFF));

    pData[0] = (stStep.ulBlockStep & 0xFF);
    stStep.ulBlockStep = (((stStep.ulBlockStep >> 1) & 0xFFFFFF00) | pData[0]);

    DebugMessageFRC("O-Block", stStep.ulBlockStep);
    DebugMessageFRC("O-line", stStep.usLineStep);

    // Set Block step
    ScalerSetBit(P5_CB_SDRF_MN_BLOCK_STEP_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((BYTE)(stStep.ulBlockStep >> 18) & 0x0F));  // Block step[22:19]
    ScalerSetByte(P5_CC_SDRF_MN_BLOCK_STEP_L, ((BYTE)((stStep.ulBlockStep) >> 10)));    // Block step[18:11]
    ScalerSetBit(P5_EB_SDRF_MN_BLOCK_STEP_BANK, ~(_BIT2 | _BIT1 | _BIT0), ((BYTE)((stStep.ulBlockStep >> 8) & 0x03) << 1)); // Block step[10:8]
    ScalerSetByte(P5_EC_SDRF_MN_BLOCK_STEP_COL, (BYTE)stStep.ulBlockStep);  // Block step[7:0]    	

    // Set Pre-read line
    ScalerSetByte(P5_BC_SDRF_MN_PRERD_VST_H, HIBYTE(g_stMDomainOutputData.usVStart - _PREREAD_MARGIN));
    ScalerSetByte(P5_BD_SDRF_MN_PRERD_VST_L, LOBYTE(g_stMDomainOutputData.usVStart - _PREREAD_MARGIN));

    // Set Water level
    ScalerSetByte(P5_C0_SDRF_MN_WTLVL, _SDRAM_ACCESS_READ_LENGTH);

    //Set Line step
    ScalerSetBit(P5_C9_SDRF_MN_LINE_STEP_H, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(stStep.usLineStep) & 0x3F));
    ScalerSetByte(P5_CA_SDRF_MN_LINE_STEP_L, LOBYTE(stStep.usLineStep));

    // Set M:N auto block toggle
    if(((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) || (GET_3D_INPUT_FORMAT() == _FRAME_PACKING)) && (GET_MEMORY_DVF_SELECT() == _2_5_IVF))
    {
        Scaler3DSetDisplayAutoBlkToggleShutterType();
        Scaler3DSetHWAutoBlockToggleShutterType();
    }    	

    // Set input format 24 / 18 / 16 bit
#if(_BIT_PER_PIXEL == 24)   
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT0, 0x00);
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT7, 0x00);
#elif(_BIT_PER_PIXEL == 18)
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT0, _BIT0);
#elif(_BIT_PER_PIXEL == 16)
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT0, 0x00);
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT7, _BIT7);
#endif

    if((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && 
       (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) &&
       (GET_INTERLACED_MODE() == _TRUE))
    {
        // Input (Ro + Re), Single buffer  
        // Display (Ro or Re), Double buffer
        
        // Set input faster
        ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT3, _BIT3);
        
        // Set Double buffer
        ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT6 | _BIT5 | _BIT4), _BIT6);
    }
    else
    {
        // Set input slower
        ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT3, 0x00);
        
        // Set Single buffer
        ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
    }
    
    // Use information from Capture
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~(_BIT2 | _BIT1), 0x00);
    
    // Enable Display
    ScalerSetBit(P5_CF_SDRF_MN_DISP_CTRL, ~_BIT0, _BIT0);

    // Enable Display double buffer
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT4, _BIT4);

    // Wait double buffer
    ScalerTimerPollingFlagProc(_SDRAM_DISPLAY_SETTING_READY_TIME, P5_D0_SDRF_MN_SDR_STATUS, _BIT4, 0);

/*
    DebugMessageFRC("1_BS-H", (((_FRC_1ST_BLOCK_STA_ADDR >> 17) & 0xFF) + ((ScalerGetBit_EXINT0(P5_CB_SDRF_MN_BLOCK_STEP_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0) & 0x0F) << 2) | ((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0xC0) >> 6))));
    DebugMessageFRC("1_BS-M", (((_FRC_1ST_BLOCK_STA_ADDR >> 9) & 0xFF) + (((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0x3F) << 2) | (ScalerGetBit_EXINT0(P5_EB_SDRF_MN_BLOCK_STEP_BANK, (_BIT2 | _BIT1) & 0x06) >>1))));
    DebugMessageFRC("1_BS-L", ((_FRC_1ST_BLOCK_STA_ADDR & 0xFF) + (ScalerGetByte_EXINT0(P5_EC_SDRF_MN_BLOCK_STEP_COL))));

    DebugMessageFRC("2_BS-H", (((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 17) & 0xFF) + ((ScalerGetBit_EXINT0(P5_CB_SDRF_MN_BLOCK_STEP_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0) & 0x0F) << 2) | ((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0xC0) >> 6))));
    DebugMessageFRC("2_BS-M", (((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 9) & 0xFF) + (((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0x3F) << 2) | (ScalerGetBit_EXINT0(P5_EB_SDRF_MN_BLOCK_STEP_BANK, (_BIT2 | _BIT1) & 0x06) >>1))));
    DebugMessageFRC("2_BS-L", ((g_ul3D_W_2ND_BLOCK_STA_ADDR & 0xFF) + (ScalerGetByte_EXINT0(P5_EC_SDRF_MN_BLOCK_STEP_COL))));
 */  
}

//--------------------------------------------------
// Description  : Set display L/R flag
// Input Value  : ucEn : Enable/Disable
// Output Value : None
//--------------------------------------------------
void Scaler3DSetDisplayLRFlagEnable(BYTE ucEn)
{
    if(ucEn == _TRUE)
    {
        // Set M-domain L/R flag
        if(GET_MEMORY_SELECT() == _MN_FRAME_SYNC_SDRAM)
        {
            DebugMessageFRC("-T-Con_LR signal-On1", 0);
            
            // Set L/R flag 
#if(_3D_SHUTTER_OUTPUT_LR_FLAG == _L_FRAME_LOW)
            // Set L frame: Low / R frame: High
            ScalerSetBit(P5_ED_SDRF_MN_3D_FRC_CTL, ~_BIT4, 0x00);
#else
            // Set L frame: High / R frame: Low
            ScalerSetBit(P5_ED_SDRF_MN_3D_FRC_CTL, ~_BIT4, _BIT4);
#endif

            // M-domain rebuild - single buffer
            ScalerSetBit(P5_ED_SDRF_MN_3D_FRC_CTL, ~(_BIT3 | _BIT2), _BIT2);
        }
        else
        {
            // Set L/R flag 
            // If IVStart <= IVS2DVSDelay (L frame: High / R frame: Low), L/R flag swap enable 
            // else L/R flag swap disable
            pData[0] = (g_stMDomainInputData.usVStart <= (((ScalerGetBit(CM_3E_IVS2DVS_DEALY_LINES_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) & 0x0F) << 8) | (ScalerGetByte(CM_40_IVS2DVS_DEALY_LINES)))) ? (1) : (0);
            
            DebugMessageFRC("-T-Con_LR signal-On2", pData[0]);            
            
#if(_3D_SHUTTER_OUTPUT_LR_FLAG == _L_FRAME_LOW)
            // Set L frame: Low / R frame: High
            ScalerSetBit(P5_ED_SDRF_MN_3D_FRC_CTL, ~_BIT4, (pData[0] << 4));
#else
            // Set L frame: High / R frame: Low
            ScalerSetBit(P5_ED_SDRF_MN_3D_FRC_CTL, ~_BIT4, ~(pData[0] << 4));
#endif

            // M-domain rebuild - dvs sample
            ScalerSetBit(P5_ED_SDRF_MN_3D_FRC_CTL, ~(_BIT3 | _BIT2), 0x00);
        } 

        // L/R flag enable (DVS falling edge effect)
        ScalerSetBit(P5_ED_SDRF_MN_3D_FRC_CTL, ~_BIT5, _BIT5);
    }
    else
    {
        // Set L/R flag swap disable
        ScalerSetBit(P5_ED_SDRF_MN_3D_FRC_CTL, ~_BIT4, 0x00);            
        
        // L/R flag disable (DVS rising edge effect)
        ScalerSetBit(P5_ED_SDRF_MN_3D_FRC_CTL, ~_BIT5, 0x00);

        DebugMessageFRC("-T-Con_LR signal-OFF", 0);
    }
    
    // Enable Display double buffer (for L/R flag swap)
    ScalerSetBit(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT4, _BIT4);
}

//--------------------------------------------------
// Description  : 3D shutter Interrupt Process (EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void Scaler3DIntHandler_EXINT0(void) using 1
{
    //===========================================
    //              IVS Event
    //===========================================
    if(ScalerGetBit_EXINT0(CM_08_NEW_ADDED_STATUS1, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6))
    {
        // Clear IVS IRQ flag
        ScalerSetBit_EXINT0(CM_08_NEW_ADDED_STATUS1, ~_BIT6, _BIT6);

        if((((ScalerGetByte_EXINT0(P5_AD_SDRF_IN1_MEM_ADDR_H) << 16) & 0xFF0000) | 
           ((ScalerGetByte_EXINT0(P5_AE_SDRF_IN1_MEM_ADDR_M) << 8) & 0xFF00) |
           (ScalerGetByte_EXINT0(P5_AF_SDRF_IN1_MEM_ADDR_L) & 0xFF)) == (_FRC_1ST_BLOCK_STA_ADDR))
        {
            // Set Address = 2nd address
            ScalerSetByte_EXINT0(P5_AD_SDRF_IN1_MEM_ADDR_H, ((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 16) & 0xFF));
            ScalerSetByte_EXINT0(P5_AE_SDRF_IN1_MEM_ADDR_M, ((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 8) & 0xFF));
            ScalerSetByte_EXINT0(P5_AF_SDRF_IN1_MEM_ADDR_L, (g_ul3D_W_2ND_BLOCK_STA_ADDR & 0xFF));
        }
        else
        {
            // Set Address = 1st address
            ScalerSetByte_EXINT0(P5_AD_SDRF_IN1_MEM_ADDR_H, ((_FRC_1ST_BLOCK_STA_ADDR >> 16) & 0xFF));
            ScalerSetByte_EXINT0(P5_AE_SDRF_IN1_MEM_ADDR_M, ((_FRC_1ST_BLOCK_STA_ADDR >> 8) & 0xFF));
            ScalerSetByte_EXINT0(P5_AF_SDRF_IN1_MEM_ADDR_L, (_FRC_1ST_BLOCK_STA_ADDR & 0xFF));
        }
        
   } // End of if(ScalerGetBit_EXINT0(CM_08_NEW_ADDED_STATUS1, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6))   
    
    //===========================================
    //              DVS Event
    //===========================================
    if(ScalerGetBit_EXINT0(CM_08_NEW_ADDED_STATUS1, (_BIT5 | _BIT4)) == (_BIT5 | _BIT4))
    {
        // Clear DVS IRQ flag
        ScalerSetBit_EXINT0(CM_08_NEW_ADDED_STATUS1, ~_BIT4, _BIT4);

        // DVS counter + 1
        g_uc3DDVSCount += 1;

        //===========================================
        //  Frame Packing & Top and Botton
        //===========================================
        if(((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && (GET_MEMORY_DVF_SELECT() == _2_5_IVF))
        {
            if(g_b3DIRQShiftStatus == _TRUE)
            {
                if(g_uc3DDVSCount == 6)
                {
                    // set Multiple of hardware = 4
                    ScalerSetBit_EXINT0(P5_BE_SDRF_MN_PXL_NUM_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (3 << 4));

                    // Enable Display double buffer
                    ScalerSetBit_EXINT0(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT4, _BIT4);
                }
                else if(g_uc3DDVSCount == 10)
                {
                    // set Multiple of hardware = 2
                    ScalerSetBit_EXINT0(P5_BE_SDRF_MN_PXL_NUM_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (1 << 4));

                    // Enable Display double buffer
                    ScalerSetBit_EXINT0(P5_D0_SDRF_MN_SDR_STATUS, ~_BIT4, _BIT4);

                    // Reset DVS counter
                    g_uc3DDVSCount = 0;   
                }
                
            }
            else // Else of if(g_b3DIRQShiftStatus == _TRUE)
            {
                if(g_uc3DDVSCount == 4)
                {
                    // Reset DVS counter
                    g_uc3DDVSCount = 0;

                    // Start regularly recurrent frame
                    g_b3DIRQShiftStatus = _TRUE;
                }
                
            } // End of if(g_b3DIRQShiftStatus == _TRUE)
            
        }
        //===========================================
        //    Side by Side  & Line interlace
        //===========================================
        else if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE))
        {
            if((GET_MEMORY_DVF_SELECT() == _2_5_IVF) || (GET_MEMORY_DVF_SELECT() == _2_IVF))
            {
                if(GET_MEMORY_DVF_SELECT() == _2_5_IVF)
                {
                    if(g_uc3DDVSCount == 8)
                    {
                        // Set 2nd Address
                        ScalerSetByte_EXINT0(P5_C6_SDRF_MN_READ_ADDR_H, ((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 17) & 0xFF));
                        ScalerSetByte_EXINT0(P5_C7_SDRF_MN_READ_ADDR_M, ((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 9) & 0xFF));
                        ScalerSetByte_EXINT0(P5_C8_SDRF_MN_READ_ADDR_L, (g_ul3D_W_2ND_BLOCK_STA_ADDR & 0xFF));

                        // Enable Display double buffer
                        ScalerSetBit_EXINT0(P5_D0_SDRF_MN_SDR_STATUS, _BIT4, _BIT4);
                        
                        return;
                    }
                    else if((g_uc3DDVSCount == 9) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
                    {
                        // Set 2nd Address + Block Step
                        ScalerSetByte_EXINT0(P5_C6_SDRF_MN_READ_ADDR_H, (((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 17) & 0xFF) + ((ScalerGetBit_EXINT0(P5_CB_SDRF_MN_BLOCK_STEP_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0) & 0x0F) << 2) | ((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0xC0) >> 6))));
                        ScalerSetByte_EXINT0(P5_C7_SDRF_MN_READ_ADDR_M, (((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 9) & 0xFF) + (((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0x3F) << 2) | (ScalerGetBit_EXINT0(P5_EB_SDRF_MN_BLOCK_STEP_BANK, (_BIT2 | _BIT1) & 0x06) >>1))));
                        ScalerSetByte_EXINT0(P5_C8_SDRF_MN_READ_ADDR_L, ((g_ul3D_W_2ND_BLOCK_STA_ADDR & 0xFF) + (ScalerGetByte_EXINT0(P5_EC_SDRF_MN_BLOCK_STEP_COL))));

                        // Enable Display double buffer
                        ScalerSetBit_EXINT0(P5_D0_SDRF_MN_SDR_STATUS, _BIT4, _BIT4);
                        
                        return;
                    }
                    else if(g_uc3DDVSCount == 10)
                    {
                        g_uc3DDVSCount = 0;
                    }
                }

                if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
                {
                    switch(g_uc3DDVSCount % 4)
                    {
                        case 0:
                            
                            if(GET_MEMORY_DVF_SELECT() == _2_IVF)
                            {
                                g_uc3DDVSCount = 0;
                            }

                            // Set 1st Address
                            ScalerSetByte_EXINT0(P5_C6_SDRF_MN_READ_ADDR_H, ((_FRC_1ST_BLOCK_STA_ADDR >> 17) & 0xFF));
                            ScalerSetByte_EXINT0(P5_C7_SDRF_MN_READ_ADDR_M, ((_FRC_1ST_BLOCK_STA_ADDR >> 9) & 0xFF));
                            ScalerSetByte_EXINT0(P5_C8_SDRF_MN_READ_ADDR_L, (_FRC_1ST_BLOCK_STA_ADDR & 0xFF));
                            
                            break;
                        
                        case 1:
                            
                            // Set 1st Address + Block Step
                            ScalerSetByte_EXINT0(P5_C6_SDRF_MN_READ_ADDR_H, (((_FRC_1ST_BLOCK_STA_ADDR >> 17) & 0xFF) + ((ScalerGetBit_EXINT0(P5_CB_SDRF_MN_BLOCK_STEP_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0) & 0x0F) << 2) | ((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0xC0) >> 6))));
                            ScalerSetByte_EXINT0(P5_C7_SDRF_MN_READ_ADDR_M, (((_FRC_1ST_BLOCK_STA_ADDR >> 9) & 0xFF) + (((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0x3F) << 2) | (ScalerGetBit_EXINT0(P5_EB_SDRF_MN_BLOCK_STEP_BANK, (_BIT2 | _BIT1) & 0x06) >>1))));
                            ScalerSetByte_EXINT0(P5_C8_SDRF_MN_READ_ADDR_L, ((_FRC_1ST_BLOCK_STA_ADDR & 0xFF) + (ScalerGetByte_EXINT0(P5_EC_SDRF_MN_BLOCK_STEP_COL))));

                            break;

                        case 2:
                            
                            // Set 2nd Address
                            ScalerSetByte_EXINT0(P5_C6_SDRF_MN_READ_ADDR_H, ((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 17) & 0xFF));
                            ScalerSetByte_EXINT0(P5_C7_SDRF_MN_READ_ADDR_M, ((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 9) & 0xFF));
                            ScalerSetByte_EXINT0(P5_C8_SDRF_MN_READ_ADDR_L, (g_ul3D_W_2ND_BLOCK_STA_ADDR & 0xFF));

                            break;
                            
                        case 3: 
                            
                            // Set 2nd Address + Block Step
                            ScalerSetByte_EXINT0(P5_C6_SDRF_MN_READ_ADDR_H, (((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 17) & 0xFF) + ((ScalerGetBit_EXINT0(P5_CB_SDRF_MN_BLOCK_STEP_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0) & 0x0F) << 2) | ((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0xC0) >> 6))));
                            ScalerSetByte_EXINT0(P5_C7_SDRF_MN_READ_ADDR_M, (((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 9) & 0xFF) + (((ScalerGetByte_EXINT0(P5_CC_SDRF_MN_BLOCK_STEP_L) & 0x3F) << 2) | (ScalerGetBit_EXINT0(P5_EB_SDRF_MN_BLOCK_STEP_BANK, (_BIT2 | _BIT1) & 0x06) >>1))));
                            ScalerSetByte_EXINT0(P5_C8_SDRF_MN_READ_ADDR_L, ((g_ul3D_W_2ND_BLOCK_STA_ADDR & 0xFF) + (ScalerGetByte_EXINT0(P5_EC_SDRF_MN_BLOCK_STEP_COL))));

                            break;

                        default:
                            
                            break;
                            
                    } // End of switch(g_uc3DDVSCount % 4)
                }
                else  // Else of if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
                {
                    switch(g_uc3DDVSCount % 4)
                    {
                        case 0:
                        case 1:
                            
                            if(GET_MEMORY_DVF_SELECT() == _2_IVF)
                            {
                                g_uc3DDVSCount = 0;
                            }

                            // Set 1st Address
                            ScalerSetByte_EXINT0(P5_C6_SDRF_MN_READ_ADDR_H, ((_FRC_1ST_BLOCK_STA_ADDR >> 17) & 0xFF));
                            ScalerSetByte_EXINT0(P5_C7_SDRF_MN_READ_ADDR_M, ((_FRC_1ST_BLOCK_STA_ADDR >> 9) & 0xFF));
                            ScalerSetByte_EXINT0(P5_C8_SDRF_MN_READ_ADDR_L, (_FRC_1ST_BLOCK_STA_ADDR & 0xFF));
                            
                            break;
                        
                        case 2:
                        case 3:
                            
                            // Set 2nd Address
                            ScalerSetByte_EXINT0(P5_C6_SDRF_MN_READ_ADDR_H, ((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 17) & 0xFF));
                            ScalerSetByte_EXINT0(P5_C7_SDRF_MN_READ_ADDR_M, ((g_ul3D_W_2ND_BLOCK_STA_ADDR >> 9) & 0xFF));
                            ScalerSetByte_EXINT0(P5_C8_SDRF_MN_READ_ADDR_L, (g_ul3D_W_2ND_BLOCK_STA_ADDR & 0xFF));

                            break;
                            
                        default:
                            
                            break;
                            
                    } // End of switch(g_uc3DDVSCount % 4)
                    
                }// End of if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)

            }
             
            // Enable Display double buffer
            ScalerSetBit_EXINT0(P5_D0_SDRF_MN_SDR_STATUS, _BIT4, _BIT4);
                
        } // End of if((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM))
        
    } // End of if(ScalerGetBit_EXINT0(CM_08_NEW_ADDED_STATUS1, (_BIT5 | _BIT4)) == (_BIT5 | _BIT4))
}

#endif // End of #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
#endif // End of #if(_3D_SUPPORT == _ON)

