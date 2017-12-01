/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2012>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : ScalerFunctionInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "Project_List.h"
#include "Pcb_List.h"

#if(_SCALER_TYPE == _RL6001_SERIES)
#include "RL6001_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6096_SERIES)
#include "RL6096_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6229_SERIES)
#include "RL6229_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6213_SERIES)
#include "RL6213_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6230_SERIES)
#include "RL6230_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6192_SERIES)
#include "RL6192_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6297_SERIES)
#include "RL6297_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6269_SERIES)
#include "RL6269_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6316_SERIES)
#include "RL6316_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6336_SERIES)
#include "RL6336_Series_ScalerInclude.h"
#elif(_SCALER_TYPE == _RL6373_SERIES)
#include "RL6373_Series_ScalerInclude.h"
#endif

#include "ScalerDebugInclude.h"
#include "ScalerPowerInclude.h"
#include "ScalerIOSCInclude.h"
#include "ScalerMcuInclude.h"
#include "ScalerTimerFunctionInclude.h"
#include "ScalerGlobalInclude.h"
#include "ScalerSDRAMInclude.h"
#include "ScalerSyncInclude.h"
#include "ScalerMeasureInclude.h"
#include "ScalerIDomainInclude.h"
#include "ScalerMDomainInclude.h"
#include "ScalerDDomainInclude.h"
#include "ScalerPLLInclude.h"
#include "ScalerAudioInclude.h"
#include "ScalerColorInclude.h"
