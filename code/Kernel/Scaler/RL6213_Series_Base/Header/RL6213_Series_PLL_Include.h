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
// ID Code      : RL6213_Series_PLL_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of M2PLL Clock Frequency Paramater
//--------------------------------------------------
#if(_EXT_XTAL == _XTAL14318K)
#define _M2PLL_PLL_M                                (66 + 2) // Page1 0xE0[7:0] default value = 0x49
#define _M2PLL_PLL_N                                (0 + 2)  // Page1 0xE1[3:0] default value = 0x0
#elif(_EXT_XTAL == _XTAL27000K)                     
#define _M2PLL_PLL_M                                (38 + 2) // Page1 0xE0[7:0] default value = 0x26
#define _M2PLL_PLL_N                                (0 + 2)  // Page1 0xE1[3:0] default value = 0x0
#else                                               
# Setting Error~!                                   
#endif                                              
                                                    
#define _M2PLL_PLL_O                                2        // Page1 0xE1[5:4] default value = 0x1
#define _DWORD_DIMENSION                            1UL
#define _M2PLL_CLK_KHZ                              (((_DWORD_DIMENSION * _EXT_XTAL * _M2PLL_PLL_M) + ((_DWORD_DIMENSION * _M2PLL_PLL_N * _M2PLL_PLL_O) / 2)) / (_DWORD_DIMENSION * _M2PLL_PLL_N * _M2PLL_PLL_O))
#define _M2PLL_CLK_MHZ                              (((_DWORD_DIMENSION * _EXT_XTAL * _M2PLL_PLL_M) + ((_DWORD_DIMENSION * _M2PLL_PLL_N * _M2PLL_PLL_O * 1000) / 2)) / (_DWORD_DIMENSION * _M2PLL_PLL_N * _M2PLL_PLL_O * 1000))


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __RL6213_SERIES_PLL__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerPllSetDpllSsc(bit bDclkSpreadSpeed, BYTE ucSpreadRange);
extern void ScalerPllSetDpllFreq(DWORD ulFreq);
extern void ScalerDPLLFineTuneFrameSync(void);

#if(_VGA_SUPPORT == _ON)
extern bit ScalerAPLLAdjust(WORD usCurrHTotal, WORD usCurrHFreq);
extern WORD ScalerAPLLGetIHTotal(void);
#endif


#endif // End of #ifndef __RL6213_SERIES_PLL__

