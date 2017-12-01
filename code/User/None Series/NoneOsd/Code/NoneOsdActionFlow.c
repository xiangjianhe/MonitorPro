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
// ID Code      : NoneOSDActionFlow.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __NONE_OSDACTIONFLOW__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _NONE_OSD)
code void (*OperationTable[][4])(void) =
{
    {NoneOsdNoneMenu,          NoneOsdNoneLeft,          NoneOsdNoneRight,          NoneOsdNoneExit,          },
};
#endif//#if(_OSD_TYPE == _NONE_OSD)
