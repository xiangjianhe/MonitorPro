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
// ID Code      : RL6192_Series_Memory_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#define _LINE_BUFFER_SIZE                           1920    // unit: 3Bytes
#define _FIFO_SIZE                                  1952    // unit: 3Bytes


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __RL6192_SERIES_MEMORY__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerMemorySetUpLineBuffer(void);
extern void ScalerMemorySetFIFOFreq(EnumScalerFIFOFreq enFIFOFreq);
extern void ScalerMemoryInitial(void);
extern void ScalerMemoryCompensateDtForLastLine(DWORD ulTargetLastLine, DWORD ulCurrentLastLine);
extern void ScalerMemoryFrameSyncSetDt(void);
extern void ScalerMemorySetFifoCapture(WORD usHWidth, WORD usVHeight);

#endif // End of #ifndef __RL6192_SERIES_MEMORY__