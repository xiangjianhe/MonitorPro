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
// ID Code      : RTDKey.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_KEY__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LENOVO_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

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


        //20141125 Abel 
#if(_AUTO_POWER_DOWN == _ON)
           if(g_ucKeyStateCurr)
           {
                g_usDisPlayCunt = 0;
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_POWER_DOWN_COUNT);
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_POWER_DOWN_TO_POWER_SAVING);
                //ScalerDebugMessage("@@KEY", 0x66);
           }     
#endif        

        // Power key process, return if power key is pressed
        if(RTDKeyPowerKeyProc())                  //Power Key處理
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
//Key Flag初始化
void RTDKeyInitial(void)
{
#if(_TOUCH_KEY_SUPPORT == _OFF)
    CLR_KEYSCANREADY();
    CLR_KEYSCANSTART();
#else
    UserTouchKeyInitial();
#endif // End of #if(_TOUCH_KEY_SUPPORT == _OFF)
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

#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
        if(g_ucKeyRepeatCount > 10)
		{
			ScalerTimerReactiveTimerEvent(SEC(0.05), _USER_TIMER_EVENT_KEY_SCAN_READY);
		}
		else
		{
			ScalerTimerReactiveTimerEvent(SEC(0.1), _USER_TIMER_EVENT_KEY_SCAN_READY);
		}
#else
        if(g_ucKeyRepeatCount > 10)
		{
			ScalerTimerReactiveTimerEvent(SEC(0.1), _USER_TIMER_EVENT_KEY_SCAN_READY);
		}
		else
		{
			ScalerTimerReactiveTimerEvent(SEC(0.2), _USER_TIMER_EVENT_KEY_SCAN_READY);
		}
#endif
        
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
#if(_TOUCH_KEY_SUPPORT == _OFF)
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
    
#elif(_TOUCH_KEY_SUPPORT == _ON)
    ucKeyState = UserTouchKeyScan();
#endif // End of #if(_TOUCH_KEY_SUPPORT == _OFF)
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
            RTDKeyPowerKeyMix();		                               //複合Key處理

#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
#if(_SHOW_KEY_MESSAGE == _ON)
            if(GET_ATE_COMMAND_STATUS()&&GET_KEYTEST_STATUS())
            {
                CLR_KEYREPEATENABLE();
                RTDKeyMessageConvert(_POWER_KEY_MASK, _POWER_KEY_MESSAGE);
                return _FALSE;
            }
 #endif
 #endif

            if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)          //Power ON
            {            	          
                SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
				Xpos=100;//lorimiao 0819 for move OSD Position
				Ypos=100;
				//jason.cheng 20141030_1 add for Message fly issue<<<<<<
				Xdirect = 1;
				Ydirect = 1;
				ucLedFlashCount = 0;//jason.cheng 20141114_2 add
#if(_AUDIO_SUPPORT == _ON)
				//>>>>>>jason.cheng 20141030_1 add for Message fly issue
                //Mute ON
                PCB_AMP_MUTE(_AMP_MUTE_ON);                
                //AMP ON
                PCB_AMP_POWER(_AMP_POWER_ON);
#endif
				PCB_USB_POWER(_USB_POWER_ON);
            }
            else                                                       //Power OFF
            {
                SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
#if(_AUDIO_SUPPORT == _ON)

#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20141117 
                PCB_AMP_MUTE(_AMP_MUTE_ON);
			    UserAdjustAudioVolume(0);    
#else
                PCB_AMP_POWER(_AMP_POWER_OFF);
#endif
#endif
				PCB_USB_POWER(_USB_POWER_OFF);
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
//複合Key處理
void RTDKeyPowerKeyMix(void)
{
    switch(g_ucKeyStateCurr)
    {
        case _POWER_RIGHT_KEY_MASK:
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON) 
            SET_FACTORY_MODE(_ON);
#endif
            break;

        case _POWER_LEFT_KEY_MASK:
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON) 
            SET_ATE_COMMAND_STATUS();
			NVRamSaveFactoryData();
#endif
            break;

        case _POWER_LEFT_RIGHT_KEY_MASK:
#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
			SET_FACTORY_MODE(_ON);
			SET_FACTORY_BURNIN(_ON);
			NVRamSaveFactoryDate();
#endif
            break;

        //20120508 Abel Factory Mode OSD Modify
        case _POWER_MENU_LEFT_KEY_MASK:            //Power Key + Menu Key + Left Key                
            if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)    //開機時工廠複合Key
            {            	            	
                SET_FACTORY_MODE(_TRUE);                  //設定工廠OSD Flag ON
                DebugMessageOsd("@@@_POWER_MENU_LEFT_KEY_MASK2", 0x78);
            }    
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
        case _MENU_KEY_MASK:                 //Menu Key
            CLR_KEYREPEATENABLE();

            //OSD Lock時間Check            
            if( (SysModeGetModeState() == _MODE_STATUS_ACTIVE ) && ( (GET_OSD_STATE() == _MENU_NONE) || (GET_OSD_STATE() == _HOTKEY_MESSAGE_MENU) ))
            {
                //計數10sTimer ON
                ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_LOCK);     //10秒後OSD LOCK切換
            }             
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
        	else if((GET_OSD_STATE() == _ADJ_FACTORY)&&(GET_FAIL_SAFE_MODE() == _FALSE)&&(SysModeGetModeState() == _MODE_STATUS_ACTIVE))
        	{
        		ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_EDIDVERSION_CLEAR);
        	}
#endif

            RTDKeyMessageConvert(_MENU_KEY_MASK, _MENU_KEY_MESSAGE);
            break;

        case _RIGHT_KEY_MASK:
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_LBL_HOTKEY_FUNCTION == _ON))
            if((GET_OSD_LOCK_STATUS() == _OFF) && (SysModeGetModeState() == _MODE_STATUS_ACTIVE ) && ((GET_OSD_STATE() == _MENU_NONE) || (GET_OSD_STATE() == _HOTKEY_MESSAGE_MENU)))            
            {
                ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_LOW_BLUE_LIGHT);  
            }             
            else
#endif            
            {
                SET_KEYREPEATENABLE();   
                RTDKeyMessageConvert(_RIGHT_KEY_MASK, _RIGHT_KEY_MESSAGE);
            }
            break;

        case _LEFT_KEY_MASK:
        	SET_KEYREPEATENABLE();
            RTDKeyMessageConvert(_LEFT_KEY_MASK, _LEFT_KEY_MESSAGE);
                        
            break;

        case _EXIT_KEY_MASK:                  //Exit Key 
            CLR_KEYREPEATENABLE();    
            
            //OSD Lock時間Check            
            if((GET_OSD_LOCK_STATUS() == _OFF) && (SysModeGetModeState() == _MODE_STATUS_ACTIVE ) && ((GET_OSD_STATE() == _MENU_NONE) || (GET_OSD_STATE() == _HOTKEY_MESSAGE_MENU)))            
            {
                //計數10sTimer ON
                ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_DDCCI_ONOFF);     //10秒後切換DDCCI OSD ON/OFF
            }             
            
            
            RTDKeyMessageConvert(_EXIT_KEY_MASK, _EXIT_KEY_MESSAGE);
            break;

		case _SOURCE_KEY_MASK:
            CLR_KEYREPEATENABLE();   
            
            RTDKeyMessageConvert(_SOURCE_KEY_MASK, _SOURCE_KEY_MESSAGE);
			break;

		case _MENU_LEFT_KEY_MASK:
			CLR_KEYREPEATENABLE();	 
			
			RTDKeyMessageConvert(_MENU_LEFT_KEY_MASK, _MENU_LEFT_KEY_MESSAGE);
			break;
			
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
#if(_SHOW_KEY_MESSAGE == _ON)
        case _SHOW_KEYTEST_MASK:
            if(GET_ATE_COMMAND_STATUS()&&GET_OSD_STATE()==_MENU_NONE)
            {
                OsdDisplayDisableOsd();
                SET_KEYTEST_STATUS();
                NVRamSaveFactoryData();
            }
            break;
#endif            
#endif

        default:
            CLR_KEYREPEATSTART();
            CLR_KEYREPEATENABLE();            
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_KEY_REPEAT_ENABLE);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DDCCI_ONOFF);   //關閉DDCCI OSD ON/OFF計數
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_LOCK);   //關閉OSD LOCK
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_EDIDVERSION_CLEAR);
#endif
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_LBL_HOTKEY_FUNCTION == _ON))
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LOW_BLUE_LIGHT);
#endif   


#if 0//Robert Wang 20130605
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
#endif

            //????(???OKey???)                             
            if(((g_ucKeyStatePrev == _MENU_KEY_MASK)|| (g_ucKeyStatePrev == _EXIT_KEY_MASK) 
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		
                ||(g_ucKeyStatePrev == _RIGHT_KEY_MASK) 
#endif
                )&&(GET_OSD_STATE() == _MENU_NONE))
            {
                //Menu放掉動作處理
                if(GET_KEYMESSAGE() == _HOLD_KEY_MESSAGE)
                {
                    SET_KEYMESSAGE(_NONE_KEY_MESSAGE);                    
                }
                else
                { 
                   if(GET_Key_Relax_FLAG() == _TRUE)
                   {                       
                       g_ucKeyStatePrev=_NONE_KEY_MESSAGE;
                       CLR_Key_Relax_FLAG();  
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
    if((g_ucKeyStatePrev ^ g_ucKeyStateCurr) & ucKeyMask)     //Key按下
    {
#if 0//Robert Wang 20130605
        if((ucKeyMsg == _LEFT_KEY_MESSAGE) && (GET_OSD_STATE() == _MENU_NONE) && (GET_FAIL_SAFE_MODE() == _FALSE)
        && (SysSourceGetSourceType() == _SOURCE_VGA))
        {
            SET_KEYMESSAGE(_NONE_KEY_MESSAGE);
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_DO_AUTO_COLOR);
        }                     
        else if( ((ucKeyMsg == _MENU_KEY_MESSAGE)||(ucKeyMsg == _EXIT_KEY_MESSAGE)) && (GET_OSD_STATE() == _MENU_NONE) )         
#else
        if( ((ucKeyMsg == _MENU_KEY_MESSAGE)||(ucKeyMsg == _EXIT_KEY_MESSAGE)) && (GET_OSD_STATE() == _MENU_NONE) )         
#endif
        {
            SET_KEYMESSAGE(_NONE_KEY_MESSAGE);    //Menu None時,按Menu or Exit Key取消按下動作
        }        
        else
        {
            SET_KEYMESSAGE(ucKeyMsg);
        }
    }
    else                                                   //Key Hold住
    {
#if 1//Robert Wang 20130603
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
#else
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
#endif
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

#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
