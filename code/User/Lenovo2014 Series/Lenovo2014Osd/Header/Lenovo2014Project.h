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
// ID Code      : UserProject.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if((_PROJECT == _RL6229_PROJECT) && (_3D_SUPPORT == _ON))
#define _OSD_3D_FUNCTION                            _ON
#else
#define _OSD_3D_FUNCTION                            _OFF
#endif

#if((_PROJECT != _RL6229_PROJECT) && (_OSD_3D_FUNCTION == _ON))
#warning "OSD 3D FUNCTION SUPPORT ON!!"
#endif

//-------------------------------------------------
//For OSD postion control
//-------------------------------------------------
#ifndef _NAVIGATE_ICON_POSITION_CONTROL
#define _NAVIGATE_ICON_POSITION_CONTROL				_OFF
#endif

//-------------------------------------------------
//For LG &LNT Panel interlace mode control
//-------------------------------------------------

#ifndef _LG_INTERLACE_MODE_SELECTION
#define _LG_INTERLACE_MODE_SELECTION				_OFF
#endif

//-------------------------------------------------
//
//-------------------------------------------------
#ifndef _LOW_BLUE_LIGHT_FUNCTION
#define _LOW_BLUE_LIGHT_FUNCTION                     _OFF
#endif

#ifndef _LBL_HOTKEY_FUNCTION
#define _LBL_HOTKEY_FUNCTION                         _OFF
#endif

#ifndef _OSD_LBL_ADJUST_FUNCTION
#define _OSD_LBL_ADJUST_FUNCTION                     _OFF
#endif


#ifndef _DFM_DC_RESET_7200_FUNCTION
#define _DFM_DC_RESET_7200_FUNCTION                  _ON
#endif

#ifndef _OSD_OD_DEF_VALUE
#define _OSD_OD_DEF_VALUE							 _OFF
#endif

#ifndef _OD_OSD_SUPPORT  //Ada.chen 20150924
#if(_OD_SUPPORT == _ON)
#define _OD_OSD_SUPPORT                              _ON
#else
#define _OD_OSD_SUPPORT                              _OFF
#endif
#endif

#ifndef _OD_OFF_GAIN_SUPPORT
#define _OD_OFF_GAIN_SUPPORT						 _OFF
#endif

#ifndef _OD_MULTI_SELECT
#define _OD_MULTI_SELECT							 _OFF
#endif








