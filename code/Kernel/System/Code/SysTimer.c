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
// ID Code      : SysTimer.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_TIMER__

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
void SysTimerHandler(void);
void SysTimerEventProc(EnumSystemTimerEventID enumEventID);
void SysTimerIntProc0(void);
void SysTimerIntProc1(void);
void SysTimerIntProc2(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Timer Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysTimerHandler(void)
{
    BYTE ucTimerEventIndex = 0;
    BYTE ucTimerEventID = 0;    
    WORD usPresentTime = 0;
    
    for(ucTimerEventIndex = 0; ucTimerEventIndex < _TIMER_EVENT_COUNT; ucTimerEventIndex++)
    {
        usPresentTime = ScalerTimerGetTimerCounter();

        if(ScalerTimerCheckEventValid(ucTimerEventIndex) == _FALSE)
        {
            continue;
        }         
        
        if(usPresentTime > ScalerTimerGetEventTime(ucTimerEventIndex))
        {
            ScalerTimerClrEventValid(ucTimerEventIndex);

            // Get Event ID From Event Index
            ucTimerEventID = ScalerTimerGetEventID(ucTimerEventIndex);
            
            if(ucTimerEventID < _USER_TIMER_EVENT_END)
            {
                UserInterfaceTimerEventProc(ucTimerEventID);
                
                continue;
            }

            if(ucTimerEventID < _SYSTEM_TIMER_EVENT_END)
            {
                SysTimerEventProc(ucTimerEventID);
                
                continue;
            }
            
            ScalerTimerEventProc(ucTimerEventID);
        }
    }
}

//--------------------------------------------------
// Description  : Timer Event Process
// Input Value  : enumEventID --> Event to be processed
// Output Value : None
//--------------------------------------------------
void SysTimerEventProc(EnumSystemTimerEventID enumEventID)
{
    switch(enumEventID)
    {
        case _SYSTEM_TIMER_EVENT_SOURCE_CLEAR_DETECTING:            
            SysSourceClearDetectingEvent();            
            break;

        case _SYSTEM_TIMER_EVENT_JUDGE_ACTIVE_STATE:
            SET_MODE_ACTIVE_READY();
            break;

        case _SYSTEM_TIMER_EVENT_JUDGE_NOSUPPORT_STATE:
            SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_NOSUPPORT);
            break;

        case _SYSTEM_TIMER_EVENT_JUDGE_NOSIGNAL_STATE:
            SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_NOSIGNAL);            
            break;

#if(_EMBEDDED_DAC_SUPPORT == _ON)
        case _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_INITIAL:
            ScalerAudioDACSetState(_AUDIO_DAC_CHARGE);
            break;
            
        case _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_CHARGE:
            ScalerAudioDACSetState(_AUDIO_DAC_DEPOP);
            break;

        case _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL:
            ScalerAudioDACDepopToNormal();
            break;
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
        case _SYSTEM_TIMER_EVENT_SOURCE_HP_CANCEL_MANUAL_SWITCH_PORT:
            SET_SOURCE_HP_PORT_SWITCH_TARGET((_INPUT_PORT_VALID + 1));
            break;
#endif 

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_ASUS_STYLE)
        case _SYSTEM_TIMER_EVENT_SOURCE_ASUS_START_AUTO:
            SET_SOURCE_ASUS_START_AUTO();
            break;
#endif
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Timer0 Int Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysTimerIntProc0(void) interrupt 1
{

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    // Clear Timer0 flag
    TF0 = 0;

    TL0 = g_ucTimerCountLByte0;
    TH0 = g_ucTimerCountHByte0;

    TR0 = _ON;
    
    UserInterfaceTimer0InstantAccess_TIMER0();
#endif

}

//--------------------------------------------------
// Description  : Timer1 Int Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysTimerIntProc1(void) interrupt 3
{
    
#if(_INSTANT_TIMER_EVENT_1 == _ON)
    // Clear Timer1 flag
    TF1 = 0;

    TL1 = g_ucTimerCountLByte1;
    TH1 = g_ucTimerCountHByte1;

    TR1 = _ON;
    
    UserInterfaceTimer1InstantAccess_TIMER1();

#if(_LC_TANK_SUPPORT == _ON)
    ScalerLCTankDpllOffsetRegulation_TIMER1();
#endif

#endif

}

//--------------------------------------------------
// Description  : Timer2 Int Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysTimerIntProc2(void) interrupt 5
{
    // Clear Timer2 flag
    TF2 = 0;

    // Clear watchdog
    CLR_MCU_WATCH_DOG(); 

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)

    g_bNotifyTimer2Int = _TRUE;

    // Timer Counter 
    g_usTimerCounter += 1;   
    
#else

    if(g_ucTimerQuarterCount >= 3)
    {
        g_ucTimerQuarterCount = 0;
            
        g_bNotifyTimer2Int = _TRUE;

        // Timer Counter 
        g_usTimerCounter += 1;   
    }
    else
    {
        g_ucTimerQuarterCount++;
    }

    UserInterfaceTimer2InstantAccess_TIMER2();

#endif

}
