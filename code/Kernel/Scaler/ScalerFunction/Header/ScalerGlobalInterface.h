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
// ID Code      : ScalerGlobalInterface.h No.0000
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
extern void ScalerGlobalWholeChipReset(void);
extern void ScalerGlobalHostControlMode(EnumPowerStatus enumPorStatus);
extern void ScalerGlobalWatchDog(bit bEnable);
extern void ScalerGlobalFirstActiveProc(BYTE ucSourceType);
extern void ScalerGlobalCrystalClkSel(bit bSel);
extern void ScalerGlobalResetProc(BYTE ucResetTarget);
extern BYTE ScalerGlobalGetIRQControl(void);
extern void ScalerGlobalSetIRQControl(BYTE ucIRQControl);
extern void ScalerGlobalIRQControl(bit bEn);
extern void ScalerGlobalOsdInitial(void);

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)
extern void ScalerGlobalPreventGarbageByBacklight_EXINT0(void);
#endif

#if(_EFFUSE_FUNCTION_SUPPORT == _ON)
extern void ScalerGlobalEffuseInitial(void);
#endif
