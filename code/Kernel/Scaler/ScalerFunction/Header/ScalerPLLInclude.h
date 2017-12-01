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
// ID Code      : ScalerPLLInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of APLL VCO Divider Threshold
//--------------------------------------------------
#define _APLL_VCO_DEVIDER_4_2_THERSHOLD             100000

//--------------------------------------------------
// Definitions of difference between measurement edge phase and calculation by mode edge phase
//--------------------------------------------------
#define _PHASE_DELAY_EDGEPHASE_THRESHOLD            2


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __SCALER_PLL__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
extern WORD g_usPhaseDelayTime;
#endif


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

#endif // End of #ifndef __SCALER_PLL__