
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
// ID Code      : NoneInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "NoneNVRamOsd.h"

#if(_OSD_TYPE == _NONE_OSD)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Definitions of Hue Saturation Range
//--------------------------------------------------
#define _DEFAULT_HUE                                _HUE_CENTER
#define _DEFAULT_SATURATION                         _SATURATION_CENTER

//--------------------------------------------------
// Macro of Key Scan Start Flag
//--------------------------------------------------
#define GET_KEYSCANSTART()                          ((bit)(g_stOsdInfo.ucOsdKeyControl & _BIT1))
#define SET_KEYSCANSTART()                          (g_stOsdInfo.ucOsdKeyControl |= _BIT1)
#define CLR_KEYSCANSTART()                          (g_stOsdInfo.ucOsdKeyControl &= ~_BIT1)

//--------------------------------------------------
// Macro of Key Scan Ready Flag
//--------------------------------------------------
#define GET_KEYSCANREADY()                          ((bit)(g_stOsdInfo.ucOsdKeyControl & _BIT0))
#define SET_KEYSCANREADY()                          (g_stOsdInfo.ucOsdKeyControl |= _BIT0)
#define CLR_KEYSCANREADY()                          (g_stOsdInfo.ucOsdKeyControl &= ~_BIT0)

//--------------------------------------------------
// Macro of Key Repeat Start
//--------------------------------------------------
#define GET_KEYREPEATSTART()                        (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT2)
#define SET_KEYREPEATSTART()                        (g_stOsdInfo.ucOsdKeyControl |= _BIT2)
#define CLR_KEYREPEATSTART()                        (g_stOsdInfo.ucOsdKeyControl &= ~_BIT2)

//--------------------------------------------------
// Macro of Key Repeat Function Enable
// If you want to use repeat function, please set this flag. If not, please clear it.
//--------------------------------------------------
#define GET_KEYREPEATENABLE()                       (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT3)
#define SET_KEYREPEATENABLE()                       (g_stOsdInfo.ucOsdKeyControl |= _BIT3)
#define CLR_KEYREPEATENABLE()                       (g_stOsdInfo.ucOsdKeyControl &= ~_BIT3)

//--------------------------------------------------
// Macro of Key Message
//--------------------------------------------------
#define GET_KEYMESSAGE()                            (g_stOsdInfo.ucOsdKeyMessage)
#define SET_KEYMESSAGE(x)                           (g_stOsdInfo.ucOsdKeyMessage = (x))

//--------------------------------------------------
// Definitions of Key Message
//--------------------------------------------------
#define _MENU_KEY_MESSAGE                           0
#define _RIGHT_KEY_MESSAGE                          1
#define _LEFT_KEY_MESSAGE                           2
#define _EXIT_KEY_MESSAGE                           3
#define _5_KEY_MESSAGE                              4
#define _6_KEY_MESSAGE                              5
#define _7_KEY_MESSAGE                              6
#define _HOLD_KEY_MESSAGE                           7
#define _NONE_KEY_MESSAGE                           8

#define _KEY_AMOUNT                                 4

//--------------------------------------------------
// Definitions of LED indicction
//--------------------------------------------------
typedef enum
{
    _LED_ALL_OFF = _LED_SYSTEM_END,          
}EnumUserLedIndication;

//--------------------------------------------------
// MACRO for Osd Status
//--------------------------------------------------
#define GET_OSD_STATE()                             (g_stOsdInfo.ucOsdState)
#define SET_OSD_STATE(x)                            (g_stOsdInfo.ucOsdState = (x))

//--------------------------------------------------
// MACRO for Osd Evevt Message
//--------------------------------------------------
#define GET_OSD_EVENT_MESSAGE()                     (g_stOsdInfo.ucOsdEventMsg)
#define SET_OSD_EVENT_MESSAGE(x)                    (g_stOsdInfo.ucOsdEventMsg = (x))

//==========================================================================================================
// Macro of NVRam User Data
//==========================================================================================================

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE ucOsdState;
    BYTE ucOsdEventMsg;
    BYTE ucOsdKeyMessage;
    BYTE ucOsdKeyControl;

}StructOsdInfo;

typedef enum
{
    _MENU_NONE, 
    _MAIN_MENU_STATE_END,    
};

//--------------------------------------------------
// Definitions of Language
//--------------------------------------------------

enum OSDEvenMassage
{
    _OSDEVENT_NONE_MSG = 0,
    _OSDEVENT_DO_AUTO_CONFIG_MSG,    
};

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#ifndef __NONE_OSD__
extern StructOsdInfo g_stOsdInfo;
#endif

//----------------------------------------------------------------------------------------
// Extern Tables from RTDOsdACTIONFLOW.c
//----------------------------------------------------------------------------------------
#ifndef __NONE_OSDACTIONFLOW__
extern code void (*OperationTable[][4])(void);
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
//----------------------------------------------------------------------------------------
// Extern functions from UserDdcci.c
//----------------------------------------------------------------------------------------
#ifndef __NONE_DDCCI__
extern void UserDdcciHandler(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from RTDKey.c
//----------------------------------------------------------------------------------------
#ifndef __NONE_KEY__
extern void NoneKeyInitial(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from RTDOsd.c
//----------------------------------------------------------------------------------------
#ifndef __NONE_OSD__
//============Main None==============//
extern void NoneOsdNoneMenu(void);
extern void NoneOsdNoneLeft(void);
extern void NoneOsdNoneRight(void);
extern void NoneOsdNoneExit(void);

#endif

#endif//#if(_OSD_TYPE == _NONE_OSD)
