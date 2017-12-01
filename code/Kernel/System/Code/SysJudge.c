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
// ID Code      : SysJudge.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_JUDGE__

#include "SysInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysJudgeHandler(void);
bit SysJudgeCheckStatus(void);
void SysJudgeStateChangeEvent(EnumModeStatus enumModeState);
void SysJudgeModeResetProc(void);
WORD SysJudgeGetActiveWaitTime(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Judge Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysJudgeHandler(void)
{
    CLR_MODE_STATE_CHANGE();

    switch(GET_POWER_STATUS())
    {
        case _POWER_STATUS_OFF:

            if(GET_MODE_STATE() != _MODE_STATUS_POWER_OFF)
            {
                SysJudgeStateChangeEvent(_MODE_STATUS_POWER_OFF);
            }
            
            break;
            
        case _POWER_STATUS_SAVING:
        case _POWER_STATUS_NOSUPPORT_SAVING:

            if(GET_MODE_STATE() != _MODE_STATUS_POWER_SAVING)
            {
                SysJudgeStateChangeEvent(_MODE_STATUS_POWER_SAVING);
            }
            
            break;
            
        case _POWER_STATUS_NORMAL:                    
            
            switch(GET_MODE_STATE())
            {
                case _MODE_STATUS_POWER_OFF:

                    SysJudgeStateChangeEvent(_MODE_STATUS_INITIAL);
                    
                    break;        
                    
                case _MODE_STATUS_INITIAL:
                    
                    SysJudgeStateChangeEvent(_MODE_STATUS_SEARCH);
                    
                    return;
                    
                    break;
                    
                case _MODE_STATUS_SEARCH:

                    if(UserInterfaceOsdGetLogoOn() == _TRUE)
                    {
                        return;
                    }
                   
                    if(GET_SOURCE_JUDGE(g_ucSearchIndex) == _TRUE)
                    {    
                        // If Timing can't be confirmed for 1 sec, switch to No Support State
                        ScalerTimerActiveTimerEvent(SEC(1), _SYSTEM_TIMER_EVENT_JUDGE_NOSIGNAL_STATE);
                        
                        if(SysModeGetTimingConfirm() == _TRUE)
                        {                            
                            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_NOSIGNAL_STATE);
                                
                            if(UserCommonInterfaceCheckNoSupport() == _FALSE)
                            {
                                ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE);                                                        
                                SysJudgeStateChangeEvent(_MODE_STATUS_DISPLAY_SETTING);
                            }
                            else
                            {
                                ScalerTimerActiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE);
                            }
                        }
                    }
                    else if(GET_SOURCE_SWITCH_FINISH() == _TRUE)    // If Search Finish, Switch to no signal
                    {                            
                        SysJudgeStateChangeEvent(_MODE_STATUS_NOSIGNAL);

                        CLR_SOURCE_SWITCH_FINISH();
                    }
                    
                    break;
                    
                case _MODE_STATUS_DISPLAY_SETTING:

                    if(((SysModeGetActiveReady() == _TRUE)) && (UserCommonInterfaceReadyForActive() == _TRUE))
                    {
                        SysJudgeStateChangeEvent(_MODE_STATUS_ACTIVE);
                        CLR_MODE_ACTIVE_READY();
                    }
                    else
                    {
                        if(SysModeGetDisplaySettingReady() == _TRUE)
                        {
                            // Check Whether to Support Current D Clk
                            if(UserInterfaceDClkNoSupportCheck() == _TRUE)
                            {
                                ScalerTimerActiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE);
                            }
                            else
                            {                                                                
                                ScalerTimerActiveTimerEvent(SysJudgeGetActiveWaitTime(), _SYSTEM_TIMER_EVENT_JUDGE_ACTIVE_STATE);
                            }
                        }
                        else
                        {
                            // If Display Setting can't be Ready for 2 sec, switch to No Support State
                            ScalerTimerActiveTimerEvent(SEC(2), _SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE);
                        }
                    }
                                        
                    break;
                    
                case _MODE_STATUS_ACTIVE:
                        
                    break;
                    
                case _MODE_STATUS_NOSUPPORT:
     
                    break;
                    
                case _MODE_STATUS_NOSIGNAL:
                case _MODE_STATUS_POWER_SAVING:
                    
                    if(SysModeGetTimingConfirm() == _TRUE)
                    {                        
                        UserCommonInterfaceOsdResetProc();
                        
                        if(UserCommonInterfaceCheckNoSupport() == _FALSE)
                        {
                            SysJudgeStateChangeEvent(_MODE_STATUS_DISPLAY_SETTING);
                        }
                        else
                        {
                            ScalerTimerActiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE);
                        }                        
                    }

                    break;
                
                case _MODE_STATUS_FACTORY:

                    break;
                    
                default:

                    break;
            }    
            
            break;
            
        default:
            break;
    }

    // Handle Status Check and Manual Reset Requests
    SysJudgeModeResetProc();    
}


//--------------------------------------------------
// Description  : Check Status
// Input Value  : None.
// Output Value : _FALSE => Status Changed
//--------------------------------------------------
bit SysJudgeCheckStatus(void)
{
    if(GET_MODE_STATE() != _MODE_STATUS_FACTORY)
    {    
        if(GET_SOURCE_JUDGE(g_ucSearchIndex) == _TRUE)
        {
            if(SysSourceStableCheck() == _FALSE)
            {
                DebugMessageSystem("Source Unstable!!", GET_SOURCE_TYPE(g_ucSearchIndex));
                return _FALSE;
            }
        }

        if(SysModeGetTimingConfirm() == _TRUE)
        {                   
            // Check whether Input Timing changed
            if(ScalerMeasureTimingChange(GET_SOURCE_TYPE(g_ucSearchIndex)) == _TRUE)
            {
                DebugMessageSystem("Measured Input HV Changed", GET_SOURCE_TYPE(g_ucSearchIndex));
                return _FALSE;
            }
        }

        if(SysModeGetDisplaySettingReady() == _TRUE)
        {
            if(ScalerMDomainMemoryCheck() == _FALSE)
            {
                DebugMessageSystem("Memory Check Failed", GET_SOURCE_TYPE(g_ucSearchIndex));
                return _FALSE;
            }

            if(GET_INPUT_TIMING_DOUBLE_CHECK() == _TRUE)
            {
                if(GET_SOURCE_TYPE(g_ucSearchIndex) != _SOURCE_VGA)
                {
                    if(ScalerSyncInterlaceCheck(GET_SOURCE_TYPE(g_ucSearchIndex)) != GET_INPUT_TIMING_INTERLACE_FLG())
                    {
                        DebugMessageSystem("Input Timing Double Check : Interlace Flag Change", GET_SOURCE_TYPE(g_ucSearchIndex));
                    
                        return _FALSE;   
                    } 
                }

                CLR_INPUT_TIMING_DOUBLE_CHECK();
            }
        }       
    }
    
    return _TRUE;
}

//--------------------------------------------------
// Description  : Switch to Active State
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysJudgeStateChangeEvent(EnumModeStatus enumModeState)
{
    SET_MODE_STATE(enumModeState);
    SET_MODE_STATE_CHANGE();
}

void SysJudgeModeResetProc(void)
{        
    switch(GET_MODE_RESET_TARGET())
    {
        case _MODE_ACTION_RESET_TO_SEARCH:

            if(GET_POWER_STATUS() != _POWER_STATUS_OFF)
            {
                SysModeResetState(_MODE_ACTION_RESET_TO_SEARCH);    

                SysJudgeStateChangeEvent(_MODE_STATUS_SEARCH);
            }
        
            break;

        case _MODE_ACTION_RESET_TO_DISPLAY_SETTING:            

            if(GET_MODE_STATE() == _MODE_STATUS_ACTIVE)
            {
                SysModeResetState(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);

                SysJudgeStateChangeEvent(_MODE_STATUS_DISPLAY_SETTING);
            }
            
            break;

#if(_3D_SUPPORT == _ON)
        case _MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG:

            if(GET_MODE_STATE() == _MODE_STATUS_ACTIVE)
            {
                SysModeResetState(_MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG);

                SysJudgeStateChangeEvent(_MODE_STATUS_DISPLAY_SETTING);
            }
            
            break;
#endif

        case _MODE_ACTION_RESET_TO_NOSIGNAL:

            if(GET_POWER_STATUS() != _POWER_STATUS_OFF)
            {
                ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_NOSIGNAL_STATE);                        

                SysJudgeStateChangeEvent(_MODE_STATUS_NOSIGNAL);
            }
            
            break;
            
        case _MODE_ACTION_RESET_TO_NOSUPPORT:

            if(GET_POWER_STATUS() != _POWER_STATUS_OFF)
            {
                SysModeResetState(_MODE_ACTION_RESET_TO_NOSUPPORT);    
                
                ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE);                        

                SysJudgeStateChangeEvent(_MODE_STATUS_NOSUPPORT);
            }
            
            break;
            
        case _MODE_ACTION_RESET_TO_FACTORY_MODE:

            SysJudgeStateChangeEvent(_MODE_STATUS_FACTORY);
        
            break;

        default:
            break;            
    }
    
    SET_MODE_RESET_TARGET(_MODE_ACTION_NO_RESET_MODE);     
    
    if(SysJudgeCheckStatus() == _FALSE)
    {
        SysModeResetState(_MODE_ACTION_RESET_TO_SEARCH);    

        SysJudgeStateChangeEvent(_MODE_STATUS_SEARCH);
    }    

}

//--------------------------------------------------
// Description  : Get Required Wait Time before Active
// Input Value  : None
// Output Value : Required Wait Time
//--------------------------------------------------
WORD SysJudgeGetActiveWaitTime(void)
{
    if(GET_MODE_NO_WAIT_FOR_ACTIVE() == _FALSE)
    {
        switch(GET_SOURCE_TYPE(g_ucSearchIndex))
        {
            
#if(_VGA_SUPPORT == _ON)
            case _SOURCE_VGA:            
                return _WAIT_TIME_TO_ACTIVE_VGA;
                break;
#endif

#if(_DVI_SUPPORT == _ON)
            case _SOURCE_DVI:
                return _WAIT_TIME_TO_ACTIVE_DVI;
                break;
#endif

#if(_HDMI_SUPPORT == _ON)
            case _SOURCE_HDMI:
                return _WAIT_TIME_TO_ACTIVE_HDMI;
                break;
#endif

#if(_DP_SUPPORT == _ON)
            case _SOURCE_DP:
                return _WAIT_TIME_TO_ACTIVE_DP;
                break;
#endif
           
            default:
                break;
        }
    }
    
    return 0;
}

