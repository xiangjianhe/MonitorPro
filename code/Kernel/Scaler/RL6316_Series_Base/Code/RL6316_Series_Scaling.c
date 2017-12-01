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
// ID Code      : RL6316_Series_Scaling.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6316_SERIES_SCALING__

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

        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_11_SU_V_COEF_INI_VALUE, 0x44);        
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
    }
    else
    {
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_00_SU_HOR_SCA_H, 0x0F);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_01_SU_HOR_SCA_M, 0xFF);
        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_02_SU_HOR_SCA_L, 0xFF);   

        ScalerSetDataPortByte(CM_33_SU_ACCESS_PORT, _CM_34_PT_10_SU_H_COEF_INI_VALUE, 0xFF);
    }   
    
    if(GET_H_SCALE_DOWN() == _FALSE)
    {
        // Enable H Scale Up
        ScalerSetBit(CM_32_SCALE_CTRL, ~_BIT0, _BIT0);
    }
}

//--------------------------------------------------
// Description  : Decide which 3D scaling size
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingGetFIFOScalingSize(StructSDRAMDataInfo* pstData)
{
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
}

