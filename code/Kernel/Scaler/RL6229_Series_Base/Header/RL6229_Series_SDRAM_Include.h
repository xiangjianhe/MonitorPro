/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6229_Series_SDRAM_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Memory Efficiency
//--------------------------------------------------
#define _MEMORY_EFFICIENCY                          86

//--------------------------------------------------
// Data Bit
//--------------------------------------------------
#define _BIT_PER_PIXEL                              24

//--------------------------------------------------
// Memory Speed 
//--------------------------------------------------
#if(_SDRAM_SIZE_CONFIG == _2M_32BIT)
#define _MEMORY_SPEED                               _MEMORY_SPEED_220MHZ
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)  
#define _MEMORY_SPEED                               _MEMORY_SPEED_198MHZ
#else
#define _MEMORY_SPEED                               _MEMORY_SPEED_198MHZ
#endif

#define _SDRAM_ACCESS_WRITE_LENGTH                  (0xA0)
#define _SDRAM_ACCESS_READ_LENGTH                   (0xFC)

//--------------------------------------------------
// Memory Size
//--------------------------------------------------
#define _MEMORY_COL_PER_BANK                        256
#define _MEMORY_ROW                                 2048

#if(_SDRAM_SIZE_CONFIG == _NO_MEMORY)
#define _MEMORY_BUS_WIDTH                           0
#define _MEMORY_SIZE                                0
#define _MEMORY_BIT_NUM                             0
#define _MEMORY_BANK                                0
#elif(_SDRAM_SIZE_CONFIG == _1M_16BIT)
#define _MEMORY_BUS_WIDTH                           16
#define _MEMORY_SIZE                                _MEMORY_16MB
#define _MEMORY_BIT_NUM                             16
#define _MEMORY_BANK                                2
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT)
#define _MEMORY_BUS_WIDTH                           32
#define _MEMORY_SIZE                                _MEMORY_32MB
#define _MEMORY_BIT_NUM                             32
#define _MEMORY_BANK                                2
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
#define _MEMORY_BUS_WIDTH                           32
#define _MEMORY_SIZE                                _MEMORY_64MB
#define _MEMORY_BIT_NUM                             32
#define _MEMORY_BANK                                4
#endif

//--------------------------------------------------
// SDRAM golden phase
//--------------------------------------------------
#if(_SDRAM_SIZE_CONFIG == _1M_16BIT)
#define _SDR_CAS_LATN                               (0x25)
#define _SDR_CLK_DLY1                               (0x00)
#define _SDR_CLK_DLY2                               (0x12)
#define _SDR_DQS_DLY                                (0x1A)
#elif(_SDRAM_SIZE_CONFIG == _1M_32BIT) 
#define _SDR_CAS_LATN                               (0x65) 
#define _SDR_CLK_DLY1                               (0x00) 
#define _SDR_CLK_DLY2                               (0x0A) 
#define _SDR_DQS_DLY                                (0x14) 
#elif(_SDRAM_SIZE_CONFIG == _2M_32BIT)
#define _SDR_CAS_LATN                               (0x85)
#define _SDR_CLK_DLY1                               (0x00)
#define _SDR_CLK_DLY2                               (0x0E)
#define _SDR_DQS_DLY                                (0x17)
#else
#warning "You must set sdram golden phase value there."
#endif

#define GET_FIRST_AUTOK_STATUS()                    (g_stSDRAMCtrl.b1FirstAutoKStatus)
#define SET_FIRST_AUTOK_STATUS(x)                   (g_stSDRAMCtrl.b1FirstAutoKStatus = (x))

#define GET_CAS_CHANGE_STATUS()                     (g_stSDRAMCtrl.b1CasChangeStatus)
#define SET_CAS_CHANGE_STATUS(x)                    (g_stSDRAMCtrl.b1CasChangeStatus = (x))

#define GET_DCON_ONLINE_STATUS()                    (g_stSDRAMCtrl.b1DCOnOnLineStatus)
#define SET_DCON_ONLINE_STATUS(x)                   (g_stSDRAMCtrl.b1DCOnOnLineStatus = (x))

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    WORD usLineStep;
    DWORD ulBlockStep;
} StructSDRAMLineBlockStep;

#ifndef __RL6229_SERIES_SDRAM__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if((_SDRAM_PHASE_CALIBRATION == _ON) || (_OD_SUPPORT == _ON))
extern DWORD g_ulSdrThreeBlockAddr1;

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
extern DWORD g_ulSdrThreeBlockAddr2;
extern DWORD g_ulSdrThreeBlockAddr3;
#endif
#endif

#if(_SDRAM_PHASE_CALIBRATION == _ON)
extern BYTE g_ucPhaseCycle; 
extern BYTE g_ucPhaseCntCheck; 
extern StructSDRAMCalControl g_stSDRAMCtrl;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerSDRAMInitialTable(void);

#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
extern void ScalerSDRAMReset(void);
extern DWORD ScalerSDRAMAddressConversion(DWORD ulTotalSize);

#if(_SDRAM_PHASE_CALIBRATION == _ON)		  
extern void ScalerSDRAMPhaseOnLineTimer();
extern void ScalerSDRAMPhaseCntCheck(BYTE ucCheckTime);
extern bit ScalerSDRAMPhaseOnLine(DWORD ulAddress);	 
#endif

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
extern StructSDRAMLineBlockStep ScalerSDRAMCalculateLineStepAndBlockStep(WORD usHorSize, WORD usVerSize);
extern void ScalerSDRAMSetFrameTrackingEnable(bit bEn);
extern void ScalerSDRAMFrameTracking(void);
extern void ScalerSDRAMSetDisplayAutoBlkToggleEnable(bit bEn);
extern void ScalerSDRAMSetHWAutoBlockToggle(void);
extern WORD ScalerSDRAMGetMNRatio(void);

#if((_OD_SUPPORT == _ON) || (_SDRAM_PHASE_CALIBRATION == _ON))
extern void ScalerSDRAMCalculateODThreeBlockAddress(DWORD ulBlockStep);
extern void ScalerSDRAMSetODThreeBlockAddress(void);
#endif

#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON) || (_OD_SUPPORT == _ON))
extern DWORD ScalerSDRAMCalculateNumberAndRemain(DWORD ulTotalSize, BYTE ucLength, bit bDummy);
#endif

#if(_3D_SUPPORT == _ON)
extern WORD ScalerSDRAMCalculateLineSizeAlignToRow(WORD usHWidth, bit bUpBound);
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON) || (_OD_SUPPORT == _ON))

#endif

#endif // End of #ifndef __RL6229_SERIES_SDRAM__

