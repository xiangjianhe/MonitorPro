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
// ID Code      : RL6001_Series_OD.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6001_SERIES_OD__

#include "ScalerFunctionInclude.h"

#if(_OD_SUPPORT == _ON) 
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _OD_FIFO_BUS_WIDTH                   64
#define _OD_FIFO_WR_LENGTH                   64
#define _OD_LBNRT_ENABLE                     _ON
#define _OD_LBNRT_MODE                       _NEWMODE

#define _RGB_6BIT                           18
#define _YUV422_6BIT                        12
#define _YUV422_5BIT                        10
#define _YUV422_4BIT                        8

#define _OD_NR_THD_RGB_6BIT                 1 // Threshold 6
#define _OD_NR_THD_YUV422_6BIT              1 // Threshold 6
#define _OD_NR_THD_YUV422_5BIT              1 // Threshold 6
#define _OD_NR_THD_YUV422_4BIT              1 // Threshold 6

#define _OD_YC_LEST_VALUE_YUV422_6BIT       1
#define _OD_YC_LEST_VALUE_YUV422_5BIT       2
#define _OD_YC_LEST_VALUE_YUV422_4BIT       2

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
void ScalerODControl(bit bOn);
void ScalerODInitial(void);
bit ScalerODGetEnable(void);
void ScalerODAdjustDeltaGain(BYTE ucValue);
BYTE ScalerODGetDeltaGain(void);
void ScalerODLoadLUT(BYTE *pODTable, BYTE ucBankNum, WORD usODTableLen, bit bChannelType);
BYTE ScalerODSizeConfirm(BYTE ucMaxResolution);
void ScalerODSetting(BYTE ucODResolution);
void ScalerODSetFIFO(WORD usWidth, WORD usHeight, BYTE ucODResolution);
void ScalerODHLWinType(EnumHLWType enumHLWType);
WORD ScalerODCalculateMemoryUseSpace(BYTE ucODbit);
void ScalerODOptimal(StructSDRAMDataInfo stFIFOScaling);
WORD ScalerODCalculateMemoryUseBW(BYTE ucODbit);
BYTE ScalerODGetCompressionBitNum(void);

#if(_FRC_SUPPORT == _ON)
void ScalerODIntHandler_EXINT0(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : OD on/off 
// Input Value  : ucOn --> _ON/_OFF
// Output Value : None
//--------------------------------------------------
void ScalerODControl(bit bOn)
{
    if((bOn == _ON) && (GET_OD_USE_BIT() != _OFF))
    {
        ScalerSetBit(P3_A1_LS_CTRL0, ~_BIT7, _BIT7);
    }
    else
    {
        ScalerSetBit(P3_A1_LS_CTRL0, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : OD Setting
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerODInitial(void)
{ 
    BYTE ucResolution = 0;

    ScalerODControl(_OFF);

    ucResolution = ScalerODSizeConfirm(GET_OD_USE_BIT());
         
    if((GET_OD_USE_BIT() != _OFF) && (ucResolution != _FALSE))
    {
        // Set OD settings
        ScalerODSetting(ucResolution);                    

        // Set OD FIFO
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
        if(GET_ASPECT_ORIGIN_MODE() == _TRUE)
        {
            // Get Current Background Start
            ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_03_DISP_DH_BKGD_STA_H, 2, pData, _AUTOINC);
            ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0E_DISP_DV_BKGD_STA_H, 2, &pData[2], _AUTOINC);
            pData[0] &= 0x0F;
            pData[2] &= 0x0F;
            
            // HLW H Start
            PDATA_WORD(0) = g_stMDomainOutputData.usHStart - PDATA_WORD(0);

            // HLW V Start
            PDATA_WORD(1) = g_stMDomainOutputData.usVStart - PDATA_WORD(1);

            // Set Hight Light Window Size
            ScalerColorHLWAdjust(PDATA_WORD(0), g_stMDomainOutputData.usHWidth, PDATA_WORD(1), g_stMDomainOutputData.usVHeight);

            // Set Border Width = 0
            ScalerColorHLWBorderAdjust(0x00, 0x00, 0x00, 0x00, 0x00);

            ScalerColorHLW(_ON);

            ScalerODSetFIFO(g_stMDomainOutputData.usHWidth, g_stMDomainOutputData.usVHeight, ucResolution);
        }
        else
#endif // End of #if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)           
        {
#if(_HIGHLIGHT_WINDOW_SUPPORT_FOR_OD == _ON)
            ScalerColorHLW(_OFF);
#endif    
            
            ScalerODSetFIFO(_PANEL_DH_WIDTH, _PANEL_DV_HEIGHT, ucResolution);
        }
        
        // Enable SDRAM Access (On-line Switch will Blink)
        ScalerSetBit(P3_A1_LS_CTRL0, ~_BIT6, _BIT6);        
    }
    else
    {
#if(_HIGHLIGHT_WINDOW_SUPPORT_FOR_OD == _ON)
        ScalerColorHLW(_OFF);
#endif    
        
        // Disable SDRAM Access (On-line Switch will Blink)
        ScalerSetBit(P3_A1_LS_CTRL0, ~_BIT6, 0x00);        
    }
}

//--------------------------------------------------
// Description  : Get OD Enable or not
// Input Value  : None
// Output Value : _ENABLE/ _DISABLE
//--------------------------------------------------
bit ScalerODGetEnable(void)
{
    return ((bit)ScalerGetBit(P3_A1_LS_CTRL0, _BIT7)) ? _ENABLE : _DISABLE;
}

//--------------------------------------------------
// Description  : OD adjust delta gain
// Input Value  : Delta gain
// Output Value : None
//--------------------------------------------------
void ScalerODAdjustDeltaGain(BYTE ucValue)
{
    ScalerSetByte(P3_B1_LS_DELTA_GAIN, (ucValue & 0x7F));
}

//--------------------------------------------------
// Description  : Get OD Delta gain
// Input Value  : None
// Output Value : Delta gain
//--------------------------------------------------
BYTE ScalerODGetDeltaGain(void)
{
    return (ScalerGetByte(P3_B1_LS_DELTA_GAIN) & 0x7F);
}

//--------------------------------------------------
// Description  : OD Load OD LUT
// Input Value  : 
//                pODTable -> OD TABLE Pointer
//                ucBankNum -> bank number
//                usODTableLen -> OD Table Length
//                bChannelType -> channel type
// Output Value : None
//--------------------------------------------------
void ScalerODLoadLUT(BYTE *pODTable, BYTE ucBankNum, WORD usODTableLen, bit bChannelType)
{
    // Enable LUT access
    ScalerSetBit(P3_AE_LS_LUT_ROW_ADDR, ~_BIT7, _BIT7);

    // Set LUT row selector = 0
    ScalerSetBit(P3_AE_LS_LUT_ROW_ADDR, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Set LUT column selector = 0
    ScalerSetBit(P3_AF_LS_LUT_COL_ADDR, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00); 

    if((bChannelType == _OD_TABLE_COMMON))
    {
        ScalerSetBit(P3_AF_LS_LUT_COL_ADDR, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);
        ScalerBurstWrite(pODTable, usODTableLen, ucBankNum, P3_B0_LS_LUT_DATA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
    else
    {
        for(pData[0] = 0; pData[0] < 3; pData[0]++)
        {
            ScalerSetBit(P3_AF_LS_LUT_COL_ADDR, ~(_BIT7 | _BIT6), pData[0] << 6);
            ScalerBurstWrite(&pODTable[pData[0]], usODTableLen, ucBankNum, P3_B0_LS_LUT_DATA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
        }
    }

    ScalerSetBit(P3_AE_LS_LUT_ROW_ADDR, ~_BIT7, 0x00);
}

//--------------------------------------------------
// Description  : OD Size Confirm
// Input Value  : Max/Min Resolution
// Output Value : return Resolution
//--------------------------------------------------
BYTE ScalerODSizeConfirm(BYTE ucMaxResolution)
{    
    BYTE ucPixelChannel = 3;
    BYTE ucResolution = 6; 

    // Check if resolution is RGB 6bit
    if((((WORD)ucPixelChannel * ucResolution * 10) <= ucMaxResolution) && 
        (((WORD)ucPixelChannel * ucResolution * 10) >= ScalerODGetCompressionBitNum()))
    {
        return (ucPixelChannel * ucResolution);
    }
    else
    {
        ucPixelChannel = 2;

        // Check if resolution is YC mode
        for(ucResolution = 6; ucResolution > 3; ucResolution--)
        {
            if((((WORD)ucPixelChannel * ucResolution * 10) <= ucMaxResolution) && 
                (((WORD)ucPixelChannel * ucResolution * 10) >= ScalerODGetCompressionBitNum()))
            {
                return (ucPixelChannel * ucResolution);
            }
        }
    }

    return _FALSE;    
}

//--------------------------------------------------
// Description  : OD adjust block setting
// Input Value  : 
//                Source Type
//                OD Resolution Bit
// Output Value : None
//--------------------------------------------------
void ScalerODSetting(BYTE ucODResolution)
{
    switch(ucODResolution)
    {
        case _RGB_6BIT: 
            ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), (_DISP_BIT_MODE << 2));
            
            // RGB Mode
            ScalerSetBit(P3_A4_LS_CPRS_CTRL, ~_BIT4, 0x00); 
            
            // RGB->YUV rounding 10 bit
            ScalerSetBit(P3_CE_LS_FRAME2, ~(_BIT7 | _BIT6), 0x00); 

            // Set Noise Reduction Threshold
            ScalerSetBit(P3_A2_LS_CTRL1, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _OD_LBNRT_ENABLE << 4 | _OD_LBNRT_MODE << 3 | (_OD_NR_THD_RGB_6BIT & 0x07));

            break;

        case _YUV422_6BIT: 
            ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), (_DISP_BIT_MODE << 2));

            // YC Mode
            ScalerSetBit(P3_A4_LS_CPRS_CTRL, ~_BIT4, _BIT4); 

            // RGB->YUV rounding 6 bit
            ScalerSetBit(P3_CE_LS_FRAME2, ~(_BIT7 | _BIT6), _BIT6); 

            // Set Estimation Value        
            ScalerSetBit(P3_CE_LS_FRAME2, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_OD_YC_LEST_VALUE_YUV422_6BIT & 0x3F));

            // Set Noise Reduction Threshold
            ScalerSetBit(P3_A2_LS_CTRL1, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _OD_LBNRT_ENABLE << 4 | _OD_LBNRT_MODE << 3 | (_OD_NR_THD_YUV422_6BIT & 0x07));

            break;

        case _YUV422_5BIT:
            ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), ((_DISP_BIT_MODE << 2) | _BIT0));

            // YC Mode
            ScalerSetBit(P3_A4_LS_CPRS_CTRL, ~_BIT4, _BIT4); 

            // Rounding 5 bit    
            ScalerSetBit(P3_CE_LS_FRAME2, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6)); 

            // Set Estimation Value        
            ScalerSetBit(P3_CE_LS_FRAME2, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_OD_YC_LEST_VALUE_YUV422_5BIT & 0x3F));

            // Set Noise Reduction Threshold
            ScalerSetBit(P3_A2_LS_CTRL1, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _OD_LBNRT_ENABLE << 4 | _OD_LBNRT_MODE << 3 | (_OD_NR_THD_YUV422_5BIT & 0x07));

            break;
            
        case _YUV422_4BIT:    
            ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT2 | _BIT1 | _BIT0), ((_DISP_BIT_MODE << 2) | _BIT1));

            // YC Mode
            ScalerSetBit(P3_A4_LS_CPRS_CTRL, ~_BIT4, _BIT4);

            // Rounding 4 bit
            ScalerSetBit(P3_CE_LS_FRAME2, ~(_BIT7 | _BIT6), _BIT7);     

            // Set Estimation Value        
            ScalerSetBit(P3_CE_LS_FRAME2, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_OD_YC_LEST_VALUE_YUV422_4BIT & 0x3F));

            // Set Noise Reduction Threshold
            ScalerSetBit(P3_A2_LS_CTRL1, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _OD_LBNRT_ENABLE << 4 | _OD_LBNRT_MODE << 3 | (_OD_NR_THD_YUV422_4BIT & 0x07));

            break;

        default:
            
            return;
            
            break;
    }
    
    if((bit)ScalerGetBit(P3_A4_LS_CPRS_CTRL, _BIT4)) // YC Rounding
    {
        // Enable color convertion block
        ScalerSetBit(P3_CC_LS_FRAME0, ~(_BIT7 | _BIT4 | _BIT3 | _BIT0), _BIT4 | _BIT3 | _BIT0);
        ScalerSetBit(P3_CD_LS_FRAME1, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT0), _BIT7 | _BIT4 | _BIT3 | _BIT0);
    }
    else // RGB Rounding
    {
        ScalerSetBit(P3_CC_LS_FRAME0, ~(_BIT7 | _BIT4 | _BIT3 | _BIT0), 0x00);
        ScalerSetBit(P3_CD_LS_FRAME1, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT0), 0x00);
    }

    // Enable Level Estimation
    ScalerSetBit(P3_A1_LS_CTRL0, ~_BIT5, _BIT5);

    // Enable Gain
    ScalerSetBit(P3_A1_LS_CTRL0, ~_BIT3, _BIT3);

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    // Choose HLW type according to aspect ratio type
    if(GET_ASPECT_ORIGIN_MODE() == _TRUE)
    {
        ScalerODHLWinType(_INSIDE_WINDOW);
    }
    else
#endif        
    {
        ScalerODHLWinType(_FULL_WINDOW);
    }
    
    // Clear flag
    ScalerSetByte(P3_B6_LS_STATUS0, _BIT0);
} 

//--------------------------------------------------
// Description  : OD Set OD Fifo
// Input Value  : 
//                usWidth -> Display Width
//                usHeight -> Display Height
//                ucODResolution -> OD Resolution
//                ucLength -> Set Fifo Length
// Output Value : None
//--------------------------------------------------
void ScalerODSetFIFO(WORD usWidth, WORD usHeight, BYTE ucODResolution)
{
    // Set Memory Start Address
#if((_SDRAM_SIZE_CONFIG == _1M_16BIT) || (_SDRAM_SIZE_CONFIG == _1M_32BIT))
    PDATA_WORD(0) = (DWORD)(_MEMORY_ROW - GET_OD_USE_SPACE()) << 1;
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
    PDATA_WORD(0) = (DWORD)(_MEMORY_ROW - GET_OD_USE_SPACE()) << 2;
#endif

    ScalerSetByte(P3_C6_LS_MEM_START_ADDR_H, pData[0]);
    ScalerSetByte(P3_C7_LS_MEM_START_ADDR_M, pData[1]);

    // Calculate total size of a frame to be saved in memory
    PDATA_DWORD(0) = (DWORD)usWidth * usHeight * ucODResolution;
    PDATA_DWORD(0) = (PDATA_DWORD(0) % _OD_FIFO_BUS_WIDTH) ?
                     (PDATA_DWORD(0) / _OD_FIFO_BUS_WIDTH) + 1 :
                     (PDATA_DWORD(0) / _OD_FIFO_BUS_WIDTH);

    // Calculate Number and Remain --> (Number x Length + Remain) x OD_FIFO_BUS_WIDTH = Total size
    PDATA_DWORD(0) = ScalerSDRAMCalculateNumberAndRemain(PDATA_DWORD(0), _OD_FIFO_WR_LENGTH, 1);

    // Set Water Level for Write
    ScalerSetByte(P3_C0_LS_WTLVL_W, (_OD_FIFO_WR_LENGTH / 2));

    // Set Water Level for Read according to Remain value
    if(pData[1] < (_OD_FIFO_WR_LENGTH / 2))
    {
        ScalerSetByte(P3_C1_LS_WTLVL_R, (_OD_FIFO_WR_LENGTH / 2));
    }
    else
    {
        ScalerSetByte(P3_C1_LS_WTLVL_R, pData[1]);
    }

    // Set Number
    ScalerSetByte(P3_C2_LS_MEM_FIFO_RW_NUM_H, pData[2]);
    ScalerSetByte(P3_C3_LS_MEM_FIFO_RW_NUM_L, pData[3]);

    // Set Length
    ScalerSetByte(P3_C4_LS_MEM_FIFO_RW_LEN, _OD_FIFO_WR_LENGTH);

    // Set Remain
    ScalerSetByte(P3_C5_LS_MEM_FIFO_RW_REMAIN, pData[1]);
}

//--------------------------------------------------
// Description  : OD HLW Type Select
// Input Value  : ucHLWType --> Inside, Outside or Full
// Output Value : None
//--------------------------------------------------
void ScalerODHLWinType(EnumHLWType enumHLWType)
{
    // Select OD HLW Type
    switch(enumHLWType)
    {
        case _FULL_WINDOW:

            ScalerSetBit(P3_A2_LS_CTRL1, ~(_BIT7 | _BIT6), _BIT7 | _BIT6); 
            
            break;

        case _INSIDE_WINDOW:

            ScalerSetBit(P3_A2_LS_CTRL1, ~(_BIT7 | _BIT6), _BIT7); 

            break;

        case _OUTSIDE_WINDOW:

            ScalerSetBit(P3_A2_LS_CTRL1, ~(_BIT7 | _BIT6), _BIT6); 

            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Calculate memory use space 
// Input Value  : OD use bit(10x)
// Output Value : OD memory use space, unit:row 
//--------------------------------------------------
WORD ScalerODCalculateMemoryUseSpace(BYTE ucODbit) // ucODbit = real ODbit x 10, 6.5bit OD --> ucODbit = 65
{
    //***************************************************//
    // Column = Column_per_bank * memory_bank
    // Row = Total memory unit / column    
    //***************************************************//

    // According to remain size ( Memory size - FIFO used size), compute OD max used bits (pixel/bits).
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)                
    if(GET_ASPECT_ORIGIN_MODE() == _TRUE)
    {
        // OD memory size, unit:row
        return (((DWORD)g_stMDomainOutputData.usVHeight * g_stMDomainOutputData.usHWidth * ucODbit / _MEMORY_BIT_NUM) / (_MEMORY_COL_PER_BANK * _MEMORY_BANK) / 10 + 1); 
    }
    else
#endif        
    {
        // OD memory size, unit:row
        return (((DWORD)_PANEL_DV_HEIGHT * _PANEL_DH_WIDTH * ucODbit / _MEMORY_BIT_NUM) / (_MEMORY_COL_PER_BANK * _MEMORY_BANK) / 10 + 1); 
    }        
}

//--------------------------------------------------
// Description  : Optimize OD bit
// Input Value  : Fifo Vheight and Hwidth to calculate FRC and 3D size
// Output Value : None
// usODBitSpace = 10 x OD bit
//--------------------------------------------------
void ScalerODOptimal(StructSDRAMDataInfo stFIFOScaling)
{
    WORD usODBitSpace = 0;
    WORD usODBitBW = 0;

    switch(GET_MEMORY_CONFIG())
    {
#if(_FRC_SUPPORT == _ON)
        case _FRC_WORK_MODE:
            if((GET_H_SCALE_DOWN() == _FALSE) && (GET_OD_USE_BIT() != _OFF))
            { 
                // Compute FIFO used size (unit : row).
                PDATA_WORD(0)= (DWORD)stFIFOScaling.usInputHWidth * _BIT_PER_PIXEL / _MEMORY_BIT_NUM;
                PDATA_DWORD(0) = ((DWORD)stFIFOScaling.usInputVHeight * PDATA_WORD(0) / (_MEMORY_COL_PER_BANK * _MEMORY_BANK));
                
                if(g_bDoubleFrame == _TRUE)
                {
                   PDATA_DWORD(0) = PDATA_DWORD(0) * 2; 
                }

                // Compute remain size ( Memory size - FIFO used size).  
                usODBitSpace = (_MEMORY_ROW - PDATA_DWORD(0));

                // Compute remain bandwidth ( Memory bandwidth - FIFO used bandwidth).   
                PDATA_WORD(0) = _PANEL_DH_WIDTH * 10 / GET_INPUT_TIMING_HWIDTH();
                PDATA_WORD(0) = (PDATA_WORD(0) <= 13) ? (PDATA_WORD(0)) : (10);

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
                if((GET_ASPECT_ORIGIN_MODE() == _TRUE) && (GET_INPUT_TIMING_HWIDTH() == 1920) && (GET_INPUT_TIMING_VHEIGHT() == 540))
                {
                    // 1080i
                    usODBitBW = (((((DWORD)1000000 * _MEMORY_SPEED) / 10 * _MEMORY_EFFICIENCY) >> 20) - ((((DWORD)stFIFOScaling.usInputHWidth * g_stMDomainInputData.usVTotal * _BIT_PER_PIXEL / _MEMORY_BUS_WIDTH * ((g_stMDomainInputData.usVFreq * 20 + (DWORD)g_usDVFreq * PDATA_WORD(0)) / 10)) >> 20) + 1));
                }
                else
#endif
                {                
                    usODBitBW = (((((DWORD)1000000 * _MEMORY_SPEED) / 10 * _MEMORY_EFFICIENCY) >> 20) - ((((DWORD)stFIFOScaling.usInputHWidth * g_stMDomainInputData.usVTotal * _BIT_PER_PIXEL / _MEMORY_BUS_WIDTH * (g_stMDomainInputData.usVFreq + (DWORD)g_usDVFreq * PDATA_WORD(0) / 10)) >> 20) + 1));
                }

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
                // According to remain size ( Memory size - FIFO used size), compute OD max used bits (pixel/bits).
                if(GET_ASPECT_ORIGIN_MODE() == _TRUE)
                {
                    // According to remain size ( Memory size - FIFO used size), compute OD max used bits (pixel/bits). 
    	    	    usODBitSpace = ((DWORD)usODBitSpace * (_MEMORY_COL_PER_BANK * _MEMORY_BANK) * _MEMORY_BIT_NUM) * 10 / ((DWORD)g_stMDomainOutputData.usVHeight * g_stMDomainOutputData.usHWidth); // 10*OD_bit
                }
                else
#endif
                {
                    // According to remain size ( Memory size - FIFO used size), compute OD max used bits (pixel/bits).
                    usODBitSpace = ((DWORD)usODBitSpace * (_MEMORY_COL_PER_BANK * _MEMORY_BANK) * _MEMORY_BIT_NUM) * 10 / ((DWORD)_PANEL_DV_HEIGHT * _PANEL_DH_WIDTH); // 10*OD_bit
                }

                // According to remain bandwidth ( Memory bandwidth - FIFO used bandwidth), compute OD max used bits (pixel/bits).
                usODBitBW = (((DWORD)usODBitBW) << 20) / 2 / g_usDVFreq * 10 * _MEMORY_BUS_WIDTH / _PANEL_DH_WIDTH / g_stMDomainOutputData.usVTotal;            

                usODBitSpace = ((usODBitSpace > usODBitBW) ? usODBitBW : usODBitSpace);
                usODBitSpace = ((usODBitSpace > 180) ? 180 : (usODBitSpace / 5 * 5));

                SET_OD_USE_BIT(usODBitSpace);
                
                SET_OD_USE_SPACE(ScalerODCalculateMemoryUseSpace(usODBitSpace));

            }
            break;
#endif // End of #if(_FRC_SUPPORT == _ON)

        case _NO_SDRAM_WORK_MODE:

            // For compiler warning
            stFIFOScaling = stFIFOScaling;

            // Based on Memory size, compute OD max used bits (pixel/bits). 
            usODBitSpace = ((DWORD)_MEMORY_SIZE << 20) * 10 / ((DWORD)_PANEL_DV_HEIGHT * _PANEL_DH_WIDTH);

            // Based on Memory bandwidth, compute OD max used bits (pixel/bits). 
            usODBitBW = ((((DWORD)1000000 * _MEMORY_SPEED) / 10 / 2) * _MEMORY_EFFICIENCY) / g_usDVFreq * 10 * _MEMORY_BUS_WIDTH / g_stMDomainOutputData.usHTotal / g_stMDomainOutputData.usVHeight;
                    
            usODBitSpace = ((usODBitSpace > usODBitBW) ? usODBitBW : usODBitSpace);
            usODBitSpace = ((usODBitSpace > 180) ? 180 : (usODBitSpace / 5 * 5));

            SET_OD_USE_BIT(usODBitSpace);
            SET_OD_USE_SPACE(ScalerODCalculateMemoryUseSpace(usODBitSpace));
            
            break;

        default:
            // For compiler warning
            stFIFOScaling = stFIFOScaling;
            break;
    }
}

//--------------------------------------------------
// Description  : Calculate memory use BW 
// Input Value  : OD use bit(10x)
// Output Value : OD memory use BW, unit:100k 
//--------------------------------------------------
WORD ScalerODCalculateMemoryUseBW(BYTE ucODbit)
{
    DWORD ulODMemoryBW = 0;

    ulODMemoryBW = ((DWORD)_PANEL_DH_WIDTH * g_stMDomainOutputData.usVTotal * ucODbit * 2 / 1024 * g_usDVFreq /_MEMORY_BUS_WIDTH / 1024);     
    ulODMemoryBW = (ulODMemoryBW / 10) + ((ulODMemoryBW % 10) ? 1 : 0);
    
    return ulODMemoryBW;
}

//--------------------------------------------------
// Description  : Get OD Compressoin Bit Number by Panel Resolution
// Input Value  : None
// Output Value : OD Compression Bit Number
//--------------------------------------------------
BYTE ScalerODGetCompressionBitNum(void)
{
    return (80);
}

#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : OD Interrupt Process (EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerODIntHandler_EXINT0(void) using 1
{
    // For Compiler waring
    // Empty function (Only for 6229 2Mx32bit SDRAM)
}
#endif // End of #if(_FRC_SUPPORT == _ON) 

#endif // End of #if(_OD_SUPPORT == _ON)
