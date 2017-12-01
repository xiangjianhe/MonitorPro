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
// ID Code      : NoneOSD.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __NONE_OSD__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _NONE_OSD)

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

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserOsdHandler(void);
void NoneOsdSystemFlowProc(void);
void NoneOsdEventMsgProc(void);

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
    NoneOsdSystemFlowProc();
    NoneOsdEventMsgProc();
}

//--------------------------------------------------
// Description  : OSD system flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void NoneOsdSystemFlowProc(void)
{        
    switch(SysPowerGetPowerStatus())
    {
        case _POWER_STATUS_OFF:

            break;
            
        case _POWER_STATUS_SAVING:

            break;
            
        case _POWER_STATUS_NORMAL:

            break;
    }

    switch(SysModeGetModeState())
    {
        case _MODE_STATUS_POWER_OFF:

            break;        
            
        case _MODE_STATUS_INITIAL:

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

#if(_FACTORY_RTD_QC_SUPPORT == _ON)
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_FACTORY_MODE);
#endif            
            break;
            
        case _MODE_STATUS_NOSUPPORT:
        case _MODE_STATUS_NOSIGNAL:

            if(SysModeGetModeStateChange()== _TRUE)
            {
                if((SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) || (SysPowerGetPowerStatus() == _POWER_STATUS_NOSUPPORT_SAVING))
                {
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_NOSUPPORT_SAVING);
                }
                else
                {
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
                }
            }

#if(_FACTORY_RTD_QC_SUPPORT == _ON)            
            SysModeSetFreeRun();
            ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);
            ScalerDDomainBackgroundEnable(_ENABLE);
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerDDomainBackgroundSetColor(0xFF, 0x00, 0x00);
            ScalerTimerDelayXms(500);
            ScalerDDomainBackgroundSetColor(0x00, 0xFF, 0x00);
            ScalerTimerDelayXms(500);
            ScalerDDomainBackgroundSetColor(0x00, 0x00, 0xFF);
            ScalerTimerDelayXms(500);            
            ScalerDDomainBackgroundEnable(_DISABLE);            
            UserInterfacePanelPowerAction(_BACKLIGHT_OFF);            
            SysModeSetResetTarget(_MODE_ACTION_RESET_TO_FACTORY_MODE);
#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)

            break;
            
        case _MODE_STATUS_POWER_SAVING:

            break;

        case _MODE_STATUS_FACTORY:

#if(_FACTORY_RTD_QC_SUPPORT == _ON)
            NoneFactoryQCFlow(SysSourceGetInputPort());
#endif

            break;
            
        default:

            break;
    }

    if(GET_KEYMESSAGE() < _KEY_AMOUNT)
    {
        (*OperationTable[GET_OSD_STATE()][GET_KEYMESSAGE()])();
    }        
}

//--------------------------------------------------
// Description  : OSD event message processing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void NoneOsdEventMsgProc(void)
{
    switch(GET_OSD_EVENT_MESSAGE())
    {

#if(_VGA_SUPPORT == _ON)        
        case _OSDEVENT_DO_AUTO_CONFIG_MSG:

            UserCommonAutoConfig();

            break;
#endif

    }

    SET_OSD_EVENT_MESSAGE(_OSDEVENT_NONE_MSG);
}

//-----------------------------------
//    Menu None
//-----------------------------------
void NoneOsdNoneMenu(void)
{
}
void NoneOsdNoneLeft(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        // Perform auto-color for RGB
        if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_RGB) == _AUTO_SUCCESS)
        {
            ScalerAutoGetAutoColorResult(&g_stAdcData);
            UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);

#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_FORMULA))
            // Calculate YPbPr gain/offset using formula
            g_stAdcData = ScalerAutoBalanceYPbPrFromFormula(&g_stAdcData);
            UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);

            // Restore RGB gain/offset
            ScalerAutoGetAutoColorResult(&g_stAdcData);
#endif
        }
        else
        {
            UserCommonNVRamRestoreADCSetting();
        }
    }
#endif // End of #if(_VGA_SUPPORT == _ON)
}
void NoneOsdNoneRight(void)
{
#if(_VGA_SUPPORT == _ON)
    UserCommonAutoConfig();
#endif
}
void NoneOsdNoneExit(void)
{
}

#endif//#if(_OSD_TYPE == _NONE_OSD)
