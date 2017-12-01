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
// ID Code      : RL6269_Series_Scaling.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6269_SERIES_SCALING__

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
void ScalerScalingSetScalingDown(StructSDRAMDataInfo stFIFOScaling);
void ScalerScalingSetScalingUp(StructSDRAMDataInfo stFIFOScaling);
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
    // Disable Scale Down
    ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT7 | _BIT3 |_BIT2 | _BIT1 | _BIT0), 0x00);
    
    //===============================
    // Decide H direction scaling down
    //===============================
    // Set H Scaling Down Factor
    if(g_stMDomainInputData.usHWidth > stFIFOScaling.usInputHWidth)
    {
        SET_H_SCALE_DOWN();
        
        // Calculate Scaling Factor        
        PDATA_DWORD(0) = (DWORD)g_stMDomainInputData.usHWidth << 20;
        PDATA_DWORD(0) = (PDATA_DWORD(0) / stFIFOScaling.usInputHWidth) + ((PDATA_DWORD(0) % stFIFOScaling.usInputHWidth) ? 1 : 0);                
        
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, ((PDATA_DWORD(0) >> 16) & 0x7F));
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, (PDATA_DWORD(0) & 0xFF));

        // Calculate Initial Phase
        PDATA_DWORD(0) = (PDATA_DWORD(0) >> 15) - 32;

        if(PDATA_DWORD(0) > 0x3F)
        {
            PDATA_DWORD(0) = 0x3F;
        }

        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, PDATA_DWORD(0));    
    }
    else
    {
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_04_H_SCALE_INIT, 0x00);
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_05_H_SCALE_DH, 0x10);
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_06_H_SCALE_DM, 0x00);
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_07_H_SCALE_DL, 0x00);        
    }

    if(GET_H_SCALE_DOWN())
    {
        // Enable H Scale Down
        ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~(_BIT3 | _BIT1), _BIT1);
    }
    
    //===============================
    // Decide V direction scaling down
    //===============================    
    // Set V Scaling Down Factor
    if(g_stMDomainInputData.usVHeight > stFIFOScaling.usInputVHeight)
    {

        SET_V_SCALE_DOWN();
        
        // Calculate Scaling Factor        
        PDATA_DWORD(0) = ((DWORD)g_stMDomainInputData.usVHeight << 18) / stFIFOScaling.usInputVHeight;
        PDATA_DWORD(0) = (PDATA_DWORD(0) + 1) >> 1;

        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, ((PDATA_DWORD(0) >> 16) & 0x07));
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, (PDATA_DWORD(0) & 0xFF));                   

        // Calculate Initial Phase
        PDATA_DWORD(0) = (PDATA_DWORD(0) >> 12) - 32;

        if(PDATA_DWORD(0) > 0x3F)
        {
            PDATA_DWORD(0) = 0x3F;
        }

        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, PDATA_DWORD(0));                     
    }
    else
    {
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_00_V_SCALE_INIT, 0x00);
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_01_V_SCALE_DH, 0x02);
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_02_V_SCALE_DM, 0x00);
        ScalerSetDataPortByte(CM_24_SCALE_DOWN_ACCESS_PORT, _CM_25_PT_03_V_SCALE_DL, 0x00);        
    }

    if(GET_V_SCALE_DOWN())
    {
        // Enable V Scale Down
        ScalerSetBit(CM_23_SCALE_DOWN_CTRL, ~_BIT0, _BIT0);
    }
}

//--------------------------------------------------
// Description  : Decide which scaling up function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingSetScalingUp(StructSDRAMDataInfo stFIFOScaling)
{
    // Disable Scale Up
    ScalerSetBit(CM_32_SCALE_CTRL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    //===============================
    // Decide V direction scaling up
    //===============================
    // Set V Scaling Up Factor    
    if(stFIFOScaling.usOutputVHeight < g_stMDomainOutputData.usVHeight)
    {
        SET_V_SCALE_UP();    
        
        PDATA_DWORD(0) = (DWORD)stFIFOScaling.usOutputVHeight << 20;
        PDATA_DWORD(0) = (PDATA_DWORD(0) / g_stMDomainOutputData.usVHeight) + (PDATA_DWORD(0) % 2);

        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_03_SU_VER_SCA_H, ((PDATA_DWORD(0) >> 16) & 0x0F));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_04_SU_VER_SCA_M, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_05_SU_VER_SCA_L, (PDATA_DWORD(0) & 0xFF));    
        
        if((GET_INTERLACED_MODE() == _FALSE) || (ScalerGetBit(CM_10_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) || (GET_INPUT_TIMING_HWIDTH() == _PANEL_DH_WIDTH))
        {
            ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xC4);        
        }
        else
        {
            ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0xFF);
        }         
    }
    else
    {
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_03_SU_VER_SCA_H, 0x0F);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_04_SU_VER_SCA_M, 0xFF);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_05_SU_VER_SCA_L, 0xFF);
    }  

    if(GET_V_SCALE_UP())
    {
        // Enable V Scale Up
        ScalerSetBit(CM_32_SCALE_CTRL, ~(_BIT2 | _BIT1), _BIT1);
    }        
    
    //===============================
    // Decide H direction scaling up
    //===============================
    // Set H Scaling Up Factor
    if(stFIFOScaling.usOutputHWidth < g_stMDomainOutputData.usHWidth)
    {
        SET_H_SCALE_UP();    
        
        PDATA_DWORD(0) = (DWORD)stFIFOScaling.usOutputHWidth << 20;
        PDATA_DWORD(0) = (PDATA_DWORD(0) / g_stMDomainOutputData.usHWidth) + (PDATA_DWORD(0) % 2);

        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, ((PDATA_DWORD(0) >> 16) & 0x0F));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_01_SU_HOR_SCA_M, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_02_SU_HOR_SCA_L, (PDATA_DWORD(0) & 0xFF));        

        // Set H Initial Phase
        // R = Input width /Output width
        // ideal initial phase = (1+R)*16*8        
        PDATA_DWORD(0) = (DWORD)(stFIFOScaling.usOutputHWidth + g_stMDomainOutputData.usHWidth) * 16 * 8 / g_stMDomainOutputData.usHWidth;
        
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, pData[3]);

        // Enable H Scale Up
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT0, _BIT0);
    }
    else
    {
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, 0x0F);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_01_SU_HOR_SCA_M, 0xFF);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_02_SU_HOR_SCA_L, 0xFF);   

        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xFF);

        // Disable H Scale Up
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT0, 0x00);
    }         

    // Enable H Scale Up
    ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT0, _BIT0);    
}

//--------------------------------------------------
// Description  : Decide which 3D scaling size
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingGetFIFOScalingSize(StructSDRAMDataInfo* pstData)
{
#if(_FRC_SUPPORT == _ON)

    WORD usMemoryRemainSpace = 0;
    WORD usMemoryRemainBW = 0;
    WORD usHSDSpace = 0;
    WORD usHSDBW = 0;

    // Clear Double buffer flag
    g_bDoubleFrame = _FALSE;

#endif // End of #if(_FRC_SUPPORT == _ON)

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

#if(_FRC_SUPPORT == _ON)

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

            //*********************************************************************************//
            // if IVF = 24Hz, Memory used size = HSD x VSD x Bit/pixel x 1.5 / (Memory_row x Memory_col x Memory_bit) 
            // else Memory used size = HSD x VSD x Bit/pixel / (Memory_row x Memory_col x Memory_bit) 

            // Memory BW = HSD x IVTotal x Bit/pixel x (IVFreq + (DVFreq * (Panel_H / IHW)) / Memory_bit
            //*********************************************************************************//

            // According to usMemoryRemainBW (Memory bandwidth - OD used bandwidth), compute input H size.
            
            PDATA_WORD(0) = _PANEL_DH_WIDTH * 10 / GET_INPUT_TIMING_HWIDTH();
            PDATA_WORD(0) = (PDATA_WORD(0) <= 13) ? (PDATA_WORD(0)) : (10);
            

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

            // According to usMemoryRemainSpace (Memory size - OD used size), compute input H size.
            switch(GET_MEMORY_DVF_SELECT())
            {
                case _2_IVF:
                case _1_IVF:
                case _60HZ_DISPLAY:
                    
                    usHSDSpace = ((DWORD)usMemoryRemainSpace * (_MEMORY_COL_PER_BANK * _MEMORY_BANK)) * _MEMORY_BIT_NUM / pstData->usInputVHeight / _BIT_PER_PIXEL;

                    break;
                    

                case _3_IVF:                   
                case _2_5_IVF:
                    

                    // If 3D + OD, OD used size = 0.
                    // 1 frame max used size = 2/3 * Memory size because 3D uses 3 block toggle.
                    usHSDSpace = ((DWORD)(usMemoryRemainSpace - _MEMORY_ROW * 1 / 3) * (_MEMORY_COL_PER_BANK * _MEMORY_BANK)) * _MEMORY_BIT_NUM /  pstData->usInputVHeight / _BIT_PER_PIXEL;                 
                    usHSDSpace -= 0x10; // Margin (unit: pixel) for use 3 block toggle.
					
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
        }  
        else // Else of if(pstData->usInputHWidth > usHSDSpace)
        {            
            if((GET_MEMORY_CONFIG() == _FRC_WORK_MODE) && (GET_MEMORY_SELECT() == _FREE_RUN_SDRAM))
            {
                // Consider Double Frame Size
                if(usMemoryRemainSpace > ((DWORD)pstData->usInputHWidth * _BIT_PER_PIXEL / _MEMORY_BIT_NUM * pstData->usInputVHeight * 2 / (_MEMORY_COL_PER_BANK * _MEMORY_BANK)))
                {
                    //Double Frame Size Conversion ok
                    g_bDoubleFrame = _TRUE;
                }
            }     
        }
        
    } // End of if(GET_MEMORY_CONFIG() != _NO_SDRAM_WORK_MODE)

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

#endif // End of #if(_FRC_SUPPORT == _ON)

}

