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
// ID Code      : RTDOSDTable.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDTABLE__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LEONVO_GREEN_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
BYTE code tOSD_WIN_TYPE0[] =
{
    // border pixel             100 BYTE 0
    (_BORDER0_1_PIXEL | _BORDER0_1_PIXEL),                                                                                                              

    // border color             100 BYTE 1
    ((_CP_GRAY_224 << 4) | _CP_GRAY_224),                                                                                                                   

    // gradient control 0       100 BYTE 2
    (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_3 | _R_GRADIENT_INC | _G_GRADIENT_INC | _B_GRADIENT_INC),     

    // gradient control 1       103 BYTE 1
    (_3_LEVEL_RER_GRADIENT),                                                                                                                        

    // function control         103 BYTE 2
    (_BLEND_ENABLE | _GRADIENT_DISABLE | _GRADIENT_DIRECTION_H | _BORDER_DISABLE | _TYPE_3D_BUTTON_1),                                                  

};

BYTE code tOSD_WIN_TYPE1[] =
{
    // border color and pixel    100 BYTE 0
//    (_BORDER0_1_PIXEL | _BORDER0_1_PIXEL),                                                                                                              
    0x09,

    // border color             100 BYTE 1
//    ((_CP_GREEN << 4) | _CP_GREEN),                                                                                                                   
    0x44,

    // gradient control 0       100 BYTE 2
//    (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_3 | _R_GRADIENT_INC | _G_GRADIENT_INC | _B_GRADIENT_INC),     
    0x00,

    // gradient control 1       103 BYTE 1
//    (_3_LEVEL_RER_GRADIENT),                                                                                                                        
    0x20,

    // function control         103 BYTE 2
//    (_BLEND_ENABLE | _GRADIENT_DISABLE | _GRADIENT_DIRECTION_H | _BORDER_DISABLE | _TYPE_3D_BUTTON_1),                                                  
    0x1f,

};


BYTE code tOSD_iBACK[] =
{
    _iBACK_00, _iBACK_01, _iBACK_02, _NEXT_,
    _iBACK_10, _iBACK_11, _iBACK_12, _END_,
    
};

BYTE code tOSD_iLEFT[] =
{
    _iLEFT_00, _iLEFT_01, _iLEFT_02, _NEXT_,
    _iLEFT_10, _iLEFT_11, _iLEFT_12, _END_,
    
};

BYTE code tOSD_iRIGHT[] =
{
    _iRIGHT_00, _iRIGHT_01, _iRIGHT_02, _NEXT_,
    _iRIGHT_10, _iRIGHT_11, _END_,
    
};

BYTE code tOSD_iOK[] =
{
    _iOK_00, _iOK_01, _iOK_02, _NEXT_,
    _iOK_10, _iOK_11, _iOK_12, _END_,
    
};


BYTE code tOSD_2iKEYITEM1[] =
{
    _2i_ARROW_CANCEL_UP1, _2i_ARROW_CANCEL_UP2, _NEXT_,       
    _2i_ARROW_CANCEL_DOWN1, _2i_ARROW_CANCEL_DOWN2, _2i_ARROW_CANCEL_DOWN3, _END_,
};

BYTE code tOSD_2iKEYITEM2[] =
{
    _2i_ARROW_L1, _2i_ARROW_L2, _END_,       
};

BYTE code tOSD_2iKEYITEM3[] =
{
    _2i_ARROW_R1, _2i_ARROW_R2, _END_,       
};

BYTE code tOSD_2iKEYITEM4[] =
{
    _2i_ARROW_ENTER1, _2i_ARROW_ENTER2, _END_,       
};




//==============================
// Main icon
//==============================

BYTE code tOSD_2iPICTURE[] =
{
    _2iPICTURE_00, _2iPICTURE_01,_2iPICTURE_02, _NEXT_,
    _2iPICTURE_10, _2iPICTURE_11,_2iPICTURE_12, _END_,
    
};
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
BYTE code tOSD_2iLOWBLUELIGHT[] =
{
    _2iLOWBLUELIGHT_00, _2iLOWBLUELIGHT_01,_2iLOWBLUELIGHT_02, _NEXT_,
    _2iLOWBLUELIGHT_10, _2iLOWBLUELIGHT_11,_2iLOWBLUELIGHT_12, _END_,
    
};
#endif
BYTE code tOSD_2iPOSITION[] =
{
    _2iPOSITION_00, _2iPOSITION_01,_2iPOSITION_02, _NEXT_,
    _2iPOSITION_10, _2iPOSITION_11,_2iPOSITION_12, _END_,
    
};

BYTE code tOSD_2iSETUP[] =
{
    _2iSETUP_00, _2iSETUP_01,_2iSETUP_02, _NEXT_,
    _2iSETUP_10, _2iSETUP_11,_2iSETUP_12, _END_,
    
};

BYTE code tOSD_2iPROPERTIES[] =
{
    _2iPROPERTIES_00, _2iPROPERTIES_01,_2iPROPERTIES_02, _NEXT_,
    _2iPROPERTIES_10, _2iPROPERTIES_11,_2iPROPERTIES_12, _END_,
    
};

BYTE code tOSD_2iOPTION[] =
{
    _2iOPTION_00, _2iOPTION_01,_2iOPTION_02, _NEXT_,
    _2iOPTION_10, _2iOPTION_11,_2iOPTION_12, _END_,
    
};

BYTE code tOSD_2iEXIT[] =
{
    _2iEXIT_00, _2iEXIT_01,_2iEXIT_02, _NEXT_,
    _2iEXIT_10, _2iEXIT_11,_2iEXIT_12, _END_,

};
//============================
// sub page:
//============================
BYTE code tOSD_2i_BRIGHTNESS_SUB[] =
{
    _2i_BRI_SUB_00,_2i_BRI_SUB_01,_END_,    
};

BYTE code tOSD_2i_CONTRAST_SUB[] =
{
    _2i_CON_SUB_00,_2i_CON_SUB_01,_END_,     
};
#if(_LENOVO_DPS_SUPPORT == _ON)
BYTE code tOSD_2i_DPS_SUB[] =
{
    _2i_DPS_SUB_00,_2i_DPS_SUB_01,_END_,     
};
#endif

#if(_USER_DCR_FUNCTION == _ON)
BYTE code tOSD_2i_DCR_SUB[] =
{
    _2i_DCR_SUB_00,_2i_DCR_SUB_01,_END_,     
};
#endif

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
BYTE code tOSD_2i_LOWBLUELIGHT_ENABLE[] =
{
    _2i_LOWBLUELIGHT_00,_2i_LOWBLUELIGHT_01,_2i_LOWBLUELIGHT_02,_NEXT_,     
    _2i_LOWBLUELIGHT_03,_2i_LOWBLUELIGHT_04,_2i_LOWBLUELIGHT_05,_END_,     
};

BYTE code tOSD_2i_LOWBLUELIGHT_DISABLE[]=
{
    _2i_LOWBLUELIGHT_00,_2i_LOWBLUELIGHT_01,_2i_LOWBLUELIGHT_02,_NEXT_,     
    _2i_LOWBLUELIGHT_03,_2i_LOWBLUELIGHT_04,_2i_LOWBLUELIGHT_06,_END_,     
};

BYTE code tOSD_LBL_HOTKEY_ICO_ENABLE[] =
{
    _FONT2_LOWBLUELIGHT_START + 0x00 , _FONT2_LOWBLUELIGHT_START + 0x01 , _FONT2_LOWBLUELIGHT_START + 0x02 , _FONT2_LOWBLUELIGHT_START + 0x03 , _FONT2_LOWBLUELIGHT_START + 0x04 , _NEXT_,
    _FONT2_LOWBLUELIGHT_START + 0x05 , _FONT2_LOWBLUELIGHT_START + 0x06 , _FONT2_LOWBLUELIGHT_START + 0x07 , _FONT2_LOWBLUELIGHT_START + 0x08 , _FONT2_LOWBLUELIGHT_START + 0x09 , _NEXT_,
    _FONT2_LOWBLUELIGHT_START + 0x0A , _FONT2_LOWBLUELIGHT_START + 0x0B , _FONT2_LOWBLUELIGHT_START + 0x0C , _FONT2_LOWBLUELIGHT_START + 0x0D , _FONT2_LOWBLUELIGHT_START + 0x0E , _END_,
};

BYTE code tOSD_LBL_HOTKEY_ICO_DISABLE[] =
{
    _FONT2_LOWBLUELIGHT_START + 0x10 , _FONT2_LOWBLUELIGHT_START + 0x11 , _FONT2_LOWBLUELIGHT_START + 0x12 , _FONT2_LOWBLUELIGHT_START + 0x13 , _FONT2_LOWBLUELIGHT_START + 0x14 , _NEXT_,
    _FONT2_LOWBLUELIGHT_START + 0x15 , _FONT2_LOWBLUELIGHT_START + 0x16 , _FONT2_LOWBLUELIGHT_START + 0x17 , _FONT2_LOWBLUELIGHT_START + 0x18 , _FONT2_LOWBLUELIGHT_START + 0x19 , _NEXT_,
    _FONT2_LOWBLUELIGHT_START + 0x1A , _FONT2_LOWBLUELIGHT_START + 0x1B , _FONT2_LOWBLUELIGHT_START + 0x1C , _FONT2_LOWBLUELIGHT_START + 0x1D , _FONT2_LOWBLUELIGHT_START + 0x1E , _END_,
};
#endif

BYTE code tOSD_2i_HPOS_SUB[] =
{
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
	_2i_HPOS_R_00,_2i_HPOS_R_01,_END_,
#else
    _2i_HPOS_SUB_00,_2i_HPOS_SUB_01, _END_,
#endif
};
  
BYTE code tOSD_2i_VPOS_SUB[] =
{
    _2i_VPOS_SUB_00,_2i_VPOS_SUB_01, _END_,
};

BYTE code tOSD_2i_AUTOMATIC_SUB[] =
{
    _2i_AUTOMATIC_SUB_00,_2i_AUTOMATIC_SUB_01, _END_,
};

BYTE code tOSD_2i_MANUAL_SUB[] =
{
    _2i_MANUAL_SUB_00,_2i_MANUAL_SUB_01, _END_,
};

BYTE code tOSD_2i_COLOR_SUB[] =
{
    _2i_COLOR_SUB_00,_2i_COLOR_SUB_01,_END_,
};

BYTE code tOSD_2i_INPUT_SUB[] =
{
    _2i_INPUT_SUB_00,_2i_INPUT_SUB_01,_2i_INPUT_SUB_02, _END_,
};

BYTE code tOSD_2i_SCALING_SUB[] =
{
    _2i_SCALING_SUB_00,_2i_SCALING_SUB_01, _END_,
};
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
BYTE code tOSD_2i_BLUELIGHT_SUB[] =
{
    _2i_BLUELIGHT_SUB_00,_2i_BLUELIGHT_SUB_01, _END_,
};
#endif

#if(_OD_SUPPORT==_ON)			
BYTE code tOSD_2i_OD_SUB[] =
{
    _2i_OD_SUB_00,_2i_OD_SUB_01,_END_,
};
#endif
BYTE code tOSD_2i_INFORMATION_SUB[] =
{
    _2i_INFORMATION_SUB_00,_2i_INFORMATION_SUB_01, _END_,
};

BYTE code tOSD_2i_LANGUAGE_SUB[] =
{
    _2i_LANGUAGE_SUB_00,_2i_LANGUAGE_SUB_01, _END_,
};

BYTE code tOSD_2i_OSDPOS_SUB[] =
{
    _2i_OSDPOS_SUB_00,_2i_OSDPOS_SUB_01, _END_,
};

BYTE code tOSD_2i_RESET_SUB[] =
{
    _2i_RESET_SUB_00,_2i_RESET_SUB_01, _END_,
};

BYTE code tOSD_2i_ACCESSIBILITY_SUB[] =
{
    _2i_ACCESSIBILITY_SUB_00,_2i_ACCESSIBILITY_SUB_01, _END_,
};

BYTE code tOSD_2i_BUTTON_REPEAT_SUB[] =
{
    _2i_BUTTON_REPEAT_SUB_00,_2i_BUTTON_REPEAT_SUB_01,_END_,
};

BYTE code tOSD_2i_MENU_TIMEOUT_SUB[] = 
{
    _2i_MENU_TIMEOUT_SUB_00,_2i_MENU_TIMEOUT_SUB_01,_END_,
};

BYTE code tOSD_2i_VGA_SUB[] =
{
    _2i_INPUT_VGA_00,_2i_INPUT_VGA_01,_2i_INPUT_VGA_02,_END_,
};

BYTE code tOSD_2i_DVI_SUB[] =
{
    _2i_INPUT_DVI_00,_2i_INPUT_DVI_01,_2i_INPUT_DVI_02,_END_,
};



//============================
// ADJ page: Slider L & R picture
//============================
BYTE code tOSD_2i_BRIGHTNESS_L[] =
{
    _2i_BRI_R_00,_2i_BRI_R_01,_END_,     
};

BYTE code tOSD_2i_BRIGHTNESS_R[] =
{
    _2i_BRI_SUB_00,_2i_BRI_SUB_01,_END_,       
};

BYTE code tOSD_2i_CONTRAST_L[] =
{
    _2i_CON_R_00,_2i_CON_R_01,_END_, 
};

BYTE code tOSD_2i_CONTRAST_R[] =
{
    _2i_CON_L_00,_2i_CON_L_01,_END_,             
};


BYTE code tOSD_2i_HPOS_L[] =
{
    _2i_HPOS_SUB_00,	_2i_HPOS_SUB_01,_END_,
};
BYTE code tOSD_2i_HPOS_R[] =
{
    _2i_HPOS_R_00,_2i_HPOS_R_01,_END_,
};
  
BYTE code tOSD_2i_VPOS_L[] =
{
	_2i_VPOS_L_00,_2i_VPOS_L_01,_END_,
};
BYTE code tOSD_2i_VPOS_R[] =
{
	_2i_VPOS_SUB_00,_2i_VPOS_SUB_01,_END_,
};

BYTE code tOSD_2i_OSDHPOS_L[] =
{
    _2i_OSDHPOS_L_00,	_2i_OSDHPOS_L_01,_END_,
};
BYTE code tOSD_2i_OSDHPOS_R[] =
{
    _2i_OSDHPOS_R_00,_2i_OSDHPOS_R_01,_END_,
};
BYTE code tOSD_2i_OSDVPOS_L[] =
{
    _2i_OSDVPOS_L_00,	_2i_OSDVPOS_L_01,_END_,
};
BYTE code tOSD_2i_OSDVPOS_R[] =
{
    _2i_OSDVPOS_R_00,_2i_OSDVPOS_R_01,_END_,
};

//============================
// ADJ page: half picture
//============================
BYTE code tOSD_2i_SUB_PICTURE[] = 
{
    _2i_PICTURE00,_2i_PICTURE01,_2i_PICTURE02,_NEXT_,
    _2i_PICTURE03,_2i_PICTURE04,_2i_PICTURE05,_NEXT_,
    _2i_PICTURE06,_2i_PICTURE07,_2i_PICTURE08,_END_,
};

BYTE code tOSD_2i_BRIGHTNESS_H[] =
{
    _2i_BRI_SUB_00,_2i_BRI_SUB_01, _END_,    
};

BYTE code tOSD_2i_CONTRAST_H[] =
{
    _2i_CON_SUB_00,_2i_CON_SUB_01, _END_,
};
#if(_LENOVO_DPS_SUPPORT == _ON)
BYTE code tOSD_2i_DPS_H[] =
{
    _2i_DPS_H_00,_2i_DPS_H_01, _NEXT_,
    _2i_DPS_H_10,_2i_DPS_H_11, _END_,
};

#endif

#if(_USER_DCR_FUNCTION == _ON)
BYTE code tOSD_2i_DCR_H[] =
{
    _2i_DCR_SUB_00,_2i_DCR_SUB_01, _END_,
};

#endif

BYTE code tOSD_2i_SUB_POSITION[] = 
{
    _2i_POSITION00,_2i_POSITION01,_2i_POSITION02,_NEXT_,
    _2i_POSITION03,_2i_POSITION04,_2i_POSITION05,_NEXT_,
    _2i_POSITION06,_2i_POSITION07,_2i_POSITION08,_END_,
};


BYTE code tOSD_2i_HPOS_H[] =
{
    _2i_HPOS_R_00,_2i_HPOS_R_01,_END_,
};
  
BYTE code tOSD_2i_VPOS_H[] =
{
    _2i_VPOS_SUB_00,_2i_VPOS_SUB_01,_END_,
};

BYTE code tOSD_2i_SUB_MANUAL[] = 
{
    _2i_MANUAL00,_2i_MANUAL01,_2i_MANUAL02,_NEXT_,
    _2i_MANUAL03,_2i_MANUAL04,_2i_MANUAL05,_NEXT_,
    _2i_MANUAL06,_2i_MANUAL07,_2i_MANUAL08,_END_,
};

BYTE code tOSD_2i_MANUAL_H[] =
{
    _2i_MANUAL_SUB_00,_2i_MANUAL_SUB_01,_END_,
};

BYTE code tOSD_2i_SUB_COLOR[] = 
{
    _2i_PROPERTIES00,_2i_PROPERTIES01,_2i_PROPERTIES02,_NEXT_,
    _2i_PROPERTIES03,_2i_PROPERTIES04,_2i_PROPERTIES05,_NEXT_,
    _2i_PROPERTIES06,_2i_PROPERTIES07,_2i_PROPERTIES08,_END_,
};

BYTE code tOSD_2i_COLOR_H[] =
{    	
    _2i_COLOR_SUB_00, _2i_COLOR_SUB_01,_END_,
};

BYTE code tOSD_2i_SCALING_H[] =
{
    _2i_SCALING_SUB_00,   _2i_SCALING_SUB_01, _END_,
};

#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
BYTE code tOSD_2i_BLUELIGHT[] =
{
    _2i_BLUELIGHT_SUB_00,   _2i_BLUELIGHT_SUB_01, _END_,
};
#endif

#if(_OD_SUPPORT==_ON)			
BYTE code tOSD_2i_OD_H[] =
{
    _2i_OD_H_00,_2i_OD_H_01, _NEXT_,
    _2i_OD_H_10,_2i_OD_H_11, _END_,
};
#endif

BYTE code tOSD_2i_SUB_INFORMATION[] = 
{
    _2i_INFORMATION00,_2i_INFORMATION01,_2i_INFORMATION02,_NEXT_,
    _2i_INFORMATION03,_2i_INFORMATION04,_2i_INFORMATION05,_NEXT_,
    _2i_INFORMATION06,_2i_INFORMATION07,_2i_INFORMATION08,_END_,
};


BYTE code tOSD_2i_INFORMATION_H[] =
{
    _2i_INFORMATION_SUB_00, _2i_INFORMATION_SUB_01, _END_,
};

BYTE code tOSD_2i_LANGUAGE_H[] =
{
    _2i_LANGUAGE_SUB_00, _2i_LANGUAGE_SUB_01,_END_,    
};

BYTE code tOSD_2i_OSDPOS_H[] =
{
    _2i_OSDPOS_SUB_00,    _2i_OSDPOS_SUB_01,_END_,
};

BYTE code tOSD_2i_RESET_H[] =
{
    _2i_RESET_SUB_00, _2i_RESET_SUB_01, _END_,    
};

BYTE code tOSD_2i_ACCESSIBILITY_H[] =
{
    _2i_ACCESSIBILITY_SUB_00, _2i_ACCESSIBILITY_SUB_01, _END_,    
};

BYTE code tOSD_2i_INPUT_H[] =
{
   	_2i_INPUT_H_00, _2i_INPUT_H_01, _2i_INPUT_H_02, _NEXT_, 
        _2i_INPUT_H_10, _2i_INPUT_H_11, _2i_INPUT_H_12,_END_,
};


//============================
// slider bar
//============================
#define SLIDER_TL_CHAR  _2BIT_SLIDER_START

BYTE code tOSD_2iSliderBar[] =
{
    SLIDER_TL_CHAR,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 5,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 5,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 5,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 4,
    SLIDER_TL_CHAR + 2, 
    _NEXT_,
    SLIDER_TL_CHAR + 1,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    SLIDER_TL_CHAR + 6,
    0x00,
    0x00,
    0x00,
    0x00,
    SLIDER_TL_CHAR + 6,
    0x00,
    0x00,
    0x00,
    0x00,
    SLIDER_TL_CHAR + 6,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    SLIDER_TL_CHAR + 3, 
    _END_,
};

BYTE code tOSD_2iSliderX[101][4] =
{
    {SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8,SLIDER_TL_CHAR+4,0x00},//0
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},// 1
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},// 2
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//3
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//4
    {SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8,SLIDER_TL_CHAR+4,0x00},//5
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//6
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//7
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//8
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//9
    {SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8,SLIDER_TL_CHAR+4,0x00},//10
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//11
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//12
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//13
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//14
    {SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8,SLIDER_TL_CHAR+4,0x00},//15
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//16
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//17
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//18
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//19

    {SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8,SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6},//20
    //                      {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6},//21xxx
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6},//21
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+27,SLIDER_TL_CHAR+28},//22
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+29,SLIDER_TL_CHAR+30},//23

    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+21,SLIDER_TL_CHAR+22},//24

    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//25
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//26
    {SLIDER_TL_CHAR+23,SLIDER_TL_CHAR+24,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//27
    {SLIDER_TL_CHAR+25,SLIDER_TL_CHAR+26,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//28

    {SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//29
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//30
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//31
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//32
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//33
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//34
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//35
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//36
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//37
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//38
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//39

    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//40
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//41
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//42
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//43
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//44

    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6},//45
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6},//46
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+27,SLIDER_TL_CHAR+28},//47
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+29,SLIDER_TL_CHAR+30},//48

    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+21,SLIDER_TL_CHAR+22},//49

    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//50 25

    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//26
    {SLIDER_TL_CHAR+23,SLIDER_TL_CHAR+24,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//27
    {SLIDER_TL_CHAR+25,SLIDER_TL_CHAR+26,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//28

    {SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//29
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//30
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//31
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//32
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//33
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//34
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//35
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//36
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//37
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//38
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//39

    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//40
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//41
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//42
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//43
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//44

    //ok
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6},//45
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6},//46
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+27,SLIDER_TL_CHAR+28},//47
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+29,SLIDER_TL_CHAR+30},//48

    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+21,SLIDER_TL_CHAR+22},//49

    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//50 75

    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//26
    {SLIDER_TL_CHAR+23,SLIDER_TL_CHAR+24,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//27
    {SLIDER_TL_CHAR+25,SLIDER_TL_CHAR+26,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//28

    {SLIDER_TL_CHAR+5,SLIDER_TL_CHAR+6,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//29
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//30
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//31
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//32
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//33
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//34
    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//35
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//36
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//37
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//38
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//39

    {SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10,SLIDER_TL_CHAR+4,0x00},//40
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//41
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//42
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//43
    //                      {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//44

    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10},//1
    {SLIDER_TL_CHAR+11,SLIDER_TL_CHAR+12,SLIDER_TL_CHAR+4,0x00},//2
    {SLIDER_TL_CHAR+13,SLIDER_TL_CHAR+14,SLIDER_TL_CHAR+15,SLIDER_TL_CHAR+16},//3
    {SLIDER_TL_CHAR+17,SLIDER_TL_CHAR+18,SLIDER_TL_CHAR+19,SLIDER_TL_CHAR+20},//4
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//44
    {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+9,SLIDER_TL_CHAR+10},//1
    //                      {SLIDER_TL_CHAR+4,0x00,SLIDER_TL_CHAR+7,SLIDER_TL_CHAR+8},//5
    {SLIDER_TL_CHAR+31,SLIDER_TL_CHAR+32,SLIDER_TL_CHAR+2,SLIDER_TL_CHAR+3},//5

};
//======================================================================================================================================================== 
//下方提示文字
BYTE code tOSD_sEXITKEY[] = // sExit
{ 
    _mE_,_mx_,_mi_,_mt_,___,_END_,                                 //_ENGLISH
    _mS_,_mo_,_mr_,_mt_,_mi_,_me_,_END_,                     //_FRENCH    
    _mE_,_ms_,_mc_,_mi_,___, _END_,                                 //_ITALIAN
    0x8d,0x8e,___, _END_,                                       //_CHINESE_S     
    _mS_,_ma_,_ml_,_mi_,_mr_,___,_END_,                                //_SPANISH(Esp)
    0xbD,0x8F,___,_END_,                                       //_JAPAN        
    _mV_,_me_,_mr_,_ml_,_ma_,_ms_,_ms_,_me_,_mn_,_END_,            //_GERMAN(Deu)
    0x6a,0x91,0x9e,0x93,0x92,_END_,      //_RUSSIAN        
};

BYTE code tOSD_sCANCELKEY[] = // sCancel
{                                                                
    _mC_,_ma_,_mn_,_mc_,_me_,_ml_, _END_,                      //_ENGLISH 
    _mA_,_mn_,_mn_,_mu_,_ml_,_me_,_mr_,_END_,                 //_FRENCH,   
    _mA_,_mn_,_mn_,_mu_,_ml_,_ml_,_ma_,_END_,                 //_ITALIAN,
    0x85,0x86,___, _END_,                                        //_CHINESE_S 
    _mC_,_ma_,_mn_,_mc_,_me_,_ml_,_ma_,_mr_, _END_,          //_SPANISH(Esp)
    0x2E,0x60,0x6E,0x3D,0x67, _END_,                                        //_JAPAN,
    _mA_,_mb_,_mb_,_mr_,_me_,_mc_,_mh_,_me_,_mn_, _END_,    //_GERMAN(Deu)
    0x78,0x98,0x96,0x8b,0x8e,0x8f, _END_,          //_RUSSIAN    
};

BYTE code tOSD_sOKKEY[] = // sOK
{                                               
    _mO_,_mK_, ___,_END_,                                //_ENGLISH       
    _mO_,_mK_, ___,_END_,                                //_FRENCH            
    _mO_,_mK_,___,_END_,                                //_ITALIAN       
    0x90,0x38,___,_END_,               //_CHINESE_S     
    //_TABSEL_CHT_ENG,_O_,_K_, _END_,               //_CHINESE_S     
    _mA_,_mc_,_me_,_mp_,_mt_,_ma_,_mr_,_END_,   //_SPANISH(Esp)  
    _TABSEL_JAP_ENG,_mO_,_mK_,___, _END_,                          //_JAPAN         
    _mO_,_mK_,___,_END_,                                  //_GERMAN(Deu)   
    0x78,0x6e,___, _END_,                                //_RUSSIAN       
};

//======================================================================================================================================================== 
//Top字串(sub Menu)
//第一層 
BYTE code tOSD_sBRIGHTNESS_CONTRAST[] = // sBrightContrast
{
#if(_LENOVO_DPS_SUPPORT == _ON)
    _B_,_r_,_i_,_g_,_h_,_t_,_n_,_e_,_s_,_s_,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_SLASH,_D_,_P_,_S_,_END_,             //_ENGLISH  
    _L_,_u_,_m_,_i_,_n_,_o_,_s_,_i_,_t_,_EU_0D,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_e_,_SLASH,_D_,_P_,_S_,_END_,  //_FRENCH           
    _L_,_u_,_m_,_i_,_n_,_o_,_s_,_i_,_t_,_EU_1A,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_o_,_SLASH,_D_,_P_,_S_,_END_,   //_ITALIAN
    _TABSEL_CHT_BIG, _CH_20,_CH_21,_CH_22,_CH_23,_CH_24,_CH_25,_CH_26,_CH_27, _SLASH,_CH_9A,_CH_9B,_CH_1C,_END_, //_CHINESE_S
    _B_,_r_,_i_,_l_,_l_,_o_,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_e_,_SLASH,_D_,_P_,_S_,_END_,                               //_SPANISH(Esp) 
    _TABSEL_JAP_BIG1, _JP_00,_JP_01,_JP_02,_JP_03,_JP_04,_JP_05,_JP_06,_JP_07,_JP_08,_JP_09,_SLASH,0xE2,0xE3,0xE4,_END_, //_JAPAN
    _H_,_e_,_l_,_l_,_i_,_g_,_k_,_e_,_i_,_t_,_SLASH,_K_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_SLASH,_D_,_P_,_S_,_END_,                               //_GERMAN(Deu)  
    0x21,0x40,0x38,0x5c,0x3b,0x3e,0x3c,_SLASH,0x23,0x5c,0x4b,0x3e,0x40,0x36,0x3b,0x3e,0x4b,0x5c,0x3b,0x3e,0x3c, _SLASH,0x34,0x25,0x30,_END_,     //_RUSSIAN    
#elif( _USER_DCR_FUNCTION ==_ON)
	_B_,_r_,_i_,_g_,_h_,_t_,_n_,_e_,_s_,_s_,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_SLASH,_D_,_C_,_R_,_END_,			 //_ENGLISH  
	_L_,_u_,_m_,_i_,_n_,_o_,_s_,_i_,_t_,_EU_0D,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_e_,_SLASH,_D_,_C_,_R_,_END_,  //_FRENCH			 
	_L_,_u_,_m_,_i_,_n_,_o_,_s_,_i_,_t_,_EU_1A,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_o_,_SLASH,_D_,_C_,_R_,_END_,   //_ITALIAN
	_TABSEL_CHT_BIG, _CH_20,_CH_21,_CH_22,_CH_23,_CH_24,_CH_25,_CH_26,_CH_27, _SLASH,_CH_C0,_CH_C1,_CH_C2,_CH_24,_CH_25,_CH_26,_CH_27,_END_, //_CHINESE_S
	_B_,_r_,_i_,_l_,_l_,_o_,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_e_,_SLASH,_D_,_C_,_R_,_END_,							   //_SPANISH(Esp) 
	_TABSEL_JAP_BIG1, _JP_00,_JP_01,_JP_02,_JP_03,_JP_04,_JP_05,_JP_06,_JP_07,_JP_08,_JP_09,_SLASH,0xE2,0xE3,0xE4,_END_, //_JAPAN
	_H_,_e_,_l_,_l_,_i_,_g_,_k_,_e_,_i_,_t_,_SLASH,_K_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_SLASH,_D_,_C_,_R_,_END_,							   //_GERMAN(Deu)  
	0x21,0x40,0x38,0x5c,0x3b,0x3e,0x3c,_SLASH,0x23,0x5c,0x4b,0x3e,0x40,0x36,0x3b,0x3e,0x4b,0x5c,0x3b,0x3e,0x3c, _SLASH,0x34,0x2a,0xB4,_END_,	 //_RUSSIAN    

#else
    _B_,_r_,_i_,_g_,_h_,_t_,_n_,_e_,_s_,_s_,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_END_,             //_ENGLISH  
    _L_,_u_,_m_,_i_,_n_,_o_,_s_,_i_,_t_,_EU_0D,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_e_,_END_,  //_FRENCH           
    _L_,_u_,_m_,_i_,_n_,_o_,_s_,_i_,_t_,_EU_1A,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_o_,_END_,   //_ITALIAN
    _TABSEL_CHT_BIG, _CH_20,_CH_21,_CH_22,_CH_23,_CH_24,_CH_25,_CH_26,_CH_27, _END_, //_CHINESE_S
    _B_,_r_,_i_,_l_,_l_,_o_,_SLASH,_C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_e_,_END_,                               //_SPANISH(Esp) 
    _TABSEL_JAP_BIG1, _JP_00,_JP_01,_JP_02,_JP_03,_JP_04,_JP_05,_JP_06,_JP_07,_JP_08,_JP_09,_END_, //_JAPAN
    _H_,_e_,_l_,_l_,_i_,_g_,_k_,_e_,_i_,_t_,_SLASH,_K_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_END_,                               //_GERMAN(Deu)  
    0x21,0x40,0x38,0x5c,0x3b,0x3e,0x3c,_SLASH,0x23,0x5c,0x4b,0x3e,0x40,0x36,0x3b,0x3e,0x4b,0x5c,0x3b,0x3e,0x3c, _END_,     //_RUSSIAN    
#endif
};

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
BYTE code tOSD_sLOWBLUELIGHT[] =
{
    _L_,_o_,_w_,_6P_,_B_,_l_,_u_,_e_,_6P_,_l_,_i_,_g_,_h_,_t_,_END_,  //_ENGLISH 
    0X00,_END_,
    0X00,_END_,
#if 0// lorimiao 20150716 for font size modify   
    _TABSEL_CHT_BIG, _CH_C4,_CH_C5,_CH_C6,_CH_C7,_CH_C8, _END_, //_CHINESE_S
#else
    _TABSEL_CHT_BIG, _CH_BB,_CH_BC,_CH_BD,_CH_BE,_CH_BF, _END_, //_CHINESE_S
#endif
    0X00,_END_,
    0X00,_END_,
    0X00,_END_,
    0X00,_END_,
};

BYTE code tOSD_sLOWBLUELIGHT_ENABLE[] = 
{
    _mS_,_me_,_ml_,_me_,_mc_,_mt_,_4P_,_mt_,_mo_,_4P_,_me_,_mn_,_ma_,_mb_,_ml_,_me_,_4P_,_mL_,_mo_,_mw_,_4P_,_mB_,_ml_,_mu_,_me_,_4P_,_mL_,_mi_,_mg_,_mh_,_mt_,_END_,         //_ENGLISH
    0X00,_END_,
    0X00,_END_,
    0X45,0xa6,0xbb,0x68,0xbe,0x44,0xc1,_END_,//_CHINESE_S
    0X00,_END_,
    0X00,_END_,
    0X00,_END_,
    0X00,_END_,
};

BYTE code tOSD_sLOWBLUELIGHT_DISABLE[] = 
{
    _mS_,_me_,_ml_,_me_,_mc_,_mt_,_4P_,_mt_,_mo_,_4P_,_md_,_mi_,_ms_,_ma_,_mb_,_ml_,_me_,_4P_,_mL_,_mo_,_mw_,_4P_,_mB_,_ml_,_mu_,_me_,_4P_,_mL_,_mi_,_mg_,_mh_,_mt_,_END_,         //_ENGLISH
    0X00,_END_,
    0X00,_END_,
    0X45,0xa6,0xc0,0x68,0xbe,0x44,0xc1,_END_,//_CHINESE_S
    0X00,_END_,
    0X00,_END_,
    0X00,_END_,
    0X00,_END_,
};
#endif

BYTE code tOSD_sIMAGE_POSITION[] =
{
    _I_,_m_,_a_,_g_,_e_,_6P_,_P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_,_END_,  //_ENGLISH 
    _P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_,_6P_,_d_,_e_,_6P_,_EU_1F,_i_,_m_,_a_,_g_,_e_, _END_,                     //_FRENCH        
    _P_,_o_,_s_,_i_,_z_,_i_,_o_,_n_,_e_,_6P_,_i_,_m_,_m_,_a_,_g_,_i_,_n_,_e_,_END_,                     //_ITALIAN       
    _TABSEL_CHT_BIG, _CH_2B,_CH_2C,_CH_2D,_CH_2E,_CH_2F,_CH_30,_CH_28,_CH_29,_CH_2A, _END_, //_CHINESE_S
    _P_,_o_,_s_,_i_,_c_,_i_,_EU_1D,_n_,_6P_,_d_,_e_,_6P_,_l_,_a_,_6P_,_i_,_m_,_a_,_g_,_e_,_n_, _END_,  //_SPANISH(Esp)  
    _TABSEL_JAP_BIG1, _JP_0A,_JP_0B,_JP_0C,_JP_0D,_JP_0E,_JP_0F,_JP_10,_JP_11,_JP_12,_END_,                                                 //_JAPAN
    _B_,_i_,_l_,_d_,_p_,_o_,_s_,_i_,_t_,_i_,_o_,_n_, _END_,                                                        //_GERMAN(Deu)   
    0x24,0x5c,0x4c,0x5c,0x4e,0x4d,0x4b,0x4f,0x4d,0x01,0x4f,0x51,0x5c,0x50,0x40,0x36,0x4e,0x4d,0x4b,0x4f,0x58, _END_,//_RUSSIAN            
};

BYTE code tOSD_sIMAGE_SETUP[] =
{
    _I_,_m_,_a_,_g_,_e_,_6P_,_S_,_e_,_t_,_u_,_p_, _END_,                                                                         //_ENGLISH
    _C_,_o_,_n_,_f_,_i_,_g_,_u_,_r_,_a_,_t_,_i_,_o_,_n_,_6P_,_d_,_e_,_6P_,_EU_1F,_i_,_m_,_a_,_g_,_e_, _END_,  //_FRENCH 
    _I_,_m_,_p_,_o_,_s_,_t_,_a_,_z_,_i_,_o_,_n_,_e_,_6P_,_i_,_m_,_m_,_a_,_g_,_i_,_n_,_e_,_END_,             //_ITALIAN 
    _TABSEL_CHT_BIG, _CH_2B,_CH_2C,_CH_2D,_CH_31,_CH_32,_CH_33, _END_, //_CHINESE_S
    _C_,_o_,_n_,_f_,_i_,_g_,_u_,_r_,_a_,_c_,_i_,_EU_1D,_n_,_6P_,_d_,_e_,_6P_,_l_,_a_,_6P_,_i_,_m_,_a_,_g_,_e_,_n_, _END_,      //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_13,_JP_14,_JP_15,_JP_16,_JP_17,_JP_18,_JP_19,_JP_1A,_JP_1B,_JP_1C,_END_, //_JAPAN
    _B_,_i_,_l_,_d_,_a_,_u_,_f_,_b_,_a_,_u_,_END_,                                                                                        //_GERMAN(Deu)           
    0x35,0x36,0x3b,0x3e,0x40,0x5c,0x3d,0x38,0x36,_6P_,0x4f,0x51,0x5c,0x50,0x40,0x36,0x4e,0x4d,0x4b,0x4f,0x58,_END_,  //_RUSSIAN      
};

BYTE code tOSD_sIMAGE_PROPERTIES[] =
{
    _I_,_m_,_a_,_g_,_e_,_6P_,_P_,_r_,_o_,_p_,_e_,_r_,_t_,_i_,_e_,_s_, _END_,                        //_ENGLISH 
    _P_,_r_,_o_,_p_,_r_,_i_,_EU_0D,_t_,_EU_0D,_s_,_6P_,_d_,_e_,_6P_,_EU_1F,_i_,_m_,_a_,_g_,_e_,_END_,            //_FRENCH
    _P_,_r_,_o_,_p_,_r_,_i_,_e_,_t_,_EU_1A,_6P_,_i_,_m_,_m_,_a_,_g_,_i_,_n_,_e_,_END_,                          //_ITALIAN
    _TABSEL_CHT_BIG, _CH_34,_CH_35,_CH_36,_CH_28,_CH_29,_CH_2A, _END_, //_CHINESE_S
    _P_,_r_,_o_,_p_,_i_,_e_,_d_,_a_,_d_,_e_,_s_,_6P_,_d_,_e_,_6P_,_l_,_a_,_6P_,_i_,_m_,_a_,_g_,_e_,_n_,_END_,  //_SPANISH(Esp)          
    _TABSEL_JAP_BIG1, _JP_1D,_JP_1E,_JP_1F,_JP_20,_JP_21,_JP_22,_JP_23,_JP_24,_JP_25,_JP_26,_END_, //_JAPAN    
    _B_,_i_,_l_,_d_,_m_,_e_,_r_,_k_,_m_,_a_,_l_,_e_,_END_,                                                           //_GERMAN(Deu)           
    0x2a,0x3f,0x5c,0x3d,0x3b,0x3e,0x3f,0x36,_6P_,0x4f,0x51,0x5c,0x50,0x40,0x36,0x4e,0x4d,0x4b,0x4f,0x58, _END_,  //_RUSSIAN      
};

BYTE code tOSD_sOPTIONS[] =
{
    _O_,_p_,_t_,_i_,_o_,_n_,_s_, _END_,    //_ENGLISH 
    _O_,_p_,_t_,_i_,_o_,_n_,_s_, _END_,    //_FRENCH
    _O_,_p_,_z_,_i_,_o_,_n_,_i_,_END_,           //_ITALIAN
    _TABSEL_CHT_BIG, _CH_37,_CH_38,_CH_39, _END_, //_CHINESE_S
    _O_,_p_,_c_,_i_,_o_,_n_,_e_,_s_,_END_,      //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_27,_JP_28,_JP_29,_JP_2A,_JP_2B,_JP_2C, _END_, //_JAPAN
    _O_,_p_,_t_,_i_,_o_,_n_,_e_,_n_,_END_,      //_GERMAN(Deu)           
    0x24,0x36,0x40,0x36,0x41,0x4d,0x3e,0x40,0x37, _END_,  //_RUSSIAN      
};

BYTE code tOSD_sEXIT[]=
{ 
    _E_,_x_,_i_,_t_,_END_,                                 //_ENGLISH
    _S_,_o_,_r_,_t_,_i_,_e_,_END_,                     //_FRENCH    
    _E_,_s_,_c_,_i_, _END_,                                 //_ITALIAN
    _TABSEL_CHT_BIG, _CH_3A,_CH_3B,_CH_3C,_END_, //_CHINESE_S
    _S_,_a_,_l_,_i_,_r_,_END_,                                //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_2D,_JP_2E,_JP_2F ,_END_, //_JAPAN 
    _V_,_e_,_r_,_l_,_a_,_s_,_s_,_e_,_n_,_END_,            //_GERMAN(Deu)
    0x27,0x37,0x48,0x5c,0x42, _END_,      //_RUSSIAN        
};

BYTE code tOSD_sFACTORY_MODE[] =
{	
   _F_,_a_,_c_,_t_,_o_,_r_,_y_,___,_M_,_o_,_d_,_e_,_END_,
};

//第三層 (第三層主畫面Title)
BYTE code tOSD_sBRIGHTNESS[] =
{
    _B_,_r_,_i_,_g_,_h_,_t_,_n_,_e_,_s_,_s_,_END_,        //_ENGLISH
    _L_,_u_,_m_,_i_,_n_,_o_,_s_,_i_,_t_,_EU_0D,_END_,   //_FRENCH
    _L_,_u_,_m_,_i_,_n_,_o_,_s_,_i_,_t_,_EU_1A,_END_,           //_ITALIAN
    _TABSEL_CHT_BIG, _CH_20,_CH_21,_CH_22,_CH_28,_CH_29,_CH_2A, _END_, //_CHINESE_S
    _B_,_r_,_i_,_l_,_l_,_o_,_END_,                               //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_30,_JP_31,_JP_32,_JP_33,_JP_34,_JP_35, _END_, //_JAPAN
    _H_,_e_,_l_,_l_,_i_,_g_,_k_,_e_,_i_,_t_,_END_,                 //_GERMAN(Deu)           
    0x21,0x40,0x38,0x5c,0x3b,0x3e,0x3c, _END_,           //_RUSSIAN         
};


BYTE code tOSD_sCONTRAST[] =
{
    _C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_, _END_,          //_ENGLISH
    _C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_e_,_END_,    //_FRENCH
    _C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_o_,_END_,             //_ITALIAN
    _TABSEL_CHT_BIG, _CH_24,_CH_25,_CH_26,_CH_27,_CH_28,_CH_29,_CH_2A, _END_, //_CHINESE_S
    _C_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_e_,_END_,    //_SPANISH(Esp)          
    _TABSEL_JAP_BIG1, _JP_36,_JP_37,_JP_38,_JP_39,_JP_3A,_JP_3B,_JP_3C,_JP_3D,_JP_3E ,_END_, //_JAPAN
    _K_,_o_,_n_,_t_,_r_,_a_,_s_,_t_,_END_,          //_GERMAN(Deu)           
    0X23,0x5c,0x4b,0x3e,0x40,0x36,0x3b,0x3e,0x4b,0x5c,0x3b,0x3e,0x3c,_END_,//_RUSSIAN         
};
#if(_LENOVO_DPS_SUPPORT == _ON)
BYTE code tOSD_sDPS[] =
{
    _D_,_P_,_S_, _END_,          //_ENGLISH
    _D_,_P_,_S_,_END_,    //_FRENCH
    _D_,_P_,_S_,_END_,             //_ITALIAN
    _TABSEL_CHT_BIG, _CH_9A,_CH_9B,_CH_1C,_END_, //_CHINESE_S
    _D_,_P_,_S_,_END_,    //_SPANISH(Esp)          
    _TABSEL_JAP_BIG1, 0xE2,0xE3,0xE4 ,_END_, //_JAPAN
    _D_,_P_,_S_,_END_,          //_GERMAN(Deu)           
    0x34,0x25,0x30,_END_,//_RUSSIAN         
};
#endif

#if(_USER_DCR_FUNCTION == _ON)
BYTE code tOSD_sDCR[] =
{
    _D_,_C_,_R_,_END_,          //_ENGLISH
    _D_,_C_,_R_,_END_,    //_FRENCH
    _D_,_C_,_R_,_END_,             //_ITALIAN
    _TABSEL_CHT_BIG, _CH_C0,_CH_C1,_CH_C2,_CH_24,_CH_25,_CH_26,_CH_27,_END_, //_CHINESE_S
    _D_,_C_,_R_,_END_,    //_SPANISH(Esp)     
	_TABSEL_JAP_BIG1, 0xE2,0xE3,0xE4 ,_END_, //_JAPAN
    _D_,_C_,_R_,_END_,  //GERMAN(Deu)  
	0x34,0x2a,0xB4,_END_,//_RUSSIAN 		
};
#endif

BYTE code tOSD_sHPOS[] = 
{
    _H_,_o_,_r_,_i_,_z_,_o_,_n_,_t_,_a_,_l_,_6P_,_P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_,_END_,         //_ENGLISH
    _P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_,_6P_,_h_,_o_,_r_,_i_,_z_,_o_,_n_,_t_,_a_,_l_,_e_,_END_,   //_FRENCH
    _P_,_o_,_s_,_i_,_z_,_i_,_o_,_n_,_e_,_6P_,_o_,_r_,_i_,_z_,_z_,_o_,_n_,_t_,_a_,_l_,_e_,_END_,                  //_ITALIAN
    _TABSEL_CHT_BIG, _CH_3D,_CH_3E,_CH_3F,_CH_2E,_CH_2F,_CH_30, _END_, //_CHINESE_S
    _P_,_o_,_s_,_i_,_c_,_i_,_EU_1D,_n_,_6P_,_h_,_o_,_r_,_i_,_z_,_o_,_n_,_t_,_a_,_l_,_END_,     //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_3F,_JP_40,_JP_41,_JP_42,_JP_43,_JP_44, _END_, //_JAPAN
    _H_,_o_,_r_,_i_,_z_,_o_,_n_,_t_,_a_,_l_,_e_,_6P_,_P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_, _END_,   //_GERMAN(Deu)           
    0X22,0x5c,0x40,0x4f,0x51,0x5c,0x4b,0x3e,0x36,0x4c,0x3c,0x4b,0x5c,0x4d,_4P_,0x3a,0x5c,0x4c,0x5c,0x4e,0x4d,0x4b,0x4f,0x4d,_END_, //_RUSSIAN      
};


BYTE code tOSD_sVPOS[] = 
{
    _V_,_e_,_r_,_t_,_i_,_c_,_a_,_l_,_6P_,_P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_,_END_,     //_ENGLISH
    _P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_,_6P_,_v_,_e_,_r_,_t_,_i_,_c_,_a_,_l_,_e_, _END_,     //_FRENCH
    _P_,_o_,_s_,_i_,_z_,_i_,_o_,_n_,_e_,_6P_,_v_,_e_,_r_,_t_,_i_,_c_,_a_,_l_,_e_,_END_,  //_ITALIAN
    _TABSEL_CHT_BIG, _CH_40,_CH_41,_CH_42,_CH_2E,_CH_2F,_CH_30, _END_, //_CHINESE_S
    _P_,_o_,_s_,_i_,_c_,_i_,_EU_1D,_n_,_6P_,_v_,_e_,_r_,_t_,_i_,_c_,_a_,_l_,_END_, //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_45,_JP_46,_JP_47,_JP_48,_JP_49,_JP_4A, _END_, //_JAPAN
    _V_,_e_,_r_,_t_,_i_,_k_,_a_,_l_,_e_,_6P_,_P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_,_END_, //_GERMAN(Deu)          
    0x27,0x4d,0x40,0x3e,0x4f,0x38,0x36,0x4c,0x3c,0x4b,0x5c,0x4d,_4P_,0x3a,0x5c,0x4c,0x5c,0x4e,0x4d,0x4b,0x4f,0x4d, _END_, //_RUSSIAN     
};

BYTE code tOSD_sMANUAL[] = 
{
    _M_,_a_,_n_,_u_,_a_,_l_,_6P_,_i_,_m_,_a_,_g_,_e_,_6P_,_s_,_e_,_t_,_t_,_i_,_n_,_g_,_s_,_END_,                         //_ENGLISH
    _D_,_EU_0D,_f_,_i_,_n_,_i_,_t_,_i_,_o_,_n_,_6P_,_m_,_a_,_n_,_u_,_e_,_l_,_l_,_e_,_6P_,_d_,_e_,_6P_,_EU_1F,_i_,_m_,_a_,_g_,_e_,_END_,  //_FRENCH
    _I_,_m_,_p_,_o_,_s_,_t_,_a_,_z_,_i_,_o_,_n_,_i_,_6P_,_m_,_a_,_n_,_u_,_a_,_l_,_i_,_6P_,_i_,_m_,_m_,_a_,_g_,_i_,_n_,_e_,_END_,      //_ITALIAN
    _TABSEL_CHT_BIG, _CH_43,_CH_44,_CH_45,_CH_28,_CH_29,_CH_2A,_CH_2B,_CH_2C,_CH_2D,_CH_31,_CH_32 ,_CH_33,_END_, //_CHINESE_S 
    _V_,_a_,_l_,_o_,_r_,_e_,_s_,_6P_,_d_,_e_,_6P_,_i_,_m_,_a_,_g_,_e_,_n_,_6P_,_m_,_a_,_n_,_u_,_a_,_l_,_e_,_s_,_END_,                      //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_4B,_JP_4C,_JP_4D,_JP_4E,_JP_4F,_JP_50,_JP_51,_JP_52,_JP_53, _END_, //_JAPAN
    _M_,_a_,_n_,_u_,_e_,_l_,_l_,_e_,_6P_,_B_,_i_,_l_,_d_,_e_,_i_,_n_,_s_,_t_,_e_,_l_,_l_,_u_,_n_,_g_,_e_,_n_,_END_,                    //_GERMAN(Deu)
    0x25,0x5f,0x47,0x4b,0x37,0x4d,_4P_,0x4b,0x36,0x3b,0x3e,0x40,0x5c,0x3d,0x38,0x4f,_4P_,0x4f,0x51,0x5c,0x50,0x40,_END_,                                                                                             //_RUSSIAN                     
};

BYTE code tOSD_sCOLOR[] =
{
    _C_,_o_,_l_,_o_,_r_, _END_,                //_ENGLISH
    _C_,_o_,_u_,_l_,_e_,_u_,_r_, _END_,    //_FRENCH
    _C_,_o_,_l_,_o_,_r_,_e_,_END_,          //_ITALIAN
    _TABSEL_CHT_BIG, _CH_46,_CH_47,_CH_48,_CH_28,_CH_29,_CH_2A, _END_, //_CHINESE_S
    _C_,_o_,_l_,_o_,_r_, _END_,                //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_54,_JP_55,_JP_56,_JP_57,_JP_58,_JP_59,_JP_5A, _END_, //_JAPAN
    _F_,_a_,_r_,_b_,_e_,_END_,                //_GERMAN(Deu)        
    0x29,0x3f,0x4d,0x3e, _END_,          //_RUSSIAN    
};


BYTE code tOSD_sINPUT[] =
{
    _I_,_n_,_p_,_u_,_t_,_4P_,_S_,_i_,_g_,_n_,_a_,_l_, _END_,              //_ENGLISH
    _S_,_i_,_g_,_n_,_a_,_l_,_4P_,_EU_D0,_e_,_n_,_t_,_r_,_EU_0D,_e_,_END_,           //_FRENCH
    _S_,_e_,_g_,_n_,_a_,_l_,_e_,_4P_,_i_,_n_,_p_,_u_,_t_,_END_,                     //_ITALIAN
    _TABSEL_CHT_BIG, _CH_8E,_CH_8F,_CH_90,_CH_91,_CH_92,_CH_93, _END_, //_CHINESE_S
    _S_,_e_,_EU_D8,_a_,_l_,_4P_,_d_,_e_,_4P_,_e_,_n_,_t_,_r_,_a_,_d_,_a_,_END_,   //_SPANISH(Esp)
    _TABSEL_JAP_BIG2,_JP_48,_JP_49,_JP_4A,_JP_4B,_JP_4C,_JP_4D,_JP_4E,_JP_4F,_JP_50,_JP_51,_END_, //_JAPAN
    _E_,_i_,_n_,_g_,_a_,_n_,_g_,_s_,_s_,_i_,_g_,_n_,_a_,_l_,_END_,               //_GERMAN(Deu)    
    0X27,0x48,0x5c,0x42,0x4b,0x5c,0x3d,_4P_,0x3b,0x4f,0x4a,0x4b,0x36,0x4c, _END_,       //_RUSSIAN    
};

BYTE code tOSD_sSCALING[] =
{
    _S_,_c_,_a_,_l_,_i_,_n_,_g_,_END_,                                        //_ENGLISH
    _E_,_c_,_h_,_e_,_l_,_l_,_e_,_END_,                                               //_FRENCH
    _S_,_e_,_g_,_n_,_a_,_l_,_e_,_4P_,_i_,_n_,_p_,_u_,_t_,_END_,                  //_ITALIAN
    _TABSEL_CHT_BIG, _CH_A2,_CH_A3,_CH_A4,_CH_A5,_CH_A6,_CH_A7,_CH_28,_CH_29,_CH_2A, _END_, //_CHINESE_S
    _S_,_e_,_EU_D8,_a_,_l_,_4P_,_d_,_e_,_4P_,_e_,_n_,_t_,_r_,_a_,_d_,_a_,_END_,   //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_5B,_JP_5C,_JP_5D,_JP_5E,_JP_5F,_JP_60, _END_, //_JAPAN
    _S_,_k_,_a_,_l_,_i_,_e_,_r_,_e_,_n_,_END_,                                     //_GERMAN(Deu)   
    0x31,0x36,0x3b,0x1f,0x3e,0x36,0x50,0x4f,0x40,0x5c,0x3f,0x36,0x4b,0x4f,0x4d,_END_,    //_RUSSIAN    
};

#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
BYTE code tOSD_sBLUELIGHT[] =
{
    _L_,_o_,_w_,_4P_,_B_,_l_,_u_,_e_,_4P_,_L_,_i_,_g_,_h_,_t_,_END_,//_ENGLISH
    _L_,_o_,_w_,_4P_,_B_,_l_,_u_,_e_,_4P_,_L_,_i_,_g_,_h_,_t_,_END_,//_FRENCH
    _L_,_o_,_w_,_4P_,_B_,_l_,_u_,_e_,_4P_,_L_,_i_,_g_,_h_,_t_,_END_,//_ITALIAN
    _TABSEL_CHT_BIG,_CH_BB,_CH_BC,_CH_BD,_CH_BE,_CH_BF,_END_,//_CHINESE_S   
    _L_,_o_,_w_,_4P_,_B_,_l_,_u_,_e_,_4P_,_L_,_i_,_g_,_h_,_t_,_END_,//_SPANISH(Esp)
    _L_,_o_,_w_,_4P_,_B_,_l_,_u_,_e_,_4P_,_L_,_i_,_g_,_h_,_t_,_END_,//_JAPAN
    _L_,_o_,_w_,_4P_,_B_,_l_,_u_,_e_,_4P_,_L_,_i_,_g_,_h_,_t_,_END_,//_GERMAN(Deu)   
    _L_,_o_,_w_,_4P_,_B_,_l_,_u_,_e_,_4P_,_L_,_i_,_g_,_h_,_t_,_END_,//_RUSSIAN    
};
#endif

#if(_OD_SUPPORT==_ON)			
BYTE code tOSD_sOD[] =
{
    _O_,_v_,_e_,_r_,_4P_,_D_,_r_,_i_,_v_,_e_, _END_,//_ENGLISH
    _V_,_i_,_t_,_e_,_s_,_s_,_e_,_4P_,_m_,_u_,_l_,_t_,_i_,_p_,_l_,_i_,_EU_0D,_e_,_END_,//_FRENCH
    _O_,_v_,_e_,_r_,_4P_,_D_,_r_,_i_,_v_,_e_,_END_,//_ITALIAN
    _TABSEL_CHT_BIG,_CH_C0,_CH_C1,_CH_C2,_CH_C3,_CH_C4,_CH_C5,_END_,//_CHINESE_S   
    _S_,_o_,_b_,_r_,_e_,_c_,_a_,_r_,_g_,_a_,_END_,   //_SPANISH(Esp)
    _TABSEL_JAP_BIG1,0xe5,0xe6,0xe7,0xe8, 0xe9,0xea,0xeb,0xec,0xed,_END_,  //_JAPAN     
    _EU_1C,_b_,_e_,_r_,_s_,_t_,_e_,_u_,_e_,_r_,_u_,_n_,_g_,_END_,//_GERMAN(Deu)   
    0x23,0x5c,0x41,0x3a,0x4d,0x4b,0x3b,0x36,0x6f,0x4f,0x58,_4P_,0x3f,0x40,0x4d,0x41,0x4d,0x4b,0x4f,_4P_,0x5c,0x3e,0x38,0x4c,0x4f,0x38,0x36,_END_,//_RUSSIAN
};
#endif
BYTE code tOSD_sINFORMATION[] =
{
    _I_,_n_,_f_,_o_,_r_,_m_,_a_,_t_,_i_,_o_,_n_, _END_,          //_ENGLISH
    _I_,_n_,_f_,_o_,_r_,_m_,_a_,_t_,_i_,_o_,_n_,_s_,_END_,    //_FRENCH
    _I_,_n_,_f_,_o_,_r_,_m_,_a_,_z_,_i_,_o_,_n_,_i_, _END_,    //_ITALIAN
    _TABSEL_CHT_BIG, _CH_52,_CH_53,_CH_54, _END_, //_CHINESE_S
    _I_,_n_,_f_,_o_,_r_,_m_,_a_,_c_,_i_,_EU_1D,_n_,_END_,      //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_83,_JP_84,_JP_85,_JP_86,_JP_87,_JP_88, _END_, //_JAPAN
    _I_,_n_,_f_,_o_,_r_,_m_,_a_,_t_,_i_,_o_,_n_,_END_,          //_GERMAN(Deu)
    0x2b,0x4b,0x49,0x5c,0x40,0x41,0x36,0x20,0x4f,0x58,_END_,       //_RUSSIAN     
};


BYTE code tOSD_sLANGUAGE[] =
{
    _M_,_e_,_n_,_u_,_6P_,_L_,_a_,_n_,_g_,_u_,_a_,_g_,_e_, _END_,                                                                //_ENGLISH
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _L_,_a_,_n_,_g_,_u_,_e_,_6P_,_EU_D0,_a_,_f_,_f_,_i_,_c_,_h_,_a_,_g_,_e_,_6P_,_d_,_u_,_6P_,_m_,_e_,_n_,_u_,_END_,  //_FRENCH
#else
    _L_,_a_,_n_,_g_,_u_,_e_,_6P_,_g_,_a_,_f_,_f_,_i_,_c_,_h_,_a_,_g_,_e_,_6P_,_d_,_u_,_p_,_m_,_e_,_n_,_u_,_END_,  //_FRENCH
#endif
    _L_,_i_,_n_,_g_,_u_,_a_,_6P_,_m_,_e_,_n_,_u_,_END_,       //_ITALIAN
    _TABSEL_CHT_BIG, _CH_5D,_CH_5E,_CH_5F,_CH_60,_CH_61,_CH_62, _END_, //_CHINESE_S
    _I_,_d_,_i_,_o_,_m_,_a_,_6P_,_d_,_e_,_l_,_6P_,_m_,_e_,_n_,0x1e,_END_,    //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_9B,_JP_9C,_JP_9D,_JP_9E,_JP_9F,_JP_A0,_JP_A1,_JP_A2,_JP_A3,_JP_A4,_JP_A5,_JP_A6,_END_, //_JAPAN
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _M_,_e_,_n_,_EU_1C,_s_,_p_,_r_,_a_,_c_,_h_,_e_,_END_,                        //_GERMAN(Deu)
#else
    _M_,_e_,_n_,0x07,_s_,_p_,_r_,_a_,_c_,_h_,_e_,_END_,                        //_GERMAN(Deu)
#endif
    0x21,0x51,0x37,0x38,_4P_,0x41,0x4d,0x4b,0x39, _END_,                                       //_RUSSIAN     
};

BYTE code tOSD_sOSDPOS[] =
{
    _M_,_e_,_n_,_u_,_6P_,_P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_, _END_,                   //_ENGLISH
    _P_,_o_,_s_,_i_,_t_,_i_,_o_,_n_,_6P_,_d_,_u_,_6P_,_m_,_e_,_n_,_u_,_END_,  //_FRENCH
    _P_,_o_,_s_,_i_,_z_,_i_,_o_,_n_,_e_,_6P_,_m_,_e_,_n_,_u_, _END_,             //_ITALIAN
    _TABSEL_CHT_BIG, _CH_5D,_CH_5E,_CH_5F,_CH_2E,_CH_2F,_CH_30, _END_, //_CHINESE_S
    _P_,_o_,_s_,_i_,_c_,_i_,_EU_1D,_n_,_6P_,_d_,_e_,_l_,_6P_,_m_,_e_,_n_,_EU_1E,_END_,     //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_A7,_JP_A8,_JP_A9,_JP_AA,_JP_AB,_JP_AC,_JP_AD,_JP_AE,_JP_AF, _END_, //_JAPAN
    _M_,_e_,_n_,_EU_1C,_p_,_o_,_s_,_i_,_t_,_i_,_o_,_n_,_END_,                            //_GERMAN(Deu)
    0X24,0x5c,0x4c,0x5c,0x4e,0x4d,0x4b,0x4f,0x4d,_4P_,0x41,0x4d,0x4b,0x39,_END_,  //_RUSSIAN 
};


BYTE code tOSD_sFACTORY_DEFAULT[] = //sReset
{
    _bF_, _ba_, _bc_, _bt_, _bo_, _br_, _by_, _6P_, _bD_, _be_, _bf_, _ba_, _bu_, _bl_, _bt_, _END_, //_ENGLISH
    _bV_,_ba_,_bl_,_be_,_bu_,_br_,_bs_,_6P_,_bu_,_bs_,_bi_,_bn_,_be_,_6P_,_bd_,_EU_0D,_bf_,_bi_,_bn_,_bi_,_be_,_bs_,_6P_,_bp_,_ba_,_br_,_6P_,_bd_,_EU_0D,_bf_,_ba_,_bu_,_bt_,_END_,  //_FRENCH
    _bP_,_br_,_be_,_bd_,_be_,_bf_,_bi_,_bn_,_bi_,_bt_,_bo_,_END_,                                   //_ITALIAN
#if 0// lorimiao 20150716 for font size modify   
    _TABSEL_CHT_BIG, _CH_63,_CH_64,_CH_65,_CH_C1,_CH_C2,_CH_C3, _END_, //_CHINESE_S
#else
    _TABSEL_CHT_BIG, _CH_63,_CH_64,_CH_65,_CH_B8,_CH_B9,_CH_BA, _END_, //_CHINESE_S
#endif
    _bV_, _ba_, _bl_, _bo_, _br_, _be_, _bs_, _6P_, _bp_, _bo_, _br_, _6P_, _bo_, _bm_,_bi_,_bs_,_bi_,_EU_1D,_bn_,_6P_,_bd_,_be_,_6P_,_bf_,_EU_0F,_bb_,_br_,_bi_,_bc_,_ba_,_END_,    //_SPANISH(Esp)
    _TABSEL_JAP_BIG1, _JP_B0,_JP_B1,_JP_B2,_JP_B3,_JP_B4,_JP_B5,_JP_B6,_JP_B7,_JP_B8,_JP_B9,_JP_BA,_END_, //_JAPAN
    _bW_,_be_,_br_,_bk_,_bs_,_be_,_bi_,_bt_,_bi_,_bg_,_be_,_6P_,_bS_,_bt_,_ba_,_bn_,_bd_,_ba_,_br_,_bd_,_be_,_bi_,_bn_,_bs_,_bt_,_be_,_bl_,_bl_,_bu_,_bn_,_bg_,_END_,         //_GERMAN(Deu)
    0x26,0x36,0x3f,0x5c,0x42,0x3b,0x38,0x4f,0x4d,_6P_,0x4b,0x36,0x3b,0x3e,0x40,0x5c,0x3d,0x38,0x4f,_END_,                                                 //_RUSSIAN 
};



BYTE code tOSD_sACCESSIBILITY[] = // sAccessibility                                                                                                     
{                                                                                                                                    
    _A_,_c_,_c_,_e_,_s_,_s_,_i_,_b_,_i_,_l_,_i_,_t_,_y_, _END_,       //_ENGLISH                                
    _A_,_c_,_c_,_e_,_s_,_s_,_i_,_b_,_i_,_l_,_i_,_t_,_EU_0D,_END_,   //_FRENCH                                 
    _A_,_c_,_c_,_e_,_s_,_s_,_i_,_b_,_i_,_l_,_i_,_t_,_EU_1A, _END_,   //_ITALIAN                            
    _TABSEL_CHT_BIG, _CH_6A,_CH_6B,_CH_6C,_CH_6D,_CH_6E,_CH_6F,_CH_70,_CH_71, _END_, //_CHINESE_S
    _A_,_c_,_c_,_e_,_s_,_i_,_b_,_i_,_l_,_i_,_d_,_a_,_d_,_END_,                //_SPANISH(Esp)                           
    _TABSEL_JAP_BIG1, _JP_BB,_JP_BC,_JP_BD,_JP_BE,_JP_BF,_JP_C0,_JP_C1,_JP_C2,_JP_C3,_JP_C4,_JP_C5,_END_, //_JAPAN
    _Z_,_u_,_g_,_r_,_i_,_f_,_f_,_s_,_m_,_EU_1B,_g_,_l_,_i_,_c_,_h_,_k_,_e_,_i_,_t_,_END_, //_GERMAN(Deu)         
    0x28,0x5c,0x3b,0x3e,0x5f,0x3a,0x4b,0x5c,0x3b,0x3e,0x3c,_END_,      //_RUSSIAN                 
};                                                                                                                                   



//========================================================================================================================================================
//Mid字串( Colon 說明文字第一行)
BYTE code tOSD_sBRIGHTNESS_COLON[] = //sBrightness1
{
    _mB_,_mr_,_mi_,_mg_,_mh_,_mt_,_mn_,_me_,_ms_,_ms_,_COLON,_END_,        //_ENGLISH
    _mL_,_mu_,_mm_,_mi_,_mn_,_mo_,_ms_,_mi_,_mt_,_EU_C2,_COLON,_END_,   //_FRENCH
    _mL_,_mu_,_mm_,_mi_,_mn_,_mo_,_ms_,_mi_,_mt_,_EU_C3,_COLON,_END_,           //_ITALIAN
    0x22,0x21,0x25,0x26,_COLON, _END_,                               //_CHINESE_S 
    _mB_,_mr_,_mi_,_ml_,_ml_,_mo_,_COLON,_END_,                               //_SPANISH(Esp)
    0x89,0x81,0x7E,0xb8, _COLON,_END_,                                                 //_JAPAN
    _mH_,_me_,_ml_,_ml_,_mi_,_mg_,_mk_,_me_,_mi_,_mt_,_COLON,_END_,                 //_GERMAN(Deu)           
    0x69,0x90,0x99,0x93,0x9a,0x98,0x80,_COLON,_END_,           //_RUSSIAN         
};

BYTE code tOSD_sCONTRAST_COLON[] = // sContrast1
{
    _mC_,_mo_,_mn_,_mt_,_mr_,_ma_,_ms_,_mt_,_COLON, _END_,          //_ENGLISH
    _mC_,_mo_,_mn_,_mt_,_mr_,_ma_,_ms_,_mt_,_me_,_COLON,_END_,    //_FRENCH
    _mC_,_mo_,_mn_,_mt_,_mr_,_ma_,_ms_,_mt_,_mo_,_COLON,_END_,             //_ITALIAN
    0x23,0x24,0x21,0x25,0x26,_COLON, _END_,             //_CHINESE_S 
    _mC_,_mo_,_mn_,_mt_,_mr_,_ma_,_ms_,_mt_,_me_,_COLON,_END_,    //_SPANISH(Esp)          
    0x34,0x6E,0x4A,0x64,0x3A,0x4A,0x7E,0xb8,_COLON, _END_,    //_JAPAN
    _mK_,_mo_,_mn_,_mt_,_mr_,_ma_,_ms_,_mt_,_COLON, _END_,          //_GERMAN(Deu)           
    0x6e,0x93,0x8e,0x98,0x90,0x8f,0x9a,0x98,0x8e,0x93,0x9a,0x98,0x80,_COLON,_END_,//_RUSSIAN         
};

#if(_LENOVO_DPS_SUPPORT == _ON)
BYTE code tOSD_sDPS_COLON[] = // sContrast1
{
    _mD_,_mP_,_mS_,_COLON, _END_,          //_ENGLISH
    _mD_,_mP_,_mS_,_COLON,_END_,    //_FRENCH
    _mD_,_mP_,_mS_,_COLON,_END_,             //_ITALIAN
    0x1a,0xBA,0x1f,_COLON,_END_,             //_CHINESE_S 
    _mD_,_mP_,_mS_,_COLON,_END_,    //_SPANISH(Esp)          
    0x1A,0xD4,0x1F,_COLON,_END_,    //_JAPAN
    _mD_,_mP_,_mS_,_COLON, _END_,          //_GERMAN(Deu)           
    0x60,0x72,0x7B,_COLON,_END_,//_RUSSIAN         
};
#endif

#if(_USER_DCR_FUNCTION == _ON)
BYTE code tOSD_sDCR_COLON[] = // sContrast1
{
    _mD_,_mC_,_mR_,_COLON, _END_,          //_ENGLISH
    _mD_,_mC_,_mR_,_COLON,_END_,    //_FRENCH
    _mD_,_mC_,_mR_,_COLON,_END_,             //_ITALIAN
    0x32,0xc2,0x23,0x24,0x21,_COLON,_END_,             //_CHINESE_S 
    _mD_,_mC_,_mR_,_COLON,_END_,    //_SPANISH(Esp)          
	0x1A,0x1B,0x1F,_COLON,_END_,	//_JAPAN
    _mD_,_mC_,_mR_,_COLON, _END_,          //_GERMAN(Deu)           
	0x60,0x74,0x6B,_COLON,_END_,//_RUSSIAN		   
};
#endif

BYTE code tOSD_sHPOS_COLON[] = //sHorizontalPosition1
{
    _mH_,_mo_,_mr_,_mi_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_4P_,_mP_,_mo_,_ms_,_mi_,_mt_,_mi_,_mo_,_mn_,_COLON,_END_,         //_ENGLISH
    _mP_,_mo_,_ms_,_mi_,_mt_,_mi_,_mo_,_mn_,_4P_,_mh_,_mo_,_mr_,_mi_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_me_,_COLON,_END_,   //_FRENCH
    _mP_,_mo_,_ms_,_mi_,_mz_,_mi_,_mo_,_mn_,_me_,_4P_,_mo_,_mr_,_mi_,_mz_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_me_,_COLON,_END_,                  //_ITALIAN
    0x2F,0x30,0x2D,0x2E,_COLON,_END_,                                                                                      //_CHINESE_S 
    _mP_,_mo_,_ms_,_mi_,_mc_,_mi_,_EU_C4,_mn_,_4P_,_mh_,_mo_,_mr_,_mi_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_COLON,_END_,     //_SPANISH(Esp)
    0xa3,0x95,0xa7,0xbA,_COLON,_END_,                                                                                      //_JAPAN
    _mH_,_mo_,_mr_,_mi_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_me_,_4P_,_mP_,_mo_,_ms_,_mi_,_mt_,_mi_,_mo_,_mn_,_COLON, _END_,   //_GERMAN(Deu)           
    0x73,0x93,0x90,0x94,0x85,0x93,0x8e,0x98,0x8f,0x86,0x80,0x8e,0x93,0x8b,_4P_,0x89,0x93,0x86,0x93,0x8a,0x8b,0x8e,0x94,0x8b,_COLON,_END_, //_RUSSIAN      
};

BYTE code tOSD_sVPOS_COLON[] = // sVerticalPosition1
{
    _mV_,_me_,_mr_,_mt_,_mi_,_mc_,_ma_,_ml_,_4P_,_mP_,_mo_,_ms_,_mi_,_mt_,_mi_,_mo_,_mn_,_COLON, _END_,     //_ENGLISH
    _mP_,_mo_,_ms_,_mi_,_mt_,_mi_,_mo_,_mn_,_4P_,_mv_,_me_,_mr_,_mt_,_mi_,_mc_,_ma_,_ml_,_me_,_COLON, _END_,     //_FRENCH
    _mP_,_mo_,_ms_,_mi_,_mz_,_mi_,_mo_,_mn_,_me_,_4P_,_mv_,_me_,_mr_,_mt_,_mi_,_mc_,_ma_,_ml_,_me_,_COLON,_END_,                  //_ITALIAN
    0x33,0x34,0x2D,0x2E,_COLON,_END_,                                                                            //_CHINESE_S
    _mP_,_mo_,_ms_,_mi_,_mc_,_mi_,_EU_C4,_mn_,_4P_,_mv_,_me_,_mr_,_mt_,_mi_,_mc_,_ma_,_ml_,_COLON,_END_,                        //_SPANISH(Esp)
    0x7B,0xb9,0xa7,0xbA,_COLON, _END_,                                                                            //_JAPAN
    _mV_,_me_,_mr_,_mt_,_mi_,_mk_,_ma_,_ml_,_me_,_4P_,_mP_,_mo_,_ms_,_mi_,_mt_,_mi_,_mo_,_mn_,_COLON,_END_,                       //_GERMAN(Deu)          
    0x6a,0x8b,0x90,0x98,0x94,0x99,0x8f,0x86,0x80,0x8e,0x93,0x8b,_4P_,0x89,0x93,0x86,0x93,0x8a,0x8b,0x8e,0x94,0x8b,_COLON, _END_, //_RUSSIAN     
};

BYTE code tOSD_sAUTOMATIC_COLON[]= //sAutomatic1
{
    _mA_,_mu_,_mt_,_mo_,_mm_,_ma_,_mt_,_mi_,_mc_,_COLON, _END_,    //_ENGLISH
    _mA_,_mu_,_mt_,_mo_,_mm_,_ma_,_mt_,_mi_,_mq_,_mu_,_me_,_COLON,_END_,    //_FRENCH
    _mA_,_mu_,_mt_,_mo_,_mm_,_ma_,_mt_,_mi_,_mc_,_mo_,_COLON,_END_,         //_ITALIAN
    0x35,0x32,0x37,0x38,_COLON, _END_,                      //_CHINESE_S
    _mA_,_mu_,_mt_,_mo_,_mm_,_EU_C5,_mt_,_mi_,_mc_,_ma_,_COLON,_END_,      //_SPANISH(Esp)     
    0xbE,0x80,0x7E,0xb8,_COLON, _END_,                      //_JAPAN    
    _mA_,_mu_,_mt_,_mo_,_mm_,_ma_,_mt_,_mi_,_ms_,_mc_,_mh_,_COLON,_END_,    //_GERMAN(Deu)
    0x70,0x95,0x98,0x93,0x96,0x8f,0x98,0x94,0x97,0x8b,0x9a,0x99,0x94, _COLON,_END_,//_RUSSIAN    
};


BYTE code tOSD_sMANUAL_COLON[] = //sManual1
{
    _mM_,_ma_,_mn_,_mu_,_ma_,_ml_,_COLON,_END_,                         //_ENGLISH
    _mM_,_ma_,_mn_,_mu_,_me_,_ml_,_ml_,_me_,_COLON,_END_,  //_FRENCH
    _mM_,_ma_,_mn_,_mu_,_ma_,_ml_,_me_,_COLON,_END_,      //_ITALIAN
    0x36,0x32,0x37,0x38,_COLON, _END_, //_CHINESE_S
    _mM_,_ma_,_mn_,_mu_,_ma_,_ml_,_COLON,_END_,                      //_SPANISH(Esp)
    0xa2,0x80,0x7E,0xb8,_COLON, _END_,  //_JAPAN    
    _mM_,_ma_,_mn_,_mu_,_me_,_ml_,_ml_,_COLON,_END_,                    //_GERMAN(Deu)
    0x6a,0x90,0x84,0x97,0x8e,0x84,0x9b,_COLON,_END_,                                                                                             //_RUSSIAN                     
};

BYTE code tOSD_sCOLOR_COLON[] = //sColor1
{
    _mC_,_mo_,_ml_,_mo_,_mr_,_COLON, _END_,                //_ENGLISH
    _mC_,_mo_,_mu_,_ml_,_me_,_mu_,_mr_,_COLON, _END_,    //_FRENCH
    _mC_,_mo_,_ml_,_mo_,_mr_,_me_,_COLON,_END_,          //_ITALIAN
    0x41,0x8F,0x25,0x26,_COLON, _END_,          //_CHINESE_S
    _mC_,_mo_,_ml_,_mo_,_mr_,_COLON, _END_,                //_SPANISH(Esp)
    0x2C,0x64,0xc1,0x7E,0xb8, _COLON,_END_,                   //_JAPAN     
    _mF_,_ma_,_mr_,_mb_,_me_,_COLON,_END_,                //_GERMAN(Deu)        
    0x6f,0x95,0x8b,0x98, _COLON,_END_,          //_RUSSIAN    
};

BYTE code tOSD_sINPUT_COLON[] =
{
    _mI_,_mn_,_mp_,_mu_,_mt_,_4P_,_mS_,_mi_,_mg_,_mn_,_ma_,_ml_,_COLON, _END_,              //_ENGLISH
    _mS_,_mi_,_mg_,_mn_,_ma_,_ml_,_4P_,_EU_C9,_me_,_mn_,_mt_,_mr_,_EU_C2,_me_,_COLON,_END_,           //_FRENCH
    _mS_,_me_,_mg_,_mn_,_ma_,_ml_,_me_,_4P_,_mi_,_mn_,_mp_,_mu_,_mt_,_COLON,_END_,                     //_ITALIAN
    0x76,0x77,0x47,0x6F,_COLON,_END_,                                                 //_CHINESE_S
    _mS_,_me_,_EU_E5,_ma_,_ml_,_4P_,_md_,_me_,_4P_,_me_,_mn_,_mt_,_mr_,_ma_,_md_,_ma_,_COLON,_END_,   //_SPANISH(Esp)
    0x9B,0x8E,0xaD,0x85,0x51,0xaF,0xb6, _COLON,_END_,                                                 //_JAPAN
    _mE_,_mi_,_mn_,_mg_,_ma_,_mn_,_mg_,_ms_,_ms_,_mi_,_mg_,_mn_,_ma_,_ml_,_COLON,_END_,               //_GERMAN(Deu)    
    0x6a,0x9e,0x93,0x92,0x8e,0x93,0x81,_4P_,0x9a,0x94,0x88,0x8e,0x8f,0x86, _COLON,_END_,       //_RUSSIAN    
};

BYTE code tOSD_sSCALING_COLON[] = //sScaling_Color
{
    _mS_,_mc_,_ma_,_ml_,_mi_,_mn_,_mg_,_COLON, _END_,                                        //_ENGLISH
    _mE_,_mc_,_mh_,_me_,_ml_,_ml_,_me_,_COLON,_END_,                                               //_FRENCH
    _mS_,_mc_,_ma_,_ml_,_ma_,_COLON,_END_,                  //_ITALIAN
    0x9e,0x9f,0x24,0x9d,0x25,0x26, _COLON,_END_,                            //_CHINESE_S   
    _mE_,_ms_,_mc_,_ma_,_ml_,_ma_,_COLON,_END_,   //_SPANISH(Esp)
    0xc5,0xc6,0x7E,0xb8,_COLON, _END_,  //_JAPAN     
    _mS_,_mk_,_ma_,_ml_,_mi_,_me_,_mr_,_me_,_mn_,_COLON,_END_,                                     //_GERMAN(Deu)   
    0x76,0x8f,0x9a,0x87,0x98,0x8f,0x82,0x94,0x90,0x93,0x95,0x8f,0x8e,0x94,0x8b ,_COLON,_END_,    //_RUSSIAN    
};

#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
BYTE code tOSD_sBLUELIGHT_COLON[] = //sScaling_Color
{
    _mL_,_mo_,_mw_,_4P_,_mB_,_ml_,_mu_,_me_,_4P_,_mL_,_mi_,_mg_,_mh_,_mt_, _END_,//_ENGLISH
    _mL_,_mo_,_mw_,_4P_,_mB_,_ml_,_mu_,_me_,_4P_,_mL_,_mi_,_mg_,_mh_,_mt_, _END_,//_FRENCH
    _mL_,_mo_,_mw_,_4P_,_mB_,_ml_,_mu_,_me_,_4P_,_mL_,_mi_,_mg_,_mh_,_mt_, _END_,//_ITALIAN
    0xbe,0x44,0xc1,_END_,//_CHINESE_S   
    _mL_,_mo_,_mw_,_4P_,_mB_,_ml_,_mu_,_me_,_4P_,_mL_,_mi_,_mg_,_mh_,_mt_, _END_,//_SPANISH(Esp)
    _mL_,_mo_,_mw_,_4P_,_mB_,_ml_,_mu_,_me_,_4P_,_mL_,_mi_,_mg_,_mh_,_mt_,//_JAPAN     
    _mL_,_mo_,_mw_,_4P_,_mB_,_ml_,_mu_,_me_,_4P_,_mL_,_mi_,_mg_,_mh_,_mt_, _END_,//_GERMAN(Deu)   
    _mL_,_mo_,_mw_,_4P_,_mB_,_ml_,_mu_,_me_,_4P_,_mL_,_mi_,_mg_,_mh_,_mt_, _END_,//_RUSSIAN    
};
#endif

#if(_OD_SUPPORT==_ON)			
BYTE code tOSD_sOD_COLON[] = 
{
    _mO_,_mv_,_me_,_mr_,_4P_,_mD_,_mr_,_mi_,_mv_,_me_,_COLON, _END_,//_ENGLISH
    _mV_,_mi_,_mt_,_me_,_ms_,_ms_,_me_,_4P_,_mm_,_mu_,_ml_,_mt_,_mi_,_mp_,_ml_,_mi_,_EU_C2,_me_,_COLON,_END_,//_FRENCH
    _mO_,_mv_,_me_,_mr_,_4P_,_mD_,_mr_,_mi_,_mv_,_me_,_COLON,_END_,//_ITALIAN
    0x32,0xC2,0x54,0x55, _COLON,_END_,//_CHINESE_S   
    _mS_,_mo_,_mb_,_mr_,_me_,_mc_,_ma_,_mr_,_mg_,_ma_,_COLON,_END_,   //_SPANISH(Esp)
    0x2a,0xc1,0x53,0xc1, 0x4c,0x64,0x25,0x57,_COLON,_END_,  //_JAPAN     
    _EU_C6,_mb_,_me_,_mr_,_ms_,_mt_,_me_,_mu_,_me_,_mr_,_mu_,_mn_,_mg_,_COLON,_END_,                                     //_GERMAN(Deu)   
    0x6e,0x93,0x96,0x89,0x8b,0x8e,0x9a,0x8f,0x9d,0x94,0x83,_4P_,0x95,0x90,0x8b,0x96,0x8b,0x8e,0x94,_4P_,0x93,0x98,0x99,0x86,0x94,0x99,0x8f,_COLON,_END_,    //_RUSSIAN    
};
#endif
BYTE code tOSD_sINFORMATION_COLON[] = //sInformation1
{
    _mI_,_mn_,_mf_,_mo_,_mr_,_mm_,_ma_,_mt_,_mi_,_mo_,_mn_,_COLON, _END_,          //_ENGLISH
    _mI_,_mn_,_mf_,_mo_,_mr_,_mm_,_ma_,_mt_,_mi_,_mo_,_mn_,_ms_,_COLON, _END_,    //_FRENCH
    _mI_,_mn_,_mf_,_mo_,_mr_,_mm_,_ma_,_mz_,_mi_,_mo_,_mn_,_mi_,_COLON, _END_,    //_ITALIAN
    0x47,0x48, _COLON,_END_,                                                          //_CHINESE_S
    _mI_,_mn_,_mf_,_mo_,_mr_,_mm_,_ma_,_mc_,_mi_,_EU_C4,_mn_,_COLON,_END_,      //_SPANISH(Esp)
    0x99,0x71,0x73,0xa0, _COLON,_END_,                                        //_JAPAN     
    _mI_,_mn_,_mf_,_mo_,_mr_,_mm_,_ma_,_mt_,_mi_,_mo_,_mn_,_COLON,_END_,          //_GERMAN(Deu)
    0x77,0x8e,0x7e,0x93,0x90,0x96,0x8f,0x9d,0x94,0x83, _COLON,_END_,       //_RUSSIAN     
};

BYTE code tOSD_sLANGUAGE_COLON[] = //sMenuLanguage1
{
    _mM_,_me_,_mn_,_mu_,_4P_,_mL_,_ma_,_mn_,_mg_,_mu_,_ma_,_mg_,_me_,_COLON, _END_,                                                                //_ENGLISH
    _mL_,_ma_,_mn_,_mg_,_mu_,_me_,_4P_,_EU_C9,_ma_,_mf_,_mf_,_mi_,_mc_,_mh_,_ma_,_mg_,_me_,_4P_,_md_,_mu_,_4P_,_mm_,_me_,_mn_,_mu_,_COLON,_END_,  //_FRENCH
    _mL_,_mi_,_mn_,_mg_,_mu_,_ma_,_4P_,_mm_,_me_,_mn_,_mu_,_COLON,_END_,                   //_ITALIAN
    0x4B,0x4C,0x4D,0x4E, _COLON,_END_,                                           //_CHINESE_S
    _mI_,_md_,_mi_,_mo_,_mm_,_ma_,_4P_,_md_,_me_,_ml_,_4P_,_mm_,_me_,_mn_,_EU_C7,_COLON,_END_,    //_SPANISH(Esp)
    0x5E,0x4F,0x61,0xc1,0x51,0x73,0xa0,0xb0,0xb5,_COLON,_END_,                                                             //_JAPAN    
    _mM_,_me_,_mn_,_EU_C6,_ms_,_mp_,_mr_,_ma_,_mc_,_mh_,_me_,_COLON,_END_,                        //_GERMAN(Deu)
    0x69,0x85,0x91,0x99,_4P_,0x96,0x8b,0x8e,0x9b, _COLON,_END_,                                       //_RUSSIAN     
};

BYTE code tOSD_sOSDPOS_COLON[] = // sMenuPosition1                                                                           
{
    _mM_,_me_,_mn_,_mu_,_4P_,_mP_,_mo_,_ms_,_mi_,_mt_,_mi_,_mo_,_mn_,_COLON, _END_,                   //_ENGLISH
    _mP_,_mo_,_ms_,_mi_,_mt_,_mi_,_mo_,_mn_,_4P_,_md_,_mu_,_4P_,_mm_,_me_,_mn_,_mu_,_COLON, _END_,  //_FRENCH
    _mP_,_mo_,_ms_,_mi_,_mz_,_mi_,_mo_,_mn_,_me_,_4P_,_mm_,_me_,_mn_,_mu_,_COLON, _END_,             //_ITALIAN
    0x4B,0x4C,0x2D,0x2E, _COLON,_END_,                                                            //_CHINESE_S
    _mP_,_mo_,_ms_,_mi_,_mc_,_mi_,_EU_C4,_mn_,_4P_,_md_,_me_,_ml_,_4P_,_mm_,_me_,_mn_,_EU_C7,_COLON,_END_,     //_SPANISH(Esp)
    0x5E,0x4F,0x61,0xc1,0x51,0xa7,0xbA,_COLON, _END_,                                                                              //_JAPAN    
    _mM_,_me_,_mn_,_EU_C6,_mp_,_mo_,_ms_,_mi_,_mt_,_mi_,_mo_,_mn_,_COLON,_END_,                            //_GERMAN(Deu)
    0x71,0x93,0x86,0x93,0x8a,0x8b,0x8e,0x94,0x8b,_4P_,0x96,0x8b,0x8e,0x9b,_COLON, _END_,  //_RUSSIAN 
};


BYTE code tOSD_sFACTORY_DEFAULT_COLON[] = //sFactoryDefault1
{
    _mF_,_ma_,_mc_,_mt_,_mo_,_mr_,_my_,_4P_,_mD_,_me_,_mf_,_ma_,_mu_,_ml_,_mt_,_COLON, _END_, //_ENGLISH
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _mV_,_ma_,_ml_,_me_,_mu_,_mr_,_ms_,_4P_,_mu_,_ms_,_mi_,_mn_,_me_,_4P_,_md_,_EU_C2,_mf_,_mi_,_mn_,_mi_,_me_,_ms_,_4P_,_mp_,_ma_,_mr_,_4P_,_md_,_EU_C2,_mf_,_ma_,_mu_,_mt_,_COLON,_END_,  //_FRENCH
#else
    _mV_,_ma_,_ml_,_me_,_mu_,_mr_,_ms_,_4P_,_mu_,_ms_,_mi_,_mn_,_me_,_4P_,_md_,_EU_C2,_mf_,_mi_,_mn_,_mi_,_me_,_ms_,_4P_,_mp_,_ma_,_mr_,_4P_,_mD_,_EU_C2,_mf_,_ma_,_mu_,_mt_,_COLON,_END_,  //_FRENCH
#endif
    _mP_,_mr_,_me_,_md_,_me_,_mf_,_mi_,_mn_,_mi_,_mt_,_mo_,_COLON,_END_,                                   //_ITALIAN
    0x8b,0x8c,0x37,0x2E, _COLON,_END_,                                                      //_CHINESE_S
    _mV_,_ma_,_ml_,_mo_,_mr_,_me_,_ms_,_4P_,_mp_,_mo_,_mr_,_4P_,_mo_,_mm_,_mi_,_ms_,_mi_,_EU_C4,_mn_,_4P_,_md_,_me_,_4P_,_mf_,_EU_C5,_mb_,_mr_,_mi_,_mc_,_ma_,_COLON,_END_,    //_SPANISH(Esp)
    0x84,0x76,0x78,0x86,0x9F,0x51,0x9E,0x7F, _COLON,_END_,                                                               //_JAPAN
    _mW_,_me_,_mr_,_mk_,_ms_,_me_,_mi_,_mt_,_mi_,_mg_,_me_,_4P_,_mS_,_mt_,_ma_,_mn_,_md_,_ma_,_mr_,_md_,_me_,_mi_,_mn_,_ms_,_mt_,_me_,_ml_,_ml_,_mu_,_mn_,_mg_,_COLON,_END_,         //_GERMAN(Deu)
    0x75,0x8f,0x95,0x93,0x92,0x9a,0x99,0x94,0x8b,_4P_,0x8e,0x8f,0x9a,0x98,0x90,0x93,0x81,0x99,0x94,_COLON,_END_,                                                 //_RUSSIAN 
};

BYTE code tOSD_sACCESSIBILITY_COLON[] = //sAccessibility1
{
    _mA_,_mc_,_mc_,_me_,_ms_,_ms_,_mi_,_mb_,_mi_,_ml_,_mi_,_mt_,_my_,_COLON, _END_,    //_ENGLISH
    _mA_,_mc_,_mc_,_me_,_ms_,_ms_,_mi_,_mb_,_mi_,_ml_,_mi_,_mt_,_EU_C2,_COLON,_END_,              //_FRENCH
    _mA_,_mc_,_mc_,_me_,_ms_,_ms_,_mi_,_mb_,_mi_,_ml_,_mi_,_mt_,_EU_C3,_COLON,_END_,              //_ITALIAN
    0x1e,0x1f,0x1a,0x54,0x55,0x56,0x57,_COLON, _END_,                                     //_CHINESE_S
    _mA_,_mc_,_mc_,_me_,_ms_,_mi_,_mb_,_mi_,_ml_,_mi_,_md_,_ma_,_md_,_COLON,_END_,                  //_SPANISH(Esp)
    0x23,0x30,0x3D,0x37,0x54,0x66,0x46,0x24,0xc1, _COLON, _END_,                            //_JAPAN           
    _mZ_,_mu_,_mg_,_mr_,_mi_,_mf_,_mf_,_ms_,_mm_,_EU_C8,_mg_,_ml_,_mi_,_mc_,_mh_,_mk_,_me_,_mi_,_mt_,_COLON,_END_,           //_GERMAN(Deu)
    0x7d,0x93,0x9a,0x98,0x84,0x89,0x8e,0x93,0x9a,0x98,0x80,_COLON,_END_,//_RUSSIAN     
};

//========================================================================================================================================================
//最細體文字( 說明文字第二行)
BYTE code tOSD_sBRIGHTNESS_EXPLAIN[] = //sAdjustBrightTip
{
    _sA_,_sd_,_sj_,_su_,_ss_,_st_,_ss_,_4P_,_so_,_sv_,_se_,_sr_,_sa_,_sl_,_sl_,_4P_,_ss_,_sc_,_sr_,_se_,_se_,_sn_,_4P_,_sb_,_sr_,_si_,_sg_,_sh_,_st_,_sn_,_se_,_ss_,_ss_,_DOT,_END_,    //_ENGLISH
    _sC_,_so_,_sn_,_st_,_sr_,_EU_3E,_sl_,_se_,_4P_,_EU_D9,_si_,_sn_,_st_,_se_,_sn_,_ss_,_si_,_st_,_EU_3A,_4P_,_sl_,_su_,_sm_,_si_,_sn_,_se_,_su_,_ss_,_se_,_4P_,_sd_,_se_,_4P_,_EU_D9,_EU_3A,_sc_,_sr_,_sa_,_sn_,_DOT,_END_,   //_FRENCH
    _sR_,_se_,_sg_,_so_,_sl_,_sa_,_4P_,_sl_,_sa_,_4P_,_sl_,_su_,_sc_,_se_,_4P_,_sd_,_se_,_sl_,_sl_,_so_,_4P_,_ss_,_sc_,_sh_,_se_,_sr_,_sm_,_so_,_DOT,_END_,                                                         //_ITALIAN
    0x25,0x26,0x27,0x28,0x22,0x21, _END_, //_CHINESE_S
    _sA_,_sj_,_su_,_ss_,_st_,_sa_,_4P_,_se_,_sl_,_4P_,_sb_,_sr_,_si_,_sl_,_sl_,_so_,_4P_,_sg_,_se_,_sn_,_se_,_sr_,_sa_,_sl_,_4P_,_sd_,_se_,_4P_,_sl_,_sa_,_4P_,_sp_,_sa_,_sn_,_st_,_sa_,_sl_,_sl_,_sa_,_DOT,_END_,      //_SPANISH(Esp)
    0x88,0x91,0x9A,0xa5,0x51,0x89,0x81,0x6D,0x7E,0xb8,0x38,0x5B,0x3B,_END_,  //_JAPAN    
    _sG_,_se_,_ss_,_sa_,_sm_,_st_,_se_,_4P_,_sB_,_si_,_sl_,_sd_,_ss_,_sc_,_sh_,_si_,_sr_,_sm_,_sh_,_se_,_sl_,_sl_,_si_,_sg_,_sk_,_se_,_si_,_st_,_4P_,_sa_,_sn_,_sp_,_sa_,_ss_,_ss_,_se_,_sn_,_DOT,_END_,            //_GERMAN(Deu)          
    0xa6,0x68,0x53,0x52,0x1e,0x1b,0x1c,0x1d,0xa9,0xaa,0xab,_4P_,0xac,0x1c,0xaa,0x1d,0xad,0xae,0x1b,_4P_,0xaf,0xaa,0x1c,0xab,0xb0,0xab,_DOT, _END_,//_RUSSIAN   
}; 

BYTE code tOSD_sCONTRAST_EXPLAIN1[] = // sAdjustContrastTip
{
    _sA_,_sd_,_sj_,_su_,_ss_,_st_,_ss_,_4P_,_sd_,_si_,_sf_,_sf_,_se_,_sr_,_se_,_sn_,_sc_,_se_,_4P_,_sb_,_se_,_st_,_sw_,_se_,_se_,_sn_,_4P_,_sl_,_si_,_sg_,_sh_,_st_,_4P_,_sa_,_sn_,_sd_,_4P_,_sd_,_sa_,_sr_,_sk_,_4P_,_sa_,_sr_,_se_,_sa_,_ss_,_DOT,_END_,                               //_ENGLISH
    _sC_,_so_,_sn_,_st_,_sr_,_EU_3E,_sl_,_se_,_4P_,_EU_D9,_so_,_sp_,_sp_,_so_,_ss_,_si_,_st_,_si_,_so_,_sn_,_4P_,_se_,_sn_,_st_,_sr_,_se_,_4P_,_sl_,_se_,_ss_,_4P_,_sz_,_so_,_sn_,_se_,_ss_,_4P_,_sc_,_sl_,_sa_,_si_,_sr_,_se_,_ss_,_4P_,_se_,_st_,_4P_,_sl_,_se_,_ss_,_4P_,_sz_,_so_,_sn_,_se_,_ss_,_4P_,_ss_,_so_,_sm_,_sb_,_sr_,_se_,_ss_,_DOT,_END_, //_FRENCH
    _sR_,_se_,_sg_,_so_,_sl_,_sa_,_4P_,_sl_,_sa_,_4P_,_sd_,_si_,_sf_,_sf_,_se_,_sr_,_se_,_sn_,_sz_,_sa_,_4P_,_st_,_sr_,_sa_,_4P_,_sl_,_se_,_4P_,_sa_,_sr_,_se_,_se_,_4P_,_sd_,_si_,_4P_,_sl_,_su_,_sc_,_se_,_4P_,_se_,_4P_,_so_,_ss_,_sc_,_su_,_sr_,_si_,_st_,_EU_3C,_DOT,_END_, //_ITALIAN
    0x29,0x2A,0x25,0x26, _END_, //_CHINESE_S
    _sA_,_sj_,_su_,_ss_,_st_,_sa_,_4P_,_sl_,_sa_,_4P_,_sd_,_si_,_sf_,_se_,_sr_,_se_,_sn_,_sc_,_si_,_sa_,_4P_,_se_,_sn_,_st_,_sr_,_se_,_4P_,_sl_,_sa_,_ss_,_4P_,_EU_D6,_sr_,_se_,_sa_,_ss_,_4P_,_sc_,_sl_,_sa_,_sr_,_sa_,_ss_,_4P_,_sy_,_4P_,_so_,_ss_,_sc_,_su_,_sr_,_sa_,_ss_,_DOT,_END_,    //_SPANISH(Esp)
    0x93,0x68,0x26,0x74,0x82,0x4B,0x70,0x26,0x74,0x82,0x51,0x75,0xb2,0x6D,0x7E,0xb8,0x38,0x5B,0x3B,_END_,  //_JAPAN   
    _sD_,_si_,_sf_,_sf_,_se_,_sr_,_se_,_sn_,_sz_,_4P_,_sz_,_sw_,_si_,_ss_,_sc_,_sh_,_se_,_sn_,_4P_,_sh_,_se_,_sl_,_sl_,_se_,_sn_,_4P_,_su_,_sn_,_sd_,_4P_,_sd_,_su_,_sn_,_sk_,_sl_,_se_,_sn_,_4P_,_sB_,_se_,_sr_,_se_,_si_,_sc_,_sh_,_se_,_sn_,_4P_,_sa_,_sn_,_sg_,_sl_,_se_,_si_,_sc_,_sh_,_se_,_sn_,_DOT,_END_,  //_GERMAN(Deu)
    0xa6,0x68,0x53,0x52,0x1e,0x1b,0x1c,0x1d,0xa9,0xaa,0xab,_4P_,0x1c,0xab,0xaf,0xb0,0x1b,0xb1,0xb2,_4P_,0xb3,0x68,0x65,0x66,0x52,_4P_,0xad,0xa9,0x68,0xae,0x1e,0xb2,0xb3,0x1b,_4P_,0x1b,_4P_,0xae,0x68,0xb3,0xb0,0xb2,0xb3,0x1b,_4P_,0x52,0x67,0xab,0xad,0xae,0xaa,0xab,0xb3,0x1b,_DOT,_END_,//_RUSSIAN   
};

#if(_LENOVO_DPS_SUPPORT == _ON)
BYTE code tOSD_sDPS_EXPLAIN1[] = // sAdjustDPSTip
{
    _sD_,_sP_,_sS_,_4P_,_so_,_sn_,_4P_,_sm_,_sa_,_sk_,_se_,_ss_,_4P_,_sl_,_so_,_sw_,_4P_,_sp_,_so_,_sw_,_se_,_sr_,_4P_,_sc_,_so_,_sn_,_ss_,_su_,_sm_,_sp_,_st_,_si_,_so_,_sn_,_DOT,_END_,                               //_ENGLISH
    _sD_,_sP_,_sS_,_4P_,_sa_,_sc_,_st_,_si_,_sv_,_EU_3A,_se_,_4P_,_sp_,_so_,_su_,_sr_,_4P_,_su_,_sn_,_se_,_4P_,_sc_,_so_,_sn_,_ss_,_so_,_sm_,_sm_,_sa_,_st_,_si_,_so_,_sn_,_4P_,_EU_3A,_sl_,_se_,_sc_,_st_,_sr_,_si_,_sq_,_su_,_se_,_4P_,_sr_,_EU_3A,_sd_,_su_,_si_,_st_,_se_,_DOT,_END_, //_FRENCH
    _sA_,_st_,_st_,_si_,_sv_,_sa_,_sn_,_sd_,_so_,_4P_,_sD_,_sP_,_sS_,_4P_,_ss_,_si_,_4P_,_sr_,_si_,_sd_,_su_,_sc_,_se_,_4P_,_si_,_sl_,_4P_,_sc_,_so_,_sn_,_ss_,_su_,_sm_,_so_,_4P_,_se_,_sn_,_se_,_sr_,_sg_,_se_,_st_,_si_,_sc_,_so_,_DOT,_END_, //_ITALIAN
    0x1A,0xBA,0x1F,0x91,0xBB,0x5D,0xBC,0xBD,0xBE,0xA4,0xBF, _END_, //_CHINESE_S
    _sD_,_sP_,_sS_,_4P_,_sr_,_se_,_sd_,_su_,_sc_,_se_,_4P_,_se_,_sl_,_4P_,_sc_,_so_,_sn_,_ss_,_su_,_sm_,_so_,_4P_,_sd_,_se_,_4P_,_se_,_sn_,_se_,_sr_,_sg_,_EU_0E,_sa_,_DOT,_END_,    //_SPANISH(Esp)
    0x1A,0xD4,0x1F,0x6D,0x2A,0x6E,0x50,0x3B,0x68,0x4B,0xD5,0xD6,0xD7,0xD8,0x22,0xD9,0x4E,0x31,0x4E,0xDA,0x5B,0x3B,_DOT,_END_,  //_JAPAN   
    _sB_,_se_,_si_,_4P_,_sa_,_sk_,_st_,_si_,_sv_,_se_,_sr_,_4P_,_sD_,_sP_,_sS_,0x0C,_sF_,_su_,_sn_,_sk_,_st_,_si_,_so_,_sn_,_4P_,_ss_,_si_,_sn_,_sk_,_st_,_4P_,_sd_,_se_,_sr_,_4P_,_sS_,_st_,_sr_,_so_,_sm_,_sv_,_se_,_sr_,_sb_,_sr_,_sa_,_su_,_sc_,_sh_,_DOT,_END_,  //_GERMAN(Deu)
    0xB4,0xAD,0x1E,0x1B,_4P_,0x7E,0x52,0xB0,0xAA,0xB1,0x1B,0xAC,_4P_,0x60,0x72,0x7B,_4P_,0xA9,0xAA,0x1E,0x5B,0x67,0x68,0xB0,0xAB,0x62,0x56,0x1D,0xAE,0x1C,0x68,0x55,0x1E,0xAC,0x68,0xB3,0xAB,0xAC,_4P_,0xB3,0x1D,0xB0,0x1B,0xAE,0x1D,0x1C,0x1D,0xB3,_4P_,0xB3,0x1D,0x54,0xB0,0x1D,0xAD,0xAE,0x46,_4P_,_4P_,_4P_,_4P_,_4P_,_4P_,_4P_,0xAD,0xB0,0x1B,0x65,0xAB,0x68,0xAE,0xAD,0xAC,_DOT,_END_,//_RUSSIAN   
};
#endif

#if(_USER_DCR_FUNCTION == _ON)
BYTE code tOSD_sDCR_EXPLAIN1[] = // sAdjustDCRTip
{
    _sE_, _sn_, _sa_, _sb_,_sl_,_se_,_4P_,_sd_, _sy_, _sn_, _sa_, _sm_, _si_, _sc_, _4P_, _sc_, _so_, _sn_, _st_, _sr_, _sa_, _ss_, _st_, _4P_, _sr_, _sa_, _st_, _si_, _so_, _DOT, _END_,    //_ENGLISH
    _sA_,_sc_,_st_,_si_,_sv_,_sa_,_st_,_si_,_so_,_sn_,_4P_,_sd_,_su_,_4P_,_sr_,_sa_,_sp_,_sp_,_so_,_sr_,_st_,_4P_,_sd_,_se_,_4P_,_sc_,_so_,_sn_,_st_,_sr_,_sa_,_ss_,_st_,_se_,_4P_,_sd_,_sy_,_sn_,_sa_,_sm_,_si_,_sq_,_su_,_se_,_DOT,_END_, //_FRENCH
    _sA_,_sb_,_si_,_sl_,_si_,_st_,_sa_,_sr_,_se_,_4P_,_sr_,_sa_,_sp_,_sp_,_so_,_sr_,_st_,_so_,_4P_,_sd_,_si_,_4P_,_sc_,_so_,_sn_,_st_,_sr_,_sa_,_ss_,_st_,_so_,_4P_,_sd_,_si_,_sn_,_sa_,_sm_,_si_,_sc_,_so_,_DOT,_END_, //_ITALIAN
    0xBB,0x68,0x32,0xc2,0x23,0x24,0x21,_DOT,_END_, //_CHINESE_S
    _sH_,_sa_,_sb_,_si_,_sl_,_si_,_st_,_se_,_4P_,_sl_,_sa_,_4P_,_sr_,_se_,_sl_,_sa_,_sc_,_si_,_EU_3D,_sn_,_4P_,_sd_,_se_,_4P_,_sc_,_so_,_sn_,_st_,_sr_,_sa_,_ss_,_st_,_se_,_4P_,_sd_,_si_,_sn_,_EU_3C,_sm_,_si_,_sc_,_so_,_DOT,_END_,    //_SPANISH(Esp)
    0xDC,0x25,0x4D,0xdd,0x44,0x30,0x34,0x6e,0x4a,0x64,0x3A,0x4a,0xD0,0x6d,0xde,0xdf,0xD2,0x69,0x5C,0x3B,_DOT,_END_,  //_JAPAN   
    _sD_,_sy_,_sn_,_sa_,_sm_,_si_,_ss_,_sc_,_sh_,_se_,_ss_,_4P_,_sK_,_so_,_sn_,_st_,_sr_,_sa_,_ss_,_st_,_sv_,_se_,_sr_,_sh_,_EU_D4,_sl_,_st_,_sn_,_si_,_ss_,_4P_,_sa_,_sk_,_st_,_si_,_sv_,_si_,_se_,_sr_,_se_,_sn_,_DOT,_END_,  //_GERMAN(Deu)
    0x6a,0xb2,0x55,0x68,0x1c,0x1b,0xae,0x68,_4P_,0x66,0x1B,0xb0,0xab,0xb3,0x1b,0x67,0x68,0xad,0xAA,0x1b,0x1a,_4P_,0xAA,0x1d,0x44,0x5e,0x5e,0x1b,0xb1,0x1b,0x68,0xb0,0xae,_4P_,0xaa,0x1D,0xB0,0xAE,0x1C,0xab,0xad,0xae,0xb0,0x1d,0xAD,0xAE,0x1b,_DOT,_END_,//_RUSSIAN   
};
#endif

BYTE code tOSD_sHPOS_EXPLAIN[] = // sMovesHPosTip
{
    _sM_,_so_,_sv_,_se_,_ss_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_sl_,_se_,_sf_,_st_,_4P_,_so_,_sr_,_4P_,_sr_,_si_,_sg_,_sh_,_st_,_DOT, _END_,                     //_ENGLISH
    _sD_,_EU_3A,_sp_,_sl_,_sa_,_sc_,_se_,_4P_,_EU_D9,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_sv_,_se_,_sr_,_ss_,_4P_,_sl_,_sa_,_4P_,_sg_,_sa_,_su_,_sc_,_sh_,_se_,_4P_,_so_,_su_,_4P_,_sv_,_se_,_sr_,_ss_,_4P_,_sl_,_sa_,_4P_,_sd_,_sr_,_so_,_si_,_st_,_se_,_DOT,_END_,   //_FRENCH 
    _sS_,_sp_,_so_,_ss_,_st_,_sa_,_4P_,_EU_D9,_si_,_sm_,_sm_,_sa_,_sg_,_si_,_sn_,_se_,_4P_,_sv_,_se_,_sr_,_ss_,_so_,_4P_,_sd_,_se_,_ss_,_st_,_sr_,_sa_,_4P_,_so_,_4P_,_sv_,_se_,_sr_,_ss_,_so_,_4P_,_ss_,_si_,_sn_,_si_,_ss_,_st_,_sr_,_sa_,_DOT,_END_,      //_ITALIAN
    0x2B,0x2C,0x2F,0x30,0x31,0x32, _END_, //_CHINESE_S
    _sM_,_su_,_se_,_sv_,_se_,_4P_,_sl_,_sa_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_sn_,_4P_,_sh_,_sa_,_sc_,_si_,_sa_,_4P_,_si_,_sz_,_sq_,_su_,_si_,_se_,_sr_,_sd_,_sa_,_4P_,_so_,_4P_,_sd_,_se_,_sr_,_se_,_sc_,_sh_,_sa_,_DOT,_END_,  //_SPANISH(Esp)      
    0x88,0xaC,0x6D,0xc0,0xb4,0x50,0xb1,0x80,0x38,0x5B,0x3B, _END_,  //_JAPAN    
    _sB_,_si_,_sl_,_sd_,_4P_,_sn_,_sa_,_sc_,_sh_,_4P_,_sl_,_si_,_sn_,_sk_,_ss_,_4P_,_so_,_sd_,_se_,_sr_,_4P_,_sr_,_se_,_sc_,_sh_,_st_,_ss_,_4P_,_sv_,_se_,_sr_,_ss_,_sc_,_sh_,_si_,_se_,_sb_,_se_,_sn_,_DOT,_END_,           //_GERMAN(Deu)         
    0xa8,0x68,0x1c,0x68,0xb3,0x68,0x54,0x68,0xb0,0x1b,0x68,_4P_,0x1b,0xaf,0x1d,0x55,0x1c,0xab,0x65,0x68,0xb0,0x1b,0xac,_4P_,0xa9,0x1e,0x68,0xa9,0x1d,_4P_,0x1b,0x1e,0x1b,_4P_,0xa9,0x56,0x1c,0xab,0xa9,0x1d,_DOT,_END_,  //_RUSSIAN           
};

BYTE code tOSD_sVPOS_EXPLAIN[] = // sMovesVPosTip
{
    _sM_,_so_,_sv_,_se_,_ss_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_su_,_sp_,_4P_,_so_,_sr_,_4P_,_sd_,_so_,_sw_,_sn_,_DOT, _END_,
    _sD_,_EU_3A,_sp_,_sl_,_sa_,_sc_,_se_,_4P_,_EU_D9,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_sv_,_se_,_sr_,_ss_,_4P_,_sl_,_se_,_4P_,_sh_,_sa_,_su_,_st_,_4P_,_so_,_su_,_4P_,_sv_,_se_,_sr_,_ss_,_4P_,_sl_,_se_,_4P_,_sb_,_sa_,_ss_,_DOT,_END_,
    _sS_,_sp_,_so_,_ss_,_st_,_sa_,_4P_,_EU_D9,_si_,_sm_,_sm_,_sa_,_sg_,_si_,_sn_,_se_,_4P_,_sv_,_se_,_sr_,_ss_,_so_,_4P_,_EU_D9,_sa_,_sl_,_st_,_so_,_4P_,_so_,_4P_,_sv_,_se_,_sr_,_ss_,_so_,_4P_,_si_,_sl_,_4P_,_sb_,_sa_,_ss_,_ss_,_so_,_DOT,_END_,  //_ITALIAN
    0x2B,0x2C,0x33,0x34,0x31,0x32, _END_, //_CHINESE_S
    _sM_,_su_,_se_,_sv_,_se_,_4P_,_sl_,_sa_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_sn_,_4P_,_sh_,_sa_,_sc_,_si_,_sa_,_4P_,_sa_,_sr_,_sr_,_si_,_sb_,_sa_,_4P_,_so_,_4P_,_sa_,_sb_,_sa_,_sj_,_so_,_DOT,_END_,     //_SPANISH(Esp)        
    0x88,0xaC,0x6D,0x9D,0xa9,0x50,0xb1,0x80,0x38,0x5B,0x3B,_END_,  //_JAPAN    
    _sB_,_si_,_sl_,_sd_,_4P_,_sn_,_sa_,_sc_,_sh_,_4P_,_so_,_sb_,_se_,_sn_,_4P_,_so_,_sd_,_se_,_sr_,_4P_,_su_,_sn_,_st_,_se_,_sn_,_4P_,_sv_,_se_,_sr_,_ss_,_sc_,_sh_,_si_,_se_,_sb_,_se_,_sn_,_DOT,_END_,  //_GERMAN(Deu)           
    0xa8,0x68,0x1c,0x68,0xb3,0x68,0x54,0x68,0xb0,0x1b,0x68,_4P_,0x1b,0xaf,0x1d,0x55,0x1c,0xab,0x65,0x68,0xb0,0x1b,0xac,_4P_,0xa9,0xa9,0x68,0x1c,0x43,_4P_,0x1b,0x1e,0x1b,_4P_,0xa9,0xb0,0x1b,0xaf,_DOT,_END_,  //_RUSSIAN           
};

BYTE code tOSD_sAUTOMATIC_EXPLAIN1[]= // sOptimizesAutoTip
{
    _sO_,_sp_,_st_,_si_,_sm_,_si_,_sz_,_se_,_ss_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_PARENT_OPEN,_ss_,_si_,_sz_,_se_,_COMMA,_sp_,_so_,_ss_,_si_,_st_,_si_,_so_,_sn_,_COMMA,_sp_,_sh_,_sa_,_ss_,_se_,_COMMA,_sa_,_sn_,_sd_,_4P_,_sc_,_sl_,_so_,_sc_,_sk_,_PARENT_CLOSE,_DOT, _END_,
    _sO_,_sp_,_st_,_si_,_sm_,_si_,_ss_,_se_,_4P_,_EU_D9,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_PARENT_OPEN,_st_,_sa_,_si_,_sl_,_sl_,_se_,_COMMA,_sp_,_so_,_ss_,_si_,_st_,_si_,_so_,_sn_,_COMMA,_4P_,_sp_,_sh_,_sa_,_ss_,_se_,_4P_,_se_,_st_,_4P_,_sh_,_so_,_sr_,_sl_,_so_,_sg_,_se_,_PARENT_CLOSE,_DOT,_END_,   //_FRENCH
    _sO_,_st_,_st_,_si_,_sm_,_si_,_sz_,_sz_,_sa_,_4P_,_EU_D9,_si_,_sm_,_sm_,_sa_,_sg_,_si_,_sn_,_se_,_4P_,_PARENT_OPEN,_sd_,_si_,_sm_,_se_,_sn_,_ss_,_si_,_so_,_sn_,_se_,_COMMA,_4P_,_sp_,_so_,_ss_,_si_,_sz_,_si_,_so_,_sn_,_se_,_COMMA,_4P_,_sf_,_sa_,_ss_,_se_,_4P_,_se_,_4P_,_so_,_sr_,_so_,_sl_,_so_,_sg_,_si_,_so_,_PARENT_CLOSE,_DOT,_END_,      //_ITALIAN
    0x28,0x39,0x3A,0x3B,_END_,//_CHINESE_S
    _sO_,_sp_,_st_,_si_,_sm_,_si_,_sz_,_sa_,_4P_,_sl_,_sa_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_sn_,_4P_,_PARENT_OPEN,_st_,_sa_,_sm_,_sa_,_EU_3F,_so_,_COMMA,_sp_,_so_,_ss_,_si_,_sc_,_si_,_EU_3D,_sn_,_COMMA,_4P_,_sf_,_sa_,_ss_,_se_,_4P_,_sy_,_4P_,_sr_,_se_,_sl_,_so_,_sj_,_PARENT_CLOSE,_DOT,_END_,     //_SPANISH(Esp)        
    0x88,0xaC,0x51,0xbE,0x80,0x7E,0xb8,0x6D,0xaE,0x26,0x5B,0x3B,_PARENT_OPEN,0x35,0x25,0x3C,0x20,0xa7,0xbA,0x20,0xa7,0xaA,0x20,0x30,0x6B,0x44,0x30,_PARENT_CLOSE,_END_,  //_JAPAN   
    _sB_,_si_,_sl_,_sd_,_4P_,_so_,_sp_,_st_,_si_,_sm_,_si_,_se_,_sr_,_se_,_sn_,_4P_,_PARENT_OPEN,_sg_,_sr_,_EU_D3,_EU_D5,_se_,_COMMA,_sp_,_so_,_ss_,_si_,_st_,_si_,_so_,_sn_,_COMMA,_4P_,_sp_,_sh_,_sa_,_ss_,_se_,_4P_,_su_,_sn_,_sd_,_4P_,_st_,_sa_,_sk_,_st_,_sg_,_se_,_sb_,_se_,_sr_,_PARENT_CLOSE,_DOT,_END_,   //_GERMAN(Deu)
    0xa5,0x56,0xae,0x1b,0xb3,0x1b,0xaf,0xab,0xb1,0x1b,0xac,_4P_,0x1b,0xaf,0x1d,0x55,0x1c,0xab,0x65,0x68,0xb0,0x1b,0xac,0x63,0x1c,0xab,0xaf,0xb3,0x68,0x1c,0x62,0x56,0x1d,0x1e,0x1d,0x65,0x68,0xb0,0x1b,0x68,0x62,0x5e,0xab,0xaf,0xab,_4P_,0x1b,_4P_,0x67,0xab,0xad,0xae,0x1d,0xae,0xab,0x64,_DOT,_END_,  //_RUSSIAN     
};
    

BYTE code tOSD_sMANUAL_EXPLAIN1[] = // sManuallyPhaseClkTip
{
    _sM_,_sa_,_sn_,_su_,_sa_,_sl_,_sl_,_sy_,_4P_,_so_,_sp_,_st_,_si_,_sm_,_si_,_sz_,_se_,_ss_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_PARENT_OPEN,_sp_,_sh_,_sa_,_ss_,_se_,_4P_,_sa_,_sn_,_sd_,_4P_,_sc_,_sl_,_so_,_sc_,_sk_,_PARENT_CLOSE,_DOT,_END_,                //_ENGLISH
    _sP_,_se_,_sr_,_sm_,_se_,_st_,_4P_,_EU_CF,_so_,_sp_,_st_,_si_,_sm_,_si_,_ss_,_se_,_sr_,_4P_,_sm_,_sa_,_sn_,_su_,_se_,_sl_,_sl_,_se_,_sm_,_se_,_sn_,_st_,_4P_,_EU_D9,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_PARENT_OPEN,_sp_,_sh_,_sa_,_ss_,_se_,_4P_,_se_,_st_,_4P_,_sh_,_so_,_sr_,_sl_,_so_,_sg_,_se_,_PARENT_CLOSE,_DOT,_END_,  //_FRENCH
    _sO_,_st_,_st_,_si_,_sm_,_si_,_sz_,_sz_,_sa_,_sz_,_si_,_so_,_sn_,_se_,_4P_,_sm_,_sa_,_sn_,_su_,_sa_,_sl_,_se_,_4P_,_sd_,_se_,_sl_,_EU_D9,_si_,_sm_,_sm_,_sa_,_sg_,_si_,_sn_,_se_,_PARENT_OPEN,_sf_,_sa_,_ss_,_se_,_4P_,_se_,_4P_,_so_,_sr_,_so_,_sl_,_so_,_sg_,_si_,_so_,_PARENT_CLOSE,_DOT,_END_,       //_ITALIAN
    0x36,0x32,0x25,0x26,0x3C,0x2D,0x3D,0x3E,0x3F,_END_, //_CHINESE_S
    _sO_,_sp_,_st_,_si_,_sm_,_si_,_sz_,_sa_,_4P_,_sl_,_sa_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_sn_,_4P_,_sm_,_sa_,_sn_,_su_,_sa_,_sl_,_sm_,_se_,_sn_,_st_,_se_,_4P_,_PARENT_OPEN,_sf_,_sa_,_ss_,_se_,_4P_,_sy_,_4P_,_sr_,_se_,_sl_,_so_,_sj_,_PARENT_CLOSE,_DOT,_END_,      //_SPANISH(Esp)
    0x88,0xaC,0x51,0xa2,0x80,0x7E,0xb8,0x6D,0xaE,0x26,0x5B,0x3B,_PARENT_OPEN,0xa7,0xaA,0x20,0x30,0x6B,0x44,0x30,_PARENT_CLOSE, _END_,  //_JAPAN   
    _sB_,_si_,_sl_,_sd_,_4P_,_sm_,_sa_,_sn_,_su_,_se_,_sl_,_sl_,_4P_,_so_,_sp_,_st_,_si_,_sm_,_si_,_se_,_sr_,_se_,_sn_,_4P_,_PARENT_OPEN,_sp_,_sh_,_sa_,_ss_,_se_,_4P_,_su_,_sn_,_sd_,_4P_,_st_,_sa_,_sk_,_st_,_sg_,_se_,_sb_,_se_,_sr_,_PARENT_CLOSE,_DOT, _END_,    //_GERMAN(Deu)       
    0xa5,0x56,0xae,0x1b,0xb3,0x1b,0xaf,0xab,0xb1,0x1b,0xac,_4P_,0x1b,0xaf,0x1d,0x55,0x1c,0xab,0x65,0x68,0xb0,0x1b,0xac,_4P_,0xa9,0x1c,0x52,0x67,0xb0,0x52,0x5b,_4P_,0x63,0x5e,0xab,0xaf,0xab,_4P_,0x1b,_4P_,0x67,0xab,0xad,0xae,0x1d,0xae,0xab,0x64,_DOT,_END_,             //_RUSSIAN     
};


BYTE code tOSD_sCOLOR_EXPLAIN[] = //sAdjustRGBTip
{
    _sA_,_sd_,_sj_,_su_,_ss_,_st_,_ss_,_4P_,_si_,_sn_,_st_,_se_,_sn_,_ss_,_si_,_st_,_sy_,_4P_,_so_,_sf_,_4P_,_sr_,_se_,_sd_,_COMMA,_sg_,_sr_,_se_,_se_,_sn_,_COMMA,_sa_,_sn_,_sd_,_4P_,_sb_,_sl_,_su_,_se_,_DOT,_END_,  //_ENGLISH
    _sD_,_EU_3A,_sf_,_si_,_sn_,_si_,_st_,_4P_,_EU_D9,_si_,_sn_,_st_,_se_,_sn_,_ss_,_si_,_st_,_EU_3A,_4P_,_sd_,_se_,_4P_,_sr_,_so_,_su_,_sg_,_se_,_COMMA,_4P_,_sv_,_se_,_sr_,_st_,_COMMA,_4P_,_sb_,_sl_,_se_,_su_,_DOT,_END_,                  //_FRENCH
    _sR_,_se_,_sg_,_so_,_sl_,_sa_,_4P_,_EU_D9,_si_,_sn_,_st_,_se_,_sn_,_ss_,_si_,_st_,_EU_3C,_4P_,_sd_,_si_,_4P_,_sr_,_so_,_ss_,_ss_,_so_,_COMMA,_sv_,_se_,_sr_,_sd_,_se_,_4P_,_se_,_4P_,_sb_,_sl_,_su_,_DOT,_END_,                         //_ITALIAN
    0x25,0x26,0x42,0x05,0x43,0x05,0x44,0x8F,0x25,_END_,      //_CHINESE_S
    _sA_,_sj_,_su_,_ss_,_st_,_sa_,_4P_,_sl_,_sa_,_4P_,_si_,_sn_,_st_,_se_,_sn_,_ss_,_si_,_sd_,_sa_,_sd_,_4P_,_sd_,_se_,_sl_,_4P_,_sr_,_so_,_sj_,_so_,_COMMA,_4P_,_sv_,_se_,_sr_,_sd_,_se_,_4P_,_sy_,_4P_,_sa_,_sz_,_su_,_sl_,_DOT,_END_,  //_SPANISH(Esp)         
    0x77,0x20,0x90,0x20,0x98,0x51,0x9C,0x7E,0x6D,0x7E,0xb8,0x38,0x5B,0x3B, _END_,    //_JAPAN 

#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) //lorimiao 20140531
    _sI_,_sn_,_st_,_se_,_sn_,_ss_,_si_,_st_,_EU_D4,_st_,_4P_,_sd_,_se_,_sr_,_4P_,_sR_,_so_,_st_,_LINE,_COMMA,_sG_,_sr_,_EU_D2,_sn_,_LINE,_4P_,_su_,_sn_,_sd_,_4P_,_sB_,_sl_,_sa_,_su_,_st_,_EU_D3,_sn_,_se_,_4P_,_sa_,_sn_,_sp_,_sa_,_ss_,_ss_,_se_,_sn_,_DOT,_END_, //_GERMAN(Deu)         
#else
    _sI_,_sn_,_st_,_se_,_sn_,_ss_,_si_,_st_,_EU_D4,_st_,_4P_,_sd_,_se_,_sr_,_4P_,_sR_,_so_,_st_,_LINE,_COMMA,_sG_,_sr_,_EU_D2,_sn_,_LINE,_COMMA,_su_,_sn_,_sd_,_4P_,_sB_,_sl_,_sa_,_su_,_st_,_EU_D3,_sn_,_se_,_4P_,_sa_,_sn_,_sp_,_sa_,_ss_,_ss_,_se_,_sn_,_DOT,_END_, //_GERMAN(Deu)         
#endif
    0xa6,0x68,0x53,0x57,0xaa,0xab,_4P_,0x1b,0xb0,0xae,0x57,0xae,0x1b,_4P_,0xaa,0x1c,0xab,0xad,0xb0,0x1d,0x53,0x1d,0x62,_4P_,0xaf,0x68,0x1e,0x68,0xb0,0x1d,0x53,0x1d,_4P_,0x1b,_4P_,0xad,0x1b,0xb0,0x68,0x53,0x1d,_DOT,_END_,  //_RUSSIAN     
};


BYTE code tOSD_sINPUT_EXPLAIN[] = //sInputTip
{
    _sS_,_se_,_sl_,_se_,_sc_,_st_,_4P_,_sv_,_si_,_sd_,_se_,_so_,_4P_,_ss_,_si_,_sg_,_sn_,_sa_,_sl_,_DOT,_END_,                             //_ENGLISH
    _sS_,_EU_3A,_sl_,_se_,_sc_,_st_,_si_,_so_,_sn_,_sn_,_se_,_sz_,_4P_,_sl_,_se_,_4P_,_ss_,_si_,_sg_,_sn_,_sa_,_sl_,_4P_,_sv_,_si_,_sd_,_EU_3A,_so_,_DOT,_END_,   //_FRENCH
    _sS_,_se_,_sl_,_se_,_sz_,_si_,_so_,_sn_,_sa_,_4P_,_si_,_sl_,_4P_,_ss_,_se_,_sg_,_sn_,_sa_,_sl_,_se_,_4P_,_sv_,_si_,_sd_,_se_,_so_,_DOT,_END_,               //_ITALIAN
    0x45,0xa6,0x98,0x99,0x47,0x6F,_END_,//_CHINESE_S
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _sS_,_se_,_sl_,_se_,_sc_,_sc_,_si_,_so_,_sn_,_se_,_4P_,_sl_,_sa_,_4P_,_ss_,_se_,_EU_3F,_sa_,_sl_,_4P_,_sd_,_se_,_4P_,_sv_,_EU_0E,_sd_,_se_,_so_,_DOT,_END_,   //_SPANISH(Esp)       
#else
    _sS_,_se_,_sl_,_se_,_sc_,_sc_,_si_,_so_,_sn_,_se_,_4P_,_sl_,_sa_,_4P_,_ss_,_se_,_EU_3F,_sa_,_sl_,_4P_,_sd_,_se_,_4P_,_sv_,_EU_CE,_sd_,_se_,_so_,_DOT,_END_,   //_SPANISH(Esp)       
#endif
    0x54,0x48,0x2a,0x37,0x32,0x4d,0x67,0x51,0xaf,0xb6,0x6d,0xae,0x26,0x5b,0x3b, _END_,    //_JAPAN 
    _sV_,_si_,_sd_,_se_,_so_,_ss_,_si_,_sg_,_sn_,_sa_,_sl_,_4P_,_sa_,_su_,_ss_,_sw_,0xd4,_sh_,_sl_,_se_,_sn_,_DOT,_END_,                                      //_GERMAN(Deu)
    0x9f,0xb2,0x55,0x68,0x1c,0x1b,0xae,0x68,_4P_,0xa9,0x1b,0x66,0x68,0x1d,0xad,0x1b,0x53,0xb0,0xab,0x1e,_DOT, _END_,   //_RUSSIAN     
};

BYTE code tOSD_sSCALING_EXPLAIN[] = //sScalingTip
{
 
    _sS_,_se_,_sl_,_se_,_sc_,_st_,_4P_,_st_,_sy_,_sp_,_se_,_4P_,_so_,_sf_,_4P_,_ss_,_sc_,_sa_,_sl_,_se_,_sd_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_DOT, _END_,
    _sS_,_EU_3A,_sl_,_se_,_sc_,_st_,_si_,_so_,_sn_,_sn_,_se_,_sz_,_4P_,_sl_,_se_,_4P_,_sf_,_so_,_sr_,_sm_,_sa_,_st_,_4P_,_sd_,_se_,_4P_,_EU_D9,_si_,_sm_,_sa_,_sg_,_se_,_DOT,_END_,    //_FRENCH
    _sS_,_se_,_sl_,_se_,_sz_,_si_,_so_,_sn_,_sa_,_sr_,_se_,_4P_,_si_,_sl_,_4P_,_st_,_si_,_sp_,_so_,_4P_,_sd_,_si_,_4P_,_si_,_sm_,_sm_,_sa_,_sg_,_si_,_sn_,_se_,_4P_,_ss_,_sc_,_sa_,_sl_,_sa_,_st_,_sa_,_DOT,_END_,      //_ITALIAN
    0x45,0xa6,0x25,0x26,0x2b,0x2c,0xa7,0xa8,0xa9, _END_,//_CHINESE_S
    _sS_,_se_,_sl_,_se_,_sc_,_sc_,_si_,_so_,_sn_,_se_,_4P_,_se_,_sl_,_4P_,_st_,_si_,_sp_,_so_,_4P_,_sd_,_se_,_4P_,_se_,_ss_,_sc_,_sa_,_sl_,_sa_,_sd_,_so_,_4P_,_sd_,_se_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_sn_,_DOT,_END_,  //_SPANISH(Esp)          
    0xc7,0xc8,0xc5,0xc9,0x36,0x6a,0x40,0x88,0xac,0x51,0x3f,0x25,0x58,0x6d,0xaf,0xb6,0x38,0x47,0x31,0x41,0x36,0xd3,_END_,    //_JAPAN 
    _sB_,_si_,_sl_,_sd_,_ss_,_sk_,_sa_,_sl_,_si_,_se_,_sr_,_su_,_sn_,_sg_,_ss_,_st_,_sy_,_sp_,_4P_,_sw_,_EU_D4,_sh_,_sl_,_se_,_sn_,_DOT,_END_,  //_GERMAN(Deu)           
    0x9f,0xb2,0x55,0x68,0x1c,0x1b,0xae,0x68,_4P_,0xae,0x1b,0x56,_4P_,0xb3,0xab,0xad,0x45,0xae,0xab,0x55,0x1b,0x1c,0x52,0x68,0xb3,0x1d,0x53,0x1d,_4P_,0x1b,0xaf,0x1d,0x55,0x1c,0xab,0x65,0x68,0xb0,0x1b,0xac,_DOT, _END_,   //_RUSSIAN      
 
 }; 
#if(_OD_SUPPORT==_ON)			
BYTE code tOSD_sOD_EXPLAIN[] = 
{
    _sR_,_se_,_ss_,_sp_,_so_,_sn_,_ss_,_se_,_4P_,_st_,_si_,_sm_,_se_,_4P_,_se_,_sn_,_sh_,_sa_,_sn_,_sc_,_se_,_sm_,_se_,_sn_,_st_,_DOT, _END_,//_ENGLISH
    _sA_,_sm_,_EU_3A,_sl_,_si_,_so_,_sr_,_sa_,_st_,_si_,_so_,_sn_,_4P_,_sd_,_su_,_4P_,_st_,_se_,_sm_,_sp_,_ss_,_4P_,_sd_,_se_,_4P_,_sr_,_EU_3A,_sp_,_so_,_sn_,_ss_,_se_,_DOT,_END_,//_FRENCH
    _sM_,_si_,_sg_,_sl_,_si_,_so_,_sr_,_sa_,_sm_,_se_,_sn_,_st_,_so_,_4P_,_sd_,_se_,_si_,_4P_,_st_,_se_,_sm_,_sp_,_si_,_4P_,_sd_,_si_,_4P_,_sr_,_si_,_ss_,_sp_,_so_,_ss_,_st_,_sa_,_DOT,_END_,//_ITALIAN
    0xC3,0xC4,0x54,0x55,0x5D,0x5e,_END_,//_CHINESE_S
    _sM_,_se_,_sj_,_so_,_sr_,_sa_,_4P_,_sd_,_se_,_sl_,_4P_,_st_,_si_,_se_,_sm_,_sp_,_so_,_4P_,_sd_,_se_,_4P_,_sr_,_se_,_ss_,_sp_,_su_,_se_,_ss_,_st_,_sa_, _DOT,_END_,//_SPANISH(Esp)          
    0xb3,0x7c,0x9f, 0x8a,0x51,0xdb,0xa4,0x87,_END_,//_JAPAN 
    _sV_,_se_,_sr_,_sb_,_se_,_ss_,_ss_,_se_,_sr_,_su_,_sn_,_sg_,_4P_,_sd_,_se_,_sr_,_4P_,_sR_,_se_,_sa_,_sk_,_st_,_si_,_so_,_sn_,_ss_,_sz_,_se_,_si_,_st_,_DOT,_END_,//_GERMAN(Deu)           
    0x52,0xb3,0x68,0xb0,0x46,0x45,0x68,0xb0,0x1b,0x68,_4P_,0xa9,0x1c,0x68,0xb3,0x68,0xb0,0x1b,_4P_,0x1d,0xae,0xa9,0x68,0xae,0xab,_DOT, _END_,//_RUSSIAN      
 
 }; 
#endif
BYTE code tOSD_sSCALING_OFF_EXPLAIN1[] = //sScalingOriginal
{
    _sS_,_sa_,_sm_,_se_,_4P_,_sA_,_ss_,_sp_,_se_,_sc_,_st_,_4P_,_sR_,_sa_,_st_,_si_,_so_,_4P_,_sw_,_si_,_st_,_sh_,_4P_,_si_,_sn_,_sp_,_su_,_st_,_4P_,_ss_,_si_,_sg_,_sn_,_sa_,_sl_, _END_,
    _sF_,_so_,_sr_,_sm_,_sa_,_st_,_4P_,_EU_CF,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_si_,_sd_,_se_,_sn_,_st_,_si_,_sq_,_su_,_se_,_4P_,_sa_,_su_,_4P_,_ss_,_si_,_sg_,_sn_,_sa_,_sl_,_4P_,_EU_CF,_se_,_sn_,_st_,_sr_,_EU_3A,_se_,_END_,   //_FRENCH
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) //lorimiao 20140531
    _sA_,_sl_,_sc_,_su_,_sn_,_si_,_4P_,_sF_,_so_,_sr_,_sm_,_sa_,_st_,_si_,_4P_,_sc_,_so_,_sn_,_4P_,_ss_,_se_,_sn_,_sg_,_sa_,_sl_,_se_,_4P_,_si_,_sn_,_4P_,_si_,_sn_,_sg_,_sr_,_se_,_ss_,_ss_,_so_,_END_,                  //_ITALIAN
#else
    _sA_,_sl_,_sc_,_su_,_sn_,_si_,_4P_,_sf_,_so_,_sr_,_sm_,_sa_,_st_,_si_,_4P_,_sc_,_so_,_sn_,_4P_,_ss_,_se_,_sn_,_sg_,_sa_,_sl_,_se_,_4P_,_si_,_sn_,_4P_,_si_,_sn_,_sg_,_sr_,_se_,_ss_,_ss_,_so_,_END_,                  //_ITALIAN
#endif
    0xaf,0x76,0x77,0x47,0x6f,0x3c,0xb0,0xb1,0xb2,0x24, _END_,  //_CHINESE_S
    _sM_,_si_,_ss_,_sm_,_sa_,_4P_,_sr_,_se_,_sl_,_sa_,_sc_,_si_,_EU_3D,_sn_,_4P_,_sd_,_se_,_4P_,_sa_,_ss_,_sp_,_se_,_sc_,_st_,_so_,_4P_,_sc_,_so_,_sn_,_4P_,_ss_,_se_,_EU_3F,_sa_,_sl_,_4P_,_sd_,_se_,_4P_,_se_,_sn_,_st_,_sr_,_sa_,_sd_,_sa_,_END_, //_SPANISH(Esp)
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)            
	0Xcb,0Xcc,0xcd,0xce,0xcf,0x30,0x4a,0xd0,0xd1,0x9b,0x8e,0xad,0x85,_END_, //_JAPAN
#else
	0Xcb,0Xcc,0xcd,0xce,0xcf,0xd0,0xc1,0x9b,0x8e,0xad,0x85,_END_, //_JAPAN
#endif
    _sB_,_si_,_sl_,_sd_,_sf_,_so_,_sr_,_sm_,_sa_,_st_,_4P_,_sw_,_si_,_se_,_4P_,_sE_,_si_,_sn_,_sg_,_sa_,_sn_,_sg_,_ss_,_ss_,_si_,_sg_,_sn_,_sa_,_sl_,_END_, //_GERMAN(Deu)
    0xa0,0x1d,0x1d,0xae,0xb0,0x1d,0x45,0x68,0xb0,0x1b,0x68,_4P_,0xad,0xae,0x1d,0x1c,0x1d,0xb0,0x62,0x1b,0x66,0x68,0xb0,0xae,0x1b,0x67,0xb0,0x1d,0x68,_4P_,0xad,0x1d,0x1d,0xae,0xb0,0x1d,0x45,0x68,0xb0,0x1b,0x5b,_4P_,0xad,0xae,0x1d,0x1c,0x1d,0xb0,_4P_,0xa9,0x43,0x1d,0x66,0xb0,0x1d,0x53,0x1d,_END_, //RUS    //_RUSSIAN
};

BYTE code tOSD_sSCALING_OFF_EXPLAIN2[] = //sScalingOriginal
{
    ___,_END_,    
    ___,_END_, //_FRENCH
    ___,_END_, //_ITALIAN
    ___,_END_, //_CHINESE_S
    ___,_END_, //_SPANISH(Esp)
    ___,_END_,//_JAPAN
    ___,_END_, //_GERMAN(Deu)
    0xad,0x1b,0x53,0xb0,0xab,0x1e,0xab,_END_, //_RUSSIAN
};


BYTE code tOSD_sSCALING_ON_EXPLAIN[] = //sScalingFull
{
    _sE_,_sx_,_sp_,_sa_,_sn_,_sd_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_st_,_so_,_4P_,_sf_,_su_,_sl_,_sl_,_4P_,_ss_,_sc_,_sr_,_se_,_se_,_sn_, _END_,
    _sE_,_st_,_si_,_sr_,_se_,_sr_,_4P_,_EU_D9,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_se_,_sn_,_4P_,_sp_,_sl_,_se_,_si_,_sn_,_4P_,_EU_3A,_sc_,_sr_,_sa_,_sn_,_END_,    //_FRENCH
    _sI_,_sn_,_sg_,_sr_,_sa_,_sn_,_sd_,_si_,_ss_,_sc_,_si_,_4P_,_si_,_sm_,_sm_,_sa_,_sg_,_si_,_sn_,_se_,_4P_,_sa_,_4P_,_ss_,_sc_,_sh_,_se_,_sr_,_sm_,_so_,_4P_,_si_,_sn_,_st_,_se_,_sr_,_so_,_END_, //_ITALIAN
    0xac,0x2b,0x2c,0xaa,0xab,0xad,0x27,0x28,0x39,_END_,  //_CHINESE_S
    _sE_,_sx_,_sp_,_sa_,_sn_,_sd_,_si_,_sr_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_sn_,_4P_,_sa_,_4P_,_sp_,_sa_,_sn_,_st_,_sa_,_sl_,_sl_,_sa_,_4P_,_sc_,_so_,_sm_,_sp_,_sl_,_se_,_st_,_sa_,_END_,           //_SPANISH(Esp) 
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)    
    0x88,0xac,0x6d,0x9a,0x88,0x91,0x50,0xc7,0xca,_END_,    //_JAPAN 
#else
    0x88,0xac,0x6d,0x9a,0x88,0x91,0xd2,0xc7,0xca,_END_,    //_JAPAN 
#endif
    _sB_,_si_,_sl_,_sd_,_4P_,_sa_,_su_,_sf_,_4P_,_sv_,_so_,_sl_,_sl_,_sb_,_si_,_sl_,_sd_,_sg_,_sr_,_EU_D3,_EU_D5,_se_,_4P_,_ss_,_st_,_sr_,_se_,_sc_,_sk_,_se_,_sn_,_END_, //_GERMAN(Deu)
    0xa6,0xab,0xad,0xae,0xac,0xb0,0x52,0xae,0x46,_4P_,0x1b,0xaf,0x1d,0x55,0x1c,0xab,0x65,0x68,0xb0,0x1b,0x68,_4P_,0xb0,0xab,_4P_,0xa9,0x68,0xad,0x46,_4P_,0xaf,0xaa,0x1c,0xab,0xb0,_END_,    //_RUSSIAN     
};

BYTE code tOSD_sINFORMATION_EXPLAIN1[] = // sShowInfoTip
{
    _sS_,_sh_,_so_,_sw_,_ss_,_4P_,_sr_,_se_,_ss_,_so_,_sl_,_su_,_st_,_si_,_so_,_sn_,_COMMA,_4P_,_sr_,_se_,_sf_,_sr_,_se_,_ss_,_sh_,_4P_,_sr_,_sa_,_st_,_se_,_COMMA,_4P_,_sa_,_sn_,_sd_,_4P_,_sp_,_sr_,_so_,_sd_,_su_,_sc_,_st_,_4P_,_sd_,_se_,_st_,_sa_,_si_,_sl_,_ss_,_DOT,_END_,
    _sA_,_sf_,_sf_,_si_,_sc_,_sh_,_se_,_4P_,_sl_,_sa_,_4P_,_sr_,_EU_3A,_ss_,_so_,_sl_,_su_,_st_,_si_,_so_,_sn_,_COMMA,_4P_,_sl_,_sa_,_4P_,_sf_,_sr_,_EU_3A,_sq_,_su_,_se_,_sn_,_sc_,_se_,_4P_,_sd_,_se_,_4P_,_sr_,_sa_,_sf_,_sr_,_sa_,_EU_CE,_sc_,_sh_,_si_,_ss_,_ss_,_se_,_sm_,_se_,_sn_,_st_,_4P_,_se_,_st_,_END_,       //_FRENCH
    _sV_,_si_,_ss_,_su_,_sa_,_sl_,_si_,_sz_,_sz_,_sa_,_4P_,_sl_,_sa_,_4P_,_sr_,_si_,_ss_,_so_,_sl_,_su_,_sz_,_si_,_so_,_sn_,_se_,_COMMA,_sl_,_sa_,_4P_,_sv_,_se_,_sl_,_so_,_sc_,_si_,_st_,_EU_3C,_4P_,_sd_,_si_,_4P_,_sa_,_sg_,_sg_,_si_,_so_,_sr_,_sn_,_sa_,_sm_,_se_,_sn_,_st_,_so_,_COMMA,_si_,_END_, //_ITALIAN
    0x83,0xb3,0x21,_COMMA,0xb4,0xb5,0xb6,_COMMA,0xb7,0xb8,0x47,0x48, _END_,   //_CHINESE_S
    _sM_,_su_,_se_,_ss_,_st_,_sr_,_sa_,_4P_,_sl_,_sa_,_4P_,_sr_,_se_,_ss_,_so_,_sl_,_su_,_sc_,_si_,_EU_3D,_sn_,_COMMA,_sc_,_sa_,_sd_,_se_,_sn_,_sc_,_si_,_sa_,_4P_,_sd_,_se_,_4P_,_sr_,_se_,_sn_,_so_,_sv_,_sa_,_sc_,_si_,_EU_3D,_sn_,_4P_,_sy_,_4P_,_sd_,_se_,_st_,_sa_,_sl_,_sl_,_se_,_ss_,_4P_,_sd_,_se_,_sl_,_8P_,_END_,              //_SPANISH(Esp)
    0x8C,0xaC,0x81,0x20,0x66,0x56,0x69,0x44,0x37,0x61,0x06,0x69,0xc1,0x4A,_4P_,0x2B,0x63,0x55,0xbB,0x94,0x51,0xaB,0xa8,0x99,0x71,0x6D,0x73,0xa0,0x38,0x5B,0x3B,_END_,  //_JAPAN    
    _sA_,_su_,_sf_,_sl_,_EU_D3,_ss_,_su_,_sn_,_sg_,_COMMA,_sB_,_si_,_sl_,_sd_,_sw_,_si_,_se_,_sd_,_se_,_sr_,_sh_,_so_,_sl_,_sf_,_sr_,_se_,_sq_,_su_,_se_,_sn_,_sz_,_4P_,_su_,_sn_,_sd_,_4P_,_sP_,_sr_,_so_,_sd_,_su_,_sk_,_st_,_sd_,_se_,_st_,_sa_,_si_,_sl_,_ss_,_4P_,_sa_,_sn_,_sz_,_se_,_si_,_sg_,_se_,_sn_,_DOT,_END_,           //_GERMAN(Deu)
    0xa0,0xa9,0x68,0x66,0x68,0xb0,0x1b,0xac,_4P_,0x1d,_4P_,0x1c,0xab,0xaf,0x1c,0x68,0x45,0x68,0xb0,0x1b,0x1b,0x62,0x67,0xab,0xad,0xae,0x1d,0xae,0x68,_4P_,0x1d,0x55,0xb0,0x1d,0xa9,0x1e,0x68,0xb0,0x1b,0xac,_4P_,0x1b,_4P_,0x1b,0xb0,0x5e,0x1d,0x1c,0xb3,0xab,0xb1,0x1b,0xac,_4P_,0x1d,_END_,    //_RUSSIAN      
};


BYTE code tOSD_sINFORMATION_EXPLAIN2[] =
{
    _END_,       //_ENGLISH
    _EU_CF,_sa_,_su_,_st_,_sr_,_se_,_ss_,_4P_,_sd_,_EU_3A,_st_,_sa_,_si_,_sl_,_ss_,_4P_,_sc_,_so_,_sn_,_sc_,_se_,_sr_,_sn_,_sa_,_sn_,_st_,_4P_,_sl_,_se_,_4P_,_sp_,_sr_,_so_,_sd_,_su_,_si_,_st_,_DOT,_END_,//_FRENCH 
    _sd_,_se_,_st_,_st_,_sa_,_sg_,_sl_,_si_,_4P_,_sd_,_se_,_sl_,_4P_,_sp_,_sr_,_so_,_sd_,_so_,_st_,_st_,_so_,_DOT,_END_,//_ITALIAN      
    _END_,       //_CHINESE_S 
    _sp_,_sr_,_so_,_sd_,_su_,_sc_,_st_,_so_,_DOT,_END_, //_SPANISH(Esp)
    _END_,       //_JAPAN
    _END_,                    //_GERMAN(Deu)         
    0x56,0x1c,0x1d,0x66,0x52,0xaa,0xae,0x68,_END_,
};


BYTE code tOSD_sLANGUAGE_EXPLAIN[] = //sChangesLngTip
{
    _sC_,_sh_,_sa_,_sn_,_sg_,_se_,_ss_,_4P_,_sl_,_sa_,_sn_,_sg_,_su_,_sa_,_sg_,_se_,_4P_,_so_,_sf_,_4P_,_sm_,_se_,_sn_,_su_,_DOT, _END_,
    _sP_,_se_,_sr_,_sm_,_se_,_st_,_4P_,_sd_,_se_,_4P_,_sc_,_sh_,_sa_,_sn_,_sg_,_se_,_sr_,_4P_,_sl_,_sa_,_4P_,_sl_,_sa_,_sn_,_sg_,_su_,_se_,_4P_,_EU_CF,_sa_,_sf_,_sf_,_si_,_sc_,_sh_,_sa_,_sg_,_se_,_4P_,_sd_,_su_,_4P_,_sm_,_se_,_sn_,_su_,_DOT,_END_,      //_FRENCH
    _sC_,_sa_,_sm_,_sb_,_si_,_sa_,_4P_,_sl_,_sa_,_4P_,_sl_,_si_,_sn_,_sg_,_su_,_sa_,_4P_,_sd_,_se_,_sl_,_4P_,_sm_,_se_,_sn_,_su_,_DOT,_END_,     //_ITALIAN
    0x49,0x4A,0x4B,0x4C,0x4D,0x4E,_END_,  //_CHINESE_S
    _sC_,_sa_,_sm_,_sb_,_si_,_sa_,_4P_,_se_,_sl_,_4P_,_si_,_sd_,_si_,_so_,_sm_,_sa_,_4P_,_sd_,_se_,_sl_,_4P_,_sm_,_se_,_sn_,_EU_D1,_DOT,_END_,    //_SPANISH(Esp)
    0x5E,0x4F,0x61,0xc1,0x49,0x73,0xa0,0x3B,0x68,0xb0,0xb5,0x2D,0xaF,0xb6,0x49,0x2F,0x5B,0x3B,_END_,      //_JAPAN
    _sS_,_sp_,_sr_,_sa_,_sc_,_sh_,_se_,_4P_,_sd_,_se_,_ss_,_4P_,_sM_,_se_,_sn_,_EU_D2,_ss_,_4P_,_EU_D4,_sn_,_sd_,_se_,_sr_,_sn_,_DOT,_END_,         //_GERMAN(Deu)    
    0xa4,0xaf,0xb3,0x68,0xb0,0x68,0xb0,0x1b,0x68,_4P_,0xac,0xaf,0xb2,0xaa,0xab,_4P_,0xb3,0x68,0xb0,0x5b,_DOT,_END_,          //_RUSSIAN 
};


BYTE code tOSD_sOSDPOS_EXPLAIN[] = // sAdjustsOSDPosTip
{
    _sA_,_sd_,_sj_,_su_,_ss_,_st_,_ss_,_4P_,_sm_,_se_,_sn_,_su_,_4P_,_sl_,_so_,_sc_,_sa_,_st_,_si_,_so_,_sn_,_DOT, _END_,                  //_ENGLISH 
    _sD_,_EU_3A,_sf_,_si_,_sn_,_si_,_st_,_4P_,_EU_D9,_se_,_sm_,_sp_,_sl_,_sa_,_sc_,_se_,_sm_,_se_,_sn_,_st_,_4P_,_sd_,_su_,_4P_,_sm_,_se_,_sn_,_su_,_DOT,_END_,    //_FRENCH
    _sR_,_se_,_sg_,_so_,_sl_,_sa_,_4P_,_sl_,_sa_,_4P_,_sp_,_so_,_ss_,_si_,_sz_,_si_,_so_,_sn_,_se_,_4P_,_sd_,_se_,_sl_,_4P_,_sm_,_se_,_sn_,_su_,_DOT,_END_,       //_ITALIAN
    0x25,0x26,0x4B,0x4C,0x2D,0x2E,_END_,                                                                         //_CHINESE_S
    _sA_,_sj_,_su_,_ss_,_st_,_sa_,_4P_,_sl_,_sa_,_4P_,_su_,_sb_,_si_,_sc_,_sa_,_sc_,_si_,_EU_3D,_sn_,_4P_,_sd_,_se_,_sl_,_4P_,_sm_,_se_,_sn_,_EU_D1,_DOT,_END_,  //_SPANISH(Esp)
    0x5E,0x4F,0x61,0xc1,0x51,0x73,0xa0,0xa7,0xbA,0x6D,0x88,0x91,0x9D,0x49,0x7E,0xb8,0x38,0x5B,0x3B, _END_,   //_JAPAN   
    _sM_,_se_,_sn_,_EU_D2,_sp_,_so_,_ss_,_si_,_st_,_si_,_so_,_sn_,_4P_,_sa_,_sn_,_sp_,_sa_,_ss_,_ss_,_se_,_sn_,_DOT,_END_,                                     //_GERMAN(Deu)
    0xa6,0x68,0x53,0x52,0x1e,0x1b,0x1c,0x1d,0xa9,0xaa,0xab,_4P_,0x56,0x1d,0x1e,0x1d,0x65,0x68,0xb0,0x1b,0xac,_4P_,0xb3,0x68,0xb0,0x5b,_DOT,_END_,          //_RUSSIAN      
};


BYTE code tOSD_sFACTORY_DEFAULT_EXPLAIN1[] = //sResetTip
{
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _sR_,_se_,_ss_,_se_,_st_,_4P_,_sm_,_so_,_sn_,_si_,_st_,_so_,_sr_,_4P_,_st_,_so_,_4P_,_so_,_sr_,_si_,_sg_,_si_,_sn_,_sa_,_sl_,_4P_,_ss_,_se_,_st_,_st_,_si_,_sn_,_sg_,_ss_,_DOT, _END_,
#else
    _sR_,_se_,_ss_,_se_,_st_,_ss_,_4P_,_sm_,_so_,_sn_,_si_,_st_,_so_,_sr_,_4P_,_st_,_so_,_4P_,_so_,_sr_,_si_,_sg_,_si_,_sn_,_sa_,_sl_,_4P_,_ss_,_se_,_st_,_st_,_si_,_sn_,_sg_,_ss_,_DOT, _END_,
#endif
    _sR_,_EU_3A,_st_,_sa_,_sb_,_sl_,_si_,_st_,_4P_,_sl_,_se_,_ss_,_4P_,_sp_,_sa_,_sr_,_sa_,_sm_,_EU_3B,_st_,_sr_,_se_,_ss_,_4P_,_EU_CF,_so_,_sr_,_si_,_sg_,_si_,_sn_,_se_,_4P_,_sd_,_se_,_4P_,_EU_D9,_4P_,_EU_3A,_sc_,_sr_,_sa_,_sn_,_DOT,_END_,              //_FRENCH
    _sR_,_si_,_sp_,_so_,_sr_,_st_,_sa_,_4P_,_sl_,_so_,_4P_,_ss_,_sc_,_sh_,_se_,_sr_,_sm_,_so_,_4P_,_sa_,_sl_,_sl_,_se_,_4P_,_si_,_sm_,_sp_,_so_,_ss_,_st_,_sa_,_sz_,_si_,_so_,_sn_,_si_,_4P_,_so_,_sr_,_si_,_sg_,_si_,_sn_,_sa_,_sl_,_si_,_DOT,_END_,      //_ITALIAN
    0x4F,0x50,0x51,0x52,0x53,0x37,0x38,_END_,   //_CHINESE_S
    _sR_,_se_,_ss_,_st_,_sa_,_sb_,_sl_,_se_,_sc_,_se_,_4P_,_se_,_sl_,_4P_,_sm_,_so_,_sn_,_si_,_st_,_so_,_sr_,_4P_,_sa_,_4P_,_ss_,_su_,_ss_,_4P_,_sv_,_sa_,_sl_,_so_,_sr_,_se_,_ss_,_4P_,_so_,_sr_,_si_,_sg_,_si_,_sn_,_sa_,_sl_,_se_,_ss_,_DOT,_END_,    //_SPANISH(Esp)
    0x5F,0x4F,0x3F,0xc1,0x6D,0x84,0x76,0x78,0x86,0x9F,0x51,0x79,0x96,0x9E,0x7F,0x50,0xa6,0x38,0x5B,0x3B,_END_,  //_JAPAN   
    _sB_,_si_,_sl_,_sd_,_ss_,_sc_,_sh_,_si_,_sr_,_sm_,_4P_,_sa_,_su_,_sf_,_4P_,_sd_,_si_,_se_,_4P_,_su_,_sr_,_ss_,_sp_,_sr_,_EU_D2,_sn_,_sg_,_sl_,_si_,_sc_,_sh_,_se_,_sn_,_4P_,_sE_,_si_,_sn_,_ss_,_st_,_se_,_sl_,_sl_,_su_,_sn_,_sg_,_se_,_sn_,_END_,  //_GERMAN(Deu)          
    0x9f,0x1d,0xad,0xad,0xae,0xab,0xb0,0x1d,0xa9,0x1b,0xae,0x46,_4P_,0x1b,0xad,0x43,0x1d,0x66,0xb0,0xb2,0x68,_4P_,0xb0,0xab,0xad,0xae,0x1c,0x1d,0x1a,0xaa,0x1b,_4P_,0xb3,0x1d,0xb0,0x1b,0xae,0x1d,0x1c,0xab,_DOT,_END_,          //_RUSSIAN     
};


BYTE code tOSD_sFACTORY_DEFAULT_EXPLAIN2[] =
{
    _END_,
    _END_,    //_FRENCH
    _END_,    //_ITALIAN
    _END_,    //_CHINESE_S      
    _END_,    //_SPANISH(Esp)
    _END_,    //_JAPAN   
    _sz_,_su_,_sr_,_EU_D2,_sc_,_sk_,_ss_,_se_,_st_,_sz_,_se_,_sn_,_DOT,_END_, //_GERMAN(Deu)          
    _END_,  //_RUSSIAN     
};


BYTE code tOSD_sACCESSIBILITY_EXPLAIN1[] = // sChangeTimeOutTip
{
    _sC_,_sh_,_sa_,_sn_,_sg_,_se_,_4P_,_sb_,_su_,_st_,_st_,_so_,_sn_,_4P_,_sr_,_se_,_sp_,_se_,_sa_,_st_,_4P_,_sr_,_sa_,_st_,_se_,_4P_,_sa_,_sn_,_sd_,_4P_,_sm_,_se_,_sn_,_su_,_4P_,_st_,_si_,_sm_,_se_,_LINE,_so_,_su_,_st_,_4P_,_ss_,_se_,_st_,_st_,_si_,_sn_,_sg_,_ss_,_DOT,_END_,
    _sD_,_EU_3A,_sf_,_si_,_sn_,_si_,_st_,_4P_,_sl_,_sa_,_4P_,_sv_,_si_,_st_,_se_,_ss_,_ss_,_se_,_4P_,_sd_,_se_,_4P_,_sr_,_EU_3A,_sp_,_EU_3A,_st_,_si_,_st_,_si_,_so_,_sn_,_4P_,_sd_,_su_,_4P_,_sc_,_sl_,_sa_,_sv_,_si_,_se_,_sr_,_4P_,_se_,_st_,_4P_,_sl_,_se_,_4P_,_sd_,_EU_3A,_sl_,_sa_,_si_,_4P_,_sd_,_se_,_4P_,_END_,      //_FRENCH
    _sM_,_so_,_sd_,_si_,_sf_,_si_,_sc_,_sa_,_4P_,_sl_,_sa_,_4P_,_sv_,_se_,_sl_,_so_,_sc_,_si_,_st_,_EU_3C,_4P_,_sd_,_si_,_4P_,_sr_,_si_,_sp_,_se_,_st_,_si_,_sz_,_si_,_so_,_sn_,_se_,_4P_,_sd_,_se_,_si_,_4P_,_sp_,_su_,_sl_,_ss_,_sa_,_sn_,_st_,_si_,_4P_,_se_,_4P_,_sl_,_se_,_END_,                  //_ITALIAN
    0x49,0x4A,0x58,0x59,0x54,0x55,0x5A,0x21,0x3D,0x4B,0x4C,0x5B,0x5C,0x5D,0x5E,_END_,  //_CHINESE_S
    _sC_,_sa_,_sm_,_sb_,_si_,_sa_,_4P_,_sl_,_sa_,_4P_,_sc_,_sa_,_sd_,_se_,_sn_,_sc_,_si_,_sa_,_4P_,_sd_,_se_,_4P_,_sr_,_se_,_sp_,_se_,_st_,_si_,_sc_,_si_,_EU_3D,_sn_,_4P_,_sd_,_se_,_4P_,_sl_,_so_,_ss_,_4P_,_sb_,_so_,_st_,_so_,_sn_,_se_,_ss_,_4P_,_sy_,_4P_,_se_,_sl_,_4P_,_sv_,_sa_,_sl_,_so_,_sr_,_END_,     //_SPANISH(Esp)
    0x59,0x3F,0x6E,0x51,0xb3,0x7C,0xa4,0x81,0x4B,0x5E,0x4F,0x61,0xc1,0x51,0x9F,0x8A,0x97,0x6A,0x9E,0x7F,0x2D,0x72,0x83,0x49,0x2F,0x5B,0x3B, _END_,   //_JAPAN
    _sW_,_si_,_se_,_sd_,_se_,_sr_,_sh_,_so_,_sl_,_su_,_sn_,_sg_,_ss_,_sg_,_se_,_ss_,_sc_,_sh_,_sw_,_si_,_sn_,_sd_,_si_,_sg_,_sk_,_se_,_si_,_st_,_4P_,_sf_,_EU_D2,_sr_,_4P_,_sT_,_sa_,_ss_,_st_,_se_,_4P_,_su_,_sn_,_sd_,_4P_,_sE_,_si_,_sn_,_ss_,_st_,_se_,_sl_,_sl_,_su_,_sn_,_sg_,_4P_,_sf_,_EU_D2,_sr_,_END_,//_GERMAN(Deu)
    0xa4,0xaf,0xb3,0x68,0xb0,0x68,0xb0,0x1b,0x68,_4P_,0x67,0xab,0xad,0xae,0x1d,0xae,0xb2,_4P_,0x56,0x1d,0xa9,0xae,0x1d,0x1c,0xab,_4P_,0x56,0x1c,0x1b,_4P_,0xb0,0xab,0x65,0xab,0xae,0x1b,0x1b,_4P_,0xaa,0xb0,0x1d,0x56,0xaa,0x1b,_4P_,0x1b,_4P_,0xb0,0xab,0xad,0xae,0x1c,0x1d,0x68,0xaa, _END_,//_RUSSIAN
};


BYTE code tOSD_sACCESSIBILITY_EXPLAIN2[] =
{
    _END_,
    _sd_,_EU_3A,_sp_,_sa_,_ss_,_ss_,_se_,_sm_,_se_,_sn_,_st_,_DOT,_END_,//_FRENCH
    _si_,_sm_,_sp_,_so_,_ss_,_st_,_sa_,_sz_,_si_,_so_,_sn_,_si_,_4P_,_sd_,_si_,_4P_,_st_,_si_,_sm_,_se_,_so_,_su_,_st_,_4P_,_sd_,_se_,_sl_,_4P_,_sm_,_se_,_sn_,_su_,_DOT,_END_,      //_ITALIAN
    _END_,  //_CHINESE_S 
    _sd_,_se_,_4P_,_st_,_si_,_se_,_sm_,_sp_,_so_,_4P_,_se_,_sx_,_sc_,_se_,_sd_,_si_,_sd_,_so_,_4P_,_sd_,_se_,_sl_,_4P_,_sm_,_se_,_sn_,_EU_D1,_DOT,_END_,     //_SPANISH(Esp)          
    _END_,  //_JAPAN     
    _sM_,_se_,_sn_,_EU_D2,_sz_,_se_,_si_,_st_,_sl_,_si_,_sm_,_si_,_st_,_4P_,_EU_D4,_sn_,_sd_,_se_,_sr_,_sn_,_DOT,_END_,     //_GERMAN(Deu)           
    0xa9,0x1c,0x68,0xb3,0x68,0xb0,0x1b,_4P_,0xaf,0xab,0xaa,0x1c,0xb2,0xae,0x1b,0xac,_4P_,0xb3,0x68,0xb0,0x5b,_DOT, _END_,//_RUSSIAN
};



//========================================================================================================================================================                                                                                                                                      
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
// sub item 
BYTE code tOSD_sCLOCK[] = //sClock
{
    _mC_,_ml_,_mo_,_mc_,_mk_, _END_,                  //_ENGLISH 
    _mH_,_mo_,_mr_,_ml_,_mo_,_mg_,_me_,_END_,             //_FRENCH
    _mO_,_mr_,_mo_,_ml_,_mo_,_mg_,_mi_,_mo_,_END_,        //_ITALIAN
    _TABSEL_CHT_BIG, _CH_72,_CH_73,_CH_74, _END_, //_CHINESE_S
    _mR_,_me_,_ml_,_mo_,_mj_,_END_,                       //_SPANISH(Esp)                                              
    _TABSEL_JAP_BIG1, _JP_C6,_JP_C7,_JP_C8,_JP_C9,_JP_CA, _END_, //_JAPAN
    _mT_,_ma_,_mk_,_mt_,_mg_,_me_,_mb_,_me_,_mr_,_END_,   //_GERMAN(Deu)                                               
    0x7f,0x8f,0x9a,0x98,0x93,0x98,0x8f, _END_,  //_RUSSIAN                     
};

BYTE code tOSD_sPHASE[] = //sPhase
{
    _mP_,_mh_,_ma_,_ms_,_me_, _END_,       //_ENGLISH 
    _mP_,_mh_,_ma_,_ms_,_me_,_END_,       //_FRENCH
    _mF_,_ma_,_ms_,_me_, _END_,             //_ITALIAN
    _TABSEL_CHT_BIG, _CH_75,_CH_76,_CH_77, _END_, //_CHINESE_S
    _mF_,_ma_,_ms_,_me_,_END_,             //_SPANISH(Esp)                                                                
    _TABSEL_JAP_BIG1, _JP_CB,_JP_CC,_JP_CD, _END_, //_JAPAN
    _mP_,_mh_,_ma_,_ms_,_me_,_END_,       //_GERMAN(Deu)                                                                             
    0x7e,0x8f,0x85,0x8f, _END_,    //_RUSSIAN                        
};

BYTE code tOSD_sSAVE[] = //sManualItem_Eng     // clock and phase save ,  RGB save
{
    _mS_,_ma_,_mv_,_me_,_END_,                                                     //_ENGLISH
    _mS_,_ma_,_mu_,_mv_,_me_,_mg_,_ma_,_mr_,_md_,_me_,_mr_,_END_,           //_FRENCH
    _mS_,_ma_,_ml_,_mv_,_ma_,_END_,                                               //_ITALIAN
    _TABSEL_CHT_BIG, _CH_78,_CH_79,_CH_7A, _END_, //_CHINESE_S
    _mG_,_mu_,_ma_,_mr_,_md_,_ma_,_mr_,_END_,                                   //_SPANISH(Esp)                                   
    _TABSEL_JAP_BIG1, _JP_CE,_JP_CF,_JP_D0,_JP_D1, _END_, //_JAPAN
    _mS_,_mp_,_me_,_mi_,_mc_,_mh_,_me_,_mr_,_mn_, _END_,                       //_GERMAN(Deu)                                                                                                                                                                                                             
    0x74,0x93,0x9e,0x90,0x8f,0x8e,0x94,0x98,0x80, _END_,  //_RUSSIAN                      
};

BYTE code tOSD_sPRESET[] = //sColorItem_Eng
{
    _mP_,_mr_,_me_,_ms_,_me_,_mt_,_4P_,_mm_,_mo_,_md_,_me_, _END_,                                       //_ENGLISH                                             
    _mM_,_mo_,_md_,_me_,_4P_,_md_,_me_,_4P_,_mp_,_mr_,_EU_C2,_ms_,_EU_C2,_ml_,_me_,_mc_,_mt_,_mi_,_mo_,_mn_,_END_,    //_FRENCH                                              
    _mM_,_mo_,_md_,_mo_,_4P_,_mp_,_mr_,_me_,_ms_,_me_,_mt_,_END_,                                                        //_ITALIAN
    _TABSEL_CHT_BIG, _CH_49,_CH_4A,_CH_4B,_CH_4C,_CH_4D,_CH_4E, _END_, //_CHINESE_S 
    _mM_,_mo_,_md_,_ma_,_ml_,_mi_,_md_,_ma_,_md_,_4P_,_mp_,_mr_,_me_,_me_,_ms_,_mt_,_ma_,_mb_,_ml_,_me_,_mc_,_mi_,_md_,_ma_,_END_, //_SPANISH(Esp)  
    _TABSEL_JAP_BIG1,_JP_6F,_JP_70,_JP_71,_JP_72,_JP_73,_JP_74,_JP_75,_JP_76,_JP_77,_JP_78,_END_, //_JAPAN
    _mV_,_mo_,_mr_,_me_,_mi_,_mn_,_ms_,_mt_,_me_,_ml_,_ml_,_mu_,_mn_,_mg_,_ms_,_mm_,_mo_,_md_,_mu_,_ms_,_END_,          //_GERMAN(Deu)                                         
    0x72,0x8b,0x8a,0x94,0x96,_4P_,0x9a,_4P_,0x89,0x90,0x8b,0x92,0x84,0x9a,0x98,0x8f,0x8e,0x93,0x95,0x99,0x8f,0x96,0x94, _END_,            //_RUSSIAN 
};

BYTE code tOSD_sCUSTOM[] = //sColorItem_Eng
{
    _mC_,_mu_,_ms_,_mt_,_mo_,_mm_, _END_,                                 //_ENGLISH                                                                                   
    _mP_,_me_,_mr_,_ms_,_mo_,_mn_,_mn_,_ma_,_ml_,_mi_,_ms_,_EU_C2,_END_,     //_FRENCH                                                                                    
    _mP_,_me_,_mr_,_ms_,_mo_,_mn_,_ma_,_ml_,_mi_,_mz_,_mz_,_ma_,_END_,         //_ITALIAN      
    _TABSEL_CHT_BIG, _CH_4F,_CH_50,_CH_51, _END_, //_CHINESE_S
    _mP_,_me_,_mr_,_ms_,_mo_,_mn_,_ma_,_ml_,_mi_,_mz_,_ma_,_md_,_ma_,_END_,    //_SPANISH(Esp)                                                                                                                             
    _TABSEL_JAP_BIG1, _JP_7E,_JP_7F,_JP_80,_JP_81,_JP_82, _END_, //_JAPAN
    _mB_,_me_,_mn_,_mu_,_mt_,_mz_,_me_,_mr_,_md_,_me_,_mf_,_mi_,_mn_,_mi_,_me_,_mr_,_mt_,_END_,           //_GERMAN(Deu)                                                                                                                              
    0x71,0x93,0x86,0x80,0x85,0x93,0x95,0x8f,0x98,0x8b,0x86,0x80,0x9a,0x99,0x94,0x81, _END_,  //_RUSSIAN                        
};


BYTE code tOSD_sNEUTRAL[] = // sPresetsItems_Eng
{
    _mN_,_me_,_mu_,_mt_,_mr_,_ma_,_ml_, _END_,  //_ENGLISH                                     
    _mN_,_me_,_mu_,_mt_,_mr_,_me_, _END_,             //_FRENCH                                      
    _mN_,_me_,_mu_,_mt_,_mr_,_mo_,_END_,              //_ITALIAN        
    _TABSEL_CHT_BIG, _CH_7B,_CH_7C,_CH_7D,_CH_34,_CH_35,_CH_36, _END_, //_CHINESE_S
    _mN_,_me_,_mu_,_mt_,_mr_,_ma_,_ml_, _END_,  //_SPANISH(Esp)                                                         
    _TABSEL_JAP_BIG2, _JP_0C,_JP_0D,_JP_0E,_JP_0F, _END_, //_JAPAN
    _mN_,_me_,_mu_,_mt_,_mr_,_ma_,_ml_, _END_,       //_GERMAN(Deu)                                                          
    0x6d,0x8b,0x81,0x98,0x90,0x8f,0x86,0x80,0x8e,0x91,0x81, _END_,  //_RUSSIAN                                          
};

BYTE code tOSD_sSRGB[] = // sPresetsItems_Eng
{
    _ms_,_mR_,_mG_,_mB_, _END_,    //_ENGLISH                                                     
    _ms_,_mR_,_mG_,_mB_,_END_,        //_FRENCH                                                      
    _ms_,_mR_,_mG_,_mB_,_END_,        //_ITALIAN                                                     
    _TABSEL_CHT_ENG, _s_,_R_,_G_,_B_, _END_, //_CHINESE_S
    _ms_,_mR_,_mG_,_mB_,_END_,        //_SPANISH(Esp)                                                         
    _TABSEL_JAP_ENG, _s_,_R_,_G_,_B_,_END_, //_JAPAN
    _ms_,_mR_,_mG_,_mB_,_END_,        //_GERMAN(Deu)    
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    0x8d,0x6b,0x6c,0x6a,_END_,        //_RUSSIAN                                         
#else
#if(_PROJECT == _PRJ_L_LS2014_A_LBL) //Ada.chen 20150906_2
	0x8d,0x6b,0x6c,0x6a,_END_,		  //_RUSSIAN										 
#else
    0x74,0x98,0x8f,0x8e,0x92,0x8f,0x90,0x98,_4P_,0x8d,0x6b,0x6c,0x6a,_END_,        //_RUSSIAN                                         
#endif
#endif    
};

BYTE code tOSD_sREDDISH[] = // sPresetsItems_Eng
{
    _mR_,_me_,_md_,_md_,_mi_,_ms_,_mh_, _END_,               //_ENGLISH
    _mP_,_ml_,_mu_,_ms_,_4P_,_mr_,_mo_,_mu_,_mg_,_me_,_END_ ,   //_FRENCH
    _mP_,_mi_,_EU_CA,_4P_,_mR_,_mo_,_ms_,_ms_,_mo_,_END_,        //_ITALIAN
    _TABSEL_CHT_BIG, _CH_7E,_CH_7F,_CH_34,_CH_35,_CH_36, _END_, //_CHINESE_S
    _6P_,_mR_,_mo_,_mj_,_mi_,_mz_,_mo_, _END_,                     //_SPANISH(Esp)      
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _TABSEL_JAP_BIG2, _JP_00,_JP_01,_JP_02,_END_, //_JAPAN
#else
    _TABSEL_JAP_BIG2, _JP_06,_JP_07,_END_, //_JAPAN
#endif    
    _mR_,_EU_C8,_mt_,_ml_,_mi_,_mc_,_mh_,_END_,                 //_GERMAN(Deu)                                                                    
    0x6e,0x90,0x8f,0x9a,0x8e,0x93,0x95,0x8f,0x98,0x91,0x81, _END_,  //_RUSSIAN                        
};

BYTE code tOSD_sBLUISH[] = // sPresetsItems_Eng
{
    _mB_,_ml_,_mu_,_mi_,_ms_,_mh_,_END_,                //_ENGLISH
    _mP_,_ml_,_mu_,_ms_,_4P_,_mb_,_ml_,_me_,_mu_,_END_,        //_FRENCH
    _mP_,_mi_,_EU_CA,_4P_,_mB_,_ml_,_mu_,_END_,                 //_ITALIAN
    _TABSEL_CHT_BIG, _CH_80,_CH_81,_CH_34,_CH_35,_CH_36, _END_, //_CHINESE_S
    _mA_,_mz_,_mu_,_ml_,_ma_,_md_,_mo_, _END_,          //_SPANISH(Esp)                                                                 
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _TABSEL_JAP_BIG2, _JP_03,_JP_04,_JP_05, _END_, //_JAPAN
#else
    _TABSEL_JAP_BIG2, _JP_0A,_JP_0B, _END_, //_JAPAN
#endif
    _mB_,_ml_,_EU_CB,_mu_,_ml_,_mi_,_mc_,_mh_,_END_,        //_GERMAN(Deu)                                                                   
    0x74,0x94,0x8e,0x8b,0x95,0x8f,0x98,0x91,0x81,_END_,  //_RUSSIAN              
};

BYTE code tOSD_sRED[] = //sCustomColor_Eng
{
    _mR_,_me_,_md_, _END_,             //_ENGLISH
    _mR_,_mo_,_mu_,_mg_,_me_,_END_,      //_FRENCH
    _mR_,_mo_,_ms_,_ms_,_mo_,_END_,      //_ITALIAN
    _TABSEL_CHT_BIG, _CH_82,_CH_83, _END_, //_CHINESE_S
    _mR_,_mo_,_mj_,_mo_,_END_,           //_SPANISH(Esp)                                                                        
    _TABSEL_JAP_BIG2, _JP_06,_JP_07, _END_, //_JAPAN
    _mR_,_mo_,_mt_,_END_,                //_GERMAN(Deu)                                                                         
    0x6e,0x90,0x8f,0x9a,0x8e,0x91,0x81, _END_,  //_RUSSIAN 
};

BYTE code tOSD_sGREEN[] =//sCustomColor_Eng
{
    _mG_,_mr_,_me_,_me_,_mn_,_END_,  //_ENGLISH
    _mV_,_me_,_mr_,_mt_,_END_,            //_FRENCH
    _mV_,_me_,_mr_,_md_,_me_,_END_,       //_ITALIAN
    _TABSEL_CHT_BIG, _CH_84,_CH_85, _END_, //_CHINESE_S
    _mV_,_me_,_mr_,_md_,_me_,_END_,       //_SPANISH(Esp)                                                                        
    _TABSEL_JAP_BIG2, _JP_08,_JP_09, _END_, //_JAPAN
    _mG_,_mr_,_EU_C6,_mn_,_END_,            //_GERMAN(Deu)                                                                         
    0x75,0x8b,0x86,0x8b,0x8e,0x91,0x81,_END_,  //_RUSSIAN                         
};

BYTE code tOSD_sBLUE[] =//sCustomColor_Eng
{
    _mB_,_ml_,_mu_,_me_,_END_,     //_ENGLISH
    _mB_,_ml_,_me_,_mu_,_END_,         //_FRENCH
    _mB_,_ml_,_mu_,_END_,              //_ITALIAN
    _TABSEL_CHT_BIG, _CH_86,_CH_87, _END_, //_CHINESE_S
    _mA_,_mz_,_mu_,_ml_,_END_,         //_SPANISH(Esp)                                                                        
    _TABSEL_JAP_BIG2, _JP_0A,_JP_0B, _END_, //_JAPAN
    _mB_,_ml_,_ma_,_mu_,_END_,         //_GERMAN(Deu)                                                                         
    0x74,0x94,0x8e,0x94,0x81,_END_,  //_RUSSIAN                     
};

BYTE code tOSD_sANALOG[] = //sInputItem_Eng
{
    _A_, _n_, _a_, _l_, _o_, _g_, _END_,                  //_ENGLISH
    _A_, _n_, _a_, _l_, _o_, _g_, _i_, _q_, _u_, _e_, _END_,                       //_FRENCH
    _A_, _n_, _a_, _l_, _o_, _g_, _i_, _c_, _o_, _END_,                     //_ITALIAN
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _TABSEL_CHT_BIG,_CH_94,_CH_95,_CH_96,_END_,   //_CHINESE_S
#else
    _TABSEL_CHT_BIG,_1_, __4, _LINE, __4,_CH_94,_CH_95,_CH_96,_END_,   //_CHINESE_S
#endif    
    _A_, _n_, _a_, _l_, _EU_1D, _g_, _i_, _c_, _o_, _END_,              //_SPANISH(Esp)                                                             
    _TABSEL_JAP_BIG2,_JP_52,_JP_53,_JP_54,_JP_55,_JP_56, _END_,  //_JAPAN                                                                        
    _A_,_n_,_a_,_l_,_o_,_g_,_END_,                    //_GERMAN(Deu) 
    0x2c,0x4b,0x36,0x4c,0x5c,0x4a,0x5c,0x3f,0x37,0x3d,_END_,//_RUSSIAN                       

};

BYTE code tOSD_sDVI[] =  //sInputDigital
{
	_D_,_i_,_g_,_i_,_t_,_a_,_l_,_END_,
	_N_,_u_,_m_,_EU_0D,_r_,_i_,_q_,_u_,_e_,_END_,
	_D_,_i_,_g_,_i_,_t_,_a_,_l_,_e_,_END_,
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
	_TABSEL_CHT_BIG,_CH_97,_CH_98,_CH_99,_END_,   //_CHINESE_S
#else
	_TABSEL_CHT_BIG,_2_, __4, _LINE, __4,_CH_97,_CH_98,_CH_99,_END_,   //_CHINESE_S
#endif
	_D_,_i_,_g_,_i_,_t_,_a_,_l_,_END_,
    _TABSEL_JAP_BIG2,_JP_57,_JP_58,_JP_59,_JP_5A,_JP_5B, _END_,  //_JAPAN                                                                            
	_D_,_i_,_g_,_i_,_t_,_a_,_l_,_END_,
	0x29,0x4f,0x49,0x40,0x5c,0x3f,0x5c,0x3d,_END_,

};

BYTE code tOSD_sSCALING_OFF[] =  // sScalingItem_Eng 
{
     _O_,_r_,_i_,_g_,_i_,_n_,_a_,_l_,___,_A_,_R_, _END_,      //_ENGLISH
     _F_,_o_,_r_,_m_,_a_,_t_,___,_EU_D0,_i_,_m_,_a_,_g_,_e_,___,_EU_D0,_o_,_r_,_i_,_g_,_i_,_n_,_e_,_END_,      //_FRENCH    
     _F_,_o_,_r_,_m_,_a_,_t_,_o_,___,_o_,_r_,_i_,_g_,_i_,_n_,_a_,_l_,_e_, _END_,                                   //_ITALIAN                                                              
     _TABSEL_CHT_BIG, _CH_A8,_CH_A9,_CH_AA,_CH_AB,_CH_AC,_CH_AD,_CH_AE, _END_, //_CHINESE_S
     _A_,_R_,___,_O_,_r_,_i_,_g_,_i_,_n_,_a_,_l_, _END_,                             //_SPANISH(Esp)             
    _TABSEL_JAP_BIG1, _JP_66,_JP_67,_JP_68,_JP_69,_JP_6A,_JP_6B,_JP_6C,_JP_6D,_JP_6E, _END_, //_JAPAN
     _O_,_r_,_i_,_g_,_i_,_n_,_a_,_l_,_f_,_o_,_r_,_m_,_a_,_t_, _END_,                                                     //_GERMAN(Deu)                                                          
     0x9c,0x3b,0x48,0x5c,0x42,0x4b,0x37,0x3d,_4P_,0x49,0x5c,0x40,0x41,0x36,0x3e, _END_,    //_RUSSIAN 
   
};

BYTE code tOSD_sSCALING_ON[] = //sScalingItem_Eng
{
    _F_,_u_,_l_,_l_,___,_S_,_c_,_r_,_e_,_e_,_n_, _END_,                                           //_ENGLISH  
    _P_,_l_,_e_,_i_,_n_,___,_EU_0D,_c_,_r_,_a_,_n_, _END_,                //_FRENCH                               
    _S_,_c_,_h_,_e_,_r_,_m_,_o_,_4P_,_i_,_n_,_t_,_e_,_r_,_o_,_END_,  //_ITALIAN                          
    _TABSEL_CHT_BIG, _CH_AF,_CH_B0,_CH_B1,_CH_B2, _END_, //_CHINESE_S
    _P_,_a_,_n_,_t_,_a_,_l_,_l_,_a_,___,_C_,_o_,_m_,_p_,_l_,_e_,_t_,_a_, _END_,    //_SPANISH(Esp)                               
    _TABSEL_JAP_BIG1, _JP_61,_JP_62,_JP_63,_JP_64,_JP_65, _END_, //_JAPAN
    _V_,_o_,_l_,_l_,_b_,_i_,_l_,_d_, _END_,                   //_GERMAN(Deu)                           
    0x35,0x36,_4P_,0x3f,0x4d,0x3b,0x3c,_4P_,0x51,0x38,0x40,0x36,0x4b, _END_,    //_RUSSIAN 
    
};

BYTE code tOSD_sENGLISH[] =
{
    _E_, _n_, _g_, _l_, _i_, _s_, _h_, _END_,
};

BYTE code tOSD_sFRENCH[] =
{
    _F_, _r_, _a_, _n_, _EU_D7, _a_, _i_, _s_, _END_,
};

BYTE code tOSD_sITALIAN[] =
{
    _I_, _t_, _a_, _l_, _i_, _a_, _n_, _o_, _END_,
};

BYTE code tOSD_sCHINESE_S[] =
{
    ___, _END_,
    ___, _END_,
    ___, _END_,
#if 0// lorimiao 20150716 for font size modify   
    _TABSEL_CHT_BIG, _CH_BC,_CH_BD,_CH_BE,_CH_BF,_CH_C0, _END_, //_CHINESE_S
#else    
    _TABSEL_CHT_BIG, _CH_B3,_CH_B4,_CH_B5,_CH_B6,_CH_B7, _END_, //_CHINESE_S
#endif
};

BYTE code tOSD_sSPANISH[] =
{
    _E_, _s_, _p_, _a_, _EU_D8, _o_, _l_, _END_,
};

BYTE code tOSD_sJAPAN[] =
{
    ___, _END_,
    ___, _END_,
    ___, _END_,
    ___, _END_,
    
    ___, _END_,
    _TABSEL_JAP_BIG2, _JP_25,_JP_26,_JP_27,_JP_28, _END_, //_JAPAN

};

BYTE code tOSD_sGERMAN[] =
{
    _D_, _e_, _u_, _t_, _s_, _c_, _h_, _END_,
};

BYTE code tOSD_sRUSSIAN[] =
{
    ___, _END_,
    ___, _END_,
    ___, _END_,
    ___, _END_,
    ___, _END_,
    ___, _END_,
    ___, _END_,
    0x25,0x5f,0x3b,0x3b,0x38,0x4f,0x3d,_END_,
};

BYTE code tOSD_sMODE[] = // sMode
{
    _M_,_o_,_d_,_e_,_END_,                               //_ENGLISH 
    _M_,_o_,_d_,_e_, _END_,                               //_FRENCH
    _M_,_o_,_d_,_o_,_END_,                               //_ITALIAN
    _TABSEL_CHT_BIG, _CH_4C,_CH_4D,_CH_4E, _END_, //_CHINESE_S
    _M_,_o_,_d_,_a_,_l_,_i_,_d_,_a_,_d_,_END_,    //_SPANISH(Esp)                                                                                                                        
    _TABSEL_JAP_BIG1, _JP_89,_JP_8A,_JP_8B,_JP_8C, _END_, //_JAPAN
    _M_,_o_,_d_,_u_,_s_,_END_,                         //_GERMAN(Deu)                                                                                                                               
    0X25,0x4d,0x4e,0x4f,0x41, _END_,             //_RUSSIAN                      
};

BYTE code tOSD_sMODE_NAME[] = //sModelName
{
    _M_,_o_,_d_,_e_,_l_,_6P_,_n_,_a_,_m_,_e_,_END_,                                 //_ENGLISH
    _N_,_o_,_m_,_6P_,_d_,_u_,_6P_,_m_,_o_,_d_,0xe4,_l_,_e_,_END_,     //_FRENCH
    _N_,_o_,_m_,_e_,_6P_,_m_,_o_,_d_,_e_,_l_,_l_,_o_,_END_,               //_ITALIAN
    _TABSEL_CHT_BIG, _CH_55,_CH_56,_CH_57,_CH_58, _END_, //_CHINESE_S
    _N_,_o_,_m_,_b_,_r_,_e_,_6P_,_d_,_e_,_l_,_6P_,_m_,_o_,_d_,_e_,_l_,_o_,_END_,   //_SPANISH(Esp)                                              
    _TABSEL_JAP_BIG1, _JP_8D,_JP_8E,_JP_8F,_JP_90,_JP_91,_JP_92, _END_, //_JAPAN
    _M_,_o_,_d_,_e_,_l_,_l_,_n_,_a_,_m_,_e_,_END_,                                    //_GERMAN(Deu)                                                                           
    0x35,0x36,0x51,0x3f,0x36,0x4b,0x4f,0x4d,_4P_,0x41,0x5c,0x42,0x4d,0x4c,0x4f, _END_,    //_RUSSIAN                    
};

BYTE code tOSD_scMODE_NAME[] =
{
    _MODEL_NAME, _END_,
};


BYTE code tOSD_sMICROCODE[] = // sMicrocode
{
    _M_,_i_,_c_,_r_,_o_,_c_,_o_,_d_,_e_, _END_,                    //_ENGLISH    
    _M_,_i_,_c_,_r_,_o_,_c_,_o_,_d_,_e_, _END_,                    //_FRENCH
    _M_,_i_,_c_,_r_,_o_,_c_,_o_,_d_,_i_,_c_,_e_,_END_,        //_ITALIAN
    _TABSEL_CHT_BIG,_CH_59,_CH_5A,_CH_5B,_CH_5C,_END_,                                               //_CHINESE_S                                                                                                                                       
    _M_,_i_,_c_,_r_,_o_,_c_,_EU_1D,_d_,_i_,_g_,_o_,_END_,    //_SPANISH(Esp)                                                                             
    _TABSEL_JAP_BIG1, _JP_93,_JP_94,_JP_95,_JP_96,_JP_97,_JP_98,_JP_99,_JP_9A, _END_, //_JAPAN
    _M_,_i_,_k_,_r_,_o_,_c_,_o_,_d_,_e_,_END_,                             //_GERMAN(Deu)                                                                             
    0x31,0x4f,0x38,0x40,0x5c,0x38,0x5c,0x42,_END_,    //_RUSSIAN                  
};

BYTE code tOSD_scMICROCODE[] =
{
     _MICROCODE, _END_,   
};


BYTE code tOSD_sDEFAULT[] = // sOsdPosItem_Eng  // position default
{                                                                                               
    _D_,_e_,_f_,_a_,_u_,_l_,_t_,_END_,                                               //_ENGLISH
    _P_,_a_,_r_,_6P_,_d_,_EU_0D,_f_,_a_,_u_,_t_, _END_,                          //_FRENCH
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _V_,_a_,_l_,_o_,_r_,_e_,_6P_,_p_,_r_,_e_,_d_,_e_,_f_,_i_,_n_,_i_,_t_,_o_, _END_,      //_ITALIAN
#else
    _V_,_a_,_l_,_o_,_r_,_e_,_6P_,_P_,_r_,_e_,_d_,_e_,_f_,_i_,_n_,_i_,_t_,_o_, _END_,      //_ITALIAN
#endif
    _TABSEL_CHT_BIG, _CH_66,_CH_67,_CH_68,_CH_69, _END_, //_CHINESE_S
    _P_,_o_,_r_,_6P_,_o_,_m_,_i_,_s_,_i_,_EU_1D,_n_,_END_,                       //_SPANISH(Esp)                                                  
    _TABSEL_JAP_BIG1, _JP_79,_JP_7A,_JP_7B,_JP_7C,_JP_7D, _END_, //_JAPAN
    _S_,_t_,_a_,_n_,_d_,_a_,_r_,_d_,_e_,_i_,_n_,_s_,_t_,_e_,_l_,_l_,_u_,_n_,_g_, _END_,     //_GERMAN(Deu)                                                                                  
    0x24,0x5c,_4P_,0x5f,0x41,0x5c,0x4c,0x47,0x36,0x4b,0x4f,0x39, _END_,                //_RUSSIAN     
};

BYTE code tOSD_sOSDPOSITIONCUSTOM[] = // sOsdPosCustomItem_Eng
{
    _C_,_u_,_s_,_t_,_o_,_m_,_END_,    //_ENGLISH                                       
    _P_,_e_,_r_,_s_,_o_,_n_,_n_,_a_,_l_,_i_,_s_,_EU_0D,_END_,              //_FRENCH                                        
    _P_,_e_,_r_,_s_,_o_,_n_,_a_,_l_,_i_,_z_,_z_,_a_,_END_,         //_ITALIAN                                       
    _TABSEL_CHT_BIG,_CH_4F,_CH_50,_CH_51,_END_,                                              //_CHINESE_S 
    _P_,_e_,_r_,_s_,_o_,_n_,_a_,_l_,_i_,_z_,_a_,_d_,_a_,_END_,              //_SPANISH(Esp)    
    _TABSEL_JAP_BIG1,_JP_7E,_JP_7F,_JP_80,_JP_81,_JP_82, _END_,                                              //_JAPAN                                                                                                       
    _B_,_e_,_n_,_u_,_t_,_z_,_e_,_r_,_d_,_e_,_f_,_i_,_n_,_i_,_e_,_r_,_t_,_END_,              //_GERMAN(Deu)                                   
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) 								
	0x24,0x5c,0x4c,0x3c,0x51,0x5c,0x3f,0x36,0x3e,0x4d,0x4c,0x3c,0x3b,0x38,0x5c,0x4d,_END_,  //_RUSSIAN  
#else
    0x24,0x5c,0x4c,0x3c,0x51,0x5c,0x3f,0x36,0x3e,0x4d,0x4c,0x3c,0x3b,0x38,0x4f,0x3d,/*0x5c,0x4d,*/ _END_,  //_RUSSIAN  
#endif
#else
    0x24,0x5c,0x4c,0x3c,0x51,0x5c,0x3f,0x36,0x3e,0x4d,0x4c,0x3c,0x3b,0x38,0x5c,0x4d, _END_,  //_RUSSIAN                                                                  
#endif
};


BYTE code tOSD_sOSDHPOS[] = // sOsdPosCustomItem_Eng
{
    _mH_,_mo_,_mr_,_mi_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_END_,    //_ENGLISH                                       
    _mH_,_mo_,_mr_,_mi_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_END_,              //_FRENCH                                        
    _mO_,_mr_,_mi_,_mz_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_me_,_END_,         //_ITALIAN                                       
    0x2f,0x30, _END_,                                              //_CHINESE_S 
    _mH_,_mo_,_mr_,_mi_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_END_,              //_SPANISH(Esp)    
    0xa3,0x95, _END_,                                              //_JAPAN                                                                                                       
    _mH_,_mo_,_mr_,_mi_,_mz_,_mo_,_mn_,_mt_,_ma_,_ml_,_END_,              //_GERMAN(Deu)                                   
    0x71,0x93,_4P_,0x88,0x93,0x90,0x94,0x85,0x93,0x8e,0x98,0x8f,0x86,0x94, _END_,  //_RUSSIAN                                                                  

};

BYTE code tOSD_sOSDVPOS[] = // sOsdPosCustomItem_Eng
{
    _mV_,_me_,_mr_,_mt_,_mi_,_mc_,_ma_,_ml_,_END_,   //_ENGLISH                                               
    _mV_,_me_,_mr_,_mt_,_mi_,_mc_,_ma_,_ml_,_END_,                 //_FRENCH                                                
    _mV_,_me_,_mr_,_mt_,_mi_,_mc_,_ma_,_ml_,_me_,_END_,            //_ITALIAN                                               
    0x33,0x34, _END_,                                       //_CHINESE_S
    _mV_,_me_,_mr_,_mt_,_mi_,_mc_,_ma_,_ml_,_END_,                 //_SPANISH(Esp)                                          
    0x7B,0xb9, _END_,                                       //_JAPAN                                                                                                       
    _mV_,_me_,_mr_,_mt_,_mi_,_mk_,_ma_,_ml_,_END_,                 //_GERMAN(Deu)                                           
    0x71,0x93,_4P_,0x95,0x8b,0x90,0x98,0x94,0x99,0x8f,0x86,0x94,_END_,    //_RUSSIAN                                                          
};

BYTE code tOSD_sOSDPOSITIONSAVE[] = //sManualItem_Eng     // osd HV position save
{
    _mS_,_ma_,_mv_,_me_,_END_,                                                     //_ENGLISH
    _mS_,_ma_,_mu_,_mv_,_me_,_mg_,_ma_,_mr_,_md_,_me_,_mr_,_END_,           //_FRENCH
    _mS_,_ma_,_ml_,_mv_,_ma_,_END_,                                               //_ITALIAN
    0x61,0x62, _END_, //_CHINESE_S
    _mG_,_mu_,_ma_,_mr_,_md_,_ma_,_mr_,_END_,                                   //_SPANISH(Esp)                                   
    0x3d,0xc1,0x57, _END_, //_JAPAN
    _mS_,_mp_,_me_,_mi_,_mc_,_mh_,_me_,_mr_,_mn_, _END_,                       //_GERMAN(Deu)                                                                                                                                                                                                             
    0x74,0x93,0x9e,0x90,0x8f,0x8e,0x94,0x98,0x80, _END_,  //_RUSSIAN                      
};


BYTE code tOSD_sCANCEL[]= // sResetItem_Eng
{
    _C_,_a_,_n_,_c_,_e_,_l_,_END_,                            //_ENGLISH                                            
    _A_,_n_,_n_,_u_,_l_,_e_,_r_,_END_,    //_FRENCH                
    _A_,_n_,_n_,_u_,_l_,_l_,_a_,_END_,                                 //_ITALIAN                                            
    _TABSEL_CHT_BIG, _CH_00,_CH_88,_CH_89,_CH_8A, _END_, //_CHINESE_S
    _C_,_a_,_n_,_c_,_e_,_l_,_a_,_r_,_END_,                       //_SPANISH(Esp)                                       
    _TABSEL_JAP_BIG2, _JP_10,_JP_11,_JP_12,_JP_13 ,_JP_14 ,_JP_15 ,_JP_16 ,_END_, //_JAPAN
    _A_,_b_,_b_,_r_,_e_,_c_,_h_,_e_,_n_,_END_,             //_GERMAN(Deu)                                        
    0x2d,0x3e,0x41,0x4d,0x4b,0x36, _END_,                 //_RUSSIAN                                    
};


BYTE code tOSD_sRESET[] = //sResetItem_Eng
{
    _R_,_e_,_s_,_e_,_t_, _END_,                            //_ENGLISH                                            
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _R_,_EU_0D,_i_,_n_,_i_,_t_,_i_,_a_,_l_,_i_,_s_,_a_,_t_,_i_,_o_,_n_,_END_,    //_FRENCH                
#else
    _R_,_EU_0D,_i_,_n_,_t_,_i_,_a_,_l_,_i_,_s_,_a_,_t_,_i_,_o_,_n_,_END_,    //_FRENCH                
#endif
    _R_,_e_,_s_,_e_,_t_,_END_,                                 //_ITALIAN                                            
    _TABSEL_CHT_BIG, _CH_8B,_CH_8C,_CH_8D, _END_, //_CHINESE_S
    _R_,_e_,_s_,_t_,_a_,_b_,_l_,_e_,_c_,_e_,_r_,_END_,                       //_SPANISH(Esp)                                       
    _TABSEL_JAP_BIG2, _JP_17,_JP_18,_JP_19,_JP_1A,_END_, //_JAPAN
    _Z_,_u_,_r_,_EU_1C,_c_,_k_,_s_,_e_,_t_,_z_,_e_,_n_,_END_,             //_GERMAN(Deu)                                        
    0x2a,0x50,0x40,0x5c,0x3b, _END_,                 //_RUSSIAN                                    
};

BYTE code tOSD_sBUTTON_REPEAT[] = // sButtonRepeatRate_Eng
{
    _mB_,_mu_,_mt_,_mt_,_mo_,_mn_,_4P_,_mr_,_me_,_mp_,_me_,_ma_,_mt_,_4P_,_mr_,_ma_,_mt_,_me_,_END_,  //_ENGLISH         
    _mV_,_mi_,_mt_,_me_,_ms_,_ms_,_me_,_4P_,_md_,_me_,_4P_,_mr_,_EU_C2,_mp_,_EU_C2,_mt_,_mi_,_mt_,_mi_,_mo_,_mn_,_4P_,_md_,_mu_,_4P_,_mc_,_ml_,_ma_,_mv_,_mi_,_me_,_mr_,_END_,  //_FRENCH          
    _mV_,_me_,_ml_,_mo_,_mc_,_mi_,_mt_,_EU_C3,_4P_,_md_,_mi_,_4P_,_mr_,_mi_,_mp_,_me_,_mt_,_mi_,_mz_,_mi_,_mo_,_mn_,_me_,_4P_,_mp_,_mu_,_ml_,_ms_,_ma_,_mn_,_mt_,_me_,_END_,     //_ITALIAN         
    0x58,0x59,0x6c,0x55,0x5a,0x21,_END_, 
    _mC_,_ma_,_md_,_me_,_mn_,_mc_,_mi_,_ma_,_4P_,_md_,_me_,_4P_,_mr_,_me_,_mp_,_me_,_mt_,_mi_,_mc_,_mi_,_EU_C4,_mn_,_4P_,_md_,_me_,_4P_,_mb_,_mo_,_mt_,_mo_,_mn_,_me_,_ms_,_END_, //_SPANISH(Esp)    
    0x59,0x3F,0x6E,0x51,0xb3,0x7C,0xa4,0x81, _END_,//_JAPAN           
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _mW_,_mi_,_me_,_md_,_me_,_mr_,_mh_,_mo_,_ml_,_mu_,_mn_,_mg_,_ms_,_mg_,_me_,_ms_,_mc_,_mh_,_mw_,_mi_,_mn_,_md_,_mi_,_mg_,_mk_,_me_,_mi_,_mt_,_4P_,_mf_,_EU_C6,_mr_,_4P_,_mT_,_ma_,_ms_,_mt_,_me_,_END_, //_GERMAN(Deu)     
#else
    _mW_,_mi_,_me_,_md_,_me_,_mr_,_mh_,_mo_,_ml_,_mu_,_mn_,_mg_,_ms_,_mg_,_me_,_ms_,_mc_,_mh_,_mw_,_mi_,_mn_,_md_,_mi_,_mg_,_mp_,_mk_,_me_,_mi_,_mt_,_4P_,_mf_,_EU_C6,_mr_,_4P_,_mT_,_ma_,_ms_,_mt_,_me_,_END_, //_GERMAN(Deu)     
#endif
    0x7f,0x8f,0x9a,0x98,0x93,0x98,0x8f,_4P_,0x89,0x93,0x95,0x98,0x93,0x90,0x8f,_4P_,0x89,0x90,0x94,_4P_,0x8e,0x8f,0x8a,0x8f,0x98,0x94,0x94,_4P_,0x99,0x8e,0x93,0x89,0x99,0x94, _END_,//_RUSSIAN                   
};

BYTE code tOSD_sMENU_TIMEOUT[] = // sMenuTimeOut
{
    _mM_,_me_,_mn_,_mu_,_4P_,_mt_,_mi_,_mm_,_me_,_4P_,_mo_,_mu_,_mt_, _END_,   //_ENGLISH         
    _mD_,_EU_C2,_mp_,_ma_,_ms_,_ms_,_me_,_mm_,_me_,_mn_,_mt_,_4P_,_md_,_mu_,_4P_,_md_,_EU_C2,_ml_,_ma_,_mi_,_4P_,_EU_C9,_ma_,_mf_,_mf_,_mi_,_mc_,_mh_,_ma_,_mg_,_me_,_4P_,_md_,_mu_,_4P_,_mm_,_me_,_mn_,_mu_,_END_, //_FRENCH          
    _mT_,_mi_,_mm_,_me_,_mo_,_mu_,_mt_,_4P_,_mm_,_me_,_mn_,_mu_,_END_,                    //_ITALIAN         
    0x4b,0x4c,0x5b,0x5c,0x5d,0x5e,_END_,                         //_CHINESE_S 
    _mT_,_mi_,_me_,_mm_,_mp_,_mo_,_4P_,_me_,_mx_,_mc_,_me_,_md_,_mi_,_md_,_mo_,_4P_,_md_,_me_,_ml_,_4P_,_mm_,_me_,_mn_,_EU_C7,_END_, //_SPANISH(Esp)    
    0x5E,0x4F,0x61,0xc1,0x51,0x9F,0x8A,0x97,0x6A,_END_,                 //_JAPAN          
    _mM_,_me_,_mn_,_EU_C6,_mz_,_me_,_mi_,_mt_,_ml_,_mi_,_mm_,_mi_,_mt_,_END_,          //_GERMAN(Deu)     
    0x6a,0x90,0x8b,0x96,0x83,_4P_,0x85,0x8f,0x99,0x90,0x91,0x98,0x94,0x83,_4P_,0x96,0x8b,0x8e,0x9b,_END_,//_RUSSIAN          
};

BYTE code tOSD_sOFF[] =  // sBtnRepeatItem_Eng
{
    _mO_,_mf_,_mf_, _END_,   //_ENGLISH        
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
    _mD_,_EU_C2,_ms_,_ma_,_mc_,_mt_,_mi_,_mv_,_EU_C2, _END_, //_FRENCH         
    _mO_,_mf_,_mf_,_END_,   //_ITALIAN        
    0x6d, _END_,            //_CHINESE_S 
    _mD_,_me_,_ms_,_ma_,_mc_,_mt_,_mi_,_mv_,_ma_,_md_,_ma_,_END_, //_SPANISH(Esp)   
#else
    _mE_,_mt_,_me_,_mi_,_mn_,_mt_, _END_, //_FRENCH         
    _mD_,_mi_,_ms_,_ma_,_mt_,_mt_,_mi_,_mv_,_ma_,_mt_,_mo_,_END_,   //_ITALIAN
    0x6d, _END_,            //_CHINESE_S 
    _mA_,_mp_,_ma_,_mg_,_ma_,_md_,_mo_,_END_, //_SPANISH(Esp)  
#endif
#else
    _mD_,_EU_C2,_ms_,_ma_,_mc_,_mt_,_mi_,_mv_,_EU_C2, _END_, //_FRENCH         
    _mO_,_mf_,_mf_,_END_,   //_ITALIAN        
    0x6d, _END_,            //_CHINESE_S 
    _mD_,_me_,_ms_,_ma_,_mc_,_mt_,_mi_,_mv_,_ma_,_md_,_ma_,_END_, //_SPANISH(Esp)   
#endif
    0x2A,0x56,_END_,   //_JAPAN          
    _mA_,_mu_,_ms_,_END_,   //_GERMAN(Deu)    
    0x6a,0x91,0x99,0x86, _END_,                 //_RUSSIAN                                  
};

#if((_LENOVO_DPS_SUPPORT == _ON) || (_OD_SUPPORT == _ON)||(_USER_DCR_FUNCTION == _ON))
BYTE code tOSD_sON[] =  // sBtnRepeatItem_Eng
{
    _mO_,_mn_, _END_,   //_ENGLISH        
    _mS_,_mu_,_mr_, _END_, //_FRENCH         
    _mA_,_mt_,_mt_,_mi_,_mv_,_ma_,_mt_,_mo_,_END_,   //_ITALIAN       
    _CH_91, _END_,            //_CHINESE_S 
    _mE_,_mn_,_mc_,_me_,_md_,_mi_,_md_,_mo_,_END_, //_SPANISH(Esp)  
    0x2A,0x6E,_END_,   //_JAPAN          
    _mA_,_mu_,_mf_,_END_,   //_GERMAN(Deu)    
    0x6a,0x99,0x86, _END_,                 //_RUSSIAN                                  
};
#endif

BYTE code tOSD_sBTNDEFAULT[] = // sBtnRepeatItem_Eng // BTN default
{                                                                                               
    _mD_,_me_,_mf_,_ma_,_mu_,_ml_,_mt_,_END_,                                               //_ENGLISH
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    _mP_,_ma_,_mr_,_4P_,_md_,_EU_C2,_mf_,_ma_,_mu_,_mt_,_END_,                          //_FRENCH
    _mV_,_ma_,_ml_,_mo_,_mr_,_me_,_4P_,_mp_,_mr_,_me_,_md_,_me_,_mf_,_mi_,_mn_,_mi_,_mt_,_mo_, _END_,      //_ITALIAN
#else
    _mP_,_ma_,_mr_,_4P_,_mD_,_EU_C2,_mf_,_ma_,_mu_,_mt_,_END_,                          //_FRENCH
    _mV_,_ma_,_ml_,_mo_,_mr_,_me_,_4P_,_mP_,_mr_,_me_,_md_,_me_,_mf_,_mi_,_mn_,_mi_,_mt_,_mo_, _END_,      //_ITALIAN
#endif
    0x6a,0x6b, _END_, //_CHINESE_S
    _mP_,_mo_,_mr_,_4P_,_mo_,_mm_,_mi_,_ms_,_mi_,_EU_C4,_mn_,_END_,                       //_SPANISH(Esp)                                                  
    0x48,0x56,0x21,0x67,0x4a, _END_, //_JAPAN
    _mS_,_mt_,_mr_,_mo_,_mm_,_ms_,_mp_,_ma_,_mr_,_mm_,_mo_,_md_,_mu_,_ms_, _END_,     //_GERMAN(Deu)                                                                                  
    0X24,0x5c,_4P_,0x5f,0x41,0x5c,0x4c,0x47,0x36,0x4b,0x4f,0x39, _END_,                //_RUSSIAN     
};


BYTE code tOSD_sSLOW[] = // sBtnRepeatItem_Eng
{
    _mS_,_ml_,_mo_,_mw_, _END_,            //_ENGLISH             
    _mL_,_me_,_mn_,_mt_, _END_,            //_FRENCH          
    _mL_,_me_,_mn_,_mt_,_mo_, _END_,      //_ITALIAN         
    0x6e, _END_,                           //_CHINESE_S 
    _mL_,_me_,_mn_,_mt_,_ma_,_END_,      //_SPANISH(Esp)    
    0x3A,0x6B,0xc1, _END_,         //_JAPAN           
    _mL_,_ma_,_mn_,_mg_,_ms_,_ma_,_mm_,_END_, //_GERMAN(Deu)     
    0x76,0x8b,0x92,0x86,0x8b,0x8e,0x8e,0x91,0x81,_END_,     //_RUSSIAN          
};


BYTE code tOSD_sAUTOADJUST_0[] = // sAutomaticAdjust
{
    _mI_,_mm_,_ma_,_mg_,_me_,_4P_,_ms_,_me_,_mt_,_mu_,_mp_,_COLON,_4P_,_mA_,_mu_,_mt_,_mo_,_mm_,_ma_,_mt_,_mi_,_mc_, _END_,               //_ENGLISH
    _mC_,_mo_,_mn_,_mf_,_mi_,_mg_,_mu_,_mr_,_ma_,_mt_,_mi_,_mo_,_mn_,_4P_,_md_,_me_,_4P_,_EU_CC,_mi_,_mm_,_ma_,_mg_,_me_,_COLON,_4P_,_mA_,_mu_,_mt_,_mo_,_mm_,_ma_,_mt_,_mi_,_mq_,_mu_,_me_, _END_,  //_FRENCH                                                                               
    _mI_,_mm_,_mp_,_mo_,_ms_,_mt_,_ma_,_mz_,_mi_,_mo_,_mn_,_me_,_4P_,_mi_,_mm_,_mm_,_ma_,_mg_,_mi_,_mn_,_me_,_COLON,_4P_,_mA_,_mu_,_mt_,_mo_,_mm_,_ma_,_mt_,_mi_,_mc_,_mo_, _END_,            //_ITALIAN                                                                              
    0x2b,0x2c,0x37,0x38,_COMMA,0x35,0x32,0x37,0x38, _END_,                                     //_CHINESE_S                                                                                
    _mC_,_mo_,_mn_,_mf_,_mi_,_mg_,_mu_,_mr_,_ma_,_mc_,_mi_,_EU_C4,_mn_,_4P_,_md_,_me_,_4P_,_ml_,_ma_,_4P_,_mi_,_mm_,_ma_,_mg_,_me_,_mn_,_COLON,_4P_,_mA_,_mu_,_mt_,_mo_,_mm_,_EU_C5,_mt_,_mi_,_mc_,_ma_,_END_,     //_SPANISH(Esp)                                                                         
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) //lorimiao 20140531
    0x88,0xac,0x51,0xbE,0x80,0x7E,0xb8,0x6D,0xae,0x26,0x5b,0x3b,_END_,//_JAPAN                                                                                             
#else
    0x88,0xac,0x51,0xbE,0x80,0x7E,0xb8,0x40,0xae,0x26,0x5b,0x3b,_END_,//_JAPAN                                                                                             
#endif
    //0x25,0x5E,0xc1,0x39,_4P_,0x3D,0x44,0x4A,0x23,0x44,0x58,_COLON,0xbE,0x80,0x7E,0xb8,_END_,//_JAPAN                                                                                             
    _mB_,_mi_,_ml_,_md_,_ma_,_mu_,_mf_,_mb_,_ma_,_mu_,_COLON,_4P_,_mA_,_mu_,_mt_,_mo_,_mm_,_ma_,_mt_,_mi_,_ms_,_mc_,_mh_, _END_, //_GERMAN(Deu)                                                                          
    0x6d,0x8f,0x9a,0x98,0x90,0x93,0x81,0x99,0x8f,_4P_,0x94,0x85,0x93,0x82,0x90,0x8f,0x8a,0x8b,0x8e,0x94,0x83,_COLON,0x70,0x95,0x98,0x93,0x96,0x8f,0x98,0x94,0x97,0x8b,0x9a,0x99,0x8f,0x83, _END_,             //_RUSSIAN  
};

//細體
BYTE code tOSD_sAUTOADJUST_1[] = // sOptimizingWaitTip
{
    _sO_,_sp_,_st_,_si_,_sm_,_si_,_sz_,_si_,_sn_,_sg_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_COMMA,_sp_,_sl_,_se_,_sa_,_ss_,_se_,_4P_,_sw_,_sa_,_si_,_st_,_DOT,_DOT,_DOT,_END_, //_ENGLISH
    _sO_,_sp_,_st_,_si_,_sm_,_si_,_ss_,_sa_,_st_,_si_,_so_,_sn_,_4P_,_sd_,_se_,_4P_,_EU_D9,_si_,_sm_,_sa_,_sg_,_se_,_4P_,_se_,_sn_,_4P_,_sc_,_so_,_su_,_sr_,_ss_,_COMMA,_4P_,_sv_,_se_,_su_,_si_,_sl_,_sl_,_se_,_sz_,_4P_,_sp_,_sa_,_st_,_si_,_se_,_sn_,_st_,_se_,_sr_,_DOT,_DOT,_DOT, _END_,  //_FRENCH                        
    _sO_,_st_,_st_,_si_,_sm_,_si_,_sz_,_sz_,_sa_,_sz_,_si_,_so_,_sn_,_se_,_4P_,_si_,_sn_,_4P_,_sc_,_so_,_sr_,_ss_,_so_,_DOT,_sA_,_st_,_st_,_se_,_sn_,_sd_,_se_,_sr_,_se_,_DOT,_DOT,_DOT,_END_,   //_ITALIAN                        
    0x28,0x39,0x3a,0x3b,0x87,_COMMA,0x88,0x89,0x8a,_DOT,_DOT,_DOT,_END_,                        //_CHINESE_S      
    _sO_,_sp_,_st_,_si_,_sm_,_si_,_sz_,_sa_,_sn_,_sd_,_so_,_4P_,_si_,_sm_,_sa_,_sg_,_se_,_sn_,_COMMA,_sp_,_so_,_sr_,_4P_,_sf_,_sa_,_sv_,_so_,_sr_,_4P_,_se_,_ss_,_sp_,_se_,_sr_,_se_,_DOT,_DOT,_DOT, _END_,         //_SPANISH(Esp)        
    0x88,0x91,0x51,0xbF,0xa1,0x87,0x6D,0xaE,0x45,0x47,0x26,0x5B,0x3B,0x20,0x38,0x52,0x65,0x31,0x2B,0x7D,0x43,0x31,0x41,0x36,0x26,_DOT,_DOT,_DOT,_END_,   //_JAPAN       
    _sD_,_sa_,_ss_,_4P_,_sB_,_si_,_sl_,_sd_,_4P_,_sw_,_si_,_sr_,_sd_,_4P_,_so_,_sp_,_st_,_si_,_sm_,_si_,_se_,_sr_,_st_,_COMMA,_sb_,_si_,_st_,_st_,_se_,_4P_,_sw_,_sa_,_sr_,_st_,_se_,_sn_,_4P_,_sS_,_si_,_se_,_DOT,_DOT,_DOT,_END_,   //_GERMAN(Deu)
    0x1d,0x56,0xae,0x1b,0xb3,0x1b,0xaf,0xab,0xb1,0x1b,0xac,_4P_,0x1b,0xaf,0x1d,0x55,0x1c,0xab,0x65,0x68,0xb0,0x1b,0xac,0x62,0x56,0x1d,0x66,0x1d,0x65,0x66,0x1b,0xae,0x68,_DOT,_DOT,_DOT, _END_,  //_RUSSIAN    
};



BYTE code tOSD_sMENU_LOCK[] = // sOsdLock
{
    _sM_,_se_,_sn_,_su_,_4P_,_si_,_ss_,_4P_,_sL_,_so_,_sc_,_sk_,_se_,_sd_, _END_,    //_ENGLISH
    _sL_,_se_,_4P_,_sM_,_se_,_sn_,_su_,_4P_,_se_,_ss_,_st_,_4P_,_sv_,_se_,_sr_,_sr_,_so_,_su_,_si_,_sl_,_sl_,_EU_3A,_END_,              //_FRENCH              
    _sM_,_se_,_sn_,_su_,_4P_,_sb_,_sl_,_so_,_sc_,_sc_,_sa_,_st_,_so_, _END_,         //_ITALIAN         
    0x4b,0x4c,0x82,0x84,_END_,  //_CHINESE_S       
    _sE_,_sl_,_4P_,_sM_,_se_,_sn_,_EU_D1,_4P_,_se_,_ss_,_st_,_EU_D6,_4P_,_sb_,_sl_,_so_,_sq_,_su_,_se_,_sa_,_sd_,_so_, _END_,          //_SPANISH(Esp)    
    0x5e,0x4f,0x34,0xc1,0x22,0x6b,0x44,0x30,0x36,0x6a,0x5b,0x38,0x40,_END_,                           //_JAPAN                                                  
    _sM_,_se_,_sn_,_EU_D2,_4P_,_si_,_ss_,_st_,_4P_,_sg_,_se_,_ss_,_sp_,_se_,_sr_,_sr_,_st_,_END_,                        //_GERMAN(Deu)
    0xa3,0x68,0xb0,0x5b,_4P_,0xaf,0xab,0x55,0x1e,0x1d,0xaa,0x1b,0x1c,0x1d,0xa9,0xab,0xb0,0x1d,_END_, //_RUSSIAN  
};


BYTE code tOSD_sMENU_UNLOCK[] = // sOsdUnLock
{
    _sM_,_se_,_sn_,_su_,_4P_,_si_,_ss_,_4P_,_sU_,_sn_,_sl_,_so_,_sc_,_sk_,_se_,_sd_, _END_,  //_ENGLISH
    _sL_,_se_,_4P_,_sM_,_se_,_sn_,_su_,_4P_,_se_,_ss_,_st_,_4P_,_sd_,_EU_3A,_sv_,_se_,_sr_,_sr_,_so_,_su_,_si_,_sl_,_sl_,_EU_3A,_END_,   //_FRENCH 
    _sM_,_se_,_sn_,_su_,_4P_,_ss_,_sb_,_sl_,_so_,_sc_,_sc_,_sa_,_st_,_so_, _END_,             //_ITALIAN                                                
    0x4b,0x4c,0x83,0x84, _END_,  //_CHINESE_S                                                                                                                                   
    _sE_,_sl_,_4P_,_sM_,_se_,_sn_,_EU_D1,_4P_,_se_,_ss_,_st_,_EU_D6,_4P_,_sd_,_se_,_ss_,_sb_,_sl_,_so_,_sq_,_su_,_se_,_sa_,_sd_,_so_,_END_,   //_SPANISH(Esp) 
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    0x5e,0x4f,0x34,0xc1,0x51,0x6b,0x44,0x30,0x22,0x8c,0x7a,0x36,0x6a,0x36,0x6a,0x5b,0x38,0x40, _END_,                    //_JAPAN                                                                                                                                      
#else
    0x5e,0x4f,0x34,0xc1,0x51,0x6b,0x44,0x30,0x22,0x8c,0x6a,0x36,0x6a,0x5b,0x38,0x40, _END_,                    //_JAPAN                                                                                                                                      
#endif
    _sM_,_se_,_sn_,_EU_D2,_4P_,_si_,_ss_,_st_,_4P_,_sf_,_sr_,_se_,_si_,_sg_,_se_,_sg_,_se_,_sb_,_se_,_sn_, _END_,     //_GERMAN(Deu) 
    0xa3,0x68,0xb0,0x5b,_4P_,0x1c,0xab,0xaf,0x55,0x1e,0x1d,0xaa,0x1b,0x1c,0x1d,0xa9,0xab,0xb0,0x1d,_END_,     //_RUSSIAN 
};


BYTE code tOSD_sDDCCI_ON[] =  // sDdcciEnable
{
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mE_,_mn_,_ma_,_mb_,_ml_,_me_,_END_,      //_ENGLISH
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mA_,_ml_,_ml_,_mu_,_mm_,_EU_C2, _END_,  //_FRENCH    
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mA_,_mc_,_mc_,_me_,_ms_,_mo_,_END_,      //_ITALIAN         
    _CH_1A,_CH_1A,_CH_1B,_CH_1D,_CH_1B,_CH_1C,___,_CH_91,_END_,                       //_CHINESE_S       
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mE_,_mn_,_mc_,_me_,_mn_,_md_,_mi_,_md_,_mo_, _END_,  //_SPANISH(Esp)    
    0x1a,0x1a,0x1b,0x1d,0x1b,0x1c,___,0x73,0xa0, _END_,         //_JAPAN           
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mE_,_mi_,_mn_,_END_,                        //_GERMAN(Deu)
    0xa1,0xa1,0xa0,0x61,0xa0,0xa2,___,0x89,0x93,0x92,0x99,0x86,0x9b,0x97,0x8b,0x8e,_END_,       //_RUSSIAN 
};


BYTE code tOSD_sDDCCI_OFF[] = //sDdcciDisable
{
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mD_,_mi_,_ms_,_ma_,_mb_,_ml_,_me_, _END_,  //_ENGLISH
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mE_,_mt_,_me_,_mi_,_mn_,_mt_,_END_,        //_FRENCH                                   
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mS_,_mp_,_me_,_mn_,_mt_,_mo_, _END_,        //_ITALIAN                                  
    _CH_1A,_CH_1A,_CH_1B,_CH_1D,_CH_1B,_CH_1C,___,_CH_6D,_END_,                       //_CHINESE_S       
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mD_,_me_,_ms_,_ma_,_mc_,_mt_,_mi_,_mv_,_ma_,_md_,_mo_,_END_,  //_SPANISH(Esp)
    0x1a,0x1a,0x1b,0x1d,0x1b,0x1c,___,0x29,0x73,0xa0, _END_,         //_JAPAN           
    _mD_,_mD_,_mC_,_SLASH,_mC_,_mI_,_4P_,_mA_,_mu_,_ms_,_END_,                          //_GERMAN(Deu)                                                
    0xa1,0xa1,0xa0,0x61,0xa0,0xa2,___,0x93,0x98,0x99,0x86,0x9b,0x97,0x8b,0x8e,_END_,     //_RUSSIAN                                                                                                                          
};


BYTE code tOSD_sPOWER_SAVING[] = // sPowersavingMode
{
    _sP_,_so_,_sw_,_se_,_sr_,_4P_,_ss_,_sa_,_sv_,_si_,_sn_,_sg_,_4P_,_sm_,_so_,_sd_,_se_,_END_,  //_ENGLISH
    _sM_,_so_,_sd_,_se_,_4P_,_EU_3A,_sc_,_so_,_sn_,_so_,_sm_,_si_,_se_,_4P_,_EU_CF,_EU_3A,_sn_,_se_,_sr_,_sg_,_si_,_se_,_END_,    //_FRENCH              
    _sM_,_so_,_sd_,_so_,_4P_,_sr_,_si_,_ss_,_sp_,_sa_,_sr_,_sm_,_si_,_so_,_4P_,_se_,_sn_,_se_,_sr_,_sg_,_si_,_sa_,_END_,                   //_ITALIAN         
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) //lorimiao 20140702
    0x92,0x93,0x80,0x81,_END_,          //_CHINESE_S    
#else
    0x47,0x6f,0x71,0x76,0x77,_END_,          //_CHINESE_S  
#endif
    _sM_,_so_,_sd_,_sa_,_sl_,_si_,_sd_,_sa_,_sd_,_4P_,_sd_,_se_,_4P_,_sa_,_sh_,_so_,_sr_,_sr_,_so_,_4P_,_sd_,_se_,_4P_,_se_,_sn_,_se_,_sr_,_sg_,_EU_0E,_sa_, _END_,//_SPANISH(Esp)    
#else
    0x92,0x93,0x80,0x81,_END_,          //_CHINESE_S       
    _sM_,_so_,_sd_,_sa_,_sl_,_si_,_sd_,_sa_,_sd_,_4P_,_sd_,_se_,_4P_,_sa_,_sh_,_so_,_sr_,_sr_,_so_,_4P_,_sd_,_se_,_4P_,_se_,_sn_,_se_,_sr_,_sg_,0x40,_sa_, _END_,//_SPANISH(Esp)    
#endif
    0x53,0x6C,0xC1,0x3D,0xC1,0x57,0x5F,0xC1,0x4C,0xBC,0x49,0x3B, _END_,            //_JAPAN           
    _sS_,_st_,_sa_,_sn_,_sd_,_sa_,_sr_,_sd_,_se_,_si_,_sn_,_ss_,_st_,_se_,_sl_,_sl_,_su_,_sn_,_sg_,_END_,                            //_GERMAN(Deu)
    0xA7,0xAa,0x1d,0xB0,0x1d,0xB3,0x1b,0x67,0xB0,0xB2,0x1a,_4P_,0x1c,0x68,0x65,0x1b,0xB3,_4P_,0x56,0x1b,0xae,0xab,0xb0,0x1b,0xac, _END_,   //_RUSSIAN  
};


BYTE code tOSD_sNOCABLE_0[] = // sNoConnect
{
    _sN_,_so_,_4P_,_sC_,_so_,_sn_,_sn_,_se_,_sc_,_st_,_si_,_so_,_sn_,_END_,                                     //_ENGLISH 
    _sC_,_EU_CD,_sb_,_sl_,_se_,_4P_,_sd_,_se_,_4P_,_ss_,_si_,_sg_,_sn_,_sa_,_sl_,_4P_,_sn_,_so_,_sn_,_4P_,_sc_,_so_,_sn_,_sn_,_se_,_sc_,_st_,_EU_3A, _END_,  //_FRENCH              
    _sN_,_se_,_ss_,_ss_,_su_,_sn_,_4P_,_sc_,_so_,_sl_,_sl_,_se_,_sg_,_sa_,_sm_,_se_,_sn_,_st_,_so_, _END_,   //_ITALIAN         
    0x47,0x6f,0x70,0x71,0x72,0x73,_END_,                                                            //_CHINESE_S       
    _sN_,_so_,_4P_,_sh_,_sa_,_sy_,_4P_,_sc_,_so_,_sn_,_se_,_sx_,_si_,_EU_3D,_sn_, _END_,                             //_SPANISH(Esp)    
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) //lorimiao 20140531
    0xaD,0x85,0x2D,0x8D,0x47,0x26,0x5B,0x3E,0x6F,_DOT,_END_,                                  //_JAPAN           
#else
	0xaD,0x85,0x2D,0x8D,0x47,0x26,0x5B,0x3E,0x6F, _END_,                                  //_JAPAN           
#endif
    _sK_,_se_,_si_,_sn_,_se_,_4P_,_sV_,_se_,_sr_,_sb_,_si_,_sn_,_sd_,_su_,_sn_,_sg_,_4P_,_LINE,_END_,                    //_GERMAN(Deu)
    0xa8,0x1d,0x66,0xaa,0x1e,0x5b,0x67,0x68,0xb0,0x1b,0x68,_4P_,0x1d,0xae,0xad,0x52,0xae,0xad,0xae,0xa9,0x52,0x68,0xae,_DOT,_END_,   //_RUSSIAN  
};


BYTE code tOSD_sNOCABLE_1[] = // sCheckSignalCable
{
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) //lorimiao 20140531
    _sC_,_sh_,_se_,_sc_,_sk_,_4P_,_sS_,_si_,_sg_,_sn_,_sa_,_sl_,_4P_,_sC_,_sa_,_sb_,_sl_,_se_, _END_,
#else
    _sC_,_sh_,_se_,_sc_,_sk_,_4P_,_ss_,_si_,_sg_,_sn_,_sa_,_sl_,_4P_,_sc_,_sa_,_sb_,_sl_,_se_, _END_,
#endif
    _END_, //_FRENCH          
    _sv_,_se_,_sr_,_si_,_sf_,_si_,_sc_,_sa_,_sr_,_se_,_4P_,_si_,_sl_,_4P_,_sc_,_sa_,_sv_,_so_,_4P_,_sd_,_si_,_4P_,_ss_,_se_,_sg_,_sn_,_sa_,_sl_,_se_,_END_,//_ITALIAN         
    ___,0x74,0x75,0x47,0x6f,0x70,___,_END_,                                                                 //_CHINESE_S        
    _sR_,_se_,_sv_,_si_,_ss_,_se_,_4P_,_se_,_sl_,_4P_,_sc_,_sa_,_sb_,_sl_,_se_,_4P_,_sd_,_se_,_4P_,_ss_,_se_,_EU_3F,_sa_,_sl_,_END_, //_SPANISH(Esp)    
    0x37,0x32,0x4D,0x67,0x33,0xc1,0x57,0x67,0x6D,0x42,0x28,0x44,0x30,0x38,0x47,0x31,0x41,0x36,0x26,_END_,  //_JAPAN           
    _sS_,_si_,_sg_,_sn_,_sa_,_sl_,_sk_,_sa_,_sb_,_se_,_sl_,_4P_,_EU_D2,_sb_,_se_,_sr_,_sp_,_sr_,_EU_D2,_sf_,_se_,_sn_, _END_,        //_GERMAN(Deu)
    ___,___,0xa8,0x1c,0x1d,0xa9,0x68,0x1c,0x46,0xae,0x68,_4P_,0xad,0x1b,0x53,0xb0,0xab,0x1e,0x46,0xb0,0xb2,0x1a,_4P_,0xaa,0xab,0x55,0x68,0x1e,0x46,___, _END_,   //_RUSSIAN 
};                                                                                                               


BYTE code tOSD_sOOR_0[] = // sInputOutOfRange
{
    _sI_,_sn_,_sp_,_su_,_st_,_4P_,_sS_,_si_,_sg_,_sn_,_sa_,_sl_,_4P_,_sO_,_su_,_st_,_4P_,_so_,_sf_,_4P_,_sR_,_sa_,_sn_,_sg_,_se_,_END_,  //_ENGLISH 
    _sS_,_si_,_sg_,_sn_,_sa_,_sl_,_4P_,_EU_CF,_se_,_sn_,_st_,_sr_,_EU_3A,_se_,_4P_,_sh_,_so_,_sr_,_ss_,_4P_,_sd_,_se_,_ss_,_4P_,_sv_,_sa_,_sl_,_se_,_su_,_sr_,_ss_,_4P_,_sa_,_su_,_st_,_so_,_sr_,_si_,_ss_,_EU_3A,_se_,_ss_, _END_, //_FRENCH          
    _sS_,_se_,_sg_,_sn_,_sa_,_sl_,_se_,_4P_,_sd_,_si_,_4P_,_si_,_sn_,_sp_,_su_,_st_,_4P_,_sf_,_su_,_so_,_sr_,_si_,_4P_,_ss_,_sc_,_sa_,_sl_,_sa_,_END_,  //_ITALIAN         
    0x76,0x77,0x47,0x6f,0x78,0x60,0x79,0x7a, _END_,  //_CHINESE_S
    _sS_,_se_,_EU_3F,_sa_,_sl_,_4P_,_sd_,_se_,_4P_,_se_,_sn_,_st_,_sr_,_sa_,_sd_,_sa_,_4P_,_sf_,_su_,_se_,_sr_,_sa_,_4P_,_sd_,_se_,_4P_,_sr_,_sa_,_sn_,_sg_,_so_,_END_,   //_SPANISH(Esp)    
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    0x9B,0x8E,0xaD,0x85,0x2D,0x69,0x6E,0x39,0xc4,0x50,0x4e,0x45,0x47,0x26,0x5B,0x3B,_END_,   //_JAPAN           
#else
    0x9B,0x8E,0xaD,0x85,0x2D,0x69,0x6E,0x39,0xc4,0x50,0x45,0x47,0x26,0x5B,0x3B,_END_,   //_JAPAN           
#endif
    _sE_,_si_,_sn_,_sg_,_sa_,_sn_,_sg_,_ss_,_ss_,_si_,_sg_,_sn_,_sa_,_sl_,_4P_,_sa_,_su_,_EU_D5,_se_,_sr_,_sh_,_sa_,_sl_,_sb_,_4P_,_sd_,_se_,_ss_,_4P_,_sg_,_EU_D2,_sl_,_st_,_si_,_sg_,_se_,_sn_,_4P_,_sB_,_se_,_sr_,_se_,_si_,_sc_,_sh_,_ss_, _END_,//_GERMAN(Deu)
    0x9f,0x43,0x1d,0x66,0xb0,0x1d,0x1a,_4P_,0xad,0x1b,0x53,0xb0,0xab,0x1e,_4P_,0xa9,0xb0,0x68,_4P_,0x66,0x1d,0x56,0x52,0xad,0xae,0x1b,0xb3,0x1d,0x53,0x1d,_4P_,0x66,0x1b,0xab,0x56,0xab,0xaf,0x1d,0xb0,0xab, _END_, //_RUSSIAN 
};

                        

BYTE code tOSD_sOOR_1[] = //sShowNativeModeStr
{
#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
    _sP_,_sl_,_se_,_sa_,_ss_,_se_,_4P_,_sC_,_sh_,_sa_,_sn_,_sg_,_se_,_4P_,_st_,_so_,_4P_,_1_, _9_, _2_, _0_, __4, _sx_, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_,_END_, //_ENGLISH  
    _sV_,_se_,_su_,_si_,_sl_,_sl_,_se_,_sz_,_4P_,_sm_,_so_,_sd_,_si_,_sf_,_si_,_se_,_sr_,_4P_,_se_,_sn_,_4P_,_1_, _9_, _2_, _0_, __4, _sx_, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_, _END_,            //_FRENCH                                                                                                                                                                                      
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) //lorimiao 20140531
    _sR_,_se_,_sg_,_so_,_sl_,_sa_,_sr_,_se_,_4P_,_sa_,_4P_,_1_, _9_, _2_, _0_, __4, _sx_, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_, //_ITALIAN                                                                                                                                                                                            
#else
	_sr_,_se_,_sg_,_so_,_sl_,_sa_,_sr_,_se_,_4P_,_sa_,_4P_,_1_, _9_, _2_, _0_, __4, _sx_, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_, //_ITALIAN                                                                                                                                                                                            
#endif
    0x25,0x26,0xb9,_4P_,_1_, _9_, _2_, _0_, __4, __X, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, __H, __z , _END_,                       //_CHINESE_S                                                                                                                                                                                           
    _sP_,_so_,_sr_,_4P_,_sf_,_sa_,_sv_,_so_,_sr_,_COMMA,_4P_,_sc_,_sa_,_sm_,_sb_,_si_,_se_,_4P_,_sa_,_4P_,_1_, _9_, _2_, _0_, __4, _sx_, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_,                 //_SPANISH(Esp)                                                                                                                                                                                    
    0x7e,0xb8,0x36,0x6a,0x68,_4P_,_1_, _9_, _2_, _0_, __4, 0x0d, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, 0x0e, 0x0f, _END_,   //_JAPAN                                                                                                                                                                                          
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) 
    _sB_,_si_,_st_,_st_,_se_,_4P_,_EU_D4,_sn_,_sd_,_se_,_sr_,_sn_,_4P_,_ss_,_si_,_se_,_4P_,_sa_,_su_,_sf_,_4P_,_1_, _9_, _2_, _0_, __4, _X_, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_,_sz_, _END_,//_GERMAN(Deu)      
#else
    _sB_,_si_,_st_,_st_,_se_,_4P_,_EU_D4,_sn_,_sd_,_se_,_sr_,_sn_,_4P_,_sS_,_si_,_se_,_4P_,_sa_,_su_,_sf_,_4P_,_1_, _9_, _2_, _0_, __4, _X_, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ , _END_,//_GERMAN(Deu)      
#endif
    0xa4,0xaf,0xb3,0x68,0xb0,0x1b,0xae,0x68,_4P_,0xb0,0xab,_4P_,_1_, _9_, _2_, _0_, __4, 0x48, __4, _1_, _0_, _8_, _0_, __4, _AT_SIGN , __4, _6_, _0_, 0x6d, 0x8c,_END_,         //_RUSSIN

#elif((_PANEL_DH_WIDTH == 1680) && (_PANEL_DV_HEIGHT == 1050))
    _sP_,_sl_,_se_,_sa_,_ss_,_se_,_4P_,_sC_,_sh_,_sa_,_sn_,_sg_,_se_,_4P_,_st_,_so_,_4P_,_1_, _6_, _8_, _0_, __4, _sx_, __4,_1_, _0_, _5_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_,_END_, //_ENGLISH  
    _sV_,_se_,_su_,_si_,_sl_,_sl_,_se_,_sz_,_4P_,_sm_,_so_,_sd_,_si_,_sf_,_si_,_se_,_sr_,_4P_,_se_,_sn_,_4P_,_1_, _6_, _8_, _0_, __4, _sx_, __4,_1_, _0_, _5_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_, _END_,            //_FRENCH                                                                                                                                                                                      
    _sr_,_se_,_sg_,_so_,_sl_,_sa_,_sr_,_se_,_4P_,_sa_,_4P_,_1_, _6_, _8_, _0_, __4, _sx_, __4,_1_, _0_, _5_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_, //_ITALIAN                                                                                                                                                                                            
    0x25,0x26,0xb9,_4P_,_1_, _6_, _8_, _0_, __4, __X, __4,_1_, _0_, _5_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, __H, __z , _END_,                       //_CHINESE_S                                                                                                                                                                                           
    _sP_,_so_,_sr_,_4P_,_sf_,_sa_,_sv_,_so_,_sr_,_COMMA,_4P_,_sc_,_sa_,_sm_,_sb_,_si_,_se_,_4P_,_sa_,_4P_,_1_, _6_, _8_, _0_, __4, _sx_, __4,_1_, _0_, _5_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_,                 //_SPANISH(Esp)                                                                                                                                                                                    
    0x7e,0xb8,0x36,0x6a,0x68,_4P_,_1_, _6_, _8_, _0_, __4, _sx_, __4,_1_, _0_, _5_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_, _END_,   //_JAPAN                                                                                                                                                                                          
    _sB_,_si_,_st_,_st_,_se_,_4P_,_EU_D4,_sn_,_sd_,_se_,_sr_,_sn_,_4P_,_sS_,_si_,_se_,_4P_,_sa_,_su_,_sf_,_4P_,_1_, _6_, _8_, _0_, __4, _X_, __4,_1_, _0_, _5_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, __H, __z , _END_,//_GERMAN(Deu)      
    0xa4,0xaf,0xb3,0x68,0xb0,0x1b,0xae,0x68,_4P_,0xb0,0xab,_4P_,_1_, _6_, _8_, _0_, __4, 0x48, __4, _1_, _0_, _5_,  _0_,  __4, _AT_SIGN , __4, _6_, _0_, 0x6d, 0x8c,_END_,         //_RUSSIN

#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900))
    _sP_,_sl_,_se_,_sa_,_ss_,_se_,_4P_,_sC_,_sh_,_sa_,_sn_,_sg_,_se_,_4P_,_st_,_so_,_4P_,_1_, _6_, _0_, _0_, __4, _sx_, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_,_END_, //_ENGLISH  
    _sV_,_se_,_su_,_si_,_sl_,_sl_,_se_,_sz_,_4P_,_sm_,_so_,_sd_,_si_,_sf_,_si_,_se_,_sr_,_4P_,_se_,_sn_,_4P_,_1_, _6_, _0_, _0_, __4, _sx_, __4, _9_, _0_,   _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_, _END_,            //_FRENCH                                                                                                                                                                                      
    _sr_,_se_,_sg_,_so_,_sl_,_sa_,_sr_,_se_,_4P_,_sa_,_4P_,_1_, _6_, _0_, _0_, __4, _sx_, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_, //_ITALIAN                                                                                                                                                                                            
    0x25,0x26,0xb9,_4P_,_1_, _6_, _0_, _0_, __4, __X, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, __H, __z , _END_,                       //_CHINESE_S                                                                                                                                                                                           
    _sP_,_so_,_sr_,_4P_,_sf_,_sa_,_sv_,_so_,_sr_,_COMMA,_4P_,_sc_,_sa_,_sm_,_sb_,_si_,_se_,_4P_,_sa_,_4P_,_1_, _6_, _0_, _0_, __4, _sx_, __4, _9_, _0_,   _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_,                 //_SPANISH(Esp)                                                                                                                                                                                    
    0x7e,0xb8,0x36,0x6a,0x68,_4P_,_1_, _6_, _0_, _0_, __4, _sx_, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_, _END_,   //_JAPAN                                                                                                                                                                                          
    _sB_,_si_,_st_,_st_,_se_,_4P_,_EU_D4,_sn_,_sd_,_se_,_sr_,_sn_,_4P_,_sS_,_si_,_se_,_4P_,_sa_,_su_,_sf_,_4P_,_1_, _6_, _0_, _0_, __4, __X, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, __H, __z , _END_,//_GERMAN(Deu)      
    0xa4,0xaf,0xb3,0x68,0xb0,0x1b,0xae,0x68,_4P_,0xb0,0xab,_4P_,_1_, _6_, _0_, _0_, __4, 0x48, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, 0x6d, 0x8c,_END_,         //_RUSSIN
                                                                                                                                                                                              
#elif((_PANEL_DH_WIDTH == 1440) && (_PANEL_DV_HEIGHT == 900))
    _sP_,_sl_,_se_,_sa_,_ss_,_se_,_4P_,_sC_,_sh_,_sa_,_sn_,_sg_,_se_,_4P_,_st_,_so_,_4P_,_1_, _4_, _4_, _0_, __4, _sx_, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_,_END_, //_ENGLISH  
    _sV_,_se_,_su_,_si_,_sl_,_sl_,_se_,_sz_,_4P_,_sm_,_so_,_sd_,_si_,_sf_,_si_,_se_,_sr_,_4P_,_se_,_sn_,_4P_,_1_, _4_, _4_, _0_, __4, _sx_, __4, _9_, _0_,   _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_, _END_,            //_FRENCH                                                                                                                                                                                      
    _sr_,_se_,_sg_,_so_,_sl_,_sa_,_sr_,_se_,_4P_,_sa_,_4P_,_1_, _4_, _4_, _0_, __4, _sx_, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_, //_ITALIAN                                                                                                                                                                                            
    0x25,0x26,0xb9,_4P_,_1_, _4_, _4_, _0_, __4, __X, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, __H, __z , _END_,                       //_CHINESE_S                                                                                                                                                                                           
    _sP_,_so_,_sr_,_4P_,_sf_,_sa_,_sv_,_so_,_sr_,_COMMA,_4P_,_sc_,_sa_,_sm_,_sb_,_si_,_se_,_4P_,_sa_,_4P_,_1_, _4_, _4_, _0_, __4, _sx_, __4, _9_, _0_,   _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_,                 //_SPANISH(Esp)                                                                                                                                                                                    
    0x7e,0xb8,0x36,0x6a,0x68,_4P_,_1_, _4_, _4_, _0_, __4, _sx_, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_, _END_,   //_JAPAN                                                                                                                                                                                          
    _sB_,_si_,_st_,_st_,_se_,_4P_,_EU_D4,_sn_,_sd_,_se_,_sr_,_sn_,_4P_,_sS_,_si_,_se_,_4P_,_sa_,_su_,_sf_,_4P_,_1_, _4_, _4_, _0_, __4, __X, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, __H, __z , _END_,//_GERMAN(Deu)      
    0xa4,0xaf,0xb3,0x68,0xb0,0x1b,0xae,0x68,_4P_,0xb0,0xab,_4P_,_1_, _4_, _4_, _0_, __4, 0x48, __4, _9_, _0_,  _0_, __4, _AT_SIGN , __4, _6_, _0_, 0x6d, 0x8c,_END_,         //_RUSSIN
 
#elif((_PANEL_DH_WIDTH == 1280) && (_PANEL_DV_HEIGHT == 1024))
    _sP_,_sl_,_se_,_sa_,_ss_,_se_,_4P_,_sC_,_sh_,_sa_,_sn_,_sg_,_se_,_4P_,_st_,_so_,_4P_,_1_, _2_, _8_, _0_, __4, _sx_, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_,_END_, //_ENGLISH  
    _sV_,_se_,_su_,_si_,_sl_,_sl_,_se_,_sz_,_4P_,_sm_,_so_,_sd_,_si_,_sf_,_si_,_se_,_sr_,_4P_,_se_,_sn_,_4P_,_1_, _2_, _8_, _0_, __4, _sx_, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_, _END_,            //_FRENCH                                                                                                                                                                                      
    _sr_,_se_,_sg_,_so_,_sl_,_sa_,_sr_,_se_,_4P_,_sa_,_4P_,_1_, _2_, _8_, _0_, __4, _sx_, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_, //_ITALIAN                                                                                                                                                                                            
    0x25,0x26,0xb9,_4P_,_1_, _2_, _8_, _0_, __4, __X, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_, __H, __z , _END_,                       //_CHINESE_S                                                                                                                                                                                           
    _sP_,_so_,_sr_,_4P_,_sf_,_sa_,_sv_,_so_,_sr_,_COMMA,_4P_,_sc_,_sa_,_sm_,_sb_,_si_,_se_,_4P_,_sa_,_4P_,_1_, _2_, _8_, _0_, __4, _sx_, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_ ,_END_,                 //_SPANISH(Esp)                                                                                                                                                                                    
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    0x7e,0xb8,0x36,0x6a,0x68,_4P_,_1_, _2_, _8_, _0_, __4, 0x0d, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_, 0x0e, 0x0f, _END_,   //_JAPAN                                                                                                                                                                                          
    _sB_,_si_,_st_,_st_,_se_,_4P_,_EU_D4,_sn_,_sd_,_se_,_sr_,_sn_,_4P_,_sS_,_si_,_se_,_4P_,_sa_,_su_,_sf_,_4P_,_1_, _2_, _8_, _0_, __4, _sx_, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_,_sH_,_sz_, _END_,//_GERMAN(Deu)      
#else
    0x7e,0xb8,0x36,0x6a,0x68,_4P_,_1_, _2_, _8_, _0_, __4, _sx_, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_, _sH_, _sz_, _END_,   //_JAPAN                                                                                                                                                                                          
    _sB_,_si_,_st_,_st_,_se_,_4P_,_EU_D4,_sn_,_sd_,_se_,_sr_,_sn_,_4P_,_sS_,_si_,_se_,_4P_,_sa_,_su_,_sf_,_4P_,_1_, _2_, _8_, _0_, __4, __X, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_, __H, __z , _END_,//_GERMAN(Deu)      
#endif
    0xa4,0xaf,0xb3,0x68,0xb0,0x1b,0xae,0x68,_4P_,0xb0,0xab,_4P_,_1_, _2_, _8_, _0_, __4, 0x48, __4, _1_, _0_,  _2_, _4_, __4, _AT_SIGN , __4, _6_, _0_, 0x6d, 0x8c,_END_,         //_RUSSIN

#else                                                         
    no define                                                 
#endif                                                        
                                                                                                   
};

#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN) //lorimiao 20140531
BYTE code tOSD_sBTNSlider_L[] = 
{
    _5_,_ms_,_me_,_mc_,_END_,
};
BYTE code tOSD_sBTNSlider_R[] = 
{
    _6_,_0_,_ms_,_me_,_mc_,_END_,
};
#else
BYTE code tOSD_sBTNSlider_L[] = 
{
    _5_,_mS_,_me_,_mc_,_END_,
};
BYTE code tOSD_sBTNSlider_R[] = 
{
    _6_,_0_,_mS_,_me_,_mc_,_END_,
};
#endif



//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************


BYTE OsdGetTableValue(BYTE value, BYTE num)
{
    return tOSD_2iSliderX[value][num];
}





#endif//#if(_OSD_TYPE == _LEONVO_GREEN_OSD)
