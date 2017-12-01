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
// ID Code      : RTDTimerInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// User timer event
//--------------------------------------------------
typedef enum
{
    _USER_TIMER_EVENT_START,
    _USER_TIMER_EVENT_KEY_REPEAT_ENABLE = _USER_TIMER_EVENT_START,
    _USER_TIMER_EVENT_KEY_SCAN_READY,
    _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO,
    _USER_TIMER_EVENT_OSD_SHOW_NO_CABLE,
    _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL,
    _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING,
    _USER_TIMER_EVENT_GO_TO_POWER_SAVING,
    _USER_TIMER_EVENT_OSD_DISABLE,
    _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON,
    _USER_TIMER_EVENT_PANEL_POWER_OFF,
    _USER_TIMER_EVENT_DO_AUTO_COLOR,
    _USER_TIMER_EVENT_PANEL_USED_TIMER,
    _USER_TIMER_EVENT_HLWIN_TYPE5_MOVE,    

#if(_ENERGY_STAR_SUPPORT == _ON)
    _USER_TIMER_EVENT_ES_ADJUST,
#endif
	
    _USER_TIMER_EVENT_END,
    _USER_TIMER_EVENT_COUNT = _USER_TIMER_EVENT_END,
} EnumUserTimerEventID;

#define _SIMULTANEOUS_USER_EVENT_COUNT             5
