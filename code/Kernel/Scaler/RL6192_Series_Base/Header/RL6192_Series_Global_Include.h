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
// ID Code      : RL6192_Series_Global_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of System Clock Frequency
//--------------------------------------------------
#define _SYS_CLK_DIV                                (ScalerGetBit(CM_22_FIFO_FREQUENCY, (_BIT6 | _BIT5  | _BIT4  | _BIT3)) >> 3) // System Clock Divider   
#define _SYS_USE_ISO_CLK                            ((bit)ScalerGetBit(CM_09_POWER_CTRL0, _BIT3) ? _TRUE : _FALSE)
#define _SYS_CLK_KHZ                                (DWORD)((bit)ScalerGetBit(CM_22_FIFO_FREQUENCY, _BIT2) ? (((DWORD)1000 * _M2PLL_CLK_MHZ ) / _SYS_CLK_DIV) : (_SYS_USE_ISO_CLK ? _INTERNAL_OSC_XTAL : _EXT_XTAL))

//--------------------------------------------------
// Definitions Of Two frame times
//--------------------------------------------------
#define _WAIT_TWO_FRAME_TIME                        90 // Reference 24 Hz, (1/24) * 2 = 83ms, give 7ms tolerance

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
