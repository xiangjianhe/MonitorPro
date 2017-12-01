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
// ID Code      : RL6269_Series_OD.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6269_SERIES_OD__

#include "ScalerFunctionInclude.h"

#if(_OD_SUPPORT == _ON) 
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _OD_FIFO_BUS_WIDTH                  64
#define _OD_FIFO_WR_LENGTH                  96
#define _OD_LBNRT_ENABLE                    _ON
#define _OD_LBNRT_MODE                      _NEWMODE

#define _OD_SRC_PIXEL_RESOL_8               0
#define _OD_SRC_PIXEL_RESOL_6               1
#define _OD_SRC_PIXEL_RESOL_5               2
#define _OD_SRC_PIXEL_RESOL_4               3

#define _OD_YUV_444_TO_422                  0
#define _OD_YUV_444_TO_411                  1
#define _OD_SPR_PIXEL_1X2                   2
#define _OD_SPR_PIXEL_1X3                   3
#define _OD_SPR_PIXEL_1X4                   4

#define _OD_SUPERPIXEL1X2_75BIT             0   // Compression Bit -> 7.5
#define _OD_SUPERPIXEL1X4_60BIT             1   // Compression Bit -> 6.0

#define _OD_PIXEL_PER_COMP                  4   // Number of Pixels Processed Per Compression
#define CEILING(x,y)                        ((x % y) ? (((x / y) + 1) * y) : x)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_FRC_SUPPORT == _ON)
BYTE g_ucODDVSCount = 0; 
BYTE g_ucODAddrChangeCount = 0;  
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerODControl(bit bOn);
void ScalerODInitial(void);
bit ScalerODGetEnable(void);
void ScalerODAdjustDeltaGain(BYTE ucValue);
BYTE ScalerODGetDeltaGain(void);
void ScalerODLoadLUT(BYTE *pODTable, BYTE ucBankNum, WORD usODTableLen, bit bChannelType);
void ScalerODSetting(void);
void ScalerODSetFIFO(WORD usWidth, WORD usHeight, BYTE ucODResolution);
void ScalerODHLWinType(EnumHLWType enumHLWType);
void ScalerODOptimal(StructSDRAMDataInfo stFIFOScaling);
WORD ScalerODCalculateMemoryUseSpace(BYTE ucODbit);
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
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
        if(GET_ASPECT_ORIGIN_MODE() == _TRUE)
        {
            // OD is not supported in aspect original(1:1) mode
#if(_FRC_SUPPORT == _ON)
            DebugMessageFRC("OD_OFF", 0);
            ScalerGlobalSetInterrupt(_IRQ_DEN, _DISABLE);
#endif
            ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT7 | _BIT6), 0x00);

            return;
        }
#endif

#if(_FRC_SUPPORT == _ON)
        DebugMessageFRC("OD_ON", 0);

        // Wait DVS start event
        ScalerTimerWaitForEvent(_EVENT_DEN_START);

        // Get current free run DVS counter
        ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_28_FREE_RUN_DVS_CNT, 1, &pData[0], _NON_AUTOINC);
        g_ucODDVSCount = pData[0] + 1;

        // FRC On + 3D Off case : 24->60Hz / 24->72Hz uses HW auto 3 block toggle
        if((GET_MEMORY_DVF_SELECT() == _3_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF) || (GET_MEMORY_DVF_SELECT() == _2_IVF))
        {
            // Set next address change counter of 3 block toggle for 3D 24Hz
            if(GET_MEMORY_DVF_SELECT() == _2_5_IVF)
            {
                switch(g_ucODDVSCount)
                {
                    case 1:
                        // Wait DVS event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                        
                    case 2:
                        g_ucODDVSCount = 0;
                        g_ucODAddrChangeCount = 2; 
                        
                        break;
                        
                    case 3:
                        // Wait DVS event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                        
                    case 4:
                        g_ucODDVSCount = 0;
                        g_ucODAddrChangeCount = 3;
                        break;
                        
                    case 5:                        
                        g_ucODDVSCount = 1;
                        g_ucODAddrChangeCount = 3;
                        break;
                        
                    default:
                        break;                    
                }
                // Enable DEN start IRQ
                ScalerGlobalSetInterrupt(_IRQ_DEN, _ENABLE);
            }
            else if(GET_MEMORY_DVF_SELECT() == _3_IVF)            
            {
                g_ucODAddrChangeCount = 3;
                
                switch(g_ucODDVSCount)
                {
                    case 1:
                        g_ucODDVSCount = 2;
                        break;
                        
                    case 2:
                        // Wait DVS event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                        
                    case 3:
                        g_ucODDVSCount = 1;
                        break;
                        
                    default:
                        break;                    
                }
               
                // Enable DEN start IRQ
                ScalerGlobalSetInterrupt(_IRQ_DEN, _ENABLE);
            }
            else if(GET_MEMORY_DVF_SELECT() == _2_IVF)
            {
                g_ucODAddrChangeCount = 2;

                switch(g_ucODDVSCount)
                {
                    case 1:
                        // Wait DVS event
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                        
                    case 2:
                        g_ucODDVSCount = 1;
                        break;
                        
                    default:
                        break;
                }
        
                // Enable DEN start IRQ
                ScalerGlobalSetInterrupt(_IRQ_DEN, _ENABLE);
            }            
            else
            {
                ScalerGlobalSetInterrupt(_IRQ_DEN, _DISABLE);
                ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            }
        }
        else
        {
            ScalerGlobalSetInterrupt(_IRQ_DEN, _DISABLE);
            ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
        }
            
#else // Else of #if(_FRC_SUPPORT == _ON)

        ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

#endif // End of #if(_FRC_SUPPORT == _ON)

    }
    else
    {
        
#if(_FRC_SUPPORT == _ON)
        DebugMessageFRC("OD_OFF", 0);

        ScalerGlobalSetInterrupt(_IRQ_DEN, _DISABLE);
#endif 

        ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT7 | _BIT6), 0x00);
    }
}

//--------------------------------------------------
// Description  : OD Setting
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerODInitial(void)
{    
    ScalerODControl(_OFF);

    if(GET_OD_USE_BIT() != _OFF)
    {      
        // Set OD settings        
        ScalerODSetting();
        
        // Set OD FIFO
        ScalerODSetFIFO(_PANEL_DH_WIDTH, _PANEL_DV_HEIGHT, ScalerODGetCompressionBitNum());
    }
}

//--------------------------------------------------
// Description  : Get OD Enable or not
// Input Value  : None
// Output Value : _ENABLE/ _DISABLE
//--------------------------------------------------
bit ScalerODGetEnable(void)
{
    return (ScalerGetBit(P3_A1_LS_CTRL0, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6)) ? _ENABLE : _DISABLE;
}

//--------------------------------------------------
// Description  : OD adjust delta gain
// Input Value  : Delta gain
// Output Value : None
//--------------------------------------------------
void ScalerODAdjustDeltaGain(BYTE ucValue)
{
    ScalerSetByte(P3_A3_LS_DELTA_GAIN, ucValue);
}

//--------------------------------------------------
// Description  : Get OD Delta gain
// Input Value  : None
// Output Value : Delta gain
//--------------------------------------------------
BYTE ScalerODGetDeltaGain(void)
{
    return ScalerGetByte(P3_A3_LS_DELTA_GAIN);
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
    ScalerSetBit(P3_BF_LS_LUT_CTRL, ~(_BIT7 | _BIT6), _BIT7);
    
    if((bChannelType == _OD_TABLE_COMMON))
    {
        ScalerBurstWrite(pODTable, usODTableLen, ucBankNum, P3_C0_LS_LUT_DATA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }

    ScalerSetBit(P3_BF_LS_LUT_CTRL, ~_BIT7, 0x00);
}

//--------------------------------------------------
// Description  : OD adjust block setting
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerODSetting(void)
{
    BYTE ucODCompressionMode = 0;
    BYTE ucODLevelEstimationValue = 0;
    BYTE ucODNRThreshold = 0;

    if(ScalerODGetCompressionBitNum() == 75)
    {
        ucODCompressionMode = _OD_SUPERPIXEL1X2_75BIT;
        ucODLevelEstimationValue = 4; // Range: 0~63
        ucODNRThreshold = 3;        
    }
    else if(ScalerODGetCompressionBitNum() == 60)
    {
        ucODCompressionMode = _OD_SUPERPIXEL1X4_60BIT;
        ucODLevelEstimationValue = 2; // Range: 0~63
        ucODNRThreshold = 1;        
    }
    
    if(ucODCompressionMode == _OD_SUPERPIXEL1X2_75BIT)
    {
        // Set Previous Frame Source Pixel Resolution: 5bit
        ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT1 | _BIT0), _OD_SRC_PIXEL_RESOL_5);
        
        // Current Path: Disable RGB->YUV, Enable Compression, Set to Super-pixel 1x2
        ScalerSetBit(P3_B0_LS_FRAME0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT4 | (_OD_SPR_PIXEL_1X2 << 1)));

        // Enable Decompression, Disable Previous/Current Frame YUV->RGB
        ScalerSetBit(P3_B1_LS_FRAME1, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), (_BIT7 | _BIT3));

        // Set Current Frame Source Pixel Resolution: 5bit
        // Disable Previous/Current Frame UV Round
        ScalerSetBit(P3_B2_LS_FRAME2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_OD_SRC_PIXEL_RESOL_5 << 6));
    }   
    else if(ucODCompressionMode == _OD_SUPERPIXEL1X4_60BIT)
    {
        // Set Previous Frame Source Pixel Resolution: 8bit
        ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT1 | _BIT0), _OD_SRC_PIXEL_RESOL_8);

        // Current Path: Disable RGB->YUV, Enable Compression, Set to Super-pixel 1x2
        ScalerSetBit(P3_B0_LS_FRAME0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT4 | (_OD_SPR_PIXEL_1X4 << 1)));

        // Enable Decompression, Disable Previous/Current Frame YUV->RGB
        ScalerSetBit(P3_B1_LS_FRAME1, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), (_BIT7 | _BIT3));

        // Set Current Frame Source Pixel Resolution: 8bit
        // Disable Previous/Current Frame UV Round
        ScalerSetBit(P3_B2_LS_FRAME2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_OD_SRC_PIXEL_RESOL_8 << 6));    
    }
    
    // Set Level Estimation Gain
    ScalerSetBit(P3_B4_LS_FRAME5, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (ucODLevelEstimationValue & 0x3F));
    
    // Enable Level Estimation
    ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT5), _BIT5);

    // Enable Gain
    ScalerSetBit(P3_A1_LS_CTRL0, ~(_BIT3), _BIT3);

    // Apply OD on full screen
    ScalerODHLWinType(_FULL_WINDOW);

    // Set Noise Reduction Threshold
    ScalerSetBit(P3_A2_LS_CTRL1, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _OD_LBNRT_ENABLE << 4 | _OD_LBNRT_MODE << 3 | (ucODNRThreshold & 0x07));
    
    // Clear flag
    ScalerSetByte(P3_A4_LS_STATUS0, _BIT0);
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

    ScalerSetByte(P3_AC_LS_MEM_START_ADDR_H, pData[0]);
    ScalerSetByte(P3_AD_LS_MEM_START_ADDR_M, pData[1]);

#if(_FRC_SUPPORT == _ON)
    ScalerSDRAMSetODThreeBlockAddress(); 
#endif // End of #if(_FRC_SUPPORT == _ON)

    // Calculate total size of a frame to be saved in memory
    PDATA_DWORD(0) = ((DWORD)CEILING(usWidth, _OD_PIXEL_PER_COMP)) * usHeight * ucODResolution / 10;
    PDATA_DWORD(0) = (PDATA_DWORD(0) % _OD_FIFO_BUS_WIDTH) ?
                     (PDATA_DWORD(0) / _OD_FIFO_BUS_WIDTH) + 1 :
                     (PDATA_DWORD(0) / _OD_FIFO_BUS_WIDTH);

    // Calculate Number and Remain --> (Number x Length + Remain) x OD_FIFO_BUS_WIDTH = Total size
    PDATA_DWORD(0) = ScalerSDRAMCalculateNumberAndRemain(PDATA_DWORD(0), _OD_FIFO_WR_LENGTH, 1);

    // Set Water Level for Write
    ScalerSetByte(P3_A6_LS_WTLVL_W, (_OD_FIFO_WR_LENGTH / 2));

    // Set Water Level for Read
    ScalerSetByte(P3_A7_LS_WTLVL_R, _OD_FIFO_WR_LENGTH);

    // Set Number
    ScalerSetByte(P3_A8_LS_MEM_FIFO_RW_NUM_H, pData[2]);
    ScalerSetByte(P3_A9_LS_MEM_FIFO_RW_NUM_L, pData[3]);

    // Set Length
    ScalerSetByte(P3_AA_LS_MEM_FIFO_RW_LEN, _OD_FIFO_WR_LENGTH);

    // Set Remain
    ScalerSetByte(P3_AB_LS_MEM_FIFO_RW_REMAIN, pData[1]);
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
// Description  : Optimize OD bit
// Input Value  : Fifo Vheight and Hwidth to calculate FRC and 3D size
// Output Value : None
// usODBitSpace = 10 x OD bit
//--------------------------------------------------
void ScalerODOptimal(StructSDRAMDataInfo stFIFOScaling)
{
    // For compiler warning
    stFIFOScaling = stFIFOScaling;
}

//--------------------------------------------------
// Description  : Calculate memory use space 
// Input Value  : OD use bit(10x) ucODbit = real ODbit x 10, 6.5bit OD --> ucODbit = 65
// Output Value : OD memory use space, unit:row 
//--------------------------------------------------
WORD ScalerODCalculateMemoryUseSpace(BYTE ucODbit) 
{
    //***************************************************//
    // Column = Column_per_bank * memory_bank
    // Row = Total memory unit / column    
    //***************************************************//

    // OD memory size, unit:row
    return ((((DWORD)CEILING(_PANEL_DH_WIDTH, _OD_PIXEL_PER_COMP)) * _PANEL_DV_HEIGHT * ucODbit / _MEMORY_BIT_NUM) / 
            (_MEMORY_COL_PER_BANK * _MEMORY_BANK) / 10 + 1);
}

//--------------------------------------------------
// Description  : Calculate memory use BW 
// Input Value  : OD use bit(10x)
// Output Value : OD memory use BW, unit:100k 
//--------------------------------------------------
WORD ScalerODCalculateMemoryUseBW(BYTE ucODbit)
{
    DWORD ulODMemoryBW = 0;

#if(_FRC_SUPPORT == _ON)
    if(GET_MEMORY_DVF_SELECT() == _2_IVF)
    {
        ulODMemoryBW = ((((DWORD)CEILING(_PANEL_DH_WIDTH, _OD_PIXEL_PER_COMP)) * g_stMDomainOutputData.usVTotal * ucODbit >> 10) * 
                        g_usDVFreq /_MEMORY_BUS_WIDTH >> 10);
    }
    else
#endif
    {
        ulODMemoryBW = ((((DWORD)CEILING(_PANEL_DH_WIDTH, _OD_PIXEL_PER_COMP)) * g_stMDomainOutputData.usVTotal * ucODbit * 2 >> 10) * 
                        g_usDVFreq /_MEMORY_BUS_WIDTH >> 10);
    }

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
    if(((((DWORD)CEILING(_PANEL_DH_WIDTH, _OD_PIXEL_PER_COMP)) * _PANEL_DV_HEIGHT * 75) / 10) <= ((DWORD)_MEMORY_16MB << 20))
    {
        return (75);
    }
    else if(((((DWORD)CEILING(_PANEL_DH_WIDTH, _OD_PIXEL_PER_COMP)) * _PANEL_DV_HEIGHT * 60) / 10) <= ((DWORD)_MEMORY_16MB << 20))
    {
        return (60);
    }

    return 0;
}

#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : OD Interrupt Process (EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerODIntHandler_EXINT0(void) using 1
{
    // DEN start event 
    if(ScalerGetBit_EXINT0(CM_08_NEW_ADDED_STATUS1, (_BIT3| _BIT2)) == (_BIT3| _BIT2))
    {
        // Clear DEN IRQ flag
        ScalerSetBit_EXINT0(CM_08_NEW_ADDED_STATUS1, ~_BIT2, _BIT2);
        
        g_ucODDVSCount += 1;

        // FRC
        if((GET_MEMORY_DVF_SELECT() == _3_IVF) || 
           (GET_MEMORY_DVF_SELECT() == _2_5_IVF) ||
           (GET_MEMORY_DVF_SELECT() == _2_IVF))
        {
            if(g_ucODAddrChangeCount == 3)
            {
                if(g_ucODDVSCount == 2)
                {
                    if(ScalerGetBit_EXINT0(P5_C1_SDRF_MN_MADDR_TOG_CTL, (_BIT1 | _BIT0)) == 0x00)
                    {
                        ScalerSetByte_EXINT0(P3_AC_LS_MEM_START_ADDR_H, (g_ulSdrThreeBlockAddr1 >> 16) & 0xFF);
                        ScalerSetByte_EXINT0(P3_AD_LS_MEM_START_ADDR_M, (g_ulSdrThreeBlockAddr1 >> 8) & 0xFF);
                        ScalerSetByte_EXINT0(P3_AE_LS_MEM_START_ADDR_L, g_ulSdrThreeBlockAddr1 & 0xFF);
                    }
                    else if(ScalerGetBit_EXINT0(P5_C1_SDRF_MN_MADDR_TOG_CTL, (_BIT1 | _BIT0)) == _BIT0)
                    {
                        ScalerSetByte_EXINT0(P3_AC_LS_MEM_START_ADDR_H, (g_ulSdrThreeBlockAddr2>> 16) & 0xFF);
                        ScalerSetByte_EXINT0(P3_AD_LS_MEM_START_ADDR_M, (g_ulSdrThreeBlockAddr2 >> 8) & 0xFF);
                        ScalerSetByte_EXINT0(P3_AE_LS_MEM_START_ADDR_L, g_ulSdrThreeBlockAddr2 & 0xFF);
                    }
                    else
                    {
                        ScalerSetByte_EXINT0(P3_AC_LS_MEM_START_ADDR_H, (g_ulSdrThreeBlockAddr3 >> 16) & 0xFF);
                        ScalerSetByte_EXINT0(P3_AD_LS_MEM_START_ADDR_M, (g_ulSdrThreeBlockAddr3 >> 8) & 0xFF);
                        ScalerSetByte_EXINT0(P3_AE_LS_MEM_START_ADDR_L, g_ulSdrThreeBlockAddr3 & 0xFF);
                    }
                    
                    ScalerSetBit_EXINT0(P3_A1_LS_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
                }
                else if(g_ucODDVSCount == 3)
                {
                    g_ucODDVSCount = 0;

                    if(GET_MEMORY_DVF_SELECT() == _2_5_IVF)
                    {
                        g_ucODAddrChangeCount = 2;
                    }

                    ScalerSetBit_EXINT0(P3_A1_LS_CTRL0, ~(_BIT7 | _BIT6), 0x00);
                }                   
            }
            else
            {
                if(g_ucODDVSCount == 1)
                {
                    if(GET_MEMORY_DVF_SELECT() != _2_IVF)
                    {
                        if(ScalerGetBit_EXINT0(P5_C1_SDRF_MN_MADDR_TOG_CTL, (_BIT1 | _BIT0)) == 0x00)
                        {
                            ScalerSetByte_EXINT0(P3_AC_LS_MEM_START_ADDR_H, (g_ulSdrThreeBlockAddr1 >> 16) & 0xFF);
                            ScalerSetByte_EXINT0(P3_AD_LS_MEM_START_ADDR_M, (g_ulSdrThreeBlockAddr1 >> 8) & 0xFF);
                            ScalerSetByte_EXINT0(P3_AE_LS_MEM_START_ADDR_L, g_ulSdrThreeBlockAddr1 & 0xFF);
                        }
                        else if(ScalerGetBit_EXINT0(P5_C1_SDRF_MN_MADDR_TOG_CTL, (_BIT1 | _BIT0)) == _BIT0)
                        {
                            ScalerSetByte_EXINT0(P3_AC_LS_MEM_START_ADDR_H, (g_ulSdrThreeBlockAddr2 >> 16) & 0xFF);
                            ScalerSetByte_EXINT0(P3_AD_LS_MEM_START_ADDR_M, (g_ulSdrThreeBlockAddr2 >> 8) & 0xFF);
                            ScalerSetByte_EXINT0(P3_AE_LS_MEM_START_ADDR_L, g_ulSdrThreeBlockAddr2 & 0xFF);
                        }
                        else
                        {
                            ScalerSetByte_EXINT0(P3_AC_LS_MEM_START_ADDR_H, (g_ulSdrThreeBlockAddr3 >> 16) & 0xFF);
                            ScalerSetByte_EXINT0(P3_AD_LS_MEM_START_ADDR_M, (g_ulSdrThreeBlockAddr3 >> 8) & 0xFF);
                            ScalerSetByte_EXINT0(P3_AE_LS_MEM_START_ADDR_L, g_ulSdrThreeBlockAddr3 & 0xFF);
                        }
                    }
                    
                    ScalerSetBit_EXINT0(P3_A1_LS_CTRL0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
                }
                else if(g_ucODDVSCount == 2)
                {
                    g_ucODDVSCount = 0;
                    
                    if(GET_MEMORY_DVF_SELECT() != _2_IVF)
                    {
                        g_ucODAddrChangeCount = 3;
                    }

                    ScalerSetBit_EXINT0(P3_A1_LS_CTRL0, ~(_BIT7 | _BIT6), 0x00);
                }                 
            }
        }
    }
}
#endif // End of #if(_FRC_SUPPORT == _ON)
#endif // End of #if(_OD_SUPPORT == _ON)

