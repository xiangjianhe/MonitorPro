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
// ID Code      : RTDKey.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_KEY__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2011_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Key Mask
//--------------------------------------------------
#define _POWER_KEY_MASK                             0x01
#define _MENU_KEY_MASK                              0x02
#define _RIGHT_KEY_MASK                             0x04
#define _LEFT_KEY_MASK                              0x08
#define _EXIT_KEY_MASK                              0x10
#define _KEY5_MASK                                  0x20
#define _KEY6_MASK                                  0x40
#define _KEY7_MASK                                  0x80
#define KEY_NONE                                    0x00

// add for xml and customer config
#define KEY_POWER                                   _POWER_KEY_MASK
#define KEY_MENU                                    _MENU_KEY_MASK
#define KEY_RIGHT                                   _RIGHT_KEY_MASK
#define KEY_LEFT                                    _LEFT_KEY_MASK
#define KEY_EXIT                                    _EXIT_KEY_MASK
#define KEY_DOWN                                    _KEY5_MASK
#define KEY_UP                                      _KEY6_MASK

#define _POWER_RIGHT_KEY_MASK                       (_POWER_KEY_MASK | _RIGHT_KEY_MASK)
#define _POWER_MENU_KEY_MASK                        (_POWER_KEY_MASK | _MENU_KEY_MASK)
#define _POWER_LEFT_RIGHT_KEY_MASK                  (_POWER_KEY_MASK | _LEFT_KEY_MASK | _RIGHT_KEY_MASK)


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucKeyStatePrev = 0;
BYTE g_ucKeyStateCurr = 0;

#if(_AD_KEY_SUPPORT == _ON)
BYTE g_ucBackupKeyState = 0xFF;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserKeyHandler(void);
void RTDKeyInitial(void);
bit RTDKeyScanReady(void);
BYTE RTDKeyScan(void);
bit RTDKeyPowerKeyProc(void);
void RTDKeyPowerKeyMix(void);
void RTDKeyMessageProc(void);
void RTDKeyMessageConvert(BYTE ucKeyMask, BYTE ucKeyMsg);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Key Handler, executed in the main loop.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserKeyHandler(void)
{
    // Clear the key message
    if(GET_KEYMESSAGE() != _HOLD_KEY_MESSAGE)
    {
        SET_KEYMESSAGE(_NONE_KEY_MESSAGE);
    }

    if(RTDKeyScanReady() == _TRUE)
    {
        // Store previous key state
        g_ucKeyStatePrev = g_ucKeyStateCurr;

        // Get current key state
        g_ucKeyStateCurr = RTDKeyScan();

        // Power key process, return if power key is pressed
        if(RTDKeyPowerKeyProc())
        {
            return;
        }

        // Convert key state to key message, store in (ucKeyNotify)
        RTDKeyMessageProc();
    }
}

//--------------------------------------------------
// Description  : Key intial.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyInitial(void)
{
    CLR_KEYSCANREADY();
    CLR_KEYSCANSTART();
}

//--------------------------------------------------
// Description  : Key scan ready process. We wait 0.02 sec in order to keep the keypad debounce
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit RTDKeyScanReady(void)
{ 
    BYTE ucShow = 0;
    
    if(GET_KEYSCANSTART() && GET_KEYSCANREADY())
    {
        return _TRUE;
    }
    else if(!GET_KEYSCANSTART())
    {
        // Set Scan start flag.
        SET_KEYSCANSTART();
        
        // SET_KEYSCANREADY();
        // Wait 0.02 sec in order to keep the keypad debounce
        ScalerTimerReactiveTimerEvent(SEC(0.07), _USER_TIMER_EVENT_KEY_SCAN_READY);
        
        return _FALSE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get key status
// Input Value  : None
// Output Value : Return Key status
//--------------------------------------------------
BYTE RTDKeyScan(void)
{
    BYTE ucKeyState = 0;
    BYTE ucVoltage0 = 0;
    BYTE ucVoltage1 = 0;
    BYTE ucVoltage2 = 0;
    BYTE ucVoltage3 = 0;

#if(_AD_KEY_SUPPORT == _ON)
    ucVoltage0 = PCB_ADKEY0();
    ucVoltage1 = PCB_ADKEY1();
    ucVoltage2 = PCB_ADKEY2();
    ucVoltage3 = PCB_ADKEY3();

    PCB_KEY_STATE(ucVoltage0, ucVoltage1, ucVoltage2, ucVoltage3, ucKeyState);

    if(g_ucBackupKeyState == ucKeyState)
    {
        if(ucKeyState != 0)
        {
            RTDKeyInitial();
        }

        return g_ucBackupKeyState;
    }

    pData[0] = 0;
    do
    {
        ScalerTimerDelayXms(1);

        if((abs(PCB_ADKEY0() - ucVoltage0) < 2) && (abs(PCB_ADKEY1() - ucVoltage1) < 2) && (abs(PCB_ADKEY2() - ucVoltage2) < 2) && (abs(PCB_ADKEY3() - ucVoltage3) < 2))
        {
            break;
        }
        else
        {
            ucVoltage0 = PCB_ADKEY0();
            ucVoltage1 = PCB_ADKEY1();
            ucVoltage2 = PCB_ADKEY2();
            ucVoltage3 = PCB_ADKEY3();
        }

        pData[0]++;
    }
    while(pData[0] < 10);

#endif // End of #if(_AD_KEY_SUPPORT == _ON)

	ucKeyState = 0;
	
    PCB_KEY_STATE(ucVoltage0, ucVoltage1, ucVoltage2, ucVoltage3, ucKeyState);

#if(_AD_KEY_SUPPORT == _ON)
    g_ucBackupKeyState = ucKeyState;
#endif

    if(ucKeyState != 0)
    {
        RTDKeyInitial();
    }

    return ucKeyState;
}

//--------------------------------------------------
// Description  : Power key process
// Input Value  : None
// Output Value : Return _TRUE if power key is pressed
//--------------------------------------------------
bit RTDKeyPowerKeyProc(void)
{
    if(g_ucKeyStateCurr & _POWER_KEY_MASK)
    {
        if((g_ucKeyStatePrev ^ g_ucKeyStateCurr) & _POWER_KEY_MASK)
        {
            RTDKeyPowerKeyMix();

            if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)
            {
                SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
            }
            else
            {
                SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
            }

            return _TRUE;
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : We can add some settings here while combo key with power key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyPowerKeyMix(void)
{
    switch(g_ucKeyStateCurr)
    {
        case _POWER_RIGHT_KEY_MASK:
            break;

        case _POWER_MENU_KEY_MASK:
            break;

        case _POWER_LEFT_RIGHT_KEY_MASK:
            break;

        default:
            break;
    }
}


//--------------------------------------------------
// Description  : Convert keypad status into key message, stores in ucKeyNotify
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyMessageProc(void)
{
    switch(g_ucKeyStateCurr)
    {
        case _MENU_KEY_MASK:
            CLR_KEYREPEATENABLE();            
            RTDKeyMessageConvert(_MENU_KEY_MASK, _MENU_KEY_MESSAGE);
            break;

        case _RIGHT_KEY_MASK:
            SET_KEYREPEATENABLE();    
            RTDKeyMessageConvert(_RIGHT_KEY_MASK, _RIGHT_KEY_MESSAGE);
            break;

        case _LEFT_KEY_MASK:
            if(GET_OSD_STATE() == _MENU_NONE)
            {
                CLR_KEYREPEATENABLE();
            }
            else
            {
                SET_KEYREPEATENABLE();
            }
            RTDKeyMessageConvert(_LEFT_KEY_MASK, _LEFT_KEY_MESSAGE);
            break;

        case _EXIT_KEY_MASK:
            CLR_KEYREPEATENABLE();            
            RTDKeyMessageConvert(_EXIT_KEY_MASK, _EXIT_KEY_MESSAGE);
            break;

        default:
            CLR_KEYREPEATSTART();
            CLR_KEYREPEATENABLE();            
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_KEY_REPEAT_ENABLE);
            if((g_ucKeyStatePrev == _LEFT_KEY_MASK) && (GET_OSD_STATE() == _MENU_NONE) && (GET_FAIL_SAFE_MODE() == _FALSE)
            && (SysSourceGetSourceType() == _SOURCE_VGA))
            {
                if(GET_KEYMESSAGE() == _HOLD_KEY_MESSAGE)
                {
                    SET_KEYMESSAGE(_NONE_KEY_MESSAGE);
                }
                else
                {
                    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DO_AUTO_COLOR);
                    SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                }
            }
            break;
    }
}

//--------------------------------------------------
// Description  : Key message translation
// Input Value  : ucKeyMask     --> Key mask
//                ucKeyMsg      --> Key message
// Output Value : None
//--------------------------------------------------
void RTDKeyMessageConvert(BYTE ucKeyMask, BYTE ucKeyMsg)
{
    if((g_ucKeyStatePrev ^ g_ucKeyStateCurr) & ucKeyMask)
    {
        if((ucKeyMsg == _LEFT_KEY_MESSAGE) && (GET_OSD_STATE() == _MENU_NONE) && (GET_FAIL_SAFE_MODE() == _FALSE)
        && (SysSourceGetSourceType() == _SOURCE_VGA))
        {
            SET_KEYMESSAGE(_NONE_KEY_MESSAGE);
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_DO_AUTO_COLOR);
        }
        else
        {
            SET_KEYMESSAGE(ucKeyMsg);
        }
    }
    else
    {
        if(GET_KEYREPEATENABLE())
        {
            if(GET_KEYREPEATSTART())
            {
                SET_KEYMESSAGE(ucKeyMsg);
            }
            else
            {
                // Set repeat key after 20ms.
                ScalerTimerActiveTimerEvent(SEC(0.02), _USER_TIMER_EVENT_KEY_REPEAT_ENABLE); //C.J. Timer
            }
        }
    }
}

#endif//#if(_OSD_TYPE == _REALTEK_2011_OSD)
