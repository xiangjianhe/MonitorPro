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
// ID Code      : Sysmain.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __MAIN__

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
BYTE data pData[16] = {0};

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysMainSystemInitial(void);
bit SysMainSytemPowerDetect(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : The main function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void main(void)
{
    do
    {
        SysMainSystemInitial();
       
        while(SysMainSytemPowerDetect() == _TRUE)
        {    
            UserKeyHandler();            
            SysPowerHandler();
            SysJudgeHandler();

#if(_AUDIO_SUPPORT == _ON)
            SysAudioHandler();
#endif
            SysTimerHandler();      
            SysSourceHandler();
            SysModeHandler();

#if(_MHL_SUPPORT == _ON)
            SysMHLMscHandler();
#endif

#if(_LC_TANK_SUPPORT == _ON)
            SysLCTankHandler();
#endif
            UserOsdHandler();
            UserCommonDdcciHandler();
            ScalerDebug();                        
        }
    }
    while(_TRUE);        
}

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysMainSystemInitial(void)
{
    ScalerMcuInitial();
    
    ScalerPinshareInitial();

    ScalerTimerInitialTimerEvent();

    UserCommonInterfaceInitial();

    ScalerMcuDdcRamEnable();

    SysSourceInitial();

    SysPowerInitial();

    SET_POWER_STATUS(_POWER_STATUS_AC_ON);
    
#if(_SUPER_LOW_POWER_SUPPORT == _ON)
    if(UserCommonNVRamGetSystemData(_MONITOR_POWER_STATUS) == _ON)
    {
        if(ScalerSLPWakeUpStatus() == _SLP_POWER_KEY_EVENT)
        {
            SET_TARGET_POWER_STATUS(_POWER_STATUS_OFF);
        }
        else
        {
            SET_TARGET_POWER_STATUS(_POWER_STATUS_NORMAL);
        }
    }
    else
    {
        if((ScalerSLPWakeUpStatus() == _SLP_POWER_KEY_EVENT) || (UserCommonNVRamGetSystemData(_SLP_AC_OFF_DETECT) == _ON))
        {
            SET_TARGET_POWER_STATUS(_POWER_STATUS_NORMAL);
        }
        else
        {
            SET_TARGET_POWER_STATUS(_POWER_STATUS_OFF);
        }
    }
    
    if((UserCommonNVRamGetSystemData(_MONITOR_POWER_STATUS) == _ON) && (ScalerSLPWakeUpStatus()!= _SLP_NO_EVENT))
    {
        SysJudgeStateChangeEvent(_MODE_STATUS_POWER_SAVING);
        
        SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);

        SysSourceCableResetProc();      
    }
    else
    {
        SysJudgeStateChangeEvent(_MODE_STATUS_POWER_OFF);
    }

#else
    if(UserCommonNVRamGetSystemData(_MONITOR_POWER_STATUS) == _ON)
    {
        SET_TARGET_POWER_STATUS(_POWER_STATUS_NORMAL);
    }
    else
    {
        SET_TARGET_POWER_STATUS(_POWER_STATUS_OFF);
    }

    SysJudgeStateChangeEvent(_MODE_STATUS_POWER_OFF);    
#endif // End of #if(_SUPER_LOW_POWER_SUPPORT == _ON)

}

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit SysMainSytemPowerDetect(void)
{
    return PCB_POWER_5V_DETECT();
}
