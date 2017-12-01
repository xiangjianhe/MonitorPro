//################################################################################
//# Copyright Statement: CVTE
//# Copyright (C) 2014 Guangzhou Shiyuan Electronics Co.,Ltd. All rights reserved.
//#      ____________        _______________  ___________
//#     / / ________ \      / / _____   ____|| |  _______|
//#    / / /      \ \ \    / / /   | | |     | | |
//#   | | |        \ \ \  / / /    | | |     | | |_______
//#   | | |         \ \ \/ / /     | | |     | |  _______|
//#   | | |          \ \ \/ /      | | |     | | |
//#    \ \ \______    \ \  /       | | |     | | |_______
//#     \_\_______|    \_\/        |_|_|     |_|_________|
//#
//################################################################################
//# descript:
//#     --> board parameters config
//#     -->
//#######################
//# filename: CVT_BOARD_CONFIG.h
//# author  : liaozurui
//# date    : 2014-12-25
//# version : V1.0.0
//# note    :
//################################################################################

#ifndef __GLOBAL_PRODUCT_DEFINE_H__
#define __GLOBAL_PRODUCT_DEFINE_H__

#define BD_MERGE(a)                                     (a)
#define BOARD_TYPE(x)                                   (x>>8)

////////////////////////////////////////////////////////////
// SOURCE DEFINE
////////////////////////////////////////////////////////////
#define DEF_SOURCE_VGA                                  1
#define DEF_SOURCE_DVI1                                 2
#define DEF_SOURCE_DVI2                                 3
#define DEF_SOURCE_DVI3                                 4
#define DEF_SOURCE_HDMI1                                5
#define DEF_SOURCE_HDMI2                                6
#define DEF_SOURCE_HDMI3                                7
#define DEF_SOURCE_DP                                   8
#define DEF_SOURCE_AUTO                                 9

//*******************MainBoardType Define****************************
// 
//#include "Pcb_List.h"

// product of board type
// name rule: base-board-name+"_SUB_" + board_sub_id
//**************************************************************************//
//  
//  
//**************************************************************************//

//**************************************************************************//
//  
//  
//**************************************************************************//
#define ID_BD_CVT_MP_RT2270C_PA553_1A_A1                BD_MERGE(BD_CVT_RL6230_MP_RT2270C_PA553_1A)
#define ID_BD_CVT_MP_RT2281C_PA553_1A_A1                BD_MERGE(BD_CVT_RL6336_MP_RT2281C_PA553_1A1D)

//--------------------------BD END--------------------------------------------

//------------------------------KEYPAD ADC START---------------------------//
#define KEYPAD_ADC_CVT_DEFAULT                          1

//--------------------------------KEYPAD ADC END---------------------------//

//------------------------------KEYPAD CONVERT START---------------------------//
#define KEYPAD_CONVERT_CVT_DEFAULT                      1
#define KEYPAD_CONVERT_AOC_DEFAULT                      2

//--------------------------------KEYPAD CONVERT END---------------------------//

//********************LogoType Define*******************************
#define ID_LOGO_NONE                                    0
#define ID_LOGO_AOC                                     1
#define ID_LOGO_ACER                                    2                 

//===============================================

//------------------------------------------
//  VOLUME TYPE
//------------------------------------------
#define VOLUME_TABLE_CS8563S_CVT_DEFAULT                1

//*****************************************************************
////////////////////////////////////////////////////////////
// LANG DEFINE
////////////////////////////////////////////////////////////
#endif
