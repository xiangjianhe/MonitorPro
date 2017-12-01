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
// ID Code      : ScalerFunctionInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_SCALER_TYPE == _RL6001_SERIES)
#include "RL6001_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6096_SERIES)
#include "RL6096_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6229_SERIES)
#include "RL6229_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6213_SERIES)
#include "RL6213_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6230_SERIES)
#include "RL6230_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6192_SERIES)
#include "RL6192_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6297_SERIES)
#include "RL6297_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6269_SERIES)
#include "RL6269_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6316_SERIES)
#include "RL6316_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6336_SERIES)
#include "RL6336_Series_ScalerInterface.h"
#elif(_SCALER_TYPE == _RL6373_SERIES)
#include "RL6373_Series_ScalerInterface.h"
#endif

#include "ScalerDebugInterface.h"
#include "ScalerPowerInterface.h"
#include "ScalerIOSCInterface.h"
#include "ScalerMcuInterface.h"
#include "ScalerTimerFunctionInterface.h"
#include "ScalerGlobalInterface.h"
#include "ScalerSDRAMInterface.h"
#include "ScalerSyncInterface.h"
#include "ScalerMeasureInterface.h"
#include "ScalerIDomainInterface.h"
#include "ScalerMDomainInterface.h"
#include "ScalerDDomainInterface.h"
#include "ScalerPLLInterface.h"
#include "ScalerAudioInterface.h"
#include "ScalerColorInterface.h"
