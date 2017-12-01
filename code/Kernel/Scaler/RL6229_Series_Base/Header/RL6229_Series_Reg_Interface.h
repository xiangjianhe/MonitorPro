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
// ID Code      : RL6229_Series_Reg_Interface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
#define ScalerSetBit(pucAddr, ucAnd, ucOr)          (*((volatile BYTE xdata *)(pucAddr)) = (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd)) | (ucOr))
#define ScalerGetBit(pucAddr, ucAnd)                (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd))
#define ScalerGetByte(pucAddr)                      (*((volatile BYTE xdata *)(pucAddr)))
#define ScalerSetByte(pucAddr, ucValue)             (*((volatile BYTE xdata *)(pucAddr)) = (ucValue))
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
