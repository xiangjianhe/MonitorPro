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

//20120509 Abel Modify start
//DFM命令使用參數
//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

#define _TPV_FQ_FACTORY							1
#define _TPV_LT_FACTORY							2
#define _TPV_WH_FACTORY							3
#define _TPV_BJ_FACTORY							4

//--------------------------------------------------
// include project 
//--------------------------------------------------
#include _FACTORY_COMMAND_INCLUDE

enum DFMStringTextDef
{
    _DFM_TEXT_PANEL_TYPE = 0,
    _DFM_TEXT_DEVICE_VERSION,
    _DFM_TEXT_MODEL_NAME,
    _DFM_TEXT_URL,
};
#ifndef GET_ADC_RGAIN
#define GET_ADC_RGAIN()         g_stAdcData.ucAdcGainMSB[0]
#endif
#ifndef GET_ADC_GGAIN
#define GET_ADC_GGAIN()         g_stAdcData.ucAdcGainMSB[1]
#endif
#ifndef GET_ADC_BGAIN
#define GET_ADC_BGAIN()         g_stAdcData.ucAdcGainMSB[2]
#endif
#ifndef GET_ADC_ROFFSET
#define GET_ADC_ROFFSET()       g_stAdcData.ucAdcOffsetMSB[0]
#endif
#ifndef GET_ADC_GOFFSET
#define GET_ADC_GOFFSET()       g_stAdcData.ucAdcOffsetMSB[1]
#endif
#ifndef GET_ADC_BOFFSET
#define GET_ADC_BOFFSET()       g_stAdcData.ucAdcOffsetMSB[2]
#endif
#ifndef FC_GET_RANGE_GAIN
#define FC_GET_RANGE_GAIN()     128
#endif

#ifndef FC_GET_BRIGHTNESS
#define FC_GET_BRIGHTNESS()     100
#endif
#ifndef FC_GET_LANGUAGE
#define FC_GET_LANGUAGE()       0x02
#endif

#ifndef _F_URL
#define _F_URL                  'U', 'R', 'L'
#endif




//--------------------------------------------------
//Definitions of Factory Data
//--------------------------------------------------
// 20111109 by jerry,  for TPV factory data
typedef struct
{
    BYTE b1BurnIn : 1;				//burnIn mode on/off
	BYTE b1LogoOff :1;				//Force Logo on/off
	BYTE b1FactoryMode :1;			//Factory mode on/off
	BYTE b1EnegyLogo :1;			//China enegy Logo on/off
	BYTE b1InternalAutoColor :1;    //Internal ADC Pass/Fail //DFM rev05 patch note 2
#if(_AUTO_POWER_DOWN == _ON)
	BYTE b1FactoryAutoPowerDown :1;	//factory auto power down on/off
#endif
#if((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
	BYTE b1VGAEdidCheck :1;			//just for WH, reload default VGA EDID 
	BYTE b1DVIEdidCheck :1;			//just for WH, reload default DVIEDID 
	BYTE b1HDMIEdidCheck :1;		//just for WH, reload default HDMI EDID 
#endif
    BYTE ucsRGBBacklight;			//sRGB backligh value
	BYTE ucVcomValue;				//Panel Vcom value
	WORD usDFMProductMode;			//DFM product Code  _PRODUCT_ON:0x55AA; _PRODUCT_OFF:0xAA55
	BYTE ucLanguage;				//recall language in Factory Mode
    	
	BYTE ucDummy1;					//reserve
	BYTE ucDummy2;					//reserve
	//total 8bytes =5bit+(3bit)+5bytes+2dummy bytes = 8 bytes
	
}StructFactoryType;


//****************************************************************************
// LAYER DEFINITIONS / MACROS 
//****************************************************************************
//--------------------------------------------------
// MACRO for BurnIn
//--------------------------------------------------
#define GET_FACTORY_BURNIN()               		(g_stFactoryData.b1BurnIn)
#define SET_FACTORY_BURNIN(x)              		(g_stFactoryData.b1BurnIn = (x))
//--------------------------------------------------
// MACRO for Logo Off Mode
//--------------------------------------------------
#define GET_FACTORY_FORCE_LOGO_OFF()			(g_stFactoryData.b1LogoOff)
#define SET_FACTORY_FORCE_LOGO_OFF(x)      		(g_stFactoryData.b1LogoOff = (x))
//--------------------------------------------------
// MACRO for FactoryMode
//--------------------------------------------------
#define GET_FACTORY_MODE()               		(g_stFactoryData.b1FactoryMode)
#define SET_FACTORY_MODE(x)              		(g_stFactoryData.b1FactoryMode = (x))
//--------------------------------------------------
// MACRO for Enegy  Logo 
//--------------------------------------------------
#define GET_FACTORY_ENEGY_LOGO()				(g_stFactoryData.b1EnegyLogo)
#define SET_FACTORY_ENEGY_LOGO(x)            	(g_stFactoryData.b1EnegyLogo= (x))
//--------------------------------------------------
// MACRO for DFM status
//--------------------------------------------------
#define GET_FACTORY_DFM_MODE()					(g_stFactoryData.usDFMProductMode)
#define SET_FACTORY_DFM_MODE(x)            		(g_stFactoryData.usDFMProductMode = (x))

//DFM rev05 patch note 2>>
//--------------------------------------------------
// MACRO for Internal Auto color 
//--------------------------------------------------
#define GET_INTERNAL_AUTOCOLOR()				(g_stFactoryData.b1InternalAutoColor)
#define SET_INTERNAL_AUTOCOLOR(x)            	(g_stFactoryData.b1InternalAutoColor = (x))
//--------------------------------------------------
//DFM rev05 patch note 2<<

// MACRO for Backlight Base
//--------------------------------------------------
#define GET_FACTORY_BACKLIGHT_BASE()			(g_stFactoryData.ucsRGBBacklight)
#define SET_FACTORY_BACKLIGHT_BASE(x)			(g_stFactoryData.ucsRGBBacklight = (x))

//--------------------------------------------------
// MACRO for Panel VCOM adjsut
//--------------------------------------------------
#define GET_FACTORY_VCOM()						(g_stFactoryData.ucVcomValue)
#define SET_FACTORY_VCOM(x)						(g_stFactoryData.ucVcomValue = (x))

#if(_AUTO_POWER_DOWN == _ON)
#define GET_FACTORY_AUTO_POWER_DOWN_STAUTS()	(g_stFactoryData.b1FactoryAutoPowerDown)
#define SET_FACTORY_AUTO_POWER_DOWN_STAUTS(x)	(g_stFactoryData.b1FactoryAutoPowerDown = (x))
#endif

#if((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
//--------------------------------------------------
// MACRO for Panel VCOM adjsut
//--------------------------------------------------
#define GET_VGA_EDID_CHECK()					(g_stFactoryData.b1VGAEdidCheck)
#define SET_VGA_EDID_CHECK(x)					(g_stFactoryData.b1VGAEdidCheck = (x))

#define GET_DVI_EDID_CHECK()					(g_stFactoryData.b1DVIEdidCheck)
#define SET_DVI_EDID_CHECK(x)					(g_stFactoryData.b1DVIEdidCheck = (x))

#define GET_HDMI_EDID_CHECK()					(g_stFactoryData.b1HDMIEdidCheck)
#define SET_HDMI_EDID_CHECK(x)					(g_stFactoryData.b1HDMIEdidCheck = (x))
#endif

//20120509 Abel end

//--------------------------------------------------
//Definitions of support Color Temperature
//--------------------------------------------------
#define _FACTORY_COLORTEMP_ITEM1                		_CT_6500
#define _FACTORY_COLORTEMP_ITEM2                		_CT_7200
#define _FACTORY_COLORTEMP_ITEM3                		_CT_9300
#define _FACTORY_COLORTEMP_ITEM4                		_CT_SRGB
#define _FACTORY_COLORTEMP_ITEM5                		_CT_USER
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
#define _FACTORY_COLORTEMP_ITEM6                		_CTLOWBLUELIGHT
#endif
//#define _FACTORY_COLORTEMP_ITEM7                		_CT_COLORTEMP_AMOUNT

//--------------------------------------------------
// Definitions of Factory OSD Flow
//--------------------------------------------------
enum OsdFactoryMenuPtr
{
//-------------------------------------------------------------------------------------------------------------------------------------------------
//  Factory State
//-------------------------------------------------------------------------------------------------------------------------------------------------
    //Auto Color
    //MENU_FACTORY_AUTOCOLOR = _MAIN_MENU_STATE_END,
    MENU_FACTORY_START=0,
	MENU_FACTORY_AUTOCOLOR,
    //Gain
    _MENU_FACTORY_GAIN_R,
    _MENU_FACTORY_GAIN_G,
    _MENU_FACTORY_GAIN_B,

    //Offset
    _MENU_FACTORY_OFFSET_R,
    _MENU_FACTORY_OFFSET_G,
    _MENU_FACTORY_OFFSET_B,

    //6500
    _MENU_FACTORY_CT1_R,
    _MENU_FACTORY_CT1_G,
    _MENU_FACTORY_CT1_B,

    //7200
    _MENU_FACTORY_CT2_R,
    _MENU_FACTORY_CT2_G,
    _MENU_FACTORY_CT2_B,

    //9300
    _MENU_FACTORY_CT3_R,
    _MENU_FACTORY_CT3_G,
    _MENU_FACTORY_CT3_B,

    //sRGB
    _MENU_FACTORY_CT4_R,
    _MENU_FACTORY_CT4_G,
    _MENU_FACTORY_CT4_B,

    //User
    _MENU_FACTORY_CT5_R,
    _MENU_FACTORY_CT5_G,
    _MENU_FACTORY_CT5_B,
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	//Low blue light
	_MENU_FACTORY_CT6_R,
	_MENU_FACTORY_CT6_G,
	_MENU_FACTORY_CT6_B,
#endif
    //BRI
    _MENU_FACTORY_BRIGHTNESS,
    //CON
    _MENU_FACTORY_CONTRAST,
    //SSC
    _MENU_FACTORY_SSC,
    //DFM
    _MENU_FACTORY_DFM,
    //BURNIN
    _MENU_FACTORY_BURNIN,
    //EDID WP
    _MENU_FACTORY_EDID_WP,
    //HW AUTOCOLOR
	_MENU_FACTORY_HW_AUTOCOLOR,
#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
    //PANEL VCOM
	_MENU_FACTORY_VCOM,
#endif

#if(_AUTO_POWER_DOWN == _ON)
	//AUTO POWER DOWN
	_MENU_FACTORY_AUTO_POWER_DOWN,
#endif
#if(_ENERGY_STAR_SUPPORT== _ON)
			//DPS
	_MENU_FACTORY_DPS,
#endif

    //RETURN    
    _MENU_FACTORY_EXIT,
    //Panel ON TIME
//    _MENU_FACTORY_POT,

//ADJ>>>>	
    //Adjust Gain
    _MENU_FACTORY_GAIN_R_ADJ,
    _MENU_FACTORY_GAIN_G_ADJ,
    _MENU_FACTORY_GAIN_B_ADJ,         
    //Adjust Offset
    _MENU_FACTORY_OFFSET_R_ADJ,
    _MENU_FACTORY_OFFSET_G_ADJ,
    _MENU_FACTORY_OFFSET_B_ADJ,

    //Adjust 6500 R G B
    _MENU_FACTORY_CT1_R_ADJ,
    _MENU_FACTORY_CT1_G_ADJ,
    _MENU_FACTORY_CT1_B_ADJ,

     //Adjust 7200 R G B
    _MENU_FACTORY_CT2_R_ADJ,
    _MENU_FACTORY_CT2_G_ADJ,
    _MENU_FACTORY_CT2_B_ADJ,

     //Adjust 9300 R G B
    _MENU_FACTORY_CT3_R_ADJ,
    _MENU_FACTORY_CT3_G_ADJ,
    _MENU_FACTORY_CT3_B_ADJ,

    //Adjust sRGB R G B
    _MENU_FACTORY_CT4_R_ADJ,
    _MENU_FACTORY_CT4_G_ADJ,
    _MENU_FACTORY_CT4_B_ADJ,
    
    //Adjust User R G B
    _MENU_FACTORY_CT5_R_ADJ,
    _MENU_FACTORY_CT5_G_ADJ,
    _MENU_FACTORY_CT5_B_ADJ,

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	//Adjust Low blue light  R G B
	_MENU_FACTORY_CT6_R_ADJ,
	_MENU_FACTORY_CT6_G_ADJ,
	_MENU_FACTORY_CT6_B_ADJ,
#endif
    //Adjust Bri  
    _MENU_FACTORY_BRIGHTNESS_ADJ,
    
    //Adjust Con     
    _MENU_FACTORY_CONTRAST_ADJ,

    //Adjust SSC 
    _MENU_FACTORY_SSC_ADJ,

#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
    //Adjust VCOM
    _MENU_FACTORY_VCOM_ADJ,
#endif
  
    _MENU_FACTORY_OSD_END,
};


//----------------------------------------------------------------------------------------
// Extern functions from FactoryFunction.c
//----------------------------------------------------------------------------------------
#ifndef __FACTORY_FUNCTION__

extern BYTE xdata ucFactoryOsdState;
extern BYTE xdata ucLcdConditionPattern;

extern void RTDFactoryOsdFuncDisableOsd(void);

extern void TPVFactoryMenuPro(void);
extern void TPVFactoryRightPro(void);
extern void TPVFactoryLeftPro(void);
extern void TPVFactoryExitPro(void);
extern void RTDFactoryPanelUsedTimer(void);
extern void TPVFactoryMainMenu(void);
extern void TPVFactoryAutoColorShowPass(void);

#endif

//20120509 Abel Modify start
//****************************************************************************
// FUNCTION EXTERN of FactoryCommand.c
//****************************************************************************
#ifndef __FACTORY_COMMAND__

extern StructFactoryType g_stFactoryData;
extern void TPVNVRamSaveFactoryDate(void);
extern void TPVNVRamLoadFactoryDate(void);
extern void TPVNVRamRestoreFactoryDate(void);
extern bit TPVFCmdFactoryCommand(void);


//DFM mode
extern void TPVDFMInitial(void);
extern bit TPVDFMModeFlag(void);
extern bit TPVDFMCableWPCheck(void);//DFM rev02 patch note 7
extern void TPVDFMFactoryRest(void);
extern void TPVDFMPowerRecall(void);
extern bit TPVDFMLogoOnCheck(void);
extern bit TPVDFMKeyPadLedCheck(BYTE ucKeyPadLed);
extern bit TPVDFMAutoConfigByPass(void);
//extern bit TPVDFMMsgTimeAcceleration(void);
extern void TPVDFMSet( bit bOnOff);
extern void TPVDFMForce2PowerOff(BYTE ucCmd);
extern void TPVFactFuncBurnInPattern(void);//DFM rev02 patch note 7
#if (_PANEL_VCOM_ADJUST_FUNCTION == _ON)
extern void TPVFCCheckPanelVcom(void);
#if(0)
extern BYTE TPVFCGetPanelVcom(void);
#endif
extern void TPVFCSetPanelVcom(BYTE setPanelVcom);
#endif

#if(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY)
extern void CFCEdid2EepromHotKey(void);
#endif
extern void TPVDFMInternalADCCheck(void); //DFM rev05 patch note 2
#endif
//20120509 Abel Modify End

#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) || (_D1_INPUT_PORT_TYPE != _D1_NO_PORT) || (_D2_INPUT_PORT_TYPE != _D2_NO_PORT))
#ifndef __TPV_FACTORY_HDCP__
extern void TpvFactHdcpGetFlashHdcpBKsv(WORD usSubAddr, BYTE usLength, BYTE *pReadArray);
extern void TpvFactHdcpGetFlashHdcpKey(WORD usSubAddr, BYTE usLength, BYTE *pReadArray);
#endif
#endif
