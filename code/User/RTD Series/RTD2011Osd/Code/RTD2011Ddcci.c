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
// ID Code      : RTDDdcci.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_DDCCI__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2011_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

#define _DDCCI_FIRMWARE_VERSION                     0x01

#define _DDCCI_BlACKLEVEL_DEFAULT                   0x50

// RC
#define _DDCCI_CMD_GetVCP_RC_NO_ERROR               0x00
#define _DDCCI_CMD_GetVCP_RC_UNSUPPORTED            0x01

// TP
#define _DDCCI_CMD_GetVCP_TP_SET_PARAMETER          0x00
#define _DDCCI_CMD_GetVCP_TP_MOMENTARY              0x01

//--------------------------------------------------
// Definitions of Contrast Range (Real Value)
//--------------------------------------------------
#define _COLORTEMP_USER_MAX                         255
#define _COLORTEMP_USER_MIN                         0
#define _COLORTEMP_USER_CENTER                      (((_COLORTEMP_USER_MAX - _COLORTEMP_USER_MIN) / 2) + _COLORTEMP_USER_MIN)


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
BYTE code tCOLORPRESET_VALUE[] = {0x08, 0x06, 0x05, 0x04, 0x01, 0x0B, 0x02};

BYTE code tINPUTSOURCEPORT[] = {0x01, 0x0F, 0x03}; //{0x0f, 0x03, 0x01};

BYTE code tLANGUAGEDEFINE[] = {0x02, 0x03, 0x04, 0x0a, 0x01, 0x0d, 0x06};



//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucDdcciRedBlackLevel   = _DDCCI_BlACKLEVEL_DEFAULT;
BYTE g_ucDdcciGreenBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;
BYTE g_ucDdcciBlueBlackLevel  = _DDCCI_BlACKLEVEL_DEFAULT;
BYTE g_ucDdcciNewControlValue = 1;
BYTE g_ucDdcciActiveValue     = 0;
BYTE g_ucColorTempUnSupport   = 0;

bit g_bForcePowSavStatus = _FALSE;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserDdcciHandler(void);
void RTDDdcciGetVCPFeature(void);
bit RTDDdcciSetVCPFeatureCheck(void);
void RTDDdcciSetVCPFeature(void);
void RTDDdcciResetAllSettings(void);
void RTDDdcciColorReset(void);

//--------------------------------------------------
// Description  : DDC Handler Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserDdcciHandler(void)
{
    if(GET_OSD_DDCCI_STATUS() == _ON)
    {    
        // Check if Data is needed to be received
        // Reply data to source according to the request
        if(GET_RUN_DDCCI_COMMAND() == _SUCCESS)
        {			
            switch(g_ucDdcciRxBuf[_DDCCI_COMMAND])
            {
                case _DDCCI_CMD_GET_VCP_FEATURE:
                    RTDDdcciGetVCPFeature();
                    break;

                case _DDCCI_CMD_SET_VCP_FEATURE:
                    RTDDdcciSetVCPFeature();
                    break;

                case _DDCCI_CMD_GET_TIMING_REPORT:
                    UserCommonDdcciGetTimingReport();
                    break;

                case _DDCCI_CMD_SAVE_CURRENT_SETTINGS:
                    break;

                case _DDCCI_CMD_CAPABILITIES_REQUEST:
                    UserCommonDdcciGetCapabilitiesRequest();
                    break;

                default:
                    UserCommonDdcciInitTx();
                    break;
            }

            UserCommonDdcciInitRx();

            SET_RUN_DDCCI_COMMAND(_FAIL);
        }
    }
}

//--------------------------------------------------
// Description  : DDCCI Get VCP Feature & VCP Feature Reply
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDDdcciGetVCPFeature(void)
{
    BYTE ucpTemp[2] = {0};
    
    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x08;
    g_ucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
    g_ucDdcciTxBuf[_DDCCI_RESULT_CODE] = _DDCCI_CMD_GetVCP_RC_NO_ERROR;
    g_ucDdcciTxBuf[_DDCCI_SINK_OPCODE] = g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE];

    switch(g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE])
    {
        case _DDCCI_OPCODE_VCP_NEW_CONTROL_VALUE:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x0002, g_ucDdcciNewControlValue);
            break;

        case _DDCCI_OPCODE_VCP_FACTORY_RESET:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_MOMENTARY, 0x0001, 0x00);
            break;

        case _DDCCI_OPCODE_VCP_RECAL_BRI_CON:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_MOMENTARY, 0x0001, 0x00);
            break;

        case _DDCCI_OPCODE_VCP_GEOMETRY_RESET:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_MOMENTARY, 0x0001, 0x00);
            break;

        case _DDCCI_OPCODE_VCP_COLOR_RESET:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_MOMENTARY, 0x0001, 0x00);
            break;

        case _DDCCI_OPCODE_VCP_COLOR_TEMP_INCREMENT:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x0000, 100);
            break;

        case _DDCCI_OPCODE_VCP_COLOR_TEMP_REQUEST:
            switch(GET_COLOR_TEMP_TYPE())
            {
                case _CT_SRGB:
                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (40 - 30));
                    break;

                case _CT_9300:
                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (93 - 30));
                    break;

                case _CT_7500:
                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (75 - 30));
                    break;

                case _CT_6500:
                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (65 - 30));
                    break;

                case _CT_5800:
                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (50 - 30));
                    break;

                default:
                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (65 - 30));
                    break;
            }
            break;

#if(_VGA_SUPPORT == _ON)
        case _DDCCI_OPCODE_VCP_CLOCK:

#if(_AUTO_CLOCK_SAVE_VALUE_OPTION == _CLOCK_SAVE_PERCENT_VALUE)
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_VGA_MODE_ADJUST_CLOCK());
#else
            {
                WORD usClockRangeMax = 0;
                WORD usClockRangeMin = 0;
                BYTE ucClock = 0;

                usClockRangeMax = UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MAX);
                usClockRangeMin = UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN);
                ucClock = UserCommonAdjustRealValueToPercent(GET_VGA_MODE_ADJUST_CLOCK(), usClockRangeMax, usClockRangeMin, (((usClockRangeMax - usClockRangeMin) / 2) + usClockRangeMin));

                UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, ucClock);
            }
#endif            
            break;

#endif // End of #if(_VGA_SUPPORT == _ON)

        case _DDCCI_OPCODE_VCP_BACKLIGHT:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,
                                      (WORD)UserCommonAdjustRealValueToPercent(GET_OSD_BACKLIGHT(),
                                      _BACKLIGHT_MAX, _BACKLIGHT_MIN, _BACKLIGHT_CENTER));
            break;

        case _DDCCI_OPCODE_VCP_CONTRAST:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,
                                      (WORD)UserCommonAdjustRealValueToPercent(GET_OSD_CONTRAST(),
                                      _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER));
            break;

        case _DDCCI_OPCODE_VCP_SELECT_COLOR_PRESET:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x000B, tCOLORPRESET_VALUE[GET_COLOR_TEMP_TYPE()]);
            break;

        case _DDCCI_OPCODE_VCP_RED_GAIN:
            ucpTemp[0] = GET_COLOR_TEMP_TYPE();

            if(GET_COLOR_TEMP_TYPE() != _CT_USER)
            {
                SET_COLOR_TEMP_TYPE(_CT_USER);

                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }

            ucpTemp[1] = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_R(),
                         _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER);

            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, ucpTemp[1]);

            SET_COLOR_TEMP_TYPE(ucpTemp[0]);

            RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            break;

        case _DDCCI_OPCODE_VCP_GREEN_GAIN:
            ucpTemp[0] = GET_COLOR_TEMP_TYPE();

            if(GET_COLOR_TEMP_TYPE() != _CT_USER)
            {
                SET_COLOR_TEMP_TYPE(_CT_USER);

                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }

            ucpTemp[1] = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_G(),
                         _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER);

            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, ucpTemp[1]);

            SET_COLOR_TEMP_TYPE(ucpTemp[0]);

            RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            break;

        case _DDCCI_OPCODE_VCP_BLUE_GAIN:
            ucpTemp[0] = GET_COLOR_TEMP_TYPE();

            if(GET_COLOR_TEMP_TYPE() != _CT_USER)
            {
                SET_COLOR_TEMP_TYPE(_CT_USER);

                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }

            ucpTemp[1] = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_B(),
                         _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER);

            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, ucpTemp[1]);

            SET_COLOR_TEMP_TYPE(ucpTemp[0]);

            RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            break;

        case _DDCCI_OPCODE_VCP_AUTO_SET_UP:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_MOMENTARY, 0x0001, 0x00);
            break;

#if(_VGA_SUPPORT == _ON) 
        case _DDCCI_OPCODE_VCP_AUTO_COLOR:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x01, 0x01);
            break;
#endif

        case _DDCCI_OPCODE_VCP_HPOSITION:
#if(_VGA_SUPPORT == _ON)            
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {
                UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_VGA_MODE_ADJUST_H_POSITION());
            }
            else
#endif
            {
                UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_DIGITAL_H_POSITION());
            }
                
            break;

        case _DDCCI_OPCODE_VCP_VPOSITION:
#if(_VGA_SUPPORT == _ON) 
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {
                UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_VGA_MODE_ADJUST_V_POSITION());
            }
            else
#endif
            {
                UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_DIGITAL_V_POSITION());
            }
            break;

#if(_VGA_SUPPORT == _ON) 
        case _DDCCI_OPCODE_VCP_CLOCK_PHASE:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_VGA_MODE_ADJUST_PHASE());                                            
            break;
#endif

        case _DDCCI_OPCODE_VCP_ACTIVE_CONTROL:
            break;

        case _DDCCI_OPCODE_VCP_INPUT_SOURCE:            
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x03, tINPUTSOURCEPORT[RTDOsdDisplayJudgeSourceType()]);
            break;

#if(_AUDIO_SUPPORT == _ENABLE)
        case _DDCCI_OPCODE_VCP_AUDIO_VOLUME:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_OSD_VOLUME());
            break;
#endif

        case _DDCCI_OPCODE_VCP_RED_BLACK_LEVEL:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, g_ucDdcciRedBlackLevel);
            break;

        case _DDCCI_OPCODE_VCP_GREEN_BLACK_LEVEL:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, g_ucDdcciGreenBlackLevel);
            break;

        case _DDCCI_OPCODE_VCP_BLUE_BLACK_LEVEL:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, g_ucDdcciBlueBlackLevel);
            break;

        case _DDCCI_OPCODE_VCP_PRODUCTKEY:
            g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 9;
            g_ucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
            break;

        case _DDCCI_OPCODE_VCP_HFREQ:
            ((DWORD *)pData)[0] = (DWORD)GET_INPUT_TIMING_HFREQ() * 100;
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 
                                      (WORD)(pData[0] << 4) + pData[1], 
                                      (WORD)(pData[3] << 4) + pData[4]);
            break;

        case _DDCCI_OPCODE_VCP_VFREQ:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0xFFFF, GET_INPUT_TIMING_VFREQ()*10);
            break;

        case _DDCCI_OPCODE_VCP_PANEL_TYPE:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x01, 1);
            break;

        case _DDCCI_OPCODE_VCP_MONITOR_TYPE:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x05, 3);
            break;

        case _DDCCI_OPCODE_VCP_APPLICATION_ENABLE:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0xFF, 0x5a);
            break;

        case _DDCCI_OPCODE_VCP_CONTROLLER_TYPE:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x0000, 0x0009);
            break;

        case _DDCCI_OPCODE_VCP_FW_LEVEL:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0xFFFF, _DDCCI_FIRMWARE_VERSION);
            break;

        case _DDCCI_OPCODE_VCP_OSD_ON_OFF:
            if(ScalerOsdGetOsdEnable())
            {
                pData[0] = 2;
            }
            else
            {
                pData[0] = 1;
            }
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x02, pData[0]);
            break;

        case _DDCCI_OPCODE_VCP_OSD_LANGUAGE:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x0D, tLANGUAGEDEFINE[GET_OSD_LANGUAGE()]);
            break;

        case _DDCCI_OPCODE_VCP_POWER_MODE:
            if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)
            {
                pData[0] = 4;
            }
            else if(SysPowerGetPowerStatus() == _POWER_STATUS_SAVING)
            {
                pData[0] = 2;
            }
            else
            {
                pData[0] = 1;
            }
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x0005, pData[0]);
            break;

        case _DDCCI_OPCODE_VCP_VERSION:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0xFFFF, 0x0202);
            break;

        case _DDCCI_OPCODE_VCP_SHARPNESS:
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x0004, GET_OSD_SHARPNESS());
            break;

        default:
            g_ucDdcciTxBuf[_DDCCI_RESULT_CODE] = _DDCCI_CMD_GetVCP_RC_UNSUPPORTED;
            break;
    }
    g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
}

//--------------------------------------------------
// Description  : Check DDCCI Set VCP Feature
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit RTDDdcciSetVCPFeatureCheck(void)
{
    switch(g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE])
    {
        case _DDCCI_OPCODE_VCP_FACTORY_RESET:
        case _DDCCI_OPCODE_VCP_RECAL_BRI_CON:
        case _DDCCI_OPCODE_VCP_GEOMETRY_RESET:
        case _DDCCI_OPCODE_VCP_COLOR_RESET:

            if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0)
            {
                return _FALSE;
            }

            break;

        case _DDCCI_OPCODE_VCP_NEW_CONTROL_VALUE:
        case _DDCCI_OPCODE_VCP_AUTO_SET_UP:
        case _DDCCI_OPCODE_VCP_AUTO_COLOR:

            if((g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0) || (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] >= 3))
            {
                return _FALSE;
            }

            break;

        case _DDCCI_OPCODE_VCP_SELECT_COLOR_PRESET:

            if((g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0) || (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] >= 0x0E))
            {
                return _FALSE;
            }

            break;

        case _DDCCI_OPCODE_VCP_OSD_LANGUAGE:

            if((g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0) || (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] >= 0x26))
            {
                return _FALSE;
            }

            break;

        case _DDCCI_OPCODE_VCP_POWER_MODE:

            if((g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0) || (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] >= 0x06))
            {
                return _FALSE;
            }

            break;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DDCCI Set VCP Feature
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDDdcciSetVCPFeature(void)
{
    BYTE ucTemp = 0;
    
    if(RTDDdcciSetVCPFeatureCheck() == _FAIL)
    {
        UserCommonDdcciInitTx();
    }
    else
    {
        switch(g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE])
        {
            case _DDCCI_OPCODE_VCP_NEW_CONTROL_VALUE:

                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x01)
                {
                    g_ucDdcciNewControlValue = 0x01;
                }

                break;

            case _DDCCI_OPCODE_VCP_SHARPNESS:

                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 4)
                {
                    g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 4;
                }
                SET_OSD_SHARPNESS(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);

                UserAdjustSharpness(GET_OSD_SHARPNESS());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

                break;

            case _DDCCI_OPCODE_VCP_INPUT_SOURCE:
                
                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x01)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysSourceSwitchInputPort(_A0_INPUT_PORT);
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x03)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysSourceSwitchInputPort(_D1_INPUT_PORT);
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x0F)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysSourceSwitchInputPort(_D0_INPUT_PORT);
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                }
                break;

            case _DDCCI_OPCODE_VCP_FACTORY_RESET:

                RTDDdcciResetAllSettings();

#if(_VGA_SUPPORT == _ON)
                if(SysSourceGetSourceType() == _SOURCE_VGA)
                {
                    UserCommonAutoConfig();
                }
                else
#endif
                {
                    SET_DIGITAL_H_POSITION(50);
                    SET_DIGITAL_V_POSITION(50);
                    UserCommonAdjustHPosition(GET_DIGITAL_H_POSITION());                                            
                    UserCommonAdjustVPosition(GET_DIGITAL_V_POSITION());
                }

                break;

            case _DDCCI_OPCODE_VCP_RECAL_BRI_CON:

                RTDNVRamRestoreBriCon();
                RTDNVRamRestoreBacklight();

                UserAdjustBacklight(GET_OSD_BACKLIGHT());
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBrightness(GET_OSD_BRIGHTNESS());
                break;

            case _DDCCI_OPCODE_VCP_GEOMETRY_RESET:

#if(_VGA_SUPPORT == _ON)
                if(SysSourceGetSourceType() == _SOURCE_VGA)
                {                    
                    UserCommonAutoConfig();
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
                }
                else
#endif
                {
                    SET_DIGITAL_H_POSITION(50);
                    SET_DIGITAL_V_POSITION(50);
                    UserCommonAdjustHPosition(GET_DIGITAL_H_POSITION());                                            
                    UserCommonAdjustVPosition(GET_DIGITAL_V_POSITION());
                }
            
                break;

            case _DDCCI_OPCODE_VCP_COLOR_RESET:

                RTDDdcciColorReset();

                break;

            case _DDCCI_OPCODE_VCP_COLOR_TEMP_REQUEST:

                g_ucColorTempUnSupport = (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] + 30);
                if(g_ucColorTempUnSupport >= 93)
                {
                    SET_COLOR_TEMP_TYPE(_CT_9300);
                }
                else if((g_ucColorTempUnSupport < 85) && (g_ucColorTempUnSupport >= 75))
                {
                    SET_COLOR_TEMP_TYPE(_CT_7500);
                }
                else if((g_ucColorTempUnSupport < 75) && (g_ucColorTempUnSupport >= 65))
                {
                    SET_COLOR_TEMP_TYPE(_CT_6500);
                }
                else if((g_ucColorTempUnSupport < 60) && (g_ucColorTempUnSupport >= 50))
                {
                    SET_COLOR_TEMP_TYPE(_CT_5800);
                }
                else
                {
                    SET_COLOR_TEMP_TYPE(_CT_SRGB);
                }

                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

                UserAdjustContrast(GET_OSD_CONTRAST());
                RTDOsdDisplayDisableOsd();

                break;

            case _DDCCI_OPCODE_VCP_CLOCK:

#if(_VGA_SUPPORT == _ON)
                if(SysSourceGetSourceType() == _SOURCE_VGA)
                {
                    if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
                    {
                        g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
                    }

#if(_AUTO_CLOCK_SAVE_VALUE_OPTION == _CLOCK_SAVE_PERCENT_VALUE)
                    SET_VGA_MODE_ADJUST_CLOCK(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
#else
                    {
                        WORD usClockRangeMax = 0;
                        WORD usClockRangeMin = 0;

                        usClockRangeMax = UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MAX);
                        usClockRangeMin = UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN);

                        SET_VGA_MODE_ADJUST_CLOCK(UserCommonAdjustPercentToRealValue(GET_VGA_MODE_ADJUST_CLOCK(), usClockRangeMax, usClockRangeMin, (((usClockRangeMax - usClockRangeMin) / 2) + usClockRangeMin)));
                    }
#endif
                    UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
                }
#endif // End of #if(_VGA_SUPPORT == _ON)

                break;

            case _DDCCI_OPCODE_VCP_BACKLIGHT:

                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
                {
                    g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
                }

                SET_OSD_BACKLIGHT(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE], _BACKLIGHT_MAX, _BACKLIGHT_MIN, _BACKLIGHT_CENTER));

                UserAdjustBacklight(GET_OSD_BACKLIGHT());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

                break;

            case _DDCCI_OPCODE_VCP_CONTRAST:

                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
                {
                    g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
                }

                SET_OSD_CONTRAST(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE], _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER));
                UserAdjustContrast(GET_OSD_CONTRAST());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);

                break;

            case _DDCCI_OPCODE_VCP_SELECT_COLOR_PRESET:

                switch(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE])
                {
                    case 0x0B:
                        SET_COLOR_TEMP_TYPE(_CT_USER);
                        break;

                    case 0x05:
                        SET_COLOR_TEMP_TYPE(_CT_6500);
                        break;

                    case 0x08:
                        SET_COLOR_TEMP_TYPE(_CT_9300);
                        break;

                    case 0x01:
                        SET_COLOR_TEMP_TYPE(_CT_SRGB);
                        break;

                    case 0x04:
                        SET_COLOR_TEMP_TYPE(_CT_5800);
                        break;

                    case 0x06:
                        SET_COLOR_TEMP_TYPE(_CT_7500);
                        break;

                    case 0x02:
                        SET_COLOR_TEMP_TYPE(_CT_OFF);
                        break;

                    default:
                        break;
                }

                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

                UserAdjustContrast(GET_OSD_CONTRAST());
                RTDOsdDisplayDisableOsd();

                break;

            case _DDCCI_OPCODE_VCP_RED_GAIN:                
                // Only write at customer color
                if(GET_COLOR_TEMP_TYPE() != _CT_USER)
                {
                    ucTemp = GET_COLOR_TEMP_TYPE();

                    SET_COLOR_TEMP_TYPE(_CT_USER);
                    
                    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

                    SET_COLOR_TEMP_TYPE_USER_R(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],
                                               _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));

                    RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());

                    SET_COLOR_TEMP_TYPE(ucTemp);

                    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
                }
                else
                {
                    SET_COLOR_TEMP_TYPE_USER_R(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],
                                               _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));

                    UserAdjustContrast(GET_OSD_CONTRAST());

                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
                }
                
                break;

            case _DDCCI_OPCODE_VCP_GREEN_GAIN:
                // Only write at customer color
                if(GET_COLOR_TEMP_TYPE() != _CT_USER)
                {
                    ucTemp = GET_COLOR_TEMP_TYPE();

                    SET_COLOR_TEMP_TYPE(_CT_USER);
                    
                    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

                    SET_COLOR_TEMP_TYPE_USER_G(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],
                                               _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));

                    RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());

                    SET_COLOR_TEMP_TYPE(ucTemp);

                    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
                }
                else
                {
                    SET_COLOR_TEMP_TYPE_USER_G(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],
                                               _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));

                    UserAdjustContrast(GET_OSD_CONTRAST());

                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
                }

                break;

            case _DDCCI_OPCODE_VCP_BLUE_GAIN:
                // Only write at customer color
                if(GET_COLOR_TEMP_TYPE() != _CT_USER)
                {
                    ucTemp = GET_COLOR_TEMP_TYPE();

                    SET_COLOR_TEMP_TYPE(_CT_USER);
                    
                    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

                    SET_COLOR_TEMP_TYPE_USER_B(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],
                                               _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));

                    RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());

                    SET_COLOR_TEMP_TYPE(ucTemp);

                    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
                }
                else
                {
                    SET_COLOR_TEMP_TYPE_USER_B(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],
                                               _COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));

                    UserAdjustContrast(GET_OSD_CONTRAST());

                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
                }

                break;

#if(_VGA_SUPPORT == _ON)
            case _DDCCI_OPCODE_VCP_AUTO_SET_UP:

                if(SysSourceGetSourceType() == _SOURCE_VGA)
                {
                    if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] != 0)
                    {
                        SET_OSD_EVENT_MESSAGE(_OSDEVENT_DO_AUTO_CONFIG_MSG);
                    }
                }

                break;
#endif

            case _DDCCI_OPCODE_VCP_HPOSITION:
#if(_VGA_SUPPORT == _ON)
                if(SysSourceGetSourceType() == _SOURCE_VGA)
                {
                    SET_VGA_MODE_ADJUST_H_POSITION(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
                    UserCommonAdjustHPosition(GET_VGA_MODE_ADJUST_H_POSITION());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
                }
                else
#endif
                {
                    SET_DIGITAL_H_POSITION(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
                    UserCommonAdjustHPosition(GET_DIGITAL_H_POSITION());
                }
                break;

            case _DDCCI_OPCODE_VCP_VPOSITION:
#if(_VGA_SUPPORT == _ON)
                if(SysSourceGetSourceType() == _SOURCE_VGA)
                {
                    if(abs(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] - GET_VGA_MODE_ADJUST_V_POSITION()) > 50)
                    {
                        SET_VGA_MODE_ADJUST_V_POSITION(50);
                    }
                    SET_VGA_MODE_ADJUST_V_POSITION(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
                    UserCommonAdjustVPosition(GET_VGA_MODE_ADJUST_V_POSITION());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
                }
                else
#endif
                {
                    SET_DIGITAL_V_POSITION(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
                    UserCommonAdjustVPosition(GET_DIGITAL_V_POSITION());
                }
                
                break;

#if(_VGA_SUPPORT == _ON)
            case _DDCCI_OPCODE_VCP_CLOCK_PHASE:

                if(SysSourceGetSourceType() == _SOURCE_VGA)
                {
                    if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
                    {
                        g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
                    }

                    SET_VGA_MODE_ADJUST_PHASE(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);

                    UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
                }

                break;
#endif

            case _DDCCI_OPCODE_VCP_ACTIVE_CONTROL:

                g_ucDdcciActiveValue = g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE];

                break;

#if(_AUDIO_SUPPORT == _ON)
            case _DDCCI_OPCODE_VCP_AUDIO_VOLUME:

                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
                {
                    g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
                }

                SET_OSD_VOLUME(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);

                UserAdjustAudioVolume(GET_OSD_VOLUME());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
                
                break;
#endif // End of #if(_AUDIO_SUPPORT == _ON)

            case _DDCCI_OPCODE_VCP_RED_BLACK_LEVEL:

                g_ucDdcciRedBlackLevel = g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE];
                // UserAdjustBrightness(g_ucDdcciRedBlackLevel);                            // Please don't delete

                break;

            case _DDCCI_OPCODE_VCP_GREEN_BLACK_LEVEL:

                g_ucDdcciGreenBlackLevel = g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE];
                // UserAdjustBrightness(g_ucDdcciGreenBlackLevel);                             // Please don't delete

                break;

            case _DDCCI_OPCODE_VCP_BLUE_BLACK_LEVEL:

                g_ucDdcciBlueBlackLevel = g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE];
                // UserAdjustBrightness(g_ucDdcciGreenBlackLevel);                             // Please don't delete

                break;

            case _DDCCI_OPCODE_VCP_POWER_MODE:

                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 5)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 4)
                {
                    SET_FORCE_POW_SAV_STATUS(_TRUE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 1)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);

#if(_SUPER_LOW_POWER_SUPPORT == _ON)
                    if(UserCommonNVRamGetSystemData(_SLP_AC_OFF_DETECT) == _OFF)
                    {
                        // Set SLP No AC Status
                        UserCommonNVRamSetSystemData(_SLP_AC_OFF_DETECT, _ON);

                        // Save System Power Status Data.
                        UserCommonNVRamSaveSystemData();
                    }
#endif
                }

                break;

            case _DDCCI_OPCODE_VCP_OSD_LANGUAGE:

                switch(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE])
                {
                    case 0x01:
                        SET_OSD_LANGUAGE(_CHINESE_T);
                        break;

                    case 0x02:
                        SET_OSD_LANGUAGE(_ENGLISH);
                        break;

                    case 0x03:
                        SET_OSD_LANGUAGE(_FRENCH);
                        break;

                    case 0x04:
                        SET_OSD_LANGUAGE(_GERMAN);
                        break;

                    case 0x0A:
                        SET_OSD_LANGUAGE(_SPANISH);
                        break;

                    case 0x06:
                        SET_OSD_LANGUAGE(_JAPAN);
                        break;

                    case 0x0D:
                        SET_OSD_LANGUAGE(_CHINESE_S);
                        break;

                    default:
                        break;
                }

                RTDOsdDisplayDisableOsd();
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

                break;

            case _DDCCI_OPCODE_VCP_OSD_ON_OFF:

                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 1)
                {
                    RTDOsdDisplayDisableOsd();
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 2)
                {
                    RTDOsdFuncEnableOsd();
                }

                break;

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
            case _DDCCI_OPCODE_VCP_DISP_CALIBRATION:

                UserCommonDdcciDispCalibProcess();

                break;
#endif

            default:

                UserCommonDdcciInitTx();

                break;
        }
    }
}

//--------------------------------------------------
// Description  : Reset monitor
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDDdcciResetAllSettings(void)
{
    UserCommonNVRamRestoreSystemData();
    RTDNVRamRestoreOSDData();

#if(_VGA_SUPPORT == _ON)
    UserCommonNVRamRestoreModeUserData();
#endif

    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
    {
        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        UserCommonNVRamSaveSystemData();
    }

    RTDDdcciColorReset();
}

//--------------------------------------------------
// Description  : Reset color to default
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDDdcciColorReset(void)
{
    g_ucDdcciRedBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;
    g_ucDdcciGreenBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;
    g_ucDdcciBlueBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;

    RTDNVRamRestoreUserColorSetting();
    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
    
    RTDNVRamRestoreBriCon();
    RTDNVRamRestoreBacklight();

    UserAdjustBacklight(GET_OSD_BACKLIGHT());
    UserAdjustContrast(GET_OSD_CONTRAST());
    UserAdjustBrightness(GET_OSD_BRIGHTNESS());
}

#endif//#if(_OSD_TYPE == _REALTEK_2011_OSD)
