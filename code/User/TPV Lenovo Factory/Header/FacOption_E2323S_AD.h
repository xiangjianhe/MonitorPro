//******************************************************************************************************************************************
//The Software is proprietary,confidential,and valuable to Realtek Semiconductor Corporation("Realtek").
//All rights,including but not limited to copyrights,patents,trademarks,trade secrets,mask work rights,
//and other similar rights and interests, are reserved to Realtek.Without prior written consent from Realtek,
//copying,reproduction,modification,distribution,or otherwise is strictly prohibited.
//The Software shall be kept strictly in confidence,and shall not be disclosed to or otherwise accessed by any third party.c <2003> - <2012>
//The Software is provided "AS IS" without any warranty of any kind,express, implied, statutory or otherwise.
//******************************************************************************************************************************************
//--------------------------------------------------
// Definitions of Factory Site
//--------------------------------------------------
#define _TPV_FACTORY_SELECT 							_TPV_FQ_FACTORY
#define _DFM_BYPASS_FORCE_PANELOFF						_OFF
//--------------------------------------------------
// Definitions of Factory OSD Menu
//--------------------------------------------------
#define _TPV_FACTORY_OSD								_OFF
#define _PANEL_SERVICE_MENU             				_OFF //_ON

//--------------------------------------------------
// Definitions of PowerOnLogo off/on  //DFM rev02 patch note 1
//--------------------------------------------------
#define _FORCE_LOGO_OFF                                 _OFF

//--------------------------------------------------
// Definitions of DFM function options
//--------------------------------------------------

#define DFM_BURN_IN()							GET_FACTORY_BURNIN()
// 20120417 by jerry, (DFM rev8 patch note 1)>>
#define _DFM_A0_PORT							0
#define _DFM_D0_PORT							1
#define _DFM_D1_PORT							2
#define DFM_DDC_WRITE_PORT						_DFM_A0_PORT

#define DFM_DVI1_DDC_CHANNEL                    _D1_DDC_CHANNEL_SEL
#define DFM_DVI2_DDC_CHANNEL                    _NO_DDC
#define DFM_HDMI1_DDC_CHANNEL					_NO_DDC
#define DFM_HDMI2_DDC_CHANNEL					_NO_DDC
#define DFM_DP1_DDC_CHANNEL						_NO_DDC
// 20120417 by jerry, (DFM rev8 patch note 1)<<

//--------------------------------------------------
//--------------------------------------------------
//TPV Factory Command setting by Project
#define COLORTEMP_RGAIN()		{\	
								SET_COLOR_TEMP_TYPE(_CT_USER);\
								RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());\	
								/*if(g_ucDdcciRxBuf[_FC_BYTE7]>100)\
									g_ucDdcciRxBuf[_FC_BYTE7]=100;\*/\
								SET_COLOR_TEMP_TYPE_USER_R(g_ucDdcciRxBuf[_FC_BYTE7]);\
								UserAdjustContrast(GET_OSD_CONTRAST());\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);\
								}
//--------------------------------------------------
#define COLORTEMP_GGAIN()		{\
								SET_COLOR_TEMP_TYPE(_CT_USER);\
								RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());\
								/*if(g_ucDdcciRxBuf[_FC_BYTE7]>100)\
									g_ucDdcciRxBuf[_FC_BYTE7]=100;\*/\
								SET_COLOR_TEMP_TYPE_USER_G(g_ucDdcciRxBuf[_FC_BYTE7]);\
								UserAdjustContrast(GET_OSD_CONTRAST());\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);\
								}
//--------------------------------------------------
#define COLORTEMP_BGAIN()		{\
								SET_COLOR_TEMP_TYPE(_CT_USER);\
								RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());\
								/*if(g_ucDdcciRxBuf[_FC_BYTE7]>100)\
									g_ucDdcciRxBuf[_FC_BYTE7]=100;\*/\
								SET_COLOR_TEMP_TYPE_USER_B(g_ucDdcciRxBuf[_FC_BYTE7]);\
								UserAdjustContrast(GET_OSD_CONTRAST());\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);\
								}			
//--------------------------------------------------
#define FC_CONTRAST()			{\
								SET_OSD_CONTRAST(g_ucDdcciRxBuf[_FC_BYTE7]);\
								UserAdjustContrast(GET_OSD_CONTRAST());\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);\
								}																											
//--------------------------------------------------
#define FC_BRIGHTNESS()			{\
								SET_OSD_BACKLIGHT(g_ucDdcciRxBuf[_FC_BYTE7]);\
								UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);\
								}					
//--------------------------------------------------
								
#define COLORTEMP_All_SAVE()	{\
								;\
								}
#define COLORTEMP_sRGB()		SET_COLOR_TEMP_TYPE(_CT_SRGB)
#define COLORTEMP_Native()    	;
#define COLORTEMP_4000()  		;
#define COLORTEMP_5000()  		;//SET_COLOR_TEMP_TYPE(_CT_5800)
#define COLORTEMP_6500()  		SET_COLOR_TEMP_TYPE(_CT_6500)
#define COLORTEMP_7200()  		SET_COLOR_TEMP_TYPE(_CT_7200)
#define COLORTEMP_8200()  		;
#define COLORTEMP_9300()  		SET_COLOR_TEMP_TYPE(_CT_9300)
#define COLORTEMP_10000() 		;
#define COLORTEMP_11500() 		;
#define COLORTEMP_User()  		SET_COLOR_TEMP_TYPE(_CT_USER)	

//--------------------------------------------------
#define COLORTEMP_RECALL()		{\
								RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());\	
								RTDNVRamLoadBriCon();\
								if(GET_COLOR_TEMP_TYPE()==_CT_USER)\
								{\
								;\
								}\
								UserAdjustContrast(GET_OSD_CONTRAST());\
								RTDNVRamSaveBriCon();\
								RTDNVRamSaveOSDData();\								
								}					



//--------------------------------------------------
#define COLORTEMP_SAVE()		{\																			
								RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());\
								}
//--------------------------------------------------
#define FC_RESET()				{\	
                                OsdFuncDisableOsd();\
                                SET_FACTORY_BURNIN(_ON);	\
                                OsdReset();\  
                                SET_FACTORY_BURNIN(_OFF);	\
                                TPVNVRamSaveFactoryDate();	\
								UserInterfaceKeyPadLedControl(_LED_TYPE_1);\
								}			
//--------------------------------------------------
#define FC_CHNIESE_T()			;//SET_OSD_LANGUAGE(_CHINESE_T)
#define FC_ENGLISH()   			SET_OSD_LANGUAGE(_ENGLISH)
#define FC_FRENCH()	  			SET_OSD_LANGUAGE(_FRENCH)
#define FC_GERMAN()				SET_OSD_LANGUAGE(_GERMAN)
#define FC_ITALIAN()   			SET_OSD_LANGUAGE(_ITALIAN)
#define FC_JAPANESE()     		SET_OSD_LANGUAGE(_JAPAN)
#define FC_KOREAN()				;//SET_OSD_LANGUAGE(_KOREA)
#define FC_PORTUGUESE_B()		;//SET_OSD_LANGUAGE(_PORTUGUESE)
#define FC_PORTUGUESE_P()		;
#define FC_RUSSIAN()			SET_OSD_LANGUAGE(_RUSSIAN)
#define FC_SPANISH()	 		SET_OSD_LANGUAGE(_SPANISH)
#define FC_SWEDISH()			;//SET_OSD_LANGUAGE(_SWEDISH)
#define FC_TURKISH()			;//SET_OSD_LANGUAGE(_TURKISH)
#define FC_CHINESE_S()			SET_OSD_LANGUAGE(_CHINESE_S)
#define FC_ARABIC()				;
#define FC_CZECH()				;//SET_OSD_LANGUAGE(_CZECH)
#define FC_DANISH()				;
#define FC_DUTCH()				;//SET_OSD_LANGUAGE (_DUTCH)
#define FC_FINNISH()			;//SET_OSD_LANGUAGE(_FINNISH)

#define FC_POLISH()				;//SET_OSD_LANGUAGE(_POLISH)												
//--------------------------------------------------
#define FC_LANGUAGE()			{\																				
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);\
								}	
//--------------------------------------------------
#define SWITCH_VGA()			{\																			
								/*SET_SHOW_SOURCE_INFO(_ON);*/\
								SysSourceSwitchInputPort(_A0_INPUT_PORT);\
								UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());\
								SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);\
								}		
					
//--------------------------------------------------
#define SWITCH_DVI()			{\																			
								/*SET_SHOW_SOURCE_INFO(_ON);*/\
								SysSourceSwitchInputPort(_D1_INPUT_PORT);\
								UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());\
								SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);\
								}	

//--------------------------------------------------
#define SWITCH_HDMI()			{\																			
                                ;\
								}	

//--------------------------------------------------
#define SWITCH_HDMI2()			{\
                                ;\
								}	

//--------------------------------------------------
#define SWITCH_DP()				{\																			
                                ;\
								}	

//--------------------------------------------------
#define ADC_RGAIN()				{\																			
								g_stAdcData.ucAdcGainMSB[0] = g_ucDdcciRxBuf[_FC_BYTE7];\				
								UserCommonInterfaceAdjustADCData();\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_ADCDATA_MSG);\
								}
//--------------------------------------------------
#define ADC_GGAIN()				{\																			
								g_stAdcData.ucAdcGainMSB[1] = g_ucDdcciRxBuf[_FC_BYTE7];\				
								UserCommonInterfaceAdjustADCData();\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_ADCDATA_MSG);\
								}		
				
//--------------------------------------------------
#define ADC_BGAIN()				{\																			
								g_stAdcData.ucAdcGainMSB[2] = g_ucDdcciRxBuf[_FC_BYTE7];\				
								UserCommonInterfaceAdjustADCData();\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_ADCDATA_MSG);\
								}		
																
//--------------------------------------------------
#define ADC_ROFFSET()			{\																			
								g_stAdcData.ucAdcOffsetMSB[0] = g_ucDdcciRxBuf[_FC_BYTE7];\				
								UserCommonInterfaceAdjustADCData();\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_ADCDATA_MSG);\
								}														
//--------------------------------------------------
#define ADC_GOFFSET()			{\																			
								g_stAdcData.ucAdcOffsetMSB[1] = g_ucDdcciRxBuf[_FC_BYTE7];\				
								UserCommonInterfaceAdjustADCData();\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_ADCDATA_MSG);\
								}
//--------------------------------------------------
#define ADC_BOFFSET()			{\																			
								g_stAdcData.ucAdcOffsetMSB[2] = g_ucDdcciRxBuf[_FC_BYTE7];\				
								UserCommonInterfaceAdjustADCData();\
								SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_ADCDATA_MSG);\
								}
//--------------------------------------------------
#define ExitFactroyMode()		{\
								SET_FACTORY_MODE(_OFF);\
								TPVNVRamSaveFactoryDate();\
								}										
						
//--------------------------------------------------
#define EnterFactroyMode()		{\
								SET_FACTORY_MODE(_ON);\
								ScalerOsdDisableOsd();\
								TPVNVRamSaveFactoryDate();\
								}					
//--------------------------------------------------
#define CheckFactroyMode()		GET_FACTORY_MODE()
//--------------------------------------------------
#define BurnIn_On()				{\
							    SET_FACTORY_BURNIN(_ON);\
							    TPVNVRamSaveFactoryDate();\
								}
//--------------------------------------------------
#define BurnIn_Off()			{\
								SET_FACTORY_BURNIN(_OFF);\
								TPVNVRamSaveFactoryDate();\
								}											
//--------------------------------------------------
#define DPEDID_ERASE()			;									
//--------------------------------------------------
#define DPEDID_WRITE()			{\
                                ;\
								}

//--------------------------------------------------
#define DPEDID_READ()			{\
                                ;\
								}
//--------------------------------------------------
#define BACKLIGHTTIME_INITIAL()	{\
								RTDNVRamRestorePanelUsedTimeData();\			
								}	
//--------------------------------------------------
#define EXIT_DFMPROC()			;//COsdFuncReset()
//20121018_2 HDCP KEY Modify
#if(_FLASH_ACCESS_FUNCTION_SUPPORT == _OFF)
//--------------------------------------------------
#define HDCP_START()			{\
								;\
								}
//--------------------------------------------------

#define HDCP_WRITE()			{\
								UserCommonEepromWrite(_EEPROM_HDCP_KEY_ADDRESS+_HDCP_BLOCK_SIZE*g_ucDdcciRxBuf[_FC_BYTE6], _HDCP_BLOCK_SIZE, &g_ucDdcciRxBuf[_FC_BYTE7]);\
								}\
//--------------------------------------------------
#define HDCP_READ(x)			{\	
								UserCommonEepromRead(_EEPROM_HDCP_KEY_ADDRESS+x, 8, pData);\	
                                }
#else

#define HDCP_START()			{\
								UserCommonFlashErasePage(_OGC_FLASH_BANK,_HDCP_PAGE);\
								}

#define HDCP_WRITE()			{\
								UserCommonFlashWrite(_OGC_FLASH_BANK,(_HDCP_PAGE) * _FLASH_PAGE_SIZE+_HDCP_BLOCK_SIZE*g_ucDdcciRxBuf[_FC_BYTE6], _HDCP_BLOCK_SIZE, &g_ucDdcciRxBuf[_FC_BYTE7]);\
								}
#define HDCP_READ(x)			{\	
								UserCommonFlashRead(_OGC_FLASH_BANK,(_HDCP_PAGE) * _FLASH_PAGE_SIZE+x, 8, pData);\									
								}
#endif

#define DFM_POWERON_REALL()		{\
								OsdReset();\
								}

#define I_CARE_I_AIR_SWITCH()	{\
                                }

#define TPVAutoDoWhiteBalance() {\
									if((SysSourceGetSourceType() == _SOURCE_VGA))\
									{\
										if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_RGB) == _AUTO_SUCCESS)\
										{\
					                        TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);\
											ScalerAutoGetAutoColorResult(&g_stAdcData);\									
                                            g_stAdcData.ucAdcOffsetMSB[0]=g_stAdcData.ucAdcOffsetMSB[0];\
                                            g_stAdcData.ucAdcOffsetMSB[1]=g_stAdcData.ucAdcOffsetMSB[1];\
                                            g_stAdcData.ucAdcOffsetMSB[2]=g_stAdcData.ucAdcOffsetMSB[2];\
                                            g_stAdcData.ucAdcGainMSB[0]=g_stAdcData.ucAdcGainMSB[0];\
                                            g_stAdcData.ucAdcGainMSB[1]=g_stAdcData.ucAdcGainMSB[1];\
                                            g_stAdcData.ucAdcGainMSB[2]=g_stAdcData.ucAdcGainMSB[2];\  
											UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);\
                                            UserCommonInterfaceAdjustADCData();\
                                            TPVFactoryMainMenu();\
                                            TPVFactoryAutoColorShowPass();\
										}\
										else\
										{\
					                        TPVFCReplyCommand(_REPLY_RESULT_04, _AWB_COMMAND_LEN_CRC);\
										}\
									}\
                                }

//--------------------------------------------------
//if project have code bank issue, modify following definition to null.  
#define TIMER_NOSIGNAL()			ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL)
#define TIMER_SAVING()				ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_GO_TO_POWER_SAVING)

//--------------------------------------------------
#define FC_DFM_INITIAL()			{\
									;\
									}
//--------------------------------------------------
#define FC_AUDIO_VOLUMN()			SET_OSD_VOLUME(90);

//DFM rev02 patch note 8>>
#define FC_EDID_EEPROM_WP_ENABLE()	{\
									PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);\
									PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);\
									PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);\
									}
#define FC_EDID_EEPROM_WP_DISABLE()	{\
									PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);\
									PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);\
									PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);\
									}

//DFM rev02 patch note 8<<
//DFM rev05 patch note 1>>
//for Philips, Lenovo,FTS, VSC,BENQ,ASUS,ACER
#define FC_DC_COLOR_MODE_SWITCH(x,y){\
										switch(x)\ 
										{\
											case 0x00:\
												break;\
											case 0x01:\
												break;\
											case 0x02:\
												break;\	
											case 0x03:\
												break;\	
											case 0x04:\
												break;\	
											case 0x05:\
												break;\
											case 0x07:\
												break;\		
											case 0x0B:\
												if(y==0x01)\
													;\
												break;\
											case 0x0C:\
												break;\ 
											case 0x0D:\
												break;\ 
											case 0x0E:\
												break;\											
											case 0x0F:\
												break;\											
											default:\
												break;\
										}\
									}

#define FC_A7_03_DCR_COMMAND(x)		{\
										if(x==0x01)\
											;\
										else\
											;\
									}
//for AOC project ICARE or IAIR, for FTS project Auto Brightness, For BenQ project Eye Protect Sensor
#define FC_A4_12_COMMAND(x)			{\
									}

//for AOC project DPS mode
#define FC_A4_13_COMMAND(x)			{\
									}

//For DELL project Enerysmart
#define FC_A4_14_COMMAND(x)			{\
									}
//for Philips Project ErgoSensor, for BENQ project ECO sensor
#define FC_A4_08_COMMAND(x)			{\
									}
//DFM rev05 patch note 1<<

//DFM rev05 patch note 5>>
#define RestoreNVRaw()          {\
                                RTDNVRamWholeRestore();\
                                }
//DFM rev05 patch note 5<<
