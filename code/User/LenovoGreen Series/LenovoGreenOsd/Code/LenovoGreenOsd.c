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
// ID Code      : UserOSD.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSD__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LEONVO_GREEN_OSD)

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
StructOsdInfo g_stOsdInfo = {0};

WORD xdata g_usAdjustValue0 = 0;
WORD xdata g_usAdjustValue1 = 0;
WORD xdata g_usAdjustValue2 = 0;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserOsdHandler(void);
void RTDOsdSystemFlowProc(void);
void RTDOsdEventMsgProc(void);
code void (*OperationTable[])(void);
void OsdReset(void);
void OsdTimeoutSaveData(void);//Eli 20121001 modify bug T9CGT478FEG3HN-74,T9CGT478FEG3HN-77.
//***************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : OSD Handler, executed in the main loop
// Input Value  : None
// Output Value : None
//--------------------------------------------------
//OSD處理(主迴圈)
void UserOsdHandler(void)
{
    RTDOsdSystemFlowProc();    //OSD(依據Power & Mode狀態)處理
    RTDOsdEventMsgProc();      //OSD動作事件處理
}

//--------------------------------------------------
// Description  : OSD system flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
//OSD(依據Power & Mode狀態)處理
void RTDOsdSystemFlowProc(void)
{        
    switch(SysModeGetModeState())                      //目前Mode狀態
    {
        case _MODE_STATUS_POWER_OFF:

            if(SysModeGetModeStateChange() == _TRUE)   //Power OFF(Mode)State轉態第一次
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SET_SHOW_SOURCE_INFO(_ON);
                SET_PREVIOUS_INPUT_PORT(UserCommonNVRamGetSystemData(_SEARCH_PORT));
            }
            
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)            
            SET_OSD_IN_FACTORY_MENU_STATUS(_OFF);
    		if(GET_ATE_COMMAND_STATUS())
    		{
    			UserCommonEepromRead(_EEPROM_EDID_VERSIONCODE_ADDRESS, 1, pData);
    			if(pData[0]==_EDID_VERSION_CODE)
    			{
    	            CLR_ATE_COMMAND_STATUS();//FOR ATE MODE
                    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LED_FLASH);
    	            NVRamSaveFactoryDate();
    			}
    		}

            g_ucOsdFlyH = _OSD_FLY_H_STEP/2;// 20120927
            g_ucOsdFlyV = _OSD_FLY_V_STEP/2;
            SET_OSD_FLY_H_STATE(); 
            SET_OSD_FLY_V_STATE();

#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
			g_ucOsdFlyH = _OSD_FLY_H_STEP/2;
			g_ucOsdFlyV = _OSD_FLY_V_STEP/2;
			
			SET_OSD_FLY_H_STATE(); 
			SET_OSD_FLY_V_STATE();			
#endif
            
            break;        
            
        case _MODE_STATUS_INITIAL:

            if(SysModeGetModeStateChange() == _TRUE)   //Initial(Mode)State轉態第一次
            {
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
                TPVDFMInternalADCCheck(); //DFM rev05 patch note 2
#endif
                OsdDispShowLogo();   
				SET_PREVIOUS_INPUT_PORT(UserCommonNVRamGetSystemData(_SEARCH_PORT));
//顯示Logo
            }
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    #if(_ADC_SELF_CALIBRATION == _ON)//ym20130924 .      
            //ym20131030 . UserCommonNVRamLoadADCSetting(_COLOR_SPACE_RGB);
            //ym20131030 . if((g_stAdcData.ucAdcGainMSB[0] == _ADC_RGB_DEFAULT_RED_GAIN)&&(g_stAdcData.ucAdcGainMSB[1] == _ADC_RGB_DEFAULT_GREEN_GAIN)&&(g_stAdcData.ucAdcGainMSB[2] == _ADC_RGB_DEFAULT_BLUE_GAIN))
            if(GET_INTERNAL_AUTOCOLOR() == _FAIL)
            {
                WISTRONFactoryAutoDoWhiteBalance();//ym20130924 . free run mode DoWhiteBalance for Lear(Lear Lee/WZS/Wistron) require 
            }
    #endif                            
#endif
            
#if(_OSD_3D_FUNCTION == _ON)        
            if(!GET_OSD_ROTATE_STATUS())
            {
                ScalerOsdFrameControlAllByte(0x250, _OSD_WITHOUT_DB, 0x00, 0x03, 0x00); //window0
                ScalerOsdFrameControlAllByte(0x254, _OSD_WITHOUT_DB, 0x00, 0x03, 0x00); //window1
                ScalerOsdFrameControlAllByte(0x25C, _OSD_WITHOUT_DB, 0x00, 0x0f, 0x00); //window3
                ScalerOsdFrameControlAllByte(0x264, _OSD_WITHOUT_DB, 0x00, 0x0f, 0x00); //window5//select Item
                ScalerOsdFrameControlAllByte(0x268, _OSD_WITHOUT_DB, 0x00, 0x0a, 0x00); //window6//select ICon            
            }
    
#if(_2D_TO_3D_FUNCTION == _OFF)
            if(GET_OSD_3D_STATUS() == _3D_2D_TO_3D)
            {
                SET_OSD_3D_STATUS(_3D_OFF);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            }
#endif

            RTDOsdDisplay3DEffectRealValueUpdate();
#endif
            break; 
            
        case _MODE_STATUS_SEARCH:
            
            if(SysModeGetModeStateChange()== _TRUE)                
            {
                UserInterfaceKeyPadLedControl(_LED_POWER_SEARCH);
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
                PCB_A0_EDID_EEPROM_WRITE_PROTECT(_HIGH);//unprotect
#endif                
            }    
            if((SysSourceGetInputPort() != GET_PREVIOUS_INPUT_PORT_STATUS()) && (GET_SHOW_SOURCE_INFO() == _OFF) && (GET_FACTORY_BURNIN() == _OFF))                 
            {
                SET_SHOW_SOURCE_INFO(_ON);
                SET_PREVIOUS_INPUT_PORT(SysSourceGetInputPort());
            }
            break;
            
        case _MODE_STATUS_DISPLAY_SETTING:
            if(SysModeGetModeStateChange()== _TRUE)
            {
				DebugMessageOsd("1.---_DISPLAY_SETTING_STATE", 0);
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)//DFM
#if (_PANEL_VCOM_ADJUST_FUNCTION == _ON)
				TPVFCCheckPanelVcom();
#endif
#endif
				SET_PREVIOUS_INPUT_PORT(SysSourceGetInputPort());
        	}
            break;
            
        case _MODE_STATUS_ACTIVE:

            if(SysModeGetModeStateChange()== _TRUE)                
            {				
				if(GET_FAIL_SAFE_MODE() == _FALSE)
				{
	                UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);

					// jimmy 20120823 for aspect ratio
		   			if(GET_OSD_STATE() != _MENU_NONE)
					{
						ScalerOsdEnableOsd();
					}                				
				} 
				//20130312 Abel DCR Modify				  
#if(_USER_DCR_FUNCTION == _ON)
				if(GET_OSD_DCR_STATUS() == _OFF)
				{
					ScalerTimer1SetTimerCount(_TIMER_OFF);	//10ms Timer1中斷停止
				}	 
#endif
#if(_AUDIO_EXTERNAL_AMP_SUPPORT == _ON)                
				UserAdjustAudioVolume(GET_OSD_VOLUME());
#endif                
            }

			if(GET_FAIL_SAFE_MODE())
			{
				break;
			}

#if(_ENERGY_STAR_SUPPORT == _ON)
            if(GET_OSD_ES_STATUS() == _ON)
            {
                UserCommonAdjustESDcrAdjust();
            }
#elif(_USER_DCR_FUNCTION == _ON)
						if((GET_OSD_DCR_STATUS() == _ON) && (!((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))))
						{
							UserAdjustDCRMeasure(); 		 //DCR 量測調整修正(隨時在做)
						}
						else
						{
							ScalerTimer1SetTimerCount(_TIMER_COUNT_10_MS);	//10ms Timer1中斷一次 
						}	 
#endif

#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
#if(_SHOW_KEY_MESSAGE == _ON)
            if(GET_ATE_COMMAND_STATUS()&&GET_KEYTEST_STATUS()&&(GET_KEYMESSAGE() != _NONE_KEY_MESSAGE))
            {
                OsdShowKeyMessage();  
                return;
            }
#endif
#endif
            
		    //Key處理
		    if(GET_KEYMESSAGE() < _KEY_AMOUNT)
		    {
		    	if((GET_OSD_STATE() == _MENU_NONE) && (ScalerOsdGetOsdEnable() == _TRUE))
		    	{	
		    		OsdDispDisableOsdTimerEvent();	
				    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
		    	}
		    	else if(GET_OSD_LOCK_STATUS() == _ON)
				{
					SET_KEYHOLDKEY();//lorimiao 20130927 for OSD lock issue
					OsdDispMessage(_MSG_LOCK);
				#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
					ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
				#elif(_FACTORY_MODE_OWNER == _OWNER_TPV)
					ScalerTimerReactiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_DISABLE);
				#else
					ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
				#endif
				}
				else
				{
		            SET_OSD_PRE_STATE(GET_OSD_STATE());
		            (*OperationTable[GET_OSD_STATE()])();            //OSD Menu處理            

	                if(GET_FACTORY_MODE() == _FALSE)
                    {      
	                    ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
                    }
				}
		    }        


            
            break;
            
        case _MODE_STATUS_NOSUPPORT:

            if(SysModeGetModeStateChange()== _TRUE)                        //No Support(Mode)State轉態第一次  
            {
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSUPPORT_MSG);
                UserInterfaceKeyPadLedControl(_LED_POWER_NOSUPPORT);       //LED控制(No Support State)  
            }

            break;
            
        case _MODE_STATUS_NOSIGNAL:

            if(SysModeGetModeStateChange()== _TRUE)                         //No Signal(Mode)State轉態第一次   
            {
				SET_PREVIOUS_INPUT_PORT(UserCommonNVRamGetSystemData(_SEARCH_PORT));   
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
				if(TPVDFMCableWPCheck()==_TRUE)//DFM rev02 patch note 7
					return;
#endif

#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
				// lorimiao 20130904 for DDCCI switch to VGA port for run factory mommand
                if(GET_FACTORY_MODE() == _TRUE)
                {
                    ScalerMcuDdcciSwitchPort(_DDCCI_MODE, _A0_INPUT_PORT);
                }

			    if((_FALSE == SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT)))&&(_ON == GET_FACTORY_MODE()))
			    {   
			        ucLcdConditionPattern=0;
			        FactoryBurnInPattern();
			    }
			    else
#endif
                {//Eli 20121205 Modify No cable & No signal message issue.
                    if((SysSourceGetCableDetect(_A0_INPUT_PORT) == _TRUE) || (SysSourceGetCableDetect(_D0_INPUT_PORT) == _TRUE) || (SysSourceGetCableDetect(_D1_INPUT_PORT) == _TRUE))
                    {
                        ScalerTimerActiveTimerEvent(SEC(0), _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);   //2秒後顯示No Signal
                    }
                    else
                    {  
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)//ym20130923 .             
                        if(GET_ATE_COMMAND_STATUS())
                        {
                            WISTRONFactoryAdjustBurnInPattern();
                        }
                        else
#endif
                        {
                            ScalerTimerActiveTimerEvent(SEC(0), _USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);    //2秒後顯示No Cable
                        }
                    }
                }
            }

            break;
            
        case _MODE_STATUS_POWER_SAVING:

    		/*//lorimiao 20131023 for DDCCI power saving Command issue
            if(SysSourceGetCableDetect(SysSourceGetInputPort()) == _FALSE)
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
            }
    		*/
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
			if((GET_FORCE_POW_SAV_STATUS() == _TRUE) &&  (GET_A0_CABLE_STATUS() == _FALSE)&& (SysSourceGetInputPort() == _A0_INPUT_PORT))
			{
			
				if(ScalerSyncVgaPreDetect() == _FALSE)
				{
					SET_FORCE_POW_SAV_STATUS(_FALSE);
					SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
					SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
				}
				
			}
#endif
        
            if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
            {
                if(GET_OSD_POWER_SAVING_SHOW_SOURCE() == _TRUE)
                {
                    SET_OSD_POWER_SAVING_SHOW_SOURCE(_FALSE);
                    
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG);
                }
                else if(GET_OSD_WAKE_UP_SWITCH_DDCCI_PORT() == _TRUE)
                {
                    SET_OSD_WAKE_UP_SWITCH_DDCCI_PORT(_FALSE);
                    
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG);
                    
                }
            }

#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON) 
            if(GET_KEYMESSAGE() < _KEY_AMOUNT)//ym20131009 .  for push any key to wake up
            {
                if(SysPowerGetPowerStatus() == _POWER_STATUS_SAVING)
                {
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_NOSIGNAL);
                    UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
                }
                else if(SysPowerGetPowerStatus() == _POWER_STATUS_NOSUPPORT_SAVING)
                {
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                    UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
                }
            }
#endif
            SET_SHOW_SOURCE_INFO(_ON);

            break;

        case _MODE_STATUS_FACTORY:

            break;
            
        default:

            break;
    }
       
}

//--------------------------------------------------
// Description  : OSD event message processing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
 //OSD動作事件處理
void RTDOsdEventMsgProc(void)
{
    switch(GET_OSD_EVENT_MESSAGE())
    {
        case _OSDEVENT_SHOW_NOSIGNAL_MSG:
                    
//            RTDOsdDisplayNoSignalProc();
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
			ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	//Ada.chen 20150923_1
#endif
			OsdDispMessage(_MSG_SLEEP);
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);

            ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_FLYING);
#if(_LEONVO_GREEN_OSD_STYLE == _LEONVO_GREEN_OSD_STYLE_0)	
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);
#else
            ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);
#endif
#else
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);
#endif
            break;

        case _OSDEVENT_SHOW_NOCABLE_MSG:
            
//            RTDOsdDisplayNoCableProc();
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
			ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	//Ada.chen 20150923_1
#endif
			OsdDispMessage(_MSG_NOCABLE);
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);           
            ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_FLYING);
			ScalerTimerActiveTimerEvent(SEC(20), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);                        
            break;

        case _OSDEVENT_SHOW_NOSUPPORT_MSG:
            
//            RTDOsdDisplayNoSupportProc();
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
			ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	//Ada.chen 20150923_1
#endif
			OsdDispMessage(_MSG_OOR);
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);

            ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_FLYING);

			//>85hz and <50hz will go to ps after 2 min,
			if((GET_INPUT_TIMING_VFREQ() >= _OOR_V_FREQ_UPPER_BOUND) || (GET_INPUT_TIMING_VFREQ() <= _FAIL_SAVE_V_FREQ_LOWER_BOUND))
			{
				ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_FLY_OSD_TO_POWER_SAVING);                        
			}
            break;


        case _OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG:

#if (_FACTORY_MODE_OWNER == _OWNER_TPV)//DFM do not show input info
			if (TPVDFMAutoConfigByPass()==_TRUE)
            {
              	ScalerTimerActiveTimerEvent(SEC(0), _USER_TIMER_EVENT_OSD_SHOW_NO_SUPPORT);	                    
            }  
            else
            {
            	ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_NO_SUPPORT);	                    
            }
#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
        	ScalerTimerActiveTimerEvent(SEC(0.1), _USER_TIMER_EVENT_OSD_SHOW_NO_SUPPORT);	                    
#else
        	ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_NO_SUPPORT);	                    
#endif                   
            UserInterfaceKeyPadLedControl(_LED_POWER_NOSUPPORT);       //LED控制(No Support State)  
            
            break;        

        case _OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG:

//            RTDOsdDisplayWakeUpShowSource();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);

            break;

        case _OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG:

//            RTDOsdDisplayWakeUpSwitchDdcciPort();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);

            break;
            
        case _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG:

            //RTDOsdDisplayPowerSavingProc();
            //UserInterfacePanelPowerAction(_BACKLIGHT_ON);
            //ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);

            break;
            
        case _OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG:

            OsdDispDisableOsdTimerEvent();
            if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) || (SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) || (SysPowerGetPowerStatus() == _POWER_STATUS_NOSUPPORT_SAVING))
            {
                SysPowerSetTargetPowerStatus(_POWER_STATUS_NOSUPPORT_SAVING);
            }
            else
            {
                SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
            }

            break;

#if(_VGA_SUPPORT == _ON)             
        case _OSDEVENT_DO_AUTO_CONFIG_MSG:
            {
            	OsdDispMessage(_MSG_AUTO);//ym20130925 . 
	            UserCommonAutoConfig();                           
	            OsdDispDisableOsdTimerEvent();          
            }
            break;
#endif

        case _OSDEVENT_ACTIVE_DO_ONE_TIME_MSG:
            
#if(_VGA_SUPPORT == _ON) 
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {                
                if(UserInterfaceFirstAutoConfig() == _TRUE)
                {
                	OsdDispMessage(_MSG_AUTO);
		            UserCommonAutoConfig();                           
		            OsdDispDisableOsdTimerEvent();          
                }
            } 
#endif
            if((GET_OSD_STATE() == _MENU_NONE) && (GET_SHOW_SOURCE_INFO()==_ON))
            {
                SET_SHOW_SOURCE_INFO(_OFF);
				SET_PREVIOUS_INPUT_PORT(SysSourceGetInputPort());
                OsdDispTimingAndInputSource();
                ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
            }
            break;

        case _OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG:
            
            UserCommonNVRamSaveSystemData();
            
            break;

#if(_VGA_SUPPORT == _ON)
        case _OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG:
            
            UserCommonNVRamSaveModeUserData();
            
            break;
#endif

        case _OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG:
            
            RTDNVRamSaveOSDData();
            
            break;
            
#if(_VGA_SUPPORT == _ON)
        case _OSDEVENT_SAVE_NVRAM_ADCDATA_MSG:
            
            if(ScalerColorGetColorSpace() == _COLOR_SPACE_RGB)
            {
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
            }
            else
            {
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
            }
            break;
#endif

        case _OSDEVENT_SAVE_NVRAM_COLORPROC_MSG:
            
            RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
            
            break;

        case _OSDEVENT_SAVE_NVRAM_BRICON_MSG:
            
            RTDNVRamSaveBriCon();
            
            break;

        case _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG:

            RTDNVRamSaveSixColorData();

            break;
    }

    SET_OSD_EVENT_MESSAGE(_OSDEVENT_NONE_MSG);
}

WORD OsdDetOverRange(WORD usValue, WORD ucMax, WORD ucMin, BYTE ucRepeat)
{
    if((ucRepeat == _OSD_NO_REPEAT)&&(((usValue == ucMax)&&(GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)) ||((usValue == ucMin)&&(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE))))//ym20131011 . 
    {
        SET_OSD_SLIDER_REDRAW(_OFF);
    }
    else
    {
        SET_OSD_SLIDER_REDRAW(_ON);
    }

    if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
    {
        if(ucRepeat == _OSD_NO_REPEAT)
        {
            if(usValue > ucMin)
            {
                usValue--;
            }
        }
        else  // _OSD_REPEAT
        {
            if(usValue == ucMin)
            {
                usValue = ucMax;
            }
            else
            {
                usValue--;
            }
        }
    }
    else
    {
        if(ucRepeat == _OSD_NO_REPEAT)
        {
            if(usValue < ucMax)
            {
                usValue++;
            }
        }
        else
        {
            if(usValue == ucMax)
            {
                usValue = ucMin;
            }
            else
            {
                usValue++;
            }        
        }
    }
    return usValue;
}


/*--------------------------------------------*/
/*                  OSD None                  */
/*--------------------------------------------*/
void OsdMenuNone(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			OsdDispDisableOsdTimerEvent();

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))		
			if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || ((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB)))
			{
				SET_OSD_STATE(_OSD_MAIN_LOWBLUELIGHT);
			}
#else
			if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
			{
				if(SysSourceGetSourceType() == _SOURCE_VGA)
				{
					SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
				}
				else
				{
					SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
				}
			}
#endif
			else
			{
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
                if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
                    {
                        if(SysSourceGetSourceType() == _SOURCE_VGA)
                        {
                            SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
                        }
                        else
                        {
                            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
                        }
                    }
                else
                    {
                        SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
                    }
#else
				SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
#endif
			}			
			
            OsdDispMainMenu(GET_OSD_STATE());       //顯示Main Menu
            break;

        case _RIGHT_KEY_MESSAGE:                    //Bri Hotkey(綠色OSD有)
#if(_USER_DCR_FUNCTION == _ON)
			if(GET_OSD_DCR_STATUS() ==_OFF)
#endif
		{
			if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || ((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB)))
            {
			}
			else
			{
	           SET_OSD_STATE(_OSD_HOTKEY_BRIGHTNESS_ADJUST);                                 
	           OsdDispBriHotkeyMenu();       //顯示Main Menu
			} 
		}			
            break;

        case _LEFT_KEY_MESSAGE: 
#if(_VGA_SUPPORT == _ON) 
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {
            	OsdDispMessage(_MSG_AUTO);
	            UserCommonAutoConfig();                           
	            //OsdDispDisableOsdTimerEvent();     
	            ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_OSD_DISABLE_AUTO_ADJUST_MSG);
            } 
#endif               	
            break;

        case _EXIT_KEY_MESSAGE:                     //Source HotKey(綠色OSD有)
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
            SET_FORCE_POW_SAV_STATUS(_FALSE);
            SET_SHOW_SOURCE_INFO(_ON);
            SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);		    
		    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
            
            if(SysSourceGetInputPort() == _A0_INPUT_PORT)
            {
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)		    
		    SysSourceSwitchInputPort(_D0_INPUT_PORT);
#elif(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)		
		    SysSourceSwitchInputPort(_D1_INPUT_PORT);
#else
		    return;
#endif            
            }      
		    else
            {
               SysSourceSwitchInputPort(_A0_INPUT_PORT);

            }

		    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
		       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
		    {
		        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
		        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
		        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
		    }
#endif
			break;

		default:
			break;
	}
}

/*--------------------------------------------*/
/*             OSD Menu第一層                 */
/*--------------------------------------------*/
//Bri/Con Top Menu(第一層)
void OsdMainMenuBrightContrast(void)
{
	switch(GET_KEYMESSAGE())
	{
        case _MENU_KEY_MESSAGE:                    //進入第二層
	#if(_USER_DCR_FUNCTION == _ON)
	  if(GET_OSD_DCR_STATUS() ==_ON)
	  	{
			SET_OSD_STATE(_OSD_PICTURE_DCR);
            OsdDispMainIconChange(_MAIN_ICON_PICTURE, _OSD_INDICATE);// 取消 "指到main icon picture"
            OsdDispSubIcon(_SUB_ICON_DCR, _OSD_SELECT);       //Brightness Icon反白 
            OsdDispMainMenuString(_SUB_STRING_DCR);           //顯示說明字串
	  	}
	  else
	  	{
 		    SET_OSD_STATE(_OSD_PICTURE_BRIGHTNESS);
 		    OsdDispMainIconChange(_MAIN_ICON_PICTURE, _OSD_INDICATE);// 取消 "指到main icon picture"
 		    OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_SELECT);	   //Brightness Icon反白 
 		    OsdDispMainMenuString(_SUB_STRING_BRIGHTNESS);		   //顯示說明字串
	  	}
    #else
			SET_OSD_STATE(_OSD_PICTURE_BRIGHTNESS);
			OsdDispMainIconChange(_MAIN_ICON_PICTURE, _OSD_INDICATE);// 取消 "指到main icon picture"
			OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_SELECT);		 //Brightness Icon反白 
			OsdDispMainMenuString(_SUB_STRING_BRIGHTNESS);			 //顯示說明字串    
	#endif
            OsdDispKeyInfo(_KEY_INFO_CANCEL);
            break; 

        case _RIGHT_KEY_MESSAGE: 
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
			 SET_OSD_STATE(_OSD_MAIN_LOWBLUELIGHT);
#else
			if(SysSourceGetSourceType() == _SOURCE_VGA)
			{
				SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
			}
			else
			{
				SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
			}
#endif			
            OsdDispMainIconSwitch();               //第一層OSD左右Key動作
            break;

        case _LEFT_KEY_MESSAGE: 
			if(GET_FACTORY_MODE())
			{
				SET_OSD_STATE(_OSD_MAIN_TPV_FACTORY);
			}
			else
        	{
        		SET_OSD_STATE(_OSD_MAIN_EXIT);
        	}            
            OsdDispMainIconSwitch();               //第一層OSD左右Key動作
            break;

        case _EXIT_KEY_MESSAGE: 
            OsdDispDisableOsdTimerEvent();         //回到上一層(Menu None)
            SET_KEYHOLDKEY();
			break;

		default:
			break;
	}
}    
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))		           
void OsdMainMenuLowBlueLight(void)
{
	switch(GET_KEYMESSAGE())
	{
        case _MENU_KEY_MESSAGE:   
            OsdDispMainIconChange(_MAIN_ICON_LOWBLUELIGHT, _OSD_INDICATE);

            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                SET_OSD_STATE(_OSD_LOWBLUELIGHT_ENABLE);
                OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_ENABLE, _OSD_SELECT); 
                OsdDispMainMenuString(_MAIN_STRING_LOWBLUELIGHT_ENABLE);
            }
            else if(GET_LOWBLUELIGHT_STATUS() == _DISABLE)
            {
                SET_OSD_STATE(_OSD_LOWBLUELIGHT_DISABLE);
                OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_DISABLE, _OSD_SELECT); 
                OsdDispMainMenuString(_MAIN_STRING_LOWBLUELIGHT_DISABLE);
            }
            
            OsdDispKeyInfo(_KEY_INFO_CANCEL);
            break; 

        case _RIGHT_KEY_MESSAGE: 
 			if(SysSourceGetSourceType() == _SOURCE_VGA)
			{
				SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
			}
			else
			{
				SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
			}
           
            OsdDispMainIconSwitch();          
            break;

        case _LEFT_KEY_MESSAGE: 
			if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || ((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB)))
			{
				if(GET_FACTORY_MODE())
				{
					SET_OSD_STATE(_OSD_MAIN_TPV_FACTORY);
				}
				else
	        	{
	        		SET_OSD_STATE(_OSD_MAIN_EXIT);
	        	}            
			}
			else
			{
				SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
			}			            
            OsdDispMainIconSwitch();             
            break;

        case _EXIT_KEY_MESSAGE: 
            OsdDispDisableOsdTimerEvent();    
            SET_KEYHOLDKEY();
			break;

		default:
			break;
	}
}
#endif			

//Postion Top Menu(第一層)
void OsdMainMenuImagePostion(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:                    //進入第二層
            SET_OSD_STATE(_OSD_POS_HPOS);
            OsdDispMainIconChange(_MAIN_ICON_POSTION, _OSD_INDICATE); //MainIcon反灰
            OsdDispSubIcon(_SUB_ICON_HPOS, _OSD_SELECT);
            OsdDispMainMenuString(_SUB_STRING_HPOS);                  //顯示Sub Menu字串      
            OsdDispKeyInfo(_KEY_INFO_CANCEL);
            break;

        case _RIGHT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_MAIN_IMAGESETUP);
            OsdDispMainIconSwitch();              //第一層OSD左右Key動作
            break;

        case _LEFT_KEY_MESSAGE: 
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))	
			SET_OSD_STATE(_OSD_MAIN_LOWBLUELIGHT);
#else
			if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
			{
				if(GET_FACTORY_MODE())
				{
					SET_OSD_STATE(_OSD_MAIN_TPV_FACTORY);
				}
				else
	        	{
	        		SET_OSD_STATE(_OSD_MAIN_EXIT);
	        	}            
			}
			else
			{
			    #if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
			    if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
                {
                    if(GET_FACTORY_MODE())
                    {
                        SET_OSD_STATE(_OSD_MAIN_TPV_FACTORY);
                    }
                    else
                    {
                        SET_OSD_STATE(_OSD_MAIN_EXIT);
                    }
                }
                else
                {
    				SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
                }
                #else
                SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
                #endif
			}	
#endif			
            OsdDispMainIconSwitch();              //第一層OSD左右Key動作        
            break;

        case _EXIT_KEY_MESSAGE: 
            OsdDispDisableOsdTimerEvent();        //回到上一層(Menu None)
            SET_KEYHOLDKEY();
            break;

        default:
            break;
    }
}    

//Setup Top Menu(第一層)
void OsdMainMenuImageSetup(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:                    //進入第二層
            SET_OSD_STATE(_OSD_SETUP_AUTOMATIC);
            OsdDispMainIconChange(_MAIN_ICON_SETUP, _OSD_INDICATE);  //MainIcon反灰
            OsdDispSubIcon(_SUB_ICON_AUTOMATIC, _OSD_SELECT);
            OsdDispMainMenuString(_SUB_STRING_AUTOMATIC);            //顯示Sub Menu字串  
            OsdDispKeyInfo(_KEY_INFO_CANCEL);
            break;

        case _RIGHT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
            OsdDispMainIconSwitch();               //第一層OSD左右Key動作
            break;

        case _LEFT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
            OsdDispMainIconSwitch();               //第一層OSD左右Key動作       
            break;

        case _EXIT_KEY_MESSAGE: 
            OsdDispDisableOsdTimerEvent();         //回到上一層(Menu None)
            SET_KEYHOLDKEY();
            break;

        default:
            break;
    }
}

//Properties Top Menu(第一層)
void OsdMainMenuImageProperties(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE: 
#if (_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)          
        if((GET_LOWBLUELIGHT_STATUS() == _ENABLE)||(GET_OSD_DCR_STATUS() == _ON))
            {
                if(UserAdjustCheckAspectRatio() == _TRUE)
                    {
                        SET_OSD_STATE(_OSD_PROP_SCALING);
                        OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_INDICATE);
                        OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT);
                        OsdDispMainMenuString(_SUB_STRING_SCALING); 
                    }
                else
                    {
                        SET_OSD_STATE(_OSD_PROP_BLUELIGHT);
                        OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_INDICATE);
                        OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_SELECT);
                        OsdDispMainMenuString(_SUB_STRING_BLUELIGHT); 
                    }
            }
        else
            {
                SET_OSD_STATE(_OSD_PROP_COLOR);
                OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_INDICATE);
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);
                OsdDispMainMenuString(_SUB_STRING_COLOR);                      
            }
#else
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if((GET_LOWBLUELIGHT_STATUS() == _ENABLE)
	#if(_USER_DCR_FUNCTION == _ON)	
			||(GET_OSD_DCR_STATUS() == _ON)
	#endif
	)
            {
#if(_INPUT_PORT_MAX != 1)
                SET_OSD_STATE(_OSD_PROP_INPUT);
                OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_INDICATE);
                OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT);
                OsdDispMainMenuString(_SUB_STRING_INPUT); 
#else
#if(_ASPECT_RATIO_SUPPORT==_ON)
				if(UserAdjustCheckAspectRatio() == _TRUE)
				{
					SET_OSD_STATE(_OSD_PROP_SCALING);
					OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_INDICATE);
					OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT);
					OsdDispMainMenuString(_SUB_STRING_SCALING); 
				}
#elif(_OD_SUPPORT==_ON)
                SET_OSD_STATE(_OSD_PROP_OD);
                OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_INDICATE);
                OsdDispSubIcon(_SUB_ICON_OD, _OSD_SELECT);
                OsdDispMainMenuString(_SUB_STRING_OD); 
 #endif                
#endif                
            }
            else
#endif                
            {
                SET_OSD_STATE(_OSD_PROP_COLOR);
                OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_INDICATE);
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);
                OsdDispMainMenuString(_SUB_STRING_COLOR);                      
            }
#endif
            OsdDispKeyInfo(_KEY_INFO_CANCEL);
            break;

        case _RIGHT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_MAIN_OPTION);
            OsdDispMainIconSwitch();               //第一層OSD左右Key動作
            break;

        case _LEFT_KEY_MESSAGE:
			if(SysSourceGetSourceType() == _SOURCE_VGA)
			{
				SET_OSD_STATE(_OSD_MAIN_IMAGESETUP);
			}
			else
			{
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))		           
    			SET_OSD_STATE(_OSD_MAIN_LOWBLUELIGHT);
#else
				if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))			
				{
					if(GET_FACTORY_MODE())
					{
						SET_OSD_STATE(_OSD_MAIN_TPV_FACTORY);
					}
					else
		        	{
		        		SET_OSD_STATE(_OSD_MAIN_EXIT);
		        	}            
				}
				else
				{
					SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
				}
#endif			
			}            
            OsdDispMainIconSwitch();               //第一層OSD左右Key動作       
            break;

        case _EXIT_KEY_MESSAGE: 
            OsdDispDisableOsdTimerEvent();         //回到上一層(Menu None)
            SET_KEYHOLDKEY();
            break;

        default:
            break;
    }
}

//Option Top Menu(第一層)
void OsdMainMenuOption(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:                    //進入第二層
            SET_OSD_STATE(_OSD_OPTION_INFORMATION);
            OsdDispMainIconChange(_MAIN_ICON_OPTION, _OSD_INDICATE);
            OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_SELECT);
            OsdDispMainMenuString(_SUB_STRING_INFORMATION);           
            OsdDispKeyInfo(_KEY_INFO_CANCEL);
            break;

        case _RIGHT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_MAIN_EXIT);
            OsdDispMainIconSwitch();               //第一層OSD左右Key動作   
            break;

        case _LEFT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
            OsdDispMainIconSwitch();               //第一層OSD左右Key動作           
            break;

        case _EXIT_KEY_MESSAGE: 
            OsdDispDisableOsdTimerEvent();         //回到上一層(Menu None)
            SET_KEYHOLDKEY();
            break;

        default:
			break;
	}
}

//Exit Top Menu
void OsdMainMenuExit(void)
{
	switch(GET_KEYMESSAGE())
	{
        case _MENU_KEY_MESSAGE:                     
            OsdDispDisableOsdTimerEvent();          
            SET_KEYHOLDKEY();
            break;

		case _RIGHT_KEY_MESSAGE: 
			if(GET_FACTORY_MODE())
			{
				SET_OSD_STATE(_OSD_MAIN_TPV_FACTORY);
			}
			else
			{
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))		           
				if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || ((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB)))			
				{
					SET_OSD_STATE(_OSD_MAIN_LOWBLUELIGHT);
				}
#else
				if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))			
				{
					if(SysSourceGetSourceType() == _SOURCE_VGA)
					{
						SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
					}
					else
					{
						SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
					}
				}
#endif			
				else
				{
				    #if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
                    if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
                    {
    					if(SysSourceGetSourceType() == _SOURCE_VGA)
    					{
    						SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
    					}
    					else
    					{
    						SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
    					}                        
                    }
                    else
                    {
                        SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
                    }
                    #else
					SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
                    #endif
				}				
			}
			
			OsdDispMainIconSwitch();		
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_MAIN_OPTION);
			OsdDispMainIconSwitch();				
			break;

		case _EXIT_KEY_MESSAGE: 
			OsdDispDisableOsdTimerEvent();
            SET_KEYHOLDKEY();
			break;

		default:
			break;
	}
}

//TPV Factory Menu(第一層)
void OsdMainMenuTPVFactory(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
            TPVFactoryMenuPro();
			break;

		case _RIGHT_KEY_MESSAGE:
            TPVFactoryRightPro();
			break;

		case _LEFT_KEY_MESSAGE: 
            TPVFactoryLeftPro();
			break;

		case _EXIT_KEY_MESSAGE:
            TPVFactoryExitPro();
            SET_KEYHOLDKEY();
			break;
            
		default:
			break;
	}
}

/*--------------------------------------------*/
/*             OSD Menu第二層                 */
/*--------------------------------------------*/
//Bright Icon Menu(第二層)
void OsdPictureBright(void)
    {
	switch(GET_KEYMESSAGE())
	{
        case _MENU_KEY_MESSAGE:                                          //進入第三層                                                       
			g_usAdjustValue0 = GET_OSD_BACKLIGHT();
            SET_OSD_STATE(_OSD_PICTURE_BRIGHTNESS_ADJUST);                                    
            OsdDispContentClear();                                       //清除中間頁面...Row4~Row11
            OsdDispSubIcon(_TITLE_ICON_BRIGHTNESS, _OSD_INDICATE); 
            OsdDispMainMenuString(_MAIN_STRING_BRIGHTNESS);                                    
            OsdDispSubIcon(_SUB_ICON_BRIGHTNESS_ADJUST, _OSD_INDICATE);  //顯示Icon   
            OsdDispSlider(_SLIDER_BRIGHTNESS);                           //顯示調整Bar                            
            break;

#if((_LENOVO_DPS_SUPPORT == _ON)||(_USER_DCR_FUNCTION == _ON))
		case _RIGHT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_PICTURE_CONTRAST);                           //設定OSD狀態Index(進入Contrast Icon Menu第二層)              
            OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);         //顯示Icon     
            OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_CONTRAST);
			break;

		case _LEFT_KEY_MESSAGE:
#if	(_LENOVO_DPS_SUPPORT == _ON)	
            SET_OSD_STATE(_OSD_PICTURE_DPS);                           //設定OSD狀態Index(進入Contrast Icon Menu第二層)              
            OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);         //顯示Icon     
            OsdDispSubIcon(_SUB_ICON_DPS, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_DPS);
#elif (_USER_DCR_FUNCTION == _ON)	
			SET_OSD_STATE(_OSD_PICTURE_DCR);						   //設定OSD狀態Index(進入Contrast Icon Menu第二層) 			 
			OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);		 //顯示Icon 	
			OsdDispSubIcon(_SUB_ICON_DCR, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_DCR);
#endif
			break;

#else
		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_PICTURE_CONTRAST);                           //設定OSD狀態Index(進入Contrast Icon Menu第二層)              
            OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);         //顯示Icon     
            OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_CONTRAST);
			break;
#endif

        case _EXIT_KEY_MESSAGE:                                          //回到上一層(Top Menu...第一層)
            SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
            OsdDispMainIconChange(_MAIN_ICON_PICTURE, _OSD_SELECT);       
            OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);    
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

		default:
			break;
	}
}

//Contrast Icon Menu(第二層)
void OsdPictureContrast(void)
{
    switch(GET_KEYMESSAGE())
    {                                                                                   
        case _MENU_KEY_MESSAGE:                                          //進入第三層   
        	g_usAdjustValue0 = GET_OSD_CONTRAST();
            SET_OSD_STATE(_OSD_PICTURE_CONTRAST_ADJUST);                                        
            OsdDispContentClear();  //清除中間頁面..  
            OsdDispSubIcon(_TITLE_ICON_CONTRAST, _OSD_INDICATE);             
            OsdDispMainMenuString(_MAIN_STRING_CONTRAST);                                                        
            OsdDispSubIcon(_SUB_ICON_CONTRAST_ADJUST, _OSD_INDICATE);    //顯示Icon  
            OsdDispSlider(_SLIDER_CONTRAST);                             //顯示調整Bar                                       

            break;                
            
#if((_LENOVO_DPS_SUPPORT == _ON)||(_USER_DCR_FUNCTION == _ON))
        case _RIGHT_KEY_MESSAGE:   
#if (_LENOVO_DPS_SUPPORT == _ON)	
            SET_OSD_STATE(_OSD_PICTURE_DPS);                         //設定OSD狀態Index(進入Brightness Icon Menu第二層)                                
            OsdDispSubIcon(_SUB_ICON_DPS, _OSD_SELECT);           //顯示Icon                                                               
            OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);                                                                     
            OsdDispMainMenuString(_SUB_STRING_DPS);    
#elif (_USER_DCR_FUNCTION == _ON)	
			SET_OSD_STATE(_OSD_PICTURE_DCR);						 //設定OSD狀態Index(進入Brightness Icon Menu第二層) 							   
			OsdDispSubIcon(_SUB_ICON_DCR, _OSD_SELECT); 		  //顯示Icon															   
			OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);																	   
			OsdDispMainMenuString(_SUB_STRING_DCR);    
#endif			
            break;                                                                                 

        case _LEFT_KEY_MESSAGE:                                          
            SET_OSD_STATE(_OSD_PICTURE_BRIGHTNESS);                         //設定OSD狀態Index(進入Brightness Icon Menu第二層)                                
            OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_SELECT);           //顯示Icon                                                               
            OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);                                                                     
            OsdDispMainMenuString(_SUB_STRING_BRIGHTNESS);                                                                   
            break;                                                                                 

#else                                                                         
        case _RIGHT_KEY_MESSAGE:                                                                    
        case _LEFT_KEY_MESSAGE:                                          
            SET_OSD_STATE(_OSD_PICTURE_BRIGHTNESS);                         //設定OSD狀態Index(進入Brightness Icon Menu第二層)                                
            OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_SELECT);           //顯示Icon                                                               
            OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);                                                                     
            OsdDispMainMenuString(_SUB_STRING_BRIGHTNESS);                                                                   
            break;                                                                                 
#endif
                                                                                 
        case _EXIT_KEY_MESSAGE:                                          //回到上一層(Top Menu...第一層) 
            SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
			OsdDispMainIconChange(_MAIN_ICON_PICTURE, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);		
			OsdDispSubStringClear();
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		default:
			break;
	}
}


#if(_LENOVO_DPS_SUPPORT == _ON)
void OsdPictureDps(void)
{
    switch(GET_KEYMESSAGE())
    {                                                                                   
        case _MENU_KEY_MESSAGE:                                          //進入第三層   
        	g_usAdjustValue0 = GET_OSD_ES_STATUS();
            SET_OSD_STATE(_OSD_PICTURE_DPS_ADJUST);                                        
            OsdDispContentClear();  //清除中間頁面..  
            OsdDispSubIcon(_TITLE_ICON_DPS, _OSD_INDICATE);             
            OsdDispMainMenuString(_MAIN_STRING_DPS);                                                        
            if(g_usAdjustValue0 == _ON)
            {
        		OsdDispSubItem(_SUB_ITEM_DPS_ON, _OSD_SELECT);
        		OsdDispSubItem(_SUB_ITEM_DPS_OFF, _OSD_UNSELECT);
            }
            else
            {
            	OsdDispSubItem(_SUB_ITEM_DPS_OFF, _OSD_SELECT);
            	OsdDispSubItem(_SUB_ITEM_DPS_ON, _OSD_UNSELECT);
            }

            break;                
            
        case _RIGHT_KEY_MESSAGE:                                                                    
            SET_OSD_STATE(_OSD_PICTURE_BRIGHTNESS);                         //設定OSD狀態Index(進入Brightness Icon Menu第二層)                                
            OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_SELECT);           //顯示Icon                                                               
            OsdDispSubIcon(_SUB_ICON_DPS, _OSD_UNSELECT);                                                                     
            OsdDispMainMenuString(_SUB_STRING_BRIGHTNESS);                                                                   
            break;                                                                                 

        case _LEFT_KEY_MESSAGE:                                          
            SET_OSD_STATE(_OSD_PICTURE_CONTRAST);                         //設定OSD狀態Index(進入Brightness Icon Menu第二層)                                
            OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_SELECT);           //顯示Icon                                                               
            OsdDispSubIcon(_SUB_ICON_DPS, _OSD_UNSELECT);                                                                     
            OsdDispMainMenuString(_SUB_STRING_CONTRAST);                                                                   
            break;                                                                                 

                                                           
        case _EXIT_KEY_MESSAGE:                                          //回到上一層(Top Menu...第一層) 
            SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
			OsdDispMainIconChange(_MAIN_ICON_PICTURE, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_DPS, _OSD_UNSELECT);		
			OsdDispSubStringClear();
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		default:
			break;
	}
}
#endif

#if(_USER_DCR_FUNCTION == _ON)
//DCR Icon Menu(第二層)
void OsdPictureDCR(void)
{
	
    switch(GET_KEYMESSAGE())
	{                                                                                   
        case _MENU_KEY_MESSAGE:                                          //進入第三層   
        	g_usAdjustValue0 = GET_OSD_DCR_STATUS();
			g_usAdjustValue1 = g_usAdjustValue0;
            SET_OSD_STATE(_OSD_PICTURE_DCR_ADJUST);                                        
            OsdDispContentClear();  //清除中間頁面..  
            OsdDispSubIcon(_TITLE_ICON_DCR, _OSD_INDICATE);             
            OsdDispMainMenuString(_MAIN_STRING_DCR);                                                        
            if(g_usAdjustValue0 == _ON)
            {
        		OsdDispSubItem(_SUB_ITEM_DCR_ON, _OSD_SELECT);
        		OsdDispSubItem(_SUB_ITEM_DCR_OFF, _OSD_UNSELECT);
            }
            else
            {
            	OsdDispSubItem(_SUB_ITEM_DCR_OFF, _OSD_SELECT);
            	OsdDispSubItem(_SUB_ITEM_DCR_ON, _OSD_UNSELECT);
            }

            break;                
            
        case _RIGHT_KEY_MESSAGE:
		 if(GET_OSD_DCR_STATUS() ==_OFF)
			{
	            SET_OSD_STATE(_OSD_PICTURE_BRIGHTNESS);                         //設定OSD狀態Index(進入Brightness Icon Menu第二層)                                
	            OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_SELECT);           //顯示Icon                                                               
	            OsdDispSubIcon(_SUB_ICON_DCR, _OSD_UNSELECT);                                                                     
	            OsdDispMainMenuString(_SUB_STRING_BRIGHTNESS);  
			}
            break;                                                                                 

        case _LEFT_KEY_MESSAGE:  
			if(GET_OSD_DCR_STATUS() ==_OFF)
			{
	            SET_OSD_STATE(_OSD_PICTURE_CONTRAST);                         //設定OSD狀態Index(進入Brightness Icon Menu第二層)                                
	            OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_SELECT);           //顯示Icon                                                               
	            OsdDispSubIcon(_SUB_ICON_DCR, _OSD_UNSELECT);                                                                     
	            OsdDispMainMenuString(_SUB_STRING_CONTRAST);      
			}
            break;                                                                                 

                                                           
        case _EXIT_KEY_MESSAGE:                                          //回到上一層(Top Menu...第一層) 
            SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
			OsdDispMainIconChange(_MAIN_ICON_PICTURE, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_DCR, _OSD_UNSELECT);		
			OsdDispSubStringClear();
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		default:
			break;
	}

}
#endif

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))		           
void OsdLowBlueLightEnable(void)
{
    switch(GET_KEYMESSAGE())
    {                                                                                         
        case _MENU_KEY_MESSAGE: 
			
			SET_LOWBLUELIGHT_STATUS(_ENABLE); //Ada.chen 20150906_1
            RTDNVRamSaveOSDData();
#if(_USER_DCR_FUNCTION == _ON)
			if(GET_OSD_DCR_STATUS() == _ON)
			{
				UserAdjustDCRControl(_OFF);
			}
#endif
            RTDNVRamLoadColorSetting(_CTLOWBLUELIGHT);
            UserAdjustContrast(_LBL_CONTRAST_DEF);
            UserAdjustBacklightPercent(_LBL_BRIGHTNESS_DEF);
            
            SET_OSD_STATE(_OSD_MAIN_LOWBLUELIGHT);    

			OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_STATIC);
            OsdDispMainIconChange(_MAIN_ICON_LOWBLUELIGHT, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_ENABLE, _OSD_UNSELECT);  
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;                                                                                         
                                                                                                           
        case _RIGHT_KEY_MESSAGE:                                                                           
        case _LEFT_KEY_MESSAGE:  
            SET_OSD_STATE(_OSD_LOWBLUELIGHT_DISABLE);
            OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_DISABLE, _OSD_SELECT);                  
            OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_ENABLE, _OSD_UNSELECT);                                                 
            OsdDispMainMenuString(_MAIN_STRING_LOWBLUELIGHT_DISABLE);                                                       
            break;                                                                                         
                                                                                                           
        case _EXIT_KEY_MESSAGE:                  
            SET_OSD_STATE(_OSD_MAIN_LOWBLUELIGHT);                                                         
            OsdDispMainIconChange(_MAIN_ICON_LOWBLUELIGHT, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_ENABLE, _OSD_UNSELECT);  
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}

void OsdLowBlueLightDisable(void)
{
    switch(GET_KEYMESSAGE())
    {                                                                                         
        case _MENU_KEY_MESSAGE: 
			
			SET_LOWBLUELIGHT_STATUS(_DISABLE); //Ada.chen 20150906_1
			RTDNVRamSaveOSDData();
#if(_USER_DCR_FUNCTION == _ON)
			if(GET_OSD_DCR_STATUS() == _ON)
			{
				UserAdjustDCRControl(_ON);
			}
#endif
            if(GET_COLOR_TEMP_STATUS() ==  _COLOR_USER)           			                  
            {
                RTDNVRamLoadColorSetting(_CT_USER);
            } 
            else
            {
			    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }    
            UserAdjustContrast(GET_OSD_CONTRAST());
            UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            
            SET_OSD_STATE(_OSD_MAIN_LOWBLUELIGHT);     
            
			if(GET_COLOR_TEMP_STATUS() == _COLOR_USER)
			{
				OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_UNSELECT);
			}
			else if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
			{
				OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_STATIC);
			}
			else
			{
				OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_UNSELECT);
			}
            
            OsdDispMainIconChange(_MAIN_ICON_LOWBLUELIGHT, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_DISABLE, _OSD_UNSELECT);  
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;                                                                                         
                                                                                                           
        case _RIGHT_KEY_MESSAGE:                                                                           
        case _LEFT_KEY_MESSAGE:                                                  
            SET_OSD_STATE(_OSD_LOWBLUELIGHT_ENABLE);
            OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_ENABLE, _OSD_SELECT);                  
            OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_DISABLE, _OSD_UNSELECT);                                                 
            OsdDispMainMenuString(_MAIN_STRING_LOWBLUELIGHT_ENABLE);                                                       
            break;                                                                                         
                                                                                                           
        case _EXIT_KEY_MESSAGE:  
            SET_OSD_STATE(_OSD_MAIN_LOWBLUELIGHT);                                                         
            OsdDispMainIconChange(_MAIN_ICON_LOWBLUELIGHT, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_DISABLE, _OSD_UNSELECT);  
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}
#endif

//H Postion Icon Menu(第二層)
void OsdPosHPos(void)
{
    switch(GET_KEYMESSAGE())
    {                                                                                         
        case _MENU_KEY_MESSAGE:                                          //進入第三層                  
        	g_usAdjustValue0 = GET_VGA_MODE_ADJUST_H_POSITION();
            SET_OSD_STATE(_OSD_POS_HPOS_ADJUST);             
            OsdDispContentClear();    //清除中間頁面                          
            OsdDispSubIcon(_TITLE_ICON_HPOS, _OSD_INDICATE);                         
            OsdDispMainMenuString(_MAIN_STRING_HPOS);                                           
            OsdDispSubIcon(_SUB_ICON_HPOS_ADJUST, _OSD_INDICATE);        //顯示Icon   
            OsdDispSlider(_SLIDER_HPOS);                                 //顯示調整Bar                                   
            break;                                                                                         
                                                                                                           
        case _RIGHT_KEY_MESSAGE:                                                                           
        case _LEFT_KEY_MESSAGE:                                                  
            SET_OSD_STATE(_OSD_POS_VPOS);                    //設定OSD狀態Index(進入V Postion Icon Menu第二層)                        
            OsdDispSubIcon(_SUB_ICON_VPOS, _OSD_SELECT);                 //顯示Icon                                   
            OsdDispSubIcon(_SUB_ICON_HPOS, _OSD_UNSELECT);                                                 
            OsdDispMainMenuString(_SUB_STRING_VPOS);                                                       
            break;                                                                                         
                                                                                                           
        case _EXIT_KEY_MESSAGE:                                          //回到上一層(Top Menu...第一層)   
            SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);                                                         
            OsdDispMainIconChange(_MAIN_ICON_POSTION, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_HPOS, _OSD_UNSELECT);  
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}

//H Postion Icon Menu(第二層)
void OsdPosVPos(void)
{
    switch(GET_KEYMESSAGE())
    {                                                                                         
        case _MENU_KEY_MESSAGE:                                          //進入第三層     
        	g_usAdjustValue1 = GET_VGA_MODE_ADJUST_V_POSITION(); 
            SET_OSD_STATE(_OSD_POS_VPOS_ADJUST);                    
            OsdDispContentClear();         //清除中間頁面                              
            OsdDispSubIcon(_TITLE_ICON_VPOS, _OSD_INDICATE);                         
            OsdDispMainMenuString(_MAIN_STRING_VPOS);                    //顯示Icon                        
            OsdDispSubIcon(_SUB_ICON_VPOS_ADJUST, _OSD_INDICATE);        //顯示調整Bar   
            OsdDispSlider(_SLIDER_VPOS);                                                                   
            break;                                                                                         
                                                                                                           
        case _RIGHT_KEY_MESSAGE:                                                                           
        case _LEFT_KEY_MESSAGE:                                          //設定OSD狀態Index(進入H Postion Icon Menu第二層) 
            SET_OSD_STATE(_OSD_POS_HPOS);                    //顯示Icon                        
            OsdDispSubIcon(_SUB_ICON_HPOS, _OSD_SELECT);                                                   
            OsdDispSubIcon(_SUB_ICON_VPOS, _OSD_UNSELECT);                                                 
            OsdDispMainMenuString(_SUB_STRING_HPOS);                                                       
            break;                                                                                         
                                                                                                           
        case _EXIT_KEY_MESSAGE:                                          //回到上一層(Top Menu...第一層)   
            SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);                                                         
            OsdDispMainIconChange(_MAIN_ICON_POSTION, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_VPOS, _OSD_UNSELECT);                      
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}

//Auto Icon Menu(第二層)
void OsdSetupAutomatic(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:                                          //執行Auto動作動作完回到OSD_None
	#if 1//(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
			OsdDispDisableOsdTimerEvent();
		    SET_OSD_EVENT_MESSAGE(_OSDEVENT_DO_AUTO_CONFIG_MSG);
			SET_KEYHOLDKEY();
	#else
			OsdDispDisableOsdTimerEvent();
			OsdDispMessage(_MSG_AUTO);		            
            UserCommonAutoConfig();                                      //Auto動作
            OsdDispDisableOsdTimerEvent();          
            SET_OSD_STATE(_OSD_MAIN_IMAGESETUP);
            OsdDispMainMenu(GET_OSD_STATE());  
	#endif
            break;

        case _RIGHT_KEY_MESSAGE: 
        case _LEFT_KEY_MESSAGE:                                          //設定OSD狀態Index(進入Manual Icon Menu第二層) 
            SET_OSD_STATE(_OSD_SETUP_MANUAL);                       //顯示Icon                               
            OsdDispSubIcon(_SUB_ICON_AUTOMATIC, _OSD_UNSELECT);                                                   
            OsdDispSubIcon(_SUB_ICON_MANUAL, _OSD_SELECT);                                                        
            OsdDispMainMenuString(_SUB_STRING_MANUAL);                                                            
            break;                                                                                                
                                                                                                                  
        case _EXIT_KEY_MESSAGE:                                          //回到上一層(Top Menu...第一層)          
            SET_OSD_STATE(_OSD_MAIN_IMAGESETUP);                                                                  
            OsdDispMainIconChange(_MAIN_ICON_SETUP, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_AUTOMATIC, _OSD_UNSELECT); 
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}

//Manual Icon Menu
void OsdSetupManual(void)
{
    switch(GET_KEYMESSAGE())
    {                                                                                                         
        case _MENU_KEY_MESSAGE:                                          //進入第三層                                                   
            SET_OSD_STATE(_OSD_SETUP_MANUAL_CLOCK);      
            OsdDispContentClear(); //清除中間頁面...Row0~Row11 
            OsdDispSubIcon(_TITLE_ICON_MANUAL, _OSD_SELECT);                                                               
            OsdDispMainMenuString(_MAIN_STRING_MANUAL);                                                          
			g_usAdjustValue0 = GET_VGA_MODE_ADJUST_CLOCK();
            OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_SELECT);         //顯示選擇Item(CLK PHASE SAVE)      
            g_usAdjustValue1 = GET_VGA_MODE_ADJUST_PHASE();
            OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_UNSELECT);                                                         
            OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_UNSELECT);                                                             
            break;                                                                                                         
                                                                                                                           
        case _RIGHT_KEY_MESSAGE:                                         //設定OSD狀態Index(進入/Auto Icon Menu第二層) 
        case _LEFT_KEY_MESSAGE:                                                                                 
            SET_OSD_STATE(_OSD_SETUP_AUTOMATIC);                                                                      
            OsdDispSubIcon(_SUB_ICON_AUTOMATIC, _OSD_SELECT);            //顯示Icon                                                   
            OsdDispSubIcon(_SUB_ICON_MANUAL, _OSD_UNSELECT);                                                               
            OsdDispMainMenuString(_SUB_STRING_AUTOMATIC);                                                                  
            break;                                                                         
                                                                         
        case _EXIT_KEY_MESSAGE:                                          //回到上一層(Top Menu...第一層)                                                   
			SET_OSD_STATE(_OSD_MAIN_IMAGESETUP);
			OsdDispMainIconChange(_MAIN_ICON_SETUP, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_MANUAL, _OSD_UNSELECT);	
			OsdDispSubStringClear();
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		default:
			break;
	}
}

//Color Icon Menu
void OsdPropColor(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:                                         
            if(GET_COLOR_TEMP_STATUS() == _COLOR_USER)
            {
                SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM);                
                OsdDispContentClear();    
                OsdDispSubIcon(_TITLE_ICON_COLOR, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_MAIN_STRING_COLOR);                
                OsdDispSubItem(_SUB_ITEM_COLOR_PRESET, _OSD_UNSELECT);           
                OsdDispSubItem(_SUB_ITEM_COLOR_CUSTOM, _OSD_SELECT);                        
            }
            else
            {
                SET_OSD_STATE(_OSD_PROP_COLOR_PRESET);                
                OsdDispContentClear();    
                OsdDispSubIcon(_TITLE_ICON_COLOR, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_MAIN_STRING_COLOR);                
                OsdDispSubItem(_SUB_ITEM_COLOR_PRESET, _OSD_SELECT);               
                OsdDispSubItem(_SUB_ITEM_COLOR_CUSTOM, _OSD_UNSELECT);          
            }
            break;

        case _RIGHT_KEY_MESSAGE: 
#if(_INPUT_PORT_MAX != 1)
            SET_OSD_STATE(_OSD_PROP_INPUT);                     
            OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT);   
            OsdDispMainMenuString(_SUB_STRING_INPUT);      
#else
#if(_ASPECT_RATIO_SUPPORT==_ON)
			if(UserAdjustCheckAspectRatio() == _TRUE)
			{
	            SET_OSD_STATE(_OSD_PROP_SCALING);                    
	            OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT);     
	            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT); 
	            OsdDispMainMenuString(_SUB_STRING_SCALING);
			}
            else
            {
                SET_OSD_STATE(_OSD_PROP_BLUELIGHT);                       
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT);   
                OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_BLUELIGHT);       
            }
#elif(_OD_SUPPORT==_ON)
			SET_OSD_STATE(_OSD_PROP_OD); 					
			OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 			
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_SELECT);	
			OsdDispMainMenuString(_SUB_STRING_OD);		
#endif
#endif
            break;
            
        case _LEFT_KEY_MESSAGE: 
#if(_OD_SUPPORT==_ON)
            SET_OSD_STATE(_OSD_PROP_OD);                    
            OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT);     
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_SELECT); 
            OsdDispMainMenuString(_SUB_STRING_OD);
#else
#if(_ASPECT_RATIO_SUPPORT==_ON)
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON) 
            SET_OSD_STATE(_OSD_PROP_BLUELIGHT);                       
            OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT);
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_SELECT);                                                               
            OsdDispMainMenuString(_SUB_STRING_BLUELIGHT);       
#else
			if(UserAdjustCheckAspectRatio() == _TRUE)
			{
				SET_OSD_STATE(_OSD_PROP_SCALING);					  
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 	
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT); 
				OsdDispMainMenuString(_SUB_STRING_SCALING);
			}
#if(_INPUT_PORT_MAX != 1)
			else
			{
				SET_OSD_STATE(_OSD_PROP_INPUT); 				   	
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 	
				OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT); 
				OsdDispMainMenuString(_SUB_STRING_INPUT);
			}
#endif //#if(_INPUT_PORT_MAX != 1)
#endif //#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON) 
#endif //#if(_ASPECT_RATIO_SUPPORT==_ON)
#endif //#if(_OD_SUPPORT==_ON)
            break;

        case _EXIT_KEY_MESSAGE:                                         
            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT);     
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}

#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
//Input Icon Menu(第二層)
void OsdPropInput(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            //進入第三層 
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {
                SET_OSD_STATE(_OSD_PROP_INPUT_ANALOG);
                OsdDispContentClear();  //清除中間頁面
    			OsdLoadFont(_FONT2_DYNAMIC_INPUTINFO);
                OsdDispSubIcon(_TITLE_ICON_INPUT, _OSD_SELECT);                 
                OsdDispMainMenuString(_MAIN_STRING_INPUT);                  
                OsdDispSubItem(_SUB_ITEM_INPUT_ANALOG, _OSD_SELECT);     //選擇VGA
                OsdDispSubItem(_SUB_ITEM_INPUT_DIGITAL, _OSD_UNSELECT); 
                OsdDispSubIcon(_SUB_ICON_ANALOG, _OSD_SELECT);  
                OsdDispSubIcon(_SUB_ICON_DIGITAL, _OSD_UNSELECT);                                 
            }
            else //if((SysSourceGetSourceType() == _SOURCE_DVI))
            {
                SET_OSD_STATE(_OSD_PROP_INPUT_DIGITAL);
                OsdDispContentClear();  //清除中間頁面
    			OsdLoadFont(_FONT2_DYNAMIC_INPUTINFO);
                OsdDispSubIcon(_TITLE_ICON_INPUT, _OSD_SELECT);                 
                OsdDispMainMenuString(_MAIN_STRING_INPUT);                  
                OsdDispSubItem(_SUB_ITEM_INPUT_ANALOG, _OSD_UNSELECT);   //選擇Digital
                OsdDispSubItem(_SUB_ITEM_INPUT_DIGITAL, _OSD_SELECT);               
                OsdDispSubIcon(_SUB_ICON_ANALOG, _OSD_UNSELECT);  
                OsdDispSubIcon(_SUB_ICON_DIGITAL, _OSD_SELECT);                                 
                
            }
            break;

        case _RIGHT_KEY_MESSAGE: 
#if(_ASPECT_RATIO_SUPPORT==_ON)
			if(UserAdjustCheckAspectRatio() == _TRUE)
			{
	            SET_OSD_STATE(_OSD_PROP_SCALING);                     
	            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);     
	            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT); 
	            OsdDispMainMenuString(_SUB_STRING_SCALING);     
			}
			else 
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)||(_USER_DCR_FUNCTION == _ON))		
            if((GET_LOWBLUELIGHT_STATUS() == _DISABLE) && (GET_OSD_DCR_STATUS() == _OFF))
#elif(_LOW_BLUE_LIGHT_FUNCTION == _ON)
            if(GET_LOWBLUELIGHT_STATUS() == _DISABLE) 
#elif(_USER_DCR_FUNCTION == _ON)
			if(GET_OSD_DCR_STATUS() == _OFF)
#endif
			{
                SET_OSD_STATE(_OSD_PROP_COLOR);                       
                OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);     
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);   
                OsdDispMainMenuString(_SUB_STRING_COLOR);
			}
#else      
#if(_OD_SUPPORT==_ON)
                SET_OSD_STATE(_OSD_PROP_OD);                     //設定OSD狀態Index(進入Scaling Icon Menu第二層)  
                OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);     
                OsdDispSubIcon(_SUB_ICON_OD, _OSD_SELECT); 
                OsdDispMainMenuString(_SUB_STRING_OD);     
#else
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)||(_USER_DCR_FUNCTION == _ON))		
            if((GET_LOWBLUELIGHT_STATUS() == _DISABLE)
#if(_USER_DCR_FUNCTION == _ON)	
					||(GET_OSD_DCR_STATUS() == _OFF)
#endif
)			
#endif
            {
                SET_OSD_STATE(_OSD_PROP_COLOR);                        //設定OSD狀態Index(進入Color Icon Menu第二層) 
                OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);     
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);   
                OsdDispMainMenuString(_SUB_STRING_COLOR);
            }
#endif
#endif
            break;

        case _LEFT_KEY_MESSAGE: 
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)||(_USER_DCR_FUNCTION == _ON))		           
            if((GET_LOWBLUELIGHT_STATUS() == _ENABLE)
#if(_USER_DCR_FUNCTION == _ON)
			||(GET_OSD_DCR_STATUS() == _ON)
#endif
)
            {
#if(_OD_SUPPORT==_ON)
                SET_OSD_STATE(_OSD_PROP_OD);                     //設定OSD狀態Index(進入Scaling Icon Menu第二層)  
                OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);     
                OsdDispSubIcon(_SUB_ICON_OD, _OSD_SELECT); 
                OsdDispMainMenuString(_SUB_STRING_OD);     
#else            
				if(UserAdjustCheckAspectRatio() == _TRUE)
				{
	                SET_OSD_STATE(_OSD_PROP_SCALING);                      
	                OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);     
	                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT); 
	                OsdDispMainMenuString(_SUB_STRING_SCALING); 
				}
				else
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)||(_USER_DCR_FUNCTION == _ON))		
				if((GET_LOWBLUELIGHT_STATUS() == _DISABLE) && (GET_OSD_DCR_STATUS() == _OFF))
#elif(_LOW_BLUE_LIGHT_FUNCTION == _ON)
				if(GET_LOWBLUELIGHT_STATUS() == _DISABLE) 
#elif(_USER_DCR_FUNCTION == _ON)
				if(GET_OSD_DCR_STATUS() == _OFF)
#endif
				{
					SET_OSD_STATE(_OSD_PROP_COLOR); 					  
					OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT); 	
					OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);	
					OsdDispMainMenuString(_SUB_STRING_COLOR);
				}

#endif
            }
            else
#endif
            {
                SET_OSD_STATE(_OSD_PROP_COLOR);                        //設定OSD狀態Index(進入Color Icon Menu第二層) 
                OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);     
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);   
                OsdDispMainMenuString(_SUB_STRING_COLOR);
            }
            break;
            
        case _EXIT_KEY_MESSAGE:                                          //回到上一層(Top Menu...第一層) 
            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT); 
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}
#endif

//Scaling Icon Menu(第二層)
void OsdPropScaling(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:                                         //進入第三層              
			OsdDispContentClear();
            OsdDispSubIcon(_TITLE_ICON_SCALING, _OSD_SELECT);                             
			OsdDispMainMenuString(_MAIN_STRING_SCALING);
			
#if(_ASPECT_RATIO_SUPPORT==_ON)
			if((GET_OSD_ASPECT_RATIO_TYPE() == _ASPECT_RATIO_OFF) && (UserAdjustCheckAspectRatio() == _TRUE))
			{
			    SET_OSD_STATE(_OSD_PROP_SCALING_OFF);
				OsdDispSubItem(_SUB_ITEM_SCALING_OFF, _OSD_SELECT);
				OsdDispSubItem(_SUB_ITEM_SCALING_ON, _OSD_UNSELECT);				
				OsdDispMainMenuString(_SUB_STRING_SCALING_OFF);			
			}
			else
			{
				SET_OSD_STATE(_OSD_PROP_SCALING_ON);
				OsdDispSubItem(_SUB_ITEM_SCALING_OFF, _OSD_UNSELECT);
				OsdDispSubItem(_SUB_ITEM_SCALING_ON, _OSD_SELECT);	
				OsdDispMainMenuString(_SUB_STRING_SCALING_ON);			
			}
#endif
            break;                                                      

        case _RIGHT_KEY_MESSAGE: 
#if(_OD_SUPPORT==_ON)
                SET_OSD_STATE(_OSD_PROP_OD);                       //設定OSD狀態Index(進入Color Icon Menu第二層) 
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);                                                           
                OsdDispSubIcon(_SUB_ICON_OD, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_OD);                                                                   
#else
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)||(_USER_DCR_FUNCTION == _ON))		           
            if((GET_LOWBLUELIGHT_STATUS() == _ENABLE)
#if(_USER_DCR_FUNCTION == _ON)
			||(GET_OSD_DCR_STATUS() == _ON)
#endif
			)	
            {
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
                SET_OSD_STATE(_OSD_PROP_INPUT);                      //設定OSD狀態Index(進入Input Icon Menu第二層)   
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);                                                           
                OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_INPUT);  
#elif (_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
                SET_OSD_STATE(_OSD_PROP_BLUELIGHT);                       
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);   
                OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_BLUELIGHT);       
#endif
            }
            else
#endif
            {
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON) 
                SET_OSD_STATE(_OSD_PROP_BLUELIGHT);                       
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);   
                OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_BLUELIGHT);       
#else
                SET_OSD_STATE(_OSD_PROP_COLOR);                       //設定OSD狀態Index(進入Color Icon Menu第二層) 
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);                                                           
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_COLOR);       
#endif                
            }
#endif
            break;                                                                                                      

        case _LEFT_KEY_MESSAGE: 
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
            SET_OSD_STATE(_OSD_PROP_INPUT);                      //設定OSD狀態Index(進入Input Icon Menu第二層)   
            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);                                                           
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT);                                                               
            OsdDispMainMenuString(_SUB_STRING_INPUT); 
#else
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
#if(_OD_SUPPORT==_ON)
                SET_OSD_STATE(_OSD_PROP_OD);                      //設定OSD狀態Index(進入Input Icon Menu第二層)   
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);                                                           
                OsdDispSubIcon(_SUB_ICON_OD, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_OD); 
#elif (_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
                SET_OSD_STATE(_OSD_PROP_BLUELIGHT);                       
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);   
                OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_BLUELIGHT);       
#endif
            }
            else
#endif
            {
#if(_USER_DCR_FUNCTION == _ON)    
                if(GET_OSD_DCR_STATUS() == _ON)
                {
                    #if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
                    SET_OSD_STATE(_OSD_PROP_BLUELIGHT);                       
                    OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);   
                    OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_SELECT);                                                               
                    OsdDispMainMenuString(_SUB_STRING_BLUELIGHT);                           
                    #endif
                }
                else
                {
                    SET_OSD_STATE(_OSD_PROP_COLOR);                       //設定OSD狀態Index(進入Color Icon Menu第二層) 
                    OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);                                                           
                    OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);                                                               
                    OsdDispMainMenuString(_SUB_STRING_COLOR);    
                }
 #else
                SET_OSD_STATE(_OSD_PROP_COLOR);                       //設定OSD狀態Index(進入Color Icon Menu第二層) 
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);                                                           
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_COLOR);    
#endif          
            }
#endif           
            break;                                                                                                      
                                                                                                                  
        case _EXIT_KEY_MESSAGE:                                         //回到上一層(Top Menu...第一層)                 
            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);                                                                   
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);       
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}

#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
void OsdPropBlueLight(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:     
            OsdDispContentClear();
            OsdDispSubIcon(_TITLE_ICON_BLUELIGHT, _OSD_SELECT);                             
            OsdDispMainMenuString(_MAIN_STRING_BLUELIGHT);
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                SET_OSD_STATE(_OSD_PROP_BLUELIGHT_ON);
                OsdDispSubItem(_SUB_ITEM_BLUELIGHT_ON, _OSD_SELECT);
                OsdDispSubItem(_SUB_ITEM_BLUELIGHT_OFF, _OSD_UNSELECT);                
            }
            else
            {
                SET_OSD_STATE(_OSD_PROP_BLUELIGHT_OFF);
                OsdDispSubItem(_SUB_ITEM_BLUELIGHT_OFF, _OSD_SELECT);
                OsdDispSubItem(_SUB_ITEM_BLUELIGHT_ON, _OSD_UNSELECT);                
            }
            break;                                                      

        case _RIGHT_KEY_MESSAGE: 
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                if(UserAdjustCheckAspectRatio() == _TRUE)
                {
                    SET_OSD_STATE(_OSD_PROP_SCALING);                    
                    OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);     
                    OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT); 
                    OsdDispMainMenuString(_SUB_STRING_SCALING);
                }
            }
            else
            {
                
                #if(_USER_DCR_FUNCTION == _ON)    
                if((GET_OSD_DCR_STATUS() != _ON)&&(GET_LOWBLUELIGHT_STATUS() != _ENABLE))
                    {
                        SET_OSD_STATE(_OSD_PROP_COLOR);                       
                        OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT); 
                        OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);                                                               
                        OsdDispMainMenuString(_SUB_STRING_COLOR);    
                    }
                else
                    {
                        if(UserAdjustCheckAspectRatio() == _TRUE)
                        {
                            SET_OSD_STATE(_OSD_PROP_SCALING);                    
                            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);     
                            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT); 
                            OsdDispMainMenuString(_SUB_STRING_SCALING);
                        }
                    }
                #else
                    SET_OSD_STATE(_OSD_PROP_COLOR);                       
                    OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT); 
                    OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);                                                               
                    OsdDispMainMenuString(_SUB_STRING_COLOR);    
                #endif
            }
            break;                                                                                                      

        case _LEFT_KEY_MESSAGE: 
#if(_INPUT_PORT_MAX != 1)
            SET_OSD_STATE(_OSD_PROP_INPUT);                      
            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);                                                           
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT);                                                               
            OsdDispMainMenuString(_SUB_STRING_INPUT); 
#else
			if(UserAdjustCheckAspectRatio() == _TRUE)
			{
	            SET_OSD_STATE(_OSD_PROP_SCALING);                    
	            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);     
	            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT); 
	            OsdDispMainMenuString(_SUB_STRING_SCALING);
			}
            else
            {
                #if(_USER_DCR_FUNCTION == _ON)
                if((GET_OSD_DCR_STATUS() != _ON)&&(GET_LOWBLUELIGHT_STATUS() != _ENABLE))
                    {
                        SET_OSD_STATE(_OSD_PROP_COLOR);                       
                        OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT); 
                        OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);                                                               
                        OsdDispMainMenuString(_SUB_STRING_COLOR);    
                    }
                else
                    {
                        if(UserAdjustCheckAspectRatio() == _TRUE)
                        {
                            SET_OSD_STATE(_OSD_PROP_SCALING);                    
                            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);     
                            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT); 
                            OsdDispMainMenuString(_SUB_STRING_SCALING);
                        }
                    }                
                #else
                SET_OSD_STATE(_OSD_PROP_COLOR);                       
                OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT); 
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_COLOR); 
                #endif
            }
#endif
            break;                                                                                                      
                                                                                                                  
        case _EXIT_KEY_MESSAGE:                                            
            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);                                                                   
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);       
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}
#endif

#if(_OD_SUPPORT == _ON)
void OsdPropOD(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:                                     
			OsdDispContentClear();
            OsdDispSubIcon(_TITLE_ICON_OD, _OSD_SELECT);                             
			OsdDispMainMenuString(_MAIN_STRING_OD);

			if(GET_OSD_OD_STATUS() == _ON)
			{
			    SET_OSD_STATE(_OSD_PROP_OD_ON);
				OsdDispSubItem(_SUB_ITEM_OD_ON, _OSD_SELECT);
				OsdDispSubItem(_SUB_ITEM_OD_OFF, _OSD_UNSELECT);				
				//OsdDispMainMenuString(_SUB_STRING_SCALING_OFF);			
			}
			else
			{
			    SET_OSD_STATE(_OSD_PROP_OD_OFF);
				OsdDispSubItem(_SUB_ITEM_OD_OFF, _OSD_SELECT);
				OsdDispSubItem(_SUB_ITEM_OD_ON, _OSD_UNSELECT);				
				//OsdDispMainMenuString(_SUB_STRING_SCALING_ON);			
			}
            break;                                                      

        case _RIGHT_KEY_MESSAGE: 
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
#if(_INPUT_PORT_MAX != 1)
                SET_OSD_STATE(_OSD_PROP_INPUT);        
                OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);                                                           
                OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_INPUT); 
#else
#if(_ASPECT_RATIO_SUPPORT==_ON)
                SET_OSD_STATE(_OSD_PROP_SCALING);        
                OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);                                                           
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_SCALING); 
#endif
#endif
            }
            else
#endif
            {
                SET_OSD_STATE(_OSD_PROP_COLOR);                 
                OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);                                                           
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_COLOR);                                                                   
            }
            break;                                                                                                      
                                                                                                                        
        case _LEFT_KEY_MESSAGE:   
#if(_ASPECT_RATIO_SUPPORT==_ON)
            SET_OSD_STATE(_OSD_PROP_SCALING);                      
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);                                                           
            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT);                                                               
            OsdDispMainMenuString(_SUB_STRING_SCALING); 

#else
#if(_INPUT_PORT_MAX != 1)
            SET_OSD_STATE(_OSD_PROP_INPUT);                      
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);                                                           
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT);                                                               
            OsdDispMainMenuString(_SUB_STRING_INPUT); 
#else
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _DISABLE)
#endif
            {
                SET_OSD_STATE(_OSD_PROP_COLOR);                 
                OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);                                                           
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);                                                               
                OsdDispMainMenuString(_SUB_STRING_COLOR);   
            }
#endif
#endif
            break;                                                                                                      
                                                                                                                        
        case _EXIT_KEY_MESSAGE:        
            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);                                                                   
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);       
            OsdDispSubStringClear();
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}
#endif

//Information Icon Menu(第二層)
void OsdOptionInformation(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:                                       //顯示目前解析度
			SET_OSD_STATE(_OSD_OPTION_INFORMATION_SHOW);        
			OsdDispContentClear();
            OsdDispSubIcon(_TITLE_ICON_INFORMATION, _OSD_SELECT);                                         
			OsdDispMainMenuString(_MAIN_STRING_INFORMATION);
			OsdDispInformationPage();		
            break;

        case _RIGHT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_OPTION_LANGUAGE);                 //設定OSD狀態Index(進入Language Icon Menu第二層)  
            OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);     //Information Icon反灰
            OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_SELECT);          //Language Icon反白 
            OsdDispMainMenuString(_SUB_STRING_LANGUAGE_SELECT);       //顯示Sub Menu中間提示文字                                                      
            break;

        case _LEFT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY);                   //設定OSD狀態Index(進入Accessibility Icon Menu第二層) 
            OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);
            OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_SELECT);
            OsdDispMainMenuString(_SUB_STRING_ACCESSIBILITY);                                                                       
            break;

        case _EXIT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_MAIN_OPTION);                          //回到上一層(Top Menu...第一層)
            OsdDispMainIconChange(_MAIN_ICON_OPTION, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);       
            OsdDispSubStringClear();        
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}

//Language Icon Menu(第二層)
void OsdOptionLanguage(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:                                       //進入第三層 
			SET_OSD_STATE(_OSD_OPTION_LANGUAGE_ADJUST);
			OsdDispContentClear();      //清除中間頁面
            OsdDispSubIcon(_TITLE_ICON_LANGUAGE, _OSD_SELECT);                                         
			OsdDispMainMenuString(_MAIN_STRING_LANGUAGE);			  //顯示Sub Menu Top文字
			g_usAdjustValue0 = GET_OSD_LANGUAGE();
			OsdDispLanguagePage(g_usAdjustValue0);			    
            break;

        case _RIGHT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_OPTION_OSDPOS);
            OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
            OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_SELECT);
            OsdDispMainMenuString(_SUB_STRING_OSDPOSTION_SELECT);                                                                       
            break;

        case _LEFT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_OPTION_INFORMATION);
            OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
            OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_SELECT);
            OsdDispMainMenuString(_SUB_STRING_INFORMATION);                                                                             
            break;

        case _EXIT_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_MAIN_OPTION);
            OsdDispMainIconChange(_MAIN_ICON_OPTION, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);      
            OsdDispSubStringClear();  
            OsdDispKeyInfo(_KEY_INFO_EXIT);
            break;

        default:
            break;
    }
}

//OSD Postion Icon Menu(第二層)
void OsdOptionOsdPos(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_DEFAULT);            
			OsdDispContentClear();
            OsdDispSubIcon(_TITLE_ICON_OSDPOS, _OSD_SELECT);                                                     
			OsdDispMainMenuString(_MAIN_STRING_OSDPOS);				
			OsdDispSubItem(_SUB_ITEM_OSDPOS_DEFAULT, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_CUSTOM, _OSD_UNSELECT);				
				
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_DEFAULT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_DEFAULT_SELECT);																				
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_LANGUAGE);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_LANGUAGE_SELECT);																						
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_MAIN_OPTION);
			OsdDispMainIconChange(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);		
			OsdDispSubStringClear();	
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		default:
			break;
	}
}

//(第二層)
void OsdOptionDefault(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_DEFAULT_CANCEL);
			OsdDispContentClear();            
            OsdDispSubIcon(_TITLE_ICON_RESET, _OSD_SELECT);                  
			OsdDispMainMenuString(_MAIN_STRING_DEFAULT);
			OsdDispSubItem(_SUB_ITEM_DEFAULT_CANCEL, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_DEFAULT_RESET, _OSD_UNSELECT);		
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_ACCESSIBILITY);																						
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_OSDPOSTION_SELECT);																								
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_MAIN_OPTION);
			OsdDispMainIconChange(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);		
			OsdDispSubStringClear();	
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		default:
			break;
	}
}

//(第二層)
void OsdOptionAccessibility(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
#if 1//Robert Wang 20130308          
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_REPEAT);
			OsdDispContentClear();
			OsdLoadFont(_FONT2_DYNAMIC_ACCESSIBILITY);
            OsdDispSubIcon(_TITLE_ICON_ACCESSIBILITY, _OSD_SELECT);    
			OsdDispMainMenuString(_MAIN_STRING_ACCESSIBILITY);
			OsdDispSubIcon(_SUB_ICON_BUTTON_REPEAT, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_MENU_TIMEOUT, _OSD_UNSELECT);		
			OsdDispMainMenuString(_SUB_STRING_BUTTON_REPEAT);					
#else            
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_REPEAT);
			OsdDispContentClear();
            OsdDispSubIcon(_TITLE_ICON_ACCESSIBILITY, _OSD_SELECT);    
			OsdDispMainMenuString(_MAIN_STRING_ACCESSIBILITY);
			OsdLoadFont(_FONT2_DYNAMIC_ACCESSIBILITY);
			OsdDispSubIcon(_SUB_ICON_BUTTON_REPEAT, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_MENU_TIMEOUT, _OSD_UNSELECT);		
			OsdDispMainMenuString(_SUB_STRING_BUTTON_REPEAT);					
#endif
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_INFORMATION);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_INFORMATION);																								
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_DEFAULT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_DEFAULT_SELECT);																										
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_MAIN_OPTION);
			OsdDispMainIconChange(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);		
			OsdDispSubStringClear();	
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		default:
			break;
	}
}

/*--------------------------------------------*/
/*             OSD Menu第三層                 */
/*--------------------------------------------*/
//Bright Adjust動作
void OsdPictureBrightAdjust(void)
{
#if((_LENOVO_DPS_SUPPORT == _ON)&&(_ENERGY_STAR_SUPPORT == _ON))
    BYTE ucTempBackLight = 0;
#endif

	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:                                            
			SET_OSD_BACKLIGHT(g_usAdjustValue0);           
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);       //儲存Bri Data      
			SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
            OsdDispMainIcon();            
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			
            break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();

			g_usAdjustValue0 = OsdDetOverRange(g_usAdjustValue0, 100, 0, _OSD_NO_REPEAT);
#if 1//(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
			if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
			{
				OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_BRIGHTNESS_L, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1); 				
				OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_BRIGHTNESS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);
			}
			else if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
			{
				OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_BRIGHTNESS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB); 				
				OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_BRIGHTNESS_R, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			}
#endif
			OsdDispSlider(_SLIDER_BRIGHTNESS);

#if((_LENOVO_DPS_SUPPORT == _ON)&&(_ENERGY_STAR_SUPPORT == _ON))
            if(GET_OSD_ES_STATUS() == _ON) 
            {
                ucTempBackLight = GET_OSD_BACKLIGHT();//ym20131007 . 
                SET_OSD_BACKLIGHT(g_usAdjustValue0);
                
                // Search Target Backlight Value.
                UserCommonAdjustESDcrSearchTargetPWM();

                // Set Adjust Value = Target Value.
                SET_ES_DCR_PWM_ADJUST_VALUE(GET_ES_DCR_PWM_TARGET_VALUE());

                // Set Backlight Value.
                UserAdjustBacklight(GET_ES_DCR_PWM_ADJUST_VALUE());

                SET_OSD_BACKLIGHT(ucTempBackLight);//ym20131007 . 
            }
            else
            {
        		UserAdjustBacklightPercent(g_usAdjustValue0);
            }
#else
        	UserAdjustBacklightPercent(g_usAdjustValue0);
#endif
			break;
			
		case _EXIT_KEY_MESSAGE: 
#if((_LENOVO_DPS_SUPPORT == _ON)&&(_ENERGY_STAR_SUPPORT == _ON))//ym20131014 . 
            if(GET_OSD_ES_STATUS() == _ON) 
            {
                // Search Target Backlight Value.
                UserCommonAdjustESDcrSearchTargetPWM();

                // Set Adjust Value = Target Value.
                SET_ES_DCR_PWM_ADJUST_VALUE(GET_ES_DCR_PWM_TARGET_VALUE());

                // Set Backlight Value.
                UserAdjustBacklight(GET_ES_DCR_PWM_ADJUST_VALUE());
            }
            else
            {
        		UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
#else
			UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
#endif
            
			SET_OSD_STATE(_OSD_PICTURE_BRIGHTNESS);
			OsdDispContentClear();
            OsdDispMainIcon();
            OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PICTURE);			
			OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);
#if(_LENOVO_DPS_SUPPORT == _ON)
			OsdDispSubIcon(_SUB_ICON_DPS, _OSD_UNSELECT);
#endif
#if(_USER_DCR_FUNCTION == _ON)
			OsdDispSubIcon(_SUB_ICON_DCR, _OSD_UNSELECT);
#endif

			OsdDispMainMenuString(_SUB_STRING_BRIGHTNESS);
			break;


		default:
			break;
	}
}

void OsdPictureContrastAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_CONTRAST(g_usAdjustValue0);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
			SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
            OsdDispMainIcon();                        
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;			

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 

//			SET_KEYREPEATENABLE();
			g_usAdjustValue0 = OsdDetOverRange(g_usAdjustValue0, 100, 0, _OSD_NO_REPEAT);
#if 1//(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
		if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
		{
			OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_CONTRAST_L, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);					
			OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_CONTRAST_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);	
		}
		else if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
		{
			OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_CONTRAST_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					 
			OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_CONTRAST_R, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);  
		}
#endif
			OsdDispSlider(_SLIDER_CONTRAST);

			UserAdjustContrast(g_usAdjustValue0);
			break;

		case _EXIT_KEY_MESSAGE: 
			UserAdjustContrast(GET_OSD_CONTRAST());
			SET_OSD_STATE(_OSD_PICTURE_CONTRAST);
			OsdDispContentClear();
            OsdDispMainIcon();                        
            OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PICTURE);			
			OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_SELECT);
#if(_LENOVO_DPS_SUPPORT == _ON)
			OsdDispSubIcon(_SUB_ICON_DPS, _OSD_UNSELECT);
#endif
#if(_USER_DCR_FUNCTION == _ON)
			OsdDispSubIcon(_SUB_ICON_DCR, _OSD_UNSELECT);
#endif

			OsdDispMainMenuString(_SUB_STRING_CONTRAST);
			break;


		default:
			break;
	}
}

#if(_LENOVO_DPS_SUPPORT == _ON)
void OsdPictureDpsAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
        #if(_ENERGY_STAR_SUPPORT == _ON)
			SET_OSD_ES_STATUS(g_usAdjustValue0);
            UserCommonAdjustESDcrProcess(GET_OSD_ES_STATUS());
        #endif

			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
            OsdDispMainIcon();                        
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);

			break;			

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			if(g_usAdjustValue0 == _ON)
			{
                g_usAdjustValue0=_OFF;			
				OsdDispSubItem(_SUB_ITEM_DPS_ON, _OSD_UNSELECT);
				OsdDispSubItem(_SUB_ITEM_DPS_OFF, _OSD_SELECT);
			}
			else
			{
                g_usAdjustValue0=_ON;			
				OsdDispSubItem(_SUB_ITEM_DPS_OFF, _OSD_UNSELECT);
				OsdDispSubItem(_SUB_ITEM_DPS_ON, _OSD_SELECT);
			}

			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PICTURE_DPS);
			OsdDispContentClear();
            OsdDispMainIcon();                        
            OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PICTURE);			
			OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_DPS, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_DPS);
			break;


		default:
			break;
	}
}
#endif

#if(_USER_DCR_FUNCTION == _ON)
void OsdPictureDCRAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_DCR_STATUS(g_usAdjustValue0);
			if(g_usAdjustValue0!=g_usAdjustValue1)
				UserAdjustDCRControl(GET_OSD_DCR_STATUS());
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
            OsdDispMainIcon();                        
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);

			break;			

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			if(g_usAdjustValue0 == _ON)
			{
                g_usAdjustValue0=_OFF;	
				OsdDispSubItem(_SUB_ITEM_DCR_ON, _OSD_UNSELECT);
				OsdDispSubItem(_SUB_ITEM_DCR_OFF, _OSD_SELECT);
			}
			else
			{
                g_usAdjustValue0=_ON;	
				OsdDispSubItem(_SUB_ITEM_DCR_OFF, _OSD_UNSELECT);
				OsdDispSubItem(_SUB_ITEM_DCR_ON, _OSD_SELECT);
			}

			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PICTURE_DCR);
			OsdDispContentClear();
            OsdDispMainIcon();                        
            OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PICTURE);			
			OsdDispSubIcon(_SUB_ICON_DCR, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_DCR);
            if(GET_OSD_DCR_STATUS() == _ON)
            {
                OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_STATIC);
                OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_STATIC);
            }
            else
            {
                OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);
                OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);
            }
			break;


		default:
			break;
	}
}
#endif

void OsdPosHPosAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_VGA_MODE_ADJUST_H_POSITION(g_usAdjustValue0);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
			SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
            OsdDispMainIcon();                        
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);

			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			g_usAdjustValue0 = OsdDetOverRange(g_usAdjustValue0, 100, 0, _OSD_NO_REPEAT);
#if 1//(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
				if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
				{
					OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_HPOS_L, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);					
					OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_HPOS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);	
				}
				else if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
				{
					OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_HPOS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					 
					OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_HPOS_R, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);	
				}
#endif

			OsdDispSlider(_SLIDER_HPOS);
			UserCommonAdjustHPosition(g_usAdjustValue0);
			break;

		case _EXIT_KEY_MESSAGE: 
			UserCommonAdjustHPosition(GET_VGA_MODE_ADJUST_H_POSITION());
			SET_OSD_STATE(_OSD_POS_HPOS);
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_POSTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_POSITION);			
			OsdDispSubIcon(_SUB_ICON_HPOS, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_VPOS, _OSD_UNSELECT);
			OsdDispMainMenuString(_SUB_STRING_HPOS);		
			break;


		default:
			break;
	}
}

void OsdPosVPosAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_VGA_MODE_ADJUST_V_POSITION(g_usAdjustValue1);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
			SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
            OsdDispMainIcon();                        
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			g_usAdjustValue1 = OsdDetOverRange(g_usAdjustValue1, 100, 0, _OSD_NO_REPEAT);
#if 1//(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
				if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
				{
					OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_VPOS_L, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);					
					OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_VPOS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);	
				}
				else if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
				{
					OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_VPOS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					 
					OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_VPOS_R, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);	
				}
#endif

			OsdDispSlider(_SLIDER_VPOS);
			UserCommonAdjustVPosition(g_usAdjustValue1);
			break;

		case _EXIT_KEY_MESSAGE: 
			UserCommonAdjustVPosition(GET_VGA_MODE_ADJUST_V_POSITION());
			SET_OSD_STATE(_OSD_POS_VPOS);
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_POSTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_POSITION);			
			OsdDispSubIcon(_SUB_ICON_HPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_VPOS, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_VPOS);				
			break;

		default:
			break;
	}
}

void OsdSetupManualClock(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_CLOCK_ADJUST);
			OsdDispContentClear();            
			OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK_ADJUST, _OSD_INDICATE);
			OsdDispSlider(_SLIDER_CLOCK);		
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_PHASE);
			OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_SELECT);
			//OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_SELECT);					
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_SAVE);
			OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_UNSELECT);
			//OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_SELECT);					
			break;

		case _EXIT_KEY_MESSAGE: 
			UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());	
			UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());			
			SET_OSD_STATE(_OSD_SETUP_MANUAL);
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_SETUP, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_SETUP);			
			OsdDispSubIcon(_SUB_ICON_AUTOMATIC, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_MANUAL, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_MANUAL);			
			break;

		default:
			break;
	}
}

void OsdSetupManualPhase(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_PHASE_ADJUST);
			OsdDispContentClear();			
			OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE_ADJUST, _OSD_INDICATE);
			OsdDispSlider(_SLIDER_PHASE);				
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_SAVE);
			//OsdDispSubItem(_SUB_ITEM_CLOCK, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_SELECT);					
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_CLOCK);
			OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_UNSELECT);
			//OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_SELECT);					
			break;

		case _EXIT_KEY_MESSAGE: 
			UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());	
			UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());					
			SET_OSD_STATE(_OSD_SETUP_MANUAL);
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_SETUP, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_SETUP);			
			OsdDispSubIcon(_SUB_ICON_AUTOMATIC, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_MANUAL, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_MANUAL);					
			break;

		default:
			break;
	}
}  

//Manual Adjust Save Menu(第三層)
void OsdSetupManualSave(void)
{
    switch(GET_KEYMESSAGE())
    {
		case _MENU_KEY_MESSAGE: 
			SET_VGA_MODE_ADJUST_CLOCK(g_usAdjustValue0);
			SET_VGA_MODE_ADJUST_PHASE(g_usAdjustValue1);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
			SET_OSD_STATE(_OSD_MAIN_IMAGESETUP);
            OsdDispMainIcon(); 
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);

			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_CLOCK);
			OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_SELECT);
			//OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_UNSELECT);					
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_PHASE);
			//OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_UNSELECT);					
			break;

		case _EXIT_KEY_MESSAGE: 
			UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());	
			UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());				
            SET_OSD_STATE(_OSD_SETUP_MANUAL);
            OsdDispContentClear();//清除中間頁面
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_SETUP, _OSD_SELECT);
            OsdDispMainMenuString(_MAIN_STRING_SETUP);          
            OsdDispSubIcon(_SUB_ICON_AUTOMATIC, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_MANUAL, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_MANUAL);						
			break;

		default:
			break;
	}
}

//Color Preset Mode Adjust Menu(第三層)
void OsdPropColorPreset(void)
{
	BYTE temp, i;
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 

			g_usAdjustValue0 = GET_COLOR_TEMP_TYPE();
            RTDNVRamLoadColorSetting( GET_COLOR_TEMP_TYPE());
            if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
            {
                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
                UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
            }
            else
            {
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
			SET_OSD_STATE(_OSD_PROP_COLOR_PRESET_ADJUST);
			OsdDispContentClear();
			OsdDispMainMenuString(_MAIN_STRING_PRESET);
			
			for(i=0; i<4; i++)
			{
				if(g_usAdjustValue0 == i)
				{
					temp = _OSD_SELECT;				
				}
				else
				{
					temp = _OSD_UNSELECT;				
				}
				
				OsdDispSubItem((_SUB_ITEM_PRESET_NEUTRAL+i), temp);
			}

			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM);
			OsdDispSubItem(_SUB_ITEM_COLOR_PRESET, _OSD_UNSELECT);			
			OsdDispSubItem(_SUB_ITEM_COLOR_CUSTOM, _OSD_SELECT);			
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR);			
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);	
			OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
			OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);
#endif
#if(_ASPECT_RATIO_SUPPORT==_ON)		
			if(UserAdjustCheckAspectRatio() == _TRUE)
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
			}
			else
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
			}
#endif
#if(_OD_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif

			OsdDispMainMenuString(_SUB_STRING_COLOR);					
            if(GET_COLOR_TEMP_STATUS() ==  _COLOR_USER)        
            {
                RTDNVRamLoadColorSetting( _CT_USER);
            } 
            else
            {
               RTDNVRamLoadColorSetting( GET_COLOR_TEMP_TYPE());
            }

            if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
            {
                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
                UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
            }
            else
            {
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
			break;

		default:
			break;
	}
}
void OsdPropColorCustom(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:		
			#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130729 for change Color Temp no AdjustBacklight issue
			g_usAdjustValue2 = GET_COLOR_TEMP_TYPE();
			SET_COLOR_TEMP_TYPE(_CT_USER);
			#endif
			RTDNVRamLoadColorSetting(_CT_USER);
			UserAdjustContrast(GET_OSD_CONTRAST());
            UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_RED);
			OsdDispContentClear();
			OsdDispMainMenuString(_MAIN_STRING_CUSTOM);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_UNSELECT);	
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_PRESET);
			OsdDispSubItem(_SUB_ITEM_COLOR_PRESET, _OSD_SELECT);			
			OsdDispSubItem(_SUB_ITEM_COLOR_CUSTOM, _OSD_UNSELECT);			
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR);			
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);	
			OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_SELECT);
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
			OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);
#endif
#if(_ASPECT_RATIO_SUPPORT==_ON)		
			if(UserAdjustCheckAspectRatio() == _TRUE)
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
			}
			else
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
			}
#endif
#if(_OD_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif

			OsdDispMainMenuString(_SUB_STRING_COLOR);			
			break;

		default:
			break;
	}
}

#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
void OsdPropInputAnalog(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
            if((SysSourceGetSourceType() != _SOURCE_VGA))
            {
       		    SET_FORCE_POW_SAV_STATUS(_FALSE);
                SET_SHOW_SOURCE_INFO(_ON);
       		    SysSourceSwitchInputPort(_A0_INPUT_PORT);
       		    
       		    SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
       		    
       		    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
       
       		    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
       		       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
       		    {
       		        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
       		        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
       		        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
       		    }
            }
			else
			{
			#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
				OsdDispDisableOsdTimerEvent();
				SET_KEYHOLDKEY();
			#else
	            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);			
				OsdDispContentClear();              
                OsdDispMainIcon();  
			    OsdLoadFont(_FONT2_DYNAMIC_PROPERTIES_CONTENT);                                
	            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);        //MainIcon反灰
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_USER_DCR_FUNCTION == _ON))		           
				if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || (GET_OSD_DCR_STATUS() == _ON))
				{
					OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
				}
				else
#elif(_LOW_BLUE_LIGHT_FUNCTION == _ON)
				if(GET_LOWBLUELIGHT_STATUS() == _ENABLE) 
				{
					OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
				}
				else
#elif(GET_OSD_DCR_STATUS() == _ON)
				if(GET_OSD_DCR_STATUS() == _ON) 
				{
					OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
				}
				else
#endif
				{
					OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
				}
	            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);        
				if(UserAdjustCheckAspectRatio() == _TRUE)
				{
					OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
				}
				else
				{
					OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
				}
#if(_OD_SUPPORT==_ON)		
    			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
                OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif

	            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);                  //顯示Sub Menu字串  
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
			#endif
			}
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_INPUT_DIGITAL);
			OsdDispSubIcon(_SUB_ICON_ANALOG, _OSD_UNSELECT);	
			OsdDispSubIcon(_SUB_ICON_DIGITAL, _OSD_SELECT);	
			OsdDispSubItem(_SUB_ITEM_INPUT_ANALOG, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_INPUT_DIGITAL, _OSD_SELECT);
		
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_INPUT);
			OsdDispContentClear();
            OsdDispMainIcon();  
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
			OsdLoadFont(_FONT2_DYNAMIC_PROPERTIES_CONTENT);
			OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT);
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_USER_DCR_FUNCTION == _ON))		           
			if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || (GET_OSD_DCR_STATUS() == _ON))
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(_LOW_BLUE_LIGHT_FUNCTION == _ON)
			if(GET_LOWBLUELIGHT_STATUS() == _ENABLE) 
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(GET_OSD_DCR_STATUS() == _ON)
			if(GET_OSD_DCR_STATUS() == _ON) 
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_ASPECT_RATIO_SUPPORT==_ON)		
			if(UserAdjustCheckAspectRatio() == _TRUE)
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
			}
			else
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
			}
#endif

#if(_OD_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif
			OsdDispMainMenuString(_SUB_STRING_INPUT);			
			break;

		default:
			break;
	}
}

void OsdPropInputDigital(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
            if((SysSourceGetSourceType() != _SOURCE_DVI))
            {
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
    		    SET_FORCE_POW_SAV_STATUS(_FALSE);
                SET_SHOW_SOURCE_INFO(_ON);
    		    SysSourceSwitchInputPort(_D0_INPUT_PORT);
#elif(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
    		    SET_FORCE_POW_SAV_STATUS(_FALSE);
                SET_SHOW_SOURCE_INFO(_ON);
    		    SysSourceSwitchInputPort(_D1_INPUT_PORT);
#else
    		    return;
#endif
    		    
    		    SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
    		    
    		    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
    
    		    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
    		       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
    		    {
    		        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
    		        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
    		        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
    		    }
    
            }
			else
			{
			#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
				OsdDispDisableOsdTimerEvent();
				SET_KEYHOLDKEY();
			#else
	            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);			
				OsdDispContentClear();              
                OsdDispMainIcon();  
			    OsdLoadFont(_FONT2_DYNAMIC_PROPERTIES_CONTENT);                
	            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);        //MainIcon反灰
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_USER_DCR_FUNCTION == _ON))		           
				if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || (GET_OSD_DCR_STATUS() == _ON))
				{
					OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
				}
				else
#elif(_LOW_BLUE_LIGHT_FUNCTION == _ON)
				if(GET_LOWBLUELIGHT_STATUS() == _ENABLE) 
				{
					OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
				}
				else
#elif(GET_OSD_DCR_STATUS() == _ON)
				if(GET_OSD_DCR_STATUS() == _ON) 
				{
					OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
				}
				else
#endif
				{
					OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
				}
	            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);        
				if(UserAdjustCheckAspectRatio() == _TRUE)
				{
					OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
				}
				else
				{
					OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
				}
#if(_OD_SUPPORT==_ON)		
    			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
                OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif

	            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);                  //顯示Sub Menu字串  
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
			#endif
			}
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_INPUT_ANALOG);
			OsdDispSubIcon(_SUB_ICON_ANALOG, _OSD_SELECT);	
			OsdDispSubIcon(_SUB_ICON_DIGITAL, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_INPUT_ANALOG, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_INPUT_DIGITAL, _OSD_UNSELECT);		
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_INPUT);
			OsdDispContentClear();
            OsdDispMainIcon();    
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
			OsdLoadFont(_FONT2_DYNAMIC_PROPERTIES_CONTENT);            
			OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_SELECT);
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_ASPECT_RATIO_SUPPORT==_ON)		
			if(UserAdjustCheckAspectRatio() == _TRUE)
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
			}
			else
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
			}
#endif

#if(_OD_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif
			OsdDispMainMenuString(_SUB_STRING_INPUT);			
			break;

		default:
			break;
	}
}
#endif

void OsdPropScalingOff(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
		
#if(_ASPECT_RATIO_SUPPORT==_ON)		
			if((UserAdjustCheckAspectRatio() == _TRUE) && (GET_OSD_ASPECT_RATIO_TYPE() != _ASPECT_RATIO_OFF))
			{				
				SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_OFF);
				UserAdjustSelectAspectRatio();
				SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);	
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
				ScalerOsdDisableOsd();				
			}			
#endif
            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);			
			OsdDispContentClear();              
            OsdDispMainIcon();                       
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);        //MainIcon反灰
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_USER_DCR_FUNCTION == _ON))		           
			if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || (GET_OSD_DCR_STATUS() == _ON))
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(_LOW_BLUE_LIGHT_FUNCTION == _ON)
			if(GET_LOWBLUELIGHT_STATUS() == _ENABLE) 
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(GET_OSD_DCR_STATUS() == _ON)
			if(GET_OSD_DCR_STATUS() == _ON) 
			{
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);        
#endif
            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);     
#if(_OD_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif
            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);                  //顯示Sub Menu字串                  
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_OSD_PROP_SCALING_ON);
			OsdDispSubItem(_SUB_ITEM_SCALING_ON, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_SCALING_OFF, _OSD_UNSELECT);	
			OsdDispMainMenuString(_SUB_STRING_SCALING_ON);
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_SCALING);
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
			OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);
#endif

#if(_OD_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif

			OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_SCALING);					
			break;

		default:
			break;
	}
}
void OsdPropScalingOn(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
#if(_ASPECT_RATIO_SUPPORT==_ON)
			if((UserAdjustCheckAspectRatio() == _TRUE) && (GET_OSD_ASPECT_RATIO_TYPE() != _ASPECT_RATIO_FULL))
			{				
				SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_FULL);
				UserAdjustSelectAspectRatio();
				SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);	
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
				ScalerOsdDisableOsd();
			}
#endif			
            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);			
			OsdDispContentClear();              
            OsdDispMainIcon();                       
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);        //MainIcon反灰
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_USER_DCR_FUNCTION == _ON))		           
			if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || (GET_OSD_DCR_STATUS() == _ON))
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(_LOW_BLUE_LIGHT_FUNCTION == _ON)
			if(GET_LOWBLUELIGHT_STATUS() == _ENABLE) 
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(GET_OSD_DCR_STATUS() == _ON)
			if(GET_OSD_DCR_STATUS() == _ON) 
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif			
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);        
#endif
            OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);      
#if(_OD_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif

            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);                  //顯示Sub Menu字串  
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_SCALING_OFF);
			OsdDispSubItem(_SUB_ITEM_SCALING_ON, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_SCALING_OFF, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_SCALING_OFF);
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_SCALING);
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
			OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);
#endif

#if(_OD_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif

			OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_SELECT);
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif
			OsdDispMainMenuString(_SUB_STRING_SCALING);							
			break;

		default:
			break;
	}
}

#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
void OsdPropBlueLightOff(void)
{
    switch(GET_KEYMESSAGE())
    {                                                                                         
        case _MENU_KEY_MESSAGE: 
#if 0//(_USER_DCR_FUNCTION == _ON)
            if(GET_OSD_DCR_STATUS() == _ON)
            {
                UserAdjustDCRControl(_ON);
            }
#endif
            SET_LOWBLUELIGHT_STATUS(_DISABLE);
            RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            UserAdjustContrast(GET_OSD_CONTRAST());
            UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            RTDNVRamSaveOSDData();

            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);			
			OsdDispContentClear();              
            
            if(GET_COLOR_TEMP_STATUS() == _COLOR_USER)
            {
                OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_UNSELECT);
            }
            else if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
            {
                OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_STATIC);
            }
            else
            {
                OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_UNSELECT);
            }
            
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_USER_DCR_FUNCTION == _ON))		           
			if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || (GET_OSD_DCR_STATUS() == _ON))
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(_LOW_BLUE_LIGHT_FUNCTION == _ON)
			if(GET_LOWBLUELIGHT_STATUS() == _ENABLE) 
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(GET_OSD_DCR_STATUS() == _ON)
			if(GET_OSD_DCR_STATUS() == _ON) 
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif			
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }            
#if(_INPUT_PORT_MAX != 1)
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);        
#endif
            if(UserAdjustCheckAspectRatio() == _TRUE)
            {
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
            }
            else
            {
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
            }
#if(_OD_SUPPORT==_ON)		
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);  
            OsdDispMainIcon();                       
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);                    
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            
            break;                                                                                         
                                                                                                           
        case _RIGHT_KEY_MESSAGE:                                                                           
        case _LEFT_KEY_MESSAGE:                                                  
            SET_OSD_STATE(_OSD_PROP_BLUELIGHT_ON);
            OsdDispSubItem(_SUB_ITEM_BLUELIGHT_OFF, _OSD_UNSELECT);
            OsdDispSubItem(_SUB_ITEM_BLUELIGHT_ON, _OSD_SELECT);  
            break;                                                                                         
                                                                                                           
        case _EXIT_KEY_MESSAGE:  
            SET_OSD_STATE(_OSD_PROP_BLUELIGHT);
            OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);
            if(UserAdjustCheckAspectRatio() == _TRUE)
            {
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
            }
            else
            {
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
            }
            
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if((GET_LOWBLUELIGHT_STATUS() == _ENABLE)||(GET_OSD_DCR_STATUS() == _ON))
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);
#endif

#if(_OD_SUPPORT==_ON)		
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif

            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_SELECT);
            OsdDispMainMenuString(_SUB_STRING_BLUELIGHT); 
            break;

        default:
            break;
    }
}

void OsdPropBlueLightOn(void)
{
    switch(GET_KEYMESSAGE())
    {                                                                                         
        case _MENU_KEY_MESSAGE: 
#if 0//(_USER_DCR_FUNCTION == _ON)
            if(GET_OSD_DCR_STATUS() == _ON)
            {
                UserAdjustDCRControl(_OFF);
            }
#endif
            SET_LOWBLUELIGHT_STATUS(_ENABLE);
            RTDNVRamLoadColorSetting(_CTLOWBLUELIGHT);
            UserAdjustContrast(_LBL_CONTRAST_DEF);
            UserAdjustBacklightPercent(_LBL_BRIGHTNESS_DEF);            
            RTDNVRamSaveOSDData();

            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);			
			OsdDispContentClear();              
            
            if(GET_COLOR_TEMP_STATUS() == _COLOR_USER)
            {
                OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_UNSELECT);
            }
            else if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
            {
                OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_STATIC);
            }
            else
            {
                OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_UNSELECT);
            }
            
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_USER_DCR_FUNCTION == _ON))		           
			if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || (GET_OSD_DCR_STATUS() == _ON))
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(_LOW_BLUE_LIGHT_FUNCTION == _ON)
			if(GET_LOWBLUELIGHT_STATUS() == _ENABLE) 
			{
				OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
			}
			else
#elif(GET_OSD_DCR_STATUS() == _ON)
			if(GET_OSD_DCR_STATUS() == _ON) 
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif			
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }            
#if(_INPUT_PORT_MAX != 1)
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);        
#endif
            if(UserAdjustCheckAspectRatio() == _TRUE)
            {
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
            }
            else
            {
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
            }
#if(_OD_SUPPORT==_ON)		
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);  
            OsdDispMainIcon();                       
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);                    
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);         
            break;                                                                                         
                                                                                                           
        case _RIGHT_KEY_MESSAGE:                                                                           
        case _LEFT_KEY_MESSAGE:  
            SET_OSD_STATE(_OSD_PROP_BLUELIGHT_OFF);
            OsdDispSubItem(_SUB_ITEM_BLUELIGHT_OFF, _OSD_SELECT);
            OsdDispSubItem(_SUB_ITEM_BLUELIGHT_ON, _OSD_UNSELECT);
            break;                                                                                         
                                                                                                           
        case _EXIT_KEY_MESSAGE:                  
            SET_OSD_STATE(_OSD_PROP_BLUELIGHT);
            OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);
            if(UserAdjustCheckAspectRatio() == _TRUE)
            {
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
            }
            else
            {
                OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
            }
            
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if((GET_LOWBLUELIGHT_STATUS() == _ENABLE)||(GET_OSD_DCR_STATUS() == _ON))
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);
#endif

#if(_OD_SUPPORT==_ON)		
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);
#endif

            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_SELECT);
            OsdDispMainMenuString(_SUB_STRING_BLUELIGHT); 
            break;

        default:
            break;
    }
}
#endif

#if(_OD_SUPPORT == _ON)
void OsdPropODOn(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
            SET_OSD_OD_STATUS(_ON);
            ScalerODControl(_ON);
            ScalerODAdjustDeltaGain(GET_OSD_OD_GAIN());            
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            

            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);			
			OsdDispContentClear();              
            OsdDispMainIcon();                       
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);        //MainIcon反灰
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);        
#endif
#if(_ASPECT_RATIO_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
#endif
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);       
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif

            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES); 
            break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_OSD_PROP_OD_OFF);
			OsdDispSubItem(_SUB_ITEM_OD_OFF, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_OD_ON, _OSD_UNSELECT);	
			//OsdDispMainMenuString(_SUB_STRING_OD_ON);
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_OD);
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
			OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);
#endif

			OsdDispSubIcon(_SUB_ICON_OD, _OSD_SELECT);

#if(_ASPECT_RATIO_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif
			OsdDispMainMenuString(_SUB_STRING_OD);		

			break;

		default:
			break;
	}
}

void OsdPropODOff(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
            SET_OSD_OD_STATUS(_OFF);
            ScalerODControl(_OFF);
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            

            SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);			
			OsdDispContentClear();              
            OsdDispMainIcon();                       
            OsdDispMainIconChange(_MAIN_ICON_PROPERTIES, _OSD_SELECT);        //MainIcon反灰
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
            OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);        
#endif
#if(_ASPECT_RATIO_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
#endif
            OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);  
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif

            OsdDispMainMenuString(_MAIN_STRING_PROPERTIES); 
            break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_OSD_PROP_OD_ON);
			OsdDispSubItem(_SUB_ITEM_OD_ON, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_OD_OFF, _OSD_UNSELECT);	
			//OsdDispMainMenuString(_SUB_STRING_OD_ON);
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_OD);
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
            }
            else
#endif
            {
                OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
            }
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
			OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);
#endif

			OsdDispSubIcon(_SUB_ICON_OD, _OSD_SELECT);

#if(_ASPECT_RATIO_SUPPORT==_ON)		
			OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif

			OsdDispMainMenuString(_SUB_STRING_OD);		
			break;

		default:
			break;
	}
}
#endif
void OsdOptionInformationShow(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
            SET_OSD_STATE(_OSD_MAIN_OPTION);			
			OsdDispContentClear();              
            OsdDispMainIcon();                       
            OsdDispMainIconChange(_MAIN_ICON_OPTION, _OSD_SELECT);        //MainIcon反灰
            OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);        
            OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);        
            OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);        
            OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);        
            OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);      //Brightness Icon反白 
            OsdDispMainMenuString(_MAIN_STRING_OPTION);                  //顯示Sub Menu字串      
			OsdDispKeyInfo(_KEY_INFO_EXIT);//Robert Wang 20130816
			break;

		case _RIGHT_KEY_MESSAGE: 
			break;

		case _LEFT_KEY_MESSAGE: 
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_INFORMATION);			
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_OPTION);			
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);
			
			OsdDispMainMenuString(_SUB_STRING_INFORMATION);														
		
			break;

		default:
			break;
	}
}

void OsdOptionLanguageAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_LANGUAGE(g_usAdjustValue0);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			
            SET_OSD_STATE(_OSD_MAIN_OPTION);			
			OsdDispContentClear();              
            OsdDispMainIcon();                       
            OsdDispMainIconChange(_MAIN_ICON_OPTION, _OSD_SELECT);
            OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);        
            OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);        
            OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);        
            OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);        
            OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);  
            OsdDispMainMenuString(_MAIN_STRING_OPTION);           //顯示Sub Menu字串     
            OsdDispKeyInfo(_KEY_INFO_ALL);                        //改變提示文字
            //載入字形改變顯示
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE:
            g_usAdjustValue1 = g_usAdjustValue0;
 			g_usAdjustValue0 = OsdDetOverRange(g_usAdjustValue0, (_LANGUAGE_AMOUNT-1), _ENGLISH, _OSD_REPEAT);
			OsdDispLanguageSelect(g_usAdjustValue0);			
			break;

		case _EXIT_KEY_MESSAGE: 

			SET_OSD_STATE(_OSD_OPTION_LANGUAGE);			
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_OPTION);			
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);
			
			OsdDispMainMenuString(_SUB_STRING_LANGUAGE_SELECT);														
			break;

		default:
			break;
	}
}
void OsdOptionOsdPosDefault(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
		
			SET_OSD_HPOS(50);
			SET_OSD_VPOS(50);
			OsdFuncSetPosition(_POS_PERCENT, GET_OSD_HPOS()*10, GET_OSD_VPOS()*10); 
			SET_OSD_POS_STATUS(_OSDPOS_DEFAULT);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			

			SET_OSD_STATE(_OSD_MAIN_OPTION);
            OsdDispMainIcon();                       

			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM);
			SET_OSD_POS_STATUS(_OSDPOS_CUSTOM);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_DEFAULT, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_CUSTOM, _OSD_SELECT);			
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS);			
			OsdDispContentClear();
			OsdLoadFont(_FONT2_DYNAMIC_OPTION_CONTENT);
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_OPTION);			
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);
			
			OsdDispMainMenuString(_SUB_STRING_OSDPOSTION_SELECT);														
	
			break;

		default:
			break;
	}
}

void OsdOptionOsdPosCustom(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_HPOS);
			OsdDispContentClear();
			g_usAdjustValue0 = GET_OSD_HPOS();
			g_usAdjustValue1 = GET_OSD_VPOS();			
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_SAVE, _OSD_UNSELECT);
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_DEFAULT);
			SET_OSD_POS_STATUS(_OSDPOS_DEFAULT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_DEFAULT, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_CUSTOM, _OSD_UNSELECT);					
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS);		
			OsdDispContentClear();
			OsdLoadFont(_FONT2_DYNAMIC_OPTION_CONTENT);
            OsdDispMainIcon();                                   
            OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_OPTION);	
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);			
			OsdDispMainMenuString(_SUB_STRING_OSDPOSTION_SELECT);																
			break;

		default:
			break;
	}
}

void OsdOptionDefaultCancel(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_DEFAULT_RESET);
			OsdDispSubItem(_SUB_ITEM_DEFAULT_CANCEL, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_DEFAULT_RESET, _OSD_SELECT);
			break;

		case _MENU_KEY_MESSAGE: 
		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_DEFAULT);		
			OsdDispContentClear();            
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_OPTION);			
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);			
			OsdDispMainMenuString(_SUB_STRING_DEFAULT_SELECT);																
			break;

		default:
			break;
	}
}

void OsdOptionDefaultReset(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			OsdReset();

			SET_OSD_STATE(_OSD_MAIN_OPTION);
            OsdDispMainIcon();                       
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_DEFAULT_CANCEL);
			OsdDispSubItem(_SUB_ITEM_DEFAULT_CANCEL, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_DEFAULT_RESET, _OSD_UNSELECT);
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_DEFAULT);			
			OsdDispContentClear();
            OsdDispMainIcon();                       
            OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_OPTION);			
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);			
			OsdDispMainMenuString(_SUB_STRING_DEFAULT_SELECT);																		
			break;

		default:
			break;
	}
}

void OsdOptionAccessibilityButtonRepeat(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 	

			
			if(GET_OSD_BUTTON_REPEAT_STATUS() == _OSD_BUTTON_REPEAT_OFF)
			{
				SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_OFF);
	    		OsdDispContentClear();     
                OsdDispSubIcon(_SUBTITLE_ICON_BUTTON_REPEAT, _OSD_SELECT);                 
    			OsdDispMainMenuString(_SUB_TITLE_STRING_BUTTON_REPEAT);                
				OsdDispSubItem(_SUB_ITEM_BUTTON_OFF, _OSD_SELECT);
				OsdDispSubItem(_SUB_ITEM_BUTTON_DEFAULT, _OSD_UNSELECT);
				OsdDispSubItem(_SUB_ITEM_BUTTON_SLOW, _OSD_UNSELECT);
			}
			else if(GET_OSD_BUTTON_REPEAT_STATUS() == _OSD_BUTTON_REPEAT_DEFAULT)
			{
				SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_DEFAULT);
	    		OsdDispContentClear();      
                OsdDispSubIcon(_SUBTITLE_ICON_BUTTON_REPEAT, _OSD_SELECT);                 
    			OsdDispMainMenuString(_SUB_TITLE_STRING_BUTTON_REPEAT);                                
				OsdDispSubItem(_SUB_ITEM_BUTTON_OFF, _OSD_UNSELECT);
				OsdDispSubItem(_SUB_ITEM_BUTTON_DEFAULT, _OSD_SELECT);
				OsdDispSubItem(_SUB_ITEM_BUTTON_SLOW, _OSD_UNSELECT);
				
			}
			else //if(GET_OSD_BUTTON_REPEAT_STATUS() == _OSD_BUTTON_REPEAT_SLOW)
			{
				SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_SLOW);
	    		OsdDispContentClear();    
                OsdDispSubIcon(_SUBTITLE_ICON_BUTTON_REPEAT, _OSD_SELECT);                 
    			OsdDispMainMenuString(_SUB_TITLE_STRING_BUTTON_REPEAT);                                
				OsdDispSubItem(_SUB_ITEM_BUTTON_OFF, _OSD_UNSELECT);
				OsdDispSubItem(_SUB_ITEM_BUTTON_DEFAULT, _OSD_UNSELECT);
				OsdDispSubItem(_SUB_ITEM_BUTTON_SLOW, _OSD_SELECT);				
			}
			
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_MENU_TIMEOUT);
			OsdDispSubIcon(_SUB_ICON_BUTTON_REPEAT, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_MENU_TIMEOUT, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_MENU_TIMEOUT);																		
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY);
			OsdDispContentClear();
            OsdDispMainIcon();                                   
            OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_OPTION);
			OsdLoadFont(_FONT2_DYNAMIC_OPTION_CONTENT);
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_SELECT);			
			OsdDispMainMenuString(_SUB_STRING_ACCESSIBILITY);																				
			break;

		default:
			break;
	}
}

void OsdOptionAccessibilityMenuTimeout(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_MENU_TIMEOUT_ADJUST);
            OsdDispContentClear();                  
            OsdDispSubIcon(_SUBTITLE_ICON_MENU_TIMEOUT, _OSD_SELECT); 
			OsdDispMainMenuString(_SUB_TITLE_STRING_MENU_TIMEOUT);
			g_usAdjustValue0 = GET_OSD_TIME_OUT();	
			OsdDispSlider(_SLIDER_OSDTIMEOUT);
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_REPEAT);
			OsdDispSubIcon(_SUB_ICON_BUTTON_REPEAT, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_MENU_TIMEOUT, _OSD_UNSELECT);
			OsdDispMainMenuString(_SUB_STRING_BUTTON_REPEAT);																		
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY);
			OsdDispContentClear();
            OsdDispMainIcon();                                             
            OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_SELECT);
			OsdDispMainMenuString(_MAIN_STRING_OPTION);
			OsdLoadFont(_FONT2_DYNAMIC_OPTION_CONTENT);
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_SELECT);			
			OsdDispMainMenuString(_SUB_STRING_ACCESSIBILITY);																				
			break;

		default:
			break;
	}
}


/*--------------------------------------------*/
/*             OSD Menu第四層                 */
/*--------------------------------------------*/
void OsdSetupManualClockAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_PHASE);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_UNSELECT);
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			g_usAdjustValue0 = OsdDetOverRange(g_usAdjustValue0, 100, 0, _OSD_NO_REPEAT);
			OsdDispSlider(_SLIDER_CLOCK);
			UserCommonAdjustClock(g_usAdjustValue0);		
			break;

		case _EXIT_KEY_MESSAGE: 
			UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());		
			g_usAdjustValue0 = GET_VGA_MODE_ADJUST_CLOCK();
			SET_OSD_STATE(_OSD_SETUP_MANUAL_CLOCK);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_UNSELECT);
			break;

		default:
			break;
	}
}

void OsdSetupManualPhaseAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_SETUP_MANUAL_SAVE);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_SELECT);
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			g_usAdjustValue1 = OsdDetOverRange(g_usAdjustValue1, 100, 0, _OSD_NO_REPEAT);
			OsdDispSlider(_SLIDER_PHASE);
			UserCommonAdjustPhase(g_usAdjustValue1);		
			break;

		case _EXIT_KEY_MESSAGE: 
			UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());	
			g_usAdjustValue1 = GET_VGA_MODE_ADJUST_PHASE();
			SET_OSD_STATE(_OSD_SETUP_MANUAL_PHASE);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_MANUAL_CLOCK, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_PHASE, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_MANUAL_SAVE, _OSD_UNSELECT);		
			break;

		default:
			break;
	}
}

void OsdPropColorPresetAdjust(void)
{
	BYTE i, temp;
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 		
			SET_COLOR_TEMP_STATUS(_COLOR_PRESET);
			SET_COLOR_TEMP_TYPE(g_usAdjustValue0);           
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
            OsdDispMainIcon();                                             
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);

			if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
			{
				OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_STATIC);
			}
			else
			{
				OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_UNSELECT);
			}

			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);			
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 

			
			g_usAdjustValue0 = OsdDetOverRange(g_usAdjustValue0, _CT_9300, _CT_7200, _OSD_REPEAT);


			for(i=0; i<4; i++)
			{
				if(g_usAdjustValue0 == i)
				{
					temp = _OSD_SELECT;				
				}
				else
				{
					temp = _OSD_UNSELECT;				
				}
				
				OsdDispSubItem((_SUB_ITEM_PRESET_NEUTRAL+i), temp);
			}

			RTDNVRamLoadColorSetting(g_usAdjustValue0);

#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
			SET_COLOR_TEMP_TYPE(g_usAdjustValue0);
#endif
			
            if(g_usAdjustValue0 == _CT_SRGB)
            {
                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
                UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
            }
            else
            {
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
			
			break;

		case _EXIT_KEY_MESSAGE: 
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
				RTDNVRamLoadOSDData();
#endif
			
            if(GET_COLOR_TEMP_STATUS() ==  _COLOR_USER)           			                  
            {
                RTDNVRamLoadColorSetting(_CT_USER);
            }
            else
            {
			    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }

            if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
            {
                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
                UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
            }
            else
            {
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
            
			SET_OSD_STATE(_OSD_PROP_COLOR_PRESET);
			OsdDispContentClear();
			OsdDispMainMenuString(_MAIN_STRING_COLOR);
			OsdDispSubItem(_SUB_ITEM_COLOR_PRESET, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_COLOR_CUSTOM, _OSD_UNSELECT);					
			break;

		default:
			break;
	}
	
}

void OsdPropColorCustomRed(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_RED_ADJUST);
			OsdDispContentClear();				
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED_ADJUST, _OSD_INDICATE);
			g_usAdjustValue0 = g_usAdjustValue1 = GET_COLOR_TEMP_TYPE_USER_R();//lorimiao 20140819 for Adjust User RGB issue
			OsdDispSlider(_SLIDER_RED);
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_GREEN);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_SELECT);
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_SAVE);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_SELECT);		
			break;

		case _EXIT_KEY_MESSAGE: 
			#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130729 for change Color Temp no AdjustBacklight issue
			SET_COLOR_TEMP_TYPE(g_usAdjustValue2);
			RTDNVRamSaveOSDData();
			#endif
            if(GET_COLOR_TEMP_STATUS() ==  _COLOR_USER)           			                  
            {
                RTDNVRamLoadColorSetting(_CT_USER);
            } 
            else
            {
			    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }    

            if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
            {
                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
                UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
            }
            else
            {
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM);
			OsdDispContentClear();
			OsdDispMainMenuString(_MAIN_STRING_COLOR);
			OsdDispSubItem(_SUB_ITEM_COLOR_PRESET, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_COLOR_CUSTOM, _OSD_SELECT);	
			break;

		default:
			break;
	}
}
void OsdPropColorCustomGreen(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_GREEN_ADJUST);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN_ADJUST, _OSD_INDICATE);
			g_usAdjustValue0 = g_usAdjustValue1 = GET_COLOR_TEMP_TYPE_USER_G();//lorimiao 20140819 for Adjust User RGB issue
			OsdDispSlider(_SLIDER_GREEN);		
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_BLUE);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_SELECT);		
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_RED);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_SELECT);				
			break;

		case _EXIT_KEY_MESSAGE: 
			#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130729 for change Color Temp no AdjustBacklight issue
			SET_COLOR_TEMP_TYPE(g_usAdjustValue2);
			RTDNVRamSaveOSDData();
			#endif
			
			if(GET_COLOR_TEMP_STATUS() ==  _COLOR_USER)           			                  
			{
                RTDNVRamLoadColorSetting(_CT_USER);
			}
            else
            {
			    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }

            if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
            {
                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
                UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
            }
            else
            {
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }            
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM);
			OsdDispContentClear();
			OsdDispMainMenuString(_MAIN_STRING_COLOR);
			OsdDispSubItem(_SUB_ITEM_COLOR_PRESET, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_COLOR_CUSTOM, _OSD_SELECT);			
			break;

		default:
			break;
	}
}
void OsdPropColorCustomBlue(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_BLUE_ADJUST);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE_ADJUST, _OSD_INDICATE);
			g_usAdjustValue0 = g_usAdjustValue1 = GET_COLOR_TEMP_TYPE_USER_B();//lorimiao 20140819 for Adjust User RGB issue
			OsdDispSlider(_SLIDER_BLUE);		
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_SAVE);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_SELECT);						
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_GREEN);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_SELECT);								
			break;

		case _EXIT_KEY_MESSAGE: 
			#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130729 for change Color Temp no AdjustBacklight issue
			SET_COLOR_TEMP_TYPE(g_usAdjustValue2);
			RTDNVRamSaveOSDData();
			#endif

			if(GET_COLOR_TEMP_STATUS() ==  _COLOR_USER)    
			{
                RTDNVRamLoadColorSetting(_CT_USER);
			}
            else
            {
			    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }    

            if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
            {
                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
                UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
            }
            else
            {
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM);
			OsdDispContentClear();
			OsdDispMainMenuString(_MAIN_STRING_COLOR);
			OsdDispSubItem(_SUB_ITEM_COLOR_PRESET, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_COLOR_CUSTOM, _OSD_SELECT);			
			break;

		default:
			break;
	}
}
void OsdPropColorCustomSave(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_UNSELECT);			
			SET_COLOR_TEMP_STATUS(_COLOR_USER);	
			#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130729 for change Color Temp no AdjustBacklight issue
			SET_COLOR_TEMP_TYPE(g_usAdjustValue2);
			RTDNVRamSaveOSDData();
			#endif
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			RTDNVRamSaveColorSetting(_CT_USER);
			SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
            OsdDispMainIcon();                                             
			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);			
			break;



		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_RED);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_SELECT);										
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_BLUE);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_SELECT);												
			break;
		
		case _EXIT_KEY_MESSAGE: 
			#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130729 for change Color Temp no AdjustBacklight issue
			SET_COLOR_TEMP_TYPE(g_usAdjustValue2);
			RTDNVRamSaveOSDData();
			#endif
			if(GET_COLOR_TEMP_STATUS() ==  _COLOR_USER)    
			{
                RTDNVRamLoadColorSetting(_CT_USER);
			}
            else
            {
			   RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }
            
            if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
            {
                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
                UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
            }
            else
            {
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM);
			OsdDispContentClear();
			OsdDispMainMenuString(_MAIN_STRING_COLOR);
			OsdDispSubItem(_SUB_ITEM_COLOR_PRESET, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_COLOR_CUSTOM, _OSD_SELECT);			
			break;

		default:
			break;
	}
}
void OsdOptionOsdPosCustomHPos(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_HPOS_ADJUST);
			OsdDispContentClear();	
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H_ADJUST, _OSD_SELECT);
			//OsdLoadFont(_FONT2_DYNAMIC_OSDPOSITION_CONTENT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS_HPOS_ADJUST, _OSD_INDICATE);  //顯示Icon   
			OsdDispSlider(_SLIDER_OSDHPOS);			
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_VPOS);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V, _OSD_SELECT);
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_SAVE);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_SAVE, _OSD_SELECT);		
			break;

		case _EXIT_KEY_MESSAGE: 
			OsdFuncSetPosition(_POS_PERCENT, GET_OSD_HPOS()*10, GET_OSD_VPOS()*10);				
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_OSDPOS_DEFAULT, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_CUSTOM, _OSD_SELECT);		
			break;

		default:
			break;
	}
}

void OsdOptionOsdPosCustomVPos(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_VPOS_ADJUST);
			OsdDispContentClear();	
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V_ADJUST, _OSD_SELECT);
			//OsdLoadFont(_FONT2_DYNAMIC_OSDPOSITION_CONTENT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS_VPOS_ADJUST, _OSD_INDICATE);  //顯示Icon   
			OsdDispSlider(_SLIDER_OSDVPOS);					
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_SAVE);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_SAVE, _OSD_SELECT);				
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_HPOS);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H, _OSD_SELECT);						
			break;

		case _EXIT_KEY_MESSAGE: 
			OsdFuncSetPosition(_POS_PERCENT, GET_OSD_HPOS()*10, GET_OSD_VPOS()*10);			
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_OSDPOS_DEFAULT, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_CUSTOM, _OSD_SELECT);		
			break;

		default:
			break;
	}
}

void OsdOptionOsdPosCustomSave(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_POS_STATUS(_OSDPOS_CUSTOM);
			SET_OSD_HPOS(g_usAdjustValue0);			
			SET_OSD_VPOS(g_usAdjustValue1);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			

			SET_OSD_STATE(_OSD_MAIN_OPTION);
            OsdDispMainIcon();                                             

			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
		
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_HPOS);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_SAVE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H, _OSD_SELECT);				
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_VPOS);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_SAVE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V, _OSD_SELECT);						
			break;

		case _EXIT_KEY_MESSAGE: 
			OsdFuncSetPosition(_POS_PERCENT, GET_OSD_HPOS()*10, GET_OSD_VPOS()*10);			
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_OSDPOS_DEFAULT, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_CUSTOM, _OSD_SELECT);				
			break;

		default:
			break;
	}
}

void OsdOptionAccessibilityButtonOFF(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:
			SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_OFF);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
		
			SET_OSD_STATE(_OSD_MAIN_OPTION);
            OsdDispMainIcon();                                             

			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_DEFAULT);
			OsdDispSubItem(_SUB_ITEM_BUTTON_OFF, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_BUTTON_DEFAULT, _OSD_SELECT);	
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_SLOW);
			OsdDispSubItem(_SUB_ITEM_BUTTON_OFF, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_BUTTON_SLOW, _OSD_SELECT);			
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_REPEAT);
			OsdDispMainMenuString(_MAIN_STRING_ACCESSIBILITY);
			OsdDispContentClear();
			OsdDispSubIcon(_SUB_ICON_BUTTON_REPEAT, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_MENU_TIMEOUT, _OSD_UNSELECT);
			OsdDispMainMenuString(_SUB_STRING_BUTTON_REPEAT);
			break;

		default:
			break;
	}
}

void OsdOptionAccessibilityButtonDefault(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_DEFAULT);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
		
			SET_OSD_STATE(_OSD_MAIN_OPTION);
            OsdDispMainIcon();                                             

			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_SLOW);
			OsdDispSubItem(_SUB_ITEM_BUTTON_DEFAULT, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_BUTTON_SLOW, _OSD_SELECT);					
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_OFF);
			OsdDispSubItem(_SUB_ITEM_BUTTON_DEFAULT, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_BUTTON_OFF, _OSD_SELECT);							
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_REPEAT);
			OsdDispMainMenuString(_MAIN_STRING_ACCESSIBILITY);
			OsdDispContentClear();
			OsdDispSubIcon(_SUB_ICON_BUTTON_REPEAT, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_MENU_TIMEOUT, _OSD_UNSELECT);
			OsdDispMainMenuString(_SUB_STRING_BUTTON_REPEAT);		
			break;

		default:
			break;
	}
}

void OsdOptionAccessibilityButtonSlow(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_SLOW);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
		
			SET_OSD_STATE(_OSD_MAIN_OPTION);
            OsdDispMainIcon();                                             

			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		case _RIGHT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_OFF);
			OsdDispSubItem(_SUB_ITEM_BUTTON_SLOW, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_BUTTON_OFF, _OSD_SELECT);									
			break;

		case _LEFT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_DEFAULT);
			OsdDispSubItem(_SUB_ITEM_BUTTON_SLOW, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_BUTTON_DEFAULT, _OSD_SELECT);											
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_BUTTON_REPEAT);
			OsdDispMainMenuString(_MAIN_STRING_ACCESSIBILITY);
			OsdDispContentClear();
			OsdDispSubIcon(_SUB_ICON_BUTTON_REPEAT, _OSD_SELECT);
			OsdDispSubIcon(_SUB_ICON_MENU_TIMEOUT, _OSD_UNSELECT);
			OsdDispMainMenuString(_SUB_STRING_BUTTON_REPEAT);		
			break;

		default:
			break;
	}
}

void OsdOptionAccessibilityMenuTimeoutAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_TIME_OUT(g_usAdjustValue0);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
			SET_OSD_STATE(_OSD_MAIN_OPTION);
            OsdDispMainIcon();                                             

			OsdDispMainIconChange((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
			// sub content
			OsdDispContent((GET_OSD_STATE() - _OSD_MAIN_BRIGHTCONTRAST));		
			OsdDispKeyInfo(_KEY_INFO_EXIT);
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			g_usAdjustValue0 = OsdDetOverRange(g_usAdjustValue0, 60, 5, _OSD_NO_REPEAT);		
			OsdDispSlider(_SLIDER_OSDTIMEOUT);			
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_ACCESSIBILITY_MENU_TIMEOUT);
			OsdDispMainMenuString(_MAIN_STRING_ACCESSIBILITY);
			OsdDispContentClear();
			OsdDispSubIcon(_SUB_ICON_BUTTON_REPEAT, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_MENU_TIMEOUT, _OSD_SELECT);
			OsdDispMainMenuString(_SUB_STRING_MENU_TIMEOUT);
			break;

		default:
			break;
	}
}

/*--------------------------------------------*/
/*             OSD Menu第五層                 */
/*--------------------------------------------*/
void OsdPropColorCustomRedAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
		
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_GREEN);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_UNSELECT);			
		
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			SET_COLOR_TEMP_TYPE_USER_R(OsdDetOverRange(GET_COLOR_TEMP_TYPE_USER_R(), _USER_COLOR_MAX, _USER_COLOR_MIN, _OSD_NO_REPEAT));	
            g_usAdjustValue1 = GET_COLOR_TEMP_TYPE_USER_R();//Eli 20121128 H9CMT178GTG1HN-38 Modify User color save bug. 
			OsdDispSlider(_SLIDER_RED);
			UserAdjustContrast(GET_OSD_CONTRAST());
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_COLOR_TEMP_TYPE_USER_R(g_usAdjustValue0);
			UserAdjustContrast(GET_OSD_CONTRAST());
		
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_RED);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_UNSELECT);			
			break;

		default:
			break;
	}
}
void OsdPropColorCustomGreenAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_BLUE);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_UNSELECT);			
		
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();			
			SET_COLOR_TEMP_TYPE_USER_G(OsdDetOverRange(GET_COLOR_TEMP_TYPE_USER_G(), _USER_COLOR_MAX, _USER_COLOR_MIN, _OSD_NO_REPEAT));	
            g_usAdjustValue1 = GET_COLOR_TEMP_TYPE_USER_G();//Eli 20121128 H9CMT178GTG1HN-38 Modify User color save bug.
			OsdDispSlider(_SLIDER_GREEN);
			UserAdjustContrast(GET_OSD_CONTRAST());		
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_COLOR_TEMP_TYPE_USER_G(g_usAdjustValue0);
			UserAdjustContrast(GET_OSD_CONTRAST());
		
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_GREEN);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_UNSELECT);			
			break;

		default:
			break;
	}
}
void OsdPropColorCustomBlueAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_SAVE);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_SELECT);			
		
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			SET_COLOR_TEMP_TYPE_USER_B(OsdDetOverRange(GET_COLOR_TEMP_TYPE_USER_B(), _USER_COLOR_MAX, _USER_COLOR_MIN, _OSD_NO_REPEAT));	
            g_usAdjustValue1 = GET_COLOR_TEMP_TYPE_USER_B();//Eli 20121128 H9CMT178GTG1HN-38 Modify User color save bug.
			OsdDispSlider(_SLIDER_BLUE);
			UserAdjustContrast(GET_OSD_CONTRAST());		
		
			break;

		case _EXIT_KEY_MESSAGE: 
			SET_COLOR_TEMP_TYPE_USER_B(g_usAdjustValue0);
			UserAdjustContrast(GET_OSD_CONTRAST());
		
			SET_OSD_STATE(_OSD_PROP_COLOR_CUSTOM_BLUE);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_CUSTOM_RED, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_GREEN, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_BLUE, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_CUSTOM_SAVE, _OSD_UNSELECT);			
			break;

		default:
			break;
	}
}
void OsdOptionOsdPosCustomHPosAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_VPOS);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_SAVE, _OSD_UNSELECT);
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			g_usAdjustValue0 = OsdDetOverRange(g_usAdjustValue0, 100, 0, _OSD_NO_REPEAT);		
#if 1//(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
			if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
			{
				OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_OSDHPOS_L, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);					
				OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_OSDHPOS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);	
			}
			else if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
			{
				OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_OSDHPOS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					 
				OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_OSDHPOS_R, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);  
			}
#endif
			OsdDispSlider(_SLIDER_OSDHPOS);
			OsdFuncSetPosition(_POS_PERCENT, g_usAdjustValue0*10, g_usAdjustValue1*10);
			break;

		case _EXIT_KEY_MESSAGE: 		
			g_usAdjustValue0 = GET_OSD_HPOS();
			OsdFuncSetPosition(_POS_PERCENT, g_usAdjustValue0*10, g_usAdjustValue1*10);
			
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_HPOS);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_SAVE, _OSD_UNSELECT);
			break;

		default:
			break;
	}
}

void OsdOptionOsdPosCustomVPosAdjust(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_SAVE);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_SAVE, _OSD_SELECT);		
			break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			g_usAdjustValue1 = OsdDetOverRange(g_usAdjustValue1, 100, 0, _OSD_NO_REPEAT);		
#if 1//(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
			if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
			{
				OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_OSDVPOS_L, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);					
				OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_OSDVPOS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);	
			}
			else if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
			{
				OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_OSDVPOS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					 
				OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_OSDVPOS_R, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);  
			}
#endif
		
			OsdDispSlider(_SLIDER_OSDVPOS);

			OsdFuncSetPosition(_POS_PERCENT, g_usAdjustValue0*10, g_usAdjustValue1*10);
			break;

		case _EXIT_KEY_MESSAGE: 
			g_usAdjustValue1 = GET_OSD_VPOS();
			OsdFuncSetPosition(_POS_PERCENT, g_usAdjustValue0*10, g_usAdjustValue1*10);
		
			SET_OSD_STATE(_OSD_OPTION_OSDPOS_CUSTOM_VPOS);
			OsdDispContentClear();
			OsdDispSubItem(_SUB_ITEM_OSDPOS_H, _OSD_UNSELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_V, _OSD_SELECT);
			OsdDispSubItem(_SUB_ITEM_OSDPOS_SAVE, _OSD_UNSELECT);
		
			break;

		default:
			break;
	}
}
//Bright HotKey Menu
void OsdHotkeyBrightAdjust(void)
{
#if((_LENOVO_DPS_SUPPORT == _ON)&&(_ENERGY_STAR_SUPPORT == _ON))
    BYTE ucTempBackLight = 0;
#endif

    switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:                                            
			SET_OSD_BACKLIGHT(g_usAdjustValue0);           
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);   //儲存Bri Data    
            OsdDispDisableOsdTimerEvent();                                 //回到上一層(Menu None)	
            SET_KEYHOLDKEY();

            break;

		case _RIGHT_KEY_MESSAGE: 
		case _LEFT_KEY_MESSAGE: 
//			SET_KEYREPEATENABLE();
			g_usAdjustValue0 = OsdDetOverRange(g_usAdjustValue0, 100, 0, _OSD_NO_REPEAT);		
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
			if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
			{
				OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_BRIGHTNESS_L, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1); 				
				OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_BRIGHTNESS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);
			}
			else if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
			{
				OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_BRIGHTNESS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB); 				
				OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_BRIGHTNESS_R, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			}
#endif
			OsdDispSlider(_SLIDER_BRIGHTNESS);
#if((_LENOVO_DPS_SUPPORT == _ON)&&(_ENERGY_STAR_SUPPORT == _ON))
            if(GET_OSD_ES_STATUS() == _ON) 
            {
                ucTempBackLight = GET_OSD_BACKLIGHT();//ym20131007 . 
                SET_OSD_BACKLIGHT(g_usAdjustValue0);
                
                // Search Target Backlight Value.
                UserCommonAdjustESDcrSearchTargetPWM();

                // Set Adjust Value = Target Value.
                SET_ES_DCR_PWM_ADJUST_VALUE(GET_ES_DCR_PWM_TARGET_VALUE());

                // Set Backlight Value.
                UserAdjustBacklight(GET_ES_DCR_PWM_ADJUST_VALUE());

                SET_OSD_BACKLIGHT(ucTempBackLight);//ym20131007 . 
            }
            else
            {
        		UserAdjustBacklightPercent(g_usAdjustValue0);
            }
#else
        	UserAdjustBacklightPercent(g_usAdjustValue0);
#endif
			break;
			
		case _EXIT_KEY_MESSAGE: 
#if((_LENOVO_DPS_SUPPORT == _ON)&&(_ENERGY_STAR_SUPPORT == _ON))//ym20131014 . 
            if(GET_OSD_ES_STATUS() == _ON) 
            {
                // Search Target Backlight Value.
                UserCommonAdjustESDcrSearchTargetPWM();

                // Set Adjust Value = Target Value.
                SET_ES_DCR_PWM_ADJUST_VALUE(GET_ES_DCR_PWM_TARGET_VALUE());

                // Set Backlight Value.
                UserAdjustBacklight(GET_ES_DCR_PWM_ADJUST_VALUE());
            }
            else
            {
        		UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
#else
			UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
#endif
			OsdDispDisableOsdTimerEvent();         //回到上一層(Menu None)
		    SET_KEYHOLDKEY();
			break;


		default:
			break;
	}
	
}
/*----------------------------------------------------*/
/*                  OSD動作Table                      */
/*----------------------------------------------------*/
code void (*OperationTable[])(void) =
{
//---0---
	OsdMenuNone,

//---1---
    OsdMainMenuBrightContrast,
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))		           
    OsdMainMenuLowBlueLight,
#endif  
    OsdMainMenuImagePostion,
    OsdMainMenuImageSetup,
    OsdMainMenuImageProperties,
    OsdMainMenuOption,
    OsdMainMenuExit,
    OsdMainMenuTPVFactory,
    
//---2---
    OsdPictureBright,
    OsdPictureContrast,
#if(_LENOVO_DPS_SUPPORT == _ON)
    OsdPictureDps,
#endif  
#if(_USER_DCR_FUNCTION == _ON)
    OsdPictureDCR,
#endif

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))		           
    OsdLowBlueLightEnable,
    OsdLowBlueLightDisable,
#endif  
    OsdPosHPos,
    OsdPosVPos,
    OsdSetupAutomatic,
    OsdSetupManual,
    OsdPropColor,
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
    OsdPropInput,
#endif
    OsdPropScaling,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
    OsdPropBlueLight,
#endif    
#if(_OD_SUPPORT == _ON)
    OsdPropOD,
#endif
    OsdOptionInformation,
    OsdOptionLanguage,
    OsdOptionOsdPos,
    OsdOptionDefault,
    OsdOptionAccessibility,

//---3---
    OsdPictureBrightAdjust,
    OsdPictureContrastAdjust,
#if(_LENOVO_DPS_SUPPORT == _ON)
    OsdPictureDpsAdjust,
#endif  
#if(_USER_DCR_FUNCTION == _ON)
   OsdPictureDCRAdjust,
#endif

    OsdPosHPosAdjust,
    OsdPosVPosAdjust,
    OsdSetupManualClock,
    OsdSetupManualPhase,
    OsdSetupManualSave,
    OsdPropColorPreset,
    OsdPropColorCustom,
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
    OsdPropInputAnalog,
    OsdPropInputDigital,
#endif
    OsdPropScalingOff,
    OsdPropScalingOn,
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
    OsdPropBlueLightOff,
    OsdPropBlueLightOn,
#endif

#if(_OD_SUPPORT == _ON)
    OsdPropODOn,
    OsdPropODOff,
#endif

    OsdOptionInformationShow,
    OsdOptionLanguageAdjust,
    OsdOptionOsdPosDefault,
    OsdOptionOsdPosCustom,
    OsdOptionDefaultCancel,
    OsdOptionDefaultReset,
    OsdOptionAccessibilityButtonRepeat,
    OsdOptionAccessibilityMenuTimeout,

//---4---
    OsdSetupManualClockAdjust,
    OsdSetupManualPhaseAdjust,
    OsdPropColorPresetAdjust,
    OsdPropColorCustomRed,
    OsdPropColorCustomGreen,
    OsdPropColorCustomBlue,
    OsdPropColorCustomSave,
    OsdOptionOsdPosCustomHPos,
    OsdOptionOsdPosCustomVPos,
    OsdOptionOsdPosCustomSave,
    OsdOptionAccessibilityButtonOFF,
    OsdOptionAccessibilityButtonDefault,
    OsdOptionAccessibilityButtonSlow,
    OsdOptionAccessibilityMenuTimeoutAdjust,

//---5---
    OsdPropColorCustomRedAdjust,
    OsdPropColorCustomGreenAdjust,
    OsdPropColorCustomBlueAdjust,
    OsdOptionOsdPosCustomHPosAdjust,
    OsdOptionOsdPosCustomVPosAdjust,

//---Hotkey----
    OsdHotkeyBrightAdjust,
};


void OsdReset(void)
{
#if(_VGA_SUPPORT == _ON)
    UserCommonNVRamRestoreModeUserData();
#endif

	SET_OSD_BACKLIGHT(_OSD_BRIGHTNESS_DEF_VALUE);
	UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());

	SET_COLOR_TEMP_TYPE_USER_R(_USER_COLOR_MAX);
	SET_COLOR_TEMP_TYPE_USER_G(_USER_COLOR_MAX);
	SET_COLOR_TEMP_TYPE_USER_B(_USER_COLOR_MAX);
	RTDNVRamSaveColorSetting(_CT_USER);

	SET_COLOR_TEMP_STATUS(_COLOR_PRESET);

#if((_FACTORY_MODE_OWNER == _OWNER_TPV) && (_DFM_DC_RESET_7200_FUNCTION == _ON))
    if(TPVDFMModeFlag()==_ON)
    {
	    SET_COLOR_TEMP_TYPE(_CT_6500);
    }
    else
#elif (_FACTORY_MODE_OWNER == _OWNER_WISTRON)            
    if(( GET_ATE_COMMAND_STATUS()== _ON)||(GET_FACTORY_MODE() == _ON))		//Irene modify for Factory need.
    {
	    SET_COLOR_TEMP_TYPE(_CT_7200);
        RTDEepromRestorePanelUsedTimeData();
    }
    else
#endif        
    {
      #if((_FACTORY_MODE_OWNER == _OWNER_WISTRON) ||(_FACTORY_MODE_OWNER == _OWNER_TPV))        
	    SET_COLOR_TEMP_TYPE(_CT_6500);
      #else
	    SET_COLOR_TEMP_TYPE(_COLOR_TEMP_DEF);
      #endif
    }

	RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

	SET_OSD_CONTRAST(_OSD_CONTRAST_DEF_VALUE);
	UserAdjustContrast(GET_OSD_CONTRAST());
#if(_ASPECT_RATIO_SUPPORT==_ON)
	if((UserAdjustCheckAspectRatio() == _TRUE) && (GET_OSD_ASPECT_RATIO_TYPE() != _ASPECT_RATIO_FULL))
	{
		SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_FULL);
		UserAdjustSelectAspectRatio();
		SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);	
//		ScalerOsdDisableOsd();					
	}
	else
	{
		SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_FULL);		
	}
#endif

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
    SET_LOWBLUELIGHT_STATUS(_DISABLE);
#endif
	SET_OSD_HPOS(50);
	SET_OSD_VPOS(50);
	OsdFuncSetPosition(_POS_PERCENT, GET_OSD_HPOS()*10, GET_OSD_VPOS()*10); 
	SET_OSD_POS_STATUS(_OSDPOS_DEFAULT);

	SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_DEFAULT);
	SET_OSD_TIME_OUT(10);
	
    SET_OSD_DDCCI_STATUS(_ON);
    ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());
#if(_LENOVO_DPS_SUPPORT == _ON)
    SET_OSD_ES_STATUS(_OFF);
#endif
#if(_USER_DCR_FUNCTION == _ON)
    SET_OSD_DCR_STATUS(_OFF);
#endif


#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)            
#if(_GAMMA_FUNCTION == _ON)
    SET_OSD_GAMMA(_GAMMA_22);
#endif
#endif
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
    if(TPVDFMAutoConfigByPass()==_FALSE)
#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20150302 for Foxconn Factory Recall Command
	if(FactoryCommandRecallFlag == 0)
#endif      
    {
    	if(SysSourceGetSourceType() == _SOURCE_VGA)
    	{
    		UserCommonAutoConfig();
    	}
    }

#if(_OD_SUPPORT == _ON)
    SET_OSD_OD_STATUS(_ON);
    ScalerODControl(_ON);
    ScalerODAdjustDeltaGain(GET_OSD_OD_GAIN());  
#endif      

	RTDNVRamSaveBriCon();
	RTDNVRamSaveOSDData();
#if(_AUDIO_EXTERNAL_AMP_SUPPORT == _ON)
	UserAdjustAudioVolume(GET_OSD_VOLUME());
#endif
		
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
    SET_FACTORY_BURNIN(_OFF);
	SET_FACTORY_MODE(_OFF);
    TPVNVRamSaveFactoryDate();	
    TPVDFMFactoryRest();
#elif (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
	SET_FACTORY_MODE(_OFF);
	SET_FACTORY_BURNIN(_OFF);
	SET_FACTORY_LOGO_ON_OFF(_ON);
	NVRamSaveFactoryDate();
	SET_ENERGY_MODE(_OFF);
#elif(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    g_bDoATECmdOK = _TRUE;
#endif   
    
}
//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdTimeoutSaveData(void)//Eli 20121001 modify bug T9CGT478FEG3HN-74,T9CGT478FEG3HN-77.
{
    if(GET_OSD_STATE() == _OSD_PICTURE_BRIGHTNESS_ADJUST)
    {
        SET_OSD_BACKLIGHT(g_usAdjustValue0);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    else if(GET_OSD_STATE() == _OSD_HOTKEY_BRIGHTNESS_ADJUST)   //20121018_1 Abel Bri Hotkey  Modify
    {
        SET_OSD_BACKLIGHT(g_usAdjustValue0);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }    
    else if(GET_OSD_STATE() == _OSD_PICTURE_CONTRAST_ADJUST)
    {
        SET_OSD_CONTRAST(g_usAdjustValue0);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);//lorimiao 20130801 for OsdTimeout contrast no save
    }
    else if(GET_OSD_STATE() == _OSD_POS_HPOS_ADJUST)
    {
        SET_VGA_MODE_ADJUST_H_POSITION(g_usAdjustValue0);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);                
    }
    else if(GET_OSD_STATE() == _OSD_POS_VPOS_ADJUST)
    {
        SET_VGA_MODE_ADJUST_V_POSITION(g_usAdjustValue1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
    }
    else if((GET_OSD_STATE() == _OSD_SETUP_MANUAL_PHASE_ADJUST)||(GET_OSD_STATE() == _OSD_SETUP_MANUAL_CLOCK_ADJUST)||
        ((GET_OSD_STATE() >= _OSD_SETUP_MANUAL_CLOCK) && (GET_OSD_STATE() <= _OSD_SETUP_MANUAL_SAVE)))
    {
        SET_VGA_MODE_ADJUST_CLOCK(g_usAdjustValue0);
        SET_VGA_MODE_ADJUST_PHASE(g_usAdjustValue1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
    }
    else if(GET_OSD_STATE() == _OSD_PROP_COLOR_PRESET_ADJUST)
    {
        SET_COLOR_TEMP_STATUS(_COLOR_PRESET);//Eli 20121128 H9CMT178GTG1HN-38 Modify User color save bug.
        SET_COLOR_TEMP_TYPE(g_usAdjustValue0);           
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    else if((GET_OSD_STATE() >= _OSD_PROP_COLOR_CUSTOM_RED) && (GET_OSD_STATE() <= _OSD_PROP_COLOR_CUSTOM_SAVE))
    {
		#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
		SET_COLOR_TEMP_TYPE(g_usAdjustValue2);
		#endif
        SET_COLOR_TEMP_STATUS(_COLOR_USER); 
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        RTDNVRamSaveColorSetting(_CT_USER);
    }
    else if(GET_OSD_STATE() == _OSD_PROP_COLOR_CUSTOM_RED_ADJUST)//Eli 20121128 H9CMT178GTG1HN-38 Modify User color save bug.
    {
		#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
		SET_COLOR_TEMP_TYPE(g_usAdjustValue2);
		#endif
        SET_COLOR_TEMP_STATUS(_COLOR_USER); 
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        SET_COLOR_TEMP_TYPE_USER_R(g_usAdjustValue1); 
        RTDNVRamSaveColorSetting(_CT_USER);
    }
    else if(GET_OSD_STATE() == _OSD_PROP_COLOR_CUSTOM_GREEN_ADJUST)//Eli 20121128 H9CMT178GTG1HN-38 Modify User color save bug.
    {
		#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
		SET_COLOR_TEMP_TYPE(g_usAdjustValue2);
		#endif
        SET_COLOR_TEMP_STATUS(_COLOR_USER); 
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        SET_COLOR_TEMP_TYPE_USER_G(g_usAdjustValue1);          
        RTDNVRamSaveColorSetting(_CT_USER);
    }
    else if(GET_OSD_STATE() == _OSD_PROP_COLOR_CUSTOM_BLUE_ADJUST)//Eli 20121128 H9CMT178GTG1HN-38 Modify User color save bug.
    {
		#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
		SET_COLOR_TEMP_TYPE(g_usAdjustValue2);
		#endif
        SET_COLOR_TEMP_STATUS(_COLOR_USER); 
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        SET_COLOR_TEMP_TYPE_USER_B(g_usAdjustValue1);          
        RTDNVRamSaveColorSetting(_CT_USER);
    }//Eli 20130102 H9CMT178GTG1HN-103 Modify OSD H/V position save bug.
    else if(((GET_OSD_STATE() >= _OSD_OPTION_OSDPOS_CUSTOM_HPOS) && (GET_OSD_STATE() <= _OSD_OPTION_OSDPOS_CUSTOM_SAVE))||
        ((GET_OSD_STATE() == _OSD_OPTION_OSDPOS_CUSTOM_HPOS_ADJUST) || (GET_OSD_STATE() == _OSD_OPTION_OSDPOS_CUSTOM_VPOS_ADJUST)))
    {
        SET_OSD_HPOS(g_usAdjustValue0);         
        SET_OSD_VPOS(g_usAdjustValue1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);   
    }
/*//Eli 20130102 H9CMT178GTG1HN-103 Modify OSD H/V position save bug.    
    else if(GET_OSD_STATE() == _OSD_OPTION_OSDPOS_CUSTOM_HPOS_ADJUST)
    {
        SET_OSD_HPOS(g_usAdjustValue0);         
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);   
    }
    else if(GET_OSD_STATE() == _OSD_OPTION_OSDPOS_CUSTOM_VPOS_ADJUST)
    {      
        SET_OSD_VPOS(g_usAdjustValue1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);   
    }
*/    
    else if(GET_OSD_STATE() == _OSD_OPTION_ACCESSIBILITY_BUTTON_OFF)
    {      
        SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_OFF);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG); 
    }
    else if(GET_OSD_STATE() == _OSD_OPTION_ACCESSIBILITY_BUTTON_DEFAULT)
    {      
        SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_DEFAULT);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG); 
    }
    else if(GET_OSD_STATE() == _OSD_OPTION_ACCESSIBILITY_BUTTON_SLOW)
    {      
        SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_SLOW);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG); 
    }
    else if(GET_OSD_STATE() == _OSD_OPTION_ACCESSIBILITY_MENU_TIMEOUT_ADJUST)
    {      
        SET_OSD_TIME_OUT(g_usAdjustValue0);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);   
    }
}
#endif//#if(_OSD_TYPE == _LEONVO_GREEN_OSD)
