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

#if(_OSD_TYPE == _REALTEK_2011_OSD)

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

WORD g_usAdjustValue = 0; //Eli test
WORD g_usBackupValue = 0; //Eli test
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserOsdHandler(void);
void RTDOsdSystemFlowProc(void);
void RTDOsdEventMsgProc(void);

//***************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : OSD Handler, executed in the main loop
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserOsdHandler(void)
{
    RTDOsdSystemFlowProc();
    RTDOsdEventMsgProc();
}

//--------------------------------------------------
// Description  : OSD system flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDOsdSystemFlowProc(void)
{        
    switch(SysModeGetModeState())
    {
        case _MODE_STATUS_POWER_OFF:

            if(SysModeGetModeStateChange() == _TRUE)
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
            }
            
            break;        
            
        case _MODE_STATUS_INITIAL:

            if(SysModeGetModeStateChange() == _TRUE)
            {
                RTDOsdDisplayShowLogo();    
                UserInterfacePanelPowerAction(_BACKLIGHT_ON);
                ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO);

#if(_SUPER_LOW_POWER_SUPPORT == _ON)
                ScalerSLPFilterKeyEvent();
#endif
            }
            
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
            }    
            
            break;
            
        case _MODE_STATUS_DISPLAY_SETTING:
            
            break;
            
        case _MODE_STATUS_ACTIVE:

            if(SysModeGetModeStateChange()== _TRUE)                
            {
                UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
            }

#if(_ENERGY_STAR_SUPPORT == _ON)
            if(GET_OSD_ES_STATUS() == _ON)
            {
                UserCommonAdjustESDcrAdjust();
            }
#endif
            break;
            
        case _MODE_STATUS_NOSUPPORT:

            if(SysModeGetModeStateChange()== _TRUE)
            {
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSUPPORT_MSG);
                UserInterfaceKeyPadLedControl(_LED_POWER_NOSUPPORT);
            }

            break;
            
        case _MODE_STATUS_NOSIGNAL:

            if(SysModeGetModeStateChange()== _TRUE)
            {
                if(SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT)))
                {
                    ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
                }
                else
                {
                    ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
                }
            }

            break;
            
        case _MODE_STATUS_POWER_SAVING:

            if(SysSourceGetCableDetect(SysSourceGetInputPort()) == _FALSE)
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
            }
            
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

            break;

        case _MODE_STATUS_FACTORY:

            break;
            
        default:

            break;
    }

    if(GET_KEYMESSAGE() < _KEY_AMOUNT)
    {
        if(GET_OSD_IN_FACTORY_MENU_STATUS() == _TRUE)
        {
            RTDFactoryMenuOperation();
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
        }
        else    
        {
            RTDOsdDispPressKey();
            (*OperationTable[GET_OSD_STATE()][GET_KEYMESSAGE()])();

            if((GET_OSD_STATE() >= _OSD_AUTO_SOURCE_HOTKEY) && 
                (GET_OSD_STATE() < _MAIN_MENU_STATE_END) && 
                ((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING) || (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL)))
            {
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
                ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
            }
            else//(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
                ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
            }

            if(GET_OSD_IN_FACTORY_MENU_STATUS())
            {
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
            }            
        }
    }        
}

//--------------------------------------------------
// Description  : OSD event message processing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDOsdEventMsgProc(void)
{
    switch(GET_OSD_EVENT_MESSAGE())
    {
        case _OSDEVENT_SHOW_NOSIGNAL_MSG:
                    
            RTDOsdDisplayNoSignalProc();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);

            break;

        case _OSDEVENT_SHOW_NOCABLE_MSG:
            
            RTDOsdDisplayNoCableProc();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
            
            break;

        case _OSDEVENT_SHOW_NOSUPPORT_MSG:
            
            RTDOsdDisplayNoSupportProc();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);

            break;

        case _OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG:
            
            RTDOsdDisplayFailSafeProc();
            
            break;        

        case _OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG:

            RTDOsdDisplayWakeUpShowSource();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);

            break;

        case _OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG:

            RTDOsdDisplayWakeUpSwitchDdcciPort();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);

            break;

        case _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG:

            RTDOsdDisplayPowerSavingProc();
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);

            break;

        case _OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG:

            RTDOsdDisplayDisableOsd();
            if((SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) || (SysPowerGetPowerStatus() == _POWER_STATUS_NOSUPPORT_SAVING))
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
            
            RTDOsdDisplayAutoProc();
            
            break;
#endif

        case _OSDEVENT_ACTIVE_DO_ONE_TIME_MSG:
            
#if(_VGA_SUPPORT == _ON) 
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {                
                if(UserInterfaceFirstAutoConfig() == _TRUE)
                {
                    RTDOsdDisplayAutoProc();
                }
            } 
#endif

            if(GET_OSD_STATE() == _MENU_NONE)
            {
                RTDOsdDisplayTimingAndInputSource();
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
            
            RTDNVRamSaveBriCon(SysSourceGetSourceType());
            
            break;

        case _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG:

            RTDNVRamSaveSixColorData();

            break;
    }

    SET_OSD_EVENT_MESSAGE(_OSDEVENT_NONE_MSG);
}

//-----------------------------------
//    Menu None
//-----------------------------------
void RTDOsdNoneMenu(void)
{
    if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
    {
        RTDOsdDispMainMenu();
    }
}
void RTDOsdNoneLeft(void)
{
    if(_INPUT_PORT_VALID == 1)
    {
        return;
    }

    if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
    {
        SET_OSD_POWER_SAVING_SHOW_SOURCE(_TRUE);

        if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING) || (SysPowerGetPowerStatus() == _POWER_STATUS_NOSUPPORT_SAVING))
        {
            SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
        }
    }
    else if((SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) || (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL))
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG);
    }
    else if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
    {
        RTDOsdDispInputSourceHotKeyPage();
    }
}
void RTDOsdNoneRight(void)
{
    if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
    {
        SET_OSD_WAKE_UP_SWITCH_DDCCI_PORT(_TRUE);

        if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING) || (SysPowerGetPowerStatus() == _POWER_STATUS_NOSUPPORT_SAVING))
        {
            SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
        }
    }
    else if((SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) || (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL))
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG);
    }
    else if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
    {
        if(GET_FAIL_SAFE_MODE() == _FALSE)
        {
            RTDOsdDisplayTimingAndInputSource();
        }
    }
}
void RTDOsdNoneExit(void)
{
    
#if(_VGA_SUPPORT == _ON)
    if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) && (GET_FAIL_SAFE_MODE() == _FALSE) && (SysSourceGetSourceType() == _SOURCE_VGA))
    {
        RTDOsdDisplayAutoProc();
    }
#endif
    
}
//============Main Picture==============//
void RTDOsdMainPictureMenu(void)
{
    RTDOsdDispSelectItem(_OSD_PICTURE_BACKLIGHT);
}
void RTDOsdMainPictureLeft(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_DISPLAY);
    RTDOsdDispPageItem(_OSD_MAIN_DISPLAY);
}
void RTDOsdMainPictureRight(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_FACTORY);
    RTDOsdDispPageItem(_OSD_MAIN_FACTORY);    
}
void RTDOsdMainPictureExit(void)
{
    RTDOsdDisplayDisableOsd();
}
//============Main Display==============//
void RTDOsdMainDisplayMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        RTDOsdDispSelectItem(_OSD_DISPLAY_AUTO);
    }
    else
#endif
    {
        RTDOsdDispSelectItem(_OSD_DISPLAY_HPOSITION);
    }
}
void RTDOsdMainDisplayLeft(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_COLOR);
    RTDOsdDispPageItem(_OSD_MAIN_COLOR);    
}
void RTDOsdMainDisplayRight(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_PICTURE);
    RTDOsdDispPageItem(_OSD_MAIN_PICTURE);        
}
void RTDOsdMainDisplayExit(void)
{
    RTDOsdDisplayDisableOsd();
}

//============Main Color==============//
void RTDOsdMainColorMenu(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_GAMMA);
}
void RTDOsdMainColorLeft(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_ADVANCE);
    RTDOsdDispPageItem(_OSD_MAIN_ADVANCE);        
}
void RTDOsdMainColorRight(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_DISPLAY);
    RTDOsdDispPageItem(_OSD_MAIN_DISPLAY);
}
void RTDOsdMainColorExit(void)
{
    RTDOsdDisplayDisableOsd();
}

//============Main Advance==============//
void RTDOsdMainAdvanceMenu(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_ASPECTRATIO);
}
void RTDOsdMainAdvanceLeft(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_INPUT);
    RTDOsdDispPageItem(_OSD_MAIN_INPUT);        
}
void RTDOsdMainAdvanceRight(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_COLOR);
    RTDOsdDispPageItem(_OSD_MAIN_COLOR);        
}
void RTDOsdMainAdvanceExit(void)
{
    RTDOsdDisplayDisableOsd();
}

//============Main Input==============//
void RTDOsdMainInputMenu(void)
{
    if(_INPUT_PORT_VALID != 1)
    {
        if(SysSourceGetScanType() == _SOURCE_SWITCH_FIXED_PORT)
        { 
            RTDOsdDispSelectItem(_OSD_INPUT_AUTO + RTDOsdDisplayJudgeSourceType() + 1);
        }
        else
        {
            RTDOsdDispSelectItem(_OSD_INPUT_AUTO);
        }
    }
}
void RTDOsdMainInputLeft(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_AUDIO);
    RTDOsdDispPageItem(_OSD_MAIN_AUDIO);        
}
void RTDOsdMainInputRight(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_ADVANCE);
    RTDOsdDispPageItem(_OSD_MAIN_ADVANCE);        
}
void RTDOsdMainInputExit(void)
{
    RTDOsdDisplayDisableOsd();
}

//============Main Audio==============//
void RTDOsdMainAudioMenu(void)
{
#if(_AUDIO_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_AUDIO_VOLUME);
#endif
}
void RTDOsdMainAudioLeft(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_OTHERS);
    RTDOsdDispPageItem(_OSD_MAIN_OTHERS);        
}
void RTDOsdMainAudioRight(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_INPUT);
    RTDOsdDispPageItem(_OSD_MAIN_INPUT);        
}
void RTDOsdMainAudioExit(void)
{
    RTDOsdDisplayDisableOsd();
}

//============Main Others==============//
void RTDOsdMainOthersMenu(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_RESET);
}
void RTDOsdMainOthersLeft(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_INFORMATION);
    RTDOsdDispPageItem(_OSD_MAIN_INFORMATION);        
}
void RTDOsdMainOthersRight(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_AUDIO);
    RTDOsdDispPageItem(_OSD_MAIN_AUDIO);        
}
void RTDOsdMainOthersExit(void)
{
    RTDOsdDisplayDisableOsd();
}

//============Main Information==============//
void RTDOsdMainInformationMenu(void)
{

}
void RTDOsdMainInformationLeft(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_FACTORY);
    RTDOsdDispPageItem(_OSD_MAIN_FACTORY);        
}
void RTDOsdMainInformationRight(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_OTHERS);
    RTDOsdDispPageItem(_OSD_MAIN_OTHERS);        
}
void RTDOsdMainInformationExit(void)
{
    RTDOsdDisplayDisableOsd();
}

//============Main Factory==============//
void RTDOsdMainFactoryMenu(void)
{
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);        
    RTDFactoryMainMenu();
}
void RTDOsdMainFactoryLeft(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_PICTURE);
    RTDOsdDispPageItem(_OSD_MAIN_PICTURE);        
}
void RTDOsdMainFactoryRight(void)
{
    RTDOsdDispSelectItem(_OSD_MAIN_INFORMATION);
    RTDOsdDispPageItem(_OSD_MAIN_INFORMATION);        
}
void RTDOsdMainFactoryExit(void)
{
    RTDOsdDisplayDisableOsd();
}

//============Picture Backlight==============//
void RTDOsdPictureBacklightMenu(void)
{
    g_usBackupValue = GET_OSD_BACKLIGHT();
    RTDOsdDispSelectItem(_OSD_PICTURE_BACKLIGHT_ADJUST);    
}
void RTDOsdPictureBacklightLeft(void)
{
    RTDOsdDispSelectItem(_OSD_PICTURE_SHARPNESS);
}
void RTDOsdPictureBacklightRight(void)
{
    RTDOsdDispSelectItem(_OSD_PICTURE_BRIGHTNESS);
}
void RTDOsdPictureBacklightExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_PICTURE);    
}

//============Picture Brightness==============//
void RTDOsdPictureBrightnessMenu(void)
{
#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() == _PCM_OSD_NATIVE)
    {
        g_usBackupValue = GET_OSD_BRIGHTNESS();
        RTDOsdDispSelectItem(_OSD_PICTURE_BRIGHTNESS_ADJUST);    
    }
#else
    g_usBackupValue = GET_OSD_BRIGHTNESS();
    RTDOsdDispSelectItem(_OSD_PICTURE_BRIGHTNESS_ADJUST);    
#endif

}
void RTDOsdPictureBrightnessLeft(void)
{
    RTDOsdDispSelectItem(_OSD_PICTURE_BACKLIGHT);
}
void RTDOsdPictureBrightnessRight(void)
{
    RTDOsdDispSelectItem(_OSD_PICTURE_CONTRAST);
}
void RTDOsdPictureBrightnessExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_PICTURE);    
}

//============Picture Contrast==============//
void RTDOsdPictureContrastMenu(void)
{
#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() == _PCM_OSD_NATIVE)
    {
        g_usBackupValue = GET_OSD_CONTRAST();
        RTDOsdDispSelectItem(_OSD_PICTURE_CONTRAST_ADJUST);
    }
#else
    g_usBackupValue = GET_OSD_CONTRAST();
    RTDOsdDispSelectItem(_OSD_PICTURE_CONTRAST_ADJUST);   
#endif

}
void RTDOsdPictureContrastLeft(void)
{
    RTDOsdDispSelectItem(_OSD_PICTURE_BRIGHTNESS);
}
void RTDOsdPictureContrastRight(void)
{
    RTDOsdDispSelectItem(_OSD_PICTURE_SHARPNESS);
}
void RTDOsdPictureContrastExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_PICTURE);        
}

//============Picture Sharpness==============//
void RTDOsdPictureSharpnessMenu(void)
{
    g_usBackupValue = GET_OSD_SHARPNESS();
    RTDOsdDispSelectItem(_OSD_PICTURE_SHARPNESS_ADJUST);    
}
void RTDOsdPictureSharpnessLeft(void)
{
    RTDOsdDispSelectItem(_OSD_PICTURE_CONTRAST);
}
void RTDOsdPictureSharpnessRight(void)
{
    RTDOsdDispSelectItem(_OSD_PICTURE_BACKLIGHT);
}
void RTDOsdPictureSharpnessExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_PICTURE);        
}

//============Picture Backlight Adjust==============//
void RTDOsdPictureBacklightAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_BACKLIGHT())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_PICTURE_BACKLIGHT);            
}
void RTDOsdPictureBacklightAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_PICTURE_BACKLIGHT_ADJUST, GET_OSD_BACKLIGHT());

#if(_ENERGY_STAR_SUPPORT == _ON)
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
        UserAdjustBacklight(GET_OSD_BACKLIGHT());
    }
#else
    UserAdjustBacklight(GET_OSD_BACKLIGHT());
#endif

}
void RTDOsdPictureBacklightAdjustRight(void)
{
    RTDOsdPictureBacklightAdjustLeft();
}
void RTDOsdPictureBacklightAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_BACKLIGHT())
    {
        SET_OSD_BACKLIGHT(g_usBackupValue);
        RTDOsdPictureBacklightAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_PICTURE_BACKLIGHT);    
}

//============Picture Brightness Adjust==============//
void RTDOsdPictureBrightnessAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_BRIGHTNESS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_PICTURE_BRIGHTNESS);        
}
void RTDOsdPictureBrightnessAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_PICTURE_BRIGHTNESS_ADJUST, GET_OSD_BRIGHTNESS());
    UserAdjustBrightness(GET_OSD_BRIGHTNESS());
}
void RTDOsdPictureBrightnessAdjustRight(void)
{
    RTDOsdPictureBrightnessAdjustLeft();
}
void RTDOsdPictureBrightnessAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_BRIGHTNESS())
    {
        SET_OSD_BRIGHTNESS(g_usBackupValue);
        RTDOsdPictureBrightnessAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_PICTURE_BRIGHTNESS);        
}

//============Picture Contrast Adjust==============//
void RTDOsdPictureContrastAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_CONTRAST())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_PICTURE_CONTRAST);        
}
void RTDOsdPictureContrastAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_PICTURE_CONTRAST_ADJUST, GET_OSD_CONTRAST());
    UserAdjustContrast(GET_OSD_CONTRAST());
}
void RTDOsdPictureContrastAdjustRight(void)
{
    RTDOsdPictureContrastAdjustLeft();
}
void RTDOsdPictureContrastAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_CONTRAST())
    {
        SET_OSD_CONTRAST(g_usBackupValue);
        RTDOsdPictureContrastAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_PICTURE_CONTRAST);        
}

//============Picture Sharpness Adjust==============//
void RTDOsdPictureSharpnessAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_SHARPNESS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_PICTURE_SHARPNESS);
}
void RTDOsdPictureSharpnessAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_PICTURE_SHARPNESS_ADJUST, GET_OSD_SHARPNESS());
    UserAdjustSharpness(GET_OSD_SHARPNESS());
}
void RTDOsdPictureSharpnessAdjustRight(void)
{
    RTDOsdPictureSharpnessAdjustLeft();
}
void RTDOsdPictureSharpnessAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_SHARPNESS())
    {
        SET_OSD_SHARPNESS(g_usBackupValue);
        RTDOsdPictureSharpnessAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_PICTURE_SHARPNESS);    
}

//============Display Auto==============//
void RTDOsdDisplayAutoMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    RTDOsdDisplayAutoProc();
#endif
}
void RTDOsdDisplayAutoLeft(void)
{
    RTDOsdDispSelectItem(_OSD_DISPLAY_PHASE);
}
void RTDOsdDisplayAutoRight(void)
{
    RTDOsdDispSelectItem(_OSD_DISPLAY_HPOSITION);
}
void RTDOsdDisplayAutoExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_DISPLAY);            
}

//============Display H Position==============//
void RTDOsdDisplayHPositionMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        g_usBackupValue = GET_VGA_MODE_ADJUST_H_POSITION();
    }
    else
#endif
    {
        g_usBackupValue = GET_DIGITAL_H_POSITION();
    }
    RTDOsdDispSelectItem(_OSD_DISPLAY_HPOSITION_ADJUST);    
}
void RTDOsdDisplayHPositionLeft(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        RTDOsdDispSelectItem(_OSD_DISPLAY_AUTO);
    }
    else
#endif
    {
        RTDOsdDispSelectItem(_OSD_DISPLAY_VPOSITION);
    }
}
void RTDOsdDisplayHPositionRight(void)
{
    RTDOsdDispSelectItem(_OSD_DISPLAY_VPOSITION);
}
void RTDOsdDisplayHPositionExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_DISPLAY);        
}

//============Display V Position==============//
void RTDOsdDisplayVPositionMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        g_usBackupValue = GET_VGA_MODE_ADJUST_V_POSITION();
    }
    else
#endif
    {
        g_usBackupValue = GET_DIGITAL_V_POSITION();
    }
    RTDOsdDispSelectItem(_OSD_DISPLAY_VPOSITION_ADJUST);    
}
void RTDOsdDisplayVPositionLeft(void)
{
    RTDOsdDispSelectItem(_OSD_DISPLAY_HPOSITION);
}
void RTDOsdDisplayVPositionRight(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        RTDOsdDispSelectItem(_OSD_DISPLAY_CLOCK);
    }
    else
#endif
    {
        RTDOsdDispSelectItem(_OSD_DISPLAY_HPOSITION);
    }
}
void RTDOsdDisplayVPositionExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_DISPLAY);        
}

//============Display Clock==============//
void RTDOsdDisplayClockMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    g_usBackupValue = GET_VGA_MODE_ADJUST_CLOCK();
    RTDOsdDispSelectItem(_OSD_DISPLAY_CLOCK_ADJUST);
#endif
}
void RTDOsdDisplayClockLeft(void)
{
    RTDOsdDispSelectItem(_OSD_DISPLAY_VPOSITION);
}
void RTDOsdDisplayClockRight(void)
{
    RTDOsdDispSelectItem(_OSD_DISPLAY_PHASE);
}
void RTDOsdDisplayClockExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_DISPLAY);            
}

//============Display Phase==============//
void RTDOsdDisplayPhaseMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    g_usBackupValue = GET_VGA_MODE_ADJUST_PHASE();
    RTDOsdDispSelectItem(_OSD_DISPLAY_PHASE_ADJUST);    
#endif
}
void RTDOsdDisplayPhaseLeft(void)
{
    RTDOsdDispSelectItem(_OSD_DISPLAY_CLOCK);
}
void RTDOsdDisplayPhaseRight(void)
{
    RTDOsdDispSelectItem(_OSD_DISPLAY_AUTO);
}
void RTDOsdDisplayPhaseExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_DISPLAY);            
}

//============Display H Position Adjust==============//
void RTDOsdDisplayHPositionAdjustMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(g_usBackupValue != GET_VGA_MODE_ADJUST_H_POSITION())
        {
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
        }
    }
#endif

    RTDOsdDispWindowZoomOut(_OSD_DISPLAY_HPOSITION);    
}
void RTDOsdDisplayHPositionAdjustLeft(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        RTDOsdDispSliderAndNumber(_OSD_DISPLAY_HPOSITION_ADJUST, GET_VGA_MODE_ADJUST_H_POSITION());
        UserCommonAdjustHPosition(GET_VGA_MODE_ADJUST_H_POSITION());        
    }
    else
#endif
    {
        RTDOsdDispSliderAndNumber(_OSD_DISPLAY_HPOSITION_ADJUST, GET_DIGITAL_H_POSITION());
        UserCommonAdjustHPosition(GET_DIGITAL_H_POSITION());
    }
}
void RTDOsdDisplayHPositionAdjustRight(void)
{
    RTDOsdDisplayHPositionAdjustLeft();
}
void RTDOsdDisplayHPositionAdjustExit(void)
{
    BYTE ucTemp = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        ucTemp = GET_VGA_MODE_ADJUST_H_POSITION();
    }
    else
#endif
    {
        ucTemp = GET_DIGITAL_H_POSITION();
    }

    if(g_usBackupValue != ucTemp)
    {
#if(_VGA_SUPPORT == _ON)
        if(SysSourceGetSourceType() == _SOURCE_VGA)
        {
            SET_VGA_MODE_ADJUST_H_POSITION(g_usBackupValue);
        }
        else
#endif
        {
            SET_DIGITAL_H_POSITION(g_usBackupValue);
        }
        RTDOsdDisplayHPositionAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_DISPLAY_HPOSITION);    
}

//============Display V Position Adjust==============//
void RTDOsdDisplayVPositionAdjustMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(g_usBackupValue != GET_VGA_MODE_ADJUST_V_POSITION())
        {
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
        }
    }
#endif

    RTDOsdDispWindowZoomOut(_OSD_DISPLAY_VPOSITION);    
}
void RTDOsdDisplayVPositionAdjustLeft(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        RTDOsdDispSliderAndNumber(_OSD_DISPLAY_VPOSITION_ADJUST, GET_VGA_MODE_ADJUST_V_POSITION());
        UserCommonAdjustVPosition(GET_VGA_MODE_ADJUST_V_POSITION());        
    }
    else
#endif
    {
        RTDOsdDispSliderAndNumber(_OSD_DISPLAY_VPOSITION_ADJUST, GET_DIGITAL_V_POSITION());
        UserCommonAdjustVPosition(GET_DIGITAL_V_POSITION());        
    }
}
void RTDOsdDisplayVPositionAdjustRight(void)
{
    RTDOsdDisplayVPositionAdjustLeft();
}
void RTDOsdDisplayVPositionAdjustExit(void)
{
    BYTE ucTemp = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        ucTemp = GET_VGA_MODE_ADJUST_V_POSITION();
    }
    else
#endif
    {
        ucTemp = GET_DIGITAL_V_POSITION();
    }

    if(g_usBackupValue != ucTemp)
    {
#if(_VGA_SUPPORT == _ON)
        if(SysSourceGetSourceType() == _SOURCE_VGA)
        {
            SET_VGA_MODE_ADJUST_V_POSITION(g_usBackupValue);
        }
        else
#endif
        {
            SET_DIGITAL_V_POSITION(g_usBackupValue);
        }
        RTDOsdDisplayVPositionAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_DISPLAY_VPOSITION);    
}

//============Display Clock Adjust==============//
void RTDOsdDisplayClockAdjustMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    if(g_usBackupValue != GET_VGA_MODE_ADJUST_CLOCK())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_DISPLAY_CLOCK);   
#endif
}
void RTDOsdDisplayClockAdjustLeft(void)
{
#if(_VGA_SUPPORT == _ON)
    RTDOsdDispSliderAndNumber(_OSD_DISPLAY_CLOCK_ADJUST, GET_VGA_MODE_ADJUST_CLOCK());
    UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());
#endif

}
void RTDOsdDisplayClockAdjustRight(void)
{
    RTDOsdDisplayClockAdjustLeft();
}
void RTDOsdDisplayClockAdjustExit(void)
{
#if(_VGA_SUPPORT == _ON)
    if(g_usBackupValue != GET_VGA_MODE_ADJUST_CLOCK())
    {
        SET_VGA_MODE_ADJUST_CLOCK(g_usBackupValue);
        RTDOsdDisplayClockAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_DISPLAY_CLOCK);   
#endif
}

//============Display Phase Adjust==============//
void RTDOsdDisplayPhaseAdjustMenu(void)
{
#if(_VGA_SUPPORT == _ON)
    if(g_usBackupValue != GET_VGA_MODE_ADJUST_PHASE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_DISPLAY_PHASE);
#endif
}
void RTDOsdDisplayPhaseAdjustLeft(void)
{
#if(_VGA_SUPPORT == _ON)
    RTDOsdDispSliderAndNumber(_OSD_DISPLAY_PHASE_ADJUST, GET_VGA_MODE_ADJUST_PHASE());
    UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());
#endif
}
void RTDOsdDisplayPhaseAdjustRight(void)
{
    RTDOsdDisplayPhaseAdjustLeft();
}
void RTDOsdDisplayPhaseAdjustExit(void)
{
#if(_VGA_SUPPORT == _ON)
    if(g_usBackupValue != GET_VGA_MODE_ADJUST_PHASE())
    {
        SET_VGA_MODE_ADJUST_PHASE(g_usBackupValue);
        RTDOsdDisplayPhaseAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_DISPLAY_PHASE);    
#endif
}

//============Color Gamma==============//
void RTDOsdColorGammaMenu(void)
{
#if(_GAMMA_FUNCTION == _ON)

#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() == _PCM_OSD_NATIVE)
    {
        g_usBackupValue = GET_OSD_GAMMA();
        RTDOsdDispSelectItem(_OSD_COLOR_GAMMA_SELECT);
    }
#else
    g_usBackupValue = GET_OSD_GAMMA();
    RTDOsdDispSelectItem(_OSD_COLOR_GAMMA_SELECT);
#endif

#endif
}
void RTDOsdColorGammaLeft(void)
{
    if((GET_OSD_COLOR_EFFECT() == _COLOREFFECT_VIVID) || (GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER))
    {
        RTDOsdDispSelectItem(_OSD_COLOR_PCM);
    }
    else
    {
        RTDOsdDispSelectItem(_OSD_COLOR_SATURATION);
    }
}
void RTDOsdColorGammaRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP);
}
void RTDOsdColorGammaExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_COLOR);        
}

//============Color Colortemp==============//
void RTDOsdColorColortempMenu(void)
{
#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() == _PCM_OSD_NATIVE)
    {
        g_usBackupValue = GET_COLOR_TEMP_TYPE();
        RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_SELECT);
    }
#else
    g_usBackupValue = GET_COLOR_TEMP_TYPE();
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_SELECT);
#endif

}
void RTDOsdColorColortempLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_GAMMA);
}
void RTDOsdColorColortempRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT);
}
void RTDOsdColorColortempExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_COLOR);        
}

//============Color Effect==============//
void RTDOsdColorEffectMenu(void)
{
#if((_ICM_SUPPORT == _ON) || (_DCC_FUNCTION == _ON))
    g_usBackupValue = GET_OSD_COLOR_EFFECT();
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_SELECT);
#endif
}
void RTDOsdColorEffectLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP);
}
void RTDOsdColorEffectRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_DEMO);
}
void RTDOsdColorEffectExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_COLOR);            
}

//============Color Demo==============//
void RTDOsdColorDemoMenu(void)
{
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    g_usBackupValue = GET_OSD_HLWIN_TYPE();
    RTDOsdDispSelectItem(_OSD_COLOR_DEMO_SELECT);
#endif
}
void RTDOsdColorDemoLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT);
}
void RTDOsdColorDemoRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_FORMAT);
}
void RTDOsdColorDemoExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_COLOR);        
}

//============Color Format==============//
void RTDOsdColorFormatMenu(void)
{
#if(_COLOR_FORMAT_CONVERT == _ON)
    g_usBackupValue = GET_OSD_COLOR_FORMAT();
    RTDOsdDispSelectItem(_OSD_COLOR_FORMAT_SELECT);
#endif
}
void RTDOsdColorFormatLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_DEMO);
}
void RTDOsdColorFormatRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_PCM);
}
void RTDOsdColorFormatExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_COLOR);            
}

//============Color PCM==============//
void RTDOsdColorPCMMenu(void)
{
#if(_PCM_FUNCTION == _ON)
    g_usBackupValue = GET_OSD_PCM_STATUS();
    RTDOsdDispSelectItem(_OSD_COLOR_PCM_SELECT);
#endif
}
void RTDOsdColorPCMLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_FORMAT);
}
void RTDOsdColorPCMRight(void)
{
    if((GET_OSD_COLOR_EFFECT() == _COLOREFFECT_VIVID) || (GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER))
    {
        RTDOsdDispSelectItem(_OSD_COLOR_GAMMA);
    }
    else
    {
        RTDOsdDispSelectItem(_OSD_COLOR_HUE);
    }
}
void RTDOsdColorPCMExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_COLOR);            
}

//============Color Hue==============//
void RTDOsdColorHueMenu(void)
{
#if(_GLOBAL_HUE_SATURATION == _ON)

#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() == _PCM_OSD_NATIVE)
    {
        g_usBackupValue = GET_OSD_HUE();
        RTDOsdDispSelectItem(_OSD_COLOR_HUE_ADJUST);
    }
#else
    g_usBackupValue = GET_OSD_HUE();
    RTDOsdDispSelectItem(_OSD_COLOR_HUE_ADJUST);
#endif

#endif
}
void RTDOsdColorHueLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_PCM);
}
void RTDOsdColorHueRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_SATURATION);
}
void RTDOsdColorHueExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_COLOR);            
}

//============Color Saturation==============//
void RTDOsdColorSaturationMenu(void)
{
#if(_GLOBAL_HUE_SATURATION == _ON)

#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() == _PCM_OSD_NATIVE)
    {
        g_usBackupValue = GET_OSD_SATURATION();
        RTDOsdDispSelectItem(_OSD_COLOR_SATURATION_ADJUST);
    }
#else
    g_usBackupValue = GET_OSD_SATURATION();
    RTDOsdDispSelectItem(_OSD_COLOR_SATURATION_ADJUST);
#endif

#endif
}
void RTDOsdColorSaturationLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_HUE);
}
void RTDOsdColorSaturationRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_GAMMA);
}
void RTDOsdColorSaturationExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_COLOR);            
}
    
//============Color Gamma Adjust==============//
void RTDOsdColorGammaAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_GAMMA())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_GAMMA);
}
void RTDOsdColorGammaAdjustLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_COLOR_GAMMA_SELECT);

#if(_GAMMA_FUNCTION == _ON)
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    ScalerColorOutputGamma(_OFF);
    
    if(GET_OSD_GAMMA() != _GAMMA_OFF)
    {
        UserAdjustGamma(GET_OSD_GAMMA());

        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        ScalerColorOutputGamma(_ON);
    }
#endif // End of #if(_GAMMA_FUNCTION == _ON)
}
void RTDOsdColorGammaAdjustRight(void)
{
    RTDOsdColorGammaAdjustLeft();
}
void RTDOsdColorGammaAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_GAMMA())
    {
        SET_OSD_GAMMA(g_usBackupValue);
        RTDOsdColorGammaAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_GAMMA);        
}

//============Color Colortemp Select==============//
void RTDOsdColorColortempSelectMenu(void)
{
    if(g_usBackupValue != GET_COLOR_TEMP_TYPE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }

    if(GET_COLOR_TEMP_TYPE() == _CT_USER)
    {
        RTDOsdDispPageItem(_OSD_COLOR_COLORTEMP_USER_R);
        RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_R);
    }
    else
    {
        RTDOsdDispWindowZoomOut(_OSD_COLOR_COLORTEMP);
    }
}
void RTDOsdColorColortempSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_COLOR_COLORTEMP_SELECT);
    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
    UserAdjustContrast(GET_OSD_CONTRAST());
}
void RTDOsdColorColortempSelectRight(void)
{
    RTDOsdColorColortempSelectLeft();
}
void RTDOsdColorColortempSelectExit(void)
{
    if(g_usBackupValue != GET_COLOR_TEMP_TYPE())
    {
        SET_COLOR_TEMP_TYPE(g_usBackupValue);
        RTDOsdColorColortempSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLORTEMP);            
}

//============Color Color Effect Select==============//
void RTDOsdColorColorEffectSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_COLOR_EFFECT())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER)
    {
        SET_OSD_SIX_COLOR(_SIXCOLOR_R);
        RTDOsdDispPageItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR);
        RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR);
    }
    else
    {
        RTDOsdDispWindowZoomOut(_OSD_COLOR_COLOREFFECT);
    }
}
void RTDOsdColorColorEffectSelectLeft(void)
{

#if(_SIX_COLOR_SUPPORT == _ON)
    BYTE ucIndex = 0;
#endif

    RTDOsdDispOsdFunctionAdjust(_OSD_COLOR_COLOREFFECT_SELECT);

#if(_DCC_FUNCTION == _ON)
        ScalerColorDCC(_OFF);
        UserAdjustDCC(GET_OSD_COLOR_EFFECT());
        
        if((GET_OSD_COLOR_EFFECT() != _COLOREFFECT_STANDARD) && (GET_OSD_COLOR_EFFECT() != _COLOREFFECT_USER))
        {
            ScalerColorDCC(_ON);
        }
#endif // End of #if(_DCC_FUNCTION == _ON)

#if(_ICM_SUPPORT == _ON)
        ScalerColorICM(_OFF);
        UserAdjustICM(GET_OSD_COLOR_EFFECT());

#if(_SIX_COLOR_SUPPORT == _ON)
        if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER)
        {
            for(ucIndex = 0; ucIndex < 6; ucIndex++)
            {
                SET_OSD_SIX_COLOR(ucIndex);
                RTDOsdDisplaySixColorGetOneColor(ucIndex);
                ScalerColorSixColorAdjust(ucIndex, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
            }

            ScalerColorSixColorEnable();
        }
#endif

        if(GET_OSD_COLOR_EFFECT() != _COLOREFFECT_STANDARD)
        {
            ScalerColorICM(_ON);
        }
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
        if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_VIVID)
        {
            ScalerColorSRGBSetGlobalHueSat(((SWORD)_DEFAULT_HUE - (SWORD)GET_OSD_HUE()), 140);
        }
        else
        {
            ScalerColorSRGBSetGlobalHueSat(((SWORD)_DEFAULT_HUE - (SWORD)GET_OSD_HUE()), GET_OSD_SATURATION());
        }
#endif
}
void RTDOsdColorColorEffectSelectRight(void)
{
    RTDOsdColorColorEffectSelectLeft();
}
void RTDOsdColorColorEffectSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_COLOR_EFFECT())
    {
        SET_OSD_COLOR_EFFECT(g_usBackupValue);
        RTDOsdColorColorEffectSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLOREFFECT);            
}

//============Color Demo Select==============//
void RTDOsdColorDemoSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_HLWIN_TYPE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_DEMO);
}
void RTDOsdColorDemoSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_COLOR_DEMO_SELECT);
    
#if((_DCC_FUNCTION == _ON) || (_DCC_HISTOGRM_INFO == _ON))
    ScalerColorDCCNormalizeFactorAdjust();
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    if(GET_OSD_HLWIN_TYPE() == _HL_WIN_OFF)
    {
        ScalerColorHLW(_OFF);
    }
    else
    {
        UserAdjustHLWinType(GET_OSD_HLWIN_TYPE());
        ScalerColorHLW(_ON);
    }
    UserAdjustContrast(GET_OSD_CONTRAST());
#endif
}
void RTDOsdColorDemoSelectRight(void)
{
    RTDOsdColorDemoSelectLeft();
}
void RTDOsdColorDemoSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_HLWIN_TYPE())
    {
        SET_OSD_HLWIN_TYPE(g_usBackupValue);
        RTDOsdColorDemoSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_DEMO);            
}

//============Color Format Select==============//
void RTDOsdColorFormatSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_COLOR_FORMAT())
    {
        switch(SysSourceGetInputPort())
        {
            case _A0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
            case _D0_INPUT_PORT:
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
            case _D1_INPUT_PORT:
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)
            case _D2_INPUT_PORT:
#endif

#if(_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)
            case _D3_INPUT_PORT:
#endif
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

                break;
                
            default:
                break;
        }
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_FORMAT);
}
void RTDOsdColorFormatSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_COLOR_FORMAT_SELECT);

#if(_OVERSCAN_SUPPORT == _ON)
    if(GET_OSD_OVERSCAN_STATUS() == _ON)
    {
        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
    }
    else
#endif
    {
        if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
        {
            SysModeColorSpaceConvert(_COLOR_SPACE_RGB);
        }
        else
        {
            SysModeColorSpaceConvert(_COLOR_SPACE_YPBPR);
        }
    }
}
void RTDOsdColorFormatSelectRight(void)
{
    RTDOsdColorFormatSelectLeft();
}
void RTDOsdColorFormatSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_COLOR_FORMAT())
    {
        switch(SysSourceGetInputPort())
        {
            case _A0_INPUT_PORT:

                SET_VGA_COLOR_FORMAT_STATUS(g_usBackupValue); 
                break;
                
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
            case _D0_INPUT_PORT:
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
            case _D1_INPUT_PORT:
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)
            case _D2_INPUT_PORT:
#endif

#if(_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)
            case _D3_INPUT_PORT:
#endif
                SET_DVI_COLOR_FORMAT_STATUS(g_usBackupValue); 

                break;
                
            default:
                break;
        }        

        RTDOsdColorFormatSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_FORMAT);            
}

//============Color PCM Select==============//
void RTDOsdColorPCMSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_PCM_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_PCM);            
}
void RTDOsdColorPCMSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_COLOR_PCM_SELECT);

#if(_PCM_FUNCTION == _ON)
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    ScalerColorOutputGamma(_OFF);     
    ScalerColorSRGB(_OFF);            
    ScalerColorPCMInputGamma(_OFF);    

    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
    {
        UserAdjustPCM(GET_OSD_PCM_STATUS());

        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

        ScalerColorBriConOff();
        ScalerColorOutputGamma(_ON);     
        ScalerColorSRGB(_ON);            
        ScalerColorPCMInputGamma(_ON);    
    }
    else
    {
        
#if(_GAMMA_FUNCTION == _ON)
        UserAdjustGamma(GET_OSD_GAMMA());
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
        ScalerColorSRGBSetGlobalHueSat(((SWORD)_DEFAULT_HUE - (SWORD)GET_OSD_HUE()), GET_OSD_SATURATION());
#endif

#if((_GAMMA_FUNCTION == _ON) || (_GLOBAL_HUE_SATURATION == _ON))
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_GAMMA_FUNCTION == _ON)
        if(GET_OSD_GAMMA() != _GAMMA_OFF)
        {
            ScalerColorOutputGamma(_ON);
        }
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
        ScalerColorSRGB(_ON);
#endif

        UserAdjustContrast(GET_OSD_CONTRAST());
        UserAdjustBrightness(GET_OSD_BRIGHTNESS());
#endif  // End of #if((_GAMMA_FUNCTION == _ON) || (_GLOBAL_HUE_SATURATION == _ON))

    }
#endif  // End of #if(_PCM_FUNCTION == _ON)

}
void RTDOsdColorPCMSelectRight(void)
{
    RTDOsdColorPCMSelectLeft();
}
void RTDOsdColorPCMSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_PCM_STATUS())
    {
        SET_OSD_PCM_STATUS(g_usBackupValue);
        RTDOsdColorPCMSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_PCM);            
}

//============Color Hue Adjust==============//
void RTDOsdColorHueAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_HUE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_HUE);            
}
void RTDOsdColorHueAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_COLOR_HUE_ADJUST, GET_OSD_HUE());
#if(_GLOBAL_HUE_SATURATION == _ON)
    ScalerColorSRGBSetGlobalHueSat(((SWORD)_DEFAULT_HUE - (SWORD)GET_OSD_HUE()), GET_OSD_SATURATION());
#endif
}
void RTDOsdColorHueAdjustRight(void)
{
    RTDOsdColorHueAdjustLeft();
}
void RTDOsdColorHueAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_HUE())
    {
        SET_OSD_HUE(g_usBackupValue);
        RTDOsdColorHueAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_HUE);            
}

//============Color Saturation Adjust==============//
void RTDOsdColorSaturationAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_SATURATION())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_SATURATION);            
}
void RTDOsdColorSaturationAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_COLOR_SATURATION_ADJUST, GET_OSD_SATURATION());
#if(_GLOBAL_HUE_SATURATION == _ON)
    ScalerColorSRGBSetGlobalHueSat(((SWORD)_DEFAULT_HUE - (SWORD)GET_OSD_HUE()), GET_OSD_SATURATION());
#endif

}
void RTDOsdColorSaturationAdjustRight(void)
{
    RTDOsdColorSaturationAdjustLeft();
}
void RTDOsdColorSaturationAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_SATURATION())
    {
        SET_OSD_SATURATION(g_usBackupValue);
        RTDOsdColorSaturationAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_SATURATION);            
}

//============Color Colortemp User R==============//
void RTDOsdColorColortempUserRMenu(void)
{
    g_usBackupValue = GET_COLOR_TEMP_TYPE_USER_R();
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_R_ADJUST);    
}
void RTDOsdColorColortempUserRLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_B);
}
void RTDOsdColorColortempUserRRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_G);
}
void RTDOsdColorColortempUserRExit(void)
{
    RTDOsdDispPageItem(_OSD_MAIN_COLOR);
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP);
}

//============Color Colortemp User G==============//
void RTDOsdColorColortempUserGMenu(void)
{
    g_usBackupValue = GET_COLOR_TEMP_TYPE_USER_G();
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_G_ADJUST);    
}
void RTDOsdColorColortempUserGLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_R);
}
void RTDOsdColorColortempUserGRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_B);
}
void RTDOsdColorColortempUserGExit(void)
{
    RTDOsdDispPageItem(_OSD_MAIN_COLOR);
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP);
}

//============Color Colortemp User B==============//
void RTDOsdColorColortempUserBMenu(void)
{
    g_usBackupValue = GET_COLOR_TEMP_TYPE_USER_B();
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_B_ADJUST);    
}
void RTDOsdColorColortempUserBLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_G);
}
void RTDOsdColorColortempUserBRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP_USER_R);
}
void RTDOsdColorColortempUserBExit(void)
{
    RTDOsdDispPageItem(_OSD_MAIN_COLOR);
    RTDOsdDispSelectItem(_OSD_COLOR_COLORTEMP);
}

//============Color Colortemp User R Adjust==============//
void RTDOsdColorColortempUserRAdjustMenu(void)
{
    if(g_usBackupValue != GET_COLOR_TEMP_TYPE_USER_R())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLORTEMP_USER_R);
}
void RTDOsdColorColortempUserRAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_COLOR_COLORTEMP_USER_R_ADJUST, GET_COLOR_TEMP_TYPE_USER_R());
    UserAdjustContrast(GET_OSD_CONTRAST());
}
void RTDOsdColorColortempUserRAdjustRight(void)
{
    RTDOsdColorColortempUserRAdjustLeft();
}
void RTDOsdColorColortempUserRAdjustExit(void)
{
    if(g_usBackupValue != GET_COLOR_TEMP_TYPE_USER_R())
    {
        SET_COLOR_TEMP_TYPE_USER_R(g_usBackupValue);
        RTDOsdColorColortempUserRAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLORTEMP_USER_R);        
}

//============Color Colortemp User G Adjust==============//
void RTDOsdColorColortempUserGAdjustMenu(void)
{
    if(g_usBackupValue != GET_COLOR_TEMP_TYPE_USER_G())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLORTEMP_USER_G);
}
void RTDOsdColorColortempUserGAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_COLOR_COLORTEMP_USER_G_ADJUST, GET_COLOR_TEMP_TYPE_USER_G());
    UserAdjustContrast(GET_OSD_CONTRAST());
}
void RTDOsdColorColortempUserGAdjustRight(void)
{
    RTDOsdColorColortempUserGAdjustLeft();
}
void RTDOsdColorColortempUserGAdjustExit(void)
{
    if(g_usBackupValue != GET_COLOR_TEMP_TYPE_USER_G())
    {
        SET_COLOR_TEMP_TYPE_USER_G(g_usBackupValue);
        RTDOsdColorColortempUserGAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLORTEMP_USER_G);
}

//============Color Colortemp User B Adjust==============//
void RTDOsdColorColortempUserBAdjustMenu(void)
{
    if(g_usBackupValue != GET_COLOR_TEMP_TYPE_USER_B())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLORTEMP_USER_B);
}
void RTDOsdColorColortempUserBAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_COLOR_COLORTEMP_USER_B_ADJUST, GET_COLOR_TEMP_TYPE_USER_B());
    UserAdjustContrast(GET_OSD_CONTRAST());
}
void RTDOsdColorColortempUserBAdjustRight(void)
{
    RTDOsdColorColortempUserBAdjustLeft();
}
void RTDOsdColorColortempUserBAdjustExit(void)
{
    if(g_usBackupValue != GET_COLOR_TEMP_TYPE_USER_B())
    {
        SET_COLOR_TEMP_TYPE_USER_B(g_usBackupValue);
        RTDOsdColorColortempUserBAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLORTEMP_USER_B);
}

//============Color Color Effect Six Color ==============//
void RTDOsdColorColorEffectSixColorMenu(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SELECT);    
}
void RTDOsdColorColorEffectSixColorLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SATURATION);
}
void RTDOsdColorColorEffectSixColorRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_HUE);
}
void RTDOsdColorColorEffectSixColorExit(void)
{
    RTDOsdDispPageItem(_OSD_MAIN_COLOR);
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT);
}

//============Color Color Effect Six Color Hue ==============//
void RTDOsdColorColorEffectSixColorHueMenu(void)
{
    g_usBackupValue = GET_OSD_SIX_COLOR_HUE();
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_HUE_ADJUST);    
}
void RTDOsdColorColorEffectSixColorHueLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR);
}
void RTDOsdColorColorEffectSixColorHueRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SATURATION);
}
void RTDOsdColorColorEffectSixColorHueExit(void)
{
    RTDOsdDispPageItem(_OSD_MAIN_COLOR);
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT);
}

//============Color Color Effect Six Color Saturation ==============//
void RTDOsdColorColorEffectSixColorSaturationMenu(void)
{
    g_usBackupValue = GET_OSD_SIX_COLOR_SATURATION();
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SATURATION_ADJUST);    
}
void RTDOsdColorColorEffectSixColorSaturationLeft(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_HUE);
}
void RTDOsdColorColorEffectSixColorSaturationRight(void)
{
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR);
}
void RTDOsdColorColorEffectSixColorSaturationExit(void)
{
    RTDOsdDispPageItem(_OSD_MAIN_COLOR);
    RTDOsdDispSelectItem(_OSD_COLOR_COLOREFFECT);
}

//============Color Color Effect Six Color Select==============//
void RTDOsdColorColorEffectSixColorSelectMenu(void)
{
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR);            
}
void RTDOsdColorColorEffectSixColorSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SELECT);
}
void RTDOsdColorColorEffectSixColorSelectRight(void)
{
    RTDOsdColorColorEffectSixColorSelectLeft();
}
void RTDOsdColorColorEffectSixColorSelectExit(void)
{
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR);            
}

//============Color Color Effect Six Color Hue Adjust==============//
void RTDOsdColorColorEffectSixColorHueAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_SIX_COLOR_HUE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_HUE);            
}
void RTDOsdColorColorEffectSixColorHueAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_HUE_ADJUST, GET_OSD_SIX_COLOR_HUE());

#if(_SIX_COLOR_SUPPORT == _ON)
    ScalerColorSixColorAdjust(GET_OSD_SIX_COLOR(), GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
#endif

}
void RTDOsdColorColorEffectSixColorHueAdjustRight(void)
{
    RTDOsdColorColorEffectSixColorHueAdjustLeft();
}
void RTDOsdColorColorEffectSixColorHueAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_SIX_COLOR_HUE())
    {
        SET_OSD_SIX_COLOR_HUE(g_usBackupValue);
        RTDOsdDisplaySixColorSetOneColor(GET_OSD_SIX_COLOR());
        RTDOsdColorColorEffectSixColorHueAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_HUE);            
}

//============Color Color Effect Six Color Saturation Adjust==============//
void RTDOsdColorColorEffectSixColorSaturationAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_SIX_COLOR_SATURATION())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SATURATION);            
}
void RTDOsdColorColorEffectSixColorSaturationAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SATURATION_ADJUST, GET_OSD_SIX_COLOR_SATURATION());

#if(_SIX_COLOR_SUPPORT == _ON)    
    ScalerColorSixColorAdjust(GET_OSD_SIX_COLOR(), GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
#endif
}
void RTDOsdColorColorEffectSixColorSaturationAdjustRight(void)
{
    RTDOsdColorColorEffectSixColorSaturationAdjustLeft();
}
void RTDOsdColorColorEffectSixColorSaturationAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_SIX_COLOR_SATURATION())
    {
        SET_OSD_SIX_COLOR_SATURATION(g_usBackupValue);
        RTDOsdDisplaySixColorSetOneColor(GET_OSD_SIX_COLOR());
        RTDOsdColorColorEffectSixColorSaturationAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_COLOR_COLOREFFECT_USER_SIXCOLOR_SATURATION);            
}

//============Advance Aspect Ratio==============//
void RTDOsdAdvanceAspectRatioMenu(void)
{
#if(_ASPECT_RATIO_SUPPORT == _ON)
    g_usBackupValue = GET_OSD_ASPECT_RATIO_TYPE();
    RTDOsdDispSelectItem(_OSD_ADVANCE_ASPECTRATIO_SELECT);
#endif
}
void RTDOsdAdvanceAspectRatioLeft(void)
{
#if(_OSD_3D_FUNCTION == _ON)    
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D);
#else
    RTDOsdDispSelectItem(_OSD_ADVANCE_ULTRA_VIVID);
#endif
}
void RTDOsdAdvanceAspectRatioRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_OVERSCAN);
}
void RTDOsdAdvanceAspectRatioExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_ADVANCE);            
}

//============Advance Oversacn==============//
void RTDOsdAdvanceOversacnMenu(void)
{
#if(_OVERSCAN_SUPPORT == _ON)
    g_usBackupValue = GET_OSD_OVERSCAN_STATUS();
    RTDOsdDispSelectItem(_OSD_ADVANCE_OVERSCAN_SELECT);
#endif
}
void RTDOsdAdvanceOversacnLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_ASPECTRATIO);
}
void RTDOsdAdvanceOversacnRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_OVERDRIVE);
}
void RTDOsdAdvanceOversacnExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_ADVANCE);        
}

//============Advance Overdrive==============//
void RTDOsdAdvanceOverdriveMenu(void)
{
#if(_OD_SUPPORT == _ON)
    g_usBackupValue = GET_OSD_OD_STATUS();
    RTDOsdDispSelectItem(_OSD_ADVANCE_OVERDRIVE_SELECT);
#endif
}
void RTDOsdAdvanceOverdriveLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_OVERSCAN);
}
void RTDOsdAdvanceOverdriveRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_ENERGY_STAR);
}
void RTDOsdAdvanceOverdriveExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_ADVANCE);        
}

//============Advance Energy Star==============//
void RTDOsdAdvanceESMenu(void)
{
#if(_ENERGY_STAR_SUPPORT == _ON)
    g_usBackupValue = GET_OSD_ES_STATUS();
    RTDOsdDispSelectItem(_OSD_ADVANCE_ENERGY_STAR_SELECT);
#endif
}
void RTDOsdAdvanceESLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_OVERDRIVE);
}
void RTDOsdAdvanceESRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_DDCCI);
}
void RTDOsdAdvanceESExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_ADVANCE);        
}

//============Advance DDCCI==============//
void RTDOsdAdvanceDdcciMenu(void)
{
    g_usBackupValue = GET_OSD_DDCCI_STATUS();
    RTDOsdDispSelectItem(_OSD_ADVANCE_DDCCI_SELECT);
}
void RTDOsdAdvanceDdcciLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_ENERGY_STAR);
}
void RTDOsdAdvanceDdcciRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_ULTRA_VIVID);
}
void RTDOsdAdvanceDdcciExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_ADVANCE);        
}

//============Advance Ultra Vivid==============//
void RTDOsdAdvanceUltraVividMenu(void)
{
#if(_ULTRA_VIVID_SUPPORT == _ON)
    g_usBackupValue = GET_OSD_ULTRA_VIVID_STATUS();
    RTDOsdDispSelectItem(_OSD_ADVANCE_ULTRA_VIVID_SELECT);
#endif
}
void RTDOsdAdvanceUltraVividLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_DDCCI);
}
void RTDOsdAdvanceUltraVividRight(void)
{
#if(_OSD_3D_FUNCTION == _ON)    
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D);
#else
    RTDOsdDispSelectItem(_OSD_ADVANCE_ASPECTRATIO);
#endif
}

void RTDOsdAdvanceUltraVividExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_ADVANCE);        
}

#if(_OSD_3D_FUNCTION == _ON)
//============Advance 3D==============//
void RTDOsdAdvance3DMenu(void)
{
    g_usBackupValue = GET_OSD_3D_STATUS();
    g_usAdjustValue = g_usBackupValue;
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_SELECT);
}
void RTDOsdAdvance3DLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_ULTRA_VIVID);
}
void RTDOsdAdvance3DRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_ASPECTRATIO);
}
void RTDOsdAdvance3DExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_ADVANCE);        
}
#endif //End of #if(_OSD_3D_FUNCTION == _ON)

//============Advance Aspect Ratio Select==============//
void RTDOsdAdvanceAspectRatioSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_ASPECT_RATIO_TYPE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    if(GET_OSD_ASPECT_RATIO_TYPE() == _ASPECT_RATIO_ORIGIN)
    {
        g_usBackupValue = GET_OSD_ASPECT_ORIGIN_RATIO();
        RTDOsdDispPageItem(_OSD_ASPECT_ORIGIN_RATIO);
        RTDOsdDispSelectItem(_OSD_ASPECT_ORIGIN_RATIO);
    }
    else
#endif
    {
        RTDOsdDispWindowZoomOut(_OSD_ADVANCE_ASPECTRATIO);    
    }
}
void RTDOsdAdvanceAspectRatioSelectLeft(void)
{
    if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
    {
        RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_ASPECTRATIO_SELECT);

#if(_ASPECT_RATIO_SUPPORT == _ON)
        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLW(_OFF);
#endif
    }
}
void RTDOsdAdvanceAspectRatioSelectRight(void)
{
    RTDOsdAdvanceAspectRatioSelectLeft();
}
void RTDOsdAdvanceAspectRatioSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_ASPECT_RATIO_TYPE())
    {
        SET_OSD_ASPECT_RATIO_TYPE(g_usBackupValue);
        RTDOsdAdvanceAspectRatioSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_ASPECTRATIO);
}

//===================== OSD Aspect Original Ratio ====================//
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
void RTDOsdAspectOriginalRatioMenu(void)
{
    if(g_usBackupValue != GET_OSD_OVERSCAN_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }

    g_usBackupValue = GET_OSD_ASPECT_ORIGIN_RATIO();
    RTDOsdDispPageItem(_OSD_MAIN_ADVANCE);
    RTDOsdDispSelectItem(_OSD_ADVANCE_ASPECTRATIO);
}
void RTDOsdAspectOriginalRatioLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_ASPECT_ORIGIN_RATIO, GET_OSD_ASPECT_ORIGIN_RATIO());

    if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
    {
        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
        ScalerColorHLW(_OFF);
#endif
    }
}
void RTDOsdAspectOriginalRatioRight(void)
{
    RTDOsdAspectOriginalRatioLeft();
}
void RTDOsdAspectOriginalRatioExit(void)
{
    if(g_usBackupValue != GET_OSD_ASPECT_ORIGIN_RATIO())
    {
        SET_OSD_ASPECT_ORIGIN_RATIO(g_usBackupValue);
        RTDOsdAspectOriginalRatioLeft();
    }
    
    RTDOsdDispPageItem(_OSD_MAIN_ADVANCE);
    RTDOsdDispSelectItem(_OSD_ADVANCE_ASPECTRATIO);
}
#endif // End of #if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)

//============Advance Oversacn Select==============//
void RTDOsdAdvanceOversacnSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_OVERSCAN_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_OVERSCAN);
}
void RTDOsdAdvanceOversacnSelectLeft(void)
{
    if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
    {
        RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_OVERSCAN_SELECT);

#if(_OVERSCAN_SUPPORT == _ON)
        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
#endif
    }
}
void RTDOsdAdvanceOversacnSelectRight(void)
{
    RTDOsdAdvanceOversacnSelectLeft();
}
void RTDOsdAdvanceOversacnSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_OVERSCAN_STATUS())
    {
        SET_OSD_OVERSCAN_STATUS(g_usBackupValue);
        RTDOsdAdvanceOversacnSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_OVERSCAN);
}

//============Advance Overdrive Select==============//
void RTDOsdAdvanceOverdriveSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_OD_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }

    if(GET_OSD_OD_STATUS() == _ON)// OD Gain
    {
        g_usBackupValue = GET_OSD_OD_GAIN();
        RTDOsdDispPageItem(_OSD_ADVANCE_OD_GAIN_ADJUST);
    }
    else
    {    
        RTDOsdDispWindowZoomOut(_OSD_ADVANCE_OVERDRIVE);
    }
}
void RTDOsdAdvanceOverdriveSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_OVERDRIVE_SELECT);
    
#if(_OD_SUPPORT == _ON)    
    ScalerODControl(GET_OSD_OD_STATUS());
#endif
}
void RTDOsdAdvanceOverdriveSelectRight(void)
{
    RTDOsdAdvanceOverdriveSelectLeft();
}
void RTDOsdAdvanceOverdriveSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_OD_STATUS())
    {
        SET_OSD_OD_STATUS(g_usBackupValue);
        RTDOsdAdvanceOverdriveSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_OVERDRIVE);    
}

//============Advance Energy Star Select==============//
void RTDOsdAdvanceESSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_ES_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_ENERGY_STAR);
}
void RTDOsdAdvanceESSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_ENERGY_STAR_SELECT);

#if(_ENERGY_STAR_SUPPORT == _ON)
    UserCommonAdjustESDcrProcess(GET_OSD_ES_STATUS());
#endif
}
void RTDOsdAdvanceESSelectRight(void)
{
    RTDOsdAdvanceESSelectLeft();
}
void RTDOsdAdvanceESSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_ES_STATUS())
    {
        SET_OSD_ES_STATUS(g_usBackupValue);
        RTDOsdAdvanceESSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_ENERGY_STAR);    
}

//============Advance DDCCI Select==============//
void RTDOsdAdvanceDdcciSelectMenu(void)
{
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_DDCCI);
    if(g_usBackupValue != GET_OSD_DDCCI_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
}
void RTDOsdAdvanceDdcciSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_DDCCI_SELECT);
    ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());    
}
void RTDOsdAdvanceDdcciSelectRight(void)
{
    RTDOsdAdvanceDdcciSelectLeft();
}
void RTDOsdAdvanceDdcciSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_DDCCI_STATUS())
    {
        SET_OSD_DDCCI_STATUS(g_usBackupValue);
        RTDOsdAdvanceDdcciSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_DDCCI);    
}

//============Advance Ultra Vivid Select==============//
void RTDOsdAdvanceUltraVividSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_ULTRA_VIVID_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_ULTRA_VIVID);
}
void RTDOsdAdvanceUltraVividSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_ULTRA_VIVID_SELECT);
    
#if(_ULTRA_VIVID_SUPPORT == _ON)
    if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
    {
        UserCommonAdjustUltraVivid(_COLOR_SPACE_RGB);
    }
    else
    {
        UserCommonAdjustUltraVivid(_COLOR_SPACE_YPBPR);
    }
#endif // End of #if(_ULTRA_VIVID_SUPPORT == _ON) 

}
void RTDOsdAdvanceUltraVividSelectRight(void)
{
    RTDOsdAdvanceUltraVividSelectLeft();
}
void RTDOsdAdvanceUltraVividSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_ULTRA_VIVID_STATUS())
    {
        SET_OSD_ULTRA_VIVID_STATUS(g_usBackupValue);
        RTDOsdAdvanceUltraVividSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_ULTRA_VIVID);        
}

#if(_OSD_3D_FUNCTION == _ON)
//============Advance 3D Select==============//
void RTDOsdAdvance3DSelectMenu(void)
{   
    if(g_usBackupValue != g_usAdjustValue)
    {
        SET_OSD_3D_STATUS(g_usAdjustValue); 
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        RTDOsdDisplay3DEffectRealValueUpdate();
        
        if(((g_usBackupValue == _3D_OFF) && (GET_OSD_3D_STATUS() == _3D_2D_TO_3D)) ||
            ((g_usBackupValue == _3D_2D_TO_3D) && (GET_OSD_3D_STATUS() == _3D_OFF)))
        {
#if(_FRC_SUPPORT == _ON)            
            if(ScalerFRCCheckUseFRC() == _TRUE)
            {
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
            }
            else
#endif                
            {
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG);
                Scaler3DSetEffectDoubleBuffer();
            }
        } 
        else
        {
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
        }
        
    }    

    if(g_usAdjustValue == _3D_OFF)
    {
        RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D);        
    }
    else
    {    
        RTDOsdDispPageItem(_OSD_ADVANCE_3D_LR);
        RTDOsdDispSelectItem(_OSD_ADVANCE_3D_LR);
    }
}
void RTDOsdAdvance3DSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_3D_SELECT);
}
void RTDOsdAdvance3DSelectRight(void)
{
    RTDOsdAdvance3DSelectLeft();
}
void RTDOsdAdvance3DSelectExit(void)
{
    if(g_usBackupValue != g_usAdjustValue)
    {
        SET_OSD_3D_STATUS(g_usBackupValue); 
        RTDOsdAdvance3DSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D);        
}
#endif //End of #if(_OSD_3D_FUNCTION == _ON)

//============Advance OD Gain Adjust==============//
void RTDOsdAdvanceOdGainAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_OD_GAIN())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispPageItem(_OSD_MAIN_ADVANCE);
    RTDOsdDispSelectItem(_OSD_ADVANCE_OVERDRIVE);
}
void RTDOsdAdvanceOdGainAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_ADVANCE_OD_GAIN_ADJUST, GET_OSD_OD_GAIN());
#if(_OD_SUPPORT == _ON)
    ScalerODAdjustDeltaGain(GET_OSD_OD_GAIN());
#endif
}
void RTDOsdAdvanceOdGainAdjustRight(void)
{
    RTDOsdAdvanceOdGainAdjustLeft();
}
void RTDOsdAdvanceOdGainAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_OD_GAIN())
    {
        SET_OSD_OD_GAIN(g_usBackupValue); 
        RTDOsdAdvanceOdGainAdjustLeft();
    }
    RTDOsdDispPageItem(_OSD_MAIN_ADVANCE);
    RTDOsdDispSelectItem(_OSD_ADVANCE_OVERDRIVE);
}

#if(_OSD_3D_FUNCTION == _ON)
//============Advance 3D LR==============//
void RTDOsdAdvance3DLRMenu(void)
{
    g_usBackupValue = GET_OSD_3D_LR_STATUS();
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_LR_SELECT);
}
void RTDOsdAdvance3DLRLeft(void)
{
#if(_2D_TO_3D_FUNCTION == _ON)
    if(GET_OSD_3D_STATUS() == _3D_2D_TO_3D)
    {
        RTDOsdDispSelectItem(_OSD_ADVANCE_3D_CONVERGENCE_MODE);
    }
    else if(GET_OSD_3D_STATUS() == _3D_ON)
#endif
    {
        RTDOsdDispSelectItem(_OSD_ADVANCE_3D_3DTO2D);
    }
}
void RTDOsdAdvance3DLRRight(void)
{
    if((GET_OSD_3D_STATUS() == _3D_ON) && (GET_OSD_3D_3DTO2D() == _ON))
    {
        RTDOsdDispSelectItem(_OSD_ADVANCE_3D_FORMAT);
    }
    else
    {
        RTDOsdDispSelectItem(_OSD_ADVANCE_3D_EFFECT);
    }
}
void RTDOsdAdvance3DLRExit(void)
{
    RTDOsdDispPageItem(_OSD_MAIN_ADVANCE);
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D);
}

//============Advance 3D Effect==============//
void RTDOsdAdvance3DEffectMenu(void)
{
    g_usBackupValue = GET_OSD_3D_EFFECT();
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_EFFECT_ADJUST);
}
void RTDOsdAdvance3DEffectLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_LR);
}
void RTDOsdAdvance3DEffectRight(void)
{
#if(_2D_TO_3D_FUNCTION == _ON)
    if(GET_OSD_3D_STATUS() == _3D_2D_TO_3D)
    {
        RTDOsdDispSelectItem(_OSD_ADVANCE_3D_CONVERGENCE);
    }
    else if(GET_OSD_3D_STATUS() == _3D_ON)
#endif
    {
        RTDOsdDispSelectItem(_OSD_ADVANCE_3D_FORMAT);
    }
}
void RTDOsdAdvance3DEffectExit(void)
{
    RTDOsdAdvance3DLRExit();
}

//============Advance 3D Format==============//
void RTDOsdAdvance3DFormatMenu(void)
{
    g_usBackupValue = GET_OSD_3D_FORMAT_STATUS();
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_FORMAT_SELECT);
}
void RTDOsdAdvance3DFormatLeft(void)
{
    if((GET_OSD_3D_STATUS() == _3D_ON) && (GET_OSD_3D_3DTO2D() == _ON))
    {
        RTDOsdDispSelectItem(_OSD_ADVANCE_3D_LR);
    }
    else
    {
        RTDOsdDispSelectItem(_OSD_ADVANCE_3D_EFFECT);
    }
}
void RTDOsdAdvance3DFormatRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_3DTO2D);
}
void RTDOsdAdvance3DFormatExit(void)
{
    RTDOsdAdvance3DLRExit();
}

//============Advance 3D 3DTO2D==============//
void RTDOsdAdvance3D3DTO2DMenu(void)
{
    g_usBackupValue = GET_OSD_3D_3DTO2D();
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_3DTO2D_SELECT);
}
void RTDOsdAdvance3D3DTO2DLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_FORMAT);
}
void RTDOsdAdvance3D3DTO2DRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_LR);
}
void RTDOsdAdvance3D3DTO2DExit(void)
{
    RTDOsdAdvance3DLRExit();
}

//============Advance 3D LR Adjus==============//
void RTDOsdAdvance3DLRSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_3D_LR_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        
        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_LR);        
}
void RTDOsdAdvance3DLRSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_3D_LR_SELECT);
}
void RTDOsdAdvance3DLRSelectRight(void)
{
    RTDOsdAdvance3DLRSelectLeft();
}
void RTDOsdAdvance3DLRSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_3D_LR_STATUS())
    {
        SET_OSD_3D_LR_STATUS(g_usBackupValue);
        RTDOsdAdvance3DLRSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_LR);        
}

//============Advance 3D Effect Adjust==============//
void RTDOsdAdvance3DEffectAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_3D_EFFECT())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

#if(_FRC_SUPPORT == _ON)            
        if(ScalerFRCCheckUseFRC() == _TRUE)
        {
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
        }
        else
#endif                
        {
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG);
            Scaler3DSetEffectDoubleBuffer();
        }                
    }

    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_EFFECT);        
}
void RTDOsdAdvance3DEffectAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_ADVANCE_3D_EFFECT_ADJUST, GET_OSD_3D_EFFECT());
}
void RTDOsdAdvance3DEffectAdjustRight(void)
{
    RTDOsdAdvance3DEffectAdjustLeft();
}
void RTDOsdAdvance3DEffectAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_3D_EFFECT())
    {
        SET_OSD_3D_EFFECT(g_usBackupValue);
        RTDOsdAdvance3DEffectAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_EFFECT);        
}

//============Advance 3D Format Select==============//
void RTDOsdAdvance3DFormatSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_3D_FORMAT_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_FORMAT);        
}

void RTDOsdAdvance3DFormatSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_3D_FORMAT_SELECT);
}

void RTDOsdAdvance3DFormatSelectRight(void)
{
    RTDOsdAdvance3DFormatSelectLeft();
}

void RTDOsdAdvance3DFormatSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_3D_FORMAT_STATUS())
    {
        SET_OSD_3D_FORMAT_STATUS(g_usBackupValue);
        RTDOsdAdvance3DFormatSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_FORMAT);        
}

//============Advance 3D 3DTO2D Select==============//
void RTDOsdAdvance3D3DTO2DSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_3D_3DTO2D())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_3DTO2D);        
}
void RTDOsdAdvance3D3DTO2DSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_3D_3DTO2D_SELECT);
}
void RTDOsdAdvance3D3DTO2DSelectRight(void)
{
    RTDOsdAdvance3D3DTO2DSelectLeft();
}
void RTDOsdAdvance3D3DTO2DSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_3D_3DTO2D())
    {
        SET_OSD_3D_3DTO2D(g_usBackupValue);
        RTDOsdAdvance3D3DTO2DSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_3DTO2D);        
}

#if(_2D_TO_3D_FUNCTION == _ON)
//============Advance 3D Convergence==============//
void RTDOsdAdvance3DConvergenceMenu(void)
{
    g_usBackupValue = GET_OSD_3D_CONVERGENCE();
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_CONVERGENCE_SELECT);
}

void RTDOsdAdvance3DConvergenceLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_EFFECT);
}

void RTDOsdAdvance3DConvergenceRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_CONVERGENCE_MODE);
}

void RTDOsdAdvance3DConvergenceExit(void)
{
    RTDOsdAdvance3DLRExit();
}

//============Advance 3D Convergence Select==============//
void RTDOsdAdvance3DConvergenceSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_3D_CONVERGENCE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        
#if(_FRC_SUPPORT == _ON)            
        if(ScalerFRCCheckUseFRC() == _TRUE)
        {
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
        }
        else
#endif                
        {
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG);
            Scaler3DSetEffectDoubleBuffer();
        }      
    }

    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_CONVERGENCE);        
}

void RTDOsdAdvance3DConvergenceSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_3D_CONVERGENCE_SELECT);
}

void RTDOsdAdvance3DConvergenceSelectRight(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_3D_CONVERGENCE_SELECT);
}

void RTDOsdAdvance3DConvergenceSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_3D_CONVERGENCE())
    {
        SET_OSD_3D_CONVERGENCE(g_usBackupValue);
        RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_3D_CONVERGENCE_SELECT);
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_CONVERGENCE);        
}

//============Advance 3D Convergence Mode==============//
void RTDOsdAdvance3DConvergenceModeMenu(void)
{
    g_usBackupValue = GET_OSD_3D_CONVERGENCE_MODE();
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_CONVERGENCE_MODE_SELECT);
}

void RTDOsdAdvance3DConvergenceModeLeft(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_CONVERGENCE);
}

void RTDOsdAdvance3DConvergenceModeRight(void)
{
    RTDOsdDispSelectItem(_OSD_ADVANCE_3D_LR);
}

void RTDOsdAdvance3DConvergenceModeExit(void)
{
    RTDOsdAdvance3DLRExit();
}

//============Advance 3D Convergence Mode Select==============//
void RTDOsdAdvance3DConvergenceModeSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_3D_CONVERGENCE_MODE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        
#if(_FRC_SUPPORT == _ON)            
        if(ScalerFRCCheckUseFRC() == _TRUE)
        {
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
        }
        else
#endif                
        {
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG);
            Scaler3DSetEffectDoubleBuffer();
        }       
    }
    
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_CONVERGENCE_MODE);
}

void RTDOsdAdvance3DConvergenceModeSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_ADVANCE_3D_CONVERGENCE_MODE_SELECT);
}

void RTDOsdAdvance3DConvergenceModeSelectRight(void)
{
    RTDOsdAdvance3DConvergenceModeSelectLeft();
}

void RTDOsdAdvance3DConvergenceModeSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_3D_CONVERGENCE_MODE())
    {
        SET_OSD_3D_CONVERGENCE_MODE(g_usBackupValue);
        RTDOsdAdvance3DConvergenceModeSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_ADVANCE_3D_CONVERGENCE_MODE);
}
#endif // End of #if(_2D_TO_3D_FUNCTION == _ON)
#endif // End of #if(_OSD_3D_FUNCTION == _ON)

//============Input Auto==============//
void RTDOsdInputAutoMenu(void)
{
    SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

    if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
    {
        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
    }
}
void RTDOsdInputAutoLeft(void)
{
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    RTDOsdDispSelectItem(_OSD_INPUT_D1);
#elif(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    RTDOsdDispSelectItem(_OSD_INPUT_D0);
#elif(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_INPUT_A0);
#endif
}
void RTDOsdInputAutoRight(void)
{
#if(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_INPUT_A0);
#elif(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    RTDOsdDispSelectItem(_OSD_INPUT_D0);
#elif(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    RTDOsdDispSelectItem(_OSD_INPUT_D1);
#endif
}
void RTDOsdInputAutoExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_INPUT);        
}


//============Input A0==============//
#if(_VGA_SUPPORT == _ON)
void RTDOsdInputA0Menu(void)
{
    SET_FORCE_POW_SAV_STATUS(_FALSE);
    SysSourceSwitchInputPort(_A0_INPUT_PORT);
    SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);    

    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
    {
        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
    }
}
void RTDOsdInputA0Left(void)
{
#if(((_D0_INPUT_PORT_TYPE == _D0_NO_PORT) && (_D1_INPUT_PORT_TYPE == _D1_NO_PORT)) &&   \
    (_VGA_SUPPORT == _ON))
    RTDOsdDispSelectItem(_OSD_INPUT_A0);
#else
    RTDOsdDispSelectItem(_OSD_INPUT_AUTO);
#endif
}
void RTDOsdInputA0Right(void)
{
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    RTDOsdDispSelectItem(_OSD_INPUT_D0);
#elif(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    RTDOsdDispSelectItem(_OSD_INPUT_D1);
#elif(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_INPUT_A0);
#endif
}
void RTDOsdInputA0Exit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_INPUT);        
}
#endif // End of #if(_VGA_SUPPORT == _ON)

//============Input D0==============//
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
void RTDOsdInputD0Menu(void)
{
    SET_FORCE_POW_SAV_STATUS(_FALSE);
    SysSourceSwitchInputPort(_D0_INPUT_PORT);       
    SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
    
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
    {
        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
    }
}
void RTDOsdInputD0Left(void)
{
#if(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_INPUT_A0);
#else
    RTDOsdDispSelectItem(_OSD_INPUT_AUTO);
#endif
}
void RTDOsdInputD0Right(void)
{
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    RTDOsdDispSelectItem(_OSD_INPUT_D1);
#else
    RTDOsdDispSelectItem(_OSD_INPUT_AUTO);
#endif
}
void RTDOsdInputD0Exit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_INPUT);        
}
#endif // End of #if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

//============Input D1==============//
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
void RTDOsdInputD1Menu(void)
{
    SET_FORCE_POW_SAV_STATUS(_FALSE);
    SysSourceSwitchInputPort(_D1_INPUT_PORT);
    SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
    
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
    {
        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
    }
}
void RTDOsdInputD1Left(void)
{
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    RTDOsdDispSelectItem(_OSD_INPUT_D0);
#elif(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_INPUT_A0);
#else
    RTDOsdDispSelectItem(_OSD_INPUT_AUTO);
#endif
}
void RTDOsdInputD1Right(void)
{
    RTDOsdDispSelectItem(_OSD_INPUT_AUTO);
}
void RTDOsdInputD1Exit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_INPUT);            
}
#endif // End of #if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)

//============Audio Volume==============//
void RTDOsdAudioVolumeMenu(void)
{
    g_usBackupValue = GET_OSD_VOLUME();
    RTDOsdDispSelectItem(_OSD_AUDIO_VOLUME_ADJUST);    
    RTDOsdDispSliderAndNumber(_OSD_AUDIO_VOLUME_ADJUST, GET_OSD_VOLUME());
}
void RTDOsdAudioVolumeLeft(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_SOUNDMODE);
}
void RTDOsdAudioVolumeRight(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_MUTE);
}
void RTDOsdAudioVolumeExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_AUDIO);        
}

//============Audio Mute==============//
void RTDOsdAudioMuteMenu(void)
{
    g_usBackupValue = GET_OSD_VOLUME_MUTE();
    RTDOsdDispSelectItem(_OSD_AUDIO_MUTE_SELECT);
}
void RTDOsdAudioMuteLeft(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_VOLUME);
}
void RTDOsdAudioMuteRight(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_STANDALONE);
}
void RTDOsdAudioMuteExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_AUDIO);            
}

//============Audio StandAlone==============//
void RTDOsdAudioStandAloneMenu(void)
{
    g_usBackupValue = GET_OSD_AUDIO_STAND_ALONE();
    RTDOsdDispSelectItem(_OSD_AUDIO_STANDALONE_SELECT);
}
void RTDOsdAudioStandAloneLeft(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_MUTE);
}
void RTDOsdAudioStandAloneRight(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_SOURCE);
}
void RTDOsdAudioStandAloneExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_AUDIO);        
}

//============Audio Source==============//
void RTDOsdAudioSourceMenu(void)
{
    if((SysSourceGetSourceType() != _SOURCE_VGA) && (SysSourceGetSourceType() != _SOURCE_DVI))
    {
        g_usBackupValue = GET_OSD_AUDIO_SOURCE();
        RTDOsdDispSelectItem(_OSD_AUDIO_SOURCE_SELECT);
    }
}
void RTDOsdAudioSourceLeft(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_STANDALONE);
}
void RTDOsdAudioSourceRight(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_SOUNDMODE);
}
void RTDOsdAudioSourceExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_AUDIO);        
}

//============Audio Sound Mode==============//
void RTDOsdAudioSoundModeMenu(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_SOUNDMODE_SELECT);
}
void RTDOsdAudioSoundModeLeft(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_SOURCE);
}
void RTDOsdAudioSoundModeRight(void)
{
    RTDOsdDispSelectItem(_OSD_AUDIO_VOLUME);
}
void RTDOsdAudioSoundModeExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_AUDIO);            
}

//============Audio Volume Adjust==============//
void RTDOsdAudioVolumeAdjustMenu(void)
{
    if((g_usBackupValue != GET_OSD_VOLUME()) || (GET_OSD_VOLUME_MUTE() == _ON))
    {
        if(GET_OSD_VOLUME_MUTE() == _ON)
        {
            SET_OSD_VOLUME_MUTE(_OFF);
        }
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_AUDIO_VOLUME);
}
void RTDOsdAudioVolumeAdjustLeft(void)
{
    if(( GET_OSD_VOLUME_MUTE() == _ON) && (g_usBackupValue == GET_OSD_VOLUME())) 
    {
        RTDOsdDispOsdFunctionAdjust(_OSD_AUDIO_MUTE_SELECT);
        SET_OSD_VOLUME_MUTE(_ON);
    }
    RTDOsdDispSliderAndNumber(_OSD_AUDIO_VOLUME_ADJUST, GET_OSD_VOLUME());
    
#if(_AUDIO_SUPPORT == _ON)
    UserAdjustAudioVolume(GET_OSD_VOLUME());
#endif
}
void RTDOsdAudioVolumeAdjustRight(void)
{
    RTDOsdAudioVolumeAdjustLeft();
}
void RTDOsdAudioVolumeAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_VOLUME())
    {
        SET_OSD_VOLUME(g_usBackupValue);
        RTDOsdAudioVolumeAdjustLeft();
    }

    if(GET_OSD_VOLUME_MUTE() == _ON)
    {
        SET_OSD_VOLUME_MUTE(_ON);
        RTDOsdDispOsdFunctionAdjust(_OSD_AUDIO_MUTE_SELECT);
    }

    RTDOsdDispWindowZoomOut(_OSD_AUDIO_VOLUME);    
}

//============Audio Mute Select==============//
void RTDOsdAudioMuteSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_VOLUME_MUTE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_AUDIO_MUTE);    
}
void RTDOsdAudioMuteSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_AUDIO_MUTE_SELECT);
    
#if(_AUDIO_SUPPORT == _ON)
    UserAdjustAudioMuteSwitch();
#endif
}
void RTDOsdAudioMuteSelectRight(void)
{
    RTDOsdAudioMuteSelectLeft();
}
void RTDOsdAudioMuteSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_VOLUME_MUTE())
    {
        SET_OSD_VOLUME_MUTE(g_usBackupValue);
        RTDOsdAudioMuteSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_AUDIO_MUTE);    
}

//============Audio StandAlone Select==============//
void RTDOsdAudioStandAloneSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_AUDIO_STAND_ALONE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_AUDIO_STANDALONE);    
}
void RTDOsdAudioStandAloneSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_AUDIO_STANDALONE_SELECT);
}
void RTDOsdAudioStandAloneSelectRight(void)
{
    RTDOsdAudioStandAloneSelectLeft();
}
void RTDOsdAudioStandAloneSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_AUDIO_STAND_ALONE())
    {
        SET_OSD_AUDIO_STAND_ALONE(g_usBackupValue);
        RTDOsdAudioStandAloneSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_AUDIO_STANDALONE);    
}

//============Audio Source==============//
void RTDOsdAudioSourceSelectMenu(void)
{
    if(g_usBackupValue != GET_OSD_AUDIO_SOURCE())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_AUDIO_SOURCE);
}
void RTDOsdAudioSourceSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_AUDIO_SOURCE_SELECT);
    
#if(_AUDIO_SUPPORT == _ON)
#if(_EMBEDDED_DAC_SUPPORT == _ON)
    UserAdjustAudioSource();
#endif
#endif
}
void RTDOsdAudioSourceSelectRight(void)
{
    RTDOsdAudioSourceSelectLeft();
}
void RTDOsdAudioSourceSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_AUDIO_SOURCE())
    {
        SET_OSD_AUDIO_SOURCE(g_usBackupValue);
        RTDOsdAudioSourceSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_AUDIO_SOURCE);
}

//============Audio Sound Mode Select==============//
void RTDOsdAudioSoundModeSelectMenu(void)
{
    RTDOsdDispWindowZoomOut(_OSD_AUDIO_SOUNDMODE);
}
void RTDOsdAudioSoundModeSelectLeft(void)
{

}
void RTDOsdAudioSoundModeSelectRight(void)
{

}
void RTDOsdAudioSoundModeSelectExit(void)
{
    RTDOsdDispWindowZoomOut(_OSD_AUDIO_SOUNDMODE);    
}

//============Other Reset==============//
void RTDOsdOtherResetMenu(void)
{
    BYTE ucTemp = GET_OSD_LANGUAGE();
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLW(_OFF);
#endif

    RTDOsdFuncDisableOsd();

    UserCommonNVRamRestoreSystemData();
    RTDNVRamRestoreOSDData();

    RTDNVRamRestoreUserColorSetting();    
    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
    RTDNVRamRestoreSixColorData();

    RTDNVRamRestoreBriCon();
    RTDNVRamRestoreBacklight();
    
#if(_VGA_SUPPORT == _ON)
    UserCommonNVRamRestoreModeUserData();
    
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        SET_VGA_MODE_DO_FIRST_AUTO(_TRUE);
        UserCommonModeSearchInitalUserAndCenterData(g_stVGAModeUserData.ucModeNumber);
        UserCommonNVRamSaveModeUserData();
    }
#endif

    if(ucTemp != GET_OSD_LANGUAGE())
    {
        SET_OSD_LANGUAGE(ucTemp);
        RTDNVRamSaveOSDData();
    }

    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);

    SET_OSD_STATE(_MENU_NONE);
}

void RTDOsdOtherResetLeft(void)
{
#if(_OSD_3D_FUNCTION == _ON)
    RTDOsdDispSelectItem(_OSD_OTHER_3DOSD);
#else
    RTDOsdDispSelectItem(_OSD_OTHER_ROTATE);
#endif
}
void RTDOsdOtherResetRight(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_MENUTIME);    
}
void RTDOsdOtherResetExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_OTHERS);        
}

//============Other Menu Time==============//
void RTDOsdOtherMenuTimeMenu(void)
{
    g_usBackupValue = GET_OSD_TIME_OUT();
    RTDOsdDispSelectItem(_OSD_OTHER_MENUTIME_ADJUST);    
}
void RTDOsdOtherMenuTimeLeft(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_RESET);
}
void RTDOsdOtherMenuTimeRight(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_OSD_H_POS);
}
void RTDOsdOtherMenuTimeExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_OTHERS);        
}

//============Other H Position==============//
void RTDOsdOtherHPositionMenu(void)
{
    g_usBackupValue = GET_OSD_HPOS();
    RTDOsdDispSelectItem(_OSD_OTHER_OSD_H_POS_ADJUST);    
}
void RTDOsdOtherHPositionLeft(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_MENUTIME);
}
void RTDOsdOtherHPositionRight(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_OSD_V_POS);
}
void RTDOsdOtherHPositionExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_OTHERS);        
}

//============Other V Position==============//
void RTDOsdOtherVPositionMenu(void)
{
    g_usBackupValue = GET_OSD_VPOS();
    RTDOsdDispSelectItem(_OSD_OTHER_OSD_V_POS_ADJUST);    
}
void RTDOsdOtherVPositionLeft(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_OSD_H_POS);
}
void RTDOsdOtherVPositionRight(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_LANGUAGE);
}
void RTDOsdOtherVPositionExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_OTHERS);            
}

//============Other Language==============//
void RTDOsdOtherLanguageMenu(void)
{
    g_usBackupValue = GET_OSD_LANGUAGE();
    g_usAdjustValue = g_usBackupValue;
    RTDOsdDispSelectItem(_OSD_OTHER_LANGUAGE_SELECT);
}
void RTDOsdOtherLanguageLeft(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_OSD_V_POS);
}
void RTDOsdOtherLanguageRight(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_TRANS);
}
void RTDOsdOtherLanguageExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_OTHERS);        
}

//============Other Trans==============//
void RTDOsdOtherTransMenu(void)
{
    g_usBackupValue = GET_OSD_TRANSPARENCY_STATUS();
    RTDOsdDispSelectItem(_OSD_OTHER_TRANS_ADJUST);    
}
void RTDOsdOtherTransLeft(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_LANGUAGE);
}
void RTDOsdOtherTransRight(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_ROTATE);
}
void RTDOsdOtherTransExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_OTHERS);        
}

//============Other Rotate==============//
void RTDOsdOtherRotateMenu(void)
{
#if(_OSD_3D_FUNCTION == _ON)
    if(GET_OSD_3DOSD_STATUS() == _OFF)
#endif     
    {
        g_usBackupValue = GET_OSD_ROTATE_STATUS();
        g_usAdjustValue = g_usBackupValue;
        RTDOsdDispSelectItem(_OSD_OTHER_ROTATE_SELECT);
    }
}
void RTDOsdOtherRotateLeft(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_TRANS);
}
void RTDOsdOtherRotateRight(void)
{
#if(_OSD_3D_FUNCTION == _ON)
    RTDOsdDispSelectItem(_OSD_OTHER_3DOSD);
#else
    RTDOsdDispSelectItem(_OSD_OTHER_RESET);
#endif
}
void RTDOsdOtherRotateExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_OTHERS);        
}

#if(_OSD_3D_FUNCTION == _ON)
//============Other 3D OSD==============//
void RTDOsdOther3DOSDMenu(void)
{
    g_usBackupValue = GET_OSD_3DOSD_STATUS();
    RTDOsdDispSelectItem(_OSD_OTHER_3DOSD_SELECT);
}

void RTDOsdOther3DOSDLeft(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_ROTATE);
}

void RTDOsdOther3DOSDRight(void)
{
    RTDOsdDispSelectItem(_OSD_OTHER_RESET);
}

void RTDOsdOther3DOSDExit(void)
{
    RTDOsdDispBackToMainIten(_OSD_MAIN_OTHERS);        
}
#endif //End of #if(_OSD_3D_FUNCTION == _ON)

//============Other Menu Time Adjust==============//
void RTDOsdOtherMenuTimeAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_TIME_OUT())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_MENUTIME);
}
void RTDOsdOtherMenuTimeAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_OTHER_MENUTIME_ADJUST, GET_OSD_TIME_OUT());
}
void RTDOsdOtherMenuTimeAdjustRight(void)
{
    RTDOsdOtherMenuTimeAdjustLeft();
}
void RTDOsdOtherMenuTimeAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_TIME_OUT())
    {
        SET_OSD_TIME_OUT(g_usBackupValue);
        RTDOsdOtherMenuTimeAdjustLeft();
        ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_MENUTIME);        
}

//============Other H Position Adjust==============//
void RTDOsdOtherHPositionAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_HPOS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_OSD_H_POS);
}
void RTDOsdOtherHPositionAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_OTHER_OSD_H_POS_ADJUST, GET_OSD_HPOS());
    RTDOsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());
}
void RTDOsdOtherHPositionAdjustRight(void)
{
    RTDOsdOtherHPositionAdjustLeft();
}
void RTDOsdOtherHPositionAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_HPOS())
    {
        SET_OSD_HPOS(g_usBackupValue);
        RTDOsdOtherHPositionAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_OSD_H_POS);    
}

//============Other V Position Adjust==============//
void RTDOsdOtherVPositionAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_VPOS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_OSD_V_POS);
}
void RTDOsdOtherVPositionAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_OTHER_OSD_V_POS_ADJUST, GET_OSD_VPOS());
    RTDOsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());
}
void RTDOsdOtherVPositionAdjustRight(void)
{
    RTDOsdOtherVPositionAdjustLeft();
}
void RTDOsdOtherVPositionAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_VPOS())
    {
        SET_OSD_VPOS(g_usBackupValue);
        RTDOsdOtherVPositionAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_OSD_V_POS);    
}

//============Other Language Select==============//
void RTDOsdOtherLanguageSelectMenu(void)
{
    if(g_usBackupValue != g_usAdjustValue)
    {
        SET_OSD_LANGUAGE(g_usAdjustValue);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        RTDOsdDispPageItem(_OSD_MAIN_OTHERS);
        RTDOsdDispSelectItem(_OSD_OTHER_LANGUAGE);
    }
    else
    {
        RTDOsdDispWindowZoomOut(_OSD_OTHER_LANGUAGE);
    }    
}
void RTDOsdOtherLanguageSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_OTHER_LANGUAGE_SELECT);
}
void RTDOsdOtherLanguageSelectRight(void)
{
    RTDOsdOtherLanguageSelectLeft();
}
void RTDOsdOtherLanguageSelectExit(void)
{
    if(g_usBackupValue != g_usAdjustValue)
    {
        g_usAdjustValue = g_usBackupValue;
        RTDOsdOtherLanguageSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_LANGUAGE);    
}

//============Other Trans Adjust==============//
void RTDOsdOtherTransAdjustMenu(void)
{
    if(g_usBackupValue != GET_OSD_TRANSPARENCY_STATUS())
    {
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_TRANS); 
}
void RTDOsdOtherTransAdjustLeft(void)
{
    RTDOsdDispSliderAndNumber(_OSD_OTHER_TRANS_ADJUST, GET_OSD_TRANSPARENCY_STATUS());
    RTDOsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());            
}
void RTDOsdOtherTransAdjustRight(void)
{
    RTDOsdOtherTransAdjustLeft();
}
void RTDOsdOtherTransAdjustExit(void)
{
    if(g_usBackupValue != GET_OSD_TRANSPARENCY_STATUS())
    {
        SET_OSD_TRANSPARENCY_STATUS(g_usBackupValue);
        RTDOsdOtherTransAdjustLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_TRANS);    
}

//============Other Rotate Select==============//
void RTDOsdOtherRotateSelectMenu(void)
{
    if(g_usBackupValue != g_usAdjustValue)
    {
        g_usBackupValue = g_usAdjustValue;
        SET_OSD_ROTATE_STATUS(g_usAdjustValue);
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        RTDOsdDispOsdRotateSwitch();
    }
    else
    {
        RTDOsdDispWindowZoomOut(_OSD_OTHER_ROTATE);    
    }
}
void RTDOsdOtherRotateSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_OTHER_ROTATE_SELECT);
}
void RTDOsdOtherRotateSelectRight(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_OTHER_ROTATE_SELECT);
}
void RTDOsdOtherRotateSelectExit(void)
{
    if(g_usBackupValue != g_usAdjustValue)
    {
        g_usAdjustValue = g_usBackupValue;
        RTDOsdDispOsdFunctionAdjust(_OSD_OTHER_ROTATE_SELECT);
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_ROTATE);        
}

#if(_OSD_3D_FUNCTION == _ON)
//============Other 3D OSD Select==============//
void RTDOsdOther3DOSDSelectMenu(void)
{
    RTDOsdDispWindowZoomOut(_OSD_OTHER_3DOSD);
    if(g_usBackupValue != GET_OSD_3DOSD_STATUS())
    {
        SET_OSD_ROTATE_STATUS(_OFF);
        RTDOsdDispOsd3DOSDSwitch();
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    }
}

void RTDOsdOther3DOSDSelectLeft(void)
{
    RTDOsdDispOsdFunctionAdjust(_OSD_OTHER_3DOSD_SELECT);
}

void RTDOsdOther3DOSDSelectRight(void)
{
    RTDOsdOther3DOSDSelectLeft();
}

void RTDOsdOther3DOSDSelectExit(void)
{
    if(g_usBackupValue != GET_OSD_3DOSD_STATUS())
    {
        SET_OSD_3DOSD_STATUS(g_usBackupValue);
        RTDOsdOther3DOSDSelectLeft();
    }
    RTDOsdDispWindowZoomOut(_OSD_OTHER_3DOSD);
}
#endif // End of #if(_OSD_3D_FUNCTION == _ON)

//============Hot Key Auto Source==============//
void RTDOsdHotKeyAutoSourceMenu(void)
{
    RTDOsdInputAutoMenu();
}
void RTDOsdHotKeyAutoSourceLeft(void)
{
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    RTDOsdDispSelectItem(_OSD_D1_HOTKEY);
#elif(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    RTDOsdDispSelectItem(_OSD_D0_HOTKEY);
#elif(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_A0_HOTKEY);
#endif
}
void RTDOsdHotKeyAutoSourceRight(void)
{
#if(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_A0_HOTKEY);
#elif(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    RTDOsdDispSelectItem(_OSD_D0_HOTKEY);
#elif(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    RTDOsdDispSelectItem(_OSD_D1_HOTKEY);
#endif
}
void RTDOsdHotKeyAutoSourceExit(void)
{
    RTDOsdDisplayDisableOsd();

    if(SysModeGetModeState() == _MODE_STATUS_NOSUPPORT)
    {
        SysPowerSetTargetPowerStatus(_POWER_STATUS_NOSUPPORT_SAVING);
    }
    else if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
    {
        SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
    }
}

//============Hot Key A0==============//
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
void RTDOsdHotKeyA0Menu(void)
{
    RTDOsdInputA0Menu();
}
void RTDOsdHotKeyA0Left(void)
{
#if(((_D0_INPUT_PORT_TYPE == _D0_NO_PORT) && (_D1_INPUT_PORT_TYPE == _D1_NO_PORT)) &&   \
    (_VGA_SUPPORT == _ON))
    RTDOsdDispSelectItem(_OSD_A0_HOTKEY);
#else
    RTDOsdDispSelectItem(_OSD_AUTO_SOURCE_HOTKEY);
#endif
}
void RTDOsdHotKeyA0Right(void)
{
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    RTDOsdDispSelectItem(_OSD_D0_HOTKEY);
#elif(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    RTDOsdDispSelectItem(_OSD_D1_HOTKEY);
#elif(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_A0_HOTKEY);
#endif
}
void RTDOsdHotKeyA0Exit(void)
{
    RTDOsdHotKeyAutoSourceExit();
}
#endif // End of #if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)

//============Hot Key D0==============//
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
void RTDOsdHotKeyD0Menu(void)
{
    RTDOsdInputD0Menu();
}
void RTDOsdHotKeyD0Left(void)
{
#if(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_A0_HOTKEY);
#else
    RTDOsdDispSelectItem(_OSD_AUTO_SOURCE_HOTKEY);
#endif
}
void RTDOsdHotKeyD0Right(void)
{
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    RTDOsdDispSelectItem(_OSD_D1_HOTKEY);
#else
    RTDOsdDispSelectItem(_OSD_AUTO_SOURCE_HOTKEY);
#endif
}
void RTDOsdHotKeyD0Exit(void)
{
    RTDOsdHotKeyAutoSourceExit();
}
#endif // End of #if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

//============Hot Key D1==============//
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
void RTDOsdHotKeyD1Menu(void)
{
    RTDOsdInputD1Menu();
}
void RTDOsdHotKeyD1Left(void)
{
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    RTDOsdDispSelectItem(_OSD_D0_HOTKEY);
#elif(_VGA_SUPPORT == _ON)
    RTDOsdDispSelectItem(_OSD_A0_HOTKEY);
#else
    RTDOsdDispSelectItem(_OSD_AUTO_SOURCE_HOTKEY);
#endif
}
void RTDOsdHotKeyD1Right(void)
{
    RTDOsdDispSelectItem(_OSD_AUTO_SOURCE_HOTKEY);
}
void RTDOsdHotKeyD1Exit(void)
{
    RTDOsdHotKeyAutoSourceExit();
}
#endif // #if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)

#endif//#if(_OSD_TYPE == _REALTEK_2011_OSD)
