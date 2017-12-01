//**********************************************************************************************************
//  The  Software  is  proprietary,  confidential,  and  valuable to Realtek Semiconductor
//  Corporation  ("Realtek").  All  rights, including but not limited  to  copyrights,
//  patents,  trademarks, trade secrets, mask work rights, and other similar rights and interests,
//  are reserved to Realtek. Without  prior  written  consent  from  Realtek,  copying, reproduction,
//  modification,  distribution,  or  otherwise  is strictly prohibited. The Software  shall  be
//  kept  strictly  in  confidence,  and  shall  not be  disclosed to or otherwise accessed by
//  any third party. @ <2003> - <2008>   The Software is provided "AS IS" without any warranty of any kind,
//  express, implied, statutory or otherwise.
//**********************************************************************************************************

//----------------------------------------------------------------------------------------------------
// ID Code      : RTDFactoryMode.c No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------
#define __FACTORY_FUNCTION__

#include "UserCommonInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

/*
#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127

#if(_AUTO_POWER_DOWN == _ON)
#define _OSD_FACTORY_ROW_SIZE                           23
#else
#define _OSD_FACTORY_ROW_SIZE                           22
#endif

#else

#if(_AUTO_POWER_DOWN == _ON)
#define _OSD_FACTORY_ROW_SIZE                           22
#else
#define _OSD_FACTORY_ROW_SIZE                           21
#endif

#endif
*/

#define _OSD_FACTORY_ROW_SIZE                           (21+_PANEL_VCOM_ADJUST_FUNCTION+_AUTO_POWER_DOWN+_LOW_BLUE_LIGHT_FUNCTION+_ENERGY_STAR_SUPPORT)

#define _OSD_FACTORY_COL_SIZE                           28
#define _OSD_FACTORY_H_POSITION							0//5//(0~100)
#define _OSD_FACTORY_V_POSITION							0//5//(0~100)

#define _OSD_FACTORY_FONT_SELECT_START                  (_OSD_FACTORY_ROW_SIZE + 1)
#define _OSD_FACTORY_FONT_START_POSITION        		((_OSD_FACTORY_ROW_SIZE + 1) + (_OSD_FACTORY_ROW_SIZE * _OSD_FACTORY_COL_SIZE))

#define _FACTORY_OSD_WINDOW_SIZE_X                      (_OSD_FACTORY_COL_SIZE * 12)
#define _FACTORY_OSD_WINDOW_SIZE_Y                      (_OSD_FACTORY_ROW_SIZE * 18)
//#define _ROTATE_FACTORY_OSD_WINDOW_OFFSET               7

//Factory Menu ROW define>>>>>>>>>>>>>>>>
#define _MODEL_NAME_ROW                                 1

#define _AUTO_COLOR_ROW                                 4
#define _ADC_GAIN_ROW 									5
#define _ADC_OFFSET_ROW 								6

#define _COLORTEMP_ITEM1_ROW 							8     //6500
#define _COLORTEMP_ITEM2_ROW 							9     //7200
#define _COLORTEMP_ITEM3_ROW 							10    //9300
#define _COLORTEMP_ITEM4_ROW 							11    //sRGB
#define _COLORTEMP_ITEM5_ROW 							12    //User
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
#define _COLORTEMP_ITEM6_ROW 							13    //Low blue light

#define _BRIGHTNESS_ROW                                 14
#define _CONTRAST_ROW                                   14
#define _SSC_ROW 										15
#define _DFM_ROW                                        16
#define _BURNIN_ROW                                     17
#define _EDID_WP_ROW                                    18
#define _HW_ADC_ROW                                     19

#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
#define _PANEL_VCOM_ROW 							    20
#define _PANEL_TIME_ROW 								21

#if(_AUTO_POWER_DOWN == _ON)
#define _AUTO_POWER_DOWN_ROW							22
#define _EXIT_ROW                                       23
#else
#define _EXIT_ROW                                       22
#endif

#define _TEXT_START_ROW                                 _MODEL_NAME_ROW
#else
#define _PANEL_TIME_ROW 								20

#if(_AUTO_POWER_DOWN == _ON)
#define _AUTO_POWER_DOWN_ROW							21
#define _EXIT_ROW                                       22
#else
#define _EXIT_ROW                                       21
#endif

#define _TEXT_START_ROW                                 _MODEL_NAME_ROW
#endif

#else
#define _BRIGHTNESS_ROW                                 13
#define _CONTRAST_ROW                                   13
#define _SSC_ROW 										14
#define _DFM_ROW                                        15
#define _BURNIN_ROW                                     16
#define _EDID_WP_ROW                                    17
#define _HW_ADC_ROW                                     18
#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
#define _PANEL_VCOM_ROW 							    19
#define _PANEL_TIME_ROW 								20

#if(_AUTO_POWER_DOWN == _ON)
#define _AUTO_POWER_DOWN_ROW							21
#define _EXIT_ROW                                       22
#else
#define _EXIT_ROW                                       21
#endif

#define _TEXT_START_ROW                                 _MODEL_NAME_ROW
#else
#define _PANEL_TIME_ROW 								19

#if(_AUTO_POWER_DOWN == _ON)
#define _AUTO_POWER_DOWN_ROW							20
#if(_ENERGY_STAR_SUPPORT == _ON)
#define _DPS_ROW                                        21
#define _EXIT_ROW                                       22
#else
#define _EXIT_ROW                                       21
#endif
#else
#if (_ENERGY_STAR_SUPPORT == _ON)
#define _DPS_ROW                                       20
#define _EXIT_ROW                                      21
#else
#define _EXIT_ROW                                       20
#endif
#endif

#define _TEXT_START_ROW                                 _MODEL_NAME_ROW
#endif
#endif
//Factory Item COL define>>>>>>>>>>>>
#define _TEXT_START_COL                                 1

#define _PASS_FAIL_COL 									15//13

#define _RGB_GAP                                        6
#define _R_COL                          				8
#define _G_COL                          				(_R_COL+_RGB_GAP)//14
#define _B_COL                          				(_R_COL+_RGB_GAP*2)//20

#define _R_NUMBER_COL                                   (_R_COL+2)//10
#define _G_NUMBER_COL                                   (_R_NUMBER_COL+_RGB_GAP)//(10+6)
#define _B_NUMBER_COL                                   (_R_NUMBER_COL+_RGB_GAP*2)//(10+6*2)

#define _BRI_COL                                        1
#define _CON_COL                                        9
#define _BRI_NUMBER_COL                                 5
#define _CON_NUMBER_COL                                 13
#define _ON_OFF_COL 									13
#define _SSC_NUMBER_COL                                 12
#define PANEL_TIME_NUMBER_COL                           13
#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
#define _VCOM_NUMBER_COL                                12
#endif

#if(_AUTO_POWER_DOWN == _ON)
#define _AUTO_POWER_DOWN_COL							18
#endif
//---------------------
//   Font index
//---------------------

enum tFactoryNumber
{
  _SPACE=0x00,
  _0,                           
  _1,                           
  _2,                           
  _3,                           
  _4,                           
  _5,                           
  _6,                           
  _7,                           
  _8,                           
  _9,                           
};

enum tFactoryLetter
{
  _A=0x0B,
  _B,
  _C,
  _D,
  _E,
  _F,
  _G,
  _H,
  _I,
  _J,
  _K,
  _L,
  _M,
  _N,
  _O,
  _P,
  _Q,
  _R,
  _S,
  _T,
  _U,
  _V,
  _W,
  _X,
  _Y,
  _Z,
  _a,
  _b,
  _c,
  _d,
  _e,
  _f,
  _g,
  _h,
  _i,
  _j,
  _k,
  _l,
  _m,
  _n,
  _o,
  _p,
  _q,
  _r,
  _s,
  _t,
  _u,
  _v,
  _w,
  _x,
  _y,
  _z,
};


// define in LenovoGreenInclude.h

#define _MINUS                       0x3f
#define _LBSM                        0x40    //left of bracket 
#define _RBSM                        0x41    //right of bracket
#define _LBT                         0x42    //left of bracket 
#define _RBT                         0x43    //right of bracket
#define _SLASH                       0x44
#define _DOT                         0x45
#define _COLON                       0x46

#if 1//Robert Wang 20121226 move from panel.h
//--------------------------------------------------
//Definitions of Panel Name string
//--------------------------------------------------
#if(_PANEL_TYPE == _TPV_CMO_M215HGE)
#define _FACTORY_PANNEL_NAME                   _C,_M,_O,_SPACE,_M,_2,_1,_5,_H,_G,_E
#elif(_PANEL_TYPE == _TPV_LG_LM190E09)
#define _FACTORY_PANNEL_NAME                   _L,_G,_SPACE,_L,_M,_1,_9,_0,_E,_0,_9
#elif(_PANEL_TYPE == _TPV_SEC_LTM190BT07)
#define _FACTORY_PANNEL_NAME                   _S,_E,_C,_SPACE,_L,_T,_M,_1,_9,_0,_B,_T,_0,_7
#elif(_PANEL_TYPE == _TPV_CMI_M220ZGE)
#define _FACTORY_PANNEL_NAME                   _C,_M,_I,_SPACE,_M,_2,_2,_0,_G,_E
#elif(_PANEL_TYPE == _TPV_SEC_LTM220MT09)
#define _FACTORY_PANNEL_NAME                   _S,_E,_C,_SPACE,_L,_T,_M,_2,_2,_0,_M,_T,_0,_9
#elif(_PANEL_TYPE == _TPV_CMI_M190CGE_20)
#define _FACTORY_PANNEL_NAME                   _C,_M,_I,_SPACE,_M,_1,_9,_0,_C,_G,_E,_SPACE,_2,_0
#elif(_PANEL_TYPE == _TPV_CMI_M195FGE_L20)
#define _FACTORY_PANNEL_NAME                   _C,_M,_I,_SPACE,_M,_1,_9,_5,_F,_G,_E,_SPACE,_L,_2,_0
#elif(_PANEL_TYPE == _TPV_LG_LM190E0A)
#define _FACTORY_PANNEL_NAME                   _L,_G,_SPACE,_L,_M,_1,_9,_0,_E,_0,_A
#elif(_PANEL_TYPE == _TPV_LG_LM200WD3_TLF1)
#define _FACTORY_PANNEL_NAME                   _L,_G,_SPACE,_L,_M,_2,_0,_0,_W,_D,_3
#elif((_PANEL_TYPE == _TPV_LG_LM230WF5_TLF1)||(_PANEL_TYPE == _TPV_LG_LM230WF5_TLH1))
#define _FACTORY_PANNEL_NAME                   _L,_G,_SPACE,_L,_M,_2,_3,_0,_W,_F,_5
#elif(_PANEL_TYPE == _TPV_LT_LM215WF3_S2DB)
#define _FACTORY_PANNEL_NAME                   _L,_T,_SPACE,_L,_M,_2,_1,_5,_W,_F,_3
#elif(_PANEL_TYPE == _TPV_JV_LM230WF3_S2G2_AD_WUXGA)
#define _FACTORY_PANNEL_NAME                   _L,_T,_SPACE,_L,_M,_2,_3,_0,_W,_F,_3
#elif(_PANEL_TYPE == _TPV_LG_LM230WF3_SLQ1)||(_PANEL_TYPE == _TPV_LG_LM230WF3_SLN1)
#define _FACTORY_PANNEL_NAME                   _L,_G,_SPACE,_L,_M,_2,_3,_0,_W,_F,_3
#elif(_PANEL_TYPE == _TPV_LG_LM230WF9_SSA1)
#define _FACTORY_PANNEL_NAME                   _L,_G,_SPACE,_L,_M,_2,_3,_0,_W,_F,_9
#elif(_PANEL_TYPE == _TPV_LG_LM230WF7_SSB1)
#define _FACTORY_PANNEL_NAME                   _L,_G,_SPACE,_L,_M,_2,_3,_0,_W,_F,_7
#elif(_PANEL_TYPE == _TPV_SAMSUNG_LTM230HL08)
#define _FACTORY_PANNEL_NAME                   _L,_T,_M,_2,_3,_0,_H,_L,_0,_8
#elif(_PANEL_TYPE == _TPV_BOE_HR230WU1_400)
#define _FACTORY_PANNEL_NAME				   _H,_R,_2,_3,_0,_W,_U,_1
#elif(_PANEL_TYPE == _TPV_AUO_M170ETN01)
#define _FACTORY_PANNEL_NAME				   _M,_1,_7,_0,_E,_T,_N,_0,_1
#elif(_PANEL_TYPE == _TPV_SEC_LTM220MT12)
#define _FACTORY_PANNEL_NAME				   _L,_T,_M,_2,_2,_0,_M,_T,_1,_2
#elif(_PANEL_TYPE == _TPV_TPV_TPM190A1_MWW4)
#define _FACTORY_PANNEL_NAME				   _T,_P,_M,_1,_9,_0,_A,_1
#elif(_PANEL_TYPE == _TPV_LG_LM195WD1_TLA1)
#define _FACTORY_PANNEL_NAME                   _L,_G,_SPACE,_L,_M,_1,_9,_5,_W,_D,_1
#elif((_PANEL_TYPE == _TPV_LNT_LM195WX1_S2A1) || (_PANEL_TYPE == _TPV_LNT_LM195WX1_S1C1))  //Ada.chen 20150814_1
#define _FACTORY_PANNEL_NAME                   _L,_M,_1,_9,_5,_W,_X,_1,_SPACE,_S,_2,_A,_1
#elif(_PANEL_TYPE == _TPV_AUO_M195RTN01_0)    //Ada.chen 20150819
#if(_PROJECT ==_PRJ_L_F2014_A_AUO_M195RTN01_00B)
#define _FACTORY_PANNEL_NAME                   _M,_1,_9,_5,_R,_T,_N,_0,_1,_SPACE,_0,_0,_B
#elif(_PROJECT ==_PRJ_L_F2014_A_AUO_M195RTN01_OLE) //Ada.chen 20160226
#define _FACTORY_PANNEL_NAME                   _M,_1,_9,_5,_R,_T,_N,_0,_1,_SPACE,_O,_L,_E
#elif(_PROJECT ==_PRJ_L_F2014_A_AUO_M195RTN01_OLF)
#define _FACTORY_PANNEL_NAME                   _M,_1,_9,_5,_R,_T,_N,_0,_1,_SPACE,_O,_L,_F
#elif((_PROJECT ==_CVT_RL6230_GREEN) || (_PROJECT ==_CVT_RL6230_PROJECT) || (_PROJECT ==_CVT_RL6336_PROJECT))
#define _FACTORY_PANNEL_NAME                   _M,_1,_9,_5,_R,_T,_N,_0,_1,_DOT,_0
#else
#define _FACTORY_PANNEL_NAME                   _M,_1,_9,_5,_R,_T,_N,_0,_1,_SPACE,_0
#endif
#elif(_PANEL_TYPE == _TPV_INL_M195FGE_L20)    //Ada.chen 20150824
#define _FACTORY_PANNEL_NAME                   _M,_1,_9,_5,_F,_G,_E,_SPACE,_L,_2,_0
#elif(_PANEL_TYPE == _TPV_AUO_TPM190WP2_PTN01)
#define _FACTORY_PANNEL_NAME				   _T,_P,_M,_1,_9,_0,_W,_P,_2
#elif(_PANEL_TYPE == _TPV_BOE_HT215F01_100)
#define _FACTORY_PANNEL_NAME				   _H,_T,_2,_1,_5,_F,_0,_1,_SPACE,_1,_0,_0
#elif(_PANEL_TYPE == _TPV_LGD_LM215WF4_TLG1)
#define _FACTORY_PANNEL_NAME				   _L,_M,_2,_1,_5,_W,_F,_4
//#elif(_PANEL_TYPE == _TPV_LNT_LM195WX1_S1C1)    //Ada.chen 20160219
//#define _FACTORY_PANNEL_NAME                   _L,_M,_1,_9,_5,_W,_X,_1,_SPACE,_S,_1,_C,_1
#elif(_PANEL_TYPE == _TPV_BOE_MV195WGM_N10)    //Ada.chen 20160219
#define _FACTORY_PANNEL_NAME                   _M,_V,_1,_9,_5,_W,_G,_M,_SPACE,_N,_1,_0

#elif(_PANEL_TYPE == _TPV_AUO_M215HTN01_DOT_1)
#define _FACTORY_PANNEL_NAME				   _M,_2,_1,_5,_H,_T,_N,_0,_1,_DOT,_1

#elif(_PANEL_TYPE == _TPV_CMI_M215HGE_L21)
#define _FACTORY_PANNEL_NAME				   _M,_2,_1,_5,_H,_G,_E,_SPACE,_L,_2,_1
#elif(_PANEL_TYPE == _TPV_INL_M215HNE_L30)
#define _FACTORY_PANNEL_NAME				   _M,_2,_1,_5,_H,_N,_E,_SPACE,_L,_3,_0
#elif(_PANEL_TYPE == _TPV_BOE_MV190E0M_N10)
#define _FACTORY_PANNEL_NAME				   _M,_V,_1,_9,_0,_E,_0,_M,_SPACE,_N,_1,_0
#elif(_PANEL_TYPE == _TPV_LG_LM190E0A_SLD1)
#define _FACTORY_PANNEL_NAME				   _L,_M,_1,_9,_0,_E,_0,_A,_SPACE,_S,_L,_D,_1
#elif(_PANEL_TYPE == _TPV_BOE_MV230FHM_N20)
#define _FACTORY_PANNEL_NAME				   _M,_V,_2,_3,_0,_F,_H,_M
#elif(_PANEL_TYPE == _FOX_CMI_M195FGE_L20)
#define _FACTORY_PANNEL_NAME				   _M,_1,_9,_5,_F,_G,_E,_MINUS,_L,_2,_0
#else
#define _FACTORY_PANNEL_NAME                   _R,_T,_D
#warning "Please check  Panel name setting!!";
#endif

#endif


//--------------------------------------------------
//Definitions of Model Name string
//--------------------------------------------------
#define _VERSION_BIOS                           		_E,_0,_V,_0,_0,_1
#define _RTK_VERSION                                    _V,_0,_0,_1

#ifndef _IC_SERIES
#define _IC_SERIES                                      _R,_T,_D,_2,_2,_8,_0,_C,_L
#endif
//--------------------------------------------------
//Definitions of Support Color Temperature string
//--------------------------------------------------
#define _FACTORY_COLORTEMP_TEXT1           				_6,_5,_0,_0
#define _FACTORY_COLORTEMP_TEXT2           				_7,_2,_0,_0
#define _FACTORY_COLORTEMP_TEXT3           				_9,_3,_0,_0
#define _FACTORY_COLORTEMP_TEXT4           				_s,_R,_G,_B
#define _FACTORY_COLORTEMP_TEXT5           				_U,_s,_e,_r
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
#define _FACTORY_COLORTEMP_TEXT6           				_L,_B,_L
#else
#define _FACTORY_COLORTEMP_TEXT6           				_U,_s,_e,_r
#endif
#define _FACTORY_COLORTEMP_TEXT7           				_U,_s,_e,_r

#define _WINDOW_ENABLE									0x01

#define _FACTORY_RBG_MAX                                255
#define _FACTORY_RBG_MIN                                0

#define _FACTORY_SSC_MAX                                15
#define _FACTORY_SSC_MIN                                0


#if(_OSD_TYPE == _LEONVO_GREEN_OSD)
#define _CP_0											_CP_GRAY_224
#define _CP_1											_CP_BG
#define _CP_2											_CP_RED
#elif(_OSD_TYPE == _LEONVO_GRAY_OSD)
#define _CP_0											_CP_GRAY_224
#define _CP_1											_CP_BG
#define _CP_2											_CP_RED_255
#elif(_OSD_TYPE == _LENOVO_ORG_OSD)
#define _CP_0											_CP_WHITE//Robert Wang 20130604
#define _CP_1											_CP_BG
#define _CP_2											_CP_YELLOW
#elif(_OSD_TYPE == _LENOVO_2014_OSD)
#define _CP_0											_CP_WHITE
#define _CP_1											_CP_BLACK
#define _CP_2											_CP_YELLOW
#endif

//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_OSD_TYPE == _LENOVO_2014_OSD)//jason.cheng 20150116_1 modify follow TPV REQUEST

BYTE code tOSD_FACTORY_FW_VERSION_STR[] =
{
	_MICROCODE,_END_,
};
BYTE code tOSD_FACTORY_MODEL_NAME_STR[] =
{
	_MODEL_NAME,_END_,
};
BYTE code tOSD_FACTORY_PANNEL_NAME_STR[] =
{
	_PANNEL_NAME,_END_,
};
BYTE code tOSD_FACTORY_RELEASE_DATE_STR[] =
{
	_RELEASE_DATE,_END_,
};
BYTE code tOSD_FACTORY_IC_SERIES_STR[] =
{
	_IC_SERIES,_END_,
};
#endif
//--------------------------------------------------
// Factory Text Table
//--------------------------------------------------
BYTE code tOSD_FACTORY_TEXT_STR[] =
{
#if(_OSD_TYPE == _LENOVO_2014_OSD)//jason.cheng 20150116_1 modify follow TPV REQUEST
/*ROW1*/    _NEXT_,//_MODEL_NAME,_SPACE,_SPACE,_SPACE,_FACTORY_PANNEL_NAME,_SPACE,_SPACE ,_NEXT_,/*ROW1*/ 
/*ROW2*/    _NEXT_,//_FW_RELEASE_DATE,_SPACE,_SPACE,_SPACE,_MICROCODE,_NEXT_, 
#else
/*ROW1*/    _FACTORY_PROJECT_NAME,_SPACE,_SPACE,_SPACE,_FACTORY_PANNEL_NAME,_SPACE,_SPACE ,_NEXT_,/*ROW1*/ 
/*ROW2*/    _FW_RELEASE_DATE,_SPACE,_SPACE,_SPACE,_FW_VERSION,_NEXT_, 
#endif
/*ROW3*/    _NEXT_,    
/*ROW4*/    _A,_U,_T,_O,_C,_O,_L,_O,_R,_NEXT_,
/*ROW5*/    _G,_A,_I,_N,_SPACE,_SPACE,_SPACE,_R,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_G,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_B,_NEXT_,	
/*ROW6*/    _O,_F,_F,_S,_E,_T,_SPACE,_R,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_G,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_B,_NEXT_,	
/*ROW7*/    _NEXT_,
            //6500
/*ROW8*/   _FACTORY_COLORTEMP_TEXT1,_SPACE,_SPACE,_SPACE,_R,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_G,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_B,_NEXT_,	
            //7200
/*ROW9*/   _FACTORY_COLORTEMP_TEXT2,_SPACE,_SPACE,_SPACE,_R,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_G,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_B,_NEXT_,	
            //9300
/*ROW10*/    _FACTORY_COLORTEMP_TEXT3,_SPACE,_SPACE,_SPACE,_R,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_G,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_B,_NEXT_,	
            //sRGB
/*ROW11*/    _FACTORY_COLORTEMP_TEXT4,_SPACE,_SPACE,_SPACE,_R,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_G,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_B,_NEXT_,	
            //User
/*ROW12*/   _FACTORY_COLORTEMP_TEXT5,_SPACE,_SPACE,_SPACE,_R,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_G,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_B,_NEXT_,	
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
            //Low Blue Light
/*ROW13*/   _FACTORY_COLORTEMP_TEXT6,_SPACE,_SPACE,_SPACE,_SPACE,_R,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_G,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_B,_NEXT_,	
#endif

/*ROW13*/   _B,_R,_I,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_C,_O,_N,_NEXT_,   
/*ROW14*/   _S,_S,_C,_NEXT_,
/*ROW15*/   _D,_F,_M,_NEXT_,	
/*ROW16*/   _B,_u,_r,_n,_i,_n,_NEXT_,
/*ROW17*/   _E,_D,_I,_D,_SPACE,_W,_P,_NEXT_,
/*ROW18*/   _H,_W,_SPACE,_A,_U,_T,_O,_C,_O,_L,_O,_R,_NEXT_,
#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
/*ROW19*/   _V,_C,_O,_M,_NEXT_,
/*ROW20*/   _P,_A,_N,_E,_L,_SPACE,_T,_I,_M,_E,_NEXT_,
#if(_AUTO_POWER_DOWN == _ON)//jason.cheng
/*ROW21*/   _A,_U,_T,_O,_SPACE,_P,_O,_W,_E,_R,_SPACE,_D,_O,_W,_N,_NEXT_,

#if(_OSD_TYPE == _LENOVO_2014_OSD)//jason.cheng 20150116_1 modify follow TPV REQUEST
/*ROW22*/   _R,_E,_T,_U,_R,_N,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_NEXT_,
#else
/*ROW22*/   _R,_E,_T,_U,_R,_N,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_IC_SERIES,_NEXT_,
#endif

#else

#if(_OSD_TYPE == _LENOVO_2014_OSD)//jason.cheng 20150116_1 modify follow TPV REQUEST
/*ROW21*/   _R,_E,_T,_U,_R,_N,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_NEXT_,
#else
/*ROW21*/   _R,_E,_T,_U,_R,_N,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_IC_SERIES,_NEXT_,
#endif

#endif

#else
/*ROW19*/   _P,_A,_N,_E,_L,_SPACE,_T,_I,_M,_E,_NEXT_,

#if(_AUTO_POWER_DOWN == _ON)//jason.cheng


/*ROW20*/	_A,_U,_T,_O,_SPACE,_P,_O,_W,_E,_R,_SPACE,_D,_O,_W,_N,_NEXT_,
#if (_ENERGY_STAR_SUPPORT == _ON)
	/*ROW21*/	_D,_P,_S,_NEXT_,
#endif

#if(_OSD_TYPE == _LENOVO_2014_OSD)//jason.cheng 20150116_1 modify follow TPV REQUEST
/*ROW21*/	_R,_E,_T,_U,_R,_N,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_NEXT_,
#else
/*ROW21*/	_R,_E,_T,_U,_R,_N,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_IC_SERIES,_NEXT_,
#endif

#else
#if (_ENERGY_STAR_SUPPORT == _ON)
	/*ROW21*/	_D,_P,_S,_NEXT_,
#endif

#if(_OSD_TYPE == _LENOVO_2014_OSD)//jason.cheng 20150116_1 modify follow TPV REQUEST
/*ROW20*/   _R,_E,_T,_U,_R,_N,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_NEXT_,
#else
/*ROW20*/   _R,_E,_T,_U,_R,_N,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_SPACE,_IC_SERIES,_NEXT_,
#endif

#endif
#endif
            _END_,

};


//--------------------------------------------------
// Windows  Table
//--------------------------------------------------
BYTE code tOSD_WINDOW_0_FACTORY_MEMU[] =
{
    WINNO(0),
    ((_CP_0&0x10)<<3) | ((_CP_0&0x10)<<2) | (_BORDER1_1_PIXEL|_BORDER0_1_PIXEL),	// Byte 0 of 104h
    ((_CP_0&0x0F)<<4) | (_CP_0&0x0F),                                   			// Byte 1 of 104h
    0x00,                                                                       	// Byte 2 of 104h
    ((_CP_0&0x20)<<2) | ((_CP_0&0x20)<<1) | (_CP_0&0x20),               			// Byte 0 of 107h    
    _1_LEVEL_RER_GRADIENT | (_CP_1 &0x1F),                                         	// Byte 1 of 107h
    (_WINDOW_ENABLE)//0x8D                                       	    			// Byte 2 of 107h
};

//--------------------------------------------------
// Factory OSD Font BitMap
//--------------------------------------------------
BYTE code tFONT_FACTORY_GLOBAL[]=
{  
    0x03,0xc6,0x81,0xf4,0xe7,0x29,0xa5,0xdb,0x03,0xdd,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xa8,0xc9,0xda,0xab,0x2a,0x59,
    0x5d,0x95,0x3c,0x53,0x95,0x1c,0x55,0xc9,0x30,0xd6,0x06,0x00,
    0xe0,0x82,0x6e,0xe8,0x86,0x6e,0xe8,0x86,0x06,0x0d,0x00,0x80,
    0x9a,0x67,0x6d,0x55,0xc8,0x14,0x6b,0x58,0x2e,0x24,0x28,0xd9,
    0x00,0x00,0xac,0x29,0xd9,0x0d,0x59,0x83,0xad,0x0a,0xaa,0x02,
    0x63,0x6d,0x00,0x00,0x32,0xc3,0x7a,0x67,0xf8,0xae,0x99,0x67,
    0xad,0x35,0x25,0x7b,0xcd,0xb0,0x18,0x16,0x00,0x00,0x4c,0xb2,
    0x91,0x50,0x23,0x5b,0x15,0x54,0x05,0xc6,0xda,0x00,0x00,0x0c,
    0xdc,0xc8,0xb2,0x47,0x42,0x55,0x42,0x55,0x82,0xb1,0x36,0x00,
    0x00,0xaa,0x64,0xab,0x42,0x0c,0xab,0xa1,0x1b,0x1a,0x34,0x00,
    0x00,0x6a,0xb2,0xb6,0xaa,0xc4,0x9e,0x5a,0xa1,0x2a,0xa1,0x2a,
    0xc1,0x58,0x1b,0x00,0x00,0x35,0x59,0x5b,0x55,0x62,0x57,0xad,
    0x50,0x85,0x65,0x00,0x2e,0x00,0x00,0xd4,0x64,0x6d,0x55,0x89,
    0x5d,0x95,0x50,0x95,0x50,0x95,0xa0,0x04,0x00,0x00,0x6a,0x92,
    0xad,0x2a,0xb1,0xa7,0x12,0xaa,0x12,0xaa,0x12,0x8c,0x6c,0x00,
    0x00,0x9c,0xc9,0xda,0x48,0x20,0x81,0x84,0x23,0xc1,0x58,0x1b,
    0x00,0x00,0x35,0xc9,0x56,0x95,0x50,0x95,0x50,0x95,0x50,0x95,
    0x60,0x64,0x03,0x00,0x40,0x25,0x1b,0x89,0x3d,0x12,0x48,0x20,
    0x41,0xc9,0x06,0x00,0x80,0x4a,0x36,0x12,0x7b,0x24,0x90,0x40,
    0x02,0x09,0x00,0x00,0x9c,0xc9,0xda,0x48,0xa4,0x24,0x54,0x25,
    0x54,0x25,0x18,0x6b,0x03,0x00,0xa0,0x2a,0xa1,0x2a,0xb1,0xab,
    0x12,0xaa,0x12,0xaa,0x12,0x94,0x00,0x00,0xa0,0x8d,0xb5,0x1b,
    0xba,0xa1,0x1b,0xba,0xa1,0x19,0x6b,0x03,0x00,0x10,0xc5,0x0e,
    0x24,0x90,0x40,0x42,0x77,0x20,0x17,0x00,0x00,0x6b,0x2a,0xd1,
    0x24,0x19,0x92,0x6a,0x92,0x5a,0x23,0x09,0x25,0x00,0x00,0x40,
    0x02,0x09,0x24,0x90,0x40,0x82,0x92,0x0d,0x00,0x80,0xee,0x6e,
    0xae,0xeb,0xbe,0xbd,0x7d,0xf5,0xfd,0x76,0x77,0xf7,0xd6,0xdd,
    0xdd,0xb4,0x06,0x00,0xc0,0x54,0x25,0xaa,0x2a,0x99,0xae,0x4a,
    0x4e,0xaa,0x92,0x67,0x55,0x25,0x8b,0x12,0x00,0x00,0xa8,0xc9,
    0xda,0xaa,0x12,0xaa,0x12,0xaa,0x12,0xaa,0x12,0x8c,0xb5,0x01,
    0x00,0x50,0x93,0x6c,0x55,0x89,0x3d,0x95,0x40,0x02,0x09,0x08,
    0x00,0x00,0xd4,0x64,0x6d,0x55,0x09,0x55,0x89,0xa7,0x2a,0xb1,
    0xa6,0x92,0x38,0x65,0x6d,0x00,0x00,0xd4,0x24,0x5b,0x55,0x62,
    0xab,0x84,0xaa,0x84,0xaa,0x04,0x25,0x00,0x00,0x98,0x9a,0xac,
    0x8d,0xc4,0x1e,0x2b,0xa3,0x8a,0xa5,0x2a,0x30,0xd6,0x06,0x00,
    0xa0,0x95,0xec,0x86,0x6e,0xe8,0x86,0x6e,0x68,0xd0,0x00,0x00,
    0xa8,0x4a,0xa8,0x4a,0xa8,0x4a,0xa8,0x4a,0xa8,0x4a,0x30,0xd6,
    0x06,0x00,0x40,0x55,0x42,0x55,0x42,0x55,0x62,0x99,0xc4,0x21,
    0x79,0x20,0x03,0x00,0x40,0x77,0x77,0x77,0x77,0x77,0x77,0x77,
    0x77,0x77,0x9f,0xee,0xee,0xdb,0xdc,0x7d,0x41,0x37,0x00,0x00,
    0xaa,0x12,0x6f,0x55,0xa2,0x8d,0xb5,0xdf,0x9a,0xac,0xad,0x2a,
    0x41,0x09,0x00,0x00,0x54,0x25,0x54,0x25,0xb6,0xb1,0xde,0x86,
    0x6e,0x68,0xd0,0x00,0x00,0xec,0xaa,0x64,0xaf,0x29,0x34,0x64,
    0x58,0x6a,0x97,0x04,0x25,0x1b,0x00,0x00,0x40,0xcd,0xb3,0xf6,
    0xae,0x5a,0xa8,0x4a,0xa8,0x4a,0x50,0xd6,0x06,0x00,0x00,0x09,
    0x24,0xd4,0x24,0x5b,0x55,0x42,0x55,0x82,0x91,0x0d,0x00,0x00,
    0xe0,0x4c,0xd6,0x46,0x02,0x09,0x47,0x82,0xb1,0x36,0x00,0x00,
    0xaa,0xb0,0xab,0x16,0xaa,0x12,0xaa,0x12,0xaa,0x12,0x94,0xb5,
    0x01,0x00,0x00,0xd4,0x64,0x6d,0x55,0x09,0x2a,0xd9,0x8e,0x04,
    0x63,0x6d,0x00,0x00,0xa2,0x58,0xbb,0x44,0x37,0x74,0x43,0x37,
    0x34,0x68,0x00,0x00,0x00,0x55,0x59,0x5b,0x55,0x42,0x55,0x42,
    0x95,0xb5,0x55,0x3d,0xc0,0xda,0x00,0x80,0xc4,0x1e,0x09,0x55,
    0x09,0x55,0x09,0x55,0x09,0x4a,0x00,0x00,0xd0,0xd0,0x0d,0x1a,
    0xba,0xa1,0x1b,0x1a,0x34,0x00,0x00,0x6b,0x86,0xb5,0x06,0xd6,
    0x0c,0x6b,0xcd,0xb0,0xd6,0x0c,0x6b,0x1b,0x6b,0x01,0x00,0x80,
    0xc4,0x9a,0x4a,0x34,0x49,0x9a,0xa4,0xd6,0x48,0x42,0x09,0x00,
    0x00,0x1a,0xba,0xa1,0x1b,0xba,0xa1,0x1b,0x1a,0x34,0x00,0x00,
    0x40,0x77,0xf5,0xbd,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,
    0xbb,0x69,0xdd,0x00,0x00,0x00,0x6a,0x92,0xad,0x2a,0xa1,0x2a,
    0xa1,0x2a,0x41,0x09,0x00,0x00,0x00,0x35,0x59,0x5b,0x55,0x42,
    0x55,0x42,0x55,0x82,0xb1,0x36,0x00,0x00,0x80,0x9a,0xac,0xad,
    0x2a,0xa1,0x2a,0xb1,0xa7,0x12,0x48,0x40,0x00,0x00,0xa0,0x2a,
    0x6b,0xab,0x4a,0xa8,0x4a,0xec,0xaa,0x15,0xaa,0x40,0x01,0x00,
    0x80,0x8f,0x59,0xeb,0x1d,0xd6,0xaa,0x61,0xad,0x19,0xd6,0x1a,
    0x58,0x03,0x00,0x00,0xa0,0x26,0x6b,0x0f,0x89,0x55,0xd8,0xaa,
    0x02,0x63,0x6d,0x00,0x00,0x1a,0xba,0x95,0xec,0x86,0x6e,0xe8,
    0x86,0xa6,0x08,0x00,0x00,0xc0,0x9a,0xe9,0x5e,0x6b,0xa6,0x7b,
    0xad,0x99,0xee,0xb5,0x66,0xba,0x17,0x25,0x1b,0x00,0x00,0x40,
    0x55,0x42,0x55,0x62,0x99,0xc4,0x21,0x79,0x20,0x03,0x00,0x00,
    0xd0,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0x7d,0xcd,0xe9,
    0x6e,0xb8,0x6f,0x00,0x00,0x00,0x55,0x89,0x3d,0xb5,0xf2,0xee,
    0xb1,0x6c,0x55,0xc9,0x4b,0x09,0x00,0x00,0x00,0x55,0x09,0x55,
    0x09,0x55,0x09,0x55,0xd6,0x56,0x05,0x46,0x36,0x00,0x00,0xaa,
    0x64,0xc7,0xb0,0x0a,0x1a,0x59,0x43,0xc9,0x06,0x00,0x00,0x00,
    0xf6,0x58,0x30,0xd6,0x06,0x00,0x00,0x00,0x2c,0x58,0xfb,0xc6,
    0xde,0x9b,0x7b,0xed,0xcd,0x6d,0xdd,0x00,0x00,0x00,0xc0,0x30,
    0xec,0xcb,0x66,0xef,0x6b,0xd8,0xfb,0xc2,0x5c,0x00,0x00,0x18,
    0x96,0x41,0x16,0x24,0x90,0x40,0x02,0x2b,0x06,0x6b,0x00,0x60,
    0x0d,0x96,0x1a,0xa8,0x82,0x2a,0xa8,0x82,0x29,0x2c,0xc3,0x02,
    0x00,0x60,0xcd,0x20,0xb0,0x1a,0x9e,0x82,0x33,0x2c,0x03,0x0b,
    0x00,0x00,0x00,0x00,0x00,0xc3,0x02,0xd6,0x00,0x00,0x80,0x00,
    0x01,0x00,0x08,0x10,0x00,0x12,0x01,0x20,0x80,0x04,0x40,0x00,
    0x08,0x12,0xff,
};


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE xdata ucFactoryOsdState=MENU_FACTORY_START;
BYTE xdata ucLcdConditionPattern=0;
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void TPVFactoryExitPro(void);
void TPVFactoryMainMenu(void);
void RTDFactoryOsdFuncDisableOsd(void);
void RTDFactoryOsdLoadHardwareVLCFont(BYTE *pArray, WORD usOffset, WORD usFontTableStart, bit bOsdRotate);
void RTDFactoryOsdFuncSetPosition(WORD usX, WORD usY);
void TPVFactFuncCalcStartAddress(BYTE ucRow, BYTE ucCol, BYTE ucIndicate);
void TPVFactFuncDrawWindow(WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd,BYTE *pStyle);
void TPVFactoryMenuItemSel(BYTE item,BYTE color);
void TPVFactoryMenuRGBnumberItemSel(BYTE ucRow,BYTE ucRGBsel,BYTE color);
void TPVFactFuncShowGainOffset(void);
void TPVFactFuncShowNumber(BYTE ucRow, BYTE ucCol, WORD usValue, BYTE ucPar);
WORD TPVFactFuncValueChange(WORD Value,WORD MaxValue,WORD MinValue,BYTE Step,bit bPar);
void TPVFactoryMenuOnOffSel(BYTE ucRow,BYTE ucCol,bit Sel);
void TPVFactoryMenuPassFailSel(BYTE ucRow,BYTE ucCol,bit Sel);
void TPVFactoryAutoColorAdj(void);


extern void TPVDFMSet( bit bOnOff);
extern bit TPVDFMModeFlag(void);
#if(_OSD_TYPE == _LENOVO_2014_OSD)//jason.cheng 20150116_1 modify follow TPV REQUEST
void TPVFactFuncLoadASCIIText(BYTE ucRow, BYTE ucCol, BYTE *pArrayIn);//2015-01-15  By Jerry //
#endif
//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//----------------------------------------------------------------------------------------------------
// OSD Factory Function
//----------------------------------------------------------------------------------------------------
//--------------------------------------------------
// Description  :TPVFactoryMenuPro
// Input Value  :
// Output Value :
//--------------------------------------------------
void TPVFactoryMenuPro(void)
{
    switch(ucFactoryOsdState)
    {
       case MENU_FACTORY_START:
           ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
           TPVFactoryMainMenu();
       break;

       case MENU_FACTORY_AUTOCOLOR:
           TPVFactoryAutoColorAdj();
       break;
//Gain
       case _MENU_FACTORY_GAIN_R:
       case _MENU_FACTORY_GAIN_G:
       case _MENU_FACTORY_GAIN_B:
           if((SysSourceGetSourceType() == _SOURCE_VGA))
           {
               TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
               TPVFactoryMenuRGBnumberItemSel(ROW(_ADC_GAIN_ROW),(ucFactoryOsdState-_MENU_FACTORY_GAIN_R),(_CP_2));
               ucFactoryOsdState=_MENU_FACTORY_GAIN_R_ADJ+(ucFactoryOsdState-_MENU_FACTORY_GAIN_R);
           }
       break;
//Offset
       case _MENU_FACTORY_OFFSET_R:
       case _MENU_FACTORY_OFFSET_G:
       case _MENU_FACTORY_OFFSET_B:
           if((SysSourceGetSourceType() == _SOURCE_VGA))
           {
               TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
               TPVFactoryMenuRGBnumberItemSel(ROW(_ADC_OFFSET_ROW),(ucFactoryOsdState-_MENU_FACTORY_OFFSET_R),(_CP_2));
               ucFactoryOsdState=_MENU_FACTORY_OFFSET_R_ADJ+(ucFactoryOsdState-_MENU_FACTORY_OFFSET_R);
           }
       break;
//6500
       case _MENU_FACTORY_CT1_R:
       case _MENU_FACTORY_CT1_G:
       case _MENU_FACTORY_CT1_B:
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM1_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT1_R),(_CP_2));
            ucFactoryOsdState=_MENU_FACTORY_CT1_R_ADJ+(ucFactoryOsdState-_MENU_FACTORY_CT1_R);
       break;
//7200
       case _MENU_FACTORY_CT2_R:
       case _MENU_FACTORY_CT2_G:
       case _MENU_FACTORY_CT2_B:
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM2_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT2_R),(_CP_2));
            ucFactoryOsdState=_MENU_FACTORY_CT2_R_ADJ+(ucFactoryOsdState-_MENU_FACTORY_CT2_R);
       break;
//9300
       case _MENU_FACTORY_CT3_R:
       case _MENU_FACTORY_CT3_G:
       case _MENU_FACTORY_CT3_B:       
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM3_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT3_R),(_CP_2));
            ucFactoryOsdState=_MENU_FACTORY_CT3_R_ADJ+(ucFactoryOsdState-_MENU_FACTORY_CT3_R);
       break;
//sRGB
       case _MENU_FACTORY_CT4_R:
       case _MENU_FACTORY_CT4_G:
       case _MENU_FACTORY_CT4_B:        
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM4_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT4_R),(_CP_2));
            ucFactoryOsdState=_MENU_FACTORY_CT4_R_ADJ+(ucFactoryOsdState-_MENU_FACTORY_CT4_R);
       break;
//User
       case _MENU_FACTORY_CT5_R:
       case _MENU_FACTORY_CT5_G:
       case _MENU_FACTORY_CT5_B:      
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM5_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT5_R),(_CP_2));
            ucFactoryOsdState=_MENU_FACTORY_CT5_R_ADJ+(ucFactoryOsdState-_MENU_FACTORY_CT5_R);
       break;

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
//Low blue light
       case _MENU_FACTORY_CT6_R:
       case _MENU_FACTORY_CT6_G:
       case _MENU_FACTORY_CT6_B:        
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM6_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT6_R),(_CP_2));
            ucFactoryOsdState=_MENU_FACTORY_CT6_R_ADJ+(ucFactoryOsdState-_MENU_FACTORY_CT6_R);
       break;
#endif
       
       case _MENU_FACTORY_BRIGHTNESS:
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
		   ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_BRIGHTNESS_ROW*_OSD_FACTORY_COL_SIZE+_BRI_NUMBER_COL),_OSD_BYTE2, (_CP_2 << 4 | _CP_1), LENGTH(3));
           ucFactoryOsdState=_MENU_FACTORY_BRIGHTNESS_ADJ;
       break;
       
       case _MENU_FACTORY_CONTRAST:
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
		   ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_CONTRAST_ROW*_OSD_FACTORY_COL_SIZE+_CON_NUMBER_COL),_OSD_BYTE2, (_CP_2 << 4 | _CP_1), LENGTH(3));
           ucFactoryOsdState=_MENU_FACTORY_CONTRAST_ADJ;
       break;
       
       case _MENU_FACTORY_SSC:
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
		   ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_SSC_ROW*_OSD_FACTORY_COL_SIZE+_SSC_NUMBER_COL),_OSD_BYTE2, (_CP_2 << 4 | _CP_1), LENGTH(3));
           ucFactoryOsdState=_MENU_FACTORY_SSC_ADJ;
       break;
       
       case _MENU_FACTORY_DFM:
            if(_OFF == TPVDFMModeFlag())
            {
               TPVDFMSet(_ON);
            }
            else
            {
               TPVDFMSet(_OFF);
            }                       
           // TPVDFMInitial();
	        TPVFactoryMenuOnOffSel(ROW(_DFM_ROW),COL(_ON_OFF_COL),TPVDFMModeFlag());//TPVDFMModeFlag()
       break;
       
       case _MENU_FACTORY_BURNIN:
            if(_OFF==GET_FACTORY_BURNIN())
            {
               SET_FACTORY_BURNIN(_ON);
            }
            else
            {
               SET_FACTORY_BURNIN(_OFF);
            }
            TPVNVRamSaveFactoryDate();
        	TPVFactoryMenuOnOffSel(ROW(_BURNIN_ROW),COL(_ON_OFF_COL),GET_FACTORY_BURNIN());      //BurnIn ON OFF

       break;
#if (_ENERGY_STAR_SUPPORT == _ON)
	   case _MENU_FACTORY_DPS:
		   if(_OFF==GET_OSD_ES_STATUS())
		   {
			  SET_OSD_ES_STATUS(_ON);
			  UserCommonAdjustESDcrProcess(_ON);
		   }
		   else
		   {
			  SET_OSD_ES_STATUS(_OFF);
			  UserCommonAdjustESDcrProcess(_OFF);
		   }
		   RTDNVRamSaveOSDData();
		   TPVFactoryMenuOnOffSel(ROW(_DPS_ROW),COL(_ON_OFF_COL),GET_OSD_ES_STATUS());		//DPS ON OFF
		   break;
#endif

       case _MENU_FACTORY_EDID_WP:
           if(_LOW == bEDID_WRITE_PROTECT)
           {
               PCB_A0_EDID_EEPROM_WRITE_PROTECT(_HIGH);           
           }
           else
           {
               PCB_A0_EDID_EEPROM_WRITE_PROTECT(_LOW);
           }
           TPVFactoryMenuOnOffSel(ROW(_EDID_WP_ROW),COL(_ON_OFF_COL),(bEDID_WRITE_PROTECT));      //EDID-WP ON OFF

       break;
       
       case _MENU_FACTORY_HW_AUTOCOLOR:
           if(GET_INTERNAL_AUTOCOLOR() == _FAIL)
           {
                SET_INTERNAL_AUTOCOLOR(_SUCCESS);
           }
           else
           {
                SET_INTERNAL_AUTOCOLOR(_FAIL);
           }
           TPVNVRamSaveFactoryDate();
           TPVFactoryMenuPassFailSel(ROW(_HW_ADC_ROW),COL(_PASS_FAIL_COL),GET_INTERNAL_AUTOCOLOR());      //HW ADC ON OFF

       break;

#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
       case _MENU_FACTORY_VCOM:
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
		   ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_PANEL_VCOM_ROW*_OSD_FACTORY_COL_SIZE+_VCOM_NUMBER_COL),_OSD_BYTE2, (_CP_2 << 4 | _CP_1), LENGTH(4));
           ucFactoryOsdState=_MENU_FACTORY_VCOM_ADJ;
       break;
#endif

#if((_OSD_TYPE == _LENOVO_2014_OSD) && (_AUTO_POWER_DOWN == _ON))
		case _MENU_FACTORY_AUTO_POWER_DOWN:
            if(_OFF == GET_FACTORY_AUTO_POWER_DOWN_STAUTS())
            {
               SET_FACTORY_AUTO_POWER_DOWN_STAUTS(_ON);
            }
            else
            {
               SET_FACTORY_AUTO_POWER_DOWN_STAUTS(_OFF);
            }			
			g_usDisPlayCunt = 0;
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_POWER_DOWN_COUNT);
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_POWER_DOWN_TO_POWER_SAVING);
			TPVNVRamSaveFactoryDate();
        	TPVFactoryMenuOnOffSel(ROW(_AUTO_POWER_DOWN_ROW),COL(_AUTO_POWER_DOWN_COL),GET_FACTORY_AUTO_POWER_DOWN_STAUTS());      //BurnIn ON OFF

			break;
#endif
      
       case _MENU_FACTORY_EXIT:
#if((_OSD_TYPE == _LENOVO_ORG_OSD) || (_OSD_TYPE == _LENOVO_2014_OSD))
            RTDFactoryOsdFuncDisableOsd();
			SET_OSD_STATE(_MAIN_FACTORY);
            OsdDispMainMenu();
			ucFactoryOsdState = MENU_FACTORY_START; 
            CLR_KEYREPEATENABLE();
#else            
			OsdFuncDisableOsd();
           	OsdFuncCloseWindow(_WIN_ALL);
           	SET_OSD_STATE(_MENU_NONE);
			SET_OSD_STATE(_OSD_MAIN_TPV_FACTORY);
            OsdDispMainMenu(GET_OSD_STATE());
			ucFactoryOsdState = MENU_FACTORY_START; 
            CLR_KEYREPEATENABLE();
#endif            
       break;

       case _MENU_FACTORY_GAIN_R_ADJ:
       case _MENU_FACTORY_GAIN_G_ADJ:
       case _MENU_FACTORY_GAIN_B_ADJ:
       case _MENU_FACTORY_OFFSET_R_ADJ:
       case _MENU_FACTORY_OFFSET_G_ADJ:
       case _MENU_FACTORY_OFFSET_B_ADJ:
       case _MENU_FACTORY_CT1_R_ADJ:
       case _MENU_FACTORY_CT1_G_ADJ:
       case _MENU_FACTORY_CT1_B_ADJ:
       case _MENU_FACTORY_CT2_R_ADJ:
       case _MENU_FACTORY_CT2_G_ADJ:
       case _MENU_FACTORY_CT2_B_ADJ:
       case _MENU_FACTORY_CT3_R_ADJ:
       case _MENU_FACTORY_CT3_G_ADJ:
       case _MENU_FACTORY_CT3_B_ADJ:
       case _MENU_FACTORY_CT4_R_ADJ:
       case _MENU_FACTORY_CT4_G_ADJ:
       case _MENU_FACTORY_CT4_B_ADJ:
       case _MENU_FACTORY_CT5_R_ADJ:
       case _MENU_FACTORY_CT5_G_ADJ:
       case _MENU_FACTORY_CT5_B_ADJ:
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
  	   case _MENU_FACTORY_CT6_R_ADJ:
  	   case _MENU_FACTORY_CT6_G_ADJ:
  	   case _MENU_FACTORY_CT6_B_ADJ:
#endif		
       case _MENU_FACTORY_BRIGHTNESS_ADJ:
       case _MENU_FACTORY_CONTRAST_ADJ:
       case _MENU_FACTORY_SSC_ADJ:
#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
       case _MENU_FACTORY_VCOM_ADJ:
#endif
            TPVFactoryExitPro();
       break;

       
       default:
       break;
    }
}
//--------------------------------------------------
// Description  :TPVFactoryRightPro
// Input Value  :
// Output Value :
//--------------------------------------------------

void TPVFactoryRightPro(void)
{
    switch(ucFactoryOsdState)
    {
        case MENU_FACTORY_START:
#if((_OSD_TYPE == _LENOVO_ORG_OSD) || (_OSD_TYPE == _LENOVO_2014_OSD))
            CLR_KEYREPEATENABLE();
#else
            #if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
					if(SysSourceGetSourceType() == _SOURCE_VGA)
				{
					SET_OSD_STATE(_OSD_MAIN_IMAGEPOSTION);
				}
				else
				{
					SET_OSD_STATE(_OSD_MAIN_IMAGEPROPERTIES);
				} 
            }
            else
            {
                SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
            }
            OsdDispMainIconSwitch();  
            CLR_KEYREPEATENABLE();
            #else
            SET_OSD_STATE(_OSD_MAIN_BRIGHTCONTRAST);
            OsdDispMainIconSwitch();  
            CLR_KEYREPEATENABLE();
            #endif
#endif
        break;

        case _MENU_FACTORY_OFFSET_B: 
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM1)
            {
                SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM1);
#if((_OSD_TYPE == _LENOVO_2014_OSD)&&(_FACTORY_MODE_OWNER == _OWNER_TPV))
        		if((GET_COLOR_TEMP_TYPE()>= _CT_7200)&&(GET_COLOR_TEMP_TYPE()<= _CT_9300))
        		{
        			SET_PRESET_COLOR_TEMP_BACKUP(_FACTORY_COLORTEMP_ITEM1);
        		}
#endif
                RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM1);
                UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState++;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
        
        case _MENU_FACTORY_CT1_B:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM2)
            {
               SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM2);
#if((_OSD_TYPE == _LENOVO_2014_OSD)&&(_FACTORY_MODE_OWNER == _OWNER_TPV))	   			   
        	   if((GET_COLOR_TEMP_TYPE()>= _CT_7200)&&(GET_COLOR_TEMP_TYPE()<= _CT_9300))
        	   {
        		   SET_PRESET_COLOR_TEMP_BACKUP(_FACTORY_COLORTEMP_ITEM2);
        	   }
#endif
               RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM2);
               UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState++;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
           
        case _MENU_FACTORY_CT2_B:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM3)
            {
               SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM3);
#if((_OSD_TYPE == _LENOVO_2014_OSD)&&(_FACTORY_MODE_OWNER == _OWNER_TPV))	   			   
        	   if((GET_COLOR_TEMP_TYPE()>= _CT_7200)&&(GET_COLOR_TEMP_TYPE()<= _CT_9300))
        	   {
        		   SET_PRESET_COLOR_TEMP_BACKUP(_FACTORY_COLORTEMP_ITEM3);
        	   }
#endif
               RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM3);
               UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState++;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
            
        case _MENU_FACTORY_CT3_B:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM4)
            {
               SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM4);
#if((_OSD_TYPE == _LENOVO_2014_OSD)&&(_FACTORY_MODE_OWNER == _OWNER_TPV))	   			   
        		if((GET_COLOR_TEMP_TYPE()>= _CT_7200)&&(GET_COLOR_TEMP_TYPE()<= _CT_9300))
        		{
        			SET_PRESET_COLOR_TEMP_BACKUP(_FACTORY_COLORTEMP_ITEM4);
        		}
#endif
        	   
               RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM4);
               UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState++;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
            
        case _MENU_FACTORY_CT4_B:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM5)
            {
                SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM5);
                RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM5);
                UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState++;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
        
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
        case _MENU_FACTORY_CT5_B:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM6)
            {
              SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM6);
              RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM6);
              UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState++;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
#endif

       case MENU_FACTORY_AUTOCOLOR:
       case _MENU_FACTORY_GAIN_R:
       case _MENU_FACTORY_GAIN_G:
       case _MENU_FACTORY_GAIN_B:
       case _MENU_FACTORY_OFFSET_R:
       case _MENU_FACTORY_OFFSET_G:
       case _MENU_FACTORY_CT1_R:
       case _MENU_FACTORY_CT1_G:       
       case _MENU_FACTORY_CT2_R:
       case _MENU_FACTORY_CT2_G:
       case _MENU_FACTORY_CT3_R:
       case _MENU_FACTORY_CT3_G:       
       case _MENU_FACTORY_CT4_R:
       case _MENU_FACTORY_CT4_G:
       case _MENU_FACTORY_CT5_R:
       case _MENU_FACTORY_CT5_G:
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	   case _MENU_FACTORY_CT6_R:
	   case _MENU_FACTORY_CT6_G:
       case _MENU_FACTORY_CT6_B:
#else
	   case _MENU_FACTORY_CT5_B:
#endif		
       case _MENU_FACTORY_BRIGHTNESS:
       case _MENU_FACTORY_CONTRAST:
       case _MENU_FACTORY_SSC:
       case _MENU_FACTORY_DFM:
       case _MENU_FACTORY_BURNIN:
       case _MENU_FACTORY_EDID_WP:
       case _MENU_FACTORY_HW_AUTOCOLOR:
#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
       case _MENU_FACTORY_VCOM:
#endif
#if(_AUTO_POWER_DOWN == _ON)
	   case _MENU_FACTORY_AUTO_POWER_DOWN:
#endif
#if (_ENERGY_STAR_SUPPORT== _ON)
	 case _MENU_FACTORY_DPS:
#endif

           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
           ucFactoryOsdState++;
           TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
       break;
       
       case _MENU_FACTORY_EXIT:
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
           ucFactoryOsdState=MENU_FACTORY_AUTOCOLOR;
           TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
       break;
       
      //ADC Gain Adjust
      case _MENU_FACTORY_GAIN_R_ADJ:
           g_stAdcData.ucAdcGainMSB[0]=TPVFactFuncValueChange(g_stAdcData.ucAdcGainMSB[0],0xFF,0x00,0x01,_TRUE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_GAIN_ROW), COL(_R_NUMBER_COL),g_stAdcData.ucAdcGainMSB[0], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;
      
      case _MENU_FACTORY_GAIN_G_ADJ:
           g_stAdcData.ucAdcGainMSB[1]=TPVFactFuncValueChange(g_stAdcData.ucAdcGainMSB[1],0xFF,0x00,0x01,_TRUE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_GAIN_ROW), COL(_G_NUMBER_COL),g_stAdcData.ucAdcGainMSB[1], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;	
      
      case _MENU_FACTORY_GAIN_B_ADJ:
           g_stAdcData.ucAdcGainMSB[2]=TPVFactFuncValueChange(g_stAdcData.ucAdcGainMSB[2],0xFF,0x00,0x01,_TRUE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_GAIN_ROW), COL(_B_NUMBER_COL),g_stAdcData.ucAdcGainMSB[2], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;			
      
      //ADC Offset Adjust
      case _MENU_FACTORY_OFFSET_R_ADJ:
           g_stAdcData.ucAdcOffsetMSB[0]=TPVFactFuncValueChange(g_stAdcData.ucAdcOffsetMSB[0],0xFF,0x00,0x01,_TRUE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_OFFSET_ROW), COL(_R_NUMBER_COL),g_stAdcData.ucAdcOffsetMSB[0], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;
      
      case _MENU_FACTORY_OFFSET_G_ADJ:
           g_stAdcData.ucAdcOffsetMSB[1]=TPVFactFuncValueChange(g_stAdcData.ucAdcOffsetMSB[1],0xFF,0x00,0x01,_TRUE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_OFFSET_ROW), COL(_G_NUMBER_COL),g_stAdcData.ucAdcOffsetMSB[1], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;
      
      case _MENU_FACTORY_OFFSET_B_ADJ:
           g_stAdcData.ucAdcOffsetMSB[2]=TPVFactFuncValueChange(g_stAdcData.ucAdcOffsetMSB[2],0xFF,0x00,0x01,_TRUE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_OFFSET_ROW), COL(_B_NUMBER_COL),g_stAdcData.ucAdcOffsetMSB[2], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;
      
      //Color Temp R Adjust
      case _MENU_FACTORY_CT1_R_ADJ:
      case _MENU_FACTORY_CT2_R_ADJ:
      case _MENU_FACTORY_CT3_R_ADJ:
      case _MENU_FACTORY_CT4_R_ADJ:
      case _MENU_FACTORY_CT5_R_ADJ:		  	
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	  case _MENU_FACTORY_CT6_R_ADJ: 
#endif
           SET_COLOR_TEMP_TYPE_USER_R(TPVFactFuncValueChange(GET_COLOR_TEMP_TYPE_USER_R(),0xFF,0x00,0x01,_TRUE));
           UserAdjustContrast(GET_OSD_CONTRAST()); 
           TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM1_ROW+(ucFactoryOsdState-_MENU_FACTORY_CT1_R_ADJ)/3), COL(_R_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_R(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
      break;
      
      //Color Temp G Adjust    
      case _MENU_FACTORY_CT1_G_ADJ:
      case _MENU_FACTORY_CT2_G_ADJ:
      case _MENU_FACTORY_CT3_G_ADJ:
      case _MENU_FACTORY_CT4_G_ADJ:
      case _MENU_FACTORY_CT5_G_ADJ:
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	  case _MENU_FACTORY_CT6_G_ADJ: 
#endif
           SET_COLOR_TEMP_TYPE_USER_G(TPVFactFuncValueChange(GET_COLOR_TEMP_TYPE_USER_G(),0xFF,0x00,0x01,_TRUE));
           UserAdjustContrast(GET_OSD_CONTRAST());  
           TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM1_ROW+(ucFactoryOsdState-_MENU_FACTORY_CT1_G_ADJ)/3), COL(_G_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_G(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
      break;
      
      //Color Temp B Adjust    
      case _MENU_FACTORY_CT1_B_ADJ:
      case _MENU_FACTORY_CT2_B_ADJ:
      case _MENU_FACTORY_CT3_B_ADJ:
      case _MENU_FACTORY_CT4_B_ADJ:
      case _MENU_FACTORY_CT5_B_ADJ:	
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	  case _MENU_FACTORY_CT6_B_ADJ: 
#endif
           SET_COLOR_TEMP_TYPE_USER_B(TPVFactFuncValueChange(GET_COLOR_TEMP_TYPE_USER_B(),0xFF,0x00,0x01,_TRUE));
           UserAdjustContrast(GET_OSD_CONTRAST());  
           TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM1_ROW+(ucFactoryOsdState-_MENU_FACTORY_CT1_B_ADJ)/3), COL(_B_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_B(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
      break;
      
      //Brightness  Adjust
      case _MENU_FACTORY_BRIGHTNESS_ADJ:                 
           SET_OSD_BACKLIGHT(TPVFactFuncValueChange(GET_OSD_BACKLIGHT(),BACKLIGHT_PERCENT_MAX,BACKLIGHT_PERCENT_MIN,0x01,_TRUE));
           UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
           TPVFactFuncShowNumber(ROW(_BRIGHTNESS_ROW), COL(_BRI_NUMBER_COL), GET_OSD_BACKLIGHT(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));   
           RTDNVRamSaveOSDData();
      break;

      //Ctrast  Adjust
      case _MENU_FACTORY_CONTRAST_ADJ:
           SET_OSD_CONTRAST(TPVFactFuncValueChange(GET_OSD_CONTRAST(),_CONTRAST_MAX,_CONTRAST_MIN,0x01,_TRUE));
           UserAdjustContrast(GET_OSD_CONTRAST());
           TPVFactFuncShowNumber(ROW(_CONTRAST_ROW), COL(_CON_NUMBER_COL), GET_OSD_CONTRAST(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           RTDNVRamSaveBriCon();
      break;
 
      case _MENU_FACTORY_SSC_ADJ:
			UserCommonNVRamSetSystemData(_SSC,TPVFactFuncValueChange(UserCommonNVRamGetSystemData(_SSC),_FACTORY_SSC_MAX,_FACTORY_SSC_MIN,0x01,_TRUE));
			ScalerPllSetDpllSsc(_DCLK_SPREAD_SPEED, UserCommonNVRamGetSystemData(_SSC));	 
            TPVFactFuncShowNumber(ROW(_SSC_ROW), COL(_SSC_NUMBER_COL), UserCommonNVRamGetSystemData(_SSC), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
      break;

#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
      case _MENU_FACTORY_VCOM_ADJ:
            //TPVFCSetPanelVcom(TPVFactFuncValueChange(GET_FACTORY_VCOM(), 128, 0, 0x01, _TRUE));			
            //Ada.chen  20160912 for LNT spec
            TPVFCSetPanelVcom(TPVFactFuncValueChange(GET_FACTORY_VCOM(), 94, 34, 0x01, _TRUE));
            TPVFactFuncShowNumber(ROW(_PANEL_VCOM_ROW), COL(_VCOM_NUMBER_COL), GET_FACTORY_VCOM(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
      break;
#endif

      default:
      break;
    }   
}
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------

void TPVFactoryLeftPro(void)
{
    switch(ucFactoryOsdState)
    {
        case MENU_FACTORY_START:
#if((_OSD_TYPE == _LENOVO_ORG_OSD) || (_OSD_TYPE == _LENOVO_2014_OSD))
            CLR_KEYREPEATENABLE();
#else
            SET_OSD_STATE(_OSD_MAIN_EXIT);
            OsdDispMainIconSwitch(); 
            CLR_KEYREPEATENABLE();
#endif
        break;

        case MENU_FACTORY_AUTOCOLOR:
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState=_MENU_FACTORY_EXIT;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
           
        case _MENU_FACTORY_CT2_R:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM1)
            {
               SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM1);
#if((_OSD_TYPE == _LENOVO_2014_OSD)&&(_FACTORY_MODE_OWNER == _OWNER_TPV))	   			   
        	   if((GET_COLOR_TEMP_TYPE()>= _CT_7200)&&(GET_COLOR_TEMP_TYPE()<= _CT_9300))
        	   {
        			SET_PRESET_COLOR_TEMP_BACKUP(_FACTORY_COLORTEMP_ITEM1);
        	   }
#endif
               RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM1);
               UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState--;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
                    
        case _MENU_FACTORY_CT3_R:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM2)
            {
               SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM2);
#if((_OSD_TYPE == _LENOVO_2014_OSD)&&(_FACTORY_MODE_OWNER == _OWNER_TPV))	   			   
        	   if((GET_COLOR_TEMP_TYPE()>= _CT_7200)&&(GET_COLOR_TEMP_TYPE()<= _CT_9300))
        	   {
        		   SET_PRESET_COLOR_TEMP_BACKUP(_FACTORY_COLORTEMP_ITEM2);
        	   }
#endif
               RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM2);
               UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState--;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
                    
        case _MENU_FACTORY_CT4_R:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM3)
            {
               SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM3);
#if((_OSD_TYPE == _LENOVO_2014_OSD)&&(_FACTORY_MODE_OWNER == _OWNER_TPV))	   			   
        	   if((GET_COLOR_TEMP_TYPE()>= _CT_7200)&&(GET_COLOR_TEMP_TYPE()<= _CT_9300))
        	   {
        		   SET_PRESET_COLOR_TEMP_BACKUP(_FACTORY_COLORTEMP_ITEM3);
        	   }
#endif
               RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM3);
               UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState--;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
        
        case _MENU_FACTORY_CT5_R:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM4)
            {
                SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM4);
#if((_OSD_TYPE == _LENOVO_2014_OSD)&&(_FACTORY_MODE_OWNER == _OWNER_TPV))	   			   
        		if((GET_COLOR_TEMP_TYPE()>= _CT_7200)&&(GET_COLOR_TEMP_TYPE()<= _CT_9300))
        		{
        			SET_PRESET_COLOR_TEMP_BACKUP(_FACTORY_COLORTEMP_ITEM4);
        		}
#endif
                RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM4);
                UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState--;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
        
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
        case _MENU_FACTORY_CT6_R:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM5)
            {
                SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM5);
#if((_OSD_TYPE == _LENOVO_2014_OSD)&&(_FACTORY_MODE_OWNER == _OWNER_TPV))	   			   
        		if((GET_COLOR_TEMP_TYPE()>= _CT_7200)&&(GET_COLOR_TEMP_TYPE()<= _CT_9300))
        		{
        			SET_PRESET_COLOR_TEMP_BACKUP(_FACTORY_COLORTEMP_ITEM5);
        		}
#endif
                RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM5);
                UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState--;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
        break;
#endif

       case _MENU_FACTORY_BRIGHTNESS:
            if(GET_COLOR_TEMP_TYPE() != _FACTORY_COLORTEMP_ITEM6)
            {
                SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM6);

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)  
				SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM6);
				RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM6);
#else
                SET_COLOR_TEMP_TYPE(_FACTORY_COLORTEMP_ITEM5);
				RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM5);
#endif
                UserAdjustContrast(GET_OSD_CONTRAST());  
            }
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState--;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
       break;

       case _MENU_FACTORY_GAIN_R:
       case _MENU_FACTORY_GAIN_G:
       case _MENU_FACTORY_GAIN_B:
       case _MENU_FACTORY_OFFSET_R:
       case _MENU_FACTORY_OFFSET_G:
       case _MENU_FACTORY_OFFSET_B:            
       case _MENU_FACTORY_CT1_R:
       case _MENU_FACTORY_CT1_G:
       case _MENU_FACTORY_CT1_B:
       case _MENU_FACTORY_CT2_G:
       case _MENU_FACTORY_CT2_B:
       case _MENU_FACTORY_CT3_G:
       case _MENU_FACTORY_CT3_B:
       case _MENU_FACTORY_CT4_G:
       case _MENU_FACTORY_CT4_B:
       case _MENU_FACTORY_CT5_G:
       case _MENU_FACTORY_CT5_B:
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	   case _MENU_FACTORY_CT6_G:
	   case _MENU_FACTORY_CT6_B:
#endif		
       case _MENU_FACTORY_CONTRAST:
       case _MENU_FACTORY_SSC:
       case _MENU_FACTORY_DFM:
       case _MENU_FACTORY_BURNIN:
       case _MENU_FACTORY_EDID_WP:
       case _MENU_FACTORY_HW_AUTOCOLOR:
#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
       case _MENU_FACTORY_VCOM:
#endif
#if(_AUTO_POWER_DOWN == _ON)
	   case _MENU_FACTORY_AUTO_POWER_DOWN:
#endif
#if(_ENERGY_STAR_SUPPORT == _ON)
	  case _MENU_FACTORY_DPS:
#endif
       case _MENU_FACTORY_EXIT:
            TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
            ucFactoryOsdState--;
            TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
       break;
      //ADC Gain Adjust
      case _MENU_FACTORY_GAIN_R_ADJ:
           g_stAdcData.ucAdcGainMSB[0]=TPVFactFuncValueChange(g_stAdcData.ucAdcGainMSB[0],0xFF,0x00,0x01,_FALSE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_GAIN_ROW), COL(_R_NUMBER_COL),g_stAdcData.ucAdcGainMSB[0], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;
      
      case _MENU_FACTORY_GAIN_G_ADJ:
           g_stAdcData.ucAdcGainMSB[1]=TPVFactFuncValueChange(g_stAdcData.ucAdcGainMSB[1],0xFF,0x00,0x01,_FALSE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_GAIN_ROW), COL(_G_NUMBER_COL),g_stAdcData.ucAdcGainMSB[1], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;	
      
      case _MENU_FACTORY_GAIN_B_ADJ:
           g_stAdcData.ucAdcGainMSB[2]=TPVFactFuncValueChange(g_stAdcData.ucAdcGainMSB[2],0xFF,0x00,0x01,_FALSE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_GAIN_ROW), COL(_B_NUMBER_COL),g_stAdcData.ucAdcGainMSB[2], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;			
      
      //ADC Offset Adjust
      case _MENU_FACTORY_OFFSET_R_ADJ:
           g_stAdcData.ucAdcOffsetMSB[0]=TPVFactFuncValueChange(g_stAdcData.ucAdcOffsetMSB[0],0xFF,0x00,0x01,_FALSE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_OFFSET_ROW), COL(_R_NUMBER_COL),g_stAdcData.ucAdcOffsetMSB[0], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;
      
      case _MENU_FACTORY_OFFSET_G_ADJ:
           g_stAdcData.ucAdcOffsetMSB[1]=TPVFactFuncValueChange(g_stAdcData.ucAdcOffsetMSB[1],0xFF,0x00,0x01,_FALSE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_OFFSET_ROW), COL(_G_NUMBER_COL),g_stAdcData.ucAdcOffsetMSB[1], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;
      
      case _MENU_FACTORY_OFFSET_B_ADJ:
           g_stAdcData.ucAdcOffsetMSB[2]=TPVFactFuncValueChange(g_stAdcData.ucAdcOffsetMSB[2],0xFF,0x00,0x01,_FALSE);
           UserCommonInterfaceAdjustADCData();
           TPVFactFuncShowNumber(ROW(_ADC_OFFSET_ROW), COL(_B_NUMBER_COL),g_stAdcData.ucAdcOffsetMSB[2], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
      break;
   
      //Color Temp R Adjust
      case _MENU_FACTORY_CT1_R_ADJ:
      case _MENU_FACTORY_CT2_R_ADJ:
      case _MENU_FACTORY_CT3_R_ADJ:
      case _MENU_FACTORY_CT4_R_ADJ:
      case _MENU_FACTORY_CT5_R_ADJ:	  	
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	  case _MENU_FACTORY_CT6_R_ADJ:
#endif
           SET_COLOR_TEMP_TYPE_USER_R(TPVFactFuncValueChange(GET_COLOR_TEMP_TYPE_USER_R(),0xFF,0x00,0x01,_FALSE));
           UserAdjustContrast(GET_OSD_CONTRAST());  
           TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM1_ROW+(ucFactoryOsdState-_MENU_FACTORY_CT1_R_ADJ)/3), COL(_R_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_R(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
      break;
      
      //Color Temp G Adjust    
      case _MENU_FACTORY_CT1_G_ADJ:
      case _MENU_FACTORY_CT2_G_ADJ:
      case _MENU_FACTORY_CT3_G_ADJ:
      case _MENU_FACTORY_CT4_G_ADJ:
      case _MENU_FACTORY_CT5_G_ADJ:	
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	  case _MENU_FACTORY_CT6_G_ADJ:
#endif
           SET_COLOR_TEMP_TYPE_USER_G(TPVFactFuncValueChange(GET_COLOR_TEMP_TYPE_USER_G(),0xFF,0x00,0x01,_FALSE));
           UserAdjustContrast(GET_OSD_CONTRAST());  
           TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM1_ROW+(ucFactoryOsdState-_MENU_FACTORY_CT1_G_ADJ)/3), COL(_G_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_G(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));          
           RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
      break;
      
      //Color Temp B Adjust    
      case _MENU_FACTORY_CT1_B_ADJ:
      case _MENU_FACTORY_CT2_B_ADJ:
      case _MENU_FACTORY_CT3_B_ADJ:
      case _MENU_FACTORY_CT4_B_ADJ:
      case _MENU_FACTORY_CT5_B_ADJ:
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	  case _MENU_FACTORY_CT6_B_ADJ:
#endif
           SET_COLOR_TEMP_TYPE_USER_B(TPVFactFuncValueChange(GET_COLOR_TEMP_TYPE_USER_B(),0xFF,0x00,0x01,_FALSE));
           UserAdjustContrast(GET_OSD_CONTRAST());  
           TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM1_ROW+(ucFactoryOsdState-_MENU_FACTORY_CT1_B_ADJ)/3), COL(_B_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_B(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
           RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
      break;
      
      //Brightness  Adjust
      case _MENU_FACTORY_BRIGHTNESS_ADJ:                 
           SET_OSD_BACKLIGHT(TPVFactFuncValueChange(GET_OSD_BACKLIGHT(),BACKLIGHT_PERCENT_MAX,BACKLIGHT_PERCENT_MIN,0x01,_FALSE));
           UserAdjustBacklightPercent(GET_OSD_BACKLIGHT()); 
           TPVFactFuncShowNumber(ROW(_BRIGHTNESS_ROW), COL(_BRI_NUMBER_COL), GET_OSD_BACKLIGHT(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));   
      break;
      
      case _MENU_FACTORY_CONTRAST_ADJ:
           SET_OSD_CONTRAST(TPVFactFuncValueChange(GET_OSD_CONTRAST(),_CONTRAST_MAX,_CONTRAST_MIN,0x01,_FALSE));
           UserAdjustContrast(GET_OSD_CONTRAST());
           TPVFactFuncShowNumber(ROW(_CONTRAST_ROW), COL(_CON_NUMBER_COL), GET_OSD_CONTRAST(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
      break;
       
      case _MENU_FACTORY_SSC_ADJ:
           UserCommonNVRamSetSystemData(_SSC,TPVFactFuncValueChange(UserCommonNVRamGetSystemData(_SSC),_FACTORY_SSC_MAX,_FACTORY_SSC_MIN,0x01,_FALSE));
           ScalerPllSetDpllSsc(_DCLK_SPREAD_SPEED, UserCommonNVRamGetSystemData(_SSC));	 
           TPVFactFuncShowNumber(ROW(_SSC_ROW), COL(_SSC_NUMBER_COL), UserCommonNVRamGetSystemData(_SSC), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
      break;

#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
      case _MENU_FACTORY_VCOM_ADJ:
            //TPVFCSetPanelVcom(TPVFactFuncValueChange(GET_FACTORY_VCOM(), 128, 0, 0x01, _FALSE));
            //Ada.chen  20160912 for LNT spec
            TPVFCSetPanelVcom(TPVFactFuncValueChange(GET_FACTORY_VCOM(), 94, 34, 0x01, _FALSE));
            TPVFactFuncShowNumber(ROW(_PANEL_VCOM_ROW), COL(_VCOM_NUMBER_COL), GET_FACTORY_VCOM(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
      break;
#endif

      default:
      break;
    }   
}

void TPVFactoryExitPro(void)
{
    switch(ucFactoryOsdState)
    {
       case MENU_FACTORY_START:
#if((_OSD_TYPE == _LENOVO_ORG_OSD) || (_OSD_TYPE == _LENOVO_2014_OSD))
        RTDFactoryOsdFuncDisableOsd();
#else
       OsdDispDisableOsdTimerEvent();
#endif
       break;

       case MENU_FACTORY_AUTOCOLOR:
       case _MENU_FACTORY_GAIN_R:
       case _MENU_FACTORY_GAIN_G:
       case _MENU_FACTORY_GAIN_B:
       case _MENU_FACTORY_OFFSET_R:
       case _MENU_FACTORY_OFFSET_G:
       case _MENU_FACTORY_OFFSET_B:
       case _MENU_FACTORY_CT1_R:
       case _MENU_FACTORY_CT1_G:
       case _MENU_FACTORY_CT1_B:
       case _MENU_FACTORY_CT2_R:
       case _MENU_FACTORY_CT2_G:
       case _MENU_FACTORY_CT2_B:
       case _MENU_FACTORY_CT3_R:
       case _MENU_FACTORY_CT3_G:
       case _MENU_FACTORY_CT3_B:
       case _MENU_FACTORY_CT4_R:
       case _MENU_FACTORY_CT4_G:
       case _MENU_FACTORY_CT4_B:
       case _MENU_FACTORY_CT5_R:
       case _MENU_FACTORY_CT5_G:
       case _MENU_FACTORY_CT5_B:
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	   case _MENU_FACTORY_CT6_R:
	   case _MENU_FACTORY_CT6_G:
	   case _MENU_FACTORY_CT6_B:
#endif
       case _MENU_FACTORY_BRIGHTNESS:
       case _MENU_FACTORY_CONTRAST:
       case _MENU_FACTORY_SSC:
       case _MENU_FACTORY_DFM:
       case _MENU_FACTORY_BURNIN:
       case _MENU_FACTORY_EDID_WP:
       case _MENU_FACTORY_HW_AUTOCOLOR:
#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
       case _MENU_FACTORY_VCOM:
#endif
#if(_AUTO_POWER_DOWN == _ON)
	   case _MENU_FACTORY_AUTO_POWER_DOWN:
#endif
#if(_ENERGY_STAR_SUPPORT == _ON)
	   case _MENU_FACTORY_DPS:
#endif
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_0)); 
           ucFactoryOsdState=_MENU_FACTORY_EXIT;
           TPVFactoryMenuItemSel(ucFactoryOsdState,_CP_2); 
       break;
      
       case _MENU_FACTORY_EXIT:
#if((_OSD_TYPE == _LENOVO_ORG_OSD) || (_OSD_TYPE == _LENOVO_2014_OSD))
			RTDFactoryOsdFuncDisableOsd();
			SET_OSD_STATE(_MAIN_FACTORY);
            OsdDispMainMenu();
			ucFactoryOsdState = MENU_FACTORY_START; 
            CLR_KEYREPEATENABLE();
#else
			OsdDispDisableOsdTimerEvent();
			SET_OSD_STATE(_OSD_MAIN_TPV_FACTORY);
            OsdDispMainMenu(GET_OSD_STATE());
			ucFactoryOsdState = MENU_FACTORY_START; 
            CLR_KEYREPEATENABLE();
#endif
       break;
//Gain
       case _MENU_FACTORY_GAIN_R_ADJ:
       case _MENU_FACTORY_GAIN_G_ADJ:
       case _MENU_FACTORY_GAIN_B_ADJ:
           TPVFactoryMenuRGBnumberItemSel(ROW(_ADC_GAIN_ROW),(ucFactoryOsdState-_MENU_FACTORY_GAIN_R_ADJ),(_CP_0));
           ucFactoryOsdState=_MENU_FACTORY_GAIN_R+(ucFactoryOsdState-_MENU_FACTORY_GAIN_R_ADJ);
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
       break;
//Offset
       case _MENU_FACTORY_OFFSET_R_ADJ:
       case _MENU_FACTORY_OFFSET_G_ADJ:
       case _MENU_FACTORY_OFFSET_B_ADJ:
           TPVFactoryMenuRGBnumberItemSel(ROW(_ADC_OFFSET_ROW),(ucFactoryOsdState-_MENU_FACTORY_OFFSET_R_ADJ),(_CP_0));
           ucFactoryOsdState=_MENU_FACTORY_OFFSET_R+(ucFactoryOsdState-_MENU_FACTORY_OFFSET_R_ADJ);
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
       break;
//6500
       case _MENU_FACTORY_CT1_R_ADJ:
       case _MENU_FACTORY_CT1_G_ADJ:
       case _MENU_FACTORY_CT1_B_ADJ:
           TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM1_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT1_R_ADJ),(_CP_0));
           ucFactoryOsdState=_MENU_FACTORY_CT1_R+(ucFactoryOsdState-_MENU_FACTORY_CT1_R_ADJ);
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
           RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
       break;
//7200
       case _MENU_FACTORY_CT2_R_ADJ:
       case _MENU_FACTORY_CT2_G_ADJ:
       case _MENU_FACTORY_CT2_B_ADJ:
           TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM2_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT2_R_ADJ),(_CP_0));
           ucFactoryOsdState=_MENU_FACTORY_CT2_R+(ucFactoryOsdState-_MENU_FACTORY_CT2_R_ADJ);
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
           RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());           
       break;
//9300
       case _MENU_FACTORY_CT3_R_ADJ:
       case _MENU_FACTORY_CT3_G_ADJ:
       case _MENU_FACTORY_CT3_B_ADJ:
           TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM3_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT3_R_ADJ),(_CP_0));
           ucFactoryOsdState=_MENU_FACTORY_CT3_R+(ucFactoryOsdState-_MENU_FACTORY_CT3_R_ADJ);
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
           RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());           
       break;
//sRGB
       case _MENU_FACTORY_CT4_R_ADJ:
       case _MENU_FACTORY_CT4_G_ADJ:
       case _MENU_FACTORY_CT4_B_ADJ:
           TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM4_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT4_R_ADJ),(_CP_0));
           ucFactoryOsdState=_MENU_FACTORY_CT4_R+(ucFactoryOsdState-_MENU_FACTORY_CT4_R_ADJ);
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
           RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());           
       break;
//User
       case _MENU_FACTORY_CT5_R_ADJ:
       case _MENU_FACTORY_CT5_G_ADJ:
       case _MENU_FACTORY_CT5_B_ADJ:
           TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM5_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT5_R_ADJ),(_CP_0));
           ucFactoryOsdState=_MENU_FACTORY_CT5_R+(ucFactoryOsdState-_MENU_FACTORY_CT5_R_ADJ);
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
           RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());           
       break;
	   
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
//Low blue light
       case _MENU_FACTORY_CT6_R_ADJ:
       case _MENU_FACTORY_CT6_G_ADJ:
       case _MENU_FACTORY_CT6_B_ADJ:
           TPVFactoryMenuRGBnumberItemSel(ROW(_COLORTEMP_ITEM6_ROW),(ucFactoryOsdState-_MENU_FACTORY_CT6_R_ADJ),(_CP_0));
           ucFactoryOsdState=_MENU_FACTORY_CT6_R+(ucFactoryOsdState-_MENU_FACTORY_CT6_R_ADJ);
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
           RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());           
       break;	   
#endif   
    
       case _MENU_FACTORY_BRIGHTNESS_ADJ:
		   ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_BRIGHTNESS_ROW*_OSD_FACTORY_COL_SIZE+_BRI_NUMBER_COL),_OSD_BYTE2, (_CP_0 << 4 | _CP_1), LENGTH(3));
           ucFactoryOsdState=_MENU_FACTORY_BRIGHTNESS;
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
       break;
       
       case _MENU_FACTORY_CONTRAST_ADJ:
		   ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_CONTRAST_ROW*_OSD_FACTORY_COL_SIZE+_ON_OFF_COL),_OSD_BYTE2, (_CP_0 << 4 | _CP_1), LENGTH(3));
           ucFactoryOsdState=_MENU_FACTORY_CONTRAST;
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
       break;
       
       case _MENU_FACTORY_SSC_ADJ:
		   ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_SSC_ROW*_OSD_FACTORY_COL_SIZE+_SSC_NUMBER_COL),_OSD_BYTE2, (_CP_0 << 4 | _CP_1), LENGTH(3));
           ucFactoryOsdState=_MENU_FACTORY_SSC;
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
       break;

#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
       case _MENU_FACTORY_VCOM_ADJ:
		   ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_PANEL_VCOM_ROW*_OSD_FACTORY_COL_SIZE+_VCOM_NUMBER_COL),_OSD_BYTE2, (_CP_0 << 4 | _CP_1), LENGTH(4));
           ucFactoryOsdState=_MENU_FACTORY_VCOM;
           TPVFactoryMenuItemSel(ucFactoryOsdState,(_CP_2)); 
       break;
#endif
              
       default:
       break;
    }    
}


void TPVFactoryMainMenu(void)
{    
    BYTE i = 0,ucTemp=0;
	BYTE ucRow=_MODEL_NAME_ROW;
    BYTE ucCol=_TEXT_START_COL;
    BYTE *pArray;

    //ScalerOsdDisableOsd();    
    //OsdFuncCloseWindow(_WIN_ALL);
    RTDFactoryOsdFuncDisableOsd();                              //關閉OSD動作
	//SET_OSD_IN_FACTORY_MENU_STATUS(_TRUE);                      //設定Factory OSD Flag
#if((_OSD_TYPE == _LENOVO_ORG_OSD) || (_OSD_TYPE == _LENOVO_2014_OSD))
    OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_0);
    OsdFuncOsdTransparency(0);   //Robert Wang 20130604
#else
	OsdLoadPalette(_PALETTE_COMMOND);
#endif
	//Load font
	RTDFactoryOsdLoadHardwareVLCFont(tFONT_FACTORY_GLOBAL,0x00,_OSD_FACTORY_FONT_START_POSITION,_FALSE);

    //Draw Window
	TPVFactFuncDrawWindow(XSTART(0), YSTART(0), XEND(_OSD_FACTORY_COL_SIZE*12), YEND((_OSD_FACTORY_ROW_SIZE+1)*18),tOSD_WINDOW_0_FACTORY_MEMU); 
    // row command
    for(i=0;i<_OSD_FACTORY_ROW_SIZE;i++)
    {
    	ScalerOsdCommandAllByte(i, (_BIT7), ((18-1)<<3), (_OSD_FACTORY_COL_SIZE));
    }
    // row command end
    ScalerOsdCommandByte(_OSD_FACTORY_ROW_SIZE, _OSD_BYTE0, 0x00);
	// setting char&font start address
	ScalerOsdFrameControlAllByte(0x004, _OSD_WITHOUT_DB, (BYTE)_OSD_FACTORY_FONT_SELECT_START, ((_OSD_FACTORY_FONT_SELECT_START >> 4) & 0xf0) | (_OSD_FACTORY_FONT_START_POSITION & 0x0f), _OSD_FACTORY_FONT_START_POSITION >> 4);
	// select ena as OSD Vsync input
	ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, 0x10);
    
    // char command initial    
    ScalerOsdCharCommandAllByteSeries(_OSD_FACTORY_FONT_SELECT_START, 0x8C, _SPACE, (_CP_0<<4), (_OSD_FACTORY_ROW_SIZE * _OSD_FACTORY_COL_SIZE));

	//draw Menu content 
    pArray=tOSD_FACTORY_TEXT_STR;
    ucTemp=0;
    while((*pArray)!=_END_)
    {
        ScalerOsdSramAddressSet(_OSD_FACTORY_FONT_SELECT_START+(WORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol, _OSD_BYTE1);
		switch(*(pArray))
		{
			case _NEXT_:
               ucRow++;
               ucCol=_TEXT_START_COL;
               pArray=pArray+1;
	    	continue;

			default:
               ucTemp=*pArray;
               ucCol=ucCol+1;
               pArray=pArray+1;
		    break;
		}
		ScalerOsdDataPort(ucTemp);
	}
#if(_OSD_TYPE == _LENOVO_2014_OSD)//jason.cheng 20150116_1 modify follow TPV REQUEST
	//2015-01-15  By Jerry //
	TPVFactFuncLoadASCIIText((_MODEL_NAME_ROW),1, tOSD_FACTORY_MODEL_NAME_STR);
	TPVFactFuncLoadASCIIText((_MODEL_NAME_ROW),9, tOSD_FACTORY_PANNEL_NAME_STR);
	TPVFactFuncLoadASCIIText((_MODEL_NAME_ROW+1),1, tOSD_FACTORY_RELEASE_DATE_STR);
	TPVFactFuncLoadASCIIText((_MODEL_NAME_ROW+1),11, tOSD_FACTORY_FW_VERSION_STR);
	TPVFactFuncLoadASCIIText((_EXIT_ROW),15, tOSD_FACTORY_IC_SERIES_STR);
#endif
	//ADC gain/offset
	TPVFactFuncShowGainOffset();    //顯示Gain Offset值

    //6500
    RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM1);
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM1_ROW), COL(_R_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_R(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM1_ROW), COL(_G_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_G(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
    TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM1_ROW), COL(_B_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_B(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));

    //7200
    RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM2);
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM2_ROW), COL(_R_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_R(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM2_ROW), COL(_G_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_G(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
    TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM2_ROW), COL(_B_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_B(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));

    //9300
    RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM3);
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM3_ROW), COL(_R_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_R(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM3_ROW), COL(_G_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_G(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
    TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM3_ROW), COL(_B_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_B(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));

    //sRGB
    RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM4);
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM4_ROW), COL(_R_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_R(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM4_ROW), COL(_G_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_G(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
    TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM4_ROW), COL(_B_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_B(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));

    //User
    RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM5);
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM5_ROW), COL(_R_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_R(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM5_ROW), COL(_G_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_G(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
    TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM5_ROW), COL(_B_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_B(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	//Low blue light
	RTDNVRamLoadColorSetting(_FACTORY_COLORTEMP_ITEM6);
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM6_ROW), COL(_R_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_R(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM6_ROW), COL(_G_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_G(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_COLORTEMP_ITEM6_ROW), COL(_B_NUMBER_COL),GET_COLOR_TEMP_TYPE_USER_B(),(_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
#endif  

   	RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());//Ada.chen modify 6500 always load user colortemp data issue;
    //BRI
    TPVFactFuncShowNumber(ROW(_BRIGHTNESS_ROW), COL(_BRI_NUMBER_COL), GET_OSD_BACKLIGHT(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));   
    
    //CON
    TPVFactFuncShowNumber(ROW(_CONTRAST_ROW), COL(_CON_NUMBER_COL), GET_OSD_CONTRAST(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
    
    //SSC
    TPVFactFuncShowNumber(ROW(_SSC_ROW), COL(_SSC_NUMBER_COL), UserCommonNVRamGetSystemData(_SSC), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
    
    //DFM
	TPVFactoryMenuOnOffSel(ROW(_DFM_ROW),COL(_ON_OFF_COL),TPVDFMModeFlag());//TPVDFMModeFlag()

    //Burn-In
	TPVFactoryMenuOnOffSel(ROW(_BURNIN_ROW),COL(_ON_OFF_COL),GET_FACTORY_BURNIN());      //BurnIn ON OFF

    //EDID-WP
	TPVFactoryMenuOnOffSel(ROW(_EDID_WP_ROW),COL(_ON_OFF_COL),(bEDID_WRITE_PROTECT));      //EDID-WP ON OFF

    //HW AUTO COLOR
	TPVFactoryMenuPassFailSel(ROW(_HW_ADC_ROW),COL(_PASS_FAIL_COL),GET_INTERNAL_AUTOCOLOR());      //HW ADC Pass/Fail

#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
	//Panel VCOM
	TPVFactFuncShowNumber(ROW(_PANEL_VCOM_ROW), COL(_VCOM_NUMBER_COL), GET_FACTORY_VCOM(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF| _SHOW_3));
#endif

    //Panel On Time
    TPVFactFuncShowNumber(ROW(_PANEL_TIME_ROW), COL(PANEL_TIME_NUMBER_COL), GET_PANEL_TIME_HOUR(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
    TPVFactFuncShowNumber(ROW(_PANEL_TIME_ROW), COL(PANEL_TIME_NUMBER_COL+5), GET_PANEL_TIME_MIN(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));    

#if(_AUTO_POWER_DOWN == _ON)	
	TPVFactoryMenuOnOffSel(ROW(_AUTO_POWER_DOWN_ROW),COL(_AUTO_POWER_DOWN_COL),GET_FACTORY_AUTO_POWER_DOWN_STAUTS()); 	 //AUTO POWER DOWN ON OFF
#endif
#if (_ENERGY_STAR_SUPPORT == _ON)
	TPVFactoryMenuOnOffSel(ROW(_DPS_ROW),COL(_ON_OFF_COL),GET_OSD_ES_STATUS()); 	 //DPS ON OFF
#endif

	//select EXIT item   ??
	TPVFactoryMenuItemSel(MENU_FACTORY_AUTOCOLOR,_CP_2); 
    ucFactoryOsdState=MENU_FACTORY_AUTOCOLOR;     
  

    //RTDFactoryOsdFuncSelectItem(_MENU_FACTORY_EXIT);

    RTDFactoryOsdFuncSetPosition(_OSD_FACTORY_H_POSITION, _OSD_FACTORY_V_POSITION);
    ScalerOsdEnableOsd(); 
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//工廠OSD關閉動作
void RTDFactoryOsdFuncDisableOsd(void)
{
    //SET_OSD_STATE(_MENU_NONE);
    //SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
    ScalerOsdDisableOsd();    
    OsdFuncCloseWindow(_WIN_ALL);    
}

//--------------------------------------------------
// Description  : Osd Load Hardware VLC Font
// Input Value  : 
// Output Value : 
//--------------------------------------------------
//工廠字型Bitmap載入到記憶體
void RTDFactoryOsdLoadHardwareVLCFont(BYTE *pArray, WORD usOffset, WORD usFontTableStart, bit bOsdRotate)
{
    WORD usNum = 0x00;
    
    if(bOsdRotate == _TRUE)
    {
        usNum = 0x85;
    }
    
    // rotation
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, usNum);
    
    // osd compression
    ScalerOsdAddrMsb(0xC0);
    ScalerOsdAddrLsb(0x05);
    ScalerOsdBurstWriteDataPort(pArray, 8, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
    
    usNum = ((WORD) * (pArray + 8) << 8) | *(pArray + 9);
    
    usOffset = usOffset * 9;
    usOffset += usFontTableStart;
    
    // osd compression enable
    ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x01);
    
    // Osd load font > 12K
    if(usOffset > 4095)
    {
        ScalerOsdScrambleLoadFontAddrHsbSet();
    }
    else
    {
        ScalerOsdScrambleLoadFontAddrHsbClr();
    }
    
    pArray += 10;
    
    ScalerOsdAddrMsb((HIBYTE(usOffset) & 0x000f) | 0xd0);
    ScalerOsdAddrLsb(LOBYTE(usOffset));
    ScalerOsdBurstWriteDataPort(pArray, usNum, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
    
    // For osd load font > 12K !!
    ScalerOsdScrambleLoadFontAddrHsbClr();
    ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x00);
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, (BYTE)bOsdRotate);
}


//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//工廠OSD Menu位置設定
void RTDFactoryOsdFuncSetPosition(WORD usX, WORD usY)
{
#if(_OSD_ROTATE_FUNCTION == _ON)    
    if(GET_OSD_ROTATE_STATUS() == _TRUE)
    {
            usX = 8 + ((DWORD)((_PANEL_DH_WIDTH-_FACTORY_OSD_WINDOW_SIZE_Y)/4)*usX)/_OSD_H_POS_MAX;
            usY = 0 + ((DWORD)(_PANEL_DV_HEIGHT-_FACTORY_OSD_WINDOW_SIZE_X)*usY)/_OSD_V_POS_MAX;    
    }
    else
#endif        
    {
            usX = 10 + ((DWORD)((_PANEL_DH_WIDTH-_FACTORY_OSD_WINDOW_SIZE_X)/4)*usX)/_OSD_H_POS_MAX;
            usY = 5 + ((DWORD)(_PANEL_DV_HEIGHT-_FACTORY_OSD_WINDOW_SIZE_Y)*usY)/_OSD_V_POS_MAX;
    }

    ScalerOsdScrambleDoubleBufferDepth(3);
    ScalerOsdFrameControlAllByte(0x000, _OSD_WITH_DB, usY>>3, usX>>2, ((usX & 0x0003) << 6) | ((usY & 0x07) << 3) | 0x01);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerOsdScrambleDoubleBufferDepth(6);
}

//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
void TPVFactFuncCalcStartAddress(BYTE ucRow, BYTE ucCol, BYTE ucIndicate)
{
	WORD xdata usOsdAddr = _OSD_FACTORY_FONT_SELECT_START+(WORD)ucRow * _OSD_FACTORY_COL_SIZE + ucCol;

	ScalerOsdAddrMsb((BYTE)(((usOsdAddr)  & 0x0fff) >> 8 ) | (((ucIndicate << 2) + 1) << 4));
	ScalerOsdAddrLsb((BYTE)((usOsdAddr) & 0x00ff));

	if(usOsdAddr > 4095)
	{
		ScalerOsdScrambleLoadFontAddrHsbSet();
	}
	else
	{
		ScalerOsdScrambleLoadFontAddrHsbClr();
	}
	
}


//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
//工廠畫win
void TPVFactFuncDrawWindow(WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd,BYTE *pStyle)
{
    BYTE cnt0 = 0;
    BYTE cnt1 = 0;
 
    cnt0 = ScalerOsdGetOsdEnable();
 
	if ((cnt0 == 0x00))
		ScalerOsdAddrMsb(0xc1);
	else
		ScalerOsdAddrMsb(0xe1);
    
	ScalerOsdAddrLsb(((*(pStyle)) * 4) + 1);
    ScalerOsdDataPort((BYTE)(((usXStart & 0xF00) >> 4) | (usYStart & 0xF00) >> 8));
    ScalerOsdDataPort((BYTE)(usXStart & 0x0FF));
    ScalerOsdDataPort((BYTE)(usYStart & 0x0FF));
    ScalerOsdDataPort((BYTE)(((usXEnd & 0xF00) >> 4) | (usYEnd & 0xF00) >> 8));
    ScalerOsdDataPort((BYTE)(usXEnd & 0x0FF));
    ScalerOsdDataPort((BYTE)(usYEnd & 0x0FF));
 	if(cnt0 == 0x01)
    {
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }
 

    for(cnt1=0;cnt1<2;cnt1++)
    {	
		ScalerOsdFrameControlAllByte((0x100+((*(pStyle)) * 4) + (cnt1 * 3)), _OSD_WITHOUT_DB, ((BYTE)(*(pStyle + ((cnt1 * 3) + 0) + 1))), ((BYTE)(*(pStyle + ((cnt1 * 3) + 1) + 1))),((BYTE)(*(pStyle + ((cnt1 * 3) + 2) + 1))));
    }
}


//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
//選擇Item(改變選到的Item顏色)
void TPVFactoryMenuItemSel(BYTE item,BYTE color)
{   
	switch (item)
	{
	    //Auto Color
        case MENU_FACTORY_AUTOCOLOR:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_AUTO_COLOR_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(9));
			break;

        //ADC Gain
        case _MENU_FACTORY_GAIN_R:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_ADC_GAIN_ROW*_OSD_FACTORY_COL_SIZE+_R_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
            
		case _MENU_FACTORY_GAIN_G:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_ADC_GAIN_ROW*_OSD_FACTORY_COL_SIZE+_G_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
            
		case _MENU_FACTORY_GAIN_B:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_ADC_GAIN_ROW*_OSD_FACTORY_COL_SIZE+_B_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;

        //ADC Offset    
		case _MENU_FACTORY_OFFSET_R:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_ADC_OFFSET_ROW*_OSD_FACTORY_COL_SIZE+_R_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
            
		case _MENU_FACTORY_OFFSET_G:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_ADC_OFFSET_ROW*_OSD_FACTORY_COL_SIZE+_G_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
            
		case _MENU_FACTORY_OFFSET_B:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_ADC_OFFSET_ROW*_OSD_FACTORY_COL_SIZE+_B_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;

        //6500
        case _MENU_FACTORY_CT1_R:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM1_ROW*_OSD_FACTORY_COL_SIZE+_R_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT1_G:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM1_ROW*_OSD_FACTORY_COL_SIZE+_G_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT1_B:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM1_ROW*_OSD_FACTORY_COL_SIZE+_B_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;

        //7200
    	case _MENU_FACTORY_CT2_R:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM2_ROW*_OSD_FACTORY_COL_SIZE+_R_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT2_G:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM2_ROW*_OSD_FACTORY_COL_SIZE+_G_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT2_B:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM2_ROW*_OSD_FACTORY_COL_SIZE+_B_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
     
        //9300
        case _MENU_FACTORY_CT3_R:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM3_ROW*_OSD_FACTORY_COL_SIZE+_R_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT3_G:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM3_ROW*_OSD_FACTORY_COL_SIZE+_G_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT3_B:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM3_ROW*_OSD_FACTORY_COL_SIZE+_B_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;

        //sRGB
        case _MENU_FACTORY_CT4_R:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM4_ROW*_OSD_FACTORY_COL_SIZE+_R_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT4_G:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM4_ROW*_OSD_FACTORY_COL_SIZE+_G_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT4_B:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM4_ROW*_OSD_FACTORY_COL_SIZE+_B_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;

        //User    
		case _MENU_FACTORY_CT5_R:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM5_ROW*_OSD_FACTORY_COL_SIZE+_R_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT5_G:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM5_ROW*_OSD_FACTORY_COL_SIZE+_G_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT5_B:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM5_ROW*_OSD_FACTORY_COL_SIZE+_B_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
		//Low blue light	  
		case _MENU_FACTORY_CT6_R:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM6_ROW*_OSD_FACTORY_COL_SIZE+_R_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT6_G:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM6_ROW*_OSD_FACTORY_COL_SIZE+_G_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
		case _MENU_FACTORY_CT6_B:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_COLORTEMP_ITEM6_ROW*_OSD_FACTORY_COL_SIZE+_B_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(1));
			break;
#endif
        //BRI
        case _MENU_FACTORY_BRIGHTNESS:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_BRIGHTNESS_ROW*_OSD_FACTORY_COL_SIZE+_BRI_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(3));
			break;
        
        //CON
        case _MENU_FACTORY_CONTRAST:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_CONTRAST_ROW*_OSD_FACTORY_COL_SIZE+_CON_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(3));
			break;
            
        //SSC
        case _MENU_FACTORY_SSC:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_SSC_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(3));
			break;
    
        //DFM
        case _MENU_FACTORY_DFM:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_DFM_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(3));
			break;	
            
        //BURNIN   
        case _MENU_FACTORY_BURNIN:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_BURNIN_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(6));
			break;
            
        //EDID WP   
        case _MENU_FACTORY_EDID_WP:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_EDID_WP_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(7));
			break;

        //HW ADC   
        case _MENU_FACTORY_HW_AUTOCOLOR:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_HW_ADC_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(12));
			break;

#if(_PANEL_VCOM_ADJUST_FUNCTION == _ON)//Robert Wang 20131127
        //PANEL VOCM   
        case _MENU_FACTORY_VCOM:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_PANEL_VCOM_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(4));
			break;
#endif

#if(_AUTO_POWER_DOWN == _ON)
		case _MENU_FACTORY_AUTO_POWER_DOWN:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_AUTO_POWER_DOWN_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(15));
			break;
#endif
        //PANEL ON TIME
        //case _MENU_FACTORY_POT:
		//	ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_PANEL_TIME_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(10));
        //    break;
              
#if(_ENERGY_STAR_SUPPORT== _ON)
		case _MENU_FACTORY_DPS:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_DPS_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(7));
			break;
#endif
        //RETURN     
	    case _MENU_FACTORY_EXIT:
			ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_EXIT_ROW*_OSD_FACTORY_COL_SIZE+_TEXT_START_COL),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(6));
			break;
            	
		default:
			break;
	}
}

void TPVFactoryMenuRGBnumberItemSel(BYTE ucRow,BYTE ucRGBsel,BYTE color)
{
    if(ucRGBsel>2)
       ucRGBsel=2;
    
	ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+_R_NUMBER_COL+ucRGBsel*_RGB_GAP),_OSD_BYTE2, (color << 4 | _CP_1), LENGTH(3));
}

//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
//顯示Gain&Offset值
void TPVFactFuncShowGainOffset(void)
{
   	TPVFactFuncShowNumber(ROW(_ADC_GAIN_ROW), COL(_R_NUMBER_COL),g_stAdcData.ucAdcGainMSB[0], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_ADC_GAIN_ROW), COL(_G_NUMBER_COL),g_stAdcData.ucAdcGainMSB[1], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_ADC_GAIN_ROW), COL(_B_NUMBER_COL),g_stAdcData.ucAdcGainMSB[2], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_ADC_OFFSET_ROW), COL(_R_NUMBER_COL),g_stAdcData.ucAdcOffsetMSB[0], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_ADC_OFFSET_ROW), COL(_G_NUMBER_COL),g_stAdcData.ucAdcOffsetMSB[1], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	TPVFactFuncShowNumber(ROW(_ADC_OFFSET_ROW), COL(_B_NUMBER_COL),g_stAdcData.ucAdcOffsetMSB[2], (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
	//ScalerDebugMessage("@@@_GainR", g_stAdcData.ucAdcGainMSB[_AUTO_RED_CHANNEL]);
    //ScalerDebugMessage("@@@_GainG", g_stAdcData.ucAdcGainMSB[_AUTO_GREEN_CHANNEL]);
    //ScalerDebugMessage("@@@_GainB", g_stAdcData.ucAdcGainMSB[_AUTO_BLUE_CHANNEL]);

    //ScalerDebugMessage("@@@_OffsetR", g_stAdcData.ucAdcOffsetMSB[_AUTO_RED_CHANNEL]);
    //ScalerDebugMessage("@@@_OffsetG", g_stAdcData.ucAdcOffsetMSB[_AUTO_GREEN_CHANNEL]);
    //ScalerDebugMessage("@@@_OffsetB", g_stAdcData.ucAdcOffsetMSB[_AUTO_BLUE_CHANNEL]);
}

//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
//顯示數字
void TPVFactFuncShowNumber(BYTE ucRow, BYTE ucCol, WORD usValue, BYTE ucPar)
{
	BYTE ucIndex = 0,ucTemp = 0,ucLoop = 0;
    BYTE ptemp[10]={0};

    ptemp[4] = (_0 + (usValue/10000));
    ptemp[3] = (_0 + (usValue%10000)/1000);
    ptemp[2] = (_0 + (usValue%1000)/100);
    ptemp[1] = (_0 + (usValue%100)/10);
    ptemp[0] = (_0 + (usValue%10));

	for(ucIndex=0; ucIndex<5; ucIndex++)
	{
		if(ptemp[4 - ucIndex] != ((bit)(ucPar & _BIT1) ? _SPACE : _0))
		{
			ucIndex = 4 - ucIndex;
			break;
		}
	}

	if(usValue == 0 && !((bit)(ucPar & 0x02)) )
	{
		ucIndex = 0;
	}

	if((bit)(ucPar & _BIT1))
	{
		ucTemp = (ucPar & 0x70) >> 4;
		ucIndex = (ucPar & 0x70) >> 4;
	}
	else
	{
		ucTemp = (ucPar & 0x70) >> 4;

		if(ucTemp < ucIndex)
		{
			ucTemp = ucIndex;
		}
	}

	if((bit)(ucPar & 0x01))     // Align Right
	{
		TPVFactFuncCalcStartAddress(ucRow, ucCol - ucTemp, _WRITE_BYTE1);
	}
	else
	{                           // Align Left
		TPVFactFuncCalcStartAddress(ucRow, ucCol, _WRITE_BYTE1);
	}

	for(ucLoop=0; ucLoop<=ucTemp; ucLoop++)
	{
		if(ucIndex >= ucTemp)
		{
			ptemp[ucLoop + 5] = ptemp[ucIndex - ucLoop];
		}
		else
		{
			if(ucLoop < (ucTemp - ucIndex))
			{
				ptemp[ucLoop + 5] = _SPACE;
			}
			else
			{
				ptemp[ucLoop + 5] = ptemp[ucIndex - (ucLoop - (ucTemp - ucIndex))];
			}
		}
	}

	for(ucLoop = 0; ucLoop <= ucTemp; ucLoop++)
	{
		ScalerOsdDataPort(ptemp[5 + ucLoop]);
	}
}

//--------------------------------------------------
// Description  : change value by step
// Input Value  :
// Output Value :
//--------------------------------------------------
//Key按下作加減動作
WORD TPVFactFuncValueChange(WORD Value,WORD MaxValue,WORD MinValue,BYTE Step,bit bPar)
{
    if(_TRUE == bPar)
    {
        if((DWORD)MaxValue <= ((DWORD)Value+Step))
        {
            return MaxValue;
        }
        else
        {
            Value = Value + Step ;      
            return Value;
        }        
    }
    else
    {
        if(Value <= (MinValue+Step))
        {
            return MinValue;
        }
        else
        {
            Value = Value - Step;
            return Value;
       }
    }
}
//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
//Bunn IN開關
void TPVFactoryMenuOnOffSel(BYTE ucRow,BYTE ucCol,bit Sel)
{	
    if(Sel)
    {
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol, _OSD_BYTE1, _O);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+1, _OSD_BYTE1, _N);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+2, _OSD_BYTE1, _SPACE);
    }
    else
    {
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol, _OSD_BYTE1, _O);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+1, _OSD_BYTE1, _F);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+2, _OSD_BYTE1, _F);
    }
}

void TPVFactoryAutoColorShowPass(void)
{
   ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+_AUTO_COLOR_ROW*_OSD_FACTORY_COL_SIZE+_PASS_FAIL_COL, _OSD_BYTE1, _P);
   ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+_AUTO_COLOR_ROW*_OSD_FACTORY_COL_SIZE+_PASS_FAIL_COL+1, _OSD_BYTE1, _A);
   ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+_AUTO_COLOR_ROW*_OSD_FACTORY_COL_SIZE+_PASS_FAIL_COL+2, _OSD_BYTE1, _S);
   ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+_AUTO_COLOR_ROW*_OSD_FACTORY_COL_SIZE+_PASS_FAIL_COL+3, _OSD_BYTE1, _S);
}

void TPVFactoryAutoColorShowFail(void)
{
    ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+_AUTO_COLOR_ROW*_OSD_FACTORY_COL_SIZE+_PASS_FAIL_COL, _OSD_BYTE1, _F);
    ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+_AUTO_COLOR_ROW*_OSD_FACTORY_COL_SIZE+_PASS_FAIL_COL+1, _OSD_BYTE1, _A);
    ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+_AUTO_COLOR_ROW*_OSD_FACTORY_COL_SIZE+_PASS_FAIL_COL+2, _OSD_BYTE1, _I);
    ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+_AUTO_COLOR_ROW*_OSD_FACTORY_COL_SIZE+_PASS_FAIL_COL+3, _OSD_BYTE1, _L);
}
void TPVFactoryAutoColorAdj(void)
{
    if((SysSourceGetSourceType() == _SOURCE_VGA))
    {
        if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_RGB) != _AUTO_SUCCESS)
        {
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
            UserCommonEepromRead(_ADC_SETTING_ADDRESS, sizeof(StructAdcDataType), &g_stAdcData.ucAdcPGA);
#else//Robert Wang 20130625 for _SYSTEM_EEPROM_EMULATION_SUPPORT == _ON
            UserCommonFlashLoadADCSetting(_COLOR_SPACE_RGB);
#endif
            UserCommonInterfaceAdjustADCData();
            TPVFactoryAutoColorShowFail();
        }
        else
        {
            ScalerAutoGetAutoColorResult(&g_stAdcData);
            g_stAdcData.ucAdcOffsetMSB[0]=g_stAdcData.ucAdcOffsetMSB[0];
            g_stAdcData.ucAdcOffsetMSB[1]=g_stAdcData.ucAdcOffsetMSB[1];
            g_stAdcData.ucAdcOffsetMSB[2]=g_stAdcData.ucAdcOffsetMSB[2];
            g_stAdcData.ucAdcGainMSB[0]=g_stAdcData.ucAdcGainMSB[0];
            g_stAdcData.ucAdcGainMSB[1]=g_stAdcData.ucAdcGainMSB[1];
            g_stAdcData.ucAdcGainMSB[2]=g_stAdcData.ucAdcGainMSB[2];  
            UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
            UserCommonInterfaceAdjustADCData();
            TPVFactoryAutoColorShowPass();
        }
        TPVFactFuncShowGainOffset();
    }
}
    
#define _INIT_BEGIN          0
#define _RED_PATTERN         1
#define _GREEN_PATTERN       2
#define _BLUE_PATTERN        3
#define _WHITE_PATTERN       4
#define _BLACK_PATTERN       5


//--------------------------------------------------
// Description  : Pannel user time
// Input Value  :
// Output Value :
//--------------------------------------------------
void RTDFactoryPanelUsedTimer(void)
{
    g_stPanelTimeData.ucMin++;
    
    if((g_stPanelTimeData.usHour >= 65535) && (g_stPanelTimeData.ucMin >= 59))
    {
        g_stPanelTimeData.usHour = 65535;
        g_stPanelTimeData.ucMin  = 59;
    }

    if(g_stPanelTimeData.ucMin >= 60)
    {
        g_stPanelTimeData.usHour++;
        g_stPanelTimeData.ucMin = 0;
    }

    if(_OFF == GET_FACTORY_MODE())
    {
        if(!(g_stPanelTimeData.ucMin % 20))// Save data per 20 Min
        {
            RTDNVRamSavePanelUsedTimeData();
        }
    }
    else
    {
        if(MENU_FACTORY_START != ucFactoryOsdState)
        {
            //Show Panel On Time
            ScalerOsdCharCommandByteSeries((_OSD_FACTORY_FONT_SELECT_START+_PANEL_TIME_ROW*_OSD_FACTORY_COL_SIZE+PANEL_TIME_NUMBER_COL+5),_OSD_BYTE1,_SPACE,LENGTH(3));
            TPVFactFuncShowNumber(ROW(_PANEL_TIME_ROW), COL(PANEL_TIME_NUMBER_COL), GET_PANEL_TIME_HOUR(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));
            TPVFactFuncShowNumber(ROW(_PANEL_TIME_ROW), COL(PANEL_TIME_NUMBER_COL+5), GET_PANEL_TIME_MIN(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3));    
        }
        
        RTDNVRamSavePanelUsedTimeData();
    }

    ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);
}

void TPVFactoryMenuPassFailSel(BYTE ucRow,BYTE ucCol,bit Sel)
{	
    if(Sel)
    {
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol, _OSD_BYTE1, _P);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+1, _OSD_BYTE1, _A);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+2, _OSD_BYTE1, _S);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+3, _OSD_BYTE1, _S);
    }
    else
    {
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol, _OSD_BYTE1, _F);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+1, _OSD_BYTE1, _A);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+2, _OSD_BYTE1, _I);
        ScalerOsdCommandByte(_OSD_FACTORY_FONT_SELECT_START+(DWORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol+3, _OSD_BYTE1, _L);
    }
}

#if(_OSD_TYPE == _LENOVO_2014_OSD)//jason.cheng 20150116_1 modify follow TPV REQUEST

BYTE code ASCII_CODE[][2]=
{
	{'0',_0}, {'1',_1}, {'2', _2}, {'3', _3}, {'4', _4}, {'5', _5}, {'6', _6}, {'7', _7}, {'8', _8}, {'9', _9},
	
	{'A', _A}, {'B', _B}, {'C', _C}, {'D', _D}, {'E', _E}, {'F', _F}, {'G', _G}, {'H', _H}, {'I', _I}, {'J', _J},
	{'K', _K}, {'L', _L}, {'M', _M}, {'N', _N}, {'O', _O}, {'P', _P}, {'Q', _Q}, {'R', _R}, {'S', _S}, {'T', _T},
	{'U', _U}, {'V', _V}, {'W', _W}, {'X', _X}, {'Y', _Y}, {'Z', _Z},
	
	{'a', _a}, {'b', _b}, {'c', _c}, {'d',_d}, {'e', _e}, {'f', _f}, {'g', _g}, {'h',_h}, {'i', _i}, {'j', _j},
	{'k', _k}, {'l', _l}, {'m', _m}, {'n',_n}, {'o', _o}, {'p', _p}, {'q', _q}, {'r',_r}, {'s', _s}, {'t', _t},
	{'u', _u}, {'v', _v}, {'w', _w}, {'x',_x}, {'y', _y}, {'z', _z},
	
	{'.', _DOT}, {'/',_SLASH}, {'{',_LBSM}, {'}',_RBSM}, {'(',_LBT}, {')',_RBT}, {':',_COLON},{'-',_MINUS},{' ',_SPACE},
};

void TPVFactFuncLoadASCIIText(BYTE ucRow, BYTE ucCol, BYTE *pArrayIn)
{
	BYTE ucTemp=0;
	ScalerOsdSramAddressSet(_OSD_FACTORY_FONT_SELECT_START+(WORD)ucRow*_OSD_FACTORY_COL_SIZE+ucCol, _OSD_BYTE1);
	while(*pArrayIn != _END_)
	{
		for( ucTemp =0 ; ucTemp < (sizeof(ASCII_CODE)/2) ; ucTemp++)
		{
			if(*pArrayIn == ASCII_CODE[ucTemp][0])
			{
				ScalerOsdDataPort(ASCII_CODE[ucTemp][1]);
				break;;
			}
		}
		if(ucTemp == (sizeof(ASCII_CODE)/2))
		{
			ScalerOsdDataPort(_SPACE);
		}
		pArrayIn++;
	}
	
}
#endif
