
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
// ID Code      : UserOSD.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSD__

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
StructOsdInfo g_stOsdInfo = {0};

WORD g_usBeforeValue = 0;
WORD g_usAdjustValue_1 = 0;
WORD g_usAdjustValue_2 = 0;
WORD g_usAdjustValue_3 = 0;
WORD g_usAdjustValue_4 = 0;

BYTE ucBurnInPattern;
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserOsdHandler(void);
void OsdSystemFlowProc(void);
void OsdEventMsgProc(void);

code void (*OperationTable[][5])(void);

void OsdTimeoutSaveData(void);

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
    OsdSystemFlowProc();     //OSD(依據Power & Mode狀態)處理
    OsdEventMsgProc();       //OSD動作事件處理
}

//--------------------------------------------------
// Description  : OSD system flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
//OSD(依據Power & Mode狀態)處理
void OsdSystemFlowProc(void)
{

    switch(SysModeGetModeState())       //目前Mode狀態
    {
        case _MODE_STATUS_POWER_OFF:

            if(SysModeGetModeStateChange() == _TRUE)   //Power OFF(Mode)State轉態第一次
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SET_OSD_INPUT_FLAG(_ON);
                SET_PREVIOUS_INPUT_PORT(UserCommonNVRamGetSystemData(_SEARCH_PORT));
#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
                SET_FACTORY_MODE(_OFF);
                SET_FACTORY_BURNIN(_OFF);
                NVRamSaveFactoryDate();
                SET_ENERGY_MODE(_OFF);
#elif(_FACTORY_MODE_OWNER == _OWNER_WISTRON) 
                SET_FACTORY_MODE(_OFF);
                SET_OSD_IN_FACTORY_MENU_STATUS(_OFF);
        		if(GET_ATE_COMMAND_STATUS())
        		{
        			NVRamLoadFactoryData();
        			if(GET_EDID_VERSIONCODE()==_EDID_VERSION_CODE)
        			{
        	            CLR_ATE_COMMAND_STATUS();//FOR ATE MODE
        	            NVRamSaveFactoryData();
        			}
                    UserInterfaceKeyPadLedControl(_LED_POWER_OFF);
        		}
#endif
            }
            
            break;        
            
        case _MODE_STATUS_INITIAL:

            if(SysModeGetModeStateChange() == _TRUE)   //Initial(Mode)State轉態第一次
            {                        
                
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
                TPVDFMInternalADCCheck(); //DFM rev05 patch note 2(自動AutoColor校正)
#endif
#if((_FACTORY_MODE_OWNER == _OWNER_WISTRON)&&(_ADC_SELF_CALIBRATION == _ON))//ym20141013 . 
                if(GET_INTERNAL_AUTOCOLOR() == _FAIL)
                {
                    WISTRONFactoryAutoDoWhiteBalance();//ym20130924 . free run mode DoWhiteBalance for Lear(Lear Lee/WZS/Wistron) require 
                }
#endif

#if (_FACTORY_MODE_OWNER == _OWNER_TPV)//DFM
				if(TPVDFMLogoOnCheck()==_TRUE)
#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502			
				if((!GET_FACTORY_MODE()) && (GET_FACTORY_LOGO_ON_OFF()))
#endif			
                {
                    OsdDisplayShowLogo();                                                        //顯示Logo
                    ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO); //2秒後Logo OFF
                }   
				SET_PREVIOUS_INPUT_PORT(UserCommonNVRamGetSystemData(_SEARCH_PORT));
            }
            
            
#if(_OSD_3D_FUNCTION == _ON)        
//            ScalerOsdFrameControlAllByte(0x250, _OSD_WITHOUT_DB, 0x00, 0x03, 0x00); //window0
//            ScalerOsdFrameControlAllByte(0x254, _OSD_WITHOUT_DB, 0x00, 0x03, 0x00); //window1
//            ScalerOsdFrameControlAllByte(0x25C, _OSD_WITHOUT_DB, 0x00, 0x0f, 0x00); //window3
//            ScalerOsdFrameControlAllByte(0x264, _OSD_WITHOUT_DB, 0x00, 0x0f, 0x00); //window5//select Item
//            ScalerOsdFrameControlAllByte(0x268, _OSD_WITHOUT_DB, 0x00, 0x0a, 0x00); //window6//select ICon            

#if(_2D_TO_3D_FUNCTION == _OFF)
            if(GET_OSD_3D_STATUS() == _3D_2D_TO_3D)
            {
                SET_OSD_3D_STATUS(_3D_OFF);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            }
#endif

#endif
            break; 
            
        case _MODE_STATUS_SEARCH:
            
            if(SysModeGetModeStateChange()== _TRUE)                //Search(Mode)State轉態第一次 
            {
                UserInterfaceKeyPadLedControl(_LED_POWER_SEARCH);  //LED控制(Search State)
                
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
                if(((GET_A0_CABLE_STATUS() == _FALSE) && (GET_D0_CABLE_STATUS() == _FALSE) && (GET_D1_CABLE_STATUS() == _FALSE))&&(GET_ATE_COMMAND_STATUS()))
                    WISTRONFactoryAdjustBurnInPattern();
#endif
            }
			
            if((SysSourceGetInputPort() != GET_PREVIOUS_INPUT_PORT_STATUS()) && (GET_OSD_INPUT_FLAG() == _OFF) && (GET_FACTORY_BURNIN() == _OFF))                 
            {
                SET_OSD_INPUT_FLAG(_ON);
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

#if(_AUTO_POWER_DOWN == _ON)           
                 g_usDisPlayCunt = 0;  
                 //ScalerDebugMessage("@@START", 0x00);
#endif
				
				SET_PREVIOUS_INPUT_PORT(SysSourceGetInputPort());
        	}
            break;
            
        case _MODE_STATUS_ACTIVE:
            if(SysModeGetModeStateChange()== _TRUE)                 //Active(Mode)State轉態第一次     
            {
				DebugMessageOsd("1.---_MODE_STATUS_ACTIVE", 0);
                UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);   //LED控制(ACTIVE State)                
            }

#if((_FACTORY_MODE_OWNER == _OWNER_FOXCONN) || (_FACTORY_MODE_OWNER == _OWNER_TPV))//lorimiao 20150122
            PCB_USB_POWER(_USB_POWER_ON);
#endif

			if(GET_FAIL_SAFE_MODE())//lorimiao 20130730 for OOR issue
			{
				break;
			}

#if (_ENERGY_STAR_SUPPORT == _ON)
			if(GET_OSD_ES_STATUS() == _ON)
				{
				UserCommonAdjustESDcrAdjust();  
				}
#endif

#if(_DCR_SUPPORT == _ON)//Eli 20140909
			if(GET_OSD_DCR_STATUS() == _ON)
            {
                UserAdjustDCRMeasure();          //DCR動態調整亮度(隨時在做)
            }
#endif


#if(_AUTO_POWER_DOWN == _ON)
			if(GET_FACTORY_AUTO_POWER_DOWN_STAUTS() == _ON)
			{
	            if(g_usDisPlayCunt > 1416000 )    //Count1次 10ms(3小時58分=14280s)
	            {
	                 //ScalerDebugMessage("@@Show", 0x11);
	                 OsdDisplayOSDAutoPowerDown();
				     ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_POWER_DOWN_COUNT);  //兩分鐘後關畫面
	                 g_usDisPlayCunt = 0; 
	            }
			}
#endif


#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
#if(_SHOW_KEY_MESSAGE == _ON)
            if(GET_ATE_COMMAND_STATUS()&&GET_KEYTEST_STATUS())//&&(GET_KEYMESSAGE() != _NONE_KEY_MESSAGE))
            {
                OsdShowKeyMessage();  
                return;
            }
#endif
#endif

            //Key & OSD處理
		    if(GET_KEYMESSAGE() < _KEY_AMOUNT)                                  //判斷KEY有按下
		    {//lorimiao 20130729 for OSD lock issue
		    	if((GET_OSD_STATE() == _MENU_NONE) && (ScalerOsdGetOsdEnable() == _TRUE))
		    	{	
		    		OsdDisplayDisableOsd();		    		
		    	}
				else if(GET_OSD_LOCK_STATUS() == _ON)
				{            
                    if(ScalerOsdGetOsdEnable() == _TRUE)
                    {
                        OsdDisplayDisableOsd();	
                    }
                    else
                    {
    					OsdDisplayOSDLockProc();
    					ScalerTimerReactiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_DISABLE);
                    }                    
				}
                else if(GET_OSD_IN_FACTORY_MENU_STATUS() == _TRUE)                    //判斷工廠OSD選項
                {
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
                    //Robert Wang 20121210 TPVFactoryMenuOperation();                                   //工廠模式OSD處理
                    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
                    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_TOUCH_LED_OFF); 
#endif                                    
                }
                else
                {
		            (*OperationTable[GET_OSD_STATE()][GET_KEYMESSAGE()])();       //OSD顯示處理

                    //20120614 Abel "F" OSD Modify
                    if(GET_FACTORY_MODE()==_TRUE)                          //判斷目前是否為工廠OSD模式
                    {    
                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_TOUCH_LED_OFF);                        
                    }
                    else
                    {
                        ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
                    }                       
                }     				
		    }
            
            break;
            
        case _MODE_STATUS_NOSUPPORT:

            if(SysModeGetModeStateChange()== _TRUE)                        //No Support(Mode)State轉態第一次  
            {
				DebugMessageOsd("1.---_MODE_STATUS_NOSUPPORT", 0);
                //SET_OSD_INPUT_FLAG(_ON);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSUPPORT_MSG);
                UserInterfaceKeyPadLedControl(_LED_POWER_NOSUPPORT);       //LED控制(No Support State)  
            }

            break;
            
        case _MODE_STATUS_NOSIGNAL:

            if(SysModeGetModeStateChange()== _TRUE)                         //No Signal(Mode)State轉態第一次   
            {
				DebugMessageOsd("1.---_MODE_STATUS_NOSIGNAL", 0);
				
                SET_PREVIOUS_INPUT_PORT(UserCommonNVRamGetSystemData(_SEARCH_PORT));   
                //SET_OSD_INPUT_FLAG(_ON);
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
				if(TPVDFMCableWPCheck()==_TRUE)//DFM rev02 patch note 7
					return;
#endif
#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
				// lorimiao 20130904 for DDCCI switch to VGA port for run factory mommand
		#if(_DDCCI_AUTO_SWITCH_SUPPORT == _OFF)
                if(GET_FACTORY_MODE() == _TRUE)
                {
                    ScalerMcuDdcciSwitchPort(_DDCCI_MODE, _A0_INPUT_PORT);
                }
		#endif
			    if((_FALSE == SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT)))&&(_ON == GET_FACTORY_MODE()))
			    {   
			        ucLcdConditionPattern=0;
			        FactoryBurnInPattern();
			    }
			    else
#endif
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
                if(((GET_A0_CABLE_STATUS() == _FALSE) && (GET_D0_CABLE_STATUS() == _FALSE) && (GET_D1_CABLE_STATUS() == _FALSE))&&(GET_ATE_COMMAND_STATUS()))
                {
                    //ym20141120 . WISTRONFactoryAdjustBurnInPattern();
			    }
			    else
#endif
                {
					//jason.cheng 20141030_4 modify for show no signal & no cable issue 
                    //if(SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT))) 
                    if((SysSourceGetCableDetect(_A0_INPUT_PORT) == _TRUE) || (SysSourceGetCableDetect(_D0_INPUT_PORT) == _TRUE) || (SysSourceGetCableDetect(_D1_INPUT_PORT) == _TRUE))
                    {
                        ScalerTimerActiveTimerEvent(SEC(0.01), _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);   //2秒後顯示No Signal
			            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);
                    }
                    else
                    {
                        ScalerTimerActiveTimerEvent(SEC(0.01), _USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);    //2秒後顯示No Cable
						ScalerTimerActiveTimerEvent(SEC(20), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);
                    }
                }    
            }

            break;
            
        case _MODE_STATUS_POWER_SAVING:
				DebugMessageOsd("1.---_MODE_STATUS_POWER_SAVING", 0);
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
    		SET_OSD_INPUT_FLAG(_ON);
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

#if((_FACTORY_MODE_OWNER == _OWNER_FOXCONN) || (_FACTORY_MODE_OWNER == _OWNER_TPV))
            if(PCB_USB_DETECT() == _FALSE)
            {
                PCB_USB_POWER(_USB_POWER_OFF);
            }
            else
            {
                PCB_USB_POWER(_USB_POWER_ON);
            }

#if(_AUTO_POWER_DOWN == _ON)//lorimiao 20141225 for WakeUp Monitor
			if(GET_FACTORY_AUTO_POWER_DOWN_STAUTS() == _ON)
            {
				if(GET_KEYMESSAGE() < _KEY_AMOUNT) 
				{ 
					SET_FORCE_POW_SAV_STATUS(_FALSE); 
					SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH); 
					SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL); 
				} 
            }
#endif
#endif

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
void OsdEventMsgProc(void)
{
    switch(GET_OSD_EVENT_MESSAGE())
    {
        case _OSDEVENT_SHOW_NOSIGNAL_MSG:
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
			ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	//Ada.chen 20150526_1
#endif
            OsdDisplayPowerSavingProc();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);
			ScalerTimerActiveTimerEvent(SEC(0.2), _USER_TIMER_EVENT_OSD_FLYING);
            break;

        case _OSDEVENT_SHOW_NOCABLE_MSG: 
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
			ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	//Ada.chen 20150526_1
#endif
			OsdDisplayNoCableProc();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);
			ScalerTimerActiveTimerEvent(SEC(0.2), _USER_TIMER_EVENT_OSD_FLYING);
			break;

        case _OSDEVENT_SHOW_NOSUPPORT_MSG:
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)	
			ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	//Ada.chen 20150526_1
#endif
			OsdDisplayNoSupportProc();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);
			ucLedFlashCount = 0;//jason.cheng 20141114_2 add
			ScalerTimerActiveTimerEvent(SEC(0.2), _USER_TIMER_EVENT_OSD_FLYING);
			
			//>85hz and <50hz will go to ps after 2 min,
			if((GET_INPUT_TIMING_VFREQ() >= _OOR_V_FREQ_UPPER_BOUND) || (GET_INPUT_TIMING_VFREQ() <= _FAIL_SAVE_V_FREQ_LOWER_BOUND))
			{
				ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_FLY_OSD_TO_POWER_SAVING);                        
			}
            break;


        case _OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG:
 			ScalerTimerActiveTimerEvent(SEC(0.3), _USER_TIMER_EVENT_OSD_SHOW_NO_SUPPORT);	                    
            break;        

        case _OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG:

            OsdDisplayWakeUpShowSource();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);

            break;

        case _OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG:

            OsdDisplayWakeUpSwitchDdcciPort();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);

            break;

        case _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG:

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
			ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	//Ada.chen 20150526_1
#endif
            OsdDisplayPowerSavingProc();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);

            break;

        case _OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG:

            OsdDisplayDisableOsd();
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
            
            OsdDisplayAutoProc();
            
            break;
#endif

        case _OSDEVENT_ACTIVE_DO_ONE_TIME_MSG:
            
#if(_VGA_SUPPORT == _ON) 
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {
                if(UserInterfaceFirstAutoConfig() == _TRUE)
                {
                    OsdDisplayAutoProc();                    
                }
            } 
#endif

            if(GET_OSD_STATE() == _MENU_NONE)
            {
                OsdDisplayTimingAndInputSource();
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

        case _OSDEVENT_SAVE_NVRAM_FACTORYDATA_MSG:
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
            TPVNVRamSaveFactoryDate();              //儲存工廠Mode用的參數
#elif (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)       //lorimiao 0717
            NVRamSaveFactoryDate();
#endif            
            break;
            
    }

    SET_OSD_EVENT_MESSAGE(_OSDEVENT_NONE_MSG);
}

void OsdNull(void)
{
}


//-----------------------------------
//    Menu None
//-----------------------------------
//Menu Key
void OsdNoneMenu(void)
{
    BYTE tmp = 0;

    if(tmp)
    {
        //SysSourceSetScanType(_SOURCE_SWITCH_AUTO_WITHOUT_GROUP); 
        //SET_OSD_STATE(OsdDisplayDetOverRange(GET_OSD_STATE(), 100, 1, _ON));
        //OsdTableFuncPutStringPropCenter(ROW(0), COL(0), WIDTH(0), _PFONT_PAGE_0, tOSD_ITEM_BRI_CON_DCR_0, GET_OSD_LANGUAGE(), 0);
        //OsdFunc1bitByte0(ROW(ucTmpRow), COL(ucTmpCol), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
        OsdFuncBlank(ROW(4), COL(1), 0 , HEIGHT(1) , 0);
    }

    if(ScalerOsdGetOsdEnable() == _FALSE)    //判斷OSD是否顯示    
    {    
       if(GET_OSD_LOCK_STATUS()==_ON)        //判斷OSD Lock
       {
           OsdDisplayOSDLockProc();          //顯示OSD LOCK
       }  
       else
       {
           OsdDispMainMenu();               //顯示OSD Main主選單
       }   
    }
}

//Left Key(Auto)
void OsdNoneLeft(void)
{
    /*g_usAdjustValue_1 = GET_OSD_VOLUME();  
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, 100, 0 , _OFF);   
    SET_OSD_VOLUME(g_usAdjustValue_1);
    UserAdjustAudioVolume(GET_OSD_VOLUME());    
    */
    
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        //OsdDisplayAutoProc();          //Auto動作  
        OsdDisplayOsdMessage(_MSG_AUTO);
        UserCommonAutoConfig();
        SET_VGA_MODE_ADJUST_H_POSITION(50);
        SET_VGA_MODE_ADJUST_V_POSITION(50);
        //OsdDisplayDisableOsd();
        ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_OSD_DISABLE_AUTO_ADJUST_MSG);
    }    
}

//Right Key(Bri Adjust)
void OsdNoneRight(void)
{	
    if((GET_OSD_DCR_STATUS()==_ON) || 
#if(_OSD_LBL_ADJUST_FUNCTION == _OFF)
	(GET_COLOR_TEMP_TYPE() == _CT_SRGB)||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
#else
	((GET_COLOR_TEMP_TYPE() == _CT_SRGB)&&(GET_OSD_LBL_STATUS() == _OFF))
#endif
     )
      return;
    
    OsdFuncOsdBlending(_BLENDING_TYPE1);
    OsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());   

    OsdFuncApplyMap(_OSD_MAP0);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_0);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_1);

    //Win 2,3,4,8,9 higher than font
    ScalerOsdFrameControlByte(0x002, _OSD_BYTE1, 0x03);
    ScalerOsdFrameControlByte(0x002, _OSD_BYTE2, 0xE0);
    
    //==== Load font & icon & color palette=======      //載入字型檔
    OsdFontLoadFont(_FONT1_GLOBAL);
    OsdFontLoadFont(_FONT1_BUTTON_ICON);
    
    // Item 5 used Font 256-511    
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
    // Item 4 used Font 256-511    
    OsdFunc1bitByte0(ROW(_ITEM_4_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
    // Item 3 used Font 256-511    
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);

    // 1 layer back ground color
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_OSD_MAP0_Height - (_ITEM_3_ROW - 1)), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

   
    SET_OSD_STATE(_MAIN_BRI_CON_DCR);  
    
    if(SysSourceGetInputPort() != _A0_INPUT_PORT)
    {           
       OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
       OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_OPTIONS);
       OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS, _MAIN_BRI_CON_DCR);
       OsdDisplayItemDraw(_ICON_1_4, _ITEM_UNSELECT, _MAIN_IMAGE_POSITION);
       OsdDisplayItemDraw(_ICON_1_5, _ITEM_UNSELECT, _MAIN_IMAGE_SETUP);          
    }
    else
    {               
       OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
       OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_OPTIONS);
       OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS, _MAIN_BRI_CON_DCR);
       OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_IMAGE_POSITION);
       OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_IMAGE_SETUP);   
    }
	
#if(_USER_DCR_FUNCTION == _ON)	
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	if(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
	{
		SET_OSD_STATE(_SUB_BRI);
		OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_DCR);
		OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_BRI);
		OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_CON);
	}
	else
#endif
	{
    	SET_OSD_STATE(_SUB_BRI);  
	    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_DCR);       
	    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_BRI);       
	    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_CON); 
	}
#else
    SET_OSD_STATE(_SUB_BRI);  
	OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, _SUB_BRI);		
	OsdDisplayItemDraw(_ITEM_2_2, _ITEM_SELECT, _SUB_CON);	 
#endif

    SET_OSD_STATE(_HOTKEY_BAR_BRI);
    OsdDisplayDrawBar(_ITEM_3_ROW, GET_OSD_BACKLIGHT(), _Bar_0_100);
    g_usBeforeValue = GET_OSD_BACKLIGHT();               //BRI調整前值
    g_usAdjustValue_1 = GET_OSD_BACKLIGHT();
    
    //==== Button ======
    OsdFunc1bitByte0(ROW(17), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(3),_1BIT_FONT_256_511_WIDTH_12);
    OsdDisplayDispButton(_KEY_INFO_ALL);       //顯示提示OSD Button ICON(最後一列)

    OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncEnableOsd();
}

//Exit Key(Source Input)
void OsdNoneExit(void)
{

#if(_INPUT_PORT_MAX > 0x01)
   #if(_INPUT_PORT_MAX == 0x03)
    BYTE ucItem_3_1, ucItem_3_2, ucItem_3_3;
   #endif
    if(SysModeGetModeState()==_MODE_STATUS_ACTIVE)   
    {
        OsdFuncOsdBlending(_BLENDING_TYPE1);
        OsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());   

        OsdFuncApplyMap(_OSD_MAP0);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_0);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_1);

        //Win 2,3,4,8,9 higher than font
        ScalerOsdFrameControlByte(0x002, _OSD_BYTE1, 0x03);
        ScalerOsdFrameControlByte(0x002, _OSD_BYTE2, 0xE0);
        
        //==== Load font & icon & color palette=======      //載入字型檔
        OsdFontLoadFont(_FONT1_GLOBAL);
        OsdFontLoadFont(_FONT1_BUTTON_ICON);
        
        // Item 5 used Font 256-511    
        OsdFunc1bitByte0(ROW(_ITEM_5_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
        // Item 4 used Font 256-511    
        OsdFunc1bitByte0(ROW(_ITEM_4_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
        // Item 3 used Font 256-511    
        OsdFunc1bitByte0(ROW(_ITEM_3_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
        
        // 1 layer back ground color
        OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_OSD_MAP0_Height - (_ITEM_3_ROW - 1)), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
       
        SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);  

        if(SysSourceGetInputPort() != _A0_INPUT_PORT)
        {                        
            OsdDisplayItemDraw(_ICON_1_1, _ITEM_UNSELECT, _MAIN_IMAGE_POSITION);
            OsdDisplayItemDraw(_ICON_1_2, _ITEM_UNSELECT, _MAIN_IMAGE_SETUP);
            OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS, _MAIN_IMAGE_PROPERTIES);
            OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_OPTIONS);
        }
        else
        {
            OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_IMAGE_POSITION);
            OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_IMAGE_SETUP);
            OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS, _MAIN_IMAGE_PROPERTIES);
            OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_OPTIONS);
        }  

        if((GET_COLOR_TEMP_TYPE() == _CT_SRGB)
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
         ||(GET_OSD_LOW_BLUE_LIGHT_STATUS()== _ON)
#endif            
        )
            OsdDisplayItemDraw(_ICON_1_5, _ITEM_UNSELECT, _MAIN_BRI_CON_DCR);             
        else
            OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_BRI_CON_DCR); 

        
#if((_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
			SET_OSD_STATE(_SUB_INPUT_SIGNAL);	
			OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, _SUB_INPUT_SIGNAL);	
#if((_USER_DCR_FUNCTION == _ON)||(_LOW_BLUE_LIGHT_FUNCTION == _ON))
			if((GET_OSD_DCR_STATUS() == _ON) 
        #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)                
            || (GET_OSD_LOW_BLUE_LIGHT_STATUS()== _ON)
        #endif            
            )
			{	
				 OsdDisplayItemDraw(_ITEM_2_2, _ITEM_UNSELECT, _SUB_COLOR);
			}
			else
#endif
			{
				OsdDisplayItemDraw(_ITEM_2_2, _ITEM_SELECT, _SUB_COLOR); 		
			}
#else

#if((_USER_DCR_FUNCTION == _ON)||(_LOW_BLUE_LIGHT_FUNCTION == _ON))
		if((GET_OSD_DCR_STATUS() == _ON) 
    #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)                
        || (GET_OSD_LOW_BLUE_LIGHT_STATUS()== _ON)
    #endif
	    )            
        {   
             OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_COLOR);
        }
        else
#endif
        {
            OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_COLOR);            
        }
        OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_INPUT_SIGNAL);
        if(UserCheckAspectRatioFunction() == _TRUE)
        {
            OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_SCALING);  
        }   
        else
        {
            OsdDisplayItemDraw(_ITEM_2_3, _ITEM_UNSELECT, _SUB_SCALING);  
        } 
#endif        
  #if(_INPUT_PORT_MAX == 0x02)

      {
        if(SysSourceGetInputPort()== _A0_INPUT_PORT)
        {
            SET_OSD_STATE(_SUB_INPUT_ANALOG);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_INPUT_ANALOG);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_INPUT_DIGITAL1);           
        }    
        else
        {
            SET_OSD_STATE(_SUB_INPUT_DIGITAL1);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_INPUT_DIGITAL1);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_INPUT_ANALOG);
        }   
    }        
  #else // #if(_INPUT_PORT_MAX == 0x03)
        switch(SysSourceGetInputPort())
        {
            case _A0_INPUT_PORT:
                SET_OSD_STATE(_SUB_INPUT_ANALOG);
                ucItem_3_1 = _SUB_INPUT_DIGITAL1;
                ucItem_3_2 = _SUB_INPUT_ANALOG;
                ucItem_3_3 = _SUB_INPUT_DIGITAL0;
                break;
                    
            case _D0_INPUT_PORT:
                SET_OSD_STATE(_SUB_INPUT_DIGITAL0);
                ucItem_3_1 = _SUB_INPUT_ANALOG;
                ucItem_3_2 = _SUB_INPUT_DIGITAL0;
                ucItem_3_3 = _SUB_INPUT_DIGITAL1;               
                break;
                    
            case _D1_INPUT_PORT:
                SET_OSD_STATE(_SUB_INPUT_DIGITAL1);
                ucItem_3_1 = _SUB_INPUT_DIGITAL0;
                ucItem_3_2 = _SUB_INPUT_DIGITAL1;
                ucItem_3_3 = _SUB_INPUT_ANALOG;                               
                break;

            default:
                break;
        }
        OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, ucItem_3_1);
        OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, ucItem_3_2);
        OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, ucItem_3_3);
#endif
        //==== Button ======
        OsdFunc1bitByte0(ROW(17), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(3),_1BIT_FONT_256_511_WIDTH_12);
        OsdDisplayDispButton(_KEY_INFO_ALL);       //顯示提示OSD Button ICON(最後一列)

        OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());

        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdFuncEnableOsd();
    }    
#endif
}

//Source Key
void OsdNoneSource(void)
{
	
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
			break;

		default:
			break;
	}
}

//====================================================================================================
//                                   第一層進入第二層
//====================================================================================================
//----------------------------------------------------------------------------------------------
//Select Item:1.Bri/Con/DCR 2.ImagePostion 3.ImageSetup 4.ImageProperties 5.Options 6.Factory
//----------------------------------------------------------------------------------------------
//Menu Key(進入第二層)
void OsdMainItemK1(void)
{
    // 2 layer back ground color
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

    //依據第一層Item目錄畫第二層
    if(GET_OSD_STATE() == _MAIN_BRI_CON_DCR)
    {
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION == _ON))
		if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
		{
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
			if(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
			{
				SET_OSD_STATE(_SUB_BRI);
				OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_DCR);
				OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_BRI);
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_CON);
			}
			else
#endif
			{
				SET_OSD_STATE(_SUB_DCR);
				OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_CON);
				OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_DCR);
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_UNSELECT, _SUB_BRI);
			}
		}
		else
#endif
		{

			if(GET_OSD_DCR_STATUS()==_ON)
			{
				SET_OSD_STATE(_SUB_DCR);
				OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_CON);
				OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_DCR);
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_UNSELECT, _SUB_BRI);
			}
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION == _ON))
			else if(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
			{
				SET_OSD_STATE(_SUB_BRI);
				OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_DCR);
				OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_BRI);
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_CON);
			}
#endif
			else
			{
				SET_OSD_STATE(_SUB_BRI);
				OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_DCR);
				OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_BRI);
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_CON);
			}
		}

    }
    else if(GET_OSD_STATE() == _MAIN_IMAGE_POSITION)
    {
        SET_OSD_STATE(_SUB_IMAGE_POS_H);
        OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, _SUB_IMAGE_POS_H);
        OsdDisplayItemDraw(_ITEM_2_2, _ITEM_SELECT, _SUB_IMAGE_POS_V);
    }
    else if(GET_OSD_STATE() == _MAIN_IMAGE_SETUP)
    {
        SET_OSD_STATE(_SUB_AUTO_SETUP);
        OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, _SUB_AUTO_SETUP);
        OsdDisplayItemDraw(_ITEM_2_2, _ITEM_SELECT, _SUB_MANUAL);
    }
    else if(GET_OSD_STATE() == _MAIN_IMAGE_PROPERTIES)
    {
	  #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
        if((GET_OSD_DCR_STATUS() == _ON)||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON))   //DCR ON Color不可選
      #else
        if(GET_OSD_DCR_STATUS() == _ON)   //DCR ON Color不可選
      #endif        
        {
#if(_INPUT_PORT_MAX > 0x01)
			SET_OSD_STATE(_SUB_INPUT_SIGNAL);
	#if((_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
			OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, _SUB_INPUT_SIGNAL);
			OsdDisplayItemDraw(_ITEM_2_2, _ITEM_UNSELECT, _SUB_COLOR);
	#else
			OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_COLOR);
			OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_INPUT_SIGNAL);
		#if(_ASPECT_RATIO_SUPPORT == _ON)
			if(UserCheckAspectRatioFunction() == _TRUE)
			{
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_SCALING);
			}	 
			else
			{
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_UNSELECT, _SUB_SCALING);
			}  
		#else
			OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_OVER_DRIVE);
		#endif
	#endif
#else
	#if((_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON))
			if(UserCheckAspectRatioFunction() == _TRUE)
			{
				SET_OSD_STATE(_SUB_SCALING);
				OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_COLOR);
				OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_SCALING);
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_OVER_DRIVE);		
			}	 
			else
			{
				SET_OSD_STATE(_SUB_OVER_DRIVE);
				OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_COLOR);
				OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_OVER_DRIVE);
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_UNSELECT, _SUB_SCALING);		
			}
	#else
		#if((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON))
			#if(_OD_OSD_SUPPORT == _ON)
			SET_OSD_STATE(_SUB_OVER_DRIVE);
			OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, _SUB_OVER_DRIVE);				
			OsdDisplayItemDraw(_ITEM_2_2, _ITEM_UNSELECT, _SUB_COLOR);
			#else
			if(UserCheckAspectRatioFunction() == _TRUE)
			{
                SET_OSD_STATE(_SUB_SCALING);
                #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_COLOR);
                OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_SCALING);
                OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_LOW_BLUE_LIGHT);
                #else
				OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, _SUB_SCALING);
                OsdDisplayItemDraw(_ITEM_2_2, _ITEM_UNSELECT, _SUB_COLOR);
                #endif
			}	 
			else
			{			
                #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT);
                OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_SCALING);
                OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_LOW_BLUE_LIGHT);
                OsdDisplayItemDraw(_ITEM_2_3, _ITEM_UNSELECT, _SUB_COLOR);
                #else
				SET_OSD_STATE(_SUB_SCALING);
				OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_SCALING);
                OsdDisplayItemDraw(_ITEM_2_2, _ITEM_UNSELECT, _SUB_COLOR);
                #endif
			}
			
			#endif
		#else
	 		#warning "Please Check _MAIN_IMAGE_PROPERTIES page !!"
		#endif
	#endif
#endif
        }
        else
        {
            SET_OSD_STATE(_SUB_COLOR);
#if(_INPUT_PORT_MAX > 0x01)
	#if((_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
			OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, _SUB_COLOR);
			OsdDisplayItemDraw(_ITEM_2_2, _ITEM_SELECT, _SUB_INPUT_SIGNAL);
	#else
		#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
            OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_LOW_BLUE_LIGHT);
		#elif(_OD_OSD_SUPPORT == _ON)
			OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_OVER_DRIVE);
		#else
            if(UserCheckAspectRatioFunction() == _TRUE)
            {
                OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_SCALING);
            }    
            else
            {
                OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_SCALING);    
            }    
		#endif
			OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_COLOR);
			OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_INPUT_SIGNAL);
	#endif	
#else
	#if((_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON))
	
		#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
			OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_LOW_BLUE_LIGHT);
		#else
			OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_OVER_DRIVE);
		#endif
			OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_COLOR);
			if(UserCheckAspectRatioFunction() == _TRUE)
			{
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_SCALING);
			}	 
			else
			{
				OsdDisplayItemDraw(_ITEM_2_3, _ITEM_UNSELECT, _SUB_SCALING);	
			}	 
	#else
		#if((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON))
            #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
            OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_LOW_BLUE_LIGHT);
            OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_COLOR);
            #else
            OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, _SUB_COLOR);
            #endif
            #if(_OD_OSD_SUPPORT == _ON)
            OsdDisplayItemDraw(_ITEM_2_2, _ITEM_SELECT, _SUB_OVER_DRIVE);
            #else
            #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
            if(UserCheckAspectRatioFunction() == _TRUE)
            {
                OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_SCALING);
            }    
            else
            {
                OsdDisplayItemDraw(_ITEM_2_3, _ITEM_UNSELECT, _SUB_SCALING);    
            }    
            #else
            if(UserCheckAspectRatioFunction() == _TRUE)
            {
                OsdDisplayItemDraw(_ITEM_2_2, _ITEM_SELECT, _SUB_SCALING);
            }    
            else
            {
                OsdDisplayItemDraw(_ITEM_2_2, _ITEM_UNSELECT, _SUB_SCALING);    
            }    
            #endif
            #endif
		#endif
		
	#endif
#endif
        }        
    }
    else if(GET_OSD_STATE() == _MAIN_OPTIONS)
    {
        SET_OSD_STATE(_SUB_INFORMATION);
#if (_DP_SUPPORT == _ON)
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
		if(SysSourceGetInputPort() == _D0_INPUT_PORT)	// DP Port(D1) 
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        if(SysSourceGetInputPort() == _D1_INPUT_PORT)   // DP Port(D1) 
#endif
        {           
            OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_DP_SELECT);
        }
        else
        {
            OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_DP_SELECT);
        }    
#else
        OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_ACCESSIBILITY);
#endif
        OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_INFORMATION);
#if(_LANGUAGE_TYPE != _1_LAN)
        OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_MENU_LANGUAGE);
#else
		OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_MENU_POSITION);

#endif
    }
    else if(GET_OSD_STATE() == _MAIN_FACTORY)
    {
        SET_OSD_STATE(_ADJ_FACTORY);
        ucFactoryOsdState = MENU_FACTORY_START;
        TPVFactoryMenuPro();
        return;
    }
      
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_CANCEL);  
}

//Left Key動作(第一層Item旋轉)
void OsdMainItemK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
}

//Right Key(第一層Item旋轉)
void OsdMainItemK3(void)
{
    OsdMainItemK2();
}

//Exit Key(離開OSD)
void OsdMainItemK4(void)
{
    SET_Key_Relax_FLAG();
    OsdDisplayDisableOsd();
}

//====================================================================================================
//                                   第二層進入第三層
//====================================================================================================
//20140901 Abel Modify
//------------------------------------------------------------
// (Bri/Con/DCR)Select Item:1.Brightness 2.Contrast 3.DCR	
//------------------------------------------------------------
//Menu Key(進入第三層)
void OsdSubBriConDcrItemK1(void)
{
    // 3 layer back ground color
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

    //依據第二層Item目錄畫第三層
    if(GET_OSD_STATE() == _SUB_BRI)
    {
        SET_OSD_STATE(_BAR_BRI);
        OsdDisplayDrawBar(_ITEM_3_ROW, GET_OSD_BACKLIGHT(), _Bar_0_100);
        g_usBeforeValue = GET_OSD_BACKLIGHT();               //BRI調整前值
        g_usAdjustValue_1 = GET_OSD_BACKLIGHT();
    }
    else if(GET_OSD_STATE() == _SUB_CON)
    {
        SET_OSD_STATE(_BAR_CON);
        OsdDisplayDrawBar(_ITEM_3_ROW, GET_OSD_CONTRAST(), _Bar_0_100);
        g_usBeforeValue = GET_OSD_CONTRAST();                //CON調整前值
        g_usAdjustValue_1 = GET_OSD_CONTRAST();
    }
#if(_USER_DCR_FUNCTION == _ON)
	
    else if(GET_OSD_STATE() == _SUB_DCR)
    {
        if(GET_OSD_DCR_STATUS() == _ON)
        {
            SET_OSD_STATE(_SUB_DCR_ON);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_DCR_ON);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_DCR_OFF);
        }
        else
        {
            SET_OSD_STATE(_SUB_DCR_OFF);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_DCR_OFF);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_DCR_ON);
        }
    }
#endif
}

//Left Key(第二層Item旋轉)
void OsdSubBriConDcrItemK2(void)
{
#if(_USER_DCR_FUNCTION == _ON)
    if(((GET_OSD_DCR_STATUS()==_OFF) &&(GET_COLOR_TEMP_TYPE() != _CT_SRGB))
   #if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION == _OFF))
     &&(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF)
   #endif
     )
#endif
    {
        OsdAnimationItemAnimation(GET_OSD_STATE());
    }    
}
 
//Right Key(第二層Item旋轉)
void OsdSubBriConDcrItemK3(void)
{
    OsdSubBriConDcrItemK2();
}

//Exit Key(離開OSD)
void OsdSubBriConDcrItemK4(void)
{
#if(_USER_DCR_FUNCTION == _ON)    
    SET_Key_Relax_FLAG();
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdDisplayWaitForDrawing();

	OsdDisplayClearFocusFrame(_ITEM_2_ROW); // 3ms
   
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BLACK), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    
    SET_OSD_STATE(_MAIN_BRI_CON_DCR);
//    OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
//    OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_OPTIONS);
//    OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS,  _MAIN_BRI_CON_DCR);
//    OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_IMAGE_POSITION);
//    OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_IMAGE_SETUP);
    
    OsdDisplayMainMenuDescription(GET_OSD_STATE()); // 108ms
    
    OsdDisplayDispButton(_KEY_INFO_EXIT);
#else
    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_BRI_CON_DCR);
//    OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_OPTIONS);
//    OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
//    OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS,  _MAIN_IMAGE_POSITION);
//    OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_IMAGE_SETUP);
//    OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);

    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);

#endif
}


//====================================================================================================
//--------------------------------------------------------------------
//  (ImagePostion)Select Item:1.(VGA)H Postion 2.(VGA)V Postion	
//--------------------------------------------------------------------
//Menu Key(進入第三層)
void OsdSubHVPosItemK1(void)
{
    // 3 layer back ground color
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

    //依據第二層Item目錄畫第三層
    if(GET_OSD_STATE() == _SUB_IMAGE_POS_H)
    {
        SET_OSD_STATE(_BAR_H_POSITION);
        OsdDisplayDrawBar(_ITEM_3_ROW, GET_VGA_MODE_ADJUST_H_POSITION(), _Bar_0_100);
        g_usBeforeValue = GET_VGA_MODE_ADJUST_H_POSITION();               //畫面H調整前值
        g_usAdjustValue_1 = GET_VGA_MODE_ADJUST_H_POSITION();        
    }
    else if(GET_OSD_STATE() == _SUB_IMAGE_POS_V)
    {
        SET_OSD_STATE(_BAR_V_POSITION);
        OsdDisplayDrawBar(_ITEM_3_ROW, GET_VGA_MODE_ADJUST_V_POSITION(), _Bar_0_100);
        g_usBeforeValue = GET_VGA_MODE_ADJUST_V_POSITION();               //畫面V調整前值
        g_usAdjustValue_1 = GET_VGA_MODE_ADJUST_V_POSITION();        
    }
}

//Left Key(第二層Item旋轉)
void OsdSubHVPosItemK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第二層Item旋轉)
void OsdSubHVPosItemK3(void)
{
    OsdSubHVPosItemK2();
}

//Exit Key(離開OSD)
void OsdSubHVPosItemK4(void)
{
    SET_Key_Relax_FLAG();
    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_IMAGE_POSITION);
//    OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_OPTIONS);
//    OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
//    OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS,  _MAIN_IMAGE_POSITION);
//    OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_IMAGE_SETUP);
//    OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);

    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
}

//-----------------------------------------------------------------
//  (ImageSetup)Select Item:1.(VGA)Automatic 2.(VGA)Manual	
//-----------------------------------------------------------------
//Menu Key(進入第三層)
void OsdSubAutoManualItemK1(void)
{
    //依據第二層Item目錄畫第三層
    if(GET_OSD_STATE() == _SUB_AUTO_SETUP)
    {        
        OsdDisplayAutoProc();                     //Auto動作        
        SET_Key_Relax_FLAG();                     //清除OSD   

       OsdFuncOsdBlending(_BLENDING_TYPE1);
       OsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());   

       OsdFuncApplyMap(_OSD_MAP0);
       OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_0);
       OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_1);

       //Win 2,3,4,8,9 higher than font
       ScalerOsdFrameControlByte(0x002, _OSD_BYTE1, 0x03);
       ScalerOsdFrameControlByte(0x002, _OSD_BYTE2, 0xE0);
    
       //==== Load font & icon & color palette=======      //載入字型檔
       OsdFontLoadFont(_FONT1_GLOBAL);
       OsdFontLoadFont(_FONT1_BUTTON_ICON);
    
       // Item 5 used Font 256-511    
       OsdFunc1bitByte0(ROW(_ITEM_5_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
       // Item 4 used Font 256-511    
       OsdFunc1bitByte0(ROW(_ITEM_4_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
       // Item 3 used Font 256-511    
       OsdFunc1bitByte0(ROW(_ITEM_3_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);

       // 1 layer back ground color
       OsdFunc1bitColor(ROW(_ITEM_1_ROW - 1), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_OSD_MAP0_Height - (_ITEM_1_ROW - 1)), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

       SET_OSD_STATE(_MAIN_IMAGE_SETUP);
       if((GET_COLOR_TEMP_TYPE() == _CT_SRGB)
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
         ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
 #endif
       )
         OsdDisplayItemDraw(_ICON_1_1, _ITEM_UNSELECT, _MAIN_BRI_CON_DCR);
       else
         OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
       OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_IMAGE_POSITION);
       OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS,  _MAIN_IMAGE_SETUP);
       OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
       OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_OPTIONS);
        
       //==== Description ======
       OsdDisplayMainMenuDescription(GET_OSD_STATE());

       //==== Button ======
       OsdFunc1bitByte0(ROW(17), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(3),_1BIT_FONT_256_511_WIDTH_12);
       OsdDisplayDispButton(_KEY_INFO_ALL);       //顯示提示OSD Button ICON(最後一列)

       OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());

       ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
       OsdFuncEnableOsd();
        
    }
    else if(GET_OSD_STATE() == _SUB_MANUAL)
    {
        // 3 layer back ground color
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

        SET_OSD_STATE(_SUB_MANUAL_CLOCK);
        OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_MANUAL_CLOCK);
        OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_MANUAL_PHASE);
    }
}

//Left Key(第二層Item旋轉)
void OsdSubAutoManualItemK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第二層Item旋轉)
void OsdSubAutoManualItemK3(void)
{
    OsdSubAutoManualItemK2();
}

//Exit Key(離開OSD)
void OsdSubAutoManualItemK4(void)
{
    SET_Key_Relax_FLAG();
    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_IMAGE_SETUP);
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
}

//----------------------------------------------------------------------
//  (Image Properties)Select Item:1.Color 2.Input Signal 3.Scaling	4.OD
//----------------------------------------------------------------------
//Menu Key(進入第三層)
void OsdSubColorInputScalingItemK1(void)
{

//#if(_INPUT_PORT_MAX > 0x01)
#if(_INPUT_PORT_MAX == 0x03)

    BYTE ucItem_3_1, ucItem_3_2, ucItem_3_3;
#endif

    // 3 layer back ground color
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

    //依據第二層Item目錄畫第三層
    if(GET_OSD_STATE() == _SUB_COLOR)
    {
        if(GET_COLOR_TEMP_TYPE()== _CT_USER)
        {
            SET_OSD_STATE(_SUB_COLOR_CUSTOM);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_COLOR_CUSTOM);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_COLOR_PRESET_MODE);           
        }    
        else
        {
            SET_OSD_STATE(_SUB_COLOR_PRESET_MODE);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_COLOR_PRESET_MODE);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_COLOR_CUSTOM);
        }   
    }
#if(_INPUT_PORT_MAX > 0x01)
    else if(GET_OSD_STATE() == _SUB_INPUT_SIGNAL)
    {
  #if (_INPUT_PORT_MAX == 0x02)

        if(SysSourceGetInputPort()== _A0_INPUT_PORT)
        {
            SET_OSD_STATE(_SUB_INPUT_ANALOG);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_INPUT_ANALOG);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_INPUT_DIGITAL1);           
        }    
        else
        {
            SET_OSD_STATE(_SUB_INPUT_DIGITAL1);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_INPUT_DIGITAL1);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_INPUT_ANALOG);
        }   
 #else
        switch(SysSourceGetInputPort())
        {
            case _A0_INPUT_PORT:
                SET_OSD_STATE(_SUB_INPUT_ANALOG);
                ucItem_3_1 = _SUB_INPUT_DIGITAL1;
                ucItem_3_2 = _SUB_INPUT_ANALOG;
                ucItem_3_3 = _SUB_INPUT_DIGITAL0;
                break;
                
            case _D0_INPUT_PORT:
                SET_OSD_STATE(_SUB_INPUT_DIGITAL0);
                ucItem_3_1 = _SUB_INPUT_ANALOG;
                ucItem_3_2 = _SUB_INPUT_DIGITAL0;
                ucItem_3_3 = _SUB_INPUT_DIGITAL1;               
                break;
                
            case _D1_INPUT_PORT:
                SET_OSD_STATE(_SUB_INPUT_DIGITAL1);
                ucItem_3_1 = _SUB_INPUT_DIGITAL0;
                ucItem_3_2 = _SUB_INPUT_DIGITAL1;
                ucItem_3_3 = _SUB_INPUT_ANALOG;                               
                break;

            default:
                break;
        }
        OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, ucItem_3_1);
        OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, ucItem_3_2);
        OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, ucItem_3_3);
    #endif
    }
#endif
#if(_ASPECT_RATIO_SUPPORT == _ON)
    else if(GET_OSD_STATE() == _SUB_SCALING)
    {
        if(GET_OSD_ASPECT_RATIO_TYPE() == _ASPECT_RATIO_FULL)
        {
            SET_OSD_STATE(_SUB_SCALING_FULL_SCREEN);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_SCALING_FULL_SCREEN);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_SCALING_ORIGINAL_AR);
        }
        else
        {
            SET_OSD_STATE(_SUB_SCALING_ORIGINAL_AR);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_SCALING_ORIGINAL_AR);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_SCALING_FULL_SCREEN);
        }
    }
#endif
#if(_OD_OSD_SUPPORT == _ON)
#if(_OD_MULTI_SELECT == _ON)
		else if(GET_OSD_STATE() == _SUB_OVER_DRIVE)
		{
			SET_OSD_STATE(_SUB_OD_OFF + GET_OSD_OD_STATUS());
			if(GET_OSD_OD_STATUS() == _OD_OFF)
			{
				OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_OD_EXTREME);
				OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS,	_SUB_OD_OFF);
				OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_OD_NORMAL);
			}
			else if(GET_OSD_OD_STATUS() == _OD_NORMAL)
			{
				OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_OD_OFF);
				OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS,	_SUB_OD_NORMAL);
				OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_OD_EXTREME);
			}
			else if(GET_OSD_OD_STATUS() == _OD_EXTREME)
			{
				OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_OD_NORMAL);
				OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS,	_SUB_OD_EXTREME);
				OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_OD_OFF);
			}
	
			g_usBeforeValue = GET_OSD_OD_STATUS();	
		}
#else
		else if(GET_OSD_STATE() == _SUB_OVER_DRIVE)
		{
			if(GET_OSD_OD_STATUS() == _ON)
			{
				SET_OSD_STATE(_SUB_OD_ON);
				OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_OD_ON);
				OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_OD_OFF);
			}
			else
			{
				SET_OSD_STATE(_SUB_OD_OFF);
				OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_OD_OFF);
				OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_OD_ON);
			}
		}
#endif
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
    else if(GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT)
    {       
        if(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
        {
            SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT_ON);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_LOW_BLUE_LIGHT_ON);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_LOW_BLUE_LIGHT_OFF);           
        }
        else
        {
            SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT_OFF);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_LOW_BLUE_LIGHT_OFF);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_LOW_BLUE_LIGHT_ON);
        } 
	}  
#endif
}

//Left Key(第二層Item旋轉)
void OsdSubColorInputScalingItemK2(void)
{
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	OsdAnimationItemAnimation(GET_OSD_STATE());
#else

	if(GET_OSD_DCR_STATUS() == _ON)
	{
#if(_INPUT_PORT_MAX > 0x01)
	#if((_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON))
		OsdAnimationItemAnimation(GET_OSD_STATE());
	#else
		#if((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON))
		
		#if(_OD_OSD_SUPPORT == _ON)
			OsdAnimationItemAnimation(GET_OSD_STATE());
		#else
			#if(_ASPECT_RATIO_SUPPORT == _ON)
			if(UserCheckAspectRatioFunction() == _TRUE)
			{
				OsdAnimationItemAnimation(GET_OSD_STATE());
			}
			#endif
		#endif	
		
		#endif
	#endif
#else
	#if((_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON))
		if(UserCheckAspectRatioFunction() == _TRUE)
		{
			OsdAnimationItemAnimation(GET_OSD_STATE());
		}
	#endif
#endif
	}
	else
	{
#if(_INPUT_PORT_MAX > 0x01)
		OsdAnimationItemAnimation(GET_OSD_STATE());							
#else

	#if((_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON))
		OsdAnimationItemAnimation(GET_OSD_STATE());
	#else
	
	#if((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON))
	
	#if(_OD_OSD_SUPPORT == _ON)
		OsdAnimationItemAnimation(GET_OSD_STATE());
	#else
		if(UserCheckAspectRatioFunction() == _TRUE)
		{
			OsdAnimationItemAnimation(GET_OSD_STATE());
		}	
	#endif	
	
	#endif
		
	#endif
		
#endif
	}
#endif
}

//Right Key(第二層Item旋轉)
void OsdSubColorInputScalingItemK3(void)
{
    OsdSubColorInputScalingItemK2();
}

//Exit Key(離開OSD)
void OsdSubColorInputScalingItemK4(void)
{
    SET_Key_Relax_FLAG();
#if(((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))\
	||((_INPUT_PORT_MAX <= 0x01) && (((_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))\
	|| ((_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))))
    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayClearFocusFrame(_ITEM_2_ROW); // 3ms
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);

#else
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);

    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
#endif
}

//-------------------------------------------------------------------------------------------------------------
//  (Option)Select Item: 1.Information 2.Language 3.OSD Postion 4.FACTORY DEFAULT 5.ACCESSIBILITY 6.DP Select	
//-------------------------------------------------------------------------------------------------------------
//Menu Key(進入第三層)
void OsdSubInfoLanPosFactAccItemK1(void)
{
    //依據第二層Item目錄畫第三層
    if(GET_OSD_STATE() == _SUB_INFORMATION)
    {
        SET_OSD_STATE(_DISP_INFORMATION);    //顯示Information訊息
        OsdDisplayDrawInformation();         
    }
    else
    {
        // 3 layer back ground color
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
#if(_LANGUAGE_TYPE != _1_LAN)
        if(GET_OSD_STATE() == _SUB_MENU_LANGUAGE)
        {
            SET_OSD_STATE(_SUB_LAN_ENGLISH + GET_OSD_LANGUAGE());

            //上一個語言Item
            SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, OsdDisplayDetOverRange(GET_OSD_STATE(), _SUB_LAN_RUSSIAN, _SUB_LAN_ENGLISH, _ON));

            //目前語言Item
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, GET_OSD_STATE());

            //下一個語言Item
            SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
            OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, OsdDisplayDetOverRange(GET_OSD_STATE(), _SUB_LAN_RUSSIAN, _SUB_LAN_ENGLISH, _ON));
        }
        else if(GET_OSD_STATE() == _SUB_MENU_POSITION)
#else
		if(GET_OSD_STATE() == _SUB_MENU_POSITION)
#endif
        {
            SET_OSD_STATE(_SUB_POS_DEFAULT);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_POS_DEFAULT);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_POS_CUSTOM);
        }
        else if(GET_OSD_STATE() == _SUB_FACTORY_DEFAULT)
        {
            SET_OSD_STATE(_SUB_FACTORY_CANCEL);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_FACTORY_CANCEL);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_FACTORY_RESET);
        }
        else if(GET_OSD_STATE() == _SUB_ACCESSIBILITY)
        {
            SET_OSD_STATE(_SUB_ACCESS_RATE);
            OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_ACCESS_RATE);
            OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_ACCESS_TIMEOUT);
        }
#if (_DP_SUPPORT == _ON)
        else if(GET_OSD_STATE() == _SUB_DP_SELECT)
        {            
            if(GET_DP_TYPE() == _DP_1_1)
            {
                SET_OSD_STATE(_SUB_DP_SL_11);           
                OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_DP_SL_11);
                OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_DP_SL_12);
            }
            else   //_DP_1_2
            {
                SET_OSD_STATE(_SUB_DP_SL_12);           
                OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_DP_SL_12);
                OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_DP_SL_11);
            }               
        }
#endif
    }
}

//Left Key(第二層Item旋轉)
void OsdSubInfoLanPosFactAccItemK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第二層Item旋轉)
void OsdSubInfoLanPosFactAccItemK3(void)
{
    OsdSubInfoLanPosFactAccItemK2();
}

//Exit Key(離開OSD)
void OsdSubInfoLanPosFactAccItemK4(void)
{
    SET_Key_Relax_FLAG();
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_OPTIONS);
//    OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_IMAGE_SETUP);
//    OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
//    OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS,  _MAIN_OPTIONS);
//    OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
//    OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_IMAGE_POSITION);

    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
}

//====================================================================================================
//                                   第三層(進入第四層)
//====================================================================================================
//-------------------------------------------------
//Select Item: Brightness Bar(第三層)處理
//-------------------------------------------------
//Menu Key(儲存至記憶體)
void OsdBarBriK1(void)
{
    //OSD儲存動作
    SET_OSD_BACKLIGHT(g_usAdjustValue_1);
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);       //儲存Bri Data       
    //SET_OSD_STATE(_SUB_BRI);    

    //回到第一層
    SET_Key_Relax_FLAG();       //離開OSD
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();  
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

#if(_USER_DCR_FUNCTION == _ON)

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_BRI_CON_DCR);  
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
	
#else

	SET_OSD_STATE(_SUB_BRI); 
	OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDisplayWaitForDrawing();
	OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
	OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

	SET_OSD_STATE(_MAIN_BRI_CON_DCR);
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDisplayWaitForDrawing();
	OsdDisplayMainMenuDescription(GET_OSD_STATE());
	OsdDisplayDispButton(_KEY_INFO_EXIT);

#endif
}

//Left Key動作(Bri Bar加減處理)
void OsdBarBriK2(void)
{
#if(_ENERGY_STAR_SUPPORT == _ON)
	BYTE ucTempBackLight = 0;
#endif

    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, BACKLIGHT_PERCENT_MAX, BACKLIGHT_PERCENT_MIN, _OFF);    
#if(_ENERGY_STAR_SUPPORT == _ON)
	if(GET_OSD_ES_STATUS() == _ON) 
	{
		ucTempBackLight = GET_OSD_BACKLIGHT(); 
		SET_OSD_BACKLIGHT(g_usAdjustValue_1);

		UserAdjustESBacklight();

		SET_OSD_BACKLIGHT(ucTempBackLight);
	}
	else
#endif
	{
		UserAdjustBacklightPercent(g_usAdjustValue_1);
	}
    OsdDisplayDrawBar(_ITEM_3_ROW,g_usAdjustValue_1, _Bar_0_100);
}

//Right Key動作(Bri Bar加減處理)
void OsdBarBriK3(void)
{
    OsdBarBriK2();
}

//Exit Key(離開OSD)
void OsdBarBriK4(void)
{
#if(_ENERGY_STAR_SUPPORT == _ON)
	if(GET_OSD_ES_STATUS() == _ON) 
	{
		UserAdjustESBacklight();
	}
	else
#endif
	{
		UserAdjustBacklightPercent(g_usBeforeValue);
		SET_OSD_BACKLIGHT(g_usBeforeValue); 		  //回到原來的值
	}
    
    SET_Key_Relax_FLAG();
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing(); //Ada.chen 20150609 
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_BRI);
}

void OsdHotKeyBarBriK1(void)
{
    //OSD儲存動作
    SET_OSD_BACKLIGHT(g_usAdjustValue_1);
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);       //儲存Bri Data   

    SET_Key_Relax_FLAG();       //離開OSD

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();

    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
#if(_USER_DCR_FUNCTION == _ON)
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_BRI_CON_DCR);
#else
	
		SET_OSD_STATE(_SUB_BRI); 
		OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
		ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		OsdDisplayWaitForDrawing();
		OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
		OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
	
		SET_OSD_STATE(_MAIN_BRI_CON_DCR);
		ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		OsdDisplayWaitForDrawing();
		OsdDisplayMainMenuDescription(GET_OSD_STATE());
		OsdDisplayDispButton(_KEY_INFO_EXIT);
	
#endif

 }

//-------------------------------------------------
//Select Item: Contrast Bar(第三層)處理
//-------------------------------------------------
//Menu Key(儲存至記憶體)
void OsdBarConK1(void)
{
    //OSD儲存動作
    SET_OSD_CONTRAST(g_usAdjustValue_1);
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);       //儲存Con Data 

    //回到第一層
    SET_Key_Relax_FLAG();      //離開OSD
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing(); //Ada.chen 20150609    
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

#if(_USER_DCR_FUNCTION == _ON)   
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_BRI_CON_DCR);  
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
#else
	SET_OSD_STATE(_SUB_CON); 
	OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDisplayWaitForDrawing();
	OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
	OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

	SET_OSD_STATE(_MAIN_BRI_CON_DCR);
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDisplayWaitForDrawing();
	OsdDisplayMainMenuDescription(GET_OSD_STATE());
	OsdDisplayDispButton(_KEY_INFO_EXIT);
#endif
}

//Left Key動作(Con Bar加減處理)
void OsdBarConK2(void)
{
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, _CONTRAST_MAX, _CONTRAST_MIN, _OFF);      
    UserAdjustContrast(g_usAdjustValue_1);
    OsdDisplayDrawBar(_ITEM_3_ROW, g_usAdjustValue_1, _Bar_0_100);
}

//Right Key(Con Bar加減處理)
void OsdBarConK3(void)
{
    OsdBarConK2();
}

//Exit Key(離開OSD)
void OsdBarConK4(void)
{
    UserAdjustContrast(g_usBeforeValue);
    SET_OSD_CONTRAST(g_usBeforeValue);           //回到原來的值
    SET_Key_Relax_FLAG();
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing(); //Ada.chen 20150609 
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_CON);
}

#if(_USER_DCR_FUNCTION == _ON)
//-------------------------------------------------
//  Select Item: DCR(第三層)處理
//-------------------------------------------------
//Menu Key(設定DCR Flag並儲存至記憶體)
void OsdSubDcrOnOffK1(void)//Eli 20140909
{    
    if(GET_OSD_STATE() == _SUB_DCR_ON)
    {
        if(GET_OSD_DCR_STATUS() == _OFF)
    	{
            UserAdjustDCRControl(_ON);
            SET_OSD_DCR_STATUS(_ON);
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        }
    }    
    else if(GET_OSD_STATE() == _SUB_DCR_OFF)    
    {
        if(GET_OSD_DCR_STATUS() == _ON)
    	{
            UserAdjustDCRControl(_OFF);
            SET_OSD_DCR_STATUS(_OFF);
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        }
    }    

    //回到第一層
    SET_Key_Relax_FLAG();      //離開OSD
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdDisplayClearFocusFrame(_ITEM_3_ROW);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(12), HEIGHT(1), CHAR(___));
    
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
#if 0//((_INPUT_PORT_MAX <= 0x01) && (_OD_OSD_SUPPORT == _OFF) && (_ASPECT_RATIO_SUPPORT == _ON))
    if(GET_FACTORY_MODE() != _ON)
    {
        OsdDisplayClearFocusFrame(_ITEM_2_ROW); // 3ms
        if((GET_OSD_DCR_STATUS() == _ON) && (UserCheckAspectRatioFunction() == _FALSE))
        {
            OsdDisplayItemDraw(_ICON_1_1, _ITEM_UNSELECT, _MAIN_IMAGE_PROPERTIES);
        }
        else
        {
            OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
        }
    }
#endif
    SET_OSD_STATE(_MAIN_BRI_CON_DCR);
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
}

//Left Key動作(ON/OFF選擇)
void OsdSubDcrOnOffK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key動作(ON/OFF選擇)
void OsdSubDcrOnOffK3(void)
{
    OsdSubDcrOnOffK2();
}

//Exit Key(離開OSD)
void OsdSubDcrOnOffK4(void)
{
    SET_Key_Relax_FLAG();
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdDisplayClearFocusFrame(_ITEM_3_ROW);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(12), HEIGHT(1), CHAR(___));

    SET_OSD_STATE(_SUB_DCR);
/*
    if(GET_OSD_DCR_STATUS() == _ON)
    {
        OsdDisplayItemDraw(_ITEM_2_1, _ITEM_UNSELECT, _SUB_CON);
        OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_DCR);
        OsdDisplayItemDraw(_ITEM_2_3, _ITEM_UNSELECT, _SUB_BRI);
    }
    else
    {
        OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_CON);
        OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_DCR);
        OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_BRI);
    }
*/
}
#endif
//--------------------------------------------------------------------
//  Select Item:(VGA)H Postion Bar(第三層)處理	
//--------------------------------------------------------------------
//Menu Key(儲存至記憶體)
void OsdBarHPositionK1(void)
{
    //OSD儲存動作
    SET_VGA_MODE_ADJUST_H_POSITION(g_usAdjustValue_1);
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG); //儲存H Postion Data 
    
    SET_Key_Relax_FLAG();      //離開OSD
    
    //回到第一層
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
   
    SET_OSD_STATE(_SUB_IMAGE_POS_H); 
    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_IMAGE_POSITION);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
}

//Left Key動作(H Postion Bar加減處理)
void OsdBarHPositionK2(void)
{
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, 100, 0, _OFF);   
    UserCommonAdjustHPosition(g_usAdjustValue_1);               //調整H位置動作
    OsdDisplayDrawBar(_ITEM_3_ROW, g_usAdjustValue_1, _Bar_0_100);    
}

//Right Key動作(H Postion Bar加減處理)
void OsdBarHPositionK3(void)
{
    OsdBarHPositionK2();
}

//Exit Key(離開OSD)
void OsdBarHPositionK4(void)
{
    UserCommonAdjustHPosition(g_usBeforeValue);
    SET_VGA_MODE_ADJUST_H_POSITION(g_usBeforeValue);           //回到原來的值
    
    SET_Key_Relax_FLAG();

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing(); //Ada.chen 20150609 
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_IMAGE_POS_H);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_IMAGE_POS_V);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_IMAGE_POS_H);
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_IMAGE_POS_V);
}

//--------------------------------------------------------------------
//  Select Item:(VGA)V Postion(第三層)處理	
//--------------------------------------------------------------------
//Menu Key(儲存至記憶體)
void OsdBarVPositionK1(void)
{
    //OSD儲存動作
    SET_VGA_MODE_ADJUST_V_POSITION(g_usAdjustValue_1);
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG); //儲存H Postion Data 
    
    SET_Key_Relax_FLAG();      //離開OSD
    
    ///回到第一層
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
   
    SET_OSD_STATE(_SUB_IMAGE_POS_V);  
    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_IMAGE_POSITION);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
}

//Left Key動作(V Postion Bar加減處理)
void OsdBarVPositionK2(void)
{

    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, 100, 0, _OFF);   
    UserCommonAdjustVPosition(g_usAdjustValue_1);      //調整V位置動作
    OsdDisplayDrawBar(_ITEM_3_ROW, g_usAdjustValue_1, _Bar_0_100);   
}

//Right Key動作(V Postion Bar加減處理)
void OsdBarVPositionK3(void)
{
    OsdBarVPositionK2();
}

//Exit Key(離開OSD)
void OsdBarVPositionK4(void)
{
    UserCommonAdjustVPosition(g_usBeforeValue);
    SET_VGA_MODE_ADJUST_V_POSITION(g_usBeforeValue);           //回到原來的值
    
    SET_Key_Relax_FLAG();

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing(); //Ada.chen 20150609 
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_IMAGE_POS_V);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_IMAGE_POS_H);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_IMAGE_POS_V);
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_IMAGE_POS_H);
}


//----------------------------------------------------------------------
//  (Manual)Select Item:1.Clock 2.Phase	(第三層)處理	
//----------------------------------------------------------------------
//Menu Key(進入第四層)
void OsdSubClockPhaseK1(void)
{
    // 4 layer back ground color
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

    //依據第三層Item目錄畫第四層
    if(GET_OSD_STATE() == _SUB_MANUAL_CLOCK)
    {
        SET_OSD_STATE(_BAR_CLOCK);
        OsdDisplayDrawBar(_ITEM_4_ROW, GET_VGA_MODE_ADJUST_CLOCK(), _Bar_0_100);
        g_usBeforeValue = GET_VGA_MODE_ADJUST_CLOCK();               //(VGA)CLK調整前值
        g_usAdjustValue_1 = GET_VGA_MODE_ADJUST_CLOCK();        
    }
    else if(GET_OSD_STATE() == _SUB_MANUAL_PHASE)
    {
        SET_OSD_STATE(_BAR_PHASE);
        OsdDisplayDrawBar(_ITEM_4_ROW, GET_VGA_MODE_ADJUST_PHASE(), _Bar_0_100);
        g_usBeforeValue = GET_VGA_MODE_ADJUST_PHASE();               //(VGA)PHASE調整前值
        g_usAdjustValue_1 = GET_VGA_MODE_ADJUST_PHASE();      
    }
}

//Left Key(第三層Item旋轉)
void OsdSubClockPhaseK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第三層Item旋轉)
void OsdSubClockPhaseK3(void)
{
    OsdSubClockPhaseK2();
}

//Exit Key(離開OSD)
void OsdSubClockPhaseK4(void)
{
    SET_Key_Relax_FLAG();
    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_MANUAL);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_AUTO_SETUP);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_MANUAL);
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_AUTO_SETUP);
}

//----------------------------------------------------------------------
//  (Color)Select Item:1.Preset Mode 2.Custom Mode(第三層)處理	
//----------------------------------------------------------------------
//Menu Key(進入第四層)
void OsdSubPresetCustomK1(void)
{
    // 4 layer back ground color
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

    g_usBeforeValue= GET_COLOR_TEMP_TYPE();            //Color Type調整前值   
  
    //依據第三層Item目錄畫第四層
    if(GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE)
    {     
#if((_FACTORY_MODE_OWNER == _OWNER_TPV) || (_FACTORY_MODE_OWNER == _OWNER_FOXCONN))
		switch(GET_PRESET_COLOR_TEMP_BACKUP()) 
#else
        switch(GET_COLOR_TEMP_TYPE()) 
#endif
        {
           case _CT_7200:   // Neutral     
               SET_OSD_STATE(_SUB_NEUTRAL);
               OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_sRGB);
               OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_NEUTRAL);
               OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_BLUISH);
               break;
               
           case _CT_SRGB:   // srgb   
               SET_OSD_STATE(_SUB_sRGB);
               OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_REDDISH);
               OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_sRGB);
               OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_NEUTRAL);
               break;
               
           case _CT_6500:   // reddish
               SET_OSD_STATE(_SUB_REDDISH);
               OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_BLUISH);
               OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_REDDISH);
               OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_sRGB);
               break;
               
           case _CT_9300:   // bluish
               SET_OSD_STATE(_SUB_BLUISH);
               OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_NEUTRAL);
               OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_BLUISH);
               OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_REDDISH);
               break;
               
           default:          //User
               SET_OSD_STATE(_SUB_NEUTRAL);  
               SET_COLOR_TEMP_TYPE(_CT_7200);
			   #if((_FACTORY_MODE_OWNER == _OWNER_TPV) || (_FACTORY_MODE_OWNER == _OWNER_FOXCONN))   
			   SET_PRESET_COLOR_TEMP_BACKUP(_CT_7200);
   			   #endif

			   #if(_FACTORY_MODE_OWNER != _OWNER_FOXCONN) //lorimiao 20141125
               g_usBeforeValue = _CT_7200;
			   #endif
               OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_sRGB);
               OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_NEUTRAL);
               OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_BLUISH);
               break;
               
        }      
#if((_FACTORY_MODE_OWNER == _OWNER_TPV) || (_FACTORY_MODE_OWNER == _OWNER_FOXCONN))
        RTDNVRamLoadColorSetting( GET_PRESET_COLOR_TEMP_BACKUP());       
        g_usAdjustValue_2 = GET_PRESET_COLOR_TEMP_BACKUP();
        if(GET_PRESET_COLOR_TEMP_BACKUP() == _CT_SRGB)
#else
        RTDNVRamLoadColorSetting( GET_COLOR_TEMP_TYPE());       
        g_usAdjustValue_2 = GET_COLOR_TEMP_TYPE();
        if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
#endif
        {
            UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
            UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
        }
        else
        {
            UserAdjustContrast(GET_OSD_CONTRAST());
#if(_ENERGY_STAR_SUPPORT == _ON)
						if(GET_OSD_ES_STATUS() == _ON)
						{
							UserAdjustESBacklight();
						}
						else
						{
							UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
						}
#else
						UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
#endif
        }
                  
    }
    else if(GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
    {     
	#if 1//lorimiao 20141025
        SET_COLOR_TEMP_TYPE(_CT_USER);
	#endif		
        SET_OSD_STATE(_SUB_CUSTOM_R);
        OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_CUSTOM_B);
        OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_CUSTOM_R);
        OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_CUSTOM_G);
        RTDNVRamLoadColorSetting(_CT_USER);
        UserAdjustContrast(GET_OSD_CONTRAST());
#if(_ENERGY_STAR_SUPPORT == _ON)
				if(GET_OSD_ES_STATUS() == _ON)
				{
					UserAdjustESBacklight();
				}
				else
				{
					UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
				}
#else
				UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
#endif
    }
}

//Left Key(第三層Item旋轉)
void OsdSubPresetCustomK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第三層Item旋轉)
void OsdSubPresetCustomK3(void)
{
    OsdSubPresetCustomK2();
}

//Exit Key(離開OSD)
void OsdSubPresetCustomK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_COLOR);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_SCALING);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_COLOR);
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_INPUT_SIGNAL);
}

#if(_INPUT_PORT_MAX > 0x01)
//----------------------------------------------------------------------
//  (Input Signal)Select Item:1.Analog 2.Digital 3.HDMI	(第三層)處理	
//----------------------------------------------------------------------
//Menu Key(設定Port並儲存至記憶體)
void OsdSubAnalogDviHdmiK1(void)
{
    BYTE ucResetToSearch = _FALSE;

    if(GET_OSD_STATE() ==  _SUB_INPUT_ANALOG)
    {
        if((SysSourceGetInputPort() != _A0_INPUT_PORT))
        {
   		    SET_FORCE_POW_SAV_STATUS(_FALSE);
   		    SysSourceSwitchInputPort(_A0_INPUT_PORT);
   		    ucResetToSearch = _TRUE;       		    
        }
		#if 1//lorimiao 20141010
		else
		{
			SET_Key_Relax_FLAG();
			OsdDisplayDisableOsd();
		}
		#endif
    }    
  #if(_INPUT_PORT_MAX == 0x03)
    else if(GET_OSD_STATE() == _SUB_INPUT_DIGITAL0)    
    {
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)        	    
        if((SysSourceGetInputPort() != _D0_INPUT_PORT))
        {
   		    SET_FORCE_POW_SAV_STATUS(_FALSE);
   		    SysSourceSwitchInputPort(_D0_INPUT_PORT);
   		    ucResetToSearch = _TRUE;       		    
        }
		#if 1//lorimiao 20141010
		else
		{
			SET_Key_Relax_FLAG();
			OsdDisplayDisableOsd();
		}
		#endif
#endif            
    }
    #endif
    else if(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)    
    {
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)        	    
        if((SysSourceGetInputPort() != _D1_INPUT_PORT))
        {
   		    SET_FORCE_POW_SAV_STATUS(_FALSE);
   		    SysSourceSwitchInputPort(_D1_INPUT_PORT);
   		    ucResetToSearch = _TRUE;       		    
        }
		#if 1//lorimiao 20141010
		else
		{
			SET_Key_Relax_FLAG();
			OsdDisplayDisableOsd();
		}
		#endif
#endif            

    }

    if(ucResetToSearch == _TRUE)
    {
        SET_OSD_INPUT_FLAG(_ON);    
	    SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
	    
	    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

	    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
	       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
	    {
	        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
	        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
	        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
	    }
        
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)//ym20141126 . for HDMI Hotplug toggle only by OSD switch port
        SET_HDMI_HOTPLUG_TOGGLE();
#endif
    }
}

//Left Key(第三層Item旋轉)
void OsdSubAnalogDviHdmiK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第三層Item旋轉)
void OsdSubAnalogDviHdmiK3(void)
{
    OsdSubAnalogDviHdmiK2();
}

//Exit Key(離開OSD)
void OsdSubAnalogDviHdmiK4(void)
{
    SET_Key_Relax_FLAG();
#if((_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
	//OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
#else
	OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
	OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdDisplayClearFocusFrame(_ITEM_3_ROW);
#endif
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
    SET_OSD_STATE(_SUB_INPUT_SIGNAL);
}
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
//-------------------------------------------------------------------------------------------
//  (Scaling)Select Item:1.Full Screen(Scaling ON) 2.Original AR(Scaling OFF)(第三層)處理		
//-------------------------------------------------------------------------------------------
//Menu Key依據選擇的Item動作
void OsdSubScalingOnOffK1(void)
{
     if(GET_OSD_STATE() == _SUB_SCALING_FULL_SCREEN)      //Scaling ON
     {        
        if((UserCheckAspectRatioFunction() == _TRUE) && (GET_OSD_ASPECT_RATIO_TYPE() != _ASPECT_RATIO_FULL))//Eli  20121105 Scaling on off condition.
		{				            
		    SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_FULL);
			UserAdjustSelectAspectRatio();
			SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);	
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
	    }
     }   
     else if(GET_OSD_STATE() == _SUB_SCALING_ORIGINAL_AR) //Scaling OFF     
     {        
        if((UserCheckAspectRatioFunction() == _TRUE) && (GET_OSD_ASPECT_RATIO_TYPE() != _ASPECT_RATIO_OFF))//Eli  20121105 Scaling on off condition.
		{				               
		    SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_OFF);
			UserAdjustSelectAspectRatio();
			SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);	
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
		}			
     }   
     SET_Key_Relax_FLAG();     //離開OSD

    //回到第一層
    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();  
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

#if((_INPUT_PORT_MAX <= 0x01)&& (_OD_OSD_SUPPORT == _OFF))

	SET_OSD_STATE(_SUB_SCALING); 
	OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
	
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDisplayWaitForDrawing();
    OsdDisplayClearFocusFrame(_ITEM_2_ROW); // 3ms
	OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
	OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
	SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);
	
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDisplayWaitForDrawing();

#else
	
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
	
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();        
    SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);
#endif   
	OsdDisplayMainMenuDescription(GET_OSD_STATE());
	OsdDisplayDispButton(_KEY_INFO_EXIT);

}

//Left Key(第三層Item旋轉)
void OsdSubScalingOnOffK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第三層Item旋轉)
void OsdSubScalingOnOffK3(void)
{
    OsdSubScalingOnOffK2();
}

//Exit Key(離開OSD)
void OsdSubScalingOnOffK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_SCALING);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_INPUT_SIGNAL);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_SCALING);
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_COLOR);
}
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------
void OsdSubLowBlueLightOnOffK1(void)
{
    DebugMessageOsd("OsdSubLowBlueLightOnOffK1", GET_OSD_STATE());
    
    if(GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON)
    {           
        if(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF)
    	{
            SET_OSD_LOW_BLUE_LIGHT_STATUS(_ON);
#if(_USER_DCR_FUNCTION == _ON)
			if(GET_OSD_DCR_STATUS() == _ON)
			{
				UserAdjustDCRControl(_OFF);
			}
#endif
			RTDNVRamLoadColorSetting(_CTLOWBLUELIGHT); 
#if(_OSD_LBL_ADJUST_FUNCTION == _OFF)
			UserAdjustBacklightPercent(_LOW_BLUE_LIGHT_BACKLIGHT);
			UserAdjustContrast(_LOW_BLUE_LIGHT_CONTRAST);
#else
			if(GET_OSD_LBL_STATUS() == _OFF)
			{
				SET_OSD_BACKLIGHT(_LOW_BLUE_LIGHT_BACKLIGHT);
				SET_OSD_CONTRAST(_LOW_BLUE_LIGHT_CONTRAST);
			}
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
			
		    SET_OSD_LBL_STATUS(_ON);
#endif
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            
        }
    }   
    else if(GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)        
    {        
        if(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
    	{
            SET_OSD_LOW_BLUE_LIGHT_STATUS(_OFF);
#if(_USER_DCR_FUNCTION == _ON)
			if(GET_OSD_DCR_STATUS() == _ON)
			{
				UserAdjustDCRControl(_ON);
			}
#endif
            RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
	        if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)	
	        {
	            UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
	            UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
	        }
	        else
	        {
	            UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
	            UserAdjustContrast(GET_OSD_CONTRAST());
        	}
#if(_OSD_LBL_ADJUST_FUNCTION == _ON)
			SET_OSD_LBL_STATUS(_OFF);
#endif
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            
        }
    }   
    RTDNVRamSaveBriCon();
	SET_Key_Relax_FLAG();     //離開OSD
   
    //回到第一層
    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();  
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

#if((_INPUT_PORT_MAX <= 0x01)&& (_OD_OSD_SUPPORT == _OFF))

	SET_OSD_STATE(_SUB_SCALING); 
	OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
	
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDisplayWaitForDrawing();
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
	OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
	OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
	SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);
	
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDisplayWaitForDrawing();

#else
	
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
	
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();        
    SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);
#endif   

    if(GET_FACTORY_MODE() != _ON)
    {
        if((GET_COLOR_TEMP_TYPE() == _CT_SRGB) 
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
		||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
#endif
		)
        {
            OsdDisplayItemDraw(_ICON_1_5, _ITEM_UNSELECT, _MAIN_BRI_CON_DCR);
        }
        else
        {
            OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
        }
    }

	OsdDisplayMainMenuDescription(GET_OSD_STATE());
	OsdDisplayDispButton(_KEY_INFO_EXIT);
}

void OsdSubLowBlueLightOnOffK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

void OsdSubLowBlueLightOnOffK3(void)
{
    OsdSubLowBlueLightOnOffK2();
}

void OsdSubLowBlueLightOnOffK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT);
}
#endif

#if(_OD_OSD_SUPPORT == _ON)
#if(_OD_MULTI_SELECT == _ON)
void OsdSubOdSelectK1(void)
{
    SET_OSD_OD_STATUS(GET_OSD_STATE() - _SUB_OD_OFF);

    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

    SET_Key_Relax_FLAG();       //離開OSD

    SET_OSD_STATE(_SUB_OVER_DRIVE);
    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));


    SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);

}
void OsdSubOdSelectK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
    SET_OSD_OD_STATUS(GET_OSD_STATE() - _SUB_OD_OFF);		//Lexie 20160328 modify for od load gain
    ScalerODAdjustDeltaGain(UserInterfaceGetODGainData());
	ScalerODControl((GET_OSD_OD_STATUS() == _OD_OFF) ? _OD_OFF : _OD_NORMAL);			  
}
void OsdSubOdSelectK3(void)
{
    OsdSubOdSelectK2();
}
void OsdSubOdSelectK4(void)
{

    SET_Key_Relax_FLAG();

    SET_Key_Relax_FLAG();
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();

    OsdDisplayClearFocusFrame(_ITEM_3_ROW);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(12), HEIGHT(1), CHAR(___));

	//Lexie 20160328 modify for od load gain
	if(g_usBeforeValue != GET_OSD_OD_STATUS())
	{
		SET_OSD_OD_STATUS(g_usBeforeValue);
	    ScalerODAdjustDeltaGain(UserInterfaceGetODGainData());
		ScalerODControl((GET_OSD_OD_STATUS() == _OD_OFF) ? _OD_OFF : _OD_NORMAL);			  
	    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
	}

    SET_OSD_STATE(_SUB_OVER_DRIVE);
/*

    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
    SET_OSD_STATE(_SUB_OVER_DRIVE);
*/
}

#else

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------
void OsdSubOdOnOffK1(void)
{
    if(GET_OSD_STATE() == _SUB_OD_ON)
    {           
        if(GET_OSD_OD_STATUS() == _OFF)
    	{
            SET_OSD_OD_STATUS(_ON);
            ScalerODControl(_ON);
            ScalerODAdjustDeltaGain(GET_OSD_OD_GAIN());            
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            
        }
    }   
    else if(GET_OSD_STATE() == _SUB_OD_OFF)        
    {        
        if(GET_OSD_OD_STATUS() == _ON)
    	{
            SET_OSD_OD_STATUS(_OFF);
            ScalerODControl(_OFF);            
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            
        }
    }   
    SET_Key_Relax_FLAG();     //離開OSD
   
   //回到第一層
    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();  
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
    
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();        
    SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
}

void OsdSubOdOnOffK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

void OsdSubOdOnOffK3(void)
{
    OsdSubOdOnOffK2();
}

void OsdSubOdOnOffK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_OVER_DRIVE);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_SCALING);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_OVER_DRIVE);
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_COLOR);
}
#endif
#endif
//---------------------------------------------------------------
//  (Information)Select Item: 顯示Information OSD動作(第三層)處理		
//---------------------------------------------------------------
//Menu Key
void OsdSubInformationK1(void)
{
    SET_Key_Relax_FLAG();

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();

    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(9), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(9), CHAR(___));

    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(_ITEM_WIDTH + 3), HEIGHT(1), CHAR(___));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_2 + 10), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_3 - 1), WIDTH(_ITEM_WIDTH + 3), HEIGHT(1), CHAR(___));
    
    //回到第一層
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();        
    SET_OSD_STATE(_MAIN_OPTIONS);
	
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);    
}

//Left Key
void OsdSubInformationK2(void)
{

}

//Right Key
void OsdSubInformationK3(void)
{
    OsdSubInformationK2();
}

//Exit Key(離開OSD)
void OsdSubInformationK4(void)
{
    //OsdSubInformationK1();
    
    SET_Key_Relax_FLAG();

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();

    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(9), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(9), CHAR(___));

    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(_ITEM_WIDTH + 3), HEIGHT(1), CHAR(___));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_2 + 10), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_3 - 1), WIDTH(_ITEM_WIDTH + 3), HEIGHT(1), CHAR(___));
    
    //回到第一層
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_3_ROW);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();        
    SET_OSD_STATE(_SUB_INFORMATION);
	
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);    
}


//-------------------------------------------------------------------------------------
//  (Languagel)Select Item:1.English 2.FRENCH 3.ITALIAN....8.RUSSIAN(第三層)處理	
//-------------------------------------------------------------------------------------
//Menu Key(語言確認)
#if(_LANGUAGE_TYPE != _1_LAN)

void OsdSubLan12345678K1(void)
{
    BYTE temp = GET_OSD_LANGUAGE();    

    SET_OSD_LANGUAGE(GET_OSD_STATE()-_SUB_LAN_ENGLISH);
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG); 

    SET_Key_Relax_FLAG();
    
    //回到第一層 
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_3_ROW);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    SET_OSD_STATE(_MAIN_OPTIONS);   
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);   
    OsdDisplayDispButton(_KEY_INFO_OK); 
}

//Left Key(第三層Item旋轉)
void OsdSubLan12345678K2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第三層Item旋轉)
void OsdSubLan12345678K3(void)
{
    OsdSubLan12345678K2();
}

//Exit Key(離開OSD)
void OsdSubLan12345678K4(void)
{
    SET_Key_Relax_FLAG();

    //回到第一層 
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_3_ROW);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_MENU_LANGUAGE);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_INFORMATION);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_MENU_LANGUAGE);
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_MENU_POSITION);
}
#endif
//---------------------------------------------------------------
//  (OSD Position)Select Item: 1.Default 2.Custom(第三層)處理		
//---------------------------------------------------------------
//Menu Key(第三層處理)
void OsdSubDefaultCustomK1(void)
{
    if(GET_OSD_STATE() == _SUB_POS_DEFAULT)   //OSD Postion回Default值
    { 
#if((_PROJECT == _PRJ_L_T2364p_AHP_LG_LM230WF9_SSA1)||(_PROJECT == _PRJ_L_T2364t_AHP_LG_LM230WF7_SSB1)||(_PROJECT == _PRJ_L_T23i_10_AHP_LG_LM230WF9_SSA1)||(_PROJECT == _PRJ_L_P23i_15_AHP_LG_LM230WF9_SSA1) ||(_PROJECT == _PRJ_L_T23i_10_AHP_BOE_MV230FHM_N20) ||(_PROJECT == _PRJ_L_P23i_10_AHP_BOE_MV230FHM_N20))

        SET_OSD_HPOS(186);
#else
		SET_OSD_HPOS(200);
#endif		
        SET_OSD_VPOS(0);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());       
        
        //回到第一層
        OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
        OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
        
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdDisplayWaitForDrawing();    
        OsdDisplayClearFocusFrame(_ITEM_2_ROW);
        OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
        OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdDisplayWaitForDrawing();        
        SET_OSD_STATE(_MAIN_OPTIONS);
        OsdDisplayMainMenuDescription(GET_OSD_STATE());
        OsdDisplayDispButton(_KEY_INFO_EXIT);    
    }
    else if(GET_OSD_STATE() == _SUB_POS_CUSTOM)
    {
        // 4 layer back ground color
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

        //依據第三層Item目錄畫第四層
        SET_OSD_STATE(_SUB_POS_CUST_H);
        OsdDisplayItemDraw(_ITEM_4_1, _ITEM_FOCUS, _SUB_POS_CUST_H);
        OsdDisplayItemDraw(_ITEM_4_2, _ITEM_SELECT, _SUB_POS_CUST_V);
    }
}

//Left Key(第三層Item旋轉)
void OsdSubDefaultCustomK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第三層Item旋轉)
void OsdSubDefaultCustomK3(void)
{
    OsdSubDefaultCustomK2();
}

//Exit Key(離開OSD)
void OsdSubDefaultCustomK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();  
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_MENU_POSITION);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_MENU_LANGUAGE);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_MENU_POSITION);
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_FACTORY_DEFAULT);
}

//--------------------------------------------------------------------
//  (Factory Default)Select Item: 1.Default 2.Custom(第三層)處理		
//--------------------------------------------------------------------
//Menu Key(第三層處理)
void OsdSubFactCancelResetK1(void)
{
    if(GET_OSD_STATE() == _SUB_FACTORY_RESET)
    {
        SET_Key_Relax_FLAG();
        OsdDisplayDisableOsd();
        OsdReset();

        OsdFuncOsdBlending(_BLENDING_TYPE1);
        OsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());   

        OsdFuncApplyMap(_OSD_MAP0);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_0);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_1);

        //Win 2,3,4,8,9 higher than font
        ScalerOsdFrameControlByte(0x002, _OSD_BYTE1, 0x03);
        ScalerOsdFrameControlByte(0x002, _OSD_BYTE2, 0xE0);

        //==== Load font & icon & color palette=======      //載入字型檔
        OsdFontLoadFont(_FONT1_GLOBAL);
        OsdFontLoadFont(_FONT1_BUTTON_ICON);

        // Item 5 used Font 256-511    
        OsdFunc1bitByte0(ROW(_ITEM_5_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
        // Item 4 used Font 256-511    
        OsdFunc1bitByte0(ROW(_ITEM_4_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);
        // Item 3 used Font 256-511    
        OsdFunc1bitByte0(ROW(_ITEM_3_ROW), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_ITEM_HEIGHT),_1BIT_FONT_256_511_WIDTH_12);

        // 1 layer back ground color
        OsdFunc1bitColor(ROW(_ITEM_1_ROW - 1), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(_OSD_MAP0_Height - (_ITEM_1_ROW - 1)), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

        SET_OSD_STATE(_MAIN_OPTIONS);        
        OsdDisplayItemDraw(_ICON_1_1, ((SysSourceGetInputPort() != _A0_INPUT_PORT) ? (_ITEM_UNSELECT) : (_ITEM_SELECT)),  _MAIN_IMAGE_SETUP);
        OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
        OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS, _MAIN_OPTIONS);
        OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
        OsdDisplayItemDraw(_ICON_1_5, ((SysSourceGetInputPort() != _A0_INPUT_PORT) ? (_ITEM_UNSELECT) : (_ITEM_SELECT)), _MAIN_IMAGE_POSITION);
        //==== Description ======
        OsdDisplayMainMenuDescription(GET_OSD_STATE());
        
        //==== Button ======
        OsdFunc1bitByte0(ROW(17), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(3),_1BIT_FONT_256_511_WIDTH_12);
        OsdDisplayDispButton(_KEY_INFO_ALL);       //顯示提示OSD Button ICON(最後一列)

        OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());

        OsdFuncEnableOsd();
    }   
    else   //_SUB_FACTORY_CANCEL
    {
        SET_Key_Relax_FLAG();
 
        //回到第一層       
        OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdDisplayWaitForDrawing();
        OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
        OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdDisplayWaitForDrawing();    
        OsdDisplayClearFocusFrame(_ITEM_2_ROW);
        OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
        OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdDisplayWaitForDrawing();        
        SET_OSD_STATE(_MAIN_OPTIONS);
        OsdDisplayMainMenuDescription(GET_OSD_STATE());
        OsdDisplayDispButton(_KEY_INFO_EXIT);    
    }  
}

//Left Key(第三層Item旋轉)
void OsdSubFactCancelResetK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第三層Item旋轉)
void OsdSubFactCancelResetK3(void)
{
    OsdSubFactCancelResetK2();
}

//Exit Key(離開OSD)
void OsdSubFactCancelResetK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_FACTORY_DEFAULT);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_MENU_POSITION);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_FACTORY_DEFAULT);
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_ACCESSIBILITY);
}

//-----------------------------------------------------------------------------------------
//  (Accessibility)Select Item: 1.Button repeat tate 2.Menu time out(第三層)處理		
//-----------------------------------------------------------------------------------------
//Menu Key(進入第四層)
void OsdSubRepeatMenuTimeK1(void)
{
    // 4 layer back ground color
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

    //依據第三層Item目錄畫第四層
    if(GET_OSD_STATE() == _SUB_ACCESS_RATE)
    {
        SET_OSD_STATE(_SUB_REPEAT_OFF + GET_OSD_BUTTON_REPEAT_STATUS());

        SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
        OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, OsdDisplayDetOverRange(GET_OSD_STATE(), _SUB_REPEAT_SLOW, _SUB_REPEAT_OFF, _ON));

        OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, GET_OSD_STATE());

        SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
        OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, OsdDisplayDetOverRange(GET_OSD_STATE(), _SUB_REPEAT_SLOW, _SUB_REPEAT_OFF, _ON));

    }
    else if(GET_OSD_STATE() == _SUB_ACCESS_TIMEOUT)
    {
        SET_OSD_STATE(_BAR_MENU_TIMEOUT);
        OsdDisplayDrawBar(_ITEM_4_ROW, GET_OSD_TIME_OUT(), _Bar_5_60);
        g_usBeforeValue = GET_OSD_TIME_OUT();               //TimeOut調整前值
        g_usAdjustValue_1 = GET_OSD_TIME_OUT();        
    }
}

//Left Key(第三層Item旋轉)
void OsdSubRepeatMenuTimeK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key(第三層Item旋轉)
void OsdSubRepeatMenuTimeK3(void)
{
    OsdSubRepeatMenuTimeK2();
}

//Exit Key(離開OSD)
void OsdSubRepeatMenuTimeK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_ACCESSIBILITY);
//    OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, _SUB_FACTORY_DEFAULT);
//    OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, _SUB_ACCESSIBILITY);
#if 0//(_DP_SUPPORT == _ON)
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_DP_SELECT);
#else
//    OsdDisplayItemDraw(_ITEM_2_3, _ITEM_SELECT, _SUB_INFORMATION);
#endif
}

//-----------------------------------------------------------------------------------------
#if (_DP_SUPPORT == _ON)
void OsdSubDpSelectK1(void)
{ 
    if(GET_OSD_STATE() == _SUB_DP_SL_11)
    {
        if(GET_DP_TYPE() != _DP_1_1)
        {
            SET_DP_TYPE(_DP_1_1); 
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);	
        }              
    }   
    else if(GET_OSD_STATE() == _SUB_DP_SL_12)  
    {
        if(GET_DP_TYPE() != _DP_1_2)
        {
            SET_DP_TYPE(_DP_1_2); 
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);	
        }              
    } 

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_OPTIONS);         
}

void OsdSubDpSelectK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

void OsdSubDpSelectK3(void)
{
    OsdSubDpSelectK2();
}

void OsdSubDpSelectK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_DP_SELECT);    
}
#endif

//====================================================================================================
//                                   第四層(進入第五層)處理
//====================================================================================================
//-----------------------------------------------
//    (Clock)Clock Bar調整(第四層)處理		
//-----------------------------------------------
//Menu Key(儲存至記憶體)
void OsdBarClockK1(void)
{
    //OSD儲存動作
    SET_VGA_MODE_ADJUST_CLOCK(g_usAdjustValue_1);
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);       //儲存CLK Data                 
    
    SET_Key_Relax_FLAG();       //離開OSD

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing(); //Ada.chen 20150609    
    OsdFunc1bitByte0(ROW(_ITEM_4_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_MANUAL_CLOCK);
    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_MANUAL_CLOCK);
    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_MANUAL_PHASE);
}

//Left Key動作(CLK Bar加減處理)
void OsdBarClockK2(void)
{
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, 100, 0, _OFF);
    UserCommonAdjustClock(g_usAdjustValue_1);
    OsdDisplayDrawBar(_ITEM_4_ROW,g_usAdjustValue_1, _Bar_0_100);    
}

//Right Key動作(CLK Bar加減處理)
void OsdBarClockK3(void)
{
    OsdBarClockK2();
}

//Exit Key(離開OSD)
void OsdBarClockK4(void)
{
    UserCommonAdjustClock(g_usBeforeValue);
    SET_VGA_MODE_ADJUST_CLOCK(g_usBeforeValue);           //回到原來的值
    
    SET_Key_Relax_FLAG();
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing(); //Ada.chen 20150609    
    OsdFunc1bitByte0(ROW(_ITEM_4_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_MANUAL_CLOCK);
//    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_MANUAL_PHASE);
//    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, _SUB_MANUAL_CLOCK);
//    OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_MANUAL_PHASE);
}

//-----------------------------------------------
//    (Phase)Phase Bar調整(第四層)處理		
//-----------------------------------------------
//Menu Key(儲存至記憶體)
void OsdBarPhaseK1(void)
{
    //OSD儲存動作
    SET_VGA_MODE_ADJUST_PHASE(g_usAdjustValue_1);
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);       //儲存CLK Data                 
    
    SET_Key_Relax_FLAG();       //離開OSD
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();  //Ada.chen 20150609   
    OsdFunc1bitByte0(ROW(_ITEM_4_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_MANUAL_PHASE);
    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, _SUB_MANUAL_PHASE);
    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, _SUB_MANUAL_CLOCK);
}

//Left Key動作(Phase Bar加減處理)
void OsdBarPhaseK2(void)
{
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, 100, 0, _OFF);
    UserCommonAdjustPhase(g_usAdjustValue_1);
    OsdDisplayDrawBar(_ITEM_4_ROW,g_usAdjustValue_1, _Bar_0_100);        
}

//Right Key動作(Phase Bar加減處理)
void OsdBarPhaseK3(void)
{
    OsdBarPhaseK2();
}

//Exit Key(離開OSD)
void OsdBarPhaseK4(void)
{
    UserCommonAdjustPhase(g_usBeforeValue);
    SET_VGA_MODE_ADJUST_PHASE(g_usBeforeValue);           //回到原來的值
    
    SET_Key_Relax_FLAG();
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing(); //Ada.chen 20150609    
    OsdFunc1bitByte0(ROW(_ITEM_4_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_MANUAL_PHASE);
//    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_MANUAL_CLOCK);
//    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, _SUB_MANUAL_PHASE);
//    OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_MANUAL_CLOCK);
}

//----------------------------------------------------------------------------------
//    (Preset Mode)Preset Mode選擇(第四層)處理: Reddish,sRGB,Neutral,Bluish        
//----------------------------------------------------------------------------------
//Menu Key(確認Preset Mode儲存至記憶體)
void OsdSubNeutralsRGBRedBluK1(void)
{
    SET_COLOR_TEMP_TYPE(g_usAdjustValue_2);
#if((_FACTORY_MODE_OWNER == _OWNER_TPV) || (_FACTORY_MODE_OWNER == _OWNER_FOXCONN))  
	if((GET_COLOR_TEMP_TYPE() >= _CT_7200)&&(GET_COLOR_TEMP_TYPE() <= _CT_9300))
	{
		SET_PRESET_COLOR_TEMP_BACKUP(g_usAdjustValue_2);
	}
#endif
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    //SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);       //儲存CLK Data                 
    
    SET_Key_Relax_FLAG();       //離開OSD

    //回到第一層
    //
    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_SELECT, GET_OSD_STATE());    
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();       
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
    
    SET_OSD_STATE(_SUB_COLOR_PRESET_MODE);
    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

#if(((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))\
	||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))\
	||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
	SET_OSD_STATE(_SUB_COLOR); 
	OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDisplayWaitForDrawing();
    OsdDisplayClearFocusFrame(_ITEM_2_ROW); // 3ms
	OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
	OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
#else
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
#endif

    if(GET_FACTORY_MODE() != _ON)
    {
        if((g_usAdjustValue_2 == _CT_SRGB)
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
     	||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
 #endif
        )
        {
            OsdDisplayItemDraw(_ICON_1_5, _ITEM_UNSELECT, _MAIN_BRI_CON_DCR);
        }
        else
        {
            OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
        }
    }

    SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);    
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
    
}

//Left Key動作(Preset Mode選擇處理)
void OsdSubNeutralsRGBRedBluK2(void)
{
    //g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, _SUB_sRGB, _SUB_NEUTRAL, _ON);
    //OsdAnimationItemAnimation(g_usAdjustValue_1);
    OsdAnimationItemAnimation(GET_OSD_STATE());
    
    switch(GET_OSD_STATE()) 
    {
        case _SUB_NEUTRAL:    //7200
            g_usAdjustValue_2 = _CT_7200;
            break;
            
        case _SUB_BLUISH:     //9300
            g_usAdjustValue_2 = _CT_9300;
            break;
            
        case _SUB_REDDISH:    //6500
            g_usAdjustValue_2 = _CT_6500;
            break;
            
        case  _SUB_sRGB:      //sRGB
            g_usAdjustValue_2 = _CT_SRGB;
            break;              
    }            
    
    RTDNVRamLoadColorSetting(g_usAdjustValue_2);

#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20141025
	SET_COLOR_TEMP_TYPE(g_usAdjustValue_2);
#endif
    if(g_usAdjustValue_2 == _CT_SRGB)
    {
        UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
#if(_ENERGY_STAR_SUPPORT == _ON)//lorimiao 20131218 for ES6.0 test
				if(GET_OSD_ES_STATUS() == _ON)
				{
					SET_OSD_ES_STATUS(_OFF);
					UserCommonAdjustESDcrProcess(GET_OSD_ES_STATUS());
				}
				else
				{
					UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
				}
#else
				UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
#endif
    }
    else
    {
        UserAdjustContrast(GET_OSD_CONTRAST());
#if(_ENERGY_STAR_SUPPORT == _ON)//lorimiao 20131218 for ES6.0 test
				if(GET_OSD_ES_STATUS() == _ON)
				{
					UserCommonAdjustESDcrProcess(GET_OSD_ES_STATUS());
				}
				else
				{
					UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
				}
#else
				UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
#endif
    }    
}

//Right Key動作(Preset Mode選擇處理)
void OsdSubNeutralsRGBRedBluK3(void)
{
    OsdSubNeutralsRGBRedBluK2();
}

//Exit Key(離開OSD)
void OsdSubNeutralsRGBRedBluK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_COLOR_PRESET_MODE);  

#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20141025
	SET_COLOR_TEMP_TYPE(g_usBeforeValue);
#endif
    RTDNVRamLoadColorSetting(g_usBeforeValue);    
    if(g_usBeforeValue == _CT_SRGB)
    {
        UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
#if(_ENERGY_STAR_SUPPORT == _ON)//lorimiao 20131218 for ES6.0 test
				if(GET_OSD_ES_STATUS() == _ON)
				{
					SET_OSD_ES_STATUS(_OFF);
					UserCommonAdjustESDcrProcess(GET_OSD_ES_STATUS());
				}
				else
				{
					UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
				}
#else
				UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
#endif
    }
    else
    {
        UserAdjustContrast(GET_OSD_CONTRAST());
#if(_ENERGY_STAR_SUPPORT == _ON)//lorimiao 20131218 for ES6.0 test
				if(GET_OSD_ES_STATUS() == _ON)
				{
					UserCommonAdjustESDcrProcess(GET_OSD_ES_STATUS());
				}
				else
				{
					UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
				}
#else
				UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
#endif
    }        
//    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_COLOR_CUSTOM);
//    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, _SUB_COLOR_PRESET_MODE);
//    OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_COLOR_CUSTOM);
}

//-------------------------------------------------------------------
//    (Custom)Select Item: 1.Red 2.Green 3.Blue選擇(第四層)處理		
//-------------------------------------------------------------------
//Menu Key(進入第五層)
void OsdSubCustomRGBK1(void)
{
    // 5 layer back ground color
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

    //依據第四層Item目錄畫第五層
    if(GET_OSD_STATE() == _SUB_CUSTOM_R)
    {
        g_usBeforeValue = GET_COLOR_TEMP_TYPE_USER_R();               //(User Color)R調整前值
        g_usAdjustValue_1 = GET_COLOR_TEMP_TYPE_USER_R();           
        SET_OSD_STATE(_BAR_CUSTOM_R);                     
    }
    else if(GET_OSD_STATE() == _SUB_CUSTOM_G)
    {
        g_usBeforeValue = GET_COLOR_TEMP_TYPE_USER_G();               //(User Color)G調整前值
        g_usAdjustValue_1 = GET_COLOR_TEMP_TYPE_USER_G();           
        SET_OSD_STATE(_BAR_CUSTOM_G);
    }
    else if(GET_OSD_STATE() == _SUB_CUSTOM_B)
    {   
        g_usBeforeValue = GET_COLOR_TEMP_TYPE_USER_B();               //(User Color)B調整前值
        g_usAdjustValue_1 = GET_COLOR_TEMP_TYPE_USER_B();   
        SET_OSD_STATE(_BAR_CUSTOM_B);
    }
    
    OsdDisplayDrawBar(_ITEM_5_ROW, UserCommonAdjustRealValueToPercent(g_usAdjustValue_1, _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER), _Bar_0_100);      
}

//Left Key動作(Item選擇處理)
void OsdSubCustomRGBK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key動作(Item選擇處理)
void OsdSubCustomRGBK3(void)
{
    OsdSubCustomRGBK2();
}

//Exit Key(離開OSD)
void OsdSubCustomRGBK4(void)
{
    SET_Key_Relax_FLAG();

#if 1//lorimiao 20141025
	RTDNVRamLoadOSDData();
    RTDNVRamLoadColorSetting( GET_COLOR_TEMP_TYPE());       
    if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
    {
        UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
        UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
    }
    else
    {
        UserAdjustContrast(GET_OSD_CONTRAST());
#if(_ENERGY_STAR_SUPPORT == _ON)
				if(GET_OSD_ES_STATUS() == _ON)
				{
					UserAdjustESBacklight();
				}
				else
				{
					UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
				}
#else
				UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
#endif
    }
#endif
    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_COLOR_CUSTOM);
//    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_COLOR_PRESET_MODE);
//    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, _SUB_COLOR_CUSTOM);
//    OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_COLOR_PRESET_MODE);
}

//-------------------------------------------------------------------------------
//    (Custom)Select Item: 1.(OSD)Horizontal 2.(OSD)Vertical選擇(第四層)處理		
//-------------------------------------------------------------------------------
//Menu Key(進入第五層)
void OsdSubPosCustomHVK1(void)
{
    // 5 layer back ground color
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));

    //依據第四層Item目錄畫第五層
    if(GET_OSD_STATE() == _SUB_POS_CUST_H)
    {
#if 1//lorimiao 20141025
        g_usBeforeValue = GET_OSD_HPOS();
        g_usAdjustValue_1 = GET_OSD_HPOS();   
#endif		
        SET_OSD_STATE(_BAR_POS_CUST_H);
        OsdDisplayItemDraw(_ITEM_5_2, _ITEM_FOCUS, _BAR_POS_CUST_H);
    }
    else if(GET_OSD_STATE() == _SUB_POS_CUST_V)
    {
#if 1//lorimiao 20141025
        g_usBeforeValue = GET_OSD_VPOS();
        g_usAdjustValue_1 = GET_OSD_VPOS(); 
#endif		
        SET_OSD_STATE(_BAR_POS_CUST_V);
        OsdDisplayItemDraw(_ITEM_5_2, _ITEM_FOCUS, _BAR_POS_CUST_V);
    }
}

//Left Key動作(Item選擇處理)
void OsdSubPosCustomHVK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key動作(Item選擇處理)
void OsdSubPosCustomHVK3(void)
{
    OsdSubPosCustomHVK2();
}

//Exit Key(離開OSD)
void OsdSubPosCustomHVK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_POS_CUSTOM);
//    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_POS_DEFAULT);
//    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, _SUB_POS_CUSTOM);
//    OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_POS_DEFAULT);
}

//-------------------------------------------------------------------------------------------------
//    (Button repeat rate)Select Item: 1.Default 2.Slow 3.OFF 選擇(第四層)處理		
//-------------------------------------------------------------------------------------------------
//Menu Key(進入第五層)
void OsdSubRepeatOffDefSlowK1(void)
{   
    if(GET_OSD_STATE() == _SUB_REPEAT_OFF)
    {
       SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_OFF);        
    }
    else if(GET_OSD_STATE() == _SUB_REPEAT_DEFAULT)
    {
        SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_DEFAULT);        
    }    
    else  //_SUB_REPEAT_SLOW 
    {
        SET_OSD_BUTTON_REPEAT_STATUS(_OSD_BUTTON_REPEAT_SLOW);        
    }    
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    
    SET_Key_Relax_FLAG();       //離開OSD

    //回到第一層
    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
   
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_OPTIONS);  
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
}

//Left Key動作(Item選擇處理)
void OsdSubRepeatOffDefSlowK2(void)
{
    OsdAnimationItemAnimation(GET_OSD_STATE());
}

//Right Key動作(Item選擇處理)
void OsdSubRepeatOffDefSlowK3(void)
{
    OsdSubRepeatOffDefSlowK2();
}

//Exit Key(離開OSD)
void OsdSubRepeatOffDefSlowK4(void)
{
    SET_Key_Relax_FLAG();

    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_ACCESS_RATE);
//    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_ACCESS_TIMEOUT);
//    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, _SUB_ACCESS_RATE);
//    OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_ACCESS_TIMEOUT);
}

//----------------------------------------------------------------------------------
//    (Menu time out)Select Item: Time Out Bar調整(第四層)處理		
//----------------------------------------------------------------------------------
//Menu Key(Time out儲存)
void OsdBarMenuTimeOutK1(void)
{
    //OSD儲存動作
    SET_OSD_TIME_OUT(g_usAdjustValue_1);
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);       //儲存TimeOut值                 
    
    SET_Key_Relax_FLAG();       //離開OSD

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdFunc1bitByte0(ROW(_ITEM_4_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
    
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdFunc1bitByte0(ROW(_ITEM_3_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));
   
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();    
    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_MAIN_OPTIONS);  
    OsdDisplayMainMenuDescription(GET_OSD_STATE());
    OsdDisplayDispButton(_KEY_INFO_EXIT);
}

//Left Key動作(Item選擇處理)
void OsdBarMenuTimeOutK2(void)
{    
    //TimeOut調整
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, 60, 5, _OFF);
    OsdDisplayDrawBar(_ITEM_4_ROW,g_usAdjustValue_1, _Bar_5_60);        
}

//Right Key動作(Item選擇處理)
void OsdBarMenuTimeOutK3(void)
{
    OsdBarMenuTimeOutK2();
}

//Exit Key(離開OSD)
void OsdBarMenuTimeOutK14(void)
{
    SET_OSD_TIME_OUT(g_usBeforeValue);               //回到原來的值            
    
    SET_Key_Relax_FLAG();

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitByte0(ROW(_ITEM_4_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_ACCESS_TIMEOUT);
//    OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, _SUB_ACCESS_RATE);
//    OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, _SUB_ACCESS_TIMEOUT);
//    OsdDisplayItemDraw(_ITEM_3_3, _ITEM_SELECT, _SUB_ACCESS_RATE);
}

//====================================================================================================
//                                   第五層處理
//====================================================================================================
//-----------------------------------------------
//    (Custom->Red)Red Bar調整(第五層)處理		
//-----------------------------------------------
//Menu Key(Red Bar值儲存)
void OsdBarCustomRK1(void)
{
    //OSD儲存動作
    SET_COLOR_TEMP_TYPE(_CT_USER);                  //儲存Custom Red值
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    SET_COLOR_TEMP_TYPE_USER_R(g_usAdjustValue_1); 
    RTDNVRamSaveColorSetting(_CT_USER);       
	//UserAdjustContrast(GET_OSD_CONTRAST());                
    
    SET_Key_Relax_FLAG();       //離開OSD

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_CUSTOM_R);
    //OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_CUSTOM_B);
    //OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_CUSTOM_R);
    //OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_CUSTOM_G);
    OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
}

//Left Key動作(Red Bar值調整)
void OsdBarCustomRK2(void)
{   
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _OFF);
    SET_COLOR_TEMP_TYPE_USER_R(g_usAdjustValue_1);    
    OsdDisplayDrawBar(_ITEM_5_ROW, UserCommonAdjustRealValueToPercent(g_usAdjustValue_1, _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER), _Bar_0_100); 
    UserAdjustContrast(GET_OSD_CONTRAST());
}

//Right Key動作(Red Bar值調整)
void OsdBarCustomRK3(void)
{
    OsdBarCustomRK2();
}

//Exit Key(離開OSD)
void OsdBarCustomRK4(void)
{
    SET_COLOR_TEMP_TYPE_USER_R(g_usBeforeValue);    //回到原來的值
	UserAdjustContrast(GET_OSD_CONTRAST());
    
    SET_Key_Relax_FLAG();

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_CUSTOM_R);
//    OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_CUSTOM_B);
//    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_CUSTOM_R);
//    OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_CUSTOM_G);
}

//-----------------------------------------------
//    (Custom->Green)Green Bar調整(第五層)處理		
//-----------------------------------------------
//Menu Key(Green Bar值儲存)
void OsdBarCustomGK1(void)
{
    SET_COLOR_TEMP_TYPE(_CT_USER);                  //儲存Custom Red值
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    SET_COLOR_TEMP_TYPE_USER_G(g_usAdjustValue_1); 
    RTDNVRamSaveColorSetting(_CT_USER);                     
    
    SET_Key_Relax_FLAG();       //離開OSD

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_CUSTOM_G);
    //OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_CUSTOM_R);
    //OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_CUSTOM_G);
    //OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_CUSTOM_B);
    OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
}

//Left Key動作(Green Bar值調整)
void OsdBarCustomGK2(void)
{
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _OFF);
    SET_COLOR_TEMP_TYPE_USER_G(g_usAdjustValue_1);        
    OsdDisplayDrawBar(_ITEM_5_ROW, UserCommonAdjustRealValueToPercent(g_usAdjustValue_1, _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER), _Bar_0_100); 
    UserAdjustContrast(GET_OSD_CONTRAST());
}

//Right Key動作(Green Bar值調整)
void OsdBarCustomGK3(void)
{
    OsdBarCustomGK2();
}

//Exit Key(離開OSD)
void OsdBarCustomGK4(void)
{

    SET_COLOR_TEMP_TYPE_USER_G(g_usBeforeValue);    //回到原來的值
	UserAdjustContrast(GET_OSD_CONTRAST());
    
    SET_Key_Relax_FLAG();

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_CUSTOM_G);
    //OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_CUSTOM_R);
    //OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_CUSTOM_G);
    //OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_CUSTOM_B);
}

//-----------------------------------------------
//    (Custom->Blue)Blue Bar調整(第五層)處理		
//-----------------------------------------------
void OsdBarCustomBK1(void)
{
    //OSD儲存動作
    SET_COLOR_TEMP_TYPE(_CT_USER);                  //儲存Custom Red值
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    SET_COLOR_TEMP_TYPE_USER_B(g_usAdjustValue_1); 
    RTDNVRamSaveColorSetting(_CT_USER);                                 
    
    SET_Key_Relax_FLAG();       //離開OSD

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_CUSTOM_B);
    //OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_CUSTOM_G);
    //OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_CUSTOM_B);
    //OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_CUSTOM_R);
    OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_BRI_CON_DCR);
}

void OsdBarCustomBK2(void)
{
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _OFF);
    SET_COLOR_TEMP_TYPE_USER_B(g_usAdjustValue_1);    
    OsdDisplayDrawBar(_ITEM_5_ROW, UserCommonAdjustRealValueToPercent(g_usAdjustValue_1, _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER), _Bar_0_100); 
    UserAdjustContrast(GET_OSD_CONTRAST());
}

void OsdBarCustomBK3(void)
{
    OsdBarCustomBK2();
}

//Exit Key(離開OSD)
void OsdBarCustomBK4(void)
{
    SET_COLOR_TEMP_TYPE_USER_B(g_usBeforeValue);    //回到原來的值
	UserAdjustContrast(GET_OSD_CONTRAST());
    
    SET_Key_Relax_FLAG();

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_CUSTOM_B);
    //OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_CUSTOM_G);
    //OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_CUSTOM_B);
    //OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_CUSTOM_R);
}

//====================================================================================================
void OsdBarPosCustomHK1(void)
{
    SET_Key_Relax_FLAG();  
#if 1//lorimiao 20141025
    SET_OSD_HPOS(g_usAdjustValue_1); 
#endif	
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    
    OsdDisplayItemDraw(_ITEM_5_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_POS_CUST_H);
//    OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_POS_CUST_V);
//    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_POS_CUST_H);
//    OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_POS_CUST_V);
}

void OsdBarPosCustomHK2(void)
{
    //SET_OSD_HPOS(OsdDisplayDetOverRange(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OFF));
#if 1//lorimiao 20141025
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OFF);
    OsdDisplaySetPosition(_MAIN_OSD, g_usAdjustValue_1, GET_OSD_VPOS());
#else	
    SET_OSD_HPOS(OsdDisplayDetOverRange(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OFF));    
    OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());
#endif	
}

void OsdBarPosCustomHK3(void)
{
    OsdBarPosCustomHK2();
}

//Exit Key(離開OSD)
void OsdBarPosCustomHK4(void)
{
    SET_Key_Relax_FLAG();
#if 1//lorimiao 20141025
    SET_OSD_HPOS(g_usBeforeValue);
    OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());
#endif	

    OsdDisplayItemDraw(_ITEM_5_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_POS_CUST_H);
//    OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_POS_CUST_V);
//    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_POS_CUST_H);
//    OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_POS_CUST_V);
}

//====================================================================================================
void OsdBarPosCustomVK1(void)
{
    SET_Key_Relax_FLAG();
#if 1//lorimiao 20141025
    SET_OSD_VPOS(g_usAdjustValue_1); 
#endif	
    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    
    OsdDisplayItemDraw(_ITEM_5_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_POS_CUST_V);
//    OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_POS_CUST_H);
//    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_POS_CUST_V);
//    OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_POS_CUST_H);
}

void OsdBarPosCustomVK2(void)
{
    //SET_OSD_VPOS(OsdDisplayDetOverRange(GET_OSD_VPOS(), _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OFF));
#if 1//lorimiao 20141025
    g_usAdjustValue_1 = OsdDisplayDetOverRange(g_usAdjustValue_1, _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OFF);
    OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), g_usAdjustValue_1);
#else	
    SET_OSD_VPOS(OsdDisplayDetOverRange(GET_OSD_VPOS(), _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OFF));
    OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());
#endif	
}

void OsdBarPosCustomVK3(void)
{
    OsdBarPosCustomVK2();
}

//Exit Key(離開OSD)
void OsdBarPosCustomVK4(void)
{
    SET_Key_Relax_FLAG();
#if 1//lorimiao 20141025
    SET_OSD_VPOS(g_usBeforeValue);
    OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());
#endif	

    OsdDisplayItemDraw(_ITEM_5_2, _ITEM_SELECT, GET_OSD_STATE());
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();
    
    OsdFunc1bitByte0(ROW(_ITEM_5_ROW - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), FGCOLOR(_CP_BG), BGCOLOR(_CP_BG));
    OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(3), CHAR(___));

    SET_OSD_STATE(_SUB_POS_CUST_V);
//    OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, _SUB_POS_CUST_H);
//    OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, _SUB_POS_CUST_V);
//    OsdDisplayItemDraw(_ITEM_4_3, _ITEM_SELECT, _SUB_POS_CUST_H);
}

//--------------------------------------------------
// Description  : OSD Timeout Save Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdTimeoutSaveData(void)
{
    if((GET_OSD_STATE() == _BAR_BRI) || (GET_OSD_STATE() ==  _HOTKEY_BAR_BRI))
    {
        SET_OSD_BACKLIGHT(g_usAdjustValue_1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);  //儲存Bri Data   
    }  
    else if(GET_OSD_STATE() ==_BAR_CON)
    {
        SET_OSD_CONTRAST(g_usAdjustValue_1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);       //儲存Con Data 
    }   
    else if(GET_OSD_STATE() ==_BAR_H_POSITION)
    {        
        SET_VGA_MODE_ADJUST_H_POSITION(g_usAdjustValue_1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG); //儲存H Postion Data 
    }    
    else if(GET_OSD_STATE() ==_BAR_V_POSITION)    
    {
        SET_VGA_MODE_ADJUST_V_POSITION(g_usAdjustValue_1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG); //儲存H Postion Data 
    }       
    else if(GET_OSD_STATE() ==_BAR_MENU_TIMEOUT)    
    {
        SET_OSD_TIME_OUT(g_usAdjustValue_1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);   //儲存TimeOut值    
    }
    else if(GET_OSD_STATE() == _BAR_CLOCK)
    {
        SET_VGA_MODE_ADJUST_CLOCK(g_usAdjustValue_1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
    }
    else if(GET_OSD_STATE() == _BAR_PHASE)
    {
        SET_VGA_MODE_ADJUST_PHASE(g_usAdjustValue_1);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
    }
    else if((GET_OSD_STATE() >= _SUB_NEUTRAL) && (GET_OSD_STATE() <= _SUB_sRGB))
    {
        SET_COLOR_TEMP_TYPE(g_usAdjustValue_2);
#if((_FACTORY_MODE_OWNER == _OWNER_TPV) || (_FACTORY_MODE_OWNER == _OWNER_FOXCONN))   
		if((GET_COLOR_TEMP_TYPE() >= _CT_7200)&&(GET_COLOR_TEMP_TYPE() <= _CT_9300))
		{
			SET_PRESET_COLOR_TEMP_BACKUP(g_usAdjustValue_2);
		}
#endif
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
	else if((GET_OSD_STATE() == _SUB_CUSTOM_R)||(GET_OSD_STATE() == _SUB_CUSTOM_G)||(GET_OSD_STATE() == _SUB_CUSTOM_B))//jason.cheng 20140205_1 modify follow TPV richer request 
	{
		SET_COLOR_TEMP_TYPE(_CT_USER);									  
		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
	}
    else if(GET_OSD_STATE() ==_BAR_CUSTOM_R)
    {
         SET_COLOR_TEMP_TYPE(_CT_USER);                                    //儲存Custom Red值
         SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
         SET_COLOR_TEMP_TYPE_USER_R(g_usAdjustValue_1); 
         RTDNVRamSaveColorSetting(_CT_USER);       
    }
    else if(GET_OSD_STATE() ==_BAR_CUSTOM_G) 
    {
         SET_COLOR_TEMP_TYPE(_CT_USER);                                    //儲存Custom Green值
         SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
         SET_COLOR_TEMP_TYPE_USER_G(g_usAdjustValue_1); 
         RTDNVRamSaveColorSetting(_CT_USER);       
    }
    else if(GET_OSD_STATE() ==_BAR_CUSTOM_B)
    {
         SET_COLOR_TEMP_TYPE(_CT_USER);                                    //儲存Custom Blue值
         SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
         SET_COLOR_TEMP_TYPE_USER_B(g_usAdjustValue_1); 
         RTDNVRamSaveColorSetting(_CT_USER);       
    }
    else if(GET_OSD_STATE() ==_BAR_POS_CUST_H)    
    {
        SET_OSD_HPOS(g_usAdjustValue_1);
         SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    else if(GET_OSD_STATE() ==_BAR_POS_CUST_V)    
    {
        SET_OSD_VPOS(g_usAdjustValue_1);
         SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
#if(_USER_DCR_FUNCTION == _ON)	
    else if(GET_OSD_STATE() == _SUB_DCR_ON)
    {
        if(GET_OSD_DCR_STATUS() == _OFF)
    	{            
            UserAdjustDCRControl(_ON);
            SET_OSD_DCR_STATUS(_ON);
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        }
    }  
    else if(GET_OSD_STATE() == _SUB_DCR_OFF)    
    {
        if(GET_OSD_DCR_STATUS() == _ON)
    	{            
            UserAdjustDCRControl(_OFF);
            SET_OSD_DCR_STATUS(_OFF);
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        }
    } 
#endif
#if(_OD_MULTI_SELECT == _ON)

#else
#if(_OD_OSD_SUPPORT == _ON)    
    else if(GET_OSD_STATE() == _SUB_OD_ON)
    {           
        if(GET_OSD_OD_STATUS() == _OFF)
    	{            
            SET_OSD_OD_STATUS(_ON);
            ScalerODControl(_ON);
            ScalerODAdjustDeltaGain(GET_OSD_OD_GAIN());            
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            
        }
    }   
    else if(GET_OSD_STATE() == _SUB_OD_OFF)        
    {        
        if(GET_OSD_OD_STATUS() == _ON)
    	{            
            SET_OSD_OD_STATUS(_OFF);
            ScalerODControl(_OFF);            
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            
        }
    }  
#endif
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
    else if(GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON)
    {           
        if(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF)
    	{            
            SET_OSD_LOW_BLUE_LIGHT_STATUS(_ON);
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            
        }
    }   
    else if(GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)        
    {        
        if(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)
    	{            
            SET_OSD_LOW_BLUE_LIGHT_STATUS(_OFF);
    		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);            
        }
    }  
#endif

    else if((GET_OSD_STATE() == _SUB_CUSTOM_R) || (GET_OSD_STATE() == _SUB_CUSTOM_G) || (GET_OSD_STATE() == _SUB_CUSTOM_B))
    {          
        SET_COLOR_TEMP_TYPE(g_usBeforeValue);  
        if(g_usBeforeValue != _CT_USER)
        {
            RTDNVRamLoadColorSetting(GET_PRESET_COLOR_TEMP_BACKUP());    
            if(g_usBeforeValue == _CT_SRGB)
            {
                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
                UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
            }
            else
            {
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            } 
        }
    }        
}

//--------------------------------------------------
// Description  : OSD Table Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
code void (*OperationTable[][5])(void) =
{
    //Menu=K1                               //Left=K2                               //Right=K3                              //Exit=K4
    { OsdNoneMenu,                        	OsdNoneLeft,                         	OsdNoneRight,                        	OsdNoneExit,                     	OsdNoneSource},

    //Level 1
    //Main Item
    { OsdMainItemK1,              	        OsdMainItemK2,                	        OsdMainItemK3,                	        OsdMainItemK4,            	        OsdNull},
    { OsdMainItemK1,              	        OsdMainItemK2,                	        OsdMainItemK3,                	        OsdMainItemK4,            	        OsdNull},
    { OsdMainItemK1,              	        OsdMainItemK2,                	        OsdMainItemK3,                	        OsdMainItemK4,            	        OsdNull},
    { OsdMainItemK1,              	        OsdMainItemK2,                	        OsdMainItemK3,                	        OsdMainItemK4,            	        OsdNull},
    { OsdMainItemK1,              	        OsdMainItemK2,                	        OsdMainItemK3,                	        OsdMainItemK4,            	        OsdNull},
    //20120517 Abel Factory Mode Modify   
    { OsdMainItemK1,              	        OsdMainItemK2,                	        OsdMainItemK3,                	        OsdMainItemK4,            	        OsdNull},
    //Robert Wang 20121213 for Factory
    { OsdMainMenuTPVFactory,              	OsdMainMenuTPVFactory,                	OsdMainMenuTPVFactory,                	OsdMainMenuTPVFactory,            	OsdNull},

    //Level 2
    //Sub Item
    { OsdSubBriConDcrItemK1,                OsdSubBriConDcrItemK2,                  OsdSubBriConDcrItemK3,                  OsdSubBriConDcrItemK4,              OsdNull},
    { OsdSubBriConDcrItemK1,                OsdSubBriConDcrItemK2,                  OsdSubBriConDcrItemK3,                  OsdSubBriConDcrItemK4,              OsdNull},
#if(_USER_DCR_FUNCTION == _ON)
	{ OsdSubBriConDcrItemK1,                OsdSubBriConDcrItemK2,                  OsdSubBriConDcrItemK3,                  OsdSubBriConDcrItemK4,              OsdNull},
#endif
    { OsdSubHVPosItemK1,                    OsdSubHVPosItemK2,                      OsdSubHVPosItemK3,                      OsdSubHVPosItemK4,                  OsdNull},
    { OsdSubHVPosItemK1,                    OsdSubHVPosItemK2,                      OsdSubHVPosItemK3,                      OsdSubHVPosItemK4,                  OsdNull},

    { OsdSubAutoManualItemK1,               OsdSubAutoManualItemK2,                 OsdSubAutoManualItemK3,                 OsdSubAutoManualItemK4,             OsdNull},
    { OsdSubAutoManualItemK1,               OsdSubAutoManualItemK2,                 OsdSubAutoManualItemK3,                 OsdSubAutoManualItemK4,             OsdNull},

    { OsdSubColorInputScalingItemK1,        OsdSubColorInputScalingItemK2,          OsdSubColorInputScalingItemK3,          OsdSubColorInputScalingItemK4,      OsdNull},

#if(_INPUT_PORT_MAX > 0x01)
    { OsdSubColorInputScalingItemK1,        OsdSubColorInputScalingItemK2,          OsdSubColorInputScalingItemK3,          OsdSubColorInputScalingItemK4,      OsdNull},
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
    { OsdSubColorInputScalingItemK1,        OsdSubColorInputScalingItemK2,          OsdSubColorInputScalingItemK3,          OsdSubColorInputScalingItemK4,      OsdNull},
#endif

#if(_OD_OSD_SUPPORT == _ON)
    { OsdSubColorInputScalingItemK1,        OsdSubColorInputScalingItemK2,          OsdSubColorInputScalingItemK3,          OsdSubColorInputScalingItemK4,      OsdNull},
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
    { OsdSubColorInputScalingItemK1,        OsdSubColorInputScalingItemK2,          OsdSubColorInputScalingItemK3,          OsdSubColorInputScalingItemK4,      OsdNull},
#endif

    { OsdSubInfoLanPosFactAccItemK1,        OsdSubInfoLanPosFactAccItemK2,          OsdSubInfoLanPosFactAccItemK3,          OsdSubInfoLanPosFactAccItemK4,      OsdNull},
#if(_LANGUAGE_TYPE != _1_LAN)
    { OsdSubInfoLanPosFactAccItemK1,        OsdSubInfoLanPosFactAccItemK2,          OsdSubInfoLanPosFactAccItemK3,          OsdSubInfoLanPosFactAccItemK4,      OsdNull},
#endif
    { OsdSubInfoLanPosFactAccItemK1,        OsdSubInfoLanPosFactAccItemK2,          OsdSubInfoLanPosFactAccItemK3,          OsdSubInfoLanPosFactAccItemK4,      OsdNull},
    { OsdSubInfoLanPosFactAccItemK1,        OsdSubInfoLanPosFactAccItemK2,          OsdSubInfoLanPosFactAccItemK3,          OsdSubInfoLanPosFactAccItemK4,      OsdNull},
    { OsdSubInfoLanPosFactAccItemK1,        OsdSubInfoLanPosFactAccItemK2,          OsdSubInfoLanPosFactAccItemK3,          OsdSubInfoLanPosFactAccItemK4,      OsdNull},
#if (_DP_SUPPORT == _ON)
    { OsdSubInfoLanPosFactAccItemK1,        OsdSubInfoLanPosFactAccItemK2,          OsdSubInfoLanPosFactAccItemK3,          OsdSubInfoLanPosFactAccItemK4,      OsdNull},
#endif

    //Level 3
    { OsdBarBriK1,                          OsdBarBriK2,                            OsdBarBriK3,                            OsdBarBriK4,                        OsdNull},
    { OsdBarConK1,                          OsdBarConK2,                            OsdBarConK3,                            OsdBarConK4,                        OsdNull},
#if(_USER_DCR_FUNCTION == _ON)
    { OsdSubDcrOnOffK1,                     OsdSubDcrOnOffK2,                       OsdSubDcrOnOffK3,                       OsdSubDcrOnOffK4,                   OsdNull},
    { OsdSubDcrOnOffK1,                     OsdSubDcrOnOffK2,                       OsdSubDcrOnOffK3,                       OsdSubDcrOnOffK4,                   OsdNull},
#endif
#if (_LOW_BLUE_LIGHT_FUNCTION == _ON)
    { OsdSubLowBlueLightOnOffK1,            OsdSubLowBlueLightOnOffK2,              OsdSubLowBlueLightOnOffK3,              OsdSubLowBlueLightOnOffK4,          OsdNull,  },
    { OsdSubLowBlueLightOnOffK1,            OsdSubLowBlueLightOnOffK2,              OsdSubLowBlueLightOnOffK3,              OsdSubLowBlueLightOnOffK4,          OsdNull,  },
#endif

    { OsdBarHPositionK1,                    OsdBarHPositionK2,                      OsdBarHPositionK3,                      OsdBarHPositionK4,                  OsdNull},
    { OsdBarVPositionK1,                    OsdBarVPositionK2,                      OsdBarVPositionK3,                      OsdBarVPositionK4,                  OsdNull},

    { OsdSubClockPhaseK1,                   OsdSubClockPhaseK2,                     OsdSubClockPhaseK3,                     OsdSubClockPhaseK4,                 OsdNull},
    { OsdSubClockPhaseK1,                   OsdSubClockPhaseK2,                     OsdSubClockPhaseK3,                     OsdSubClockPhaseK4,                 OsdNull},

    { OsdSubPresetCustomK1,                 OsdSubPresetCustomK2,                   OsdSubPresetCustomK3,                   OsdSubPresetCustomK4,               OsdNull},
    { OsdSubPresetCustomK1,                 OsdSubPresetCustomK2,                   OsdSubPresetCustomK3,                   OsdSubPresetCustomK4,               OsdNull},

#if(_INPUT_PORT_MAX > 0x01)
    { OsdSubAnalogDviHdmiK1,                OsdSubAnalogDviHdmiK2,                  OsdSubAnalogDviHdmiK3,                  OsdSubAnalogDviHdmiK4,              OsdNull},
    { OsdSubAnalogDviHdmiK1,                OsdSubAnalogDviHdmiK2,                  OsdSubAnalogDviHdmiK3,                  OsdSubAnalogDviHdmiK4,              OsdNull},
    { OsdSubAnalogDviHdmiK1,                OsdSubAnalogDviHdmiK2,                  OsdSubAnalogDviHdmiK3,                  OsdSubAnalogDviHdmiK4,              OsdNull},
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
    { OsdSubScalingOnOffK1,                 OsdSubScalingOnOffK2,                   OsdSubScalingOnOffK3,                   OsdSubScalingOnOffK4,               OsdNull},
    { OsdSubScalingOnOffK1,                 OsdSubScalingOnOffK2,                   OsdSubScalingOnOffK3,                   OsdSubScalingOnOffK4,               OsdNull},
#endif

#if(_OD_OSD_SUPPORT == _ON)
#if(_OD_MULTI_SELECT == _ON)
	{ OsdSubOdSelectK1, 					OsdSubOdSelectK2,						OsdSubOdSelectK3,						OsdSubOdSelectK4,					 OsdNull},
	{ OsdSubOdSelectK1, 					OsdSubOdSelectK2,						OsdSubOdSelectK3,						OsdSubOdSelectK4,					 OsdNull},
	{ OsdSubOdSelectK1, 					OsdSubOdSelectK2,						OsdSubOdSelectK3,						OsdSubOdSelectK4,					 OsdNull},
#else
    { OsdSubOdOnOffK1,                      OsdSubOdOnOffK2,                        OsdSubOdOnOffK3,                        OsdSubOdOnOffK4,                    OsdNull},
    { OsdSubOdOnOffK1,                      OsdSubOdOnOffK2,                        OsdSubOdOnOffK3,                        OsdSubOdOnOffK4,                    OsdNull},
#endif
#endif

    { OsdSubInformationK1,                  OsdSubInformationK2,                    OsdSubInformationK3,                    OsdSubInformationK4,                OsdNull},
#if(_LANGUAGE_TYPE != _1_LAN)
    { OsdSubLan12345678K1,                  OsdSubLan12345678K2,                    OsdSubLan12345678K3,                    OsdSubLan12345678K4,                OsdNull},
    { OsdSubLan12345678K1,                  OsdSubLan12345678K2,                    OsdSubLan12345678K3,                    OsdSubLan12345678K4,                OsdNull},
    { OsdSubLan12345678K1,                  OsdSubLan12345678K2,                    OsdSubLan12345678K3,                    OsdSubLan12345678K4,                OsdNull},
    { OsdSubLan12345678K1,                  OsdSubLan12345678K2,                    OsdSubLan12345678K3,                    OsdSubLan12345678K4,                OsdNull},
    { OsdSubLan12345678K1,                  OsdSubLan12345678K2,                    OsdSubLan12345678K3,                    OsdSubLan12345678K4,                OsdNull},
    { OsdSubLan12345678K1,                  OsdSubLan12345678K2,                    OsdSubLan12345678K3,                    OsdSubLan12345678K4,                OsdNull},
    { OsdSubLan12345678K1,                  OsdSubLan12345678K2,                    OsdSubLan12345678K3,                    OsdSubLan12345678K4,                OsdNull},
    { OsdSubLan12345678K1,                  OsdSubLan12345678K2,                    OsdSubLan12345678K3,                    OsdSubLan12345678K4,                OsdNull},
#endif
    { OsdSubDefaultCustomK1,                OsdSubDefaultCustomK2,                  OsdSubDefaultCustomK3,                  OsdSubDefaultCustomK4,              OsdNull},
    { OsdSubDefaultCustomK1,                OsdSubDefaultCustomK2,                  OsdSubDefaultCustomK3,                  OsdSubDefaultCustomK4,              OsdNull},

    { OsdSubFactCancelResetK1,              OsdSubFactCancelResetK2,                OsdSubFactCancelResetK3,                OsdSubFactCancelResetK4,            OsdNull},
    { OsdSubFactCancelResetK1,              OsdSubFactCancelResetK2,                OsdSubFactCancelResetK3,                OsdSubFactCancelResetK4,            OsdNull},

    { OsdSubRepeatMenuTimeK1,               OsdSubRepeatMenuTimeK2,                 OsdSubRepeatMenuTimeK3,                 OsdSubRepeatMenuTimeK4,             OsdNull},
    { OsdSubRepeatMenuTimeK1,               OsdSubRepeatMenuTimeK2,                 OsdSubRepeatMenuTimeK3,                 OsdSubRepeatMenuTimeK4,             OsdNull},

#if (_DP_SUPPORT == _ON)
    { OsdSubDpSelectK1,                     OsdSubDpSelectK2,                       OsdSubDpSelectK3,                       OsdSubDpSelectK4,                   OsdNull},
    { OsdSubDpSelectK1,                     OsdSubDpSelectK2,                       OsdSubDpSelectK3,                       OsdSubDpSelectK4,                   OsdNull},
#endif

    //Level 4
    { OsdBarClockK1,                        OsdBarClockK2,                          OsdBarClockK3,                          OsdBarClockK4,                      OsdNull},
    { OsdBarPhaseK1,                        OsdBarPhaseK2,                          OsdBarPhaseK3,                          OsdBarPhaseK4,                      OsdNull},

    { OsdSubNeutralsRGBRedBluK1,            OsdSubNeutralsRGBRedBluK2,              OsdSubNeutralsRGBRedBluK3,              OsdSubNeutralsRGBRedBluK4,          OsdNull},
    { OsdSubNeutralsRGBRedBluK1,            OsdSubNeutralsRGBRedBluK2,              OsdSubNeutralsRGBRedBluK3,              OsdSubNeutralsRGBRedBluK4,          OsdNull},
    { OsdSubNeutralsRGBRedBluK1,            OsdSubNeutralsRGBRedBluK2,              OsdSubNeutralsRGBRedBluK3,              OsdSubNeutralsRGBRedBluK4,          OsdNull},
    { OsdSubNeutralsRGBRedBluK1,            OsdSubNeutralsRGBRedBluK2,              OsdSubNeutralsRGBRedBluK3,              OsdSubNeutralsRGBRedBluK4,          OsdNull},

    { OsdSubCustomRGBK1,                    OsdSubCustomRGBK2,                      OsdSubCustomRGBK3,                      OsdSubCustomRGBK4,                  OsdNull},
    { OsdSubCustomRGBK1,                    OsdSubCustomRGBK2,                      OsdSubCustomRGBK3,                      OsdSubCustomRGBK4,                  OsdNull},
    { OsdSubCustomRGBK1,                    OsdSubCustomRGBK2,                      OsdSubCustomRGBK3,                      OsdSubCustomRGBK4,                  OsdNull},

    { OsdSubPosCustomHVK1,                  OsdSubPosCustomHVK2,                    OsdSubPosCustomHVK3,                    OsdSubPosCustomHVK4,                OsdNull},
    { OsdSubPosCustomHVK1,                  OsdSubPosCustomHVK2,                    OsdSubPosCustomHVK3,                    OsdSubPosCustomHVK4,                OsdNull},

    { OsdSubRepeatOffDefSlowK1,             OsdSubRepeatOffDefSlowK2,               OsdSubRepeatOffDefSlowK3,               OsdSubRepeatOffDefSlowK4,           OsdNull},
    { OsdSubRepeatOffDefSlowK1,             OsdSubRepeatOffDefSlowK2,               OsdSubRepeatOffDefSlowK3,               OsdSubRepeatOffDefSlowK4,           OsdNull},
    { OsdSubRepeatOffDefSlowK1,             OsdSubRepeatOffDefSlowK2,               OsdSubRepeatOffDefSlowK3,               OsdSubRepeatOffDefSlowK4,           OsdNull},

    { OsdBarMenuTimeOutK1,                  OsdBarMenuTimeOutK2,                    OsdBarMenuTimeOutK3,                    OsdBarMenuTimeOutK14,               OsdNull},

    //Level 5
    { OsdBarCustomRK1,                      OsdBarCustomRK2,                        OsdBarCustomRK3,                        OsdBarCustomRK4,                    OsdNull},
    { OsdBarCustomGK1,                      OsdBarCustomGK2,                        OsdBarCustomGK3,                        OsdBarCustomGK4,                    OsdNull},
    { OsdBarCustomBK1,                      OsdBarCustomBK2,                        OsdBarCustomBK3,                        OsdBarCustomBK4,                    OsdNull},

    { OsdBarPosCustomHK1,                   OsdBarPosCustomHK2,                     OsdBarPosCustomHK3,                     OsdBarPosCustomHK4,                 OsdNull},
    { OsdBarPosCustomVK1,                   OsdBarPosCustomVK2,                     OsdBarPosCustomVK3,                     OsdBarPosCustomVK4,                 OsdNull},

    //Hotkey    
    { OsdMainItemK4,                        OsdMainItemK4,                          OsdMainItemK4,                          OsdMainItemK4,                      OsdNull},    
    { OsdHotKeyBarBriK1,                    OsdBarBriK2,                            OsdBarBriK3,                            OsdBarBriK4,                        OsdNull},

};


#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
