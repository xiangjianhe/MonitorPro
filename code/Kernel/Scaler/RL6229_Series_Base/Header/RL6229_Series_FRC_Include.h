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
// ID Code      : RL6229_Series_FRC_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of FRC address
//--------------------------------------------------
#define _FRC_1ST_BLOCK_STA_ADDR                     0x000000
#if(_MEMORY_SIZE < _MEMORY_64MB)
#define _FRC_2ND_BLOCK_STA_ADDR                     0x200000
#else
#define _FRC_2ND_BLOCK_STA_ADDR                     0x400000
#endif

//--------------------------------------------------
// Definitions of OD FRC Double buffer ready time
//--------------------------------------------------
#define _SDRAM_DISPLAY_SETTING_READY_TIME    	    (50)

// MN auto block toggle: HW apply in DVS of Frame Sync.
// 24 to 60 (2:5): 24Hz = 41.6 ms/frame. 41.6*2 = 83.2 ~= 84 ms
#define _M_N_AUTO_BLK_TOGGLE_STABLE_TIME    	    (100)


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __RL6229_SERIES_FRC__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

#if(_FRC_SUPPORT == _ON)
extern void ScalerFRCControl(WORD usHorSize, WORD usVerSize);
extern void ScalerFRCAdjustIVS2DVSDelay(void);
extern void ScalerFRCCompareIHFandDHF(void);
extern void ScalerFRCOneFrameCtrl(DWORD ulIHF, DWORD ulDHF);
extern WORD ScalerFRCSetOneFrameDVTotal(void);
#endif 

#endif // End of #ifndef __RL6229_SERIES_FRC__