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
// ID Code      : RL6001_Series_SDRAM_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Memory Efficiency
//--------------------------------------------------
#define _MEMORY_EFFICIENCY                          81

//--------------------------------------------------
// Data Bit
//--------------------------------------------------
#define _BIT_PER_PIXEL                              24


//--------------------------------------------------
// Memory Speed 
//--------------------------------------------------
#define _MEMORY_SPEED                               _MEMORY_SPEED_198MHZ

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


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    WORD usLineStep;
    DWORD ulBlockStep;
} StructSDRAMLineBlockStep;

#ifndef __RL6001_SERIES_SDRAM__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerSDRAMInitialTable(void);
#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
extern void ScalerSDRAMReset(void);
extern DWORD ScalerSDRAMAddressConversion(DWORD ulTotalSize);

#if((_FRC_SUPPORT == _ON) || (_OD_SUPPORT == _ON))
extern DWORD ScalerSDRAMCalculateNumberAndRemain(DWORD ulTotalSize, BYTE ucLength, bit bDummy);
#endif

#endif

#endif // End of #ifndef __RL6001_SERIES_SDRAM__

