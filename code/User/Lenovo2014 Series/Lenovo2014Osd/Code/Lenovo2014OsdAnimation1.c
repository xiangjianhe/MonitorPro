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

#define __RTD_OSD_ANIMATION__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LENOVO_2014_OSD)

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


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdAnimationItemAnimation1(BYTE ucOsdState);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************


//////////////////////////////////////////////////

#define COLOR_o_                    COLOR(_CP_WHITE,_CP_ITEM_SEL_BG)
#define COLOR_of                    COLOR(_CP_ITEM_SEL_BG,_CP_MENU_BG)

#define COLOR_x_                    COLOR(_CP_WHITE,_CP_ITEM_UNSEL_BG)
#define COLOR_xf                    COLOR(_CP_ITEM_UNSEL_BG,_CP_MENU_BG)

#define COLOR___                    COLOR(_CP_MENU_BG,_CP_MENU_BG)

//////////////////////////////////////////////////
/*
BYTE code tOSD_Icon_Animation_L_1_BYTE1[]=
{
    _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3), _Item_Frame_RT_,
    _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7), _Item_Frame_RB_,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE1[]=
{
    (_FONT1_ICON_DYNAMIC_6_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3),
    (_FONT1_ICON_DYNAMIC_6_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7),
};

BYTE code tOSD_Icon_Animation_L_3_BYTE1[]=
{
    (_FONT1_ICON_DYNAMIC_6_of_5 + 2), (_FONT1_ICON_DYNAMIC_6_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2),
    (_FONT1_ICON_DYNAMIC_6_of_5 + 6), (_FONT1_ICON_DYNAMIC_6_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6),
};

BYTE code tOSD_Icon_Animation_L_4_BYTE1[]=
{
    (_FONT1_ICON_DYNAMIC_6_of_5 + 1), (_FONT1_ICON_DYNAMIC_6_of_5 + 2), (_FONT1_ICON_DYNAMIC_6_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1),
    (_FONT1_ICON_DYNAMIC_6_of_5 + 5), (_FONT1_ICON_DYNAMIC_6_of_5 + 6), (_FONT1_ICON_DYNAMIC_6_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5),
};

BYTE code tOSD_Icon_Animation_L_5_BYTE1[]=
{
    (_FONT1_ICON_DYNAMIC_6_of_5 + 0), (_FONT1_ICON_DYNAMIC_6_of_5 + 1), (_FONT1_ICON_DYNAMIC_6_of_5 + 2), (_FONT1_ICON_DYNAMIC_6_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0),
    (_FONT1_ICON_DYNAMIC_6_of_5 + 4), (_FONT1_ICON_DYNAMIC_6_of_5 + 5), (_FONT1_ICON_DYNAMIC_6_of_5 + 6), (_FONT1_ICON_DYNAMIC_6_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4),
};

BYTE code tOSD_Icon_Animation_L_6_BYTE1[]=
{
    _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_6_of_5 + 0), (_FONT1_ICON_DYNAMIC_6_of_5 + 1), (_FONT1_ICON_DYNAMIC_6_of_5 + 2), (_FONT1_ICON_DYNAMIC_6_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_,
    _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_6_of_5 + 4), (_FONT1_ICON_DYNAMIC_6_of_5 + 5), (_FONT1_ICON_DYNAMIC_6_of_5 + 6), (_FONT1_ICON_DYNAMIC_6_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_6_of_5 + 0), (_FONT1_ICON_DYNAMIC_6_of_5 + 1), (_FONT1_ICON_DYNAMIC_6_of_5 + 2), (_FONT1_ICON_DYNAMIC_6_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___,
    ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_6_of_5 + 4), (_FONT1_ICON_DYNAMIC_6_of_5 + 5), (_FONT1_ICON_DYNAMIC_6_of_5 + 6), (_FONT1_ICON_DYNAMIC_6_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_1_of_5 + 0), (_FONT1_ICON_1_START_1_of_5 + 1), (_FONT1_ICON_1_START_1_of_5 + 2), (_FONT1_ICON_1_START_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_2_of_5 + 0), (_FONT1_ICON_1_START_2_of_5 + 1), (_FONT1_ICON_1_START_2_of_5 + 2), (_FONT1_ICON_1_START_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_3_of_5 + 0), (_FONT1_ICON_1_START_3_of_5 + 1), (_FONT1_ICON_1_START_3_of_5 + 2), (_FONT1_ICON_1_START_3_of_5 + 3), (_FONT1_ICON_1_START_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_4_of_5 + 0), (_FONT1_ICON_1_START_4_of_5 + 1), (_FONT1_ICON_1_START_4_of_5 + 2), (_FONT1_ICON_1_START_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_5_of_5 + 0), (_FONT1_ICON_1_START_5_of_5 + 1), (_FONT1_ICON_1_START_5_of_5 + 2), (_FONT1_ICON_1_START_5_of_5 + 3), _Item_Frame_RT_, ___,
    ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_1_of_5 + 4), (_FONT1_ICON_1_START_1_of_5 + 5), (_FONT1_ICON_1_START_1_of_5 + 6), (_FONT1_ICON_1_START_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_2_of_5 + 4), (_FONT1_ICON_1_START_2_of_5 + 5), (_FONT1_ICON_1_START_2_of_5 + 6), (_FONT1_ICON_1_START_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_3_of_5 + 5), (_FONT1_ICON_1_START_3_of_5 + 6), (_FONT1_ICON_1_START_3_of_5 + 7), (_FONT1_ICON_1_START_3_of_5 + 8), (_FONT1_ICON_1_START_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_4_of_5 + 4), (_FONT1_ICON_1_START_4_of_5 + 5), (_FONT1_ICON_1_START_4_of_5 + 6), (_FONT1_ICON_1_START_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_5_of_5 + 4), (_FONT1_ICON_1_START_5_of_5 + 5), (_FONT1_ICON_1_START_5_of_5 + 6), (_FONT1_ICON_1_START_5_of_5 + 7), _Item_Frame_RB_, ___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE1[] =
{
    tOSD_Icon_Animation_L_1_BYTE1,
    tOSD_Icon_Animation_L_2_BYTE1,
    tOSD_Icon_Animation_L_3_BYTE1,
    tOSD_Icon_Animation_L_4_BYTE1,
    tOSD_Icon_Animation_L_5_BYTE1,
    tOSD_Icon_Animation_L_6_BYTE1,
    tOSD_Icon_Animation_L_7_BYTE1,
    tOSD_Icon_Animation_L_8_BYTE1,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_ooooo_ooooo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_ooooo_ooooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_ooooo_ooooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_ooooo_ooooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_ooooo_ooooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_ooooo_ooooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_ooooo_ooooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_ooooo_ooooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_ooooo_ooooo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_L_2_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_L_3_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_L_4_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_L_5_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_L_6_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_L_7_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_L_8_BYTE2_ooooo_ooooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_xoooo_oxooo[]=
{
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_xoooo_oxooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_xoooo_oxooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_xoooo_oxooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_xoooo_oxooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_xoooo_oxooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_xoooo_oxooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_xoooo_oxooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_xoooo_oxooo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_xoooo_oxooo,
    tOSD_Icon_Animation_L_2_BYTE2_xoooo_oxooo,
    tOSD_Icon_Animation_L_3_BYTE2_xoooo_oxooo,
    tOSD_Icon_Animation_L_4_BYTE2_xoooo_oxooo,
    tOSD_Icon_Animation_L_5_BYTE2_xoooo_oxooo,
    tOSD_Icon_Animation_L_6_BYTE2_xoooo_oxooo,
    tOSD_Icon_Animation_L_7_BYTE2_xoooo_oxooo,
    tOSD_Icon_Animation_L_8_BYTE2_xoooo_oxooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_oxooo_ooxoo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_oxooo_ooxoo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_oxooo_ooxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_oxooo_ooxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_oxooo_ooxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_oxooo_ooxoo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_oxooo_ooxoo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_oxooo_ooxoo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_oxooo_ooxoo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_oxooo_ooxoo,
    tOSD_Icon_Animation_L_2_BYTE2_oxooo_ooxoo,
    tOSD_Icon_Animation_L_3_BYTE2_oxooo_ooxoo,
    tOSD_Icon_Animation_L_4_BYTE2_oxooo_ooxoo,
    tOSD_Icon_Animation_L_5_BYTE2_oxooo_ooxoo,
    tOSD_Icon_Animation_L_6_BYTE2_oxooo_ooxoo,
    tOSD_Icon_Animation_L_7_BYTE2_oxooo_ooxoo,
    tOSD_Icon_Animation_L_8_BYTE2_oxooo_ooxoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_ooxoo_oooxo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_ooxoo_oooxo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_ooxoo_oooxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_ooxoo_oooxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_ooxoo_oooxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_ooxoo_oooxo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_ooxoo_oooxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_ooxoo_oooxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_ooxoo_oooxo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_ooxoo_oooxo,
    tOSD_Icon_Animation_L_2_BYTE2_ooxoo_oooxo,
    tOSD_Icon_Animation_L_3_BYTE2_ooxoo_oooxo,
    tOSD_Icon_Animation_L_4_BYTE2_ooxoo_oooxo,
    tOSD_Icon_Animation_L_5_BYTE2_ooxoo_oooxo,
    tOSD_Icon_Animation_L_6_BYTE2_ooxoo_oooxo,
    tOSD_Icon_Animation_L_7_BYTE2_ooxoo_oooxo,
    tOSD_Icon_Animation_L_8_BYTE2_ooxoo_oooxo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_oooxo_oooox[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_oooxo_oooox[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_oooxo_oooox[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_oooxo_oooox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_oooxo_oooox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_oooxo_oooox[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_oooxo_oooox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_oooxo_oooox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_oooxo_oooox[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_oooxo_oooox,
    tOSD_Icon_Animation_L_2_BYTE2_oooxo_oooox,
    tOSD_Icon_Animation_L_3_BYTE2_oooxo_oooox,
    tOSD_Icon_Animation_L_4_BYTE2_oooxo_oooox,
    tOSD_Icon_Animation_L_5_BYTE2_oooxo_oooox,
    tOSD_Icon_Animation_L_6_BYTE2_oooxo_oooox,
    tOSD_Icon_Animation_L_7_BYTE2_oooxo_oooox,
    tOSD_Icon_Animation_L_8_BYTE2_oooxo_oooox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_oooox_xoooo[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_oooox_xoooo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_oooox_xoooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_oooox_xoooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_oooox_xoooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_oooox_xoooo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_oooox_xoooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_oooox_xoooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_oooox_xoooo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_oooox_xoooo,
    tOSD_Icon_Animation_L_2_BYTE2_oooox_xoooo,
    tOSD_Icon_Animation_L_3_BYTE2_oooox_xoooo,
    tOSD_Icon_Animation_L_4_BYTE2_oooox_xoooo,
    tOSD_Icon_Animation_L_5_BYTE2_oooox_xoooo,
    tOSD_Icon_Animation_L_6_BYTE2_oooox_xoooo,
    tOSD_Icon_Animation_L_7_BYTE2_oooox_xoooo,
    tOSD_Icon_Animation_L_8_BYTE2_oooox_xoooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_ooooo_xoooo[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_ooooo_xoooo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_ooooo_xoooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_ooooo_xoooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_ooooo_xoooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_ooooo_xoooo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_ooooo_xoooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_ooooo_xoooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_ooooo_xoooo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_ooooo_xoooo,
    tOSD_Icon_Animation_L_2_BYTE2_ooooo_xoooo,
    tOSD_Icon_Animation_L_3_BYTE2_ooooo_xoooo,
    tOSD_Icon_Animation_L_4_BYTE2_ooooo_xoooo,
    tOSD_Icon_Animation_L_5_BYTE2_ooooo_xoooo,
    tOSD_Icon_Animation_L_6_BYTE2_ooooo_xoooo,
    tOSD_Icon_Animation_L_7_BYTE2_ooooo_xoooo,
    tOSD_Icon_Animation_L_8_BYTE2_ooooo_xoooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_oooox_ooooo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_oooox_ooooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_oooox_ooooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_oooox_ooooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_oooox_ooooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_oooox_ooooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_oooox_ooooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_oooox_ooooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_oooox_ooooo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_oooox_ooooo,
    tOSD_Icon_Animation_L_2_BYTE2_oooox_ooooo,
    tOSD_Icon_Animation_L_3_BYTE2_oooox_ooooo,
    tOSD_Icon_Animation_L_4_BYTE2_oooox_ooooo,
    tOSD_Icon_Animation_L_5_BYTE2_oooox_ooooo,
    tOSD_Icon_Animation_L_6_BYTE2_oooox_ooooo,
    tOSD_Icon_Animation_L_7_BYTE2_oooox_ooooo,
    tOSD_Icon_Animation_L_8_BYTE2_oooox_ooooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_xxooo_oxxoo[]=
{
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_xxooo_oxxoo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_xxooo_oxxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_xxooo_oxxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_xxooo_oxxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_xxooo_oxxoo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_xxooo_oxxoo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_xxooo_oxxoo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_xxooo_oxxoo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_xxooo_oxxoo,
    tOSD_Icon_Animation_L_2_BYTE2_xxooo_oxxoo,
    tOSD_Icon_Animation_L_3_BYTE2_xxooo_oxxoo,
    tOSD_Icon_Animation_L_4_BYTE2_xxooo_oxxoo,
    tOSD_Icon_Animation_L_5_BYTE2_xxooo_oxxoo,
    tOSD_Icon_Animation_L_6_BYTE2_xxooo_oxxoo,
    tOSD_Icon_Animation_L_7_BYTE2_xxooo_oxxoo,
    tOSD_Icon_Animation_L_8_BYTE2_xxooo_oxxoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_oxxoo_ooxxo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_oxxoo_ooxxo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_oxxoo_ooxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_oxxoo_ooxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_oxxoo_ooxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_oxxoo_ooxxo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_oxxoo_ooxxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_oxxoo_ooxxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_oxxoo_ooxxo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_oxxoo_ooxxo,
    tOSD_Icon_Animation_L_2_BYTE2_oxxoo_ooxxo,
    tOSD_Icon_Animation_L_3_BYTE2_oxxoo_ooxxo,
    tOSD_Icon_Animation_L_4_BYTE2_oxxoo_ooxxo,
    tOSD_Icon_Animation_L_5_BYTE2_oxxoo_ooxxo,
    tOSD_Icon_Animation_L_6_BYTE2_oxxoo_ooxxo,
    tOSD_Icon_Animation_L_7_BYTE2_oxxoo_ooxxo,
    tOSD_Icon_Animation_L_8_BYTE2_oxxoo_ooxxo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_ooxxo_oooxx[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_ooxxo_oooxx[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_ooxxo_oooxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_ooxxo_oooxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_ooxxo_oooxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_ooxxo_oooxx[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_ooxxo_oooxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_ooxxo_oooxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_ooxxo_oooxx[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_ooxxo_oooxx,
    tOSD_Icon_Animation_L_2_BYTE2_ooxxo_oooxx,
    tOSD_Icon_Animation_L_3_BYTE2_ooxxo_oooxx,
    tOSD_Icon_Animation_L_4_BYTE2_ooxxo_oooxx,
    tOSD_Icon_Animation_L_5_BYTE2_ooxxo_oooxx,
    tOSD_Icon_Animation_L_6_BYTE2_ooxxo_oooxx,
    tOSD_Icon_Animation_L_7_BYTE2_ooxxo_oooxx,
    tOSD_Icon_Animation_L_8_BYTE2_ooxxo_oooxx,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_oooxx_xooox[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_oooxx_xooox[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_oooxx_xooox[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_oooxx_xooox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_oooxx_xooox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_oooxx_xooox[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_oooxx_xooox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_oooxx_xooox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_oooxx_xooox[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_oooxx_xooox,
    tOSD_Icon_Animation_L_2_BYTE2_oooxx_xooox,
    tOSD_Icon_Animation_L_3_BYTE2_oooxx_xooox,
    tOSD_Icon_Animation_L_4_BYTE2_oooxx_xooox,
    tOSD_Icon_Animation_L_5_BYTE2_oooxx_xooox,
    tOSD_Icon_Animation_L_6_BYTE2_oooxx_xooox,
    tOSD_Icon_Animation_L_7_BYTE2_oooxx_xooox,
    tOSD_Icon_Animation_L_8_BYTE2_oooxx_xooox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_xooox_xxooo[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_xooox_xxooo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_xooox_xxooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_xooox_xxooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_xooox_xxooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_xooox_xxooo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_xooox_xxooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_xooox_xxooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_xooox_xxooo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_xooox_xxooo,
    tOSD_Icon_Animation_L_2_BYTE2_xooox_xxooo,
    tOSD_Icon_Animation_L_3_BYTE2_xooox_xxooo,
    tOSD_Icon_Animation_L_4_BYTE2_xooox_xxooo,
    tOSD_Icon_Animation_L_5_BYTE2_xooox_xxooo,
    tOSD_Icon_Animation_L_6_BYTE2_xooox_xxooo,
    tOSD_Icon_Animation_L_7_BYTE2_xooox_xxooo,
    tOSD_Icon_Animation_L_8_BYTE2_xooox_xxooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_xoooo_xxooo[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_xoooo_xxooo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_xoooo_xxooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_xoooo_xxooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_xoooo_xxooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_xoooo_xxooo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_xoooo_xxooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_xoooo_xxooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_xoooo_xxooo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_xoooo_xxooo,
    tOSD_Icon_Animation_L_2_BYTE2_xoooo_xxooo,
    tOSD_Icon_Animation_L_3_BYTE2_xoooo_xxooo,
    tOSD_Icon_Animation_L_4_BYTE2_xoooo_xxooo,
    tOSD_Icon_Animation_L_5_BYTE2_xoooo_xxooo,
    tOSD_Icon_Animation_L_6_BYTE2_xoooo_xxooo,
    tOSD_Icon_Animation_L_7_BYTE2_xoooo_xxooo,
    tOSD_Icon_Animation_L_8_BYTE2_xoooo_xxooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_oooxx_oooox[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_oooxx_oooox[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_oooxx_oooox[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_oooxx_oooox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_oooxx_oooox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_oooxx_oooox[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_oooxx_oooox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_oooxx_oooox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_oooxx_oooox[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_oooxx_oooox,
    tOSD_Icon_Animation_L_2_BYTE2_oooxx_oooox,
    tOSD_Icon_Animation_L_3_BYTE2_oooxx_oooox,
    tOSD_Icon_Animation_L_4_BYTE2_oooxx_oooox,
    tOSD_Icon_Animation_L_5_BYTE2_oooxx_oooox,
    tOSD_Icon_Animation_L_6_BYTE2_oooxx_oooox,
    tOSD_Icon_Animation_L_7_BYTE2_oooxx_oooox,
    tOSD_Icon_Animation_L_8_BYTE2_oooxx_oooox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_xxxoo_oxxxo[]=
{
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_xxxoo_oxxxo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_xxxoo_oxxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_xxxoo_oxxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_xxxoo_oxxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_xxxoo_oxxxo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_xxxoo_oxxxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_xxxoo_oxxxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_xxxoo_oxxxo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_xxxoo_oxxxo,
    tOSD_Icon_Animation_L_2_BYTE2_xxxoo_oxxxo,
    tOSD_Icon_Animation_L_3_BYTE2_xxxoo_oxxxo,
    tOSD_Icon_Animation_L_4_BYTE2_xxxoo_oxxxo,
    tOSD_Icon_Animation_L_5_BYTE2_xxxoo_oxxxo,
    tOSD_Icon_Animation_L_6_BYTE2_xxxoo_oxxxo,
    tOSD_Icon_Animation_L_7_BYTE2_xxxoo_oxxxo,
    tOSD_Icon_Animation_L_8_BYTE2_xxxoo_oxxxo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_oxxxo_ooxxx[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_oxxxo_ooxxx[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_oxxxo_ooxxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_oxxxo_ooxxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_oxxxo_ooxxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_oxxxo_ooxxx[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_oxxxo_ooxxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_oxxxo_ooxxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_oxxxo_ooxxx[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_oxxxo_ooxxx,
    tOSD_Icon_Animation_L_2_BYTE2_oxxxo_ooxxx,
    tOSD_Icon_Animation_L_3_BYTE2_oxxxo_ooxxx,
    tOSD_Icon_Animation_L_4_BYTE2_oxxxo_ooxxx,
    tOSD_Icon_Animation_L_5_BYTE2_oxxxo_ooxxx,
    tOSD_Icon_Animation_L_6_BYTE2_oxxxo_ooxxx,
    tOSD_Icon_Animation_L_7_BYTE2_oxxxo_ooxxx,
    tOSD_Icon_Animation_L_8_BYTE2_oxxxo_ooxxx,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_ooxxx_xooxx[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_ooxxx_xooxx[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_ooxxx_xooxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_ooxxx_xooxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_ooxxx_xooxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_ooxxx_xooxx[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_ooxxx_xooxx[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_ooxxx_xooxx[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_ooxxx_xooxx[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_ooxxx_xooxx,
    tOSD_Icon_Animation_L_2_BYTE2_ooxxx_xooxx,
    tOSD_Icon_Animation_L_3_BYTE2_ooxxx_xooxx,
    tOSD_Icon_Animation_L_4_BYTE2_ooxxx_xooxx,
    tOSD_Icon_Animation_L_5_BYTE2_ooxxx_xooxx,
    tOSD_Icon_Animation_L_6_BYTE2_ooxxx_xooxx,
    tOSD_Icon_Animation_L_7_BYTE2_ooxxx_xooxx,
    tOSD_Icon_Animation_L_8_BYTE2_ooxxx_xooxx,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_xooxx_xxoox[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_xooxx_xxoox[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_xooxx_xxoox[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_xooxx_xxoox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_xooxx_xxoox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_xooxx_xxoox[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_xooxx_xxoox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_xooxx_xxoox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_xooxx_xxoox[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_xooxx_xxoox,
    tOSD_Icon_Animation_L_2_BYTE2_xooxx_xxoox,
    tOSD_Icon_Animation_L_3_BYTE2_xooxx_xxoox,
    tOSD_Icon_Animation_L_4_BYTE2_xooxx_xxoox,
    tOSD_Icon_Animation_L_5_BYTE2_xooxx_xxoox,
    tOSD_Icon_Animation_L_6_BYTE2_xooxx_xxoox,
    tOSD_Icon_Animation_L_7_BYTE2_xooxx_xxoox,
    tOSD_Icon_Animation_L_8_BYTE2_xooxx_xxoox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_xxoox_xxxoo[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_xxoox_xxxoo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_xxoox_xxxoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_xxoox_xxxoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_xxoox_xxxoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_xxoox_xxxoo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_xxoox_xxxoo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_xxoox_xxxoo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_xxoox_xxxoo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_xxoox_xxxoo,
    tOSD_Icon_Animation_L_2_BYTE2_xxoox_xxxoo,
    tOSD_Icon_Animation_L_3_BYTE2_xxoox_xxxoo,
    tOSD_Icon_Animation_L_4_BYTE2_xxoox_xxxoo,
    tOSD_Icon_Animation_L_5_BYTE2_xxoox_xxxoo,
    tOSD_Icon_Animation_L_6_BYTE2_xxoox_xxxoo,
    tOSD_Icon_Animation_L_7_BYTE2_xxoox_xxxoo,
    tOSD_Icon_Animation_L_8_BYTE2_xxoox_xxxoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_xxooo_xxxoo[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_xxooo_xxxoo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_xxooo_xxxoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_xxooo_xxxoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_xxooo_xxxoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_xxooo_xxxoo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_xxooo_xxxoo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_xxooo_xxxoo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_xxooo_xxxoo[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_xxooo_xxxoo,
    tOSD_Icon_Animation_L_2_BYTE2_xxooo_xxxoo,
    tOSD_Icon_Animation_L_3_BYTE2_xxooo_xxxoo,
    tOSD_Icon_Animation_L_4_BYTE2_xxooo_xxxoo,
    tOSD_Icon_Animation_L_5_BYTE2_xxooo_xxxoo,
    tOSD_Icon_Animation_L_6_BYTE2_xxooo_xxxoo,
    tOSD_Icon_Animation_L_7_BYTE2_xxooo_xxxoo,
    tOSD_Icon_Animation_L_8_BYTE2_xxooo_xxxoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_L_1_BYTE2_ooxxx_oooxx[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_2_BYTE2_ooxxx_oooxx[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_3_BYTE2_ooxxx_oooxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_4_BYTE2_ooxxx_oooxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_5_BYTE2_ooxxx_oooxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_L_6_BYTE2_ooxxx_oooxx[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_L_7_BYTE2_ooxxx_oooxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_L_8_BYTE2_ooxxx_oooxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_L_BYTE2_ooxxx_oooxx[] =
{
    tOSD_Icon_Animation_L_1_BYTE2_ooxxx_oooxx,
    tOSD_Icon_Animation_L_2_BYTE2_ooxxx_oooxx,
    tOSD_Icon_Animation_L_3_BYTE2_ooxxx_oooxx,
    tOSD_Icon_Animation_L_4_BYTE2_ooxxx_oooxx,
    tOSD_Icon_Animation_L_5_BYTE2_ooxxx_oooxx,
    tOSD_Icon_Animation_L_6_BYTE2_ooxxx_oooxx,
    tOSD_Icon_Animation_L_7_BYTE2_ooxxx_oooxx,
    tOSD_Icon_Animation_L_8_BYTE2_ooxxx_oooxx,
};

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE1[]=
{
    _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_,
    _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE1[]=
{
    (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_6_of_5 + 0),
    (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_6_of_5 + 4),
};

BYTE code tOSD_Icon_Animation_R_3_BYTE1[]=
{
    (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_6_of_5 + 0), (_FONT1_ICON_DYNAMIC_6_of_5 + 1),
    (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_6_of_5 + 4), (_FONT1_ICON_DYNAMIC_6_of_5 + 5),
};

BYTE code tOSD_Icon_Animation_R_4_BYTE1[]=
{
    (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_6_of_5 + 0), (_FONT1_ICON_DYNAMIC_6_of_5 + 1), (_FONT1_ICON_DYNAMIC_6_of_5 + 2),
    (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_6_of_5 + 4), (_FONT1_ICON_DYNAMIC_6_of_5 + 5), (_FONT1_ICON_DYNAMIC_6_of_5 + 6),
};

BYTE code tOSD_Icon_Animation_R_5_BYTE1[]=
{
    (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_6_of_5 + 0), (_FONT1_ICON_DYNAMIC_6_of_5 + 1), (_FONT1_ICON_DYNAMIC_6_of_5 + 2), (_FONT1_ICON_DYNAMIC_6_of_5 + 3),
    (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_6_of_5 + 4), (_FONT1_ICON_DYNAMIC_6_of_5 + 5), (_FONT1_ICON_DYNAMIC_6_of_5 + 6), (_FONT1_ICON_DYNAMIC_6_of_5 + 7),
};

BYTE code tOSD_Icon_Animation_R_6_BYTE1[]=
{
    _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_6_of_5 + 0), (_FONT1_ICON_DYNAMIC_6_of_5 + 1), (_FONT1_ICON_DYNAMIC_6_of_5 + 2), (_FONT1_ICON_DYNAMIC_6_of_5 + 3), _Item_Frame_RT_,
    _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_6_of_5 + 4), (_FONT1_ICON_DYNAMIC_6_of_5 + 5), (_FONT1_ICON_DYNAMIC_6_of_5 + 6), (_FONT1_ICON_DYNAMIC_6_of_5 + 7), _Item_Frame_RB_,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_6_of_5 + 0), (_FONT1_ICON_DYNAMIC_6_of_5 + 1), (_FONT1_ICON_DYNAMIC_6_of_5 + 2), (_FONT1_ICON_DYNAMIC_6_of_5 + 3), _Item_Frame_RT_, ___,
    ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_6_of_5 + 4), (_FONT1_ICON_DYNAMIC_6_of_5 + 5), (_FONT1_ICON_DYNAMIC_6_of_5 + 6), (_FONT1_ICON_DYNAMIC_6_of_5 + 7), _Item_Frame_RB_, ___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_1_of_5 + 0), (_FONT1_ICON_1_START_1_of_5 + 1), (_FONT1_ICON_1_START_1_of_5 + 2), (_FONT1_ICON_1_START_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_2_of_5 + 0), (_FONT1_ICON_1_START_2_of_5 + 1), (_FONT1_ICON_1_START_2_of_5 + 2), (_FONT1_ICON_1_START_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_3_of_5 + 0), (_FONT1_ICON_1_START_3_of_5 + 1), (_FONT1_ICON_1_START_3_of_5 + 2), (_FONT1_ICON_1_START_3_of_5 + 3), (_FONT1_ICON_1_START_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_4_of_5 + 0), (_FONT1_ICON_1_START_4_of_5 + 1), (_FONT1_ICON_1_START_4_of_5 + 2), (_FONT1_ICON_1_START_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_1_START_5_of_5 + 0), (_FONT1_ICON_1_START_5_of_5 + 1), (_FONT1_ICON_1_START_5_of_5 + 2), (_FONT1_ICON_1_START_5_of_5 + 3), _Item_Frame_RT_, ___,
    ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_1_of_5 + 4), (_FONT1_ICON_1_START_1_of_5 + 5), (_FONT1_ICON_1_START_1_of_5 + 6), (_FONT1_ICON_1_START_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_2_of_5 + 4), (_FONT1_ICON_1_START_2_of_5 + 5), (_FONT1_ICON_1_START_2_of_5 + 6), (_FONT1_ICON_1_START_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_3_of_5 + 5), (_FONT1_ICON_1_START_3_of_5 + 6), (_FONT1_ICON_1_START_3_of_5 + 7), (_FONT1_ICON_1_START_3_of_5 + 8), (_FONT1_ICON_1_START_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_4_of_5 + 4), (_FONT1_ICON_1_START_4_of_5 + 5), (_FONT1_ICON_1_START_4_of_5 + 6), (_FONT1_ICON_1_START_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_1_START_5_of_5 + 4), (_FONT1_ICON_1_START_5_of_5 + 5), (_FONT1_ICON_1_START_5_of_5 + 6), (_FONT1_ICON_1_START_5_of_5 + 7), _Item_Frame_RB_, ___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE1[] =
{
    tOSD_Icon_Animation_R_1_BYTE1,
    tOSD_Icon_Animation_R_2_BYTE1,
    tOSD_Icon_Animation_R_3_BYTE1,
    tOSD_Icon_Animation_R_4_BYTE1,
    tOSD_Icon_Animation_R_5_BYTE1,
    tOSD_Icon_Animation_R_6_BYTE1,
    tOSD_Icon_Animation_R_7_BYTE1,
    tOSD_Icon_Animation_R_8_BYTE1,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_ooooo_ooooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_ooooo_ooooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_ooooo_ooooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_ooooo_ooooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_ooooo_ooooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_ooooo_ooooo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_ooooo_ooooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_ooooo_ooooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_ooooo_ooooo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_R_2_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_R_3_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_R_4_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_R_5_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_R_6_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_R_7_BYTE2_ooooo_ooooo,
    tOSD_Icon_Animation_R_8_BYTE2_ooooo_ooooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_xoooo_oooox[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_xoooo_oooox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_xoooo_oooox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_xoooo_oooox[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_xoooo_oooox[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_xoooo_oooox[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_xoooo_oooox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_xoooo_oooox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_xoooo_oooox[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_xoooo_oooox,
    tOSD_Icon_Animation_R_2_BYTE2_xoooo_oooox,
    tOSD_Icon_Animation_R_3_BYTE2_xoooo_oooox,
    tOSD_Icon_Animation_R_4_BYTE2_xoooo_oooox,
    tOSD_Icon_Animation_R_5_BYTE2_xoooo_oooox,
    tOSD_Icon_Animation_R_6_BYTE2_xoooo_oooox,
    tOSD_Icon_Animation_R_7_BYTE2_xoooo_oooox,
    tOSD_Icon_Animation_R_8_BYTE2_xoooo_oooox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_oooox_oooxo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_oooox_oooxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_oooox_oooxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_oooox_oooxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_oooox_oooxo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_oooox_oooxo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_oooox_oooxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_oooox_oooxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_oooox_oooxo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_oooox_oooxo,
    tOSD_Icon_Animation_R_2_BYTE2_oooox_oooxo,
    tOSD_Icon_Animation_R_3_BYTE2_oooox_oooxo,
    tOSD_Icon_Animation_R_4_BYTE2_oooox_oooxo,
    tOSD_Icon_Animation_R_5_BYTE2_oooox_oooxo,
    tOSD_Icon_Animation_R_6_BYTE2_oooox_oooxo,
    tOSD_Icon_Animation_R_7_BYTE2_oooox_oooxo,
    tOSD_Icon_Animation_R_8_BYTE2_oooox_oooxo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_oooxo_ooxoo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_oooxo_ooxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_oooxo_ooxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_oooxo_ooxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_oooxo_ooxoo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_oooxo_ooxoo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_oooxo_ooxoo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_oooxo_ooxoo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_oooxo_ooxoo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_oooxo_ooxoo,
    tOSD_Icon_Animation_R_2_BYTE2_oooxo_ooxoo,
    tOSD_Icon_Animation_R_3_BYTE2_oooxo_ooxoo,
    tOSD_Icon_Animation_R_4_BYTE2_oooxo_ooxoo,
    tOSD_Icon_Animation_R_5_BYTE2_oooxo_ooxoo,
    tOSD_Icon_Animation_R_6_BYTE2_oooxo_ooxoo,
    tOSD_Icon_Animation_R_7_BYTE2_oooxo_ooxoo,
    tOSD_Icon_Animation_R_8_BYTE2_oooxo_ooxoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_ooxoo_oxooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_ooxoo_oxooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_ooxoo_oxooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_ooxoo_oxooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_ooxoo_oxooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_ooxoo_oxooo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_ooxoo_oxooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_ooxoo_oxooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_ooxoo_oxooo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_ooxoo_oxooo,
    tOSD_Icon_Animation_R_2_BYTE2_ooxoo_oxooo,
    tOSD_Icon_Animation_R_3_BYTE2_ooxoo_oxooo,
    tOSD_Icon_Animation_R_4_BYTE2_ooxoo_oxooo,
    tOSD_Icon_Animation_R_5_BYTE2_ooxoo_oxooo,
    tOSD_Icon_Animation_R_6_BYTE2_ooxoo_oxooo,
    tOSD_Icon_Animation_R_7_BYTE2_ooxoo_oxooo,
    tOSD_Icon_Animation_R_8_BYTE2_ooxoo_oxooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_oxooo_xoooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_oxooo_xoooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_oxooo_xoooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_oxooo_xoooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_oxooo_xoooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_oxooo_xoooo[]=
{
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_oxooo_xoooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_oxooo_xoooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_oxooo_xoooo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_oxooo_xoooo,
    tOSD_Icon_Animation_R_2_BYTE2_oxooo_xoooo,
    tOSD_Icon_Animation_R_3_BYTE2_oxooo_xoooo,
    tOSD_Icon_Animation_R_4_BYTE2_oxooo_xoooo,
    tOSD_Icon_Animation_R_5_BYTE2_oxooo_xoooo,
    tOSD_Icon_Animation_R_6_BYTE2_oxooo_xoooo,
    tOSD_Icon_Animation_R_7_BYTE2_oxooo_xoooo,
    tOSD_Icon_Animation_R_8_BYTE2_oxooo_xoooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_xoooo_ooooo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_xoooo_ooooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_xoooo_ooooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_xoooo_ooooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_xoooo_ooooo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_xoooo_ooooo[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_xoooo_ooooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_xoooo_ooooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_xoooo_ooooo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_xoooo_ooooo,
    tOSD_Icon_Animation_R_2_BYTE2_xoooo_ooooo,
    tOSD_Icon_Animation_R_3_BYTE2_xoooo_ooooo,
    tOSD_Icon_Animation_R_4_BYTE2_xoooo_ooooo,
    tOSD_Icon_Animation_R_5_BYTE2_xoooo_ooooo,
    tOSD_Icon_Animation_R_6_BYTE2_xoooo_ooooo,
    tOSD_Icon_Animation_R_7_BYTE2_xoooo_ooooo,
    tOSD_Icon_Animation_R_8_BYTE2_xoooo_ooooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_ooooo_oooox[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_ooooo_oooox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_ooooo_oooox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_ooooo_oooox[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_ooooo_oooox[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_ooooo_oooox[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_ooooo_oooox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_ooooo_oooox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_ooooo_oooox[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_ooooo_oooox,
    tOSD_Icon_Animation_R_2_BYTE2_ooooo_oooox,
    tOSD_Icon_Animation_R_3_BYTE2_ooooo_oooox,
    tOSD_Icon_Animation_R_4_BYTE2_ooooo_oooox,
    tOSD_Icon_Animation_R_5_BYTE2_ooooo_oooox,
    tOSD_Icon_Animation_R_6_BYTE2_ooooo_oooox,
    tOSD_Icon_Animation_R_7_BYTE2_ooooo_oooox,
    tOSD_Icon_Animation_R_8_BYTE2_ooooo_oooox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_xxooo_xooox[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_xxooo_xooox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_xxooo_xooox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_xxooo_xooox[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_xxooo_xooox[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_xxooo_xooox[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_xxooo_xooox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_xxooo_xooox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_xxooo_xooox[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_xxooo_xooox,
    tOSD_Icon_Animation_R_2_BYTE2_xxooo_xooox,
    tOSD_Icon_Animation_R_3_BYTE2_xxooo_xooox,
    tOSD_Icon_Animation_R_4_BYTE2_xxooo_xooox,
    tOSD_Icon_Animation_R_5_BYTE2_xxooo_xooox,
    tOSD_Icon_Animation_R_6_BYTE2_xxooo_xooox,
    tOSD_Icon_Animation_R_7_BYTE2_xxooo_xooox,
    tOSD_Icon_Animation_R_8_BYTE2_xxooo_xooox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_xooox_oooxx[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_xooox_oooxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_xooox_oooxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_xooox_oooxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_xooox_oooxx[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_xooox_oooxx[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_xooox_oooxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_xooox_oooxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_xooox_oooxx[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_xooox_oooxx,
    tOSD_Icon_Animation_R_2_BYTE2_xooox_oooxx,
    tOSD_Icon_Animation_R_3_BYTE2_xooox_oooxx,
    tOSD_Icon_Animation_R_4_BYTE2_xooox_oooxx,
    tOSD_Icon_Animation_R_5_BYTE2_xooox_oooxx,
    tOSD_Icon_Animation_R_6_BYTE2_xooox_oooxx,
    tOSD_Icon_Animation_R_7_BYTE2_xooox_oooxx,
    tOSD_Icon_Animation_R_8_BYTE2_xooox_oooxx,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_oooxx_ooxxo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_oooxx_ooxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_oooxx_ooxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_oooxx_ooxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_oooxx_ooxxo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_oooxx_ooxxo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_oooxx_ooxxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_oooxx_ooxxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_oooxx_ooxxo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_oooxx_ooxxo,
    tOSD_Icon_Animation_R_2_BYTE2_oooxx_ooxxo,
    tOSD_Icon_Animation_R_3_BYTE2_oooxx_ooxxo,
    tOSD_Icon_Animation_R_4_BYTE2_oooxx_ooxxo,
    tOSD_Icon_Animation_R_5_BYTE2_oooxx_ooxxo,
    tOSD_Icon_Animation_R_6_BYTE2_oooxx_ooxxo,
    tOSD_Icon_Animation_R_7_BYTE2_oooxx_ooxxo,
    tOSD_Icon_Animation_R_8_BYTE2_oooxx_ooxxo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_ooxxo_oxxoo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_ooxxo_oxxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_ooxxo_oxxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_ooxxo_oxxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_ooxxo_oxxoo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_ooxxo_oxxoo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_ooxxo_oxxoo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_ooxxo_oxxoo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_ooxxo_oxxoo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_ooxxo_oxxoo,
    tOSD_Icon_Animation_R_2_BYTE2_ooxxo_oxxoo,
    tOSD_Icon_Animation_R_3_BYTE2_ooxxo_oxxoo,
    tOSD_Icon_Animation_R_4_BYTE2_ooxxo_oxxoo,
    tOSD_Icon_Animation_R_5_BYTE2_ooxxo_oxxoo,
    tOSD_Icon_Animation_R_6_BYTE2_ooxxo_oxxoo,
    tOSD_Icon_Animation_R_7_BYTE2_ooxxo_oxxoo,
    tOSD_Icon_Animation_R_8_BYTE2_ooxxo_oxxoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_oxxoo_xxooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_oxxoo_xxooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_oxxoo_xxooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_oxxoo_xxooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_oxxoo_xxooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_oxxoo_xxooo[]=
{
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_oxxoo_xxooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_oxxoo_xxooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_oxxoo_xxooo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_oxxoo_xxooo,
    tOSD_Icon_Animation_R_2_BYTE2_oxxoo_xxooo,
    tOSD_Icon_Animation_R_3_BYTE2_oxxoo_xxooo,
    tOSD_Icon_Animation_R_4_BYTE2_oxxoo_xxooo,
    tOSD_Icon_Animation_R_5_BYTE2_oxxoo_xxooo,
    tOSD_Icon_Animation_R_6_BYTE2_oxxoo_xxooo,
    tOSD_Icon_Animation_R_7_BYTE2_oxxoo_xxooo,
    tOSD_Icon_Animation_R_8_BYTE2_oxxoo_xxooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_oooox_oooxx[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_oooox_oooxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_oooox_oooxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_oooox_oooxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_oooox_oooxx[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_oooox_oooxx[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_oooox_oooxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_oooox_oooxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_oooox_oooxx[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_oooox_oooxx,
    tOSD_Icon_Animation_R_2_BYTE2_oooox_oooxx,
    tOSD_Icon_Animation_R_3_BYTE2_oooox_oooxx,
    tOSD_Icon_Animation_R_4_BYTE2_oooox_oooxx,
    tOSD_Icon_Animation_R_5_BYTE2_oooox_oooxx,
    tOSD_Icon_Animation_R_6_BYTE2_oooox_oooxx,
    tOSD_Icon_Animation_R_7_BYTE2_oooox_oooxx,
    tOSD_Icon_Animation_R_8_BYTE2_oooox_oooxx,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_xxooo_xoooo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_xxooo_xoooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_xxooo_xoooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_xxooo_xoooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_xxooo_xoooo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_xxooo_xoooo[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_xxooo_xoooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_xxooo_xoooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_xxooo_xoooo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_xxooo_xoooo,
    tOSD_Icon_Animation_R_2_BYTE2_xxooo_xoooo,
    tOSD_Icon_Animation_R_3_BYTE2_xxooo_xoooo,
    tOSD_Icon_Animation_R_4_BYTE2_xxooo_xoooo,
    tOSD_Icon_Animation_R_5_BYTE2_xxooo_xoooo,
    tOSD_Icon_Animation_R_6_BYTE2_xxooo_xoooo,
    tOSD_Icon_Animation_R_7_BYTE2_xxooo_xoooo,
    tOSD_Icon_Animation_R_8_BYTE2_xxooo_xoooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_xxxoo_xxoox[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_xxxoo_xxoox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_xxxoo_xxoox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_xxxoo_xxoox[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_xxxoo_xxoox[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_xxxoo_xxoox[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_xxxoo_xxoox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_xxxoo_xxoox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_xxxoo_xxoox[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_xxxoo_xxoox,
    tOSD_Icon_Animation_R_2_BYTE2_xxxoo_xxoox,
    tOSD_Icon_Animation_R_3_BYTE2_xxxoo_xxoox,
    tOSD_Icon_Animation_R_4_BYTE2_xxxoo_xxoox,
    tOSD_Icon_Animation_R_5_BYTE2_xxxoo_xxoox,
    tOSD_Icon_Animation_R_6_BYTE2_xxxoo_xxoox,
    tOSD_Icon_Animation_R_7_BYTE2_xxxoo_xxoox,
    tOSD_Icon_Animation_R_8_BYTE2_xxxoo_xxoox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_xxoox_xooxx[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_xxoox_xooxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_xxoox_xooxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_xxoox_xooxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_xxoox_xooxx[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_xxoox_xooxx[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_xxoox_xooxx[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_xxoox_xooxx[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_xxoox_xooxx[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_xxoox_xooxx,
    tOSD_Icon_Animation_R_2_BYTE2_xxoox_xooxx,
    tOSD_Icon_Animation_R_3_BYTE2_xxoox_xooxx,
    tOSD_Icon_Animation_R_4_BYTE2_xxoox_xooxx,
    tOSD_Icon_Animation_R_5_BYTE2_xxoox_xooxx,
    tOSD_Icon_Animation_R_6_BYTE2_xxoox_xooxx,
    tOSD_Icon_Animation_R_7_BYTE2_xxoox_xooxx,
    tOSD_Icon_Animation_R_8_BYTE2_xxoox_xooxx,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_xooxx_ooxxx[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_xooxx_ooxxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_xooxx_ooxxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_xooxx_ooxxx[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_xooxx_ooxxx[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_xooxx_ooxxx[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_xooxx_ooxxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_xooxx_ooxxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_xooxx_ooxxx[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_xooxx_ooxxx,
    tOSD_Icon_Animation_R_2_BYTE2_xooxx_ooxxx,
    tOSD_Icon_Animation_R_3_BYTE2_xooxx_ooxxx,
    tOSD_Icon_Animation_R_4_BYTE2_xooxx_ooxxx,
    tOSD_Icon_Animation_R_5_BYTE2_xooxx_ooxxx,
    tOSD_Icon_Animation_R_6_BYTE2_xooxx_ooxxx,
    tOSD_Icon_Animation_R_7_BYTE2_xooxx_ooxxx,
    tOSD_Icon_Animation_R_8_BYTE2_xooxx_ooxxx,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_ooxxx_oxxxo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_ooxxx_oxxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_ooxxx_oxxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_ooxxx_oxxxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_ooxxx_oxxxo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_ooxxx_oxxxo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_ooxxx_oxxxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_ooxxx_oxxxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_ooxxx_oxxxo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_ooxxx_oxxxo,
    tOSD_Icon_Animation_R_2_BYTE2_ooxxx_oxxxo,
    tOSD_Icon_Animation_R_3_BYTE2_ooxxx_oxxxo,
    tOSD_Icon_Animation_R_4_BYTE2_ooxxx_oxxxo,
    tOSD_Icon_Animation_R_5_BYTE2_ooxxx_oxxxo,
    tOSD_Icon_Animation_R_6_BYTE2_ooxxx_oxxxo,
    tOSD_Icon_Animation_R_7_BYTE2_ooxxx_oxxxo,
    tOSD_Icon_Animation_R_8_BYTE2_ooxxx_oxxxo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_oxxxo_xxxoo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_oxxxo_xxxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_oxxxo_xxxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_oxxxo_xxxoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_oxxxo_xxxoo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_oxxxo_xxxoo[]=
{
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_oxxxo_xxxoo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_oxxxo_xxxoo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_oxxxo_xxxoo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_oxxxo_xxxoo,
    tOSD_Icon_Animation_R_2_BYTE2_oxxxo_xxxoo,
    tOSD_Icon_Animation_R_3_BYTE2_oxxxo_xxxoo,
    tOSD_Icon_Animation_R_4_BYTE2_oxxxo_xxxoo,
    tOSD_Icon_Animation_R_5_BYTE2_oxxxo_xxxoo,
    tOSD_Icon_Animation_R_6_BYTE2_oxxxo_xxxoo,
    tOSD_Icon_Animation_R_7_BYTE2_oxxxo_xxxoo,
    tOSD_Icon_Animation_R_8_BYTE2_oxxxo_xxxoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_oooxx_ooxxx[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_oooxx_ooxxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_oooxx_ooxxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_oooxx_ooxxx[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_oooxx_ooxxx[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_oooxx_ooxxx[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_oooxx_ooxxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_oooxx_ooxxx[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_oooxx_ooxxx[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_oooxx_ooxxx,
    tOSD_Icon_Animation_R_2_BYTE2_oooxx_ooxxx,
    tOSD_Icon_Animation_R_3_BYTE2_oooxx_ooxxx,
    tOSD_Icon_Animation_R_4_BYTE2_oooxx_ooxxx,
    tOSD_Icon_Animation_R_5_BYTE2_oooxx_ooxxx,
    tOSD_Icon_Animation_R_6_BYTE2_oooxx_ooxxx,
    tOSD_Icon_Animation_R_7_BYTE2_oooxx_ooxxx,
    tOSD_Icon_Animation_R_8_BYTE2_oooxx_ooxxx,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_R_1_BYTE2_xxxoo_xxooo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_2_BYTE2_xxxoo_xxooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_3_BYTE2_xxxoo_xxooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_4_BYTE2_xxxoo_xxooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_5_BYTE2_xxxoo_xxooo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Icon_Animation_R_6_BYTE2_xxxoo_xxooo[]=
{
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Icon_Animation_R_7_BYTE2_xxxoo_xxooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

BYTE code tOSD_Icon_Animation_R_8_BYTE2_xxxoo_xxooo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Icon_Animation_R_BYTE2_xxxoo_xxooo[] =
{
    tOSD_Icon_Animation_R_1_BYTE2_xxxoo_xxooo,
    tOSD_Icon_Animation_R_2_BYTE2_xxxoo_xxooo,
    tOSD_Icon_Animation_R_3_BYTE2_xxxoo_xxooo,
    tOSD_Icon_Animation_R_4_BYTE2_xxxoo_xxooo,
    tOSD_Icon_Animation_R_5_BYTE2_xxxoo_xxooo,
    tOSD_Icon_Animation_R_6_BYTE2_xxxoo_xxooo,
    tOSD_Icon_Animation_R_7_BYTE2_xxxoo_xxooo,
    tOSD_Icon_Animation_R_8_BYTE2_xxxoo_xxooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Icon_Animation_Original_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_1_of_5 + 0), (_FONT1_ICON_DYNAMIC_1_of_5 + 1), (_FONT1_ICON_DYNAMIC_1_of_5 + 2), (_FONT1_ICON_DYNAMIC_1_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_2_of_5 + 0), (_FONT1_ICON_DYNAMIC_2_of_5 + 1), (_FONT1_ICON_DYNAMIC_2_of_5 + 2), (_FONT1_ICON_DYNAMIC_2_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_3_of_5 + 0), (_FONT1_ICON_DYNAMIC_3_of_5 + 1), (_FONT1_ICON_DYNAMIC_3_of_5 + 2), (_FONT1_ICON_DYNAMIC_3_of_5 + 3), (_FONT1_ICON_DYNAMIC_3_of_5 + 4), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_4_of_5 + 0), (_FONT1_ICON_DYNAMIC_4_of_5 + 1), (_FONT1_ICON_DYNAMIC_4_of_5 + 2), (_FONT1_ICON_DYNAMIC_4_of_5 + 3), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ICON_DYNAMIC_5_of_5 + 0), (_FONT1_ICON_DYNAMIC_5_of_5 + 1), (_FONT1_ICON_DYNAMIC_5_of_5 + 2), (_FONT1_ICON_DYNAMIC_5_of_5 + 3), _Item_Frame_RT_, ___,
    ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_1_of_5 + 4), (_FONT1_ICON_DYNAMIC_1_of_5 + 5), (_FONT1_ICON_DYNAMIC_1_of_5 + 6), (_FONT1_ICON_DYNAMIC_1_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_2_of_5 + 4), (_FONT1_ICON_DYNAMIC_2_of_5 + 5), (_FONT1_ICON_DYNAMIC_2_of_5 + 6), (_FONT1_ICON_DYNAMIC_2_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_3_of_5 + 5), (_FONT1_ICON_DYNAMIC_3_of_5 + 6), (_FONT1_ICON_DYNAMIC_3_of_5 + 7), (_FONT1_ICON_DYNAMIC_3_of_5 + 8), (_FONT1_ICON_DYNAMIC_3_of_5 + 9), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_4_of_5 + 4), (_FONT1_ICON_DYNAMIC_4_of_5 + 5), (_FONT1_ICON_DYNAMIC_4_of_5 + 6), (_FONT1_ICON_DYNAMIC_4_of_5 + 7), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ICON_DYNAMIC_5_of_5 + 4), (_FONT1_ICON_DYNAMIC_5_of_5 + 5), (_FONT1_ICON_DYNAMIC_5_of_5 + 6), (_FONT1_ICON_DYNAMIC_5_of_5 + 7), _Item_Frame_RB_, ___,
};
*/
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_L_1_BYTE1[]=
{
    _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_,
    _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_,
};

BYTE code tOSD_Item_Animation_L_2_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),
    (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),
};

BYTE code tOSD_Item_Animation_L_3_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7),
    (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16),
};

BYTE code tOSD_Item_Animation_L_4_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6),
    (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15),
};

BYTE code tOSD_Item_Animation_L_5_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5),
    (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14),
};

BYTE code tOSD_Item_Animation_L_6_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4),
    (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13),
};

BYTE code tOSD_Item_Animation_L_7_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3),
    (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12),
};

BYTE code tOSD_Item_Animation_L_8_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2),
    (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11),
};

BYTE code tOSD_Item_Animation_L_9_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1),
    (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10),
};

BYTE code tOSD_Item_Animation_L_10_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0),
    (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9),
};

BYTE code tOSD_Item_Animation_L_11_BYTE1[]=
{
    _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_,
    _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_,
};

BYTE code tOSD_Item_Animation_L_12_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___,
    ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___,
};

code BYTE *tOSD_Item_Animation_L_1to12_BYTE1[] =
{
    tOSD_Item_Animation_L_1_BYTE1,
    tOSD_Item_Animation_L_2_BYTE1,
    tOSD_Item_Animation_L_3_BYTE1,
    tOSD_Item_Animation_L_4_BYTE1,
    tOSD_Item_Animation_L_5_BYTE1,
    tOSD_Item_Animation_L_6_BYTE1,
    tOSD_Item_Animation_L_7_BYTE1,
    tOSD_Item_Animation_L_8_BYTE1,
    tOSD_Item_Animation_L_9_BYTE1,
    tOSD_Item_Animation_L_10_BYTE1,
    tOSD_Item_Animation_L_11_BYTE1,
    tOSD_Item_Animation_L_12_BYTE1,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_L_1_BYTE2_ooo_ooo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Item_Animation_L_2_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_3_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_4_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_5_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_6_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_7_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_8_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_9_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_10_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_11_BYTE2_ooo_ooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Item_Animation_L_12_BYTE2_ooo_ooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Item_Animation_L_1to12_BYTE2_ooo_ooo[] =
{
    tOSD_Item_Animation_L_1_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_2_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_3_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_4_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_5_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_6_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_7_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_8_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_9_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_10_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_11_BYTE2_ooo_ooo,
    tOSD_Item_Animation_L_12_BYTE2_ooo_ooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_L_1_BYTE2_xoo_oxo[]=
{
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Item_Animation_L_2_BYTE2_xoo_oxo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_3_BYTE2_xoo_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_4_BYTE2_xoo_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_5_BYTE2_xoo_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_6_BYTE2_xoo_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_7_BYTE2_xoo_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_8_BYTE2_xoo_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_9_BYTE2_xoo_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_10_BYTE2_xoo_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_11_BYTE2_xoo_oxo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Item_Animation_L_12_BYTE2_xoo_oxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Item_Animation_L_1to12_BYTE2_xoo_oxo[] =
{
    tOSD_Item_Animation_L_1_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_2_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_3_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_4_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_5_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_6_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_7_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_8_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_9_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_10_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_11_BYTE2_xoo_oxo,
    tOSD_Item_Animation_L_12_BYTE2_xoo_oxo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_L_1_BYTE2_oxo_oox[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Item_Animation_L_2_BYTE2_oxo_oox[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_3_BYTE2_oxo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_4_BYTE2_oxo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_5_BYTE2_oxo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_6_BYTE2_oxo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_7_BYTE2_oxo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_8_BYTE2_oxo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_9_BYTE2_oxo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_10_BYTE2_oxo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_11_BYTE2_oxo_oox[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
};

BYTE code tOSD_Item_Animation_L_12_BYTE2_oxo_oox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[] =
{
    tOSD_Item_Animation_L_1_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_2_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_3_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_4_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_5_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_6_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_7_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_8_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_9_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_10_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_11_BYTE2_oxo_oox,
    tOSD_Item_Animation_L_12_BYTE2_oxo_oox,
};


//Abel222
//////////////////////////////////////////////////
/*
BYTE code tOSD_Item_Animation_L_1_BYTE2_oxo_xox[]=
{
   
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    
};

BYTE code tOSD_Item_Animation_L_2_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_3_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_4_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_5_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_6_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_7_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_8_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_9_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_10_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_11_BYTE2_oxo_xox[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf,
};

BYTE code tOSD_Item_Animation_L_12_BYTE2_oxo_xox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};
*/

BYTE code tOSD_Item_Animation_L_1_BYTE2_oxo_xox[]=
{
   
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    
};

BYTE code tOSD_Item_Animation_L_2_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_xf, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_3_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_4_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_5_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_6_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_7_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_8_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_9_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_10_BYTE2_oxo_xox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_11_BYTE2_oxo_xox[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
};

BYTE code tOSD_Item_Animation_L_12_BYTE2_oxo_xox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};


code BYTE *tOSD_Item_Animation_L_1to12_BYTE2_oxo_xox[] =
{
    tOSD_Item_Animation_L_1_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_2_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_3_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_4_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_5_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_6_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_7_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_8_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_9_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_10_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_11_BYTE2_oxo_xox,
    tOSD_Item_Animation_L_12_BYTE2_oxo_xox,
};
//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_L_1_BYTE2_oox_xoo[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Item_Animation_L_2_BYTE2_oox_xoo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_3_BYTE2_oox_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_4_BYTE2_oox_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_5_BYTE2_oox_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_6_BYTE2_oox_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_7_BYTE2_oox_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_8_BYTE2_oox_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_9_BYTE2_oox_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_10_BYTE2_oox_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_11_BYTE2_oox_xoo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Item_Animation_L_12_BYTE2_oox_xoo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Item_Animation_L_1to12_BYTE2_oox_xoo[] =
{
    tOSD_Item_Animation_L_1_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_2_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_3_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_4_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_5_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_6_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_7_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_8_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_9_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_10_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_11_BYTE2_oox_xoo,
    tOSD_Item_Animation_L_12_BYTE2_oox_xoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_L_1_BYTE2_ooo_xoo[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Item_Animation_L_2_BYTE2_ooo_xoo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_3_BYTE2_ooo_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_4_BYTE2_ooo_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_5_BYTE2_ooo_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_6_BYTE2_ooo_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_7_BYTE2_ooo_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_8_BYTE2_ooo_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_9_BYTE2_ooo_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_10_BYTE2_ooo_xoo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Item_Animation_L_11_BYTE2_ooo_xoo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Item_Animation_L_12_BYTE2_ooo_xoo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Item_Animation_L_1to12_BYTE2_ooo_xoo[] =
{
    tOSD_Item_Animation_L_1_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_2_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_3_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_4_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_5_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_6_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_7_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_8_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_9_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_10_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_11_BYTE2_ooo_xoo,
    tOSD_Item_Animation_L_12_BYTE2_ooo_xoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_L_1_BYTE2_oox_ooo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Item_Animation_L_2_BYTE2_oox_ooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_3_BYTE2_oox_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_4_BYTE2_oox_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_5_BYTE2_oox_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_6_BYTE2_oox_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_7_BYTE2_oox_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_8_BYTE2_oox_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_9_BYTE2_oox_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_10_BYTE2_oox_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Item_Animation_L_11_BYTE2_oox_ooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Item_Animation_L_12_BYTE2_oox_ooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Item_Animation_L_1to12_BYTE2_oox_ooo[] =
{
    tOSD_Item_Animation_L_1_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_2_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_3_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_4_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_5_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_6_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_7_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_8_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_9_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_10_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_11_BYTE2_oox_ooo,
    tOSD_Item_Animation_L_12_BYTE2_oox_ooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_R_1_BYTE1[]=
{
    _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_,
    _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_,
};

BYTE code tOSD_Item_Animation_R_2_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0),
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9),
};

BYTE code tOSD_Item_Animation_R_3_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1),
    (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10),
};

BYTE code tOSD_Item_Animation_R_4_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2),
    (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11),
};

BYTE code tOSD_Item_Animation_R_5_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3),
    (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12),
};

BYTE code tOSD_Item_Animation_R_6_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4),
    (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13),
};

BYTE code tOSD_Item_Animation_R_7_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5),
    (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14),
};

BYTE code tOSD_Item_Animation_R_8_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6),
    (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15),
};

BYTE code tOSD_Item_Animation_R_9_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7),
    (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16),
};

BYTE code tOSD_Item_Animation_R_10_BYTE1[]=
{
    (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8),
    (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17),
};

BYTE code tOSD_Item_Animation_R_11_BYTE1[]=
{
    _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_,
    _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_,
};

BYTE code tOSD_Item_Animation_R_12_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 0), (_FONT1_ITEM_DYNAMIC_4_of_3 + 1), (_FONT1_ITEM_DYNAMIC_4_of_3 + 2), (_FONT1_ITEM_DYNAMIC_4_of_3 + 3), (_FONT1_ITEM_DYNAMIC_4_of_3 + 4), (_FONT1_ITEM_DYNAMIC_4_of_3 + 5), (_FONT1_ITEM_DYNAMIC_4_of_3 + 6), (_FONT1_ITEM_DYNAMIC_4_of_3 + 7), (_FONT1_ITEM_DYNAMIC_4_of_3 + 8), _Item_Frame_RT_, ___,
    ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_4_of_3 + 9), (_FONT1_ITEM_DYNAMIC_4_of_3 +10), (_FONT1_ITEM_DYNAMIC_4_of_3 +11), (_FONT1_ITEM_DYNAMIC_4_of_3 +12), (_FONT1_ITEM_DYNAMIC_4_of_3 +13), (_FONT1_ITEM_DYNAMIC_4_of_3 +14), (_FONT1_ITEM_DYNAMIC_4_of_3 +15), (_FONT1_ITEM_DYNAMIC_4_of_3 +16), (_FONT1_ITEM_DYNAMIC_4_of_3 +17), _Item_Frame_RB_, ___,
};

code BYTE *tOSD_Item_Animation_R_1to12_BYTE1[] =
{
    tOSD_Item_Animation_R_1_BYTE1,
    tOSD_Item_Animation_R_2_BYTE1,
    tOSD_Item_Animation_R_3_BYTE1,
    tOSD_Item_Animation_R_4_BYTE1,
    tOSD_Item_Animation_R_5_BYTE1,
    tOSD_Item_Animation_R_6_BYTE1,
    tOSD_Item_Animation_R_7_BYTE1,
    tOSD_Item_Animation_R_8_BYTE1,
    tOSD_Item_Animation_R_9_BYTE1,
    tOSD_Item_Animation_R_10_BYTE1,
    tOSD_Item_Animation_R_11_BYTE1,
    tOSD_Item_Animation_R_12_BYTE1,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_R_1_BYTE2_ooo_ooo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Item_Animation_R_2_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_3_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_4_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_5_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_6_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_7_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_8_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_9_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_10_BYTE2_ooo_ooo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_11_BYTE2_ooo_ooo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Item_Animation_R_12_BYTE2_ooo_ooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Item_Animation_R_1to12_BYTE2_ooo_ooo[] =
{
    tOSD_Item_Animation_R_1_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_2_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_3_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_4_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_5_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_6_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_7_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_8_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_9_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_10_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_11_BYTE2_ooo_ooo,
    tOSD_Item_Animation_R_12_BYTE2_ooo_ooo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_R_1_BYTE2_xoo_oox[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Item_Animation_R_2_BYTE2_xoo_oox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_3_BYTE2_xoo_oox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_4_BYTE2_xoo_oox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_5_BYTE2_xoo_oox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_6_BYTE2_xoo_oox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_7_BYTE2_xoo_oox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_8_BYTE2_xoo_oox[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_9_BYTE2_xoo_oox[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_10_BYTE2_xoo_oox[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_11_BYTE2_xoo_oox[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Item_Animation_R_12_BYTE2_xoo_oox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Item_Animation_R_1to12_BYTE2_xoo_oox[] =
{
    tOSD_Item_Animation_R_1_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_2_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_3_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_4_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_5_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_6_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_7_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_8_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_9_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_10_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_11_BYTE2_xoo_oox,
    tOSD_Item_Animation_R_12_BYTE2_xoo_oox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_R_1_BYTE2_oox_oxo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of,
};

BYTE code tOSD_Item_Animation_R_2_BYTE2_oox_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_3_BYTE2_oox_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_4_BYTE2_oox_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_5_BYTE2_oox_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_6_BYTE2_oox_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_7_BYTE2_oox_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_8_BYTE2_oox_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_9_BYTE2_oox_oxo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_10_BYTE2_oox_oxo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_11_BYTE2_oox_oxo[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Item_Animation_R_12_BYTE2_oox_oxo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Item_Animation_R_1to12_BYTE2_oox_oxo[] =
{
    tOSD_Item_Animation_R_1_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_2_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_3_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_4_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_5_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_6_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_7_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_8_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_9_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_10_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_11_BYTE2_oox_oxo,
    tOSD_Item_Animation_R_12_BYTE2_oox_oxo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_R_1_BYTE2_oxo_xoo[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Item_Animation_R_2_BYTE2_oxo_xoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_3_BYTE2_oxo_xoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_4_BYTE2_oxo_xoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_5_BYTE2_oxo_xoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_6_BYTE2_oxo_xoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_7_BYTE2_oxo_xoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_8_BYTE2_oxo_xoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_9_BYTE2_oxo_xoo[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_10_BYTE2_oxo_xoo[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_11_BYTE2_oxo_xoo[]=
{
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Item_Animation_R_12_BYTE2_oxo_xoo[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[] =
{
    tOSD_Item_Animation_R_1_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_2_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_3_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_4_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_5_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_6_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_7_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_8_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_9_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_10_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_11_BYTE2_oxo_xoo,
    tOSD_Item_Animation_R_12_BYTE2_oxo_xoo,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_R_1_BYTE2_ooo_oox[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Item_Animation_R_2_BYTE2_ooo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_3_BYTE2_ooo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_4_BYTE2_ooo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_5_BYTE2_ooo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_6_BYTE2_ooo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_7_BYTE2_ooo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_8_BYTE2_ooo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_9_BYTE2_ooo_oox[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_10_BYTE2_ooo_oox[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_11_BYTE2_ooo_oox[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Item_Animation_R_12_BYTE2_ooo_oox[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Item_Animation_R_1to12_BYTE2_ooo_oox[] =
{
    tOSD_Item_Animation_R_1_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_2_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_3_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_4_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_5_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_6_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_7_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_8_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_9_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_10_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_11_BYTE2_ooo_oox,
    tOSD_Item_Animation_R_12_BYTE2_ooo_oox,
};

//////////////////////////////////////////////////

BYTE code tOSD_Item_Animation_R_1_BYTE2_xoo_ooo[]=
{
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_Item_Animation_R_2_BYTE2_xoo_ooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_3_BYTE2_xoo_ooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_4_BYTE2_xoo_ooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_5_BYTE2_xoo_ooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_6_BYTE2_xoo_ooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_7_BYTE2_xoo_ooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_8_BYTE2_xoo_ooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_9_BYTE2_xoo_ooo[]=
{
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_10_BYTE2_xoo_ooo[]=
{
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_Item_Animation_R_11_BYTE2_xoo_ooo[]=
{
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_Item_Animation_R_12_BYTE2_xoo_ooo[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_Item_Animation_R_1to12_BYTE2_xoo_ooo[] =
{
    tOSD_Item_Animation_R_1_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_2_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_3_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_4_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_5_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_6_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_7_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_8_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_9_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_10_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_11_BYTE2_xoo_ooo,
    tOSD_Item_Animation_R_12_BYTE2_xoo_ooo,
};

//<-
BYTE code tOSD_Item_Animation_R_1_BYTE2_oxo_xox[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf,
};

BYTE code tOSD_Item_Animation_R_2_BYTE2_oxo_xox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_3_BYTE2_oxo_xox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_4_BYTE2_oxo_xox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_5_BYTE2_oxo_xox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_6_BYTE2_oxo_xox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_7_BYTE2_oxo_xox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_8_BYTE2_oxo_xox[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_9_BYTE2_oxo_xox[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_10_BYTE2_oxo_xox[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_,
};

BYTE code tOSD_Item_Animation_R_11_BYTE2_oxo_xox[]=
{
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
    COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf,
};

BYTE code tOSD_Item_Animation_R_12_BYTE2_oxo_xox[]=
{
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
    COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_xf, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_x_, COLOR_xf, COLOR___,
};

code BYTE *tOSD_Item_Animation_R_1to12_BYTE2_oxo_xox[] =
{
    tOSD_Item_Animation_R_1_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_2_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_3_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_4_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_5_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_6_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_7_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_8_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_9_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_10_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_11_BYTE2_oxo_xox,
    tOSD_Item_Animation_R_12_BYTE2_oxo_xox,
};

//////////////////////////////////////////////////
BYTE code tOSD_Item_Animation_Original_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 0), (_FONT1_ITEM_DYNAMIC_1_of_3 + 1), (_FONT1_ITEM_DYNAMIC_1_of_3 + 2), (_FONT1_ITEM_DYNAMIC_1_of_3 + 3), (_FONT1_ITEM_DYNAMIC_1_of_3 + 4), (_FONT1_ITEM_DYNAMIC_1_of_3 + 5), (_FONT1_ITEM_DYNAMIC_1_of_3 + 6), (_FONT1_ITEM_DYNAMIC_1_of_3 + 7), (_FONT1_ITEM_DYNAMIC_1_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 0), (_FONT1_ITEM_DYNAMIC_2_of_3 + 1), (_FONT1_ITEM_DYNAMIC_2_of_3 + 2), (_FONT1_ITEM_DYNAMIC_2_of_3 + 3), (_FONT1_ITEM_DYNAMIC_2_of_3 + 4), (_FONT1_ITEM_DYNAMIC_2_of_3 + 5), (_FONT1_ITEM_DYNAMIC_2_of_3 + 6), (_FONT1_ITEM_DYNAMIC_2_of_3 + 7), (_FONT1_ITEM_DYNAMIC_2_of_3 + 8), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 0), (_FONT1_ITEM_DYNAMIC_3_of_3 + 1), (_FONT1_ITEM_DYNAMIC_3_of_3 + 2), (_FONT1_ITEM_DYNAMIC_3_of_3 + 3), (_FONT1_ITEM_DYNAMIC_3_of_3 + 4), (_FONT1_ITEM_DYNAMIC_3_of_3 + 5), (_FONT1_ITEM_DYNAMIC_3_of_3 + 6), (_FONT1_ITEM_DYNAMIC_3_of_3 + 7), (_FONT1_ITEM_DYNAMIC_3_of_3 + 8),_Item_Frame_RT_, ___,
    ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_1_of_3 + 9), (_FONT1_ITEM_DYNAMIC_1_of_3 +10), (_FONT1_ITEM_DYNAMIC_1_of_3 +11), (_FONT1_ITEM_DYNAMIC_1_of_3 +12), (_FONT1_ITEM_DYNAMIC_1_of_3 +13), (_FONT1_ITEM_DYNAMIC_1_of_3 +14), (_FONT1_ITEM_DYNAMIC_1_of_3 +15), (_FONT1_ITEM_DYNAMIC_1_of_3 +16), (_FONT1_ITEM_DYNAMIC_1_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_2_of_3 + 9), (_FONT1_ITEM_DYNAMIC_2_of_3 +10), (_FONT1_ITEM_DYNAMIC_2_of_3 +11), (_FONT1_ITEM_DYNAMIC_2_of_3 +12), (_FONT1_ITEM_DYNAMIC_2_of_3 +13), (_FONT1_ITEM_DYNAMIC_2_of_3 +14), (_FONT1_ITEM_DYNAMIC_2_of_3 +15), (_FONT1_ITEM_DYNAMIC_2_of_3 +16), (_FONT1_ITEM_DYNAMIC_2_of_3 +17), _Item_Frame_RB_, ___, _Item_Frame_LB_, (_FONT1_ITEM_DYNAMIC_3_of_3 + 9), (_FONT1_ITEM_DYNAMIC_3_of_3 +10), (_FONT1_ITEM_DYNAMIC_3_of_3 +11), (_FONT1_ITEM_DYNAMIC_3_of_3 +12), (_FONT1_ITEM_DYNAMIC_3_of_3 +13), (_FONT1_ITEM_DYNAMIC_3_of_3 +14), (_FONT1_ITEM_DYNAMIC_3_of_3 +15), (_FONT1_ITEM_DYNAMIC_3_of_3 +16), (_FONT1_ITEM_DYNAMIC_3_of_3 +17),_Item_Frame_RB_, ___,
};

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

BYTE code tOSD_2Item_Animation_L_1_BYTE1[]=
{
     _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_,
     _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_,
};

BYTE code tOSD_2Item_Animation_L_2_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29),
};

BYTE code tOSD_2Item_Animation_L_3_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28),
};

BYTE code tOSD_2Item_Animation_L_4_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27),
};

BYTE code tOSD_2Item_Animation_L_5_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26),
};

BYTE code tOSD_2Item_Animation_L_6_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25),
};

BYTE code tOSD_2Item_Animation_L_7_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24),
};

BYTE code tOSD_2Item_Animation_L_8_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23),
};

BYTE code tOSD_2Item_Animation_L_9_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22),
};

BYTE code tOSD_2Item_Animation_L_10_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21),
};

BYTE code tOSD_2Item_Animation_L_11_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20),
};

BYTE code tOSD_2Item_Animation_L_12_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19),
};

BYTE code tOSD_2Item_Animation_L_13_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18),
};

BYTE code tOSD_2Item_Animation_L_14_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17),
};

BYTE code tOSD_2Item_Animation_L_15_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16),
};

BYTE code tOSD_2Item_Animation_L_16_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0),
    (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15),
};

BYTE code tOSD_2Item_Animation_L_17_BYTE1[]=
{
    _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_,
    _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_,
};

BYTE code tOSD_2Item_Animation_L_18_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___,
    ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___,
};

code BYTE *tOSD_2Item_Animation_L_1to12_BYTE1[] =
{
    tOSD_2Item_Animation_L_1_BYTE1,
    tOSD_2Item_Animation_L_2_BYTE1,
    tOSD_2Item_Animation_L_3_BYTE1,
    tOSD_2Item_Animation_L_4_BYTE1,
    tOSD_2Item_Animation_L_5_BYTE1,
    tOSD_2Item_Animation_L_6_BYTE1,
    tOSD_2Item_Animation_L_7_BYTE1,
    tOSD_2Item_Animation_L_8_BYTE1,
    tOSD_2Item_Animation_L_9_BYTE1,
    tOSD_2Item_Animation_L_10_BYTE1,
    tOSD_2Item_Animation_L_11_BYTE1,
    tOSD_2Item_Animation_L_12_BYTE1,
    tOSD_2Item_Animation_L_13_BYTE1,
    tOSD_2Item_Animation_L_14_BYTE1,
    tOSD_2Item_Animation_L_15_BYTE1,
    tOSD_2Item_Animation_L_16_BYTE1,
    tOSD_2Item_Animation_L_17_BYTE1,
    tOSD_2Item_Animation_L_18_BYTE1,
};

//////////////////////////////////////////////////

BYTE code tOSD_2Item_Animation_L_1_BYTE2[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_2Item_Animation_L_2_BYTE2[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_3_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_4_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_5_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_6_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_7_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_8_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_9_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_10_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_11_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_12_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_13_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_14_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_15_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_16_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_L_17_BYTE2[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_2Item_Animation_L_18_BYTE2[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_2Item_Animation_L_1to12_BYTE2[] =
{
    tOSD_2Item_Animation_L_1_BYTE2,
    tOSD_2Item_Animation_L_2_BYTE2,
    tOSD_2Item_Animation_L_3_BYTE2,
    tOSD_2Item_Animation_L_4_BYTE2,
    tOSD_2Item_Animation_L_5_BYTE2,
    tOSD_2Item_Animation_L_6_BYTE2,
    tOSD_2Item_Animation_L_7_BYTE2,
    tOSD_2Item_Animation_L_8_BYTE2,
    tOSD_2Item_Animation_L_9_BYTE2,
    tOSD_2Item_Animation_L_10_BYTE2,
    tOSD_2Item_Animation_L_11_BYTE2,
    tOSD_2Item_Animation_L_12_BYTE2,
    tOSD_2Item_Animation_L_13_BYTE2,
    tOSD_2Item_Animation_L_14_BYTE2,
    tOSD_2Item_Animation_L_15_BYTE2,
    tOSD_2Item_Animation_L_16_BYTE2,
    tOSD_2Item_Animation_L_17_BYTE2,
    tOSD_2Item_Animation_L_18_BYTE2,
};

//////////////////////////////////////////////////

BYTE code tOSD_2Item_Animation_R_1_BYTE1[]=
{
    _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_,
    _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_,
};

BYTE code tOSD_2Item_Animation_R_2_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15),
};

BYTE code tOSD_2Item_Animation_R_3_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16),
};

BYTE code tOSD_2Item_Animation_R_4_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17),
};

BYTE code tOSD_2Item_Animation_R_5_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18),
};

BYTE code tOSD_2Item_Animation_R_6_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19),
};

BYTE code tOSD_2Item_Animation_R_7_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20),
};

BYTE code tOSD_2Item_Animation_R_8_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21),
};

BYTE code tOSD_2Item_Animation_R_9_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22),
};

BYTE code tOSD_2Item_Animation_R_10_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23),
};

BYTE code tOSD_2Item_Animation_R_11_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24),
};

BYTE code tOSD_2Item_Animation_R_12_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25),
};

BYTE code tOSD_2Item_Animation_R_13_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26),
};

BYTE code tOSD_2Item_Animation_R_14_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27),
};

BYTE code tOSD_2Item_Animation_R_15_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28),
};

BYTE code tOSD_2Item_Animation_R_16_BYTE1[]=
{
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14),
    (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29),
};

BYTE code tOSD_2Item_Animation_R_17_BYTE1[]=
{
    _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_,
    _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_,
};

BYTE code tOSD_2Item_Animation_R_18_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___,
    ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_3_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___,
};

code BYTE *tOSD_2Item_Animation_R_1to12_BYTE1[] =
{
    tOSD_2Item_Animation_R_1_BYTE1,
    tOSD_2Item_Animation_R_2_BYTE1,
    tOSD_2Item_Animation_R_3_BYTE1,
    tOSD_2Item_Animation_R_4_BYTE1,
    tOSD_2Item_Animation_R_5_BYTE1,
    tOSD_2Item_Animation_R_6_BYTE1,
    tOSD_2Item_Animation_R_7_BYTE1,
    tOSD_2Item_Animation_R_8_BYTE1,
    tOSD_2Item_Animation_R_9_BYTE1,
    tOSD_2Item_Animation_R_10_BYTE1,
    tOSD_2Item_Animation_R_11_BYTE1,
    tOSD_2Item_Animation_R_12_BYTE1,
    tOSD_2Item_Animation_R_13_BYTE1,
    tOSD_2Item_Animation_R_14_BYTE1,
    tOSD_2Item_Animation_R_15_BYTE1,
    tOSD_2Item_Animation_R_16_BYTE1,
    tOSD_2Item_Animation_R_17_BYTE1,
    tOSD_2Item_Animation_R_18_BYTE1,
};

//////////////////////////////////////////////////

BYTE code tOSD_2Item_Animation_R_1_BYTE2[]=
{
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
    COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of,
};

BYTE code tOSD_2Item_Animation_R_2_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_3_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_4_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_5_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_6_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_7_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_8_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_9_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_10_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_11_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_12_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_13_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_14_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_15_BYTE2[]=
{
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_16_BYTE2[]=
{
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
    COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_,
};

BYTE code tOSD_2Item_Animation_R_17_BYTE2[]=
{
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
    COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of,
};

BYTE code tOSD_2Item_Animation_R_18_BYTE2[]=
{
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
    COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___, COLOR_of, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_o_, COLOR_of, COLOR___,
};

code BYTE *tOSD_2Item_Animation_R_1to12_BYTE2[] =
{
    tOSD_2Item_Animation_R_1_BYTE2,
    tOSD_2Item_Animation_R_2_BYTE2,
    tOSD_2Item_Animation_R_3_BYTE2,
    tOSD_2Item_Animation_R_4_BYTE2,
    tOSD_2Item_Animation_R_5_BYTE2,
    tOSD_2Item_Animation_R_6_BYTE2,
    tOSD_2Item_Animation_R_7_BYTE2,
    tOSD_2Item_Animation_R_8_BYTE2,
    tOSD_2Item_Animation_R_9_BYTE2,
    tOSD_2Item_Animation_R_10_BYTE2,
    tOSD_2Item_Animation_R_11_BYTE2,
    tOSD_2Item_Animation_R_12_BYTE2,
    tOSD_2Item_Animation_R_13_BYTE2,
    tOSD_2Item_Animation_R_14_BYTE2,
    tOSD_2Item_Animation_R_15_BYTE2,
    tOSD_2Item_Animation_R_16_BYTE2,
    tOSD_2Item_Animation_R_17_BYTE2,
    tOSD_2Item_Animation_R_18_BYTE2,
};

//////////////////////////////////////////////////

BYTE code tOSD_2Item_Animation_Original_BYTE1[]=
{
    ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +14), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 0), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 1), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 2), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 3), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 4), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 5), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 6), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 7), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 8), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 + 9), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +10), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +11), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +12), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +13), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +14), _Item_Frame_RT_, ___,
    ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_1_of_2 +29), _Item_Frame_RT_, ___, _Item_Frame_LT_, (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +15), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +16), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +17), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +18), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +19), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +20), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +21), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +22), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +23), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +24), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +25), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +26), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +27), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +28), (_FONT1_256_512_ITEM_DYNAMIC_2_of_2 +29), _Item_Frame_RT_, ___,
};

//////////////////////////////////////////////////
void OsdAnimationItemAnimation1(BYTE ucOsdState)
{
    BYTE i;
    BYTE ucTmpL , ucTmpR;
    BYTE ucTmpKey = GET_KEYMESSAGE();
    BYTE ucOsdStateMax , ucOsdStateMin;
    
    switch(ucOsdState)
    {
        //Level 2
        //Sub Item
		case _SUB_BRI :
		case _SUB_CON :
#if(_USER_DCR_FUNCTION == _ON)		
        case _SUB_DCR :
#endif
        case _SUB_IMAGE_POS_H :
        case _SUB_IMAGE_POS_V :

        case _SUB_AUTO_SETUP :
        case _SUB_MANUAL :

        case _SUB_COLOR :
#if(_INPUT_PORT_MAX > 0x01)
        case _SUB_INPUT_SIGNAL :
#endif
#if(_ASPECT_RATIO_SUPPORT == _ON)
        case _SUB_SCALING :
#endif
#if(_OD_OSD_SUPPORT == _ON)
        case _SUB_OVER_DRIVE :
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
        case _SUB_LOW_BLUE_LIGHT:
#endif

        case _SUB_INFORMATION :
#if(_LANGUAGE_TYPE != _1_LAN)
        case _SUB_MENU_LANGUAGE :
#endif
        case _SUB_MENU_POSITION :
        case _SUB_FACTORY_DEFAULT :
        case _SUB_ACCESSIBILITY :
#if (_DP_SUPPORT == _ON)
        case _SUB_DP_SELECT :
#endif

#if(_USER_DCR_FUNCTION == _ON)
            if((ucOsdState >= _SUB_BRI) && (ucOsdState <= _SUB_DCR))
            {
                ucOsdStateMin = _SUB_BRI;
                ucOsdStateMax = _SUB_DCR;
            }
#else
			if((ucOsdState >= _SUB_BRI) && (ucOsdState <= _SUB_CON))
			{
				ucOsdStateMin = _SUB_BRI;
				ucOsdStateMax = _SUB_CON;
			}
#endif
            else if((ucOsdState >= _SUB_IMAGE_POS_H) && (ucOsdState <= _SUB_IMAGE_POS_V))
            {
                ucOsdStateMin = _SUB_IMAGE_POS_H;
                ucOsdStateMax = _SUB_IMAGE_POS_V;
            }
            else if((ucOsdState >= _SUB_AUTO_SETUP) && (ucOsdState <= _SUB_MANUAL))
            {
                ucOsdStateMin = _SUB_AUTO_SETUP;
                ucOsdStateMax = _SUB_MANUAL;
            }
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)//rinny
            else if((ucOsdState >= _SUB_COLOR) && (ucOsdState <= _SUB_LOW_BLUE_LIGHT))
            {
                ucOsdStateMin = _SUB_COLOR;
                ucOsdStateMax = _SUB_LOW_BLUE_LIGHT;
            }

#else
  #if(_OD_OSD_SUPPORT == _ON)
            else if((ucOsdState >= _SUB_COLOR) && (ucOsdState <= _SUB_OVER_DRIVE))
            {
                ucOsdStateMin = _SUB_COLOR;
                ucOsdStateMax = _SUB_OVER_DRIVE;
            }
  #else
    #if(_ASPECT_RATIO_SUPPORT == _ON)
            else if((ucOsdState >= _SUB_COLOR) && (ucOsdState <= _SUB_SCALING))
            {
                ucOsdStateMin = _SUB_COLOR;
                ucOsdStateMax = _SUB_SCALING;
            }
   #else
			else if((ucOsdState >= _SUB_COLOR) && (ucOsdState <= _SUB_INPUT_SIGNAL))
			{
				ucOsdStateMin = _SUB_COLOR;
				ucOsdStateMax = _SUB_INPUT_SIGNAL;
			}
   #endif
 #endif
#endif
#if(_DP_SUPPORT == _ON)
            else if((_SUB_INFORMATION <= ucOsdState) && (ucOsdState <= _SUB_DP_SELECT))
            {
                ucOsdStateMin = _SUB_INFORMATION;
                ucOsdStateMax = _SUB_DP_SELECT;
            }
#else
            else if((ucOsdState >= _SUB_INFORMATION) && (ucOsdState <= _SUB_ACCESSIBILITY))
            {
                ucOsdStateMin = _SUB_INFORMATION;
                ucOsdStateMax = _SUB_ACCESSIBILITY;
            }
#endif

#if(_USER_DCR_FUNCTION == _ON)
            if((ucOsdState == _SUB_IMAGE_POS_H) || (ucOsdState == _SUB_IMAGE_POS_V) 
				|| (ucOsdState == _SUB_AUTO_SETUP) || (ucOsdState == _SUB_MANUAL)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _OFF))
				|| (ucOsdState == _SUB_COLOR) || (ucOsdState == _SUB_INPUT_SIGNAL)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
				|| (ucOsdState == _SUB_COLOR) || (ucOsdState == _SUB_OVER_DRIVE)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF))
                #if _LOW_BLUE_LIGHT_FUNCTION
                #else
				|| (ucOsdState == _SUB_COLOR) || (ucOsdState == _SUB_SCALING)
                #endif
#endif
				)
#else
			if((ucOsdState == _SUB_BRI) || (ucOsdState == _SUB_CON)
				|| (ucOsdState == _SUB_IMAGE_POS_H) || (ucOsdState == _SUB_IMAGE_POS_V)
				|| (ucOsdState == _SUB_AUTO_SETUP) || (ucOsdState == _SUB_MANUAL)
#if((_INPUT_PORT_MAX > 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF)&&(_OD_OSD_SUPPORT == _OFF))
				|| (ucOsdState == _SUB_COLOR) || (ucOsdState == _SUB_INPUT_SIGNAL)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _OFF) && (_OD_OSD_SUPPORT == _ON))
				|| (ucOsdState == _SUB_COLOR) || (ucOsdState == _SUB_OVER_DRIVE)
#elif((_INPUT_PORT_MAX <= 0x01) && (_ASPECT_RATIO_SUPPORT == _ON) && (_OD_OSD_SUPPORT == _OFF))
				|| (ucOsdState == _SUB_COLOR) || (ucOsdState == _SUB_SCALING)
#endif
				)
#endif
            {
                OsdDisplayItemDraw(_ITEM_2_1, _ITEM_SELECT, GET_OSD_STATE());

                ucTmpR = OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ITEM_DYNAMIC_1_of_2);
                OsdFontLoadItem(ucTmpR, _FONT1_ITEM_DYNAMIC_2_of_2);
                OsdFontLoadItem(((GET_KEYMESSAGE() ==  _LEFT_KEY_MESSAGE) ? (ucTmpR) : (GET_OSD_STATE())), _FONT1_ITEM_DYNAMIC_3_of_2);
                SET_OSD_STATE(OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON));

                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE1);
                ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_Original_BYTE1, 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                
                if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
                {
                    for(i = 0 ; i < (15 + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_L_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_L_1to12_BYTE2[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }
                else
                {
                    for(i = 0 ; i < (15 + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_R_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_R_1to12_BYTE2[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }
                
                ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);

                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ITEM_2_START_1_of_2);
                OsdFontLoadItem(ucTmpR, _FONT1_ITEM_2_START_2_of_2);
                
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(2), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_1_of_2));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(20), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_2_of_2));
                
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(2 - 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
                OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(2 + 15), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
                OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(2), WIDTH(15), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_FOCUS_BG));

                OsdDisplayItemDraw(_ITEM_2_1, _ITEM_FOCUS, GET_OSD_STATE());
            }
            else
            {
                OsdDisplayItemDraw(_ITEM_2_2, _ITEM_SELECT, GET_OSD_STATE());

#if(_INPUT_PORT_MAX <= 0x01)

                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                //取左邊osd state
                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                ucTmpL = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                   
                //取右邊osd state    
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);                  
                SET_KEYMESSAGE(ucTmpKey);

                //顯示目前的ICON
                OsdFontLoadItem(ucTmpL, _FONT1_ITEM_DYNAMIC_1_of_3);
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ITEM_DYNAMIC_2_of_3);
                OsdFontLoadItem(ucTmpR, _FONT1_ITEM_DYNAMIC_3_of_3);

                //取欲動作的ICON 
                if((GET_OSD_STATE() >= _SUB_COLOR) && (GET_OSD_STATE() <= _SUB_LOW_BLUE_LIGHT))
                {
                    if((GET_OSD_DCR_STATUS() == _ON) && (UserCheckAspectRatioFunction() == _TRUE))
                    {
                        if(GET_OSD_STATE() == _SUB_COLOR)
                        {
                            SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT);
                        }
                        else
                        {
                            if(GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT)
                            {
                                SET_OSD_STATE(_SUB_SCALING);
                            }
                            else
                            {
                                SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT);
                            }
                        }
                    }
                    else if((GET_OSD_DCR_STATUS() == _ON) && (UserCheckAspectRatioFunction() == _FALSE))
                    {
                        SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT);
                    }
                    else if((GET_OSD_DCR_STATUS() == _OFF) && (UserCheckAspectRatioFunction() == _FALSE))
                    {
                        if((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF))
                        {
                            if(GET_OSD_STATE() == _SUB_SCALING)
                            {
                                SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT);
                            }
                            else
                            {
                                if(GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT)
                                {
                                    SET_OSD_STATE(_SUB_COLOR);
                                }
                                else
                                {
                                    SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT);
                                }
                            }
                        }
                        else
                        {
                            SET_OSD_STATE(_SUB_LOW_BLUE_LIGHT);
                        }
                    }
                    else
                    {
                        SET_OSD_STATE(OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON));
                    }
                }
                else
                {
                    SET_OSD_STATE(OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON));
                }
                i = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(i, _FONT1_ITEM_DYNAMIC_4_of_3);
#else
                do
                {
                    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                    //取左邊osd state
                    SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                    ucTmpL = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                       
                    //取右邊osd state    
                    SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                    ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);                  
                    SET_KEYMESSAGE(ucTmpKey);
                    
                    //顯示目前的ICON
                    OsdFontLoadItem(ucTmpL, _FONT1_ITEM_DYNAMIC_1_of_3);
                    OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ITEM_DYNAMIC_2_of_3);
                    OsdFontLoadItem(ucTmpR, _FONT1_ITEM_DYNAMIC_3_of_3);
                    
                    //取欲動作的ICON 
                    SET_OSD_STATE(OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON));
                    i = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                    OsdFontLoadItem(i, _FONT1_ITEM_DYNAMIC_4_of_3);
                }while((((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON))    && (GET_OSD_STATE() == _SUB_COLOR)) 
#if (_DP_SUPPORT == _ON)                
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
					|| ((SysSourceGetInputPort() != _D0_INPUT_PORT) && (GET_OSD_STATE() == _SUB_DP_SELECT)) 
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
					|| ((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_DP_SELECT)) 
#endif
#endif  
#if(_ASPECT_RATIO_SUPPORT == _ON)
                     || ((UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_SCALING)) 
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)	
					|| ((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON) && (GET_OSD_STATE() == _SUB_DCR))
					|| ((GET_OSD_DCR_STATUS() == _ON) && (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT)) 
#endif
					);
#endif//#if(_INPUT_PORT_MAX <= 0x01)
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE1);
                ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_Original_BYTE1, 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);

                if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
                {
                    for(i = 0 ; i < (_ITEM_WIDTH + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE2);


#if(_ASPECT_RATIO_SUPPORT == _ON)
	#if(_INPUT_PORT_MAX > 0x01)
					//DCR ON(Color)& Scaling反灰處理
					if( (((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON))&&(UserCheckAspectRatioFunction() == _FALSE)) && (GET_OSD_STATE() == _SUB_INPUT_SIGNAL))	   
					{
						//ScalerDebugMessage("L_GY_1", 0x00);
						ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
					}
		#if(_OD_OSD_SUPPORT == _ON)//Robert Wang 20141103
					else if(((GET_OSD_DCR_STATUS() == _ON)&&(UserCheckAspectRatioFunction() == _FALSE)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))	  
					{
						//ScalerDebugMessage("L_GY_2", 0x01);
						 ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
					}
					else if(((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)&&(UserCheckAspectRatioFunction() == _FALSE)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))	  
					{
						//ScalerDebugMessage("L_GY_2", 0x01);
						 ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
					}
		#endif
					else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))						  
					{
						ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_xoo_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
					}
	#else	
		#if(_OD_OSD_SUPPORT == _ON)//Robert Wang 20141103
						if((((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON))&&(UserCheckAspectRatioFunction() == _FALSE)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))	  
						{
							//ScalerDebugMessage("L_GY_2", 0x01);
							 ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
						else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))
		#else
						if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))						  
		#endif
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_xoo_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
	#endif
#else
	#if(_OD_OSD_SUPPORT == _ON)//Robert Wang 20141103
                        if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))     
                        {
                            //ScalerDebugMessage("L_GY_2", 0x01);
                             ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }
						else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))						  
	#else	
						if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))
	#endif
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_xoo_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
#endif     

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)	
						else if((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON) && (GET_OSD_STATE() == _SUB_BRI))	  
						{
							//ScalerDebugMessage("L_GY_2", 0x01);
							 ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
						else if((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON) && (GET_OSD_STATE() == _SUB_CON))	  
						{
							//ScalerDebugMessage("L_GY_2", 0x01);
							 ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
#endif
						//DCR ON(Color)反灰處理 
#if(_INPUT_PORT_MAX > 0x01)
                        else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_INPUT_SIGNAL))                          
                        {
#if(_OD_OSD_SUPPORT == _ON)
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_ooo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
#else
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
#endif
                        }
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)

                        else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_SCALING))
                        {
                            #if((_OD_OSD_SUPPORT == _ON)&&(_INPUT_PORT_MAX == 0x01))
                                ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                            #elif((_OD_OSD_SUPPORT == _ON)||(_LOW_BLUE_LIGHT_FUNCTION == _ON))
                                ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                            #endif

                        }
#endif

	#if((_OD_OSD_SUPPORT == _ON) && (_INPUT_PORT_MAX == 0x01))
                        else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (UserCheckAspectRatioFunction() == _TRUE) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))
                        {
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    	}
	#elif(_OD_OSD_SUPPORT == _ON)
		#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
						else if(((GET_OSD_DCR_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
						else if((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)&&(GET_OSD_STATE() == _SUB_OVER_DRIVE))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
		#else
	
                        else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
		#endif
	#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)						
                        //Scaling反灰處理
                        else if((UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_COLOR))
                        {
                            //ScalerDebugMessage("L_43_1", 0x01);
	#if(_OD_OSD_SUPPORT == _ON)
		#if(_INPUT_PORT_MAX == 0x01)
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
		#else
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
		#endif
	#else
        #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)    
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
        #else 
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
	    #endif
	#endif
                        }
						
	#if(_INPUT_PORT_MAX > 0x01)
                        else if((UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_INPUT_SIGNAL))                          
                        {
                            //ScalerDebugMessage("L_43_2", 0x02);
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        } 
	#endif
	
	#if(_OD_OSD_SUPPORT == _ON)
                        else if((UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))                         
                        {
                            //ScalerDebugMessage("L_43_3", 0x03);
			#if(_INPUT_PORT_MAX == 0x01)
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
			#else
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_ooo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
			#endif
                        }                        
	#endif
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)						

                        else if(((GET_OSD_DCR_STATUS() == _OFF) &&(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF)) && (UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT))
                        {
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oox_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }   
						else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (UserCheckAspectRatioFunction() == _TRUE) && (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
						else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT))
						{ 
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
#endif
                        

#if (_DP_SUPPORT == _ON)   //DP Select反灰處理
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
						else if((SysSourceGetInputPort() != _D0_INPUT_PORT) && (GET_OSD_STATE() == _SUB_DP_SELECT))
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
						else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_DP_SELECT))
#endif
                        {                            
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_xoo_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                        else if((SysSourceGetInputPort() != _D0_INPUT_PORT) && (GET_OSD_STATE() == _SUB_INFORMATION))
#else
						else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_INFORMATION))
#endif
                        {                            
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_ooo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        } 
                        //else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_MENU_LANGUAGE))
                        //{
                        //     ScalerDebugMessage("L_LAN",0x03);
                        //     ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_xoo_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        //} 
                        //else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_MENU_POSITION))
                        //{
                        //     ScalerDebugMessage("L_Postion",0x04);
                        //     ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_xoo_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        //} 
                        //else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_FACTORY_DEFAULT))
                        //{
                        //     ScalerDebugMessage("L_Factory",0x05);
                        //     ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_xoo_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        //} 
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                        else if((SysSourceGetInputPort() != _D0_INPUT_PORT) && (GET_OSD_STATE() == _SUB_ACCESSIBILITY))
#else
						else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_ACCESSIBILITY))
#endif
                        {                            
                             ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_oxo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }
#endif
                        else
                        {
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_ooo_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }
                    }
                }
                else
                {
                    for(i = 0 ; i < (_ITEM_WIDTH + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_2_ROW,0), _OSD_BYTE2);

#if(_ASPECT_RATIO_SUPPORT == _ON)
	#if(_INPUT_PORT_MAX > 0x01)
						 //DCR ON(Color)& Scaling反灰處理
	                    if( (((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON))&&(UserCheckAspectRatioFunction() == _FALSE)) && (GET_OSD_STATE() == _SUB_INPUT_SIGNAL))     
	                    {
	                        //ScalerDebugMessage("L_GY_1", 0x00);
	                         ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
	                    }
		#if(_OD_OSD_SUPPORT == _ON)//Robert Wang 20141103
	                    else if( ((GET_OSD_DCR_STATUS() == _ON)&&(UserCheckAspectRatioFunction() == _FALSE)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))     
	                    {
	                        //ScalerDebugMessage("L_GY_2", 0x01);
	                         ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
	                    }
	                    else if( ((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)&&(UserCheckAspectRatioFunction() == _FALSE)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))     
	                    {
	                        //ScalerDebugMessage("L_GY_2", 0x01);
	                         ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
	                    }
		#endif
	                    //DCR ON(Color)反灰處理
	                    else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))                           
	                    {
	                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oox_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
	                    }
	#else
		#if(_OD_OSD_SUPPORT == _ON)//Robert Wang 20141103
					if( (((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON))&&(UserCheckAspectRatioFunction() == _FALSE)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))	  
					{
						//ScalerDebugMessage("L_GY_2", 0x01);
						 ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
					}
					//DCR ON(Color)反灰處理
					else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))
		#else
					//DCR ON(Color)反灰處理
					if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))							
		#endif
					{
						ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oox_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
					}
	#endif
#else
	#if(_OD_OSD_SUPPORT == _ON)//Robert Wang 20141103
	                    if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))     
	                    {
	                        //ScalerDebugMessage("L_GY_2", 0x01);
	                         ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
	                    }
	                    //DCR ON(Color)反灰處理
	                    else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))  
	#else
						//DCR ON(Color)反灰處理
						if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_COLOR))							
	#endif
	                    {
	                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oox_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
	                    }
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)	
						else if((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON) && (GET_OSD_STATE() == _SUB_BRI))	  
						{
							//ScalerDebugMessage("L_GY_2", 0x01);
							 ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
						else if((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON) && (GET_OSD_STATE() == _SUB_CON))	  
						{
							//ScalerDebugMessage("L_GY_2", 0x01);
							 ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_xoo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
#endif

#if(_INPUT_PORT_MAX > 0x01)
						 //DCR ON(Color)& Scaling反灰處理
                        else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_INPUT_SIGNAL))
                        {
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)												
                        else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_SCALING))
                        {
		                #if((_OD_OSD_SUPPORT == _ON)&&(_INPUT_PORT_MAX == 0x01))
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
		                #elif((_OD_OSD_SUPPORT == _ON)||(_LOW_BLUE_LIGHT_FUNCTION == _ON))
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        #endif
                        }
#endif

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)

                        else if(((GET_OSD_DCR_STATUS() == _OFF) &&(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF)) && (UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT))
                        {
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }                        
						else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (UserCheckAspectRatioFunction() == _TRUE) && (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_ooo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
						else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_LOW_BLUE_LIGHT))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)												
		#if((_OD_OSD_SUPPORT == _ON)&&(_INPUT_PORT_MAX == 0x01)) 
						else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (UserCheckAspectRatioFunction() == _TRUE) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_xoo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
		#elif(_OD_OSD_SUPPORT == _ON)
			#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
						else if((GET_OSD_DCR_STATUS() == _ON) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_xoo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
						else if((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_ooo_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
			#else	
						else if(((GET_OSD_DCR_STATUS() == _ON) ||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))
						{
							ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_xoo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
						}
			#endif
		#endif

                        //Scaling反灰處理
                        else if((UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_COLOR))
                        {
                            //ScalerDebugMessage("R_43_1", 0x01);
	#if(_OD_OSD_SUPPORT == _ON)
			#if(_INPUT_PORT_MAX == 0x01)
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_xoo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
			#else
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_xoo_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
			#endif
	#else
            #if(_LOW_BLUE_LIGHT_FUNCTION == _ON)						
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_xoo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
			#else
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
			#endif
	#endif
                        }  
	#if(_INPUT_PORT_MAX > 0x01)
                        else if((UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_INPUT_SIGNAL))                          
                        {
                            //ScalerDebugMessage("R_43_2", 0x02);
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_ooo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }
	#endif
	
	#if(_OD_OSD_SUPPORT == _ON)                        
                        else if((UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _SUB_OVER_DRIVE))                          
                        {
                            //ScalerDebugMessage("R_43_2", 0x02);
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }   
	#endif         

#endif

#if (_DP_SUPPORT == _ON)

                        //DP Select反灰處理
                        //else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_DP_SELECT))
                        //{                             
                        //    ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_xoo_oxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        //}
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                        else if((SysSourceGetInputPort() != _D0_INPUT_PORT) && (GET_OSD_STATE() == _SUB_INFORMATION))
#else
						else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_INFORMATION))
#endif
                        {      
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_oxo_xoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);                        
                        } 
#if(_LANGUAGE_TYPE != _1_LAN)
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
						else if((SysSourceGetInputPort() != _D0_INPUT_PORT) && (GET_OSD_STATE() == _SUB_MENU_LANGUAGE))
#else
						else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_MENU_LANGUAGE))
#endif
                        {     
                             ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_xoo_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }   
#endif
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                        else if((SysSourceGetInputPort() != _D0_INPUT_PORT) && (GET_OSD_STATE() == _SUB_ACCESSIBILITY))
#else
                        else if((SysSourceGetInputPort() != _D1_INPUT_PORT) && (GET_OSD_STATE() == _SUB_ACCESSIBILITY))
#endif
                        {    
                        
                             ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_ooo_oox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }
#endif
                        else
                        {
                        	
                            ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_ooo_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        }
                    }
                }

                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                ucTmpL = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);

                OsdFontLoadItem(ucTmpL, _FONT1_ITEM_2_START_1_of_3);
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ITEM_2_START_2_of_3);
                OsdFontLoadItem(ucTmpR, _FONT1_ITEM_2_START_3_of_3);

                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_1), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_1_of_3));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_2), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_2_of_3));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_2_START_3_of_3));

                OsdDisplayItemDraw(_ITEM_2_2, _ITEM_FOCUS, GET_OSD_STATE());
//                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
//                OsdDisplayItemColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_2), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
//                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
//                OsdDisplayDrawFocusFrame(_ITEM_2_ROW);
            }
            
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
					if(GET_OSD_DCR_STATUS() ==_OFF)
					{
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3 - 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_SEL_BG));
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3 + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_SEL_BG));
					}
					else
					{
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3 - 1), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_UNSEL_BG));
					OsdFunc1bitColor(ROW(_ITEM_2_ROW), COL(_ITEM_COL_3 + _ITEM_WIDTH), WIDTH(1), HEIGHT(1), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_UNSEL_BG));
					}
				}
			}
#endif
            break;

        //Level 3
#if(_USER_DCR_FUNCTION == _ON)       
        case _SUB_DCR_ON :
        case _SUB_DCR_OFF:
#endif
        case _SUB_MANUAL_CLOCK :
        case _SUB_MANUAL_PHASE:

        case _SUB_COLOR_PRESET_MODE :
        case _SUB_COLOR_CUSTOM:
			
#if(_INPUT_PORT_MAX == 0x02)
        case _SUB_INPUT_ANALOG :
        case _SUB_INPUT_DIGITAL1:        
		case _SUB_INPUT_DIGITAL0:

#elif(_INPUT_PORT_MAX == 0x03)
        case _SUB_INPUT_ANALOG :
        case _SUB_INPUT_DIGITAL0:
        case _SUB_INPUT_DIGITAL1:

#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
        case _SUB_SCALING_FULL_SCREEN :
        case _SUB_SCALING_ORIGINAL_AR:
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
        case _SUB_LOW_BLUE_LIGHT_ON :
        case _SUB_LOW_BLUE_LIGHT_OFF :
#endif

#if(_OD_OSD_SUPPORT == _ON)
#if(_OD_MULTI_SELECT == _ON)
		case _SUB_OD_OFF:
		case _SUB_OD_NORMAL:
		case _SUB_OD_EXTREME:
#else
        case _SUB_OD_ON :
        case _SUB_OD_OFF :
#endif
#endif

#if(_LANGUAGE_TYPE != _1_LAN)
        case _SUB_LAN_ENGLISH :
        case _SUB_LAN_FRENCH :
        case _SUB_LAN_ITALIAN :
        case _SUB_LAN_CHINESE_S :
        case _SUB_LAN_SPANISH :
        case _SUB_LAN_JAPAN :
        case _SUB_LAN_GERMAN :
        case _SUB_LAN_RUSSIAN :
#endif
        case _SUB_POS_DEFAULT :
        case _SUB_POS_CUSTOM :

        case _SUB_FACTORY_CANCEL :
        case _SUB_FACTORY_RESET :

        case _SUB_ACCESS_RATE :
        case _SUB_ACCESS_TIMEOUT :

#if (_DP_SUPPORT == _ON)
        case _SUB_DP_SL_11 :
        case _SUB_DP_SL_12 :
#endif

#if(_USER_DCR_FUNCTION == _ON)
            if((ucOsdState >= _SUB_DCR_ON) && (ucOsdState <= _SUB_DCR_OFF))
            {
                ucOsdStateMin = _SUB_DCR_ON;
                ucOsdStateMax = _SUB_DCR_OFF;
            }
            else if((ucOsdState >= _SUB_MANUAL_CLOCK) && (ucOsdState <= _SUB_MANUAL_PHASE))
            {
                ucOsdStateMin = _SUB_MANUAL_CLOCK;
                ucOsdStateMax = _SUB_MANUAL_PHASE;
            }
#else
			if((ucOsdState >= _SUB_MANUAL_CLOCK) && (ucOsdState <= _SUB_MANUAL_PHASE))
			{
				ucOsdStateMin = _SUB_MANUAL_CLOCK;
				ucOsdStateMax = _SUB_MANUAL_PHASE;
			}
#endif
            else if((ucOsdState >= _SUB_COLOR_PRESET_MODE) && (ucOsdState <= _SUB_COLOR_CUSTOM))
            {
                ucOsdStateMin = _SUB_COLOR_PRESET_MODE;
                ucOsdStateMax = _SUB_COLOR_CUSTOM;
            }
#if(_INPUT_PORT_MAX > 0x01)
            else if((ucOsdState >= _SUB_INPUT_ANALOG) && (ucOsdState <= _SUB_INPUT_DIGITAL1))
            {
                ucOsdStateMin = _SUB_INPUT_ANALOG;
                ucOsdStateMax = _SUB_INPUT_DIGITAL1;
            }
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
			
            else if((ucOsdState >= _SUB_SCALING_FULL_SCREEN) && (ucOsdState <= _SUB_SCALING_ORIGINAL_AR))
            {
                ucOsdStateMin = _SUB_SCALING_FULL_SCREEN;
                ucOsdStateMax = _SUB_SCALING_ORIGINAL_AR;
            }
#endif

#if(_OD_OSD_SUPPORT == _ON)
#if(_OD_MULTI_SELECT == _ON)
			else if((ucOsdState >= _SUB_OD_OFF) && (ucOsdState <= _SUB_OD_EXTREME))
			{
				ucOsdStateMin = _SUB_OD_OFF;
				ucOsdStateMax = _SUB_OD_EXTREME;
			}
#else
            else if((ucOsdState >= _SUB_OD_ON) && (ucOsdState <= _SUB_OD_OFF))
            {
                ucOsdStateMin = _SUB_OD_ON;
                ucOsdStateMax = _SUB_OD_OFF;
            }
#endif
#endif
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
            else if((ucOsdState >= _SUB_LOW_BLUE_LIGHT_ON) && (ucOsdState <= _SUB_LOW_BLUE_LIGHT_OFF))
            {
                ucOsdStateMin = _SUB_LOW_BLUE_LIGHT_ON;
                ucOsdStateMax = _SUB_LOW_BLUE_LIGHT_OFF;
            }
#endif

#if(_LANGUAGE_TYPE != _1_LAN)
            else if((ucOsdState >= _SUB_LAN_ENGLISH) && (ucOsdState <= _SUB_LAN_RUSSIAN))
            {
                ucOsdStateMin = _SUB_LAN_ENGLISH;
                ucOsdStateMax = _SUB_LAN_RUSSIAN;
            }
#endif
            else if((ucOsdState >= _SUB_POS_DEFAULT) && (ucOsdState <= _SUB_POS_CUSTOM))
            {
                ucOsdStateMin = _SUB_POS_DEFAULT;
                ucOsdStateMax = _SUB_POS_CUSTOM;
            }
            else if((ucOsdState >= _SUB_FACTORY_CANCEL) && (ucOsdState <= _SUB_FACTORY_RESET))
            {
                ucOsdStateMin = _SUB_FACTORY_CANCEL;
                ucOsdStateMax = _SUB_FACTORY_RESET;
            }
            else if((ucOsdState >= _SUB_ACCESS_RATE) && (ucOsdState <= _SUB_ACCESS_TIMEOUT))
            {
                ucOsdStateMin = _SUB_ACCESS_RATE;
                ucOsdStateMax = _SUB_ACCESS_TIMEOUT;
            }
#if (_DP_SUPPORT == _ON)
            else if((_SUB_DP_SL_11 <= ucOsdState) && (ucOsdState <= _SUB_DP_SL_12))
            {
                ucOsdStateMin = _SUB_DP_SL_11;
                ucOsdStateMax = _SUB_DP_SL_12;
            }
#endif

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
#if(_DP_SUPPORT == _ON)
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
                OsdDisplayItemDraw(_ITEM_3_1, _ITEM_SELECT, GET_OSD_STATE());

                ucTmpR = OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_256_512_ITEM_DYNAMIC_1_of_2);
                OsdFontLoadItem(ucTmpR, _FONT1_256_512_ITEM_DYNAMIC_2_of_2);
                OsdFontLoadItem(((GET_KEYMESSAGE() ==  _LEFT_KEY_MESSAGE) ? (ucTmpR) : (GET_OSD_STATE())), _FONT1_256_512_ITEM_DYNAMIC_3_of_2);
                SET_OSD_STATE(OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON));

                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE1);
                ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_Original_BYTE1, 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                
                if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
                {
                    for(i = 0 ; i < (15 + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_L_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_L_1to12_BYTE2[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }
                else
                {
                    for(i = 0 ; i < (15 + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_R_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_R_1to12_BYTE2[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }
                
                ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);

                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ITEM_3_START_1_of_2);
                OsdFontLoadItem(ucTmpR, _FONT1_ITEM_3_START_2_of_2);
                
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(2), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_1_of_2));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(20), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_2_of_2));
                
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(2 - 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
                OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(2 + 15), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
                OsdFunc1bitColor(ROW(_ITEM_3_ROW), COL(2), WIDTH(15), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_FOCUS_BG));

                OsdDisplayItemDraw(_ITEM_3_1, _ITEM_FOCUS, GET_OSD_STATE());
            }
            else
            {
                OsdDisplayItemDraw(_ITEM_3_2, _ITEM_SELECT, GET_OSD_STATE());
//                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
//                OsdDisplayClearFocusFrame(_ITEM_3_ROW);

                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                ucTmpL = OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON);
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                ucTmpR = OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON);
                SET_KEYMESSAGE(ucTmpKey);

                OsdFontLoadItem(ucTmpL, _FONT1_256_512_ITEM_DYNAMIC_1_of_3);
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_256_512_ITEM_DYNAMIC_2_of_3);
                OsdFontLoadItem(ucTmpR, _FONT1_256_512_ITEM_DYNAMIC_3_of_3);
                SET_OSD_STATE(OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON));
                i = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(i, _FONT1_256_512_ITEM_DYNAMIC_4_of_3);

                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE1);
                ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_Original_BYTE1, 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);

                if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
                {
                    for(i = 0 ; i < (_ITEM_WIDTH + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_ooo_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }
                else
                {
                    for(i = 0 ; i < (_ITEM_WIDTH + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_3_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_ooo_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }

                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                ucTmpL = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);

                OsdFontLoadItem(ucTmpL, _FONT1_ITEM_3_START_1_of_3);
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ITEM_3_START_2_of_3);
                OsdFontLoadItem(ucTmpR, _FONT1_ITEM_3_START_3_of_3);

                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_1), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_1_of_3));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_2_of_3));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_3_ROW), COL(_ITEM_COL_3), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_3_START_3_of_3));

                OsdDisplayItemDraw(_ITEM_3_2, _ITEM_FOCUS, GET_OSD_STATE());
//                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
//                OsdDisplayItemColor(ROW(_ITEM_3_ROW), COL(_ITEM_COL_2), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
//                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
//                OsdDisplayDrawFocusFrame(_ITEM_3_ROW);
            }
            break;

        //Level 4
        case _SUB_NEUTRAL :
        case _SUB_BLUISH :
        case _SUB_REDDISH :
        case _SUB_sRGB :

        case _SUB_CUSTOM_R :
        case _SUB_CUSTOM_G :
        case _SUB_CUSTOM_B :

        case _SUB_POS_CUST_H :
        case _SUB_POS_CUST_V :

        case _SUB_REPEAT_OFF :
        case _SUB_REPEAT_DEFAULT :
        case _SUB_REPEAT_SLOW :

            if((ucOsdState >= _SUB_NEUTRAL) && (ucOsdState <= _SUB_sRGB))
            {
                ucOsdStateMin = _SUB_NEUTRAL;
                ucOsdStateMax = _SUB_sRGB;
            }
            else if((ucOsdState >= _SUB_CUSTOM_R) && (ucOsdState <= _SUB_CUSTOM_B))
            {
                ucOsdStateMin = _SUB_CUSTOM_R;
                ucOsdStateMax = _SUB_CUSTOM_B;
            }
            else if((ucOsdState >= _SUB_POS_CUST_H) && (ucOsdState <= _SUB_POS_CUST_V))
            {
                ucOsdStateMin = _SUB_POS_CUST_H;
                ucOsdStateMax = _SUB_POS_CUST_V;
            }
            else if((ucOsdState >= _SUB_REPEAT_OFF) && (ucOsdState <= _SUB_REPEAT_SLOW))
            {
                ucOsdStateMin = _SUB_REPEAT_OFF;
                ucOsdStateMax = _SUB_REPEAT_SLOW;
            }

            if((GET_OSD_STATE() == _SUB_POS_CUST_H) || (GET_OSD_STATE() == _SUB_POS_CUST_V))
            {
                OsdDisplayItemDraw(_ITEM_4_1, _ITEM_SELECT, GET_OSD_STATE());

                ucTmpR = OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_256_512_ITEM_DYNAMIC_1_of_2);
                OsdFontLoadItem(ucTmpR, _FONT1_256_512_ITEM_DYNAMIC_2_of_2);
                OsdFontLoadItem(((GET_KEYMESSAGE() ==  _LEFT_KEY_MESSAGE) ? (ucTmpR) : (GET_OSD_STATE())), _FONT1_256_512_ITEM_DYNAMIC_3_of_2);
                SET_OSD_STATE(OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON));

                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE1);
                ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_Original_BYTE1, 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                
                if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
                {
                    for(i = 0 ; i < (15 + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_L_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_L_1to12_BYTE2[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }
                else
                {
                    for(i = 0 ; i < (15 + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_R_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_2Item_Animation_R_1to12_BYTE2[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }
                
                ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);

                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ITEM_4_START_1_of_2);
                OsdFontLoadItem(ucTmpR, _FONT1_ITEM_4_START_2_of_2);
                
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(2), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_1_of_2));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(20), WIDTH(15), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_2_of_2));
                
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(2 - 1), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
                OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(2 + 15), WIDTH(1), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
                OsdFunc1bitColor(ROW(_ITEM_4_ROW), COL(2), WIDTH(15), HEIGHT(_ITEM_HEIGHT), FGCOLOR(_CP_WHITE), BGCOLOR(_CP_ITEM_FOCUS_BG));

                OsdDisplayItemDraw(_ITEM_4_1, _ITEM_FOCUS, GET_OSD_STATE());
            }
            else
            {
                OsdDisplayItemDraw(_ITEM_4_2, _ITEM_SELECT, GET_OSD_STATE());
//                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
//                OsdDisplayClearFocusFrame(_ITEM_4_ROW);
    
                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                ucTmpL = OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON);
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                ucTmpR = OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON);
                SET_KEYMESSAGE(ucTmpKey);
    
                OsdFontLoadItem(ucTmpL, _FONT1_256_512_ITEM_DYNAMIC_1_of_3);
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_256_512_ITEM_DYNAMIC_2_of_3);
                OsdFontLoadItem(ucTmpR, _FONT1_256_512_ITEM_DYNAMIC_3_of_3);
                SET_OSD_STATE(OsdDisplayDetOverRange(ucOsdState, ucOsdStateMax, ucOsdStateMin, _ON));
                i = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(i, _FONT1_256_512_ITEM_DYNAMIC_4_of_3);
    
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE1);
                ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_Original_BYTE1, 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
    
                if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
                {
                    for(i = 0 ; i < (_ITEM_WIDTH + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_L_1to12_BYTE2_ooo_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }
                else
                {
                    for(i = 0 ; i < (_ITEM_WIDTH + 3) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_4_ROW,0), _OSD_BYTE2);
                        ScalerOsdBurstWriteDataPort(tOSD_Item_Animation_R_1to12_BYTE2_ooo_ooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                    }
                }
    
                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                ucTmpL = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
    
                OsdFontLoadItem(ucTmpL, _FONT1_ITEM_4_START_1_of_3);
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ITEM_4_START_2_of_3);
                OsdFontLoadItem(ucTmpR, _FONT1_ITEM_4_START_3_of_3);
    
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_1), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_1_of_3));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_2_of_3));
                OsdFunc1bitItemApplyChar(ROW(_ITEM_4_ROW), COL(_ITEM_COL_3), WIDTH(_ITEM_WIDTH), HEIGHT(_ITEM_HEIGHT), CHAR(_FONT1_ITEM_4_START_3_of_3));
    
                OsdDisplayItemDraw(_ITEM_4_2, _ITEM_FOCUS, GET_OSD_STATE());
//                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
//                OsdDisplayItemColor(ROW(_ITEM_4_ROW), COL(_ITEM_COL_2), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
//                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
//                OsdDisplayDrawFocusFrame(_ITEM_4_ROW);

            }
            break;

        default:
            break;
    }
}

#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
