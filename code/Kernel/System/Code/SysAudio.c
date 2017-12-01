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
// ID Code      : SysAudio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_AUDIO__

#include "SysInclude.h"

#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_EMBEDDED_DAC_SUPPORT == _ON)
#define _DAC_VCM_INITIAL_TIME                       SEC(0.1)
#define _DAC_VCM_CHARGE_TIME                        SEC(0.5)
#define _DAC_DEPOP_TO_NORMAL_WAIT_TIME              SEC(0.1)
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructAudioInfoType idata g_stAudioInfo = {0};

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysAudioHandler(void);
EnumAudioState SysAudioGetAudioState(void);
void SysAudioPowerProc(EnumPowerAction enumSwitch);
void SysAudioMuteProc(bit bMute);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
void SysAudioDACHandler(void);
#endif

void SysAudioDigitalAudioHandler(void);
void SysAudioChangeAudioState(EnumAudioState enumAudioState);

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
void SysAudioInternalGenTestProc(bit bOn);
#endif
//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Audio handler. Main audio control flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioHandler(void)
{    
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioGetInternalAudioGenEnable() == _ENABLE)
    {
        return;
    }
#endif
    
#if(_EMBEDDED_DAC_SUPPORT == _ON)
    SysAudioDACHandler();
#endif

    SysAudioDigitalAudioHandler();

    switch(GET_AUDIO_STATE())
    {
        case _AUDIO_STATUS_PREPARING:
            
            if(GET_AUDIO_STATE_CHANGE() == _TRUE)
            {                
                CLR_AUDIO_STATE_CHANGE();
                SET_AUDIO_PLAYBACK_SEARCH_INDEX(0x0F);
            }
            
            if(UserInterfaceGetAudioReadyToPlay() == _TRUE)
            {
                ScalerAudioWatchDogProc(_ON);
                SysAudioMuteProc(_OFF);
                
                DebugMessageAudio("Switch to Audio Playback", 0x00);
                SysAudioChangeAudioState(_AUDIO_STATUS_PLAYBACK);
            }
            break;
            
        case _AUDIO_STATUS_PLAYBACK:

            if(GET_AUDIO_STATE_CHANGE() == _TRUE)
            {                
                CLR_AUDIO_STATE_CHANGE();
                SET_AUDIO_PLAYBACK_SEARCH_INDEX(g_ucSearchIndex);
            }

            if(UserInterfaceGetAudioReadyToPlay() == _FALSE)
            {
                SysAudioMuteProc(_ON);
                ScalerAudioWatchDogProc(_OFF);
                
                DebugMessageAudio("Switch to Audio Preparing", 0x00);
                SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);           
            }
            break;

        case _AUDIO_STATUS_POWER_OFF:
        default:
            break;
    }

#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
    if((UserInterfaceGetAudioStandAlone() == _TRUE) && (GET_AUDIO_STATE() == _AUDIO_STATUS_PLAYBACK) && (ScalerAudioGetDigitalAudioSource() == _DIGITAL_AUDIO_SOURCE_DP) && (UserInterfaceGetAudioSource() == _DIGITAL_AUDIO))
    {
        SET_DP_AUDIO_PLAYING_ALONE();
    }
    else
    {
        CLR_DP_AUDIO_PLAYING_ALONE();
    }
#endif            
}

//--------------------------------------------------
// Description  : Get Current Audio 
// Input Value  : None
// Output Value : Node
//--------------------------------------------------
EnumAudioState SysAudioGetAudioState(void)
{
    return GET_AUDIO_STATE();
}

//--------------------------------------------------
// Description  : Audio Power Process
// Input Value  : None
// Output Value : Node
//--------------------------------------------------
void SysAudioPowerProc(EnumPowerAction enumSwitch)
{   
    switch(enumSwitch)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:

            ScalerAudioInitial();   

            // Add User interface function
            UserInterfaceAudioPowerProc(_POWER_STATUS_NORMAL);

            SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);            
            break;

        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:

            // Mute Audio
            SysAudioMuteProc(_ON);         

            // Disable Audio
            ScalerAudioDisable();

            // Add User interface function
            UserInterfaceAudioPowerProc(_POWER_STATUS_OFF);

            SysAudioChangeAudioState(_AUDIO_STATUS_POWER_OFF);
            break;

        case _POWER_ACTION_PS_TO_NORMAL:

#if(_SLEEP_AUDIO_SUPPORT == _ON)
            if(GET_AUDIO_STATE() != _AUDIO_STATUS_PLAYBACK)
            {
                ScalerAudioInitial();  

                // Add User interface function
                UserInterfaceAudioPowerProc(_POWER_STATUS_NORMAL);

                SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);                
            }
#else
            ScalerAudioInitial();  

            // Add User interface function
            UserInterfaceAudioPowerProc(_POWER_STATUS_NORMAL);

            SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
#endif
            
            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NORMAL_TO_NOSUPPORT_PS:

#if(_SLEEP_AUDIO_SUPPORT == _ON)
            if(GET_AUDIO_STATE() != _AUDIO_STATUS_PLAYBACK)
            {
                // Disable Audio
                ScalerAudioDisable();
                
                SysAudioChangeAudioState(_AUDIO_STATUS_POWER_OFF);                
                
                // Add User interface function
                UserInterfaceAudioPowerProc(_POWER_STATUS_SAVING);                
            }
#else
            // Disable Audio
            ScalerAudioDisable();

            SysAudioChangeAudioState(_AUDIO_STATUS_POWER_OFF);
            
            // Add User interface function
            UserInterfaceAudioPowerProc(_POWER_STATUS_SAVING);            
#endif // End of #if(_SLEEP_AUDIO_SUPPORT == _ON)
            
            break;
            
        default:
            break;
    }
       
}

//--------------------------------------------------
// Description  : Audio Mute Process
// Input Value  : _ON => Mute On
// Output Value : None
//--------------------------------------------------
void SysAudioMuteProc(bit bMute)
{  
    if(bMute == _ON)
    {
        UserInterfaceAudioAmpMuteProc(_ON);
        
        ScalerAudioMuteProc(_ON, UserInterfaceGetAudioVolume());
    }
    else
    {
        ScalerAudioMuteProc(_OFF, UserInterfaceGetAudioVolume());
        
        UserInterfaceAudioAmpMuteProc(_OFF);
    }
}

#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Audio DAC Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioDACHandler(void)
{
    if((ScalerAudioDACGetState() != _AUDIO_DAC_OFF) && (ScalerAudioDACGetState() != _AUDIO_DAC_INITIAL)  && (ScalerAudioDACGetState() != _AUDIO_DAC_CHARGE))
    {
        // User want to change DAC Input / Output
        if((ScalerAudioDACGetInputSource() != UserInterfaceGetAudioSource()) || (ScalerAudioDACGetOutput() != UserInterfaceGetAudioDACOutput()))
        {
            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL);

            SysAudioMuteProc(_ON);
            ScalerAudioWatchDogProc(_OFF);
            ScalerAudioDACNormalToDepop();

            if(ScalerAudioDACGetOutput() != UserInterfaceGetAudioDACOutput())
            {
                DebugMessageAudio("Audio Dac Switch Output", ScalerAudioDACGetInputSource());
                
                ScalerAudioDACSetVcmReady(_OFF);
                ScalerAudioDACSetState(_AUDIO_DAC_CHARGE);
            }
            else
            {
                DebugMessageAudio("Audio Dac Switch Input", ScalerAudioDACGetInputSource());

                ScalerAudioDACInputSwitch(UserInterfaceGetAudioSource());
            }

            SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
        }
    }
        
    switch(ScalerAudioDACGetState())
    {
        case _AUDIO_DAC_OFF:

            break;
            
        case _AUDIO_DAC_INITIAL:

            if(ScalerAudioDACGetStateChange() == _TRUE)
            {
                DebugMessageAudio("Audio Dac Initial", 0x00);
                
                ScalerTimerActiveTimerEvent(_DAC_VCM_INITIAL_TIME, _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_INITIAL);
            }
            
            break;            

        case _AUDIO_DAC_CHARGE:
            
            if(ScalerAudioDACGetStateChange() == _TRUE)
            {
                DebugMessageAudio("Audio Dac Charge", 0x00);

                ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL);
                ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_CHARGE);
                
                ScalerAudioDACOutputSwitch(UserInterfaceGetAudioDACOutput());                
                ScalerAudioDACSetVcmReady(_ON);
                
                ScalerTimerActiveTimerEvent(_DAC_VCM_CHARGE_TIME, _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_CHARGE);
            }
            
            break;
            
        case _AUDIO_DAC_DEPOP:

            if(ScalerAudioDACGetStateChange() == _TRUE)
            {                
                DebugMessageAudio("Audio Dac Depop", 0x00);                
                    
                // Analog In can't enable output here because 0 volume could be heard
                if(ScalerAudioDACGetInputSource() == _DIGITAL_AUDIO)
                {
                    ScalerAudioDACOutputEnable();
                    ScalerTimerActiveTimerEvent(_DAC_DEPOP_TO_NORMAL_WAIT_TIME, _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL);
                }
                else
                {             
                    if(GET_AUDIO_STATE() == _AUDIO_STATUS_PLAYBACK)
                    {
                        SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
                    }
                    
                    ScalerAudioDACSetState(_AUDIO_DAC_READY); 
                }
            }
            break;

        case _AUDIO_DAC_READY:

            break;
            
        default:
            break;
    }

    ScalerAudioDACClrStateChange();
}
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Digital Audio Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioDigitalAudioHandler(void)
{
    ScalerAudioDigitalOutputMute(UserInterfaceDecideAudioNonLPCMMute());
    
    ScalerAudioDigitalDetect();    
}

//--------------------------------------------------
// Description  : Change Audio State
// Input Value  : Target Audio State
// Output Value : Node
//--------------------------------------------------
void SysAudioChangeAudioState(EnumAudioState enumAudioState)
{
    SET_AUDIO_STATE(enumAudioState);
    SET_AUDIO_STATE_CHANGE();
}

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Internal Audio Gen Test Process
// Input Value  : _ON/ _OFF
// Output Value : None
//--------------------------------------------------
void SysAudioInternalGenTestProc(bit bOn)
{
    ScalerAudioDigitalVolumeMute(_ON, UserInterfaceGetAudioVolume());        

#if(_EMBEDDED_DAC_SUPPORT == _ON)            
    ScalerAudioAnalogVolumeMute(_ON, (BYTE)UserInterfaceGetAudioVolume());        
#endif
    
    if(bOn == _ON)
    {
        ScalerAudioWatchDogProc(_OFF);
        
        ScalerAudioDACInputSwitch(_DIGITAL_AUDIO);
        ScalerAudioInternalAudioGenSwitch(_ON);

        ScalerAudioDACRestart();
        ScalerAudioDigitalVolumeMute(_OFF, UserInterfaceGetAudioVolume());
    }
    else
    {
        ScalerAudioInternalAudioGenSwitch(_OFF);        
        SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
    }
}
#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
#endif // End of #if(_AUDIO_SUPPORT == _ON)
