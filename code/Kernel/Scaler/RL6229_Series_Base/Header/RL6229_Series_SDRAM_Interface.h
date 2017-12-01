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
// ID Code      : RL6229_Series_SDRAM_Interface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_SDRAM_PHASE_CALIBRATION == _ON)
#define GET_FIRST_AUTOK_STATUS()               (g_stSDRAMCtrl.b1FirstAutoKStatus)
#define SET_FIRST_AUTOK_STATUS(x)              (g_stSDRAMCtrl.b1FirstAutoKStatus = (x))

#define GET_CAS_CHANGE_STATUS()                (g_stSDRAMCtrl.b1CasChangeStatus)
#define SET_CAS_CHANGE_STATUS(x)               (g_stSDRAMCtrl.b1CasChangeStatus = (x))

#define GET_DCON_ONLINE_STATUS()               (g_stSDRAMCtrl.b1DCOnOnLineStatus)
#define SET_DCON_ONLINE_STATUS(x)              (g_stSDRAMCtrl.b1DCOnOnLineStatus = (x))
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_SDRAM_PHASE_CALIBRATION == _ON)
extern StructSDRAMCalControl g_stSDRAMCtrl;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_SDRAM_SIZE_CONFIG != _NO_MEMORY)
extern void ScalerSDRAMPowerControl(bit bOn);

#if(_SDRAM_PHASE_CALIBRATION == _ON)
extern void ScalerSDRAMPhaseSearch(void);	
extern bit ScalerSDRAMPhaseDCOnCheck(DWORD ulAddress);
#endif

#endif
