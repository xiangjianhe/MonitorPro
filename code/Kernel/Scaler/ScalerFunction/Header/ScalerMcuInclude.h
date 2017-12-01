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
// ID Code      : ScalerMcuInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Macros of 5us Delay
//--------------------------------------------------
#define Delay5us(N)                                  {\
                                                         g_ucDelay5usI = N;      \
                                                         while(--g_ucDelay5usI); \
                                                     }

//--------------------------------------------------
// Macros of SW IIC Status
//--------------------------------------------------
#if(_SW_IIC_SUPPORT == _ON)
#define GET_SW_IIC_STATUS()                          (g_ucSwIICStatus)
#define SET_SW_IIC_STATUS(x)                         (g_ucSwIICStatus = (x))
#endif


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __SCALER_MCU__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

extern BYTE data g_ucDelay5usN;
extern BYTE data g_ucDelay5usI;

#if(_SW_IIC_SUPPORT == _ON)
extern BYTE idata g_ucSwIICStatus;
#endif


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerMcuDdcDebounceSel(EnumClkSel enumClock);
extern void ScalerMcuFlashClockDiv(EnumFlashClkDiv enumClkDiv);
extern void ScalerMcuClockDiv(EnumMcuClkDiv enumClkDiv);

#if(_SW_IIC_SUPPORT == _ON)
extern bit ScalerMcuIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE *pReadArray);
extern bit ScalerMcuIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE * pWriteArray);
#endif

#if(_HW_IIC_SUPPORT == _ON)
extern bit ScalerMcuHwIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pReadArray, BYTE ucHwIICPinNum);
extern bit ScalerMcuHwIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pWriteArray, BYTE ucHwIICPinNum);
#endif

#endif // End of #ifndef __SCALER_MCU__