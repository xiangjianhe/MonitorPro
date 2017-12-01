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
// ID Code      : UserOSDActionFlow.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDACTIONFLOW__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2011_OSD)
code void (*OperationTable[][4])(void) =
{
    {RTDOsdNoneMenu,                                        RTDOsdNoneLeft,                                        RTDOsdNoneRight,                                        RTDOsdNoneExit,                                        },
    {RTDOsdMainPictureMenu,                                 RTDOsdMainPictureLeft,                                 RTDOsdMainPictureRight,                                 RTDOsdMainPictureExit,                                 },
    {RTDOsdMainDisplayMenu,                                 RTDOsdMainDisplayLeft,                                 RTDOsdMainDisplayRight,                                 RTDOsdMainDisplayExit,                                 },
    {RTDOsdMainColorMenu,                                   RTDOsdMainColorLeft,                                   RTDOsdMainColorRight,                                   RTDOsdMainColorExit,                                   },
    {RTDOsdMainAdvanceMenu,                                 RTDOsdMainAdvanceLeft,                                 RTDOsdMainAdvanceRight,                                 RTDOsdMainAdvanceExit,                                 },
    {RTDOsdMainInputMenu,                                   RTDOsdMainInputLeft,                                   RTDOsdMainInputRight,                                   RTDOsdMainInputExit,                                   },
    {RTDOsdMainAudioMenu,                                   RTDOsdMainAudioLeft,                                   RTDOsdMainAudioRight,                                   RTDOsdMainAudioExit,                                   },
    {RTDOsdMainOthersMenu,                                  RTDOsdMainOthersLeft,                                  RTDOsdMainOthersRight,                                  RTDOsdMainOthersExit,                                  },
    {RTDOsdMainInformationMenu,                             RTDOsdMainInformationLeft,                             RTDOsdMainInformationRight,                             RTDOsdMainInformationExit,                             },
    {RTDOsdMainFactoryMenu,                                 RTDOsdMainFactoryLeft,                                 RTDOsdMainFactoryRight,                                 RTDOsdMainFactoryExit,                                 },

    {RTDOsdPictureBacklightMenu,                            RTDOsdPictureBacklightLeft,                            RTDOsdPictureBacklightRight,                            RTDOsdPictureBacklightExit,                            },
    {RTDOsdPictureBrightnessMenu,                           RTDOsdPictureBrightnessLeft,                           RTDOsdPictureBrightnessRight,                           RTDOsdPictureBrightnessExit,                           },
    {RTDOsdPictureContrastMenu,                             RTDOsdPictureContrastLeft,                             RTDOsdPictureContrastRight,                             RTDOsdPictureContrastExit,                             },             
    {RTDOsdPictureSharpnessMenu,                            RTDOsdPictureSharpnessLeft,                            RTDOsdPictureSharpnessRight,                            RTDOsdPictureSharpnessExit,                            },
    {RTDOsdPictureBacklightAdjustMenu,                      RTDOsdPictureBacklightAdjustLeft,                      RTDOsdPictureBacklightAdjustRight,                      RTDOsdPictureBacklightAdjustExit,                      },
    {RTDOsdPictureBrightnessAdjustMenu,                     RTDOsdPictureBrightnessAdjustLeft,                     RTDOsdPictureBrightnessAdjustRight,                     RTDOsdPictureBrightnessAdjustExit,                     },
    {RTDOsdPictureContrastAdjustMenu,                       RTDOsdPictureContrastAdjustLeft,                       RTDOsdPictureContrastAdjustRight,                       RTDOsdPictureContrastAdjustExit,                       }, 
    {RTDOsdPictureSharpnessAdjustMenu,                      RTDOsdPictureSharpnessAdjustLeft,                      RTDOsdPictureSharpnessAdjustRight,                      RTDOsdPictureSharpnessAdjustExit,                      },

    {RTDOsdDisplayAutoMenu,                                 RTDOsdDisplayAutoLeft,                                 RTDOsdDisplayAutoRight,                                 RTDOsdDisplayAutoExit,                                 },
    {RTDOsdDisplayHPositionMenu,                            RTDOsdDisplayHPositionLeft,                            RTDOsdDisplayHPositionRight,                            RTDOsdDisplayHPositionExit,                            },
    {RTDOsdDisplayVPositionMenu,                            RTDOsdDisplayVPositionLeft,                            RTDOsdDisplayVPositionRight,                            RTDOsdDisplayVPositionExit,                            },
    {RTDOsdDisplayClockMenu,                                RTDOsdDisplayClockLeft,                                RTDOsdDisplayClockRight,                                RTDOsdDisplayClockExit,                                },
    {RTDOsdDisplayPhaseMenu,                                RTDOsdDisplayPhaseLeft,                                RTDOsdDisplayPhaseRight,                                RTDOsdDisplayPhaseExit,                                },
    {RTDOsdDisplayHPositionAdjustMenu,                      RTDOsdDisplayHPositionAdjustLeft,                      RTDOsdDisplayHPositionAdjustRight,                      RTDOsdDisplayHPositionAdjustExit,                      },
    {RTDOsdDisplayVPositionAdjustMenu,                      RTDOsdDisplayVPositionAdjustLeft,                      RTDOsdDisplayVPositionAdjustRight,                      RTDOsdDisplayVPositionAdjustExit,                      },
    {RTDOsdDisplayClockAdjustMenu,                          RTDOsdDisplayClockAdjustLeft,                          RTDOsdDisplayClockAdjustRight,                          RTDOsdDisplayClockAdjustExit,                          },
    {RTDOsdDisplayPhaseAdjustMenu,                          RTDOsdDisplayPhaseAdjustLeft,                          RTDOsdDisplayPhaseAdjustRight,                          RTDOsdDisplayPhaseAdjustExit,                          },

    {RTDOsdColorGammaMenu,                                  RTDOsdColorGammaLeft,                                  RTDOsdColorGammaRight,                                  RTDOsdColorGammaExit,                                  },
    {RTDOsdColorColortempMenu,                              RTDOsdColorColortempLeft,                              RTDOsdColorColortempRight,                              RTDOsdColorColortempExit,                              },
    {RTDOsdColorEffectMenu,                                 RTDOsdColorEffectLeft,                                 RTDOsdColorEffectRight,                                 RTDOsdColorEffectExit,                                 },
    {RTDOsdColorDemoMenu,                                   RTDOsdColorDemoLeft,                                   RTDOsdColorDemoRight,                                   RTDOsdColorDemoExit,                                   },
    {RTDOsdColorFormatMenu,                                 RTDOsdColorFormatLeft,                                 RTDOsdColorFormatRight,                                 RTDOsdColorFormatExit,                                 },
    {RTDOsdColorPCMMenu,                                    RTDOsdColorPCMLeft,                                    RTDOsdColorPCMRight,                                    RTDOsdColorPCMExit,                                    },
    {RTDOsdColorHueMenu,                                    RTDOsdColorHueLeft,                                    RTDOsdColorHueRight,                                    RTDOsdColorHueExit,                                    },
    {RTDOsdColorSaturationMenu,                             RTDOsdColorSaturationLeft,                             RTDOsdColorSaturationRight,                             RTDOsdColorSaturationExit,                             },
    {RTDOsdColorGammaAdjustMenu,                            RTDOsdColorGammaAdjustLeft,                            RTDOsdColorGammaAdjustRight,                            RTDOsdColorGammaAdjustExit,                            },
    {RTDOsdColorColortempSelectMenu,                        RTDOsdColorColortempSelectLeft,                        RTDOsdColorColortempSelectRight,                        RTDOsdColorColortempSelectExit,                        },
    {RTDOsdColorColorEffectSelectMenu,                      RTDOsdColorColorEffectSelectLeft,                      RTDOsdColorColorEffectSelectRight,                      RTDOsdColorColorEffectSelectExit,                      },
    {RTDOsdColorDemoSelectMenu,                             RTDOsdColorDemoSelectLeft,                             RTDOsdColorDemoSelectRight,                             RTDOsdColorDemoSelectExit,                             },
    {RTDOsdColorFormatSelectMenu,                           RTDOsdColorFormatSelectLeft,                           RTDOsdColorFormatSelectRight,                           RTDOsdColorFormatSelectExit,                           },
    {RTDOsdColorPCMSelectMenu,                              RTDOsdColorPCMSelectLeft,                              RTDOsdColorPCMSelectRight,                              RTDOsdColorPCMSelectExit,                              },
    {RTDOsdColorHueAdjustMenu,                              RTDOsdColorHueAdjustLeft,                              RTDOsdColorHueAdjustRight,                              RTDOsdColorHueAdjustExit,                              },
    {RTDOsdColorSaturationAdjustMenu,                       RTDOsdColorSaturationAdjustLeft,                       RTDOsdColorSaturationAdjustRight,                       RTDOsdColorSaturationAdjustExit,                       },
    {RTDOsdColorColortempUserRMenu,                         RTDOsdColorColortempUserRLeft,                         RTDOsdColorColortempUserRRight,                         RTDOsdColorColortempUserRExit,                         },
    {RTDOsdColorColortempUserGMenu,                         RTDOsdColorColortempUserGLeft,                         RTDOsdColorColortempUserGRight,                         RTDOsdColorColortempUserGExit,                         },
    {RTDOsdColorColortempUserBMenu,                         RTDOsdColorColortempUserBLeft,                         RTDOsdColorColortempUserBRight,                         RTDOsdColorColortempUserBExit,                         },
    {RTDOsdColorColortempUserRAdjustMenu,                   RTDOsdColorColortempUserRAdjustLeft,                   RTDOsdColorColortempUserRAdjustRight,                   RTDOsdColorColortempUserRAdjustExit,                   },
    {RTDOsdColorColortempUserGAdjustMenu,                   RTDOsdColorColortempUserGAdjustLeft,                   RTDOsdColorColortempUserGAdjustRight,                   RTDOsdColorColortempUserGAdjustExit,                   },
    {RTDOsdColorColortempUserBAdjustMenu,                   RTDOsdColorColortempUserBAdjustLeft,                   RTDOsdColorColortempUserBAdjustRight,                   RTDOsdColorColortempUserBAdjustExit,                   },  
    {RTDOsdColorColorEffectSixColorMenu,                    RTDOsdColorColorEffectSixColorLeft,                    RTDOsdColorColorEffectSixColorRight,                    RTDOsdColorColorEffectSixColorExit,                    },
    {RTDOsdColorColorEffectSixColorHueMenu,                 RTDOsdColorColorEffectSixColorHueLeft,                 RTDOsdColorColorEffectSixColorHueRight,                 RTDOsdColorColorEffectSixColorHueExit,                 },
    {RTDOsdColorColorEffectSixColorSaturationMenu,          RTDOsdColorColorEffectSixColorSaturationLeft,          RTDOsdColorColorEffectSixColorSaturationRight,          RTDOsdColorColorEffectSixColorSaturationExit,          },
    {RTDOsdColorColorEffectSixColorSelectMenu,              RTDOsdColorColorEffectSixColorSelectLeft,              RTDOsdColorColorEffectSixColorSelectRight,              RTDOsdColorColorEffectSixColorSelectExit,              },
    {RTDOsdColorColorEffectSixColorHueAdjustMenu,           RTDOsdColorColorEffectSixColorHueAdjustLeft,           RTDOsdColorColorEffectSixColorHueAdjustRight,           RTDOsdColorColorEffectSixColorHueAdjustExit,           },
    {RTDOsdColorColorEffectSixColorSaturationAdjustMenu,    RTDOsdColorColorEffectSixColorSaturationAdjustLeft,    RTDOsdColorColorEffectSixColorSaturationAdjustRight,    RTDOsdColorColorEffectSixColorSaturationAdjustExit,    },

    {RTDOsdAdvanceAspectRatioMenu,                          RTDOsdAdvanceAspectRatioLeft,                          RTDOsdAdvanceAspectRatioRight,                          RTDOsdAdvanceAspectRatioExit,                          },
    {RTDOsdAdvanceOversacnMenu,                             RTDOsdAdvanceOversacnLeft,                             RTDOsdAdvanceOversacnRight,                             RTDOsdAdvanceOversacnExit,                             },
    {RTDOsdAdvanceOverdriveMenu,                            RTDOsdAdvanceOverdriveLeft,                            RTDOsdAdvanceOverdriveRight,                            RTDOsdAdvanceOverdriveExit,                            },
    {RTDOsdAdvanceESMenu,                                   RTDOsdAdvanceESLeft,                                   RTDOsdAdvanceESRight,                                   RTDOsdAdvanceESExit,                                   },
    {RTDOsdAdvanceDdcciMenu,                                RTDOsdAdvanceDdcciLeft,                                RTDOsdAdvanceDdcciRight,                                RTDOsdAdvanceDdcciExit,                                },
    {RTDOsdAdvanceUltraVividMenu,                           RTDOsdAdvanceUltraVividLeft,                           RTDOsdAdvanceUltraVividRight,                           RTDOsdAdvanceUltraVividExit,                           },
#if(_OSD_3D_FUNCTION == _ON)        
    {RTDOsdAdvance3DMenu,                                   RTDOsdAdvance3DLeft,                                   RTDOsdAdvance3DRight,                                   RTDOsdAdvance3DExit,                                   },
#endif

    {RTDOsdAdvanceAspectRatioSelectMenu,                    RTDOsdAdvanceAspectRatioSelectLeft,                    RTDOsdAdvanceAspectRatioSelectRight,                    RTDOsdAdvanceAspectRatioSelectExit,                    },
    {RTDOsdAdvanceOversacnSelectMenu,                       RTDOsdAdvanceOversacnSelectLeft,                       RTDOsdAdvanceOversacnSelectRight,                       RTDOsdAdvanceOversacnSelectExit,                       },
    {RTDOsdAdvanceOverdriveSelectMenu,                      RTDOsdAdvanceOverdriveSelectLeft,                      RTDOsdAdvanceOverdriveSelectRight,                      RTDOsdAdvanceOverdriveSelectExit,                      },
    {RTDOsdAdvanceESSelectMenu,                             RTDOsdAdvanceESSelectLeft,                             RTDOsdAdvanceESSelectRight,                            RTDOsdAdvanceESSelectExit,                              },
    {RTDOsdAdvanceDdcciSelectMenu,                          RTDOsdAdvanceDdcciSelectLeft,                          RTDOsdAdvanceDdcciSelectRight,                          RTDOsdAdvanceDdcciSelectExit,                          },
    {RTDOsdAdvanceUltraVividSelectMenu,                     RTDOsdAdvanceUltraVividSelectLeft,                     RTDOsdAdvanceUltraVividSelectRight,                     RTDOsdAdvanceUltraVividSelectExit,                     },
#if(_OSD_3D_FUNCTION == _ON)        
    {RTDOsdAdvance3DSelectMenu,                             RTDOsdAdvance3DSelectLeft,                             RTDOsdAdvance3DSelectRight,                             RTDOsdAdvance3DSelectExit,                             },
#endif 

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    {RTDOsdAspectOriginalRatioMenu,                         RTDOsdAspectOriginalRatioLeft,                         RTDOsdAspectOriginalRatioRight,                         RTDOsdAspectOriginalRatioExit,                         },
#endif

    {RTDOsdAdvanceOdGainAdjustMenu,                         RTDOsdAdvanceOdGainAdjustLeft,                         RTDOsdAdvanceOdGainAdjustRight,                         RTDOsdAdvanceOdGainAdjustExit,                         },

#if(_OSD_3D_FUNCTION == _ON)        
    {RTDOsdAdvance3DLRMenu,                                 RTDOsdAdvance3DLRLeft,                                 RTDOsdAdvance3DLRRight,                                 RTDOsdAdvance3DLRExit,                                 },
    {RTDOsdAdvance3DEffectMenu,                             RTDOsdAdvance3DEffectLeft,                             RTDOsdAdvance3DEffectRight,                             RTDOsdAdvance3DEffectExit,                             },
    {RTDOsdAdvance3DFormatMenu,                             RTDOsdAdvance3DFormatLeft,                             RTDOsdAdvance3DFormatRight,                             RTDOsdAdvance3DFormatExit,                             },
    {RTDOsdAdvance3D3DTO2DMenu,                             RTDOsdAdvance3D3DTO2DLeft,                             RTDOsdAdvance3D3DTO2DRight,                             RTDOsdAdvance3D3DTO2DExit,                             },
    {RTDOsdAdvance3DLRSelectMenu,                           RTDOsdAdvance3DLRSelectLeft,                           RTDOsdAdvance3DLRSelectRight,                           RTDOsdAdvance3DLRSelectExit,                           },
    {RTDOsdAdvance3DEffectAdjustMenu,                       RTDOsdAdvance3DEffectAdjustLeft,                       RTDOsdAdvance3DEffectAdjustRight,                       RTDOsdAdvance3DEffectAdjustExit,                       },
    {RTDOsdAdvance3DFormatSelectMenu,                       RTDOsdAdvance3DFormatSelectLeft,                       RTDOsdAdvance3DFormatSelectRight,                       RTDOsdAdvance3DFormatSelectExit,                       },
    {RTDOsdAdvance3D3DTO2DSelectMenu,                       RTDOsdAdvance3D3DTO2DSelectLeft,                       RTDOsdAdvance3D3DTO2DSelectRight,                       RTDOsdAdvance3D3DTO2DSelectExit,                       },
#if(_2D_TO_3D_FUNCTION == _ON)
    {RTDOsdAdvance3DConvergenceMenu,                        RTDOsdAdvance3DConvergenceLeft,                        RTDOsdAdvance3DConvergenceRight,                        RTDOsdAdvance3DConvergenceExit,                        },
    {RTDOsdAdvance3DConvergenceSelectMenu,                  RTDOsdAdvance3DConvergenceSelectLeft,                  RTDOsdAdvance3DConvergenceSelectRight,                  RTDOsdAdvance3DConvergenceSelectExit,                  },
    {RTDOsdAdvance3DConvergenceModeMenu,                    RTDOsdAdvance3DConvergenceModeLeft,                    RTDOsdAdvance3DConvergenceModeRight,                    RTDOsdAdvance3DConvergenceModeExit,                    },
    {RTDOsdAdvance3DConvergenceModeSelectMenu,              RTDOsdAdvance3DConvergenceModeSelectLeft,              RTDOsdAdvance3DConvergenceModeSelectRight,              RTDOsdAdvance3DConvergenceModeSelectExit,              },
#endif
#endif

    {RTDOsdInputAutoMenu,                                   RTDOsdInputAutoLeft,                                   RTDOsdInputAutoRight,                                   RTDOsdInputAutoExit,                                   },        

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    {RTDOsdInputA0Menu,                                     RTDOsdInputA0Left,                                     RTDOsdInputA0Right,                                     RTDOsdInputA0Exit,                                     },        
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    {RTDOsdInputD0Menu,                                     RTDOsdInputD0Left,                                     RTDOsdInputD0Right,                                     RTDOsdInputD0Exit,                                     },        
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    {RTDOsdInputD1Menu,                                     RTDOsdInputD1Left,                                     RTDOsdInputD1Right,                                     RTDOsdInputD1Exit,                                     },        
#endif

    {RTDOsdAudioVolumeMenu,                                 RTDOsdAudioVolumeLeft,                                 RTDOsdAudioVolumeRight,                                 RTDOsdAudioVolumeExit,                                 },
    {RTDOsdAudioMuteMenu,                                   RTDOsdAudioMuteLeft,                                   RTDOsdAudioMuteRight,                                   RTDOsdAudioMuteExit,                                   },
    {RTDOsdAudioStandAloneMenu,                             RTDOsdAudioStandAloneLeft,                             RTDOsdAudioStandAloneRight,                             RTDOsdAudioStandAloneExit,                             },        
    {RTDOsdAudioSourceMenu,                                 RTDOsdAudioSourceLeft,                                 RTDOsdAudioSourceRight,                                 RTDOsdAudioSourceExit,                                 },
    {RTDOsdAudioSoundModeMenu,                              RTDOsdAudioSoundModeLeft,                              RTDOsdAudioSoundModeRight,                              RTDOsdAudioSoundModeExit,                              },
    {RTDOsdAudioVolumeAdjustMenu,                           RTDOsdAudioVolumeAdjustLeft,                           RTDOsdAudioVolumeAdjustRight,                           RTDOsdAudioVolumeAdjustExit,                           },
    {RTDOsdAudioMuteSelectMenu,                             RTDOsdAudioMuteSelectLeft,                             RTDOsdAudioMuteSelectRight,                             RTDOsdAudioMuteSelectExit,                             },
    {RTDOsdAudioStandAloneSelectMenu,                       RTDOsdAudioStandAloneSelectLeft,                       RTDOsdAudioStandAloneSelectRight,                       RTDOsdAudioStandAloneSelectExit,                       },    
    {RTDOsdAudioSourceSelectMenu,                           RTDOsdAudioSourceSelectLeft,                           RTDOsdAudioSourceSelectRight,                           RTDOsdAudioSourceSelectExit,                           },
    {RTDOsdAudioSoundModeSelectMenu,                        RTDOsdAudioSoundModeSelectLeft,                        RTDOsdAudioSoundModeSelectRight,                        RTDOsdAudioSoundModeSelectExit,                        },    

    {RTDOsdOtherResetMenu,                                  RTDOsdOtherResetLeft,                                  RTDOsdOtherResetRight,                                  RTDOsdOtherResetExit,                                  },    
    {RTDOsdOtherMenuTimeMenu,                               RTDOsdOtherMenuTimeLeft,                               RTDOsdOtherMenuTimeRight,                               RTDOsdOtherMenuTimeExit,                               },    
    {RTDOsdOtherHPositionMenu,                              RTDOsdOtherHPositionLeft,                              RTDOsdOtherHPositionRight,                              RTDOsdOtherHPositionExit,                              },    
    {RTDOsdOtherVPositionMenu,                              RTDOsdOtherVPositionLeft,                              RTDOsdOtherVPositionRight,                              RTDOsdOtherVPositionExit,                              },    
    {RTDOsdOtherLanguageMenu,                               RTDOsdOtherLanguageLeft,                               RTDOsdOtherLanguageRight,                               RTDOsdOtherLanguageExit,                               },    
    {RTDOsdOtherTransMenu,                                  RTDOsdOtherTransLeft,                                  RTDOsdOtherTransRight,                                  RTDOsdOtherTransExit,                                  },    
    {RTDOsdOtherRotateMenu,                                 RTDOsdOtherRotateLeft,                                 RTDOsdOtherRotateRight,                                 RTDOsdOtherRotateExit,                                 },    
        
#if(_OSD_3D_FUNCTION == _ON)        
    {RTDOsdOther3DOSDMenu,                                  RTDOsdOther3DOSDLeft,                                  RTDOsdOther3DOSDRight,                                  RTDOsdOther3DOSDExit,                                  },  
#endif

    {RTDOsdOtherMenuTimeAdjustMenu,                         RTDOsdOtherMenuTimeAdjustLeft,                         RTDOsdOtherMenuTimeAdjustRight,                         RTDOsdOtherMenuTimeAdjustExit,                         },    
    {RTDOsdOtherHPositionAdjustMenu,                        RTDOsdOtherHPositionAdjustLeft,                        RTDOsdOtherHPositionAdjustRight,                        RTDOsdOtherHPositionAdjustExit,                        },   
    {RTDOsdOtherVPositionAdjustMenu,                        RTDOsdOtherVPositionAdjustLeft,                        RTDOsdOtherVPositionAdjustRight,                        RTDOsdOtherVPositionAdjustExit,                        },    
    {RTDOsdOtherLanguageSelectMenu,                         RTDOsdOtherLanguageSelectLeft,                         RTDOsdOtherLanguageSelectRight,                         RTDOsdOtherLanguageSelectExit,                         },    
    {RTDOsdOtherTransAdjustMenu,                            RTDOsdOtherTransAdjustLeft,                            RTDOsdOtherTransAdjustRight,                            RTDOsdOtherTransAdjustExit,                            },    
    {RTDOsdOtherRotateSelectMenu,                           RTDOsdOtherRotateSelectLeft,                           RTDOsdOtherRotateSelectRight,                           RTDOsdOtherRotateSelectExit,                           },

#if(_OSD_3D_FUNCTION == _ON)        
    {RTDOsdOther3DOSDSelectMenu,                            RTDOsdOther3DOSDSelectLeft,                            RTDOsdOther3DOSDSelectRight,                            RTDOsdOther3DOSDSelectExit,                            },
#endif

    {RTDOsdHotKeyAutoSourceMenu,                            RTDOsdHotKeyAutoSourceLeft,                            RTDOsdHotKeyAutoSourceRight,                            RTDOsdHotKeyAutoSourceExit,                            },

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    {RTDOsdHotKeyA0Menu,                                    RTDOsdHotKeyA0Left,                                    RTDOsdHotKeyA0Right,                                    RTDOsdHotKeyA0Exit,                                    },
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    {RTDOsdHotKeyD0Menu,                                    RTDOsdHotKeyD0Left,                                    RTDOsdHotKeyD0Right,                                    RTDOsdHotKeyD0Exit,                                    },
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    {RTDOsdHotKeyD1Menu,                                    RTDOsdHotKeyD1Left,                                    RTDOsdHotKeyD1Right,                                    RTDOsdHotKeyD1Exit,                                    },
#endif

};
#endif//#if(_OSD_TYPE == _REALTEK_2011_OSD)
