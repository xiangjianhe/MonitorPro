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
// ID Code      : RL6229_Series_Scaling.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6229_SERIES_SCALING__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_3D_SUPPORT == _ON)
#define _QUINCNUX_ALIGN_LR_SEL                  _LEFT 
#define _SBS_MASK_LR_SEL_BY_CAPTURE             _LEFT 
#endif

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

BYTE g_ucVFCI = 0x00;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

void ScalerScalingSetScalingDown(StructSDRAMDataInfo stFIFOScaling);
void ScalerScalingSetScalingUp(StructSDRAMDataInfo stFIFOScaling);

#if(_3D_SUPPORT == _ON)

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
void ScalerScalingVSD2DiffPhase(DWORD ulVSDFactor);
#endif

EnumVSUCoefType ScalerScalingGetScalingUpType(void);
void ScalerScalingHSDSbS2DiffPhase(DWORD ulHSDFactor);
void ScalerScalingSetQuincnuxType(BYTE ucQuincunxType);
void ScalerScalingSet2DQuincnuxType(BYTE ucQuincunxType, BYTE ucInitialPhase1, BYTE ucInitialPhase2);
#endif

#if(_2D_TO_3D_FUNCTION == _ON)
void ScalerScalingNonLinearScalingUpInitial(void);
void ScalerScalingNonLinearScalingUpSetting(WORD usFIFOHWidth);
#endif

void ScalerScalingGetFIFOScalingSize(StructSDRAMDataInfo* pstData);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Decide which scaling down function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingSetScalingDown(StructSDRAMDataInfo stFIFOScaling)
{
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    CLR_H_SCALE_DOWN_2_DIFF_PHASE();
    CLR_V_SCALE_DOWN_2_DIFF_PHASE();
#endif
    
    // Disable Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT7 | _BIT3 |_BIT2 | _BIT1 | _BIT0), 0x00);

    // Disable share line buffer to I domain
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, 0x00);

    // Disable Hor use L/R different initial 
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, ~_BIT6, 0x00);  

    // Disable 3D Scale down, disable Ver use L/R different initial 
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, ~(_BIT7 | _BIT6), 0x00); 

    // Disable Horizontal quincunx interpolation
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~_BIT0, 0x00); 

    //=================================================
    // Decide H and V direction scaling down and factor
    //=================================================    

    //--------------------------------------------------
    // Get HSD Factor and Initial Phase
    //--------------------------------------------------
    
    // Calculate H Scaling Factor
    if(g_stMDomainInputData.usHWidth > stFIFOScaling.usInputHWidth)
    {
        SET_H_SCALE_DOWN();
        
         // Calculate Scaling Factor        
        PDATA_DWORD(0) = (DWORD)g_stMDomainInputData.usHWidth << 20;
        
        PDATA_DWORD(0) = (PDATA_DWORD(0) / stFIFOScaling.usInputHWidth) + ((PDATA_DWORD(0) % stFIFOScaling.usInputHWidth) ? 1 : 0);    
    }
    else
    {
        ((DWORD *)pData)[0] = 0x100000;
    }        

    // Calculate Initial Phase
    pData[15] = (PDATA_DWORD(0) >> 15) - 32; // (factor - 1) / 2

    if(pData[15] > 0x3F)
    {
        pData[15] = 0x3F;
    }
    
    // set phase
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, pData[15]);  
    
    // set H Scaling factor
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, (pData[1] & 0x7F));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, pData[2]);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, pData[3]);

    //--------------------------------------------------
    // Get VSD Factor and Initial Phase
    //--------------------------------------------------

    // Calculate V Scaling Factor
    if(g_stMDomainInputData.usVHeight > stFIFOScaling.usInputVHeight)
    {
        SET_V_SCALE_DOWN();
        
        // Calculate Scaling Factor    
        PDATA_DWORD(1) = ((((DWORD)g_stMDomainInputData.usVHeight << 18) / stFIFOScaling.usInputVHeight) + 1) >> 1;

    }
    else
    {
        PDATA_DWORD(1) = 0x20000;
    }    

    // Calculate Initial Phase
    pData[15] = (PDATA_DWORD(1) >> 12) - 32; // (factor - 1) / 2

    if(pData[15] > 0x3F)
    {
        pData[15] = 0x3F;
    }

    // Modify initial phase for VSD phase 0 issue
    // MSB 6bit of decimal part is zero for factor,phase can't be zero
    if((PDATA_DWORD(1) > 0x20000) && (PDATA_DWORD(1) <= 0x207FF))
    {
        if(pData[15] == 0)
        {
            pData[15] = 1;
        }      
    }
    
    // Set Initial Phase
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[15]);        

    // Set V Scaling factor
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, (pData[5] & 0x07));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, pData[6]);
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, pData[7]);

#if(_3D_SUPPORT == _ON)
    if(GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT)
    {        
        switch(GET_3D_INPUT_FORMAT())
        {
            // Hor_2D same as 2D
            // Hor_3D same as 2D            
            // Ver_2D same as 2D
            // Ver_3D different with 2D                 
            case _TOP_AND_BOTTOM:
            case _FRAME_PACKING:
            case _FRAME_SEQUENTIAL:

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
                if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
                {     
                    // 2 VSD initial phase, need set VSD 
                    SET_V_SCALE_DOWN_2_DIFF_PHASE();
                    
                    ScalerScalingVSD2DiffPhase(PDATA_DWORD(1));
                }
#endif

                break;

            // Hor_2D different with 2D
            // Hor_3D different with 2D            
            // Ver_2D same as 2D
            // Ver_3D different with 2D  
            case _SIDE_BY_SIDE_HALF:
                
                //===============================
                // SBS Reset
                //===============================    
                
                ScalerScalingHSDSbS2DiffPhase(PDATA_DWORD(0));

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
                if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
                {
                    // 2 VSD initial phase, need set VSD 
                    SET_V_SCALE_DOWN_2_DIFF_PHASE();
                    
                    ScalerScalingVSD2DiffPhase(PDATA_DWORD(1));
                }
#endif

                break;

            // Hor_2D same as 2D
            // Hor_3D same as 2D            
            // Ver_2D same as 2D
            // Ver_3D same as 2D            
            case _LINE_INTERLACE:
                
                break;

            default:
                break;
        }        
    }
#endif // End of #if(_3D_SUPPORT == _ON)

    // Set Input Capture to Scale Down Block
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_32_SD_IN_WID_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(g_stMDomainInputData.usHWidth));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_33_SD_IN_WID_L, LOBYTE(g_stMDomainInputData.usHWidth));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_34_SD_IN_LEN_M, HIBYTE(g_stMDomainInputData.usVHeight));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_35_SD_IN_LEN_L, LOBYTE(g_stMDomainInputData.usVHeight));

    // Set Output Capture of Scale Down Block
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_36_SD_OUT_WID_M, HIBYTE(stFIFOScaling.usInputHWidth));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_37_SD_OUT_WID_L, LOBYTE(stFIFOScaling.usInputHWidth));    
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_38_SD_OUT_LEN_M, HIBYTE(stFIFOScaling.usInputVHeight));
    ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_39_SD_OUT_LEN_L, LOBYTE(stFIFOScaling.usInputVHeight)); 

    
    //===============================
    // Set H direction scaling down
    //===============================
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))    
    if((GET_H_SCALE_DOWN() == _TRUE) || (GET_H_SCALE_DOWN_2_DIFF_PHASE() == _TRUE))
#else
    if(GET_H_SCALE_DOWN() == _TRUE)
#endif
    {              
        // Enable H Scale Down
        ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT1), _BIT1);
    }

    //===============================
    // Set V direction scaling down
    //===============================
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))  
    if((GET_V_SCALE_DOWN() == _TRUE) || (GET_V_SCALE_DOWN_2_DIFF_PHASE() == _TRUE))   
#else
    if(GET_V_SCALE_DOWN() == _TRUE)
#endif
    {        
        // Enable I domain share display line buffer & MAC when vertical scale down
        ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, _BIT5);

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))

#if(_2D_TO_3D_FUNCTION == _ON)
        if((GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT) || (GET_2DTO3D_ENABLE() == _ENABLE))
#else
        if(GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT)
#endif
        {
            // Enable VSD 3D Scale down
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, ~_BIT7, _BIT7);

#if(_2D_TO_3D_FUNCTION == _ON)
            if((GET_2DTO3D_ENABLE() == _ENABLE) || (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) || ((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))
#else
            if((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) || ((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))
#endif
            {  
                // Share 2 line buffer for VSD
                ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT7, _BIT7); 
            }            
        }
#endif // End if #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))

        // Enable V Scale Down
        ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);      
    }
}

//--------------------------------------------------
// Description  : Decide which scaling function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingSetScalingUp(StructSDRAMDataInfo stFIFOScaling)
{
    // Disable Scale Up
    ScalerSetBit(CM_32_SCALE_CTRL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Disable 3 line buffer for 2D SU
    ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~_BIT6, 0x00);

    // Disable VSU for line interleave/ VSU for line interleave/ Disable line switch when line interleave
    ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), 0x00);    

#if(_2D_TO_3D_FUNCTION == _ON)

    ScalerScalingNonLinearScalingUpInitial();

#endif
    
    //===============================
    // Decide V direction scaling up
    //===============================
    // Set V Scaling Up Factor    
    if(stFIFOScaling.usOutputVHeight < g_stMDomainOutputData.usVHeight)
    {
        SET_V_SCALE_UP();    
        
        PDATA_DWORD(0) = (DWORD)stFIFOScaling.usOutputVHeight << 20;
        PDATA_DWORD(0) = (PDATA_DWORD(0) / g_stMDomainOutputData.usVHeight) + (PDATA_DWORD(0) % 2);

        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_03_SU_VER_SCA_H, (pData[1] & 0x0F));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_04_SU_VER_SCA_M, pData[2]);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_05_SU_VER_SCA_L, pData[3]);

#if(_3D_SUPPORT == _ON)

        switch(ScalerScalingGetScalingUpType())
        {  
            case _VSU_2D_4LINE_COEF:

                if((GET_INTERLACED_MODE() == _FALSE) || (ScalerGetBit(CM_10_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) || (GET_INPUT_TIMING_HWIDTH() == _PANEL_DH_WIDTH))
                {
                    g_ucVFCI = 0xC4; 
                }
                else
                {
                    g_ucVFCI = 0xFF; 
                }
                
                break;

            case _VSU_2D_3LINE_COEF:

                g_ucVFCI = 0xC4 - 0x80; 

                ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~(_BIT6), _BIT6);

                break;

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

            case _VSU_3D_3LINE_COEF:

                // Set V Initial Phase
                // R = Input Height /Output Height
                // ideal initial phase: for 3line SU = (1+R)*16*8- 0x80 
                g_ucVFCI = (DWORD)(stFIFOScaling.usOutputVHeight + g_stMDomainOutputData.usVHeight) * 16 * 8 / g_stMDomainOutputData.usVHeight - 0x80;

                // 3line SU for line interleave  // disable line switch
                ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);   
                
                break; 
                
            case _VSU_3D_2LINE_COEF:

                // Set V Initial Phase
                // R = Input Height /Output Height
                // ideal initial phase: for 4line SU = (1+R)*16*8 
                g_ucVFCI = (DWORD)(stFIFOScaling.usOutputVHeight + g_stMDomainOutputData.usVHeight) * 16 * 8 / g_stMDomainOutputData.usVHeight;
                
                // 2line VSU for line interleave  // disable line switch
                ScalerSetBit(CM_37_SU_LINE_INTERLEAVE, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));  
                
                break;

#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)

            case _VSU_3D_4LINE_COEF:

                // ideal initial phase: for 4line SU = (1+R)*16*8 
                g_ucVFCI = (DWORD)(stFIFOScaling.usOutputVHeight + g_stMDomainOutputData.usVHeight) * 16 * 8 / g_stMDomainOutputData.usVHeight;
                
                break;

            case _VSU_3D_3LINE_COEF:

                // Set V Initial Phase
                // R = Input Height /Output Height
                // ideal initial phase: for 3line SU = (1+R)*16*8- 0x80 
                g_ucVFCI = (DWORD)(stFIFOScaling.usOutputVHeight + g_stMDomainOutputData.usVHeight) * 16 * 8 / g_stMDomainOutputData.usVHeight - 0x80;
                 
                break;                 
#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)



            default:

                break;
        }            

#else // Else of #if(_3D_SUPPORT == _ON)

        if((GET_INTERLACED_MODE() == _FALSE) || (ScalerGetBit(CM_10_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) || (GET_INPUT_TIMING_HWIDTH() == _PANEL_DH_WIDTH))
        {
            g_ucVFCI = 0xC4; 
        }
        else
        {
            g_ucVFCI = 0xFF; 
        }
#endif // End of #if(_3D_SUPPORT == _ON)

        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, g_ucVFCI);
    }
    else
    {
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_03_SU_VER_SCA_H, 0x0F);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_04_SU_VER_SCA_M, 0xFF);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_05_SU_VER_SCA_L, 0xFF);
    }

    //===============================
    // Set V direction scaling up
    //===============================
    if(GET_V_SCALE_UP())
    {
        // Enable V Scale Up
        ScalerSetBit(CM_32_SCALE_CTRL, ~(_BIT2 | _BIT1), _BIT1);
    }    

    //===============================
    // Decide H direction scaling up
    //===============================
    SET_H_SCALE_UP();    
    
    // Set H Scaling Up Factor
    if(stFIFOScaling.usOutputHWidth < g_stMDomainOutputData.usHWidth)
    {        
        PDATA_DWORD(0) = (DWORD)stFIFOScaling.usOutputHWidth << 20;
        PDATA_DWORD(0) = (PDATA_DWORD(0) / g_stMDomainOutputData.usHWidth) + (PDATA_DWORD(0) % 2);

        ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (pData[1] & 0x0F));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_01_SU_HOR_SCA_M, pData[2]);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_02_SU_HOR_SCA_L, pData[3]);

        // Set H Initial Phase
        // R = Input width /Output width
        // ideal initial phase = (1+R)*16*8        
        PDATA_DWORD(0) = (DWORD)(stFIFOScaling.usOutputHWidth + g_stMDomainOutputData.usHWidth) * 16 * 8 / g_stMDomainOutputData.usHWidth;
        
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, pData[3]);

        // disable Horizontal by_line_scale_up
        ScalerSetBit(CM_35_FILTER_CTRL, ~_BIT3, 0x00);   
    }
    else
    {
        ScalerSetDataPortBit(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0) , 0x0F);        
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_01_SU_HOR_SCA_M, 0xFF);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_02_SU_HOR_SCA_L, 0xFF);         

        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xFF);
    }            

    //===============================
    // Set H direction scaling up
    //===============================
    if(GET_H_SCALE_UP())
    {    
        // Enable H Scale Up
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT0, _BIT0);
    }
    
#if(_2D_TO_3D_FUNCTION == _ON)
    // Set Non-Linear Horizontal Sscaling Up
    ScalerScalingNonLinearScalingUpSetting(stFIFOScaling.usOutputHWidth);
#endif
}

#if(_3D_SUPPORT == _ON)
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
//--------------------------------------------------
// Description  : V Scaling Down phase for vertical LR 3D type, ex: FP, TnB and FS
//                3D display need 2 Ver initial phase no matter SD or no SD
// Input Value  : VSD factor    
// Output Value : None
//--------------------------------------------------
void ScalerScalingVSD2DiffPhase(DWORD ulVSDFactor)
{  
    // pData[11] = Initial phase 1
    // pData[12] = Initial phase 2

    // (factor * 64) < (2 * 64) -> 0
    // ((factor / 2) - 1) / 2
    pData[11] = ((ulVSDFactor >> 11) < (2 << 6)) ? 0 : (ulVSDFactor >> 13) - 32;
    
    if(pData[11] > 0x3F)
    {
        pData[11] = 0x3F;
    }          

    // initial phase2 = initial phase1 + factor / 2        
    pData[12] = pData[11] + (ulVSDFactor >> 12);

    if(pData[12] > 0x3F)
    {
        pData[12] = 0x3F;
        
        pData[11] = ((ulVSDFactor >> 12) >= 0x3F) ? 0 : pData[12] - (ulVSDFactor >> 12);
    }

    switch(GET_3D_INPUT_FORMAT())
    {
        case _SIDE_BY_SIDE_HALF:
        case _FRAME_SEQUENTIAL:

            if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)
            {
                // Switch Data
                pData[15]= pData[12];
                pData[12] = pData[11];
                pData[11] = pData[15];
            } 
            
            break;

        case _FRAME_PACKING:
        case _TOP_AND_BOTTOM:
            
            if((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_INTERLACED_MODE() == _TRUE))
            {
                // 1080i / 576i / 480i
                if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR)
                {
                    // Switch Data
                    pData[15]= pData[12];
                    pData[12] = pData[11];
                    pData[11] = pData[15];
                }

                if(pData[12] >= 0x20)
                {
                    pData[12] = pData[12] - 0x20; 
                }                        
                else
                {
                    if(((0x20 - pData[12]) + pData[11]) > 0x3F)
                    {
                        pData[11] = 0x3F;
                    }
                    else
                    {
                        pData[11] = pData[11] + (0x20 - pData[12]);
                    }
                    pData[12] = 0;                     
                }
                                
                break;
            }

            if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_RL)
            {
                // Switch Data
                pData[15]= pData[12];
                pData[12] = pData[11];
                pData[11] = pData[15];
            } 
          
            break;

        default:

            break;
    }           

    // Modify initial phase for VSD phase 0 issue
    // MSB 6bit of decimal part is zero for factor,phase can't be zero
    if((ulVSDFactor > 0x20000) && (ulVSDFactor <= 0x207FF))
    {
        if(pData[11] == 0)
        {
            pData[11] = 1;

            if(pData[12] != 0x3F)
            {
                pData[12] = pData[12] + 1;
            }
        }

        if(pData[12] == 0)
        {
            pData[12] = 1;

            if(pData[11] != 0x3F)
            {
                pData[11] = pData[11] + 1;
            }           
        }        
    }
    
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, ~_BIT6, (pData[11] == pData[12]) ? 0 : _BIT6);        
    
    // Set Initial Phase
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[11]); 
    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_31_V_INITIAL_RIGHT, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[12]);                                          

    // Avoid IEN Overlapped with IVS
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
}
#endif  // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

//--------------------------------------------------
// Description  : Get 3D ScalingUp Type
// Input Value  : none
// Output Value : 0: no 3D ScaleUp,  1: 3D 3Line V ScaleUp,  2:3D 2Line V ScaleUp,
//--------------------------------------------------
EnumVSUCoefType ScalerScalingGetScalingUpType(void)
{   
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

#if(_2D_TO_3D_FUNCTION == _ON)

    if(((GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) || (GET_2DTO3D_ENABLE() == _ENABLE)) // 3D input, 3D display
    {
        return (((GET_V_SCALE_DOWN() == _TRUE) || (GET_V_SCALE_DOWN_2_DIFF_PHASE() == _TRUE)) ? _VSU_3D_2LINE_COEF : _VSU_3D_3LINE_COEF);
    }
    else // 2D display
    {
        return (((GET_V_SCALE_DOWN() == _TRUE) || (GET_V_SCALE_DOWN_2_DIFF_PHASE() == _TRUE)) ? _VSU_2D_3LINE_COEF : _VSU_2D_4LINE_COEF);
    }

#else

    if((GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) // 3D input, 3D display
    {
        return (((GET_V_SCALE_DOWN() == _TRUE) || (GET_V_SCALE_DOWN_2_DIFF_PHASE() == _TRUE)) ? _VSU_3D_2LINE_COEF : _VSU_3D_3LINE_COEF);
    }
    else // 2D display
    {
        return (((GET_V_SCALE_DOWN() == _TRUE) || (GET_V_SCALE_DOWN_2_DIFF_PHASE() == _TRUE)) ? _VSU_2D_3LINE_COEF : _VSU_2D_4LINE_COEF);
    }

#endif // End of #if(_2D_TO_3D_FUNCTION == _ON)

#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)

    if(GET_V_SCALE_DOWN() == _TRUE)  
    {
        return _VSU_2D_3LINE_COEF;
    }
    else
    {
        return _VSU_3D_4LINE_COEF;
    }
       
#endif // End of #if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)

    return _VSU_2D_4LINE_COEF;
}

//--------------------------------------------------
// Description  : H Scaling Down phase for SbS
//                Need 1 HSD initial phase:
//                3D:SbS_OL_OR, SbS_EL_ER    
//                2D:SbS_OL_OR, SbS_EL_ER, SbS_OL_ER, SbS_OL_ER,

//                Need 2 HSD initial phase:
//                3D:SbS_OL_ER, SbS_OL_ER,SbS_OL_OR_Quin, SbS_EL_ER_Quin, SbS_OL_ER_Quin, SbS_OL_ER_Quin,   
//                2D:SbS_OL_OR_Quin, SbS_EL_ER_Quin, SbS_OL_ER_Quin, SbS_OL_ER_Quin,

//                3D display need 2 Ver initial phase no matter SD or no SD
// Input Value  : HSD factor
// Output Value : None
//--------------------------------------------------
void ScalerScalingHSDSbS2DiffPhase(DWORD ulHSDFactor)
{
    // pData[11] = Initial phase 1
    // pData[12] = Initial phase 2
    
    // Calculate Initial Phase
    pData[11] = (ulHSDFactor >> 15) - 32; // (factor - 1) / 2

    if(pData[11] > 0x3F)
    {
        pData[11] = 0x3F;
    }

    pData[12] = pData[11];
    
    switch(GET_3D_EXT_DATA())
    {
        //2D and 3D display have only 1 initial phase
        case _3D_EXT_OL_OR:
        case _3D_EXT_EL_ER:           
            
            break;

        //2D and 3D display have 2 initial phase    
        case _3D_EXT_OL_OR_QUIN:   
        case _3D_EXT_OL_ER_QUIN:
        case _3D_EXT_EL_OR_QUIN:
        case _3D_EXT_EL_ER_QUIN:

            // 2 different initial phase must scale down
            SET_H_SCALE_DOWN_2_DIFF_PHASE();
        
            pData[12] = pData[11] + 32;

            if(pData[12] > 0x3F)
            {
                pData[12] = 0x3F;
                pData[11] = pData[12] - 32;
            }
            
            break;

        //2D display have only 1 initial phase
        //3D display have 2 initial phase
        case _3D_EXT_OL_ER:
        case _3D_EXT_EL_OR:
        
            if(GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)
            {
                // 2 different initial phase must scale down
                SET_H_SCALE_DOWN_2_DIFF_PHASE();
            
                pData[12] = pData[11] + 32;

                if(pData[12] > 0x3F)
                {
                    pData[12] = 0x3F;
                    pData[11] = pData[12] - 32;
                }
            }    
           
            break;            
            
        default:

            break;
    }        
   
    if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)
    {
        //same as 2D set H diff phase
        ScalerScalingSet2DQuincnuxType(GET_3D_EXT_DATA(), pData[11], pData[12]);
    }
    else   
    {

#if(_QUINCNUX_ALIGN_LR_SEL == _LEFT)  
        if(GET_3D_EXT_DATA() == _3D_EXT_EL_OR)
        {
            pData[15] = pData[11];
            pData[11] = pData[12];
            pData[12] = pData[15];
        }
#else
        if(GET_3D_EXT_DATA()  == _3D_EXT_OL_ER)
        {
            pData[15] = pData[11];
            pData[11] = pData[12];
            pData[12] = pData[15];
        }
#endif
    
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, pData[11]);  
        ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[12] & 0x3F);  
        ScalerScalingSetQuincnuxType(GET_3D_EXT_DATA());
    }

    ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, ~_BIT6, (pData[11] == pData[12]) ? 0 : _BIT6);       
}

//--------------------------------------------------
// Description  : set quincunx type 
// Input Value  : quincunx type
// Output Value : None
//--------------------------------------------------
void ScalerScalingSetQuincnuxType(BYTE ucQuincunxType)
{
    switch(ucQuincunxType)
    {
        case _3D_EXT_OL_OR_QUIN:   
#if(_QUINCNUX_ALIGN_LR_SEL == _LEFT)        
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT2 | _BIT1), 0x00);  
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT4 | _BIT3), 0x00); 
#else
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT2 | _BIT1), (_BIT1));  
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT4 | _BIT3), (_BIT3)); 
#endif  

            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~_BIT0, _BIT0);  
            break;
        
        case _3D_EXT_OL_ER_QUIN:
        
#if(_QUINCNUX_ALIGN_LR_SEL == _LEFT)        
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT2 | _BIT1), 0x00);  
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT4 | _BIT3), _BIT4); 
#else
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT2 | _BIT1), (_BIT1));  
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT4 | _BIT3), (_BIT4 |_BIT3)); 
#endif  

            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~_BIT0, _BIT0);  
            break;
        
        case _3D_EXT_EL_OR_QUIN:
        
#if(_QUINCNUX_ALIGN_LR_SEL == _LEFT)        
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT2 | _BIT1), _BIT2);  
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT4 | _BIT3), 0x00); 
#else
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT2 | _BIT1), (_BIT1 | _BIT0));  
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT4 | _BIT3), (_BIT3)); 
#endif  

            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~_BIT0, _BIT0);  
            break;
            
        case _3D_EXT_EL_ER_QUIN:
        
#if(_QUINCNUX_ALIGN_LR_SEL == _LEFT)        
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT2 | _BIT1), _BIT2);  
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT4 | _BIT3), _BIT4); 
#else
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT2 | _BIT1), (_BIT1 | _BIT0));  
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3)); 
#endif  

            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~_BIT0, _BIT0);  
            break;                      
            
        default:
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2E_H_QUINCUNX_CTRL, ~_BIT0, 0x00);  
            break;
    }
}

//--------------------------------------------------
// Description  : set quincunx type for 2D by diff h phase for 2D
// Input Value  : quincunx type and initial phase
// Output Value : None
//--------------------------------------------------
void ScalerScalingSet2DQuincnuxType(BYTE ucQuincunxType, BYTE ucInitialPhase1, BYTE ucInitialPhase2)
{
    switch(ucQuincunxType)
    {
#if(_SBS_MASK_LR_SEL_BY_CAPTURE == _LEFT)    
        case _3D_EXT_OL_OR_QUIN:  
        case _3D_EXT_OL_ER_QUIN:
#else   
        case _3D_EXT_OL_OR_QUIN:  
        case _3D_EXT_EL_OR_QUIN:
#endif        
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, ucInitialPhase2);          
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ucInitialPhase1 & 0x3F);  
            break;                                    
        
        default:
            ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, ucInitialPhase1);  
            ScalerSetDataPortBit(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_2D_H_SCALE_INIT_EVEN, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ucInitialPhase2 & 0x3F);  

            break;
    }
}

#endif

#if(_2D_TO_3D_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Non-linear scaling up initial
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerScalingNonLinearScalingUpInitial(void)
{
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_06_SU_H_SF_SEGMENT_1PIXEL_H, 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_07_SU_H_SF_SEGMENT_1PIXEL_L, 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_08_SU_H_SF_SEGMENT_2PIXEL_H, 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_09_SU_H_SF_SEGMENT_2PIXEL_L, 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0A_SU_H_SF_SEGMENT_3PIXEL_H, 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0B_SU_H_SF_SEGMENT_3PIXEL_L, 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0C_SU_H_SF_DELTA_1_H, 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0D_SU_H_SF_DELTA_1_L, 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0E_SU_H_SF_DELTA_2_H, 0x00);
    ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0F_SU_H_SF_DELTA_2_L, 0x00);    
}

//--------------------------------------------------
// Description  : Non-linear scaling up setting
// Input Value  : FIFOHWidth, Convergence Mode
// Output Value : none
//--------------------------------------------------
void ScalerScalingNonLinearScalingUpSetting(WORD usFIFOHWidth)
{
    WORD usW1 = 0;            // segment1 pixel
    WORD usW2 = 0;            // segment2 pixel
    WORD usW3 = 0;            // segment3 pixel      
    
    if((GET_2DTO3D_ENABLE() == _ENABLE) && (GET_3D_SHIFT_MODE_EFFECT() != 0x00) && 
       ((GET_3D_SELECT_CONVERGENCE_MODE() != _LINEAR_MODE) && (GET_3D_SELECT_CONVERGENCE_MODE() != _NON_LINEAR_MODE_3)))
    {             
        if(usFIFOHWidth == g_stMDomainOutputData.usHWidth)
        {
            PDATA_WORD(0) = 0xFFFF;
        }
        else if(usFIFOHWidth < g_stMDomainOutputData.usHWidth)
        {
            PDATA_WORD(0) = (WORD)(((DWORD)usFIFOHWidth << 16) / g_stMDomainOutputData.usHWidth);
        }    
        else
        {
            return;
        }
         
        switch(GET_3D_SELECT_CONVERGENCE_MODE()) 
        {
            case _NON_LINEAR_MODE_1:
            case _NON_LINEAR_MODE_4:            
                ////////// Inward //////////
                usW1 = g_stMDomainOutputData.usHWidth * 13 / 96 ;
                usW2 = g_stMDomainOutputData.usHWidth * 5 / 24 ; // 20/96
                usW3 = g_stMDomainOutputData.usHWidth - SHL(usW1, 1) - SHL(usW2, 1); 

                if(PDATA_WORD(0) < 54613)
                {
                    PDATA_WORD(2) = (WORD)((DWORD)PDATA_WORD(0) * 6 / 5);
                }            
                else
                {   
                    PDATA_WORD(2) = 0xFFFF;
                }
                PDATA_WORD(1) = (WORD)((DWORD)PDATA_WORD(2) * 100 / 163);
                break;

            case _NON_LINEAR_MODE_2:
            case _NON_LINEAR_MODE_5:
                ////////// Outward //////////
                usW1 = g_stMDomainOutputData.usHWidth * 7 / 64 ; // 21/192
                usW2 = g_stMDomainOutputData.usHWidth * 5 / 24 ; // 40/192
                usW3 = g_stMDomainOutputData.usHWidth - SHL(usW1, 1) - SHL(usW2, 1); 
                
                if(PDATA_WORD(0) < 54613)
                {
                    PDATA_WORD(1) = (WORD)((DWORD)PDATA_WORD(0) * 6 / 5);
                }            
                else
                {   
                    PDATA_WORD(1) = 0xFFFF;
                }
                PDATA_WORD(2) = (WORD)((DWORD)PDATA_WORD(1) * 100 / 127);
                break;

            default:
                return;
                break;
        }
             
        //Calculate Csu = (Xm - Su(w1 - 1) - Fsu(w2 + w3))/(w1 + w2)
        PDATA_DWORD(2) = (DWORD)(1048576 >> 16) * ((DWORD)PDATA_WORD(0) * (g_stMDomainOutputData.usHWidth - 1) - (DWORD)PDATA_WORD(1) * (usW1 -1) - (DWORD)PDATA_WORD(2) * (usW2 + usW3)) / (usW1 + usW2);

        if(((PDATA_WORD(1) < PDATA_WORD(2)) && ((PDATA_DWORD(2) >> 4) > PDATA_WORD(2)))
        || ((PDATA_WORD(1) > PDATA_WORD(2)) && ((PDATA_DWORD(2) >> 4) > PDATA_WORD(1))))
        {
            return;
        }    
        
        //Calculate SU
        PDATA_DWORD(3) = SHR(((2097152 >> 16) * (DWORD)PDATA_WORD(1)) + 1, 1);
       
        if (PDATA_DWORD(3) > PDATA_DWORD(2))
        {
            PDATA_DWORD(3) = (DWORD)0 - (PDATA_DWORD(3) - PDATA_DWORD(2)) / (DWORD)usW1; //The MSB is sign bit
        }
        else
        {
            //Calculate d1
            PDATA_DWORD(3) = (PDATA_DWORD(2) - PDATA_DWORD(3)) / (DWORD)usW1;
        }

        pData[6] = ((PDATA_DWORD(3) >> 8) & 0xff);
        pData[7] = (PDATA_DWORD(3)  & 0xff);

        //Calculate Fsu
        PDATA_DWORD(3) = SHR(((2097152 >> 16) * (DWORD)PDATA_WORD(2)) + 1, 1);

        if (PDATA_DWORD(3) > PDATA_DWORD(2))
        {
            PDATA_DWORD(3) = (PDATA_DWORD(3) - PDATA_DWORD(2)) / (DWORD)usW2;
        }
        else
        {
            PDATA_DWORD(3) = (DWORD)0 - (PDATA_DWORD(2) - PDATA_DWORD(3)) / (DWORD)usW2;
        }   

        pData[8] = ((PDATA_DWORD(3) >> 8) & 0xff);
        pData[9] = (PDATA_DWORD(3) & 0xff);


        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_06_SU_H_SF_SEGMENT_1PIXEL_H, AND(HIBYTE(usW1), 0x07));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_07_SU_H_SF_SEGMENT_1PIXEL_L, LOBYTE(usW1));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_08_SU_H_SF_SEGMENT_2PIXEL_H, AND(HIBYTE(usW2), 0x07));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_09_SU_H_SF_SEGMENT_2PIXEL_L, LOBYTE(usW2));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0A_SU_H_SF_SEGMENT_3PIXEL_H, AND(HIBYTE(usW3), 0x07));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0B_SU_H_SF_SEGMENT_3PIXEL_L, LOBYTE(usW3));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0C_SU_H_SF_DELTA_1_H, pData[6]);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0D_SU_H_SF_DELTA_1_L, pData[7]);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0E_SU_H_SF_DELTA_2_H, pData[8]);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_0F_SU_H_SF_DELTA_2_L, pData[9]);

        PDATA_DWORD(3) = (1048576 >> 16) * (DWORD)PDATA_WORD(1) ;               
        
        ScalerGetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, 1, &pData[6], _NON_AUTOINC);
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        
        pData[0] = ((pData[6] & 0xF0) | ((PDATA_DWORD(3) >> 16) & 0x0F));
        pData[1] = ((PDATA_DWORD(3) >> 8) & 0xff);
        pData[2] = (PDATA_DWORD(3) & 0xff);

        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, pData[0]);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_01_SU_HOR_SCA_M, pData[1]);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_02_SU_HOR_SCA_L, pData[2]);
    }   
}
#endif

//--------------------------------------------------
// Description  : Decide which 3D scaling size
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingGetFIFOScalingSize(StructSDRAMDataInfo* pstData)
{
#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

    WORD usMemoryRemainSpace = 0;
    WORD usMemoryRemainBW = 0;
    WORD usHSDSpace = 0;
    WORD usHSDBW = 0;

    // Clear Double buffer flag
    g_bDoubleFrame = _FALSE;

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
    {
        // SBS reset function
        g_stMDomainInputData.usHWidth = g_stMDomainInputData.usHWidth / 2;
        g_stMDomainInputData.usVHeight = 2 * g_stMDomainInputData.usVHeight;
    } 
	
    // Set Reset function after ScalerMDomainGetFIFOScalingSize()
    // HW: SBS reset --> HSD --> VSD
    Scaler3DSBSHReset(g_stMDomainInputData.usHWidth);
	
#endif // End of #if(_3D_SUPPORT == _ON)
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

    //-----------------------------------------------
    // Consider FIFO Input / Output H width
    //-----------------------------------------------
    if(g_stMDomainInputData.usHWidth > g_stMDomainOutputData.usHWidth)
    {
        pstData->usInputHWidth = g_stMDomainOutputData.usHWidth;
        pstData->usOutputHWidth = g_stMDomainOutputData.usHWidth;        
    }
    else
    {
        pstData->usInputHWidth = g_stMDomainInputData.usHWidth;
        pstData->usOutputHWidth = g_stMDomainInputData.usHWidth;
    }

    //-----------------------------------------------
    // Consider FIFO Input / Output V Height
    //-----------------------------------------------
    if(g_stMDomainInputData.usVHeight > g_stMDomainOutputData.usVHeight)
    {
        pstData->usInputVHeight = g_stMDomainOutputData.usVHeight;
        pstData->usOutputVHeight = g_stMDomainOutputData.usVHeight;
    }
    else
    {
        pstData->usInputVHeight = g_stMDomainInputData.usVHeight;
        pstData->usOutputVHeight = g_stMDomainInputData.usVHeight;
    }

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    if((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
    {
        // L image + R image > Display height
        if((pstData->usInputVHeight * 2) > g_stMDomainOutputData.usVHeight)
        {
            pstData->usInputVHeight = g_stMDomainOutputData.usVHeight;
        }
    }
    else if((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D))
    {
        if(g_stMDomainInputData.usVHeight > g_stMDomainOutputData.usVHeight)
        {
            // Need to 3D VSD and 2D VSU. 
            // But HW don't support this condition. so, no VSD.            
            pstData->usInputVHeight = g_stMDomainInputData.usVHeight;
            pstData->usOutputVHeight = g_stMDomainInputData.usVHeight;
        }
    }
#endif //End of #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))

#if(_OD_SUPPORT == _ON)    
    // unit=row
    usMemoryRemainSpace = ((GET_OD_USE_SPACE() < _MEMORY_ROW) ? (_MEMORY_ROW - GET_OD_USE_SPACE()) : 0); 

    // unit=100K bus width
    usMemoryRemainBW = ((((((DWORD)1000000 * _MEMORY_SPEED) / 10 * _MEMORY_EFFICIENCY) >> 20) > GET_OD_USE_BW()) ? 
                       (((((DWORD)1000000 * _MEMORY_SPEED) / 10 * _MEMORY_EFFICIENCY) >> 20) - GET_OD_USE_BW()) : 
                       (0));
#else
    // unit=row
    usMemoryRemainSpace = _MEMORY_ROW; 

    // unit=100Kbit
    usMemoryRemainBW = ((((DWORD)1000000 * _MEMORY_SPEED) / 10 * _MEMORY_EFFICIENCY) >> 20);

#endif // End of #if(_OD_SUPPORT == _ON)

    DebugMessageFRC("usMemoryRemainBW", usMemoryRemainBW);
    DebugMessageFRC("usMemoryRemainSpace", usMemoryRemainSpace);

    //-----------------------------------------------
    // Consider FIFO Input / Output H width in 3D or FRC
    //-----------------------------------------------
    switch(GET_MEMORY_CONFIG())
    {
        case _FRC_WORK_MODE:
        case _3D_WORK_MODE:

            //*********************************************************************************//
            // if IVF = 24Hz, Memory used size = HSD x VSD x Bit/pixel x 1.5 / (Memory_row x Memory_col x Memory_bit) 
            // else Memory used size = HSD x VSD x Bit/pixel / (Memory_row x Memory_col x Memory_bit) 

            // Memory BW = HSD x IVTotal x Bit/pixel x (IVFreq + (DVFreq * (Panel_H / IHW)) / Memory_bit
            //*********************************************************************************//

            // According to usMemoryRemainBW (Memory bandwidth - OD used bandwidth), compute input H size.
            
            PDATA_WORD(0) = _PANEL_DH_WIDTH * 10 / GET_INPUT_TIMING_HWIDTH();
            PDATA_WORD(0) = (PDATA_WORD(0) <= 13) ? (PDATA_WORD(0)) : (10);
            
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))

            if(GET_3D_INPUT_FORMAT() == _FRAME_PACKING)
            {
                if((GET_INTERLACED_MODE() == _TRUE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D))
                {
                    // After Mask function, IDEN isn't average allocation in frame duration.
                    // Therefore VFreq of the input bandwidth computation (g_stMDomainInputData.usVFreq) needs " * 1.5".
                    usHSDBW = (((((DWORD)usMemoryRemainBW << 10) / 10) << 10) / g_stMDomainInputData.usVTotal * _MEMORY_BUS_WIDTH / _BIT_PER_PIXEL * 10 / (g_stMDomainInputData.usVFreq * 15 + ((DWORD)g_usDVFreq / 2 * PDATA_WORD(0))) * 10);
                }
                else
                {
                    // Total_Bandwidth = Write_Bandwidth + Read_Bandwidth.
                    // Write_Bandwidth = HSD x IVTotal x Bit/pixel x IVFreq / Memory_bit. 
                    // Read_Bandwidth = HSD x (IVTotal / 2) x Bit/pixel x (DVFreq * (Panel_H / IHW))/ Memory_bit.
                    // ( Frame packing's VTotal ~= 2D's timing VTotal * 2 )
                    usHSDBW = (((((DWORD)usMemoryRemainBW << 10) / 10) << 10) / g_stMDomainInputData.usVTotal * _MEMORY_BUS_WIDTH / _BIT_PER_PIXEL * 10 / (g_stMDomainInputData.usVFreq + ((DWORD)g_usDVFreq / 2 * PDATA_WORD(0) / 10)));
                }
            }
            else        
#endif // End of #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
            {
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
                if((GET_ASPECT_ORIGIN_MODE() == _TRUE) && (GET_INPUT_TIMING_HWIDTH() == 1920) && (GET_INPUT_TIMING_VHEIGHT() == 540))
                {
                    // For 1080i_50(Pixel_ratio = 75.24Mhz), Input used bandwidth * 1.22.
                    usHSDBW = (((((DWORD)usMemoryRemainBW << 10) / 10) << 10) / g_stMDomainInputData.usVTotal * _MEMORY_BUS_WIDTH / _BIT_PER_PIXEL * 10 / ((g_stMDomainInputData.usVFreq * 22 + (DWORD)g_usDVFreq * PDATA_WORD(0)) / 10));                    
                }
                else
#endif                    
                {
                    usHSDBW = (((((DWORD)usMemoryRemainBW << 10) / 10) << 10) / g_stMDomainInputData.usVTotal * _MEMORY_BUS_WIDTH / _BIT_PER_PIXEL * 10 / (g_stMDomainInputData.usVFreq + (DWORD)g_usDVFreq * PDATA_WORD(0) / 10));
                }
            }

            // According to usMemoryRemainSpace (Memory size - OD used size), compute input H size.
            switch(GET_MEMORY_DVF_SELECT())
            {
                case _2_IVF:
                case _1_IVF:
                case _60HZ_DISPLAY:
                    
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))

                    // For PR, frame sequential use 3 block toggle
                    if((GET_3D_INPUT_FORMAT() != _FRAME_SEQUENTIAL) ||
                       ((GET_3D_INPUT_FORMAT()== _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))
                    {
                        usHSDSpace = ((DWORD)usMemoryRemainSpace * (_MEMORY_COL_PER_BANK * _MEMORY_BANK)) * _MEMORY_BIT_NUM / pstData->usInputVHeight / _BIT_PER_PIXEL;
                        break;
                    }
                    
#elif((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))

                    // "SBS + _2_IVF" and "SBS + _3_IVF" as the same case.
                    if(((GET_3D_INPUT_FORMAT() != _SIDE_BY_SIDE_HALF) && (GET_3D_INPUT_FORMAT() != _LINE_INTERLACE)) || 
                       ((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && (GET_MEMORY_DVF_SELECT() != _2_IVF)) ||
                       ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) && (GET_MEMORY_DVF_SELECT() != _2_IVF)))
                    {
                        usHSDSpace = ((DWORD)usMemoryRemainSpace * (_MEMORY_COL_PER_BANK * _MEMORY_BANK)) * _MEMORY_BIT_NUM / pstData->usInputVHeight / _BIT_PER_PIXEL;
                        break;
                    }
                    
#else // Else of #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))

                    usHSDSpace = ((DWORD)usMemoryRemainSpace * (_MEMORY_COL_PER_BANK * _MEMORY_BANK)) * _MEMORY_BIT_NUM / pstData->usInputVHeight / _BIT_PER_PIXEL;

                    break;
                    
#endif // End of #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))

                case _3_IVF:                   
                case _2_5_IVF:
                    
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))

                    if(((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) || (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE)) && (GET_MEMORY_DVF_SELECT() != _1_IVF))
                    {
                        // Use 1/2 memory size
                        usHSDSpace = ((DWORD)usMemoryRemainSpace * (_MEMORY_COL_PER_BANK * _MEMORY_BANK)) * _MEMORY_BIT_NUM / 2 / pstData->usInputVHeight / _BIT_PER_PIXEL;                 
                    }
                    else
                    {
                        // If 3D + OD, OD used size = 0.
                        // 1 frame max used size = 2/3 * Memory size because 3D uses 3 block toggle.
                        usHSDSpace = ((DWORD)(usMemoryRemainSpace - _MEMORY_ROW * 1 / 3) * (_MEMORY_COL_PER_BANK * _MEMORY_BANK)) * _MEMORY_BIT_NUM /  pstData->usInputVHeight / _BIT_PER_PIXEL;                 
                    }

                    usHSDSpace -= 0x10; // Margin (unit: pixel) for use 3 block toggle.

#else // Else of #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))

                    // If 3D + OD, OD used size = 0.
                    // 1 frame max used size = 2/3 * Memory size because 3D uses 3 block toggle.
                    usHSDSpace = ((DWORD)(usMemoryRemainSpace - _MEMORY_ROW * 1 / 3) * (_MEMORY_COL_PER_BANK * _MEMORY_BANK)) * _MEMORY_BIT_NUM /  pstData->usInputVHeight / _BIT_PER_PIXEL;                 
                    usHSDSpace -= 0x10; // Margin (unit: pixel) for use 3 block toggle.
                    
#endif // End of #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))

                    break;
                    
                    
                default:

                    break;
            }  
            
            break;

        default:

            break;
    }       

    DebugMessageFRC("usHSDSpace", usHSDSpace);
    DebugMessageFRC("usHSDBW", usHSDBW);

    if(GET_MEMORY_CONFIG() != _NO_SDRAM_WORK_MODE)
    {
        usHSDSpace = ((usHSDSpace > usHSDBW) ? (usHSDBW) : (usHSDSpace));  
        
        // RL6229 Block step unit : row --- START
        if(pstData->usInputHWidth > usHSDSpace) // HSD impossible double buffer
        {
            pstData->usInputHWidth = usHSDSpace;
            
#if(_3D_SUPPORT == _ON)
        // 6229 FRC's double buffer mode cannot have Bank address.
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
            if((((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && 
                (GET_MEMORY_DVF_SELECT() != _1_IVF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) ||
                ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) && (GET_INTERLACED_MODE() == _TRUE)))
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
            // 1. FP interlace mode + 2D display uses FRC's double buffer mode.
            // 2. Avoid OD data overlap R image before R output in LR display.
            if(((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) && (GET_INTERLACED_MODE() == _TRUE)) ||
               ((((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && 
                (GET_MEMORY_DVF_SELECT() != _1_IVF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) ||
                ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) && (GET_INTERLACED_MODE() == _TRUE))))
#endif
            {
                // Align HWidth with 0.25/0.5/0.75/1/1.25/1.5 row
                pstData->usInputHWidth = ScalerSDRAMCalculateLineSizeAlignToRow(pstData->usInputHWidth, _FALSE);
            }
#endif //End of #if(_3D_SUPPORT == _ON)
            
        }  
        else // Else of if(pstData->usInputHWidth > usHSDSpace)
        {

#if(_3D_SUPPORT == _ON)

            // 6229 FRC's double buffer mode cannot have Bank address.
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
            if((((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && 
                (GET_MEMORY_DVF_SELECT() != _1_IVF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) ||
                ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) && (GET_INTERLACED_MODE() == _TRUE)))
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
            // 1. FP interlace mode + 2D display uses FRC's double buffer mode.
            // 2. Avoid OD data overlap R image before R output in LR display.
            if(((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) && (GET_INTERLACED_MODE() == _TRUE)) ||
               ((((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)) && 
                (GET_MEMORY_DVF_SELECT() != _1_IVF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) ||
                ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D) && (GET_INTERLACED_MODE() == _TRUE))))
#endif
            {
                // Align HWidth with 0.25/0.5/0.75/1/1.25/1.5 row
                usHSDBW = ScalerSDRAMCalculateLineSizeAlignToRow(pstData->usInputHWidth, _TRUE);
                
                usHSDBW = ((usHSDSpace >= usHSDBW) ? usHSDBW : (usHSDBW - (_MEMORY_COL_PER_BANK * _MEMORY_BIT_NUM / _BIT_PER_PIXEL)));                
                pstData->usInputHWidth = ((pstData->usInputHWidth > usHSDBW) ? usHSDBW : pstData->usInputHWidth);              
            }

#endif //End of #if(_3D_SUPPORT == _ON)
            
#if(_FRC_SUPPORT == _ON)
            if((GET_MEMORY_CONFIG() == _FRC_WORK_MODE) && (GET_MEMORY_SELECT() == _FREE_RUN_SDRAM))
            {
                // Consider Double Frame Size
                if(usMemoryRemainSpace > ((DWORD)pstData->usInputHWidth * _BIT_PER_PIXEL / _MEMORY_BIT_NUM * pstData->usInputVHeight * 2 / (_MEMORY_COL_PER_BANK * _MEMORY_BANK)))
                {
                    //Double Frame Size Conversion ok
                    g_bDoubleFrame = _TRUE;
                }
            }     
#endif // End of #if(_FRC_SUPPORT == _ON)
        }
        
    } // End of if(GET_MEMORY_CONFIG() != _NO_SDRAM_WORK_MODE)

#if(_2D_TO_3D_FUNCTION == _ON)

    // For non-linear scaling up
    if((GET_2DTO3D_ENABLE() == _ENABLE) && (GET_3D_SHIFT_MODE_EFFECT() != 0x00) && 
       ((GET_3D_SELECT_CONVERGENCE_MODE() != _LINEAR_MODE) && (GET_3D_SELECT_CONVERGENCE_MODE() != _NON_LINEAR_MODE_3)))

    {
        if(pstData->usInputHWidth > (g_stMDomainOutputData.usHWidth * 10 / 12))
        {
            pstData->usInputHWidth = (g_stMDomainOutputData.usHWidth * 10 / 12);
        }
    }  
    
#endif 

#if(_FRC_SUPPORT == _ON)
    // When DVF/IVF > 1.5, can't use one frame FRC. Use one frame FRC, drop frame too much.
    if((GET_MEMORY_CONFIG() == _FRC_WORK_MODE) && (GET_MEMORY_DVF_SELECT() == _60HZ_DISPLAY) && 
        (g_bDoubleFrame == _FALSE) && ((g_usDVFreq * 10 / g_stMDomainInputData.usVFreq) > 15))
    {
        // unit=row       
        pstData->usInputHWidth = ((DWORD)_MEMORY_ROW * (_MEMORY_COL_PER_BANK * _MEMORY_BANK)) * _MEMORY_BIT_NUM / 2 / pstData->usInputVHeight / _BIT_PER_PIXEL;
        g_bDoubleFrame = _TRUE;

#if(_OD_SUPPORT == _ON)        
        SET_OD_USE_BIT(_OFF);
#endif
    }
#endif // End of #if(_FRC_SUPPORT == _ON)

    // Let HWidth be multiple of 2.
    pstData->usInputHWidth -= (pstData->usInputHWidth % 2);
    pstData->usOutputHWidth = pstData->usInputHWidth;

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))

#if((_OD_SUPPORT == _ON) || (_SDRAM_PHASE_CALIBRATION == _ON))
    if(((GET_MEMORY_DVF_SELECT() == _2_5_IVF) || (GET_MEMORY_DVF_SELECT() == _3_IVF)) && 
       (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_LR) &&
       ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM)))
    {
        // Avoid OD data overlap R image before R output in LR display.
        pstData->usInputHWidth -= _3_BLOCK_OD_MARGIN;
        pstData->usOutputHWidth = pstData->usInputHWidth;
    }
#endif

#elif((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))

    if((GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF) && 
        (GET_MEMORY_DVF_SELECT() != _1_IVF) &&
        (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
    {
        pstData->usOutputHWidth = pstData->usOutputHWidth >> 1;
    }
     
#endif

    //-----------------------------------------------
    // Consider FIFO Input / Output V Height in 3D or FRC
    //-----------------------------------------------
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    if((GET_3D_INPUT_FORMAT()== _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D))
    {
        // L image + R image > Display height
        if((pstData->usInputVHeight * 2) > g_stMDomainOutputData.usVHeight)
        {
            pstData->usInputVHeight = g_stMDomainOutputData.usVHeight >> 1;
            pstData->usOutputVHeight = g_stMDomainOutputData.usVHeight; 
        }
    }

    if(((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_INTERLACED_MODE() == _TRUE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)) ||
       ((GET_3D_INPUT_FORMAT() == _LINE_INTERLACE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)))
    {
        pstData->usOutputVHeight = pstData->usOutputVHeight >> 1;
    }    
    
#elif((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))

    if((GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) || 
        (GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || 
        (GET_3D_INPUT_FORMAT() == _LINE_INTERLACE))
    {
        if(((GET_MEMORY_DVF_SELECT() != _1_IVF) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)) ||
           ((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_INTERLACED_MODE() == _TRUE) && (GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)))
        {
            pstData->usOutputVHeight = pstData->usOutputVHeight >> 1;
        }    
    } 
    
#endif // End of #if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

}

