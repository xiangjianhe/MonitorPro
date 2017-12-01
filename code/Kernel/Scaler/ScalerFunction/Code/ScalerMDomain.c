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
// ID Code      : ScalerMDomain.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_MDOMAIN__

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

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
bit idata g_bAspectOriginMode = 0;
#endif

#if(_OD_SUPPORT == _ON)
BYTE idata g_ucMemoryODUseBit = 0;
WORD idata g_usMemoryODUseSpace = 0;
WORD idata g_usMemoryODUseBW = 0;
#endif

#if((_OD_SUPPORT == _ON) || (_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
bit g_bDoubleFrame = _FALSE;
WORD idata g_usDVFreq = 0;
#endif

DWORD idata g_ulDClkFreq = 0;

StructMDomainInfo idata g_stMDomainInfo;
StructTimingInfo data g_stMDomainInputData;
StructDisplayInfo data g_stMDomainOutputData;
    
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerMDomainControl(void);
bit ScalerMDomainMemoryCheck(void);
BYTE ScalerMDomainMemorySelectConfirm(void); 
void ScalerMDomainSetDisplayFormat(BYTE ucMemorySel);
void ScalerMDomainSetScaling(StructSDRAMDataInfo stFIFOScaling);
void ScalerMDomainFSVgipDoubleBufferApply(void);

void ScalerMDomainMemoryConfig(void);

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
void ScalerMDomainAspectOriginMode(bit bOn);
#endif

#if(_OD_SUPPORT == _ON)
void ScalerMDomainODConfig(void);

#if(_FRC_SUPPORT == _ON)
WORD ScalerMDomainGetFRCMemorySpace(WORD usIVheight, WORD usIHwidth);
WORD ScalerMDomainGetFRCMemoryBW(WORD usIVF, WORD usIHwidth);
#endif

#if(_3D_SUPPORT == _ON)
WORD ScalerMDomainGet3DMemorySpace(WORD usIVheight, WORD usIHwidth);
WORD ScalerMDomainGet3DMemoryBW(void);
#endif // End of #if(_3D_SUPPORT == _ON)

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
void ScalerMDomainCalMemoryUseSpaceBW(void);
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
#endif // End of #if(_OD_SUPPORT == _ON)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : M Domain Main Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerMDomainControl(void)
{        
#if(_3D_SUPPORT == _ON)
    bit b3DDoubleBuffer = _FALSE;
#endif

    StructSDRAMDataInfo stFIFOScaling;   

    ScalerMDomainMemoryConfig();

    // Update DVT in Line buffer frame sync
    if(GET_MEMORY_CONFIG() == _NO_SDRAM_WORK_MODE)
    {
        g_stMDomainOutputData.usVTotal = ((DWORD)g_stMDomainInputData.usHFreq * (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight * 1000) / g_stMDomainInputData.usVFreq; 
    }

    // Select Memory Configuration Type
    SET_MEMORY_SELECT(ScalerMDomainMemorySelectConfirm());
    
    // Disable Spread Spectrum
    ScalerPllSetDpllSsc(_DCLK_SPREAD_SPEED, _OFF);

#if(_OD_SUPPORT == _ON)
	ScalerMDomainODConfig();
#endif
    
    // Get Scaling size in FIFO 
    ScalerScalingGetFIFOScalingSize(&stFIFOScaling);
        
    // Scaling Setting 
    ScalerMDomainSetScaling(stFIFOScaling);

    // Enable Active Region Measure
    ScalerMeasureSetRegionCount(_MEASURE_TARGET_INPUT, _ACTIVE_REGION_TYPE);
    
#if(_OD_SUPPORT == _ON)
    ScalerODOptimal(stFIFOScaling);    
#endif

    // Set FIFO Capture Window
    ScalerMemorySetFifoCapture(stFIFOScaling.usOutputHWidth, stFIFOScaling.usOutputVHeight);
    
    // Set up Line Buffer
    ScalerMemorySetUpLineBuffer();
    
    // Set Memory Utilization
    switch(GET_MEMORY_SELECT())
    {
        case _FRAME_SYNC_LINE_BUFFER:

#if(_3D_SUPPORT == _ON)

            // 3D Misc Double buffer enable
            if(GET_3D_MISC_DOUBLE_BUFFER() == _TRUE)
            {   
                b3DDoubleBuffer = _TRUE;
                Scaler3DAdjustWithoutMuteLineBuffer();
            }
            else
            {
                // Initial M Domain Block
                ScalerMemoryInitial();            

                // Set FIFO freq.
                ScalerMemorySetFIFOFreq(_SCALER_FIFO_FREQ_M2PLL);
                
                // Set DVSt At Least Larger than 3.5 Input Lines for Buffering Input Data
                g_stMDomainOutputData.usVStart = ((DWORD)35 * g_stMDomainOutputData.usVHeight / g_stMDomainInputData.usVHeight + 5) / 10;
                if(g_stMDomainOutputData.usVStart < _PANEL_DV_START)
                {
                    g_stMDomainOutputData.usVStart = _PANEL_DV_START;        
                }

                // Set Initial Dt Value
                ScalerMemoryFrameSyncSetDt();
                
                // Set display Format
                ScalerMDomainSetDisplayFormat(_FRAME_SYNC_LINE_BUFFER);

                // Fine Tune DClk Offset
                ScalerDPLLFineTuneFrameSync(); 

                // Adjust IVS/IHS for Position Range
                ScalerIDomainVgipAdjustIHVDelay();

                ScalerMDomainFSVgipDoubleBufferApply();
                
#if(_2D_TO_3D_FUNCTION == _ENABLE)
                g_ucIVstart = ScalerGetByte(CM_19_IPV_ACT_STA_L);
                g_ucIVSDelay = ScalerGetByte(CM_1C_IVS_DELAY);
                g_ucDVstart = g_stMDomainOutputData.usVStart;  
#endif
            }

#if(_2D_TO_3D_FUNCTION == _ON)
            // Check Frame Sync for 3D
            if(GET_2DTO3D_ENABLE() == _ENABLE)
            {
                ScalerMemoryFrameSyncTuneDt();
            }
#endif

#else // Else of #if(_3D_SUPPORT == _ON)

            // Initial M Domain Block
            ScalerMemoryInitial();            

            // Set FIFO freq.
            ScalerMemorySetFIFOFreq(_SCALER_FIFO_FREQ_M2PLL);
            
            // Set DVSt At Least Larger than 3.5 Input Lines for Buffering Input Data
            g_stMDomainOutputData.usVStart = ((DWORD)35 * g_stMDomainOutputData.usVHeight / g_stMDomainInputData.usVHeight + 5) / 10;
            if(g_stMDomainOutputData.usVStart < _PANEL_DV_START)
            {
                g_stMDomainOutputData.usVStart = _PANEL_DV_START;        
            }

            // Set Initial Dt Value
            ScalerMemoryFrameSyncSetDt();

            // Set display Format
            ScalerMDomainSetDisplayFormat(_FRAME_SYNC_LINE_BUFFER);

            // Fine Tune DClk Offset
            ScalerDPLLFineTuneFrameSync(); 

            // Adjust IVS/IHS for Position Range
            ScalerIDomainVgipAdjustIHVDelay();

            ScalerMDomainFSVgipDoubleBufferApply();

#endif // End of #if(_3D_SUPPORT == _ON)    

            break;
            
#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

        case _FRAME_SYNC_SDRAM:
        case _FREE_RUN_SDRAM:
        case _MN_FRAME_SYNC_SDRAM: 

            // Measure Input Active Region
            ScalerMeasureSetRegionCount(_MEASURE_TARGET_INPUT, _ACTIVE_REGION_TYPE);
            g_ulActiveRegionBackUp = ScalerMeasureGetRegionCountResult(_WAIT);

#if(_3D_SUPPORT == _ON)

            // 3D Misc Double buffer enable
            if(GET_3D_MISC_DOUBLE_BUFFER() == _TRUE)
            {
                b3DDoubleBuffer = _TRUE;
                
                if(GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT)
                {
                    // Set 3D control
                    Scaler3DControl(stFIFOScaling.usInputHWidth, stFIFOScaling.usInputVHeight, stFIFOScaling.usOutputHWidth, stFIFOScaling.usOutputVHeight);
                }

#if(_FRC_SUPPORT == _ON)
                if(GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT)
                {
                    // Set FRC control
                    ScalerFRCControl(stFIFOScaling.usInputHWidth, stFIFOScaling.usInputVHeight);                    
                }
#endif // End of #if(_FRC_SUPPORT == _ON)

                Scaler3DAdjustWithoutMuteFrameBuffer();
            }
            else
#endif // End of #if(_3D_SUPPORT == _ON)
            {
                // Initial M Domain Block
                ScalerMemoryInitial();   
                
                // Set FIFO freq.
                ScalerMemorySetFIFOFreq(_SCALER_FIFO_FREQ_MPLL);

                // Adjust IVS/IHS for Position Range
                ScalerIDomainVgipAdjustIHVDelay();

                ScalerVgipDoubleBufferApply();

                // Set display Format           
                ScalerMDomainSetDisplayFormat(GET_MEMORY_SELECT());
                
#if(_3D_SUPPORT == _ON)

                if(GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT)
                {
                    // Set 3D control
                    Scaler3DControl(stFIFOScaling.usInputHWidth, stFIFOScaling.usInputVHeight, stFIFOScaling.usOutputHWidth, stFIFOScaling.usOutputVHeight);

                    break;
                }
                
#endif // End of #if(_3D_SUPPORT == _ON)

#if(_FRC_SUPPORT == _ON)
                // Set FRC control
                ScalerFRCControl(stFIFOScaling.usInputHWidth, stFIFOScaling.usInputVHeight); 
#endif // End of #if(_FRC_SUPPORT == _ON)

            }
            
            break;

#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

        default:

            // Initial M Domain Block
            ScalerMemoryInitial();   
            
            break;
    }    

    // Enable Spread Spectrum
    ScalerPllSetDpllSsc(_DCLK_SPREAD_SPEED, _DCLK_SPREAD_RANGE);         

    // Measure Input Active Region
    ScalerMeasureSetRegionCount(_MEASURE_TARGET_INPUT, _ACTIVE_REGION_TYPE);
    
    ScalerTimerWaitForEvent(_EVENT_IVS);    

#if(_OD_SUPPORT == _ON)
    // Set ODInitial after FRC setting for 3D  
    ScalerODInitial();
#endif    

#if((_SDRAM_PHASE_CALIBRATION == _ON) && ((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON)))
#if(_OD_SUPPORT == _ON)
    if(GET_OD_USE_BIT() == _OFF)
#endif
    {
        // Only 6229 : HW auto block toggle in 24Hz
        ScalerSDRAMSetODThreeBlockAddress();
    }
#endif    

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)

#if(_3D_SUPPORT == _ON)
    if(b3DDoubleBuffer == _FALSE)
    {
        ScalerSDRAMReset();
    }
#else
    ScalerSDRAMReset();
#endif

#endif

    // Clear Buffer Status
    ScalerSetByte(CM_02_STATUS0, 0x00);

    // Clear Display Vsync timeout flag
    ScalerSetBit(CM_0C_WATCH_DOG_CTRL0, ~_BIT0, _BIT0);

    ScalerTimerWaitForEvent(_EVENT_IVS);  

    if((ScalerMDomainMemoryCheck() == _FALSE) ||
       (ScalerMeasureActiveRegionChange() == _TRUE))
    {
        DebugMessageScaler("MemoryCheck Fail in Display Setting", GET_MEMORY_SELECT());    
                
        return _FALSE;            
    }

#if(_LC_TANK_SUPPORT == _ON)
    // Save current status for DPLL
    ScalerLCTankDpllOffsetRegulationInitial();
#endif

    return _TRUE;
}

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerMDomainMemoryCheck(void)
{                                   
    // Check fifo under/overflow and Input HVsync error flag, Display Vsync timeout flag 
    if((ScalerGetBit(CM_02_STATUS0, (_BIT6 | _BIT5 | _BIT1 | _BIT0)) != 0x00) || (ScalerGetBit(CM_0C_WATCH_DOG_CTRL0, _BIT0) != 0x00))
    {
        return _FALSE;
    }   
    
    return _TRUE;
}

//--------------------------------------------------
// Description  : Memory select and consider OD size to calculate HSD for FRC and 3D
// Input Value  : Memory word type and SDram InputHwidth/InputVheight/OutputHwidth/OutputVeight
// Output Value : Memory select
//--------------------------------------------------
BYTE ScalerMDomainMemorySelectConfirm(void)
{
    switch(GET_MEMORY_CONFIG())
    {
        case _NO_SDRAM_WORK_MODE:
            
            return _FRAME_SYNC_LINE_BUFFER;

#if(_FRC_SUPPORT == _ON)
        case _FRC_WORK_MODE:        

            if((g_stMDomainInputData.usVFreq < _PANEL_MIN_FRAME_RATE) || (g_stMDomainInputData.usVFreq > _PANEL_MAX_FRAME_RATE)) 
            {
                switch(GET_MEMORY_DVF_SELECT())
                {
                    case _3_IVF:                       
                    case _2_5_IVF:
                    case _2_IVF:

                        return _MN_FRAME_SYNC_SDRAM;

                    default:

                        return _FREE_RUN_SDRAM;
                }    
            }
            else
            {
                return _FRAME_SYNC_SDRAM;
            }
#endif

#if(_3D_SUPPORT == _ON)

        case _3D_WORK_MODE:

            switch(GET_MEMORY_DVF_SELECT())
            {
                case _3_IVF:                   
                case _2_5_IVF:
                case _2_IVF:
                   
                    return _MN_FRAME_SYNC_SDRAM;

                case _1_IVF:

                    return _FRAME_SYNC_SDRAM;

                default:
                    
                    return _FREE_RUN_SDRAM;
            }    
#endif    

        default:

            return _FRAME_SYNC_LINE_BUFFER;
    }        
}

//--------------------------------------------------
// Description  : Set Display Format
// Input Value  : ucMemorySel --> FrameSyn/FreeRun
// Output Value : _FALSE => DCLK Exceed Supported Range
//--------------------------------------------------
void ScalerMDomainSetDisplayFormat(BYTE ucMemorySel)
{        
    // Set Display Format

    // Set DHS Width (Must be Even number)
    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_02_DISP_DHS_END);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, (_PANEL_DH_SYNC_WIDTH + _PANEL_DH_SYNC_WIDTH % 2));

    // Set DVS Width
    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0D_DISP_DVS_END);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, _PANEL_DV_SYNC_HEIGHT);      
    
    // Background HStart
    PDATA_WORD(0) = _PANEL_DH_START + ((_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT) ? (_PANEL_DH_START % 2) : 0);
    
    // Background HEnd
    PDATA_WORD(1) = PDATA_WORD(0) + g_stMDomainOutputData.usHBackWidth;

    // Active HStart
    PDATA_WORD(2) = g_stMDomainOutputData.usHStart + ((_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT) ? (g_stMDomainOutputData.usHStart % 2) : 0);    

    // Active HEnd
    PDATA_WORD(3) = PDATA_WORD(2) + g_stMDomainOutputData.usHWidth;

    // Active VEnd        
    PDATA_WORD(4) = g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight;    

    // Wait for Porch to Avoid Settings Applied on Differnt Frames
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // Set Display Active Vstart/Vend
    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_10_DISP_DV_ACT_STA_H);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, HIBYTE(g_stMDomainOutputData.usVStart));  
    ScalerSetByte(CM_2B_DISP_DATA_PORT, LOBYTE(g_stMDomainOutputData.usVStart)); 
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[8]);  
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[9]);  

    // Set Display Active Hstart/Hend
    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_05_DISP_DH_ACT_STA_H);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[4]);  
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[5]);      
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[6]); 
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[7]);  

    // Set Display Background Hstart/Hend
    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_03_DISP_DH_BKGD_STA_H);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, (pData[0] & 0x0F));
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[1]);   
    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_09_DISP_DH_BKGD_END_H);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, (pData[2] & 0x0F));
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[3]);         
    
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)

    // Set Display Background Vstart/Vend   
    if((GET_ASPECT_ORIGIN_MODE() == _TRUE) && (ucMemorySel != _FRAME_SYNC_LINE_BUFFER))
    {
        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0E_DISP_DV_BKGD_STA_H);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, HIBYTE(_PANEL_DV_START));   

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0F_DISP_DV_BKGD_STA_L);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, LOBYTE(_PANEL_DV_START));         
        
        
        // Set OSD DEN Reference
        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_21_DISP_OSD_REFERENCE_DEN);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, (_PANEL_DV_START - 4));        

        PDATA_WORD(0) = _PANEL_DV_START + g_stMDomainOutputData.usVBackHeight;        
    }
    else
#endif // End of #if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)

    {
        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0E_DISP_DV_BKGD_STA_H);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, HIBYTE(g_stMDomainOutputData.usVStart));   

        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0F_DISP_DV_BKGD_STA_L);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, LOBYTE(g_stMDomainOutputData.usVStart));         
        
        
        // Set OSD DEN Reference
        ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_21_DISP_OSD_REFERENCE_DEN);
        ScalerSetByte(CM_2B_DISP_DATA_PORT, (g_stMDomainOutputData.usVStart - 4));  
        
        PDATA_WORD(0) = g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVBackHeight;        
    }

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_14_DISP_DV_BKGD_END_H);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[0]); 

    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_15_DISP_DV_BKGD_END_L);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[1]);         

    switch(ucMemorySel)
    {
        case _FRAME_SYNC_LINE_BUFFER:
            
            // Set DVTotal
            PDATA_WORD(0) = (DWORD)g_stMDomainInputData.usVTotal * (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight;

#if(_FREESYNC_SUPPORT == _ON)
            if(GET_FREESYNC_ENABLED() == _TRUE)
            {
                // DVtotal for free run setting
                PDATA_WORD(0) = _PANEL_DV_TOTAL_MAX;
            }
#endif

            ScalerSetBit(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(PDATA_WORD(0))) & 0x0F);
            ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, (LOBYTE(PDATA_WORD(0))));             
            
            // Set (DVTotal + 64) for Frame Sync Watch Dog
            PDATA_WORD(0) += 64;
            
            ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0B_DISP_DV_TOTAL_H);
            ScalerSetByte(CM_2B_DISP_DATA_PORT, (pData[0] & 0x0F)); 

            ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0C_DISP_DV_TOTAL_L);
            ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[1]);                         

            // Enable Display Timing
            ScalerSetBit(CM_28_VDISP_CTRL, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));
            
            // Calculate DClk for Frame Sync
            PDATA_DWORD(0) = (DWORD)(g_stMDomainOutputData.usHTotal) * (DWORD)g_stMDomainInputData.usHFreq * (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight / 10; 

            break;
            
        case _FRAME_SYNC_SDRAM:
        case _FREE_RUN_SDRAM:
        case _MN_FRAME_SYNC_SDRAM: 
            
#if(_FRC_SUPPORT == _ON)

            if((g_bDoubleFrame == _FALSE) && (ucMemorySel == _FREE_RUN_SDRAM) && 
                (g_stMDomainOutputData.usVHeight == _PANEL_DV_HEIGHT) && 
                (g_stMDomainInputData.usVFreq > _PANEL_MAX_FRAME_RATE))
            {
                PDATA_WORD(2) = ScalerFRCSetOneFrameDVTotal();
            }
            else if((g_bDoubleFrame == _FALSE) && (ucMemorySel == _FREE_RUN_SDRAM) &&
                    (((g_stMDomainOutputData.usVHeight < _PANEL_DV_HEIGHT) && (g_stMDomainInputData.usVFreq > _PANEL_MAX_FRAME_RATE)) || (g_stMDomainInputData.usVFreq < _PANEL_MIN_FRAME_RATE)))
            {
                PDATA_WORD(2) = _PANEL_DV_TOTAL_MIN;
            }
            else
            {
                PDATA_WORD(2) = _PANEL_DV_TOTAL;
            }
#endif // End of #if(_FRC_SUPPORT == _ON)

#if(_3D_SUPPORT == _ON)            
            if(GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT)
            {
                PDATA_WORD(2) = _PANEL_DV_TOTAL;
            }
            
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
            if((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) && (GET_MEMORY_DVF_SELECT() == _1_IVF))
            {
                // Set Max VTotal to avoid frame tear
                PDATA_WORD(2) = _PANEL_DV_TOTAL_MAX;
            }
#endif
#endif

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

            // Calculate and set display clock frequency for FRC mode
            PDATA_DWORD(0) = (DWORD)(g_stMDomainOutputData.usHTotal) * PDATA_WORD(2) * g_usDVFreq / 10000;

            if(ucMemorySel == _FRAME_SYNC_SDRAM)
            {        
                // Calculate DV_TOTAL setting for watchdog (Not Actual DVTotal)
                PDATA_WORD(2) += 64;

                ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0B_DISP_DV_TOTAL_H);
                ScalerSetByte(CM_2B_DISP_DATA_PORT, (pData[4] & 0x0F)); 

                ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0C_DISP_DV_TOTAL_L);
                ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[5]);  

                // Set (WD DVTotal + 1) for free run DVtotal
                PDATA_WORD(2) += 1;

#if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)
                ScalerSetByte(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, (((_LAST_LINE_TARGET - 4) >> 4) & 0xF0) | (pData[4] & 0x0F));
                ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, pData[5]);
                ScalerSetByte(P1_C9_EVEN_FIX_LASTLINE_LENGTH_L, LOBYTE((_LAST_LINE_TARGET - 4)));
#elif(_DISP_OUTPUT_PORT == _DISP_SINGLE_PORT)
                ScalerSetByte(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, (((_LAST_LINE_TARGET - 3) >> 4) & 0xF0) | (pData[4] & 0x0F));
                ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, pData[5]);
                ScalerSetByte(P1_C9_EVEN_FIX_LASTLINE_LENGTH_L, LOBYTE((_LAST_LINE_TARGET - 3)));
#endif                            
            }
            else
            {
#if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)
                ScalerSetByte(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, (((_LAST_LINE_TARGET - 4) >> 4) & 0xF0) | (pData[4] & 0x0F));
                ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, pData[5]);
                ScalerSetByte(P1_C9_EVEN_FIX_LASTLINE_LENGTH_L, LOBYTE((_LAST_LINE_TARGET - 4)));
#elif(_DISP_OUTPUT_PORT == _DISP_SINGLE_PORT)
                ScalerSetByte(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, (((_LAST_LINE_TARGET - 3) >> 4) & 0xF0) | (pData[4] & 0x0F));
                ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, pData[5]);
                ScalerSetByte(P1_C9_EVEN_FIX_LASTLINE_LENGTH_L, LOBYTE((_LAST_LINE_TARGET - 3)));
#endif
        
                // Calculate DV_TOTAL setting for watchdog (Not Actual DVTotal)
                PDATA_WORD(2) += 64;

                ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0B_DISP_DV_TOTAL_H);
                ScalerSetByte(CM_2B_DISP_DATA_PORT, (pData[4] & 0x0F)); 

                ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0C_DISP_DV_TOTAL_L);
                ScalerSetByte(CM_2B_DISP_DATA_PORT, pData[5]);             
            }
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

            break;

        case _FREE_RUN_NO_INPUT:            
                
            // Set Vtotal for Free Run
            ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0B_DISP_DV_TOTAL_H);
            ScalerSetByte(CM_2B_DISP_DATA_PORT, (HIBYTE(g_stMDomainOutputData.usVTotal) & 0x0F)); 

            ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_0C_DISP_DV_TOTAL_L);
            ScalerSetByte(CM_2B_DISP_DATA_PORT, LOBYTE(g_stMDomainOutputData.usVTotal));  
            
            // Enable Display Timing
            ScalerSetBit(CM_28_VDISP_CTRL, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));

            // Assign DClk
            PDATA_DWORD(0) = (DWORD)_PANEL_PIXEL_CLOCK * 1000;

            // Adjust DHTotal and DVTotal
#if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)            
            ScalerSetByte(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, ((((g_stMDomainOutputData.usHTotal - 4) >> 4) & 0xF0) | (HIBYTE(g_stMDomainOutputData.usVTotal) & 0x0F)));
            ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, LOBYTE(g_stMDomainOutputData.usVTotal));
            ScalerSetByte(P1_C9_EVEN_FIX_LASTLINE_LENGTH_L, LOBYTE(g_stMDomainOutputData.usHTotal - 4));
#elif(_DISP_OUTPUT_PORT == _DISP_SINGLE_PORT)
            ScalerSetByte(P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M, ((((g_stMDomainOutputData.usHTotal - 3) >> 4) & 0xF0) | (HIBYTE(g_stMDomainOutputData.usVTotal) & 0x0F)));
            ScalerSetByte(P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L, LOBYTE(g_stMDomainOutputData.usVTotal));
            ScalerSetByte(P1_C9_EVEN_FIX_LASTLINE_LENGTH_L, LOBYTE(g_stMDomainOutputData.usHTotal - 3));
#endif

            break;

        default:
            
            break;        
    }
        
    // If DClk Out of Panel Spec => Try Modifying DHTotal
    // DClk >= Panel Max with Max SSC (_DCLK_SPREAD_RANGE / 2 each Side plus 1 % margin)
    if(PDATA_DWORD(0) >= ((DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000 - _DCLK_SPREAD_RANGE * 5 / 2 - 10)))
    {
        // Calculate Target DHTotal
        PDATA_DWORD(1) = g_stMDomainOutputData.usHTotal * ((DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000 - _DCLK_SPREAD_RANGE * 5 / 2 - 10)) / PDATA_DWORD(0);
        
        // Make Sure DHTotal to be 4's multiple
        PDATA_DWORD(1) -= PDATA_DWORD(1) % 4;        

        if(PDATA_DWORD(1) < _PANEL_DH_TOTAL_MIN)
        {
            PDATA_DWORD(1) = _PANEL_DH_TOTAL_MIN;
        }          
            
        PDATA_DWORD(0) = PDATA_DWORD(0) * PDATA_DWORD(1) / g_stMDomainOutputData.usHTotal;
        g_stMDomainOutputData.usHTotal = PDATA_DWORD(1);                      
        
        DebugMessageScaler("D Clock Larger Than Panel Spec => Modify Htotal", PDATA_DWORD(1));        
    }
    else if(PDATA_DWORD(0) <= ((DWORD)_PANEL_PIXEL_CLOCK_MIN * (1000 + _DCLK_SPREAD_RANGE * 5 / 2 + 10))) // DClk <= Panel Min plus Max SSC (plus margin)
    {
        // Calculate Target DHTotal
        PDATA_DWORD(1) = g_stMDomainOutputData.usHTotal * ((DWORD)_PANEL_PIXEL_CLOCK_MIN * (1000 + _DCLK_SPREAD_RANGE * 5 / 2 + 10)) / PDATA_DWORD(0);
        
        // Make Sure DHTotal to be 4's multiple
        if(GET_MEMORY_SELECT() == _MN_FRAME_SYNC_SDRAM)
        {
            // Avoid Frame tracking (25Hz to 50Hz) set DVT too small.
            PDATA_DWORD(1) -= (PDATA_DWORD(1) % 4);
        }
        else
        {
            PDATA_DWORD(1) += (PDATA_DWORD(1) % 4);
        }

        if(PDATA_DWORD(1) > _PANEL_DH_TOTAL_MAX)
        {
            PDATA_DWORD(1) = _PANEL_DH_TOTAL_MAX;
        }

        if(GET_MEMORY_SELECT() == _MN_FRAME_SYNC_SDRAM)
        {
             PDATA_DWORD(0) = ((DWORD)_PANEL_PIXEL_CLOCK_MIN * (1000 + _DCLK_SPREAD_RANGE * 5 / 2 + 10));
        }
        else
        {
            PDATA_DWORD(0) = PDATA_DWORD(0) * PDATA_DWORD(1) / g_stMDomainOutputData.usHTotal;
        }

        g_stMDomainOutputData.usHTotal = PDATA_DWORD(1);                      
        
        DebugMessageScaler("D Clock Smaller Than Panel Spec => Modify Htotal", PDATA_DWORD(1));        
    }
    
     // DHtotal 
#if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)      
    ScalerSetDataPortBit(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_00_DISP_DH_TOTAL_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(g_stMDomainOutputData.usHTotal - 4) & 0x0F));   
    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, (LOBYTE(g_stMDomainOutputData.usHTotal - 4)));    
#elif(_DISP_OUTPUT_PORT == _DISP_SINGLE_PORT)
    ScalerSetDataPortBit(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_00_DISP_DH_TOTAL_H, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(g_stMDomainOutputData.usHTotal - 3) & 0x0F));   
    ScalerSetByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_01_DISP_DH_TOTAL_L);
    ScalerSetByte(CM_2B_DISP_DATA_PORT, (LOBYTE(g_stMDomainOutputData.usHTotal - 3)));    
#endif

    SET_D_CLK_FREQ(PDATA_DWORD(0));          
    
    // Set DClk
    ScalerPllSetDpllFreq(PDATA_DWORD(0));   
}

//--------------------------------------------------
// Description  : Decide which scaling function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerMDomainSetScaling(StructSDRAMDataInfo stFIFOScaling)
{
    CLR_H_SCALE_DOWN();
    CLR_H_SCALE_UP();
    CLR_V_SCALE_DOWN();
    CLR_V_SCALE_UP();

    // Disable I domain share display line buffer & MAC when vertical scale down
    ScalerSetBit(CM_33_SU_ACCESS_PORT, ~_BIT5, 0x00);  
    
    ScalerScalingSetScalingDown(stFIFOScaling);

    ScalerScalingSetScalingUp(stFIFOScaling);
}

//--------------------------------------------------
// Description  : Special Double Buffer Apply Procedure for FS
// Input Value  : None
// Output Value : None
// Note : Only for Frame Sync case
//--------------------------------------------------
void ScalerMDomainFSVgipDoubleBufferApply(void)
{
    bit bFreeRunEn = _FALSE;

    // Avoid (Current_IVSDelay + IVStart + IVHeight) > IVToal + New_IVSDelay
    PDATA_WORD(0) = (ScalerVgipGetCaptureVDelay() + ScalerVgipGetCaptureVStartPosition() + g_stMDomainInputData.usVHeight);
    bFreeRunEn = (PDATA_WORD(0) > g_stMDomainInputData.usVTotal) ? (_TRUE) : (_FALSE);
     
    if(bFreeRunEn == _TRUE)
    {
        ScalerTimerWaitForEvent(_EVENT_DEN_START);       

        // Set Free run
        ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT3, 0x00);
    }

    ScalerVgipDoubleBufferApply();

    if(bFreeRunEn == _TRUE)
    {
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

        // Set Frame sync
        ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT3, _BIT3);
    }        
}


//--------------------------------------------------
// Description  : Config
// Input Value  : 10*OD bit (6.5bit OD --> set 65)
// Output Value : None
//--------------------------------------------------
void ScalerMDomainMemoryConfig(void) 
{
    SET_MEMORY_CONFIG(_NO_SDRAM_WORK_MODE); // user decide work type

#if(_FRC_SUPPORT == _ON)

    // Calculate frame sync DVtotal
    PDATA_WORD(0) = (DWORD)g_stMDomainInputData.usVTotal * g_stMDomainOutputData.usVHeight / g_stMDomainInputData.usVHeight;

    if((g_stMDomainInputData.usVFreq < _PANEL_MIN_FRAME_RATE) || (g_stMDomainInputData.usVFreq > _PANEL_MAX_FRAME_RATE) || (g_stMDomainOutputData.usVBackHeight > g_stMDomainOutputData.usVHeight) || 
        (PDATA_WORD(0) > (_PANEL_DV_TOTAL_MAX - 2)) || (PDATA_WORD(0) < (_PANEL_DV_TOTAL_MIN + 2))) 
    {
        SET_MEMORY_CONFIG(_FRC_WORK_MODE); // user decide work type	
    }
#endif	
    
#if(_3D_SUPPORT == _ON)
    if(GET_3D_INPUT_FORMAT() != _NO_3D_FORMAT)
    {
        SET_MEMORY_CONFIG(_3D_WORK_MODE);        
    }
#endif

}

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable 
// Input Value  : 
// Output Value : None
//--------------------------------------------------
void ScalerMDomainAspectOriginMode(bit bOn)
{
    SET_ASPECT_ORIGIN_MODE(bOn);
}
#endif

#if(_OD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : If memory is not enough for OD, disable OD 
// Input Value  : Input timing for cal FRC and 3D memory size
// Output Value : None
//--------------------------------------------------
void ScalerMDomainODConfig(void)
{
    
#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))    
    WORD usMemorySpace = 0;
    WORD usMemoryBW = 0;   
#endif

    SET_OD_USE_BIT(_OFF);

    if(ScalerODGetCompressionBitNum() == 0x00)
    {
        return;
    }
     
    switch(GET_MEMORY_CONFIG())
    {
        case _NO_SDRAM_WORK_MODE:

            if((ScalerODCalculateMemoryUseSpace(ScalerODGetCompressionBitNum()) < _MEMORY_ROW) && 
               (((((DWORD)1000000 * _MEMORY_SPEED) / 10 * _MEMORY_EFFICIENCY) >> 20) > ScalerODCalculateMemoryUseBW(ScalerODGetCompressionBitNum())))
            {
                SET_OD_USE_BIT(ScalerODGetCompressionBitNum());    
            }
            
            break;
            
#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
#if(_FRC_SUPPORT == _ON)
        case _FRC_WORK_MODE:
#endif
#if(_3D_SUPPORT == _ON)
        case _3D_WORK_MODE:
#endif

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
            if(GET_ASPECT_ORIGIN_MODE() == _TRUE)
            {
                PDATA_WORD(0) = g_stMDomainOutputData.usVHeight;
            }
            else
#endif
            {
                PDATA_WORD(0) = ((g_stMDomainInputData.usVHeight > _PANEL_DV_HEIGHT) ? (_PANEL_DV_HEIGHT) : (g_stMDomainInputData.usVHeight));  
            }

#if(_FRC_SUPPORT == _ON)
            if(GET_MEMORY_CONFIG() == _FRC_WORK_MODE)
            {
                usMemorySpace = ScalerMDomainGetFRCMemorySpace(PDATA_WORD(0), g_stMDomainInputData.usHWidth);
                usMemoryBW = ScalerMDomainGetFRCMemoryBW(g_stMDomainInputData.usVFreq, g_stMDomainInputData.usHWidth);
            }
#endif

#if(_3D_SUPPORT == _ON)
            if(GET_MEMORY_CONFIG() == _3D_WORK_MODE)
            {
                usMemorySpace = ScalerMDomainGet3DMemorySpace(PDATA_WORD(0), g_stMDomainInputData.usHWidth);
                usMemoryBW = ScalerMDomainGet3DMemoryBW();
            }
#endif

            if((((DWORD)usMemorySpace * _SDRAM_ACCEPTABLE_HSD_RATIO / 100) < _MEMORY_ROW) && 
               (((((DWORD)1000000 * _MEMORY_SPEED) / 10 * _MEMORY_EFFICIENCY) >> 20) > ((DWORD)usMemoryBW * _SDRAM_ACCEPTABLE_HSD_RATIO / 100)))
            {
                switch(GET_MEMORY_DVF_SELECT())
                {
                    case _3_IVF:
                    case _2_5_IVF:
                        
                        // Used HW auto 3 block toggle.
                        if((((WORD)_MEMORY_ROW * 2 / 3 - ((DWORD)usMemorySpace * _SDRAM_ACCEPTABLE_HSD_RATIO / 100)) > ScalerODCalculateMemoryUseSpace(ScalerODGetCompressionBitNum())) &&
                            ((((((DWORD)1000000 * _MEMORY_SPEED) / 10 * _MEMORY_EFFICIENCY) >> 20) - ((DWORD)usMemoryBW * _SDRAM_ACCEPTABLE_HSD_RATIO / 100)) > ScalerODCalculateMemoryUseBW(ScalerODGetCompressionBitNum())))
                        {
                            
#if(_3D_SUPPORT == _ON)
                            if((GET_3D_INPUT_FORMAT() == _FRAME_PACKING) || 
                               (GET_3D_INPUT_FORMAT() == _TOP_AND_BOTTOM) ||
                               ((GET_3D_INPUT_FORMAT() == _FRAME_SEQUENTIAL) && (GET_3D_OUTPUT_SEQUENCE() != _3D_DISPLAY_2D)))
                            {
                                // Calculate OD size
                                PDATA_WORD(0) = ScalerODCalculateMemoryUseSpace(ScalerODGetCompressionBitNum());
                                
                                // OD use R image size, so OD size < R image size.
                                if(((DWORD)usMemorySpace * _SDRAM_ACCEPTABLE_HSD_RATIO / 100) > (PDATA_WORD(0) * 2))
                                {
                                    SET_OD_USE_BIT(ScalerODGetCompressionBitNum());
                                }
                            }
                            else
#endif
                            {
                                SET_OD_USE_BIT(ScalerODGetCompressionBitNum());
                            }

                        }
                        
                        break;

                    default:
                        
                        if(((_MEMORY_ROW - ((DWORD)usMemorySpace * _SDRAM_ACCEPTABLE_HSD_RATIO / 100)) > ScalerODCalculateMemoryUseSpace(ScalerODGetCompressionBitNum())) &&
                            ((((((DWORD)1000000 * _MEMORY_SPEED) / 10 * _MEMORY_EFFICIENCY) >> 20) - ((DWORD)usMemoryBW * _SDRAM_ACCEPTABLE_HSD_RATIO / 100)) > ScalerODCalculateMemoryUseBW(ScalerODGetCompressionBitNum())))
                        {
                            SET_OD_USE_BIT(ScalerODGetCompressionBitNum());    
                        }
                        
                    break;
                }
            }
            
            break;
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

        default:

            break;
    }

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
    ScalerMDomainCalMemoryUseSpaceBW(); 
#endif

}

#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Calculate FRC use memory space
// Input Value  : IVheight and IHwidth
// Output Value : FRC use memory space, unit: row
//--------------------------------------------------
WORD ScalerMDomainGetFRCMemorySpace(WORD usIVheight, WORD usIHwidth)
{
    WORD usMemoryFRCSpace = 0;

    //***************************************************//
    // Column = Column_per_bank * memory_bank
    // Row = Total memory unit / column    
    //***************************************************//
    
    usMemoryFRCSpace = ((DWORD)usIVheight * usIHwidth * _BIT_PER_PIXEL * 10 / _MEMORY_BIT_NUM / (_MEMORY_COL_PER_BANK * _MEMORY_BANK)); // 10*row
    usMemoryFRCSpace = (usMemoryFRCSpace % 10) ? (usMemoryFRCSpace / 10 + 1) : (usMemoryFRCSpace / 10); // unit:row  

    return usMemoryFRCSpace;
}

//--------------------------------------------------
// Description  : Calculate FRC use memory BW
// Input Value  : IVF, IVheight and IHwidth
// Output Value : FRC use memory BW, unit: 100k
//--------------------------------------------------
WORD ScalerMDomainGetFRCMemoryBW(WORD usIVF, WORD usIHwidth)
{
    DWORD ulMemoryFRCBW = 0;  
    
    ulMemoryFRCBW = _PANEL_DH_WIDTH * 10 / GET_INPUT_TIMING_HWIDTH();
    ulMemoryFRCBW = (ulMemoryFRCBW <= 13) ? (ulMemoryFRCBW) : (10);

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    if((GET_ASPECT_ORIGIN_MODE() == _TRUE) && (GET_INPUT_TIMING_HWIDTH() == 1920) && (GET_INPUT_TIMING_VHEIGHT() == 540))
    {
        // 1080i
       ulMemoryFRCBW = ((((DWORD)g_stMDomainInputData.usVTotal * usIHwidth /_MEMORY_BUS_WIDTH * _BIT_PER_PIXEL * ((usIVF * 20 + g_usDVFreq * ulMemoryFRCBW) / 10))) >> 10);
    }
    else
#endif                    
    {
        ulMemoryFRCBW = ((((DWORD)g_stMDomainInputData.usVTotal * usIHwidth /_MEMORY_BUS_WIDTH * _BIT_PER_PIXEL * (usIVF + (g_usDVFreq * ulMemoryFRCBW / 10)))) >> 10);
    }

    ulMemoryFRCBW = (ulMemoryFRCBW >> 10) + ((ulMemoryFRCBW % 1024) ? 1 : 0); // unit:100k    

    return (ulMemoryFRCBW & 0xFFFF);
}

#endif // #if(_FRC_SUPPORT == _ON)

#if(_3D_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Calculate FRC use memory space
// Input Value  : IVheight and IHwidth
// Output Value : FRC use memory space, unit: row
//--------------------------------------------------
WORD ScalerMDomainGet3DMemorySpace(WORD usIVheight, WORD usIHwidth)
{
    WORD usMemory3DSpace = 0;

    //***************************************************//
    // Column = Column_per_bank * memory_bank
    // Row = Total memory unit / column    
    //***************************************************//
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
    if(GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF)
    {
        usMemory3DSpace = ((DWORD)usIVheight * (usIHwidth / 2) * _BIT_PER_PIXEL * 10 / _MEMORY_BIT_NUM / (_MEMORY_COL_PER_BANK * _MEMORY_BANK)); // 10*row
    }
    else
#elif(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
    if((GET_MEMORY_DVF_SELECT() == _1_IVF) && (GET_3D_INPUT_FORMAT() == _SIDE_BY_SIDE_HALF))
    {
        usMemory3DSpace = ((DWORD)usIVheight * (usIHwidth / 2) * _BIT_PER_PIXEL * 10 / _MEMORY_BIT_NUM / (_MEMORY_COL_PER_BANK * _MEMORY_BANK)); // 10*row
    }
    else
#endif
    {
        usMemory3DSpace = ((DWORD)usIVheight * usIHwidth * _BIT_PER_PIXEL * 10 / _MEMORY_BIT_NUM / (_MEMORY_COL_PER_BANK * _MEMORY_BANK)); // 10*row
    }

    usMemory3DSpace = (usMemory3DSpace % 10) ? (usMemory3DSpace / 10 + 1) : (usMemory3DSpace / 10); // unit:row 
    
    return usMemory3DSpace;
}

//--------------------------------------------------
// Description  : Calculate FRC use memory BW
// Input Value  : IVF, IVheight and IHwidth
// Output Value : FRC use memory BW, unit: 100k
//--------------------------------------------------
WORD ScalerMDomainGet3DMemoryBW(void)
{
    DWORD usMemory3DBW = 0;    

    usMemory3DBW = _PANEL_DH_WIDTH * 10 / GET_INPUT_TIMING_HWIDTH();
    usMemory3DBW = (usMemory3DBW <= 13) ? (usMemory3DBW) : (10);

    if(GET_3D_INPUT_FORMAT() == _FRAME_PACKING)
    {
        
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
        if(GET_3D_OUTPUT_SEQUENCE() == _3D_DISPLAY_2D)
        {
            usMemory3DBW = (((DWORD)g_stMDomainInputData.usVTotal * g_stMDomainInputData.usHWidth * (g_stMDomainInputData.usVFreq * 15 + ((DWORD)g_usDVFreq / 2 * usMemory3DBW))) >> 10) * _BIT_PER_PIXEL / _MEMORY_BUS_WIDTH;
        }
        else
#endif
        {
            usMemory3DBW = (((DWORD)g_stMDomainInputData.usVTotal * g_stMDomainInputData.usHWidth * (g_stMDomainInputData.usVFreq + ((DWORD)g_usDVFreq / 2 * usMemory3DBW / 10))) >> 10) * _BIT_PER_PIXEL / _MEMORY_BUS_WIDTH;
        }

    }
    else
    {
        usMemory3DBW = (((DWORD)g_stMDomainInputData.usVTotal * g_stMDomainInputData.usHWidth * (g_stMDomainInputData.usVFreq + ((DWORD)g_usDVFreq * usMemory3DBW / 10))) >> 10) * _BIT_PER_PIXEL / _MEMORY_BUS_WIDTH;
    }

    usMemory3DBW = (usMemory3DBW >> 10) + ((usMemory3DBW % 1024) ? 1 : 0); // unit:100k    
    
    return (usMemory3DBW & 0xFFFF);
}
#endif // End of #if(_3D_SUPPORT == _ON)

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Calculate memory use BW 
// Input Value  : OD use bit(10x)
// Output Value : None
//--------------------------------------------------
void ScalerMDomainCalMemoryUseSpaceBW(void)
{
    SET_OD_USE_SPACE(_OFF);
    SET_OD_USE_BW(_OFF);    

    if(GET_OD_USE_BIT() != _OFF)
    {
        SET_OD_USE_SPACE(ScalerODCalculateMemoryUseSpace(GET_OD_USE_BIT()));
        SET_OD_USE_BW(ScalerODCalculateMemoryUseBW(GET_OD_USE_BIT()));    
    }
}
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
#endif // End of #if(_OD_SUPPORT == _ON) 


