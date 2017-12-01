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
// ID Code      : Panel_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// Definitions by Panel
//****************************************************************************
#if(_PANEL_EXIST_MULTIPANEL == _OFF)
//--------------------------------------------------
// Modification of Panel Parameters
//--------------------------------------------------
#if(_PANEL_DH_START != 32)
#warning "DH Start Should Be 32"
#undef _PANEL_DH_START
#define _PANEL_DH_START                             32
#endif

#if(_PANEL_DH_SYNC_WIDTH != 8)
#warning "DH Sync Width Should Be 8"
#undef _PANEL_DH_SYNC_WIDTH
#define _PANEL_DH_SYNC_WIDTH                        8
#endif

#if(_PANEL_DV_START != 6)
#warning "DV Start Should Be 6"
#undef _PANEL_DV_START
#define _PANEL_DV_START                             6
#endif

#if(_PANEL_DV_SYNC_HEIGHT != 2)
#warning "DV Sync Height Should Be 2"
#undef _PANEL_DV_SYNC_HEIGHT
#define _PANEL_DV_SYNC_HEIGHT                       2
#endif

#if(_PANEL_DV_TOTAL_MIN < _PANEL_DV_HEIGHT)
#warning "DV Total Min < DV Height"
#endif

#if(_PANEL_DV_TOTAL_MIN < (_PANEL_DV_HEIGHT + _PANEL_DV_SYNC_HEIGHT))
#warning "DV Total Min < (DV Height + DV Sync Height)"
#endif

#if(_PANEL_DH_TOTAL_MIN < _PANEL_DH_WIDTH)
#warning "DH Total Min < DH Width"
#endif

#if(_PANEL_DH_TOTAL_MIN < (_PANEL_DH_WIDTH + _PANEL_DH_SYNC_WIDTH))
#warning "DH Total Min < (DH Width + DVH Sync Width)"
#endif

//--------------------------------------------------
// Definitions for FREESYNC Panel Parameters
//--------------------------------------------------
#if(_FREESYNC_SUPPORT == _ON)
#ifndef _PANEL_FREESYNC_MAX_FRAME_RATE
#warning "Please Define _PANEL_FREESYNC_MAX_FRAME_RATE at Panel.h for Freesync"
#endif

#ifndef _PANEL_FREESYNC_MIN_FRAME_RATE
#warning "Please Define _PANEL_FREESYNC_MIN_FRAME_RATE at Panel.h for Freesync"
#endif

#if(_PANEL_DV_TOTAL_MAX < ((_PANEL_DV_TOTAL * _PANEL_FREESYNC_MAX_FRAME_RATE) / _PANEL_FREESYNC_MIN_FRAME_RATE))
#warning "_PANEL_DV_TOTAL_MAX Should Be Larger than (DVTotal * FreeSync Vfreq Ratio)!"
#endif
#endif

#endif // End of #if(_PANEL_EXIST_MULTIPANEL == _OFF)

//--------------------------------------------------
// Definitions for ADC Gain/Offset Adjust
//--------------------------------------------------
#ifndef _PANEL_ADC_OFFSET_BIAS
#define _PANEL_ADC_OFFSET_BIAS                      (0) // 0~5
#endif

#ifndef _PANEL_ADC_GAIN_BIAS
#define _PANEL_ADC_GAIN_BIAS                        (0) // -5~0
#endif

//--------------------------------------------------
// Definitions for panel switch function
//--------------------------------------------------
#ifndef _PANEL_SWITCH_PAD_SUPPORT
#define _PANEL_SWITCH_PAD_SUPPORT                   _OFF
#endif

#if(_PANEL_SWITCH_PAD_SUPPORT == _ON)

#ifndef _PANEL_SWITCH_DRIVING
#define _PANEL_SWITCH_DRIVING                       (_HIGH) // _HIGH or _LOW driving
#endif

#ifndef _PANEL_SWITCH_CURRENT
#define _PANEL_SWITCH_CURRENT                       (4)    // 0~7 (small ~ large)
#endif

#ifndef _PANEL_SWITCH_WAIT_TIME
#define _PANEL_SWITCH_WAIT_TIME                     (10)   // unit: ms
#endif

#endif

//--------------------------------------------------
// D Dither Define for 30bit Mode
//--------------------------------------------------
#if(_DISP_BIT_MODE == _DISP_30_BIT)
#undef _D_DITHER_SUPPORT
#define _D_DITHER_SUPPORT                           _OFF
#endif

#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _OFF)
#ifdef _PANEL_ELED_STRING_NUMBER
#warning "Please Select None E-LED Panel Type"
#endif
#endif

#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
#ifndef _PANEL_ELED_STRING_NUMBER
#warning "Please Select E-LED Panel Type"
#endif
#endif

