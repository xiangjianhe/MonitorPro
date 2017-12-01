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
    _USER_TIMER_EVENT_OSD_DISABLE_AUTO_ADJUST_MSG,
    _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON,
    _USER_TIMER_EVENT_PANEL_POWER_OFF,
    _USER_TIMER_EVENT_DO_AUTO_COLOR,
    _USER_TIMER_EVENT_PANEL_USED_TIMER,
    _USER_TIMER_EVENT_HLWIN_TYPE5_MOVE,    
#if(_ENERGY_STAR_SUPPORT == _ON)
    _USER_TIMER_EVENT_ES_ADJUST,
#endif
    _USER_TIMER_EVNET_TOUCH_RESTORT,
	_USER_TIMER_EVENT_TOUCH_LED_OFF,    
	_USER_TIMER_EVENT_OSD_LOCK,  
	_USER_TIMER_EVENT_OSD_DDCCI_ONOFF, 
	_USER_TIMER_EVENT_BURN_IN, 
    _USER_TIMER_EVENT_OSD_SHOW_NO_SUPPORT,        
    _USER_TIMER_EVENT_FLY_OSD_TO_POWER_SAVING,
    _USER_TIMER_EVENT_OSD_FLYING,

#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    _USER_TIMER_EVENT_LED_FLASH,
    _USER_TIMER_EVENT_EDIDVERSION_CLEAR,
#endif

#if(_AUDIO_SUPPORT == _ON)	
    _USER_TIMER_EVENT_AMP_POWER_OFF,
    _USER_TIMER_EVENT_AMP_MUTE_OFF, 
#endif
    
#if(_AUTO_POWER_DOWN == _ON)
     _USER_TIMER_EVENT_POWER_DOWN_COUNT,
     _USER_TIMER_EVENT_POWER_DOWN_TO_POWER_SAVING,
#endif
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_LBL_HOTKEY_FUNCTION == _ON))
    _USER_TIMER_EVENT_LOW_BLUE_LIGHT,
#endif
    _USER_TIMER_EVENT_END,
    _USER_TIMER_EVENT_COUNT = _USER_TIMER_EVENT_END,
} EnumUserTimerEventID;

#define _SIMULTANEOUS_USER_EVENT_COUNT             5
