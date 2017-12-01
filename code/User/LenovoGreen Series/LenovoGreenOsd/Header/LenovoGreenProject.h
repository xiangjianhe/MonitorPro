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
// ID Code      : UserProject.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if((_PROJECT == _RL6229_PROJECT) && (_3D_SUPPORT == _ON))
#define _OSD_3D_FUNCTION                            _ON

#else
#define _OSD_3D_FUNCTION                            _OFF

#endif

#if((_PROJECT != _RL6229_PROJECT) && (_OSD_3D_FUNCTION == _ON))
#warning "OSD 3D FUNCTION SUPPORT ON!!"
#endif

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
//DFM rev07 patch note 3 >>
#if((_SCALER_TYPE == _RL6336_SERIES)&&((_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE)||(_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE)||(_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE)))
#define _SUPPORT_PC99                               _ON
#endif

#if((_DP_SUPPORT == _ON) || (_MHL_SUPPORT == _ON))

#if(_SYSTEM_EEPROM_EMULATION_END_PAGE > 13)
    #warning "Please Check _SYSTEM_EEPROM_EMULATION_END_PAGE !!"
#endif

#else

#ifdef _SUPPORT_PC99 
#if(_SYSTEM_EEPROM_EMULATION_END_PAGE > 13)
    #warning "Please Check _SYSTEM_EEPROM_EMULATION_END_PAGE !!"
#endif
#endif

#endif

//DFM rev07 patch note 3 <<
#endif

#if(_PROJECT == _RTD2281CW_WISTRON_PROJECT)&&(_ENERGY_STAR_SUPPORT == _ON)
#define _LENOVO_DPS_SUPPORT                         _ON
#else
#define _LENOVO_DPS_SUPPORT                         _OFF
#endif

#if((_USER_DCR_FUNCTION == _ON)&&(_LENOVO_DPS_SUPPORT ==_ON))
#warning "DCR and DPS function can't both turn on!!"
#endif
//-------------------------------------------------
//
//-------------------------------------------------
#ifndef _LOW_BLUE_LIGHT_FUNCTION
#define _LOW_BLUE_LIGHT_FUNCTION                     _OFF
#endif

#ifndef _LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP
#define _LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP         _OFF
#endif

#ifndef _DFM_DC_RESET_7200_FUNCTION
#define _DFM_DC_RESET_7200_FUNCTION                  _ON
#endif

#define _LEONVO_GREEN_OSD_STYLE_0                   0           
#define _LEONVO_GREEN_OSD_STYLE_1                   1

#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
#define _USER_COLOR_MAX                             100
#define _USER_COLOR_MIN                             0
#define _LEONVO_GREEN_OSD_STYLE                     _LEONVO_GREEN_OSD_STYLE_0
#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
#define _USER_COLOR_MAX                             128
#define _USER_COLOR_MIN                             28
#define _LEONVO_GREEN_OSD_STYLE                     _LEONVO_GREEN_OSD_STYLE_0
#else
#define _USER_COLOR_MAX                             128
#define _USER_COLOR_MIN                             28
#define _LEONVO_GREEN_OSD_STYLE                     _LEONVO_GREEN_OSD_STYLE_1
#endif

//--------------------------------------------------
// Definitions of DDCCI function Macro
//--------------------------------------------------

#define DDCCI_GET_OSD_BACKLIGHT()					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,GET_OSD_BACKLIGHT())
#define DDCCI_GET_OSD_CONTRAST()					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,(WORD)UserCommonAdjustRealValueToPercent(GET_OSD_CONTRAST(),_CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER))
#define DDCCI_GET_COLOR_TEMP_TYPE_USER_R()			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,(WORD)UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_R(),_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER))
#define DDCCI_GET_COLOR_TEMP_TYPE_USER_G()			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,(WORD)UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_G(),_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER))
#define DDCCI_GET_COLOR_TEMP_TYPE_USER_B()			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100,(WORD)UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_B(),_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER))
#define DDCCI_GET_INPUTPORT()                       UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, sizeof(tINPUTSOURCEPORT), tINPUTSOURCEPORT[OsdDispJudgeSourceType()])
#define DDCCI_GET_OSD_VOLUME()						UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_OSD_VOLUME())
#define DDCCI_GET_OSD_SHARPNESS()					UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 0x0004, GET_OSD_SHARPNESS())
#if (_VGA_SUPPORT == _ON)
#define DDCCI_GET_VGA_MODE_ADJUST_H_POSITION()		UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_VGA_MODE_ADJUST_H_POSITION())
#define DDCCI_GET_VGA_MODE_ADJUST_V_POSITION()		UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_VGA_MODE_ADJUST_V_POSITION())
#define DDCCI_GET_VGA_MODE_ADJUST_PHASE()			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_VGA_MODE_ADJUST_PHASE())
#define DDCCI_GET_VGA_MODE_ADJUST_CLOCK()			UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, 100, GET_VGA_MODE_ADJUST_CLOCK())
#endif
#define DDCCI_GET_COLOR_TEMP_REQUEST()				{\
											            switch(GET_COLOR_TEMP_TYPE())\
											            {\
											                case _CT_9300:\
											                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (93 - 30));\
											                    break;\
											                case _CT_7200:\
											                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (75 - 30));\
											                    break;\
											                case _CT_6500:\
											                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (65 - 30));\
											                    break;\
                                                            case _CT_SRGB:\
                                                                UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (40 - 30));\                   
                                                                break;\
											                default:\
											                    UserCommonDdcciSetVCPReplyValue(_DDCCI_CMD_GetVCP_TP_SET_PARAMETER, (93 - 30), (g_ucColorTempUnSupport - 30));\
											                    break;\
											            }\
													}
//--------------------------------------------------
#define DDCCI_SET_OSD_BACKLIGHT()					{\	
										                if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)\
										                {\
										                    g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;\
										                }\
										                SET_OSD_BACKLIGHT((g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]));\
										                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());\
										                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\
													}
#define DDCCI_SET_OSD_CONTRAST()					{\
														if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)\
														{\
															g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;\
														}\														
														SET_OSD_CONTRAST(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE], _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER));\
														UserAdjustContrast(GET_OSD_CONTRAST());\
														SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);\
													}
#define DDCCI_SET_OSD_COLOR_TEMP()					{\
														if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x0B)\
														{\
														    SET_COLOR_TEMP_STATUS(_COLOR_USER);\
														}\
														else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x05)\
														{\
														    SET_COLOR_TEMP_STATUS(_COLOR_PRESET);\
															SET_COLOR_TEMP_TYPE(_CT_6500);\
														}\
														else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x08)\
														{\
														    SET_COLOR_TEMP_STATUS(_COLOR_PRESET);\
															SET_COLOR_TEMP_TYPE(_CT_9300);\
														}\
														else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x01)\
														{\
														    SET_COLOR_TEMP_STATUS(_COLOR_PRESET);\
															SET_COLOR_TEMP_TYPE(_CT_SRGB);\
														}\
														else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 0x06)\
														{\
														    SET_COLOR_TEMP_STATUS(_COLOR_PRESET);\
															SET_COLOR_TEMP_TYPE(_CT_7200);\
														}\	
														if(_COLOR_USER == GET_COLOR_TEMP_STATUS())\
                                                        {\
                                                            RTDNVRamLoadColorSetting(_CT_USER);\
                                                        }\
                                                        else\
                                                        {\
														    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());\
                                                        }\
                                                        if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))\
                                                        {\
                                                            UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);\
                                                            UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);\
                                                        }\
                                                        else\
                                                        {\
                                                            UserAdjustContrast(GET_OSD_CONTRAST());\
                                                            UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());\
                                                        }\
                                                        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\
													}
#define DDCCI_SET_COLOR_TEMP_TYPE_USER_R()			{\
														SET_COLOR_TEMP_TYPE_USER_R(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));\
													}
#define DDCCI_SET_COLOR_TEMP_TYPE_USER_G()			{\
														SET_COLOR_TEMP_TYPE_USER_G(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));\
													}
#define DDCCI_SET_COLOR_TEMP_TYPE_USER_B()			{\
														SET_COLOR_TEMP_TYPE_USER_B(UserCommonAdjustPercentToRealValue(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE],_COLORTEMP_USER_MAX, _COLORTEMP_USER_MIN, _COLORTEMP_USER_CENTER));\
													}
#define DDCCI_SET_OSD_SHARPNESS()					{\
														if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 4)\
														{\
															g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 4;\
														}\
														SET_OSD_SHARPNESS(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);\
														UserAdjustSharpness(GET_OSD_SHARPNESS());\
														SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\
													}	
#define DDCCI_SET_INPUTPORT()						{\	
                                                        if((tINPUTSOURCEPORT[OsdDispJudgeSourceType()])!=(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]))\
                                                        {\
                                                           switch(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE])\
                                                           {\
                                                               case 0x01:\
                                                                   SET_FORCE_POW_SAV_STATUS(_FALSE);\
                                                                   SET_SHOW_SOURCE_INFO(_ON);\
															       SysSourceSwitchInputPort(_A0_INPUT_PORT);\
															       SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);\
															   break;\
                                                               case 0x03:\
                                                                   SET_FORCE_POW_SAV_STATUS(_FALSE);\
                                                                   SET_SHOW_SOURCE_INFO(_ON);\
															       SysSourceSwitchInputPort(_D1_INPUT_PORT);\
															       SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);\
															   break;\
															   /*case 0x0F:*/\
                                                               /*    SET_FORCE_POW_SAV_STATUS(_FALSE);*/\
															   /*    SysSourceSwitchInputPort(_D0_INPUT_PORT);*/\
															   /*    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);*/\
                                                               /*break;*/\
                                                               default:\
                                                               break;\
                                                           }\
                                                       }\
													}
#define DDCCI_SET_FACTORY_RESET()					{\
                                                        RTDDdcciResetAllSettings();\
													}
#define DDCCI_SET_RECAL_BRI_CON()					{\
                                                        RTDNVRamRestoreBriCon();\
															if(_COLOR_USER == GET_COLOR_TEMP_STATUS())\
															{\
																RTDNVRamLoadColorSetting(_CT_USER);\
															}\
															else\
															{\
																RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());\
															}\
                                                        RTDNVRamRestoreBacklight();\                                                                    													
														UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());\
														UserAdjustContrast(GET_OSD_CONTRAST());\
														/*UserAdjustBrightness(GET_OSD_BRIGHTNESS());*/\
													}

#if 1//(_FACTORY_MODE_OWNER == _OWNER_WISTRON)//orimiao 20140702 for Display Tune Toolbox test fail   
#define DDCCI_SET_GEOMETRY_RESET()					{\
													    if((SysSourceGetSourceType() == _SOURCE_VGA)&&((SysModeGetModeState()==_MODE_STATUS_ACTIVE)))\
													    {\
													    	SET_VGA_MODE_ADJUST_H_POSITION(50);\
															SET_VGA_MODE_ADJUST_V_POSITION(50);\
															SET_VGA_MODE_ADJUST_CLOCK(50);\
                                                            UserCommonAutoConfig();\
													        UserCommonNVRamSaveModeUserData();\
													    }\
													}
#else
#define DDCCI_SET_GEOMETRY_RESET()					{\
													    if((SysSourceGetSourceType() == _SOURCE_VGA)&&((SysModeGetModeState()==_MODE_STATUS_ACTIVE)))\
													    {\
													    	SET_VGA_MODE_ADJUST_H_POSITION(50);\
															SET_VGA_MODE_ADJUST_V_POSITION(50);\
															SET_VGA_MODE_ADJUST_CLOCK(50);\
															SET_VGA_MODE_ADJUST_PHASE(GET_VGA_MODE_ADJUST_PHASE());\
															UserCommonAdjustHPosition(GET_VGA_MODE_ADJUST_H_POSITION());\
															UserCommonAdjustVPosition(GET_VGA_MODE_ADJUST_V_POSITION());\
															UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());\
															UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());\														
													        UserCommonNVRamSaveModeUserData();\
													    }\
													}
#endif

#define DDCCI_SET_COLOR_RESET()						{\
														g_ucDdcciRedBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;\
														g_ucDdcciGreenBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;\
														g_ucDdcciBlueBlackLevel = _DDCCI_BlACKLEVEL_DEFAULT;\
														RTDNVRamRestoreUserColorSetting();\
														SET_COLOR_TEMP_STATUS(_COLOR_PRESET);\
                                                        SET_COLOR_TEMP_TYPE(_COLOR_TEMP_DEF);\
														RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());\
														UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());\
														UserAdjustContrast(GET_OSD_CONTRAST());\
														SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\
														/*UserAdjustBrightness(GET_OSD_BRIGHTNESS());*/\
													}

#define DDCCI_SET_OSD_VOLUME()						{\
														if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)\
														{\
															g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;\
														}\														
														SET_OSD_VOLUME(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);\														
														UserAdjustVolume(GET_OSD_VOLUME());\
														SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\
													}
#if (_VGA_SUPPORT == _ON)
#define DDCCI_SET_VGA_MODE_ADJUST_H_POSITION()		{\
														SET_VGA_MODE_ADJUST_H_POSITION(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);\
														UserCommonAdjustHPosition(GET_VGA_MODE_ADJUST_H_POSITION());\
														SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);\
													}
#define DDCCI_SET_VGA_MODE_ADJUST_V_POSITION()		{\
														if(abs(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] - GET_VGA_MODE_ADJUST_V_POSITION()) > 50)\
														{\
															SET_VGA_MODE_ADJUST_V_POSITION(50);\
														}\
														SET_VGA_MODE_ADJUST_V_POSITION(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);\
														UserCommonAdjustVPosition(GET_VGA_MODE_ADJUST_V_POSITION());\
														SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);\
													}
#define DDCCI_SET_VGA_MODE_ADJUST_PHASE()			{\
														if(SysSourceGetSourceType() == _SOURCE_VGA)\
														{\
															if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)\
															{\
																g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;\
															}\											
															SET_VGA_MODE_ADJUST_PHASE(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);\																												
															UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());\
															SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);\
														}\
													}
#define DDCCI_SET_VGA_MODE_ADJUST_CLOCK()			{\
														if(SysSourceGetSourceType() == _SOURCE_VGA)\
														{\
															if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] > 100)\
															{\
																g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] = 100;\
															}\
															SET_VGA_MODE_ADJUST_CLOCK(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE]);\
															UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());\
															SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);\
														}\
													}
#endif
#define DDCCI_SET_OSD_LANGUAGE()			{\
												switch(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE])\
												{\													 
													case 0x02:\
														SET_OSD_LANGUAGE(_ENGLISH);\
														break;\
													case 0x03:\
														SET_OSD_LANGUAGE(_FRENCH);\
														break;\
													case 0x04:\
														SET_OSD_LANGUAGE(_GERMAN);\
														break;\
													case 0x05:\
														SET_OSD_LANGUAGE(_ITALIAN);\
														break;\	
													case 0x06:\
														SET_OSD_LANGUAGE(_JAPAN);\
														break;\	
													case 0x09:\
														SET_OSD_LANGUAGE(_RUSSIAN);\
														break;\
													case 0x0A:\
														SET_OSD_LANGUAGE(_SPANISH);\
														break;\													 
													case 0x0D:\
														SET_OSD_LANGUAGE(_CHINESE_S);\
														break;\													 
													default:\
														break;\
												}\
												OsdFuncDisableOsd();\
												SET_OSD_STATE(_MENU_NONE);\
												SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\
											}
#define DDCCI_SET_OSD_ON_OFF()				{\
                                                OsdDispDisableOsdTimerEvent();\
												if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 1)\
												{\
				                                     SET_OSD_LOCK_STATUS(_ON);\
				                                     SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\	
												}\
												else if(g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] == 2)\
												{\
				                                      SET_OSD_LOCK_STATUS(_OFF);\
				                                      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\	
												}\
											}										
#define DDCCI_SET_COLOR_TEMP_REQUEST()		{\	
												g_ucColorTempUnSupport = (g_ucDdcciRxBuf[_DDCCI_SET_LOW_BYTE] + 30);\
												if(g_ucColorTempUnSupport >= 93)\
												{\
                                                    SET_COLOR_TEMP_STATUS(_COLOR_PRESET);\
													SET_COLOR_TEMP_TYPE(_CT_9300);\
												}\
												else if((g_ucColorTempUnSupport < 85) && (g_ucColorTempUnSupport >= 75))\
												{\
                                                    SET_COLOR_TEMP_STATUS(_COLOR_PRESET);\
													SET_COLOR_TEMP_TYPE(_CT_7200);\
												}\
												else if((g_ucColorTempUnSupport < 75) && (g_ucColorTempUnSupport >= 65))\
												{\
                                                    SET_COLOR_TEMP_STATUS(_COLOR_PRESET);\
													SET_COLOR_TEMP_TYPE(_CT_6500);\
												}\
                                                else if((g_ucColorTempUnSupport < 54) && (g_ucColorTempUnSupport >= 40))\
                                                {\
                                                    SET_COLOR_TEMP_STATUS(_COLOR_PRESET);\
                                                    SET_COLOR_TEMP_TYPE(_CT_SRGB);\
                                                }\
                                                else\
                                                {\
                                                    SET_COLOR_TEMP_TYPE(_CT_USER);\
                                                }\
												RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());\
                                                if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))\
                                                {\
                                                    UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);\
                                                    UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);\
                                                }\
                                                else\
                                                {\
                                                    UserAdjustContrast(GET_OSD_CONTRAST());\
                                                    UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());\
                                                }\
                                                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\
											}
