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
// ID Code      : RL6373_Series_SLP_Interface.h No.0000
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
extern bit ScalerSLPPC99PowerDetect(void);
extern void ScalerSLPVcckoffRelease(void);
extern bit ScalerSLPPowerKeyHit();
extern BYTE ScalerSarAdcCodeValue(void);
extern bit ScalerSLPCableDetectHit(void);
extern void ScalerSLPLedLevelMode(bit ucLedStatus);
extern void ScalerSLPLedCounterMode(void);

#if(_SUPER_LOW_POWER_SUPPORT == _ON)
extern void ScalerSLPSystemInitial(void);
extern void ScalerSLPPSFlagClear(void);
extern void ScalerSLPPDFlagClear(void);
extern void ScalerSLPPowerStatus(EnumPowerStatus enumPorStatus);
extern bit ScalerSLPV33OffStatus(void);
extern bit ScalerSLPVcckOffStatus(void);
extern void ScalerSLPVSetSwrEn(bit ucSwrStatus);
extern bit ScalerSLPVSetSwrEnStatus(void);
extern BYTE ScalerSLPWakeUpStatus(void);
extern void ScalerSLPFilterKeyEvent(void);
#endif