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

#if(_OSD_TYPE == _LENOVO_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//#define _DDCCI_FIRMWARE_VERSION                     0x01

#define _DDCCI_BlACKLEVEL_DEFAULT                   0x50

// RC
#define _DDCCI_CMD_GetVCP_RC_NO_ERROR               0x00
#define _DDCCI_CMD_GetVCP_RC_UNSUPPORTED            0x01

// TP
#define _DDCCI_CMD_GetVCP_TP_SET_PARAMETER          0x00
#define _DDCCI_CMD_GetVCP_TP_MOMENTARY              0x01

#define _DDCCI_OPCODE_VCP_TPV_FACTORY				0xFE// 20111216 by jerry 
//--------------------------------------------------
// Definitions of Contrast Range (Real Value)
//--------------------------------------------------
//#define _DDCCI_COLORTEMP_USER_MAX                         128
//#define _DDCCI_COLORTEMP_USER_MIN                         28
//#define _DDCCI_COLORTEMP_USER_CENTER                      (((_COLORTEMP_USER_MAX - _COLORTEMP_USER_MIN) / 2) + _COLORTEMP_USER_MIN)


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
BYTE code tCOLORPRESET_VALUE[] = {0x06, 0x01, 0x05, 0x08, 0x0B};
//01h  sRGB  sRGB 
//02h  Display native  Display native 
//03h  4000 K  Warmer 
//04h  5000 K  
//05H  6500 K 
//06h  7500 K 
//07h  8200 K 
//08h  9300 K 
//09h  10000 K 
//0Ah  11500 K  Cooler 
//0Bh  User 1  User 1 
//0Ch  User 2  User 2 
//0Dh  User 3  User 3 
/*
#if((_DIGITAL1_TYPE == _HDMI_PORT) && (_DIGITAL2_TYPE == _DP_PORT))//Eli 20121127 H9CMT178GTG1HN-23 Modify DDCCI input source switch command bug.
BYTE code tINPUTSOURCEPORT[] = {0x01, 0x04, 0x11, 0x0F}; 
#elif((_DIGITAL1_TYPE == _DVI_PORT) && (_DIGITAL2_TYPE == _DP_PORT))
BYTE code tINPUTSOURCEPORT[] = {0x01, 0x04, 0x11, 0x03}; 
#elif((_DIGITAL1_TYPE == _DVI_PORT) && (_DIGITAL2_TYPE == _NONE_PORT)) 
BYTE code tINPUTSOURCEPORT[] = {0x01, 0x03};
#else
BYTE code tINPUTSOURCEPORT[] = {0x01, 0x03};
#endif
*/
#if (_A0_INPUT_PORT_TYPE == _A0_VGA_PORT)
#define _VGA 0x01,
#else
#define _VGA 
#endif

#if ((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT))
#define _DVI 0x03,
#else
#define _DVI 
#endif

#if (((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))&&((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)))
#define _HDMI 0x11,0x12,
#elif (((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))||((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)))
#define _HDMI 0x11,
#else
#define _HDMI 
#endif

#if ((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)||(_D1_INPUT_PORT_TYPE == _D1_DP_PORT))
#define _DP 0x0F,
#else
#define _DP 
#endif

BYTE code tINPUTSOURCEPORT[] = {_VGA _DVI _HDMI _DP };
//BYTE code tINPUTSOURCEPORT[] = {0x01, 0x0F, 0x03};
//02h Analog video (R/G/B) 2
//03h Digital video (TMDS) 1 DVI 1
//04h Digital video (TMDS) 2 DVI 2
//05h Composite video 1
//06h Composite video 2
//07h S-video 1
//08h S-video 2
//09h Tuner 1
//0Ah Tuner 2
//0Bh Tuner 3
//0Ch Component video (YPrPb / YCrCb) 1
//0Dh Component video (YPrPb / YCrCb) 2
//0Eh Component video (YPrPb / YCrCb) 3
//0Fh DisplayPort 1
//10h DisplayPort 2
//11h Digital Video (TMDS) 3 HDMI 1
//12h Digital Video (TMDS) 4 HDMI 2
//. 13h Reserved and are un-assigned

//_ENGLISH=0,_FRENCH,_ITALIAN,_CHINESE_S,_SPANISH,_JAPAN,_GERMAN,_RUSSIAN,
BYTE code tLANGUAGEDEFINE[] = {0x02, 0x03, 0x05, 0x0D, 0x0A, 0x06, 0x04, 0x09};
//00h  Reserved, must be ignored 
//01h  Chinese (traditional / Hantai) 
//02h English 
//03h  French 
//04h German 
//05h  Italian 
//06h Japanese 
//07h  Korean 
//08h Portuguese (Portugal) 
//09h  Russian 
//0Ah Spanish 
//0Bh  Swedish 
//0Ch Turkish 
//0Dh  Chinese (simplified / Kantai) 
//0Eh Portuguese (Brazil) 
//0Fh  Arabic 
//10h Bulgarian 
//11h  Croatian 
//12h Czech 
//13h  Danish 
//14h Dutch 
//15h  Estonian 
//16h Finnish 
//17h  Greek 
//18h Hebrew 
//19h  Hindi 
//1Ah Hungarian 
//1Bh  Latvian 
//1Ch Lithuanian 
//1Dh  Norwegian 
//1Eh Polish 
//1Fh  Romanian 
//20h Serbian 
//21h  Slovak 
//22h Slovenian 
//23h  Thai 
//24h Ukrainian 
//25h  Vietnamese 
//MCCS Standard    Version 3 c Copyright 2003 !V 2006 Video Electronics Standards Association  Page 60 of 130 



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
#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130806
BYTE ucDDCPowerSavingTemp  = 0;
#endif			
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserDdcciHandler(void);
void RTDDdcciGetVCPFeature(void);
bit RTDDdcciSetVCPFeatureCheck(void);
void RTDDdcciSetVCPFeature(void);
void RTDDdcciResetAllSettings(void);
//void RTDDdcciColorReset(void);

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
#if ((_FACTORY_MODE_OWNER == _OWNER_TPV))//DFM
			if(TPVFCmdFactoryCommand() == _FALSE)     //§PÂ_¬O§_¬°DFM DDCCI©R¥O
#elif(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
			if(FactoryCommand() == _FALSE)			
#endif			
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
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
		                if((g_ucDdcciRxBuf[_DDCCI_COMMAND] == _DDCCI_COMMAND_FOXCONN_FACTORY) || (g_ucDdcciRxBuf[_DDCCI_COMMAND] == _DDCCI_COMMAND_FOXCONN_HDCP))
		                {
		                    CDdcciFactoryCommand(g_ucDdcciRxBuf[_DDCCI_COMMAND]);
		                }
		                else
		                {
		                    UserCommonDdcciInitTx();
		                }
#else
		                UserCommonDdcciInitTx();
#endif // End of #if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
                        break;
                }
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
				case _CT_9300:
					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (93 - 30));
					break;
					
				case _CT_7200:
					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (75 - 30));
					break;
					
				case _CT_6500:
					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (65 - 30));
					break;
					
				case _CT_SRGB:
					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (40 - 30)); 				  
					break;
					
				default:
					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (65 - 30));
					break;
					
			}
            break;

#if(_VGA_SUPPORT == _ON)
        case _DDCCI_OPCODE_VCP_CLOCK:
			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_VGA_MODE_ADJUST_CLOCK());
            break;
#endif

        case _DDCCI_OPCODE_VCP_BACKLIGHT:
			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,GET_OSD_BACKLIGHT());
            break;

        case _DDCCI_OPCODE_VCP_CONTRAST:
			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,(WORD)UserCommonAdjustRealValueToPercent(GET_OSD_CONTRAST(),_CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER));
            break;

        case _DDCCI_OPCODE_VCP_SELECT_COLOR_PRESET:
            if(GET_COLOR_TEMP_TYPE() == _CT_USER)
            {
               UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x000B, 0x0B);
            }
            else
            {
               UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x000B, tCOLORPRESET_VALUE[GET_COLOR_TEMP_TYPE()]);
            }
            break;

        case _DDCCI_OPCODE_VCP_RED_GAIN:
            ucpTemp[0] = GET_COLOR_TEMP_TYPE();

            if(GET_COLOR_TEMP_TYPE() != _CT_USER)
            {
                SET_COLOR_TEMP_TYPE(_CT_USER);

                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }
			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,(WORD)UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_R(),_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));

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

			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,(WORD)UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_G(),_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));

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

			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,(WORD)UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_B(),_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));

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
#if 0//Robert Wang 20130520 mark 
                UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_DIGITAL_H_POSITION());
#endif
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
#if 0//Robert Wang 20130520 mark 
                UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_DIGITAL_V_POSITION());
#endif
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
			switch(OsdDispJudgeSourceType())
			{
				case _OSD_SOURCE_PORT_VGA:
					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x11, 0x01);
					break;
				
				case _OSD_SOURCE_PORT_DVI:
					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x11, 0x03);
					break;
					
				case _OSD_SOURCE_PORT_HDMI:
					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x11, 0x11);
					break;
					
				case _OSD_SOURCE_PORT_DP:
					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x11, 0x0F);
					break;
			}
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
            UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (WORD)(pData[0] << 8) + pData[1], (WORD)(pData[2] << 8) + pData[3]);
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
            if(GET_OSD_LOCK_STATUS() == _OFF)
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
		#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130806
            if(SysModeGetModeState() == _MODE_STATUS_POWER_OFF)
            {
                pData[0] = 5;
            }
            else if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
                pData[0]= 1;
            }
			else if(ucDDCPowerSavingTemp > 0)
			{
			    pData[0] = ucDDCPowerSavingTemp;
			}
            else if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
            {
                pData[0]= 4;
            }
		#else
			
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
		#endif
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
           
	   if(g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE] != _DDCCI_OPCODE_VCP_NEW_CONTROL_VALUE )
	   {
		   if(ScalerOsdGetOsdEnable() == _TRUE)
		   { 
			   OsdDisplayDisableOsd();	   
		   }
	   }
	
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
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20141013

                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x01)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysSourceSwitchInputPort(_A0_INPUT_PORT);
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x11)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysSourceSwitchInputPort(_D0_INPUT_PORT);
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x0F)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysSourceSwitchInputPort(_D1_INPUT_PORT);
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                }
				
#else 
                switch(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE])

				{
#if (_A0_INPUT_PORT_TYPE == _A0_VGA_PORT)                
                    case 0x01: // VGA
                        SET_FORCE_POW_SAV_STATUS(_FALSE);
                        SysSourceSwitchInputPort(_A0_INPUT_PORT);
                        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);                    
                    break;
#endif

#if ((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT))
                    case 0x03: // DVI
                        SET_FORCE_POW_SAV_STATUS(_FALSE);
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
                        SysSourceSwitchInputPort(_D0_INPUT_PORT);
#else
                        SysSourceSwitchInputPort(_D1_INPUT_PORT);
#endif
                        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                    break;                    
#endif

#if (((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))&&((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)))
                    case 0x11: // HDMI1                    
                        SET_FORCE_POW_SAV_STATUS(_FALSE);
                        SysSourceSwitchInputPort(_D0_INPUT_PORT);
                        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                    break;           
                    
                    case 0x12: // HDMI2                    
                        SET_FORCE_POW_SAV_STATUS(_FALSE);
                        SysSourceSwitchInputPort(_D1_INPUT_PORT);
                        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                    break;                    

#elif (((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))||((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)))
                    case 0x11: // HDMI1
                        SET_FORCE_POW_SAV_STATUS(_FALSE);
#if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)   
                        SysSourceSwitchInputPort(_D0_INPUT_PORT);
#else
                        SysSourceSwitchInputPort(_D1_INPUT_PORT);
#endif
                        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                    break;           
#endif

#if ((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)||(_D1_INPUT_PORT_TYPE == _D1_DP_PORT))
                    case 0x0F: // DP1
                        SET_FORCE_POW_SAV_STATUS(_FALSE);
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)                                                
                        SysSourceSwitchInputPort(_D0_INPUT_PORT);
#else
                        SysSourceSwitchInputPort(_D1_INPUT_PORT);
#endif
                        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                    break;           
#endif

                }
/*
#if((_DIGITAL1_TYPE == _HDMI_PORT) && (_DIGITAL2_TYPE == _DP_PORT))
				 if((tINPUTSOURCEPORT[OsdDispJudgeSourceType()]) != (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]))
				 {
					switch(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE])
					{
						case 0x01:
							SET_FORCE_POW_SAV_STATUS(_FALSE);
							SysSourceSwitchInputPort(_A0_INPUT_PORT);
							SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
						break;
						
						case 0x11:
							SET_FORCE_POW_SAV_STATUS(_FALSE);
							SysSourceSwitchInputPort(_D0_INPUT_PORT);
							SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
						break;
						
						case 0x0f:
							SET_FORCE_POW_SAV_STATUS(_FALSE);
							SysSourceSwitchInputPort(_D1_INPUT_PORT);
							SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
						break; 
						
						default:
						break;
					}
				}
#elif((_DIGITAL1_TYPE == _DVI_PORT) && (_DIGITAL2_TYPE == _DP_PORT))
				 if((tINPUTSOURCEPORT[OsdDispJudgeSourceType()]) != (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]))
				 {
					switch(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE])
					{
						case 0x01:
							SET_FORCE_POW_SAV_STATUS(_FALSE);
							SysSourceSwitchInputPort(_A0_INPUT_PORT);
							SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
						break;
						
						case 0x11:
							SET_FORCE_POW_SAV_STATUS(_FALSE);
							SysSourceSwitchInputPort(_D0_INPUT_PORT);
							SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
						break;
						
						case 0x03:
							SET_FORCE_POW_SAV_STATUS(_FALSE);
							SysSourceSwitchInputPort(_D1_INPUT_PORT);
							SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
						break; 
						
						default:
						break;
					}
				}
#else
                if((tINPUTSOURCEPORT[OsdDispJudgeSourceType()]) != (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]))
                {
                   switch(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE])
                   {
                       case 0x01:
                           SET_FORCE_POW_SAV_STATUS(_FALSE);
					       SysSourceSwitchInputPort(_A0_INPUT_PORT);
					       SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
					   break;
                       case 0x03:
                           SET_FORCE_POW_SAV_STATUS(_FALSE);
					       SysSourceSwitchInputPort(_D1_INPUT_PORT);
					       SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
					   break;
                       default:
                       break;
                   }
               }
#endif
*/
#endif				
                break;

            case _DDCCI_OPCODE_VCP_FACTORY_RESET:
				RTDDdcciResetAllSettings();
                break;

            case _DDCCI_OPCODE_VCP_RECAL_BRI_CON:
#if(_USER_DCR_FUNCTION == _ON)
				if(GET_OSD_DCR_STATUS() == _OFF)
#endif
				{
	                RTDNVRamRestoreBriCon();
	                RTDNVRamRestoreBacklight();
				#if(_ENERGY_STAR_SUPPORT == _ON)
			        if(GET_OSD_ES_STATUS() == _ON) 
			        {
						UserAdjustESBacklight();
					}
			        else
				#endif
			        {
						UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
			        }
					UserAdjustContrast(GET_OSD_CONTRAST());
				}
                break;

            case _DDCCI_OPCODE_VCP_GEOMETRY_RESET:

#if(_VGA_SUPPORT == _ON)
				if((SysSourceGetSourceType() == _SOURCE_VGA)&&((SysModeGetModeState()==_MODE_STATUS_ACTIVE)))
				{
					SET_VGA_MODE_ADJUST_H_POSITION(50);
					SET_VGA_MODE_ADJUST_V_POSITION(50);
					SET_VGA_MODE_ADJUST_CLOCK(50);
					UserCommonAutoConfig();
					UserCommonNVRamSaveModeUserData();
				}
#endif
                break;

            case _DDCCI_OPCODE_VCP_COLOR_RESET:
#if(_USER_DCR_FUNCTION == _ON)
				if(GET_OSD_DCR_STATUS() == _OFF)
#endif
				{
					g_ucDdcciRedBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;
					g_ucDdcciGreenBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;
					g_ucDdcciBlueBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;
					RTDNVRamRestoreUserColorSetting();
					RTDNVRamRestoreBriCon();
	                RTDNVRamRestoreBacklight();                                                                   															
	                SET_COLOR_TEMP_TYPE(_COLOR_TEMP_DEF);
					#if((_FACTORY_MODE_OWNER == _OWNER_TPV) || (_FACTORY_MODE_OWNER == _OWNER_FOXCONN))
					SET_PRESET_COLOR_TEMP_BACKUP(_COLOR_TEMP_DEF);
					#endif				
					RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
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
					UserAdjustContrast(GET_OSD_CONTRAST());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
				}
                break;

            case _DDCCI_OPCODE_VCP_COLOR_TEMP_REQUEST:

                g_ucColorTempUnSupport = (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] + 30);
                if(g_ucColorTempUnSupport >= 93)
                {
                    SET_COLOR_TEMP_TYPE(_CT_9300);
                }
                else if((g_ucColorTempUnSupport < 85) && (g_ucColorTempUnSupport >= 75))
                {
                    SET_COLOR_TEMP_TYPE(_CT_7200);
                }
                else if((g_ucColorTempUnSupport < 75) && (g_ucColorTempUnSupport >= 65))
                {
                    SET_COLOR_TEMP_TYPE(_CT_6500);
                }
				else
                {
                    SET_COLOR_TEMP_TYPE(_CT_SRGB);
                }
				#if((_FACTORY_MODE_OWNER == _OWNER_TPV) || (_FACTORY_MODE_OWNER == _OWNER_FOXCONN))
				if((GET_COLOR_TEMP_TYPE() >=_CT_7200)&&(GET_COLOR_TEMP_TYPE() <=_CT_9300))
				{
					SET_PRESET_COLOR_TEMP_BACKUP(GET_COLOR_TEMP_TYPE());
				}
				#endif
                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

	            if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
	            {
	                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
#if(_ENERGY_STAR_SUPPORT == _ON)
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
#if(_ENERGY_STAR_SUPPORT == _ON)
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
				
                OsdDisplayDisableOsd();

                break;

            case _DDCCI_OPCODE_VCP_CLOCK:

#if(_VGA_SUPPORT == _ON)
				if(SysSourceGetSourceType() == _SOURCE_VGA)
				{
					if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
					{
						g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
					}
					SET_VGA_MODE_ADJUST_CLOCK(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
					UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
				}
#endif
                break;

            case _DDCCI_OPCODE_VCP_BACKLIGHT:
#if(_USER_DCR_FUNCTION == _ON)
                if(GET_OSD_DCR_STATUS() == _OFF)
#endif
                {
                    if(_CT_SRGB != GET_COLOR_TEMP_TYPE())
                    {
				#if(_ENERGY_STAR_SUPPORT == _ON)
	                    if(GET_OSD_ES_STATUS() == _ON) 
	                    {
			                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
			                {
			                    g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
			                }
			                SET_OSD_BACKLIGHT((g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]));
			                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
	                        UserAdjustESBacklight();
	                    }
	                    else
				#endif
		                {
							if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
							{
								g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
							}
							SET_OSD_BACKLIGHT((g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]));
							UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
							SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
		                }
                    }
                }
                break;


            case _DDCCI_OPCODE_VCP_CONTRAST:
#if(_USER_DCR_FUNCTION == _ON)
                if(GET_OSD_DCR_STATUS() == _OFF)
#endif
                {
                    if(_CT_SRGB != GET_COLOR_TEMP_TYPE())
                    {
						if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
						{
							g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
						}														
						SET_OSD_CONTRAST(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE], _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER));
						UserAdjustContrast(GET_OSD_CONTRAST());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
                    }
                }
                break;

            case _DDCCI_OPCODE_VCP_SELECT_COLOR_PRESET:
#if(_USER_DCR_FUNCTION == _ON)
                if(GET_OSD_DCR_STATUS() == _OFF)
#endif
                {
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

	                    case 0x06:
	                        SET_COLOR_TEMP_TYPE(_CT_7200);
	                        break;

	                    default:
	                        break;
	                }
					#if((_FACTORY_MODE_OWNER == _OWNER_TPV) || (_FACTORY_MODE_OWNER == _OWNER_FOXCONN))
					if((GET_COLOR_TEMP_TYPE() >=_CT_7200)&&(GET_COLOR_TEMP_TYPE() <=_CT_9300))
					{
						SET_PRESET_COLOR_TEMP_BACKUP(GET_COLOR_TEMP_TYPE());
					}
					#endif
	                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

		            if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
		            {
		                UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
#if(_ENERGY_STAR_SUPPORT == _ON)
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
#if(_ENERGY_STAR_SUPPORT == _ON)
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

	                OsdDisplayDisableOsd();
	                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);        
                }
                break;

            case _DDCCI_OPCODE_VCP_RED_GAIN:                
                // Only write at customer color
#if(_USER_DCR_FUNCTION == _ON)
                if(GET_OSD_DCR_STATUS() == _OFF)
#endif
                {				
                    if(GET_COLOR_TEMP_TYPE() != _CT_USER)
                    {
                        RTDNVRamLoadColorSetting(_CT_USER);                        
                        SET_COLOR_TEMP_TYPE(_CT_USER);
                    }	
					SET_COLOR_TEMP_TYPE_USER_R(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));
                    UserAdjustContrast(GET_OSD_CONTRAST());
                    
    			#if(_ENERGY_STAR_SUPPORT == _ON)
    	            if(GET_OSD_DCR_STATUS() == _ON) 
    	            {
    					UserCommonAdjustESDcrAdjust();    
    				}
    	            else
    			#endif
    	            {
    	        		UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
    	            }
                    RTDNVRamSaveColorSetting(_CT_USER);
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
                }
                break;

            case _DDCCI_OPCODE_VCP_GREEN_GAIN:
#if(_USER_DCR_FUNCTION == _ON)
                if(GET_OSD_DCR_STATUS() == _OFF)
#endif
                {
                // Only write at customer color
                if(GET_COLOR_TEMP_TYPE() != _CT_USER)
                {
                    RTDNVRamLoadColorSetting(_CT_USER);                     
                    SET_COLOR_TEMP_TYPE(_CT_USER);
                }
				SET_COLOR_TEMP_TYPE_USER_G(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));
                UserAdjustContrast(GET_OSD_CONTRAST());
			#if(_ENERGY_STAR_SUPPORT == _ON)
	            if(GET_OSD_DCR_STATUS() == _ON) 
	            {
					UserCommonAdjustESDcrAdjust();
				}
	            else
			#endif
	            {
	        		UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
	            }
                RTDNVRamSaveColorSetting(_CT_USER);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
                }
                break;

            case _DDCCI_OPCODE_VCP_BLUE_GAIN:
#if(_USER_DCR_FUNCTION == _ON)
                if(GET_OSD_DCR_STATUS() == _OFF)
#endif
                {
                // Only write at customer color
                if(GET_COLOR_TEMP_TYPE() != _CT_USER)
                {
                    RTDNVRamLoadColorSetting(_CT_USER);                     
                    SET_COLOR_TEMP_TYPE(_CT_USER);
                }
				SET_COLOR_TEMP_TYPE_USER_B(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));
                UserAdjustContrast(GET_OSD_CONTRAST());
			#if(_ENERGY_STAR_SUPPORT == _ON)
	            if(GET_OSD_DCR_STATUS() == _ON) 
	            {
					UserCommonAdjustESDcrAdjust();
				}
	            else
			#endif
	            {
	        		UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
	            }
                RTDNVRamSaveColorSetting(_CT_USER);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
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
#if 0//Robert Wang 20130520 mark 
                    SET_DIGITAL_H_POSITION(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
                    UserCommonAdjustHPosition(GET_DIGITAL_H_POSITION());
#endif
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
#if 0//Robert Wang 20130520 mark 
                    SET_DIGITAL_V_POSITION(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
                    UserCommonAdjustVPosition(GET_DIGITAL_V_POSITION());
#endif
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

#if((_AUDIO_SUPPORT == _ON)&&(_AUDIO_ADJUST_FUNCTION_SUPPORT == _ON))
            case _DDCCI_OPCODE_VCP_AUDIO_VOLUME:
				
				if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)
				{
					g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;
				}														
				SET_OSD_VOLUME(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);														
				UserAdjustAudioVolume(GET_OSD_VOLUME());
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
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
#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130806
                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 5)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
                    ucDDCPowerSavingTemp = 5;
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 4)
                {
                    SET_FORCE_POW_SAV_STATUS(_TRUE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
					UserInterfaceKeyPadLedControl(_LED_POWER_OFF);
                    ucDDCPowerSavingTemp = 4;
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 3)
                {
                    SET_FORCE_POW_SAV_STATUS(_TRUE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
					UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);
                    ucDDCPowerSavingTemp = 3;
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 2)
                {
                    SET_FORCE_POW_SAV_STATUS(_TRUE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
					UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);
                    ucDDCPowerSavingTemp = 2;
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 1)
                {
                    if((SysPowerGetPowerStatus() != _POWER_STATUS_NORMAL)&&(ucDDCPowerSavingTemp != 5))
                    {
	                    SET_FORCE_POW_SAV_STATUS(_FALSE);
	                    SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
	                    ucDDCPowerSavingTemp = 0;
	                }
                }
#elif(_FACTORY_MODE_OWNER == _OWNER_TPV)

                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 5)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
#if(_AUDIO_SUPPORT == _ON)	
					//Mute ON
					PCB_AMP_MUTE(_AMP_MUTE_ON);
					//AMP OFF
					PCB_AMP_POWER(_AMP_POWER_OFF);
#endif
					PCB_USB_POWER(_USB_POWER_OFF);
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
					Xpos=100;
					Ypos=100;
					Xdirect = 1;
					Ydirect = 1;
					ucLedFlashCount = 0;
#if(_AUDIO_SUPPORT == _ON)
					//Mute ON
					PCB_AMP_MUTE(_AMP_MUTE_ON); 			   
					//AMP ON
					PCB_AMP_POWER(_AMP_POWER_ON);
#endif
					PCB_USB_POWER(_USB_POWER_ON);
				}
			
				TPVDFMForce2PowerOff(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
			
#elif (_FACTORY_MODE_OWNER == _OWNER_WISTRON)            
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
                }


#else
                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 4)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 2)
                {
                    SET_FORCE_POW_SAV_STATUS(_TRUE);
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                }
                else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 1)
                {
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
                }

				TPVDFMForce2PowerOff(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);
#endif

                break;

            case _DDCCI_OPCODE_VCP_OSD_LANGUAGE:

				switch(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE])
				{												 
					case 0x02:
						SET_OSD_LANGUAGE(_ENGLISH);
						break;
					case 0x03:
						SET_OSD_LANGUAGE(_FRENCH);
						break;
					case 0x04:
						SET_OSD_LANGUAGE(_GERMAN);
						break;
					case 0x05:
						SET_OSD_LANGUAGE(_ITALIAN);
						break;
					case 0x06:
						SET_OSD_LANGUAGE(_JAPAN);
						break;
					case 0x09:
						SET_OSD_LANGUAGE(_RUSSIAN);
						break;
					case 0x0A:
						SET_OSD_LANGUAGE(_SPANISH);
						break;												 
					case 0x0D:
						SET_OSD_LANGUAGE(_CHINESE_S);
						break; 												 
					default:
						break;
				}
				OsdFuncDisableOsd();
				SET_OSD_STATE(_MENU_NONE);
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);

                break;

            case _DDCCI_OPCODE_VCP_OSD_ON_OFF:

				  OsdFuncDisableOsd();
				  OsdFuncCloseWindow(_WIN_ALL);
				  SET_OSD_STATE(_MENU_NONE);
				  CLR_Key_Relax_FLAG();
				  if((g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 1) && (GET_OSD_LOCK_STATUS() != _ON))
				  {
					   SET_OSD_LOCK_STATUS(_ON);
					   SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);  
				  }
				  else if((g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 2) && (GET_OSD_LOCK_STATUS() != _OFF))
				  {
						SET_OSD_LOCK_STATUS(_OFF);
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
				  }

                break;

#if((_OCC_SUPPORT == _ON) || (_OGC_SUPPORT == _ON))
            case _DDCCI_OPCODE_OCC_FUNCTION:

                // Pablo
//                UserDdcciOGCProcess();

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
   OsdReset();
}
/*
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
	SET_COLOR_TEMP_TYPE(_COLOR_TEMP_DEF);
    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
	SET_NOVO_VISION_STATUS(_NOVO_VISION_TEXT);

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)    
    SET_OSD_HLWIN_TYPE(_HL_WIN_OFF);
    ScalerColorHLW(_OFF);
#endif
    
    RTDNVRamRestoreBriCon();
    RTDNVRamRestoreBacklight();

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
    UserAdjustBrightness(GET_OSD_BRIGHTNESS());
}
*/
#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
