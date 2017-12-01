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
// ID Code      : SysSource.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_SOURCE__

#include "SysInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Macro of Getting Input Source
//--------------------------------------------------
#define GET_INPUT_PORT(x)               (tINPUT_PORT[g_ucSourceSearchPriority[x]])

//--------------------------------------------------
// Macro of Getting Input Port Type
//--------------------------------------------------
#define GET_INPUTPORT_TYPE(x)           (tINPUT_PORT_TYPE[g_ucSourceSearchPriority[x]])

//--------------------------------------------------
// Macro of Getting Input Port Group Type
//--------------------------------------------------
#define GET_INPUTPORT_GROUP(x)          (g_ucSourceSearchGroup[g_ucSourceSearchPriority[x]])


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Input Port Data Table
//--------------------------------------------------
BYTE code tINPUT_PORT[] =
{
    _D0_INPUT_PORT,
    _D1_INPUT_PORT,
    _D2_INPUT_PORT,
    _D3_INPUT_PORT,        
    _A0_INPUT_PORT,
};

BYTE code tINPUT_PORT_TYPE[] =
{
    _D0_INPUT_PORT_TYPE,
    _D1_INPUT_PORT_TYPE,
    _D2_INPUT_PORT_TYPE,
    _D3_INPUT_PORT_TYPE,        
    _A0_INPUT_PORT_TYPE,
};


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructSourceInfoType idata g_stSourceInfo[_INPUT_PORT_VALID];
StructSourceInfoType idata g_stSourceInfoBackup;
// SourceInfo bit[0:2] -- Source Type
//#define _SOURCE_NONE                      0
//#define _SOURCE_VGA                       1
//#define _SOURCE_DVI                       2
//#define _SOURCE_HDMI                      3
//#define _SOURCE_DP                        4
//#define _SOURCE_VIDEO                     5
//                                        = 000 => no Source
//                                        = 001 => VGA Source
//                                        = 010 => DVI Source
//                                        = 011 => HDMI Source
//                                        = 100 => DP Source
//                                        = 101 => Video Source
//                                        = others => reserved

// SourceInfo bit[3:4] -- Source Search Times
//                                     = 0~3 => Counter

// SourceInfo bit[5] -- Cable detect
//            = 0 => No
//            = 1 => Yes

// SourceInfo bit[7] -- Source Chosen
//                                      = 0 => Unchosen
//                                      = 1 => Chosen

BYTE idata g_ucSearchIndex = 0;

StructInputInfoType idata g_stInputInfo = {0};

BYTE g_ucSourceSearchPriority[5] = {_INPUT_PORT_SEARCH_PRI_0, _INPUT_PORT_SEARCH_PRI_1, _INPUT_PORT_SEARCH_PRI_2, _INPUT_PORT_SEARCH_PRI_3, _INPUT_PORT_SEARCH_PRI_4};
BYTE g_ucSourceSearchGroup[5] = {_D0_INPUT_PORT_GROUP, _D1_INPUT_PORT_GROUP, _D2_INPUT_PORT_GROUP, _D3_INPUT_PORT_GROUP, _A0_INPUT_PORT_GROUP};

bit g_bA0CableDetect = _FALSE;
bit g_bD0CableDetect = _FALSE;
bit g_bD1CableDetect = _FALSE;
bit g_bD2CableDetect = _FALSE;
bit g_bD3CableDetect = _FALSE;
bit g_bD1DpDualPortStatus = _FALSE;
bit g_bD0MHLCableDetect = _FALSE;
bit g_bD1MHLCableDetect = _FALSE;

bit idata g_bSysPSIntDetect = _FALSE;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysSourceHandler(void);
void SysSourceDetectPort(void);
void SysSourceClearDetectingEvent(void);
void SysSourceSearchTimeInitial(void);
void SysSourceJudge(void);
void SysSourceSwitchPort(void);
void SysSourceScanPortInitial(void);
void SysSourceInitial(void);
bit SysSourceStableCheck(void);
BYTE SysSourceGetSourceType(void);
BYTE SysSourceGetInputPort(void);
BYTE SysSourceGetSpecificInputPort(BYTE ucIndex);

#if(_SLEEP_AUDIO_SUPPORT == _ON)
BYTE SysSourceGetAudioPlaybackPort(void);
#endif

void SysSourceSwitchInputPort(BYTE ucInputPort);
void SysSourceInfoReset(void);
void SysSourceCableDetection(void);
bit SysSourceCheckTargetTimes(BYTE ucTargetTimes);
void SysSourceSetScanType(BYTE ucScanType);
BYTE SysSourceGetScanType(void);
BYTE SysSourceConvertSearchPort(BYTE ucInputPort);
bit SysSourceGetCableDetect(BYTE ucInputPort);
bit SysSourceGetCableStatusChange(BYTE ucInputPort);
void SysSourceCableResetProc(void);
void SysSourceFirstActiveProc(void);
void SysSourcePowerOffProc(void);
void SysSourceSetSearchPriority(EnumSourceSearchPort enumPort, EnumSourceSearchPortPriority enumSourcePriority);
void SysSourceSetSearchGroup(EnumSourceSearchPort enumPort, EnumSourceSearchGroup enumSourceGroup);

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
bit SysSourceHpGetSourceJudge(void);
BYTE SysSourceHpGetTargetSourceType(BYTE ucSearchIndex);
BYTE SysSourceHpGetTargetSearchTimes(void);
bit SysSourceHpGetSwitchPortNoCable(void);
bit SysSourceHpGetTargetPortNoSignal(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Source Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceHandler(void)
{
    SysSourceCableDetection();
            
    if((GET_MODE_STATE() != _MODE_STATUS_POWER_OFF) && (GET_MODE_STATE() != _MODE_STATUS_INITIAL) && (UserInterfaceGetForcePowSavStatus() == _FALSE))
    {
        if(GET_SOURCE_JUDGE(g_ucSearchIndex) == _FALSE)
        {
            if(GET_SOURCE_DETECTING() == _FALSE)
            {            
                SysSourceSwitchPort();
            }            

            if(GET_SOURCE_SEARCH_PORT_INITIAL() == _TRUE)
            {
                SysSourceScanPortInitial();
                
                CLR_SOURCE_SEARCH_PORT_INITIAL();                
            }        

            if(GET_SOURCE_SEARCH_TIME_INITIAL() == _TRUE)
            {
                SysSourceSearchTimeInitial();

                CLR_SOURCE_SEARCH_TIME_INITIAL();
            }

            // Port Detection
            SysSourceDetectPort();

            // Decide if this port is about to be chosen
            SysSourceJudge();
        }
    }
}

//--------------------------------------------------
// Description  : Port Detection
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceDetectPort(void)
{
    switch(GET_SOURCE_SCAN_TYPE())
    {
#if(_HP_SOURCE_SCAN_SUPPORT == _ON)

        case _SOURCE_SWITCH_HP_SOURCE_SCAN:
        case _SOURCE_SWITCH_HP_SOURCE_SWITCH:
        case _SOURCE_SWITCH_HP_TIMING_CHANGE:
        case _SOURCE_SWITCH_HP_OOR_SOURCE_SCAN:     

            if(GET_SOURCE_HP_SWITCH_NO_CABLE() == _TRUE)
            {
                return;
            }

            break;
#endif
        default:

            break;
    }

    SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);
    
    switch(GET_INPUTPORT_TYPE(g_ucSearchIndex))
    {
#if(_VGA_SUPPORT == _ON)        
        case _A0_VGA_PORT:

            if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
            {   
                SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncVgaPreDetect());
            }
            else if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
            {   
                SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncVgaPreDetect());

                if((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_POLLING_MODE) && (GET_SOURCE_PREDETECT(g_ucSearchIndex) == _TRUE))
                {
                    SET_SOURCE_TYPE(g_ucSearchIndex, SysVGAScanInputPort());
                }                
            }
            
            break;
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

#if(_DVI_SUPPORT == _ON)
        case _D0_DVI_PORT:
        case _D1_DVI_PORT:
        case _D2_DVI_PORT:
        case _D3_DVI_PORT:             
#endif

#if(_HDMI_SUPPORT == _ON)
        case _D0_HDMI_PORT:                        
        case _D1_HDMI_PORT:
        case _D2_HDMI_PORT:
        case _D3_HDMI_PORT:                
#endif

            if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
            {
                SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncTmdsPSPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    
            }
            else if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
            {
                SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncTmdsNormalPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    

                if((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_POLLING_MODE) && (GET_SOURCE_PREDETECT(g_ucSearchIndex) == _TRUE))
                {
                    SET_SOURCE_TYPE(g_ucSearchIndex, ScalerSyncTmdsScanInputPort(GET_INPUTPORT_TYPE(g_ucSearchIndex)));                
                }                                
            }

            break;
#endif

#if(_MHL_SUPPORT == _ON)
        case _D0_MHL_PORT: 
            
            if(GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE)
            {
                if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
                {
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncTmdsPSPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    
                }
                else if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
                {
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncTmdsNormalPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    

                    if((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_POLLING_MODE) && (GET_SOURCE_PREDETECT(g_ucSearchIndex) == _TRUE))
                    {
                        SET_SOURCE_TYPE(g_ucSearchIndex, ScalerSyncTmdsScanInputPort(GET_INPUTPORT_TYPE(g_ucSearchIndex)));                
                    }                                
                }
            }
            else if(GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)
            {
                if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
                {
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncMHLPSPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    
                }
                else if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
                {
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncMHLNormalPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    

                    if((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_POLLING_MODE) && (GET_SOURCE_PREDETECT(g_ucSearchIndex) == _TRUE))
                    {
                        SET_SOURCE_TYPE(g_ucSearchIndex, ScalerSyncTmdsScanInputPort(GET_INPUTPORT_TYPE(g_ucSearchIndex)));                
                    }                                
                }
            }
            break;

        case _D1_MHL_PORT:
            
            if(GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE)
            {
                if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
                {
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncTmdsPSPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    
                }
                else if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
                {
                    
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncTmdsNormalPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    
                    
                    if((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_POLLING_MODE) && (GET_SOURCE_PREDETECT(g_ucSearchIndex) == _TRUE))
                    {
                        SET_SOURCE_TYPE(g_ucSearchIndex, ScalerSyncTmdsScanInputPort(GET_INPUTPORT_TYPE(g_ucSearchIndex)));                
                    }                                
                }
            }
            else if(GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)
            {
                if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
                {
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncMHLPSPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    
                }
                else if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
                {
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncMHLNormalPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    
                    
                    if((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_POLLING_MODE) && (GET_SOURCE_PREDETECT(g_ucSearchIndex) == _TRUE))
                    {
                        SET_SOURCE_TYPE(g_ucSearchIndex, ScalerSyncTmdsScanInputPort(GET_INPUTPORT_TYPE(g_ucSearchIndex)));                
                    }                                
                }
            }
            break;

#endif

#if(_DP_SUPPORT == _ON)
        case _D0_DP_PORT:
        case _D1_DP_PORT:    
            
            if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
            {
                SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncDpPSPreDetect());            
            }
            else if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
            {
                SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncDpNormalPreDetect());

                if((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_POLLING_MODE) && (GET_SOURCE_PREDETECT(g_ucSearchIndex) == _TRUE))
                {
                    SET_SOURCE_TYPE(g_ucSearchIndex, ScalerSyncDpScanInputPort());                
                }                                                
            }
            
            break;
#endif

#if(_DP_DUAL_MODE_SUPPORT == _ON)

        case _D1_DP_DUAL_PORT:

            if(GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS)
            {                
                if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
                {
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncTmdsPSPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    
                }
                else if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
                {                    
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncTmdsNormalPreDetect(GET_INPUT_PORT(g_ucSearchIndex)));                                    

                    if((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_POLLING_MODE) && (GET_SOURCE_PREDETECT(g_ucSearchIndex) == _TRUE))
                    {
                        SET_SOURCE_TYPE(g_ucSearchIndex, ScalerSyncTmdsScanInputPort(GET_INPUTPORT_TYPE(g_ucSearchIndex)));                
                    }                                
                }
            }
            else
            {
                if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
                {
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncDpPSPreDetect());            
                }
                else if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
                {                    
                    SET_SOURCE_PREDETECT(g_ucSearchIndex, ScalerSyncDpNormalPreDetect());

                    if((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_POLLING_MODE) && (GET_SOURCE_PREDETECT(g_ucSearchIndex) == _TRUE))
                    {
                        SET_SOURCE_TYPE(g_ucSearchIndex, ScalerSyncDpScanInputPort());                
                    }                                                
                }
            }

            break;
#endif
        default:
            
            break;
    }    
}

//--------------------------------------------------
// Description  : Event to clear detection and finish flag
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceClearDetectingEvent(void)
{
#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
    if(GET_DP_AUDIO_PLAYING_ALONE() == _TRUE)
    {
        if(GET_MODE_STATE() == _MODE_STATUS_SEARCH)
        {
            SET_SOURCE_SWITCH_FINISH();
        }
        ScalerTimerActiveTimerEvent(SEC(0), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
        return;
    }
#endif

    CLR_SOURCE_DETECTING();
}

//--------------------------------------------------
// Description  : Decide how much time will be spent on the first port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceSearchTimeInitial(void)
{
    SET_SOURCE_DETECTING();

    if(GET_SOURCE_SEARCH_DELAY_MODE() == _SOURCE_SEARCH_POLLING_MODE)
    {
        ScalerTimerReactiveTimerEvent(SEC(0), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
    }
    
#if(_SOURCE_DOUBLE_CHECK_NVRAM_PORT_SUPPORT == _ON)
    else if(GET_SOURCE_SEARCH_DELAY_MODE() == _SOURCE_SEARCH_DELAY_NVRAM_PORT_MODE)
    {   
        SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);
        
        ScalerTimerReactiveTimerEvent(_SOURCE_DOUBLE_CHECK_SEARCH_TIME_NVRAM_PORT, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);    
    }
#endif

    else if(GET_SOURCE_SEARCH_DELAY_MODE() == _SOURCE_SEARCH_DELAY_REACTIVE_MODE)
    {             
        SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                
        switch(GET_INPUTPORT_TYPE(g_ucSearchIndex))
        {
            case _A0_VGA_PORT:
                
                ScalerTimerReactiveTimerEvent(SEC(2), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);

                break;

            case _D0_DVI_PORT:
            case _D0_HDMI_PORT:
            case _D1_DVI_PORT:            
            case _D1_HDMI_PORT:                        
            case _D2_DVI_PORT:
            case _D2_HDMI_PORT:
            case _D3_DVI_PORT:
            case _D3_HDMI_PORT:   
                
                ScalerTimerReactiveTimerEvent(SEC(4.5), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);

                break;

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
            case _D0_MHL_PORT:

                if(GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)
                {
                    ScalerTimerReactiveTimerEvent(SEC(6), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                }
                else
                {
                    ScalerTimerReactiveTimerEvent(SEC(4.5), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                }
                
                break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
            case _D1_MHL_PORT:  

                if(GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)
                {
                    ScalerTimerReactiveTimerEvent(SEC(6), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                }
                else
                {
                    ScalerTimerReactiveTimerEvent(SEC(4.5), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                }
                
                break;
#endif

            case _D0_DP_PORT:
            case _D1_DP_PORT:                                    
            
                ScalerTimerReactiveTimerEvent(SEC(4), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);

                break;                        

#if(_DP_DUAL_MODE_SUPPORT == _ON)

            case _D1_DP_DUAL_PORT:          

                if(GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS)
                {
                    ScalerTimerReactiveTimerEvent(SEC(4.5), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                }
                else
                {
                    ScalerTimerReactiveTimerEvent(SEC(4), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                }                        

                break;
#endif
            default:
                break;
        }                                                
    }
    else
    {        
        switch(GET_SOURCE_SCAN_TYPE())
        {        
            case _SOURCE_SWITCH_FIXED_PORT:
            case _SOURCE_SWITCH_AUTO_IN_GROUP:
            case _SOURCE_SWITCH_AUTO_WITHOUT_GROUP:
            case _SOURCE_SWITCH_DELL_HOTKEY_FIXED:
            case _SOURCE_SWITCH_DELL_HOTKEY_AUTO:

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)

                ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_ALL_PORT, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_DELL_STYLE)

                switch(GET_INPUTPORT_TYPE(g_ucSearchIndex))
                {
                    case _A0_VGA_PORT:

                        if(GET_CABLE_DETECT(g_ucSearchIndex) == _TRUE)
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_VGA, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }
                        else
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_VGA_NO_CABLE, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }  
                        
                        break;

                    case _D0_DVI_PORT:
                    case _D0_HDMI_PORT:
                    case _D0_MHL_PORT:
                    case _D1_DVI_PORT:            
                    case _D1_HDMI_PORT:  
                    case _D1_MHL_PORT:
                    case _D2_DVI_PORT:
                    case _D2_HDMI_PORT:
                    case _D3_DVI_PORT:
                    case _D3_HDMI_PORT: 
                        
                        if(GET_CABLE_DETECT(g_ucSearchIndex) == _TRUE)
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_TMDS, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }
                        else
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_TMDS_NO_CABLE, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }
                        
                        break;

                    case _D0_DP_PORT:
                    case _D1_DP_PORT:                                    
                    
                        if(GET_CABLE_DETECT(g_ucSearchIndex) == _TRUE)
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_DP, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }
                        else
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_DP_NO_CABLE, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }
                        
                        break;                        

#if(_DP_DUAL_MODE_SUPPORT == _ON)

                    case _D1_DP_DUAL_PORT:          

                        if(GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS)
                        {
                            if(GET_CABLE_DETECT(g_ucSearchIndex) == _TRUE)
                            {
                                ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_TMDS, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                            }
                            else
                            {
                                ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_TMDS_NO_CABLE, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                            }
                        }
                        else
                        {
                            if(GET_CABLE_DETECT(g_ucSearchIndex) == _TRUE)
                            {
                                ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_DP, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                            }
                            else
                            {
                                ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_DP_NO_CABLE, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                            }
                        }                        

                        break;
#endif // End of #if(_DP_DUAL_MODE_SUPPORT == _ON)

                    default:
                        break;
                }    
#else // Else of #if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)

                switch(GET_INPUTPORT_TYPE(g_ucSearchIndex))
                {
                    case _A0_VGA_PORT:
                        
                        ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_VGA, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);

                        break;

                    case _D0_DVI_PORT:
                    case _D0_HDMI_PORT:
                    case _D0_MHL_PORT:
                    case _D1_DVI_PORT:            
                    case _D1_HDMI_PORT:  
                    case _D1_MHL_PORT:
                    case _D2_DVI_PORT:
                    case _D2_HDMI_PORT:
                    case _D3_DVI_PORT:
                    case _D3_HDMI_PORT: 
                        
                        ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_TMDS, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);

                        break;

                    case _D0_DP_PORT:
                    case _D1_DP_PORT:                                    
                    
                        ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_DP, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);

                        break;                        

#if(_DP_DUAL_MODE_SUPPORT == _ON)

                    case _D1_DP_DUAL_PORT:          

                        if(GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS)
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_TMDS, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }
                        else
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_DP, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }                        

                        break;
#endif // End of #if(_DP_DUAL_MODE_SUPPORT == _ON)

                    default:
                        break;
                }     
#endif // End of #if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)

                break;

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)

            case _SOURCE_SWITCH_HP_SOURCE_SCAN:
            case _SOURCE_SWITCH_HP_TIMING_CHANGE:
            case _SOURCE_SWITCH_HP_OOR_SOURCE_SCAN:     

                switch(GET_INPUTPORT_TYPE(g_ucSearchIndex))
                {
                    case _A0_VGA_PORT:

                        if(GET_CABLE_DETECT(g_ucSearchIndex) == _TRUE)
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_VGA, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);                        
                        }
                        else if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)                            
                        {
                            ScalerTimerReactiveTimerEvent(SEC(0.2), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);                        
                        }
                        else
                        {
                            ScalerTimerReactiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);                        
                        }       
                        
                        break;

                    case _D0_DVI_PORT:
                    case _D0_HDMI_PORT:     
                    case _D0_MHL_PORT:
                    case _D1_DVI_PORT:            
                    case _D1_HDMI_PORT:
                    case _D1_MHL_PORT:                        
                    case _D2_DVI_PORT:
                    case _D2_HDMI_PORT:
                    case _D3_DVI_PORT:
                    case _D3_HDMI_PORT:
                       
                        if(GET_CABLE_DETECT(g_ucSearchIndex) == _TRUE)
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_TMDS, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }
                        else if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)                            
                        {
                            ScalerTimerReactiveTimerEvent(SEC(0.2), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);                        
                        }
                        else
                        {
                            ScalerTimerReactiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);                        
                        }
                        
                        break;

                    case _D0_DP_PORT:
                    case _D1_DP_PORT:            

                        if(GET_CABLE_DETECT(g_ucSearchIndex) == _TRUE)
                        {
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_DP, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        }
                        else if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)                            
                        {
                            ScalerTimerReactiveTimerEvent(SEC(0.2), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);                        
                        }
                        else
                        {
                            ScalerTimerReactiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);                        
                        }
                        
                        break;                        

                    default:
                        break;
                }    
                
                break;

            case _SOURCE_SWITCH_HP_SOURCE_SWITCH:

                if(GET_SOURCE_HP_SWITCH_NO_CABLE() == _TRUE)
                {
                    DebugMessageSystem("5. wuzanne test : No Cable Search 5secs", 0);
                    
                    ScalerTimerReactiveTimerEvent(SEC(6), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                }
                else if(GET_CABLE_DETECT(g_ucSearchIndex) == _FALSE)
                {
                    ScalerTimerReactiveTimerEvent(SEC(0.2), _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                }
                else
                {
                    switch(GET_INPUTPORT_TYPE(g_ucSearchIndex)) 
                    {
                        case _A0_VGA_PORT:

                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_VGA, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);                        
                                 
                            break;

                        case _D0_DVI_PORT:
                        case _D0_HDMI_PORT: 
                        case _D0_MHL_PORT:
                        case _D1_DVI_PORT:            
                        case _D1_HDMI_PORT:
                        case _D1_MHL_PORT:
                        case _D2_DVI_PORT:
                        case _D2_HDMI_PORT:
                        case _D3_DVI_PORT:
                        case _D3_HDMI_PORT:  
                            
                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_TMDS, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                        
                            break;

                        case _D0_DP_PORT:
                        case _D1_DP_PORT:            

                            ScalerTimerReactiveTimerEvent(_SOURCE_DEFAULT_SEARCH_TIME_DP, _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                            
                            break;                        

                        default:
                            break;
                    }    
                }
                
                break;
#endif // End of #if(_HP_SOURCE_SCAN_SUPPORT == _ON)

            default:
                break;                            
        }
    }                              
}

//--------------------------------------------------
// Description  : Judge if the port with source will be chosen
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceJudge(void)
{
    switch(GET_SOURCE_SCAN_TYPE())
    {
        case _SOURCE_SWITCH_FIXED_PORT:
        case _SOURCE_SWITCH_AUTO_IN_GROUP:
        case _SOURCE_SWITCH_AUTO_WITHOUT_GROUP:
        case _SOURCE_SWITCH_DELL_HOTKEY_FIXED:
        case _SOURCE_SWITCH_DELL_HOTKEY_AUTO:

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)            
        case _SOURCE_SWITCH_HP_TIMING_CHANGE:
#endif
            if(GET_SOURCE_TYPE(g_ucSearchIndex) != _SOURCE_NONE)
            { 
                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                
                // Choose Current Source to proceed
                SET_SOURCE_JUDGE(g_ucSearchIndex, _TRUE);

                if(GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_DELL_HOTKEY_FIXED)
                {
                    SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_FIXED_PORT);
                }
                else if(GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_DELL_HOTKEY_AUTO)
                {
                    SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_AUTO_IN_GROUP);
                }                
            }    
            else if(GET_SOURCE_PREDETECT(g_ucSearchIndex))
            {        
                if(GET_SOURCE_SEARCH_TIME_REACTIVE() == _TRUE)
                {                         
                    ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                    
                    SET_SOURCE_DETECTING();

                    SET_SOURCE_SEARCH_TIME_INITIAL();

                    SET_SOURCE_SEARCH_PORT_INITIAL();
                    
#if(_SOURCE_DOUBLE_CHECK_NVRAM_PORT_SUPPORT == _ON)

                    if((GET_SOURCE_SEARCH_CHECK_NVRAM_PORT() == _TRUE) &&
                        (GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) != 0x00) &&
                        (((GET_INPUTPORT_GROUP(g_ucSearchIndex) == GET_INPUTPORT_GROUP(SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT)))) && (GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_AUTO_IN_GROUP)) || (GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_AUTO_WITHOUT_GROUP)) &&
                        (g_ucSearchIndex != SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT))))
                    {                        
                        g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));

                        SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_NVRAM_PORT_MODE);
                    }
                    else
                    {
                        SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_REACTIVE_MODE);

                        CLR_SOURCE_SEARCH_TIME_REACTIVE();
                    }

                    CLR_SOURCE_SEARCH_CHECK_NVRAM_PORT();
                    
#else
                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_REACTIVE_MODE);

                    CLR_SOURCE_SEARCH_TIME_REACTIVE();
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                    if(((GET_INPUT_PORT(g_ucSearchIndex) == _D0_INPUT_PORT) && (GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)) ||
                       ((GET_INPUT_PORT(g_ucSearchIndex) == _D1_INPUT_PORT) && (GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)))
                    {
                        UserInterfaceChangeMHLEDIDData(GET_INPUT_PORT(g_ucSearchIndex));
                    }
#endif
                }
                
                if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
                {
                    SET_TARGET_POWER_STATUS(_POWER_STATUS_NORMAL);
                }
            }

            if(GET_POWER_STATUS() == _POWER_STATUS_NOSUPPORT_SAVING)
            {        
                // For Nosupport Power Saving Mode Change
                SET_TARGET_POWER_STATUS(_POWER_STATUS_NORMAL);
            }

            break;

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)

        case _SOURCE_SWITCH_HP_SOURCE_SCAN:
        case _SOURCE_SWITCH_HP_SOURCE_SWITCH:
        case _SOURCE_SWITCH_HP_OOR_SOURCE_SCAN:            

            if(GET_SOURCE_TYPE(g_ucSearchIndex) != _SOURCE_NONE)
            { 
                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

                if(GET_SOURCE_HP_SOURCE_JUDGE() == _TRUE)
                {                
                    CLR_SOURCE_HP_TARGET_NO_SIGNAL();
                    
                    SET_SOURCE_JUDGE(g_ucSearchIndex, _TRUE);

                    if((GET_SOURCE_HP_TIMING_CHANGE() == _TRUE) && 
                        (g_ucSearchIndex == SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT))))
                    {
                        SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_HP_TIMING_CHANGE);
                    }                    
                }
                else
                {
                    CLR_SOURCE_DETECTING();

                    CLR_MODE_TIMING_CONFIRM();
                }

                DebugMessageSystem("7. wuzanne test : Source Judge HP Case", g_ucSearchIndex);
            }    
            else if(GET_SOURCE_PREDETECT(g_ucSearchIndex))
            {        
                if(GET_SOURCE_SEARCH_TIME_REACTIVE() == _TRUE)
                {                         
                    ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
                    
                    SET_SOURCE_DETECTING();

                    SET_SOURCE_SEARCH_TIME_INITIAL();

                    SET_SOURCE_SEARCH_PORT_INITIAL();
                    
                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_REACTIVE_MODE);

                    CLR_SOURCE_SEARCH_TIME_REACTIVE();
                }
                
                if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
                {
                    SET_TARGET_POWER_STATUS(_POWER_STATUS_NORMAL);
                }
            }

            if(GET_POWER_STATUS() == _POWER_STATUS_NOSUPPORT_SAVING)
            {        
                // For Nosupport Power Saving Mode Change
                SET_TARGET_POWER_STATUS(_POWER_STATUS_NORMAL);
            }            

            break;
#endif // End of #if(_HP_SOURCE_SCAN_SUPPORT == _ON)

        default:

            break;
    }    
}

//--------------------------------------------------
// Description  : Port Switch Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceSwitchPort(void)
{
    BYTE ucCount = 0;
    BYTE ucBackupSearchIndex = g_ucSearchIndex;

    switch(GET_SOURCE_SCAN_TYPE())
    {
        case _SOURCE_SWITCH_FIXED_PORT:

            if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
            {
                INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);

                SET_SOURCE_SWITCH_FINISH();
            }
            
            break;

        case _SOURCE_SWITCH_AUTO_IN_GROUP:
            
            // Switch to the next port by search priority with group limit.
            do 
            {
#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)

                if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
                {
                    INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex); 
                    
                    if(SysSourceCheckTargetTimes(1) == _TRUE)
                    {
                        SET_SOURCE_SWITCH_FINISH();
                    }                    
                }

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_AFTER_NOSIGNAL_STATE)

                if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
                {
                    INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex); 
                    
                    if(SysSourceCheckTargetTimes(1) == _TRUE)
                    {
                        SET_SOURCE_SWITCH_FINISH();

                        if(GET_MODE_STATE() == _MODE_STATUS_SEARCH)
                        {
                            g_ucSearchIndex = ucBackupSearchIndex;
                            
                            return;
                        }                        
                    }                    
                }

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ACER_STYLE)

                if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) <= 1)
                {
                    if(SysSourceCheckTargetTimes(1) == _TRUE)
                    {
                        SET_SOURCE_SWITCH_FINISH();

                        if(GET_MODE_STATE() == _MODE_STATUS_SEARCH)
                        {
                            g_ucSearchIndex = ucBackupSearchIndex;
                            
                            return;
                        }                        
                    }

                    INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);
                }  

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ASUS_STYLE)

                if(GET_SOURCE_ASUS_START_AUTO() == _TRUE)
                {
                    if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
                    {
                        INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);

                        if(SysSourceCheckTargetTimes(1) == _TRUE)
                        {
                            SET_SOURCE_SWITCH_FINISH();
                        }
                    }
                }
                else
                {
                    if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
                    {
                        INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);

                        SET_SOURCE_SWITCH_FINISH();

                        ScalerTimerActiveTimerEvent(_SOURCE_ASUS_START_AUTO_TIME, _SYSTEM_TIMER_EVENT_SOURCE_ASUS_START_AUTO);
                    }

                    return;
                }              
                
#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_DELL_STYLE)

                if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
                {
                    INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);

                    if(SysSourceCheckTargetTimes(1) == _TRUE)
                    {
                        SET_SOURCE_SWITCH_FINISH();
                    }
                }
                
#endif // End of #if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)

                g_ucSearchIndex = (g_ucSearchIndex + 1) % _INPUT_PORT_VALID;

                if(GET_INPUTPORT_GROUP(g_ucSearchIndex) == GET_INPUTPORT_GROUP(ucBackupSearchIndex))
                {
                    break;
                }

                ucCount++;
            }
            while(ucCount < _INPUT_PORT_VALID);

            if(g_ucSearchIndex != ucBackupSearchIndex)
            {                
                SET_SOURCE_SEARCH_TIME_INITIAL();

                SET_SOURCE_SEARCH_PORT_INITIAL();

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)

                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_AFTER_NOSIGNAL_STATE)

                if(GET_MODE_STATE() == _MODE_STATUS_SEARCH)
                {
                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                }
                else
                {
                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);
                }

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ACER_STYLE)

                if(GET_MODE_STATE() == _MODE_STATUS_SEARCH)
                {
                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                }
                else
                {
                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);
                }             
                
#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ASUS_STYLE)

                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_DELL_STYLE)

                pData[1] = 0;
 
                for(pData[0] = 0; pData[0] < _INPUT_PORT_VALID; pData[0]++)
                {
                    if(GET_SOURCE_SEARCH_TIMES(pData[0]) == 1)
                    {
                        pData[1]++;
                    }
                }                

                if(pData[1] >= 2)
                {
                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);
                }
                else
                {
                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                }
#endif
                SET_SOURCE_SEARCH_TIME_REACTIVE();                
            }
            
            break;

        case _SOURCE_SWITCH_AUTO_WITHOUT_GROUP:

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)

            if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
            {
                INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);

                if(SysSourceCheckTargetTimes(1) == _TRUE)
                {
                    SET_SOURCE_SWITCH_FINISH();
                }
            }

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_AFTER_NOSIGNAL_STATE)

            if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
            {
                INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);

                if(SysSourceCheckTargetTimes(1) == _TRUE)
                {
                    SET_SOURCE_SWITCH_FINISH();

                    if(GET_MODE_STATE() == _MODE_STATUS_SEARCH)
                    {
                        return;
                    }                        
                }
            }

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ACER_STYLE)

            if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) <= 1)
            {
                if(SysSourceCheckTargetTimes(1) == _TRUE)
                {
                    SET_SOURCE_SWITCH_FINISH();

                    if(GET_MODE_STATE() == _MODE_STATUS_SEARCH)
                    {
                        return;
                    }                        
                }

                INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);
            }   

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ASUS_STYLE)

            if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
            {
                INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex); 

                if(SysSourceCheckTargetTimes(1) == _TRUE)
                {
                    SET_SOURCE_SWITCH_FINISH();
                }                
            }   

#endif // End of #if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)

            g_ucSearchIndex = (g_ucSearchIndex + 1) % _INPUT_PORT_VALID;

            DebugMessageSystem("7. wuanne test : Search Initial : 3", 0);
            
            SET_SOURCE_SEARCH_TIME_INITIAL();

            SET_SOURCE_SEARCH_PORT_INITIAL();

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_IN_SEARCH_STATE)

            SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);

#elif((_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_AFTER_NOSIGNAL_STATE) || (_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ACER_STYLE))

            if(GET_MODE_STATE() == _MODE_STATUS_SEARCH)
            {
                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
            }
            else
            {
                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);
            }    

#elif(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ASUS_STYLE)

            SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);              
#endif
            SET_SOURCE_SEARCH_TIME_REACTIVE();            

            break;

        case _SOURCE_SWITCH_DELL_HOTKEY_FIXED:
        case _SOURCE_SWITCH_DELL_HOTKEY_AUTO:

            do
            {
                if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
                {
                    INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);

                    if(SysSourceCheckTargetTimes(1) == _TRUE)
                    {
                        SET_SOURCE_SWITCH_FINISH();

                        if(GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_DELL_HOTKEY_FIXED)
                        {
                            g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));
                             
                            SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_FIXED_PORT);
                        }
                        else if(GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_DELL_HOTKEY_AUTO)
                        {
                            SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_AUTO_IN_GROUP);
                        }

                        SET_SOURCE_SEARCH_TIME_INITIAL();

                        SET_SOURCE_SEARCH_PORT_INITIAL();

                        SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

                        SET_SOURCE_SEARCH_TIME_REACTIVE();

                        return;
                    }
                }
                
                g_ucSearchIndex = (g_ucSearchIndex + 1) % _INPUT_PORT_VALID;

                if(GET_INPUTPORT_GROUP(g_ucSearchIndex) == GET_INPUTPORT_GROUP(ucBackupSearchIndex))
                {
                    break;
                }

                ucCount++;
            }
            while(ucCount < _INPUT_PORT_VALID);

            if(g_ucSearchIndex != ucBackupSearchIndex)
            {
                SET_SOURCE_SEARCH_TIME_INITIAL();

                SET_SOURCE_SEARCH_PORT_INITIAL();

                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

                SET_SOURCE_SEARCH_TIME_REACTIVE();
            }

            break;

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)

        case _SOURCE_SWITCH_HP_SOURCE_SCAN:

            CLR_SOURCE_HP_SOURCE_JUDGE();

            if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) < GET_SOURCE_HP_TARGET_SEARCH_TIMES())
            {
                INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);                         

                DebugMessageSystem("7. wuzanne test : == SearchIndex ==", g_ucSearchIndex);
                DebugMessageSystem("7. wuzanee test : Search Times", GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex));
            }               

            if((SysSourceCheckTargetTimes(1) == _TRUE) || 
                (SysSourceCheckTargetTimes(2) == _TRUE) || 
                (SysSourceCheckTargetTimes(3) == _TRUE))                
            {      
                if(UserCommonNVRamGetSystemData(_SOURCE_HP_AUTO_SEARCH) == _TRUE)
                {
                    if((GET_SOURCE_HP_PORT_SWITCH_TARGET() < _INPUT_PORT_VALID) && (GET_CABLE_DETECT(GET_SOURCE_HP_PORT_SWITCH_TARGET()) == _TRUE))
                    {
                        if(GET_SOURCE_TYPE(GET_SOURCE_HP_PORT_SWITCH_TARGET()) != _SOURCE_NONE)
                        {
                            g_ucSearchIndex = GET_SOURCE_HP_PORT_SWITCH_TARGET();

                            DebugMessageSystem("7. wuzanne test : Bingo Switch Port!!!!!!!", 0); 

                            SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);

                            SET_SOURCE_SEARCH_TIME_INITIAL();

                            SET_SOURCE_SEARCH_PORT_INITIAL();

                            SET_SOURCE_SEARCH_TIME_REACTIVE(); 

                            SET_SOURCE_HP_SOURCE_JUDGE();

                            CLR_SOURCE_PREDETECT(g_ucSearchIndex);

                            SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

                            SET_SOURCE_HP_PORT_SWITCH_TARGET((_INPUT_PORT_VALID + 1));

                            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_SOURCE_HP_CANCEL_MANUAL_SWITCH_PORT);                            
                            
                            return;                         
                        }
                    }
                    else
                    {
                        if(GET_SOURCE_HP_PORT_SWITCH_TARGET() < _INPUT_PORT_VALID)
                        {
                            if(GET_SOURCE_TYPE(GET_SOURCE_HP_PORT_SWITCH_TARGET()) != _SOURCE_NONE)
                            {
                                g_ucSearchIndex = GET_SOURCE_HP_PORT_SWITCH_TARGET();

                                DebugMessageSystem("7. wuzanne test : Bingo Switch Port!!!!!!!", 0); 

                                SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);

                                SET_SOURCE_SEARCH_TIME_INITIAL();

                                SET_SOURCE_SEARCH_PORT_INITIAL();

                                SET_SOURCE_SEARCH_TIME_REACTIVE(); 

                                SET_SOURCE_HP_SOURCE_JUDGE();

                                CLR_SOURCE_PREDETECT(g_ucSearchIndex);

                                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

                                SET_SOURCE_HP_PORT_SWITCH_TARGET((_INPUT_PORT_VALID + 1));

                                ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_SOURCE_HP_CANCEL_MANUAL_SWITCH_PORT);                            
                                
                                return;                         
                            }
                        }
                        
                        if(GET_SOURCE_TYPE(SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT))) != _SOURCE_NONE)
                        {
                            g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));
    
                            DebugMessageSystem("7. wuzanne test : Bingo Eeprom!!!!!!!", g_ucSearchIndex);
    
                            SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);
    
                            SET_SOURCE_SEARCH_TIME_INITIAL();
    
                            SET_SOURCE_SEARCH_PORT_INITIAL();
    
                            SET_SOURCE_SEARCH_TIME_REACTIVE(); 
    
                            SET_SOURCE_HP_SOURCE_JUDGE();
    
                            CLR_SOURCE_PREDETECT(g_ucSearchIndex);
    
                            SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                            
                            return;                    
                        }                
    
                        if(GET_SOURCE_TYPE(SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SOURCE_HP_DEFAULT_PORT))) != _SOURCE_NONE)
                        {
                            g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SOURCE_HP_DEFAULT_PORT));;
    
                            DebugMessageSystem("7. wuzanne test : Bingo Defautlt!!!!!!!", g_ucSearchIndex);
    
                            SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);
    
                            SET_SOURCE_SEARCH_TIME_INITIAL();
    
                            SET_SOURCE_SEARCH_PORT_INITIAL();
    
                            SET_SOURCE_SEARCH_TIME_REACTIVE(); 
    
                            SET_SOURCE_HP_SOURCE_JUDGE();
    
                            CLR_SOURCE_PREDETECT(g_ucSearchIndex);
    
                            SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                            
                            return;                    
                        }
    
                        for(pData[0] = 0; pData[0] < _INPUT_PORT_VALID; pData[0]++)
                        {
                            if(GET_SOURCE_TYPE(pData[0]) != _SOURCE_NONE)
                            {
                                g_ucSearchIndex = pData[0];
    
                                DebugMessageSystem("7. wuzanne test : Bingo Priority!!!!!!!", g_ucSearchIndex);
    
                                SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);
    
                                SET_SOURCE_SEARCH_TIME_INITIAL();
    
                                SET_SOURCE_SEARCH_PORT_INITIAL();
    
                                SET_SOURCE_SEARCH_TIME_REACTIVE(); 
    
                                SET_SOURCE_HP_SOURCE_JUDGE();
    
                                CLR_SOURCE_PREDETECT(g_ucSearchIndex);
    
                                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                                
                                return;
                            }
                        }     
                    }
                }
                else
                {
                    if(GET_SOURCE_TYPE(SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT))) != _SOURCE_NONE)
                    {
                        DebugMessageSystem("7. wuzanne test : Bingo Eeprom Fix Port!!!!!!!", g_ucSearchIndex);

                        g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));

                        SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);

                        SET_SOURCE_SEARCH_TIME_INITIAL();

                        SET_SOURCE_SEARCH_PORT_INITIAL();

                        SET_SOURCE_SEARCH_TIME_REACTIVE(); 

                        SET_SOURCE_HP_SOURCE_JUDGE();

                        CLR_SOURCE_PREDETECT(g_ucSearchIndex);

                        SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                        
                        return;                    
                    }
                }

                if((GET_MODE_STATE() == _MODE_STATUS_SEARCH) && (SysSourceCheckTargetTimes(1) == _TRUE)) 
                {
                    pData[1] = 0;
                    
                    for(pData[0] = 0; pData[0] < _INPUT_PORT_VALID; pData[0]++)
                    {
                        pData[1] = pData[1] | GET_CABLE_DETECT(pData[0]);
                    }

                    if(pData[1] == 0)
                    {
                        SET_SOURCE_HP_TARGET_SEARCH_TIMES(1);         
                    }
                }                       
            }
                         
            if((GET_MODE_STATE() == _MODE_STATUS_SEARCH) && (SysSourceCheckTargetTimes(GET_SOURCE_HP_TARGET_SEARCH_TIMES()) == _TRUE))  
            {                
                if(GET_SOURCE_HP_PORT_SWITCH_TARGET() > _INPUT_PORT_VALID)
                {
                    DebugMessageSystem("7. wuzanne test : Search Finish !!!!!!!!!!!!!!!!!!!", g_ucSearchIndex);
                    CLR_SOURCE_HP_TARGET_NO_SIGNAL();//Vincent 20130326 Source
                    SET_SOURCE_SWITCH_FINISH();
                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);
                }
                else
                {
                    SET_SOURCE_HP_TARGET_NO_SIGNAL();
                    ScalerTimerActiveTimerEvent(SEC(5), _SYSTEM_TIMER_EVENT_SOURCE_HP_CANCEL_MANUAL_SWITCH_PORT);
                }
            }

            if((UserCommonNVRamGetSystemData(_SOURCE_HP_AUTO_SEARCH) == _TRUE) || 
                (((UserCommonNVRamGetSystemData(_SOURCE_HP_AUTO_SEARCH) == _FALSE)) && 
                  (GET_MODE_STATE() == _MODE_STATUS_SEARCH)))
            {
                g_ucSearchIndex = (g_ucSearchIndex + 1) % _INPUT_PORT_VALID;            
            }
            else
            {
                g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));
            }
            
            if(GET_MODE_STATE() == _MODE_STATUS_NOSIGNAL)
            {                
                SET_SOURCE_HP_SOURCE_JUDGE();
                
                if(UserCommonNVRamGetSystemData(_SOURCE_HP_AUTO_SEARCH) == _FALSE)
                {
                    g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));                    
                }
            }
            else if(GET_MODE_STATE() == _MODE_STATUS_POWER_SAVING)
            {
                SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_HP_TIMING_CHANGE);

                if(UserCommonNVRamGetSystemData(_SOURCE_HP_AUTO_SEARCH) == _FALSE)
                {
                    g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));                    
                }
            }
                
            SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);

            SET_SOURCE_SEARCH_TIME_INITIAL();

            SET_SOURCE_SEARCH_PORT_INITIAL();

            SET_SOURCE_SEARCH_TIME_REACTIVE();            
            
            CLR_SOURCE_PREDETECT(g_ucSearchIndex);
            
            break;

        case _SOURCE_SWITCH_HP_TIMING_CHANGE:

            if(GET_MODE_STATE() == _MODE_STATUS_SEARCH)
            {
                g_ucSearchIndex = 0;

                SET_SOURCE_SEARCH_TIME_INITIAL();

                SET_SOURCE_SEARCH_PORT_INITIAL();

                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

                SET_SOURCE_SEARCH_TIME_REACTIVE();     

                SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_HP_SOURCE_SCAN);

                SET_SOURCE_HP_TIMING_CHANGE();

                SET_SOURCE_HP_TARGET_SEARCH_TIMES(1);

                CLR_SOURCE_HP_SOURCE_JUDGE();                

                CLR_SOURCE_PREDETECT(g_ucSearchIndex);

                return;
            }
           
            if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) == 0x00)
            {
                INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);

                if(SysSourceCheckTargetTimes(1) == _TRUE)
                {
                    SET_SOURCE_SWITCH_FINISH();
                }
            }

            if(UserCommonNVRamGetSystemData(_SOURCE_HP_AUTO_SEARCH) == _TRUE)
            {
                g_ucSearchIndex = (g_ucSearchIndex + 1) % _INPUT_PORT_VALID;
            }            
            
            SET_SOURCE_SEARCH_TIME_INITIAL();

            SET_SOURCE_SEARCH_PORT_INITIAL();

            SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);

            SET_SOURCE_SEARCH_TIME_REACTIVE();            

            break;

        case _SOURCE_SWITCH_HP_SOURCE_SWITCH:
            
            if(UserCommonNVRamGetSystemData(_SOURCE_HP_AUTO_SEARCH) == _TRUE)
            {
                if(GET_SOURCE_HP_SWITCH_NO_CABLE() == _FALSE)
                {
                    if(GET_SOURCE_TYPE(g_ucSearchIndex) != _SOURCE_NONE)
                    {
                        for(pData[0] = 0; pData[0] < _INPUT_PORT_VALID; pData[0]++)
                        {
                            CLR_SOURCE_SEARCH_TIMES(pData[0]);                    
                        }

                        SET_SOURCE_HP_TARGET_SEARCH_TIMES(1);

                        DebugMessageSystem("5. wuzanne test : Switch Port with Signal", GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex));
                    }
                    else
                    {
                        if(GET_CABLE_DETECT(g_ucSearchIndex) == _FALSE)
                        {
                            SET_SOURCE_HP_SWITCH_NO_CABLE();

                            SET_SOURCE_SEARCH_TIME_INITIAL();

                            DebugMessageSystem("5. wuzanne test : Switch Port No Cable", GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex));

                            return;
                        }
                        else
                        {
                            for(pData[0] = 0; pData[0] < _INPUT_PORT_VALID; pData[0]++)
                            {
                                CLR_SOURCE_SEARCH_TIMES(pData[0]);
                                INCREASE_SOURCE_SEARCH_TIMES(pData[0]);
                            }                                    

                            SET_SOURCE_HP_TARGET_SEARCH_TIMES(3);

                            DebugMessageSystem("5. wuzanne test : Switch Port No Signal", GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex));
                        }
                    }
                
                }
                else
                {
                    CLR_SOURCE_HP_SWITCH_NO_CABLE();

                    for(pData[0] = 0; pData[0] < _INPUT_PORT_VALID; pData[0]++)
                    {
                        CLR_SOURCE_SEARCH_TIMES(pData[0]);
                    }                                    

                    SET_SOURCE_HP_TARGET_SEARCH_TIMES(3);

                    DebugMessageSystem("5. wuzanne test : Switch Port No Cable Finish", GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex));                
                }
            
                g_ucSearchIndex = 0;
            
            }
            else
            {
                if(GET_SOURCE_TYPE(g_ucSearchIndex) == _SOURCE_NONE)            
                {
                    for(pData[0] = 0; pData[0] < _INPUT_PORT_VALID; pData[0]++)
                    {
                        CLR_SOURCE_SEARCH_TIMES(pData[0]);
                        
                        INCREASE_SOURCE_SEARCH_TIMES(pData[0]);
                    }
                    
                    if(GET_CABLE_DETECT(g_ucSearchIndex) == _FALSE)
                    {                        
                        SET_SOURCE_HP_TARGET_SEARCH_TIMES(1);
                    }
                    else
                    {
                        SET_SOURCE_HP_TARGET_SEARCH_TIMES(3);
                        
                        g_ucSearchIndex = 0;
                    }
                }
                else
                {
                    for(pData[0] = 0; pData[0] < _INPUT_PORT_VALID; pData[0]++)
                    {
                        CLR_SOURCE_SEARCH_TIMES(pData[0]);
                    }  
                    
                    SET_SOURCE_HP_TARGET_SEARCH_TIMES(1);
                }
                                
            }

            SET_SOURCE_SEARCH_TIME_INITIAL();

            SET_SOURCE_SEARCH_PORT_INITIAL();

            SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

            SET_SOURCE_SEARCH_TIME_REACTIVE();     

            SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_HP_SOURCE_SCAN);

            CLR_SOURCE_HP_TIMING_CHANGE();

            CLR_SOURCE_HP_SOURCE_JUDGE(); 

            CLR_SOURCE_PREDETECT(g_ucSearchIndex);

            break;

        case _SOURCE_SWITCH_HP_OOR_SOURCE_SCAN:

            CLR_SOURCE_HP_SOURCE_JUDGE();

            if(GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex) < GET_SOURCE_HP_TARGET_SEARCH_TIMES())
            {
                INCREASE_SOURCE_SEARCH_TIMES(g_ucSearchIndex);                         

                DebugMessageSystem("7. wuzanne test : == SearchIndex ==", g_ucSearchIndex);
                DebugMessageSystem("7. wuzanee test : Search Times", GET_SOURCE_SEARCH_TIMES(g_ucSearchIndex));
            }               

            if(SysSourceCheckTargetTimes(1) == _TRUE)
            {      
                if((GET_SOURCE_TYPE(SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SOURCE_HP_DEFAULT_PORT))) != _SOURCE_NONE) &&
                    (UserCommonNVRamGetSystemData(_SOURCE_HP_DEFAULT_PORT) != UserCommonNVRamGetSystemData(_SEARCH_PORT)))
                {
                    g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SOURCE_HP_DEFAULT_PORT));;

                    DebugMessageSystem("7. wuzanne test : Bingo Defautlt!!!!!!!", g_ucSearchIndex);

                    SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);

                    SET_SOURCE_SEARCH_TIME_INITIAL();

                    SET_SOURCE_SEARCH_PORT_INITIAL();

                    SET_SOURCE_SEARCH_TIME_REACTIVE(); 

                    SET_SOURCE_HP_SOURCE_JUDGE();

                    CLR_SOURCE_PREDETECT(g_ucSearchIndex);

                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

                    SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_HP_SOURCE_SCAN);
                    
                    return;                    
                }

                for(pData[0] = 0; pData[0] < _INPUT_PORT_VALID; pData[0]++)
                {
                    if((GET_SOURCE_TYPE(pData[0]) != _SOURCE_NONE) && 
                        (SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT)) != pData[0]))
                    {
                        g_ucSearchIndex = pData[0];

                        DebugMessageSystem("7. wuzanne test : Bingo Priority!!!!!!!", g_ucSearchIndex);

                        SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);

                        SET_SOURCE_SEARCH_TIME_INITIAL();

                        SET_SOURCE_SEARCH_PORT_INITIAL();

                        SET_SOURCE_SEARCH_TIME_REACTIVE(); 

                        SET_SOURCE_HP_SOURCE_JUDGE();

                        CLR_SOURCE_PREDETECT(g_ucSearchIndex);

                        SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

                        SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_HP_SOURCE_SCAN);                        
                        
                        return;
                    }
                }     

                if(GET_SOURCE_TYPE(SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT))) != _SOURCE_NONE)
                {
                    g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));

                    DebugMessageSystem("7. wuzanne test : Bingo Eeprom!!!!!!!", g_ucSearchIndex);

                    SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);

                    SET_SOURCE_SEARCH_TIME_INITIAL();

                    SET_SOURCE_SEARCH_PORT_INITIAL();

                    SET_SOURCE_SEARCH_TIME_REACTIVE(); 

                    SET_SOURCE_HP_SOURCE_JUDGE();

                    CLR_SOURCE_PREDETECT(g_ucSearchIndex);

                    SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
                    
                    return;                    
                }                                    
            }
                         
            if((GET_MODE_STATE() == _MODE_STATUS_SEARCH) && (SysSourceCheckTargetTimes(GET_SOURCE_HP_TARGET_SEARCH_TIMES()) == _TRUE))  
            {                
                DebugMessageSystem("7. wuzanne test : Search Finish !!!!!!!!!!!!!!!!!!!", g_ucSearchIndex);
                SET_SOURCE_SWITCH_FINISH();
                SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_POLLING_MODE);
                SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_HP_SOURCE_SCAN);
                SET_SOURCE_HP_PORT_SWITCH_TARGET((_INPUT_PORT_VALID + 1));
            }

            g_ucSearchIndex = (g_ucSearchIndex + 1) % _INPUT_PORT_VALID;                      
                
            SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_NONE);

            SET_SOURCE_SEARCH_TIME_INITIAL();

            SET_SOURCE_SEARCH_PORT_INITIAL();

            SET_SOURCE_SEARCH_TIME_REACTIVE();            
            
            CLR_SOURCE_PREDETECT(g_ucSearchIndex);

            break;

#endif // End of #if(_HP_SOURCE_SCAN_SUPPORT == _ON)

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Port Initial Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceScanPortInitial(void)
{
    ScalerSyncInterfaceSwitch(GET_INPUTPORT_TYPE(g_ucSearchIndex), GET_SOURCE_SEARCH_DELAY_MODE());                
    
    switch(GET_INPUTPORT_TYPE(g_ucSearchIndex))
    {
#if(_VGA_SUPPORT == _ON)
        case _A0_VGA_PORT:

            DebugMessageSystem("7. VGA Port Initial", 1);

            if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
            {     
                ScalerSyncVgaScanInitial();
            }          
            
            break;
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

        case _D0_DVI_PORT:
        case _D1_DVI_PORT:
        case _D2_DVI_PORT:
        case _D3_DVI_PORT:            
        case _D0_HDMI_PORT:                        
        case _D1_HDMI_PORT:
        case _D2_HDMI_PORT:                        
        case _D3_HDMI_PORT:
        case _D0_MHL_PORT:
        case _D1_MHL_PORT:

            DebugMessageSystem("7. TMDS Port Initial", 1);
            
            if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
            {                                 
                ScalerSyncTmdsScanInitial(GET_INPUT_PORT(g_ucSearchIndex));
            }
            
            break;
#endif

#if(_DP_SUPPORT == _ON)
        case _D0_DP_PORT:
        case _D1_DP_PORT:            

            DebugMessageSystem("7. DP Port Initial", 1);

            if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
            {                     
                ScalerSyncDpScanInitial();
            }    
                        
            break;
#endif


#if(_DP_DUAL_MODE_SUPPORT == _ON)

        case _D1_DP_DUAL_PORT:
            
            if(GET_POWER_STATUS() == _POWER_STATUS_NORMAL)
            {             
                if(GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS)
                {
                    ScalerSyncTmdsScanInitial(GET_INPUT_PORT(g_ucSearchIndex));
                }
                else
                {
                    ScalerSyncDpScanInitial();
                }                
            }    
                        
            break;            
#endif
        default:

            break;
    }        
}

//--------------------------------------------------
// Description  : Initial Source Switch Flags
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceInitial(void)
{    
    BYTE ucPort = 0;

    SysSourceSetSearchPriority(_NO_INPUT_PORT, _INPUT_PORT_PRIORITY_NONE);
    SysSourceSetSearchGroup(_NO_INPUT_PORT, _INPUT_PORT_GROUP_NONE);
    
#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
    g_ucSearchIndex = 0;

    SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_HP_SOURCE_SCAN); 

    CLR_SOURCE_HP_TIMING_CHANGE();

    SET_SOURCE_HP_TARGET_SEARCH_TIMES(3);  

    SET_SOURCE_HP_PORT_SWITCH_TARGET((_INPUT_PORT_VALID + 1));
#else
    if((UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != _SOURCE_SWITCH_AUTO_IN_GROUP) &&
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != _SOURCE_SWITCH_AUTO_WITHOUT_GROUP) &&
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != _SOURCE_SWITCH_FIXED_PORT))
    {
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
        UserCommonEepromRestoreSystemData();
#else
        UserCommonFlashRestoreSystemData();
#endif
    }
    
    g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));

    SET_SOURCE_SCAN_TYPE(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE)); 
#endif       

    for(ucPort = 0; ucPort< _INPUT_PORT_VALID; ucPort++)
    {
        SET_CABLE_DETECT(ucPort, _FALSE);
    }   

#if(_DIGITAL_PORT_SUPPORT == _ON)
    if(UserCommonNVRamGetSystemData(_HDMI_HOT_PLUG_SUPPORT) == _TRUE)
    {
        SET_HDMI_HOTPLUG_TOGGLE();
        SET_HDMI_HOTPLUG_TIME(UserCommonNVRamGetSystemData(_HDMI_HOT_PLUG_SUPPORT_TIME));
    }
    else
    {        
        CLR_HDMI_HOTPLUG_TOGGLE();              
    }
#endif
}

//--------------------------------------------------
// Description  : Source Stable Check Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit SysSourceStableCheck(void)
{
    switch(GET_SOURCE_TYPE(g_ucSearchIndex))
    {
#if(_VGA_SUPPORT == _ON)        
        case _SOURCE_VGA:
            
            return (bit)ScalerSyncVgaStableDetect();
            
            break;
#endif

#if(_DVI_SUPPORT == _ON)
        case _SOURCE_DVI:

            return (bit)ScalerSyncTmdsStableDetect(_SOURCE_DVI);

            break;
#endif

#if(_HDMI_SUPPORT == _ON)
        case _SOURCE_HDMI:
            
            return (bit)ScalerSyncTmdsStableDetect(_SOURCE_HDMI);
            
            break;
#endif

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:

            return (bit)ScalerSyncDpStableDetect();
            
            break;
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Source Type
// Input Value  : None
// Output Value : Source Type --> VGA/DVI/HDMI/DP
//--------------------------------------------------
BYTE SysSourceGetSourceType(void)
{
    return GET_SOURCE_TYPE(g_ucSearchIndex);
}

//--------------------------------------------------
// Description  : Get Input Port Type
// Input Value  : None
// Output Value : ucInputPort --> Input Port Type
//--------------------------------------------------
BYTE SysSourceGetInputPort(void)
{
    return GET_INPUT_PORT(g_ucSearchIndex);
}

//--------------------------------------------------
// Description  : Get Input Port
// Input Value  : Search Index
// Output Value : ucInputPort --> Input Port
//--------------------------------------------------
BYTE SysSourceGetSpecificInputPort(BYTE ucIndex)
{
    return GET_INPUT_PORT(ucIndex);
}

#if(_SLEEP_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Current Playback Search Index
// Input Value  : None
// Output Value : Search Index
//--------------------------------------------------
BYTE SysSourceGetAudioPlaybackPort(void)
{
    return GET_INPUT_PORT(GET_AUDIO_PLAYBACK_SEARCH_INDEX());
}
#endif

//--------------------------------------------------
// Description  : Get Source Type
// Input Value  : ucInputPort --> Input Port(A0,A1,D0,D1,V1)
// Output Value : None
//--------------------------------------------------
void SysSourceSwitchInputPort(BYTE ucInputPort)
{
    switch(GET_SOURCE_SCAN_TYPE())
    {
#if(_HP_SOURCE_SCAN_SUPPORT == _ON)

        case _SOURCE_SWITCH_HP_SOURCE_SCAN:
        case _SOURCE_SWITCH_HP_SOURCE_SWITCH:
        case _SOURCE_SWITCH_HP_TIMING_CHANGE:

            if(GET_SOURCE_TYPE(g_ucSearchIndex) == _SOURCE_NONE)
            {
                UserCommonNVRamSetSystemData(_SEARCH_PORT, ucInputPort);
            }

            g_ucSearchIndex = SysSourceConvertSearchPort(ucInputPort); 

            DebugMessageSystem("7. wuzanne test : OSD Switch Port to --> ", SysSourceConvertSearchPort(ucInputPort));

            if(UserCommonNVRamGetSystemData(_SOURCE_HP_AUTO_SEARCH) == _TRUE)
            {
                SET_SOURCE_HP_PORT_SWITCH_TARGET(SysSourceConvertSearchPort(ucInputPort));
            }
            else
            {
                SET_SOURCE_HP_PORT_SWITCH_TARGET((_INPUT_PORT_VALID + 1));

                UserCommonNVRamSetSystemData(_SEARCH_PORT, ucInputPort);
            }

            CLR_SOURCE_HP_SOURCE_JUDGE();

            CLR_SOURCE_HP_SWITCH_NO_CABLE();

            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_SOURCE_HP_CANCEL_MANUAL_SWITCH_PORT);

            break;

        case _SOURCE_SWITCH_HP_OOR_SOURCE_SCAN:
            
            g_ucSearchIndex = 0;

            CLR_SOURCE_HP_SOURCE_JUDGE();            

            CLR_SOURCE_HP_TIMING_CHANGE();

            SET_SOURCE_HP_TARGET_SEARCH_TIMES(1);  

            SET_SOURCE_HP_PORT_SWITCH_TARGET((_INPUT_PORT_VALID + 1));     

            SysSourceInfoReset();

            break;
#endif
        default:

            g_ucSearchIndex = SysSourceConvertSearchPort(ucInputPort); 

            break;
    }   
}


//--------------------------------------------------
// Description  : Source Information Reset 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceInfoReset(void)
{
    BYTE ucCnt = 0x00;

    SET_SOURCE_SEARCH_PORT_INITIAL();

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ASUS_STYLE)

    if(GET_MODE_STATE() != _MODE_STATUS_POWER_SAVING)
    {
        CLR_SOURCE_ASUS_START_AUTO();
        ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_SOURCE_ASUS_START_AUTO);
    }
    
#endif

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
    if((GET_MODE_STATE() != _MODE_STATUS_SEARCH) || (GET_SOURCE_JUDGE(g_ucSearchIndex) == _TRUE))
#else
    if((GET_MODE_STATE() != _MODE_STATUS_SEARCH) || (UserInterfaceCheckCableReset() == _TRUE) || (GET_SOURCE_JUDGE(g_ucSearchIndex) == _TRUE))
#endif
    {        
        // Clear Source Flags
        SET_SOURCE_DETECTING();        
        SET_SOURCE_SEARCH_TIME_INITIAL();
        CLR_SOURCE_SWITCH_FINISH();
        SET_SOURCE_SEARCH_TIME_REACTIVE();

#if(_SOURCE_DOUBLE_CHECK_NVRAM_PORT_SUPPORT == _ON)

        if((GET_MODE_STATE() == _MODE_STATUS_POWER_OFF) || ((GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_DELAY_REACTIVE_MODE) && (GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_DELAY_NVRAM_PORT_MODE)))
        {
            SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);

            SET_SOURCE_SEARCH_CHECK_NVRAM_PORT();
        }          
#else
        if((GET_MODE_STATE() == _MODE_STATUS_POWER_OFF) || (GET_SOURCE_SEARCH_DELAY_MODE() != _SOURCE_SEARCH_DELAY_REACTIVE_MODE))
        {
            SET_SOURCE_SEARCH_DELAY_MODE(_SOURCE_SEARCH_DELAY_DEFAULT_MODE);
        }  
#endif
        ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING);
    }

    for(ucCnt = 0; ucCnt < _INPUT_PORT_VALID; ucCnt++)
    {
        // Interface Reset Process
        if(GET_SOURCE_SCAN_TYPE() != _SOURCE_SWITCH_HP_SOURCE_SCAN)
        {
            SET_SOURCE_TYPE(ucCnt, _SOURCE_NONE);
        }
        
        CLR_SOURCE_SEARCH_TIMES(ucCnt);
        CLR_SOURCE_JUDGE(ucCnt);
        CLR_SOURCE_PREDETECT(ucCnt);
    }
}

//--------------------------------------------------
// Description  : Source Cable Status Detection 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceCableDetection(void)
{
    BYTE ucI = 0;

    // Get Each Cable Status From Pin
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)            
    PCB_A0_PIN();
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    PCB_D0_PIN();
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    PCB_D1_PIN();
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
    PCB_D2_PIN();
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
    PCB_D3_PIN();
#endif

    for(ucI = 0; ucI < _INPUT_PORT_VALID; ucI++)
    {
        SET_CABLE_STATUS_CHANGE(ucI, _FALSE);
        
        switch(GET_INPUT_PORT(ucI))
        {

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)            

            case _A0_INPUT_PORT:
                if(GET_CABLE_DETECT(ucI) != GET_A0_CABLE_STATUS())
                {
                    ScalerTimerDelayXms(10);
                    
                    PCB_A0_PIN();
                    
                    if(GET_CABLE_DETECT(ucI) != GET_A0_CABLE_STATUS())
                    {
                        SET_CABLE_DETECT(ucI, GET_A0_CABLE_STATUS());
                        SET_CABLE_STATUS_CHANGE(ucI, _TRUE);
                        
                        DebugMessageSystem("0. Cable Status Chanaged A0", ucI);	
                    }
                }
                break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)            

            case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
                if((GET_CABLE_DETECT(ucI) != GET_D0_CABLE_STATUS()) || (GET_D0_TMDS_MODE() != PCB_D0_MHL_DETECT()))
#else
                if(GET_CABLE_DETECT(ucI) != GET_D0_CABLE_STATUS())
#endif

                {
                    ScalerTimerDelayXms(10);
                    
                    PCB_D0_PIN();

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
                    if((GET_CABLE_DETECT(ucI) != GET_D0_CABLE_STATUS()) || (GET_D0_TMDS_MODE() != PCB_D0_MHL_DETECT()))
#else
                    if(GET_CABLE_DETECT(ucI) != GET_D0_CABLE_STATUS())
#endif

                    {

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                        if(GET_D0_CABLE_STATUS() == _TRUE)
                        {    
                            if((UserCommonNVRamGetSystemData(_DP_HOT_PLUG_DC_OFF_HIGH) == _ON) || (GET_POWER_STATUS() != _POWER_STATUS_OFF))
                            {
                                ScalerTimerReactiveTimerEvent(SEC(0.1), _SCALER_TIMER_EVENT_DP_HOTPLUG_ASSERTED);                                                                                        
                            }                            
                        }
                        else
                        {
                            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HOTPLUG_ASSERTED);
                            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT);
                            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ);
                            PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                        }

#elif(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
                        SET_D0_TMDS_MODE(_TMDS_MHL_MODE);
#else
                        SET_D0_TMDS_MODE(PCB_D0_MHL_DETECT());
#endif

                        if(GET_D0_CABLE_STATUS() == _TRUE)
                        {
                            if(GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)
                            {
                                ScalerMHLModeMHLSetting(GET_INPUT_PORT(ucI));
                            }
                            else
                            {
                                ScalerMHLModeHdmiSetting(GET_INPUT_PORT(ucI));
                            }
                        }
                        else
                        {
                            ScalerMHLModeHdmiSetting(GET_INPUT_PORT(ucI));
                        }

                        SET_SOURCE_SEARCH_PORT_INITIAL();

#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

                        SET_CABLE_DETECT(ucI, GET_D0_CABLE_STATUS());
                        SET_CABLE_STATUS_CHANGE(ucI, _TRUE);         

                        DebugMessageSystem("0. Cable Status Chanaged D0", ucI);	                        
                    }
                }
                break;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT) 

            case _D1_INPUT_PORT:
                
#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
                if((GET_CABLE_DETECT(ucI) != GET_D1_CABLE_STATUS()) || (GET_D1_TMDS_MODE() != PCB_D1_MHL_DETECT()))
#else
                if(GET_CABLE_DETECT(ucI) != GET_D1_CABLE_STATUS())
#endif
                {
                    ScalerTimerDelayXms(10);
                    
                    PCB_D1_PIN();
                    
#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
                    if((GET_CABLE_DETECT(ucI) != GET_D1_CABLE_STATUS()) || (GET_D1_TMDS_MODE() != PCB_D1_MHL_DETECT()))
#else
                    if(GET_CABLE_DETECT(ucI) != GET_D1_CABLE_STATUS())
#endif

                    {

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
                        if(GET_D1_CABLE_STATUS() == _TRUE)
                        {
                            if((UserCommonNVRamGetSystemData(_DP_HOT_PLUG_DC_OFF_HIGH) == _ON) || (GET_POWER_STATUS() != _POWER_STATUS_OFF))
                            {
                                ScalerTimerReactiveTimerEvent(SEC(0.1), _SCALER_TIMER_EVENT_DP_HOTPLUG_ASSERTED);                                                                                        
                            }  
                        }
                        else
                        {
                            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HOTPLUG_ASSERTED);
                            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT);
                            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ);
                            PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                        }
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT)

                        PCB_D1_DP_DUAL_PIN();

                        if(GET_D1_CABLE_STATUS() == _TRUE)
                        {
                            if(GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_DP)
                            {                                
                                ScalerDpDualModeDpSetting();

                                if((UserCommonNVRamGetSystemData(_DP_HOT_PLUG_DC_OFF_HIGH) == _ON) || (GET_POWER_STATUS() != _POWER_STATUS_OFF))
                                {
                                    ScalerTimerReactiveTimerEvent(SEC(0.1), _SCALER_TIMER_EVENT_DP_HOTPLUG_ASSERTED);                                                                                        
                                }    
                            }
                            else
                            {
                                SET_SOURCE_SEARCH_PORT_INITIAL();
                                ScalerDpDualModeTmdsSetting();
                                PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
                            }
                        }
                        else
                        {
                            SET_SOURCE_SEARCH_PORT_INITIAL();
                            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HOTPLUG_ASSERTED);
                            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT);
                            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ);
                            PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                        }

#elif(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
                        SET_D1_TMDS_MODE(_TMDS_MHL_MODE);
#else
                        SET_D1_TMDS_MODE(PCB_D1_MHL_DETECT());
#endif

                        if(GET_D1_CABLE_STATUS() == _TRUE)
                        {
                            if(GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)
                            {         
                                ScalerMHLModeMHLSetting(GET_INPUT_PORT(ucI));
                            }
                            else
                            {
                                ScalerMHLModeHdmiSetting(GET_INPUT_PORT(ucI));
                            }
                        }
                        else
                        {
                            ScalerMHLModeHdmiSetting(GET_INPUT_PORT(ucI));
                        }
                        
                        SET_SOURCE_SEARCH_PORT_INITIAL();
#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

                        SET_CABLE_DETECT(ucI, GET_D1_CABLE_STATUS());
                        SET_CABLE_STATUS_CHANGE(ucI, _TRUE);                        

                        DebugMessageSystem("0. Cable Status Chanaged D1", ucI);	                        
                    }
                }
                break;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)            

            case _D2_INPUT_PORT:
                if(GET_CABLE_DETECT(ucI) != GET_D2_CABLE_STATUS())
                {
                    ScalerTimerDelayXms(10);

                    PCB_D2_PIN();
                    
                    if(GET_CABLE_DETECT(ucI) != GET_D2_CABLE_STATUS())
                    {
                        SET_CABLE_DETECT(ucI, GET_D2_CABLE_STATUS());
                        SET_CABLE_STATUS_CHANGE(ucI, _TRUE);                        

                        DebugMessageSystem("0. Cable Status Chanaged D2", ucI);	                        
                    }
                }
                break;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)            

            case _D3_INPUT_PORT:
                if(GET_CABLE_DETECT(ucI) != GET_D3_CABLE_STATUS())
                {
                    ScalerTimerDelayXms(10);

                    PCB_D2_PIN();
                    
                    if(GET_CABLE_DETECT(ucI) != GET_D3_CABLE_STATUS())
                    {
                        SET_CABLE_DETECT(ucI, GET_D3_CABLE_STATUS());
                        SET_CABLE_STATUS_CHANGE(ucI, _TRUE);                        

                        DebugMessageSystem("0. Cable Status Chanaged D3", ucI);	                        
                    }
                }
                break;
#endif

            default:
                break;
        }
    }        
}

//--------------------------------------------------
// Description  : Judge Source Search Times
// Input Value  : target search times
// Output Value : True --> search times of valid ports equal to target times
//--------------------------------------------------
bit SysSourceCheckTargetTimes(BYTE ucTargetTimes)
{
    BYTE ucCnt = 0x00;

    for(ucCnt = 0; ucCnt < _INPUT_PORT_VALID; ucCnt++)
    {
        if(GET_SOURCE_SEARCH_TIMES(ucCnt) != ucTargetTimes)
        {
            return _FALSE;
        }
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Set Scan Type for User
// Input Value  : Preferred Scan Type
// Output Value : None
//--------------------------------------------------
void SysSourceSetScanType(BYTE ucScanType)
{
    SET_SOURCE_SCAN_TYPE(ucScanType);
}

//--------------------------------------------------
// Description  : Get Scan Type for User
// Input Value  : None
// Output Value : Current Scan Type
//--------------------------------------------------
BYTE SysSourceGetScanType(void)
{
    return GET_SOURCE_SCAN_TYPE();
}

//--------------------------------------------------
// Description  : Convert Search Port to Search Index
// Input Value  : Input Port
// Output Value : Search Index
//--------------------------------------------------
BYTE SysSourceConvertSearchPort(BYTE ucInputPort)
{
    BYTE ucTemp = 0;

    while(ucTemp < _INPUT_PORT_VALID)
    {
        if(GET_INPUT_PORT(ucTemp) == ucInputPort)
        {
            return ucTemp;
        }
        
        ucTemp++;
    }

    return 0;
}

//--------------------------------------------------
// Description  : Get Source Cable Detect 
// Input Value  : ucInputPort
// Output Value : _TRUE => Cable Detected, _FASLE => Cable Undected
//--------------------------------------------------
bit SysSourceGetCableDetect(BYTE ucInputPort)
{
    return GET_CABLE_DETECT(SysSourceConvertSearchPort(ucInputPort));
}

//--------------------------------------------------
// Description  : Get Source Cable Status Change
// Input Value  : ucInputPort
// Output Value : _TRUE => Cable Status Changed
//--------------------------------------------------
bit SysSourceGetCableStatusChange(BYTE ucInputPort)
{
    return GET_CABLE_STATUS_CHANGE(SysSourceConvertSearchPort(ucInputPort));
}

//--------------------------------------------------
// Description  : Source Reset when Cable Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceCableResetProc(void)
{
    switch(GET_SOURCE_SCAN_TYPE())
    {
#if(_HP_SOURCE_SCAN_SUPPORT == _ON)

        case _SOURCE_SWITCH_HP_SOURCE_SCAN:
        case _SOURCE_SWITCH_HP_SOURCE_SWITCH:
        case _SOURCE_SWITCH_HP_TIMING_CHANGE:
        case _SOURCE_SWITCH_HP_OOR_SOURCE_SCAN:

            SET_SOURCE_HP_TARGET_SEARCH_TIMES(1);

            break;
#endif
        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Source First Active Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourceFirstActiveProc(void)
{
    switch(GET_SOURCE_SCAN_TYPE())
    {
#if(_HP_SOURCE_SCAN_SUPPORT == _ON)

        case _SOURCE_SWITCH_HP_SOURCE_SCAN:
        case _SOURCE_SWITCH_HP_SOURCE_SWITCH:
        case _SOURCE_SWITCH_HP_TIMING_CHANGE:
        case _SOURCE_SWITCH_HP_OOR_SOURCE_SCAN:            

            SET_SOURCE_HP_PORT_SWITCH_TARGET((_INPUT_PORT_VALID + 1));

            break;
#endif
        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Source Power Off Proc
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysSourcePowerOffProc(void)
{
    switch(GET_SOURCE_SCAN_TYPE())
    {
#if(_HP_SOURCE_SCAN_SUPPORT == _ON)

        case _SOURCE_SWITCH_HP_SOURCE_SCAN:
        case _SOURCE_SWITCH_HP_SOURCE_SWITCH:
        case _SOURCE_SWITCH_HP_TIMING_CHANGE:
        case _SOURCE_SWITCH_HP_OOR_SOURCE_SCAN:            

            SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_HP_SOURCE_SCAN);

            CLR_SOURCE_HP_TIMING_CHANGE();

            CLR_SOURCE_HP_SWITCH_NO_CABLE();

            CLR_SOURCE_HP_TARGET_NO_SIGNAL();

            g_ucSearchIndex = 0;

            SET_SOURCE_HP_TARGET_SEARCH_TIMES(3);  

            SET_SOURCE_HP_PORT_SWITCH_TARGET((_INPUT_PORT_VALID + 1));

            ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_SOURCE_HP_CANCEL_MANUAL_SWITCH_PORT);

            break;
#endif
        default:

            if(GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_DELL_HOTKEY_FIXED)
            {
                SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_FIXED_PORT);
            }
            else if(GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_DELL_HOTKEY_AUTO)
            {
                SET_SOURCE_SCAN_TYPE(_SOURCE_SWITCH_AUTO_IN_GROUP);
            }  
                
            g_ucSearchIndex = SysSourceConvertSearchPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));

            break;
    }

#if(_DP_SUPPORT == _ON)
    if(UserCommonNVRamGetSystemData(_DP_HOT_PLUG_DC_OFF_HIGH) == _FALSE)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
#endif
        ScalerDpDpcdLinkStatusReset();

        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HOTPLUG_ASSERTED);
        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_HDCP_LONG_HOTPLUG_EVENT);
        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_LINK_STATUS_IRQ);
    }
#endif    
}

//--------------------------------------------------
// Description  : Input Port Search Priority Select
// Input Value  : Priority and Input Port
// Output Value : None
//--------------------------------------------------
void SysSourceSetSearchPriority(EnumSourceSearchPort enumPort, EnumSourceSearchPortPriority enumSourcePriority)
{
    BYTE ucCnt = 0;
    BYTE ucCnt1 = 0;
    BYTE ucSearchIndexBackup = SysSourceConvertSearchPort(enumPort); 
    BYTE ucInputPortBackup = SysSourceGetSpecificInputPort(enumSourcePriority); 
    
    if((enumSourcePriority >= _INPUT_PORT_PRIORITY_NONE) || (enumPort >= _NO_INPUT_PORT) || (ucSearchIndexBackup == enumSourcePriority))
    {
        return;        
    }
    
    SET_SOURCE_TYPE_BACKUP(GET_SOURCE_TYPE(enumSourcePriority));
    SET_SOURCE_SEARCH_TIMES_BACKUP(GET_SOURCE_SEARCH_TIMES(enumSourcePriority));
    SET_SOURCE_JUDGE_BACKUP(GET_SOURCE_JUDGE(enumSourcePriority));
    SET_SOURCE_PREDETECT_BACKUP(GET_SOURCE_PREDETECT(enumSourcePriority));
    SET_CABLE_DETECT_BACKUP(GET_CABLE_DETECT(enumSourcePriority));
    SET_CABLE_STATUS_CHANGE_BACKUP(GET_CABLE_STATUS_CHANGE(enumSourcePriority));

    SET_SOURCE_TYPE(enumSourcePriority, GET_SOURCE_TYPE(ucSearchIndexBackup));
    SET_SOURCE_SEARCH_TIMES(enumSourcePriority, GET_SOURCE_SEARCH_TIMES(ucSearchIndexBackup));
    SET_SOURCE_JUDGE(enumSourcePriority, GET_SOURCE_JUDGE(ucSearchIndexBackup));
    SET_SOURCE_PREDETECT(enumSourcePriority, GET_SOURCE_PREDETECT(ucSearchIndexBackup));
    SET_CABLE_DETECT(enumSourcePriority, GET_CABLE_DETECT(ucSearchIndexBackup));
    SET_CABLE_STATUS_CHANGE(enumSourcePriority, GET_CABLE_STATUS_CHANGE(ucSearchIndexBackup));            

    SET_SOURCE_TYPE(ucSearchIndexBackup, GET_SOURCE_TYPE_BACKUP());
    SET_SOURCE_SEARCH_TIMES(ucSearchIndexBackup, GET_SOURCE_SEARCH_TIMES_BACKUP());
    SET_SOURCE_JUDGE(ucSearchIndexBackup, GET_SOURCE_JUDGE_BACKUP());
    SET_SOURCE_PREDETECT(ucSearchIndexBackup, GET_SOURCE_PREDETECT_BACKUP());
    SET_CABLE_DETECT(ucSearchIndexBackup, GET_CABLE_DETECT_BACKUP());
    SET_CABLE_STATUS_CHANGE(ucSearchIndexBackup, GET_CABLE_STATUS_CHANGE_BACKUP());            

    if(enumSourcePriority == g_ucSearchIndex)
    {
        g_ucSearchIndex = ucSearchIndexBackup;
    }
    else if(ucSearchIndexBackup == g_ucSearchIndex)
    {
        g_ucSearchIndex = enumSourcePriority;
    }
    
    g_ucSourceSearchPriority[enumSourcePriority] = enumPort;
    g_ucSourceSearchPriority[ucSearchIndexBackup] = ucInputPortBackup;
}

//--------------------------------------------------
// Description  : Input Port Search Group Select
// Input Value  : Group and Input Port
// Output Value : None
//--------------------------------------------------
void SysSourceSetSearchGroup(EnumSourceSearchPort enumPort, EnumSourceSearchGroup enumSourceGroup)
{
    if((enumPort >= _NO_INPUT_PORT) || (enumSourceGroup >= _INPUT_PORT_GROUP_NONE))
    {
        return;
    }
    
    g_ucSourceSearchGroup[enumPort] = enumSourceGroup;
}

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HP Source Judge Flag
// Input Value  : None
// Output Value : True --> HP Judge
//--------------------------------------------------
bit SysSourceHpGetSourceJudge(void)
{
    return (bit)GET_SOURCE_HP_SOURCE_JUDGE();
}

//--------------------------------------------------
// Description  : Get Target Source Type
// Input Value  : Target SearchIndex
// Output Value : Target Souce Type
//--------------------------------------------------
BYTE SysSourceHpGetTargetSourceType(BYTE ucSearchIndex)
{
    return GET_SOURCE_TYPE(ucSearchIndex);
}

//--------------------------------------------------
// Description  : Get Target Source Search Times
// Input Value  : None
// Output Value : Target Source Search Times
//--------------------------------------------------
BYTE SysSourceHpGetTargetSearchTimes(void)
{
    return GET_SOURCE_HP_TARGET_SEARCH_TIMES();
}

//--------------------------------------------------
// Description  : Get Switch Port Cable Status
// Input Value  : None
// Output Value : True --> No Cable
//--------------------------------------------------
bit SysSourceHpGetSwitchPortNoCable(void)
{
    return GET_SOURCE_HP_SWITCH_NO_CABLE();
}

//--------------------------------------------------
// Description  : Get Switch Port Nosignal Status
// Input Value  : None
// Output Value : True --> Show Monitor Status
//--------------------------------------------------
bit SysSourceHpGetTargetPortNoSignal(void)
{
    return GET_SOURCE_HP_TARGET_NO_SIGNAL();
}

#endif
