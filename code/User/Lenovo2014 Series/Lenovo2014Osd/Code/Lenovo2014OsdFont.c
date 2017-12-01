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
// ID Code      : UserOSDFont.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDFONT__

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

//****************************************************************************
// FUNCTION DEFINITIONS
//**************************************************************************** 
void OsdFontLoadFont(BYTE ucState)
{
    switch(ucState)
    {
        case _FONT1_GLOBAL:
        case _FONT1_BAR:
        case _FONT1_BUTTON_ICON:
        case _FONT1_INPUT_OSD_VGA:
		case _FONT1_INPUT_OSD_DVI://jason.cheng 20150207_1 modify DVI source icon
        case _FONT1_INPUT_OSD_HDMI:
        case _FONT1_INPUT_OSD_DP:
        case _MESSAGE_FONT_GLOBAL:
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
        case _FONT1_LOW_BLUE_LIGHT_ENABLE:
        case _FONT1_LOW_BLUE_LIGHT_DISABLE:
#endif
            OsdFontLoadFontBank1(ucState);
            break;

        case _FONTX_LOGO:
            OsdFontLoadFontBank2(ucState);
            break;

        default:
            break;
    }

}

void OsdFontLoadItem(BYTE ucState, WORD usOffset)
{ 
#if(_INPUT_PORT_MAX > 0x01)

    if((ucState >= _MENU_NONE) && (ucState <= _SUB_INPUT_SIGNAL))
    {
        OsdFontLoadItemBank2(ucState, usOffset);
    } 
#else
	if((ucState >= _MENU_NONE) && (ucState <= _SUB_COLOR))
	{
		OsdFontLoadItemBank2(ucState, usOffset);
	} 
#endif
#if(_ASPECT_RATIO_SUPPORT == _ON)
    else if((ucState >= _SUB_SCALING) && (ucState <= _SUB_sRGB))
    {
        OsdFontLoadItemBank4(ucState, usOffset);
    }
#else

#if(_OD_OSD_SUPPORT == _ON)
	else if((ucState >= _SUB_OVER_DRIVE) && (ucState <= _SUB_sRGB))
	{
		OsdFontLoadItemBank4(ucState, usOffset);
	}
#else
	else if((ucState >= _SUB_INFORMATION) && (ucState <= _SUB_sRGB))
	{
		OsdFontLoadItemBank4(ucState, usOffset);
	}
#endif

#endif
    else if((ucState >= _SUB_CUSTOM_R) && (ucState <= _MAIN_MENU_STATE_END))    
    {
        OsdFontLoadItemBank6(ucState, usOffset);
    }    
}
#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
