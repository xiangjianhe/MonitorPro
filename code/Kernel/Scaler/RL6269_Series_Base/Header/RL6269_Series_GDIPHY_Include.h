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
// ID Code      : RL6269_Series_GDIPHY_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of GDI Clk Freq. (in kHz)
//--------------------------------------------------
#define _GDI_CLK_KHZ                                (DWORD)(_M2PLL_CLK_KHZ / _SYS_CLK_DIV)    // in kHz

//--------------------------------------------------
// Macros of Z0 Disconnection for MHL
//--------------------------------------------------
#define GET_MHL_2D_SWITCH()                         (bMHL2DSwitch)
#define SET_MHL_2D_SWITCH()                         (bMHL2DSwitch = _TRUE)
#define CLR_MHL_2D_SWITCH()                         (bMHL2DSwitch = _FALSE)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __RL6269_SERIES_GDIPHY__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern bit bMHL2DSwitch;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_DIGITAL_PORT_SUPPORT == _ON)
extern void ScalerGDIDigitalPhySwitch(BYTE ucInputPortType);
extern void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bPort1);
extern void ScalerGDIPhy2DSwitch(BYTE ucPortSelect);
extern void ScalerGDIPhyPowerSavingProc(void);
extern void ScalerGDIPhyPowerOffProc(void);
extern void ScalerGDIBandgap(bit bSelect);
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
#endif // End of #ifndef __RL6269_SERIES_GDIPHY__
