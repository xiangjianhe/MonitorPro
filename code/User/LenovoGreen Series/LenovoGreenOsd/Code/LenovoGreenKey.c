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

#if(_OSD_TYPE == _LEONVO_GREEN_OSD)

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
#define _UP_KEY_MASK                                0x20
#define _DOWN_KEY_MASK                              0x40
#define _KEY7_MASK                                  0x80
#define KEY_NONE                                    0x00

// add for xml and customer config
#define KEY_POWER                                   _POWER_KEY_MASK
#define KEY_MENU                                    _MENU_KEY_MASK
#define KEY_RIGHT                                   _RIGHT_KEY_MASK
#define KEY_LEFT                                    _LEFT_KEY_MASK
#define KEY_EXIT                                    _EXIT_KEY_MASK
#define KEY_DOWN                                    _DOWN_KEY_MASK
#define KEY_UP                                      _UP_KEY_MASK

#define _POWER_LEFT_KEY_MASK                        (_POWER_KEY_MASK | _LEFT_KEY_MASK)
#define _POWER_RIGHT_KEY_MASK                       (_POWER_KEY_MASK | _RIGHT_KEY_MASK)
#define _POWER_MENU_KEY_MASK                        (_POWER_KEY_MASK | _MENU_KEY_MASK)
#define _POWER_LEFT_RIGHT_KEY_MASK                  (_POWER_KEY_MASK | _LEFT_KEY_MASK | _RIGHT_KEY_MASK)
#define _EXIT_MENU_KEY_MASK                         (_EXIT_KEY_MASK | _MENU_KEY_MASK)

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

BYTE g_ucKeyRepeatCount = 0x00;

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
//Key處理(主迴圈)
void UserKeyHandler(void)
{
    // Clear the key message
    if(GET_KEYMESSAGE() != _HOLD_KEY_MESSAGE)     //判斷Hold Key
    {
        SET_KEYMESSAGE(_NONE_KEY_MESSAGE);
    }

    if(RTDKeyScanReady() == _TRUE)                //Scan到Key
    {
        // Store previous key state
        g_ucKeyStatePrev = g_ucKeyStateCurr;      //上次Key狀態傳存

        // Get current key state
        g_ucKeyStateCurr = RTDKeyScan();          //讀取Key值

        // Power key process, return if power key is pressed
        if(RTDKeyPowerKeyProc())                  //Power Key處理
        {
            return;
        }

        // Convert key state to key message, store in (ucKeyNotify)
	    RTDKeyMessageProc();                   //Key訊息處理
    }
}

//--------------------------------------------------
// Description  : Key intial.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
//Key Flag初始化
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
//判斷Key是否Scan ok
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
        if(g_ucKeyRepeatCount > 10)
        {
            ScalerTimerReactiveTimerEvent(SEC(0.1), _USER_TIMER_EVENT_KEY_SCAN_READY);
        }
        else
        {
            ScalerTimerReactiveTimerEvent(SEC(0.2), _USER_TIMER_EVENT_KEY_SCAN_READY);
        }
        
        return _FALSE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get key status
// Input Value  : None
// Output Value : Return Key status
//--------------------------------------------------
//讀取Key值
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
    else
    {
        g_ucBackupKeyState = ucKeyState;
        ucKeyState = 0;
        return g_ucBackupKeyState;
    }
#endif // End of #if(_AD_KEY_SUPPORT == _ON)
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
//Power Key處理
bit RTDKeyPowerKeyProc(void)
{
    if(g_ucKeyStateCurr & _POWER_KEY_MASK)
    {
        if((g_ucKeyStatePrev ^ g_ucKeyStateCurr) & _POWER_KEY_MASK)
        {
            RTDKeyPowerKeyMix();

#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
#if(_SHOW_KEY_MESSAGE == _ON)
            if(GET_ATE_COMMAND_STATUS()&&GET_KEYTEST_STATUS())
            {
                CLR_KEYREPEATENABLE();
                RTDKeyMessageConvert(_POWER_KEY_MASK, _POWER_KEY_MESSAGE);
            }
            else
#endif
#endif
            {
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
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : We can add some settings here while combo key with power key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
//複合Key處理
void RTDKeyPowerKeyMix(void)
{
    switch(g_ucKeyStateCurr)
    {
        case _POWER_RIGHT_KEY_MASK:
            break;

        case _POWER_MENU_KEY_MASK:
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
            SET_ATE_COMMAND_STATUS();
            NVRamSaveFactoryDate();
#endif						
            break;

#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
        case _POWER_LEFT_KEY_MASK:
			SET_FACTORY_MODE(_ON);
            break;
#endif						

        case _POWER_LEFT_RIGHT_KEY_MASK:
#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
			SET_FACTORY_MODE(_ON);
			SET_FACTORY_BURNIN(_ON);
			NVRamSaveFactoryDate();
#endif
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
//Key訊息處理
void RTDKeyMessageProc(void)
{
	if((g_ucKeyStateCurr != 0x00) && (g_ucKeyRepeatCount < 0xff))
	{
		g_ucKeyRepeatCount++; 
	}
    
    switch(g_ucKeyStateCurr)
    {
        case _MENU_KEY_MASK:
        	if((GET_OSD_STATE() == _MENU_NONE)&&(GET_FAIL_SAFE_MODE() == _FALSE))
        	{
        		ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_LOCK);
        	}
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)            
        	else if((GET_OSD_STATE() == _OSD_MAIN_TPV_FACTORY)&&(GET_FAIL_SAFE_MODE() == _FALSE))
        	{
        		ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_EDIDVERSION_CLEAR);
        	}
#endif            
        	else
        	{
        		RTDKeyMessageConvert(_MENU_KEY_MASK, _MENU_KEY_MESSAGE);
        	}            
            break;

        case _RIGHT_KEY_MASK:
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		
            if((GET_OSD_LOCK_STATUS() == _OFF) && (GET_OSD_STATE() == _MENU_NONE) && (GET_FAIL_SAFE_MODE() == _FALSE))            
            {
                CLR_KEYREPEATENABLE();
                ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_LOWBLUELIGHT_HOTKEY);  
            }             
            else
#endif            
            {
                SET_KEYREPEATENABLE();
            }
            RTDKeyMessageConvert(_RIGHT_KEY_MASK, _RIGHT_KEY_MESSAGE);
            break;

        case _LEFT_KEY_MASK:
            RTDKeyMessageConvert(_LEFT_KEY_MASK, _LEFT_KEY_MESSAGE);
            SET_KEYREPEATENABLE();
            break;

        case _EXIT_KEY_MASK: 
        	CLR_KEYREPEATENABLE();
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)            
			if((GET_OSD_LOCK_STATUS() == _OFF) && (GET_OSD_STATE() == _MENU_NONE) && (GET_FAIL_SAFE_MODE() == _FALSE)&&(SysModeGetModeState() == _MODE_STATUS_ACTIVE))
        	{
    #if(_SHOW_KEY_MESSAGE == _ON)
        	    if((g_ucKeyStatePrev == 0)&&(!GET_ATE_COMMAND_STATUS())&&(!GET_KEYTEST_STATUS()))
    #else
                if(g_ucKeyStatePrev == 0)//ym20131009 . 
    #endif        
                {
            	    SET_KEYHOLDKEY();
                }
                
        		ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_INPUT);
        		ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_DDCCI);
        	}
#else
			if((GET_OSD_LOCK_STATUS() == _OFF) && (GET_OSD_STATE() == _MENU_NONE) && (GET_FAIL_SAFE_MODE() == _FALSE))
			{
			#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)       
				ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_DDCCI);
			#else
				ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_DDCCI);
			#endif        
			}
#endif        
        	else
        	{
        		RTDKeyMessageConvert(_EXIT_KEY_MASK, _EXIT_KEY_MESSAGE);
        	}                               
            break;
            
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
#if(_SHOW_KEY_MESSAGE == _ON)
        case _EXIT_MENU_KEY_MASK:
            if(GET_ATE_COMMAND_STATUS()&&GET_OSD_STATE()==_MENU_NONE)
            {
                OsdDispDisableOsdTimerEvent();
                SET_KEYTEST_STATUS();
                NVRamSaveFactoryDate();
                RTDKeyMessageConvert(_EXIT_MENU_KEY_MASK, _ENTER_KEY_TEST_MESSAGE);
            }
            break;
#endif
#endif

        default:
/*
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)            
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_EDIDVERSION_CLEAR);      

			if((g_ucKeyStatePrev == _MENU_KEY_MASK) && (g_ucKeyStateCurr == 0) && ((GET_OSD_STATE() == _MENU_NONE)||(GET_OSD_STATE() == _OSD_MAIN_TPV_FACTORY)) && (GET_KEYHOLDKEY() != _TRUE))
			{
				RTDKeyMessageConvert(_MENU_KEY_MASK, _MENU_KEY_MESSAGE);
			}
			
			if((g_ucKeyStatePrev == _EXIT_KEY_MASK) && (g_ucKeyStateCurr == 0) && ((GET_OSD_STATE() == _MENU_NONE)||(GET_OSD_STATE() == _OSD_MAIN_TPV_FACTORY)) && (GET_KEYHOLDKEY() != _TRUE))
			{
				RTDKeyMessageConvert(_EXIT_KEY_MASK, _EXIT_KEY_MESSAGE);
			}
#else
			if((g_ucKeyStatePrev == _MENU_KEY_MASK) && (g_ucKeyStateCurr == 0) && (GET_OSD_STATE() == _MENU_NONE) && (GET_KEYHOLDKEY() != _TRUE))
			{
				RTDKeyMessageConvert(_MENU_KEY_MASK, _MENU_KEY_MESSAGE);
			}
			
			if((g_ucKeyStatePrev == _EXIT_KEY_MASK) && (g_ucKeyStateCurr == 0) && (GET_OSD_STATE() == _MENU_NONE) && (GET_KEYHOLDKEY() != _TRUE))
			{
				RTDKeyMessageConvert(_EXIT_KEY_MASK, _EXIT_KEY_MESSAGE);
			}

			if((g_ucKeyStatePrev == _RIGHT_KEY_MASK) && (g_ucKeyStateCurr == 0) && (GET_OSD_STATE() == _MENU_NONE) && (GET_KEYHOLDKEY() != _TRUE))
			{
				RTDKeyMessageConvert(_RIGHT_KEY_MASK, _RIGHT_KEY_MESSAGE);
			}
#endif
*/                               
            CLR_KEYREPEATSTART();
            CLR_KEYREPEATENABLE();            
            //CLR_KEYHOLDKEY();
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_KEY_REPEAT_ENABLE);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_LOCK);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DDCCI);
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)             
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_INPUT);//ym20131009 . 
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_EDIDVERSION_CLEAR);      
#endif  
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_LOWBLUELIGHT_HOTKEY);
#endif   

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		
            if( ((g_ucKeyStatePrev == _RIGHT_KEY_MASK) || (g_ucKeyStatePrev == _MENU_KEY_MASK)|| (g_ucKeyStatePrev == _EXIT_KEY_MASK) )&&  (GET_OSD_STATE() == _MENU_NONE) )
#else
            if( ((g_ucKeyStatePrev == _MENU_KEY_MASK)|| (g_ucKeyStatePrev == _EXIT_KEY_MASK) )&&  (GET_OSD_STATE() == _MENU_NONE) )
#endif   
            {
                //Menu放掉動作處理
                if(GET_KEYMESSAGE() == _HOLD_KEY_MESSAGE)
                {
                    SET_KEYMESSAGE(_NONE_KEY_MESSAGE);                    
                }
                else
                { 
                   if(GET_KEYHOLDKEY() == _TRUE)
                   {                       
                       g_ucKeyStatePrev=_NONE_KEY_MESSAGE;
                       CLR_KEYHOLDKEY();  
                   }
                   else
                   {
                       if(g_ucKeyStatePrev == _MENU_KEY_MASK)
                       {
                          SET_KEYMESSAGE(_MENU_KEY_MESSAGE); 
                       }   
                       else if(g_ucKeyStatePrev == _EXIT_KEY_MASK)
                       {    
                          SET_KEYMESSAGE(_EXIT_KEY_MESSAGE); 
                       } 
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		
                       else if(g_ucKeyStatePrev == _RIGHT_KEY_MASK)
                       {    
                          SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE); 
                       }   
#endif   
                   }
                }                                         
            }                
            g_ucKeyRepeatCount = 0;
            break;
    }
}

//--------------------------------------------------
// Description  : Key message translation
// Input Value  : ucKeyMask     --> Key mask
//                ucKeyMsg      --> Key message
// Output Value : None
//--------------------------------------------------
//Key動作與訊息轉換
void RTDKeyMessageConvert(BYTE ucKeyMask, BYTE ucKeyMsg)
{
    if((g_ucKeyStatePrev ^ g_ucKeyStateCurr) & ucKeyMask)
    {
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		
        if( ((ucKeyMsg == _RIGHT_KEY_MESSAGE) || (ucKeyMsg == _MENU_KEY_MESSAGE)||(ucKeyMsg == _EXIT_KEY_MESSAGE)) && (GET_OSD_STATE() == _MENU_NONE) )         
#else
        if(( (ucKeyMsg == _MENU_KEY_MESSAGE)||(ucKeyMsg == _EXIT_KEY_MESSAGE)) && (GET_OSD_STATE() == _MENU_NONE) )         
#endif   
        {
            SET_KEYMESSAGE(_NONE_KEY_MESSAGE);    
        }        
        else
        {
            SET_KEYMESSAGE(ucKeyMsg);
        }
    }
    else
    {
        if((GET_KEYREPEATENABLE()) && (GET_OSD_BUTTON_REPEAT_STATUS() != _OSD_BUTTON_REPEAT_OFF))
        {
            if(GET_KEYREPEATSTART())
            {
                SET_KEYMESSAGE(ucKeyMsg);
                if(GET_OSD_BUTTON_REPEAT_STATUS() == _OSD_BUTTON_REPEAT_SLOW)
                {
                	CLR_KEYREPEATSTART();
                }                
            }
            else
            {
            	if(GET_OSD_BUTTON_REPEAT_STATUS() == _OSD_BUTTON_REPEAT_DEFAULT)
            	{
	                // Set repeat key after 20ms.
	                ScalerTimerActiveTimerEvent(SEC(0.02), _USER_TIMER_EVENT_KEY_REPEAT_ENABLE);				
            	}
            	else
            	{
            		ScalerTimerActiveTimerEvent(SEC(0.3), _USER_TIMER_EVENT_KEY_REPEAT_ENABLE);				
            	}
                
            }
        }
    }
}

#if ((_FACTORY_MODE_OWNER == _OWNER_TPV))//DFM
void TPVKeyIntoFactory(void)
{

    if(_MENU_KEY_MASK == RTDKeyScan())
    {
	   SET_FACTORY_MODE(_ON);
       TPVNVRamSaveFactoryDate();
    }
    else if(_ON==GET_FACTORY_MODE())
    {
       SET_FACTORY_MODE(_OFF);
       TPVNVRamSaveFactoryDate();
    }
}
#endif

#endif//#if(_OSD_TYPE == _LEONVO_GREEN_OSD)
