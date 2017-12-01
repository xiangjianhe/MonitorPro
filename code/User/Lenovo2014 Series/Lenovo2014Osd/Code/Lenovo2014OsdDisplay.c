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
// ID Code      : UserOSDDisplay.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDDISPLAY__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LENOVO_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Definitions of Item list
//--------------------------------------------------
#define _ITEM_DYNAMIC_STEP_0                        0
#define _ITEM_DYNAMIC_STEP_1                        1
#define _ITEM_DYNAMIC_STEP_2                        2
#define _ITEM_DYNAMIC_STEP_3                        3
#define _ITEM_DYNAMIC_STEP_MAX                      4


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
WORD Xpos=100,Ypos=100;//lorimiao 20130731 for MSG OSD Move
bit Xdirect=1,Ydirect=1;
BYTE ucLedFlashCount = 0;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdDispMainMenu(void);

#if(_INPUT_PORT_MAX >= 0x01)
BYTE OsdDisplayJudgeSourceType(void);
#endif
void OsdDisplayTimingAndInputSource(void);
void OsdDisplayNoSupportProc(void);
void OsdDisplayNoCableProc(void);
void OsdDisplayWakeUpShowSource();

#if(_VGA_SUPPORT == _ON)
void OsdDisplayAutoProc(void);
void OsdDisplayAutoBalanceProc(void);
#endif
BYTE OsdDispJudgeSourceType(void);
void OsdDisplayShowLogo(void);
void OsdDisplayOsdMessage(BYTE ucMessage);
void OsdDisplayWakeUpSwitchDdcciPort(void);
void OsdDisplayPowerSavingProc(void);
void OsdDisplaySetPosition(BYTE ucType, WORD usHPos, WORD usVPos);
void OsdDisplayDisableOsd(void);
WORD OsdDisplayDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle);
void OsdDisplayDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
void OsdDisplayDispButton(BYTE ucState);
void OsdDisplayMainMenuDescription(BYTE ucState);
void OsdDispMessageFlying(void);
#if(_INPUT_PORT_MAX >= 0x01)
void OsdDispInputInfo(void);
#endif
void OsdDisplayItemDraw(BYTE ucItem, BYTE ucItemStatus, BYTE ucOsdState);
void OsdDisplayItemFrame(BYTE ucRow, BYTE ucCol, BYTE ucBgColor);
void OsdDisplayIconFrame(BYTE ucRow, BYTE ucCol, BYTE ucBgColor);
void OsdDisplayIconColor(BYTE ucRow, BYTE ucCol, BYTE ucFgColor, BYTE ucBgColor);
void OsdDisplayDrawFocusFrame(BYTE ucRow);
void OsdDisplayClearFocusFrame(BYTE ucRow);
void OsdDisplayDrawBar(BYTE ucRow, BYTE ucBarValue, BYTE ucBarType);
//void OsdDisplayClearBar(BYTE ucRow);
void OsdDisplayDrawInformation(void);
void OsdDispInformationPage(void);
bit OsdDisplayWaitForDrawing(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************


//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
 //顯示OSD Main主選單
void OsdDispMainMenu(void)
{
    OsdDisplayDisableOsd();
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

    //==== Factory Icon=======
    //20140929 Abel Modify
    if(GET_FACTORY_MODE()== _ON)
    {   
        //show"F"
        //OsdFunc1bitColor(ROW(18), COL(35), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_YELLOW), BGCOLOR(_CP_ITEM_FOCUS_BG));
        //OsdFunc1bitChar(ROW(18), COL(35), WIDTH(1), HEIGHT(1), CHAR(_Factory_F_));   

        SET_OSD_STATE(_MAIN_FACTORY);
#if((_INPUT_PORT_MAX <= 0x01) &&(_OD_OSD_SUPPORT == _OFF) && (_ASPECT_RATIO_SUPPORT == _ON))
		OsdDisplayItemDraw(_ICON_1_1, (((GET_OSD_DCR_STATUS() == _ON)&&(UserCheckAspectRatioFunction() == _FALSE)) ? (_ITEM_UNSELECT) : (_ITEM_SELECT)), _MAIN_IMAGE_PROPERTIES);
#else
		OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
#endif
        OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_OPTIONS);
        OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS,  _MAIN_FACTORY);
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
		OsdDisplayItemDraw(_ICON_1_4, (((GET_COLOR_TEMP_TYPE() == _CT_SRGB)||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) ? (_ITEM_UNSELECT) : (_ITEM_SELECT)), _MAIN_BRI_CON_DCR);
#else
		OsdDisplayItemDraw(_ICON_1_4, ((GET_COLOR_TEMP_TYPE() == _CT_SRGB) ? (_ITEM_UNSELECT) : (_ITEM_SELECT)), _MAIN_BRI_CON_DCR);
#endif
        OsdDisplayItemDraw(_ICON_1_5, ((SysSourceGetInputPort() != _A0_INPUT_PORT) ? (_ITEM_UNSELECT) : (_ITEM_SELECT)), _MAIN_IMAGE_POSITION);

    }    
    else
    {
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
	if((GET_COLOR_TEMP_TYPE() == _CT_SRGB)||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON))
#else
	if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
#endif
        {
            if(SysSourceGetInputPort() != _A0_INPUT_PORT)
            {
                SET_OSD_STATE(_MAIN_IMAGE_PROPERTIES);
                OsdDisplayItemDraw(_ICON_1_1, _ITEM_UNSELECT, _MAIN_IMAGE_POSITION);
                OsdDisplayItemDraw(_ICON_1_2, _ITEM_UNSELECT, _MAIN_IMAGE_SETUP);
                OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS,  _MAIN_IMAGE_PROPERTIES);
                OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_OPTIONS);
                OsdDisplayItemDraw(_ICON_1_5, _ITEM_UNSELECT, _MAIN_BRI_CON_DCR);
            }
            else
            {
                SET_OSD_STATE(_MAIN_IMAGE_POSITION);
                OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_OPTIONS);
                OsdDisplayItemDraw(_ICON_1_2, _ITEM_UNSELECT, _MAIN_BRI_CON_DCR);
                OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS,  _MAIN_IMAGE_POSITION);
                OsdDisplayItemDraw(_ICON_1_4, _ITEM_SELECT, _MAIN_IMAGE_SETUP);
                OsdDisplayItemDraw(_ICON_1_5, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
            }
        }
        else
        {
            SET_OSD_STATE(_MAIN_BRI_CON_DCR);
#if((_INPUT_PORT_MAX <= 0x01) &&(_OD_OSD_SUPPORT == _OFF) && (_ASPECT_RATIO_SUPPORT == _ON))
            OsdDisplayItemDraw(_ICON_1_1, (((GET_OSD_DCR_STATUS() == _ON)&&(UserCheckAspectRatioFunction() == _FALSE)) ? (_ITEM_UNSELECT) : (_ITEM_SELECT)), _MAIN_IMAGE_PROPERTIES);
#else
			OsdDisplayItemDraw(_ICON_1_1, _ITEM_SELECT, _MAIN_IMAGE_PROPERTIES);
#endif
            OsdDisplayItemDraw(_ICON_1_2, _ITEM_SELECT, _MAIN_OPTIONS);
            OsdDisplayItemDraw(_ICON_1_3, _ITEM_FOCUS,  _MAIN_BRI_CON_DCR);
            OsdDisplayItemDraw(_ICON_1_4, ((SysSourceGetInputPort() != _A0_INPUT_PORT) ? (_ITEM_UNSELECT) : (_ITEM_SELECT)), _MAIN_IMAGE_POSITION);
            OsdDisplayItemDraw(_ICON_1_5, ((SysSourceGetInputPort() != _A0_INPUT_PORT) ? (_ITEM_UNSELECT) : (_ITEM_SELECT)), _MAIN_IMAGE_SETUP);
        }
    }    

#if 0
    if(SysSourceGetSourceType() != _SOURCE_VGA)
    {
        OsdFunc1bitColor(ROW(_MAINICON_ROW_START), COL(_MAINICON_2_COL_START), WIDTH(7), HEIGHT(4), FGCOLOR(_CP_BLACK), BGCOLOR(_CP_BLANK));
        OsdFunc1bitColor(ROW(_MAINICON_ROW_START), COL(_MAINICON_3_COL_START), WIDTH(7), HEIGHT(4), FGCOLOR(_CP_BLACK), BGCOLOR(_CP_BLANK));
    }
    OsdFuncSet2BitIconOffset(_2BIT_OFFSET);    
    OsdFontLoadFont(_FONT1_GLOBAL);
#endif


    //==== Window=======
//    OsdDisplayDrawWindow(_WIN_0,_WIN_0_X_START,_WIN_0_Y_START,_WIN_0_X_END,_WIN_0_Y_END,_CP_MENU_BG);

    //==== Description ======
    OsdDisplayMainMenuDescription(GET_OSD_STATE());

    //==== Button ======
    OsdFunc1bitByte0(ROW(17), COL(0), WIDTH(_OSD_MAP0_Width), HEIGHT(3),_1BIT_FONT_256_511_WIDTH_12);
    OsdDisplayDispButton(_KEY_INFO_ALL);       //顯示提示OSD Button ICON(最後一列)

    OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());

    OsdFuncEnableOsd();
}

#if(_INPUT_PORT_MAX >= 0x01)
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE OsdDisplayJudgeSourceType(void)
{
    BYTE ucTemp = 0;

    switch(SysSourceGetInputPort())
    {
        case _A0_INPUT_PORT:
            ucTemp = _OSD_SOURCE_PORT_VGA;
            break;
    
        case _D0_INPUT_PORT:
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
                ucTemp = _OSD_SOURCE_PORT_DVI;
#elif(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
                ucTemp = _OSD_SOURCE_PORT_HDMI;
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                ucTemp = _OSD_SOURCE_PORT_DP;
#endif
            break;
    
        case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
                ucTemp = _OSD_SOURCE_PORT_DVI;
#elif(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
                ucTemp = _OSD_SOURCE_PORT_HDMI;
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
                ucTemp = _OSD_SOURCE_PORT_DP;
#endif
            break; 
    
        default:
            break;
    }

    return(ucTemp);
}
#endif

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayTimingAndInputSource(void)
{
#if 0   //alex.huang 20120120
    OsdDisplayOsdMessage(_INPUT_SIGNAL_MSG);
#endif
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayNoSupportProc(void)
{
    OsdDisplayOsdMessage(_MSG_OOR);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
/*
void OsdDisplayFailSafeProc(void)
{
#if 0   //alex.huang 20120120
    OsdDisplayOsdMessage(_FAIL_SAFE_MODE_MSG);
#endif
}
*/
#if 0
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayNoSignalProc(void)
{
    OsdDisplayOsdMessage(_NOSIGNAL_MSG);
}
#endif

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayNoCableProc(void)
{
    OsdDisplayOsdMessage(_MSG_NOCABLE);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayWakeUpShowSource()
{
//    OsdDispInputSourceHotKeyPage();
    SET_OSD_DO_WORK_MENU_STATUS(_TRUE);
    SET_KEYMESSAGE(_NONE_KEY_MESSAGE);

    // Activate Power Saving Event
    ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
}


//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayOSDLockProc(void)
{
    SET_Key_Relax_FLAG();
    OsdDisplayDisableOsd();    
    OsdDisplayOsdMessage(_MSG_LOCK_UNLOCK);        
}


//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayOSDDDCCIONOFFProc(void)
{
    SET_Key_Relax_FLAG();
    OsdDisplayDisableOsd();                 
    OsdDisplayOsdMessage(_MSG_DDCCI_ON_OFF);                       
}

#if(_AUTO_POWER_DOWN == _ON)
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayOSDAutoPowerDown(void)
{
    CLR_Key_Relax_FLAG();
    OsdDisplayDisableOsd();                 
    OsdDisplayOsdMessage(_MSG_AUTO_POWER_DOWN);   
}
#endif

#if(_VGA_SUPPORT == _ON)    
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayAutoProc(void)
{
    //OsdDisplayDisableOsd();    
    OsdDisplayOsdMessage(_MSG_AUTO);
    UserCommonAutoConfig();
#if 1//lorimiao 20141104 
	SET_VGA_MODE_ADJUST_H_POSITION(50);
	SET_VGA_MODE_ADJUST_V_POSITION(50);
#endif

    //If the monitor is all black, the menu will wait for 1 seconds to disappear
    if(g_ucAutoConfigStatus & _AUTO_CONFIG_MEASURE_ERROR)
    {
        ScalerTimerDelayXms(1000);
    }
    OsdDisplayDisableOsd();
    //ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_OSD_DISABLE_AUTO_ADJUST_MSG);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayAutoBalanceProc(void)
{
    OsdDisplayDisableOsd();    
//    OsdDisplayOsdMessage(_AUTO_COLOR_MSG);
    
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
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
#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))
        else
        {
            // Perform auto-color for YPbPr
            if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_YPBPR) == _AUTO_SUCCESS)
            {
                ScalerAutoGetAutoColorResult(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);
            }
            else
            {
                UserCommonNVRamRestoreADCSetting();
            }
        }
#endif
    }
    
    OsdDisplayDisableOsd();
    SET_KEYMESSAGE(_HOLD_KEY_MESSAGE);        
}
#endif // End of #if(_VGA_SUPPORT == _ON) 

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE OsdDispJudgeSourceType(void)
{
    BYTE ucTemp = 0;

    switch(SysSourceGetInputPort())
    {
        case _A0_INPUT_PORT:
            ucTemp = _OSD_SOURCE_PORT_VGA;
            break;
    
        case _D0_INPUT_PORT:
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
                ucTemp = _OSD_SOURCE_PORT_DVI;
#elif(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
                ucTemp = _OSD_SOURCE_PORT_HDMI;
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                ucTemp = _OSD_SOURCE_PORT_DP;
#endif
            break;
    
        case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
                ucTemp = _OSD_SOURCE_PORT_DVI;
#elif(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
                ucTemp = _OSD_SOURCE_PORT_HDMI;
#elif((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT))
                ucTemp = _OSD_SOURCE_PORT_DP;
#endif
            break;
       
        default:
            break;
    }

    return(ucTemp);
}

//--------------------------------------------------
// Description  : Logo showing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDisplayShowLogo(void)
{
    BYTE ucStep = 0;

    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);

#if 1   //alex.huang 20140909

#if (_FACTORY_MODE_OWNER == _OWNER_TPV)//DFM
	if(TPVDFMLogoOnCheck()==_TRUE)
#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
	if((!GET_FACTORY_MODE()) && (GET_FACTORY_LOGO_ON_OFF()))
#elif(_FACTORY_MODE_OWNER == _OWNER_WISTRON)            
    if (!GET_FACTORY_MODE() && !GET_ATE_COMMAND_STATUS())
#endif
    {
#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)
        OsdDisplayDisableOsd();
        OsdFuncOsdBlending(_BLENDING_TYPE1);
        OsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());    

        OsdFuncApplyMap(_OSD_LOGO_MAP);

        //載入1Bit Bitmap
        OsdFontLoadFontBank2(_FONTX_LOGO);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_LOGO);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_LOGO);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX2, _PALETTE_LOGO);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX3, _PALETTE_LOGO);

        //OSD顯示位置    
#if((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))
        OsdFuncSetPosition((7 + ((DWORD)((_PANEL_DH_WIDTH-(WORD)g_ucOsdWidth*12)/4)*25)/1000), (2 + ((DWORD)(_PANEL_DV_HEIGHT-16-(WORD)g_ucOsdHeight*18)*25)/1000)); //(25,25)
    #if(_EPA_LOGO == _ON)
        OsdDisplayDrawWindow(_WIN_0,1278,482,(1278 + 116),(482 + 116),_CP_LOGO_IBM_WHITE);
    #endif
#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))
        OsdFuncSetPosition((7 + ((DWORD)((_PANEL_DH_WIDTH-(WORD)g_ucOsdWidth*12)/4)*50)/1000), (2 + ((DWORD)(_PANEL_DV_HEIGHT-16-(WORD)g_ucOsdHeight*18)*200)/1000)); //(50,200)
    #if(_EPA_LOGO == _ON)
        OsdDisplayDrawWindow(_WIN_0,1335,500,(1335 + 116),(500 + 116),_CP_LOGO_IBM_WHITE);
    #endif
#elif((_PANEL_DH_WIDTH == 1280) && (_PANEL_DV_HEIGHT == 1024)) 
        OsdFuncSetPosition((7 + ((DWORD)((_PANEL_DH_WIDTH-(WORD)g_ucOsdWidth*12)/4)*10)/1000), (2 + ((DWORD)(_PANEL_DV_HEIGHT-16-(WORD)g_ucOsdHeight*18)*950)/1000)); //(10,400)
    #if(_EPA_LOGO == _ON)
        OsdDisplayDrawWindow(_WIN_0,1159,428,(1159 + 116),(428 + 116),_CP_LOGO_IBM_WHITE);
    #endif
#elif((_PANEL_DH_WIDTH == 1680) && (_PANEL_DV_HEIGHT == 1050))
       // OsdFuncSetPosition((7 + ((DWORD)((_PANEL_DH_WIDTH-(WORD)g_ucOsdWidth*12)/4)*35)/1000), (2 + ((DWORD)(_PANEL_DV_HEIGHT-16-(WORD)g_ucOsdHeight*18)*400)/1000)); //(35,400)
        OsdFuncSetPosition(21,400);//ym20141009 . 
    #if(_EPA_LOGO == _ON)
        OsdDisplayDrawWindow(_WIN_0,1515,536,(1515 + 116),(536 + 116),_CP_LOGO_IBM_WHITE);
    #endif
#elif((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
        OsdFuncSetPosition((7 + ((DWORD)((_PANEL_DH_WIDTH-(WORD)g_ucOsdWidth*12)/4)*58)/1000),(2 + ((DWORD)(_PANEL_DV_HEIGHT-16-(WORD)g_ucOsdHeight*18)*864)/1000)); //(58,864)
    #if(_EPA_LOGO == _ON)
		#if 1// //lorimiao 20140927
		OsdDisplayDrawWindow(_WIN_0,1650,607,(1650 + 117),(607 + 117),_CP_LOGO_IBM_WHITE);
		#else
        OsdDisplayDrawWindow(_WIN_0,1651,608,(1651 + 116),(608 + 116),_CP_LOGO_IBM_WHITE);
		#endif
    #endif
#endif

#elif(_LOGO_TYPE == _LENOVO)

        OsdDisplayDisableOsd();
        OsdFuncOsdBlending(_BLENDING_TYPE1);
        OsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());    

        OsdFuncApplyMap(_OSD_LOGO_MAP);

        //載入1Bit Bitmap    
        OsdFontLoadFontBank2(_FONTX_LOGO);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_LOGO);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_LOGO);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX2, _PALETTE_LOGO);
        OsdTableFuncSetColorPalette(_PALETTE_INDEX3, _PALETTE_LOGO);

    #if(_EPA_LOGO == _ON)
        #if((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))
        OsdFuncSetPosition((6 + ((DWORD)((_PANEL_DH_WIDTH-(WORD)g_ucOsdWidth*12)/4)*100)/1000),(2 + ((DWORD)(_PANEL_DV_HEIGHT-16-(WORD)g_ucOsdHeight*18)*(1000-50))/1000));
        #else
        OsdFuncSetPosition((7 + ((DWORD)((_PANEL_DH_WIDTH-(WORD)g_ucOsdWidth*12)/4)*100)/1000),(2 + ((DWORD)(_PANEL_DV_HEIGHT-16-(WORD)g_ucOsdHeight*18)*(1000-50))/1000));
        #endif
    #else
        #if((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))
		OsdFuncSetPosition((6 + ((DWORD)((_PANEL_DH_WIDTH-(WORD)g_ucOsdWidth*12)/4)*130)/1000),(2 + ((DWORD)(_PANEL_DV_HEIGHT-16-(WORD)g_ucOsdHeight*18)*(1000-270))/1000));
        #else
		OsdFuncSetPosition((7 + ((DWORD)((_PANEL_DH_WIDTH-(WORD)g_ucOsdWidth*12)/4)*130)/1000),(2 + ((DWORD)(_PANEL_DV_HEIGHT-16-(WORD)g_ucOsdHeight*18)*(1000-270))/1000));
        #endif
    #endif

#if(_EPA_LOGO == _ON)
		OsdDisplayDrawWindow(_WIN_0,1650,607,(1650 + 117),(607 + 117),_CP_LOGO_LENOVO_WHITE);
#endif

        ScalerDDomainBackgroundEnable(_ENABLE);
        ScalerDDomainBackgroundSetColor(255, 255, 255);
		
#elif((_LOGO_TYPE == _LENOVO_THINKVISION_EPA) || (_LOGO_TYPE == _LENOVO_THINKVISION) ||(_LOGO_TYPE == _LENOVO_2015_EPA) ||(_LOGO_TYPE == _LENOVO_2015))

		OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_LOGO);
		OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_LOGO);
		OsdTableFuncSetColorPalette(_PALETTE_INDEX2, _PALETTE_LOGO);
		OsdTableFuncSetColorPalette(_PALETTE_INDEX3, _PALETTE_LOGO);
		

		OsdDisplayDisableOsd();
		//OsdFuncOsdBlending(_BLENDING_TYPE1);
		OsdFuncOsdTransparency(0);	  

		OsdFontLoadFontBank2(_FONTX_LOGO);

		ScalerOsdPosition(_OSD_POSITION_GLOBAL_A, 0, 0);


#endif
    }

#else
    OsdDisplayDisableOsd();
    OsdFuncOsdBlending(_BLENDING_TYPE1);
    OsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());    

//OsdDispMainMenu();

    OsdFuncApplyMap(_OSD_MAP2);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_LOGO);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_LOGO);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX2, _PALETTE_LOGO);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX3, _PALETTE_LOGO);
    OsdFuncSet2BitIconOffset(_LOGO_2Bit_START);

    OsdFontLoadFontBank2(_FONTX_LOGO);

    OsdDisplaySetPosition(_LOGO_OSD, 50, 50);
#endif
	UserAdjustBacklightPercent(100);
	UserInterfacePanelPowerAction(_BACKLIGHT_ON);
    OsdFuncEnableOsd();
    SET_OSD_LOGO_ON(_ON);  
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayOsdMessage(BYTE ucMessage)
{
	if(ucMessage != _MSG_FLYING)
	{
		OsdDisplayDisableOsd();

        //==== OSD map setting=======
        OsdFuncOsdBlending(_BLENDING_TYPE1);    
        OsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());        
        OsdFuncApplyMap(_OSD_MAP1);

        //==== Load font & icon & color palette=======   
        OsdFontLoadFont(_MESSAGE_FONT_GLOBAL);       
        OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_0);
        
        //==== Window=======
        OsdDisplayDrawWindow(_WIN_1,_X_MSG_START,_Y_MSG_START,_X_MSG_END,_Y_MSG_END,_CP_ITEM_FOCUS_BG);

        //==== CLR Message OSD =======   
        OsdFunc1bitChar(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight), CHAR(___));    
        //OsdFunc1bitColor(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));                   
	}		
    
    switch(ucMessage)
	{
		case _MSG_AUTO:
			OsdFuncPutStringPropCenter(ROW(1), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_AUTOMATIC, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);
			OsdFuncPutStringPropCenter(ROW(3), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_PLEASE_WAIT, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);                   
			break;
			
		case _MSG_LOCK_UNLOCK:					
            SET_OSD_STATE(_HOTKEY_MESSAGE_MENU);          
            if(GET_OSD_LOCK_STATUS()==_ON)
            {
                OsdFuncPutStringPropCenter(ROW(2), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_OSD_LOCKED_STR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);
            }
            else
            {
                OsdFuncPutStringPropCenter(ROW(2), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_OSD_UNLOCKED_STR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);
            }                                                
			break;

		
		case _MSG_DDCCI_ON_OFF:
            SET_OSD_STATE(_HOTKEY_MESSAGE_MENU);   
            if(GET_OSD_DDCCI_STATUS()==_TRUE)
            {
                OsdFuncPutStringPropCenter(ROW(2), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_DDCCI_ENABLE_STR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);
            }   
            else
            {
                OsdFuncPutStringPropCenter(ROW(2), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_DDCCI_DISABLE_STR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);
            }               			
            OsdDisplaySetPosition(_MESSAGE_OSD, _OSD_H_POS_CENTER, _OSD_V_POS_CENTER);
			break;		
			
		case _MSG_SLEEP:	
			OsdFuncPutStringPropCenter(ROW(2), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_POWER_SAVING_STR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);
            OsdDisplaySetPosition(_MESSAGE_OSD, _OSD_H_POS_CENTER, _OSD_V_POS_CENTER);
			break;
						
		case _MSG_NOCABLE:
            if(GET_OSD_LANGUAGE() == _FRENCH)
            {
			    OsdFuncPutStringPropCenter(ROW(2), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_NO_CONNECTION_STR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);				
			}    
            else   
            {
			    OsdFuncPutStringPropCenter(ROW(1), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_NO_CONNECTION_STR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);				
			    OsdFuncPutStringPropCenter(ROW(3), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_CHECK_CABLE_STR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);						
            }
            OsdDisplaySetPosition(_MESSAGE_OSD, _OSD_H_POS_CENTER, _OSD_V_POS_CENTER);
			break;
			
		case _MSG_OOR:
			OsdFuncPutStringPropCenter(ROW(1), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_INPUT_NOT_SUPPORT_STR_0, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);		
            OsdFuncPutStringPropCenter(ROW(3), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_INPUT_NOT_SUPPORT_STR_1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);
            OsdDisplaySetPosition(_MESSAGE_OSD, _OSD_H_POS_CENTER, _OSD_V_POS_CENTER);
			break;

#if(_AUTO_POWER_DOWN == _ON)
        case _MSG_AUTO_POWER_DOWN:
            OsdFuncPutStringPropCenter(ROW(2), COL(0), WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_AUTO_POWER_DOWN_STR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_BG), _1BIT_FONT_0_255_WIDTH_12);
            break;
#endif

		default:
			break;
	}

    //lorimiao 20130731 for MSG OSD Move
	if((ucMessage == _MSG_SLEEP) ||(ucMessage == _MSG_NOCABLE) || (ucMessage == _MSG_OOR))
		OsdDisplaySetPosition(_MESSAGE_OSD, Xpos, Ypos); 
	else
	    OsdDisplaySetPosition(_MESSAGE_OSD, _OSD_H_POS_CENTER, _OSD_V_POS_CENTER);  //OSD置中


	ScalerOsdEnableOsd();
}


//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayWakeUpSwitchDdcciPort(void)
{
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GO_TO_POWER_SAVING);

    SET_OSD_SHOWING_SWITCH_DDCCI_PORT(_TRUE);
    if(GET_OSD_DDCCI_STATUS() == _OFF)
    {
        SET_OSD_DDCCI_STATUS(_ON);
    }
    else
    {
        SET_OSD_DDCCI_STATUS(_OFF);                
    }    

    OsdDisplayOsdMessage(_MSG_DDCCI_ON_OFF);
    ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());    
    RTDNVRamSaveOSDData();

    // Activate Power Saving Event
    ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayPowerSavingProc(void)
{
    OsdDisplayOsdMessage(_MSG_SLEEP);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplaySetPosition(BYTE ucType, WORD usHPos, WORD usVPos)
{
    usVPos = _OSD_V_POS_MAX - usVPos;

	if(GET_OSD_ROTATE_STATUS() == _TRUE)
	{
		if(ucType == _MAIN_OSD)//Main page	   
		{
			usHPos = 8 + ((DWORD)((_PANEL_DH_WIDTH-_MAIN_WINDOW_SIZE_Y)/4)*usHPos)/_OSD_H_POS_MAX;
			usVPos = 6 + ((DWORD)(_PANEL_DV_HEIGHT-_MAIN_WINDOW_SIZE_X)*usVPos)/_OSD_V_POS_MAX;	 
		}
		else if(ucType == _INPUT_SOURCE_OSD)//Hotkey page	 
		{
			usHPos = 8 + ((DWORD)((_PANEL_DH_WIDTH-_INPUT_SOURCE_SIZE_Y)/4)*usHPos)/_OSD_H_POS_MAX;
			usVPos = 6 + ((DWORD)(_PANEL_DV_HEIGHT-_INPUT_SOURCE_SIZE_X)*usVPos)/_OSD_V_POS_MAX;    
		}
		else if(ucType == _LOGO_OSD)//Logo
		{
			usHPos = 8 + ((DWORD)((_PANEL_DH_WIDTH-_LOGO_WINDOW_SIZE_Y)/4)*usHPos)/_OSD_H_POS_MAX;
			usVPos = 6 + ((DWORD)(_PANEL_DV_HEIGHT-_LOGO_WINDOW_SIZE_X)*usVPos)/_OSD_V_POS_MAX;	 
		}				 
		else if(ucType == _MESSAGE_OSD)//Message OSD
		{
			usHPos = 8 + ((DWORD)((_PANEL_DH_WIDTH-_MESSAGE_WINDOW_SIZE_Y)/4)*usHPos)/_OSD_H_POS_MAX;
			usVPos = 6 + ((DWORD)(_PANEL_DV_HEIGHT-_MESSAGE_WINDOW_SIZE_X)*usVPos)/_OSD_V_POS_MAX;	
		}				   
	}
	else
	{
		if(ucType == _MAIN_OSD)//Main page
		{
#if(_SCALER_TYPE == _RL6230_SERIES)//Ada.chen 20150519 modify OSD don't to edge issue 
            usHPos = 5 + ((DWORD)((_PANEL_DH_WIDTH - (_OSD_MAP0_Width * 12))/4)*usHPos)/_OSD_H_POS_MAX;
#else
			usHPos = 7 + ((DWORD)((_PANEL_DH_WIDTH - (_OSD_MAP0_Width * 12))/4)*usHPos)/_OSD_H_POS_MAX;
#endif
            usVPos = 4 + ((DWORD)(_PANEL_DV_HEIGHT - (_OSD_MAP0_Height * 18))*usVPos)/_OSD_V_POS_MAX;
		}
		else if(ucType == _INPUT_SOURCE_OSD)//Hotkey page	 
		{
			usHPos = 8 + ((DWORD)((_PANEL_DH_WIDTH-_INPUT_SOURCE_SIZE_X)/4)*usHPos)/_OSD_H_POS_MAX;
			usVPos = 6 + ((DWORD)(_PANEL_DV_HEIGHT-_INPUT_SOURCE_SIZE_Y)*usVPos)/_OSD_V_POS_MAX;    
		}
		else if(ucType == _LOGO_OSD)//Logo
		{
			usHPos = 8 + ((DWORD)((_PANEL_DH_WIDTH-_LOGO_WINDOW_SIZE_X)/4)*usHPos)/_OSD_H_POS_MAX;
			usVPos = 6 + ((DWORD)(_PANEL_DV_HEIGHT-_LOGO_WINDOW_SIZE_Y)*usVPos)/_OSD_V_POS_MAX;	 
		}					   
		else if(ucType == _MESSAGE_OSD)//Message OSD
		{
#if((_PANEL_DH_WIDTH == 1680) && (_PANEL_DV_HEIGHT == 1050))
			usHPos = 3 + ((DWORD)((_PANEL_DH_WIDTH-_MESSAGE_WINDOW_SIZE_X-4)/4)*usHPos)/_OSD_H_POS_MAX;
#else
			usHPos = 5 + ((DWORD)((_PANEL_DH_WIDTH-_MESSAGE_WINDOW_SIZE_X-4)/4)*usHPos)/_OSD_H_POS_MAX;
#endif
			usVPos = 0 + ((DWORD)(_PANEL_DV_HEIGHT-_MESSAGE_WINDOW_SIZE_Y-4)*usVPos)/_OSD_V_POS_MAX;	
		}		 
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
		else if(ucType == _LOW_BLUE_LIGHT_OSD)//Hotkey page	 
		{
			usHPos = 8 + ((DWORD)((_PANEL_DH_WIDTH-_LOW_BLUE_LIGHT_SIZE_X)/4)*usHPos)/_OSD_H_POS_MAX;
			usVPos = 6 + ((DWORD)(_PANEL_DV_HEIGHT-_LOW_BLUE_LIGHT_SIZE_Y)*usVPos)/_OSD_V_POS_MAX;    
		}
#endif        
	}

	OsdFuncSetPosition(usHPos,usVPos);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayDisableOsd(void)
{
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);        
	SET_OSD_STATE(_MENU_NONE);	  
	OsdFuncDisableOsd();
	OsdFuncCloseWindow(_WIN_ALL);
	SET_OSD_SHOWING_SWITCH_DDCCI_PORT(_FALSE);
	SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
	ucFactoryOsdState=MENU_FACTORY_START;
    
	if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)	  
	{
		SET_OSD_DO_WORK_MENU_STATUS(_FALSE);
	}			
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
WORD OsdDisplayDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle)
{
	switch(GET_KEYMESSAGE())
	{
		case _RIGHT_KEY_MESSAGE:
			if (ucValue >= ucMax)
			{
				if(bCycle == _ON)
				{
					return ucMin;
				}
				else
				{
					return ucMax;
				}
			}
			else
			{
				ucValue++;				
			}
			break;
		
		case _LEFT_KEY_MESSAGE:
			if (ucValue <= ucMin)
			{
				if(bCycle == _ON)
				{
					return ucMax;
				}
				else
				{
					return ucMin;
				}
			}
			else
			{
				ucValue--;
			}
			break;
		
		default:
			break;
	}

    return ucValue;
}

//--------------------------------------------------
// Description  : 
// Input Value  :
// ucBorderPixel        bit5~3 shadow/border width or 3D button thickness in pixel unit:0~7 1~8 pixel.
//                      bit2~0 shadow/border height  in line unit:0~7 1~8 line.
//
// ucBorderColor        bit7~4 shadow/border/3D button left-top/botton border color
//                      bit3~0 shadow/border/3D button right-botton/top border color
//
// ucWinFuncControl:    bit7: blend  0:disable, 1:enable
//                      bit6: gradient 0:disable, 1:enable
//                      bit5: gradient direction  0:H, 1:V
//                      bit4: shadow/border/3D button 0:disable, 1:enable
//                      bit3~1:0~3: shadow type 1~4,  4~5: 3D button1~2, 6:reserved, 7:border.
//
// ucGradientCon0:      bit7: R gradient polarity 0:decrease, 1:increase
//                      bit6: G gradient polarity 0:decrease, 1:increase
//                      bit5: B gradient polarity 0:decrease, 1:increase
//                      bit3~4: gradient level 0~3
//                      bit2: R gradient 0:disable, 1:enable
//                      bit1: G gradient 0:disable, 1:enable
//                      bit0: B gradient 0:disable, 1:enable
//
// ucGradientCon0:      bit7~5 0: 8 level per gradient
//                      1~7: 1~7 level per gradient
// Output Value :       None
//--------------------------------------------------
void OsdDisplayDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor)
{
    BYTE ucIndex = 0;

#if(_OSD_ROTATE_FUNCTION == _ON)
    WORD xdata usTemp = 0;
    WORD xdata usTemp1 = 0;

    if(GET_OSD_ROTATE_STATUS() == _ON)
    {
        usTemp  = usXEnd - usXStart;
        usTemp1 = usYEnd - usYStart;

        usXStart = 10 + usYStart;
        
        usXEnd = usXStart + usTemp1;
        usYEnd = usYStart + usTemp;
    }
#endif

#if 1   //alex.huang 20130731 for fine tuning OSD H position 2 pixel
    usXStart += _OSD_POSITION_FONT_A_H_DELAY_;
    usXEnd += _OSD_POSITION_FONT_A_H_DELAY_;
#endif

    OsdTableFuncDrawWindow(ucWindow, usXStart, usYStart, usXEnd, usYEnd, ucColor);
}

/*----------------------------------------*/
/*    顯示提示OSD Button ICON(最後一列)   */
/*----------------------------------------*/
void OsdDisplayDispButton(BYTE ucState)
{
#if(_NAVIGATE_ICON_POSITION_CONTROL == _ON)	 
    BYTE i,BlankCol;			 
#endif
	    
  	switch(ucState)
  	{
#if(_NAVIGATE_ICON_POSITION_CONTROL == _ON)
		case _KEY_INFO_ALL: 	
			OsdFunc1bitColor(ROW(_BUTTON_ICON_ROW), COL(_NAVIGATE_ICON_EXIT_COL_POSITION), WIDTH(30), HEIGHT(2), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_MENU_BG));
            
            //ICON前一個插入縮排
            OsdFuncBlank(ROW(_BUTTON_ICON_ROW), COL(_NAVIGATE_ICON_EXIT_COL_POSITION-1), PIXEL(_ICON_BLANK1_PIXEL) , HEIGHT(2) , BGCOLOR(_CP_MENU_BG));
            OsdFuncBlank(ROW(_BUTTON_ICON_ROW), COL(_NAVIGATE_ICON_LEFT_COL_POSITION-1), PIXEL(_ICON_BLANK2_PIXEL) , HEIGHT(2) , BGCOLOR(_CP_MENU_BG));
            OsdFuncBlank(ROW(_BUTTON_ICON_ROW), COL(_NAVIGATE_ICON_RIGHT_COL_POSITION-1), PIXEL(_ICON_BLANK3_PIXEL) , HEIGHT(2) , BGCOLOR(_CP_MENU_BG));
            OsdFuncBlank(ROW(_BUTTON_ICON_ROW), COL(_NAVIGATE_ICON_ENTER_COL_POSITION-1), PIXEL(_ICON_BLANK4_PIXEL) , HEIGHT(2) , BGCOLOR(_CP_MENU_BG));
            OsdFuncBlank(ROW(_BUTTON_ICON_ROW), COL(_NAVIGATE_ICON_POWER_COL_POSITION-1), PIXEL(_ICON_BLANK5_PIXEL) , HEIGHT(2) , BGCOLOR(_CP_MENU_BG));

            //最後ICON後減掉Pixel
            BlankCol = (_ICON_BLANK1_PIXEL + _ICON_BLANK2_PIXEL + _ICON_BLANK3_PIXEL + _ICON_BLANK4_PIXEL + _ICON_BLANK5_PIXEL-12*5)/8;                      
            for(i=0 ; i<BlankCol ; i++) 
            {
              OsdFuncBlank(ROW(_BUTTON_ICON_ROW), COL(_AFTER_NAVIGATE_ICON_POWER_COL_POSITION+i), PIXEL(4) , HEIGHT(2) , BGCOLOR(_CP_MENU_BG));                            
            }  
            if((_ICON_BLANK1_PIXEL + _ICON_BLANK2_PIXEL + _ICON_BLANK3_PIXEL + _ICON_BLANK4_PIXEL + _ICON_BLANK5_PIXEL-12*5)%8)
            {
                 OsdFuncBlank(ROW(_BUTTON_ICON_ROW), COL(_AFTER_NAVIGATE_ICON_POWER_COL_POSITION+i), PIXEL(12-(_ICON_BLANK1_PIXEL + _ICON_BLANK2_PIXEL + _ICON_BLANK3_PIXEL + _ICON_BLANK4_PIXEL + _ICON_BLANK5_PIXEL-12*5)%8), HEIGHT(2) , BGCOLOR(_CP_MENU_BG));
            }             
            
			OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(_NAVIGATE_ICON_EXIT_COL_POSITION),tOSD_BUTTON_EXIT_ICON);
			OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(_NAVIGATE_ICON_LEFT_COL_POSITION),tOSD_BUTTON_LEFT_ICON);
			OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(_NAVIGATE_ICON_RIGHT_COL_POSITION),tOSD_BUTTON_RIGHT_ICON);
			OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(_NAVIGATE_ICON_ENTER_COL_POSITION),tOSD_BUTTON_OK_ICON);
			OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(_NAVIGATE_ICON_POWER_COL_POSITION),tOSD_BUTTON_POWER_ICON);   
            /*
            //TEXT前一個插入縮排
            OsdFuncBlank(ROW(_BUTTON_ICON_ROW+2), COL(_NAVIGATE_TEXT_EXIT_COL_POSITION), PIXEL(_TEXT_BLANK1_PIXEL) , HEIGHT(1) , BGCOLOR(_CP_MENU_BG));
            OsdFuncBlank(ROW(_BUTTON_ICON_ROW+2), COL(_NAVIGATE_TEXT_ENTER_COL_POSITION), PIXEL(_TEXT_BLANK2_PIXEL) , HEIGHT(1) , BGCOLOR(_CP_MENU_BG));

            //計算插入的Pixel數
            BlankCol = (_TEXT_BLANK1_PIXEL + _TEXT_BLANK2_PIXEL -12*2)/8;                     
            //最後一個ICON減去補的Pixel            
            for(i=0 ; i<BlankCol ; i++) //補一個字最小4Pixel 
            {
              OsdFuncBlank(ROW(_BUTTON_ICON_ROW + 2), COL(_AFTER_NAVIGATE_TEXT_ENTER_COL_POSITION+i), PIXEL(4) , HEIGHT(1) , BGCOLOR(_CP_MENU_BG));                         
            }            

            //超過字的多一個字
            if((_TEXT_BLANK1_PIXEL + _TEXT_BLANK2_PIXEL -12*2)%8)
            {
                 OsdFuncBlank(ROW(_BUTTON_ICON_ROW + 2), COL(_AFTER_NAVIGATE_TEXT_ENTER_COL_POSITION+i), PIXEL(12-(_TEXT_BLANK1_PIXEL + _TEXT_BLANK2_PIXEL -12*2)%8), HEIGHT(1) , BGCOLOR(_CP_MENU_BG));
            }       
            */              
            OsdFuncPutStringPropCenter(ROW(_BUTTON_ICON_ROW + 2), COL(_NAVIGATE_TEXT_EXIT_COL_POSITION), LENGTH(9), _PFONT_PAGE_ITEM_0, tOSD_sEXIT, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_0_255_WIDTH_12);
			OsdFuncPutStringPropCenter(ROW(_BUTTON_ICON_ROW + 2), COL(_NAVIGATE_TEXT_ENTER_COL_POSITION), LENGTH(7),_PFONT_PAGE_ITEM_1, tOSD_sOK, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_0_255_WIDTH_12);
		    break;

		case _KEY_INFO_EXIT: 
			OsdFunc1bitChar(ROW(_BUTTON_ICON_ROW + 2), COL(_NAVIGATE_TEXT_EXIT_COL_POSITION), WIDTH(9), HEIGHT(1), CHAR(___));
			OsdFuncPutStringPropCenter(ROW(_BUTTON_ICON_ROW + 2), COL(_NAVIGATE_TEXT_EXIT_COL_POSITION), LENGTH(9), _PFONT_PAGE_ITEM_0, tOSD_sEXIT, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_0_255_WIDTH_12);
			break;
			
		case _KEY_INFO_CANCEL:
			OsdFunc1bitChar(ROW(_BUTTON_ICON_ROW + 2), COL(_NAVIGATE_TEXT_EXIT_COL_POSITION), WIDTH(9), HEIGHT(1), CHAR(___));
			OsdFuncPutStringPropCenter(ROW(_BUTTON_ICON_ROW + 2), COL(_NAVIGATE_TEXT_EXIT_COL_POSITION), LENGTH(9), _PFONT_PAGE_ITEM_0, tOSD_sCANCEL, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_0_255_WIDTH_12);		 
			break;
		
		case _KEY_INFO_OK: 
			OsdFunc1bitChar(ROW(_BUTTON_ICON_ROW + 2), COL(_NAVIGATE_TEXT_ENTER_COL_POSITION), WIDTH(7), HEIGHT(1), CHAR(___));
			OsdFuncPutStringPropCenter(ROW(_BUTTON_ICON_ROW + 2), COL(_NAVIGATE_TEXT_ENTER_COL_POSITION), LENGTH(7),_PFONT_PAGE_ITEM_1, tOSD_sOK, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_0_255_WIDTH_12);
			break;
		
		default:
			break;
#else
        case _KEY_INFO_ALL:  	
            OsdFunc1bitColor(ROW(_BUTTON_ICON_ROW), COL(5), WIDTH(30), HEIGHT(2), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_MENU_BG));
            OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(5),tOSD_BUTTON_EXIT_ICON);
            OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(13),tOSD_BUTTON_LEFT_ICON);
            OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(21),tOSD_BUTTON_RIGHT_ICON);
            OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(29),tOSD_BUTTON_OK_ICON);
            OsdTableFuncLoadIcon(ROW(_BUTTON_ICON_ROW),COL(31),tOSD_BUTTON_POWER_ICON); 
            OsdFuncPutStringPropCenter(ROW(_BUTTON_ICON_ROW + 2), COL(28), LENGTH(5),_PFONT_PAGE_ITEM_1, tOSD_sOK, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_0_255_WIDTH_12);
            break;

        case _KEY_INFO_EXIT: 
            OsdFunc1bitChar(ROW(_BUTTON_ICON_ROW + 2), COL(2), WIDTH(9), HEIGHT(1), CHAR(___));
            OsdFuncPutStringPropCenter(ROW(_BUTTON_ICON_ROW + 2), COL(2), LENGTH(9), _PFONT_PAGE_ITEM_0, tOSD_sEXIT, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_0_255_WIDTH_12);
            break;
            
        case _KEY_INFO_CANCEL:
            OsdFunc1bitChar(ROW(_BUTTON_ICON_ROW + 2), COL(2), WIDTH(9), HEIGHT(1), CHAR(___));
            OsdFuncPutStringPropCenter(ROW(_BUTTON_ICON_ROW + 2), COL(2), LENGTH(9), _PFONT_PAGE_ITEM_0, tOSD_sCANCEL, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_0_255_WIDTH_12);        
            break;

        case _KEY_INFO_OK: 
            OsdFunc1bitChar(ROW(_BUTTON_ICON_ROW + 2), COL(28), WIDTH(5), HEIGHT(1), CHAR(___));
            OsdFuncPutStringPropCenter(ROW(_BUTTON_ICON_ROW + 2), COL(28), LENGTH(5),_PFONT_PAGE_ITEM_1, tOSD_sOK, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_0_255_WIDTH_12);
            break;

        default:
            break;
#endif
  	}    
}

/*----------------------------------------*/
/*          顯示Main Menu說明文字         */
/*----------------------------------------*/
void OsdDisplayMainMenuDescription(BYTE ucState)
{
   
    OsdFunc1bitChar(ROW(16), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(1), CHAR(___));

    switch(ucState)
    {
        case _MAIN_BRI_CON_DCR:
            OsdFuncPutStringProp(ROW(16), COL(1), _PFONT_PAGE_0, tOSD_sDESCRIPTION_BRI_CON_DCR, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_256_511_WIDTH_12);           
            break;
             
        case _MAIN_IMAGE_POSITION:
            OsdFuncPutStringProp(ROW(16), COL(1), _PFONT_PAGE_0, tOSD_sDESCRIPTION_IMAGE_POSITION, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_256_511_WIDTH_12);
            break;
        
        case _MAIN_IMAGE_SETUP:            
                OsdFuncPutStringProp(ROW(16), COL(1), _PFONT_PAGE_0, tOSD_sDESCRIPTION_IMAGE_SETUP, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_256_511_WIDTH_12);
            break;

        case _MAIN_IMAGE_PROPERTIES:
            OsdFuncPutStringProp(ROW(16), COL(1), _PFONT_PAGE_0, tOSD_sDESCRIPTION_IMAGE_PROPERTIES, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_256_511_WIDTH_12);
            break;

        case _MAIN_OPTIONS:
            OsdFuncPutStringProp(ROW(16), COL(1), _PFONT_PAGE_0, tOSD_sDESCRIPTION_OPTION, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_256_511_WIDTH_12);
            break;
            
        case _MAIN_FACTORY:
            OsdFuncPutStringProp(ROW(16), COL(1), _PFONT_PAGE_0, tOSD_sDESCRIPTION_FACTORY, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_MENU_BG), _1BIT_FONT_256_511_WIDTH_12);
            break;
        default:
            break;

    }

}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDispMessageFlying(void)
{
    if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
        return;

    if(Xpos >= 200)
        Xdirect = 0;

    if(Ypos >= 200)  
        Ydirect = 0;

    if(Xpos <= 0)
        Xdirect = 1;

    if(Ypos <= 0)
        Ydirect = 1;

    if(Xdirect == 0)
        Xpos--;
    else
        Xpos++;

    if(Ydirect == 0)
        Ypos = Ypos - 2;    
    else
        Ypos = Ypos + 2;    

    if((SysModeGetModeState() == _MODE_STATUS_ACTIVE)||(SysModeGetModeState() == _MODE_STATUS_NOSUPPORT))
    {	//jason.cheng 20141114_2 modify follow TPV richer request
        if(((ucLedFlashCount/2)%2) == 1)
        {
            UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
        }
        else
        {
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);                
        }	
		if(ucLedFlashCount >= 3)
		{
			ucLedFlashCount = 0;
		}
		else
		{
			ucLedFlashCount++;
		}	
    }

    OsdDisplaySetPosition(_MESSAGE_OSD, Xpos, Ypos);
	ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_FLYING);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------

#define _OSD_INPUT_2BIT_OFFSET                       6
#define _OSD_INPUTA_ADDRESS_ROWCOMMAND               0
#define _OSD_INPUTA_ADDRESS_CHARCOMMAND              4
#define _OSD_INPUT_FONT_BASE_ADDRESS                 36

#if(_INPUT_PORT_MAX >= 0x01)
void OsdDispInputInfo(void)
{
    OsdFuncOsdBlending(_BLENDING_TYPE1);
    OsdFuncOsdTransparency(GET_OSD_TRANSPARENCY_STATUS());   

//==== Load font & icon & color palette=======      //載入字型檔
    OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_INPUT);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_INPUT);

    ScalerOsd2BitFontOffset(_OSD_INPUT_2BIT_OFFSET);
    ScalerOsdSramBaseAddressSet(_OSD_A, _OSD_INPUTA_ADDRESS_ROWCOMMAND, _OSD_INPUTA_ADDRESS_CHARCOMMAND, _OSD_INPUT_FONT_BASE_ADDRESS);

    if(OsdDisplayJudgeSourceType() == _OSD_SOURCE_PORT_VGA)
    {
        OsdFontLoadFont(_FONT1_INPUT_OSD_VGA);
    }
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
    else if(OsdDisplayJudgeSourceType() == _OSD_SOURCE_PORT_DVI)
    {  
        // jimmy Temp
        OsdFontLoadFont(_FONT1_INPUT_OSD_DVI);//jason.cheng 20150207_1 modify DVI source icon
    }
#endif
#if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
    else if(OsdDisplayJudgeSourceType() == _OSD_SOURCE_PORT_HDMI)
    {
        OsdFontLoadFont(_FONT1_INPUT_OSD_HDMI);
    }
#endif
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)||(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    else if(OsdDisplayJudgeSourceType() == _OSD_SOURCE_PORT_DP)
    {
        OsdFontLoadFont(_FONT1_INPUT_OSD_DP);
    }
#endif

    //OsdDisplaySetPosition(_INPUT_SOURCE_OSD, 5, 195);
    OsdDisplaySetPosition(_INPUT_SOURCE_OSD, 1, 198);

	OsdFuncEnableOsd();
}
#endif

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayItemDraw(BYTE ucItem, BYTE ucItemStatus, BYTE ucOsdState)
{
    BYTE tmpItemBgColor = 0;
    BYTE tmpFontAddress = 0;

    if(ucItemStatus == _ITEM_UNSELECT)
    {
        tmpItemBgColor = _CP_ITEM_UNSEL_BG;
    }
    else if(ucItemStatus == _ITEM_SELECT)
    {
        tmpItemBgColor = _CP_ITEM_SEL_BG;
    }
    else if(ucItemStatus == _ITEM_FOCUS)
    {
        tmpItemBgColor = _CP_ITEM_FOCUS_BG;
    }

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing();

    switch(ucItem)
    {
        case _ITEM_5_2 :
            if((GET_OSD_STATE() == _BAR_POS_CUST_H) || (GET_OSD_STATE() == _BAR_POS_CUST_V))
            {
                OsdDisplayItemFrame(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2), BGCOLOR(tmpItemBgColor));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_5_2_START));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_5_2_START);
                
                if((ucItemStatus == _ITEM_UNSELECT) || (ucItemStatus == _ITEM_SELECT))
                {
                        // Clear Focus Frame
/////1
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(___));
/////2
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////3
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////4
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_T_));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 5), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 6), WIDTH(5), HEIGHT(1), CHAR(___));
/////5
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(___));
/////6
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_T_));
/////7
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(___));
/////8
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
                }
                else if(ucItemStatus == _ITEM_FOCUS)
                {
                        // Draw Focus Frame
/////1
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
/////2
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_L_));
/////3
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_R_));
/////4
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_TB_));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 5), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_2));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 6), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_B_));
/////5
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
/////6
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_4));
/////7
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
/////8
                        OsdFunc1bitColor(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_5_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RB_));
                }
            }
            break;
//====================================================================================================
        case _ITEM_4_1 :
            if(    (GET_OSD_STATE() == _SUB_POS_CUST_H) || (GET_OSD_STATE() == _SUB_POS_CUST_V)
              )
            {
                {   // Draw Item Frame
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LT_));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + 1), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LB_));
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 + 15), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RT_));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + 1), COL(_ITEM_COL_1 + 15), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RB_));
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 + 15), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1), WIDTH(15), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(tmpItemBgColor));
                }
                OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1), WIDTH(15), HEIGHT(2), CHAR(___));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(2), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_1_of_2));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_4_START_1_of_2);

                if((ucItemStatus == _ITEM_UNSELECT) || (ucItemStatus == _ITEM_SELECT))
                {
                    // Clear Focus Frame
/////1
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(___));
/////2
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////3                    
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////4
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
/////5
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(___));
/////6
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
/////7
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(___));
/////8
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
                }
                else if(ucItemStatus == _ITEM_FOCUS)
                {
                    // Draw Focus Frame
/////1
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
/////2
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_L_));
/////3
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_R_));
/////4
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(_Select_Frame_TB_));
/////5
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
/////6
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LTB_));
/////7
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
/////8
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RTB_));
                }
            }
            else
            {
                OsdDisplayItemFrame(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1), BGCOLOR(tmpItemBgColor));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_1_of_3));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_4_START_1_of_3);
            }
            break;

        case _ITEM_4_2 :
            if(    (GET_OSD_STATE() == _SUB_POS_CUST_H) || (GET_OSD_STATE() == _SUB_POS_CUST_V)
              )
            {
                {   // Draw Frame
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(19), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LT_));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + 1), COL(19), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LB_));
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(19), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(35), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RT_));
                    OsdFunc1bitChar(ROW(_ITEM_4_ROW + 1), COL(35), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RB_));
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(35), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(20), WIDTH(15), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(tmpItemBgColor));
                }
                OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(20), WIDTH(15), HEIGHT(2), CHAR(___));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(20), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_2_of_2));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_4_START_2_of_2);
            }
            else
            {
                OsdDisplayItemFrame(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2), BGCOLOR(tmpItemBgColor));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_2_of_3));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_4_START_2_of_3);

                if((ucItemStatus == _ITEM_UNSELECT) || (ucItemStatus == _ITEM_SELECT))
                {
                    if(((GET_OSD_STATE() >= _SUB_NEUTRAL) && (GET_OSD_STATE() <= _SUB_sRGB)) || ((GET_OSD_STATE() >= _SUB_CUSTOM_R) && (GET_OSD_STATE() <= _SUB_CUSTOM_B)) || ((GET_OSD_STATE() >= _SUB_REPEAT_OFF) && (GET_OSD_STATE() <= _SUB_REPEAT_SLOW)))
                    {
                        // Clear Focus Frame
/////1
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(___));
/////2
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////3
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////4
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_T_));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 5), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 6), WIDTH(5), HEIGHT(1), CHAR(___));
/////5
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(___));
/////6
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_T_));
/////7
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(___));
/////8
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
                    }
                    else
                    {
                        OsdDisplayClearFocusFrame(_ITEM_4_ROW);
                    }
                }
                else if(ucItemStatus == _ITEM_FOCUS)
                {
                    if(((GET_OSD_STATE() >= _SUB_NEUTRAL) && (GET_OSD_STATE() <= _SUB_sRGB)) || ((GET_OSD_STATE() >= _SUB_CUSTOM_R) && (GET_OSD_STATE() <= _SUB_CUSTOM_B)) || ((GET_OSD_STATE() >= _SUB_REPEAT_OFF) && (GET_OSD_STATE() <= _SUB_REPEAT_SLOW)))
                    {
                        // Draw Focus Frame
/////1
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
/////2
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_L_));
/////3
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_R_));
/////4
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_TB_));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 5), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_2));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 6), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_B_));
/////5
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
/////6
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_4));
/////7
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
/////8
                        OsdFunc1bitColor(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_4_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RB_));
                    }
                    else
                    {
                        OsdDisplayDrawFocusFrame(_ITEM_4_ROW);
                    }
                }
            }
            break;

        case _ITEM_4_3 :
            OsdDisplayItemFrame(ROW(_ITEM_4_ROW), COL(_ITEM_COL_3), BGCOLOR(tmpItemBgColor));
            OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_3), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_3_of_3));
            OsdFontLoadItem(ucOsdState, _FONT1_ITEM_4_START_3_of_3);
            break;
//====================================================================================================
        case _ITEM_3_1 :
            if(  
#if(_USER_DCR_FUNCTION == _ON)				
				(GET_OSD_STATE() == _SUB_DCR_ON) || (GET_OSD_STATE() == _SUB_DCR_OFF)
                || (GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
  #if(_INPUT_PORT_MAX == 0x02)              
                ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150707
  #endif

#else
				(GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
  #if(_INPUT_PORT_MAX == 0x02)			  
				||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150727
  #endif
#endif
                || (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON) || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)
#endif
#if(_ASPECT_RATIO_SUPPORT == _ON)              
                || (GET_OSD_STATE() == _SUB_SCALING_FULL_SCREEN) || (GET_OSD_STATE() == _SUB_SCALING_ORIGINAL_AR)
#endif

#if(_OD_OSD_SUPPORT == _ON)
#if(_OD_MULTI_SELECT == _OFF)
                || (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
#endif

#if (_DP_SUPPORT == _ON)
                || (GET_OSD_STATE() == _SUB_DP_SL_11) || (GET_OSD_STATE() == _SUB_DP_SL_12)
#endif
                || (GET_OSD_STATE() == _SUB_POS_DEFAULT) || (GET_OSD_STATE() == _SUB_POS_CUSTOM)
                || (GET_OSD_STATE() == _SUB_FACTORY_CANCEL) || (GET_OSD_STATE() == _SUB_FACTORY_RESET)
                || (GET_OSD_STATE() == _SUB_ACCESS_RATE) || (GET_OSD_STATE() == _SUB_ACCESS_TIMEOUT)
              )
            {
                {   // Draw Item Frame
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LT_));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW + 1), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LB_));
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 + 15), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RT_));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW + 1), COL(_ITEM_COL_1 + 15), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RB_));
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 + 15), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1), WIDTH(15), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(tmpItemBgColor));
                }
                OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1), WIDTH(15), HEIGHT(2), CHAR(___));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(2), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_1_of_2));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_3_START_1_of_2);

                if((ucItemStatus == _ITEM_UNSELECT) || (ucItemStatus == _ITEM_SELECT))
                {
                    // Clear Focus Frame
/////1
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(___));
/////2
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////3                    
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////4
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    if(0x00 
#if(_USER_DCR_FUNCTION == _ON)										
						|| (GET_OSD_STATE() == _SUB_DCR_ON) || (GET_OSD_STATE() == _SUB_DCR_OFF)
	#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
		||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
              #if(_INPUT_PORT_MAX == 0x02)              
                            ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150707
              #endif

	#endif
#else
	#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
		||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM) 						
               #if(_INPUT_PORT_MAX == 0x02)			  
 			            ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150727
               #endif
	#endif
#endif

#if(((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT== _OFF)))
						|| (GET_OSD_STATE() == _SUB_SCALING_FULL_SCREEN) || (GET_OSD_STATE() == _SUB_SCALING_ORIGINAL_AR)
#endif
#if(((_INPUT_PORT_MAX > 0x01) && (_OD_OSD_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
#if(_OD_MULTI_SELECT == _OFF)
                        || (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
#endif
#if (_DP_SUPPORT == _ON)
                        || (GET_OSD_STATE() == _SUB_DP_SL_11) || (GET_OSD_STATE() == _SUB_DP_SL_12)
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                        || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON) || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)
#endif
                        || (GET_OSD_STATE() == _SUB_POS_DEFAULT) || (GET_OSD_STATE() == _SUB_POS_CUSTOM)
                        || (GET_OSD_STATE() == _SUB_FACTORY_CANCEL) || (GET_OSD_STATE() == _SUB_FACTORY_RESET) 
                        || (GET_OSD_STATE() == _SUB_ACCESS_RATE) || (GET_OSD_STATE() == _SUB_ACCESS_TIMEOUT)
                      )
                    {   //235
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(11), HEIGHT(1), CHAR(___));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1 + 11), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1 + 12), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_T_));
                    }
					else if((GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
					|| (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
					)
                    {   //225
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
                    }
/////5
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(___));
/////6
                    if(0x00 
#if(_USER_DCR_FUNCTION == _ON)										
						|| (GET_OSD_STATE() == _SUB_DCR_ON) || (GET_OSD_STATE() == _SUB_DCR_OFF) 
#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
	||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
          #if(_INPUT_PORT_MAX == 0x02)              
                        ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150707
          #endif

#endif
#else
#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
	||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM) 
		#if(_INPUT_PORT_MAX == 0x02)			  
				  		||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150727
		#endif
#endif
#endif

#if(((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_SCALING_FULL_SCREEN) || (GET_OSD_STATE() == _SUB_SCALING_ORIGINAL_AR)
#endif

#if(((_INPUT_PORT_MAX > 0x01) && (_OD_OSD_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
#if(_OD_MULTI_SELECT == _OFF)
                        || (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
#endif
#if (_DP_SUPPORT == _ON)
                        || (GET_OSD_STATE() == _SUB_DP_SL_11) || (GET_OSD_STATE() == _SUB_DP_SL_12)
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                        || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON) || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)
#endif
                        || (GET_OSD_STATE() == _SUB_POS_DEFAULT) || (GET_OSD_STATE() == _SUB_POS_CUSTOM)
                        || (GET_OSD_STATE() == _SUB_FACTORY_CANCEL) || (GET_OSD_STATE() == _SUB_FACTORY_RESET)
                        || (GET_OSD_STATE() == _SUB_ACCESS_RATE) || (GET_OSD_STATE() == _SUB_ACCESS_TIMEOUT)
                      )
                    {
                        OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(___));
                    }
					else if((GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
					|| (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
					)
                    {
                        OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
                    }
/////7
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(___));
/////8
                    if(0x00 
#if(_USER_DCR_FUNCTION == _ON)										
						|| (GET_OSD_STATE() == _SUB_DCR_ON) || (GET_OSD_STATE() == _SUB_DCR_OFF) 
#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
		||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
          #if(_INPUT_PORT_MAX == 0x02)              
                        ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150707
          #endif

#endif
#else
#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
	||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
			#if(_INPUT_PORT_MAX == 0x02)			  
			  			||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150727
			#endif
#endif
#endif
#if(((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_SCALING_FULL_SCREEN) || (GET_OSD_STATE() == _SUB_SCALING_ORIGINAL_AR)
#endif
#if(((_INPUT_PORT_MAX > 0x01) && (_OD_OSD_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
#if(_OD_MULTI_SELECT == _OFF)
                        || (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
#endif
#if (_DP_SUPPORT == _ON)
                        || (GET_OSD_STATE() == _SUB_DP_SL_11) || (GET_OSD_STATE() == _SUB_DP_SL_12)
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                        || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON) || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)
#endif
                        || (GET_OSD_STATE() == _SUB_POS_DEFAULT) || (GET_OSD_STATE() == _SUB_POS_CUSTOM)
                        || (GET_OSD_STATE() == _SUB_FACTORY_CANCEL) || (GET_OSD_STATE() == _SUB_FACTORY_RESET)
                        || (GET_OSD_STATE() == _SUB_ACCESS_RATE) || (GET_OSD_STATE() == _SUB_ACCESS_TIMEOUT)
                      )
                    {
                        OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_T_));
                    }
					else if((GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
					|| (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
					)
                    {
                        OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
                    }
/////
                }
                else if(ucItemStatus == _ITEM_FOCUS)
                {
                    // Draw Focus Frame
/////1
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
/////2
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_L_));
/////3
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_R_));
/////4
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    if(0x00 
#if(_USER_DCR_FUNCTION == _ON)										
						|| (GET_OSD_STATE() == _SUB_DCR_ON) || (GET_OSD_STATE() == _SUB_DCR_OFF) 
	#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
		||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM) 
          #if(_INPUT_PORT_MAX == 0x02)              
                        ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150707
          #endif
	#endif

#else

	#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
		||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM) 
		#if(_INPUT_PORT_MAX == 0x02)			  
				  		||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150727
		#endif
	#endif

#endif

#if(((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_SCALING_FULL_SCREEN) || (GET_OSD_STATE() == _SUB_SCALING_ORIGINAL_AR)
#endif
#if(((_INPUT_PORT_MAX > 0x01) && (_OD_OSD_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
#if(_OD_MULTI_SELECT == _OFF)
                        || (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
#endif
#if (_DP_SUPPORT == _ON)
                        || (GET_OSD_STATE() == _SUB_DP_SL_11) || (GET_OSD_STATE() == _SUB_DP_SL_12)
#endif
                        || (GET_OSD_STATE() == _SUB_POS_DEFAULT) || (GET_OSD_STATE() == _SUB_POS_CUSTOM)
                        || (GET_OSD_STATE() == _SUB_FACTORY_CANCEL) || (GET_OSD_STATE() == _SUB_FACTORY_RESET) 
                        || (GET_OSD_STATE() == _SUB_ACCESS_RATE) || (GET_OSD_STATE() == _SUB_ACCESS_TIMEOUT)
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                        || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON) || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)
#endif
                      )
                    {
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(11), HEIGHT(1), CHAR(_Select_Frame_B_));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1 + 11), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_1));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1 + 12), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_TB_));
                    }
					else if((GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
					|| (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
					)
                    {
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(_Select_Frame_TB_));
                    }
/////5
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
/////6
                    if(0x00 
#if(_USER_DCR_FUNCTION == _ON)										
						|| (GET_OSD_STATE() == _SUB_DCR_ON) || (GET_OSD_STATE() == _SUB_DCR_OFF) 
	#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
		||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM) 
          #if(_INPUT_PORT_MAX == 0x02)              
                        ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150707
          #endif
	#endif
#else
	#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
		||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM) 
			#if(_INPUT_PORT_MAX == 0x02)			  
				  		||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150727
			#endif
	#endif

#endif
#if(((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_SCALING_FULL_SCREEN) || (GET_OSD_STATE() == _SUB_SCALING_ORIGINAL_AR)
#endif						
#if(((_INPUT_PORT_MAX > 0x01) && (_OD_OSD_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
#if(_OD_MULTI_SELECT == _OFF)
                        || (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
#endif
#if (_DP_SUPPORT == _ON)
                        || (GET_OSD_STATE() == _SUB_DP_SL_11) || (GET_OSD_STATE() == _SUB_DP_SL_12)
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                        || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON) || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)
#endif
                        || (GET_OSD_STATE() == _SUB_POS_DEFAULT) || (GET_OSD_STATE() == _SUB_POS_CUSTOM)
                        || (GET_OSD_STATE() == _SUB_FACTORY_CANCEL) || (GET_OSD_STATE() == _SUB_FACTORY_RESET)
                        || (GET_OSD_STATE() == _SUB_ACCESS_RATE) || (GET_OSD_STATE() == _SUB_ACCESS_TIMEOUT)
                      )
                    {
                        OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LB_));
                    }
					else if((GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
					|| (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
					)
                    {
                        OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LTB_));
                    }
/////7
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
/////8
                    if(0x00
#if(_USER_DCR_FUNCTION == _ON)																
						|| (GET_OSD_STATE() == _SUB_DCR_ON) || (GET_OSD_STATE() == _SUB_DCR_OFF) 
	#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
		||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM) 
          #if(_INPUT_PORT_MAX == 0x02)              
                        ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150707
          #endif
	#endif
#else
	#if(((_INPUT_PORT_MAX > 0x01) && ((_ASPECT_RATIO_SUPPORT == _ON) || (_OD_OSD_SUPPORT == _ON)))\
		||((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
						|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM) 
		#if(_INPUT_PORT_MAX == 0x02)			  
					   ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150727
		#endif
	#endif
#endif

#if(((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF)))
						|| (GET_OSD_STATE() == _SUB_SCALING_FULL_SCREEN) || (GET_OSD_STATE() == _SUB_SCALING_ORIGINAL_AR)
#endif

#if(((_INPUT_PORT_MAX > 0x01) && (_OD_OSD_SUPPORT == _ON))  || ((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _ON)))
#if(_OD_MULTI_SELECT == _OFF)
                        || (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
#endif
#if (_DP_SUPPORT == _ON)
                        || (GET_OSD_STATE() == _SUB_DP_SL_11) || (GET_OSD_STATE() == _SUB_DP_SL_12)
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                        || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON) || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)
#endif
                        || (GET_OSD_STATE() == _SUB_POS_DEFAULT) || (GET_OSD_STATE() == _SUB_POS_CUSTOM)
                        || (GET_OSD_STATE() == _SUB_FACTORY_CANCEL) || (GET_OSD_STATE() == _SUB_FACTORY_RESET)
                        || (GET_OSD_STATE() == _SUB_ACCESS_RATE) || (GET_OSD_STATE() == _SUB_ACCESS_TIMEOUT)
                      )
                    {
                        OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_3));
                    }
					else if((GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
					|| (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
					|| (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
					)
                    {
                        OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                        OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RTB_));
                    }
/////
                }
            }
            else
            {
                OsdDisplayItemFrame(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1), BGCOLOR(tmpItemBgColor));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_1_of_3));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_3_START_1_of_3);
            }
            break;

        case _ITEM_3_2 :
            if(    
#if(_USER_DCR_FUNCTION == _ON)																
				(GET_OSD_STATE() == _SUB_DCR_ON) || (GET_OSD_STATE() == _SUB_DCR_OFF)
                || (GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
  #if(_INPUT_PORT_MAX == 0x02)              
                ||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150707
  #endif
#else
				(GET_OSD_STATE() == _SUB_MANUAL_CLOCK) || (GET_OSD_STATE() == _SUB_MANUAL_PHASE)
  #if(_INPUT_PORT_MAX == 0x02)			  
				||(GET_OSD_STATE() == _SUB_INPUT_ANALOG)||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)//20150727
  #endif
#endif
                || (GET_OSD_STATE() == _SUB_COLOR_PRESET_MODE) || (GET_OSD_STATE() == _SUB_COLOR_CUSTOM)
                
#if(_ASPECT_RATIO_SUPPORT == _ON)
                || (GET_OSD_STATE() == _SUB_SCALING_FULL_SCREEN) || (GET_OSD_STATE() == _SUB_SCALING_ORIGINAL_AR)
#endif

#if(_OD_OSD_SUPPORT == _ON)
#if(_OD_MULTI_SELECT == _OFF)
                || (GET_OSD_STATE() == _SUB_OD_ON) || (GET_OSD_STATE() == _SUB_OD_OFF)
#endif
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_ON) || (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT_OFF)
#endif
#if (_DP_SUPPORT == _ON)
                || (GET_OSD_STATE() == _SUB_DP_SL_11) || (GET_OSD_STATE() == _SUB_DP_SL_12)
#endif
                || (GET_OSD_STATE() == _SUB_POS_DEFAULT) || (GET_OSD_STATE() == _SUB_POS_CUSTOM)
                || (GET_OSD_STATE() == _SUB_FACTORY_CANCEL) || (GET_OSD_STATE() == _SUB_FACTORY_RESET)
                || (GET_OSD_STATE() == _SUB_ACCESS_RATE) || (GET_OSD_STATE() == _SUB_ACCESS_TIMEOUT)
              )
            {
                {   // Draw Frame
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(19), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LT_));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW + 1), COL(19), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LB_));
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(19), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(35), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RT_));
                    OsdFunc1bitChar(ROW(_ITEM_3_ROW + 1), COL(35), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RB_));
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(35), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(20), WIDTH(15), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(tmpItemBgColor));
                }
                OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(20), WIDTH(15), HEIGHT(2), CHAR(___));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(20), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_2_of_2));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_3_START_2_of_2);
            }
            else
            {
                OsdDisplayItemFrame(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2), BGCOLOR(tmpItemBgColor));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_2_of_3));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_3_START_2_of_3);
                
#if((_ASPECT_RATIO_SUPPORT == _OFF)&&(_OD_OSD_SUPPORT == _OFF))
				if((ucItemStatus == _ITEM_UNSELECT) || (ucItemStatus == _ITEM_SELECT))
				{
					if((GET_OSD_STATE() == _SUB_INPUT_ANALOG) || (GET_OSD_STATE() == _SUB_INPUT_DIGITAL0) ||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)) 
					{
					// Clear Focus Frame
/////1
						OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(___));
/////2
						OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////3
						OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////4
						OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_T_));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 5), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 6), WIDTH(5), HEIGHT(1), CHAR(___));
/////5
						OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(___));
/////6
						OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_T_));
/////7
						OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(___));
/////8
						OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
					}
					else
					{
						OsdDisplayClearFocusFrame(_ITEM_3_ROW);
					}
				}
				else if(ucItemStatus == _ITEM_FOCUS)
				{
					if((GET_OSD_STATE() == _SUB_INPUT_ANALOG) || (GET_OSD_STATE() == _SUB_INPUT_DIGITAL0) ||(GET_OSD_STATE() == _SUB_INPUT_DIGITAL1)) 
					{
						// Clear Focus Frame
/////1
						OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
/////2
						OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_L_));
/////3
						OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_R_));
/////4
						OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_TB_));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 5), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_2));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1 + 6), WIDTH(5), HEIGHT(1), CHAR(_Select_Frame_B_));
/////5
						OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
/////6
						OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_4));
/////7
						OsdFunc1bitColor(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
/////8
						OsdFunc1bitColor(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
						OsdFunc1bitChar(ROW(_ITEM_3_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RB_));
					}
					else
					{
						OsdDisplayDrawFocusFrame(_ITEM_3_ROW);
					}
				}
#else
                if((ucItemStatus == _ITEM_UNSELECT) || (ucItemStatus == _ITEM_SELECT))
                {
                    OsdDisplayClearFocusFrame(_ITEM_3_ROW);
                }
                else if(ucItemStatus == _ITEM_FOCUS)
                {
                    OsdDisplayDrawFocusFrame(_ITEM_3_ROW);
                }
#endif
            }
            break;

        case _ITEM_3_3 :
            OsdDisplayItemFrame(ROW(_ITEM_3_ROW), COL(_ITEM_COL_3), BGCOLOR(tmpItemBgColor));
            OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_3), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_3_of_3));
            OsdFontLoadItem(ucOsdState, _FONT1_ITEM_3_START_3_of_3);
            break;
//====================================================================================================
        case _ITEM_2_1 :
#if(_USER_DCR_FUNCTION == _ON)																
			if(
				(GET_OSD_STATE() == _SUB_IMAGE_POS_H) || (GET_OSD_STATE() == _SUB_IMAGE_POS_V)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))

				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_INPUT_SIGNAL)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_OVER_DRIVE)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF))
                #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                #else
				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_SCALING)
                #endif
#endif
				|| (GET_OSD_STATE() == _SUB_AUTO_SETUP) || (GET_OSD_STATE() == _SUB_MANUAL)
				)
#else
            if(
				(GET_OSD_STATE() == _SUB_BRI) || (GET_OSD_STATE() == _SUB_CON)
				|| (GET_OSD_STATE() == _SUB_IMAGE_POS_H) || (GET_OSD_STATE() == _SUB_IMAGE_POS_V)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))

				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_INPUT_SIGNAL)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_OVER_DRIVE)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF))
				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_SCALING)
#endif
				|| (GET_OSD_STATE() == _SUB_AUTO_SETUP) || (GET_OSD_STATE() == _SUB_MANUAL)
				)
#endif
            {
                {   // Draw Item Frame
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LT_));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + 1), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LB_));
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 + 15), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RT_));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + 1), COL(_ITEM_COL_1 + 15), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RB_));
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 + 15), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1), WIDTH(15), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(tmpItemBgColor));
                }
                OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1), WIDTH(15), HEIGHT(2), CHAR(___));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(2), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_1_of_2));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_2_START_1_of_2);

                if((ucItemStatus == _ITEM_UNSELECT) || (ucItemStatus == _ITEM_SELECT))
                {
                    // Clear Focus Frame
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(___));
                    
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
                    
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
/////
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(13), HEIGHT(1), CHAR(___));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1 + 13), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1 + 14), WIDTH(3), HEIGHT(1), CHAR(_Select_Frame_T_));
/////           
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(___));

                    OsdFunc1bitColor(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(___));
            
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(___));
            
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_T_));
                }
                else if(ucItemStatus == _ITEM_FOCUS)
                {
                    // Draw Focus Frame
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
                    
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_L_));
                    
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_R_));
/////
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(15 + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1), WIDTH(13), HEIGHT(1), CHAR(_Select_Frame_B_));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1 + 13), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_1));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 1 + 14), WIDTH(3), HEIGHT(1), CHAR(_Select_Frame_TB_));
/////
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
            
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LB_));
            
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW - 1), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
            
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + _ITEM_HEIGHT), COL(_ITEM_COL_1 + 15 + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_3));
                }
            }
            else
            {
                OsdDisplayItemFrame(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1), BGCOLOR(tmpItemBgColor));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_1_of_3));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_2_START_1_of_3);
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
			if(GET_OSD_LANGUAGE() == _RUSSIAN)
			{
				if(GET_OSD_STATE()== _SUB_COLOR)
				{
					OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), CHAR(_Factory_F_+1));
					OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), CHAR(_Factory_F_+2));
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_SEL_BG));
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1 + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_SEL_BG));
				}
				else if(GET_OSD_STATE()== _SUB_LOW_BLUE_LIGHT)
				{
					OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_2 - 1), WIDTH(1), HEIGHT(1), CHAR(_Factory_F_+1));
					OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), CHAR(_Factory_F_+2));
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_2 - 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_FOCUS_BG));
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_2 + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_FOCUS_BG));

				}

#if(_OD_SUPPORT == _ON)
				else if(GET_OSD_STATE()== _SUB_OVER_DRIVE)
#else
				else if(GET_OSD_STATE()== _SUB_SCALING)
#endif
				{
					OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3 - 1), WIDTH(1), HEIGHT(1), CHAR(_Factory_F_+1));
					OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3 + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), CHAR(_Factory_F_+2));
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3 - 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_SEL_BG));
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3 + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_SEL_BG));
				}
			}
#endif

			}
            break;

        case _ITEM_2_2 :
#if(_USER_DCR_FUNCTION == _ON)
			if((GET_OSD_STATE() == _SUB_IMAGE_POS_H) || (GET_OSD_STATE() == _SUB_IMAGE_POS_V)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))

				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_INPUT_SIGNAL)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_OVER_DRIVE)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF))
                #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
                #else
				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_SCALING)
                #endif
#endif
				|| (GET_OSD_STATE() == _SUB_AUTO_SETUP) || (GET_OSD_STATE() == _SUB_MANUAL)
				)
#else
            if((GET_OSD_STATE() == _SUB_BRI) || (GET_OSD_STATE() == _SUB_CON)
				|| (GET_OSD_STATE() == _SUB_IMAGE_POS_H) || (GET_OSD_STATE() == _SUB_IMAGE_POS_V)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))

				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_INPUT_SIGNAL)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_OVER_DRIVE)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF))
				||(GET_OSD_STATE() == _SUB_COLOR) || (GET_OSD_STATE() == _SUB_SCALING)
#endif
				|| (GET_OSD_STATE() == _SUB_AUTO_SETUP) || (GET_OSD_STATE() == _SUB_MANUAL)\
				)
#endif
            {
                {   // Draw Frame
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(19), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LT_));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + 1), COL(19), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LB_));
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(19), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(35), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RT_));
                    OsdFunc1bitChar(ROW(_ITEM_2_ROW + 1), COL(35), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RB_));
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(35), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(tmpItemBgColor), BGCOLOR(_CP_MENU_BG));
                    
                    OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(20), WIDTH(15), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(tmpItemBgColor));
                }
                OsdFunc1bitChar(ROW(_ITEM_2_ROW), COL(20), WIDTH(15), HEIGHT(2), CHAR(___));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(20), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_2_of_2));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_2_START_2_of_2);
            }
            else
            {
                OsdDisplayItemFrame(ROW(_ITEM_2_ROW), COL(_ITEM_COL_2), BGCOLOR(tmpItemBgColor));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_2), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_2_of_3));
                OsdFontLoadItem(ucOsdState, _FONT1_ITEM_2_START_2_of_3);
                
                if((ucItemStatus == _ITEM_UNSELECT) || (ucItemStatus == _ITEM_SELECT))
                {
                    OsdDisplayClearFocusFrame(_ITEM_2_ROW);
                }
                else if(ucItemStatus == _ITEM_FOCUS)
                {
                    OsdDisplayDrawFocusFrame(_ITEM_2_ROW);
                }
            }
            break;

        case _ITEM_2_3 :
            OsdDisplayItemFrame(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3), BGCOLOR(tmpItemBgColor));            
            OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_3_of_3));            
            OsdFontLoadItem(ucOsdState, _FONT1_ITEM_2_START_3_of_3);
            break;
//====================================================================================================
        case _ICON_1_1 :
            OsdDisplayIconFrame(ROW(_ITEM_1_ROW), COL(_ICON_COL_1), BGCOLOR(tmpItemBgColor));
            OsdFunc1bitItemApplyChar(ROW(_ITEM_1_ROW), COL(_ICON_COL_1), WIDTH(_ICON_WIDTH), HEIGHT(_ICON_HEIGHT), CHAR(_FONT1_ICON_1_START_1_of_5));
            OsdFontLoadItem(ucOsdState, _FONT1_ICON_1_START_1_of_5);
            break;

        case _ICON_1_2 :
            OsdDisplayIconFrame(ROW(_ITEM_1_ROW), COL(_ICON_COL_2), BGCOLOR(tmpItemBgColor));
            OsdFunc1bitItemApplyChar(ROW(_ITEM_1_ROW), COL(_ICON_COL_2), WIDTH(_ICON_WIDTH), HEIGHT(_ICON_HEIGHT), CHAR(_FONT1_ICON_1_START_2_of_5));
            OsdFontLoadItem(ucOsdState, _FONT1_ICON_1_START_2_of_5);
            break;

        case _ICON_1_3 :
            OsdDisplayIconFrame(ROW(_ITEM_1_ROW), COL(_ICON_COL_3), BGCOLOR(tmpItemBgColor));
            OsdFunc1bitItemApplyChar(ROW(_ITEM_1_ROW), COL(_ICON_COL_3), WIDTH(_ICON_WIDTH + 1), HEIGHT(_ICON_HEIGHT), CHAR(_FONT1_ICON_1_START_3_of_5));
            OsdFontLoadItem(ucOsdState, _FONT1_ICON_1_START_3_of_5);

            if((ucItemStatus == _ITEM_UNSELECT) || (ucItemStatus == _ITEM_SELECT))
            {
                OsdDisplayClearFocusFrame(_ITEM_1_ROW);
            }
            else if(ucItemStatus == _ITEM_FOCUS)
            {
                OsdDisplayDrawFocusFrame(_ITEM_1_ROW);
            }
            break;

        case _ICON_1_4 :
            OsdDisplayIconFrame(ROW(_ITEM_1_ROW), COL(_ICON_COL_4), BGCOLOR(tmpItemBgColor));
            OsdFunc1bitItemApplyChar(ROW(_ITEM_1_ROW), COL(_ICON_COL_4), WIDTH(_ICON_WIDTH), HEIGHT(_ICON_HEIGHT), CHAR(_FONT1_ICON_1_START_4_of_5));
            OsdFontLoadItem(ucOsdState, _FONT1_ICON_1_START_4_of_5);
            break;

        case _ICON_1_5 :
            OsdDisplayIconFrame(ROW(_ITEM_1_ROW), COL(_ICON_COL_5), BGCOLOR(tmpItemBgColor));
            OsdFunc1bitItemApplyChar(ROW(_ITEM_1_ROW), COL(_ICON_COL_5), WIDTH(_ICON_WIDTH), HEIGHT(_ICON_HEIGHT), CHAR(_FONT1_ICON_1_START_5_of_5));
            OsdFontLoadItem(ucOsdState, _FONT1_ICON_1_START_5_of_5);
            break;
        default:
            break;
    }
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayItemFrame(BYTE ucRow, BYTE ucCol, BYTE ucBgColor)
{
    OsdFunc1bitChar(ROW(ucRow), COL(ucCol - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LT_));
    OsdFunc1bitChar(ROW(ucRow + 1), COL(ucCol - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LB_));
    OsdFunc1bitColor(ROW(ucRow), COL(ucCol - 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(ucBgColor), BGCOLOR(_CP_MENU_BG));

    OsdFunc1bitChar(ROW(ucRow), COL(ucCol + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RT_));
    OsdFunc1bitChar(ROW(ucRow + 1), COL(ucCol + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RB_));
    OsdFunc1bitColor(ROW(ucRow), COL(ucCol + _ITEM_WIDTH), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(ucBgColor), BGCOLOR(_CP_MENU_BG));

    OsdFunc1bitColor(ROW(ucRow), COL(ucCol), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(ucBgColor));
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayIconFrame(BYTE ucRow, BYTE ucCol, BYTE ucBgColor)
{
    OsdFunc1bitChar(ROW(ucRow), COL(ucCol - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LT_));
    OsdFunc1bitChar(ROW(ucRow + 1), COL(ucCol - 1), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_LB_));
    OsdFunc1bitColor(ROW(ucRow), COL(ucCol - 1), WIDTH(1), HEIGHT(_ICON_HEIGHT), FGCOLOR(ucBgColor), BGCOLOR(_CP_MENU_BG));

    OsdFunc1bitChar(ROW(ucRow), COL(ucCol + _ICON_WIDTH + ((ucCol == _ICON_COL_3) ? (1) : (0))), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RT_));
    OsdFunc1bitChar(ROW(ucRow + 1), COL(ucCol + _ICON_WIDTH + ((ucCol == _ICON_COL_3) ? (1) : (0))), WIDTH(1), HEIGHT(1), CHAR(_Item_Frame_RB_));
    OsdFunc1bitColor(ROW(ucRow), COL(ucCol + _ICON_WIDTH + ((ucCol == _ICON_COL_3) ? (1) : (0))), WIDTH(1), HEIGHT(_ICON_HEIGHT), FGCOLOR(ucBgColor), BGCOLOR(_CP_MENU_BG));

    OsdFunc1bitColor(ROW(ucRow), COL(ucCol), WIDTH(_ICON_WIDTH + ((ucCol == _ICON_COL_3) ? (1) : (0))), HEIGHT(_ICON_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(ucBgColor));
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayIconColor(BYTE ucRow, BYTE ucCol, BYTE ucFgColor, BYTE ucBgColor)
{
    OsdFunc1bitColor(ROW(ucRow), COL(ucCol - 1), WIDTH(1), HEIGHT(_ICON_HEIGHT), FGCOLOR(ucFgColor), BGCOLOR(ucBgColor));
    OsdFunc1bitColor(ROW(ucRow), COL(ucCol + _ICON_WIDTH + ((ucCol == _ICON_COL_3) ? (1) : (0))), WIDTH(1), HEIGHT(_ICON_HEIGHT), FGCOLOR(ucFgColor), BGCOLOR(ucBgColor));

    OsdFunc1bitColor(ROW(ucRow), COL(ucCol), WIDTH(_ICON_WIDTH + ((ucCol == _ICON_COL_3) ? (1) : (0))), HEIGHT(_ICON_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(ucFgColor));
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayDrawFocusFrame(BYTE ucRow)
{
    if(ucRow == _ITEM_1_ROW)
    {
        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ICON_COL_3 - 1), WIDTH((_ICON_WIDTH + 1) + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ICON_COL_3 - 1), WIDTH((_ICON_WIDTH + 1) + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
        
        OsdFunc1bitColor(ROW(ucRow), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(_ICON_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(_ICON_HEIGHT), CHAR(_Select_Frame_L_));
        
        OsdFunc1bitColor(ROW(ucRow), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(_ICON_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(_ICON_HEIGHT), CHAR(_Select_Frame_R_));
//
        OsdFunc1bitColor(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 - 1), WIDTH((_ICON_WIDTH + 1) + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 - 1), WIDTH((_ICON_WIDTH + 1) + 2), HEIGHT(1), CHAR(_Select_Frame_B_));

        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));

        OsdFunc1bitColor(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LB_));

        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));

        OsdFunc1bitColor(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RB_));
    }
    else
    {
        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
        
        OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_L_));
        
        OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(_Select_Frame_R_));
//
        OsdFunc1bitColor(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        if(ucRow == _ITEM_2_ROW)
        {
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(13), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_B_));
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(14), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_1));
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(15), WIDTH(7), HEIGHT(1), CHAR(_Select_Frame_TB_));
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(22), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_2));
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(23), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_B_));
        }
        else
        {
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(_Select_Frame_TB_));
        }
        
        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));

        OsdFunc1bitColor(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR((ucRow == _ITEM_2_ROW) ? (_Select_Frame_LB_) : (_Select_Frame_LTB_)));

        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));

        OsdFunc1bitColor(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR((ucRow == _ITEM_2_ROW) ? (_Select_Frame_RB_) : (_Select_Frame_RTB_)));
    }
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayClearFocusFrame(BYTE ucRow)
{
    if(ucRow == _ITEM_1_ROW)
    {
        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ICON_COL_3 - 1), WIDTH((_ICON_WIDTH + 1) + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ICON_COL_3 - 1), WIDTH((_ICON_WIDTH + 1) + 2), HEIGHT(1), CHAR(___));
        
        OsdFunc1bitColor(ROW(ucRow), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(_ICON_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(_ICON_HEIGHT), CHAR(___));
        
        OsdFunc1bitColor(ROW(ucRow), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(_ICON_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(_ICON_HEIGHT), CHAR(___));
//
        OsdFunc1bitColor(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 - 1), WIDTH((_ICON_WIDTH + 1) + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 - 1), WIDTH((_ICON_WIDTH + 1) + 2), HEIGHT(1), CHAR(___));

        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(1), CHAR(___));

        OsdFunc1bitColor(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 - 2), WIDTH(1), HEIGHT(1), CHAR(___));

        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(1), CHAR(___));

        OsdFunc1bitColor(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ICON_HEIGHT), COL(_ICON_COL_3 + (_ICON_WIDTH + 1) + 1), WIDTH(1), HEIGHT(1), CHAR(___));
    }
    else
    {
        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(___));
        
        OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
        
        OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), CHAR(___));
//
//        OsdFunc1bitColor(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        if(ucRow == _ITEM_2_ROW)
        {
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(13), WIDTH(1), HEIGHT(1), CHAR(___));
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(14), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(15), WIDTH(7), HEIGHT(1), CHAR(_Select_Frame_T_));
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(22), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(23), WIDTH(1), HEIGHT(1), CHAR(___));
        }
        else
        {
            OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
        }

        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(___));

//        OsdFunc1bitColor(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR((ucRow == _ITEM_2_ROW) ? (___) : (_Select_Frame_LT_)));

        OsdFunc1bitColor(ROW(ucRow - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow - 1), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(___));

//        OsdFunc1bitColor(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
        OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR((ucRow == _ITEM_2_ROW) ? (___) : (_Select_Frame_RT_)));
    }
}


//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
// OSD Bar調整  
BYTE code tOSD_0_100_BAR_TABLE_U[]=
{
    _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_0_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_10_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_20_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_30_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_40_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_50_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_60_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_70_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_80_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_90_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_100_U,
    _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U,
};

BYTE code tOSD_0_100_BAR_TABLE_D[]=
{
    _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_0_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_10_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_20_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_30_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_40_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_50_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_60_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_70_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_80_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_90_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_100_D,
    _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D,
};

BYTE code tOSD_5_60_BAR_TABLE_U[]=
{
    _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_5_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_10_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_20_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_30_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_40_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_50_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_60_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,
    _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U, _Bar_T_U, _Bar_U, _Bar_U,    
};

BYTE code tOSD_5_60_BAR_TABLE_D[]=
{
    _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_5_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_10_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_20_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_30_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_40_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_50_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_60_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,
    _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D, _Bar_T_D, _Bar_D, _Bar_D,   
};



void OsdDisplayDrawBar(BYTE ucRow, BYTE ucBarValue, BYTE ucBarType)
{
    BYTE x = 0,uTempVal;

    OsdFontLoadFont(_FONT1_BAR);

    uTempVal = (120 * ucBarValue / 100);
        
    OsdFunc1bitByte0(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(_BAR_WIDTH), HEIGHT(_BAR_HEIGHT), _1BIT_FONT_256_511_WIDTH_12);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdDisplayWaitForDrawing(); //Ada.chen 20150721 
     
    //Bar 顏色處理
    if(GET_OSD_STATE() == _BAR_MENU_TIMEOUT)  //5-60
    {
        if(uTempVal < 23)                    //出現-5-
        {
            OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(_BAR_WIDTH), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_FOCUS_BG));
            OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(23 - uTempVal), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_UNSEL_BG));
        }
        else if(uTempVal > 55)              //出現-60-
        {
            OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(_BAR_WIDTH), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_FOCUS_BG));
            OsdFunc1bitColor(ROW(ucRow), COL(_BAR_WIDTH+1 - (uTempVal-55)), WIDTH(uTempVal-55), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_UNSEL_BG));
        }    
        else
        {
            OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(_BAR_WIDTH), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_FOCUS_BG));
        }        
    }
    else                                    //0-100
    {
        if(uTempVal < 17)                   //出現-0-
        {
            OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(_BAR_WIDTH), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_FOCUS_BG));
            OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(17 - uTempVal), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_UNSEL_BG));
        }
        else if(uTempVal > 103)             //出現-100-
        {
            OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(_BAR_WIDTH), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_FOCUS_BG));
            OsdFunc1bitColor(ROW(ucRow), COL(_BAR_WIDTH+1 - (uTempVal-103)), WIDTH(uTempVal-103), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_UNSEL_BG));
        }    
        else
        {
            OsdFunc1bitColor(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(_BAR_WIDTH), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_ITEM_FOCUS_BG));
        }        
    }
    
    OsdFunc1bitChar(ROW(ucRow), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), CHAR(_Bar_L_U));
    OsdFunc1bitChar(ROW(ucRow + 1), COL(_ITEM_COL_1 - 1), WIDTH(1), HEIGHT(1), CHAR(_Bar_L_D));
    OsdFunc1bitChar(ROW(ucRow), COL(_ITEM_COL_1 - 2 + _BAR_WIDTH), WIDTH(1), HEIGHT(1), CHAR(_Bar_R_U));
    OsdFunc1bitChar(ROW(ucRow + 1), COL(_ITEM_COL_1 - 2 + _BAR_WIDTH), WIDTH(1), HEIGHT(1), CHAR(_Bar_R_D));

    if(ucBarType == _Bar_0_100)
    {
        for(x = 0 ; x < (_BAR_WIDTH - 2) ; x++)
        {
            OsdFunc1bitChar(ROW(ucRow), COL(_ITEM_COL_1 + x), WIDTH(1), HEIGHT(1), CHAR(*(tOSD_0_100_BAR_TABLE_U + x + (120 * ucBarValue / 100))));
            OsdFunc1bitChar(ROW(ucRow + 1), COL(_ITEM_COL_1 + x), WIDTH(1), HEIGHT(1), CHAR(*(tOSD_0_100_BAR_TABLE_D + x + (120 * ucBarValue / 100))));
        }
    }
    else     //_Bar_5_60
    {
        for(x = 0 ; x < (_BAR_WIDTH - 2) ; x++)
        {
            OsdFunc1bitChar(ROW(ucRow), COL(_ITEM_COL_1 + x), WIDTH(1), HEIGHT(1), CHAR(*(tOSD_5_60_BAR_TABLE_U + x + (120 * ucBarValue / 100))));
            OsdFunc1bitChar(ROW(ucRow + 1), COL(_ITEM_COL_1 + x), WIDTH(1), HEIGHT(1), CHAR(*(tOSD_5_60_BAR_TABLE_D + x + (120 * ucBarValue / 100))));
        }
    }
    
    OsdFunc1bitByte0(ROW(ucRow - 1), COL(18), WIDTH(1), HEIGHT(1), _1BIT_FONT_256_511_WIDTH_12);
    OsdFunc1bitColor(ROW(ucRow - 1), COL(18), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
    OsdFunc1bitChar(ROW(ucRow - 1), COL(18), WIDTH(1), HEIGHT(1), CHAR(_Bar_V));

//    OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 1), WIDTH(_ITEM_WIDTH + 2), HEIGHT(1), CHAR(_Select_Frame_T_));
//    OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 - 2), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));
//    OsdFunc1bitChar(ROW(ucRow + _ITEM_HEIGHT), COL(_ITEM_COL_2 + _ITEM_WIDTH + 1), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));

}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
/*
void OsdDisplayClearBar(BYTE ucRow)
{
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncCloseWindow(_WIN8);

    OsdFunc1bitByte0(ROW(ucRow - 1), COL(_ITEM_COL_1 - 1), WIDTH(_BAR_WIDTH), HEIGHT(_BAR_HEIGHT),_1BIT_FONT_0_255_WIDTH_12);
    OsdFunc1bitColor(ROW(ucRow - 1), COL(_ITEM_COL_1 - 1), WIDTH(_BAR_WIDTH), HEIGHT(_BAR_HEIGHT), FGCOLOR(_CP_MENU_BG), BGCOLOR(_CP_MENU_BG));
}
*/

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayDrawInformation(void)
{

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
   
    //Item
    //OsdFunc1bitColor(ROW(1), COL(1), WIDTH(35), HEIGHT(8), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_FOCUS_BG));
    OsdFunc1bitColor(ROW(1), COL(1), WIDTH(35), HEIGHT(8), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_FOCUS_BG));

    //Forcus Frame  
    OsdFunc1bitColor(ROW(0), COL(1), WIDTH(35), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
    OsdFunc1bitChar(ROW(0), COL(1), WIDTH(35), HEIGHT(1), CHAR(_Select_Frame_T_));
    
    OsdFunc1bitColor(ROW(9), COL(1), WIDTH(35), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
    OsdFunc1bitChar(ROW(9), COL(1), WIDTH(11), HEIGHT(1), CHAR(_Select_Frame_B_));
    OsdFunc1bitChar(ROW(9), COL(12), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_1));
    OsdFunc1bitChar(ROW(9), COL(13), WIDTH(11), HEIGHT(1), CHAR(_Select_Frame_TB_));
    OsdFunc1bitChar(ROW(9), COL(24), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_SPECIAL_2));
    OsdFunc1bitChar(ROW(9), COL(25), WIDTH(11), HEIGHT(1), CHAR(_Select_Frame_B_));

    OsdFunc1bitColor(ROW(1), COL(0), WIDTH(1), HEIGHT(8), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
    OsdFunc1bitChar(ROW(1), COL(0), WIDTH(1), HEIGHT(8), CHAR(_Select_Frame_L_));

    OsdFunc1bitColor(ROW(1), COL(36), WIDTH(1), HEIGHT(8), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
    OsdFunc1bitChar(ROW(1), COL(36), WIDTH(1), HEIGHT(8), CHAR(_Select_Frame_R_));

    OsdFunc1bitColor(ROW(0), COL(0), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
    OsdFunc1bitChar(ROW(0), COL(0), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LT_));

    OsdFunc1bitColor(ROW(9), COL(0), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
    OsdFunc1bitChar(ROW(9), COL(0), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_LB_));

    OsdFunc1bitColor(ROW(0), COL(36), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
    OsdFunc1bitChar(ROW(0), COL(36), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RT_));

    OsdFunc1bitColor(ROW(9), COL(36), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_FOCUS_FRAME), BGCOLOR(_CP_MENU_BG));
    OsdFunc1bitChar(ROW(9), COL(36), WIDTH(1), HEIGHT(1), CHAR(_Select_Frame_RB_));

    OsdDispInformationPage();
    //OsdFunc1bitColor(ROW(1), COL(1), WIDTH(35), HEIGHT(8), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_FOCUS_BG));
}



//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDispInformationPage(void)	// jimmy 20121008_1 font interval width
{              
	BYTE xdata parray[20];
	BYTE row=2,i=0, tempcol=0;
	
	// jimmy 20121011_0 fine tune information string location	
	if(OsdFuncGetStringLength(tOSD_sMODE_NAME, GET_OSD_LANGUAGE()) > OsdFuncGetStringLength(tOSD_sMICROCODE, GET_OSD_LANGUAGE()))
	{
		tempcol = 20 - 3 - (OsdFuncGetStringLength(tOSD_sMODE_NAME, GET_OSD_LANGUAGE()) / 12);
	}
	else
	{
		tempcol = 20 - 3 - (OsdFuncGetStringLength(tOSD_sMICROCODE, GET_OSD_LANGUAGE()) / 12);
	}
	
  	OsdFuncPutStringProp(row, tempcol, _PFONT_PAGE_0, tOSD_sMODE, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);
	OsdFuncPutStringProp(row+3, tempcol, _PFONT_PAGE_0, tOSD_sMODE_NAME, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);
#if 0//((_PROJECT == _PRJ_L_T2254G_A_SEC_LTM220MT12) || (_PROJECT == _CVT_RL6230_PROJECT))
	OsdFuncPutStringProp(row+3, tempcol+11, _PFONT_PAGE_0, tOSD_sMODE_NAME_LOW_RADIATION, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);
#endif
	OsdFuncPutStringProp(row+5, tempcol, _PFONT_PAGE_0, tOSD_sMICROCODE, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);

	tempcol = 20;
	
	// show resolution
	if(GET_INPUT_TIMING_HWIDTH() > 999)
	{
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() / 1000) + _0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 1000 / 100) + _0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 100 / 10) + _0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 10) + _0_;	
	}
	else
	{
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 1000 / 100) + _0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 100 / 10) + _0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 10) + _0_;	
	}
	
	parray[i++] = _x_;
	//jason.cheng 20141110_1 add follow TPV request (I Timing show V need X2 );
	if(GET_INPUT_TIMING_INTERLACE_FLG() == _ON)
	{
		if((GET_INPUT_TIMING_VHEIGHT()*2) > 999)
		{
			parray[i++] = ((GET_INPUT_TIMING_VHEIGHT()*2) / 1000) + _0_;
			parray[i++] = ((GET_INPUT_TIMING_VHEIGHT()*2) % 1000 / 100) + _0_;
			parray[i++] = ((GET_INPUT_TIMING_VHEIGHT()*2) % 100 / 10) + _0_;
			parray[i++] = ((GET_INPUT_TIMING_VHEIGHT()*2) % 10) + _0_;	
		}
		else
		{
			parray[i++] = ((GET_INPUT_TIMING_VHEIGHT()*2) % 1000 / 100) + _0_;
			parray[i++] = ((GET_INPUT_TIMING_VHEIGHT()*2) % 100 / 10) + _0_;
			parray[i++] = ((GET_INPUT_TIMING_VHEIGHT()*2) % 10) + _0_;	
		}
	}
	else
	{
		if(GET_INPUT_TIMING_VHEIGHT() > 999)
		{
			parray[i++] = (GET_INPUT_TIMING_VHEIGHT() / 1000) + _0_;
			parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 1000 / 100) + _0_;
			parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 100 / 10) + _0_;
			parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 10) + _0_;	
		}
		else
		{
			parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 1000 / 100) + _0_;
			parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 100 / 10) + _0_;
			parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 10) + _0_;	
		}
	}
	parray[i++] = _END_;
	
	OsdFuncPutStringProp(row, tempcol, _PFONT_PAGE_0, parray, _ENGLISH, COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);
	
	// H / V
	i = 0;
	
	parray[i++] = (GET_INPUT_TIMING_HFREQ() / 100) + _0_;
	parray[i++] = (GET_INPUT_TIMING_HFREQ() % 100 / 10) + _0_;
	parray[i++] = _DOT;
	parray[i++] = (GET_INPUT_TIMING_HFREQ() % 10) + _0_;
	parray[i++] = _K_;
	parray[i++] = _H_;
	parray[i++] = _z_;
	parray[i++] = __6;
	parray[i++] = _SLASH;
	parray[i++] = __6;
	parray[i++] = (GET_INPUT_TIMING_VFREQ() / 100) + _0_;
	parray[i++] = (GET_INPUT_TIMING_VFREQ() % 100 / 10) + _0_;
	parray[i++] = _DOT;
	parray[i++] = (GET_INPUT_TIMING_VFREQ() % 10) + _0_;
	parray[i++] = _H_;
	parray[i++] = _z_;
	parray[i++] = _END_;	
	OsdFuncPutStringProp(row+1, tempcol, _PFONT_PAGE_0, parray, _ENGLISH, COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)//jason.cheng 20150116_1 update	
	OsdFuncASCIIConvert(tOSD_scMODE_NAME,parray);//2015-01-15  By Jerry //
	OsdFuncPutStringProp(row+3, tempcol, _PFONT_PAGE_0, parray, _ENGLISH, COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);
#else
	OsdFuncPutStringProp(row+3, tempcol, _PFONT_PAGE_0, tOSD_scMODE_NAME, _ENGLISH, COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);
#endif

#if((_FACTORY_MODE_OWNER == _OWNER_WISTRON)&&(_PANEL_EXIST_MULTIPANEL == _ON)) 
    FacMtiPanelShowVersion(ROW(row+5),COL(tempcol));
#else   

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)//jason.cheng 20150116_1 update	
	OsdFuncASCIIConvert(tOSD_scMICROCODE,parray);//2015-01-15  By Jerry //
	OsdFuncPutStringProp(row+5, tempcol, _PFONT_PAGE_0, parray, _ENGLISH, COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);	
#else
	OsdFuncPutStringProp(row+5, tempcol, _PFONT_PAGE_0, tOSD_scMICROCODE, _ENGLISH, COLOR(_CP_WHITE,_CP_ITEM_FOCUS_BG), _1BIT_FONT_256_511_WIDTH_12);	
#endif

#endif
    

}

bit OsdDisplayWaitForDrawing(void)
{
    BYTE ucTemp = (WORD)GET_OSD_VPOS() * 100 / (_OSD_V_POS_MAX - _OSD_V_POS_MIN);

    if((GET_INPUT_TIMING_VFREQ() > 855) || (GET_INPUT_TIMING_VFREQ() < 230))
    {
        return _FALSE;
    }

    if(ucTemp > 50)
    {
        ScalerTimerDelayXms(10000/2/GET_INPUT_TIMING_VFREQ());
    }

    return _TRUE;    
}


#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_LBL_HOTKEY_FUNCTION == _ON))
#define _OSD_LOW_BLUE_LIGHT_WIDTH                       168
#define _OSD_LOW_BLUE_LIGHT_HEIGHT                      90
//#define _OSD_LOW_BLUE_LIGHT_2BIT_OFFSET                18
#define _OSD_LOW_BLUE_LIGHT_FONT_BASE_ADDRESS           81
#define _OSD_LOW_BLUE_LIGHT_ADDRESS_ROWCOMMAND          0
#define _OSD_LOW_BLUE_LIGHT_ADDRESS_CHARCOMMAND         6

    
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayLowBlueLightHotKeyMsg(void)
{
    OsdFuncOsdBlending(_BLENDING_TYPE1);
    OsdFuncOsdTransparency(0);   

//==== Load font & icon & color palette=======      //載入字型檔
    OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_LOW_BLUE_LIGHT);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_LOW_BLUE_LIGHT);

    
    if(GET_OSD_LOW_BLUE_LIGHT_STATUS()==_ENABLE)
    {
		ScalerOsd2BitFontOffset(18);  
		// ScalerOsd2BitFontOffset(_OSD_LOW_BLUE_LIGHT_2BIT_OFFSET);
		ScalerOsdSramBaseAddressSet(_OSD_A, _OSD_LOW_BLUE_LIGHT_ADDRESS_ROWCOMMAND, _OSD_LOW_BLUE_LIGHT_ADDRESS_CHARCOMMAND, _OSD_LOW_BLUE_LIGHT_FONT_BASE_ADDRESS);
        OsdFontLoadFont(_FONT1_LOW_BLUE_LIGHT_ENABLE);
    }
    else
    {
		ScalerOsd2BitFontOffset(20); 
		// ScalerOsd2BitFontOffset(_OSD_LOW_BLUE_LIGHT_2BIT_OFFSET);
		ScalerOsdSramBaseAddressSet(_OSD_A, _OSD_LOW_BLUE_LIGHT_ADDRESS_ROWCOMMAND, _OSD_LOW_BLUE_LIGHT_ADDRESS_CHARCOMMAND, _OSD_LOW_BLUE_LIGHT_FONT_BASE_ADDRESS);
        OsdFontLoadFont(_FONT1_LOW_BLUE_LIGHT_DISABLE);
    }

    OsdDisplaySetPosition(_LOW_BLUE_LIGHT_OSD, 177, 0);

	OsdFuncEnableOsd();
}
#endif


/*
BYTE OsdDisplayItemCheck(BYTE ucOsdState)
{
    BYTE i=0;
    BYTE ucSelectCheck = 0;
    DebugMessageOsd("ucOsdState = ",ucOsdState);
   // for(i=(ucOsdState-1), i<=(ucOsdState+1),i++)
    {
        switch(i)
        {
            //Level 2
            case _SUB_COLOR:
                if((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON))
                    ucSelectCheck |= (0x00<<(i - (ucOsdState-1)));
                else    
                    ucSelectCheck |= (_BIT0<<(i - (ucOsdState-1)));
            break;

#if(_INPUT_PORT_MAX > 0x01)  
            case _SUB_INPUT_SIGNAL:
                ucSelectCheck |= (_BIT0<<(i - (ucOsdState-1)));
            break;
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
            case _SUB_SCALING:
                if(UserCheckAspectRatioFunction() == _TRUE)
                    ucSelectCheck |= (_BIT0<<(i - (ucOsdState-1)));
                else    
                    ucSelectCheck |= (0x00<<(i - (ucOsdState-1)));
            break;
#endif

#if(_OD_OSD_SUPPORT == _ON)
            case _SUB_OVER_DRIVE:
                ucSelectCheck |= (_BIT0<<(i - (ucOsdState-1)));
            break;
#endif

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
            case _SUB_LOW_BLUE_LIGHT:
                ucSelectCheck |= (_BIT0<<(i - (ucOsdState-1)));
            break;
#endif
        }
    }
DebugMessageOsd(" ucSelectCheck= ",ucSelectCheck);
    return ucSelectCheck;
}
*/

#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
