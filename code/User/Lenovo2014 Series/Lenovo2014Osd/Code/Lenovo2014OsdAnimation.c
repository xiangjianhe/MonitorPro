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
void OsdAnimationItemAnimation(BYTE ucOsdState);
void OsdAnimationItemAnimation2(BYTE ucOsdState);

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

//////////////////////////////////////////////////
void OsdAnimationItemAnimation(BYTE ucOsdState)
{
    switch(ucOsdState)
    {
        //Level 1
        //Main Item
		case _MAIN_BRI_CON_DCR :
#if(_VGA_SUPPORT == _ON)
		case _MAIN_IMAGE_POSITION :
        case _MAIN_IMAGE_SETUP :
#endif
        case _MAIN_IMAGE_PROPERTIES :
        case _MAIN_OPTIONS :
        case _MAIN_FACTORY :
			OsdAnimationItemAnimation2(ucOsdState);
			break;
		default:
			OsdAnimationItemAnimation1(ucOsdState);
			break;
    }
}

//////////////////////////////////////////////////
void OsdAnimationItemAnimation2(BYTE ucOsdState)
{
    BYTE i;
    BYTE ucTmpL , ucTmpR;
    BYTE ucTmpKey = GET_KEYMESSAGE();
    BYTE ucOsdStateMax , ucOsdStateMin;
    
    switch(ucOsdState)
    {
        //Level 1
        //Main Item
		case _MAIN_BRI_CON_DCR :
		case _MAIN_IMAGE_POSITION :
        case _MAIN_IMAGE_SETUP :
        case _MAIN_IMAGE_PROPERTIES :
        case _MAIN_OPTIONS :
        case _MAIN_FACTORY :
            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
            OsdDisplayClearFocusFrame(_ITEM_1_ROW);
            OsdDisplayIconColor(ROW(_ITEM_1_ROW), COL(_ICON_COL_3), FGCOLOR(_CP_ITEM_SEL_BG), BGCOLOR(_CP_MENU_BG));

            //20140929 Abel Modify
            if(GET_FACTORY_MODE() == _ON)
            {
                ucOsdStateMin = _MAIN_BRI_CON_DCR;
                ucOsdStateMax = _MAIN_FACTORY;
            }
            else
            {
                ucOsdStateMin = _MAIN_BRI_CON_DCR;
                ucOsdStateMax = _MAIN_OPTIONS;    
            }

            do
            {
                // Dynamic 2
                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                ucTmpL = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(ucTmpL, _FONT1_ICON_DYNAMIC_2_of_5);
                // Dynamic 1
                ucTmpL = OsdDisplayDetOverRange(ucTmpL, ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(ucTmpL, _FONT1_ICON_DYNAMIC_1_of_5);
                // Dynamic 3
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ICON_DYNAMIC_3_of_5);
                // Dynamic 4
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(ucTmpR, _FONT1_ICON_DYNAMIC_4_of_5);
                // Dynamic 5
                ucTmpR = OsdDisplayDetOverRange(ucTmpR, ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(ucTmpR, _FONT1_ICON_DYNAMIC_5_of_5);
                        
                SET_KEYMESSAGE(ucTmpKey);
                SET_OSD_STATE(OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON));
                // Dynamic 6
                i = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                i = OsdDisplayDetOverRange(i, ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(i, _FONT1_ICON_DYNAMIC_6_of_5);
            }while(((GET_COLOR_TEMP_TYPE() == _CT_SRGB) && (GET_OSD_STATE() == _MAIN_BRI_CON_DCR))
            		||((SysSourceGetInputPort() != _A0_INPUT_PORT) && (GET_OSD_STATE() == _MAIN_IMAGE_POSITION))
            		||((SysSourceGetInputPort() != _A0_INPUT_PORT) && (GET_OSD_STATE() == _MAIN_IMAGE_SETUP))
#if((_INPUT_PORT_MAX <= 0x01) &&(_OD_OSD_SUPPORT == _OFF) && (_ASPECT_RATIO_SUPPORT == _ON))
					|| ((GET_COLOR_TEMP_TYPE() != _CT_SRGB) && (GET_OSD_DCR_STATUS() == _ON) && (UserCheckAspectRatioFunction() == _FALSE) && (GET_OSD_STATE() == _MAIN_IMAGE_PROPERTIES))
#endif
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
                     ||((GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON) && (GET_OSD_STATE() == _MAIN_BRI_CON_DCR)) 
 #endif  
                  );
 
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_1_ROW,0), _OSD_BYTE1);
                ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_Original_BYTE1, 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);

                // _FONT1_ICON_1_START_2_of_5
                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                ucTmpL = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(ucTmpL, _FONT1_ICON_1_START_2_of_5);
                // _FONT1_ICON_1_START_1_of_5
                ucTmpL = OsdDisplayDetOverRange(ucTmpL, ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(ucTmpL, _FONT1_ICON_1_START_1_of_5);
                // _FONT1_ICON_1_START_3_of_5
                OsdFontLoadItem(GET_OSD_STATE(), _FONT1_ICON_1_START_3_of_5);
                // _FONT1_ICON_1_START_4_of_5
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                ucTmpR = OsdDisplayDetOverRange(GET_OSD_STATE(), ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(ucTmpR, _FONT1_ICON_1_START_4_of_5);
                // _FONT1_ICON_1_START_5_of_5
                ucTmpR = OsdDisplayDetOverRange(ucTmpR, ucOsdStateMax, ucOsdStateMin, _ON);
                OsdFontLoadItem(ucTmpR, _FONT1_ICON_1_START_5_of_5);

                SET_KEYMESSAGE(ucTmpKey);

                if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
                {
                    for(i = 0 ; i < (_ICON_WIDTH + 4) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_1_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_1_ROW,0), _OSD_BYTE2);
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
                        if(((GET_COLOR_TEMP_TYPE() != _CT_SRGB)&&(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF)) && (SysSourceGetInputPort() == _A0_INPUT_PORT))
#else                            
                        if(((GET_COLOR_TEMP_TYPE() != _CT_SRGB)) && (SysSourceGetInputPort() == _A0_INPUT_PORT))
#endif
                        {
#if((_INPUT_PORT_MAX <= 0x01) &&(_OD_OSD_SUPPORT == _OFF) && (_ASPECT_RATIO_SUPPORT == _ON))
							if((GET_OSD_DCR_STATUS() == _ON) && (UserCheckAspectRatioFunction() == _FALSE))
							{
                            	switch(GET_OSD_STATE())
								{
									case _MAIN_BRI_CON_DCR :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooox_ooooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooox_xoooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
									case _MAIN_IMAGE_POSITION :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooxo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooxo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
	
									case _MAIN_IMAGE_SETUP :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooxoo_oooxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooxoo_oooxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
	
									case _MAIN_IMAGE_PROPERTIES :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooox_ooooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooxo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
	
									case _MAIN_OPTIONS :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xoooo_oxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xoooo_oxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
	
									case _MAIN_FACTORY :
										ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooooo_xoooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										break;
	
									default:
										break;
								}
							}
							else
							{
								ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooooo_ooooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
							}
	#else
                            ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooooo_ooooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
	#endif
                        }
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
                        else if(((GET_COLOR_TEMP_TYPE() == _CT_SRGB)||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (SysSourceGetInputPort() == _A0_INPUT_PORT))
#else                            
                        else if(((GET_COLOR_TEMP_TYPE() == _CT_SRGB)) && (SysSourceGetInputPort() == _A0_INPUT_PORT))
#endif

                        {
                            switch(GET_OSD_STATE())
                            {
                                case _MAIN_BRI_CON_DCR :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oxooo_ooxoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                case _MAIN_IMAGE_POSITION :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xoooo_oxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                case _MAIN_IMAGE_SETUP :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooooo_xoooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooox_xoooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_IMAGE_PROPERTIES :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooox_ooooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooxo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_OPTIONS :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooxo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooxoo_oooxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_FACTORY :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooxoo_oooxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                default:
                                    break;
                            }
                        }
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
                        else if(((GET_COLOR_TEMP_TYPE() != _CT_SRGB)&&(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF)) && (SysSourceGetInputPort() != _A0_INPUT_PORT))
#else                            
                        else if(((GET_COLOR_TEMP_TYPE() != _CT_SRGB)) && (SysSourceGetInputPort() != _A0_INPUT_PORT))
#endif
                        
                        {
                            switch(GET_OSD_STATE())
                            {
                                case _MAIN_BRI_CON_DCR :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooxxo_oooxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                case _MAIN_IMAGE_POSITION :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oxxoo_ooxxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                case _MAIN_IMAGE_SETUP :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xxooo_oxxoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                case _MAIN_IMAGE_PROPERTIES :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xoooo_xxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xooox_xxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_OPTIONS :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooox_xoooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooxx_xooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_FACTORY :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooxx_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                default:
                                    break;
                            }
                        }
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
                        else if(((GET_COLOR_TEMP_TYPE() == _CT_SRGB)||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (SysSourceGetInputPort() != _A0_INPUT_PORT))
#else                            
                        else if(((GET_COLOR_TEMP_TYPE() == _CT_SRGB)) && (SysSourceGetInputPort() != _A0_INPUT_PORT))
#endif

                        {
                            switch(GET_OSD_STATE())
                            {
                                case _MAIN_BRI_CON_DCR :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oxxxo_ooxxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                case _MAIN_IMAGE_POSITION :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xxxoo_oxxxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                case _MAIN_IMAGE_SETUP :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xxooo_xxxoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xxoox_xxxoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_IMAGE_PROPERTIES :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xooox_xxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_xooxx_xxoox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_OPTIONS :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_oooxx_xooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooxxx_xooxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_FACTORY :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_L_BYTE2_ooxxx_oooxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                default:
                                    break;
                            }
                        }
                    }
                }
                else
                {
                    for(i = 0 ; i < (_ICON_WIDTH + 4) ; i += 1)
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_1_ROW,0), _OSD_BYTE1);
                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE1[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                        ScalerOsdSramAddressSet(OsdFuncCalcStartAddress(_ITEM_1_ROW,0), _OSD_BYTE2);
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
                        if(((GET_COLOR_TEMP_TYPE() != _CT_SRGB)&&(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF)) && (SysSourceGetInputPort() == _A0_INPUT_PORT))
#else                            
                        if(((GET_COLOR_TEMP_TYPE() != _CT_SRGB)) && (SysSourceGetInputPort() == _A0_INPUT_PORT))
#endif

                        {
#if((_INPUT_PORT_MAX <= 0x01) &&(_OD_OSD_SUPPORT == _OFF) && (_ASPECT_RATIO_SUPPORT == _ON))
							if((GET_OSD_DCR_STATUS() == _ON) && (UserCheckAspectRatioFunction() == _FALSE))
							{
                            	switch(GET_OSD_STATE())
								{
									case _MAIN_BRI_CON_DCR :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xoooo_ooooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oxooo_xoooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
	
									case _MAIN_IMAGE_POSITION :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_ooooo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xoooo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
	
									case _MAIN_IMAGE_SETUP :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooox_oooxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooox_oooxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
	
									case _MAIN_IMAGE_PROPERTIES :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooxo_ooxoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooxo_ooxoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
	
									case _MAIN_OPTIONS :
										if(GET_FACTORY_MODE() == _ON)
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_ooxoo_oxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										else
										{
											ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_ooxoo_oxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										}
										break;
	
									case _MAIN_FACTORY :
										ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oxooo_xoooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
										break;
	
									default:
										break;
								}
							}
							else
							{
								ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_ooooo_ooooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
							}
	#else                       
                            ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_ooooo_ooooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
	#endif
						}
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
                        else if(((GET_COLOR_TEMP_TYPE() == _CT_SRGB)||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (SysSourceGetInputPort() == _A0_INPUT_PORT))
#else                            
                        else if(((GET_COLOR_TEMP_TYPE() == _CT_SRGB)) && (SysSourceGetInputPort() == _A0_INPUT_PORT))
#endif
                        {
                            switch(GET_OSD_STATE())
                            {
                                case _MAIN_BRI_CON_DCR :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooxo_ooxoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;
                        
                                case _MAIN_IMAGE_POSITION :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_ooxoo_oxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;
                        
                                case _MAIN_IMAGE_SETUP :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oxooo_xoooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;
                        
                                case _MAIN_IMAGE_PROPERTIES :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xoooo_ooooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xoooo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;
                        
                                case _MAIN_OPTIONS :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_ooooo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooox_oooxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_FACTORY :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooox_oooxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                default:
                                    break;
                            }
                        }
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
                        else if(((GET_COLOR_TEMP_TYPE() != _CT_SRGB)&&(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _OFF)) && (SysSourceGetInputPort() != _A0_INPUT_PORT))
#else                            
                        else if(((GET_COLOR_TEMP_TYPE() != _CT_SRGB)) && (SysSourceGetInputPort() != _A0_INPUT_PORT))
#endif
                            
                        {
                            switch(GET_OSD_STATE())
                            {
                                case _MAIN_BRI_CON_DCR :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooox_oooxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xooox_oooxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;
                        
                                case _MAIN_IMAGE_POSITION :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooxx_ooxxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;
                        
                                case _MAIN_IMAGE_SETUP :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_ooxxo_oxxoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;
                        
                                case _MAIN_IMAGE_PROPERTIES :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oxxoo_xxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;
                        
                                case _MAIN_OPTIONS :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xxooo_xoooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xxooo_xooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_FACTORY :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xoooo_oooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                 default:
                                    break;
                            }
                        }
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION  == _OFF))
                        else if(((GET_COLOR_TEMP_TYPE() == _CT_SRGB)||(GET_OSD_LOW_BLUE_LIGHT_STATUS() == _ON)) && (SysSourceGetInputPort() != _A0_INPUT_PORT))
#else                            
                        else if(((GET_COLOR_TEMP_TYPE() == _CT_SRGB)) && (SysSourceGetInputPort() != _A0_INPUT_PORT))
#endif

                        {
                            switch(GET_OSD_STATE())
                            {
                                case _MAIN_BRI_CON_DCR :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oooxx_ooxxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xooxx_ooxxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;
                        
                                case _MAIN_IMAGE_POSITION :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_ooxxx_oxxxo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;
                        
                                case _MAIN_IMAGE_SETUP :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_oxxxo_xxxoo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;
                        
                                case _MAIN_IMAGE_PROPERTIES :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xxxoo_xxooo[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xxxoo_xxoox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;
                        
                                case _MAIN_OPTIONS :
                                    if(GET_FACTORY_MODE() == _ON)
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xxooo_xooox[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    else
                                    {
                                        ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xxoox_xooxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    }
                                    break;

                                case _MAIN_FACTORY :
                                    ScalerOsdBurstWriteDataPort(tOSD_Icon_Animation_R_BYTE2_xooox_oooxx[i], 74, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
                                    break;

                                default:
                                    break;
                            }
                        }
                    }
            }
            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
            OsdDisplayIconColor(ROW(_ITEM_1_ROW), COL(_ICON_COL_3), FGCOLOR(_CP_ITEM_FOCUS_BG), BGCOLOR(_CP_MENU_BG));
            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
            OsdDisplayDrawFocusFrame(_ITEM_1_ROW);
            break;

        default:
            break;
    }
}

#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
