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
// ID Code      : RL6297_Series_VGIP_Interface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerVgipModifyPolarity(BYTE ucSourceType);

#if(_VGA_SUPPORT == _ON)
extern void ScalerVgipModifyVsLatchEdge(bit bWait);
#endif

extern WORD ScalerVgipGetCaptureVStartPosition(void);
extern WORD ScalerVgipGetCaptureVHeight(void);
extern WORD ScalerVgipGetCaptureVDelay(void);
extern void ScalerVgipSetCaptureVDelay(WORD usIVSDelay);
extern WORD ScalerVgipGetCaptureHStartPosition(void);
extern void ScalerVgipSetCaptureHDelay(WORD usIHSDelay);
extern WORD ScalerVgipGetCaptureHDelay(void);
extern WORD ScalerVgipGetCaptureHWidth(void);
extern void ScalerVgipDoubleBufferApply(void);
extern void ScalerVgipDoubleBufferEnable(bit bEn);