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
// ID Code      : SysInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "Global.h"
#include "Project.h"
#include "ScalerFunctionInterface.h"
#include "UserCommonInterface.h"

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Power.c Related MACRO
//--------------------------------------------------
//--------------------------------------------------
// Power action
//--------------------------------------------------
#define GET_TARGET_POWER_STATUS()          (g_stPowerInfo.b4PowerAction)
#define SET_TARGET_POWER_STATUS(x)         (g_stPowerInfo.b4PowerAction = x)

//--------------------------------------------------
// Power status
//--------------------------------------------------
#define GET_POWER_STATUS()                 (g_stPowerInfo.b4PowerStatus)
#define SET_POWER_STATUS(x)                (g_stPowerInfo.b4PowerStatus = x)

//--------------------------------------------------
// Power Isolation flag
//--------------------------------------------------
#define GET_POWER_GDI_ISO_FLG()            (bit)(g_stPowerInfo.b1GDIIsolationFlag)
#define SET_POWER_GDI_ISO_FLG()            (g_stPowerInfo.b1GDIIsolationFlag = 1)
#define CLR_POWER_GDI_ISO_FLG()            (g_stPowerInfo.b1GDIIsolationFlag = 0)

#define GET_POWER_TOP_ISO_FLG()            (bit)(g_stPowerInfo.b1TopIsolationFlag)
#define SET_POWER_TOP_ISO_FLG()            (g_stPowerInfo.b1TopIsolationFlag = 1)
#define CLR_POWER_TOP_ISO_FLG()            (g_stPowerInfo.b1TopIsolationFlag = 0)

#define GET_POWER_ANALOG_ISO_FLG()         (bit)(g_stPowerInfo.b1AnalogIsolationFlag)
#define SET_POWER_ANALOG_ISO_FLG()         (g_stPowerInfo.b1AnalogIsolationFlag = 1)
#define CLR_POWER_ANALOG_ISO_FLG()         (g_stPowerInfo.b1AnalogIsolationFlag = 0)


//--------------------------------------------------
// Source.c Related MACRO
//--------------------------------------------------
#define GET_SOURCE_SEARCH_TIME_INITIAL()        ((bit)(g_stInputInfo.b1SearchTimeInitial))
#define SET_SOURCE_SEARCH_TIME_INITIAL()        (g_stInputInfo.b1SearchTimeInitial = 1)
#define CLR_SOURCE_SEARCH_TIME_INITIAL()        (g_stInputInfo.b1SearchTimeInitial = 0)

#define GET_SOURCE_SEARCH_PORT_INITIAL()        ((bit)(g_stInputInfo.b1SearchPortInitial))
#define SET_SOURCE_SEARCH_PORT_INITIAL()        (g_stInputInfo.b1SearchPortInitial = 1)
#define CLR_SOURCE_SEARCH_PORT_INITIAL()        (g_stInputInfo.b1SearchPortInitial = 0)

#define GET_SOURCE_DETECTING()                  ((bit)(g_stInputInfo.b1Detecting))
#define SET_SOURCE_DETECTING()                  (g_stInputInfo.b1Detecting = 1)
#define CLR_SOURCE_DETECTING()                  (g_stInputInfo.b1Detecting = 0)

#define GET_SOURCE_SCAN_TYPE()                  (g_stInputInfo.b4SourceSwitchType)
#define SET_SOURCE_SCAN_TYPE(x)                 (g_stInputInfo.b4SourceSwitchType = (x))

#define GET_SOURCE_SWITCH_FINISH()              (g_stInputInfo.b1SourceSwitchCount)
#define SET_SOURCE_SWITCH_FINISH()              (g_stInputInfo.b1SourceSwitchCount = 1)
#define CLR_SOURCE_SWITCH_FINISH()              (g_stInputInfo.b1SourceSwitchCount = 0)

#define GET_SOURCE_SEARCH_TIME_REACTIVE()       (g_stInputInfo.b1SourceSearchTimeReactivate)
#define SET_SOURCE_SEARCH_TIME_REACTIVE()       (g_stInputInfo.b1SourceSearchTimeReactivate = 1)
#define CLR_SOURCE_SEARCH_TIME_REACTIVE()       (g_stInputInfo.b1SourceSearchTimeReactivate = 0)

#define GET_SOURCE_SEARCH_CHECK_NVRAM_PORT()    (g_stInputInfo.b1SourceSearchCheckNVRamPort)
#define SET_SOURCE_SEARCH_CHECK_NVRAM_PORT()    (g_stInputInfo.b1SourceSearchCheckNVRamPort = 1)
#define CLR_SOURCE_SEARCH_CHECK_NVRAM_PORT()    (g_stInputInfo.b1SourceSearchCheckNVRamPort = 0)

#define GET_SOURCE_SEARCH_DELAY_MODE()          (g_stInputInfo.b2SourceSearchDelayMode)
#define SET_SOURCE_SEARCH_DELAY_MODE(x)         (g_stInputInfo.b2SourceSearchDelayMode = (x))

#define GET_SOURCE_HP_SOURCE_JUDGE()            (g_stInputInfo.b1SourceHpSourceJudge)
#define SET_SOURCE_HP_SOURCE_JUDGE()            (g_stInputInfo.b1SourceHpSourceJudge = 1)
#define CLR_SOURCE_HP_SOURCE_JUDGE()            (g_stInputInfo.b1SourceHpSourceJudge = 0)

#define GET_SOURCE_HP_SWITCH_NO_CABLE()         (g_stInputInfo.b1SourceHpSwitchNoCable)
#define SET_SOURCE_HP_SWITCH_NO_CABLE()         (g_stInputInfo.b1SourceHpSwitchNoCable = 1)
#define CLR_SOURCE_HP_SWITCH_NO_CABLE()         (g_stInputInfo.b1SourceHpSwitchNoCable = 0)

#define GET_SOURCE_HP_TIMING_CHANGE()           (g_stInputInfo.b1SourceHpTimingChange)
#define SET_SOURCE_HP_TIMING_CHANGE()           (g_stInputInfo.b1SourceHpTimingChange = 1)
#define CLR_SOURCE_HP_TIMING_CHANGE()           (g_stInputInfo.b1SourceHpTimingChange = 0)

#define GET_SOURCE_HP_TARGET_SEARCH_TIMES()     (g_stInputInfo.b2SourceHpTargetSearchTimes)
#define SET_SOURCE_HP_TARGET_SEARCH_TIMES(x)    (g_stInputInfo.b2SourceHpTargetSearchTimes = (x))

#define GET_SOURCE_HP_PORT_SWITCH_TARGET()      (g_stInputInfo.b3SourceHpPortSwitchTarget)
#define SET_SOURCE_HP_PORT_SWITCH_TARGET(x)     (g_stInputInfo.b3SourceHpPortSwitchTarget = (x))

#define GET_SOURCE_TYPE(x)                      (g_stSourceInfo[x].b3SourceType)
#define SET_SOURCE_TYPE(x, y)                   (g_stSourceInfo[x].b3SourceType = (y))

#define GET_SOURCE_SEARCH_TIMES(x)              ((g_stSourceInfo[x].b2SearchTimes))
#define INCREASE_SOURCE_SEARCH_TIMES(x)         (g_stSourceInfo[x].b2SearchTimes++)
#define SET_SOURCE_SEARCH_TIMES(x, y)           (g_stSourceInfo[x].b2SearchTimes = (y))
#define CLR_SOURCE_SEARCH_TIMES(x)              (g_stSourceInfo[x].b2SearchTimes = 0)

#define GET_CABLE_DETECT(x)                     (g_stSourceInfo[x].b1CableDetect)
#define SET_CABLE_DETECT(x, y)                  (g_stSourceInfo[x].b1CableDetect = (y))

#define GET_CABLE_STATUS_CHANGE(x)              (g_stSourceInfo[x].b1CableStatusChange)
#define SET_CABLE_STATUS_CHANGE(x, y)           (g_stSourceInfo[x].b1CableStatusChange = (y))

#define GET_SOURCE_JUDGE(x)                     ((bit)(g_stSourceInfo[x].b1SourceChosen))
#define SET_SOURCE_JUDGE(x, y)                  (g_stSourceInfo[x].b1SourceChosen = (y))
#define CLR_SOURCE_JUDGE(x)                     (g_stSourceInfo[x].b1SourceChosen = 0)

#define GET_SOURCE_PREDETECT(x)                 ((bit)(g_stSourceInfo[x].b1SourcePreDetect))
#define SET_SOURCE_PREDETECT(x, y)              (g_stSourceInfo[x].b1SourcePreDetect = (y))
#define CLR_SOURCE_PREDETECT(x)                 (g_stSourceInfo[x].b1SourcePreDetect = 0)

#define GET_SOURCE_TYPE_BACKUP()                (g_stSourceInfoBackup.b3SourceType)
#define SET_SOURCE_TYPE_BACKUP(x)               (g_stSourceInfoBackup.b3SourceType = (x))

#define GET_SOURCE_SEARCH_TIMES_BACKUP()       ((g_stSourceInfoBackup.b2SearchTimes))
#define SET_SOURCE_SEARCH_TIMES_BACKUP(x)    (g_stSourceInfoBackup.b2SearchTimes = (x))

#define GET_CABLE_DETECT_BACKUP()               (g_stSourceInfoBackup.b1CableDetect)
#define SET_CABLE_DETECT_BACKUP(x)              (g_stSourceInfoBackup.b1CableDetect = (x))

#define GET_CABLE_STATUS_CHANGE_BACKUP()        (g_stSourceInfoBackup.b1CableStatusChange)
#define SET_CABLE_STATUS_CHANGE_BACKUP(x)       (g_stSourceInfoBackup.b1CableStatusChange = (x))

#define GET_SOURCE_JUDGE_BACKUP()               ((bit)(g_stSourceInfoBackup.b1SourceChosen))
#define SET_SOURCE_JUDGE_BACKUP(x)              (g_stSourceInfoBackup.b1SourceChosen = (x))

#define GET_SOURCE_PREDETECT_BACKUP()           ((bit)(g_stSourceInfoBackup.b1SourcePreDetect))
#define SET_SOURCE_PREDETECT_BACKUP(x)          (g_stSourceInfoBackup.b1SourcePreDetect = (x))

#define GET_SOURCE_HP_TARGET_NO_SIGNAL()         (g_stInputInfo.b1SourceHpTargetNoSignal)
#define SET_SOURCE_HP_TARGET_NO_SIGNAL()         (g_stInputInfo.b1SourceHpTargetNoSignal = 1)
#define CLR_SOURCE_HP_TARGET_NO_SIGNAL()         (g_stInputInfo.b1SourceHpTargetNoSignal = 0)

#define GET_SOURCE_ASUS_START_AUTO()            (g_stInputInfo.b1SourceAsusStartAuto)
#define SET_SOURCE_ASUS_START_AUTO()            (g_stInputInfo.b1SourceAsusStartAuto = 1)
#define CLR_SOURCE_ASUS_START_AUTO()            (g_stInputInfo.b1SourceAsusStartAuto = 0)

//--------------------------------------------------
// Mode.c Related MACRO
//--------------------------------------------------
#define GET_MODE_STATE()                        (g_stModeInfo.b5ModeState)
#define SET_MODE_STATE(x)                       (g_stModeInfo.b5ModeState = x)

#define GET_MODE_DISPLAY_SETTING_READY()        (bit)(g_stModeInfo.b1DisplaySettingReady)
#define SET_MODE_DISPLAY_SETTING_READY()        (g_stModeInfo.b1DisplaySettingReady = _TRUE)
#define CLR_MODE_DISPLAY_SETTING_READY()        (g_stModeInfo.b1DisplaySettingReady = _FALSE)

#define GET_MODE_TIMING_CONFIRM()               (bit)(g_stModeInfo.b1TimingConfirm)
#define SET_MODE_TIMING_CONFIRM()               (g_stModeInfo.b1TimingConfirm = _TRUE)
#define CLR_MODE_TIMING_CONFIRM()               (g_stModeInfo.b1TimingConfirm = _FALSE)

#define GET_MODE_STATE_CHANGE()                 (bit)(g_stModeInfo.b1ModeStateChanged)
#define SET_MODE_STATE_CHANGE()                 (g_stModeInfo.b1ModeStateChanged = _TRUE)
#define CLR_MODE_STATE_CHANGE()                 (g_stModeInfo.b1ModeStateChanged = _FALSE)

#define GET_MODE_RESET_TARGET()                 (g_stModeInfo.b4ModeResetFlag)
#define SET_MODE_RESET_TARGET(x)                (g_stModeInfo.b4ModeResetFlag = x)

#define GET_MODE_NO_WAIT_FOR_ACTIVE()           (bit)(g_stModeInfo.b1NoWaitForActive)
#define SET_MODE_NO_WAIT_FOR_ACTIVE()           (g_stModeInfo.b1NoWaitForActive = _TRUE)
#define CLR_MODE_NO_WAIT_FOR_ACTIVE()           (g_stModeInfo.b1NoWaitForActive = _FALSE)

#define GET_MODE_ACTIVE_READY()                 (bit)(g_stModeInfo.b1ActiveReady)
#define SET_MODE_ACTIVE_READY()                 (g_stModeInfo.b1ActiveReady = _TRUE)
#define CLR_MODE_ACTIVE_READY()                 (g_stModeInfo.b1ActiveReady = _FALSE)

//--------------------------------------------------
// Audio.c Related MACRO
//--------------------------------------------------
#define GET_AUDIO_PLAYBACK_SEARCH_INDEX()       (g_stAudioInfo.b4AudioPlaybackSearchIndex)
#define SET_AUDIO_PLAYBACK_SEARCH_INDEX(x)      (g_stAudioInfo.b4AudioPlaybackSearchIndex = x)

#define GET_AUDIO_STATE()                       (g_stAudioInfo.b2AudioState)
#define SET_AUDIO_STATE(x)                      (g_stAudioInfo.b2AudioState = x)

#define GET_AUDIO_STATE_CHANGE()                (bit)(g_stAudioInfo.b1AudioStateChange)
#define SET_AUDIO_STATE_CHANGE()                (g_stAudioInfo.b1AudioStateChange = _TRUE)
#define CLR_AUDIO_STATE_CHANGE()                (g_stAudioInfo.b1AudioStateChange = _FALSE)

#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))    
#define GET_DP_AUDIO_PLAYING_ALONE()            (bit)(g_stAudioInfo.b1AudioDpPlayingAlone)
#define SET_DP_AUDIO_PLAYING_ALONE()            (g_stAudioInfo.b1AudioDpPlayingAlone = _TRUE)
#define CLR_DP_AUDIO_PLAYING_ALONE()            (g_stAudioInfo.b1AudioDpPlayingAlone = _FALSE)
#endif
//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE b1SearchTimeInitial : 1;
    BYTE b1SearchPortInitial : 1;
    BYTE b1Detecting : 1;
    BYTE b4SourceSwitchType : 4; // 0000 : fixed;
                                 // 0001 : auto in group;
                                 // 0010 : auto without group;
                                 // 0011 : HP style 1 --> Scan Mode;
                                 // 0100 : HP style 2 --> Timing Change;
                                 // 0101 : HP style 3 --> Switch Port
                                 // 0110 : HP style 4 --> OOR search scan
                                 // 0111 : Asus auto
                                 // 1000 : Dell hotkey auto
                                 // 1011 : Dell hotkey fixed
    BYTE b1SourceSwitchCount : 1;
    BYTE b1SourceSearchTimeReactivate : 1;
    BYTE b1SourceSearchCheckNVRamPort : 1;    
    BYTE b2SourceSearchDelayMode : 2; // 00 : Polling
                                      // 01 : Defualt Search Time
                                      // 10 : Reactivate Search Time
    BYTE b1SourceHpSourceJudge : 1;
    BYTE b1SourceHpSwitchNoCable : 1;
    BYTE b1SourceHpTimingChange : 1;

    BYTE b2SourceHpTargetSearchTimes : 2;
    BYTE b3SourceHpPortSwitchTarget : 3;
    BYTE b1SourceHpTargetNoSignal : 1;
    BYTE b1SourceAsusStartAuto : 1;
} StructInputInfoType;

typedef struct
{
    BYTE b5ModeState : 5;
    BYTE b1DisplaySettingReady : 1;
    BYTE b1TimingConfirm : 1;
    BYTE b1ModeStateChanged : 1;
    BYTE b4ModeResetFlag : 4;    
    BYTE b1NoWaitForActive : 1;
    BYTE b1ActiveReady : 1;
} StructModeInfoType;

typedef struct
{
    BYTE b4PowerAction : 4;
    BYTE b4PowerStatus : 4;
    BYTE b1GDIIsolationFlag : 1;
    BYTE b1TopIsolationFlag : 1;
    BYTE b1AnalogIsolationFlag : 1;
} StructPowerInfoType;

typedef struct
{
    BYTE b3SourceType : 3;
    BYTE b2SearchTimes : 2;
    BYTE b1CableDetect : 1;
    BYTE b1CableStatusChange : 1;    
    BYTE b1SourceChosen : 1;
    BYTE b1SourcePreDetect : 1;
} StructSourceInfoType;

typedef struct
{
    BYTE b4AudioPlaybackSearchIndex : 4;    
    BYTE b2AudioState : 2;
    BYTE b1AudioStateChange : 1;

#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))    
    BYTE b1AudioDpPlayingAlone : 1;
#endif    
} StructAudioInfoType;
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#ifndef __SYSTEM_MODE__
extern StructModeInfoType idata g_stModeInfo;
#endif

#ifndef __SYSTEM_POWER__
extern StructPowerInfoType idata g_stPowerInfo;
#endif

#ifndef __SYSTEM_SOURCE__
extern StructSourceInfoType idata g_stSourceInfo[_INPUT_PORT_VALID];
extern StructSourceInfoType idata g_stSourceInfoBackup;
extern BYTE idata g_ucSearchIndex;
extern StructInputInfoType idata g_stInputInfo;
extern bit g_bSysPSIntDetect;
#endif

#ifndef __SYSTEM_AUDIO__
extern StructAudioInfoType idata g_stAudioInfo;
#endif

#ifndef __SYSTEM_VGA__
#endif 

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#ifndef __SYSTEM_JUDGE__
extern void SysJudgeHandler(void);
extern void SysJudgeStateChangeEvent(EnumModeStatus enumModeState);
#endif

#ifndef __SYSTEM_MODE__
extern void SysModeHandler(void);
extern bit SysModeGetDisplaySettingReady(void);
extern bit SysModeGetTimingConfirm(void);
extern bit SysModeGetActiveReady(void);
extern void SysModeResetState(BYTE ucResetTarget);
extern void SysModeSetFreeRun(void);
#endif

#ifndef __SYSTEM_MHL__
extern void SysMHLMscHandler(void);
#endif

#ifndef __SYSTEM_LCTANK__
extern void SysLCTankHandler(void);
#endif

#ifndef __SYSTEM_POWER__
extern void SysPowerInitial(void);
extern void SysPowerHandler(void);
#endif

#ifndef __SYSTEM_SOURCE__
extern void SysSourceHandler(void);
extern void SysSourceInitial(void);
extern bit SysSourceStableCheck(void);
extern void SysSourceClearDetectingEvent(void);
extern void SysSourceSwitchInputPort(BYTE ucInputPort);
extern void SysSourceInfoReset(void);
extern BYTE SysSourceGetInputPort(void);
extern BYTE SysSourceGetSourceType(void);
extern BYTE SysSourceConvertSearchPort(BYTE ucInputPort);
extern void SysSourceCableResetProc(void);
extern void SysSourceFirstActiveProc(void);
extern void SysSourcePowerOffProc(void);

#endif

#ifndef __SYSTEM_TIMER__
extern void SysTimerHandler(void);
#endif

#ifndef __SYSTEM_VGA__

#if(_VGA_SUPPORT == _ON)
extern BYTE SysVGAScanInputPort(void);
#endif

#endif

#ifndef __SYSTEM_AUDIO__

#if(_AUDIO_SUPPORT == _ON)
extern void SysAudioHandler(void);
extern void SysAudioPowerProc(EnumPowerAction enumSwitch);
#endif

#endif

